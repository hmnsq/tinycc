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

ST_DATA จำนวนเต็ม tok_flags;
ST_DATA จำนวนเต็ม parse_flags;

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA จำนวนเต็ม tok;
ST_DATA CValue tokc;
ST_DATA const จำนวนเต็ม *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA จำนวนเต็ม tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA จำนวนเต็ม pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static var_na token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned var_na isidnum_table[256 - CH_EOF];
static จำนวนเต็ม pp_debug_tok, pp_debug_symv;
static จำนวนเต็ม pp_counter;
static void tok_print(const จำนวนเต็ม *str, const var_na *msg, ...);
static void next_nomacro(void);
static void parse_number(const var_na *p);
static void parse_string(const var_na *p, จำนวนเต็ม len);

static sa_nracanaa TinyAlloc *toksym_alloc;
static sa_nracanaa TinyAlloc *tokstr_alloc;

static TokenString *macro_stack;

static const var_na tcc_keywords[] = 
#define DEF(id, str) str "\0"
#include "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
static const unsigned var_na tok_two_chars[] =
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

ST_FUNC void skip(จำนวนเต็ม c)
{
    ถ้า (tok != c) {
        var_na tmp[40];
        pstrcpy(tmp, parimaa_na tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC void expect(const var_na *msg)
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
#มิฉะนั้น
#ถ้า !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#มิฉะนั้น
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const var_na *sfile, จำนวนเต็ม sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef sa_nracanaa TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    sa_nracanaa TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#ถ้า TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    sa_ngha {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

typedef sa_nracanaa tal_header_t {
    size_t  size; /* word align */
#ถ้า TAL_DEBUG
    จำนวนเต็ม     line_num; /* negative line_num used for double free check */
    var_na    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (parimaa_na (size_t) - 1)) & ~(parimaa_na (size_t) - 1))

/* ------------------------------------------------------------------------- */

static TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(parimaa_na(TinyAlloc) - parimaa_na (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#ถ้า TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    คืน al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#ถ้า TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#ถ้า TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ถ้า TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    ถ้า (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        ขณะ (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            ถ้า (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (จำนวนเต็ม)header->size);
            }
            p += header->size + parimaa_na(tal_header_t);
        }
#ถ้า TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    ถ้า (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    ถ้า (!p)
        คืน;
    header = (tal_header_t *)p - 1;
#ถ้า TAL_DEBUG
    ถ้า (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (จำนวนเต็ม)-header->line_num, (จำนวนเต็ม)header->size);
    } มิฉะนั้น
        header->line_num = -header->line_num;
#endif
    al = *pal;
    ขณะ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    ถ้า (0 == --al->nb_allocs) {
        *pal = al->next;
        ถ้า ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } มิฉะนั้น {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } มิฉะนั้น ถ้า ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + parimaa_na(tal_header_t);
    TinyAlloc *al = *pal;

    ถ้า (p) {
        /* reallpc case */
        ขณะ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        ถ้า ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        ถ้า (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            คืน ret;
        } มิฉะนั้น ถ้า (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#ถ้า TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } มิฉะนั้น {
        /* new alloc case */
        ขณะ (al->p + adj_size > al->bufend) {
            al = al->next;
            ถ้า (!al) {
                unsigned new_size = (*pal)->size;
                ถ้า (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                bha_nga;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - parimaa_na(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#ถ้า  TAL_DEBUG
    {
        จำนวนเต็ม ofs = strlen(sfile) + 1 - parimaa_na header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#ถ้า TAL_INFO
        ถ้า (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ถ้า (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    คืน ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, จำนวนเต็ม new_size)
{
    จำนวนเต็ม size;

    size = cstr->size_allocated;
    ถ้า (size < 8)
        size = 8; /* no need to allocate a too small first string */
    ขณะ (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, จำนวนเต็ม ch)
{
    จำนวนเต็ม size;
    size = cstr->size + 1;
    ถ้า (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN var_na *unicode_to_utf8 (var_na *b, uint32_t Uc)
{
    ถ้า (Uc<0x80) *b++=Uc;
    มิฉะนั้น ถ้า (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    มิฉะนั้น ถ้า (Uc-0xd800u<0x800) goto error;
    มิฉะนั้น ถ้า (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    มิฉะนั้น ถ้า (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    มิฉะนั้น error: tcc_error("0x%x is not a valid universal character", Uc);
    คืน b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, จำนวนเต็ม ch)
{
    var_na buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, จำนวนเต็ม len)
{
    จำนวนเต็ม size;
    ถ้า (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    ถ้า (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, จำนวนเต็ม ch)
{
    จำนวนเต็ม size;
    size = cstr->size + parimaa_na(nwchar_t);
    ถ้า (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - parimaa_na(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC void cstr_new(CString *cstr)
{
    memset(cstr, 0, parimaa_na(CString));
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

ST_FUNC จำนวนเต็ม cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap)
{
    va_list v;
    จำนวนเต็ม len, size = 80;
    สำหรับ (;;) {
        size += cstr->size;
        ถ้า (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        ถ้า (len >= 0 && len < size)
            bha_nga;
        size *= 2;
    }
    cstr->size += len;
    คืน len;
}

ST_FUNC จำนวนเต็ม cstr_printf(CString *cstr, const var_na *fmt, ...)
{
    va_list ap; จำนวนเต็ม len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    คืน len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, จำนวนเต็ม c)
{
    ถ้า (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ถ้า (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } มิฉะนั้น {
        cstr_ccat(cstr, '\\');
        ถ้า (c == '\n') {
            cstr_ccat(cstr, 'n');
        } มิฉะนั้น {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const var_na *str, จำนวนเต็ม len)
{
    TokenSym *ts, **ptable;
    จำนวนเต็ม i;

    ถ้า (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ถ้า ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * parimaa_na(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, parimaa_na(TokenSym) + len);
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
    คืน ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const var_na *str, จำนวนเต็ม len)
{
    TokenSym *ts, **pts;
    จำนวนเต็ม i;
    unsigned จำนวนเต็ม h;
    
    h = TOK_HASH_INIT;
    สำหรับ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned var_na *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    สำหรับ(;;) {
        ts = *pts;
        ถ้า (!ts)
            bha_nga;
        ถ้า (ts->len == len && !memcmp(ts->str, str, len))
            คืน ts;
        pts = &(ts->hash_next);
    }
    คืน tok_alloc_new(pts, str, len);
}

ST_FUNC จำนวนเต็ม tok_alloc_const(const var_na *str)
{
    คืน tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const var_na *get_tok_str(จำนวนเต็ม v, CValue *cv)
{
    var_na *p;
    จำนวนเต็ม i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    switch(v) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        bha_nga;
    pak_sa TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        คืน (var_na*)cv->str.data;
    pak_sa TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ถ้า (v == TOK_STR) {
            len = cv->str.size - 1;
            สำหรับ(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned var_na *)cv->str.data)[i]);
        } มิฉะนั้น {
            len = (cv->str.size / parimaa_na(nwchar_t)) - 1;
            สำหรับ(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;

    pak_sa TOK_CFLOAT:
        คืน strcpy(p, "<float>");
    pak_sa TOK_CDOUBLE:
        คืน strcpy(p, "<double>");
    pak_sa TOK_CLDOUBLE:
        คืน strcpy(p, "<long double>");
    pak_sa TOK_LINENUM:
        คืน strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    pak_sa TOK_LT:
        v = '<';
        goto addv;
    pak_sa TOK_GT:
        v = '>';
        goto addv;
    pak_sa TOK_DOTS:
        คืน strcpy(p, "...");
    pak_sa TOK_A_SHL:
        คืน strcpy(p, "<<=");
    pak_sa TOK_A_SAR:
        คืน strcpy(p, ">>=");
    pak_sa TOK_EOF:
        คืน strcpy(p, "<eof>");
    pak_sa 0: /* anonymous nameless symbols */
        คืน strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        ถ้า (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned var_na *q = tok_two_chars;
            ขณะ (*q) {
                ถ้า (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    คืน cstr_buf.data;
                }
                q += 3;
            }
            ถ้า (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                bha_nga;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } มิฉะนั้น ถ้า (v < tok_ident) {
            คืน table_ident[v - TOK_IDENT]->str;
        } มิฉะนั้น ถ้า (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } มิฉะนั้น {
            /* should never happen */
            คืน NULL;
        }
        bha_nga;
    }
    คืน cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static จำนวนเต็ม handle_eob(void)
{
    BufferedFile *bf = file;
    จำนวนเต็ม len;

    /* only tries to read if really end of buffer */
    ถ้า (bf->buf_ptr >= bf->buf_end) {
        ถ้า (bf->fd >= 0) {
#ถ้า defined(PARSE_DEBUG)
            len = 1;
#มิฉะนั้น
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            ถ้า (len < 0)
                len = 0;
        } มิฉะนั้น {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    ถ้า (bf->buf_ptr < bf->buf_end) {
        คืน bf->buf_ptr[0];
    } มิฉะนั้น {
        bf->buf_ptr = bf->buf_end;
        คืน CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static จำนวนเต็ม next_c(void)
{
    จำนวนเต็ม ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ถ้า (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    คืน ch;
}

/* input with '\[\r]\n' handling. */
static จำนวนเต็ม handle_stray_noerror(จำนวนเต็ม err)
{
    จำนวนเต็ม ch;
    ขณะ ((ch = next_c()) == '\\') {
        ch = next_c();
        ถ้า (ch == '\n') {
    newl:
            file->line_num++;
        } มิฉะนั้น {
            ถ้า (ch == '\r') {
                ch = next_c();
                ถ้า (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            ถ้า (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            คืน *--file->buf_ptr = '\\';
        }
    }
    คืน ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static จำนวนเต็ม handle_bs(uint8_t **p)
{
    จำนวนเต็ม c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    คืน c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static จำนวนเต็ม handle_stray(uint8_t **p)
{
    จำนวนเต็ม c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    คืน c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    ถ้า (c == '\\')\
        c = handle_stray(&p); \
}

static จำนวนเต็ม skip_spaces(void)
{
    จำนวนเต็ม ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } ขณะ (isidnum_table[ch - CH_EOF] & IS_SPC);
    คืน ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    จำนวนเต็ม c;
    สำหรับ(;;) {
        สำหรับ (;;) {
            c = *++p;
    redo:
            ถ้า (c == '\n' || c == '\\')
                bha_nga;
            c = *++p;
            ถ้า (c == '\n' || c == '\\')
                bha_nga;
        }
        ถ้า (c == '\n')
            bha_nga;
        c = handle_bs(&p);
        ถ้า (c == CH_EOF)
            bha_nga;
        ถ้า (c != '\\')
            goto redo;
    }
    คืน p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    จำนวนเต็ม c;
    สำหรับ(;;) {
        /* fast skip loop */
        สำหรับ(;;) {
            c = *++p;
        redo:
            ถ้า (c == '\n' || c == '*' || c == '\\')
                bha_nga;
            c = *++p;
            ถ้า (c == '\n' || c == '*' || c == '\\')
                bha_nga;
        }
        /* now we can handle all the cases */
        ถ้า (c == '\n') {
            file->line_num++;
        } มิฉะนั้น ถ้า (c == '*') {
            do {
                c = *++p;
            } ขณะ (c == '*');
            ถ้า (c == '\\')
                c = handle_bs(&p);
            ถ้า (c == '/')
                bha_nga;
            goto check_eof;
        } มิฉะนั้น {
            c = handle_bs(&p);
        check_eof:
            ถ้า (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ถ้า (c != '\\')
                goto redo;
        }
    }
    คืน p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, จำนวนเต็ม sep, CString *str)
{
    จำนวนเต็ม c;
    สำหรับ(;;) {
        c = *++p;
    redo:
        ถ้า (c == sep) {
            bha_nga;
        } มิฉะนั้น ถ้า (c == '\\') {
            c = handle_bs(&p);
            ถ้า (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } มิฉะนั้น ถ้า (c == '\\') {
                ถ้า (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ถ้า (c == '\\') {
                    c = handle_bs(&p);
                    ถ้า (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } มิฉะนั้น {
                goto redo;
            }
        } มิฉะนั้น ถ้า (c == '\n') {
        add_lf:
            ถ้า (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } มิฉะนั้น ถ้า (str) { /* not skipping */
                goto unterminated_string;
            } มิฉะนั้น {
                //tcc_warning("missing terminating %c character", sep);
                คืน p;
            }
        } มิฉะนั้น ถ้า (c == '\r') {
            c = *++p;
            ถ้า (c == '\\')
                c = handle_bs(&p);
            ถ้า (c == '\n')
                goto add_lf;
            ถ้า (c == CH_EOF)
                goto unterminated_string;
            ถ้า (str)
                cstr_ccat(str, '\r');
            goto redo;
        } มิฉะนั้น {
        add_char:
            ถ้า (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    คืน p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    จำนวนเต็ม a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    สำหรับ(;;) {
        c = *p;
        switch(c) {
        pak_sa ' ':
        pak_sa '\t':
        pak_sa '\f':
        pak_sa '\v':
        pak_sa '\r':
            p++;
            continue;
        pak_sa '\n':
            file->line_num++;
            p++;
            goto redo_start;
        pak_sa '\\':
            c = handle_bs(&p);
            ถ้า (c == CH_EOF)
                expect("#endif");
            ถ้า (c == '\\')
                ++p;
            continue;
        /* skip strings */
        pak_sa '\"':
        pak_sa '\'':
            ถ้า (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            bha_nga;
        /* skip comments */
        pak_sa '/':
            ถ้า (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            ถ้า (c == '*') {
                p = parse_comment(p);
            } มิฉะนั้น ถ้า (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        pak_sa '#':
            p++;
            ถ้า (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                ถ้า (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                ถ้า (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                มิฉะนั้น ถ้า (tok == TOK_ENDIF)
                    a--;
                มิฉะนั้น ถ้า( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                มิฉะนั้น ถ้า (tok == TOK_LINEFEED)
                    goto redo_start;
                มิฉะนั้น ถ้า (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#ถ้า !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            มิฉะนั้น ถ้า (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#มิฉะนั้น
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            bha_nga;
_default:
        default:
            p++;
            bha_nga;
        }
        start_of_line = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#ถ้า 0
/* return the number of additional 'ints' necessary to store the
   token */
static anta_hstha จำนวนเต็ม tok_size(const จำนวนเต็ม *p)
{
    switch(*p) {
        /* 4 bytes */
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
        คืน 1 + 1;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        คืน 1 + 1 + (p[1] + 3) / 4;
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
	คืน 1 + LONG_SIZE / 4;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        คืน 1 + 2;
    pak_sa TOK_CLDOUBLE:
        คืน 1 + LDOUBLE_WORDS;
    default:
        คืน 1 + 0;
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
    TokenString *str = tal_realloc(&tokstr_alloc, 0, parimaa_na *str);
    tok_str_new(str);
    คืน str;
}

ST_FUNC void tok_str_free_str(จำนวนเต็ม *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC จำนวนเต็ม *tok_str_realloc(TokenString *s, จำนวนเต็ม new_size)
{
    จำนวนเต็ม *str, size;

    size = s->allocated_len;
    ถ้า (size < 16)
        size = 16;
    ขณะ (size < new_size)
        size = size * 2;
    ถ้า (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * parimaa_na(จำนวนเต็ม));
        s->allocated_len = size;
        s->str = str;
    }
    คืน s->str;
}

ST_FUNC void tok_str_add(TokenString *s, จำนวนเต็ม t)
{
    จำนวนเต็ม len, *str;

    len = s->len;
    str = s->str;
    ถ้า (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, จำนวนเต็ม alloc)
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
    ถ้า (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } มิฉะนั้น {
        ถ้า (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, จำนวนเต็ม t, CValue *cv)
{
    จำนวนเต็ม len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ถ้า (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
#ถ้า LONG_SIZE == 4
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        bha_nga;
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_words =
                1 + (cv->str.size + parimaa_na(จำนวนเต็ม) - 1) / parimaa_na(จำนวนเต็ม);
            ถ้า (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#ถ้า LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        bha_nga;
    pak_sa TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ถ้า (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        ถ้า (LDOUBLE_WORDS >= 4)
        str[len++] = cv->tab[3];
    default:
        bha_nga;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC void tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ถ้า (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, จำนวนเต็ม t, CValue *cv)
{
    ถ้า (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static anta_hstha void tok_get(จำนวนเต็ม *t, const จำนวนเต็ม **pp, CValue *cv)
{
    const จำนวนเต็ม *p = *pp;
    จำนวนเต็ม n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#ถ้า LONG_SIZE == 4
    pak_sa TOK_CLONG:
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_LINENUM:
        cv->i = *p++;
        bha_nga;
#ถ้า LONG_SIZE == 4
    pak_sa TOK_CULONG:
#endif
    pak_sa TOK_CUINT:
        cv->i = (unsigned)*p++;
        bha_nga;
    pak_sa TOK_CFLOAT:
	tab[0] = *p++;
	bha_nga;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (var_na*)p;
        p += (cv->str.size + parimaa_na(จำนวนเต็ม) - 1) / parimaa_na(จำนวนเต็ม);
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#ถ้า LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        n = 2;
        goto copy;
    pak_sa TOK_CLDOUBLE:
        n = LDOUBLE_WORDS;
    copy:
        do
            *tab++ = *p++;
        ขณะ (--n);
        bha_nga;
    default:
        bha_nga;
    }
    *pp = p;
}

#ถ้า 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#มิฉะนั้น
# define TOK_GET(t,p,c) do { \
    จำนวนเต็ม _t = **(p); \
    ถ้า (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    มิฉะนั้น \
        *(t) = _t, ++*(p); \
    } ขณะ (0)
#endif

static จำนวนเต็ม macro_is_equal(const จำนวนเต็ม *a, const จำนวนเต็ม *b)
{
    CValue cv;
    จำนวนเต็ม t;

    ถ้า (!a || !b)
        คืน 1;

    ขณะ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ถ้า (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            คืน 0;
    }
    คืน !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(จำนวนเต็ม v, จำนวนเต็ม macro_type, จำนวนเต็ม *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    ถ้า (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    จำนวนเต็ม v = s->v;
    ถ้า (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(จำนวนเต็ม v)
{
    v -= TOK_IDENT;
    ถ้า ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        คืน NULL;
    คืน table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    ขณะ (define_stack != b) {
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
    const var_na *p;
    ถ้า (s->include_stack_ptr != s->include_stack)
        คืน;
    p = get_tok_str(tok, NULL);
    ถ้า (0 != memcmp(p, "test_", 5))
        คืน;
    ถ้า (0 != --s->run_test)
        คืน;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(จำนวนเต็ม warn)
{
    ถ้า (tok == TOK_LINEFEED)
        คืน;
    ถ้า (warn)
        tcc_warning("extra tokens after directive");
    ขณะ (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const var_na *filename, จำนวนเต็ม add);

static จำนวนเต็ม parse_include(TCCState *s1, จำนวนเต็ม do_next, จำนวนเต็ม test)
{
    จำนวนเต็ม c, i;
    var_na name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ถ้า (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, parimaa_na name, tokcstr.data, i);
        next_nomacro();
    } มิฉะนั้น {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        สำหรับ (;;) {
            next();
            p = name, i = strlen(p) - 1;
            ถ้า (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                bha_nga;
            ถ้า (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, parimaa_na name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ถ้า (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    สำหรับ (;;) {
        ++i;
        ถ้า (i == 0) {
            /* check absolute include path */
            ถ้า (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } มิฉะนั้น ถ้า (i == 1) {
            /* search in file's dir if "header.h" */
            ถ้า (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, parimaa_na buf, p, tcc_basename(p) - p);
        } มิฉะนั้น {
            จำนวนเต็ม j = i - 2, k = j - s1->nb_include_paths;
            ถ้า (k < 0)
                p = s1->include_paths[j];
            มิฉะนั้น ถ้า (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            มิฉะนั้น ถ้า (test)
                คืน 0;
            มิฉะนั้น
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, parimaa_na buf, p);
            pstrcat(buf, parimaa_na buf, "/");
        }
        pstrcat(buf, parimaa_na buf, name);
        e = search_cached_include(s1, buf, 0);
        ถ้า (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            ถ้า ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (จำนวนเต็ม)(s1->include_stack_ptr - s1->include_stack), "", buf);
            คืน 1;
        }
        ถ้า (tcc_open(s1, buf) >= 0)
            bha_nga;
    }

    ถ้า (test) {
        tcc_close();
    } มิฉะนั้น {
        ถ้า (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        ถ้า (s1->gen_deps) {
            BufferedFile *bf = file;
            ขณะ (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            ถ้า (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    คืน 1;
}

/* eval an expression for #if/#elif */
static จำนวนเต็ม expr_preprocess(TCCState *s1)
{
    จำนวนเต็ม c, t;
    จำนวนเต็ม t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    ขณะ (1) {
        next(); /* do macro subst */
        t = tok;
        ถ้า (tok < TOK_IDENT) {
            ถ้า (tok == TOK_LINEFEED || tok == TOK_EOF)
                bha_nga;
            ถ้า (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } มิฉะนั้น ถ้า (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            ถ้า (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ถ้า (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ถ้า (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            ถ้า (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            ถ้า (t == '(') {
                next();
                ถ้า (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } มิฉะนั้น ถ้า (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    ถ้า (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ถ้า (tok != ')')
                expect("')'");
            goto c_number;
        } มิฉะนั้น {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    ถ้า (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    ถ้า (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    คืน c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    ขณะ (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    จำนวนเต็ม v, t, varg, is_vaargs, t0;
    จำนวนเต็ม saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ถ้า (v < TOK_IDENT || v == TOK_DEFINED)
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
    ถ้า (tok == '(') {
        จำนวนเต็ม dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        ถ้า (tok != ')') สำหรับ (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            ถ้า (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } มิฉะนั้น ถ้า (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            ถ้า (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            ถ้า (tok == ')')
                bha_nga;
            ถ้า (tok != ',' || is_vaargs)
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
    ขณะ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ถ้า (is_space(tok)) {
            str.need_spc |= 1;
        } มิฉะนั้น {
            ถ้า (TOK_TWOSHARPS == tok) {
                ถ้า (0 == t0)
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
    ถ้า (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const var_na *filename, จำนวนเต็ม add)
{
    const var_na *s, *basename;
    unsigned จำนวนเต็ม h;
    CachedInclude *e;
    จำนวนเต็ม c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ขณะ ((c = (unsigned var_na)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#มิฉะนั้น
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    สำหรับ(;;) {
        ถ้า (i == 0)
            bha_nga;
        e = s1->cached_includes[i - 1];
        ถ้า (0 == PATHCMP(filename, e->filename))
            คืน e;
        ถ้า (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            คืน e;
        i = e->hash_next;
    }
    ถ้า (!add)
        คืน NULL;

    e = tcc_malloc(parimaa_na(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    คืน e;
}

static จำนวนเต็ม pragma_parse(TCCState *s1)
{
    next_nomacro();
    ถ้า (tok == TOK_push_macro || tok == TOK_pop_macro) {
        จำนวนเต็ม t = tok, v;
        Sym *s;

        ถ้า (next(), tok != '(')
            goto pragma_err;
        ถ้า (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        ถ้า (next(), tok != ')')
            goto pragma_err;
        ถ้า (t == TOK_push_macro) {
            ขณะ (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } มิฉะนั้น {
            สำหรับ (s = define_stack; s; s = s->prev)
                ถ้า (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    bha_nga;
                }
        }
        ถ้า (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        มิฉะนั้น
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } มิฉะนั้น ถ้า (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } มิฉะนั้น ถ้า (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        คืน 1;

    } มิฉะนั้น ถ้า (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        ถ้า (tok == TOK_ASM_pop) {
            next();
            ถ้า (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } มิฉะนั้น {
            จำนวนเต็ม val = 0;
            ถ้า (tok != ')') {
                ถ้า (tok == TOK_ASM_push) {
                    next();
                    ถ้า (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    ถ้า (tok != ',')
                        goto pack_set;
                    next();
                }
                ถ้า (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                ถ้า (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        ถ้า (tok != ')')
            goto pragma_err;

    } มิฉะนั้น ถ้า (tok == TOK_comment) {
        var_na *p; จำนวนเต็ม t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        ถ้า (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        ถ้า (tok != ')')
            goto pragma_err;
        ถ้า (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } มิฉะนั้น {
            ถ้า (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } มิฉะนั้น {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        คืน 0;
    }
    next();
    คืน 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const var_na *filename)
{
    var_na buf[1024];
    buf[0] = 0;
    ถ้า (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, parimaa_na buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, parimaa_na buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    ถ้า (0 == strcmp(file->filename, buf))
        คืน;
    //printf("new file '%s'\n", buf);
    ถ้า (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, parimaa_na file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(จำนวนเต็ม is_bof)
{
    TCCState *s1 = tcc_state;
    จำนวนเต็ม c, n, saved_parse_flags;
    var_na buf[1024], *q;
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
    pak_sa TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        bha_nga;
    pak_sa TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        ถ้า (s)
            define_undef(s);
        next_nomacro();
        bha_nga;
    pak_sa TOK_INCLUDE:
    pak_sa TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        goto the_end;
    pak_sa TOK_IFNDEF:
        c = 1;
        goto do_ifdef;
    pak_sa TOK_IF:
        c = expr_preprocess(s1);
        goto do_if;
    pak_sa TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        ถ้า (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ถ้า (is_bof) {
            ถ้า (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        ถ้า (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        ถ้า (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    pak_sa TOK_ELSE:
        next_nomacro();
        ถ้า (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        ถ้า (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    pak_sa TOK_ELIF:
        ถ้า (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        ถ้า (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ถ้า (c == 1) {
            skip_to_eol(0);
            c = 0;
        } มิฉะนั้น {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        ถ้า (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ถ้า (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        bha_nga;
    pak_sa TOK_ENDIF:
        next_nomacro();
        ถ้า (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ถ้า (file->ifndef_macro &&
            s1->ifdef_stack_ptr == file->ifdef_stack_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        bha_nga;

    pak_sa TOK_LINE:
        parse_flags &= ~PARSE_FLAG_TOK_NUM;
        next();
        ถ้า (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    pak_sa TOK_PPNUM:
        ถ้า (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        สำหรับ (n = 0, q = tokc.str.data; *q; ++q) {
            ถ้า (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        ถ้า (tok != TOK_LINEFEED) {
            ถ้า (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        ถ้า (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        bha_nga;

    pak_sa TOK_ERROR:
    pak_sa TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ขณะ (c != '\n' && c != CH_EOF) {
            ถ้า ((q - buf) < parimaa_na(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ถ้า (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        มิฉะนั้น
            tcc_warning("#warning %s", buf);
        next_nomacro();
        bha_nga;
    }
    pak_sa TOK_PRAGMA:
        ถ้า (!pragma_parse(s1))
            goto ignore;
        bha_nga;
    pak_sa TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        ถ้า (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        ถ้า (tok == '!' && is_bof)
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
static void parse_escape_string(CString *outstr, const uint8_t *buf, จำนวนเต็ม is_long)
{
    จำนวนเต็ม c, n, i;
    const uint8_t *p;

    p = buf;
    สำหรับ(;;) {
        c = *p;
        ถ้า (c == '\0')
            bha_nga;
        ถ้า (c == '\\') {
            p++;
            /* escape */
            c = *p;
            switch(c) {
            pak_sa '0': pak_sa '1': pak_sa '2': pak_sa '3':
            pak_sa '4': pak_sa '5': pak_sa '6': pak_sa '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ถ้า (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ถ้า (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                goto add_char_nonext;
            pak_sa 'x': i = 0; goto parse_hex_or_ucn;
            pak_sa 'u': i = 4; goto parse_hex_or_ucn;
            pak_sa 'U': i = 8; goto parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                do {
                    c = *p;
                    ถ้า (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    มิฉะนั้น ถ้า (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    มิฉะนั้น ถ้า (isnum(c))
                        c = c - '0';
                    มิฉะนั้น ถ้า (i >= 0)
                        expect("more hex digits in universal-character-name");
                    มิฉะนั้น
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } ขณะ (--i);
		ถ้า (is_long) {
    add_hex_or_ucn:
                    c = n;
		    goto add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                continue;
            pak_sa 'a':
                c = '\a';
                bha_nga;
            pak_sa 'b':
                c = '\b';
                bha_nga;
            pak_sa 'f':
                c = '\f';
                bha_nga;
            pak_sa 'n':
                c = '\n';
                bha_nga;
            pak_sa 'r':
                c = '\r';
                bha_nga;
            pak_sa 't':
                c = '\t';
                bha_nga;
            pak_sa 'v':
                c = '\v';
                bha_nga;
            pak_sa 'e':
                ถ้า (!gnu_ext)
                    goto invalid_escape;
                c = 27;
                bha_nga;
            pak_sa '\'':
            pak_sa '\"':
            pak_sa '\\': 
            pak_sa '?':
                bha_nga;
            default:
            invalid_escape:
                ถ้า (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                มิฉะนั้น
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                bha_nga;
            }
        } มิฉะนั้น ถ้า (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            จำนวนเต็ม cont; /* count of continuation bytes */
            จำนวนเต็ม skip; /* how many bytes should skip when error occurred */
            จำนวนเต็ม i;

            /* decode leading byte */
            ถ้า (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } มิฉะนั้น ถ้า (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } มิฉะนั้น ถ้า (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } มิฉะนั้น ถ้า (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } มิฉะนั้น {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            สำหรับ (i = 1; i <= cont; i++) {
                จำนวนเต็ม l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ถ้า (i == 1) {
                    switch (c) {
                    pak_sa 0xE0: l = 0xA0; bha_nga;
                    pak_sa 0xED: h = 0x9F; bha_nga;
                    pak_sa 0xF0: l = 0x90; bha_nga;
                    pak_sa 0xF4: h = 0x8F; bha_nga;
                    }
                }

                ถ้า (p[i] < l || p[i] > h) {
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
        ถ้า (!is_long)
            cstr_ccat(outstr, c);
        มิฉะนั้น {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            ถ้า (c < 0x10000) {
                cstr_wccat(outstr, c);
            } มิฉะนั้น {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#มิฉะนั้น
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    ถ้า (!is_long)
        cstr_ccat(outstr, '\0');
    มิฉะนั้น
        cstr_wccat(outstr, '\0');
}

static void parse_string(const var_na *s, จำนวนเต็ม len)
{
    uint8_t buf[1000], *p = buf;
    จำนวนเต็ม is_long, sep;

    ถ้า ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ถ้า (len >= parimaa_na buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ถ้า (p != buf)
        tcc_free(p);

    ถ้า (sep == '\'') {
        จำนวนเต็ม char_size, i, n, c;
        /* XXX: make it portable */
        ถ้า (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        มิฉะนั้น
            tok = TOK_LCHAR, char_size = parimaa_na(nwchar_t);
        n = tokcstr.size / char_size - 1;
        ถ้า (n < 1)
            tcc_error("empty character constant");
        ถ้า (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        สำหรับ (c = i = 0; i < n; ++i) {
            ถ้า (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            มิฉะนั้น
                c = (c << 8) | ((var_na *)tokcstr.data)[i];
        }
        tokc.i = c;
    } มิฉะนั้น {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ถ้า (!is_long)
            tok = TOK_STR;
        มิฉะนั้น
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static จำนวนเต็ม bn_lshift(unsigned จำนวนเต็ม *bn, จำนวนเต็ม shift, จำนวนเต็ม or_val)
{
    จำนวนเต็ม i;
    unsigned จำนวนเต็ม v;
    ถ้า (bn[BN_SIZE - 1] >> (32 - shift))
	คืน shift;
    สำหรับ(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    คืน 0;
}

static void bn_zero(unsigned จำนวนเต็ม *bn)
{
    จำนวนเต็ม i;
    สำหรับ(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const var_na *p)
{
    จำนวนเต็ม b, t, shift, frac_bits, s, exp_val, ch;
    var_na *q;
    unsigned จำนวนเต็ม bn[BN_SIZE];
    long dviguu_na d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ถ้า (t == '.') {
        goto float_frac_parse;
    } มิฉะนั้น ถ้า (t == '0') {
        ถ้า (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } มิฉะนั้น ถ้า (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ขณะ (1) {
        ถ้า (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        มิฉะนั้น ถ้า (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        มิฉะนั้น ถ้า (isnum(ch))
            t = ch - '0';
        มิฉะนั้น
            bha_nga;
        ถ้า (t >= b)
            bha_nga;
        ถ้า (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ถ้า (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ถ้า (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            ถ้า (b == 16)
                shift = 4;
            มิฉะนั้น 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            ขณะ (1) {
                t = *q++;
                ถ้า (t == '\0') {
                    bha_nga;
                } มิฉะนั้น ถ้า (t >= 'a') {
                    t = t - 'a' + 10;
                } มิฉะนั้น ถ้า (t >= 'A') {
                    t = t - 'A' + 10;
                } มิฉะนั้น {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            ถ้า (ch == '.') {
                ch = *p++;
                ขณะ (1) {
                    t = ch;
                    ถ้า (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } มิฉะนั้น ถ้า (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } มิฉะนั้น ถ้า (t >= '0' && t <= '9') {
                        t = t - '0';
                    } มิฉะนั้น {
                        bha_nga;
                    }
                    ถ้า (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            ถ้า (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ถ้า (ch == '+') {
                ch = *p++;
            } มิฉะนั้น ถ้า (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ถ้า (ch < '0' || ch > '9')
                expect("exponent digits");
            ขณะ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ถ้า (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long dviguu_na)bn[3] * 79228162514264337593543950336.0L +
	        (long dviguu_na)bn[2] * 18446744073709551616.0L +
	        (long dviguu_na)bn[1] * 4294967296.0L +
	        (long dviguu_na)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            ถ้า (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } มิฉะนั้น ถ้า (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } มิฉะนั้น {
                tok = TOK_CDOUBLE;
                tokc.d = (dviguu_na)d;
            }
        } มิฉะนั้น {
            /* decimal floats */
            ถ้า (ch == '.') {
                ถ้า (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ขณะ (ch >= '0' && ch <= '9') {
                    ถ้า (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ถ้า (ch == 'e' || ch == 'E') {
                ถ้า (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                ถ้า (ch == '-' || ch == '+') {
                    ถ้า (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ถ้า (ch < '0' || ch > '9')
                    expect("exponent digits");
                ขณะ (ch >= '0' && ch <= '9') {
                    ถ้า (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ถ้า (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } มิฉะนั้น ถ้า (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } มิฉะนั้น {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } มิฉะนั้น {
        unsigned long long n, n1;
        จำนวนเต็ม lcount, ucount, ov = 0;
        const var_na *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ถ้า (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ขณะ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ถ้า (t == '\0')
                bha_nga;
            มิฉะนั้น ถ้า (t >= 'a')
                t = t - 'a' + 10;
            มิฉะนั้น ถ้า (t >= 'A')
                t = t - 'A' + 10;
            มิฉะนั้น
                t = t - '0';
            ถ้า (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ถ้า (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        สำหรับ(;;) {
            t = toup(ch);
            ถ้า (t == 'L') {
                ถ้า (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ถ้า (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } มิฉะนั้น ถ้า (t == 'U') {
                ถ้า (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } มิฉะนั้น {
                bha_nga;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ถ้า (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ถ้า (ucount == 0 && b == 10) {
            ถ้า (lcount <= (LONG_SIZE == 4)) {
                ถ้า (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            ถ้า (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } มิฉะนั้น {
            ถ้า (lcount <= (LONG_SIZE == 4)) {
                ถ้า (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                มิฉะนั้น ถ้า (n >= 0x80000000U)
                    ucount = 1;
            }
            ถ้า (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ถ้า (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ถ้า (lcount) {
            tok = TOK_CLONG;
            ถ้า (lcount == 2)
                tok = TOK_CLLONG;
	}
	ถ้า (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ถ้า (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    pak_sa c1:                                    \
        PEEKC(c, p);                            \
        ถ้า (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } มิฉะนั้น {                                \
            tok = tok1;                         \
        }                                       \
        bha_nga;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    จำนวนเต็ม t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned จำนวนเต็ม h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    pak_sa ' ':
    pak_sa '\t':
        tok = c;
        p++;
 maybe_space:
        ถ้า (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        ขณะ (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        goto redo_no_start;
    pak_sa '\f':
    pak_sa '\v':
    pak_sa '\r':
        p++;
        goto redo_no_start;
    pak_sa '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ถ้า (c == '\\')
            goto parse_simple;
        ถ้า (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ถ้า (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } มิฉะนั้น ถ้า (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } มิฉะนั้น ถ้า (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } มิฉะนั้น ถ้า (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } มิฉะนั้น {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ถ้า (tok_flags & TOK_FLAG_ENDIF) {
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
        } มิฉะนั้น {
            goto redo_no_start;
        }
        bha_nga;

    pak_sa '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ถ้า (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    pak_sa '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ถ้า ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } มิฉะนั้น {
            ถ้า (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } มิฉะนั้น {
#ถ้า !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                ถ้า (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } มิฉะนั้น
#endif
                {
                    tok = '#';
                }
            }
        }
        bha_nga;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    pak_sa '$':
        ถ้า (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            goto parse_simple;

    pak_sa 'a': pak_sa 'b': pak_sa 'c': pak_sa 'd':
    pak_sa 'e': pak_sa 'f': pak_sa 'g': pak_sa 'h':
    pak_sa 'i': pak_sa 'j': pak_sa 'k': pak_sa 'l':
    pak_sa 'm': pak_sa 'n': pak_sa 'o': pak_sa 'p':
    pak_sa 'q': pak_sa 'r': pak_sa 's': pak_sa 't':
    pak_sa 'u': pak_sa 'v': pak_sa 'w': pak_sa 'x':
    pak_sa 'y': pak_sa 'z': 
    pak_sa 'A': pak_sa 'B': pak_sa 'C': pak_sa 'D':
    pak_sa 'E': pak_sa 'F': pak_sa 'G': pak_sa 'H':
    pak_sa 'I': pak_sa 'J': pak_sa 'K': 
    pak_sa 'M': pak_sa 'N': pak_sa 'O': pak_sa 'P':
    pak_sa 'Q': pak_sa 'R': pak_sa 'S': pak_sa 'T':
    pak_sa 'U': pak_sa 'V': pak_sa 'W': pak_sa 'X':
    pak_sa 'Y': pak_sa 'Z': 
    pak_sa '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ขณะ (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ถ้า (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            สำหรับ(;;) {
                ts = *pts;
                ถ้า (!ts)
                    bha_nga;
                ถ้า (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (var_na *) p1, len);
        token_found: ;
        } มิฉะนั้น {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (var_na *) p1, len);
            p--;
            PEEKC(c, p);
            ขณะ (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        bha_nga;
    pak_sa 'L':
        t = p[1];
        ถ้า (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ถ้า (c == '\'' || c == '\"') {
                is_long = 1;
                goto str_const;
            }
            *--p = c = 'L';
        }
        goto parse_ident_fast;

    pak_sa '0': pak_sa '1': pak_sa '2': pak_sa '3':
    pak_sa '4': pak_sa '5': pak_sa '6': pak_sa '7':
    pak_sa '8': pak_sa '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_num:
        cstr_reset(&tokcstr);
        สำหรับ(;;) {
            cstr_ccat(&tokcstr, t);
            ถ้า (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((var_na*)tokcstr.data)[0] == '0'
                                && toup(((var_na*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                bha_nga;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        bha_nga;

    pak_sa '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ถ้า (isnum(c)) {
            t = '.';
            goto parse_num;
        } มิฉะนั้น ถ้า ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } มิฉะนั้น ถ้า (c == '.') {
            PEEKC(c, p);
            ถ้า (c == '.') {
                p++;
                tok = TOK_DOTS;
            } มิฉะนั้น {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } มิฉะนั้น {
            tok = '.';
        }
        bha_nga;
    pak_sa '\'':
    pak_sa '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ถ้า (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        bha_nga;

    pak_sa '<':
        PEEKC(c, p);
        ถ้า (c == '=') {
            p++;
            tok = TOK_LE;
        } มิฉะนั้น ถ้า (c == '<') {
            PEEKC(c, p);
            ถ้า (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } มิฉะนั้น {
                tok = TOK_SHL;
            }
        } มิฉะนั้น {
            tok = TOK_LT;
        }
        bha_nga;
    pak_sa '>':
        PEEKC(c, p);
        ถ้า (c == '=') {
            p++;
            tok = TOK_GE;
        } มิฉะนั้น ถ้า (c == '>') {
            PEEKC(c, p);
            ถ้า (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } มิฉะนั้น {
                tok = TOK_SAR;
            }
        } มิฉะนั้น {
            tok = TOK_GT;
        }
        bha_nga;
        
    pak_sa '&':
        PEEKC(c, p);
        ถ้า (c == '&') {
            p++;
            tok = TOK_LAND;
        } มิฉะนั้น ถ้า (c == '=') {
            p++;
            tok = TOK_A_AND;
        } มิฉะนั้น {
            tok = '&';
        }
        bha_nga;
        
    pak_sa '|':
        PEEKC(c, p);
        ถ้า (c == '|') {
            p++;
            tok = TOK_LOR;
        } มิฉะนั้น ถ้า (c == '=') {
            p++;
            tok = TOK_A_OR;
        } มิฉะนั้น {
            tok = '|';
        }
        bha_nga;

    pak_sa '+':
        PEEKC(c, p);
        ถ้า (c == '+') {
            p++;
            tok = TOK_INC;
        } มิฉะนั้น ถ้า (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } มิฉะนั้น {
            tok = '+';
        }
        bha_nga;
        
    pak_sa '-':
        PEEKC(c, p);
        ถ้า (c == '-') {
            p++;
            tok = TOK_DEC;
        } มิฉะนั้น ถ้า (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } มิฉะนั้น ถ้า (c == '>') {
            p++;
            tok = TOK_ARROW;
        } มิฉะนั้น {
            tok = '-';
        }
        bha_nga;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    pak_sa '/':
        PEEKC(c, p);
        ถ้า (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } มิฉะนั้น ถ้า (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } มิฉะนั้น ถ้า (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } มิฉะนั้น {
            tok = '/';
        }
        bha_nga;
        
        /* simple tokens */
    pak_sa '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        ถ้า (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_line_comment(p);
            goto redo_no_start;
        }
#endif
    pak_sa '(':
    pak_sa ')':
    pak_sa '[':
    pak_sa ']':
    pak_sa '{':
    pak_sa '}':
    pak_sa ',':
    pak_sa ';':
    pak_sa ':':
    pak_sa '?':
    pak_sa '~':
    parse_simple:
        tok = c;
        p++;
        bha_nga;
    pak_sa 0xEF: /* UTF8 BOM ? */
        ถ้า (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        ถ้า (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        ถ้า (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        bha_nga;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ถ้า defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static จำนวนเต็ม indent;
static void define_print(TCCState *s1, จำนวนเต็ม v);
static void pp_print(const var_na *msg, จำนวนเต็ม v, const จำนวนเต็ม *str)
{
    FILE *fp = tcc_state->ppfp;

    ถ้า (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    มิฉะนั้น ถ้า (msg[0] == '+')
         ++indent, ++msg;
    มิฉะนั้น ถ้า (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    ถ้า (msg[0] == '#') {
        define_print(tcc_state, v);
    } มิฉะนั้น {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#มิฉะนั้น
#define PP_PRINT(x)
#endif

static จำนวนเต็ม macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const จำนวนเต็ม *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static จำนวนเต็ม *macro_arg_subst(Sym **nested_list, const จำนวนเต็ม *macro_str, Sym *args)
{
    จำนวนเต็ม t, t0, t1, t2, n;
    const จำนวนเต็ม *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    สำหรับ (s = args, n = 0; s; s = s->prev, ++n);
    ขณะ (n--) {
        สำหรับ (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    ขณะ(1) {
        TOK_GET(&t, &macro_str, &cval);
        ถ้า (!t)
            bha_nga;
        ถ้า (t == '#') {
            /* stringize */
            do t = *macro_str++; ขณะ (t == ' ');
            s = sym_find2(args, t);
            ถ้า (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ขณะ (*st != TOK_EOF) {
                    const var_na *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ขณะ (*s) {
                        ถ้า (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        มิฉะนั้น
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
            } มิฉะนั้น ถ้า ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } มิฉะนั้น {
                expect("macro parameter after '#'");
            }
        } มิฉะนั้น ถ้า (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            ถ้า (s) {
                st = s->d;
                n = 0;
                ขณะ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ถ้า (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ถ้า (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        จำนวนเต็ม c = str.str[str.len - 1];
                        ขณะ (str.str[--str.len] != ',')
                            ;
                        ถ้า (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } มิฉะนั้น {
                            /* suppress '##' and add variable */
                            str.len++;
                            ถ้า (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } มิฉะนั้น {
                        ถ้า (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } มิฉะนั้น {
            add_var:
		    ถ้า (!s->e) {
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
                ขณะ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } มิฉะนั้น {
                tok_str_add(&str, t);
            }
        } มิฉะนั้น {
            tok_str_add2(&str, t, &cval);
        }
        ถ้า (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    คืน str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static anta_hstha จำนวนเต็ม *macro_twosharps(const จำนวนเต็ม *ptr0)
{
    จำนวนเต็ม t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const จำนวนเต็ม *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    สำหรับ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ถ้า (t1 == 0)
            bha_nga;
        สำหรับ (;;) {
            n = 0;
            ขณะ ((t2 = ptr[n]) == ' ')
                ++n;
            ถ้า (t2 != TOK_PPJOIN)
                bha_nga;
            ptr += n;
            ขณะ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ถ้า (t2 == TOK_PLCHLDR)
                continue;
            ถ้า (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ถ้า (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            สำหรับ (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ถ้า (*file->buf_ptr == 0)
                    bha_nga;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ถ้า (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    คืน macro_str1.str;
}

static จำนวนเต็ม peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    จำนวนเต็ม c;
    สำหรับ (;;) {
        PEEKC(c, p);
        switch (c) {
        pak_sa '/':
            PEEKC(c, p);
            ถ้า (c == '*')
                p = parse_comment(p);
            มิฉะนั้น ถ้า (c == '/')
                p = parse_line_comment(p);
            มิฉะนั้น {
                c = *--p = '/';
                goto leave;
            }
            --p, c = ' ';
            bha_nga;
        pak_sa ' ': pak_sa '\t':
            bha_nga;
        pak_sa '\f': pak_sa '\v': pak_sa '\r':
            continue;
        pak_sa '\n':
            file->line_num++, tok_flags |= TOK_FLAG_BOL;
            bha_nga;
        default: leave:
            file->buf_ptr = p;
            คืน c;
        }
        ถ้า (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static จำนวนเต็ม next_argstream(Sym **nested_list, TokenString *ws_str)
{
    จำนวนเต็ม t;
    Sym *sa;

    ขณะ (macro_ptr) {
        const จำนวนเต็ม *m = macro_ptr;
        ขณะ ((t = *m) != 0) {
            ถ้า (ws_str) {
                ถ้า (t != ' ')
                    คืน t;
                ++m;
            } มิฉะนั้น {
                TOK_GET(&tok, &macro_ptr, &tokc);
                คืน tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ถ้า (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ถ้า (ws_str) {
        คืน peek_file(ws_str);
    } มิฉะนั้น {
        next_nomacro();
        ถ้า (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        คืน tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static จำนวนเต็ม macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    จำนวนเต็ม t;
    จำนวนเต็ม v = s->v;

    PP_PRINT(("#", v, s->d));
    ถ้า (s->d) {
        จำนวนเต็ม *mstr = s->d;
        จำนวนเต็ม *jstr;
        Sym *sa;
        จำนวนเต็ม ret;

        ถ้า (s->type.t & MACRO_FUNC) {
            จำนวนเต็ม saved_parse_flags = parse_flags;
            TokenString str;
            จำนวนเต็ม parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            ถ้า (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ถ้า (parse_flags & PARSE_FLAG_SPACES)
                    สำหรับ (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                คืน 0;
            } มิฉะนั้น {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            สำหรับ(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } ขณะ (t == ' ' || --i);

                ถ้า (!sa) {
                    ถ้า (t == ')') /* handle '()' case */
                        bha_nga;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ขณะ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ถ้า (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ถ้า (t == '(')
                        parlevel++;
                    ถ้า (t == ')')
                        parlevel--;
                    ถ้า (t == ' ')
                        str.need_spc |= 1;
                    มิฉะนั้น
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                ถ้า (t == ')') {
                    ถ้า (!sa)
                        bha_nga;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ถ้า (sa->type.t && gnu_ext)
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
            ขณะ (sa) {
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
        ถ้า (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ถ้า (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ถ้า (jstr != mstr)
            tok_str_free_str(jstr);
        ถ้า (mstr != s->d)
            tok_str_free_str(mstr);
        คืน ret;

    } มิฉะนั้น {
        CValue cval;
        var_na buf[32], *cstrval = buf;

        /* special macros */
        ถ้า (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, parimaa_na(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } มิฉะนั้น ถ้า (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } มิฉะนั้น ถ้า (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            sa_nracanaa tm *tm;
            time(&ti);
            tm = localtime(&ti);
            ถ้า (v == TOK___DATE__) {
                static var_na const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, parimaa_na(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } มิฉะนั้น {
                snprintf(buf, parimaa_na(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        คืน 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static จำนวนเต็ม macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const จำนวนเต็ม *macro_str
    )
{
    Sym *s;
    จำนวนเต็ม t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    จำนวนเต็ม tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    ขณะ (1) {
        TOK_GET(&t, &macro_str, &cval);
        ถ้า (t == 0 || t == TOK_EOF)
            bha_nga;
        ถ้า (t >= TOK_IDENT) {
            s = define_find(t);
            ถ้า (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            ถ้า (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (จำนวนเต็ม*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ถ้า (macro_stack != str) {
                /* already finished by reading function macro arguments */
                bha_nga;
            }
            macro_str = macro_ptr;
            end_macro ();
        } มิฉะนั้น ถ้า (t == ' ') {
            ถ้า (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } มิฉะนั้น {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ถ้า (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ถ้า (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    คืน nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    จำนวนเต็ม t;
    ขณะ (macro_ptr) {
redo:
        t = *macro_ptr;
        ถ้า (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ถ้า (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } มิฉะนั้น ถ้า (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } มิฉะนั้น ถ้า (t == TOK_EOF) {
            /* do nothing */
        } มิฉะนั้น {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            ถ้า (t == '\\') {
                ถ้า (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        คืน;
    }

    next_nomacro();
    t = tok;
    ถ้า (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        ถ้า (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        คืน;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ถ้า (t == TOK_PPNUM) {
        ถ้า  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } มิฉะนั้น ถ้า (t == TOK_PPSTR) {
        ถ้า (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(จำนวนเต็ม last_tok)
{
    TokenString *str = &unget_buf;
    จำนวนเต็ม alloc = 0;
    ถ้า (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ถ้า (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

static const var_na * const target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# ถ้า PTR_SIZE == 8
    "_WIN64\0"
# endif
#มิฉะนั้น
# ถ้า defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# มิฉะนั้น
    "__linux__\0"
    "__linux\0"
#  ถ้า TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

static void putdef(CString *cs, const var_na *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

static void putdefs(CString *cs, const var_na *p)
{
    ขณะ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, จำนวนเต็ม is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    ถ้า (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    ถ้า (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ถ้า (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ถ้า (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    ถ้า (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    ถ้า (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    ถ้า (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ถ้า (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ถ้า (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ถ้า (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    ถ้า (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ถ้า CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#มิฉะนั้น
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, จำนวนเต็ม filetype)
{
    จำนวนเต็ม is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

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

    ถ้า (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ถ้า (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        ถ้า (s1->cmdline_incl.size)
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
    ขณะ (macro_stack)
        end_macro();
    macro_ptr = NULL;
    ขณะ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC จำนวนเต็ม set_idnum(จำนวนเต็ม c, จำนวนเต็ม val)
{
    จำนวนเต็ม prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    คืน prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    จำนวนเต็ม i, c;
    const var_na *p, *r;

    /* init isid table */
    สำหรับ(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    สำหรับ(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * parimaa_na(TokenSym *));
    memset(s->cached_includes_hash, 0, parimaa_na s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ขณะ (*p) {
        r = p;
        สำหรับ(;;) {
            c = *r++;
            ถ้า (c == '\0')
                bha_nga;
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
    จำนวนเต็ม i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ถ้า (n > total_idents)
        total_idents = n;
    สำหรับ (i = n; --i >= 0;)
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

static จำนวนเต็ม pp_need_space(จำนวนเต็ม a, จำนวนเต็ม b);

static void tok_print(const จำนวนเต็ม *str, const var_na *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    จำนวนเต็ม t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    ขณะ (str) {
	TOK_GET(&t, &str, &cval);
	ถ้า (t == 0 || t == TOK_EOF)
	    bha_nga;
        ถ้า (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, จำนวนเต็ม level)
{
    จำนวนเต็ม d = f->line_num - f->line_ref;

    ถ้า (s1->dflag & 4)
	คืน;

    ถ้า (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } มิฉะนั้น ถ้า (level == 0 && f->line_ref && d < 8) {
	ขณะ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } มิฉะนั้น ถ้า (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } มิฉะนั้น {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, จำนวนเต็ม v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    ถ้า (NULL == s || NULL == s->d)
        คืน;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    ถ้า (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        ถ้า (a)
            สำหรับ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                ถ้า (!(a = a->next))
                    bha_nga;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    จำนวนเต็ม v, t;
    const var_na *vs;
    FILE *fp;

    t = pp_debug_tok;
    ถ้า (t == 0)
        คืน;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    ถ้า (t == TOK_DEFINE) {
        define_print(s1, v);
    } มิฉะนั้น ถ้า (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } มิฉะนั้น ถ้า (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } มิฉะนั้น ถ้า (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static จำนวนเต็ม pp_need_space(จำนวนเต็ม a, จำนวนเต็ม b)
{
    คืน 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static จำนวนเต็ม pp_check_he0xE(จำนวนเต็ม t, const var_na *p)
{
    ถ้า (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        คืน 'E';
    คืน t;
}

/* Preprocess the current file */
ST_FUNC จำนวนเต็ม tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    จำนวนเต็ม token_seen, spcs, level;
    const var_na *p;
    var_na white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ถ้า (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    ถ้า (s1->do_bench) {
	/* for PP benchmarks */
	do next(); ขณะ (tok != TOK_EOF);
	คืน 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    ถ้า (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    สำหรับ (;;) {
        iptr = s1->include_stack_ptr;
        next();
        ถ้า (tok == TOK_EOF)
            bha_nga;

        level = s1->include_stack_ptr - iptr;
        ถ้า (level) {
            ถ้า (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        ถ้า (s1->dflag & 7) {
            pp_debug_defines(s1);
            ถ้า (s1->dflag & 4)
                continue;
        }

        ถ้า (is_space(tok)) {
            ถ้า (spcs < parimaa_na white - 1)
                white[spcs++] = tok;
            continue;
        } มิฉะนั้น ถ้า (tok == TOK_LINEFEED) {
            spcs = 0;
            ถ้า (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } มิฉะนั้น ถ้า (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } มิฉะนั้น ถ้า (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    คืน 0;
}

/* ------------------------------------------------------------------------- */
