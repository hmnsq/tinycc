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
#അന്തര്ഭാവ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA പൂർണ്ണസംഖ്യ tok_flags;
ST_DATA പൂർണ്ണസംഖ്യ parse_flags;

ST_DATA ഘടന BufferedFile *file;
ST_DATA പൂർണ്ണസംഖ്യ tok;
ST_DATA CValue tokc;
ST_DATA സ്ഥിരം പൂർണ്ണസംഖ്യ *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA പൂർണ്ണസംഖ്യ tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA പൂർണ്ണസംഖ്യ pp_വ്യഞ്ജകം;

/* ------------------------------------------------------------------------- */

സ്ഥിതം TokenSym *hash_ident[TOK_HASH_SIZE];
സ്ഥിതം അക്ഷരം token_buf[STRING_MAX_SIZE + 1];
സ്ഥിതം CString cstr_buf;
സ്ഥിതം TokenString tokstr_buf;
സ്ഥിതം TokenString unget_buf;
സ്ഥിതം unsigned അക്ഷരം isidnum_table[256 - CH_EOF];
സ്ഥിതം പൂർണ്ണസംഖ്യ pp_debug_tok, pp_debug_symv;
സ്ഥിതം പൂർണ്ണസംഖ്യ pp_counter;
സ്ഥിതം ശൂന്യം tok_print(സ്ഥിരം പൂർണ്ണസംഖ്യ *str, സ്ഥിരം അക്ഷരം *സന്ദേശം, ...);
സ്ഥിതം ശൂന്യം next_nomacro(ശൂന്യം);
സ്ഥിതം ശൂന്യം parse_സംഖ്യ(സ്ഥിരം അക്ഷരം *p);
സ്ഥിതം ശൂന്യം parse_string(സ്ഥിരം അക്ഷരം *p, പൂർണ്ണസംഖ്യ len);

സ്ഥിതം ഘടന TinyAlloc *toksym_alloc;
സ്ഥിതം ഘടന TinyAlloc *tokstr_alloc;

സ്ഥിതം TokenString *macro_അട്ടി;

സ്ഥിതം സ്ഥിരം അക്ഷരം tcc_keywords[] = 
#define DEF(id, str) str "\0"
#അന്തര്ഭാവ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം tok_two_chars[] =
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

