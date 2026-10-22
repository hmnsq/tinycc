/*
 *  TCC - Tiny C Compiler
 * 
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#define USING_GLOBALS
#include "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA 整数 tok_flags;
ST_DATA 整数 parse_flags;

ST_DATA struct BufferedFile *file;
ST_DATA 整数 tok;
ST_DATA CValue tokc;
ST_DATA const 整数 *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA 整数 tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA 整数 pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static char token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned char isidnum_table[256 - CH_EOF];
static 整数 pp_debug_tok, pp_debug_symv;
static 整数 pp_counter;
static void tok_print(const 整数 *str, const char *msg, ...);
static void next_nomacro(void);
static void parse_number(const char *p);
static void parse_string(const char *p, 整数 len);

static struct TinyAlloc *toksym_alloc;
static struct TinyAlloc *tokstr_alloc;

static TokenString *macro_stack;

static const char tcc_keywords[] = 
#define DEF(id, str) str "\0"
#include "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
static const unsigned char tok_two_chars[] =
/* outdated -- gr
    "<=\236>=\235!=\225&&\240||\241++\244--\242==\224<<\1>>\2+=\253"
    "-=\255*=\252/=\257%=\245&=\246^=\336|=\374->\313..\250##\266";
*/{
    '<','=', TOK_LE,
    '>','=', TOK_GE,
    '!','=', TOK_NE,
    '&','&', TOK_LAND,
    '|','|', TOK_LOR,
    '+','+', TOK_INC,
    '-','-', TOK_DEC,
    '=','=', TOK_EQ,
    '<','<', TOK_SHL,
    '>','>', TOK_SAR,
    '+','=', TOK_A_ADD,
    '-','=', TOK_A_SUB,
    '*','=', TOK_A_MUL,
    '/','=', TOK_A_DIV,
    '%','=', TOK_A_MOD,
    '&','=', TOK_A_AND,
    '^','=', TOK_A_XOR,
    '|','=', TOK_A_OR,
    '-','>', TOK_ARROW,
    '.','.', TOK_TWODOTS,
    '#','#', TOK_TWOSHARPS,
    0
};

