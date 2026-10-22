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

#ವ್ಯಾಖ್ಯಾನಿಸು USING_GLOBALS
#ಅನ್ತರ್ಭಾವ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#ವ್ಯಾಖ್ಯಾನಿಸು ACCEPT_LF_ಒಳ_ಅಕ್ಷರಸರಣಿಗಳು 0

/********************************************************/
/* global variables */

ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok_flags;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ parse_flags;

ST_ದತ್ತಾಂಶ ರಚನೆ BufferedFile *file;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok;
ST_ದತ್ತಾಂಶ CValue tokc;
ST_ದತ್ತಾಂಶ ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *macro_ptr;
ST_ದತ್ತಾಂಶ CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ tok_ident;
ST_ದತ್ತಾಂಶ TokenSym **ಕೋಷ್ಟಕ_ident;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ pp_ಅಭಿವ್ಯಕ್ತಿ;

/* ------------------------------------------------------------------------- */

ಸ್ಥಿರ TokenSym *hash_ident[TOK_HASH_ಗಾತ್ರ];
ಸ್ಥಿರ ಅಕ್ಷರ token_buf[STRING_MAX_ಗಾತ್ರ + 1];
ಸ್ಥಿರ CString cstr_buf;
ಸ್ಥಿರ TokenString tokstr_buf;
ಸ್ಥಿರ TokenString unget_buf;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ isidnum_ಕೋಷ್ಟಕ[256 - CH_EOF];
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pp_debug_tok, pp_debug_symv;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pp_counter;
ಸ್ಥಿರ ಶೂನ್ಯ tok_print(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, ...);
ಸ್ಥಿರ ಶೂನ್ಯ ಮುಂದಿನ_nomacro(ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಸಂಖ್ಯೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p);
ಸ್ಥಿರ ಶೂನ್ಯ parse_string(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, ಪೂರ್ಣಾಂಕ len);

ಸ್ಥಿರ ರಚನೆ TinyAlloc *toksym_alloc;
ಸ್ಥಿರ ರಚನೆ TinyAlloc *tokstr_alloc;

ಸ್ಥಿರ TokenString *macro_ರಾಶಿ;

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ tcc_keywords[] = 
#ವ್ಯಾಖ್ಯಾನಿಸು DEF(id, str) str "\0"
#ಅನ್ತರ್ಭಾವ "tcctok.h"
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DEF
;

/* WARNING: the content of this string encodes token numbers */
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ tok_two_chars[] =
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
    '+','=', TOK_A_ಕೂಡಿಸು,
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

ST_FUNC ಶೂನ್ಯ skip(ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (tok != c) {
        ಅಕ್ಷರ tmp[40];
        pstrcpy(tmp, ಗಾತ್ರ tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    ಮುಂದಿನ();
}

ST_FUNC ಶೂನ್ಯ expect(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
    tcc_error("%s expected", ಸಂದೇಶ);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#ವ್ಯಾಖ್ಯಾನಿಸು USE_TAL

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ USE_TAL /* may cause memory leaks after errors */
#ವ್ಯಾಖ್ಯಾನಿಸು tal_free(al, p) tcc_free(p)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_realloc(al, p, ಗಾತ್ರ_2) tcc_realloc(p, ಗಾತ್ರ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_new(a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_delete(a)
#ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ !defined(MEM_DEBUG)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_free(al, p) tal_free_impl(al, p)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_realloc(al, p, ಗಾತ್ರ_2) tal_realloc_impl(al, p, ಗಾತ್ರ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು TAL_DEBUG_PARAMS
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#ವ್ಯಾಖ್ಯಾನಿಸು tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tal_realloc(al, p, ಗಾತ್ರ_2) tal_realloc_impl(al, p, ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು TAL_DEBUG_PARAMS , ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sfile, ಪೂರ್ಣಾಂಕ sline
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು TOKSYM_TAL_ಗಾತ್ರ (256 * 1024) /* allocator for TokenSym in table_ident */
#ವ್ಯಾಖ್ಯಾನಿಸು TOKSTR_TAL_ಗಾತ್ರ (256 * 1024) /* allocator for TokenString instances */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ರಚನೆ TinyAlloc *ಮುಂದಿನ;
    ಚಿಹ್ನೆರಹಿತ nb_allocs;
    ಚಿಹ್ನೆರಹಿತ ಗಾತ್ರ_2;
#ಆದರೆ TAL_INFO
    ಚಿಹ್ನೆರಹಿತ nb_peak;
    ಚಿಹ್ನೆರಹಿತ nb_ಒಟ್ಟು;
    uint8_t *peak_p;
#ಆದರೆ_ಅಂತ್ಯ
    ಒಕ್ಕೂಟ {
        uint8_t ಬಫರ್[1];
        ಗಾತ್ರ_t _aligner_;
    };
} TinyAlloc;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ tal_ಶೀರ್ಷಿಕೆ_t {
    ಗಾತ್ರ_t  ಗಾತ್ರ_2; /* word align */
#ಆದರೆ TAL_DEBUG
    ಪೂರ್ಣಾಂಕ     ಸಾಲು_ಅಂಕೆ; /* negative line_num used for double free check */
    ಅಕ್ಷರ    file_name[40];
#ಆದರೆ_ಅಂತ್ಯ
} tal_ಶೀರ್ಷಿಕೆ_t;

#ವ್ಯಾಖ್ಯಾನಿಸು TAL_ALIGN(ಗಾತ್ರ_2) \
    (((ಗಾತ್ರ_2) + (ಗಾತ್ರ (ಗಾತ್ರ_t) - 1)) & ~(ಗಾತ್ರ (ಗಾತ್ರ_t) - 1))

/* ------------------------------------------------------------------------- */

ಸ್ಥಿರ TinyAlloc *tal_new(TinyAlloc **pal, ಚಿಹ್ನೆರಹಿತ ಗಾತ್ರ_2)
{
    TinyAlloc *al = tcc_malloc(ಗಾತ್ರ(TinyAlloc) - ಗಾತ್ರ (ಗಾತ್ರ_t) + ಗಾತ್ರ_2);
    al->p = al->ಬಫರ್;
    al->bufend = al->ಬಫರ್ + ಗಾತ್ರ_2;
    al->nb_allocs = 0;
    al->ಮುಂದಿನ = *pal, *pal = al;
    al->ಗಾತ್ರ_2 = al->ಮುಂದಿನ ? al->ಮುಂದಿನ->ಗಾತ್ರ_2 : ಗಾತ್ರ_2;
#ಆದರೆ TAL_INFO
    al->nb_peak = 0;
    al->nb_ಒಟ್ಟು = 0;
    al->peak_p = al->p;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ al;
}

ಸ್ಥಿರ ಶೂನ್ಯ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *ಮುಂದಿನ;

#ಆದರೆ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#ಆದರೆ_ಅಂತ್ಯ
ಬಾಲ_call:
#ಆದರೆ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ಆದರೆ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->ಬಫರ್, al->nb_peak, al->nb_ಒಟ್ಟು,
            (al->peak_p - al->ಬಫರ್) * 100.0 / (al->bufend - al->ಬಫರ್));
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->ಬಫರ್;
        ಆಗ (p < al->p) {
            tal_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ = (tal_ಶೀರ್ಷಿಕೆ_t *)p;
            ಆದರೆ (ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        ಶೀರ್ಷಿಕೆ->file_name, ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ, (ಪೂರ್ಣಾಂಕ)ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2);
            }
            p += ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 + ಗಾತ್ರ(tal_ಶೀರ್ಷಿಕೆ_t);
        }
#ಆದರೆ TAL_DEBUG == 2
        ನಿರ್ಗಮಿಸು(2);
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಮುಂದಿನ = al->ಮುಂದಿನ;
    tcc_free(al);
    al = ಮುಂದಿನ;
    ಆದರೆ (al)
        ಹೋಗು ಬಾಲ_call;
    *pal = al;
}

ಸ್ಥಿರ ಶೂನ್ಯ tal_free_impl(TinyAlloc **pal, ಶೂನ್ಯ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **ತುದಿ = pal;
    tal_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ;

    ಆದರೆ (!p)
        ಹಿಂತಿರುಗಿ;
    ಶೀರ್ಷಿಕೆ = (tal_ಶೀರ್ಷಿಕೆ_t *)p - 1;
#ಆದರೆ TAL_DEBUG
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                ಶೀರ್ಷಿಕೆ->file_name, (ಪೂರ್ಣಾಂಕ)-ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ, (ಪೂರ್ಣಾಂಕ)ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2);
    } ಇಲ್ಲದಿದ್ದರೆ
        ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ = -ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ;
