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

ST_DATA ចំនួនគត់ tok_flags;
ST_DATA ចំនួនគត់ parse_flags;

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA ចំនួនគត់ tok;
ST_DATA CValue tokc;
ST_DATA const ចំនួនគត់ *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ចំនួនគត់ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ចំនួនគត់ pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static var_na token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned var_na isidnum_table[256 - CH_EOF];
static ចំនួនគត់ pp_debug_tok, pp_debug_symv;
static ចំនួនគត់ pp_counter;
static void tok_print(const ចំនួនគត់ *str, const var_na *msg, ...);
static void next_nomacro(void);
static void parse_number(const var_na *p);
static void parse_string(const var_na *p, ចំនួនគត់ len);

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

ST_FUNC void skip(ចំនួនគត់ c)
{
    ប្រសិនបើ (tok != c) {
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
#បើមិនដូច្នេះ
#ប្រសិនបើ !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#បើមិនដូច្នេះ
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const var_na *sfile, ចំនួនគត់ sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef sa_nracanaa TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    sa_nracanaa TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#ប្រសិនបើ TAL_INFO
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
#ប្រសិនបើ TAL_DEBUG
    ចំនួនគត់     line_num; /* negative line_num used for double free check */
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
#ប្រសិនបើ TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ត្រឡប់ al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#ប្រសិនបើ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#ប្រសិនបើ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ប្រសិនបើ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    ប្រសិនបើ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        ខណៈពេល (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            ប្រសិនបើ (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (ចំនួនគត់)header->size);
            }
            p += header->size + parimaa_na(tal_header_t);
        }
#ប្រសិនបើ TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    ប្រសិនបើ (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    ប្រសិនបើ (!p)
        ត្រឡប់;
    header = (tal_header_t *)p - 1;
#ប្រសិនបើ TAL_DEBUG
    ប្រសិនបើ (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (ចំនួនគត់)-header->line_num, (ចំនួនគត់)header->size);
    } បើមិនដូច្នេះ
        header->line_num = -header->line_num;
