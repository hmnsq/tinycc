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
#ಅನ್ತರ್ಭಾವ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA ಪೂರ್ಣಾಙ್ಕ tok_flags;
ST_DATA ಪೂರ್ಣಾಙ್ಕ parse_flags;

ST_DATA ಸಂರಚನಾ BufferedFile *file;
ST_DATA ಪೂರ್ಣಾಙ್ಕ tok;
ST_DATA CValue tokc;
ST_DATA ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ಪೂರ್ಣಾಙ್ಕ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ಪೂರ್ಣಾಙ್ಕ pp_ಅಭಿವ್ಯಕ್ತಿ;

/* ------------------------------------------------------------------------- */

ಸ್ಥಿರ TokenSym *hash_ident[TOK_HASH_SIZE];
ಸ್ಥಿರ ವರ್ಣ token_buf[STRING_MAX_SIZE + 1];
ಸ್ಥಿರ CString cstr_buf;
ಸ್ಥಿರ TokenString tokstr_buf;
ಸ್ಥಿರ TokenString unget_buf;
ಸ್ಥಿರ unsigned ವರ್ಣ isidnum_table[256 - CH_EOF];
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pp_debug_tok, pp_debug_symv;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pp_counter;
ಸ್ಥಿರ ಶೂನ್ಯ tok_print(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *str, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ, ...);
ಸ್ಥಿರ ಶೂನ್ಯ next_nomacro(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಸಂಖ್ಯೆ(ಧ್ರುವ ವರ್ಣ *p);
ಸ್ಥಿರ ಶೂನ್ಯ parse_string(ಧ್ರುವ ವರ್ಣ *p, ಪೂರ್ಣಾಙ್ಕ len);

ಸ್ಥಿರ ಸಂರಚನಾ TinyAlloc *toksym_alloc;
ಸ್ಥಿರ ಸಂರಚನಾ TinyAlloc *tokstr_alloc;

ಸ್ಥಿರ TokenString *macro_ರಾಶಿ;

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ tcc_keywords[] = 
#define DEF(id, str) str "\0"
#ಅನ್ತರ್ಭಾವ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ tok_two_chars[] =
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

ST_FUNC ಶೂನ್ಯ skip(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯದಿ (tok != c) {
        ವರ್ಣ tmp[40];
        pstrcpy(tmp, ಪರಿಮಾಣ tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC ಶೂನ್ಯ expect(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
    tcc_error("%s expected", ಸಂದೇಶ);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#ಅನ್ಯಥಾ
#ಯದಿ !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#ಅನ್ಯಥಾ
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ಧ್ರುವ ವರ್ಣ *sfile, ಪೂರ್ಣಾಙ್ಕ sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ಸಂರಚನಾ TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#ಯದಿ TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    ಸಙ್ಘ {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tal_header_t {
    size_t  size; /* word align */
#ಯದಿ TAL_DEBUG
    ಪೂರ್ಣಾಙ್ಕ     ಸಾಲು_ಅಂಕೆ; /* negative line_num used for double free check */
    ವರ್ಣ    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (ಪರಿಮಾಣ (size_t) - 1)) & ~(ಪರಿಮಾಣ (size_t) - 1))

/* ------------------------------------------------------------------------- */

ಸ್ಥಿರ TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(ಪರಿಮಾಣ(TinyAlloc) - ಪರಿಮಾಣ (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#ಯದಿ TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ಪ್ರತ್ಯಾಗಮ al;
}

ಸ್ಥಿರ ಶೂನ್ಯ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#ಯದಿ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#ಯದಿ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ಯದಿ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    ಯದಿ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        ಯಾವತ್ (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            ಯದಿ (header->ಸಾಲು_ಅಂಕೆ > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->ಸಾಲು_ಅಂಕೆ, (ಪೂರ್ಣಾಙ್ಕ)header->size);
            }
            p += header->size + ಪರಿಮಾಣ(tal_header_t);
        }
#ಯದಿ TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    ಯದಿ (al)
        ಗಚ್ಛ tail_call;
    *pal = al;
}

ಸ್ಥಿರ ಶೂನ್ಯ tal_free_impl(TinyAlloc **pal, ಶೂನ್ಯ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **ತುದಿ = pal;
    tal_header_t *header;

    ಯದಿ (!p)
        ಪ್ರತ್ಯಾಗಮ;
    header = (tal_header_t *)p - 1;
#ಯದಿ TAL_DEBUG
    ಯದಿ (header->ಸಾಲು_ಅಂಕೆ < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (ಪೂರ್ಣಾಙ್ಕ)-header->ಸಾಲು_ಅಂಕೆ, (ಪೂರ್ಣಾಙ್ಕ)header->size);
    } ಅನ್ಯಥಾ
        header->ಸಾಲು_ಅಂಕೆ = -header->ಸಾಲು_ಅಂಕೆ;
#endif
    al = *pal;
    ಯಾವತ್ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    ಯದಿ (0 == --al->nb_allocs) {
        *pal = al->next;
        ಯದಿ ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } ಅನ್ಯಥಾ {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *ತುದಿ, *ತುದಿ = al;
        }
    } ಅನ್ಯಥಾ ಯದಿ ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ *tal_realloc_impl(TinyAlloc **pal, ಶೂನ್ಯ *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    ಶೂನ್ಯ *ret;
    unsigned adj_size = TAL_ALIGN(size) + ಪರಿಮಾಣ(tal_header_t);
    TinyAlloc *al = *pal;

    ಯದಿ (p) {
        /* reallpc case */
        ಯಾವತ್ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        ಯದಿ ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        ಯದಿ (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ಪ್ರತ್ಯಾಗಮ ret;
        } ಅನ್ಯಥಾ ಯದಿ (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#ಯದಿ TAL_DEBUG
            header->ಸಾಲು_ಅಂಕೆ = -header->ಸಾಲು_ಅಂಕೆ;
#endif
        }
    } ಅನ್ಯಥಾ {
        /* new alloc case */
        ಯಾವತ್ (al->p + adj_size > al->bufend) {
            al = al->next;
            ಯದಿ (!al) {
                unsigned new_size = (*pal)->size;
                ಯದಿ (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                ಭಙ್ಗ;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - ಪರಿಮಾಣ(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#ಯದಿ  TAL_DEBUG
    {
        ಪೂರ್ಣಾಙ್ಕ ofs = strlen(sfile) + 1 - ಪರಿಮಾಣ header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->ಸಾಲು_ಅಂಕೆ = sline;
#ಯದಿ TAL_INFO
        ಯದಿ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ಯದಿ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ಪ್ರತ್ಯಾಗಮ ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ಸ್ಥಿರ ಶೂನ್ಯ cstr_realloc(CString *cstr, ಪೂರ್ಣಾಙ್ಕ new_size)
{
    ಪೂರ್ಣಾಙ್ಕ size;

    size = cstr->size_allocated;
    ಯದಿ (size < 8)
        size = 8; /* no need to allocate a too small first string */
    ಯಾವತ್ (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN ಶೂನ್ಯ cstr_ccat(CString *cstr, ಪೂರ್ಣಾಙ್ಕ ch)
{
    ಪೂರ್ಣಾಙ್ಕ size;
    size = cstr->size + 1;
    ಯದಿ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN ವರ್ಣ *unicode_to_utf8 (ವರ್ಣ *b, uint32_t Uc)
{
    ಯದಿ (Uc<0x80) *b++=Uc;
    ಅನ್ಯಥಾ ಯದಿ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    ಅನ್ಯಥಾ ಯದಿ (Uc-0xd800u<0x800) ಗಚ್ಛ error;
    ಅನ್ಯಥಾ ಯದಿ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ಅನ್ಯಥಾ ಯದಿ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ಅನ್ಯಥಾ error: tcc_error("0x%x is not a valid universal character", Uc);
    ಪ್ರತ್ಯಾಗಮ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN ಶೂನ್ಯ cstr_u8cat(CString *cstr, ಪೂರ್ಣಾಙ್ಕ ch)
{
    ವರ್ಣ buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC ಶೂನ್ಯ cstr_cat(CString *cstr, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len)
{
    ಪೂರ್ಣಾಙ್ಕ size;
    ಯದಿ (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    ಯದಿ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC ಶೂನ್ಯ cstr_wccat(CString *cstr, ಪೂರ್ಣಾಙ್ಕ ch)
{
    ಪೂರ್ಣಾಙ್ಕ size;
    size = cstr->size + ಪರಿಮಾಣ(nwchar_t);
    ಯದಿ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - ಪರಿಮಾಣ(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC ಶೂನ್ಯ cstr_new(CString *cstr)
{
    memset(cstr, 0, ಪರಿಮಾಣ(CString));
}

/* free string and reset it to NULL */
ST_FUNC ಶೂನ್ಯ cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC ಶೂನ್ಯ cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ cstr_vprintf(CString *cstr, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap)
{
    va_list v;
    ಪೂರ್ಣಾಙ್ಕ len, size = 80;
    ಪ್ರತಿ (;;) {
        size += cstr->size;
        ಯದಿ (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        ಯದಿ (len >= 0 && len < size)
            ಭಙ್ಗ;
        size *= 2;
    }
    cstr->size += len;
    ಪ್ರತ್ಯಾಗಮ len;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ cstr_printf(CString *cstr, ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap; ಪೂರ್ಣಾಙ್ಕ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ಪ್ರತ್ಯಾಗಮ len;
}

/* XXX: unicode ? */
ಸ್ಥಿರ ಶೂನ್ಯ add_char(CString *cstr, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯದಿ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ಯದಿ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } ಅನ್ಯಥಾ {
        cstr_ccat(cstr, '\\');
        ಯದಿ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } ಅನ್ಯಥಾ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ಸ್ಥಿರ TokenSym *tok_alloc_new(TokenSym **pts, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len)
{
    TokenSym *ts, **ptable;
    ಪೂರ್ಣಾಙ್ಕ i;

    ಯದಿ (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ಯದಿ ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * ಪರಿಮಾಣ(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, ಪರಿಮಾಣ(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ರಿಕ್ತ;
    ts->sym_label = ರಿಕ್ತ;
    ts->sym_struct = ರಿಕ್ತ;
    ts->sym_identifier = ರಿಕ್ತ;
    ts->len = len;
    ts->hash_next = ರಿಕ್ತ;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ಪ್ರತ್ಯಾಗಮ ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ len)
{
    TokenSym *ts, **pts;
    ಪೂರ್ಣಾಙ್ಕ i;
    unsigned ಪೂರ್ಣಾಙ್ಕ h;
    
    h = TOK_HASH_INIT;
    ಪ್ರತಿ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned ವರ್ಣ *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    ಪ್ರತಿ(;;) {
        ts = *pts;
        ಯದಿ (!ts)
            ಭಙ್ಗ;
        ಯದಿ (ts->len == len && !memcmp(ts->str, str, len))
            ಪ್ರತ್ಯಾಗಮ ts;
        pts = &(ts->hash_next);
    }
    ಪ್ರತ್ಯಾಗಮ tok_alloc_new(pts, str, len);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tok_alloc_const(ಧ್ರುವ ವರ್ಣ *str)
{
    ಪ್ರತ್ಯಾಗಮ tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ಧ್ರುವ ವರ್ಣ *get_tok_str(ಪೂರ್ಣಾಙ್ಕ v, CValue *cv)
{
    ವರ್ಣ *p;
    ಪೂರ್ಣಾಙ್ಕ i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    ವಿಕಲ್ಪ(v) {
    ಪಕ್ಷ TOK_CINT:
    ಪಕ್ಷ TOK_CUINT:
    ಪಕ್ಷ TOK_CLONG:
    ಪಕ್ಷ TOK_CULONG:
    ಪಕ್ಷ TOK_CLLONG:
    ಪಕ್ಷ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    ಪಕ್ಷ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_PPNUM:
    ಪಕ್ಷ TOK_PPSTR:
        ಪ್ರತ್ಯಾಗಮ (ವರ್ಣ*)cv->str.data;
    ಪಕ್ಷ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    ಪಕ್ಷ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ಯದಿ (v == TOK_STR) {
            len = cv->str.size - 1;
            ಪ್ರತಿ(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned ವರ್ಣ *)cv->str.data)[i]);
        } ಅನ್ಯಥಾ {
            len = (cv->str.size / ಪರಿಮಾಣ(nwchar_t)) - 1;
            ಪ್ರತಿ(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_CFLOAT:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<float>");
    ಪಕ್ಷ TOK_CDOUBLE:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<double>");
    ಪಕ್ಷ TOK_CLDOUBLE:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<long double>");
    ಪಕ್ಷ TOK_LINENUM:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    ಪಕ್ಷ TOK_LT:
        v = '<';
        ಗಚ್ಛ addv;
    ಪಕ್ಷ TOK_GT:
        v = '>';
        ಗಚ್ಛ addv;
    ಪಕ್ಷ TOK_DOTS:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "...");
    ಪಕ್ಷ TOK_A_SHL:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<<=");
    ಪಕ್ಷ TOK_A_SAR:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, ">>=");
    ಪಕ್ಷ TOK_EOF:
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<eof>");
    ಪಕ್ಷ 0: /* anonymous nameless symbols */
        ಪ್ರತ್ಯಾಗಮ strcpy(p, "<no name>");
    ಸ್ವಭಾವ:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        ಯದಿ (v < TOK_IDENT) {
            /* search in two bytes table */
            ಧ್ರುವ unsigned ವರ್ಣ *q = tok_two_chars;
            ಯಾವತ್ (*q) {
                ಯದಿ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ಪ್ರತ್ಯಾಗಮ cstr_buf.data;
                }
                q += 3;
            }
            ಯದಿ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ಭಙ್ಗ;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } ಅನ್ಯಥಾ ಯದಿ (v < tok_ident) {
            ಪ್ರತ್ಯಾಗಮ table_ident[v - TOK_IDENT]->str;
        } ಅನ್ಯಥಾ ಯದಿ (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } ಅನ್ಯಥಾ {
            /* should never happen */
            ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
        }
        ಭಙ್ಗ;
    }
    ಪ್ರತ್ಯಾಗಮ cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ handle_eob(ಶೂನ್ಯ)
{
    BufferedFile *bf = file;
    ಪೂರ್ಣಾಙ್ಕ len;

    /* only tries to read if really end of buffer */
    ಯದಿ (bf->buf_ptr >= bf->buf_end) {
        ಯದಿ (bf->fd >= 0) {
#ಯದಿ defined(PARSE_DEBUG)
            len = 1;
#ಅನ್ಯಥಾ
            len = IO_BUF_SIZE;
#endif
            len = ಪಠ(bf->fd, bf->buffer, len);
            ಯದಿ (len < 0)
                len = 0;
        } ಅನ್ಯಥಾ {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    ಯದಿ (bf->buf_ptr < bf->buf_end) {
        ಪ್ರತ್ಯಾಗಮ bf->buf_ptr[0];
    } ಅನ್ಯಥಾ {
        bf->buf_ptr = bf->buf_end;
        ಪ್ರತ್ಯಾಗಮ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ next_c(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ಯದಿ (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ಪ್ರತ್ಯಾಗಮ ch;
}

/* input with '\[\r]\n' handling. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ handle_stray_noerror(ಪೂರ್ಣಾಙ್ಕ err)
{
    ಪೂರ್ಣಾಙ್ಕ ch;
    ಯಾವತ್ ((ch = next_c()) == '\\') {
        ch = next_c();
        ಯದಿ (ch == '\n') {
    newl:
            file->ಸಾಲು_ಅಂಕೆ++;
        } ಅನ್ಯಥಾ {
            ಯದಿ (ch == '\r') {
                ch = next_c();
                ಯದಿ (ch == '\n')
                    ಗಚ್ಛ newl;
                *--file->buf_ptr = '\r';
            }
            ಯದಿ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ಪ್ರತ್ಯಾಗಮ *--file->buf_ptr = '\\';
        }
    }
    ಪ್ರತ್ಯಾಗಮ ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ handle_bs(uint8_t **p)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ಪ್ರತ್ಯಾಗಮ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ handle_stray(uint8_t **p)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ಪ್ರತ್ಯಾಗಮ c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    ಯದಿ (c == '\\')\
        c = handle_stray(&p); \
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ skip_spaces(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ch;
    --file->buf_ptr;
    ಕುರು {
        ch = ninp();
    } ಯಾವತ್ (isidnum_table[ch - CH_EOF] & IS_SPC);
    ಪ್ರತ್ಯಾಗಮ ch;
}

/* single line C++ comments */
ಸ್ಥಿರ uint8_t *parse_ಸಾಲು_comment(uint8_t *p)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    ಪ್ರತಿ(;;) {
        ಪ್ರತಿ (;;) {
            c = *++p;
    redo:
            ಯದಿ (c == '\n' || c == '\\')
                ಭಙ್ಗ;
            c = *++p;
            ಯದಿ (c == '\n' || c == '\\')
                ಭಙ್ಗ;
        }
        ಯದಿ (c == '\n')
            ಭಙ್ಗ;
        c = handle_bs(&p);
        ಯದಿ (c == CH_EOF)
            ಭಙ್ಗ;
        ಯದಿ (c != '\\')
            ಗಚ್ಛ redo;
    }
    ಪ್ರತ್ಯಾಗಮ p;
}

/* C comments */
ಸ್ಥಿರ uint8_t *parse_comment(uint8_t *p)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    ಪ್ರತಿ(;;) {
        /* fast skip loop */
        ಪ್ರತಿ(;;) {
            c = *++p;
        redo:
            ಯದಿ (c == '\n' || c == '*' || c == '\\')
                ಭಙ್ಗ;
            c = *++p;
            ಯದಿ (c == '\n' || c == '*' || c == '\\')
                ಭಙ್ಗ;
        }
        /* now we can handle all the cases */
        ಯದಿ (c == '\n') {
            file->ಸಾಲು_ಅಂಕೆ++;
        } ಅನ್ಯಥಾ ಯದಿ (c == '*') {
            ಕುರು {
                c = *++p;
            } ಯಾವತ್ (c == '*');
            ಯದಿ (c == '\\')
                c = handle_bs(&p);
            ಯದಿ (c == '/')
                ಭಙ್ಗ;
            ಗಚ್ಛ check_eof;
        } ಅನ್ಯಥಾ {
            c = handle_bs(&p);
        check_eof:
            ಯದಿ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ಯದಿ (c != '\\')
                ಗಚ್ಛ redo;
        }
    }
    ಪ್ರತ್ಯಾಗಮ p + 1;
}

/* parse a string without interpreting escapes */
ಸ್ಥಿರ uint8_t *parse_pp_string(uint8_t *p, ಪೂರ್ಣಾಙ್ಕ sep, CString *str)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    ಪ್ರತಿ(;;) {
        c = *++p;
    redo:
        ಯದಿ (c == sep) {
            ಭಙ್ಗ;
        } ಅನ್ಯಥಾ ಯದಿ (c == '\\') {
            c = handle_bs(&p);
            ಯದಿ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } ಅನ್ಯಥಾ ಯದಿ (c == '\\') {
                ಯದಿ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ಯದಿ (c == '\\') {
                    c = handle_bs(&p);
                    ಯದಿ (c == CH_EOF)
                        ಗಚ್ಛ unterminated_string;
                }
                ಗಚ್ಛ add_char;
            } ಅನ್ಯಥಾ {
                ಗಚ್ಛ redo;
            }
        } ಅನ್ಯಥಾ ಯದಿ (c == '\n') {
        add_lf:
            ಯದಿ (ACCEPT_LF_IN_STRINGS) {
                file->ಸಾಲು_ಅಂಕೆ++;
                ಗಚ್ಛ add_char;
            } ಅನ್ಯಥಾ ಯದಿ (str) { /* not skipping */
                ಗಚ್ಛ unterminated_string;
            } ಅನ್ಯಥಾ {
                //tcc_warning("missing terminating %c character", sep);
                ಪ್ರತ್ಯಾಗಮ p;
            }
        } ಅನ್ಯಥಾ ಯದಿ (c == '\r') {
            c = *++p;
            ಯದಿ (c == '\\')
                c = handle_bs(&p);
            ಯದಿ (c == '\n')
                ಗಚ್ಛ add_lf;
            ಯದಿ (c == CH_EOF)
                ಗಚ್ಛ unterminated_string;
            ಯದಿ (str)
                cstr_ccat(str, '\r');
            ಗಚ್ಛ redo;
        } ಅನ್ಯಥಾ {
        add_char:
            ಯದಿ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ಪ್ರತ್ಯಾಗಮ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ಸ್ಥಿರ ಶೂನ್ಯ preprocess_skip(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a, start_of_ಸಾಲು, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_ಸಾಲು = 1;
    in_warn_or_error = 0;
    ಪ್ರತಿ(;;) {
        c = *p;
        ವಿಕಲ್ಪ(c) {
        ಪಕ್ಷ ' ':
        ಪಕ್ಷ '\t':
        ಪಕ್ಷ '\f':
        ಪಕ್ಷ '\v':
        ಪಕ್ಷ '\r':
            p++;
            ಅನುವರ್ತ;
        ಪಕ್ಷ '\n':
            file->ಸಾಲು_ಅಂಕೆ++;
            p++;
            ಗಚ್ಛ redo_start;
        ಪಕ್ಷ '\\':
            c = handle_bs(&p);
            ಯದಿ (c == CH_EOF)
                expect("#endif");
            ಯದಿ (c == '\\')
                ++p;
            ಅನುವರ್ತ;
        /* skip strings */
        ಪಕ್ಷ '\"':
        ಪಕ್ಷ '\'':
            ಯದಿ (in_warn_or_error)
                ಗಚ್ಛ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ರಿಕ್ತ);
            ಭಙ್ಗ;
        /* skip comments */
        ಪಕ್ಷ '/':
            ಯದಿ (in_warn_or_error)
                ಗಚ್ಛ _default;
            ++p;
            c = handle_bs(&p);
            ಯದಿ (c == '*') {
                p = parse_comment(p);
            } ಅನ್ಯಥಾ ಯದಿ (c == '/') {
                p = parse_ಸಾಲು_comment(p);
            }
            ಅನುವರ್ತ;
        ಪಕ್ಷ '#':
            p++;
            ಯದಿ (start_of_ಸಾಲು) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                ಯದಿ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    ಗಚ್ಛ the_end;
                ಯದಿ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                ಅನ್ಯಥಾ ಯದಿ (tok == TOK_ENDIF)
                    a--;
                ಅನ್ಯಥಾ ಯದಿ( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                ಅನ್ಯಥಾ ಯದಿ (tok == TOK_LINEFEED)
                    ಗಚ್ಛ redo_start;
                ಅನ್ಯಥಾ ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_ಸಾಲು_comment(p - 1);
            }
#ಯದಿ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            ಅನ್ಯಥಾ ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_ಸಾಲು_comment(p - 1);
#ಅನ್ಯಥಾ
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            ಭಙ್ಗ;
_default:
        ಸ್ವಭಾವ:
            p++;
            ಭಙ್ಗ;
        }
        start_of_ಸಾಲು = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#ಯದಿ 0
/* return the number of additional 'ints' necessary to store the
   token */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ tok_size(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *p)
{
    ವಿಕಲ್ಪ(*p) {
        /* 4 bytes */
    ಪಕ್ಷ TOK_CINT:
    ಪಕ್ಷ TOK_CUINT:
    ಪಕ್ಷ TOK_CCHAR:
    ಪಕ್ಷ TOK_LCHAR:
    ಪಕ್ಷ TOK_CFLOAT:
    ಪಕ್ಷ TOK_LINENUM:
        ಪ್ರತ್ಯಾಗಮ 1 + 1;
    ಪಕ್ಷ TOK_STR:
    ಪಕ್ಷ TOK_LSTR:
    ಪಕ್ಷ TOK_PPNUM:
    ಪಕ್ಷ TOK_PPSTR:
        ಪ್ರತ್ಯಾಗಮ 1 + 1 + (p[1] + 3) / 4;
    ಪಕ್ಷ TOK_CLONG:
    ಪಕ್ಷ TOK_CULONG:
	ಪ್ರತ್ಯಾಗಮ 1 + LONG_SIZE / 4;
    ಪಕ್ಷ TOK_CDOUBLE:
    ಪಕ್ಷ TOK_CLLONG:
    ಪಕ್ಷ TOK_CULLONG:
        ಪ್ರತ್ಯಾಗಮ 1 + 2;
    ಪಕ್ಷ TOK_CLDOUBLE:
        ಪ್ರತ್ಯಾಗಮ 1 + LDOUBLE_ಪದಗಳು;
    ಸ್ವಭಾವ:
        ಪ್ರತ್ಯಾಗಮ 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN ಶೂನ್ಯ tok_str_new(TokenString *s)
{
    s->str = ರಿಕ್ತ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_ಸಾಲು_ಅಂಕೆ = -1;
}

ST_FUNC TokenString *tok_str_alloc(ಶೂನ್ಯ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, ಪರಿಮಾಣ *str);
    tok_str_new(str);
    ಪ್ರತ್ಯಾಗಮ str;
}

ST_FUNC ಶೂನ್ಯ tok_str_free_str(ಪೂರ್ಣಾಙ್ಕ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ಶೂನ್ಯ tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ *tok_str_realloc(TokenString *s, ಪೂರ್ಣಾಙ್ಕ new_size)
{
    ಪೂರ್ಣಾಙ್ಕ *str, size;

    size = s->allocated_len;
    ಯದಿ (size < 16)
        size = 16;
    ಯಾವತ್ (size < new_size)
        size = size * 2;
    ಯದಿ (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
        s->allocated_len = size;
        s->str = str;
    }
    ಪ್ರತ್ಯಾಗಮ s->str;
}

ST_FUNC ಶೂನ್ಯ tok_str_add(TokenString *s, ಪೂರ್ಣಾಙ್ಕ t)
{
    ಪೂರ್ಣಾಙ್ಕ len, *str;

    len = s->len;
    str = s->str;
    ಯದಿ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC ಶೂನ್ಯ begin_macro(TokenString *str, ಪೂರ್ಣಾಙ್ಕ alloc)
{
    str->alloc = alloc;
    str->prev = macro_ರಾಶಿ;
    str->prev_ptr = macro_ptr;
    str->save_ಸಾಲು_ಅಂಕೆ = file->ಸಾಲು_ಅಂಕೆ;
    macro_ptr = str->str;
    macro_ರಾಶಿ = str;
}

ST_FUNC ಶೂನ್ಯ end_macro(ಶೂನ್ಯ)
{
    TokenString *str = macro_ರಾಶಿ;
    macro_ರಾಶಿ = str->prev;
    macro_ptr = str->prev_ptr;
    file->ಸಾಲು_ಅಂಕೆ = str->save_ಸಾಲು_ಅಂಕೆ;
    ಯದಿ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } ಅನ್ಯಥಾ {
        ಯದಿ (str->alloc == 2)
            str->str = ರಿಕ್ತ; /* don't free */
        tok_str_free(str);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tok_str_add2(TokenString *s, ಪೂರ್ಣಾಙ್ಕ t, CValue *cv)
{
    ಪೂರ್ಣಾಙ್ಕ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ಯದಿ (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    ವಿಕಲ್ಪ(t) {
    ಪಕ್ಷ TOK_CINT:
    ಪಕ್ಷ TOK_CUINT:
    ಪಕ್ಷ TOK_CCHAR:
    ಪಕ್ಷ TOK_LCHAR:
    ಪಕ್ಷ TOK_CFLOAT:
    ಪಕ್ಷ TOK_LINENUM:
#ಯದಿ LONG_SIZE == 4
    ಪಕ್ಷ TOK_CLONG:
    ಪಕ್ಷ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_PPNUM:
    ಪಕ್ಷ TOK_PPSTR:
    ಪಕ್ಷ TOK_STR:
    ಪಕ್ಷ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_ಪದಗಳು =
                1 + (cv->str.size + ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ) - 1) / ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ);
            ಯದಿ (len + nb_ಪದಗಳು >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_ಪದಗಳು + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_ಪದಗಳು;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CDOUBLE:
    ಪಕ್ಷ TOK_CLLONG:
    ಪಕ್ಷ TOK_CULLONG:
#ಯದಿ LONG_SIZE == 8
    ಪಕ್ಷ TOK_CLONG:
    ಪಕ್ಷ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ಯದಿ (LDOUBLE_ಪದಗಳು >= 3)
        str[len++] = cv->tab[2];
        ಯದಿ (LDOUBLE_ಪದಗಳು >= 4)
        str[len++] = cv->tab[3];
    ಸ್ವಭಾವ:
        ಭಙ್ಗ;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC ಶೂನ್ಯ tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ಯದಿ (file->ಸಾಲು_ಅಂಕೆ != s->last_ಸಾಲು_ಅಂಕೆ) {
        s->last_ಸಾಲು_ಅಂಕೆ = file->ಸಾಲು_ಅಂಕೆ;
        cval.i = s->last_ಸಾಲು_ಅಂಕೆ;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ಸ್ಥಿರ ಶೂನ್ಯ tok_str_add2_spc(TokenString *s, ಪೂರ್ಣಾಙ್ಕ t, CValue *cv)
{
    ಯದಿ (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ tok_get(ಪೂರ್ಣಾಙ್ಕ *t, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ **pp, CValue *cv)
{
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *p = *pp;
    ಪೂರ್ಣಾಙ್ಕ n, *tab;

    tab = cv->tab;
    ವಿಕಲ್ಪ(*t = *p++) {
#ಯದಿ LONG_SIZE == 4
    ಪಕ್ಷ TOK_CLONG:
#endif
    ಪಕ್ಷ TOK_CINT:
    ಪಕ್ಷ TOK_CCHAR:
    ಪಕ್ಷ TOK_LCHAR:
    ಪಕ್ಷ TOK_LINENUM:
        cv->i = *p++;
        ಭಙ್ಗ;
#ಯದಿ LONG_SIZE == 4
    ಪಕ್ಷ TOK_CULONG:
#endif
    ಪಕ್ಷ TOK_CUINT:
        cv->i = (unsigned)*p++;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CFLOAT:
	tab[0] = *p++;
	ಭಙ್ಗ;
    ಪಕ್ಷ TOK_STR:
    ಪಕ್ಷ TOK_LSTR:
    ಪಕ್ಷ TOK_PPNUM:
    ಪಕ್ಷ TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (ವರ್ಣ*)p;
        p += (cv->str.size + ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ) - 1) / ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ);
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_CDOUBLE:
    ಪಕ್ಷ TOK_CLLONG:
    ಪಕ್ಷ TOK_CULLONG:
#ಯದಿ LONG_SIZE == 8
    ಪಕ್ಷ TOK_CLONG:
    ಪಕ್ಷ TOK_CULONG:
#endif
        n = 2;
        ಗಚ್ಛ copy;
    ಪಕ್ಷ TOK_CLDOUBLE:
        n = LDOUBLE_ಪದಗಳು;
    copy:
        ಕುರು
            *tab++ = *p++;
        ಯಾವತ್ (--n);
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        ಭಙ್ಗ;
    }
    *pp = p;
}

#ಯದಿ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#ಅನ್ಯಥಾ
# define TOK_GET(t,p,c) ಕುರು { \
    ಪೂರ್ಣಾಙ್ಕ _t = **(p); \
    ಯದಿ (TOK_HAS_ಮೌಲ್ಯ(_t)) \
        tok_get(t, p, c); \
    ಅನ್ಯಥಾ \
        *(t) = _t, ++*(p); \
    } ಯಾವತ್ (0)
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ macro_is_equal(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *a, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *b)
{
    CValue cv;
    ಪೂರ್ಣಾಙ್ಕ t;

    ಯದಿ (!a || !b)
        ಪ್ರತ್ಯಾಗಮ 1;

    ಯಾವತ್ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ಯದಿ (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ಪ್ರತ್ಯಾಗಮ 0;
    }
    ಪ್ರತ್ಯಾಗಮ !(*a || *b);
}

/* defines handling */
ST_INLN ಶೂನ್ಯ define_ತಳ್ಳು(ಪೂರ್ಣಾಙ್ಕ v, ಪೂರ್ಣಾಙ್ಕ macro_type, ಪೂರ್ಣಾಙ್ಕ *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_ರಾಶಿ, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    ಯದಿ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ರಿಕ್ತ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC ಶೂನ್ಯ define_undef(Sym *s)
{
    ಪೂರ್ಣಾಙ್ಕ v = s->v;
    ಯದಿ (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = ರಿಕ್ತ;
}

ST_INLN Sym *define_find(ಪೂರ್ಣಾಙ್ಕ v)
{
    v -= TOK_IDENT;
    ಯದಿ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    ಪ್ರತ್ಯಾಗಮ table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC ಶೂನ್ಯ free_defines(Sym *b)
{
    ಯಾವತ್ (define_ರಾಶಿ != b) {
        Sym *ತುದಿ = define_ರಾಶಿ;
        define_ರಾಶಿ = ತುದಿ->prev;
        tok_str_free_str(ತುದಿ->d);
        define_undef(ತುದಿ);
        sym_free(ತುದಿ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ಸ್ಥಿರ ಶೂನ್ಯ maybe_run_test(TCCState *s)
{
    ಧ್ರುವ ವರ್ಣ *p;
    ಯದಿ (s->include_ರಾಶಿ_ptr != s->include_ರಾಶಿ)
        ಪ್ರತ್ಯಾಗಮ;
    p = get_tok_str(tok, ರಿಕ್ತ);
    ಯದಿ (0 != memcmp(p, "test_", 5))
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (0 != --s->run_test)
        ಪ್ರತ್ಯಾಗಮ;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ತಳ್ಳು(tok, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
}

ST_FUNC ಶೂನ್ಯ skip_to_eol(ಪೂರ್ಣಾಙ್ಕ warn)
{
    ಯದಿ (tok == TOK_LINEFEED)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (warn)
        tcc_warning("extra tokens after directive");
    ಯಾವತ್ (macro_ರಾಶಿ)
        end_macro();
    file->buf_ptr = parse_ಸಾಲು_comment(file->buf_ptr - 1);
    next_nomacro();
}

ಸ್ಥಿರ CachedInclude *
ಹುಡುಕು_cached_include(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ add);

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ parse_include(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ do_next, ಪೂರ್ಣಾಙ್ಕ test)
{
    ಪೂರ್ಣಾಙ್ಕ c, i;
    ವರ್ಣ name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ಯದಿ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, ಪರಿಮಾಣ name, tokcstr.data, i);
        next_nomacro();
    } ಅನ್ಯಥಾ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        ಪ್ರತಿ (;;) {
            next();
            p = name, i = strlen(p) - 1;
            ಯದಿ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ಭಙ್ಗ;
            ಯದಿ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, ಪರಿಮಾಣ name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ಯದಿ (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    ಪ್ರತಿ (;;) {
        ++i;
        ಯದಿ (i == 0) {
            /* check absolute include path */
            ಯದಿ (!IS_ABSPATH(name))
                ಅನುವರ್ತ;
            buf[0] = '\0';
        } ಅನ್ಯಥಾ ಯದಿ (i == 1) {
            /* search in file's dir if "header.h" */
            ಯದಿ (c != '\"')
                ಅನುವರ್ತ;
            p = file->true_filename;
            pstrncpy(buf, ಪರಿಮಾಣ buf, p, tcc_basename(p) - p);
        } ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ j = i - 2, k = j - s1->nb_include_paths;
            ಯದಿ (k < 0)
                p = s1->include_paths[j];
            ಅನ್ಯಥಾ ಯದಿ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            ಅನ್ಯಥಾ ಯದಿ (test)
                ಪ್ರತ್ಯಾಗಮ 0;
            ಅನ್ಯಥಾ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, ಪರಿಮಾಣ buf, p);
            pstrcat(buf, ಪರಿಮಾಣ buf, "/");
        }
        pstrcat(buf, ಪರಿಮಾಣ buf, name);
        e = ಹುಡುಕು_cached_include(s1, buf, 0);
        ಯದಿ (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            ಯದಿ ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (ಪೂರ್ಣಾಙ್ಕ)(s1->include_ರಾಶಿ_ptr - s1->include_ರಾಶಿ), "", buf);
            ಪ್ರತ್ಯಾಗಮ 1;
        }
        ಯದಿ (tcc_open(s1, buf) >= 0)
            ಭಙ್ಗ;
    }

    ಯದಿ (test) {
        tcc_close();
    } ಅನ್ಯಥಾ {
        ಯದಿ (s1->include_ರಾಶಿ_ptr >= s1->include_ರಾಶಿ + INCLUDE_ರಾಶಿ_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ರಾಶಿ_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        ಯದಿ (s1->gen_deps) {
            BufferedFile *bf = file;
            ಯಾವತ್ (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            ಯದಿ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ಪ್ರತ್ಯಾಗಮ 1;
}

/* eval an expression for #if/#elif */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ಅಭಿವ್ಯಕ್ತಿ_preprocess(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ c, t;
    ಪೂರ್ಣಾಙ್ಕ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_ಅಭಿವ್ಯಕ್ತಿ = 1;
    ಯಾವತ್ (1) {
        next(); /* do macro subst */
        t = tok;
        ಯದಿ (tok < TOK_IDENT) {
            ಯದಿ (tok == TOK_LINEFEED || tok == TOK_EOF)
                ಭಙ್ಗ;
            ಯದಿ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            ಯದಿ (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ಯದಿ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ಯದಿ (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            ಯದಿ (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            ಯದಿ (t == '(') {
                next();
                ಯದಿ (tok != ')')
                    expect("')'");
            }
            ಗಚ್ಛ c_ಸಂಖ್ಯೆ;
        } ಅನ್ಯಥಾ ಯದಿ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    ಯದಿ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ಯದಿ (tok != ')')
                expect("')'");
            ಗಚ್ಛ c_ಸಂಖ್ಯೆ;
        } ಅನ್ಯಥಾ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_ಸಂಖ್ಯೆ:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    ಯದಿ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_ಅಭಿವ್ಯಕ್ತಿ = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = ಅಭಿವ್ಯಕ್ತಿ_const();
    ಯದಿ (tok != TOK_EOF)
        tcc_error("...");
    pp_ಅಭಿವ್ಯಕ್ತಿ = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ಪ್ರತ್ಯಾಗಮ c != 0;
}

ST_FUNC ಶೂನ್ಯ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_ಅಭಿವ್ಯಕ್ತಿ, 0));
    macro_ptr = macro_ರಾಶಿ->str;
    ಯಾವತ್ (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC ಶೂನ್ಯ parse_define(ಶೂನ್ಯ)
{
    Sym *s, *first, **ps;
    ಪೂರ್ಣಾಙ್ಕ v, t, varg, is_vaargs, t0;
    ಪೂರ್ಣಾಙ್ಕ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ಯದಿ (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = ರಿಕ್ತ;
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
    ಯದಿ (tok == '(') {
        ಪೂರ್ಣಾಙ್ಕ dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        ಯದಿ (tok != ')') ಪ್ರತಿ (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            ಯದಿ (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            ಯದಿ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ರಾಶಿ, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            ಯದಿ (tok == ')')
                ಭಙ್ಗ;
            ಯದಿ (tok != ',' || is_vaargs)
                ಗಚ್ಛ bad_list;
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
    ಯಾವತ್ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ಯದಿ (is_space(tok)) {
            str.need_spc |= 1;
        } ಅನ್ಯಥಾ {
            ಯದಿ (TOK_TWOSHARPS == tok) {
                ಯದಿ (0 == t0)
                    ಗಚ್ಛ bad_twosharp;
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
    ಯದಿ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ತಳ್ಳು(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ಸ್ಥಿರ CachedInclude *ಹುಡುಕು_cached_include(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ add)
{
    ಧ್ರುವ ವರ್ಣ *s, *basename;
    unsigned ಪೂರ್ಣಾಙ್ಕ h;
    CachedInclude *e;
    ಪೂರ್ಣಾಙ್ಕ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ಯಾವತ್ ((c = (unsigned ವರ್ಣ)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#ಅನ್ಯಥಾ
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    ಪ್ರತಿ(;;) {
        ಯದಿ (i == 0)
            ಭಙ್ಗ;
        e = s1->cached_includes[i - 1];
        ಯದಿ (0 == PATHCMP(filename, e->filename))
            ಪ್ರತ್ಯಾಗಮ e;
        ಯದಿ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ಪ್ರತ್ಯಾಗಮ e;
        i = e->hash_next;
    }
    ಯದಿ (!add)
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;

    e = tcc_malloc(ಪರಿಮಾಣ(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    ಪ್ರತ್ಯಾಗಮ e;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pragma_parse(TCCState *s1)
{
    next_nomacro();
    ಯದಿ (tok == TOK_ತಳ್ಳು_macro || tok == TOK_ತೆಗೆ_macro) {
        ಪೂರ್ಣಾಙ್ಕ t = tok, v;
        Sym *s;

        ಯದಿ (next(), tok != '(')
            ಗಚ್ಛ pragma_err;
        ಯದಿ (next(), tok != TOK_STR)
            ಗಚ್ಛ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        ಯದಿ (next(), tok != ')')
            ಗಚ್ಛ pragma_err;
        ಯದಿ (t == TOK_ತಳ್ಳು_macro) {
            ಯಾವತ್ (ರಿಕ್ತ == (s = define_find(v)))
                define_ತಳ್ಳು(v, 0, ರಿಕ್ತ, ರಿಕ್ತ);
            s->type.ref = s; /* set push boundary */
        } ಅನ್ಯಥಾ {
            ಪ್ರತಿ (s = define_ರಾಶಿ; s; s = s->prev)
                ಯದಿ (s->v == v && s->type.ref == s) {
                    s->type.ref = ರಿಕ್ತ;
                    ಭಙ್ಗ;
                }
        }
        ಯದಿ (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : ರಿಕ್ತ;
        ಅನ್ಯಥಾ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_once) {
        ಹುಡುಕು_cached_include(s1, file->true_filename, 1)->once = 1;

    } ಅನ್ಯಥಾ ಯದಿ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ಪ್ರತ್ಯಾಗಮ 1;

    } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        ಯದಿ (tok == TOK_ASM_ತೆಗೆ) {
            next();
            ಯದಿ (s1->pack_ರಾಶಿ_ptr <= s1->pack_ರಾಶಿ) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ರಾಶಿ_ptr--;
        } ಅನ್ಯಥಾ {
            ಪೂರ್ಣಾಙ್ಕ val = 0;
            ಯದಿ (tok != ')') {
                ಯದಿ (tok == TOK_ASM_ತಳ್ಳು) {
                    next();
                    ಯದಿ (s1->pack_ರಾಶಿ_ptr >= s1->pack_ರಾಶಿ + PACK_ರಾಶಿ_SIZE - 1)
                        ಗಚ್ಛ stk_error;
                    val = *s1->pack_ರಾಶಿ_ptr++;
                    ಯದಿ (tok != ',')
                        ಗಚ್ಛ pack_set;
                    next();
                }
                ಯದಿ (tok != TOK_CINT)
                    ಗಚ್ಛ pragma_err;
                val = tokc.i;
                ಯದಿ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    ಗಚ್ಛ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_ರಾಶಿ_ptr = val;
        }
        ಯದಿ (tok != ')')
            ಗಚ್ಛ pragma_err;

    } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_comment) {
        ವರ್ಣ *p; ಪೂರ್ಣಾಙ್ಕ t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        ಯದಿ (tok != TOK_STR)
            ಗಚ್ಛ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        ಯದಿ (tok != ')')
            ಗಚ್ಛ pragma_err;
        ಯದಿ (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } ಅನ್ಯಥಾ {
            ಯದಿ (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } ಅನ್ಯಥಾ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ಪ್ರತ್ಯಾಗಮ 0;
    }
    next();
    ಪ್ರತ್ಯಾಗಮ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC ಶೂನ್ಯ tccpp_putfile(ಧ್ರುವ ವರ್ಣ *filename)
{
    ವರ್ಣ buf[1024];
    buf[0] = 0;
    ಯದಿ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, ಪರಿಮಾಣ buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, ಪರಿಮಾಣ buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    ಯದಿ (0 == strcmp(file->filename, buf))
        ಪ್ರತ್ಯಾಗಮ;
    //printf("new file '%s'\n", buf);
    ಯದಿ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, ಪರಿಮಾಣ file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC ಶೂನ್ಯ preprocess(ಪೂರ್ಣಾಙ್ಕ is_bof)
{
    TCCState *s1 = tcc_state;
    ಪೂರ್ಣಾಙ್ಕ c, n, saved_parse_flags;
    ವರ್ಣ buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_ಅಂಕೆ
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    ವಿಕಲ್ಪ(tok) {
    ಪಕ್ಷ TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        ಯದಿ (s)
            define_undef(s);
        next_nomacro();
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_INCLUDE:
    ಪಕ್ಷ TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        ಗಚ್ಛ the_end;
    ಪಕ್ಷ TOK_IFNDEF:
        c = 1;
        ಗಚ್ಛ do_ifdef;
    ಪಕ್ಷ TOK_IF:
        c = ಅಭಿವ್ಯಕ್ತಿ_preprocess(s1);
        ಗಚ್ಛ do_if;
    ಪಕ್ಷ TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        ಯದಿ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ಯದಿ (is_bof) {
            ಯದಿ (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, ರಿಕ್ತ));
#endif
                file->ifndef_macro = tok;
            }
        }
        ಯದಿ (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr >= s1->ifdef_ರಾಶಿ + IFDEF_ರಾಶಿ_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ರಾಶಿ_ptr++ = c;
        ಗಚ್ಛ test_skip;
    ಪಕ್ಷ TOK_ELSE:
        next_nomacro();
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr == s1->ifdef_ರಾಶಿ)
            tcc_error("#else without matching #if");
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ರಾಶಿ_ptr[-1] ^= 3);
        ಗಚ್ಛ test_else;
    ಪಕ್ಷ TOK_ELIF:
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr == s1->ifdef_ರಾಶಿ)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ರಾಶಿ_ptr[-1];
        ಯದಿ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ಯದಿ (c == 1) {
            skip_to_eol(0);
            c = 0;
        } ಅನ್ಯಥಾ {
            c = ಅಭಿವ್ಯಕ್ತಿ_preprocess(s1);
            s1->ifdef_ರಾಶಿ_ptr[-1] = c;
        }
    test_else:
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr == file->ifdef_ರಾಶಿ_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ಯದಿ (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            ಗಚ್ಛ redo;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_ENDIF:
        next_nomacro();
        ಯದಿ (s1->ifdef_ರಾಶಿ_ptr <= file->ifdef_ರಾಶಿ_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ರಾಶಿ_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ಯದಿ (file->ifndef_macro &&
            s1->ifdef_ರಾಶಿ_ptr == file->ifdef_ರಾಶಿ_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_ಸಾಲು:
        parse_flags &= ~PARSE_FLAG_TOK_ಅಂಕೆ;
        next();
        ಯದಿ (tok != TOK_PPNUM) {
    ಸಾಲು_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        ಗಚ್ಛ ಸಾಲು_ಅಂಕೆ_2;
    ಪಕ್ಷ TOK_PPNUM:
        ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE)
            ಗಚ್ಛ ignore;
        c = 0; /* no error with extra tokens */
    ಸಾಲು_ಅಂಕೆ_2:
        ಪ್ರತಿ (n = 0, q = tokc.str.data; *q; ++q) {
            ಯದಿ (!isnum(*q))
                ಗಚ್ಛ ಸಾಲು_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        ಯದಿ (tok != TOK_LINEFEED) {
            ಯದಿ (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                ಗಚ್ಛ ಸಾಲು_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        ಯದಿ (file->fd > 0)
            total_ಸಾಲುಗಳು += file->ಸಾಲು_ಅಂಕೆ - n;
        file->ಸಾಲು_ಅಂಕೆ = n;
        ಭಙ್ಗ;

    ಪಕ್ಷ TOK_ERROR:
    ಪಕ್ಷ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ಯಾವತ್ (c != '\n' && c != CH_EOF) {
            ಯದಿ ((q - buf) < ಪರಿಮಾಣ(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ಯದಿ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        ಅನ್ಯಥಾ
            tcc_warning("#warning %s", buf);
        next_nomacro();
        ಭಙ್ಗ;
    }
    ಪಕ್ಷ TOK_PRAGMA:
        ಯದಿ (!pragma_parse(s1))
            ಗಚ್ಛ ignore;
        ಭಙ್ಗ;
    ಪಕ್ಷ TOK_LINEFEED:
        ಗಚ್ಛ the_end;
    ಸ್ವಭಾವ:
        /* ignore gas line comment in an 'S' file. */
        ಯದಿ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            ಗಚ್ಛ ignore;
        ಯದಿ (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            ಗಚ್ಛ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        ಗಚ್ಛ the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_escape_string(CString *outstr, ಧ್ರುವ uint8_t *buf, ಪೂರ್ಣಾಙ್ಕ is_long)
{
    ಪೂರ್ಣಾಙ್ಕ c, n, i;
    ಧ್ರುವ uint8_t *p;

    p = buf;
    ಪ್ರತಿ(;;) {
        c = *p;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        ಯದಿ (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ವಿಕಲ್ಪ(c) {
            ಪಕ್ಷ '0': ಪಕ್ಷ '1': ಪಕ್ಷ '2': ಪಕ್ಷ '3':
            ಪಕ್ಷ '4': ಪಕ್ಷ '5': ಪಕ್ಷ '6': ಪಕ್ಷ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ಯದಿ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ಯದಿ (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                ಗಚ್ಛ add_char_nonext;
            ಪಕ್ಷ 'x': i = 0; ಗಚ್ಛ parse_hex_or_ucn;
            ಪಕ್ಷ 'u': i = 4; ಗಚ್ಛ parse_hex_or_ucn;
            ಪಕ್ಷ 'U': i = 8; ಗಚ್ಛ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                ಕುರು {
                    c = *p;
                    ಯದಿ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    ಅನ್ಯಥಾ ಯದಿ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    ಅನ್ಯಥಾ ಯದಿ (isnum(c))
                        c = c - '0';
                    ಅನ್ಯಥಾ ಯದಿ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    ಅನ್ಯಥಾ
                        ಗಚ್ಛ add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } ಯಾವತ್ (--i);
		ಯದಿ (is_long) {
    add_hex_or_ucn:
                    c = n;
		    ಗಚ್ಛ add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ಅನುವರ್ತ;
            ಪಕ್ಷ 'a':
                c = '\a';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'b':
                c = '\b';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'f':
                c = '\f';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'n':
                c = '\n';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'r':
                c = '\r';
                ಭಙ್ಗ;
            ಪಕ್ಷ 't':
                c = '\t';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'v':
                c = '\v';
                ಭಙ್ಗ;
            ಪಕ್ಷ 'e':
                ಯದಿ (!gnu_ext)
                    ಗಚ್ಛ invalid_escape;
                c = 27;
                ಭಙ್ಗ;
            ಪಕ್ಷ '\'':
            ಪಕ್ಷ '\"':
            ಪಕ್ಷ '\\': 
            ಪಕ್ಷ '?':
                ಭಙ್ಗ;
            ಸ್ವಭಾವ:
            invalid_escape:
                ಯದಿ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                ಅನ್ಯಥಾ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ಭಙ್ಗ;
            }
        } ಅನ್ಯಥಾ ಯದಿ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ಪೂರ್ಣಾಙ್ಕ cont; /* count of continuation bytes */
            ಪೂರ್ಣಾಙ್ಕ skip; /* how many bytes should skip when error occurred */
            ಪೂರ್ಣಾಙ್ಕ i;

            /* decode leading byte */
            ಯದಿ (c < 0xC2) {
	            skip = 1; ಗಚ್ಛ invalid_utf8_sequence;
            } ಅನ್ಯಥಾ ಯದಿ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } ಅನ್ಯಥಾ ಯದಿ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } ಅನ್ಯಥಾ ಯದಿ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } ಅನ್ಯಥಾ {
	            skip = 1; ಗಚ್ಛ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            ಪ್ರತಿ (i = 1; i <= cont; i++) {
                ಪೂರ್ಣಾಙ್ಕ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ಯದಿ (i == 1) {
                    ವಿಕಲ್ಪ (c) {
                    ಪಕ್ಷ 0xE0: l = 0xA0; ಭಙ್ಗ;
                    ಪಕ್ಷ 0xED: h = 0x9F; ಭಙ್ಗ;
                    ಪಕ್ಷ 0xF0: l = 0x90; ಭಙ್ಗ;
                    ಪಕ್ಷ 0xF4: h = 0x8F; ಭಙ್ಗ;
                    }
                }

                ಯದಿ (p[i] < l || p[i] > h) {
                    skip = i; ಗಚ್ಛ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            ಗಚ್ಛ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            ಗಚ್ಛ add_char_nonext;

        }
        p++;
    add_char_nonext:
        ಯದಿ (!is_long)
            cstr_ccat(outstr, c);
        ಅನ್ಯಥಾ {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            ಯದಿ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } ಅನ್ಯಥಾ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#ಅನ್ಯಥಾ
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    ಯದಿ (!is_long)
        cstr_ccat(outstr, '\0');
    ಅನ್ಯಥಾ
        cstr_wccat(outstr, '\0');
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_string(ಧ್ರುವ ವರ್ಣ *s, ಪೂರ್ಣಾಙ್ಕ len)
{
    uint8_t buf[1000], *p = buf;
    ಪೂರ್ಣಾಙ್ಕ is_long, sep;

    ಯದಿ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ಯದಿ (len >= ಪರಿಮಾಣ buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ಯದಿ (p != buf)
        tcc_free(p);

    ಯದಿ (sep == '\'') {
        ಪೂರ್ಣಾಙ್ಕ char_size, i, n, c;
        /* XXX: make it portable */
        ಯದಿ (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        ಅನ್ಯಥಾ
            tok = TOK_LCHAR, char_size = ಪರಿಮಾಣ(nwchar_t);
        n = tokcstr.size / char_size - 1;
        ಯದಿ (n < 1)
            tcc_error("empty character constant");
        ಯದಿ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        ಪ್ರತಿ (c = i = 0; i < n; ++i) {
            ಯದಿ (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            ಅನ್ಯಥಾ
                c = (c << 8) | ((ವರ್ಣ *)tokcstr.data)[i];
        }
        tokc.i = c;
    } ಅನ್ಯಥಾ {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ಯದಿ (!is_long)
            tok = TOK_STR;
        ಅನ್ಯಥಾ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ bn_lshift(unsigned ಪೂರ್ಣಾಙ್ಕ *bn, ಪೂರ್ಣಾಙ್ಕ shift, ಪೂರ್ಣಾಙ್ಕ or_val)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    unsigned ಪೂರ್ಣಾಙ್ಕ v;
    ಯದಿ (bn[BN_SIZE - 1] >> (32 - shift))
	ಪ್ರತ್ಯಾಗಮ shift;
    ಪ್ರತಿ(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ bn_zero(unsigned ಪೂರ್ಣಾಙ್ಕ *bn)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಸಂಖ್ಯೆ(ಧ್ರುವ ವರ್ಣ *p)
{
    ಪೂರ್ಣಾಙ್ಕ b, t, shift, frac_bits, s, exp_val, ch;
    ವರ್ಣ *q;
    unsigned ಪೂರ್ಣಾಙ್ಕ bn[BN_SIZE];
    long ದ್ವಿಗುಣ d;

    /*ಸಂಖ್ಯೆ*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ಯದಿ (t == '.') {
        ಗಚ್ಛ float_frac_parse;
    } ಅನ್ಯಥಾ ಯದಿ (t == '0') {
        ಯದಿ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } ಅನ್ಯಥಾ ಯದಿ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ಯಾವತ್ (1) {
        ಯದಿ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        ಅನ್ಯಥಾ ಯದಿ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        ಅನ್ಯಥಾ ಯದಿ (isnum(ch))
            t = ch - '0';
        ಅನ್ಯಥಾ
            ಭಙ್ಗ;
        ಯದಿ (t >= b)
            ಭಙ್ಗ;
        ಯದಿ (q >= token_buf + STRING_MAX_SIZE) {
        ಅಂಕೆ_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ಯದಿ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ಯದಿ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            ಯದಿ (b == 16)
                shift = 4;
            ಅನ್ಯಥಾ 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            ಯಾವತ್ (1) {
                t = *q++;
                ಯದಿ (t == '\0') {
                    ಭಙ್ಗ;
                } ಅನ್ಯಥಾ ಯದಿ (t >= 'a') {
                    t = t - 'a' + 10;
                } ಅನ್ಯಥಾ ಯದಿ (t >= 'A') {
                    t = t - 'A' + 10;
                } ಅನ್ಯಥಾ {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            ಯದಿ (ch == '.') {
                ch = *p++;
                ಯಾವತ್ (1) {
                    t = ch;
                    ಯದಿ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } ಅನ್ಯಥಾ ಯದಿ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } ಅನ್ಯಥಾ ಯದಿ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } ಅನ್ಯಥಾ {
                        ಭಙ್ಗ;
                    }
                    ಯದಿ (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            ಯದಿ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ಯದಿ (ch == '+') {
                ch = *p++;
            } ಅನ್ಯಥಾ ಯದಿ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ಯದಿ (ch < '0' || ch > '9')
                expect("exponent digits");
            ಯಾವತ್ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ಯದಿ (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long ದ್ವಿಗುಣ)bn[3] * 79228162514264337593543950336.0L +
	        (long ದ್ವಿಗುಣ)bn[2] * 18446744073709551616.0L +
	        (long ದ್ವಿಗುಣ)bn[1] * 4294967296.0L +
	        (long ದ್ವಿಗುಣ)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            ಯದಿ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ಭಿನ್ನ)d;
            } ಅನ್ಯಥಾ ಯದಿ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } ಅನ್ಯಥಾ {
                tok = TOK_CDOUBLE;
                tokc.d = (ದ್ವಿಗುಣ)d;
            }
        } ಅನ್ಯಥಾ {
            /* decimal floats */
            ಯದಿ (ch == '.') {
                ಯದಿ (q >= token_buf + STRING_MAX_SIZE)
                    ಗಚ್ಛ ಅಂಕೆ_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ಯಾವತ್ (ch >= '0' && ch <= '9') {
                    ಯದಿ (q >= token_buf + STRING_MAX_SIZE)
                        ಗಚ್ಛ ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ಯದಿ (ch == 'e' || ch == 'E') {
                ಯದಿ (q >= token_buf + STRING_MAX_SIZE)
                    ಗಚ್ಛ ಅಂಕೆ_too_long;
                *q++ = ch;
                ch = *p++;
                ಯದಿ (ch == '-' || ch == '+') {
                    ಯದಿ (q >= token_buf + STRING_MAX_SIZE)
                        ಗಚ್ಛ ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ಯದಿ (ch < '0' || ch > '9')
                    expect("exponent digits");
                ಯಾವತ್ (ch >= '0' && ch <= '9') {
                    ಯದಿ (q >= token_buf + STRING_MAX_SIZE)
                        ಗಚ್ಛ ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ಯದಿ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ರಿಕ್ತ);
            } ಅನ್ಯಥಾ ಯದಿ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ರಿಕ್ತ);
            } ಅನ್ಯಥಾ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ರಿಕ್ತ);
            }
        }
    } ಅನ್ಯಥಾ {
        unsigned long long n, n1;
        ಪೂರ್ಣಾಙ್ಕ lcount, ucount, ov = 0;
        ಧ್ರುವ ವರ್ಣ *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ಯದಿ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ಯಾವತ್(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ಯದಿ (t == '\0')
                ಭಙ್ಗ;
            ಅನ್ಯಥಾ ಯದಿ (t >= 'a')
                t = t - 'a' + 10;
            ಅನ್ಯಥಾ ಯದಿ (t >= 'A')
                t = t - 'A' + 10;
            ಅನ್ಯಥಾ
                t = t - '0';
            ಯದಿ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ಯದಿ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        ಪ್ರತಿ(;;) {
            t = toup(ch);
            ಯದಿ (t == 'L') {
                ಯದಿ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ಯದಿ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } ಅನ್ಯಥಾ ಯದಿ (t == 'U') {
                ಯದಿ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } ಅನ್ಯಥಾ {
                ಭಙ್ಗ;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ಯದಿ (pp_ಅಭಿವ್ಯಕ್ತಿ)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ಯದಿ (ucount == 0 && b == 10) {
            ಯದಿ (lcount <= (LONG_SIZE == 4)) {
                ಯದಿ (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            ಯದಿ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } ಅನ್ಯಥಾ {
            ಯದಿ (lcount <= (LONG_SIZE == 4)) {
                ಯದಿ (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                ಅನ್ಯಥಾ ಯದಿ (n >= 0x80000000U)
                    ucount = 1;
            }
            ಯದಿ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ಯದಿ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ಯದಿ (lcount) {
            tok = TOK_CLONG;
            ಯದಿ (lcount == 2)
                tok = TOK_CLLONG;
	}
	ಯದಿ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ಯದಿ (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    ಪಕ್ಷ c1:                                    \
        PEEKC(c, p);                            \
        ಯದಿ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } ಅನ್ಯಥಾ {                                \
            tok = tok1;                         \
        }                                       \
        ಭಙ್ಗ;

/* return next token without macro substitution */
ಸ್ಥಿರ ಶೂನ್ಯ next_nomacro(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned ಪೂರ್ಣಾಙ್ಕ h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    ವಿಕಲ್ಪ(c) {
    ಪಕ್ಷ ' ':
    ಪಕ್ಷ '\t':
        tok = c;
        p++;
 maybe_space:
        ಯದಿ (parse_flags & PARSE_FLAG_SPACES)
            ಗಚ್ಛ keep_tok_flags;
        ಯಾವತ್ (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        ಗಚ್ಛ redo_no_start;
    ಪಕ್ಷ '\f':
    ಪಕ್ಷ '\v':
    ಪಕ್ಷ '\r':
        p++;
        ಗಚ್ಛ redo_no_start;
    ಪಕ್ಷ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ಯದಿ (c == '\\')
            ಗಚ್ಛ parse_simple;
        ಯದಿ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ಯದಿ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                ಗಚ್ಛ maybe_newline;
            } ಅನ್ಯಥಾ ಯದಿ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } ಅನ್ಯಥಾ ಯದಿ (s1->ifdef_ರಾಶಿ_ptr != file->ifdef_ರಾಶಿ_ptr) {
                tcc_error("missing #endif");
            } ಅನ್ಯಥಾ ಯದಿ (s1->include_ರಾಶಿ_ptr == s1->include_ರಾಶಿ) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } ಅನ್ಯಥಾ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ಯದಿ (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ರಿಕ್ತ));
#endif
                    ಹುಡುಕು_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ರಾಶಿ_ptr--;
                p = file->buf_ptr;
                ಗಚ್ಛ maybe_newline;
            }
        } ಅನ್ಯಥಾ {
            ಗಚ್ಛ redo_no_start;
        }
        ಭಙ್ಗ;

    ಪಕ್ಷ '\n':
        file->ಸಾಲು_ಅಂಕೆ++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ಯದಿ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            ಗಚ್ಛ redo_no_start;
        tok = TOK_LINEFEED;
        ಗಚ್ಛ keep_tok_flags;

    ಪಕ್ಷ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ಯದಿ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            ಗಚ್ಛ maybe_newline;
        } ಅನ್ಯಥಾ {
            ಯದಿ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } ಅನ್ಯಥಾ {
#ಯದಿ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_ಸಾಲು_comment(p - 1);
                    ಗಚ್ಛ redo_no_start;
                } ಅನ್ಯಥಾ
#endif
                {
                    tok = '#';
                }
            }
        }
        ಭಙ್ಗ;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    ಪಕ್ಷ '$':
        ಯದಿ (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            ಗಚ್ಛ parse_simple;

    ಪಕ್ಷ 'a': ಪಕ್ಷ 'b': ಪಕ್ಷ 'c': ಪಕ್ಷ 'd':
    ಪಕ್ಷ 'e': ಪಕ್ಷ 'f': ಪಕ್ಷ 'g': ಪಕ್ಷ 'h':
    ಪಕ್ಷ 'i': ಪಕ್ಷ 'j': ಪಕ್ಷ 'k': ಪಕ್ಷ 'l':
    ಪಕ್ಷ 'm': ಪಕ್ಷ 'n': ಪಕ್ಷ 'o': ಪಕ್ಷ 'p':
    ಪಕ್ಷ 'q': ಪಕ್ಷ 'r': ಪಕ್ಷ 's': ಪಕ್ಷ 't':
    ಪಕ್ಷ 'u': ಪಕ್ಷ 'v': ಪಕ್ಷ 'w': ಪಕ್ಷ 'x':
    ಪಕ್ಷ 'y': ಪಕ್ಷ 'z': 
    ಪಕ್ಷ 'A': ಪಕ್ಷ 'B': ಪಕ್ಷ 'C': ಪಕ್ಷ 'D':
    ಪಕ್ಷ 'E': ಪಕ್ಷ 'F': ಪಕ್ಷ 'G': ಪಕ್ಷ 'H':
    ಪಕ್ಷ 'I': ಪಕ್ಷ 'J': ಪಕ್ಷ 'K': 
    ಪಕ್ಷ 'M': ಪಕ್ಷ 'N': ಪಕ್ಷ 'O': ಪಕ್ಷ 'P':
    ಪಕ್ಷ 'Q': ಪಕ್ಷ 'R': ಪಕ್ಷ 'S': ಪಕ್ಷ 'T':
    ಪಕ್ಷ 'U': ಪಕ್ಷ 'V': ಪಕ್ಷ 'W': ಪಕ್ಷ 'X':
    ಪಕ್ಷ 'Y': ಪಕ್ಷ 'Z': 
    ಪಕ್ಷ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ಯಾವತ್ (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ಯದಿ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            ಪ್ರತಿ(;;) {
                ts = *pts;
                ಯದಿ (!ts)
                    ಭಙ್ಗ;
                ಯದಿ (ts->len == len && !memcmp(ts->str, p1, len))
                    ಗಚ್ಛ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (ವರ್ಣ *) p1, len);
        token_found: ;
        } ಅನ್ಯಥಾ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (ವರ್ಣ *) p1, len);
            p--;
            PEEKC(c, p);
            ಯಾವತ್ (isidnum_table[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        ಭಙ್ಗ;
    ಪಕ್ಷ 'L':
        t = p[1];
        ಯದಿ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ಯದಿ (c == '\'' || c == '\"') {
                is_long = 1;
                ಗಚ್ಛ str_const;
            }
            *--p = c = 'L';
        }
        ಗಚ್ಛ parse_ident_fast;

    ಪಕ್ಷ '0': ಪಕ್ಷ '1': ಪಕ್ಷ '2': ಪಕ್ಷ '3':
    ಪಕ್ಷ '4': ಪಕ್ಷ '5': ಪಕ್ಷ '6': ಪಕ್ಷ '7':
    ಪಕ್ಷ '8': ಪಕ್ಷ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_ಅಂಕೆ:
        cstr_reset(&tokcstr);
        ಪ್ರತಿ(;;) {
            cstr_ccat(&tokcstr, t);
            ಯದಿ (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((ವರ್ಣ*)tokcstr.data)[0] == '0'
                                && toup(((ವರ್ಣ*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ಭಙ್ಗ;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        ಭಙ್ಗ;

    ಪಕ್ಷ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ಯದಿ (isnum(c)) {
            t = '.';
            ಗಚ್ಛ parse_ಅಂಕೆ;
        } ಅನ್ಯಥಾ ಯದಿ ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))) {
            *--p = c = '.';
            ಗಚ್ಛ parse_ident_fast;
        } ಅನ್ಯಥಾ ಯದಿ (c == '.') {
            PEEKC(c, p);
            ಯದಿ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } ಅನ್ಯಥಾ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } ಅನ್ಯಥಾ {
            tok = '.';
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ '\'':
    ಪಕ್ಷ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ಯದಿ (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        ಭಙ್ಗ;

    ಪಕ್ಷ '<':
        PEEKC(c, p);
        ಯದಿ (c == '=') {
            p++;
            tok = TOK_LE;
        } ಅನ್ಯಥಾ ಯದಿ (c == '<') {
            PEEKC(c, p);
            ಯದಿ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } ಅನ್ಯಥಾ {
                tok = TOK_SHL;
            }
        } ಅನ್ಯಥಾ {
            tok = TOK_LT;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ '>':
        PEEKC(c, p);
        ಯದಿ (c == '=') {
            p++;
            tok = TOK_GE;
        } ಅನ್ಯಥಾ ಯದಿ (c == '>') {
            PEEKC(c, p);
            ಯದಿ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } ಅನ್ಯಥಾ {
                tok = TOK_SAR;
            }
        } ಅನ್ಯಥಾ {
            tok = TOK_GT;
        }
        ಭಙ್ಗ;
        
    ಪಕ್ಷ '&':
        PEEKC(c, p);
        ಯದಿ (c == '&') {
            p++;
            tok = TOK_LAND;
        } ಅನ್ಯಥಾ ಯದಿ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } ಅನ್ಯಥಾ {
            tok = '&';
        }
        ಭಙ್ಗ;
        
    ಪಕ್ಷ '|':
        PEEKC(c, p);
        ಯದಿ (c == '|') {
            p++;
            tok = TOK_LOR;
        } ಅನ್ಯಥಾ ಯದಿ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } ಅನ್ಯಥಾ {
            tok = '|';
        }
        ಭಙ್ಗ;

    ಪಕ್ಷ '+':
        PEEKC(c, p);
        ಯದಿ (c == '+') {
            p++;
            tok = TOK_INC;
        } ಅನ್ಯಥಾ ಯದಿ (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } ಅನ್ಯಥಾ {
            tok = '+';
        }
        ಭಙ್ಗ;
        
    ಪಕ್ಷ '-':
        PEEKC(c, p);
        ಯದಿ (c == '-') {
            p++;
            tok = TOK_DEC;
        } ಅನ್ಯಥಾ ಯದಿ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } ಅನ್ಯಥಾ ಯದಿ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } ಅನ್ಯಥಾ {
            tok = '-';
        }
        ಭಙ್ಗ;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    ಪಕ್ಷ '/':
        PEEKC(c, p);
        ಯದಿ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            ಗಚ್ಛ maybe_space;
        } ಅನ್ಯಥಾ ಯದಿ (c == '/') {
            p = parse_ಸಾಲು_comment(p);
            tok = ' ';
            ಗಚ್ಛ maybe_space;
        } ಅನ್ಯಥಾ ಯದಿ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } ಅನ್ಯಥಾ {
            tok = '/';
        }
        ಭಙ್ಗ;
        
        /* simple tokens */
    ಪಕ್ಷ '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_ಸಾಲು_comment(p);
            ಗಚ್ಛ redo_no_start;
        }
#endif
    ಪಕ್ಷ '(':
    ಪಕ್ಷ ')':
    ಪಕ್ಷ '[':
    ಪಕ್ಷ ']':
    ಪಕ್ಷ '{':
    ಪಕ್ಷ '}':
    ಪಕ್ಷ ',':
    ಪಕ್ಷ ';':
    ಪಕ್ಷ ':':
    ಪಕ್ಷ '?':
    ಪಕ್ಷ '~':
    parse_simple:
        tok = c;
        p++;
        ಭಙ್ಗ;
    ಪಕ್ಷ 0xEF: /* UTF8 BOM ? */
        ಯದಿ (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            ಗಚ್ಛ redo_no_start;
        }
    ಸ್ವಭಾವ:
        ಯದಿ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    ಗಚ್ಛ parse_ident_fast;
        ಯದಿ (parse_flags & PARSE_FLAG_ASM_FILE)
            ಗಚ್ಛ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ಭಙ್ಗ;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ಯದಿ defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ indent;
ಸ್ಥಿರ ಶೂನ್ಯ define_print(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ v);
ಸ್ಥಿರ ಶೂನ್ಯ pp_print(ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ, ಪೂರ್ಣಾಙ್ಕ v, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *str)
{
    FILE *fp = tcc_state->ppfp;

    ಯದಿ (ಸಂದೇಶ[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    ಅನ್ಯಥಾ ಯದಿ (ಸಂದೇಶ[0] == '+')
         ++indent, ++ಸಂದೇಶ;
    ಅನ್ಯಥಾ ಯದಿ (ಸಂದೇಶ[0] == '-')
        --indent, ++ಸಂದೇಶ;

    fprintf(fp, "%*s", indent, "");
    ಯದಿ (ಸಂದೇಶ[0] == '#') {
        define_print(tcc_state, v);
    } ಅನ್ಯಥಾ {
        tok_print(str, v ? "%s %s" : "%s", ಸಂದೇಶ, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#ಅನ್ಯಥಾ
#define PP_PRINT(x)
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ *macro_arg_subst(Sym **nested_list, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *macro_str, Sym *args)
{
    ಪೂರ್ಣಾಙ್ಕ t, t0, t1, t2, n;
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    ಪ್ರತಿ (s = args, n = 0; s; s = s->prev, ++n);
    ಯಾವತ್ (n--) {
        ಪ್ರತಿ (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    ಯಾವತ್(1) {
        TOK_GET(&t, &macro_str, &cval);
        ಯದಿ (!t)
            ಭಙ್ಗ;
        ಯದಿ (t == '#') {
            /* stringize */
            ಕುರು t = *macro_str++; ಯಾವತ್ (t == ' ');
            s = sym_find2(args, t);
            ಯದಿ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ಯಾವತ್ (*st != TOK_EOF) {
                    ಧ್ರುವ ವರ್ಣ *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ಯಾವತ್ (*s) {
                        ಯದಿ (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        ಅನ್ಯಥಾ
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
            } ಅನ್ಯಥಾ ಯದಿ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } ಅನ್ಯಥಾ {
                expect("macro parameter after '#'");
            }
        } ಅನ್ಯಥಾ ಯದಿ (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            ಯದಿ (s) {
                st = s->d;
                n = 0;
                ಯಾವತ್ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ಯದಿ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ಯದಿ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ಪೂರ್ಣಾಙ್ಕ c = str.str[str.len - 1];
                        ಯಾವತ್ (str.str[--str.len] != ',')
                            ;
                        ಯದಿ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } ಅನ್ಯಥಾ {
                            /* suppress '##' and add variable */
                            str.len++;
                            ಯದಿ (c == ' ')
                                str.str[str.len++] = c;
                            ಗಚ್ಛ add_var;
                        }
                    } ಅನ್ಯಥಾ {
                        ಯದಿ (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } ಅನ್ಯಥಾ {
            add_var:
		    ಯದಿ (!s->e) {
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
                ಯಾವತ್ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } ಅನ್ಯಥಾ {
                tok_str_add(&str, t);
            }
        } ಅನ್ಯಥಾ {
            tok_str_add2(&str, t, &cval);
        }
        ಯದಿ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ಪ್ರತ್ಯಾಗಮ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಪೂರ್ಣಾಙ್ಕ *macro_twosharps(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *ptr0)
{
    ಪೂರ್ಣಾಙ್ಕ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    ಪ್ರತಿ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ಯದಿ (t1 == 0)
            ಭಙ್ಗ;
        ಪ್ರತಿ (;;) {
            n = 0;
            ಯಾವತ್ ((t2 = ptr[n]) == ' ')
                ++n;
            ಯದಿ (t2 != TOK_PPJOIN)
                ಭಙ್ಗ;
            ptr += n;
            ಯಾವತ್ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ಯದಿ (t2 == TOK_PLCHLDR)
                ಅನುವರ್ತ;
            ಯದಿ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ಯದಿ (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            ಪ್ರತಿ (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ಯದಿ (*file->buf_ptr == 0)
                    ಭಙ್ಗ;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ಯದಿ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ಪ್ರತ್ಯಾಗಮ macro_str1.str;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ಪೂರ್ಣಾಙ್ಕ c;
    ಪ್ರತಿ (;;) {
        PEEKC(c, p);
        ವಿಕಲ್ಪ (c) {
        ಪಕ್ಷ '/':
            PEEKC(c, p);
            ಯದಿ (c == '*')
                p = parse_comment(p);
            ಅನ್ಯಥಾ ಯದಿ (c == '/')
                p = parse_ಸಾಲು_comment(p);
            ಅನ್ಯಥಾ {
                c = *--p = '/';
                ಗಚ್ಛ leave;
            }
            --p, c = ' ';
            ಭಙ್ಗ;
        ಪಕ್ಷ ' ': ಪಕ್ಷ '\t':
            ಭಙ್ಗ;
        ಪಕ್ಷ '\f': ಪಕ್ಷ '\v': ಪಕ್ಷ '\r':
            ಅನುವರ್ತ;
        ಪಕ್ಷ '\n':
            file->ಸಾಲು_ಅಂಕೆ++, tok_flags |= TOK_FLAG_BOL;
            ಭಙ್ಗ;
        ಸ್ವಭಾವ: leave:
            file->buf_ptr = p;
            ಪ್ರತ್ಯಾಗಮ c;
        }
        ಯದಿ (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ next_argstream(Sym **nested_list, TokenString *ws_str)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    Sym *sa;

    ಯಾವತ್ (macro_ptr) {
        ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *m = macro_ptr;
        ಯಾವತ್ ((t = *m) != 0) {
            ಯದಿ (ws_str) {
                ಯದಿ (t != ' ')
                    ಪ್ರತ್ಯಾಗಮ t;
                ++m;
            } ಅನ್ಯಥಾ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ಪ್ರತ್ಯಾಗಮ tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ಯದಿ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ಯದಿ (ws_str) {
        ಪ್ರತ್ಯಾಗಮ peek_file(ws_str);
    } ಅನ್ಯಥಾ {
        next_nomacro();
        ಯದಿ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ಪ್ರತ್ಯಾಗಮ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    ಪೂರ್ಣಾಙ್ಕ v = s->v;

    PP_PRINT(("#", v, s->d));
    ಯದಿ (s->d) {
        ಪೂರ್ಣಾಙ್ಕ *mstr = s->d;
        ಪೂರ್ಣಾಙ್ಕ *jstr;
        Sym *sa;
        ಪೂರ್ಣಾಙ್ಕ ret;

        ಯದಿ (s->type.t & MACRO_FUNC) {
            ಪೂರ್ಣಾಙ್ಕ saved_parse_flags = parse_flags;
            TokenString str;
            ಪೂರ್ಣಾಙ್ಕ parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            ಯದಿ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ಯದಿ (parse_flags & PARSE_FLAG_SPACES)
                    ಪ್ರತಿ (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ಪ್ರತ್ಯಾಗಮ 0;
            } ಅನ್ಯಥಾ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = ರಿಕ್ತ;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            ಪ್ರತಿ(;;) {
                ಕುರು {
                    t = next_argstream(nested_list, ರಿಕ್ತ);
                } ಯಾವತ್ (t == ' ' || --i);

                ಯದಿ (!sa) {
                    ಯದಿ (t == ')') /* handle '()' case */
                        ಭಙ್ಗ;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ಯಾವತ್ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ಯದಿ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ಯದಿ (t == '(')
                        parlevel++;
                    ಯದಿ (t == ')')
                        parlevel--;
                    ಯದಿ (t == ' ')
                        str.need_spc |= 1;
                    ಅನ್ಯಥಾ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, ರಿಕ್ತ);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                ಯದಿ (t == ')') {
                    ಯದಿ (!sa)
                        ಭಙ್ಗ;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ಯದಿ (sa->type.t && gnu_ext)
                        ಗಚ್ಛ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            ಯಾವತ್ (sa) {
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
        ಯದಿ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ಯದಿ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ಯದಿ (jstr != mstr)
            tok_str_free_str(jstr);
        ಯದಿ (mstr != s->d)
            tok_str_free_str(mstr);
        ಪ್ರತ್ಯಾಗಮ ret;

    } ಅನ್ಯಥಾ {
        CValue cval;
        ವರ್ಣ buf[32], *cstrval = buf;

        /* special macros */
        ಯದಿ (v == TOK_ಸಾಲು_2 || v == TOK___COUNTER__) {
            t = v == TOK_ಸಾಲು_2 ? file->ಸಾಲು_ಅಂಕೆ : pp_counter++;
            snprintf(buf, ಪರಿಮಾಣ(buf), "%d", t);
            t = TOK_PPNUM;
            ಗಚ್ಛ add_cstr1;

        } ಅನ್ಯಥಾ ಯದಿ (v == TOK___FILE__) {
            cstrval = file->filename;
            ಗಚ್ಛ add_cstr;

        } ಅನ್ಯಥಾ ಯದಿ (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            ಸಂರಚನಾ tm *tm;
            time(&ti);
            tm = localtime(&ti);
            ಯದಿ (v == TOK___DATE__) {
                ಸ್ಥಿರ ವರ್ಣ ಧ್ರುವ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, ಪರಿಮಾಣ(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } ಅನ್ಯಥಾ {
                snprintf(buf, ಪರಿಮಾಣ(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ಪ್ರತ್ಯಾಗಮ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *macro_str
    )
{
    Sym *s;
    ಪೂರ್ಣಾಙ್ಕ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    ಪೂರ್ಣಾಙ್ಕ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    ಯಾವತ್ (1) {
        TOK_GET(&t, &macro_str, &cval);
        ಯದಿ (t == 0 || t == TOK_EOF)
            ಭಙ್ಗ;
        ಯದಿ (t >= TOK_IDENT) {
            s = define_find(t);
            ಯದಿ (s == ರಿಕ್ತ || nosubst)
                ಗಚ್ಛ no_subst;
            /* if nested substitution, do nothing */
            ಯದಿ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                ಗಚ್ಛ no_subst;
            }
            str = tok_str_alloc();
            str->str = (ಪೂರ್ಣಾಙ್ಕ*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ಯದಿ (macro_ರಾಶಿ != str) {
                /* already finished by reading function macro arguments */
                ಭಙ್ಗ;
            }
            macro_str = macro_ptr;
            end_macro ();
        } ಅನ್ಯಥಾ ಯದಿ (t == ' ') {
            ಯದಿ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } ಅನ್ಯಥಾ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ಯದಿ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ಯದಿ (t == TOK_DEFINED && pp_ಅಭಿವ್ಯಕ್ತಿ)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ಪ್ರತ್ಯಾಗಮ nosubst;
}

/* return next token with macro substitution */
ST_FUNC ಶೂನ್ಯ next(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ t;
    ಯಾವತ್ (macro_ptr) {
redo:
        t = *macro_ptr;
        ಯದಿ (TOK_HAS_ಮೌಲ್ಯ(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ಯದಿ (t == TOK_LINENUM) {
                file->ಸಾಲು_ಅಂಕೆ = tokc.i;
                ಗಚ್ಛ redo;
            }
            ಗಚ್ಛ convert;
        } ಅನ್ಯಥಾ ಯದಿ (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            ಅನುವರ್ತ;
        } ಅನ್ಯಥಾ ಯದಿ (t == TOK_EOF) {
            /* do nothing */
        } ಅನ್ಯಥಾ {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            ಯದಿ (t == '\\') {
                ಯದಿ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ಪ್ರತ್ಯಾಗಮ;
    }

    next_nomacro();
    t = tok;
    ಯದಿ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        ಯದಿ (s) {
            Sym *nested_list = ರಿಕ್ತ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            ಗಚ್ಛ redo;
        }
        ಪ್ರತ್ಯಾಗಮ;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ಯದಿ (t == TOK_PPNUM) {
        ಯದಿ  (parse_flags & PARSE_FLAG_TOK_ಅಂಕೆ)
            parse_ಸಂಖ್ಯೆ(tokc.str.data);
    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_PPSTR) {
        ಯದಿ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN ಶೂನ್ಯ unget_tok(ಪೂರ್ಣಾಙ್ಕ last_tok)
{
    TokenString *str = &unget_buf;
    ಪೂರ್ಣಾಙ್ಕ alloc = 0;
    ಯದಿ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ಯದಿ (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# ಯದಿ PTR_SIZE == 8
    "_WIN64\0"
# endif
#ಅನ್ಯಥಾ
# ಯದಿ defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# ಅನ್ಯಥಾ
    "__linux__\0"
    "__linux\0"
#  ಯದಿ TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

ಸ್ಥಿರ ಶೂನ್ಯ putdef(CString *cs, ಧ್ರುವ ವರ್ಣ *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ಸ್ಥಿರ ಶೂನ್ಯ putdefs(CString *cs, ಧ್ರುವ ವರ್ಣ *p)
{
    ಯಾವತ್ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_predefs(TCCState *s1, CString *cs, ಪೂರ್ಣಾಙ್ಕ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    ಯದಿ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    ಯದಿ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ಯದಿ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    ಯದಿ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    ಯದಿ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ಯದಿ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ಯದಿ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ಯದಿ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    ಯದಿ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ಯದಿ CONFIG_TCC_PREDEFS
        #ಅನ್ತರ್ಭಾವ "tccdefs_.h" /* include as strings */
#ಅನ್ಯಥಾ
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC ಶೂನ್ಯ preprocess_start(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ filetype)
{
    ಪೂರ್ಣಾಙ್ಕ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ರಾಶಿ_ptr = s1->include_ರಾಶಿ;
    s1->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ;
    file->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ_ptr;
    pp_ಅಭಿವ್ಯಕ್ತಿ = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ರಾಶಿ[0] = 0;
    s1->pack_ರಾಶಿ_ptr = s1->pack_ರಾಶಿ;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    ಯದಿ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ಯದಿ (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        ಯದಿ (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ರಾಶಿ_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC ಶೂನ್ಯ preprocess_end(TCCState *s1)
{
    ಯಾವತ್ (macro_ರಾಶಿ)
        end_macro();
    macro_ptr = ರಿಕ್ತ;
    ಯಾವತ್ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ set_idnum(ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ val)
{
    ಪೂರ್ಣಾಙ್ಕ prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ಪ್ರತ್ಯಾಗಮ prev;
}

ST_FUNC ಶೂನ್ಯ tccpp_new(TCCState *s)
{
    ಪೂರ್ಣಾಙ್ಕ i, c;
    ಧ್ರುವ ವರ್ಣ *p, *r;

    /* init isid table */
    ಪ್ರತಿ(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_ಅಂಕೆ
            : 0);

    ಪ್ರತಿ(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * ಪರಿಮಾಣ(TokenSym *));
    memset(s->cached_includes_hash, 0, ಪರಿಮಾಣ s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ಯಾವತ್ (*p) {
        r = p;
        ಪ್ರತಿ(;;) {
            c = *r++;
            ಯದಿ (c == '\0')
                ಭಙ್ಗ;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ತಳ್ಳು(TOK_ಸಾಲು_2, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
    define_ತಳ್ಳು(TOK___FILE__, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
    define_ತಳ್ಳು(TOK___DATE__, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
    define_ತಳ್ಳು(TOK___TIME__, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
    define_ತಳ್ಳು(TOK___COUNTER__, MACRO_OBJ, ರಿಕ್ತ, ರಿಕ್ತ);
}

ST_FUNC ಶೂನ್ಯ tccpp_delete(TCCState *s)
{
    ಪೂರ್ಣಾಙ್ಕ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ಯದಿ (n > total_idents)
        total_idents = n;
    ಪ್ರತಿ (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ರಿಕ್ತ;

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

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pp_need_space(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b);

ಸ್ಥಿರ ಶೂನ್ಯ tok_print(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *str, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ಪೂರ್ಣಾಙ್ಕ t, t0, s;
    CValue cval;

    va_start(ap, ಸಂದೇಶ);
    vfprintf(fp, ಸಂದೇಶ, ap);
    va_end(ap);

    s = t0 = 0;
    ಯಾವತ್ (str) {
	TOK_GET(&t, &str, &cval);
	ಯದಿ (t == 0 || t == TOK_EOF)
	    ಭಙ್ಗ;
        ಯದಿ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ಸ್ಥಿರ ಶೂನ್ಯ pp_ಸಾಲು(TCCState *s1, BufferedFile *f, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಪೂರ್ಣಾಙ್ಕ d = f->ಸಾಲು_ಅಂಕೆ - f->ಸಾಲು_ref;

    ಯದಿ (s1->dflag & 4)
	ಪ್ರತ್ಯಾಗಮ;

    ಯದಿ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } ಅನ್ಯಥಾ ಯದಿ (level == 0 && f->ಸಾಲು_ref && d < 8) {
	ಯಾವತ್ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } ಅನ್ಯಥಾ ಯದಿ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->ಸಾಲು_ಅಂಕೆ, f->filename);
    } ಅನ್ಯಥಾ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->ಸಾಲು_ಅಂಕೆ, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->ಸಾಲು_ref = f->ಸಾಲು_ಅಂಕೆ;
}

ಸ್ಥಿರ ಶೂನ್ಯ define_print(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    ಯದಿ (ರಿಕ್ತ == s || ರಿಕ್ತ == s->d)
        ಪ್ರತ್ಯಾಗಮ;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ರಿಕ್ತ));
    ಯದಿ (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        ಯದಿ (a)
            ಪ್ರತಿ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ರಿಕ್ತ));
                ಯದಿ (!(a = a->next))
                    ಭಙ್ಗ;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ಸ್ಥಿರ ಶೂನ್ಯ pp_debug_defines(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ v, t;
    ಧ್ರುವ ವರ್ಣ *vs;
    FILE *fp;

    t = pp_debug_tok;
    ಯದಿ (t == 0)
        ಪ್ರತ್ಯಾಗಮ;

    file->ಸಾಲು_ಅಂಕೆ--;
    pp_ಸಾಲು(s1, file, 0);
    file->ಸಾಲು_ref = ++file->ಸಾಲು_ಅಂಕೆ;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ರಿಕ್ತ);
    ಯದಿ (t == TOK_DEFINE) {
        define_print(s1, v);
    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_ತಳ್ಳು_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } ಅನ್ಯಥಾ ಯದಿ (t == TOK_ತೆಗೆ_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pp_need_space(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಪ್ರತ್ಯಾಗಮ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ pp_check_he0xE(ಪೂರ್ಣಾಙ್ಕ t, ಧ್ರುವ ವರ್ಣ *p)
{
    ಯದಿ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ಪ್ರತ್ಯಾಗಮ 'E';
    ಪ್ರತ್ಯಾಗಮ t;
}

/* Preprocess the current file */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ಪೂರ್ಣಾಙ್ಕ token_seen, spcs, level;
    ಧ್ರುವ ವರ್ಣ *p;
    ವರ್ಣ white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ಯದಿ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_ಅಂಕೆ, s1->Pflag = 1;

    ಯದಿ (s1->do_bench) {
	/* for PP benchmarks */
	ಕುರು next(); ಯಾವತ್ (tok != TOK_EOF);
	ಪ್ರತ್ಯಾಗಮ 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    ಯದಿ (file->prev)
        pp_ಸಾಲು(s1, file->prev, level++);
    pp_ಸಾಲು(s1, file, level);

    ಪ್ರತಿ (;;) {
        iptr = s1->include_ರಾಶಿ_ptr;
        next();
        ಯದಿ (tok == TOK_EOF)
            ಭಙ್ಗ;

        level = s1->include_ರಾಶಿ_ptr - iptr;
        ಯದಿ (level) {
            ಯದಿ (level > 0)
                pp_ಸಾಲು(s1, *iptr, 0);
            pp_ಸಾಲು(s1, file, level);
        }
        ಯದಿ (s1->dflag & 7) {
            pp_debug_defines(s1);
            ಯದಿ (s1->dflag & 4)
                ಅನುವರ್ತ;
        }

        ಯದಿ (is_space(tok)) {
            ಯದಿ (spcs < ಪರಿಮಾಣ white - 1)
                white[spcs++] = tok;
            ಅನುವರ್ತ;
        } ಅನ್ಯಥಾ ಯದಿ (tok == TOK_LINEFEED) {
            spcs = 0;
            ಯದಿ (token_seen == TOK_LINEFEED)
                ಅನುವರ್ತ;
            ++file->ಸಾಲು_ref;
        } ಅನ್ಯಥಾ ಯದಿ (token_seen == TOK_LINEFEED) {
            pp_ಸಾಲು(s1, file, 0);
        } ಅನ್ಯಥಾ ಯದಿ (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ------------------------------------------------------------------------- */
