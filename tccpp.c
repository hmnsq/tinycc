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
ST_DATA पूर्णाङ्क pp_व्यञ्जकम्;

/* ------------------------------------------------------------------------- */

स्थिर TokenSym *hash_ident[TOK_HASH_SIZE];
स्थिर वर्ण token_buf[STRING_MAX_SIZE + 1];
स्थिर CString cstr_buf;
स्थिर TokenString tokstr_buf;
स्थिर TokenString unget_buf;
स्थिर unsigned वर्ण isidnum_table[256 - CH_EOF];
स्थिर पूर्णाङ्क pp_debug_tok, pp_debug_symv;
स्थिर पूर्णाङ्क pp_counter;
स्थिर शून्य tok_print(ध्रुव पूर्णाङ्क *str, ध्रुव वर्ण *सन्देशः, ...);
स्थिर शून्य next_nomacro(शून्य);
स्थिर शून्य parse_सङ्ख्या(ध्रुव वर्ण *p);
स्थिर शून्य parse_string(ध्रुव वर्ण *p, पूर्णाङ्क len);

स्थिर संरचना TinyAlloc *toksym_alloc;
स्थिर संरचना TinyAlloc *tokstr_alloc;

स्थिर TokenString *macro_राशिः;

स्थिर ध्रुव वर्ण tcc_keywords[] = 
#define DEF(id, str) str "\0"
#अन्तर्भाव "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
स्थिर ध्रुव unsigned वर्ण tok_two_chars[] =
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
    सचे (tok != c) {
        वर्ण tmp[40];
        pstrcpy(tmp, परिमाण tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC शून्य expect(ध्रुव वर्ण *सन्देशः)
{
    tcc_error("%s expected", सन्देशः);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#अञ्ञथा
#सचे !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#अञ्ञथा
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
    unsigned nb_allocs;
    unsigned size;
#सचे TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    सङ्घ {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

प्रकारनिर्देश संरचना tal_header_t {
    size_t  size; /* word align */
#सचे TAL_DEBUG
    पूर्णाङ्क     पङ्क्तिः_अङ्कः; /* negative line_num used for double free check */
    वर्ण    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (परिमाण (size_t) - 1)) & ~(परिमाण (size_t) - 1))

/* ------------------------------------------------------------------------- */

स्थिर TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(परिमाण(TinyAlloc) - परिमाण (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#सचे TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    पटिनिवत्त al;
}

स्थिर शून्य tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#सचे TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#सचे TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#सचे TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    सचे (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        याव (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            सचे (header->पङ्क्तिः_अङ्कः > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->पङ्क्तिः_अङ्कः, (पूर्णाङ्क)header->size);
            }
            p += header->size + परिमाण(tal_header_t);
        }
#सचे TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    सचे (al)
        गच्छ tail_call;
    *pal = al;
}

स्थिर शून्य tal_free_impl(TinyAlloc **pal, शून्य *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **शिखरम् = pal;
    tal_header_t *header;

    सचे (!p)
        पटिनिवत्त;
    header = (tal_header_t *)p - 1;
#सचे TAL_DEBUG
    सचे (header->पङ्क्तिः_अङ्कः < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (पूर्णाङ्क)-header->पङ्क्तिः_अङ्कः, (पूर्णाङ्क)header->size);
    } अञ्ञथा
        header->पङ्क्तिः_अङ्कः = -header->पङ्क्तिः_अङ्कः;
#endif
    al = *pal;
    याव ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    सचे (0 == --al->nb_allocs) {
        *pal = al->next;
        सचे ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } अञ्ञथा {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *शिखरम्, *शिखरम् = al;
        }
    } अञ्ञथा सचे ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

