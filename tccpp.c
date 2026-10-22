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

#تعریف_کرو USING_GLOBALS
#شامل "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#تعریف_کرو ACCEPT_LF_اندر_لڑیاں 0

/********************************************************/
/* global variables */

ST_ڈیٹا صحیح tok_flags;
ST_ڈیٹا صحیح parse_flags;

ST_ڈیٹا ساخت BufferedFile *file;
ST_ڈیٹا صحیح tok;
ST_ڈیٹا CValue tokc;
ST_ڈیٹا ثابت صحیح *macro_ptr;
ST_ڈیٹا CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_ڈیٹا صحیح tok_ident;
ST_ڈیٹا TokenSym **جدول_ident;
ST_ڈیٹا صحیح pp_اظہاریہ;

/* ------------------------------------------------------------------------- */

ساکن TokenSym *hash_ident[TOK_HASH_سائز];
ساکن حرف token_buf[STRING_MAX_سائز + 1];
ساکن CString cstr_buf;
ساکن TokenString tokstr_buf;
ساکن TokenString unget_buf;
ساکن غیرعلامتی حرف isidnum_جدول[256 - CH_EOF];
ساکن صحیح pp_debug_tok, pp_debug_symv;
ساکن صحیح pp_شمار;
ساکن خالی tok_print(ثابت صحیح *str, ثابت حرف *پیغام, ...);
ساکن خالی اگلا_nomacro(خالی);
ساکن خالی parse_نمبر(ثابت حرف *p);
ساکن خالی parse_string(ثابت حرف *p, صحیح len);

ساکن ساخت TinyAlloc *toksym_alloc;
ساکن ساخت TinyAlloc *tokstr_alloc;

ساکن TokenString *macro_ڈھیر;

ساکن ثابت حرف tcc_keywords[] = 
#تعریف_کرو DEF(id, str) str "\0"
#شامل "tcctok.h"
#تعریف_منسوخ DEF
;

/* WARNING: the content of this string encodes token numbers */
ساکن ثابت غیرعلامتی حرف tok_two_chars[] =
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
    '+','=', TOK_A_جوڑو,
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

ST_FUNC خالی skip(صحیح c)
{
    اگر (tok != c) {
        حرف tmp[40];
        pstrcpy(tmp, حجم tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    اگلا();
}

ST_FUNC خالی expect(ثابت حرف *پیغام)
{
    tcc_error("%s expected", پیغام);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#تعریف_کرو USE_TAL

#اگر_غیر_تعریف_شدہ USE_TAL /* may cause memory leaks after errors */
#تعریف_کرو tal_free(al, p) tcc_free(p)
#تعریف_کرو tal_realloc(al, p, سائز) tcc_realloc(p, سائز)
#تعریف_کرو tal_new(a,b)
#تعریف_کرو tal_delete(a)
#ورنہ
#اگر !defined(MEM_DEBUG)
#تعریف_کرو tal_free(al, p) tal_free_impl(al, p)
#تعریف_کرو tal_realloc(al, p, سائز) tal_realloc_impl(al, p, سائز)
#تعریف_کرو TAL_DEBUG_PARAMS
#ورنہ
#تعریف_کرو TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#تعریف_کرو tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#تعریف_کرو tal_realloc(al, p, سائز) tal_realloc_impl(al, p, سائز, __FILE__, __LINE__)
#تعریف_کرو TAL_DEBUG_PARAMS , ثابت حرف *sfile, صحیح sline
#اگر_ختم

#تعریف_کرو TOKSYM_TAL_سائز (256 * 1024) /* allocator for TokenSym in table_ident */
#تعریف_کرو TOKSTR_TAL_سائز (256 * 1024) /* allocator for TokenString instances */

قسمتعریف ساخت TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ساخت TinyAlloc *اگلا;
    غیرعلامتی nb_allocs;
    غیرعلامتی سائز;
#اگر TAL_INFO
    غیرعلامتی nb_peak;
    غیرعلامتی nb_کل;
    uint8_t *peak_p;
#اگر_ختم
    اتحاد {
        uint8_t بفر[1];
        سائز_t _aligner_;
    };
} TinyAlloc;

قسمتعریف ساخت tal_سرخی_t {
    سائز_t  سائز; /* word align */
#اگر TAL_DEBUG
    صحیح     سطر_عدد; /* negative line_num used for double free check */
    حرف    file_name[40];
#اگر_ختم
} tal_سرخی_t;

#تعریف_کرو TAL_ALIGN(سائز) \
    (((سائز) + (حجم (سائز_t) - 1)) & ~(حجم (سائز_t) - 1))

/* ------------------------------------------------------------------------- */

ساکن TinyAlloc *tal_new(TinyAlloc **pal, غیرعلامتی سائز)
{
    TinyAlloc *al = tcc_malloc(حجم(TinyAlloc) - حجم (سائز_t) + سائز);
    al->p = al->بفر;
    al->bufend = al->بفر + سائز;
    al->nb_allocs = 0;
    al->اگلا = *pal, *pal = al;
    al->سائز = al->اگلا ? al->اگلا->سائز : سائز;
#اگر TAL_INFO
    al->nb_peak = 0;
    al->nb_کل = 0;
    al->peak_p = al->p;
#اگر_ختم
    واپس al;
}

ساکن خالی tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *اگلا;

#اگر TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#اگر_ختم
دم_call:
#اگر TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#اگر TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->بفر, al->nb_peak, al->nb_کل,
            (al->peak_p - al->بفر) * 100.0 / (al->bufend - al->بفر));
#اگر_ختم
    اگر (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->بفر;
        جب (p < al->p) {
            tal_سرخی_t *سرخی = (tal_سرخی_t *)p;
            اگر (سرخی->سطر_عدد > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        سرخی->file_name, سرخی->سطر_عدد, (صحیح)سرخی->سائز);
            }
            p += سرخی->سائز + حجم(tal_سرخی_t);
        }
#اگر TAL_DEBUG == 2
        باہر_نکلو(2);
#اگر_ختم
    }
#اگر_ختم
    اگلا = al->اگلا;
    tcc_free(al);
    al = اگلا;
    اگر (al)
        جاؤ دم_call;
    *pal = al;
}

ساکن خالی tal_free_impl(TinyAlloc **pal, خالی *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **چوٹی = pal;
    tal_سرخی_t *سرخی;

    اگر (!p)
        واپس;
    سرخی = (tal_سرخی_t *)p - 1;
#اگر TAL_DEBUG
    اگر (سرخی->سطر_عدد < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                سرخی->file_name, (صحیح)-سرخی->سطر_عدد, (صحیح)سرخی->سائز);
    } ورنہ
        سرخی->سطر_عدد = -سرخی->سطر_عدد;
#اگر_ختم
    al = *pal;
    جب ((uint8_t*)p < al->بفر || (uint8_t*)p > al->bufend)
        al = *(pal = &al->اگلا);
    اگر (0 == --al->nb_allocs) {
        *pal = al->اگلا;
        اگر ((al->bufend - al->بفر) > al->سائز) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } ورنہ {
            /* reset and move to front */
            al->p = al->بفر;
            al->اگلا = *چوٹی, *چوٹی = al;
        }
    } ورنہ اگر ((uint8_t*)p + سرخی->سائز == al->p) {
        al->p = (uint8_t*)سرخی;
    }
}

