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

#تعریف_کړه USING_GLOBALS
#ضمن "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#تعریف_کړه ACCEPT_LF_دننه_مزي_ګانې 0

/********************************************************/
/* global variables */

ST_معلومات صحيح tok_flags;
ST_معلومات صحيح parse_flags;

ST_معلومات بنية BufferedFile *file;
ST_معلومات صحيح tok;
ST_معلومات CValue tokc;
ST_معلومات ثابت صحيح *macro_ptr;
ST_معلومات CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_معلومات صحيح tok_ident;
ST_معلومات TokenSym **جدول_ident;
ST_معلومات صحيح pp_بیان;

/* ------------------------------------------------------------------------- */

ساكن TokenSym *hash_ident[TOK_HASH_اندازه];
ساكن حرف token_buf[STRING_MAX_اندازه + 1];
ساكن CString cstr_buf;
ساكن TokenString tokstr_buf;
ساكن TokenString unget_buf;
ساكن بینښه حرف isidnum_جدول[256 - CH_EOF];
ساكن صحيح pp_debug_tok, pp_debug_symv;
ساكن صحيح pp_counter;
ساكن فراغ tok_print(ثابت صحيح *str, ثابت حرف *پیغام, ...);
ساكن فراغ بل_nomacro(فراغ);
ساكن فراغ parse_شمېره(ثابت حرف *p);
ساكن فراغ parse_string(ثابت حرف *p, صحيح len);

ساكن بنية TinyAlloc *toksym_alloc;
ساكن بنية TinyAlloc *tokstr_alloc;

ساكن TokenString *macro_ډېری;

ساكن ثابت حرف tcc_keywords[] = 
#تعریف_کړه DEF(id, str) str "\0"
#ضمن "tcctok.h"
#تعریف_لغوه DEF
;

/* WARNING: the content of this string encodes token numbers */
ساكن ثابت بینښه حرف tok_two_chars[] =
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
    '+','=', TOK_A_جمع_کړه,
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

ST_FUNC فراغ skip(صحيح c)
{
    إذا (tok != c) {
        حرف tmp[40];
        pstrcpy(tmp, حجم tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    بل();
}

ST_FUNC فراغ expect(ثابت حرف *پیغام)
{
    tcc_error("%s expected", پیغام);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#تعریف_کړه USE_TAL

#که_نه_تعریف_شوی USE_TAL /* may cause memory leaks after errors */
#تعریف_کړه tal_free(al, p) tcc_free(p)
#تعریف_کړه tal_realloc(al, p, اندازه) tcc_realloc(p, اندازه)
#تعریف_کړه tal_new(a,b)
#تعریف_کړه tal_delete(a)
#وإلا
#إذا !defined(MEM_DEBUG)
#تعریف_کړه tal_free(al, p) tal_free_impl(al, p)
#تعریف_کړه tal_realloc(al, p, اندازه) tal_realloc_impl(al, p, اندازه)
#تعریف_کړه TAL_DEBUG_PARAMS
#وإلا
#تعریف_کړه TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#تعریف_کړه tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#تعریف_کړه tal_realloc(al, p, اندازه) tal_realloc_impl(al, p, اندازه, __FILE__, __LINE__)
#تعریف_کړه TAL_DEBUG_PARAMS , ثابت حرف *sfile, صحيح sline
#د_که_پای

#تعریف_کړه TOKSYM_TAL_اندازه (256 * 1024) /* allocator for TokenSym in table_ident */
#تعریف_کړه TOKSTR_TAL_اندازه (256 * 1024) /* allocator for TokenString instances */

تعريفنوع بنية TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    بنية TinyAlloc *بل;
    بینښه nb_allocs;
    بینښه اندازه;
#إذا TAL_INFO
    بینښه nb_peak;
    بینښه nb_ټول;
    uint8_t *peak_p;
#د_که_پای
    اتحاد {
        uint8_t بفر[1];
        اندازه_t _aligner_;
    };
} TinyAlloc;

تعريفنوع بنية tal_سرلیک_t {
    اندازه_t  اندازه; /* word align */
#إذا TAL_DEBUG
    صحيح     کرښه_عدد; /* negative line_num used for double free check */
    حرف    file_name[40];
#د_که_پای
} tal_سرلیک_t;

#تعریف_کړه TAL_ALIGN(اندازه) \
    (((اندازه) + (حجم (اندازه_t) - 1)) & ~(حجم (اندازه_t) - 1))

/* ------------------------------------------------------------------------- */

ساكن TinyAlloc *tal_new(TinyAlloc **pal, بینښه اندازه)
{
    TinyAlloc *al = tcc_malloc(حجم(TinyAlloc) - حجم (اندازه_t) + اندازه);
    al->p = al->بفر;
    al->bufend = al->بفر + اندازه;
    al->nb_allocs = 0;
    al->بل = *pal, *pal = al;
    al->اندازه = al->بل ? al->بل->اندازه : اندازه;
#إذا TAL_INFO
    al->nb_peak = 0;
    al->nb_ټول = 0;
    al->peak_p = al->p;
#د_که_پای
    أرجع al;
}

ساكن فراغ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *بل;

#إذا TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#د_که_پای
لکۍ_call:
#إذا TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#إذا TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->بفر, al->nb_peak, al->nb_ټول,
            (al->peak_p - al->بفر) * 100.0 / (al->bufend - al->بفر));
#د_که_پای
    إذا (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->بفر;
        طالما (p < al->p) {
            tal_سرلیک_t *سرلیک = (tal_سرلیک_t *)p;
            إذا (سرلیک->کرښه_عدد > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        سرلیک->file_name, سرلیک->کرښه_عدد, (صحيح)سرلیک->اندازه);
            }
            p += سرلیک->اندازه + حجم(tal_سرلیک_t);
        }
#إذا TAL_DEBUG == 2
        وتل(2);
#د_که_پای
    }
#د_که_پای
    بل = al->بل;
    tcc_free(al);
    al = بل;
    إذا (al)
        اذهب لکۍ_call;
    *pal = al;
}

ساكن فراغ tal_free_impl(TinyAlloc **pal, فراغ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **سر = pal;
    tal_سرلیک_t *سرلیک;

    إذا (!p)
        أرجع;
    سرلیک = (tal_سرلیک_t *)p - 1;
#إذا TAL_DEBUG
    إذا (سرلیک->کرښه_عدد < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                سرلیک->file_name, (صحيح)-سرلیک->کرښه_عدد, (صحيح)سرلیک->اندازه);
    } وإلا
        سرلیک->کرښه_عدد = -سرلیک->کرښه_عدد;
#د_که_پای
    al = *pal;
    طالما ((uint8_t*)p < al->بفر || (uint8_t*)p > al->bufend)
        al = *(pal = &al->بل);
    إذا (0 == --al->nb_allocs) {
        *pal = al->بل;
        إذا ((al->bufend - al->بفر) > al->اندازه) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } وإلا {
            /* reset and move to front */
            al->p = al->بفر;
            al->بل = *سر, *سر = al;
        }
    } وإلا إذا ((uint8_t*)p + سرلیک->اندازه == al->p) {
        al->p = (uint8_t*)سرلیک;
    }
}

