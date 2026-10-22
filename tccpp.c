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
#অন্তর্ভাব "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_তথ্য পূর্ণসংখ্যা tok_flags;
ST_তথ্য পূর্ণসংখ্যা parse_flags;

ST_তথ্য কাঠামো BufferedFile *file;
ST_তথ্য পূর্ণসংখ্যা tok;
ST_তথ্য CValue tokc;
ST_তথ্য ধ্রুবক পূর্ণসংখ্যা *macro_ptr;
ST_তথ্য CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_তথ্য পূর্ণসংখ্যা tok_ident;
ST_তথ্য TokenSym **table_ident;
ST_তথ্য পূর্ণসংখ্যা pp_রাশিমালা;

/* ------------------------------------------------------------------------- */

স্থির TokenSym *hash_ident[TOK_HASH_আকার];
স্থির অক্ষর token_buf[STRING_MAX_আকার + 1];
স্থির CString cstr_buf;
স্থির TokenString tokstr_buf;
স্থির TokenString unget_buf;
স্থির unsigned অক্ষর isidnum_table[256 - CH_EOF];
স্থির পূর্ণসংখ্যা pp_debug_tok, pp_debug_symv;
স্থির পূর্ণসংখ্যা pp_গণক;
স্থির শূন্য tok_print(ধ্রুবক পূর্ণসংখ্যা *str, ধ্রুবক অক্ষর *বার্তা, ...);
স্থির শূন্য পরবর্তী_nomacro(শূন্য);
স্থির শূন্য parse_সংখ্যা(ধ্রুবক অক্ষর *p);
স্থির শূন্য parse_string(ধ্রুবক অক্ষর *p, পূর্ণসংখ্যা len);

স্থির কাঠামো TinyAlloc *toksym_alloc;
স্থির কাঠামো TinyAlloc *tokstr_alloc;

স্থির TokenString *macro_স্তূপ;

স্থির ধ্রুবক অক্ষর tcc_keywords[] = 
#define DEF(id, str) str "\0"
#অন্তর্ভাব "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
স্থির ধ্রুবক unsigned অক্ষর tok_two_chars[] =
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

ST_FUNC শূন্য skip(পূর্ণসংখ্যা c)
{
    যদি (tok != c) {
        অক্ষর tmp[40];
        pstrcpy(tmp, আকার tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    পরবর্তী();
}

ST_FUNC শূন্য expect(ধ্রুবক অক্ষর *বার্তা)
{
    tcc_error("%s expected", বার্তা);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, আকার_2) tcc_realloc(p, আকার_2)
#define tal_new(a,b)
#define tal_delete(a)
#অন্যথা
#যদি !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, আকার_2) tal_realloc_impl(al, p, আকার_2)
#define TAL_DEBUG_PARAMS
#অন্যথা
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, আকার_2) tal_realloc_impl(al, p, আকার_2, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ধ্রুবক অক্ষর *sfile, পূর্ণসংখ্যা sline
#endif

#define TOKSYM_TAL_আকার (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_আকার (256 * 1024) /* allocator for TokenString instances */

প্রকারলেখ কাঠামো TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    কাঠামো TinyAlloc *পরবর্তী;
    unsigned nb_allocs;
    unsigned আকার_2;
#যদি TAL_INFO
    unsigned nb_peak;
    unsigned nb_যোগ;
    uint8_t *peak_p;
#endif
    সংঘ {
        uint8_t বাফার[1];
        আকার_t _aligner_;
    };
} TinyAlloc;

প্রকারলেখ কাঠামো tal_header_t {
    আকার_t  আকার_2; /* word align */
#যদি TAL_DEBUG
    পূর্ণসংখ্যা     সারি_অঙ্ক; /* negative line_num used for double free check */
    অক্ষর    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(আকার_2) \
    (((আকার_2) + (আকার (আকার_t) - 1)) & ~(আকার (আকার_t) - 1))

/* ------------------------------------------------------------------------- */

স্থির TinyAlloc *tal_new(TinyAlloc **pal, unsigned আকার_2)
{
    TinyAlloc *al = tcc_malloc(আকার(TinyAlloc) - আকার (আকার_t) + আকার_2);
    al->p = al->বাফার;
    al->bufend = al->বাফার + আকার_2;
    al->nb_allocs = 0;
    al->পরবর্তী = *pal, *pal = al;
    al->আকার_2 = al->পরবর্তী ? al->পরবর্তী->আকার_2 : আকার_2;
#যদি TAL_INFO
    al->nb_peak = 0;
    al->nb_যোগ = 0;
    al->peak_p = al->p;
#endif
    ফেরত al;
}

স্থির শূন্য tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *পরবর্তী;

#যদি TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
লেজ_call:
#যদি TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#যদি TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->বাফার, al->nb_peak, al->nb_যোগ,
            (al->peak_p - al->বাফার) * 100.0 / (al->bufend - al->বাফার));
#endif
    যদি (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->বাফার;
        যখন (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            যদি (header->সারি_অঙ্ক > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->সারি_অঙ্ক, (পূর্ণসংখ্যা)header->আকার_2);
            }
            p += header->আকার_2 + আকার(tal_header_t);
        }
#যদি TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    পরবর্তী = al->পরবর্তী;
    tcc_free(al);
    al = পরবর্তী;
    যদি (al)
        যাও লেজ_call;
    *pal = al;
}

স্থির শূন্য tal_free_impl(TinyAlloc **pal, শূন্য *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **শীর্ষ = pal;
    tal_header_t *header;

    যদি (!p)
        ফেরত;
    header = (tal_header_t *)p - 1;
#যদি TAL_DEBUG
    যদি (header->সারি_অঙ্ক < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (পূর্ণসংখ্যা)-header->সারি_অঙ্ক, (পূর্ণসংখ্যা)header->আকার_2);
    } অন্যথা
        header->সারি_অঙ্ক = -header->সারি_অঙ্ক;
#endif
    al = *pal;
    যখন ((uint8_t*)p < al->বাফার || (uint8_t*)p > al->bufend)
        al = *(pal = &al->পরবর্তী);
    যদি (0 == --al->nb_allocs) {
        *pal = al->পরবর্তী;
        যদি ((al->bufend - al->বাফার) > al->আকার_2) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } অন্যথা {
            /* reset and move to front */
            al->p = al->বাফার;
            al->পরবর্তী = *শীর্ষ, *শীর্ষ = al;
        }
    } অন্যথা যদি ((uint8_t*)p + header->আকার_2 == al->p) {
        al->p = (uint8_t*)header;
    }
}