ST_FUNC ശൂന്യം skip(പൂർണ്ണസംഖ്യ c)
{
    എങ്കിൽ (tok != c) {
        അക്ഷരം tmp[40];
        pstrcpy(tmp, വലുപ്പം tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC ശൂന്യം expect(സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
    tcc_error("%s expected", സന്ദേശം);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#അല്ലെങ്കിൽ
#എങ്കിൽ !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#അല്ലെങ്കിൽ
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , സ്ഥിരം അക്ഷരം *sfile, പൂർണ്ണസംഖ്യ sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

തരനിർവചനം ഘടന TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ഘടന TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#എങ്കിൽ TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    സംഘം {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

തരനിർവചനം ഘടന tal_header_t {
    size_t  size; /* word align */
#എങ്കിൽ TAL_DEBUG
    പൂർണ്ണസംഖ്യ     വരി_അക്കം; /* negative line_num used for double free check */
    അക്ഷരം    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (വലുപ്പം (size_t) - 1)) & ~(വലുപ്പം (size_t) - 1))

/* ------------------------------------------------------------------------- */

സ്ഥിതം TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(വലുപ്പം(TinyAlloc) - വലുപ്പം (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#എങ്കിൽ TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    തിരികെ al;
}

സ്ഥിതം ശൂന്യം tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#എങ്കിൽ TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#എങ്കിൽ TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#എങ്കിൽ TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    എങ്കിൽ (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        ആകുമ്പോൾ (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            എങ്കിൽ (header->വരി_അക്കം > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->വരി_അക്കം, (പൂർണ്ണസംഖ്യ)header->size);
            }
            p += header->size + വലുപ്പം(tal_header_t);
        }
#എങ്കിൽ TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    എങ്കിൽ (al)
        പോകുക tail_call;
    *pal = al;
}

സ്ഥിതം ശൂന്യം tal_free_impl(TinyAlloc **pal, ശൂന്യം *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **മുകൾ = pal;
    tal_header_t *header;

    എങ്കിൽ (!p)
        തിരികെ;
    header = (tal_header_t *)p - 1;
#എങ്കിൽ TAL_DEBUG
    എങ്കിൽ (header->വരി_അക്കം < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (പൂർണ്ണസംഖ്യ)-header->വരി_അക്കം, (പൂർണ്ണസംഖ്യ)header->size);
    } അല്ലെങ്കിൽ
        header->വരി_അക്കം = -header->വരി_അക്കം;
#endif
    al = *pal;
    ആകുമ്പോൾ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    എങ്കിൽ (0 == --al->nb_allocs) {
        *pal = al->next;
        എങ്കിൽ ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } അല്ലെങ്കിൽ {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *മുകൾ, *മുകൾ = al;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

സ്ഥിതം ശൂന്യം *tal_realloc_impl(TinyAlloc **pal, ശൂന്യം *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    ശൂന്യം *ret;
    unsigned adj_size = TAL_ALIGN(size) + വലുപ്പം(tal_header_t);
    TinyAlloc *al = *pal;

    എങ്കിൽ (p) {
        /* reallpc case */
        ആകുമ്പോൾ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        എങ്കിൽ ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        എങ്കിൽ (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            തിരികെ ret;
        } അല്ലെങ്കിൽ എങ്കിൽ (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#എങ്കിൽ TAL_DEBUG
            header->വരി_അക്കം = -header->വരി_അക്കം;
#endif
        }
    } അല്ലെങ്കിൽ {
        /* new alloc case */
        ആകുമ്പോൾ (al->p + adj_size > al->bufend) {
            al = al->next;
            എങ്കിൽ (!al) {
                unsigned new_size = (*pal)->size;
                എങ്കിൽ (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                നിർത്തുക;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - വലുപ്പം(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#എങ്കിൽ  TAL_DEBUG
    {
        പൂർണ്ണസംഖ്യ ofs = strlen(sfile) + 1 - വലുപ്പം header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->വരി_അക്കം = sline;
#എങ്കിൽ TAL_INFO
        എങ്കിൽ (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        എങ്കിൽ (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    തിരികെ ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
സ്ഥിതം ശൂന്യം cstr_realloc(CString *cstr, പൂർണ്ണസംഖ്യ new_size)
{
    പൂർണ്ണസംഖ്യ size;

    size = cstr->size_allocated;
    എങ്കിൽ (size < 8)
        size = 8; /* no need to allocate a too small first string */
    ആകുമ്പോൾ (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN ശൂന്യം cstr_ccat(CString *cstr, പൂർണ്ണസംഖ്യ ch)
{
    പൂർണ്ണസംഖ്യ size;
    size = cstr->size + 1;
    എങ്കിൽ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN അക്ഷരം *unicode_to_utf8 (അക്ഷരം *b, uint32_t Uc)
{
    എങ്കിൽ (Uc<0x80) *b++=Uc;
    അല്ലെങ്കിൽ എങ്കിൽ (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    അല്ലെങ്കിൽ എങ്കിൽ (Uc-0xd800u<0x800) പോകുക error;
    അല്ലെങ്കിൽ എങ്കിൽ (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    അല്ലെങ്കിൽ എങ്കിൽ (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    അല്ലെങ്കിൽ error: tcc_error("0x%x is not a valid universal character", Uc);
    തിരികെ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN ശൂന്യം cstr_u8cat(CString *cstr, പൂർണ്ണസംഖ്യ ch)
{
    അക്ഷരം buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC ശൂന്യം cstr_cat(CString *cstr, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len)
{
    പൂർണ്ണസംഖ്യ size;
    എങ്കിൽ (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    എങ്കിൽ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC ശൂന്യം cstr_wccat(CString *cstr, പൂർണ്ണസംഖ്യ ch)
{
    പൂർണ്ണസംഖ്യ size;
    size = cstr->size + വലുപ്പം(nwchar_t);
    എങ്കിൽ (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - വലുപ്പം(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC ശൂന്യം cstr_new(CString *cstr)
{
    memset(cstr, 0, വലുപ്പം(CString));
}

/* free string and reset it to NULL */
ST_FUNC ശൂന്യം cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC ശൂന്യം cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC പൂർണ്ണസംഖ്യ cstr_vprintf(CString *cstr, സ്ഥിരം അക്ഷരം *fmt, va_list ap)
{
    va_list v;
    പൂർണ്ണസംഖ്യ len, size = 80;
    വേണ്ടി (;;) {
        size += cstr->size;
        എങ്കിൽ (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        എങ്കിൽ (len >= 0 && len < size)
            നിർത്തുക;
        size *= 2;
    }
    cstr->size += len;
    തിരികെ len;
}

ST_FUNC പൂർണ്ണസംഖ്യ cstr_printf(CString *cstr, സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap; പൂർണ്ണസംഖ്യ len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    തിരികെ len;
}

/* XXX: unicode ? */
സ്ഥിതം ശൂന്യം add_char(CString *cstr, പൂർണ്ണസംഖ്യ c)
{
    എങ്കിൽ (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    എങ്കിൽ (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } അല്ലെങ്കിൽ {
        cstr_ccat(cstr, '\\');
        എങ്കിൽ (c == '\n') {
            cstr_ccat(cstr, 'n');
        } അല്ലെങ്കിൽ {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
സ്ഥിതം TokenSym *tok_alloc_new(TokenSym **pts, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len)
{
    TokenSym *ts, **ptable;
    പൂർണ്ണസംഖ്യ i;

    എങ്കിൽ (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    എങ്കിൽ ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * വലുപ്പം(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, വലുപ്പം(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ശൂന്യ;
    ts->sym_label = ശൂന്യ;
    ts->sym_struct = ശൂന്യ;
    ts->sym_identifier = ശൂന്യ;
    ts->len = len;
    ts->hash_next = ശൂന്യ;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    തിരികെ ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ len)
{
    TokenSym *ts, **pts;
    പൂർണ്ണസംഖ്യ i;
    unsigned പൂർണ്ണസംഖ്യ h;
    
    h = TOK_HASH_INIT;
    വേണ്ടി(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned അക്ഷരം *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    വേണ്ടി(;;) {
        ts = *pts;
        എങ്കിൽ (!ts)
            നിർത്തുക;
        എങ്കിൽ (ts->len == len && !memcmp(ts->str, str, len))
            തിരികെ ts;
        pts = &(ts->hash_next);
    }
    തിരികെ tok_alloc_new(pts, str, len);
}

ST_FUNC പൂർണ്ണസംഖ്യ tok_alloc_const(സ്ഥിരം അക്ഷരം *str)
{
    തിരികെ tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC സ്ഥിരം അക്ഷരം *get_tok_str(പൂർണ്ണസംഖ്യ v, CValue *cv)
{
    അക്ഷരം *p;
    പൂർണ്ണസംഖ്യ i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    തിരഞ്ഞെടുപ്പ്(v) {
    അവസ്ഥ TOK_CINT:
    അവസ്ഥ TOK_CUINT:
    അവസ്ഥ TOK_CLONG:
    അവസ്ഥ TOK_CULONG:
    അവസ്ഥ TOK_CLLONG:
    അവസ്ഥ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        നിർത്തുക;
    അവസ്ഥ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    അവസ്ഥ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        നിർത്തുക;
    അവസ്ഥ TOK_PPNUM:
    അവസ്ഥ TOK_PPSTR:
        തിരികെ (അക്ഷരം*)cv->str.data;
    അവസ്ഥ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    അവസ്ഥ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        എങ്കിൽ (v == TOK_STR) {
            len = cv->str.size - 1;
            വേണ്ടി(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned അക്ഷരം *)cv->str.data)[i]);
        } അല്ലെങ്കിൽ {
            len = (cv->str.size / വലുപ്പം(nwchar_t)) - 1;
            വേണ്ടി(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        നിർത്തുക;

    അവസ്ഥ TOK_CFLOAT:
        തിരികെ strcpy(p, "<float>");
    അവസ്ഥ TOK_CDOUBLE:
        തിരികെ strcpy(p, "<double>");
    അവസ്ഥ TOK_CLDOUBLE:
        തിരികെ strcpy(p, "<long double>");
    അവസ്ഥ TOK_LINENUM:
        തിരികെ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    അവസ്ഥ TOK_LT:
        v = '<';
        പോകുക addv;
    അവസ്ഥ TOK_GT:
        v = '>';
        പോകുക addv;
    അവസ്ഥ TOK_DOTS:
        തിരികെ strcpy(p, "...");
    അവസ്ഥ TOK_A_SHL:
        തിരികെ strcpy(p, "<<=");
    അവസ്ഥ TOK_A_SAR:
        തിരികെ strcpy(p, ">>=");
    അവസ്ഥ TOK_EOF:
        തിരികെ strcpy(p, "<eof>");
    അവസ്ഥ 0: /* anonymous nameless symbols */
        തിരികെ strcpy(p, "<no name>");
    സ്ഥിരസ്ഥിതി:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        എങ്കിൽ (v < TOK_IDENT) {
            /* search in two bytes table */
            സ്ഥിരം unsigned അക്ഷരം *q = tok_two_chars;
            ആകുമ്പോൾ (*q) {
                എങ്കിൽ (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    തിരികെ cstr_buf.data;
                }
                q += 3;
            }
            എങ്കിൽ (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                നിർത്തുക;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } അല്ലെങ്കിൽ എങ്കിൽ (v < tok_ident) {
            തിരികെ table_ident[v - TOK_IDENT]->str;
        } അല്ലെങ്കിൽ എങ്കിൽ (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } അല്ലെങ്കിൽ {
            /* should never happen */
            തിരികെ ശൂന്യ;
        }
        നിർത്തുക;
    }
    തിരികെ cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
സ്ഥിതം പൂർണ്ണസംഖ്യ handle_eob(ശൂന്യം)
{
    BufferedFile *bf = file;
    പൂർണ്ണസംഖ്യ len;

    /* only tries to read if really end of buffer */
    എങ്കിൽ (bf->buf_ptr >= bf->buf_end) {
        എങ്കിൽ (bf->fd >= 0) {
#എങ്കിൽ defined(PARSE_DEBUG)
            len = 1;
#അല്ലെങ്കിൽ
            len = IO_BUF_SIZE;
#endif
            len = പഠ(bf->fd, bf->buffer, len);
            എങ്കിൽ (len < 0)
                len = 0;
        } അല്ലെങ്കിൽ {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    എങ്കിൽ (bf->buf_ptr < bf->buf_end) {
        തിരികെ bf->buf_ptr[0];
    } അല്ലെങ്കിൽ {
        bf->buf_ptr = bf->buf_end;
        തിരികെ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
സ്ഥിതം പൂർണ്ണസംഖ്യ next_c(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    എങ്കിൽ (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    തിരികെ ch;
}

/* input with '\[\r]\n' handling. */
സ്ഥിതം പൂർണ്ണസംഖ്യ handle_stray_noerror(പൂർണ്ണസംഖ്യ err)
{
    പൂർണ്ണസംഖ്യ ch;
    ആകുമ്പോൾ ((ch = next_c()) == '\\') {
        ch = next_c();
        എങ്കിൽ (ch == '\n') {
    newl:
            file->വരി_അക്കം++;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (ch == '\r') {
                ch = next_c();
                എങ്കിൽ (ch == '\n')
                    പോകുക newl;
                *--file->buf_ptr = '\r';
            }
            എങ്കിൽ (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            തിരികെ *--file->buf_ptr = '\\';
        }
    }
    തിരികെ ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
സ്ഥിതം പൂർണ്ണസംഖ്യ handle_bs(uint8_t **p)
{
    പൂർണ്ണസംഖ്യ c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    തിരികെ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
സ്ഥിതം പൂർണ്ണസംഖ്യ handle_stray(uint8_t **p)
{
    പൂർണ്ണസംഖ്യ c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    തിരികെ c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    എങ്കിൽ (c == '\\')\
        c = handle_stray(&p); \
}

സ്ഥിതം പൂർണ്ണസംഖ്യ skip_spaces(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ ch;
    --file->buf_ptr;
    ചെയ്യുക {
        ch = ninp();
    } ആകുമ്പോൾ (isidnum_table[ch - CH_EOF] & IS_SPC);
    തിരികെ ch;
}

/* single line C++ comments */
സ്ഥിതം uint8_t *parse_വരി_comment(uint8_t *p)
{
    പൂർണ്ണസംഖ്യ c;
    വേണ്ടി(;;) {
        വേണ്ടി (;;) {
            c = *++p;
    redo:
            എങ്കിൽ (c == '\n' || c == '\\')
                നിർത്തുക;
            c = *++p;
            എങ്കിൽ (c == '\n' || c == '\\')
                നിർത്തുക;
        }
        എങ്കിൽ (c == '\n')
            നിർത്തുക;
        c = handle_bs(&p);
        എങ്കിൽ (c == CH_EOF)
            നിർത്തുക;
        എങ്കിൽ (c != '\\')
            പോകുക redo;
    }
    തിരികെ p;
}

/* C comments */
സ്ഥിതം uint8_t *parse_comment(uint8_t *p)
{
    പൂർണ്ണസംഖ്യ c;
    വേണ്ടി(;;) {
        /* fast skip loop */
        വേണ്ടി(;;) {
            c = *++p;
        redo:
            എങ്കിൽ (c == '\n' || c == '*' || c == '\\')
                നിർത്തുക;
            c = *++p;
            എങ്കിൽ (c == '\n' || c == '*' || c == '\\')
                നിർത്തുക;
        }
        /* now we can handle all the cases */
        എങ്കിൽ (c == '\n') {
            file->വരി_അക്കം++;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '*') {
            ചെയ്യുക {
                c = *++p;
            } ആകുമ്പോൾ (c == '*');
            എങ്കിൽ (c == '\\')
                c = handle_bs(&p);
            എങ്കിൽ (c == '/')
                നിർത്തുക;
            പോകുക check_eof;
        } അല്ലെങ്കിൽ {
            c = handle_bs(&p);
        check_eof:
            എങ്കിൽ (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            എങ്കിൽ (c != '\\')
                പോകുക redo;
        }
    }
    തിരികെ p + 1;
}

/* parse a string without interpreting escapes */
സ്ഥിതം uint8_t *parse_pp_string(uint8_t *p, പൂർണ്ണസംഖ്യ sep, CString *str)
{
    പൂർണ്ണസംഖ്യ c;
    വേണ്ടി(;;) {
        c = *++p;
    redo:
        എങ്കിൽ (c == sep) {
            നിർത്തുക;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '\\') {
            c = handle_bs(&p);
            എങ്കിൽ (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } അല്ലെങ്കിൽ എങ്കിൽ (c == '\\') {
                എങ്കിൽ (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                എങ്കിൽ (c == '\\') {
                    c = handle_bs(&p);
                    എങ്കിൽ (c == CH_EOF)
                        പോകുക unterminated_string;
                }
                പോകുക add_char;
            } അല്ലെങ്കിൽ {
                പോകുക redo;
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '\n') {
        add_lf:
            എങ്കിൽ (ACCEPT_LF_IN_STRINGS) {
                file->വരി_അക്കം++;
                പോകുക add_char;
            } അല്ലെങ്കിൽ എങ്കിൽ (str) { /* not skipping */
                പോകുക unterminated_string;
            } അല്ലെങ്കിൽ {
                //tcc_warning("missing terminating %c character", sep);
                തിരികെ p;
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '\r') {
            c = *++p;
            എങ്കിൽ (c == '\\')
                c = handle_bs(&p);
            എങ്കിൽ (c == '\n')
                പോകുക add_lf;
            എങ്കിൽ (c == CH_EOF)
                പോകുക unterminated_string;
            എങ്കിൽ (str)
                cstr_ccat(str, '\r');
            പോകുക redo;
        } അല്ലെങ്കിൽ {
        add_char:
            എങ്കിൽ (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    തിരികെ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
സ്ഥിതം ശൂന്യം preprocess_skip(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a, start_of_വരി, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_വരി = 1;
    in_warn_or_error = 0;
    വേണ്ടി(;;) {
        c = *p;
        തിരഞ്ഞെടുപ്പ്(c) {
        അവസ്ഥ ' ':
        അവസ്ഥ '\t':
        അവസ്ഥ '\f':
        അവസ്ഥ '\v':
        അവസ്ഥ '\r':
            p++;
            തുടരുക;
        അവസ്ഥ '\n':
            file->വരി_അക്കം++;
            p++;
            പോകുക redo_start;
        അവസ്ഥ '\\':
            c = handle_bs(&p);
            എങ്കിൽ (c == CH_EOF)
                expect("#endif");
            എങ്കിൽ (c == '\\')
                ++p;
            തുടരുക;
        /* skip strings */
        അവസ്ഥ '\"':
        അവസ്ഥ '\'':
            എങ്കിൽ (in_warn_or_error)
                പോകുക _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ശൂന്യ);
            നിർത്തുക;
        /* skip comments */
        അവസ്ഥ '/':
            എങ്കിൽ (in_warn_or_error)
                പോകുക _default;
            ++p;
            c = handle_bs(&p);
            എങ്കിൽ (c == '*') {
                p = parse_comment(p);
            } അല്ലെങ്കിൽ എങ്കിൽ (c == '/') {
                p = parse_വരി_comment(p);
            }
            തുടരുക;
        അവസ്ഥ '#':
            p++;
            എങ്കിൽ (start_of_വരി) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                എങ്കിൽ (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    പോകുക the_end;
                എങ്കിൽ (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_ENDIF)
                    a--;
                അല്ലെങ്കിൽ എങ്കിൽ( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_LINEFEED)
                    പോകുക redo_start;
                അല്ലെങ്കിൽ എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_വരി_comment(p - 1);
            }
#എങ്കിൽ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            അല്ലെങ്കിൽ എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_വരി_comment(p - 1);
#അല്ലെങ്കിൽ
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            നിർത്തുക;
_default:
        സ്ഥിരസ്ഥിതി:
            p++;
            നിർത്തുക;
        }
        start_of_വരി = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#എങ്കിൽ 0
/* return the number of additional 'ints' necessary to store the
   token */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ tok_size(സ്ഥിരം പൂർണ്ണസംഖ്യ *p)
{
    തിരഞ്ഞെടുപ്പ്(*p) {
        /* 4 bytes */
    അവസ്ഥ TOK_CINT:
    അവസ്ഥ TOK_CUINT:
    അവസ്ഥ TOK_CCHAR:
    അവസ്ഥ TOK_LCHAR:
    അവസ്ഥ TOK_CFLOAT:
    അവസ്ഥ TOK_LINENUM:
        തിരികെ 1 + 1;
    അവസ്ഥ TOK_STR:
    അവസ്ഥ TOK_LSTR:
    അവസ്ഥ TOK_PPNUM:
    അവസ്ഥ TOK_PPSTR:
        തിരികെ 1 + 1 + (p[1] + 3) / 4;
    അവസ്ഥ TOK_CLONG:
    അവസ്ഥ TOK_CULONG:
	തിരികെ 1 + LONG_SIZE / 4;
    അവസ്ഥ TOK_CDOUBLE:
    അവസ്ഥ TOK_CLLONG:
    അവസ്ഥ TOK_CULLONG:
        തിരികെ 1 + 2;
    അവസ്ഥ TOK_CLDOUBLE:
        തിരികെ 1 + LDOUBLE_വാക്കുകൾ;
    സ്ഥിരസ്ഥിതി:
        തിരികെ 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN ശൂന്യം tok_str_new(TokenString *s)
{
    s->str = ശൂന്യ;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_വരി_അക്കം = -1;
}

ST_FUNC TokenString *tok_str_alloc(ശൂന്യം)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, വലുപ്പം *str);
    tok_str_new(str);
    തിരികെ str;
}

ST_FUNC ശൂന്യം tok_str_free_str(പൂർണ്ണസംഖ്യ *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ശൂന്യം tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC പൂർണ്ണസംഖ്യ *tok_str_realloc(TokenString *s, പൂർണ്ണസംഖ്യ new_size)
{
    പൂർണ്ണസംഖ്യ *str, size;

    size = s->allocated_len;
    എങ്കിൽ (size < 16)
        size = 16;
    ആകുമ്പോൾ (size < new_size)
        size = size * 2;
    എങ്കിൽ (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * വലുപ്പം(പൂർണ്ണസംഖ്യ));
        s->allocated_len = size;
        s->str = str;
    }
    തിരികെ s->str;
}

ST_FUNC ശൂന്യം tok_str_add(TokenString *s, പൂർണ്ണസംഖ്യ t)
{
    പൂർണ്ണസംഖ്യ len, *str;

    len = s->len;
    str = s->str;
    എങ്കിൽ (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC ശൂന്യം begin_macro(TokenString *str, പൂർണ്ണസംഖ്യ alloc)
{
    str->alloc = alloc;
    str->prev = macro_അട്ടി;
    str->prev_ptr = macro_ptr;
    str->save_വരി_അക്കം = file->വരി_അക്കം;
    macro_ptr = str->str;
    macro_അട്ടി = str;
}

ST_FUNC ശൂന്യം end_macro(ശൂന്യം)
{
    TokenString *str = macro_അട്ടി;
    macro_അട്ടി = str->prev;
    macro_ptr = str->prev_ptr;
    file->വരി_അക്കം = str->save_വരി_അക്കം;
    എങ്കിൽ (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (str->alloc == 2)
            str->str = ശൂന്യ; /* don't free */
        tok_str_free(str);
    }
}

സ്ഥിതം ശൂന്യം tok_str_add2(TokenString *s, പൂർണ്ണസംഖ്യ t, CValue *cv)
{
    പൂർണ്ണസംഖ്യ len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    എങ്കിൽ (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    തിരഞ്ഞെടുപ്പ്(t) {
    അവസ്ഥ TOK_CINT:
    അവസ്ഥ TOK_CUINT:
    അവസ്ഥ TOK_CCHAR:
    അവസ്ഥ TOK_LCHAR:
    അവസ്ഥ TOK_CFLOAT:
    അവസ്ഥ TOK_LINENUM:
#എങ്കിൽ LONG_SIZE == 4
    അവസ്ഥ TOK_CLONG:
    അവസ്ഥ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        നിർത്തുക;
    അവസ്ഥ TOK_PPNUM:
    അവസ്ഥ TOK_PPSTR:
    അവസ്ഥ TOK_STR:
    അവസ്ഥ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_വാക്കുകൾ =
                1 + (cv->str.size + വലുപ്പം(പൂർണ്ണസംഖ്യ) - 1) / വലുപ്പം(പൂർണ്ണസംഖ്യ);
            എങ്കിൽ (len + nb_വാക്കുകൾ >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_വാക്കുകൾ + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_വാക്കുകൾ;
        }
        നിർത്തുക;
    അവസ്ഥ TOK_CDOUBLE:
    അവസ്ഥ TOK_CLLONG:
    അവസ്ഥ TOK_CULLONG:
#എങ്കിൽ LONG_SIZE == 8
    അവസ്ഥ TOK_CLONG:
    അവസ്ഥ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        നിർത്തുക;
    അവസ്ഥ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        എങ്കിൽ (LDOUBLE_വാക്കുകൾ >= 3)
        str[len++] = cv->tab[2];
        എങ്കിൽ (LDOUBLE_വാക്കുകൾ >= 4)
        str[len++] = cv->tab[3];
    സ്ഥിരസ്ഥിതി:
        നിർത്തുക;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC ശൂന്യം tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    എങ്കിൽ (file->വരി_അക്കം != s->last_വരി_അക്കം) {
        s->last_വരി_അക്കം = file->വരി_അക്കം;
        cval.i = s->last_വരി_അക്കം;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
സ്ഥിതം ശൂന്യം tok_str_add2_spc(TokenString *s, പൂർണ്ണസംഖ്യ t, CValue *cv)
{
    എങ്കിൽ (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
സ്ഥിതം വരിയിൽ ശൂന്യം tok_get(പൂർണ്ണസംഖ്യ *t, സ്ഥിരം പൂർണ്ണസംഖ്യ **pp, CValue *cv)
{
    സ്ഥിരം പൂർണ്ണസംഖ്യ *p = *pp;
    പൂർണ്ണസംഖ്യ n, *tab;

    tab = cv->tab;
    തിരഞ്ഞെടുപ്പ്(*t = *p++) {
#എങ്കിൽ LONG_SIZE == 4
    അവസ്ഥ TOK_CLONG:
#endif
    അവസ്ഥ TOK_CINT:
    അവസ്ഥ TOK_CCHAR:
    അവസ്ഥ TOK_LCHAR:
    അവസ്ഥ TOK_LINENUM:
        cv->i = *p++;
        നിർത്തുക;
#എങ്കിൽ LONG_SIZE == 4
    അവസ്ഥ TOK_CULONG:
#endif
    അവസ്ഥ TOK_CUINT:
        cv->i = (unsigned)*p++;
        നിർത്തുക;
    അവസ്ഥ TOK_CFLOAT:
	tab[0] = *p++;
	നിർത്തുക;
    അവസ്ഥ TOK_STR:
    അവസ്ഥ TOK_LSTR:
    അവസ്ഥ TOK_PPNUM:
    അവസ്ഥ TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (അക്ഷരം*)p;
        p += (cv->str.size + വലുപ്പം(പൂർണ്ണസംഖ്യ) - 1) / വലുപ്പം(പൂർണ്ണസംഖ്യ);
        നിർത്തുക;
    അവസ്ഥ TOK_CDOUBLE:
    അവസ്ഥ TOK_CLLONG:
    അവസ്ഥ TOK_CULLONG:
#എങ്കിൽ LONG_SIZE == 8
    അവസ്ഥ TOK_CLONG:
    അവസ്ഥ TOK_CULONG:
#endif
        n = 2;
        പോകുക copy;
    അവസ്ഥ TOK_CLDOUBLE:
        n = LDOUBLE_വാക്കുകൾ;
    copy:
        ചെയ്യുക
            *tab++ = *p++;
        ആകുമ്പോൾ (--n);
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        നിർത്തുക;
    }
    *pp = p;
}

#എങ്കിൽ 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#അല്ലെങ്കിൽ
# define TOK_GET(t,p,c) ചെയ്യുക { \
    പൂർണ്ണസംഖ്യ _t = **(p); \
    എങ്കിൽ (TOK_HAS_മൂല്യം(_t)) \
        tok_get(t, p, c); \
    അല്ലെങ്കിൽ \
        *(t) = _t, ++*(p); \
    } ആകുമ്പോൾ (0)
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ macro_is_equal(സ്ഥിരം പൂർണ്ണസംഖ്യ *a, സ്ഥിരം പൂർണ്ണസംഖ്യ *b)
{
    CValue cv;
    പൂർണ്ണസംഖ്യ t;

    എങ്കിൽ (!a || !b)
        തിരികെ 1;

    ആകുമ്പോൾ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        എങ്കിൽ (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            തിരികെ 0;
    }
    തിരികെ !(*a || *b);
}

/* defines handling */
ST_INLN ശൂന്യം define_തള്ളുക(പൂർണ്ണസംഖ്യ v, പൂർണ്ണസംഖ്യ macro_type, പൂർണ്ണസംഖ്യ *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_അട്ടി, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    എങ്കിൽ (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ശൂന്യ));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC ശൂന്യം define_undef(Sym *s)
{
    പൂർണ്ണസംഖ്യ v = s->v;
    എങ്കിൽ (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = ശൂന്യ;
}

ST_INLN Sym *define_find(പൂർണ്ണസംഖ്യ v)
{
    v -= TOK_IDENT;
    എങ്കിൽ ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        തിരികെ ശൂന്യ;
    തിരികെ table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC ശൂന്യം free_defines(Sym *b)
{
    ആകുമ്പോൾ (define_അട്ടി != b) {
        Sym *മുകൾ = define_അട്ടി;
        define_അട്ടി = മുകൾ->prev;
        tok_str_free_str(മുകൾ->d);
        define_undef(മുകൾ);
        sym_free(മുകൾ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
സ്ഥിതം ശൂന്യം maybe_run_test(TCCState *s)
{
    സ്ഥിരം അക്ഷരം *p;
    എങ്കിൽ (s->include_അട്ടി_ptr != s->include_അട്ടി)
        തിരികെ;
    p = get_tok_str(tok, ശൂന്യ);
    എങ്കിൽ (0 != memcmp(p, "test_", 5))
        തിരികെ;
    എങ്കിൽ (0 != --s->run_test)
        തിരികെ;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_തള്ളുക(tok, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
}

ST_FUNC ശൂന്യം skip_to_eol(പൂർണ്ണസംഖ്യ warn)
{
    എങ്കിൽ (tok == TOK_LINEFEED)
        തിരികെ;
    എങ്കിൽ (warn)
        tcc_warning("extra tokens after directive");
    ആകുമ്പോൾ (macro_അട്ടി)
        end_macro();
    file->buf_ptr = parse_വരി_comment(file->buf_ptr - 1);
    next_nomacro();
}

സ്ഥിതം CachedInclude *
തിരയൽ_cached_include(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ add);

സ്ഥിതം പൂർണ്ണസംഖ്യ parse_include(TCCState *s1, പൂർണ്ണസംഖ്യ do_next, പൂർണ്ണസംഖ്യ test)
{
    പൂർണ്ണസംഖ്യ c, i;
    അക്ഷരം name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    എങ്കിൽ (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, വലുപ്പം name, tokcstr.data, i);
        next_nomacro();
    } അല്ലെങ്കിൽ {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        വേണ്ടി (;;) {
            next();
            p = name, i = strlen(p) - 1;
            എങ്കിൽ (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                നിർത്തുക;
            എങ്കിൽ (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, വലുപ്പം name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    എങ്കിൽ (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    വേണ്ടി (;;) {
        ++i;
        എങ്കിൽ (i == 0) {
            /* check absolute include path */
            എങ്കിൽ (!IS_ABSPATH(name))
                തുടരുക;
            buf[0] = '\0';
        } അല്ലെങ്കിൽ എങ്കിൽ (i == 1) {
            /* search in file's dir if "header.h" */
            എങ്കിൽ (c != '\"')
                തുടരുക;
            p = file->true_filename;
            pstrncpy(buf, വലുപ്പം buf, p, tcc_basename(p) - p);
        } അല്ലെങ്കിൽ {
            പൂർണ്ണസംഖ്യ j = i - 2, k = j - s1->nb_include_paths;
            എങ്കിൽ (k < 0)
                p = s1->include_paths[j];
            അല്ലെങ്കിൽ എങ്കിൽ (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            അല്ലെങ്കിൽ എങ്കിൽ (test)
                തിരികെ 0;
            അല്ലെങ്കിൽ
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, വലുപ്പം buf, p);
            pstrcat(buf, വലുപ്പം buf, "/");
        }
        pstrcat(buf, വലുപ്പം buf, name);
        e = തിരയൽ_cached_include(s1, buf, 0);
        എങ്കിൽ (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            എങ്കിൽ ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (പൂർണ്ണസംഖ്യ)(s1->include_അട്ടി_ptr - s1->include_അട്ടി), "", buf);
            തിരികെ 1;
        }
        എങ്കിൽ (tcc_open(s1, buf) >= 0)
            നിർത്തുക;
    }

    എങ്കിൽ (test) {
        tcc_close();
    } അല്ലെങ്കിൽ {
        എങ്കിൽ (s1->include_അട്ടി_ptr >= s1->include_അട്ടി + INCLUDE_അട്ടി_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_അട്ടി_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        എങ്കിൽ (s1->gen_deps) {
            BufferedFile *bf = file;
            ആകുമ്പോൾ (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            എങ്കിൽ (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    തിരികെ 1;
}

/* eval an expression for #if/#elif */
സ്ഥിതം പൂർണ്ണസംഖ്യ വ്യഞ്ജകം_preprocess(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ c, t;
    പൂർണ്ണസംഖ്യ t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_വ്യഞ്ജകം = 1;
    ആകുമ്പോൾ (1) {
        next(); /* do macro subst */
        t = tok;
        എങ്കിൽ (tok < TOK_IDENT) {
            എങ്കിൽ (tok == TOK_LINEFEED || tok == TOK_EOF)
                നിർത്തുക;
            എങ്കിൽ (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            എങ്കിൽ (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            എങ്കിൽ (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            എങ്കിൽ (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            എങ്കിൽ (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            എങ്കിൽ (t == '(') {
                next();
                എങ്കിൽ (tok != ')')
                    expect("')'");
            }
            പോകുക c_സംഖ്യ;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    എങ്കിൽ (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            എങ്കിൽ (tok != ')')
                expect("')'");
            പോകുക c_സംഖ്യ;
        } അല്ലെങ്കിൽ {
            /* if undefined macro, replace with zero */
            c = 0;
        c_സംഖ്യ:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    എങ്കിൽ (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_വ്യഞ്ജകം = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = വ്യഞ്ജകം_const();
    എങ്കിൽ (tok != TOK_EOF)
        tcc_error("...");
    pp_വ്യഞ്ജകം = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    തിരികെ c != 0;
}

ST_FUNC ശൂന്യം pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_വ്യഞ്ജകം, 0));
    macro_ptr = macro_അട്ടി->str;
    ആകുമ്പോൾ (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC ശൂന്യം parse_define(ശൂന്യം)
{
    Sym *s, *first, **ps;
    പൂർണ്ണസംഖ്യ v, t, varg, is_vaargs, t0;
    പൂർണ്ണസംഖ്യ saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    എങ്കിൽ (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = ശൂന്യ;
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
    എങ്കിൽ (tok == '(') {
        പൂർണ്ണസംഖ്യ dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        എങ്കിൽ (tok != ')') വേണ്ടി (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            എങ്കിൽ (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            എങ്കിൽ (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_അട്ടി, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            എങ്കിൽ (tok == ')')
                നിർത്തുക;
            എങ്കിൽ (tok != ',' || is_vaargs)
                പോകുക bad_list;
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
    ആകുമ്പോൾ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        എങ്കിൽ (is_space(tok)) {
            str.need_spc |= 1;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (TOK_TWOSHARPS == tok) {
                എങ്കിൽ (0 == t0)
                    പോകുക bad_twosharp;
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
    എങ്കിൽ (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_തള്ളുക(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

സ്ഥിതം CachedInclude *തിരയൽ_cached_include(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ add)
{
    സ്ഥിരം അക്ഷരം *s, *basename;
    unsigned പൂർണ്ണസംഖ്യ h;
    CachedInclude *e;
    പൂർണ്ണസംഖ്യ c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ആകുമ്പോൾ ((c = (unsigned അക്ഷരം)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#അല്ലെങ്കിൽ
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    വേണ്ടി(;;) {
        എങ്കിൽ (i == 0)
            നിർത്തുക;
        e = s1->cached_includes[i - 1];
        എങ്കിൽ (0 == PATHCMP(filename, e->filename))
            തിരികെ e;
        എങ്കിൽ (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            തിരികെ e;
        i = e->hash_next;
    }
    എങ്കിൽ (!add)
        തിരികെ ശൂന്യ;

    e = tcc_malloc(വലുപ്പം(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    തിരികെ e;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ pragma_parse(TCCState *s1)
{
    next_nomacro();
    എങ്കിൽ (tok == TOK_തള്ളുക_macro || tok == TOK_എടുക്കുക_macro) {
        പൂർണ്ണസംഖ്യ t = tok, v;
        Sym *s;

        എങ്കിൽ (next(), tok != '(')
            പോകുക pragma_err;
        എങ്കിൽ (next(), tok != TOK_STR)
            പോകുക pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        എങ്കിൽ (next(), tok != ')')
            പോകുക pragma_err;
        എങ്കിൽ (t == TOK_തള്ളുക_macro) {
            ആകുമ്പോൾ (ശൂന്യ == (s = define_find(v)))
                define_തള്ളുക(v, 0, ശൂന്യ, ശൂന്യ);
            s->type.ref = s; /* set push boundary */
        } അല്ലെങ്കിൽ {
            വേണ്ടി (s = define_അട്ടി; s; s = s->prev)
                എങ്കിൽ (s->v == v && s->type.ref == s) {
                    s->type.ref = ശൂന്യ;
                    നിർത്തുക;
                }
        }
        എങ്കിൽ (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : ശൂന്യ;
        അല്ലെങ്കിൽ
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_once) {
        തിരയൽ_cached_include(s1, file->true_filename, 1)->once = 1;

    } അല്ലെങ്കിൽ എങ്കിൽ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        തിരികെ 1;

    } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        എങ്കിൽ (tok == TOK_ASM_എടുക്കുക) {
            next();
            എങ്കിൽ (s1->pack_അട്ടി_ptr <= s1->pack_അട്ടി) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_അട്ടി_ptr--;
        } അല്ലെങ്കിൽ {
            പൂർണ്ണസംഖ്യ val = 0;
            എങ്കിൽ (tok != ')') {
                എങ്കിൽ (tok == TOK_ASM_തള്ളുക) {
                    next();
                    എങ്കിൽ (s1->pack_അട്ടി_ptr >= s1->pack_അട്ടി + PACK_അട്ടി_SIZE - 1)
                        പോകുക stk_error;
                    val = *s1->pack_അട്ടി_ptr++;
                    എങ്കിൽ (tok != ',')
                        പോകുക pack_set;
                    next();
                }
                എങ്കിൽ (tok != TOK_CINT)
                    പോകുക pragma_err;
                val = tokc.i;
                എങ്കിൽ (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    പോകുക pragma_err;
                next();
            }
        pack_set:
            *s1->pack_അട്ടി_ptr = val;
        }
        എങ്കിൽ (tok != ')')
            പോകുക pragma_err;

    } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_comment) {
        അക്ഷരം *p; പൂർണ്ണസംഖ്യ t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        എങ്കിൽ (tok != TOK_STR)
            പോകുക pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        എങ്കിൽ (tok != ')')
            പോകുക pragma_err;
        എങ്കിൽ (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } അല്ലെങ്കിൽ {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        തിരികെ 0;
    }
    next();
    തിരികെ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC ശൂന്യം tccpp_putfile(സ്ഥിരം അക്ഷരം *filename)
{
    അക്ഷരം buf[1024];
    buf[0] = 0;
    എങ്കിൽ (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, വലുപ്പം buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, വലുപ്പം buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    എങ്കിൽ (0 == strcmp(file->filename, buf))
        തിരികെ;
    //printf("new file '%s'\n", buf);
    എങ്കിൽ (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, വലുപ്പം file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC ശൂന്യം preprocess(പൂർണ്ണസംഖ്യ is_bof)
{
    TCCState *s1 = tcc_state;
    പൂർണ്ണസംഖ്യ c, n, saved_parse_flags;
    അക്ഷരം buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_അക്കം
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    തിരഞ്ഞെടുപ്പ്(tok) {
    അവസ്ഥ TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        നിർത്തുക;
    അവസ്ഥ TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        എങ്കിൽ (s)
            define_undef(s);
        next_nomacro();
        നിർത്തുക;
    അവസ്ഥ TOK_INCLUDE:
    അവസ്ഥ TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        പോകുക the_end;
    അവസ്ഥ TOK_IFNDEF:
        c = 1;
        പോകുക do_ifdef;
    അവസ്ഥ TOK_IF:
        c = വ്യഞ്ജകം_preprocess(s1);
        പോകുക do_if;
    അവസ്ഥ TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        എങ്കിൽ (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        എങ്കിൽ (is_bof) {
            എങ്കിൽ (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, ശൂന്യ));
#endif
                file->ifndef_macro = tok;
            }
        }
        എങ്കിൽ (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr >= s1->ifdef_അട്ടി + IFDEF_അട്ടി_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_അട്ടി_ptr++ = c;
        പോകുക test_skip;
    അവസ്ഥ TOK_ELSE:
        next_nomacro();
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr == s1->ifdef_അട്ടി)
            tcc_error("#else without matching #if");
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_അട്ടി_ptr[-1] ^= 3);
        പോകുക test_else;
    അവസ്ഥ TOK_ELIF:
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr == s1->ifdef_അട്ടി)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_അട്ടി_ptr[-1];
        എങ്കിൽ (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        എങ്കിൽ (c == 1) {
            skip_to_eol(0);
            c = 0;
        } അല്ലെങ്കിൽ {
            c = വ്യഞ്ജകം_preprocess(s1);
            s1->ifdef_അട്ടി_ptr[-1] = c;
        }
    test_else:
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr == file->ifdef_അട്ടി_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        എങ്കിൽ (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            പോകുക redo;
        }
        നിർത്തുക;
    അവസ്ഥ TOK_ENDIF:
        next_nomacro();
        എങ്കിൽ (s1->ifdef_അട്ടി_ptr <= file->ifdef_അട്ടി_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_അട്ടി_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        എങ്കിൽ (file->ifndef_macro &&
            s1->ifdef_അട്ടി_ptr == file->ifdef_അട്ടി_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        നിർത്തുക;

    അവസ്ഥ TOK_വരി:
        parse_flags &= ~PARSE_FLAG_TOK_അക്കം;
        next();
        എങ്കിൽ (tok != TOK_PPNUM) {
    വരി_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        പോകുക വരി_അക്കം_2;
    അവസ്ഥ TOK_PPNUM:
        എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE)
            പോകുക ignore;
        c = 0; /* no error with extra tokens */
    വരി_അക്കം_2:
        വേണ്ടി (n = 0, q = tokc.str.data; *q; ++q) {
            എങ്കിൽ (!isnum(*q))
                പോകുക വരി_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        എങ്കിൽ (tok != TOK_LINEFEED) {
            എങ്കിൽ (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                പോകുക വരി_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        എങ്കിൽ (file->fd > 0)
            total_വരികൾ += file->വരി_അക്കം - n;
        file->വരി_അക്കം = n;
        നിർത്തുക;

    അവസ്ഥ TOK_ERROR:
    അവസ്ഥ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ആകുമ്പോൾ (c != '\n' && c != CH_EOF) {
            എങ്കിൽ ((q - buf) < വലുപ്പം(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        എങ്കിൽ (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        അല്ലെങ്കിൽ
            tcc_warning("#warning %s", buf);
        next_nomacro();
        നിർത്തുക;
    }
    അവസ്ഥ TOK_PRAGMA:
        എങ്കിൽ (!pragma_parse(s1))
            പോകുക ignore;
        നിർത്തുക;
    അവസ്ഥ TOK_LINEFEED:
        പോകുക the_end;
    സ്ഥിരസ്ഥിതി:
        /* ignore gas line comment in an 'S' file. */
        എങ്കിൽ (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            പോകുക ignore;
        എങ്കിൽ (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            പോകുക ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        പോകുക the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
സ്ഥിതം ശൂന്യം parse_escape_string(CString *outstr, സ്ഥിരം uint8_t *buf, പൂർണ്ണസംഖ്യ is_long)
{
    പൂർണ്ണസംഖ്യ c, n, i;
    സ്ഥിരം uint8_t *p;

    p = buf;
    വേണ്ടി(;;) {
        c = *p;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        എങ്കിൽ (c == '\\') {
            p++;
            /* escape */
            c = *p;
            തിരഞ്ഞെടുപ്പ്(c) {
            അവസ്ഥ '0': അവസ്ഥ '1': അവസ്ഥ '2': അവസ്ഥ '3':
            അവസ്ഥ '4': അവസ്ഥ '5': അവസ്ഥ '6': അവസ്ഥ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                എങ്കിൽ (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    എങ്കിൽ (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                പോകുക add_char_nonext;
            അവസ്ഥ 'x': i = 0; പോകുക parse_hex_or_ucn;
            അവസ്ഥ 'u': i = 4; പോകുക parse_hex_or_ucn;
            അവസ്ഥ 'U': i = 8; പോകുക parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                ചെയ്യുക {
                    c = *p;
                    എങ്കിൽ (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    അല്ലെങ്കിൽ എങ്കിൽ (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    അല്ലെങ്കിൽ എങ്കിൽ (isnum(c))
                        c = c - '0';
                    അല്ലെങ്കിൽ എങ്കിൽ (i >= 0)
                        expect("more hex digits in universal-character-name");
                    അല്ലെങ്കിൽ
                        പോകുക add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } ആകുമ്പോൾ (--i);
		എങ്കിൽ (is_long) {
    add_hex_or_ucn:
                    c = n;
		    പോകുക add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                തുടരുക;
            അവസ്ഥ 'a':
                c = '\a';
                നിർത്തുക;
            അവസ്ഥ 'b':
                c = '\b';
                നിർത്തുക;
            അവസ്ഥ 'f':
                c = '\f';
                നിർത്തുക;
            അവസ്ഥ 'n':
                c = '\n';
                നിർത്തുക;
            അവസ്ഥ 'r':
                c = '\r';
                നിർത്തുക;
            അവസ്ഥ 't':
                c = '\t';
                നിർത്തുക;
            അവസ്ഥ 'v':
                c = '\v';
                നിർത്തുക;
            അവസ്ഥ 'e':
                എങ്കിൽ (!gnu_ext)
                    പോകുക invalid_escape;
                c = 27;
                നിർത്തുക;
            അവസ്ഥ '\'':
            അവസ്ഥ '\"':
            അവസ്ഥ '\\': 
            അവസ്ഥ '?':
                നിർത്തുക;
            സ്ഥിരസ്ഥിതി:
            invalid_escape:
                എങ്കിൽ (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                അല്ലെങ്കിൽ
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                നിർത്തുക;
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            പൂർണ്ണസംഖ്യ cont; /* count of continuation bytes */
            പൂർണ്ണസംഖ്യ skip; /* how many bytes should skip when error occurred */
            പൂർണ്ണസംഖ്യ i;

            /* decode leading byte */
            എങ്കിൽ (c < 0xC2) {
	            skip = 1; പോകുക invalid_utf8_sequence;
            } അല്ലെങ്കിൽ എങ്കിൽ (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } അല്ലെങ്കിൽ എങ്കിൽ (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } അല്ലെങ്കിൽ എങ്കിൽ (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } അല്ലെങ്കിൽ {
	            skip = 1; പോകുക invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            വേണ്ടി (i = 1; i <= cont; i++) {
                പൂർണ്ണസംഖ്യ l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                എങ്കിൽ (i == 1) {
                    തിരഞ്ഞെടുപ്പ് (c) {
                    അവസ്ഥ 0xE0: l = 0xA0; നിർത്തുക;
                    അവസ്ഥ 0xED: h = 0x9F; നിർത്തുക;
                    അവസ്ഥ 0xF0: l = 0x90; നിർത്തുക;
                    അവസ്ഥ 0xF4: h = 0x8F; നിർത്തുക;
                    }
                }

                എങ്കിൽ (p[i] < l || p[i] > h) {
                    skip = i; പോകുക invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            പോകുക add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            പോകുക add_char_nonext;

        }
        p++;
    add_char_nonext:
        എങ്കിൽ (!is_long)
            cstr_ccat(outstr, c);
        അല്ലെങ്കിൽ {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            എങ്കിൽ (c < 0x10000) {
                cstr_wccat(outstr, c);
            } അല്ലെങ്കിൽ {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#അല്ലെങ്കിൽ
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    എങ്കിൽ (!is_long)
        cstr_ccat(outstr, '\0');
    അല്ലെങ്കിൽ
        cstr_wccat(outstr, '\0');
}

സ്ഥിതം ശൂന്യം parse_string(സ്ഥിരം അക്ഷരം *s, പൂർണ്ണസംഖ്യ len)
{
    uint8_t buf[1000], *p = buf;
    പൂർണ്ണസംഖ്യ is_long, sep;

    എങ്കിൽ ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    എങ്കിൽ (len >= വലുപ്പം buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    എങ്കിൽ (p != buf)
        tcc_free(p);

    എങ്കിൽ (sep == '\'') {
        പൂർണ്ണസംഖ്യ char_size, i, n, c;
        /* XXX: make it portable */
        എങ്കിൽ (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        അല്ലെങ്കിൽ
            tok = TOK_LCHAR, char_size = വലുപ്പം(nwchar_t);
        n = tokcstr.size / char_size - 1;
        എങ്കിൽ (n < 1)
            tcc_error("empty character constant");
        എങ്കിൽ (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        വേണ്ടി (c = i = 0; i < n; ++i) {
            എങ്കിൽ (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            അല്ലെങ്കിൽ
                c = (c << 8) | ((അക്ഷരം *)tokcstr.data)[i];
        }
        tokc.i = c;
    } അല്ലെങ്കിൽ {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        എങ്കിൽ (!is_long)
            tok = TOK_STR;
        അല്ലെങ്കിൽ
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
സ്ഥിതം പൂർണ്ണസംഖ്യ bn_lshift(unsigned പൂർണ്ണസംഖ്യ *bn, പൂർണ്ണസംഖ്യ shift, പൂർണ്ണസംഖ്യ or_val)
{
    പൂർണ്ണസംഖ്യ i;
    unsigned പൂർണ്ണസംഖ്യ v;
    എങ്കിൽ (bn[BN_SIZE - 1] >> (32 - shift))
	തിരികെ shift;
    വേണ്ടി(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    തിരികെ 0;
}

സ്ഥിതം ശൂന്യം bn_zero(unsigned പൂർണ്ണസംഖ്യ *bn)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
സ്ഥിതം ശൂന്യം parse_സംഖ്യ(സ്ഥിരം അക്ഷരം *p)
{
    പൂർണ്ണസംഖ്യ b, t, shift, frac_bits, s, exp_val, ch;
    അക്ഷരം *q;
    unsigned പൂർണ്ണസംഖ്യ bn[BN_SIZE];
    long ഇരട്ട d;

    /*സംഖ്യ*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    എങ്കിൽ (t == '.') {
        പോകുക float_frac_parse;
    } അല്ലെങ്കിൽ എങ്കിൽ (t == '0') {
        എങ്കിൽ (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } അല്ലെങ്കിൽ എങ്കിൽ (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ആകുമ്പോൾ (1) {
        എങ്കിൽ (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        അല്ലെങ്കിൽ എങ്കിൽ (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        അല്ലെങ്കിൽ എങ്കിൽ (isnum(ch))
            t = ch - '0';
        അല്ലെങ്കിൽ
            നിർത്തുക;
        എങ്കിൽ (t >= b)
            നിർത്തുക;
        എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE) {
        അക്കം_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    എങ്കിൽ (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        എങ്കിൽ (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            എങ്കിൽ (b == 16)
                shift = 4;
            അല്ലെങ്കിൽ 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            ആകുമ്പോൾ (1) {
                t = *q++;
                എങ്കിൽ (t == '\0') {
                    നിർത്തുക;
                } അല്ലെങ്കിൽ എങ്കിൽ (t >= 'a') {
                    t = t - 'a' + 10;
                } അല്ലെങ്കിൽ എങ്കിൽ (t >= 'A') {
                    t = t - 'A' + 10;
                } അല്ലെങ്കിൽ {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            എങ്കിൽ (ch == '.') {
                ch = *p++;
                ആകുമ്പോൾ (1) {
                    t = ch;
                    എങ്കിൽ (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } അല്ലെങ്കിൽ എങ്കിൽ (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } അല്ലെങ്കിൽ എങ്കിൽ (t >= '0' && t <= '9') {
                        t = t - '0';
                    } അല്ലെങ്കിൽ {
                        നിർത്തുക;
                    }
                    എങ്കിൽ (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            എങ്കിൽ (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            എങ്കിൽ (ch == '+') {
                ch = *p++;
            } അല്ലെങ്കിൽ എങ്കിൽ (ch == '-') {
                s = -1;
                ch = *p++;
            }
            എങ്കിൽ (ch < '0' || ch > '9')
                expect("exponent digits");
            ആകുമ്പോൾ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		എങ്കിൽ (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long ഇരട്ട)bn[3] * 79228162514264337593543950336.0L +
	        (long ഇരട്ട)bn[2] * 18446744073709551616.0L +
	        (long ഇരട്ട)bn[1] * 4294967296.0L +
	        (long ഇരട്ട)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            എങ്കിൽ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ദശാംശം)d;
            } അല്ലെങ്കിൽ എങ്കിൽ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } അല്ലെങ്കിൽ {
                tok = TOK_CDOUBLE;
                tokc.d = (ഇരട്ട)d;
            }
        } അല്ലെങ്കിൽ {
            /* decimal floats */
            എങ്കിൽ (ch == '.') {
                എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE)
                    പോകുക അക്കം_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ആകുമ്പോൾ (ch >= '0' && ch <= '9') {
                    എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE)
                        പോകുക അക്കം_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            എങ്കിൽ (ch == 'e' || ch == 'E') {
                എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE)
                    പോകുക അക്കം_too_long;
                *q++ = ch;
                ch = *p++;
                എങ്കിൽ (ch == '-' || ch == '+') {
                    എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE)
                        പോകുക അക്കം_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                എങ്കിൽ (ch < '0' || ch > '9')
                    expect("exponent digits");
                ആകുമ്പോൾ (ch >= '0' && ch <= '9') {
                    എങ്കിൽ (q >= token_buf + STRING_MAX_SIZE)
                        പോകുക അക്കം_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            എങ്കിൽ (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ശൂന്യ);
            } അല്ലെങ്കിൽ എങ്കിൽ (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ശൂന്യ);
            } അല്ലെങ്കിൽ {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ശൂന്യ);
            }
        }
    } അല്ലെങ്കിൽ {
        unsigned long long n, n1;
        പൂർണ്ണസംഖ്യ lcount, ucount, ov = 0;
        സ്ഥിരം അക്ഷരം *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        എങ്കിൽ (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ആകുമ്പോൾ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            എങ്കിൽ (t == '\0')
                നിർത്തുക;
            അല്ലെങ്കിൽ എങ്കിൽ (t >= 'a')
                t = t - 'a' + 10;
            അല്ലെങ്കിൽ എങ്കിൽ (t >= 'A')
                t = t - 'A' + 10;
            അല്ലെങ്കിൽ
                t = t - '0';
            എങ്കിൽ (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            എങ്കിൽ (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        വേണ്ടി(;;) {
            t = toup(ch);
            എങ്കിൽ (t == 'L') {
                എങ്കിൽ (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                എങ്കിൽ (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } അല്ലെങ്കിൽ എങ്കിൽ (t == 'U') {
                എങ്കിൽ (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } അല്ലെങ്കിൽ {
                നിർത്തുക;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        എങ്കിൽ (pp_വ്യഞ്ജകം)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        എങ്കിൽ (ucount == 0 && b == 10) {
            എങ്കിൽ (lcount <= (LONG_SIZE == 4)) {
                എങ്കിൽ (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            എങ്കിൽ (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (lcount <= (LONG_SIZE == 4)) {
                എങ്കിൽ (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                അല്ലെങ്കിൽ എങ്കിൽ (n >= 0x80000000U)
                    ucount = 1;
            }
            എങ്കിൽ (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        എങ്കിൽ (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	എങ്കിൽ (lcount) {
            tok = TOK_CLONG;
            എങ്കിൽ (lcount == 2)
                tok = TOK_CLLONG;
	}
	എങ്കിൽ (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    എങ്കിൽ (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    അവസ്ഥ c1:                                    \
        PEEKC(c, p);                            \
        എങ്കിൽ (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } അല്ലെങ്കിൽ {                                \
            tok = tok1;                         \
        }                                       \
        നിർത്തുക;

/* return next token without macro substitution */
സ്ഥിതം ശൂന്യം next_nomacro(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned പൂർണ്ണസംഖ്യ h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    തിരഞ്ഞെടുപ്പ്(c) {
    അവസ്ഥ ' ':
    അവസ്ഥ '\t':
        tok = c;
        p++;
 maybe_space:
        എങ്കിൽ (parse_flags & PARSE_FLAG_SPACES)
            പോകുക keep_tok_flags;
        ആകുമ്പോൾ (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        പോകുക redo_no_start;
    അവസ്ഥ '\f':
    അവസ്ഥ '\v':
    അവസ്ഥ '\r':
        p++;
        പോകുക redo_no_start;
    അവസ്ഥ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        എങ്കിൽ (c == '\\')
            പോകുക parse_simple;
        എങ്കിൽ (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            എങ്കിൽ (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                പോകുക maybe_newline;
            } അല്ലെങ്കിൽ എങ്കിൽ (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } അല്ലെങ്കിൽ എങ്കിൽ (s1->ifdef_അട്ടി_ptr != file->ifdef_അട്ടി_ptr) {
                tcc_error("missing #endif");
            } അല്ലെങ്കിൽ എങ്കിൽ (s1->include_അട്ടി_ptr == s1->include_അട്ടി) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } അല്ലെങ്കിൽ {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                എങ്കിൽ (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ശൂന്യ));
#endif
                    തിരയൽ_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_അട്ടി_ptr--;
                p = file->buf_ptr;
                പോകുക maybe_newline;
            }
        } അല്ലെങ്കിൽ {
            പോകുക redo_no_start;
        }
        നിർത്തുക;

    അവസ്ഥ '\n':
        file->വരി_അക്കം++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        എങ്കിൽ (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            പോകുക redo_no_start;
        tok = TOK_LINEFEED;
        പോകുക keep_tok_flags;

    അവസ്ഥ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        എങ്കിൽ ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            പോകുക maybe_newline;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } അല്ലെങ്കിൽ {
#എങ്കിൽ !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_വരി_comment(p - 1);
                    പോകുക redo_no_start;
                } അല്ലെങ്കിൽ
#endif
                {
                    tok = '#';
                }
            }
        }
        നിർത്തുക;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    അവസ്ഥ '$':
        എങ്കിൽ (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            പോകുക parse_simple;

    അവസ്ഥ 'a': അവസ്ഥ 'b': അവസ്ഥ 'c': അവസ്ഥ 'd':
    അവസ്ഥ 'e': അവസ്ഥ 'f': അവസ്ഥ 'g': അവസ്ഥ 'h':
    അവസ്ഥ 'i': അവസ്ഥ 'j': അവസ്ഥ 'k': അവസ്ഥ 'l':
    അവസ്ഥ 'm': അവസ്ഥ 'n': അവസ്ഥ 'o': അവസ്ഥ 'p':
    അവസ്ഥ 'q': അവസ്ഥ 'r': അവസ്ഥ 's': അവസ്ഥ 't':
    അവസ്ഥ 'u': അവസ്ഥ 'v': അവസ്ഥ 'w': അവസ്ഥ 'x':
    അവസ്ഥ 'y': അവസ്ഥ 'z': 
    അവസ്ഥ 'A': അവസ്ഥ 'B': അവസ്ഥ 'C': അവസ്ഥ 'D':
    അവസ്ഥ 'E': അവസ്ഥ 'F': അവസ്ഥ 'G': അവസ്ഥ 'H':
    അവസ്ഥ 'I': അവസ്ഥ 'J': അവസ്ഥ 'K': 
    അവസ്ഥ 'M': അവസ്ഥ 'N': അവസ്ഥ 'O': അവസ്ഥ 'P':
    അവസ്ഥ 'Q': അവസ്ഥ 'R': അവസ്ഥ 'S': അവസ്ഥ 'T':
    അവസ്ഥ 'U': അവസ്ഥ 'V': അവസ്ഥ 'W': അവസ്ഥ 'X':
    അവസ്ഥ 'Y': അവസ്ഥ 'Z': 
    അവസ്ഥ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ആകുമ്പോൾ (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_അക്കം))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        എങ്കിൽ (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            വേണ്ടി(;;) {
                ts = *pts;
                എങ്കിൽ (!ts)
                    നിർത്തുക;
                എങ്കിൽ (ts->len == len && !memcmp(ts->str, p1, len))
                    പോകുക token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (അക്ഷരം *) p1, len);
        token_found: ;
        } അല്ലെങ്കിൽ {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (അക്ഷരം *) p1, len);
            p--;
            PEEKC(c, p);
            ആകുമ്പോൾ (isidnum_table[c - CH_EOF] & (IS_ID|IS_അക്കം))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        നിർത്തുക;
    അവസ്ഥ 'L':
        t = p[1];
        എങ്കിൽ (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            എങ്കിൽ (c == '\'' || c == '\"') {
                is_long = 1;
                പോകുക str_const;
            }
            *--p = c = 'L';
        }
        പോകുക parse_ident_fast;

    അവസ്ഥ '0': അവസ്ഥ '1': അവസ്ഥ '2': അവസ്ഥ '3':
    അവസ്ഥ '4': അവസ്ഥ '5': അവസ്ഥ '6': അവസ്ഥ '7':
    അവസ്ഥ '8': അവസ്ഥ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_അക്കം:
        cstr_reset(&tokcstr);
        വേണ്ടി(;;) {
            cstr_ccat(&tokcstr, t);
            എങ്കിൽ (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_അക്കം))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((അക്ഷരം*)tokcstr.data)[0] == '0'
                                && toup(((അക്ഷരം*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                നിർത്തുക;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        നിർത്തുക;

    അവസ്ഥ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        എങ്കിൽ (isnum(c)) {
            t = '.';
            പോകുക parse_അക്കം;
        } അല്ലെങ്കിൽ എങ്കിൽ ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_അക്കം))) {
            *--p = c = '.';
            പോകുക parse_ident_fast;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '.') {
            PEEKC(c, p);
            എങ്കിൽ (c == '.') {
                p++;
                tok = TOK_DOTS;
            } അല്ലെങ്കിൽ {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } അല്ലെങ്കിൽ {
            tok = '.';
        }
        നിർത്തുക;
    അവസ്ഥ '\'':
    അവസ്ഥ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        എങ്കിൽ (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        നിർത്തുക;

    അവസ്ഥ '<':
        PEEKC(c, p);
        എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_LE;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '<') {
            PEEKC(c, p);
            എങ്കിൽ (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } അല്ലെങ്കിൽ {
                tok = TOK_SHL;
            }
        } അല്ലെങ്കിൽ {
            tok = TOK_LT;
        }
        നിർത്തുക;
    അവസ്ഥ '>':
        PEEKC(c, p);
        എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_GE;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '>') {
            PEEKC(c, p);
            എങ്കിൽ (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } അല്ലെങ്കിൽ {
                tok = TOK_SAR;
            }
        } അല്ലെങ്കിൽ {
            tok = TOK_GT;
        }
        നിർത്തുക;
        
    അവസ്ഥ '&':
        PEEKC(c, p);
        എങ്കിൽ (c == '&') {
            p++;
            tok = TOK_LAND;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_A_AND;
        } അല്ലെങ്കിൽ {
            tok = '&';
        }
        നിർത്തുക;
        
    അവസ്ഥ '|':
        PEEKC(c, p);
        എങ്കിൽ (c == '|') {
            p++;
            tok = TOK_LOR;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_A_OR;
        } അല്ലെങ്കിൽ {
            tok = '|';
        }
        നിർത്തുക;

    അവസ്ഥ '+':
        PEEKC(c, p);
        എങ്കിൽ (c == '+') {
            p++;
            tok = TOK_INC;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } അല്ലെങ്കിൽ {
            tok = '+';
        }
        നിർത്തുക;
        
    അവസ്ഥ '-':
        PEEKC(c, p);
        എങ്കിൽ (c == '-') {
            p++;
            tok = TOK_DEC;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '>') {
            p++;
            tok = TOK_ARROW;
        } അല്ലെങ്കിൽ {
            tok = '-';
        }
        നിർത്തുക;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    അവസ്ഥ '/':
        PEEKC(c, p);
        എങ്കിൽ (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            പോകുക maybe_space;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '/') {
            p = parse_വരി_comment(p);
            tok = ' ';
            പോകുക maybe_space;
        } അല്ലെങ്കിൽ എങ്കിൽ (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } അല്ലെങ്കിൽ {
            tok = '/';
        }
        നിർത്തുക;
        
        /* simple tokens */
    അവസ്ഥ '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_വരി_comment(p);
            പോകുക redo_no_start;
        }
#endif
    അവസ്ഥ '(':
    അവസ്ഥ ')':
    അവസ്ഥ '[':
    അവസ്ഥ ']':
    അവസ്ഥ '{':
    അവസ്ഥ '}':
    അവസ്ഥ ',':
    അവസ്ഥ ';':
    അവസ്ഥ ':':
    അവസ്ഥ '?':
    അവസ്ഥ '~':
    parse_simple:
        tok = c;
        p++;
        നിർത്തുക;
    അവസ്ഥ 0xEF: /* UTF8 BOM ? */
        എങ്കിൽ (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            പോകുക redo_no_start;
        }
    സ്ഥിരസ്ഥിതി:
        എങ്കിൽ (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    പോകുക parse_ident_fast;
        എങ്കിൽ (parse_flags & PARSE_FLAG_ASM_FILE)
            പോകുക parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        നിർത്തുക;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#എങ്കിൽ defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
സ്ഥിതം പൂർണ്ണസംഖ്യ indent;
സ്ഥിതം ശൂന്യം define_print(TCCState *s1, പൂർണ്ണസംഖ്യ v);
സ്ഥിതം ശൂന്യം pp_print(സ്ഥിരം അക്ഷരം *സന്ദേശം, പൂർണ്ണസംഖ്യ v, സ്ഥിരം പൂർണ്ണസംഖ്യ *str)
{
    FILE *fp = tcc_state->ppfp;

    എങ്കിൽ (സന്ദേശം[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    അല്ലെങ്കിൽ എങ്കിൽ (സന്ദേശം[0] == '+')
         ++indent, ++സന്ദേശം;
    അല്ലെങ്കിൽ എങ്കിൽ (സന്ദേശം[0] == '-')
        --indent, ++സന്ദേശം;

    fprintf(fp, "%*s", indent, "");
    എങ്കിൽ (സന്ദേശം[0] == '#') {
        define_print(tcc_state, v);
    } അല്ലെങ്കിൽ {
        tok_print(str, v ? "%s %s" : "%s", സന്ദേശം, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#അല്ലെങ്കിൽ
#define PP_PRINT(x)
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    സ്ഥിരം പൂർണ്ണസംഖ്യ *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
സ്ഥിതം പൂർണ്ണസംഖ്യ *macro_arg_subst(Sym **nested_list, സ്ഥിരം പൂർണ്ണസംഖ്യ *macro_str, Sym *args)
{
    പൂർണ്ണസംഖ്യ t, t0, t1, t2, n;
    സ്ഥിരം പൂർണ്ണസംഖ്യ *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    വേണ്ടി (s = args, n = 0; s; s = s->prev, ++n);
    ആകുമ്പോൾ (n--) {
        വേണ്ടി (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    ആകുമ്പോൾ(1) {
        TOK_GET(&t, &macro_str, &cval);
        എങ്കിൽ (!t)
            നിർത്തുക;
        എങ്കിൽ (t == '#') {
            /* stringize */
            ചെയ്യുക t = *macro_str++; ആകുമ്പോൾ (t == ' ');
            s = sym_find2(args, t);
            എങ്കിൽ (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ആകുമ്പോൾ (*st != TOK_EOF) {
                    സ്ഥിരം അക്ഷരം *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ആകുമ്പോൾ (*s) {
                        എങ്കിൽ (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        അല്ലെങ്കിൽ
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
            } അല്ലെങ്കിൽ എങ്കിൽ ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } അല്ലെങ്കിൽ {
                expect("macro parameter after '#'");
            }
        } അല്ലെങ്കിൽ എങ്കിൽ (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            എങ്കിൽ (s) {
                st = s->d;
                n = 0;
                ആകുമ്പോൾ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                എങ്കിൽ (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    എങ്കിൽ (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        പൂർണ്ണസംഖ്യ c = str.str[str.len - 1];
                        ആകുമ്പോൾ (str.str[--str.len] != ',')
                            ;
                        എങ്കിൽ (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } അല്ലെങ്കിൽ {
                            /* suppress '##' and add variable */
                            str.len++;
                            എങ്കിൽ (c == ' ')
                                str.str[str.len++] = c;
                            പോകുക add_var;
                        }
                    } അല്ലെങ്കിൽ {
                        എങ്കിൽ (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } അല്ലെങ്കിൽ {
            add_var:
		    എങ്കിൽ (!s->e) {
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
                ആകുമ്പോൾ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } അല്ലെങ്കിൽ {
                tok_str_add(&str, t);
            }
        } അല്ലെങ്കിൽ {
            tok_str_add2(&str, t, &cval);
        }
        എങ്കിൽ (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    തിരികെ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
സ്ഥിതം വരിയിൽ പൂർണ്ണസംഖ്യ *macro_twosharps(സ്ഥിരം പൂർണ്ണസംഖ്യ *ptr0)
{
    പൂർണ്ണസംഖ്യ t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    സ്ഥിരം പൂർണ്ണസംഖ്യ *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    വേണ്ടി (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        എങ്കിൽ (t1 == 0)
            നിർത്തുക;
        വേണ്ടി (;;) {
            n = 0;
            ആകുമ്പോൾ ((t2 = ptr[n]) == ' ')
                ++n;
            എങ്കിൽ (t2 != TOK_PPJOIN)
                നിർത്തുക;
            ptr += n;
            ആകുമ്പോൾ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            എങ്കിൽ (t2 == TOK_PLCHLDR)
                തുടരുക;
            എങ്കിൽ (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        എങ്കിൽ (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            വേണ്ടി (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                എങ്കിൽ (*file->buf_ptr == 0)
                    നിർത്തുക;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        എങ്കിൽ (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    തിരികെ macro_str1.str;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    പൂർണ്ണസംഖ്യ c;
    വേണ്ടി (;;) {
        PEEKC(c, p);
        തിരഞ്ഞെടുപ്പ് (c) {
        അവസ്ഥ '/':
            PEEKC(c, p);
            എങ്കിൽ (c == '*')
                p = parse_comment(p);
            അല്ലെങ്കിൽ എങ്കിൽ (c == '/')
                p = parse_വരി_comment(p);
            അല്ലെങ്കിൽ {
                c = *--p = '/';
                പോകുക leave;
            }
            --p, c = ' ';
            നിർത്തുക;
        അവസ്ഥ ' ': അവസ്ഥ '\t':
            നിർത്തുക;
        അവസ്ഥ '\f': അവസ്ഥ '\v': അവസ്ഥ '\r':
            തുടരുക;
        അവസ്ഥ '\n':
            file->വരി_അക്കം++, tok_flags |= TOK_FLAG_BOL;
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി: leave:
            file->buf_ptr = p;
            തിരികെ c;
        }
        എങ്കിൽ (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
സ്ഥിതം പൂർണ്ണസംഖ്യ next_argstream(Sym **nested_list, TokenString *ws_str)
{
    പൂർണ്ണസംഖ്യ t;
    Sym *sa;

    ആകുമ്പോൾ (macro_ptr) {
        സ്ഥിരം പൂർണ്ണസംഖ്യ *m = macro_ptr;
        ആകുമ്പോൾ ((t = *m) != 0) {
            എങ്കിൽ (ws_str) {
                എങ്കിൽ (t != ' ')
                    തിരികെ t;
                ++m;
            } അല്ലെങ്കിൽ {
                TOK_GET(&tok, &macro_ptr, &tokc);
                തിരികെ tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        എങ്കിൽ (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    എങ്കിൽ (ws_str) {
        തിരികെ peek_file(ws_str);
    } അല്ലെങ്കിൽ {
        next_nomacro();
        എങ്കിൽ (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        തിരികെ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
സ്ഥിതം പൂർണ്ണസംഖ്യ macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    പൂർണ്ണസംഖ്യ t;
    പൂർണ്ണസംഖ്യ v = s->v;

    PP_PRINT(("#", v, s->d));
    എങ്കിൽ (s->d) {
        പൂർണ്ണസംഖ്യ *mstr = s->d;
        പൂർണ്ണസംഖ്യ *jstr;
        Sym *sa;
        പൂർണ്ണസംഖ്യ ret;

        എങ്കിൽ (s->type.t & MACRO_FUNC) {
            പൂർണ്ണസംഖ്യ saved_parse_flags = parse_flags;
            TokenString str;
            പൂർണ്ണസംഖ്യ parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            എങ്കിൽ (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                എങ്കിൽ (parse_flags & PARSE_FLAG_SPACES)
                    വേണ്ടി (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                തിരികെ 0;
            } അല്ലെങ്കിൽ {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = ശൂന്യ;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            വേണ്ടി(;;) {
                ചെയ്യുക {
                    t = next_argstream(nested_list, ശൂന്യ);
                } ആകുമ്പോൾ (t == ' ' || --i);

                എങ്കിൽ (!sa) {
                    എങ്കിൽ (t == ')') /* handle '()' case */
                        നിർത്തുക;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ആകുമ്പോൾ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    എങ്കിൽ (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    എങ്കിൽ (t == '(')
                        parlevel++;
                    എങ്കിൽ (t == ')')
                        parlevel--;
                    എങ്കിൽ (t == ' ')
                        str.need_spc |= 1;
                    അല്ലെങ്കിൽ
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, ശൂന്യ);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                എങ്കിൽ (t == ')') {
                    എങ്കിൽ (!sa)
                        നിർത്തുക;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    എങ്കിൽ (sa->type.t && gnu_ext)
                        പോകുക empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            ആകുമ്പോൾ (sa) {
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
        എങ്കിൽ (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        എങ്കിൽ (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        എങ്കിൽ (jstr != mstr)
            tok_str_free_str(jstr);
        എങ്കിൽ (mstr != s->d)
            tok_str_free_str(mstr);
        തിരികെ ret;

    } അല്ലെങ്കിൽ {
        CValue cval;
        അക്ഷരം buf[32], *cstrval = buf;

        /* special macros */
        എങ്കിൽ (v == TOK_വരി_2 || v == TOK___COUNTER__) {
            t = v == TOK_വരി_2 ? file->വരി_അക്കം : pp_counter++;
            snprintf(buf, വലുപ്പം(buf), "%d", t);
            t = TOK_PPNUM;
            പോകുക add_cstr1;

        } അല്ലെങ്കിൽ എങ്കിൽ (v == TOK___FILE__) {
            cstrval = file->filename;
            പോകുക add_cstr;

        } അല്ലെങ്കിൽ എങ്കിൽ (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            ഘടന tm *tm;
            time(&ti);
            tm = localtime(&ti);
            എങ്കിൽ (v == TOK___DATE__) {
                സ്ഥിതം അക്ഷരം സ്ഥിരം ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, വലുപ്പം(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } അല്ലെങ്കിൽ {
                snprintf(buf, വലുപ്പം(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        തിരികെ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
സ്ഥിതം പൂർണ്ണസംഖ്യ macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    സ്ഥിരം പൂർണ്ണസംഖ്യ *macro_str
    )
{
    Sym *s;
    പൂർണ്ണസംഖ്യ t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    പൂർണ്ണസംഖ്യ tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    ആകുമ്പോൾ (1) {
        TOK_GET(&t, &macro_str, &cval);
        എങ്കിൽ (t == 0 || t == TOK_EOF)
            നിർത്തുക;
        എങ്കിൽ (t >= TOK_IDENT) {
            s = define_find(t);
            എങ്കിൽ (s == ശൂന്യ || nosubst)
                പോകുക no_subst;
            /* if nested substitution, do nothing */
            എങ്കിൽ (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                പോകുക no_subst;
            }
            str = tok_str_alloc();
            str->str = (പൂർണ്ണസംഖ്യ*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            എങ്കിൽ (macro_അട്ടി != str) {
                /* already finished by reading function macro arguments */
                നിർത്തുക;
            }
            macro_str = macro_ptr;
            end_macro ();
        } അല്ലെങ്കിൽ എങ്കിൽ (t == ' ') {
            എങ്കിൽ (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } അല്ലെങ്കിൽ {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            എങ്കിൽ (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            എങ്കിൽ (t == TOK_DEFINED && pp_വ്യഞ്ജകം)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    തിരികെ nosubst;
}

/* return next token with macro substitution */
ST_FUNC ശൂന്യം next(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ t;
    ആകുമ്പോൾ (macro_ptr) {
redo:
        t = *macro_ptr;
        എങ്കിൽ (TOK_HAS_മൂല്യം(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            എങ്കിൽ (t == TOK_LINENUM) {
                file->വരി_അക്കം = tokc.i;
                പോകുക redo;
            }
            പോകുക convert;
        } അല്ലെങ്കിൽ എങ്കിൽ (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            തുടരുക;
        } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_EOF) {
            /* do nothing */
        } അല്ലെങ്കിൽ {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            എങ്കിൽ (t == '\\') {
                എങ്കിൽ (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        തിരികെ;
    }

    next_nomacro();
    t = tok;
    എങ്കിൽ (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        എങ്കിൽ (s) {
            Sym *nested_list = ശൂന്യ;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            പോകുക redo;
        }
        തിരികെ;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    എങ്കിൽ (t == TOK_PPNUM) {
        എങ്കിൽ  (parse_flags & PARSE_FLAG_TOK_അക്കം)
            parse_സംഖ്യ(tokc.str.data);
    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_PPSTR) {
        എങ്കിൽ (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN ശൂന്യം unget_tok(പൂർണ്ണസംഖ്യ last_tok)
{
    TokenString *str = &unget_buf;
    പൂർണ്ണസംഖ്യ alloc = 0;
    എങ്കിൽ (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    എങ്കിൽ (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

സ്ഥിതം സ്ഥിരം അക്ഷരം * സ്ഥിരം target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# എങ്കിൽ PTR_SIZE == 8
    "_WIN64\0"
# endif
#അല്ലെങ്കിൽ
# എങ്കിൽ defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# അല്ലെങ്കിൽ
    "__linux__\0"
    "__linux\0"
#  എങ്കിൽ TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

സ്ഥിതം ശൂന്യം putdef(CString *cs, സ്ഥിരം അക്ഷരം *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

സ്ഥിതം ശൂന്യം putdefs(CString *cs, സ്ഥിരം അക്ഷരം *p)
{
    ആകുമ്പോൾ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

സ്ഥിതം ശൂന്യം tcc_predefs(TCCState *s1, CString *cs, പൂർണ്ണസംഖ്യ is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    എങ്കിൽ (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    എങ്കിൽ (is_asm)
      putdef(cs, "__ASSEMBLER__");
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    എങ്കിൽ (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    എങ്കിൽ (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    എങ്കിൽ (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    എങ്കിൽ (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    എങ്കിൽ (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    എങ്കിൽ (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#എങ്കിൽ CONFIG_TCC_PREDEFS
        #അന്തര്ഭാവ "tccdefs_.h" /* include as strings */
#അല്ലെങ്കിൽ
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC ശൂന്യം preprocess_start(TCCState *s1, പൂർണ്ണസംഖ്യ filetype)
{
    പൂർണ്ണസംഖ്യ is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_അട്ടി_ptr = s1->include_അട്ടി;
    s1->ifdef_അട്ടി_ptr = s1->ifdef_അട്ടി;
    file->ifdef_അട്ടി_ptr = s1->ifdef_അട്ടി_ptr;
    pp_വ്യഞ്ജകം = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_അട്ടി[0] = 0;
    s1->pack_അട്ടി_ptr = s1->pack_അട്ടി;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    എങ്കിൽ (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        എങ്കിൽ (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        എങ്കിൽ (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_അട്ടി_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC ശൂന്യം preprocess_end(TCCState *s1)
{
    ആകുമ്പോൾ (macro_അട്ടി)
        end_macro();
    macro_ptr = ശൂന്യ;
    ആകുമ്പോൾ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC പൂർണ്ണസംഖ്യ set_idnum(പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ val)
{
    പൂർണ്ണസംഖ്യ prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    തിരികെ prev;
}

ST_FUNC ശൂന്യം tccpp_new(TCCState *s)
{
    പൂർണ്ണസംഖ്യ i, c;
    സ്ഥിരം അക്ഷരം *p, *r;

    /* init isid table */
    വേണ്ടി(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_അക്കം
            : 0);

    വേണ്ടി(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * വലുപ്പം(TokenSym *));
    memset(s->cached_includes_hash, 0, വലുപ്പം s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ആകുമ്പോൾ (*p) {
        r = p;
        വേണ്ടി(;;) {
            c = *r++;
            എങ്കിൽ (c == '\0')
                നിർത്തുക;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_തള്ളുക(TOK_വരി_2, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
    define_തള്ളുക(TOK___FILE__, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
    define_തള്ളുക(TOK___DATE__, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
    define_തള്ളുക(TOK___TIME__, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
    define_തള്ളുക(TOK___COUNTER__, MACRO_OBJ, ശൂന്യ, ശൂന്യ);
}

ST_FUNC ശൂന്യം tccpp_delete(TCCState *s)
{
    പൂർണ്ണസംഖ്യ i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    എങ്കിൽ (n > total_idents)
        total_idents = n;
    വേണ്ടി (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ശൂന്യ;

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

സ്ഥിതം പൂർണ്ണസംഖ്യ pp_need_space(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b);

സ്ഥിതം ശൂന്യം tok_print(സ്ഥിരം പൂർണ്ണസംഖ്യ *str, സ്ഥിരം അക്ഷരം *സന്ദേശം, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    പൂർണ്ണസംഖ്യ t, t0, s;
    CValue cval;

    va_start(ap, സന്ദേശം);
    vfprintf(fp, സന്ദേശം, ap);
    va_end(ap);

    s = t0 = 0;
    ആകുമ്പോൾ (str) {
	TOK_GET(&t, &str, &cval);
	എങ്കിൽ (t == 0 || t == TOK_EOF)
	    നിർത്തുക;
        എങ്കിൽ (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

സ്ഥിതം ശൂന്യം pp_വരി(TCCState *s1, BufferedFile *f, പൂർണ്ണസംഖ്യ level)
{
    പൂർണ്ണസംഖ്യ d = f->വരി_അക്കം - f->വരി_ref;

    എങ്കിൽ (s1->dflag & 4)
	തിരികെ;

    എങ്കിൽ (s1->Pflag == വരി_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } അല്ലെങ്കിൽ എങ്കിൽ (level == 0 && f->വരി_ref && d < 8) {
	ആകുമ്പോൾ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } അല്ലെങ്കിൽ എങ്കിൽ (s1->Pflag == വരി_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->വരി_അക്കം, f->filename);
    } അല്ലെങ്കിൽ {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->വരി_അക്കം, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->വരി_ref = f->വരി_അക്കം;
}

സ്ഥിതം ശൂന്യം define_print(TCCState *s1, പൂർണ്ണസംഖ്യ v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    എങ്കിൽ (ശൂന്യ == s || ശൂന്യ == s->d)
        തിരികെ;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ശൂന്യ));
    എങ്കിൽ (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        എങ്കിൽ (a)
            വേണ്ടി (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ശൂന്യ));
                എങ്കിൽ (!(a = a->next))
                    നിർത്തുക;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

സ്ഥിതം ശൂന്യം pp_debug_defines(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ v, t;
    സ്ഥിരം അക്ഷരം *vs;
    FILE *fp;

    t = pp_debug_tok;
    എങ്കിൽ (t == 0)
        തിരികെ;

    file->വരി_അക്കം--;
    pp_വരി(s1, file, 0);
    file->വരി_ref = ++file->വരി_അക്കം;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ശൂന്യ);
    എങ്കിൽ (t == TOK_DEFINE) {
        define_print(s1, v);
    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_തള്ളുക_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } അല്ലെങ്കിൽ എങ്കിൽ (t == TOK_എടുക്കുക_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
സ്ഥിതം പൂർണ്ണസംഖ്യ pp_need_space(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    തിരികെ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
സ്ഥിതം പൂർണ്ണസംഖ്യ pp_check_he0xE(പൂർണ്ണസംഖ്യ t, സ്ഥിരം അക്ഷരം *p)
{
    എങ്കിൽ (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        തിരികെ 'E';
    തിരികെ t;
}

/* Preprocess the current file */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    പൂർണ്ണസംഖ്യ token_seen, spcs, level;
    സ്ഥിരം അക്ഷരം *p;
    അക്ഷരം white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    എങ്കിൽ (s1->Pflag == വരി_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_അക്കം, s1->Pflag = 1;

    എങ്കിൽ (s1->do_bench) {
	/* for PP benchmarks */
	ചെയ്യുക next(); ആകുമ്പോൾ (tok != TOK_EOF);
	തിരികെ 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    എങ്കിൽ (file->prev)
        pp_വരി(s1, file->prev, level++);
    pp_വരി(s1, file, level);

    വേണ്ടി (;;) {
        iptr = s1->include_അട്ടി_ptr;
        next();
        എങ്കിൽ (tok == TOK_EOF)
            നിർത്തുക;

        level = s1->include_അട്ടി_ptr - iptr;
        എങ്കിൽ (level) {
            എങ്കിൽ (level > 0)
                pp_വരി(s1, *iptr, 0);
            pp_വരി(s1, file, level);
        }
        എങ്കിൽ (s1->dflag & 7) {
            pp_debug_defines(s1);
            എങ്കിൽ (s1->dflag & 4)
                തുടരുക;
        }

        എങ്കിൽ (is_space(tok)) {
            എങ്കിൽ (spcs < വലുപ്പം white - 1)
                white[spcs++] = tok;
            തുടരുക;
        } അല്ലെങ്കിൽ എങ്കിൽ (tok == TOK_LINEFEED) {
            spcs = 0;
            എങ്കിൽ (token_seen == TOK_LINEFEED)
                തുടരുക;
            ++file->വരി_ref;
        } അല്ലെങ്കിൽ എങ്കിൽ (token_seen == TOK_LINEFEED) {
            pp_വരി(s1, file, 0);
        } അല്ലെങ്കിൽ എങ്കിൽ (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    തിരികെ 0;
}

/* ------------------------------------------------------------------------- */
