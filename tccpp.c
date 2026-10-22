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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCEPT_LF_ਵਿੱਚ_ਲੜੀਆਂ 0

/********************************************************/
/* global variables */

ST_ਅੰਕੜੇ ਪੂਰਨ tok_flags;
ST_ਅੰਕੜੇ ਪੂਰਨ parse_flags;

ST_ਅੰਕੜੇ ਬਣਤਰ BufferedFile *file;
ST_ਅੰਕੜੇ ਪੂਰਨ tok;
ST_ਅੰਕੜੇ CValue tokc;
ST_ਅੰਕੜੇ ਅਚਲ ਪੂਰਨ *macro_ptr;
ST_ਅੰਕੜੇ CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ਅੰਕੜੇ ਪੂਰਨ tok_ident;
ST_ਅੰਕੜੇ TokenSym **ਸਾਰਣੀ_ident;
ST_ਅੰਕੜੇ ਪੂਰਨ pp_ਵਿਅੰਜਕ;

/* ------------------------------------------------------------------------- */

ਸਥਿਰ TokenSym *hash_ident[TOK_HASH_ਮਾਪ];
ਸਥਿਰ ਅੱਖਰ token_buf[STRING_MAX_ਮਾਪ + 1];
ਸਥਿਰ CString cstr_buf;
ਸਥਿਰ TokenString tokstr_buf;
ਸਥਿਰ TokenString unget_buf;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ isidnum_ਸਾਰਣੀ[256 - CH_EOF];
ਸਥਿਰ ਪੂਰਨ pp_debug_tok, pp_debug_symv;
ਸਥਿਰ ਪੂਰਨ pp_counter;
ਸਥਿਰ ਖਾਲੀ tok_print(ਅਚਲ ਪੂਰਨ *str, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, ...);
ਸਥਿਰ ਖਾਲੀ ਅਗਲਾ_nomacro(ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਖਿਆ(ਅਚਲ ਅੱਖਰ *p);
ਸਥਿਰ ਖਾਲੀ parse_string(ਅਚਲ ਅੱਖਰ *p, ਪੂਰਨ len);

ਸਥਿਰ ਬਣਤਰ TinyAlloc *toksym_alloc;
ਸਥਿਰ ਬਣਤਰ TinyAlloc *tokstr_alloc;

ਸਥਿਰ TokenString *macro_ਢੇਰ;

ਸਥਿਰ ਅਚਲ ਅੱਖਰ tcc_keywords[] = 
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEF(id, str) str "\0"
#ਅਨ੍ਤਰ੍ਭਾਵ "tcctok.h"
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DEF
;

/* WARNING: the content of this string encodes token numbers */
ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ tok_two_chars[] =
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
    '+','=', TOK_A_ਜੋੜੋ,
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

ST_FUNC ਖਾਲੀ skip(ਪੂਰਨ c)
{
    ਜੇ (tok != c) {
        ਅੱਖਰ tmp[40];
        pstrcpy(tmp, ਆਕਾਰ tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    ਅਗਲਾ();
}

ST_FUNC ਖਾਲੀ expect(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
    tcc_error("%s expected", ਸੁਨੇਹਾ);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USE_TAL

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ USE_TAL /* may cause memory leaks after errors */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_free(al, p) tcc_free(p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_realloc(al, p, ਮਾਪ) tcc_realloc(p, ਮਾਪ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_new(a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_delete(a)
#ਨਹੀਂਤਾਂ
#ਜੇ !defined(MEM_DEBUG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_free(al, p) tal_free_impl(al, p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_realloc(al, p, ਮਾਪ) tal_realloc_impl(al, p, ਮਾਪ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TAL_DEBUG_PARAMS
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tal_realloc(al, p, ਮਾਪ) tal_realloc_impl(al, p, ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TAL_DEBUG_PARAMS , ਅਚਲ ਅੱਖਰ *sfile, ਪੂਰਨ sline
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKSYM_TAL_ਮਾਪ (256 * 1024) /* allocator for TokenSym in table_ident */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKSTR_TAL_ਮਾਪ (256 * 1024) /* allocator for TokenString instances */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ਬਣਤਰ TinyAlloc *ਅਗਲਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ nb_allocs;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਮਾਪ;
#ਜੇ TAL_INFO
    ਬਿਨਾਨਿਸ਼ਾਨੀ nb_peak;
    ਬਿਨਾਨਿਸ਼ਾਨੀ nb_ਕੁੱਲ;
    uint8_t *peak_p;
#ਜੇ_ਅੰਤ
    ਸੰਘ {
        uint8_t ਬਫਰ[1];
        ਮਾਪ_t _aligner_;
    };
} TinyAlloc;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ tal_ਸਿਰਲੇਖ_t {
    ਮਾਪ_t  ਮਾਪ; /* word align */
#ਜੇ TAL_DEBUG
    ਪੂਰਨ     ਸਤਰ_ਅੰਕ; /* negative line_num used for double free check */
    ਅੱਖਰ    file_name[40];
#ਜੇ_ਅੰਤ
} tal_ਸਿਰਲੇਖ_t;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TAL_ALIGN(ਮਾਪ) \
    (((ਮਾਪ) + (ਆਕਾਰ (ਮਾਪ_t) - 1)) & ~(ਆਕਾਰ (ਮਾਪ_t) - 1))

/* ------------------------------------------------------------------------- */

ਸਥਿਰ TinyAlloc *tal_new(TinyAlloc **pal, ਬਿਨਾਨਿਸ਼ਾਨੀ ਮਾਪ)
{
    TinyAlloc *al = tcc_malloc(ਆਕਾਰ(TinyAlloc) - ਆਕਾਰ (ਮਾਪ_t) + ਮਾਪ);
    al->p = al->ਬਫਰ;
    al->bufend = al->ਬਫਰ + ਮਾਪ;
    al->nb_allocs = 0;
    al->ਅਗਲਾ = *pal, *pal = al;
    al->ਮਾਪ = al->ਅਗਲਾ ? al->ਅਗਲਾ->ਮਾਪ : ਮਾਪ;
#ਜੇ TAL_INFO
    al->nb_peak = 0;
    al->nb_ਕੁੱਲ = 0;
    al->peak_p = al->p;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ al;
}

ਸਥਿਰ ਖਾਲੀ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *ਅਗਲਾ;

#ਜੇ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#ਜੇ_ਅੰਤ
ਪੂਛ_call:
#ਜੇ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ਜੇ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->ਬਫਰ, al->nb_peak, al->nb_ਕੁੱਲ,
            (al->peak_p - al->ਬਫਰ) * 100.0 / (al->bufend - al->ਬਫਰ));
#ਜੇ_ਅੰਤ
    ਜੇ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->ਬਫਰ;
        ਜਦੋਂ (p < al->p) {
            tal_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ = (tal_ਸਿਰਲੇਖ_t *)p;
            ਜੇ (ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        ਸਿਰਲੇਖ->file_name, ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ, (ਪੂਰਨ)ਸਿਰਲੇਖ->ਮਾਪ);
            }
            p += ਸਿਰਲੇਖ->ਮਾਪ + ਆਕਾਰ(tal_ਸਿਰਲੇਖ_t);
        }
#ਜੇ TAL_DEBUG == 2
        ਬਾਹਰ_ਨਿਕਲੋ(2);
#ਜੇ_ਅੰਤ
    }
#ਜੇ_ਅੰਤ
    ਅਗਲਾ = al->ਅਗਲਾ;
    tcc_free(al);
    al = ਅਗਲਾ;
    ਜੇ (al)
        ਜਾਓ ਪੂਛ_call;
    *pal = al;
}

ਸਥਿਰ ਖਾਲੀ tal_free_impl(TinyAlloc **pal, ਖਾਲੀ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **ਸਿਖਰ = pal;
    tal_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ;

    ਜੇ (!p)
        ਵਾਪਸ;
    ਸਿਰਲੇਖ = (tal_ਸਿਰਲੇਖ_t *)p - 1;
#ਜੇ TAL_DEBUG
    ਜੇ (ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                ਸਿਰਲੇਖ->file_name, (ਪੂਰਨ)-ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ, (ਪੂਰਨ)ਸਿਰਲੇਖ->ਮਾਪ);
    } ਨਹੀਂਤਾਂ
        ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ = -ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ;
#ਜੇ_ਅੰਤ
    al = *pal;
    ਜਦੋਂ ((uint8_t*)p < al->ਬਫਰ || (uint8_t*)p > al->bufend)
        al = *(pal = &al->ਅਗਲਾ);
    ਜੇ (0 == --al->nb_allocs) {
        *pal = al->ਅਗਲਾ;
        ਜੇ ((al->bufend - al->ਬਫਰ) > al->ਮਾਪ) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } ਨਹੀਂਤਾਂ {
            /* reset and move to front */
            al->p = al->ਬਫਰ;
            al->ਅਗਲਾ = *ਸਿਖਰ, *ਸਿਖਰ = al;
        }
    } ਨਹੀਂਤਾਂ ਜੇ ((uint8_t*)p + ਸਿਰਲੇਖ->ਮਾਪ == al->p) {
        al->p = (uint8_t*)ਸਿਰਲੇਖ;
    }
}

ਸਥਿਰ ਖਾਲੀ *tal_realloc_impl(TinyAlloc **pal, ਖਾਲੀ *p, ਬਿਨਾਨਿਸ਼ਾਨੀ ਮਾਪ TAL_DEBUG_PARAMS)
{
    tal_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ;
    ਖਾਲੀ *ret;
    ਬਿਨਾਨਿਸ਼ਾਨੀ adj_ਮਾਪ = TAL_ALIGN(ਮਾਪ) + ਆਕਾਰ(tal_ਸਿਰਲੇਖ_t);
    TinyAlloc *al = *pal;

    ਜੇ (p) {
        /* reallpc case */
        ਜਦੋਂ ((uint8_t*)p < al->ਬਫਰ || (uint8_t*)p > al->bufend)
            al = al->ਅਗਲਾ;
        ਸਿਰਲੇਖ = (tal_ਸਿਰਲੇਖ_t *)p - 1;
        ਜੇ ((uint8_t*)p + ਸਿਰਲੇਖ->ਮਾਪ == al->p)
            al->p = (uint8_t*)ਸਿਰਲੇਖ; /* maybe reuse */
        ਜੇ (al->p + adj_ਮਾਪ > al->bufend) {
            ret = tal_realloc(pal, 0, ਮਾਪ);
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(ret, p, ਸਿਰਲੇਖ->ਮਾਪ);
            tal_free(pal, p);
            ਵਾਪਸ ret;
        } ਨਹੀਂਤਾਂ ਜੇ (al->p != (uint8_t*)ਸਿਰਲੇਖ) {
            ਸਮ੍ਰਿਤੀ_ਨਕਲ((tal_ਸਿਰਲੇਖ_t*)al->p + 1, p, ਸਿਰਲੇਖ->ਮਾਪ);
#ਜੇ TAL_DEBUG
            ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ = -ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ;
#ਜੇ_ਅੰਤ
        }
    } ਨਹੀਂਤਾਂ {
        /* new alloc case */
        ਜਦੋਂ (al->p + adj_ਮਾਪ > al->bufend) {
            al = al->ਅਗਲਾ;
            ਜੇ (!al) {
                ਬਿਨਾਨਿਸ਼ਾਨੀ new_ਮਾਪ = (*pal)->ਮਾਪ;
                ਜੇ (adj_ਮਾਪ > new_ਮਾਪ) {
                    new_ਮਾਪ = adj_ਮਾਪ;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_ਮਾਪ);
                ਰੋਕੋ;
            }
        }
        al->nb_allocs++;
    }
    ਸਿਰਲੇਖ = (tal_ਸਿਰਲੇਖ_t *)al->p;
    ਸਿਰਲੇਖ->ਮਾਪ = adj_ਮਾਪ - ਆਕਾਰ(tal_ਸਿਰਲੇਖ_t);
    al->p += adj_ਮਾਪ;
    ret = ਸਿਰਲੇਖ + 1;
#ਜੇ  TAL_DEBUG
    {
        ਪੂਰਨ ofs = ਲੜੀ_ਲੰਬਾਈ(sfile) + 1 - ਆਕਾਰ ਸਿਰਲੇਖ->file_name;
        strcpy(ਸਿਰਲੇਖ->file_name, sfile + (ofs > 0 ? ofs : 0));
        ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ = sline;
#ਜੇ TAL_INFO
        ਜੇ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ਜੇ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_ਕੁੱਲ++;
#ਜੇ_ਅੰਤ
    }
#ਜੇ_ਅੰਤ
    ਵਾਪਸ ret;
}

#ਜੇ_ਅੰਤ /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ਸਥਿਰ ਖਾਲੀ cstr_realloc(CString *cstr, ਪੂਰਨ new_ਮਾਪ)
{
    ਪੂਰਨ ਮਾਪ;

    ਮਾਪ = cstr->ਮਾਪ_allocated;
    ਜੇ (ਮਾਪ < 8)
        ਮਾਪ = 8; /* no need to allocate a too small first string */
    ਜਦੋਂ (ਮਾਪ < new_ਮਾਪ)
        ਮਾਪ = ਮਾਪ * 2;
    cstr->ਅੰਕੜੇ = tcc_realloc(cstr->ਅੰਕੜੇ, ਮਾਪ);
    cstr->ਮਾਪ_allocated = ਮਾਪ;
}

/* add a byte */
ST_INLN ਖਾਲੀ cstr_ccat(CString *cstr, ਪੂਰਨ ch)
{
    ਪੂਰਨ ਮਾਪ;
    ਮਾਪ = cstr->ਮਾਪ + 1;
    ਜੇ (ਮਾਪ > cstr->ਮਾਪ_allocated)
        cstr_realloc(cstr, ਮਾਪ);
    cstr->ਅੰਕੜੇ[ਮਾਪ - 1] = ch;
    cstr->ਮਾਪ = ਮਾਪ;
}

ST_INLN ਅੱਖਰ *unicode_ਮੰਜ਼ਿਲ_utf8 (ਅੱਖਰ *b, uint32_t Uc)
{
    ਜੇ (Uc<0x80) *b++=Uc;
    ਨਹੀਂਤਾਂ ਜੇ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    ਨਹੀਂਤਾਂ ਜੇ (Uc-0xd800u<0x800) ਜਾਓ error;
    ਨਹੀਂਤਾਂ ਜੇ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ਨਹੀਂਤਾਂ ਜੇ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ਨਹੀਂਤਾਂ error: tcc_error("0x%x is not a valid universal character", Uc);
    ਵਾਪਸ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN ਖਾਲੀ cstr_u8cat(CString *cstr, ਪੂਰਨ ch)
{
    ਅੱਖਰ buf[4], *e;
    e = unicode_ਮੰਜ਼ਿਲ_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC ਖਾਲੀ cstr_cat(CString *cstr, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len)
{
    ਪੂਰਨ ਮਾਪ;
    ਜੇ (len <= 0)
        len = ਲੜੀ_ਲੰਬਾਈ(str) + 1 + len;
    ਮਾਪ = cstr->ਮਾਪ + len;
    ਜੇ (ਮਾਪ > cstr->ਮਾਪ_allocated)
        cstr_realloc(cstr, ਮਾਪ);
    memmove(cstr->ਅੰਕੜੇ + cstr->ਮਾਪ, str, len);
    cstr->ਮਾਪ = ਮਾਪ;
}

/* add a wide char */
ST_FUNC ਖਾਲੀ cstr_wccat(CString *cstr, ਪੂਰਨ ch)
{
    ਪੂਰਨ ਮਾਪ;
    ਮਾਪ = cstr->ਮਾਪ + ਆਕਾਰ(nwchar_t);
    ਜੇ (ਮਾਪ > cstr->ਮਾਪ_allocated)
        cstr_realloc(cstr, ਮਾਪ);
    *(nwchar_t *)(cstr->ਅੰਕੜੇ + ਮਾਪ - ਆਕਾਰ(nwchar_t)) = ch;
    cstr->ਮਾਪ = ਮਾਪ;
}

ST_FUNC ਖਾਲੀ cstr_new(CString *cstr)
{
    memset(cstr, 0, ਆਕਾਰ(CString));
}

/* free string and reset it to NULL */
ST_FUNC ਖਾਲੀ cstr_free(CString *cstr)
{
    tcc_free(cstr->ਅੰਕੜੇ);
}

/* reset string to empty */
ST_FUNC ਖਾਲੀ cstr_reset(CString *cstr)
{
    cstr->ਮਾਪ = 0;
}

ST_FUNC ਪੂਰਨ cstr_vprintf(CString *cstr, ਅਚਲ ਅੱਖਰ *fmt, va_list ap)
{
    va_list v;
    ਪੂਰਨ len, ਮਾਪ = 80;
    ਲਈ (;;) {
        ਮਾਪ += cstr->ਮਾਪ;
        ਜੇ (ਮਾਪ > cstr->ਮਾਪ_allocated)
            cstr_realloc(cstr, ਮਾਪ);
        ਮਾਪ = cstr->ਮਾਪ_allocated - cstr->ਮਾਪ;
        va_copy(v, ap);
        len = vsnprintf(cstr->ਅੰਕੜੇ + cstr->ਮਾਪ, ਮਾਪ, fmt, v);
        va_end(v);
        ਜੇ (len >= 0 && len < ਮਾਪ)
            ਰੋਕੋ;
        ਮਾਪ *= 2;
    }
    cstr->ਮਾਪ += len;
    ਵਾਪਸ len;
}

ST_FUNC ਪੂਰਨ cstr_printf(CString *cstr, ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap; ਪੂਰਨ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ਵਾਪਸ len;
}

/* XXX: unicode ? */
ਸਥਿਰ ਖਾਲੀ ਜੋੜੋ_char(CString *cstr, ਪੂਰਨ c)
{
    ਜੇ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ਜੇ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } ਨਹੀਂਤਾਂ {
        cstr_ccat(cstr, '\\');
        ਜੇ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } ਨਹੀਂਤਾਂ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ਸਥਿਰ TokenSym *tok_alloc_new(TokenSym **pts, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len)
{
    TokenSym *ts, **ptable;
    ਪੂਰਨ i;

    ਜੇ (tok_ident >= SYM_ਪਹਿਲਾ_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ਜੇ ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(ਸਾਰਣੀ_ident, (i + TOK_ALLOC_INCR) * ਆਕਾਰ(TokenSym *));
        ਸਾਰਣੀ_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, ਆਕਾਰ(TokenSym) + len);
    ਸਾਰਣੀ_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ਨਿਰਾ;
    ts->sym_label = ਨਿਰਾ;
    ts->sym_struct = ਨਿਰਾ;
    ts->sym_identifier = ਨਿਰਾ;
    ts->len = len;
    ts->hash_ਅਗਲਾ = ਨਿਰਾ;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ਵਾਪਸ ts;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_HASH_INIT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ len)
{
    TokenSym *ts, **pts;
    ਪੂਰਨ i;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ h;
    
    h = TOK_HASH_INIT;
    ਲਈ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)str)[i]);
    h &= (TOK_HASH_ਮਾਪ - 1);

    pts = &hash_ident[h];
    ਲਈ(;;) {
        ts = *pts;
        ਜੇ (!ts)
            ਰੋਕੋ;
        ਜੇ (ts->len == len && !memcmp(ts->str, str, len))
            ਵਾਪਸ ts;
        pts = &(ts->hash_ਅਗਲਾ);
    }
    ਵਾਪਸ tok_alloc_new(pts, str, len);
}

