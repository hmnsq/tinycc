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

ST_DATA ཧྲིལ tok_flags;
ST_DATA ཧྲིལ parse_flags;

ST_DATA sa_nracanaa BufferedFile *file;
ST_DATA ཧྲིལ tok;
ST_DATA CValue tokc;
ST_DATA const ཧྲིལ *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ཧྲིལ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ཧྲིལ pp_expr;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static var_na token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static TokenString unget_buf;
static unsigned var_na isidnum_table[256 - CH_EOF];
static ཧྲིལ pp_debug_tok, pp_debug_symv;
static ཧྲིལ pp_counter;
static void tok_print(const ཧྲིལ *str, const var_na *msg, ...);
static void next_nomacro(void);
static void parse_number(const var_na *p);
static void parse_string(const var_na *p, ཧྲིལ len);

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

ST_FUNC void skip(ཧྲིལ c)
{
    གལ་སྲིད (tok != c) {
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
#དེ་མིན
#གལ་སྲིད !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#དེ་མིན
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , const var_na *sfile, ཧྲིལ sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

typedef sa_nracanaa TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    sa_nracanaa TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#གལ་སྲིད TAL_INFO
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
#གལ་སྲིད TAL_DEBUG
    ཧྲིལ     line_num; /* negative line_num used for double free check */
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
#གལ་སྲིད TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ལོག al;
}

static void tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#གལ་སྲིད TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#གལ་སྲིད TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#གལ་སྲིད TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    གལ་སྲིད (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        སྐབས (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            གལ་སྲིད (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (ཧྲིལ)header->size);
            }
            p += header->size + parimaa_na(tal_header_t);
        }
#གལ་སྲིད TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    གལ་སྲིད (al)
        goto tail_call;
    *pal = al;
}

static void tal_free_impl(TinyAlloc **pal, void *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    གལ་སྲིད (!p)
        ལོག;
    header = (tal_header_t *)p - 1;
#གལ་སྲིད TAL_DEBUG
    གལ་སྲིད (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (ཧྲིལ)-header->line_num, (ཧྲིལ)header->size);
    } དེ་མིན
        header->line_num = -header->line_num;