स्थिर शून्य *tal_realloc_impl(TinyAlloc **pal, शून्य *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    शून्य *ret;
    unsigned adj_size = TAL_ALIGN(size) + परिमाण(tal_header_t);
    TinyAlloc *al = *pal;

    सचे (p) {
        /* reallpc case */
        याव ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        सचे ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        सचे (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            पटिनिवत्त ret;
        } अञ्ञथा सचे (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#सचे TAL_DEBUG
            header->पङ्क्तिः_अङ्कः = -header->पङ्क्तिः_अङ्कः;
#endif
        }
    } अञ्ञथा {
        /* new alloc case */
        याव (al->p + adj_size > al->bufend) {
            al = al->next;
            सचे (!al) {
                unsigned new_size = (*pal)->size;
                सचे (adj_size > new_size) {
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
#सचे  TAL_DEBUG
    {
        पूर्णाङ्क ofs = strlen(sfile) + 1 - परिमाण header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->पङ्क्तिः_अङ्कः = sline;
#सचे TAL_INFO
        सचे (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        सचे (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    पटिनिवत्त ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
स्थिर शून्य cstr_realloc(CString *cstr, पूर्णाङ्क new_size)
{
    पूर्णाङ्क size;

    size = cstr->size_allocated;
    सचे (size < 8)
        size = 8; /* no need to allocate a too small first string */
    याव (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN शून्य cstr_ccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क size;
    size = cstr->size + 1;
    सचे (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN वर्ण *unicode_to_utf8 (वर्ण *b, uint32_t Uc)
{
    सचे (Uc<0x80) *b++=Uc;
    अञ्ञथा सचे (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    अञ्ञथा सचे (Uc-0xd800u<0x800) गच्छ error;
    अञ्ञथा सचे (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अञ्ञथा सचे (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    अञ्ञथा error: tcc_error("0x%x is not a valid universal character", Uc);
    पटिनिवत्त b;
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
    सचे (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    सचे (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC शून्य cstr_wccat(CString *cstr, पूर्णाङ्क ch)
{
    पूर्णाङ्क size;
    size = cstr->size + परिमाण(nwchar_t);
    सचे (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - परिमाण(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC शून्य cstr_new(CString *cstr)
{
    memset(cstr, 0, परिमाण(CString));
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

ST_FUNC पूर्णाङ्क cstr_vprintf(CString *cstr, ध्रुव वर्ण *fmt, va_list ap)
{
    va_list v;
    पूर्णाङ्क len, size = 80;
    अत्थाय (;;) {
        size += cstr->size;
        सचे (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        सचे (len >= 0 && len < size)
            भङ्ग;
        size *= 2;
    }
    cstr->size += len;
    पटिनिवत्त len;
}

ST_FUNC पूर्णाङ्क cstr_printf(CString *cstr, ध्रुव वर्ण *fmt, ...)
{
    va_list ap; पूर्णाङ्क len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    पटिनिवत्त len;
}

/* XXX: unicode ? */
स्थिर शून्य add_char(CString *cstr, पूर्णाङ्क c)
{
    सचे (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    सचे (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } अञ्ञथा {
        cstr_ccat(cstr, '\\');
        सचे (c == '\n') {
            cstr_ccat(cstr, 'n');
        } अञ्ञथा {
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

    सचे (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    सचे ((i % TOK_ALLOC_INCR) == 0) {
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
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    पटिनिवत्त ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ध्रुव वर्ण *str, पूर्णाङ्क len)
{
    TokenSym *ts, **pts;
    पूर्णाङ्क i;
    unsigned पूर्णाङ्क h;
    
    h = TOK_HASH_INIT;
    अत्थाय(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned वर्ण *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    अत्थाय(;;) {
        ts = *pts;
        सचे (!ts)
            भङ्ग;
        सचे (ts->len == len && !memcmp(ts->str, str, len))
            पटिनिवत्त ts;
        pts = &(ts->hash_next);
    }
    पटिनिवत्त tok_alloc_new(pts, str, len);
}

ST_FUNC पूर्णाङ्क tok_alloc_const(ध्रुव वर्ण *str)
{
    पटिनिवत्त tok_alloc(str, strlen(str))->tok;
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
        sprintf(p, "%llu", (unsigned long long)cv->i);
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
        पटिनिवत्त (वर्ण*)cv->str.data;
    पक्ष TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    पक्ष TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        सचे (v == TOK_STR) {
            len = cv->str.size - 1;
            अत्थाय(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned वर्ण *)cv->str.data)[i]);
        } अञ्ञथा {
            len = (cv->str.size / परिमाण(nwchar_t)) - 1;
            अत्थाय(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        भङ्ग;

    पक्ष TOK_CFLOAT:
        पटिनिवत्त strcpy(p, "<float>");
    पक्ष TOK_CDOUBLE:
        पटिनिवत्त strcpy(p, "<double>");
    पक्ष TOK_CLDOUBLE:
        पटिनिवत्त strcpy(p, "<long double>");
    पक्ष TOK_LINENUM:
        पटिनिवत्त strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    पक्ष TOK_LT:
        v = '<';
        गच्छ addv;
    पक्ष TOK_GT:
        v = '>';
        गच्छ addv;
    पक्ष TOK_DOTS:
        पटिनिवत्त strcpy(p, "...");
    पक्ष TOK_A_SHL:
        पटिनिवत्त strcpy(p, "<<=");
    पक्ष TOK_A_SAR:
        पटिनिवत्त strcpy(p, ">>=");
    पक्ष TOK_EOF:
        पटिनिवत्त strcpy(p, "<eof>");
    पक्ष 0: /* anonymous nameless symbols */
        पटिनिवत्त strcpy(p, "<no name>");
    स्वभाव:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        सचे (v < TOK_IDENT) {
            /* search in two bytes table */
            ध्रुव unsigned वर्ण *q = tok_two_chars;
            याव (*q) {
                सचे (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    पटिनिवत्त cstr_buf.data;
                }
                q += 3;
            }
            सचे (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                भङ्ग;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } अञ्ञथा सचे (v < tok_ident) {
            पटिनिवत्त table_ident[v - TOK_IDENT]->str;
        } अञ्ञथा सचे (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } अञ्ञथा {
            /* should never happen */
            पटिनिवत्त रिक्त;
        }
        भङ्ग;
    }
    पटिनिवत्त cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
स्थिर पूर्णाङ्क handle_eob(शून्य)
{
    BufferedFile *bf = file;
    पूर्णाङ्क len;

    /* only tries to read if really end of buffer */
    सचे (bf->buf_ptr >= bf->buf_end) {
        सचे (bf->fd >= 0) {
#सचे defined(PARSE_DEBUG)
            len = 1;
#अञ्ञथा
            len = IO_BUF_SIZE;
#endif
            len = पठ(bf->fd, bf->buffer, len);
            सचे (len < 0)
                len = 0;
        } अञ्ञथा {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    सचे (bf->buf_ptr < bf->buf_end) {
        पटिनिवत्त bf->buf_ptr[0];
    } अञ्ञथा {
        bf->buf_ptr = bf->buf_end;
        पटिनिवत्त CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
स्थिर पूर्णाङ्क next_c(शून्य)
{
    पूर्णाङ्क ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    सचे (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    पटिनिवत्त ch;
}

/* input with '\[\r]\n' handling. */
स्थिर पूर्णाङ्क handle_stray_noerror(पूर्णाङ्क err)
{
    पूर्णाङ्क ch;
    याव ((ch = next_c()) == '\\') {
        ch = next_c();
        सचे (ch == '\n') {
    newl:
            file->पङ्क्तिः_अङ्कः++;
        } अञ्ञथा {
            सचे (ch == '\r') {
                ch = next_c();
                सचे (ch == '\n')
                    गच्छ newl;
                *--file->buf_ptr = '\r';
            }
            सचे (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            पटिनिवत्त *--file->buf_ptr = '\\';
        }
    }
    पटिनिवत्त ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
स्थिर पूर्णाङ्क handle_bs(uint8_t **p)
{
    पूर्णाङ्क c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    पटिनिवत्त c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
स्थिर पूर्णाङ्क handle_stray(uint8_t **p)
{
    पूर्णाङ्क c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    पटिनिवत्त c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    सचे (c == '\\')\
        c = handle_stray(&p); \
}

स्थिर पूर्णाङ्क skip_spaces(शून्य)
{
    पूर्णाङ्क ch;
    --file->buf_ptr;
    करोहि {
        ch = ninp();
    } याव (isidnum_table[ch - CH_EOF] & IS_SPC);
    पटिनिवत्त ch;
}

/* single line C++ comments */
स्थिर uint8_t *parse_पङ्क्तिः_comment(uint8_t *p)
{
    पूर्णाङ्क c;
    अत्थाय(;;) {
        अत्थाय (;;) {
            c = *++p;
    redo:
            सचे (c == '\n' || c == '\\')
                भङ्ग;
            c = *++p;
            सचे (c == '\n' || c == '\\')
                भङ्ग;
        }
        सचे (c == '\n')
            भङ्ग;
        c = handle_bs(&p);
        सचे (c == CH_EOF)
            भङ्ग;
        सचे (c != '\\')
            गच्छ redo;
    }
    पटिनिवत्त p;
}

/* C comments */
स्थिर uint8_t *parse_comment(uint8_t *p)
{
    पूर्णाङ्क c;
    अत्थाय(;;) {
        /* fast skip loop */
        अत्थाय(;;) {
            c = *++p;
        redo:
            सचे (c == '\n' || c == '*' || c == '\\')
                भङ्ग;
            c = *++p;
            सचे (c == '\n' || c == '*' || c == '\\')
                भङ्ग;
        }
        /* now we can handle all the cases */
        सचे (c == '\n') {
            file->पङ्क्तिः_अङ्कः++;
        } अञ्ञथा सचे (c == '*') {
            करोहि {
                c = *++p;
            } याव (c == '*');
            सचे (c == '\\')
                c = handle_bs(&p);
            सचे (c == '/')
                भङ्ग;
            गच्छ check_eof;
        } अञ्ञथा {
            c = handle_bs(&p);
        check_eof:
            सचे (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            सचे (c != '\\')
                गच्छ redo;
        }
    }
    पटिनिवत्त p + 1;
}

/* parse a string without interpreting escapes */
स्थिर uint8_t *parse_pp_string(uint8_t *p, पूर्णाङ्क sep, CString *str)
{
    पूर्णाङ्क c;
    अत्थाय(;;) {
        c = *++p;
    redo:
        सचे (c == sep) {
            भङ्ग;
        } अञ्ञथा सचे (c == '\\') {
            c = handle_bs(&p);
            सचे (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } अञ्ञथा सचे (c == '\\') {
                सचे (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                सचे (c == '\\') {
                    c = handle_bs(&p);
                    सचे (c == CH_EOF)
                        गच्छ unterminated_string;
                }
                गच्छ add_char;
            } अञ्ञथा {
                गच्छ redo;
            }
        } अञ्ञथा सचे (c == '\n') {
        add_lf:
            सचे (ACCEPT_LF_IN_STRINGS) {
                file->पङ्क्तिः_अङ्कः++;
                गच्छ add_char;
            } अञ्ञथा सचे (str) { /* not skipping */
                गच्छ unterminated_string;
            } अञ्ञथा {
                //tcc_warning("missing terminating %c character", sep);
                पटिनिवत्त p;
            }
        } अञ्ञथा सचे (c == '\r') {
            c = *++p;
            सचे (c == '\\')
                c = handle_bs(&p);
            सचे (c == '\n')
                गच्छ add_lf;
            सचे (c == CH_EOF)
                गच्छ unterminated_string;
            सचे (str)
                cstr_ccat(str, '\r');
            गच्छ redo;
        } अञ्ञथा {
        add_char:
            सचे (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    पटिनिवत्त p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
स्थिर शून्य preprocess_skip(शून्य)
{
    पूर्णाङ्क a, start_of_पङ्क्तिः, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_पङ्क्तिः = 1;
    in_warn_or_error = 0;
    अत्थाय(;;) {
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
            सचे (c == CH_EOF)
                expect("#endif");
            सचे (c == '\\')
                ++p;
            अनुवर्त;
        /* skip strings */
        पक्ष '\"':
        पक्ष '\'':
            सचे (in_warn_or_error)
                गच्छ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, रिक्त);
            भङ्ग;
        /* skip comments */
        पक्ष '/':
            सचे (in_warn_or_error)
                गच्छ _default;
            ++p;
            c = handle_bs(&p);
            सचे (c == '*') {
                p = parse_comment(p);
            } अञ्ञथा सचे (c == '/') {
                p = parse_पङ्क्तिः_comment(p);
            }
            अनुवर्त;
        पक्ष '#':
            p++;
            सचे (start_of_पङ्क्तिः) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                सचे (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    गच्छ the_end;
                सचे (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                अञ्ञथा सचे (tok == TOK_ENDIF)
                    a--;
                अञ्ञथा सचे( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                अञ्ञथा सचे (tok == TOK_LINEFEED)
                    गच्छ redo_start;
                अञ्ञथा सचे (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_पङ्क्तिः_comment(p - 1);
            }
#सचे !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            अञ्ञथा सचे (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_पङ्क्तिः_comment(p - 1);
#अञ्ञथा
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            भङ्ग;
_default:
        स्वभाव:
            p++;
            भङ्ग;
        }
        start_of_पङ्क्तिः = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#सचे 0
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
        पटिनिवत्त 1 + 1;
    पक्ष TOK_STR:
    पक्ष TOK_LSTR:
    पक्ष TOK_PPNUM:
    पक्ष TOK_PPSTR:
        पटिनिवत्त 1 + 1 + (p[1] + 3) / 4;
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
	पटिनिवत्त 1 + LONG_SIZE / 4;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
        पटिनिवत्त 1 + 2;
    पक्ष TOK_CLDOUBLE:
        पटिनिवत्त 1 + LDOUBLE_शब्दाः;
    स्वभाव:
        पटिनिवत्त 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN शून्य tok_str_new(TokenString *s)
{
    s->str = रिक्त;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_पङ्क्तिः_अङ्कः = -1;
}

ST_FUNC TokenString *tok_str_alloc(शून्य)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, परिमाण *str);
    tok_str_new(str);
    पटिनिवत्त str;
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
    सचे (size < 16)
        size = 16;
    याव (size < new_size)
        size = size * 2;
    सचे (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * परिमाण(पूर्णाङ्क));
        s->allocated_len = size;
        s->str = str;
    }
    पटिनिवत्त s->str;
}

ST_FUNC शून्य tok_str_add(TokenString *s, पूर्णाङ्क t)
{
    पूर्णाङ्क len, *str;

    len = s->len;
    str = s->str;
    सचे (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC शून्य begin_macro(TokenString *str, पूर्णाङ्क alloc)
{
    str->alloc = alloc;
    str->prev = macro_राशिः;
    str->prev_ptr = macro_ptr;
    str->save_पङ्क्तिः_अङ्कः = file->पङ्क्तिः_अङ्कः;
    macro_ptr = str->str;
    macro_राशिः = str;
}

ST_FUNC शून्य end_macro(शून्य)
{
    TokenString *str = macro_राशिः;
    macro_राशिः = str->prev;
    macro_ptr = str->prev_ptr;
    file->पङ्क्तिः_अङ्कः = str->save_पङ्क्तिः_अङ्कः;
    सचे (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } अञ्ञथा {
        सचे (str->alloc == 2)
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
    सचे (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    विकल्प(t) {
    पक्ष TOK_CINT:
    पक्ष TOK_CUINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_CFLOAT:
    पक्ष TOK_LINENUM:
#सचे LONG_SIZE == 4
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
            size_t nb_शब्दाः =
                1 + (cv->str.size + परिमाण(पूर्णाङ्क) - 1) / परिमाण(पूर्णाङ्क);
            सचे (len + nb_शब्दाः >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_शब्दाः + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_शब्दाः;
        }
        भङ्ग;
    पक्ष TOK_CDOUBLE:
    पक्ष TOK_CLLONG:
    पक्ष TOK_CULLONG:
#सचे LONG_SIZE == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        भङ्ग;
    पक्ष TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        सचे (LDOUBLE_शब्दाः >= 3)
        str[len++] = cv->tab[2];
        सचे (LDOUBLE_शब्दाः >= 4)
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
    सचे (file->पङ्क्तिः_अङ्कः != s->last_पङ्क्तिः_अङ्कः) {
        s->last_पङ्क्तिः_अङ्कः = file->पङ्क्तिः_अङ्कः;
        cval.i = s->last_पङ्क्तिः_अङ्कः;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
स्थिर शून्य tok_str_add2_spc(TokenString *s, पूर्णाङ्क t, CValue *cv)
{
    सचे (s->need_spc == 3)
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
#सचे LONG_SIZE == 4
    पक्ष TOK_CLONG:
#endif
    पक्ष TOK_CINT:
    पक्ष TOK_CCHAR:
    पक्ष TOK_LCHAR:
    पक्ष TOK_LINENUM:
        cv->i = *p++;
        भङ्ग;
#सचे LONG_SIZE == 4
    पक्ष TOK_CULONG:
#endif
    पक्ष TOK_CUINT:
        cv->i = (unsigned)*p++;
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
#सचे LONG_SIZE == 8
    पक्ष TOK_CLONG:
    पक्ष TOK_CULONG:
#endif
        n = 2;
        गच्छ copy;
    पक्ष TOK_CLDOUBLE:
        n = LDOUBLE_शब्दाः;
    copy:
        करोहि
            *tab++ = *p++;
        याव (--n);
        भङ्ग;
    स्वभाव:
        भङ्ग;
    }
    *pp = p;
}

#सचे 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#अञ्ञथा
# define TOK_GET(t,p,c) करोहि { \
    पूर्णाङ्क _t = **(p); \
    सचे (TOK_HAS_मानम्(_t)) \
        tok_get(t, p, c); \
    अञ्ञथा \
        *(t) = _t, ++*(p); \
    } याव (0)
#endif

स्थिर पूर्णाङ्क macro_is_equal(ध्रुव पूर्णाङ्क *a, ध्रुव पूर्णाङ्क *b)
{
    CValue cv;
    पूर्णाङ्क t;

    सचे (!a || !b)
        पटिनिवत्त 1;

    याव (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        सचे (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            पटिनिवत्त 0;
    }
    पटिनिवत्त !(*a || *b);
}

/* defines handling */
ST_INLN शून्य define_प्रक्षिप(पूर्णाङ्क v, पूर्णाङ्क macro_type, पूर्णाङ्क *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_राशिः, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    सचे (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, रिक्त));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC शून्य define_undef(Sym *s)
{
    पूर्णाङ्क v = s->v;
    सचे (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = रिक्त;
}

ST_INLN Sym *define_find(पूर्णाङ्क v)
{
    v -= TOK_IDENT;
    सचे ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        पटिनिवत्त रिक्त;
    पटिनिवत्त table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC शून्य free_defines(Sym *b)
{
    याव (define_राशिः != b) {
        Sym *शिखरम् = define_राशिः;
        define_राशिः = शिखरम्->prev;
        tok_str_free_str(शिखरम्->d);
        define_undef(शिखरम्);
        sym_free(शिखरम्);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
स्थिर शून्य maybe_run_test(TCCState *s)
{
    ध्रुव वर्ण *p;
    सचे (s->include_राशिः_ptr != s->include_राशिः)
        पटिनिवत्त;
    p = get_tok_str(tok, रिक्त);
    सचे (0 != memcmp(p, "test_", 5))
        पटिनिवत्त;
    सचे (0 != --s->run_test)
        पटिनिवत्त;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_प्रक्षिप(tok, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य skip_to_eol(पूर्णाङ्क warn)
{
    सचे (tok == TOK_LINEFEED)
        पटिनिवत्त;
    सचे (warn)
        tcc_warning("extra tokens after directive");
    याव (macro_राशिः)
        end_macro();
    file->buf_ptr = parse_पङ्क्तिः_comment(file->buf_ptr - 1);
    next_nomacro();
}

स्थिर CachedInclude *
अन्वेषणम्_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क add);

स्थिर पूर्णाङ्क parse_include(TCCState *s1, पूर्णाङ्क do_next, पूर्णाङ्क test)
{
    पूर्णाङ्क c, i;
    वर्ण name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    सचे (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, परिमाण name, tokcstr.data, i);
        next_nomacro();
    } अञ्ञथा {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        अत्थाय (;;) {
            next();
            p = name, i = strlen(p) - 1;
            सचे (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                भङ्ग;
            सचे (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, परिमाण name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    सचे (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    अत्थाय (;;) {
        ++i;
        सचे (i == 0) {
            /* check absolute include path */
            सचे (!IS_ABSPATH(name))
                अनुवर्त;
            buf[0] = '\0';
        } अञ्ञथा सचे (i == 1) {
            /* search in file's dir if "header.h" */
            सचे (c != '\"')
                अनुवर्त;
            p = file->true_filename;
            pstrncpy(buf, परिमाण buf, p, tcc_basename(p) - p);
        } अञ्ञथा {
            पूर्णाङ्क j = i - 2, k = j - s1->nb_include_paths;
            सचे (k < 0)
                p = s1->include_paths[j];
            अञ्ञथा सचे (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            अञ्ञथा सचे (test)
                पटिनिवत्त 0;
            अञ्ञथा
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, परिमाण buf, p);
            pstrcat(buf, परिमाण buf, "/");
        }
        pstrcat(buf, परिमाण buf, name);
        e = अन्वेषणम्_cached_include(s1, buf, 0);
        सचे (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            सचे ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (पूर्णाङ्क)(s1->include_राशिः_ptr - s1->include_राशिः), "", buf);
            पटिनिवत्त 1;
        }
        सचे (tcc_open(s1, buf) >= 0)
            भङ्ग;
    }

    सचे (test) {
        tcc_close();
    } अञ्ञथा {
        सचे (s1->include_राशिः_ptr >= s1->include_राशिः + INCLUDE_राशिः_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_राशिः_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        सचे (s1->gen_deps) {
            BufferedFile *bf = file;
            याव (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            सचे (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    पटिनिवत्त 1;
}

/* eval an expression for #if/#elif */
स्थिर पूर्णाङ्क व्यञ्जकम्_preprocess(TCCState *s1)
{
    पूर्णाङ्क c, t;
    पूर्णाङ्क t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_व्यञ्जकम् = 1;
    याव (1) {
        next(); /* do macro subst */
        t = tok;
        सचे (tok < TOK_IDENT) {
            सचे (tok == TOK_LINEFEED || tok == TOK_EOF)
                भङ्ग;
            सचे (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } अञ्ञथा सचे (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            सचे (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            सचे (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            सचे (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            सचे (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            सचे (t == '(') {
                next();
                सचे (tok != ')')
                    expect("')'");
            }
            गच्छ c_सङ्ख्या;
        } अञ्ञथा सचे (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    सचे (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            सचे (tok != ')')
                expect("')'");
            गच्छ c_सङ्ख्या;
        } अञ्ञथा {
            /* if undefined macro, replace with zero */
            c = 0;
        c_सङ्ख्या:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    सचे (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_व्यञ्जकम् = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = व्यञ्जकम्_const();
    सचे (tok != TOK_EOF)
        tcc_error("...");
    pp_व्यञ्जकम् = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    पटिनिवत्त c != 0;
}

ST_FUNC शून्य pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_व्यञ्जकम्, 0));
    macro_ptr = macro_राशिः->str;
    याव (next(), tok != TOK_EOF)
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
    सचे (v < TOK_IDENT || v == TOK_DEFINED)
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
    सचे (tok == '(') {
        पूर्णाङ्क dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        सचे (tok != ')') अत्थाय (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            सचे (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } अञ्ञथा सचे (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            सचे (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_राशिः, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            सचे (tok == ')')
                भङ्ग;
            सचे (tok != ',' || is_vaargs)
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
    याव (tok != TOK_LINEFEED && tok != TOK_EOF) {
        सचे (is_space(tok)) {
            str.need_spc |= 1;
        } अञ्ञथा {
            सचे (TOK_TWOSHARPS == tok) {
                सचे (0 == t0)
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
    सचे (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_प्रक्षिप(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

स्थिर CachedInclude *अन्वेषणम्_cached_include(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क add)
{
    ध्रुव वर्ण *s, *basename;
    unsigned पूर्णाङ्क h;
    CachedInclude *e;
    पूर्णाङ्क c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    याव ((c = (unsigned वर्ण)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#अञ्ञथा
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    अत्थाय(;;) {
        सचे (i == 0)
            भङ्ग;
        e = s1->cached_includes[i - 1];
        सचे (0 == PATHCMP(filename, e->filename))
            पटिनिवत्त e;
        सचे (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            पटिनिवत्त e;
        i = e->hash_next;
    }
    सचे (!add)
        पटिनिवत्त रिक्त;

    e = tcc_malloc(परिमाण(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    पटिनिवत्त e;
}

स्थिर पूर्णाङ्क pragma_parse(TCCState *s1)
{
    next_nomacro();
    सचे (tok == TOK_प्रक्षिप_macro || tok == TOK_निष्कासय_macro) {
        पूर्णाङ्क t = tok, v;
        Sym *s;

        सचे (next(), tok != '(')
            गच्छ pragma_err;
        सचे (next(), tok != TOK_STR)
            गच्छ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        सचे (next(), tok != ')')
            गच्छ pragma_err;
        सचे (t == TOK_प्रक्षिप_macro) {
            याव (रिक्त == (s = define_find(v)))
                define_प्रक्षिप(v, 0, रिक्त, रिक्त);
            s->type.ref = s; /* set push boundary */
        } अञ्ञथा {
            अत्थाय (s = define_राशिः; s; s = s->prev)
                सचे (s->v == v && s->type.ref == s) {
                    s->type.ref = रिक्त;
                    भङ्ग;
                }
        }
        सचे (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : रिक्त;
        अञ्ञथा
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } अञ्ञथा सचे (tok == TOK_once) {
        अन्वेषणम्_cached_include(s1, file->true_filename, 1)->once = 1;

    } अञ्ञथा सचे (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        पटिनिवत्त 1;

    } अञ्ञथा सचे (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        सचे (tok == TOK_ASM_निष्कासय) {
            next();
            सचे (s1->pack_राशिः_ptr <= s1->pack_राशिः) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_राशिः_ptr--;
        } अञ्ञथा {
            पूर्णाङ्क val = 0;
            सचे (tok != ')') {
                सचे (tok == TOK_ASM_प्रक्षिप) {
                    next();
                    सचे (s1->pack_राशिः_ptr >= s1->pack_राशिः + PACK_राशिः_SIZE - 1)
                        गच्छ stk_error;
                    val = *s1->pack_राशिः_ptr++;
                    सचे (tok != ',')
                        गच्छ pack_set;
                    next();
                }
                सचे (tok != TOK_CINT)
                    गच्छ pragma_err;
                val = tokc.i;
                सचे (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    गच्छ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_राशिः_ptr = val;
        }
        सचे (tok != ')')
            गच्छ pragma_err;

    } अञ्ञथा सचे (tok == TOK_comment) {
        वर्ण *p; पूर्णाङ्क t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        सचे (tok != TOK_STR)
            गच्छ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        सचे (tok != ')')
            गच्छ pragma_err;
        सचे (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } अञ्ञथा {
            सचे (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } अञ्ञथा {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        पटिनिवत्त 0;
    }
    next();
    पटिनिवत्त 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC शून्य tccpp_putfile(ध्रुव वर्ण *filename)
{
    वर्ण buf[1024];
    buf[0] = 0;
    सचे (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, परिमाण buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, परिमाण buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    सचे (0 == strcmp(file->filename, buf))
        पटिनिवत्त;
    //printf("new file '%s'\n", buf);
    सचे (file->true_filename == file->filename)
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
        सचे (s)
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
        c = व्यञ्जकम्_preprocess(s1);
        गच्छ do_if;
    पक्ष TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        सचे (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        सचे (is_bof) {
            सचे (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, रिक्त));
#endif
                file->ifndef_macro = tok;
            }
        }
        सचे (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        सचे (s1->ifdef_राशिः_ptr >= s1->ifdef_राशिः + IFDEF_राशिः_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_राशिः_ptr++ = c;
        गच्छ test_skip;
    पक्ष TOK_ELSE:
        next_nomacro();
        सचे (s1->ifdef_राशिः_ptr == s1->ifdef_राशिः)
            tcc_error("#else without matching #if");
        सचे (s1->ifdef_राशिः_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_राशिः_ptr[-1] ^= 3);
        गच्छ test_else;
    पक्ष TOK_ELIF:
        सचे (s1->ifdef_राशिः_ptr == s1->ifdef_राशिः)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_राशिः_ptr[-1];
        सचे (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        सचे (c == 1) {
            skip_to_eol(0);
            c = 0;
        } अञ्ञथा {
            c = व्यञ्जकम्_preprocess(s1);
            s1->ifdef_राशिः_ptr[-1] = c;
        }
    test_else:
        सचे (s1->ifdef_राशिः_ptr == file->ifdef_राशिः_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        सचे (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            गच्छ redo;
        }
        भङ्ग;
    पक्ष TOK_ENDIF:
        next_nomacro();
        सचे (s1->ifdef_राशिः_ptr <= file->ifdef_राशिः_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_राशिः_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        सचे (file->ifndef_macro &&
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
        next();
        सचे (tok != TOK_PPNUM) {
    पङ्क्तिः_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        गच्छ पङ्क्तिः_अङ्कः_2;
    पक्ष TOK_PPNUM:
        सचे (parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        c = 0; /* no error with extra tokens */
    पङ्क्तिः_अङ्कः_2:
        अत्थाय (n = 0, q = tokc.str.data; *q; ++q) {
            सचे (!isnum(*q))
                गच्छ पङ्क्तिः_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        सचे (tok != TOK_LINEFEED) {
            सचे (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                गच्छ पङ्क्तिः_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        सचे (file->fd > 0)
            total_पङ्क्तयः += file->पङ्क्तिः_अङ्कः - n;
        file->पङ्क्तिः_अङ्कः = n;
        भङ्ग;

    पक्ष TOK_ERROR:
    पक्ष TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        याव (c != '\n' && c != CH_EOF) {
            सचे ((q - buf) < परिमाण(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        सचे (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        अञ्ञथा
            tcc_warning("#warning %s", buf);
        next_nomacro();
        भङ्ग;
    }
    पक्ष TOK_PRAGMA:
        सचे (!pragma_parse(s1))
            गच्छ ignore;
        भङ्ग;
    पक्ष TOK_LINEFEED:
        गच्छ the_end;
    स्वभाव:
        /* ignore gas line comment in an 'S' file. */
        सचे (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ ignore;
        सचे (tok == '!' && is_bof)
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
    अत्थाय(;;) {
        c = *p;
        सचे (c == '\0')
            भङ्ग;
        सचे (c == '\\') {
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
                सचे (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    सचे (isoct(c)) {
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
                करोहि {
                    c = *p;
                    सचे (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    अञ्ञथा सचे (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    अञ्ञथा सचे (isnum(c))
                        c = c - '0';
                    अञ्ञथा सचे (i >= 0)
                        expect("more hex digits in universal-character-name");
                    अञ्ञथा
                        गच्छ add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } याव (--i);
		सचे (is_long) {
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
                सचे (!gnu_ext)
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
                सचे (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                अञ्ञथा
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                भङ्ग;
            }
        } अञ्ञथा सचे (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            पूर्णाङ्क cont; /* count of continuation bytes */
            पूर्णाङ्क skip; /* how many bytes should skip when error occurred */
            पूर्णाङ्क i;

            /* decode leading byte */
            सचे (c < 0xC2) {
	            skip = 1; गच्छ invalid_utf8_sequence;
            } अञ्ञथा सचे (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } अञ्ञथा सचे (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } अञ्ञथा सचे (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } अञ्ञथा {
	            skip = 1; गच्छ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            अत्थाय (i = 1; i <= cont; i++) {
                पूर्णाङ्क l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                सचे (i == 1) {
                    विकल्प (c) {
                    पक्ष 0xE0: l = 0xA0; भङ्ग;
                    पक्ष 0xED: h = 0x9F; भङ्ग;
                    पक्ष 0xF0: l = 0x90; भङ्ग;
                    पक्ष 0xF4: h = 0x8F; भङ्ग;
                    }
                }

                सचे (p[i] < l || p[i] > h) {
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
        सचे (!is_long)
            cstr_ccat(outstr, c);
        अञ्ञथा {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            सचे (c < 0x10000) {
                cstr_wccat(outstr, c);
            } अञ्ञथा {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#अञ्ञथा
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    सचे (!is_long)
        cstr_ccat(outstr, '\0');
    अञ्ञथा
        cstr_wccat(outstr, '\0');
}

स्थिर शून्य parse_string(ध्रुव वर्ण *s, पूर्णाङ्क len)
{
    uint8_t buf[1000], *p = buf;
    पूर्णाङ्क is_long, sep;

    सचे ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    सचे (len >= परिमाण buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    सचे (p != buf)
        tcc_free(p);

    सचे (sep == '\'') {
        पूर्णाङ्क char_size, i, n, c;
        /* XXX: make it portable */
        सचे (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        अञ्ञथा
            tok = TOK_LCHAR, char_size = परिमाण(nwchar_t);
        n = tokcstr.size / char_size - 1;
        सचे (n < 1)
            tcc_error("empty character constant");
        सचे (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        अत्थाय (c = i = 0; i < n; ++i) {
            सचे (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            अञ्ञथा
                c = (c << 8) | ((वर्ण *)tokcstr.data)[i];
        }
        tokc.i = c;
    } अञ्ञथा {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        सचे (!is_long)
            tok = TOK_STR;
        अञ्ञथा
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
स्थिर पूर्णाङ्क bn_lshift(unsigned पूर्णाङ्क *bn, पूर्णाङ्क shift, पूर्णाङ्क or_val)
{
    पूर्णाङ्क i;
    unsigned पूर्णाङ्क v;
    सचे (bn[BN_SIZE - 1] >> (32 - shift))
	पटिनिवत्त shift;
    अत्थाय(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    पटिनिवत्त 0;
}

स्थिर शून्य bn_zero(unsigned पूर्णाङ्क *bn)
{
    पूर्णाङ्क i;
    अत्थाय(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
स्थिर शून्य parse_सङ्ख्या(ध्रुव वर्ण *p)
{
    पूर्णाङ्क b, t, shift, frac_bits, s, exp_val, ch;
    वर्ण *q;
    unsigned पूर्णाङ्क bn[BN_SIZE];
    long द्विगुण d;

    /*सङ्ख्या*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    सचे (t == '.') {
        गच्छ float_frac_parse;
    } अञ्ञथा सचे (t == '0') {
        सचे (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } अञ्ञथा सचे (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    याव (1) {
        सचे (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        अञ्ञथा सचे (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        अञ्ञथा सचे (isnum(ch))
            t = ch - '0';
        अञ्ञथा
            भङ्ग;
        सचे (t >= b)
            भङ्ग;
        सचे (q >= token_buf + STRING_MAX_SIZE) {
        अङ्कः_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    सचे (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        सचे (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            सचे (b == 16)
                shift = 4;
            अञ्ञथा 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            याव (1) {
                t = *q++;
                सचे (t == '\0') {
                    भङ्ग;
                } अञ्ञथा सचे (t >= 'a') {
                    t = t - 'a' + 10;
                } अञ्ञथा सचे (t >= 'A') {
                    t = t - 'A' + 10;
                } अञ्ञथा {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            सचे (ch == '.') {
                ch = *p++;
                याव (1) {
                    t = ch;
                    सचे (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } अञ्ञथा सचे (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } अञ्ञथा सचे (t >= '0' && t <= '9') {
                        t = t - '0';
                    } अञ्ञथा {
                        भङ्ग;
                    }
                    सचे (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            सचे (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            सचे (ch == '+') {
                ch = *p++;
            } अञ्ञथा सचे (ch == '-') {
                s = -1;
                ch = *p++;
            }
            सचे (ch < '0' || ch > '9')
                expect("exponent digits");
            याव (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		सचे (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long द्विगुण)bn[3] * 79228162514264337593543950336.0L +
	        (long द्विगुण)bn[2] * 18446744073709551616.0L +
	        (long द्विगुण)bn[1] * 4294967296.0L +
	        (long द्विगुण)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            सचे (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (भिन्न)d;
            } अञ्ञथा सचे (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } अञ्ञथा {
                tok = TOK_CDOUBLE;
                tokc.d = (द्विगुण)d;
            }
        } अञ्ञथा {
            /* decimal floats */
            सचे (ch == '.') {
                सचे (q >= token_buf + STRING_MAX_SIZE)
                    गच्छ अङ्कः_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                याव (ch >= '0' && ch <= '9') {
                    सचे (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            सचे (ch == 'e' || ch == 'E') {
                सचे (q >= token_buf + STRING_MAX_SIZE)
                    गच्छ अङ्कः_too_long;
                *q++ = ch;
                ch = *p++;
                सचे (ch == '-' || ch == '+') {
                    सचे (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                सचे (ch < '0' || ch > '9')
                    expect("exponent digits");
                याव (ch >= '0' && ch <= '9') {
                    सचे (q >= token_buf + STRING_MAX_SIZE)
                        गच्छ अङ्कः_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            सचे (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, रिक्त);
            } अञ्ञथा सचे (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, रिक्त);
            } अञ्ञथा {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, रिक्त);
            }
        }
    } अञ्ञथा {
        unsigned long long n, n1;
        पूर्णाङ्क lcount, ucount, ov = 0;
        ध्रुव वर्ण *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        सचे (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        याव(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            सचे (t == '\0')
                भङ्ग;
            अञ्ञथा सचे (t >= 'a')
                t = t - 'a' + 10;
            अञ्ञथा सचे (t >= 'A')
                t = t - 'A' + 10;
            अञ्ञथा
                t = t - '0';
            सचे (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            सचे (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        अत्थाय(;;) {
            t = toup(ch);
            सचे (t == 'L') {
                सचे (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                सचे (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } अञ्ञथा सचे (t == 'U') {
                सचे (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } अञ्ञथा {
                भङ्ग;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        सचे (pp_व्यञ्जकम्)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        सचे (ucount == 0 && b == 10) {
            सचे (lcount <= (LONG_SIZE == 4)) {
                सचे (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            सचे (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } अञ्ञथा {
            सचे (lcount <= (LONG_SIZE == 4)) {
                सचे (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                अञ्ञथा सचे (n >= 0x80000000U)
                    ucount = 1;
            }
            सचे (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        सचे (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	सचे (lcount) {
            tok = TOK_CLONG;
            सचे (lcount == 2)
                tok = TOK_CLLONG;
	}
	सचे (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    सचे (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    पक्ष c1:                                    \
        PEEKC(c, p);                            \
        सचे (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } अञ्ञथा {                                \
            tok = tok1;                         \
        }                                       \
        भङ्ग;

/* return next token without macro substitution */
स्थिर शून्य next_nomacro(शून्य)
{
    पूर्णाङ्क t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned पूर्णाङ्क h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    विकल्प(c) {
    पक्ष ' ':
    पक्ष '\t':
        tok = c;
        p++;
 maybe_space:
        सचे (parse_flags & PARSE_FLAG_SPACES)
            गच्छ keep_tok_flags;
        याव (isidnum_table[*p - CH_EOF] & IS_SPC)
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
        सचे (c == '\\')
            गच्छ parse_simple;
        सचे (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            सचे (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                गच्छ maybe_newline;
            } अञ्ञथा सचे (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } अञ्ञथा सचे (s1->ifdef_राशिः_ptr != file->ifdef_राशिः_ptr) {
                tcc_error("missing #endif");
            } अञ्ञथा सचे (s1->include_राशिः_ptr == s1->include_राशिः) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } अञ्ञथा {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                सचे (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, रिक्त));
#endif
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
        } अञ्ञथा {
            गच्छ redo_no_start;
        }
        भङ्ग;

    पक्ष '\n':
        file->पङ्क्तिः_अङ्कः++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        सचे (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            गच्छ redo_no_start;
        tok = TOK_LINEFEED;
        गच्छ keep_tok_flags;

    पक्ष '#':
        /* XXX: simplify */
        PEEKC(c, p);
        सचे ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            गच्छ maybe_newline;
        } अञ्ञथा {
            सचे (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } अञ्ञथा {
#सचे !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                सचे (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_पङ्क्तिः_comment(p - 1);
                    गच्छ redo_no_start;
                } अञ्ञथा
#endif
                {
                    tok = '#';
                }
            }
        }
        भङ्ग;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    पक्ष '$':
        सचे (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        याव (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_अङ्कः))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        सचे (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            अत्थाय(;;) {
                ts = *pts;
                सचे (!ts)
                    भङ्ग;
                सचे (ts->len == len && !memcmp(ts->str, p1, len))
                    गच्छ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (वर्ण *) p1, len);
        token_found: ;
        } अञ्ञथा {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (वर्ण *) p1, len);
            p--;
            PEEKC(c, p);
            याव (isidnum_table[c - CH_EOF] & (IS_ID|IS_अङ्कः))
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
        सचे (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            सचे (c == '\'' || c == '\"') {
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
        अत्थाय(;;) {
            cstr_ccat(&tokcstr, t);
            सचे (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_अङ्कः))
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
        सचे (isnum(c)) {
            t = '.';
            गच्छ parse_अङ्कः;
        } अञ्ञथा सचे ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_अङ्कः))) {
            *--p = c = '.';
            गच्छ parse_ident_fast;
        } अञ्ञथा सचे (c == '.') {
            PEEKC(c, p);
            सचे (c == '.') {
                p++;
                tok = TOK_DOTS;
            } अञ्ञथा {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } अञ्ञथा {
            tok = '.';
        }
        भङ्ग;
    पक्ष '\'':
    पक्ष '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        सचे (is_long)
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
        सचे (c == '=') {
            p++;
            tok = TOK_LE;
        } अञ्ञथा सचे (c == '<') {
            PEEKC(c, p);
            सचे (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } अञ्ञथा {
                tok = TOK_SHL;
            }
        } अञ्ञथा {
            tok = TOK_LT;
        }
        भङ्ग;
    पक्ष '>':
        PEEKC(c, p);
        सचे (c == '=') {
            p++;
            tok = TOK_GE;
        } अञ्ञथा सचे (c == '>') {
            PEEKC(c, p);
            सचे (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } अञ्ञथा {
                tok = TOK_SAR;
            }
        } अञ्ञथा {
            tok = TOK_GT;
        }
        भङ्ग;
        
    पक्ष '&':
        PEEKC(c, p);
        सचे (c == '&') {
            p++;
            tok = TOK_LAND;
        } अञ्ञथा सचे (c == '=') {
            p++;
            tok = TOK_A_AND;
        } अञ्ञथा {
            tok = '&';
        }
        भङ्ग;
        
    पक्ष '|':
        PEEKC(c, p);
        सचे (c == '|') {
            p++;
            tok = TOK_LOR;
        } अञ्ञथा सचे (c == '=') {
            p++;
            tok = TOK_A_OR;
        } अञ्ञथा {
            tok = '|';
        }
        भङ्ग;

    पक्ष '+':
        PEEKC(c, p);
        सचे (c == '+') {
            p++;
            tok = TOK_INC;
        } अञ्ञथा सचे (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } अञ्ञथा {
            tok = '+';
        }
        भङ्ग;
        
    पक्ष '-':
        PEEKC(c, p);
        सचे (c == '-') {
            p++;
            tok = TOK_DEC;
        } अञ्ञथा सचे (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } अञ्ञथा सचे (c == '>') {
            p++;
            tok = TOK_ARROW;
        } अञ्ञथा {
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
        सचे (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            गच्छ maybe_space;
        } अञ्ञथा सचे (c == '/') {
            p = parse_पङ्क्तिः_comment(p);
            tok = ' ';
            गच्छ maybe_space;
        } अञ्ञथा सचे (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } अञ्ञथा {
            tok = '/';
        }
        भङ्ग;
        
        /* simple tokens */
    पक्ष '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        सचे (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_पङ्क्तिः_comment(p);
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
        सचे (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            गच्छ redo_no_start;
        }
    स्वभाव:
        सचे (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    गच्छ parse_ident_fast;
        सचे (parse_flags & PARSE_FLAG_ASM_FILE)
            गच्छ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        भङ्ग;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#सचे defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
स्थिर पूर्णाङ्क indent;
स्थिर शून्य define_print(TCCState *s1, पूर्णाङ्क v);
स्थिर शून्य pp_print(ध्रुव वर्ण *सन्देशः, पूर्णाङ्क v, ध्रुव पूर्णाङ्क *str)
{
    FILE *fp = tcc_state->ppfp;

    सचे (सन्देशः[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    अञ्ञथा सचे (सन्देशः[0] == '+')
         ++indent, ++सन्देशः;
    अञ्ञथा सचे (सन्देशः[0] == '-')
        --indent, ++सन्देशः;

    fprintf(fp, "%*s", indent, "");
    सचे (सन्देशः[0] == '#') {
        define_print(tcc_state, v);
    } अञ्ञथा {
        tok_print(str, v ? "%s %s" : "%s", सन्देशः, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#अञ्ञथा
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
    अत्थाय (s = args, n = 0; s; s = s->prev, ++n);
    याव (n--) {
        अत्थाय (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    याव(1) {
        TOK_GET(&t, &macro_str, &cval);
        सचे (!t)
            भङ्ग;
        सचे (t == '#') {
            /* stringize */
            करोहि t = *macro_str++; याव (t == ' ');
            s = sym_find2(args, t);
            सचे (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                याव (*st != TOK_EOF) {
                    ध्रुव वर्ण *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    याव (*s) {
                        सचे (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        अञ्ञथा
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
            } अञ्ञथा सचे ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } अञ्ञथा {
                expect("macro parameter after '#'");
            }
        } अञ्ञथा सचे (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            सचे (s) {
                st = s->d;
                n = 0;
                याव ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                सचे (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    सचे (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        पूर्णाङ्क c = str.str[str.len - 1];
                        याव (str.str[--str.len] != ',')
                            ;
                        सचे (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } अञ्ञथा {
                            /* suppress '##' and add variable */
                            str.len++;
                            सचे (c == ' ')
                                str.str[str.len++] = c;
                            गच्छ add_var;
                        }
                    } अञ्ञथा {
                        सचे (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } अञ्ञथा {
            add_var:
		    सचे (!s->e) {
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
                याव (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } अञ्ञथा {
                tok_str_add(&str, t);
            }
        } अञ्ञथा {
            tok_str_add2(&str, t, &cval);
        }
        सचे (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    पटिनिवत्त str.str;
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
    अत्थाय (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        सचे (t1 == 0)
            भङ्ग;
        अत्थाय (;;) {
            n = 0;
            याव ((t2 = ptr[n]) == ' ')
                ++n;
            सचे (t2 != TOK_PPJOIN)
                भङ्ग;
            ptr += n;
            याव ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            सचे (t2 == TOK_PLCHLDR)
                अनुवर्त;
            सचे (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        सचे (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            अत्थाय (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                सचे (*file->buf_ptr == 0)
                    भङ्ग;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        सचे (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    पटिनिवत्त macro_str1.str;
}

स्थिर पूर्णाङ्क peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    पूर्णाङ्क c;
    अत्थाय (;;) {
        PEEKC(c, p);
        विकल्प (c) {
        पक्ष '/':
            PEEKC(c, p);
            सचे (c == '*')
                p = parse_comment(p);
            अञ्ञथा सचे (c == '/')
                p = parse_पङ्क्तिः_comment(p);
            अञ्ञथा {
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
            पटिनिवत्त c;
        }
        सचे (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
स्थिर पूर्णाङ्क next_argstream(Sym **nested_list, TokenString *ws_str)
{
    पूर्णाङ्क t;
    Sym *sa;

    याव (macro_ptr) {
        ध्रुव पूर्णाङ्क *m = macro_ptr;
        याव ((t = *m) != 0) {
            सचे (ws_str) {
                सचे (t != ' ')
                    पटिनिवत्त t;
                ++m;
            } अञ्ञथा {
                TOK_GET(&tok, &macro_ptr, &tokc);
                पटिनिवत्त tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        सचे (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    सचे (ws_str) {
        पटिनिवत्त peek_file(ws_str);
    } अञ्ञथा {
        next_nomacro();
        सचे (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        पटिनिवत्त tok;
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
    सचे (s->d) {
        पूर्णाङ्क *mstr = s->d;
        पूर्णाङ्क *jstr;
        Sym *sa;
        पूर्णाङ्क ret;

        सचे (s->type.t & MACRO_FUNC) {
            पूर्णाङ्क saved_parse_flags = parse_flags;
            TokenString str;
            पूर्णाङ्क parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            सचे (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                सचे (parse_flags & PARSE_FLAG_SPACES)
                    अत्थाय (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                पटिनिवत्त 0;
            } अञ्ञथा {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = रिक्त;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            अत्थाय(;;) {
                करोहि {
                    t = next_argstream(nested_list, रिक्त);
                } याव (t == ' ' || --i);

                सचे (!sa) {
                    सचे (t == ')') /* handle '()' case */
                        भङ्ग;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                याव (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    सचे (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    सचे (t == '(')
                        parlevel++;
                    सचे (t == ')')
                        parlevel--;
                    सचे (t == ' ')
                        str.need_spc |= 1;
                    अञ्ञथा
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, रिक्त);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                सचे (t == ')') {
                    सचे (!sa)
                        भङ्ग;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    सचे (sa->type.t && gnu_ext)
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
            याव (sa) {
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
        सचे (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        सचे (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        सचे (jstr != mstr)
            tok_str_free_str(jstr);
        सचे (mstr != s->d)
            tok_str_free_str(mstr);
        पटिनिवत्त ret;

    } अञ्ञथा {
        CValue cval;
        वर्ण buf[32], *cstrval = buf;

        /* special macros */
        सचे (v == TOK_पङ्क्तिः_2 || v == TOK___COUNTER__) {
            t = v == TOK_पङ्क्तिः_2 ? file->पङ्क्तिः_अङ्कः : pp_counter++;
            snprintf(buf, परिमाण(buf), "%d", t);
            t = TOK_PPNUM;
            गच्छ add_cstr1;

        } अञ्ञथा सचे (v == TOK___FILE__) {
            cstrval = file->filename;
            गच्छ add_cstr;

        } अञ्ञथा सचे (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            संरचना tm *tm;
            time(&ti);
            tm = localtime(&ti);
            सचे (v == TOK___DATE__) {
                स्थिर वर्ण ध्रुव ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, परिमाण(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } अञ्ञथा {
                snprintf(buf, परिमाण(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        पटिनिवत्त 0;
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

    याव (1) {
        TOK_GET(&t, &macro_str, &cval);
        सचे (t == 0 || t == TOK_EOF)
            भङ्ग;
        सचे (t >= TOK_IDENT) {
            s = define_find(t);
            सचे (s == रिक्त || nosubst)
                गच्छ no_subst;
            /* if nested substitution, do nothing */
            सचे (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                गच्छ no_subst;
            }
            str = tok_str_alloc();
            str->str = (पूर्णाङ्क*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            सचे (macro_राशिः != str) {
                /* already finished by reading function macro arguments */
                भङ्ग;
            }
            macro_str = macro_ptr;
            end_macro ();
        } अञ्ञथा सचे (t == ' ') {
            सचे (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } अञ्ञथा {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            सचे (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            सचे (t == TOK_DEFINED && pp_व्यञ्जकम्)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    पटिनिवत्त nosubst;
}

/* return next token with macro substitution */
ST_FUNC शून्य next(शून्य)
{
    पूर्णाङ्क t;
    याव (macro_ptr) {
redo:
        t = *macro_ptr;
        सचे (TOK_HAS_मानम्(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            सचे (t == TOK_LINENUM) {
                file->पङ्क्तिः_अङ्कः = tokc.i;
                गच्छ redo;
            }
            गच्छ convert;
        } अञ्ञथा सचे (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            अनुवर्त;
        } अञ्ञथा सचे (t == TOK_EOF) {
            /* do nothing */
        } अञ्ञथा {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            सचे (t == '\\') {
                सचे (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        पटिनिवत्त;
    }

    next_nomacro();
    t = tok;
    सचे (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        सचे (s) {
            Sym *nested_list = रिक्त;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            गच्छ redo;
        }
        पटिनिवत्त;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    सचे (t == TOK_PPNUM) {
        सचे  (parse_flags & PARSE_FLAG_TOK_अङ्कः)
            parse_सङ्ख्या(tokc.str.data);
    } अञ्ञथा सचे (t == TOK_PPSTR) {
        सचे (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN शून्य unget_tok(पूर्णाङ्क last_tok)
{
    TokenString *str = &unget_buf;
    पूर्णाङ्क alloc = 0;
    सचे (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    सचे (tok != TOK_EOF)
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
# सचे PTR_SIZE == 8
    "_WIN64\0"
# endif
#अञ्ञथा
# सचे defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# अञ्ञथा
    "__linux__\0"
    "__linux\0"
#  सचे TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

स्थिर शून्य putdef(CString *cs, ध्रुव वर्ण *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

स्थिर शून्य putdefs(CString *cs, ध्रुव वर्ण *p)
{
    याव (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

स्थिर शून्य tcc_predefs(TCCState *s1, CString *cs, पूर्णाङ्क is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    सचे (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    सचे (is_asm)
      putdef(cs, "__ASSEMBLER__");
    सचे (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    सचे (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    सचे (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    सचे (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    सचे (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    सचे (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    सचे (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    सचे (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    सचे (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#सचे CONFIG_TCC_PREDEFS
        #अन्तर्भाव "tccdefs_.h" /* include as strings */
#अञ्ञथा
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

    s1->include_राशिः_ptr = s1->include_राशिः;
    s1->ifdef_राशिः_ptr = s1->ifdef_राशिः;
    file->ifdef_राशिः_ptr = s1->ifdef_राशिः_ptr;
    pp_व्यञ्जकम् = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_राशिः[0] = 0;
    s1->pack_राशिः_ptr = s1->pack_राशिः;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    सचे (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        सचे (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        सचे (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_राशिः_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC शून्य preprocess_end(TCCState *s1)
{
    याव (macro_राशिः)
        end_macro();
    macro_ptr = रिक्त;
    याव (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC पूर्णाङ्क set_idnum(पूर्णाङ्क c, पूर्णाङ्क val)
{
    पूर्णाङ्क prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    पटिनिवत्त prev;
}

ST_FUNC शून्य tccpp_new(TCCState *s)
{
    पूर्णाङ्क i, c;
    ध्रुव वर्ण *p, *r;

    /* init isid table */
    अत्थाय(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_अङ्कः
            : 0);

    अत्थाय(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * परिमाण(TokenSym *));
    memset(s->cached_includes_hash, 0, परिमाण s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    याव (*p) {
        r = p;
        अत्थाय(;;) {
            c = *r++;
            सचे (c == '\0')
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
    define_प्रक्षिप(TOK___COUNTER__, MACRO_OBJ, रिक्त, रिक्त);
}

ST_FUNC शून्य tccpp_delete(TCCState *s)
{
    पूर्णाङ्क i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    सचे (n > total_idents)
        total_idents = n;
    अत्थाय (i = n; --i >= 0;)
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
    याव (str) {
	TOK_GET(&t, &str, &cval);
	सचे (t == 0 || t == TOK_EOF)
	    भङ्ग;
        सचे (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

स्थिर शून्य pp_पङ्क्तिः(TCCState *s1, BufferedFile *f, पूर्णाङ्क level)
{
    पूर्णाङ्क d = f->पङ्क्तिः_अङ्कः - f->पङ्क्तिः_ref;

    सचे (s1->dflag & 4)
	पटिनिवत्त;

    सचे (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } अञ्ञथा सचे (level == 0 && f->पङ्क्तिः_ref && d < 8) {
	याव (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } अञ्ञथा सचे (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->पङ्क्तिः_अङ्कः, f->filename);
    } अञ्ञथा {
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
    सचे (रिक्त == s || रिक्त == s->d)
        पटिनिवत्त;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, रिक्त));
    सचे (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        सचे (a)
            अत्थाय (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, रिक्त));
                सचे (!(a = a->next))
                    भङ्ग;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

स्थिर शून्य pp_debug_defines(TCCState *s1)
{
    पूर्णाङ्क v, t;
    ध्रुव वर्ण *vs;
    FILE *fp;

    t = pp_debug_tok;
    सचे (t == 0)
        पटिनिवत्त;

    file->पङ्क्तिः_अङ्कः--;
    pp_पङ्क्तिः(s1, file, 0);
    file->पङ्क्तिः_ref = ++file->पङ्क्तिः_अङ्कः;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, रिक्त);
    सचे (t == TOK_DEFINE) {
        define_print(s1, v);
    } अञ्ञथा सचे (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } अञ्ञथा सचे (t == TOK_प्रक्षिप_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } अञ्ञथा सचे (t == TOK_निष्कासय_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
स्थिर पूर्णाङ्क pp_need_space(पूर्णाङ्क a, पूर्णाङ्क b)
{
    पटिनिवत्त 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
स्थिर पूर्णाङ्क pp_check_he0xE(पूर्णाङ्क t, ध्रुव वर्ण *p)
{
    सचे (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        पटिनिवत्त 'E';
    पटिनिवत्त t;
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
    सचे (s1->Pflag == पङ्क्तिः_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_अङ्कः, s1->Pflag = 1;

    सचे (s1->do_bench) {
	/* for PP benchmarks */
	करोहि next(); याव (tok != TOK_EOF);
	पटिनिवत्त 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    सचे (file->prev)
        pp_पङ्क्तिः(s1, file->prev, level++);
    pp_पङ्क्तिः(s1, file, level);

    अत्थाय (;;) {
        iptr = s1->include_राशिः_ptr;
        next();
        सचे (tok == TOK_EOF)
            भङ्ग;

        level = s1->include_राशिः_ptr - iptr;
        सचे (level) {
            सचे (level > 0)
                pp_पङ्क्तिः(s1, *iptr, 0);
            pp_पङ्क्तिः(s1, file, level);
        }
        सचे (s1->dflag & 7) {
            pp_debug_defines(s1);
            सचे (s1->dflag & 4)
                अनुवर्त;
        }

        सचे (is_space(tok)) {
            सचे (spcs < परिमाण white - 1)
                white[spcs++] = tok;
            अनुवर्त;
        } अञ्ञथा सचे (tok == TOK_LINEFEED) {
            spcs = 0;
            सचे (token_seen == TOK_LINEFEED)
                अनुवर्त;
            ++file->पङ्क्तिः_ref;
        } अञ्ञथा सचे (token_seen == TOK_LINEFEED) {
            pp_पङ्क्तिः(s1, file, 0);
        } अञ्ञथा सचे (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    पटिनिवत्त 0;
}

/* ------------------------------------------------------------------------- */
