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

#घोषणा USING_GLOBALS
#समावेश "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#घोषणा ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_तथ्य पूर्णांक tok_flags;
ST_तथ्य पूर्णांक parse_flags;

ST_तथ्य काष्ठा BufferedFile *file;
ST_तथ्य पूर्णांक tok;
ST_तथ्य CValue tokc;
ST_तथ्य स्थिर पूर्णांक *macro_ptr;
ST_तथ्य CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_तथ्य पूर्णांक tok_ident;
ST_तथ्य TokenSym **table_ident;
ST_तथ्य पूर्णांक pp_व्यंजक;

/* ------------------------------------------------------------------------- */

अटल TokenSym *hash_ident[TOK_HASH_आकार];
अटल अक्षर token_buf[STRING_MAX_आकार + 1];
अटल CString cstr_buf;
अटल TokenString tokstr_buf;
अटल TokenString unget_buf;
अटल अचिन्हित अक्षर isidnum_table[256 - CH_EOF];
अटल पूर्णांक pp_debug_tok, pp_debug_symv;
अटल पूर्णांक pp_गणक;
अटल व्योम tok_print(स्थिर पूर्णांक *str, स्थिर अक्षर *संदेश, ...);
अटल व्योम अग्र_nomacro(व्योम);
अटल व्योम parse_संख्या(स्थिर अक्षर *p);
अटल व्योम parse_string(स्थिर अक्षर *p, पूर्णांक len);

अटल काष्ठा TinyAlloc *toksym_alloc;
अटल काष्ठा TinyAlloc *tokstr_alloc;

अटल TokenString *macro_ढेर;

अटल स्थिर अक्षर tcc_keywords[] = 
#घोषणा DEF(id, str) str "\0"
#समावेश "tcctok.h"
#अघोषित DEF
;

/* WARNING: the content of this string encodes token numbers */
अटल स्थिर अचिन्हित अक्षर tok_two_chars[] =
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

