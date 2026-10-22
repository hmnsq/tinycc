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
#अन्तर्भाव "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA पूर्णांक tok_flags;
ST_DATA पूर्णांक parse_flags;

ST_DATA संरचना BufferedFile *file;
ST_DATA पूर्णांक tok;
ST_DATA CValue tokc;
ST_DATA स्थिरांक पूर्णांक *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA पूर्णांक tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA पूर्णांक pp_अभिव्यक्ती;

/* ------------------------------------------------------------------------- */

स्थिर TokenSym *hash_ident[TOK_HASH_SIZE];
स्थिर अक्षर token_buf[STRING_MAX_SIZE + 1];
स्थिर CString cstr_buf;
स्थिर TokenString tokstr_buf;
स्थिर TokenString unget_buf;
स्थिर अचिन्हित अक्षर isidnum_table[256 - CH_EOF];
स्थिर पूर्णांक pp_debug_tok, pp_debug_symv;
स्थिर पूर्णांक pp_counter;
स्थिर शून्य tok_print(स्थिरांक पूर्णांक *str, स्थिरांक अक्षर *संदेश, ...);
स्थिर शून्य next_nomacro(शून्य);
स्थिर शून्य parse_संख्या(स्थिरांक अक्षर *p);
स्थिर शून्य parse_string(स्थिरांक अक्षर *p, पूर्णांक len);

स्थिर संरचना TinyAlloc *toksym_alloc;
स्थिर संरचना TinyAlloc *tokstr_alloc;

स्थिर TokenString *macro_चळत;

स्थिर स्थिरांक अक्षर tcc_keywords[] = 
#define DEF(id, str) str "\0"
#अन्तर्भाव "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
स्थिर स्थिरांक अचिन्हित अक्षर tok_two_chars[] =
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

