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
#ضمن "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA صحيح tok_flags;
ST_DATA صحيح parse_flags;

ST_DATA بنية BufferedFile *file;
ST_DATA صحيح tok;
ST_DATA CValue tokc;
ST_DATA ثابت صحيح *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA صحيح tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA صحيح pp_expr;

/* ------------------------------------------------------------------------- */

ساكن TokenSym *hash_ident[TOK_HASH_SIZE];
ساكن حرف token_buf[STRING_MAX_SIZE + 1];
ساكن CString cstr_buf;
ساكن TokenString tokstr_buf;
ساكن TokenString unget_buf;
ساكن unsigned حرف isidnum_table[256 - CH_EOF];
ساكن صحيح pp_debug_tok, pp_debug_symv;
ساكن صحيح pp_counter;
ساكن فراغ tok_print(ثابت صحيح *str, ثابت حرف *msg, ...);
ساكن فراغ next_nomacro(فراغ);
ساكن فراغ parse_number(ثابت حرف *p);
ساكن فراغ parse_string(ثابت حرف *p, صحيح len);

ساكن بنية TinyAlloc *toksym_alloc;
ساكن بنية TinyAlloc *tokstr_alloc;

ساكن TokenString *macro_stack;

ساكن ثابت حرف tcc_keywords[] = 
#define DEF(id, str) str "\0"
#ضمن "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
ساكن ثابت unsigned حرف tok_two_chars[] =
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

ST_FUNC فراغ skip(صحيح c)
{
    אם (tok != c) {
        حرف tmp[40];
        pstrcpy(tmp, حجم tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC فراغ expect(ثابت حرف *msg)
{
    tcc_error("%s expected", msg);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#אחרת
#אם !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#אחרת
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ثابت حرف *sfile, صحيح sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

تعريفنوع بنية TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    بنية TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#אם TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    اتحاد {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

تعريفنوع بنية tal_header_t {
    size_t  size; /* word align */
#אם TAL_DEBUG
    صحيح     line_num; /* negative line_num used for double free check */
    حرف    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (حجم (size_t) - 1)) & ~(حجم (size_t) - 1))

/* ------------------------------------------------------------------------- */

ساكن TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(حجم(TinyAlloc) - حجم (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#אם TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    החזר al;
}

ساكن فراغ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#אם TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#אם TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#אם TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    אם (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        כלעוד (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            אם (header->line_num > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->line_num, (صحيح)header->size);
            }
            p += header->size + حجم(tal_header_t);
        }
#אם TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    אם (al)
        اذهب tail_call;
    *pal = al;
}

ساكن فراغ tal_free_impl(TinyAlloc **pal, فراغ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **top = pal;
    tal_header_t *header;

    אם (!p)
        החזר;
    header = (tal_header_t *)p - 1;
#אם TAL_DEBUG
    אם (header->line_num < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (صحيح)-header->line_num, (صحيح)header->size);
    } אחרת
        header->line_num = -header->line_num;
#endif
    al = *pal;
    כלעוד ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    אם (0 == --al->nb_allocs) {
        *pal = al->next;
        אם ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } אחרת {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *top, *top = al;
        }
    } אחרת אם ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

