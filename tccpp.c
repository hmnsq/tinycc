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
#شامل "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA صحیح tok_flags;
ST_DATA صحیح parse_flags;

ST_DATA ساختار BufferedFile *file;
ST_DATA صحیح tok;
ST_DATA CValue tokc;
ST_DATA ثابت صحیح *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA صحیح tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA صحیح pp_عبارت;

/* ------------------------------------------------------------------------- */

ایستا TokenSym *hash_ident[TOK_HASH_SIZE];
ایستا نویسه token_buf[STRING_MAX_SIZE + 1];
ایستا CString cstr_buf;
ایستا TokenString tokstr_buf;
ایستا TokenString unget_buf;
ایستا unsigned نویسه isidnum_table[256 - CH_EOF];
ایستا صحیح pp_debug_tok, pp_debug_symv;
ایستا صحیح pp_counter;
ایستا تهی tok_print(ثابت صحیح *str, ثابت نویسه *پیام, ...);
ایستا تهی next_nomacro(تهی);
ایستا تهی parse_عدد(ثابت نویسه *p);
ایستا تهی parse_string(ثابت نویسه *p, صحیح len);

ایستا ساختار TinyAlloc *toksym_alloc;
ایستا ساختار TinyAlloc *tokstr_alloc;

ایستا TokenString *macro_پشته;

ایستا ثابت نویسه tcc_keywords[] = 
#define DEF(id, str) str "\0"
#شامل "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
ایستا ثابت unsigned نویسه tok_two_chars[] =
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

ST_FUNC تهی skip(صحیح c)
{
    اگر (tok != c) {
        نویسه tmp[40];
        pstrcpy(tmp, اندازه tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC تهی expect(ثابت نویسه *پیام)
{
    tcc_error("%s expected", پیام);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#وگرنه
#اگر !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#وگرنه
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ثابت نویسه *sfile, صحیح sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

تعریفنوع ساختار TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ساختار TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#اگر TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    اجتماع {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

تعریفنوع ساختار tal_header_t {
    size_t  size; /* word align */
#اگر TAL_DEBUG
    صحیح     سطر_رقم; /* negative line_num used for double free check */
    نویسه    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (اندازه (size_t) - 1)) & ~(اندازه (size_t) - 1))

/* ------------------------------------------------------------------------- */

ایستا TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(اندازه(TinyAlloc) - اندازه (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#اگر TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    بازگشت al;
}

ایستا تهی tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#اگر TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#اگر TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#اگر TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    اگر (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        وقتی (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            اگر (header->سطر_رقم > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->سطر_رقم, (صحیح)header->size);
            }
            p += header->size + اندازه(tal_header_t);
        }
#اگر TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    اگر (al)
        برو tail_call;
    *pal = al;
}

ایستا تهی tal_free_impl(TinyAlloc **pal, تهی *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **بالاترین = pal;
    tal_header_t *header;

    اگر (!p)
        بازگشت;
    header = (tal_header_t *)p - 1;
#اگر TAL_DEBUG
    اگر (header->سطر_رقم < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (صحیح)-header->سطر_رقم, (صحیح)header->size);
    } وگرنه
        header->سطر_رقم = -header->سطر_رقم;
#endif
    al = *pal;
    وقتی ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    اگر (0 == --al->nb_allocs) {
        *pal = al->next;
        اگر ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } وگرنه {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *بالاترین, *بالاترین = al;
        }
    } وگرنه اگر ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