#endif
    al = *pal;
    སྐབས ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    གལ་སྲིད (0 == --al->nb_allocs) {
        *pal = al->next;
        གལ་སྲིད ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } དེ་མིན {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } དེ་མིན གལ་སྲིད ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    void *ret;
    unsigned adj_size = TAL_ALIGN(size) + parimaa_na(tal_header_t);
    TinyAlloc *al = *pal;

    གལ་སྲིད (p) {
        /* reallpc case */
        སྐབས ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        གལ་སྲིད ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        གལ་སྲིད (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ལོག ret;
        } དེ་མིན གལ་སྲིད (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#གལ་སྲིད TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } དེ་མིན {
        /* new alloc case */
        སྐབས (al->p + adj_size > al->bufend) {
            al = al->next;
            གལ་སྲིད (!al) {
                unsigned new_size = (*pal)->size;
                གལ་སྲིད (adj_size > new_size) {
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
#གལ་སྲིད  TAL_DEBUG
    {
        ཧྲིལ ofs = strlen(sfile) + 1 - parimaa_na header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#གལ་སྲིད TAL_INFO
        གལ་སྲིད (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        གལ་སྲིད (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ལོག ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
static void cstr_realloc(CString *cstr, ཧྲིལ new_size)
{
    ཧྲིལ size;

    size = cstr->size_allocated;
    གལ་སྲིད (size < 8)
        size = 8; /* no need to allocate a too small first string */
    སྐབས (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN void cstr_ccat(CString *cstr, ཧྲིལ ch)
{
    ཧྲིལ size;
    size = cstr->size + 1;
    གལ་སྲིད (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN var_na *unicode_to_utf8 (var_na *b, uint32_t Uc)
{
    གལ་སྲིད (Uc<0x80) *b++=Uc;
    དེ་མིན གལ་སྲིད (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    དེ་མིན གལ་སྲིད (Uc-0xd800u<0x800) goto error;
    དེ་མིན གལ་སྲིད (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    དེ་མིན གལ་སྲིད (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    དེ་མིན error: tcc_error("0x%x is not a valid universal character", Uc);
    ལོག b;
}

/* add a unicode character expanded into utf8 */
ST_INLN void cstr_u8cat(CString *cstr, ཧྲིལ ch)
{
    var_na buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC void cstr_cat(CString *cstr, const var_na *str, ཧྲིལ len)
{
    ཧྲིལ size;
    གལ་སྲིད (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    གལ་སྲིད (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC void cstr_wccat(CString *cstr, ཧྲིལ ch)
{
    ཧྲིལ size;
    size = cstr->size + parimaa_na(nwchar_t);
    གལ་སྲིད (size > cstr->size_allocated)
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

ST_FUNC ཧྲིལ cstr_vprintf(CString *cstr, const var_na *fmt, va_list ap)
{
    va_list v;
    ཧྲིལ len, size = 80;
    དོན་ལུ (;;) {
        size += cstr->size;
        གལ་སྲིད (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        གལ་སྲིད (len >= 0 && len < size)
            bha_nga;
        size *= 2;
    }
    cstr->size += len;
    ལོག len;
}

ST_FUNC ཧྲིལ cstr_printf(CString *cstr, const var_na *fmt, ...)
{
    va_list ap; ཧྲིལ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ལོག len;
}

/* XXX: unicode ? */
static void add_char(CString *cstr, ཧྲིལ c)
{
    གལ་སྲིད (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    གལ་སྲིད (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } དེ་མིན {
        cstr_ccat(cstr, '\\');
        གལ་སྲིད (c == '\n') {
            cstr_ccat(cstr, 'n');
        } དེ་མིན {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
static TokenSym *tok_alloc_new(TokenSym **pts, const var_na *str, ཧྲིལ len)
{
    TokenSym *ts, **ptable;
    ཧྲིལ i;

    གལ་སྲིད (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    གལ་སྲིད ((i % TOK_ALLOC_INCR) == 0) {
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
    ལོག ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(const var_na *str, ཧྲིལ len)
{
    TokenSym *ts, **pts;
    ཧྲིལ i;
    unsigned ཧྲིལ h;
    
    h = TOK_HASH_INIT;
    དོན་ལུ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned var_na *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    དོན་ལུ(;;) {
        ts = *pts;
        གལ་སྲིད (!ts)
            bha_nga;
        གལ་སྲིད (ts->len == len && !memcmp(ts->str, str, len))
            ལོག ts;
        pts = &(ts->hash_next);
    }
    ལོག tok_alloc_new(pts, str, len);
}

ST_FUNC ཧྲིལ tok_alloc_const(const var_na *str)
{
    ལོག tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC const var_na *get_tok_str(ཧྲིལ v, CValue *cv)
{
    var_na *p;
    ཧྲིལ i, len;

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
        ལོག (var_na*)cv->str.data;
    pak_sa TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    pak_sa TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        གལ་སྲིད (v == TOK_STR) {
            len = cv->str.size - 1;
            དོན་ལུ(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned var_na *)cv->str.data)[i]);
        } དེ་མིན {
            len = (cv->str.size / parimaa_na(nwchar_t)) - 1;
            དོན་ལུ(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        bha_nga;

    pak_sa TOK_CFLOAT:
        ལོག strcpy(p, "<float>");
    pak_sa TOK_CDOUBLE:
        ལོག strcpy(p, "<double>");
    pak_sa TOK_CLDOUBLE:
        ལོག strcpy(p, "<long double>");
    pak_sa TOK_LINENUM:
        ལོག strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    pak_sa TOK_LT:
        v = '<';
        goto addv;
    pak_sa TOK_GT:
        v = '>';
        goto addv;
    pak_sa TOK_DOTS:
        ལོག strcpy(p, "...");
    pak_sa TOK_A_SHL:
        ལོག strcpy(p, "<<=");
    pak_sa TOK_A_SAR:
        ལོག strcpy(p, ">>=");
    pak_sa TOK_EOF:
        ལོག strcpy(p, "<eof>");
    pak_sa 0: /* anonymous nameless symbols */
        ལོག strcpy(p, "<no name>");
    default:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        གལ་སྲིད (v < TOK_IDENT) {
            /* search in two bytes table */
            const unsigned var_na *q = tok_two_chars;
            སྐབས (*q) {
                གལ་སྲིད (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ལོག cstr_buf.data;
                }
                q += 3;
            }
            གལ་སྲིད (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                bha_nga;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } དེ་མིན གལ་སྲིད (v < tok_ident) {
            ལོག table_ident[v - TOK_IDENT]->str;
        } དེ་མིན གལ་སྲིད (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } དེ་མིན {
            /* should never happen */
            ལོག NULL;
        }
        bha_nga;
    }
    ལོག cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
static ཧྲིལ handle_eob(void)
{
    BufferedFile *bf = file;
    ཧྲིལ len;

    /* only tries to read if really end of buffer */
    གལ་སྲིད (bf->buf_ptr >= bf->buf_end) {
        གལ་སྲིད (bf->fd >= 0) {
#གལ་སྲིད defined(PARSE_DEBUG)
            len = 1;
#དེ་མིན
            len = IO_BUF_SIZE;
#endif
            len = read(bf->fd, bf->buffer, len);
            གལ་སྲིད (len < 0)
                len = 0;
        } དེ་མིན {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    གལ་སྲིད (bf->buf_ptr < bf->buf_end) {
        ལོག bf->buf_ptr[0];
    } དེ་མིན {
        bf->buf_ptr = bf->buf_end;
        ལོག CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
static ཧྲིལ next_c(void)
{
    ཧྲིལ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    གལ་སྲིད (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ལོག ch;
}

/* input with '\[\r]\n' handling. */
static ཧྲིལ handle_stray_noerror(ཧྲིལ err)
{
    ཧྲིལ ch;
    སྐབས ((ch = next_c()) == '\\') {
        ch = next_c();
        གལ་སྲིད (ch == '\n') {
    newl:
            file->line_num++;
        } དེ་མིན {
            གལ་སྲིད (ch == '\r') {
                ch = next_c();
                གལ་སྲིད (ch == '\n')
                    goto newl;
                *--file->buf_ptr = '\r';
            }
            གལ་སྲིད (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ལོག *--file->buf_ptr = '\\';
        }
    }
    ལོག ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
static ཧྲིལ handle_bs(uint8_t **p)
{
    ཧྲིལ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ལོག c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
static ཧྲིལ handle_stray(uint8_t **p)
{
    ཧྲིལ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ལོག c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    གལ་སྲིད (c == '\\')\
        c = handle_stray(&p); \
}

static ཧྲིལ skip_spaces(void)
{
    ཧྲིལ ch;
    --file->buf_ptr;
    do {
        ch = ninp();
    } སྐབས (isidnum_table[ch - CH_EOF] & IS_SPC);
    ལོག ch;
}

/* single line C++ comments */
static uint8_t *parse_line_comment(uint8_t *p)
{
    ཧྲིལ c;
    དོན་ལུ(;;) {
        དོན་ལུ (;;) {
            c = *++p;
    redo:
            གལ་སྲིད (c == '\n' || c == '\\')
                bha_nga;
            c = *++p;
            གལ་སྲིད (c == '\n' || c == '\\')
                bha_nga;
        }
        གལ་སྲིད (c == '\n')
            bha_nga;
        c = handle_bs(&p);
        གལ་སྲིད (c == CH_EOF)
            bha_nga;
        གལ་སྲིད (c != '\\')
            goto redo;
    }
    ལོག p;
}

/* C comments */
static uint8_t *parse_comment(uint8_t *p)
{
    ཧྲིལ c;
    དོན་ལུ(;;) {
        /* fast skip loop */
        དོན་ལུ(;;) {
            c = *++p;
        redo:
            གལ་སྲིད (c == '\n' || c == '*' || c == '\\')
                bha_nga;
            c = *++p;
            གལ་སྲིད (c == '\n' || c == '*' || c == '\\')
                bha_nga;
        }
        /* now we can handle all the cases */
        གལ་སྲིད (c == '\n') {
            file->line_num++;
        } དེ་མིན གལ་སྲིད (c == '*') {
            do {
                c = *++p;
            } སྐབས (c == '*');
            གལ་སྲིད (c == '\\')
                c = handle_bs(&p);
            གལ་སྲིད (c == '/')
                bha_nga;
            goto check_eof;
        } དེ་མིན {
            c = handle_bs(&p);
        check_eof:
            གལ་སྲིད (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            གལ་སྲིད (c != '\\')
                goto redo;
        }
    }
    ལོག p + 1;
}

/* parse a string without interpreting escapes */
static uint8_t *parse_pp_string(uint8_t *p, ཧྲིལ sep, CString *str)
{
    ཧྲིལ c;
    དོན་ལུ(;;) {
        c = *++p;
    redo:
        གལ་སྲིད (c == sep) {
            bha_nga;
        } དེ་མིན གལ་སྲིད (c == '\\') {
            c = handle_bs(&p);
            གལ་སྲིད (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } དེ་མིན གལ་སྲིད (c == '\\') {
                གལ་སྲིད (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                གལ་སྲིད (c == '\\') {
                    c = handle_bs(&p);
                    གལ་སྲིད (c == CH_EOF)
                        goto unterminated_string;
                }
                goto add_char;
            } དེ་མིན {
                goto redo;
            }
        } དེ་མིན གལ་སྲིད (c == '\n') {
        add_lf:
            གལ་སྲིད (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                goto add_char;
            } དེ་མིན གལ་སྲིད (str) { /* not skipping */
                goto unterminated_string;
            } དེ་མིན {
                //tcc_warning("missing terminating %c character", sep);
                ལོག p;
            }
        } དེ་མིན གལ་སྲིད (c == '\r') {
            c = *++p;
            གལ་སྲིད (c == '\\')
                c = handle_bs(&p);
            གལ་སྲིད (c == '\n')
                goto add_lf;
            གལ་སྲིད (c == CH_EOF)
                goto unterminated_string;
            གལ་སྲིད (str)
                cstr_ccat(str, '\r');
            goto redo;
        } དེ་མིན {
        add_char:
            གལ་སྲིད (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ལོག p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
static void preprocess_skip(void)
{
    ཧྲིལ a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    དོན་ལུ(;;) {
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
            གལ་སྲིད (c == CH_EOF)
                expect("#endif");
            གལ་སྲིད (c == '\\')
                ++p;
            continue;
        /* skip strings */
        pak_sa '\"':
        pak_sa '\'':
            གལ་སྲིད (in_warn_or_error)
                goto _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, NULL);
            bha_nga;
        /* skip comments */
        pak_sa '/':
            གལ་སྲིད (in_warn_or_error)
                goto _default;
            ++p;
            c = handle_bs(&p);
            གལ་སྲིད (c == '*') {
                p = parse_comment(p);
            } དེ་མིན གལ་སྲིད (c == '/') {
                p = parse_line_comment(p);
            }
            continue;
        pak_sa '#':
            p++;
            གལ་སྲིད (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                གལ་སྲིད (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    goto the_end;
                གལ་སྲིད (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                དེ་མིན གལ་སྲིད (tok == TOK_ENDIF)
                    a--;
                དེ་མིན གལ་སྲིད( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                དེ་མིན གལ་སྲིད (tok == TOK_LINEFEED)
                    goto redo_start;
                དེ་མིན གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#གལ་སྲིད !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            དེ་མིན གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#དེ་མིན
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

#གལ་སྲིད 0
/* return the number of additional 'ints' necessary to store the
   token */
static anta_hstha ཧྲིལ tok_size(const ཧྲིལ *p)
{
    switch(*p) {
        /* 4 bytes */
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
        ལོག 1 + 1;
    pak_sa TOK_STR:
    pak_sa TOK_LSTR:
    pak_sa TOK_PPNUM:
    pak_sa TOK_PPSTR:
        ལོག 1 + 1 + (p[1] + 3) / 4;
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
	ལོག 1 + LONG_SIZE / 4;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
        ལོག 1 + 2;
    pak_sa TOK_CLDOUBLE:
        ལོག 1 + LDOUBLE_WORDS;
    default:
        ལོག 1 + 0;
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
    ལོག str;
}

ST_FUNC void tok_str_free_str(ཧྲིལ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ཧྲིལ *tok_str_realloc(TokenString *s, ཧྲིལ new_size)
{
    ཧྲིལ *str, size;

    size = s->allocated_len;
    གལ་སྲིད (size < 16)
        size = 16;
    སྐབས (size < new_size)
        size = size * 2;
    གལ་སྲིད (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * parimaa_na(ཧྲིལ));
        s->allocated_len = size;
        s->str = str;
    }
    ལོག s->str;
}

ST_FUNC void tok_str_add(TokenString *s, ཧྲིལ t)
{
    ཧྲིལ len, *str;

    len = s->len;
    str = s->str;
    གལ་སྲིད (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC void begin_macro(TokenString *str, ཧྲིལ alloc)
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
    གལ་སྲིད (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } དེ་མིན {
        གལ་སྲིད (str->alloc == 2)
            str->str = NULL; /* don't free */
        tok_str_free(str);
    }
}

static void tok_str_add2(TokenString *s, ཧྲིལ t, CValue *cv)
{
    ཧྲིལ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    གལ་སྲིད (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    switch(t) {
    pak_sa TOK_CINT:
    pak_sa TOK_CUINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_CFLOAT:
    pak_sa TOK_LINENUM:
#གལ་སྲིད LONG_SIZE == 4
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
                1 + (cv->str.size + parimaa_na(ཧྲིལ) - 1) / parimaa_na(ཧྲིལ);
            གལ་སྲིད (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#གལ་སྲིད LONG_SIZE == 8
    pak_sa TOK_CLONG:
    pak_sa TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        bha_nga;
    pak_sa TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        གལ་སྲིད (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        གལ་སྲིད (LDOUBLE_WORDS >= 4)
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
    གལ་སྲིད (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
static void tok_str_add2_spc(TokenString *s, ཧྲིལ t, CValue *cv)
{
    གལ་སྲིད (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
static anta_hstha void tok_get(ཧྲིལ *t, const ཧྲིལ **pp, CValue *cv)
{
    const ཧྲིལ *p = *pp;
    ཧྲིལ n, *tab;

    tab = cv->tab;
    switch(*t = *p++) {
#གལ་སྲིད LONG_SIZE == 4
    pak_sa TOK_CLONG:
#endif
    pak_sa TOK_CINT:
    pak_sa TOK_CCHAR:
    pak_sa TOK_LCHAR:
    pak_sa TOK_LINENUM:
        cv->i = *p++;
        bha_nga;
#གལ་སྲིད LONG_SIZE == 4
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
        p += (cv->str.size + parimaa_na(ཧྲིལ) - 1) / parimaa_na(ཧྲིལ);
        bha_nga;
    pak_sa TOK_CDOUBLE:
    pak_sa TOK_CLLONG:
    pak_sa TOK_CULLONG:
#གལ་སྲིད LONG_SIZE == 8
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
        སྐབས (--n);
        bha_nga;
    default:
        bha_nga;
    }
    *pp = p;
}

#གལ་སྲིད 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#དེ་མིན
# define TOK_GET(t,p,c) do { \
    ཧྲིལ _t = **(p); \
    གལ་སྲིད (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    དེ་མིན \
        *(t) = _t, ++*(p); \
    } སྐབས (0)
#endif

static ཧྲིལ macro_is_equal(const ཧྲིལ *a, const ཧྲིལ *b)
{
    CValue cv;
    ཧྲིལ t;

    གལ་སྲིད (!a || !b)
        ལོག 1;

    སྐབས (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        གལ་སྲིད (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ལོག 0;
    }
    ལོག !(*a || *b);
}

/* defines handling */
ST_INLN void define_push(ཧྲིལ v, ཧྲིལ macro_type, ཧྲིལ *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    གལ་སྲིད (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, NULL));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC void define_undef(Sym *s)
{
    ཧྲིལ v = s->v;
    གལ་སྲིད (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = NULL;
}

ST_INLN Sym *define_find(ཧྲིལ v)
{
    v -= TOK_IDENT;
    གལ་སྲིད ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ལོག NULL;
    ལོག table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC void free_defines(Sym *b)
{
    སྐབས (define_stack != b) {
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
    གལ་སྲིད (s->include_stack_ptr != s->include_stack)
        ལོག;
    p = get_tok_str(tok, NULL);
    གལ་སྲིད (0 != memcmp(p, "test_", 5))
        ལོག;
    གལ་སྲིད (0 != --s->run_test)
        ལོག;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, NULL, NULL);
}

ST_FUNC void skip_to_eol(ཧྲིལ warn)
{
    གལ་སྲིད (tok == TOK_LINEFEED)
        ལོག;
    གལ་སྲིད (warn)
        tcc_warning("extra tokens after directive");
    སྐབས (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

static CachedInclude *
search_cached_include(TCCState *s1, const var_na *filename, ཧྲིལ add);

static ཧྲིལ parse_include(TCCState *s1, ཧྲིལ do_next, ཧྲིལ test)
{
    ཧྲིལ c, i;
    var_na name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    གལ་སྲིད (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, parimaa_na name, tokcstr.data, i);
        next_nomacro();
    } དེ་མིན {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        དོན་ལུ (;;) {
            next();
            p = name, i = strlen(p) - 1;
            གལ་སྲིད (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                bha_nga;
            གལ་སྲིད (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, parimaa_na name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    གལ་སྲིད (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    དོན་ལུ (;;) {
        ++i;
        གལ་སྲིད (i == 0) {
            /* check absolute include path */
            གལ་སྲིད (!IS_ABSPATH(name))
                continue;
            buf[0] = '\0';
        } དེ་མིན གལ་སྲིད (i == 1) {
            /* search in file's dir if "header.h" */
            གལ་སྲིད (c != '\"')
                continue;
            p = file->true_filename;
            pstrncpy(buf, parimaa_na buf, p, tcc_basename(p) - p);
        } དེ་མིན {
            ཧྲིལ j = i - 2, k = j - s1->nb_include_paths;
            གལ་སྲིད (k < 0)
                p = s1->include_paths[j];
            དེ་མིན གལ་སྲིད (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            དེ་མིན གལ་སྲིད (test)
                ལོག 0;
            དེ་མིན
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, parimaa_na buf, p);
            pstrcat(buf, parimaa_na buf, "/");
        }
        pstrcat(buf, parimaa_na buf, name);
        e = search_cached_include(s1, buf, 0);
        གལ་སྲིད (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            གལ་སྲིད ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (ཧྲིལ)(s1->include_stack_ptr - s1->include_stack), "", buf);
            ལོག 1;
        }
        གལ་སྲིད (tcc_open(s1, buf) >= 0)
            bha_nga;
    }

    གལ་སྲིད (test) {
        tcc_close();
    } དེ་མིན {
        གལ་སྲིད (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        གལ་སྲིད (s1->gen_deps) {
            BufferedFile *bf = file;
            སྐབས (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            གལ་སྲིད (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ལོག 1;
}

/* eval an expression for #if/#elif */
static ཧྲིལ expr_preprocess(TCCState *s1)
{
    ཧྲིལ c, t;
    ཧྲིལ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    སྐབས (1) {
        next(); /* do macro subst */
        t = tok;
        གལ་སྲིད (tok < TOK_IDENT) {
            གལ་སྲིད (tok == TOK_LINEFEED || tok == TOK_EOF)
                bha_nga;
            གལ་སྲིད (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } དེ་མིན གལ་སྲིད (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            གལ་སྲིད (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            གལ་སྲིད (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            གལ་སྲིད (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            གལ་སྲིད (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            གལ་སྲིད (t == '(') {
                next();
                གལ་སྲིད (tok != ')')
                    expect("')'");
            }
            goto c_number;
        } དེ་མིན གལ་སྲིད (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    གལ་སྲིད (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            གལ་སྲིད (tok != ')')
                expect("')'");
            goto c_number;
        } དེ་མིན {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    གལ་སྲིད (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    གལ་སྲིད (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ལོག c != 0;
}

ST_FUNC void pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    སྐབས (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC void parse_define(void)
{
    Sym *s, *first, **ps;
    ཧྲིལ v, t, varg, is_vaargs, t0;
    ཧྲིལ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    གལ་སྲིད (v < TOK_IDENT || v == TOK_DEFINED)
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
    གལ་སྲིད (tok == '(') {
        ཧྲིལ dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        གལ་སྲིད (tok != ')') དོན་ལུ (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            གལ་སྲིད (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } དེ་མིན གལ་སྲིད (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            གལ་སྲིད (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            གལ་སྲིད (tok == ')')
                bha_nga;
            གལ་སྲིད (tok != ',' || is_vaargs)
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
    སྐབས (tok != TOK_LINEFEED && tok != TOK_EOF) {
        གལ་སྲིད (is_space(tok)) {
            str.need_spc |= 1;
        } དེ་མིན {
            གལ་སྲིད (TOK_TWOSHARPS == tok) {
                གལ་སྲིད (0 == t0)
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
    གལ་སྲིད (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

static CachedInclude *search_cached_include(TCCState *s1, const var_na *filename, ཧྲིལ add)
{
    const var_na *s, *basename;
    unsigned ཧྲིལ h;
    CachedInclude *e;
    ཧྲིལ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    སྐབས ((c = (unsigned var_na)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#དེ་མིན
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    དོན་ལུ(;;) {
        གལ་སྲིད (i == 0)
            bha_nga;
        e = s1->cached_includes[i - 1];
        གལ་སྲིད (0 == PATHCMP(filename, e->filename))
            ལོག e;
        གལ་སྲིད (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ལོག e;
        i = e->hash_next;
    }
    གལ་སྲིད (!add)
        ལོག NULL;

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
    ལོག e;
}

static ཧྲིལ pragma_parse(TCCState *s1)
{
    next_nomacro();
    གལ་སྲིད (tok == TOK_push_macro || tok == TOK_pop_macro) {
        ཧྲིལ t = tok, v;
        Sym *s;

        གལ་སྲིད (next(), tok != '(')
            goto pragma_err;
        གལ་སྲིད (next(), tok != TOK_STR)
            goto pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        གལ་སྲིད (next(), tok != ')')
            goto pragma_err;
        གལ་སྲིད (t == TOK_push_macro) {
            སྐབས (NULL == (s = define_find(v)))
                define_push(v, 0, NULL, NULL);
            s->type.ref = s; /* set push boundary */
        } དེ་མིན {
            དོན་ལུ (s = define_stack; s; s = s->prev)
                གལ་སྲིད (s->v == v && s->type.ref == s) {
                    s->type.ref = NULL;
                    bha_nga;
                }
        }
        གལ་སྲིད (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : NULL;
        དེ་མིན
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } དེ་མིན གལ་སྲིད (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } དེ་མིན གལ་སྲིད (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ལོག 1;

    } དེ་མིན གལ་སྲིད (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        གལ་སྲིད (tok == TOK_ASM_pop) {
            next();
            གལ་སྲིད (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } དེ་མིན {
            ཧྲིལ val = 0;
            གལ་སྲིད (tok != ')') {
                གལ་སྲིད (tok == TOK_ASM_push) {
                    next();
                    གལ་སྲིད (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        goto stk_error;
                    val = *s1->pack_stack_ptr++;
                    གལ་སྲིད (tok != ',')
                        goto pack_set;
                    next();
                }
                གལ་སྲིད (tok != TOK_CINT)
                    goto pragma_err;
                val = tokc.i;
                གལ་སྲིད (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    goto pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        གལ་སྲིད (tok != ')')
            goto pragma_err;

    } དེ་མིན གལ་སྲིད (tok == TOK_comment) {
        var_na *p; ཧྲིལ t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        གལ་སྲིད (tok != TOK_STR)
            goto pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        གལ་སྲིད (tok != ')')
            goto pragma_err;
        གལ་སྲིད (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } དེ་མིན {
            གལ་སྲིད (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } དེ་མིན {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ལོག 0;
    }
    next();
    ལོག 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC void tccpp_putfile(const var_na *filename)
{
    var_na buf[1024];
    buf[0] = 0;
    གལ་སྲིད (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, parimaa_na buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, parimaa_na buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    གལ་སྲིད (0 == strcmp(file->filename, buf))
        ལོག;
    //printf("new file '%s'\n", buf);
    གལ་སྲིད (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, parimaa_na file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC void preprocess(ཧྲིལ is_bof)
{
    TCCState *s1 = tcc_state;
    ཧྲིལ c, n, saved_parse_flags;
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
        གལ་སྲིད (s)
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
        གལ་སྲིད (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        གལ་སྲིད (is_bof) {
            གལ་སྲིད (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, NULL));
#endif
                file->ifndef_macro = tok;
            }
        }
        གལ་སྲིད (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        གལ་སྲིད (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        goto test_skip;
    pak_sa TOK_ELSE:
        next_nomacro();
        གལ་སྲིད (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        གལ་སྲིད (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        goto test_else;
    pak_sa TOK_ELIF:
        གལ་སྲིད (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        གལ་སྲིད (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        གལ་སྲིད (c == 1) {
            skip_to_eol(0);
            c = 0;
        } དེ་མིན {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        གལ་སྲིད (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        གལ་སྲིད (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            goto redo;
        }
        bha_nga;
    pak_sa TOK_ENDIF:
        next_nomacro();
        གལ་སྲིད (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        གལ་སྲིད (file->ifndef_macro &&
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
        གལ་སྲིད (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        goto _line_num;
    pak_sa TOK_PPNUM:
        གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        དོན་ལུ (n = 0, q = tokc.str.data; *q; ++q) {
            གལ་སྲིད (!isnum(*q))
                goto _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        གལ་སྲིད (tok != TOK_LINEFEED) {
            གལ་སྲིད (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                goto _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        གལ་སྲིད (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        bha_nga;

    pak_sa TOK_ERROR:
    pak_sa TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        སྐབས (c != '\n' && c != CH_EOF) {
            གལ་སྲིད ((q - buf) < parimaa_na(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        གལ་སྲིད (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        དེ་མིན
            tcc_warning("#warning %s", buf);
        next_nomacro();
        bha_nga;
    }
    pak_sa TOK_PRAGMA:
        གལ་སྲིད (!pragma_parse(s1))
            goto ignore;
        bha_nga;
    pak_sa TOK_LINEFEED:
        goto the_end;
    default:
        /* ignore gas line comment in an 'S' file. */
        གལ་སྲིད (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            goto ignore;
        གལ་སྲིད (tok == '!' && is_bof)
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
static void parse_escape_string(CString *outstr, const uint8_t *buf, ཧྲིལ is_long)
{
    ཧྲིལ c, n, i;
    const uint8_t *p;

    p = buf;
    དོན་ལུ(;;) {
        c = *p;
        གལ་སྲིད (c == '\0')
            bha_nga;
        གལ་སྲིད (c == '\\') {
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
                གལ་སྲིད (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    གལ་སྲིད (isoct(c)) {
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
                    གལ་སྲིད (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    དེ་མིན གལ་སྲིད (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    དེ་མིན གལ་སྲིད (isnum(c))
                        c = c - '0';
                    དེ་མིན གལ་སྲིད (i >= 0)
                        expect("more hex digits in universal-character-name");
                    དེ་མིན
                        goto add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } སྐབས (--i);
		གལ་སྲིད (is_long) {
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
                གལ་སྲིད (!gnu_ext)
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
                གལ་སྲིད (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                དེ་མིན
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                bha_nga;
            }
        } དེ་མིན གལ་སྲིད (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ཧྲིལ cont; /* count of continuation bytes */
            ཧྲིལ skip; /* how many bytes should skip when error occurred */
            ཧྲིལ i;

            /* decode leading byte */
            གལ་སྲིད (c < 0xC2) {
	            skip = 1; goto invalid_utf8_sequence;
            } དེ་མིན གལ་སྲིད (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } དེ་མིན གལ་སྲིད (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } དེ་མིན གལ་སྲིད (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } དེ་མིན {
	            skip = 1; goto invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            དོན་ལུ (i = 1; i <= cont; i++) {
                ཧྲིལ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                གལ་སྲིད (i == 1) {
                    switch (c) {
                    pak_sa 0xE0: l = 0xA0; bha_nga;
                    pak_sa 0xED: h = 0x9F; bha_nga;
                    pak_sa 0xF0: l = 0x90; bha_nga;
                    pak_sa 0xF4: h = 0x8F; bha_nga;
                    }
                }

                གལ་སྲིད (p[i] < l || p[i] > h) {
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
        གལ་སྲིད (!is_long)
            cstr_ccat(outstr, c);
        དེ་མིན {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            གལ་སྲིད (c < 0x10000) {
                cstr_wccat(outstr, c);
            } དེ་མིན {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#དེ་མིན
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    གལ་སྲིད (!is_long)
        cstr_ccat(outstr, '\0');
    དེ་མིན
        cstr_wccat(outstr, '\0');
}

static void parse_string(const var_na *s, ཧྲིལ len)
{
    uint8_t buf[1000], *p = buf;
    ཧྲིལ is_long, sep;

    གལ་སྲིད ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    གལ་སྲིད (len >= parimaa_na buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    གལ་སྲིད (p != buf)
        tcc_free(p);

    གལ་སྲིད (sep == '\'') {
        ཧྲིལ char_size, i, n, c;
        /* XXX: make it portable */
        གལ་སྲིད (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        དེ་མིན
            tok = TOK_LCHAR, char_size = parimaa_na(nwchar_t);
        n = tokcstr.size / char_size - 1;
        གལ་སྲིད (n < 1)
            tcc_error("empty character constant");
        གལ་སྲིད (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        དོན་ལུ (c = i = 0; i < n; ++i) {
            གལ་སྲིད (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            དེ་མིན
                c = (c << 8) | ((var_na *)tokcstr.data)[i];
        }
        tokc.i = c;
    } དེ་མིན {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        གལ་སྲིད (!is_long)
            tok = TOK_STR;
        དེ་མིན
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
static ཧྲིལ bn_lshift(unsigned ཧྲིལ *bn, ཧྲིལ shift, ཧྲིལ or_val)
{
    ཧྲིལ i;
    unsigned ཧྲིལ v;
    གལ་སྲིད (bn[BN_SIZE - 1] >> (32 - shift))
	ལོག shift;
    དོན་ལུ(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ལོག 0;
}

static void bn_zero(unsigned ཧྲིལ *bn)
{
    ཧྲིལ i;
    དོན་ལུ(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const var_na *p)
{
    ཧྲིལ b, t, shift, frac_bits, s, exp_val, ch;
    var_na *q;
    unsigned ཧྲིལ bn[BN_SIZE];
    long dviguu_na d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    གལ་སྲིད (t == '.') {
        goto float_frac_parse;
    } དེ་མིན གལ་སྲིད (t == '0') {
        གལ་སྲིད (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } དེ་མིན གལ་སྲིད (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    སྐབས (1) {
        གལ་སྲིད (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        དེ་མིན གལ་སྲིད (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        དེ་མིན གལ་སྲིད (isnum(ch))
            t = ch - '0';
        དེ་མིན
            bha_nga;
        གལ་སྲིད (t >= b)
            bha_nga;
        གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    གལ་སྲིད (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        གལ་སྲིད (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            གལ་སྲིད (b == 16)
                shift = 4;
            དེ་མིན 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            སྐབས (1) {
                t = *q++;
                གལ་སྲིད (t == '\0') {
                    bha_nga;
                } དེ་མིན གལ་སྲིད (t >= 'a') {
                    t = t - 'a' + 10;
                } དེ་མིན གལ་སྲིད (t >= 'A') {
                    t = t - 'A' + 10;
                } དེ་མིན {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            གལ་སྲིད (ch == '.') {
                ch = *p++;
                སྐབས (1) {
                    t = ch;
                    གལ་སྲིད (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } དེ་མིན གལ་སྲིད (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } དེ་མིན གལ་སྲིད (t >= '0' && t <= '9') {
                        t = t - '0';
                    } དེ་མིན {
                        bha_nga;
                    }
                    གལ་སྲིད (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            གལ་སྲིད (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            གལ་སྲིད (ch == '+') {
                ch = *p++;
            } དེ་མིན གལ་སྲིད (ch == '-') {
                s = -1;
                ch = *p++;
            }
            གལ་སྲིད (ch < '0' || ch > '9')
                expect("exponent digits");
            སྐབས (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		གལ་སྲིད (exp_val < 100000000)
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
            གལ་སྲིད (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } དེ་མིན གལ་སྲིད (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } དེ་མིན {
                tok = TOK_CDOUBLE;
                tokc.d = (dviguu_na)d;
            }
        } དེ་མིན {
            /* decimal floats */
            གལ་སྲིད (ch == '.') {
                གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                སྐབས (ch >= '0' && ch <= '9') {
                    གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            གལ་སྲིད (ch == 'e' || ch == 'E') {
                གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                གལ་སྲིད (ch == '-' || ch == '+') {
                    གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                གལ་སྲིད (ch < '0' || ch > '9')
                    expect("exponent digits");
                སྐབས (ch >= '0' && ch <= '9') {
                    གལ་སྲིད (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            གལ་སྲིད (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } དེ་མིན གལ་སྲིད (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
            } དེ་མིན {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } དེ་མིན {
        unsigned long long n, n1;
        ཧྲིལ lcount, ucount, ov = 0;
        const var_na *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        གལ་སྲིད (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        སྐབས(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            གལ་སྲིད (t == '\0')
                bha_nga;
            དེ་མིན གལ་སྲིད (t >= 'a')
                t = t - 'a' + 10;
            དེ་མིན གལ་སྲིད (t >= 'A')
                t = t - 'A' + 10;
            དེ་མིན
                t = t - '0';
            གལ་སྲིད (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            གལ་སྲིད (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        དོན་ལུ(;;) {
            t = toup(ch);
            གལ་སྲིད (t == 'L') {
                གལ་སྲིད (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                གལ་སྲིད (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } དེ་མིན གལ་སྲིད (t == 'U') {
                གལ་སྲིད (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } དེ་མིན {
                bha_nga;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        གལ་སྲིད (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        གལ་སྲིད (ucount == 0 && b == 10) {
            གལ་སྲིད (lcount <= (LONG_SIZE == 4)) {
                གལ་སྲིད (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            གལ་སྲིད (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } དེ་མིན {
            གལ་སྲིད (lcount <= (LONG_SIZE == 4)) {
                གལ་སྲིད (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                དེ་མིན གལ་སྲིད (n >= 0x80000000U)
                    ucount = 1;
            }
            གལ་སྲིད (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        གལ་སྲིད (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	གལ་སྲིད (lcount) {
            tok = TOK_CLONG;
            གལ་སྲིད (lcount == 2)
                tok = TOK_CLLONG;
	}
	གལ་སྲིད (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    གལ་སྲིད (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    pak_sa c1:                                    \
        PEEKC(c, p);                            \
        གལ་སྲིད (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } དེ་མིན {                                \
            tok = tok1;                         \
        }                                       \
        bha_nga;

/* return next token without macro substitution */
static void next_nomacro(void)
{
    ཧྲིལ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned ཧྲིལ h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    pak_sa ' ':
    pak_sa '\t':
        tok = c;
        p++;
 maybe_space:
        གལ་སྲིད (parse_flags & PARSE_FLAG_SPACES)
            goto keep_tok_flags;
        སྐབས (isidnum_table[*p - CH_EOF] & IS_SPC)
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
        གལ་སྲིད (c == '\\')
            goto parse_simple;
        གལ་སྲིད (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            གལ་སྲིད (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                goto maybe_newline;
            } དེ་མིན གལ་སྲིད (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } དེ་མིན གལ་སྲིད (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } དེ་མིན གལ་སྲིད (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } དེ་མིན {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                གལ་སྲིད (tok_flags & TOK_FLAG_ENDIF) {
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
        } དེ་མིན {
            goto redo_no_start;
        }
        bha_nga;

    pak_sa '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        གལ་སྲིད (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            goto redo_no_start;
        tok = TOK_LINEFEED;
        goto keep_tok_flags;

    pak_sa '#':
        /* XXX: simplify */
        PEEKC(c, p);
        གལ་སྲིད ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            goto maybe_newline;
        } དེ་མིན {
            གལ་སྲིད (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } དེ་མིན {
#གལ་སྲིད !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    goto redo_no_start;
                } དེ་མིན
#endif
                {
                    tok = '#';
                }
            }
        }
        bha_nga;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    pak_sa '$':
        གལ་སྲིད (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        སྐབས (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        གལ་སྲིད (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            དོན་ལུ(;;) {
                ts = *pts;
                གལ་སྲིད (!ts)
                    bha_nga;
                གལ་སྲིད (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (var_na *) p1, len);
        token_found: ;
        } དེ་མིན {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (var_na *) p1, len);
            p--;
            PEEKC(c, p);
            སྐབས (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        གལ་སྲིད (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            གལ་སྲིད (c == '\'' || c == '\"') {
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
        དོན་ལུ(;;) {
            cstr_ccat(&tokcstr, t);
            གལ་སྲིད (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
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
        གལ་སྲིད (isnum(c)) {
            t = '.';
            goto parse_num;
        } དེ་མིན གལ་སྲིད ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            goto parse_ident_fast;
        } དེ་མིན གལ་སྲིད (c == '.') {
            PEEKC(c, p);
            གལ་སྲིད (c == '.') {
                p++;
                tok = TOK_DOTS;
            } དེ་མིན {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } དེ་མིན {
            tok = '.';
        }
        bha_nga;
    pak_sa '\'':
    pak_sa '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        གལ་སྲིད (is_long)
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
        གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_LE;
        } དེ་མིན གལ་སྲིད (c == '<') {
            PEEKC(c, p);
            གལ་སྲིད (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } དེ་མིན {
                tok = TOK_SHL;
            }
        } དེ་མིན {
            tok = TOK_LT;
        }
        bha_nga;
    pak_sa '>':
        PEEKC(c, p);
        གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_GE;
        } དེ་མིན གལ་སྲིད (c == '>') {
            PEEKC(c, p);
            གལ་སྲིད (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } དེ་མིན {
                tok = TOK_SAR;
            }
        } དེ་མིན {
            tok = TOK_GT;
        }
        bha_nga;
        
    pak_sa '&':
        PEEKC(c, p);
        གལ་སྲིད (c == '&') {
            p++;
            tok = TOK_LAND;
        } དེ་མིན གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_A_AND;
        } དེ་མིན {
            tok = '&';
        }
        bha_nga;
        
    pak_sa '|':
        PEEKC(c, p);
        གལ་སྲིད (c == '|') {
            p++;
            tok = TOK_LOR;
        } དེ་མིན གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_A_OR;
        } དེ་མིན {
            tok = '|';
        }
        bha_nga;

    pak_sa '+':
        PEEKC(c, p);
        གལ་སྲིད (c == '+') {
            p++;
            tok = TOK_INC;
        } དེ་མིན གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } དེ་མིན {
            tok = '+';
        }
        bha_nga;
        
    pak_sa '-':
        PEEKC(c, p);
        གལ་སྲིད (c == '-') {
            p++;
            tok = TOK_DEC;
        } དེ་མིན གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } དེ་མིན གལ་སྲིད (c == '>') {
            p++;
            tok = TOK_ARROW;
        } དེ་མིན {
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
        གལ་སྲིད (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            goto maybe_space;
        } དེ་མིན གལ་སྲིད (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto maybe_space;
        } དེ་མིན གལ་སྲིད (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } དེ་མིན {
            tok = '/';
        }
        bha_nga;
        
        /* simple tokens */
    pak_sa '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE) {
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
        གལ་སྲིད (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            goto redo_no_start;
        }
    default:
        གལ་སྲིད (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    goto parse_ident_fast;
        གལ་སྲིད (parse_flags & PARSE_FLAG_ASM_FILE)
            goto parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        bha_nga;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#གལ་སྲིད defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
static ཧྲིལ indent;
static void define_print(TCCState *s1, ཧྲིལ v);
static void pp_print(const var_na *msg, ཧྲིལ v, const ཧྲིལ *str)
{
    FILE *fp = tcc_state->ppfp;

    གལ་སྲིད (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    དེ་མིན གལ་སྲིད (msg[0] == '+')
         ++indent, ++msg;
    དེ་མིན གལ་སྲིད (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    གལ་སྲིད (msg[0] == '#') {
        define_print(tcc_state, v);
    } དེ་མིན {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#དེ་མིན
#define PP_PRINT(x)
#endif

static ཧྲིལ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ཧྲིལ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
static ཧྲིལ *macro_arg_subst(Sym **nested_list, const ཧྲིལ *macro_str, Sym *args)
{
    ཧྲིལ t, t0, t1, t2, n;
    const ཧྲིལ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    དོན་ལུ (s = args, n = 0; s; s = s->prev, ++n);
    སྐབས (n--) {
        དོན་ལུ (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    སྐབས(1) {
        TOK_GET(&t, &macro_str, &cval);
        གལ་སྲིད (!t)
            bha_nga;
        གལ་སྲིད (t == '#') {
            /* stringize */
            do t = *macro_str++; སྐབས (t == ' ');
            s = sym_find2(args, t);
            གལ་སྲིད (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                སྐབས (*st != TOK_EOF) {
                    const var_na *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    སྐབས (*s) {
                        གལ་སྲིད (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        དེ་མིན
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
            } དེ་མིན གལ་སྲིད ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } དེ་མིན {
                expect("macro parameter after '#'");
            }
        } དེ་མིན གལ་སྲིད (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            གལ་སྲིད (s) {
                st = s->d;
                n = 0;
                སྐབས ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                གལ་སྲིད (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    གལ་སྲིད (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ཧྲིལ c = str.str[str.len - 1];
                        སྐབས (str.str[--str.len] != ',')
                            ;
                        གལ་སྲིད (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } དེ་མིན {
                            /* suppress '##' and add variable */
                            str.len++;
                            གལ་སྲིད (c == ' ')
                                str.str[str.len++] = c;
                            goto add_var;
                        }
                    } དེ་མིན {
                        གལ་སྲིད (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } དེ་མིན {
            add_var:
		    གལ་སྲིད (!s->e) {
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
                སྐབས (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } དེ་མིན {
                tok_str_add(&str, t);
            }
        } དེ་མིན {
            tok_str_add2(&str, t, &cval);
        }
        གལ་སྲིད (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ལོག str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
static anta_hstha ཧྲིལ *macro_twosharps(const ཧྲིལ *ptr0)
{
    ཧྲིལ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    const ཧྲིལ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    དོན་ལུ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        གལ་སྲིད (t1 == 0)
            bha_nga;
        དོན་ལུ (;;) {
            n = 0;
            སྐབས ((t2 = ptr[n]) == ' ')
                ++n;
            གལ་སྲིད (t2 != TOK_PPJOIN)
                bha_nga;
            ptr += n;
            སྐབས ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            གལ་སྲིད (t2 == TOK_PLCHLDR)
                continue;
            གལ་སྲིད (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        གལ་སྲིད (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            དོན་ལུ (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                གལ་སྲིད (*file->buf_ptr == 0)
                    bha_nga;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        གལ་སྲིད (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ལོག macro_str1.str;
}

static ཧྲིལ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ཧྲིལ c;
    དོན་ལུ (;;) {
        PEEKC(c, p);
        switch (c) {
        pak_sa '/':
            PEEKC(c, p);
            གལ་སྲིད (c == '*')
                p = parse_comment(p);
            དེ་མིན གལ་སྲིད (c == '/')
                p = parse_line_comment(p);
            དེ་མིན {
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
            ལོག c;
        }
        གལ་སྲིད (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
static ཧྲིལ next_argstream(Sym **nested_list, TokenString *ws_str)
{
    ཧྲིལ t;
    Sym *sa;

    སྐབས (macro_ptr) {
        const ཧྲིལ *m = macro_ptr;
        སྐབས ((t = *m) != 0) {
            གལ་སྲིད (ws_str) {
                གལ་སྲིད (t != ' ')
                    ལོག t;
                ++m;
            } དེ་མིན {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ལོག tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        གལ་སྲིད (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    གལ་སྲིད (ws_str) {
        ལོག peek_file(ws_str);
    } དེ་མིན {
        next_nomacro();
        གལ་སྲིད (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ལོག tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
static ཧྲིལ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ཧྲིལ t;
    ཧྲིལ v = s->v;

    PP_PRINT(("#", v, s->d));
    གལ་སྲིད (s->d) {
        ཧྲིལ *mstr = s->d;
        ཧྲིལ *jstr;
        Sym *sa;
        ཧྲིལ ret;

        གལ་སྲིད (s->type.t & MACRO_FUNC) {
            ཧྲིལ saved_parse_flags = parse_flags;
            TokenString str;
            ཧྲིལ parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            གལ་སྲིད (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                གལ་སྲིད (parse_flags & PARSE_FLAG_SPACES)
                    དོན་ལུ (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ལོག 0;
            } དེ་མིན {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = NULL;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            དོན་ལུ(;;) {
                do {
                    t = next_argstream(nested_list, NULL);
                } སྐབས (t == ' ' || --i);

                གལ་སྲིད (!sa) {
                    གལ་སྲིད (t == ')') /* handle '()' case */
                        bha_nga;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                སྐབས (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    གལ་སྲིད (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    གལ་སྲིད (t == '(')
                        parlevel++;
                    གལ་སྲིད (t == ')')
                        parlevel--;
                    གལ་སྲིད (t == ' ')
                        str.need_spc |= 1;
                    དེ་མིན
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, NULL);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                གལ་སྲིད (t == ')') {
                    གལ་སྲིད (!sa)
                        bha_nga;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    གལ་སྲིད (sa->type.t && gnu_ext)
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
            སྐབས (sa) {
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
        གལ་སྲིད (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        གལ་སྲིད (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        གལ་སྲིད (jstr != mstr)
            tok_str_free_str(jstr);
        གལ་སྲིད (mstr != s->d)
            tok_str_free_str(mstr);
        ལོག ret;

    } དེ་མིན {
        CValue cval;
        var_na buf[32], *cstrval = buf;

        /* special macros */
        གལ་སྲིད (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, parimaa_na(buf), "%d", t);
            t = TOK_PPNUM;
            goto add_cstr1;

        } དེ་མིན གལ་སྲིད (v == TOK___FILE__) {
            cstrval = file->filename;
            goto add_cstr;

        } དེ་མིན གལ་སྲིད (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            sa_nracanaa tm *tm;
            time(&ti);
            tm = localtime(&ti);
            གལ་སྲིད (v == TOK___DATE__) {
                static var_na const ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, parimaa_na(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } དེ་མིན {
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
        ལོག 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
static ཧྲིལ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    const ཧྲིལ *macro_str
    )
{
    Sym *s;
    ཧྲིལ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    ཧྲིལ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    སྐབས (1) {
        TOK_GET(&t, &macro_str, &cval);
        གལ་སྲིད (t == 0 || t == TOK_EOF)
            bha_nga;
        གལ་སྲིད (t >= TOK_IDENT) {
            s = define_find(t);
            གལ་སྲིད (s == NULL || nosubst)
                goto no_subst;
            /* if nested substitution, do nothing */
            གལ་སྲིད (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                goto no_subst;
            }
            str = tok_str_alloc();
            str->str = (ཧྲིལ*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            གལ་སྲིད (macro_stack != str) {
                /* already finished by reading function macro arguments */
                bha_nga;
            }
            macro_str = macro_ptr;
            end_macro ();
        } དེ་མིན གལ་སྲིད (t == ' ') {
            གལ་སྲིད (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } དེ་མིན {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            གལ་སྲིད (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            གལ་སྲིད (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ལོག nosubst;
}

/* return next token with macro substitution */
ST_FUNC void next(void)
{
    ཧྲིལ t;
    སྐབས (macro_ptr) {
redo:
        t = *macro_ptr;
        གལ་སྲིད (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            གལ་སྲིད (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                goto redo;
            }
            goto convert;
        } དེ་མིན གལ་སྲིད (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            continue;
        } དེ་མིན གལ་སྲིད (t == TOK_EOF) {
            /* do nothing */
        } དེ་མིན {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            གལ་སྲིད (t == '\\') {
                གལ་སྲིད (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ལོག;
    }

    next_nomacro();
    t = tok;
    གལ་སྲིད (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        གལ་སྲིད (s) {
            Sym *nested_list = NULL;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            goto redo;
        }
        ལོག;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    གལ་སྲིད (t == TOK_PPNUM) {
        གལ་སྲིད  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } དེ་མིན གལ་སྲིད (t == TOK_PPSTR) {
        གལ་སྲིད (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN void unget_tok(ཧྲིལ last_tok)
{
    TokenString *str = &unget_buf;
    ཧྲིལ alloc = 0;
    གལ་སྲིད (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    གལ་སྲིད (tok != TOK_EOF)
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
# གལ་སྲིད PTR_SIZE == 8
    "_WIN64\0"
# endif
#དེ་མིན
# གལ་སྲིད defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# དེ་མིན
    "__linux__\0"
    "__linux\0"
#  གལ་སྲིད TARGETOS_ANDROID
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
    སྐབས (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

static void tcc_predefs(TCCState *s1, CString *cs, ཧྲིལ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    གལ་སྲིད (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    གལ་སྲིད (is_asm)
      putdef(cs, "__ASSEMBLER__");
    གལ་སྲིད (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    གལ་སྲིད (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    གལ་སྲིད (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    གལ་སྲིད (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    གལ་སྲིད (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    གལ་སྲིད (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    གལ་སྲིད (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    གལ་སྲིད (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    གལ་སྲིད (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#གལ་སྲིད CONFIG_TCC_PREDEFS
        #include "tccdefs_.h" /* include as strings */
#དེ་མིན
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC void preprocess_start(TCCState *s1, ཧྲིལ filetype)
{
    ཧྲིལ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

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

    གལ་སྲིད (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        གལ་སྲིད (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        གལ་སྲིད (s1->cmdline_incl.size)
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
    སྐབས (macro_stack)
        end_macro();
    macro_ptr = NULL;
    སྐབས (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ཧྲིལ set_idnum(ཧྲིལ c, ཧྲིལ val)
{
    ཧྲིལ prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ལོག prev;
}

ST_FUNC void tccpp_new(TCCState *s)
{
    ཧྲིལ i, c;
    const var_na *p, *r;

    /* init isid table */
    དོན་ལུ(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    དོན་ལུ(i = 128; i<256; i++)
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
    སྐབས (*p) {
        r = p;
        དོན་ལུ(;;) {
            c = *r++;
            གལ་སྲིད (c == '\0')
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
    ཧྲིལ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    གལ་སྲིད (n > total_idents)
        total_idents = n;
    དོན་ལུ (i = n; --i >= 0;)
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

static ཧྲིལ pp_need_space(ཧྲིལ a, ཧྲིལ b);

static void tok_print(const ཧྲིལ *str, const var_na *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ཧྲིལ t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    སྐབས (str) {
	TOK_GET(&t, &str, &cval);
	གལ་སྲིད (t == 0 || t == TOK_EOF)
	    bha_nga;
        གལ་སྲིད (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

static void pp_line(TCCState *s1, BufferedFile *f, ཧྲིལ level)
{
    ཧྲིལ d = f->line_num - f->line_ref;

    གལ་སྲིད (s1->dflag & 4)
	ལོག;

    གལ་སྲིད (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } དེ་མིན གལ་སྲིད (level == 0 && f->line_ref && d < 8) {
	སྐབས (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } དེ་མིན གལ་སྲིད (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } དེ་མིན {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

static void define_print(TCCState *s1, ཧྲིལ v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    གལ་སྲིད (NULL == s || NULL == s->d)
        ལོག;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, NULL));
    གལ་སྲིད (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        གལ་སྲིད (a)
            དོན་ལུ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, NULL));
                གལ་སྲིད (!(a = a->next))
                    bha_nga;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

static void pp_debug_defines(TCCState *s1)
{
    ཧྲིལ v, t;
    const var_na *vs;
    FILE *fp;

    t = pp_debug_tok;
    གལ་སྲིད (t == 0)
        ལོག;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, NULL);
    གལ་སྲིད (t == TOK_DEFINE) {
        define_print(s1, v);
    } དེ་མིན གལ་སྲིད (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } དེ་མིན གལ་སྲིད (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } དེ་མིན གལ་སྲིད (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
static ཧྲིལ pp_need_space(ཧྲིལ a, ཧྲིལ b)
{
    ལོག 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
static ཧྲིལ pp_check_he0xE(ཧྲིལ t, const var_na *p)
{
    གལ་སྲིད (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ལོག 'E';
    ལོག t;
}

/* Preprocess the current file */
ST_FUNC ཧྲིལ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ཧྲིལ token_seen, spcs, level;
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
    གལ་སྲིད (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    གལ་སྲིད (s1->do_bench) {
	/* for PP benchmarks */
	do next(); སྐབས (tok != TOK_EOF);
	ལོག 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    གལ་སྲིད (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    དོན་ལུ (;;) {
        iptr = s1->include_stack_ptr;
        next();
        གལ་སྲིད (tok == TOK_EOF)
            bha_nga;

        level = s1->include_stack_ptr - iptr;
        གལ་སྲིད (level) {
            གལ་སྲིད (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        གལ་སྲིད (s1->dflag & 7) {
            pp_debug_defines(s1);
            གལ་སྲིད (s1->dflag & 4)
                continue;
        }

        གལ་སྲིད (is_space(tok)) {
            གལ་སྲིད (spcs < parimaa_na white - 1)
                white[spcs++] = tok;
            continue;
        } དེ་མིན གལ་སྲིད (tok == TOK_LINEFEED) {
            spcs = 0;
            གལ་སྲིད (token_seen == TOK_LINEFEED)
                continue;
            ++file->line_ref;
        } དེ་མིན གལ་སྲིད (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } དེ་མིན གལ་སྲིད (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ལོག 0;
}

/* ------------------------------------------------------------------------- */
