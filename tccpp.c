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

#నిర్వచించు USING_GLOBALS
#అన్తర్భావ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#నిర్వచించు ACCEPT_LF_లోపల_అక్షరశ్రేణులు 0

/********************************************************/
/* global variables */

ST_దత్తాంశం పూర్ణాంకం tok_flags;
ST_దత్తాంశం పూర్ణాంకం parse_flags;

ST_దత్తాంశం నిర్మాణం BufferedFile *file;
ST_దత్తాంశం పూర్ణాంకం tok;
ST_దత్తాంశం CValue tokc;
ST_దత్తాంశం స్థిరరాశి పూర్ణాంకం *macro_ptr;
ST_దత్తాంశం CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_దత్తాంశం పూర్ణాంకం tok_ident;
ST_దత్తాంశం TokenSym **పట్టిక_ident;
ST_దత్తాంశం పూర్ణాంకం pp_సమాసం;

/* ------------------------------------------------------------------------- */

స్థిర TokenSym *hash_ident[TOK_HASH_కొలత];
స్థిర అక్షరం token_buf[STRING_MAX_కొలత + 1];
స్థిర CString cstr_buf;
స్థిర TokenString tokstr_buf;
స్థిర TokenString unget_buf;
స్థిర గుర్తులేని అక్షరం isidnum_పట్టిక[256 - CH_EOF];
స్థిర పూర్ణాంకం pp_debug_tok, pp_debug_symv;
స్థిర పూర్ణాంకం pp_counter;
స్థిర శూన్య tok_print(స్థిరరాశి పూర్ణాంకం *str, స్థిరరాశి అక్షరం *సందేశం, ...);
స్థిర శూన్య తదుపరి_nomacro(శూన్య);
స్థిర శూన్య parse_సంఖ్య(స్థిరరాశి అక్షరం *p);
స్థిర శూన్య parse_string(స్థిరరాశి అక్షరం *p, పూర్ణాంకం len);

స్థిర నిర్మాణం TinyAlloc *toksym_alloc;
స్థిర నిర్మాణం TinyAlloc *tokstr_alloc;

స్థిర TokenString *macro_దొంతర;

స్థిర స్థిరరాశి అక్షరం tcc_keywords[] = 
#నిర్వచించు DEF(id, str) str "\0"
#అన్తర్భావ "tcctok.h"
#నిర్వచనం_రద్దు DEF
;

/* WARNING: the content of this string encodes token numbers */
స్థిర స్థిరరాశి గుర్తులేని అక్షరం tok_two_chars[] =
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
    '+','=', TOK_A_కూడు,
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

ST_FUNC శూన్య skip(పూర్ణాంకం c)
{
    ఒకవేళ (tok != c) {
        అక్షరం tmp[40];
        pstrcpy(tmp, పరిమాణం tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    తదుపరి();
}

ST_FUNC శూన్య expect(స్థిరరాశి అక్షరం *సందేశం)
{
    tcc_error("%s expected", సందేశం);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#నిర్వచించు USE_TAL

#నిర్వచితం_కాకపోతే USE_TAL /* may cause memory leaks after errors */
#నిర్వచించు tal_free(al, p) tcc_free(p)
#నిర్వచించు tal_realloc(al, p, కొలత) tcc_realloc(p, కొలత)
#నిర్వచించు tal_new(a,b)
#నిర్వచించు tal_delete(a)
#లేకపోతే
#ఒకవేళ !defined(MEM_DEBUG)
#నిర్వచించు tal_free(al, p) tal_free_impl(al, p)
#నిర్వచించు tal_realloc(al, p, కొలత) tal_realloc_impl(al, p, కొలత)
#నిర్వచించు TAL_DEBUG_PARAMS
#లేకపోతే
#నిర్వచించు TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#నిర్వచించు tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#నిర్వచించు tal_realloc(al, p, కొలత) tal_realloc_impl(al, p, కొలత, __FILE__, __LINE__)
#నిర్వచించు TAL_DEBUG_PARAMS , స్థిరరాశి అక్షరం *sfile, పూర్ణాంకం sline
#అయితే_ముగింపు

#నిర్వచించు TOKSYM_TAL_కొలత (256 * 1024) /* allocator for TokenSym in table_ident */
#నిర్వచించు TOKSTR_TAL_కొలత (256 * 1024) /* allocator for TokenString instances */

రకనిర్వచనం నిర్మాణం TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    నిర్మాణం TinyAlloc *తదుపరి;
    గుర్తులేని nb_allocs;
    గుర్తులేని కొలత;
#ఒకవేళ TAL_INFO
    గుర్తులేని nb_peak;
    గుర్తులేని nb_మొత్తం;
    uint8_t *peak_p;
#అయితే_ముగింపు
    సంఘం {
        uint8_t బఫరు[1];
        కొలత_t _aligner_;
    };
} TinyAlloc;

రకనిర్వచనం నిర్మాణం tal_శీర్షిక_t {
    కొలత_t  కొలత; /* word align */
#ఒకవేళ TAL_DEBUG
    పూర్ణాంకం     పంక్తి_అంకె; /* negative line_num used for double free check */
    అక్షరం    file_name[40];
#అయితే_ముగింపు
} tal_శీర్షిక_t;

#నిర్వచించు TAL_ALIGN(కొలత) \
    (((కొలత) + (పరిమాణం (కొలత_t) - 1)) & ~(పరిమాణం (కొలత_t) - 1))

/* ------------------------------------------------------------------------- */

స్థిర TinyAlloc *tal_new(TinyAlloc **pal, గుర్తులేని కొలత)
{
    TinyAlloc *al = tcc_malloc(పరిమాణం(TinyAlloc) - పరిమాణం (కొలత_t) + కొలత);
    al->p = al->బఫరు;
    al->bufend = al->బఫరు + కొలత;
    al->nb_allocs = 0;
    al->తదుపరి = *pal, *pal = al;
    al->కొలత = al->తదుపరి ? al->తదుపరి->కొలత : కొలత;
#ఒకవేళ TAL_INFO
    al->nb_peak = 0;
    al->nb_మొత్తం = 0;
    al->peak_p = al->p;
#అయితే_ముగింపు
    తిరిగి al;
}

స్థిర శూన్య tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *తదుపరి;

#ఒకవేళ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#అయితే_ముగింపు
తోక_call:
#ఒకవేళ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ఒకవేళ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->బఫరు, al->nb_peak, al->nb_మొత్తం,
            (al->peak_p - al->బఫరు) * 100.0 / (al->bufend - al->బఫరు));
#అయితే_ముగింపు
    ఒకవేళ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->బఫరు;
        అయితే (p < al->p) {
            tal_శీర్షిక_t *శీర్షిక = (tal_శీర్షిక_t *)p;
            ఒకవేళ (శీర్షిక->పంక్తి_అంకె > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        శీర్షిక->file_name, శీర్షిక->పంక్తి_అంకె, (పూర్ణాంకం)శీర్షిక->కొలత);
            }
            p += శీర్షిక->కొలత + పరిమాణం(tal_శీర్షిక_t);
        }
#ఒకవేళ TAL_DEBUG == 2
        నిష్క్రమించు(2);
#అయితే_ముగింపు
    }
#అయితే_ముగింపు
    తదుపరి = al->తదుపరి;
    tcc_free(al);
    al = తదుపరి;
    ఒకవేళ (al)
        వెళ్ళు తోక_call;
    *pal = al;
}

స్థిర శూన్య tal_free_impl(TinyAlloc **pal, శూన్య *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **శిఖరం = pal;
    tal_శీర్షిక_t *శీర్షిక;

    ఒకవేళ (!p)
        తిరిగి;
    శీర్షిక = (tal_శీర్షిక_t *)p - 1;
#ఒకవేళ TAL_DEBUG
    ఒకవేళ (శీర్షిక->పంక్తి_అంకె < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                శీర్షిక->file_name, (పూర్ణాంకం)-శీర్షిక->పంక్తి_అంకె, (పూర్ణాంకం)శీర్షిక->కొలత);
    } లేకపోతే
        శీర్షిక->పంక్తి_అంకె = -శీర్షిక->పంక్తి_అంకె;
#అయితే_ముగింపు
    al = *pal;
    అయితే ((uint8_t*)p < al->బఫరు || (uint8_t*)p > al->bufend)
        al = *(pal = &al->తదుపరి);
    ఒకవేళ (0 == --al->nb_allocs) {
        *pal = al->తదుపరి;
        ఒకవేళ ((al->bufend - al->బఫరు) > al->కొలత) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } లేకపోతే {
            /* reset and move to front */
            al->p = al->బఫరు;
            al->తదుపరి = *శిఖరం, *శిఖరం = al;
        }
    } లేకపోతే ఒకవేళ ((uint8_t*)p + శీర్షిక->కొలత == al->p) {
        al->p = (uint8_t*)శీర్షిక;
    }
}

స్థిర శూన్య *tal_realloc_impl(TinyAlloc **pal, శూన్య *p, గుర్తులేని కొలత TAL_DEBUG_PARAMS)
{
    tal_శీర్షిక_t *శీర్షిక;
    శూన్య *ret;
    గుర్తులేని adj_కొలత = TAL_ALIGN(కొలత) + పరిమాణం(tal_శీర్షిక_t);
    TinyAlloc *al = *pal;

    ఒకవేళ (p) {
        /* reallpc case */
        అయితే ((uint8_t*)p < al->బఫరు || (uint8_t*)p > al->bufend)
            al = al->తదుపరి;
        శీర్షిక = (tal_శీర్షిక_t *)p - 1;
        ఒకవేళ ((uint8_t*)p + శీర్షిక->కొలత == al->p)
            al->p = (uint8_t*)శీర్షిక; /* maybe reuse */
        ఒకవేళ (al->p + adj_కొలత > al->bufend) {
            ret = tal_realloc(pal, 0, కొలత);
            జ్ఞాపకం_నకలు(ret, p, శీర్షిక->కొలత);
            tal_free(pal, p);
            తిరిగి ret;
        } లేకపోతే ఒకవేళ (al->p != (uint8_t*)శీర్షిక) {
            జ్ఞాపకం_నకలు((tal_శీర్షిక_t*)al->p + 1, p, శీర్షిక->కొలత);
#ఒకవేళ TAL_DEBUG
            శీర్షిక->పంక్తి_అంకె = -శీర్షిక->పంక్తి_అంకె;
#అయితే_ముగింపు
        }
    } లేకపోతే {
        /* new alloc case */
        అయితే (al->p + adj_కొలత > al->bufend) {
            al = al->తదుపరి;
            ఒకవేళ (!al) {
                గుర్తులేని new_కొలత = (*pal)->కొలత;
                ఒకవేళ (adj_కొలత > new_కొలత) {
                    new_కొలత = adj_కొలత;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_కొలత);
                ఆపు;
            }
        }
        al->nb_allocs++;
    }
    శీర్షిక = (tal_శీర్షిక_t *)al->p;
    శీర్షిక->కొలత = adj_కొలత - పరిమాణం(tal_శీర్షిక_t);
    al->p += adj_కొలత;
    ret = శీర్షిక + 1;
#ఒకవేళ  TAL_DEBUG
    {
        పూర్ణాంకం ofs = అక్షరశ్రేణి_పొడవు(sfile) + 1 - పరిమాణం శీర్షిక->file_name;
        strcpy(శీర్షిక->file_name, sfile + (ofs > 0 ? ofs : 0));
        శీర్షిక->పంక్తి_అంకె = sline;
#ఒకవేళ TAL_INFO
        ఒకవేళ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ఒకవేళ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_మొత్తం++;
#అయితే_ముగింపు
    }
#అయితే_ముగింపు
    తిరిగి ret;
}

#అయితే_ముగింపు /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
స్థిర శూన్య cstr_realloc(CString *cstr, పూర్ణాంకం new_కొలత)
{
    పూర్ణాంకం కొలత;

    కొలత = cstr->కొలత_allocated;
    ఒకవేళ (కొలత < 8)
        కొలత = 8; /* no need to allocate a too small first string */
    అయితే (కొలత < new_కొలత)
        కొలత = కొలత * 2;
    cstr->దత్తాంశం = tcc_realloc(cstr->దత్తాంశం, కొలత);
    cstr->కొలత_allocated = కొలత;
}

/* add a byte */
ST_INLN శూన్య cstr_ccat(CString *cstr, పూర్ణాంకం ch)
{
    పూర్ణాంకం కొలత;
    కొలత = cstr->కొలత + 1;
    ఒకవేళ (కొలత > cstr->కొలత_allocated)
        cstr_realloc(cstr, కొలత);
    cstr->దత్తాంశం[కొలత - 1] = ch;
    cstr->కొలత = కొలత;
}

ST_INLN అక్షరం *unicode_గమ్యం_utf8 (అక్షరం *b, uint32_t Uc)
{
    ఒకవేళ (Uc<0x80) *b++=Uc;
    లేకపోతే ఒకవేళ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    లేకపోతే ఒకవేళ (Uc-0xd800u<0x800) వెళ్ళు error;
    లేకపోతే ఒకవేళ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    లేకపోతే ఒకవేళ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    లేకపోతే error: tcc_error("0x%x is not a valid universal character", Uc);
    తిరిగి b;
}