স্থির শূন্য *tal_realloc_impl(TinyAlloc **pal, শূন্য *p, unsigned আকার_2 TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    শূন্য *ret;
    unsigned adj_আকার = TAL_ALIGN(আকার_2) + আকার(tal_header_t);
    TinyAlloc *al = *pal;

    যদি (p) {
        /* reallpc case */
        যখন ((uint8_t*)p < al->বাফার || (uint8_t*)p > al->bufend)
            al = al->পরবর্তী;
        header = (tal_header_t *)p - 1;
        যদি ((uint8_t*)p + header->আকার_2 == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        যদি (al->p + adj_আকার > al->bufend) {
            ret = tal_realloc(pal, 0, আকার_2);
            memcpy(ret, p, header->আকার_2);
            tal_free(pal, p);
            ফেরত ret;
        } অন্যথা যদি (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->আকার_2);
#যদি TAL_DEBUG
            header->সারি_অঙ্ক = -header->সারি_অঙ্ক;
#endif
        }
    } অন্যথা {
        /* new alloc case */
        যখন (al->p + adj_আকার > al->bufend) {
            al = al->পরবর্তী;
            যদি (!al) {
                unsigned new_আকার = (*pal)->আকার_2;
                যদি (adj_আকার > new_আকার) {
                    new_আকার = adj_আকার;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_আকার);
                বিরতি;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->আকার_2 = adj_আকার - আকার(tal_header_t);
    al->p += adj_আকার;
    ret = header + 1;
#যদি  TAL_DEBUG
    {
        পূর্ণসংখ্যা ofs = strlen(sfile) + 1 - আকার header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->সারি_অঙ্ক = sline;
#যদি TAL_INFO
        যদি (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        যদি (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_যোগ++;
#endif
    }
#endif
    ফেরত ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
স্থির শূন্য cstr_realloc(CString *cstr, পূর্ণসংখ্যা new_আকার)
{
    পূর্ণসংখ্যা আকার_2;

    আকার_2 = cstr->আকার_allocated;
    যদি (আকার_2 < 8)
        আকার_2 = 8; /* no need to allocate a too small first string */
    যখন (আকার_2 < new_আকার)
        আকার_2 = আকার_2 * 2;
    cstr->তথ্য = tcc_realloc(cstr->তথ্য, আকার_2);
    cstr->আকার_allocated = আকার_2;
}

/* add a byte */
ST_INLN শূন্য cstr_ccat(CString *cstr, পূর্ণসংখ্যা ch)
{
    পূর্ণসংখ্যা আকার_2;
    আকার_2 = cstr->আকার_2 + 1;
    যদি (আকার_2 > cstr->আকার_allocated)
        cstr_realloc(cstr, আকার_2);
    cstr->তথ্য[আকার_2 - 1] = ch;
    cstr->আকার_2 = আকার_2;
}

ST_INLN অক্ষর *unicode_to_utf8 (অক্ষর *b, uint32_t Uc)
{
    যদি (Uc<0x80) *b++=Uc;
    অন্যথা যদি (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    অন্যথা যদি (Uc-0xd800u<0x800) যাও error;
    অন্যথা যদি (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    অন্যথা যদি (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    অন্যথা error: tcc_error("0x%x is not a valid universal character", Uc);
    ফেরত b;
}

/* add a unicode character expanded into utf8 */
ST_INLN শূন্য cstr_u8cat(CString *cstr, পূর্ণসংখ্যা ch)
{
    অক্ষর buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC শূন্য cstr_cat(CString *cstr, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা len)
{
    পূর্ণসংখ্যা আকার_2;
    যদি (len <= 0)
        len = strlen(str) + 1 + len;
    আকার_2 = cstr->আকার_2 + len;
    যদি (আকার_2 > cstr->আকার_allocated)
        cstr_realloc(cstr, আকার_2);
    memmove(cstr->তথ্য + cstr->আকার_2, str, len);
    cstr->আকার_2 = আকার_2;
}

/* add a wide char */
ST_FUNC শূন্য cstr_wccat(CString *cstr, পূর্ণসংখ্যা ch)
{
    পূর্ণসংখ্যা আকার_2;
    আকার_2 = cstr->আকার_2 + আকার(nwchar_t);
    যদি (আকার_2 > cstr->আকার_allocated)
        cstr_realloc(cstr, আকার_2);
    *(nwchar_t *)(cstr->তথ্য + আকার_2 - আকার(nwchar_t)) = ch;
    cstr->আকার_2 = আকার_2;
}

ST_FUNC শূন্য cstr_new(CString *cstr)
{
    memset(cstr, 0, আকার(CString));
}

/* free string and reset it to NULL */
ST_FUNC শূন্য cstr_free(CString *cstr)
{
    tcc_free(cstr->তথ্য);
}

/* reset string to empty */
ST_FUNC শূন্য cstr_reset(CString *cstr)
{
    cstr->আকার_2 = 0;
}

ST_FUNC পূর্ণসংখ্যা cstr_vprintf(CString *cstr, ধ্রুবক অক্ষর *fmt, va_list ap)
{
    va_list v;
    পূর্ণসংখ্যা len, আকার_2 = 80;
    জন্য (;;) {
        আকার_2 += cstr->আকার_2;
        যদি (আকার_2 > cstr->আকার_allocated)
            cstr_realloc(cstr, আকার_2);
        আকার_2 = cstr->আকার_allocated - cstr->আকার_2;
        va_copy(v, ap);
        len = vsnprintf(cstr->তথ্য + cstr->আকার_2, আকার_2, fmt, v);
        va_end(v);
        যদি (len >= 0 && len < আকার_2)
            বিরতি;
        আকার_2 *= 2;
    }
    cstr->আকার_2 += len;
    ফেরত len;
}

ST_FUNC পূর্ণসংখ্যা cstr_printf(CString *cstr, ধ্রুবক অক্ষর *fmt, ...)
{
    va_list ap; পূর্ণসংখ্যা len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ফেরত len;
}

/* XXX: unicode ? */
স্থির শূন্য add_char(CString *cstr, পূর্ণসংখ্যা c)
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
স্থির TokenSym *tok_alloc_new(TokenSym **pts, ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা len)
{
    TokenSym *ts, **ptable;
    পূর্ণসংখ্যা i;

    যদি (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    যদি ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * আকার(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, আকার(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ফাঁকা;
    ts->sym_label = ফাঁকা;
    ts->sym_struct = ফাঁকা;
    ts->sym_identifier = ফাঁকা;
    ts->len = len;
    ts->hash_পরবর্তী = ফাঁকা;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ফেরত ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ধ্রুবক অক্ষর *str, পূর্ণসংখ্যা len)
{
    TokenSym *ts, **pts;
    পূর্ণসংখ্যা i;
    unsigned পূর্ণসংখ্যা h;
    
    h = TOK_HASH_INIT;
    জন্য(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned অক্ষর *)str)[i]);
    h &= (TOK_HASH_আকার - 1);

    pts = &hash_ident[h];
    জন্য(;;) {
        ts = *pts;
        যদি (!ts)
            বিরতি;
        যদি (ts->len == len && !memcmp(ts->str, str, len))
            ফেরত ts;
        pts = &(ts->hash_পরবর্তী);
    }
    ফেরত tok_alloc_new(pts, str, len);
}

ST_FUNC পূর্ণসংখ্যা tok_alloc_const(ধ্রুবক অক্ষর *str)
{
    ফেরত tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ধ্রুবক অক্ষর *get_tok_str(পূর্ণসংখ্যা v, CValue *cv)
{
    অক্ষর *p;
    পূর্ণসংখ্যা i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.তথ্য;

    নির্বাচন(v) {
    ক্ষেত্র TOK_CINT:
    ক্ষেত্র TOK_CUINT:
    ক্ষেত্র TOK_CLONG:
    ক্ষেত্র TOK_CULONG:
    ক্ষেত্র TOK_CLLONG:
    ক্ষেত্র TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        বিরতি;
    ক্ষেত্র TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    ক্ষেত্র TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        বিরতি;
    ক্ষেত্র TOK_PPNUM:
    ক্ষেত্র TOK_PPSTR:
        ফেরত (অক্ষর*)cv->str.তথ্য;
    ক্ষেত্র TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    ক্ষেত্র TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        যদি (v == TOK_STR) {
            len = cv->str.আকার_2 - 1;
            জন্য(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned অক্ষর *)cv->str.তথ্য)[i]);
        } অন্যথা {
            len = (cv->str.আকার_2 / আকার(nwchar_t)) - 1;
            জন্য(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.তথ্য)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        বিরতি;

    ক্ষেত্র TOK_CFLOAT:
        ফেরত strcpy(p, "<float>");
    ক্ষেত্র TOK_CDOUBLE:
        ফেরত strcpy(p, "<double>");
    ক্ষেত্র TOK_CLDOUBLE:
        ফেরত strcpy(p, "<long double>");
    ক্ষেত্র TOK_LINENUM:
        ফেরত strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    ক্ষেত্র TOK_LT:
        v = '<';
        যাও addv;
    ক্ষেত্র TOK_GT:
        v = '>';
        যাও addv;
    ক্ষেত্র TOK_DOTS:
        ফেরত strcpy(p, "...");
    ক্ষেত্র TOK_A_SHL:
        ফেরত strcpy(p, "<<=");
    ক্ষেত্র TOK_A_SAR:
        ফেরত strcpy(p, ">>=");
    ক্ষেত্র TOK_EOF:
        ফেরত strcpy(p, "<eof>");
    ক্ষেত্র 0: /* anonymous nameless symbols */
        ফেরত strcpy(p, "<no name>");
    পূর্বনির্ধারিত:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        যদি (v < TOK_IDENT) {
            /* search in two bytes table */
            ধ্রুবক unsigned অক্ষর *q = tok_two_chars;
            যখন (*q) {
                যদি (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ফেরত cstr_buf.তথ্য;
                }
                q += 3;
            }
            যদি (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                বিরতি;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } অন্যথা যদি (v < tok_ident) {
            ফেরত table_ident[v - TOK_IDENT]->str;
        } অন্যথা যদি (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } অন্যথা {
            /* should never happen */
            ফেরত ফাঁকা;
        }
        বিরতি;
    }
    ফেরত cstr_buf.তথ্য;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
স্থির পূর্ণসংখ্যা handle_eob(শূন্য)
{
    BufferedFile *bf = file;
    পূর্ণসংখ্যা len;

    /* only tries to read if really end of buffer */
    যদি (bf->buf_ptr >= bf->buf_end) {
        যদি (bf->fd >= 0) {
#যদি defined(PARSE_DEBUG)
            len = 1;
#অন্যথা
            len = IO_BUF_আকার;
#endif
            len = পঠ(bf->fd, bf->বাফার, len);
            যদি (len < 0)
                len = 0;
        } অন্যথা {
            len = 0;
        }
        যোগ_bytes += len;
        bf->buf_ptr = bf->বাফার;
        bf->buf_end = bf->বাফার + len;
        *bf->buf_end = CH_EOB;
    }
    যদি (bf->buf_ptr < bf->buf_end) {
        ফেরত bf->buf_ptr[0];
    } অন্যথা {
        bf->buf_ptr = bf->buf_end;
        ফেরত CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
স্থির পূর্ণসংখ্যা পরবর্তী_c(শূন্য)
{
    পূর্ণসংখ্যা ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    যদি (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ফেরত ch;
}

/* input with '\[\r]\n' handling. */
স্থির পূর্ণসংখ্যা handle_stray_noerror(পূর্ণসংখ্যা err)
{
    পূর্ণসংখ্যা ch;
    যখন ((ch = পরবর্তী_c()) == '\\') {
        ch = পরবর্তী_c();
        যদি (ch == '\n') {
    newl:
            file->সারি_অঙ্ক++;
        } অন্যথা {
            যদি (ch == '\r') {
                ch = পরবর্তী_c();
                যদি (ch == '\n')
                    যাও newl;
                *--file->buf_ptr = '\r';
            }
            যদি (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ফেরত *--file->buf_ptr = '\\';
        }
    }
    ফেরত ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
স্থির পূর্ণসংখ্যা handle_bs(uint8_t **p)
{
    পূর্ণসংখ্যা c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ফেরত c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
স্থির পূর্ণসংখ্যা handle_stray(uint8_t **p)
{
    পূর্ণসংখ্যা c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ফেরত c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    যদি (c == '\\')\
        c = handle_stray(&p); \
}

স্থির পূর্ণসংখ্যা skip_spaces(শূন্য)
{
    পূর্ণসংখ্যা ch;
    --file->buf_ptr;
    করো {
        ch = ninp();
    } যখন (isidnum_table[ch - CH_EOF] & IS_SPC);
    ফেরত ch;
}

/* single line C++ comments */
স্থির uint8_t *parse_সারি_comment(uint8_t *p)
{
    পূর্ণসংখ্যা c;
    জন্য(;;) {
        জন্য (;;) {
            c = *++p;
    redo:
            যদি (c == '\n' || c == '\\')
                বিরতি;
            c = *++p;
            যদি (c == '\n' || c == '\\')
                বিরতি;
        }
        যদি (c == '\n')
            বিরতি;
        c = handle_bs(&p);
        যদি (c == CH_EOF)
            বিরতি;
        যদি (c != '\\')
            যাও redo;
    }
    ফেরত p;
}

/* C comments */
স্থির uint8_t *parse_comment(uint8_t *p)
{
    পূর্ণসংখ্যা c;
    জন্য(;;) {
        /* fast skip loop */
        জন্য(;;) {
            c = *++p;
        redo:
            যদি (c == '\n' || c == '*' || c == '\\')
                বিরতি;
            c = *++p;
            যদি (c == '\n' || c == '*' || c == '\\')
                বিরতি;
        }
        /* now we can handle all the cases */
        যদি (c == '\n') {
            file->সারি_অঙ্ক++;
        } অন্যথা যদি (c == '*') {
            করো {
                c = *++p;
            } যখন (c == '*');
            যদি (c == '\\')
                c = handle_bs(&p);
            যদি (c == '/')
                বিরতি;
            যাও check_eof;
        } অন্যথা {
            c = handle_bs(&p);
        check_eof:
            যদি (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            যদি (c != '\\')
                যাও redo;
        }
    }
    ফেরত p + 1;
}

/* parse a string without interpreting escapes */
স্থির uint8_t *parse_pp_string(uint8_t *p, পূর্ণসংখ্যা sep, CString *str)
{
    পূর্ণসংখ্যা c;
    জন্য(;;) {
        c = *++p;
    redo:
        যদি (c == sep) {
            বিরতি;
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
                        যাও unterminated_string;
                }
                যাও add_char;
            } অন্যথা {
                যাও redo;
            }
        } অন্যথা যদি (c == '\n') {
        add_lf:
            যদি (ACCEPT_LF_IN_STRINGS) {
                file->সারি_অঙ্ক++;
                যাও add_char;
            } অন্যথা যদি (str) { /* not skipping */
                যাও unterminated_string;
            } অন্যথা {
                //tcc_warning("missing terminating %c character", sep);
                ফেরত p;
            }
        } অন্যথা যদি (c == '\r') {
            c = *++p;
            যদি (c == '\\')
                c = handle_bs(&p);
            যদি (c == '\n')
                যাও add_lf;
            যদি (c == CH_EOF)
                যাও unterminated_string;
            যদি (str)
                cstr_ccat(str, '\r');
            যাও redo;
        } অন্যথা {
        add_char:
            যদি (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ফেরত p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
স্থির শূন্য preprocess_skip(শূন্য)
{
    পূর্ণসংখ্যা a, start_of_সারি, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_সারি = 1;
    in_warn_or_error = 0;
    জন্য(;;) {
        c = *p;
        নির্বাচন(c) {
        ক্ষেত্র ' ':
        ক্ষেত্র '\t':
        ক্ষেত্র '\f':
        ক্ষেত্র '\v':
        ক্ষেত্র '\r':
            p++;
            চালু;
        ক্ষেত্র '\n':
            file->সারি_অঙ্ক++;
            p++;
            যাও redo_start;
        ক্ষেত্র '\\':
            c = handle_bs(&p);
            যদি (c == CH_EOF)
                expect("#endif");
            যদি (c == '\\')
                ++p;
            চালু;
        /* skip strings */
        ক্ষেত্র '\"':
        ক্ষেত্র '\'':
            যদি (in_warn_or_error)
                যাও _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ফাঁকা);
            বিরতি;
        /* skip comments */
        ক্ষেত্র '/':
            যদি (in_warn_or_error)
                যাও _default;
            ++p;
            c = handle_bs(&p);
            যদি (c == '*') {
                p = parse_comment(p);
            } অন্যথা যদি (c == '/') {
                p = parse_সারি_comment(p);
            }
            চালু;
        ক্ষেত্র '#':
            p++;
            যদি (start_of_সারি) {
                file->buf_ptr = p;
                পরবর্তী_nomacro();
                p = file->buf_ptr;
                যদি (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    যাও the_end;
                যদি (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                অন্যথা যদি (tok == TOK_ENDIF)
                    a--;
                অন্যথা যদি( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                অন্যথা যদি (tok == TOK_LINEFEED)
                    যাও redo_start;
                অন্যথা যদি (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_সারি_comment(p - 1);
            }
#যদি !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            অন্যথা যদি (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_সারি_comment(p - 1);
#অন্যথা
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            বিরতি;
_default:
        পূর্বনির্ধারিত:
            p++;
            বিরতি;
        }
        start_of_সারি = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#যদি 0
/* return the number of additional 'ints' necessary to store the
   token */
স্থির অন্তঃরেখ পূর্ণসংখ্যা tok_আকার(ধ্রুবক পূর্ণসংখ্যা *p)
{
    নির্বাচন(*p) {
        /* 4 bytes */
    ক্ষেত্র TOK_CINT:
    ক্ষেত্র TOK_CUINT:
    ক্ষেত্র TOK_CCHAR:
    ক্ষেত্র TOK_LCHAR:
    ক্ষেত্র TOK_CFLOAT:
    ক্ষেত্র TOK_LINENUM:
        ফেরত 1 + 1;
    ক্ষেত্র TOK_STR:
    ক্ষেত্র TOK_LSTR:
    ক্ষেত্র TOK_PPNUM:
    ক্ষেত্র TOK_PPSTR:
        ফেরত 1 + 1 + (p[1] + 3) / 4;
    ক্ষেত্র TOK_CLONG:
    ক্ষেত্র TOK_CULONG:
	ফেরত 1 + LONG_আকার / 4;
    ক্ষেত্র TOK_CDOUBLE:
    ক্ষেত্র TOK_CLLONG:
    ক্ষেত্র TOK_CULLONG:
        ফেরত 1 + 2;
    ক্ষেত্র TOK_CLDOUBLE:
        ফেরত 1 + LDOUBLE_শব্দগুলি;
    পূর্বনির্ধারিত:
        ফেরত 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN শূন্য tok_str_new(TokenString *s)
{
    s->str = ফাঁকা;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_সারি_অঙ্ক = -1;
}

ST_FUNC TokenString *tok_str_alloc(শূন্য)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, আকার *str);
    tok_str_new(str);
    ফেরত str;
}

ST_FUNC শূন্য tok_str_free_str(পূর্ণসংখ্যা *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC শূন্য tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC পূর্ণসংখ্যা *tok_str_realloc(TokenString *s, পূর্ণসংখ্যা new_আকার)
{
    পূর্ণসংখ্যা *str, আকার_2;

    আকার_2 = s->allocated_len;
    যদি (আকার_2 < 16)
        আকার_2 = 16;
    যখন (আকার_2 < new_আকার)
        আকার_2 = আকার_2 * 2;
    যদি (আকার_2 > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, আকার_2 * আকার(পূর্ণসংখ্যা));
        s->allocated_len = আকার_2;
        s->str = str;
    }
    ফেরত s->str;
}

ST_FUNC শূন্য tok_str_add(TokenString *s, পূর্ণসংখ্যা t)
{
    পূর্ণসংখ্যা len, *str;

    len = s->len;
    str = s->str;
    যদি (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC শূন্য begin_macro(TokenString *str, পূর্ণসংখ্যা alloc)
{
    str->alloc = alloc;
    str->পূর্ব = macro_স্তূপ;
    str->পূর্ব_ptr = macro_ptr;
    str->save_সারি_অঙ্ক = file->সারি_অঙ্ক;
    macro_ptr = str->str;
    macro_স্তূপ = str;
}

ST_FUNC শূন্য end_macro(শূন্য)
{
    TokenString *str = macro_স্তূপ;
    macro_স্তূপ = str->পূর্ব;
    macro_ptr = str->পূর্ব_ptr;
    file->সারি_অঙ্ক = str->save_সারি_অঙ্ক;
    যদি (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } অন্যথা {
        যদি (str->alloc == 2)
            str->str = ফাঁকা; /* don't free */
        tok_str_free(str);
    }
}

স্থির শূন্য tok_str_add2(TokenString *s, পূর্ণসংখ্যা t, CValue *cv)
{
    পূর্ণসংখ্যা len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    যদি (len + TOK_MAX_আকার >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_আকার + 1);
    str[len++] = t;
    নির্বাচন(t) {
    ক্ষেত্র TOK_CINT:
    ক্ষেত্র TOK_CUINT:
    ক্ষেত্র TOK_CCHAR:
    ক্ষেত্র TOK_LCHAR:
    ক্ষেত্র TOK_CFLOAT:
    ক্ষেত্র TOK_LINENUM:
#যদি LONG_আকার == 4
    ক্ষেত্র TOK_CLONG:
    ক্ষেত্র TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        বিরতি;
    ক্ষেত্র TOK_PPNUM:
    ক্ষেত্র TOK_PPSTR:
    ক্ষেত্র TOK_STR:
    ক্ষেত্র TOK_LSTR:
        {
            /* Insert the string into the int array. */
            আকার_t nb_শব্দগুলি =
                1 + (cv->str.আকার_2 + আকার(পূর্ণসংখ্যা) - 1) / আকার(পূর্ণসংখ্যা);
            যদি (len + nb_শব্দগুলি >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_শব্দগুলি + 1);
            str[len] = cv->str.আকার_2;
            memcpy(&str[len + 1], cv->str.তথ্য, cv->str.আকার_2);
            len += nb_শব্দগুলি;
        }
        বিরতি;
    ক্ষেত্র TOK_CDOUBLE:
    ক্ষেত্র TOK_CLLONG:
    ক্ষেত্র TOK_CULLONG:
#যদি LONG_আকার == 8
    ক্ষেত্র TOK_CLONG:
    ক্ষেত্র TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        বিরতি;
    ক্ষেত্র TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        যদি (LDOUBLE_শব্দগুলি >= 3)
        str[len++] = cv->tab[2];
        যদি (LDOUBLE_শব্দগুলি >= 4)
        str[len++] = cv->tab[3];
    পূর্বনির্ধারিত:
        বিরতি;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC শূন্য tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    যদি (file->সারি_অঙ্ক != s->last_সারি_অঙ্ক) {
        s->last_সারি_অঙ্ক = file->সারি_অঙ্ক;
        cval.i = s->last_সারি_অঙ্ক;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
স্থির শূন্য tok_str_add2_spc(TokenString *s, পূর্ণসংখ্যা t, CValue *cv)
{
    যদি (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
স্থির অন্তঃরেখ শূন্য tok_get(পূর্ণসংখ্যা *t, ধ্রুবক পূর্ণসংখ্যা **pp, CValue *cv)
{
    ধ্রুবক পূর্ণসংখ্যা *p = *pp;
    পূর্ণসংখ্যা n, *tab;

    tab = cv->tab;
    নির্বাচন(*t = *p++) {
#যদি LONG_আকার == 4
    ক্ষেত্র TOK_CLONG:
#endif
    ক্ষেত্র TOK_CINT:
    ক্ষেত্র TOK_CCHAR:
    ক্ষেত্র TOK_LCHAR:
    ক্ষেত্র TOK_LINENUM:
        cv->i = *p++;
        বিরতি;
#যদি LONG_আকার == 4
    ক্ষেত্র TOK_CULONG:
#endif
    ক্ষেত্র TOK_CUINT:
        cv->i = (unsigned)*p++;
        বিরতি;
    ক্ষেত্র TOK_CFLOAT:
	tab[0] = *p++;
	বিরতি;
    ক্ষেত্র TOK_STR:
    ক্ষেত্র TOK_LSTR:
    ক্ষেত্র TOK_PPNUM:
    ক্ষেত্র TOK_PPSTR:
        cv->str.আকার_2 = *p++;
        cv->str.তথ্য = (অক্ষর*)p;
        p += (cv->str.আকার_2 + আকার(পূর্ণসংখ্যা) - 1) / আকার(পূর্ণসংখ্যা);
        বিরতি;
    ক্ষেত্র TOK_CDOUBLE:
    ক্ষেত্র TOK_CLLONG:
    ক্ষেত্র TOK_CULLONG:
#যদি LONG_আকার == 8
    ক্ষেত্র TOK_CLONG:
    ক্ষেত্র TOK_CULONG:
#endif
        n = 2;
        যাও copy;
    ক্ষেত্র TOK_CLDOUBLE:
        n = LDOUBLE_শব্দগুলি;
    copy:
        করো
            *tab++ = *p++;
        যখন (--n);
        বিরতি;
    পূর্বনির্ধারিত:
        বিরতি;
    }
    *pp = p;
}

#যদি 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#অন্যথা
# define TOK_GET(t,p,c) করো { \
    পূর্ণসংখ্যা _t = **(p); \
    যদি (TOK_HAS_মান(_t)) \
        tok_get(t, p, c); \
    অন্যথা \
        *(t) = _t, ++*(p); \
    } যখন (0)
#endif

স্থির পূর্ণসংখ্যা macro_is_equal(ধ্রুবক পূর্ণসংখ্যা *a, ধ্রুবক পূর্ণসংখ্যা *b)
{
    CValue cv;
    পূর্ণসংখ্যা t;

    যদি (!a || !b)
        ফেরত 1;

    যখন (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        যদি (strcmp(tokcstr.তথ্য, get_tok_str(t, &cv)))
            ফেরত 0;
    }
    ফেরত !(*a || *b);
}

/* defines handling */
ST_INLN শূন্য define_ঠেলো(পূর্ণসংখ্যা v, পূর্ণসংখ্যা macro_type, পূর্ণসংখ্যা *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_স্তূপ, v, macro_type, 0);
    s->d = str;
    s->পরবর্তী = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    যদি (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ফাঁকা));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC শূন্য define_undef(Sym *s)
{
    পূর্ণসংখ্যা v = s->v;
    যদি (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = ফাঁকা;
}

ST_INLN Sym *define_find(পূর্ণসংখ্যা v)
{
    v -= TOK_IDENT;
    যদি ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ফেরত ফাঁকা;
    ফেরত table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC শূন্য free_defines(Sym *b)
{
    যখন (define_স্তূপ != b) {
        Sym *শীর্ষ = define_স্তূপ;
        define_স্তূপ = শীর্ষ->পূর্ব;
        tok_str_free_str(শীর্ষ->d);
        define_undef(শীর্ষ);
        sym_free(শীর্ষ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
স্থির শূন্য maybe_run_test(TCCState *s)
{
    ধ্রুবক অক্ষর *p;
    যদি (s->include_স্তূপ_ptr != s->include_স্তূপ)
        ফেরত;
    p = get_tok_str(tok, ফাঁকা);
    যদি (0 != memcmp(p, "test_", 5))
        ফেরত;
    যদি (0 != --s->run_test)
        ফেরত;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ঠেলো(tok, MACRO_OBJ, ফাঁকা, ফাঁকা);
}

ST_FUNC শূন্য skip_to_eol(পূর্ণসংখ্যা warn)
{
    যদি (tok == TOK_LINEFEED)
        ফেরত;
    যদি (warn)
        tcc_warning("extra tokens after directive");
    যখন (macro_স্তূপ)
        end_macro();
    file->buf_ptr = parse_সারি_comment(file->buf_ptr - 1);
    পরবর্তী_nomacro();
}

স্থির CachedInclude *
অনুসন্ধান_cached_include(TCCState *s1, ধ্রুবক অক্ষর *filename, পূর্ণসংখ্যা add);

স্থির পূর্ণসংখ্যা parse_include(TCCState *s1, পূর্ণসংখ্যা do_পরবর্তী, পূর্ণসংখ্যা test)
{
    পূর্ণসংখ্যা c, i;
    অক্ষর name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    যদি (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.আকার_2;
        pstrncpy(name, আকার name, tokcstr.তথ্য, i);
        পরবর্তী_nomacro();
    } অন্যথা {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        জন্য (;;) {
            পরবর্তী();
            p = name, i = strlen(p) - 1;
            যদি (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                বিরতি;
            যদি (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, আকার name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    যদি (!test)
        skip_to_eol(1);

    i = do_পরবর্তী ? file->include_পরবর্তী_সূচক : -1;
    জন্য (;;) {
        ++i;
        যদি (i == 0) {
            /* check absolute include path */
            যদি (!IS_ABSPATH(name))
                চালু;
            buf[0] = '\0';
        } অন্যথা যদি (i == 1) {
            /* search in file's dir if "header.h" */
            যদি (c != '\"')
                চালু;
            p = file->true_filename;
            pstrncpy(buf, আকার buf, p, tcc_basename(p) - p);
        } অন্যথা {
            পূর্ণসংখ্যা j = i - 2, k = j - s1->nb_include_paths;
            যদি (k < 0)
                p = s1->include_paths[j];
            অন্যথা যদি (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            অন্যথা যদি (test)
                ফেরত 0;
            অন্যথা
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, আকার buf, p);
            pstrcat(buf, আকার buf, "/");
        }
        pstrcat(buf, আকার buf, name);
        e = অনুসন্ধান_cached_include(s1, buf, 0);
        যদি (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            যদি ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (পূর্ণসংখ্যা)(s1->include_স্তূপ_ptr - s1->include_স্তূপ), "", buf);
            ফেরত 1;
        }
        যদি (tcc_open(s1, buf) >= 0)
            বিরতি;
    }

    যদি (test) {
        tcc_close();
    } অন্যথা {
        যদি (s1->include_স্তূপ_ptr >= s1->include_স্তূপ + INCLUDE_স্তূপ_আকার)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_স্তূপ_ptr++ = file->পূর্ব;
        file->include_পরবর্তী_সূচক = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->পূর্ব->filename, file->filename);
#endif
        /* update target deps */
        যদি (s1->gen_deps) {
            BufferedFile *bf = file;
            যখন (i == 1 && (bf = bf->পূর্ব))
                i = bf->include_পরবর্তী_সূচক;
            /* skip system include files */
            যদি (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ফেরত 1;
}

/* eval an expression for #if/#elif */
স্থির পূর্ণসংখ্যা রাশিমালা_preprocess(TCCState *s1)
{
    পূর্ণসংখ্যা c, t;
    পূর্ণসংখ্যা t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_রাশিমালা = 1;
    যখন (1) {
        পরবর্তী(); /* do macro subst */
        t = tok;
        যদি (tok < TOK_IDENT) {
            যদি (tok == TOK_LINEFEED || tok == TOK_EOF)
                বিরতি;
            যদি (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } অন্যথা যদি (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            পরবর্তী();
            t = tok;
            যদি (t == '(') 
                পরবর্তী();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            যদি (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            যদি (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            যদি (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_পরবর্তী)
                c = 1;
            যদি (t == '(') {
                পরবর্তী();
                যদি (tok != ')')
                    expect("')'");
            }
            যাও c_সংখ্যা;
        } অন্যথা যদি (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_পরবর্তী) {
            t = tok;
            পরবর্তী();
	    যদি (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            যদি (tok != ')')
                expect("')'");
            যাও c_সংখ্যা;
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
    pp_রাশিমালা = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    পরবর্তী();
    c = রাশিমালা_const();
    যদি (tok != TOK_EOF)
        tcc_error("...");
    pp_রাশিমালা = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ফেরত c != 0;
}

ST_FUNC শূন্য pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_রাশিমালা, 0));
    macro_ptr = macro_স্তূপ->str;
    যখন (পরবর্তী(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC শূন্য parse_define(শূন্য)
{
    Sym *s, *first, **ps;
    পূর্ণসংখ্যা v, t, varg, is_vaargs, t0;
    পূর্ণসংখ্যা saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    যদি (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = ফাঁকা;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    পরবর্তী_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    যদি (tok == '(') {
        পূর্ণসংখ্যা dotid = set_idnum('.', 0);
        পরবর্তী_nomacro();
        ps = &first;
        যদি (tok != ')') জন্য (;;) {
            varg = tok;
            পরবর্তী_nomacro();
            is_vaargs = 0;
            যদি (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } অন্যথা যদি (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                পরবর্তী_nomacro();
            }
            যদি (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_স্তূপ, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->পরবর্তী;
            যদি (tok == ')')
                বিরতি;
            যদি (tok != ',' || is_vaargs)
                যাও bad_list;
            পরবর্তী_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        পরবর্তী_nomacro();
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
    যখন (tok != TOK_LINEFEED && tok != TOK_EOF) {
        যদি (is_space(tok)) {
            str.need_spc |= 1;
        } অন্যথা {
            যদি (TOK_TWOSHARPS == tok) {
                যদি (0 == t0)
                    যাও bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        পরবর্তী_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_add(&str, 0);
    যদি (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ঠেলো(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

স্থির CachedInclude *অনুসন্ধান_cached_include(TCCState *s1, ধ্রুবক অক্ষর *filename, পূর্ণসংখ্যা add)
{
    ধ্রুবক অক্ষর *s, *basename;
    unsigned পূর্ণসংখ্যা h;
    CachedInclude *e;
    পূর্ণসংখ্যা c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    যখন ((c = (unsigned অক্ষর)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#অন্যথা
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_আকার - 1);

    i = s1->cached_includes_hash[h];
    জন্য(;;) {
        যদি (i == 0)
            বিরতি;
        e = s1->cached_includes[i - 1];
        যদি (0 == PATHCMP(filename, e->filename))
            ফেরত e;
        যদি (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ফেরত e;
        i = e->hash_পরবর্তী;
    }
    যদি (!add)
        ফেরত ফাঁকা;

    e = tcc_malloc(আকার(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_পরবর্তী = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    ফেরত e;
}

স্থির পূর্ণসংখ্যা pragma_parse(TCCState *s1)
{
    পরবর্তী_nomacro();
    যদি (tok == TOK_ঠেলো_macro || tok == TOK_বের_করো_macro) {
        পূর্ণসংখ্যা t = tok, v;
        Sym *s;

        যদি (পরবর্তী(), tok != '(')
            যাও pragma_err;
        যদি (পরবর্তী(), tok != TOK_STR)
            যাও pragma_err;
        v = tok_alloc(tokc.str.তথ্য, tokc.str.আকার_2 - 1)->tok;
        যদি (পরবর্তী(), tok != ')')
            যাও pragma_err;
        যদি (t == TOK_ঠেলো_macro) {
            যখন (ফাঁকা == (s = define_find(v)))
                define_ঠেলো(v, 0, ফাঁকা, ফাঁকা);
            s->type.ref = s; /* set push boundary */
        } অন্যথা {
            জন্য (s = define_স্তূপ; s; s = s->পূর্ব)
                যদি (s->v == v && s->type.ref == s) {
                    s->type.ref = ফাঁকা;
                    বিরতি;
                }
        }
        যদি (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : ফাঁকা;
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
        ফেরত 1;

    } অন্যথা যদি (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        পরবর্তী();
        skip('(');
        যদি (tok == TOK_ASM_বের_করো) {
            পরবর্তী();
            যদি (s1->pack_স্তূপ_ptr <= s1->pack_স্তূপ) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_স্তূপ_ptr--;
        } অন্যথা {
            পূর্ণসংখ্যা val = 0;
            যদি (tok != ')') {
                যদি (tok == TOK_ASM_ঠেলো) {
                    পরবর্তী();
                    যদি (s1->pack_স্তূপ_ptr >= s1->pack_স্তূপ + PACK_স্তূপ_আকার - 1)
                        যাও stk_error;
                    val = *s1->pack_স্তূপ_ptr++;
                    যদি (tok != ',')
                        যাও pack_set;
                    পরবর্তী();
                }
                যদি (tok != TOK_CINT)
                    যাও pragma_err;
                val = tokc.i;
                যদি (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    যাও pragma_err;
                পরবর্তী();
            }
        pack_set:
            *s1->pack_স্তূপ_ptr = val;
        }
        যদি (tok != ')')
            যাও pragma_err;

    } অন্যথা যদি (tok == TOK_comment) {
        অক্ষর *p; পূর্ণসংখ্যা t;
        পরবর্তী();
        skip('(');
        t = tok;
        পরবর্তী();
        skip(',');
        যদি (tok != TOK_STR)
            যাও pragma_err;
        p = tcc_strdup(tokc.str.তথ্য);
        পরবর্তী();
        যদি (tok != ')')
            যাও pragma_err;
        যদি (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } অন্যথা {
            যদি (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } অন্যথা {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ফেরত 0;
    }
    পরবর্তী();
    ফেরত 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC শূন্য tccpp_putfile(ধ্রুবক অক্ষর *filename)
{
    অক্ষর buf[1024];
    buf[0] = 0;
    যদি (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, আকার buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, আকার buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    যদি (0 == strcmp(file->filename, buf))
        ফেরত;
    //printf("new file '%s'\n", buf);
    যদি (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, আকার file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC শূন্য preprocess(পূর্ণসংখ্যা is_bof)
{
    TCCState *s1 = tcc_state;
    পূর্ণসংখ্যা c, n, saved_parse_flags;
    অক্ষর buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_অঙ্ক
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    পরবর্তী_nomacro();
 redo:
    নির্বাচন(tok) {
    ক্ষেত্র TOK_DEFINE:
        pp_debug_tok = tok;
        পরবর্তী_nomacro();
        pp_debug_symv = tok;
        parse_define();
        বিরতি;
    ক্ষেত্র TOK_UNDEF:
        pp_debug_tok = tok;
        পরবর্তী_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        যদি (s)
            define_undef(s);
        পরবর্তী_nomacro();
        বিরতি;
    ক্ষেত্র TOK_INCLUDE:
    ক্ষেত্র TOK_INCLUDE_পরবর্তী:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        যাও the_end;
    ক্ষেত্র TOK_IFNDEF:
        c = 1;
        যাও do_ifdef;
    ক্ষেত্র TOK_IF:
        c = রাশিমালা_preprocess(s1);
        যাও do_if;
    ক্ষেত্র TOK_IFDEF:
        c = 0;
    do_ifdef:
        পরবর্তী_nomacro();
        যদি (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        যদি (is_bof) {
            যদি (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, ফাঁকা));
#endif
                file->ifndef_macro = tok;
            }
        }
        যদি (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_পরবর্তী)
            c ^= 1;
        পরবর্তী_nomacro();
    do_if:
        যদি (s1->ifdef_স্তূপ_ptr >= s1->ifdef_স্তূপ + IFDEF_স্তূপ_আকার)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_স্তূপ_ptr++ = c;
        যাও test_skip;
    ক্ষেত্র TOK_ELSE:
        পরবর্তী_nomacro();
        যদি (s1->ifdef_স্তূপ_ptr == s1->ifdef_স্তূপ)
            tcc_error("#else without matching #if");
        যদি (s1->ifdef_স্তূপ_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_স্তূপ_ptr[-1] ^= 3);
        যাও test_else;
    ক্ষেত্র TOK_ELIF:
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
            c = রাশিমালা_preprocess(s1);
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
            যাও redo;
        }
        বিরতি;
    ক্ষেত্র TOK_ENDIF:
        পরবর্তী_nomacro();
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
        বিরতি;

    ক্ষেত্র TOK_সারি:
        parse_flags &= ~PARSE_FLAG_TOK_অঙ্ক;
        পরবর্তী();
        যদি (tok != TOK_PPNUM) {
    সারি_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        যাও সারি_অঙ্ক_2;
    ক্ষেত্র TOK_PPNUM:
        যদি (parse_flags & PARSE_FLAG_ASM_FILE)
            যাও ignore;
        c = 0; /* no error with extra tokens */
    সারি_অঙ্ক_2:
        জন্য (n = 0, q = tokc.str.তথ্য; *q; ++q) {
            যদি (!isnum(*q))
                যাও সারি_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        পরবর্তী();
        যদি (tok != TOK_LINEFEED) {
            যদি (tok != TOK_PPSTR || tokc.str.তথ্য[0] != '"')
                যাও সারি_err;
            tokc.str.তথ্য[tokc.str.আকার_2 - 2] = 0;
            tccpp_putfile(tokc.str.তথ্য + 1);
            পরবর্তী();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        যদি (file->fd > 0)
            যোগ_সারিগুলি += file->সারি_অঙ্ক - n;
        file->সারি_অঙ্ক = n;
        বিরতি;

    ক্ষেত্র TOK_ERROR:
    ক্ষেত্র TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        যখন (c != '\n' && c != CH_EOF) {
            যদি ((q - buf) < আকার(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        যদি (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        অন্যথা
            tcc_warning("#warning %s", buf);
        পরবর্তী_nomacro();
        বিরতি;
    }
    ক্ষেত্র TOK_PRAGMA:
        যদি (!pragma_parse(s1))
            যাও ignore;
        বিরতি;
    ক্ষেত্র TOK_LINEFEED:
        যাও the_end;
    পূর্বনির্ধারিত:
        /* ignore gas line comment in an 'S' file. */
        যদি (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            যাও ignore;
        যদি (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            যাও ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        যাও the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
স্থির শূন্য parse_escape_string(CString *outstr, ধ্রুবক uint8_t *buf, পূর্ণসংখ্যা is_long)
{
    পূর্ণসংখ্যা c, n, i;
    ধ্রুবক uint8_t *p;

    p = buf;
    জন্য(;;) {
        c = *p;
        যদি (c == '\0')
            বিরতি;
        যদি (c == '\\') {
            p++;
            /* escape */
            c = *p;
            নির্বাচন(c) {
            ক্ষেত্র '0': ক্ষেত্র '1': ক্ষেত্র '2': ক্ষেত্র '3':
            ক্ষেত্র '4': ক্ষেত্র '5': ক্ষেত্র '6': ক্ষেত্র '7':
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
                যাও add_char_nonext;
            ক্ষেত্র 'x': i = 0; যাও parse_hex_or_ucn;
            ক্ষেত্র 'u': i = 4; যাও parse_hex_or_ucn;
            ক্ষেত্র 'U': i = 8; যাও parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                করো {
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
                        যাও add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } যখন (--i);
		যদি (is_long) {
    add_hex_or_ucn:
                    c = n;
		    যাও add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                চালু;
            ক্ষেত্র 'a':
                c = '\a';
                বিরতি;
            ক্ষেত্র 'b':
                c = '\b';
                বিরতি;
            ক্ষেত্র 'f':
                c = '\f';
                বিরতি;
            ক্ষেত্র 'n':
                c = '\n';
                বিরতি;
            ক্ষেত্র 'r':
                c = '\r';
                বিরতি;
            ক্ষেত্র 't':
                c = '\t';
                বিরতি;
            ক্ষেত্র 'v':
                c = '\v';
                বিরতি;
            ক্ষেত্র 'e':
                যদি (!gnu_ext)
                    যাও invalid_escape;
                c = 27;
                বিরতি;
            ক্ষেত্র '\'':
            ক্ষেত্র '\"':
            ক্ষেত্র '\\': 
            ক্ষেত্র '?':
                বিরতি;
            পূর্বনির্ধারিত:
            invalid_escape:
                যদি (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                অন্যথা
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                বিরতি;
            }
        } অন্যথা যদি (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            পূর্ণসংখ্যা cont; /* count of continuation bytes */
            পূর্ণসংখ্যা skip; /* how many bytes should skip when error occurred */
            পূর্ণসংখ্যা i;

            /* decode leading byte */
            যদি (c < 0xC2) {
	            skip = 1; যাও invalid_utf8_sequence;
            } অন্যথা যদি (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } অন্যথা যদি (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } অন্যথা যদি (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } অন্যথা {
	            skip = 1; যাও invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            জন্য (i = 1; i <= cont; i++) {
                পূর্ণসংখ্যা l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                যদি (i == 1) {
                    নির্বাচন (c) {
                    ক্ষেত্র 0xE0: l = 0xA0; বিরতি;
                    ক্ষেত্র 0xED: h = 0x9F; বিরতি;
                    ক্ষেত্র 0xF0: l = 0x90; বিরতি;
                    ক্ষেত্র 0xF4: h = 0x8F; বিরতি;
                    }
                }

                যদি (p[i] < l || p[i] > h) {
                    skip = i; যাও invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            যাও add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            যাও add_char_nonext;

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

স্থির শূন্য parse_string(ধ্রুবক অক্ষর *s, পূর্ণসংখ্যা len)
{
    uint8_t buf[1000], *p = buf;
    পূর্ণসংখ্যা is_long, sep;

    যদি ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    যদি (len >= আকার buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    যদি (p != buf)
        tcc_free(p);

    যদি (sep == '\'') {
        পূর্ণসংখ্যা char_আকার, i, n, c;
        /* XXX: make it portable */
        যদি (!is_long)
            tok = TOK_CCHAR, char_আকার = 1;
        অন্যথা
            tok = TOK_LCHAR, char_আকার = আকার(nwchar_t);
        n = tokcstr.আকার_2 / char_আকার - 1;
        যদি (n < 1)
            tcc_error("empty character constant");
        যদি (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        জন্য (c = i = 0; i < n; ++i) {
            যদি (is_long)
                c = ((nwchar_t *)tokcstr.তথ্য)[i];
            অন্যথা
                c = (c << 8) | ((অক্ষর *)tokcstr.তথ্য)[i];
        }
        tokc.i = c;
    } অন্যথা {
        tokc.str.আকার_2 = tokcstr.আকার_2;
        tokc.str.তথ্য = tokcstr.তথ্য;
        যদি (!is_long)
            tok = TOK_STR;
        অন্যথা
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_আকার 4

/* bn = (bn << shift) | or_val */
স্থির পূর্ণসংখ্যা bn_lshift(unsigned পূর্ণসংখ্যা *bn, পূর্ণসংখ্যা shift, পূর্ণসংখ্যা or_val)
{
    পূর্ণসংখ্যা i;
    unsigned পূর্ণসংখ্যা v;
    যদি (bn[BN_আকার - 1] >> (32 - shift))
	ফেরত shift;
    জন্য(i=0;i<BN_আকার;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ফেরত 0;
}

স্থির শূন্য bn_zero(unsigned পূর্ণসংখ্যা *bn)
{
    পূর্ণসংখ্যা i;
    জন্য(i=0;i<BN_আকার;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
স্থির শূন্য parse_সংখ্যা(ধ্রুবক অক্ষর *p)
{
    পূর্ণসংখ্যা b, t, shift, frac_bits, s, exp_val, ch;
    অক্ষর *q;
    unsigned পূর্ণসংখ্যা bn[BN_আকার];
    long দ্বিগুণ d;

    /*সংখ্যা*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    যদি (t == '.') {
        যাও float_frac_parse;
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
    যখন (1) {
        যদি (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        অন্যথা যদি (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        অন্যথা যদি (isnum(ch))
            t = ch - '0';
        অন্যথা
            বিরতি;
        যদি (t >= b)
            বিরতি;
        যদি (q >= token_buf + STRING_MAX_আকার) {
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
            যখন (1) {
                t = *q++;
                যদি (t == '\0') {
                    বিরতি;
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
                যখন (1) {
                    t = ch;
                    যদি (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } অন্যথা যদি (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } অন্যথা যদি (t >= '0' && t <= '9') {
                        t = t - '0';
                    } অন্যথা {
                        বিরতি;
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
            যখন (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		যদি (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long দ্বিগুণ)bn[3] * 79228162514264337593543950336.0L +
	        (long দ্বিগুণ)bn[2] * 18446744073709551616.0L +
	        (long দ্বিগুণ)bn[1] * 4294967296.0L +
	        (long দ্বিগুণ)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            যদি (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (দশমিক)d;
            } অন্যথা যদি (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } অন্যথা {
                tok = TOK_CDOUBLE;
                tokc.d = (দ্বিগুণ)d;
            }
        } অন্যথা {
            /* decimal floats */
            যদি (ch == '.') {
                যদি (q >= token_buf + STRING_MAX_আকার)
                    যাও অঙ্ক_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                যখন (ch >= '0' && ch <= '9') {
                    যদি (q >= token_buf + STRING_MAX_আকার)
                        যাও অঙ্ক_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            যদি (ch == 'e' || ch == 'E') {
                যদি (q >= token_buf + STRING_MAX_আকার)
                    যাও অঙ্ক_too_long;
                *q++ = ch;
                ch = *p++;
                যদি (ch == '-' || ch == '+') {
                    যদি (q >= token_buf + STRING_MAX_আকার)
                        যাও অঙ্ক_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                যদি (ch < '0' || ch > '9')
                    expect("exponent digits");
                যখন (ch >= '0' && ch <= '9') {
                    যদি (q >= token_buf + STRING_MAX_আকার)
                        যাও অঙ্ক_too_long;
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
                tokc.f = strtof(token_buf, ফাঁকা);
            } অন্যথা যদি (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ফাঁকা);
            } অন্যথা {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ফাঁকা);
            }
        }
    } অন্যথা {
        unsigned long long n, n1;
        পূর্ণসংখ্যা lcount, ucount, ov = 0;
        ধ্রুবক অক্ষর *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        যদি (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        যখন(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            যদি (t == '\0')
                বিরতি;
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
        জন্য(;;) {
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
                বিরতি;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        যদি (pp_রাশিমালা)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        যদি (ucount == 0 && b == 10) {
            যদি (lcount <= (LONG_আকার == 4)) {
                যদি (n >= 0x80000000U)
                    lcount = (LONG_আকার == 4) + 1;
            }
            যদি (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } অন্যথা {
            যদি (lcount <= (LONG_আকার == 4)) {
                যদি (n >= 0x100000000ULL)
                    lcount = (LONG_আকার == 4) + 1;
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
    ক্ষেত্র c1:                                    \
        PEEKC(c, p);                            \
        যদি (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } অন্যথা {                                \
            tok = tok1;                         \
        }                                       \
        বিরতি;

/* return next token without macro substitution */
স্থির শূন্য পরবর্তী_nomacro(শূন্য)
{
    পূর্ণসংখ্যা t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned পূর্ণসংখ্যা h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    নির্বাচন(c) {
    ক্ষেত্র ' ':
    ক্ষেত্র '\t':
        tok = c;
        p++;
 maybe_space:
        যদি (parse_flags & PARSE_FLAG_SPACES)
            যাও keep_tok_flags;
        যখন (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        যাও redo_no_start;
    ক্ষেত্র '\f':
    ক্ষেত্র '\v':
    ক্ষেত্র '\r':
        p++;
        যাও redo_no_start;
    ক্ষেত্র '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        যদি (c == '\\')
            যাও parse_simple;
        যদি (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            যদি (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                যাও maybe_newline;
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
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ফাঁকা));
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
                যাও maybe_newline;
            }
        } অন্যথা {
            যাও redo_no_start;
        }
        বিরতি;

    ক্ষেত্র '\n':
        file->সারি_অঙ্ক++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        যদি (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            যাও redo_no_start;
        tok = TOK_LINEFEED;
        যাও keep_tok_flags;

    ক্ষেত্র '#':
        /* XXX: simplify */
        PEEKC(c, p);
        যদি ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            যাও maybe_newline;
        } অন্যথা {
            যদি (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } অন্যথা {
#যদি !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                যদি (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_সারি_comment(p - 1);
                    যাও redo_no_start;
                } অন্যথা
#endif
                {
                    tok = '#';
                }
            }
        }
        বিরতি;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    ক্ষেত্র '$':
        যদি (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            যাও parse_simple;

    ক্ষেত্র 'a': ক্ষেত্র 'b': ক্ষেত্র 'c': ক্ষেত্র 'd':
    ক্ষেত্র 'e': ক্ষেত্র 'f': ক্ষেত্র 'g': ক্ষেত্র 'h':
    ক্ষেত্র 'i': ক্ষেত্র 'j': ক্ষেত্র 'k': ক্ষেত্র 'l':
    ক্ষেত্র 'm': ক্ষেত্র 'n': ক্ষেত্র 'o': ক্ষেত্র 'p':
    ক্ষেত্র 'q': ক্ষেত্র 'r': ক্ষেত্র 's': ক্ষেত্র 't':
    ক্ষেত্র 'u': ক্ষেত্র 'v': ক্ষেত্র 'w': ক্ষেত্র 'x':
    ক্ষেত্র 'y': ক্ষেত্র 'z': 
    ক্ষেত্র 'A': ক্ষেত্র 'B': ক্ষেত্র 'C': ক্ষেত্র 'D':
    ক্ষেত্র 'E': ক্ষেত্র 'F': ক্ষেত্র 'G': ক্ষেত্র 'H':
    ক্ষেত্র 'I': ক্ষেত্র 'J': ক্ষেত্র 'K': 
    ক্ষেত্র 'M': ক্ষেত্র 'N': ক্ষেত্র 'O': ক্ষেত্র 'P':
    ক্ষেত্র 'Q': ক্ষেত্র 'R': ক্ষেত্র 'S': ক্ষেত্র 'T':
    ক্ষেত্র 'U': ক্ষেত্র 'V': ক্ষেত্র 'W': ক্ষেত্র 'X':
    ক্ষেত্র 'Y': ক্ষেত্র 'Z': 
    ক্ষেত্র '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        যখন (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        যদি (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_আকার - 1);
            pts = &hash_ident[h];
            জন্য(;;) {
                ts = *pts;
                যদি (!ts)
                    বিরতি;
                যদি (ts->len == len && !memcmp(ts->str, p1, len))
                    যাও token_found;
                pts = &(ts->hash_পরবর্তী);
            }
            ts = tok_alloc_new(pts, (অক্ষর *) p1, len);
        token_found: ;
        } অন্যথা {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (অক্ষর *) p1, len);
            p--;
            PEEKC(c, p);
            যখন (isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.তথ্য, tokcstr.আকার_2);
        }
        tok = ts->tok;
        বিরতি;
    ক্ষেত্র 'L':
        t = p[1];
        যদি (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            যদি (c == '\'' || c == '\"') {
                is_long = 1;
                যাও str_const;
            }
            *--p = c = 'L';
        }
        যাও parse_ident_fast;

    ক্ষেত্র '0': ক্ষেত্র '1': ক্ষেত্র '2': ক্ষেত্র '3':
    ক্ষেত্র '4': ক্ষেত্র '5': ক্ষেত্র '6': ক্ষেত্র '7':
    ক্ষেত্র '8': ক্ষেত্র '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_অঙ্ক:
        cstr_reset(&tokcstr);
        জন্য(;;) {
            cstr_ccat(&tokcstr, t);
            যদি (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((অক্ষর*)tokcstr.তথ্য)[0] == '0'
                                && toup(((অক্ষর*)tokcstr.তথ্য)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                বিরতি;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.আকার_2 = tokcstr.আকার_2;
        tokc.str.তথ্য = tokcstr.তথ্য;
        tok = TOK_PPNUM;
        বিরতি;

    ক্ষেত্র '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        যদি (isnum(c)) {
            t = '.';
            যাও parse_অঙ্ক;
        } অন্যথা যদি ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_অঙ্ক))) {
            *--p = c = '.';
            যাও parse_ident_fast;
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
        বিরতি;
    ক্ষেত্র '\'':
    ক্ষেত্র '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        যদি (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.আকার_2 = tokcstr.আকার_2;
        tokc.str.তথ্য = tokcstr.তথ্য;
        tok = TOK_PPSTR;
        বিরতি;

    ক্ষেত্র '<':
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
        বিরতি;
    ক্ষেত্র '>':
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
        বিরতি;
        
    ক্ষেত্র '&':
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
        বিরতি;
        
    ক্ষেত্র '|':
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
        বিরতি;

    ক্ষেত্র '+':
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
        বিরতি;
        
    ক্ষেত্র '-':
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
        বিরতি;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    ক্ষেত্র '/':
        PEEKC(c, p);
        যদি (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            যাও maybe_space;
        } অন্যথা যদি (c == '/') {
            p = parse_সারি_comment(p);
            tok = ' ';
            যাও maybe_space;
        } অন্যথা যদি (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } অন্যথা {
            tok = '/';
        }
        বিরতি;
        
        /* simple tokens */
    ক্ষেত্র '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        যদি (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_সারি_comment(p);
            যাও redo_no_start;
        }
#endif
    ক্ষেত্র '(':
    ক্ষেত্র ')':
    ক্ষেত্র '[':
    ক্ষেত্র ']':
    ক্ষেত্র '{':
    ক্ষেত্র '}':
    ক্ষেত্র ',':
    ক্ষেত্র ';':
    ক্ষেত্র ':':
    ক্ষেত্র '?':
    ক্ষেত্র '~':
    parse_simple:
        tok = c;
        p++;
        বিরতি;
    ক্ষেত্র 0xEF: /* UTF8 BOM ? */
        যদি (p[1] == 0xBB && p[2] == 0xBF && p == file->বাফার) {
            p += 3;
            যাও redo_no_start;
        }
    পূর্বনির্ধারিত:
        যদি (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    যাও parse_ident_fast;
        যদি (parse_flags & PARSE_FLAG_ASM_FILE)
            যাও parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        বিরতি;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#যদি defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
স্থির পূর্ণসংখ্যা indent;
স্থির শূন্য define_print(TCCState *s1, পূর্ণসংখ্যা v);
স্থির শূন্য pp_print(ধ্রুবক অক্ষর *বার্তা, পূর্ণসংখ্যা v, ধ্রুবক পূর্ণসংখ্যা *str)
{
    FILE *fp = tcc_state->ppfp;

    যদি (বার্তা[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    অন্যথা যদি (বার্তা[0] == '+')
         ++indent, ++বার্তা;
    অন্যথা যদি (বার্তা[0] == '-')
        --indent, ++বার্তা;

    fprintf(fp, "%*s", indent, "");
    যদি (বার্তা[0] == '#') {
        define_print(tcc_state, v);
    } অন্যথা {
        tok_print(str, v ? "%s %s" : "%s", বার্তা, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#অন্যথা
#define PP_PRINT(x)
#endif

স্থির পূর্ণসংখ্যা macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ধ্রুবক পূর্ণসংখ্যা *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
স্থির পূর্ণসংখ্যা *macro_arg_subst(Sym **nested_list, ধ্রুবক পূর্ণসংখ্যা *macro_str, Sym *args)
{
    পূর্ণসংখ্যা t, t0, t1, t2, n;
    ধ্রুবক পূর্ণসংখ্যা *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    জন্য (s = args, n = 0; s; s = s->পূর্ব, ++n);
    যখন (n--) {
        জন্য (s = args, t = 0; t < n; s = s->পূর্ব, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    যখন(1) {
        TOK_GET(&t, &macro_str, &cval);
        যদি (!t)
            বিরতি;
        যদি (t == '#') {
            /* stringize */
            করো t = *macro_str++; যখন (t == ' ');
            s = sym_find2(args, t);
            যদি (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                যখন (*st != TOK_EOF) {
                    ধ্রুবক অক্ষর *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    যখন (*s) {
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
                cval.str.আকার_2 = tokcstr.আকার_2;
                cval.str.তথ্য = tokcstr.তথ্য;
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
                যখন ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                যদি (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    যদি (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        পূর্ণসংখ্যা c = str.str[str.len - 1];
                        যখন (str.str[--str.len] != ',')
                            ;
                        যদি (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } অন্যথা {
                            /* suppress '##' and add variable */
                            str.len++;
                            যদি (c == ' ')
                                str.str[str.len++] = c;
                            যাও add_var;
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
                যখন (*st != TOK_EOF) {
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
    ফেরত str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
স্থির অন্তঃরেখ পূর্ণসংখ্যা *macro_twosharps(ধ্রুবক পূর্ণসংখ্যা *ptr0)
{
    পূর্ণসংখ্যা t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ধ্রুবক পূর্ণসংখ্যা *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    জন্য (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        যদি (t1 == 0)
            বিরতি;
        জন্য (;;) {
            n = 0;
            যখন ((t2 = ptr[n]) == ' ')
                ++n;
            যদি (t2 != TOK_PPJOIN)
                বিরতি;
            ptr += n;
            যখন ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            যদি (t2 == TOK_PLCHLDR)
                চালু;
            যদি (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        যদি (tokcstr.আকার_2) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.আকার_2);
            memcpy(file->বাফার, tokcstr.তথ্য, tokcstr.আকার_2);
            tok_flags = 0; /* don't interpret '#' */
            জন্য (n = 0;;n = l) {
                পরবর্তী_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                যদি (*file->buf_ptr == 0)
                    বিরতি;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->বাফার;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->বাফার + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        যদি (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ফেরত macro_str1.str;
}

স্থির পূর্ণসংখ্যা peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    পূর্ণসংখ্যা c;
    জন্য (;;) {
        PEEKC(c, p);
        নির্বাচন (c) {
        ক্ষেত্র '/':
            PEEKC(c, p);
            যদি (c == '*')
                p = parse_comment(p);
            অন্যথা যদি (c == '/')
                p = parse_সারি_comment(p);
            অন্যথা {
                c = *--p = '/';
                যাও leave;
            }
            --p, c = ' ';
            বিরতি;
        ক্ষেত্র ' ': ক্ষেত্র '\t':
            বিরতি;
        ক্ষেত্র '\f': ক্ষেত্র '\v': ক্ষেত্র '\r':
            চালু;
        ক্ষেত্র '\n':
            file->সারি_অঙ্ক++, tok_flags |= TOK_FLAG_BOL;
            বিরতি;
        পূর্বনির্ধারিত: leave:
            file->buf_ptr = p;
            ফেরত c;
        }
        যদি (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
স্থির পূর্ণসংখ্যা পরবর্তী_argstream(Sym **nested_list, TokenString *ws_str)
{
    পূর্ণসংখ্যা t;
    Sym *sa;

    যখন (macro_ptr) {
        ধ্রুবক পূর্ণসংখ্যা *m = macro_ptr;
        যখন ((t = *m) != 0) {
            যদি (ws_str) {
                যদি (t != ' ')
                    ফেরত t;
                ++m;
            } অন্যথা {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ফেরত tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        যদি (sa)
            *nested_list = sa->পূর্ব, sym_free(sa);
    }
    যদি (ws_str) {
        ফেরত peek_file(ws_str);
    } অন্যথা {
        পরবর্তী_nomacro();
        যদি (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ফেরত tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
স্থির পূর্ণসংখ্যা macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    পূর্ণসংখ্যা t;
    পূর্ণসংখ্যা v = s->v;

    PP_PRINT(("#", v, s->d));
    যদি (s->d) {
        পূর্ণসংখ্যা *mstr = s->d;
        পূর্ণসংখ্যা *jstr;
        Sym *sa;
        পূর্ণসংখ্যা ret;

        যদি (s->type.t & MACRO_FUNC) {
            পূর্ণসংখ্যা saved_parse_flags = parse_flags;
            TokenString str;
            পূর্ণসংখ্যা parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = পরবর্তী_argstream(nested_list, &str);
            যদি (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                যদি (parse_flags & PARSE_FLAG_SPACES)
                    জন্য (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ফেরত 0;
            } অন্যথা {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = ফাঁকা;
            sa = s->পরবর্তী;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            জন্য(;;) {
                করো {
                    t = পরবর্তী_argstream(nested_list, ফাঁকা);
                } যখন (t == ' ' || --i);

                যদি (!sa) {
                    যদি (t == ')') /* handle '()' case */
                        বিরতি;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                যখন (parlevel > 0
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
                    t = পরবর্তী_argstream(nested_list, ফাঁকা);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->পরবর্তী;
                যদি (t == ')') {
                    যদি (!sa)
                        বিরতি;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    যদি (sa->type.t && gnu_ext)
                        যাও empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            যখন (sa) {
                sa1 = sa->পূর্ব;
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
            *nested_list = sa->পূর্ব, sym_free(sa);

        যদি (jstr != mstr)
            tok_str_free_str(jstr);
        যদি (mstr != s->d)
            tok_str_free_str(mstr);
        ফেরত ret;

    } অন্যথা {
        CValue cval;
        অক্ষর buf[32], *cstrval = buf;

        /* special macros */
        যদি (v == TOK_সারি_2 || v == TOK_গণক) {
            t = v == TOK_সারি_2 ? file->সারি_অঙ্ক : pp_গণক++;
            snprintf(buf, আকার(buf), "%d", t);
            t = TOK_PPNUM;
            যাও add_cstr1;

        } অন্যথা যদি (v == TOK___FILE__) {
            cstrval = file->filename;
            যাও add_cstr;

        } অন্যথা যদি (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            কাঠামো tm *tm;
            time(&ti);
            tm = localtime(&ti);
            যদি (v == TOK___DATE__) {
                স্থির অক্ষর ধ্রুবক ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, আকার(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } অন্যথা {
                snprintf(buf, আকার(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.আকার_2 = strlen(cstrval) + 1;
            cval.str.তথ্য = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ফেরত 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
স্থির পূর্ণসংখ্যা macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ধ্রুবক পূর্ণসংখ্যা *macro_str
    )
{
    Sym *s;
    পূর্ণসংখ্যা t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    পূর্ণসংখ্যা tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    যখন (1) {
        TOK_GET(&t, &macro_str, &cval);
        যদি (t == 0 || t == TOK_EOF)
            বিরতি;
        যদি (t >= TOK_IDENT) {
            s = define_find(t);
            যদি (s == ফাঁকা || nosubst)
                যাও no_subst;
            /* if nested substitution, do nothing */
            যদি (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                যাও no_subst;
            }
            str = tok_str_alloc();
            str->str = (পূর্ণসংখ্যা*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            যদি (macro_স্তূপ != str) {
                /* already finished by reading function macro arguments */
                বিরতি;
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
            যদি (t == TOK_DEFINED && pp_রাশিমালা)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ফেরত nosubst;
}

/* return next token with macro substitution */
ST_FUNC শূন্য পরবর্তী(শূন্য)
{
    পূর্ণসংখ্যা t;
    যখন (macro_ptr) {
redo:
        t = *macro_ptr;
        যদি (TOK_HAS_মান(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            যদি (t == TOK_LINENUM) {
                file->সারি_অঙ্ক = tokc.i;
                যাও redo;
            }
            যাও convert;
        } অন্যথা যদি (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            চালু;
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
        ফেরত;
    }

    পরবর্তী_nomacro();
    t = tok;
    যদি (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        যদি (s) {
            Sym *nested_list = ফাঁকা;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            যাও redo;
        }
        ফেরত;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    যদি (t == TOK_PPNUM) {
        যদি  (parse_flags & PARSE_FLAG_TOK_অঙ্ক)
            parse_সংখ্যা(tokc.str.তথ্য);
    } অন্যথা যদি (t == TOK_PPSTR) {
        যদি (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.তথ্য, tokc.str.আকার_2 - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN শূন্য unget_tok(পূর্ণসংখ্যা last_tok)
{
    TokenString *str = &unget_buf;
    পূর্ণসংখ্যা alloc = 0;
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

স্থির ধ্রুবক অক্ষর * ধ্রুবক target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# যদি PTR_আকার == 8
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

স্থির শূন্য putdef(CString *cs, ধ্রুবক অক্ষর *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

স্থির শূন্য putdefs(CString *cs, ধ্রুবক অক্ষর *p)
{
    যখন (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

স্থির শূন্য tcc_predefs(TCCState *s1, CString *cs, পূর্ণসংখ্যা is_asm)
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
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_আকার);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_আকার);
    যদি (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#যদি CONFIG_TCC_PREDEFS
        #অন্তর্ভাব "tccdefs_.h" /* include as strings */
#অন্যথা
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC শূন্য preprocess_start(TCCState *s1, পূর্ণসংখ্যা filetype)
{
    পূর্ণসংখ্যা is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_স্তূপ_ptr = s1->include_স্তূপ;
    s1->ifdef_স্তূপ_ptr = s1->ifdef_স্তূপ;
    file->ifdef_স্তূপ_ptr = s1->ifdef_স্তূপ_ptr;
    pp_রাশিমালা = 0;
    pp_গণক = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_স্তূপ[0] = 0;
    s1->pack_স্তূপ_ptr = s1->pack_স্তূপ;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    যদি (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        যদি (s1->cmdline_defs.আকার_2)
          cstr_cat(&cstr, s1->cmdline_defs.তথ্য, s1->cmdline_defs.আকার_2);
        যদি (s1->cmdline_incl.আকার_2)
          cstr_cat(&cstr, s1->cmdline_incl.তথ্য, s1->cmdline_incl.আকার_2);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_স্তূপ_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.আকার_2);
        memcpy(file->বাফার, cstr.তথ্য, cstr.আকার_2);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC শূন্য preprocess_end(TCCState *s1)
{
    যখন (macro_স্তূপ)
        end_macro();
    macro_ptr = ফাঁকা;
    যখন (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC পূর্ণসংখ্যা set_idnum(পূর্ণসংখ্যা c, পূর্ণসংখ্যা val)
{
    পূর্ণসংখ্যা পূর্ব = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ফেরত পূর্ব;
}

ST_FUNC শূন্য tccpp_new(TCCState *s)
{
    পূর্ণসংখ্যা i, c;
    ধ্রুবক অক্ষর *p, *r;

    /* init isid table */
    জন্য(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_অঙ্ক
            : 0);

    জন্য(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_আকার);
    tal_new(&tokstr_alloc, TOKSTR_TAL_আকার);

    memset(hash_ident, 0, TOK_HASH_আকার * আকার(TokenSym *));
    memset(s->cached_includes_hash, 0, আকার s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_আকার);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_আকার);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_আকার);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    যখন (*p) {
        r = p;
        জন্য(;;) {
            c = *r++;
            যদি (c == '\0')
                বিরতি;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ঠেলো(TOK_সারি_2, MACRO_OBJ, ফাঁকা, ফাঁকা);
    define_ঠেলো(TOK___FILE__, MACRO_OBJ, ফাঁকা, ফাঁকা);
    define_ঠেলো(TOK___DATE__, MACRO_OBJ, ফাঁকা, ফাঁকা);
    define_ঠেলো(TOK___TIME__, MACRO_OBJ, ফাঁকা, ফাঁকা);
    define_ঠেলো(TOK_গণক, MACRO_OBJ, ফাঁকা, ফাঁকা);
}

ST_FUNC শূন্য tccpp_delete(TCCState *s)
{
    পূর্ণসংখ্যা i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    যদি (n > যোগ_idents)
        যোগ_idents = n;
    জন্য (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ফাঁকা;

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

স্থির পূর্ণসংখ্যা pp_need_space(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b);

স্থির শূন্য tok_print(ধ্রুবক পূর্ণসংখ্যা *str, ধ্রুবক অক্ষর *বার্তা, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    পূর্ণসংখ্যা t, t0, s;
    CValue cval;

    va_start(ap, বার্তা);
    vfprintf(fp, বার্তা, ap);
    va_end(ap);

    s = t0 = 0;
    যখন (str) {
	TOK_GET(&t, &str, &cval);
	যদি (t == 0 || t == TOK_EOF)
	    বিরতি;
        যদি (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

স্থির শূন্য pp_সারি(TCCState *s1, BufferedFile *f, পূর্ণসংখ্যা level)
{
    পূর্ণসংখ্যা d = f->সারি_অঙ্ক - f->সারি_ref;

    যদি (s1->dflag & 4)
	ফেরত;

    যদি (s1->Pflag == সারি_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } অন্যথা যদি (level == 0 && f->সারি_ref && d < 8) {
	যখন (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } অন্যথা যদি (s1->Pflag == সারি_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->সারি_অঙ্ক, f->filename);
    } অন্যথা {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->সারি_অঙ্ক, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->সারি_ref = f->সারি_অঙ্ক;
}

স্থির শূন্য define_print(TCCState *s1, পূর্ণসংখ্যা v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    যদি (ফাঁকা == s || ফাঁকা == s->d)
        ফেরত;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ফাঁকা));
    যদি (s->type.t & MACRO_FUNC) {
        Sym *a = s->পরবর্তী;
        fprintf(fp,"(");
        যদি (a)
            জন্য (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ফাঁকা));
                যদি (!(a = a->পরবর্তী))
                    বিরতি;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

স্থির শূন্য pp_debug_defines(TCCState *s1)
{
    পূর্ণসংখ্যা v, t;
    ধ্রুবক অক্ষর *vs;
    FILE *fp;

    t = pp_debug_tok;
    যদি (t == 0)
        ফেরত;

    file->সারি_অঙ্ক--;
    pp_সারি(s1, file, 0);
    file->সারি_ref = ++file->সারি_অঙ্ক;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ফাঁকা);
    যদি (t == TOK_DEFINE) {
        define_print(s1, v);
    } অন্যথা যদি (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } অন্যথা যদি (t == TOK_ঠেলো_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } অন্যথা যদি (t == TOK_বের_করো_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
স্থির পূর্ণসংখ্যা pp_need_space(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
    ফেরত 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
স্থির পূর্ণসংখ্যা pp_check_he0xE(পূর্ণসংখ্যা t, ধ্রুবক অক্ষর *p)
{
    যদি (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ফেরত 'E';
    ফেরত t;
}

/* Preprocess the current file */
ST_FUNC পূর্ণসংখ্যা tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    পূর্ণসংখ্যা token_seen, spcs, level;
    ধ্রুবক অক্ষর *p;
    অক্ষর white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    যদি (s1->Pflag == সারি_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_অঙ্ক, s1->Pflag = 1;

    যদি (s1->do_bench) {
	/* for PP benchmarks */
	করো পরবর্তী(); যখন (tok != TOK_EOF);
	ফেরত 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    যদি (file->পূর্ব)
        pp_সারি(s1, file->পূর্ব, level++);
    pp_সারি(s1, file, level);

    জন্য (;;) {
        iptr = s1->include_স্তূপ_ptr;
        পরবর্তী();
        যদি (tok == TOK_EOF)
            বিরতি;

        level = s1->include_স্তূপ_ptr - iptr;
        যদি (level) {
            যদি (level > 0)
                pp_সারি(s1, *iptr, 0);
            pp_সারি(s1, file, level);
        }
        যদি (s1->dflag & 7) {
            pp_debug_defines(s1);
            যদি (s1->dflag & 4)
                চালু;
        }

        যদি (is_space(tok)) {
            যদি (spcs < আকার white - 1)
                white[spcs++] = tok;
            চালু;
        } অন্যথা যদি (tok == TOK_LINEFEED) {
            spcs = 0;
            যদি (token_seen == TOK_LINEFEED)
                চালু;
            ++file->সারি_ref;
        } অন্যথা যদি (token_seen == TOK_LINEFEED) {
            pp_সারি(s1, file, 0);
        } অন্যথা যদি (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ফেরত 0;
}

/* ------------------------------------------------------------------------- */