ST_FUNC void skip(整数 c)
{
    如果 (tok != c) {
        char tmp[40];
        pstrcpy(tmp, sizeof tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC void expect(const char *msg)
{
    tcc_error("%s expected", msg);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#否则
#如果 !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#否则
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const char *sfile, 整数 sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef struct TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    struct TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#如果 TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    union {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

typedef struct tal_header_t {
    size_t  size; /* word align */
#如果 TAL_DEBUG
    整数     line_num; /* negative line_num used for double free check */
    char    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (sizeof (size_t) - 1)) & ~(sizeof (size_t) - 1))

/* ------------------------------------------------------------------------- */

static TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(sizeof(TinyAlloc) - sizeof (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#如果 TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    返回 al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#如果 TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#如果 TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#如果 TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    如果 (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        当 (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            如果 (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (整数)header->size);
            }
            p += header->size + sizeof(tal_header_t);
        }
#如果 TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    如果 (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    如果 (!p)
        返回;
    header = (tal_header_t *)p - 1;
#如果 TAL_DEBUG
    如果 (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (整数)-header->line_num, (整数)header->size);
    } 否则
        header->line_num = -header->line_num;
#endif
    al = *pal;
    当 ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    如果 (0 == --al->nb_allocs) {
        *pal = al->next;
        如果 ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } 否则 {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } 否则 如果 ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + sizeof(tal_header_t);
    TinyAlloc *al = *pal;

    如果 (p) {
        /* reallpc case */
        当 ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        如果 ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        如果 (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            返回 ret;
        } 否则 如果 (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#如果 TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } 否则 {
        /* new alloc case */
        当 (al->p + adj_size > al->bufend) {
            al = al->next;
            如果 (!al) {
                unsigned new_size = (*pal)->size;
                如果 (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                break;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - sizeof(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#如果  TAL_DEBUG
    {
        整数 ofs = strlen(sfile) + 1 - sizeof header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#如果 TAL_INFO
        如果 (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        如果 (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    返回 ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, 整数 new_size)
{
    整数 size;

    size = cstr->size_allocated;
    如果 (size < 8)
        size = 8; /* no need to allocate a too small first string */
    当 (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, 整数 ch)
{
    整数 size;
    size = cstr->size + 1;
    如果 (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN char *unicode_to_utf8 (char *b, uint32_t Uc)
{
    如果 (Uc<0x80) *b++=Uc;
    否则 如果 (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    否则 如果 (Uc-0xd800u<0x800) goto error;
    否则 如果 (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    否则 如果 (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    否则 error: tcc_error("0x%x is not a valid universal character", Uc);
    返回 b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, 整数 ch)
{
    char buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const char *str, 整数 len)
{
    整数 size;
    如果 (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    如果 (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, 整数 ch)
{
    整数 size;
    size = cstr->size + sizeof(nwchar_t);
    如果 (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - sizeof(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC void cstr_new(CString *cstr)
{
    memset(cstr, 0, sizeof(CString));
}

/* free string and reset it to NULL */
ST_FUNC void cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC void cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC 整数 cstr_vprintf(CString *cstr, const char *fmt, va_list ap)
{
    va_list v;
    整数 len, size = 80;
    为 (;;) {
        size += cstr->size;
        如果 (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        如果 (len >= 0 && len < size)
            break;
        size *= 2;
    }
    cstr->size += len;
    返回 len;
}

ST_FUNC 整数 cstr_printf(CString *cstr, const char *fmt, ...)
{
    va_list ap; 整数 len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    返回 len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, 整数 c)
{
    如果 (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    如果 (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } 否则 {
        cstr_ccat(cstr, '\\');
        如果 (c == '\n') {
            cstr_ccat(cstr, 'n');
        } 否则 {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const char *str, 整数 len)
{
    TokenSym *ts, **ptable;
    整数 i;

    如果 (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    如果 ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * sizeof(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, sizeof(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = NULL;
    ts->sym_label = NULL;
    ts->sym_struct = NULL;
    ts->sym_identifier = NULL;
    ts->len = len;
    ts->hash_next = NULL;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    返回 ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const char *str, 整数 len)
{
    TokenSym *ts, **pts;
    整数 i;
    unsigned 整数 h;
    
    h = TOK_HASH_INIT;
    为(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned char *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    为(;;) {
        ts = *pts;
        如果 (!ts)
            break;
        如果 (ts->len == len && !memcmp(ts->str, str, len))
            返回 ts;
        pts = &(ts->hash_next);
    }
    返回 tok_alloc_new(pts, str, len);
}

ST_FUNC 整数 tok_alloc_const(const char *str)
{
    返回 tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const char *get_tok_str(整数 v, CValue *cv)
{
    char *p;
    整数 i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    switch(v) {
    case TOK_CINT:
    case TOK_CUINT:
    case TOK_CLONG:
    case TOK_CULONG:
    case TOK_CLLONG:
    case TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        break;
    case TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    case TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        break;
    case TOK_PPNUM:
    case TOK_PPSTR:
        返回 (char*)cv->str.data;
    case TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    case TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        如果 (v == TOK_STR) {
            len = cv->str.size - 1;
            为(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned char *)cv->str.data)[i]);
        } 否则 {
            len = (cv->str.size / sizeof(nwchar_t)) - 1;
            为(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        break;

    case TOK_CFLOAT:
        返回 strcpy(p, "<float>");
    case TOK_CDOUBLE:
        返回 strcpy(p, "<double>");
    case TOK_CLDOUBLE:
        返回 strcpy(p, "<long double>");
    case TOK_LINENUM:
        返回 strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    case TOK_LT:
        v = '<';
        goto addv;
    case TOK_GT:
        v = '>';
        goto addv;
    case TOK_DOTS:
        返回 strcpy(p, "...");
    case TOK_A_SHL:
        返回 strcpy(p, "<<=");
    case TOK_A_SAR:
        返回 strcpy(p, ">>=");
    case TOK_EOF:
        返回 strcpy(p, "<eof>");
    case 0: /* anonymous nameless symbols */
        返回 strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        如果 (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned char *q = tok_two_chars;
            当 (*q) {
                如果 (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    返回 cstr_buf.data;
                }
                q += 3;
            }
            如果 (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                break;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } 否则 如果 (v < tok_ident) {
            返回 table_ident[v - TOK_IDENT]->str;
        } 否则 如果 (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } 否则 {
            /* should never happen */
            返回 NULL;
        }
        break;
    }
    返回 cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static 整数 handle_eob(void)
{
    BufferedFile *bf = file;
    整数 len;

    /* only tries to read if really end of buffer */
    如果 (bf->buf_ptr >= bf->buf_end) {
        如果 (bf->fd >= 0) {
#如果 defined(PARSE_DEBUG)
            len = 1;
#否则
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            如果 (len < 0)
                len = 0;
        } 否则 {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    如果 (bf->buf_ptr < bf->buf_end) {
        返回 bf->buf_ptr[0];
    } 否则 {
        bf->buf_ptr = bf->buf_end;
        返回 CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static 整数 next_c(void)
{
    整数 ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    如果 (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    返回 ch;
}

/* input with '\[\r]\n' handling. */
static 整数 handle_stray_noerror(整数 err)
{
    整数 ch;
    当 ((ch = next_c()) == '\\') {
        ch = next_c();
        如果 (ch == '\n') {
    newl:
            file->line_num++;
        } 否则 {
            如果 (ch == '\r') {
                ch = next_c();
                如果 (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            如果 (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            返回 *--file->buf_ptr = '\\';
        }
    }
    返回 ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static 整数 handle_bs(uint8_t **p)
{
    整数 c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    返回 c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static 整数 handle_stray(uint8_t **p)
{
    整数 c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    返回 c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    如果 (c == '\\')\
        c = handle_stray(&p); \
}

static 整数 skip_spaces(void)
{
    整数 ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } 当 (isidnum_table[ch - CH_EOF] & IS_SPC);
    返回 ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    整数 c;
    为(;;) {
        为 (;;) {
            c = *++p;
    redo:
            如果 (c == '\n' || c == '\\')
                break;
            c = *++p;
            如果 (c == '\n' || c == '\\')
                break;
        }
        如果 (c == '\n')
            break;
        c = handle_bs(&p);
        如果 (c == CH_EOF)
            break;
        如果 (c != '\\')
            goto redo;
    }
    返回 p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    整数 c;
    为(;;) {
        /* fast skip loop */
        为(;;) {
            c = *++p;
        redo:
            如果 (c == '\n' || c == '*' || c == '\\')
                break;
            c = *++p;
            如果 (c == '\n' || c == '*' || c == '\\')
                break;
        }
        /* now we can handle all the cases */
        如果 (c == '\n') {
            file->line_num++;
        } 否则 如果 (c == '*') {
            do {
                c = *++p;
            } 当 (c == '*');
            如果 (c == '\\')
                c = handle_bs(&p);
            如果 (c == '/')
                break;
            goto check_eof;
        } 否则 {
            c = handle_bs(&p);
        check_eof:
            如果 (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            如果 (c != '\\')
                goto redo;
        }
    }
    返回 p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, 整数 sep, CString *str)
{
    整数 c;
    为(;;) {
        c = *++p;
    redo:
        如果 (c == sep) {
            break;
        } 否则 如果 (c == '\\') {
            c = handle_bs(&p);
            如果 (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } 否则 如果 (c == '\\') {
                如果 (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                如果 (c == '\\') {
                    c = handle_bs(&p);
                    如果 (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } 否则 {
                goto redo;
            }
        } 否则 如果 (c == '\n') {
        add_lf:
            如果 (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } 否则 如果 (str) { /* not skipping */
                goto unterminated_string;
            } 否则 {
                //tcc_warning("missing terminating %c character", sep);
                返回 p;
            }
        } 否则 如果 (c == '\r') {
            c = *++p;
            如果 (c == '\\')
                c = handle_bs(&p);
            如果 (c == '\n')
                goto add_lf;
            如果 (c == CH_EOF)
                goto unterminated_string;
            如果 (str)
                cstr_ccat(str, '\r');
            goto redo;
        } 否则 {
        add_char:
            如果 (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    返回 p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    整数 a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    为(;;) {
        c = *p;
        switch(c) {
        case ' ':
        case '\t':
        case '\f':
        case '\v':
        case '\r':
            p++;
            continue;
        case '\n':
            file->line_num++;
            p++;
            goto redo_start;
        case '\\':
            c = handle_bs(&p);
            如果 (c == CH_EOF)
                expect("#endif");
            如果 (c == '\\')
                ++p;
            continue;
        /* skip strings */
        case '\"':
        case '\'':
            如果 (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            break;
        /* skip comments */
        case '/':
            如果 (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            如果 (c == '*') {
                p = parse_comment(p);
            } 否则 如果 (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        case '#':
            p++;
            如果 (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                如果 (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                如果 (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                否则 如果 (tok == TOK_ENDIF)
                    a--;
                否则 如果( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                否则 如果 (tok == TOK_LINEFEED)
                    goto redo_start;
                否则 如果 (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#如果 !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            否则 如果 (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#否则
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            break;
_default:
        default:
            p++;
            break;
        }
        start_of_line = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#如果 0
/* return the number of additional 'ints' necessary to store the
   token */
static inline 整数 tok_size(const 整数 *p)
{
    switch(*p) {
        /* 4 bytes */
    case TOK_CINT:
    case TOK_CUINT:
    case TOK_CCHAR:
    case TOK_LCHAR:
    case TOK_CFLOAT:
    case TOK_LINENUM:
        返回 1 + 1;
    case TOK_STR:
    case TOK_LSTR:
    case TOK_PPNUM:
    case TOK_PPSTR:
        返回 1 + 1 + (p[1] + 3) / 4;
    case TOK_CLONG:
    case TOK_CULONG:
	返回 1 + LONG_SIZE / 4;
    case TOK_CDOUBLE:
    case TOK_CLLONG:
    case TOK_CULLONG:
        返回 1 + 2;
    case TOK_CLDOUBLE:
        返回 1 + LDOUBLE_WORDS;
    default:
        返回 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN void tok_str_new(TokenString *s)
{
    s->str = NULL;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_line_num = -1;
}

ST_FUNC TokenString *tok_str_alloc(void)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, sizeof *str);
    tok_str_new(str);
    返回 str;
}

ST_FUNC void tok_str_free_str(整数 *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC 整数 *tok_str_realloc(TokenString *s, 整数 new_size)
{
    整数 *str, size;

    size = s->allocated_len;
    如果 (size < 16)
        size = 16;
    当 (size < new_size)
        size = size * 2;
    如果 (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * sizeof(整数));
        s->allocated_len = size;
        s->str = str;
    }
    返回 s->str;
}

ST_FUNC void tok_str_add(TokenString *s, 整数 t)
{
    整数 len, *str;

    len = s->len;
    str = s->str;
    如果 (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, 整数 alloc)
{
    str->alloc = alloc;
    str->prev = macro_stack;
    str->prev_ptr = macro_ptr;
    str->save_line_num = file->line_num;
    macro_ptr = str->str;
    macro_stack = str;
}

ST_FUNC void end_macro(void)
{
    TokenString *str = macro_stack;
    macro_stack = str->prev;
    macro_ptr = str->prev_ptr;
    file->line_num = str->save_line_num;
    如果 (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } 否则 {
        如果 (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, 整数 t, CValue *cv)
{
    整数 len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    如果 (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    case TOK_CINT:
    case TOK_CUINT:
    case TOK_CCHAR:
    case TOK_LCHAR:
    case TOK_CFLOAT:
    case TOK_LINENUM:
#如果 LONG_SIZE == 4
    case TOK_CLONG:
    case TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        break;
    case TOK_PPNUM:
    case TOK_PPSTR:
    case TOK_STR:
    case TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_words =
                1 + (cv->str.size + sizeof(整数) - 1) / sizeof(整数);
            如果 (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        break;
    case TOK_CDOUBLE:
    case TOK_CLLONG:
    case TOK_CULLONG:
#如果 LONG_SIZE == 8
    case TOK_CLONG:
    case TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        break;
    case TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        如果 (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        如果 (LDOUBLE_WORDS >= 4)
        str[len++] = cv->tab[3];
    default:
        break;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC void tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    如果 (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, 整数 t, CValue *cv)
{
    如果 (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static inline void tok_get(整数 *t, const 整数 **pp, CValue *cv)
{
    const 整数 *p = *pp;
    整数 n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#如果 LONG_SIZE == 4
    case TOK_CLONG:
#endif
    case TOK_CINT:
    case TOK_CCHAR:
    case TOK_LCHAR:
    case TOK_LINENUM:
        cv->i = *p++;
        break;
#如果 LONG_SIZE == 4
    case TOK_CULONG:
#endif
    case TOK_CUINT:
        cv->i = (unsigned)*p++;
        break;
    case TOK_CFLOAT:
	tab[0] = *p++;
	break;
    case TOK_STR:
    case TOK_LSTR:
    case TOK_PPNUM:
    case TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (char*)p;
        p += (cv->str.size + sizeof(整数) - 1) / sizeof(整数);
        break;
    case TOK_CDOUBLE:
    case TOK_CLLONG:
    case TOK_CULLONG:
#如果 LONG_SIZE == 8
    case TOK_CLONG:
    case TOK_CULONG:
#endif
        n = 2;
        goto copy;
    case TOK_CLDOUBLE:
        n = LDOUBLE_WORDS;
    copy:
        do
            *tab++ = *p++;
        当 (--n);
        break;
    default:
        break;
    }
    *pp = p;
}

#如果 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#否则
# define TOK_GET(t,p,c) do { \
    整数 _t = **(p); \
    如果 (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    否则 \
        *(t) = _t, ++*(p); \
    } 当 (0)
#endif

static 整数 macro_is_equal(const 整数 *a, const 整数 *b)
{
    CValue cv;
    整数 t;

    如果 (!a || !b)
        返回 1;

    当 (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        如果 (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            返回 0;
    }
    返回 !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(整数 v, 整数 macro_type, 整数 *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    如果 (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    整数 v = s->v;
    如果 (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(整数 v)
{
    v -= TOK_IDENT;
    如果 ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        返回 NULL;
    返回 table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    当 (define_stack != b) {
        Sym *top = define_stack;
        define_stack = top->prev;
        tok_str_free_str(top->d);
        define_undef(top);
        sym_free(top);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
static void maybe_run_test(TCCState *s)
{
    const char *p;
    如果 (s->include_stack_ptr != s->include_stack)
        返回;
    p = get_tok_str(tok, NULL);
    如果 (0 != memcmp(p, "test_", 5))
        返回;
    如果 (0 != --s->run_test)
        返回;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(整数 warn)
{
    如果 (tok == TOK_LINEFEED)
        返回;
    如果 (warn)
        tcc_warning("extra tokens after directive");
    当 (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const char *filename, 整数 add);

static 整数 parse_include(TCCState *s1, 整数 do_next, 整数 test)
{
    整数 c, i;
    char name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    如果 (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, sizeof name, tokcstr.data, i);
        next_nomacro();
    } 否则 {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        为 (;;) {
            next();
            p = name, i = strlen(p) - 1;
            如果 (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                break;
            如果 (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, sizeof name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    如果 (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    为 (;;) {
        ++i;
        如果 (i == 0) {
            /* check absolute include path */
            如果 (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } 否则 如果 (i == 1) {
            /* search in file's dir if "header.h" */
            如果 (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, sizeof buf, p, tcc_basename(p) - p);
        } 否则 {
            整数 j = i - 2, k = j - s1->nb_include_paths;
            如果 (k < 0)
                p = s1->include_paths[j];
            否则 如果 (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            否则 如果 (test)
                返回 0;
            否则
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, sizeof buf, p);
            pstrcat(buf, sizeof buf, "/");
        }
        pstrcat(buf, sizeof buf, name);
        e = search_cached_include(s1, buf, 0);
        如果 (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            如果 ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (整数)(s1->include_stack_ptr - s1->include_stack), "", buf);
            返回 1;
        }
        如果 (tcc_open(s1, buf) >= 0)
            break;
    }

    如果 (test) {
        tcc_close();
    } 否则 {
        如果 (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        如果 (s1->gen_deps) {
            BufferedFile *bf = file;
            当 (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            如果 (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    返回 1;
}

/* eval an expression for #if/#elif */
static 整数 expr_preprocess(TCCState *s1)
{
    整数 c, t;
    整数 t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    当 (1) {
        next(); /* do macro subst */
        t = tok;
        如果 (tok < TOK_IDENT) {
            如果 (tok == TOK_LINEFEED || tok == TOK_EOF)
                break;
            如果 (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } 否则 如果 (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            如果 (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            如果 (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            如果 (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            如果 (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            如果 (t == '(') {
                next();
                如果 (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } 否则 如果 (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    如果 (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            如果 (tok != ')')
                expect("')'");
            goto c_number;
        } 否则 {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    如果 (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    如果 (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    返回 c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    当 (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    整数 v, t, varg, is_vaargs, t0;
    整数 saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    如果 (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = NULL;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    next_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    如果 (tok == '(') {
        整数 dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        如果 (tok != ')') 为 (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            如果 (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } 否则 如果 (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            如果 (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            如果 (tok == ')')
                break;
            如果 (tok != ',' || is_vaargs)
                goto bad_list;
            next_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        next_nomacro();
        t = MACRO_FUNC;
        set_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    当 (tok != TOK_LINEFEED && tok != TOK_EOF) {
        如果 (is_space(tok)) {
            str.need_spc |= 1;
        } 否则 {
            如果 (TOK_TWOSHARPS == tok) {
                如果 (0 == t0)
                    goto bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        next_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_add(&str, 0);
    如果 (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const char *filename, 整数 add)
{
    const char *s, *basename;
    unsigned 整数 h;
    CachedInclude *e;
    整数 c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    当 ((c = (unsigned char)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#否则
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    为(;;) {
        如果 (i == 0)
            break;
        e = s1->cached_includes[i - 1];
        如果 (0 == PATHCMP(filename, e->filename))
            返回 e;
        如果 (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            返回 e;
        i = e->hash_next;
    }
    如果 (!add)
        返回 NULL;

    e = tcc_malloc(sizeof(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    返回 e;
}

static 整数 pragma_parse(TCCState *s1)
{
    next_nomacro();
    如果 (tok == TOK_push_macro || tok == TOK_pop_macro) {
        整数 t = tok, v;
        Sym *s;

        如果 (next(), tok != '(')
            goto pragma_err;
        如果 (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        如果 (next(), tok != ')')
            goto pragma_err;
        如果 (t == TOK_push_macro) {
            当 (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } 否则 {
            为 (s = define_stack; s; s = s->prev)
                如果 (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    break;
                }
        }
        如果 (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        否则
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } 否则 如果 (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } 否则 如果 (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        返回 1;

    } 否则 如果 (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        如果 (tok == TOK_ASM_pop) {
            next();
            如果 (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } 否则 {
            整数 val = 0;
            如果 (tok != ')') {
                如果 (tok == TOK_ASM_push) {
                    next();
                    如果 (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    如果 (tok != ',')
                        goto pack_set;
                    next();
                }
                如果 (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                如果 (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        如果 (tok != ')')
            goto pragma_err;

    } 否则 如果 (tok == TOK_comment) {
        char *p; 整数 t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        如果 (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        如果 (tok != ')')
            goto pragma_err;
        如果 (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } 否则 {
            如果 (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } 否则 {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        返回 0;
    }
    next();
    返回 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const char *filename)
{
    char buf[1024];
    buf[0] = 0;
    如果 (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, sizeof buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, sizeof buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    如果 (0 == strcmp(file->filename, buf))
        返回;
    //printf("new file '%s'\n", buf);
    如果 (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, sizeof file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(整数 is_bof)
{
    TCCState *s1 = tcc_state;
    整数 c, n, saved_parse_flags;
    char buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_NUM
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    switch(tok) {
    case TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        break;
    case TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        如果 (s)
            define_undef(s);
        next_nomacro();
        break;
    case TOK_INCLUDE:
    case TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        goto the_end;
    case TOK_IFNDEF:
        c = 1;
        goto do_ifdef;
    case TOK_IF:
        c = expr_preprocess(s1);
        goto do_if;
    case TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        如果 (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        如果 (is_bof) {
            如果 (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        如果 (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        如果 (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    case TOK_ELSE:
        next_nomacro();
        如果 (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        如果 (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    case TOK_ELIF:
        如果 (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        如果 (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        如果 (c == 1) {
            skip_to_eol(0);
            c = 0;
        } 否则 {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        如果 (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        如果 (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        break;
    case TOK_ENDIF:
        next_nomacro();
        如果 (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        如果 (file->ifndef_macro &&
            s1->ifdef_stack_ptr == file->ifdef_stack_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        break;

    case TOK_LINE:
        parse_flags &= ~PARSE_FLAG_TOK_NUM;
        next();
        如果 (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    case TOK_PPNUM:
        如果 (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        为 (n = 0, q = tokc.str.data; *q; ++q) {
            如果 (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        如果 (tok != TOK_LINEFEED) {
            如果 (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        如果 (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        break;

    case TOK_ERROR:
    case TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        当 (c != '\n' && c != CH_EOF) {
            如果 ((q - buf) < sizeof(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        如果 (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        否则
            tcc_warning("#warning %s", buf);
        next_nomacro();
        break;
    }
    case TOK_PRAGMA:
        如果 (!pragma_parse(s1))
            goto ignore;
        break;
    case TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        如果 (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        如果 (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            goto ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        goto the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
static void parse_escape_string(CString *outstr, const uint8_t *buf, 整数 is_long)
{
    整数 c, n, i;
    const uint8_t *p;

    p = buf;
    为(;;) {
        c = *p;
        如果 (c == '\0')
            break;
        如果 (c == '\\') {
            p++;
            /* escape */
            c = *p;
            switch(c) {
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                如果 (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    如果 (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                goto add_char_nonext;
            case 'x': i = 0; goto parse_hex_or_ucn;
            case 'u': i = 4; goto parse_hex_or_ucn;
            case 'U': i = 8; goto parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                do {
                    c = *p;
                    如果 (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    否则 如果 (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    否则 如果 (isnum(c))
                        c = c - '0';
                    否则 如果 (i >= 0)
                        expect("more hex digits in universal-character-name");
                    否则
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } 当 (--i);
		如果 (is_long) {
    add_hex_or_ucn:
                    c = n;
		    goto add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                continue;
            case 'a':
                c = '\a';
                break;
            case 'b':
                c = '\b';
                break;
            case 'f':
                c = '\f';
                break;
            case 'n':
                c = '\n';
                break;
            case 'r':
                c = '\r';
                break;
            case 't':
                c = '\t';
                break;
            case 'v':
                c = '\v';
                break;
            case 'e':
                如果 (!gnu_ext)
                    goto invalid_escape;
                c = 27;
                break;
            case '\'':
            case '\"':
            case '\\': 
            case '?':
                break;
            default:
            invalid_escape:
                如果 (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                否则
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                break;
            }
        } 否则 如果 (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            整数 cont; /* count of continuation bytes */
            整数 skip; /* how many bytes should skip when error occurred */
            整数 i;

            /* decode leading byte */
            如果 (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } 否则 如果 (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } 否则 如果 (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } 否则 如果 (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } 否则 {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            为 (i = 1; i <= cont; i++) {
                整数 l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                如果 (i == 1) {
                    switch (c) {
                    case 0xE0: l = 0xA0; break;
                    case 0xED: h = 0x9F; break;
                    case 0xF0: l = 0x90; break;
                    case 0xF4: h = 0x8F; break;
                    }
                }

                如果 (p[i] < l || p[i] > h) {
                    skip = i; goto invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            goto add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            goto add_char_nonext;

        }
        p++;
    add_char_nonext:
        如果 (!is_long)
            cstr_ccat(outstr, c);
        否则 {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            如果 (c < 0x10000) {
                cstr_wccat(outstr, c);
            } 否则 {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#否则
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    如果 (!is_long)
        cstr_ccat(outstr, '\0');
    否则
        cstr_wccat(outstr, '\0');
}

static void parse_string(const char *s, 整数 len)
{
    uint8_t buf[1000], *p = buf;
    整数 is_long, sep;

    如果 ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    如果 (len >= sizeof buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    如果 (p != buf)
        tcc_free(p);

    如果 (sep == '\'') {
        整数 char_size, i, n, c;
        /* XXX: make it portable */
        如果 (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        否则
            tok = TOK_LCHAR, char_size = sizeof(nwchar_t);
        n = tokcstr.size / char_size - 1;
        如果 (n < 1)
            tcc_error("empty character constant");
        如果 (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        为 (c = i = 0; i < n; ++i) {
            如果 (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            否则
                c = (c << 8) | ((char *)tokcstr.data)[i];
        }
        tokc.i = c;
    } 否则 {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        如果 (!is_long)
            tok = TOK_STR;
        否则
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static 整数 bn_lshift(unsigned 整数 *bn, 整数 shift, 整数 or_val)
{
    整数 i;
    unsigned 整数 v;
    如果 (bn[BN_SIZE - 1] >> (32 - shift))
	返回 shift;
    为(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    返回 0;
}

static void bn_zero(unsigned 整数 *bn)
{
    整数 i;
    为(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const char *p)
{
    整数 b, t, shift, frac_bits, s, exp_val, ch;
    char *q;
    unsigned 整数 bn[BN_SIZE];
    long double d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    如果 (t == '.') {
        goto float_frac_parse;
    } 否则 如果 (t == '0') {
        如果 (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } 否则 如果 (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    当 (1) {
        如果 (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        否则 如果 (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        否则 如果 (isnum(ch))
            t = ch - '0';
        否则
            break;
        如果 (t >= b)
            break;
        如果 (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    如果 (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        如果 (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            如果 (b == 16)
                shift = 4;
            否则 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            当 (1) {
                t = *q++;
                如果 (t == '\0') {
                    break;
                } 否则 如果 (t >= 'a') {
                    t = t - 'a' + 10;
                } 否则 如果 (t >= 'A') {
                    t = t - 'A' + 10;
                } 否则 {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            如果 (ch == '.') {
                ch = *p++;
                当 (1) {
                    t = ch;
                    如果 (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } 否则 如果 (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } 否则 如果 (t >= '0' && t <= '9') {
                        t = t - '0';
                    } 否则 {
                        break;
                    }
                    如果 (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            如果 (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            如果 (ch == '+') {
                ch = *p++;
            } 否则 如果 (ch == '-') {
                s = -1;
                ch = *p++;
            }
            如果 (ch < '0' || ch > '9')
                expect("exponent digits");
            当 (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		如果 (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long double)bn[3] * 79228162514264337593543950336.0L +
	        (long double)bn[2] * 18446744073709551616.0L +
	        (long double)bn[1] * 4294967296.0L +
	        (long double)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            如果 (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } 否则 如果 (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } 否则 {
                tok = TOK_CDOUBLE;
                tokc.d = (double)d;
            }
        } 否则 {
            /* decimal floats */
            如果 (ch == '.') {
                如果 (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                当 (ch >= '0' && ch <= '9') {
                    如果 (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            如果 (ch == 'e' || ch == 'E') {
                如果 (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                如果 (ch == '-' || ch == '+') {
                    如果 (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                如果 (ch < '0' || ch > '9')
                    expect("exponent digits");
                当 (ch >= '0' && ch <= '9') {
                    如果 (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            如果 (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } 否则 如果 (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } 否则 {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } 否则 {
        unsigned long long n, n1;
        整数 lcount, ucount, ov = 0;
        const char *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        如果 (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        当(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            如果 (t == '\0')
                break;
            否则 如果 (t >= 'a')
                t = t - 'a' + 10;
            否则 如果 (t >= 'A')
                t = t - 'A' + 10;
            否则
                t = t - '0';
            如果 (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            如果 (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        为(;;) {
            t = toup(ch);
            如果 (t == 'L') {
                如果 (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                如果 (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } 否则 如果 (t == 'U') {
                如果 (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } 否则 {
                break;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        如果 (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        如果 (ucount == 0 && b == 10) {
            如果 (lcount <= (LONG_SIZE == 4)) {
                如果 (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            如果 (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } 否则 {
            如果 (lcount <= (LONG_SIZE == 4)) {
                如果 (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                否则 如果 (n >= 0x80000000U)
                    ucount = 1;
            }
            如果 (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        如果 (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	如果 (lcount) {
            tok = TOK_CLONG;
            如果 (lcount == 2)
                tok = TOK_CLLONG;
	}
	如果 (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    如果 (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    case c1:                                    \
        PEEKC(c, p);                            \
        如果 (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } 否则 {                                \
            tok = tok1;                         \
        }                                       \
        break;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    整数 t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned 整数 h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    case ' ':
    case '\t':
        tok = c;
        p++;
 maybe_space:
        如果 (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        当 (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        goto redo_no_start;
    case '\f':
    case '\v':
    case '\r':
        p++;
        goto redo_no_start;
    case '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        如果 (c == '\\')
            goto parse_simple;
        如果 (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            如果 (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } 否则 如果 (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } 否则 如果 (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } 否则 如果 (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } 否则 {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                如果 (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, NULL));
#endif
                    search_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_stack_ptr--;
                p = file->buf_ptr;
                goto maybe_newline;
            }
        } 否则 {
            goto redo_no_start;
        }
        break;

    case '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        如果 (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    case '#':
        /* XXX: simplify */
        PEEKC(c, p);
        如果 ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } 否则 {
            如果 (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } 否则 {
#如果 !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                如果 (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } 否则
#endif
                {
                    tok = '#';
                }
            }
        }
        break;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    case '$':
        如果 (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            goto parse_simple;

    case 'a': case 'b': case 'c': case 'd':
    case 'e': case 'f': case 'g': case 'h':
    case 'i': case 'j': case 'k': case 'l':
    case 'm': case 'n': case 'o': case 'p':
    case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x':
    case 'y': case 'z': 
    case 'A': case 'B': case 'C': case 'D':
    case 'E': case 'F': case 'G': case 'H':
    case 'I': case 'J': case 'K': 
    case 'M': case 'N': case 'O': case 'P':
    case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X':
    case 'Y': case 'Z': 
    case '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        当 (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        如果 (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            为(;;) {
                ts = *pts;
                如果 (!ts)
                    break;
                如果 (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (char *) p1, len);
        token_found: ;
        } 否则 {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (char *) p1, len);
            p--;
            PEEKC(c, p);
            当 (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        break;
    case 'L':
        t = p[1];
        如果 (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            如果 (c == '\'' || c == '\"') {
                is_long = 1;
                goto str_const;
            }
            *--p = c = 'L';
        }
        goto parse_ident_fast;

    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
    case '8': case '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_num:
        cstr_reset(&tokcstr);
        为(;;) {
            cstr_ccat(&tokcstr, t);
            如果 (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((char*)tokcstr.data)[0] == '0'
                                && toup(((char*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                break;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        break;

    case '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        如果 (isnum(c)) {
            t = '.';
            goto parse_num;
        } 否则 如果 ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } 否则 如果 (c == '.') {
            PEEKC(c, p);
            如果 (c == '.') {
                p++;
                tok = TOK_DOTS;
            } 否则 {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } 否则 {
            tok = '.';
        }
        break;
    case '\'':
    case '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        如果 (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        break;

    case '<':
        PEEKC(c, p);
        如果 (c == '=') {
            p++;
            tok = TOK_LE;
        } 否则 如果 (c == '<') {
            PEEKC(c, p);
            如果 (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } 否则 {
                tok = TOK_SHL;
            }
        } 否则 {
            tok = TOK_LT;
        }
        break;
    case '>':
        PEEKC(c, p);
        如果 (c == '=') {
            p++;
            tok = TOK_GE;
        } 否则 如果 (c == '>') {
            PEEKC(c, p);
            如果 (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } 否则 {
                tok = TOK_SAR;
            }
        } 否则 {
            tok = TOK_GT;
        }
        break;
        
    case '&':
        PEEKC(c, p);
        如果 (c == '&') {
            p++;
            tok = TOK_LAND;
        } 否则 如果 (c == '=') {
            p++;
            tok = TOK_A_AND;
        } 否则 {
            tok = '&';
        }
        break;
        
    case '|':
        PEEKC(c, p);
        如果 (c == '|') {
            p++;
            tok = TOK_LOR;
        } 否则 如果 (c == '=') {
            p++;
            tok = TOK_A_OR;
        } 否则 {
            tok = '|';
        }
        break;

    case '+':
        PEEKC(c, p);
        如果 (c == '+') {
            p++;
            tok = TOK_INC;
        } 否则 如果 (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } 否则 {
            tok = '+';
        }
        break;
        
    case '-':
        PEEKC(c, p);
        如果 (c == '-') {
            p++;
            tok = TOK_DEC;
        } 否则 如果 (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } 否则 如果 (c == '>') {
            p++;
            tok = TOK_ARROW;
        } 否则 {
            tok = '-';
        }
        break;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    case '/':
        PEEKC(c, p);
        如果 (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } 否则 如果 (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } 否则 如果 (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } 否则 {
            tok = '/';
        }
        break;
        
        /* simple tokens */
    case '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        如果 (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_line_comment(p);
            goto redo_no_start;
        }
#endif
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
    case ',':
    case ';':
    case ':':
    case '?':
    case '~':
    parse_simple:
        tok = c;
        p++;
        break;
    case 0xEF: /* UTF8 BOM ? */
        如果 (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        如果 (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        如果 (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        break;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#如果 defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static 整数 indent;
static void define_print(TCCState *s1, 整数 v);
static void pp_print(const char *msg, 整数 v, const 整数 *str)
{
    FILE *fp = tcc_state->ppfp;

    如果 (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    否则 如果 (msg[0] == '+')
         ++indent, ++msg;
    否则 如果 (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    如果 (msg[0] == '#') {
        define_print(tcc_state, v);
    } 否则 {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#否则
#define PP_PRINT(x)
#endif

static 整数 macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const 整数 *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static 整数 *macro_arg_subst(Sym **nested_list, const 整数 *macro_str, Sym *args)
{
    整数 t, t0, t1, t2, n;
    const 整数 *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    为 (s = args, n = 0; s; s = s->prev, ++n);
    当 (n--) {
        为 (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    当(1) {
        TOK_GET(&t, &macro_str, &cval);
        如果 (!t)
            break;
        如果 (t == '#') {
            /* stringize */
            do t = *macro_str++; 当 (t == ' ');
            s = sym_find2(args, t);
            如果 (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                当 (*st != TOK_EOF) {
                    const char *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    当 (*s) {
                        如果 (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        否则
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.size = tokcstr.size;
                cval.str.data = tokcstr.data;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#ifdef TCC_TARGET_ARM
            } 否则 如果 ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } 否则 {
                expect("macro parameter after '#'");
            }
        } 否则 如果 (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            如果 (s) {
                st = s->d;
                n = 0;
                当 ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                如果 (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    如果 (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        整数 c = str.str[str.len - 1];
                        当 (str.str[--str.len] != ',')
                            ;
                        如果 (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } 否则 {
                            /* suppress '##' and add variable */
                            str.len++;
                            如果 (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } 否则 {
                        如果 (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } 否则 {
            add_var:
		    如果 (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_add(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                当 (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } 否则 {
                tok_str_add(&str, t);
            }
        } 否则 {
            tok_str_add2(&str, t, &cval);
        }
        如果 (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    返回 str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static inline 整数 *macro_twosharps(const 整数 *ptr0)
{
    整数 t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const 整数 *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    为 (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        如果 (t1 == 0)
            break;
        为 (;;) {
            n = 0;
            当 ((t2 = ptr[n]) == ' ')
                ++n;
            如果 (t2 != TOK_PPJOIN)
                break;
            ptr += n;
            当 ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            如果 (t2 == TOK_PLCHLDR)
                continue;
            如果 (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        如果 (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            为 (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                如果 (*file->buf_ptr == 0)
                    break;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        如果 (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    返回 macro_str1.str;
}

static 整数 peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    整数 c;
    为 (;;) {
        PEEKC(c, p);
        switch (c) {
        case '/':
            PEEKC(c, p);
            如果 (c == '*')
                p = parse_comment(p);
            否则 如果 (c == '/')
                p = parse_line_comment(p);
            否则 {
                c = *--p = '/';
                goto leave;
            }
            --p, c = ' ';
            break;
        case ' ': case '\t':
            break;
        case '\f': case '\v': case '\r':
            continue;
        case '\n':
            file->line_num++, tok_flags |= TOK_FLAG_BOL;
            break;
        default: leave:
            file->buf_ptr = p;
            返回 c;
        }
        如果 (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static 整数 next_argstream(Sym **nested_list, TokenString *ws_str)
{
    整数 t;
    Sym *sa;

    当 (macro_ptr) {
        const 整数 *m = macro_ptr;
        当 ((t = *m) != 0) {
            如果 (ws_str) {
                如果 (t != ' ')
                    返回 t;
                ++m;
            } 否则 {
                TOK_GET(&tok, &macro_ptr, &tokc);
                返回 tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        如果 (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    如果 (ws_str) {
        返回 peek_file(ws_str);
    } 否则 {
        next_nomacro();
        如果 (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        返回 tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static 整数 macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    整数 t;
    整数 v = s->v;

    PP_PRINT(("#", v, s->d));
    如果 (s->d) {
        整数 *mstr = s->d;
        整数 *jstr;
        Sym *sa;
        整数 ret;

        如果 (s->type.t & MACRO_FUNC) {
            整数 saved_parse_flags = parse_flags;
            TokenString str;
            整数 parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            如果 (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                如果 (parse_flags & PARSE_FLAG_SPACES)
                    为 (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                返回 0;
            } 否则 {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            为(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } 当 (t == ' ' || --i);

                如果 (!sa) {
                    如果 (t == ')') /* handle '()' case */
                        break;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                当 (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    如果 (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    如果 (t == '(')
                        parlevel++;
                    如果 (t == ')')
                        parlevel--;
                    如果 (t == ' ')
                        str.need_spc |= 1;
                    否则
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                如果 (t == ')') {
                    如果 (!sa)
                        break;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    如果 (sa->type.t && gnu_ext)
                        goto empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            当 (sa) {
                sa1 = sa->prev;
                tok_str_free_str(sa->d);
                tok_str_free_str(sa->e);
                sym_free(sa);
                sa = sa1;
            }
            parse_flags = saved_parse_flags;
        }

        /* process '##'s (if present) */
        jstr = mstr;
        如果 (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        如果 (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        如果 (jstr != mstr)
            tok_str_free_str(jstr);
        如果 (mstr != s->d)
            tok_str_free_str(mstr);
        返回 ret;

    } 否则 {
        CValue cval;
        char buf[32], *cstrval = buf;

        /* special macros */
        如果 (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, sizeof(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } 否则 如果 (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } 否则 如果 (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            struct tm *tm;
            time(&ti);
            tm = localtime(&ti);
            如果 (v == TOK___DATE__) {
                static char const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, sizeof(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } 否则 {
                snprintf(buf, sizeof(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        返回 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static 整数 macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const 整数 *macro_str
    )
{
    Sym *s;
    整数 t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    整数 tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    当 (1) {
        TOK_GET(&t, &macro_str, &cval);
        如果 (t == 0 || t == TOK_EOF)
            break;
        如果 (t >= TOK_IDENT) {
            s = define_find(t);
            如果 (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            如果 (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (整数*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            如果 (macro_stack != str) {
                /* already finished by reading function macro arguments */
                break;
            }
            macro_str = macro_ptr;
            end_macro ();
        } 否则 如果 (t == ' ') {
            如果 (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } 否则 {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            如果 (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            如果 (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    返回 nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    整数 t;
    当 (macro_ptr) {
redo:
        t = *macro_ptr;
        如果 (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            如果 (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } 否则 如果 (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } 否则 如果 (t == TOK_EOF) {
            /* do nothing */
        } 否则 {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            如果 (t == '\\') {
                如果 (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        返回;
    }

    next_nomacro();
    t = tok;
    如果 (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        如果 (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        返回;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    如果 (t == TOK_PPNUM) {
        如果  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } 否则 如果 (t == TOK_PPSTR) {
        如果 (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(整数 last_tok)
{
    TokenString *str = &unget_buf;
    整数 alloc = 0;
    如果 (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    如果 (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

static const char * const target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# 如果 PTR_SIZE == 8
    "_WIN64\0"
# endif
#否则
# 如果 defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# 否则
    "__linux__\0"
    "__linux\0"
#  如果 TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

static void putdef(CString *cs, const char *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

static void putdefs(CString *cs, const char *p)
{
    当 (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, 整数 is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    如果 (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    如果 (is_asm)
      putdef(cs, "__ASSEMBLER__");
    如果 (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    如果 (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    如果 (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    如果 (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    如果 (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    如果 (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    如果 (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    如果 (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    如果 (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#如果 CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#否则
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, 整数 filetype)
{
    整数 is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_stack_ptr = s1->include_stack;
    s1->ifdef_stack_ptr = s1->ifdef_stack;
    file->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    pp_expr = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_stack[0] = 0;
    s1->pack_stack_ptr = s1->pack_stack;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    如果 (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        如果 (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        如果 (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_stack_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC void preprocess_end(TCCState *s1)
{
    当 (macro_stack)
        end_macro();
    macro_ptr = NULL;
    当 (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC 整数 set_idnum(整数 c, 整数 val)
{
    整数 prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    返回 prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    整数 i, c;
    const char *p, *r;

    /* init isid table */
    为(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    为(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * sizeof(TokenSym *));
    memset(s->cached_includes_hash, 0, sizeof s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    当 (*p) {
        r = p;
        为(;;) {
            c = *r++;
            如果 (c == '\0')
                break;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_push(TOK___LINE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___FILE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___DATE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___TIME__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___COUNTER__, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void tccpp_delete(TCCState *s)
{
    整数 i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    如果 (n > total_idents)
        total_idents = n;
    为 (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = NULL;

    /* free static buffers */
    cstr_free(&tokcstr);
    cstr_free(&cstr_buf);
    tok_str_free_str(tokstr_buf.str);
    tok_str_free_str(unget_buf.str);

    /* free allocators */
    tal_delete(&toksym_alloc);
    tal_delete(&tokstr_alloc);
}

/* ------------------------------------------------------------------------- */
/* tcc -E [-P[1]] [-dD} support */

static 整数 pp_need_space(整数 a, 整数 b);

static void tok_print(const 整数 *str, const char *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    整数 t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    当 (str) {
	TOK_GET(&t, &str, &cval);
	如果 (t == 0 || t == TOK_EOF)
	    break;
        如果 (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, 整数 level)
{
    整数 d = f->line_num - f->line_ref;

    如果 (s1->dflag & 4)
	返回;

    如果 (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } 否则 如果 (level == 0 && f->line_ref && d < 8) {
	当 (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } 否则 如果 (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } 否则 {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, 整数 v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    如果 (NULL == s || NULL == s->d)
        返回;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    如果 (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        如果 (a)
            为 (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                如果 (!(a = a->next))
                    break;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    整数 v, t;
    const char *vs;
    FILE *fp;

    t = pp_debug_tok;
    如果 (t == 0)
        返回;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    如果 (t == TOK_DEFINE) {
        define_print(s1, v);
    } 否则 如果 (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } 否则 如果 (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } 否则 如果 (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static 整数 pp_need_space(整数 a, 整数 b)
{
    返回 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static 整数 pp_check_he0xE(整数 t, const char *p)
{
    如果 (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        返回 'E';
    返回 t;
}

/* Preprocess the current file */
ST_FUNC 整数 tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    整数 token_seen, spcs, level;
    const char *p;
    char white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    如果 (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    如果 (s1->do_bench) {
	/* for PP benchmarks */
	do next(); 当 (tok != TOK_EOF);
	返回 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    如果 (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    为 (;;) {
        iptr = s1->include_stack_ptr;
        next();
        如果 (tok == TOK_EOF)
            break;

        level = s1->include_stack_ptr - iptr;
        如果 (level) {
            如果 (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        如果 (s1->dflag & 7) {
            pp_debug_defines(s1);
            如果 (s1->dflag & 4)
                continue;
        }

        如果 (is_space(tok)) {
            如果 (spcs < sizeof white - 1)
                white[spcs++] = tok;
            continue;
        } 否则 如果 (tok == TOK_LINEFEED) {
            spcs = 0;
            如果 (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } 否则 如果 (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } 否则 如果 (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    返回 0;
}

/* ------------------------------------------------------------------------- */
