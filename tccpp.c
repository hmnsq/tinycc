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

ST_DATA पूर्णाङ्क tok_flags;
ST_DATA पूर्णाङ्क parse_flags;

ST_DATA संरचना BufferedFile *file;
ST_DATA पूर्णाङ्क tok;
ST_DATA CValue tokc;
ST_DATA ध्रुव पूर्णाङ्क *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA पूर्णाङ्क tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA पूर्णाङ्क pp_व्यंजक;

/* ------------------------------------------------------------------------- */

स्थिर TokenSym *hash_ident[TOK_HASH_SIZE];
स्थिर वर्ण token_buf[STRING_MAX_SIZE + 1];
स्थिर CString cstr_buf;
स्थिर TokenString tokstr_buf;
स्थिर TokenString unget_buf;
स्थिर अचिन्हित वर्ण isidnum_table[256 - CH_EOF];
स्थिर पूर्णाङ्क pp_debug_tok, pp_debug_symv;
स्थिर पूर्णाङ्क pp_counter;
स्थिर शून्य tok_print(ध्रुव पूर्णाङ्क *str, ध्रुव वर्ण *संदेश, ...);
स्थिर शून्य next_nomacro(शून्य);
स्थिर शून्य parse_संख्या(ध्रुव वर्ण *p);
स्थिर शून्य parse_string(ध्रुव वर्ण *p, पूर्णाङ्क len);

स्थिर संरचना TinyAlloc *toksym_alloc;
स्थिर संरचना TinyAlloc *tokstr_alloc;

स्थिर TokenString *macro_ढेर;

स्थिर ध्रुव वर्ण tcc_keywords[] = 
#define DEF(id, str) str "\0"
#अन्तर्भाव "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
स्थिर ध्रुव अचिन्हित वर्ण tok_two_chars[] =
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

