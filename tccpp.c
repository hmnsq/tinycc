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

#परिभाषय USING_GLOBALS
#अन्तर्भाव "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#परिभाषय ACCEPT_LF_अन्तर्_वाक्यानि 0

/********************************************************/
/* global variables */

ST_दत्त पूर्णाङ्क tok_flags;
ST_दत्त पूर्णाङ्क parse_flags;

ST_दत्त संरचना BufferedFile *file;
ST_दत्त पूर्णाङ्क tok;
ST_दत्त CValue tokc;
ST_दत्त ध्रुव पूर्णाङ्क *macro_ptr;
ST_दत्त CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_दत्त पूर्णाङ्क tok_ident;
ST_दत्त TokenSym **सारणी_ident;
ST_दत्त पूर्णाङ्क pp_व्यञ्जकम्;

/* ------------------------------------------------------------------------- */

स्थिर TokenSym *hash_ident[TOK_HASH_आकार];
स्थिर वर्ण token_buf[STRING_MAX_आकार + 1];
स्थिर CString cstr_buf;
स्थिर TokenString tokstr_buf;
स्थिर TokenString unget_buf;
स्थिर अचिह्नित वर्ण isidnum_सारणी[256 - CH_EOF];
स्थिर पूर्णाङ्क pp_debug_tok, pp_debug_symv;
स्थिर पूर्णाङ्क pp_गणक;
स्थिर शून्य tok_print(ध्रुव पूर्णाङ्क *str, ध्रुव वर्ण *सन्देशः, ...);
स्थिर शून्य अग्र_nomacro(शून्य);
स्थिर शून्य parse_सङ्ख्या(ध्रुव वर्ण *p);
स्थिर शून्य parse_string(ध्रुव वर्ण *p, पूर्णाङ्क len);

स्थिर संरचना TinyAlloc *toksym_alloc;
स्थिर संरचना TinyAlloc *tokstr_alloc;

स्थिर TokenString *macro_राशिः;

स्थिर ध्रुव वर्ण tcc_keywords[] = 
#परिभाषय DEF(id, str) str "\0"
#अन्तर्भाव "tcctok.h"
#अपरिभाषय DEF
;

/* WARNING: the content of this string encodes token numbers */
स्थिर ध्रुव अचिह्नित वर्ण tok_two_chars[] =
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
    '+','=', TOK_A_सङ्कलय,
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

ST_FUNC शून्य skip(पूर्णाङ्क c)
{
    यदि (tok != c) {
        वर्ण tmp[40];
        pstrcpy(tmp, परिमाण tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    अग्र();
}

ST_FUNC शून्य expect(ध्रुव वर्ण *सन्देशः)
{
    tcc_error("%s expected", सन्देशः);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#परिभाषय USE_TAL

#यदि_अपरिभाषितम् USE_TAL /* may cause memory leaks after errors */
#परिभाषय tal_free(al, p) tcc_free(p)
#परिभाषय tal_realloc(al, p, आकार) tcc_realloc(p, आकार)
#परिभाषय tal_new(a,b)
#परिभाषय tal_delete(a)
#अन्यथा
#यदि !defined(MEM_DEBUG)
#परिभाषय tal_free(al, p) tal_free_impl(al, p)
#परिभाषय tal_realloc(al, p, आकार) tal_realloc_impl(al, p, आकार)
#परिभाषय TAL_DEBUG_PARAMS
#अन्यथा
#परिभाषय TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#परिभाषय tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#परिभाषय tal_realloc(al, p, आकार) tal_realloc_impl(al, p, आकार, __FILE__, __LINE__)
#परिभाषय TAL_DEBUG_PARAMS , ध्रुव वर्ण *sfile, पूर्णाङ्क sline
#यदि_अन्तः

#परिभाषय TOKSYM_TAL_आकार (256 * 1024) /* allocator for TokenSym in table_ident */
#परिभाषय TOKSTR_TAL_आकार (256 * 1024) /* allocator for TokenString instances */

प्रकारनिर्देश संरचना TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    संरचना TinyAlloc *अग्र;
    अचिह्नित nb_allocs;
    अचिह्नित आकार;
#यदि TAL_INFO
    अचिह्नित nb_peak;
    अचिह्नित nb_योग;
    uint8_t *peak_p;
#यदि_अन्तः
    सङ्घ {
        uint8_t बफर[1];
        आकार_t _aligner_;
    };
} TinyAlloc;

प्रकारनिर्देश संरचना tal_शीर्षकम्_t {
    आकार_t  आकार; /* word align */
#यदि TAL_DEBUG
    पूर्णाङ्क     पङ्क्तिः_अङ्कः; /* negative line_num used for double free check */
    वर्ण    file_name[40];
#यदि_अन्तः
} tal_शीर्षकम्_t;

#परिभाषय TAL_ALIGN(आकार) \
    (((आकार) + (परिमाण (आकार_t) - 1)) & ~(परिमाण (आकार_t) - 1))

/* ------------------------------------------------------------------------- */

स्थिर TinyAlloc *tal_new(TinyAlloc **pal, अचिह्नित आकार)
{
    TinyAlloc *al = tcc_malloc(परिमाण(TinyAlloc) - परिमाण (आकार_t) + आकार);
    al->p = al->बफर;
    al->bufend = al->बफर + आकार;
    al->nb_allocs = 0;
    al->अग्र = *pal, *pal = al;
    al->आकार = al->अग्र ? al->अग्र->आकार : आकार;
#यदि TAL_INFO
    al->nb_peak = 0;
    al->nb_योग = 0;
    al->peak_p = al->p;
#यदि_अन्तः
    प्रत्यागम al;
}

स्थिर शून्य tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *अग्र;

#यदि TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#यदि_अन्तः
पुच्छ_call:
#यदि TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#यदि TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->बफर, al->nb_peak, al->nb_योग,
            (al->peak_p - al->बफर) * 100.0 / (al->bufend - al->बफर));
#यदि_अन्तः
    यदि (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->बफर;
        यावत् (p < al->p) {
            tal_शीर्षकम्_t *शीर्षकम् = (tal_शीर्षकम्_t *)p;
            यदि (शीर्षकम्->पङ्क्तिः_अङ्कः > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        शीर्षकम्->file_name, शीर्षकम्->पङ्क्तिः_अङ्कः, (पूर्णाङ्क)शीर्षकम्->आकार);
            }
            p += शीर्षकम्->आकार + परिमाण(tal_शीर्षकम्_t);
        }
#यदि TAL_DEBUG == 2
        निर्गच्छ(2);
#यदि_अन्तः
    }
#यदि_अन्तः
    अग्र = al->अग्र;
    tcc_free(al);
    al = अग्र;
    यदि (al)
        गच्छ पुच्छ_call;
    *pal = al;
}

स्थिर शून्य tal_free_impl(TinyAlloc **pal, शून्य *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **शिखरम् = pal;
    tal_शीर्षकम्_t *शीर्षकम्;

    यदि (!p)
        प्रत्यागम;
    शीर्षकम् = (tal_शीर्षकम्_t *)p - 1;
#यदि TAL_DEBUG
    यदि (शीर्षकम्->पङ्क्तिः_अङ्कः < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                शीर्षकम्->file_name, (पूर्णाङ्क)-शीर्षकम्->पङ्क्तिः_अङ्कः, (पूर्णाङ्क)शीर्षकम्->आकार);
    } अन्यथा
        शीर्षकम्->पङ्क्तिः_अङ्कः = -शीर्षकम्->पङ्क्तिः_अङ्कः;
#यदि_अन्तः
    al = *pal;
    यावत् ((uint8_t*)p < al->बफर || (uint8_t*)p > al->bufend)
        al = *(pal = &al->अग्र);
    यदि (0 == --al->nb_allocs) {
        *pal = al->अग्र;
        यदि ((al->bufend - al->बफर) > al->आकार) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } अन्यथा {
            /* reset and move to front */
            al->p = al->बफर;
            al->अग्र = *शिखरम्, *शिखरम् = al;
        }
    } अन्यथा यदि ((uint8_t*)p + शीर्षकम्->आकार == al->p) {
        al->p = (uint8_t*)शीर्षकम्;
    }
}