ST_FUNC ਪੂਰਨ tok_alloc_const(ਅਚਲ ਅੱਖਰ *str)
{
    ਵਾਪਸ tok_alloc(str, ਲੜੀ_ਲੰਬਾਈ(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ਅਚਲ ਅੱਖਰ *get_tok_str(ਪੂਰਨ v, CValue *cv)
{
    ਅੱਖਰ *p;
    ਪੂਰਨ i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.ਅੰਕੜੇ;

    ਚੋਣ(v) {
    ਹਾਲਤ TOK_CINT:
    ਹਾਲਤ TOK_CUINT:
    ਹਾਲਤ TOK_CLONG:
    ਹਾਲਤ TOK_CULONG:
    ਹਾਲਤ TOK_CLLONG:
    ਹਾਲਤ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)cv->i);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    ਹਾਲਤ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        ਜੋੜੋ_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ਰੋਕੋ;
    ਹਾਲਤ TOK_PPNUM:
    ਹਾਲਤ TOK_PPSTR:
        ਵਾਪਸ (ਅੱਖਰ*)cv->str.ਅੰਕੜੇ;
    ਹਾਲਤ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    ਹਾਲਤ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ਜੇ (v == TOK_STR) {
            len = cv->str.ਮਾਪ - 1;
            ਲਈ(i=0;i<len;i++)
                ਜੋੜੋ_char(&cstr_buf, ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)cv->str.ਅੰਕੜੇ)[i]);
        } ਨਹੀਂਤਾਂ {
            len = (cv->str.ਮਾਪ / ਆਕਾਰ(nwchar_t)) - 1;
            ਲਈ(i=0;i<len;i++)
                ਜੋੜੋ_char(&cstr_buf, ((nwchar_t *)cv->str.ਅੰਕੜੇ)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ਰੋਕੋ;

    ਹਾਲਤ TOK_CFLOAT:
        ਵਾਪਸ strcpy(p, "<float>");
    ਹਾਲਤ TOK_CDOUBLE:
        ਵਾਪਸ strcpy(p, "<double>");
    ਹਾਲਤ TOK_CLDOUBLE:
        ਵਾਪਸ strcpy(p, "<long double>");
    ਹਾਲਤ TOK_LINENUM:
        ਵਾਪਸ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    ਹਾਲਤ TOK_LT:
        v = '<';
        ਜਾਓ addv;
    ਹਾਲਤ TOK_GT:
        v = '>';
        ਜਾਓ addv;
    ਹਾਲਤ TOK_DOTS:
        ਵਾਪਸ strcpy(p, "...");
    ਹਾਲਤ TOK_A_SHL:
        ਵਾਪਸ strcpy(p, "<<=");
    ਹਾਲਤ TOK_A_SAR:
        ਵਾਪਸ strcpy(p, ">>=");
    ਹਾਲਤ TOK_EOF:
        ਵਾਪਸ strcpy(p, "<eof>");
    ਹਾਲਤ 0: /* anonymous nameless symbols */
        ਵਾਪਸ strcpy(p, "<no name>");
    ਮੂਲ:
        v &= ~(SYM_ਖੇਤਰ | SYM_STRUCT);
        ਜੇ (v < TOK_IDENT) {
            /* search in two bytes table */
            ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *q = tok_two_chars;
            ਜਦੋਂ (*q) {
                ਜੇ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ਵਾਪਸ cstr_buf.ਅੰਕੜੇ;
                }
                q += 3;
            }
            ਜੇ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ਰੋਕੋ;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } ਨਹੀਂਤਾਂ ਜੇ (v < tok_ident) {
            ਵਾਪਸ ਸਾਰਣੀ_ident[v - TOK_IDENT]->str;
        } ਨਹੀਂਤਾਂ ਜੇ (v >= SYM_ਪਹਿਲਾ_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_ਪਹਿਲਾ_ANOM);
        } ਨਹੀਂਤਾਂ {
            /* should never happen */
            ਵਾਪਸ ਨਿਰਾ;
        }
        ਰੋਕੋ;
    }
    ਵਾਪਸ cstr_buf.ਅੰਕੜੇ;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ਸਥਿਰ ਪੂਰਨ handle_eob(ਖਾਲੀ)
{
    BufferedFile *bf = file;
    ਪੂਰਨ len;

    /* only tries to read if really end of buffer */
    ਜੇ (bf->buf_ptr >= bf->buf_ਸਿਰਾ) {
        ਜੇ (bf->fd >= 0) {
#ਜੇ defined(PARSE_DEBUG)
            len = 1;
#ਨਹੀਂਤਾਂ
            len = IO_BUF_ਮਾਪ;
#ਜੇ_ਅੰਤ
            len = ਪਠ(bf->fd, bf->ਬਫਰ, len);
            ਜੇ (len < 0)
                len = 0;
        } ਨਹੀਂਤਾਂ {
            len = 0;
        }
        ਕੁੱਲ_ਬਾਈਟਾਂ += len;
        bf->buf_ptr = bf->ਬਫਰ;
        bf->buf_ਸਿਰਾ = bf->ਬਫਰ + len;
        *bf->buf_ਸਿਰਾ = CH_EOB;
    }
    ਜੇ (bf->buf_ptr < bf->buf_ਸਿਰਾ) {
        ਵਾਪਸ bf->buf_ptr[0];
    } ਨਹੀਂਤਾਂ {
        bf->buf_ptr = bf->buf_ਸਿਰਾ;
        ਵਾਪਸ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ਸਥਿਰ ਪੂਰਨ ਅਗਲਾ_c(ਖਾਲੀ)
{
    ਪੂਰਨ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ਜੇ (ch == CH_EOB && file->buf_ptr >= file->buf_ਸਿਰਾ)
        ch = handle_eob();
    ਵਾਪਸ ch;
}

/* input with '\[\r]\n' handling. */
ਸਥਿਰ ਪੂਰਨ handle_stray_noerror(ਪੂਰਨ err)
{
    ਪੂਰਨ ch;
    ਜਦੋਂ ((ch = ਅਗਲਾ_c()) == '\\') {
        ch = ਅਗਲਾ_c();
        ਜੇ (ch == '\n') {
    newl:
            file->ਸਤਰ_ਅੰਕ++;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (ch == '\r') {
                ch = ਅਗਲਾ_c();
                ਜੇ (ch == '\n')
                    ਜਾਓ newl;
                *--file->buf_ptr = '\r';
            }
            ਜੇ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ਵਾਪਸ *--file->buf_ptr = '\\';
        }
    }
    ਵਾਪਸ ch;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ਸਥਿਰ ਪੂਰਨ handle_bs(uint8_t **p)
{
    ਪੂਰਨ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ਵਾਪਸ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ਸਥਿਰ ਪੂਰਨ handle_stray(uint8_t **p)
{
    ਪੂਰਨ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ਵਾਪਸ c;
}

/* handle the complicated stray case */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PEEKC(c, p)\
{\
    c = *++p;\
    ਜੇ (c == '\\')\
        c = handle_stray(&p); \
}

ਸਥਿਰ ਪੂਰਨ skip_spaces(ਖਾਲੀ)
{
    ਪੂਰਨ ch;
    --file->buf_ptr;
    ਕਰੋ {
        ch = ninp();
    } ਜਦੋਂ (isidnum_ਸਾਰਣੀ[ch - CH_EOF] & IS_SPC);
    ਵਾਪਸ ch;
}

/* single line C++ comments */
ਸਥਿਰ uint8_t *parse_ਸਤਰ_comment(uint8_t *p)
{
    ਪੂਰਨ c;
    ਲਈ(;;) {
        ਲਈ (;;) {
            c = *++p;
    redo:
            ਜੇ (c == '\n' || c == '\\')
                ਰੋਕੋ;
            c = *++p;
            ਜੇ (c == '\n' || c == '\\')
                ਰੋਕੋ;
        }
        ਜੇ (c == '\n')
            ਰੋਕੋ;
        c = handle_bs(&p);
        ਜੇ (c == CH_EOF)
            ਰੋਕੋ;
        ਜੇ (c != '\\')
            ਜਾਓ redo;
    }
    ਵਾਪਸ p;
}

/* C comments */
ਸਥਿਰ uint8_t *parse_comment(uint8_t *p)
{
    ਪੂਰਨ c;
    ਲਈ(;;) {
        /* fast skip loop */
        ਲਈ(;;) {
            c = *++p;
        redo:
            ਜੇ (c == '\n' || c == '*' || c == '\\')
                ਰੋਕੋ;
            c = *++p;
            ਜੇ (c == '\n' || c == '*' || c == '\\')
                ਰੋਕੋ;
        }
        /* now we can handle all the cases */
        ਜੇ (c == '\n') {
            file->ਸਤਰ_ਅੰਕ++;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '*') {
            ਕਰੋ {
                c = *++p;
            } ਜਦੋਂ (c == '*');
            ਜੇ (c == '\\')
                c = handle_bs(&p);
            ਜੇ (c == '/')
                ਰੋਕੋ;
            ਜਾਓ check_eof;
        } ਨਹੀਂਤਾਂ {
            c = handle_bs(&p);
        check_eof:
            ਜੇ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ਜੇ (c != '\\')
                ਜਾਓ redo;
        }
    }
    ਵਾਪਸ p + 1;
}

/* parse a string without interpreting escapes */
ਸਥਿਰ uint8_t *parse_pp_string(uint8_t *p, ਪੂਰਨ sep, CString *str)
{
    ਪੂਰਨ c;
    ਲਈ(;;) {
        c = *++p;
    redo:
        ਜੇ (c == sep) {
            ਰੋਕੋ;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '\\') {
            c = handle_bs(&p);
            ਜੇ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } ਨਹੀਂਤਾਂ ਜੇ (c == '\\') {
                ਜੇ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ਜੇ (c == '\\') {
                    c = handle_bs(&p);
                    ਜੇ (c == CH_EOF)
                        ਜਾਓ unterminated_string;
                }
                ਜਾਓ ਜੋੜੋ_char;
            } ਨਹੀਂਤਾਂ {
                ਜਾਓ redo;
            }
        } ਨਹੀਂਤਾਂ ਜੇ (c == '\n') {
        ਜੋੜੋ_lf:
            ਜੇ (ACCEPT_LF_ਵਿੱਚ_ਲੜੀਆਂ) {
                file->ਸਤਰ_ਅੰਕ++;
                ਜਾਓ ਜੋੜੋ_char;
            } ਨਹੀਂਤਾਂ ਜੇ (str) { /* not skipping */
                ਜਾਓ unterminated_string;
            } ਨਹੀਂਤਾਂ {
                //tcc_warning("missing terminating %c character", sep);
                ਵਾਪਸ p;
            }
        } ਨਹੀਂਤਾਂ ਜੇ (c == '\r') {
            c = *++p;
            ਜੇ (c == '\\')
                c = handle_bs(&p);
            ਜੇ (c == '\n')
                ਜਾਓ ਜੋੜੋ_lf;
            ਜੇ (c == CH_EOF)
                ਜਾਓ unterminated_string;
            ਜੇ (str)
                cstr_ccat(str, '\r');
            ਜਾਓ redo;
        } ਨਹੀਂਤਾਂ {
        ਜੋੜੋ_char:
            ਜੇ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ਵਾਪਸ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ਸਥਿਰ ਖਾਲੀ preprocess_skip(ਖਾਲੀ)
{
    ਪੂਰਨ a, ਸ਼ੁਰੂ_ਦਾ_ਸਤਰ, c, ਵਿੱਚ_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_ਸ਼ੁਰੂ:
    ਸ਼ੁਰੂ_ਦਾ_ਸਤਰ = 1;
    ਵਿੱਚ_warn_or_error = 0;
    ਲਈ(;;) {
        c = *p;
        ਚੋਣ(c) {
        ਹਾਲਤ ' ':
        ਹਾਲਤ '\t':
        ਹਾਲਤ '\f':
        ਹਾਲਤ '\v':
        ਹਾਲਤ '\r':
            p++;
            ਜਾਰੀ;
        ਹਾਲਤ '\n':
            file->ਸਤਰ_ਅੰਕ++;
            p++;
            ਜਾਓ redo_ਸ਼ੁਰੂ;
        ਹਾਲਤ '\\':
            c = handle_bs(&p);
            ਜੇ (c == CH_EOF)
                expect("#endif");
            ਜੇ (c == '\\')
                ++p;
            ਜਾਰੀ;
        /* skip strings */
        ਹਾਲਤ '\"':
        ਹਾਲਤ '\'':
            ਜੇ (ਵਿੱਚ_warn_or_error)
                ਜਾਓ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ਨਿਰਾ);
            ਰੋਕੋ;
        /* skip comments */
        ਹਾਲਤ '/':
            ਜੇ (ਵਿੱਚ_warn_or_error)
                ਜਾਓ _default;
            ++p;
            c = handle_bs(&p);
            ਜੇ (c == '*') {
                p = parse_comment(p);
            } ਨਹੀਂਤਾਂ ਜੇ (c == '/') {
                p = parse_ਸਤਰ_comment(p);
            }
            ਜਾਰੀ;
        ਹਾਲਤ '#':
            p++;
            ਜੇ (ਸ਼ੁਰੂ_ਦਾ_ਸਤਰ) {
                file->buf_ptr = p;
                ਅਗਲਾ_nomacro();
                p = file->buf_ptr;
                ਜੇ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    ਜਾਓ the_ਸਿਰਾ;
                ਜੇ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_ENDIF)
                    a--;
                ਨਹੀਂਤਾਂ ਜੇ( tok == TOK_ERROR || tok == TOK_WARNING)
                    ਵਿੱਚ_warn_or_error = 1;
                ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_LINEFEED)
                    ਜਾਓ redo_ਸ਼ੁਰੂ;
                ਨਹੀਂਤਾਂ ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_ਸਤਰ_comment(p - 1);
            }
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM) && !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
            ਨਹੀਂਤਾਂ ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_ਸਤਰ_comment(p - 1);
#ਨਹੀਂਤਾਂ
            /* ARM/ARM64 assembly uses '#' for constants */
#ਜੇ_ਅੰਤ
            ਰੋਕੋ;
_default:
        ਮੂਲ:
            p++;
            ਰੋਕੋ;
        }
        ਸ਼ੁਰੂ_ਦਾ_ਸਤਰ = 0;
    }
 the_ਸਿਰਾ: ;
    file->buf_ptr = p;
}

#ਜੇ 0
/* return the number of additional 'ints' necessary to store the
   token */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ tok_ਮਾਪ(ਅਚਲ ਪੂਰਨ *p)
{
    ਚੋਣ(*p) {
        /* 4 bytes */
    ਹਾਲਤ TOK_CINT:
    ਹਾਲਤ TOK_CUINT:
    ਹਾਲਤ TOK_CCHAR:
    ਹਾਲਤ TOK_LCHAR:
    ਹਾਲਤ TOK_CFLOAT:
    ਹਾਲਤ TOK_LINENUM:
        ਵਾਪਸ 1 + 1;
    ਹਾਲਤ TOK_STR:
    ਹਾਲਤ TOK_LSTR:
    ਹਾਲਤ TOK_PPNUM:
    ਹਾਲਤ TOK_PPSTR:
        ਵਾਪਸ 1 + 1 + (p[1] + 3) / 4;
    ਹਾਲਤ TOK_CLONG:
    ਹਾਲਤ TOK_CULONG:
	ਵਾਪਸ 1 + LONG_ਮਾਪ / 4;
    ਹਾਲਤ TOK_CDOUBLE:
    ਹਾਲਤ TOK_CLLONG:
    ਹਾਲਤ TOK_CULLONG:
        ਵਾਪਸ 1 + 2;
    ਹਾਲਤ TOK_CLDOUBLE:
        ਵਾਪਸ 1 + LDOUBLE_ਸ਼ਬਦ;
    ਮੂਲ:
        ਵਾਪਸ 1 + 0;
    }
}
#ਜੇ_ਅੰਤ

/* token string handling */
ST_INLN ਖਾਲੀ tok_str_new(TokenString *s)
{
    s->str = ਨਿਰਾ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->ਆਖਰੀ_ਸਤਰ_ਅੰਕ = -1;
}

ST_FUNC TokenString *tok_str_alloc(ਖਾਲੀ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, ਆਕਾਰ *str);
    tok_str_new(str);
    ਵਾਪਸ str;
}

ST_FUNC ਖਾਲੀ tok_str_free_str(ਪੂਰਨ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ਖਾਲੀ tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ਪੂਰਨ *tok_str_realloc(TokenString *s, ਪੂਰਨ new_ਮਾਪ)
{
    ਪੂਰਨ *str, ਮਾਪ;

    ਮਾਪ = s->allocated_len;
    ਜੇ (ਮਾਪ < 16)
        ਮਾਪ = 16;
    ਜਦੋਂ (ਮਾਪ < new_ਮਾਪ)
        ਮਾਪ = ਮਾਪ * 2;
    ਜੇ (ਮਾਪ > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, ਮਾਪ * ਆਕਾਰ(ਪੂਰਨ));
        s->allocated_len = ਮਾਪ;
        s->str = str;
    }
    ਵਾਪਸ s->str;
}

ST_FUNC ਖਾਲੀ tok_str_ਜੋੜੋ(TokenString *s, ਪੂਰਨ t)
{
    ਪੂਰਨ len, *str;

    len = s->len;
    str = s->str;
    ਜੇ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC ਖਾਲੀ begin_macro(TokenString *str, ਪੂਰਨ alloc)
{
    str->alloc = alloc;
    str->prev = macro_ਢੇਰ;
    str->prev_ptr = macro_ptr;
    str->save_ਸਤਰ_ਅੰਕ = file->ਸਤਰ_ਅੰਕ;
    macro_ptr = str->str;
    macro_ਢੇਰ = str;
}

ST_FUNC ਖਾਲੀ ਸਿਰਾ_macro(ਖਾਲੀ)
{
    TokenString *str = macro_ਢੇਰ;
    macro_ਢੇਰ = str->prev;
    macro_ptr = str->prev_ptr;
    file->ਸਤਰ_ਅੰਕ = str->save_ਸਤਰ_ਅੰਕ;
    ਜੇ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } ਨਹੀਂਤਾਂ {
        ਜੇ (str->alloc == 2)
            str->str = ਨਿਰਾ; /* don't free */
        tok_str_free(str);
    }
}

ਸਥਿਰ ਖਾਲੀ tok_str_add2(TokenString *s, ਪੂਰਨ t, CValue *cv)
{
    ਪੂਰਨ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ਜੇ (len + TOK_MAX_ਮਾਪ >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_ਮਾਪ + 1);
    str[len++] = t;
    ਚੋਣ(t) {
    ਹਾਲਤ TOK_CINT:
    ਹਾਲਤ TOK_CUINT:
    ਹਾਲਤ TOK_CCHAR:
    ਹਾਲਤ TOK_LCHAR:
    ਹਾਲਤ TOK_CFLOAT:
    ਹਾਲਤ TOK_LINENUM:
#ਜੇ LONG_ਮਾਪ == 4
    ਹਾਲਤ TOK_CLONG:
    ਹਾਲਤ TOK_CULONG:
#ਜੇ_ਅੰਤ
        str[len++] = cv->tab[0];
        ਰੋਕੋ;
    ਹਾਲਤ TOK_PPNUM:
    ਹਾਲਤ TOK_PPSTR:
    ਹਾਲਤ TOK_STR:
    ਹਾਲਤ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            ਮਾਪ_t nb_ਸ਼ਬਦ =
                1 + (cv->str.ਮਾਪ + ਆਕਾਰ(ਪੂਰਨ) - 1) / ਆਕਾਰ(ਪੂਰਨ);
            ਜੇ (len + nb_ਸ਼ਬਦ >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_ਸ਼ਬਦ + 1);
            str[len] = cv->str.ਮਾਪ;
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&str[len + 1], cv->str.ਅੰਕੜੇ, cv->str.ਮਾਪ);
            len += nb_ਸ਼ਬਦ;
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CDOUBLE:
    ਹਾਲਤ TOK_CLLONG:
    ਹਾਲਤ TOK_CULLONG:
#ਜੇ LONG_ਮਾਪ == 8
    ਹਾਲਤ TOK_CLONG:
    ਹਾਲਤ TOK_CULONG:
#ਜੇ_ਅੰਤ
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ਜੇ (LDOUBLE_ਸ਼ਬਦ >= 3)
        str[len++] = cv->tab[2];
        ਜੇ (LDOUBLE_ਸ਼ਬਦ >= 4)
        str[len++] = cv->tab[3];
    ਮੂਲ:
        ਰੋਕੋ;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC ਖਾਲੀ tok_str_ਜੋੜੋ_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ਜੇ (file->ਸਤਰ_ਅੰਕ != s->ਆਖਰੀ_ਸਤਰ_ਅੰਕ) {
        s->ਆਖਰੀ_ਸਤਰ_ਅੰਕ = file->ਸਤਰ_ਅੰਕ;
        cval.i = s->ਆਖਰੀ_ਸਤਰ_ਅੰਕ;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ਸਥਿਰ ਖਾਲੀ tok_str_add2_spc(TokenString *s, ਪੂਰਨ t, CValue *cv)
{
    ਜੇ (s->need_spc == 3)
        tok_str_ਜੋੜੋ(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ tok_get(ਪੂਰਨ *t, ਅਚਲ ਪੂਰਨ **pp, CValue *cv)
{
    ਅਚਲ ਪੂਰਨ *p = *pp;
    ਪੂਰਨ n, *tab;

    tab = cv->tab;
    ਚੋਣ(*t = *p++) {
#ਜੇ LONG_ਮਾਪ == 4
    ਹਾਲਤ TOK_CLONG:
#ਜੇ_ਅੰਤ
    ਹਾਲਤ TOK_CINT:
    ਹਾਲਤ TOK_CCHAR:
    ਹਾਲਤ TOK_LCHAR:
    ਹਾਲਤ TOK_LINENUM:
        cv->i = *p++;
        ਰੋਕੋ;
#ਜੇ LONG_ਮਾਪ == 4
    ਹਾਲਤ TOK_CULONG:
#ਜੇ_ਅੰਤ
    ਹਾਲਤ TOK_CUINT:
        cv->i = (ਬਿਨਾਨਿਸ਼ਾਨੀ)*p++;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CFLOAT:
	tab[0] = *p++;
	ਰੋਕੋ;
    ਹਾਲਤ TOK_STR:
    ਹਾਲਤ TOK_LSTR:
    ਹਾਲਤ TOK_PPNUM:
    ਹਾਲਤ TOK_PPSTR:
        cv->str.ਮਾਪ = *p++;
        cv->str.ਅੰਕੜੇ = (ਅੱਖਰ*)p;
        p += (cv->str.ਮਾਪ + ਆਕਾਰ(ਪੂਰਨ) - 1) / ਆਕਾਰ(ਪੂਰਨ);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_CDOUBLE:
    ਹਾਲਤ TOK_CLLONG:
    ਹਾਲਤ TOK_CULLONG:
#ਜੇ LONG_ਮਾਪ == 8
    ਹਾਲਤ TOK_CLONG:
    ਹਾਲਤ TOK_CULONG:
#ਜੇ_ਅੰਤ
        n = 2;
        ਜਾਓ copy;
    ਹਾਲਤ TOK_CLDOUBLE:
        n = LDOUBLE_ਸ਼ਬਦ;
    copy:
        ਕਰੋ
            *tab++ = *p++;
        ਜਦੋਂ (--n);
        ਰੋਕੋ;
    ਮੂਲ:
        ਰੋਕੋ;
    }
    *pp = p;
}

#ਜੇ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#ਨਹੀਂਤਾਂ
# define TOK_GET(t,p,c) ਕਰੋ { \
    ਪੂਰਨ _t = **(p); \
    ਜੇ (TOK_HAS_ਮੁੱਲ(_t)) \
        tok_get(t, p, c); \
    ਨਹੀਂਤਾਂ \
        *(t) = _t, ++*(p); \
    } ਜਦੋਂ (0)
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ macro_is_equal(ਅਚਲ ਪੂਰਨ *a, ਅਚਲ ਪੂਰਨ *b)
{
    CValue cv;
    ਪੂਰਨ t;

    ਜੇ (!a || !b)
        ਵਾਪਸ 1;

    ਜਦੋਂ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ਜੇ (strcmp(tokcstr.ਅੰਕੜੇ, get_tok_str(t, &cv)))
            ਵਾਪਸ 0;
    }
    ਵਾਪਸ !(*a || *b);
}

/* defines handling */
ST_INLN ਖਾਲੀ define_ਧੱਕੋ(ਪੂਰਨ v, ਪੂਰਨ macro_type, ਪੂਰਨ *str, Sym *ਪਹਿਲਾ_arg)
{
    Sym *s, *o;

    o = define_ਲੱਭੋ(v);
    s = sym_push2(&define_ਢੇਰ, v, macro_type, 0);
    s->d = str;
    s->ਅਗਲਾ = ਪਹਿਲਾ_arg;
    ਸਾਰਣੀ_ident[v - TOK_IDENT]->sym_define = s;

    ਜੇ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ਨਿਰਾ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC ਖਾਲੀ define_undef(Sym *s)
{
    ਪੂਰਨ v = s->v;
    ਜੇ (v >= TOK_IDENT && v < tok_ident)
        ਸਾਰਣੀ_ident[v - TOK_IDENT]->sym_define = ਨਿਰਾ;
}

ST_INLN Sym *define_ਲੱਭੋ(ਪੂਰਨ v)
{
    v -= TOK_IDENT;
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ)v >= (ਬਿਨਾਨਿਸ਼ਾਨੀ)(tok_ident - TOK_IDENT))
        ਵਾਪਸ ਨਿਰਾ;
    ਵਾਪਸ ਸਾਰਣੀ_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC ਖਾਲੀ free_ਨਿਰਧਾਰਤ_ਕਰਦਾ(Sym *b)
{
    ਜਦੋਂ (define_ਢੇਰ != b) {
        Sym *ਸਿਖਰ = define_ਢੇਰ;
        define_ਢੇਰ = ਸਿਖਰ->prev;
        tok_str_free_str(ਸਿਖਰ->d);
        define_undef(ਸਿਖਰ);
        sym_free(ਸਿਖਰ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ਸਥਿਰ ਖਾਲੀ maybe_ਲੜੀਵਾਰ_test(TCCState *s)
{
    ਅਚਲ ਅੱਖਰ *p;
    ਜੇ (s->include_ਢੇਰ_ptr != s->include_ਢੇਰ)
        ਵਾਪਸ;
    p = get_tok_str(tok, ਨਿਰਾ);
    ਜੇ (0 != memcmp(p, "test_", 5))
        ਵਾਪਸ;
    ਜੇ (0 != --s->ਲੜੀਵਾਰ_test)
        ਵਾਪਸ;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ਧੱਕੋ(tok, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
}

ST_FUNC ਖਾਲੀ skip_ਮੰਜ਼ਿਲ_eol(ਪੂਰਨ warn)
{
    ਜੇ (tok == TOK_LINEFEED)
        ਵਾਪਸ;
    ਜੇ (warn)
        tcc_warning("extra tokens after directive");
    ਜਦੋਂ (macro_ਢੇਰ)
        ਸਿਰਾ_macro();
    file->buf_ptr = parse_ਸਤਰ_comment(file->buf_ptr - 1);
    ਅਗਲਾ_nomacro();
}

ਸਥਿਰ CachedInclude *
ਖੋਜ_cached_include(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ ਜੋੜੋ);

ਸਥਿਰ ਪੂਰਨ parse_include(TCCState *s1, ਪੂਰਨ do_ਅਗਲਾ, ਪੂਰਨ test)
{
    ਪੂਰਨ c, i;
    ਅੱਖਰ name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ਜੇ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.ਮਾਪ;
        pstrncpy(name, ਆਕਾਰ name, tokcstr.ਅੰਕੜੇ, i);
        ਅਗਲਾ_nomacro();
    } ਨਹੀਂਤਾਂ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        ਲਈ (;;) {
            ਅਗਲਾ();
            p = name, i = ਲੜੀ_ਲੰਬਾਈ(p) - 1;
            ਜੇ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ਰੋਕੋ;
            ਜੇ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, ਆਕਾਰ name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ਜੇ (!test)
        skip_ਮੰਜ਼ਿਲ_eol(1);

    i = do_ਅਗਲਾ ? file->include_ਅਗਲਾ_ਸੂਚਕਾਂਕ : -1;
    ਲਈ (;;) {
        ++i;
        ਜੇ (i == 0) {
            /* check absolute include path */
            ਜੇ (!IS_ABSPATH(name))
                ਜਾਰੀ;
            buf[0] = '\0';
        } ਨਹੀਂਤਾਂ ਜੇ (i == 1) {
            /* search in file's dir if "header.h" */
            ਜੇ (c != '\"')
                ਜਾਰੀ;
            p = file->true_filename;
            pstrncpy(buf, ਆਕਾਰ buf, p, tcc_basename(p) - p);
        } ਨਹੀਂਤਾਂ {
            ਪੂਰਨ j = i - 2, k = j - s1->nb_include_paths;
            ਜੇ (k < 0)
                p = s1->include_paths[j];
            ਨਹੀਂਤਾਂ ਜੇ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            ਨਹੀਂਤਾਂ ਜੇ (test)
                ਵਾਪਸ 0;
            ਨਹੀਂਤਾਂ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, ਆਕਾਰ buf, p);
            pstrcat(buf, ਆਕਾਰ buf, "/");
        }
        pstrcat(buf, ਆਕਾਰ buf, name);
        e = ਖੋਜ_cached_include(s1, buf, 0);
        ਜੇ (e && (define_ਲੱਭੋ(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
            ਲਿਖੋ("%s: skipping cached %s\n", file->filename, buf);
#ਜੇ_ਅੰਤ
            ਜੇ ((s1->verbose | 1) == 3) /* -vv[v] */
                ਲਿਖੋ("=> %*s%s\n",
                   (ਪੂਰਨ)(s1->include_ਢੇਰ_ptr - s1->include_ਢੇਰ), "", buf);
            ਵਾਪਸ 1;
        }
        ਜੇ (tcc_open(s1, buf) >= 0)
            ਰੋਕੋ;
    }

    ਜੇ (test) {
        tcc_close();
    } ਨਹੀਂਤਾਂ {
        ਜੇ (s1->include_ਢੇਰ_ptr >= s1->include_ਢੇਰ + INCLUDE_ਢੇਰ_ਮਾਪ)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ਢੇਰ_ptr++ = file->prev;
        file->include_ਅਗਲਾ_ਸੂਚਕਾਂਕ = i;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
        ਲਿਖੋ("%s: including %s\n", file->prev->filename, file->filename);
#ਜੇ_ਅੰਤ
        /* update target deps */
        ਜੇ (s1->gen_deps) {
            BufferedFile *bf = file;
            ਜਦੋਂ (i == 1 && (bf = bf->prev))
                i = bf->include_ਅਗਲਾ_ਸੂਚਕਾਂਕ;
            /* skip system include files */
            ਜੇ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_ਜੋੜੋ(&s1->ਨਿਸ਼ਾਨਾ_deps, &s1->nb_ਨਿਸ਼ਾਨਾ_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ਵਾਪਸ 1;
}

/* eval an expression for #if/#elif */
ਸਥਿਰ ਪੂਰਨ ਵਿਅੰਜਕ_preprocess(TCCState *s1)
{
    ਪੂਰਨ c, t;
    ਪੂਰਨ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_ਵਿਅੰਜਕ = 1;
    ਜਦੋਂ (1) {
        ਅਗਲਾ(); /* do macro subst */
        t = tok;
        ਜੇ (tok < TOK_IDENT) {
            ਜੇ (tok == TOK_LINEFEED || tok == TOK_EOF)
                ਰੋਕੋ;
            ਜੇ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            ਅਗਲਾ();
            t = tok;
            ਜੇ (t == '(') 
                ਅਗਲਾ();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ਜੇ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ਜੇ (s1->ਲੜੀਵਾਰ_test)
                maybe_ਲੜੀਵਾਰ_test(s1);
            c = 0;
            ਜੇ (define_ਲੱਭੋ(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_ਅਗਲਾ)
                c = 1;
            ਜੇ (t == '(') {
                ਅਗਲਾ();
                ਜੇ (tok != ')')
                    expect("')'");
            }
            ਜਾਓ c_ਸੰਖਿਆ;
        } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_ਅਗਲਾ) {
            t = tok;
            ਅਗਲਾ();
	    ਜੇ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ਜੇ (tok != ')')
                expect("')'");
            ਜਾਓ c_ਸੰਖਿਆ;
        } ਨਹੀਂਤਾਂ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_ਸੰਖਿਆ:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_ਜੋੜੋ_tok(str);
    }
    ਜੇ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_ਜੋੜੋ(str, TOK_EOF); /* simulate end of file */
    pp_ਵਿਅੰਜਕ = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    ਅਗਲਾ();
    c = ਵਿਅੰਜਕ_const();
    ਜੇ (tok != TOK_EOF)
        tcc_error("...");
    pp_ਵਿਅੰਜਕ = 0;
    ਸਿਰਾ_macro();
    tok = t; /* restore LF or EOF */
    ਵਾਪਸ c != 0;
}

ST_FUNC ਖਾਲੀ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_ਵਿਅੰਜਕ, 0));
    macro_ptr = macro_ਢੇਰ->str;
    ਜਦੋਂ (ਅਗਲਾ(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC ਖਾਲੀ parse_define(ਖਾਲੀ)
{
    Sym *s, *ਪਹਿਲਾ, **ps;
    ਪੂਰਨ v, t, varg, is_vaargs, t0;
    ਪੂਰਨ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ਜੇ (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    ਪਹਿਲਾ = ਨਿਰਾ;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    ਅਗਲਾ_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    ਜੇ (tok == '(') {
        ਪੂਰਨ dotid = ਸੈੱਟ_idnum('.', 0);
        ਅਗਲਾ_nomacro();
        ps = &ਪਹਿਲਾ;
        ਜੇ (tok != ')') ਲਈ (;;) {
            varg = tok;
            ਅਗਲਾ_nomacro();
            is_vaargs = 0;
            ਜੇ (varg == TOK_DOTS) {
                varg = TOK_VA_ਦਲੀਲਾਂ;
                is_vaargs = 1;
            } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                ਅਗਲਾ_nomacro();
            }
            ਜੇ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ਢੇਰ, varg | SYM_ਖੇਤਰ, is_vaargs, 0);
            *ps = s;
            ps = &s->ਅਗਲਾ;
            ਜੇ (tok == ')')
                ਰੋਕੋ;
            ਜੇ (tok != ',' || is_vaargs)
                ਜਾਓ bad_list;
            ਅਗਲਾ_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        ਅਗਲਾ_nomacro();
        t = MACRO_FUNC;
        ਸੈੱਟ_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    ਜਦੋਂ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ਜੇ (is_space(tok)) {
            str.need_spc |= 1;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (TOK_TWOSHARPS == tok) {
                ਜੇ (0 == t0)
                    ਜਾਓ bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        ਅਗਲਾ_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_ਜੋੜੋ(&str, 0);
    ਜੇ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ਧੱਕੋ(v, t, str.str, ਪਹਿਲਾ);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ਸਥਿਰ CachedInclude *ਖੋਜ_cached_include(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ ਜੋੜੋ)
{
    ਅਚਲ ਅੱਖਰ *s, *basename;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ h;
    CachedInclude *e;
    ਪੂਰਨ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ਜਦੋਂ ((c = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)*s) != 0) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#ਨਹੀਂਤਾਂ
        h = TOK_HASH_FUNC(h, c);
#ਜੇ_ਅੰਤ
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_ਮਾਪ - 1);

    i = s1->cached_includes_hash[h];
    ਲਈ(;;) {
        ਜੇ (i == 0)
            ਰੋਕੋ;
        e = s1->cached_includes[i - 1];
        ਜੇ (0 == PATHCMP(filename, e->filename))
            ਵਾਪਸ e;
        ਜੇ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ਵਾਪਸ e;
        i = e->hash_ਅਗਲਾ;
    }
    ਜੇ (!ਜੋੜੋ)
        ਵਾਪਸ ਨਿਰਾ;

    e = tcc_malloc(ਆਕਾਰ(CachedInclude) + (len = ਲੜੀ_ਲੰਬਾਈ(filename)));
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_ਜੋੜੋ(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_ਅਗਲਾ = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
    ਲਿਖੋ("adding cached '%s'\n", filename);
#ਜੇ_ਅੰਤ
    ਵਾਪਸ e;
}

ਸਥਿਰ ਪੂਰਨ pragma_parse(TCCState *s1)
{
    ਅਗਲਾ_nomacro();
    ਜੇ (tok == TOK_ਧੱਕੋ_macro || tok == TOK_ਕੱਢੋ_macro) {
        ਪੂਰਨ t = tok, v;
        Sym *s;

        ਜੇ (ਅਗਲਾ(), tok != '(')
            ਜਾਓ pragma_err;
        ਜੇ (ਅਗਲਾ(), tok != TOK_STR)
            ਜਾਓ pragma_err;
        v = tok_alloc(tokc.str.ਅੰਕੜੇ, tokc.str.ਮਾਪ - 1)->tok;
        ਜੇ (ਅਗਲਾ(), tok != ')')
            ਜਾਓ pragma_err;
        ਜੇ (t == TOK_ਧੱਕੋ_macro) {
            ਜਦੋਂ (ਨਿਰਾ == (s = define_ਲੱਭੋ(v)))
                define_ਧੱਕੋ(v, 0, ਨਿਰਾ, ਨਿਰਾ);
            s->type.ref = s; /* set push boundary */
        } ਨਹੀਂਤਾਂ {
            ਲਈ (s = define_ਢੇਰ; s; s = s->prev)
                ਜੇ (s->v == v && s->type.ref == s) {
                    s->type.ref = ਨਿਰਾ;
                    ਰੋਕੋ;
                }
        }
        ਜੇ (s)
            ਸਾਰਣੀ_ident[v - TOK_IDENT]->sym_define = s->d ? s : ਨਿਰਾ;
        ਨਹੀਂਤਾਂ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_once) {
        ਖੋਜ_cached_include(s1, file->true_filename, 1)->once = 1;

    } ਨਹੀਂਤਾਂ ਜੇ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ਵਾਪਸ 1;

    } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        ਅਗਲਾ();
        skip('(');
        ਜੇ (tok == TOK_ASM_ਕੱਢੋ) {
            ਅਗਲਾ();
            ਜੇ (s1->pack_ਢੇਰ_ptr <= s1->pack_ਢੇਰ) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ਢੇਰ_ptr--;
        } ਨਹੀਂਤਾਂ {
            ਪੂਰਨ val = 0;
            ਜੇ (tok != ')') {
                ਜੇ (tok == TOK_ASM_ਧੱਕੋ) {
                    ਅਗਲਾ();
                    ਜੇ (s1->pack_ਢੇਰ_ptr >= s1->pack_ਢੇਰ + PACK_ਢੇਰ_ਮਾਪ - 1)
                        ਜਾਓ stk_error;
                    val = *s1->pack_ਢੇਰ_ptr++;
                    ਜੇ (tok != ',')
                        ਜਾਓ pack_ਸੈੱਟ;
                    ਅਗਲਾ();
                }
                ਜੇ (tok != TOK_CINT)
                    ਜਾਓ pragma_err;
                val = tokc.i;
                ਜੇ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    ਜਾਓ pragma_err;
                ਅਗਲਾ();
            }
        pack_ਸੈੱਟ:
            *s1->pack_ਢੇਰ_ptr = val;
        }
        ਜੇ (tok != ')')
            ਜਾਓ pragma_err;

    } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_comment) {
        ਅੱਖਰ *p; ਪੂਰਨ t;
        ਅਗਲਾ();
        skip('(');
        t = tok;
        ਅਗਲਾ();
        skip(',');
        ਜੇ (tok != TOK_STR)
            ਜਾਓ pragma_err;
        p = tcc_strdup(tokc.str.ਅੰਕੜੇ);
        ਅਗਲਾ();
        ਜੇ (tok != ')')
            ਜਾਓ pragma_err;
        ਜੇ (t == TOK_lib) {
            dynarray_ਜੋੜੋ(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } ਨਹੀਂਤਾਂ {
            ਜੇ (t == TOK_option)
                tcc_ਸੈੱਟ_options(s1, p);
            tcc_free(p);
        }

    } ਨਹੀਂਤਾਂ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ਵਾਪਸ 0;
    }
    ਅਗਲਾ();
    ਵਾਪਸ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC ਖਾਲੀ tccpp_putfile(ਅਚਲ ਅੱਖਰ *filename)
{
    ਅੱਖਰ buf[1024];
    buf[0] = 0;
    ਜੇ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, ਆਕਾਰ buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, ਆਕਾਰ buf, filename);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    normalize_slashes(buf);
#ਜੇ_ਅੰਤ
    ਜੇ (0 == strcmp(file->filename, buf))
        ਵਾਪਸ;
    //printf("new file '%s'\n", buf);
    ਜੇ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, ਆਕਾਰ file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC ਖਾਲੀ preprocess(ਪੂਰਨ is_bof)
{
    TCCState *s1 = tcc_state;
    ਪੂਰਨ c, n, saved_parse_flags;
    ਅੱਖਰ buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_ਅੰਕ
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    ਅਗਲਾ_nomacro();
 redo:
    ਚੋਣ(tok) {
    ਹਾਲਤ TOK_DEFINE:
        pp_debug_tok = tok;
        ਅਗਲਾ_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ਰੋਕੋ;
    ਹਾਲਤ TOK_UNDEF:
        pp_debug_tok = tok;
        ਅਗਲਾ_nomacro();
        pp_debug_symv = tok;
        s = define_ਲੱਭੋ(tok);
        /* undefine symbol by putting an invalid name */
        ਜੇ (s)
            define_undef(s);
        ਅਗਲਾ_nomacro();
        ਰੋਕੋ;
    ਹਾਲਤ TOK_INCLUDE:
    ਹਾਲਤ TOK_INCLUDE_ਅਗਲਾ:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        ਜਾਓ the_ਸਿਰਾ;
    ਹਾਲਤ TOK_IFNDEF:
        c = 1;
        ਜਾਓ do_ifdef;
    ਹਾਲਤ TOK_IF:
        c = ਵਿਅੰਜਕ_preprocess(s1);
        ਜਾਓ do_if;
    ਹਾਲਤ TOK_IFDEF:
        c = 0;
    do_ifdef:
        ਅਗਲਾ_nomacro();
        ਜੇ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ਜੇ (is_bof) {
            ਜੇ (c) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
                ਲਿਖੋ("#ifndef %s\n", get_tok_str(tok, ਨਿਰਾ));
#ਜੇ_ਅੰਤ
                file->ifndef_macro = tok;
            }
        }
        ਜੇ (define_ਲੱਭੋ(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_ਅਗਲਾ)
            c ^= 1;
        ਅਗਲਾ_nomacro();
    do_if:
        ਜੇ (s1->ifdef_ਢੇਰ_ptr >= s1->ifdef_ਢੇਰ + IFDEF_ਢੇਰ_ਮਾਪ)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ਢੇਰ_ptr++ = c;
        ਜਾਓ test_skip;
    ਹਾਲਤ TOK_ELSE:
        ਅਗਲਾ_nomacro();
        ਜੇ (s1->ifdef_ਢੇਰ_ptr == s1->ifdef_ਢੇਰ)
            tcc_error("#else without matching #if");
        ਜੇ (s1->ifdef_ਢੇਰ_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ਢੇਰ_ptr[-1] ^= 3);
        ਜਾਓ test_else;
    ਹਾਲਤ TOK_ELIF:
        ਜੇ (s1->ifdef_ਢੇਰ_ptr == s1->ifdef_ਢੇਰ)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ਢੇਰ_ptr[-1];
        ਜੇ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ਜੇ (c == 1) {
            skip_ਮੰਜ਼ਿਲ_eol(0);
            c = 0;
        } ਨਹੀਂਤਾਂ {
            c = ਵਿਅੰਜਕ_preprocess(s1);
            s1->ifdef_ਢੇਰ_ptr[-1] = c;
        }
    test_else:
        ਜੇ (s1->ifdef_ਢੇਰ_ptr == file->ifdef_ਢੇਰ_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ਜੇ (!(c & 1)) {
            skip_ਮੰਜ਼ਿਲ_eol(1);
            preprocess_skip();
            is_bof = 0;
            ਜਾਓ redo;
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ENDIF:
        ਅਗਲਾ_nomacro();
        ਜੇ (s1->ifdef_ਢੇਰ_ptr <= file->ifdef_ਢੇਰ_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ਢੇਰ_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ਜੇ (file->ifndef_macro &&
            s1->ifdef_ਢੇਰ_ptr == file->ifdef_ਢੇਰ_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ਰੋਕੋ;

    ਹਾਲਤ TOK_ਸਤਰ:
        parse_flags &= ~PARSE_FLAG_TOK_ਅੰਕ;
        ਅਗਲਾ();
        ਜੇ (tok != TOK_PPNUM) {
    ਸਤਰ_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        ਜਾਓ ਸਤਰ_ਅੰਕ_2;
    ਹਾਲਤ TOK_PPNUM:
        ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE)
            ਜਾਓ ignore;
        c = 0; /* no error with extra tokens */
    ਸਤਰ_ਅੰਕ_2:
        ਲਈ (n = 0, q = tokc.str.ਅੰਕੜੇ; *q; ++q) {
            ਜੇ (!isnum(*q))
                ਜਾਓ ਸਤਰ_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        ਅਗਲਾ();
        ਜੇ (tok != TOK_LINEFEED) {
            ਜੇ (tok != TOK_PPSTR || tokc.str.ਅੰਕੜੇ[0] != '"')
                ਜਾਓ ਸਤਰ_err;
            tokc.str.ਅੰਕੜੇ[tokc.str.ਮਾਪ - 2] = 0;
            tccpp_putfile(tokc.str.ਅੰਕੜੇ + 1);
            ਅਗਲਾ();
            /* skip optional level number & advance to next line */
            skip_ਮੰਜ਼ਿਲ_eol(c);
        }
        ਜੇ (file->fd > 0)
            ਕੁੱਲ_ਸਤਰਾਂ += file->ਸਤਰ_ਅੰਕ - n;
        file->ਸਤਰ_ਅੰਕ = n;
        ਰੋਕੋ;

    ਹਾਲਤ TOK_ERROR:
    ਹਾਲਤ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ਜਦੋਂ (c != '\n' && c != CH_EOF) {
            ਜੇ ((q - buf) < ਆਕਾਰ(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ਜੇ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        ਨਹੀਂਤਾਂ
            tcc_warning("#warning %s", buf);
        ਅਗਲਾ_nomacro();
        ਰੋਕੋ;
    }
    ਹਾਲਤ TOK_PRAGMA:
        ਜੇ (!pragma_parse(s1))
            ਜਾਓ ignore;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_LINEFEED:
        ਜਾਓ the_ਸਿਰਾ;
    ਮੂਲ:
        /* ignore gas line comment in an 'S' file. */
        ਜੇ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            ਜਾਓ ignore;
        ਜੇ (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            ਜਾਓ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_ਮੰਜ਼ਿਲ_eol(0);
        ਜਾਓ the_ਸਿਰਾ;
    }
    skip_ਮੰਜ਼ਿਲ_eol(1);
 the_ਸਿਰਾ:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ਸਥਿਰ ਖਾਲੀ parse_escape_string(CString *outstr, ਅਚਲ uint8_t *buf, ਪੂਰਨ is_long)
{
    ਪੂਰਨ c, n, i;
    ਅਚਲ uint8_t *p;

    p = buf;
    ਲਈ(;;) {
        c = *p;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        ਜੇ (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ਚੋਣ(c) {
            ਹਾਲਤ '0': ਹਾਲਤ '1': ਹਾਲਤ '2': ਹਾਲਤ '3':
            ਹਾਲਤ '4': ਹਾਲਤ '5': ਹਾਲਤ '6': ਹਾਲਤ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ਜੇ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ਜੇ (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                ਜਾਓ ਜੋੜੋ_char_nonext;
            ਹਾਲਤ 'x': i = 0; ਜਾਓ parse_hex_or_ucn;
            ਹਾਲਤ 'u': i = 4; ਜਾਓ parse_hex_or_ucn;
            ਹਾਲਤ 'U': i = 8; ਜਾਓ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                ਕਰੋ {
                    c = *p;
                    ਜੇ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    ਨਹੀਂਤਾਂ ਜੇ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    ਨਹੀਂਤਾਂ ਜੇ (isnum(c))
                        c = c - '0';
                    ਨਹੀਂਤਾਂ ਜੇ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    ਨਹੀਂਤਾਂ
                        ਜਾਓ ਜੋੜੋ_hex_or_ucn;
                    n = (ਬਿਨਾਨਿਸ਼ਾਨੀ) n * 16 + c;
                    p++;
                } ਜਦੋਂ (--i);
		ਜੇ (is_long) {
    ਜੋੜੋ_hex_or_ucn:
                    c = n;
		    ਜਾਓ ਜੋੜੋ_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ਜਾਰੀ;
            ਹਾਲਤ 'a':
                c = '\a';
                ਰੋਕੋ;
            ਹਾਲਤ 'b':
                c = '\b';
                ਰੋਕੋ;
            ਹਾਲਤ 'f':
                c = '\f';
                ਰੋਕੋ;
            ਹਾਲਤ 'n':
                c = '\n';
                ਰੋਕੋ;
            ਹਾਲਤ 'r':
                c = '\r';
                ਰੋਕੋ;
            ਹਾਲਤ 't':
                c = '\t';
                ਰੋਕੋ;
            ਹਾਲਤ 'v':
                c = '\v';
                ਰੋਕੋ;
            ਹਾਲਤ 'e':
                ਜੇ (!gnu_ext)
                    ਜਾਓ invalid_escape;
                c = 27;
                ਰੋਕੋ;
            ਹਾਲਤ '\'':
            ਹਾਲਤ '\"':
            ਹਾਲਤ '\\': 
            ਹਾਲਤ '?':
                ਰੋਕੋ;
            ਮੂਲ:
            invalid_escape:
                ਜੇ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                ਨਹੀਂਤਾਂ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ਰੋਕੋ;
            }
        } ਨਹੀਂਤਾਂ ਜੇ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ਪੂਰਨ cont; /* count of continuation bytes */
            ਪੂਰਨ skip; /* how many bytes should skip when error occurred */
            ਪੂਰਨ i;

            /* decode leading byte */
            ਜੇ (c < 0xC2) {
	            skip = 1; ਜਾਓ invalid_utf8_sequence;
            } ਨਹੀਂਤਾਂ ਜੇ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } ਨਹੀਂਤਾਂ ਜੇ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } ਨਹੀਂਤਾਂ ਜੇ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } ਨਹੀਂਤਾਂ {
	            skip = 1; ਜਾਓ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            ਲਈ (i = 1; i <= cont; i++) {
                ਪੂਰਨ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ਜੇ (i == 1) {
                    ਚੋਣ (c) {
                    ਹਾਲਤ 0xE0: l = 0xA0; ਰੋਕੋ;
                    ਹਾਲਤ 0xED: h = 0x9F; ਰੋਕੋ;
                    ਹਾਲਤ 0xF0: l = 0x90; ਰੋਕੋ;
                    ਹਾਲਤ 0xF4: h = 0x8F; ਰੋਕੋ;
                    }
                }

                ਜੇ (p[i] < l || p[i] > h) {
                    skip = i; ਜਾਓ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            ਜਾਓ ਜੋੜੋ_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            ਜਾਓ ਜੋੜੋ_char_nonext;

        }
        p++;
    ਜੋੜੋ_char_nonext:
        ਜੇ (!is_long)
            cstr_ccat(outstr, c);
        ਨਹੀਂਤਾਂ {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            /* store as UTF-16 */
            ਜੇ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } ਨਹੀਂਤਾਂ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#ਨਹੀਂਤਾਂ
            cstr_wccat(outstr, c);
#ਜੇ_ਅੰਤ
        }
    }
    /* add a trailing '\0' */
    ਜੇ (!is_long)
        cstr_ccat(outstr, '\0');
    ਨਹੀਂਤਾਂ
        cstr_wccat(outstr, '\0');
}

ਸਥਿਰ ਖਾਲੀ parse_string(ਅਚਲ ਅੱਖਰ *s, ਪੂਰਨ len)
{
    uint8_t buf[1000], *p = buf;
    ਪੂਰਨ is_long, sep;

    ਜੇ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ਜੇ (len >= ਆਕਾਰ buf)
        p = tcc_malloc(len + 1);
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ਜੇ (p != buf)
        tcc_free(p);

    ਜੇ (sep == '\'') {
        ਪੂਰਨ char_ਮਾਪ, i, n, c;
        /* XXX: make it portable */
        ਜੇ (!is_long)
            tok = TOK_CCHAR, char_ਮਾਪ = 1;
        ਨਹੀਂਤਾਂ
            tok = TOK_LCHAR, char_ਮਾਪ = ਆਕਾਰ(nwchar_t);
        n = tokcstr.ਮਾਪ / char_ਮਾਪ - 1;
        ਜੇ (n < 1)
            tcc_error("empty character constant");
        ਜੇ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        ਲਈ (c = i = 0; i < n; ++i) {
            ਜੇ (is_long)
                c = ((nwchar_t *)tokcstr.ਅੰਕੜੇ)[i];
            ਨਹੀਂਤਾਂ
                c = (c << 8) | ((ਅੱਖਰ *)tokcstr.ਅੰਕੜੇ)[i];
        }
        tokc.i = c;
    } ਨਹੀਂਤਾਂ {
        tokc.str.ਮਾਪ = tokcstr.ਮਾਪ;
        tokc.str.ਅੰਕੜੇ = tokcstr.ਅੰਕੜੇ;
        ਜੇ (!is_long)
            tok = TOK_STR;
        ਨਹੀਂਤਾਂ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_ਮਾਪ 4

/* bn = (bn << shift) | or_val */
ਸਥਿਰ ਪੂਰਨ bn_lshift(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *bn, ਪੂਰਨ ਖਿਸਕਾਓ, ਪੂਰਨ or_val)
{
    ਪੂਰਨ i;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ v;
    ਜੇ (bn[BN_ਮਾਪ - 1] >> (32 - ਖਿਸਕਾਓ))
	ਵਾਪਸ ਖਿਸਕਾਓ;
    ਲਈ(i=0;i<BN_ਮਾਪ;i++) {
        v = bn[i];
        bn[i] = (v << ਖਿਸਕਾਓ) | or_val;
        or_val = v >> (32 - ਖਿਸਕਾਓ);
    }
    ਵਾਪਸ 0;
}

ਸਥਿਰ ਖਾਲੀ bn_zero(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *bn)
{
    ਪੂਰਨ i;
    ਲਈ(i=0;i<BN_ਮਾਪ;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਖਿਆ(ਅਚਲ ਅੱਖਰ *p)
{
    ਪੂਰਨ b, t, ਖਿਸਕਾਓ, frac_ਬਿੱਟ, s, exp_val, ch;
    ਅੱਖਰ *q;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ bn[BN_ਮਾਪ];
    ਲੰਮਾ ਦੁੱਗਣਾ d;

    /*ਸੰਖਿਆ*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ਜੇ (t == '.') {
        ਜਾਓ float_frac_parse;
    } ਨਹੀਂਤਾਂ ਜੇ (t == '0') {
        ਜੇ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } ਨਹੀਂਤਾਂ ਜੇ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ਜਦੋਂ (1) {
        ਜੇ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        ਨਹੀਂਤਾਂ ਜੇ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        ਨਹੀਂਤਾਂ ਜੇ (isnum(ch))
            t = ch - '0';
        ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
        ਜੇ (t >= b)
            ਰੋਕੋ;
        ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ) {
        ਅੰਕ_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ਜੇ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ਜੇ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_ਬਿੱਟ = 0;
            *q = '\0';
            ਜੇ (b == 16)
                ਖਿਸਕਾਓ = 4;
            ਨਹੀਂਤਾਂ 
                ਖਿਸਕਾਓ = 1;
            bn_zero(bn);
            q = token_buf;
            ਜਦੋਂ (1) {
                t = *q++;
                ਜੇ (t == '\0') {
                    ਰੋਕੋ;
                } ਨਹੀਂਤਾਂ ਜੇ (t >= 'a') {
                    t = t - 'a' + 10;
                } ਨਹੀਂਤਾਂ ਜੇ (t >= 'A') {
                    t = t - 'A' + 10;
                } ਨਹੀਂਤਾਂ {
                    t = t - '0';
                }
                frac_ਬਿੱਟ -= bn_lshift(bn, ਖਿਸਕਾਓ, t);
            }
            ਜੇ (ch == '.') {
                ch = *p++;
                ਜਦੋਂ (1) {
                    t = ch;
                    ਜੇ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } ਨਹੀਂਤਾਂ ਜੇ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } ਨਹੀਂਤਾਂ ਜੇ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } ਨਹੀਂਤਾਂ {
                        ਰੋਕੋ;
                    }
                    ਜੇ (t >= b)
                        tcc_error("invalid digit");
                    frac_ਬਿੱਟ -= bn_lshift(bn, ਖਿਸਕਾਓ, t);
                    frac_ਬਿੱਟ += ਖਿਸਕਾਓ;
                    ch = *p++;
                }
            }
            ਜੇ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ਜੇ (ch == '+') {
                ch = *p++;
            } ਨਹੀਂਤਾਂ ਜੇ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ਜੇ (ch < '0' || ch > '9')
                expect("exponent digits");
            ਜਦੋਂ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ਜੇ (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (ਲੰਮਾ ਦੁੱਗਣਾ)bn[3] * 79228162514264337593543950336.0L +
	        (ਲੰਮਾ ਦੁੱਗਣਾ)bn[2] * 18446744073709551616.0L +
	        (ਲੰਮਾ ਦੁੱਗਣਾ)bn[1] * 4294967296.0L +
	        (ਲੰਮਾ ਦੁੱਗਣਾ)bn[0];
            d = ldexpl(d, exp_val - frac_ਬਿੱਟ);
            t = toup(ch);
            ਜੇ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ਦਸ਼ਮਲਵ)d;
            } ਨਹੀਂਤਾਂ ਜੇ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } ਨਹੀਂਤਾਂ {
                tok = TOK_CDOUBLE;
                tokc.d = (ਦੁੱਗਣਾ)d;
            }
        } ਨਹੀਂਤਾਂ {
            /* decimal floats */
            ਜੇ (ch == '.') {
                ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ)
                    ਜਾਓ ਅੰਕ_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ਜਦੋਂ (ch >= '0' && ch <= '9') {
                    ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ)
                        ਜਾਓ ਅੰਕ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ਜੇ (ch == 'e' || ch == 'E') {
                ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ)
                    ਜਾਓ ਅੰਕ_too_long;
                *q++ = ch;
                ch = *p++;
                ਜੇ (ch == '-' || ch == '+') {
                    ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ)
                        ਜਾਓ ਅੰਕ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ਜੇ (ch < '0' || ch > '9')
                    expect("exponent digits");
                ਜਦੋਂ (ch >= '0' && ch <= '9') {
                    ਜੇ (q >= token_buf + STRING_MAX_ਮਾਪ)
                        ਜਾਓ ਅੰਕ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ਜੇ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ਨਿਰਾ);
            } ਨਹੀਂਤਾਂ ਜੇ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ਨਿਰਾ);
            } ਨਹੀਂਤਾਂ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ਨਿਰਾ);
            }
        }
    } ਨਹੀਂਤਾਂ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ n, n1;
        ਪੂਰਨ lcount, ucount, ov = 0;
        ਅਚਲ ਅੱਖਰ *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ਜੇ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ਜਦੋਂ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ਜੇ (t == '\0')
                ਰੋਕੋ;
            ਨਹੀਂਤਾਂ ਜੇ (t >= 'a')
                t = t - 'a' + 10;
            ਨਹੀਂਤਾਂ ਜੇ (t >= 'A')
                t = t - 'A' + 10;
            ਨਹੀਂਤਾਂ
                t = t - '0';
            ਜੇ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ਜੇ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        ਲਈ(;;) {
            t = toup(ch);
            ਜੇ (t == 'L') {
                ਜੇ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ਜੇ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } ਨਹੀਂਤਾਂ ਜੇ (t == 'U') {
                ਜੇ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } ਨਹੀਂਤਾਂ {
                ਰੋਕੋ;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ਜੇ (pp_ਵਿਅੰਜਕ)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ਜੇ (ucount == 0 && b == 10) {
            ਜੇ (lcount <= (LONG_ਮਾਪ == 4)) {
                ਜੇ (n >= 0x80000000U)
                    lcount = (LONG_ਮਾਪ == 4) + 1;
            }
            ਜੇ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (lcount <= (LONG_ਮਾਪ == 4)) {
                ਜੇ (n >= 0x100000000ULL)
                    lcount = (LONG_ਮਾਪ == 4) + 1;
                ਨਹੀਂਤਾਂ ਜੇ (n >= 0x80000000U)
                    ucount = 1;
            }
            ਜੇ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ਜੇ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ਜੇ (lcount) {
            tok = TOK_CLONG;
            ਜੇ (lcount == 2)
                tok = TOK_CLLONG;
	}
	ਜੇ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ਜੇ (ch)
        tcc_error("invalid number");
}


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARSE2(c1, tok1, c2, tok2)              \
    ਹਾਲਤ c1:                                    \
        PEEKC(c, p);                            \
        ਜੇ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } ਨਹੀਂਤਾਂ {                                \
            tok = tok1;                         \
        }                                       \
        ਰੋਕੋ;

/* return next token without macro substitution */
ਸਥਿਰ ਖਾਲੀ ਅਗਲਾ_nomacro(ਖਾਲੀ)
{
    ਪੂਰਨ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ h;

    p = file->buf_ptr;
 redo_no_ਸ਼ੁਰੂ:
    c = *p;
    ਚੋਣ(c) {
    ਹਾਲਤ ' ':
    ਹਾਲਤ '\t':
        tok = c;
        p++;
 maybe_space:
        ਜੇ (parse_flags & PARSE_FLAG_SPACES)
            ਜਾਓ keep_tok_flags;
        ਜਦੋਂ (isidnum_ਸਾਰਣੀ[*p - CH_EOF] & IS_SPC)
            ++p;
        ਜਾਓ redo_no_ਸ਼ੁਰੂ;
    ਹਾਲਤ '\f':
    ਹਾਲਤ '\v':
    ਹਾਲਤ '\r':
        p++;
        ਜਾਓ redo_no_ਸ਼ੁਰੂ;
    ਹਾਲਤ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ਜੇ (c == '\\')
            ਜਾਓ parse_simple;
        ਜੇ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ਜੇ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                ਜਾਓ maybe_newline;
            } ਨਹੀਂਤਾਂ ਜੇ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } ਨਹੀਂਤਾਂ ਜੇ (s1->ifdef_ਢੇਰ_ptr != file->ifdef_ਢੇਰ_ptr) {
                tcc_error("missing #endif");
            } ਨਹੀਂਤਾਂ ਜੇ (s1->include_ਢੇਰ_ptr == s1->include_ਢੇਰ) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } ਨਹੀਂਤਾਂ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ਜੇ (tok_flags & TOK_FLAG_ENDIF) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INC_DEBUG
                    ਲਿਖੋ("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ਨਿਰਾ));
#ਜੇ_ਅੰਤ
                    ਖੋਜ_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ਢੇਰ_ptr--;
                p = file->buf_ptr;
                ਜਾਓ maybe_newline;
            }
        } ਨਹੀਂਤਾਂ {
            ਜਾਓ redo_no_ਸ਼ੁਰੂ;
        }
        ਰੋਕੋ;

    ਹਾਲਤ '\n':
        file->ਸਤਰ_ਅੰਕ++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ਜੇ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            ਜਾਓ redo_no_ਸ਼ੁਰੂ;
        tok = TOK_LINEFEED;
        ਜਾਓ keep_tok_flags;

    ਹਾਲਤ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ਜੇ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            ਜਾਓ maybe_newline;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } ਨਹੀਂਤਾਂ {
#ਜੇ !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM) && !defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
                ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_ਸਤਰ_comment(p - 1);
                    ਜਾਓ redo_no_ਸ਼ੁਰੂ;
                } ਨਹੀਂਤਾਂ
#ਜੇ_ਅੰਤ
                {
                    tok = '#';
                }
            }
        }
        ਰੋਕੋ;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    ਹਾਲਤ '$':
        ਜੇ (!(isidnum_ਸਾਰਣੀ['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            ਜਾਓ parse_simple;

    ਹਾਲਤ 'a': ਹਾਲਤ 'b': ਹਾਲਤ 'c': ਹਾਲਤ 'd':
    ਹਾਲਤ 'e': ਹਾਲਤ 'f': ਹਾਲਤ 'g': ਹਾਲਤ 'h':
    ਹਾਲਤ 'i': ਹਾਲਤ 'j': ਹਾਲਤ 'k': ਹਾਲਤ 'l':
    ਹਾਲਤ 'm': ਹਾਲਤ 'n': ਹਾਲਤ 'o': ਹਾਲਤ 'p':
    ਹਾਲਤ 'q': ਹਾਲਤ 'r': ਹਾਲਤ 's': ਹਾਲਤ 't':
    ਹਾਲਤ 'u': ਹਾਲਤ 'v': ਹਾਲਤ 'w': ਹਾਲਤ 'x':
    ਹਾਲਤ 'y': ਹਾਲਤ 'z': 
    ਹਾਲਤ 'A': ਹਾਲਤ 'B': ਹਾਲਤ 'C': ਹਾਲਤ 'D':
    ਹਾਲਤ 'E': ਹਾਲਤ 'F': ਹਾਲਤ 'G': ਹਾਲਤ 'H':
    ਹਾਲਤ 'I': ਹਾਲਤ 'J': ਹਾਲਤ 'K': 
    ਹਾਲਤ 'M': ਹਾਲਤ 'N': ਹਾਲਤ 'O': ਹਾਲਤ 'P':
    ਹਾਲਤ 'Q': ਹਾਲਤ 'R': ਹਾਲਤ 'S': ਹਾਲਤ 'T':
    ਹਾਲਤ 'U': ਹਾਲਤ 'V': ਹਾਲਤ 'W': ਹਾਲਤ 'X':
    ਹਾਲਤ 'Y': ਹਾਲਤ 'Z': 
    ਹਾਲਤ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ਜਦੋਂ (c = *++p, isidnum_ਸਾਰਣੀ[c - CH_EOF] & (IS_ID|IS_ਅੰਕ))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ਜੇ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_ਮਾਪ - 1);
            pts = &hash_ident[h];
            ਲਈ(;;) {
                ts = *pts;
                ਜੇ (!ts)
                    ਰੋਕੋ;
                ਜੇ (ts->len == len && !memcmp(ts->str, p1, len))
                    ਜਾਓ token_ਮਿਲਿਆ;
                pts = &(ts->hash_ਅਗਲਾ);
            }
            ts = tok_alloc_new(pts, (ਅੱਖਰ *) p1, len);
        token_ਮਿਲਿਆ: ;
        } ਨਹੀਂਤਾਂ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (ਅੱਖਰ *) p1, len);
            p--;
            PEEKC(c, p);
            ਜਦੋਂ (isidnum_ਸਾਰਣੀ[c - CH_EOF] & (IS_ID|IS_ਅੰਕ))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.ਅੰਕੜੇ, tokcstr.ਮਾਪ);
        }
        tok = ts->tok;
        ਰੋਕੋ;
    ਹਾਲਤ 'L':
        t = p[1];
        ਜੇ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ਜੇ (c == '\'' || c == '\"') {
                is_long = 1;
                ਜਾਓ str_const;
            }
            *--p = c = 'L';
        }
        ਜਾਓ parse_ident_fast;

    ਹਾਲਤ '0': ਹਾਲਤ '1': ਹਾਲਤ '2': ਹਾਲਤ '3':
    ਹਾਲਤ '4': ਹਾਲਤ '5': ਹਾਲਤ '6': ਹਾਲਤ '7':
    ਹਾਲਤ '8': ਹਾਲਤ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_ਅੰਕ:
        cstr_reset(&tokcstr);
        ਲਈ(;;) {
            cstr_ccat(&tokcstr, t);
            ਜੇ (!((isidnum_ਸਾਰਣੀ[c - CH_EOF] & (IS_ID|IS_ਅੰਕ))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((ਅੱਖਰ*)tokcstr.ਅੰਕੜੇ)[0] == '0'
                                && toup(((ਅੱਖਰ*)tokcstr.ਅੰਕੜੇ)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ਰੋਕੋ;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.ਮਾਪ = tokcstr.ਮਾਪ;
        tokc.str.ਅੰਕੜੇ = tokcstr.ਅੰਕੜੇ;
        tok = TOK_PPNUM;
        ਰੋਕੋ;

    ਹਾਲਤ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ਜੇ (isnum(c)) {
            t = '.';
            ਜਾਓ parse_ਅੰਕ;
        } ਨਹੀਂਤਾਂ ਜੇ ((isidnum_ਸਾਰਣੀ['.' - CH_EOF] & IS_ID)
                   && (isidnum_ਸਾਰਣੀ[c - CH_EOF] & (IS_ID|IS_ਅੰਕ))) {
            *--p = c = '.';
            ਜਾਓ parse_ident_fast;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '.') {
            PEEKC(c, p);
            ਜੇ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } ਨਹੀਂਤਾਂ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } ਨਹੀਂਤਾਂ {
            tok = '.';
        }
        ਰੋਕੋ;
    ਹਾਲਤ '\'':
    ਹਾਲਤ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ਜੇ (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.ਮਾਪ = tokcstr.ਮਾਪ;
        tokc.str.ਅੰਕੜੇ = tokcstr.ਅੰਕੜੇ;
        tok = TOK_PPSTR;
        ਰੋਕੋ;

    ਹਾਲਤ '<':
        PEEKC(c, p);
        ਜੇ (c == '=') {
            p++;
            tok = TOK_LE;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '<') {
            PEEKC(c, p);
            ਜੇ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } ਨਹੀਂਤਾਂ {
                tok = TOK_SHL;
            }
        } ਨਹੀਂਤਾਂ {
            tok = TOK_LT;
        }
        ਰੋਕੋ;
    ਹਾਲਤ '>':
        PEEKC(c, p);
        ਜੇ (c == '=') {
            p++;
            tok = TOK_GE;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '>') {
            PEEKC(c, p);
            ਜੇ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } ਨਹੀਂਤਾਂ {
                tok = TOK_SAR;
            }
        } ਨਹੀਂਤਾਂ {
            tok = TOK_GT;
        }
        ਰੋਕੋ;
        
    ਹਾਲਤ '&':
        PEEKC(c, p);
        ਜੇ (c == '&') {
            p++;
            tok = TOK_LAND;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } ਨਹੀਂਤਾਂ {
            tok = '&';
        }
        ਰੋਕੋ;
        
    ਹਾਲਤ '|':
        PEEKC(c, p);
        ਜੇ (c == '|') {
            p++;
            tok = TOK_LOR;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } ਨਹੀਂਤਾਂ {
            tok = '|';
        }
        ਰੋਕੋ;

    ਹਾਲਤ '+':
        PEEKC(c, p);
        ਜੇ (c == '+') {
            p++;
            tok = TOK_INC;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '=') {
            p++;
            tok = TOK_A_ਜੋੜੋ;
        } ਨਹੀਂਤਾਂ {
            tok = '+';
        }
        ਰੋਕੋ;
        
    ਹਾਲਤ '-':
        PEEKC(c, p);
        ਜੇ (c == '-') {
            p++;
            tok = TOK_DEC;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } ਨਹੀਂਤਾਂ {
            tok = '-';
        }
        ਰੋਕੋ;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    ਹਾਲਤ '/':
        PEEKC(c, p);
        ਜੇ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            ਜਾਓ maybe_space;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '/') {
            p = parse_ਸਤਰ_comment(p);
            tok = ' ';
            ਜਾਓ maybe_space;
        } ਨਹੀਂਤਾਂ ਜੇ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } ਨਹੀਂਤਾਂ {
            tok = '/';
        }
        ਰੋਕੋ;
        
        /* simple tokens */
    ਹਾਲਤ '@': /* only used in assembler */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM /* comment on arm asm */
        ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_ਸਤਰ_comment(p);
            ਜਾਓ redo_no_ਸ਼ੁਰੂ;
        }
#ਜੇ_ਅੰਤ
    ਹਾਲਤ '(':
    ਹਾਲਤ ')':
    ਹਾਲਤ '[':
    ਹਾਲਤ ']':
    ਹਾਲਤ '{':
    ਹਾਲਤ '}':
    ਹਾਲਤ ',':
    ਹਾਲਤ ';':
    ਹਾਲਤ ':':
    ਹਾਲਤ '?':
    ਹਾਲਤ '~':
    parse_simple:
        tok = c;
        p++;
        ਰੋਕੋ;
    ਹਾਲਤ 0xEF: /* UTF8 BOM ? */
        ਜੇ (p[1] == 0xBB && p[2] == 0xBF && p == file->ਬਫਰ) {
            p += 3;
            ਜਾਓ redo_no_ਸ਼ੁਰੂ;
        }
    ਮੂਲ:
        ਜੇ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    ਜਾਓ parse_ident_fast;
        ਜੇ (parse_flags & PARSE_FLAG_ASM_FILE)
            ਜਾਓ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ਰੋਕੋ;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ਜੇ defined(PARSE_DEBUG)
    ਲਿਖੋ("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#ਜੇ_ਅੰਤ
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PP_DEBUG
ਸਥਿਰ ਪੂਰਨ indent;
ਸਥਿਰ ਖਾਲੀ define_print(TCCState *s1, ਪੂਰਨ v);
ਸਥਿਰ ਖਾਲੀ pp_print(ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, ਪੂਰਨ v, ਅਚਲ ਪੂਰਨ *str)
{
    FILE *fp = tcc_state->ppfp;

    ਜੇ (ਸੁਨੇਹਾ[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    ਨਹੀਂਤਾਂ ਜੇ (ਸੁਨੇਹਾ[0] == '+')
         ++indent, ++ਸੁਨੇਹਾ;
    ਨਹੀਂਤਾਂ ਜੇ (ਸੁਨੇਹਾ[0] == '-')
        --indent, ++ਸੁਨੇਹਾ;

    fprintf(fp, "%*s", indent, "");
    ਜੇ (ਸੁਨੇਹਾ[0] == '#') {
        define_print(tcc_state, v);
    } ਨਹੀਂਤਾਂ {
        tok_print(str, v ? "%s %s" : "%s", ਸੁਨੇਹਾ, get_tok_str(v, 0));
    }
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PP_PRINT(x) pp_print x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PP_PRINT(x)
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ਅਚਲ ਪੂਰਨ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ਸਥਿਰ ਪੂਰਨ *macro_arg_subst(Sym **nested_list, ਅਚਲ ਪੂਰਨ *macro_str, Sym *ਦਲੀਲਾਂ)
{
    ਪੂਰਨ t, t0, t1, t2, n;
    ਅਚਲ ਪੂਰਨ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    ਲਈ (s = ਦਲੀਲਾਂ, n = 0; s; s = s->prev, ++n);
    ਜਦੋਂ (n--) {
        ਲਈ (s = ਦਲੀਲਾਂ, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#ਜੇ_ਅੰਤ

    tok_str_new(&str);
    t0 = t1 = 0;
    ਜਦੋਂ(1) {
        TOK_GET(&t, &macro_str, &cval);
        ਜੇ (!t)
            ਰੋਕੋ;
        ਜੇ (t == '#') {
            /* stringize */
            ਕਰੋ t = *macro_str++; ਜਦੋਂ (t == ' ');
            s = sym_find2(ਦਲੀਲਾਂ, t);
            ਜੇ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ਜਦੋਂ (*st != TOK_EOF) {
                    ਅਚਲ ਅੱਖਰ *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ਜਦੋਂ (*s) {
                        ਜੇ (t == TOK_PPSTR && *s != '\'')
                            ਜੋੜੋ_char(&tokcstr, *s);
                        ਨਹੀਂਤਾਂ
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.ਮਾਪ = tokcstr.ਮਾਪ;
                cval.str.ਅੰਕੜੇ = tokcstr.ਅੰਕੜੇ;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
            } ਨਹੀਂਤਾਂ ਜੇ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_ਜੋੜੋ(&str, '#');
#ਜੇ_ਅੰਤ
            } ਨਹੀਂਤਾਂ {
                expect("macro parameter after '#'");
            }
        } ਨਹੀਂਤਾਂ ਜੇ (t >= TOK_IDENT) {
            s = sym_find2(ਦਲੀਲਾਂ, t);
            ਜੇ (s) {
                st = s->d;
                n = 0;
                ਜਦੋਂ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ਜੇ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ਜੇ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ਪੂਰਨ c = str.str[str.len - 1];
                        ਜਦੋਂ (str.str[--str.len] != ',')
                            ;
                        ਜੇ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } ਨਹੀਂਤਾਂ {
                            /* suppress '##' and add variable */
                            str.len++;
                            ਜੇ (c == ' ')
                                str.str[str.len++] = c;
                            ਜਾਓ ਜੋੜੋ_var;
                        }
                    } ਨਹੀਂਤਾਂ {
                        ਜੇ (*st == TOK_EOF)
                            tok_str_ਜੋੜੋ(&str, TOK_PLCHLDR);
                    }
                } ਨਹੀਂਤਾਂ {
            ਜੋੜੋ_var:
		    ਜੇ (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_ਜੋੜੋ(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                ਜਦੋਂ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } ਨਹੀਂਤਾਂ {
                tok_str_ਜੋੜੋ(&str, t);
            }
        } ਨਹੀਂਤਾਂ {
            tok_str_add2(&str, t, &cval);
        }
        ਜੇ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_ਜੋੜੋ(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ਵਾਪਸ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ *macro_twosharps(ਅਚਲ ਪੂਰਨ *ptr0)
{
    ਪੂਰਨ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ਅਚਲ ਪੂਰਨ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    ਲਈ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ਜੇ (t1 == 0)
            ਰੋਕੋ;
        ਲਈ (;;) {
            n = 0;
            ਜਦੋਂ ((t2 = ptr[n]) == ' ')
                ++n;
            ਜੇ (t2 != TOK_PPJOIN)
                ਰੋਕੋ;
            ptr += n;
            ਜਦੋਂ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ਜੇ (t2 == TOK_PLCHLDR)
                ਜਾਰੀ;
            ਜੇ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ਜੇ (tokcstr.ਮਾਪ) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.ਮਾਪ);
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(file->ਬਫਰ, tokcstr.ਅੰਕੜੇ, tokcstr.ਮਾਪ);
            tok_flags = 0; /* don't interpret '#' */
            ਲਈ (n = 0;;n = l) {
                ਅਗਲਾ_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ਜੇ (*file->buf_ptr == 0)
                    ਰੋਕੋ;
                tok_str_ਜੋੜੋ(&macro_str1, ' ');
                l = file->buf_ptr - file->ਬਫਰ;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->ਬਫਰ + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ਜੇ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_ਜੋੜੋ(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ਵਾਪਸ macro_str1.str;
}

ਸਥਿਰ ਪੂਰਨ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ਪੂਰਨ c;
    ਲਈ (;;) {
        PEEKC(c, p);
        ਚੋਣ (c) {
        ਹਾਲਤ '/':
            PEEKC(c, p);
            ਜੇ (c == '*')
                p = parse_comment(p);
            ਨਹੀਂਤਾਂ ਜੇ (c == '/')
                p = parse_ਸਤਰ_comment(p);
            ਨਹੀਂਤਾਂ {
                c = *--p = '/';
                ਜਾਓ leave;
            }
            --p, c = ' ';
            ਰੋਕੋ;
        ਹਾਲਤ ' ': ਹਾਲਤ '\t':
            ਰੋਕੋ;
        ਹਾਲਤ '\f': ਹਾਲਤ '\v': ਹਾਲਤ '\r':
            ਜਾਰੀ;
        ਹਾਲਤ '\n':
            file->ਸਤਰ_ਅੰਕ++, tok_flags |= TOK_FLAG_BOL;
            ਰੋਕੋ;
        ਮੂਲ: leave:
            file->buf_ptr = p;
            ਵਾਪਸ c;
        }
        ਜੇ (ws_str)
            tok_str_ਜੋੜੋ(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ਸਥਿਰ ਪੂਰਨ ਅਗਲਾ_argstream(Sym **nested_list, TokenString *ws_str)
{
    ਪੂਰਨ t;
    Sym *sa;

    ਜਦੋਂ (macro_ptr) {
        ਅਚਲ ਪੂਰਨ *m = macro_ptr;
        ਜਦੋਂ ((t = *m) != 0) {
            ਜੇ (ws_str) {
                ਜੇ (t != ' ')
                    ਵਾਪਸ t;
                ++m;
            } ਨਹੀਂਤਾਂ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ਵਾਪਸ tok;
            }
        }
        ਸਿਰਾ_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ਜੇ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ਜੇ (ws_str) {
        ਵਾਪਸ peek_file(ws_str);
    } ਨਹੀਂਤਾਂ {
        ਅਗਲਾ_nomacro();
        ਜੇ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ਵਾਪਸ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ਸਥਿਰ ਪੂਰਨ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ਪੂਰਨ t;
    ਪੂਰਨ v = s->v;

    PP_PRINT(("#", v, s->d));
    ਜੇ (s->d) {
        ਪੂਰਨ *mstr = s->d;
        ਪੂਰਨ *jstr;
        Sym *sa;
        ਪੂਰਨ ret;

        ਜੇ (s->type.t & MACRO_FUNC) {
            ਪੂਰਨ saved_parse_flags = parse_flags;
            TokenString str;
            ਪੂਰਨ parlevel, i;
            Sym *sa1, *ਦਲੀਲਾਂ;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = ਅਗਲਾ_argstream(nested_list, &str);
            ਜੇ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ਜੇ (parse_flags & PARSE_FLAG_SPACES)
                    ਲਈ (i = 0; i < str.len; i++)
                        tok_str_ਜੋੜੋ(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ਵਾਪਸ 0;
            } ਨਹੀਂਤਾਂ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            ਦਲੀਲਾਂ = ਨਿਰਾ;
            sa = s->ਅਗਲਾ;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            ਲਈ(;;) {
                ਕਰੋ {
                    t = ਅਗਲਾ_argstream(nested_list, ਨਿਰਾ);
                } ਜਦੋਂ (t == ' ' || --i);

                ਜੇ (!sa) {
                    ਜੇ (t == ')') /* handle '()' case */
                        ਰੋਕੋ;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            ਖਾਲੀ_ਥਾਵਾਂ_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ਜਦੋਂ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ਜੇ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ਜੇ (t == '(')
                        parlevel++;
                    ਜੇ (t == ')')
                        parlevel--;
                    ਜੇ (t == ' ')
                        str.need_spc |= 1;
                    ਨਹੀਂਤਾਂ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = ਅਗਲਾ_argstream(nested_list, ਨਿਰਾ);
                }
                tok_str_ਜੋੜੋ(&str, TOK_EOF);
                sa1 = sym_push2(&ਦਲੀਲਾਂ, sa->v & ~SYM_ਖੇਤਰ, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->ਅਗਲਾ;
                ਜੇ (t == ')') {
                    ਜੇ (!sa)
                        ਰੋਕੋ;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ਜੇ (sa->type.t && gnu_ext)
                        ਜਾਓ ਖਾਲੀ_ਥਾਵਾਂ_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, ਦਲੀਲਾਂ);
            /* free memory */
            sa = ਦਲੀਲਾਂ;
            ਜਦੋਂ (sa) {
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
        ਜੇ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ਜੇ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ਜੇ (jstr != mstr)
            tok_str_free_str(jstr);
        ਜੇ (mstr != s->d)
            tok_str_free_str(mstr);
        ਵਾਪਸ ret;

    } ਨਹੀਂਤਾਂ {
        CValue cval;
        ਅੱਖਰ buf[32], *cstrval = buf;

        /* special macros */
        ਜੇ (v == TOK_ਸਤਰ_2 || v == TOK___COUNTER__) {
            t = v == TOK_ਸਤਰ_2 ? file->ਸਤਰ_ਅੰਕ : pp_counter++;
            snprintf(buf, ਆਕਾਰ(buf), "%d", t);
            t = TOK_PPNUM;
            ਜਾਓ ਜੋੜੋ_cstr1;

        } ਨਹੀਂਤਾਂ ਜੇ (v == TOK___FILE__) {
            cstrval = file->filename;
            ਜਾਓ ਜੋੜੋ_cstr;

        } ਨਹੀਂਤਾਂ ਜੇ (v == TOK___DATE__ || v == TOK_ਸਮਾਂ) {
            time_t ti;
            ਬਣਤਰ tm *tm;
            ਸਮਾਂ(&ti);
            tm = localtime(&ti);
            ਜੇ (v == TOK___DATE__) {
                ਸਥਿਰ ਅੱਖਰ ਅਚਲ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, ਆਕਾਰ(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } ਨਹੀਂਤਾਂ {
                snprintf(buf, ਆਕਾਰ(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        ਜੋੜੋ_cstr:
            t = TOK_STR;
        ਜੋੜੋ_cstr1:
            cval.str.ਮਾਪ = ਲੜੀ_ਲੰਬਾਈ(cstrval) + 1;
            cval.str.ਅੰਕੜੇ = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ਵਾਪਸ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ਸਥਿਰ ਪੂਰਨ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ਅਚਲ ਪੂਰਨ *macro_str
    )
{
    Sym *s;
    ਪੂਰਨ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PP_DEBUG
    ਪੂਰਨ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#ਜੇ_ਅੰਤ

    ਜਦੋਂ (1) {
        TOK_GET(&t, &macro_str, &cval);
        ਜੇ (t == 0 || t == TOK_EOF)
            ਰੋਕੋ;
        ਜੇ (t >= TOK_IDENT) {
            s = define_ਲੱਭੋ(t);
            ਜੇ (s == ਨਿਰਾ || nosubst)
                ਜਾਓ no_subst;
            /* if nested substitution, do nothing */
            ਜੇ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_ਖੇਤਰ;
                ਜਾਓ no_subst;
            }
            str = tok_str_alloc();
            str->str = (ਪੂਰਨ*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ਜੇ (macro_ਢੇਰ != str) {
                /* already finished by reading function macro arguments */
                ਰੋਕੋ;
            }
            macro_str = macro_ptr;
            ਸਿਰਾ_macro ();
        } ਨਹੀਂਤਾਂ ਜੇ (t == ' ') {
            ਜੇ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } ਨਹੀਂਤਾਂ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ਜੇ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ਜੇ (t == TOK_DEFINED && pp_ਵਿਅੰਜਕ)
                nosubst = 1;
        }
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ PP_DEBUG
    tok_str_ਜੋੜੋ(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#ਜੇ_ਅੰਤ
    ਵਾਪਸ nosubst;
}

/* return next token with macro substitution */
ST_FUNC ਖਾਲੀ ਅਗਲਾ(ਖਾਲੀ)
{
    ਪੂਰਨ t;
    ਜਦੋਂ (macro_ptr) {
redo:
        t = *macro_ptr;
        ਜੇ (TOK_HAS_ਮੁੱਲ(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ਜੇ (t == TOK_LINENUM) {
                file->ਸਤਰ_ਅੰਕ = tokc.i;
                ਜਾਓ redo;
            }
            ਜਾਓ convert;
        } ਨਹੀਂਤਾਂ ਜੇ (t == 0) {
            /* end of macro or unget token string */
            ਸਿਰਾ_macro();
            ਜਾਰੀ;
        } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_EOF) {
            /* do nothing */
        } ਨਹੀਂਤਾਂ {
            ++macro_ptr;
            t &= ~SYM_ਖੇਤਰ; /* remove 'nosubst' marker */
            ਜੇ (t == '\\') {
                ਜੇ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ਵਾਪਸ;
    }

    ਅਗਲਾ_nomacro();
    t = tok;
    ਜੇ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_ਲੱਭੋ(t);
        ਜੇ (s) {
            Sym *nested_list = ਨਿਰਾ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_ਜੋੜੋ(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            ਜਾਓ redo;
        }
        ਵਾਪਸ;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ਜੇ (t == TOK_PPNUM) {
        ਜੇ  (parse_flags & PARSE_FLAG_TOK_ਅੰਕ)
            parse_ਸੰਖਿਆ(tokc.str.ਅੰਕੜੇ);
    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_PPSTR) {
        ਜੇ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.ਅੰਕੜੇ, tokc.str.ਮਾਪ - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN ਖਾਲੀ unget_tok(ਪੂਰਨ ਆਖਰੀ_tok)
{
    TokenString *str = &unget_buf;
    ਪੂਰਨ alloc = 0;
    ਜੇ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ਜੇ (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_ਜੋੜੋ(str, 0);
    begin_macro(str, alloc);
    tok = ਆਖਰੀ_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ਸਥਿਰ ਅਚਲ ਅੱਖਰ * ਅਚਲ ਨਿਸ਼ਾਨਾ_os_defs =
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    "_WIN32\0"
# ਜੇ PTR_ਮਾਪ == 8
    "_WIN64\0"
# endif
#ਨਹੀਂਤਾਂ
# ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# ਨਹੀਂਤਾਂ
    "__linux__\0"
    "__linux\0"
#  ਜੇ TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#ਜੇ_ਅੰਤ
    ;

ਸਥਿਰ ਖਾਲੀ putdef(CString *cs, ਅਚਲ ਅੱਖਰ *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ਸਥਿਰ ਖਾਲੀ putdefs(CString *cs, ਅਚਲ ਅੱਖਰ *p)
{
    ਜਦੋਂ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ਸਥਿਰ ਖਾਲੀ tcc_predefs(TCCState *s1, CString *cs, ਪੂਰਨ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_ਸੰਸਕਰਣ[4]);
    putdefs(cs, ਨਿਸ਼ਾਨਾ_machine_defs);
    putdefs(cs, ਨਿਸ਼ਾਨਾ_os_defs);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    ਜੇ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#ਜੇ_ਅੰਤ
    ਜੇ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ਜੇ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ)
      putdef(cs, "__TCC_RUN__");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ਜੇ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#ਜੇ_ਅੰਤ
    ਜੇ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ਜੇ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ਜੇ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ਜੇ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_ਮਾਪ);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_ਮਾਪ);
    ਜੇ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ਜੇ CONFIG_TCC_PREDEFS
        #ਅਨ੍ਤਰ੍ਭਾਵ "tccdefs_.h" /* include as strings */
#ਨਹੀਂਤਾਂ
        "#include <tccdefs.h>\n" /* load at runtime */
#ਜੇ_ਅੰਤ
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC ਖਾਲੀ preprocess_ਸ਼ੁਰੂ(TCCState *s1, ਪੂਰਨ filetype)
{
    ਪੂਰਨ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ਢੇਰ_ptr = s1->include_ਢੇਰ;
    s1->ifdef_ਢੇਰ_ptr = s1->ifdef_ਢੇਰ;
    file->ifdef_ਢੇਰ_ptr = s1->ifdef_ਢੇਰ_ptr;
    pp_ਵਿਅੰਜਕ = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ਢੇਰ[0] = 0;
    s1->pack_ਢੇਰ_ptr = s1->pack_ਢੇਰ;

    ਸੈੱਟ_idnum('$', s1->dollars_ਵਿੱਚ_identifiers ? IS_ID : 0);
    ਸੈੱਟ_idnum('.', is_asm ? IS_ID : 0);

    ਜੇ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ਜੇ (s1->cmdline_defs.ਮਾਪ)
          cstr_cat(&cstr, s1->cmdline_defs.ਅੰਕੜੇ, s1->cmdline_defs.ਮਾਪ);
        ਜੇ (s1->cmdline_incl.ਮਾਪ)
          cstr_cat(&cstr, s1->cmdline_incl.ਅੰਕੜੇ, s1->cmdline_incl.ਮਾਪ);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ਢੇਰ_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.ਮਾਪ);
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(file->ਬਫਰ, cstr.ਅੰਕੜੇ, cstr.ਮਾਪ);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC ਖਾਲੀ preprocess_ਸਿਰਾ(TCCState *s1)
{
    ਜਦੋਂ (macro_ਢੇਰ)
        ਸਿਰਾ_macro();
    macro_ptr = ਨਿਰਾ;
    ਜਦੋਂ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ਪੂਰਨ ਸੈੱਟ_idnum(ਪੂਰਨ c, ਪੂਰਨ val)
{
    ਪੂਰਨ prev = isidnum_ਸਾਰਣੀ[c - CH_EOF];
    isidnum_ਸਾਰਣੀ[c - CH_EOF] = val;
    ਵਾਪਸ prev;
}

ST_FUNC ਖਾਲੀ tccpp_new(TCCState *s)
{
    ਪੂਰਨ i, c;
    ਅਚਲ ਅੱਖਰ *p, *r;

    /* init isid table */
    ਲਈ(i = CH_EOF; i<128; i++)
        ਸੈੱਟ_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_ਅੰਕ
            : 0);

    ਲਈ(i = 128; i<256; i++)
        ਸੈੱਟ_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_ਮਾਪ);
    tal_new(&tokstr_alloc, TOKSTR_TAL_ਮਾਪ);

    memset(hash_ident, 0, TOK_HASH_ਮਾਪ * ਆਕਾਰ(TokenSym *));
    memset(s->cached_includes_hash, 0, ਆਕਾਰ s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_ਮਾਪ);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_ਮਾਪ);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_ਮਾਪ);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ਜਦੋਂ (*p) {
        r = p;
        ਲਈ(;;) {
            c = *r++;
            ਜੇ (c == '\0')
                ਰੋਕੋ;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ਧੱਕੋ(TOK_ਸਤਰ_2, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
    define_ਧੱਕੋ(TOK___FILE__, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
    define_ਧੱਕੋ(TOK___DATE__, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
    define_ਧੱਕੋ(TOK_ਸਮਾਂ, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
    define_ਧੱਕੋ(TOK___COUNTER__, MACRO_OBJ, ਨਿਰਾ, ਨਿਰਾ);
}

ST_FUNC ਖਾਲੀ tccpp_delete(TCCState *s)
{
    ਪੂਰਨ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ਜੇ (n > ਕੁੱਲ_idents)
        ਕੁੱਲ_idents = n;
    ਲਈ (i = n; --i >= 0;)
        tal_free(&toksym_alloc, ਸਾਰਣੀ_ident[i]);
    tcc_free(ਸਾਰਣੀ_ident);
    ਸਾਰਣੀ_ident = ਨਿਰਾ;

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

ਸਥਿਰ ਪੂਰਨ pp_need_space(ਪੂਰਨ a, ਪੂਰਨ b);

ਸਥਿਰ ਖਾਲੀ tok_print(ਅਚਲ ਪੂਰਨ *str, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ਪੂਰਨ t, t0, s;
    CValue cval;

    va_start(ap, ਸੁਨੇਹਾ);
    vfprintf(fp, ਸੁਨੇਹਾ, ap);
    va_end(ap);

    s = t0 = 0;
    ਜਦੋਂ (str) {
	TOK_GET(&t, &str, &cval);
	ਜੇ (t == 0 || t == TOK_EOF)
	    ਰੋਕੋ;
        ਜੇ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ਸਥਿਰ ਖਾਲੀ pp_ਸਤਰ(TCCState *s1, BufferedFile *f, ਪੂਰਨ level)
{
    ਪੂਰਨ d = f->ਸਤਰ_ਅੰਕ - f->ਸਤਰ_ref;

    ਜੇ (s1->dflag & 4)
	ਵਾਪਸ;

    ਜੇ (s1->Pflag == ਸਤਰ_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } ਨਹੀਂਤਾਂ ਜੇ (level == 0 && f->ਸਤਰ_ref && d < 8) {
	ਜਦੋਂ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } ਨਹੀਂਤਾਂ ਜੇ (s1->Pflag == ਸਤਰ_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->ਸਤਰ_ਅੰਕ, f->filename);
    } ਨਹੀਂਤਾਂ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->ਸਤਰ_ਅੰਕ, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->ਸਤਰ_ref = f->ਸਤਰ_ਅੰਕ;
}

ਸਥਿਰ ਖਾਲੀ define_print(TCCState *s1, ਪੂਰਨ v)
{
    FILE *fp;
    Sym *s;

    s = define_ਲੱਭੋ(v);
    ਜੇ (ਨਿਰਾ == s || ਨਿਰਾ == s->d)
        ਵਾਪਸ;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ਨਿਰਾ));
    ਜੇ (s->type.t & MACRO_FUNC) {
        Sym *a = s->ਅਗਲਾ;
        fprintf(fp,"(");
        ਜੇ (a)
            ਲਈ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ਨਿਰਾ));
                ਜੇ (!(a = a->ਅਗਲਾ))
                    ਰੋਕੋ;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ਸਥਿਰ ਖਾਲੀ pp_debug_ਨਿਰਧਾਰਤ_ਕਰਦਾ(TCCState *s1)
{
    ਪੂਰਨ v, t;
    ਅਚਲ ਅੱਖਰ *vs;
    FILE *fp;

    t = pp_debug_tok;
    ਜੇ (t == 0)
        ਵਾਪਸ;

    file->ਸਤਰ_ਅੰਕ--;
    pp_ਸਤਰ(s1, file, 0);
    file->ਸਤਰ_ref = ++file->ਸਤਰ_ਅੰਕ;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ਨਿਰਾ);
    ਜੇ (t == TOK_DEFINE) {
        define_print(s1, v);
    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_ਧੱਕੋ_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } ਨਹੀਂਤਾਂ ਜੇ (t == TOK_ਕੱਢੋ_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ਸਥਿਰ ਪੂਰਨ pp_need_space(ਪੂਰਨ a, ਪੂਰਨ b)
{
    ਵਾਪਸ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ਸਥਿਰ ਪੂਰਨ pp_check_he0xE(ਪੂਰਨ t, ਅਚਲ ਅੱਖਰ *p)
{
    ਜੇ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ਵਾਪਸ 'E';
    ਵਾਪਸ t;
}

/* Preprocess the current file */
ST_FUNC ਪੂਰਨ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ਪੂਰਨ token_ਵੇਖਿਆ, spcs, level;
    ਅਚਲ ਅੱਖਰ *p;
    ਅੱਖਰ white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ਜੇ (s1->Pflag == ਸਤਰ_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_ਅੰਕ, s1->Pflag = 1;

    ਜੇ (s1->do_bench) {
	/* for PP benchmarks */
	ਕਰੋ ਅਗਲਾ(); ਜਦੋਂ (tok != TOK_EOF);
	ਵਾਪਸ 0;
    }

    token_ਵੇਖਿਆ = TOK_LINEFEED, spcs = 0, level = 0;
    ਜੇ (file->prev)
        pp_ਸਤਰ(s1, file->prev, level++);
    pp_ਸਤਰ(s1, file, level);

    ਲਈ (;;) {
        iptr = s1->include_ਢੇਰ_ptr;
        ਅਗਲਾ();
        ਜੇ (tok == TOK_EOF)
            ਰੋਕੋ;

        level = s1->include_ਢੇਰ_ptr - iptr;
        ਜੇ (level) {
            ਜੇ (level > 0)
                pp_ਸਤਰ(s1, *iptr, 0);
            pp_ਸਤਰ(s1, file, level);
        }
        ਜੇ (s1->dflag & 7) {
            pp_debug_ਨਿਰਧਾਰਤ_ਕਰਦਾ(s1);
            ਜੇ (s1->dflag & 4)
                ਜਾਰੀ;
        }

        ਜੇ (is_space(tok)) {
            ਜੇ (spcs < ਆਕਾਰ white - 1)
                white[spcs++] = tok;
            ਜਾਰੀ;
        } ਨਹੀਂਤਾਂ ਜੇ (tok == TOK_LINEFEED) {
            spcs = 0;
            ਜੇ (token_ਵੇਖਿਆ == TOK_LINEFEED)
                ਜਾਰੀ;
            ++file->ਸਤਰ_ref;
        } ਨਹੀਂਤਾਂ ਜੇ (token_ਵੇਖਿਆ == TOK_LINEFEED) {
            pp_ਸਤਰ(s1, file, 0);
        } ਨਹੀਂਤਾਂ ਜੇ (spcs == 0 && pp_need_space(token_ਵੇਖਿਆ, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_ਵੇਖਿਆ = pp_check_he0xE(tok, p);
    }
    ਵਾਪਸ 0;
}

/* ------------------------------------------------------------------------- */
