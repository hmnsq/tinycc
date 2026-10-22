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
#অন্তর্ভাৱ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA পূর্ণাঙ্ক tok_flags;
ST_DATA পূর্ণাঙ্ক parse_flags;

ST_DATA সংরচনা BufferedFile *file;
ST_DATA পূর্ণাঙ্ক tok;
ST_DATA CValue tokc;
ST_DATA ধ্রুৱ পূর্ণাঙ্ক *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA পূর্ণাঙ্ক tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA পূর্ণাঙ্ক pp_ৰাশিমালা;

/* ------------------------------------------------------------------------- */

স্থির TokenSym *hash_ident[TOK_HASH_SIZE];
স্থির ৱর্ণ token_buf[STRING_MAX_SIZE + 1];
স্থির CString cstr_buf;
স্থির TokenString tokstr_buf;
স্থির TokenString unget_buf;
স্থির unsigned ৱর্ণ isidnum_table[256 - CH_EOF];
স্থির পূর্ণাঙ্ক pp_debug_tok, pp_debug_symv;
স্থির পূর্ণাঙ্ক pp_counter;
স্থির শূন্য tok_print(ধ্রুৱ পূর্ণাঙ্ক *str, ধ্রুৱ ৱর্ণ *বাৰ্তা, ...);
স্থির শূন্য next_nomacro(শূন্য);
স্থির শূন্য parse_সংখ্যা(ধ্রুৱ ৱর্ণ *p);
স্থির শূন্য parse_string(ধ্রুৱ ৱর্ণ *p, পূর্ণাঙ্ক len);

স্থির সংরচনা TinyAlloc *toksym_alloc;
স্থির সংরচনা TinyAlloc *tokstr_alloc;

স্থির TokenString *macro_স্তূপ;

স্থির ধ্রুৱ ৱর্ণ tcc_keywords[] = 
#define DEF(id, str) str "\0"
#অন্তর্ভাৱ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
স্থির ধ্রুৱ unsigned ৱর্ণ tok_two_chars[] =
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

ST_FUNC শূন্য skip(পূর্ণাঙ্ক c)
{
    যদি (tok != c) {
        ৱর্ণ tmp[40];
        pstrcpy(tmp, পরিমাণ tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC শূন্য expect(ধ্রুৱ ৱর্ণ *বাৰ্তা)
{
    tcc_error("%s expected", বাৰ্তা);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#অন্যথা
#যদি !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#অন্যথা
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ধ্রুৱ ৱর্ণ *sfile, পূর্ণাঙ্ক sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

প্রকারনির্দেশ সংরচনা TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    সংরচনা TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#যদি TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    সঙ্ঘ {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

প্রকারনির্দেশ সংরচনা tal_header_t {
    size_t  size; /* word align */
#যদি TAL_DEBUG
    পূর্ণাঙ্ক     সাৰি_অঙ্ক; /* negative line_num used for double free check */
    ৱর্ণ    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (পরিমাণ (size_t) - 1)) & ~(পরিমাণ (size_t) - 1))

/* ------------------------------------------------------------------------- */

স্থির TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(পরিমাণ(TinyAlloc) - পরিমাণ (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#যদি TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ঘূৰাই al;
}

স্থির শূন্য tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#যদি TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#যদি TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#যদি TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    যদি (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        যেতিয়ালৈ (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            যদি (header->সাৰি_অঙ্ক > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->সাৰি_অঙ্ক, (পূর্ণাঙ্ক)header->size);
            }
            p += header->size + পরিমাণ(tal_header_t);
        }
#যদি TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    যদি (al)
        গচ্ছ tail_call;
    *pal = al;
}

স্থির শূন্য tal_free_impl(TinyAlloc **pal, শূন্য *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **শীৰ্ষ = pal;
    tal_header_t *header;

    যদি (!p)
        ঘূৰাই;
    header = (tal_header_t *)p - 1;
#যদি TAL_DEBUG
    যদি (header->সাৰি_অঙ্ক < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (পূর্ণাঙ্ক)-header->সাৰি_অঙ্ক, (পূর্ণাঙ্ক)header->size);
    } অন্যথা
        header->সাৰি_অঙ্ক = -header->সাৰি_অঙ্ক;
#endif
    al = *pal;
    যেতিয়ালৈ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    যদি (0 == --al->nb_allocs) {
        *pal = al->next;
        যদি ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } অন্যথা {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *শীৰ্ষ, *শীৰ্ষ = al;
        }
    } অন্যথা যদি ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

