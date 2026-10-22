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

ST_DATA ကိန်းပြည့် tok_flags;
ST_DATA ကိန်းပြည့် parse_flags;

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA ကိန်းပြည့် tok;
ST_DATA CValue tokc;
ST_DATA const ကိန်းပြည့် *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ကိန်းပြည့် tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ကိန်းပြည့် pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static var_na token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned var_na isidnum_table[256 - CH_EOF];
static ကိန်းပြည့် pp_debug_tok, pp_debug_symv;
static ကိန်းပြည့် pp_counter;
static void tok_print(const ကိန်းပြည့် *str, const var_na *msg, ...);
static void next_nomacro(void);
static void parse_number(const var_na *p);
static void parse_string(const var_na *p, ကိန်းပြည့် len);

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

ST_FUNC void skip(ကိန်းပြည့် c)
{
    အကယ်၍ (tok != c) {
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
#မဟုတ်ပါက
#အကယ်၍ !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#မဟုတ်ပါက
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const var_na *sfile, ကိန်းပြည့် sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef sa_nracanaa TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    sa_nracanaa TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#အကယ်၍ TAL_INFO
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
#အကယ်၍ TAL_DEBUG
    ကိန်းပြည့်     line_num; /* negative line_num used for double free check */
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
#အကယ်၍ TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ပြန်ပေး al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#အကယ်၍ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#အကယ်၍ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#အကယ်၍ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    အကယ်၍ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        နေစဉ် (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            အကယ်၍ (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (ကိန်းပြည့်)header->size);
            }
            p += header->size + parimaa_na(tal_header_t);
        }
#အကယ်၍ TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    အကယ်၍ (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    အကယ်၍ (!p)
        ပြန်ပေး;
    header = (tal_header_t *)p - 1;
#အကယ်၍ TAL_DEBUG
    အကယ်၍ (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (ကိန်းပြည့်)-header->line_num, (ကိန်းပြည့်)header->size);
    } မဟုတ်ပါက
        header->line_num = -header->line_num;