#endif
    al = *pal;
    ខណៈពេល ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    ប្រសិនបើ (0 == --al->nb_allocs) {
        *pal = al->next;
        ប្រសិនបើ ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } បើមិនដូច្នេះ {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } បើមិនដូច្នេះ ប្រសិនបើ ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + parimaa_na(tal_header_t);
    TinyAlloc *al = *pal;

    ប្រសិនបើ (p) {
        /* reallpc case */
        ខណៈពេល ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        ប្រសិនបើ ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        ប្រសិនបើ (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ត្រឡប់ ret;
        } បើមិនដូច្នេះ ប្រសិនបើ (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#ប្រសិនបើ TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } បើមិនដូច្នេះ {
        /* new alloc case */
        ខណៈពេល (al->p + adj_size > al->bufend) {
            al = al->next;
            ប្រសិនបើ (!al) {
                unsigned new_size = (*pal)->size;
                ប្រសិនបើ (adj_size > new_size) {
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
#ប្រសិនបើ  TAL_DEBUG
    {
        ចំនួនគត់ ofs = strlen(sfile) + 1 - parimaa_na header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#ប្រសិនបើ TAL_INFO
        ប្រសិនបើ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ប្រសិនបើ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ត្រឡប់ ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, ចំនួនគត់ new_size)
{
    ចំនួនគត់ size;

    size = cstr->size_allocated;
    ប្រសិនបើ (size < 8)
        size = 8; /* no need to allocate a too small first string */
    ខណៈពេល (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, ចំនួនគត់ ch)
{
    ចំនួនគត់ size;
    size = cstr->size + 1;
    ប្រសិនបើ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN var_na *unicode_to_utf8 (var_na *b, uint32_t Uc)
{
    ប្រសិនបើ (Uc<0x80) *b++=Uc;
    បើមិនដូច្នេះ ប្រសិនបើ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    បើមិនដូច្នេះ ប្រសិនបើ (Uc-0xd800u<0x800) goto error;
    បើមិនដូច្នេះ ប្រសិនបើ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    បើមិនដូច្នេះ ប្រសិនបើ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    បើមិនដូច្នេះ error: tcc_error("0x%x is not a valid universal character", Uc);
    ត្រឡប់ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, ចំនួនគត់ ch)
{
    var_na buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, ចំនួនគត់ len)
{
    ចំនួនគត់ size;
    ប្រសិនបើ (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    ប្រសិនបើ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, ចំនួនគត់ ch)
{
    ចំនួនគត់ size;
    size = cstr->size + parimaa_na(nwchar_t);
    ប្រសិនបើ (size > cstr->size_allocated)
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

ST_FUNC ចំនួនគត់ cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap)
{
    va_list v;
    ចំនួនគត់ len, size = 80;
    សម្រាប់ (;;) {
        size += cstr->size;
        ប្រសិនបើ (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        ប្រសិនបើ (len >= 0 && len < size)
            bha_nga;
        size *= 2;
    }
    cstr->size += len;
    ត្រឡប់ len;
}

ST_FUNC ចំនួនគត់ cstr_printf(CString *cstr, const var_na *fmt, ...)
{
    va_list ap; ចំនួនគត់ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ត្រឡប់ len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, ចំនួនគត់ c)
{
    ប្រសិនបើ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ប្រសិនបើ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } បើមិនដូច្នេះ {
        cstr_ccat(cstr, '\\');
        ប្រសិនបើ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } បើមិនដូច្នេះ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const var_na *str, ចំនួនគត់ len)
{
    TokenSym *ts, **ptable;
    ចំនួនគត់ i;

    ប្រសិនបើ (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ប្រសិនបើ ((i % TOK_ALLOC_INCR) == 0) {
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
    ត្រឡប់ ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const var_na *str, ចំនួនគត់ len)
{
    TokenSym *ts, **pts;
    ចំនួនគត់ i;
    unsigned ចំនួនគត់ h;
    
    h = TOK_HASH_INIT;
    សម្រាប់(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned var_na *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    សម្រាប់(;;) {
        ts = *pts;
        ប្រសិនបើ (!ts)
            bha_nga;
        ប្រសិនបើ (ts->len == len && !memcmp(ts->str, str, len))
            ត្រឡប់ ts;
        pts = &(ts->hash_next);
    }
    ត្រឡប់ tok_alloc_new(pts, str, len);
}

ST_FUNC ចំនួនគត់ tok_alloc_const(const var_na *str)
{
    ត្រឡប់ tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const var_na *get_tok_str(ចំនួនគត់ v, CValue *cv)
{
    var_na *p;
    ចំនួនគត់ i, len;

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
        ត្រឡប់ (var_na*)cv->str.data;
    pak_sa TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ប្រសិនបើ (v == TOK_STR) {
            len = cv->str.size - 1;
            សម្រាប់(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned var_na *)cv->str.data)[i]);
        } បើមិនដូច្នេះ {
            len = (cv->str.size / parimaa_na(nwchar_t)) - 1;
            សម្រាប់(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;

    pak_sa TOK_CFLOAT:
        ត្រឡប់ strcpy(p, "<float>");
    pak_sa TOK_CDOUBLE:
        ត្រឡប់ strcpy(p, "<double>");
    pak_sa TOK_CLDOUBLE:
        ត្រឡប់ strcpy(p, "<long double>");
    pak_sa TOK_LINENUM:
        ត្រឡប់ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    pak_sa TOK_LT:
        v = '<';
        goto addv;
    pak_sa TOK_GT:
        v = '>';
        goto addv;
    pak_sa TOK_DOTS:
        ត្រឡប់ strcpy(p, "...");
    pak_sa TOK_A_SHL:
        ត្រឡប់ strcpy(p, "<<=");
    pak_sa TOK_A_SAR:
        ត្រឡប់ strcpy(p, ">>=");
    pak_sa TOK_EOF:
        ត្រឡប់ strcpy(p, "<eof>");
    pak_sa 0: /* anonymous nameless symbols */
        ត្រឡប់ strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        ប្រសិនបើ (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned var_na *q = tok_two_chars;
            ខណៈពេល (*q) {
                ប្រសិនបើ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ត្រឡប់ cstr_buf.data;
                }
                q += 3;
            }
            ប្រសិនបើ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                bha_nga;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } បើមិនដូច្នេះ ប្រសិនបើ (v < tok_ident) {
            ត្រឡប់ table_ident[v - TOK_IDENT]->str;
        } បើមិនដូច្នេះ ប្រសិនបើ (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } បើមិនដូច្នេះ {
            /* should never happen */
            ត្រឡប់ NULL;
        }
        bha_nga;
    }
    ត្រឡប់ cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static ចំនួនគត់ handle_eob(void)
{
    BufferedFile *bf = file;
    ចំនួនគត់ len;

    /* only tries to read if really end of buffer */
    ប្រសិនបើ (bf->buf_ptr >= bf->buf_end) {
        ប្រសិនបើ (bf->fd >= 0) {
#ប្រសិនបើ defined(PARSE_DEBUG)
            len = 1;
#បើមិនដូច្នេះ
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            ប្រសិនបើ (len < 0)
                len = 0;
        } បើមិនដូច្នេះ {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    ប្រសិនបើ (bf->buf_ptr < bf->buf_end) {
        ត្រឡប់ bf->buf_ptr[0];
    } បើមិនដូច្នេះ {
        bf->buf_ptr = bf->buf_end;
        ត្រឡប់ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static ចំនួនគត់ next_c(void)
{
    ចំនួនគត់ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ប្រសិនបើ (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ត្រឡប់ ch;
}

/* input with '\[\r]\n' handling. */
static ចំនួនគត់ handle_stray_noerror(ចំនួនគត់ err)
{
    ចំនួនគត់ ch;
    ខណៈពេល ((ch = next_c()) == '\\') {
        ch = next_c();
        ប្រសិនបើ (ch == '\n') {
    newl:
            file->line_num++;
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (ch == '\r') {
                ch = next_c();
                ប្រសិនបើ (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            ប្រសិនបើ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ត្រឡប់ *--file->buf_ptr = '\\';
        }
    }
    ត្រឡប់ ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static ចំនួនគត់ handle_bs(uint8_t **p)
{
    ចំនួនគត់ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ត្រឡប់ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static ចំនួនគត់ handle_stray(uint8_t **p)
{
    ចំនួនគត់ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ត្រឡប់ c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    ប្រសិនបើ (c == '\\')\
        c = handle_stray(&p); \
}

static ចំនួនគត់ skip_spaces(void)
{
    ចំនួនគត់ ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } ខណៈពេល (isidnum_table[ch - CH_EOF] & IS_SPC);
    ត្រឡប់ ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    ចំនួនគត់ c;
    សម្រាប់(;;) {
        សម្រាប់ (;;) {
            c = *++p;
    redo:
            ប្រសិនបើ (c == '\n' || c == '\\')
                bha_nga;
            c = *++p;
            ប្រសិនបើ (c == '\n' || c == '\\')
                bha_nga;
        }
        ប្រសិនបើ (c == '\n')
            bha_nga;
        c = handle_bs(&p);
        ប្រសិនបើ (c == CH_EOF)
            bha_nga;
        ប្រសិនបើ (c != '\\')
            goto redo;
    }
    ត្រឡប់ p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    ចំនួនគត់ c;
    សម្រាប់(;;) {
        /* fast skip loop */
        សម្រាប់(;;) {
            c = *++p;
        redo:
            ប្រសិនបើ (c == '\n' || c == '*' || c == '\\')
                bha_nga;
            c = *++p;
            ប្រសិនបើ (c == '\n' || c == '*' || c == '\\')
                bha_nga;
        }
        /* now we can handle all the cases */
        ប្រសិនបើ (c == '\n') {
            file->line_num++;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '*') {
            do {
                c = *++p;
            } ខណៈពេល (c == '*');
            ប្រសិនបើ (c == '\\')
                c = handle_bs(&p);
            ប្រសិនបើ (c == '/')
                bha_nga;
            goto check_eof;
        } បើមិនដូច្នេះ {
            c = handle_bs(&p);
        check_eof:
            ប្រសិនបើ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ប្រសិនបើ (c != '\\')
                goto redo;
        }
    }
    ត្រឡប់ p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, ចំនួនគត់ sep, CString *str)
{
    ចំនួនគត់ c;
    សម្រាប់(;;) {
        c = *++p;
    redo:
        ប្រសិនបើ (c == sep) {
            bha_nga;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '\\') {
            c = handle_bs(&p);
            ប្រសិនបើ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } បើមិនដូច្នេះ ប្រសិនបើ (c == '\\') {
                ប្រសិនបើ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ប្រសិនបើ (c == '\\') {
                    c = handle_bs(&p);
                    ប្រសិនបើ (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } បើមិនដូច្នេះ {
                goto redo;
            }
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '\n') {
        add_lf:
            ប្រសិនបើ (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } បើមិនដូច្នេះ ប្រសិនបើ (str) { /* not skipping */
                goto unterminated_string;
            } បើមិនដូច្នេះ {
                //tcc_warning("missing terminating %c character", sep);
                ត្រឡប់ p;
            }
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '\r') {
            c = *++p;
            ប្រសិនបើ (c == '\\')
                c = handle_bs(&p);
            ប្រសិនបើ (c == '\n')
                goto add_lf;
            ប្រសិនបើ (c == CH_EOF)
                goto unterminated_string;
            ប្រសិនបើ (str)
                cstr_ccat(str, '\r');
            goto redo;
        } បើមិនដូច្នេះ {
        add_char:
            ប្រសិនបើ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ត្រឡប់ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    ចំនួនគត់ a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    សម្រាប់(;;) {
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
            ប្រសិនបើ (c == CH_EOF)
                expect("#endif");
            ប្រសិនបើ (c == '\\')
                ++p;
            continue;
        /* skip strings */
        pak_sa '\"':
        pak_sa '\'':
            ប្រសិនបើ (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            bha_nga;
        /* skip comments */
        pak_sa '/':
            ប្រសិនបើ (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            ប្រសិនបើ (c == '*') {
                p = parse_comment(p);
            } បើមិនដូច្នេះ ប្រសិនបើ (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        pak_sa '#':
            p++;
            ប្រសិនបើ (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                ប្រសិនបើ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                ប្រសិនបើ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_ENDIF)
                    a--;
                បើមិនដូច្នេះ ប្រសិនបើ( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_LINEFEED)
                    goto redo_start;
                បើមិនដូច្នេះ ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#ប្រសិនបើ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            បើមិនដូច្នេះ ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#បើមិនដូច្នេះ
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

#ប្រសិនបើ 0
/* return the number of additional 'ints' necessary to store the
   token */
static anta_hstha ចំនួនគត់ tok_size(const ចំនួនគត់ *p)
{
    switch(*p) {
        /* 4 bytes */
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
        ត្រឡប់ 1 + 1;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        ត្រឡប់ 1 + 1 + (p[1] + 3) / 4;
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
	ត្រឡប់ 1 + LONG_SIZE / 4;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        ត្រឡប់ 1 + 2;
    pak_sa TOK_CLDOUBLE:
        ត្រឡប់ 1 + LDOUBLE_WORDS;
    default:
        ត្រឡប់ 1 + 0;
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
    ត្រឡប់ str;
}

ST_FUNC void tok_str_free_str(ចំនួនគត់ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ចំនួនគត់ *tok_str_realloc(TokenString *s, ចំនួនគត់ new_size)
{
    ចំនួនគត់ *str, size;

    size = s->allocated_len;
    ប្រសិនបើ (size < 16)
        size = 16;
    ខណៈពេល (size < new_size)
        size = size * 2;
    ប្រសិនបើ (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * parimaa_na(ចំនួនគត់));
        s->allocated_len = size;
        s->str = str;
    }
    ត្រឡប់ s->str;
}

ST_FUNC void tok_str_add(TokenString *s, ចំនួនគត់ t)
{
    ចំនួនគត់ len, *str;

    len = s->len;
    str = s->str;
    ប្រសិនបើ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, ចំនួនគត់ alloc)
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
    ប្រសិនបើ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } បើមិនដូច្នេះ {
        ប្រសិនបើ (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, ចំនួនគត់ t, CValue *cv)
{
    ចំនួនគត់ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ប្រសិនបើ (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
#ប្រសិនបើ LONG_SIZE == 4
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
                1 + (cv->str.size + parimaa_na(ចំនួនគត់) - 1) / parimaa_na(ចំនួនគត់);
            ប្រសិនបើ (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#ប្រសិនបើ LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        bha_nga;
    pak_sa TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ប្រសិនបើ (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        ប្រសិនបើ (LDOUBLE_WORDS >= 4)
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
    ប្រសិនបើ (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, ចំនួនគត់ t, CValue *cv)
{
    ប្រសិនបើ (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static anta_hstha void tok_get(ចំនួនគត់ *t, const ចំនួនគត់ **pp, CValue *cv)
{
    const ចំនួនគត់ *p = *pp;
    ចំនួនគត់ n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#ប្រសិនបើ LONG_SIZE == 4
    pak_sa TOK_CLONG:
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_LINENUM:
        cv->i = *p++;
        bha_nga;
#ប្រសិនបើ LONG_SIZE == 4
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
        p += (cv->str.size + parimaa_na(ចំនួនគត់) - 1) / parimaa_na(ចំនួនគត់);
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#ប្រសិនបើ LONG_SIZE == 8
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
        ខណៈពេល (--n);
        bha_nga;
    default:
        bha_nga;
    }
    *pp = p;
}

#ប្រសិនបើ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#បើមិនដូច្នេះ
# define TOK_GET(t,p,c) do { \
    ចំនួនគត់ _t = **(p); \
    ប្រសិនបើ (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    បើមិនដូច្នេះ \
        *(t) = _t, ++*(p); \
    } ខណៈពេល (0)
#endif

static ចំនួនគត់ macro_is_equal(const ចំនួនគត់ *a, const ចំនួនគត់ *b)
{
    CValue cv;
    ចំនួនគត់ t;

    ប្រសិនបើ (!a || !b)
        ត្រឡប់ 1;

    ខណៈពេល (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ប្រសិនបើ (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ត្រឡប់ 0;
    }
    ត្រឡប់ !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(ចំនួនគត់ v, ចំនួនគត់ macro_type, ចំនួនគត់ *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    ប្រសិនបើ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    ចំនួនគត់ v = s->v;
    ប្រសិនបើ (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(ចំនួនគត់ v)
{
    v -= TOK_IDENT;
    ប្រសិនបើ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ត្រឡប់ NULL;
    ត្រឡប់ table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    ខណៈពេល (define_stack != b) {
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
    ប្រសិនបើ (s->include_stack_ptr != s->include_stack)
        ត្រឡប់;
    p = get_tok_str(tok, NULL);
    ប្រសិនបើ (0 != memcmp(p, "test_", 5))
        ត្រឡប់;
    ប្រសិនបើ (0 != --s->run_test)
        ត្រឡប់;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(ចំនួនគត់ warn)
{
    ប្រសិនបើ (tok == TOK_LINEFEED)
        ត្រឡប់;
    ប្រសិនបើ (warn)
        tcc_warning("extra tokens after directive");
    ខណៈពេល (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const var_na *filename, ចំនួនគត់ add);

static ចំនួនគត់ parse_include(TCCState *s1, ចំនួនគត់ do_next, ចំនួនគត់ test)
{
    ចំនួនគត់ c, i;
    var_na name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ប្រសិនបើ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, parimaa_na name, tokcstr.data, i);
        next_nomacro();
    } បើមិនដូច្នេះ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        សម្រាប់ (;;) {
            next();
            p = name, i = strlen(p) - 1;
            ប្រសិនបើ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                bha_nga;
            ប្រសិនបើ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, parimaa_na name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ប្រសិនបើ (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    សម្រាប់ (;;) {
        ++i;
        ប្រសិនបើ (i == 0) {
            /* check absolute include path */
            ប្រសិនបើ (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } បើមិនដូច្នេះ ប្រសិនបើ (i == 1) {
            /* search in file's dir if "header.h" */
            ប្រសិនបើ (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, parimaa_na buf, p, tcc_basename(p) - p);
        } បើមិនដូច្នេះ {
            ចំនួនគត់ j = i - 2, k = j - s1->nb_include_paths;
            ប្រសិនបើ (k < 0)
                p = s1->include_paths[j];
            បើមិនដូច្នេះ ប្រសិនបើ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            បើមិនដូច្នេះ ប្រសិនបើ (test)
                ត្រឡប់ 0;
            បើមិនដូច្នេះ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, parimaa_na buf, p);
            pstrcat(buf, parimaa_na buf, "/");
        }
        pstrcat(buf, parimaa_na buf, name);
        e = search_cached_include(s1, buf, 0);
        ប្រសិនបើ (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            ប្រសិនបើ ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (ចំនួនគត់)(s1->include_stack_ptr - s1->include_stack), "", buf);
            ត្រឡប់ 1;
        }
        ប្រសិនបើ (tcc_open(s1, buf) >= 0)
            bha_nga;
    }

    ប្រសិនបើ (test) {
        tcc_close();
    } បើមិនដូច្នេះ {
        ប្រសិនបើ (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        ប្រសិនបើ (s1->gen_deps) {
            BufferedFile *bf = file;
            ខណៈពេល (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            ប្រសិនបើ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ត្រឡប់ 1;
}

/* eval an expression for #if/#elif */
static ចំនួនគត់ expr_preprocess(TCCState *s1)
{
    ចំនួនគត់ c, t;
    ចំនួនគត់ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    ខណៈពេល (1) {
        next(); /* do macro subst */
        t = tok;
        ប្រសិនបើ (tok < TOK_IDENT) {
            ប្រសិនបើ (tok == TOK_LINEFEED || tok == TOK_EOF)
                bha_nga;
            ប្រសិនបើ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            ប្រសិនបើ (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ប្រសិនបើ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ប្រសិនបើ (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            ប្រសិនបើ (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            ប្រសិនបើ (t == '(') {
                next();
                ប្រសិនបើ (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    ប្រសិនបើ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ប្រសិនបើ (tok != ')')
                expect("')'");
            goto c_number;
        } បើមិនដូច្នេះ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    ប្រសិនបើ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    ប្រសិនបើ (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ត្រឡប់ c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    ខណៈពេល (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    ចំនួនគត់ v, t, varg, is_vaargs, t0;
    ចំនួនគត់ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ប្រសិនបើ (v < TOK_IDENT || v == TOK_DEFINED)
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
    ប្រសិនបើ (tok == '(') {
        ចំនួនគត់ dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        ប្រសិនបើ (tok != ')') សម្រាប់ (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            ប្រសិនបើ (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            ប្រសិនបើ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            ប្រសិនបើ (tok == ')')
                bha_nga;
            ប្រសិនបើ (tok != ',' || is_vaargs)
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
    ខណៈពេល (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ប្រសិនបើ (is_space(tok)) {
            str.need_spc |= 1;
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (TOK_TWOSHARPS == tok) {
                ប្រសិនបើ (0 == t0)
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
    ប្រសិនបើ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const var_na *filename, ចំនួនគត់ add)
{
    const var_na *s, *basename;
    unsigned ចំនួនគត់ h;
    CachedInclude *e;
    ចំនួនគត់ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ខណៈពេល ((c = (unsigned var_na)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#បើមិនដូច្នេះ
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    សម្រាប់(;;) {
        ប្រសិនបើ (i == 0)
            bha_nga;
        e = s1->cached_includes[i - 1];
        ប្រសិនបើ (0 == PATHCMP(filename, e->filename))
            ត្រឡប់ e;
        ប្រសិនបើ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ត្រឡប់ e;
        i = e->hash_next;
    }
    ប្រសិនបើ (!add)
        ត្រឡប់ NULL;

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
    ត្រឡប់ e;
}

static ចំនួនគត់ pragma_parse(TCCState *s1)
{
    next_nomacro();
    ប្រសិនបើ (tok == TOK_push_macro || tok == TOK_pop_macro) {
        ចំនួនគត់ t = tok, v;
        Sym *s;

        ប្រសិនបើ (next(), tok != '(')
            goto pragma_err;
        ប្រសិនបើ (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        ប្រសិនបើ (next(), tok != ')')
            goto pragma_err;
        ប្រសិនបើ (t == TOK_push_macro) {
            ខណៈពេល (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } បើមិនដូច្នេះ {
            សម្រាប់ (s = define_stack; s; s = s->prev)
                ប្រសិនបើ (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    bha_nga;
                }
        }
        ប្រសិនបើ (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        បើមិនដូច្នេះ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } បើមិនដូច្នេះ ប្រសិនបើ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ត្រឡប់ 1;

    } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        ប្រសិនបើ (tok == TOK_ASM_pop) {
            next();
            ប្រសិនបើ (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } បើមិនដូច្នេះ {
            ចំនួនគត់ val = 0;
            ប្រសិនបើ (tok != ')') {
                ប្រសិនបើ (tok == TOK_ASM_push) {
                    next();
                    ប្រសិនបើ (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    ប្រសិនបើ (tok != ',')
                        goto pack_set;
                    next();
                }
                ប្រសិនបើ (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                ប្រសិនបើ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        ប្រសិនបើ (tok != ')')
            goto pragma_err;

    } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_comment) {
        var_na *p; ចំនួនគត់ t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        ប្រសិនបើ (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        ប្រសិនបើ (tok != ')')
            goto pragma_err;
        ប្រសិនបើ (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } បើមិនដូច្នេះ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ត្រឡប់ 0;
    }
    next();
    ត្រឡប់ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const var_na *filename)
{
    var_na buf[1024];
    buf[0] = 0;
    ប្រសិនបើ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, parimaa_na buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, parimaa_na buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    ប្រសិនបើ (0 == strcmp(file->filename, buf))
        ត្រឡប់;
    //printf("new file '%s'\n", buf);
    ប្រសិនបើ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, parimaa_na file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(ចំនួនគត់ is_bof)
{
    TCCState *s1 = tcc_state;
    ចំនួនគត់ c, n, saved_parse_flags;
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
        ប្រសិនបើ (s)
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
        ប្រសិនបើ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ប្រសិនបើ (is_bof) {
            ប្រសិនបើ (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        ប្រសិនបើ (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        ប្រសិនបើ (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    pak_sa TOK_ELSE:
        next_nomacro();
        ប្រសិនបើ (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        ប្រសិនបើ (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    pak_sa TOK_ELIF:
        ប្រសិនបើ (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        ប្រសិនបើ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ប្រសិនបើ (c == 1) {
            skip_to_eol(0);
            c = 0;
        } បើមិនដូច្នេះ {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        ប្រសិនបើ (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ប្រសិនបើ (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        bha_nga;
    pak_sa TOK_ENDIF:
        next_nomacro();
        ប្រសិនបើ (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ប្រសិនបើ (file->ifndef_macro &&
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
        ប្រសិនបើ (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    pak_sa TOK_PPNUM:
        ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        សម្រាប់ (n = 0, q = tokc.str.data; *q; ++q) {
            ប្រសិនបើ (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        ប្រសិនបើ (tok != TOK_LINEFEED) {
            ប្រសិនបើ (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        ប្រសិនបើ (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        bha_nga;

    pak_sa TOK_ERROR:
    pak_sa TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ខណៈពេល (c != '\n' && c != CH_EOF) {
            ប្រសិនបើ ((q - buf) < parimaa_na(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ប្រសិនបើ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        បើមិនដូច្នេះ
            tcc_warning("#warning %s", buf);
        next_nomacro();
        bha_nga;
    }
    pak_sa TOK_PRAGMA:
        ប្រសិនបើ (!pragma_parse(s1))
            goto ignore;
        bha_nga;
    pak_sa TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        ប្រសិនបើ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        ប្រសិនបើ (tok == '!' && is_bof)
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
static void parse_escape_string(CString *outstr, const uint8_t *buf, ចំនួនគត់ is_long)
{
    ចំនួនគត់ c, n, i;
    const uint8_t *p;

    p = buf;
    សម្រាប់(;;) {
        c = *p;
        ប្រសិនបើ (c == '\0')
            bha_nga;
        ប្រសិនបើ (c == '\\') {
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
                ប្រសិនបើ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ប្រសិនបើ (isoct(c)) {
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
                    ប្រសិនបើ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    បើមិនដូច្នេះ ប្រសិនបើ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    បើមិនដូច្នេះ ប្រសិនបើ (isnum(c))
                        c = c - '0';
                    បើមិនដូច្នេះ ប្រសិនបើ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    បើមិនដូច្នេះ
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } ខណៈពេល (--i);
		ប្រសិនបើ (is_long) {
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
                ប្រសិនបើ (!gnu_ext)
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
                ប្រសិនបើ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                បើមិនដូច្នេះ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                bha_nga;
            }
        } បើមិនដូច្នេះ ប្រសិនបើ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ចំនួនគត់ cont; /* count of continuation bytes */
            ចំនួនគត់ skip; /* how many bytes should skip when error occurred */
            ចំនួនគត់ i;

            /* decode leading byte */
            ប្រសិនបើ (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } បើមិនដូច្នេះ ប្រសិនបើ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } បើមិនដូច្នេះ ប្រសិនបើ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } បើមិនដូច្នេះ ប្រសិនបើ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } បើមិនដូច្នេះ {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            សម្រាប់ (i = 1; i <= cont; i++) {
                ចំនួនគត់ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ប្រសិនបើ (i == 1) {
                    switch (c) {
                    pak_sa 0xE0: l = 0xA0; bha_nga;
                    pak_sa 0xED: h = 0x9F; bha_nga;
                    pak_sa 0xF0: l = 0x90; bha_nga;
                    pak_sa 0xF4: h = 0x8F; bha_nga;
                    }
                }

                ប្រសិនបើ (p[i] < l || p[i] > h) {
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
        ប្រសិនបើ (!is_long)
            cstr_ccat(outstr, c);
        បើមិនដូច្នេះ {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            ប្រសិនបើ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } បើមិនដូច្នេះ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#បើមិនដូច្នេះ
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    ប្រសិនបើ (!is_long)
        cstr_ccat(outstr, '\0');
    បើមិនដូច្នេះ
        cstr_wccat(outstr, '\0');
}

static void parse_string(const var_na *s, ចំនួនគត់ len)
{
    uint8_t buf[1000], *p = buf;
    ចំនួនគត់ is_long, sep;

    ប្រសិនបើ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ប្រសិនបើ (len >= parimaa_na buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ប្រសិនបើ (p != buf)
        tcc_free(p);

    ប្រសិនបើ (sep == '\'') {
        ចំនួនគត់ char_size, i, n, c;
        /* XXX: make it portable */
        ប្រសិនបើ (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        បើមិនដូច្នេះ
            tok = TOK_LCHAR, char_size = parimaa_na(nwchar_t);
        n = tokcstr.size / char_size - 1;
        ប្រសិនបើ (n < 1)
            tcc_error("empty character constant");
        ប្រសិនបើ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        សម្រាប់ (c = i = 0; i < n; ++i) {
            ប្រសិនបើ (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            បើមិនដូច្នេះ
                c = (c << 8) | ((var_na *)tokcstr.data)[i];
        }
        tokc.i = c;
    } បើមិនដូច្នេះ {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ប្រសិនបើ (!is_long)
            tok = TOK_STR;
        បើមិនដូច្នេះ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static ចំនួនគត់ bn_lshift(unsigned ចំនួនគត់ *bn, ចំនួនគត់ shift, ចំនួនគត់ or_val)
{
    ចំនួនគត់ i;
    unsigned ចំនួនគត់ v;
    ប្រសិនបើ (bn[BN_SIZE - 1] >> (32 - shift))
	ត្រឡប់ shift;
    សម្រាប់(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ត្រឡប់ 0;
}

static void bn_zero(unsigned ចំនួនគត់ *bn)
{
    ចំនួនគត់ i;
    សម្រាប់(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const var_na *p)
{
    ចំនួនគត់ b, t, shift, frac_bits, s, exp_val, ch;
    var_na *q;
    unsigned ចំនួនគត់ bn[BN_SIZE];
    long dviguu_na d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ប្រសិនបើ (t == '.') {
        goto float_frac_parse;
    } បើមិនដូច្នេះ ប្រសិនបើ (t == '0') {
        ប្រសិនបើ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } បើមិនដូច្នេះ ប្រសិនបើ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ខណៈពេល (1) {
        ប្រសិនបើ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        បើមិនដូច្នេះ ប្រសិនបើ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        បើមិនដូច្នេះ ប្រសិនបើ (isnum(ch))
            t = ch - '0';
        បើមិនដូច្នេះ
            bha_nga;
        ប្រសិនបើ (t >= b)
            bha_nga;
        ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ប្រសិនបើ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ប្រសិនបើ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            ប្រសិនបើ (b == 16)
                shift = 4;
            បើមិនដូច្នេះ 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            ខណៈពេល (1) {
                t = *q++;
                ប្រសិនបើ (t == '\0') {
                    bha_nga;
                } បើមិនដូច្នេះ ប្រសិនបើ (t >= 'a') {
                    t = t - 'a' + 10;
                } បើមិនដូច្នេះ ប្រសិនបើ (t >= 'A') {
                    t = t - 'A' + 10;
                } បើមិនដូច្នេះ {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            ប្រសិនបើ (ch == '.') {
                ch = *p++;
                ខណៈពេល (1) {
                    t = ch;
                    ប្រសិនបើ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } បើមិនដូច្នេះ ប្រសិនបើ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } បើមិនដូច្នេះ ប្រសិនបើ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } បើមិនដូច្នេះ {
                        bha_nga;
                    }
                    ប្រសិនបើ (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            ប្រសិនបើ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ប្រសិនបើ (ch == '+') {
                ch = *p++;
            } បើមិនដូច្នេះ ប្រសិនបើ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ប្រសិនបើ (ch < '0' || ch > '9')
                expect("exponent digits");
            ខណៈពេល (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ប្រសិនបើ (exp_val < 100000000)
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
            ប្រសិនបើ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } បើមិនដូច្នេះ ប្រសិនបើ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } បើមិនដូច្នេះ {
                tok = TOK_CDOUBLE;
                tokc.d = (dviguu_na)d;
            }
        } បើមិនដូច្នេះ {
            /* decimal floats */
            ប្រសិនបើ (ch == '.') {
                ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ខណៈពេល (ch >= '0' && ch <= '9') {
                    ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ប្រសិនបើ (ch == 'e' || ch == 'E') {
                ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                ប្រសិនបើ (ch == '-' || ch == '+') {
                    ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ប្រសិនបើ (ch < '0' || ch > '9')
                    expect("exponent digits");
                ខណៈពេល (ch >= '0' && ch <= '9') {
                    ប្រសិនបើ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ប្រសិនបើ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } បើមិនដូច្នេះ ប្រសិនបើ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } បើមិនដូច្នេះ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } បើមិនដូច្នេះ {
        unsigned long long n, n1;
        ចំនួនគត់ lcount, ucount, ov = 0;
        const var_na *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ប្រសិនបើ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ខណៈពេល(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ប្រសិនបើ (t == '\0')
                bha_nga;
            បើមិនដូច្នេះ ប្រសិនបើ (t >= 'a')
                t = t - 'a' + 10;
            បើមិនដូច្នេះ ប្រសិនបើ (t >= 'A')
                t = t - 'A' + 10;
            បើមិនដូច្នេះ
                t = t - '0';
            ប្រសិនបើ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ប្រសិនបើ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        សម្រាប់(;;) {
            t = toup(ch);
            ប្រសិនបើ (t == 'L') {
                ប្រសិនបើ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ប្រសិនបើ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } បើមិនដូច្នេះ ប្រសិនបើ (t == 'U') {
                ប្រសិនបើ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } បើមិនដូច្នេះ {
                bha_nga;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ប្រសិនបើ (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ប្រសិនបើ (ucount == 0 && b == 10) {
            ប្រសិនបើ (lcount <= (LONG_SIZE == 4)) {
                ប្រសិនបើ (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            ប្រសិនបើ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (lcount <= (LONG_SIZE == 4)) {
                ប្រសិនបើ (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                បើមិនដូច្នេះ ប្រសិនបើ (n >= 0x80000000U)
                    ucount = 1;
            }
            ប្រសិនបើ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ប្រសិនបើ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ប្រសិនបើ (lcount) {
            tok = TOK_CLONG;
            ប្រសិនបើ (lcount == 2)
                tok = TOK_CLLONG;
	}
	ប្រសិនបើ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ប្រសិនបើ (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    pak_sa c1:                                    \
        PEEKC(c, p);                            \
        ប្រសិនបើ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } បើមិនដូច្នេះ {                                \
            tok = tok1;                         \
        }                                       \
        bha_nga;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    ចំនួនគត់ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned ចំនួនគត់ h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    pak_sa ' ':
    pak_sa '\t':
        tok = c;
        p++;
 maybe_space:
        ប្រសិនបើ (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        ខណៈពេល (isidnum_table[*p - CH_EOF] & IS_SPC)
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
        ប្រសិនបើ (c == '\\')
            goto parse_simple;
        ប្រសិនបើ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ប្រសិនបើ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } បើមិនដូច្នេះ ប្រសិនបើ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } បើមិនដូច្នេះ ប្រសិនបើ (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } បើមិនដូច្នេះ ប្រសិនបើ (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } បើមិនដូច្នេះ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ប្រសិនបើ (tok_flags & TOK_FLAG_ENDIF) {
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
        } បើមិនដូច្នេះ {
            goto redo_no_start;
        }
        bha_nga;

    pak_sa '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ប្រសិនបើ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    pak_sa '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ប្រសិនបើ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } បើមិនដូច្នេះ {
            ប្រសិនបើ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } បើមិនដូច្នេះ {
#ប្រសិនបើ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } បើមិនដូច្នេះ
#endif
                {
                    tok = '#';
                }
            }
        }
        bha_nga;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    pak_sa '$':
        ប្រសិនបើ (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        ខណៈពេល (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ប្រសិនបើ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            សម្រាប់(;;) {
                ts = *pts;
                ប្រសិនបើ (!ts)
                    bha_nga;
                ប្រសិនបើ (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (var_na *) p1, len);
        token_found: ;
        } បើមិនដូច្នេះ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (var_na *) p1, len);
            p--;
            PEEKC(c, p);
            ខណៈពេល (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        ប្រសិនបើ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ប្រសិនបើ (c == '\'' || c == '\"') {
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
        សម្រាប់(;;) {
            cstr_ccat(&tokcstr, t);
            ប្រសិនបើ (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        ប្រសិនបើ (isnum(c)) {
            t = '.';
            goto parse_num;
        } បើមិនដូច្នេះ ប្រសិនបើ ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '.') {
            PEEKC(c, p);
            ប្រសិនបើ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } បើមិនដូច្នេះ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } បើមិនដូច្នេះ {
            tok = '.';
        }
        bha_nga;
    pak_sa '\'':
    pak_sa '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ប្រសិនបើ (is_long)
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
        ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_LE;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '<') {
            PEEKC(c, p);
            ប្រសិនបើ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } បើមិនដូច្នេះ {
                tok = TOK_SHL;
            }
        } បើមិនដូច្នេះ {
            tok = TOK_LT;
        }
        bha_nga;
    pak_sa '>':
        PEEKC(c, p);
        ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_GE;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '>') {
            PEEKC(c, p);
            ប្រសិនបើ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } បើមិនដូច្នេះ {
                tok = TOK_SAR;
            }
        } បើមិនដូច្នេះ {
            tok = TOK_GT;
        }
        bha_nga;
        
    pak_sa '&':
        PEEKC(c, p);
        ប្រសិនបើ (c == '&') {
            p++;
            tok = TOK_LAND;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } បើមិនដូច្នេះ {
            tok = '&';
        }
        bha_nga;
        
    pak_sa '|':
        PEEKC(c, p);
        ប្រសិនបើ (c == '|') {
            p++;
            tok = TOK_LOR;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } បើមិនដូច្នេះ {
            tok = '|';
        }
        bha_nga;

    pak_sa '+':
        PEEKC(c, p);
        ប្រសិនបើ (c == '+') {
            p++;
            tok = TOK_INC;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } បើមិនដូច្នេះ {
            tok = '+';
        }
        bha_nga;
        
    pak_sa '-':
        PEEKC(c, p);
        ប្រសិនបើ (c == '-') {
            p++;
            tok = TOK_DEC;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } បើមិនដូច្នេះ {
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
        ប្រសិនបើ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } បើមិនដូច្នេះ ប្រសិនបើ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } បើមិនដូច្នេះ {
            tok = '/';
        }
        bha_nga;
        
        /* simple tokens */
    pak_sa '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE) {
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
        ប្រសិនបើ (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        ប្រសិនបើ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        ប្រសិនបើ (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        bha_nga;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ប្រសិនបើ defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static ចំនួនគត់ indent;
static void define_print(TCCState *s1, ចំនួនគត់ v);
static void pp_print(const var_na *msg, ចំនួនគត់ v, const ចំនួនគត់ *str)
{
    FILE *fp = tcc_state->ppfp;

    ប្រសិនបើ (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    បើមិនដូច្នេះ ប្រសិនបើ (msg[0] == '+')
         ++indent, ++msg;
    បើមិនដូច្នេះ ប្រសិនបើ (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    ប្រសិនបើ (msg[0] == '#') {
        define_print(tcc_state, v);
    } បើមិនដូច្នេះ {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#បើមិនដូច្នេះ
#define PP_PRINT(x)
#endif

static ចំនួនគត់ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ចំនួនគត់ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static ចំនួនគត់ *macro_arg_subst(Sym **nested_list, const ចំនួនគត់ *macro_str, Sym *args)
{
    ចំនួនគត់ t, t0, t1, t2, n;
    const ចំនួនគត់ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    សម្រាប់ (s = args, n = 0; s; s = s->prev, ++n);
    ខណៈពេល (n--) {
        សម្រាប់ (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    ខណៈពេល(1) {
        TOK_GET(&t, &macro_str, &cval);
        ប្រសិនបើ (!t)
            bha_nga;
        ប្រសិនបើ (t == '#') {
            /* stringize */
            do t = *macro_str++; ខណៈពេល (t == ' ');
            s = sym_find2(args, t);
            ប្រសិនបើ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ខណៈពេល (*st != TOK_EOF) {
                    const var_na *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ខណៈពេល (*s) {
                        ប្រសិនបើ (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        បើមិនដូច្នេះ
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
            } បើមិនដូច្នេះ ប្រសិនបើ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } បើមិនដូច្នេះ {
                expect("macro parameter after '#'");
            }
        } បើមិនដូច្នេះ ប្រសិនបើ (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            ប្រសិនបើ (s) {
                st = s->d;
                n = 0;
                ខណៈពេល ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ប្រសិនបើ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ប្រសិនបើ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ចំនួនគត់ c = str.str[str.len - 1];
                        ខណៈពេល (str.str[--str.len] != ',')
                            ;
                        ប្រសិនបើ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } បើមិនដូច្នេះ {
                            /* suppress '##' and add variable */
                            str.len++;
                            ប្រសិនបើ (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } បើមិនដូច្នេះ {
                        ប្រសិនបើ (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } បើមិនដូច្នេះ {
            add_var:
		    ប្រសិនបើ (!s->e) {
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
                ខណៈពេល (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } បើមិនដូច្នេះ {
                tok_str_add(&str, t);
            }
        } បើមិនដូច្នេះ {
            tok_str_add2(&str, t, &cval);
        }
        ប្រសិនបើ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ត្រឡប់ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static anta_hstha ចំនួនគត់ *macro_twosharps(const ចំនួនគត់ *ptr0)
{
    ចំនួនគត់ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const ចំនួនគត់ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    សម្រាប់ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ប្រសិនបើ (t1 == 0)
            bha_nga;
        សម្រាប់ (;;) {
            n = 0;
            ខណៈពេល ((t2 = ptr[n]) == ' ')
                ++n;
            ប្រសិនបើ (t2 != TOK_PPJOIN)
                bha_nga;
            ptr += n;
            ខណៈពេល ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ប្រសិនបើ (t2 == TOK_PLCHLDR)
                continue;
            ប្រសិនបើ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ប្រសិនបើ (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            សម្រាប់ (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ប្រសិនបើ (*file->buf_ptr == 0)
                    bha_nga;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ប្រសិនបើ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ត្រឡប់ macro_str1.str;
}

static ចំនួនគត់ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ចំនួនគត់ c;
    សម្រាប់ (;;) {
        PEEKC(c, p);
        switch (c) {
        pak_sa '/':
            PEEKC(c, p);
            ប្រសិនបើ (c == '*')
                p = parse_comment(p);
            បើមិនដូច្នេះ ប្រសិនបើ (c == '/')
                p = parse_line_comment(p);
            បើមិនដូច្នេះ {
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
            ត្រឡប់ c;
        }
        ប្រសិនបើ (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static ចំនួនគត់ next_argstream(Sym **nested_list, TokenString *ws_str)
{
    ចំនួនគត់ t;
    Sym *sa;

    ខណៈពេល (macro_ptr) {
        const ចំនួនគត់ *m = macro_ptr;
        ខណៈពេល ((t = *m) != 0) {
            ប្រសិនបើ (ws_str) {
                ប្រសិនបើ (t != ' ')
                    ត្រឡប់ t;
                ++m;
            } បើមិនដូច្នេះ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ត្រឡប់ tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ប្រសិនបើ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ប្រសិនបើ (ws_str) {
        ត្រឡប់ peek_file(ws_str);
    } បើមិនដូច្នេះ {
        next_nomacro();
        ប្រសិនបើ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ត្រឡប់ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static ចំនួនគត់ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ចំនួនគត់ t;
    ចំនួនគត់ v = s->v;

    PP_PRINT(("#", v, s->d));
    ប្រសិនបើ (s->d) {
        ចំនួនគត់ *mstr = s->d;
        ចំនួនគត់ *jstr;
        Sym *sa;
        ចំនួនគត់ ret;

        ប្រសិនបើ (s->type.t & MACRO_FUNC) {
            ចំនួនគត់ saved_parse_flags = parse_flags;
            TokenString str;
            ចំនួនគត់ parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            ប្រសិនបើ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ប្រសិនបើ (parse_flags & PARSE_FLAG_SPACES)
                    សម្រាប់ (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ត្រឡប់ 0;
            } បើមិនដូច្នេះ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            សម្រាប់(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } ខណៈពេល (t == ' ' || --i);

                ប្រសិនបើ (!sa) {
                    ប្រសិនបើ (t == ')') /* handle '()' case */
                        bha_nga;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ខណៈពេល (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ប្រសិនបើ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ប្រសិនបើ (t == '(')
                        parlevel++;
                    ប្រសិនបើ (t == ')')
                        parlevel--;
                    ប្រសិនបើ (t == ' ')
                        str.need_spc |= 1;
                    បើមិនដូច្នេះ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                ប្រសិនបើ (t == ')') {
                    ប្រសិនបើ (!sa)
                        bha_nga;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ប្រសិនបើ (sa->type.t && gnu_ext)
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
            ខណៈពេល (sa) {
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
        ប្រសិនបើ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ប្រសិនបើ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ប្រសិនបើ (jstr != mstr)
            tok_str_free_str(jstr);
        ប្រសិនបើ (mstr != s->d)
            tok_str_free_str(mstr);
        ត្រឡប់ ret;

    } បើមិនដូច្នេះ {
        CValue cval;
        var_na buf[32], *cstrval = buf;

        /* special macros */
        ប្រសិនបើ (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, parimaa_na(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } បើមិនដូច្នេះ ប្រសិនបើ (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } បើមិនដូច្នេះ ប្រសិនបើ (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            sa_nracanaa tm *tm;
            time(&ti);
            tm = localtime(&ti);
            ប្រសិនបើ (v == TOK___DATE__) {
                static var_na const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, parimaa_na(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } បើមិនដូច្នេះ {
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
        ត្រឡប់ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static ចំនួនគត់ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ចំនួនគត់ *macro_str
    )
{
    Sym *s;
    ចំនួនគត់ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    ចំនួនគត់ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    ខណៈពេល (1) {
        TOK_GET(&t, &macro_str, &cval);
        ប្រសិនបើ (t == 0 || t == TOK_EOF)
            bha_nga;
        ប្រសិនបើ (t >= TOK_IDENT) {
            s = define_find(t);
            ប្រសិនបើ (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            ប្រសិនបើ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (ចំនួនគត់*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ប្រសិនបើ (macro_stack != str) {
                /* already finished by reading function macro arguments */
                bha_nga;
            }
            macro_str = macro_ptr;
            end_macro ();
        } បើមិនដូច្នេះ ប្រសិនបើ (t == ' ') {
            ប្រសិនបើ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } បើមិនដូច្នេះ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ប្រសិនបើ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ប្រសិនបើ (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ត្រឡប់ nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    ចំនួនគត់ t;
    ខណៈពេល (macro_ptr) {
redo:
        t = *macro_ptr;
        ប្រសិនបើ (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ប្រសិនបើ (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } បើមិនដូច្នេះ ប្រសិនបើ (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } បើមិនដូច្នេះ ប្រសិនបើ (t == TOK_EOF) {
            /* do nothing */
        } បើមិនដូច្នេះ {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            ប្រសិនបើ (t == '\\') {
                ប្រសិនបើ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ត្រឡប់;
    }

    next_nomacro();
    t = tok;
    ប្រសិនបើ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        ប្រសិនបើ (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        ត្រឡប់;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ប្រសិនបើ (t == TOK_PPNUM) {
        ប្រសិនបើ  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } បើមិនដូច្នេះ ប្រសិនបើ (t == TOK_PPSTR) {
        ប្រសិនបើ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(ចំនួនគត់ last_tok)
{
    TokenString *str = &unget_buf;
    ចំនួនគត់ alloc = 0;
    ប្រសិនបើ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ប្រសិនបើ (tok != TOK_EOF)
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
# ប្រសិនបើ PTR_SIZE == 8
    "_WIN64\0"
# endif
#បើមិនដូច្នេះ
# ប្រសិនបើ defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# បើមិនដូច្នេះ
    "__linux__\0"
    "__linux\0"
#  ប្រសិនបើ TARGETOS_ANDROID
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
    ខណៈពេល (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, ចំនួនគត់ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    ប្រសិនបើ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    ប្រសិនបើ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ប្រសិនបើ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ប្រសិនបើ (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    ប្រសិនបើ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    ប្រសិនបើ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    ប្រសិនបើ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ប្រសិនបើ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ប្រសិនបើ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ប្រសិនបើ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    ប្រសិនបើ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ប្រសិនបើ CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#បើមិនដូច្នេះ
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, ចំនួនគត់ filetype)
{
    ចំនួនគត់ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

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

    ប្រសិនបើ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ប្រសិនបើ (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        ប្រសិនបើ (s1->cmdline_incl.size)
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
    ខណៈពេល (macro_stack)
        end_macro();
    macro_ptr = NULL;
    ខណៈពេល (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ចំនួនគត់ set_idnum(ចំនួនគត់ c, ចំនួនគត់ val)
{
    ចំនួនគត់ prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ត្រឡប់ prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    ចំនួនគត់ i, c;
    const var_na *p, *r;

    /* init isid table */
    សម្រាប់(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    សម្រាប់(i = 128; i<256; i++)
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
    ខណៈពេល (*p) {
        r = p;
        សម្រាប់(;;) {
            c = *r++;
            ប្រសិនបើ (c == '\0')
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
    ចំនួនគត់ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ប្រសិនបើ (n > total_idents)
        total_idents = n;
    សម្រាប់ (i = n; --i >= 0;)
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

static ចំនួនគត់ pp_need_space(ចំនួនគត់ a, ចំនួនគត់ b);

static void tok_print(const ចំនួនគត់ *str, const var_na *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ចំនួនគត់ t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    ខណៈពេល (str) {
	TOK_GET(&t, &str, &cval);
	ប្រសិនបើ (t == 0 || t == TOK_EOF)
	    bha_nga;
        ប្រសិនបើ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, ចំនួនគត់ level)
{
    ចំនួនគត់ d = f->line_num - f->line_ref;

    ប្រសិនបើ (s1->dflag & 4)
	ត្រឡប់;

    ប្រសិនបើ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } បើមិនដូច្នេះ ប្រសិនបើ (level == 0 && f->line_ref && d < 8) {
	ខណៈពេល (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } បើមិនដូច្នេះ ប្រសិនបើ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } បើមិនដូច្នេះ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, ចំនួនគត់ v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    ប្រសិនបើ (NULL == s || NULL == s->d)
        ត្រឡប់;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    ប្រសិនបើ (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        ប្រសិនបើ (a)
            សម្រាប់ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                ប្រសិនបើ (!(a = a->next))
                    bha_nga;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    ចំនួនគត់ v, t;
    const var_na *vs;
    FILE *fp;

    t = pp_debug_tok;
    ប្រសិនបើ (t == 0)
        ត្រឡប់;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    ប្រសិនបើ (t == TOK_DEFINE) {
        define_print(s1, v);
    } បើមិនដូច្នេះ ប្រសិនបើ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } បើមិនដូច្នេះ ប្រសិនបើ (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } បើមិនដូច្នេះ ប្រសិនបើ (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static ចំនួនគត់ pp_need_space(ចំនួនគត់ a, ចំនួនគត់ b)
{
    ត្រឡប់ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static ចំនួនគត់ pp_check_he0xE(ចំនួនគត់ t, const var_na *p)
{
    ប្រសិនបើ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ត្រឡប់ 'E';
    ត្រឡប់ t;
}

/* Preprocess the current file */
ST_FUNC ចំនួនគត់ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ចំនួនគត់ token_seen, spcs, level;
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
    ប្រសិនបើ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    ប្រសិនបើ (s1->do_bench) {
	/* for PP benchmarks */
	do next(); ខណៈពេល (tok != TOK_EOF);
	ត្រឡប់ 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    ប្រសិនបើ (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    សម្រាប់ (;;) {
        iptr = s1->include_stack_ptr;
        next();
        ប្រសិនបើ (tok == TOK_EOF)
            bha_nga;

        level = s1->include_stack_ptr - iptr;
        ប្រសិនបើ (level) {
            ប្រសិនបើ (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        ប្រសិនបើ (s1->dflag & 7) {
            pp_debug_defines(s1);
            ប្រសិនបើ (s1->dflag & 4)
                continue;
        }

        ប្រសិនបើ (is_space(tok)) {
            ប្រសិនបើ (spcs < parimaa_na white - 1)
                white[spcs++] = tok;
            continue;
        } បើមិនដូច្នេះ ប្រសិនបើ (tok == TOK_LINEFEED) {
            spcs = 0;
            ប្រសិនបើ (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } បើមិនដូច្នេះ ប្រសិនបើ (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } បើមិនដូច្នេះ ប្រសិនបើ (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ត្រឡប់ 0;
}

/* ------------------------------------------------------------------------- */