ST_FUNC शून्य skip(पूर्णाङ्क c)
{
    यदि (tok != c) {
        वर्ण tmp[40];
        pstrcpy(tmp, परिमाण tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC शून्य expect(ध्रुव वर्ण *संदेश)
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
#यदि !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#अन्यथा
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ध्रुव वर्ण *sfile, पूर्णाङ्क sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

प्रकारनिर्देश संरचना TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    संरचना TinyAlloc *next;
    अचिन्हित nb_allocs;
    अचिन्हित size;
#यदि TAL_INFO
    अचिन्हित nb_peak;
    अचिन्हित nb_total;
    uint8_t *peak_p;
#endif
    सङ्घ {
        uint8_t buffer[1];
        माप_प्रकार _aligner_;
    };
} TinyAlloc;

प्रकारनिर्देश संरचना tal_header_t {
    माप_प्रकार  size; /* word align */
#यदि TAL_DEBUG
    पूर्णाङ्क     पंक्ति_अंक; /* negative line_num used for double free check */
    वर्ण    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (परिमाण (माप_प्रकार) - 1)) & ~(परिमाण (माप_प्रकार) - 1))

/* ------------------------------------------------------------------------- */

स्थिर TinyAlloc *tal_new(TinyAlloc **pal, अचिन्हित size)
{
    TinyAlloc *al = tcc_malloc(परिमाण(TinyAlloc) - परिमाण (माप_प्रकार) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#यदि TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    प्रत्यागम al;
}

स्थिर शून्य tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#यदि TAL_INFO
    ख_लिखो(मानक_त्रुटि, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#यदि TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#यदि TAL_INFO
    ख_लिखो(मानक_त्रुटि, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    यदि (al->nb_allocs > 0) {
        uint8_t *p;
        ख_लिखो(मानक_त्रुटि, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        यावत् (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            यदि (header->पंक्ति_अंक > 0) {
                ख_लिखो(मानक_त्रुटि, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->पंक्ति_अंक, (पूर्णाङ्क)header->size);
            }
            p += header->size + परिमाण(tal_header_t);
        }
#यदि TAL_DEBUG == 2
        निकास(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    यदि (al)
        गच्छ tail_call;
    *pal = al;
}

स्थिर शून्य tal_free_impl(TinyAlloc **pal, शून्य *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **शीर्ष = pal;
    tal_header_t *header;

    यदि (!p)
        प्रत्यागम;
    header = (tal_header_t *)p - 1;
#यदि TAL_DEBUG
    यदि (header->पंक्ति_अंक < 0) {
        ख_लिखो(मानक_त्रुटि, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        ख_लिखो(मानक_त्रुटि, "%s:%d: %d bytes\n",
                header->file_name, (पूर्णाङ्क)-header->पंक्ति_अंक, (पूर्णाङ्क)header->size);
    } अन्यथा
        header->पंक्ति_अंक = -header->पंक्ति_अंक;
#endif
    al = *pal;
    यावत् ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    यदि (0 == --al->nb_allocs) {
        *pal = al->next;
        यदि ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } अन्यथा {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *शीर्ष, *शीर्ष = al;
        }
    } अन्यथा यदि ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

स्थिर शून्य *tal_realloc_impl(TinyAlloc **pal, शून्य *p, अचिन्हित size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    शून्य *ret;
    अचिन्हित adj_size = TAL_ALIGN(size) + परिमाण(tal_header_t);
    TinyAlloc *al = *pal;

    यदि (p) {
        /* reallpc case */
        यावत् ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        यदि ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        यदि (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            स_नकल(ret, p, header->size);
            tal_free(pal, p);
            प्रत्यागम ret;
        } अन्यथा यदि (al->p != (uint8_t*)header) {
            स_नकल((tal_header_t*)al->p + 1, p, header->size);
#यदि TAL_DEBUG
            header->पंक्ति_अंक = -header->पंक्ति_अंक;
#endif
        }
    } अन्यथा {
        /* new alloc case */
        यावत् (al->p + adj_size > al->bufend) {
            al = al->next;
            यदि (!al) {
                अचिन्हित new_size = (*pal)->size;
                यदि (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                भङ्ग;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - परिमाण(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#यदि  TAL_DEBUG
    {
        पूर्णाङ्क ofs = म_माप(sfile) + 1 - परिमाण header->file_name;
        म_नकल(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->पंक्ति_अंक = sline;
#यदि TAL_INFO
        यदि (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        यदि (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    प्रत्यागम ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
स्थिर शून्य cstr_realloc(CString *cstr, पूर्णाङ्क new_size)
{
    पूर्णाङ्क size;

    size = cstr->size_allocated;
    यदि (size < 8)
        size = 8; /* no need to allocate a too small first string */
    यावत् (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN शून्य cstr_ccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क size;
    size = cstr->size + 1;
    यदि (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN वर्ण *unicode_to_utf8 (वर्ण *b, uint32_t Uc)
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
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC शून्य cstr_cat(CString *cstr, ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    पूर्णाङ्क size;
    यदि (len <= 0)
        len = म_माप(str) + 1 + len;
    size = cstr->size + len;
    यदि (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    स_हटाओ(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC शून्य cstr_wccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क size;
    size = cstr->size + परिमाण(nwchar_t);
    यदि (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - परिमाण(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC शून्य cstr_new(CString *cstr)
{
    स_रखो(cstr, 0, परिमाण(CString));
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

ST_FUNC पूर्णाङ्क cstr_vprintf(CString *cstr, ध्रुव वर्ण *fmt, बहु_सूची ap)
{
    बहु_सूची v;
    पूर्णाङ्क len, size = 80;
    प्रति (;;) {
        size += cstr->size;
        यदि (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        बहु_पूर्ण(v);
        यदि (len >= 0 && len < size)
            भङ्ग;
        size *= 2;
    }
    cstr->size += len;
    प्रत्यागम len;
}

ST_FUNC पूर्णाङ्क cstr_printf(CString *cstr, ध्रुव वर्ण *fmt, ...)
{
    बहु_सूची ap; पूर्णाङ्क len;
    बहु_शुरू(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    बहु_पूर्ण(ap);
    प्रत्यागम len;
}

/* XXX: unicode ? */
स्थिर शून्य add_char(CString *cstr, पूर्णाङ्क c)
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
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * परिमाण(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, परिमाण(TokenSym) + len);
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
    प्रत्यागम ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    TokenSym *ts, **pts;
    पूर्णाङ्क i;
    अचिन्हित पूर्णाङ्क h;
    
    h = TOK_HASH_INIT;
    प्रति(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((अचिन्हित वर्ण *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    प्रति(;;) {
        ts = *pts;
        यदि (!ts)
            भङ्ग;
        यदि (ts->len == len && !स_भेद(ts->str, str, len))
            प्रत्यागम ts;
        pts = &(ts->hash_next);
    }
    प्रत्यागम tok_alloc_new(pts, str, len);
}

ST_FUNC पूर्णाङ्क tok_alloc_const(ध्रुव वर्ण *str)
{
    प्रत्यागम tok_alloc(str, म_माप(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ध्रुव वर्ण *get_tok_str(पूर्णाङ्क v, CValue *cv)
{
    वर्ण *p;
    पूर्णाङ्क i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    विकल्प(v) {
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        प्र_लिखो(p, "%llu", (अचिन्हित दीर्घ दीर्घ)cv->i);
        भङ्ग;
    पक्ष TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    पक्ष TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        भङ्ग;
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        प्रत्यागम (वर्ण*)cv->str.data;
    पक्ष TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    पक्ष TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        यदि (v == TOK_STR) {
            len = cv->str.size - 1;
            प्रति(i=0;i<len;i++)
                add_char(&cstr_buf, ((अचिन्हित वर्ण *)cv->str.data)[i]);
        } अन्यथा {
            len = (cv->str.size / परिमाण(nwchar_t)) - 1;
            प्रति(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        भङ्ग;

    पक्ष TOK_CFLOAT:
        प्रत्यागम म_नकल(p, "<float>");
    पक्ष TOK_CDOUBLE:
        प्रत्यागम म_नकल(p, "<double>");
    पक्ष TOK_CLDOUBLE:
        प्रत्यागम म_नकल(p, "<long double>");
    पक्ष TOK_LINENUM:
        प्रत्यागम म_नकल(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    पक्ष TOK_LT:
        v = '<';
        गच्छ addv;
    पक्ष TOK_GT:
        v = '>';
        गच्छ addv;
    पक्ष TOK_DOTS:
        प्रत्यागम म_नकल(p, "...");
    पक्ष TOK_A_SHL:
        प्रत्यागम म_नकल(p, "<<=");
    पक्ष TOK_A_SAR:
        प्रत्यागम म_नकल(p, ">>=");
    पक्ष TOK_EOF:
        प्रत्यागम म_नकल(p, "<eof>");
    पक्ष 0: /* anonymous nameless symbols */
        प्रत्यागम म_नकल(p, "<no name>");
    स्वभाव:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        यदि (v < TOK_IDENT) {
            /* search in two bytes table */
            ध्रुव अचिन्हित वर्ण *q = tok_two_chars;
            यावत् (*q) {
                यदि (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    प्रत्यागम cstr_buf.data;
                }
                q += 3;
            }
            यदि (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                प्र_लिखो(p, "<\\x%02x>", v);
                भङ्ग;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } अन्यथा यदि (v < tok_ident) {
            प्रत्यागम table_ident[v - TOK_IDENT]->str;
        } अन्यथा यदि (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            प्र_लिखो(p, "L.%u", v - SYM_FIRST_ANOM);
        } अन्यथा {
            /* should never happen */
            प्रत्यागम रिक्त;
        }
        भङ्ग;
    }
    प्रत्यागम cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
स्थिर पूर्णाङ्क handle_eob(शून्य)
{
    BufferedFile *bf = file;
    पूर्णाङ्क len;

    /* only tries to read if really end of buffer */
    यदि (bf->buf_ptr >= bf->buf_end) {
        यदि (bf->fd >= 0) {
#यदि defined(PARSE_DEBUG)
            len = 1;
#अन्यथा
            len = IO_BUF_SIZE;
#endif
            len = पठ(bf->fd, bf->buffer, len);
            यदि (len < 0)
                len = 0;
        } अन्यथा {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    यदि (bf->buf_ptr < bf->buf_end) {
        प्रत्यागम bf->buf_ptr[0];
    } अन्यथा {
        bf->buf_ptr = bf->buf_end;
        प्रत्यागम CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
स्थिर पूर्णाङ्क next_c(शून्य)
{
    पूर्णाङ्क ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    यदि (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    प्रत्यागम ch;
}

/* input with '\[\r]\n' handling. */
स्थिर पूर्णाङ्क handle_stray_noerror(पूर्णाङ्क err)
{
    पूर्णाङ्क ch;
    यावत् ((ch = next_c()) == '\\') {
        ch = next_c();
        यदि (ch == '\n') {
    newl:
            file->पंक्ति_अंक++;
        } अन्यथा {
            यदि (ch == '\r') {
                ch = next_c();
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

#define ninp() handle_stray_noerror(0)

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
#define PEEKC(c, p)\
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
    } यावत् (isidnum_table[ch - CH_EOF] & IS_SPC);
    प्रत्यागम ch;
}

/* single line C++ comments */
स्थिर uint8_t *parse_पंक्ति_comment(uint8_t *p)
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
            file->पंक्ति_अंक++;
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
                गच्छ add_char;
            } अन्यथा {
                गच्छ redo;
            }
        } अन्यथा यदि (c == '\n') {
        add_lf:
            यदि (ACCEPT_LF_IN_STRINGS) {
                file->पंक्ति_अंक++;
                गच्छ add_char;
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
                गच्छ add_lf;
            यदि (c == CH_EOF)
                गच्छ unterminated_string;
            यदि (str)
                cstr_ccat(str, '\r');
            गच्छ redo;
        } अन्यथा {
        add_char:
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
    पूर्णाङ्क a, start_of_पंक्ति, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_पंक्ति = 1;
    in_warn_or_error = 0;
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
            file->पंक्ति_अंक++;
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
            यदि (in_warn_or_error)
                गच्छ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, रिक्त);
            भङ्ग;
        /* skip comments */
        पक्ष '/':
            यदि (in_warn_or_error)
                गच्छ _default;
            ++p;
            c = handle_bs(&p);
            यदि (c == '*') {
                p = parse_comment(p);
            } अन्यथा यदि (c == '/') {
                p = parse_पंक्ति_comment(p);
            }
            अनुवर्त;
        पक्ष '#':
            p++;
            यदि (start_of_पंक्ति) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                यदि (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    गच्छ the_end;
                यदि (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                अन्यथा यदि (tok == TOK_ENDIF)
                    a--;
                अन्यथा यदि( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                अन्यथा यदि (tok == TOK_LINEFEED)
                    गच्छ redo_start;
                अन्यथा यदि (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_पंक्ति_comment(p - 1);
            }
#यदि !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            अन्यथा यदि (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_पंक्ति_comment(p - 1);
#अन्यथा
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            भङ्ग;
_default:
        स्वभाव:
            p++;
            भङ्ग;
        }
        start_of_पंक्ति = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#यदि 0
/* return the number of additional 'ints' necessary to store the
   token */
स्थिर अन्तःस्थ पूर्णाङ्क tok_size(ध्रुव पूर्णाङ्क *p)
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
	प्रत्यागम 1 + LONG_SIZE / 4;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
        प्रत्यागम 1 + 2;
    पक्ष TOK_CLDOUBLE:
        प्रत्यागम 1 + LDOUBLE_शब्दगण;
    स्वभाव:
        प्रत्यागम 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN शून्य tok_str_new(TokenString *s)
{
    s->str = रिक्त;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_पंक्ति_अंक = -1;
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

ST_FUNC पूर्णाङ्क *tok_str_realloc(TokenString *s, पूर्णाङ्क new_size)
{
    पूर्णाङ्क *str, size;

    size = s->allocated_len;
    यदि (size < 16)
        size = 16;
    यावत् (size < new_size)
        size = size * 2;
    यदि (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * परिमाण(पूर्णाङ्क));
        s->allocated_len = size;
        s->str = str;
    }
    प्रत्यागम s->str;
}

ST_FUNC शून्य tok_str_add(TokenString *s, पूर्णाङ्क t)
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
    str->prev = macro_ढेर;
    str->prev_ptr = macro_ptr;
    str->save_पंक्ति_अंक = file->पंक्ति_अंक;
    macro_ptr = str->str;
    macro_ढेर = str;
}

ST_FUNC शून्य end_macro(शून्य)
{
    TokenString *str = macro_ढेर;
    macro_ढेर = str->prev;
    macro_ptr = str->prev_ptr;
    file->पंक्ति_अंक = str->save_पंक्ति_अंक;
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
    यदि (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    विकल्प(t) {
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_CFLOAT:
    पक्ष TOK_LINENUM:
#यदि LONG_SIZE == 4
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        भङ्ग;
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
        {
            /* Insert the string into the int array. */
            माप_प्रकार nb_शब्दगण =
                1 + (cv->str.size + परिमाण(पूर्णाङ्क) - 1) / परिमाण(पूर्णाङ्क);
            यदि (len + nb_शब्दगण >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_शब्दगण + 1);
            str[len] = cv->str.size;
            स_नकल(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_शब्दगण;
        }
        भङ्ग;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
#यदि LONG_SIZE == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        भङ्ग;
    पक्ष TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        यदि (LDOUBLE_शब्दगण >= 3)
        str[len++] = cv->tab[2];
        यदि (LDOUBLE_शब्दगण >= 4)
        str[len++] = cv->tab[3];
    स्वभाव:
        भङ्ग;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC शून्य tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    यदि (file->पंक्ति_अंक != s->last_पंक्ति_अंक) {
        s->last_पंक्ति_अंक = file->पंक्ति_अंक;
        cval.i = s->last_पंक्ति_अंक;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
स्थिर शून्य tok_str_add2_spc(TokenString *s, पूर्णाङ्क t, CValue *cv)
{
    यदि (s->need_spc == 3)
        tok_str_add(s, ' ');
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
#यदि LONG_SIZE == 4
    पक्ष TOK_CLONG:
#endif
    पक्ष TOK_CINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_LINENUM:
        cv->i = *p++;
        भङ्ग;
#यदि LONG_SIZE == 4
    पक्ष TOK_CULONG:
#endif
    पक्ष TOK_CUINT:
        cv->i = (अचिन्हित)*p++;
        भङ्ग;
    पक्ष TOK_CFLOAT:
	tab[0] = *p++;
	भङ्ग;
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (वर्ण*)p;
        p += (cv->str.size + परिमाण(पूर्णाङ्क) - 1) / परिमाण(पूर्णाङ्क);
        भङ्ग;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
#यदि LONG_SIZE == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#endif
        n = 2;
        गच्छ copy;
    पक्ष TOK_CLDOUBLE:
        n = LDOUBLE_शब्दगण;
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
    यदि (TOK_HAS_मूल्य(_t)) \
        tok_get(t, p, c); \
    अन्यथा \
        *(t) = _t, ++*(p); \
    } यावत् (0)
#endif

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
        यदि (म_भेद(tokcstr.data, get_tok_str(t, &cv)))
            प्रत्यागम 0;
    }
    प्रत्यागम !(*a || *b);
}

/* defines handling */
ST_INLN शून्य define_धकेलो(पूर्णाङ्क v, पूर्णाङ्क macro_type, पूर्णाङ्क *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_ढेर, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    यदि (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, रिक्त));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC शून्य define_undef(Sym *s)
{
    पूर्णाङ्क v = s->v;
    यदि (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = रिक्त;
}

ST_INLN Sym *define_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    यदि ((अचिन्हित)v >= (अचिन्हित)(tok_ident - TOK_IDENT))
        प्रत्यागम रिक्त;
    प्रत्यागम table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC शून्य free_defines(Sym *b)
{
    यावत् (define_ढेर != b) {
        Sym *शीर्ष = define_ढेर;
        define_ढेर = शीर्ष->prev;
        tok_str_free_str(शीर्ष->d);
        define_undef(शीर्ष);
        sym_free(शीर्ष);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
स्थिर शून्य maybe_run_test(TCCState *s)
{
    ध्रुव वर्ण *p;
    यदि (s->include_ढेर_ptr != s->include_ढेर)
        प्रत्यागम;
    p = get_tok_str(tok, रिक्त);
    यदि (0 != स_भेद(p, "test_", 5))
        प्रत्यागम;
    यदि (0 != --s->run_test)
        प्रत्यागम;
    ख_लिखो(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), ख_साफ(s->ppfp);
    define_धकेलो(tok, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य skip_to_eol(पूर्णाङ्क warn)
{
    यदि (tok == TOK_LINEFEED)
        प्रत्यागम;
    यदि (warn)
        tcc_warning("extra tokens after directive");
    यावत् (macro_ढेर)
        end_macro();
    file->buf_ptr = parse_पंक्ति_comment(file->buf_ptr - 1);
    next_nomacro();
}

स्थिर CachedInclude *
खोज_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क add);

स्थिर पूर्णाङ्क parse_include(TCCState *s1, पूर्णाङ्क do_next, पूर्णाङ्क test)
{
    पूर्णाङ्क c, i;
    वर्ण name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    यदि (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, परिमाण name, tokcstr.data, i);
        next_nomacro();
    } अन्यथा {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        प्रति (;;) {
            next();
            p = name, i = म_माप(p) - 1;
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
        स_हटाओ(p, p + 1, i - 1), p[i - 1] = 0;
    }

    यदि (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
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
        e = खोज_cached_include(s1, buf, 0);
        यदि (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            म_लिखो("%s: skipping cached %s\n", file->filename, buf);
#endif
            यदि ((s1->verbose | 1) == 3) /* -vv[v] */
                म_लिखो("=> %*s%s\n",
                   (पूर्णाङ्क)(s1->include_ढेर_ptr - s1->include_ढेर), "", buf);
            प्रत्यागम 1;
        }
        यदि (tcc_open(s1, buf) >= 0)
            भङ्ग;
    }

    यदि (test) {
        tcc_close();
    } अन्यथा {
        यदि (s1->include_ढेर_ptr >= s1->include_ढेर + INCLUDE_ढेर_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ढेर_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        म_लिखो("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        यदि (s1->gen_deps) {
            BufferedFile *bf = file;
            यावत् (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            यदि (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    प्रत्यागम 1;
}

/* eval an expression for #if/#elif */
स्थिर पूर्णाङ्क व्यंजक_preprocess(TCCState *s1)
{
    पूर्णाङ्क c, t;
    पूर्णाङ्क t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_व्यंजक = 1;
    यावत् (1) {
        next(); /* do macro subst */
        t = tok;
        यदि (tok < TOK_IDENT) {
            यदि (tok == TOK_LINEFEED || tok == TOK_EOF)
                भङ्ग;
            यदि (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } अन्यथा यदि (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            यदि (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            यदि (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            यदि (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            यदि (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            यदि (t == '(') {
                next();
                यदि (tok != ')')
                    expect("')'");
            }
            गच्छ c_संख्या;
        } अन्यथा यदि (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    यदि (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            यदि (tok != ')')
                expect("')'");
            गच्छ c_संख्या;
        } अन्यथा {
            /* if undefined macro, replace with zero */
            c = 0;
        c_संख्या:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    यदि (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_व्यंजक = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = व्यंजक_const();
    यदि (tok != TOK_EOF)
        tcc_error("...");
    pp_व्यंजक = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    प्रत्यागम c != 0;
}

ST_FUNC शून्य pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_व्यंजक, 0));
    macro_ptr = macro_ढेर->str;
    यावत् (next(), tok != TOK_EOF)
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
    next_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    यदि (tok == '(') {
        पूर्णाङ्क dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        यदि (tok != ')') प्रति (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            यदि (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } अन्यथा यदि (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            यदि (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ढेर, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            यदि (tok == ')')
                भङ्ग;
            यदि (tok != ',' || is_vaargs)
                गच्छ bad_list;
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
        next_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_add(&str, 0);
    यदि (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_धकेलो(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

स्थिर CachedInclude *खोज_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क add)
{
    ध्रुव वर्ण *s, *basename;
    अचिन्हित पूर्णाङ्क h;
    CachedInclude *e;
    पूर्णाङ्क c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    यावत् ((c = (अचिन्हित वर्ण)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#अन्यथा
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

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
        i = e->hash_next;
    }
    यदि (!add)
        प्रत्यागम रिक्त;

    e = tcc_malloc(परिमाण(CachedInclude) + (len = म_माप(filename)));
    स_नकल(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    म_लिखो("adding cached '%s'\n", filename);
#endif
    प्रत्यागम e;
}

स्थिर पूर्णाङ्क pragma_parse(TCCState *s1)
{
    next_nomacro();
    यदि (tok == TOK_धकेलो_macro || tok == TOK_निकालो_macro) {
        पूर्णाङ्क t = tok, v;
        Sym *s;

        यदि (next(), tok != '(')
            गच्छ pragma_err;
        यदि (next(), tok != TOK_STR)
            गच्छ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        यदि (next(), tok != ')')
            गच्छ pragma_err;
        यदि (t == TOK_धकेलो_macro) {
            यावत् (रिक्त == (s = define_find(v)))
                define_धकेलो(v, 0, रिक्त, रिक्त);
            s->type.ref = s; /* set push boundary */
        } अन्यथा {
            प्रति (s = define_ढेर; s; s = s->prev)
                यदि (s->v == v && s->type.ref == s) {
                    s->type.ref = रिक्त;
                    भङ्ग;
                }
        }
        यदि (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : रिक्त;
        अन्यथा
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } अन्यथा यदि (tok == TOK_once) {
        खोज_cached_include(s1, file->true_filename, 1)->once = 1;

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
        next();
        skip('(');
        यदि (tok == TOK_ASM_निकालो) {
            next();
            यदि (s1->pack_ढेर_ptr <= s1->pack_ढेर) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ढेर_ptr--;
        } अन्यथा {
            पूर्णाङ्क val = 0;
            यदि (tok != ')') {
                यदि (tok == TOK_ASM_धकेलो) {
                    next();
                    यदि (s1->pack_ढेर_ptr >= s1->pack_ढेर + PACK_ढेर_SIZE - 1)
                        गच्छ stk_error;
                    val = *s1->pack_ढेर_ptr++;
                    यदि (tok != ',')
                        गच्छ pack_set;
                    next();
                }
                यदि (tok != TOK_CINT)
                    गच्छ pragma_err;
                val = tokc.i;
                यदि (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    गच्छ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_ढेर_ptr = val;
        }
        यदि (tok != ')')
            गच्छ pragma_err;

    } अन्यथा यदि (tok == TOK_comment) {
        वर्ण *p; पूर्णाङ्क t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        यदि (tok != TOK_STR)
            गच्छ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        यदि (tok != ')')
            गच्छ pragma_err;
        यदि (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } अन्यथा {
            यदि (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } अन्यथा {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        प्रत्यागम 0;
    }
    next();
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
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    यदि (0 == म_भेद(file->filename, buf))
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
        | PARSE_FLAG_TOK_अंक
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    विकल्प(tok) {
    पक्ष TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        भङ्ग;
    पक्ष TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        यदि (s)
            define_undef(s);
        next_nomacro();
        भङ्ग;
    पक्ष TOK_INCLUDE:
    पक्ष TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        गच्छ the_end;
    पक्ष TOK_IFNDEF:
        c = 1;
        गच्छ do_ifdef;
    पक्ष TOK_IF:
        c = व्यंजक_preprocess(s1);
        गच्छ do_if;
    पक्ष TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        यदि (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        यदि (is_bof) {
            यदि (c) {
#ifdef INC_DEBUG
                म_लिखो("#ifndef %s\n", get_tok_str(tok, रिक्त));
#endif
                file->ifndef_macro = tok;
            }
        }
        यदि (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        यदि (s1->ifdef_ढेर_ptr >= s1->ifdef_ढेर + IFDEF_ढेर_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ढेर_ptr++ = c;
        गच्छ test_skip;
    पक्ष TOK_ELSE:
        next_nomacro();
        यदि (s1->ifdef_ढेर_ptr == s1->ifdef_ढेर)
            tcc_error("#else without matching #if");
        यदि (s1->ifdef_ढेर_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ढेर_ptr[-1] ^= 3);
        गच्छ test_else;
    पक्ष TOK_ELIF:
        यदि (s1->ifdef_ढेर_ptr == s1->ifdef_ढेर)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ढेर_ptr[-1];
        यदि (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        यदि (c == 1) {
            skip_to_eol(0);
            c = 0;
        } अन्यथा {
            c = व्यंजक_preprocess(s1);
            s1->ifdef_ढेर_ptr[-1] = c;
        }
    test_else:
        यदि (s1->ifdef_ढेर_ptr == file->ifdef_ढेर_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        यदि (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            गच्छ redo;
        }
        भङ्ग;
    पक्ष TOK_ENDIF:
        next_nomacro();
        यदि (s1->ifdef_ढेर_ptr <= file->ifdef_ढेर_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ढेर_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        यदि (file->ifndef_macro &&
            s1->ifdef_ढेर_ptr == file->ifdef_ढेर_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        भङ्ग;

    पक्ष TOK_पंक्ति:
        parse_flags &= ~PARSE_FLAG_TOK_अंक;
        next();
        यदि (tok != TOK_PPNUM) {
    पंक्ति_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        गच्छ पंक्ति_अंक_2;
    पक्ष TOK_PPNUM:
        यदि (parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        c = 0; /* no error with extra tokens */
    पंक्ति_अंक_2:
        प्रति (n = 0, q = tokc.str.data; *q; ++q) {
            यदि (!isnum(*q))
                गच्छ पंक्ति_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        यदि (tok != TOK_LINEFEED) {
            यदि (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                गच्छ पंक्ति_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        यदि (file->fd > 0)
            total_पंक्तियाँ += file->पंक्ति_अंक - n;
        file->पंक्ति_अंक = n;
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
        next_nomacro();
        भङ्ग;
    }
    पक्ष TOK_PRAGMA:
        यदि (!pragma_parse(s1))
            गच्छ ignore;
        भङ्ग;
    पक्ष TOK_LINEFEED:
        गच्छ the_end;
    स्वभाव:
        /* ignore gas line comment in an 'S' file. */
        यदि (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        यदि (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            गच्छ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        गच्छ the_end;
    }
    skip_to_eol(1);
 the_end:
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
                गच्छ add_char_nonext;
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
                        गच्छ add_hex_or_ucn;
                    n = (अचिन्हित) n * 16 + c;
                    p++;
                } यावत् (--i);
		यदि (is_long) {
    add_hex_or_ucn:
                    c = n;
		    गच्छ add_char_nonext;
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
            गच्छ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            गच्छ add_char_nonext;

        }
        p++;
    add_char_nonext:
        यदि (!is_long)
            cstr_ccat(outstr, c);
        अन्यथा {
#ifdef TCC_TARGET_PE
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
#endif
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
    स_नकल(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    यदि (p != buf)
        tcc_free(p);

    यदि (sep == '\'') {
        पूर्णाङ्क char_size, i, n, c;
        /* XXX: make it portable */
        यदि (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        अन्यथा
            tok = TOK_LCHAR, char_size = परिमाण(nwchar_t);
        n = tokcstr.size / char_size - 1;
        यदि (n < 1)
            tcc_error("empty character constant");
        यदि (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        प्रति (c = i = 0; i < n; ++i) {
            यदि (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            अन्यथा
                c = (c << 8) | ((वर्ण *)tokcstr.data)[i];
        }
        tokc.i = c;
    } अन्यथा {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        यदि (!is_long)
            tok = TOK_STR;
        अन्यथा
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
स्थिर पूर्णाङ्क bn_lshift(अचिन्हित पूर्णाङ्क *bn, पूर्णाङ्क shift, पूर्णाङ्क or_val)
{
    पूर्णाङ्क i;
    अचिन्हित पूर्णाङ्क v;
    यदि (bn[BN_SIZE - 1] >> (32 - shift))
	प्रत्यागम shift;
    प्रति(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    प्रत्यागम 0;
}

स्थिर शून्य bn_zero(अचिन्हित पूर्णाङ्क *bn)
{
    पूर्णाङ्क i;
    प्रति(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
स्थिर शून्य parse_संख्या(ध्रुव वर्ण *p)
{
    पूर्णाङ्क b, t, shift, frac_bits, s, exp_val, ch;
    वर्ण *q;
    अचिन्हित पूर्णाङ्क bn[BN_SIZE];
    दीर्घ द्विगुण d;

    /*संख्या*/
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
        यदि (q >= token_buf + STRING_MAX_SIZE) {
        अंक_too_long:
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
            frac_bits = 0;
            *q = '\0';
            यदि (b == 16)
                shift = 4;
            अन्यथा 
                shift = 1;
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
                frac_bits -= bn_lshift(bn, shift, t);
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
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
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
            d = ldexpl(d, exp_val - frac_bits);
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
                यदि (q >= token_buf + STRING_MAX_SIZE)
                    गच्छ अंक_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                यावत् (ch >= '0' && ch <= '9') {
                    यदि (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            यदि (ch == 'e' || ch == 'E') {
                यदि (q >= token_buf + STRING_MAX_SIZE)
                    गच्छ अंक_too_long;
                *q++ = ch;
                ch = *p++;
                यदि (ch == '-' || ch == '+') {
                    यदि (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                यदि (ch < '0' || ch > '9')
                    expect("exponent digits");
                यावत् (ch >= '0' && ch <= '9') {
                    यदि (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अंक_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            त्रुटि_सं = 0;
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
                tokc.d = म_से_भग्न(token_buf, रिक्त);
            }
        }
    } अन्यथा {
        अचिन्हित दीर्घ दीर्घ n, n1;
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
        यदि (pp_व्यंजक)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        यदि (ucount == 0 && b == 10) {
            यदि (lcount <= (LONG_SIZE == 4)) {
                यदि (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            यदि (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } अन्यथा {
            यदि (lcount <= (LONG_SIZE == 4)) {
                यदि (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
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


#define PARSE2(c1, tok1, c2, tok2)              \
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
स्थिर शून्य next_nomacro(शून्य)
{
    पूर्णाङ्क t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    अचिन्हित पूर्णाङ्क h;

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
        यावत् (isidnum_table[*p - CH_EOF] & IS_SPC)
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
            } अन्यथा यदि (s1->ifdef_ढेर_ptr != file->ifdef_ढेर_ptr) {
                tcc_error("missing #endif");
            } अन्यथा यदि (s1->include_ढेर_ptr == s1->include_ढेर) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } अन्यथा {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                यदि (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    म_लिखो("#endif %s\n", get_tok_str(file->ifndef_macro_saved, रिक्त));
#endif
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
                गच्छ maybe_newline;
            }
        } अन्यथा {
            गच्छ redo_no_start;
        }
        भङ्ग;

    पक्ष '\n':
        file->पंक्ति_अंक++;
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
                    p = parse_पंक्ति_comment(p - 1);
                    गच्छ redo_no_start;
                } अन्यथा
#endif
                {
                    tok = '#';
                }
            }
        }
        भङ्ग;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    पक्ष '$':
        यदि (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        यावत् (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        यदि (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            प्रति(;;) {
                ts = *pts;
                यदि (!ts)
                    भङ्ग;
                यदि (ts->len == len && !स_भेद(ts->str, p1, len))
                    गच्छ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (वर्ण *) p1, len);
        token_found: ;
        } अन्यथा {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (वर्ण *) p1, len);
            p--;
            PEEKC(c, p);
            यावत् (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
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
    parse_अंक:
        cstr_reset(&tokcstr);
        प्रति(;;) {
            cstr_ccat(&tokcstr, t);
            यदि (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((वर्ण*)tokcstr.data)[0] == '0'
                                && toup(((वर्ण*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                भङ्ग;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        भङ्ग;

    पक्ष '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        यदि (isnum(c)) {
            t = '.';
            गच्छ parse_अंक;
        } अन्यथा यदि ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_अंक))) {
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
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
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
            tok = TOK_A_ADD;
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
            p = parse_पंक्ति_comment(p);
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
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        यदि (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_पंक्ति_comment(p);
            गच्छ redo_no_start;
        }
#endif
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
        यदि (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
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
    म_लिखो("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
स्थिर पूर्णाङ्क indent;
स्थिर शून्य define_print(TCCState *s1, पूर्णाङ्क v);
स्थिर शून्य pp_print(ध्रुव वर्ण *संदेश, पूर्णाङ्क v, ध्रुव पूर्णाङ्क *str)
{
    खाता *fp = tcc_state->ppfp;

    यदि (संदेश[0] == '#' && indent == 0)
        ख_लिखो(fp, "\n");
    अन्यथा यदि (संदेश[0] == '+')
         ++indent, ++संदेश;
    अन्यथा यदि (संदेश[0] == '-')
        --indent, ++संदेश;

    ख_लिखो(fp, "%*s", indent, "");
    यदि (संदेश[0] == '#') {
        define_print(tcc_state, v);
    } अन्यथा {
        tok_print(str, v ? "%s %s" : "%s", संदेश, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#अन्यथा
#define PP_PRINT(x)
#endif

स्थिर पूर्णाङ्क macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ध्रुव पूर्णाङ्क *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
स्थिर पूर्णाङ्क *macro_arg_subst(Sym **nested_list, ध्रुव पूर्णाङ्क *macro_str, Sym *args)
{
    पूर्णाङ्क t, t0, t1, t2, n;
    ध्रुव पूर्णाङ्क *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    प्रति (s = args, n = 0; s; s = s->prev, ++n);
    यावत् (n--) {
        प्रति (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    यावत्(1) {
        TOK_GET(&t, &macro_str, &cval);
        यदि (!t)
            भङ्ग;
        यदि (t == '#') {
            /* stringize */
            कुरु t = *macro_str++; यावत् (t == ' ');
            s = sym_find2(args, t);
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
            } अन्यथा यदि ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } अन्यथा {
                expect("macro parameter after '#'");
            }
        } अन्यथा यदि (t >= TOK_IDENT) {
            s = sym_find2(args, t);
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
                            गच्छ add_var;
                        }
                    } अन्यथा {
                        यदि (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } अन्यथा {
            add_var:
		    यदि (!s->e) {
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
                यावत् (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } अन्यथा {
                tok_str_add(&str, t);
            }
        } अन्यथा {
            tok_str_add2(&str, t, &cval);
        }
        यदि (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
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
        यदि (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            स_नकल(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            प्रति (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                यदि (*file->buf_ptr == 0)
                    भङ्ग;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        यदि (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
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
                p = parse_पंक्ति_comment(p);
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
            file->पंक्ति_अंक++, tok_flags |= TOK_FLAG_BOL;
            भङ्ग;
        स्वभाव: leave:
            file->buf_ptr = p;
            प्रत्यागम c;
        }
        यदि (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
स्थिर पूर्णाङ्क next_argstream(Sym **nested_list, TokenString *ws_str)
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
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        यदि (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    यदि (ws_str) {
        प्रत्यागम peek_file(ws_str);
    } अन्यथा {
        next_nomacro();
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
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            यदि (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                यदि (parse_flags & PARSE_FLAG_SPACES)
                    प्रति (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                प्रत्यागम 0;
            } अन्यथा {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = रिक्त;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            प्रति(;;) {
                कुरु {
                    t = next_argstream(nested_list, रिक्त);
                } यावत् (t == ' ' || --i);

                यदि (!sa) {
                    यदि (t == ')') /* handle '()' case */
                        भङ्ग;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
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
                    t = next_argstream(nested_list, रिक्त);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                यदि (t == ')') {
                    यदि (!sa)
                        भङ्ग;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    यदि (sa->type.t && gnu_ext)
                        गच्छ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            यावत् (sa) {
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
        यदि (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        यदि (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        यदि (jstr != mstr)
            tok_str_free_str(jstr);
        यदि (mstr != s->d)
            tok_str_free_str(mstr);
        प्रत्यागम ret;

    } अन्यथा {
        CValue cval;
        वर्ण buf[32], *cstrval = buf;

        /* special macros */
        यदि (v == TOK_पंक्ति_2 || v == TOK___COUNTER__) {
            t = v == TOK_पंक्ति_2 ? file->पंक्ति_अंक : pp_counter++;
            snprintf(buf, परिमाण(buf), "%d", t);
            t = TOK_PPNUM;
            गच्छ add_cstr1;

        } अन्यथा यदि (v == TOK___FILE__) {
            cstrval = file->filename;
            गच्छ add_cstr;

        } अन्यथा यदि (v == TOK___DATE__ || v == TOK___TIME__) {
            समय_प्रकार ti;
            संरचना पंचांग *पंचांग;
            समय(&ti);
            पंचांग = स_स्थानीय(&ti);
            यदि (v == TOK___DATE__) {
                स्थिर वर्ण ध्रुव ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, परिमाण(buf), "%s %2d %d",
                    ab_month_name[पंचांग->tm_mon], पंचांग->tm_mday, पंचांग->tm_year + 1900);
            } अन्यथा {
                snprintf(buf, परिमाण(buf), "%02d:%02d:%02d",
                    पंचांग->tm_hour, पंचांग->tm_min, पंचांग->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = म_माप(cstrval) + 1;
            cval.str.data = cstrval;
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

#ifdef PP_DEBUG
    पूर्णाङ्क tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

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
                t |= SYM_FIELD;
                गच्छ no_subst;
            }
            str = tok_str_alloc();
            str->str = (पूर्णाङ्क*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            यदि (macro_ढेर != str) {
                /* already finished by reading function macro arguments */
                भङ्ग;
            }
            macro_str = macro_ptr;
            end_macro ();
        } अन्यथा यदि (t == ' ') {
            यदि (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } अन्यथा {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            यदि (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            यदि (t == TOK_DEFINED && pp_व्यंजक)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    प्रत्यागम nosubst;
}

/* return next token with macro substitution */
ST_FUNC शून्य next(शून्य)
{
    पूर्णाङ्क t;
    यावत् (macro_ptr) {
redo:
        t = *macro_ptr;
        यदि (TOK_HAS_मूल्य(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            यदि (t == TOK_LINENUM) {
                file->पंक्ति_अंक = tokc.i;
                गच्छ redo;
            }
            गच्छ convert;
        } अन्यथा यदि (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            अनुवर्त;
        } अन्यथा यदि (t == TOK_EOF) {
            /* do nothing */
        } अन्यथा {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            यदि (t == '\\') {
                यदि (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        प्रत्यागम;
    }

    next_nomacro();
    t = tok;
    यदि (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        यदि (s) {
            Sym *nested_list = रिक्त;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            गच्छ redo;
        }
        प्रत्यागम;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    यदि (t == TOK_PPNUM) {
        यदि  (parse_flags & PARSE_FLAG_TOK_अंक)
            parse_संख्या(tokc.str.data);
    } अन्यथा यदि (t == TOK_PPSTR) {
        यदि (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN शून्य unget_tok(पूर्णाङ्क last_tok)
{
    TokenString *str = &unget_buf;
    पूर्णाङ्क alloc = 0;
    यदि (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    यदि (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

स्थिर ध्रुव वर्ण * ध्रुव target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# यदि PTR_SIZE == 8
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
#endif
    ;

स्थिर शून्य putdef(CString *cs, ध्रुव वर्ण *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!म_अक्षर(p, ' ')*2]);
}

स्थिर शून्य putdefs(CString *cs, ध्रुव वर्ण *p)
{
    यावत् (*p)
        putdef(cs, p), p = म_अक्षर(p, 0) + 1;
}

स्थिर शून्य tcc_predefs(TCCState *s1, CString *cs, पूर्णाङ्क is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    यदि (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    यदि (is_asm)
      putdef(cs, "__ASSEMBLER__");
    यदि (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    यदि (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    यदि (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    यदि (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    यदि (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    यदि (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    यदि (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    यदि (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
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
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC शून्य preprocess_start(TCCState *s1, पूर्णाङ्क filetype)
{
    पूर्णाङ्क is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ढेर_ptr = s1->include_ढेर;
    s1->ifdef_ढेर_ptr = s1->ifdef_ढेर;
    file->ifdef_ढेर_ptr = s1->ifdef_ढेर_ptr;
    pp_व्यंजक = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ढेर[0] = 0;
    s1->pack_ढेर_ptr = s1->pack_ढेर;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    यदि (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        यदि (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        यदि (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ढेर_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        स_नकल(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC शून्य preprocess_end(TCCState *s1)
{
    यावत् (macro_ढेर)
        end_macro();
    macro_ptr = रिक्त;
    यावत् (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC पूर्णाङ्क set_idnum(पूर्णाङ्क c, पूर्णाङ्क val)
{
    पूर्णाङ्क prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    प्रत्यागम prev;
}

ST_FUNC शून्य tccpp_new(TCCState *s)
{
    पूर्णाङ्क i, c;
    ध्रुव वर्ण *p, *r;

    /* init isid table */
    प्रति(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_अंक
            : 0);

    प्रति(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    स_रखो(hash_ident, 0, TOK_HASH_SIZE * परिमाण(TokenSym *));
    स_रखो(s->cached_includes_hash, 0, परिमाण s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

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
    define_धकेलो(TOK_पंक्ति_2, MACRO_OBJ, रिक्त, रिक्त);
    define_धकेलो(TOK___FILE__, MACRO_OBJ, रिक्त, रिक्त);
    define_धकेलो(TOK___DATE__, MACRO_OBJ, रिक्त, रिक्त);
    define_धकेलो(TOK___TIME__, MACRO_OBJ, रिक्त, रिक्त);
    define_धकेलो(TOK___COUNTER__, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य tccpp_delete(TCCState *s)
{
    पूर्णाङ्क i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    यदि (n > total_idents)
        total_idents = n;
    प्रति (i = n; --i >= 0;)
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

स्थिर पूर्णाङ्क pp_need_space(पूर्णाङ्क a, पूर्णाङ्क b);

स्थिर शून्य tok_print(ध्रुव पूर्णाङ्क *str, ध्रुव वर्ण *संदेश, ...)
{
    खाता *fp = tcc_state->ppfp;
    बहु_सूची ap;
    पूर्णाङ्क t, t0, s;
    CValue cval;

    बहु_शुरू(ap, संदेश);
    भख_लिखो(fp, संदेश, ap);
    बहु_पूर्ण(ap);

    s = t0 = 0;
    यावत् (str) {
	TOK_GET(&t, &str, &cval);
	यदि (t == 0 || t == TOK_EOF)
	    भङ्ग;
        यदि (pp_need_space(t0, t))
            s = 0;
	ख_लिखो(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    ख_लिखो(fp, "\n");
}

स्थिर शून्य pp_पंक्ति(TCCState *s1, BufferedFile *f, पूर्णाङ्क level)
{
    पूर्णाङ्क d = f->पंक्ति_अंक - f->पंक्ति_ref;

    यदि (s1->dflag & 4)
	प्रत्यागम;

    यदि (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } अन्यथा यदि (level == 0 && f->पंक्ति_ref && d < 8) {
	यावत् (d > 0)
	    ख_माला_दो("\n", s1->ppfp), --d;
    } अन्यथा यदि (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_STD) {
	ख_लिखो(s1->ppfp, "#line %d \"%s\"\n", f->पंक्ति_अंक, f->filename);
    } अन्यथा {
	ख_लिखो(s1->ppfp, "# %d \"%s\"%s\n", f->पंक्ति_अंक, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->पंक्ति_ref = f->पंक्ति_अंक;
}

स्थिर शून्य define_print(TCCState *s1, पूर्णाङ्क v)
{
    खाता *fp;
    Sym *s;

    s = define_find(v);
    यदि (रिक्त == s || रिक्त == s->d)
        प्रत्यागम;

    fp = s1->ppfp;
    ख_लिखो(fp, "#define %s", get_tok_str(v, रिक्त));
    यदि (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        ख_लिखो(fp,"(");
        यदि (a)
            प्रति (;;) {
                ख_लिखो(fp,"%s", get_tok_str(a->v, रिक्त));
                यदि (!(a = a->next))
                    भङ्ग;
                ख_लिखो(fp,",");
            }
        ख_लिखो(fp,")");
    }
    tok_print(s->d, "");
}

स्थिर शून्य pp_debug_defines(TCCState *s1)
{
    पूर्णाङ्क v, t;
    ध्रुव वर्ण *vs;
    खाता *fp;

    t = pp_debug_tok;
    यदि (t == 0)
        प्रत्यागम;

    file->पंक्ति_अंक--;
    pp_पंक्ति(s1, file, 0);
    file->पंक्ति_ref = ++file->पंक्ति_अंक;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, रिक्त);
    यदि (t == TOK_DEFINE) {
        define_print(s1, v);
    } अन्यथा यदि (t == TOK_UNDEF) {
        ख_लिखो(fp, "#undef %s\n", vs);
    } अन्यथा यदि (t == TOK_धकेलो_macro) {
        ख_लिखो(fp, "#pragma push_macro(\"%s\")\n", vs);
    } अन्यथा यदि (t == TOK_निकालो_macro) {
        ख_लिखो(fp, "#pragma pop_macro(\"%s\")\n", vs);
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
    यदि (t == TOK_PPNUM && toup(म_अक्षर(p, 0)[-1]) == 'E')
        प्रत्यागम 'E';
    प्रत्यागम t;
}

/* Preprocess the current file */
ST_FUNC पूर्णाङ्क tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    पूर्णाङ्क token_seen, spcs, level;
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
    यदि (s1->Pflag == पंक्ति_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_अंक, s1->Pflag = 1;

    यदि (s1->do_bench) {
	/* for PP benchmarks */
	कुरु next(); यावत् (tok != TOK_EOF);
	प्रत्यागम 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    यदि (file->prev)
        pp_पंक्ति(s1, file->prev, level++);
    pp_पंक्ति(s1, file, level);

    प्रति (;;) {
        iptr = s1->include_ढेर_ptr;
        next();
        यदि (tok == TOK_EOF)
            भङ्ग;

        level = s1->include_ढेर_ptr - iptr;
        यदि (level) {
            यदि (level > 0)
                pp_पंक्ति(s1, *iptr, 0);
            pp_पंक्ति(s1, file, level);
        }
        यदि (s1->dflag & 7) {
            pp_debug_defines(s1);
            यदि (s1->dflag & 4)
                अनुवर्त;
        }

        यदि (is_space(tok)) {
            यदि (spcs < परिमाण white - 1)
                white[spcs++] = tok;
            अनुवर्त;
        } अन्यथा यदि (tok == TOK_LINEFEED) {
            spcs = 0;
            यदि (token_seen == TOK_LINEFEED)
                अनुवर्त;
            ++file->पंक्ति_ref;
        } अन्यथा यदि (token_seen == TOK_LINEFEED) {
            pp_पंक्ति(s1, file, 0);
        } अन्यथा यदि (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, ख_माला_दो(white, s1->ppfp), spcs = 0;
        ख_माला_दो(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    प्रत्यागम 0;
}

/* ------------------------------------------------------------------------- */