ساكن فراغ *tal_realloc_impl(TinyAlloc **pal, فراغ *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    فراغ *ret;
    unsigned adj_size = TAL_ALIGN(size) + حجم(tal_header_t);
    TinyAlloc *al = *pal;

    אם (p) {
        /* reallpc case */
        כלעוד ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        אם ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        אם (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            החזר ret;
        } אחרת אם (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#אם TAL_DEBUG
            header->line_num = -header->line_num;
#endif
        }
    } אחרת {
        /* new alloc case */
        כלעוד (al->p + adj_size > al->bufend) {
            al = al->next;
            אם (!al) {
                unsigned new_size = (*pal)->size;
                אם (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                اكسر;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - حجم(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#אם  TAL_DEBUG
    {
        صحيح ofs = strlen(sfile) + 1 - حجم header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->line_num = sline;
#אם TAL_INFO
        אם (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        אם (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    החזר ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ساكن فراغ cstr_realloc(CString *cstr, صحيح new_size)
{
    صحيح size;

    size = cstr->size_allocated;
    אם (size < 8)
        size = 8; /* no need to allocate a too small first string */
    כלעוד (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN فراغ cstr_ccat(CString *cstr, صحيح ch)
{
    صحيح size;
    size = cstr->size + 1;
    אם (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN حرف *unicode_to_utf8 (حرف *b, uint32_t Uc)
{
    אם (Uc<0x80) *b++=Uc;
    אחרת אם (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    אחרת אם (Uc-0xd800u<0x800) اذهب error;
    אחרת אם (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    אחרת אם (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    אחרת error: tcc_error("0x%x is not a valid universal character", Uc);
    החזר b;
}

/* add a unicode character expanded into utf8 */
ST_INLN فراغ cstr_u8cat(CString *cstr, صحيح ch)
{
    حرف buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC فراغ cstr_cat(CString *cstr, ثابت حرف *str, صحيح len)
{
    صحيح size;
    אם (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    אם (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC فراغ cstr_wccat(CString *cstr, صحيح ch)
{
    صحيح size;
    size = cstr->size + حجم(nwchar_t);
    אם (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - حجم(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC فراغ cstr_new(CString *cstr)
{
    memset(cstr, 0, حجم(CString));
}

/* free string and reset it to NULL */
ST_FUNC فراغ cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC فراغ cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC صحيح cstr_vprintf(CString *cstr, ثابت حرف *fmt, va_list ap)
{
    va_list v;
    صحيح len, size = 80;
    עבור (;;) {
        size += cstr->size;
        אם (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        אם (len >= 0 && len < size)
            اكسر;
        size *= 2;
    }
    cstr->size += len;
    החזר len;
}

ST_FUNC صحيح cstr_printf(CString *cstr, ثابت حرف *fmt, ...)
{
    va_list ap; صحيح len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    החזר len;
}

/* XXX: unicode ? */
ساكن فراغ add_char(CString *cstr, صحيح c)
{
    אם (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    אם (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } אחרת {
        cstr_ccat(cstr, '\\');
        אם (c == '\n') {
            cstr_ccat(cstr, 'n');
        } אחרת {
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

    אם (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    אם ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * حجم(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, حجم(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = عدم;
    ts->sym_label = عدم;
    ts->sym_struct = عدم;
    ts->sym_identifier = عدم;
    ts->len = len;
    ts->hash_next = عدم;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    החזר ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ثابت حرف *str, صحيح len)
{
    TokenSym *ts, **pts;
    صحيح i;
    unsigned صحيح h;
    
    h = TOK_HASH_INIT;
    עבור(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned حرف *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    עבור(;;) {
        ts = *pts;
        אם (!ts)
            اكسر;
        אם (ts->len == len && !memcmp(ts->str, str, len))
            החזר ts;
        pts = &(ts->hash_next);
    }
    החזר tok_alloc_new(pts, str, len);
}

ST_FUNC صحيح tok_alloc_const(ثابت حرف *str)
{
    החזר tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ثابت حرف *get_tok_str(صحيح v, CValue *cv)
{
    حرف *p;
    صحيح i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    بدل(v) {
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CLONG:
    حالة TOK_CULONG:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        اكسر;
    حالة TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    حالة TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        اكسر;
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        החזר (حرف*)cv->str.data;
    حالة TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    حالة TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        אם (v == TOK_STR) {
            len = cv->str.size - 1;
            עבור(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned حرف *)cv->str.data)[i]);
        } אחרת {
            len = (cv->str.size / حجم(nwchar_t)) - 1;
            עבור(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        اكسر;

    حالة TOK_CFLOAT:
        החזר strcpy(p, "<float>");
    حالة TOK_CDOUBLE:
        החזר strcpy(p, "<double>");
    حالة TOK_CLDOUBLE:
        החזר strcpy(p, "<long double>");
    حالة TOK_LINENUM:
        החזר strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    حالة TOK_LT:
        v = '<';
        اذهب addv;
    حالة TOK_GT:
        v = '>';
        اذهب addv;
    حالة TOK_DOTS:
        החזר strcpy(p, "...");
    حالة TOK_A_SHL:
        החזר strcpy(p, "<<=");
    حالة TOK_A_SAR:
        החזר strcpy(p, ">>=");
    حالة TOK_EOF:
        החזר strcpy(p, "<eof>");
    حالة 0: /* anonymous nameless symbols */
        החזר strcpy(p, "<no name>");
    افتراضي:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        אם (v < TOK_IDENT) {
            /* search in two bytes table */
            ثابت unsigned حرف *q = tok_two_chars;
            כלעוד (*q) {
                אם (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    החזר cstr_buf.data;
                }
                q += 3;
            }
            אם (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                اكسر;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } אחרת אם (v < tok_ident) {
            החזר table_ident[v - TOK_IDENT]->str;
        } אחרת אם (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } אחרת {
            /* should never happen */
            החזר عدم;
        }
        اكسر;
    }
    החזר cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ساكن صحيح handle_eob(فراغ)
{
    BufferedFile *bf = file;
    صحيح len;

    /* only tries to read if really end of buffer */
    אם (bf->buf_ptr >= bf->buf_end) {
        אם (bf->fd >= 0) {
#אם defined(PARSE_DEBUG)
            len = 1;
#אחרת
            len = IO_BUF_SIZE;
#endif
            len = اقرأ(bf->fd, bf->buffer, len);
            אם (len < 0)
                len = 0;
        } אחרת {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    אם (bf->buf_ptr < bf->buf_end) {
        החזר bf->buf_ptr[0];
    } אחרת {
        bf->buf_ptr = bf->buf_end;
        החזר CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ساكن صحيح next_c(فراغ)
{
    صحيح ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    אם (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    החזר ch;
}

/* input with '\[\r]\n' handling. */
ساكن صحيح handle_stray_noerror(صحيح err)
{
    صحيح ch;
    כלעוד ((ch = next_c()) == '\\') {
        ch = next_c();
        אם (ch == '\n') {
    newl:
            file->line_num++;
        } אחרת {
            אם (ch == '\r') {
                ch = next_c();
                אם (ch == '\n')
                    اذهب newl;
                *--file->buf_ptr = '\r';
            }
            אם (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            החזר *--file->buf_ptr = '\\';
        }
    }
    החזר ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ساكن صحيح handle_bs(uint8_t **p)
{
    صحيح c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    החזר c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ساكن صحيح handle_stray(uint8_t **p)
{
    صحيح c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    החזר c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    אם (c == '\\')\
        c = handle_stray(&p); \
}

ساكن صحيح skip_spaces(فراغ)
{
    صحيح ch;
    --file->buf_ptr;
    עשה {
        ch = ninp();
    } כלעוד (isidnum_table[ch - CH_EOF] & IS_SPC);
    החזר ch;
}

/* single line C++ comments */
ساكن uint8_t *parse_line_comment(uint8_t *p)
{
    صحيح c;
    עבור(;;) {
        עבור (;;) {
            c = *++p;
    redo:
            אם (c == '\n' || c == '\\')
                اكسر;
            c = *++p;
            אם (c == '\n' || c == '\\')
                اكسر;
        }
        אם (c == '\n')
            اكسر;
        c = handle_bs(&p);
        אם (c == CH_EOF)
            اكسر;
        אם (c != '\\')
            اذهب redo;
    }
    החזר p;
}

/* C comments */
ساكن uint8_t *parse_comment(uint8_t *p)
{
    صحيح c;
    עבור(;;) {
        /* fast skip loop */
        עבור(;;) {
            c = *++p;
        redo:
            אם (c == '\n' || c == '*' || c == '\\')
                اكسر;
            c = *++p;
            אם (c == '\n' || c == '*' || c == '\\')
                اكسر;
        }
        /* now we can handle all the cases */
        אם (c == '\n') {
            file->line_num++;
        } אחרת אם (c == '*') {
            עשה {
                c = *++p;
            } כלעוד (c == '*');
            אם (c == '\\')
                c = handle_bs(&p);
            אם (c == '/')
                اكسر;
            اذهب check_eof;
        } אחרת {
            c = handle_bs(&p);
        check_eof:
            אם (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            אם (c != '\\')
                اذهب redo;
        }
    }
    החזר p + 1;
}

/* parse a string without interpreting escapes */
ساكن uint8_t *parse_pp_string(uint8_t *p, صحيح sep, CString *str)
{
    صحيح c;
    עבור(;;) {
        c = *++p;
    redo:
        אם (c == sep) {
            اكسر;
        } אחרת אם (c == '\\') {
            c = handle_bs(&p);
            אם (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } אחרת אם (c == '\\') {
                אם (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                אם (c == '\\') {
                    c = handle_bs(&p);
                    אם (c == CH_EOF)
                        اذهب unterminated_string;
                }
                اذهب add_char;
            } אחרת {
                اذهب redo;
            }
        } אחרת אם (c == '\n') {
        add_lf:
            אם (ACCEPT_LF_IN_STRINGS) {
                file->line_num++;
                اذهب add_char;
            } אחרת אם (str) { /* not skipping */
                اذهب unterminated_string;
            } אחרת {
                //tcc_warning("missing terminating %c character", sep);
                החזר p;
            }
        } אחרת אם (c == '\r') {
            c = *++p;
            אם (c == '\\')
                c = handle_bs(&p);
            אם (c == '\n')
                اذهب add_lf;
            אם (c == CH_EOF)
                اذهب unterminated_string;
            אם (str)
                cstr_ccat(str, '\r');
            اذهب redo;
        } אחרת {
        add_char:
            אם (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    החזר p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ساكن فراغ preprocess_skip(فراغ)
{
    صحيح a, start_of_line, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_line = 1;
    in_warn_or_error = 0;
    עבור(;;) {
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
            file->line_num++;
            p++;
            اذهب redo_start;
        حالة '\\':
            c = handle_bs(&p);
            אם (c == CH_EOF)
                expect("#endif");
            אם (c == '\\')
                ++p;
            استمر;
        /* skip strings */
        حالة '\"':
        حالة '\'':
            אם (in_warn_or_error)
                اذهب _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, عدم);
            اكسر;
        /* skip comments */
        حالة '/':
            אם (in_warn_or_error)
                اذهب _default;
            ++p;
            c = handle_bs(&p);
            אם (c == '*') {
                p = parse_comment(p);
            } אחרת אם (c == '/') {
                p = parse_line_comment(p);
            }
            استمر;
        حالة '#':
            p++;
            אם (start_of_line) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                אם (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    اذهب the_end;
                אם (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                אחרת אם (tok == TOK_ENDIF)
                    a--;
                אחרת אם( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                אחרת אם (tok == TOK_LINEFEED)
                    اذهب redo_start;
                אחרת אם (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_line_comment(p - 1);
            }
#אם !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            אחרת אם (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_line_comment(p - 1);
#אחרת
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            اكسر;
_default:
        افتراضي:
            p++;
            اكسر;
        }
        start_of_line = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#אם 0
/* return the number of additional 'ints' necessary to store the
   token */
ساكن مضمن صحيح tok_size(ثابت صحيح *p)
{
    بدل(*p) {
        /* 4 bytes */
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_CFLOAT:
    حالة TOK_LINENUM:
        החזר 1 + 1;
    حالة TOK_STR:
    حالة TOK_LSTR:
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        החזר 1 + 1 + (p[1] + 3) / 4;
    حالة TOK_CLONG:
    حالة TOK_CULONG:
	החזר 1 + LONG_SIZE / 4;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
        החזר 1 + 2;
    حالة TOK_CLDOUBLE:
        החזר 1 + LDOUBLE_WORDS;
    افتراضي:
        החזר 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN فراغ tok_str_new(TokenString *s)
{
    s->str = عدم;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_line_num = -1;
}

ST_FUNC TokenString *tok_str_alloc(فراغ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, حجم *str);
    tok_str_new(str);
    החזר str;
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

ST_FUNC صحيح *tok_str_realloc(TokenString *s, صحيح new_size)
{
    صحيح *str, size;

    size = s->allocated_len;
    אם (size < 16)
        size = 16;
    כלעוד (size < new_size)
        size = size * 2;
    אם (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * حجم(صحيح));
        s->allocated_len = size;
        s->str = str;
    }
    החזר s->str;
}

ST_FUNC فراغ tok_str_add(TokenString *s, صحيح t)
{
    صحيح len, *str;

    len = s->len;
    str = s->str;
    אם (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC فراغ begin_macro(TokenString *str, صحيح alloc)
{
    str->alloc = alloc;
    str->prev = macro_stack;
    str->prev_ptr = macro_ptr;
    str->save_line_num = file->line_num;
    macro_ptr = str->str;
    macro_stack = str;
}

ST_FUNC فراغ end_macro(فراغ)
{
    TokenString *str = macro_stack;
    macro_stack = str->prev;
    macro_ptr = str->prev_ptr;
    file->line_num = str->save_line_num;
    אם (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } אחרת {
        אם (str->alloc == 2)
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
    אם (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    بدل(t) {
    حالة TOK_CINT:
    حالة TOK_CUINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_CFLOAT:
    حالة TOK_LINENUM:
#אם LONG_SIZE == 4
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        اكسر;
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
    حالة TOK_STR:
    حالة TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_words =
                1 + (cv->str.size + حجم(صحيح) - 1) / حجم(صحيح);
            אם (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        اكسر;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
#אם LONG_SIZE == 8
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        اكسر;
    حالة TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        אם (LDOUBLE_WORDS >= 3)
        str[len++] = cv->tab[2];
        אם (LDOUBLE_WORDS >= 4)
        str[len++] = cv->tab[3];
    افتراضي:
        اكسر;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC فراغ tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    אם (file->line_num != s->last_line_num) {
        s->last_line_num = file->line_num;
        cval.i = s->last_line_num;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ساكن فراغ tok_str_add2_spc(TokenString *s, صحيح t, CValue *cv)
{
    אם (s->need_spc == 3)
        tok_str_add(s, ' ');
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
#אם LONG_SIZE == 4
    حالة TOK_CLONG:
#endif
    حالة TOK_CINT:
    حالة TOK_CCHAR:
    حالة TOK_LCHAR:
    حالة TOK_LINENUM:
        cv->i = *p++;
        اكسر;
#אם LONG_SIZE == 4
    حالة TOK_CULONG:
#endif
    حالة TOK_CUINT:
        cv->i = (unsigned)*p++;
        اكسر;
    حالة TOK_CFLOAT:
	tab[0] = *p++;
	اكسر;
    حالة TOK_STR:
    حالة TOK_LSTR:
    حالة TOK_PPNUM:
    حالة TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (حرف*)p;
        p += (cv->str.size + حجم(صحيح) - 1) / حجم(صحيح);
        اكسر;
    حالة TOK_CDOUBLE:
    حالة TOK_CLLONG:
    حالة TOK_CULLONG:
#אם LONG_SIZE == 8
    حالة TOK_CLONG:
    حالة TOK_CULONG:
#endif
        n = 2;
        اذهب copy;
    حالة TOK_CLDOUBLE:
        n = LDOUBLE_WORDS;
    copy:
        עשה
            *tab++ = *p++;
        כלעוד (--n);
        اكسر;
    افتراضي:
        اكسر;
    }
    *pp = p;
}

#אם 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#אחרת
# define TOK_GET(t,p,c) עשה { \
    صحيح _t = **(p); \
    אם (TOK_HAS_VALUE(_t)) \
        tok_get(t, p, c); \
    אחרת \
        *(t) = _t, ++*(p); \
    } כלעוד (0)
#endif

ساكن صحيح macro_is_equal(ثابت صحيح *a, ثابت صحيح *b)
{
    CValue cv;
    صحيح t;

    אם (!a || !b)
        החזר 1;

    כלעוד (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        אם (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            החזר 0;
    }
    החזר !(*a || *b);
}

/* defines handling */
ST_INLN فراغ define_push(صحيح v, صحيح macro_type, صحيح *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_stack, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    אם (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, عدم));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC فراغ define_undef(Sym *s)
{
    صحيح v = s->v;
    אם (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = عدم;
}

ST_INLN Sym *define_find(صحيح v)
{
    v -= TOK_IDENT;
    אם ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        החזר عدم;
    החזר table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC فراغ free_defines(Sym *b)
{
    כלעוד (define_stack != b) {
        Sym *top = define_stack;
        define_stack = top->prev;
        tok_str_free_str(top->d);
        define_undef(top);
        sym_free(top);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ساكن فراغ maybe_run_test(TCCState *s)
{
    ثابت حرف *p;
    אם (s->include_stack_ptr != s->include_stack)
        החזר;
    p = get_tok_str(tok, عدم);
    אם (0 != memcmp(p, "test_", 5))
        החזר;
    אם (0 != --s->run_test)
        החזר;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_push(tok, MACRO_OBJ, عدم, عدم);
}

ST_FUNC فراغ skip_to_eol(صحيح warn)
{
    אם (tok == TOK_LINEFEED)
        החזר;
    אם (warn)
        tcc_warning("extra tokens after directive");
    כלעוד (macro_stack)
        end_macro();
    file->buf_ptr = parse_line_comment(file->buf_ptr - 1);
    next_nomacro();
}

ساكن CachedInclude *
search_cached_include(TCCState *s1, ثابت حرف *filename, صحيح add);

ساكن صحيح parse_include(TCCState *s1, صحيح do_next, صحيح test)
{
    صحيح c, i;
    حرف name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    אם (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, حجم name, tokcstr.data, i);
        next_nomacro();
    } אחרת {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        עבור (;;) {
            next();
            p = name, i = strlen(p) - 1;
            אם (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                اكسر;
            אם (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, حجم name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    אם (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    עבור (;;) {
        ++i;
        אם (i == 0) {
            /* check absolute include path */
            אם (!IS_ABSPATH(name))
                استمر;
            buf[0] = '\0';
        } אחרת אם (i == 1) {
            /* search in file's dir if "header.h" */
            אם (c != '\"')
                استمر;
            p = file->true_filename;
            pstrncpy(buf, حجم buf, p, tcc_basename(p) - p);
        } אחרת {
            صحيح j = i - 2, k = j - s1->nb_include_paths;
            אם (k < 0)
                p = s1->include_paths[j];
            אחרת אם (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            אחרת אם (test)
                החזר 0;
            אחרת
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, حجم buf, p);
            pstrcat(buf, حجم buf, "/");
        }
        pstrcat(buf, حجم buf, name);
        e = search_cached_include(s1, buf, 0);
        אם (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            אם ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (صحيح)(s1->include_stack_ptr - s1->include_stack), "", buf);
            החזר 1;
        }
        אם (tcc_open(s1, buf) >= 0)
            اكسر;
    }

    אם (test) {
        tcc_close();
    } אחרת {
        אם (s1->include_stack_ptr >= s1->include_stack + INCLUDE_STACK_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_stack_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        אם (s1->gen_deps) {
            BufferedFile *bf = file;
            כלעוד (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            אם (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    החזר 1;
}

/* eval an expression for #if/#elif */
ساكن صحيح expr_preprocess(TCCState *s1)
{
    صحيح c, t;
    صحيح t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_expr = 1;
    כלעוד (1) {
        next(); /* do macro subst */
        t = tok;
        אם (tok < TOK_IDENT) {
            אם (tok == TOK_LINEFEED || tok == TOK_EOF)
                اكسر;
            אם (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } אחרת אם (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            אם (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            אם (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            אם (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            אם (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            אם (t == '(') {
                next();
                אם (tok != ')')
                    expect("')'");
            }
            اذهب c_number;
        } אחרת אם (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    אם (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            אם (tok != ')')
                expect("')'");
            اذهب c_number;
        } אחרת {
            /* if undefined macro, replace with zero */
            c = 0;
        c_number:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    אם (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_expr = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = expr_const();
    אם (tok != TOK_EOF)
        tcc_error("...");
    pp_expr = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    החזר c != 0;
}

ST_FUNC فراغ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_expr, 0));
    macro_ptr = macro_stack->str;
    כלעוד (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC فراغ parse_define(فراغ)
{
    Sym *s, *first, **ps;
    صحيح v, t, varg, is_vaargs, t0;
    صحيح saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    אם (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = عدم;
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
    אם (tok == '(') {
        صحيح dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        אם (tok != ')') עבור (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            אם (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } אחרת אם (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            אם (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_stack, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            אם (tok == ')')
                اكسر;
            אם (tok != ',' || is_vaargs)
                اذهب bad_list;
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
    כלעוד (tok != TOK_LINEFEED && tok != TOK_EOF) {
        אם (is_space(tok)) {
            str.need_spc |= 1;
        } אחרת {
            אם (TOK_TWOSHARPS == tok) {
                אם (0 == t0)
                    اذهب bad_twosharp;
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
    אם (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_push(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ساكن CachedInclude *search_cached_include(TCCState *s1, ثابت حرف *filename, صحيح add)
{
    ثابت حرف *s, *basename;
    unsigned صحيح h;
    CachedInclude *e;
    صحيح c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    כלעוד ((c = (unsigned حرف)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#אחרת
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    עבור(;;) {
        אם (i == 0)
            اكسر;
        e = s1->cached_includes[i - 1];
        אם (0 == PATHCMP(filename, e->filename))
            החזר e;
        אם (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            החזר e;
        i = e->hash_next;
    }
    אם (!add)
        החזר عدم;

    e = tcc_malloc(حجم(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    החזר e;
}

ساكن صحيح pragma_parse(TCCState *s1)
{
    next_nomacro();
    אם (tok == TOK_push_macro || tok == TOK_pop_macro) {
        صحيح t = tok, v;
        Sym *s;

        אם (next(), tok != '(')
            اذهب pragma_err;
        אם (next(), tok != TOK_STR)
            اذهب pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        אם (next(), tok != ')')
            اذهب pragma_err;
        אם (t == TOK_push_macro) {
            כלעוד (عدم == (s = define_find(v)))
                define_push(v, 0, عدم, عدم);
            s->type.ref = s; /* set push boundary */
        } אחרת {
            עבור (s = define_stack; s; s = s->prev)
                אם (s->v == v && s->type.ref == s) {
                    s->type.ref = عدم;
                    اكسر;
                }
        }
        אם (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : عدم;
        אחרת
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } אחרת אם (tok == TOK_once) {
        search_cached_include(s1, file->true_filename, 1)->once = 1;

    } אחרת אם (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        החזר 1;

    } אחרת אם (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        אם (tok == TOK_ASM_pop) {
            next();
            אם (s1->pack_stack_ptr <= s1->pack_stack) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_stack_ptr--;
        } אחרת {
            صحيح val = 0;
            אם (tok != ')') {
                אם (tok == TOK_ASM_push) {
                    next();
                    אם (s1->pack_stack_ptr >= s1->pack_stack + PACK_STACK_SIZE - 1)
                        اذهب stk_error;
                    val = *s1->pack_stack_ptr++;
                    אם (tok != ',')
                        اذهب pack_set;
                    next();
                }
                אם (tok != TOK_CINT)
                    اذهب pragma_err;
                val = tokc.i;
                אם (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    اذهب pragma_err;
                next();
            }
        pack_set:
            *s1->pack_stack_ptr = val;
        }
        אם (tok != ')')
            اذهب pragma_err;

    } אחרת אם (tok == TOK_comment) {
        حرف *p; صحيح t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        אם (tok != TOK_STR)
            اذهب pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        אם (tok != ')')
            اذهب pragma_err;
        אם (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } אחרת {
            אם (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } אחרת {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        החזר 0;
    }
    next();
    החזר 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC فراغ tccpp_putfile(ثابت حرف *filename)
{
    حرف buf[1024];
    buf[0] = 0;
    אם (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, حجم buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, حجم buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    אם (0 == strcmp(file->filename, buf))
        החזר;
    //printf("new file '%s'\n", buf);
    אם (file->true_filename == file->filename)
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
        | PARSE_FLAG_TOK_NUM
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    بدل(tok) {
    حالة TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        اكسر;
    حالة TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        אם (s)
            define_undef(s);
        next_nomacro();
        اكسر;
    حالة TOK_INCLUDE:
    حالة TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        اذهب the_end;
    حالة TOK_IFNDEF:
        c = 1;
        اذهب do_ifdef;
    حالة TOK_IF:
        c = expr_preprocess(s1);
        اذهب do_if;
    حالة TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        אם (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        אם (is_bof) {
            אם (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, عدم));
#endif
                file->ifndef_macro = tok;
            }
        }
        אם (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        אם (s1->ifdef_stack_ptr >= s1->ifdef_stack + IFDEF_STACK_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_stack_ptr++ = c;
        اذهب test_skip;
    حالة TOK_ELSE:
        next_nomacro();
        אם (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#else without matching #if");
        אם (s1->ifdef_stack_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_stack_ptr[-1] ^= 3);
        اذهب test_else;
    حالة TOK_ELIF:
        אם (s1->ifdef_stack_ptr == s1->ifdef_stack)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_stack_ptr[-1];
        אם (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        אם (c == 1) {
            skip_to_eol(0);
            c = 0;
        } אחרת {
            c = expr_preprocess(s1);
            s1->ifdef_stack_ptr[-1] = c;
        }
    test_else:
        אם (s1->ifdef_stack_ptr == file->ifdef_stack_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        אם (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            اذهب redo;
        }
        اكسر;
    حالة TOK_ENDIF:
        next_nomacro();
        אם (s1->ifdef_stack_ptr <= file->ifdef_stack_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_stack_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        אם (file->ifndef_macro &&
            s1->ifdef_stack_ptr == file->ifdef_stack_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        اكسر;

    حالة TOK_LINE:
        parse_flags &= ~PARSE_FLAG_TOK_NUM;
        next();
        אם (tok != TOK_PPNUM) {
    _line_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        اذهب _line_num;
    حالة TOK_PPNUM:
        אם (parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب ignore;
        c = 0; /* no error with extra tokens */
    _line_num:
        עבור (n = 0, q = tokc.str.data; *q; ++q) {
            אם (!isnum(*q))
                اذهب _line_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        אם (tok != TOK_LINEFEED) {
            אם (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                اذهب _line_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        אם (file->fd > 0)
            total_lines += file->line_num - n;
        file->line_num = n;
        اكسر;

    حالة TOK_ERROR:
    حالة TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        כלעוד (c != '\n' && c != CH_EOF) {
            אם ((q - buf) < حجم(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        אם (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        אחרת
            tcc_warning("#warning %s", buf);
        next_nomacro();
        اكسر;
    }
    حالة TOK_PRAGMA:
        אם (!pragma_parse(s1))
            اذهب ignore;
        اكسر;
    حالة TOK_LINEFEED:
        اذهب the_end;
    افتراضي:
        /* ignore gas line comment in an 'S' file. */
        אם (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب ignore;
        אם (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            اذهب ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        اذهب the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ساكن فراغ parse_escape_string(CString *outstr, ثابت uint8_t *buf, صحيح is_long)
{
    صحيح c, n, i;
    ثابت uint8_t *p;

    p = buf;
    עבור(;;) {
        c = *p;
        אם (c == '\0')
            اكسر;
        אם (c == '\\') {
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
                אם (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    אם (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                اذهب add_char_nonext;
            حالة 'x': i = 0; اذهب parse_hex_or_ucn;
            حالة 'u': i = 4; اذهب parse_hex_or_ucn;
            حالة 'U': i = 8; اذهب parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                עשה {
                    c = *p;
                    אם (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    אחרת אם (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    אחרת אם (isnum(c))
                        c = c - '0';
                    אחרת אם (i >= 0)
                        expect("more hex digits in universal-character-name");
                    אחרת
                        اذهب add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } כלעוד (--i);
		אם (is_long) {
    add_hex_or_ucn:
                    c = n;
		    اذهب add_char_nonext;
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
                אם (!gnu_ext)
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
                אם (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                אחרת
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                اكسر;
            }
        } אחרת אם (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            صحيح cont; /* count of continuation bytes */
            صحيح skip; /* how many bytes should skip when error occurred */
            صحيح i;

            /* decode leading byte */
            אם (c < 0xC2) {
	            skip = 1; اذهب invalid_utf8_sequence;
            } אחרת אם (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } אחרת אם (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } אחרת אם (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } אחרת {
	            skip = 1; اذهب invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            עבור (i = 1; i <= cont; i++) {
                صحيح l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                אם (i == 1) {
                    بدل (c) {
                    حالة 0xE0: l = 0xA0; اكسر;
                    حالة 0xED: h = 0x9F; اكسر;
                    حالة 0xF0: l = 0x90; اكسر;
                    حالة 0xF4: h = 0x8F; اكسر;
                    }
                }

                אם (p[i] < l || p[i] > h) {
                    skip = i; اذهب invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            اذهب add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            اذهب add_char_nonext;

        }
        p++;
    add_char_nonext:
        אם (!is_long)
            cstr_ccat(outstr, c);
        אחרת {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            אם (c < 0x10000) {
                cstr_wccat(outstr, c);
            } אחרת {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#אחרת
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    אם (!is_long)
        cstr_ccat(outstr, '\0');
    אחרת
        cstr_wccat(outstr, '\0');
}

ساكن فراغ parse_string(ثابت حرف *s, صحيح len)
{
    uint8_t buf[1000], *p = buf;
    صحيح is_long, sep;

    אם ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    אם (len >= حجم buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    אם (p != buf)
        tcc_free(p);

    אם (sep == '\'') {
        صحيح char_size, i, n, c;
        /* XXX: make it portable */
        אם (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        אחרת
            tok = TOK_LCHAR, char_size = حجم(nwchar_t);
        n = tokcstr.size / char_size - 1;
        אם (n < 1)
            tcc_error("empty character constant");
        אם (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        עבור (c = i = 0; i < n; ++i) {
            אם (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            אחרת
                c = (c << 8) | ((حرف *)tokcstr.data)[i];
        }
        tokc.i = c;
    } אחרת {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        אם (!is_long)
            tok = TOK_STR;
        אחרת
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
ساكن صحيح bn_lshift(unsigned صحيح *bn, صحيح shift, صحيح or_val)
{
    صحيح i;
    unsigned صحيح v;
    אם (bn[BN_SIZE - 1] >> (32 - shift))
	החזר shift;
    עבור(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    החזר 0;
}

ساكن فراغ bn_zero(unsigned صحيح *bn)
{
    صحيح i;
    עבור(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ساكن فراغ parse_number(ثابت حرف *p)
{
    صحيح b, t, shift, frac_bits, s, exp_val, ch;
    حرف *q;
    unsigned صحيح bn[BN_SIZE];
    long مزدوج d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    אם (t == '.') {
        اذهب float_frac_parse;
    } אחרת אם (t == '0') {
        אם (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } אחרת אם (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    כלעוד (1) {
        אם (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        אחרת אם (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        אחרת אם (isnum(ch))
            t = ch - '0';
        אחרת
            اكسر;
        אם (t >= b)
            اكسر;
        אם (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    אם (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        אם (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            אם (b == 16)
                shift = 4;
            אחרת 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            כלעוד (1) {
                t = *q++;
                אם (t == '\0') {
                    اكسر;
                } אחרת אם (t >= 'a') {
                    t = t - 'a' + 10;
                } אחרת אם (t >= 'A') {
                    t = t - 'A' + 10;
                } אחרת {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            אם (ch == '.') {
                ch = *p++;
                כלעוד (1) {
                    t = ch;
                    אם (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } אחרת אם (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } אחרת אם (t >= '0' && t <= '9') {
                        t = t - '0';
                    } אחרת {
                        اكسر;
                    }
                    אם (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            אם (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            אם (ch == '+') {
                ch = *p++;
            } אחרת אם (ch == '-') {
                s = -1;
                ch = *p++;
            }
            אם (ch < '0' || ch > '9')
                expect("exponent digits");
            כלעוד (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		אם (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long مزدوج)bn[3] * 79228162514264337593543950336.0L +
	        (long مزدوج)bn[2] * 18446744073709551616.0L +
	        (long مزدوج)bn[1] * 4294967296.0L +
	        (long مزدوج)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            אם (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (عائم)d;
            } אחרת אם (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } אחרת {
                tok = TOK_CDOUBLE;
                tokc.d = (مزدوج)d;
            }
        } אחרת {
            /* decimal floats */
            אם (ch == '.') {
                אם (q >= token_buf + STRING_MAX_SIZE)
                    اذهب num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                כלעוד (ch >= '0' && ch <= '9') {
                    אם (q >= token_buf + STRING_MAX_SIZE)
                        اذهب num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            אם (ch == 'e' || ch == 'E') {
                אם (q >= token_buf + STRING_MAX_SIZE)
                    اذهب num_too_long;
                *q++ = ch;
                ch = *p++;
                אם (ch == '-' || ch == '+') {
                    אם (q >= token_buf + STRING_MAX_SIZE)
                        اذهب num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                אם (ch < '0' || ch > '9')
                    expect("exponent digits");
                כלעוד (ch >= '0' && ch <= '9') {
                    אם (q >= token_buf + STRING_MAX_SIZE)
                        اذهب num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            אם (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, عدم);
            } אחרת אם (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, عدم);
            } אחרת {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, عدم);
            }
        }
    } אחרת {
        unsigned long long n, n1;
        صحيح lcount, ucount, ov = 0;
        ثابت حرف *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        אם (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        כלעוד(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            אם (t == '\0')
                اكسر;
            אחרת אם (t >= 'a')
                t = t - 'a' + 10;
            אחרת אם (t >= 'A')
                t = t - 'A' + 10;
            אחרת
                t = t - '0';
            אם (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            אם (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        עבור(;;) {
            t = toup(ch);
            אם (t == 'L') {
                אם (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                אם (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } אחרת אם (t == 'U') {
                אם (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } אחרת {
                اكسر;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        אם (pp_expr)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        אם (ucount == 0 && b == 10) {
            אם (lcount <= (LONG_SIZE == 4)) {
                אם (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            אם (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } אחרת {
            אם (lcount <= (LONG_SIZE == 4)) {
                אם (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                אחרת אם (n >= 0x80000000U)
                    ucount = 1;
            }
            אם (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        אם (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	אם (lcount) {
            tok = TOK_CLONG;
            אם (lcount == 2)
                tok = TOK_CLLONG;
	}
	אם (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    אם (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    حالة c1:                                    \
        PEEKC(c, p);                            \
        אם (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } אחרת {                                \
            tok = tok1;                         \
        }                                       \
        اكسر;

/* return next token without macro substitution */
ساكن فراغ next_nomacro(فراغ)
{
    صحيح t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned صحيح h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    بدل(c) {
    حالة ' ':
    حالة '\t':
        tok = c;
        p++;
 maybe_space:
        אם (parse_flags & PARSE_FLAG_SPACES)
            اذهب keep_tok_flags;
        כלעוד (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        اذهب redo_no_start;
    حالة '\f':
    حالة '\v':
    حالة '\r':
        p++;
        اذهب redo_no_start;
    حالة '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        אם (c == '\\')
            اذهب parse_simple;
        אם (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            אם (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                اذهب maybe_newline;
            } אחרת אם (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } אחרת אם (s1->ifdef_stack_ptr != file->ifdef_stack_ptr) {
                tcc_error("missing #endif");
            } אחרת אם (s1->include_stack_ptr == s1->include_stack) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } אחרת {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                אם (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, عدم));
#endif
                    search_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_stack_ptr--;
                p = file->buf_ptr;
                اذهب maybe_newline;
            }
        } אחרת {
            اذهب redo_no_start;
        }
        اكسر;

    حالة '\n':
        file->line_num++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        אם (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            اذهب redo_no_start;
        tok = TOK_LINEFEED;
        اذهب keep_tok_flags;

    حالة '#':
        /* XXX: simplify */
        PEEKC(c, p);
        אם ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            اذهب maybe_newline;
        } אחרת {
            אם (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } אחרת {
#אם !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                אם (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_line_comment(p - 1);
                    اذهب redo_no_start;
                } אחרת
#endif
                {
                    tok = '#';
                }
            }
        }
        اكسر;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    حالة '$':
        אם (!(isidnum_table['$' - CH_EOF] & IS_ID)
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
        כלעוד (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        אם (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            עבור(;;) {
                ts = *pts;
                אם (!ts)
                    اكسر;
                אם (ts->len == len && !memcmp(ts->str, p1, len))
                    اذهب token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (حرف *) p1, len);
        token_found: ;
        } אחרת {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (حرف *) p1, len);
            p--;
            PEEKC(c, p);
            כלעוד (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        اكسر;
    حالة 'L':
        t = p[1];
        אם (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            אם (c == '\'' || c == '\"') {
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
    parse_num:
        cstr_reset(&tokcstr);
        עבור(;;) {
            cstr_ccat(&tokcstr, t);
            אם (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((حرف*)tokcstr.data)[0] == '0'
                                && toup(((حرف*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                اكسر;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        اكسر;

    حالة '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        אם (isnum(c)) {
            t = '.';
            اذهب parse_num;
        } אחרת אם ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_NUM))) {
            *--p = c = '.';
            اذهب parse_ident_fast;
        } אחרת אם (c == '.') {
            PEEKC(c, p);
            אם (c == '.') {
                p++;
                tok = TOK_DOTS;
            } אחרת {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } אחרת {
            tok = '.';
        }
        اكسر;
    حالة '\'':
    حالة '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        אם (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        اكسر;

    حالة '<':
        PEEKC(c, p);
        אם (c == '=') {
            p++;
            tok = TOK_LE;
        } אחרת אם (c == '<') {
            PEEKC(c, p);
            אם (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } אחרת {
                tok = TOK_SHL;
            }
        } אחרת {
            tok = TOK_LT;
        }
        اكسر;
    حالة '>':
        PEEKC(c, p);
        אם (c == '=') {
            p++;
            tok = TOK_GE;
        } אחרת אם (c == '>') {
            PEEKC(c, p);
            אם (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } אחרת {
                tok = TOK_SAR;
            }
        } אחרת {
            tok = TOK_GT;
        }
        اكسر;
        
    حالة '&':
        PEEKC(c, p);
        אם (c == '&') {
            p++;
            tok = TOK_LAND;
        } אחרת אם (c == '=') {
            p++;
            tok = TOK_A_AND;
        } אחרת {
            tok = '&';
        }
        اكسر;
        
    حالة '|':
        PEEKC(c, p);
        אם (c == '|') {
            p++;
            tok = TOK_LOR;
        } אחרת אם (c == '=') {
            p++;
            tok = TOK_A_OR;
        } אחרת {
            tok = '|';
        }
        اكسر;

    حالة '+':
        PEEKC(c, p);
        אם (c == '+') {
            p++;
            tok = TOK_INC;
        } אחרת אם (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } אחרת {
            tok = '+';
        }
        اكسر;
        
    حالة '-':
        PEEKC(c, p);
        אם (c == '-') {
            p++;
            tok = TOK_DEC;
        } אחרת אם (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } אחרת אם (c == '>') {
            p++;
            tok = TOK_ARROW;
        } אחרת {
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
        אם (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            اذهب maybe_space;
        } אחרת אם (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            اذهب maybe_space;
        } אחרת אם (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } אחרת {
            tok = '/';
        }
        اكسر;
        
        /* simple tokens */
    حالة '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        אם (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_line_comment(p);
            اذهب redo_no_start;
        }
#endif
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
        אם (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            اذهب redo_no_start;
        }
    افتراضي:
        אם (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    اذهب parse_ident_fast;
        אם (parse_flags & PARSE_FLAG_ASM_FILE)
            اذهب parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        اكسر;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#אם defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
ساكن صحيح indent;
ساكن فراغ define_print(TCCState *s1, صحيح v);
ساكن فراغ pp_print(ثابت حرف *msg, صحيح v, ثابت صحيح *str)
{
    FILE *fp = tcc_state->ppfp;

    אם (msg[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    אחרת אם (msg[0] == '+')
         ++indent, ++msg;
    אחרת אם (msg[0] == '-')
        --indent, ++msg;

    fprintf(fp, "%*s", indent, "");
    אם (msg[0] == '#') {
        define_print(tcc_state, v);
    } אחרת {
        tok_print(str, v ? "%s %s" : "%s", msg, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#אחרת
#define PP_PRINT(x)
#endif

ساكن صحيح macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ثابت صحيح *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ساكن صحيح *macro_arg_subst(Sym **nested_list, ثابت صحيح *macro_str, Sym *args)
{
    صحيح t, t0, t1, t2, n;
    ثابت صحيح *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    עבור (s = args, n = 0; s; s = s->prev, ++n);
    כלעוד (n--) {
        עבור (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    כלעוד(1) {
        TOK_GET(&t, &macro_str, &cval);
        אם (!t)
            اكسر;
        אם (t == '#') {
            /* stringize */
            עשה t = *macro_str++; כלעוד (t == ' ');
            s = sym_find2(args, t);
            אם (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                כלעוד (*st != TOK_EOF) {
                    ثابت حرف *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    כלעוד (*s) {
                        אם (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        אחרת
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
            } אחרת אם ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } אחרת {
                expect("macro parameter after '#'");
            }
        } אחרת אם (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            אם (s) {
                st = s->d;
                n = 0;
                כלעוד ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                אם (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    אם (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        صحيح c = str.str[str.len - 1];
                        כלעוד (str.str[--str.len] != ',')
                            ;
                        אם (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } אחרת {
                            /* suppress '##' and add variable */
                            str.len++;
                            אם (c == ' ')
                                str.str[str.len++] = c;
                            اذهب add_var;
                        }
                    } אחרת {
                        אם (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } אחרת {
            add_var:
		    אם (!s->e) {
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
                כלעוד (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } אחרת {
                tok_str_add(&str, t);
            }
        } אחרת {
            tok_str_add2(&str, t, &cval);
        }
        אם (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    החזר str.str;
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
    עבור (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        אם (t1 == 0)
            اكسر;
        עבור (;;) {
            n = 0;
            כלעוד ((t2 = ptr[n]) == ' ')
                ++n;
            אם (t2 != TOK_PPJOIN)
                اكسر;
            ptr += n;
            כלעוד ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            אם (t2 == TOK_PLCHLDR)
                استمر;
            אם (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        אם (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            עבור (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                אם (*file->buf_ptr == 0)
                    اكسر;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        אם (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    החזר macro_str1.str;
}

ساكن صحيح peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    صحيح c;
    עבור (;;) {
        PEEKC(c, p);
        بدل (c) {
        حالة '/':
            PEEKC(c, p);
            אם (c == '*')
                p = parse_comment(p);
            אחרת אם (c == '/')
                p = parse_line_comment(p);
            אחרת {
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
            file->line_num++, tok_flags |= TOK_FLAG_BOL;
            اكسر;
        افتراضي: leave:
            file->buf_ptr = p;
            החזר c;
        }
        אם (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ساكن صحيح next_argstream(Sym **nested_list, TokenString *ws_str)
{
    صحيح t;
    Sym *sa;

    כלעוד (macro_ptr) {
        ثابت صحيح *m = macro_ptr;
        כלעוד ((t = *m) != 0) {
            אם (ws_str) {
                אם (t != ' ')
                    החזר t;
                ++m;
            } אחרת {
                TOK_GET(&tok, &macro_ptr, &tokc);
                החזר tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        אם (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    אם (ws_str) {
        החזר peek_file(ws_str);
    } אחרת {
        next_nomacro();
        אם (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        החזר tok;
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
    אם (s->d) {
        صحيح *mstr = s->d;
        صحيح *jstr;
        Sym *sa;
        صحيح ret;

        אם (s->type.t & MACRO_FUNC) {
            صحيح saved_parse_flags = parse_flags;
            TokenString str;
            صحيح parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            אם (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                אם (parse_flags & PARSE_FLAG_SPACES)
                    עבור (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                החזר 0;
            } אחרת {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = عدم;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            עבור(;;) {
                עשה {
                    t = next_argstream(nested_list, عدم);
                } כלעוד (t == ' ' || --i);

                אם (!sa) {
                    אם (t == ')') /* handle '()' case */
                        اكسر;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                כלעוד (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    אם (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    אם (t == '(')
                        parlevel++;
                    אם (t == ')')
                        parlevel--;
                    אם (t == ' ')
                        str.need_spc |= 1;
                    אחרת
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, عدم);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                אם (t == ')') {
                    אם (!sa)
                        اكسر;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    אם (sa->type.t && gnu_ext)
                        اذهب empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            כלעוד (sa) {
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
        אם (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        אם (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        אם (jstr != mstr)
            tok_str_free_str(jstr);
        אם (mstr != s->d)
            tok_str_free_str(mstr);
        החזר ret;

    } אחרת {
        CValue cval;
        حرف buf[32], *cstrval = buf;

        /* special macros */
        אם (v == TOK___LINE__ || v == TOK___COUNTER__) {
            t = v == TOK___LINE__ ? file->line_num : pp_counter++;
            snprintf(buf, حجم(buf), "%d", t);
            t = TOK_PPNUM;
            اذهب add_cstr1;

        } אחרת אם (v == TOK___FILE__) {
            cstrval = file->filename;
            اذهب add_cstr;

        } אחרת אם (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            بنية tm *tm;
            time(&ti);
            tm = localtime(&ti);
            אם (v == TOK___DATE__) {
                ساكن حرف ثابت ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, حجم(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } אחרת {
                snprintf(buf, حجم(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        החזר 0;
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

#ifdef PP_DEBUG
    صحيح tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    כלעוד (1) {
        TOK_GET(&t, &macro_str, &cval);
        אם (t == 0 || t == TOK_EOF)
            اكسر;
        אם (t >= TOK_IDENT) {
            s = define_find(t);
            אם (s == عدم || nosubst)
                اذهب no_subst;
            /* if nested substitution, do nothing */
            אם (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                اذهب no_subst;
            }
            str = tok_str_alloc();
            str->str = (صحيح*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            אם (macro_stack != str) {
                /* already finished by reading function macro arguments */
                اكسر;
            }
            macro_str = macro_ptr;
            end_macro ();
        } אחרת אם (t == ' ') {
            אם (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } אחרת {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            אם (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            אם (t == TOK_DEFINED && pp_expr)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    החזר nosubst;
}

/* return next token with macro substitution */
ST_FUNC فراغ next(فراغ)
{
    صحيح t;
    כלעוד (macro_ptr) {
redo:
        t = *macro_ptr;
        אם (TOK_HAS_VALUE(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            אם (t == TOK_LINENUM) {
                file->line_num = tokc.i;
                اذهب redo;
            }
            اذهب convert;
        } אחרת אם (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            استمر;
        } אחרת אם (t == TOK_EOF) {
            /* do nothing */
        } אחרת {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            אם (t == '\\') {
                אם (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        החזר;
    }

    next_nomacro();
    t = tok;
    אם (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        אם (s) {
            Sym *nested_list = عدم;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            اذهب redo;
        }
        החזר;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    אם (t == TOK_PPNUM) {
        אם  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number(tokc.str.data);
    } אחרת אם (t == TOK_PPSTR) {
        אם (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN فراغ unget_tok(صحيح last_tok)
{
    TokenString *str = &unget_buf;
    صحيح alloc = 0;
    אם (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    אם (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ساكن ثابت حرف * ثابت target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# אם PTR_SIZE == 8
    "_WIN64\0"
# endif
#אחרת
# אם defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# אחרת
    "__linux__\0"
    "__linux\0"
#  אם TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

ساكن فراغ putdef(CString *cs, ثابت حرف *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ساكن فراغ putdefs(CString *cs, ثابت حرف *p)
{
    כלעוד (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ساكن فراغ tcc_predefs(TCCState *s1, CString *cs, صحيح is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    אם (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    אם (is_asm)
      putdef(cs, "__ASSEMBLER__");
    אם (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    אם (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    אם (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    אם (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    אם (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    אם (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    אם (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    אם (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    אם (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#אם CONFIG_TCC_PREDEFS
        #ضمن "tccdefs_.h" /* include as strings */
#אחרת
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC فراغ preprocess_start(TCCState *s1, صحيح filetype)
{
    صحيح is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_stack_ptr = s1->include_stack;
    s1->ifdef_stack_ptr = s1->ifdef_stack;
    file->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    pp_expr = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_stack[0] = 0;
    s1->pack_stack_ptr = s1->pack_stack;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    אם (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        אם (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        אם (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_stack_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC فراغ preprocess_end(TCCState *s1)
{
    כלעוד (macro_stack)
        end_macro();
    macro_ptr = عدم;
    כלעוד (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC صحيح set_idnum(صحيح c, صحيح val)
{
    صحيح prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    החזר prev;
}

ST_FUNC فراغ tccpp_new(TCCState *s)
{
    صحيح i, c;
    ثابت حرف *p, *r;

    /* init isid table */
    עבור(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_NUM
            : 0);

    עבור(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * حجم(TokenSym *));
    memset(s->cached_includes_hash, 0, حجم s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    כלעוד (*p) {
        r = p;
        עבור(;;) {
            c = *r++;
            אם (c == '\0')
                اكسر;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_push(TOK___LINE__, MACRO_OBJ, عدم, عدم);
    define_push(TOK___FILE__, MACRO_OBJ, عدم, عدم);
    define_push(TOK___DATE__, MACRO_OBJ, عدم, عدم);
    define_push(TOK___TIME__, MACRO_OBJ, عدم, عدم);
    define_push(TOK___COUNTER__, MACRO_OBJ, عدم, عدم);
}

ST_FUNC فراغ tccpp_delete(TCCState *s)
{
    صحيح i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    אם (n > total_idents)
        total_idents = n;
    עבור (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = عدم;

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

ساكن فراغ tok_print(ثابت صحيح *str, ثابت حرف *msg, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    صحيح t, t0, s;
    CValue cval;

    va_start(ap, msg);
    vfprintf(fp, msg, ap);
    va_end(ap);

    s = t0 = 0;
    כלעוד (str) {
	TOK_GET(&t, &str, &cval);
	אם (t == 0 || t == TOK_EOF)
	    اكسر;
        אם (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ساكن فراغ pp_line(TCCState *s1, BufferedFile *f, صحيح level)
{
    صحيح d = f->line_num - f->line_ref;

    אם (s1->dflag & 4)
	החזר;

    אם (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } אחרת אם (level == 0 && f->line_ref && d < 8) {
	כלעוד (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } אחרת אם (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->line_num, f->filename);
    } אחרת {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->line_num, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->line_ref = f->line_num;
}

ساكن فراغ define_print(TCCState *s1, صحيح v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    אם (عدم == s || عدم == s->d)
        החזר;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, عدم));
    אם (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        אם (a)
            עבור (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, عدم));
                אם (!(a = a->next))
                    اكسر;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ساكن فراغ pp_debug_defines(TCCState *s1)
{
    صحيح v, t;
    ثابت حرف *vs;
    FILE *fp;

    t = pp_debug_tok;
    אם (t == 0)
        החזר;

    file->line_num--;
    pp_line(s1, file, 0);
    file->line_ref = ++file->line_num;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, عدم);
    אם (t == TOK_DEFINE) {
        define_print(s1, v);
    } אחרת אם (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } אחרת אם (t == TOK_push_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } אחרת אם (t == TOK_pop_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ساكن صحيح pp_need_space(صحيح a, صحيح b)
{
    החזר 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ساكن صحيح pp_check_he0xE(صحيح t, ثابت حرف *p)
{
    אם (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        החזר 'E';
    החזר t;
}

/* Preprocess the current file */
ST_FUNC صحيح tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    صحيح token_seen, spcs, level;
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
    אם (s1->Pflag == LINE_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_NUM, s1->Pflag = 1;

    אם (s1->do_bench) {
	/* for PP benchmarks */
	עשה next(); כלעוד (tok != TOK_EOF);
	החזר 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    אם (file->prev)
        pp_line(s1, file->prev, level++);
    pp_line(s1, file, level);

    עבור (;;) {
        iptr = s1->include_stack_ptr;
        next();
        אם (tok == TOK_EOF)
            اكسر;

        level = s1->include_stack_ptr - iptr;
        אם (level) {
            אם (level > 0)
                pp_line(s1, *iptr, 0);
            pp_line(s1, file, level);
        }
        אם (s1->dflag & 7) {
            pp_debug_defines(s1);
            אם (s1->dflag & 4)
                استمر;
        }

        אם (is_space(tok)) {
            אם (spcs < حجم white - 1)
                white[spcs++] = tok;
            استمر;
        } אחרת אם (tok == TOK_LINEFEED) {
            spcs = 0;
            אם (token_seen == TOK_LINEFEED)
                استمر;
            ++file->line_ref;
        } אחרת אם (token_seen == TOK_LINEFEED) {
            pp_line(s1, file, 0);
        } אחרת אם (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    החזר 0;
}

/* ------------------------------------------------------------------------- */