#ಆದರೆ_ಅಂತ್ಯ
    al = *pal;
    ಆಗ ((uint8_t*)p < al->ಬಫರ್ || (uint8_t*)p > al->bufend)
        al = *(pal = &al->ಮುಂದಿನ);
    ಆದರೆ (0 == --al->nb_allocs) {
        *pal = al->ಮುಂದಿನ;
        ಆದರೆ ((al->bufend - al->ಬಫರ್) > al->ಗಾತ್ರ_2) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* reset and move to front */
            al->p = al->ಬಫರ್;
            al->ಮುಂದಿನ = *ತುದಿ, *ತುದಿ = al;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((uint8_t*)p + ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 == al->p) {
        al->p = (uint8_t*)ಶೀರ್ಷಿಕೆ;
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ *tal_realloc_impl(TinyAlloc **pal, ಶೂನ್ಯ *p, ಚಿಹ್ನೆರಹಿತ ಗಾತ್ರ_2 TAL_DEBUG_PARAMS)
{
    tal_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ;
    ಶೂನ್ಯ *ret;
    ಚಿಹ್ನೆರಹಿತ adj_ಗಾತ್ರ = TAL_ALIGN(ಗಾತ್ರ_2) + ಗಾತ್ರ(tal_ಶೀರ್ಷಿಕೆ_t);
    TinyAlloc *al = *pal;

    ಆದರೆ (p) {
        /* reallpc case */
        ಆಗ ((uint8_t*)p < al->ಬಫರ್ || (uint8_t*)p > al->bufend)
            al = al->ಮುಂದಿನ;
        ಶೀರ್ಷಿಕೆ = (tal_ಶೀರ್ಷಿಕೆ_t *)p - 1;
        ಆದರೆ ((uint8_t*)p + ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 == al->p)
            al->p = (uint8_t*)ಶೀರ್ಷಿಕೆ; /* maybe reuse */
        ಆದರೆ (al->p + adj_ಗಾತ್ರ > al->bufend) {
            ret = tal_realloc(pal, 0, ಗಾತ್ರ_2);
            ಸ್ಮರಣೆ_ನಕಲು(ret, p, ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2);
            tal_free(pal, p);
            ಹಿಂತಿರುಗಿ ret;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (al->p != (uint8_t*)ಶೀರ್ಷಿಕೆ) {
            ಸ್ಮರಣೆ_ನಕಲು((tal_ಶೀರ್ಷಿಕೆ_t*)al->p + 1, p, ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2);
#ಆದರೆ TAL_DEBUG
            ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ = -ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ;
#ಆದರೆ_ಅಂತ್ಯ
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* new alloc case */
        ಆಗ (al->p + adj_ಗಾತ್ರ > al->bufend) {
            al = al->ಮುಂದಿನ;
            ಆದರೆ (!al) {
                ಚಿಹ್ನೆರಹಿತ new_ಗಾತ್ರ = (*pal)->ಗಾತ್ರ_2;
                ಆದರೆ (adj_ಗಾತ್ರ > new_ಗಾತ್ರ) {
                    new_ಗಾತ್ರ = adj_ಗಾತ್ರ;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_ಗಾತ್ರ);
                ನಿಲ್ಲಿಸು;
            }
        }
        al->nb_allocs++;
    }
    ಶೀರ್ಷಿಕೆ = (tal_ಶೀರ್ಷಿಕೆ_t *)al->p;
    ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 = adj_ಗಾತ್ರ - ಗಾತ್ರ(tal_ಶೀರ್ಷಿಕೆ_t);
    al->p += adj_ಗಾತ್ರ;
    ret = ಶೀರ್ಷಿಕೆ + 1;
#ಆದರೆ  TAL_DEBUG
    {
        ಪೂರ್ಣಾಂಕ ofs = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(sfile) + 1 - ಗಾತ್ರ ಶೀರ್ಷಿಕೆ->file_name;
        strcpy(ಶೀರ್ಷಿಕೆ->file_name, sfile + (ofs > 0 ? ofs : 0));
        ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ = sline;
#ಆದರೆ TAL_INFO
        ಆದರೆ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ಆದರೆ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_ಒಟ್ಟು++;
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ ret;
}

#ಆದರೆ_ಅಂತ್ಯ /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ಸ್ಥಿರ ಶೂನ್ಯ cstr_realloc(CString *cstr, ಪೂರ್ಣಾಂಕ new_ಗಾತ್ರ)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;

    ಗಾತ್ರ_2 = cstr->ಗಾತ್ರ_allocated;
    ಆದರೆ (ಗಾತ್ರ_2 < 8)
        ಗಾತ್ರ_2 = 8; /* no need to allocate a too small first string */
    ಆಗ (ಗಾತ್ರ_2 < new_ಗಾತ್ರ)
        ಗಾತ್ರ_2 = ಗಾತ್ರ_2 * 2;
    cstr->ದತ್ತಾಂಶ = tcc_realloc(cstr->ದತ್ತಾಂಶ, ಗಾತ್ರ_2);
    cstr->ಗಾತ್ರ_allocated = ಗಾತ್ರ_2;
}

/* add a byte */
ST_INLN ಶೂನ್ಯ cstr_ccat(CString *cstr, ಪೂರ್ಣಾಂಕ ch)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;
    ಗಾತ್ರ_2 = cstr->ಗಾತ್ರ_2 + 1;
    ಆದರೆ (ಗಾತ್ರ_2 > cstr->ಗಾತ್ರ_allocated)
        cstr_realloc(cstr, ಗಾತ್ರ_2);
    cstr->ದತ್ತಾಂಶ[ಗಾತ್ರ_2 - 1] = ch;
    cstr->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
}

ST_INLN ಅಕ್ಷರ *unicode_ಗಮ್ಯ_utf8 (ಅಕ್ಷರ *b, uint32_t Uc)
{
    ಆದರೆ (Uc<0x80) *b++=Uc;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (Uc-0xd800u<0x800) ಹೋಗು error;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ಇಲ್ಲದಿದ್ದರೆ error: tcc_error("0x%x is not a valid universal character", Uc);
    ಹಿಂತಿರುಗಿ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN ಶೂನ್ಯ cstr_u8cat(CString *cstr, ಪೂರ್ಣಾಂಕ ch)
{
    ಅಕ್ಷರ buf[4], *e;
    e = unicode_ಗಮ್ಯ_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC ಶೂನ್ಯ cstr_cat(CString *cstr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;
    ಆದರೆ (len <= 0)
        len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str) + 1 + len;
    ಗಾತ್ರ_2 = cstr->ಗಾತ್ರ_2 + len;
    ಆದರೆ (ಗಾತ್ರ_2 > cstr->ಗಾತ್ರ_allocated)
        cstr_realloc(cstr, ಗಾತ್ರ_2);
    memmove(cstr->ದತ್ತಾಂಶ + cstr->ಗಾತ್ರ_2, str, len);
    cstr->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
}

/* add a wide char */
ST_FUNC ಶೂನ್ಯ cstr_wccat(CString *cstr, ಪೂರ್ಣಾಂಕ ch)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2;
    ಗಾತ್ರ_2 = cstr->ಗಾತ್ರ_2 + ಗಾತ್ರ(nwchar_t);
    ಆದರೆ (ಗಾತ್ರ_2 > cstr->ಗಾತ್ರ_allocated)
        cstr_realloc(cstr, ಗಾತ್ರ_2);
    *(nwchar_t *)(cstr->ದತ್ತಾಂಶ + ಗಾತ್ರ_2 - ಗಾತ್ರ(nwchar_t)) = ch;
    cstr->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
}

ST_FUNC ಶೂನ್ಯ cstr_new(CString *cstr)
{
    memset(cstr, 0, ಗಾತ್ರ(CString));
}

/* free string and reset it to NULL */
ST_FUNC ಶೂನ್ಯ cstr_free(CString *cstr)
{
    tcc_free(cstr->ದತ್ತಾಂಶ);
}

/* reset string to empty */
ST_FUNC ಶೂನ್ಯ cstr_reset(CString *cstr)
{
    cstr->ಗಾತ್ರ_2 = 0;
}

ST_FUNC ಪೂರ್ಣಾಂಕ cstr_vprintf(CString *cstr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap)
{
    va_list v;
    ಪೂರ್ಣಾಂಕ len, ಗಾತ್ರ_2 = 80;
    ಗಾಗಿ (;;) {
        ಗಾತ್ರ_2 += cstr->ಗಾತ್ರ_2;
        ಆದರೆ (ಗಾತ್ರ_2 > cstr->ಗಾತ್ರ_allocated)
            cstr_realloc(cstr, ಗಾತ್ರ_2);
        ಗಾತ್ರ_2 = cstr->ಗಾತ್ರ_allocated - cstr->ಗಾತ್ರ_2;
        va_copy(v, ap);
        len = vsnprintf(cstr->ದತ್ತಾಂಶ + cstr->ಗಾತ್ರ_2, ಗಾತ್ರ_2, fmt, v);
        va_end(v);
        ಆದರೆ (len >= 0 && len < ಗಾತ್ರ_2)
            ನಿಲ್ಲಿಸು;
        ಗಾತ್ರ_2 *= 2;
    }
    cstr->ಗಾತ್ರ_2 += len;
    ಹಿಂತಿರುಗಿ len;
}

ST_FUNC ಪೂರ್ಣಾಂಕ cstr_printf(CString *cstr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap; ಪೂರ್ಣಾಂಕ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ಹಿಂತಿರುಗಿ len;
}

/* XXX: unicode ? */
ಸ್ಥಿರ ಶೂನ್ಯ ಕೂಡಿಸು_char(CString *cstr, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ಆದರೆ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } ಇಲ್ಲದಿದ್ದರೆ {
        cstr_ccat(cstr, '\\');
        ಆದರೆ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } ಇಲ್ಲದಿದ್ದರೆ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ಸ್ಥಿರ TokenSym *tok_alloc_new(TokenSym **pts, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len)
{
    TokenSym *ts, **ptable;
    ಪೂರ್ಣಾಂಕ i;

    ಆದರೆ (tok_ident >= SYM_ಮೊದಲ_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ಆದರೆ ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(ಕೋಷ್ಟಕ_ident, (i + TOK_ALLOC_INCR) * ಗಾತ್ರ(TokenSym *));
        ಕೋಷ್ಟಕ_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, ಗಾತ್ರ(TokenSym) + len);
    ಕೋಷ್ಟಕ_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ಖಾಲಿ;
    ts->sym_label = ಖಾಲಿ;
    ts->sym_struct = ಖಾಲಿ;
    ts->sym_identifier = ಖಾಲಿ;
    ts->len = len;
    ts->hash_ಮುಂದಿನ = ಖಾಲಿ;
    ಸ್ಮರಣೆ_ನಕಲು(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ಹಿಂತಿರುಗಿ ts;
}

#ವ್ಯಾಖ್ಯಾನಿಸು TOK_HASH_INIT 1
#ವ್ಯಾಖ್ಯಾನಿಸು TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ len)
{
    TokenSym *ts, **pts;
    ಪೂರ್ಣಾಂಕ i;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ h;
    
    h = TOK_HASH_INIT;
    ಗಾಗಿ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)str)[i]);
    h &= (TOK_HASH_ಗಾತ್ರ - 1);

    pts = &hash_ident[h];
    ಗಾಗಿ(;;) {
        ts = *pts;
        ಆದರೆ (!ts)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (ts->len == len && !memcmp(ts->str, str, len))
            ಹಿಂತಿರುಗಿ ts;
        pts = &(ts->hash_ಮುಂದಿನ);
    }
    ಹಿಂತಿರುಗಿ tok_alloc_new(pts, str, len);
}

ST_FUNC ಪೂರ್ಣಾಂಕ tok_alloc_const(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಹಿಂತಿರುಗಿ tok_alloc(str, ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *get_tok_str(ಪೂರ್ಣಾಂಕ v, CValue *cv)
{
    ಅಕ್ಷರ *p;
    ಪೂರ್ಣಾಂಕ i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.ದತ್ತಾಂಶ;

    ಆಯ್ಕೆ(v) {
    ಸ್ಥಿತಿ TOK_CINT:
    ಸ್ಥಿತಿ TOK_CUINT:
    ಸ್ಥಿತಿ TOK_CLONG:
    ಸ್ಥಿತಿ TOK_CULONG:
    ಸ್ಥಿತಿ TOK_CLLONG:
    ಸ್ಥಿತಿ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)cv->i);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    ಸ್ಥಿತಿ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        ಕೂಡಿಸು_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_PPNUM:
    ಸ್ಥಿತಿ TOK_PPSTR:
        ಹಿಂತಿರುಗಿ (ಅಕ್ಷರ*)cv->str.ದತ್ತಾಂಶ;
    ಸ್ಥಿತಿ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    ಸ್ಥಿತಿ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ಆದರೆ (v == TOK_STR) {
            len = cv->str.ಗಾತ್ರ_2 - 1;
            ಗಾಗಿ(i=0;i<len;i++)
                ಕೂಡಿಸು_char(&cstr_buf, ((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)cv->str.ದತ್ತಾಂಶ)[i]);
        } ಇಲ್ಲದಿದ್ದರೆ {
            len = (cv->str.ಗಾತ್ರ_2 / ಗಾತ್ರ(nwchar_t)) - 1;
            ಗಾಗಿ(i=0;i<len;i++)
                ಕೂಡಿಸು_char(&cstr_buf, ((nwchar_t *)cv->str.ದತ್ತಾಂಶ)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_CFLOAT:
        ಹಿಂತಿರುಗಿ strcpy(p, "<float>");
    ಸ್ಥಿತಿ TOK_CDOUBLE:
        ಹಿಂತಿರುಗಿ strcpy(p, "<double>");
    ಸ್ಥಿತಿ TOK_CLDOUBLE:
        ಹಿಂತಿರುಗಿ strcpy(p, "<long double>");
    ಸ್ಥಿತಿ TOK_LINENUM:
        ಹಿಂತಿರುಗಿ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    ಸ್ಥಿತಿ TOK_LT:
        v = '<';
        ಹೋಗು addv;
    ಸ್ಥಿತಿ TOK_GT:
        v = '>';
        ಹೋಗು addv;
    ಸ್ಥಿತಿ TOK_DOTS:
        ಹಿಂತಿರುಗಿ strcpy(p, "...");
    ಸ್ಥಿತಿ TOK_A_SHL:
        ಹಿಂತಿರುಗಿ strcpy(p, "<<=");
    ಸ್ಥಿತಿ TOK_A_SAR:
        ಹಿಂತಿರುಗಿ strcpy(p, ">>=");
    ಸ್ಥಿತಿ TOK_EOF:
        ಹಿಂತಿರುಗಿ strcpy(p, "<eof>");
    ಸ್ಥಿತಿ 0: /* anonymous nameless symbols */
        ಹಿಂತಿರುಗಿ strcpy(p, "<no name>");
    ಪೂರ್ವನಿಯೋಜಿತ:
        v &= ~(SYM_ಕ್ಷೇತ್ರ | SYM_STRUCT);
        ಆದರೆ (v < TOK_IDENT) {
            /* search in two bytes table */
            ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *q = tok_two_chars;
            ಆಗ (*q) {
                ಆದರೆ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ಹಿಂತಿರುಗಿ cstr_buf.ದತ್ತಾಂಶ;
                }
                q += 3;
            }
            ಆದರೆ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ನಿಲ್ಲಿಸು;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v < tok_ident) {
            ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->str;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v >= SYM_ಮೊದಲ_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_ಮೊದಲ_ANOM);
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* should never happen */
            ಹಿಂತಿರುಗಿ ಖಾಲಿ;
        }
        ನಿಲ್ಲಿಸು;
    }
    ಹಿಂತಿರುಗಿ cstr_buf.ದತ್ತಾಂಶ;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ handle_eob(ಶೂನ್ಯ)
{
    BufferedFile *bf = file;
    ಪೂರ್ಣಾಂಕ len;

    /* only tries to read if really end of buffer */
    ಆದರೆ (bf->buf_ptr >= bf->buf_ಕೊನೆ) {
        ಆದರೆ (bf->fd >= 0) {
#ಆದರೆ defined(PARSE_DEBUG)
            len = 1;
#ಇಲ್ಲದಿದ್ದರೆ
            len = IO_BUF_ಗಾತ್ರ;
#ಆದರೆ_ಅಂತ್ಯ
            len = ಪಠ(bf->fd, bf->ಬಫರ್, len);
            ಆದರೆ (len < 0)
                len = 0;
        } ಇಲ್ಲದಿದ್ದರೆ {
            len = 0;
        }
        ಒಟ್ಟು_ಬೈಟುಗಳು += len;
        bf->buf_ptr = bf->ಬಫರ್;
        bf->buf_ಕೊನೆ = bf->ಬಫರ್ + len;
        *bf->buf_ಕೊನೆ = CH_EOB;
    }
    ಆದರೆ (bf->buf_ptr < bf->buf_ಕೊನೆ) {
        ಹಿಂತಿರುಗಿ bf->buf_ptr[0];
    } ಇಲ್ಲದಿದ್ದರೆ {
        bf->buf_ptr = bf->buf_ಕೊನೆ;
        ಹಿಂತಿರುಗಿ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಮುಂದಿನ_c(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ಆದರೆ (ch == CH_EOB && file->buf_ptr >= file->buf_ಕೊನೆ)
        ch = handle_eob();
    ಹಿಂತಿರುಗಿ ch;
}

/* input with '\[\r]\n' handling. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ handle_stray_noerror(ಪೂರ್ಣಾಂಕ err)
{
    ಪೂರ್ಣಾಂಕ ch;
    ಆಗ ((ch = ಮುಂದಿನ_c()) == '\\') {
        ch = ಮುಂದಿನ_c();
        ಆದರೆ (ch == '\n') {
    newl:
            file->ಸಾಲು_ಅಂಕೆ++;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (ch == '\r') {
                ch = ಮುಂದಿನ_c();
                ಆದರೆ (ch == '\n')
                    ಹೋಗು newl;
                *--file->buf_ptr = '\r';
            }
            ಆದರೆ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ಹಿಂತಿರುಗಿ *--file->buf_ptr = '\\';
        }
    }
    ಹಿಂತಿರುಗಿ ch;
}

#ವ್ಯಾಖ್ಯಾನಿಸು ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ handle_bs(uint8_t **p)
{
    ಪೂರ್ಣಾಂಕ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ಹಿಂತಿರುಗಿ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ handle_stray(uint8_t **p)
{
    ಪೂರ್ಣಾಂಕ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ಹಿಂತಿರುಗಿ c;
}

/* handle the complicated stray case */
#ವ್ಯಾಖ್ಯಾನಿಸು PEEKC(c, p)\
{\
    c = *++p;\
    ಆದರೆ (c == '\\')\
        c = handle_stray(&p); \
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ skip_spaces(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ch;
    --file->buf_ptr;
    ಮಾಡು {
        ch = ninp();
    } ಆಗ (isidnum_ಕೋಷ್ಟಕ[ch - CH_EOF] & IS_SPC);
    ಹಿಂತಿರುಗಿ ch;
}

/* single line C++ comments */
ಸ್ಥಿರ uint8_t *parse_ಸಾಲು_comment(uint8_t *p)
{
    ಪೂರ್ಣಾಂಕ c;
    ಗಾಗಿ(;;) {
        ಗಾಗಿ (;;) {
            c = *++p;
    redo:
            ಆದರೆ (c == '\n' || c == '\\')
                ನಿಲ್ಲಿಸು;
            c = *++p;
            ಆದರೆ (c == '\n' || c == '\\')
                ನಿಲ್ಲಿಸು;
        }
        ಆದರೆ (c == '\n')
            ನಿಲ್ಲಿಸು;
        c = handle_bs(&p);
        ಆದರೆ (c == CH_EOF)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (c != '\\')
            ಹೋಗು redo;
    }
    ಹಿಂತಿರುಗಿ p;
}

/* C comments */
ಸ್ಥಿರ uint8_t *parse_comment(uint8_t *p)
{
    ಪೂರ್ಣಾಂಕ c;
    ಗಾಗಿ(;;) {
        /* fast skip loop */
        ಗಾಗಿ(;;) {
            c = *++p;
        redo:
            ಆದರೆ (c == '\n' || c == '*' || c == '\\')
                ನಿಲ್ಲಿಸು;
            c = *++p;
            ಆದರೆ (c == '\n' || c == '*' || c == '\\')
                ನಿಲ್ಲಿಸು;
        }
        /* now we can handle all the cases */
        ಆದರೆ (c == '\n') {
            file->ಸಾಲು_ಅಂಕೆ++;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '*') {
            ಮಾಡು {
                c = *++p;
            } ಆಗ (c == '*');
            ಆದರೆ (c == '\\')
                c = handle_bs(&p);
            ಆದರೆ (c == '/')
                ನಿಲ್ಲಿಸು;
            ಹೋಗು check_eof;
        } ಇಲ್ಲದಿದ್ದರೆ {
            c = handle_bs(&p);
        check_eof:
            ಆದರೆ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ಆದರೆ (c != '\\')
                ಹೋಗು redo;
        }
    }
    ಹಿಂತಿರುಗಿ p + 1;
}

/* parse a string without interpreting escapes */
ಸ್ಥಿರ uint8_t *parse_pp_string(uint8_t *p, ಪೂರ್ಣಾಂಕ sep, CString *str)
{
    ಪೂರ್ಣಾಂಕ c;
    ಗಾಗಿ(;;) {
        c = *++p;
    redo:
        ಆದರೆ (c == sep) {
            ನಿಲ್ಲಿಸು;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '\\') {
            c = handle_bs(&p);
            ಆದರೆ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '\\') {
                ಆದರೆ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ಆದರೆ (c == '\\') {
                    c = handle_bs(&p);
                    ಆದರೆ (c == CH_EOF)
                        ಹೋಗು unterminated_string;
                }
                ಹೋಗು ಕೂಡಿಸು_char;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ಹೋಗು redo;
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '\n') {
        ಕೂಡಿಸು_lf:
            ಆದರೆ (ACCEPT_LF_ಒಳ_ಅಕ್ಷರಸರಣಿಗಳು) {
                file->ಸಾಲು_ಅಂಕೆ++;
                ಹೋಗು ಕೂಡಿಸು_char;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (str) { /* not skipping */
                ಹೋಗು unterminated_string;
            } ಇಲ್ಲದಿದ್ದರೆ {
                //tcc_warning("missing terminating %c character", sep);
                ಹಿಂತಿರುಗಿ p;
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '\r') {
            c = *++p;
            ಆದರೆ (c == '\\')
                c = handle_bs(&p);
            ಆದರೆ (c == '\n')
                ಹೋಗು ಕೂಡಿಸು_lf;
            ಆದರೆ (c == CH_EOF)
                ಹೋಗು unterminated_string;
            ಆದರೆ (str)
                cstr_ccat(str, '\r');
            ಹೋಗು redo;
        } ಇಲ್ಲದಿದ್ದರೆ {
        ಕೂಡಿಸು_char:
            ಆದರೆ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ಹಿಂತಿರುಗಿ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ಸ್ಥಿರ ಶೂನ್ಯ preprocess_skip(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a, ಆರಂಭ_ದ_ಸಾಲು, c, ಒಳ_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_ಆರಂಭ:
    ಆರಂಭ_ದ_ಸಾಲು = 1;
    ಒಳ_warn_or_error = 0;
    ಗಾಗಿ(;;) {
        c = *p;
        ಆಯ್ಕೆ(c) {
        ಸ್ಥಿತಿ ' ':
        ಸ್ಥಿತಿ '\t':
        ಸ್ಥಿತಿ '\f':
        ಸ್ಥಿತಿ '\v':
        ಸ್ಥಿತಿ '\r':
            p++;
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ '\n':
            file->ಸಾಲು_ಅಂಕೆ++;
            p++;
            ಹೋಗು redo_ಆರಂಭ;
        ಸ್ಥಿತಿ '\\':
            c = handle_bs(&p);
            ಆದರೆ (c == CH_EOF)
                expect("#endif");
            ಆದರೆ (c == '\\')
                ++p;
            ಮುಂದುವರಿ;
        /* skip strings */
        ಸ್ಥಿತಿ '\"':
        ಸ್ಥಿತಿ '\'':
            ಆದರೆ (ಒಳ_warn_or_error)
                ಹೋಗು _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ಖಾಲಿ);
            ನಿಲ್ಲಿಸು;
        /* skip comments */
        ಸ್ಥಿತಿ '/':
            ಆದರೆ (ಒಳ_warn_or_error)
                ಹೋಗು _default;
            ++p;
            c = handle_bs(&p);
            ಆದರೆ (c == '*') {
                p = parse_comment(p);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '/') {
                p = parse_ಸಾಲು_comment(p);
            }
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ '#':
            p++;
            ಆದರೆ (ಆರಂಭ_ದ_ಸಾಲು) {
                file->buf_ptr = p;
                ಮುಂದಿನ_nomacro();
                p = file->buf_ptr;
                ಆದರೆ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    ಹೋಗು the_ಕೊನೆ;
                ಆದರೆ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_ENDIF)
                    a--;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ( tok == TOK_ERROR || tok == TOK_WARNING)
                    ಒಳ_warn_or_error = 1;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_LINEFEED)
                    ಹೋಗು redo_ಆರಂಭ;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_ಸಾಲು_comment(p - 1);
            }
#ಆದರೆ !defined(TCC_ಗುರಿ_ARM) && !defined(TCC_ಗುರಿ_ARM64)
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_ಸಾಲು_comment(p - 1);
#ಇಲ್ಲದಿದ್ದರೆ
            /* ARM/ARM64 assembly uses '#' for constants */
#ಆದರೆ_ಅಂತ್ಯ
            ನಿಲ್ಲಿಸು;
_default:
        ಪೂರ್ವನಿಯೋಜಿತ:
            p++;
            ನಿಲ್ಲಿಸು;
        }
        ಆರಂಭ_ದ_ಸಾಲು = 0;
    }
 the_ಕೊನೆ: ;
    file->buf_ptr = p;
}

#ಆದರೆ 0
/* return the number of additional 'ints' necessary to store the
   token */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ tok_ಗಾತ್ರ(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *p)
{
    ಆಯ್ಕೆ(*p) {
        /* 4 bytes */
    ಸ್ಥಿತಿ TOK_CINT:
    ಸ್ಥಿತಿ TOK_CUINT:
    ಸ್ಥಿತಿ TOK_CCHAR:
    ಸ್ಥಿತಿ TOK_LCHAR:
    ಸ್ಥಿತಿ TOK_CFLOAT:
    ಸ್ಥಿತಿ TOK_LINENUM:
        ಹಿಂತಿರುಗಿ 1 + 1;
    ಸ್ಥಿತಿ TOK_STR:
    ಸ್ಥಿತಿ TOK_LSTR:
    ಸ್ಥಿತಿ TOK_PPNUM:
    ಸ್ಥಿತಿ TOK_PPSTR:
        ಹಿಂತಿರುಗಿ 1 + 1 + (p[1] + 3) / 4;
    ಸ್ಥಿತಿ TOK_CLONG:
    ಸ್ಥಿತಿ TOK_CULONG:
	ಹಿಂತಿರುಗಿ 1 + LONG_ಗಾತ್ರ / 4;
    ಸ್ಥಿತಿ TOK_CDOUBLE:
    ಸ್ಥಿತಿ TOK_CLLONG:
    ಸ್ಥಿತಿ TOK_CULLONG:
        ಹಿಂತಿರುಗಿ 1 + 2;
    ಸ್ಥಿತಿ TOK_CLDOUBLE:
        ಹಿಂತಿರುಗಿ 1 + LDOUBLE_ಪದಗಳು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಹಿಂತಿರುಗಿ 1 + 0;
    }
}
#ಆದರೆ_ಅಂತ್ಯ

/* token string handling */
ST_INLN ಶೂನ್ಯ tok_str_new(TokenString *s)
{
    s->str = ಖಾಲಿ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = -1;
}

ST_FUNC TokenString *tok_str_alloc(ಶೂನ್ಯ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, ಗಾತ್ರ *str);
    tok_str_new(str);
    ಹಿಂತಿರುಗಿ str;
}

ST_FUNC ಶೂನ್ಯ tok_str_free_str(ಪೂರ್ಣಾಂಕ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ಶೂನ್ಯ tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ಪೂರ್ಣಾಂಕ *tok_str_realloc(TokenString *s, ಪೂರ್ಣಾಂಕ new_ಗಾತ್ರ)
{
    ಪೂರ್ಣಾಂಕ *str, ಗಾತ್ರ_2;

    ಗಾತ್ರ_2 = s->allocated_len;
    ಆದರೆ (ಗಾತ್ರ_2 < 16)
        ಗಾತ್ರ_2 = 16;
    ಆಗ (ಗಾತ್ರ_2 < new_ಗಾತ್ರ)
        ಗಾತ್ರ_2 = ಗಾತ್ರ_2 * 2;
    ಆದರೆ (ಗಾತ್ರ_2 > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, ಗಾತ್ರ_2 * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
        s->allocated_len = ಗಾತ್ರ_2;
        s->str = str;
    }
    ಹಿಂತಿರುಗಿ s->str;
}

ST_FUNC ಶೂನ್ಯ tok_str_ಕೂಡಿಸು(TokenString *s, ಪೂರ್ಣಾಂಕ t)
{
    ಪೂರ್ಣಾಂಕ len, *str;

    len = s->len;
    str = s->str;
    ಆದರೆ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC ಶೂನ್ಯ begin_macro(TokenString *str, ಪೂರ್ಣಾಂಕ alloc)
{
    str->alloc = alloc;
    str->prev = macro_ರಾಶಿ;
    str->prev_ptr = macro_ptr;
    str->save_ಸಾಲು_ಅಂಕೆ = file->ಸಾಲು_ಅಂಕೆ;
    macro_ptr = str->str;
    macro_ರಾಶಿ = str;
}

ST_FUNC ಶೂನ್ಯ ಕೊನೆ_macro(ಶೂನ್ಯ)
{
    TokenString *str = macro_ರಾಶಿ;
    macro_ರಾಶಿ = str->prev;
    macro_ptr = str->prev_ptr;
    file->ಸಾಲು_ಅಂಕೆ = str->save_ಸಾಲು_ಅಂಕೆ;
    ಆದರೆ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (str->alloc == 2)
            str->str = ಖಾಲಿ; /* don't free */
        tok_str_free(str);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tok_str_add2(TokenString *s, ಪೂರ್ಣಾಂಕ t, CValue *cv)
{
    ಪೂರ್ಣಾಂಕ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ಆದರೆ (len + TOK_MAX_ಗಾತ್ರ >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_ಗಾತ್ರ + 1);
    str[len++] = t;
    ಆಯ್ಕೆ(t) {
    ಸ್ಥಿತಿ TOK_CINT:
    ಸ್ಥಿತಿ TOK_CUINT:
    ಸ್ಥಿತಿ TOK_CCHAR:
    ಸ್ಥಿತಿ TOK_LCHAR:
    ಸ್ಥಿತಿ TOK_CFLOAT:
    ಸ್ಥಿತಿ TOK_LINENUM:
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    ಸ್ಥಿತಿ TOK_CLONG:
    ಸ್ಥಿತಿ TOK_CULONG:
#ಆದರೆ_ಅಂತ್ಯ
        str[len++] = cv->tab[0];
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_PPNUM:
    ಸ್ಥಿತಿ TOK_PPSTR:
    ಸ್ಥಿತಿ TOK_STR:
    ಸ್ಥಿತಿ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            ಗಾತ್ರ_t nb_ಪದಗಳು =
                1 + (cv->str.ಗಾತ್ರ_2 + ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ) - 1) / ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ);
            ಆದರೆ (len + nb_ಪದಗಳು >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_ಪದಗಳು + 1);
            str[len] = cv->str.ಗಾತ್ರ_2;
            ಸ್ಮರಣೆ_ನಕಲು(&str[len + 1], cv->str.ದತ್ತಾಂಶ, cv->str.ಗಾತ್ರ_2);
            len += nb_ಪದಗಳು;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CDOUBLE:
    ಸ್ಥಿತಿ TOK_CLLONG:
    ಸ್ಥಿತಿ TOK_CULLONG:
#ಆದರೆ LONG_ಗಾತ್ರ == 8
    ಸ್ಥಿತಿ TOK_CLONG:
    ಸ್ಥಿತಿ TOK_CULONG:
#ಆದರೆ_ಅಂತ್ಯ
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ಆದರೆ (LDOUBLE_ಪದಗಳು >= 3)
        str[len++] = cv->tab[2];
        ಆದರೆ (LDOUBLE_ಪದಗಳು >= 4)
        str[len++] = cv->tab[3];
    ಪೂರ್ವನಿಯೋಜಿತ:
        ನಿಲ್ಲಿಸು;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC ಶೂನ್ಯ tok_str_ಕೂಡಿಸು_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ಆದರೆ (file->ಸಾಲು_ಅಂಕೆ != s->ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ) {
        s->ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = file->ಸಾಲು_ಅಂಕೆ;
        cval.i = s->ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ಸ್ಥಿರ ಶೂನ್ಯ tok_str_add2_spc(TokenString *s, ಪೂರ್ಣಾಂಕ t, CValue *cv)
{
    ಆದರೆ (s->need_spc == 3)
        tok_str_ಕೂಡಿಸು(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ tok_get(ಪೂರ್ಣಾಂಕ *t, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ **pp, CValue *cv)
{
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *p = *pp;
    ಪೂರ್ಣಾಂಕ n, *tab;

    tab = cv->tab;
    ಆಯ್ಕೆ(*t = *p++) {
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    ಸ್ಥಿತಿ TOK_CLONG:
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ TOK_CINT:
    ಸ್ಥಿತಿ TOK_CCHAR:
    ಸ್ಥಿತಿ TOK_LCHAR:
    ಸ್ಥಿತಿ TOK_LINENUM:
        cv->i = *p++;
        ನಿಲ್ಲಿಸು;
#ಆದರೆ LONG_ಗಾತ್ರ == 4
    ಸ್ಥಿತಿ TOK_CULONG:
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ TOK_CUINT:
        cv->i = (ಚಿಹ್ನೆರಹಿತ)*p++;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CFLOAT:
	tab[0] = *p++;
	ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_STR:
    ಸ್ಥಿತಿ TOK_LSTR:
    ಸ್ಥಿತಿ TOK_PPNUM:
    ಸ್ಥಿತಿ TOK_PPSTR:
        cv->str.ಗಾತ್ರ_2 = *p++;
        cv->str.ದತ್ತಾಂಶ = (ಅಕ್ಷರ*)p;
        p += (cv->str.ಗಾತ್ರ_2 + ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ) - 1) / ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ);
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_CDOUBLE:
    ಸ್ಥಿತಿ TOK_CLLONG:
    ಸ್ಥಿತಿ TOK_CULLONG:
#ಆದರೆ LONG_ಗಾತ್ರ == 8
    ಸ್ಥಿತಿ TOK_CLONG:
    ಸ್ಥಿತಿ TOK_CULONG:
#ಆದರೆ_ಅಂತ್ಯ
        n = 2;
        ಹೋಗು copy;
    ಸ್ಥಿತಿ TOK_CLDOUBLE:
        n = LDOUBLE_ಪದಗಳು;
    copy:
        ಮಾಡು
            *tab++ = *p++;
        ಆಗ (--n);
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        ನಿಲ್ಲಿಸು;
    }
    *pp = p;
}

#ಆದರೆ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#ಇಲ್ಲದಿದ್ದರೆ
# define TOK_GET(t,p,c) ಮಾಡು { \
    ಪೂರ್ಣಾಂಕ _t = **(p); \
    ಆದರೆ (TOK_HAS_ಮೌಲ್ಯ(_t)) \
        tok_get(t, p, c); \
    ಇಲ್ಲದಿದ್ದರೆ \
        *(t) = _t, ++*(p); \
    } ಆಗ (0)
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ macro_is_equal(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *a, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *b)
{
    CValue cv;
    ಪೂರ್ಣಾಂಕ t;

    ಆದರೆ (!a || !b)
        ಹಿಂತಿರುಗಿ 1;

    ಆಗ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ಆದರೆ (strcmp(tokcstr.ದತ್ತಾಂಶ, get_tok_str(t, &cv)))
            ಹಿಂತಿರುಗಿ 0;
    }
    ಹಿಂತಿರುಗಿ !(*a || *b);
}

/* defines handling */
ST_INLN ಶೂನ್ಯ define_ತಳ್ಳು(ಪೂರ್ಣಾಂಕ v, ಪೂರ್ಣಾಂಕ macro_type, ಪೂರ್ಣಾಂಕ *str, Sym *ಮೊದಲ_arg)
{
    Sym *s, *o;

    o = define_ಕಂಡುಹಿಡಿ(v);
    s = sym_push2(&define_ರಾಶಿ, v, macro_type, 0);
    s->d = str;
    s->ಮುಂದಿನ = ಮೊದಲ_arg;
    ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->sym_define = s;

    ಆದರೆ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ಖಾಲಿ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC ಶೂನ್ಯ define_undef(Sym *s)
{
    ಪೂರ್ಣಾಂಕ v = s->v;
    ಆದರೆ (v >= TOK_IDENT && v < tok_ident)
        ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->sym_define = ಖಾಲಿ;
}

ST_INLN Sym *define_ಕಂಡುಹಿಡಿ(ಪೂರ್ಣಾಂಕ v)
{
    v -= TOK_IDENT;
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ)v >= (ಚಿಹ್ನೆರಹಿತ)(tok_ident - TOK_IDENT))
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    ಹಿಂತಿರುಗಿ ಕೋಷ್ಟಕ_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC ಶೂನ್ಯ free_ನಿರೂಪಿಸುತ್ತದೆ(Sym *b)
{
    ಆಗ (define_ರಾಶಿ != b) {
        Sym *ತುದಿ = define_ರಾಶಿ;
        define_ರಾಶಿ = ತುದಿ->prev;
        tok_str_free_str(ತುದಿ->d);
        define_undef(ತುದಿ);
        sym_free(ತುದಿ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ಸ್ಥಿರ ಶೂನ್ಯ maybe_ಸತತ_test(TCCState *s)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
    ಆದರೆ (s->include_ರಾಶಿ_ptr != s->include_ರಾಶಿ)
        ಹಿಂತಿರುಗಿ;
    p = get_tok_str(tok, ಖಾಲಿ);
    ಆದರೆ (0 != memcmp(p, "test_", 5))
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (0 != --s->ಸತತ_test)
        ಹಿಂತಿರುಗಿ;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ತಳ್ಳು(tok, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
}

ST_FUNC ಶೂನ್ಯ skip_ಗಮ್ಯ_eol(ಪೂರ್ಣಾಂಕ warn)
{
    ಆದರೆ (tok == TOK_LINEFEED)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (warn)
        tcc_warning("extra tokens after directive");
    ಆಗ (macro_ರಾಶಿ)
        ಕೊನೆ_macro();
    file->buf_ptr = parse_ಸಾಲು_comment(file->buf_ptr - 1);
    ಮುಂದಿನ_nomacro();
}

ಸ್ಥಿರ CachedInclude *
ಹುಡುಕು_cached_include(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು);

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ parse_include(TCCState *s1, ಪೂರ್ಣಾಂಕ do_ಮುಂದಿನ, ಪೂರ್ಣಾಂಕ test)
{
    ಪೂರ್ಣಾಂಕ c, i;
    ಅಕ್ಷರ name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ಆದರೆ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.ಗಾತ್ರ_2;
        pstrncpy(name, ಗಾತ್ರ name, tokcstr.ದತ್ತಾಂಶ, i);
        ಮುಂದಿನ_nomacro();
    } ಇಲ್ಲದಿದ್ದರೆ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        ಗಾಗಿ (;;) {
            ಮುಂದಿನ();
            p = name, i = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(p) - 1;
            ಆದರೆ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ನಿಲ್ಲಿಸು;
            ಆದರೆ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, ಗಾತ್ರ name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ಆದರೆ (!test)
        skip_ಗಮ್ಯ_eol(1);

    i = do_ಮುಂದಿನ ? file->include_ಮುಂದಿನ_ಸೂಚ್ಯಂಕ : -1;
    ಗಾಗಿ (;;) {
        ++i;
        ಆದರೆ (i == 0) {
            /* check absolute include path */
            ಆದರೆ (!IS_ABSPATH(name))
                ಮುಂದುವರಿ;
            buf[0] = '\0';
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i == 1) {
            /* search in file's dir if "header.h" */
            ಆದರೆ (c != '\"')
                ಮುಂದುವರಿ;
            p = file->true_filename;
            pstrncpy(buf, ಗಾತ್ರ buf, p, tcc_basename(p) - p);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪೂರ್ಣಾಂಕ j = i - 2, k = j - s1->nb_include_paths;
            ಆದರೆ (k < 0)
                p = s1->include_paths[j];
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (test)
                ಹಿಂತಿರುಗಿ 0;
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, ಗಾತ್ರ buf, p);
            pstrcat(buf, ಗಾತ್ರ buf, "/");
        }
        pstrcat(buf, ಗಾತ್ರ buf, name);
        e = ಹುಡುಕು_cached_include(s1, buf, 0);
        ಆದರೆ (e && (define_ಕಂಡುಹಿಡಿ(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
            ಬರೆ("%s: skipping cached %s\n", file->filename, buf);
#ಆದರೆ_ಅಂತ್ಯ
            ಆದರೆ ((s1->verbose | 1) == 3) /* -vv[v] */
                ಬರೆ("=> %*s%s\n",
                   (ಪೂರ್ಣಾಂಕ)(s1->include_ರಾಶಿ_ptr - s1->include_ರಾಶಿ), "", buf);
            ಹಿಂತಿರುಗಿ 1;
        }
        ಆದರೆ (tcc_open(s1, buf) >= 0)
            ನಿಲ್ಲಿಸು;
    }

    ಆದರೆ (test) {
        tcc_close();
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಆದರೆ (s1->include_ರಾಶಿ_ptr >= s1->include_ರಾಶಿ + INCLUDE_ರಾಶಿ_ಗಾತ್ರ)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ರಾಶಿ_ptr++ = file->prev;
        file->include_ಮುಂದಿನ_ಸೂಚ್ಯಂಕ = i;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
        ಬರೆ("%s: including %s\n", file->prev->filename, file->filename);
#ಆದರೆ_ಅಂತ್ಯ
        /* update target deps */
        ಆದರೆ (s1->gen_deps) {
            BufferedFile *bf = file;
            ಆಗ (i == 1 && (bf = bf->prev))
                i = bf->include_ಮುಂದಿನ_ಸೂಚ್ಯಂಕ;
            /* skip system include files */
            ಆದರೆ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_ಕೂಡಿಸು(&s1->ಗುರಿ_deps, &s1->nb_ಗುರಿ_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ಹಿಂತಿರುಗಿ 1;
}

/* eval an expression for #if/#elif */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಅಭಿವ್ಯಕ್ತಿ_preprocess(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ c, t;
    ಪೂರ್ಣಾಂಕ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_ಅಭಿವ್ಯಕ್ತಿ = 1;
    ಆಗ (1) {
        ಮುಂದಿನ(); /* do macro subst */
        t = tok;
        ಆದರೆ (tok < TOK_IDENT) {
            ಆದರೆ (tok == TOK_LINEFEED || tok == TOK_EOF)
                ನಿಲ್ಲಿಸು;
            ಆದರೆ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            ಮುಂದಿನ();
            t = tok;
            ಆದರೆ (t == '(') 
                ಮುಂದಿನ();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ಆದರೆ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ಆದರೆ (s1->ಸತತ_test)
                maybe_ಸತತ_test(s1);
            c = 0;
            ಆದರೆ (define_ಕಂಡುಹಿಡಿ(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_ಮುಂದಿನ)
                c = 1;
            ಆದರೆ (t == '(') {
                ಮುಂದಿನ();
                ಆದರೆ (tok != ')')
                    expect("')'");
            }
            ಹೋಗು c_ಸಂಖ್ಯೆ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_ಮುಂದಿನ) {
            t = tok;
            ಮುಂದಿನ();
	    ಆದರೆ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ಆದರೆ (tok != ')')
                expect("')'");
            ಹೋಗು c_ಸಂಖ್ಯೆ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_ಸಂಖ್ಯೆ:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_ಕೂಡಿಸು_tok(str);
    }
    ಆದರೆ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_ಕೂಡಿಸು(str, TOK_EOF); /* simulate end of file */
    pp_ಅಭಿವ್ಯಕ್ತಿ = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    ಮುಂದಿನ();
    c = ಅಭಿವ್ಯಕ್ತಿ_const();
    ಆದರೆ (tok != TOK_EOF)
        tcc_error("...");
    pp_ಅಭಿವ್ಯಕ್ತಿ = 0;
    ಕೊನೆ_macro();
    tok = t; /* restore LF or EOF */
    ಹಿಂತಿರುಗಿ c != 0;
}

ST_FUNC ಶೂನ್ಯ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_ಅಭಿವ್ಯಕ್ತಿ, 0));
    macro_ptr = macro_ರಾಶಿ->str;
    ಆಗ (ಮುಂದಿನ(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC ಶೂನ್ಯ parse_define(ಶೂನ್ಯ)
{
    Sym *s, *ಮೊದಲ, **ps;
    ಪೂರ್ಣಾಂಕ v, t, varg, is_vaargs, t0;
    ಪೂರ್ಣಾಂಕ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ಆದರೆ (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    ಮೊದಲ = ಖಾಲಿ;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    ಮುಂದಿನ_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    ಆದರೆ (tok == '(') {
        ಪೂರ್ಣಾಂಕ dotid = ಗಣ_idnum('.', 0);
        ಮುಂದಿನ_nomacro();
        ps = &ಮೊದಲ;
        ಆದರೆ (tok != ')') ಗಾಗಿ (;;) {
            varg = tok;
            ಮುಂದಿನ_nomacro();
            is_vaargs = 0;
            ಆದರೆ (varg == TOK_DOTS) {
                varg = TOK_VA_ವಾದಗಳು;
                is_vaargs = 1;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                ಮುಂದಿನ_nomacro();
            }
            ಆದರೆ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ರಾಶಿ, varg | SYM_ಕ್ಷೇತ್ರ, is_vaargs, 0);
            *ps = s;
            ps = &s->ಮುಂದಿನ;
            ಆದರೆ (tok == ')')
                ನಿಲ್ಲಿಸು;
            ಆದರೆ (tok != ',' || is_vaargs)
                ಹೋಗು bad_list;
            ಮುಂದಿನ_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        ಮುಂದಿನ_nomacro();
        t = MACRO_FUNC;
        ಗಣ_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    ಆಗ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ಆದರೆ (is_space(tok)) {
            str.need_spc |= 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (TOK_TWOSHARPS == tok) {
                ಆದರೆ (0 == t0)
                    ಹೋಗು bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        ಮುಂದಿನ_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_ಕೂಡಿಸು(&str, 0);
    ಆದರೆ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ತಳ್ಳು(v, t, str.str, ಮೊದಲ);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ಸ್ಥಿರ CachedInclude *ಹುಡುಕು_cached_include(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, *basename;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ h;
    CachedInclude *e;
    ಪೂರ್ಣಾಂಕ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ಆಗ ((c = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)*s) != 0) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#ಇಲ್ಲದಿದ್ದರೆ
        h = TOK_HASH_FUNC(h, c);
#ಆದರೆ_ಅಂತ್ಯ
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_ಗಾತ್ರ - 1);

    i = s1->cached_includes_hash[h];
    ಗಾಗಿ(;;) {
        ಆದರೆ (i == 0)
            ನಿಲ್ಲಿಸು;
        e = s1->cached_includes[i - 1];
        ಆದರೆ (0 == PATHCMP(filename, e->filename))
            ಹಿಂತಿರುಗಿ e;
        ಆದರೆ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ಹಿಂತಿರುಗಿ e;
        i = e->hash_ಮುಂದಿನ;
    }
    ಆದರೆ (!ಕೂಡಿಸು)
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;

    e = tcc_malloc(ಗಾತ್ರ(CachedInclude) + (len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(filename)));
    ಸ್ಮರಣೆ_ನಕಲು(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_ಕೂಡಿಸು(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_ಮುಂದಿನ = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
    ಬರೆ("adding cached '%s'\n", filename);
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ e;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pragma_parse(TCCState *s1)
{
    ಮುಂದಿನ_nomacro();
    ಆದರೆ (tok == TOK_ತಳ್ಳು_macro || tok == TOK_ತೆಗೆ_macro) {
        ಪೂರ್ಣಾಂಕ t = tok, v;
        Sym *s;

        ಆದರೆ (ಮುಂದಿನ(), tok != '(')
            ಹೋಗು pragma_err;
        ಆದರೆ (ಮುಂದಿನ(), tok != TOK_STR)
            ಹೋಗು pragma_err;
        v = tok_alloc(tokc.str.ದತ್ತಾಂಶ, tokc.str.ಗಾತ್ರ_2 - 1)->tok;
        ಆದರೆ (ಮುಂದಿನ(), tok != ')')
            ಹೋಗು pragma_err;
        ಆದರೆ (t == TOK_ತಳ್ಳು_macro) {
            ಆಗ (ಖಾಲಿ == (s = define_ಕಂಡುಹಿಡಿ(v)))
                define_ತಳ್ಳು(v, 0, ಖಾಲಿ, ಖಾಲಿ);
            s->type.ref = s; /* set push boundary */
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಗಾಗಿ (s = define_ರಾಶಿ; s; s = s->prev)
                ಆದರೆ (s->v == v && s->type.ref == s) {
                    s->type.ref = ಖಾಲಿ;
                    ನಿಲ್ಲಿಸು;
                }
        }
        ಆದರೆ (s)
            ಕೋಷ್ಟಕ_ident[v - TOK_IDENT]->sym_define = s->d ? s : ಖಾಲಿ;
        ಇಲ್ಲದಿದ್ದರೆ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_once) {
        ಹುಡುಕು_cached_include(s1, file->true_filename, 1)->once = 1;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ಹಿಂತಿರುಗಿ 1;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        ಮುಂದಿನ();
        skip('(');
        ಆದರೆ (tok == TOK_ASM_ತೆಗೆ) {
            ಮುಂದಿನ();
            ಆದರೆ (s1->pack_ರಾಶಿ_ptr <= s1->pack_ರಾಶಿ) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ರಾಶಿ_ptr--;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಪೂರ್ಣಾಂಕ val = 0;
            ಆದರೆ (tok != ')') {
                ಆದರೆ (tok == TOK_ASM_ತಳ್ಳು) {
                    ಮುಂದಿನ();
                    ಆದರೆ (s1->pack_ರಾಶಿ_ptr >= s1->pack_ರಾಶಿ + PACK_ರಾಶಿ_ಗಾತ್ರ - 1)
                        ಹೋಗು stk_error;
                    val = *s1->pack_ರಾಶಿ_ptr++;
                    ಆದರೆ (tok != ',')
                        ಹೋಗು pack_ಗಣ;
                    ಮುಂದಿನ();
                }
                ಆದರೆ (tok != TOK_CINT)
                    ಹೋಗು pragma_err;
                val = tokc.i;
                ಆದರೆ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    ಹೋಗು pragma_err;
                ಮುಂದಿನ();
            }
        pack_ಗಣ:
            *s1->pack_ರಾಶಿ_ptr = val;
        }
        ಆದರೆ (tok != ')')
            ಹೋಗು pragma_err;

    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_comment) {
        ಅಕ್ಷರ *p; ಪೂರ್ಣಾಂಕ t;
        ಮುಂದಿನ();
        skip('(');
        t = tok;
        ಮುಂದಿನ();
        skip(',');
        ಆದರೆ (tok != TOK_STR)
            ಹೋಗು pragma_err;
        p = tcc_strdup(tokc.str.ದತ್ತಾಂಶ);
        ಮುಂದಿನ();
        ಆದರೆ (tok != ')')
            ಹೋಗು pragma_err;
        ಆದರೆ (t == TOK_lib) {
            dynarray_ಕೂಡಿಸು(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (t == TOK_option)
                tcc_ಗಣ_options(s1, p);
            tcc_free(p);
        }

    } ಇಲ್ಲದಿದ್ದರೆ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ಹಿಂತಿರುಗಿ 0;
    }
    ಮುಂದಿನ();
    ಹಿಂತಿರುಗಿ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC ಶೂನ್ಯ tccpp_putfile(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಅಕ್ಷರ buf[1024];
    buf[0] = 0;
    ಆದರೆ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, ಗಾತ್ರ buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, ಗಾತ್ರ buf, filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    normalize_slashes(buf);
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (0 == strcmp(file->filename, buf))
        ಹಿಂತಿರುಗಿ;
    //printf("new file '%s'\n", buf);
    ಆದರೆ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, ಗಾತ್ರ file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC ಶೂನ್ಯ preprocess(ಪೂರ್ಣಾಂಕ is_bof)
{
    TCCState *s1 = tcc_state;
    ಪೂರ್ಣಾಂಕ c, n, saved_parse_flags;
    ಅಕ್ಷರ buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_ಅಂಕೆ
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    ಮುಂದಿನ_nomacro();
 redo:
    ಆಯ್ಕೆ(tok) {
    ಸ್ಥಿತಿ TOK_DEFINE:
        pp_debug_tok = tok;
        ಮುಂದಿನ_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_UNDEF:
        pp_debug_tok = tok;
        ಮುಂದಿನ_nomacro();
        pp_debug_symv = tok;
        s = define_ಕಂಡುಹಿಡಿ(tok);
        /* undefine symbol by putting an invalid name */
        ಆದರೆ (s)
            define_undef(s);
        ಮುಂದಿನ_nomacro();
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_INCLUDE:
    ಸ್ಥಿತಿ TOK_INCLUDE_ಮುಂದಿನ:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        ಹೋಗು the_ಕೊನೆ;
    ಸ್ಥಿತಿ TOK_IFNDEF:
        c = 1;
        ಹೋಗು do_ifdef;
    ಸ್ಥಿತಿ TOK_IF:
        c = ಅಭಿವ್ಯಕ್ತಿ_preprocess(s1);
        ಹೋಗು do_if;
    ಸ್ಥಿತಿ TOK_IFDEF:
        c = 0;
    do_ifdef:
        ಮುಂದಿನ_nomacro();
        ಆದರೆ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ಆದರೆ (is_bof) {
            ಆದರೆ (c) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
                ಬರೆ("#ifndef %s\n", get_tok_str(tok, ಖಾಲಿ));
#ಆದರೆ_ಅಂತ್ಯ
                file->ifndef_macro = tok;
            }
        }
        ಆದರೆ (define_ಕಂಡುಹಿಡಿ(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_ಮುಂದಿನ)
            c ^= 1;
        ಮುಂದಿನ_nomacro();
    do_if:
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr >= s1->ifdef_ರಾಶಿ + IFDEF_ರಾಶಿ_ಗಾತ್ರ)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ರಾಶಿ_ptr++ = c;
        ಹೋಗು test_skip;
    ಸ್ಥಿತಿ TOK_ELSE:
        ಮುಂದಿನ_nomacro();
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr == s1->ifdef_ರಾಶಿ)
            tcc_error("#else without matching #if");
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ರಾಶಿ_ptr[-1] ^= 3);
        ಹೋಗು test_else;
    ಸ್ಥಿತಿ TOK_ELIF:
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr == s1->ifdef_ರಾಶಿ)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ರಾಶಿ_ptr[-1];
        ಆದರೆ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ಆದರೆ (c == 1) {
            skip_ಗಮ್ಯ_eol(0);
            c = 0;
        } ಇಲ್ಲದಿದ್ದರೆ {
            c = ಅಭಿವ್ಯಕ್ತಿ_preprocess(s1);
            s1->ifdef_ರಾಶಿ_ptr[-1] = c;
        }
    test_else:
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr == file->ifdef_ರಾಶಿ_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ಆದರೆ (!(c & 1)) {
            skip_ಗಮ್ಯ_eol(1);
            preprocess_skip();
            is_bof = 0;
            ಹೋಗು redo;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_ENDIF:
        ಮುಂದಿನ_nomacro();
        ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr <= file->ifdef_ರಾಶಿ_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ರಾಶಿ_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ಆದರೆ (file->ifndef_macro &&
            s1->ifdef_ರಾಶಿ_ptr == file->ifdef_ರಾಶಿ_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_ಸಾಲು:
        parse_flags &= ~PARSE_FLAG_TOK_ಅಂಕೆ;
        ಮುಂದಿನ();
        ಆದರೆ (tok != TOK_PPNUM) {
    ಸಾಲು_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        ಹೋಗು ಸಾಲು_ಅಂಕೆ_2;
    ಸ್ಥಿತಿ TOK_PPNUM:
        ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE)
            ಹೋಗು ignore;
        c = 0; /* no error with extra tokens */
    ಸಾಲು_ಅಂಕೆ_2:
        ಗಾಗಿ (n = 0, q = tokc.str.ದತ್ತಾಂಶ; *q; ++q) {
            ಆದರೆ (!isnum(*q))
                ಹೋಗು ಸಾಲು_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        ಮುಂದಿನ();
        ಆದರೆ (tok != TOK_LINEFEED) {
            ಆದರೆ (tok != TOK_PPSTR || tokc.str.ದತ್ತಾಂಶ[0] != '"')
                ಹೋಗು ಸಾಲು_err;
            tokc.str.ದತ್ತಾಂಶ[tokc.str.ಗಾತ್ರ_2 - 2] = 0;
            tccpp_putfile(tokc.str.ದತ್ತಾಂಶ + 1);
            ಮುಂದಿನ();
            /* skip optional level number & advance to next line */
            skip_ಗಮ್ಯ_eol(c);
        }
        ಆದರೆ (file->fd > 0)
            ಒಟ್ಟು_ಸಾಲುಗಳು += file->ಸಾಲು_ಅಂಕೆ - n;
        file->ಸಾಲು_ಅಂಕೆ = n;
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ TOK_ERROR:
    ಸ್ಥಿತಿ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ಆಗ (c != '\n' && c != CH_EOF) {
            ಆದರೆ ((q - buf) < ಗಾತ್ರ(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ಆದರೆ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        ಇಲ್ಲದಿದ್ದರೆ
            tcc_warning("#warning %s", buf);
        ಮುಂದಿನ_nomacro();
        ನಿಲ್ಲಿಸು;
    }
    ಸ್ಥಿತಿ TOK_PRAGMA:
        ಆದರೆ (!pragma_parse(s1))
            ಹೋಗು ignore;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ TOK_LINEFEED:
        ಹೋಗು the_ಕೊನೆ;
    ಪೂರ್ವನಿಯೋಜಿತ:
        /* ignore gas line comment in an 'S' file. */
        ಆದರೆ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            ಹೋಗು ignore;
        ಆದರೆ (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            ಹೋಗು ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_ಗಮ್ಯ_eol(0);
        ಹೋಗು the_ಕೊನೆ;
    }
    skip_ಗಮ್ಯ_eol(1);
 the_ಕೊನೆ:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ಸ್ಥಿರ ಶೂನ್ಯ parse_escape_string(CString *outstr, ಸ್ಥಿರಾಂಕ uint8_t *buf, ಪೂರ್ಣಾಂಕ is_long)
{
    ಪೂರ್ಣಾಂಕ c, n, i;
    ಸ್ಥಿರಾಂಕ uint8_t *p;

    p = buf;
    ಗಾಗಿ(;;) {
        c = *p;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ಆಯ್ಕೆ(c) {
            ಸ್ಥಿತಿ '0': ಸ್ಥಿತಿ '1': ಸ್ಥಿತಿ '2': ಸ್ಥಿತಿ '3':
            ಸ್ಥಿತಿ '4': ಸ್ಥಿತಿ '5': ಸ್ಥಿತಿ '6': ಸ್ಥಿತಿ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ಆದರೆ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ಆದರೆ (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                ಹೋಗು ಕೂಡಿಸು_char_nonext;
            ಸ್ಥಿತಿ 'x': i = 0; ಹೋಗು parse_hex_or_ucn;
            ಸ್ಥಿತಿ 'u': i = 4; ಹೋಗು parse_hex_or_ucn;
            ಸ್ಥಿತಿ 'U': i = 8; ಹೋಗು parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                ಮಾಡು {
                    c = *p;
                    ಆದರೆ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (isnum(c))
                        c = c - '0';
                    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    ಇಲ್ಲದಿದ್ದರೆ
                        ಹೋಗು ಕೂಡಿಸು_hex_or_ucn;
                    n = (ಚಿಹ್ನೆರಹಿತ) n * 16 + c;
                    p++;
                } ಆಗ (--i);
		ಆದರೆ (is_long) {
    ಕೂಡಿಸು_hex_or_ucn:
                    c = n;
		    ಹೋಗು ಕೂಡಿಸು_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ಮುಂದುವರಿ;
            ಸ್ಥಿತಿ 'a':
                c = '\a';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'b':
                c = '\b';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'f':
                c = '\f';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'n':
                c = '\n';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'r':
                c = '\r';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 't':
                c = '\t';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'v':
                c = '\v';
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'e':
                ಆದರೆ (!gnu_ext)
                    ಹೋಗು invalid_escape;
                c = 27;
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ '\'':
            ಸ್ಥಿತಿ '\"':
            ಸ್ಥಿತಿ '\\': 
            ಸ್ಥಿತಿ '?':
                ನಿಲ್ಲಿಸು;
            ಪೂರ್ವನಿಯೋಜಿತ:
            invalid_escape:
                ಆದರೆ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                ಇಲ್ಲದಿದ್ದರೆ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ನಿಲ್ಲಿಸು;
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ಪೂರ್ಣಾಂಕ cont; /* count of continuation bytes */
            ಪೂರ್ಣಾಂಕ skip; /* how many bytes should skip when error occurred */
            ಪೂರ್ಣಾಂಕ i;

            /* decode leading byte */
            ಆದರೆ (c < 0xC2) {
	            skip = 1; ಹೋಗು invalid_utf8_sequence;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } ಇಲ್ಲದಿದ್ದರೆ {
	            skip = 1; ಹೋಗು invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            ಗಾಗಿ (i = 1; i <= cont; i++) {
                ಪೂರ್ಣಾಂಕ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ಆದರೆ (i == 1) {
                    ಆಯ್ಕೆ (c) {
                    ಸ್ಥಿತಿ 0xE0: l = 0xA0; ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ 0xED: h = 0x9F; ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ 0xF0: l = 0x90; ನಿಲ್ಲಿಸು;
                    ಸ್ಥಿತಿ 0xF4: h = 0x8F; ನಿಲ್ಲಿಸು;
                    }
                }

                ಆದರೆ (p[i] < l || p[i] > h) {
                    skip = i; ಹೋಗು invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            ಹೋಗು ಕೂಡಿಸು_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            ಹೋಗು ಕೂಡಿಸು_char_nonext;

        }
        p++;
    ಕೂಡಿಸು_char_nonext:
        ಆದರೆ (!is_long)
            cstr_ccat(outstr, c);
        ಇಲ್ಲದಿದ್ದರೆ {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            /* store as UTF-16 */
            ಆದರೆ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } ಇಲ್ಲದಿದ್ದರೆ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#ಇಲ್ಲದಿದ್ದರೆ
            cstr_wccat(outstr, c);
#ಆದರೆ_ಅಂತ್ಯ
        }
    }
    /* add a trailing '\0' */
    ಆದರೆ (!is_long)
        cstr_ccat(outstr, '\0');
    ಇಲ್ಲದಿದ್ದರೆ
        cstr_wccat(outstr, '\0');
}

ಸ್ಥಿರ ಶೂನ್ಯ parse_string(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಪೂರ್ಣಾಂಕ len)
{
    uint8_t buf[1000], *p = buf;
    ಪೂರ್ಣಾಂಕ is_long, sep;

    ಆದರೆ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ಆದರೆ (len >= ಗಾತ್ರ buf)
        p = tcc_malloc(len + 1);
    ಸ್ಮರಣೆ_ನಕಲು(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ಆದರೆ (p != buf)
        tcc_free(p);

    ಆದರೆ (sep == '\'') {
        ಪೂರ್ಣಾಂಕ char_ಗಾತ್ರ, i, n, c;
        /* XXX: make it portable */
        ಆದರೆ (!is_long)
            tok = TOK_CCHAR, char_ಗಾತ್ರ = 1;
        ಇಲ್ಲದಿದ್ದರೆ
            tok = TOK_LCHAR, char_ಗಾತ್ರ = ಗಾತ್ರ(nwchar_t);
        n = tokcstr.ಗಾತ್ರ_2 / char_ಗಾತ್ರ - 1;
        ಆದರೆ (n < 1)
            tcc_error("empty character constant");
        ಆದರೆ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        ಗಾಗಿ (c = i = 0; i < n; ++i) {
            ಆದರೆ (is_long)
                c = ((nwchar_t *)tokcstr.ದತ್ತಾಂಶ)[i];
            ಇಲ್ಲದಿದ್ದರೆ
                c = (c << 8) | ((ಅಕ್ಷರ *)tokcstr.ದತ್ತಾಂಶ)[i];
        }
        tokc.i = c;
    } ಇಲ್ಲದಿದ್ದರೆ {
        tokc.str.ಗಾತ್ರ_2 = tokcstr.ಗಾತ್ರ_2;
        tokc.str.ದತ್ತಾಂಶ = tokcstr.ದತ್ತಾಂಶ;
        ಆದರೆ (!is_long)
            tok = TOK_STR;
        ಇಲ್ಲದಿದ್ದರೆ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#ವ್ಯಾಖ್ಯಾನಿಸು BN_ಗಾತ್ರ 4

/* bn = (bn << shift) | or_val */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ bn_lshift(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *bn, ಪೂರ್ಣಾಂಕ ಸರಿಸು, ಪೂರ್ಣಾಂಕ or_val)
{
    ಪೂರ್ಣಾಂಕ i;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ v;
    ಆದರೆ (bn[BN_ಗಾತ್ರ - 1] >> (32 - ಸರಿಸು))
	ಹಿಂತಿರುಗಿ ಸರಿಸು;
    ಗಾಗಿ(i=0;i<BN_ಗಾತ್ರ;i++) {
        v = bn[i];
        bn[i] = (v << ಸರಿಸು) | or_val;
        or_val = v >> (32 - ಸರಿಸು);
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಸ್ಥಿರ ಶೂನ್ಯ bn_zero(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *bn)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ(i=0;i<BN_ಗಾತ್ರ;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ಸ್ಥಿರ ಶೂನ್ಯ parse_ಸಂಖ್ಯೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    ಪೂರ್ಣಾಂಕ b, t, ಸರಿಸು, frac_ಬಿಟ್ಟುಗಳು, s, exp_val, ch;
    ಅಕ್ಷರ *q;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ bn[BN_ಗಾತ್ರ];
    ದೀರ್ಘ ದ್ವಿಗುಣ d;

    /*ಸಂಖ್ಯೆ*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ಆದರೆ (t == '.') {
        ಹೋಗು float_frac_parse;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == '0') {
        ಆದರೆ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ಆಗ (1) {
        ಆದರೆ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (isnum(ch))
            t = ch - '0';
        ಇಲ್ಲದಿದ್ದರೆ
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (t >= b)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ) {
        ಅಂಕೆ_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ಆದರೆ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ಆದರೆ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_ಬಿಟ್ಟುಗಳು = 0;
            *q = '\0';
            ಆದರೆ (b == 16)
                ಸರಿಸು = 4;
            ಇಲ್ಲದಿದ್ದರೆ 
                ಸರಿಸು = 1;
            bn_zero(bn);
            q = token_buf;
            ಆಗ (1) {
                t = *q++;
                ಆದರೆ (t == '\0') {
                    ನಿಲ್ಲಿಸು;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= 'a') {
                    t = t - 'a' + 10;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= 'A') {
                    t = t - 'A' + 10;
                } ಇಲ್ಲದಿದ್ದರೆ {
                    t = t - '0';
                }
                frac_ಬಿಟ್ಟುಗಳು -= bn_lshift(bn, ಸರಿಸು, t);
            }
            ಆದರೆ (ch == '.') {
                ch = *p++;
                ಆಗ (1) {
                    t = ch;
                    ಆದರೆ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ನಿಲ್ಲಿಸು;
                    }
                    ಆದರೆ (t >= b)
                        tcc_error("invalid digit");
                    frac_ಬಿಟ್ಟುಗಳು -= bn_lshift(bn, ಸರಿಸು, t);
                    frac_ಬಿಟ್ಟುಗಳು += ಸರಿಸು;
                    ch = *p++;
                }
            }
            ಆದರೆ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ಆದರೆ (ch == '+') {
                ch = *p++;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ಆದರೆ (ch < '0' || ch > '9')
                expect("exponent digits");
            ಆಗ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ಆದರೆ (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (ದೀರ್ಘ ದ್ವಿಗುಣ)bn[3] * 79228162514264337593543950336.0L +
	        (ದೀರ್ಘ ದ್ವಿಗುಣ)bn[2] * 18446744073709551616.0L +
	        (ದೀರ್ಘ ದ್ವಿಗುಣ)bn[1] * 4294967296.0L +
	        (ದೀರ್ಘ ದ್ವಿಗುಣ)bn[0];
            d = ldexpl(d, exp_val - frac_ಬಿಟ್ಟುಗಳು);
            t = toup(ch);
            ಆದರೆ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ದಶಮಾಂಶ)d;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok = TOK_CDOUBLE;
                tokc.d = (ದ್ವಿಗುಣ)d;
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* decimal floats */
            ಆದರೆ (ch == '.') {
                ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ)
                    ಹೋಗು ಅಂಕೆ_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ಆಗ (ch >= '0' && ch <= '9') {
                    ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ)
                        ಹೋಗು ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ಆದರೆ (ch == 'e' || ch == 'E') {
                ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ)
                    ಹೋಗು ಅಂಕೆ_too_long;
                *q++ = ch;
                ch = *p++;
                ಆದರೆ (ch == '-' || ch == '+') {
                    ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ)
                        ಹೋಗು ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ಆದರೆ (ch < '0' || ch > '9')
                    expect("exponent digits");
                ಆಗ (ch >= '0' && ch <= '9') {
                    ಆದರೆ (q >= token_buf + STRING_MAX_ಗಾತ್ರ)
                        ಹೋಗು ಅಂಕೆ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ಆದರೆ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ಖಾಲಿ);
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ಖಾಲಿ);
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ಖಾಲಿ);
            }
        }
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ n, n1;
        ಪೂರ್ಣಾಂಕ lcount, ucount, ov = 0;
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ಆದರೆ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ಆಗ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ಆದರೆ (t == '\0')
                ನಿಲ್ಲಿಸು;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= 'a')
                t = t - 'a' + 10;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= 'A')
                t = t - 'A' + 10;
            ಇಲ್ಲದಿದ್ದರೆ
                t = t - '0';
            ಆದರೆ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ಆದರೆ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        ಗಾಗಿ(;;) {
            t = toup(ch);
            ಆದರೆ (t == 'L') {
                ಆದರೆ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ಆದರೆ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == 'U') {
                ಆದರೆ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } ಇಲ್ಲದಿದ್ದರೆ {
                ನಿಲ್ಲಿಸು;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ಆದರೆ (pp_ಅಭಿವ್ಯಕ್ತಿ)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ಆದರೆ (ucount == 0 && b == 10) {
            ಆದರೆ (lcount <= (LONG_ಗಾತ್ರ == 4)) {
                ಆದರೆ (n >= 0x80000000U)
                    lcount = (LONG_ಗಾತ್ರ == 4) + 1;
            }
            ಆದರೆ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (lcount <= (LONG_ಗಾತ್ರ == 4)) {
                ಆದರೆ (n >= 0x100000000ULL)
                    lcount = (LONG_ಗಾತ್ರ == 4) + 1;
                ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (n >= 0x80000000U)
                    ucount = 1;
            }
            ಆದರೆ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ಆದರೆ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ಆದರೆ (lcount) {
            tok = TOK_CLONG;
            ಆದರೆ (lcount == 2)
                tok = TOK_CLLONG;
	}
	ಆದರೆ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ಆದರೆ (ch)
        tcc_error("invalid number");
}


#ವ್ಯಾಖ್ಯಾನಿಸು PARSE2(c1, tok1, c2, tok2)              \
    ಸ್ಥಿತಿ c1:                                    \
        PEEKC(c, p);                            \
        ಆದರೆ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } ಇಲ್ಲದಿದ್ದರೆ {                                \
            tok = tok1;                         \
        }                                       \
        ನಿಲ್ಲಿಸು;

/* return next token without macro substitution */
ಸ್ಥಿರ ಶೂನ್ಯ ಮುಂದಿನ_nomacro(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ h;

    p = file->buf_ptr;
 redo_no_ಆರಂಭ:
    c = *p;
    ಆಯ್ಕೆ(c) {
    ಸ್ಥಿತಿ ' ':
    ಸ್ಥಿತಿ '\t':
        tok = c;
        p++;
 maybe_space:
        ಆದರೆ (parse_flags & PARSE_FLAG_SPACES)
            ಹೋಗು keep_tok_flags;
        ಆಗ (isidnum_ಕೋಷ್ಟಕ[*p - CH_EOF] & IS_SPC)
            ++p;
        ಹೋಗು redo_no_ಆರಂಭ;
    ಸ್ಥಿತಿ '\f':
    ಸ್ಥಿತಿ '\v':
    ಸ್ಥಿತಿ '\r':
        p++;
        ಹೋಗು redo_no_ಆರಂಭ;
    ಸ್ಥಿತಿ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ಆದರೆ (c == '\\')
            ಹೋಗು parse_simple;
        ಆದರೆ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ಆದರೆ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                ಹೋಗು maybe_newline;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->ifdef_ರಾಶಿ_ptr != file->ifdef_ರಾಶಿ_ptr) {
                tcc_error("missing #endif");
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->include_ರಾಶಿ_ptr == s1->include_ರಾಶಿ) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ಆದರೆ (tok_flags & TOK_FLAG_ENDIF) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INC_DEBUG
                    ಬರೆ("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ಖಾಲಿ));
#ಆದರೆ_ಅಂತ್ಯ
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
                ಹೋಗು maybe_newline;
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಹೋಗು redo_no_ಆರಂಭ;
        }
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ '\n':
        file->ಸಾಲು_ಅಂಕೆ++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ಆದರೆ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            ಹೋಗು redo_no_ಆರಂಭ;
        tok = TOK_LINEFEED;
        ಹೋಗು keep_tok_flags;

    ಸ್ಥಿತಿ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ಆದರೆ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            ಹೋಗು maybe_newline;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } ಇಲ್ಲದಿದ್ದರೆ {
#ಆದರೆ !defined(TCC_ಗುರಿ_ARM) && !defined(TCC_ಗುರಿ_ARM64)
                ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_ಸಾಲು_comment(p - 1);
                    ಹೋಗು redo_no_ಆರಂಭ;
                } ಇಲ್ಲದಿದ್ದರೆ
#ಆದರೆ_ಅಂತ್ಯ
                {
                    tok = '#';
                }
            }
        }
        ನಿಲ್ಲಿಸು;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    ಸ್ಥಿತಿ '$':
        ಆದರೆ (!(isidnum_ಕೋಷ್ಟಕ['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            ಹೋಗು parse_simple;

    ಸ್ಥಿತಿ 'a': ಸ್ಥಿತಿ 'b': ಸ್ಥಿತಿ 'c': ಸ್ಥಿತಿ 'd':
    ಸ್ಥಿತಿ 'e': ಸ್ಥಿತಿ 'f': ಸ್ಥಿತಿ 'g': ಸ್ಥಿತಿ 'h':
    ಸ್ಥಿತಿ 'i': ಸ್ಥಿತಿ 'j': ಸ್ಥಿತಿ 'k': ಸ್ಥಿತಿ 'l':
    ಸ್ಥಿತಿ 'm': ಸ್ಥಿತಿ 'n': ಸ್ಥಿತಿ 'o': ಸ್ಥಿತಿ 'p':
    ಸ್ಥಿತಿ 'q': ಸ್ಥಿತಿ 'r': ಸ್ಥಿತಿ 's': ಸ್ಥಿತಿ 't':
    ಸ್ಥಿತಿ 'u': ಸ್ಥಿತಿ 'v': ಸ್ಥಿತಿ 'w': ಸ್ಥಿತಿ 'x':
    ಸ್ಥಿತಿ 'y': ಸ್ಥಿತಿ 'z': 
    ಸ್ಥಿತಿ 'A': ಸ್ಥಿತಿ 'B': ಸ್ಥಿತಿ 'C': ಸ್ಥಿತಿ 'D':
    ಸ್ಥಿತಿ 'E': ಸ್ಥಿತಿ 'F': ಸ್ಥಿತಿ 'G': ಸ್ಥಿತಿ 'H':
    ಸ್ಥಿತಿ 'I': ಸ್ಥಿತಿ 'J': ಸ್ಥಿತಿ 'K': 
    ಸ್ಥಿತಿ 'M': ಸ್ಥಿತಿ 'N': ಸ್ಥಿತಿ 'O': ಸ್ಥಿತಿ 'P':
    ಸ್ಥಿತಿ 'Q': ಸ್ಥಿತಿ 'R': ಸ್ಥಿತಿ 'S': ಸ್ಥಿತಿ 'T':
    ಸ್ಥಿತಿ 'U': ಸ್ಥಿತಿ 'V': ಸ್ಥಿತಿ 'W': ಸ್ಥಿತಿ 'X':
    ಸ್ಥಿತಿ 'Y': ಸ್ಥಿತಿ 'Z': 
    ಸ್ಥಿತಿ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ಆಗ (c = *++p, isidnum_ಕೋಷ್ಟಕ[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ಆದರೆ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_ಗಾತ್ರ - 1);
            pts = &hash_ident[h];
            ಗಾಗಿ(;;) {
                ts = *pts;
                ಆದರೆ (!ts)
                    ನಿಲ್ಲಿಸು;
                ಆದರೆ (ts->len == len && !memcmp(ts->str, p1, len))
                    ಹೋಗು token_ಸಿಕ್ಕಿತು;
                pts = &(ts->hash_ಮುಂದಿನ);
            }
            ts = tok_alloc_new(pts, (ಅಕ್ಷರ *) p1, len);
        token_ಸಿಕ್ಕಿತು: ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (ಅಕ್ಷರ *) p1, len);
            p--;
            PEEKC(c, p);
            ಆಗ (isidnum_ಕೋಷ್ಟಕ[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.ದತ್ತಾಂಶ, tokcstr.ಗಾತ್ರ_2);
        }
        tok = ts->tok;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 'L':
        t = p[1];
        ಆದರೆ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ಆದರೆ (c == '\'' || c == '\"') {
                is_long = 1;
                ಹೋಗು str_const;
            }
            *--p = c = 'L';
        }
        ಹೋಗು parse_ident_fast;

    ಸ್ಥಿತಿ '0': ಸ್ಥಿತಿ '1': ಸ್ಥಿತಿ '2': ಸ್ಥಿತಿ '3':
    ಸ್ಥಿತಿ '4': ಸ್ಥಿತಿ '5': ಸ್ಥಿತಿ '6': ಸ್ಥಿತಿ '7':
    ಸ್ಥಿತಿ '8': ಸ್ಥಿತಿ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_ಅಂಕೆ:
        cstr_reset(&tokcstr);
        ಗಾಗಿ(;;) {
            cstr_ccat(&tokcstr, t);
            ಆದರೆ (!((isidnum_ಕೋಷ್ಟಕ[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((ಅಕ್ಷರ*)tokcstr.ದತ್ತಾಂಶ)[0] == '0'
                                && toup(((ಅಕ್ಷರ*)tokcstr.ದತ್ತಾಂಶ)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ನಿಲ್ಲಿಸು;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.ಗಾತ್ರ_2 = tokcstr.ಗಾತ್ರ_2;
        tokc.str.ದತ್ತಾಂಶ = tokcstr.ದತ್ತಾಂಶ;
        tok = TOK_PPNUM;
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ಆದರೆ (isnum(c)) {
            t = '.';
            ಹೋಗು parse_ಅಂಕೆ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((isidnum_ಕೋಷ್ಟಕ['.' - CH_EOF] & IS_ID)
                   && (isidnum_ಕೋಷ್ಟಕ[c - CH_EOF] & (IS_ID|IS_ಅಂಕೆ))) {
            *--p = c = '.';
            ಹೋಗು parse_ident_fast;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '.') {
            PEEKC(c, p);
            ಆದರೆ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } ಇಲ್ಲದಿದ್ದರೆ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '.';
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '\'':
    ಸ್ಥಿತಿ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ಆದರೆ (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.ಗಾತ್ರ_2 = tokcstr.ಗಾತ್ರ_2;
        tokc.str.ದತ್ತಾಂಶ = tokcstr.ದತ್ತಾಂಶ;
        tok = TOK_PPSTR;
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ '<':
        PEEKC(c, p);
        ಆದರೆ (c == '=') {
            p++;
            tok = TOK_LE;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '<') {
            PEEKC(c, p);
            ಆದರೆ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok = TOK_SHL;
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = TOK_LT;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ '>':
        PEEKC(c, p);
        ಆದರೆ (c == '=') {
            p++;
            tok = TOK_GE;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '>') {
            PEEKC(c, p);
            ಆದರೆ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok = TOK_SAR;
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = TOK_GT;
        }
        ನಿಲ್ಲಿಸು;
        
    ಸ್ಥಿತಿ '&':
        PEEKC(c, p);
        ಆದರೆ (c == '&') {
            p++;
            tok = TOK_LAND;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '&';
        }
        ನಿಲ್ಲಿಸು;
        
    ಸ್ಥಿತಿ '|':
        PEEKC(c, p);
        ಆದರೆ (c == '|') {
            p++;
            tok = TOK_LOR;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '|';
        }
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ '+':
        PEEKC(c, p);
        ಆದರೆ (c == '+') {
            p++;
            tok = TOK_INC;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '=') {
            p++;
            tok = TOK_A_ಕೂಡಿಸು;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '+';
        }
        ನಿಲ್ಲಿಸು;
        
    ಸ್ಥಿತಿ '-':
        PEEKC(c, p);
        ಆದರೆ (c == '-') {
            p++;
            tok = TOK_DEC;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '-';
        }
        ನಿಲ್ಲಿಸು;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    ಸ್ಥಿತಿ '/':
        PEEKC(c, p);
        ಆದರೆ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            ಹೋಗು maybe_space;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '/') {
            p = parse_ಸಾಲು_comment(p);
            tok = ' ';
            ಹೋಗು maybe_space;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok = '/';
        }
        ನಿಲ್ಲಿಸು;
        
        /* simple tokens */
    ಸ್ಥಿತಿ '@': /* only used in assembler */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM /* comment on arm asm */
        ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_ಸಾಲು_comment(p);
            ಹೋಗು redo_no_ಆರಂಭ;
        }
#ಆದರೆ_ಅಂತ್ಯ
    ಸ್ಥಿತಿ '(':
    ಸ್ಥಿತಿ ')':
    ಸ್ಥಿತಿ '[':
    ಸ್ಥಿತಿ ']':
    ಸ್ಥಿತಿ '{':
    ಸ್ಥಿತಿ '}':
    ಸ್ಥಿತಿ ',':
    ಸ್ಥಿತಿ ';':
    ಸ್ಥಿತಿ ':':
    ಸ್ಥಿತಿ '?':
    ಸ್ಥಿತಿ '~':
    parse_simple:
        tok = c;
        p++;
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ 0xEF: /* UTF8 BOM ? */
        ಆದರೆ (p[1] == 0xBB && p[2] == 0xBF && p == file->ಬಫರ್) {
            p += 3;
            ಹೋಗು redo_no_ಆರಂಭ;
        }
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಆದರೆ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    ಹೋಗು parse_ident_fast;
        ಆದರೆ (parse_flags & PARSE_FLAG_ASM_FILE)
            ಹೋಗು parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ನಿಲ್ಲಿಸು;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ಆದರೆ defined(PARSE_DEBUG)
    ಬರೆ("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#ಆದರೆ_ಅಂತ್ಯ
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PP_DEBUG
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ indent;
ಸ್ಥಿರ ಶೂನ್ಯ define_print(TCCState *s1, ಪೂರ್ಣಾಂಕ v);
ಸ್ಥಿರ ಶೂನ್ಯ pp_print(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, ಪೂರ್ಣಾಂಕ v, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *str)
{
    FILE *fp = tcc_state->ppfp;

    ಆದರೆ (ಸಂದೇಶ[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಸಂದೇಶ[0] == '+')
         ++indent, ++ಸಂದೇಶ;
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಸಂದೇಶ[0] == '-')
        --indent, ++ಸಂದೇಶ;

    fprintf(fp, "%*s", indent, "");
    ಆದರೆ (ಸಂದೇಶ[0] == '#') {
        define_print(tcc_state, v);
    } ಇಲ್ಲದಿದ್ದರೆ {
        tok_print(str, v ? "%s %s" : "%s", ಸಂದೇಶ, get_tok_str(v, 0));
    }
}
#ವ್ಯಾಖ್ಯಾನಿಸು PP_PRINT(x) pp_print x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PP_PRINT(x)
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ *macro_arg_subst(Sym **nested_list, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *macro_str, Sym *ವಾದಗಳು)
{
    ಪೂರ್ಣಾಂಕ t, t0, t1, t2, n;
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    ಗಾಗಿ (s = ವಾದಗಳು, n = 0; s; s = s->prev, ++n);
    ಆಗ (n--) {
        ಗಾಗಿ (s = ವಾದಗಳು, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#ಆದರೆ_ಅಂತ್ಯ

    tok_str_new(&str);
    t0 = t1 = 0;
    ಆಗ(1) {
        TOK_GET(&t, &macro_str, &cval);
        ಆದರೆ (!t)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (t == '#') {
            /* stringize */
            ಮಾಡು t = *macro_str++; ಆಗ (t == ' ');
            s = sym_find2(ವಾದಗಳು, t);
            ಆದರೆ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ಆಗ (*st != TOK_EOF) {
                    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ಆಗ (*s) {
                        ಆದರೆ (t == TOK_PPSTR && *s != '\'')
                            ಕೂಡಿಸು_char(&tokcstr, *s);
                        ಇಲ್ಲದಿದ್ದರೆ
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.ಗಾತ್ರ_2 = tokcstr.ಗಾತ್ರ_2;
                cval.str.ದತ್ತಾಂಶ = tokcstr.ದತ್ತಾಂಶ;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_ಕೂಡಿಸು(&str, '#');
#ಆದರೆ_ಅಂತ್ಯ
            } ಇಲ್ಲದಿದ್ದರೆ {
                expect("macro parameter after '#'");
            }
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t >= TOK_IDENT) {
            s = sym_find2(ವಾದಗಳು, t);
            ಆದರೆ (s) {
                st = s->d;
                n = 0;
                ಆಗ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ಆದರೆ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ಆದರೆ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ಪೂರ್ಣಾಂಕ c = str.str[str.len - 1];
                        ಆಗ (str.str[--str.len] != ',')
                            ;
                        ಆದರೆ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } ಇಲ್ಲದಿದ್ದರೆ {
                            /* suppress '##' and add variable */
                            str.len++;
                            ಆದರೆ (c == ' ')
                                str.str[str.len++] = c;
                            ಹೋಗು ಕೂಡಿಸು_var;
                        }
                    } ಇಲ್ಲದಿದ್ದರೆ {
                        ಆದರೆ (*st == TOK_EOF)
                            tok_str_ಕೂಡಿಸು(&str, TOK_PLCHLDR);
                    }
                } ಇಲ್ಲದಿದ್ದರೆ {
            ಕೂಡಿಸು_var:
		    ಆದರೆ (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_ಕೂಡಿಸು(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                ಆಗ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok_str_ಕೂಡಿಸು(&str, t);
            }
        } ಇಲ್ಲದಿದ್ದರೆ {
            tok_str_add2(&str, t, &cval);
        }
        ಆದರೆ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_ಕೂಡಿಸು(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ಹಿಂತಿರುಗಿ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಪೂರ್ಣಾಂಕ *macro_twosharps(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *ptr0)
{
    ಪೂರ್ಣಾಂಕ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    ಗಾಗಿ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ಆದರೆ (t1 == 0)
            ನಿಲ್ಲಿಸು;
        ಗಾಗಿ (;;) {
            n = 0;
            ಆಗ ((t2 = ptr[n]) == ' ')
                ++n;
            ಆದರೆ (t2 != TOK_PPJOIN)
                ನಿಲ್ಲಿಸು;
            ptr += n;
            ಆಗ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ಆದರೆ (t2 == TOK_PLCHLDR)
                ಮುಂದುವರಿ;
            ಆದರೆ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ಆದರೆ (tokcstr.ಗಾತ್ರ_2) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.ಗಾತ್ರ_2);
            ಸ್ಮರಣೆ_ನಕಲು(file->ಬಫರ್, tokcstr.ದತ್ತಾಂಶ, tokcstr.ಗಾತ್ರ_2);
            tok_flags = 0; /* don't interpret '#' */
            ಗಾಗಿ (n = 0;;n = l) {
                ಮುಂದಿನ_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ಆದರೆ (*file->buf_ptr == 0)
                    ನಿಲ್ಲಿಸು;
                tok_str_ಕೂಡಿಸು(&macro_str1, ' ');
                l = file->buf_ptr - file->ಬಫರ್;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->ಬಫರ್ + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ಆದರೆ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_ಕೂಡಿಸು(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ಹಿಂತಿರುಗಿ macro_str1.str;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ಪೂರ್ಣಾಂಕ c;
    ಗಾಗಿ (;;) {
        PEEKC(c, p);
        ಆಯ್ಕೆ (c) {
        ಸ್ಥಿತಿ '/':
            PEEKC(c, p);
            ಆದರೆ (c == '*')
                p = parse_comment(p);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '/')
                p = parse_ಸಾಲು_comment(p);
            ಇಲ್ಲದಿದ್ದರೆ {
                c = *--p = '/';
                ಹೋಗು leave;
            }
            --p, c = ' ';
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ ' ': ಸ್ಥಿತಿ '\t':
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ '\f': ಸ್ಥಿತಿ '\v': ಸ್ಥಿತಿ '\r':
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ '\n':
            file->ಸಾಲು_ಅಂಕೆ++, tok_flags |= TOK_FLAG_BOL;
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ: leave:
            file->buf_ptr = p;
            ಹಿಂತಿರುಗಿ c;
        }
        ಆದರೆ (ws_str)
            tok_str_ಕೂಡಿಸು(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಮುಂದಿನ_argstream(Sym **nested_list, TokenString *ws_str)
{
    ಪೂರ್ಣಾಂಕ t;
    Sym *sa;

    ಆಗ (macro_ptr) {
        ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *m = macro_ptr;
        ಆಗ ((t = *m) != 0) {
            ಆದರೆ (ws_str) {
                ಆದರೆ (t != ' ')
                    ಹಿಂತಿರುಗಿ t;
                ++m;
            } ಇಲ್ಲದಿದ್ದರೆ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ಹಿಂತಿರುಗಿ tok;
            }
        }
        ಕೊನೆ_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ಆದರೆ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ಆದರೆ (ws_str) {
        ಹಿಂತಿರುಗಿ peek_file(ws_str);
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಮುಂದಿನ_nomacro();
        ಆದರೆ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ಹಿಂತಿರುಗಿ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ಪೂರ್ಣಾಂಕ t;
    ಪೂರ್ಣಾಂಕ v = s->v;

    PP_PRINT(("#", v, s->d));
    ಆದರೆ (s->d) {
        ಪೂರ್ಣಾಂಕ *mstr = s->d;
        ಪೂರ್ಣಾಂಕ *jstr;
        Sym *sa;
        ಪೂರ್ಣಾಂಕ ret;

        ಆದರೆ (s->type.t & MACRO_FUNC) {
            ಪೂರ್ಣಾಂಕ saved_parse_flags = parse_flags;
            TokenString str;
            ಪೂರ್ಣಾಂಕ parlevel, i;
            Sym *sa1, *ವಾದಗಳು;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = ಮುಂದಿನ_argstream(nested_list, &str);
            ಆದರೆ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ಆದರೆ (parse_flags & PARSE_FLAG_SPACES)
                    ಗಾಗಿ (i = 0; i < str.len; i++)
                        tok_str_ಕೂಡಿಸು(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ಹಿಂತಿರುಗಿ 0;
            } ಇಲ್ಲದಿದ್ದರೆ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            ವಾದಗಳು = ಖಾಲಿ;
            sa = s->ಮುಂದಿನ;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            ಗಾಗಿ(;;) {
                ಮಾಡು {
                    t = ಮುಂದಿನ_argstream(nested_list, ಖಾಲಿ);
                } ಆಗ (t == ' ' || --i);

                ಆದರೆ (!sa) {
                    ಆದರೆ (t == ')') /* handle '()' case */
                        ನಿಲ್ಲಿಸು;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            ಖಾಲಿಗಳು_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ಆಗ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ಆದರೆ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ಆದರೆ (t == '(')
                        parlevel++;
                    ಆದರೆ (t == ')')
                        parlevel--;
                    ಆದರೆ (t == ' ')
                        str.need_spc |= 1;
                    ಇಲ್ಲದಿದ್ದರೆ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = ಮುಂದಿನ_argstream(nested_list, ಖಾಲಿ);
                }
                tok_str_ಕೂಡಿಸು(&str, TOK_EOF);
                sa1 = sym_push2(&ವಾದಗಳು, sa->v & ~SYM_ಕ್ಷೇತ್ರ, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->ಮುಂದಿನ;
                ಆದರೆ (t == ')') {
                    ಆದರೆ (!sa)
                        ನಿಲ್ಲಿಸು;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ಆದರೆ (sa->type.t && gnu_ext)
                        ಹೋಗು ಖಾಲಿಗಳು_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, ವಾದಗಳು);
            /* free memory */
            sa = ವಾದಗಳು;
            ಆಗ (sa) {
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
        ಆದರೆ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ಆದರೆ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ಆದರೆ (jstr != mstr)
            tok_str_free_str(jstr);
        ಆದರೆ (mstr != s->d)
            tok_str_free_str(mstr);
        ಹಿಂತಿರುಗಿ ret;

    } ಇಲ್ಲದಿದ್ದರೆ {
        CValue cval;
        ಅಕ್ಷರ buf[32], *cstrval = buf;

        /* special macros */
        ಆದರೆ (v == TOK_ಸಾಲು_2 || v == TOK___COUNTER__) {
            t = v == TOK_ಸಾಲು_2 ? file->ಸಾಲು_ಅಂಕೆ : pp_counter++;
            snprintf(buf, ಗಾತ್ರ(buf), "%d", t);
            t = TOK_PPNUM;
            ಹೋಗು ಕೂಡಿಸು_cstr1;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == TOK___FILE__) {
            cstrval = file->filename;
            ಹೋಗು ಕೂಡಿಸು_cstr;

        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (v == TOK___DATE__ || v == TOK_ಸಮಯ) {
            time_t ti;
            ರಚನೆ tm *tm;
            ಸಮಯ(&ti);
            tm = localtime(&ti);
            ಆದರೆ (v == TOK___DATE__) {
                ಸ್ಥಿರ ಅಕ್ಷರ ಸ್ಥಿರಾಂಕ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, ಗಾತ್ರ(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } ಇಲ್ಲದಿದ್ದರೆ {
                snprintf(buf, ಗಾತ್ರ(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        ಕೂಡಿಸು_cstr:
            t = TOK_STR;
        ಕೂಡಿಸು_cstr1:
            cval.str.ಗಾತ್ರ_2 = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(cstrval) + 1;
            cval.str.ದತ್ತಾಂಶ = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ಹಿಂತಿರುಗಿ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *macro_str
    )
{
    Sym *s;
    ಪೂರ್ಣಾಂಕ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PP_DEBUG
    ಪೂರ್ಣಾಂಕ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#ಆದರೆ_ಅಂತ್ಯ

    ಆಗ (1) {
        TOK_GET(&t, &macro_str, &cval);
        ಆದರೆ (t == 0 || t == TOK_EOF)
            ನಿಲ್ಲಿಸು;
        ಆದರೆ (t >= TOK_IDENT) {
            s = define_ಕಂಡುಹಿಡಿ(t);
            ಆದರೆ (s == ಖಾಲಿ || nosubst)
                ಹೋಗು no_subst;
            /* if nested substitution, do nothing */
            ಆದರೆ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_ಕ್ಷೇತ್ರ;
                ಹೋಗು no_subst;
            }
            str = tok_str_alloc();
            str->str = (ಪೂರ್ಣಾಂಕ*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ಆದರೆ (macro_ರಾಶಿ != str) {
                /* already finished by reading function macro arguments */
                ನಿಲ್ಲಿಸು;
            }
            macro_str = macro_ptr;
            ಕೊನೆ_macro ();
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == ' ') {
            ಆದರೆ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } ಇಲ್ಲದಿದ್ದರೆ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ಆದರೆ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ಆದರೆ (t == TOK_DEFINED && pp_ಅಭಿವ್ಯಕ್ತಿ)
                nosubst = 1;
        }
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ PP_DEBUG
    tok_str_ಕೂಡಿಸು(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ nosubst;
}

/* return next token with macro substitution */
ST_FUNC ಶೂನ್ಯ ಮುಂದಿನ(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ t;
    ಆಗ (macro_ptr) {
redo:
        t = *macro_ptr;
        ಆದರೆ (TOK_HAS_ಮೌಲ್ಯ(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ಆದರೆ (t == TOK_LINENUM) {
                file->ಸಾಲು_ಅಂಕೆ = tokc.i;
                ಹೋಗು redo;
            }
            ಹೋಗು convert;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == 0) {
            /* end of macro or unget token string */
            ಕೊನೆ_macro();
            ಮುಂದುವರಿ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_EOF) {
            /* do nothing */
        } ಇಲ್ಲದಿದ್ದರೆ {
            ++macro_ptr;
            t &= ~SYM_ಕ್ಷೇತ್ರ; /* remove 'nosubst' marker */
            ಆದರೆ (t == '\\') {
                ಆದರೆ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ಹಿಂತಿರುಗಿ;
    }

    ಮುಂದಿನ_nomacro();
    t = tok;
    ಆದರೆ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_ಕಂಡುಹಿಡಿ(t);
        ಆದರೆ (s) {
            Sym *nested_list = ಖಾಲಿ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_ಕೂಡಿಸು(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            ಹೋಗು redo;
        }
        ಹಿಂತಿರುಗಿ;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ಆದರೆ (t == TOK_PPNUM) {
        ಆದರೆ  (parse_flags & PARSE_FLAG_TOK_ಅಂಕೆ)
            parse_ಸಂಖ್ಯೆ(tokc.str.ದತ್ತಾಂಶ);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_PPSTR) {
        ಆದರೆ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.ದತ್ತಾಂಶ, tokc.str.ಗಾತ್ರ_2 - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN ಶೂನ್ಯ unget_tok(ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_tok)
{
    TokenString *str = &unget_buf;
    ಪೂರ್ಣಾಂಕ alloc = 0;
    ಆದರೆ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ಆದರೆ (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_ಕೂಡಿಸು(str, 0);
    begin_macro(str, alloc);
    tok = ಕೊನೆಯ_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ ಗುರಿ_os_defs =
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    "_WIN32\0"
# ಆದರೆ PTR_ಗಾತ್ರ == 8
    "_WIN64\0"
# endif
#ಇಲ್ಲದಿದ್ದರೆ
# ಆದರೆ defined TCC_ಗುರಿ_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# ಇಲ್ಲದಿದ್ದರೆ
    "__linux__\0"
    "__linux\0"
#  ಆದರೆ TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#ಆದರೆ_ಅಂತ್ಯ
    ;

ಸ್ಥಿರ ಶೂನ್ಯ putdef(CString *cs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ಸ್ಥಿರ ಶೂನ್ಯ putdefs(CString *cs, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    ಆಗ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_predefs(TCCState *s1, CString *cs, ಪೂರ್ಣಾಂಕ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_ಆವೃತ್ತಿ[4]);
    putdefs(cs, ಗುರಿ_machine_defs);
    putdefs(cs, ಗುರಿ_os_defs);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    ಆದರೆ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ಆದರೆ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ)
      putdef(cs, "__TCC_RUN__");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ಆದರೆ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#ಆದರೆ_ಅಂತ್ಯ
    ಆದರೆ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ಆದರೆ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ಆದರೆ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ಆದರೆ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_ಗಾತ್ರ);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_ಗಾತ್ರ);
    ಆದರೆ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ಆದರೆ CONFIG_TCC_PREDEFS
        #ಅನ್ತರ್ಭಾವ "tccdefs_.h" /* include as strings */
#ಇಲ್ಲದಿದ್ದರೆ
        "#include <tccdefs.h>\n" /* load at runtime */
#ಆದರೆ_ಅಂತ್ಯ
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC ಶೂನ್ಯ preprocess_ಆರಂಭ(TCCState *s1, ಪೂರ್ಣಾಂಕ filetype)
{
    ಪೂರ್ಣಾಂಕ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ರಾಶಿ_ptr = s1->include_ರಾಶಿ;
    s1->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ;
    file->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ_ptr;
    pp_ಅಭಿವ್ಯಕ್ತಿ = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ರಾಶಿ[0] = 0;
    s1->pack_ರಾಶಿ_ptr = s1->pack_ರಾಶಿ;

    ಗಣ_idnum('$', s1->dollars_ಒಳ_identifiers ? IS_ID : 0);
    ಗಣ_idnum('.', is_asm ? IS_ID : 0);

    ಆದರೆ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ಆದರೆ (s1->cmdline_defs.ಗಾತ್ರ_2)
          cstr_cat(&cstr, s1->cmdline_defs.ದತ್ತಾಂಶ, s1->cmdline_defs.ಗಾತ್ರ_2);
        ಆದರೆ (s1->cmdline_incl.ಗಾತ್ರ_2)
          cstr_cat(&cstr, s1->cmdline_incl.ದತ್ತಾಂಶ, s1->cmdline_incl.ಗಾತ್ರ_2);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ರಾಶಿ_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.ಗಾತ್ರ_2);
        ಸ್ಮರಣೆ_ನಕಲು(file->ಬಫರ್, cstr.ದತ್ತಾಂಶ, cstr.ಗಾತ್ರ_2);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC ಶೂನ್ಯ preprocess_ಕೊನೆ(TCCState *s1)
{
    ಆಗ (macro_ರಾಶಿ)
        ಕೊನೆ_macro();
    macro_ptr = ಖಾಲಿ;
    ಆಗ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ಪೂರ್ಣಾಂಕ ಗಣ_idnum(ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ val)
{
    ಪೂರ್ಣಾಂಕ prev = isidnum_ಕೋಷ್ಟಕ[c - CH_EOF];
    isidnum_ಕೋಷ್ಟಕ[c - CH_EOF] = val;
    ಹಿಂತಿರುಗಿ prev;
}

ST_FUNC ಶೂನ್ಯ tccpp_new(TCCState *s)
{
    ಪೂರ್ಣಾಂಕ i, c;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, *r;

    /* init isid table */
    ಗಾಗಿ(i = CH_EOF; i<128; i++)
        ಗಣ_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_ಅಂಕೆ
            : 0);

    ಗಾಗಿ(i = 128; i<256; i++)
        ಗಣ_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_ಗಾತ್ರ);
    tal_new(&tokstr_alloc, TOKSTR_TAL_ಗಾತ್ರ);

    memset(hash_ident, 0, TOK_HASH_ಗಾತ್ರ * ಗಾತ್ರ(TokenSym *));
    memset(s->cached_includes_hash, 0, ಗಾತ್ರ s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_ಗಾತ್ರ);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_ಗಾತ್ರ);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_ಗಾತ್ರ);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ಆಗ (*p) {
        r = p;
        ಗಾಗಿ(;;) {
            c = *r++;
            ಆದರೆ (c == '\0')
                ನಿಲ್ಲಿಸು;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ತಳ್ಳು(TOK_ಸಾಲು_2, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
    define_ತಳ್ಳು(TOK___FILE__, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
    define_ತಳ್ಳು(TOK___DATE__, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
    define_ತಳ್ಳು(TOK_ಸಮಯ, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
    define_ತಳ್ಳು(TOK___COUNTER__, MACRO_OBJ, ಖಾಲಿ, ಖಾಲಿ);
}

ST_FUNC ಶೂನ್ಯ tccpp_delete(TCCState *s)
{
    ಪೂರ್ಣಾಂಕ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ಆದರೆ (n > ಒಟ್ಟು_idents)
        ಒಟ್ಟು_idents = n;
    ಗಾಗಿ (i = n; --i >= 0;)
        tal_free(&toksym_alloc, ಕೋಷ್ಟಕ_ident[i]);
    tcc_free(ಕೋಷ್ಟಕ_ident);
    ಕೋಷ್ಟಕ_ident = ಖಾಲಿ;

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

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pp_need_space(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b);

ಸ್ಥಿರ ಶೂನ್ಯ tok_print(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ಪೂರ್ಣಾಂಕ t, t0, s;
    CValue cval;

    va_start(ap, ಸಂದೇಶ);
    vfprintf(fp, ಸಂದೇಶ, ap);
    va_end(ap);

    s = t0 = 0;
    ಆಗ (str) {
	TOK_GET(&t, &str, &cval);
	ಆದರೆ (t == 0 || t == TOK_EOF)
	    ನಿಲ್ಲಿಸು;
        ಆದರೆ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ಸ್ಥಿರ ಶೂನ್ಯ pp_ಸಾಲು(TCCState *s1, BufferedFile *f, ಪೂರ್ಣಾಂಕ level)
{
    ಪೂರ್ಣಾಂಕ d = f->ಸಾಲು_ಅಂಕೆ - f->ಸಾಲು_ref;

    ಆದರೆ (s1->dflag & 4)
	ಹಿಂತಿರುಗಿ;

    ಆದರೆ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (level == 0 && f->ಸಾಲು_ref && d < 8) {
	ಆಗ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->ಸಾಲು_ಅಂಕೆ, f->filename);
    } ಇಲ್ಲದಿದ್ದರೆ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->ಸಾಲು_ಅಂಕೆ, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->ಸಾಲು_ref = f->ಸಾಲು_ಅಂಕೆ;
}

ಸ್ಥಿರ ಶೂನ್ಯ define_print(TCCState *s1, ಪೂರ್ಣಾಂಕ v)
{
    FILE *fp;
    Sym *s;

    s = define_ಕಂಡುಹಿಡಿ(v);
    ಆದರೆ (ಖಾಲಿ == s || ಖಾಲಿ == s->d)
        ಹಿಂತಿರುಗಿ;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ಖಾಲಿ));
    ಆದರೆ (s->type.t & MACRO_FUNC) {
        Sym *a = s->ಮುಂದಿನ;
        fprintf(fp,"(");
        ಆದರೆ (a)
            ಗಾಗಿ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ಖಾಲಿ));
                ಆದರೆ (!(a = a->ಮುಂದಿನ))
                    ನಿಲ್ಲಿಸು;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ಸ್ಥಿರ ಶೂನ್ಯ pp_debug_ನಿರೂಪಿಸುತ್ತದೆ(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ v, t;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *vs;
    FILE *fp;

    t = pp_debug_tok;
    ಆದರೆ (t == 0)
        ಹಿಂತಿರುಗಿ;

    file->ಸಾಲು_ಅಂಕೆ--;
    pp_ಸಾಲು(s1, file, 0);
    file->ಸಾಲು_ref = ++file->ಸಾಲು_ಅಂಕೆ;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ಖಾಲಿ);
    ಆದರೆ (t == TOK_DEFINE) {
        define_print(s1, v);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_ತಳ್ಳು_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (t == TOK_ತೆಗೆ_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pp_need_space(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    ಹಿಂತಿರುಗಿ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ pp_check_he0xE(ಪೂರ್ಣಾಂಕ t, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p)
{
    ಆದರೆ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ಹಿಂತಿರುಗಿ 'E';
    ಹಿಂತಿರುಗಿ t;
}

/* Preprocess the current file */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ಪೂರ್ಣಾಂಕ token_ನೋಡಿದ, spcs, level;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
    ಅಕ್ಷರ white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ಆದರೆ (s1->Pflag == ಸಾಲು_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_ಅಂಕೆ, s1->Pflag = 1;

    ಆದರೆ (s1->do_bench) {
	/* for PP benchmarks */
	ಮಾಡು ಮುಂದಿನ(); ಆಗ (tok != TOK_EOF);
	ಹಿಂತಿರುಗಿ 0;
    }

    token_ನೋಡಿದ = TOK_LINEFEED, spcs = 0, level = 0;
    ಆದರೆ (file->prev)
        pp_ಸಾಲು(s1, file->prev, level++);
    pp_ಸಾಲು(s1, file, level);

    ಗಾಗಿ (;;) {
        iptr = s1->include_ರಾಶಿ_ptr;
        ಮುಂದಿನ();
        ಆದರೆ (tok == TOK_EOF)
            ನಿಲ್ಲಿಸು;

        level = s1->include_ರಾಶಿ_ptr - iptr;
        ಆದರೆ (level) {
            ಆದರೆ (level > 0)
                pp_ಸಾಲು(s1, *iptr, 0);
            pp_ಸಾಲು(s1, file, level);
        }
        ಆದರೆ (s1->dflag & 7) {
            pp_debug_ನಿರೂಪಿಸುತ್ತದೆ(s1);
            ಆದರೆ (s1->dflag & 4)
                ಮುಂದುವರಿ;
        }

        ಆದರೆ (is_space(tok)) {
            ಆದರೆ (spcs < ಗಾತ್ರ white - 1)
                white[spcs++] = tok;
            ಮುಂದುವರಿ;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (tok == TOK_LINEFEED) {
            spcs = 0;
            ಆದರೆ (token_ನೋಡಿದ == TOK_LINEFEED)
                ಮುಂದುವರಿ;
            ++file->ಸಾಲು_ref;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (token_ನೋಡಿದ == TOK_LINEFEED) {
            pp_ಸಾಲು(s1, file, 0);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (spcs == 0 && pp_need_space(token_ನೋಡಿದ, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_ನೋಡಿದ = pp_check_he0xE(tok, p);
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* ------------------------------------------------------------------------- */