/* add a unicode character expanded into utf8 */
ST_INLN శూన్య cstr_u8cat(CString *cstr, పూర్ణాంకం ch)
{
    అక్షరం buf[4], *e;
    e = unicode_గమ్యం_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC శూన్య cstr_cat(CString *cstr, స్థిరరాశి అక్షరం *str, పూర్ణాంకం len)
{
    పూర్ణాంకం కొలత;
    ఒకవేళ (len <= 0)
        len = అక్షరశ్రేణి_పొడవు(str) + 1 + len;
    కొలత = cstr->కొలత + len;
    ఒకవేళ (కొలత > cstr->కొలత_allocated)
        cstr_realloc(cstr, కొలత);
    memmove(cstr->దత్తాంశం + cstr->కొలత, str, len);
    cstr->కొలత = కొలత;
}

/* add a wide char */
ST_FUNC శూన్య cstr_wccat(CString *cstr, పూర్ణాంకం ch)
{
    పూర్ణాంకం కొలత;
    కొలత = cstr->కొలత + పరిమాణం(nwchar_t);
    ఒకవేళ (కొలత > cstr->కొలత_allocated)
        cstr_realloc(cstr, కొలత);
    *(nwchar_t *)(cstr->దత్తాంశం + కొలత - పరిమాణం(nwchar_t)) = ch;
    cstr->కొలత = కొలత;
}

ST_FUNC శూన్య cstr_new(CString *cstr)
{
    memset(cstr, 0, పరిమాణం(CString));
}

/* free string and reset it to NULL */
ST_FUNC శూన్య cstr_free(CString *cstr)
{
    tcc_free(cstr->దత్తాంశం);
}

/* reset string to empty */
ST_FUNC శూన్య cstr_reset(CString *cstr)
{
    cstr->కొలత = 0;
}

ST_FUNC పూర్ణాంకం cstr_vprintf(CString *cstr, స్థిరరాశి అక్షరం *fmt, va_list ap)
{
    va_list v;
    పూర్ణాంకం len, కొలత = 80;
    కొరకు (;;) {
        కొలత += cstr->కొలత;
        ఒకవేళ (కొలత > cstr->కొలత_allocated)
            cstr_realloc(cstr, కొలత);
        కొలత = cstr->కొలత_allocated - cstr->కొలత;
        va_copy(v, ap);
        len = vsnprintf(cstr->దత్తాంశం + cstr->కొలత, కొలత, fmt, v);
        va_end(v);
        ఒకవేళ (len >= 0 && len < కొలత)
            ఆపు;
        కొలత *= 2;
    }
    cstr->కొలత += len;
    తిరిగి len;
}

ST_FUNC పూర్ణాంకం cstr_printf(CString *cstr, స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap; పూర్ణాంకం len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    తిరిగి len;
}

/* XXX: unicode ? */
స్థిర శూన్య కూడు_char(CString *cstr, పూర్ణాంకం c)
{
    ఒకవేళ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ఒకవేళ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } లేకపోతే {
        cstr_ccat(cstr, '\\');
        ఒకవేళ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } లేకపోతే {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
స్థిర TokenSym *tok_alloc_new(TokenSym **pts, స్థిరరాశి అక్షరం *str, పూర్ణాంకం len)
{
    TokenSym *ts, **ptable;
    పూర్ణాంకం i;

    ఒకవేళ (tok_ident >= SYM_మొదటి_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ఒకవేళ ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(పట్టిక_ident, (i + TOK_ALLOC_INCR) * పరిమాణం(TokenSym *));
        పట్టిక_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, పరిమాణం(TokenSym) + len);
    పట్టిక_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ఖాళీ;
    ts->sym_label = ఖాళీ;
    ts->sym_struct = ఖాళీ;
    ts->sym_identifier = ఖాళీ;
    ts->len = len;
    ts->hash_తదుపరి = ఖాళీ;
    జ్ఞాపకం_నకలు(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    తిరిగి ts;
}

#నిర్వచించు TOK_HASH_INIT 1
#నిర్వచించు TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(స్థిరరాశి అక్షరం *str, పూర్ణాంకం len)
{
    TokenSym *ts, **pts;
    పూర్ణాంకం i;
    గుర్తులేని పూర్ణాంకం h;
    
    h = TOK_HASH_INIT;
    కొరకు(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((గుర్తులేని అక్షరం *)str)[i]);
    h &= (TOK_HASH_కొలత - 1);

    pts = &hash_ident[h];
    కొరకు(;;) {
        ts = *pts;
        ఒకవేళ (!ts)
            ఆపు;
        ఒకవేళ (ts->len == len && !memcmp(ts->str, str, len))
            తిరిగి ts;
        pts = &(ts->hash_తదుపరి);
    }
    తిరిగి tok_alloc_new(pts, str, len);
}

ST_FUNC పూర్ణాంకం tok_alloc_const(స్థిరరాశి అక్షరం *str)
{
    తిరిగి tok_alloc(str, అక్షరశ్రేణి_పొడవు(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC స్థిరరాశి అక్షరం *get_tok_str(పూర్ణాంకం v, CValue *cv)
{
    అక్షరం *p;
    పూర్ణాంకం i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.దత్తాంశం;

    ఎంపిక(v) {
    స్థితి TOK_CINT:
    స్థితి TOK_CUINT:
    స్థితి TOK_CLONG:
    స్థితి TOK_CULONG:
    స్థితి TOK_CLLONG:
    స్థితి TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (గుర్తులేని దీర్ఘ దీర్ఘ)cv->i);
        ఆపు;
    స్థితి TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    స్థితి TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        కూడు_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ఆపు;
    స్థితి TOK_PPNUM:
    స్థితి TOK_PPSTR:
        తిరిగి (అక్షరం*)cv->str.దత్తాంశం;
    స్థితి TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    స్థితి TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ఒకవేళ (v == TOK_STR) {
            len = cv->str.కొలత - 1;
            కొరకు(i=0;i<len;i++)
                కూడు_char(&cstr_buf, ((గుర్తులేని అక్షరం *)cv->str.దత్తాంశం)[i]);
        } లేకపోతే {
            len = (cv->str.కొలత / పరిమాణం(nwchar_t)) - 1;
            కొరకు(i=0;i<len;i++)
                కూడు_char(&cstr_buf, ((nwchar_t *)cv->str.దత్తాంశం)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ఆపు;

    స్థితి TOK_CFLOAT:
        తిరిగి strcpy(p, "<float>");
    స్థితి TOK_CDOUBLE:
        తిరిగి strcpy(p, "<double>");
    స్థితి TOK_CLDOUBLE:
        తిరిగి strcpy(p, "<long double>");
    స్థితి TOK_LINENUM:
        తిరిగి strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    స్థితి TOK_LT:
        v = '<';
        వెళ్ళు addv;
    స్థితి TOK_GT:
        v = '>';
        వెళ్ళు addv;
    స్థితి TOK_DOTS:
        తిరిగి strcpy(p, "...");
    స్థితి TOK_A_SHL:
        తిరిగి strcpy(p, "<<=");
    స్థితి TOK_A_SAR:
        తిరిగి strcpy(p, ">>=");
    స్థితి TOK_EOF:
        తిరిగి strcpy(p, "<eof>");
    స్థితి 0: /* anonymous nameless symbols */
        తిరిగి strcpy(p, "<no name>");
    అప్రమేయ:
        v &= ~(SYM_క్షేత్రం | SYM_STRUCT);
        ఒకవేళ (v < TOK_IDENT) {
            /* search in two bytes table */
            స్థిరరాశి గుర్తులేని అక్షరం *q = tok_two_chars;
            అయితే (*q) {
                ఒకవేళ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    తిరిగి cstr_buf.దత్తాంశం;
                }
                q += 3;
            }
            ఒకవేళ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ఆపు;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } లేకపోతే ఒకవేళ (v < tok_ident) {
            తిరిగి పట్టిక_ident[v - TOK_IDENT]->str;
        } లేకపోతే ఒకవేళ (v >= SYM_మొదటి_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_మొదటి_ANOM);
        } లేకపోతే {
            /* should never happen */
            తిరిగి ఖాళీ;
        }
        ఆపు;
    }
    తిరిగి cstr_buf.దత్తాంశం;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
స్థిర పూర్ణాంకం handle_eob(శూన్య)
{
    BufferedFile *bf = file;
    పూర్ణాంకం len;

    /* only tries to read if really end of buffer */
    ఒకవేళ (bf->buf_ptr >= bf->buf_చివర) {
        ఒకవేళ (bf->fd >= 0) {
#ఒకవేళ defined(PARSE_DEBUG)
            len = 1;
#లేకపోతే
            len = IO_BUF_కొలత;
#అయితే_ముగింపు
            len = పఠ(bf->fd, bf->బఫరు, len);
            ఒకవేళ (len < 0)
                len = 0;
        } లేకపోతే {
            len = 0;
        }
        మొత్తం_బైట్లు += len;
        bf->buf_ptr = bf->బఫరు;
        bf->buf_చివర = bf->బఫరు + len;
        *bf->buf_చివర = CH_EOB;
    }
    ఒకవేళ (bf->buf_ptr < bf->buf_చివర) {
        తిరిగి bf->buf_ptr[0];
    } లేకపోతే {
        bf->buf_ptr = bf->buf_చివర;
        తిరిగి CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
స్థిర పూర్ణాంకం తదుపరి_c(శూన్య)
{
    పూర్ణాంకం ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ఒకవేళ (ch == CH_EOB && file->buf_ptr >= file->buf_చివర)
        ch = handle_eob();
    తిరిగి ch;
}

/* input with '\[\r]\n' handling. */
స్థిర పూర్ణాంకం handle_stray_noerror(పూర్ణాంకం err)
{
    పూర్ణాంకం ch;
    అయితే ((ch = తదుపరి_c()) == '\\') {
        ch = తదుపరి_c();
        ఒకవేళ (ch == '\n') {
    newl:
            file->పంక్తి_అంకె++;
        } లేకపోతే {
            ఒకవేళ (ch == '\r') {
                ch = తదుపరి_c();
                ఒకవేళ (ch == '\n')
                    వెళ్ళు newl;
                *--file->buf_ptr = '\r';
            }
            ఒకవేళ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            తిరిగి *--file->buf_ptr = '\\';
        }
    }
    తిరిగి ch;
}

#నిర్వచించు ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
స్థిర పూర్ణాంకం handle_bs(uint8_t **p)
{
    పూర్ణాంకం c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    తిరిగి c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
స్థిర పూర్ణాంకం handle_stray(uint8_t **p)
{
    పూర్ణాంకం c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    తిరిగి c;
}

/* handle the complicated stray case */
#నిర్వచించు PEEKC(c, p)\
{\
    c = *++p;\
    ఒకవేళ (c == '\\')\
        c = handle_stray(&p); \
}

స్థిర పూర్ణాంకం skip_spaces(శూన్య)
{
    పూర్ణాంకం ch;
    --file->buf_ptr;
    చేయి {
        ch = ninp();
    } అయితే (isidnum_పట్టిక[ch - CH_EOF] & IS_SPC);
    తిరిగి ch;
}

/* single line C++ comments */
స్థిర uint8_t *parse_పంక్తి_comment(uint8_t *p)
{
    పూర్ణాంకం c;
    కొరకు(;;) {
        కొరకు (;;) {
            c = *++p;
    redo:
            ఒకవేళ (c == '\n' || c == '\\')
                ఆపు;
            c = *++p;
            ఒకవేళ (c == '\n' || c == '\\')
                ఆపు;
        }
        ఒకవేళ (c == '\n')
            ఆపు;
        c = handle_bs(&p);
        ఒకవేళ (c == CH_EOF)
            ఆపు;
        ఒకవేళ (c != '\\')
            వెళ్ళు redo;
    }
    తిరిగి p;
}

/* C comments */
స్థిర uint8_t *parse_comment(uint8_t *p)
{
    పూర్ణాంకం c;
    కొరకు(;;) {
        /* fast skip loop */
        కొరకు(;;) {
            c = *++p;
        redo:
            ఒకవేళ (c == '\n' || c == '*' || c == '\\')
                ఆపు;
            c = *++p;
            ఒకవేళ (c == '\n' || c == '*' || c == '\\')
                ఆపు;
        }
        /* now we can handle all the cases */
        ఒకవేళ (c == '\n') {
            file->పంక్తి_అంకె++;
        } లేకపోతే ఒకవేళ (c == '*') {
            చేయి {
                c = *++p;
            } అయితే (c == '*');
            ఒకవేళ (c == '\\')
                c = handle_bs(&p);
            ఒకవేళ (c == '/')
                ఆపు;
            వెళ్ళు check_eof;
        } లేకపోతే {
            c = handle_bs(&p);
        check_eof:
            ఒకవేళ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ఒకవేళ (c != '\\')
                వెళ్ళు redo;
        }
    }
    తిరిగి p + 1;
}

/* parse a string without interpreting escapes */
స్థిర uint8_t *parse_pp_string(uint8_t *p, పూర్ణాంకం sep, CString *str)
{
    పూర్ణాంకం c;
    కొరకు(;;) {
        c = *++p;
    redo:
        ఒకవేళ (c == sep) {
            ఆపు;
        } లేకపోతే ఒకవేళ (c == '\\') {
            c = handle_bs(&p);
            ఒకవేళ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } లేకపోతే ఒకవేళ (c == '\\') {
                ఒకవేళ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ఒకవేళ (c == '\\') {
                    c = handle_bs(&p);
                    ఒకవేళ (c == CH_EOF)
                        వెళ్ళు unterminated_string;
                }
                వెళ్ళు కూడు_char;
            } లేకపోతే {
                వెళ్ళు redo;
            }
        } లేకపోతే ఒకవేళ (c == '\n') {
        కూడు_lf:
            ఒకవేళ (ACCEPT_LF_లోపల_అక్షరశ్రేణులు) {
                file->పంక్తి_అంకె++;
                వెళ్ళు కూడు_char;
            } లేకపోతే ఒకవేళ (str) { /* not skipping */
                వెళ్ళు unterminated_string;
            } లేకపోతే {
                //tcc_warning("missing terminating %c character", sep);
                తిరిగి p;
            }
        } లేకపోతే ఒకవేళ (c == '\r') {
            c = *++p;
            ఒకవేళ (c == '\\')
                c = handle_bs(&p);
            ఒకవేళ (c == '\n')
                వెళ్ళు కూడు_lf;
            ఒకవేళ (c == CH_EOF)
                వెళ్ళు unterminated_string;
            ఒకవేళ (str)
                cstr_ccat(str, '\r');
            వెళ్ళు redo;
        } లేకపోతే {
        కూడు_char:
            ఒకవేళ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    తిరిగి p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
స్థిర శూన్య preprocess_skip(శూన్య)
{
    పూర్ణాంకం a, ప్రారంభం_యొక్క_పంక్తి, c, లోపల_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_ప్రారంభం:
    ప్రారంభం_యొక్క_పంక్తి = 1;
    లోపల_warn_or_error = 0;
    కొరకు(;;) {
        c = *p;
        ఎంపిక(c) {
        స్థితి ' ':
        స్థితి '\t':
        స్థితి '\f':
        స్థితి '\v':
        స్థితి '\r':
            p++;
            కొనసాగు;
        స్థితి '\n':
            file->పంక్తి_అంకె++;
            p++;
            వెళ్ళు redo_ప్రారంభం;
        స్థితి '\\':
            c = handle_bs(&p);
            ఒకవేళ (c == CH_EOF)
                expect("#endif");
            ఒకవేళ (c == '\\')
                ++p;
            కొనసాగు;
        /* skip strings */
        స్థితి '\"':
        స్థితి '\'':
            ఒకవేళ (లోపల_warn_or_error)
                వెళ్ళు _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ఖాళీ);
            ఆపు;
        /* skip comments */
        స్థితి '/':
            ఒకవేళ (లోపల_warn_or_error)
                వెళ్ళు _default;
            ++p;
            c = handle_bs(&p);
            ఒకవేళ (c == '*') {
                p = parse_comment(p);
            } లేకపోతే ఒకవేళ (c == '/') {
                p = parse_పంక్తి_comment(p);
            }
            కొనసాగు;
        స్థితి '#':
            p++;
            ఒకవేళ (ప్రారంభం_యొక్క_పంక్తి) {
                file->buf_ptr = p;
                తదుపరి_nomacro();
                p = file->buf_ptr;
                ఒకవేళ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    వెళ్ళు the_చివర;
                ఒకవేళ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                లేకపోతే ఒకవేళ (tok == TOK_ENDIF)
                    a--;
                లేకపోతే ఒకవేళ( tok == TOK_ERROR || tok == TOK_WARNING)
                    లోపల_warn_or_error = 1;
                లేకపోతే ఒకవేళ (tok == TOK_LINEFEED)
                    వెళ్ళు redo_ప్రారంభం;
                లేకపోతే ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_పంక్తి_comment(p - 1);
            }
#ఒకవేళ !defined(TCC_లక్ష్యం_ARM) && !defined(TCC_లక్ష్యం_ARM64)
            లేకపోతే ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_పంక్తి_comment(p - 1);
#లేకపోతే
            /* ARM/ARM64 assembly uses '#' for constants */
#అయితే_ముగింపు
            ఆపు;
_default:
        అప్రమేయ:
            p++;
            ఆపు;
        }
        ప్రారంభం_యొక్క_పంక్తి = 0;
    }
 the_చివర: ;
    file->buf_ptr = p;
}

#ఒకవేళ 0
/* return the number of additional 'ints' necessary to store the
   token */
స్థిర అంతఃవరుస పూర్ణాంకం tok_కొలత(స్థిరరాశి పూర్ణాంకం *p)
{
    ఎంపిక(*p) {
        /* 4 bytes */
    స్థితి TOK_CINT:
    స్థితి TOK_CUINT:
    స్థితి TOK_CCHAR:
    స్థితి TOK_LCHAR:
    స్థితి TOK_CFLOAT:
    స్థితి TOK_LINENUM:
        తిరిగి 1 + 1;
    స్థితి TOK_STR:
    స్థితి TOK_LSTR:
    స్థితి TOK_PPNUM:
    స్థితి TOK_PPSTR:
        తిరిగి 1 + 1 + (p[1] + 3) / 4;
    స్థితి TOK_CLONG:
    స్థితి TOK_CULONG:
	తిరిగి 1 + LONG_కొలత / 4;
    స్థితి TOK_CDOUBLE:
    స్థితి TOK_CLLONG:
    స్థితి TOK_CULLONG:
        తిరిగి 1 + 2;
    స్థితి TOK_CLDOUBLE:
        తిరిగి 1 + LDOUBLE_పదాలు;
    అప్రమేయ:
        తిరిగి 1 + 0;
    }
}
#అయితే_ముగింపు

/* token string handling */
ST_INLN శూన్య tok_str_new(TokenString *s)
{
    s->str = ఖాళీ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->చివరి_పంక్తి_అంకె = -1;
}

ST_FUNC TokenString *tok_str_alloc(శూన్య)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, పరిమాణం *str);
    tok_str_new(str);
    తిరిగి str;
}

ST_FUNC శూన్య tok_str_free_str(పూర్ణాంకం *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC శూన్య tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC పూర్ణాంకం *tok_str_realloc(TokenString *s, పూర్ణాంకం new_కొలత)
{
    పూర్ణాంకం *str, కొలత;

    కొలత = s->allocated_len;
    ఒకవేళ (కొలత < 16)
        కొలత = 16;
    అయితే (కొలత < new_కొలత)
        కొలత = కొలత * 2;
    ఒకవేళ (కొలత > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, కొలత * పరిమాణం(పూర్ణాంకం));
        s->allocated_len = కొలత;
        s->str = str;
    }
    తిరిగి s->str;
}

ST_FUNC శూన్య tok_str_కూడు(TokenString *s, పూర్ణాంకం t)
{
    పూర్ణాంకం len, *str;

    len = s->len;
    str = s->str;
    ఒకవేళ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC శూన్య begin_macro(TokenString *str, పూర్ణాంకం alloc)
{
    str->alloc = alloc;
    str->prev = macro_దొంతర;
    str->prev_ptr = macro_ptr;
    str->save_పంక్తి_అంకె = file->పంక్తి_అంకె;
    macro_ptr = str->str;
    macro_దొంతర = str;
}

ST_FUNC శూన్య చివర_macro(శూన్య)
{
    TokenString *str = macro_దొంతర;
    macro_దొంతర = str->prev;
    macro_ptr = str->prev_ptr;
    file->పంక్తి_అంకె = str->save_పంక్తి_అంకె;
    ఒకవేళ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } లేకపోతే {
        ఒకవేళ (str->alloc == 2)
            str->str = ఖాళీ; /* don't free */
        tok_str_free(str);
    }
}

స్థిర శూన్య tok_str_add2(TokenString *s, పూర్ణాంకం t, CValue *cv)
{
    పూర్ణాంకం len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ఒకవేళ (len + TOK_MAX_కొలత >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_కొలత + 1);
    str[len++] = t;
    ఎంపిక(t) {
    స్థితి TOK_CINT:
    స్థితి TOK_CUINT:
    స్థితి TOK_CCHAR:
    స్థితి TOK_LCHAR:
    స్థితి TOK_CFLOAT:
    స్థితి TOK_LINENUM:
#ఒకవేళ LONG_కొలత == 4
    స్థితి TOK_CLONG:
    స్థితి TOK_CULONG:
#అయితే_ముగింపు
        str[len++] = cv->tab[0];
        ఆపు;
    స్థితి TOK_PPNUM:
    స్థితి TOK_PPSTR:
    స్థితి TOK_STR:
    స్థితి TOK_LSTR:
        {
            /* Insert the string into the int array. */
            కొలత_t nb_పదాలు =
                1 + (cv->str.కొలత + పరిమాణం(పూర్ణాంకం) - 1) / పరిమాణం(పూర్ణాంకం);
            ఒకవేళ (len + nb_పదాలు >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_పదాలు + 1);
            str[len] = cv->str.కొలత;
            జ్ఞాపకం_నకలు(&str[len + 1], cv->str.దత్తాంశం, cv->str.కొలత);
            len += nb_పదాలు;
        }
        ఆపు;
    స్థితి TOK_CDOUBLE:
    స్థితి TOK_CLLONG:
    స్థితి TOK_CULLONG:
#ఒకవేళ LONG_కొలత == 8
    స్థితి TOK_CLONG:
    స్థితి TOK_CULONG:
#అయితే_ముగింపు
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ఆపు;
    స్థితి TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ఒకవేళ (LDOUBLE_పదాలు >= 3)
        str[len++] = cv->tab[2];
        ఒకవేళ (LDOUBLE_పదాలు >= 4)
        str[len++] = cv->tab[3];
    అప్రమేయ:
        ఆపు;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC శూన్య tok_str_కూడు_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ఒకవేళ (file->పంక్తి_అంకె != s->చివరి_పంక్తి_అంకె) {
        s->చివరి_పంక్తి_అంకె = file->పంక్తి_అంకె;
        cval.i = s->చివరి_పంక్తి_అంకె;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
స్థిర శూన్య tok_str_add2_spc(TokenString *s, పూర్ణాంకం t, CValue *cv)
{
    ఒకవేళ (s->need_spc == 3)
        tok_str_కూడు(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
స్థిర అంతఃవరుస శూన్య tok_get(పూర్ణాంకం *t, స్థిరరాశి పూర్ణాంకం **pp, CValue *cv)
{
    స్థిరరాశి పూర్ణాంకం *p = *pp;
    పూర్ణాంకం n, *tab;

    tab = cv->tab;
    ఎంపిక(*t = *p++) {
#ఒకవేళ LONG_కొలత == 4
    స్థితి TOK_CLONG:
#అయితే_ముగింపు
    స్థితి TOK_CINT:
    స్థితి TOK_CCHAR:
    స్థితి TOK_LCHAR:
    స్థితి TOK_LINENUM:
        cv->i = *p++;
        ఆపు;
#ఒకవేళ LONG_కొలత == 4
    స్థితి TOK_CULONG:
#అయితే_ముగింపు
    స్థితి TOK_CUINT:
        cv->i = (గుర్తులేని)*p++;
        ఆపు;
    స్థితి TOK_CFLOAT:
	tab[0] = *p++;
	ఆపు;
    స్థితి TOK_STR:
    స్థితి TOK_LSTR:
    స్థితి TOK_PPNUM:
    స్థితి TOK_PPSTR:
        cv->str.కొలత = *p++;
        cv->str.దత్తాంశం = (అక్షరం*)p;
        p += (cv->str.కొలత + పరిమాణం(పూర్ణాంకం) - 1) / పరిమాణం(పూర్ణాంకం);
        ఆపు;
    స్థితి TOK_CDOUBLE:
    స్థితి TOK_CLLONG:
    స్థితి TOK_CULLONG:
#ఒకవేళ LONG_కొలత == 8
    స్థితి TOK_CLONG:
    స్థితి TOK_CULONG:
#అయితే_ముగింపు
        n = 2;
        వెళ్ళు copy;
    స్థితి TOK_CLDOUBLE:
        n = LDOUBLE_పదాలు;
    copy:
        చేయి
            *tab++ = *p++;
        అయితే (--n);
        ఆపు;
    అప్రమేయ:
        ఆపు;
    }
    *pp = p;
}

#ఒకవేళ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#లేకపోతే
# define TOK_GET(t,p,c) చేయి { \
    పూర్ణాంకం _t = **(p); \
    ఒకవేళ (TOK_HAS_విలువ(_t)) \
        tok_get(t, p, c); \
    లేకపోతే \
        *(t) = _t, ++*(p); \
    } అయితే (0)
#అయితే_ముగింపు

స్థిర పూర్ణాంకం macro_is_equal(స్థిరరాశి పూర్ణాంకం *a, స్థిరరాశి పూర్ణాంకం *b)
{
    CValue cv;
    పూర్ణాంకం t;

    ఒకవేళ (!a || !b)
        తిరిగి 1;

    అయితే (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ఒకవేళ (strcmp(tokcstr.దత్తాంశం, get_tok_str(t, &cv)))
            తిరిగి 0;
    }
    తిరిగి !(*a || *b);
}

/* defines handling */
ST_INLN శూన్య define_నెట్టు(పూర్ణాంకం v, పూర్ణాంకం macro_type, పూర్ణాంకం *str, Sym *మొదటి_arg)
{
    Sym *s, *o;

    o = define_కనుగొను(v);
    s = sym_push2(&define_దొంతర, v, macro_type, 0);
    s->d = str;
    s->తదుపరి = మొదటి_arg;
    పట్టిక_ident[v - TOK_IDENT]->sym_define = s;

    ఒకవేళ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ఖాళీ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC శూన్య define_undef(Sym *s)
{
    పూర్ణాంకం v = s->v;
    ఒకవేళ (v >= TOK_IDENT && v < tok_ident)
        పట్టిక_ident[v - TOK_IDENT]->sym_define = ఖాళీ;
}

ST_INLN Sym *define_కనుగొను(పూర్ణాంకం v)
{
    v -= TOK_IDENT;
    ఒకవేళ ((గుర్తులేని)v >= (గుర్తులేని)(tok_ident - TOK_IDENT))
        తిరిగి ఖాళీ;
    తిరిగి పట్టిక_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC శూన్య free_నిర్వచిస్తుంది(Sym *b)
{
    అయితే (define_దొంతర != b) {
        Sym *శిఖరం = define_దొంతర;
        define_దొంతర = శిఖరం->prev;
        tok_str_free_str(శిఖరం->d);
        define_undef(శిఖరం);
        sym_free(శిఖరం);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
స్థిర శూన్య maybe_నిరంతరం_test(TCCState *s)
{
    స్థిరరాశి అక్షరం *p;
    ఒకవేళ (s->include_దొంతర_ptr != s->include_దొంతర)
        తిరిగి;
    p = get_tok_str(tok, ఖాళీ);
    ఒకవేళ (0 != memcmp(p, "test_", 5))
        తిరిగి;
    ఒకవేళ (0 != --s->నిరంతరం_test)
        తిరిగి;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_నెట్టు(tok, MACRO_OBJ, ఖాళీ, ఖాళీ);
}

ST_FUNC శూన్య skip_గమ్యం_eol(పూర్ణాంకం warn)
{
    ఒకవేళ (tok == TOK_LINEFEED)
        తిరిగి;
    ఒకవేళ (warn)
        tcc_warning("extra tokens after directive");
    అయితే (macro_దొంతర)
        చివర_macro();
    file->buf_ptr = parse_పంక్తి_comment(file->buf_ptr - 1);
    తదుపరి_nomacro();
}

స్థిర CachedInclude *
శోధన_cached_include(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం కూడు);

స్థిర పూర్ణాంకం parse_include(TCCState *s1, పూర్ణాంకం do_తదుపరి, పూర్ణాంకం test)
{
    పూర్ణాంకం c, i;
    అక్షరం name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ఒకవేళ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.కొలత;
        pstrncpy(name, పరిమాణం name, tokcstr.దత్తాంశం, i);
        తదుపరి_nomacro();
    } లేకపోతే {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        కొరకు (;;) {
            తదుపరి();
            p = name, i = అక్షరశ్రేణి_పొడవు(p) - 1;
            ఒకవేళ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ఆపు;
            ఒకవేళ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, పరిమాణం name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ఒకవేళ (!test)
        skip_గమ్యం_eol(1);

    i = do_తదుపరి ? file->include_తదుపరి_సూచీ : -1;
    కొరకు (;;) {
        ++i;
        ఒకవేళ (i == 0) {
            /* check absolute include path */
            ఒకవేళ (!IS_ABSPATH(name))
                కొనసాగు;
            buf[0] = '\0';
        } లేకపోతే ఒకవేళ (i == 1) {
            /* search in file's dir if "header.h" */
            ఒకవేళ (c != '\"')
                కొనసాగు;
            p = file->true_filename;
            pstrncpy(buf, పరిమాణం buf, p, tcc_basename(p) - p);
        } లేకపోతే {
            పూర్ణాంకం j = i - 2, k = j - s1->nb_include_paths;
            ఒకవేళ (k < 0)
                p = s1->include_paths[j];
            లేకపోతే ఒకవేళ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            లేకపోతే ఒకవేళ (test)
                తిరిగి 0;
            లేకపోతే
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, పరిమాణం buf, p);
            pstrcat(buf, పరిమాణం buf, "/");
        }
        pstrcat(buf, పరిమాణం buf, name);
        e = శోధన_cached_include(s1, buf, 0);
        ఒకవేళ (e && (define_కనుగొను(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#నిర్వచితమైతే INC_DEBUG
            రాయి("%s: skipping cached %s\n", file->filename, buf);
#అయితే_ముగింపు
            ఒకవేళ ((s1->verbose | 1) == 3) /* -vv[v] */
                రాయి("=> %*s%s\n",
                   (పూర్ణాంకం)(s1->include_దొంతర_ptr - s1->include_దొంతర), "", buf);
            తిరిగి 1;
        }
        ఒకవేళ (tcc_open(s1, buf) >= 0)
            ఆపు;
    }

    ఒకవేళ (test) {
        tcc_close();
    } లేకపోతే {
        ఒకవేళ (s1->include_దొంతర_ptr >= s1->include_దొంతర + INCLUDE_దొంతర_కొలత)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_దొంతర_ptr++ = file->prev;
        file->include_తదుపరి_సూచీ = i;
#నిర్వచితమైతే INC_DEBUG
        రాయి("%s: including %s\n", file->prev->filename, file->filename);
#అయితే_ముగింపు
        /* update target deps */
        ఒకవేళ (s1->gen_deps) {
            BufferedFile *bf = file;
            అయితే (i == 1 && (bf = bf->prev))
                i = bf->include_తదుపరి_సూచీ;
            /* skip system include files */
            ఒకవేళ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_కూడు(&s1->లక్ష్యం_deps, &s1->nb_లక్ష్యం_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    తిరిగి 1;
}

/* eval an expression for #if/#elif */
స్థిర పూర్ణాంకం సమాసం_preprocess(TCCState *s1)
{
    పూర్ణాంకం c, t;
    పూర్ణాంకం t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_సమాసం = 1;
    అయితే (1) {
        తదుపరి(); /* do macro subst */
        t = tok;
        ఒకవేళ (tok < TOK_IDENT) {
            ఒకవేళ (tok == TOK_LINEFEED || tok == TOK_EOF)
                ఆపు;
            ఒకవేళ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } లేకపోతే ఒకవేళ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            తదుపరి();
            t = tok;
            ఒకవేళ (t == '(') 
                తదుపరి();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ఒకవేళ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ఒకవేళ (s1->నిరంతరం_test)
                maybe_నిరంతరం_test(s1);
            c = 0;
            ఒకవేళ (define_కనుగొను(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_తదుపరి)
                c = 1;
            ఒకవేళ (t == '(') {
                తదుపరి();
                ఒకవేళ (tok != ')')
                    expect("')'");
            }
            వెళ్ళు c_సంఖ్య;
        } లేకపోతే ఒకవేళ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_తదుపరి) {
            t = tok;
            తదుపరి();
	    ఒకవేళ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ఒకవేళ (tok != ')')
                expect("')'");
            వెళ్ళు c_సంఖ్య;
        } లేకపోతే {
            /* if undefined macro, replace with zero */
            c = 0;
        c_సంఖ్య:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_కూడు_tok(str);
    }
    ఒకవేళ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_కూడు(str, TOK_EOF); /* simulate end of file */
    pp_సమాసం = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    తదుపరి();
    c = సమాసం_const();
    ఒకవేళ (tok != TOK_EOF)
        tcc_error("...");
    pp_సమాసం = 0;
    చివర_macro();
    tok = t; /* restore LF or EOF */
    తిరిగి c != 0;
}

ST_FUNC శూన్య pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_సమాసం, 0));
    macro_ptr = macro_దొంతర->str;
    అయితే (తదుపరి(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC శూన్య parse_define(శూన్య)
{
    Sym *s, *మొదటి, **ps;
    పూర్ణాంకం v, t, varg, is_vaargs, t0;
    పూర్ణాంకం saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ఒకవేళ (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    మొదటి = ఖాళీ;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    తదుపరి_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    ఒకవేళ (tok == '(') {
        పూర్ణాంకం dotid = సమితి_idnum('.', 0);
        తదుపరి_nomacro();
        ps = &మొదటి;
        ఒకవేళ (tok != ')') కొరకు (;;) {
            varg = tok;
            తదుపరి_nomacro();
            is_vaargs = 0;
            ఒకవేళ (varg == TOK_DOTS) {
                varg = TOK_VA_వాదనలు;
                is_vaargs = 1;
            } లేకపోతే ఒకవేళ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                తదుపరి_nomacro();
            }
            ఒకవేళ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_దొంతర, varg | SYM_క్షేత్రం, is_vaargs, 0);
            *ps = s;
            ps = &s->తదుపరి;
            ఒకవేళ (tok == ')')
                ఆపు;
            ఒకవేళ (tok != ',' || is_vaargs)
                వెళ్ళు bad_list;
            తదుపరి_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        తదుపరి_nomacro();
        t = MACRO_FUNC;
        సమితి_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    అయితే (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ఒకవేళ (is_space(tok)) {
            str.need_spc |= 1;
        } లేకపోతే {
            ఒకవేళ (TOK_TWOSHARPS == tok) {
                ఒకవేళ (0 == t0)
                    వెళ్ళు bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        తదుపరి_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_కూడు(&str, 0);
    ఒకవేళ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_నెట్టు(v, t, str.str, మొదటి);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

స్థిర CachedInclude *శోధన_cached_include(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం కూడు)
{
    స్థిరరాశి అక్షరం *s, *basename;
    గుర్తులేని పూర్ణాంకం h;
    CachedInclude *e;
    పూర్ణాంకం c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    అయితే ((c = (గుర్తులేని అక్షరం)*s) != 0) {
#నిర్వచితమైతే _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#లేకపోతే
        h = TOK_HASH_FUNC(h, c);
#అయితే_ముగింపు
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_కొలత - 1);

    i = s1->cached_includes_hash[h];
    కొరకు(;;) {
        ఒకవేళ (i == 0)
            ఆపు;
        e = s1->cached_includes[i - 1];
        ఒకవేళ (0 == PATHCMP(filename, e->filename))
            తిరిగి e;
        ఒకవేళ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            తిరిగి e;
        i = e->hash_తదుపరి;
    }
    ఒకవేళ (!కూడు)
        తిరిగి ఖాళీ;

    e = tcc_malloc(పరిమాణం(CachedInclude) + (len = అక్షరశ్రేణి_పొడవు(filename)));
    జ్ఞాపకం_నకలు(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_కూడు(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_తదుపరి = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#నిర్వచితమైతే INC_DEBUG
    రాయి("adding cached '%s'\n", filename);
#అయితే_ముగింపు
    తిరిగి e;
}

స్థిర పూర్ణాంకం pragma_parse(TCCState *s1)
{
    తదుపరి_nomacro();
    ఒకవేళ (tok == TOK_నెట్టు_macro || tok == TOK_తీయి_macro) {
        పూర్ణాంకం t = tok, v;
        Sym *s;

        ఒకవేళ (తదుపరి(), tok != '(')
            వెళ్ళు pragma_err;
        ఒకవేళ (తదుపరి(), tok != TOK_STR)
            వెళ్ళు pragma_err;
        v = tok_alloc(tokc.str.దత్తాంశం, tokc.str.కొలత - 1)->tok;
        ఒకవేళ (తదుపరి(), tok != ')')
            వెళ్ళు pragma_err;
        ఒకవేళ (t == TOK_నెట్టు_macro) {
            అయితే (ఖాళీ == (s = define_కనుగొను(v)))
                define_నెట్టు(v, 0, ఖాళీ, ఖాళీ);
            s->type.ref = s; /* set push boundary */
        } లేకపోతే {
            కొరకు (s = define_దొంతర; s; s = s->prev)
                ఒకవేళ (s->v == v && s->type.ref == s) {
                    s->type.ref = ఖాళీ;
                    ఆపు;
                }
        }
        ఒకవేళ (s)
            పట్టిక_ident[v - TOK_IDENT]->sym_define = s->d ? s : ఖాళీ;
        లేకపోతే
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } లేకపోతే ఒకవేళ (tok == TOK_once) {
        శోధన_cached_include(s1, file->true_filename, 1)->once = 1;

    } లేకపోతే ఒకవేళ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        తిరిగి 1;

    } లేకపోతే ఒకవేళ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        తదుపరి();
        skip('(');
        ఒకవేళ (tok == TOK_ASM_తీయి) {
            తదుపరి();
            ఒకవేళ (s1->pack_దొంతర_ptr <= s1->pack_దొంతర) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_దొంతర_ptr--;
        } లేకపోతే {
            పూర్ణాంకం val = 0;
            ఒకవేళ (tok != ')') {
                ఒకవేళ (tok == TOK_ASM_నెట్టు) {
                    తదుపరి();
                    ఒకవేళ (s1->pack_దొంతర_ptr >= s1->pack_దొంతర + PACK_దొంతర_కొలత - 1)
                        వెళ్ళు stk_error;
                    val = *s1->pack_దొంతర_ptr++;
                    ఒకవేళ (tok != ',')
                        వెళ్ళు pack_సమితి;
                    తదుపరి();
                }
                ఒకవేళ (tok != TOK_CINT)
                    వెళ్ళు pragma_err;
                val = tokc.i;
                ఒకవేళ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    వెళ్ళు pragma_err;
                తదుపరి();
            }
        pack_సమితి:
            *s1->pack_దొంతర_ptr = val;
        }
        ఒకవేళ (tok != ')')
            వెళ్ళు pragma_err;

    } లేకపోతే ఒకవేళ (tok == TOK_comment) {
        అక్షరం *p; పూర్ణాంకం t;
        తదుపరి();
        skip('(');
        t = tok;
        తదుపరి();
        skip(',');
        ఒకవేళ (tok != TOK_STR)
            వెళ్ళు pragma_err;
        p = tcc_strdup(tokc.str.దత్తాంశం);
        తదుపరి();
        ఒకవేళ (tok != ')')
            వెళ్ళు pragma_err;
        ఒకవేళ (t == TOK_lib) {
            dynarray_కూడు(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } లేకపోతే {
            ఒకవేళ (t == TOK_option)
                tcc_సమితి_options(s1, p);
            tcc_free(p);
        }

    } లేకపోతే {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        తిరిగి 0;
    }
    తదుపరి();
    తిరిగి 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC శూన్య tccpp_putfile(స్థిరరాశి అక్షరం *filename)
{
    అక్షరం buf[1024];
    buf[0] = 0;
    ఒకవేళ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, పరిమాణం buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, పరిమాణం buf, filename);
#నిర్వచితమైతే _WIN32
    normalize_slashes(buf);
#అయితే_ముగింపు
    ఒకవేళ (0 == strcmp(file->filename, buf))
        తిరిగి;
    //printf("new file '%s'\n", buf);
    ఒకవేళ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, పరిమాణం file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC శూన్య preprocess(పూర్ణాంకం is_bof)
{
    TCCState *s1 = tcc_state;
    పూర్ణాంకం c, n, saved_parse_flags;
    అక్షరం buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_అంకె
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    తదుపరి_nomacro();
 redo:
    ఎంపిక(tok) {
    స్థితి TOK_DEFINE:
        pp_debug_tok = tok;
        తదుపరి_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ఆపు;
    స్థితి TOK_UNDEF:
        pp_debug_tok = tok;
        తదుపరి_nomacro();
        pp_debug_symv = tok;
        s = define_కనుగొను(tok);
        /* undefine symbol by putting an invalid name */
        ఒకవేళ (s)
            define_undef(s);
        తదుపరి_nomacro();
        ఆపు;
    స్థితి TOK_INCLUDE:
    స్థితి TOK_INCLUDE_తదుపరి:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        వెళ్ళు the_చివర;
    స్థితి TOK_IFNDEF:
        c = 1;
        వెళ్ళు do_ifdef;
    స్థితి TOK_IF:
        c = సమాసం_preprocess(s1);
        వెళ్ళు do_if;
    స్థితి TOK_IFDEF:
        c = 0;
    do_ifdef:
        తదుపరి_nomacro();
        ఒకవేళ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ఒకవేళ (is_bof) {
            ఒకవేళ (c) {
#నిర్వచితమైతే INC_DEBUG
                రాయి("#ifndef %s\n", get_tok_str(tok, ఖాళీ));
#అయితే_ముగింపు
                file->ifndef_macro = tok;
            }
        }
        ఒకవేళ (define_కనుగొను(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_తదుపరి)
            c ^= 1;
        తదుపరి_nomacro();
    do_if:
        ఒకవేళ (s1->ifdef_దొంతర_ptr >= s1->ifdef_దొంతర + IFDEF_దొంతర_కొలత)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_దొంతర_ptr++ = c;
        వెళ్ళు test_skip;
    స్థితి TOK_ELSE:
        తదుపరి_nomacro();
        ఒకవేళ (s1->ifdef_దొంతర_ptr == s1->ifdef_దొంతర)
            tcc_error("#else without matching #if");
        ఒకవేళ (s1->ifdef_దొంతర_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_దొంతర_ptr[-1] ^= 3);
        వెళ్ళు test_else;
    స్థితి TOK_ELIF:
        ఒకవేళ (s1->ifdef_దొంతర_ptr == s1->ifdef_దొంతర)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_దొంతర_ptr[-1];
        ఒకవేళ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ఒకవేళ (c == 1) {
            skip_గమ్యం_eol(0);
            c = 0;
        } లేకపోతే {
            c = సమాసం_preprocess(s1);
            s1->ifdef_దొంతర_ptr[-1] = c;
        }
    test_else:
        ఒకవేళ (s1->ifdef_దొంతర_ptr == file->ifdef_దొంతర_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ఒకవేళ (!(c & 1)) {
            skip_గమ్యం_eol(1);
            preprocess_skip();
            is_bof = 0;
            వెళ్ళు redo;
        }
        ఆపు;
    స్థితి TOK_ENDIF:
        తదుపరి_nomacro();
        ఒకవేళ (s1->ifdef_దొంతర_ptr <= file->ifdef_దొంతర_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_దొంతర_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ఒకవేళ (file->ifndef_macro &&
            s1->ifdef_దొంతర_ptr == file->ifdef_దొంతర_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ఆపు;

    స్థితి TOK_పంక్తి:
        parse_flags &= ~PARSE_FLAG_TOK_అంకె;
        తదుపరి();
        ఒకవేళ (tok != TOK_PPNUM) {
    పంక్తి_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        వెళ్ళు పంక్తి_అంకె_2;
    స్థితి TOK_PPNUM:
        ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE)
            వెళ్ళు ignore;
        c = 0; /* no error with extra tokens */
    పంక్తి_అంకె_2:
        కొరకు (n = 0, q = tokc.str.దత్తాంశం; *q; ++q) {
            ఒకవేళ (!isnum(*q))
                వెళ్ళు పంక్తి_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        తదుపరి();
        ఒకవేళ (tok != TOK_LINEFEED) {
            ఒకవేళ (tok != TOK_PPSTR || tokc.str.దత్తాంశం[0] != '"')
                వెళ్ళు పంక్తి_err;
            tokc.str.దత్తాంశం[tokc.str.కొలత - 2] = 0;
            tccpp_putfile(tokc.str.దత్తాంశం + 1);
            తదుపరి();
            /* skip optional level number & advance to next line */
            skip_గమ్యం_eol(c);
        }
        ఒకవేళ (file->fd > 0)
            మొత్తం_పంక్తులు += file->పంక్తి_అంకె - n;
        file->పంక్తి_అంకె = n;
        ఆపు;

    స్థితి TOK_ERROR:
    స్థితి TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        అయితే (c != '\n' && c != CH_EOF) {
            ఒకవేళ ((q - buf) < పరిమాణం(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ఒకవేళ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        లేకపోతే
            tcc_warning("#warning %s", buf);
        తదుపరి_nomacro();
        ఆపు;
    }
    స్థితి TOK_PRAGMA:
        ఒకవేళ (!pragma_parse(s1))
            వెళ్ళు ignore;
        ఆపు;
    స్థితి TOK_LINEFEED:
        వెళ్ళు the_చివర;
    అప్రమేయ:
        /* ignore gas line comment in an 'S' file. */
        ఒకవేళ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            వెళ్ళు ignore;
        ఒకవేళ (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            వెళ్ళు ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_గమ్యం_eol(0);
        వెళ్ళు the_చివర;
    }
    skip_గమ్యం_eol(1);
 the_చివర:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
స్థిర శూన్య parse_escape_string(CString *outstr, స్థిరరాశి uint8_t *buf, పూర్ణాంకం is_long)
{
    పూర్ణాంకం c, n, i;
    స్థిరరాశి uint8_t *p;

    p = buf;
    కొరకు(;;) {
        c = *p;
        ఒకవేళ (c == '\0')
            ఆపు;
        ఒకవేళ (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ఎంపిక(c) {
            స్థితి '0': స్థితి '1': స్థితి '2': స్థితి '3':
            స్థితి '4': స్థితి '5': స్థితి '6': స్థితి '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ఒకవేళ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ఒకవేళ (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                వెళ్ళు కూడు_char_nonext;
            స్థితి 'x': i = 0; వెళ్ళు parse_hex_or_ucn;
            స్థితి 'u': i = 4; వెళ్ళు parse_hex_or_ucn;
            స్థితి 'U': i = 8; వెళ్ళు parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                చేయి {
                    c = *p;
                    ఒకవేళ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    లేకపోతే ఒకవేళ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    లేకపోతే ఒకవేళ (isnum(c))
                        c = c - '0';
                    లేకపోతే ఒకవేళ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    లేకపోతే
                        వెళ్ళు కూడు_hex_or_ucn;
                    n = (గుర్తులేని) n * 16 + c;
                    p++;
                } అయితే (--i);
		ఒకవేళ (is_long) {
    కూడు_hex_or_ucn:
                    c = n;
		    వెళ్ళు కూడు_char_nonext;
		}
                cstr_u8cat(outstr, n);
                కొనసాగు;
            స్థితి 'a':
                c = '\a';
                ఆపు;
            స్థితి 'b':
                c = '\b';
                ఆపు;
            స్థితి 'f':
                c = '\f';
                ఆపు;
            స్థితి 'n':
                c = '\n';
                ఆపు;
            స్థితి 'r':
                c = '\r';
                ఆపు;
            స్థితి 't':
                c = '\t';
                ఆపు;
            స్థితి 'v':
                c = '\v';
                ఆపు;
            స్థితి 'e':
                ఒకవేళ (!gnu_ext)
                    వెళ్ళు invalid_escape;
                c = 27;
                ఆపు;
            స్థితి '\'':
            స్థితి '\"':
            స్థితి '\\': 
            స్థితి '?':
                ఆపు;
            అప్రమేయ:
            invalid_escape:
                ఒకవేళ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                లేకపోతే
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ఆపు;
            }
        } లేకపోతే ఒకవేళ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            పూర్ణాంకం cont; /* count of continuation bytes */
            పూర్ణాంకం skip; /* how many bytes should skip when error occurred */
            పూర్ణాంకం i;

            /* decode leading byte */
            ఒకవేళ (c < 0xC2) {
	            skip = 1; వెళ్ళు invalid_utf8_sequence;
            } లేకపోతే ఒకవేళ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } లేకపోతే ఒకవేళ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } లేకపోతే ఒకవేళ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } లేకపోతే {
	            skip = 1; వెళ్ళు invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            కొరకు (i = 1; i <= cont; i++) {
                పూర్ణాంకం l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ఒకవేళ (i == 1) {
                    ఎంపిక (c) {
                    స్థితి 0xE0: l = 0xA0; ఆపు;
                    స్థితి 0xED: h = 0x9F; ఆపు;
                    స్థితి 0xF0: l = 0x90; ఆపు;
                    స్థితి 0xF4: h = 0x8F; ఆపు;
                    }
                }

                ఒకవేళ (p[i] < l || p[i] > h) {
                    skip = i; వెళ్ళు invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            వెళ్ళు కూడు_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            వెళ్ళు కూడు_char_nonext;

        }
        p++;
    కూడు_char_nonext:
        ఒకవేళ (!is_long)
            cstr_ccat(outstr, c);
        లేకపోతే {
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            /* store as UTF-16 */
            ఒకవేళ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } లేకపోతే {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#లేకపోతే
            cstr_wccat(outstr, c);
#అయితే_ముగింపు
        }
    }
    /* add a trailing '\0' */
    ఒకవేళ (!is_long)
        cstr_ccat(outstr, '\0');
    లేకపోతే
        cstr_wccat(outstr, '\0');
}

స్థిర శూన్య parse_string(స్థిరరాశి అక్షరం *s, పూర్ణాంకం len)
{
    uint8_t buf[1000], *p = buf;
    పూర్ణాంకం is_long, sep;

    ఒకవేళ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ఒకవేళ (len >= పరిమాణం buf)
        p = tcc_malloc(len + 1);
    జ్ఞాపకం_నకలు(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ఒకవేళ (p != buf)
        tcc_free(p);

    ఒకవేళ (sep == '\'') {
        పూర్ణాంకం char_కొలత, i, n, c;
        /* XXX: make it portable */
        ఒకవేళ (!is_long)
            tok = TOK_CCHAR, char_కొలత = 1;
        లేకపోతే
            tok = TOK_LCHAR, char_కొలత = పరిమాణం(nwchar_t);
        n = tokcstr.కొలత / char_కొలత - 1;
        ఒకవేళ (n < 1)
            tcc_error("empty character constant");
        ఒకవేళ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        కొరకు (c = i = 0; i < n; ++i) {
            ఒకవేళ (is_long)
                c = ((nwchar_t *)tokcstr.దత్తాంశం)[i];
            లేకపోతే
                c = (c << 8) | ((అక్షరం *)tokcstr.దత్తాంశం)[i];
        }
        tokc.i = c;
    } లేకపోతే {
        tokc.str.కొలత = tokcstr.కొలత;
        tokc.str.దత్తాంశం = tokcstr.దత్తాంశం;
        ఒకవేళ (!is_long)
            tok = TOK_STR;
        లేకపోతే
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#నిర్వచించు BN_కొలత 4

/* bn = (bn << shift) | or_val */
స్థిర పూర్ణాంకం bn_lshift(గుర్తులేని పూర్ణాంకం *bn, పూర్ణాంకం జరుపు, పూర్ణాంకం or_val)
{
    పూర్ణాంకం i;
    గుర్తులేని పూర్ణాంకం v;
    ఒకవేళ (bn[BN_కొలత - 1] >> (32 - జరుపు))
	తిరిగి జరుపు;
    కొరకు(i=0;i<BN_కొలత;i++) {
        v = bn[i];
        bn[i] = (v << జరుపు) | or_val;
        or_val = v >> (32 - జరుపు);
    }
    తిరిగి 0;
}

స్థిర శూన్య bn_zero(గుర్తులేని పూర్ణాంకం *bn)
{
    పూర్ణాంకం i;
    కొరకు(i=0;i<BN_కొలత;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
స్థిర శూన్య parse_సంఖ్య(స్థిరరాశి అక్షరం *p)
{
    పూర్ణాంకం b, t, జరుపు, frac_బిట్లు, s, exp_val, ch;
    అక్షరం *q;
    గుర్తులేని పూర్ణాంకం bn[BN_కొలత];
    దీర్ఘ ద్విగుణ d;

    /*సంఖ్య*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ఒకవేళ (t == '.') {
        వెళ్ళు float_frac_parse;
    } లేకపోతే ఒకవేళ (t == '0') {
        ఒకవేళ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } లేకపోతే ఒకవేళ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    అయితే (1) {
        ఒకవేళ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        లేకపోతే ఒకవేళ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        లేకపోతే ఒకవేళ (isnum(ch))
            t = ch - '0';
        లేకపోతే
            ఆపు;
        ఒకవేళ (t >= b)
            ఆపు;
        ఒకవేళ (q >= token_buf + STRING_MAX_కొలత) {
        అంకె_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ఒకవేళ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ఒకవేళ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_బిట్లు = 0;
            *q = '\0';
            ఒకవేళ (b == 16)
                జరుపు = 4;
            లేకపోతే 
                జరుపు = 1;
            bn_zero(bn);
            q = token_buf;
            అయితే (1) {
                t = *q++;
                ఒకవేళ (t == '\0') {
                    ఆపు;
                } లేకపోతే ఒకవేళ (t >= 'a') {
                    t = t - 'a' + 10;
                } లేకపోతే ఒకవేళ (t >= 'A') {
                    t = t - 'A' + 10;
                } లేకపోతే {
                    t = t - '0';
                }
                frac_బిట్లు -= bn_lshift(bn, జరుపు, t);
            }
            ఒకవేళ (ch == '.') {
                ch = *p++;
                అయితే (1) {
                    t = ch;
                    ఒకవేళ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } లేకపోతే ఒకవేళ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } లేకపోతే ఒకవేళ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } లేకపోతే {
                        ఆపు;
                    }
                    ఒకవేళ (t >= b)
                        tcc_error("invalid digit");
                    frac_బిట్లు -= bn_lshift(bn, జరుపు, t);
                    frac_బిట్లు += జరుపు;
                    ch = *p++;
                }
            }
            ఒకవేళ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ఒకవేళ (ch == '+') {
                ch = *p++;
            } లేకపోతే ఒకవేళ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ఒకవేళ (ch < '0' || ch > '9')
                expect("exponent digits");
            అయితే (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ఒకవేళ (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (దీర్ఘ ద్విగుణ)bn[3] * 79228162514264337593543950336.0L +
	        (దీర్ఘ ద్విగుణ)bn[2] * 18446744073709551616.0L +
	        (దీర్ఘ ద్విగుణ)bn[1] * 4294967296.0L +
	        (దీర్ఘ ద్విగుణ)bn[0];
            d = ldexpl(d, exp_val - frac_బిట్లు);
            t = toup(ch);
            ఒకవేళ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (దశాంశం)d;
            } లేకపోతే ఒకవేళ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } లేకపోతే {
                tok = TOK_CDOUBLE;
                tokc.d = (ద్విగుణ)d;
            }
        } లేకపోతే {
            /* decimal floats */
            ఒకవేళ (ch == '.') {
                ఒకవేళ (q >= token_buf + STRING_MAX_కొలత)
                    వెళ్ళు అంకె_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                అయితే (ch >= '0' && ch <= '9') {
                    ఒకవేళ (q >= token_buf + STRING_MAX_కొలత)
                        వెళ్ళు అంకె_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ఒకవేళ (ch == 'e' || ch == 'E') {
                ఒకవేళ (q >= token_buf + STRING_MAX_కొలత)
                    వెళ్ళు అంకె_too_long;
                *q++ = ch;
                ch = *p++;
                ఒకవేళ (ch == '-' || ch == '+') {
                    ఒకవేళ (q >= token_buf + STRING_MAX_కొలత)
                        వెళ్ళు అంకె_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ఒకవేళ (ch < '0' || ch > '9')
                    expect("exponent digits");
                అయితే (ch >= '0' && ch <= '9') {
                    ఒకవేళ (q >= token_buf + STRING_MAX_కొలత)
                        వెళ్ళు అంకె_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ఒకవేళ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ఖాళీ);
            } లేకపోతే ఒకవేళ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ఖాళీ);
            } లేకపోతే {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ఖాళీ);
            }
        }
    } లేకపోతే {
        గుర్తులేని దీర్ఘ దీర్ఘ n, n1;
        పూర్ణాంకం lcount, ucount, ov = 0;
        స్థిరరాశి అక్షరం *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ఒకవేళ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        అయితే(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ఒకవేళ (t == '\0')
                ఆపు;
            లేకపోతే ఒకవేళ (t >= 'a')
                t = t - 'a' + 10;
            లేకపోతే ఒకవేళ (t >= 'A')
                t = t - 'A' + 10;
            లేకపోతే
                t = t - '0';
            ఒకవేళ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ఒకవేళ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        కొరకు(;;) {
            t = toup(ch);
            ఒకవేళ (t == 'L') {
                ఒకవేళ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ఒకవేళ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } లేకపోతే ఒకవేళ (t == 'U') {
                ఒకవేళ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } లేకపోతే {
                ఆపు;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ఒకవేళ (pp_సమాసం)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ఒకవేళ (ucount == 0 && b == 10) {
            ఒకవేళ (lcount <= (LONG_కొలత == 4)) {
                ఒకవేళ (n >= 0x80000000U)
                    lcount = (LONG_కొలత == 4) + 1;
            }
            ఒకవేళ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } లేకపోతే {
            ఒకవేళ (lcount <= (LONG_కొలత == 4)) {
                ఒకవేళ (n >= 0x100000000ULL)
                    lcount = (LONG_కొలత == 4) + 1;
                లేకపోతే ఒకవేళ (n >= 0x80000000U)
                    ucount = 1;
            }
            ఒకవేళ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ఒకవేళ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ఒకవేళ (lcount) {
            tok = TOK_CLONG;
            ఒకవేళ (lcount == 2)
                tok = TOK_CLLONG;
	}
	ఒకవేళ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ఒకవేళ (ch)
        tcc_error("invalid number");
}


#నిర్వచించు PARSE2(c1, tok1, c2, tok2)              \
    స్థితి c1:                                    \
        PEEKC(c, p);                            \
        ఒకవేళ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } లేకపోతే {                                \
            tok = tok1;                         \
        }                                       \
        ఆపు;

/* return next token without macro substitution */
స్థిర శూన్య తదుపరి_nomacro(శూన్య)
{
    పూర్ణాంకం t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    గుర్తులేని పూర్ణాంకం h;

    p = file->buf_ptr;
 redo_no_ప్రారంభం:
    c = *p;
    ఎంపిక(c) {
    స్థితి ' ':
    స్థితి '\t':
        tok = c;
        p++;
 maybe_space:
        ఒకవేళ (parse_flags & PARSE_FLAG_SPACES)
            వెళ్ళు keep_tok_flags;
        అయితే (isidnum_పట్టిక[*p - CH_EOF] & IS_SPC)
            ++p;
        వెళ్ళు redo_no_ప్రారంభం;
    స్థితి '\f':
    స్థితి '\v':
    స్థితి '\r':
        p++;
        వెళ్ళు redo_no_ప్రారంభం;
    స్థితి '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ఒకవేళ (c == '\\')
            వెళ్ళు parse_simple;
        ఒకవేళ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ఒకవేళ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                వెళ్ళు maybe_newline;
            } లేకపోతే ఒకవేళ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } లేకపోతే ఒకవేళ (s1->ifdef_దొంతర_ptr != file->ifdef_దొంతర_ptr) {
                tcc_error("missing #endif");
            } లేకపోతే ఒకవేళ (s1->include_దొంతర_ptr == s1->include_దొంతర) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } లేకపోతే {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ఒకవేళ (tok_flags & TOK_FLAG_ENDIF) {
#నిర్వచితమైతే INC_DEBUG
                    రాయి("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ఖాళీ));
#అయితే_ముగింపు
                    శోధన_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_దొంతర_ptr--;
                p = file->buf_ptr;
                వెళ్ళు maybe_newline;
            }
        } లేకపోతే {
            వెళ్ళు redo_no_ప్రారంభం;
        }
        ఆపు;

    స్థితి '\n':
        file->పంక్తి_అంకె++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ఒకవేళ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            వెళ్ళు redo_no_ప్రారంభం;
        tok = TOK_LINEFEED;
        వెళ్ళు keep_tok_flags;

    స్థితి '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ఒకవేళ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            వెళ్ళు maybe_newline;
        } లేకపోతే {
            ఒకవేళ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } లేకపోతే {
#ఒకవేళ !defined(TCC_లక్ష్యం_ARM) && !defined(TCC_లక్ష్యం_ARM64)
                ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_పంక్తి_comment(p - 1);
                    వెళ్ళు redo_no_ప్రారంభం;
                } లేకపోతే
#అయితే_ముగింపు
                {
                    tok = '#';
                }
            }
        }
        ఆపు;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    స్థితి '$':
        ఒకవేళ (!(isidnum_పట్టిక['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            వెళ్ళు parse_simple;

    స్థితి 'a': స్థితి 'b': స్థితి 'c': స్థితి 'd':
    స్థితి 'e': స్థితి 'f': స్థితి 'g': స్థితి 'h':
    స్థితి 'i': స్థితి 'j': స్థితి 'k': స్థితి 'l':
    స్థితి 'm': స్థితి 'n': స్థితి 'o': స్థితి 'p':
    స్థితి 'q': స్థితి 'r': స్థితి 's': స్థితి 't':
    స్థితి 'u': స్థితి 'v': స్థితి 'w': స్థితి 'x':
    స్థితి 'y': స్థితి 'z': 
    స్థితి 'A': స్థితి 'B': స్థితి 'C': స్థితి 'D':
    స్థితి 'E': స్థితి 'F': స్థితి 'G': స్థితి 'H':
    స్థితి 'I': స్థితి 'J': స్థితి 'K': 
    స్థితి 'M': స్థితి 'N': స్థితి 'O': స్థితి 'P':
    స్థితి 'Q': స్థితి 'R': స్థితి 'S': స్థితి 'T':
    స్థితి 'U': స్థితి 'V': స్థితి 'W': స్థితి 'X':
    స్థితి 'Y': స్థితి 'Z': 
    స్థితి '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        అయితే (c = *++p, isidnum_పట్టిక[c - CH_EOF] & (IS_ID|IS_అంకె))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ఒకవేళ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_కొలత - 1);
            pts = &hash_ident[h];
            కొరకు(;;) {
                ts = *pts;
                ఒకవేళ (!ts)
                    ఆపు;
                ఒకవేళ (ts->len == len && !memcmp(ts->str, p1, len))
                    వెళ్ళు token_దొరికింది;
                pts = &(ts->hash_తదుపరి);
            }
            ts = tok_alloc_new(pts, (అక్షరం *) p1, len);
        token_దొరికింది: ;
        } లేకపోతే {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (అక్షరం *) p1, len);
            p--;
            PEEKC(c, p);
            అయితే (isidnum_పట్టిక[c - CH_EOF] & (IS_ID|IS_అంకె))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.దత్తాంశం, tokcstr.కొలత);
        }
        tok = ts->tok;
        ఆపు;
    స్థితి 'L':
        t = p[1];
        ఒకవేళ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ఒకవేళ (c == '\'' || c == '\"') {
                is_long = 1;
                వెళ్ళు str_const;
            }
            *--p = c = 'L';
        }
        వెళ్ళు parse_ident_fast;

    స్థితి '0': స్థితి '1': స్థితి '2': స్థితి '3':
    స్థితి '4': స్థితి '5': స్థితి '6': స్థితి '7':
    స్థితి '8': స్థితి '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_అంకె:
        cstr_reset(&tokcstr);
        కొరకు(;;) {
            cstr_ccat(&tokcstr, t);
            ఒకవేళ (!((isidnum_పట్టిక[c - CH_EOF] & (IS_ID|IS_అంకె))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((అక్షరం*)tokcstr.దత్తాంశం)[0] == '0'
                                && toup(((అక్షరం*)tokcstr.దత్తాంశం)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ఆపు;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.కొలత = tokcstr.కొలత;
        tokc.str.దత్తాంశం = tokcstr.దత్తాంశం;
        tok = TOK_PPNUM;
        ఆపు;

    స్థితి '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ఒకవేళ (isnum(c)) {
            t = '.';
            వెళ్ళు parse_అంకె;
        } లేకపోతే ఒకవేళ ((isidnum_పట్టిక['.' - CH_EOF] & IS_ID)
                   && (isidnum_పట్టిక[c - CH_EOF] & (IS_ID|IS_అంకె))) {
            *--p = c = '.';
            వెళ్ళు parse_ident_fast;
        } లేకపోతే ఒకవేళ (c == '.') {
            PEEKC(c, p);
            ఒకవేళ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } లేకపోతే {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } లేకపోతే {
            tok = '.';
        }
        ఆపు;
    స్థితి '\'':
    స్థితి '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ఒకవేళ (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.కొలత = tokcstr.కొలత;
        tokc.str.దత్తాంశం = tokcstr.దత్తాంశం;
        tok = TOK_PPSTR;
        ఆపు;

    స్థితి '<':
        PEEKC(c, p);
        ఒకవేళ (c == '=') {
            p++;
            tok = TOK_LE;
        } లేకపోతే ఒకవేళ (c == '<') {
            PEEKC(c, p);
            ఒకవేళ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } లేకపోతే {
                tok = TOK_SHL;
            }
        } లేకపోతే {
            tok = TOK_LT;
        }
        ఆపు;
    స్థితి '>':
        PEEKC(c, p);
        ఒకవేళ (c == '=') {
            p++;
            tok = TOK_GE;
        } లేకపోతే ఒకవేళ (c == '>') {
            PEEKC(c, p);
            ఒకవేళ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } లేకపోతే {
                tok = TOK_SAR;
            }
        } లేకపోతే {
            tok = TOK_GT;
        }
        ఆపు;
        
    స్థితి '&':
        PEEKC(c, p);
        ఒకవేళ (c == '&') {
            p++;
            tok = TOK_LAND;
        } లేకపోతే ఒకవేళ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } లేకపోతే {
            tok = '&';
        }
        ఆపు;
        
    స్థితి '|':
        PEEKC(c, p);
        ఒకవేళ (c == '|') {
            p++;
            tok = TOK_LOR;
        } లేకపోతే ఒకవేళ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } లేకపోతే {
            tok = '|';
        }
        ఆపు;

    స్థితి '+':
        PEEKC(c, p);
        ఒకవేళ (c == '+') {
            p++;
            tok = TOK_INC;
        } లేకపోతే ఒకవేళ (c == '=') {
            p++;
            tok = TOK_A_కూడు;
        } లేకపోతే {
            tok = '+';
        }
        ఆపు;
        
    స్థితి '-':
        PEEKC(c, p);
        ఒకవేళ (c == '-') {
            p++;
            tok = TOK_DEC;
        } లేకపోతే ఒకవేళ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } లేకపోతే ఒకవేళ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } లేకపోతే {
            tok = '-';
        }
        ఆపు;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    స్థితి '/':
        PEEKC(c, p);
        ఒకవేళ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            వెళ్ళు maybe_space;
        } లేకపోతే ఒకవేళ (c == '/') {
            p = parse_పంక్తి_comment(p);
            tok = ' ';
            వెళ్ళు maybe_space;
        } లేకపోతే ఒకవేళ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } లేకపోతే {
            tok = '/';
        }
        ఆపు;
        
        /* simple tokens */
    స్థితి '@': /* only used in assembler */
#నిర్వచితమైతే TCC_లక్ష్యం_ARM /* comment on arm asm */
        ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_పంక్తి_comment(p);
            వెళ్ళు redo_no_ప్రారంభం;
        }
#అయితే_ముగింపు
    స్థితి '(':
    స్థితి ')':
    స్థితి '[':
    స్థితి ']':
    స్థితి '{':
    స్థితి '}':
    స్థితి ',':
    స్థితి ';':
    స్థితి ':':
    స్థితి '?':
    స్థితి '~':
    parse_simple:
        tok = c;
        p++;
        ఆపు;
    స్థితి 0xEF: /* UTF8 BOM ? */
        ఒకవేళ (p[1] == 0xBB && p[2] == 0xBF && p == file->బఫరు) {
            p += 3;
            వెళ్ళు redo_no_ప్రారంభం;
        }
    అప్రమేయ:
        ఒకవేళ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    వెళ్ళు parse_ident_fast;
        ఒకవేళ (parse_flags & PARSE_FLAG_ASM_FILE)
            వెళ్ళు parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ఆపు;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ఒకవేళ defined(PARSE_DEBUG)
    రాయి("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#అయితే_ముగింపు
}

#నిర్వచితమైతే PP_DEBUG
స్థిర పూర్ణాంకం indent;
స్థిర శూన్య define_print(TCCState *s1, పూర్ణాంకం v);
స్థిర శూన్య pp_print(స్థిరరాశి అక్షరం *సందేశం, పూర్ణాంకం v, స్థిరరాశి పూర్ణాంకం *str)
{
    FILE *fp = tcc_state->ppfp;

    ఒకవేళ (సందేశం[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    లేకపోతే ఒకవేళ (సందేశం[0] == '+')
         ++indent, ++సందేశం;
    లేకపోతే ఒకవేళ (సందేశం[0] == '-')
        --indent, ++సందేశం;

    fprintf(fp, "%*s", indent, "");
    ఒకవేళ (సందేశం[0] == '#') {
        define_print(tcc_state, v);
    } లేకపోతే {
        tok_print(str, v ? "%s %s" : "%s", సందేశం, get_tok_str(v, 0));
    }
}
#నిర్వచించు PP_PRINT(x) pp_print x
#లేకపోతే
#నిర్వచించు PP_PRINT(x)
#అయితే_ముగింపు

స్థిర పూర్ణాంకం macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    స్థిరరాశి పూర్ణాంకం *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
స్థిర పూర్ణాంకం *macro_arg_subst(Sym **nested_list, స్థిరరాశి పూర్ణాంకం *macro_str, Sym *వాదనలు)
{
    పూర్ణాంకం t, t0, t1, t2, n;
    స్థిరరాశి పూర్ణాంకం *st;
    Sym *s;
    CValue cval;
    TokenString str;

#నిర్వచితమైతే PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    కొరకు (s = వాదనలు, n = 0; s; s = s->prev, ++n);
    అయితే (n--) {
        కొరకు (s = వాదనలు, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#అయితే_ముగింపు

    tok_str_new(&str);
    t0 = t1 = 0;
    అయితే(1) {
        TOK_GET(&t, &macro_str, &cval);
        ఒకవేళ (!t)
            ఆపు;
        ఒకవేళ (t == '#') {
            /* stringize */
            చేయి t = *macro_str++; అయితే (t == ' ');
            s = sym_find2(వాదనలు, t);
            ఒకవేళ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                అయితే (*st != TOK_EOF) {
                    స్థిరరాశి అక్షరం *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    అయితే (*s) {
                        ఒకవేళ (t == TOK_PPSTR && *s != '\'')
                            కూడు_char(&tokcstr, *s);
                        లేకపోతే
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.కొలత = tokcstr.కొలత;
                cval.str.దత్తాంశం = tokcstr.దత్తాంశం;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
            } లేకపోతే ఒకవేళ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_కూడు(&str, '#');
#అయితే_ముగింపు
            } లేకపోతే {
                expect("macro parameter after '#'");
            }
        } లేకపోతే ఒకవేళ (t >= TOK_IDENT) {
            s = sym_find2(వాదనలు, t);
            ఒకవేళ (s) {
                st = s->d;
                n = 0;
                అయితే ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ఒకవేళ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ఒకవేళ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        పూర్ణాంకం c = str.str[str.len - 1];
                        అయితే (str.str[--str.len] != ',')
                            ;
                        ఒకవేళ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } లేకపోతే {
                            /* suppress '##' and add variable */
                            str.len++;
                            ఒకవేళ (c == ' ')
                                str.str[str.len++] = c;
                            వెళ్ళు కూడు_var;
                        }
                    } లేకపోతే {
                        ఒకవేళ (*st == TOK_EOF)
                            tok_str_కూడు(&str, TOK_PLCHLDR);
                    }
                } లేకపోతే {
            కూడు_var:
		    ఒకవేళ (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_కూడు(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                అయితే (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } లేకపోతే {
                tok_str_కూడు(&str, t);
            }
        } లేకపోతే {
            tok_str_add2(&str, t, &cval);
        }
        ఒకవేళ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_కూడు(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    తిరిగి str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
స్థిర అంతఃవరుస పూర్ణాంకం *macro_twosharps(స్థిరరాశి పూర్ణాంకం *ptr0)
{
    పూర్ణాంకం t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    స్థిరరాశి పూర్ణాంకం *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    కొరకు (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ఒకవేళ (t1 == 0)
            ఆపు;
        కొరకు (;;) {
            n = 0;
            అయితే ((t2 = ptr[n]) == ' ')
                ++n;
            ఒకవేళ (t2 != TOK_PPJOIN)
                ఆపు;
            ptr += n;
            అయితే ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ఒకవేళ (t2 == TOK_PLCHLDR)
                కొనసాగు;
            ఒకవేళ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ఒకవేళ (tokcstr.కొలత) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.కొలత);
            జ్ఞాపకం_నకలు(file->బఫరు, tokcstr.దత్తాంశం, tokcstr.కొలత);
            tok_flags = 0; /* don't interpret '#' */
            కొరకు (n = 0;;n = l) {
                తదుపరి_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ఒకవేళ (*file->buf_ptr == 0)
                    ఆపు;
                tok_str_కూడు(&macro_str1, ' ');
                l = file->buf_ptr - file->బఫరు;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->బఫరు + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ఒకవేళ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_కూడు(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    తిరిగి macro_str1.str;
}

స్థిర పూర్ణాంకం peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    పూర్ణాంకం c;
    కొరకు (;;) {
        PEEKC(c, p);
        ఎంపిక (c) {
        స్థితి '/':
            PEEKC(c, p);
            ఒకవేళ (c == '*')
                p = parse_comment(p);
            లేకపోతే ఒకవేళ (c == '/')
                p = parse_పంక్తి_comment(p);
            లేకపోతే {
                c = *--p = '/';
                వెళ్ళు leave;
            }
            --p, c = ' ';
            ఆపు;
        స్థితి ' ': స్థితి '\t':
            ఆపు;
        స్థితి '\f': స్థితి '\v': స్థితి '\r':
            కొనసాగు;
        స్థితి '\n':
            file->పంక్తి_అంకె++, tok_flags |= TOK_FLAG_BOL;
            ఆపు;
        అప్రమేయ: leave:
            file->buf_ptr = p;
            తిరిగి c;
        }
        ఒకవేళ (ws_str)
            tok_str_కూడు(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
స్థిర పూర్ణాంకం తదుపరి_argstream(Sym **nested_list, TokenString *ws_str)
{
    పూర్ణాంకం t;
    Sym *sa;

    అయితే (macro_ptr) {
        స్థిరరాశి పూర్ణాంకం *m = macro_ptr;
        అయితే ((t = *m) != 0) {
            ఒకవేళ (ws_str) {
                ఒకవేళ (t != ' ')
                    తిరిగి t;
                ++m;
            } లేకపోతే {
                TOK_GET(&tok, &macro_ptr, &tokc);
                తిరిగి tok;
            }
        }
        చివర_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ఒకవేళ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ఒకవేళ (ws_str) {
        తిరిగి peek_file(ws_str);
    } లేకపోతే {
        తదుపరి_nomacro();
        ఒకవేళ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        తిరిగి tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
స్థిర పూర్ణాంకం macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    పూర్ణాంకం t;
    పూర్ణాంకం v = s->v;

    PP_PRINT(("#", v, s->d));
    ఒకవేళ (s->d) {
        పూర్ణాంకం *mstr = s->d;
        పూర్ణాంకం *jstr;
        Sym *sa;
        పూర్ణాంకం ret;

        ఒకవేళ (s->type.t & MACRO_FUNC) {
            పూర్ణాంకం saved_parse_flags = parse_flags;
            TokenString str;
            పూర్ణాంకం parlevel, i;
            Sym *sa1, *వాదనలు;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = తదుపరి_argstream(nested_list, &str);
            ఒకవేళ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ఒకవేళ (parse_flags & PARSE_FLAG_SPACES)
                    కొరకు (i = 0; i < str.len; i++)
                        tok_str_కూడు(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                తిరిగి 0;
            } లేకపోతే {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            వాదనలు = ఖాళీ;
            sa = s->తదుపరి;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            కొరకు(;;) {
                చేయి {
                    t = తదుపరి_argstream(nested_list, ఖాళీ);
                } అయితే (t == ' ' || --i);

                ఒకవేళ (!sa) {
                    ఒకవేళ (t == ')') /* handle '()' case */
                        ఆపు;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            ఖాళీలు_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                అయితే (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ఒకవేళ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ఒకవేళ (t == '(')
                        parlevel++;
                    ఒకవేళ (t == ')')
                        parlevel--;
                    ఒకవేళ (t == ' ')
                        str.need_spc |= 1;
                    లేకపోతే
                        tok_str_add2_spc(&str, t, &tokc);
                    t = తదుపరి_argstream(nested_list, ఖాళీ);
                }
                tok_str_కూడు(&str, TOK_EOF);
                sa1 = sym_push2(&వాదనలు, sa->v & ~SYM_క్షేత్రం, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->తదుపరి;
                ఒకవేళ (t == ')') {
                    ఒకవేళ (!sa)
                        ఆపు;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ఒకవేళ (sa->type.t && gnu_ext)
                        వెళ్ళు ఖాళీలు_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, వాదనలు);
            /* free memory */
            sa = వాదనలు;
            అయితే (sa) {
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
        ఒకవేళ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ఒకవేళ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ఒకవేళ (jstr != mstr)
            tok_str_free_str(jstr);
        ఒకవేళ (mstr != s->d)
            tok_str_free_str(mstr);
        తిరిగి ret;

    } లేకపోతే {
        CValue cval;
        అక్షరం buf[32], *cstrval = buf;

        /* special macros */
        ఒకవేళ (v == TOK_పంక్తి_2 || v == TOK___COUNTER__) {
            t = v == TOK_పంక్తి_2 ? file->పంక్తి_అంకె : pp_counter++;
            snprintf(buf, పరిమాణం(buf), "%d", t);
            t = TOK_PPNUM;
            వెళ్ళు కూడు_cstr1;

        } లేకపోతే ఒకవేళ (v == TOK___FILE__) {
            cstrval = file->filename;
            వెళ్ళు కూడు_cstr;

        } లేకపోతే ఒకవేళ (v == TOK___DATE__ || v == TOK_సమయం) {
            time_t ti;
            నిర్మాణం tm *tm;
            సమయం(&ti);
            tm = localtime(&ti);
            ఒకవేళ (v == TOK___DATE__) {
                స్థిర అక్షరం స్థిరరాశి ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, పరిమాణం(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } లేకపోతే {
                snprintf(buf, పరిమాణం(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        కూడు_cstr:
            t = TOK_STR;
        కూడు_cstr1:
            cval.str.కొలత = అక్షరశ్రేణి_పొడవు(cstrval) + 1;
            cval.str.దత్తాంశం = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        తిరిగి 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
స్థిర పూర్ణాంకం macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    స్థిరరాశి పూర్ణాంకం *macro_str
    )
{
    Sym *s;
    పూర్ణాంకం t, nosubst = 0;
    CValue cval;
    TokenString *str;

#నిర్వచితమైతే PP_DEBUG
    పూర్ణాంకం tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#అయితే_ముగింపు

    అయితే (1) {
        TOK_GET(&t, &macro_str, &cval);
        ఒకవేళ (t == 0 || t == TOK_EOF)
            ఆపు;
        ఒకవేళ (t >= TOK_IDENT) {
            s = define_కనుగొను(t);
            ఒకవేళ (s == ఖాళీ || nosubst)
                వెళ్ళు no_subst;
            /* if nested substitution, do nothing */
            ఒకవేళ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_క్షేత్రం;
                వెళ్ళు no_subst;
            }
            str = tok_str_alloc();
            str->str = (పూర్ణాంకం*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ఒకవేళ (macro_దొంతర != str) {
                /* already finished by reading function macro arguments */
                ఆపు;
            }
            macro_str = macro_ptr;
            చివర_macro ();
        } లేకపోతే ఒకవేళ (t == ' ') {
            ఒకవేళ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } లేకపోతే {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ఒకవేళ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ఒకవేళ (t == TOK_DEFINED && pp_సమాసం)
                nosubst = 1;
        }
    }

#నిర్వచితమైతే PP_DEBUG
    tok_str_కూడు(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#అయితే_ముగింపు
    తిరిగి nosubst;
}

/* return next token with macro substitution */
ST_FUNC శూన్య తదుపరి(శూన్య)
{
    పూర్ణాంకం t;
    అయితే (macro_ptr) {
redo:
        t = *macro_ptr;
        ఒకవేళ (TOK_HAS_విలువ(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ఒకవేళ (t == TOK_LINENUM) {
                file->పంక్తి_అంకె = tokc.i;
                వెళ్ళు redo;
            }
            వెళ్ళు convert;
        } లేకపోతే ఒకవేళ (t == 0) {
            /* end of macro or unget token string */
            చివర_macro();
            కొనసాగు;
        } లేకపోతే ఒకవేళ (t == TOK_EOF) {
            /* do nothing */
        } లేకపోతే {
            ++macro_ptr;
            t &= ~SYM_క్షేత్రం; /* remove 'nosubst' marker */
            ఒకవేళ (t == '\\') {
                ఒకవేళ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        తిరిగి;
    }

    తదుపరి_nomacro();
    t = tok;
    ఒకవేళ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_కనుగొను(t);
        ఒకవేళ (s) {
            Sym *nested_list = ఖాళీ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_కూడు(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            వెళ్ళు redo;
        }
        తిరిగి;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ఒకవేళ (t == TOK_PPNUM) {
        ఒకవేళ  (parse_flags & PARSE_FLAG_TOK_అంకె)
            parse_సంఖ్య(tokc.str.దత్తాంశం);
    } లేకపోతే ఒకవేళ (t == TOK_PPSTR) {
        ఒకవేళ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.దత్తాంశం, tokc.str.కొలత - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN శూన్య unget_tok(పూర్ణాంకం చివరి_tok)
{
    TokenString *str = &unget_buf;
    పూర్ణాంకం alloc = 0;
    ఒకవేళ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ఒకవేళ (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_కూడు(str, 0);
    begin_macro(str, alloc);
    tok = చివరి_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

స్థిర స్థిరరాశి అక్షరం * స్థిరరాశి లక్ష్యం_os_defs =
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    "_WIN32\0"
# ఒకవేళ PTR_కొలత == 8
    "_WIN64\0"
# endif
#లేకపోతే
# ఒకవేళ defined TCC_లక్ష్యం_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# లేకపోతే
    "__linux__\0"
    "__linux\0"
#  ఒకవేళ TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#అయితే_ముగింపు
    ;

స్థిర శూన్య putdef(CString *cs, స్థిరరాశి అక్షరం *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

స్థిర శూన్య putdefs(CString *cs, స్థిరరాశి అక్షరం *p)
{
    అయితే (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

స్థిర శూన్య tcc_predefs(TCCState *s1, CString *cs, పూర్ణాంకం is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_సంస్కరణ[4]);
    putdefs(cs, లక్ష్యం_machine_defs);
    putdefs(cs, లక్ష్యం_os_defs);

#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    ఒకవేళ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#అయితే_ముగింపు
    ఒకవేళ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ఒకవేళ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం)
      putdef(cs, "__TCC_RUN__");
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    ఒకవేళ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#అయితే_ముగింపు
    ఒకవేళ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ఒకవేళ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ఒకవేళ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ఒకవేళ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_కొలత);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_కొలత);
    ఒకవేళ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ఒకవేళ CONFIG_TCC_PREDEFS
        #అన్తర్భావ "tccdefs_.h" /* include as strings */
#లేకపోతే
        "#include <tccdefs.h>\n" /* load at runtime */
#అయితే_ముగింపు
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC శూన్య preprocess_ప్రారంభం(TCCState *s1, పూర్ణాంకం filetype)
{
    పూర్ణాంకం is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_దొంతర_ptr = s1->include_దొంతర;
    s1->ifdef_దొంతర_ptr = s1->ifdef_దొంతర;
    file->ifdef_దొంతర_ptr = s1->ifdef_దొంతర_ptr;
    pp_సమాసం = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_దొంతర[0] = 0;
    s1->pack_దొంతర_ptr = s1->pack_దొంతర;

    సమితి_idnum('$', s1->dollars_లోపల_identifiers ? IS_ID : 0);
    సమితి_idnum('.', is_asm ? IS_ID : 0);

    ఒకవేళ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ఒకవేళ (s1->cmdline_defs.కొలత)
          cstr_cat(&cstr, s1->cmdline_defs.దత్తాంశం, s1->cmdline_defs.కొలత);
        ఒకవేళ (s1->cmdline_incl.కొలత)
          cstr_cat(&cstr, s1->cmdline_incl.దత్తాంశం, s1->cmdline_incl.కొలత);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_దొంతర_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.కొలత);
        జ్ఞాపకం_నకలు(file->బఫరు, cstr.దత్తాంశం, cstr.కొలత);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC శూన్య preprocess_చివర(TCCState *s1)
{
    అయితే (macro_దొంతర)
        చివర_macro();
    macro_ptr = ఖాళీ;
    అయితే (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC పూర్ణాంకం సమితి_idnum(పూర్ణాంకం c, పూర్ణాంకం val)
{
    పూర్ణాంకం prev = isidnum_పట్టిక[c - CH_EOF];
    isidnum_పట్టిక[c - CH_EOF] = val;
    తిరిగి prev;
}

ST_FUNC శూన్య tccpp_new(TCCState *s)
{
    పూర్ణాంకం i, c;
    స్థిరరాశి అక్షరం *p, *r;

    /* init isid table */
    కొరకు(i = CH_EOF; i<128; i++)
        సమితి_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_అంకె
            : 0);

    కొరకు(i = 128; i<256; i++)
        సమితి_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_కొలత);
    tal_new(&tokstr_alloc, TOKSTR_TAL_కొలత);

    memset(hash_ident, 0, TOK_HASH_కొలత * పరిమాణం(TokenSym *));
    memset(s->cached_includes_hash, 0, పరిమాణం s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_కొలత);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_కొలత);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_కొలత);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    అయితే (*p) {
        r = p;
        కొరకు(;;) {
            c = *r++;
            ఒకవేళ (c == '\0')
                ఆపు;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_నెట్టు(TOK_పంక్తి_2, MACRO_OBJ, ఖాళీ, ఖాళీ);
    define_నెట్టు(TOK___FILE__, MACRO_OBJ, ఖాళీ, ఖాళీ);
    define_నెట్టు(TOK___DATE__, MACRO_OBJ, ఖాళీ, ఖాళీ);
    define_నెట్టు(TOK_సమయం, MACRO_OBJ, ఖాళీ, ఖాళీ);
    define_నెట్టు(TOK___COUNTER__, MACRO_OBJ, ఖాళీ, ఖాళీ);
}

ST_FUNC శూన్య tccpp_delete(TCCState *s)
{
    పూర్ణాంకం i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ఒకవేళ (n > మొత్తం_idents)
        మొత్తం_idents = n;
    కొరకు (i = n; --i >= 0;)
        tal_free(&toksym_alloc, పట్టిక_ident[i]);
    tcc_free(పట్టిక_ident);
    పట్టిక_ident = ఖాళీ;

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

స్థిర పూర్ణాంకం pp_need_space(పూర్ణాంకం a, పూర్ణాంకం b);

స్థిర శూన్య tok_print(స్థిరరాశి పూర్ణాంకం *str, స్థిరరాశి అక్షరం *సందేశం, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    పూర్ణాంకం t, t0, s;
    CValue cval;

    va_start(ap, సందేశం);
    vfprintf(fp, సందేశం, ap);
    va_end(ap);

    s = t0 = 0;
    అయితే (str) {
	TOK_GET(&t, &str, &cval);
	ఒకవేళ (t == 0 || t == TOK_EOF)
	    ఆపు;
        ఒకవేళ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

స్థిర శూన్య pp_పంక్తి(TCCState *s1, BufferedFile *f, పూర్ణాంకం level)
{
    పూర్ణాంకం d = f->పంక్తి_అంకె - f->పంక్తి_ref;

    ఒకవేళ (s1->dflag & 4)
	తిరిగి;

    ఒకవేళ (s1->Pflag == పంక్తి_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } లేకపోతే ఒకవేళ (level == 0 && f->పంక్తి_ref && d < 8) {
	అయితే (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } లేకపోతే ఒకవేళ (s1->Pflag == పంక్తి_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->పంక్తి_అంకె, f->filename);
    } లేకపోతే {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->పంక్తి_అంకె, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->పంక్తి_ref = f->పంక్తి_అంకె;
}

స్థిర శూన్య define_print(TCCState *s1, పూర్ణాంకం v)
{
    FILE *fp;
    Sym *s;

    s = define_కనుగొను(v);
    ఒకవేళ (ఖాళీ == s || ఖాళీ == s->d)
        తిరిగి;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ఖాళీ));
    ఒకవేళ (s->type.t & MACRO_FUNC) {
        Sym *a = s->తదుపరి;
        fprintf(fp,"(");
        ఒకవేళ (a)
            కొరకు (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ఖాళీ));
                ఒకవేళ (!(a = a->తదుపరి))
                    ఆపు;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

స్థిర శూన్య pp_debug_నిర్వచిస్తుంది(TCCState *s1)
{
    పూర్ణాంకం v, t;
    స్థిరరాశి అక్షరం *vs;
    FILE *fp;

    t = pp_debug_tok;
    ఒకవేళ (t == 0)
        తిరిగి;

    file->పంక్తి_అంకె--;
    pp_పంక్తి(s1, file, 0);
    file->పంక్తి_ref = ++file->పంక్తి_అంకె;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ఖాళీ);
    ఒకవేళ (t == TOK_DEFINE) {
        define_print(s1, v);
    } లేకపోతే ఒకవేళ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } లేకపోతే ఒకవేళ (t == TOK_నెట్టు_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } లేకపోతే ఒకవేళ (t == TOK_తీయి_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
స్థిర పూర్ణాంకం pp_need_space(పూర్ణాంకం a, పూర్ణాంకం b)
{
    తిరిగి 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
స్థిర పూర్ణాంకం pp_check_he0xE(పూర్ణాంకం t, స్థిరరాశి అక్షరం *p)
{
    ఒకవేళ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        తిరిగి 'E';
    తిరిగి t;
}

/* Preprocess the current file */
ST_FUNC పూర్ణాంకం tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    పూర్ణాంకం token_చూసిన, spcs, level;
    స్థిరరాశి అక్షరం *p;
    అక్షరం white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ఒకవేళ (s1->Pflag == పంక్తి_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_అంకె, s1->Pflag = 1;

    ఒకవేళ (s1->do_bench) {
	/* for PP benchmarks */
	చేయి తదుపరి(); అయితే (tok != TOK_EOF);
	తిరిగి 0;
    }

    token_చూసిన = TOK_LINEFEED, spcs = 0, level = 0;
    ఒకవేళ (file->prev)
        pp_పంక్తి(s1, file->prev, level++);
    pp_పంక్తి(s1, file, level);

    కొరకు (;;) {
        iptr = s1->include_దొంతర_ptr;
        తదుపరి();
        ఒకవేళ (tok == TOK_EOF)
            ఆపు;

        level = s1->include_దొంతర_ptr - iptr;
        ఒకవేళ (level) {
            ఒకవేళ (level > 0)
                pp_పంక్తి(s1, *iptr, 0);
            pp_పంక్తి(s1, file, level);
        }
        ఒకవేళ (s1->dflag & 7) {
            pp_debug_నిర్వచిస్తుంది(s1);
            ఒకవేళ (s1->dflag & 4)
                కొనసాగు;
        }

        ఒకవేళ (is_space(tok)) {
            ఒకవేళ (spcs < పరిమాణం white - 1)
                white[spcs++] = tok;
            కొనసాగు;
        } లేకపోతే ఒకవేళ (tok == TOK_LINEFEED) {
            spcs = 0;
            ఒకవేళ (token_చూసిన == TOK_LINEFEED)
                కొనసాగు;
            ++file->పంక్తి_ref;
        } లేకపోతే ఒకవేళ (token_చూసిన == TOK_LINEFEED) {
            pp_పంక్తి(s1, file, 0);
        } లేకపోతే ఒకవేళ (spcs == 0 && pp_need_space(token_చూసిన, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_చూసిన = pp_check_he0xE(tok, p);
    }
    తిరిగి 0;
}

/* ------------------------------------------------------------------------- */
