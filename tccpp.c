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

ST_DATA පූර්ණ_සංඛ්‍යා tok_flags;
ST_DATA පූර්ණ_සංඛ්‍යා parse_flags;

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA පූර්ණ_සංඛ්‍යා tok;
ST_DATA CValue tokc;
ST_DATA const පූර්ණ_සංඛ්‍යා *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA පූර්ණ_සංඛ්‍යා tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA පූර්ණ_සංඛ්‍යා pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static var_na token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned var_na isidnum_table[256 - CH_EOF];
static පූර්ණ_සංඛ්‍යා pp_debug_tok, pp_debug_symv;
static පූර්ණ_සංඛ්‍යා pp_counter;
static void tok_print(const පූර්ණ_සංඛ්‍යා *str, const var_na *msg, ...);
static void next_nomacro(void);
static void parse_number(const var_na *p);
static void parse_string(const var_na *p, පූර්ණ_සංඛ්‍යා len);

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

ST_FUNC void skip(පූර්ණ_සංඛ්‍යා c)
{
    නම් (tok != c) {
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
#නැතහොත්
#නම් !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#නැතහොත්
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const var_na *sfile, පූර්ණ_සංඛ්‍යා sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef sa_nracanaa TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    sa_nracanaa TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#නම් TAL_INFO
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
#නම් TAL_DEBUG
    පූර්ණ_සංඛ්‍යා     line_num; /* negative line_num used for double free check */
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
#නම් TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ආපසු al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#නම් TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#නම් TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#නම් TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    නම් (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        අතරතුර (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            නම් (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (පූර්ණ_සංඛ්‍යා)header->size);
            }
            p += header->size + parimaa_na(tal_header_t);
        }
#නම් TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    නම් (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    නම් (!p)
        ආපසු;
    header = (tal_header_t *)p - 1;
#නම් TAL_DEBUG
    නම් (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (පූර්ණ_සංඛ්‍යා)-header->line_num, (පූර්ණ_සංඛ්‍යා)header->size);
    } නැතහොත්
        header->line_num = -header->line_num;