ST_FUNC शून्य skip(पूर्णांक c)
{
    जर (tok != c) {
        अक्षर tmp[40];
        pstrcpy(tmp, आकार tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC शून्य expect(स्थिरांक अक्षर *संदेश)
{
    tcc_error("%s expected", संदेश);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#अन्यथा
#जर !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#अन्यथा
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , स्थिरांक अक्षर *sfile, पूर्णांक sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

प्रकारव्याख्या संरचना TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    संरचना TinyAlloc *next;
    अचिन्हित nb_allocs;
    अचिन्हित size;
#जर TAL_INFO
    अचिन्हित nb_peak;
    अचिन्हित nb_total;
    uint8_t *peak_p;
#endif
    संघ {
        uint8_t buffer[1];
        माप_प्रकार _aligner_;
    };
} TinyAlloc;

प्रकारव्याख्या संरचना tal_header_t {
    माप_प्रकार  size; /* word align */
#जर TAL_DEBUG
    पूर्णांक     ओळ_अंक; /* negative line_num used for double free check */
    अक्षर    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (आकार (माप_प्रकार) - 1)) & ~(आकार (माप_प्रकार) - 1))

/* ------------------------------------------------------------------------- */

स्थिर TinyAlloc *tal_new(TinyAlloc **pal, अचिन्हित size)
{
    TinyAlloc *al = tcc_malloc(आकार(TinyAlloc) - आकार (माप_प्रकार) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#जर TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    परत al;
}

स्थिर शून्य tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#जर TAL_INFO
    ख_लिखो(मानक_त्रुटि, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#जर TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#जर TAL_INFO
    ख_लिखो(मानक_त्रुटि, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    जर (al->nb_allocs > 0) {
        uint8_t *p;
        ख_लिखो(मानक_त्रुटि, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        पर्यंत (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            जर (header->ओळ_अंक > 0) {
                ख_लिखो(मानक_त्रुटि, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->ओळ_अंक, (पूर्णांक)header->size);
            }
            p += header->size + आकार(tal_header_t);
        }
#जर TAL_DEBUG == 2
        निकास(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    जर (al)
        जा tail_call;
    *pal = al;
}

स्थिर शून्य tal_free_impl(TinyAlloc **pal, शून्य *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **शीर्ष = pal;
    tal_header_t *header;

    जर (!p)
        परत;
    header = (tal_header_t *)p - 1;
#जर TAL_DEBUG
    जर (header->ओळ_अंक < 0) {
        ख_लिखो(मानक_त्रुटि, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        ख_लिखो(मानक_त्रुटि, "%s:%d: %d bytes\n",
                header->file_name, (पूर्णांक)-header->ओळ_अंक, (पूर्णांक)header->size);
    } अन्यथा
        header->ओळ_अंक = -header->ओळ_अंक;
#endif
    al = *pal;
    पर्यंत ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    जर (0 == --al->nb_allocs) {
        *pal = al->next;
        जर ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } अन्यथा {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *शीर्ष, *शीर्ष = al;
        }
    } अन्यथा जर ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

स्थिर शून्य *tal_realloc_impl(TinyAlloc **pal, शून्य *p, अचिन्हित size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    शून्य *ret;
    अचिन्हित adj_size = TAL_ALIGN(size) + आकार(tal_header_t);
    TinyAlloc *al = *pal;

    जर (p) {
        /* reallpc case */
        पर्यंत ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        जर ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        जर (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            स_नकल(ret, p, header->size);
            tal_free(pal, p);
            परत ret;
        } अन्यथा जर (al->p != (uint8_t*)header) {
            स_नकल((tal_header_t*)al->p + 1, p, header->size);
#जर TAL_DEBUG
            header->ओळ_अंक = -header->ओळ_अंक;
#endif
        }
    } अन्यथा {
        /* new alloc case */
        पर्यंत (al->p + adj_size > al->bufend) {
            al = al->next;
            जर (!al) {
                अचिन्हित new_size = (*pal)->size;
                जर (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                थांबा;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - आकार(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#जर  TAL_DEBUG
    {
        पूर्णांक ofs = म_माप(sfile) + 1 - आकार header->file_name;
        म_नकल(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->ओळ_अंक = sline;
#जर TAL_INFO
        जर (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        जर (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    परत ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
स्थिर शून्य cstr_realloc(CString *cstr, पूर्णांक new_size)
{
    पूर्णांक size;

    size = cstr->size_allocated;
    जर (size < 8)
        size = 8; /* no need to allocate a too small first string */
    पर्यंत (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN शून्य cstr_ccat(CString *cstr, पूर्णांक ch)
{
    पूर्णांक size;
    size = cstr->size + 1;
    जर (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN अक्षर *unicode_to_utf8 (अक्षर *b, uint32_t Uc)
{
    जर (Uc<0x80) *b++=Uc;
    अन्यथा जर (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    अन्यथा जर (Uc-0xd800u<0x800) जा error;
    अन्यथा जर (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा जर (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अन्यथा error: tcc_error("0x%x is not a valid universal character", Uc);
    परत b;
}

/* add a unicode character expanded into utf8 */
ST_INLN शून्य cstr_u8cat(CString *cstr, पूर्णांक ch)
{
    अक्षर buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC शून्य cstr_cat(CString *cstr, स्थिरांक अक्षर *str, पूर्णांक len)
{
    पूर्णांक size;
    जर (len <= 0)
        len = म_माप(str) + 1 + len;
    size = cstr->size + len;
    जर (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    स_हटाओ(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC शून्य cstr_wccat(CString *cstr, पूर्णांक ch)
{
    पूर्णांक size;
    size = cstr->size + आकार(nwchar_t);
    जर (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - आकार(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC शून्य cstr_new(CString *cstr)
{
    स_रखो(cstr, 0, आकार(CString));
}

/* free string and reset it to NULL */
ST_FUNC शून्य cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC शून्य cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC पूर्णांक cstr_vprintf(CString *cstr, स्थिरांक अक्षर *fmt, बहु_सूची ap)
{
    बहु_सूची v;
    पूर्णांक len, size = 80;
    साठी (;;) {
        size += cstr->size;
        जर (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        बहु_पूर्ण(v);
        जर (len >= 0 && len < size)
            थांबा;
        size *= 2;
    }
    cstr->size += len;
    परत len;
}

ST_FUNC पूर्णांक cstr_printf(CString *cstr, स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap; पूर्णांक len;
    बहु_शुरू(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    बहु_पूर्ण(ap);
    परत len;
}

/* XXX: unicode ? */
स्थिर शून्य add_char(CString *cstr, पूर्णांक c)
{
    जर (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    जर (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } अन्यथा {
        cstr_ccat(cstr, '\\');
        जर (c == '\n') {
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
स्थिर TokenSym *tok_alloc_new(TokenSym **pts, स्थिरांक अक्षर *str, पूर्णांक len)
{
    TokenSym *ts, **ptable;
    पूर्णांक i;

    जर (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    जर ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * आकार(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, आकार(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = रिक्त;
    ts->sym_label = रिक्त;
    ts->sym_struct = रिक्त;
    ts->sym_identifier = रिक्त;
    ts->len = len;
    ts->hash_next = रिक्त;
    स_नकल(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    परत ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(स्थिरांक अक्षर *str, पूर्णांक len)
{
    TokenSym *ts, **pts;
    पूर्णांक i;
    अचिन्हित पूर्णांक h;
    
    h = TOK_HASH_INIT;
    साठी(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((अचिन्हित अक्षर *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    साठी(;;) {
        ts = *pts;
        जर (!ts)
            थांबा;
        जर (ts->len == len && !स_भेद(ts->str, str, len))
            परत ts;
        pts = &(ts->hash_next);
    }
    परत tok_alloc_new(pts, str, len);
}

ST_FUNC पूर्णांक tok_alloc_const(स्थिरांक अक्षर *str)
{
    परत tok_alloc(str, म_माप(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC स्थिरांक अक्षर *get_tok_str(पूर्णांक v, CValue *cv)
{
    अक्षर *p;
    पूर्णांक i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    निवड(v) {
    स्थिती TOK_CINT:
    स्थिती TOK_CUINT:
    स्थिती TOK_CLONG:
    स्थिती TOK_CULONG:
    स्थिती TOK_CLLONG:
    स्थिती TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        प्र_लिखो(p, "%llu", (अचिन्हित दीर्घ दीर्घ)cv->i);
        थांबा;
    स्थिती TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    स्थिती TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        थांबा;
    स्थिती TOK_PPNUM:
    स्थिती TOK_PPSTR:
        परत (अक्षर*)cv->str.data;
    स्थिती TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    स्थिती TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        जर (v == TOK_STR) {
            len = cv->str.size - 1;
            साठी(i=0;i<len;i++)
                add_char(&cstr_buf, ((अचिन्हित अक्षर *)cv->str.data)[i]);
        } अन्यथा {
            len = (cv->str.size / आकार(nwchar_t)) - 1;
            साठी(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        थांबा;

    स्थिती TOK_CFLOAT:
        परत म_नकल(p, "<float>");
    स्थिती TOK_CDOUBLE:
        परत म_नकल(p, "<double>");
    स्थिती TOK_CLDOUBLE:
        परत म_नकल(p, "<long double>");
    स्थिती TOK_LINENUM:
        परत म_नकल(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    स्थिती TOK_LT:
        v = '<';
        जा addv;
    स्थिती TOK_GT:
        v = '>';
        जा addv;
    स्थिती TOK_DOTS:
        परत म_नकल(p, "...");
    स्थिती TOK_A_SHL:
        परत म_नकल(p, "<<=");
    स्थिती TOK_A_SAR:
        परत म_नकल(p, ">>=");
    स्थिती TOK_EOF:
        परत म_नकल(p, "<eof>");
    स्थिती 0: /* anonymous nameless symbols */
        परत म_नकल(p, "<no name>");
    पूर्वनिर्धारित:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        जर (v < TOK_IDENT) {
            /* search in two bytes table */
            स्थिरांक अचिन्हित अक्षर *q = tok_two_chars;
            पर्यंत (*q) {
                जर (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    परत cstr_buf.data;
                }
                q += 3;
            }
            जर (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                प्र_लिखो(p, "<\\x%02x>", v);
                थांबा;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } अन्यथा जर (v < tok_ident) {
            परत table_ident[v - TOK_IDENT]->str;
        } अन्यथा जर (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            प्र_लिखो(p, "L.%u", v - SYM_FIRST_ANOM);
        } अन्यथा {
            /* should never happen */
            परत रिक्त;
        }
        थांबा;
    }
    परत cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
स्थिर पूर्णांक handle_eob(शून्य)
{
    BufferedFile *bf = file;
    पूर्णांक len;

    /* only tries to read if really end of buffer */
    जर (bf->buf_ptr >= bf->buf_end) {
        जर (bf->fd >= 0) {
#जर defined(PARSE_DEBUG)
            len = 1;
#अन्यथा
            len = IO_BUF_SIZE;
#endif
            len = पठ(bf->fd, bf->buffer, len);
            जर (len < 0)
                len = 0;
        } अन्यथा {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    जर (bf->buf_ptr < bf->buf_end) {
        परत bf->buf_ptr[0];
    } अन्यथा {
        bf->buf_ptr = bf->buf_end;
        परत CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
स्थिर पूर्णांक next_c(शून्य)
{
    पूर्णांक ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    जर (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    परत ch;
}

/* input with '\[\r]\n' handling. */
स्थिर पूर्णांक handle_stray_noerror(पूर्णांक err)
{
    पूर्णांक ch;
    पर्यंत ((ch = next_c()) == '\\') {
        ch = next_c();
        जर (ch == '\n') {
    newl:
            file->ओळ_अंक++;
        } अन्यथा {
            जर (ch == '\r') {
                ch = next_c();
                जर (ch == '\n')
                    जा newl;
                *--file->buf_ptr = '\r';
            }
            जर (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            परत *--file->buf_ptr = '\\';
        }
    }
    परत ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
स्थिर पूर्णांक handle_bs(uint8_t **p)
{
    पूर्णांक c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    परत c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
स्थिर पूर्णांक handle_stray(uint8_t **p)
{
    पूर्णांक c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    परत c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    जर (c == '\\')\
        c = handle_stray(&p); \
}

स्थिर पूर्णांक skip_spaces(शून्य)
{
    पूर्णांक ch;
    --file->buf_ptr;
    करा {
        ch = ninp();
    } पर्यंत (isidnum_table[ch - CH_EOF] & IS_SPC);
    परत ch;
}

/* single line C++ comments */
स्थिर uint8_t *parse_ओळ_comment(uint8_t *p)
{
    पूर्णांक c;
    साठी(;;) {
        साठी (;;) {
            c = *++p;
    redo:
            जर (c == '\n' || c == '\\')
                थांबा;
            c = *++p;
            जर (c == '\n' || c == '\\')
                थांबा;
        }
        जर (c == '\n')
            थांबा;
        c = handle_bs(&p);
        जर (c == CH_EOF)
            थांबा;
        जर (c != '\\')
            जा redo;
    }
    परत p;
}

/* C comments */
स्थिर uint8_t *parse_comment(uint8_t *p)
{
    पूर्णांक c;
    साठी(;;) {
        /* fast skip loop */
        साठी(;;) {
            c = *++p;
        redo:
            जर (c == '\n' || c == '*' || c == '\\')
                थांबा;
            c = *++p;
            जर (c == '\n' || c == '*' || c == '\\')
                थांबा;
        }
        /* now we can handle all the cases */
        जर (c == '\n') {
            file->ओळ_अंक++;
        } अन्यथा जर (c == '*') {
            करा {
                c = *++p;
            } पर्यंत (c == '*');
            जर (c == '\\')
                c = handle_bs(&p);
            जर (c == '/')
                थांबा;
            जा check_eof;
        } अन्यथा {
            c = handle_bs(&p);
        check_eof:
            जर (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            जर (c != '\\')
                जा redo;
        }
    }
    परत p + 1;
}

/* parse a string without interpreting escapes */
स्थिर uint8_t *parse_pp_string(uint8_t *p, पूर्णांक sep, CString *str)
{
    पूर्णांक c;
    साठी(;;) {
        c = *++p;
    redo:
        जर (c == sep) {
            थांबा;
        } अन्यथा जर (c == '\\') {
            c = handle_bs(&p);
            जर (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } अन्यथा जर (c == '\\') {
                जर (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                जर (c == '\\') {
                    c = handle_bs(&p);
                    जर (c == CH_EOF)
                        जा unterminated_string;
                }
                जा add_char;
            } अन्यथा {
                जा redo;
            }
        } अन्यथा जर (c == '\n') {
        add_lf:
            जर (ACCEPT_LF_IN_STRINGS) {
                file->ओळ_अंक++;
                जा add_char;
            } अन्यथा जर (str) { /* not skipping */
                जा unterminated_string;
            } अन्यथा {
                //tcc_warning("missing terminating %c character", sep);
                परत p;
            }
        } अन्यथा जर (c == '\r') {
            c = *++p;
            जर (c == '\\')
                c = handle_bs(&p);
            जर (c == '\n')
                जा add_lf;
            जर (c == CH_EOF)
                जा unterminated_string;
            जर (str)
                cstr_ccat(str, '\r');
            जा redo;
        } अन्यथा {
        add_char:
            जर (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    परत p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
स्थिर शून्य preprocess_skip(शून्य)
{
    पूर्णांक a, start_of_ओळ, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_ओळ = 1;
    in_warn_or_error = 0;
    साठी(;;) {
        c = *p;
        निवड(c) {
        स्थिती ' ':
        स्थिती '\t':
        स्थिती '\f':
        स्थिती '\v':
        स्थिती '\r':
            p++;
            सुरूठेवा;
        स्थिती '\n':
            file->ओळ_अंक++;
            p++;
            जा redo_start;
        स्थिती '\\':
            c = handle_bs(&p);
            जर (c == CH_EOF)
                expect("#endif");
            जर (c == '\\')
                ++p;
            सुरूठेवा;
        /* skip strings */
        स्थिती '\"':
        स्थिती '\'':
            जर (in_warn_or_error)
                जा _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, रिक्त);
            थांबा;
        /* skip comments */
        स्थिती '/':
            जर (in_warn_or_error)
                जा _default;
            ++p;
            c = handle_bs(&p);
            जर (c == '*') {
                p = parse_comment(p);
            } अन्यथा जर (c == '/') {
                p = parse_ओळ_comment(p);
            }
            सुरूठेवा;
        स्थिती '#':
            p++;
            जर (start_of_ओळ) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                जर (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    जा the_end;
                जर (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                अन्यथा जर (tok == TOK_ENDIF)
                    a--;
                अन्यथा जर( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                अन्यथा जर (tok == TOK_LINEFEED)
                    जा redo_start;
                अन्यथा जर (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_ओळ_comment(p - 1);
            }
#जर !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            अन्यथा जर (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_ओळ_comment(p - 1);
#अन्यथा
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            थांबा;
_default:
        पूर्वनिर्धारित:
            p++;
            थांबा;
        }
        start_of_ओळ = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#जर 0
/* return the number of additional 'ints' necessary to store the
   token */
स्थिर ओळीत पूर्णांक tok_size(स्थिरांक पूर्णांक *p)
{
    निवड(*p) {
        /* 4 bytes */
    स्थिती TOK_CINT:
    स्थिती TOK_CUINT:
    स्थिती TOK_CCHAR:
    स्थिती TOK_LCHAR:
    स्थिती TOK_CFLOAT:
    स्थिती TOK_LINENUM:
        परत 1 + 1;
    स्थिती TOK_STR:
    स्थिती TOK_LSTR:
    स्थिती TOK_PPNUM:
    स्थिती TOK_PPSTR:
        परत 1 + 1 + (p[1] + 3) / 4;
    स्थिती TOK_CLONG:
    स्थिती TOK_CULONG:
	परत 1 + LONG_SIZE / 4;
    स्थिती TOK_CDOUBLE:
    स्थिती TOK_CLLONG:
    स्थिती TOK_CULLONG:
        परत 1 + 2;
    स्थिती TOK_CLDOUBLE:
        परत 1 + LDOUBLE_शब्द;
    पूर्वनिर्धारित:
        परत 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN शून्य tok_str_new(TokenString *s)
{
    s->str = रिक्त;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_ओळ_अंक = -1;
}

ST_FUNC TokenString *tok_str_alloc(शून्य)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, आकार *str);
    tok_str_new(str);
    परत str;
}

ST_FUNC शून्य tok_str_free_str(पूर्णांक *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC शून्य tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC पूर्णांक *tok_str_realloc(TokenString *s, पूर्णांक new_size)
{
    पूर्णांक *str, size;

    size = s->allocated_len;
    जर (size < 16)
        size = 16;
    पर्यंत (size < new_size)
        size = size * 2;
    जर (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * आकार(पूर्णांक));
        s->allocated_len = size;
        s->str = str;
    }
    परत s->str;
}

ST_FUNC शून्य tok_str_add(TokenString *s, पूर्णांक t)
{
    पूर्णांक len, *str;

    len = s->len;
    str = s->str;
    जर (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC शून्य begin_macro(TokenString *str, पूर्णांक alloc)
{
    str->alloc = alloc;
    str->prev = macro_चळत;
    str->prev_ptr = macro_ptr;
    str->save_ओळ_अंक = file->ओळ_अंक;
    macro_ptr = str->str;
    macro_चळत = str;
}

ST_FUNC शून्य end_macro(शून्य)
{
    TokenString *str = macro_चळत;
    macro_चळत = str->prev;
    macro_ptr = str->prev_ptr;
    file->ओळ_अंक = str->save_ओळ_अंक;
    जर (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } अन्यथा {
        जर (str->alloc == 2)
            str->str = रिक्त; /* don't free */
        tok_str_free(str);
    }
}

स्थिर शून्य tok_str_add2(TokenString *s, पूर्णांक t, CValue *cv)
{
    पूर्णांक len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    जर (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    निवड(t) {
    स्थिती TOK_CINT:
    स्थिती TOK_CUINT:
    स्थिती TOK_CCHAR:
    स्थिती TOK_LCHAR:
    स्थिती TOK_CFLOAT:
    स्थिती TOK_LINENUM:
#जर LONG_SIZE == 4
    स्थिती TOK_CLONG:
    स्थिती TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        थांबा;
    स्थिती TOK_PPNUM:
    स्थिती TOK_PPSTR:
    स्थिती TOK_STR:
    स्थिती TOK_LSTR:
        {
            /* Insert the string into the int array. */
            माप_प्रकार nb_शब्द =
                1 + (cv->str.size + आकार(पूर्णांक) - 1) / आकार(पूर्णांक);
            जर (len + nb_शब्द >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_शब्द + 1);
            str[len] = cv->str.size;
            स_नकल(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_शब्द;
        }
        थांबा;
    स्थिती TOK_CDOUBLE:
    स्थिती TOK_CLLONG:
    स्थिती TOK_CULLONG:
#जर LONG_SIZE == 8
    स्थिती TOK_CLONG:
    स्थिती TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        थांबा;
    स्थिती TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        जर (LDOUBLE_शब्द >= 3)
        str[len++] = cv->tab[2];
        जर (LDOUBLE_शब्द >= 4)
        str[len++] = cv->tab[3];
    पूर्वनिर्धारित:
        थांबा;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC शून्य tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    जर (file->ओळ_अंक != s->last_ओळ_अंक) {
        s->last_ओळ_अंक = file->ओळ_अंक;
        cval.i = s->last_ओळ_अंक;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
स्थिर शून्य tok_str_add2_spc(TokenString *s, पूर्णांक t, CValue *cv)
{
    जर (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
स्थिर ओळीत शून्य tok_get(पूर्णांक *t, स्थिरांक पूर्णांक **pp, CValue *cv)
{
    स्थिरांक पूर्णांक *p = *pp;
    पूर्णांक n, *tab;

    tab = cv->tab;
    निवड(*t = *p++) {
#जर LONG_SIZE == 4
    स्थिती TOK_CLONG:
#endif
    स्थिती TOK_CINT:
    स्थिती TOK_CCHAR:
    स्थिती TOK_LCHAR:
    स्थिती TOK_LINENUM:
        cv->i = *p++;
        थांबा;
#जर LONG_SIZE == 4
    स्थिती TOK_CULONG:
#endif
    स्थिती TOK_CUINT:
        cv->i = (अचिन्हित)*p++;
        थांबा;
    स्थिती TOK_CFLOAT:
	tab[0] = *p++;
	थांबा;
    स्थिती TOK_STR:
    स्थिती TOK_LSTR:
    स्थिती TOK_PPNUM:
    स्थिती TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (अक्षर*)p;
        p += (cv->str.size + आकार(पूर्णांक) - 1) / आकार(पूर्णांक);
        थांबा;
    स्थिती TOK_CDOUBLE:
    स्थिती TOK_CLLONG:
    स्थिती TOK_CULLONG:
#जर LONG_SIZE == 8
    स्थिती TOK_CLONG:
    स्थिती TOK_CULONG:
#endif
        n = 2;
        जा copy;
    स्थिती TOK_CLDOUBLE:
        n = LDOUBLE_शब्द;
    copy:
        करा
            *tab++ = *p++;
        पर्यंत (--n);
        थांबा;
    पूर्वनिर्धारित:
        थांबा;
    }
    *pp = p;
}

#जर 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#अन्यथा
# define TOK_GET(t,p,c) करा { \
    पूर्णांक _t = **(p); \
    जर (TOK_HAS_मूल्य(_t)) \
        tok_get(t, p, c); \
    अन्यथा \
        *(t) = _t, ++*(p); \
    } पर्यंत (0)
#endif

स्थिर पूर्णांक macro_is_equal(स्थिरांक पूर्णांक *a, स्थिरांक पूर्णांक *b)
{
    CValue cv;
    पूर्णांक t;

    जर (!a || !b)
        परत 1;

    पर्यंत (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        जर (म_भेद(tokcstr.data, get_tok_str(t, &cv)))
            परत 0;
    }
    परत !(*a || *b);
}

/* defines handling */
ST_INLN शून्य define_ढकला(पूर्णांक v, पूर्णांक macro_type, पूर्णांक *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_चळत, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    जर (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, रिक्त));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC शून्य define_undef(Sym *s)
{
    पूर्णांक v = s->v;
    जर (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = रिक्त;
}

ST_INLN Sym *define_find(पूर्णांक v)
{
    v -= TOK_IDENT;
    जर ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        परत रिक्त;
    परत table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC शून्य free_defines(Sym *b)
{
    पर्यंत (define_चळत != b) {
        Sym *शीर्ष = define_चळत;
        define_चळत = शीर्ष->prev;
        tok_str_free_str(शीर्ष->d);
        define_undef(शीर्ष);
        sym_free(शीर्ष);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
स्थिर शून्य maybe_run_test(TCCState *s)
{
    स्थिरांक अक्षर *p;
    जर (s->include_चळत_ptr != s->include_चळत)
        परत;
    p = get_tok_str(tok, रिक्त);
    जर (0 != स_भेद(p, "test_", 5))
        परत;
    जर (0 != --s->run_test)
        परत;
    ख_लिखो(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), ख_साफ(s->ppfp);
    define_ढकला(tok, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य skip_to_eol(पूर्णांक warn)
{
    जर (tok == TOK_LINEFEED)
        परत;
    जर (warn)
        tcc_warning("extra tokens after directive");
    पर्यंत (macro_चळत)
        end_macro();
    file->buf_ptr = parse_ओळ_comment(file->buf_ptr - 1);
    next_nomacro();
}

स्थिर CachedInclude *
शोध_cached_include(TCCState *s1, स्थिरांक अक्षर *filename, पूर्णांक add);

स्थिर पूर्णांक parse_include(TCCState *s1, पूर्णांक do_next, पूर्णांक test)
{
    पूर्णांक c, i;
    अक्षर name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    जर (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, आकार name, tokcstr.data, i);
        next_nomacro();
    } अन्यथा {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        साठी (;;) {
            next();
            p = name, i = म_माप(p) - 1;
            जर (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                थांबा;
            जर (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, आकार name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        स_हटाओ(p, p + 1, i - 1), p[i - 1] = 0;
    }

    जर (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    साठी (;;) {
        ++i;
        जर (i == 0) {
            /* check absolute include path */
            जर (!IS_ABSPATH(name))
                सुरूठेवा;
            buf[0] = '\0';
        } अन्यथा जर (i == 1) {
            /* search in file's dir if "header.h" */
            जर (c != '\"')
                सुरूठेवा;
            p = file->true_filename;
            pstrncpy(buf, आकार buf, p, tcc_basename(p) - p);
        } अन्यथा {
            पूर्णांक j = i - 2, k = j - s1->nb_include_paths;
            जर (k < 0)
                p = s1->include_paths[j];
            अन्यथा जर (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            अन्यथा जर (test)
                परत 0;
            अन्यथा
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, आकार buf, p);
            pstrcat(buf, आकार buf, "/");
        }
        pstrcat(buf, आकार buf, name);
        e = शोध_cached_include(s1, buf, 0);
        जर (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            म_लिखो("%s: skipping cached %s\n", file->filename, buf);
#endif
            जर ((s1->verbose | 1) == 3) /* -vv[v] */
                म_लिखो("=> %*s%s\n",
                   (पूर्णांक)(s1->include_चळत_ptr - s1->include_चळत), "", buf);
            परत 1;
        }
        जर (tcc_open(s1, buf) >= 0)
            थांबा;
    }

    जर (test) {
        tcc_close();
    } अन्यथा {
        जर (s1->include_चळत_ptr >= s1->include_चळत + INCLUDE_चळत_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_चळत_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        म_लिखो("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        जर (s1->gen_deps) {
            BufferedFile *bf = file;
            पर्यंत (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            जर (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    परत 1;
}

/* eval an expression for #if/#elif */
स्थिर पूर्णांक अभिव्यक्ती_preprocess(TCCState *s1)
{
    पूर्णांक c, t;
    पूर्णांक t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_अभिव्यक्ती = 1;
    पर्यंत (1) {
        next(); /* do macro subst */
        t = tok;
        जर (tok < TOK_IDENT) {
            जर (tok == TOK_LINEFEED || tok == TOK_EOF)
                थांबा;
            जर (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } अन्यथा जर (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            जर (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            जर (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            जर (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            जर (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            जर (t == '(') {
                next();
                जर (tok != ')')
                    expect("')'");
            }
            जा c_संख्या;
        } अन्यथा जर (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    जर (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            जर (tok != ')')
                expect("')'");
            जा c_संख्या;
        } अन्यथा {
            /* if undefined macro, replace with zero */
            c = 0;
        c_संख्या:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    जर (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_अभिव्यक्ती = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = अभिव्यक्ती_const();
    जर (tok != TOK_EOF)
        tcc_error("...");
    pp_अभिव्यक्ती = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    परत c != 0;
}

ST_FUNC शून्य pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_अभिव्यक्ती, 0));
    macro_ptr = macro_चळत->str;
    पर्यंत (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC शून्य parse_define(शून्य)
{
    Sym *s, *first, **ps;
    पूर्णांक v, t, varg, is_vaargs, t0;
    पूर्णांक saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    जर (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = रिक्त;
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
    जर (tok == '(') {
        पूर्णांक dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        जर (tok != ')') साठी (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            जर (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } अन्यथा जर (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            जर (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_चळत, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            जर (tok == ')')
                थांबा;
            जर (tok != ',' || is_vaargs)
                जा bad_list;
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
    पर्यंत (tok != TOK_LINEFEED && tok != TOK_EOF) {
        जर (is_space(tok)) {
            str.need_spc |= 1;
        } अन्यथा {
            जर (TOK_TWOSHARPS == tok) {
                जर (0 == t0)
                    जा bad_twosharp;
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
    जर (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ढकला(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

स्थिर CachedInclude *शोध_cached_include(TCCState *s1, स्थिरांक अक्षर *filename, पूर्णांक add)
{
    स्थिरांक अक्षर *s, *basename;
    अचिन्हित पूर्णांक h;
    CachedInclude *e;
    पूर्णांक c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    पर्यंत ((c = (अचिन्हित अक्षर)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#अन्यथा
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    साठी(;;) {
        जर (i == 0)
            थांबा;
        e = s1->cached_includes[i - 1];
        जर (0 == PATHCMP(filename, e->filename))
            परत e;
        जर (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            परत e;
        i = e->hash_next;
    }
    जर (!add)
        परत रिक्त;

    e = tcc_malloc(आकार(CachedInclude) + (len = म_माप(filename)));
    स_नकल(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    म_लिखो("adding cached '%s'\n", filename);
#endif
    परत e;
}

स्थिर पूर्णांक pragma_parse(TCCState *s1)
{
    next_nomacro();
    जर (tok == TOK_ढकला_macro || tok == TOK_काढा_macro) {
        पूर्णांक t = tok, v;
        Sym *s;

        जर (next(), tok != '(')
            जा pragma_err;
        जर (next(), tok != TOK_STR)
            जा pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        जर (next(), tok != ')')
            जा pragma_err;
        जर (t == TOK_ढकला_macro) {
            पर्यंत (रिक्त == (s = define_find(v)))
                define_ढकला(v, 0, रिक्त, रिक्त);
            s->type.ref = s; /* set push boundary */
        } अन्यथा {
            साठी (s = define_चळत; s; s = s->prev)
                जर (s->v == v && s->type.ref == s) {
                    s->type.ref = रिक्त;
                    थांबा;
                }
        }
        जर (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : रिक्त;
        अन्यथा
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } अन्यथा जर (tok == TOK_once) {
        शोध_cached_include(s1, file->true_filename, 1)->once = 1;

    } अन्यथा जर (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        परत 1;

    } अन्यथा जर (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        जर (tok == TOK_ASM_काढा) {
            next();
            जर (s1->pack_चळत_ptr <= s1->pack_चळत) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_चळत_ptr--;
        } अन्यथा {
            पूर्णांक val = 0;
            जर (tok != ')') {
                जर (tok == TOK_ASM_ढकला) {
                    next();
                    जर (s1->pack_चळत_ptr >= s1->pack_चळत + PACK_चळत_SIZE - 1)
                        जा stk_error;
                    val = *s1->pack_चळत_ptr++;
                    जर (tok != ',')
                        जा pack_set;
                    next();
                }
                जर (tok != TOK_CINT)
                    जा pragma_err;
                val = tokc.i;
                जर (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    जा pragma_err;
                next();
            }
        pack_set:
            *s1->pack_चळत_ptr = val;
        }
        जर (tok != ')')
            जा pragma_err;

    } अन्यथा जर (tok == TOK_comment) {
        अक्षर *p; पूर्णांक t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        जर (tok != TOK_STR)
            जा pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        जर (tok != ')')
            जा pragma_err;
        जर (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } अन्यथा {
            जर (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } अन्यथा {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        परत 0;
    }
    next();
    परत 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC शून्य tccpp_putfile(स्थिरांक अक्षर *filename)
{
    अक्षर buf[1024];
    buf[0] = 0;
    जर (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, आकार buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, आकार buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    जर (0 == म_भेद(file->filename, buf))
        परत;
    //printf("new file '%s'\n", buf);
    जर (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, आकार file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC शून्य preprocess(पूर्णांक is_bof)
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

    next_nomacro();
 redo:
    निवड(tok) {
    स्थिती TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        थांबा;
    स्थिती TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        जर (s)
            define_undef(s);
        next_nomacro();
        थांबा;
    स्थिती TOK_INCLUDE:
    स्थिती TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        जा the_end;
    स्थिती TOK_IFNDEF:
        c = 1;
        जा do_ifdef;
    स्थिती TOK_IF:
        c = अभिव्यक्ती_preprocess(s1);
        जा do_if;
    स्थिती TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        जर (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        जर (is_bof) {
            जर (c) {
#ifdef INC_DEBUG
                म_लिखो("#ifndef %s\n", get_tok_str(tok, रिक्त));
#endif
                file->ifndef_macro = tok;
            }
        }
        जर (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        जर (s1->ifdef_चळत_ptr >= s1->ifdef_चळत + IFDEF_चळत_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_चळत_ptr++ = c;
        जा test_skip;
    स्थिती TOK_ELSE:
        next_nomacro();
        जर (s1->ifdef_चळत_ptr == s1->ifdef_चळत)
            tcc_error("#else without matching #if");
        जर (s1->ifdef_चळत_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_चळत_ptr[-1] ^= 3);
        जा test_else;
    स्थिती TOK_ELIF:
        जर (s1->ifdef_चळत_ptr == s1->ifdef_चळत)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_चळत_ptr[-1];
        जर (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        जर (c == 1) {
            skip_to_eol(0);
            c = 0;
        } अन्यथा {
            c = अभिव्यक्ती_preprocess(s1);
            s1->ifdef_चळत_ptr[-1] = c;
        }
    test_else:
        जर (s1->ifdef_चळत_ptr == file->ifdef_चळत_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        जर (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            जा redo;
        }
        थांबा;
    स्थिती TOK_ENDIF:
        next_nomacro();
        जर (s1->ifdef_चळत_ptr <= file->ifdef_चळत_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_चळत_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        जर (file->ifndef_macro &&
            s1->ifdef_चळत_ptr == file->ifdef_चळत_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        थांबा;

    स्थिती TOK_ओळ:
        parse_flags &= ~PARSE_FLAG_TOK_अंक;
        next();
        जर (tok != TOK_PPNUM) {
    ओळ_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        जा ओळ_अंक_2;
    स्थिती TOK_PPNUM:
        जर (parse_flags & PARSE_FLAG_ASM_FILE)
            जा ignore;
        c = 0; /* no error with extra tokens */
    ओळ_अंक_2:
        साठी (n = 0, q = tokc.str.data; *q; ++q) {
            जर (!isnum(*q))
                जा ओळ_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        जर (tok != TOK_LINEFEED) {
            जर (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                जा ओळ_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        जर (file->fd > 0)
            total_ओळी += file->ओळ_अंक - n;
        file->ओळ_अंक = n;
        थांबा;

    स्थिती TOK_ERROR:
    स्थिती TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        पर्यंत (c != '\n' && c != CH_EOF) {
            जर ((q - buf) < आकार(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        जर (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        अन्यथा
            tcc_warning("#warning %s", buf);
        next_nomacro();
        थांबा;
    }
    स्थिती TOK_PRAGMA:
        जर (!pragma_parse(s1))
            जा ignore;
        थांबा;
    स्थिती TOK_LINEFEED:
        जा the_end;
    पूर्वनिर्धारित:
        /* ignore gas line comment in an 'S' file. */
        जर (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            जा ignore;
        जर (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            जा ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        जा the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
स्थिर शून्य parse_escape_string(CString *outstr, स्थिरांक uint8_t *buf, पूर्णांक is_long)
{
    पूर्णांक c, n, i;
    स्थिरांक uint8_t *p;

    p = buf;
    साठी(;;) {
        c = *p;
        जर (c == '\0')
            थांबा;
        जर (c == '\\') {
            p++;
            /* escape */
            c = *p;
            निवड(c) {
            स्थिती '0': स्थिती '1': स्थिती '2': स्थिती '3':
            स्थिती '4': स्थिती '5': स्थिती '6': स्थिती '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                जर (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    जर (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                जा add_char_nonext;
            स्थिती 'x': i = 0; जा parse_hex_or_ucn;
            स्थिती 'u': i = 4; जा parse_hex_or_ucn;
            स्थिती 'U': i = 8; जा parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                करा {
                    c = *p;
                    जर (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    अन्यथा जर (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    अन्यथा जर (isnum(c))
                        c = c - '0';
                    अन्यथा जर (i >= 0)
                        expect("more hex digits in universal-character-name");
                    अन्यथा
                        जा add_hex_or_ucn;
                    n = (अचिन्हित) n * 16 + c;
                    p++;
                } पर्यंत (--i);
		जर (is_long) {
    add_hex_or_ucn:
                    c = n;
		    जा add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                सुरूठेवा;
            स्थिती 'a':
                c = '\a';
                थांबा;
            स्थिती 'b':
                c = '\b';
                थांबा;
            स्थिती 'f':
                c = '\f';
                थांबा;
            स्थिती 'n':
                c = '\n';
                थांबा;
            स्थिती 'r':
                c = '\r';
                थांबा;
            स्थिती 't':
                c = '\t';
                थांबा;
            स्थिती 'v':
                c = '\v';
                थांबा;
            स्थिती 'e':
                जर (!gnu_ext)
                    जा invalid_escape;
                c = 27;
                थांबा;
            स्थिती '\'':
            स्थिती '\"':
            स्थिती '\\': 
            स्थिती '?':
                थांबा;
            पूर्वनिर्धारित:
            invalid_escape:
                जर (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                अन्यथा
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                थांबा;
            }
        } अन्यथा जर (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            पूर्णांक cont; /* count of continuation bytes */
            पूर्णांक skip; /* how many bytes should skip when error occurred */
            पूर्णांक i;

            /* decode leading byte */
            जर (c < 0xC2) {
	            skip = 1; जा invalid_utf8_sequence;
            } अन्यथा जर (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } अन्यथा जर (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } अन्यथा जर (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } अन्यथा {
	            skip = 1; जा invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            साठी (i = 1; i <= cont; i++) {
                पूर्णांक l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                जर (i == 1) {
                    निवड (c) {
                    स्थिती 0xE0: l = 0xA0; थांबा;
                    स्थिती 0xED: h = 0x9F; थांबा;
                    स्थिती 0xF0: l = 0x90; थांबा;
                    स्थिती 0xF4: h = 0x8F; थांबा;
                    }
                }

                जर (p[i] < l || p[i] > h) {
                    skip = i; जा invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            जा add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            जा add_char_nonext;

        }
        p++;
    add_char_nonext:
        जर (!is_long)
            cstr_ccat(outstr, c);
        अन्यथा {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            जर (c < 0x10000) {
                cstr_wccat(outstr, c);
            } अन्यथा {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#अन्यथा
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    जर (!is_long)
        cstr_ccat(outstr, '\0');
    अन्यथा
        cstr_wccat(outstr, '\0');
}

स्थिर शून्य parse_string(स्थिरांक अक्षर *s, पूर्णांक len)
{
    uint8_t buf[1000], *p = buf;
    पूर्णांक is_long, sep;

    जर ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    जर (len >= आकार buf)
        p = tcc_malloc(len + 1);
    स_नकल(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    जर (p != buf)
        tcc_free(p);

    जर (sep == '\'') {
        पूर्णांक char_size, i, n, c;
        /* XXX: make it portable */
        जर (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        अन्यथा
            tok = TOK_LCHAR, char_size = आकार(nwchar_t);
        n = tokcstr.size / char_size - 1;
        जर (n < 1)
            tcc_error("empty character constant");
        जर (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        साठी (c = i = 0; i < n; ++i) {
            जर (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            अन्यथा
                c = (c << 8) | ((अक्षर *)tokcstr.data)[i];
        }
        tokc.i = c;
    } अन्यथा {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        जर (!is_long)
            tok = TOK_STR;
        अन्यथा
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
स्थिर पूर्णांक bn_lshift(अचिन्हित पूर्णांक *bn, पूर्णांक shift, पूर्णांक or_val)
{
    पूर्णांक i;
    अचिन्हित पूर्णांक v;
    जर (bn[BN_SIZE - 1] >> (32 - shift))
	परत shift;
    साठी(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    परत 0;
}

स्थिर शून्य bn_zero(अचिन्हित पूर्णांक *bn)
{
    पूर्णांक i;
    साठी(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
स्थिर शून्य parse_संख्या(स्थिरांक अक्षर *p)
{
    पूर्णांक b, t, shift, frac_bits, s, exp_val, ch;
    अक्षर *q;
    अचिन्हित पूर्णांक bn[BN_SIZE];
    दीर्घ द्विगुण d;

    /*संख्या*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    जर (t == '.') {
        जा float_frac_parse;
    } अन्यथा जर (t == '0') {
        जर (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } अन्यथा जर (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    पर्यंत (1) {
        जर (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        अन्यथा जर (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        अन्यथा जर (isnum(ch))
            t = ch - '0';
        अन्यथा
            थांबा;
        जर (t >= b)
            थांबा;
        जर (q >= token_buf + STRING_MAX_SIZE) {
        अंक_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    जर (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        जर (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            जर (b == 16)
                shift = 4;
            अन्यथा 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            पर्यंत (1) {
                t = *q++;
                जर (t == '\0') {
                    थांबा;
                } अन्यथा जर (t >= 'a') {
                    t = t - 'a' + 10;
                } अन्यथा जर (t >= 'A') {
                    t = t - 'A' + 10;
                } अन्यथा {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            जर (ch == '.') {
                ch = *p++;
                पर्यंत (1) {
                    t = ch;
                    जर (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } अन्यथा जर (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } अन्यथा जर (t >= '0' && t <= '9') {
                        t = t - '0';
                    } अन्यथा {
                        थांबा;
                    }
                    जर (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            जर (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            जर (ch == '+') {
                ch = *p++;
            } अन्यथा जर (ch == '-') {
                s = -1;
                ch = *p++;
            }
            जर (ch < '0' || ch > '9')
                expect("exponent digits");
            पर्यंत (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		जर (exp_val < 100000000)
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
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            जर (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (दशांश)d;
            } अन्यथा जर (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = (द्विगुण)d;
            }
        } अन्यथा {
            /* decimal floats */
            जर (ch == '.') {
                जर (q >= token_buf + STRING_MAX_SIZE)
                    जा अंक_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                पर्यंत (ch >= '0' && ch <= '9') {
                    जर (q >= token_buf + STRING_MAX_SIZE)
                        जा अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            जर (ch == 'e' || ch == 'E') {
                जर (q >= token_buf + STRING_MAX_SIZE)
                    जा अंक_too_long;
                *q++ = ch;
                ch = *p++;
                जर (ch == '-' || ch == '+') {
                    जर (q >= token_buf + STRING_MAX_SIZE)
                        जा अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                जर (ch < '0' || ch > '9')
                    expect("exponent digits");
                पर्यंत (ch >= '0' && ch <= '9') {
                    जर (q >= token_buf + STRING_MAX_SIZE)
                        जा अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            त्रुटि_सं = 0;
            जर (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, रिक्त);
            } अन्यथा जर (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, रिक्त);
            } अन्यथा {
                tok = TOK_CDOUBLE;
                tokc.d = म_से_भग्न(token_buf, रिक्त);
            }
        }
    } अन्यथा {
        अचिन्हित दीर्घ दीर्घ n, n1;
        पूर्णांक lcount, ucount, ov = 0;
        स्थिरांक अक्षर *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        जर (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        पर्यंत(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            जर (t == '\0')
                थांबा;
            अन्यथा जर (t >= 'a')
                t = t - 'a' + 10;
            अन्यथा जर (t >= 'A')
                t = t - 'A' + 10;
            अन्यथा
                t = t - '0';
            जर (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            जर (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        साठी(;;) {
            t = toup(ch);
            जर (t == 'L') {
                जर (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                जर (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } अन्यथा जर (t == 'U') {
                जर (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } अन्यथा {
                थांबा;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        जर (pp_अभिव्यक्ती)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        जर (ucount == 0 && b == 10) {
            जर (lcount <= (LONG_SIZE == 4)) {
                जर (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            जर (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } अन्यथा {
            जर (lcount <= (LONG_SIZE == 4)) {
                जर (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                अन्यथा जर (n >= 0x80000000U)
                    ucount = 1;
            }
            जर (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        जर (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	जर (lcount) {
            tok = TOK_CLONG;
            जर (lcount == 2)
                tok = TOK_CLLONG;
	}
	जर (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    जर (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    स्थिती c1:                                    \
        PEEKC(c, p);                            \
        जर (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } अन्यथा {                                \
            tok = tok1;                         \
        }                                       \
        थांबा;

/* return next token without macro substitution */
स्थिर शून्य next_nomacro(शून्य)
{
    पूर्णांक t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    अचिन्हित पूर्णांक h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    निवड(c) {
    स्थिती ' ':
    स्थिती '\t':
        tok = c;
        p++;
 maybe_space:
        जर (parse_flags & PARSE_FLAG_SPACES)
            जा keep_tok_flags;
        पर्यंत (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        जा redo_no_start;
    स्थिती '\f':
    स्थिती '\v':
    स्थिती '\r':
        p++;
        जा redo_no_start;
    स्थिती '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        जर (c == '\\')
            जा parse_simple;
        जर (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            जर (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                जा maybe_newline;
            } अन्यथा जर (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } अन्यथा जर (s1->ifdef_चळत_ptr != file->ifdef_चळत_ptr) {
                tcc_error("missing #endif");
            } अन्यथा जर (s1->include_चळत_ptr == s1->include_चळत) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } अन्यथा {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                जर (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    म_लिखो("#endif %s\n", get_tok_str(file->ifndef_macro_saved, रिक्त));
#endif
                    शोध_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_चळत_ptr--;
                p = file->buf_ptr;
                जा maybe_newline;
            }
        } अन्यथा {
            जा redo_no_start;
        }
        थांबा;

    स्थिती '\n':
        file->ओळ_अंक++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        जर (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            जा redo_no_start;
        tok = TOK_LINEFEED;
        जा keep_tok_flags;

    स्थिती '#':
        /* XXX: simplify */
        PEEKC(c, p);
        जर ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            जा maybe_newline;
        } अन्यथा {
            जर (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } अन्यथा {
#जर !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                जर (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_ओळ_comment(p - 1);
                    जा redo_no_start;
                } अन्यथा
#endif
                {
                    tok = '#';
                }
            }
        }
        थांबा;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    स्थिती '$':
        जर (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            जा parse_simple;

    स्थिती 'a': स्थिती 'b': स्थिती 'c': स्थिती 'd':
    स्थिती 'e': स्थिती 'f': स्थिती 'g': स्थिती 'h':
    स्थिती 'i': स्थिती 'j': स्थिती 'k': स्थिती 'l':
    स्थिती 'm': स्थिती 'n': स्थिती 'o': स्थिती 'p':
    स्थिती 'q': स्थिती 'r': स्थिती 's': स्थिती 't':
    स्थिती 'u': स्थिती 'v': स्थिती 'w': स्थिती 'x':
    स्थिती 'y': स्थिती 'z': 
    स्थिती 'A': स्थिती 'B': स्थिती 'C': स्थिती 'D':
    स्थिती 'E': स्थिती 'F': स्थिती 'G': स्थिती 'H':
    स्थिती 'I': स्थिती 'J': स्थिती 'K': 
    स्थिती 'M': स्थिती 'N': स्थिती 'O': स्थिती 'P':
    स्थिती 'Q': स्थिती 'R': स्थिती 'S': स्थिती 'T':
    स्थिती 'U': स्थिती 'V': स्थिती 'W': स्थिती 'X':
    स्थिती 'Y': स्थिती 'Z': 
    स्थिती '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        पर्यंत (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        जर (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            साठी(;;) {
                ts = *pts;
                जर (!ts)
                    थांबा;
                जर (ts->len == len && !स_भेद(ts->str, p1, len))
                    जा token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (अक्षर *) p1, len);
        token_found: ;
        } अन्यथा {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (अक्षर *) p1, len);
            p--;
            PEEKC(c, p);
            पर्यंत (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        थांबा;
    स्थिती 'L':
        t = p[1];
        जर (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            जर (c == '\'' || c == '\"') {
                is_long = 1;
                जा str_const;
            }
            *--p = c = 'L';
        }
        जा parse_ident_fast;

    स्थिती '0': स्थिती '1': स्थिती '2': स्थिती '3':
    स्थिती '4': स्थिती '5': स्थिती '6': स्थिती '7':
    स्थिती '8': स्थिती '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_अंक:
        cstr_reset(&tokcstr);
        साठी(;;) {
            cstr_ccat(&tokcstr, t);
            जर (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((अक्षर*)tokcstr.data)[0] == '0'
                                && toup(((अक्षर*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                थांबा;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        थांबा;

    स्थिती '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        जर (isnum(c)) {
            t = '.';
            जा parse_अंक;
        } अन्यथा जर ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))) {
            *--p = c = '.';
            जा parse_ident_fast;
        } अन्यथा जर (c == '.') {
            PEEKC(c, p);
            जर (c == '.') {
                p++;
                tok = TOK_DOTS;
            } अन्यथा {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } अन्यथा {
            tok = '.';
        }
        थांबा;
    स्थिती '\'':
    स्थिती '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        जर (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        थांबा;

    स्थिती '<':
        PEEKC(c, p);
        जर (c == '=') {
            p++;
            tok = TOK_LE;
        } अन्यथा जर (c == '<') {
            PEEKC(c, p);
            जर (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } अन्यथा {
                tok = TOK_SHL;
            }
        } अन्यथा {
            tok = TOK_LT;
        }
        थांबा;
    स्थिती '>':
        PEEKC(c, p);
        जर (c == '=') {
            p++;
            tok = TOK_GE;
        } अन्यथा जर (c == '>') {
            PEEKC(c, p);
            जर (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } अन्यथा {
                tok = TOK_SAR;
            }
        } अन्यथा {
            tok = TOK_GT;
        }
        थांबा;
        
    स्थिती '&':
        PEEKC(c, p);
        जर (c == '&') {
            p++;
            tok = TOK_LAND;
        } अन्यथा जर (c == '=') {
            p++;
            tok = TOK_A_AND;
        } अन्यथा {
            tok = '&';
        }
        थांबा;
        
    स्थिती '|':
        PEEKC(c, p);
        जर (c == '|') {
            p++;
            tok = TOK_LOR;
        } अन्यथा जर (c == '=') {
            p++;
            tok = TOK_A_OR;
        } अन्यथा {
            tok = '|';
        }
        थांबा;

    स्थिती '+':
        PEEKC(c, p);
        जर (c == '+') {
            p++;
            tok = TOK_INC;
        } अन्यथा जर (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } अन्यथा {
            tok = '+';
        }
        थांबा;
        
    स्थिती '-':
        PEEKC(c, p);
        जर (c == '-') {
            p++;
            tok = TOK_DEC;
        } अन्यथा जर (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } अन्यथा जर (c == '>') {
            p++;
            tok = TOK_ARROW;
        } अन्यथा {
            tok = '-';
        }
        थांबा;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    स्थिती '/':
        PEEKC(c, p);
        जर (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            जा maybe_space;
        } अन्यथा जर (c == '/') {
            p = parse_ओळ_comment(p);
            tok = ' ';
            जा maybe_space;
        } अन्यथा जर (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } अन्यथा {
            tok = '/';
        }
        थांबा;
        
        /* simple tokens */
    स्थिती '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        जर (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_ओळ_comment(p);
            जा redo_no_start;
        }
#endif
    स्थिती '(':
    स्थिती ')':
    स्थिती '[':
    स्थिती ']':
    स्थिती '{':
    स्थिती '}':
    स्थिती ',':
    स्थिती ';':
    स्थिती ':':
    स्थिती '?':
    स्थिती '~':
    parse_simple:
        tok = c;
        p++;
        थांबा;
    स्थिती 0xEF: /* UTF8 BOM ? */
        जर (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            जा redo_no_start;
        }
    पूर्वनिर्धारित:
        जर (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    जा parse_ident_fast;
        जर (parse_flags & PARSE_FLAG_ASM_FILE)
            जा parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        थांबा;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#जर defined(PARSE_DEBUG)
    म_लिखो("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
स्थिर पूर्णांक indent;
स्थिर शून्य define_print(TCCState *s1, पूर्णांक v);
स्थिर शून्य pp_print(स्थिरांक अक्षर *संदेश, पूर्णांक v, स्थिरांक पूर्णांक *str)
{
    खाता *fp = tcc_state->ppfp;

    जर (संदेश[0] == '#' && indent == 0)
        ख_लिखो(fp, "\n");
    अन्यथा जर (संदेश[0] == '+')
         ++indent, ++संदेश;
    अन्यथा जर (संदेश[0] == '-')
        --indent, ++संदेश;

    ख_लिखो(fp, "%*s", indent, "");
    जर (संदेश[0] == '#') {
        define_print(tcc_state, v);
    } अन्यथा {
        tok_print(str, v ? "%s %s" : "%s", संदेश, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#अन्यथा
#define PP_PRINT(x)
#endif

स्थिर पूर्णांक macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    स्थिरांक पूर्णांक *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
स्थिर पूर्णांक *macro_arg_subst(Sym **nested_list, स्थिरांक पूर्णांक *macro_str, Sym *args)
{
    पूर्णांक t, t0, t1, t2, n;
    स्थिरांक पूर्णांक *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    साठी (s = args, n = 0; s; s = s->prev, ++n);
    पर्यंत (n--) {
        साठी (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    पर्यंत(1) {
        TOK_GET(&t, &macro_str, &cval);
        जर (!t)
            थांबा;
        जर (t == '#') {
            /* stringize */
            करा t = *macro_str++; पर्यंत (t == ' ');
            s = sym_find2(args, t);
            जर (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                पर्यंत (*st != TOK_EOF) {
                    स्थिरांक अक्षर *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    पर्यंत (*s) {
                        जर (t == TOK_PPSTR && *s != '\'')
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
                cval.str.size = tokcstr.size;
                cval.str.data = tokcstr.data;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#ifdef TCC_TARGET_ARM
            } अन्यथा जर ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } अन्यथा {
                expect("macro parameter after '#'");
            }
        } अन्यथा जर (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            जर (s) {
                st = s->d;
                n = 0;
                पर्यंत ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                जर (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    जर (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        पूर्णांक c = str.str[str.len - 1];
                        पर्यंत (str.str[--str.len] != ',')
                            ;
                        जर (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } अन्यथा {
                            /* suppress '##' and add variable */
                            str.len++;
                            जर (c == ' ')
                                str.str[str.len++] = c;
                            जा add_var;
                        }
                    } अन्यथा {
                        जर (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } अन्यथा {
            add_var:
		    जर (!s->e) {
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
                पर्यंत (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } अन्यथा {
                tok_str_add(&str, t);
            }
        } अन्यथा {
            tok_str_add2(&str, t, &cval);
        }
        जर (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    परत str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
स्थिर ओळीत पूर्णांक *macro_twosharps(स्थिरांक पूर्णांक *ptr0)
{
    पूर्णांक t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    स्थिरांक पूर्णांक *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    साठी (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        जर (t1 == 0)
            थांबा;
        साठी (;;) {
            n = 0;
            पर्यंत ((t2 = ptr[n]) == ' ')
                ++n;
            जर (t2 != TOK_PPJOIN)
                थांबा;
            ptr += n;
            पर्यंत ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            जर (t2 == TOK_PLCHLDR)
                सुरूठेवा;
            जर (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        जर (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            स_नकल(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            साठी (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                जर (*file->buf_ptr == 0)
                    थांबा;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        जर (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    परत macro_str1.str;
}

स्थिर पूर्णांक peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    पूर्णांक c;
    साठी (;;) {
        PEEKC(c, p);
        निवड (c) {
        स्थिती '/':
            PEEKC(c, p);
            जर (c == '*')
                p = parse_comment(p);
            अन्यथा जर (c == '/')
                p = parse_ओळ_comment(p);
            अन्यथा {
                c = *--p = '/';
                जा leave;
            }
            --p, c = ' ';
            थांबा;
        स्थिती ' ': स्थिती '\t':
            थांबा;
        स्थिती '\f': स्थिती '\v': स्थिती '\r':
            सुरूठेवा;
        स्थिती '\n':
            file->ओळ_अंक++, tok_flags |= TOK_FLAG_BOL;
            थांबा;
        पूर्वनिर्धारित: leave:
            file->buf_ptr = p;
            परत c;
        }
        जर (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
स्थिर पूर्णांक next_argstream(Sym **nested_list, TokenString *ws_str)
{
    पूर्णांक t;
    Sym *sa;

    पर्यंत (macro_ptr) {
        स्थिरांक पूर्णांक *m = macro_ptr;
        पर्यंत ((t = *m) != 0) {
            जर (ws_str) {
                जर (t != ' ')
                    परत t;
                ++m;
            } अन्यथा {
                TOK_GET(&tok, &macro_ptr, &tokc);
                परत tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        जर (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    जर (ws_str) {
        परत peek_file(ws_str);
    } अन्यथा {
        next_nomacro();
        जर (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        परत tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
स्थिर पूर्णांक macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    पूर्णांक t;
    पूर्णांक v = s->v;

    PP_PRINT(("#", v, s->d));
    जर (s->d) {
        पूर्णांक *mstr = s->d;
        पूर्णांक *jstr;
        Sym *sa;
        पूर्णांक ret;

        जर (s->type.t & MACRO_FUNC) {
            पूर्णांक saved_parse_flags = parse_flags;
            TokenString str;
            पूर्णांक parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            जर (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                जर (parse_flags & PARSE_FLAG_SPACES)
                    साठी (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                परत 0;
            } अन्यथा {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = रिक्त;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            साठी(;;) {
                करा {
                    t = next_argstream(nested_list, रिक्त);
                } पर्यंत (t == ' ' || --i);

                जर (!sa) {
                    जर (t == ')') /* handle '()' case */
                        थांबा;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                पर्यंत (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    जर (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    जर (t == '(')
                        parlevel++;
                    जर (t == ')')
                        parlevel--;
                    जर (t == ' ')
                        str.need_spc |= 1;
                    अन्यथा
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, रिक्त);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                जर (t == ')') {
                    जर (!sa)
                        थांबा;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    जर (sa->type.t && gnu_ext)
                        जा empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            पर्यंत (sa) {
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
        जर (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        जर (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        जर (jstr != mstr)
            tok_str_free_str(jstr);
        जर (mstr != s->d)
            tok_str_free_str(mstr);
        परत ret;

    } अन्यथा {
        CValue cval;
        अक्षर buf[32], *cstrval = buf;

        /* special macros */
        जर (v == TOK_ओळ_2 || v == TOK___COUNTER__) {
            t = v == TOK_ओळ_2 ? file->ओळ_अंक : pp_counter++;
            snprintf(buf, आकार(buf), "%d", t);
            t = TOK_PPNUM;
            जा add_cstr1;

        } अन्यथा जर (v == TOK___FILE__) {
            cstrval = file->filename;
            जा add_cstr;

        } अन्यथा जर (v == TOK___DATE__ || v == TOK___TIME__) {
            समय_प्रकार ti;
            संरचना पंचांग *पंचांग;
            समय(&ti);
            पंचांग = स_स्थानीय(&ti);
            जर (v == TOK___DATE__) {
                स्थिर अक्षर स्थिरांक ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, आकार(buf), "%s %2d %d",
                    ab_month_name[पंचांग->tm_mon], पंचांग->tm_mday, पंचांग->tm_year + 1900);
            } अन्यथा {
                snprintf(buf, आकार(buf), "%02d:%02d:%02d",
                    पंचांग->tm_hour, पंचांग->tm_min, पंचांग->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = म_माप(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        परत 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
स्थिर पूर्णांक macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    स्थिरांक पूर्णांक *macro_str
    )
{
    Sym *s;
    पूर्णांक t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    पूर्णांक tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    पर्यंत (1) {
        TOK_GET(&t, &macro_str, &cval);
        जर (t == 0 || t == TOK_EOF)
            थांबा;
        जर (t >= TOK_IDENT) {
            s = define_find(t);
            जर (s == रिक्त || nosubst)
                जा no_subst;
            /* if nested substitution, do nothing */
            जर (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                जा no_subst;
            }
            str = tok_str_alloc();
            str->str = (पूर्णांक*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            जर (macro_चळत != str) {
                /* already finished by reading function macro arguments */
                थांबा;
            }
            macro_str = macro_ptr;
            end_macro ();
        } अन्यथा जर (t == ' ') {
            जर (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } अन्यथा {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            जर (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            जर (t == TOK_DEFINED && pp_अभिव्यक्ती)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    परत nosubst;
}

/* return next token with macro substitution */
ST_FUNC शून्य next(शून्य)
{
    पूर्णांक t;
    पर्यंत (macro_ptr) {
redo:
        t = *macro_ptr;
        जर (TOK_HAS_मूल्य(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            जर (t == TOK_LINENUM) {
                file->ओळ_अंक = tokc.i;
                जा redo;
            }
            जा convert;
        } अन्यथा जर (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            सुरूठेवा;
        } अन्यथा जर (t == TOK_EOF) {
            /* do nothing */
        } अन्यथा {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            जर (t == '\\') {
                जर (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        परत;
    }

    next_nomacro();
    t = tok;
    जर (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        जर (s) {
            Sym *nested_list = रिक्त;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            जा redo;
        }
        परत;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    जर (t == TOK_PPNUM) {
        जर  (parse_flags & PARSE_FLAG_TOK_अंक)
            parse_संख्या(tokc.str.data);
    } अन्यथा जर (t == TOK_PPSTR) {
        जर (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN शून्य unget_tok(पूर्णांक last_tok)
{
    TokenString *str = &unget_buf;
    पूर्णांक alloc = 0;
    जर (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    जर (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

स्थिर स्थिरांक अक्षर * स्थिरांक target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# जर PTR_SIZE == 8
    "_WIN64\0"
# endif
#अन्यथा
# जर defined TCC_TARGET_MACHO
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
#  जर TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

स्थिर शून्य putdef(CString *cs, स्थिरांक अक्षर *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!म_अक्षर(p, ' ')*2]);
}

स्थिर शून्य putdefs(CString *cs, स्थिरांक अक्षर *p)
{
    पर्यंत (*p)
        putdef(cs, p), p = म_अक्षर(p, 0) + 1;
}

स्थिर शून्य tcc_predefs(TCCState *s1, CString *cs, पूर्णांक is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    जर (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    जर (is_asm)
      putdef(cs, "__ASSEMBLER__");
    जर (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    जर (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    जर (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    जर (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    जर (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    जर (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    जर (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    जर (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    जर (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#जर CONFIG_TCC_PREDEFS
        #अन्तर्भाव "tccdefs_.h" /* include as strings */
#अन्यथा
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC शून्य preprocess_start(TCCState *s1, पूर्णांक filetype)
{
    पूर्णांक is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_चळत_ptr = s1->include_चळत;
    s1->ifdef_चळत_ptr = s1->ifdef_चळत;
    file->ifdef_चळत_ptr = s1->ifdef_चळत_ptr;
    pp_अभिव्यक्ती = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_चळत[0] = 0;
    s1->pack_चळत_ptr = s1->pack_चळत;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    जर (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        जर (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        जर (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_चळत_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        स_नकल(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC शून्य preprocess_end(TCCState *s1)
{
    पर्यंत (macro_चळत)
        end_macro();
    macro_ptr = रिक्त;
    पर्यंत (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC पूर्णांक set_idnum(पूर्णांक c, पूर्णांक val)
{
    पूर्णांक prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    परत prev;
}

ST_FUNC शून्य tccpp_new(TCCState *s)
{
    पूर्णांक i, c;
    स्थिरांक अक्षर *p, *r;

    /* init isid table */
    साठी(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_अंक
            : 0);

    साठी(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    स_रखो(hash_ident, 0, TOK_HASH_SIZE * आकार(TokenSym *));
    स_रखो(s->cached_includes_hash, 0, आकार s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    पर्यंत (*p) {
        r = p;
        साठी(;;) {
            c = *r++;
            जर (c == '\0')
                थांबा;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ढकला(TOK_ओळ_2, MACRO_OBJ, रिक्त, रिक्त);
    define_ढकला(TOK___FILE__, MACRO_OBJ, रिक्त, रिक्त);
    define_ढकला(TOK___DATE__, MACRO_OBJ, रिक्त, रिक्त);
    define_ढकला(TOK___TIME__, MACRO_OBJ, रिक्त, रिक्त);
    define_ढकला(TOK___COUNTER__, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य tccpp_delete(TCCState *s)
{
    पूर्णांक i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    जर (n > total_idents)
        total_idents = n;
    साठी (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = रिक्त;

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

स्थिर पूर्णांक pp_need_space(पूर्णांक a, पूर्णांक b);

स्थिर शून्य tok_print(स्थिरांक पूर्णांक *str, स्थिरांक अक्षर *संदेश, ...)
{
    खाता *fp = tcc_state->ppfp;
    बहु_सूची ap;
    पूर्णांक t, t0, s;
    CValue cval;

    बहु_शुरू(ap, संदेश);
    भख_लिखो(fp, संदेश, ap);
    बहु_पूर्ण(ap);

    s = t0 = 0;
    पर्यंत (str) {
	TOK_GET(&t, &str, &cval);
	जर (t == 0 || t == TOK_EOF)
	    थांबा;
        जर (pp_need_space(t0, t))
            s = 0;
	ख_लिखो(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    ख_लिखो(fp, "\n");
}

स्थिर शून्य pp_ओळ(TCCState *s1, BufferedFile *f, पूर्णांक level)
{
    पूर्णांक d = f->ओळ_अंक - f->ओळ_ref;

    जर (s1->dflag & 4)
	परत;

    जर (s1->Pflag == ओळ_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } अन्यथा जर (level == 0 && f->ओळ_ref && d < 8) {
	पर्यंत (d > 0)
	    ख_माला_दो("\n", s1->ppfp), --d;
    } अन्यथा जर (s1->Pflag == ओळ_MACRO_OUTPUT_FORMAT_STD) {
	ख_लिखो(s1->ppfp, "#line %d \"%s\"\n", f->ओळ_अंक, f->filename);
    } अन्यथा {
	ख_लिखो(s1->ppfp, "# %d \"%s\"%s\n", f->ओळ_अंक, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->ओळ_ref = f->ओळ_अंक;
}

स्थिर शून्य define_print(TCCState *s1, पूर्णांक v)
{
    खाता *fp;
    Sym *s;

    s = define_find(v);
    जर (रिक्त == s || रिक्त == s->d)
        परत;

    fp = s1->ppfp;
    ख_लिखो(fp, "#define %s", get_tok_str(v, रिक्त));
    जर (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        ख_लिखो(fp,"(");
        जर (a)
            साठी (;;) {
                ख_लिखो(fp,"%s", get_tok_str(a->v, रिक्त));
                जर (!(a = a->next))
                    थांबा;
                ख_लिखो(fp,",");
            }
        ख_लिखो(fp,")");
    }
    tok_print(s->d, "");
}

स्थिर शून्य pp_debug_defines(TCCState *s1)
{
    पूर्णांक v, t;
    स्थिरांक अक्षर *vs;
    खाता *fp;

    t = pp_debug_tok;
    जर (t == 0)
        परत;

    file->ओळ_अंक--;
    pp_ओळ(s1, file, 0);
    file->ओळ_ref = ++file->ओळ_अंक;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, रिक्त);
    जर (t == TOK_DEFINE) {
        define_print(s1, v);
    } अन्यथा जर (t == TOK_UNDEF) {
        ख_लिखो(fp, "#undef %s\n", vs);
    } अन्यथा जर (t == TOK_ढकला_macro) {
        ख_लिखो(fp, "#pragma push_macro(\"%s\")\n", vs);
    } अन्यथा जर (t == TOK_काढा_macro) {
        ख_लिखो(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
स्थिर पूर्णांक pp_need_space(पूर्णांक a, पूर्णांक b)
{
    परत 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
स्थिर पूर्णांक pp_check_he0xE(पूर्णांक t, स्थिरांक अक्षर *p)
{
    जर (t == TOK_PPNUM && toup(म_अक्षर(p, 0)[-1]) == 'E')
        परत 'E';
    परत t;
}

/* Preprocess the current file */
ST_FUNC पूर्णांक tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    पूर्णांक token_seen, spcs, level;
    स्थिरांक अक्षर *p;
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
    जर (s1->Pflag == ओळ_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_अंक, s1->Pflag = 1;

    जर (s1->do_bench) {
	/* for PP benchmarks */
	करा next(); पर्यंत (tok != TOK_EOF);
	परत 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    जर (file->prev)
        pp_ओळ(s1, file->prev, level++);
    pp_ओळ(s1, file, level);

    साठी (;;) {
        iptr = s1->include_चळत_ptr;
        next();
        जर (tok == TOK_EOF)
            थांबा;

        level = s1->include_चळत_ptr - iptr;
        जर (level) {
            जर (level > 0)
                pp_ओळ(s1, *iptr, 0);
            pp_ओळ(s1, file, level);
        }
        जर (s1->dflag & 7) {
            pp_debug_defines(s1);
            जर (s1->dflag & 4)
                सुरूठेवा;
        }

        जर (is_space(tok)) {
            जर (spcs < आकार white - 1)
                white[spcs++] = tok;
            सुरूठेवा;
        } अन्यथा जर (tok == TOK_LINEFEED) {
            spcs = 0;
            जर (token_seen == TOK_LINEFEED)
                सुरूठेवा;
            ++file->ओळ_ref;
        } अन्यथा जर (token_seen == TOK_LINEFEED) {
            pp_ओळ(s1, file, 0);
        } अन्यथा जर (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, ख_माला_दो(white, s1->ppfp), spcs = 0;
        ख_माला_दो(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    परत 0;
}

/* ------------------------------------------------------------------------- */