ST_FUNC व्योम skip(पूर्णांक c)
{
    अगर (tok != c) {
        अक्षर tmp[40];
        pstrcpy(tmp, माप tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    अग्र();
}

ST_FUNC व्योम expect(स्थिर अक्षर *संदेश)
{
    tcc_error("%s expected", संदेश);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#घोषणा USE_TAL

#अगर_अघोषित USE_TAL /* may cause memory leaks after errors */
#घोषणा tal_free(al, p) tcc_free(p)
#घोषणा tal_realloc(al, p, आकार) tcc_realloc(p, आकार)
#घोषणा tal_new(a,b)
#घोषणा tal_delete(a)
#अन्यथा
#अगर !defined(MEM_DEBUG)
#घोषणा tal_free(al, p) tal_free_impl(al, p)
#घोषणा tal_realloc(al, p, आकार) tal_realloc_impl(al, p, आकार)
#घोषणा TAL_DEBUG_PARAMS
#अन्यथा
#घोषणा TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#घोषणा tal_free(al, p) tal_free_impl(al, p, __खाता__, __LINE__)
#घोषणा tal_realloc(al, p, आकार) tal_realloc_impl(al, p, आकार, __खाता__, __LINE__)
#घोषणा TAL_DEBUG_PARAMS , स्थिर अक्षर *sfile, पूर्णांक sline
#पूर्ण_अगर

#घोषणा TOKSYM_TAL_आकार (256 * 1024) /* allocator for TokenSym in table_ident */
#घोषणा TOKSTR_TAL_आकार (256 * 1024) /* allocator for TokenString instances */

प्रकार काष्ठा TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    काष्ठा TinyAlloc *अग्र;
    अचिन्हित nb_allocs;
    अचिन्हित आकार;
#अगर TAL_INFO
    अचिन्हित nb_peak;
    अचिन्हित nb_योग;
    uint8_t *peak_p;
#पूर्ण_अगर
    जोड़ {
        uint8_t बफर[1];
        माप_प्रकार _aligner_;
    };
} TinyAlloc;

प्रकार काष्ठा tal_header_t {
    माप_प्रकार  आकार; /* word align */
#अगर TAL_DEBUG
    पूर्णांक     पंक्ति_अंक; /* negative line_num used for double free check */
    अक्षर    file_name[40];
#पूर्ण_अगर
} tal_header_t;

#घोषणा TAL_ALIGN(आकार) \
    (((आकार) + (माप (माप_प्रकार) - 1)) & ~(माप (माप_प्रकार) - 1))

/* ------------------------------------------------------------------------- */

अटल TinyAlloc *tal_new(TinyAlloc **pal, अचिन्हित आकार)
{
    TinyAlloc *al = tcc_malloc(माप(TinyAlloc) - माप (माप_प्रकार) + आकार);
    al->p = al->बफर;
    al->bufend = al->बफर + आकार;
    al->nb_allocs = 0;
    al->अग्र = *pal, *pal = al;
    al->आकार = al->अग्र ? al->अग्र->आकार : आकार;
#अगर TAL_INFO
    al->nb_peak = 0;
    al->nb_योग = 0;
    al->peak_p = al->p;
#पूर्ण_अगर
    वापस al;
}

अटल व्योम tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *अग्र;

#अगर TAL_INFO
    ख_लिखो(मानक_त्रुटि, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#पूर्ण_अगर
पुच्छ_call:
#अगर TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#अगर TAL_INFO
    ख_लिखो(मानक_त्रुटि, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->बफर, al->nb_peak, al->nb_योग,
            (al->peak_p - al->बफर) * 100.0 / (al->bufend - al->बफर));
#पूर्ण_अगर
    अगर (al->nb_allocs > 0) {
        uint8_t *p;
        ख_लिखो(मानक_त्रुटि, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->बफर;
        जबतक (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            अगर (header->पंक्ति_अंक > 0) {
                ख_लिखो(मानक_त्रुटि, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->पंक्ति_अंक, (पूर्णांक)header->आकार);
            }
            p += header->आकार + माप(tal_header_t);
        }
#अगर TAL_DEBUG == 2
        निकास(2);
#पूर्ण_अगर
    }
#पूर्ण_अगर
    अग्र = al->अग्र;
    tcc_free(al);
    al = अग्र;
    अगर (al)
        जाओ पुच्छ_call;
    *pal = al;
}

अटल व्योम tal_free_impl(TinyAlloc **pal, व्योम *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **शीर्ष = pal;
    tal_header_t *header;

    अगर (!p)
        वापस;
    header = (tal_header_t *)p - 1;
#अगर TAL_DEBUG
    अगर (header->पंक्ति_अंक < 0) {
        ख_लिखो(मानक_त्रुटि, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        ख_लिखो(मानक_त्रुटि, "%s:%d: %d bytes\n",
                header->file_name, (पूर्णांक)-header->पंक्ति_अंक, (पूर्णांक)header->आकार);
    } अन्यथा
        header->पंक्ति_अंक = -header->पंक्ति_अंक;
#पूर्ण_अगर
    al = *pal;
    जबतक ((uint8_t*)p < al->बफर || (uint8_t*)p > al->bufend)
        al = *(pal = &al->अग्र);
    अगर (0 == --al->nb_allocs) {
        *pal = al->अग्र;
        अगर ((al->bufend - al->बफर) > al->आकार) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } अन्यथा {
            /* reset and move to front */
            al->p = al->बफर;
            al->अग्र = *शीर्ष, *शीर्ष = al;
        }
    } अन्यथा अगर ((uint8_t*)p + header->आकार == al->p) {
        al->p = (uint8_t*)header;
    }
}

अटल व्योम *tal_realloc_impl(TinyAlloc **pal, व्योम *p, अचिन्हित आकार TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    व्योम *ret;
    अचिन्हित adj_आकार = TAL_ALIGN(आकार) + माप(tal_header_t);
    TinyAlloc *al = *pal;

    अगर (p) {
        /* reallpc case */
        जबतक ((uint8_t*)p < al->बफर || (uint8_t*)p > al->bufend)
            al = al->अग्र;
        header = (tal_header_t *)p - 1;
        अगर ((uint8_t*)p + header->आकार == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        अगर (al->p + adj_आकार > al->bufend) {
            ret = tal_realloc(pal, 0, आकार);
            स_नकल(ret, p, header->आकार);
            tal_free(pal, p);
            वापस ret;
        } अन्यथा अगर (al->p != (uint8_t*)header) {
            स_नकल((tal_header_t*)al->p + 1, p, header->आकार);
#अगर TAL_DEBUG
            header->पंक्ति_अंक = -header->पंक्ति_अंक;
#पूर्ण_अगर
        }
    } अन्यथा {
        /* new alloc case */
        जबतक (al->p + adj_आकार > al->bufend) {
            al = al->अग्र;
            अगर (!al) {
                अचिन्हित new_आकार = (*pal)->आकार;
                अगर (adj_आकार > new_आकार) {
                    new_आकार = adj_आकार;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_आकार);
                अवरोध;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->आकार = adj_आकार - माप(tal_header_t);
    al->p += adj_आकार;
    ret = header + 1;
#अगर  TAL_DEBUG
    {
        पूर्णांक ofs = म_माप(sfile) + 1 - माप header->file_name;
        म_नकल(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->पंक्ति_अंक = sline;
#अगर TAL_INFO
        अगर (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        अगर (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_योग++;
#पूर्ण_अगर
    }
#पूर्ण_अगर
    वापस ret;
}

#पूर्ण_अगर /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
अटल व्योम cstr_realloc(CString *cstr, पूर्णांक new_आकार)
{
    पूर्णांक आकार;

    आकार = cstr->आकार_allocated;
    अगर (आकार < 8)
        आकार = 8; /* no need to allocate a too small first string */
    जबतक (आकार < new_आकार)
        आकार = आकार * 2;
    cstr->तथ्य = tcc_realloc(cstr->तथ्य, आकार);
    cstr->आकार_allocated = आकार;
}

/* add a byte */
ST_INLN व्योम cstr_ccat(CString *cstr, पूर्णांक ch)
{
    पूर्णांक आकार;
    आकार = cstr->आकार + 1;
    अगर (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    cstr->तथ्य[आकार - 1] = ch;
    cstr->आकार = आकार;
}

ST_INLN अक्षर *unicode_to_utf8 (अक्षर *b, uint32_t Uc)
{
    अगर (Uc<0x80) *b++=Uc;
    अन्यथा अगर (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    अन्यथा अगर (Uc-0xd800u<0x800) जाओ error;
    अन्यथा अगर (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा अगर (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा error: tcc_error("0x%x is not a valid universal character", Uc);
    वापस b;
}

/* add a unicode character expanded into utf8 */
ST_INLN व्योम cstr_u8cat(CString *cstr, पूर्णांक ch)
{
    अक्षर buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC व्योम cstr_cat(CString *cstr, स्थिर अक्षर *str, पूर्णांक len)
{
    पूर्णांक आकार;
    अगर (len <= 0)
        len = म_माप(str) + 1 + len;
    आकार = cstr->आकार + len;
    अगर (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    स_हटाओ(cstr->तथ्य + cstr->आकार, str, len);
    cstr->आकार = आकार;
}

/* add a wide char */
ST_FUNC व्योम cstr_wccat(CString *cstr, पूर्णांक ch)
{
    पूर्णांक आकार;
    आकार = cstr->आकार + माप(nwchar_t);
    अगर (आकार > cstr->आकार_allocated)
        cstr_realloc(cstr, आकार);
    *(nwchar_t *)(cstr->तथ्य + आकार - माप(nwchar_t)) = ch;
    cstr->आकार = आकार;
}

ST_FUNC व्योम cstr_new(CString *cstr)
{
    स_रखो(cstr, 0, माप(CString));
}

/* free string and reset it to NULL */
ST_FUNC व्योम cstr_free(CString *cstr)
{
    tcc_free(cstr->तथ्य);
}

/* reset string to empty */
ST_FUNC व्योम cstr_reset(CString *cstr)
{
    cstr->आकार = 0;
}

ST_FUNC पूर्णांक cstr_vprintf(CString *cstr, स्थिर अक्षर *fmt, बहु_सूची ap)
{
    बहु_सूची v;
    पूर्णांक len, आकार = 80;
    क्रम (;;) {
        आकार += cstr->आकार;
        अगर (आकार > cstr->आकार_allocated)
            cstr_realloc(cstr, आकार);
        आकार = cstr->आकार_allocated - cstr->आकार;
        va_copy(v, ap);
        len = vsnprintf(cstr->तथ्य + cstr->आकार, आकार, fmt, v);
        बहु_पूर्ण(v);
        अगर (len >= 0 && len < आकार)
            अवरोध;
        आकार *= 2;
    }
    cstr->आकार += len;
    वापस len;
}

ST_FUNC पूर्णांक cstr_printf(CString *cstr, स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap; पूर्णांक len;
    बहु_शुरू(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    बहु_पूर्ण(ap);
    वापस len;
}

/* XXX: unicode ? */
अटल व्योम add_char(CString *cstr, पूर्णांक c)
{
    अगर (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    अगर (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } अन्यथा {
        cstr_ccat(cstr, '\\');
        अगर (c == '\n') {
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
अटल TokenSym *tok_alloc_new(TokenSym **pts, स्थिर अक्षर *str, पूर्णांक len)
{
    TokenSym *ts, **ptable;
    पूर्णांक i;

    अगर (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    अगर ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * माप(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, माप(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = शून्य;
    ts->sym_label = शून्य;
    ts->sym_struct = शून्य;
    ts->sym_identifier = शून्य;
    ts->len = len;
    ts->hash_अग्र = शून्य;
    स_नकल(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    वापस ts;
}

#घोषणा TOK_HASH_INIT 1
#घोषणा TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(स्थिर अक्षर *str, पूर्णांक len)
{
    TokenSym *ts, **pts;
    पूर्णांक i;
    अचिन्हित पूर्णांक h;
    
    h = TOK_HASH_INIT;
    क्रम(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((अचिन्हित अक्षर *)str)[i]);
    h &= (TOK_HASH_आकार - 1);

    pts = &hash_ident[h];
    क्रम(;;) {
        ts = *pts;
        अगर (!ts)
            अवरोध;
        अगर (ts->len == len && !स_भेद(ts->str, str, len))
            वापस ts;
        pts = &(ts->hash_अग्र);
    }
    वापस tok_alloc_new(pts, str, len);
}

ST_FUNC पूर्णांक tok_alloc_const(स्थिर अक्षर *str)
{
    वापस tok_alloc(str, म_माप(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC स्थिर अक्षर *get_tok_str(पूर्णांक v, CValue *cv)
{
    अक्षर *p;
    पूर्णांक i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.तथ्य;

    चयन(v) {
    हाल TOK_CINT:
    हाल TOK_CUINT:
    हाल TOK_CLONG:
    हाल TOK_CULONG:
    हाल TOK_CLLONG:
    हाल TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        प्र_लिखो(p, "%llu", (अचिन्हित दीर्घ दीर्घ)cv->i);
        अवरोध;
    हाल TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    हाल TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        अवरोध;
    हाल TOK_PPNUM:
    हाल TOK_PPSTR:
        वापस (अक्षर*)cv->str.तथ्य;
    हाल TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    हाल TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        अगर (v == TOK_STR) {
            len = cv->str.आकार - 1;
            क्रम(i=0;i<len;i++)
                add_char(&cstr_buf, ((अचिन्हित अक्षर *)cv->str.तथ्य)[i]);
        } अन्यथा {
            len = (cv->str.आकार / माप(nwchar_t)) - 1;
            क्रम(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.तथ्य)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        अवरोध;

    हाल TOK_CFLOAT:
        वापस म_नकल(p, "<float>");
    हाल TOK_CDOUBLE:
        वापस म_नकल(p, "<double>");
    हाल TOK_CLDOUBLE:
        वापस म_नकल(p, "<long double>");
    हाल TOK_LINENUM:
        वापस म_नकल(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    हाल TOK_LT:
        v = '<';
        जाओ addv;
    हाल TOK_GT:
        v = '>';
        जाओ addv;
    हाल TOK_DOTS:
        वापस म_नकल(p, "...");
    हाल TOK_A_SHL:
        वापस म_नकल(p, "<<=");
    हाल TOK_A_SAR:
        वापस म_नकल(p, ">>=");
    हाल TOK_EOF:
        वापस म_नकल(p, "<eof>");
    हाल 0: /* anonymous nameless symbols */
        वापस म_नकल(p, "<no name>");
    शेष:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        अगर (v < TOK_IDENT) {
            /* search in two bytes table */
            स्थिर अचिन्हित अक्षर *q = tok_two_chars;
            जबतक (*q) {
                अगर (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    वापस cstr_buf.तथ्य;
                }
                q += 3;
            }
            अगर (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                प्र_लिखो(p, "<\\x%02x>", v);
                अवरोध;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } अन्यथा अगर (v < tok_ident) {
            वापस table_ident[v - TOK_IDENT]->str;
        } अन्यथा अगर (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            प्र_लिखो(p, "L.%u", v - SYM_FIRST_ANOM);
        } अन्यथा {
            /* should never happen */
            वापस शून्य;
        }
        अवरोध;
    }
    वापस cstr_buf.तथ्य;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
अटल पूर्णांक handle_eob(व्योम)
{
    BufferedFile *bf = file;
    पूर्णांक len;

    /* only tries to read if really end of buffer */
    अगर (bf->buf_ptr >= bf->buf_end) {
        अगर (bf->fd >= 0) {
#अगर defined(PARSE_DEBUG)
            len = 1;
#अन्यथा
            len = IO_BUF_आकार;
#पूर्ण_अगर
            len = पढ़ो(bf->fd, bf->बफर, len);
            अगर (len < 0)
                len = 0;
        } अन्यथा {
            len = 0;
        }
        योग_bytes += len;
        bf->buf_ptr = bf->बफर;
        bf->buf_end = bf->बफर + len;
        *bf->buf_end = CH_EOB;
    }
    अगर (bf->buf_ptr < bf->buf_end) {
        वापस bf->buf_ptr[0];
    } अन्यथा {
        bf->buf_ptr = bf->buf_end;
        वापस CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
अटल पूर्णांक अग्र_c(व्योम)
{
    पूर्णांक ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    अगर (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    वापस ch;
}

/* input with '\[\r]\n' handling. */
अटल पूर्णांक handle_stray_noerror(पूर्णांक err)
{
    पूर्णांक ch;
    जबतक ((ch = अग्र_c()) == '\\') {
        ch = अग्र_c();
        अगर (ch == '\n') {
    newl:
            file->पंक्ति_अंक++;
        } अन्यथा {
            अगर (ch == '\r') {
                ch = अग्र_c();
                अगर (ch == '\n')
                    जाओ newl;
                *--file->buf_ptr = '\r';
            }
            अगर (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            वापस *--file->buf_ptr = '\\';
        }
    }
    वापस ch;
}

#घोषणा ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
अटल पूर्णांक handle_bs(uint8_t **p)
{
    पूर्णांक c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    वापस c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
अटल पूर्णांक handle_stray(uint8_t **p)
{
    पूर्णांक c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    वापस c;
}

/* handle the complicated stray case */
#घोषणा PEEKC(c, p)\
{\
    c = *++p;\
    अगर (c == '\\')\
        c = handle_stray(&p); \
}

अटल पूर्णांक skip_spaces(व्योम)
{
    पूर्णांक ch;
    --file->buf_ptr;
    करो {
        ch = ninp();
    } जबतक (isidnum_table[ch - CH_EOF] & IS_SPC);
    वापस ch;
}

/* single line C++ comments */
अटल uint8_t *parse_पंक्ति_comment(uint8_t *p)
{
    पूर्णांक c;
    क्रम(;;) {
        क्रम (;;) {
            c = *++p;
    redo:
            अगर (c == '\n' || c == '\\')
                अवरोध;
            c = *++p;
            अगर (c == '\n' || c == '\\')
                अवरोध;
        }
        अगर (c == '\n')
            अवरोध;
        c = handle_bs(&p);
        अगर (c == CH_EOF)
            अवरोध;
        अगर (c != '\\')
            जाओ redo;
    }
    वापस p;
}

/* C comments */
अटल uint8_t *parse_comment(uint8_t *p)
{
    पूर्णांक c;
    क्रम(;;) {
        /* fast skip loop */
        क्रम(;;) {
            c = *++p;
        redo:
            अगर (c == '\n' || c == '*' || c == '\\')
                अवरोध;
            c = *++p;
            अगर (c == '\n' || c == '*' || c == '\\')
                अवरोध;
        }
        /* now we can handle all the cases */
        अगर (c == '\n') {
            file->पंक्ति_अंक++;
        } अन्यथा अगर (c == '*') {
            करो {
                c = *++p;
            } जबतक (c == '*');
            अगर (c == '\\')
                c = handle_bs(&p);
            अगर (c == '/')
                अवरोध;
            जाओ check_eof;
        } अन्यथा {
            c = handle_bs(&p);
        check_eof:
            अगर (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            अगर (c != '\\')
                जाओ redo;
        }
    }
    वापस p + 1;
}

/* parse a string without interpreting escapes */
अटल uint8_t *parse_pp_string(uint8_t *p, पूर्णांक sep, CString *str)
{
    पूर्णांक c;
    क्रम(;;) {
        c = *++p;
    redo:
        अगर (c == sep) {
            अवरोध;
        } अन्यथा अगर (c == '\\') {
            c = handle_bs(&p);
            अगर (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } अन्यथा अगर (c == '\\') {
                अगर (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                अगर (c == '\\') {
                    c = handle_bs(&p);
                    अगर (c == CH_EOF)
                        जाओ unterminated_string;
                }
                जाओ add_char;
            } अन्यथा {
                जाओ redo;
            }
        } अन्यथा अगर (c == '\n') {
        add_lf:
            अगर (ACCEPT_LF_IN_STRINGS) {
                file->पंक्ति_अंक++;
                जाओ add_char;
            } अन्यथा अगर (str) { /* not skipping */
                जाओ unterminated_string;
            } अन्यथा {
                //tcc_warning("missing terminating %c character", sep);
                वापस p;
            }
        } अन्यथा अगर (c == '\r') {
            c = *++p;
            अगर (c == '\\')
                c = handle_bs(&p);
            अगर (c == '\n')
                जाओ add_lf;
            अगर (c == CH_EOF)
                जाओ unterminated_string;
            अगर (str)
                cstr_ccat(str, '\r');
            जाओ redo;
        } अन्यथा {
        add_char:
            अगर (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    वापस p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
अटल व्योम preprocess_skip(व्योम)
{
    पूर्णांक a, start_of_पंक्ति, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_पंक्ति = 1;
    in_warn_or_error = 0;
    क्रम(;;) {
        c = *p;
        चयन(c) {
        हाल ' ':
        हाल '\t':
        हाल '\f':
        हाल '\v':
        हाल '\r':
            p++;
            जारी;
        हाल '\n':
            file->पंक्ति_अंक++;
            p++;
            जाओ redo_start;
        हाल '\\':
            c = handle_bs(&p);
            अगर (c == CH_EOF)
                expect("#endif");
            अगर (c == '\\')
                ++p;
            जारी;
        /* skip strings */
        हाल '\"':
        हाल '\'':
            अगर (in_warn_or_error)
                जाओ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, शून्य);
            अवरोध;
        /* skip comments */
        हाल '/':
            अगर (in_warn_or_error)
                जाओ _default;
            ++p;
            c = handle_bs(&p);
            अगर (c == '*') {
                p = parse_comment(p);
            } अन्यथा अगर (c == '/') {
                p = parse_पंक्ति_comment(p);
            }
            जारी;
        हाल '#':
            p++;
            अगर (start_of_पंक्ति) {
                file->buf_ptr = p;
                अग्र_nomacro();
                p = file->buf_ptr;
                अगर (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    जाओ the_end;
                अगर (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                अन्यथा अगर (tok == TOK_ENDIF)
                    a--;
                अन्यथा अगर( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                अन्यथा अगर (tok == TOK_LINEFEED)
                    जाओ redo_start;
                अन्यथा अगर (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_पंक्ति_comment(p - 1);
            }
#अगर !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            अन्यथा अगर (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_पंक्ति_comment(p - 1);
#अन्यथा
            /* ARM/ARM64 assembly uses '#' for constants */
#पूर्ण_अगर
            अवरोध;
_default:
        शेष:
            p++;
            अवरोध;
        }
        start_of_पंक्ति = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#अगर 0
/* return the number of additional 'ints' necessary to store the
   token */
अटल अंतरभूत पूर्णांक tok_आकार(स्थिर पूर्णांक *p)
{
    चयन(*p) {
        /* 4 bytes */
    हाल TOK_CINT:
    हाल TOK_CUINT:
    हाल TOK_CCHAR:
    हाल TOK_LCHAR:
    हाल TOK_CFLOAT:
    हाल TOK_LINENUM:
        वापस 1 + 1;
    हाल TOK_STR:
    हाल TOK_LSTR:
    हाल TOK_PPNUM:
    हाल TOK_PPSTR:
        वापस 1 + 1 + (p[1] + 3) / 4;
    हाल TOK_CLONG:
    हाल TOK_CULONG:
	वापस 1 + LONG_आकार / 4;
    हाल TOK_CDOUBLE:
    हाल TOK_CLLONG:
    हाल TOK_CULLONG:
        वापस 1 + 2;
    हाल TOK_CLDOUBLE:
        वापस 1 + LDOUBLE_शब्दगण;
    शेष:
        वापस 1 + 0;
    }
}
#पूर्ण_अगर

/* token string handling */
ST_INLN व्योम tok_str_new(TokenString *s)
{
    s->str = शून्य;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_पंक्ति_अंक = -1;
}

ST_FUNC TokenString *tok_str_alloc(व्योम)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, माप *str);
    tok_str_new(str);
    वापस str;
}

ST_FUNC व्योम tok_str_free_str(पूर्णांक *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC व्योम tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC पूर्णांक *tok_str_realloc(TokenString *s, पूर्णांक new_आकार)
{
    पूर्णांक *str, आकार;

    आकार = s->allocated_len;
    अगर (आकार < 16)
        आकार = 16;
    जबतक (आकार < new_आकार)
        आकार = आकार * 2;
    अगर (आकार > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, आकार * माप(पूर्णांक));
        s->allocated_len = आकार;
        s->str = str;
    }
    वापस s->str;
}

ST_FUNC व्योम tok_str_add(TokenString *s, पूर्णांक t)
{
    पूर्णांक len, *str;

    len = s->len;
    str = s->str;
    अगर (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC व्योम begin_macro(TokenString *str, पूर्णांक alloc)
{
    str->alloc = alloc;
    str->पूर्व = macro_ढेर;
    str->पूर्व_ptr = macro_ptr;
    str->save_पंक्ति_अंक = file->पंक्ति_अंक;
    macro_ptr = str->str;
    macro_ढेर = str;
}

ST_FUNC व्योम end_macro(व्योम)
{
    TokenString *str = macro_ढेर;
    macro_ढेर = str->पूर्व;
    macro_ptr = str->पूर्व_ptr;
    file->पंक्ति_अंक = str->save_पंक्ति_अंक;
    अगर (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } अन्यथा {
        अगर (str->alloc == 2)
            str->str = शून्य; /* don't free */
        tok_str_free(str);
    }
}

अटल व्योम tok_str_add2(TokenString *s, पूर्णांक t, CValue *cv)
{
    पूर्णांक len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    अगर (len + TOK_MAX_आकार >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_आकार + 1);
    str[len++] = t;
    चयन(t) {
    हाल TOK_CINT:
    हाल TOK_CUINT:
    हाल TOK_CCHAR:
    हाल TOK_LCHAR:
    हाल TOK_CFLOAT:
    हाल TOK_LINENUM:
#अगर LONG_आकार == 4
    हाल TOK_CLONG:
    हाल TOK_CULONG:
#पूर्ण_अगर
        str[len++] = cv->tab[0];
        अवरोध;
    हाल TOK_PPNUM:
    हाल TOK_PPSTR:
    हाल TOK_STR:
    हाल TOK_LSTR:
        {
            /* Insert the string into the int array. */
            माप_प्रकार nb_शब्दगण =
                1 + (cv->str.आकार + माप(पूर्णांक) - 1) / माप(पूर्णांक);
            अगर (len + nb_शब्दगण >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_शब्दगण + 1);
            str[len] = cv->str.आकार;
            स_नकल(&str[len + 1], cv->str.तथ्य, cv->str.आकार);
            len += nb_शब्दगण;
        }
        अवरोध;
    हाल TOK_CDOUBLE:
    हाल TOK_CLLONG:
    हाल TOK_CULLONG:
#अगर LONG_आकार == 8
    हाल TOK_CLONG:
    हाल TOK_CULONG:
#पूर्ण_अगर
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        अवरोध;
    हाल TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        अगर (LDOUBLE_शब्दगण >= 3)
        str[len++] = cv->tab[2];
        अगर (LDOUBLE_शब्दगण >= 4)
        str[len++] = cv->tab[3];
    शेष:
        अवरोध;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC व्योम tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    अगर (file->पंक्ति_अंक != s->last_पंक्ति_अंक) {
        s->last_पंक्ति_अंक = file->पंक्ति_अंक;
        cval.i = s->last_पंक्ति_अंक;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
अटल व्योम tok_str_add2_spc(TokenString *s, पूर्णांक t, CValue *cv)
{
    अगर (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
अटल अंतरभूत व्योम tok_get(पूर्णांक *t, स्थिर पूर्णांक **pp, CValue *cv)
{
    स्थिर पूर्णांक *p = *pp;
    पूर्णांक n, *tab;

    tab = cv->tab;
    चयन(*t = *p++) {
#अगर LONG_आकार == 4
    हाल TOK_CLONG:
#पूर्ण_अगर
    हाल TOK_CINT:
    हाल TOK_CCHAR:
    हाल TOK_LCHAR:
    हाल TOK_LINENUM:
        cv->i = *p++;
        अवरोध;
#अगर LONG_आकार == 4
    हाल TOK_CULONG:
#पूर्ण_अगर
    हाल TOK_CUINT:
        cv->i = (अचिन्हित)*p++;
        अवरोध;
    हाल TOK_CFLOAT:
	tab[0] = *p++;
	अवरोध;
    हाल TOK_STR:
    हाल TOK_LSTR:
    हाल TOK_PPNUM:
    हाल TOK_PPSTR:
        cv->str.आकार = *p++;
        cv->str.तथ्य = (अक्षर*)p;
        p += (cv->str.आकार + माप(पूर्णांक) - 1) / माप(पूर्णांक);
        अवरोध;
    हाल TOK_CDOUBLE:
    हाल TOK_CLLONG:
    हाल TOK_CULLONG:
#अगर LONG_आकार == 8
    हाल TOK_CLONG:
    हाल TOK_CULONG:
#पूर्ण_अगर
        n = 2;
        जाओ copy;
    हाल TOK_CLDOUBLE:
        n = LDOUBLE_शब्दगण;
    copy:
        करो
            *tab++ = *p++;
        जबतक (--n);
        अवरोध;
    शेष:
        अवरोध;
    }
    *pp = p;
}

#अगर 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#अन्यथा
# define TOK_GET(t,p,c) करो { \
    पूर्णांक _t = **(p); \
    अगर (TOK_HAS_मूल्य(_t)) \
        tok_get(t, p, c); \
    अन्यथा \
        *(t) = _t, ++*(p); \
    } जबतक (0)
#पूर्ण_अगर

अटल पूर्णांक macro_is_equal(स्थिर पूर्णांक *a, स्थिर पूर्णांक *b)
{
    CValue cv;
    पूर्णांक t;

    अगर (!a || !b)
        वापस 1;

    जबतक (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        अगर (म_भेद(tokcstr.तथ्य, get_tok_str(t, &cv)))
            वापस 0;
    }
    वापस !(*a || *b);
}

/* defines handling */
ST_INLN व्योम define_धकेलो(पूर्णांक v, पूर्णांक macro_type, पूर्णांक *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_ढेर, v, macro_type, 0);
    s->d = str;
    s->अग्र = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    अगर (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, शून्य));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC व्योम define_undef(Sym *s)
{
    पूर्णांक v = s->v;
    अगर (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = शून्य;
}

ST_INLN Sym *define_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    अगर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        वापस शून्य;
    वापस table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC व्योम free_defines(Sym *b)
{
    जबतक (define_ढेर != b) {
        Sym *शीर्ष = define_ढेर;
        define_ढेर = शीर्ष->पूर्व;
        tok_str_free_str(शीर्ष->d);
        define_undef(शीर्ष);
        sym_free(शीर्ष);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
अटल व्योम maybe_run_test(TCCState *s)
{
    स्थिर अक्षर *p;
    अगर (s->include_ढेर_ptr != s->include_ढेर)
        वापस;
    p = get_tok_str(tok, शून्य);
    अगर (0 != स_भेद(p, "test_", 5))
        वापस;
    अगर (0 != --s->run_test)
        वापस;
    ख_लिखो(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), ख_साफ(s->ppfp);
    define_धकेलो(tok, MACRO_OBJ, शून्य, शून्य);
}

ST_FUNC व्योम skip_to_eol(पूर्णांक warn)
{
    अगर (tok == TOK_LINEFEED)
        वापस;
    अगर (warn)
        tcc_warning("extra tokens after directive");
    जबतक (macro_ढेर)
        end_macro();
    file->buf_ptr = parse_पंक्ति_comment(file->buf_ptr - 1);
    अग्र_nomacro();
}

अटल CachedInclude *
खोज_cached_include(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक add);

अटल पूर्णांक parse_include(TCCState *s1, पूर्णांक do_अग्र, पूर्णांक test)
{
    पूर्णांक c, i;
    अक्षर name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    अगर (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.आकार;
        pstrncpy(name, माप name, tokcstr.तथ्य, i);
        अग्र_nomacro();
    } अन्यथा {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        क्रम (;;) {
            अग्र();
            p = name, i = म_माप(p) - 1;
            अगर (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                अवरोध;
            अगर (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, माप name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        स_हटाओ(p, p + 1, i - 1), p[i - 1] = 0;
    }

    अगर (!test)
        skip_to_eol(1);

    i = do_अग्र ? file->include_अग्र_सूचकांक : -1;
    क्रम (;;) {
        ++i;
        अगर (i == 0) {
            /* check absolute include path */
            अगर (!IS_ABSPATH(name))
                जारी;
            buf[0] = '\0';
        } अन्यथा अगर (i == 1) {
            /* search in file's dir if "header.h" */
            अगर (c != '\"')
                जारी;
            p = file->true_filename;
            pstrncpy(buf, माप buf, p, tcc_basename(p) - p);
        } अन्यथा {
            पूर्णांक j = i - 2, k = j - s1->nb_include_paths;
            अगर (k < 0)
                p = s1->include_paths[j];
            अन्यथा अगर (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            अन्यथा अगर (test)
                वापस 0;
            अन्यथा
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, माप buf, p);
            pstrcat(buf, माप buf, "/");
        }
        pstrcat(buf, माप buf, name);
        e = खोज_cached_include(s1, buf, 0);
        अगर (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#अगर_घोषित INC_DEBUG
            म_लिखो("%s: skipping cached %s\n", file->filename, buf);
#पूर्ण_अगर
            अगर ((s1->verbose | 1) == 3) /* -vv[v] */
                म_लिखो("=> %*s%s\n",
                   (पूर्णांक)(s1->include_ढेर_ptr - s1->include_ढेर), "", buf);
            वापस 1;
        }
        अगर (tcc_open(s1, buf) >= 0)
            अवरोध;
    }

    अगर (test) {
        tcc_close();
    } अन्यथा {
        अगर (s1->include_ढेर_ptr >= s1->include_ढेर + INCLUDE_ढेर_आकार)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ढेर_ptr++ = file->पूर्व;
        file->include_अग्र_सूचकांक = i;
#अगर_घोषित INC_DEBUG
        म_लिखो("%s: including %s\n", file->पूर्व->filename, file->filename);
#पूर्ण_अगर
        /* update target deps */
        अगर (s1->gen_deps) {
            BufferedFile *bf = file;
            जबतक (i == 1 && (bf = bf->पूर्व))
                i = bf->include_अग्र_सूचकांक;
            /* skip system include files */
            अगर (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    वापस 1;
}

/* eval an expression for #if/#elif */
अटल पूर्णांक व्यंजक_preprocess(TCCState *s1)
{
    पूर्णांक c, t;
    पूर्णांक t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_व्यंजक = 1;
    जबतक (1) {
        अग्र(); /* do macro subst */
        t = tok;
        अगर (tok < TOK_IDENT) {
            अगर (tok == TOK_LINEFEED || tok == TOK_EOF)
                अवरोध;
            अगर (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } अन्यथा अगर (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            अग्र();
            t = tok;
            अगर (t == '(') 
                अग्र();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            अगर (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            अगर (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            अगर (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_अग्र)
                c = 1;
            अगर (t == '(') {
                अग्र();
                अगर (tok != ')')
                    expect("')'");
            }
            जाओ c_संख्या;
        } अन्यथा अगर (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_अग्र) {
            t = tok;
            अग्र();
	    अगर (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            अगर (tok != ')')
                expect("')'");
            जाओ c_संख्या;
        } अन्यथा {
            /* if undefined macro, replace with zero */
            c = 0;
        c_संख्या:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    अगर (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_व्यंजक = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    अग्र();
    c = व्यंजक_const();
    अगर (tok != TOK_EOF)
        tcc_error("...");
    pp_व्यंजक = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    वापस c != 0;
}

ST_FUNC व्योम pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_व्यंजक, 0));
    macro_ptr = macro_ढेर->str;
    जबतक (अग्र(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC व्योम parse_define(व्योम)
{
    Sym *s, *first, **ps;
    पूर्णांक v, t, varg, is_vaargs, t0;
    पूर्णांक saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    अगर (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = शून्य;
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
    अगर (tok == '(') {
        पूर्णांक dotid = set_idnum('.', 0);
        अग्र_nomacro();
        ps = &first;
        अगर (tok != ')') क्रम (;;) {
            varg = tok;
            अग्र_nomacro();
            is_vaargs = 0;
            अगर (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } अन्यथा अगर (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                अग्र_nomacro();
            }
            अगर (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ढेर, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->अग्र;
            अगर (tok == ')')
                अवरोध;
            अगर (tok != ',' || is_vaargs)
                जाओ bad_list;
            अग्र_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        अग्र_nomacro();
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
    जबतक (tok != TOK_LINEFEED && tok != TOK_EOF) {
        अगर (is_space(tok)) {
            str.need_spc |= 1;
        } अन्यथा {
            अगर (TOK_TWOSHARPS == tok) {
                अगर (0 == t0)
                    जाओ bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        अग्र_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_add(&str, 0);
    अगर (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_धकेलो(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

अटल CachedInclude *खोज_cached_include(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक add)
{
    स्थिर अक्षर *s, *basename;
    अचिन्हित पूर्णांक h;
    CachedInclude *e;
    पूर्णांक c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    जबतक ((c = (अचिन्हित अक्षर)*s) != 0) {
#अगर_घोषित _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#अन्यथा
        h = TOK_HASH_FUNC(h, c);
#पूर्ण_अगर
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_आकार - 1);

    i = s1->cached_includes_hash[h];
    क्रम(;;) {
        अगर (i == 0)
            अवरोध;
        e = s1->cached_includes[i - 1];
        अगर (0 == PATHCMP(filename, e->filename))
            वापस e;
        अगर (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            वापस e;
        i = e->hash_अग्र;
    }
    अगर (!add)
        वापस शून्य;

    e = tcc_malloc(माप(CachedInclude) + (len = म_माप(filename)));
    स_नकल(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_अग्र = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#अगर_घोषित INC_DEBUG
    म_लिखो("adding cached '%s'\n", filename);
#पूर्ण_अगर
    वापस e;
}

अटल पूर्णांक pragma_parse(TCCState *s1)
{
    अग्र_nomacro();
    अगर (tok == TOK_धकेलो_macro || tok == TOK_निकालो_macro) {
        पूर्णांक t = tok, v;
        Sym *s;

        अगर (अग्र(), tok != '(')
            जाओ pragma_err;
        अगर (अग्र(), tok != TOK_STR)
            जाओ pragma_err;
        v = tok_alloc(tokc.str.तथ्य, tokc.str.आकार - 1)->tok;
        अगर (अग्र(), tok != ')')
            जाओ pragma_err;
        अगर (t == TOK_धकेलो_macro) {
            जबतक (शून्य == (s = define_find(v)))
                define_धकेलो(v, 0, शून्य, शून्य);
            s->type.ref = s; /* set push boundary */
        } अन्यथा {
            क्रम (s = define_ढेर; s; s = s->पूर्व)
                अगर (s->v == v && s->type.ref == s) {
                    s->type.ref = शून्य;
                    अवरोध;
                }
        }
        अगर (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : शून्य;
        अन्यथा
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } अन्यथा अगर (tok == TOK_once) {
        खोज_cached_include(s1, file->true_filename, 1)->once = 1;

    } अन्यथा अगर (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        वापस 1;

    } अन्यथा अगर (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        अग्र();
        skip('(');
        अगर (tok == TOK_ASM_निकालो) {
            अग्र();
            अगर (s1->pack_ढेर_ptr <= s1->pack_ढेर) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ढेर_ptr--;
        } अन्यथा {
            पूर्णांक val = 0;
            अगर (tok != ')') {
                अगर (tok == TOK_ASM_धकेलो) {
                    अग्र();
                    अगर (s1->pack_ढेर_ptr >= s1->pack_ढेर + PACK_ढेर_आकार - 1)
                        जाओ stk_error;
                    val = *s1->pack_ढेर_ptr++;
                    अगर (tok != ',')
                        जाओ pack_set;
                    अग्र();
                }
                अगर (tok != TOK_CINT)
                    जाओ pragma_err;
                val = tokc.i;
                अगर (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    जाओ pragma_err;
                अग्र();
            }
        pack_set:
            *s1->pack_ढेर_ptr = val;
        }
        अगर (tok != ')')
            जाओ pragma_err;

    } अन्यथा अगर (tok == TOK_comment) {
        अक्षर *p; पूर्णांक t;
        अग्र();
        skip('(');
        t = tok;
        अग्र();
        skip(',');
        अगर (tok != TOK_STR)
            जाओ pragma_err;
        p = tcc_strdup(tokc.str.तथ्य);
        अग्र();
        अगर (tok != ')')
            जाओ pragma_err;
        अगर (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } अन्यथा {
            अगर (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } अन्यथा {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        वापस 0;
    }
    अग्र();
    वापस 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC व्योम tccpp_putfile(स्थिर अक्षर *filename)
{
    अक्षर buf[1024];
    buf[0] = 0;
    अगर (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, माप buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, माप buf, filename);
#अगर_घोषित _WIN32
    normalize_slashes(buf);
#पूर्ण_अगर
    अगर (0 == म_भेद(file->filename, buf))
        वापस;
    //printf("new file '%s'\n", buf);
    अगर (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, माप file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC व्योम preprocess(पूर्णांक is_bof)
{
    TCCState *s1 = tcc_state;
    पूर्णांक c, n, saved_parse_flags;
    अक्षर buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_अंक
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    अग्र_nomacro();
 redo:
    चयन(tok) {
    हाल TOK_DEFINE:
        pp_debug_tok = tok;
        अग्र_nomacro();
        pp_debug_symv = tok;
        parse_define();
        अवरोध;
    हाल TOK_UNDEF:
        pp_debug_tok = tok;
        अग्र_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        अगर (s)
            define_undef(s);
        अग्र_nomacro();
        अवरोध;
    हाल TOK_INCLUDE:
    हाल TOK_INCLUDE_अग्र:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        जाओ the_end;
    हाल TOK_IFNDEF:
        c = 1;
        जाओ do_ifdef;
    हाल TOK_IF:
        c = व्यंजक_preprocess(s1);
        जाओ do_if;
    हाल TOK_IFDEF:
        c = 0;
    do_ifdef:
        अग्र_nomacro();
        अगर (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        अगर (is_bof) {
            अगर (c) {
#अगर_घोषित INC_DEBUG
                म_लिखो("#ifndef %s\n", get_tok_str(tok, शून्य));
#पूर्ण_अगर
                file->ifndef_macro = tok;
            }
        }
        अगर (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_अग्र)
            c ^= 1;
        अग्र_nomacro();
    do_if:
        अगर (s1->ifdef_ढेर_ptr >= s1->ifdef_ढेर + IFDEF_ढेर_आकार)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ढेर_ptr++ = c;
        जाओ test_skip;
    हाल TOK_ELSE:
        अग्र_nomacro();
        अगर (s1->ifdef_ढेर_ptr == s1->ifdef_ढेर)
            tcc_error("#else without matching #if");
        अगर (s1->ifdef_ढेर_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ढेर_ptr[-1] ^= 3);
        जाओ test_else;
    हाल TOK_ELIF:
        अगर (s1->ifdef_ढेर_ptr == s1->ifdef_ढेर)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ढेर_ptr[-1];
        अगर (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        अगर (c == 1) {
            skip_to_eol(0);
            c = 0;
        } अन्यथा {
            c = व्यंजक_preprocess(s1);
            s1->ifdef_ढेर_ptr[-1] = c;
        }
    test_else:
        अगर (s1->ifdef_ढेर_ptr == file->ifdef_ढेर_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        अगर (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            जाओ redo;
        }
        अवरोध;
    हाल TOK_ENDIF:
        अग्र_nomacro();
        अगर (s1->ifdef_ढेर_ptr <= file->ifdef_ढेर_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ढेर_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        अगर (file->ifndef_macro &&
            s1->ifdef_ढेर_ptr == file->ifdef_ढेर_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        अवरोध;

    हाल TOK_पंक्ति:
        parse_flags &= ~PARSE_FLAG_TOK_अंक;
        अग्र();
        अगर (tok != TOK_PPNUM) {
    पंक्ति_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        जाओ पंक्ति_अंक_2;
    हाल TOK_PPNUM:
        अगर (parse_flags & PARSE_FLAG_ASM_FILE)
            जाओ ignore;
        c = 0; /* no error with extra tokens */
    पंक्ति_अंक_2:
        क्रम (n = 0, q = tokc.str.तथ्य; *q; ++q) {
            अगर (!isnum(*q))
                जाओ पंक्ति_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        अग्र();
        अगर (tok != TOK_LINEFEED) {
            अगर (tok != TOK_PPSTR || tokc.str.तथ्य[0] != '"')
                जाओ पंक्ति_err;
            tokc.str.तथ्य[tokc.str.आकार - 2] = 0;
            tccpp_putfile(tokc.str.तथ्य + 1);
            अग्र();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        अगर (file->fd > 0)
            योग_पंक्तियाँ += file->पंक्ति_अंक - n;
        file->पंक्ति_अंक = n;
        अवरोध;

    हाल TOK_ERROR:
    हाल TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        जबतक (c != '\n' && c != CH_EOF) {
            अगर ((q - buf) < माप(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        अगर (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        अन्यथा
            tcc_warning("#warning %s", buf);
        अग्र_nomacro();
        अवरोध;
    }
    हाल TOK_PRAGMA:
        अगर (!pragma_parse(s1))
            जाओ ignore;
        अवरोध;
    हाल TOK_LINEFEED:
        जाओ the_end;
    शेष:
        /* ignore gas line comment in an 'S' file. */
        अगर (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            जाओ ignore;
        अगर (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            जाओ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        जाओ the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
अटल व्योम parse_escape_string(CString *outstr, स्थिर uint8_t *buf, पूर्णांक is_long)
{
    पूर्णांक c, n, i;
    स्थिर uint8_t *p;

    p = buf;
    क्रम(;;) {
        c = *p;
        अगर (c == '\0')
            अवरोध;
        अगर (c == '\\') {
            p++;
            /* escape */
            c = *p;
            चयन(c) {
            हाल '0': हाल '1': हाल '2': हाल '3':
            हाल '4': हाल '5': हाल '6': हाल '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                अगर (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    अगर (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                जाओ add_char_nonext;
            हाल 'x': i = 0; जाओ parse_hex_or_ucn;
            हाल 'u': i = 4; जाओ parse_hex_or_ucn;
            हाल 'U': i = 8; जाओ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                करो {
                    c = *p;
                    अगर (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    अन्यथा अगर (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    अन्यथा अगर (isnum(c))
                        c = c - '0';
                    अन्यथा अगर (i >= 0)
                        expect("more hex digits in universal-character-name");
                    अन्यथा
                        जाओ add_hex_or_ucn;
                    n = (अचिन्हित) n * 16 + c;
                    p++;
                } जबतक (--i);
		अगर (is_long) {
    add_hex_or_ucn:
                    c = n;
		    जाओ add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                जारी;
            हाल 'a':
                c = '\a';
                अवरोध;
            हाल 'b':
                c = '\b';
                अवरोध;
            हाल 'f':
                c = '\f';
                अवरोध;
            हाल 'n':
                c = '\n';
                अवरोध;
            हाल 'r':
                c = '\r';
                अवरोध;
            हाल 't':
                c = '\t';
                अवरोध;
            हाल 'v':
                c = '\v';
                अवरोध;
            हाल 'e':
                अगर (!gnu_ext)
                    जाओ invalid_escape;
                c = 27;
                अवरोध;
            हाल '\'':
            हाल '\"':
            हाल '\\': 
            हाल '?':
                अवरोध;
            शेष:
            invalid_escape:
                अगर (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                अन्यथा
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                अवरोध;
            }
        } अन्यथा अगर (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            पूर्णांक cont; /* count of continuation bytes */
            पूर्णांक skip; /* how many bytes should skip when error occurred */
            पूर्णांक i;

            /* decode leading byte */
            अगर (c < 0xC2) {
	            skip = 1; जाओ invalid_utf8_sequence;
            } अन्यथा अगर (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } अन्यथा अगर (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } अन्यथा अगर (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } अन्यथा {
	            skip = 1; जाओ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            क्रम (i = 1; i <= cont; i++) {
                पूर्णांक l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                अगर (i == 1) {
                    चयन (c) {
                    हाल 0xE0: l = 0xA0; अवरोध;
                    हाल 0xED: h = 0x9F; अवरोध;
                    हाल 0xF0: l = 0x90; अवरोध;
                    हाल 0xF4: h = 0x8F; अवरोध;
                    }
                }

                अगर (p[i] < l || p[i] > h) {
                    skip = i; जाओ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            जाओ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            जाओ add_char_nonext;

        }
        p++;
    add_char_nonext:
        अगर (!is_long)
            cstr_ccat(outstr, c);
        अन्यथा {
#अगर_घोषित TCC_TARGET_PE
            /* store as UTF-16 */
            अगर (c < 0x10000) {
                cstr_wccat(outstr, c);
            } अन्यथा {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#अन्यथा
            cstr_wccat(outstr, c);
#पूर्ण_अगर
        }
    }
    /* add a trailing '\0' */
    अगर (!is_long)
        cstr_ccat(outstr, '\0');
    अन्यथा
        cstr_wccat(outstr, '\0');
}

अटल व्योम parse_string(स्थिर अक्षर *s, पूर्णांक len)
{
    uint8_t buf[1000], *p = buf;
    पूर्णांक is_long, sep;

    अगर ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    अगर (len >= माप buf)
        p = tcc_malloc(len + 1);
    स_नकल(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    अगर (p != buf)
        tcc_free(p);

    अगर (sep == '\'') {
        पूर्णांक char_आकार, i, n, c;
        /* XXX: make it portable */
        अगर (!is_long)
            tok = TOK_CCHAR, char_आकार = 1;
        अन्यथा
            tok = TOK_LCHAR, char_आकार = माप(nwchar_t);
        n = tokcstr.आकार / char_आकार - 1;
        अगर (n < 1)
            tcc_error("empty character constant");
        अगर (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        क्रम (c = i = 0; i < n; ++i) {
            अगर (is_long)
                c = ((nwchar_t *)tokcstr.तथ्य)[i];
            अन्यथा
                c = (c << 8) | ((अक्षर *)tokcstr.तथ्य)[i];
        }
        tokc.i = c;
    } अन्यथा {
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.तथ्य = tokcstr.तथ्य;
        अगर (!is_long)
            tok = TOK_STR;
        अन्यथा
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#घोषणा BN_आकार 4

/* bn = (bn << shift) | or_val */
अटल पूर्णांक bn_lshift(अचिन्हित पूर्णांक *bn, पूर्णांक shift, पूर्णांक or_val)
{
    पूर्णांक i;
    अचिन्हित पूर्णांक v;
    अगर (bn[BN_आकार - 1] >> (32 - shift))
	वापस shift;
    क्रम(i=0;i<BN_आकार;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    वापस 0;
}

अटल व्योम bn_zero(अचिन्हित पूर्णांक *bn)
{
    पूर्णांक i;
    क्रम(i=0;i<BN_आकार;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
अटल व्योम parse_संख्या(स्थिर अक्षर *p)
{
    पूर्णांक b, t, shift, frac_bits, s, exp_val, ch;
    अक्षर *q;
    अचिन्हित पूर्णांक bn[BN_आकार];
    दीर्घ द्विगुन d;

    /*संख्या*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    अगर (t == '.') {
        जाओ float_frac_parse;
    } अन्यथा अगर (t == '0') {
        अगर (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } अन्यथा अगर (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    जबतक (1) {
        अगर (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        अन्यथा अगर (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        अन्यथा अगर (isnum(ch))
            t = ch - '0';
        अन्यथा
            अवरोध;
        अगर (t >= b)
            अवरोध;
        अगर (q >= token_buf + STRING_MAX_आकार) {
        अंक_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    अगर (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        अगर (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            अगर (b == 16)
                shift = 4;
            अन्यथा 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            जबतक (1) {
                t = *q++;
                अगर (t == '\0') {
                    अवरोध;
                } अन्यथा अगर (t >= 'a') {
                    t = t - 'a' + 10;
                } अन्यथा अगर (t >= 'A') {
                    t = t - 'A' + 10;
                } अन्यथा {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            अगर (ch == '.') {
                ch = *p++;
                जबतक (1) {
                    t = ch;
                    अगर (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } अन्यथा अगर (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } अन्यथा अगर (t >= '0' && t <= '9') {
                        t = t - '0';
                    } अन्यथा {
                        अवरोध;
                    }
                    अगर (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            अगर (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            अगर (ch == '+') {
                ch = *p++;
            } अन्यथा अगर (ch == '-') {
                s = -1;
                ch = *p++;
            }
            अगर (ch < '0' || ch > '9')
                expect("exponent digits");
            जबतक (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		अगर (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (दीर्घ द्विगुन)bn[3] * 79228162514264337593543950336.0L +
	        (दीर्घ द्विगुन)bn[2] * 18446744073709551616.0L +
	        (दीर्घ द्विगुन)bn[1] * 4294967296.0L +
	        (दीर्घ द्विगुन)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            अगर (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (भग्न)d;
            } अन्यथा अगर (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = (द्विगुन)d;
            }
        } अन्यथा {
            /* decimal floats */
            अगर (ch == '.') {
                अगर (q >= token_buf + STRING_MAX_आकार)
                    जाओ अंक_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                जबतक (ch >= '0' && ch <= '9') {
                    अगर (q >= token_buf + STRING_MAX_आकार)
                        जाओ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            अगर (ch == 'e' || ch == 'E') {
                अगर (q >= token_buf + STRING_MAX_आकार)
                    जाओ अंक_too_long;
                *q++ = ch;
                ch = *p++;
                अगर (ch == '-' || ch == '+') {
                    अगर (q >= token_buf + STRING_MAX_आकार)
                        जाओ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                अगर (ch < '0' || ch > '9')
                    expect("exponent digits");
                जबतक (ch >= '0' && ch <= '9') {
                    अगर (q >= token_buf + STRING_MAX_आकार)
                        जाओ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            त्रुटि_सं = 0;
            अगर (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, शून्य);
            } अन्यथा अगर (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, शून्य);
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = म_से_भग्न(token_buf, शून्य);
            }
        }
    } अन्यथा {
        अचिन्हित दीर्घ दीर्घ n, n1;
        पूर्णांक lcount, ucount, ov = 0;
        स्थिर अक्षर *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        अगर (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        जबतक(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            अगर (t == '\0')
                अवरोध;
            अन्यथा अगर (t >= 'a')
                t = t - 'a' + 10;
            अन्यथा अगर (t >= 'A')
                t = t - 'A' + 10;
            अन्यथा
                t = t - '0';
            अगर (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            अगर (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        क्रम(;;) {
            t = toup(ch);
            अगर (t == 'L') {
                अगर (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                अगर (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } अन्यथा अगर (t == 'U') {
                अगर (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } अन्यथा {
                अवरोध;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        अगर (pp_व्यंजक)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        अगर (ucount == 0 && b == 10) {
            अगर (lcount <= (LONG_आकार == 4)) {
                अगर (n >= 0x80000000U)
                    lcount = (LONG_आकार == 4) + 1;
            }
            अगर (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } अन्यथा {
            अगर (lcount <= (LONG_आकार == 4)) {
                अगर (n >= 0x100000000ULL)
                    lcount = (LONG_आकार == 4) + 1;
                अन्यथा अगर (n >= 0x80000000U)
                    ucount = 1;
            }
            अगर (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        अगर (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	अगर (lcount) {
            tok = TOK_CLONG;
            अगर (lcount == 2)
                tok = TOK_CLLONG;
	}
	अगर (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    अगर (ch)
        tcc_error("invalid number");
}


#घोषणा PARSE2(c1, tok1, c2, tok2)              \
    हाल c1:                                    \
        PEEKC(c, p);                            \
        अगर (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } अन्यथा {                                \
            tok = tok1;                         \
        }                                       \
        अवरोध;

/* return next token without macro substitution */
अटल व्योम अग्र_nomacro(व्योम)
{
    पूर्णांक t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    अचिन्हित पूर्णांक h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    चयन(c) {
    हाल ' ':
    हाल '\t':
        tok = c;
        p++;
 maybe_space:
        अगर (parse_flags & PARSE_FLAG_SPACES)
            जाओ keep_tok_flags;
        जबतक (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        जाओ redo_no_start;
    हाल '\f':
    हाल '\v':
    हाल '\r':
        p++;
        जाओ redo_no_start;
    हाल '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        अगर (c == '\\')
            जाओ parse_simple;
        अगर (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            अगर (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                जाओ maybe_newline;
            } अन्यथा अगर (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } अन्यथा अगर (s1->ifdef_ढेर_ptr != file->ifdef_ढेर_ptr) {
                tcc_error("missing #endif");
            } अन्यथा अगर (s1->include_ढेर_ptr == s1->include_ढेर) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } अन्यथा {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                अगर (tok_flags & TOK_FLAG_ENDIF) {
#अगर_घोषित INC_DEBUG
                    म_लिखो("#endif %s\n", get_tok_str(file->ifndef_macro_saved, शून्य));
#पूर्ण_अगर
                    खोज_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ढेर_ptr--;
                p = file->buf_ptr;
                जाओ maybe_newline;
            }
        } अन्यथा {
            जाओ redo_no_start;
        }
        अवरोध;

    हाल '\n':
        file->पंक्ति_अंक++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        अगर (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            जाओ redo_no_start;
        tok = TOK_LINEFEED;
        जाओ keep_tok_flags;

    हाल '#':
        /* XXX: simplify */
        PEEKC(c, p);
        अगर ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            जाओ maybe_newline;
        } अन्यथा {
            अगर (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } अन्यथा {
#अगर !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                अगर (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_पंक्ति_comment(p - 1);
                    जाओ redo_no_start;
                } अन्यथा
#पूर्ण_अगर
                {
                    tok = '#';
                }
            }
        }
        अवरोध;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    हाल '$':
        अगर (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            जाओ parse_simple;

    हाल 'a': हाल 'b': हाल 'c': हाल 'd':
    हाल 'e': हाल 'f': हाल 'g': हाल 'h':
    हाल 'i': हाल 'j': हाल 'k': हाल 'l':
    हाल 'm': हाल 'n': हाल 'o': हाल 'p':
    हाल 'q': हाल 'r': हाल 's': हाल 't':
    हाल 'u': हाल 'v': हाल 'w': हाल 'x':
    हाल 'y': हाल 'z': 
    हाल 'A': हाल 'B': हाल 'C': हाल 'D':
    हाल 'E': हाल 'F': हाल 'G': हाल 'H':
    हाल 'I': हाल 'J': हाल 'K': 
    हाल 'M': हाल 'N': हाल 'O': हाल 'P':
    हाल 'Q': हाल 'R': हाल 'S': हाल 'T':
    हाल 'U': हाल 'V': हाल 'W': हाल 'X':
    हाल 'Y': हाल 'Z': 
    हाल '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        जबतक (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        अगर (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_आकार - 1);
            pts = &hash_ident[h];
            क्रम(;;) {
                ts = *pts;
                अगर (!ts)
                    अवरोध;
                अगर (ts->len == len && !स_भेद(ts->str, p1, len))
                    जाओ token_found;
                pts = &(ts->hash_अग्र);
            }
            ts = tok_alloc_new(pts, (अक्षर *) p1, len);
        token_found: ;
        } अन्यथा {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (अक्षर *) p1, len);
            p--;
            PEEKC(c, p);
            जबतक (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.तथ्य, tokcstr.आकार);
        }
        tok = ts->tok;
        अवरोध;
    हाल 'L':
        t = p[1];
        अगर (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            अगर (c == '\'' || c == '\"') {
                is_long = 1;
                जाओ str_const;
            }
            *--p = c = 'L';
        }
        जाओ parse_ident_fast;

    हाल '0': हाल '1': हाल '2': हाल '3':
    हाल '4': हाल '5': हाल '6': हाल '7':
    हाल '8': हाल '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_अंक:
        cstr_reset(&tokcstr);
        क्रम(;;) {
            cstr_ccat(&tokcstr, t);
            अगर (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((अक्षर*)tokcstr.तथ्य)[0] == '0'
                                && toup(((अक्षर*)tokcstr.तथ्य)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                अवरोध;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.तथ्य = tokcstr.तथ्य;
        tok = TOK_PPNUM;
        अवरोध;

    हाल '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        अगर (isnum(c)) {
            t = '.';
            जाओ parse_अंक;
        } अन्यथा अगर ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))) {
            *--p = c = '.';
            जाओ parse_ident_fast;
        } अन्यथा अगर (c == '.') {
            PEEKC(c, p);
            अगर (c == '.') {
                p++;
                tok = TOK_DOTS;
            } अन्यथा {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } अन्यथा {
            tok = '.';
        }
        अवरोध;
    हाल '\'':
    हाल '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        अगर (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.आकार = tokcstr.आकार;
        tokc.str.तथ्य = tokcstr.तथ्य;
        tok = TOK_PPSTR;
        अवरोध;

    हाल '<':
        PEEKC(c, p);
        अगर (c == '=') {
            p++;
            tok = TOK_LE;
        } अन्यथा अगर (c == '<') {
            PEEKC(c, p);
            अगर (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } अन्यथा {
                tok = TOK_SHL;
            }
        } अन्यथा {
            tok = TOK_LT;
        }
        अवरोध;
    हाल '>':
        PEEKC(c, p);
        अगर (c == '=') {
            p++;
            tok = TOK_GE;
        } अन्यथा अगर (c == '>') {
            PEEKC(c, p);
            अगर (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } अन्यथा {
                tok = TOK_SAR;
            }
        } अन्यथा {
            tok = TOK_GT;
        }
        अवरोध;
        
    हाल '&':
        PEEKC(c, p);
        अगर (c == '&') {
            p++;
            tok = TOK_LAND;
        } अन्यथा अगर (c == '=') {
            p++;
            tok = TOK_A_AND;
        } अन्यथा {
            tok = '&';
        }
        अवरोध;
        
    हाल '|':
        PEEKC(c, p);
        अगर (c == '|') {
            p++;
            tok = TOK_LOR;
        } अन्यथा अगर (c == '=') {
            p++;
            tok = TOK_A_OR;
        } अन्यथा {
            tok = '|';
        }
        अवरोध;

    हाल '+':
        PEEKC(c, p);
        अगर (c == '+') {
            p++;
            tok = TOK_INC;
        } अन्यथा अगर (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } अन्यथा {
            tok = '+';
        }
        अवरोध;
        
    हाल '-':
        PEEKC(c, p);
        अगर (c == '-') {
            p++;
            tok = TOK_DEC;
        } अन्यथा अगर (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } अन्यथा अगर (c == '>') {
            p++;
            tok = TOK_ARROW;
        } अन्यथा {
            tok = '-';
        }
        अवरोध;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    हाल '/':
        PEEKC(c, p);
        अगर (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            जाओ maybe_space;
        } अन्यथा अगर (c == '/') {
            p = parse_पंक्ति_comment(p);
            tok = ' ';
            जाओ maybe_space;
        } अन्यथा अगर (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } अन्यथा {
            tok = '/';
        }
        अवरोध;
        
        /* simple tokens */
    हाल '@': /* only used in assembler */
#अगर_घोषित TCC_TARGET_ARM /* comment on arm asm */
        अगर (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_पंक्ति_comment(p);
            जाओ redo_no_start;
        }
#पूर्ण_अगर
    हाल '(':
    हाल ')':
    हाल '[':
    हाल ']':
    हाल '{':
    हाल '}':
    हाल ',':
    हाल ';':
    हाल ':':
    हाल '?':
    हाल '~':
    parse_simple:
        tok = c;
        p++;
        अवरोध;
    हाल 0xEF: /* UTF8 BOM ? */
        अगर (p[1] == 0xBB && p[2] == 0xBF && p == file->बफर) {
            p += 3;
            जाओ redo_no_start;
        }
    शेष:
        अगर (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    जाओ parse_ident_fast;
        अगर (parse_flags & PARSE_FLAG_ASM_FILE)
            जाओ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        अवरोध;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#अगर defined(PARSE_DEBUG)
    म_लिखो("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#पूर्ण_अगर
}

#अगर_घोषित PP_DEBUG
अटल पूर्णांक indent;
अटल व्योम define_print(TCCState *s1, पूर्णांक v);
अटल व्योम pp_print(स्थिर अक्षर *संदेश, पूर्णांक v, स्थिर पूर्णांक *str)
{
    खाता *fp = tcc_state->ppfp;

    अगर (संदेश[0] == '#' && indent == 0)
        ख_लिखो(fp, "\n");
    अन्यथा अगर (संदेश[0] == '+')
         ++indent, ++संदेश;
    अन्यथा अगर (संदेश[0] == '-')
        --indent, ++संदेश;

    ख_लिखो(fp, "%*s", indent, "");
    अगर (संदेश[0] == '#') {
        define_print(tcc_state, v);
    } अन्यथा {
        tok_print(str, v ? "%s %s" : "%s", संदेश, get_tok_str(v, 0));
    }
}
#घोषणा PP_PRINT(x) pp_print x
#अन्यथा
#घोषणा PP_PRINT(x)
#पूर्ण_अगर

अटल पूर्णांक macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    स्थिर पूर्णांक *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
अटल पूर्णांक *macro_arg_subst(Sym **nested_list, स्थिर पूर्णांक *macro_str, Sym *args)
{
    पूर्णांक t, t0, t1, t2, n;
    स्थिर पूर्णांक *st;
    Sym *s;
    CValue cval;
    TokenString str;

#अगर_घोषित PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    क्रम (s = args, n = 0; s; s = s->पूर्व, ++n);
    जबतक (n--) {
        क्रम (s = args, t = 0; t < n; s = s->पूर्व, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#पूर्ण_अगर

    tok_str_new(&str);
    t0 = t1 = 0;
    जबतक(1) {
        TOK_GET(&t, &macro_str, &cval);
        अगर (!t)
            अवरोध;
        अगर (t == '#') {
            /* stringize */
            करो t = *macro_str++; जबतक (t == ' ');
            s = sym_find2(args, t);
            अगर (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                जबतक (*st != TOK_EOF) {
                    स्थिर अक्षर *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    जबतक (*s) {
                        अगर (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
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
                cval.str.तथ्य = tokcstr.तथ्य;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#अगर_घोषित TCC_TARGET_ARM
            } अन्यथा अगर ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#पूर्ण_अगर
            } अन्यथा {
                expect("macro parameter after '#'");
            }
        } अन्यथा अगर (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            अगर (s) {
                st = s->d;
                n = 0;
                जबतक ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                अगर (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    अगर (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        पूर्णांक c = str.str[str.len - 1];
                        जबतक (str.str[--str.len] != ',')
                            ;
                        अगर (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } अन्यथा {
                            /* suppress '##' and add variable */
                            str.len++;
                            अगर (c == ' ')
                                str.str[str.len++] = c;
                            जाओ add_var;
                        }
                    } अन्यथा {
                        अगर (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } अन्यथा {
            add_var:
		    अगर (!s->e) {
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
                जबतक (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } अन्यथा {
                tok_str_add(&str, t);
            }
        } अन्यथा {
            tok_str_add2(&str, t, &cval);
        }
        अगर (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    वापस str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
अटल अंतरभूत पूर्णांक *macro_twosharps(स्थिर पूर्णांक *ptr0)
{
    पूर्णांक t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    स्थिर पूर्णांक *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    क्रम (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        अगर (t1 == 0)
            अवरोध;
        क्रम (;;) {
            n = 0;
            जबतक ((t2 = ptr[n]) == ' ')
                ++n;
            अगर (t2 != TOK_PPJOIN)
                अवरोध;
            ptr += n;
            जबतक ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            अगर (t2 == TOK_PLCHLDR)
                जारी;
            अगर (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        अगर (tokcstr.आकार) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.आकार);
            स_नकल(file->बफर, tokcstr.तथ्य, tokcstr.आकार);
            tok_flags = 0; /* don't interpret '#' */
            क्रम (n = 0;;n = l) {
                अग्र_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                अगर (*file->buf_ptr == 0)
                    अवरोध;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->बफर;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->बफर + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        अगर (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    वापस macro_str1.str;
}

अटल पूर्णांक peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    पूर्णांक c;
    क्रम (;;) {
        PEEKC(c, p);
        चयन (c) {
        हाल '/':
            PEEKC(c, p);
            अगर (c == '*')
                p = parse_comment(p);
            अन्यथा अगर (c == '/')
                p = parse_पंक्ति_comment(p);
            अन्यथा {
                c = *--p = '/';
                जाओ leave;
            }
            --p, c = ' ';
            अवरोध;
        हाल ' ': हाल '\t':
            अवरोध;
        हाल '\f': हाल '\v': हाल '\r':
            जारी;
        हाल '\n':
            file->पंक्ति_अंक++, tok_flags |= TOK_FLAG_BOL;
            अवरोध;
        शेष: leave:
            file->buf_ptr = p;
            वापस c;
        }
        अगर (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
अटल पूर्णांक अग्र_argstream(Sym **nested_list, TokenString *ws_str)
{
    पूर्णांक t;
    Sym *sa;

    जबतक (macro_ptr) {
        स्थिर पूर्णांक *m = macro_ptr;
        जबतक ((t = *m) != 0) {
            अगर (ws_str) {
                अगर (t != ' ')
                    वापस t;
                ++m;
            } अन्यथा {
                TOK_GET(&tok, &macro_ptr, &tokc);
                वापस tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        अगर (sa)
            *nested_list = sa->पूर्व, sym_free(sa);
    }
    अगर (ws_str) {
        वापस peek_file(ws_str);
    } अन्यथा {
        अग्र_nomacro();
        अगर (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        वापस tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
अटल पूर्णांक macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    पूर्णांक t;
    पूर्णांक v = s->v;

    PP_PRINT(("#", v, s->d));
    अगर (s->d) {
        पूर्णांक *mstr = s->d;
        पूर्णांक *jstr;
        Sym *sa;
        पूर्णांक ret;

        अगर (s->type.t & MACRO_FUNC) {
            पूर्णांक saved_parse_flags = parse_flags;
            TokenString str;
            पूर्णांक parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = अग्र_argstream(nested_list, &str);
            अगर (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                अगर (parse_flags & PARSE_FLAG_SPACES)
                    क्रम (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                वापस 0;
            } अन्यथा {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = शून्य;
            sa = s->अग्र;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            क्रम(;;) {
                करो {
                    t = अग्र_argstream(nested_list, शून्य);
                } जबतक (t == ' ' || --i);

                अगर (!sa) {
                    अगर (t == ')') /* handle '()' case */
                        अवरोध;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                जबतक (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    अगर (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    अगर (t == '(')
                        parlevel++;
                    अगर (t == ')')
                        parlevel--;
                    अगर (t == ' ')
                        str.need_spc |= 1;
                    अन्यथा
                        tok_str_add2_spc(&str, t, &tokc);
                    t = अग्र_argstream(nested_list, शून्य);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->अग्र;
                अगर (t == ')') {
                    अगर (!sa)
                        अवरोध;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    अगर (sa->type.t && gnu_ext)
                        जाओ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            जबतक (sa) {
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
        अगर (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        अगर (sa == *nested_list)
            *nested_list = sa->पूर्व, sym_free(sa);

        अगर (jstr != mstr)
            tok_str_free_str(jstr);
        अगर (mstr != s->d)
            tok_str_free_str(mstr);
        वापस ret;

    } अन्यथा {
        CValue cval;
        अक्षर buf[32], *cstrval = buf;

        /* special macros */
        अगर (v == TOK_पंक्ति_2 || v == TOK_गणक) {
            t = v == TOK_पंक्ति_2 ? file->पंक्ति_अंक : pp_गणक++;
            snprintf(buf, माप(buf), "%d", t);
            t = TOK_PPNUM;
            जाओ add_cstr1;

        } अन्यथा अगर (v == TOK___FILE__) {
            cstrval = file->filename;
            जाओ add_cstr;

        } अन्यथा अगर (v == TOK___DATE__ || v == TOK___TIME__) {
            समय_प्रकार ti;
            काष्ठा पंचांग *पंचांग;
            समय(&ti);
            पंचांग = स_स्थानीय(&ti);
            अगर (v == TOK___DATE__) {
                अटल अक्षर स्थिर ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, माप(buf), "%s %2d %d",
                    ab_month_name[पंचांग->tm_mon], पंचांग->tm_mday, पंचांग->tm_year + 1900);
            } अन्यथा {
                snprintf(buf, माप(buf), "%02d:%02d:%02d",
                    पंचांग->tm_hour, पंचांग->tm_min, पंचांग->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.आकार = म_माप(cstrval) + 1;
            cval.str.तथ्य = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        वापस 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
अटल पूर्णांक macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    स्थिर पूर्णांक *macro_str
    )
{
    Sym *s;
    पूर्णांक t, nosubst = 0;
    CValue cval;
    TokenString *str;

#अगर_घोषित PP_DEBUG
    पूर्णांक tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#पूर्ण_अगर

    जबतक (1) {
        TOK_GET(&t, &macro_str, &cval);
        अगर (t == 0 || t == TOK_EOF)
            अवरोध;
        अगर (t >= TOK_IDENT) {
            s = define_find(t);
            अगर (s == शून्य || nosubst)
                जाओ no_subst;
            /* if nested substitution, do nothing */
            अगर (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                जाओ no_subst;
            }
            str = tok_str_alloc();
            str->str = (पूर्णांक*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            अगर (macro_ढेर != str) {
                /* already finished by reading function macro arguments */
                अवरोध;
            }
            macro_str = macro_ptr;
            end_macro ();
        } अन्यथा अगर (t == ' ') {
            अगर (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } अन्यथा {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            अगर (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            अगर (t == TOK_DEFINED && pp_व्यंजक)
                nosubst = 1;
        }
    }

#अगर_घोषित PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#पूर्ण_अगर
    वापस nosubst;
}

/* return next token with macro substitution */
ST_FUNC व्योम अग्र(व्योम)
{
    पूर्णांक t;
    जबतक (macro_ptr) {
redo:
        t = *macro_ptr;
        अगर (TOK_HAS_मूल्य(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            अगर (t == TOK_LINENUM) {
                file->पंक्ति_अंक = tokc.i;
                जाओ redo;
            }
            जाओ convert;
        } अन्यथा अगर (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            जारी;
        } अन्यथा अगर (t == TOK_EOF) {
            /* do nothing */
        } अन्यथा {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            अगर (t == '\\') {
                अगर (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        वापस;
    }

    अग्र_nomacro();
    t = tok;
    अगर (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        अगर (s) {
            Sym *nested_list = शून्य;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            जाओ redo;
        }
        वापस;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    अगर (t == TOK_PPNUM) {
        अगर  (parse_flags & PARSE_FLAG_TOK_अंक)
            parse_संख्या(tokc.str.तथ्य);
    } अन्यथा अगर (t == TOK_PPSTR) {
        अगर (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.तथ्य, tokc.str.आकार - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN व्योम unget_tok(पूर्णांक last_tok)
{
    TokenString *str = &unget_buf;
    पूर्णांक alloc = 0;
    अगर (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    अगर (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

अटल स्थिर अक्षर * स्थिर target_os_defs =
#अगर_घोषित TCC_TARGET_PE
    "_WIN32\0"
# अगर PTR_आकार == 8
    "_WIN64\0"
# endif
#अन्यथा
# अगर defined TCC_TARGET_MACHO
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
#  अगर TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#पूर्ण_अगर
    ;

अटल व्योम putdef(CString *cs, स्थिर अक्षर *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!म_अक्षर(p, ' ')*2]);
}

अटल व्योम putdefs(CString *cs, स्थिर अक्षर *p)
{
    जबतक (*p)
        putdef(cs, p), p = म_अक्षर(p, 0) + 1;
}

अटल व्योम tcc_predefs(TCCState *s1, CString *cs, पूर्णांक is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#अगर_घोषित TCC_TARGET_ARM
    अगर (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#पूर्ण_अगर
    अगर (is_asm)
      putdef(cs, "__ASSEMBLER__");
    अगर (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    अगर (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#अगर_घोषित CONFIG_TCC_BACKTRACE
    अगर (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#पूर्ण_अगर
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#पूर्ण_अगर
    अगर (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    अगर (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    अगर (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    अगर (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_आकार);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_आकार);
    अगर (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#अगर CONFIG_TCC_PREDEFS
        #समावेश "tccdefs_.h" /* include as strings */
#अन्यथा
        "#include <tccdefs.h>\n" /* load at runtime */
#पूर्ण_अगर
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC व्योम preprocess_start(TCCState *s1, पूर्णांक filetype)
{
    पूर्णांक is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ढेर_ptr = s1->include_ढेर;
    s1->ifdef_ढेर_ptr = s1->ifdef_ढेर;
    file->ifdef_ढेर_ptr = s1->ifdef_ढेर_ptr;
    pp_व्यंजक = 0;
    pp_गणक = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ढेर[0] = 0;
    s1->pack_ढेर_ptr = s1->pack_ढेर;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    अगर (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        अगर (s1->cmdline_defs.आकार)
          cstr_cat(&cstr, s1->cmdline_defs.तथ्य, s1->cmdline_defs.आकार);
        अगर (s1->cmdline_incl.आकार)
          cstr_cat(&cstr, s1->cmdline_incl.तथ्य, s1->cmdline_incl.आकार);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ढेर_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.आकार);
        स_नकल(file->बफर, cstr.तथ्य, cstr.आकार);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC व्योम preprocess_end(TCCState *s1)
{
    जबतक (macro_ढेर)
        end_macro();
    macro_ptr = शून्य;
    जबतक (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC पूर्णांक set_idnum(पूर्णांक c, पूर्णांक val)
{
    पूर्णांक पूर्व = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    वापस पूर्व;
}

ST_FUNC व्योम tccpp_new(TCCState *s)
{
    पूर्णांक i, c;
    स्थिर अक्षर *p, *r;

    /* init isid table */
    क्रम(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_अंक
            : 0);

    क्रम(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_आकार);
    tal_new(&tokstr_alloc, TOKSTR_TAL_आकार);

    स_रखो(hash_ident, 0, TOK_HASH_आकार * माप(TokenSym *));
    स_रखो(s->cached_includes_hash, 0, माप s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_आकार);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_आकार);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_आकार);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    जबतक (*p) {
        r = p;
        क्रम(;;) {
            c = *r++;
            अगर (c == '\0')
                अवरोध;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_धकेलो(TOK_पंक्ति_2, MACRO_OBJ, शून्य, शून्य);
    define_धकेलो(TOK___FILE__, MACRO_OBJ, शून्य, शून्य);
    define_धकेलो(TOK___DATE__, MACRO_OBJ, शून्य, शून्य);
    define_धकेलो(TOK___TIME__, MACRO_OBJ, शून्य, शून्य);
    define_धकेलो(TOK_गणक, MACRO_OBJ, शून्य, शून्य);
}

ST_FUNC व्योम tccpp_delete(TCCState *s)
{
    पूर्णांक i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    अगर (n > योग_idents)
        योग_idents = n;
    क्रम (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = शून्य;

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

अटल पूर्णांक pp_need_space(पूर्णांक a, पूर्णांक b);

अटल व्योम tok_print(स्थिर पूर्णांक *str, स्थिर अक्षर *संदेश, ...)
{
    खाता *fp = tcc_state->ppfp;
    बहु_सूची ap;
    पूर्णांक t, t0, s;
    CValue cval;

    बहु_शुरू(ap, संदेश);
    भख_लिखो(fp, संदेश, ap);
    बहु_पूर्ण(ap);

    s = t0 = 0;
    जबतक (str) {
	TOK_GET(&t, &str, &cval);
	अगर (t == 0 || t == TOK_EOF)
	    अवरोध;
        अगर (pp_need_space(t0, t))
            s = 0;
	ख_लिखो(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    ख_लिखो(fp, "\n");
}

अटल व्योम pp_पंक्ति(TCCState *s1, BufferedFile *f, पूर्णांक level)
{
    पूर्णांक d = f->पंक्ति_अंक - f->पंक्ति_ref;

    अगर (s1->dflag & 4)
	वापस;

    अगर (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } अन्यथा अगर (level == 0 && f->पंक्ति_ref && d < 8) {
	जबतक (d > 0)
	    ख_माला_दो("\n", s1->ppfp), --d;
    } अन्यथा अगर (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_STD) {
	ख_लिखो(s1->ppfp, "#line %d \"%s\"\n", f->पंक्ति_अंक, f->filename);
    } अन्यथा {
	ख_लिखो(s1->ppfp, "# %d \"%s\"%s\n", f->पंक्ति_अंक, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->पंक्ति_ref = f->पंक्ति_अंक;
}

अटल व्योम define_print(TCCState *s1, पूर्णांक v)
{
    खाता *fp;
    Sym *s;

    s = define_find(v);
    अगर (शून्य == s || शून्य == s->d)
        वापस;

    fp = s1->ppfp;
    ख_लिखो(fp, "#define %s", get_tok_str(v, शून्य));
    अगर (s->type.t & MACRO_FUNC) {
        Sym *a = s->अग्र;
        ख_लिखो(fp,"(");
        अगर (a)
            क्रम (;;) {
                ख_लिखो(fp,"%s", get_tok_str(a->v, शून्य));
                अगर (!(a = a->अग्र))
                    अवरोध;
                ख_लिखो(fp,",");
            }
        ख_लिखो(fp,")");
    }
    tok_print(s->d, "");
}

अटल व्योम pp_debug_defines(TCCState *s1)
{
    पूर्णांक v, t;
    स्थिर अक्षर *vs;
    खाता *fp;

    t = pp_debug_tok;
    अगर (t == 0)
        वापस;

    file->पंक्ति_अंक--;
    pp_पंक्ति(s1, file, 0);
    file->पंक्ति_ref = ++file->पंक्ति_अंक;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, शून्य);
    अगर (t == TOK_DEFINE) {
        define_print(s1, v);
    } अन्यथा अगर (t == TOK_UNDEF) {
        ख_लिखो(fp, "#undef %s\n", vs);
    } अन्यथा अगर (t == TOK_धकेलो_macro) {
        ख_लिखो(fp, "#pragma push_macro(\"%s\")\n", vs);
    } अन्यथा अगर (t == TOK_निकालो_macro) {
        ख_लिखो(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
अटल पूर्णांक pp_need_space(पूर्णांक a, पूर्णांक b)
{
    वापस 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
अटल पूर्णांक pp_check_he0xE(पूर्णांक t, स्थिर अक्षर *p)
{
    अगर (t == TOK_PPNUM && toup(म_अक्षर(p, 0)[-1]) == 'E')
        वापस 'E';
    वापस t;
}

/* Preprocess the current file */
ST_FUNC पूर्णांक tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    पूर्णांक token_seen, spcs, level;
    स्थिर अक्षर *p;
    अक्षर white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    अगर (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_अंक, s1->Pflag = 1;

    अगर (s1->do_bench) {
	/* for PP benchmarks */
	करो अग्र(); जबतक (tok != TOK_EOF);
	वापस 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    अगर (file->पूर्व)
        pp_पंक्ति(s1, file->पूर्व, level++);
    pp_पंक्ति(s1, file, level);

    क्रम (;;) {
        iptr = s1->include_ढेर_ptr;
        अग्र();
        अगर (tok == TOK_EOF)
            अवरोध;

        level = s1->include_ढेर_ptr - iptr;
        अगर (level) {
            अगर (level > 0)
                pp_पंक्ति(s1, *iptr, 0);
            pp_पंक्ति(s1, file, level);
        }
        अगर (s1->dflag & 7) {
            pp_debug_defines(s1);
            अगर (s1->dflag & 4)
                जारी;
        }

        अगर (is_space(tok)) {
            अगर (spcs < माप white - 1)
                white[spcs++] = tok;
            जारी;
        } अन्यथा अगर (tok == TOK_LINEFEED) {
            spcs = 0;
            अगर (token_seen == TOK_LINEFEED)
                जारी;
            ++file->पंक्ति_ref;
        } अन्यथा अगर (token_seen == TOK_LINEFEED) {
            pp_पंक्ति(s1, file, 0);
        } अन्यथा अगर (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, ख_माला_दो(white, s1->ppfp), spcs = 0;
        ख_माला_दो(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    वापस 0;
}

/* ------------------------------------------------------------------------- */