स्थिर शून्य *tal_realloc_impl(TinyAlloc **pal, शून्य *p, अचिह्नित आकार TAL_DEBUG_PARAMS)
{
    tal_शीर्षकम्_t *शीर्षकम्;
    शून्य *ret;
    अचिह्नित adj_आकार = TAL_ALIGN(आकार) + परिमाण(tal_शीर्षकम्_t);
    TinyAlloc *al = *pal;

    यदि (p) {
        /* reallpc case */
        यावत् ((uint8_t*)p < al->बफर || (uint8_t*)p > al->bufend)
            al = al->अग्र;
        शीर्षकम् = (tal_शीर्षकम्_t *)p - 1;
        यदि ((uint8_t*)p + शीर्षकम्->आकार == al->p)
            al->p = (uint8_t*)शीर्षकम्; /* maybe reuse */
        यदि (al->p + adj_आकार > al->bufend) {
            ret = tal_realloc(pal, 0, आकार);
            स्मृतिं_प्रतिलिख(ret, p, शीर्षकम्->आकार);
            tal_free(pal, p);
            प्रत्यागम ret;
        } अन्यथा यदि (al->p != (uint8_t*)शीर्षकम्) {
            स्मृतिं_प्रतिलिख((tal_शीर्षकम्_t*)al->p + 1, p, शीर्षकम्->आकार);
#यदि TAL_DEBUG
            शीर्षकम्->पङ्क्तिः_अङ्कः = -शीर्षकम्->पङ्क्तिः_अङ्कः;
#यदि_अन्तः
        }
    } अन्यथा {
        /* new alloc case */
        यावत् (al->p + adj_आकार > al->bufend) {
            al = al->अग्र;
            यदि (!al) {
                अचिह्नित new_आकार = (*pal)->आकार;
                यदि (adj_आकार > new_आकार) {
                    new_आकार = adj_आकार;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_आकार);
                भङ्ग;
            }
        }
        al->nb_allocs++;
    }
    शीर्षकम् = (tal_शीर्षकम्_t *)al->p;
    शीर्षकम्->आकार = adj_आकार - परिमाण(tal_शीर्षकम्_t);
    al->p += adj_आकार;
    ret = शीर्षकम् + 1;
#यदि  TAL_DEBUG
    {
        पूर्णाङ्क ofs = वाक्यदैर्घ्यम्(sfile) + 1 - परिमाण शीर्षकम्->file_name;
        वाक्यं_प्रतिलिख(शीर्षकम्->file_name, sfile + (ofs > 0 ? ofs : 0));
        शीर्षकम्->पङ्क्तिः_अङ्कः = sline;
#यदि TAL_INFO
        यदि (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        यदि (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_योग++;
#यदि_अन्तः
    }
#यदि_अन्तः
    प्रत्यागम ret;
}

#यदि_अन्तः /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
स्थिर शून्य cstr_realloc(CString *cstr, पूर्णाङ्क new_आकार)
{
    पूर्णाङ्क आकार;

    आकार = cstr->आकार_allocated;
    यदि (आकार < 8)
        आकार = 8; /* no need to allocate a too small first string */
    यावत् (आकार < new_आकार)
        आकार = आकार * 2;
    cstr->दत्त = tcc_realloc(cstr->दत्त, आकार);
    cstr->आकार_allocated = आकार;
}

/* add a byte */
ST_INLN शून्य cstr_ccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क आकार;
    आकार = cstr->आकार + 1;
    यदि (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    cstr->दत्त[आकार - 1] = ch;
    cstr->आकार = आकार;
}

ST_INLN वर्ण *unicode_गन्तव्यम्_utf8 (वर्ण *b, uint32_t Uc)
{
    यदि (Uc<0x80) *b++=Uc;
    अन्यथा यदि (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    अन्यथा यदि (Uc-0xd800u<0x800) गच्छ error;
    अन्यथा यदि (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा यदि (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा error: tcc_error("0x%x is not a valid universal character", Uc);
    प्रत्यागम b;
}

/* add a unicode character expanded into utf8 */
ST_INLN शून्य cstr_u8cat(CString *cstr, पूर्णाङ्क ch)
{
    वर्ण buf[4], *e;
    e = unicode_गन्तव्यम्_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC शून्य cstr_cat(CString *cstr, ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    पूर्णाङ्क आकार;
    यदि (len <= 0)
        len = वाक्यदैर्घ्यम्(str) + 1 + len;
    आकार = cstr->आकार + len;
    यदि (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    memmove(cstr->दत्त + cstr->आकार, str, len);
    cstr->आकार = आकार;
}

/* add a wide char */
ST_FUNC शून्य cstr_wccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क आकार;
    आकार = cstr->आकार + परिमाण(nwchar_t);
    यदि (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    *(nwchar_t *)(cstr->दत्त + आकार - परिमाण(nwchar_t)) = ch;
    cstr->आकार = आकार;
}

ST_FUNC शून्य cstr_new(CString *cstr)
{
    स्मृतिं_पूरय(cstr, 0, परिमाण(CString));
}

/* free string and reset it to NULL */
ST_FUNC शून्य cstr_free(CString *cstr)
{
    tcc_free(cstr->दत्त);
}

/* reset string to empty */
ST_FUNC शून्य cstr_reset(CString *cstr)
{
    cstr->आकार = 0;
}

ST_FUNC पूर्णाङ्क cstr_vprintf(CString *cstr, ध्रुव वर्ण *fmt, va_list ap)
{
    va_list v;
    पूर्णाङ्क len, आकार = 80;
    प्रति (;;) {
        आकार += cstr->आकार;
        यदि (आकार > cstr->आकार_allocated)
            cstr_realloc(cstr, आकार);
        आकार = cstr->आकार_allocated - cstr->आकार;
        va_copy(v, ap);
        len = vsnprintf(cstr->दत्त + cstr->आकार, आकार, fmt, v);
        va_end(v);
        यदि (len >= 0 && len < आकार)
            भङ्ग;
        आकार *= 2;
    }
    cstr->आकार += len;
    प्रत्यागम len;
}

ST_FUNC पूर्णाङ्क cstr_printf(CString *cstr, ध्रुव वर्ण *fmt, ...)
{
    va_list ap; पूर्णाङ्क len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    प्रत्यागम len;
}

/* XXX: unicode ? */
स्थिर शून्य सङ्कलय_char(CString *cstr, पूर्णाङ्क c)
{
    यदि (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    यदि (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } अन्यथा {
        cstr_ccat(cstr, '\\');
        यदि (c == '\n') {
            cstr_ccat(cstr, 'n');
        } अन्यथा {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
स्थिर TokenSym *tok_alloc_new(TokenSym **pts, ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    TokenSym *ts, **ptable;
    पूर्णाङ्क i;

    यदि (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    यदि ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(सारणी_ident, (i + TOK_ALLOC_INCR) * परिमाण(TokenSym *));
        सारणी_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, परिमाण(TokenSym) + len);
    सारणी_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = रिक्त;
    ts->sym_label = रिक्त;
    ts->sym_struct = रिक्त;
    ts->sym_identifier = रिक्त;
    ts->len = len;
    ts->hash_अग्र = रिक्त;
    स्मृतिं_प्रतिलिख(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    प्रत्यागम ts;
}

#परिभाषय TOK_HASH_INIT 1
#परिभाषय TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    TokenSym *ts, **pts;
    पूर्णाङ्क i;
    अचिह्नित पूर्णाङ्क h;
    
    h = TOK_HASH_INIT;
    प्रति(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((अचिह्नित वर्ण *)str)[i]);
    h &= (TOK_HASH_आकार - 1);

    pts = &hash_ident[h];
    प्रति(;;) {
        ts = *pts;
        यदि (!ts)
            भङ्ग;
        यदि (ts->len == len && !memcmp(ts->str, str, len))
            प्रत्यागम ts;
        pts = &(ts->hash_अग्र);
    }
    प्रत्यागम tok_alloc_new(pts, str, len);
}

ST_FUNC पूर्णाङ्क tok_alloc_const(ध्रुव वर्ण *str)
{
    प्रत्यागम tok_alloc(str, वाक्यदैर्घ्यम्(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ध्रुव वर्ण *get_tok_str(पूर्णाङ्क v, CValue *cv)
{
    वर्ण *p;
    पूर्णाङ्क i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.दत्त;

    विकल्प(v) {
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (अचिह्नित दीर्घ दीर्घ)cv->i);
        भङ्ग;
    पक्ष TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    पक्ष TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        सङ्कलय_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        भङ्ग;
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        प्रत्यागम (वर्ण*)cv->str.दत्त;
    पक्ष TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    पक्ष TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        यदि (v == TOK_STR) {
            len = cv->str.आकार - 1;
            प्रति(i=0;i<len;i++)
                सङ्कलय_char(&cstr_buf, ((अचिह्नित वर्ण *)cv->str.दत्त)[i]);
        } अन्यथा {
            len = (cv->str.आकार / परिमाण(nwchar_t)) - 1;
            प्रति(i=0;i<len;i++)
                सङ्कलय_char(&cstr_buf, ((nwchar_t *)cv->str.दत्त)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        भङ्ग;

    पक्ष TOK_CFLOAT:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<float>");
    पक्ष TOK_CDOUBLE:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<double>");
    पक्ष TOK_CLDOUBLE:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<long double>");
    पक्ष TOK_LINENUM:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    पक्ष TOK_LT:
        v = '<';
        गच्छ addv;
    पक्ष TOK_GT:
        v = '>';
        गच्छ addv;
    पक्ष TOK_DOTS:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "...");
    पक्ष TOK_A_SHL:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<<=");
    पक्ष TOK_A_SAR:
        प्रत्यागम वाक्यं_प्रतिलिख(p, ">>=");
    पक्ष TOK_EOF:
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<eof>");
    पक्ष 0: /* anonymous nameless symbols */
        प्रत्यागम वाक्यं_प्रतिलिख(p, "<no name>");
    स्वभाव:
        v &= ~(SYM_क्षेत्रम् | SYM_STRUCT);
        यदि (v < TOK_IDENT) {
            /* search in two bytes table */
            ध्रुव अचिह्नित वर्ण *q = tok_two_chars;
            यावत् (*q) {
                यदि (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    प्रत्यागम cstr_buf.दत्त;
                }
                q += 3;
            }
            यदि (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                भङ्ग;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } अन्यथा यदि (v < tok_ident) {
            प्रत्यागम सारणी_ident[v - TOK_IDENT]->str;
        } अन्यथा यदि (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } अन्यथा {
            /* should never happen */
            प्रत्यागम रिक्त;
        }
        भङ्ग;
    }
    प्रत्यागम cstr_buf.दत्त;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
स्थिर पूर्णाङ्क handle_eob(शून्य)
{
    BufferedFile *bf = file;
    पूर्णाङ्क len;

    /* only tries to read if really end of buffer */
    यदि (bf->buf_ptr >= bf->buf_अन्तः) {
        यदि (bf->fd >= 0) {
#यदि defined(PARSE_DEBUG)
            len = 1;
#अन्यथा
            len = IO_BUF_आकार;
#यदि_अन्तः
            len = पठ(bf->fd, bf->बफर, len);
            यदि (len < 0)
                len = 0;
        } अन्यथा {
            len = 0;
        }
        योग_अष्टकानि += len;
        bf->buf_ptr = bf->बफर;
        bf->buf_अन्तः = bf->बफर + len;
        *bf->buf_अन्तः = CH_EOB;
    }
    यदि (bf->buf_ptr < bf->buf_अन्तः) {
        प्रत्यागम bf->buf_ptr[0];
    } अन्यथा {
        bf->buf_ptr = bf->buf_अन्तः;
        प्रत्यागम CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
स्थिर पूर्णाङ्क अग्र_c(शून्य)
{
    पूर्णाङ्क ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    यदि (ch == CH_EOB && file->buf_ptr >= file->buf_अन्तः)
        ch = handle_eob();
    प्रत्यागम ch;
}

/* input with '\[\r]\n' handling. */
स्थिर पूर्णाङ्क handle_stray_noerror(पूर्णाङ्क err)
{
    पूर्णाङ्क ch;
    यावत् ((ch = अग्र_c()) == '\\') {
        ch = अग्र_c();
        यदि (ch == '\n') {
    newl:
            file->पङ्क्तिः_अङ्कः++;
        } अन्यथा {
            यदि (ch == '\r') {
                ch = अग्र_c();
                यदि (ch == '\n')
                    गच्छ newl;
                *--file->buf_ptr = '\r';
            }
            यदि (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            प्रत्यागम *--file->buf_ptr = '\\';
        }
    }
    प्रत्यागम ch;
}

#परिभाषय ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
स्थिर पूर्णाङ्क handle_bs(uint8_t **p)
{
    पूर्णाङ्क c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    प्रत्यागम c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
स्थिर पूर्णाङ्क handle_stray(uint8_t **p)
{
    पूर्णाङ्क c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    प्रत्यागम c;
}

/* handle the complicated stray case */
#परिभाषय PEEKC(c, p)\
{\
    c = *++p;\
    यदि (c == '\\')\
        c = handle_stray(&p); \
}

स्थिर पूर्णाङ्क skip_spaces(शून्य)
{
    पूर्णाङ्क ch;
    --file->buf_ptr;
    कुरु {
        ch = ninp();
    } यावत् (isidnum_सारणी[ch - CH_EOF] & IS_SPC);
    प्रत्यागम ch;
}

/* single line C++ comments */
स्थिर uint8_t *parse_पङ्क्तिः_comment(uint8_t *p)
{
    पूर्णाङ्क c;
    प्रति(;;) {
        प्रति (;;) {
            c = *++p;
    redo:
            यदि (c == '\n' || c == '\\')
                भङ्ग;
            c = *++p;
            यदि (c == '\n' || c == '\\')
                भङ्ग;
        }
        यदि (c == '\n')
            भङ्ग;
        c = handle_bs(&p);
        यदि (c == CH_EOF)
            भङ्ग;
        यदि (c != '\\')
            गच्छ redo;
    }
    प्रत्यागम p;
}

/* C comments */
स्थिर uint8_t *parse_comment(uint8_t *p)
{
    पूर्णाङ्क c;
    प्रति(;;) {
        /* fast skip loop */
        प्रति(;;) {
            c = *++p;
        redo:
            यदि (c == '\n' || c == '*' || c == '\\')
                भङ्ग;
            c = *++p;
            यदि (c == '\n' || c == '*' || c == '\\')
                भङ्ग;
        }
        /* now we can handle all the cases */
        यदि (c == '\n') {
            file->पङ्क्तिः_अङ्कः++;
        } अन्यथा यदि (c == '*') {
            कुरु {
                c = *++p;
            } यावत् (c == '*');
            यदि (c == '\\')
                c = handle_bs(&p);
            यदि (c == '/')
                भङ्ग;
            गच्छ check_eof;
        } अन्यथा {
            c = handle_bs(&p);
        check_eof:
            यदि (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            यदि (c != '\\')
                गच्छ redo;
        }
    }
    प्रत्यागम p + 1;
}

/* parse a string without interpreting escapes */
स्थिर uint8_t *parse_pp_string(uint8_t *p, पूर्णाङ्क sep, CString *str)
{
    पूर्णाङ्क c;
    प्रति(;;) {
        c = *++p;
    redo:
        यदि (c == sep) {
            भङ्ग;
        } अन्यथा यदि (c == '\\') {
            c = handle_bs(&p);
            यदि (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } अन्यथा यदि (c == '\\') {
                यदि (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                यदि (c == '\\') {
                    c = handle_bs(&p);
                    यदि (c == CH_EOF)
                        गच्छ unterminated_string;
                }
                गच्छ सङ्कलय_char;
            } अन्यथा {
                गच्छ redo;
            }
        } अन्यथा यदि (c == '\n') {
        सङ्कलय_lf:
            यदि (ACCEPT_LF_अन्तर्_वाक्यानि) {
                file->पङ्क्तिः_अङ्कः++;
                गच्छ सङ्कलय_char;
            } अन्यथा यदि (str) { /* not skipping */
                गच्छ unterminated_string;
            } अन्यथा {
                //tcc_warning("missing terminating %c character", sep);
                प्रत्यागम p;
            }
        } अन्यथा यदि (c == '\r') {
            c = *++p;
            यदि (c == '\\')
                c = handle_bs(&p);
            यदि (c == '\n')
                गच्छ सङ्कलय_lf;
            यदि (c == CH_EOF)
                गच्छ unterminated_string;
            यदि (str)
                cstr_ccat(str, '\r');
            गच्छ redo;
        } अन्यथा {
        सङ्कलय_char:
            यदि (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    प्रत्यागम p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
स्थिर शून्य preprocess_skip(शून्य)
{
    पूर्णाङ्क a, start_सम्बन्धि_पङ्क्तिः, c, अन्तर्_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_सम्बन्धि_पङ्क्तिः = 1;
    अन्तर्_warn_or_error = 0;
    प्रति(;;) {
        c = *p;
        विकल्प(c) {
        पक्ष ' ':
        पक्ष '\t':
        पक्ष '\f':
        पक्ष '\v':
        पक्ष '\r':
            p++;
            अनुवर्त;
        पक्ष '\n':
            file->पङ्क्तिः_अङ्कः++;
            p++;
            गच्छ redo_start;
        पक्ष '\\':
            c = handle_bs(&p);
            यदि (c == CH_EOF)
                expect("#endif");
            यदि (c == '\\')
                ++p;
            अनुवर्त;
        /* skip strings */
        पक्ष '\"':
        पक्ष '\'':
            यदि (अन्तर्_warn_or_error)
                गच्छ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, रिक्त);
            भङ्ग;
        /* skip comments */
        पक्ष '/':
            यदि (अन्तर्_warn_or_error)
                गच्छ _default;
            ++p;
            c = handle_bs(&p);
            यदि (c == '*') {
                p = parse_comment(p);
            } अन्यथा यदि (c == '/') {
                p = parse_पङ्क्तिः_comment(p);
            }
            अनुवर्त;
        पक्ष '#':
            p++;
            यदि (start_सम्बन्धि_पङ्क्तिः) {
                file->buf_ptr = p;
                अग्र_nomacro();
                p = file->buf_ptr;
                यदि (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    गच्छ the_अन्तः;
                यदि (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                अन्यथा यदि (tok == TOK_ENDIF)
                    a--;
                अन्यथा यदि( tok == TOK_ERROR || tok == TOK_WARNING)
                    अन्तर्_warn_or_error = 1;
                अन्यथा यदि (tok == TOK_LINEFEED)
                    गच्छ redo_start;
                अन्यथा यदि (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_पङ्क्तिः_comment(p - 1);
            }
#यदि !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            अन्यथा यदि (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_पङ्क्तिः_comment(p - 1);
#अन्यथा
            /* ARM/ARM64 assembly uses '#' for constants */
#यदि_अन्तः
            भङ्ग;
_default:
        स्वभाव:
            p++;
            भङ्ग;
        }
        start_सम्बन्धि_पङ्क्तिः = 0;
    }
 the_अन्तः: ;
    file->buf_ptr = p;
}

#यदि 0
/* return the number of additional 'ints' necessary to store the
   token */
स्थिर अन्तःस्थ पूर्णाङ्क tok_आकार(ध्रुव पूर्णाङ्क *p)
{
    विकल्प(*p) {
        /* 4 bytes */
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_CFLOAT:
    पक्ष TOK_LINENUM:
        प्रत्यागम 1 + 1;
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        प्रत्यागम 1 + 1 + (p[1] + 3) / 4;
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
	प्रत्यागम 1 + LONG_आकार / 4;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
        प्रत्यागम 1 + 2;
    पक्ष TOK_CLDOUBLE:
        प्रत्यागम 1 + LDOUBLE_शब्दाः;
    स्वभाव:
        प्रत्यागम 1 + 0;
    }
}
#यदि_अन्तः

/* token string handling */
ST_INLN शून्य tok_str_new(TokenString *s)
{
    s->str = रिक्त;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->चरमः_पङ्क्तिः_अङ्कः = -1;
}

ST_FUNC TokenString *tok_str_alloc(शून्य)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, परिमाण *str);
    tok_str_new(str);
    प्रत्यागम str;
}

ST_FUNC शून्य tok_str_free_str(पूर्णाङ्क *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC शून्य tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC पूर्णाङ्क *tok_str_realloc(TokenString *s, पूर्णाङ्क new_आकार)
{
    पूर्णाङ्क *str, आकार;

    आकार = s->allocated_len;
    यदि (आकार < 16)
        आकार = 16;
    यावत् (आकार < new_आकार)
        आकार = आकार * 2;
    यदि (आकार > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, आकार * परिमाण(पूर्णाङ्क));
        s->allocated_len = आकार;
        s->str = str;
    }
    प्रत्यागम s->str;
}

ST_FUNC शून्य tok_str_सङ्कलय(TokenString *s, पूर्णाङ्क t)
{
    पूर्णाङ्क len, *str;

    len = s->len;
    str = s->str;
    यदि (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC शून्य begin_macro(TokenString *str, पूर्णाङ्क alloc)
{
    str->alloc = alloc;
    str->पूर्व = macro_राशिः;
    str->पूर्व_ptr = macro_ptr;
    str->save_पङ्क्तिः_अङ्कः = file->पङ्क्तिः_अङ्कः;
    macro_ptr = str->str;
    macro_राशिः = str;
}

ST_FUNC शून्य अन्तः_macro(शून्य)
{
    TokenString *str = macro_राशिः;
    macro_राशिः = str->पूर्व;
    macro_ptr = str->पूर्व_ptr;
    file->पङ्क्तिः_अङ्कः = str->save_पङ्क्तिः_अङ्कः;
    यदि (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } अन्यथा {
        यदि (str->alloc == 2)
            str->str = रिक्त; /* don't free */
        tok_str_free(str);
    }
}

स्थिर शून्य tok_str_add2(TokenString *s, पूर्णाङ्क t, CValue *cv)
{
    पूर्णाङ्क len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    यदि (len + TOK_MAX_आकार >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_आकार + 1);
    str[len++] = t;
    विकल्प(t) {
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_CFLOAT:
    पक्ष TOK_LINENUM:
#यदि LONG_आकार == 4
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#यदि_अन्तः
        str[len++] = cv->tab[0];
        भङ्ग;
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
        {
            /* Insert the string into the int array. */
            आकार_t nb_शब्दाः =
                1 + (cv->str.आकार + परिमाण(पूर्णाङ्क) - 1) / परिमाण(पूर्णाङ्क);
            यदि (len + nb_शब्दाः >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_शब्दाः + 1);
            str[len] = cv->str.आकार;
            स्मृतिं_प्रतिलिख(&str[len + 1], cv->str.दत्त, cv->str.आकार);
            len += nb_शब्दाः;
        }
        भङ्ग;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
#यदि LONG_आकार == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#यदि_अन्तः
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        भङ्ग;
    पक्ष TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        यदि (LDOUBLE_शब्दाः >= 3)
        str[len++] = cv->tab[2];
        यदि (LDOUBLE_शब्दाः >= 4)
        str[len++] = cv->tab[3];
    स्वभाव:
        भङ्ग;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC शून्य tok_str_सङ्कलय_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    यदि (file->पङ्क्तिः_अङ्कः != s->चरमः_पङ्क्तिः_अङ्कः) {
        s->चरमः_पङ्क्तिः_अङ्कः = file->पङ्क्तिः_अङ्कः;
        cval.i = s->चरमः_पङ्क्तिः_अङ्कः;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
स्थिर शून्य tok_str_add2_spc(TokenString *s, पूर्णाङ्क t, CValue *cv)
{
    यदि (s->need_spc == 3)
        tok_str_सङ्कलय(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
स्थिर अन्तःस्थ शून्य tok_get(पूर्णाङ्क *t, ध्रुव पूर्णाङ्क **pp, CValue *cv)
{
    ध्रुव पूर्णाङ्क *p = *pp;
    पूर्णाङ्क n, *tab;

    tab = cv->tab;
    विकल्प(*t = *p++) {
#यदि LONG_आकार == 4
    पक्ष TOK_CLONG:
#यदि_अन्तः
    पक्ष TOK_CINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_LINENUM:
        cv->i = *p++;
        भङ्ग;
#यदि LONG_आकार == 4
    पक्ष TOK_CULONG:
#यदि_अन्तः
    पक्ष TOK_CUINT:
        cv->i = (अचिह्नित)*p++;
        भङ्ग;
    पक्ष TOK_CFLOAT:
	tab[0] = *p++;
	भङ्ग;
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        cv->str.आकार = *p++;
        cv->str.दत्त = (वर्ण*)p;
        p += (cv->str.आकार + परिमाण(पूर्णाङ्क) - 1) / परिमाण(पूर्णाङ्क);
        भङ्ग;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
#यदि LONG_आकार == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#यदि_अन्तः
        n = 2;
        गच्छ copy;
    पक्ष TOK_CLDOUBLE:
        n = LDOUBLE_शब्दाः;
    copy:
        कुरु
            *tab++ = *p++;
        यावत् (--n);
        भङ्ग;
    स्वभाव:
        भङ्ग;
    }
    *pp = p;
}

#यदि 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#अन्यथा
# define TOK_GET(t,p,c) कुरु { \
    पूर्णाङ्क _t = **(p); \
    यदि (TOK_HAS_मानम्(_t)) \
        tok_get(t, p, c); \
    अन्यथा \
        *(t) = _t, ++*(p); \
    } यावत् (0)
#यदि_अन्तः

स्थिर पूर्णाङ्क macro_is_equal(ध्रुव पूर्णाङ्क *a, ध्रुव पूर्णाङ्क *b)
{
    CValue cv;
    पूर्णाङ्क t;

    यदि (!a || !b)
        प्रत्यागम 1;

    यावत् (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        यदि (वाक्यं_तुलय(tokcstr.दत्त, get_tok_str(t, &cv)))
            प्रत्यागम 0;
    }
    प्रत्यागम !(*a || *b);
}

/* defines handling */
ST_INLN शून्य define_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क macro_type, पूर्णाङ्क *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_राशिः, v, macro_type, 0);
    s->d = str;
    s->अग्र = first_arg;
    सारणी_ident[v - TOK_IDENT]->sym_define = s;

    यदि (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, रिक्त));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC शून्य define_undef(Sym *s)
{
    पूर्णाङ्क v = s->v;
    यदि (v >= TOK_IDENT && v < tok_ident)
        सारणी_ident[v - TOK_IDENT]->sym_define = रिक्त;
}

ST_INLN Sym *define_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    यदि ((अचिह्नित)v >= (अचिह्नित)(tok_ident - TOK_IDENT))
        प्रत्यागम रिक्त;
    प्रत्यागम सारणी_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC शून्य free_परिभाषते(Sym *b)
{
    यावत् (define_राशिः != b) {
        Sym *शिखरम् = define_राशिः;
        define_राशिः = शिखरम्->पूर्व;
        tok_str_free_str(शिखरम्->d);
        define_undef(शिखरम्);
        sym_free(शिखरम्);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
स्थिर शून्य maybe_सततम्_test(TCCState *s)
{
    ध्रुव वर्ण *p;
    यदि (s->include_राशिः_ptr != s->include_राशिः)
        प्रत्यागम;
    p = get_tok_str(tok, रिक्त);
    यदि (0 != memcmp(p, "test_", 5))
        प्रत्यागम;
    यदि (0 != --s->सततम्_test)
        प्रत्यागम;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_प्रक्षिप(tok, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य skip_गन्तव्यम्_eol(पूर्णाङ्क warn)
{
    यदि (tok == TOK_LINEFEED)
        प्रत्यागम;
    यदि (warn)
        tcc_warning("extra tokens after directive");
    यावत् (macro_राशिः)
        अन्तः_macro();
    file->buf_ptr = parse_पङ्क्तिः_comment(file->buf_ptr - 1);
    अग्र_nomacro();
}

स्थिर CachedInclude *
अन्वेषणम्_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क सङ्कलय);

स्थिर पूर्णाङ्क parse_include(TCCState *s1, पूर्णाङ्क do_अग्र, पूर्णाङ्क test)
{
    पूर्णाङ्क c, i;
    वर्ण name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    यदि (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.आकार;
        pstrncpy(name, परिमाण name, tokcstr.दत्त, i);
        अग्र_nomacro();
    } अन्यथा {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        प्रति (;;) {
            अग्र();
            p = name, i = वाक्यदैर्घ्यम्(p) - 1;
            यदि (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                भङ्ग;
            यदि (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, परिमाण name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    यदि (!test)
        skip_गन्तव्यम्_eol(1);

    i = do_अग्र ? file->include_अग्र_सूचकांक : -1;
    प्रति (;;) {
        ++i;
        यदि (i == 0) {
            /* check absolute include path */
            यदि (!IS_ABSPATH(name))
                अनुवर्त;
            buf[0] = '\0';
        } अन्यथा यदि (i == 1) {
            /* search in file's dir if "header.h" */
            यदि (c != '\"')
                अनुवर्त;
            p = file->true_filename;
            pstrncpy(buf, परिमाण buf, p, tcc_basename(p) - p);
        } अन्यथा {
            पूर्णाङ्क j = i - 2, k = j - s1->nb_include_paths;
            यदि (k < 0)
                p = s1->include_paths[j];
            अन्यथा यदि (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            अन्यथा यदि (test)
                प्रत्यागम 0;
            अन्यथा
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, परिमाण buf, p);
            pstrcat(buf, परिमाण buf, "/");
        }
        pstrcat(buf, परिमाण buf, name);
        e = अन्वेषणम्_cached_include(s1, buf, 0);
        यदि (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#यदि_परिभाषितम् INC_DEBUG
            प्रारूप_लिख("%s: skipping cached %s\n", file->filename, buf);
#यदि_अन्तः
            यदि ((s1->verbose | 1) == 3) /* -vv[v] */
                प्रारूप_लिख("=> %*s%s\n",
                   (पूर्णाङ्क)(s1->include_राशिः_ptr - s1->include_राशिः), "", buf);
            प्रत्यागम 1;
        }
        यदि (tcc_open(s1, buf) >= 0)
            भङ्ग;
    }

    यदि (test) {
        tcc_close();
    } अन्यथा {
        यदि (s1->include_राशिः_ptr >= s1->include_राशिः + INCLUDE_राशिः_आकार)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_राशिः_ptr++ = file->पूर्व;
        file->include_अग्र_सूचकांक = i;
#यदि_परिभाषितम् INC_DEBUG
        प्रारूप_लिख("%s: including %s\n", file->पूर्व->filename, file->filename);
#यदि_अन्तः
        /* update target deps */
        यदि (s1->gen_deps) {
            BufferedFile *bf = file;
            यावत् (i == 1 && (bf = bf->पूर्व))
                i = bf->include_अग्र_सूचकांक;
            /* skip system include files */
            यदि (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_सङ्कलय(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    प्रत्यागम 1;
}

/* eval an expression for #if/#elif */
स्थिर पूर्णाङ्क व्यञ्जकम्_preprocess(TCCState *s1)
{
    पूर्णाङ्क c, t;
    पूर्णाङ्क t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_व्यञ्जकम् = 1;
    यावत् (1) {
        अग्र(); /* do macro subst */
        t = tok;
        यदि (tok < TOK_IDENT) {
            यदि (tok == TOK_LINEFEED || tok == TOK_EOF)
                भङ्ग;
            यदि (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } अन्यथा यदि (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            अग्र();
            t = tok;
            यदि (t == '(') 
                अग्र();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            यदि (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            यदि (s1->सततम्_test)
                maybe_सततम्_test(s1);
            c = 0;
            यदि (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_अग्र)
                c = 1;
            यदि (t == '(') {
                अग्र();
                यदि (tok != ')')
                    expect("')'");
            }
            गच्छ c_सङ्ख्या;
        } अन्यथा यदि (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_अग्र) {
            t = tok;
            अग्र();
	    यदि (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            यदि (tok != ')')
                expect("')'");
            गच्छ c_सङ्ख्या;
        } अन्यथा {
            /* if undefined macro, replace with zero */
            c = 0;
        c_सङ्ख्या:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_सङ्कलय_tok(str);
    }
    यदि (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_सङ्कलय(str, TOK_EOF); /* simulate end of file */
    pp_व्यञ्जकम् = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    अग्र();
    c = व्यञ्जकम्_const();
    यदि (tok != TOK_EOF)
        tcc_error("...");
    pp_व्यञ्जकम् = 0;
    अन्तः_macro();
    tok = t; /* restore LF or EOF */
    प्रत्यागम c != 0;
}

ST_FUNC शून्य pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_व्यञ्जकम्, 0));
    macro_ptr = macro_राशिः->str;
    यावत् (अग्र(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC शून्य parse_define(शून्य)
{
    Sym *s, *first, **ps;
    पूर्णाङ्क v, t, varg, is_vaargs, t0;
    पूर्णाङ्क saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    यदि (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = रिक्त;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    अग्र_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    यदि (tok == '(') {
        पूर्णाङ्क dotid = समुच्चयः_idnum('.', 0);
        अग्र_nomacro();
        ps = &first;
        यदि (tok != ')') प्रति (;;) {
            varg = tok;
            अग्र_nomacro();
            is_vaargs = 0;
            यदि (varg == TOK_DOTS) {
                varg = TOK_VA_तर्काः;
                is_vaargs = 1;
            } अन्यथा यदि (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                अग्र_nomacro();
            }
            यदि (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_राशिः, varg | SYM_क्षेत्रम्, is_vaargs, 0);
            *ps = s;
            ps = &s->अग्र;
            यदि (tok == ')')
                भङ्ग;
            यदि (tok != ',' || is_vaargs)
                गच्छ bad_list;
            अग्र_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        अग्र_nomacro();
        t = MACRO_FUNC;
        समुच्चयः_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    यावत् (tok != TOK_LINEFEED && tok != TOK_EOF) {
        यदि (is_space(tok)) {
            str.need_spc |= 1;
        } अन्यथा {
            यदि (TOK_TWOSHARPS == tok) {
                यदि (0 == t0)
                    गच्छ bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        अग्र_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_सङ्कलय(&str, 0);
    यदि (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_प्रक्षिप(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

स्थिर CachedInclude *अन्वेषणम्_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क सङ्कलय)
{
    ध्रुव वर्ण *s, *basename;
    अचिह्नित पूर्णाङ्क h;
    CachedInclude *e;
    पूर्णाङ्क c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    यावत् ((c = (अचिह्नित वर्ण)*s) != 0) {
#यदि_परिभाषितम् _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#अन्यथा
        h = TOK_HASH_FUNC(h, c);
#यदि_अन्तः
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_आकार - 1);

    i = s1->cached_includes_hash[h];
    प्रति(;;) {
        यदि (i == 0)
            भङ्ग;
        e = s1->cached_includes[i - 1];
        यदि (0 == PATHCMP(filename, e->filename))
            प्रत्यागम e;
        यदि (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            प्रत्यागम e;
        i = e->hash_अग्र;
    }
    यदि (!सङ्कलय)
        प्रत्यागम रिक्त;

    e = tcc_malloc(परिमाण(CachedInclude) + (len = वाक्यदैर्घ्यम्(filename)));
    स्मृतिं_प्रतिलिख(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_सङ्कलय(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_अग्र = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#यदि_परिभाषितम् INC_DEBUG
    प्रारूप_लिख("adding cached '%s'\n", filename);
#यदि_अन्तः
    प्रत्यागम e;
}

स्थिर पूर्णाङ्क pragma_parse(TCCState *s1)
{
    अग्र_nomacro();
    यदि (tok == TOK_प्रक्षिप_macro || tok == TOK_निष्कासय_macro) {
        पूर्णाङ्क t = tok, v;
        Sym *s;

        यदि (अग्र(), tok != '(')
            गच्छ pragma_err;
        यदि (अग्र(), tok != TOK_STR)
            गच्छ pragma_err;
        v = tok_alloc(tokc.str.दत्त, tokc.str.आकार - 1)->tok;
        यदि (अग्र(), tok != ')')
            गच्छ pragma_err;
        यदि (t == TOK_प्रक्षिप_macro) {
            यावत् (रिक्त == (s = define_find(v)))
                define_प्रक्षिप(v, 0, रिक्त, रिक्त);
            s->type.ref = s; /* set push boundary */
        } अन्यथा {
            प्रति (s = define_राशिः; s; s = s->पूर्व)
                यदि (s->v == v && s->type.ref == s) {
                    s->type.ref = रिक्त;
                    भङ्ग;
                }
        }
        यदि (s)
            सारणी_ident[v - TOK_IDENT]->sym_define = s->d ? s : रिक्त;
        अन्यथा
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } अन्यथा यदि (tok == TOK_once) {
        अन्वेषणम्_cached_include(s1, file->true_filename, 1)->once = 1;

    } अन्यथा यदि (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        प्रत्यागम 1;

    } अन्यथा यदि (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        अग्र();
        skip('(');
        यदि (tok == TOK_ASM_निष्कासय) {
            अग्र();
            यदि (s1->pack_राशिः_ptr <= s1->pack_राशिः) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_राशिः_ptr--;
        } अन्यथा {
            पूर्णाङ्क val = 0;
            यदि (tok != ')') {
                यदि (tok == TOK_ASM_प्रक्षिप) {
                    अग्र();
                    यदि (s1->pack_राशिः_ptr >= s1->pack_राशिः + PACK_राशिः_आकार - 1)
                        गच्छ stk_error;
                    val = *s1->pack_राशिः_ptr++;
                    यदि (tok != ',')
                        गच्छ pack_समुच्चयः;
                    अग्र();
                }
                यदि (tok != TOK_CINT)
                    गच्छ pragma_err;
                val = tokc.i;
                यदि (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    गच्छ pragma_err;
                अग्र();
            }
        pack_समुच्चयः:
            *s1->pack_राशिः_ptr = val;
        }
        यदि (tok != ')')
            गच्छ pragma_err;

    } अन्यथा यदि (tok == TOK_comment) {
        वर्ण *p; पूर्णाङ्क t;
        अग्र();
        skip('(');
        t = tok;
        अग्र();
        skip(',');
        यदि (tok != TOK_STR)
            गच्छ pragma_err;
        p = tcc_strdup(tokc.str.दत्त);
        अग्र();
        यदि (tok != ')')
            गच्छ pragma_err;
        यदि (t == TOK_lib) {
            dynarray_सङ्कलय(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } अन्यथा {
            यदि (t == TOK_option)
                tcc_समुच्चयः_options(s1, p);
            tcc_free(p);
        }

    } अन्यथा {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        प्रत्यागम 0;
    }
    अग्र();
    प्रत्यागम 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC शून्य tccpp_putfile(ध्रुव वर्ण *filename)
{
    वर्ण buf[1024];
    buf[0] = 0;
    यदि (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, परिमाण buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, परिमाण buf, filename);
#यदि_परिभाषितम् _WIN32
    normalize_slashes(buf);
#यदि_अन्तः
    यदि (0 == वाक्यं_तुलय(file->filename, buf))
        प्रत्यागम;
    //printf("new file '%s'\n", buf);
    यदि (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, परिमाण file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC शून्य preprocess(पूर्णाङ्क is_bof)
{
    TCCState *s1 = tcc_state;
    पूर्णाङ्क c, n, saved_parse_flags;
    वर्ण buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_अङ्कः
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    अग्र_nomacro();
 redo:
    विकल्प(tok) {
    पक्ष TOK_DEFINE:
        pp_debug_tok = tok;
        अग्र_nomacro();
        pp_debug_symv = tok;
        parse_define();
        भङ्ग;
    पक्ष TOK_UNDEF:
        pp_debug_tok = tok;
        अग्र_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        यदि (s)
            define_undef(s);
        अग्र_nomacro();
        भङ्ग;
    पक्ष TOK_INCLUDE:
    पक्ष TOK_INCLUDE_अग्र:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        गच्छ the_अन्तः;
    पक्ष TOK_IFNDEF:
        c = 1;
        गच्छ do_ifdef;
    पक्ष TOK_IF:
        c = व्यञ्जकम्_preprocess(s1);
        गच्छ do_if;
    पक्ष TOK_IFDEF:
        c = 0;
    do_ifdef:
        अग्र_nomacro();
        यदि (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        यदि (is_bof) {
            यदि (c) {
#यदि_परिभाषितम् INC_DEBUG
                प्रारूप_लिख("#ifndef %s\n", get_tok_str(tok, रिक्त));
#यदि_अन्तः
                file->ifndef_macro = tok;
            }
        }
        यदि (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_अग्र)
            c ^= 1;
        अग्र_nomacro();
    do_if:
        यदि (s1->ifdef_राशिः_ptr >= s1->ifdef_राशिः + IFDEF_राशिः_आकार)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_राशिः_ptr++ = c;
        गच्छ test_skip;
    पक्ष TOK_ELSE:
        अग्र_nomacro();
        यदि (s1->ifdef_राशिः_ptr == s1->ifdef_राशिः)
            tcc_error("#else without matching #if");
        यदि (s1->ifdef_राशिः_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_राशिः_ptr[-1] ^= 3);
        गच्छ test_else;
    पक्ष TOK_ELIF:
        यदि (s1->ifdef_राशिः_ptr == s1->ifdef_राशिः)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_राशिः_ptr[-1];
        यदि (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        यदि (c == 1) {
            skip_गन्तव्यम्_eol(0);
            c = 0;
        } अन्यथा {
            c = व्यञ्जकम्_preprocess(s1);
            s1->ifdef_राशिः_ptr[-1] = c;
        }
    test_else:
        यदि (s1->ifdef_राशिः_ptr == file->ifdef_राशिः_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        यदि (!(c & 1)) {
            skip_गन्तव्यम्_eol(1);
            preprocess_skip();
            is_bof = 0;
            गच्छ redo;
        }
        भङ्ग;
    पक्ष TOK_ENDIF:
        अग्र_nomacro();
        यदि (s1->ifdef_राशिः_ptr <= file->ifdef_राशिः_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_राशिः_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        यदि (file->ifndef_macro &&
            s1->ifdef_राशिः_ptr == file->ifdef_राशिः_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        भङ्ग;

    पक्ष TOK_पङ्क्तिः:
        parse_flags &= ~PARSE_FLAG_TOK_अङ्कः;
        अग्र();
        यदि (tok != TOK_PPNUM) {
    पङ्क्तिः_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        गच्छ पङ्क्तिः_अङ्कः_2;
    पक्ष TOK_PPNUM:
        यदि (parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        c = 0; /* no error with extra tokens */
    पङ्क्तिः_अङ्कः_2:
        प्रति (n = 0, q = tokc.str.दत्त; *q; ++q) {
            यदि (!isnum(*q))
                गच्छ पङ्क्तिः_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        अग्र();
        यदि (tok != TOK_LINEFEED) {
            यदि (tok != TOK_PPSTR || tokc.str.दत्त[0] != '"')
                गच्छ पङ्क्तिः_err;
            tokc.str.दत्त[tokc.str.आकार - 2] = 0;
            tccpp_putfile(tokc.str.दत्त + 1);
            अग्र();
            /* skip optional level number & advance to next line */
            skip_गन्तव्यम्_eol(c);
        }
        यदि (file->fd > 0)
            योग_पङ्क्तयः += file->पङ्क्तिः_अङ्कः - n;
        file->पङ्क्तिः_अङ्कः = n;
        भङ्ग;

    पक्ष TOK_ERROR:
    पक्ष TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        यावत् (c != '\n' && c != CH_EOF) {
            यदि ((q - buf) < परिमाण(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        यदि (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        अन्यथा
            tcc_warning("#warning %s", buf);
        अग्र_nomacro();
        भङ्ग;
    }
    पक्ष TOK_PRAGMA:
        यदि (!pragma_parse(s1))
            गच्छ ignore;
        भङ्ग;
    पक्ष TOK_LINEFEED:
        गच्छ the_अन्तः;
    स्वभाव:
        /* ignore gas line comment in an 'S' file. */
        यदि (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        यदि (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            गच्छ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_गन्तव्यम्_eol(0);
        गच्छ the_अन्तः;
    }
    skip_गन्तव्यम्_eol(1);
 the_अन्तः:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
स्थिर शून्य parse_escape_string(CString *outstr, ध्रुव uint8_t *buf, पूर्णाङ्क is_long)
{
    पूर्णाङ्क c, n, i;
    ध्रुव uint8_t *p;

    p = buf;
    प्रति(;;) {
        c = *p;
        यदि (c == '\0')
            भङ्ग;
        यदि (c == '\\') {
            p++;
            /* escape */
            c = *p;
            विकल्प(c) {
            पक्ष '0': पक्ष '1': पक्ष '2': पक्ष '3':
            पक्ष '4': पक्ष '5': पक्ष '6': पक्ष '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                यदि (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    यदि (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                गच्छ सङ्कलय_char_nonext;
            पक्ष 'x': i = 0; गच्छ parse_hex_or_ucn;
            पक्ष 'u': i = 4; गच्छ parse_hex_or_ucn;
            पक्ष 'U': i = 8; गच्छ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                कुरु {
                    c = *p;
                    यदि (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    अन्यथा यदि (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    अन्यथा यदि (isnum(c))
                        c = c - '0';
                    अन्यथा यदि (i >= 0)
                        expect("more hex digits in universal-character-name");
                    अन्यथा
                        गच्छ सङ्कलय_hex_or_ucn;
                    n = (अचिह्नित) n * 16 + c;
                    p++;
                } यावत् (--i);
		यदि (is_long) {
    सङ्कलय_hex_or_ucn:
                    c = n;
		    गच्छ सङ्कलय_char_nonext;
		}
                cstr_u8cat(outstr, n);
                अनुवर्त;
            पक्ष 'a':
                c = '\a';
                भङ्ग;
            पक्ष 'b':
                c = '\b';
                भङ्ग;
            पक्ष 'f':
                c = '\f';
                भङ्ग;
            पक्ष 'n':
                c = '\n';
                भङ्ग;
            पक्ष 'r':
                c = '\r';
                भङ्ग;
            पक्ष 't':
                c = '\t';
                भङ्ग;
            पक्ष 'v':
                c = '\v';
                भङ्ग;
            पक्ष 'e':
                यदि (!gnu_ext)
                    गच्छ invalid_escape;
                c = 27;
                भङ्ग;
            पक्ष '\'':
            पक्ष '\"':
            पक्ष '\\': 
            पक्ष '?':
                भङ्ग;
            स्वभाव:
            invalid_escape:
                यदि (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                अन्यथा
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                भङ्ग;
            }
        } अन्यथा यदि (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            पूर्णाङ्क cont; /* count of continuation bytes */
            पूर्णाङ्क skip; /* how many bytes should skip when error occurred */
            पूर्णाङ्क i;

            /* decode leading byte */
            यदि (c < 0xC2) {
	            skip = 1; गच्छ invalid_utf8_sequence;
            } अन्यथा यदि (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } अन्यथा यदि (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } अन्यथा यदि (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } अन्यथा {
	            skip = 1; गच्छ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            प्रति (i = 1; i <= cont; i++) {
                पूर्णाङ्क l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                यदि (i == 1) {
                    विकल्प (c) {
                    पक्ष 0xE0: l = 0xA0; भङ्ग;
                    पक्ष 0xED: h = 0x9F; भङ्ग;
                    पक्ष 0xF0: l = 0x90; भङ्ग;
                    पक्ष 0xF4: h = 0x8F; भङ्ग;
                    }
                }

                यदि (p[i] < l || p[i] > h) {
                    skip = i; गच्छ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            गच्छ सङ्कलय_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            गच्छ सङ्कलय_char_nonext;

        }
        p++;
    सङ्कलय_char_nonext:
        यदि (!is_long)
            cstr_ccat(outstr, c);
        अन्यथा {
#यदि_परिभाषितम् TCC_TARGET_PE
            /* store as UTF-16 */
            यदि (c < 0x10000) {
                cstr_wccat(outstr, c);
            } अन्यथा {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#अन्यथा
            cstr_wccat(outstr, c);
#यदि_अन्तः
        }
    }
    /* add a trailing '\0' */
    यदि (!is_long)
        cstr_ccat(outstr, '\0');
    अन्यथा
        cstr_wccat(outstr, '\0');
}

स्थिर शून्य parse_string(ध्रुव वर्ण *s, पूर्णाङ्क len)
{
    uint8_t buf[1000], *p = buf;
    पूर्णाङ्क is_long, sep;

    यदि ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    यदि (len >= परिमाण buf)
        p = tcc_malloc(len + 1);
    स्मृतिं_प्रतिलिख(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    यदि (p != buf)
        tcc_free(p);

    यदि (sep == '\'') {
        पूर्णाङ्क char_आकार, i, n, c;
        /* XXX: make it portable */
        यदि (!is_long)
            tok = TOK_CCHAR, char_आकार = 1;
        अन्यथा
            tok = TOK_LCHAR, char_आकार = परिमाण(nwchar_t);
        n = tokcstr.आकार / char_आकार - 1;
        यदि (n < 1)
            tcc_error("empty character constant");
        यदि (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        प्रति (c = i = 0; i < n; ++i) {
            यदि (is_long)
                c = ((nwchar_t *)tokcstr.दत्त)[i];
            अन्यथा
                c = (c << 8) | ((वर्ण *)tokcstr.दत्त)[i];
        }
        tokc.i = c;
    } अन्यथा {
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.दत्त = tokcstr.दत्त;
        यदि (!is_long)
            tok = TOK_STR;
        अन्यथा
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#परिभाषय BN_आकार 4

/* bn = (bn << shift) | or_val */
स्थिर पूर्णाङ्क bn_lshift(अचिह्नित पूर्णाङ्क *bn, पूर्णाङ्क सरणम्, पूर्णाङ्क or_val)
{
    पूर्णाङ्क i;
    अचिह्नित पूर्णाङ्क v;
    यदि (bn[BN_आकार - 1] >> (32 - सरणम्))
	प्रत्यागम सरणम्;
    प्रति(i=0;i<BN_आकार;i++) {
        v = bn[i];
        bn[i] = (v << सरणम्) | or_val;
        or_val = v >> (32 - सरणम्);
    }
    प्रत्यागम 0;
}

स्थिर शून्य bn_zero(अचिह्नित पूर्णाङ्क *bn)
{
    पूर्णाङ्क i;
    प्रति(i=0;i<BN_आकार;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
स्थिर शून्य parse_सङ्ख्या(ध्रुव वर्ण *p)
{
    पूर्णाङ्क b, t, सरणम्, frac_द्वयङ्काः, s, exp_val, ch;
    वर्ण *q;
    अचिह्नित पूर्णाङ्क bn[BN_आकार];
    दीर्घ द्विगुण d;

    /*सङ्ख्या*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    यदि (t == '.') {
        गच्छ float_frac_parse;
    } अन्यथा यदि (t == '0') {
        यदि (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } अन्यथा यदि (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    यावत् (1) {
        यदि (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        अन्यथा यदि (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        अन्यथा यदि (isnum(ch))
            t = ch - '0';
        अन्यथा
            भङ्ग;
        यदि (t >= b)
            भङ्ग;
        यदि (q >= token_buf + STRING_MAX_आकार) {
        अङ्कः_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    यदि (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        यदि (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_द्वयङ्काः = 0;
            *q = '\0';
            यदि (b == 16)
                सरणम् = 4;
            अन्यथा 
                सरणम् = 1;
            bn_zero(bn);
            q = token_buf;
            यावत् (1) {
                t = *q++;
                यदि (t == '\0') {
                    भङ्ग;
                } अन्यथा यदि (t >= 'a') {
                    t = t - 'a' + 10;
                } अन्यथा यदि (t >= 'A') {
                    t = t - 'A' + 10;
                } अन्यथा {
                    t = t - '0';
                }
                frac_द्वयङ्काः -= bn_lshift(bn, सरणम्, t);
            }
            यदि (ch == '.') {
                ch = *p++;
                यावत् (1) {
                    t = ch;
                    यदि (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } अन्यथा यदि (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } अन्यथा यदि (t >= '0' && t <= '9') {
                        t = t - '0';
                    } अन्यथा {
                        भङ्ग;
                    }
                    यदि (t >= b)
                        tcc_error("invalid digit");
                    frac_द्वयङ्काः -= bn_lshift(bn, सरणम्, t);
                    frac_द्वयङ्काः += सरणम्;
                    ch = *p++;
                }
            }
            यदि (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            यदि (ch == '+') {
                ch = *p++;
            } अन्यथा यदि (ch == '-') {
                s = -1;
                ch = *p++;
            }
            यदि (ch < '0' || ch > '9')
                expect("exponent digits");
            यावत् (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		यदि (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (दीर्घ द्विगुण)bn[3] * 79228162514264337593543950336.0L +
	        (दीर्घ द्विगुण)bn[2] * 18446744073709551616.0L +
	        (दीर्घ द्विगुण)bn[1] * 4294967296.0L +
	        (दीर्घ द्विगुण)bn[0];
            d = ldexpl(d, exp_val - frac_द्वयङ्काः);
            t = toup(ch);
            यदि (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (भिन्न)d;
            } अन्यथा यदि (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = (द्विगुण)d;
            }
        } अन्यथा {
            /* decimal floats */
            यदि (ch == '.') {
                यदि (q >= token_buf + STRING_MAX_आकार)
                    गच्छ अङ्कः_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                यावत् (ch >= '0' && ch <= '9') {
                    यदि (q >= token_buf + STRING_MAX_आकार)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            यदि (ch == 'e' || ch == 'E') {
                यदि (q >= token_buf + STRING_MAX_आकार)
                    गच्छ अङ्कः_too_long;
                *q++ = ch;
                ch = *p++;
                यदि (ch == '-' || ch == '+') {
                    यदि (q >= token_buf + STRING_MAX_आकार)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                यदि (ch < '0' || ch > '9')
                    expect("exponent digits");
                यावत् (ch >= '0' && ch <= '9') {
                    यदि (q >= token_buf + STRING_MAX_आकार)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            यदि (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, रिक्त);
            } अन्यथा यदि (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, रिक्त);
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, रिक्त);
            }
        }
    } अन्यथा {
        अचिह्नित दीर्घ दीर्घ n, n1;
        पूर्णाङ्क lcount, ucount, ov = 0;
        ध्रुव वर्ण *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        यदि (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        यावत्(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            यदि (t == '\0')
                भङ्ग;
            अन्यथा यदि (t >= 'a')
                t = t - 'a' + 10;
            अन्यथा यदि (t >= 'A')
                t = t - 'A' + 10;
            अन्यथा
                t = t - '0';
            यदि (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            यदि (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        प्रति(;;) {
            t = toup(ch);
            यदि (t == 'L') {
                यदि (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                यदि (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } अन्यथा यदि (t == 'U') {
                यदि (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } अन्यथा {
                भङ्ग;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        यदि (pp_व्यञ्जकम्)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        यदि (ucount == 0 && b == 10) {
            यदि (lcount <= (LONG_आकार == 4)) {
                यदि (n >= 0x80000000U)
                    lcount = (LONG_आकार == 4) + 1;
            }
            यदि (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } अन्यथा {
            यदि (lcount <= (LONG_आकार == 4)) {
                यदि (n >= 0x100000000ULL)
                    lcount = (LONG_आकार == 4) + 1;
                अन्यथा यदि (n >= 0x80000000U)
                    ucount = 1;
            }
            यदि (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        यदि (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	यदि (lcount) {
            tok = TOK_CLONG;
            यदि (lcount == 2)
                tok = TOK_CLLONG;
	}
	यदि (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    यदि (ch)
        tcc_error("invalid number");
}


#परिभाषय PARSE2(c1, tok1, c2, tok2)              \
    पक्ष c1:                                    \
        PEEKC(c, p);                            \
        यदि (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } अन्यथा {                                \
            tok = tok1;                         \
        }                                       \
        भङ्ग;

/* return next token without macro substitution */
स्थिर शून्य अग्र_nomacro(शून्य)
{
    पूर्णाङ्क t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    अचिह्नित पूर्णाङ्क h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    विकल्प(c) {
    पक्ष ' ':
    पक्ष '\t':
        tok = c;
        p++;
 maybe_space:
        यदि (parse_flags & PARSE_FLAG_SPACES)
            गच्छ keep_tok_flags;
        यावत् (isidnum_सारणी[*p - CH_EOF] & IS_SPC)
            ++p;
        गच्छ redo_no_start;
    पक्ष '\f':
    पक्ष '\v':
    पक्ष '\r':
        p++;
        गच्छ redo_no_start;
    पक्ष '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        यदि (c == '\\')
            गच्छ parse_simple;
        यदि (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            यदि (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                गच्छ maybe_newline;
            } अन्यथा यदि (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } अन्यथा यदि (s1->ifdef_राशिः_ptr != file->ifdef_राशिः_ptr) {
                tcc_error("missing #endif");
            } अन्यथा यदि (s1->include_राशिः_ptr == s1->include_राशिः) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } अन्यथा {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                यदि (tok_flags & TOK_FLAG_ENDIF) {
#यदि_परिभाषितम् INC_DEBUG
                    प्रारूप_लिख("#endif %s\n", get_tok_str(file->ifndef_macro_saved, रिक्त));
#यदि_अन्तः
                    अन्वेषणम्_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_राशिः_ptr--;
                p = file->buf_ptr;
                गच्छ maybe_newline;
            }
        } अन्यथा {
            गच्छ redo_no_start;
        }
        भङ्ग;

    पक्ष '\n':
        file->पङ्क्तिः_अङ्कः++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        यदि (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            गच्छ redo_no_start;
        tok = TOK_LINEFEED;
        गच्छ keep_tok_flags;

    पक्ष '#':
        /* XXX: simplify */
        PEEKC(c, p);
        यदि ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            गच्छ maybe_newline;
        } अन्यथा {
            यदि (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } अन्यथा {
#यदि !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                यदि (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_पङ्क्तिः_comment(p - 1);
                    गच्छ redo_no_start;
                } अन्यथा
#यदि_अन्तः
                {
                    tok = '#';
                }
            }
        }
        भङ्ग;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    पक्ष '$':
        यदि (!(isidnum_सारणी['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            गच्छ parse_simple;

    पक्ष 'a': पक्ष 'b': पक्ष 'c': पक्ष 'd':
    पक्ष 'e': पक्ष 'f': पक्ष 'g': पक्ष 'h':
    पक्ष 'i': पक्ष 'j': पक्ष 'k': पक्ष 'l':
    पक्ष 'm': पक्ष 'n': पक्ष 'o': पक्ष 'p':
    पक्ष 'q': पक्ष 'r': पक्ष 's': पक्ष 't':
    पक्ष 'u': पक्ष 'v': पक्ष 'w': पक्ष 'x':
    पक्ष 'y': पक्ष 'z': 
    पक्ष 'A': पक्ष 'B': पक्ष 'C': पक्ष 'D':
    पक्ष 'E': पक्ष 'F': पक्ष 'G': पक्ष 'H':
    पक्ष 'I': पक्ष 'J': पक्ष 'K': 
    पक्ष 'M': पक्ष 'N': पक्ष 'O': पक्ष 'P':
    पक्ष 'Q': पक्ष 'R': पक्ष 'S': पक्ष 'T':
    पक्ष 'U': पक्ष 'V': पक्ष 'W': पक्ष 'X':
    पक्ष 'Y': पक्ष 'Z': 
    पक्ष '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        यावत् (c = *++p, isidnum_सारणी[c - CH_EOF] & (IS_ID|IS_अङ्कः))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        यदि (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_आकार - 1);
            pts = &hash_ident[h];
            प्रति(;;) {
                ts = *pts;
                यदि (!ts)
                    भङ्ग;
                यदि (ts->len == len && !memcmp(ts->str, p1, len))
                    गच्छ token_प्राप्तम्;
                pts = &(ts->hash_अग्र);
            }
            ts = tok_alloc_new(pts, (वर्ण *) p1, len);
        token_प्राप्तम्: ;
        } अन्यथा {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (वर्ण *) p1, len);
            p--;
            PEEKC(c, p);
            यावत् (isidnum_सारणी[c - CH_EOF] & (IS_ID|IS_अङ्कः))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.दत्त, tokcstr.आकार);
        }
        tok = ts->tok;
        भङ्ग;
    पक्ष 'L':
        t = p[1];
        यदि (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            यदि (c == '\'' || c == '\"') {
                is_long = 1;
                गच्छ str_const;
            }
            *--p = c = 'L';
        }
        गच्छ parse_ident_fast;

    पक्ष '0': पक्ष '1': पक्ष '2': पक्ष '3':
    पक्ष '4': पक्ष '5': पक्ष '6': पक्ष '7':
    पक्ष '8': पक्ष '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_अङ्कः:
        cstr_reset(&tokcstr);
        प्रति(;;) {
            cstr_ccat(&tokcstr, t);
            यदि (!((isidnum_सारणी[c - CH_EOF] & (IS_ID|IS_अङ्कः))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((वर्ण*)tokcstr.दत्त)[0] == '0'
                                && toup(((वर्ण*)tokcstr.दत्त)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                भङ्ग;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.दत्त = tokcstr.दत्त;
        tok = TOK_PPNUM;
        भङ्ग;

    पक्ष '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        यदि (isnum(c)) {
            t = '.';
            गच्छ parse_अङ्कः;
        } अन्यथा यदि ((isidnum_सारणी['.' - CH_EOF] & IS_ID)
                   && (isidnum_सारणी[c - CH_EOF] & (IS_ID|IS_अङ्कः))) {
            *--p = c = '.';
            गच्छ parse_ident_fast;
        } अन्यथा यदि (c == '.') {
            PEEKC(c, p);
            यदि (c == '.') {
                p++;
                tok = TOK_DOTS;
            } अन्यथा {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } अन्यथा {
            tok = '.';
        }
        भङ्ग;
    पक्ष '\'':
    पक्ष '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        यदि (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.दत्त = tokcstr.दत्त;
        tok = TOK_PPSTR;
        भङ्ग;

    पक्ष '<':
        PEEKC(c, p);
        यदि (c == '=') {
            p++;
            tok = TOK_LE;
        } अन्यथा यदि (c == '<') {
            PEEKC(c, p);
            यदि (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } अन्यथा {
                tok = TOK_SHL;
            }
        } अन्यथा {
            tok = TOK_LT;
        }
        भङ्ग;
    पक्ष '>':
        PEEKC(c, p);
        यदि (c == '=') {
            p++;
            tok = TOK_GE;
        } अन्यथा यदि (c == '>') {
            PEEKC(c, p);
            यदि (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } अन्यथा {
                tok = TOK_SAR;
            }
        } अन्यथा {
            tok = TOK_GT;
        }
        भङ्ग;
        
    पक्ष '&':
        PEEKC(c, p);
        यदि (c == '&') {
            p++;
            tok = TOK_LAND;
        } अन्यथा यदि (c == '=') {
            p++;
            tok = TOK_A_AND;
        } अन्यथा {
            tok = '&';
        }
        भङ्ग;
        
    पक्ष '|':
        PEEKC(c, p);
        यदि (c == '|') {
            p++;
            tok = TOK_LOR;
        } अन्यथा यदि (c == '=') {
            p++;
            tok = TOK_A_OR;
        } अन्यथा {
            tok = '|';
        }
        भङ्ग;

    पक्ष '+':
        PEEKC(c, p);
        यदि (c == '+') {
            p++;
            tok = TOK_INC;
        } अन्यथा यदि (c == '=') {
            p++;
            tok = TOK_A_सङ्कलय;
        } अन्यथा {
            tok = '+';
        }
        भङ्ग;
        
    पक्ष '-':
        PEEKC(c, p);
        यदि (c == '-') {
            p++;
            tok = TOK_DEC;
        } अन्यथा यदि (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } अन्यथा यदि (c == '>') {
            p++;
            tok = TOK_ARROW;
        } अन्यथा {
            tok = '-';
        }
        भङ्ग;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    पक्ष '/':
        PEEKC(c, p);
        यदि (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            गच्छ maybe_space;
        } अन्यथा यदि (c == '/') {
            p = parse_पङ्क्तिः_comment(p);
            tok = ' ';
            गच्छ maybe_space;
        } अन्यथा यदि (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } अन्यथा {
            tok = '/';
        }
        भङ्ग;
        
        /* simple tokens */
    पक्ष '@': /* only used in assembler */
#यदि_परिभाषितम् TCC_TARGET_ARM /* comment on arm asm */
        यदि (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_पङ्क्तिः_comment(p);
            गच्छ redo_no_start;
        }
#यदि_अन्तः
    पक्ष '(':
    पक्ष ')':
    पक्ष '[':
    पक्ष ']':
    पक्ष '{':
    पक्ष '}':
    पक्ष ',':
    पक्ष ';':
    पक्ष ':':
    पक्ष '?':
    पक्ष '~':
    parse_simple:
        tok = c;
        p++;
        भङ्ग;
    पक्ष 0xEF: /* UTF8 BOM ? */
        यदि (p[1] == 0xBB && p[2] == 0xBF && p == file->बफर) {
            p += 3;
            गच्छ redo_no_start;
        }
    स्वभाव:
        यदि (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    गच्छ parse_ident_fast;
        यदि (parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        भङ्ग;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#यदि defined(PARSE_DEBUG)
    प्रारूप_लिख("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#यदि_अन्तः
}

#यदि_परिभाषितम् PP_DEBUG
स्थिर पूर्णाङ्क indent;
स्थिर शून्य define_print(TCCState *s1, पूर्णाङ्क v);
स्थिर शून्य pp_print(ध्रुव वर्ण *सन्देशः, पूर्णाङ्क v, ध्रुव पूर्णाङ्क *str)
{
    FILE *fp = tcc_state->ppfp;

    यदि (सन्देशः[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    अन्यथा यदि (सन्देशः[0] == '+')
         ++indent, ++सन्देशः;
    अन्यथा यदि (सन्देशः[0] == '-')
        --indent, ++सन्देशः;

    fprintf(fp, "%*s", indent, "");
    यदि (सन्देशः[0] == '#') {
        define_print(tcc_state, v);
    } अन्यथा {
        tok_print(str, v ? "%s %s" : "%s", सन्देशः, get_tok_str(v, 0));
    }
}
#परिभाषय PP_PRINT(x) pp_print x
#अन्यथा
#परिभाषय PP_PRINT(x)
#यदि_अन्तः

स्थिर पूर्णाङ्क macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ध्रुव पूर्णाङ्क *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
स्थिर पूर्णाङ्क *macro_arg_subst(Sym **nested_list, ध्रुव पूर्णाङ्क *macro_str, Sym *तर्काः)
{
    पूर्णाङ्क t, t0, t1, t2, n;
    ध्रुव पूर्णाङ्क *st;
    Sym *s;
    CValue cval;
    TokenString str;

#यदि_परिभाषितम् PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    प्रति (s = तर्काः, n = 0; s; s = s->पूर्व, ++n);
    यावत् (n--) {
        प्रति (s = तर्काः, t = 0; t < n; s = s->पूर्व, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#यदि_अन्तः

    tok_str_new(&str);
    t0 = t1 = 0;
    यावत्(1) {
        TOK_GET(&t, &macro_str, &cval);
        यदि (!t)
            भङ्ग;
        यदि (t == '#') {
            /* stringize */
            कुरु t = *macro_str++; यावत् (t == ' ');
            s = sym_find2(तर्काः, t);
            यदि (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                यावत् (*st != TOK_EOF) {
                    ध्रुव वर्ण *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    यावत् (*s) {
                        यदि (t == TOK_PPSTR && *s != '\'')
                            सङ्कलय_char(&tokcstr, *s);
                        अन्यथा
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.आकार = tokcstr.आकार;
                cval.str.दत्त = tokcstr.दत्त;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#यदि_परिभाषितम् TCC_TARGET_ARM
            } अन्यथा यदि ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_सङ्कलय(&str, '#');
#यदि_अन्तः
            } अन्यथा {
                expect("macro parameter after '#'");
            }
        } अन्यथा यदि (t >= TOK_IDENT) {
            s = sym_find2(तर्काः, t);
            यदि (s) {
                st = s->d;
                n = 0;
                यावत् ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                यदि (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    यदि (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        पूर्णाङ्क c = str.str[str.len - 1];
                        यावत् (str.str[--str.len] != ',')
                            ;
                        यदि (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } अन्यथा {
                            /* suppress '##' and add variable */
                            str.len++;
                            यदि (c == ' ')
                                str.str[str.len++] = c;
                            गच्छ सङ्कलय_var;
                        }
                    } अन्यथा {
                        यदि (*st == TOK_EOF)
                            tok_str_सङ्कलय(&str, TOK_PLCHLDR);
                    }
                } अन्यथा {
            सङ्कलय_var:
		    यदि (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_सङ्कलय(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                यावत् (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } अन्यथा {
                tok_str_सङ्कलय(&str, t);
            }
        } अन्यथा {
            tok_str_add2(&str, t, &cval);
        }
        यदि (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_सङ्कलय(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    प्रत्यागम str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
स्थिर अन्तःस्थ पूर्णाङ्क *macro_twosharps(ध्रुव पूर्णाङ्क *ptr0)
{
    पूर्णाङ्क t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ध्रुव पूर्णाङ्क *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    प्रति (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        यदि (t1 == 0)
            भङ्ग;
        प्रति (;;) {
            n = 0;
            यावत् ((t2 = ptr[n]) == ' ')
                ++n;
            यदि (t2 != TOK_PPJOIN)
                भङ्ग;
            ptr += n;
            यावत् ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            यदि (t2 == TOK_PLCHLDR)
                अनुवर्त;
            यदि (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        यदि (tokcstr.आकार) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.आकार);
            स्मृतिं_प्रतिलिख(file->बफर, tokcstr.दत्त, tokcstr.आकार);
            tok_flags = 0; /* don't interpret '#' */
            प्रति (n = 0;;n = l) {
                अग्र_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                यदि (*file->buf_ptr == 0)
                    भङ्ग;
                tok_str_सङ्कलय(&macro_str1, ' ');
                l = file->buf_ptr - file->बफर;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->बफर + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        यदि (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_सङ्कलय(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    प्रत्यागम macro_str1.str;
}

स्थिर पूर्णाङ्क peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    पूर्णाङ्क c;
    प्रति (;;) {
        PEEKC(c, p);
        विकल्प (c) {
        पक्ष '/':
            PEEKC(c, p);
            यदि (c == '*')
                p = parse_comment(p);
            अन्यथा यदि (c == '/')
                p = parse_पङ्क्तिः_comment(p);
            अन्यथा {
                c = *--p = '/';
                गच्छ leave;
            }
            --p, c = ' ';
            भङ्ग;
        पक्ष ' ': पक्ष '\t':
            भङ्ग;
        पक्ष '\f': पक्ष '\v': पक्ष '\r':
            अनुवर्त;
        पक्ष '\n':
            file->पङ्क्तिः_अङ्कः++, tok_flags |= TOK_FLAG_BOL;
            भङ्ग;
        स्वभाव: leave:
            file->buf_ptr = p;
            प्रत्यागम c;
        }
        यदि (ws_str)
            tok_str_सङ्कलय(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
स्थिर पूर्णाङ्क अग्र_argstream(Sym **nested_list, TokenString *ws_str)
{
    पूर्णाङ्क t;
    Sym *sa;

    यावत् (macro_ptr) {
        ध्रुव पूर्णाङ्क *m = macro_ptr;
        यावत् ((t = *m) != 0) {
            यदि (ws_str) {
                यदि (t != ' ')
                    प्रत्यागम t;
                ++m;
            } अन्यथा {
                TOK_GET(&tok, &macro_ptr, &tokc);
                प्रत्यागम tok;
            }
        }
        अन्तः_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        यदि (sa)
            *nested_list = sa->पूर्व, sym_free(sa);
    }
    यदि (ws_str) {
        प्रत्यागम peek_file(ws_str);
    } अन्यथा {
        अग्र_nomacro();
        यदि (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        प्रत्यागम tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
स्थिर पूर्णाङ्क macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    पूर्णाङ्क t;
    पूर्णाङ्क v = s->v;

    PP_PRINT(("#", v, s->d));
    यदि (s->d) {
        पूर्णाङ्क *mstr = s->d;
        पूर्णाङ्क *jstr;
        Sym *sa;
        पूर्णाङ्क ret;

        यदि (s->type.t & MACRO_FUNC) {
            पूर्णाङ्क saved_parse_flags = parse_flags;
            TokenString str;
            पूर्णाङ्क parlevel, i;
            Sym *sa1, *तर्काः;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = अग्र_argstream(nested_list, &str);
            यदि (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                यदि (parse_flags & PARSE_FLAG_SPACES)
                    प्रति (i = 0; i < str.len; i++)
                        tok_str_सङ्कलय(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                प्रत्यागम 0;
            } अन्यथा {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            तर्काः = रिक्त;
            sa = s->अग्र;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            प्रति(;;) {
                कुरु {
                    t = अग्र_argstream(nested_list, रिक्त);
                } यावत् (t == ' ' || --i);

                यदि (!sa) {
                    यदि (t == ')') /* handle '()' case */
                        भङ्ग;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            रिक्तानि_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                यावत् (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    यदि (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    यदि (t == '(')
                        parlevel++;
                    यदि (t == ')')
                        parlevel--;
                    यदि (t == ' ')
                        str.need_spc |= 1;
                    अन्यथा
                        tok_str_add2_spc(&str, t, &tokc);
                    t = अग्र_argstream(nested_list, रिक्त);
                }
                tok_str_सङ्कलय(&str, TOK_EOF);
                sa1 = sym_push2(&तर्काः, sa->v & ~SYM_क्षेत्रम्, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->अग्र;
                यदि (t == ')') {
                    यदि (!sa)
                        भङ्ग;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    यदि (sa->type.t && gnu_ext)
                        गच्छ रिक्तानि_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, तर्काः);
            /* free memory */
            sa = तर्काः;
            यावत् (sa) {
                sa1 = sa->पूर्व;
                tok_str_free_str(sa->d);
                tok_str_free_str(sa->e);
                sym_free(sa);
                sa = sa1;
            }
            parse_flags = saved_parse_flags;
        }

        /* process '##'s (if present) */
        jstr = mstr;
        यदि (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        यदि (sa == *nested_list)
            *nested_list = sa->पूर्व, sym_free(sa);

        यदि (jstr != mstr)
            tok_str_free_str(jstr);
        यदि (mstr != s->d)
            tok_str_free_str(mstr);
        प्रत्यागम ret;

    } अन्यथा {
        CValue cval;
        वर्ण buf[32], *cstrval = buf;

        /* special macros */
        यदि (v == TOK_पङ्क्तिः_2 || v == TOK_गणक) {
            t = v == TOK_पङ्क्तिः_2 ? file->पङ्क्तिः_अङ्कः : pp_गणक++;
            snprintf(buf, परिमाण(buf), "%d", t);
            t = TOK_PPNUM;
            गच्छ सङ्कलय_cstr1;

        } अन्यथा यदि (v == TOK___FILE__) {
            cstrval = file->filename;
            गच्छ सङ्कलय_cstr;

        } अन्यथा यदि (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            संरचना tm *tm;
            time(&ti);
            tm = localtime(&ti);
            यदि (v == TOK___DATE__) {
                स्थिर वर्ण ध्रुव ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, परिमाण(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } अन्यथा {
                snprintf(buf, परिमाण(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        सङ्कलय_cstr:
            t = TOK_STR;
        सङ्कलय_cstr1:
            cval.str.आकार = वाक्यदैर्घ्यम्(cstrval) + 1;
            cval.str.दत्त = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        प्रत्यागम 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
स्थिर पूर्णाङ्क macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ध्रुव पूर्णाङ्क *macro_str
    )
{
    Sym *s;
    पूर्णाङ्क t, nosubst = 0;
    CValue cval;
    TokenString *str;

#यदि_परिभाषितम् PP_DEBUG
    पूर्णाङ्क tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#यदि_अन्तः

    यावत् (1) {
        TOK_GET(&t, &macro_str, &cval);
        यदि (t == 0 || t == TOK_EOF)
            भङ्ग;
        यदि (t >= TOK_IDENT) {
            s = define_find(t);
            यदि (s == रिक्त || nosubst)
                गच्छ no_subst;
            /* if nested substitution, do nothing */
            यदि (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_क्षेत्रम्;
                गच्छ no_subst;
            }
            str = tok_str_alloc();
            str->str = (पूर्णाङ्क*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            यदि (macro_राशिः != str) {
                /* already finished by reading function macro arguments */
                भङ्ग;
            }
            macro_str = macro_ptr;
            अन्तः_macro ();
        } अन्यथा यदि (t == ' ') {
            यदि (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } अन्यथा {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            यदि (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            यदि (t == TOK_DEFINED && pp_व्यञ्जकम्)
                nosubst = 1;
        }
    }

#यदि_परिभाषितम् PP_DEBUG
    tok_str_सङ्कलय(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#यदि_अन्तः
    प्रत्यागम nosubst;
}

/* return next token with macro substitution */
ST_FUNC शून्य अग्र(शून्य)
{
    पूर्णाङ्क t;
    यावत् (macro_ptr) {
redo:
        t = *macro_ptr;
        यदि (TOK_HAS_मानम्(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            यदि (t == TOK_LINENUM) {
                file->पङ्क्तिः_अङ्कः = tokc.i;
                गच्छ redo;
            }
            गच्छ convert;
        } अन्यथा यदि (t == 0) {
            /* end of macro or unget token string */
            अन्तः_macro();
            अनुवर्त;
        } अन्यथा यदि (t == TOK_EOF) {
            /* do nothing */
        } अन्यथा {
            ++macro_ptr;
            t &= ~SYM_क्षेत्रम्; /* remove 'nosubst' marker */
            यदि (t == '\\') {
                यदि (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        प्रत्यागम;
    }

    अग्र_nomacro();
    t = tok;
    यदि (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        यदि (s) {
            Sym *nested_list = रिक्त;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_सङ्कलय(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            गच्छ redo;
        }
        प्रत्यागम;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    यदि (t == TOK_PPNUM) {
        यदि  (parse_flags & PARSE_FLAG_TOK_अङ्कः)
            parse_सङ्ख्या(tokc.str.दत्त);
    } अन्यथा यदि (t == TOK_PPSTR) {
        यदि (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.दत्त, tokc.str.आकार - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN शून्य unget_tok(पूर्णाङ्क चरमः_tok)
{
    TokenString *str = &unget_buf;
    पूर्णाङ्क alloc = 0;
    यदि (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    यदि (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_सङ्कलय(str, 0);
    begin_macro(str, alloc);
    tok = चरमः_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

स्थिर ध्रुव वर्ण * ध्रुव target_os_defs =
#यदि_परिभाषितम् TCC_TARGET_PE
    "_WIN32\0"
# यदि PTR_आकार == 8
    "_WIN64\0"
# endif
#अन्यथा
# यदि defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# अन्यथा
    "__linux__\0"
    "__linux\0"
#  यदि TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#यदि_अन्तः
    ;

स्थिर शून्य putdef(CString *cs, ध्रुव वर्ण *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

स्थिर शून्य putdefs(CString *cs, ध्रुव वर्ण *p)
{
    यावत् (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

स्थिर शून्य tcc_predefs(TCCState *s1, CString *cs, पूर्णाङ्क is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_संस्करणम्[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#यदि_परिभाषितम् TCC_TARGET_ARM
    यदि (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#यदि_अन्तः
    यदि (is_asm)
      putdef(cs, "__ASSEMBLER__");
    यदि (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    यदि (s1->output_type == TCC_OUTPUT_स्मृतिः)
      putdef(cs, "__TCC_RUN__");
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    यदि (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#यदि_अन्तः
    यदि (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    यदि (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    यदि (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    यदि (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_आकार);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_आकार);
    यदि (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#यदि CONFIG_TCC_PREDEFS
        #अन्तर्भाव "tccdefs_.h" /* include as strings */
#अन्यथा
        "#include <tccdefs.h>\n" /* load at runtime */
#यदि_अन्तः
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC शून्य preprocess_start(TCCState *s1, पूर्णाङ्क filetype)
{
    पूर्णाङ्क is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_राशिः_ptr = s1->include_राशिः;
    s1->ifdef_राशिः_ptr = s1->ifdef_राशिः;
    file->ifdef_राशिः_ptr = s1->ifdef_राशिः_ptr;
    pp_व्यञ्जकम् = 0;
    pp_गणक = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_राशिः[0] = 0;
    s1->pack_राशिः_ptr = s1->pack_राशिः;

    समुच्चयः_idnum('$', s1->dollars_अन्तर्_identifiers ? IS_ID : 0);
    समुच्चयः_idnum('.', is_asm ? IS_ID : 0);

    यदि (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        यदि (s1->cmdline_defs.आकार)
          cstr_cat(&cstr, s1->cmdline_defs.दत्त, s1->cmdline_defs.आकार);
        यदि (s1->cmdline_incl.आकार)
          cstr_cat(&cstr, s1->cmdline_incl.दत्त, s1->cmdline_incl.आकार);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_राशिः_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.आकार);
        स्मृतिं_प्रतिलिख(file->बफर, cstr.दत्त, cstr.आकार);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC शून्य preprocess_अन्तः(TCCState *s1)
{
    यावत् (macro_राशिः)
        अन्तः_macro();
    macro_ptr = रिक्त;
    यावत् (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC पूर्णाङ्क समुच्चयः_idnum(पूर्णाङ्क c, पूर्णाङ्क val)
{
    पूर्णाङ्क पूर्व = isidnum_सारणी[c - CH_EOF];
    isidnum_सारणी[c - CH_EOF] = val;
    प्रत्यागम पूर्व;
}

ST_FUNC शून्य tccpp_new(TCCState *s)
{
    पूर्णाङ्क i, c;
    ध्रुव वर्ण *p, *r;

    /* init isid table */
    प्रति(i = CH_EOF; i<128; i++)
        समुच्चयः_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_अङ्कः
            : 0);

    प्रति(i = 128; i<256; i++)
        समुच्चयः_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_आकार);
    tal_new(&tokstr_alloc, TOKSTR_TAL_आकार);

    स्मृतिं_पूरय(hash_ident, 0, TOK_HASH_आकार * परिमाण(TokenSym *));
    स्मृतिं_पूरय(s->cached_includes_hash, 0, परिमाण s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_आकार);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_आकार);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_आकार);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    यावत् (*p) {
        r = p;
        प्रति(;;) {
            c = *r++;
            यदि (c == '\0')
                भङ्ग;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_प्रक्षिप(TOK_पङ्क्तिः_2, MACRO_OBJ, रिक्त, रिक्त);
    define_प्रक्षिप(TOK___FILE__, MACRO_OBJ, रिक्त, रिक्त);
    define_प्रक्षिप(TOK___DATE__, MACRO_OBJ, रिक्त, रिक्त);
    define_प्रक्षिप(TOK___TIME__, MACRO_OBJ, रिक्त, रिक्त);
    define_प्रक्षिप(TOK_गणक, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य tccpp_delete(TCCState *s)
{
    पूर्णाङ्क i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    यदि (n > योग_idents)
        योग_idents = n;
    प्रति (i = n; --i >= 0;)
        tal_free(&toksym_alloc, सारणी_ident[i]);
    tcc_free(सारणी_ident);
    सारणी_ident = रिक्त;

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

स्थिर पूर्णाङ्क pp_need_space(पूर्णाङ्क a, पूर्णाङ्क b);

स्थिर शून्य tok_print(ध्रुव पूर्णाङ्क *str, ध्रुव वर्ण *सन्देशः, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    पूर्णाङ्क t, t0, s;
    CValue cval;

    va_start(ap, सन्देशः);
    vfprintf(fp, सन्देशः, ap);
    va_end(ap);

    s = t0 = 0;
    यावत् (str) {
	TOK_GET(&t, &str, &cval);
	यदि (t == 0 || t == TOK_EOF)
	    भङ्ग;
        यदि (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

स्थिर शून्य pp_पङ्क्तिः(TCCState *s1, BufferedFile *f, पूर्णाङ्क level)
{
    पूर्णाङ्क d = f->पङ्क्तिः_अङ्कः - f->पङ्क्तिः_ref;

    यदि (s1->dflag & 4)
	प्रत्यागम;

    यदि (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } अन्यथा यदि (level == 0 && f->पङ्क्तिः_ref && d < 8) {
	यावत् (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } अन्यथा यदि (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->पङ्क्तिः_अङ्कः, f->filename);
    } अन्यथा {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->पङ्क्तिः_अङ्कः, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->पङ्क्तिः_ref = f->पङ्क्तिः_अङ्कः;
}

स्थिर शून्य define_print(TCCState *s1, पूर्णाङ्क v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    यदि (रिक्त == s || रिक्त == s->d)
        प्रत्यागम;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, रिक्त));
    यदि (s->type.t & MACRO_FUNC) {
        Sym *a = s->अग्र;
        fprintf(fp,"(");
        यदि (a)
            प्रति (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, रिक्त));
                यदि (!(a = a->अग्र))
                    भङ्ग;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

स्थिर शून्य pp_debug_परिभाषते(TCCState *s1)
{
    पूर्णाङ्क v, t;
    ध्रुव वर्ण *vs;
    FILE *fp;

    t = pp_debug_tok;
    यदि (t == 0)
        प्रत्यागम;

    file->पङ्क्तिः_अङ्कः--;
    pp_पङ्क्तिः(s1, file, 0);
    file->पङ्क्तिः_ref = ++file->पङ्क्तिः_अङ्कः;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, रिक्त);
    यदि (t == TOK_DEFINE) {
        define_print(s1, v);
    } अन्यथा यदि (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } अन्यथा यदि (t == TOK_प्रक्षिप_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } अन्यथा यदि (t == TOK_निष्कासय_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
स्थिर पूर्णाङ्क pp_need_space(पूर्णाङ्क a, पूर्णाङ्क b)
{
    प्रत्यागम 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
स्थिर पूर्णाङ्क pp_check_he0xE(पूर्णाङ्क t, ध्रुव वर्ण *p)
{
    यदि (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        प्रत्यागम 'E';
    प्रत्यागम t;
}

/* Preprocess the current file */
ST_FUNC पूर्णाङ्क tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    पूर्णाङ्क token_आलोकितम्, spcs, level;
    ध्रुव वर्ण *p;
    वर्ण white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    यदि (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_अङ्कः, s1->Pflag = 1;

    यदि (s1->do_bench) {
	/* for PP benchmarks */
	कुरु अग्र(); यावत् (tok != TOK_EOF);
	प्रत्यागम 0;
    }

    token_आलोकितम् = TOK_LINEFEED, spcs = 0, level = 0;
    यदि (file->पूर्व)
        pp_पङ्क्तिः(s1, file->पूर्व, level++);
    pp_पङ्क्तिः(s1, file, level);

    प्रति (;;) {
        iptr = s1->include_राशिः_ptr;
        अग्र();
        यदि (tok == TOK_EOF)
            भङ्ग;

        level = s1->include_राशिः_ptr - iptr;
        यदि (level) {
            यदि (level > 0)
                pp_पङ्क्तिः(s1, *iptr, 0);
            pp_पङ्क्तिः(s1, file, level);
        }
        यदि (s1->dflag & 7) {
            pp_debug_परिभाषते(s1);
            यदि (s1->dflag & 4)
                अनुवर्त;
        }

        यदि (is_space(tok)) {
            यदि (spcs < परिमाण white - 1)
                white[spcs++] = tok;
            अनुवर्त;
        } अन्यथा यदि (tok == TOK_LINEFEED) {
            spcs = 0;
            यदि (token_आलोकितम् == TOK_LINEFEED)
                अनुवर्त;
            ++file->पङ्क्तिः_ref;
        } अन्यथा यदि (token_आलोकितम् == TOK_LINEFEED) {
            pp_पङ्क्तिः(s1, file, 0);
        } अन्यथा यदि (spcs == 0 && pp_need_space(token_आलोकितम्, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_आलोकितम् = pp_check_he0xE(tok, p);
    }
    प्रत्यागम 0;
}

/* ------------------------------------------------------------------------- */