ایستا تهی *tal_realloc_impl(TinyAlloc **pal, تهی *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    تهی *ret;
    unsigned adj_size = TAL_ALIGN(size) + اندازه(tal_header_t);
    TinyAlloc *al = *pal;

    اگر (p) {
        /* reallpc case */
        وقتی ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        اگر ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        اگر (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            بازگشت ret;
        } وگرنه اگر (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#اگر TAL_DEBUG
            header->سطر_رقم = -header->سطر_رقم;
#endif
        }
    } وگرنه {
        /* new alloc case */
        وقتی (al->p + adj_size > al->bufend) {
            al = al->next;
            اگر (!al) {
                unsigned new_size = (*pal)->size;
                اگر (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                بشکن;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - اندازه(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#اگر  TAL_DEBUG
    {
        صحیح ofs = strlen(sfile) + 1 - اندازه header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->سطر_رقم = sline;
#اگر TAL_INFO
        اگر (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        اگر (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    بازگشت ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ایستا تهی cstr_realloc(CString *cstr, صحیح new_size)
{
    صحیح size;

    size = cstr->size_allocated;
    اگر (size < 8)
        size = 8; /* no need to allocate a too small first string */
    وقتی (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN تهی cstr_ccat(CString *cstr, صحیح ch)
{
    صحیح size;
    size = cstr->size + 1;
    اگر (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN نویسه *unicode_to_utf8 (نویسه *b, uint32_t Uc)
{
    اگر (Uc<0x80) *b++=Uc;
    وگرنه اگر (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    وگرنه اگر (Uc-0xd800u<0x800) برو error;
    وگرنه اگر (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    وگرنه اگر (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    وگرنه error: tcc_error("0x%x is not a valid universal character", Uc);
    بازگشت b;
}

/* add a unicode character expanded into utf8 */
ST_INLN تهی cstr_u8cat(CString *cstr, صحیح ch)
{
    نویسه buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC تهی cstr_cat(CString *cstr, ثابت نویسه *str, صحیح len)
{
    صحیح size;
    اگر (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    اگر (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC تهی cstr_wccat(CString *cstr, صحیح ch)
{
    صحیح size;
    size = cstr->size + اندازه(nwchar_t);
    اگر (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - اندازه(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC تهی cstr_new(CString *cstr)
{
    memset(cstr, 0, اندازه(CString));
}

/* free string and reset it to NULL */
ST_FUNC تهی cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC تهی cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC صحیح cstr_vprintf(CString *cstr, ثابت نویسه *fmt, va_list ap)
{
    va_list v;
    صحیح len, size = 80;
    برای (;;) {
        size += cstr->size;
        اگر (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        اگر (len >= 0 && len < size)
            بشکن;
        size *= 2;
    }
    cstr->size += len;
    بازگشت len;
}

ST_FUNC صحیح cstr_printf(CString *cstr, ثابت نویسه *fmt, ...)
{
    va_list ap; صحیح len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    بازگشت len;
}

/* XXX: unicode ? */
ایستا تهی add_char(CString *cstr, صحیح c)
{
    اگر (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    اگر (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } وگرنه {
        cstr_ccat(cstr, '\\');
        اگر (c == '\n') {
            cstr_ccat(cstr, 'n');
        } وگرنه {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ایستا TokenSym *tok_alloc_new(TokenSym **pts, ثابت نویسه *str, صحیح len)
{
    TokenSym *ts, **ptable;
    صحیح i;

    اگر (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    اگر ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * اندازه(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, اندازه(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = پوچ;
    ts->sym_label = پوچ;
    ts->sym_struct = پوچ;
    ts->sym_identifier = پوچ;
    ts->len = len;
    ts->hash_next = پوچ;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    بازگشت ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ثابت نویسه *str, صحیح len)
{
    TokenSym *ts, **pts;
    صحیح i;
    unsigned صحیح h;
    
    h = TOK_HASH_INIT;
    برای(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned نویسه *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    برای(;;) {
        ts = *pts;
        اگر (!ts)
            بشکن;
        اگر (ts->len == len && !memcmp(ts->str, str, len))
            بازگشت ts;
        pts = &(ts->hash_next);
    }
    بازگشت tok_alloc_new(pts, str, len);
}

ST_FUNC صحیح tok_alloc_const(ثابت نویسه *str)
{
    بازگشت tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ثابت نویسه *get_tok_str(صحیح v, CValue *cv)
{
    نویسه *p;
    صحیح i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    انتخاب(v) {
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CLONG:
    حالت TOK_CULONG:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        بشکن;
    حالت TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    حالت TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        بشکن;
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        بازگشت (نویسه*)cv->str.data;
    حالت TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    حالت TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        اگر (v == TOK_STR) {
            len = cv->str.size - 1;
            برای(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned نویسه *)cv->str.data)[i]);
        } وگرنه {
            len = (cv->str.size / اندازه(nwchar_t)) - 1;
            برای(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        بشکن;

    حالت TOK_CFLOAT:
        بازگشت strcpy(p, "<float>");
    حالت TOK_CDOUBLE:
        بازگشت strcpy(p, "<double>");
    حالت TOK_CLDOUBLE:
        بازگشت strcpy(p, "<long double>");
    حالت TOK_LINENUM:
        بازگشت strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    حالت TOK_LT:
        v = '<';
        برو addv;
    حالت TOK_GT:
        v = '>';
        برو addv;
    حالت TOK_DOTS:
        بازگشت strcpy(p, "...");
    حالت TOK_A_SHL:
        بازگشت strcpy(p, "<<=");
    حالت TOK_A_SAR:
        بازگشت strcpy(p, ">>=");
    حالت TOK_EOF:
        بازگشت strcpy(p, "<eof>");
    حالت 0: /* anonymous nameless symbols */
        بازگشت strcpy(p, "<no name>");
    پیشفرض:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        اگر (v < TOK_IDENT) {
            /* search in two bytes table */
            ثابت unsigned نویسه *q = tok_two_chars;
            وقتی (*q) {
                اگر (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    بازگشت cstr_buf.data;
                }
                q += 3;
            }
            اگر (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                بشکن;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } وگرنه اگر (v < tok_ident) {
            بازگشت table_ident[v - TOK_IDENT]->str;
        } وگرنه اگر (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } وگرنه {
            /* should never happen */
            بازگشت پوچ;
        }
        بشکن;
    }
    بازگشت cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ایستا صحیح handle_eob(تهی)
{
    BufferedFile *bf = file;
    صحیح len;

    /* only tries to read if really end of buffer */
    اگر (bf->buf_ptr >= bf->buf_end) {
        اگر (bf->fd >= 0) {
#اگر defined(PARSE_DEBUG)
            len = 1;
#وگرنه
            len = IO_BUF_SIZE;
#endif
            len = اقرأ(bf->fd, bf->buffer, len);
            اگر (len < 0)
                len = 0;
        } وگرنه {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    اگر (bf->buf_ptr < bf->buf_end) {
        بازگشت bf->buf_ptr[0];
    } وگرنه {
        bf->buf_ptr = bf->buf_end;
        بازگشت CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ایستا صحیح next_c(تهی)
{
    صحیح ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    اگر (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    بازگشت ch;
}

/* input with '\[\r]\n' handling. */
ایستا صحیح handle_stray_noerror(صحیح err)
{
    صحیح ch;
    وقتی ((ch = next_c()) == '\\') {
        ch = next_c();
        اگر (ch == '\n') {
    newl:
            file->سطر_رقم++;
        } وگرنه {
            اگر (ch == '\r') {
                ch = next_c();
                اگر (ch == '\n')
                    برو newl;
                *--file->buf_ptr = '\r';
            }
            اگر (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            بازگشت *--file->buf_ptr = '\\';
        }
    }
    بازگشت ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ایستا صحیح handle_bs(uint8_t **p)
{
    صحیح c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    بازگشت c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ایستا صحیح handle_stray(uint8_t **p)
{
    صحیح c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    بازگشت c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    اگر (c == '\\')\
        c = handle_stray(&p); \
}

ایستا صحیح skip_spaces(تهی)
{
    صحیح ch;
    --file->buf_ptr;
    انجامبده {
        ch = ninp();
    } وقتی (isidnum_table[ch - CH_EOF] & IS_SPC);
    بازگشت ch;
}

/* single line C++ comments */
ایستا uint8_t *parse_سطر_comment(uint8_t *p)
{
    صحیح c;
    برای(;;) {
        برای (;;) {
            c = *++p;
    redo:
            اگر (c == '\n' || c == '\\')
                بشکن;
            c = *++p;
            اگر (c == '\n' || c == '\\')
                بشکن;
        }
        اگر (c == '\n')
            بشکن;
        c = handle_bs(&p);
        اگر (c == CH_EOF)
            بشکن;
        اگر (c != '\\')
            برو redo;
    }
    بازگشت p;
}

/* C comments */
ایستا uint8_t *parse_comment(uint8_t *p)
{
    صحیح c;
    برای(;;) {
        /* fast skip loop */
        برای(;;) {
            c = *++p;
        redo:
            اگر (c == '\n' || c == '*' || c == '\\')
                بشکن;
            c = *++p;
            اگر (c == '\n' || c == '*' || c == '\\')
                بشکن;
        }
        /* now we can handle all the cases */
        اگر (c == '\n') {
            file->سطر_رقم++;
        } وگرنه اگر (c == '*') {
            انجامبده {
                c = *++p;
            } وقتی (c == '*');
            اگر (c == '\\')
                c = handle_bs(&p);
            اگر (c == '/')
                بشکن;
            برو check_eof;
        } وگرنه {
            c = handle_bs(&p);
        check_eof:
            اگر (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            اگر (c != '\\')
                برو redo;
        }
    }
    بازگشت p + 1;
}

/* parse a string without interpreting escapes */
ایستا uint8_t *parse_pp_string(uint8_t *p, صحیح sep, CString *str)
{
    صحیح c;
    برای(;;) {
        c = *++p;
    redo:
        اگر (c == sep) {
            بشکن;
        } وگرنه اگر (c == '\\') {
            c = handle_bs(&p);
            اگر (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } وگرنه اگر (c == '\\') {
                اگر (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                اگر (c == '\\') {
                    c = handle_bs(&p);
                    اگر (c == CH_EOF)
                        برو unterminated_string;
                }
                برو add_char;
            } وگرنه {
                برو redo;
            }
        } وگرنه اگر (c == '\n') {
        add_lf:
            اگر (ACCEPT_LF_IN_STRINGS) {
                file->سطر_رقم++;
                برو add_char;
            } وگرنه اگر (str) { /* not skipping */
                برو unterminated_string;
            } وگرنه {
                //tcc_warning("missing terminating %c character", sep);
                بازگشت p;
            }
        } وگرنه اگر (c == '\r') {
            c = *++p;
            اگر (c == '\\')
                c = handle_bs(&p);
            اگر (c == '\n')
                برو add_lf;
            اگر (c == CH_EOF)
                برو unterminated_string;
            اگر (str)
                cstr_ccat(str, '\r');
            برو redo;
        } وگرنه {
        add_char:
            اگر (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    بازگشت p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ایستا تهی preprocess_skip(تهی)
{
    صحیح a, start_of_سطر, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_سطر = 1;
    in_warn_or_error = 0;
    برای(;;) {
        c = *p;
        انتخاب(c) {
        حالت ' ':
        حالت '\t':
        حالت '\f':
        حالت '\v':
        حالت '\r':
            p++;
            ادامه;
        حالت '\n':
            file->سطر_رقم++;
            p++;
            برو redo_start;
        حالت '\\':
            c = handle_bs(&p);
            اگر (c == CH_EOF)
                expect("#endif");
            اگر (c == '\\')
                ++p;
            ادامه;
        /* skip strings */
        حالت '\"':
        حالت '\'':
            اگر (in_warn_or_error)
                برو _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, پوچ);
            بشکن;
        /* skip comments */
        حالت '/':
            اگر (in_warn_or_error)
                برو _default;
            ++p;
            c = handle_bs(&p);
            اگر (c == '*') {
                p = parse_comment(p);
            } وگرنه اگر (c == '/') {
                p = parse_سطر_comment(p);
            }
            ادامه;
        حالت '#':
            p++;
            اگر (start_of_سطر) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                اگر (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    برو the_end;
                اگر (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                وگرنه اگر (tok == TOK_ENDIF)
                    a--;
                وگرنه اگر( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                وگرنه اگر (tok == TOK_LINEFEED)
                    برو redo_start;
                وگرنه اگر (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_سطر_comment(p - 1);
            }
#اگر !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            وگرنه اگر (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_سطر_comment(p - 1);
#وگرنه
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            بشکن;
_default:
        پیشفرض:
            p++;
            بشکن;
        }
        start_of_سطر = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#اگر 0
/* return the number of additional 'ints' necessary to store the
   token */
ایستا درونخطی صحیح tok_size(ثابت صحیح *p)
{
    انتخاب(*p) {
        /* 4 bytes */
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_CFLOAT:
    حالت TOK_LINENUM:
        بازگشت 1 + 1;
    حالت TOK_STR:
    حالت TOK_LSTR:
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        بازگشت 1 + 1 + (p[1] + 3) / 4;
    حالت TOK_CLONG:
    حالت TOK_CULONG:
	بازگشت 1 + LONG_SIZE / 4;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
        بازگشت 1 + 2;
    حالت TOK_CLDOUBLE:
        بازگشت 1 + LDOUBLE_واژگان;
    پیشفرض:
        بازگشت 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN تهی tok_str_new(TokenString *s)
{
    s->str = پوچ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_سطر_رقم = -1;
}

ST_FUNC TokenString *tok_str_alloc(تهی)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, اندازه *str);
    tok_str_new(str);
    بازگشت str;
}

ST_FUNC تهی tok_str_free_str(صحیح *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC تهی tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC صحیح *tok_str_realloc(TokenString *s, صحیح new_size)
{
    صحیح *str, size;

    size = s->allocated_len;
    اگر (size < 16)
        size = 16;
    وقتی (size < new_size)
        size = size * 2;
    اگر (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * اندازه(صحیح));
        s->allocated_len = size;
        s->str = str;
    }
    بازگشت s->str;
}

ST_FUNC تهی tok_str_add(TokenString *s, صحیح t)
{
    صحیح len, *str;

    len = s->len;
    str = s->str;
    اگر (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC تهی begin_macro(TokenString *str, صحیح alloc)
{
    str->alloc = alloc;
    str->prev = macro_پشته;
    str->prev_ptr = macro_ptr;
    str->save_سطر_رقم = file->سطر_رقم;
    macro_ptr = str->str;
    macro_پشته = str;
}

ST_FUNC تهی end_macro(تهی)
{
    TokenString *str = macro_پشته;
    macro_پشته = str->prev;
    macro_ptr = str->prev_ptr;
    file->سطر_رقم = str->save_سطر_رقم;
    اگر (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } وگرنه {
        اگر (str->alloc == 2)
            str->str = پوچ; /* don't free */
        tok_str_free(str);
    }
}

ایستا تهی tok_str_add2(TokenString *s, صحیح t, CValue *cv)
{
    صحیح len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    اگر (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    انتخاب(t) {
    حالت TOK_CINT:
    حالت TOK_CUINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_CFLOAT:
    حالت TOK_LINENUM:
#اگر LONG_SIZE == 4
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        بشکن;
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
    حالت TOK_STR:
    حالت TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_واژگان =
                1 + (cv->str.size + اندازه(صحیح) - 1) / اندازه(صحیح);
            اگر (len + nb_واژگان >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_واژگان + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_واژگان;
        }
        بشکن;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
#اگر LONG_SIZE == 8
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        بشکن;
    حالت TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        اگر (LDOUBLE_واژگان >= 3)
        str[len++] = cv->tab[2];
        اگر (LDOUBLE_واژگان >= 4)
        str[len++] = cv->tab[3];
    پیشفرض:
        بشکن;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC تهی tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    اگر (file->سطر_رقم != s->last_سطر_رقم) {
        s->last_سطر_رقم = file->سطر_رقم;
        cval.i = s->last_سطر_رقم;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ایستا تهی tok_str_add2_spc(TokenString *s, صحیح t, CValue *cv)
{
    اگر (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ایستا درونخطی تهی tok_get(صحیح *t, ثابت صحیح **pp, CValue *cv)
{
    ثابت صحیح *p = *pp;
    صحیح n, *tab;

    tab = cv->tab;
    انتخاب(*t = *p++) {
#اگر LONG_SIZE == 4
    حالت TOK_CLONG:
#endif
    حالت TOK_CINT:
    حالت TOK_CCHAR:
    حالت TOK_LCHAR:
    حالت TOK_LINENUM:
        cv->i = *p++;
        بشکن;
#اگر LONG_SIZE == 4
    حالت TOK_CULONG:
#endif
    حالت TOK_CUINT:
        cv->i = (unsigned)*p++;
        بشکن;
    حالت TOK_CFLOAT:
	tab[0] = *p++;
	بشکن;
    حالت TOK_STR:
    حالت TOK_LSTR:
    حالت TOK_PPNUM:
    حالت TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (نویسه*)p;
        p += (cv->str.size + اندازه(صحیح) - 1) / اندازه(صحیح);
        بشکن;
    حالت TOK_CDOUBLE:
    حالت TOK_CLLONG:
    حالت TOK_CULLONG:
#اگر LONG_SIZE == 8
    حالت TOK_CLONG:
    حالت TOK_CULONG:
#endif
        n = 2;
        برو copy;
    حالت TOK_CLDOUBLE:
        n = LDOUBLE_واژگان;
    copy:
        انجامبده
            *tab++ = *p++;
        وقتی (--n);
        بشکن;
    پیشفرض:
        بشکن;
    }
    *pp = p;
}

#اگر 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#وگرنه
# define TOK_GET(t,p,c) انجامبده { \
    صحیح _t = **(p); \
    اگر (TOK_HAS_مقدار(_t)) \
        tok_get(t, p, c); \
    وگرنه \
        *(t) = _t, ++*(p); \
    } وقتی (0)
#endif

ایستا صحیح macro_is_equal(ثابت صحیح *a, ثابت صحیح *b)
{
    CValue cv;
    صحیح t;

    اگر (!a || !b)
        بازگشت 1;

    وقتی (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        اگر (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            بازگشت 0;
    }
    بازگشت !(*a || *b);
}

/* defines handling */
ST_INLN تهی define_افزودن(صحیح v, صحیح macro_type, صحیح *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_پشته, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    اگر (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, پوچ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC تهی define_undef(Sym *s)
{
    صحیح v = s->v;
    اگر (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = پوچ;
}

ST_INLN Sym *define_find(صحیح v)
{
    v -= TOK_IDENT;
    اگر ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        بازگشت پوچ;
    بازگشت table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC تهی free_defines(Sym *b)
{
    وقتی (define_پشته != b) {
        Sym *بالاترین = define_پشته;
        define_پشته = بالاترین->prev;
        tok_str_free_str(بالاترین->d);
        define_undef(بالاترین);
        sym_free(بالاترین);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ایستا تهی maybe_run_test(TCCState *s)
{
    ثابت نویسه *p;
    اگر (s->include_پشته_ptr != s->include_پشته)
        بازگشت;
    p = get_tok_str(tok, پوچ);
    اگر (0 != memcmp(p, "test_", 5))
        بازگشت;
    اگر (0 != --s->run_test)
        بازگشت;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_افزودن(tok, MACRO_OBJ, پوچ, پوچ);
}

ST_FUNC تهی skip_to_eol(صحیح warn)
{
    اگر (tok == TOK_LINEFEED)
        بازگشت;
    اگر (warn)
        tcc_warning("extra tokens after directive");
    وقتی (macro_پشته)
        end_macro();
    file->buf_ptr = parse_سطر_comment(file->buf_ptr - 1);
    next_nomacro();
}

ایستا CachedInclude *
جستجو_cached_include(TCCState *s1, ثابت نویسه *filename, صحیح add);

ایستا صحیح parse_include(TCCState *s1, صحیح do_next, صحیح test)
{
    صحیح c, i;
    نویسه name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    اگر (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, اندازه name, tokcstr.data, i);
        next_nomacro();
    } وگرنه {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        برای (;;) {
            next();
            p = name, i = strlen(p) - 1;
            اگر (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                بشکن;
            اگر (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, اندازه name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    اگر (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    برای (;;) {
        ++i;
        اگر (i == 0) {
            /* check absolute include path */
            اگر (!IS_ABSPATH(name))
                ادامه;
            buf[0] = '\0';
        } وگرنه اگر (i == 1) {
            /* search in file's dir if "header.h" */
            اگر (c != '\"')
                ادامه;
            p = file->true_filename;
            pstrncpy(buf, اندازه buf, p, tcc_basename(p) - p);
        } وگرنه {
            صحیح j = i - 2, k = j - s1->nb_include_paths;
            اگر (k < 0)
                p = s1->include_paths[j];
            وگرنه اگر (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            وگرنه اگر (test)
                بازگشت 0;
            وگرنه
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, اندازه buf, p);
            pstrcat(buf, اندازه buf, "/");
        }
        pstrcat(buf, اندازه buf, name);
        e = جستجو_cached_include(s1, buf, 0);
        اگر (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            اگر ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (صحیح)(s1->include_پشته_ptr - s1->include_پشته), "", buf);
            بازگشت 1;
        }
        اگر (tcc_open(s1, buf) >= 0)
            بشکن;
    }

    اگر (test) {
        tcc_close();
    } وگرنه {
        اگر (s1->include_پشته_ptr >= s1->include_پشته + INCLUDE_پشته_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_پشته_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        اگر (s1->gen_deps) {
            BufferedFile *bf = file;
            وقتی (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            اگر (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    بازگشت 1;
}

/* eval an expression for #if/#elif */
ایستا صحیح عبارت_preprocess(TCCState *s1)
{
    صحیح c, t;
    صحیح t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_عبارت = 1;
    وقتی (1) {
        next(); /* do macro subst */
        t = tok;
        اگر (tok < TOK_IDENT) {
            اگر (tok == TOK_LINEFEED || tok == TOK_EOF)
                بشکن;
            اگر (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } وگرنه اگر (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            اگر (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            اگر (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            اگر (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            اگر (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            اگر (t == '(') {
                next();
                اگر (tok != ')')
                    expect("')'");
            }
            برو c_عدد;
        } وگرنه اگر (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    اگر (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            اگر (tok != ')')
                expect("')'");
            برو c_عدد;
        } وگرنه {
            /* if undefined macro, replace with zero */
            c = 0;
        c_عدد:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    اگر (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_عبارت = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = عبارت_const();
    اگر (tok != TOK_EOF)
        tcc_error("...");
    pp_عبارت = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    بازگشت c != 0;
}

ST_FUNC تهی pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_عبارت, 0));
    macro_ptr = macro_پشته->str;
    وقتی (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC تهی parse_define(تهی)
{
    Sym *s, *first, **ps;
    صحیح v, t, varg, is_vaargs, t0;
    صحیح saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    اگر (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = پوچ;
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
    اگر (tok == '(') {
        صحیح dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        اگر (tok != ')') برای (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            اگر (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } وگرنه اگر (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            اگر (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_پشته, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            اگر (tok == ')')
                بشکن;
            اگر (tok != ',' || is_vaargs)
                برو bad_list;
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
    وقتی (tok != TOK_LINEFEED && tok != TOK_EOF) {
        اگر (is_space(tok)) {
            str.need_spc |= 1;
        } وگرنه {
            اگر (TOK_TWOSHARPS == tok) {
                اگر (0 == t0)
                    برو bad_twosharp;
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
    اگر (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_افزودن(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ایستا CachedInclude *جستجو_cached_include(TCCState *s1, ثابت نویسه *filename, صحیح add)
{
    ثابت نویسه *s, *basename;
    unsigned صحیح h;
    CachedInclude *e;
    صحیح c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    وقتی ((c = (unsigned نویسه)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#وگرنه
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    برای(;;) {
        اگر (i == 0)
            بشکن;
        e = s1->cached_includes[i - 1];
        اگر (0 == PATHCMP(filename, e->filename))
            بازگشت e;
        اگر (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            بازگشت e;
        i = e->hash_next;
    }
    اگر (!add)
        بازگشت پوچ;

    e = tcc_malloc(اندازه(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    بازگشت e;
}

ایستا صحیح pragma_parse(TCCState *s1)
{
    next_nomacro();
    اگر (tok == TOK_افزودن_macro || tok == TOK_برداشت_macro) {
        صحیح t = tok, v;
        Sym *s;

        اگر (next(), tok != '(')
            برو pragma_err;
        اگر (next(), tok != TOK_STR)
            برو pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        اگر (next(), tok != ')')
            برو pragma_err;
        اگر (t == TOK_افزودن_macro) {
            وقتی (پوچ == (s = define_find(v)))
                define_افزودن(v, 0, پوچ, پوچ);
            s->type.ref = s; /* set push boundary */
        } وگرنه {
            برای (s = define_پشته; s; s = s->prev)
                اگر (s->v == v && s->type.ref == s) {
                    s->type.ref = پوچ;
                    بشکن;
                }
        }
        اگر (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : پوچ;
        وگرنه
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } وگرنه اگر (tok == TOK_once) {
        جستجو_cached_include(s1, file->true_filename, 1)->once = 1;

    } وگرنه اگر (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        بازگشت 1;

    } وگرنه اگر (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        اگر (tok == TOK_ASM_برداشت) {
            next();
            اگر (s1->pack_پشته_ptr <= s1->pack_پشته) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_پشته_ptr--;
        } وگرنه {
            صحیح val = 0;
            اگر (tok != ')') {
                اگر (tok == TOK_ASM_افزودن) {
                    next();
                    اگر (s1->pack_پشته_ptr >= s1->pack_پشته + PACK_پشته_SIZE - 1)
                        برو stk_error;
                    val = *s1->pack_پشته_ptr++;
                    اگر (tok != ',')
                        برو pack_set;
                    next();
                }
                اگر (tok != TOK_CINT)
                    برو pragma_err;
                val = tokc.i;
                اگر (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    برو pragma_err;
                next();
            }
        pack_set:
            *s1->pack_پشته_ptr = val;
        }
        اگر (tok != ')')
            برو pragma_err;

    } وگرنه اگر (tok == TOK_comment) {
        نویسه *p; صحیح t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        اگر (tok != TOK_STR)
            برو pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        اگر (tok != ')')
            برو pragma_err;
        اگر (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } وگرنه {
            اگر (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } وگرنه {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        بازگشت 0;
    }
    next();
    بازگشت 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC تهی tccpp_putfile(ثابت نویسه *filename)
{
    نویسه buf[1024];
    buf[0] = 0;
    اگر (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, اندازه buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, اندازه buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    اگر (0 == strcmp(file->filename, buf))
        بازگشت;
    //printf("new file '%s'\n", buf);
    اگر (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, اندازه file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC تهی preprocess(صحیح is_bof)
{
    TCCState *s1 = tcc_state;
    صحیح c, n, saved_parse_flags;
    نویسه buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_رقم
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    انتخاب(tok) {
    حالت TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        بشکن;
    حالت TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        اگر (s)
            define_undef(s);
        next_nomacro();
        بشکن;
    حالت TOK_INCLUDE:
    حالت TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        برو the_end;
    حالت TOK_IFNDEF:
        c = 1;
        برو do_ifdef;
    حالت TOK_IF:
        c = عبارت_preprocess(s1);
        برو do_if;
    حالت TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        اگر (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        اگر (is_bof) {
            اگر (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, پوچ));
#endif
                file->ifndef_macro = tok;
            }
        }
        اگر (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        اگر (s1->ifdef_پشته_ptr >= s1->ifdef_پشته + IFDEF_پشته_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_پشته_ptr++ = c;
        برو test_skip;
    حالت TOK_ELSE:
        next_nomacro();
        اگر (s1->ifdef_پشته_ptr == s1->ifdef_پشته)
            tcc_error("#else without matching #if");
        اگر (s1->ifdef_پشته_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_پشته_ptr[-1] ^= 3);
        برو test_else;
    حالت TOK_ELIF:
        اگر (s1->ifdef_پشته_ptr == s1->ifdef_پشته)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_پشته_ptr[-1];
        اگر (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        اگر (c == 1) {
            skip_to_eol(0);
            c = 0;
        } وگرنه {
            c = عبارت_preprocess(s1);
            s1->ifdef_پشته_ptr[-1] = c;
        }
    test_else:
        اگر (s1->ifdef_پشته_ptr == file->ifdef_پشته_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        اگر (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            برو redo;
        }
        بشکن;
    حالت TOK_ENDIF:
        next_nomacro();
        اگر (s1->ifdef_پشته_ptr <= file->ifdef_پشته_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_پشته_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        اگر (file->ifndef_macro &&
            s1->ifdef_پشته_ptr == file->ifdef_پشته_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        بشکن;

    حالت TOK_سطر:
        parse_flags &= ~PARSE_FLAG_TOK_رقم;
        next();
        اگر (tok != TOK_PPNUM) {
    سطر_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        برو سطر_رقم_2;
    حالت TOK_PPNUM:
        اگر (parse_flags & PARSE_FLAG_ASM_FILE)
            برو ignore;
        c = 0; /* no error with extra tokens */
    سطر_رقم_2:
        برای (n = 0, q = tokc.str.data; *q; ++q) {
            اگر (!isnum(*q))
                برو سطر_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        اگر (tok != TOK_LINEFEED) {
            اگر (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                برو سطر_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        اگر (file->fd > 0)
            total_سطرها += file->سطر_رقم - n;
        file->سطر_رقم = n;
        بشکن;

    حالت TOK_ERROR:
    حالت TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        وقتی (c != '\n' && c != CH_EOF) {
            اگر ((q - buf) < اندازه(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        اگر (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        وگرنه
            tcc_warning("#warning %s", buf);
        next_nomacro();
        بشکن;
    }
    حالت TOK_PRAGMA:
        اگر (!pragma_parse(s1))
            برو ignore;
        بشکن;
    حالت TOK_LINEFEED:
        برو the_end;
    پیشفرض:
        /* ignore gas line comment in an 'S' file. */
        اگر (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            برو ignore;
        اگر (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            برو ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        برو the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ایستا تهی parse_escape_string(CString *outstr, ثابت uint8_t *buf, صحیح is_long)
{
    صحیح c, n, i;
    ثابت uint8_t *p;

    p = buf;
    برای(;;) {
        c = *p;
        اگر (c == '\0')
            بشکن;
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
                برو add_char_nonext;
            حالت 'x': i = 0; برو parse_hex_or_ucn;
            حالت 'u': i = 4; برو parse_hex_or_ucn;
            حالت 'U': i = 8; برو parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                انجامبده {
                    c = *p;
                    اگر (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    وگرنه اگر (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    وگرنه اگر (isnum(c))
                        c = c - '0';
                    وگرنه اگر (i >= 0)
                        expect("more hex digits in universal-character-name");
                    وگرنه
                        برو add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } وقتی (--i);
		اگر (is_long) {
    add_hex_or_ucn:
                    c = n;
		    برو add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ادامه;
            حالت 'a':
                c = '\a';
                بشکن;
            حالت 'b':
                c = '\b';
                بشکن;
            حالت 'f':
                c = '\f';
                بشکن;
            حالت 'n':
                c = '\n';
                بشکن;
            حالت 'r':
                c = '\r';
                بشکن;
            حالت 't':
                c = '\t';
                بشکن;
            حالت 'v':
                c = '\v';
                بشکن;
            حالت 'e':
                اگر (!gnu_ext)
                    برو invalid_escape;
                c = 27;
                بشکن;
            حالت '\'':
            حالت '\"':
            حالت '\\': 
            حالت '?':
                بشکن;
            پیشفرض:
            invalid_escape:
                اگر (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                وگرنه
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                بشکن;
            }
        } وگرنه اگر (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            صحیح cont; /* count of continuation bytes */
            صحیح skip; /* how many bytes should skip when error occurred */
            صحیح i;

            /* decode leading byte */
            اگر (c < 0xC2) {
	            skip = 1; برو invalid_utf8_sequence;
            } وگرنه اگر (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } وگرنه اگر (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } وگرنه اگر (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } وگرنه {
	            skip = 1; برو invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            برای (i = 1; i <= cont; i++) {
                صحیح l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                اگر (i == 1) {
                    انتخاب (c) {
                    حالت 0xE0: l = 0xA0; بشکن;
                    حالت 0xED: h = 0x9F; بشکن;
                    حالت 0xF0: l = 0x90; بشکن;
                    حالت 0xF4: h = 0x8F; بشکن;
                    }
                }

                اگر (p[i] < l || p[i] > h) {
                    skip = i; برو invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            برو add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            برو add_char_nonext;

        }
        p++;
    add_char_nonext:
        اگر (!is_long)
            cstr_ccat(outstr, c);
        وگرنه {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            اگر (c < 0x10000) {
                cstr_wccat(outstr, c);
            } وگرنه {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#وگرنه
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    اگر (!is_long)
        cstr_ccat(outstr, '\0');
    وگرنه
        cstr_wccat(outstr, '\0');
}

ایستا تهی parse_string(ثابت نویسه *s, صحیح len)
{
    uint8_t buf[1000], *p = buf;
    صحیح is_long, sep;

    اگر ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    اگر (len >= اندازه buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    اگر (p != buf)
        tcc_free(p);

    اگر (sep == '\'') {
        صحیح char_size, i, n, c;
        /* XXX: make it portable */
        اگر (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        وگرنه
            tok = TOK_LCHAR, char_size = اندازه(nwchar_t);
        n = tokcstr.size / char_size - 1;
        اگر (n < 1)
            tcc_error("empty character constant");
        اگر (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        برای (c = i = 0; i < n; ++i) {
            اگر (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            وگرنه
                c = (c << 8) | ((نویسه *)tokcstr.data)[i];
        }
        tokc.i = c;
    } وگرنه {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        اگر (!is_long)
            tok = TOK_STR;
        وگرنه
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
ایستا صحیح bn_lshift(unsigned صحیح *bn, صحیح shift, صحیح or_val)
{
    صحیح i;
    unsigned صحیح v;
    اگر (bn[BN_SIZE - 1] >> (32 - shift))
	بازگشت shift;
    برای(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    بازگشت 0;
}

ایستا تهی bn_zero(unsigned صحیح *bn)
{
    صحیح i;
    برای(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ایستا تهی parse_عدد(ثابت نویسه *p)
{
    صحیح b, t, shift, frac_bits, s, exp_val, ch;
    نویسه *q;
    unsigned صحیح bn[BN_SIZE];
    long دوگانه d;

    /*عدد*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    اگر (t == '.') {
        برو float_frac_parse;
    } وگرنه اگر (t == '0') {
        اگر (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } وگرنه اگر (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    وقتی (1) {
        اگر (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        وگرنه اگر (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        وگرنه اگر (isnum(ch))
            t = ch - '0';
        وگرنه
            بشکن;
        اگر (t >= b)
            بشکن;
        اگر (q >= token_buf + STRING_MAX_SIZE) {
        رقم_too_long:
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
            frac_bits = 0;
            *q = '\0';
            اگر (b == 16)
                shift = 4;
            وگرنه 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            وقتی (1) {
                t = *q++;
                اگر (t == '\0') {
                    بشکن;
                } وگرنه اگر (t >= 'a') {
                    t = t - 'a' + 10;
                } وگرنه اگر (t >= 'A') {
                    t = t - 'A' + 10;
                } وگرنه {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            اگر (ch == '.') {
                ch = *p++;
                وقتی (1) {
                    t = ch;
                    اگر (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } وگرنه اگر (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } وگرنه اگر (t >= '0' && t <= '9') {
                        t = t - '0';
                    } وگرنه {
                        بشکن;
                    }
                    اگر (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
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
            } وگرنه اگر (ch == '-') {
                s = -1;
                ch = *p++;
            }
            اگر (ch < '0' || ch > '9')
                expect("exponent digits");
            وقتی (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		اگر (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long دوگانه)bn[3] * 79228162514264337593543950336.0L +
	        (long دوگانه)bn[2] * 18446744073709551616.0L +
	        (long دوگانه)bn[1] * 4294967296.0L +
	        (long دوگانه)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            اگر (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (اعشاری)d;
            } وگرنه اگر (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } وگرنه {
                tok = TOK_CDOUBLE;
                tokc.d = (دوگانه)d;
            }
        } وگرنه {
            /* decimal floats */
            اگر (ch == '.') {
                اگر (q >= token_buf + STRING_MAX_SIZE)
                    برو رقم_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                وقتی (ch >= '0' && ch <= '9') {
                    اگر (q >= token_buf + STRING_MAX_SIZE)
                        برو رقم_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            اگر (ch == 'e' || ch == 'E') {
                اگر (q >= token_buf + STRING_MAX_SIZE)
                    برو رقم_too_long;
                *q++ = ch;
                ch = *p++;
                اگر (ch == '-' || ch == '+') {
                    اگر (q >= token_buf + STRING_MAX_SIZE)
                        برو رقم_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                اگر (ch < '0' || ch > '9')
                    expect("exponent digits");
                وقتی (ch >= '0' && ch <= '9') {
                    اگر (q >= token_buf + STRING_MAX_SIZE)
                        برو رقم_too_long;
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
                tokc.f = strtof(token_buf, پوچ);
            } وگرنه اگر (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, پوچ);
            } وگرنه {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, پوچ);
            }
        }
    } وگرنه {
        unsigned long long n, n1;
        صحیح lcount, ucount, ov = 0;
        ثابت نویسه *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        اگر (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        وقتی(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            اگر (t == '\0')
                بشکن;
            وگرنه اگر (t >= 'a')
                t = t - 'a' + 10;
            وگرنه اگر (t >= 'A')
                t = t - 'A' + 10;
            وگرنه
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
        برای(;;) {
            t = toup(ch);
            اگر (t == 'L') {
                اگر (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                اگر (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } وگرنه اگر (t == 'U') {
                اگر (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } وگرنه {
                بشکن;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        اگر (pp_عبارت)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        اگر (ucount == 0 && b == 10) {
            اگر (lcount <= (LONG_SIZE == 4)) {
                اگر (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            اگر (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } وگرنه {
            اگر (lcount <= (LONG_SIZE == 4)) {
                اگر (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                وگرنه اگر (n >= 0x80000000U)
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


#define PARSE2(c1, tok1, c2, tok2)              \
    حالت c1:                                    \
        PEEKC(c, p);                            \
        اگر (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } وگرنه {                                \
            tok = tok1;                         \
        }                                       \
        بشکن;

/* return next token without macro substitution */
ایستا تهی next_nomacro(تهی)
{
    صحیح t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned صحیح h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    انتخاب(c) {
    حالت ' ':
    حالت '\t':
        tok = c;
        p++;
 maybe_space:
        اگر (parse_flags & PARSE_FLAG_SPACES)
            برو keep_tok_flags;
        وقتی (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        برو redo_no_start;
    حالت '\f':
    حالت '\v':
    حالت '\r':
        p++;
        برو redo_no_start;
    حالت '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        اگر (c == '\\')
            برو parse_simple;
        اگر (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            اگر (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                برو maybe_newline;
            } وگرنه اگر (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } وگرنه اگر (s1->ifdef_پشته_ptr != file->ifdef_پشته_ptr) {
                tcc_error("missing #endif");
            } وگرنه اگر (s1->include_پشته_ptr == s1->include_پشته) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } وگرنه {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                اگر (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, پوچ));
#endif
                    جستجو_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_پشته_ptr--;
                p = file->buf_ptr;
                برو maybe_newline;
            }
        } وگرنه {
            برو redo_no_start;
        }
        بشکن;

    حالت '\n':
        file->سطر_رقم++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        اگر (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            برو redo_no_start;
        tok = TOK_LINEFEED;
        برو keep_tok_flags;

    حالت '#':
        /* XXX: simplify */
        PEEKC(c, p);
        اگر ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            برو maybe_newline;
        } وگرنه {
            اگر (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } وگرنه {
#اگر !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                اگر (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_سطر_comment(p - 1);
                    برو redo_no_start;
                } وگرنه
#endif
                {
                    tok = '#';
                }
            }
        }
        بشکن;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    حالت '$':
        اگر (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            برو parse_simple;

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
        وقتی (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_رقم))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        اگر (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            برای(;;) {
                ts = *pts;
                اگر (!ts)
                    بشکن;
                اگر (ts->len == len && !memcmp(ts->str, p1, len))
                    برو token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (نویسه *) p1, len);
        token_found: ;
        } وگرنه {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (نویسه *) p1, len);
            p--;
            PEEKC(c, p);
            وقتی (isidnum_table[c - CH_EOF] & (IS_ID|IS_رقم))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        بشکن;
    حالت 'L':
        t = p[1];
        اگر (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            اگر (c == '\'' || c == '\"') {
                is_long = 1;
                برو str_const;
            }
            *--p = c = 'L';
        }
        برو parse_ident_fast;

    حالت '0': حالت '1': حالت '2': حالت '3':
    حالت '4': حالت '5': حالت '6': حالت '7':
    حالت '8': حالت '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_رقم:
        cstr_reset(&tokcstr);
        برای(;;) {
            cstr_ccat(&tokcstr, t);
            اگر (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_رقم))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((نویسه*)tokcstr.data)[0] == '0'
                                && toup(((نویسه*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                بشکن;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        بشکن;

    حالت '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        اگر (isnum(c)) {
            t = '.';
            برو parse_رقم;
        } وگرنه اگر ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_رقم))) {
            *--p = c = '.';
            برو parse_ident_fast;
        } وگرنه اگر (c == '.') {
            PEEKC(c, p);
            اگر (c == '.') {
                p++;
                tok = TOK_DOTS;
            } وگرنه {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } وگرنه {
            tok = '.';
        }
        بشکن;
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
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        بشکن;

    حالت '<':
        PEEKC(c, p);
        اگر (c == '=') {
            p++;
            tok = TOK_LE;
        } وگرنه اگر (c == '<') {
            PEEKC(c, p);
            اگر (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } وگرنه {
                tok = TOK_SHL;
            }
        } وگرنه {
            tok = TOK_LT;
        }
        بشکن;
    حالت '>':
        PEEKC(c, p);
        اگر (c == '=') {
            p++;
            tok = TOK_GE;
        } وگرنه اگر (c == '>') {
            PEEKC(c, p);
            اگر (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } وگرنه {
                tok = TOK_SAR;
            }
        } وگرنه {
            tok = TOK_GT;
        }
        بشکن;
        
    حالت '&':
        PEEKC(c, p);
        اگر (c == '&') {
            p++;
            tok = TOK_LAND;
        } وگرنه اگر (c == '=') {
            p++;
            tok = TOK_A_AND;
        } وگرنه {
            tok = '&';
        }
        بشکن;
        
    حالت '|':
        PEEKC(c, p);
        اگر (c == '|') {
            p++;
            tok = TOK_LOR;
        } وگرنه اگر (c == '=') {
            p++;
            tok = TOK_A_OR;
        } وگرنه {
            tok = '|';
        }
        بشکن;

    حالت '+':
        PEEKC(c, p);
        اگر (c == '+') {
            p++;
            tok = TOK_INC;
        } وگرنه اگر (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } وگرنه {
            tok = '+';
        }
        بشکن;
        
    حالت '-':
        PEEKC(c, p);
        اگر (c == '-') {
            p++;
            tok = TOK_DEC;
        } وگرنه اگر (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } وگرنه اگر (c == '>') {
            p++;
            tok = TOK_ARROW;
        } وگرنه {
            tok = '-';
        }
        بشکن;

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
            برو maybe_space;
        } وگرنه اگر (c == '/') {
            p = parse_سطر_comment(p);
            tok = ' ';
            برو maybe_space;
        } وگرنه اگر (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } وگرنه {
            tok = '/';
        }
        بشکن;
        
        /* simple tokens */
    حالت '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        اگر (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_سطر_comment(p);
            برو redo_no_start;
        }
#endif
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
        بشکن;
    حالت 0xEF: /* UTF8 BOM ? */
        اگر (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            برو redo_no_start;
        }
    پیشفرض:
        اگر (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    برو parse_ident_fast;
        اگر (parse_flags & PARSE_FLAG_ASM_FILE)
            برو parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        بشکن;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#اگر defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
ایستا صحیح indent;
ایستا تهی define_print(TCCState *s1, صحیح v);
ایستا تهی pp_print(ثابت نویسه *پیام, صحیح v, ثابت صحیح *str)
{
    FILE *fp = tcc_state->ppfp;

    اگر (پیام[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    وگرنه اگر (پیام[0] == '+')
         ++indent, ++پیام;
    وگرنه اگر (پیام[0] == '-')
        --indent, ++پیام;

    fprintf(fp, "%*s", indent, "");
    اگر (پیام[0] == '#') {
        define_print(tcc_state, v);
    } وگرنه {
        tok_print(str, v ? "%s %s" : "%s", پیام, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#وگرنه
#define PP_PRINT(x)
#endif

ایستا صحیح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحیح *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ایستا صحیح *macro_arg_subst(Sym **nested_list, ثابت صحیح *macro_str, Sym *args)
{
    صحیح t, t0, t1, t2, n;
    ثابت صحیح *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    برای (s = args, n = 0; s; s = s->prev, ++n);
    وقتی (n--) {
        برای (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    وقتی(1) {
        TOK_GET(&t, &macro_str, &cval);
        اگر (!t)
            بشکن;
        اگر (t == '#') {
            /* stringize */
            انجامبده t = *macro_str++; وقتی (t == ' ');
            s = sym_find2(args, t);
            اگر (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                وقتی (*st != TOK_EOF) {
                    ثابت نویسه *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    وقتی (*s) {
                        اگر (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        وگرنه
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
            } وگرنه اگر ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } وگرنه {
                expect("macro parameter after '#'");
            }
        } وگرنه اگر (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            اگر (s) {
                st = s->d;
                n = 0;
                وقتی ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                اگر (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    اگر (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        صحیح c = str.str[str.len - 1];
                        وقتی (str.str[--str.len] != ',')
                            ;
                        اگر (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } وگرنه {
                            /* suppress '##' and add variable */
                            str.len++;
                            اگر (c == ' ')
                                str.str[str.len++] = c;
                            برو add_var;
                        }
                    } وگرنه {
                        اگر (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } وگرنه {
            add_var:
		    اگر (!s->e) {
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
                وقتی (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } وگرنه {
                tok_str_add(&str, t);
            }
        } وگرنه {
            tok_str_add2(&str, t, &cval);
        }
        اگر (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    بازگشت str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ایستا درونخطی صحیح *macro_twosharps(ثابت صحیح *ptr0)
{
    صحیح t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ثابت صحیح *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    برای (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        اگر (t1 == 0)
            بشکن;
        برای (;;) {
            n = 0;
            وقتی ((t2 = ptr[n]) == ' ')
                ++n;
            اگر (t2 != TOK_PPJOIN)
                بشکن;
            ptr += n;
            وقتی ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            اگر (t2 == TOK_PLCHLDR)
                ادامه;
            اگر (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        اگر (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            برای (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                اگر (*file->buf_ptr == 0)
                    بشکن;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        اگر (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    بازگشت macro_str1.str;
}

ایستا صحیح peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    صحیح c;
    برای (;;) {
        PEEKC(c, p);
        انتخاب (c) {
        حالت '/':
            PEEKC(c, p);
            اگر (c == '*')
                p = parse_comment(p);
            وگرنه اگر (c == '/')
                p = parse_سطر_comment(p);
            وگرنه {
                c = *--p = '/';
                برو leave;
            }
            --p, c = ' ';
            بشکن;
        حالت ' ': حالت '\t':
            بشکن;
        حالت '\f': حالت '\v': حالت '\r':
            ادامه;
        حالت '\n':
            file->سطر_رقم++, tok_flags |= TOK_FLAG_BOL;
            بشکن;
        پیشفرض: leave:
            file->buf_ptr = p;
            بازگشت c;
        }
        اگر (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ایستا صحیح next_argstream(Sym **nested_list, TokenString *ws_str)
{
    صحیح t;
    Sym *sa;

    وقتی (macro_ptr) {
        ثابت صحیح *m = macro_ptr;
        وقتی ((t = *m) != 0) {
            اگر (ws_str) {
                اگر (t != ' ')
                    بازگشت t;
                ++m;
            } وگرنه {
                TOK_GET(&tok, &macro_ptr, &tokc);
                بازگشت tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        اگر (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    اگر (ws_str) {
        بازگشت peek_file(ws_str);
    } وگرنه {
        next_nomacro();
        اگر (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        بازگشت tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ایستا صحیح macro_subst_tok(
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
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            اگر (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                اگر (parse_flags & PARSE_FLAG_SPACES)
                    برای (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                بازگشت 0;
            } وگرنه {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = پوچ;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            برای(;;) {
                انجامبده {
                    t = next_argstream(nested_list, پوچ);
                } وقتی (t == ' ' || --i);

                اگر (!sa) {
                    اگر (t == ')') /* handle '()' case */
                        بشکن;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                وقتی (parlevel > 0
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
                    وگرنه
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, پوچ);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                اگر (t == ')') {
                    اگر (!sa)
                        بشکن;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    اگر (sa->type.t && gnu_ext)
                        برو empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            وقتی (sa) {
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
        اگر (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        اگر (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        اگر (jstr != mstr)
            tok_str_free_str(jstr);
        اگر (mstr != s->d)
            tok_str_free_str(mstr);
        بازگشت ret;

    } وگرنه {
        CValue cval;
        نویسه buf[32], *cstrval = buf;

        /* special macros */
        اگر (v == TOK_سطر_2 || v == TOK___COUNTER__) {
            t = v == TOK_سطر_2 ? file->سطر_رقم : pp_counter++;
            snprintf(buf, اندازه(buf), "%d", t);
            t = TOK_PPNUM;
            برو add_cstr1;

        } وگرنه اگر (v == TOK___FILE__) {
            cstrval = file->filename;
            برو add_cstr;

        } وگرنه اگر (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            ساختار tm *tm;
            time(&ti);
            tm = localtime(&ti);
            اگر (v == TOK___DATE__) {
                ایستا نویسه ثابت ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, اندازه(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } وگرنه {
                snprintf(buf, اندازه(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        بازگشت 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ایستا صحیح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحیح *macro_str
    )
{
    Sym *s;
    صحیح t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    صحیح tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    وقتی (1) {
        TOK_GET(&t, &macro_str, &cval);
        اگر (t == 0 || t == TOK_EOF)
            بشکن;
        اگر (t >= TOK_IDENT) {
            s = define_find(t);
            اگر (s == پوچ || nosubst)
                برو no_subst;
            /* if nested substitution, do nothing */
            اگر (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                برو no_subst;
            }
            str = tok_str_alloc();
            str->str = (صحیح*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            اگر (macro_پشته != str) {
                /* already finished by reading function macro arguments */
                بشکن;
            }
            macro_str = macro_ptr;
            end_macro ();
        } وگرنه اگر (t == ' ') {
            اگر (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } وگرنه {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            اگر (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            اگر (t == TOK_DEFINED && pp_عبارت)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    بازگشت nosubst;
}

/* return next token with macro substitution */
ST_FUNC تهی next(تهی)
{
    صحیح t;
    وقتی (macro_ptr) {
redo:
        t = *macro_ptr;
        اگر (TOK_HAS_مقدار(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            اگر (t == TOK_LINENUM) {
                file->سطر_رقم = tokc.i;
                برو redo;
            }
            برو convert;
        } وگرنه اگر (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            ادامه;
        } وگرنه اگر (t == TOK_EOF) {
            /* do nothing */
        } وگرنه {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            اگر (t == '\\') {
                اگر (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        بازگشت;
    }

    next_nomacro();
    t = tok;
    اگر (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        اگر (s) {
            Sym *nested_list = پوچ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            برو redo;
        }
        بازگشت;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    اگر (t == TOK_PPNUM) {
        اگر  (parse_flags & PARSE_FLAG_TOK_رقم)
            parse_عدد(tokc.str.data);
    } وگرنه اگر (t == TOK_PPSTR) {
        اگر (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN تهی unget_tok(صحیح last_tok)
{
    TokenString *str = &unget_buf;
    صحیح alloc = 0;
    اگر (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    اگر (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ایستا ثابت نویسه * ثابت target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# اگر PTR_SIZE == 8
    "_WIN64\0"
# endif
#وگرنه
# اگر defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# وگرنه
    "__linux__\0"
    "__linux\0"
#  اگر TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

ایستا تهی putdef(CString *cs, ثابت نویسه *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ایستا تهی putdefs(CString *cs, ثابت نویسه *p)
{
    وقتی (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ایستا تهی tcc_predefs(TCCState *s1, CString *cs, صحیح is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    اگر (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    اگر (is_asm)
      putdef(cs, "__ASSEMBLER__");
    اگر (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    اگر (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    اگر (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    اگر (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    اگر (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    اگر (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    اگر (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    اگر (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#اگر CONFIG_TCC_PREDEFS
        #شامل "tccdefs_.h" /* include as strings */
#وگرنه
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC تهی preprocess_start(TCCState *s1, صحیح filetype)
{
    صحیح is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_پشته_ptr = s1->include_پشته;
    s1->ifdef_پشته_ptr = s1->ifdef_پشته;
    file->ifdef_پشته_ptr = s1->ifdef_پشته_ptr;
    pp_عبارت = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_پشته[0] = 0;
    s1->pack_پشته_ptr = s1->pack_پشته;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    اگر (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        اگر (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        اگر (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_پشته_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC تهی preprocess_end(TCCState *s1)
{
    وقتی (macro_پشته)
        end_macro();
    macro_ptr = پوچ;
    وقتی (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC صحیح set_idnum(صحیح c, صحیح val)
{
    صحیح prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    بازگشت prev;
}

ST_FUNC تهی tccpp_new(TCCState *s)
{
    صحیح i, c;
    ثابت نویسه *p, *r;

    /* init isid table */
    برای(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_رقم
            : 0);

    برای(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * اندازه(TokenSym *));
    memset(s->cached_includes_hash, 0, اندازه s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    وقتی (*p) {
        r = p;
        برای(;;) {
            c = *r++;
            اگر (c == '\0')
                بشکن;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_افزودن(TOK_سطر_2, MACRO_OBJ, پوچ, پوچ);
    define_افزودن(TOK___FILE__, MACRO_OBJ, پوچ, پوچ);
    define_افزودن(TOK___DATE__, MACRO_OBJ, پوچ, پوچ);
    define_افزودن(TOK___TIME__, MACRO_OBJ, پوچ, پوچ);
    define_افزودن(TOK___COUNTER__, MACRO_OBJ, پوچ, پوچ);
}

ST_FUNC تهی tccpp_delete(TCCState *s)
{
    صحیح i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    اگر (n > total_idents)
        total_idents = n;
    برای (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = پوچ;

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

ایستا صحیح pp_need_space(صحیح a, صحیح b);

ایستا تهی tok_print(ثابت صحیح *str, ثابت نویسه *پیام, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    صحیح t, t0, s;
    CValue cval;

    va_start(ap, پیام);
    vfprintf(fp, پیام, ap);
    va_end(ap);

    s = t0 = 0;
    وقتی (str) {
	TOK_GET(&t, &str, &cval);
	اگر (t == 0 || t == TOK_EOF)
	    بشکن;
        اگر (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ایستا تهی pp_سطر(TCCState *s1, BufferedFile *f, صحیح level)
{
    صحیح d = f->سطر_رقم - f->سطر_ref;

    اگر (s1->dflag & 4)
	بازگشت;

    اگر (s1->Pflag == سطر_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } وگرنه اگر (level == 0 && f->سطر_ref && d < 8) {
	وقتی (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } وگرنه اگر (s1->Pflag == سطر_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->سطر_رقم, f->filename);
    } وگرنه {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->سطر_رقم, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->سطر_ref = f->سطر_رقم;
}

ایستا تهی define_print(TCCState *s1, صحیح v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    اگر (پوچ == s || پوچ == s->d)
        بازگشت;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, پوچ));
    اگر (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        اگر (a)
            برای (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, پوچ));
                اگر (!(a = a->next))
                    بشکن;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ایستا تهی pp_debug_defines(TCCState *s1)
{
    صحیح v, t;
    ثابت نویسه *vs;
    FILE *fp;

    t = pp_debug_tok;
    اگر (t == 0)
        بازگشت;

    file->سطر_رقم--;
    pp_سطر(s1, file, 0);
    file->سطر_ref = ++file->سطر_رقم;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, پوچ);
    اگر (t == TOK_DEFINE) {
        define_print(s1, v);
    } وگرنه اگر (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } وگرنه اگر (t == TOK_افزودن_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } وگرنه اگر (t == TOK_برداشت_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ایستا صحیح pp_need_space(صحیح a, صحیح b)
{
    بازگشت 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ایستا صحیح pp_check_he0xE(صحیح t, ثابت نویسه *p)
{
    اگر (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        بازگشت 'E';
    بازگشت t;
}

/* Preprocess the current file */
ST_FUNC صحیح tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    صحیح token_seen, spcs, level;
    ثابت نویسه *p;
    نویسه white[400];

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
        parse_flags |= PARSE_FLAG_TOK_رقم, s1->Pflag = 1;

    اگر (s1->do_bench) {
	/* for PP benchmarks */
	انجامبده next(); وقتی (tok != TOK_EOF);
	بازگشت 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    اگر (file->prev)
        pp_سطر(s1, file->prev, level++);
    pp_سطر(s1, file, level);

    برای (;;) {
        iptr = s1->include_پشته_ptr;
        next();
        اگر (tok == TOK_EOF)
            بشکن;

        level = s1->include_پشته_ptr - iptr;
        اگر (level) {
            اگر (level > 0)
                pp_سطر(s1, *iptr, 0);
            pp_سطر(s1, file, level);
        }
        اگر (s1->dflag & 7) {
            pp_debug_defines(s1);
            اگر (s1->dflag & 4)
                ادامه;
        }

        اگر (is_space(tok)) {
            اگر (spcs < اندازه white - 1)
                white[spcs++] = tok;
            ادامه;
        } وگرنه اگر (tok == TOK_LINEFEED) {
            spcs = 0;
            اگر (token_seen == TOK_LINEFEED)
                ادامه;
            ++file->سطر_ref;
        } وگرنه اگر (token_seen == TOK_LINEFEED) {
            pp_سطر(s1, file, 0);
        } وگرنه اگر (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    بازگشت 0;
}

/* ------------------------------------------------------------------------- */