#endif
    al = *pal;
    අතරතුර ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    නම් (0 == --al->nb_allocs) {
        *pal = al->next;
        නම් ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } නැතහොත් {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } නැතහොත් නම් ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + parimaa_na(tal_header_t);
    TinyAlloc *al = *pal;

    නම් (p) {
        /* reallpc case */
        අතරතුර ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        නම් ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        නම් (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ආපසු ret;
        } නැතහොත් නම් (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#නම් TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } නැතහොත් {
        /* new alloc case */
        අතරතුර (al->p + adj_size > al->bufend) {
            al = al->next;
            නම් (!al) {
                unsigned new_size = (*pal)->size;
                නම් (adj_size > new_size) {
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
#නම්  TAL_DEBUG
    {
        පූර්ණ_සංඛ්‍යා ofs = strlen(sfile) + 1 - parimaa_na header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#නම් TAL_INFO
        නම් (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        නම් (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ආපසු ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, පූර්ණ_සංඛ්‍යා new_size)
{
    පූර්ණ_සංඛ්‍යා size;

    size = cstr->size_allocated;
    නම් (size < 8)
        size = 8; /* no need to allocate a too small first string */
    අතරතුර (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, පූර්ණ_සංඛ්‍යා ch)
{
    පූර්ණ_සංඛ්‍යා size;
    size = cstr->size + 1;
    නම් (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN var_na *unicode_to_utf8 (var_na *b, uint32_t Uc)
{
    නම් (Uc<0x80) *b++=Uc;
    නැතහොත් නම් (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    නැතහොත් නම් (Uc-0xd800u<0x800) goto error;
    නැතහොත් නම් (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    නැතහොත් නම් (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    නැතහොත් error: tcc_error("0x%x is not a valid universal character", Uc);
    ආපසු b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, පූර්ණ_සංඛ්‍යා ch)
{
    var_na buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, පූර්ණ_සංඛ්‍යා len)
{
    පූර්ණ_සංඛ්‍යා size;
    නම් (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    නම් (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, පූර්ණ_සංඛ්‍යා ch)
{
    පූර්ණ_සංඛ්‍යා size;
    size = cstr->size + parimaa_na(nwchar_t);
    නම් (size > cstr->size_allocated)
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

ST_FUNC පූර්ණ_සංඛ්‍යා cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap)
{
    va_list v;
    පූර්ණ_සංඛ්‍යා len, size = 80;
    සඳහා (;;) {
        size += cstr->size;
        නම් (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        නම් (len >= 0 && len < size)
            bha_nga;
        size *= 2;
    }
    cstr->size += len;
    ආපසු len;
}

ST_FUNC පූර්ණ_සංඛ්‍යා cstr_printf(CString *cstr, const var_na *fmt, ...)
{
    va_list ap; පූර්ණ_සංඛ්‍යා len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ආපසු len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, පූර්ණ_සංඛ්‍යා c)
{
    නම් (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    නම් (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } නැතහොත් {
        cstr_ccat(cstr, '\\');
        නම් (c == '\n') {
            cstr_ccat(cstr, 'n');
        } නැතහොත් {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const var_na *str, පූර්ණ_සංඛ්‍යා len)
{
    TokenSym *ts, **ptable;
    පූර්ණ_සංඛ්‍යා i;

    නම් (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    නම් ((i % TOK_ALLOC_INCR) == 0) {
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
    ආපසු ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const var_na *str, පූර්ණ_සංඛ්‍යා len)
{
    TokenSym *ts, **pts;
    පූර්ණ_සංඛ්‍යා i;
    unsigned පූර්ණ_සංඛ්‍යා h;
    
    h = TOK_HASH_INIT;
    සඳහා(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned var_na *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    සඳහා(;;) {
        ts = *pts;
        නම් (!ts)
            bha_nga;
        නම් (ts->len == len && !memcmp(ts->str, str, len))
            ආපසු ts;
        pts = &(ts->hash_next);
    }
    ආපසු tok_alloc_new(pts, str, len);
}

ST_FUNC පූර්ණ_සංඛ්‍යා tok_alloc_const(const var_na *str)
{
    ආපසු tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const var_na *get_tok_str(පූර්ණ_සංඛ්‍යා v, CValue *cv)
{
    var_na *p;
    පූර්ණ_සංඛ්‍යා i, len;

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
        ආපසු (var_na*)cv->str.data;
    pak_sa TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        නම් (v == TOK_STR) {
            len = cv->str.size - 1;
            සඳහා(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned var_na *)cv->str.data)[i]);
        } නැතහොත් {
            len = (cv->str.size / parimaa_na(nwchar_t)) - 1;
            සඳහා(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;

    pak_sa TOK_CFLOAT:
        ආපසු strcpy(p, "<float>");
    pak_sa TOK_CDOUBLE:
        ආපසු strcpy(p, "<double>");
    pak_sa TOK_CLDOUBLE:
        ආපසු strcpy(p, "<long double>");
    pak_sa TOK_LINENUM:
        ආපසු strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    pak_sa TOK_LT:
        v = '<';
        goto addv;
    pak_sa TOK_GT:
        v = '>';
        goto addv;
    pak_sa TOK_DOTS:
        ආපසු strcpy(p, "...");
    pak_sa TOK_A_SHL:
        ආපසු strcpy(p, "<<=");
    pak_sa TOK_A_SAR:
        ආපසු strcpy(p, ">>=");
    pak_sa TOK_EOF:
        ආපසු strcpy(p, "<eof>");
    pak_sa 0: /* anonymous nameless symbols */
        ආපසු strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        නම් (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned var_na *q = tok_two_chars;
            අතරතුර (*q) {
                නම් (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ආපසු cstr_buf.data;
                }
                q += 3;
            }
            නම් (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                bha_nga;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } නැතහොත් නම් (v < tok_ident) {
            ආපසු table_ident[v - TOK_IDENT]->str;
        } නැතහොත් නම් (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } නැතහොත් {
            /* should never happen */
            ආපසු NULL;
        }
        bha_nga;
    }
    ආපසු cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static පූර්ණ_සංඛ්‍යා handle_eob(void)
{
    BufferedFile *bf = file;
    පූර්ණ_සංඛ්‍යා len;

    /* only tries to read if really end of buffer */
    නම් (bf->buf_ptr >= bf->buf_end) {
        නම් (bf->fd >= 0) {
#නම් defined(PARSE_DEBUG)
            len = 1;
#නැතහොත්
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            නම් (len < 0)
                len = 0;
        } නැතහොත් {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    නම් (bf->buf_ptr < bf->buf_end) {
        ආපසු bf->buf_ptr[0];
    } නැතහොත් {
        bf->buf_ptr = bf->buf_end;
        ආපසු CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static පූර්ණ_සංඛ්‍යා next_c(void)
{
    පූර්ණ_සංඛ්‍යා ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    නම් (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ආපසු ch;
}

/* input with '\[\r]\n' handling. */
static පූර්ණ_සංඛ්‍යා handle_stray_noerror(පූර්ණ_සංඛ්‍යා err)
{
    පූර්ණ_සංඛ්‍යා ch;
    අතරතුර ((ch = next_c()) == '\\') {
        ch = next_c();
        නම් (ch == '\n') {
    newl:
            file->line_num++;
        } නැතහොත් {
            නම් (ch == '\r') {
                ch = next_c();
                නම් (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            නම් (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ආපසු *--file->buf_ptr = '\\';
        }
    }
    ආපසු ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static පූර්ණ_සංඛ්‍යා handle_bs(uint8_t **p)
{
    පූර්ණ_සංඛ්‍යා c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ආපසු c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static පූර්ණ_සංඛ්‍යා handle_stray(uint8_t **p)
{
    පූර්ණ_සංඛ්‍යා c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ආපසු c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    නම් (c == '\\')\
        c = handle_stray(&p); \
}

static පූර්ණ_සංඛ්‍යා skip_spaces(void)
{
    පූර්ණ_සංඛ්‍යා ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } අතරතුර (isidnum_table[ch - CH_EOF] & IS_SPC);
    ආපසු ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    පූර්ණ_සංඛ්‍යා c;
    සඳහා(;;) {
        සඳහා (;;) {
            c = *++p;
    redo:
            නම් (c == '\n' || c == '\\')
                bha_nga;
            c = *++p;
            නම් (c == '\n' || c == '\\')
                bha_nga;
        }
        නම් (c == '\n')
            bha_nga;
        c = handle_bs(&p);
        නම් (c == CH_EOF)
            bha_nga;
        නම් (c != '\\')
            goto redo;
    }
    ආපසු p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    පූර්ණ_සංඛ්‍යා c;
    සඳහා(;;) {
        /* fast skip loop */
        සඳහා(;;) {
            c = *++p;
        redo:
            නම් (c == '\n' || c == '*' || c == '\\')
                bha_nga;
            c = *++p;
            නම් (c == '\n' || c == '*' || c == '\\')
                bha_nga;
        }
        /* now we can handle all the cases */
        නම් (c == '\n') {
            file->line_num++;
        } නැතහොත් නම් (c == '*') {
            do {
                c = *++p;
            } අතරතුර (c == '*');
            නම් (c == '\\')
                c = handle_bs(&p);
            නම් (c == '/')
                bha_nga;
            goto check_eof;
        } නැතහොත් {
            c = handle_bs(&p);
        check_eof:
            නම් (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            නම් (c != '\\')
                goto redo;
        }
    }
    ආපසු p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, පූර්ණ_සංඛ්‍යා sep, CString *str)
{
    පූර්ණ_සංඛ්‍යා c;
    සඳහා(;;) {
        c = *++p;
    redo:
        නම් (c == sep) {
            bha_nga;
        } නැතහොත් නම් (c == '\\') {
            c = handle_bs(&p);
            නම් (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } නැතහොත් නම් (c == '\\') {
                නම් (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                නම් (c == '\\') {
                    c = handle_bs(&p);
                    නම් (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } නැතහොත් {
                goto redo;
            }
        } නැතහොත් නම් (c == '\n') {
        add_lf:
            නම් (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } නැතහොත් නම් (str) { /* not skipping */
                goto unterminated_string;
            } නැතහොත් {
                //tcc_warning("missing terminating %c character", sep);
                ආපසු p;
            }
        } නැතහොත් නම් (c == '\r') {
            c = *++p;
            නම් (c == '\\')
                c = handle_bs(&p);
            නම් (c == '\n')
                goto add_lf;
            නම් (c == CH_EOF)
                goto unterminated_string;
            නම් (str)
                cstr_ccat(str, '\r');
            goto redo;
        } නැතහොත් {
        add_char:
            නම් (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ආපසු p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    පූර්ණ_සංඛ්‍යා a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    සඳහා(;;) {
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
            නම් (c == CH_EOF)
                expect("#endif");
            නම් (c == '\\')
                ++p;
            continue;
        /* skip strings */
        pak_sa '\"':
        pak_sa '\'':
            නම් (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            bha_nga;
        /* skip comments */
        pak_sa '/':
            නම් (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            නම් (c == '*') {
                p = parse_comment(p);
            } නැතහොත් නම් (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        pak_sa '#':
            p++;
            නම් (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                නම් (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                නම් (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                නැතහොත් නම් (tok == TOK_ENDIF)
                    a--;
                නැතහොත් නම්( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                නැතහොත් නම් (tok == TOK_LINEFEED)
                    goto redo_start;
                නැතහොත් නම් (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#නම් !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            නැතහොත් නම් (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#නැතහොත්
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

#නම් 0
/* return the number of additional 'ints' necessary to store the
   token */
static anta_hstha පූර්ණ_සංඛ්‍යා tok_size(const පූර්ණ_සංඛ්‍යා *p)
{
    switch(*p) {
        /* 4 bytes */
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
        ආපසු 1 + 1;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        ආපසු 1 + 1 + (p[1] + 3) / 4;
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
	ආපසු 1 + LONG_SIZE / 4;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        ආපසු 1 + 2;
    pak_sa TOK_CLDOUBLE:
        ආපසු 1 + LDOUBLE_WORDS;
    default:
        ආපසු 1 + 0;
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
    ආපසු str;
}

ST_FUNC void tok_str_free_str(පූර්ණ_සංඛ්‍යා *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC පූර්ණ_සංඛ්‍යා *tok_str_realloc(TokenString *s, පූර්ණ_සංඛ්‍යා new_size)
{
    පූර්ණ_සංඛ්‍යා *str, size;

    size = s->allocated_len;
    නම් (size < 16)
        size = 16;
    අතරතුර (size < new_size)
        size = size * 2;
    නම් (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * parimaa_na(පූර්ණ_සංඛ්‍යා));
        s->allocated_len = size;
        s->str = str;
    }
    ආපසු s->str;
}

ST_FUNC void tok_str_add(TokenString *s, පූර්ණ_සංඛ්‍යා t)
{
    පූර්ණ_සංඛ්‍යා len, *str;

    len = s->len;
    str = s->str;
    නම් (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, පූර්ණ_සංඛ්‍යා alloc)
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
    නම් (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } නැතහොත් {
        නම් (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, පූර්ණ_සංඛ්‍යා t, CValue *cv)
{
    පූර්ණ_සංඛ්‍යා len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    නම් (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
#නම් LONG_SIZE == 4
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
                1 + (cv->str.size + parimaa_na(පූර්ණ_සංඛ්‍යා) - 1) / parimaa_na(පූර්ණ_සංඛ්‍යා);
            නම් (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#නම් LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        bha_nga;
    pak_sa TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        නම් (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        නම් (LDOUBLE_WORDS >= 4)
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
    නම් (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, පූර්ණ_සංඛ්‍යා t, CValue *cv)
{
    නම් (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static anta_hstha void tok_get(පූර්ණ_සංඛ්‍යා *t, const පූර්ණ_සංඛ්‍යා **pp, CValue *cv)
{
    const පූර්ණ_සංඛ්‍යා *p = *pp;
    පූර්ණ_සංඛ්‍යා n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#නම් LONG_SIZE == 4
    pak_sa TOK_CLONG:
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_LINENUM:
        cv->i = *p++;
        bha_nga;
#නම් LONG_SIZE == 4
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
        p += (cv->str.size + parimaa_na(පූර්ණ_සංඛ්‍යා) - 1) / parimaa_na(පූර්ණ_සංඛ්‍යා);
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#නම් LONG_SIZE == 8
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
        අතරතුර (--n);
        bha_nga;
    default:
        bha_nga;
    }
    *pp = p;
}

#නම් 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#නැතහොත්
# define TOK_GET(t,p,c) do { \
    පූර්ණ_සංඛ්‍යා _t = **(p); \
    නම් (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    නැතහොත් \
        *(t) = _t, ++*(p); \
    } අතරතුර (0)
#endif

static පූර්ණ_සංඛ්‍යා macro_is_equal(const පූර්ණ_සංඛ්‍යා *a, const පූර්ණ_සංඛ්‍යා *b)
{
    CValue cv;
    පූර්ණ_සංඛ්‍යා t;

    නම් (!a || !b)
        ආපසු 1;

    අතරතුර (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        නම් (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ආපසු 0;
    }
    ආපසු !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(පූර්ණ_සංඛ්‍යා v, පූර්ණ_සංඛ්‍යා macro_type, පූර්ණ_සංඛ්‍යා *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    නම් (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    පූර්ණ_සංඛ්‍යා v = s->v;
    නම් (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(පූර්ණ_සංඛ්‍යා v)
{
    v -= TOK_IDENT;
    නම් ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ආපසු NULL;
    ආපසු table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    අතරතුර (define_stack != b) {
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
    නම් (s->include_stack_ptr != s->include_stack)
        ආපසු;
    p = get_tok_str(tok, NULL);
    නම් (0 != memcmp(p, "test_", 5))
        ආපසු;
    නම් (0 != --s->run_test)
        ආපසු;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(පූර්ණ_සංඛ්‍යා warn)
{
    නම් (tok == TOK_LINEFEED)
        ආපසු;
    නම් (warn)
        tcc_warning("extra tokens after directive");
    අතරතුර (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const var_na *filename, පූර්ණ_සංඛ්‍යා add);

static පූර්ණ_සංඛ්‍යා parse_include(TCCState *s1, පූර්ණ_සංඛ්‍යා do_next, පූර්ණ_සංඛ්‍යා test)
{
    පූර්ණ_සංඛ්‍යා c, i;
    var_na name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    නම් (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, parimaa_na name, tokcstr.data, i);
        next_nomacro();
    } නැතහොත් {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        සඳහා (;;) {
            next();
            p = name, i = strlen(p) - 1;
            නම් (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                bha_nga;
            නම් (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, parimaa_na name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    නම් (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    සඳහා (;;) {
        ++i;
        නම් (i == 0) {
            /* check absolute include path */
            නම් (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } නැතහොත් නම් (i == 1) {
            /* search in file's dir if "header.h" */
            නම් (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, parimaa_na buf, p, tcc_basename(p) - p);
        } නැතහොත් {
            පූර්ණ_සංඛ්‍යා j = i - 2, k = j - s1->nb_include_paths;
            නම් (k < 0)
                p = s1->include_paths[j];
            නැතහොත් නම් (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            නැතහොත් නම් (test)
                ආපසු 0;
            නැතහොත්
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, parimaa_na buf, p);
            pstrcat(buf, parimaa_na buf, "/");
        }
        pstrcat(buf, parimaa_na buf, name);
        e = search_cached_include(s1, buf, 0);
        නම් (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            නම් ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (පූර්ණ_සංඛ්‍යා)(s1->include_stack_ptr - s1->include_stack), "", buf);
            ආපසු 1;
        }
        නම් (tcc_open(s1, buf) >= 0)
            bha_nga;
    }

    නම් (test) {
        tcc_close();
    } නැතහොත් {
        නම් (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        නම් (s1->gen_deps) {
            BufferedFile *bf = file;
            අතරතුර (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            නම් (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ආපසු 1;
}

/* eval an expression for #if/#elif */
static පූර්ණ_සංඛ්‍යා expr_preprocess(TCCState *s1)
{
    පූර්ණ_සංඛ්‍යා c, t;
    පූර්ණ_සංඛ්‍යා t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    අතරතුර (1) {
        next(); /* do macro subst */
        t = tok;
        නම් (tok < TOK_IDENT) {
            නම් (tok == TOK_LINEFEED || tok == TOK_EOF)
                bha_nga;
            නම් (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } නැතහොත් නම් (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            නම් (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            නම් (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            නම් (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            නම් (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            නම් (t == '(') {
                next();
                නම් (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } නැතහොත් නම් (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    නම් (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            නම් (tok != ')')
                expect("')'");
            goto c_number;
        } නැතහොත් {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    නම් (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    නම් (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ආපසු c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    අතරතුර (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    පූර්ණ_සංඛ්‍යා v, t, varg, is_vaargs, t0;
    පූර්ණ_සංඛ්‍යා saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    නම් (v < TOK_IDENT || v == TOK_DEFINED)
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
    නම් (tok == '(') {
        පූර්ණ_සංඛ්‍යා dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        නම් (tok != ')') සඳහා (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            නම් (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } නැතහොත් නම් (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            නම් (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            නම් (tok == ')')
                bha_nga;
            නම් (tok != ',' || is_vaargs)
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
    අතරතුර (tok != TOK_LINEFEED && tok != TOK_EOF) {
        නම් (is_space(tok)) {
            str.need_spc |= 1;
        } නැතහොත් {
            නම් (TOK_TWOSHARPS == tok) {
                නම් (0 == t0)
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
    නම් (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const var_na *filename, පූර්ණ_සංඛ්‍යා add)
{
    const var_na *s, *basename;
    unsigned පූර්ණ_සංඛ්‍යා h;
    CachedInclude *e;
    පූර්ණ_සංඛ්‍යා c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    අතරතුර ((c = (unsigned var_na)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#නැතහොත්
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    සඳහා(;;) {
        නම් (i == 0)
            bha_nga;
        e = s1->cached_includes[i - 1];
        නම් (0 == PATHCMP(filename, e->filename))
            ආපසු e;
        නම් (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ආපසු e;
        i = e->hash_next;
    }
    නම් (!add)
        ආපසු NULL;

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
    ආපසු e;
}

static පූර්ණ_සංඛ්‍යා pragma_parse(TCCState *s1)
{
    next_nomacro();
    නම් (tok == TOK_push_macro || tok == TOK_pop_macro) {
        පූර්ණ_සංඛ්‍යා t = tok, v;
        Sym *s;

        නම් (next(), tok != '(')
            goto pragma_err;
        නම් (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        නම් (next(), tok != ')')
            goto pragma_err;
        නම් (t == TOK_push_macro) {
            අතරතුර (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } නැතහොත් {
            සඳහා (s = define_stack; s; s = s->prev)
                නම් (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    bha_nga;
                }
        }
        නම් (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        නැතහොත්
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } නැතහොත් නම් (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } නැතහොත් නම් (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ආපසු 1;

    } නැතහොත් නම් (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        නම් (tok == TOK_ASM_pop) {
            next();
            නම් (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } නැතහොත් {
            පූර්ණ_සංඛ්‍යා val = 0;
            නම් (tok != ')') {
                නම් (tok == TOK_ASM_push) {
                    next();
                    නම් (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    නම් (tok != ',')
                        goto pack_set;
                    next();
                }
                නම් (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                නම් (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        නම් (tok != ')')
            goto pragma_err;

    } නැතහොත් නම් (tok == TOK_comment) {
        var_na *p; පූර්ණ_සංඛ්‍යා t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        නම් (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        නම් (tok != ')')
            goto pragma_err;
        නම් (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } නැතහොත් {
            නම් (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } නැතහොත් {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ආපසු 0;
    }
    next();
    ආපසු 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const var_na *filename)
{
    var_na buf[1024];
    buf[0] = 0;
    නම් (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, parimaa_na buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, parimaa_na buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    නම් (0 == strcmp(file->filename, buf))
        ආපසු;
    //printf("new file '%s'\n", buf);
    නම් (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, parimaa_na file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(පූර්ණ_සංඛ්‍යා is_bof)
{
    TCCState *s1 = tcc_state;
    පූර්ණ_සංඛ්‍යා c, n, saved_parse_flags;
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
        නම් (s)
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
        නම් (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        නම් (is_bof) {
            නම් (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        නම් (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        නම් (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    pak_sa TOK_ELSE:
        next_nomacro();
        නම් (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        නම් (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    pak_sa TOK_ELIF:
        නම් (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        නම් (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        නම් (c == 1) {
            skip_to_eol(0);
            c = 0;
        } නැතහොත් {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        නම් (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        නම් (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        bha_nga;
    pak_sa TOK_ENDIF:
        next_nomacro();
        නම් (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        නම් (file->ifndef_macro &&
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
        නම් (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    pak_sa TOK_PPNUM:
        නම් (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        සඳහා (n = 0, q = tokc.str.data; *q; ++q) {
            නම් (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        නම් (tok != TOK_LINEFEED) {
            නම් (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        නම් (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        bha_nga;

    pak_sa TOK_ERROR:
    pak_sa TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        අතරතුර (c != '\n' && c != CH_EOF) {
            නම් ((q - buf) < parimaa_na(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        නම් (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        නැතහොත්
            tcc_warning("#warning %s", buf);
        next_nomacro();
        bha_nga;
    }
    pak_sa TOK_PRAGMA:
        නම් (!pragma_parse(s1))
            goto ignore;
        bha_nga;
    pak_sa TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        නම් (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        නම් (tok == '!' && is_bof)
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
static void parse_escape_string(CString *outstr, const uint8_t *buf, පූර්ණ_සංඛ්‍යා is_long)
{
    පූර්ණ_සංඛ්‍යා c, n, i;
    const uint8_t *p;

    p = buf;
    සඳහා(;;) {
        c = *p;
        නම් (c == '\0')
            bha_nga;
        නම් (c == '\\') {
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
                නම් (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    නම් (isoct(c)) {
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
                    නම් (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    නැතහොත් නම් (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    නැතහොත් නම් (isnum(c))
                        c = c - '0';
                    නැතහොත් නම් (i >= 0)
                        expect("more hex digits in universal-character-name");
                    නැතහොත්
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } අතරතුර (--i);
		නම් (is_long) {
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
                නම් (!gnu_ext)
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
                නම් (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                නැතහොත්
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                bha_nga;
            }
        } නැතහොත් නම් (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            පූර්ණ_සංඛ්‍යා cont; /* count of continuation bytes */
            පූර්ණ_සංඛ්‍යා skip; /* how many bytes should skip when error occurred */
            පූර්ණ_සංඛ්‍යා i;

            /* decode leading byte */
            නම් (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } නැතහොත් නම් (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } නැතහොත් නම් (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } නැතහොත් නම් (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } නැතහොත් {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            සඳහා (i = 1; i <= cont; i++) {
                පූර්ණ_සංඛ්‍යා l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                නම් (i == 1) {
                    switch (c) {
                    pak_sa 0xE0: l = 0xA0; bha_nga;
                    pak_sa 0xED: h = 0x9F; bha_nga;
                    pak_sa 0xF0: l = 0x90; bha_nga;
                    pak_sa 0xF4: h = 0x8F; bha_nga;
                    }
                }

                නම් (p[i] < l || p[i] > h) {
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
        නම් (!is_long)
            cstr_ccat(outstr, c);
        නැතහොත් {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            නම් (c < 0x10000) {
                cstr_wccat(outstr, c);
            } නැතහොත් {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#නැතහොත්
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    නම් (!is_long)
        cstr_ccat(outstr, '\0');
    නැතහොත්
        cstr_wccat(outstr, '\0');
}

static void parse_string(const var_na *s, පූර්ණ_සංඛ්‍යා len)
{
    uint8_t buf[1000], *p = buf;
    පූර්ණ_සංඛ්‍යා is_long, sep;

    නම් ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    නම් (len >= parimaa_na buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    නම් (p != buf)
        tcc_free(p);

    නම් (sep == '\'') {
        පූර්ණ_සංඛ්‍යා char_size, i, n, c;
        /* XXX: make it portable */
        නම් (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        නැතහොත්
            tok = TOK_LCHAR, char_size = parimaa_na(nwchar_t);
        n = tokcstr.size / char_size - 1;
        නම් (n < 1)
            tcc_error("empty character constant");
        නම් (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        සඳහා (c = i = 0; i < n; ++i) {
            නම් (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            නැතහොත්
                c = (c << 8) | ((var_na *)tokcstr.data)[i];
        }
        tokc.i = c;
    } නැතහොත් {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        නම් (!is_long)
            tok = TOK_STR;
        නැතහොත්
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static පූර්ණ_සංඛ්‍යා bn_lshift(unsigned පූර්ණ_සංඛ්‍යා *bn, පූර්ණ_සංඛ්‍යා shift, පූර්ණ_සංඛ්‍යා or_val)
{
    පූර්ණ_සංඛ්‍යා i;
    unsigned පූර්ණ_සංඛ්‍යා v;
    නම් (bn[BN_SIZE - 1] >> (32 - shift))
	ආපසු shift;
    සඳහා(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ආපසු 0;
}

static void bn_zero(unsigned පූර්ණ_සංඛ්‍යා *bn)
{
    පූර්ණ_සංඛ්‍යා i;
    සඳහා(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const var_na *p)
{
    පූර්ණ_සංඛ්‍යා b, t, shift, frac_bits, s, exp_val, ch;
    var_na *q;
    unsigned පූර්ණ_සංඛ්‍යා bn[BN_SIZE];
    long dviguu_na d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    නම් (t == '.') {
        goto float_frac_parse;
    } නැතහොත් නම් (t == '0') {
        නම් (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } නැතහොත් නම් (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    අතරතුර (1) {
        නම් (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        නැතහොත් නම් (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        නැතහොත් නම් (isnum(ch))
            t = ch - '0';
        නැතහොත්
            bha_nga;
        නම් (t >= b)
            bha_nga;
        නම් (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    නම් (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        නම් (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            නම් (b == 16)
                shift = 4;
            නැතහොත් 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            අතරතුර (1) {
                t = *q++;
                නම් (t == '\0') {
                    bha_nga;
                } නැතහොත් නම් (t >= 'a') {
                    t = t - 'a' + 10;
                } නැතහොත් නම් (t >= 'A') {
                    t = t - 'A' + 10;
                } නැතහොත් {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            නම් (ch == '.') {
                ch = *p++;
                අතරතුර (1) {
                    t = ch;
                    නම් (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } නැතහොත් නම් (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } නැතහොත් නම් (t >= '0' && t <= '9') {
                        t = t - '0';
                    } නැතහොත් {
                        bha_nga;
                    }
                    නම් (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            නම් (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            නම් (ch == '+') {
                ch = *p++;
            } නැතහොත් නම් (ch == '-') {
                s = -1;
                ch = *p++;
            }
            නම් (ch < '0' || ch > '9')
                expect("exponent digits");
            අතරතුර (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		නම් (exp_val < 100000000)
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
            නම් (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } නැතහොත් නම් (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } නැතහොත් {
                tok = TOK_CDOUBLE;
                tokc.d = (dviguu_na)d;
            }
        } නැතහොත් {
            /* decimal floats */
            නම් (ch == '.') {
                නම් (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                අතරතුර (ch >= '0' && ch <= '9') {
                    නම් (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            නම් (ch == 'e' || ch == 'E') {
                නම් (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                නම් (ch == '-' || ch == '+') {
                    නම් (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                නම් (ch < '0' || ch > '9')
                    expect("exponent digits");
                අතරතුර (ch >= '0' && ch <= '9') {
                    නම් (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            නම් (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } නැතහොත් නම් (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } නැතහොත් {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } නැතහොත් {
        unsigned long long n, n1;
        පූර්ණ_සංඛ්‍යා lcount, ucount, ov = 0;
        const var_na *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        නම් (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        අතරතුර(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            නම් (t == '\0')
                bha_nga;
            නැතහොත් නම් (t >= 'a')
                t = t - 'a' + 10;
            නැතහොත් නම් (t >= 'A')
                t = t - 'A' + 10;
            නැතහොත්
                t = t - '0';
            නම් (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            නම් (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        සඳහා(;;) {
            t = toup(ch);
            නම් (t == 'L') {
                නම් (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                නම් (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } නැතහොත් නම් (t == 'U') {
                නම් (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } නැතහොත් {
                bha_nga;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        නම් (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        නම් (ucount == 0 && b == 10) {
            නම් (lcount <= (LONG_SIZE == 4)) {
                නම් (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            නම් (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } නැතහොත් {
            නම් (lcount <= (LONG_SIZE == 4)) {
                නම් (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                නැතහොත් නම් (n >= 0x80000000U)
                    ucount = 1;
            }
            නම් (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        නම් (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	නම් (lcount) {
            tok = TOK_CLONG;
            නම් (lcount == 2)
                tok = TOK_CLLONG;
	}
	නම් (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    නම් (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    pak_sa c1:                                    \
        PEEKC(c, p);                            \
        නම් (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } නැතහොත් {                                \
            tok = tok1;                         \
        }                                       \
        bha_nga;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    පූර්ණ_සංඛ්‍යා t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned පූර්ණ_සංඛ්‍යා h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    pak_sa ' ':
    pak_sa '\t':
        tok = c;
        p++;
 maybe_space:
        නම් (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        අතරතුර (isidnum_table[*p - CH_EOF] & IS_SPC)
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
        නම් (c == '\\')
            goto parse_simple;
        නම් (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            නම් (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } නැතහොත් නම් (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } නැතහොත් නම් (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } නැතහොත් නම් (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } නැතහොත් {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                නම් (tok_flags & TOK_FLAG_ENDIF) {
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
        } නැතහොත් {
            goto redo_no_start;
        }
        bha_nga;

    pak_sa '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        නම් (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    pak_sa '#':
        /* XXX: simplify */
        PEEKC(c, p);
        නම් ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } නැතහොත් {
            නම් (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } නැතහොත් {
#නම් !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                නම් (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } නැතහොත්
#endif
                {
                    tok = '#';
                }
            }
        }
        bha_nga;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    pak_sa '$':
        නම් (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        අතරතුර (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        නම් (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            සඳහා(;;) {
                ts = *pts;
                නම් (!ts)
                    bha_nga;
                නම් (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (var_na *) p1, len);
        token_found: ;
        } නැතහොත් {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (var_na *) p1, len);
            p--;
            PEEKC(c, p);
            අතරතුර (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        නම් (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            නම් (c == '\'' || c == '\"') {
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
        සඳහා(;;) {
            cstr_ccat(&tokcstr, t);
            නම් (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        නම් (isnum(c)) {
            t = '.';
            goto parse_num;
        } නැතහොත් නම් ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } නැතහොත් නම් (c == '.') {
            PEEKC(c, p);
            නම් (c == '.') {
                p++;
                tok = TOK_DOTS;
            } නැතහොත් {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } නැතහොත් {
            tok = '.';
        }
        bha_nga;
    pak_sa '\'':
    pak_sa '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        නම් (is_long)
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
        නම් (c == '=') {
            p++;
            tok = TOK_LE;
        } නැතහොත් නම් (c == '<') {
            PEEKC(c, p);
            නම් (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } නැතහොත් {
                tok = TOK_SHL;
            }
        } නැතහොත් {
            tok = TOK_LT;
        }
        bha_nga;
    pak_sa '>':
        PEEKC(c, p);
        නම් (c == '=') {
            p++;
            tok = TOK_GE;
        } නැතහොත් නම් (c == '>') {
            PEEKC(c, p);
            නම් (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } නැතහොත් {
                tok = TOK_SAR;
            }
        } නැතහොත් {
            tok = TOK_GT;
        }
        bha_nga;
        
    pak_sa '&':
        PEEKC(c, p);
        නම් (c == '&') {
            p++;
            tok = TOK_LAND;
        } නැතහොත් නම් (c == '=') {
            p++;
            tok = TOK_A_AND;
        } නැතහොත් {
            tok = '&';
        }
        bha_nga;
        
    pak_sa '|':
        PEEKC(c, p);
        නම් (c == '|') {
            p++;
            tok = TOK_LOR;
        } නැතහොත් නම් (c == '=') {
            p++;
            tok = TOK_A_OR;
        } නැතහොත් {
            tok = '|';
        }
        bha_nga;

    pak_sa '+':
        PEEKC(c, p);
        නම් (c == '+') {
            p++;
            tok = TOK_INC;
        } නැතහොත් නම් (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } නැතහොත් {
            tok = '+';
        }
        bha_nga;
        
    pak_sa '-':
        PEEKC(c, p);
        නම් (c == '-') {
            p++;
            tok = TOK_DEC;
        } නැතහොත් නම් (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } නැතහොත් නම් (c == '>') {
            p++;
            tok = TOK_ARROW;
        } නැතහොත් {
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
        නම් (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } නැතහොත් නම් (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } නැතහොත් නම් (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } නැතහොත් {
            tok = '/';
        }
        bha_nga;
        
        /* simple tokens */
    pak_sa '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        නම් (parse_flags & PARSE_FLAG_ASM_FILE) {
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
        නම් (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        නම් (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        නම් (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        bha_nga;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#නම් defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static පූර්ණ_සංඛ්‍යා indent;
static void define_print(TCCState *s1, පූර්ණ_සංඛ්‍යා v);
static void pp_print(const var_na *msg, පූර්ණ_සංඛ්‍යා v, const පූර්ණ_සංඛ්‍යා *str)
{
    FILE *fp = tcc_state->ppfp;

    නම් (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    නැතහොත් නම් (msg[0] == '+')
         ++indent, ++msg;
    නැතහොත් නම් (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    නම් (msg[0] == '#') {
        define_print(tcc_state, v);
    } නැතහොත් {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#නැතහොත්
#define PP_PRINT(x)
#endif

static පූර්ණ_සංඛ්‍යා macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const පූර්ණ_සංඛ්‍යා *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static පූර්ණ_සංඛ්‍යා *macro_arg_subst(Sym **nested_list, const පූර්ණ_සංඛ්‍යා *macro_str, Sym *args)
{
    පූර්ණ_සංඛ්‍යා t, t0, t1, t2, n;
    const පූර්ණ_සංඛ්‍යා *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    සඳහා (s = args, n = 0; s; s = s->prev, ++n);
    අතරතුර (n--) {
        සඳහා (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    අතරතුර(1) {
        TOK_GET(&t, &macro_str, &cval);
        නම් (!t)
            bha_nga;
        නම් (t == '#') {
            /* stringize */
            do t = *macro_str++; අතරතුර (t == ' ');
            s = sym_find2(args, t);
            නම් (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                අතරතුර (*st != TOK_EOF) {
                    const var_na *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    අතරතුර (*s) {
                        නම් (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        නැතහොත්
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
            } නැතහොත් නම් ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } නැතහොත් {
                expect("macro parameter after '#'");
            }
        } නැතහොත් නම් (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            නම් (s) {
                st = s->d;
                n = 0;
                අතරතුර ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                නම් (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    නම් (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        පූර්ණ_සංඛ්‍යා c = str.str[str.len - 1];
                        අතරතුර (str.str[--str.len] != ',')
                            ;
                        නම් (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } නැතහොත් {
                            /* suppress '##' and add variable */
                            str.len++;
                            නම් (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } නැතහොත් {
                        නම් (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } නැතහොත් {
            add_var:
		    නම් (!s->e) {
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
                අතරතුර (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } නැතහොත් {
                tok_str_add(&str, t);
            }
        } නැතහොත් {
            tok_str_add2(&str, t, &cval);
        }
        නම් (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ආපසු str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static anta_hstha පූර්ණ_සංඛ්‍යා *macro_twosharps(const පූර්ණ_සංඛ්‍යා *ptr0)
{
    පූර්ණ_සංඛ්‍යා t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const පූර්ණ_සංඛ්‍යා *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    සඳහා (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        නම් (t1 == 0)
            bha_nga;
        සඳහා (;;) {
            n = 0;
            අතරතුර ((t2 = ptr[n]) == ' ')
                ++n;
            නම් (t2 != TOK_PPJOIN)
                bha_nga;
            ptr += n;
            අතරතුර ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            නම් (t2 == TOK_PLCHLDR)
                continue;
            නම් (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        නම් (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            සඳහා (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                නම් (*file->buf_ptr == 0)
                    bha_nga;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        නම් (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ආපසු macro_str1.str;
}

static පූර්ණ_සංඛ්‍යා peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    පූර්ණ_සංඛ්‍යා c;
    සඳහා (;;) {
        PEEKC(c, p);
        switch (c) {
        pak_sa '/':
            PEEKC(c, p);
            නම් (c == '*')
                p = parse_comment(p);
            නැතහොත් නම් (c == '/')
                p = parse_line_comment(p);
            නැතහොත් {
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
            ආපසු c;
        }
        නම් (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static පූර්ණ_සංඛ්‍යා next_argstream(Sym **nested_list, TokenString *ws_str)
{
    පූර්ණ_සංඛ්‍යා t;
    Sym *sa;

    අතරතුර (macro_ptr) {
        const පූර්ණ_සංඛ්‍යා *m = macro_ptr;
        අතරතුර ((t = *m) != 0) {
            නම් (ws_str) {
                නම් (t != ' ')
                    ආපසු t;
                ++m;
            } නැතහොත් {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ආපසු tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        නම් (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    නම් (ws_str) {
        ආපසු peek_file(ws_str);
    } නැතහොත් {
        next_nomacro();
        නම් (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ආපසු tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static පූර්ණ_සංඛ්‍යා macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    පූර්ණ_සංඛ්‍යා t;
    පූර්ණ_සංඛ්‍යා v = s->v;

    PP_PRINT(("#", v, s->d));
    නම් (s->d) {
        පූර්ණ_සංඛ්‍යා *mstr = s->d;
        පූර්ණ_සංඛ්‍යා *jstr;
        Sym *sa;
        පූර්ණ_සංඛ්‍යා ret;

        නම් (s->type.t & MACRO_FUNC) {
            පූර්ණ_සංඛ්‍යා saved_parse_flags = parse_flags;
            TokenString str;
            පූර්ණ_සංඛ්‍යා parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            නම් (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                නම් (parse_flags & PARSE_FLAG_SPACES)
                    සඳහා (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ආපසු 0;
            } නැතහොත් {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            සඳහා(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } අතරතුර (t == ' ' || --i);

                නම් (!sa) {
                    නම් (t == ')') /* handle '()' case */
                        bha_nga;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                අතරතුර (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    නම් (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    නම් (t == '(')
                        parlevel++;
                    නම් (t == ')')
                        parlevel--;
                    නම් (t == ' ')
                        str.need_spc |= 1;
                    නැතහොත්
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                නම් (t == ')') {
                    නම් (!sa)
                        bha_nga;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    නම් (sa->type.t && gnu_ext)
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
            අතරතුර (sa) {
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
        නම් (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        නම් (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        නම් (jstr != mstr)
            tok_str_free_str(jstr);
        නම් (mstr != s->d)
            tok_str_free_str(mstr);
        ආපසු ret;

    } නැතහොත් {
        CValue cval;
        var_na buf[32], *cstrval = buf;

        /* special macros */
        නම් (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, parimaa_na(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } නැතහොත් නම් (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } නැතහොත් නම් (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            sa_nracanaa tm *tm;
            time(&ti);
            tm = localtime(&ti);
            නම් (v == TOK___DATE__) {
                static var_na const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, parimaa_na(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } නැතහොත් {
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
        ආපසු 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static පූර්ණ_සංඛ්‍යා macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const පූර්ණ_සංඛ්‍යා *macro_str
    )
{
    Sym *s;
    පූර්ණ_සංඛ්‍යා t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    පූර්ණ_සංඛ්‍යා tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    අතරතුර (1) {
        TOK_GET(&t, &macro_str, &cval);
        නම් (t == 0 || t == TOK_EOF)
            bha_nga;
        නම් (t >= TOK_IDENT) {
            s = define_find(t);
            නම් (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            නම් (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (පූර්ණ_සංඛ්‍යා*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            නම් (macro_stack != str) {
                /* already finished by reading function macro arguments */
                bha_nga;
            }
            macro_str = macro_ptr;
            end_macro ();
        } නැතහොත් නම් (t == ' ') {
            නම් (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } නැතහොත් {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            නම් (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            නම් (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ආපසු nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    පූර්ණ_සංඛ්‍යා t;
    අතරතුර (macro_ptr) {
redo:
        t = *macro_ptr;
        නම් (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            නම් (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } නැතහොත් නම් (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } නැතහොත් නම් (t == TOK_EOF) {
            /* do nothing */
        } නැතහොත් {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            නම් (t == '\\') {
                නම් (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ආපසු;
    }

    next_nomacro();
    t = tok;
    නම් (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        නම් (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        ආපසු;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    නම් (t == TOK_PPNUM) {
        නම්  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } නැතහොත් නම් (t == TOK_PPSTR) {
        නම් (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(පූර්ණ_සංඛ්‍යා last_tok)
{
    TokenString *str = &unget_buf;
    පූර්ණ_සංඛ්‍යා alloc = 0;
    නම් (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    නම් (tok != TOK_EOF)
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
# නම් PTR_SIZE == 8
    "_WIN64\0"
# endif
#නැතහොත්
# නම් defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# නැතහොත්
    "__linux__\0"
    "__linux\0"
#  නම් TARGETOS_ANDROID
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
    අතරතුර (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, පූර්ණ_සංඛ්‍යා is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    නම් (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    නම් (is_asm)
      putdef(cs, "__ASSEMBLER__");
    නම් (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    නම් (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    නම් (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    නම් (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    නම් (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    නම් (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    නම් (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    නම් (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    නම් (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#නම් CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#නැතහොත්
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, පූර්ණ_සංඛ්‍යා filetype)
{
    පූර්ණ_සංඛ්‍යා is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

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

    නම් (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        නම් (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        නම් (s1->cmdline_incl.size)
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
    අතරතුර (macro_stack)
        end_macro();
    macro_ptr = NULL;
    අතරතුර (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC පූර්ණ_සංඛ්‍යා set_idnum(පූර්ණ_සංඛ්‍යා c, පූර්ණ_සංඛ්‍යා val)
{
    පූර්ණ_සංඛ්‍යා prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ආපසු prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    පූර්ණ_සංඛ්‍යා i, c;
    const var_na *p, *r;

    /* init isid table */
    සඳහා(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    සඳහා(i = 128; i<256; i++)
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
    අතරතුර (*p) {
        r = p;
        සඳහා(;;) {
            c = *r++;
            නම් (c == '\0')
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
    පූර්ණ_සංඛ්‍යා i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    නම් (n > total_idents)
        total_idents = n;
    සඳහා (i = n; --i >= 0;)
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

static පූර්ණ_සංඛ්‍යා pp_need_space(පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b);

static void tok_print(const පූර්ණ_සංඛ්‍යා *str, const var_na *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    පූර්ණ_සංඛ්‍යා t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    අතරතුර (str) {
	TOK_GET(&t, &str, &cval);
	නම් (t == 0 || t == TOK_EOF)
	    bha_nga;
        නම් (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, පූර්ණ_සංඛ්‍යා level)
{
    පූර්ණ_සංඛ්‍යා d = f->line_num - f->line_ref;

    නම් (s1->dflag & 4)
	ආපසු;

    නම් (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } නැතහොත් නම් (level == 0 && f->line_ref && d < 8) {
	අතරතුර (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } නැතහොත් නම් (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } නැතහොත් {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, පූර්ණ_සංඛ්‍යා v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    නම් (NULL == s || NULL == s->d)
        ආපසු;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    නම් (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        නම් (a)
            සඳහා (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                නම් (!(a = a->next))
                    bha_nga;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    පූර්ණ_සංඛ්‍යා v, t;
    const var_na *vs;
    FILE *fp;

    t = pp_debug_tok;
    නම් (t == 0)
        ආපසු;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    නම් (t == TOK_DEFINE) {
        define_print(s1, v);
    } නැතහොත් නම් (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } නැතහොත් නම් (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } නැතහොත් නම් (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static පූර්ණ_සංඛ්‍යා pp_need_space(පූර්ණ_සංඛ්‍යා a, පූර්ණ_සංඛ්‍යා b)
{
    ආපසු 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static පූර්ණ_සංඛ්‍යා pp_check_he0xE(පූර්ණ_සංඛ්‍යා t, const var_na *p)
{
    නම් (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ආපසු 'E';
    ආපසු t;
}

/* Preprocess the current file */
ST_FUNC පූර්ණ_සංඛ්‍යා tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    පූර්ණ_සංඛ්‍යා token_seen, spcs, level;
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
    නම් (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    නම් (s1->do_bench) {
	/* for PP benchmarks */
	do next(); අතරතුර (tok != TOK_EOF);
	ආපසු 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    නම් (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    සඳහා (;;) {
        iptr = s1->include_stack_ptr;
        next();
        නම් (tok == TOK_EOF)
            bha_nga;

        level = s1->include_stack_ptr - iptr;
        නම් (level) {
            නම් (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        නම් (s1->dflag & 7) {
            pp_debug_defines(s1);
            නම් (s1->dflag & 4)
                continue;
        }

        නම් (is_space(tok)) {
            නම් (spcs < parimaa_na white - 1)
                white[spcs++] = tok;
            continue;
        } නැතහොත් නම් (tok == TOK_LINEFEED) {
            spcs = 0;
            නම් (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } නැතහොත් නම් (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } නැතහොත් නම් (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ආපසු 0;
}

/* ------------------------------------------------------------------------- */