স্থির শূন্য *tal_realloc_impl(TinyAlloc **pal, শূন্য *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    শূন্য *ret;
    unsigned adj_size = TAL_ALIGN(size) + পরিমাণ(tal_header_t);
    TinyAlloc *al = *pal;

    যদি (p) {
        /* reallpc case */
        যেতিয়ালৈ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        যদি ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        যদি (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ঘূৰাই ret;
        } অন্যথা যদি (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#যদি TAL_DEBUG
            header->সাৰি_অঙ্ক = -header->সাৰি_অঙ্ক;
#endif
        }
    } অন্যথা {
        /* new alloc case */
        যেতিয়ালৈ (al->p + adj_size > al->bufend) {
            al = al->next;
            যদি (!al) {
                unsigned new_size = (*pal)->size;
                যদি (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                ভঙ্গ;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - পরিমাণ(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#যদি  TAL_DEBUG
    {
        পূর্ণাঙ্ক ofs = strlen(sfile) + 1 - পরিমাণ header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->সাৰি_অঙ্ক = sline;
#যদি TAL_INFO
        যদি (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        যদি (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ঘূৰাই ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
স্থির শূন্য cstr_realloc(CString *cstr, পূর্ণাঙ্ক new_size)
{
    পূর্ণাঙ্ক size;

    size = cstr->size_allocated;
    যদি (size < 8)
        size = 8; /* no need to allocate a too small first string */
    যেতিয়ালৈ (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN শূন্য cstr_ccat(CString *cstr, পূর্ণাঙ্ক ch)
{
    পূর্ণাঙ্ক size;
    size = cstr->size + 1;
    যদি (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN ৱর্ণ *unicode_to_utf8 (ৱর্ণ *b, uint32_t Uc)
{
    যদি (Uc<0x80) *b++=Uc;
    অন্যথা যদি (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    অন্যথা যদি (Uc-0xd800u<0x800) গচ্ছ error;
    অন্যথা যদি (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    অন্যথা যদি (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    অন্যথা error: tcc_error("0x%x is not a valid universal character", Uc);
    ঘূৰাই b;
}

/* add a unicode character expanded into utf8 */
ST_INLN শূন্য cstr_u8cat(CString *cstr, পূর্ণাঙ্ক ch)
{
    ৱর্ণ buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC শূন্য cstr_cat(CString *cstr, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক len)
{
    পূর্ণাঙ্ক size;
    যদি (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    যদি (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC শূন্য cstr_wccat(CString *cstr, পূর্ণাঙ্ক ch)
{
    পূর্ণাঙ্ক size;
    size = cstr->size + পরিমাণ(nwchar_t);
    যদি (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - পরিমাণ(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC শূন্য cstr_new(CString *cstr)
{
    memset(cstr, 0, পরিমাণ(CString));
}

/* free string and reset it to NULL */
ST_FUNC শূন্য cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC শূন্য cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC পূর্ণাঙ্ক cstr_vprintf(CString *cstr, ধ্রুৱ ৱর্ণ *fmt, va_list ap)
{
    va_list v;
    পূর্ণাঙ্ক len, size = 80;
    বাবে (;;) {
        size += cstr->size;
        যদি (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        যদি (len >= 0 && len < size)
            ভঙ্গ;
        size *= 2;
    }
    cstr->size += len;
    ঘূৰাই len;
}

ST_FUNC পূর্ণাঙ্ক cstr_printf(CString *cstr, ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list ap; পূর্ণাঙ্ক len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ঘূৰাই len;
}

/* XXX: unicode ? */
স্থির শূন্য add_char(CString *cstr, পূর্ণাঙ্ক c)
{
    যদি (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    যদি (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } অন্যথা {
        cstr_ccat(cstr, '\\');
        যদি (c == '\n') {
            cstr_ccat(cstr, 'n');
        } অন্যথা {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
স্থির TokenSym *tok_alloc_new(TokenSym **pts, ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক len)
{
    TokenSym *ts, **ptable;
    পূর্ণাঙ্ক i;

    যদি (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    যদি ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * পরিমাণ(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, পরিমাণ(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = রিক্ত;
    ts->sym_label = রিক্ত;
    ts->sym_struct = রিক্ত;
    ts->sym_identifier = রিক্ত;
    ts->len = len;
    ts->hash_next = রিক্ত;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ঘূৰাই ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ধ্রুৱ ৱর্ণ *str, পূর্ণাঙ্ক len)
{
    TokenSym *ts, **pts;
    পূর্ণাঙ্ক i;
    unsigned পূর্ণাঙ্ক h;
    
    h = TOK_HASH_INIT;
    বাবে(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned ৱর্ণ *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    বাবে(;;) {
        ts = *pts;
        যদি (!ts)
            ভঙ্গ;
        যদি (ts->len == len && !memcmp(ts->str, str, len))
            ঘূৰাই ts;
        pts = &(ts->hash_next);
    }
    ঘূৰাই tok_alloc_new(pts, str, len);
}

ST_FUNC পূর্ণাঙ্ক tok_alloc_const(ধ্রুৱ ৱর্ণ *str)
{
    ঘূৰাই tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ধ্রুৱ ৱর্ণ *get_tok_str(পূর্ণাঙ্ক v, CValue *cv)
{
    ৱর্ণ *p;
    পূর্ণাঙ্ক i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    ৱিকল্প(v) {
    পক্ষ TOK_CINT:
    পক্ষ TOK_CUINT:
    পক্ষ TOK_CLONG:
    পক্ষ TOK_CULONG:
    পক্ষ TOK_CLLONG:
    পক্ষ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        ভঙ্গ;
    পক্ষ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    পক্ষ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ভঙ্গ;
    পক্ষ TOK_PPNUM:
    পক্ষ TOK_PPSTR:
        ঘূৰাই (ৱর্ণ*)cv->str.data;
    পক্ষ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    পক্ষ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        যদি (v == TOK_STR) {
            len = cv->str.size - 1;
            বাবে(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned ৱর্ণ *)cv->str.data)[i]);
        } অন্যথা {
            len = (cv->str.size / পরিমাণ(nwchar_t)) - 1;
            বাবে(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ভঙ্গ;

    পক্ষ TOK_CFLOAT:
        ঘূৰাই strcpy(p, "<float>");
    পক্ষ TOK_CDOUBLE:
        ঘূৰাই strcpy(p, "<double>");
    পক্ষ TOK_CLDOUBLE:
        ঘূৰাই strcpy(p, "<long double>");
    পক্ষ TOK_LINENUM:
        ঘূৰাই strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    পক্ষ TOK_LT:
        v = '<';
        গচ্ছ addv;
    পক্ষ TOK_GT:
        v = '>';
        গচ্ছ addv;
    পক্ষ TOK_DOTS:
        ঘূৰাই strcpy(p, "...");
    পক্ষ TOK_A_SHL:
        ঘূৰাই strcpy(p, "<<=");
    পক্ষ TOK_A_SAR:
        ঘূৰাই strcpy(p, ">>=");
    পক্ষ TOK_EOF:
        ঘূৰাই strcpy(p, "<eof>");
    পক্ষ 0: /* anonymous nameless symbols */
        ঘূৰাই strcpy(p, "<no name>");
    স্ৱভাৱ:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        যদি (v < TOK_IDENT) {
            /* search in two bytes table */
            ধ্রুৱ unsigned ৱর্ণ *q = tok_two_chars;
            যেতিয়ালৈ (*q) {
                যদি (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ঘূৰাই cstr_buf.data;
                }
                q += 3;
            }
            যদি (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ভঙ্গ;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } অন্যথা যদি (v < tok_ident) {
            ঘূৰাই table_ident[v - TOK_IDENT]->str;
        } অন্যথা যদি (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } অন্যথা {
            /* should never happen */
            ঘূৰাই রিক্ত;
        }
        ভঙ্গ;
    }
    ঘূৰাই cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
স্থির পূর্ণাঙ্ক handle_eob(শূন্য)
{
    BufferedFile *bf = file;
    পূর্ণাঙ্ক len;

    /* only tries to read if really end of buffer */
    যদি (bf->buf_ptr >= bf->buf_end) {
        যদি (bf->fd >= 0) {
#যদি defined(PARSE_DEBUG)
            len = 1;
#অন্যথা
            len = IO_BUF_SIZE;
#endif
            len = পঠ(bf->fd, bf->buffer, len);
            যদি (len < 0)
                len = 0;
        } অন্যথা {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    যদি (bf->buf_ptr < bf->buf_end) {
        ঘূৰাই bf->buf_ptr[0];
    } অন্যথা {
        bf->buf_ptr = bf->buf_end;
        ঘূৰাই CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
স্থির পূর্ণাঙ্ক next_c(শূন্য)
{
    পূর্ণাঙ্ক ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    যদি (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ঘূৰাই ch;
}

/* input with '\[\r]\n' handling. */
স্থির পূর্ণাঙ্ক handle_stray_noerror(পূর্ণাঙ্ক err)
{
    পূর্ণাঙ্ক ch;
    যেতিয়ালৈ ((ch = next_c()) == '\\') {
        ch = next_c();
        যদি (ch == '\n') {
    newl:
            file->সাৰি_অঙ্ক++;
        } অন্যথা {
            যদি (ch == '\r') {
                ch = next_c();
                যদি (ch == '\n')
                    গচ্ছ newl;
                *--file->buf_ptr = '\r';
            }
            যদি (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ঘূৰাই *--file->buf_ptr = '\\';
        }
    }
    ঘূৰাই ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
স্থির পূর্ণাঙ্ক handle_bs(uint8_t **p)
{
    পূর্ণাঙ্ক c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ঘূৰাই c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
স্থির পূর্ণাঙ্ক handle_stray(uint8_t **p)
{
    পূর্ণাঙ্ক c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ঘূৰাই c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    যদি (c == '\\')\
        c = handle_stray(&p); \
}

স্থির পূর্ণাঙ্ক skip_spaces(শূন্য)
{
    পূর্ণাঙ্ক ch;
    --file->buf_ptr;
    কৰা {
        ch = ninp();
    } যেতিয়ালৈ (isidnum_table[ch - CH_EOF] & IS_SPC);
    ঘূৰাই ch;
}

/* single line C++ comments */
স্থির uint8_t *parse_সাৰি_comment(uint8_t *p)
{
    পূর্ণাঙ্ক c;
    বাবে(;;) {
        বাবে (;;) {
            c = *++p;
    redo:
            যদি (c == '\n' || c == '\\')
                ভঙ্গ;
            c = *++p;
            যদি (c == '\n' || c == '\\')
                ভঙ্গ;
        }
        যদি (c == '\n')
            ভঙ্গ;
        c = handle_bs(&p);
        যদি (c == CH_EOF)
            ভঙ্গ;
        যদি (c != '\\')
            গচ্ছ redo;
    }
    ঘূৰাই p;
}

/* C comments */
স্থির uint8_t *parse_comment(uint8_t *p)
{
    পূর্ণাঙ্ক c;
    বাবে(;;) {
        /* fast skip loop */
        বাবে(;;) {
            c = *++p;
        redo:
            যদি (c == '\n' || c == '*' || c == '\\')
                ভঙ্গ;
            c = *++p;
            যদি (c == '\n' || c == '*' || c == '\\')
                ভঙ্গ;
        }
        /* now we can handle all the cases */
        যদি (c == '\n') {
            file->সাৰি_অঙ্ক++;
        } অন্যথা যদি (c == '*') {
            কৰা {
                c = *++p;
            } যেতিয়ালৈ (c == '*');
            যদি (c == '\\')
                c = handle_bs(&p);
            যদি (c == '/')
                ভঙ্গ;
            গচ্ছ check_eof;
        } অন্যথা {
            c = handle_bs(&p);
        check_eof:
            যদি (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            যদি (c != '\\')
                গচ্ছ redo;
        }
    }
    ঘূৰাই p + 1;
}

/* parse a string without interpreting escapes */
স্থির uint8_t *parse_pp_string(uint8_t *p, পূর্ণাঙ্ক sep, CString *str)
{
    পূর্ণাঙ্ক c;
    বাবে(;;) {
        c = *++p;
    redo:
        যদি (c == sep) {
            ভঙ্গ;
        } অন্যথা যদি (c == '\\') {
            c = handle_bs(&p);
            যদি (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } অন্যথা যদি (c == '\\') {
                যদি (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                যদি (c == '\\') {
                    c = handle_bs(&p);
                    যদি (c == CH_EOF)
                        গচ্ছ unterminated_string;
                }
                গচ্ছ add_char;
            } অন্যথা {
                গচ্ছ redo;
            }
        } অন্যথা যদি (c == '\n') {
        add_lf:
            যদি (ACCEPT_LF_IN_STRINGS) {
                file->সাৰি_অঙ্ক++;
                গচ্ছ add_char;
            } অন্যথা যদি (str) { /* not skipping */
                গচ্ছ unterminated_string;
            } অন্যথা {
                //tcc_warning("missing terminating %c character", sep);
                ঘূৰাই p;
            }
        } অন্যথা যদি (c == '\r') {
            c = *++p;
            যদি (c == '\\')
                c = handle_bs(&p);
            যদি (c == '\n')
                গচ্ছ add_lf;
            যদি (c == CH_EOF)
                গচ্ছ unterminated_string;
            যদি (str)
                cstr_ccat(str, '\r');
            গচ্ছ redo;
        } অন্যথা {
        add_char:
            যদি (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ঘূৰাই p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
স্থির শূন্য preprocess_skip(শূন্য)
{
    পূর্ণাঙ্ক a, start_of_সাৰি, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_সাৰি = 1;
    in_warn_or_error = 0;
    বাবে(;;) {
        c = *p;
        ৱিকল্প(c) {
        পক্ষ ' ':
        পক্ষ '\t':
        পক্ষ '\f':
        পক্ষ '\v':
        পক্ষ '\r':
            p++;
            অনুৱর্ত;
        পক্ষ '\n':
            file->সাৰি_অঙ্ক++;
            p++;
            গচ্ছ redo_start;
        পক্ষ '\\':
            c = handle_bs(&p);
            যদি (c == CH_EOF)
                expect("#endif");
            যদি (c == '\\')
                ++p;
            অনুৱর্ত;
        /* skip strings */
        পক্ষ '\"':
        পক্ষ '\'':
            যদি (in_warn_or_error)
                গচ্ছ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, রিক্ত);
            ভঙ্গ;
        /* skip comments */
        পক্ষ '/':
            যদি (in_warn_or_error)
                গচ্ছ _default;
            ++p;
            c = handle_bs(&p);
            যদি (c == '*') {
                p = parse_comment(p);
            } অন্যথা যদি (c == '/') {
                p = parse_সাৰি_comment(p);
            }
            অনুৱর্ত;
        পক্ষ '#':
            p++;
            যদি (start_of_সাৰি) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                যদি (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    গচ্ছ the_end;
                যদি (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                অন্যথা যদি (tok == TOK_ENDIF)
                    a--;
                অন্যথা যদি( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                অন্যথা যদি (tok == TOK_LINEFEED)
                    গচ্ছ redo_start;
                অন্যথা যদি (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_সাৰি_comment(p - 1);
            }
#যদি !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            অন্যথা যদি (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_সাৰি_comment(p - 1);
#অন্যথা
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            ভঙ্গ;
_default:
        স্ৱভাৱ:
            p++;
            ভঙ্গ;
        }
        start_of_সাৰি = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#যদি 0
/* return the number of additional 'ints' necessary to store the
   token */
স্থির অন্তঃস্থ পূর্ণাঙ্ক tok_size(ধ্রুৱ পূর্ণাঙ্ক *p)
{
    ৱিকল্প(*p) {
        /* 4 bytes */
    পক্ষ TOK_CINT:
    পক্ষ TOK_CUINT:
    পক্ষ TOK_CCHAR:
    পক্ষ TOK_LCHAR:
    পক্ষ TOK_CFLOAT:
    পক্ষ TOK_LINENUM:
        ঘূৰাই 1 + 1;
    পক্ষ TOK_STR:
    পক্ষ TOK_LSTR:
    পক্ষ TOK_PPNUM:
    পক্ষ TOK_PPSTR:
        ঘূৰাই 1 + 1 + (p[1] + 3) / 4;
    পক্ষ TOK_CLONG:
    পক্ষ TOK_CULONG:
	ঘূৰাই 1 + LONG_SIZE / 4;
    পক্ষ TOK_CDOUBLE:
    পক্ষ TOK_CLLONG:
    পক্ষ TOK_CULLONG:
        ঘূৰাই 1 + 2;
    পক্ষ TOK_CLDOUBLE:
        ঘূৰাই 1 + LDOUBLE_শব্দগুলি;
    স্ৱভাৱ:
        ঘূৰাই 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN শূন্য tok_str_new(TokenString *s)
{
    s->str = রিক্ত;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_সাৰি_অঙ্ক = -1;
}

ST_FUNC TokenString *tok_str_alloc(শূন্য)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, পরিমাণ *str);
    tok_str_new(str);
    ঘূৰাই str;
}

ST_FUNC শূন্য tok_str_free_str(পূর্ণাঙ্ক *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC শূন্য tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC পূর্ণাঙ্ক *tok_str_realloc(TokenString *s, পূর্ণাঙ্ক new_size)
{
    পূর্ণাঙ্ক *str, size;

    size = s->allocated_len;
    যদি (size < 16)
        size = 16;
    যেতিয়ালৈ (size < new_size)
        size = size * 2;
    যদি (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * পরিমাণ(পূর্ণাঙ্ক));
        s->allocated_len = size;
        s->str = str;
    }
    ঘূৰাই s->str;
}

ST_FUNC শূন্য tok_str_add(TokenString *s, পূর্ণাঙ্ক t)
{
    পূর্ণাঙ্ক len, *str;

    len = s->len;
    str = s->str;
    যদি (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC শূন্য begin_macro(TokenString *str, পূর্ণাঙ্ক alloc)
{
    str->alloc = alloc;
    str->prev = macro_স্তূপ;
    str->prev_ptr = macro_ptr;
    str->save_সাৰি_অঙ্ক = file->সাৰি_অঙ্ক;
    macro_ptr = str->str;
    macro_স্তূপ = str;
}

ST_FUNC শূন্য end_macro(শূন্য)
{
    TokenString *str = macro_স্তূপ;
    macro_স্তূপ = str->prev;
    macro_ptr = str->prev_ptr;
    file->সাৰি_অঙ্ক = str->save_সাৰি_অঙ্ক;
    যদি (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } অন্যথা {
        যদি (str->alloc == 2)
            str->str = রিক্ত; /* don't free */
        tok_str_free(str);
    }
}

স্থির শূন্য tok_str_add2(TokenString *s, পূর্ণাঙ্ক t, CValue *cv)
{
    পূর্ণাঙ্ক len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    যদি (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    ৱিকল্প(t) {
    পক্ষ TOK_CINT:
    পক্ষ TOK_CUINT:
    পক্ষ TOK_CCHAR:
    পক্ষ TOK_LCHAR:
    পক্ষ TOK_CFLOAT:
    পক্ষ TOK_LINENUM:
#যদি LONG_SIZE == 4
    পক্ষ TOK_CLONG:
    পক্ষ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        ভঙ্গ;
    পক্ষ TOK_PPNUM:
    পক্ষ TOK_PPSTR:
    পক্ষ TOK_STR:
    পক্ষ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_শব্দগুলি =
                1 + (cv->str.size + পরিমাণ(পূর্ণাঙ্ক) - 1) / পরিমাণ(পূর্ণাঙ্ক);
            যদি (len + nb_শব্দগুলি >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_শব্দগুলি + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_শব্দগুলি;
        }
        ভঙ্গ;
    পক্ষ TOK_CDOUBLE:
    পক্ষ TOK_CLLONG:
    পক্ষ TOK_CULLONG:
#যদি LONG_SIZE == 8
    পক্ষ TOK_CLONG:
    পক্ষ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ভঙ্গ;
    পক্ষ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        যদি (LDOUBLE_শব্দগুলি >= 3)
        str[len++] = cv->tab[2];
        যদি (LDOUBLE_শব্দগুলি >= 4)
        str[len++] = cv->tab[3];
    স্ৱভাৱ:
        ভঙ্গ;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC শূন্য tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    যদি (file->সাৰি_অঙ্ক != s->last_সাৰি_অঙ্ক) {
        s->last_সাৰি_অঙ্ক = file->সাৰি_অঙ্ক;
        cval.i = s->last_সাৰি_অঙ্ক;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
স্থির শূন্য tok_str_add2_spc(TokenString *s, পূর্ণাঙ্ক t, CValue *cv)
{
    যদি (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
স্থির অন্তঃস্থ শূন্য tok_get(পূর্ণাঙ্ক *t, ধ্রুৱ পূর্ণাঙ্ক **pp, CValue *cv)
{
    ধ্রুৱ পূর্ণাঙ্ক *p = *pp;
    পূর্ণাঙ্ক n, *tab;

    tab = cv->tab;
    ৱিকল্প(*t = *p++) {
#যদি LONG_SIZE == 4
    পক্ষ TOK_CLONG:
#endif
    পক্ষ TOK_CINT:
    পক্ষ TOK_CCHAR:
    পক্ষ TOK_LCHAR:
    পক্ষ TOK_LINENUM:
        cv->i = *p++;
        ভঙ্গ;
#যদি LONG_SIZE == 4
    পক্ষ TOK_CULONG:
#endif
    পক্ষ TOK_CUINT:
        cv->i = (unsigned)*p++;
        ভঙ্গ;
    পক্ষ TOK_CFLOAT:
	tab[0] = *p++;
	ভঙ্গ;
    পক্ষ TOK_STR:
    পক্ষ TOK_LSTR:
    পক্ষ TOK_PPNUM:
    পক্ষ TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (ৱর্ণ*)p;
        p += (cv->str.size + পরিমাণ(পূর্ণাঙ্ক) - 1) / পরিমাণ(পূর্ণাঙ্ক);
        ভঙ্গ;
    পক্ষ TOK_CDOUBLE:
    পক্ষ TOK_CLLONG:
    পক্ষ TOK_CULLONG:
#যদি LONG_SIZE == 8
    পক্ষ TOK_CLONG:
    পক্ষ TOK_CULONG:
#endif
        n = 2;
        গচ্ছ copy;
    পক্ষ TOK_CLDOUBLE:
        n = LDOUBLE_শব্দগুলি;
    copy:
        কৰা
            *tab++ = *p++;
        যেতিয়ালৈ (--n);
        ভঙ্গ;
    স্ৱভাৱ:
        ভঙ্গ;
    }
    *pp = p;
}

#যদি 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#অন্যথা
# define TOK_GET(t,p,c) কৰা { \
    পূর্ণাঙ্ক _t = **(p); \
    যদি (TOK_HAS_মান(_t)) \
        tok_get(t, p, c); \
    অন্যথা \
        *(t) = _t, ++*(p); \
    } যেতিয়ালৈ (0)
#endif

স্থির পূর্ণাঙ্ক macro_is_equal(ধ্রুৱ পূর্ণাঙ্ক *a, ধ্রুৱ পূর্ণাঙ্ক *b)
{
    CValue cv;
    পূর্ণাঙ্ক t;

    যদি (!a || !b)
        ঘূৰাই 1;

    যেতিয়ালৈ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        যদি (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ঘূৰাই 0;
    }
    ঘূৰাই !(*a || *b);
}

/* defines handling */
ST_INLN শূন্য define_ঠেলো(পূর্ণাঙ্ক v, পূর্ণাঙ্ক macro_type, পূর্ণাঙ্ক *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_স্তূপ, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    যদি (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, রিক্ত));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC শূন্য define_undef(Sym *s)
{
    পূর্ণাঙ্ক v = s->v;
    যদি (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = রিক্ত;
}

ST_INLN Sym *define_find(পূর্ণাঙ্ক v)
{
    v -= TOK_IDENT;
    যদি ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ঘূৰাই রিক্ত;
    ঘূৰাই table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC শূন্য free_defines(Sym *b)
{
    যেতিয়ালৈ (define_স্তূপ != b) {
        Sym *শীৰ্ষ = define_স্তূপ;
        define_স্তূপ = শীৰ্ষ->prev;
        tok_str_free_str(শীৰ্ষ->d);
        define_undef(শীৰ্ষ);
        sym_free(শীৰ্ষ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
স্থির শূন্য maybe_run_test(TCCState *s)
{
    ধ্রুৱ ৱর্ণ *p;
    যদি (s->include_স্তূপ_ptr != s->include_স্তূপ)
        ঘূৰাই;
    p = get_tok_str(tok, রিক্ত);
    যদি (0 != memcmp(p, "test_", 5))
        ঘূৰাই;
    যদি (0 != --s->run_test)
        ঘূৰাই;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ঠেলো(tok, MACRO_OBJ, রিক্ত, রিক্ত);
}

ST_FUNC শূন্য skip_to_eol(পূর্ণাঙ্ক warn)
{
    যদি (tok == TOK_LINEFEED)
        ঘূৰাই;
    যদি (warn)
        tcc_warning("extra tokens after directive");
    যেতিয়ালৈ (macro_স্তূপ)
        end_macro();
    file->buf_ptr = parse_সাৰি_comment(file->buf_ptr - 1);
    next_nomacro();
}

স্থির CachedInclude *
অনুসন্ধান_cached_include(TCCState *s1, ধ্রুৱ ৱর্ণ *filename, পূর্ণাঙ্ক add);

স্থির পূর্ণাঙ্ক parse_include(TCCState *s1, পূর্ণাঙ্ক do_next, পূর্ণাঙ্ক test)
{
    পূর্ণাঙ্ক c, i;
    ৱর্ণ name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    যদি (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, পরিমাণ name, tokcstr.data, i);
        next_nomacro();
    } অন্যথা {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        বাবে (;;) {
            next();
            p = name, i = strlen(p) - 1;
            যদি (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ভঙ্গ;
            যদি (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, পরিমাণ name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    যদি (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    বাবে (;;) {
        ++i;
        যদি (i == 0) {
            /* check absolute include path */
            যদি (!IS_ABSPATH(name))
                অনুৱর্ত;
            buf[0] = '\0';
        } অন্যথা যদি (i == 1) {
            /* search in file's dir if "header.h" */
            যদি (c != '\"')
                অনুৱর্ত;
            p = file->true_filename;
            pstrncpy(buf, পরিমাণ buf, p, tcc_basename(p) - p);
        } অন্যথা {
            পূর্ণাঙ্ক j = i - 2, k = j - s1->nb_include_paths;
            যদি (k < 0)
                p = s1->include_paths[j];
            অন্যথা যদি (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            অন্যথা যদি (test)
                ঘূৰাই 0;
            অন্যথা
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, পরিমাণ buf, p);
            pstrcat(buf, পরিমাণ buf, "/");
        }
        pstrcat(buf, পরিমাণ buf, name);
        e = অনুসন্ধান_cached_include(s1, buf, 0);
        যদি (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            যদি ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (পূর্ণাঙ্ক)(s1->include_স্তূপ_ptr - s1->include_স্তূপ), "", buf);
            ঘূৰাই 1;
        }
        যদি (tcc_open(s1, buf) >= 0)
            ভঙ্গ;
    }

    যদি (test) {
        tcc_close();
    } অন্যথা {
        যদি (s1->include_স্তূপ_ptr >= s1->include_স্তূপ + INCLUDE_স্তূপ_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_স্তূপ_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        যদি (s1->gen_deps) {
            BufferedFile *bf = file;
            যেতিয়ালৈ (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            যদি (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ঘূৰাই 1;
}

/* eval an expression for #if/#elif */
স্থির পূর্ণাঙ্ক ৰাশিমালা_preprocess(TCCState *s1)
{
    পূর্ণাঙ্ক c, t;
    পূর্ণাঙ্ক t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_ৰাশিমালা = 1;
    যেতিয়ালৈ (1) {
        next(); /* do macro subst */
        t = tok;
        যদি (tok < TOK_IDENT) {
            যদি (tok == TOK_LINEFEED || tok == TOK_EOF)
                ভঙ্গ;
            যদি (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } অন্যথা যদি (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            যদি (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            যদি (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            যদি (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            যদি (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            যদি (t == '(') {
                next();
                যদি (tok != ')')
                    expect("')'");
            }
            গচ্ছ c_সংখ্যা;
        } অন্যথা যদি (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    যদি (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            যদি (tok != ')')
                expect("')'");
            গচ্ছ c_সংখ্যা;
        } অন্যথা {
            /* if undefined macro, replace with zero */
            c = 0;
        c_সংখ্যা:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    যদি (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_ৰাশিমালা = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = ৰাশিমালা_const();
    যদি (tok != TOK_EOF)
        tcc_error("...");
    pp_ৰাশিমালা = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ঘূৰাই c != 0;
}

ST_FUNC শূন্য pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_ৰাশিমালা, 0));
    macro_ptr = macro_স্তূপ->str;
    যেতিয়ালৈ (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC শূন্য parse_define(শূন্য)
{
    Sym *s, *first, **ps;
    পূর্ণাঙ্ক v, t, varg, is_vaargs, t0;
    পূর্ণাঙ্ক saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    যদি (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = রিক্ত;
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
    যদি (tok == '(') {
        পূর্ণাঙ্ক dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        যদি (tok != ')') বাবে (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            যদি (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } অন্যথা যদি (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            যদি (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_স্তূপ, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            যদি (tok == ')')
                ভঙ্গ;
            যদি (tok != ',' || is_vaargs)
                গচ্ছ bad_list;
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
    যেতিয়ালৈ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        যদি (is_space(tok)) {
            str.need_spc |= 1;
        } অন্যথা {
            যদি (TOK_TWOSHARPS == tok) {
                যদি (0 == t0)
                    গচ্ছ bad_twosharp;
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
    যদি (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ঠেলো(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

স্থির CachedInclude *অনুসন্ধান_cached_include(TCCState *s1, ধ্রুৱ ৱর্ণ *filename, পূর্ণাঙ্ক add)
{
    ধ্রুৱ ৱর্ণ *s, *basename;
    unsigned পূর্ণাঙ্ক h;
    CachedInclude *e;
    পূর্ণাঙ্ক c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    যেতিয়ালৈ ((c = (unsigned ৱর্ণ)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#অন্যথা
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    বাবে(;;) {
        যদি (i == 0)
            ভঙ্গ;
        e = s1->cached_includes[i - 1];
        যদি (0 == PATHCMP(filename, e->filename))
            ঘূৰাই e;
        যদি (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ঘূৰাই e;
        i = e->hash_next;
    }
    যদি (!add)
        ঘূৰাই রিক্ত;

    e = tcc_malloc(পরিমাণ(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    ঘূৰাই e;
}

স্থির পূর্ণাঙ্ক pragma_parse(TCCState *s1)
{
    next_nomacro();
    যদি (tok == TOK_ঠেলো_macro || tok == TOK_বেৰ_কৰো_macro) {
        পূর্ণাঙ্ক t = tok, v;
        Sym *s;

        যদি (next(), tok != '(')
            গচ্ছ pragma_err;
        যদি (next(), tok != TOK_STR)
            গচ্ছ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        যদি (next(), tok != ')')
            গচ্ছ pragma_err;
        যদি (t == TOK_ঠেলো_macro) {
            যেতিয়ালৈ (রিক্ত == (s = define_find(v)))
                define_ঠেলো(v, 0, রিক্ত, রিক্ত);
            s->type.ref = s; /* set push boundary */
        } অন্যথা {
            বাবে (s = define_স্তূপ; s; s = s->prev)
                যদি (s->v == v && s->type.ref == s) {
                    s->type.ref = রিক্ত;
                    ভঙ্গ;
                }
        }
        যদি (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : রিক্ত;
        অন্যথা
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } অন্যথা যদি (tok == TOK_once) {
        অনুসন্ধান_cached_include(s1, file->true_filename, 1)->once = 1;

    } অন্যথা যদি (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ঘূৰাই 1;

    } অন্যথা যদি (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        যদি (tok == TOK_ASM_বেৰ_কৰো) {
            next();
            যদি (s1->pack_স্তূপ_ptr <= s1->pack_স্তূপ) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_স্তূপ_ptr--;
        } অন্যথা {
            পূর্ণাঙ্ক val = 0;
            যদি (tok != ')') {
                যদি (tok == TOK_ASM_ঠেলো) {
                    next();
                    যদি (s1->pack_স্তূপ_ptr >= s1->pack_স্তূপ + PACK_স্তূপ_SIZE - 1)
                        গচ্ছ stk_error;
                    val = *s1->pack_স্তূপ_ptr++;
                    যদি (tok != ',')
                        গচ্ছ pack_set;
                    next();
                }
                যদি (tok != TOK_CINT)
                    গচ্ছ pragma_err;
                val = tokc.i;
                যদি (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    গচ্ছ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_স্তূপ_ptr = val;
        }
        যদি (tok != ')')
            গচ্ছ pragma_err;

    } অন্যথা যদি (tok == TOK_comment) {
        ৱর্ণ *p; পূর্ণাঙ্ক t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        যদি (tok != TOK_STR)
            গচ্ছ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        যদি (tok != ')')
            গচ্ছ pragma_err;
        যদি (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } অন্যথা {
            যদি (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } অন্যথা {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ঘূৰাই 0;
    }
    next();
    ঘূৰাই 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC শূন্য tccpp_putfile(ধ্রুৱ ৱর্ণ *filename)
{
    ৱর্ণ buf[1024];
    buf[0] = 0;
    যদি (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, পরিমাণ buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, পরিমাণ buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    যদি (0 == strcmp(file->filename, buf))
        ঘূৰাই;
    //printf("new file '%s'\n", buf);
    যদি (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, পরিমাণ file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC শূন্য preprocess(পূর্ণাঙ্ক is_bof)
{
    TCCState *s1 = tcc_state;
    পূর্ণাঙ্ক c, n, saved_parse_flags;
    ৱর্ণ buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_অঙ্ক
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    ৱিকল্প(tok) {
    পক্ষ TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ভঙ্গ;
    পক্ষ TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        যদি (s)
            define_undef(s);
        next_nomacro();
        ভঙ্গ;
    পক্ষ TOK_INCLUDE:
    পক্ষ TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        গচ্ছ the_end;
    পক্ষ TOK_IFNDEF:
        c = 1;
        গচ্ছ do_ifdef;
    পক্ষ TOK_IF:
        c = ৰাশিমালা_preprocess(s1);
        গচ্ছ do_if;
    পক্ষ TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        যদি (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        যদি (is_bof) {
            যদি (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, রিক্ত));
#endif
                file->ifndef_macro = tok;
            }
        }
        যদি (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        যদি (s1->ifdef_স্তূপ_ptr >= s1->ifdef_স্তূপ + IFDEF_স্তূপ_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_স্তূপ_ptr++ = c;
        গচ্ছ test_skip;
    পক্ষ TOK_ELSE:
        next_nomacro();
        যদি (s1->ifdef_স্তূপ_ptr == s1->ifdef_স্তূপ)
            tcc_error("#else without matching #if");
        যদি (s1->ifdef_স্তূপ_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_স্তূপ_ptr[-1] ^= 3);
        গচ্ছ test_else;
    পক্ষ TOK_ELIF:
        যদি (s1->ifdef_স্তূপ_ptr == s1->ifdef_স্তূপ)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_স্তূপ_ptr[-1];
        যদি (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        যদি (c == 1) {
            skip_to_eol(0);
            c = 0;
        } অন্যথা {
            c = ৰাশিমালা_preprocess(s1);
            s1->ifdef_স্তূপ_ptr[-1] = c;
        }
    test_else:
        যদি (s1->ifdef_স্তূপ_ptr == file->ifdef_স্তূপ_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        যদি (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            গচ্ছ redo;
        }
        ভঙ্গ;
    পক্ষ TOK_ENDIF:
        next_nomacro();
        যদি (s1->ifdef_স্তূপ_ptr <= file->ifdef_স্তূপ_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_স্তূপ_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        যদি (file->ifndef_macro &&
            s1->ifdef_স্তূপ_ptr == file->ifdef_স্তূপ_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ভঙ্গ;

    পক্ষ TOK_সাৰি:
        parse_flags &= ~PARSE_FLAG_TOK_অঙ্ক;
        next();
        যদি (tok != TOK_PPNUM) {
    সাৰি_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        গচ্ছ সাৰি_অঙ্ক_2;
    পক্ষ TOK_PPNUM:
        যদি (parse_flags & PARSE_FLAG_ASM_FILE)
            গচ্ছ ignore;
        c = 0; /* no error with extra tokens */
    সাৰি_অঙ্ক_2:
        বাবে (n = 0, q = tokc.str.data; *q; ++q) {
            যদি (!isnum(*q))
                গচ্ছ সাৰি_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        যদি (tok != TOK_LINEFEED) {
            যদি (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                গচ্ছ সাৰি_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        যদি (file->fd > 0)
            total_সাৰিগুলি += file->সাৰি_অঙ্ক - n;
        file->সাৰি_অঙ্ক = n;
        ভঙ্গ;

    পক্ষ TOK_ERROR:
    পক্ষ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        যেতিয়ালৈ (c != '\n' && c != CH_EOF) {
            যদি ((q - buf) < পরিমাণ(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        যদি (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        অন্যথা
            tcc_warning("#warning %s", buf);
        next_nomacro();
        ভঙ্গ;
    }
    পক্ষ TOK_PRAGMA:
        যদি (!pragma_parse(s1))
            গচ্ছ ignore;
        ভঙ্গ;
    পক্ষ TOK_LINEFEED:
        গচ্ছ the_end;
    স্ৱভাৱ:
        /* ignore gas line comment in an 'S' file. */
        যদি (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            গচ্ছ ignore;
        যদি (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            গচ্ছ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        গচ্ছ the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
স্থির শূন্য parse_escape_string(CString *outstr, ধ্রুৱ uint8_t *buf, পূর্ণাঙ্ক is_long)
{
    পূর্ণাঙ্ক c, n, i;
    ধ্রুৱ uint8_t *p;

    p = buf;
    বাবে(;;) {
        c = *p;
        যদি (c == '\0')
            ভঙ্গ;
        যদি (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ৱিকল্প(c) {
            পক্ষ '0': পক্ষ '1': পক্ষ '2': পক্ষ '3':
            পক্ষ '4': পক্ষ '5': পক্ষ '6': পক্ষ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                যদি (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    যদি (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                গচ্ছ add_char_nonext;
            পক্ষ 'x': i = 0; গচ্ছ parse_hex_or_ucn;
            পক্ষ 'u': i = 4; গচ্ছ parse_hex_or_ucn;
            পক্ষ 'U': i = 8; গচ্ছ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                কৰা {
                    c = *p;
                    যদি (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    অন্যথা যদি (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    অন্যথা যদি (isnum(c))
                        c = c - '0';
                    অন্যথা যদি (i >= 0)
                        expect("more hex digits in universal-character-name");
                    অন্যথা
                        গচ্ছ add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } যেতিয়ালৈ (--i);
		যদি (is_long) {
    add_hex_or_ucn:
                    c = n;
		    গচ্ছ add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                অনুৱর্ত;
            পক্ষ 'a':
                c = '\a';
                ভঙ্গ;
            পক্ষ 'b':
                c = '\b';
                ভঙ্গ;
            পক্ষ 'f':
                c = '\f';
                ভঙ্গ;
            পক্ষ 'n':
                c = '\n';
                ভঙ্গ;
            পক্ষ 'r':
                c = '\r';
                ভঙ্গ;
            পক্ষ 't':
                c = '\t';
                ভঙ্গ;
            পক্ষ 'v':
                c = '\v';
                ভঙ্গ;
            পক্ষ 'e':
                যদি (!gnu_ext)
                    গচ্ছ invalid_escape;
                c = 27;
                ভঙ্গ;
            পক্ষ '\'':
            পক্ষ '\"':
            পক্ষ '\\': 
            পক্ষ '?':
                ভঙ্গ;
            স্ৱভাৱ:
            invalid_escape:
                যদি (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                অন্যথা
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ভঙ্গ;
            }
        } অন্যথা যদি (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            পূর্ণাঙ্ক cont; /* count of continuation bytes */
            পূর্ণাঙ্ক skip; /* how many bytes should skip when error occurred */
            পূর্ণাঙ্ক i;

            /* decode leading byte */
            যদি (c < 0xC2) {
	            skip = 1; গচ্ছ invalid_utf8_sequence;
            } অন্যথা যদি (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } অন্যথা যদি (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } অন্যথা যদি (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } অন্যথা {
	            skip = 1; গচ্ছ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            বাবে (i = 1; i <= cont; i++) {
                পূর্ণাঙ্ক l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                যদি (i == 1) {
                    ৱিকল্প (c) {
                    পক্ষ 0xE0: l = 0xA0; ভঙ্গ;
                    পক্ষ 0xED: h = 0x9F; ভঙ্গ;
                    পক্ষ 0xF0: l = 0x90; ভঙ্গ;
                    পক্ষ 0xF4: h = 0x8F; ভঙ্গ;
                    }
                }

                যদি (p[i] < l || p[i] > h) {
                    skip = i; গচ্ছ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            গচ্ছ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            গচ্ছ add_char_nonext;

        }
        p++;
    add_char_nonext:
        যদি (!is_long)
            cstr_ccat(outstr, c);
        অন্যথা {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            যদি (c < 0x10000) {
                cstr_wccat(outstr, c);
            } অন্যথা {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#অন্যথা
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    যদি (!is_long)
        cstr_ccat(outstr, '\0');
    অন্যথা
        cstr_wccat(outstr, '\0');
}

স্থির শূন্য parse_string(ধ্রুৱ ৱর্ণ *s, পূর্ণাঙ্ক len)
{
    uint8_t buf[1000], *p = buf;
    পূর্ণাঙ্ক is_long, sep;

    যদি ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    যদি (len >= পরিমাণ buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    যদি (p != buf)
        tcc_free(p);

    যদি (sep == '\'') {
        পূর্ণাঙ্ক char_size, i, n, c;
        /* XXX: make it portable */
        যদি (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        অন্যথা
            tok = TOK_LCHAR, char_size = পরিমাণ(nwchar_t);
        n = tokcstr.size / char_size - 1;
        যদি (n < 1)
            tcc_error("empty character constant");
        যদি (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        বাবে (c = i = 0; i < n; ++i) {
            যদি (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            অন্যথা
                c = (c << 8) | ((ৱর্ণ *)tokcstr.data)[i];
        }
        tokc.i = c;
    } অন্যথা {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        যদি (!is_long)
            tok = TOK_STR;
        অন্যথা
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
স্থির পূর্ণাঙ্ক bn_lshift(unsigned পূর্ণাঙ্ক *bn, পূর্ণাঙ্ক shift, পূর্ণাঙ্ক or_val)
{
    পূর্ণাঙ্ক i;
    unsigned পূর্ণাঙ্ক v;
    যদি (bn[BN_SIZE - 1] >> (32 - shift))
	ঘূৰাই shift;
    বাবে(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ঘূৰাই 0;
}

স্থির শূন্য bn_zero(unsigned পূর্ণাঙ্ক *bn)
{
    পূর্ণাঙ্ক i;
    বাবে(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
স্থির শূন্য parse_সংখ্যা(ধ্রুৱ ৱর্ণ *p)
{
    পূর্ণাঙ্ক b, t, shift, frac_bits, s, exp_val, ch;
    ৱর্ণ *q;
    unsigned পূর্ণাঙ্ক bn[BN_SIZE];
    long দ্ৱিগুণ d;

    /*সংখ্যা*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    যদি (t == '.') {
        গচ্ছ float_frac_parse;
    } অন্যথা যদি (t == '0') {
        যদি (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } অন্যথা যদি (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    যেতিয়ালৈ (1) {
        যদি (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        অন্যথা যদি (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        অন্যথা যদি (isnum(ch))
            t = ch - '0';
        অন্যথা
            ভঙ্গ;
        যদি (t >= b)
            ভঙ্গ;
        যদি (q >= token_buf + STRING_MAX_SIZE) {
        অঙ্ক_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    যদি (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        যদি (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            যদি (b == 16)
                shift = 4;
            অন্যথা 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            যেতিয়ালৈ (1) {
                t = *q++;
                যদি (t == '\0') {
                    ভঙ্গ;
                } অন্যথা যদি (t >= 'a') {
                    t = t - 'a' + 10;
                } অন্যথা যদি (t >= 'A') {
                    t = t - 'A' + 10;
                } অন্যথা {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            যদি (ch == '.') {
                ch = *p++;
                যেতিয়ালৈ (1) {
                    t = ch;
                    যদি (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } অন্যথা যদি (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } অন্যথা যদি (t >= '0' && t <= '9') {
                        t = t - '0';
                    } অন্যথা {
                        ভঙ্গ;
                    }
                    যদি (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            যদি (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            যদি (ch == '+') {
                ch = *p++;
            } অন্যথা যদি (ch == '-') {
                s = -1;
                ch = *p++;
            }
            যদি (ch < '0' || ch > '9')
                expect("exponent digits");
            যেতিয়ালৈ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		যদি (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long দ্ৱিগুণ)bn[3] * 79228162514264337593543950336.0L +
	        (long দ্ৱিগুণ)bn[2] * 18446744073709551616.0L +
	        (long দ্ৱিগুণ)bn[1] * 4294967296.0L +
	        (long দ্ৱিগুণ)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            যদি (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ভিন্ন)d;
            } অন্যথা যদি (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } অন্যথা {
                tok = TOK_CDOUBLE;
                tokc.d = (দ্ৱিগুণ)d;
            }
        } অন্যথা {
            /* decimal floats */
            যদি (ch == '.') {
                যদি (q >= token_buf + STRING_MAX_SIZE)
                    গচ্ছ অঙ্ক_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                যেতিয়ালৈ (ch >= '0' && ch <= '9') {
                    যদি (q >= token_buf + STRING_MAX_SIZE)
                        গচ্ছ অঙ্ক_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            যদি (ch == 'e' || ch == 'E') {
                যদি (q >= token_buf + STRING_MAX_SIZE)
                    গচ্ছ অঙ্ক_too_long;
                *q++ = ch;
                ch = *p++;
                যদি (ch == '-' || ch == '+') {
                    যদি (q >= token_buf + STRING_MAX_SIZE)
                        গচ্ছ অঙ্ক_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                যদি (ch < '0' || ch > '9')
                    expect("exponent digits");
                যেতিয়ালৈ (ch >= '0' && ch <= '9') {
                    যদি (q >= token_buf + STRING_MAX_SIZE)
                        গচ্ছ অঙ্ক_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            যদি (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, রিক্ত);
            } অন্যথা যদি (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, রিক্ত);
            } অন্যথা {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, রিক্ত);
            }
        }
    } অন্যথা {
        unsigned long long n, n1;
        পূর্ণাঙ্ক lcount, ucount, ov = 0;
        ধ্রুৱ ৱর্ণ *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        যদি (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        যেতিয়ালৈ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            যদি (t == '\0')
                ভঙ্গ;
            অন্যথা যদি (t >= 'a')
                t = t - 'a' + 10;
            অন্যথা যদি (t >= 'A')
                t = t - 'A' + 10;
            অন্যথা
                t = t - '0';
            যদি (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            যদি (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        বাবে(;;) {
            t = toup(ch);
            যদি (t == 'L') {
                যদি (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                যদি (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } অন্যথা যদি (t == 'U') {
                যদি (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } অন্যথা {
                ভঙ্গ;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        যদি (pp_ৰাশিমালা)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        যদি (ucount == 0 && b == 10) {
            যদি (lcount <= (LONG_SIZE == 4)) {
                যদি (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            যদি (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } অন্যথা {
            যদি (lcount <= (LONG_SIZE == 4)) {
                যদি (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                অন্যথা যদি (n >= 0x80000000U)
                    ucount = 1;
            }
            যদি (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        যদি (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	যদি (lcount) {
            tok = TOK_CLONG;
            যদি (lcount == 2)
                tok = TOK_CLLONG;
	}
	যদি (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    যদি (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    পক্ষ c1:                                    \
        PEEKC(c, p);                            \
        যদি (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } অন্যথা {                                \
            tok = tok1;                         \
        }                                       \
        ভঙ্গ;

/* return next token without macro substitution */
স্থির শূন্য next_nomacro(শূন্য)
{
    পূর্ণাঙ্ক t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned পূর্ণাঙ্ক h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    ৱিকল্প(c) {
    পক্ষ ' ':
    পক্ষ '\t':
        tok = c;
        p++;
 maybe_space:
        যদি (parse_flags & PARSE_FLAG_SPACES)
            গচ্ছ keep_tok_flags;
        যেতিয়ালৈ (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        গচ্ছ redo_no_start;
    পক্ষ '\f':
    পক্ষ '\v':
    পক্ষ '\r':
        p++;
        গচ্ছ redo_no_start;
    পক্ষ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        যদি (c == '\\')
            গচ্ছ parse_simple;
        যদি (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            যদি (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                গচ্ছ maybe_newline;
            } অন্যথা যদি (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } অন্যথা যদি (s1->ifdef_স্তূপ_ptr != file->ifdef_স্তূপ_ptr) {
                tcc_error("missing #endif");
            } অন্যথা যদি (s1->include_স্তূপ_ptr == s1->include_স্তূপ) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } অন্যথা {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                যদি (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, রিক্ত));
#endif
                    অনুসন্ধান_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_স্তূপ_ptr--;
                p = file->buf_ptr;
                গচ্ছ maybe_newline;
            }
        } অন্যথা {
            গচ্ছ redo_no_start;
        }
        ভঙ্গ;

    পক্ষ '\n':
        file->সাৰি_অঙ্ক++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        যদি (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            গচ্ছ redo_no_start;
        tok = TOK_LINEFEED;
        গচ্ছ keep_tok_flags;

    পক্ষ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        যদি ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            গচ্ছ maybe_newline;
        } অন্যথা {
            যদি (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } অন্যথা {
#যদি !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                যদি (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_সাৰি_comment(p - 1);
                    গচ্ছ redo_no_start;
                } অন্যথা
#endif
                {
                    tok = '#';
                }
            }
        }
        ভঙ্গ;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    পক্ষ '$':
        যদি (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            গচ্ছ parse_simple;

    পক্ষ 'a': পক্ষ 'b': পক্ষ 'c': পক্ষ 'd':
    পক্ষ 'e': পক্ষ 'f': পক্ষ 'g': পক্ষ 'h':
    পক্ষ 'i': পক্ষ 'j': পক্ষ 'k': পক্ষ 'l':
    পক্ষ 'm': পক্ষ 'n': পক্ষ 'o': পক্ষ 'p':
    পক্ষ 'q': পক্ষ 'r': পক্ষ 's': পক্ষ 't':
    পক্ষ 'u': পক্ষ 'v': পক্ষ 'w': পক্ষ 'x':
    পক্ষ 'y': পক্ষ 'z': 
    পক্ষ 'A': পক্ষ 'B': পক্ষ 'C': পক্ষ 'D':
    পক্ষ 'E': পক্ষ 'F': পক্ষ 'G': পক্ষ 'H':
    পক্ষ 'I': পক্ষ 'J': পক্ষ 'K': 
    পক্ষ 'M': পক্ষ 'N': পক্ষ 'O': পক্ষ 'P':
    পক্ষ 'Q': পক্ষ 'R': পক্ষ 'S': পক্ষ 'T':
    পক্ষ 'U': পক্ষ 'V': পক্ষ 'W': পক্ষ 'X':
    পক্ষ 'Y': পক্ষ 'Z': 
    পক্ষ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        যেতিয়ালৈ (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        যদি (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            বাবে(;;) {
                ts = *pts;
                যদি (!ts)
                    ভঙ্গ;
                যদি (ts->len == len && !memcmp(ts->str, p1, len))
                    গচ্ছ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (ৱর্ণ *) p1, len);
        token_found: ;
        } অন্যথা {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (ৱর্ণ *) p1, len);
            p--;
            PEEKC(c, p);
            যেতিয়ালৈ (isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        ভঙ্গ;
    পক্ষ 'L':
        t = p[1];
        যদি (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            যদি (c == '\'' || c == '\"') {
                is_long = 1;
                গচ্ছ str_const;
            }
            *--p = c = 'L';
        }
        গচ্ছ parse_ident_fast;

    পক্ষ '0': পক্ষ '1': পক্ষ '2': পক্ষ '3':
    পক্ষ '4': পক্ষ '5': পক্ষ '6': পক্ষ '7':
    পক্ষ '8': পক্ষ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_অঙ্ক:
        cstr_reset(&tokcstr);
        বাবে(;;) {
            cstr_ccat(&tokcstr, t);
            যদি (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((ৱর্ণ*)tokcstr.data)[0] == '0'
                                && toup(((ৱর্ণ*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ভঙ্গ;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        ভঙ্গ;

    পক্ষ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        যদি (isnum(c)) {
            t = '.';
            গচ্ছ parse_অঙ্ক;
        } অন্যথা যদি ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))) {
            *--p = c = '.';
            গচ্ছ parse_ident_fast;
        } অন্যথা যদি (c == '.') {
            PEEKC(c, p);
            যদি (c == '.') {
                p++;
                tok = TOK_DOTS;
            } অন্যথা {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } অন্যথা {
            tok = '.';
        }
        ভঙ্গ;
    পক্ষ '\'':
    পক্ষ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        যদি (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        ভঙ্গ;

    পক্ষ '<':
        PEEKC(c, p);
        যদি (c == '=') {
            p++;
            tok = TOK_LE;
        } অন্যথা যদি (c == '<') {
            PEEKC(c, p);
            যদি (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } অন্যথা {
                tok = TOK_SHL;
            }
        } অন্যথা {
            tok = TOK_LT;
        }
        ভঙ্গ;
    পক্ষ '>':
        PEEKC(c, p);
        যদি (c == '=') {
            p++;
            tok = TOK_GE;
        } অন্যথা যদি (c == '>') {
            PEEKC(c, p);
            যদি (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } অন্যথা {
                tok = TOK_SAR;
            }
        } অন্যথা {
            tok = TOK_GT;
        }
        ভঙ্গ;
        
    পক্ষ '&':
        PEEKC(c, p);
        যদি (c == '&') {
            p++;
            tok = TOK_LAND;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_AND;
        } অন্যথা {
            tok = '&';
        }
        ভঙ্গ;
        
    পক্ষ '|':
        PEEKC(c, p);
        যদি (c == '|') {
            p++;
            tok = TOK_LOR;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_OR;
        } অন্যথা {
            tok = '|';
        }
        ভঙ্গ;

    পক্ষ '+':
        PEEKC(c, p);
        যদি (c == '+') {
            p++;
            tok = TOK_INC;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } অন্যথা {
            tok = '+';
        }
        ভঙ্গ;
        
    পক্ষ '-':
        PEEKC(c, p);
        যদি (c == '-') {
            p++;
            tok = TOK_DEC;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } অন্যথা যদি (c == '>') {
            p++;
            tok = TOK_ARROW;
        } অন্যথা {
            tok = '-';
        }
        ভঙ্গ;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    পক্ষ '/':
        PEEKC(c, p);
        যদি (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            গচ্ছ maybe_space;
        } অন্যথা যদি (c == '/') {
            p = parse_সাৰি_comment(p);
            tok = ' ';
            গচ্ছ maybe_space;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } অন্যথা {
            tok = '/';
        }
        ভঙ্গ;
        
        /* simple tokens */
    পক্ষ '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        যদি (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_সাৰি_comment(p);
            গচ্ছ redo_no_start;
        }
#endif
    পক্ষ '(':
    পক্ষ ')':
    পক্ষ '[':
    পক্ষ ']':
    পক্ষ '{':
    পক্ষ '}':
    পক্ষ ',':
    পক্ষ ';':
    পক্ষ ':':
    পক্ষ '?':
    পক্ষ '~':
    parse_simple:
        tok = c;
        p++;
        ভঙ্গ;
    পক্ষ 0xEF: /* UTF8 BOM ? */
        যদি (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            গচ্ছ redo_no_start;
        }
    স্ৱভাৱ:
        যদি (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    গচ্ছ parse_ident_fast;
        যদি (parse_flags & PARSE_FLAG_ASM_FILE)
            গচ্ছ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ভঙ্গ;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#যদি defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
স্থির পূর্ণাঙ্ক indent;
স্থির শূন্য define_print(TCCState *s1, পূর্ণাঙ্ক v);
স্থির শূন্য pp_print(ধ্রুৱ ৱর্ণ *বাৰ্তা, পূর্ণাঙ্ক v, ধ্রুৱ পূর্ণাঙ্ক *str)
{
    FILE *fp = tcc_state->ppfp;

    যদি (বাৰ্তা[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    অন্যথা যদি (বাৰ্তা[0] == '+')
         ++indent, ++বাৰ্তা;
    অন্যথা যদি (বাৰ্তা[0] == '-')
        --indent, ++বাৰ্তা;

    fprintf(fp, "%*s", indent, "");
    যদি (বাৰ্তা[0] == '#') {
        define_print(tcc_state, v);
    } অন্যথা {
        tok_print(str, v ? "%s %s" : "%s", বাৰ্তা, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#অন্যথা
#define PP_PRINT(x)
#endif

স্থির পূর্ণাঙ্ক macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ধ্রুৱ পূর্ণাঙ্ক *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
স্থির পূর্ণাঙ্ক *macro_arg_subst(Sym **nested_list, ধ্রুৱ পূর্ণাঙ্ক *macro_str, Sym *args)
{
    পূর্ণাঙ্ক t, t0, t1, t2, n;
    ধ্রুৱ পূর্ণাঙ্ক *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    বাবে (s = args, n = 0; s; s = s->prev, ++n);
    যেতিয়ালৈ (n--) {
        বাবে (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    যেতিয়ালৈ(1) {
        TOK_GET(&t, &macro_str, &cval);
        যদি (!t)
            ভঙ্গ;
        যদি (t == '#') {
            /* stringize */
            কৰা t = *macro_str++; যেতিয়ালৈ (t == ' ');
            s = sym_find2(args, t);
            যদি (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                যেতিয়ালৈ (*st != TOK_EOF) {
                    ধ্রুৱ ৱর্ণ *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    যেতিয়ালৈ (*s) {
                        যদি (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        অন্যথা
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
            } অন্যথা যদি ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } অন্যথা {
                expect("macro parameter after '#'");
            }
        } অন্যথা যদি (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            যদি (s) {
                st = s->d;
                n = 0;
                যেতিয়ালৈ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                যদি (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    যদি (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        পূর্ণাঙ্ক c = str.str[str.len - 1];
                        যেতিয়ালৈ (str.str[--str.len] != ',')
                            ;
                        যদি (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } অন্যথা {
                            /* suppress '##' and add variable */
                            str.len++;
                            যদি (c == ' ')
                                str.str[str.len++] = c;
                            গচ্ছ add_var;
                        }
                    } অন্যথা {
                        যদি (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } অন্যথা {
            add_var:
		    যদি (!s->e) {
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
                যেতিয়ালৈ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } অন্যথা {
                tok_str_add(&str, t);
            }
        } অন্যথা {
            tok_str_add2(&str, t, &cval);
        }
        যদি (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ঘূৰাই str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
স্থির অন্তঃস্থ পূর্ণাঙ্ক *macro_twosharps(ধ্রুৱ পূর্ণাঙ্ক *ptr0)
{
    পূর্ণাঙ্ক t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ধ্রুৱ পূর্ণাঙ্ক *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    বাবে (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        যদি (t1 == 0)
            ভঙ্গ;
        বাবে (;;) {
            n = 0;
            যেতিয়ালৈ ((t2 = ptr[n]) == ' ')
                ++n;
            যদি (t2 != TOK_PPJOIN)
                ভঙ্গ;
            ptr += n;
            যেতিয়ালৈ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            যদি (t2 == TOK_PLCHLDR)
                অনুৱর্ত;
            যদি (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        যদি (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            বাবে (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                যদি (*file->buf_ptr == 0)
                    ভঙ্গ;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        যদি (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ঘূৰাই macro_str1.str;
}

স্থির পূর্ণাঙ্ক peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    পূর্ণাঙ্ক c;
    বাবে (;;) {
        PEEKC(c, p);
        ৱিকল্প (c) {
        পক্ষ '/':
            PEEKC(c, p);
            যদি (c == '*')
                p = parse_comment(p);
            অন্যথা যদি (c == '/')
                p = parse_সাৰি_comment(p);
            অন্যথা {
                c = *--p = '/';
                গচ্ছ leave;
            }
            --p, c = ' ';
            ভঙ্গ;
        পক্ষ ' ': পক্ষ '\t':
            ভঙ্গ;
        পক্ষ '\f': পক্ষ '\v': পক্ষ '\r':
            অনুৱর্ত;
        পক্ষ '\n':
            file->সাৰি_অঙ্ক++, tok_flags |= TOK_FLAG_BOL;
            ভঙ্গ;
        স্ৱভাৱ: leave:
            file->buf_ptr = p;
            ঘূৰাই c;
        }
        যদি (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
স্থির পূর্ণাঙ্ক next_argstream(Sym **nested_list, TokenString *ws_str)
{
    পূর্ণাঙ্ক t;
    Sym *sa;

    যেতিয়ালৈ (macro_ptr) {
        ধ্রুৱ পূর্ণাঙ্ক *m = macro_ptr;
        যেতিয়ালৈ ((t = *m) != 0) {
            যদি (ws_str) {
                যদি (t != ' ')
                    ঘূৰাই t;
                ++m;
            } অন্যথা {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ঘূৰাই tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        যদি (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    যদি (ws_str) {
        ঘূৰাই peek_file(ws_str);
    } অন্যথা {
        next_nomacro();
        যদি (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ঘূৰাই tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
স্থির পূর্ণাঙ্ক macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    পূর্ণাঙ্ক t;
    পূর্ণাঙ্ক v = s->v;

    PP_PRINT(("#", v, s->d));
    যদি (s->d) {
        পূর্ণাঙ্ক *mstr = s->d;
        পূর্ণাঙ্ক *jstr;
        Sym *sa;
        পূর্ণাঙ্ক ret;

        যদি (s->type.t & MACRO_FUNC) {
            পূর্ণাঙ্ক saved_parse_flags = parse_flags;
            TokenString str;
            পূর্ণাঙ্ক parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            যদি (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                যদি (parse_flags & PARSE_FLAG_SPACES)
                    বাবে (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ঘূৰাই 0;
            } অন্যথা {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = রিক্ত;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            বাবে(;;) {
                কৰা {
                    t = next_argstream(nested_list, রিক্ত);
                } যেতিয়ালৈ (t == ' ' || --i);

                যদি (!sa) {
                    যদি (t == ')') /* handle '()' case */
                        ভঙ্গ;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                যেতিয়ালৈ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    যদি (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    যদি (t == '(')
                        parlevel++;
                    যদি (t == ')')
                        parlevel--;
                    যদি (t == ' ')
                        str.need_spc |= 1;
                    অন্যথা
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, রিক্ত);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                যদি (t == ')') {
                    যদি (!sa)
                        ভঙ্গ;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    যদি (sa->type.t && gnu_ext)
                        গচ্ছ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            যেতিয়ালৈ (sa) {
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
        যদি (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        যদি (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        যদি (jstr != mstr)
            tok_str_free_str(jstr);
        যদি (mstr != s->d)
            tok_str_free_str(mstr);
        ঘূৰাই ret;

    } অন্যথা {
        CValue cval;
        ৱর্ণ buf[32], *cstrval = buf;

        /* special macros */
        যদি (v == TOK_সাৰি_2 || v == TOK___COUNTER__) {
            t = v == TOK_সাৰি_2 ? file->সাৰি_অঙ্ক : pp_counter++;
            snprintf(buf, পরিমাণ(buf), "%d", t);
            t = TOK_PPNUM;
            গচ্ছ add_cstr1;

        } অন্যথা যদি (v == TOK___FILE__) {
            cstrval = file->filename;
            গচ্ছ add_cstr;

        } অন্যথা যদি (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            সংরচনা tm *tm;
            time(&ti);
            tm = localtime(&ti);
            যদি (v == TOK___DATE__) {
                স্থির ৱর্ণ ধ্রুৱ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, পরিমাণ(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } অন্যথা {
                snprintf(buf, পরিমাণ(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ঘূৰাই 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
স্থির পূর্ণাঙ্ক macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ধ্রুৱ পূর্ণাঙ্ক *macro_str
    )
{
    Sym *s;
    পূর্ণাঙ্ক t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    পূর্ণাঙ্ক tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    যেতিয়ালৈ (1) {
        TOK_GET(&t, &macro_str, &cval);
        যদি (t == 0 || t == TOK_EOF)
            ভঙ্গ;
        যদি (t >= TOK_IDENT) {
            s = define_find(t);
            যদি (s == রিক্ত || nosubst)
                গচ্ছ no_subst;
            /* if nested substitution, do nothing */
            যদি (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                গচ্ছ no_subst;
            }
            str = tok_str_alloc();
            str->str = (পূর্ণাঙ্ক*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            যদি (macro_স্তূপ != str) {
                /* already finished by reading function macro arguments */
                ভঙ্গ;
            }
            macro_str = macro_ptr;
            end_macro ();
        } অন্যথা যদি (t == ' ') {
            যদি (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } অন্যথা {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            যদি (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            যদি (t == TOK_DEFINED && pp_ৰাশিমালা)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ঘূৰাই nosubst;
}

/* return next token with macro substitution */
ST_FUNC শূন্য next(শূন্য)
{
    পূর্ণাঙ্ক t;
    যেতিয়ালৈ (macro_ptr) {
redo:
        t = *macro_ptr;
        যদি (TOK_HAS_মান(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            যদি (t == TOK_LINENUM) {
                file->সাৰি_অঙ্ক = tokc.i;
                গচ্ছ redo;
            }
            গচ্ছ convert;
        } অন্যথা যদি (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            অনুৱর্ত;
        } অন্যথা যদি (t == TOK_EOF) {
            /* do nothing */
        } অন্যথা {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            যদি (t == '\\') {
                যদি (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ঘূৰাই;
    }

    next_nomacro();
    t = tok;
    যদি (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        যদি (s) {
            Sym *nested_list = রিক্ত;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            গচ্ছ redo;
        }
        ঘূৰাই;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    যদি (t == TOK_PPNUM) {
        যদি  (parse_flags & PARSE_FLAG_TOK_অঙ্ক)
            parse_সংখ্যা(tokc.str.data);
    } অন্যথা যদি (t == TOK_PPSTR) {
        যদি (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN শূন্য unget_tok(পূর্ণাঙ্ক last_tok)
{
    TokenString *str = &unget_buf;
    পূর্ণাঙ্ক alloc = 0;
    যদি (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    যদি (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

স্থির ধ্রুৱ ৱর্ণ * ধ্রুৱ target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# যদি PTR_SIZE == 8
    "_WIN64\0"
# endif
#অন্যথা
# যদি defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# অন্যথা
    "__linux__\0"
    "__linux\0"
#  যদি TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

স্থির শূন্য putdef(CString *cs, ধ্রুৱ ৱর্ণ *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

স্থির শূন্য putdefs(CString *cs, ধ্রুৱ ৱর্ণ *p)
{
    যেতিয়ালৈ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

স্থির শূন্য tcc_predefs(TCCState *s1, CString *cs, পূর্ণাঙ্ক is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    যদি (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    যদি (is_asm)
      putdef(cs, "__ASSEMBLER__");
    যদি (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    যদি (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    যদি (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    যদি (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    যদি (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    যদি (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    যদি (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    যদি (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#যদি CONFIG_TCC_PREDEFS
        #অন্তর্ভাৱ "tccdefs_.h" /* include as strings */
#অন্যথা
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC শূন্য preprocess_start(TCCState *s1, পূর্ণাঙ্ক filetype)
{
    পূর্ণাঙ্ক is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_স্তূপ_ptr = s1->include_স্তূপ;
    s1->ifdef_স্তূপ_ptr = s1->ifdef_স্তূপ;
    file->ifdef_স্তূপ_ptr = s1->ifdef_স্তূপ_ptr;
    pp_ৰাশিমালা = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_স্তূপ[0] = 0;
    s1->pack_স্তূপ_ptr = s1->pack_স্তূপ;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    যদি (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        যদি (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        যদি (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_স্তূপ_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC শূন্য preprocess_end(TCCState *s1)
{
    যেতিয়ালৈ (macro_স্তূপ)
        end_macro();
    macro_ptr = রিক্ত;
    যেতিয়ালৈ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC পূর্ণাঙ্ক set_idnum(পূর্ণাঙ্ক c, পূর্ণাঙ্ক val)
{
    পূর্ণাঙ্ক prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ঘূৰাই prev;
}

ST_FUNC শূন্য tccpp_new(TCCState *s)
{
    পূর্ণাঙ্ক i, c;
    ধ্রুৱ ৱর্ণ *p, *r;

    /* init isid table */
    বাবে(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_অঙ্ক
            : 0);

    বাবে(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * পরিমাণ(TokenSym *));
    memset(s->cached_includes_hash, 0, পরিমাণ s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    যেতিয়ালৈ (*p) {
        r = p;
        বাবে(;;) {
            c = *r++;
            যদি (c == '\0')
                ভঙ্গ;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ঠেলো(TOK_সাৰি_2, MACRO_OBJ, রিক্ত, রিক্ত);
    define_ঠেলো(TOK___FILE__, MACRO_OBJ, রিক্ত, রিক্ত);
    define_ঠেলো(TOK___DATE__, MACRO_OBJ, রিক্ত, রিক্ত);
    define_ঠেলো(TOK___TIME__, MACRO_OBJ, রিক্ত, রিক্ত);
    define_ঠেলো(TOK___COUNTER__, MACRO_OBJ, রিক্ত, রিক্ত);
}

ST_FUNC শূন্য tccpp_delete(TCCState *s)
{
    পূর্ণাঙ্ক i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    যদি (n > total_idents)
        total_idents = n;
    বাবে (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = রিক্ত;

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

স্থির পূর্ণাঙ্ক pp_need_space(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b);

স্থির শূন্য tok_print(ধ্রুৱ পূর্ণাঙ্ক *str, ধ্রুৱ ৱর্ণ *বাৰ্তা, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    পূর্ণাঙ্ক t, t0, s;
    CValue cval;

    va_start(ap, বাৰ্তা);
    vfprintf(fp, বাৰ্তা, ap);
    va_end(ap);

    s = t0 = 0;
    যেতিয়ালৈ (str) {
	TOK_GET(&t, &str, &cval);
	যদি (t == 0 || t == TOK_EOF)
	    ভঙ্গ;
        যদি (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

স্থির শূন্য pp_সাৰি(TCCState *s1, BufferedFile *f, পূর্ণাঙ্ক level)
{
    পূর্ণাঙ্ক d = f->সাৰি_অঙ্ক - f->সাৰি_ref;

    যদি (s1->dflag & 4)
	ঘূৰাই;

    যদি (s1->Pflag == সাৰি_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } অন্যথা যদি (level == 0 && f->সাৰি_ref && d < 8) {
	যেতিয়ালৈ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } অন্যথা যদি (s1->Pflag == সাৰি_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->সাৰি_অঙ্ক, f->filename);
    } অন্যথা {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->সাৰি_অঙ্ক, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->সাৰি_ref = f->সাৰি_অঙ্ক;
}

স্থির শূন্য define_print(TCCState *s1, পূর্ণাঙ্ক v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    যদি (রিক্ত == s || রিক্ত == s->d)
        ঘূৰাই;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, রিক্ত));
    যদি (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        যদি (a)
            বাবে (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, রিক্ত));
                যদি (!(a = a->next))
                    ভঙ্গ;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

স্থির শূন্য pp_debug_defines(TCCState *s1)
{
    পূর্ণাঙ্ক v, t;
    ধ্রুৱ ৱর্ণ *vs;
    FILE *fp;

    t = pp_debug_tok;
    যদি (t == 0)
        ঘূৰাই;

    file->সাৰি_অঙ্ক--;
    pp_সাৰি(s1, file, 0);
    file->সাৰি_ref = ++file->সাৰি_অঙ্ক;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, রিক্ত);
    যদি (t == TOK_DEFINE) {
        define_print(s1, v);
    } অন্যথা যদি (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } অন্যথা যদি (t == TOK_ঠেলো_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } অন্যথা যদি (t == TOK_বেৰ_কৰো_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
স্থির পূর্ণাঙ্ক pp_need_space(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
{
    ঘূৰাই 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
স্থির পূর্ণাঙ্ক pp_check_he0xE(পূর্ণাঙ্ক t, ধ্রুৱ ৱর্ণ *p)
{
    যদি (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ঘূৰাই 'E';
    ঘূৰাই t;
}

/* Preprocess the current file */
ST_FUNC পূর্ণাঙ্ক tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    পূর্ণাঙ্ক token_seen, spcs, level;
    ধ্রুৱ ৱর্ণ *p;
    ৱর্ণ white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    যদি (s1->Pflag == সাৰি_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_অঙ্ক, s1->Pflag = 1;

    যদি (s1->do_bench) {
	/* for PP benchmarks */
	কৰা next(); যেতিয়ালৈ (tok != TOK_EOF);
	ঘূৰাই 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    যদি (file->prev)
        pp_সাৰি(s1, file->prev, level++);
    pp_সাৰি(s1, file, level);

    বাবে (;;) {
        iptr = s1->include_স্তূপ_ptr;
        next();
        যদি (tok == TOK_EOF)
            ভঙ্গ;

        level = s1->include_স্তূপ_ptr - iptr;
        যদি (level) {
            যদি (level > 0)
                pp_সাৰি(s1, *iptr, 0);
            pp_সাৰি(s1, file, level);
        }
        যদি (s1->dflag & 7) {
            pp_debug_defines(s1);
            যদি (s1->dflag & 4)
                অনুৱর্ত;
        }

        যদি (is_space(tok)) {
            যদি (spcs < পরিমাণ white - 1)
                white[spcs++] = tok;
            অনুৱর্ত;
        } অন্যথা যদি (tok == TOK_LINEFEED) {
            spcs = 0;
            যদি (token_seen == TOK_LINEFEED)
                অনুৱর্ত;
            ++file->সাৰি_ref;
        } অন্যথা যদি (token_seen == TOK_LINEFEED) {
            pp_সাৰি(s1, file, 0);
        } অন্যথা যদি (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ঘূৰাই 0;
}

/* ------------------------------------------------------------------------- */