#endif
    al = *pal;
    နေစဉ် ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    အကယ်၍ (0 == --al->nb_allocs) {
        *pal = al->next;
        အကယ်၍ ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } မဟုတ်ပါက {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } မဟုတ်ပါက အကယ်၍ ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + parimaa_na(tal_header_t);
    TinyAlloc *al = *pal;

    အကယ်၍ (p) {
        /* reallpc case */
        နေစဉ် ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        အကယ်၍ ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        အကယ်၍ (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ပြန်ပေး ret;
        } မဟုတ်ပါက အကယ်၍ (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#အကယ်၍ TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } မဟုတ်ပါက {
        /* new alloc case */
        နေစဉ် (al->p + adj_size > al->bufend) {
            al = al->next;
            အကယ်၍ (!al) {
                unsigned new_size = (*pal)->size;
                အကယ်၍ (adj_size > new_size) {
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
#အကယ်၍  TAL_DEBUG
    {
        ကိန်းပြည့် ofs = strlen(sfile) + 1 - parimaa_na header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#အကယ်၍ TAL_INFO
        အကယ်၍ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        အကယ်၍ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ပြန်ပေး ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, ကိန်းပြည့် new_size)
{
    ကိန်းပြည့် size;

    size = cstr->size_allocated;
    အကယ်၍ (size < 8)
        size = 8; /* no need to allocate a too small first string */
    နေစဉ် (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, ကိန်းပြည့် ch)
{
    ကိန်းပြည့် size;
    size = cstr->size + 1;
    အကယ်၍ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN var_na *unicode_to_utf8 (var_na *b, uint32_t Uc)
{
    အကယ်၍ (Uc<0x80) *b++=Uc;
    မဟုတ်ပါက အကယ်၍ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    မဟုတ်ပါက အကယ်၍ (Uc-0xd800u<0x800) goto error;
    မဟုတ်ပါက အကယ်၍ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    မဟုတ်ပါက အကယ်၍ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    မဟုတ်ပါက error: tcc_error("0x%x is not a valid universal character", Uc);
    ပြန်ပေး b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, ကိန်းပြည့် ch)
{
    var_na buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, ကိန်းပြည့် len)
{
    ကိန်းပြည့် size;
    အကယ်၍ (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    အကယ်၍ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, ကိန်းပြည့် ch)
{
    ကိန်းပြည့် size;
    size = cstr->size + parimaa_na(nwchar_t);
    အကယ်၍ (size > cstr->size_allocated)
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

ST_FUNC ကိန်းပြည့် cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap)
{
    va_list v;
    ကိန်းပြည့် len, size = 80;
    အတွက် (;;) {
        size += cstr->size;
        အကယ်၍ (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        အကယ်၍ (len >= 0 && len < size)
            bha_nga;
        size *= 2;
    }
    cstr->size += len;
    ပြန်ပေး len;
}

ST_FUNC ကိန်းပြည့် cstr_printf(CString *cstr, const var_na *fmt, ...)
{
    va_list ap; ကိန်းပြည့် len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ပြန်ပေး len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, ကိန်းပြည့် c)
{
    အကယ်၍ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    အကယ်၍ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } မဟုတ်ပါက {
        cstr_ccat(cstr, '\\');
        အကယ်၍ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } မဟုတ်ပါက {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const var_na *str, ကိန်းပြည့် len)
{
    TokenSym *ts, **ptable;
    ကိန်းပြည့် i;

    အကယ်၍ (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    အကယ်၍ ((i % TOK_ALLOC_INCR) == 0) {
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
    ပြန်ပေး ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const var_na *str, ကိန်းပြည့် len)
{
    TokenSym *ts, **pts;
    ကိန်းပြည့် i;
    unsigned ကိန်းပြည့် h;
    
    h = TOK_HASH_INIT;
    အတွက်(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned var_na *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    အတွက်(;;) {
        ts = *pts;
        အကယ်၍ (!ts)
            bha_nga;
        အကယ်၍ (ts->len == len && !memcmp(ts->str, str, len))
            ပြန်ပေး ts;
        pts = &(ts->hash_next);
    }
    ပြန်ပေး tok_alloc_new(pts, str, len);
}

ST_FUNC ကိန်းပြည့် tok_alloc_const(const var_na *str)
{
    ပြန်ပေး tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const var_na *get_tok_str(ကိန်းပြည့် v, CValue *cv)
{
    var_na *p;
    ကိန်းပြည့် i, len;

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
        ပြန်ပေး (var_na*)cv->str.data;
    pak_sa TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        အကယ်၍ (v == TOK_STR) {
            len = cv->str.size - 1;
            အတွက်(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned var_na *)cv->str.data)[i]);
        } မဟုတ်ပါက {
            len = (cv->str.size / parimaa_na(nwchar_t)) - 1;
            အတွက်(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;

    pak_sa TOK_CFLOAT:
        ပြန်ပေး strcpy(p, "<float>");
    pak_sa TOK_CDOUBLE:
        ပြန်ပေး strcpy(p, "<double>");
    pak_sa TOK_CLDOUBLE:
        ပြန်ပေး strcpy(p, "<long double>");
    pak_sa TOK_LINENUM:
        ပြန်ပေး strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    pak_sa TOK_LT:
        v = '<';
        goto addv;
    pak_sa TOK_GT:
        v = '>';
        goto addv;
    pak_sa TOK_DOTS:
        ပြန်ပေး strcpy(p, "...");
    pak_sa TOK_A_SHL:
        ပြန်ပေး strcpy(p, "<<=");
    pak_sa TOK_A_SAR:
        ပြန်ပေး strcpy(p, ">>=");
    pak_sa TOK_EOF:
        ပြန်ပေး strcpy(p, "<eof>");
    pak_sa 0: /* anonymous nameless symbols */
        ပြန်ပေး strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        အကယ်၍ (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned var_na *q = tok_two_chars;
            နေစဉ် (*q) {
                အကယ်၍ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ပြန်ပေး cstr_buf.data;
                }
                q += 3;
            }
            အကယ်၍ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                bha_nga;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } မဟုတ်ပါက အကယ်၍ (v < tok_ident) {
            ပြန်ပေး table_ident[v - TOK_IDENT]->str;
        } မဟုတ်ပါက အကယ်၍ (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } မဟုတ်ပါက {
            /* should never happen */
            ပြန်ပေး NULL;
        }
        bha_nga;
    }
    ပြန်ပေး cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static ကိန်းပြည့် handle_eob(void)
{
    BufferedFile *bf = file;
    ကိန်းပြည့် len;

    /* only tries to read if really end of buffer */
    အကယ်၍ (bf->buf_ptr >= bf->buf_end) {
        အကယ်၍ (bf->fd >= 0) {
#အကယ်၍ defined(PARSE_DEBUG)
            len = 1;
#မဟုတ်ပါက
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            အကယ်၍ (len < 0)
                len = 0;
        } မဟုတ်ပါက {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    အကယ်၍ (bf->buf_ptr < bf->buf_end) {
        ပြန်ပေး bf->buf_ptr[0];
    } မဟုတ်ပါက {
        bf->buf_ptr = bf->buf_end;
        ပြန်ပေး CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static ကိန်းပြည့် next_c(void)
{
    ကိန်းပြည့် ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    အကယ်၍ (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ပြန်ပေး ch;
}

/* input with '\[\r]\n' handling. */
static ကိန်းပြည့် handle_stray_noerror(ကိန်းပြည့် err)
{
    ကိန်းပြည့် ch;
    နေစဉ် ((ch = next_c()) == '\\') {
        ch = next_c();
        အကယ်၍ (ch == '\n') {
    newl:
            file->line_num++;
        } မဟုတ်ပါက {
            အကယ်၍ (ch == '\r') {
                ch = next_c();
                အကယ်၍ (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            အကယ်၍ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ပြန်ပေး *--file->buf_ptr = '\\';
        }
    }
    ပြန်ပေး ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static ကိန်းပြည့် handle_bs(uint8_t **p)
{
    ကိန်းပြည့် c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ပြန်ပေး c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static ကိန်းပြည့် handle_stray(uint8_t **p)
{
    ကိန်းပြည့် c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ပြန်ပေး c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    အကယ်၍ (c == '\\')\
        c = handle_stray(&p); \
}

static ကိန်းပြည့် skip_spaces(void)
{
    ကိန်းပြည့် ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } နေစဉ် (isidnum_table[ch - CH_EOF] & IS_SPC);
    ပြန်ပေး ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    ကိန်းပြည့် c;
    အတွက်(;;) {
        အတွက် (;;) {
            c = *++p;
    redo:
            အကယ်၍ (c == '\n' || c == '\\')
                bha_nga;
            c = *++p;
            အကယ်၍ (c == '\n' || c == '\\')
                bha_nga;
        }
        အကယ်၍ (c == '\n')
            bha_nga;
        c = handle_bs(&p);
        အကယ်၍ (c == CH_EOF)
            bha_nga;
        အကယ်၍ (c != '\\')
            goto redo;
    }
    ပြန်ပေး p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    ကိန်းပြည့် c;
    အတွက်(;;) {
        /* fast skip loop */
        အတွက်(;;) {
            c = *++p;
        redo:
            အကယ်၍ (c == '\n' || c == '*' || c == '\\')
                bha_nga;
            c = *++p;
            အကယ်၍ (c == '\n' || c == '*' || c == '\\')
                bha_nga;
        }
        /* now we can handle all the cases */
        အကယ်၍ (c == '\n') {
            file->line_num++;
        } မဟုတ်ပါက အကယ်၍ (c == '*') {
            do {
                c = *++p;
            } နေစဉ် (c == '*');
            အကယ်၍ (c == '\\')
                c = handle_bs(&p);
            အကယ်၍ (c == '/')
                bha_nga;
            goto check_eof;
        } မဟုတ်ပါက {
            c = handle_bs(&p);
        check_eof:
            အကယ်၍ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            အကယ်၍ (c != '\\')
                goto redo;
        }
    }
    ပြန်ပေး p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, ကိန်းပြည့် sep, CString *str)
{
    ကိန်းပြည့် c;
    အတွက်(;;) {
        c = *++p;
    redo:
        အကယ်၍ (c == sep) {
            bha_nga;
        } မဟုတ်ပါက အကယ်၍ (c == '\\') {
            c = handle_bs(&p);
            အကယ်၍ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } မဟုတ်ပါက အကယ်၍ (c == '\\') {
                အကယ်၍ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                အကယ်၍ (c == '\\') {
                    c = handle_bs(&p);
                    အကယ်၍ (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } မဟုတ်ပါက {
                goto redo;
            }
        } မဟုတ်ပါက အကယ်၍ (c == '\n') {
        add_lf:
            အကယ်၍ (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } မဟုတ်ပါက အကယ်၍ (str) { /* not skipping */
                goto unterminated_string;
            } မဟုတ်ပါက {
                //tcc_warning("missing terminating %c character", sep);
                ပြန်ပေး p;
            }
        } မဟုတ်ပါက အကယ်၍ (c == '\r') {
            c = *++p;
            အကယ်၍ (c == '\\')
                c = handle_bs(&p);
            အကယ်၍ (c == '\n')
                goto add_lf;
            အကယ်၍ (c == CH_EOF)
                goto unterminated_string;
            အကယ်၍ (str)
                cstr_ccat(str, '\r');
            goto redo;
        } မဟုတ်ပါက {
        add_char:
            အကယ်၍ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ပြန်ပေး p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    ကိန်းပြည့် a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    အတွက်(;;) {
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
            အကယ်၍ (c == CH_EOF)
                expect("#endif");
            အကယ်၍ (c == '\\')
                ++p;
            continue;
        /* skip strings */
        pak_sa '\"':
        pak_sa '\'':
            အကယ်၍ (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            bha_nga;
        /* skip comments */
        pak_sa '/':
            အကယ်၍ (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            အကယ်၍ (c == '*') {
                p = parse_comment(p);
            } မဟုတ်ပါက အကယ်၍ (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        pak_sa '#':
            p++;
            အကယ်၍ (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                အကယ်၍ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                အကယ်၍ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                မဟုတ်ပါက အကယ်၍ (tok == TOK_ENDIF)
                    a--;
                မဟုတ်ပါက အကယ်၍( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                မဟုတ်ပါက အကယ်၍ (tok == TOK_LINEFEED)
                    goto redo_start;
                မဟုတ်ပါက အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#အကယ်၍ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            မဟုတ်ပါက အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#မဟုတ်ပါက
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

#အကယ်၍ 0
/* return the number of additional 'ints' necessary to store the
   token */
static anta_hstha ကိန်းပြည့် tok_size(const ကိန်းပြည့် *p)
{
    switch(*p) {
        /* 4 bytes */
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
        ပြန်ပေး 1 + 1;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        ပြန်ပေး 1 + 1 + (p[1] + 3) / 4;
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
	ပြန်ပေး 1 + LONG_SIZE / 4;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        ပြန်ပေး 1 + 2;
    pak_sa TOK_CLDOUBLE:
        ပြန်ပေး 1 + LDOUBLE_WORDS;
    default:
        ပြန်ပေး 1 + 0;
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
    ပြန်ပေး str;
}

ST_FUNC void tok_str_free_str(ကိန်းပြည့် *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ကိန်းပြည့် *tok_str_realloc(TokenString *s, ကိန်းပြည့် new_size)
{
    ကိန်းပြည့် *str, size;

    size = s->allocated_len;
    အကယ်၍ (size < 16)
        size = 16;
    နေစဉ် (size < new_size)
        size = size * 2;
    အကယ်၍ (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * parimaa_na(ကိန်းပြည့်));
        s->allocated_len = size;
        s->str = str;
    }
    ပြန်ပေး s->str;
}

ST_FUNC void tok_str_add(TokenString *s, ကိန်းပြည့် t)
{
    ကိန်းပြည့် len, *str;

    len = s->len;
    str = s->str;
    အကယ်၍ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, ကိန်းပြည့် alloc)
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
    အကယ်၍ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } မဟုတ်ပါက {
        အကယ်၍ (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, ကိန်းပြည့် t, CValue *cv)
{
    ကိန်းပြည့် len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    အကယ်၍ (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
#အကယ်၍ LONG_SIZE == 4
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
                1 + (cv->str.size + parimaa_na(ကိန်းပြည့်) - 1) / parimaa_na(ကိန်းပြည့်);
            အကယ်၍ (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#အကယ်၍ LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        bha_nga;
    pak_sa TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        အကယ်၍ (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        အကယ်၍ (LDOUBLE_WORDS >= 4)
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
    အကယ်၍ (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, ကိန်းပြည့် t, CValue *cv)
{
    အကယ်၍ (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static anta_hstha void tok_get(ကိန်းပြည့် *t, const ကိန်းပြည့် **pp, CValue *cv)
{
    const ကိန်းပြည့် *p = *pp;
    ကိန်းပြည့် n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#အကယ်၍ LONG_SIZE == 4
    pak_sa TOK_CLONG:
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_LINENUM:
        cv->i = *p++;
        bha_nga;
#အကယ်၍ LONG_SIZE == 4
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
        p += (cv->str.size + parimaa_na(ကိန်းပြည့်) - 1) / parimaa_na(ကိန်းပြည့်);
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#အကယ်၍ LONG_SIZE == 8
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
        နေစဉ် (--n);
        bha_nga;
    default:
        bha_nga;
    }
    *pp = p;
}

#အကယ်၍ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#မဟုတ်ပါက
# define TOK_GET(t,p,c) do { \
    ကိန်းပြည့် _t = **(p); \
    အကယ်၍ (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    မဟုတ်ပါက \
        *(t) = _t, ++*(p); \
    } နေစဉ် (0)
#endif

static ကိန်းပြည့် macro_is_equal(const ကိန်းပြည့် *a, const ကိန်းပြည့် *b)
{
    CValue cv;
    ကိန်းပြည့် t;

    အကယ်၍ (!a || !b)
        ပြန်ပေး 1;

    နေစဉ် (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        အကယ်၍ (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ပြန်ပေး 0;
    }
    ပြန်ပေး !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(ကိန်းပြည့် v, ကိန်းပြည့် macro_type, ကိန်းပြည့် *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    အကယ်၍ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    ကိန်းပြည့် v = s->v;
    အကယ်၍ (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(ကိန်းပြည့် v)
{
    v -= TOK_IDENT;
    အကယ်၍ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ပြန်ပေး NULL;
    ပြန်ပေး table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    နေစဉ် (define_stack != b) {
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
    အကယ်၍ (s->include_stack_ptr != s->include_stack)
        ပြန်ပေး;
    p = get_tok_str(tok, NULL);
    အကယ်၍ (0 != memcmp(p, "test_", 5))
        ပြန်ပေး;
    အကယ်၍ (0 != --s->run_test)
        ပြန်ပေး;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(ကိန်းပြည့် warn)
{
    အကယ်၍ (tok == TOK_LINEFEED)
        ပြန်ပေး;
    အကယ်၍ (warn)
        tcc_warning("extra tokens after directive");
    နေစဉ် (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const var_na *filename, ကိန်းပြည့် add);

static ကိန်းပြည့် parse_include(TCCState *s1, ကိန်းပြည့် do_next, ကိန်းပြည့် test)
{
    ကိန်းပြည့် c, i;
    var_na name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    အကယ်၍ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, parimaa_na name, tokcstr.data, i);
        next_nomacro();
    } မဟုတ်ပါက {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        အတွက် (;;) {
            next();
            p = name, i = strlen(p) - 1;
            အကယ်၍ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                bha_nga;
            အကယ်၍ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, parimaa_na name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    အကယ်၍ (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    အတွက် (;;) {
        ++i;
        အကယ်၍ (i == 0) {
            /* check absolute include path */
            အကယ်၍ (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } မဟုတ်ပါက အကယ်၍ (i == 1) {
            /* search in file's dir if "header.h" */
            အကယ်၍ (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, parimaa_na buf, p, tcc_basename(p) - p);
        } မဟုတ်ပါက {
            ကိန်းပြည့် j = i - 2, k = j - s1->nb_include_paths;
            အကယ်၍ (k < 0)
                p = s1->include_paths[j];
            မဟုတ်ပါက အကယ်၍ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            မဟုတ်ပါက အကယ်၍ (test)
                ပြန်ပေး 0;
            မဟုတ်ပါက
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, parimaa_na buf, p);
            pstrcat(buf, parimaa_na buf, "/");
        }
        pstrcat(buf, parimaa_na buf, name);
        e = search_cached_include(s1, buf, 0);
        အကယ်၍ (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            အကယ်၍ ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (ကိန်းပြည့်)(s1->include_stack_ptr - s1->include_stack), "", buf);
            ပြန်ပေး 1;
        }
        အကယ်၍ (tcc_open(s1, buf) >= 0)
            bha_nga;
    }

    အကယ်၍ (test) {
        tcc_close();
    } မဟုတ်ပါက {
        အကယ်၍ (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        အကယ်၍ (s1->gen_deps) {
            BufferedFile *bf = file;
            နေစဉ် (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            အကယ်၍ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ပြန်ပေး 1;
}

/* eval an expression for #if/#elif */
static ကိန်းပြည့် expr_preprocess(TCCState *s1)
{
    ကိန်းပြည့် c, t;
    ကိန်းပြည့် t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    နေစဉ် (1) {
        next(); /* do macro subst */
        t = tok;
        အကယ်၍ (tok < TOK_IDENT) {
            အကယ်၍ (tok == TOK_LINEFEED || tok == TOK_EOF)
                bha_nga;
            အကယ်၍ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } မဟုတ်ပါက အကယ်၍ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            အကယ်၍ (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            အကယ်၍ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            အကယ်၍ (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            အကယ်၍ (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            အကယ်၍ (t == '(') {
                next();
                အကယ်၍ (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } မဟုတ်ပါက အကယ်၍ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    အကယ်၍ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            အကယ်၍ (tok != ')')
                expect("')'");
            goto c_number;
        } မဟုတ်ပါက {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    အကယ်၍ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    အကယ်၍ (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ပြန်ပေး c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    နေစဉ် (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    ကိန်းပြည့် v, t, varg, is_vaargs, t0;
    ကိန်းပြည့် saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    အကယ်၍ (v < TOK_IDENT || v == TOK_DEFINED)
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
    အကယ်၍ (tok == '(') {
        ကိန်းပြည့် dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        အကယ်၍ (tok != ')') အတွက် (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            အကယ်၍ (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } မဟုတ်ပါက အကယ်၍ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            အကယ်၍ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            အကယ်၍ (tok == ')')
                bha_nga;
            အကယ်၍ (tok != ',' || is_vaargs)
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
    နေစဉ် (tok != TOK_LINEFEED && tok != TOK_EOF) {
        အကယ်၍ (is_space(tok)) {
            str.need_spc |= 1;
        } မဟုတ်ပါက {
            အကယ်၍ (TOK_TWOSHARPS == tok) {
                အကယ်၍ (0 == t0)
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
    အကယ်၍ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const var_na *filename, ကိန်းပြည့် add)
{
    const var_na *s, *basename;
    unsigned ကိန်းပြည့် h;
    CachedInclude *e;
    ကိန်းပြည့် c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    နေစဉ် ((c = (unsigned var_na)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#မဟုတ်ပါက
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    အတွက်(;;) {
        အကယ်၍ (i == 0)
            bha_nga;
        e = s1->cached_includes[i - 1];
        အကယ်၍ (0 == PATHCMP(filename, e->filename))
            ပြန်ပေး e;
        အကယ်၍ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ပြန်ပေး e;
        i = e->hash_next;
    }
    အကယ်၍ (!add)
        ပြန်ပေး NULL;

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
    ပြန်ပေး e;
}

static ကိန်းပြည့် pragma_parse(TCCState *s1)
{
    next_nomacro();
    အကယ်၍ (tok == TOK_push_macro || tok == TOK_pop_macro) {
        ကိန်းပြည့် t = tok, v;
        Sym *s;

        အကယ်၍ (next(), tok != '(')
            goto pragma_err;
        အကယ်၍ (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        အကယ်၍ (next(), tok != ')')
            goto pragma_err;
        အကယ်၍ (t == TOK_push_macro) {
            နေစဉ် (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } မဟုတ်ပါက {
            အတွက် (s = define_stack; s; s = s->prev)
                အကယ်၍ (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    bha_nga;
                }
        }
        အကယ်၍ (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        မဟုတ်ပါက
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } မဟုတ်ပါက အကယ်၍ (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } မဟုတ်ပါက အကယ်၍ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ပြန်ပေး 1;

    } မဟုတ်ပါက အကယ်၍ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        အကယ်၍ (tok == TOK_ASM_pop) {
            next();
            အကယ်၍ (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } မဟုတ်ပါက {
            ကိန်းပြည့် val = 0;
            အကယ်၍ (tok != ')') {
                အကယ်၍ (tok == TOK_ASM_push) {
                    next();
                    အကယ်၍ (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    အကယ်၍ (tok != ',')
                        goto pack_set;
                    next();
                }
                အကယ်၍ (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                အကယ်၍ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        အကယ်၍ (tok != ')')
            goto pragma_err;

    } မဟုတ်ပါက အကယ်၍ (tok == TOK_comment) {
        var_na *p; ကိန်းပြည့် t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        အကယ်၍ (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        အကယ်၍ (tok != ')')
            goto pragma_err;
        အကယ်၍ (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } မဟုတ်ပါက {
            အကယ်၍ (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } မဟုတ်ပါက {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ပြန်ပေး 0;
    }
    next();
    ပြန်ပေး 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const var_na *filename)
{
    var_na buf[1024];
    buf[0] = 0;
    အကယ်၍ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, parimaa_na buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, parimaa_na buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    အကယ်၍ (0 == strcmp(file->filename, buf))
        ပြန်ပေး;
    //printf("new file '%s'\n", buf);
    အကယ်၍ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, parimaa_na file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(ကိန်းပြည့် is_bof)
{
    TCCState *s1 = tcc_state;
    ကိန်းပြည့် c, n, saved_parse_flags;
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
        အကယ်၍ (s)
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
        အကယ်၍ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        အကယ်၍ (is_bof) {
            အကယ်၍ (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        အကယ်၍ (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        အကယ်၍ (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    pak_sa TOK_ELSE:
        next_nomacro();
        အကယ်၍ (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        အကယ်၍ (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    pak_sa TOK_ELIF:
        အကယ်၍ (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        အကယ်၍ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        အကယ်၍ (c == 1) {
            skip_to_eol(0);
            c = 0;
        } မဟုတ်ပါက {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        အကယ်၍ (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        အကယ်၍ (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        bha_nga;
    pak_sa TOK_ENDIF:
        next_nomacro();
        အကယ်၍ (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        အကယ်၍ (file->ifndef_macro &&
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
        အကယ်၍ (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    pak_sa TOK_PPNUM:
        အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        အတွက် (n = 0, q = tokc.str.data; *q; ++q) {
            အကယ်၍ (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        အကယ်၍ (tok != TOK_LINEFEED) {
            အကယ်၍ (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        အကယ်၍ (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        bha_nga;

    pak_sa TOK_ERROR:
    pak_sa TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        နေစဉ် (c != '\n' && c != CH_EOF) {
            အကယ်၍ ((q - buf) < parimaa_na(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        အကယ်၍ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        မဟုတ်ပါက
            tcc_warning("#warning %s", buf);
        next_nomacro();
        bha_nga;
    }
    pak_sa TOK_PRAGMA:
        အကယ်၍ (!pragma_parse(s1))
            goto ignore;
        bha_nga;
    pak_sa TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        အကယ်၍ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        အကယ်၍ (tok == '!' && is_bof)
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
static void parse_escape_string(CString *outstr, const uint8_t *buf, ကိန်းပြည့် is_long)
{
    ကိန်းပြည့် c, n, i;
    const uint8_t *p;

    p = buf;
    အတွက်(;;) {
        c = *p;
        အကယ်၍ (c == '\0')
            bha_nga;
        အကယ်၍ (c == '\\') {
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
                အကယ်၍ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    အကယ်၍ (isoct(c)) {
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
                    အကယ်၍ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    မဟုတ်ပါက အကယ်၍ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    မဟုတ်ပါက အကယ်၍ (isnum(c))
                        c = c - '0';
                    မဟုတ်ပါက အကယ်၍ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    မဟုတ်ပါက
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } နေစဉ် (--i);
		အကယ်၍ (is_long) {
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
                အကယ်၍ (!gnu_ext)
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
                အကယ်၍ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                မဟုတ်ပါက
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                bha_nga;
            }
        } မဟုတ်ပါက အကယ်၍ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ကိန်းပြည့် cont; /* count of continuation bytes */
            ကိန်းပြည့် skip; /* how many bytes should skip when error occurred */
            ကိန်းပြည့် i;

            /* decode leading byte */
            အကယ်၍ (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } မဟုတ်ပါက အကယ်၍ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } မဟုတ်ပါက အကယ်၍ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } မဟုတ်ပါက အကယ်၍ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } မဟုတ်ပါက {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            အတွက် (i = 1; i <= cont; i++) {
                ကိန်းပြည့် l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                အကယ်၍ (i == 1) {
                    switch (c) {
                    pak_sa 0xE0: l = 0xA0; bha_nga;
                    pak_sa 0xED: h = 0x9F; bha_nga;
                    pak_sa 0xF0: l = 0x90; bha_nga;
                    pak_sa 0xF4: h = 0x8F; bha_nga;
                    }
                }

                အကယ်၍ (p[i] < l || p[i] > h) {
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
        အကယ်၍ (!is_long)
            cstr_ccat(outstr, c);
        မဟုတ်ပါက {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            အကယ်၍ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } မဟုတ်ပါက {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#မဟုတ်ပါက
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    အကယ်၍ (!is_long)
        cstr_ccat(outstr, '\0');
    မဟုတ်ပါက
        cstr_wccat(outstr, '\0');
}

static void parse_string(const var_na *s, ကိန်းပြည့် len)
{
    uint8_t buf[1000], *p = buf;
    ကိန်းပြည့် is_long, sep;

    အကယ်၍ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    အကယ်၍ (len >= parimaa_na buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    အကယ်၍ (p != buf)
        tcc_free(p);

    အကယ်၍ (sep == '\'') {
        ကိန်းပြည့် char_size, i, n, c;
        /* XXX: make it portable */
        အကယ်၍ (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        မဟုတ်ပါက
            tok = TOK_LCHAR, char_size = parimaa_na(nwchar_t);
        n = tokcstr.size / char_size - 1;
        အကယ်၍ (n < 1)
            tcc_error("empty character constant");
        အကယ်၍ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        အတွက် (c = i = 0; i < n; ++i) {
            အကယ်၍ (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            မဟုတ်ပါက
                c = (c << 8) | ((var_na *)tokcstr.data)[i];
        }
        tokc.i = c;
    } မဟုတ်ပါက {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        အကယ်၍ (!is_long)
            tok = TOK_STR;
        မဟုတ်ပါက
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static ကိန်းပြည့် bn_lshift(unsigned ကိန်းပြည့် *bn, ကိန်းပြည့် shift, ကိန်းပြည့် or_val)
{
    ကိန်းပြည့် i;
    unsigned ကိန်းပြည့် v;
    အကယ်၍ (bn[BN_SIZE - 1] >> (32 - shift))
	ပြန်ပေး shift;
    အတွက်(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ပြန်ပေး 0;
}

static void bn_zero(unsigned ကိန်းပြည့် *bn)
{
    ကိန်းပြည့် i;
    အတွက်(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const var_na *p)
{
    ကိန်းပြည့် b, t, shift, frac_bits, s, exp_val, ch;
    var_na *q;
    unsigned ကိန်းပြည့် bn[BN_SIZE];
    long dviguu_na d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    အကယ်၍ (t == '.') {
        goto float_frac_parse;
    } မဟုတ်ပါက အကယ်၍ (t == '0') {
        အကယ်၍ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } မဟုတ်ပါက အကယ်၍ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    နေစဉ် (1) {
        အကယ်၍ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        မဟုတ်ပါက အကယ်၍ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        မဟုတ်ပါက အကယ်၍ (isnum(ch))
            t = ch - '0';
        မဟုတ်ပါက
            bha_nga;
        အကယ်၍ (t >= b)
            bha_nga;
        အကယ်၍ (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    အကယ်၍ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        အကယ်၍ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            အကယ်၍ (b == 16)
                shift = 4;
            မဟုတ်ပါက 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            နေစဉ် (1) {
                t = *q++;
                အကယ်၍ (t == '\0') {
                    bha_nga;
                } မဟုတ်ပါက အကယ်၍ (t >= 'a') {
                    t = t - 'a' + 10;
                } မဟုတ်ပါက အကယ်၍ (t >= 'A') {
                    t = t - 'A' + 10;
                } မဟုတ်ပါက {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            အကယ်၍ (ch == '.') {
                ch = *p++;
                နေစဉ် (1) {
                    t = ch;
                    အကယ်၍ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } မဟုတ်ပါက အကယ်၍ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } မဟုတ်ပါက အကယ်၍ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } မဟုတ်ပါက {
                        bha_nga;
                    }
                    အကယ်၍ (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            အကယ်၍ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            အကယ်၍ (ch == '+') {
                ch = *p++;
            } မဟုတ်ပါက အကယ်၍ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            အကယ်၍ (ch < '0' || ch > '9')
                expect("exponent digits");
            နေစဉ် (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		အကယ်၍ (exp_val < 100000000)
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
            အကယ်၍ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } မဟုတ်ပါက အကယ်၍ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } မဟုတ်ပါက {
                tok = TOK_CDOUBLE;
                tokc.d = (dviguu_na)d;
            }
        } မဟုတ်ပါက {
            /* decimal floats */
            အကယ်၍ (ch == '.') {
                အကယ်၍ (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                နေစဉ် (ch >= '0' && ch <= '9') {
                    အကယ်၍ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            အကယ်၍ (ch == 'e' || ch == 'E') {
                အကယ်၍ (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                အကယ်၍ (ch == '-' || ch == '+') {
                    အကယ်၍ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                အကယ်၍ (ch < '0' || ch > '9')
                    expect("exponent digits");
                နေစဉ် (ch >= '0' && ch <= '9') {
                    အကယ်၍ (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            အကယ်၍ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } မဟုတ်ပါက အကယ်၍ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } မဟုတ်ပါက {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } မဟုတ်ပါက {
        unsigned long long n, n1;
        ကိန်းပြည့် lcount, ucount, ov = 0;
        const var_na *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        အကယ်၍ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        နေစဉ်(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            အကယ်၍ (t == '\0')
                bha_nga;
            မဟုတ်ပါက အကယ်၍ (t >= 'a')
                t = t - 'a' + 10;
            မဟုတ်ပါက အကယ်၍ (t >= 'A')
                t = t - 'A' + 10;
            မဟုတ်ပါက
                t = t - '0';
            အကယ်၍ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            အကယ်၍ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        အတွက်(;;) {
            t = toup(ch);
            အကယ်၍ (t == 'L') {
                အကယ်၍ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                အကယ်၍ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } မဟုတ်ပါက အကယ်၍ (t == 'U') {
                အကယ်၍ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } မဟုတ်ပါက {
                bha_nga;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        အကယ်၍ (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        အကယ်၍ (ucount == 0 && b == 10) {
            အကယ်၍ (lcount <= (LONG_SIZE == 4)) {
                အကယ်၍ (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            အကယ်၍ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } မဟုတ်ပါက {
            အကယ်၍ (lcount <= (LONG_SIZE == 4)) {
                အကယ်၍ (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                မဟုတ်ပါက အကယ်၍ (n >= 0x80000000U)
                    ucount = 1;
            }
            အကယ်၍ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        အကယ်၍ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	အကယ်၍ (lcount) {
            tok = TOK_CLONG;
            အကယ်၍ (lcount == 2)
                tok = TOK_CLLONG;
	}
	အကယ်၍ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    အကယ်၍ (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    pak_sa c1:                                    \
        PEEKC(c, p);                            \
        အကယ်၍ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } မဟုတ်ပါက {                                \
            tok = tok1;                         \
        }                                       \
        bha_nga;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    ကိန်းပြည့် t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned ကိန်းပြည့် h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    pak_sa ' ':
    pak_sa '\t':
        tok = c;
        p++;
 maybe_space:
        အကယ်၍ (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        နေစဉ် (isidnum_table[*p - CH_EOF] & IS_SPC)
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
        အကယ်၍ (c == '\\')
            goto parse_simple;
        အကယ်၍ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            အကယ်၍ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } မဟုတ်ပါက အကယ်၍ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } မဟုတ်ပါက အကယ်၍ (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } မဟုတ်ပါက အကယ်၍ (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } မဟုတ်ပါက {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                အကယ်၍ (tok_flags & TOK_FLAG_ENDIF) {
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
        } မဟုတ်ပါက {
            goto redo_no_start;
        }
        bha_nga;

    pak_sa '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        အကယ်၍ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    pak_sa '#':
        /* XXX: simplify */
        PEEKC(c, p);
        အကယ်၍ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } မဟုတ်ပါက {
            အကယ်၍ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } မဟုတ်ပါက {
#အကယ်၍ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } မဟုတ်ပါက
#endif
                {
                    tok = '#';
                }
            }
        }
        bha_nga;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    pak_sa '$':
        အကယ်၍ (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        နေစဉ် (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        အကယ်၍ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            အတွက်(;;) {
                ts = *pts;
                အကယ်၍ (!ts)
                    bha_nga;
                အကယ်၍ (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (var_na *) p1, len);
        token_found: ;
        } မဟုတ်ပါက {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (var_na *) p1, len);
            p--;
            PEEKC(c, p);
            နေစဉ် (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        အကယ်၍ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            အကယ်၍ (c == '\'' || c == '\"') {
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
        အတွက်(;;) {
            cstr_ccat(&tokcstr, t);
            အကယ်၍ (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        အကယ်၍ (isnum(c)) {
            t = '.';
            goto parse_num;
        } မဟုတ်ပါက အကယ်၍ ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } မဟုတ်ပါက အကယ်၍ (c == '.') {
            PEEKC(c, p);
            အကယ်၍ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } မဟုတ်ပါက {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } မဟုတ်ပါက {
            tok = '.';
        }
        bha_nga;
    pak_sa '\'':
    pak_sa '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        အကယ်၍ (is_long)
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
        အကယ်၍ (c == '=') {
            p++;
            tok = TOK_LE;
        } မဟုတ်ပါက အကယ်၍ (c == '<') {
            PEEKC(c, p);
            အကယ်၍ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } မဟုတ်ပါက {
                tok = TOK_SHL;
            }
        } မဟုတ်ပါက {
            tok = TOK_LT;
        }
        bha_nga;
    pak_sa '>':
        PEEKC(c, p);
        အကယ်၍ (c == '=') {
            p++;
            tok = TOK_GE;
        } မဟုတ်ပါက အကယ်၍ (c == '>') {
            PEEKC(c, p);
            အကယ်၍ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } မဟုတ်ပါက {
                tok = TOK_SAR;
            }
        } မဟုတ်ပါက {
            tok = TOK_GT;
        }
        bha_nga;
        
    pak_sa '&':
        PEEKC(c, p);
        အကယ်၍ (c == '&') {
            p++;
            tok = TOK_LAND;
        } မဟုတ်ပါက အကယ်၍ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } မဟုတ်ပါက {
            tok = '&';
        }
        bha_nga;
        
    pak_sa '|':
        PEEKC(c, p);
        အကယ်၍ (c == '|') {
            p++;
            tok = TOK_LOR;
        } မဟုတ်ပါက အကယ်၍ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } မဟုတ်ပါက {
            tok = '|';
        }
        bha_nga;

    pak_sa '+':
        PEEKC(c, p);
        အကယ်၍ (c == '+') {
            p++;
            tok = TOK_INC;
        } မဟုတ်ပါက အကယ်၍ (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } မဟုတ်ပါက {
            tok = '+';
        }
        bha_nga;
        
    pak_sa '-':
        PEEKC(c, p);
        အကယ်၍ (c == '-') {
            p++;
            tok = TOK_DEC;
        } မဟုတ်ပါက အကယ်၍ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } မဟုတ်ပါက အကယ်၍ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } မဟုတ်ပါက {
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
        အကယ်၍ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } မဟုတ်ပါက အကယ်၍ (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } မဟုတ်ပါက အကယ်၍ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } မဟုတ်ပါက {
            tok = '/';
        }
        bha_nga;
        
        /* simple tokens */
    pak_sa '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE) {
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
        အကယ်၍ (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        အကယ်၍ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        အကယ်၍ (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        bha_nga;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#အကယ်၍ defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static ကိန်းပြည့် indent;
static void define_print(TCCState *s1, ကိန်းပြည့် v);
static void pp_print(const var_na *msg, ကိန်းပြည့် v, const ကိန်းပြည့် *str)
{
    FILE *fp = tcc_state->ppfp;

    အကယ်၍ (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    မဟုတ်ပါက အကယ်၍ (msg[0] == '+')
         ++indent, ++msg;
    မဟုတ်ပါက အကယ်၍ (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    အကယ်၍ (msg[0] == '#') {
        define_print(tcc_state, v);
    } မဟုတ်ပါက {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#မဟုတ်ပါက
#define PP_PRINT(x)
#endif

static ကိန်းပြည့် macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ကိန်းပြည့် *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static ကိန်းပြည့် *macro_arg_subst(Sym **nested_list, const ကိန်းပြည့် *macro_str, Sym *args)
{
    ကိန်းပြည့် t, t0, t1, t2, n;
    const ကိန်းပြည့် *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    အတွက် (s = args, n = 0; s; s = s->prev, ++n);
    နေစဉ် (n--) {
        အတွက် (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    နေစဉ်(1) {
        TOK_GET(&t, &macro_str, &cval);
        အကယ်၍ (!t)
            bha_nga;
        အကယ်၍ (t == '#') {
            /* stringize */
            do t = *macro_str++; နေစဉ် (t == ' ');
            s = sym_find2(args, t);
            အကယ်၍ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                နေစဉ် (*st != TOK_EOF) {
                    const var_na *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    နေစဉ် (*s) {
                        အကယ်၍ (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        မဟုတ်ပါက
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
            } မဟုတ်ပါက အကယ်၍ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } မဟုတ်ပါက {
                expect("macro parameter after '#'");
            }
        } မဟုတ်ပါက အကယ်၍ (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            အကယ်၍ (s) {
                st = s->d;
                n = 0;
                နေစဉ် ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                အကယ်၍ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    အကယ်၍ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ကိန်းပြည့် c = str.str[str.len - 1];
                        နေစဉ် (str.str[--str.len] != ',')
                            ;
                        အကယ်၍ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } မဟုတ်ပါက {
                            /* suppress '##' and add variable */
                            str.len++;
                            အကယ်၍ (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } မဟုတ်ပါက {
                        အကယ်၍ (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } မဟုတ်ပါက {
            add_var:
		    အကယ်၍ (!s->e) {
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
                နေစဉ် (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } မဟုတ်ပါက {
                tok_str_add(&str, t);
            }
        } မဟုတ်ပါက {
            tok_str_add2(&str, t, &cval);
        }
        အကယ်၍ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ပြန်ပေး str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static anta_hstha ကိန်းပြည့် *macro_twosharps(const ကိန်းပြည့် *ptr0)
{
    ကိန်းပြည့် t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const ကိန်းပြည့် *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    အတွက် (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        အကယ်၍ (t1 == 0)
            bha_nga;
        အတွက် (;;) {
            n = 0;
            နေစဉ် ((t2 = ptr[n]) == ' ')
                ++n;
            အကယ်၍ (t2 != TOK_PPJOIN)
                bha_nga;
            ptr += n;
            နေစဉ် ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            အကယ်၍ (t2 == TOK_PLCHLDR)
                continue;
            အကယ်၍ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        အကယ်၍ (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            အတွက် (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                အကယ်၍ (*file->buf_ptr == 0)
                    bha_nga;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        အကယ်၍ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ပြန်ပေး macro_str1.str;
}

static ကိန်းပြည့် peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ကိန်းပြည့် c;
    အတွက် (;;) {
        PEEKC(c, p);
        switch (c) {
        pak_sa '/':
            PEEKC(c, p);
            အကယ်၍ (c == '*')
                p = parse_comment(p);
            မဟုတ်ပါက အကယ်၍ (c == '/')
                p = parse_line_comment(p);
            မဟုတ်ပါက {
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
            ပြန်ပေး c;
        }
        အကယ်၍ (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static ကိန်းပြည့် next_argstream(Sym **nested_list, TokenString *ws_str)
{
    ကိန်းပြည့် t;
    Sym *sa;

    နေစဉ် (macro_ptr) {
        const ကိန်းပြည့် *m = macro_ptr;
        နေစဉ် ((t = *m) != 0) {
            အကယ်၍ (ws_str) {
                အကယ်၍ (t != ' ')
                    ပြန်ပေး t;
                ++m;
            } မဟုတ်ပါက {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ပြန်ပေး tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        အကယ်၍ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    အကယ်၍ (ws_str) {
        ပြန်ပေး peek_file(ws_str);
    } မဟုတ်ပါက {
        next_nomacro();
        အကယ်၍ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ပြန်ပေး tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static ကိန်းပြည့် macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ကိန်းပြည့် t;
    ကိန်းပြည့် v = s->v;

    PP_PRINT(("#", v, s->d));
    အကယ်၍ (s->d) {
        ကိန်းပြည့် *mstr = s->d;
        ကိန်းပြည့် *jstr;
        Sym *sa;
        ကိန်းပြည့် ret;

        အကယ်၍ (s->type.t & MACRO_FUNC) {
            ကိန်းပြည့် saved_parse_flags = parse_flags;
            TokenString str;
            ကိန်းပြည့် parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            အကယ်၍ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                အကယ်၍ (parse_flags & PARSE_FLAG_SPACES)
                    အတွက် (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ပြန်ပေး 0;
            } မဟုတ်ပါက {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            အတွက်(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } နေစဉ် (t == ' ' || --i);

                အကယ်၍ (!sa) {
                    အကယ်၍ (t == ')') /* handle '()' case */
                        bha_nga;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                နေစဉ် (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    အကယ်၍ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    အကယ်၍ (t == '(')
                        parlevel++;
                    အကယ်၍ (t == ')')
                        parlevel--;
                    အကယ်၍ (t == ' ')
                        str.need_spc |= 1;
                    မဟုတ်ပါက
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                အကယ်၍ (t == ')') {
                    အကယ်၍ (!sa)
                        bha_nga;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    အကယ်၍ (sa->type.t && gnu_ext)
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
            နေစဉ် (sa) {
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
        အကယ်၍ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        အကယ်၍ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        အကယ်၍ (jstr != mstr)
            tok_str_free_str(jstr);
        အကယ်၍ (mstr != s->d)
            tok_str_free_str(mstr);
        ပြန်ပေး ret;

    } မဟုတ်ပါက {
        CValue cval;
        var_na buf[32], *cstrval = buf;

        /* special macros */
        အကယ်၍ (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, parimaa_na(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } မဟုတ်ပါက အကယ်၍ (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } မဟုတ်ပါက အကယ်၍ (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            sa_nracanaa tm *tm;
            time(&ti);
            tm = localtime(&ti);
            အကယ်၍ (v == TOK___DATE__) {
                static var_na const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, parimaa_na(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } မဟုတ်ပါက {
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
        ပြန်ပေး 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static ကိန်းပြည့် macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ကိန်းပြည့် *macro_str
    )
{
    Sym *s;
    ကိန်းပြည့် t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    ကိန်းပြည့် tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    နေစဉ် (1) {
        TOK_GET(&t, &macro_str, &cval);
        အကယ်၍ (t == 0 || t == TOK_EOF)
            bha_nga;
        အကယ်၍ (t >= TOK_IDENT) {
            s = define_find(t);
            အကယ်၍ (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            အကယ်၍ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (ကိန်းပြည့်*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            အကယ်၍ (macro_stack != str) {
                /* already finished by reading function macro arguments */
                bha_nga;
            }
            macro_str = macro_ptr;
            end_macro ();
        } မဟုတ်ပါက အကယ်၍ (t == ' ') {
            အကယ်၍ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } မဟုတ်ပါက {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            အကယ်၍ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            အကယ်၍ (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ပြန်ပေး nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    ကိန်းပြည့် t;
    နေစဉ် (macro_ptr) {
redo:
        t = *macro_ptr;
        အကယ်၍ (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            အကယ်၍ (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } မဟုတ်ပါက အကယ်၍ (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } မဟုတ်ပါက အကယ်၍ (t == TOK_EOF) {
            /* do nothing */
        } မဟုတ်ပါက {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            အကယ်၍ (t == '\\') {
                အကယ်၍ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ပြန်ပေး;
    }

    next_nomacro();
    t = tok;
    အကယ်၍ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        အကယ်၍ (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        ပြန်ပေး;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    အကယ်၍ (t == TOK_PPNUM) {
        အကယ်၍  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } မဟုတ်ပါက အကယ်၍ (t == TOK_PPSTR) {
        အကယ်၍ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(ကိန်းပြည့် last_tok)
{
    TokenString *str = &unget_buf;
    ကိန်းပြည့် alloc = 0;
    အကယ်၍ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    အကယ်၍ (tok != TOK_EOF)
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
# အကယ်၍ PTR_SIZE == 8
    "_WIN64\0"
# endif
#မဟုတ်ပါက
# အကယ်၍ defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# မဟုတ်ပါက
    "__linux__\0"
    "__linux\0"
#  အကယ်၍ TARGETOS_ANDROID
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
    နေစဉ် (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, ကိန်းပြည့် is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    အကယ်၍ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    အကယ်၍ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    အကယ်၍ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    အကယ်၍ (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    အကယ်၍ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    အကယ်၍ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    အကယ်၍ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    အကယ်၍ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    အကယ်၍ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    အကယ်၍ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    အကယ်၍ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#အကယ်၍ CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#မဟုတ်ပါက
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, ကိန်းပြည့် filetype)
{
    ကိန်းပြည့် is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

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

    အကယ်၍ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        အကယ်၍ (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        အကယ်၍ (s1->cmdline_incl.size)
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
    နေစဉ် (macro_stack)
        end_macro();
    macro_ptr = NULL;
    နေစဉ် (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ကိန်းပြည့် set_idnum(ကိန်းပြည့် c, ကိန်းပြည့် val)
{
    ကိန်းပြည့် prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ပြန်ပေး prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    ကိန်းပြည့် i, c;
    const var_na *p, *r;

    /* init isid table */
    အတွက်(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    အတွက်(i = 128; i<256; i++)
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
    နေစဉ် (*p) {
        r = p;
        အတွက်(;;) {
            c = *r++;
            အကယ်၍ (c == '\0')
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
    ကိန်းပြည့် i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    အကယ်၍ (n > total_idents)
        total_idents = n;
    အတွက် (i = n; --i >= 0;)
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

static ကိန်းပြည့် pp_need_space(ကိန်းပြည့် a, ကိန်းပြည့် b);

static void tok_print(const ကိန်းပြည့် *str, const var_na *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ကိန်းပြည့် t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    နေစဉ် (str) {
	TOK_GET(&t, &str, &cval);
	အကယ်၍ (t == 0 || t == TOK_EOF)
	    bha_nga;
        အကယ်၍ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, ကိန်းပြည့် level)
{
    ကိန်းပြည့် d = f->line_num - f->line_ref;

    အကယ်၍ (s1->dflag & 4)
	ပြန်ပေး;

    အကယ်၍ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } မဟုတ်ပါက အကယ်၍ (level == 0 && f->line_ref && d < 8) {
	နေစဉ် (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } မဟုတ်ပါက အကယ်၍ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } မဟုတ်ပါက {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, ကိန်းပြည့် v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    အကယ်၍ (NULL == s || NULL == s->d)
        ပြန်ပေး;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    အကယ်၍ (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        အကယ်၍ (a)
            အတွက် (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                အကယ်၍ (!(a = a->next))
                    bha_nga;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    ကိန်းပြည့် v, t;
    const var_na *vs;
    FILE *fp;

    t = pp_debug_tok;
    အကယ်၍ (t == 0)
        ပြန်ပေး;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    အကယ်၍ (t == TOK_DEFINE) {
        define_print(s1, v);
    } မဟုတ်ပါက အကယ်၍ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } မဟုတ်ပါက အကယ်၍ (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } မဟုတ်ပါက အကယ်၍ (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static ကိန်းပြည့် pp_need_space(ကိန်းပြည့် a, ကိန်းပြည့် b)
{
    ပြန်ပေး 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static ကိန်းပြည့် pp_check_he0xE(ကိန်းပြည့် t, const var_na *p)
{
    အကယ်၍ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ပြန်ပေး 'E';
    ပြန်ပေး t;
}

/* Preprocess the current file */
ST_FUNC ကိန်းပြည့် tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ကိန်းပြည့် token_seen, spcs, level;
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
    အကယ်၍ (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    အကယ်၍ (s1->do_bench) {
	/* for PP benchmarks */
	do next(); နေစဉ် (tok != TOK_EOF);
	ပြန်ပေး 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    အကယ်၍ (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    အတွက် (;;) {
        iptr = s1->include_stack_ptr;
        next();
        အကယ်၍ (tok == TOK_EOF)
            bha_nga;

        level = s1->include_stack_ptr - iptr;
        အကယ်၍ (level) {
            အကယ်၍ (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        အကယ်၍ (s1->dflag & 7) {
            pp_debug_defines(s1);
            အကယ်၍ (s1->dflag & 4)
                continue;
        }

        အကယ်၍ (is_space(tok)) {
            အကယ်၍ (spcs < parimaa_na white - 1)
                white[spcs++] = tok;
            continue;
        } မဟုတ်ပါက အကယ်၍ (tok == TOK_LINEFEED) {
            spcs = 0;
            အကယ်၍ (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } မဟုတ်ပါက အကယ်၍ (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } မဟုတ်ပါက အကယ်၍ (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ပြန်ပေး 0;
}

/* ------------------------------------------------------------------------- */