ساكن فراغ *tal_realloc_impl(TinyAlloc **pal, فراغ *p, بینښه اندازه TAL_DEBUG_PARAMS)
{
    tal_سرلیک_t *سرلیک;
    فراغ *ret;
    بینښه adj_اندازه = TAL_ALIGN(اندازه) + حجم(tal_سرلیک_t);
    TinyAlloc *al = *pal;

    إذا (p) {
        /* reallpc case */
        طالما ((uint8_t*)p < al->بفر || (uint8_t*)p > al->bufend)
            al = al->بل;
        سرلیک = (tal_سرلیک_t *)p - 1;
        إذا ((uint8_t*)p + سرلیک->اندازه == al->p)
            al->p = (uint8_t*)سرلیک; /* maybe reuse */
        إذا (al->p + adj_اندازه > al->bufend) {
            ret = tal_realloc(pal, 0, اندازه);
            حافظه_نقل(ret, p, سرلیک->اندازه);
            tal_free(pal, p);
            أرجع ret;
        } وإلا إذا (al->p != (uint8_t*)سرلیک) {
            حافظه_نقل((tal_سرلیک_t*)al->p + 1, p, سرلیک->اندازه);
#إذا TAL_DEBUG
            سرلیک->کرښه_عدد = -سرلیک->کرښه_عدد;
#د_که_پای
        }
    } وإلا {
        /* new alloc case */
        طالما (al->p + adj_اندازه > al->bufend) {
            al = al->بل;
            إذا (!al) {
                بینښه new_اندازه = (*pal)->اندازه;
                إذا (adj_اندازه > new_اندازه) {
                    new_اندازه = adj_اندازه;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_اندازه);
                اكسر;
            }
        }
        al->nb_allocs++;
    }
    سرلیک = (tal_سرلیک_t *)al->p;
    سرلیک->اندازه = adj_اندازه - حجم(tal_سرلیک_t);
    al->p += adj_اندازه;
    ret = سرلیک + 1;
#إذا  TAL_DEBUG
    {
        صحيح ofs = مزي_اوږدوالی(sfile) + 1 - حجم سرلیک->file_name;
        strcpy(سرلیک->file_name, sfile + (ofs > 0 ? ofs : 0));
        سرلیک->کرښه_عدد = sline;
#إذا TAL_INFO
        إذا (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        إذا (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_ټول++;
#د_که_پای
    }
#د_که_پای
    أرجع ret;
}

#د_که_پای /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ساكن فراغ cstr_realloc(CString *cstr, صحيح new_اندازه)
{
    صحيح اندازه;

    اندازه = cstr->اندازه_allocated;
    إذا (اندازه < 8)
        اندازه = 8; /* no need to allocate a too small first string */
    طالما (اندازه < new_اندازه)
        اندازه = اندازه * 2;
    cstr->معلومات = tcc_realloc(cstr->معلومات, اندازه);
    cstr->اندازه_allocated = اندازه;
}

/* add a byte */
ST_INLN فراغ cstr_ccat(CString *cstr, صحيح ch)
{
    صحيح اندازه;
    اندازه = cstr->اندازه + 1;
    إذا (اندازه > cstr->اندازه_allocated)
        cstr_realloc(cstr, اندازه);
    cstr->معلومات[اندازه - 1] = ch;
    cstr->اندازه = اندازه;
}

ST_INLN حرف *unicode_منزل_utf8 (حرف *b, uint32_t Uc)
{
    إذا (Uc<0x80) *b++=Uc;
    وإلا إذا (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    وإلا إذا (Uc-0xd800u<0x800) اذهب error;
    وإلا إذا (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    وإلا إذا (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    وإلا error: tcc_error("0x%x is not a valid universal character", Uc);
    أرجع b;
}

/* add a unicode character expanded into utf8 */
ST_INLN فراغ cstr_u8cat(CString *cstr, صحيح ch)
{
    حرف buf[4], *e;
    e = unicode_منزل_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC فراغ cstr_cat(CString *cstr, ثابت حرف *str, صحيح len)
{
    صحيح اندازه;
    إذا (len <= 0)
        len = مزي_اوږدوالی(str) + 1 + len;
    اندازه = cstr->اندازه + len;
    إذا (اندازه > cstr->اندازه_allocated)
        cstr_realloc(cstr, اندازه);
    memmove(cstr->معلومات + cstr->اندازه, str, len);
    cstr->اندازه = اندازه;
}

/* add a wide char */
ST_FUNC فراغ cstr_wccat(CString *cstr, صحيح ch)
{
    صحيح اندازه;
    اندازه = cstr->اندازه + حجم(nwchar_t);
    إذا (اندازه > cstr->اندازه_allocated)
        cstr_realloc(cstr, اندازه);
    *(nwchar_t *)(cstr->معلومات + اندازه - حجم(nwchar_t)) = ch;
    cstr->اندازه = اندازه;
}

ST_FUNC فراغ cstr_new(CString *cstr)
{
    memset(cstr, 0, حجم(CString));
}

/* free string and reset it to NULL */
ST_FUNC فراغ cstr_free(CString *cstr)
{
    tcc_free(cstr->معلومات);
}

/* reset string to empty */
ST_FUNC فراغ cstr_reset(CString *cstr)
{
    cstr->اندازه = 0;
}

ST_FUNC صحيح cstr_vprintf(CString *cstr, ثابت حرف *fmt, va_list ap)
{
    va_list v;
    صحيح len, اندازه = 80;
    لكل (;;) {
        اندازه += cstr->اندازه;
        إذا (اندازه > cstr->اندازه_allocated)
            cstr_realloc(cstr, اندازه);
        اندازه = cstr->اندازه_allocated - cstr->اندازه;
        va_copy(v, ap);
        len = vsnprintf(cstr->معلومات + cstr->اندازه, اندازه, fmt, v);
        va_end(v);
        إذا (len >= 0 && len < اندازه)
            اكسر;
        اندازه *= 2;
    }
    cstr->اندازه += len;
    أرجع len;
}

ST_FUNC صحيح cstr_printf(CString *cstr, ثابت حرف *fmt, ...)
{
    va_list ap; صحيح len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    أرجع len;
}

/* XXX: unicode ? */
ساكن فراغ جمع_کړه_char(CString *cstr, صحيح c)
{
    إذا (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    إذا (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } وإلا {
        cstr_ccat(cstr, '\\');
        إذا (c == '\n') {
            cstr_ccat(cstr, 'n');
        } وإلا {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ساكن TokenSym *tok_alloc_new(TokenSym **pts, ثابت حرف *str, صحيح len)
{
    TokenSym *ts, **ptable;
    صحيح i;

    إذا (tok_ident >= SYM_لومړی_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    إذا ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(جدول_ident, (i + TOK_ALLOC_INCR) * حجم(TokenSym *));
        جدول_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, حجم(TokenSym) + len);
    جدول_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = عدم;
    ts->sym_label = عدم;
    ts->sym_struct = عدم;
    ts->sym_identifier = عدم;
    ts->len = len;
    ts->hash_بل = عدم;
    حافظه_نقل(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    أرجع ts;
}

#تعریف_کړه TOK_HASH_INIT 1
#تعریف_کړه TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحيح len)
{
    TokenSym *ts, **pts;
    صحيح i;
    بینښه صحيح h;
    
    h = TOK_HASH_INIT;
    لكل(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((بینښه حرف *)str)[i]);
    h &= (TOK_HASH_اندازه - 1);

    pts = &hash_ident[h];
    لكل(;;) {
        ts = *pts;
        إذا (!ts)
            اكسر;
        إذا (ts->len == len && !memcmp(ts->str, str, len))
            أرجع ts;
        pts = &(ts->hash_بل);
    }
    أرجع tok_alloc_new(pts, str, len);
}

ST_FUNC صحيح tok_alloc_const(ثابت حرف *str)
{
    أرجع tok_alloc(str, مزي_اوږدوالی(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ثابت حرف *get_tok_str(صحيح v, CValue *cv)
{
    حرف *p;
    صحيح i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.معلومات;

    بدل(v) {
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CLONG:
    حالة TOK_CULONG:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (بینښه اوږد اوږد)cv->i);
        اكسر;
    حالة TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    حالة TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        جمع_کړه_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        اكسر;
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        أرجع (حرف*)cv->str.معلومات;
    حالة TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    حالة TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        إذا (v == TOK_STR) {
            len = cv->str.اندازه - 1;
            لكل(i=0;i<len;i++)
                جمع_کړه_char(&cstr_buf, ((بینښه حرف *)cv->str.معلومات)[i]);
        } وإلا {
            len = (cv->str.اندازه / حجم(nwchar_t)) - 1;
            لكل(i=0;i<len;i++)
                جمع_کړه_char(&cstr_buf, ((nwchar_t *)cv->str.معلومات)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        اكسر;

    حالة TOK_CFLOAT:
        أرجع strcpy(p, "<float>");
    حالة TOK_CDOUBLE:
        أرجع strcpy(p, "<double>");
    حالة TOK_CLDOUBLE:
        أرجع strcpy(p, "<long double>");
    حالة TOK_LINENUM:
        أرجع strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    حالة TOK_LT:
        v = '<';
        اذهب addv;
    حالة TOK_GT:
        v = '>';
        اذهب addv;
    حالة TOK_DOTS:
        أرجع strcpy(p, "...");
    حالة TOK_A_SHL:
        أرجع strcpy(p, "<<=");
    حالة TOK_A_SAR:
        أرجع strcpy(p, ">>=");
    حالة TOK_EOF:
        أرجع strcpy(p, "<eof>");
    حالة 0: /* anonymous nameless symbols */
        أرجع strcpy(p, "<no name>");
    افتراضي:
        v &= ~(SYM_ډګر | SYM_STRUCT);
        إذا (v < TOK_IDENT) {
            /* search in two bytes table */
            ثابت بینښه حرف *q = tok_two_chars;
            طالما (*q) {
                إذا (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    أرجع cstr_buf.معلومات;
                }
                q += 3;
            }
            إذا (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                اكسر;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } وإلا إذا (v < tok_ident) {
            أرجع جدول_ident[v - TOK_IDENT]->str;
        } وإلا إذا (v >= SYM_لومړی_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_لومړی_ANOM);
        } وإلا {
            /* should never happen */
            أرجع عدم;
        }
        اكسر;
    }
    أرجع cstr_buf.معلومات;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ساكن صحيح handle_eob(فراغ)
{
    BufferedFile *bf = file;
    صحيح len;

    /* only tries to read if really end of buffer */
    إذا (bf->buf_ptr >= bf->buf_پای_ټکی) {
        إذا (bf->fd >= 0) {
#إذا defined(PARSE_DEBUG)
            len = 1;
#وإلا
            len = IO_BUF_اندازه;
#د_که_پای
            len = اقرأ(bf->fd, bf->بفر, len);
            إذا (len < 0)
                len = 0;
        } وإلا {
            len = 0;
        }
        ټول_بایټونه += len;
        bf->buf_ptr = bf->بفر;
        bf->buf_پای_ټکی = bf->بفر + len;
        *bf->buf_پای_ټکی = CH_EOB;
    }
    إذا (bf->buf_ptr < bf->buf_پای_ټکی) {
        أرجع bf->buf_ptr[0];
    } وإلا {
        bf->buf_ptr = bf->buf_پای_ټکی;
        أرجع CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ساكن صحيح بل_c(فراغ)
{
    صحيح ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    إذا (ch == CH_EOB && file->buf_ptr >= file->buf_پای_ټکی)
        ch = handle_eob();
    أرجع ch;
}

/* input with '\[\r]\n' handling. */
ساكن صحيح handle_stray_noerror(صحيح err)
{
    صحيح ch;
    طالما ((ch = بل_c()) == '\\') {
        ch = بل_c();
        إذا (ch == '\n') {
    newl:
            file->کرښه_عدد++;
        } وإلا {
            إذا (ch == '\r') {
                ch = بل_c();
                إذا (ch == '\n')
                    اذهب newl;
                *--file->buf_ptr = '\r';
            }
            إذا (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            أرجع *--file->buf_ptr = '\\';
        }
    }
    أرجع ch;
}

#تعریف_کړه ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ساكن صحيح handle_bs(uint8_t **p)
{
    صحيح c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    أرجع c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ساكن صحيح handle_stray(uint8_t **p)
{
    صحيح c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    أرجع c;
}

/* handle the complicated stray case */
#تعریف_کړه PEEKC(c, p)\
{\
    c = *++p;\
    إذا (c == '\\')\
        c = handle_stray(&p); \
}

ساكن صحيح skip_spaces(فراغ)
{
    صحيح ch;
    --file->buf_ptr;
    افعل {
        ch = ninp();
    } طالما (isidnum_جدول[ch - CH_EOF] & IS_SPC);
    أرجع ch;
}

/* single line C++ comments */
ساكن uint8_t *parse_کرښه_comment(uint8_t *p)
{
    صحيح c;
    لكل(;;) {
        لكل (;;) {
            c = *++p;
    redo:
            إذا (c == '\n' || c == '\\')
                اكسر;
            c = *++p;
            إذا (c == '\n' || c == '\\')
                اكسر;
        }
        إذا (c == '\n')
            اكسر;
        c = handle_bs(&p);
        إذا (c == CH_EOF)
            اكسر;
        إذا (c != '\\')
            اذهب redo;
    }
    أرجع p;
}

/* C comments */
ساكن uint8_t *parse_comment(uint8_t *p)
{
    صحيح c;
    لكل(;;) {
        /* fast skip loop */
        لكل(;;) {
            c = *++p;
        redo:
            إذا (c == '\n' || c == '*' || c == '\\')
                اكسر;
            c = *++p;
            إذا (c == '\n' || c == '*' || c == '\\')
                اكسر;
        }
        /* now we can handle all the cases */
        إذا (c == '\n') {
            file->کرښه_عدد++;
        } وإلا إذا (c == '*') {
            افعل {
                c = *++p;
            } طالما (c == '*');
            إذا (c == '\\')
                c = handle_bs(&p);
            إذا (c == '/')
                اكسر;
            اذهب check_eof;
        } وإلا {
            c = handle_bs(&p);
        check_eof:
            إذا (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            إذا (c != '\\')
                اذهب redo;
        }
    }
    أرجع p + 1;
}

/* parse a string without interpreting escapes */
ساكن uint8_t *parse_pp_string(uint8_t *p, صحيح sep, CString *str)
{
    صحيح c;
    لكل(;;) {
        c = *++p;
    redo:
        إذا (c == sep) {
            اكسر;
        } وإلا إذا (c == '\\') {
            c = handle_bs(&p);
            إذا (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } وإلا إذا (c == '\\') {
                إذا (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                إذا (c == '\\') {
                    c = handle_bs(&p);
                    إذا (c == CH_EOF)
                        اذهب unterminated_string;
                }
                اذهب جمع_کړه_char;
            } وإلا {
                اذهب redo;
            }
        } وإلا إذا (c == '\n') {
        جمع_کړه_lf:
            إذا (ACCEPT_LF_دننه_مزي_ګانې) {
                file->کرښه_عدد++;
                اذهب جمع_کړه_char;
            } وإلا إذا (str) { /* not skipping */
                اذهب unterminated_string;
            } وإلا {
                //tcc_warning("missing terminating %c character", sep);
                أرجع p;
            }
        } وإلا إذا (c == '\r') {
            c = *++p;
            إذا (c == '\\')
                c = handle_bs(&p);
            إذا (c == '\n')
                اذهب جمع_کړه_lf;
            إذا (c == CH_EOF)
                اذهب unterminated_string;
            إذا (str)
                cstr_ccat(str, '\r');
            اذهب redo;
        } وإلا {
        جمع_کړه_char:
            إذا (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    أرجع p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ساكن فراغ preprocess_skip(فراغ)
{
    صحيح a, پیل_د_کرښه, c, دننه_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_پیل:
    پیل_د_کرښه = 1;
    دننه_warn_or_error = 0;
    لكل(;;) {
        c = *p;
        بدل(c) {
        حالة ' ':
        حالة '\t':
        حالة '\f':
        حالة '\v':
        حالة '\r':
            p++;
            استمر;
        حالة '\n':
            file->کرښه_عدد++;
            p++;
            اذهب redo_پیل;
        حالة '\\':
            c = handle_bs(&p);
            إذا (c == CH_EOF)
                expect("#endif");
            إذا (c == '\\')
                ++p;
            استمر;
        /* skip strings */
        حالة '\"':
        حالة '\'':
            إذا (دننه_warn_or_error)
                اذهب _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, عدم);
            اكسر;
        /* skip comments */
        حالة '/':
            إذا (دننه_warn_or_error)
                اذهب _default;
            ++p;
            c = handle_bs(&p);
            إذا (c == '*') {
                p = parse_comment(p);
            } وإلا إذا (c == '/') {
                p = parse_کرښه_comment(p);
            }
            استمر;
        حالة '#':
            p++;
            إذا (پیل_د_کرښه) {
                file->buf_ptr = p;
                بل_nomacro();
                p = file->buf_ptr;
                إذا (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    اذهب the_پای_ټکی;
                إذا (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                وإلا إذا (tok == TOK_ENDIF)
                    a--;
                وإلا إذا( tok == TOK_ERROR || tok == TOK_WARNING)
                    دننه_warn_or_error = 1;
                وإلا إذا (tok == TOK_LINEFEED)
                    اذهب redo_پیل;
                وإلا إذا (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_کرښه_comment(p - 1);
            }
#إذا !defined(TCC_موخه_ARM) && !defined(TCC_موخه_ARM64)
            وإلا إذا (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_کرښه_comment(p - 1);
#وإلا
            /* ARM/ARM64 assembly uses '#' for constants */
#د_که_پای
            اكسر;
_default:
        افتراضي:
            p++;
            اكسر;
        }
        پیل_د_کرښه = 0;
    }
 the_پای_ټکی: ;
    file->buf_ptr = p;
}

#إذا 0
/* return the number of additional 'ints' necessary to store the
   token */
ساكن مضمن صحيح tok_اندازه(ثابت صحيح *p)
{
    بدل(*p) {
        /* 4 bytes */
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_CFLOAT:
    حالة TOK_LINENUM:
        أرجع 1 + 1;
    حالة TOK_STR:
    حالة TOK_LSTR:
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        أرجع 1 + 1 + (p[1] + 3) / 4;
    حالة TOK_CLONG:
    حالة TOK_CULONG:
	أرجع 1 + LONG_اندازه / 4;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
        أرجع 1 + 2;
    حالة TOK_CLDOUBLE:
        أرجع 1 + LDOUBLE_ټکي;
    افتراضي:
        أرجع 1 + 0;
    }
}
#د_که_پای

/* token string handling */
ST_INLN فراغ tok_str_new(TokenString *s)
{
    s->str = عدم;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->وروستی_کرښه_عدد = -1;
}

ST_FUNC TokenString *tok_str_alloc(فراغ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, حجم *str);
    tok_str_new(str);
    أرجع str;
}

ST_FUNC فراغ tok_str_free_str(صحيح *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC فراغ tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC صحيح *tok_str_realloc(TokenString *s, صحيح new_اندازه)
{
    صحيح *str, اندازه;

    اندازه = s->allocated_len;
    إذا (اندازه < 16)
        اندازه = 16;
    طالما (اندازه < new_اندازه)
        اندازه = اندازه * 2;
    إذا (اندازه > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, اندازه * حجم(صحيح));
        s->allocated_len = اندازه;
        s->str = str;
    }
    أرجع s->str;
}

ST_FUNC فراغ tok_str_جمع_کړه(TokenString *s, صحيح t)
{
    صحيح len, *str;

    len = s->len;
    str = s->str;
    إذا (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC فراغ begin_macro(TokenString *str, صحيح alloc)
{
    str->alloc = alloc;
    str->prev = macro_ډېری;
    str->prev_ptr = macro_ptr;
    str->save_کرښه_عدد = file->کرښه_عدد;
    macro_ptr = str->str;
    macro_ډېری = str;
}

ST_FUNC فراغ پای_ټکی_macro(فراغ)
{
    TokenString *str = macro_ډېری;
    macro_ډېری = str->prev;
    macro_ptr = str->prev_ptr;
    file->کرښه_عدد = str->save_کرښه_عدد;
    إذا (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } وإلا {
        إذا (str->alloc == 2)
            str->str = عدم; /* don't free */
        tok_str_free(str);
    }
}

ساكن فراغ tok_str_add2(TokenString *s, صحيح t, CValue *cv)
{
    صحيح len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    إذا (len + TOK_MAX_اندازه >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_اندازه + 1);
    str[len++] = t;
    بدل(t) {
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_CFLOAT:
    حالة TOK_LINENUM:
#إذا LONG_اندازه == 4
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#د_که_پای
        str[len++] = cv->tab[0];
        اكسر;
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
    حالة TOK_STR:
    حالة TOK_LSTR:
        {
            /* Insert the string into the int array. */
            اندازه_t nb_ټکي =
                1 + (cv->str.اندازه + حجم(صحيح) - 1) / حجم(صحيح);
            إذا (len + nb_ټکي >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_ټکي + 1);
            str[len] = cv->str.اندازه;
            حافظه_نقل(&str[len + 1], cv->str.معلومات, cv->str.اندازه);
            len += nb_ټکي;
        }
        اكسر;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
#إذا LONG_اندازه == 8
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#د_که_پای
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        اكسر;
    حالة TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        إذا (LDOUBLE_ټکي >= 3)
        str[len++] = cv->tab[2];
        إذا (LDOUBLE_ټکي >= 4)
        str[len++] = cv->tab[3];
    افتراضي:
        اكسر;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC فراغ tok_str_جمع_کړه_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    إذا (file->کرښه_عدد != s->وروستی_کرښه_عدد) {
        s->وروستی_کرښه_عدد = file->کرښه_عدد;
        cval.i = s->وروستی_کرښه_عدد;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ساكن فراغ tok_str_add2_spc(TokenString *s, صحيح t, CValue *cv)
{
    إذا (s->need_spc == 3)
        tok_str_جمع_کړه(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ساكن مضمن فراغ tok_get(صحيح *t, ثابت صحيح **pp, CValue *cv)
{
    ثابت صحيح *p = *pp;
    صحيح n, *tab;

    tab = cv->tab;
    بدل(*t = *p++) {
#إذا LONG_اندازه == 4
    حالة TOK_CLONG:
#د_که_پای
    حالة TOK_CINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_LINENUM:
        cv->i = *p++;
        اكسر;
#إذا LONG_اندازه == 4
    حالة TOK_CULONG:
#د_که_پای
    حالة TOK_CUINT:
        cv->i = (بینښه)*p++;
        اكسر;
    حالة TOK_CFLOAT:
	tab[0] = *p++;
	اكسر;
    حالة TOK_STR:
    حالة TOK_LSTR:
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        cv->str.اندازه = *p++;
        cv->str.معلومات = (حرف*)p;
        p += (cv->str.اندازه + حجم(صحيح) - 1) / حجم(صحيح);
        اكسر;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
#إذا LONG_اندازه == 8
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#د_که_پای
        n = 2;
        اذهب copy;
    حالة TOK_CLDOUBLE:
        n = LDOUBLE_ټکي;
    copy:
        افعل
            *tab++ = *p++;
        طالما (--n);
        اكسر;
    افتراضي:
        اكسر;
    }
    *pp = p;
}

#إذا 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#وإلا
# define TOK_GET(t,p,c) افعل { \
    صحيح _t = **(p); \
    إذا (TOK_HAS_ارزښت(_t)) \
        tok_get(t, p, c); \
    وإلا \
        *(t) = _t, ++*(p); \
    } طالما (0)
#د_که_پای

ساكن صحيح macro_is_equal(ثابت صحيح *a, ثابت صحيح *b)
{
    CValue cv;
    صحيح t;

    إذا (!a || !b)
        أرجع 1;

    طالما (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        إذا (strcmp(tokcstr.معلومات, get_tok_str(t, &cv)))
            أرجع 0;
    }
    أرجع !(*a || *b);
}

/* defines handling */
ST_INLN فراغ define_ټېل(صحيح v, صحيح macro_type, صحيح *str, Sym *لومړی_arg)
{
    Sym *s, *o;

    o = define_پیدا_کړه(v);
    s = sym_push2(&define_ډېری, v, macro_type, 0);
    s->d = str;
    s->بل = لومړی_arg;
    جدول_ident[v - TOK_IDENT]->sym_define = s;

    إذا (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, عدم));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC فراغ define_undef(Sym *s)
{
    صحيح v = s->v;
    إذا (v >= TOK_IDENT && v < tok_ident)
        جدول_ident[v - TOK_IDENT]->sym_define = عدم;
}

ST_INLN Sym *define_پیدا_کړه(صحيح v)
{
    v -= TOK_IDENT;
    إذا ((بینښه)v >= (بینښه)(tok_ident - TOK_IDENT))
        أرجع عدم;
    أرجع جدول_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC فراغ free_تعریفوي(Sym *b)
{
    طالما (define_ډېری != b) {
        Sym *سر = define_ډېری;
        define_ډېری = سر->prev;
        tok_str_free_str(سر->d);
        define_undef(سر);
        sym_free(سر);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ساكن فراغ maybe_پرلپسې_test(TCCState *s)
{
    ثابت حرف *p;
    إذا (s->include_ډېری_ptr != s->include_ډېری)
        أرجع;
    p = get_tok_str(tok, عدم);
    إذا (0 != memcmp(p, "test_", 5))
        أرجع;
    إذا (0 != --s->پرلپسې_test)
        أرجع;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ټېل(tok, MACRO_OBJ, عدم, عدم);
}

ST_FUNC فراغ skip_منزل_eol(صحيح warn)
{
    إذا (tok == TOK_LINEFEED)
        أرجع;
    إذا (warn)
        tcc_warning("extra tokens after directive");
    طالما (macro_ډېری)
        پای_ټکی_macro();
    file->buf_ptr = parse_کرښه_comment(file->buf_ptr - 1);
    بل_nomacro();
}

ساكن CachedInclude *
پلټنه_cached_include(TCCState *s1, ثابت حرف *filename, صحيح جمع_کړه);

ساكن صحيح parse_include(TCCState *s1, صحيح do_بل, صحيح test)
{
    صحيح c, i;
    حرف name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    إذا (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.اندازه;
        pstrncpy(name, حجم name, tokcstr.معلومات, i);
        بل_nomacro();
    } وإلا {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        لكل (;;) {
            بل();
            p = name, i = مزي_اوږدوالی(p) - 1;
            إذا (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                اكسر;
            إذا (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, حجم name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    إذا (!test)
        skip_منزل_eol(1);

    i = do_بل ? file->include_بل_شاخص : -1;
    لكل (;;) {
        ++i;
        إذا (i == 0) {
            /* check absolute include path */
            إذا (!IS_ABSPATH(name))
                استمر;
            buf[0] = '\0';
        } وإلا إذا (i == 1) {
            /* search in file's dir if "header.h" */
            إذا (c != '\"')
                استمر;
            p = file->true_filename;
            pstrncpy(buf, حجم buf, p, tcc_basename(p) - p);
        } وإلا {
            صحيح j = i - 2, k = j - s1->nb_include_paths;
            إذا (k < 0)
                p = s1->include_paths[j];
            وإلا إذا (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            وإلا إذا (test)
                أرجع 0;
            وإلا
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, حجم buf, p);
            pstrcat(buf, حجم buf, "/");
        }
        pstrcat(buf, حجم buf, name);
        e = پلټنه_cached_include(s1, buf, 0);
        إذا (e && (define_پیدا_کړه(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#که_تعریف_شوی INC_DEBUG
            چاپ_کړه("%s: skipping cached %s\n", file->filename, buf);
#د_که_پای
            إذا ((s1->verbose | 1) == 3) /* -vv[v] */
                چاپ_کړه("=> %*s%s\n",
                   (صحيح)(s1->include_ډېری_ptr - s1->include_ډېری), "", buf);
            أرجع 1;
        }
        إذا (tcc_open(s1, buf) >= 0)
            اكسر;
    }

    إذا (test) {
        tcc_close();
    } وإلا {
        إذا (s1->include_ډېری_ptr >= s1->include_ډېری + INCLUDE_ډېری_اندازه)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ډېری_ptr++ = file->prev;
        file->include_بل_شاخص = i;
#که_تعریف_شوی INC_DEBUG
        چاپ_کړه("%s: including %s\n", file->prev->filename, file->filename);
#د_که_پای
        /* update target deps */
        إذا (s1->gen_deps) {
            BufferedFile *bf = file;
            طالما (i == 1 && (bf = bf->prev))
                i = bf->include_بل_شاخص;
            /* skip system include files */
            إذا (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_جمع_کړه(&s1->موخه_deps, &s1->nb_موخه_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    أرجع 1;
}

/* eval an expression for #if/#elif */
ساكن صحيح بیان_preprocess(TCCState *s1)
{
    صحيح c, t;
    صحيح t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_بیان = 1;
    طالما (1) {
        بل(); /* do macro subst */
        t = tok;
        إذا (tok < TOK_IDENT) {
            إذا (tok == TOK_LINEFEED || tok == TOK_EOF)
                اكسر;
            إذا (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } وإلا إذا (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            بل();
            t = tok;
            إذا (t == '(') 
                بل();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            إذا (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            إذا (s1->پرلپسې_test)
                maybe_پرلپسې_test(s1);
            c = 0;
            إذا (define_پیدا_کړه(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_بل)
                c = 1;
            إذا (t == '(') {
                بل();
                إذا (tok != ')')
                    expect("')'");
            }
            اذهب c_شمېره;
        } وإلا إذا (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_بل) {
            t = tok;
            بل();
	    إذا (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            إذا (tok != ')')
                expect("')'");
            اذهب c_شمېره;
        } وإلا {
            /* if undefined macro, replace with zero */
            c = 0;
        c_شمېره:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_جمع_کړه_tok(str);
    }
    إذا (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_جمع_کړه(str, TOK_EOF); /* simulate end of file */
    pp_بیان = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    بل();
    c = بیان_const();
    إذا (tok != TOK_EOF)
        tcc_error("...");
    pp_بیان = 0;
    پای_ټکی_macro();
    tok = t; /* restore LF or EOF */
    أرجع c != 0;
}

ST_FUNC فراغ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_بیان, 0));
    macro_ptr = macro_ډېری->str;
    طالما (بل(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC فراغ parse_define(فراغ)
{
    Sym *s, *لومړی, **ps;
    صحيح v, t, varg, is_vaargs, t0;
    صحيح saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    إذا (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    لومړی = عدم;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    بل_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    إذا (tok == '(') {
        صحيح dotid = سېټ_idnum('.', 0);
        بل_nomacro();
        ps = &لومړی;
        إذا (tok != ')') لكل (;;) {
            varg = tok;
            بل_nomacro();
            is_vaargs = 0;
            إذا (varg == TOK_DOTS) {
                varg = TOK_VA_دلیلونه;
                is_vaargs = 1;
            } وإلا إذا (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                بل_nomacro();
            }
            إذا (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ډېری, varg | SYM_ډګر, is_vaargs, 0);
            *ps = s;
            ps = &s->بل;
            إذا (tok == ')')
                اكسر;
            إذا (tok != ',' || is_vaargs)
                اذهب bad_list;
            بل_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        بل_nomacro();
        t = MACRO_FUNC;
        سېټ_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    طالما (tok != TOK_LINEFEED && tok != TOK_EOF) {
        إذا (is_space(tok)) {
            str.need_spc |= 1;
        } وإلا {
            إذا (TOK_TWOSHARPS == tok) {
                إذا (0 == t0)
                    اذهب bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        بل_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_جمع_کړه(&str, 0);
    إذا (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ټېل(v, t, str.str, لومړی);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ساكن CachedInclude *پلټنه_cached_include(TCCState *s1, ثابت حرف *filename, صحيح جمع_کړه)
{
    ثابت حرف *s, *basename;
    بینښه صحيح h;
    CachedInclude *e;
    صحيح c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    طالما ((c = (بینښه حرف)*s) != 0) {
#که_تعریف_شوی _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#وإلا
        h = TOK_HASH_FUNC(h, c);
#د_که_پای
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_اندازه - 1);

    i = s1->cached_includes_hash[h];
    لكل(;;) {
        إذا (i == 0)
            اكسر;
        e = s1->cached_includes[i - 1];
        إذا (0 == PATHCMP(filename, e->filename))
            أرجع e;
        إذا (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            أرجع e;
        i = e->hash_بل;
    }
    إذا (!جمع_کړه)
        أرجع عدم;

    e = tcc_malloc(حجم(CachedInclude) + (len = مزي_اوږدوالی(filename)));
    حافظه_نقل(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_جمع_کړه(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_بل = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#که_تعریف_شوی INC_DEBUG
    چاپ_کړه("adding cached '%s'\n", filename);
#د_که_پای
    أرجع e;
}

ساكن صحيح pragma_parse(TCCState *s1)
{
    بل_nomacro();
    إذا (tok == TOK_ټېل_macro || tok == TOK_راوباسه_macro) {
        صحيح t = tok, v;
        Sym *s;

        إذا (بل(), tok != '(')
            اذهب pragma_err;
        إذا (بل(), tok != TOK_STR)
            اذهب pragma_err;
        v = tok_alloc(tokc.str.معلومات, tokc.str.اندازه - 1)->tok;
        إذا (بل(), tok != ')')
            اذهب pragma_err;
        إذا (t == TOK_ټېل_macro) {
            طالما (عدم == (s = define_پیدا_کړه(v)))
                define_ټېل(v, 0, عدم, عدم);
            s->type.ref = s; /* set push boundary */
        } وإلا {
            لكل (s = define_ډېری; s; s = s->prev)
                إذا (s->v == v && s->type.ref == s) {
                    s->type.ref = عدم;
                    اكسر;
                }
        }
        إذا (s)
            جدول_ident[v - TOK_IDENT]->sym_define = s->d ? s : عدم;
        وإلا
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } وإلا إذا (tok == TOK_once) {
        پلټنه_cached_include(s1, file->true_filename, 1)->once = 1;

    } وإلا إذا (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        أرجع 1;

    } وإلا إذا (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        بل();
        skip('(');
        إذا (tok == TOK_ASM_راوباسه) {
            بل();
            إذا (s1->pack_ډېری_ptr <= s1->pack_ډېری) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ډېری_ptr--;
        } وإلا {
            صحيح val = 0;
            إذا (tok != ')') {
                إذا (tok == TOK_ASM_ټېل) {
                    بل();
                    إذا (s1->pack_ډېری_ptr >= s1->pack_ډېری + PACK_ډېری_اندازه - 1)
                        اذهب stk_error;
                    val = *s1->pack_ډېری_ptr++;
                    إذا (tok != ',')
                        اذهب pack_سېټ;
                    بل();
                }
                إذا (tok != TOK_CINT)
                    اذهب pragma_err;
                val = tokc.i;
                إذا (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    اذهب pragma_err;
                بل();
            }
        pack_سېټ:
            *s1->pack_ډېری_ptr = val;
        }
        إذا (tok != ')')
            اذهب pragma_err;

    } وإلا إذا (tok == TOK_comment) {
        حرف *p; صحيح t;
        بل();
        skip('(');
        t = tok;
        بل();
        skip(',');
        إذا (tok != TOK_STR)
            اذهب pragma_err;
        p = tcc_strdup(tokc.str.معلومات);
        بل();
        إذا (tok != ')')
            اذهب pragma_err;
        إذا (t == TOK_lib) {
            dynarray_جمع_کړه(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } وإلا {
            إذا (t == TOK_option)
                tcc_سېټ_options(s1, p);
            tcc_free(p);
        }

    } وإلا {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        أرجع 0;
    }
    بل();
    أرجع 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename)
{
    حرف buf[1024];
    buf[0] = 0;
    إذا (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, حجم buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, حجم buf, filename);
#که_تعریف_شوی _WIN32
    normalize_slashes(buf);
#د_که_پای
    إذا (0 == strcmp(file->filename, buf))
        أرجع;
    //printf("new file '%s'\n", buf);
    إذا (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, حجم file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC فراغ preprocess(صحيح is_bof)
{
    TCCState *s1 = tcc_state;
    صحيح c, n, saved_parse_flags;
    حرف buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_عدد
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    بل_nomacro();
 redo:
    بدل(tok) {
    حالة TOK_DEFINE:
        pp_debug_tok = tok;
        بل_nomacro();
        pp_debug_symv = tok;
        parse_define();
        اكسر;
    حالة TOK_UNDEF:
        pp_debug_tok = tok;
        بل_nomacro();
        pp_debug_symv = tok;
        s = define_پیدا_کړه(tok);
        /* undefine symbol by putting an invalid name */
        إذا (s)
            define_undef(s);
        بل_nomacro();
        اكسر;
    حالة TOK_INCLUDE:
    حالة TOK_INCLUDE_بل:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        اذهب the_پای_ټکی;
    حالة TOK_IFNDEF:
        c = 1;
        اذهب do_ifdef;
    حالة TOK_IF:
        c = بیان_preprocess(s1);
        اذهب do_if;
    حالة TOK_IFDEF:
        c = 0;
    do_ifdef:
        بل_nomacro();
        إذا (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        إذا (is_bof) {
            إذا (c) {
#که_تعریف_شوی INC_DEBUG
                چاپ_کړه("#ifndef %s\n", get_tok_str(tok, عدم));
#د_که_پای
                file->ifndef_macro = tok;
            }
        }
        إذا (define_پیدا_کړه(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_بل)
            c ^= 1;
        بل_nomacro();
    do_if:
        إذا (s1->ifdef_ډېری_ptr >= s1->ifdef_ډېری + IFDEF_ډېری_اندازه)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ډېری_ptr++ = c;
        اذهب test_skip;
    حالة TOK_ELSE:
        بل_nomacro();
        إذا (s1->ifdef_ډېری_ptr == s1->ifdef_ډېری)
            tcc_error("#else without matching #if");
        إذا (s1->ifdef_ډېری_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ډېری_ptr[-1] ^= 3);
        اذهب test_else;
    حالة TOK_ELIF:
        إذا (s1->ifdef_ډېری_ptr == s1->ifdef_ډېری)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ډېری_ptr[-1];
        إذا (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        إذا (c == 1) {
            skip_منزل_eol(0);
            c = 0;
        } وإلا {
            c = بیان_preprocess(s1);
            s1->ifdef_ډېری_ptr[-1] = c;
        }
    test_else:
        إذا (s1->ifdef_ډېری_ptr == file->ifdef_ډېری_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        إذا (!(c & 1)) {
            skip_منزل_eol(1);
            preprocess_skip();
            is_bof = 0;
            اذهب redo;
        }
        اكسر;
    حالة TOK_ENDIF:
        بل_nomacro();
        إذا (s1->ifdef_ډېری_ptr <= file->ifdef_ډېری_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ډېری_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        إذا (file->ifndef_macro &&
            s1->ifdef_ډېری_ptr == file->ifdef_ډېری_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        اكسر;

    حالة TOK_کرښه:
        parse_flags &= ~PARSE_FLAG_TOK_عدد;
        بل();
        إذا (tok != TOK_PPNUM) {
    کرښه_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        اذهب کرښه_عدد_2;
    حالة TOK_PPNUM:
        إذا (parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب ignore;
        c = 0; /* no error with extra tokens */
    کرښه_عدد_2:
        لكل (n = 0, q = tokc.str.معلومات; *q; ++q) {
            إذا (!isnum(*q))
                اذهب کرښه_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        بل();
        إذا (tok != TOK_LINEFEED) {
            إذا (tok != TOK_PPSTR || tokc.str.معلومات[0] != '"')
                اذهب کرښه_err;
            tokc.str.معلومات[tokc.str.اندازه - 2] = 0;
            tccpp_putfile(tokc.str.معلومات + 1);
            بل();
            /* skip optional level number & advance to next line */
            skip_منزل_eol(c);
        }
        إذا (file->fd > 0)
            ټول_کرښې += file->کرښه_عدد - n;
        file->کرښه_عدد = n;
        اكسر;

    حالة TOK_ERROR:
    حالة TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        طالما (c != '\n' && c != CH_EOF) {
            إذا ((q - buf) < حجم(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        إذا (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        وإلا
            tcc_warning("#warning %s", buf);
        بل_nomacro();
        اكسر;
    }
    حالة TOK_PRAGMA:
        إذا (!pragma_parse(s1))
            اذهب ignore;
        اكسر;
    حالة TOK_LINEFEED:
        اذهب the_پای_ټکی;
    افتراضي:
        /* ignore gas line comment in an 'S' file. */
        إذا (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب ignore;
        إذا (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            اذهب ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_منزل_eol(0);
        اذهب the_پای_ټکی;
    }
    skip_منزل_eol(1);
 the_پای_ټکی:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ساكن فراغ parse_escape_string(CString *outstr, ثابت uint8_t *buf, صحيح is_long)
{
    صحيح c, n, i;
    ثابت uint8_t *p;

    p = buf;
    لكل(;;) {
        c = *p;
        إذا (c == '\0')
            اكسر;
        إذا (c == '\\') {
            p++;
            /* escape */
            c = *p;
            بدل(c) {
            حالة '0': حالة '1': حالة '2': حالة '3':
            حالة '4': حالة '5': حالة '6': حالة '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                إذا (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    إذا (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                اذهب جمع_کړه_char_nonext;
            حالة 'x': i = 0; اذهب parse_hex_or_ucn;
            حالة 'u': i = 4; اذهب parse_hex_or_ucn;
            حالة 'U': i = 8; اذهب parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                افعل {
                    c = *p;
                    إذا (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    وإلا إذا (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    وإلا إذا (isnum(c))
                        c = c - '0';
                    وإلا إذا (i >= 0)
                        expect("more hex digits in universal-character-name");
                    وإلا
                        اذهب جمع_کړه_hex_or_ucn;
                    n = (بینښه) n * 16 + c;
                    p++;
                } طالما (--i);
		إذا (is_long) {
    جمع_کړه_hex_or_ucn:
                    c = n;
		    اذهب جمع_کړه_char_nonext;
		}
                cstr_u8cat(outstr, n);
                استمر;
            حالة 'a':
                c = '\a';
                اكسر;
            حالة 'b':
                c = '\b';
                اكسر;
            حالة 'f':
                c = '\f';
                اكسر;
            حالة 'n':
                c = '\n';
                اكسر;
            حالة 'r':
                c = '\r';
                اكسر;
            حالة 't':
                c = '\t';
                اكسر;
            حالة 'v':
                c = '\v';
                اكسر;
            حالة 'e':
                إذا (!gnu_ext)
                    اذهب invalid_escape;
                c = 27;
                اكسر;
            حالة '\'':
            حالة '\"':
            حالة '\\': 
            حالة '?':
                اكسر;
            افتراضي:
            invalid_escape:
                إذا (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                وإلا
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                اكسر;
            }
        } وإلا إذا (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            صحيح cont; /* count of continuation bytes */
            صحيح skip; /* how many bytes should skip when error occurred */
            صحيح i;

            /* decode leading byte */
            إذا (c < 0xC2) {
	            skip = 1; اذهب invalid_utf8_sequence;
            } وإلا إذا (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } وإلا إذا (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } وإلا إذا (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } وإلا {
	            skip = 1; اذهب invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            لكل (i = 1; i <= cont; i++) {
                صحيح l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                إذا (i == 1) {
                    بدل (c) {
                    حالة 0xE0: l = 0xA0; اكسر;
                    حالة 0xED: h = 0x9F; اكسر;
                    حالة 0xF0: l = 0x90; اكسر;
                    حالة 0xF4: h = 0x8F; اكسر;
                    }
                }

                إذا (p[i] < l || p[i] > h) {
                    skip = i; اذهب invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            اذهب جمع_کړه_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            اذهب جمع_کړه_char_nonext;

        }
        p++;
    جمع_کړه_char_nonext:
        إذا (!is_long)
            cstr_ccat(outstr, c);
        وإلا {
#که_تعریف_شوی TCC_موخه_PE
            /* store as UTF-16 */
            إذا (c < 0x10000) {
                cstr_wccat(outstr, c);
            } وإلا {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#وإلا
            cstr_wccat(outstr, c);
#د_که_پای
        }
    }
    /* add a trailing '\0' */
    إذا (!is_long)
        cstr_ccat(outstr, '\0');
    وإلا
        cstr_wccat(outstr, '\0');
}

ساكن فراغ parse_string(ثابت حرف *s, صحيح len)
{
    uint8_t buf[1000], *p = buf;
    صحيح is_long, sep;

    إذا ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    إذا (len >= حجم buf)
        p = tcc_malloc(len + 1);
    حافظه_نقل(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    إذا (p != buf)
        tcc_free(p);

    إذا (sep == '\'') {
        صحيح char_اندازه, i, n, c;
        /* XXX: make it portable */
        إذا (!is_long)
            tok = TOK_CCHAR, char_اندازه = 1;
        وإلا
            tok = TOK_LCHAR, char_اندازه = حجم(nwchar_t);
        n = tokcstr.اندازه / char_اندازه - 1;
        إذا (n < 1)
            tcc_error("empty character constant");
        إذا (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        لكل (c = i = 0; i < n; ++i) {
            إذا (is_long)
                c = ((nwchar_t *)tokcstr.معلومات)[i];
            وإلا
                c = (c << 8) | ((حرف *)tokcstr.معلومات)[i];
        }
        tokc.i = c;
    } وإلا {
        tokc.str.اندازه = tokcstr.اندازه;
        tokc.str.معلومات = tokcstr.معلومات;
        إذا (!is_long)
            tok = TOK_STR;
        وإلا
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#تعریف_کړه BN_اندازه 4

/* bn = (bn << shift) | or_val */
ساكن صحيح bn_lshift(بینښه صحيح *bn, صحيح ښويدنه, صحيح or_val)
{
    صحيح i;
    بینښه صحيح v;
    إذا (bn[BN_اندازه - 1] >> (32 - ښويدنه))
	أرجع ښويدنه;
    لكل(i=0;i<BN_اندازه;i++) {
        v = bn[i];
        bn[i] = (v << ښويدنه) | or_val;
        or_val = v >> (32 - ښويدنه);
    }
    أرجع 0;
}

ساكن فراغ bn_zero(بینښه صحيح *bn)
{
    صحيح i;
    لكل(i=0;i<BN_اندازه;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ساكن فراغ parse_شمېره(ثابت حرف *p)
{
    صحيح b, t, ښويدنه, frac_بټونه, s, exp_val, ch;
    حرف *q;
    بینښه صحيح bn[BN_اندازه];
    اوږد مزدوج d;

    /*شمېره*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    إذا (t == '.') {
        اذهب float_frac_parse;
    } وإلا إذا (t == '0') {
        إذا (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } وإلا إذا (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    طالما (1) {
        إذا (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        وإلا إذا (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        وإلا إذا (isnum(ch))
            t = ch - '0';
        وإلا
            اكسر;
        إذا (t >= b)
            اكسر;
        إذا (q >= token_buf + STRING_MAX_اندازه) {
        عدد_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    إذا (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        إذا (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_بټونه = 0;
            *q = '\0';
            إذا (b == 16)
                ښويدنه = 4;
            وإلا 
                ښويدنه = 1;
            bn_zero(bn);
            q = token_buf;
            طالما (1) {
                t = *q++;
                إذا (t == '\0') {
                    اكسر;
                } وإلا إذا (t >= 'a') {
                    t = t - 'a' + 10;
                } وإلا إذا (t >= 'A') {
                    t = t - 'A' + 10;
                } وإلا {
                    t = t - '0';
                }
                frac_بټونه -= bn_lshift(bn, ښويدنه, t);
            }
            إذا (ch == '.') {
                ch = *p++;
                طالما (1) {
                    t = ch;
                    إذا (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } وإلا إذا (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } وإلا إذا (t >= '0' && t <= '9') {
                        t = t - '0';
                    } وإلا {
                        اكسر;
                    }
                    إذا (t >= b)
                        tcc_error("invalid digit");
                    frac_بټونه -= bn_lshift(bn, ښويدنه, t);
                    frac_بټونه += ښويدنه;
                    ch = *p++;
                }
            }
            إذا (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            إذا (ch == '+') {
                ch = *p++;
            } وإلا إذا (ch == '-') {
                s = -1;
                ch = *p++;
            }
            إذا (ch < '0' || ch > '9')
                expect("exponent digits");
            طالما (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		إذا (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (اوږد مزدوج)bn[3] * 79228162514264337593543950336.0L +
	        (اوږد مزدوج)bn[2] * 18446744073709551616.0L +
	        (اوږد مزدوج)bn[1] * 4294967296.0L +
	        (اوږد مزدوج)bn[0];
            d = ldexpl(d, exp_val - frac_بټونه);
            t = toup(ch);
            إذا (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (عائم)d;
            } وإلا إذا (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } وإلا {
                tok = TOK_CDOUBLE;
                tokc.d = (مزدوج)d;
            }
        } وإلا {
            /* decimal floats */
            إذا (ch == '.') {
                إذا (q >= token_buf + STRING_MAX_اندازه)
                    اذهب عدد_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                طالما (ch >= '0' && ch <= '9') {
                    إذا (q >= token_buf + STRING_MAX_اندازه)
                        اذهب عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            إذا (ch == 'e' || ch == 'E') {
                إذا (q >= token_buf + STRING_MAX_اندازه)
                    اذهب عدد_too_long;
                *q++ = ch;
                ch = *p++;
                إذا (ch == '-' || ch == '+') {
                    إذا (q >= token_buf + STRING_MAX_اندازه)
                        اذهب عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                إذا (ch < '0' || ch > '9')
                    expect("exponent digits");
                طالما (ch >= '0' && ch <= '9') {
                    إذا (q >= token_buf + STRING_MAX_اندازه)
                        اذهب عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            إذا (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, عدم);
            } وإلا إذا (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, عدم);
            } وإلا {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, عدم);
            }
        }
    } وإلا {
        بینښه اوږد اوږد n, n1;
        صحيح lcount, ucount, ov = 0;
        ثابت حرف *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        إذا (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        طالما(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            إذا (t == '\0')
                اكسر;
            وإلا إذا (t >= 'a')
                t = t - 'a' + 10;
            وإلا إذا (t >= 'A')
                t = t - 'A' + 10;
            وإلا
                t = t - '0';
            إذا (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            إذا (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        لكل(;;) {
            t = toup(ch);
            إذا (t == 'L') {
                إذا (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                إذا (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } وإلا إذا (t == 'U') {
                إذا (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } وإلا {
                اكسر;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        إذا (pp_بیان)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        إذا (ucount == 0 && b == 10) {
            إذا (lcount <= (LONG_اندازه == 4)) {
                إذا (n >= 0x80000000U)
                    lcount = (LONG_اندازه == 4) + 1;
            }
            إذا (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } وإلا {
            إذا (lcount <= (LONG_اندازه == 4)) {
                إذا (n >= 0x100000000ULL)
                    lcount = (LONG_اندازه == 4) + 1;
                وإلا إذا (n >= 0x80000000U)
                    ucount = 1;
            }
            إذا (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        إذا (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	إذا (lcount) {
            tok = TOK_CLONG;
            إذا (lcount == 2)
                tok = TOK_CLLONG;
	}
	إذا (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    إذا (ch)
        tcc_error("invalid number");
}


#تعریف_کړه PARSE2(c1, tok1, c2, tok2)              \
    حالة c1:                                    \
        PEEKC(c, p);                            \
        إذا (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } وإلا {                                \
            tok = tok1;                         \
        }                                       \
        اكسر;

/* return next token without macro substitution */
ساكن فراغ بل_nomacro(فراغ)
{
    صحيح t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    بینښه صحيح h;

    p = file->buf_ptr;
 redo_no_پیل:
    c = *p;
    بدل(c) {
    حالة ' ':
    حالة '\t':
        tok = c;
        p++;
 maybe_space:
        إذا (parse_flags & PARSE_FLAG_SPACES)
            اذهب keep_tok_flags;
        طالما (isidnum_جدول[*p - CH_EOF] & IS_SPC)
            ++p;
        اذهب redo_no_پیل;
    حالة '\f':
    حالة '\v':
    حالة '\r':
        p++;
        اذهب redo_no_پیل;
    حالة '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        إذا (c == '\\')
            اذهب parse_simple;
        إذا (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            إذا (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                اذهب maybe_newline;
            } وإلا إذا (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } وإلا إذا (s1->ifdef_ډېری_ptr != file->ifdef_ډېری_ptr) {
                tcc_error("missing #endif");
            } وإلا إذا (s1->include_ډېری_ptr == s1->include_ډېری) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } وإلا {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                إذا (tok_flags & TOK_FLAG_ENDIF) {
#که_تعریف_شوی INC_DEBUG
                    چاپ_کړه("#endif %s\n", get_tok_str(file->ifndef_macro_saved, عدم));
#د_که_پای
                    پلټنه_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ډېری_ptr--;
                p = file->buf_ptr;
                اذهب maybe_newline;
            }
        } وإلا {
            اذهب redo_no_پیل;
        }
        اكسر;

    حالة '\n':
        file->کرښه_عدد++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        إذا (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            اذهب redo_no_پیل;
        tok = TOK_LINEFEED;
        اذهب keep_tok_flags;

    حالة '#':
        /* XXX: simplify */
        PEEKC(c, p);
        إذا ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            اذهب maybe_newline;
        } وإلا {
            إذا (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } وإلا {
#إذا !defined(TCC_موخه_ARM) && !defined(TCC_موخه_ARM64)
                إذا (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_کرښه_comment(p - 1);
                    اذهب redo_no_پیل;
                } وإلا
#د_که_پای
                {
                    tok = '#';
                }
            }
        }
        اكسر;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    حالة '$':
        إذا (!(isidnum_جدول['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            اذهب parse_simple;

    حالة 'a': حالة 'b': حالة 'c': حالة 'd':
    حالة 'e': حالة 'f': حالة 'g': حالة 'h':
    حالة 'i': حالة 'j': حالة 'k': حالة 'l':
    حالة 'm': حالة 'n': حالة 'o': حالة 'p':
    حالة 'q': حالة 'r': حالة 's': حالة 't':
    حالة 'u': حالة 'v': حالة 'w': حالة 'x':
    حالة 'y': حالة 'z': 
    حالة 'A': حالة 'B': حالة 'C': حالة 'D':
    حالة 'E': حالة 'F': حالة 'G': حالة 'H':
    حالة 'I': حالة 'J': حالة 'K': 
    حالة 'M': حالة 'N': حالة 'O': حالة 'P':
    حالة 'Q': حالة 'R': حالة 'S': حالة 'T':
    حالة 'U': حالة 'V': حالة 'W': حالة 'X':
    حالة 'Y': حالة 'Z': 
    حالة '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        طالما (c = *++p, isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        إذا (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_اندازه - 1);
            pts = &hash_ident[h];
            لكل(;;) {
                ts = *pts;
                إذا (!ts)
                    اكسر;
                إذا (ts->len == len && !memcmp(ts->str, p1, len))
                    اذهب token_وموندل;
                pts = &(ts->hash_بل);
            }
            ts = tok_alloc_new(pts, (حرف *) p1, len);
        token_وموندل: ;
        } وإلا {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (حرف *) p1, len);
            p--;
            PEEKC(c, p);
            طالما (isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.معلومات, tokcstr.اندازه);
        }
        tok = ts->tok;
        اكسر;
    حالة 'L':
        t = p[1];
        إذا (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            إذا (c == '\'' || c == '\"') {
                is_long = 1;
                اذهب str_const;
            }
            *--p = c = 'L';
        }
        اذهب parse_ident_fast;

    حالة '0': حالة '1': حالة '2': حالة '3':
    حالة '4': حالة '5': حالة '6': حالة '7':
    حالة '8': حالة '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_عدد:
        cstr_reset(&tokcstr);
        لكل(;;) {
            cstr_ccat(&tokcstr, t);
            إذا (!((isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((حرف*)tokcstr.معلومات)[0] == '0'
                                && toup(((حرف*)tokcstr.معلومات)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                اكسر;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.اندازه = tokcstr.اندازه;
        tokc.str.معلومات = tokcstr.معلومات;
        tok = TOK_PPNUM;
        اكسر;

    حالة '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        إذا (isnum(c)) {
            t = '.';
            اذهب parse_عدد;
        } وإلا إذا ((isidnum_جدول['.' - CH_EOF] & IS_ID)
                   && (isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))) {
            *--p = c = '.';
            اذهب parse_ident_fast;
        } وإلا إذا (c == '.') {
            PEEKC(c, p);
            إذا (c == '.') {
                p++;
                tok = TOK_DOTS;
            } وإلا {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } وإلا {
            tok = '.';
        }
        اكسر;
    حالة '\'':
    حالة '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        إذا (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.اندازه = tokcstr.اندازه;
        tokc.str.معلومات = tokcstr.معلومات;
        tok = TOK_PPSTR;
        اكسر;

    حالة '<':
        PEEKC(c, p);
        إذا (c == '=') {
            p++;
            tok = TOK_LE;
        } وإلا إذا (c == '<') {
            PEEKC(c, p);
            إذا (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } وإلا {
                tok = TOK_SHL;
            }
        } وإلا {
            tok = TOK_LT;
        }
        اكسر;
    حالة '>':
        PEEKC(c, p);
        إذا (c == '=') {
            p++;
            tok = TOK_GE;
        } وإلا إذا (c == '>') {
            PEEKC(c, p);
            إذا (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } وإلا {
                tok = TOK_SAR;
            }
        } وإلا {
            tok = TOK_GT;
        }
        اكسر;
        
    حالة '&':
        PEEKC(c, p);
        إذا (c == '&') {
            p++;
            tok = TOK_LAND;
        } وإلا إذا (c == '=') {
            p++;
            tok = TOK_A_AND;
        } وإلا {
            tok = '&';
        }
        اكسر;
        
    حالة '|':
        PEEKC(c, p);
        إذا (c == '|') {
            p++;
            tok = TOK_LOR;
        } وإلا إذا (c == '=') {
            p++;
            tok = TOK_A_OR;
        } وإلا {
            tok = '|';
        }
        اكسر;

    حالة '+':
        PEEKC(c, p);
        إذا (c == '+') {
            p++;
            tok = TOK_INC;
        } وإلا إذا (c == '=') {
            p++;
            tok = TOK_A_جمع_کړه;
        } وإلا {
            tok = '+';
        }
        اكسر;
        
    حالة '-':
        PEEKC(c, p);
        إذا (c == '-') {
            p++;
            tok = TOK_DEC;
        } وإلا إذا (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } وإلا إذا (c == '>') {
            p++;
            tok = TOK_ARROW;
        } وإلا {
            tok = '-';
        }
        اكسر;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    حالة '/':
        PEEKC(c, p);
        إذا (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            اذهب maybe_space;
        } وإلا إذا (c == '/') {
            p = parse_کرښه_comment(p);
            tok = ' ';
            اذهب maybe_space;
        } وإلا إذا (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } وإلا {
            tok = '/';
        }
        اكسر;
        
        /* simple tokens */
    حالة '@': /* only used in assembler */
#که_تعریف_شوی TCC_موخه_ARM /* comment on arm asm */
        إذا (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_کرښه_comment(p);
            اذهب redo_no_پیل;
        }
#د_که_پای
    حالة '(':
    حالة ')':
    حالة '[':
    حالة ']':
    حالة '{':
    حالة '}':
    حالة ',':
    حالة ';':
    حالة ':':
    حالة '?':
    حالة '~':
    parse_simple:
        tok = c;
        p++;
        اكسر;
    حالة 0xEF: /* UTF8 BOM ? */
        إذا (p[1] == 0xBB && p[2] == 0xBF && p == file->بفر) {
            p += 3;
            اذهب redo_no_پیل;
        }
    افتراضي:
        إذا (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    اذهب parse_ident_fast;
        إذا (parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        اكسر;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#إذا defined(PARSE_DEBUG)
    چاپ_کړه("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#د_که_پای
}

#که_تعریف_شوی PP_DEBUG
ساكن صحيح indent;
ساكن فراغ define_print(TCCState *s1, صحيح v);
ساكن فراغ pp_print(ثابت حرف *پیغام, صحيح v, ثابت صحيح *str)
{
    FILE *fp = tcc_state->ppfp;

    إذا (پیغام[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    وإلا إذا (پیغام[0] == '+')
         ++indent, ++پیغام;
    وإلا إذا (پیغام[0] == '-')
        --indent, ++پیغام;

    fprintf(fp, "%*s", indent, "");
    إذا (پیغام[0] == '#') {
        define_print(tcc_state, v);
    } وإلا {
        tok_print(str, v ? "%s %s" : "%s", پیغام, get_tok_str(v, 0));
    }
}
#تعریف_کړه PP_PRINT(x) pp_print x
#وإلا
#تعریف_کړه PP_PRINT(x)
#د_که_پای

ساكن صحيح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحيح *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ساكن صحيح *macro_arg_subst(Sym **nested_list, ثابت صحيح *macro_str, Sym *دلیلونه)
{
    صحيح t, t0, t1, t2, n;
    ثابت صحيح *st;
    Sym *s;
    CValue cval;
    TokenString str;

#که_تعریف_شوی PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    لكل (s = دلیلونه, n = 0; s; s = s->prev, ++n);
    طالما (n--) {
        لكل (s = دلیلونه, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#د_که_پای

    tok_str_new(&str);
    t0 = t1 = 0;
    طالما(1) {
        TOK_GET(&t, &macro_str, &cval);
        إذا (!t)
            اكسر;
        إذا (t == '#') {
            /* stringize */
            افعل t = *macro_str++; طالما (t == ' ');
            s = sym_find2(دلیلونه, t);
            إذا (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                طالما (*st != TOK_EOF) {
                    ثابت حرف *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    طالما (*s) {
                        إذا (t == TOK_PPSTR && *s != '\'')
                            جمع_کړه_char(&tokcstr, *s);
                        وإلا
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.اندازه = tokcstr.اندازه;
                cval.str.معلومات = tokcstr.معلومات;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#که_تعریف_شوی TCC_موخه_ARM
            } وإلا إذا ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_جمع_کړه(&str, '#');
#د_که_پای
            } وإلا {
                expect("macro parameter after '#'");
            }
        } وإلا إذا (t >= TOK_IDENT) {
            s = sym_find2(دلیلونه, t);
            إذا (s) {
                st = s->d;
                n = 0;
                طالما ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                إذا (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    إذا (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        صحيح c = str.str[str.len - 1];
                        طالما (str.str[--str.len] != ',')
                            ;
                        إذا (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } وإلا {
                            /* suppress '##' and add variable */
                            str.len++;
                            إذا (c == ' ')
                                str.str[str.len++] = c;
                            اذهب جمع_کړه_var;
                        }
                    } وإلا {
                        إذا (*st == TOK_EOF)
                            tok_str_جمع_کړه(&str, TOK_PLCHLDR);
                    }
                } وإلا {
            جمع_کړه_var:
		    إذا (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_جمع_کړه(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                طالما (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } وإلا {
                tok_str_جمع_کړه(&str, t);
            }
        } وإلا {
            tok_str_add2(&str, t, &cval);
        }
        إذا (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_جمع_کړه(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    أرجع str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ساكن مضمن صحيح *macro_twosharps(ثابت صحيح *ptr0)
{
    صحيح t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ثابت صحيح *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    لكل (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        إذا (t1 == 0)
            اكسر;
        لكل (;;) {
            n = 0;
            طالما ((t2 = ptr[n]) == ' ')
                ++n;
            إذا (t2 != TOK_PPJOIN)
                اكسر;
            ptr += n;
            طالما ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            إذا (t2 == TOK_PLCHLDR)
                استمر;
            إذا (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        إذا (tokcstr.اندازه) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.اندازه);
            حافظه_نقل(file->بفر, tokcstr.معلومات, tokcstr.اندازه);
            tok_flags = 0; /* don't interpret '#' */
            لكل (n = 0;;n = l) {
                بل_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                إذا (*file->buf_ptr == 0)
                    اكسر;
                tok_str_جمع_کړه(&macro_str1, ' ');
                l = file->buf_ptr - file->بفر;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->بفر + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        إذا (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_جمع_کړه(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    أرجع macro_str1.str;
}

ساكن صحيح peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    صحيح c;
    لكل (;;) {
        PEEKC(c, p);
        بدل (c) {
        حالة '/':
            PEEKC(c, p);
            إذا (c == '*')
                p = parse_comment(p);
            وإلا إذا (c == '/')
                p = parse_کرښه_comment(p);
            وإلا {
                c = *--p = '/';
                اذهب leave;
            }
            --p, c = ' ';
            اكسر;
        حالة ' ': حالة '\t':
            اكسر;
        حالة '\f': حالة '\v': حالة '\r':
            استمر;
        حالة '\n':
            file->کرښه_عدد++, tok_flags |= TOK_FLAG_BOL;
            اكسر;
        افتراضي: leave:
            file->buf_ptr = p;
            أرجع c;
        }
        إذا (ws_str)
            tok_str_جمع_کړه(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ساكن صحيح بل_argstream(Sym **nested_list, TokenString *ws_str)
{
    صحيح t;
    Sym *sa;

    طالما (macro_ptr) {
        ثابت صحيح *m = macro_ptr;
        طالما ((t = *m) != 0) {
            إذا (ws_str) {
                إذا (t != ' ')
                    أرجع t;
                ++m;
            } وإلا {
                TOK_GET(&tok, &macro_ptr, &tokc);
                أرجع tok;
            }
        }
        پای_ټکی_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        إذا (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    إذا (ws_str) {
        أرجع peek_file(ws_str);
    } وإلا {
        بل_nomacro();
        إذا (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        أرجع tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ساكن صحيح macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    صحيح t;
    صحيح v = s->v;

    PP_PRINT(("#", v, s->d));
    إذا (s->d) {
        صحيح *mstr = s->d;
        صحيح *jstr;
        Sym *sa;
        صحيح ret;

        إذا (s->type.t & MACRO_FUNC) {
            صحيح saved_parse_flags = parse_flags;
            TokenString str;
            صحيح parlevel, i;
            Sym *sa1, *دلیلونه;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = بل_argstream(nested_list, &str);
            إذا (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                إذا (parse_flags & PARSE_FLAG_SPACES)
                    لكل (i = 0; i < str.len; i++)
                        tok_str_جمع_کړه(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                أرجع 0;
            } وإلا {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            دلیلونه = عدم;
            sa = s->بل;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            لكل(;;) {
                افعل {
                    t = بل_argstream(nested_list, عدم);
                } طالما (t == ' ' || --i);

                إذا (!sa) {
                    إذا (t == ')') /* handle '()' case */
                        اكسر;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            تشه_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                طالما (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    إذا (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    إذا (t == '(')
                        parlevel++;
                    إذا (t == ')')
                        parlevel--;
                    إذا (t == ' ')
                        str.need_spc |= 1;
                    وإلا
                        tok_str_add2_spc(&str, t, &tokc);
                    t = بل_argstream(nested_list, عدم);
                }
                tok_str_جمع_کړه(&str, TOK_EOF);
                sa1 = sym_push2(&دلیلونه, sa->v & ~SYM_ډګر, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->بل;
                إذا (t == ')') {
                    إذا (!sa)
                        اكسر;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    إذا (sa->type.t && gnu_ext)
                        اذهب تشه_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, دلیلونه);
            /* free memory */
            sa = دلیلونه;
            طالما (sa) {
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
        إذا (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        إذا (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        إذا (jstr != mstr)
            tok_str_free_str(jstr);
        إذا (mstr != s->d)
            tok_str_free_str(mstr);
        أرجع ret;

    } وإلا {
        CValue cval;
        حرف buf[32], *cstrval = buf;

        /* special macros */
        إذا (v == TOK_کرښه_2 || v == TOK___COUNTER__) {
            t = v == TOK_کرښه_2 ? file->کرښه_عدد : pp_counter++;
            snprintf(buf, حجم(buf), "%d", t);
            t = TOK_PPNUM;
            اذهب جمع_کړه_cstr1;

        } وإلا إذا (v == TOK___FILE__) {
            cstrval = file->filename;
            اذهب جمع_کړه_cstr;

        } وإلا إذا (v == TOK___DATE__ || v == TOK_وخت) {
            time_t ti;
            بنية tm *tm;
            وخت(&ti);
            tm = localtime(&ti);
            إذا (v == TOK___DATE__) {
                ساكن حرف ثابت ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, حجم(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } وإلا {
                snprintf(buf, حجم(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        جمع_کړه_cstr:
            t = TOK_STR;
        جمع_کړه_cstr1:
            cval.str.اندازه = مزي_اوږدوالی(cstrval) + 1;
            cval.str.معلومات = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        أرجع 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ساكن صحيح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحيح *macro_str
    )
{
    Sym *s;
    صحيح t, nosubst = 0;
    CValue cval;
    TokenString *str;

#که_تعریف_شوی PP_DEBUG
    صحيح tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#د_که_پای

    طالما (1) {
        TOK_GET(&t, &macro_str, &cval);
        إذا (t == 0 || t == TOK_EOF)
            اكسر;
        إذا (t >= TOK_IDENT) {
            s = define_پیدا_کړه(t);
            إذا (s == عدم || nosubst)
                اذهب no_subst;
            /* if nested substitution, do nothing */
            إذا (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_ډګر;
                اذهب no_subst;
            }
            str = tok_str_alloc();
            str->str = (صحيح*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            إذا (macro_ډېری != str) {
                /* already finished by reading function macro arguments */
                اكسر;
            }
            macro_str = macro_ptr;
            پای_ټکی_macro ();
        } وإلا إذا (t == ' ') {
            إذا (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } وإلا {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            إذا (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            إذا (t == TOK_DEFINED && pp_بیان)
                nosubst = 1;
        }
    }

#که_تعریف_شوی PP_DEBUG
    tok_str_جمع_کړه(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#د_که_پای
    أرجع nosubst;
}

/* return next token with macro substitution */
ST_FUNC فراغ بل(فراغ)
{
    صحيح t;
    طالما (macro_ptr) {
redo:
        t = *macro_ptr;
        إذا (TOK_HAS_ارزښت(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            إذا (t == TOK_LINENUM) {
                file->کرښه_عدد = tokc.i;
                اذهب redo;
            }
            اذهب convert;
        } وإلا إذا (t == 0) {
            /* end of macro or unget token string */
            پای_ټکی_macro();
            استمر;
        } وإلا إذا (t == TOK_EOF) {
            /* do nothing */
        } وإلا {
            ++macro_ptr;
            t &= ~SYM_ډګر; /* remove 'nosubst' marker */
            إذا (t == '\\') {
                إذا (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        أرجع;
    }

    بل_nomacro();
    t = tok;
    إذا (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_پیدا_کړه(t);
        إذا (s) {
            Sym *nested_list = عدم;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_جمع_کړه(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            اذهب redo;
        }
        أرجع;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    إذا (t == TOK_PPNUM) {
        إذا  (parse_flags & PARSE_FLAG_TOK_عدد)
            parse_شمېره(tokc.str.معلومات);
    } وإلا إذا (t == TOK_PPSTR) {
        إذا (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.معلومات, tokc.str.اندازه - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN فراغ unget_tok(صحيح وروستی_tok)
{
    TokenString *str = &unget_buf;
    صحيح alloc = 0;
    إذا (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    إذا (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_جمع_کړه(str, 0);
    begin_macro(str, alloc);
    tok = وروستی_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ساكن ثابت حرف * ثابت موخه_os_defs =
#که_تعریف_شوی TCC_موخه_PE
    "_WIN32\0"
# إذا PTR_اندازه == 8
    "_WIN64\0"
# endif
#وإلا
# إذا defined TCC_موخه_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# وإلا
    "__linux__\0"
    "__linux\0"
#  إذا TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#د_که_پای
    ;

ساكن فراغ putdef(CString *cs, ثابت حرف *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ساكن فراغ putdefs(CString *cs, ثابت حرف *p)
{
    طالما (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ساكن فراغ tcc_predefs(TCCState *s1, CString *cs, صحيح is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_نسخه[4]);
    putdefs(cs, موخه_machine_defs);
    putdefs(cs, موخه_os_defs);

#که_تعریف_شوی TCC_موخه_ARM
    إذا (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#د_که_پای
    إذا (is_asm)
      putdef(cs, "__ASSEMBLER__");
    إذا (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    إذا (s1->output_type == TCC_OUTPUT_حافظه)
      putdef(cs, "__TCC_RUN__");
#که_تعریف_شوی CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#د_که_پای
#که_تعریف_شوی CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#د_که_پای
    إذا (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    إذا (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    إذا (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    إذا (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_اندازه);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_اندازه);
    إذا (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#إذا CONFIG_TCC_PREDEFS
        #ضمن "tccdefs_.h" /* include as strings */
#وإلا
        "#include <tccdefs.h>\n" /* load at runtime */
#د_که_پای
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC فراغ preprocess_پیل(TCCState *s1, صحيح filetype)
{
    صحيح is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ډېری_ptr = s1->include_ډېری;
    s1->ifdef_ډېری_ptr = s1->ifdef_ډېری;
    file->ifdef_ډېری_ptr = s1->ifdef_ډېری_ptr;
    pp_بیان = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ډېری[0] = 0;
    s1->pack_ډېری_ptr = s1->pack_ډېری;

    سېټ_idnum('$', s1->dollars_دننه_identifiers ? IS_ID : 0);
    سېټ_idnum('.', is_asm ? IS_ID : 0);

    إذا (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        إذا (s1->cmdline_defs.اندازه)
          cstr_cat(&cstr, s1->cmdline_defs.معلومات, s1->cmdline_defs.اندازه);
        إذا (s1->cmdline_incl.اندازه)
          cstr_cat(&cstr, s1->cmdline_incl.معلومات, s1->cmdline_incl.اندازه);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ډېری_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.اندازه);
        حافظه_نقل(file->بفر, cstr.معلومات, cstr.اندازه);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC فراغ preprocess_پای_ټکی(TCCState *s1)
{
    طالما (macro_ډېری)
        پای_ټکی_macro();
    macro_ptr = عدم;
    طالما (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC صحيح سېټ_idnum(صحيح c, صحيح val)
{
    صحيح prev = isidnum_جدول[c - CH_EOF];
    isidnum_جدول[c - CH_EOF] = val;
    أرجع prev;
}

ST_FUNC فراغ tccpp_new(TCCState *s)
{
    صحيح i, c;
    ثابت حرف *p, *r;

    /* init isid table */
    لكل(i = CH_EOF; i<128; i++)
        سېټ_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_عدد
            : 0);

    لكل(i = 128; i<256; i++)
        سېټ_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_اندازه);
    tal_new(&tokstr_alloc, TOKSTR_TAL_اندازه);

    memset(hash_ident, 0, TOK_HASH_اندازه * حجم(TokenSym *));
    memset(s->cached_includes_hash, 0, حجم s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_اندازه);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_اندازه);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_اندازه);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    طالما (*p) {
        r = p;
        لكل(;;) {
            c = *r++;
            إذا (c == '\0')
                اكسر;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ټېل(TOK_کرښه_2, MACRO_OBJ, عدم, عدم);
    define_ټېل(TOK___FILE__, MACRO_OBJ, عدم, عدم);
    define_ټېل(TOK___DATE__, MACRO_OBJ, عدم, عدم);
    define_ټېل(TOK_وخت, MACRO_OBJ, عدم, عدم);
    define_ټېل(TOK___COUNTER__, MACRO_OBJ, عدم, عدم);
}

ST_FUNC فراغ tccpp_delete(TCCState *s)
{
    صحيح i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    إذا (n > ټول_idents)
        ټول_idents = n;
    لكل (i = n; --i >= 0;)
        tal_free(&toksym_alloc, جدول_ident[i]);
    tcc_free(جدول_ident);
    جدول_ident = عدم;

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

ساكن صحيح pp_need_space(صحيح a, صحيح b);

ساكن فراغ tok_print(ثابت صحيح *str, ثابت حرف *پیغام, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    صحيح t, t0, s;
    CValue cval;

    va_start(ap, پیغام);
    vfprintf(fp, پیغام, ap);
    va_end(ap);

    s = t0 = 0;
    طالما (str) {
	TOK_GET(&t, &str, &cval);
	إذا (t == 0 || t == TOK_EOF)
	    اكسر;
        إذا (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ساكن فراغ pp_کرښه(TCCState *s1, BufferedFile *f, صحيح level)
{
    صحيح d = f->کرښه_عدد - f->کرښه_ref;

    إذا (s1->dflag & 4)
	أرجع;

    إذا (s1->Pflag == کرښه_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } وإلا إذا (level == 0 && f->کرښه_ref && d < 8) {
	طالما (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } وإلا إذا (s1->Pflag == کرښه_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->کرښه_عدد, f->filename);
    } وإلا {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->کرښه_عدد, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->کرښه_ref = f->کرښه_عدد;
}

ساكن فراغ define_print(TCCState *s1, صحيح v)
{
    FILE *fp;
    Sym *s;

    s = define_پیدا_کړه(v);
    إذا (عدم == s || عدم == s->d)
        أرجع;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, عدم));
    إذا (s->type.t & MACRO_FUNC) {
        Sym *a = s->بل;
        fprintf(fp,"(");
        إذا (a)
            لكل (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, عدم));
                إذا (!(a = a->بل))
                    اكسر;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ساكن فراغ pp_debug_تعریفوي(TCCState *s1)
{
    صحيح v, t;
    ثابت حرف *vs;
    FILE *fp;

    t = pp_debug_tok;
    إذا (t == 0)
        أرجع;

    file->کرښه_عدد--;
    pp_کرښه(s1, file, 0);
    file->کرښه_ref = ++file->کرښه_عدد;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, عدم);
    إذا (t == TOK_DEFINE) {
        define_print(s1, v);
    } وإلا إذا (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } وإلا إذا (t == TOK_ټېل_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } وإلا إذا (t == TOK_راوباسه_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ساكن صحيح pp_need_space(صحيح a, صحيح b)
{
    أرجع 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ساكن صحيح pp_check_he0xE(صحيح t, ثابت حرف *p)
{
    إذا (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        أرجع 'E';
    أرجع t;
}

/* Preprocess the current file */
ST_FUNC صحيح tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    صحيح token_کتل_شوی, spcs, level;
    ثابت حرف *p;
    حرف white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    إذا (s1->Pflag == کرښه_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_عدد, s1->Pflag = 1;

    إذا (s1->do_bench) {
	/* for PP benchmarks */
	افعل بل(); طالما (tok != TOK_EOF);
	أرجع 0;
    }

    token_کتل_شوی = TOK_LINEFEED, spcs = 0, level = 0;
    إذا (file->prev)
        pp_کرښه(s1, file->prev, level++);
    pp_کرښه(s1, file, level);

    لكل (;;) {
        iptr = s1->include_ډېری_ptr;
        بل();
        إذا (tok == TOK_EOF)
            اكسر;

        level = s1->include_ډېری_ptr - iptr;
        إذا (level) {
            إذا (level > 0)
                pp_کرښه(s1, *iptr, 0);
            pp_کرښه(s1, file, level);
        }
        إذا (s1->dflag & 7) {
            pp_debug_تعریفوي(s1);
            إذا (s1->dflag & 4)
                استمر;
        }

        إذا (is_space(tok)) {
            إذا (spcs < حجم white - 1)
                white[spcs++] = tok;
            استمر;
        } وإلا إذا (tok == TOK_LINEFEED) {
            spcs = 0;
            إذا (token_کتل_شوی == TOK_LINEFEED)
                استمر;
            ++file->کرښه_ref;
        } وإلا إذا (token_کتل_شوی == TOK_LINEFEED) {
            pp_کرښه(s1, file, 0);
        } وإلا إذا (spcs == 0 && pp_need_space(token_کتل_شوی, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_کتل_شوی = pp_check_he0xE(tok, p);
    }
    أرجع 0;
}

/* ------------------------------------------------------------------------- */