ساکن خالی *tal_realloc_impl(TinyAlloc **pal, خالی *p, غیرعلامتی سائز TAL_DEBUG_PARAMS)
{
    tal_سرخی_t *سرخی;
    خالی *ret;
    غیرعلامتی adj_سائز = TAL_ALIGN(سائز) + حجم(tal_سرخی_t);
    TinyAlloc *al = *pal;

    اگر (p) {
        /* reallpc case */
        جب ((uint8_t*)p < al->بفر || (uint8_t*)p > al->bufend)
            al = al->اگلا;
        سرخی = (tal_سرخی_t *)p - 1;
        اگر ((uint8_t*)p + سرخی->سائز == al->p)
            al->p = (uint8_t*)سرخی; /* maybe reuse */
        اگر (al->p + adj_سائز > al->bufend) {
            ret = tal_realloc(pal, 0, سائز);
            حافظہ_نقل(ret, p, سرخی->سائز);
            tal_free(pal, p);
            واپس ret;
        } ورنہ اگر (al->p != (uint8_t*)سرخی) {
            حافظہ_نقل((tal_سرخی_t*)al->p + 1, p, سرخی->سائز);
#اگر TAL_DEBUG
            سرخی->سطر_عدد = -سرخی->سطر_عدد;
#اگر_ختم
        }
    } ورنہ {
        /* new alloc case */
        جب (al->p + adj_سائز > al->bufend) {
            al = al->اگلا;
            اگر (!al) {
                غیرعلامتی new_سائز = (*pal)->سائز;
                اگر (adj_سائز > new_سائز) {
                    new_سائز = adj_سائز;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_سائز);
                توڑو;
            }
        }
        al->nb_allocs++;
    }
    سرخی = (tal_سرخی_t *)al->p;
    سرخی->سائز = adj_سائز - حجم(tal_سرخی_t);
    al->p += adj_سائز;
    ret = سرخی + 1;
#اگر  TAL_DEBUG
    {
        صحیح ofs = لڑی_لمبائی(sfile) + 1 - حجم سرخی->file_name;
        strcpy(سرخی->file_name, sfile + (ofs > 0 ? ofs : 0));
        سرخی->سطر_عدد = sline;
#اگر TAL_INFO
        اگر (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        اگر (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_کل++;
#اگر_ختم
    }
#اگر_ختم
    واپس ret;
}

#اگر_ختم /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ساکن خالی cstr_realloc(CString *cstr, صحیح new_سائز)
{
    صحیح سائز;

    سائز = cstr->سائز_allocated;
    اگر (سائز < 8)
        سائز = 8; /* no need to allocate a too small first string */
    جب (سائز < new_سائز)
        سائز = سائز * 2;
    cstr->ڈیٹا = tcc_realloc(cstr->ڈیٹا, سائز);
    cstr->سائز_allocated = سائز;
}

/* add a byte */
ST_INLN خالی cstr_ccat(CString *cstr, صحیح ch)
{
    صحیح سائز;
    سائز = cstr->سائز + 1;
    اگر (سائز > cstr->سائز_allocated)
        cstr_realloc(cstr, سائز);
    cstr->ڈیٹا[سائز - 1] = ch;
    cstr->سائز = سائز;
}

ST_INLN حرف *unicode_مقصد_utf8 (حرف *b, uint32_t Uc)
{
    اگر (Uc<0x80) *b++=Uc;
    ورنہ اگر (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    ورنہ اگر (Uc-0xd800u<0x800) جاؤ error;
    ورنہ اگر (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ورنہ اگر (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ورنہ error: tcc_error("0x%x is not a valid universal character", Uc);
    واپس b;
}

/* add a unicode character expanded into utf8 */
ST_INLN خالی cstr_u8cat(CString *cstr, صحیح ch)
{
    حرف buf[4], *e;
    e = unicode_مقصد_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC خالی cstr_cat(CString *cstr, ثابت حرف *str, صحیح len)
{
    صحیح سائز;
    اگر (len <= 0)
        len = لڑی_لمبائی(str) + 1 + len;
    سائز = cstr->سائز + len;
    اگر (سائز > cstr->سائز_allocated)
        cstr_realloc(cstr, سائز);
    memmove(cstr->ڈیٹا + cstr->سائز, str, len);
    cstr->سائز = سائز;
}

/* add a wide char */
ST_FUNC خالی cstr_wccat(CString *cstr, صحیح ch)
{
    صحیح سائز;
    سائز = cstr->سائز + حجم(nwchar_t);
    اگر (سائز > cstr->سائز_allocated)
        cstr_realloc(cstr, سائز);
    *(nwchar_t *)(cstr->ڈیٹا + سائز - حجم(nwchar_t)) = ch;
    cstr->سائز = سائز;
}

ST_FUNC خالی cstr_new(CString *cstr)
{
    memset(cstr, 0, حجم(CString));
}

/* free string and reset it to NULL */
ST_FUNC خالی cstr_free(CString *cstr)
{
    tcc_free(cstr->ڈیٹا);
}

/* reset string to empty */
ST_FUNC خالی cstr_reset(CString *cstr)
{
    cstr->سائز = 0;
}

ST_FUNC صحیح cstr_vprintf(CString *cstr, ثابت حرف *fmt, va_list ap)
{
    va_list v;
    صحیح len, سائز = 80;
    برائے (;;) {
        سائز += cstr->سائز;
        اگر (سائز > cstr->سائز_allocated)
            cstr_realloc(cstr, سائز);
        سائز = cstr->سائز_allocated - cstr->سائز;
        va_copy(v, ap);
        len = vsnprintf(cstr->ڈیٹا + cstr->سائز, سائز, fmt, v);
        va_end(v);
        اگر (len >= 0 && len < سائز)
            توڑو;
        سائز *= 2;
    }
    cstr->سائز += len;
    واپس len;
}

ST_FUNC صحیح cstr_printf(CString *cstr, ثابت حرف *fmt, ...)
{
    va_list ap; صحیح len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    واپس len;
}

/* XXX: unicode ? */
ساکن خالی جوڑو_char(CString *cstr, صحیح c)
{
    اگر (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    اگر (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } ورنہ {
        cstr_ccat(cstr, '\\');
        اگر (c == '\n') {
            cstr_ccat(cstr, 'n');
        } ورنہ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ساکن TokenSym *tok_alloc_new(TokenSym **pts, ثابت حرف *str, صحیح len)
{
    TokenSym *ts, **ptable;
    صحیح i;

    اگر (tok_ident >= SYM_پہلا_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    اگر ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(جدول_ident, (i + TOK_ALLOC_INCR) * حجم(TokenSym *));
        جدول_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, حجم(TokenSym) + len);
    جدول_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = تہی;
    ts->sym_label = تہی;
    ts->sym_struct = تہی;
    ts->sym_identifier = تہی;
    ts->len = len;
    ts->hash_اگلا = تہی;
    حافظہ_نقل(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    واپس ts;
}

#تعریف_کرو TOK_HASH_INIT 1
#تعریف_کرو TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحیح len)
{
    TokenSym *ts, **pts;
    صحیح i;
    غیرعلامتی صحیح h;
    
    h = TOK_HASH_INIT;
    برائے(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((غیرعلامتی حرف *)str)[i]);
    h &= (TOK_HASH_سائز - 1);

    pts = &hash_ident[h];
    برائے(;;) {
        ts = *pts;
        اگر (!ts)
            توڑو;
        اگر (ts->len == len && !memcmp(ts->str, str, len))
            واپس ts;
        pts = &(ts->hash_اگلا);
    }
    واپس tok_alloc_new(pts, str, len);
}

ST_FUNC صحیح tok_alloc_const(ثابت حرف *str)
{
    واپس tok_alloc(str, لڑی_لمبائی(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ثابت حرف *get_tok_str(صحیح v, CValue *cv)
{
    حرف *p;
    صحیح i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.ڈیٹا;

    انتخاب(v) {
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CLONG:
    حالت TOK_CULONG:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (غیرعلامتی طویل طویل)cv->i);
        توڑو;
    حالت TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    حالت TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        جوڑو_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        توڑو;
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        واپس (حرف*)cv->str.ڈیٹا;
    حالت TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    حالت TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        اگر (v == TOK_STR) {
            len = cv->str.سائز - 1;
            برائے(i=0;i<len;i++)
                جوڑو_char(&cstr_buf, ((غیرعلامتی حرف *)cv->str.ڈیٹا)[i]);
        } ورنہ {
            len = (cv->str.سائز / حجم(nwchar_t)) - 1;
            برائے(i=0;i<len;i++)
                جوڑو_char(&cstr_buf, ((nwchar_t *)cv->str.ڈیٹا)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        توڑو;

    حالت TOK_CFLOAT:
        واپس strcpy(p, "<float>");
    حالت TOK_CDOUBLE:
        واپس strcpy(p, "<double>");
    حالت TOK_CLDOUBLE:
        واپس strcpy(p, "<long double>");
    حالت TOK_LINENUM:
        واپس strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    حالت TOK_LT:
        v = '<';
        جاؤ addv;
    حالت TOK_GT:
        v = '>';
        جاؤ addv;
    حالت TOK_DOTS:
        واپس strcpy(p, "...");
    حالت TOK_A_SHL:
        واپس strcpy(p, "<<=");
    حالت TOK_A_SAR:
        واپس strcpy(p, ">>=");
    حالت TOK_EOF:
        واپس strcpy(p, "<eof>");
    حالت 0: /* anonymous nameless symbols */
        واپس strcpy(p, "<no name>");
    طےشدہ:
        v &= ~(SYM_میدان | SYM_STRUCT);
        اگر (v < TOK_IDENT) {
            /* search in two bytes table */
            ثابت غیرعلامتی حرف *q = tok_two_chars;
            جب (*q) {
                اگر (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    واپس cstr_buf.ڈیٹا;
                }
                q += 3;
            }
            اگر (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                توڑو;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } ورنہ اگر (v < tok_ident) {
            واپس جدول_ident[v - TOK_IDENT]->str;
        } ورنہ اگر (v >= SYM_پہلا_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_پہلا_ANOM);
        } ورنہ {
            /* should never happen */
            واپس تہی;
        }
        توڑو;
    }
    واپس cstr_buf.ڈیٹا;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ساکن صحیح handle_eob(خالی)
{
    BufferedFile *bf = file;
    صحیح len;

    /* only tries to read if really end of buffer */
    اگر (bf->buf_ptr >= bf->buf_انتہا) {
        اگر (bf->fd >= 0) {
#اگر defined(PARSE_DEBUG)
            len = 1;
#ورنہ
            len = IO_BUF_سائز;
#اگر_ختم
            len = اقرأ(bf->fd, bf->بفر, len);
            اگر (len < 0)
                len = 0;
        } ورنہ {
            len = 0;
        }
        کل_بائٹیں += len;
        bf->buf_ptr = bf->بفر;
        bf->buf_انتہا = bf->بفر + len;
        *bf->buf_انتہا = CH_EOB;
    }
    اگر (bf->buf_ptr < bf->buf_انتہا) {
        واپس bf->buf_ptr[0];
    } ورنہ {
        bf->buf_ptr = bf->buf_انتہا;
        واپس CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ساکن صحیح اگلا_c(خالی)
{
    صحیح ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    اگر (ch == CH_EOB && file->buf_ptr >= file->buf_انتہا)
        ch = handle_eob();
    واپس ch;
}

/* input with '\[\r]\n' handling. */
ساکن صحیح handle_stray_noerror(صحیح err)
{
    صحیح ch;
    جب ((ch = اگلا_c()) == '\\') {
        ch = اگلا_c();
        اگر (ch == '\n') {
    newl:
            file->سطر_عدد++;
        } ورنہ {
            اگر (ch == '\r') {
                ch = اگلا_c();
                اگر (ch == '\n')
                    جاؤ newl;
                *--file->buf_ptr = '\r';
            }
            اگر (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            واپس *--file->buf_ptr = '\\';
        }
    }
    واپس ch;
}

#تعریف_کرو ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ساکن صحیح handle_bs(uint8_t **p)
{
    صحیح c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    واپس c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ساکن صحیح handle_stray(uint8_t **p)
{
    صحیح c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    واپس c;
}

/* handle the complicated stray case */
#تعریف_کرو PEEKC(c, p)\
{\
    c = *++p;\
    اگر (c == '\\')\
        c = handle_stray(&p); \
}

ساکن صحیح skip_spaces(خالی)
{
    صحیح ch;
    --file->buf_ptr;
    کرو {
        ch = ninp();
    } جب (isidnum_جدول[ch - CH_EOF] & IS_SPC);
    واپس ch;
}

/* single line C++ comments */
ساکن uint8_t *parse_سطر_comment(uint8_t *p)
{
    صحیح c;
    برائے(;;) {
        برائے (;;) {
            c = *++p;
    redo:
            اگر (c == '\n' || c == '\\')
                توڑو;
            c = *++p;
            اگر (c == '\n' || c == '\\')
                توڑو;
        }
        اگر (c == '\n')
            توڑو;
        c = handle_bs(&p);
        اگر (c == CH_EOF)
            توڑو;
        اگر (c != '\\')
            جاؤ redo;
    }
    واپس p;
}

/* C comments */
ساکن uint8_t *parse_comment(uint8_t *p)
{
    صحیح c;
    برائے(;;) {
        /* fast skip loop */
        برائے(;;) {
            c = *++p;
        redo:
            اگر (c == '\n' || c == '*' || c == '\\')
                توڑو;
            c = *++p;
            اگر (c == '\n' || c == '*' || c == '\\')
                توڑو;
        }
        /* now we can handle all the cases */
        اگر (c == '\n') {
            file->سطر_عدد++;
        } ورنہ اگر (c == '*') {
            کرو {
                c = *++p;
            } جب (c == '*');
            اگر (c == '\\')
                c = handle_bs(&p);
            اگر (c == '/')
                توڑو;
            جاؤ check_eof;
        } ورنہ {
            c = handle_bs(&p);
        check_eof:
            اگر (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            اگر (c != '\\')
                جاؤ redo;
        }
    }
    واپس p + 1;
}

/* parse a string without interpreting escapes */
ساکن uint8_t *parse_pp_string(uint8_t *p, صحیح sep, CString *str)
{
    صحیح c;
    برائے(;;) {
        c = *++p;
    redo:
        اگر (c == sep) {
            توڑو;
        } ورنہ اگر (c == '\\') {
            c = handle_bs(&p);
            اگر (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } ورنہ اگر (c == '\\') {
                اگر (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                اگر (c == '\\') {
                    c = handle_bs(&p);
                    اگر (c == CH_EOF)
                        جاؤ unterminated_string;
                }
                جاؤ جوڑو_char;
            } ورنہ {
                جاؤ redo;
            }
        } ورنہ اگر (c == '\n') {
        جوڑو_lf:
            اگر (ACCEPT_LF_اندر_لڑیاں) {
                file->سطر_عدد++;
                جاؤ جوڑو_char;
            } ورنہ اگر (str) { /* not skipping */
                جاؤ unterminated_string;
            } ورنہ {
                //tcc_warning("missing terminating %c character", sep);
                واپس p;
            }
        } ورنہ اگر (c == '\r') {
            c = *++p;
            اگر (c == '\\')
                c = handle_bs(&p);
            اگر (c == '\n')
                جاؤ جوڑو_lf;
            اگر (c == CH_EOF)
                جاؤ unterminated_string;
            اگر (str)
                cstr_ccat(str, '\r');
            جاؤ redo;
        } ورنہ {
        جوڑو_char:
            اگر (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    واپس p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ساکن خالی preprocess_skip(خالی)
{
    صحیح a, آغاز_کا_سطر, c, اندر_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_آغاز:
    آغاز_کا_سطر = 1;
    اندر_warn_or_error = 0;
    برائے(;;) {
        c = *p;
        انتخاب(c) {
        حالت ' ':
        حالت '\t':
        حالت '\f':
        حالت '\v':
        حالت '\r':
            p++;
            جاری;
        حالت '\n':
            file->سطر_عدد++;
            p++;
            جاؤ redo_آغاز;
        حالت '\\':
            c = handle_bs(&p);
            اگر (c == CH_EOF)
                expect("#endif");
            اگر (c == '\\')
                ++p;
            جاری;
        /* skip strings */
        حالت '\"':
        حالت '\'':
            اگر (اندر_warn_or_error)
                جاؤ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, تہی);
            توڑو;
        /* skip comments */
        حالت '/':
            اگر (اندر_warn_or_error)
                جاؤ _default;
            ++p;
            c = handle_bs(&p);
            اگر (c == '*') {
                p = parse_comment(p);
            } ورنہ اگر (c == '/') {
                p = parse_سطر_comment(p);
            }
            جاری;
        حالت '#':
            p++;
            اگر (آغاز_کا_سطر) {
                file->buf_ptr = p;
                اگلا_nomacro();
                p = file->buf_ptr;
                اگر (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    جاؤ the_انتہا;
                اگر (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                ورنہ اگر (tok == TOK_ENDIF)
                    a--;
                ورنہ اگر( tok == TOK_ERROR || tok == TOK_WARNING)
                    اندر_warn_or_error = 1;
                ورنہ اگر (tok == TOK_LINEFEED)
                    جاؤ redo_آغاز;
                ورنہ اگر (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_سطر_comment(p - 1);
            }
#اگر !defined(TCC_ہدف_ARM) && !defined(TCC_ہدف_ARM64)
            ورنہ اگر (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_سطر_comment(p - 1);
#ورنہ
            /* ARM/ARM64 assembly uses '#' for constants */
#اگر_ختم
            توڑو;
_default:
        طےشدہ:
            p++;
            توڑو;
        }
        آغاز_کا_سطر = 0;
    }
 the_انتہا: ;
    file->buf_ptr = p;
}

#اگر 0
/* return the number of additional 'ints' necessary to store the
   token */
ساکن اندرونی صحیح tok_سائز(ثابت صحیح *p)
{
    انتخاب(*p) {
        /* 4 bytes */
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_CFLOAT:
    حالت TOK_LINENUM:
        واپس 1 + 1;
    حالت TOK_STR:
    حالت TOK_LSTR:
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        واپس 1 + 1 + (p[1] + 3) / 4;
    حالت TOK_CLONG:
    حالت TOK_CULONG:
	واپس 1 + LONG_سائز / 4;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
        واپس 1 + 2;
    حالت TOK_CLDOUBLE:
        واپس 1 + LDOUBLE_الفاظ;
    طےشدہ:
        واپس 1 + 0;
    }
}
#اگر_ختم

/* token string handling */
ST_INLN خالی tok_str_new(TokenString *s)
{
    s->str = تہی;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->آخری_سطر_عدد = -1;
}

ST_FUNC TokenString *tok_str_alloc(خالی)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, حجم *str);
    tok_str_new(str);
    واپس str;
}

ST_FUNC خالی tok_str_free_str(صحیح *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC خالی tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC صحیح *tok_str_realloc(TokenString *s, صحیح new_سائز)
{
    صحیح *str, سائز;

    سائز = s->allocated_len;
    اگر (سائز < 16)
        سائز = 16;
    جب (سائز < new_سائز)
        سائز = سائز * 2;
    اگر (سائز > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, سائز * حجم(صحیح));
        s->allocated_len = سائز;
        s->str = str;
    }
    واپس s->str;
}

ST_FUNC خالی tok_str_جوڑو(TokenString *s, صحیح t)
{
    صحیح len, *str;

    len = s->len;
    str = s->str;
    اگر (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC خالی begin_macro(TokenString *str, صحیح alloc)
{
    str->alloc = alloc;
    str->پچھلا = macro_ڈھیر;
    str->پچھلا_ptr = macro_ptr;
    str->save_سطر_عدد = file->سطر_عدد;
    macro_ptr = str->str;
    macro_ڈھیر = str;
}

ST_FUNC خالی انتہا_macro(خالی)
{
    TokenString *str = macro_ڈھیر;
    macro_ڈھیر = str->پچھلا;
    macro_ptr = str->پچھلا_ptr;
    file->سطر_عدد = str->save_سطر_عدد;
    اگر (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } ورنہ {
        اگر (str->alloc == 2)
            str->str = تہی; /* don't free */
        tok_str_free(str);
    }
}

ساکن خالی tok_str_add2(TokenString *s, صحیح t, CValue *cv)
{
    صحیح len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    اگر (len + TOK_MAX_سائز >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_سائز + 1);
    str[len++] = t;
    انتخاب(t) {
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_CFLOAT:
    حالت TOK_LINENUM:
#اگر LONG_سائز == 4
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#اگر_ختم
        str[len++] = cv->tab[0];
        توڑو;
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
    حالت TOK_STR:
    حالت TOK_LSTR:
        {
            /* Insert the string into the int array. */
            سائز_t nb_الفاظ =
                1 + (cv->str.سائز + حجم(صحیح) - 1) / حجم(صحیح);
            اگر (len + nb_الفاظ >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_الفاظ + 1);
            str[len] = cv->str.سائز;
            حافظہ_نقل(&str[len + 1], cv->str.ڈیٹا, cv->str.سائز);
            len += nb_الفاظ;
        }
        توڑو;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
#اگر LONG_سائز == 8
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#اگر_ختم
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        توڑو;
    حالت TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        اگر (LDOUBLE_الفاظ >= 3)
        str[len++] = cv->tab[2];
        اگر (LDOUBLE_الفاظ >= 4)
        str[len++] = cv->tab[3];
    طےشدہ:
        توڑو;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC خالی tok_str_جوڑو_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    اگر (file->سطر_عدد != s->آخری_سطر_عدد) {
        s->آخری_سطر_عدد = file->سطر_عدد;
        cval.i = s->آخری_سطر_عدد;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ساکن خالی tok_str_add2_spc(TokenString *s, صحیح t, CValue *cv)
{
    اگر (s->need_spc == 3)
        tok_str_جوڑو(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ساکن اندرونی خالی tok_get(صحیح *t, ثابت صحیح **pp, CValue *cv)
{
    ثابت صحیح *p = *pp;
    صحیح n, *tab;

    tab = cv->tab;
    انتخاب(*t = *p++) {
#اگر LONG_سائز == 4
    حالت TOK_CLONG:
#اگر_ختم
    حالت TOK_CINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_LINENUM:
        cv->i = *p++;
        توڑو;
#اگر LONG_سائز == 4
    حالت TOK_CULONG:
#اگر_ختم
    حالت TOK_CUINT:
        cv->i = (غیرعلامتی)*p++;
        توڑو;
    حالت TOK_CFLOAT:
	tab[0] = *p++;
	توڑو;
    حالت TOK_STR:
    حالت TOK_LSTR:
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        cv->str.سائز = *p++;
        cv->str.ڈیٹا = (حرف*)p;
        p += (cv->str.سائز + حجم(صحیح) - 1) / حجم(صحیح);
        توڑو;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
#اگر LONG_سائز == 8
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#اگر_ختم
        n = 2;
        جاؤ copy;
    حالت TOK_CLDOUBLE:
        n = LDOUBLE_الفاظ;
    copy:
        کرو
            *tab++ = *p++;
        جب (--n);
        توڑو;
    طےشدہ:
        توڑو;
    }
    *pp = p;
}

#اگر 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#ورنہ
# define TOK_GET(t,p,c) کرو { \
    صحیح _t = **(p); \
    اگر (TOK_HAS_قدر(_t)) \
        tok_get(t, p, c); \
    ورنہ \
        *(t) = _t, ++*(p); \
    } جب (0)
#اگر_ختم

ساکن صحیح macro_is_equal(ثابت صحیح *a, ثابت صحیح *b)
{
    CValue cv;
    صحیح t;

    اگر (!a || !b)
        واپس 1;

    جب (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        اگر (strcmp(tokcstr.ڈیٹا, get_tok_str(t, &cv)))
            واپس 0;
    }
    واپس !(*a || *b);
}

/* defines handling */
ST_INLN خالی define_ڈالو(صحیح v, صحیح macro_type, صحیح *str, Sym *پہلا_arg)
{
    Sym *s, *o;

    o = define_ڈھونڈو(v);
    s = sym_push2(&define_ڈھیر, v, macro_type, 0);
    s->d = str;
    s->اگلا = پہلا_arg;
    جدول_ident[v - TOK_IDENT]->sym_define = s;

    اگر (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, تہی));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC خالی define_undef(Sym *s)
{
    صحیح v = s->v;
    اگر (v >= TOK_IDENT && v < tok_ident)
        جدول_ident[v - TOK_IDENT]->sym_define = تہی;
}

ST_INLN Sym *define_ڈھونڈو(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((غیرعلامتی)v >= (غیرعلامتی)(tok_ident - TOK_IDENT))
        واپس تہی;
    واپس جدول_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC خالی free_متعین_کرتا(Sym *b)
{
    جب (define_ڈھیر != b) {
        Sym *چوٹی = define_ڈھیر;
        define_ڈھیر = چوٹی->پچھلا;
        tok_str_free_str(چوٹی->d);
        define_undef(چوٹی);
        sym_free(چوٹی);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ساکن خالی maybe_تسلسل_test(TCCState *s)
{
    ثابت حرف *p;
    اگر (s->include_ڈھیر_ptr != s->include_ڈھیر)
        واپس;
    p = get_tok_str(tok, تہی);
    اگر (0 != memcmp(p, "test_", 5))
        واپس;
    اگر (0 != --s->تسلسل_test)
        واپس;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ڈالو(tok, MACRO_OBJ, تہی, تہی);
}

ST_FUNC خالی skip_مقصد_eol(صحیح warn)
{
    اگر (tok == TOK_LINEFEED)
        واپس;
    اگر (warn)
        tcc_warning("extra tokens after directive");
    جب (macro_ڈھیر)
        انتہا_macro();
    file->buf_ptr = parse_سطر_comment(file->buf_ptr - 1);
    اگلا_nomacro();
}

ساکن CachedInclude *
تلاش_cached_include(TCCState *s1, ثابت حرف *filename, صحیح جوڑو);

ساکن صحیح parse_include(TCCState *s1, صحیح do_اگلا, صحیح test)
{
    صحیح c, i;
    حرف name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    اگر (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.سائز;
        pstrncpy(name, حجم name, tokcstr.ڈیٹا, i);
        اگلا_nomacro();
    } ورنہ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        برائے (;;) {
            اگلا();
            p = name, i = لڑی_لمبائی(p) - 1;
            اگر (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                توڑو;
            اگر (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, حجم name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    اگر (!test)
        skip_مقصد_eol(1);

    i = do_اگلا ? file->include_اگلا_اشاریہ : -1;
    برائے (;;) {
        ++i;
        اگر (i == 0) {
            /* check absolute include path */
            اگر (!IS_ABSPATH(name))
                جاری;
            buf[0] = '\0';
        } ورنہ اگر (i == 1) {
            /* search in file's dir if "header.h" */
            اگر (c != '\"')
                جاری;
            p = file->true_filename;
            pstrncpy(buf, حجم buf, p, tcc_basename(p) - p);
        } ورنہ {
            صحیح j = i - 2, k = j - s1->nb_include_paths;
            اگر (k < 0)
                p = s1->include_paths[j];
            ورنہ اگر (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            ورنہ اگر (test)
                واپس 0;
            ورنہ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, حجم buf, p);
            pstrcat(buf, حجم buf, "/");
        }
        pstrcat(buf, حجم buf, name);
        e = تلاش_cached_include(s1, buf, 0);
        اگر (e && (define_ڈھونڈو(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#اگر_تعریف_شدہ INC_DEBUG
            لکھو("%s: skipping cached %s\n", file->filename, buf);
#اگر_ختم
            اگر ((s1->verbose | 1) == 3) /* -vv[v] */
                لکھو("=> %*s%s\n",
                   (صحیح)(s1->include_ڈھیر_ptr - s1->include_ڈھیر), "", buf);
            واپس 1;
        }
        اگر (tcc_open(s1, buf) >= 0)
            توڑو;
    }

    اگر (test) {
        tcc_close();
    } ورنہ {
        اگر (s1->include_ڈھیر_ptr >= s1->include_ڈھیر + INCLUDE_ڈھیر_سائز)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ڈھیر_ptr++ = file->پچھلا;
        file->include_اگلا_اشاریہ = i;
#اگر_تعریف_شدہ INC_DEBUG
        لکھو("%s: including %s\n", file->پچھلا->filename, file->filename);
#اگر_ختم
        /* update target deps */
        اگر (s1->gen_deps) {
            BufferedFile *bf = file;
            جب (i == 1 && (bf = bf->پچھلا))
                i = bf->include_اگلا_اشاریہ;
            /* skip system include files */
            اگر (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_جوڑو(&s1->ہدف_deps, &s1->nb_ہدف_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    واپس 1;
}

/* eval an expression for #if/#elif */
ساکن صحیح اظہاریہ_preprocess(TCCState *s1)
{
    صحیح c, t;
    صحیح t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_اظہاریہ = 1;
    جب (1) {
        اگلا(); /* do macro subst */
        t = tok;
        اگر (tok < TOK_IDENT) {
            اگر (tok == TOK_LINEFEED || tok == TOK_EOF)
                توڑو;
            اگر (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } ورنہ اگر (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            اگلا();
            t = tok;
            اگر (t == '(') 
                اگلا();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            اگر (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            اگر (s1->تسلسل_test)
                maybe_تسلسل_test(s1);
            c = 0;
            اگر (define_ڈھونڈو(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK_HAS_INCLUDE_اگلا)
                c = 1;
            اگر (t == '(') {
                اگلا();
                اگر (tok != ')')
                    expect("')'");
            }
            جاؤ c_نمبر;
        } ورنہ اگر (tok == TOK___HAS_INCLUDE ||
                   tok == TOK_HAS_INCLUDE_اگلا) {
            t = tok;
            اگلا();
	    اگر (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            اگر (tok != ')')
                expect("')'");
            جاؤ c_نمبر;
        } ورنہ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_نمبر:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_جوڑو_tok(str);
    }
    اگر (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_جوڑو(str, TOK_EOF); /* simulate end of file */
    pp_اظہاریہ = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    اگلا();
    c = اظہاریہ_const();
    اگر (tok != TOK_EOF)
        tcc_error("...");
    pp_اظہاریہ = 0;
    انتہا_macro();
    tok = t; /* restore LF or EOF */
    واپس c != 0;
}

ST_FUNC خالی pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_اظہاریہ, 0));
    macro_ptr = macro_ڈھیر->str;
    جب (اگلا(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC خالی parse_define(خالی)
{
    Sym *s, *پہلا, **ps;
    صحیح v, t, varg, is_vaargs, t0;
    صحیح saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    اگر (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    پہلا = تہی;
    t = MACRO_OBJ;
    /* We have to parse the whole define as if not in asm mode, in particular
       no line comment with '#' must be ignored.  Also for function
       macros the argument list must be parsed without '.' being an ID
       character.  */
    parse_flags = ((parse_flags & ~PARSE_FLAG_ASM_FILE) | PARSE_FLAG_SPACES);
    /* '(' must be just after macro definition for MACRO_FUNC */
    اگلا_nomacro();
    parse_flags &= ~PARSE_FLAG_SPACES;
    is_vaargs = 0;
    اگر (tok == '(') {
        صحیح dotid = سیٹ_idnum('.', 0);
        اگلا_nomacro();
        ps = &پہلا;
        اگر (tok != ')') برائے (;;) {
            varg = tok;
            اگلا_nomacro();
            is_vaargs = 0;
            اگر (varg == TOK_DOTS) {
                varg = TOK_VA_دلائل;
                is_vaargs = 1;
            } ورنہ اگر (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                اگلا_nomacro();
            }
            اگر (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ڈھیر, varg | SYM_میدان, is_vaargs, 0);
            *ps = s;
            ps = &s->اگلا;
            اگر (tok == ')')
                توڑو;
            اگر (tok != ',' || is_vaargs)
                جاؤ bad_list;
            اگلا_nomacro();
        }
        parse_flags |= PARSE_FLAG_SPACES;
        اگلا_nomacro();
        t = MACRO_FUNC;
        سیٹ_idnum('.', dotid);
    }

    /* The body of a macro definition should be parsed such that identifiers
       are parsed like the file mode determines (i.e. with '.' being an
       ID character in asm mode).  But '#' should be retained instead of
       regarded as line comment leader, so still don't set ASM_FILE
       in parse_flags. */
    parse_flags |= PARSE_FLAG_ACCEPT_STRAYS | PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED;
    tok_str_new(&str);
    t0 = 0;
    جب (tok != TOK_LINEFEED && tok != TOK_EOF) {
        اگر (is_space(tok)) {
            str.need_spc |= 1;
        } ورنہ {
            اگر (TOK_TWOSHARPS == tok) {
                اگر (0 == t0)
                    جاؤ bad_twosharp;
                tok = TOK_PPJOIN;
                t |= MACRO_JOIN;
            }
            tok_str_add2_spc(&str, tok, &tokc);
            t0 = tok;
        }
        اگلا_nomacro();
    }
    parse_flags = saved_parse_flags;
    tok_str_جوڑو(&str, 0);
    اگر (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ڈالو(v, t, str.str, پہلا);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ساکن CachedInclude *تلاش_cached_include(TCCState *s1, ثابت حرف *filename, صحیح جوڑو)
{
    ثابت حرف *s, *basename;
    غیرعلامتی صحیح h;
    CachedInclude *e;
    صحیح c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    جب ((c = (غیرعلامتی حرف)*s) != 0) {
#اگر_تعریف_شدہ _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#ورنہ
        h = TOK_HASH_FUNC(h, c);
#اگر_ختم
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_سائز - 1);

    i = s1->cached_includes_hash[h];
    برائے(;;) {
        اگر (i == 0)
            توڑو;
        e = s1->cached_includes[i - 1];
        اگر (0 == PATHCMP(filename, e->filename))
            واپس e;
        اگر (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            واپس e;
        i = e->hash_اگلا;
    }
    اگر (!جوڑو)
        واپس تہی;

    e = tcc_malloc(حجم(CachedInclude) + (len = لڑی_لمبائی(filename)));
    حافظہ_نقل(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_جوڑو(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_اگلا = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#اگر_تعریف_شدہ INC_DEBUG
    لکھو("adding cached '%s'\n", filename);
#اگر_ختم
    واپس e;
}

ساکن صحیح pragma_parse(TCCState *s1)
{
    اگلا_nomacro();
    اگر (tok == TOK_ڈالو_macro || tok == TOK_نکالو_macro) {
        صحیح t = tok, v;
        Sym *s;

        اگر (اگلا(), tok != '(')
            جاؤ pragma_err;
        اگر (اگلا(), tok != TOK_STR)
            جاؤ pragma_err;
        v = tok_alloc(tokc.str.ڈیٹا, tokc.str.سائز - 1)->tok;
        اگر (اگلا(), tok != ')')
            جاؤ pragma_err;
        اگر (t == TOK_ڈالو_macro) {
            جب (تہی == (s = define_ڈھونڈو(v)))
                define_ڈالو(v, 0, تہی, تہی);
            s->type.ref = s; /* set push boundary */
        } ورنہ {
            برائے (s = define_ڈھیر; s; s = s->پچھلا)
                اگر (s->v == v && s->type.ref == s) {
                    s->type.ref = تہی;
                    توڑو;
                }
        }
        اگر (s)
            جدول_ident[v - TOK_IDENT]->sym_define = s->d ? s : تہی;
        ورنہ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } ورنہ اگر (tok == TOK_once) {
        تلاش_cached_include(s1, file->true_filename, 1)->once = 1;

    } ورنہ اگر (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        واپس 1;

    } ورنہ اگر (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        اگلا();
        skip('(');
        اگر (tok == TOK_ASM_نکالو) {
            اگلا();
            اگر (s1->pack_ڈھیر_ptr <= s1->pack_ڈھیر) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ڈھیر_ptr--;
        } ورنہ {
            صحیح val = 0;
            اگر (tok != ')') {
                اگر (tok == TOK_ASM_ڈالو) {
                    اگلا();
                    اگر (s1->pack_ڈھیر_ptr >= s1->pack_ڈھیر + PACK_ڈھیر_سائز - 1)
                        جاؤ stk_error;
                    val = *s1->pack_ڈھیر_ptr++;
                    اگر (tok != ',')
                        جاؤ pack_سیٹ;
                    اگلا();
                }
                اگر (tok != TOK_CINT)
                    جاؤ pragma_err;
                val = tokc.i;
                اگر (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    جاؤ pragma_err;
                اگلا();
            }
        pack_سیٹ:
            *s1->pack_ڈھیر_ptr = val;
        }
        اگر (tok != ')')
            جاؤ pragma_err;

    } ورنہ اگر (tok == TOK_comment) {
        حرف *p; صحیح t;
        اگلا();
        skip('(');
        t = tok;
        اگلا();
        skip(',');
        اگر (tok != TOK_STR)
            جاؤ pragma_err;
        p = tcc_strdup(tokc.str.ڈیٹا);
        اگلا();
        اگر (tok != ')')
            جاؤ pragma_err;
        اگر (t == TOK_lib) {
            dynarray_جوڑو(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } ورنہ {
            اگر (t == TOK_option)
                tcc_سیٹ_options(s1, p);
            tcc_free(p);
        }

    } ورنہ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        واپس 0;
    }
    اگلا();
    واپس 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC خالی tccpp_putfile(ثابت حرف *filename)
{
    حرف buf[1024];
    buf[0] = 0;
    اگر (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, حجم buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, حجم buf, filename);
#اگر_تعریف_شدہ _WIN32
    normalize_slashes(buf);
#اگر_ختم
    اگر (0 == strcmp(file->filename, buf))
        واپس;
    //printf("new file '%s'\n", buf);
    اگر (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, حجم file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC خالی preprocess(صحیح is_bof)
{
    TCCState *s1 = tcc_state;
    صحیح c, n, saved_parse_flags;
    حرف buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_عدد
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    اگلا_nomacro();
 redo:
    انتخاب(tok) {
    حالت TOK_DEFINE:
        pp_debug_tok = tok;
        اگلا_nomacro();
        pp_debug_symv = tok;
        parse_define();
        توڑو;
    حالت TOK_UNDEF:
        pp_debug_tok = tok;
        اگلا_nomacro();
        pp_debug_symv = tok;
        s = define_ڈھونڈو(tok);
        /* undefine symbol by putting an invalid name */
        اگر (s)
            define_undef(s);
        اگلا_nomacro();
        توڑو;
    حالت TOK_INCLUDE:
    حالت TOK_INCLUDE_اگلا:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        جاؤ the_انتہا;
    حالت TOK_IFNDEF:
        c = 1;
        جاؤ do_ifdef;
    حالت TOK_IF:
        c = اظہاریہ_preprocess(s1);
        جاؤ do_if;
    حالت TOK_IFDEF:
        c = 0;
    do_ifdef:
        اگلا_nomacro();
        اگر (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        اگر (is_bof) {
            اگر (c) {
#اگر_تعریف_شدہ INC_DEBUG
                لکھو("#ifndef %s\n", get_tok_str(tok, تہی));
#اگر_ختم
                file->ifndef_macro = tok;
            }
        }
        اگر (define_ڈھونڈو(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK_HAS_INCLUDE_اگلا)
            c ^= 1;
        اگلا_nomacro();
    do_if:
        اگر (s1->ifdef_ڈھیر_ptr >= s1->ifdef_ڈھیر + IFDEF_ڈھیر_سائز)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ڈھیر_ptr++ = c;
        جاؤ test_skip;
    حالت TOK_ELSE:
        اگلا_nomacro();
        اگر (s1->ifdef_ڈھیر_ptr == s1->ifdef_ڈھیر)
            tcc_error("#else without matching #if");
        اگر (s1->ifdef_ڈھیر_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ڈھیر_ptr[-1] ^= 3);
        جاؤ test_else;
    حالت TOK_ELIF:
        اگر (s1->ifdef_ڈھیر_ptr == s1->ifdef_ڈھیر)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ڈھیر_ptr[-1];
        اگر (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        اگر (c == 1) {
            skip_مقصد_eol(0);
            c = 0;
        } ورنہ {
            c = اظہاریہ_preprocess(s1);
            s1->ifdef_ڈھیر_ptr[-1] = c;
        }
    test_else:
        اگر (s1->ifdef_ڈھیر_ptr == file->ifdef_ڈھیر_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        اگر (!(c & 1)) {
            skip_مقصد_eol(1);
            preprocess_skip();
            is_bof = 0;
            جاؤ redo;
        }
        توڑو;
    حالت TOK_ENDIF:
        اگلا_nomacro();
        اگر (s1->ifdef_ڈھیر_ptr <= file->ifdef_ڈھیر_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ڈھیر_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        اگر (file->ifndef_macro &&
            s1->ifdef_ڈھیر_ptr == file->ifdef_ڈھیر_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        توڑو;

    حالت TOK_سطر:
        parse_flags &= ~PARSE_FLAG_TOK_عدد;
        اگلا();
        اگر (tok != TOK_PPNUM) {
    سطر_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        جاؤ سطر_عدد_2;
    حالت TOK_PPNUM:
        اگر (parse_flags & PARSE_FLAG_ASM_FILE)
            جاؤ ignore;
        c = 0; /* no error with extra tokens */
    سطر_عدد_2:
        برائے (n = 0, q = tokc.str.ڈیٹا; *q; ++q) {
            اگر (!isnum(*q))
                جاؤ سطر_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        اگلا();
        اگر (tok != TOK_LINEFEED) {
            اگر (tok != TOK_PPSTR || tokc.str.ڈیٹا[0] != '"')
                جاؤ سطر_err;
            tokc.str.ڈیٹا[tokc.str.سائز - 2] = 0;
            tccpp_putfile(tokc.str.ڈیٹا + 1);
            اگلا();
            /* skip optional level number & advance to next line */
            skip_مقصد_eol(c);
        }
        اگر (file->fd > 0)
            کل_سطریں += file->سطر_عدد - n;
        file->سطر_عدد = n;
        توڑو;

    حالت TOK_ERROR:
    حالت TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        جب (c != '\n' && c != CH_EOF) {
            اگر ((q - buf) < حجم(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        اگر (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        ورنہ
            tcc_warning("#warning %s", buf);
        اگلا_nomacro();
        توڑو;
    }
    حالت TOK_PRAGMA:
        اگر (!pragma_parse(s1))
            جاؤ ignore;
        توڑو;
    حالت TOK_LINEFEED:
        جاؤ the_انتہا;
    طےشدہ:
        /* ignore gas line comment in an 'S' file. */
        اگر (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            جاؤ ignore;
        اگر (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            جاؤ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_مقصد_eol(0);
        جاؤ the_انتہا;
    }
    skip_مقصد_eol(1);
 the_انتہا:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ساکن خالی parse_escape_string(CString *outstr, ثابت uint8_t *buf, صحیح is_long)
{
    صحیح c, n, i;
    ثابت uint8_t *p;

    p = buf;
    برائے(;;) {
        c = *p;
        اگر (c == '\0')
            توڑو;
        اگر (c == '\\') {
            p++;
            /* escape */
            c = *p;
            انتخاب(c) {
            حالت '0': حالت '1': حالت '2': حالت '3':
            حالت '4': حالت '5': حالت '6': حالت '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                اگر (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    اگر (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                جاؤ جوڑو_char_nonext;
            حالت 'x': i = 0; جاؤ parse_hex_or_ucn;
            حالت 'u': i = 4; جاؤ parse_hex_or_ucn;
            حالت 'U': i = 8; جاؤ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                کرو {
                    c = *p;
                    اگر (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    ورنہ اگر (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    ورنہ اگر (isnum(c))
                        c = c - '0';
                    ورنہ اگر (i >= 0)
                        expect("more hex digits in universal-character-name");
                    ورنہ
                        جاؤ جوڑو_hex_or_ucn;
                    n = (غیرعلامتی) n * 16 + c;
                    p++;
                } جب (--i);
		اگر (is_long) {
    جوڑو_hex_or_ucn:
                    c = n;
		    جاؤ جوڑو_char_nonext;
		}
                cstr_u8cat(outstr, n);
                جاری;
            حالت 'a':
                c = '\a';
                توڑو;
            حالت 'b':
                c = '\b';
                توڑو;
            حالت 'f':
                c = '\f';
                توڑو;
            حالت 'n':
                c = '\n';
                توڑو;
            حالت 'r':
                c = '\r';
                توڑو;
            حالت 't':
                c = '\t';
                توڑو;
            حالت 'v':
                c = '\v';
                توڑو;
            حالت 'e':
                اگر (!gnu_ext)
                    جاؤ invalid_escape;
                c = 27;
                توڑو;
            حالت '\'':
            حالت '\"':
            حالت '\\': 
            حالت '?':
                توڑو;
            طےشدہ:
            invalid_escape:
                اگر (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                ورنہ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                توڑو;
            }
        } ورنہ اگر (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            صحیح cont; /* count of continuation bytes */
            صحیح skip; /* how many bytes should skip when error occurred */
            صحیح i;

            /* decode leading byte */
            اگر (c < 0xC2) {
	            skip = 1; جاؤ invalid_utf8_sequence;
            } ورنہ اگر (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } ورنہ اگر (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } ورنہ اگر (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } ورنہ {
	            skip = 1; جاؤ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            برائے (i = 1; i <= cont; i++) {
                صحیح l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                اگر (i == 1) {
                    انتخاب (c) {
                    حالت 0xE0: l = 0xA0; توڑو;
                    حالت 0xED: h = 0x9F; توڑو;
                    حالت 0xF0: l = 0x90; توڑو;
                    حالت 0xF4: h = 0x8F; توڑو;
                    }
                }

                اگر (p[i] < l || p[i] > h) {
                    skip = i; جاؤ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            جاؤ جوڑو_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            جاؤ جوڑو_char_nonext;

        }
        p++;
    جوڑو_char_nonext:
        اگر (!is_long)
            cstr_ccat(outstr, c);
        ورنہ {
#اگر_تعریف_شدہ TCC_ہدف_PE
            /* store as UTF-16 */
            اگر (c < 0x10000) {
                cstr_wccat(outstr, c);
            } ورنہ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#ورنہ
            cstr_wccat(outstr, c);
#اگر_ختم
        }
    }
    /* add a trailing '\0' */
    اگر (!is_long)
        cstr_ccat(outstr, '\0');
    ورنہ
        cstr_wccat(outstr, '\0');
}

ساکن خالی parse_string(ثابت حرف *s, صحیح len)
{
    uint8_t buf[1000], *p = buf;
    صحیح is_long, sep;

    اگر ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    اگر (len >= حجم buf)
        p = tcc_malloc(len + 1);
    حافظہ_نقل(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    اگر (p != buf)
        tcc_free(p);

    اگر (sep == '\'') {
        صحیح char_سائز, i, n, c;
        /* XXX: make it portable */
        اگر (!is_long)
            tok = TOK_CCHAR, char_سائز = 1;
        ورنہ
            tok = TOK_LCHAR, char_سائز = حجم(nwchar_t);
        n = tokcstr.سائز / char_سائز - 1;
        اگر (n < 1)
            tcc_error("empty character constant");
        اگر (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        برائے (c = i = 0; i < n; ++i) {
            اگر (is_long)
                c = ((nwchar_t *)tokcstr.ڈیٹا)[i];
            ورنہ
                c = (c << 8) | ((حرف *)tokcstr.ڈیٹا)[i];
        }
        tokc.i = c;
    } ورنہ {
        tokc.str.سائز = tokcstr.سائز;
        tokc.str.ڈیٹا = tokcstr.ڈیٹا;
        اگر (!is_long)
            tok = TOK_STR;
        ورنہ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#تعریف_کرو BN_سائز 4

/* bn = (bn << shift) | or_val */
ساکن صحیح bn_lshift(غیرعلامتی صحیح *bn, صحیح سرکاؤ, صحیح or_val)
{
    صحیح i;
    غیرعلامتی صحیح v;
    اگر (bn[BN_سائز - 1] >> (32 - سرکاؤ))
	واپس سرکاؤ;
    برائے(i=0;i<BN_سائز;i++) {
        v = bn[i];
        bn[i] = (v << سرکاؤ) | or_val;
        or_val = v >> (32 - سرکاؤ);
    }
    واپس 0;
}

ساکن خالی bn_zero(غیرعلامتی صحیح *bn)
{
    صحیح i;
    برائے(i=0;i<BN_سائز;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ساکن خالی parse_نمبر(ثابت حرف *p)
{
    صحیح b, t, سرکاؤ, frac_بٹ, s, exp_val, ch;
    حرف *q;
    غیرعلامتی صحیح bn[BN_سائز];
    طویل دوہرا d;

    /*نمبر*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    اگر (t == '.') {
        جاؤ float_frac_parse;
    } ورنہ اگر (t == '0') {
        اگر (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } ورنہ اگر (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    جب (1) {
        اگر (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        ورنہ اگر (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        ورنہ اگر (isnum(ch))
            t = ch - '0';
        ورنہ
            توڑو;
        اگر (t >= b)
            توڑو;
        اگر (q >= token_buf + STRING_MAX_سائز) {
        عدد_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    اگر (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        اگر (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_بٹ = 0;
            *q = '\0';
            اگر (b == 16)
                سرکاؤ = 4;
            ورنہ 
                سرکاؤ = 1;
            bn_zero(bn);
            q = token_buf;
            جب (1) {
                t = *q++;
                اگر (t == '\0') {
                    توڑو;
                } ورنہ اگر (t >= 'a') {
                    t = t - 'a' + 10;
                } ورنہ اگر (t >= 'A') {
                    t = t - 'A' + 10;
                } ورنہ {
                    t = t - '0';
                }
                frac_بٹ -= bn_lshift(bn, سرکاؤ, t);
            }
            اگر (ch == '.') {
                ch = *p++;
                جب (1) {
                    t = ch;
                    اگر (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } ورنہ اگر (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } ورنہ اگر (t >= '0' && t <= '9') {
                        t = t - '0';
                    } ورنہ {
                        توڑو;
                    }
                    اگر (t >= b)
                        tcc_error("invalid digit");
                    frac_بٹ -= bn_lshift(bn, سرکاؤ, t);
                    frac_بٹ += سرکاؤ;
                    ch = *p++;
                }
            }
            اگر (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            اگر (ch == '+') {
                ch = *p++;
            } ورنہ اگر (ch == '-') {
                s = -1;
                ch = *p++;
            }
            اگر (ch < '0' || ch > '9')
                expect("exponent digits");
            جب (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		اگر (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (طویل دوہرا)bn[3] * 79228162514264337593543950336.0L +
	        (طویل دوہرا)bn[2] * 18446744073709551616.0L +
	        (طویل دوہرا)bn[1] * 4294967296.0L +
	        (طویل دوہرا)bn[0];
            d = ldexpl(d, exp_val - frac_بٹ);
            t = toup(ch);
            اگر (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (اعشاری)d;
            } ورنہ اگر (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } ورنہ {
                tok = TOK_CDOUBLE;
                tokc.d = (دوہرا)d;
            }
        } ورنہ {
            /* decimal floats */
            اگر (ch == '.') {
                اگر (q >= token_buf + STRING_MAX_سائز)
                    جاؤ عدد_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                جب (ch >= '0' && ch <= '9') {
                    اگر (q >= token_buf + STRING_MAX_سائز)
                        جاؤ عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            اگر (ch == 'e' || ch == 'E') {
                اگر (q >= token_buf + STRING_MAX_سائز)
                    جاؤ عدد_too_long;
                *q++ = ch;
                ch = *p++;
                اگر (ch == '-' || ch == '+') {
                    اگر (q >= token_buf + STRING_MAX_سائز)
                        جاؤ عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                اگر (ch < '0' || ch > '9')
                    expect("exponent digits");
                جب (ch >= '0' && ch <= '9') {
                    اگر (q >= token_buf + STRING_MAX_سائز)
                        جاؤ عدد_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            اگر (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, تہی);
            } ورنہ اگر (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, تہی);
            } ورنہ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, تہی);
            }
        }
    } ورنہ {
        غیرعلامتی طویل طویل n, n1;
        صحیح lcount, ucount, ov = 0;
        ثابت حرف *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        اگر (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        جب(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            اگر (t == '\0')
                توڑو;
            ورنہ اگر (t >= 'a')
                t = t - 'a' + 10;
            ورنہ اگر (t >= 'A')
                t = t - 'A' + 10;
            ورنہ
                t = t - '0';
            اگر (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            اگر (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        برائے(;;) {
            t = toup(ch);
            اگر (t == 'L') {
                اگر (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                اگر (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } ورنہ اگر (t == 'U') {
                اگر (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } ورنہ {
                توڑو;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        اگر (pp_اظہاریہ)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        اگر (ucount == 0 && b == 10) {
            اگر (lcount <= (LONG_سائز == 4)) {
                اگر (n >= 0x80000000U)
                    lcount = (LONG_سائز == 4) + 1;
            }
            اگر (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } ورنہ {
            اگر (lcount <= (LONG_سائز == 4)) {
                اگر (n >= 0x100000000ULL)
                    lcount = (LONG_سائز == 4) + 1;
                ورنہ اگر (n >= 0x80000000U)
                    ucount = 1;
            }
            اگر (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        اگر (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	اگر (lcount) {
            tok = TOK_CLONG;
            اگر (lcount == 2)
                tok = TOK_CLLONG;
	}
	اگر (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    اگر (ch)
        tcc_error("invalid number");
}


#تعریف_کرو PARSE2(c1, tok1, c2, tok2)              \
    حالت c1:                                    \
        PEEKC(c, p);                            \
        اگر (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } ورنہ {                                \
            tok = tok1;                         \
        }                                       \
        توڑو;

/* return next token without macro substitution */
ساکن خالی اگلا_nomacro(خالی)
{
    صحیح t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    غیرعلامتی صحیح h;

    p = file->buf_ptr;
 redo_no_آغاز:
    c = *p;
    انتخاب(c) {
    حالت ' ':
    حالت '\t':
        tok = c;
        p++;
 maybe_space:
        اگر (parse_flags & PARSE_FLAG_SPACES)
            جاؤ keep_tok_flags;
        جب (isidnum_جدول[*p - CH_EOF] & IS_SPC)
            ++p;
        جاؤ redo_no_آغاز;
    حالت '\f':
    حالت '\v':
    حالت '\r':
        p++;
        جاؤ redo_no_آغاز;
    حالت '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        اگر (c == '\\')
            جاؤ parse_simple;
        اگر (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            اگر (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                جاؤ maybe_newline;
            } ورنہ اگر (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } ورنہ اگر (s1->ifdef_ڈھیر_ptr != file->ifdef_ڈھیر_ptr) {
                tcc_error("missing #endif");
            } ورنہ اگر (s1->include_ڈھیر_ptr == s1->include_ڈھیر) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } ورنہ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                اگر (tok_flags & TOK_FLAG_ENDIF) {
#اگر_تعریف_شدہ INC_DEBUG
                    لکھو("#endif %s\n", get_tok_str(file->ifndef_macro_saved, تہی));
#اگر_ختم
                    تلاش_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ڈھیر_ptr--;
                p = file->buf_ptr;
                جاؤ maybe_newline;
            }
        } ورنہ {
            جاؤ redo_no_آغاز;
        }
        توڑو;

    حالت '\n':
        file->سطر_عدد++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        اگر (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            جاؤ redo_no_آغاز;
        tok = TOK_LINEFEED;
        جاؤ keep_tok_flags;

    حالت '#':
        /* XXX: simplify */
        PEEKC(c, p);
        اگر ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            جاؤ maybe_newline;
        } ورنہ {
            اگر (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } ورنہ {
#اگر !defined(TCC_ہدف_ARM) && !defined(TCC_ہدف_ARM64)
                اگر (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_سطر_comment(p - 1);
                    جاؤ redo_no_آغاز;
                } ورنہ
#اگر_ختم
                {
                    tok = '#';
                }
            }
        }
        توڑو;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    حالت '$':
        اگر (!(isidnum_جدول['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            جاؤ parse_simple;

    حالت 'a': حالت 'b': حالت 'c': حالت 'd':
    حالت 'e': حالت 'f': حالت 'g': حالت 'h':
    حالت 'i': حالت 'j': حالت 'k': حالت 'l':
    حالت 'm': حالت 'n': حالت 'o': حالت 'p':
    حالت 'q': حالت 'r': حالت 's': حالت 't':
    حالت 'u': حالت 'v': حالت 'w': حالت 'x':
    حالت 'y': حالت 'z': 
    حالت 'A': حالت 'B': حالت 'C': حالت 'D':
    حالت 'E': حالت 'F': حالت 'G': حالت 'H':
    حالت 'I': حالت 'J': حالت 'K': 
    حالت 'M': حالت 'N': حالت 'O': حالت 'P':
    حالت 'Q': حالت 'R': حالت 'S': حالت 'T':
    حالت 'U': حالت 'V': حالت 'W': حالت 'X':
    حالت 'Y': حالت 'Z': 
    حالت '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        جب (c = *++p, isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        اگر (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_سائز - 1);
            pts = &hash_ident[h];
            برائے(;;) {
                ts = *pts;
                اگر (!ts)
                    توڑو;
                اگر (ts->len == len && !memcmp(ts->str, p1, len))
                    جاؤ token_ملا;
                pts = &(ts->hash_اگلا);
            }
            ts = tok_alloc_new(pts, (حرف *) p1, len);
        token_ملا: ;
        } ورنہ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (حرف *) p1, len);
            p--;
            PEEKC(c, p);
            جب (isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.ڈیٹا, tokcstr.سائز);
        }
        tok = ts->tok;
        توڑو;
    حالت 'L':
        t = p[1];
        اگر (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            اگر (c == '\'' || c == '\"') {
                is_long = 1;
                جاؤ str_const;
            }
            *--p = c = 'L';
        }
        جاؤ parse_ident_fast;

    حالت '0': حالت '1': حالت '2': حالت '3':
    حالت '4': حالت '5': حالت '6': حالت '7':
    حالت '8': حالت '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_عدد:
        cstr_reset(&tokcstr);
        برائے(;;) {
            cstr_ccat(&tokcstr, t);
            اگر (!((isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((حرف*)tokcstr.ڈیٹا)[0] == '0'
                                && toup(((حرف*)tokcstr.ڈیٹا)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                توڑو;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.سائز = tokcstr.سائز;
        tokc.str.ڈیٹا = tokcstr.ڈیٹا;
        tok = TOK_PPNUM;
        توڑو;

    حالت '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        اگر (isnum(c)) {
            t = '.';
            جاؤ parse_عدد;
        } ورنہ اگر ((isidnum_جدول['.' - CH_EOF] & IS_ID)
                   && (isidnum_جدول[c - CH_EOF] & (IS_ID|IS_عدد))) {
            *--p = c = '.';
            جاؤ parse_ident_fast;
        } ورنہ اگر (c == '.') {
            PEEKC(c, p);
            اگر (c == '.') {
                p++;
                tok = TOK_DOTS;
            } ورنہ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } ورنہ {
            tok = '.';
        }
        توڑو;
    حالت '\'':
    حالت '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        اگر (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.سائز = tokcstr.سائز;
        tokc.str.ڈیٹا = tokcstr.ڈیٹا;
        tok = TOK_PPSTR;
        توڑو;

    حالت '<':
        PEEKC(c, p);
        اگر (c == '=') {
            p++;
            tok = TOK_LE;
        } ورنہ اگر (c == '<') {
            PEEKC(c, p);
            اگر (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } ورنہ {
                tok = TOK_SHL;
            }
        } ورنہ {
            tok = TOK_LT;
        }
        توڑو;
    حالت '>':
        PEEKC(c, p);
        اگر (c == '=') {
            p++;
            tok = TOK_GE;
        } ورنہ اگر (c == '>') {
            PEEKC(c, p);
            اگر (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } ورنہ {
                tok = TOK_SAR;
            }
        } ورنہ {
            tok = TOK_GT;
        }
        توڑو;
        
    حالت '&':
        PEEKC(c, p);
        اگر (c == '&') {
            p++;
            tok = TOK_LAND;
        } ورنہ اگر (c == '=') {
            p++;
            tok = TOK_A_AND;
        } ورنہ {
            tok = '&';
        }
        توڑو;
        
    حالت '|':
        PEEKC(c, p);
        اگر (c == '|') {
            p++;
            tok = TOK_LOR;
        } ورنہ اگر (c == '=') {
            p++;
            tok = TOK_A_OR;
        } ورنہ {
            tok = '|';
        }
        توڑو;

    حالت '+':
        PEEKC(c, p);
        اگر (c == '+') {
            p++;
            tok = TOK_INC;
        } ورنہ اگر (c == '=') {
            p++;
            tok = TOK_A_جوڑو;
        } ورنہ {
            tok = '+';
        }
        توڑو;
        
    حالت '-':
        PEEKC(c, p);
        اگر (c == '-') {
            p++;
            tok = TOK_DEC;
        } ورنہ اگر (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } ورنہ اگر (c == '>') {
            p++;
            tok = TOK_ARROW;
        } ورنہ {
            tok = '-';
        }
        توڑو;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    حالت '/':
        PEEKC(c, p);
        اگر (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            جاؤ maybe_space;
        } ورنہ اگر (c == '/') {
            p = parse_سطر_comment(p);
            tok = ' ';
            جاؤ maybe_space;
        } ورنہ اگر (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } ورنہ {
            tok = '/';
        }
        توڑو;
        
        /* simple tokens */
    حالت '@': /* only used in assembler */
#اگر_تعریف_شدہ TCC_ہدف_ARM /* comment on arm asm */
        اگر (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_سطر_comment(p);
            جاؤ redo_no_آغاز;
        }
#اگر_ختم
    حالت '(':
    حالت ')':
    حالت '[':
    حالت ']':
    حالت '{':
    حالت '}':
    حالت ',':
    حالت ';':
    حالت ':':
    حالت '?':
    حالت '~':
    parse_simple:
        tok = c;
        p++;
        توڑو;
    حالت 0xEF: /* UTF8 BOM ? */
        اگر (p[1] == 0xBB && p[2] == 0xBF && p == file->بفر) {
            p += 3;
            جاؤ redo_no_آغاز;
        }
    طےشدہ:
        اگر (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    جاؤ parse_ident_fast;
        اگر (parse_flags & PARSE_FLAG_ASM_FILE)
            جاؤ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        توڑو;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#اگر defined(PARSE_DEBUG)
    لکھو("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#اگر_ختم
}

#اگر_تعریف_شدہ PP_DEBUG
ساکن صحیح indent;
ساکن خالی define_print(TCCState *s1, صحیح v);
ساکن خالی pp_print(ثابت حرف *پیغام, صحیح v, ثابت صحیح *str)
{
    FILE *fp = tcc_state->ppfp;

    اگر (پیغام[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    ورنہ اگر (پیغام[0] == '+')
         ++indent, ++پیغام;
    ورنہ اگر (پیغام[0] == '-')
        --indent, ++پیغام;

    fprintf(fp, "%*s", indent, "");
    اگر (پیغام[0] == '#') {
        define_print(tcc_state, v);
    } ورنہ {
        tok_print(str, v ? "%s %s" : "%s", پیغام, get_tok_str(v, 0));
    }
}
#تعریف_کرو PP_PRINT(x) pp_print x
#ورنہ
#تعریف_کرو PP_PRINT(x)
#اگر_ختم

ساکن صحیح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحیح *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ساکن صحیح *macro_arg_subst(Sym **nested_list, ثابت صحیح *macro_str, Sym *دلائل)
{
    صحیح t, t0, t1, t2, n;
    ثابت صحیح *st;
    Sym *s;
    CValue cval;
    TokenString str;

#اگر_تعریف_شدہ PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    برائے (s = دلائل, n = 0; s; s = s->پچھلا, ++n);
    جب (n--) {
        برائے (s = دلائل, t = 0; t < n; s = s->پچھلا, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#اگر_ختم

    tok_str_new(&str);
    t0 = t1 = 0;
    جب(1) {
        TOK_GET(&t, &macro_str, &cval);
        اگر (!t)
            توڑو;
        اگر (t == '#') {
            /* stringize */
            کرو t = *macro_str++; جب (t == ' ');
            s = sym_find2(دلائل, t);
            اگر (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                جب (*st != TOK_EOF) {
                    ثابت حرف *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    جب (*s) {
                        اگر (t == TOK_PPSTR && *s != '\'')
                            جوڑو_char(&tokcstr, *s);
                        ورنہ
                            cstr_ccat(&tokcstr, *s);
                        ++s;
                    }
                }
                cstr_ccat(&tokcstr, '\"');
                cstr_ccat(&tokcstr, '\0');
                //printf("\nstringize: <%s>\n", (char *)tokcstr.data);
                /* add string */
                cval.str.سائز = tokcstr.سائز;
                cval.str.ڈیٹا = tokcstr.ڈیٹا;
                tok_str_add2(&str, TOK_PPSTR, &cval);
#اگر_تعریف_شدہ TCC_ہدف_ARM
            } ورنہ اگر ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_جوڑو(&str, '#');
#اگر_ختم
            } ورنہ {
                expect("macro parameter after '#'");
            }
        } ورنہ اگر (t >= TOK_IDENT) {
            s = sym_find2(دلائل, t);
            اگر (s) {
                st = s->d;
                n = 0;
                جب ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                اگر (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    اگر (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        صحیح c = str.str[str.len - 1];
                        جب (str.str[--str.len] != ',')
                            ;
                        اگر (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } ورنہ {
                            /* suppress '##' and add variable */
                            str.len++;
                            اگر (c == ' ')
                                str.str[str.len++] = c;
                            جاؤ جوڑو_var;
                        }
                    } ورنہ {
                        اگر (*st == TOK_EOF)
                            tok_str_جوڑو(&str, TOK_PLCHLDR);
                    }
                } ورنہ {
            جوڑو_var:
		    اگر (!s->e) {
			/* Expand arguments tokens and store them.  In most
			   cases we could also re-expand each argument if
			   used multiple times, but not if the argument
			   contains the __COUNTER__ macro.  */
			TokenString str2;
			tok_str_new(&str2);
			macro_subst(&str2, nested_list, st);
			tok_str_جوڑو(&str2, TOK_EOF);
			s->e = str2.str;
		    }
		    st = s->e;
                }
                جب (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } ورنہ {
                tok_str_جوڑو(&str, t);
            }
        } ورنہ {
            tok_str_add2(&str, t, &cval);
        }
        اگر (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_جوڑو(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    واپس str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ساکن اندرونی صحیح *macro_twosharps(ثابت صحیح *ptr0)
{
    صحیح t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ثابت صحیح *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    برائے (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        اگر (t1 == 0)
            توڑو;
        برائے (;;) {
            n = 0;
            جب ((t2 = ptr[n]) == ' ')
                ++n;
            اگر (t2 != TOK_PPJOIN)
                توڑو;
            ptr += n;
            جب ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            اگر (t2 == TOK_PLCHLDR)
                جاری;
            اگر (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        اگر (tokcstr.سائز) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.سائز);
            حافظہ_نقل(file->بفر, tokcstr.ڈیٹا, tokcstr.سائز);
            tok_flags = 0; /* don't interpret '#' */
            برائے (n = 0;;n = l) {
                اگلا_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                اگر (*file->buf_ptr == 0)
                    توڑو;
                tok_str_جوڑو(&macro_str1, ' ');
                l = file->buf_ptr - file->بفر;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->بفر + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        اگر (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_جوڑو(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    واپس macro_str1.str;
}

ساکن صحیح peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    صحیح c;
    برائے (;;) {
        PEEKC(c, p);
        انتخاب (c) {
        حالت '/':
            PEEKC(c, p);
            اگر (c == '*')
                p = parse_comment(p);
            ورنہ اگر (c == '/')
                p = parse_سطر_comment(p);
            ورنہ {
                c = *--p = '/';
                جاؤ leave;
            }
            --p, c = ' ';
            توڑو;
        حالت ' ': حالت '\t':
            توڑو;
        حالت '\f': حالت '\v': حالت '\r':
            جاری;
        حالت '\n':
            file->سطر_عدد++, tok_flags |= TOK_FLAG_BOL;
            توڑو;
        طےشدہ: leave:
            file->buf_ptr = p;
            واپس c;
        }
        اگر (ws_str)
            tok_str_جوڑو(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ساکن صحیح اگلا_argstream(Sym **nested_list, TokenString *ws_str)
{
    صحیح t;
    Sym *sa;

    جب (macro_ptr) {
        ثابت صحیح *m = macro_ptr;
        جب ((t = *m) != 0) {
            اگر (ws_str) {
                اگر (t != ' ')
                    واپس t;
                ++m;
            } ورنہ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                واپس tok;
            }
        }
        انتہا_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        اگر (sa)
            *nested_list = sa->پچھلا, sym_free(sa);
    }
    اگر (ws_str) {
        واپس peek_file(ws_str);
    } ورنہ {
        اگلا_nomacro();
        اگر (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        واپس tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ساکن صحیح macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    صحیح t;
    صحیح v = s->v;

    PP_PRINT(("#", v, s->d));
    اگر (s->d) {
        صحیح *mstr = s->d;
        صحیح *jstr;
        Sym *sa;
        صحیح ret;

        اگر (s->type.t & MACRO_FUNC) {
            صحیح saved_parse_flags = parse_flags;
            TokenString str;
            صحیح parlevel, i;
            Sym *sa1, *دلائل;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = اگلا_argstream(nested_list, &str);
            اگر (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                اگر (parse_flags & PARSE_FLAG_SPACES)
                    برائے (i = 0; i < str.len; i++)
                        tok_str_جوڑو(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                واپس 0;
            } ورنہ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            دلائل = تہی;
            sa = s->اگلا;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            برائے(;;) {
                کرو {
                    t = اگلا_argstream(nested_list, تہی);
                } جب (t == ' ' || --i);

                اگر (!sa) {
                    اگر (t == ')') /* handle '()' case */
                        توڑو;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            خالی_خانے_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                جب (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    اگر (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    اگر (t == '(')
                        parlevel++;
                    اگر (t == ')')
                        parlevel--;
                    اگر (t == ' ')
                        str.need_spc |= 1;
                    ورنہ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = اگلا_argstream(nested_list, تہی);
                }
                tok_str_جوڑو(&str, TOK_EOF);
                sa1 = sym_push2(&دلائل, sa->v & ~SYM_میدان, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->اگلا;
                اگر (t == ')') {
                    اگر (!sa)
                        توڑو;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    اگر (sa->type.t && gnu_ext)
                        جاؤ خالی_خانے_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, دلائل);
            /* free memory */
            sa = دلائل;
            جب (sa) {
                sa1 = sa->پچھلا;
                tok_str_free_str(sa->d);
                tok_str_free_str(sa->e);
                sym_free(sa);
                sa = sa1;
            }
            parse_flags = saved_parse_flags;
        }

        /* process '##'s (if present) */
        jstr = mstr;
        اگر (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        اگر (sa == *nested_list)
            *nested_list = sa->پچھلا, sym_free(sa);

        اگر (jstr != mstr)
            tok_str_free_str(jstr);
        اگر (mstr != s->d)
            tok_str_free_str(mstr);
        واپس ret;

    } ورنہ {
        CValue cval;
        حرف buf[32], *cstrval = buf;

        /* special macros */
        اگر (v == TOK_سطر_2 || v == TOK_شمار) {
            t = v == TOK_سطر_2 ? file->سطر_عدد : pp_شمار++;
            snprintf(buf, حجم(buf), "%d", t);
            t = TOK_PPNUM;
            جاؤ جوڑو_cstr1;

        } ورنہ اگر (v == TOK___FILE__) {
            cstrval = file->filename;
            جاؤ جوڑو_cstr;

        } ورنہ اگر (v == TOK___DATE__ || v == TOK_وقت) {
            time_t ti;
            ساخت tm *tm;
            وقت(&ti);
            tm = localtime(&ti);
            اگر (v == TOK___DATE__) {
                ساکن حرف ثابت ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, حجم(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } ورنہ {
                snprintf(buf, حجم(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        جوڑو_cstr:
            t = TOK_STR;
        جوڑو_cstr1:
            cval.str.سائز = لڑی_لمبائی(cstrval) + 1;
            cval.str.ڈیٹا = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        واپس 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ساکن صحیح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحیح *macro_str
    )
{
    Sym *s;
    صحیح t, nosubst = 0;
    CValue cval;
    TokenString *str;

#اگر_تعریف_شدہ PP_DEBUG
    صحیح tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#اگر_ختم

    جب (1) {
        TOK_GET(&t, &macro_str, &cval);
        اگر (t == 0 || t == TOK_EOF)
            توڑو;
        اگر (t >= TOK_IDENT) {
            s = define_ڈھونڈو(t);
            اگر (s == تہی || nosubst)
                جاؤ no_subst;
            /* if nested substitution, do nothing */
            اگر (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_میدان;
                جاؤ no_subst;
            }
            str = tok_str_alloc();
            str->str = (صحیح*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            اگر (macro_ڈھیر != str) {
                /* already finished by reading function macro arguments */
                توڑو;
            }
            macro_str = macro_ptr;
            انتہا_macro ();
        } ورنہ اگر (t == ' ') {
            اگر (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } ورنہ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            اگر (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            اگر (t == TOK_DEFINED && pp_اظہاریہ)
                nosubst = 1;
        }
    }

#اگر_تعریف_شدہ PP_DEBUG
    tok_str_جوڑو(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#اگر_ختم
    واپس nosubst;
}

/* return next token with macro substitution */
ST_FUNC خالی اگلا(خالی)
{
    صحیح t;
    جب (macro_ptr) {
redo:
        t = *macro_ptr;
        اگر (TOK_HAS_قدر(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            اگر (t == TOK_LINENUM) {
                file->سطر_عدد = tokc.i;
                جاؤ redo;
            }
            جاؤ convert;
        } ورنہ اگر (t == 0) {
            /* end of macro or unget token string */
            انتہا_macro();
            جاری;
        } ورنہ اگر (t == TOK_EOF) {
            /* do nothing */
        } ورنہ {
            ++macro_ptr;
            t &= ~SYM_میدان; /* remove 'nosubst' marker */
            اگر (t == '\\') {
                اگر (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        واپس;
    }

    اگلا_nomacro();
    t = tok;
    اگر (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_ڈھونڈو(t);
        اگر (s) {
            Sym *nested_list = تہی;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_جوڑو(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            جاؤ redo;
        }
        واپس;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    اگر (t == TOK_PPNUM) {
        اگر  (parse_flags & PARSE_FLAG_TOK_عدد)
            parse_نمبر(tokc.str.ڈیٹا);
    } ورنہ اگر (t == TOK_PPSTR) {
        اگر (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.ڈیٹا, tokc.str.سائز - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN خالی unget_tok(صحیح آخری_tok)
{
    TokenString *str = &unget_buf;
    صحیح alloc = 0;
    اگر (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    اگر (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_جوڑو(str, 0);
    begin_macro(str, alloc);
    tok = آخری_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ساکن ثابت حرف * ثابت ہدف_os_defs =
#اگر_تعریف_شدہ TCC_ہدف_PE
    "_WIN32\0"
# اگر PTR_سائز == 8
    "_WIN64\0"
# endif
#ورنہ
# اگر defined TCC_ہدف_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# ورنہ
    "__linux__\0"
    "__linux\0"
#  اگر TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#اگر_ختم
    ;

ساکن خالی putdef(CString *cs, ثابت حرف *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ساکن خالی putdefs(CString *cs, ثابت حرف *p)
{
    جب (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ساکن خالی tcc_predefs(TCCState *s1, CString *cs, صحیح is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_نسخہ[4]);
    putdefs(cs, ہدف_machine_defs);
    putdefs(cs, ہدف_os_defs);

#اگر_تعریف_شدہ TCC_ہدف_ARM
    اگر (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#اگر_ختم
    اگر (is_asm)
      putdef(cs, "__ASSEMBLER__");
    اگر (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    اگر (s1->output_type == TCC_OUTPUT_حافظہ)
      putdef(cs, "__TCC_RUN__");
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#اگر_ختم
    اگر (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    اگر (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    اگر (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    اگر (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_سائز);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_سائز);
    اگر (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#اگر CONFIG_TCC_PREDEFS
        #شامل "tccdefs_.h" /* include as strings */
#ورنہ
        "#include <tccdefs.h>\n" /* load at runtime */
#اگر_ختم
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC خالی preprocess_آغاز(TCCState *s1, صحیح filetype)
{
    صحیح is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ڈھیر_ptr = s1->include_ڈھیر;
    s1->ifdef_ڈھیر_ptr = s1->ifdef_ڈھیر;
    file->ifdef_ڈھیر_ptr = s1->ifdef_ڈھیر_ptr;
    pp_اظہاریہ = 0;
    pp_شمار = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ڈھیر[0] = 0;
    s1->pack_ڈھیر_ptr = s1->pack_ڈھیر;

    سیٹ_idnum('$', s1->dollars_اندر_identifiers ? IS_ID : 0);
    سیٹ_idnum('.', is_asm ? IS_ID : 0);

    اگر (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        اگر (s1->cmdline_defs.سائز)
          cstr_cat(&cstr, s1->cmdline_defs.ڈیٹا, s1->cmdline_defs.سائز);
        اگر (s1->cmdline_incl.سائز)
          cstr_cat(&cstr, s1->cmdline_incl.ڈیٹا, s1->cmdline_incl.سائز);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ڈھیر_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.سائز);
        حافظہ_نقل(file->بفر, cstr.ڈیٹا, cstr.سائز);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC خالی preprocess_انتہا(TCCState *s1)
{
    جب (macro_ڈھیر)
        انتہا_macro();
    macro_ptr = تہی;
    جب (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC صحیح سیٹ_idnum(صحیح c, صحیح val)
{
    صحیح پچھلا = isidnum_جدول[c - CH_EOF];
    isidnum_جدول[c - CH_EOF] = val;
    واپس پچھلا;
}

ST_FUNC خالی tccpp_new(TCCState *s)
{
    صحیح i, c;
    ثابت حرف *p, *r;

    /* init isid table */
    برائے(i = CH_EOF; i<128; i++)
        سیٹ_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_عدد
            : 0);

    برائے(i = 128; i<256; i++)
        سیٹ_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_سائز);
    tal_new(&tokstr_alloc, TOKSTR_TAL_سائز);

    memset(hash_ident, 0, TOK_HASH_سائز * حجم(TokenSym *));
    memset(s->cached_includes_hash, 0, حجم s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_سائز);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_سائز);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_سائز);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    جب (*p) {
        r = p;
        برائے(;;) {
            c = *r++;
            اگر (c == '\0')
                توڑو;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ڈالو(TOK_سطر_2, MACRO_OBJ, تہی, تہی);
    define_ڈالو(TOK___FILE__, MACRO_OBJ, تہی, تہی);
    define_ڈالو(TOK___DATE__, MACRO_OBJ, تہی, تہی);
    define_ڈالو(TOK_وقت, MACRO_OBJ, تہی, تہی);
    define_ڈالو(TOK_شمار, MACRO_OBJ, تہی, تہی);
}

ST_FUNC خالی tccpp_delete(TCCState *s)
{
    صحیح i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    اگر (n > کل_idents)
        کل_idents = n;
    برائے (i = n; --i >= 0;)
        tal_free(&toksym_alloc, جدول_ident[i]);
    tcc_free(جدول_ident);
    جدول_ident = تہی;

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

ساکن صحیح pp_need_space(صحیح a, صحیح b);

ساکن خالی tok_print(ثابت صحیح *str, ثابت حرف *پیغام, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    صحیح t, t0, s;
    CValue cval;

    va_start(ap, پیغام);
    vfprintf(fp, پیغام, ap);
    va_end(ap);

    s = t0 = 0;
    جب (str) {
	TOK_GET(&t, &str, &cval);
	اگر (t == 0 || t == TOK_EOF)
	    توڑو;
        اگر (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ساکن خالی pp_سطر(TCCState *s1, BufferedFile *f, صحیح level)
{
    صحیح d = f->سطر_عدد - f->سطر_ref;

    اگر (s1->dflag & 4)
	واپس;

    اگر (s1->Pflag == سطر_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } ورنہ اگر (level == 0 && f->سطر_ref && d < 8) {
	جب (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } ورنہ اگر (s1->Pflag == سطر_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->سطر_عدد, f->filename);
    } ورنہ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->سطر_عدد, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->سطر_ref = f->سطر_عدد;
}

ساکن خالی define_print(TCCState *s1, صحیح v)
{
    FILE *fp;
    Sym *s;

    s = define_ڈھونڈو(v);
    اگر (تہی == s || تہی == s->d)
        واپس;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, تہی));
    اگر (s->type.t & MACRO_FUNC) {
        Sym *a = s->اگلا;
        fprintf(fp,"(");
        اگر (a)
            برائے (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, تہی));
                اگر (!(a = a->اگلا))
                    توڑو;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ساکن خالی pp_debug_متعین_کرتا(TCCState *s1)
{
    صحیح v, t;
    ثابت حرف *vs;
    FILE *fp;

    t = pp_debug_tok;
    اگر (t == 0)
        واپس;

    file->سطر_عدد--;
    pp_سطر(s1, file, 0);
    file->سطر_ref = ++file->سطر_عدد;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, تہی);
    اگر (t == TOK_DEFINE) {
        define_print(s1, v);
    } ورنہ اگر (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } ورنہ اگر (t == TOK_ڈالو_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } ورنہ اگر (t == TOK_نکالو_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ساکن صحیح pp_need_space(صحیح a, صحیح b)
{
    واپس 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ساکن صحیح pp_check_he0xE(صحیح t, ثابت حرف *p)
{
    اگر (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        واپس 'E';
    واپس t;
}

/* Preprocess the current file */
ST_FUNC صحیح tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    صحیح token_نظر_آیا, spcs, level;
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
    اگر (s1->Pflag == سطر_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_عدد, s1->Pflag = 1;

    اگر (s1->do_bench) {
	/* for PP benchmarks */
	کرو اگلا(); جب (tok != TOK_EOF);
	واپس 0;
    }

    token_نظر_آیا = TOK_LINEFEED, spcs = 0, level = 0;
    اگر (file->پچھلا)
        pp_سطر(s1, file->پچھلا, level++);
    pp_سطر(s1, file, level);

    برائے (;;) {
        iptr = s1->include_ڈھیر_ptr;
        اگلا();
        اگر (tok == TOK_EOF)
            توڑو;

        level = s1->include_ڈھیر_ptr - iptr;
        اگر (level) {
            اگر (level > 0)
                pp_سطر(s1, *iptr, 0);
            pp_سطر(s1, file, level);
        }
        اگر (s1->dflag & 7) {
            pp_debug_متعین_کرتا(s1);
            اگر (s1->dflag & 4)
                جاری;
        }

        اگر (is_space(tok)) {
            اگر (spcs < حجم white - 1)
                white[spcs++] = tok;
            جاری;
        } ورنہ اگر (tok == TOK_LINEFEED) {
            spcs = 0;
            اگر (token_نظر_آیا == TOK_LINEFEED)
                جاری;
            ++file->سطر_ref;
        } ورنہ اگر (token_نظر_آیا == TOK_LINEFEED) {
            pp_سطر(s1, file, 0);
        } ورنہ اگر (spcs == 0 && pp_need_space(token_نظر_آیا, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_نظر_آیا = pp_check_he0xE(tok, p);
    }
    واپس 0;
}

/* ------------------------------------------------------------------------- */
