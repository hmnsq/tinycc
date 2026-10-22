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
#ଅନ୍ତର୍ଭାଵ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_flags;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_flags;

ST_DATA ସଂରଚନା BufferedFile *file;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok;
ST_DATA CValue tokc;
ST_DATA ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_ପଦସମଷ୍ଟି;

/* ------------------------------------------------------------------------- */

ସ୍ଥିର TokenSym *hash_ident[TOK_HASH_SIZE];
ସ୍ଥିର ଅକ୍ଷର token_buf[STRING_MAX_SIZE + 1];
ସ୍ଥିର CString cstr_buf;
ସ୍ଥିର TokenString tokstr_buf;
ସ୍ଥିର TokenString unget_buf;
ସ୍ଥିର unsigned ଅକ୍ଷର isidnum_table[256 - CH_EOF];
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_debug_tok, pp_debug_symv;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_counter;
ସ୍ଥିର ଶୂନ୍ୟ tok_print(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ, ...);
ସ୍ଥିର ଶୂନ୍ୟ next_nomacro(ଶୂନ୍ୟ);
ସ୍ଥିର ଶୂନ୍ୟ parse_ସଂଖ୍ୟା(ଅଚଳ ଅକ୍ଷର *p);
ସ୍ଥିର ଶୂନ୍ୟ parse_string(ଅଚଳ ଅକ୍ଷର *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len);

ସ୍ଥିର ସଂରଚନା TinyAlloc *toksym_alloc;
ସ୍ଥିର ସଂରଚନା TinyAlloc *tokstr_alloc;

ସ୍ଥିର TokenString *macro_ଗଦା;

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର tcc_keywords[] = 
#define DEF(id, str) str "\0"
#ଅନ୍ତର୍ଭାଵ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର tok_two_chars[] =
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

ST_FUNC ଶୂନ୍ୟ skip(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯଦି (tok != c) {
        ଅକ୍ଷର tmp[40];
        pstrcpy(tmp, ଆକାର tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC ଶୂନ୍ୟ expect(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
    tcc_error("%s expected", ସନ୍ଦେଶ);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#ଅନ୍ୟଥା
#ଯଦି !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#ଅନ୍ୟଥା
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , ଅଚଳ ଅକ୍ଷର *sfile, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    ସଂରଚନା TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#ଯଦି TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    ସଂଘ {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tal_header_t {
    size_t  size; /* word align */
#ଯଦି TAL_DEBUG
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା     ଧାଡ଼ି_ଅଙ୍କ; /* negative line_num used for double free check */
    ଅକ୍ଷର    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (ଆକାର (size_t) - 1)) & ~(ଆକାର (size_t) - 1))

/* ------------------------------------------------------------------------- */

ସ୍ଥିର TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(ଆକାର(TinyAlloc) - ଆକାର (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#ଯଦି TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    ଫେରନ୍ତୁ al;
}

ସ୍ଥିର ଶୂନ୍ୟ tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#ଯଦି TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#ଯଦି TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#ଯଦି TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    ଯଦି (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        ଯେତେବେଳେ (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            ଯଦି (header->ଧାଡ଼ି_ଅଙ୍କ > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->ଧାଡ଼ି_ଅଙ୍କ, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)header->size);
            }
            p += header->size + ଆକାର(tal_header_t);
        }
#ଯଦି TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    ଯଦି (al)
        ଯାଅ tail_call;
    *pal = al;
}

ସ୍ଥିର ଶୂନ୍ୟ tal_free_impl(TinyAlloc **pal, ଶୂନ୍ୟ *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **ଶୀର୍ଷ = pal;
    tal_header_t *header;

    ଯଦି (!p)
        ଫେରନ୍ତୁ;
    header = (tal_header_t *)p - 1;
#ଯଦି TAL_DEBUG
    ଯଦି (header->ଧାଡ଼ି_ଅଙ୍କ < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)-header->ଧାଡ଼ି_ଅଙ୍କ, (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)header->size);
    } ଅନ୍ୟଥା
        header->ଧାଡ଼ି_ଅଙ୍କ = -header->ଧାଡ଼ି_ଅଙ୍କ;
#endif
    al = *pal;
    ଯେତେବେଳେ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    ଯଦି (0 == --al->nb_allocs) {
        *pal = al->next;
        ଯଦି ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } ଅନ୍ୟଥା {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *ଶୀର୍ଷ, *ଶୀର୍ଷ = al;
        }
    } ଅନ୍ୟଥା ଯଦି ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

ସ୍ଥିର ଶୂନ୍ୟ *tal_realloc_impl(TinyAlloc **pal, ଶୂନ୍ୟ *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    ଶୂନ୍ୟ *ret;
    unsigned adj_size = TAL_ALIGN(size) + ଆକାର(tal_header_t);
    TinyAlloc *al = *pal;

    ଯଦି (p) {
        /* reallpc case */
        ଯେତେବେଳେ ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        ଯଦି ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        ଯଦି (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            ଫେରନ୍ତୁ ret;
        } ଅନ୍ୟଥା ଯଦି (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#ଯଦି TAL_DEBUG
            header->ଧାଡ଼ି_ଅଙ୍କ = -header->ଧାଡ଼ି_ଅଙ୍କ;
#endif
        }
    } ଅନ୍ୟଥା {
        /* new alloc case */
        ଯେତେବେଳେ (al->p + adj_size > al->bufend) {
            al = al->next;
            ଯଦି (!al) {
                unsigned new_size = (*pal)->size;
                ଯଦି (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                ଭାଙ୍ଗ;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - ଆକାର(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#ଯଦି  TAL_DEBUG
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ofs = strlen(sfile) + 1 - ଆକାର header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->ଧାଡ଼ି_ଅଙ୍କ = sline;
#ଯଦି TAL_INFO
        ଯଦି (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        ଯଦି (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    ଫେରନ୍ତୁ ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
ସ୍ଥିର ଶୂନ୍ୟ cstr_realloc(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା new_size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;

    size = cstr->size_allocated;
    ଯଦି (size < 8)
        size = 8; /* no need to allocate a too small first string */
    ଯେତେବେଳେ (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN ଶୂନ୍ୟ cstr_ccat(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;
    size = cstr->size + 1;
    ଯଦି (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN ଅକ୍ଷର *unicode_to_utf8 (ଅକ୍ଷର *b, uint32_t Uc)
{
    ଯଦି (Uc<0x80) *b++=Uc;
    ଅନ୍ୟଥା ଯଦି (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    ଅନ୍ୟଥା ଯଦି (Uc-0xd800u<0x800) ଯାଅ error;
    ଅନ୍ୟଥା ଯଦି (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ଅନ୍ୟଥା ଯଦି (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    ଅନ୍ୟଥା error: tcc_error("0x%x is not a valid universal character", Uc);
    ଫେରନ୍ତୁ b;
}

/* add a unicode character expanded into utf8 */
ST_INLN ଶୂନ୍ୟ cstr_u8cat(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch)
{
    ଅକ୍ଷର buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC ଶୂନ୍ୟ cstr_cat(CString *cstr, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;
    ଯଦି (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    ଯଦି (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC ଶୂନ୍ୟ cstr_wccat(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size;
    size = cstr->size + ଆକାର(nwchar_t);
    ଯଦି (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - ଆକାର(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC ଶୂନ୍ୟ cstr_new(CString *cstr)
{
    memset(cstr, 0, ଆକାର(CString));
}

/* free string and reset it to NULL */
ST_FUNC ଶୂନ୍ୟ cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC ଶୂନ୍ୟ cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା cstr_vprintf(CString *cstr, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap)
{
    va_list v;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, size = 80;
    ପାଇଁ (;;) {
        size += cstr->size;
        ଯଦି (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        ଯଦି (len >= 0 && len < size)
            ଭାଙ୍ଗ;
        size *= 2;
    }
    cstr->size += len;
    ଫେରନ୍ତୁ len;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା cstr_printf(CString *cstr, ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap; ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    ଫେରନ୍ତୁ len;
}

/* XXX: unicode ? */
ସ୍ଥିର ଶୂନ୍ୟ add_char(CString *cstr, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯଦି (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    ଯଦି (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } ଅନ୍ୟଥା {
        cstr_ccat(cstr, '\\');
        ଯଦି (c == '\n') {
            cstr_ccat(cstr, 'n');
        } ଅନ୍ୟଥା {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
ସ୍ଥିର TokenSym *tok_alloc_new(TokenSym **pts, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len)
{
    TokenSym *ts, **ptable;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ଯଦି (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    ଯଦି ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * ଆକାର(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, ଆକାର(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ଖାଲି;
    ts->sym_label = ଖାଲି;
    ts->sym_struct = ଖାଲି;
    ts->sym_identifier = ଖାଲି;
    ts->len = len;
    ts->hash_next = ଖାଲି;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    ଫେରନ୍ତୁ ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len)
{
    TokenSym *ts, **pts;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା h;
    
    h = TOK_HASH_INIT;
    ପାଇଁ(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned ଅକ୍ଷର *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    ପାଇଁ(;;) {
        ts = *pts;
        ଯଦି (!ts)
            ଭାଙ୍ଗ;
        ଯଦି (ts->len == len && !memcmp(ts->str, str, len))
            ଫେରନ୍ତୁ ts;
        pts = &(ts->hash_next);
    }
    ଫେରନ୍ତୁ tok_alloc_new(pts, str, len);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_alloc_const(ଅଚଳ ଅକ୍ଷର *str)
{
    ଫେରନ୍ତୁ tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC ଅଚଳ ଅକ୍ଷର *get_tok_str(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, CValue *cv)
{
    ଅକ୍ଷର *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    ବାଛ(v) {
    ସ୍ଥିତି TOK_CINT:
    ସ୍ଥିତି TOK_CUINT:
    ସ୍ଥିତି TOK_CLONG:
    ସ୍ଥିତି TOK_CULONG:
    ସ୍ଥିତି TOK_CLLONG:
    ସ୍ଥିତି TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    ସ୍ଥିତି TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_PPNUM:
    ସ୍ଥିତି TOK_PPSTR:
        ଫେରନ୍ତୁ (ଅକ୍ଷର*)cv->str.data;
    ସ୍ଥିତି TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    ସ୍ଥିତି TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        ଯଦି (v == TOK_STR) {
            len = cv->str.size - 1;
            ପାଇଁ(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned ଅକ୍ଷର *)cv->str.data)[i]);
        } ଅନ୍ୟଥା {
            len = (cv->str.size / ଆକାର(nwchar_t)) - 1;
            ପାଇଁ(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_CFLOAT:
        ଫେରନ୍ତୁ strcpy(p, "<float>");
    ସ୍ଥିତି TOK_CDOUBLE:
        ଫେରନ୍ତୁ strcpy(p, "<double>");
    ସ୍ଥିତି TOK_CLDOUBLE:
        ଫେରନ୍ତୁ strcpy(p, "<long double>");
    ସ୍ଥିତି TOK_LINENUM:
        ଫେରନ୍ତୁ strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    ସ୍ଥିତି TOK_LT:
        v = '<';
        ଯାଅ addv;
    ସ୍ଥିତି TOK_GT:
        v = '>';
        ଯାଅ addv;
    ସ୍ଥିତି TOK_DOTS:
        ଫେରନ୍ତୁ strcpy(p, "...");
    ସ୍ଥିତି TOK_A_SHL:
        ଫେରନ୍ତୁ strcpy(p, "<<=");
    ସ୍ଥିତି TOK_A_SAR:
        ଫେରନ୍ତୁ strcpy(p, ">>=");
    ସ୍ଥିତି TOK_EOF:
        ଫେରନ୍ତୁ strcpy(p, "<eof>");
    ସ୍ଥିତି 0: /* anonymous nameless symbols */
        ଫେରନ୍ତୁ strcpy(p, "<no name>");
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        ଯଦି (v < TOK_IDENT) {
            /* search in two bytes table */
            ଅଚଳ unsigned ଅକ୍ଷର *q = tok_two_chars;
            ଯେତେବେଳେ (*q) {
                ଯଦି (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    ଫେରନ୍ତୁ cstr_buf.data;
                }
                q += 3;
            }
            ଯଦି (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                ଭାଙ୍ଗ;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } ଅନ୍ୟଥା ଯଦି (v < tok_ident) {
            ଫେରନ୍ତୁ table_ident[v - TOK_IDENT]->str;
        } ଅନ୍ୟଥା ଯଦି (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } ଅନ୍ୟଥା {
            /* should never happen */
            ଫେରନ୍ତୁ ଖାଲି;
        }
        ଭାଙ୍ଗ;
    }
    ଫେରନ୍ତୁ cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା handle_eob(ଶୂନ୍ୟ)
{
    BufferedFile *bf = file;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;

    /* only tries to read if really end of buffer */
    ଯଦି (bf->buf_ptr >= bf->buf_end) {
        ଯଦି (bf->fd >= 0) {
#ଯଦି defined(PARSE_DEBUG)
            len = 1;
#ଅନ୍ୟଥା
            len = IO_BUF_SIZE;
#endif
            len = ପଠ(bf->fd, bf->buffer, len);
            ଯଦି (len < 0)
                len = 0;
        } ଅନ୍ୟଥା {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    ଯଦି (bf->buf_ptr < bf->buf_end) {
        ଫେରନ୍ତୁ bf->buf_ptr[0];
    } ଅନ୍ୟଥା {
        bf->buf_ptr = bf->buf_end;
        ଫେରନ୍ତୁ CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା next_c(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    ଯଦି (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    ଫେରନ୍ତୁ ch;
}

/* input with '\[\r]\n' handling. */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା handle_stray_noerror(ପୂର୍ଣ୍ଣସଂଖ୍ୟା err)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch;
    ଯେତେବେଳେ ((ch = next_c()) == '\\') {
        ch = next_c();
        ଯଦି (ch == '\n') {
    newl:
            file->ଧାଡ଼ି_ଅଙ୍କ++;
        } ଅନ୍ୟଥା {
            ଯଦି (ch == '\r') {
                ch = next_c();
                ଯଦି (ch == '\n')
                    ଯାଅ newl;
                *--file->buf_ptr = '\r';
            }
            ଯଦି (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            ଫେରନ୍ତୁ *--file->buf_ptr = '\\';
        }
    }
    ଫେରନ୍ତୁ ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା handle_bs(uint8_t **p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    ଫେରନ୍ତୁ c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା handle_stray(uint8_t **p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    ଫେରନ୍ତୁ c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    ଯଦି (c == '\\')\
        c = handle_stray(&p); \
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା skip_spaces(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ch;
    --file->buf_ptr;
    କର {
        ch = ninp();
    } ଯେତେବେଳେ (isidnum_table[ch - CH_EOF] & IS_SPC);
    ଫେରନ୍ତୁ ch;
}

/* single line C++ comments */
ସ୍ଥିର uint8_t *parse_ଧାଡ଼ି_comment(uint8_t *p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ପାଇଁ(;;) {
        ପାଇଁ (;;) {
            c = *++p;
    redo:
            ଯଦି (c == '\n' || c == '\\')
                ଭାଙ୍ଗ;
            c = *++p;
            ଯଦି (c == '\n' || c == '\\')
                ଭାଙ୍ଗ;
        }
        ଯଦି (c == '\n')
            ଭାଙ୍ଗ;
        c = handle_bs(&p);
        ଯଦି (c == CH_EOF)
            ଭାଙ୍ଗ;
        ଯଦି (c != '\\')
            ଯାଅ redo;
    }
    ଫେରନ୍ତୁ p;
}

/* C comments */
ସ୍ଥିର uint8_t *parse_comment(uint8_t *p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ପାଇଁ(;;) {
        /* fast skip loop */
        ପାଇଁ(;;) {
            c = *++p;
        redo:
            ଯଦି (c == '\n' || c == '*' || c == '\\')
                ଭାଙ୍ଗ;
            c = *++p;
            ଯଦି (c == '\n' || c == '*' || c == '\\')
                ଭାଙ୍ଗ;
        }
        /* now we can handle all the cases */
        ଯଦି (c == '\n') {
            file->ଧାଡ଼ି_ଅଙ୍କ++;
        } ଅନ୍ୟଥା ଯଦି (c == '*') {
            କର {
                c = *++p;
            } ଯେତେବେଳେ (c == '*');
            ଯଦି (c == '\\')
                c = handle_bs(&p);
            ଯଦି (c == '/')
                ଭାଙ୍ଗ;
            ଯାଅ check_eof;
        } ଅନ୍ୟଥା {
            c = handle_bs(&p);
        check_eof:
            ଯଦି (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            ଯଦି (c != '\\')
                ଯାଅ redo;
        }
    }
    ଫେରନ୍ତୁ p + 1;
}

/* parse a string without interpreting escapes */
ସ୍ଥିର uint8_t *parse_pp_string(uint8_t *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sep, CString *str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ପାଇଁ(;;) {
        c = *++p;
    redo:
        ଯଦି (c == sep) {
            ଭାଙ୍ଗ;
        } ଅନ୍ୟଥା ଯଦି (c == '\\') {
            c = handle_bs(&p);
            ଯଦି (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } ଅନ୍ୟଥା ଯଦି (c == '\\') {
                ଯଦି (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                ଯଦି (c == '\\') {
                    c = handle_bs(&p);
                    ଯଦି (c == CH_EOF)
                        ଯାଅ unterminated_string;
                }
                ଯାଅ add_char;
            } ଅନ୍ୟଥା {
                ଯାଅ redo;
            }
        } ଅନ୍ୟଥା ଯଦି (c == '\n') {
        add_lf:
            ଯଦି (ACCEPT_LF_IN_STRINGS) {
                file->ଧାଡ଼ି_ଅଙ୍କ++;
                ଯାଅ add_char;
            } ଅନ୍ୟଥା ଯଦି (str) { /* not skipping */
                ଯାଅ unterminated_string;
            } ଅନ୍ୟଥା {
                //tcc_warning("missing terminating %c character", sep);
                ଫେରନ୍ତୁ p;
            }
        } ଅନ୍ୟଥା ଯଦି (c == '\r') {
            c = *++p;
            ଯଦି (c == '\\')
                c = handle_bs(&p);
            ଯଦି (c == '\n')
                ଯାଅ add_lf;
            ଯଦି (c == CH_EOF)
                ଯାଅ unterminated_string;
            ଯଦି (str)
                cstr_ccat(str, '\r');
            ଯାଅ redo;
        } ଅନ୍ୟଥା {
        add_char:
            ଯଦି (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    ଫେରନ୍ତୁ p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
ସ୍ଥିର ଶୂନ୍ୟ preprocess_skip(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, start_of_ଧାଡ଼ି, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_ଧାଡ଼ି = 1;
    in_warn_or_error = 0;
    ପାଇଁ(;;) {
        c = *p;
        ବାଛ(c) {
        ସ୍ଥିତି ' ':
        ସ୍ଥିତି '\t':
        ସ୍ଥିତି '\f':
        ସ୍ଥିତି '\v':
        ସ୍ଥିତି '\r':
            p++;
            ଜାରି;
        ସ୍ଥିତି '\n':
            file->ଧାଡ଼ି_ଅଙ୍କ++;
            p++;
            ଯାଅ redo_start;
        ସ୍ଥିତି '\\':
            c = handle_bs(&p);
            ଯଦି (c == CH_EOF)
                expect("#endif");
            ଯଦି (c == '\\')
                ++p;
            ଜାରି;
        /* skip strings */
        ସ୍ଥିତି '\"':
        ସ୍ଥିତି '\'':
            ଯଦି (in_warn_or_error)
                ଯାଅ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ଖାଲି);
            ଭାଙ୍ଗ;
        /* skip comments */
        ସ୍ଥିତି '/':
            ଯଦି (in_warn_or_error)
                ଯାଅ _default;
            ++p;
            c = handle_bs(&p);
            ଯଦି (c == '*') {
                p = parse_comment(p);
            } ଅନ୍ୟଥା ଯଦି (c == '/') {
                p = parse_ଧାଡ଼ି_comment(p);
            }
            ଜାରି;
        ସ୍ଥିତି '#':
            p++;
            ଯଦି (start_of_ଧାଡ଼ି) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                ଯଦି (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    ଯାଅ the_end;
                ଯଦି (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                ଅନ୍ୟଥା ଯଦି (tok == TOK_ENDIF)
                    a--;
                ଅନ୍ୟଥା ଯଦି( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                ଅନ୍ୟଥା ଯଦି (tok == TOK_LINEFEED)
                    ଯାଅ redo_start;
                ଅନ୍ୟଥା ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_ଧାଡ଼ି_comment(p - 1);
            }
#ଯଦି !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            ଅନ୍ୟଥା ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_ଧାଡ଼ି_comment(p - 1);
#ଅନ୍ୟଥା
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            ଭାଙ୍ଗ;
_default:
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            p++;
            ଭାଙ୍ଗ;
        }
        start_of_ଧାଡ଼ି = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#ଯଦି 0
/* return the number of additional 'ints' necessary to store the
   token */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା tok_size(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p)
{
    ବାଛ(*p) {
        /* 4 bytes */
    ସ୍ଥିତି TOK_CINT:
    ସ୍ଥିତି TOK_CUINT:
    ସ୍ଥିତି TOK_CCHAR:
    ସ୍ଥିତି TOK_LCHAR:
    ସ୍ଥିତି TOK_CFLOAT:
    ସ୍ଥିତି TOK_LINENUM:
        ଫେରନ୍ତୁ 1 + 1;
    ସ୍ଥିତି TOK_STR:
    ସ୍ଥିତି TOK_LSTR:
    ସ୍ଥିତି TOK_PPNUM:
    ସ୍ଥିତି TOK_PPSTR:
        ଫେରନ୍ତୁ 1 + 1 + (p[1] + 3) / 4;
    ସ୍ଥିତି TOK_CLONG:
    ସ୍ଥିତି TOK_CULONG:
	ଫେରନ୍ତୁ 1 + LONG_SIZE / 4;
    ସ୍ଥିତି TOK_CDOUBLE:
    ସ୍ଥିତି TOK_CLLONG:
    ସ୍ଥିତି TOK_CULLONG:
        ଫେରନ୍ତୁ 1 + 2;
    ସ୍ଥିତି TOK_CLDOUBLE:
        ଫେରନ୍ତୁ 1 + LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଫେରନ୍ତୁ 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN ଶୂନ୍ୟ tok_str_new(TokenString *s)
{
    s->str = ଖାଲି;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_ଧାଡ଼ି_ଅଙ୍କ = -1;
}

ST_FUNC TokenString *tok_str_alloc(ଶୂନ୍ୟ)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, ଆକାର *str);
    tok_str_new(str);
    ଫେରନ୍ତୁ str;
}

ST_FUNC ଶୂନ୍ୟ tok_str_free_str(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ଶୂନ୍ୟ tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା *tok_str_realloc(TokenString *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା new_size)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str, size;

    size = s->allocated_len;
    ଯଦି (size < 16)
        size = 16;
    ଯେତେବେଳେ (size < new_size)
        size = size * 2;
    ଯଦି (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
        s->allocated_len = size;
        s->str = str;
    }
    ଫେରନ୍ତୁ s->str;
}

ST_FUNC ଶୂନ୍ୟ tok_str_add(TokenString *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, *str;

    len = s->len;
    str = s->str;
    ଯଦି (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC ଶୂନ୍ୟ begin_macro(TokenString *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା alloc)
{
    str->alloc = alloc;
    str->prev = macro_ଗଦା;
    str->prev_ptr = macro_ptr;
    str->save_ଧାଡ଼ି_ଅଙ୍କ = file->ଧାଡ଼ି_ଅଙ୍କ;
    macro_ptr = str->str;
    macro_ଗଦା = str;
}

ST_FUNC ଶୂନ୍ୟ end_macro(ଶୂନ୍ୟ)
{
    TokenString *str = macro_ଗଦା;
    macro_ଗଦା = str->prev;
    macro_ptr = str->prev_ptr;
    file->ଧାଡ଼ି_ଅଙ୍କ = str->save_ଧାଡ଼ି_ଅଙ୍କ;
    ଯଦି (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } ଅନ୍ୟଥା {
        ଯଦି (str->alloc == 2)
            str->str = ଖାଲି; /* don't free */
        tok_str_free(str);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ tok_str_add2(TokenString *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, CValue *cv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    ଯଦି (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    ବାଛ(t) {
    ସ୍ଥିତି TOK_CINT:
    ସ୍ଥିତି TOK_CUINT:
    ସ୍ଥିତି TOK_CCHAR:
    ସ୍ଥିତି TOK_LCHAR:
    ସ୍ଥିତି TOK_CFLOAT:
    ସ୍ଥିତି TOK_LINENUM:
#ଯଦି LONG_SIZE == 4
    ସ୍ଥିତି TOK_CLONG:
    ସ୍ଥିତି TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_PPNUM:
    ସ୍ଥିତି TOK_PPSTR:
    ସ୍ଥିତି TOK_STR:
    ସ୍ଥିତି TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_ଶବ୍ଦଗୁଡ଼ିକ =
                1 + (cv->str.size + ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) - 1) / ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
            ଯଦି (len + nb_ଶବ୍ଦଗୁଡ଼ିକ >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_ଶବ୍ଦଗୁଡ଼ିକ + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_ଶବ୍ଦଗୁଡ଼ିକ;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CDOUBLE:
    ସ୍ଥିତି TOK_CLLONG:
    ସ୍ଥିତି TOK_CULLONG:
#ଯଦି LONG_SIZE == 8
    ସ୍ଥିତି TOK_CLONG:
    ସ୍ଥିତି TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        ଯଦି (LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ >= 3)
        str[len++] = cv->tab[2];
        ଯଦି (LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ >= 4)
        str[len++] = cv->tab[3];
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଭାଙ୍ଗ;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC ଶୂନ୍ୟ tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    ଯଦି (file->ଧାଡ଼ି_ଅଙ୍କ != s->last_ଧାଡ଼ି_ଅଙ୍କ) {
        s->last_ଧାଡ଼ି_ଅଙ୍କ = file->ଧାଡ଼ି_ଅଙ୍କ;
        cval.i = s->last_ଧାଡ଼ି_ଅଙ୍କ;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
ସ୍ଥିର ଶୂନ୍ୟ tok_str_add2_spc(TokenString *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, CValue *cv)
{
    ଯଦି (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ tok_get(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *t, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା **pp, CValue *cv)
{
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p = *pp;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, *tab;

    tab = cv->tab;
    ବାଛ(*t = *p++) {
#ଯଦି LONG_SIZE == 4
    ସ୍ଥିତି TOK_CLONG:
#endif
    ସ୍ଥିତି TOK_CINT:
    ସ୍ଥିତି TOK_CCHAR:
    ସ୍ଥିତି TOK_LCHAR:
    ସ୍ଥିତି TOK_LINENUM:
        cv->i = *p++;
        ଭାଙ୍ଗ;
#ଯଦି LONG_SIZE == 4
    ସ୍ଥିତି TOK_CULONG:
#endif
    ସ୍ଥିତି TOK_CUINT:
        cv->i = (unsigned)*p++;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CFLOAT:
	tab[0] = *p++;
	ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_STR:
    ସ୍ଥିତି TOK_LSTR:
    ସ୍ଥିତି TOK_PPNUM:
    ସ୍ଥିତି TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (ଅକ୍ଷର*)p;
        p += (cv->str.size + ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) - 1) / ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_CDOUBLE:
    ସ୍ଥିତି TOK_CLLONG:
    ସ୍ଥିତି TOK_CULLONG:
#ଯଦି LONG_SIZE == 8
    ସ୍ଥିତି TOK_CLONG:
    ସ୍ଥିତି TOK_CULONG:
#endif
        n = 2;
        ଯାଅ copy;
    ସ୍ଥିତି TOK_CLDOUBLE:
        n = LDOUBLE_ଶବ୍ଦଗୁଡ଼ିକ;
    copy:
        କର
            *tab++ = *p++;
        ଯେତେବେଳେ (--n);
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଭାଙ୍ଗ;
    }
    *pp = p;
}

#ଯଦି 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#ଅନ୍ୟଥା
# define TOK_GET(t,p,c) କର { \
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା _t = **(p); \
    ଯଦି (TOK_HAS_ମୂଲ୍ୟ(_t)) \
        tok_get(t, p, c); \
    ଅନ୍ୟଥା \
        *(t) = _t, ++*(p); \
    } ଯେତେବେଳେ (0)
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_is_equal(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *a, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *b)
{
    CValue cv;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;

    ଯଦି (!a || !b)
        ଫେରନ୍ତୁ 1;

    ଯେତେବେଳେ (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        ଯଦି (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            ଫେରନ୍ତୁ 0;
    }
    ଫେରନ୍ତୁ !(*a || *b);
}

/* defines handling */
ST_INLN ଶୂନ୍ୟ define_ଠେଲ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_type, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_ଗଦା, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    ଯଦି (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ଖାଲି));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC ଶୂନ୍ୟ define_undef(Sym *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = s->v;
    ଯଦି (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = ଖାଲି;
}

ST_INLN Sym *define_find(ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    v -= TOK_IDENT;
    ଯଦି ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        ଫେରନ୍ତୁ ଖାଲି;
    ଫେରନ୍ତୁ table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC ଶୂନ୍ୟ free_defines(Sym *b)
{
    ଯେତେବେଳେ (define_ଗଦା != b) {
        Sym *ଶୀର୍ଷ = define_ଗଦା;
        define_ଗଦା = ଶୀର୍ଷ->prev;
        tok_str_free_str(ଶୀର୍ଷ->d);
        define_undef(ଶୀର୍ଷ);
        sym_free(ଶୀର୍ଷ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
ସ୍ଥିର ଶୂନ୍ୟ maybe_run_test(TCCState *s)
{
    ଅଚଳ ଅକ୍ଷର *p;
    ଯଦି (s->include_ଗଦା_ptr != s->include_ଗଦା)
        ଫେରନ୍ତୁ;
    p = get_tok_str(tok, ଖାଲି);
    ଯଦି (0 != memcmp(p, "test_", 5))
        ଫେରନ୍ତୁ;
    ଯଦି (0 != --s->run_test)
        ଫେରନ୍ତୁ;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ଠେଲ(tok, MACRO_OBJ, ଖାଲି, ଖାଲି);
}

ST_FUNC ଶୂନ୍ୟ skip_to_eol(ପୂର୍ଣ୍ଣସଂଖ୍ୟା warn)
{
    ଯଦି (tok == TOK_LINEFEED)
        ଫେରନ୍ତୁ;
    ଯଦି (warn)
        tcc_warning("extra tokens after directive");
    ଯେତେବେଳେ (macro_ଗଦା)
        end_macro();
    file->buf_ptr = parse_ଧାଡ଼ି_comment(file->buf_ptr - 1);
    next_nomacro();
}

ସ୍ଥିର CachedInclude *
ସନ୍ଧାନ_cached_include(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା add);

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା parse_include(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା do_next, ପୂର୍ଣ୍ଣସଂଖ୍ୟା test)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, i;
    ଅକ୍ଷର name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    ଯଦି (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, ଆକାର name, tokcstr.data, i);
        next_nomacro();
    } ଅନ୍ୟଥା {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        ପାଇଁ (;;) {
            next();
            p = name, i = strlen(p) - 1;
            ଯଦି (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                ଭାଙ୍ଗ;
            ଯଦି (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, ଆକାର name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    ଯଦି (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    ପାଇଁ (;;) {
        ++i;
        ଯଦି (i == 0) {
            /* check absolute include path */
            ଯଦି (!IS_ABSPATH(name))
                ଜାରି;
            buf[0] = '\0';
        } ଅନ୍ୟଥା ଯଦି (i == 1) {
            /* search in file's dir if "header.h" */
            ଯଦି (c != '\"')
                ଜାରି;
            p = file->true_filename;
            pstrncpy(buf, ଆକାର buf, p, tcc_basename(p) - p);
        } ଅନ୍ୟଥା {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = i - 2, k = j - s1->nb_include_paths;
            ଯଦି (k < 0)
                p = s1->include_paths[j];
            ଅନ୍ୟଥା ଯଦି (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            ଅନ୍ୟଥା ଯଦି (test)
                ଫେରନ୍ତୁ 0;
            ଅନ୍ୟଥା
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, ଆକାର buf, p);
            pstrcat(buf, ଆକାର buf, "/");
        }
        pstrcat(buf, ଆକାର buf, name);
        e = ସନ୍ଧାନ_cached_include(s1, buf, 0);
        ଯଦି (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            ଯଦି ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(s1->include_ଗଦା_ptr - s1->include_ଗଦା), "", buf);
            ଫେରନ୍ତୁ 1;
        }
        ଯଦି (tcc_open(s1, buf) >= 0)
            ଭାଙ୍ଗ;
    }

    ଯଦି (test) {
        tcc_close();
    } ଅନ୍ୟଥା {
        ଯଦି (s1->include_ଗଦା_ptr >= s1->include_ଗଦା + INCLUDE_ଗଦା_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ଗଦା_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        ଯଦି (s1->gen_deps) {
            BufferedFile *bf = file;
            ଯେତେବେଳେ (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            ଯଦି (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    ଫେରନ୍ତୁ 1;
}

/* eval an expression for #if/#elif */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା ପଦସମଷ୍ଟି_preprocess(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, t;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_ପଦସମଷ୍ଟି = 1;
    ଯେତେବେଳେ (1) {
        next(); /* do macro subst */
        t = tok;
        ଯଦି (tok < TOK_IDENT) {
            ଯଦି (tok == TOK_LINEFEED || tok == TOK_EOF)
                ଭାଙ୍ଗ;
            ଯଦି (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } ଅନ୍ୟଥା ଯଦି (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            ଯଦି (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            ଯଦି (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            ଯଦି (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            ଯଦି (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            ଯଦି (t == '(') {
                next();
                ଯଦି (tok != ')')
                    expect("')'");
            }
            ଯାଅ c_ସଂଖ୍ୟା;
        } ଅନ୍ୟଥା ଯଦି (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    ଯଦି (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            ଯଦି (tok != ')')
                expect("')'");
            ଯାଅ c_ସଂଖ୍ୟା;
        } ଅନ୍ୟଥା {
            /* if undefined macro, replace with zero */
            c = 0;
        c_ସଂଖ୍ୟା:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    ଯଦି (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_ପଦସମଷ୍ଟି = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = ପଦସମଷ୍ଟି_const();
    ଯଦି (tok != TOK_EOF)
        tcc_error("...");
    pp_ପଦସମଷ୍ଟି = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    ଫେରନ୍ତୁ c != 0;
}

ST_FUNC ଶୂନ୍ୟ pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_ପଦସମଷ୍ଟି, 0));
    macro_ptr = macro_ଗଦା->str;
    ଯେତେବେଳେ (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC ଶୂନ୍ୟ parse_define(ଶୂନ୍ୟ)
{
    Sym *s, *first, **ps;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, t, varg, is_vaargs, t0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    ଯଦି (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = ଖାଲି;
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
    ଯଦି (tok == '(') {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        ଯଦି (tok != ')') ପାଇଁ (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            ଯଦି (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } ଅନ୍ୟଥା ଯଦି (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            ଯଦି (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ଗଦା, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            ଯଦି (tok == ')')
                ଭାଙ୍ଗ;
            ଯଦି (tok != ',' || is_vaargs)
                ଯାଅ bad_list;
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
    ଯେତେବେଳେ (tok != TOK_LINEFEED && tok != TOK_EOF) {
        ଯଦି (is_space(tok)) {
            str.need_spc |= 1;
        } ଅନ୍ୟଥା {
            ଯଦି (TOK_TWOSHARPS == tok) {
                ଯଦି (0 == t0)
                    ଯାଅ bad_twosharp;
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
    ଯଦି (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ଠେଲ(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

ସ୍ଥିର CachedInclude *ସନ୍ଧାନ_cached_include(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା add)
{
    ଅଚଳ ଅକ୍ଷର *s, *basename;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା h;
    CachedInclude *e;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    ଯେତେବେଳେ ((c = (unsigned ଅକ୍ଷର)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#ଅନ୍ୟଥା
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    ପାଇଁ(;;) {
        ଯଦି (i == 0)
            ଭାଙ୍ଗ;
        e = s1->cached_includes[i - 1];
        ଯଦି (0 == PATHCMP(filename, e->filename))
            ଫେରନ୍ତୁ e;
        ଯଦି (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            ଫେରନ୍ତୁ e;
        i = e->hash_next;
    }
    ଯଦି (!add)
        ଫେରନ୍ତୁ ଖାଲି;

    e = tcc_malloc(ଆକାର(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    ଫେରନ୍ତୁ e;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pragma_parse(TCCState *s1)
{
    next_nomacro();
    ଯଦି (tok == TOK_ଠେଲ_macro || tok == TOK_କାଢ଼_macro) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = tok, v;
        Sym *s;

        ଯଦି (next(), tok != '(')
            ଯାଅ pragma_err;
        ଯଦି (next(), tok != TOK_STR)
            ଯାଅ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        ଯଦି (next(), tok != ')')
            ଯାଅ pragma_err;
        ଯଦି (t == TOK_ଠେଲ_macro) {
            ଯେତେବେଳେ (ଖାଲି == (s = define_find(v)))
                define_ଠେଲ(v, 0, ଖାଲି, ଖାଲି);
            s->type.ref = s; /* set push boundary */
        } ଅନ୍ୟଥା {
            ପାଇଁ (s = define_ଗଦା; s; s = s->prev)
                ଯଦି (s->v == v && s->type.ref == s) {
                    s->type.ref = ଖାଲି;
                    ଭାଙ୍ଗ;
                }
        }
        ଯଦି (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : ଖାଲି;
        ଅନ୍ୟଥା
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } ଅନ୍ୟଥା ଯଦି (tok == TOK_once) {
        ସନ୍ଧାନ_cached_include(s1, file->true_filename, 1)->once = 1;

    } ଅନ୍ୟଥା ଯଦି (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        ଫେରନ୍ତୁ 1;

    } ଅନ୍ୟଥା ଯଦି (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        ଯଦି (tok == TOK_ASM_କାଢ଼) {
            next();
            ଯଦି (s1->pack_ଗଦା_ptr <= s1->pack_ଗଦା) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ଗଦା_ptr--;
        } ଅନ୍ୟଥା {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା val = 0;
            ଯଦି (tok != ')') {
                ଯଦି (tok == TOK_ASM_ଠେଲ) {
                    next();
                    ଯଦି (s1->pack_ଗଦା_ptr >= s1->pack_ଗଦା + PACK_ଗଦା_SIZE - 1)
                        ଯାଅ stk_error;
                    val = *s1->pack_ଗଦା_ptr++;
                    ଯଦି (tok != ',')
                        ଯାଅ pack_set;
                    next();
                }
                ଯଦି (tok != TOK_CINT)
                    ଯାଅ pragma_err;
                val = tokc.i;
                ଯଦି (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    ଯାଅ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_ଗଦା_ptr = val;
        }
        ଯଦି (tok != ')')
            ଯାଅ pragma_err;

    } ଅନ୍ୟଥା ଯଦି (tok == TOK_comment) {
        ଅକ୍ଷର *p; ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        ଯଦି (tok != TOK_STR)
            ଯାଅ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        ଯଦି (tok != ')')
            ଯାଅ pragma_err;
        ଯଦି (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } ଅନ୍ୟଥା {
            ଯଦି (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } ଅନ୍ୟଥା {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        ଫେରନ୍ତୁ 0;
    }
    next();
    ଫେରନ୍ତୁ 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC ଶୂନ୍ୟ tccpp_putfile(ଅଚଳ ଅକ୍ଷର *filename)
{
    ଅକ୍ଷର buf[1024];
    buf[0] = 0;
    ଯଦି (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, ଆକାର buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, ଆକାର buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    ଯଦି (0 == strcmp(file->filename, buf))
        ଫେରନ୍ତୁ;
    //printf("new file '%s'\n", buf);
    ଯଦି (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, ଆକାର file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC ଶୂନ୍ୟ preprocess(ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_bof)
{
    TCCState *s1 = tcc_state;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, n, saved_parse_flags;
    ଅକ୍ଷର buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_ଅଙ୍କ
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    ବାଛ(tok) {
    ସ୍ଥିତି TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        ଯଦି (s)
            define_undef(s);
        next_nomacro();
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_INCLUDE:
    ସ୍ଥିତି TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        ଯାଅ the_end;
    ସ୍ଥିତି TOK_IFNDEF:
        c = 1;
        ଯାଅ do_ifdef;
    ସ୍ଥିତି TOK_IF:
        c = ପଦସମଷ୍ଟି_preprocess(s1);
        ଯାଅ do_if;
    ସ୍ଥିତି TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        ଯଦି (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        ଯଦି (is_bof) {
            ଯଦି (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, ଖାଲି));
#endif
                file->ifndef_macro = tok;
            }
        }
        ଯଦି (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        ଯଦି (s1->ifdef_ଗଦା_ptr >= s1->ifdef_ଗଦା + IFDEF_ଗଦା_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ଗଦା_ptr++ = c;
        ଯାଅ test_skip;
    ସ୍ଥିତି TOK_ELSE:
        next_nomacro();
        ଯଦି (s1->ifdef_ଗଦା_ptr == s1->ifdef_ଗଦା)
            tcc_error("#else without matching #if");
        ଯଦି (s1->ifdef_ଗଦା_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ଗଦା_ptr[-1] ^= 3);
        ଯାଅ test_else;
    ସ୍ଥିତି TOK_ELIF:
        ଯଦି (s1->ifdef_ଗଦା_ptr == s1->ifdef_ଗଦା)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ଗଦା_ptr[-1];
        ଯଦି (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        ଯଦି (c == 1) {
            skip_to_eol(0);
            c = 0;
        } ଅନ୍ୟଥା {
            c = ପଦସମଷ୍ଟି_preprocess(s1);
            s1->ifdef_ଗଦା_ptr[-1] = c;
        }
    test_else:
        ଯଦି (s1->ifdef_ଗଦା_ptr == file->ifdef_ଗଦା_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        ଯଦି (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            ଯାଅ redo;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_ENDIF:
        next_nomacro();
        ଯଦି (s1->ifdef_ଗଦା_ptr <= file->ifdef_ଗଦା_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ଗଦା_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        ଯଦି (file->ifndef_macro &&
            s1->ifdef_ଗଦା_ptr == file->ifdef_ଗଦା_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_ଧାଡ଼ି:
        parse_flags &= ~PARSE_FLAG_TOK_ଅଙ୍କ;
        next();
        ଯଦି (tok != TOK_PPNUM) {
    ଧାଡ଼ି_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        ଯାଅ ଧାଡ଼ି_ଅଙ୍କ_2;
    ସ୍ଥିତି TOK_PPNUM:
        ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE)
            ଯାଅ ignore;
        c = 0; /* no error with extra tokens */
    ଧାଡ଼ି_ଅଙ୍କ_2:
        ପାଇଁ (n = 0, q = tokc.str.data; *q; ++q) {
            ଯଦି (!isnum(*q))
                ଯାଅ ଧାଡ଼ି_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        ଯଦି (tok != TOK_LINEFEED) {
            ଯଦି (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                ଯାଅ ଧାଡ଼ି_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        ଯଦି (file->fd > 0)
            total_ଧାଡ଼ିଗୁଡ଼ିକ += file->ଧାଡ଼ି_ଅଙ୍କ - n;
        file->ଧାଡ଼ି_ଅଙ୍କ = n;
        ଭାଙ୍ଗ;

    ସ୍ଥିତି TOK_ERROR:
    ସ୍ଥିତି TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        ଯେତେବେଳେ (c != '\n' && c != CH_EOF) {
            ଯଦି ((q - buf) < ଆକାର(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        ଯଦି (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        ଅନ୍ୟଥା
            tcc_warning("#warning %s", buf);
        next_nomacro();
        ଭାଙ୍ଗ;
    }
    ସ୍ଥିତି TOK_PRAGMA:
        ଯଦି (!pragma_parse(s1))
            ଯାଅ ignore;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି TOK_LINEFEED:
        ଯାଅ the_end;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        /* ignore gas line comment in an 'S' file. */
        ଯଦି (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            ଯାଅ ignore;
        ଯଦି (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            ଯାଅ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        ଯାଅ the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
ସ୍ଥିର ଶୂନ୍ୟ parse_escape_string(CString *outstr, ଅଚଳ uint8_t *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_long)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, n, i;
    ଅଚଳ uint8_t *p;

    p = buf;
    ପାଇଁ(;;) {
        c = *p;
        ଯଦି (c == '\0')
            ଭାଙ୍ଗ;
        ଯଦି (c == '\\') {
            p++;
            /* escape */
            c = *p;
            ବାଛ(c) {
            ସ୍ଥିତି '0': ସ୍ଥିତି '1': ସ୍ଥିତି '2': ସ୍ଥିତି '3':
            ସ୍ଥିତି '4': ସ୍ଥିତି '5': ସ୍ଥିତି '6': ସ୍ଥିତି '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                ଯଦି (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    ଯଦି (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                ଯାଅ add_char_nonext;
            ସ୍ଥିତି 'x': i = 0; ଯାଅ parse_hex_or_ucn;
            ସ୍ଥିତି 'u': i = 4; ଯାଅ parse_hex_or_ucn;
            ସ୍ଥିତି 'U': i = 8; ଯାଅ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                କର {
                    c = *p;
                    ଯଦି (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    ଅନ୍ୟଥା ଯଦି (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    ଅନ୍ୟଥା ଯଦି (isnum(c))
                        c = c - '0';
                    ଅନ୍ୟଥା ଯଦି (i >= 0)
                        expect("more hex digits in universal-character-name");
                    ଅନ୍ୟଥା
                        ଯାଅ add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } ଯେତେବେଳେ (--i);
		ଯଦି (is_long) {
    add_hex_or_ucn:
                    c = n;
		    ଯାଅ add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ଜାରି;
            ସ୍ଥିତି 'a':
                c = '\a';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'b':
                c = '\b';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'f':
                c = '\f';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'n':
                c = '\n';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'r':
                c = '\r';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 't':
                c = '\t';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'v':
                c = '\v';
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'e':
                ଯଦି (!gnu_ext)
                    ଯାଅ invalid_escape;
                c = 27;
                ଭାଙ୍ଗ;
            ସ୍ଥିତି '\'':
            ସ୍ଥିତି '\"':
            ସ୍ଥିତି '\\': 
            ସ୍ଥିତି '?':
                ଭାଙ୍ଗ;
            ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            invalid_escape:
                ଯଦି (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                ଅନ୍ୟଥା
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                ଭାଙ୍ଗ;
            }
        } ଅନ୍ୟଥା ଯଦି (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            ପୂର୍ଣ୍ଣସଂଖ୍ୟା cont; /* count of continuation bytes */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା skip; /* how many bytes should skip when error occurred */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

            /* decode leading byte */
            ଯଦି (c < 0xC2) {
	            skip = 1; ଯାଅ invalid_utf8_sequence;
            } ଅନ୍ୟଥା ଯଦି (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } ଅନ୍ୟଥା ଯଦି (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } ଅନ୍ୟଥା ଯଦି (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } ଅନ୍ୟଥା {
	            skip = 1; ଯାଅ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            ପାଇଁ (i = 1; i <= cont; i++) {
                ପୂର୍ଣ୍ଣସଂଖ୍ୟା l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                ଯଦି (i == 1) {
                    ବାଛ (c) {
                    ସ୍ଥିତି 0xE0: l = 0xA0; ଭାଙ୍ଗ;
                    ସ୍ଥିତି 0xED: h = 0x9F; ଭାଙ୍ଗ;
                    ସ୍ଥିତି 0xF0: l = 0x90; ଭାଙ୍ଗ;
                    ସ୍ଥିତି 0xF4: h = 0x8F; ଭାଙ୍ଗ;
                    }
                }

                ଯଦି (p[i] < l || p[i] > h) {
                    skip = i; ଯାଅ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            ଯାଅ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            ଯାଅ add_char_nonext;

        }
        p++;
    add_char_nonext:
        ଯଦି (!is_long)
            cstr_ccat(outstr, c);
        ଅନ୍ୟଥା {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            ଯଦି (c < 0x10000) {
                cstr_wccat(outstr, c);
            } ଅନ୍ୟଥା {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#ଅନ୍ୟଥା
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    ଯଦି (!is_long)
        cstr_ccat(outstr, '\0');
    ଅନ୍ୟଥା
        cstr_wccat(outstr, '\0');
}

ସ୍ଥିର ଶୂନ୍ୟ parse_string(ଅଚଳ ଅକ୍ଷର *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା len)
{
    uint8_t buf[1000], *p = buf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_long, sep;

    ଯଦି ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    ଯଦି (len >= ଆକାର buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    ଯଦି (p != buf)
        tcc_free(p);

    ଯଦି (sep == '\'') {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା char_size, i, n, c;
        /* XXX: make it portable */
        ଯଦି (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        ଅନ୍ୟଥା
            tok = TOK_LCHAR, char_size = ଆକାର(nwchar_t);
        n = tokcstr.size / char_size - 1;
        ଯଦି (n < 1)
            tcc_error("empty character constant");
        ଯଦି (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        ପାଇଁ (c = i = 0; i < n; ++i) {
            ଯଦି (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            ଅନ୍ୟଥା
                c = (c << 8) | ((ଅକ୍ଷର *)tokcstr.data)[i];
        }
        tokc.i = c;
    } ଅନ୍ୟଥା {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        ଯଦି (!is_long)
            tok = TOK_STR;
        ଅନ୍ୟଥା
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା bn_lshift(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bn, ପୂର୍ଣ୍ଣସଂଖ୍ୟା shift, ପୂର୍ଣ୍ଣସଂଖ୍ୟା or_val)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
    ଯଦି (bn[BN_SIZE - 1] >> (32 - shift))
	ଫେରନ୍ତୁ shift;
    ପାଇଁ(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    ଫେରନ୍ତୁ 0;
}

ସ୍ଥିର ଶୂନ୍ୟ bn_zero(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *bn)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
ସ୍ଥିର ଶୂନ୍ୟ parse_ସଂଖ୍ୟା(ଅଚଳ ଅକ୍ଷର *p)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, t, shift, frac_bits, s, exp_val, ch;
    ଅକ୍ଷର *q;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା bn[BN_SIZE];
    long ଦ୍ୱିଗୁଣ d;

    /*ସଂଖ୍ୟା*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    ଯଦି (t == '.') {
        ଯାଅ float_frac_parse;
    } ଅନ୍ୟଥା ଯଦି (t == '0') {
        ଯଦି (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } ଅନ୍ୟଥା ଯଦି (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    ଯେତେବେଳେ (1) {
        ଯଦି (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        ଅନ୍ୟଥା ଯଦି (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        ଅନ୍ୟଥା ଯଦି (isnum(ch))
            t = ch - '0';
        ଅନ୍ୟଥା
            ଭାଙ୍ଗ;
        ଯଦି (t >= b)
            ଭାଙ୍ଗ;
        ଯଦି (q >= token_buf + STRING_MAX_SIZE) {
        ଅଙ୍କ_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    ଯଦି (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        ଯଦି (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            ଯଦି (b == 16)
                shift = 4;
            ଅନ୍ୟଥା 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            ଯେତେବେଳେ (1) {
                t = *q++;
                ଯଦି (t == '\0') {
                    ଭାଙ୍ଗ;
                } ଅନ୍ୟଥା ଯଦି (t >= 'a') {
                    t = t - 'a' + 10;
                } ଅନ୍ୟଥା ଯଦି (t >= 'A') {
                    t = t - 'A' + 10;
                } ଅନ୍ୟଥା {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            ଯଦି (ch == '.') {
                ch = *p++;
                ଯେତେବେଳେ (1) {
                    t = ch;
                    ଯଦି (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } ଅନ୍ୟଥା ଯଦି (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } ଅନ୍ୟଥା ଯଦି (t >= '0' && t <= '9') {
                        t = t - '0';
                    } ଅନ୍ୟଥା {
                        ଭାଙ୍ଗ;
                    }
                    ଯଦି (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            ଯଦି (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            ଯଦି (ch == '+') {
                ch = *p++;
            } ଅନ୍ୟଥା ଯଦି (ch == '-') {
                s = -1;
                ch = *p++;
            }
            ଯଦି (ch < '0' || ch > '9')
                expect("exponent digits");
            ଯେତେବେଳେ (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		ଯଦି (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long ଦ୍ୱିଗୁଣ)bn[3] * 79228162514264337593543950336.0L +
	        (long ଦ୍ୱିଗୁଣ)bn[2] * 18446744073709551616.0L +
	        (long ଦ୍ୱିଗୁଣ)bn[1] * 4294967296.0L +
	        (long ଦ୍ୱିଗୁଣ)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            ଯଦି (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (ଦଶମିକ)d;
            } ଅନ୍ୟଥା ଯଦି (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } ଅନ୍ୟଥା {
                tok = TOK_CDOUBLE;
                tokc.d = (ଦ୍ୱିଗୁଣ)d;
            }
        } ଅନ୍ୟଥା {
            /* decimal floats */
            ଯଦି (ch == '.') {
                ଯଦି (q >= token_buf + STRING_MAX_SIZE)
                    ଯାଅ ଅଙ୍କ_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                ଯେତେବେଳେ (ch >= '0' && ch <= '9') {
                    ଯଦି (q >= token_buf + STRING_MAX_SIZE)
                        ଯାଅ ଅଙ୍କ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            ଯଦି (ch == 'e' || ch == 'E') {
                ଯଦି (q >= token_buf + STRING_MAX_SIZE)
                    ଯାଅ ଅଙ୍କ_too_long;
                *q++ = ch;
                ch = *p++;
                ଯଦି (ch == '-' || ch == '+') {
                    ଯଦି (q >= token_buf + STRING_MAX_SIZE)
                        ଯାଅ ଅଙ୍କ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                ଯଦି (ch < '0' || ch > '9')
                    expect("exponent digits");
                ଯେତେବେଳେ (ch >= '0' && ch <= '9') {
                    ଯଦି (q >= token_buf + STRING_MAX_SIZE)
                        ଯାଅ ଅଙ୍କ_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            ଯଦି (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ଖାଲି);
            } ଅନ୍ୟଥା ଯଦି (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ଖାଲି);
            } ଅନ୍ୟଥା {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ଖାଲି);
            }
        }
    } ଅନ୍ୟଥା {
        unsigned long long n, n1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା lcount, ucount, ov = 0;
        ଅଚଳ ଅକ୍ଷର *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        ଯଦି (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        ଯେତେବେଳେ(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            ଯଦି (t == '\0')
                ଭାଙ୍ଗ;
            ଅନ୍ୟଥା ଯଦି (t >= 'a')
                t = t - 'a' + 10;
            ଅନ୍ୟଥା ଯଦି (t >= 'A')
                t = t - 'A' + 10;
            ଅନ୍ୟଥା
                t = t - '0';
            ଯଦି (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            ଯଦି (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        ପାଇଁ(;;) {
            t = toup(ch);
            ଯଦି (t == 'L') {
                ଯଦି (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                ଯଦି (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } ଅନ୍ୟଥା ଯଦି (t == 'U') {
                ଯଦି (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } ଅନ୍ୟଥା {
                ଭାଙ୍ଗ;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        ଯଦି (pp_ପଦସମଷ୍ଟି)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        ଯଦି (ucount == 0 && b == 10) {
            ଯଦି (lcount <= (LONG_SIZE == 4)) {
                ଯଦି (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            ଯଦି (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } ଅନ୍ୟଥା {
            ଯଦି (lcount <= (LONG_SIZE == 4)) {
                ଯଦି (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                ଅନ୍ୟଥା ଯଦି (n >= 0x80000000U)
                    ucount = 1;
            }
            ଯଦି (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        ଯଦି (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	ଯଦି (lcount) {
            tok = TOK_CLONG;
            ଯଦି (lcount == 2)
                tok = TOK_CLLONG;
	}
	ଯଦି (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    ଯଦି (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    ସ୍ଥିତି c1:                                    \
        PEEKC(c, p);                            \
        ଯଦି (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } ଅନ୍ୟଥା {                                \
            tok = tok1;                         \
        }                                       \
        ଭାଙ୍ଗ;

/* return next token without macro substitution */
ସ୍ଥିର ଶୂନ୍ୟ next_nomacro(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    ବାଛ(c) {
    ସ୍ଥିତି ' ':
    ସ୍ଥିତି '\t':
        tok = c;
        p++;
 maybe_space:
        ଯଦି (parse_flags & PARSE_FLAG_SPACES)
            ଯାଅ keep_tok_flags;
        ଯେତେବେଳେ (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        ଯାଅ redo_no_start;
    ସ୍ଥିତି '\f':
    ସ୍ଥିତି '\v':
    ସ୍ଥିତି '\r':
        p++;
        ଯାଅ redo_no_start;
    ସ୍ଥିତି '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        ଯଦି (c == '\\')
            ଯାଅ parse_simple;
        ଯଦି (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            ଯଦି (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                ଯାଅ maybe_newline;
            } ଅନ୍ୟଥା ଯଦି (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } ଅନ୍ୟଥା ଯଦି (s1->ifdef_ଗଦା_ptr != file->ifdef_ଗଦା_ptr) {
                tcc_error("missing #endif");
            } ଅନ୍ୟଥା ଯଦି (s1->include_ଗଦା_ptr == s1->include_ଗଦା) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } ଅନ୍ୟଥା {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                ଯଦି (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ଖାଲି));
#endif
                    ସନ୍ଧାନ_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ଗଦା_ptr--;
                p = file->buf_ptr;
                ଯାଅ maybe_newline;
            }
        } ଅନ୍ୟଥା {
            ଯାଅ redo_no_start;
        }
        ଭାଙ୍ଗ;

    ସ୍ଥିତି '\n':
        file->ଧାଡ଼ି_ଅଙ୍କ++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        ଯଦି (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            ଯାଅ redo_no_start;
        tok = TOK_LINEFEED;
        ଯାଅ keep_tok_flags;

    ସ୍ଥିତି '#':
        /* XXX: simplify */
        PEEKC(c, p);
        ଯଦି ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            ଯାଅ maybe_newline;
        } ଅନ୍ୟଥା {
            ଯଦି (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } ଅନ୍ୟଥା {
#ଯଦି !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_ଧାଡ଼ି_comment(p - 1);
                    ଯାଅ redo_no_start;
                } ଅନ୍ୟଥା
#endif
                {
                    tok = '#';
                }
            }
        }
        ଭାଙ୍ଗ;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    ସ୍ଥିତି '$':
        ଯଦି (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            ଯାଅ parse_simple;

    ସ୍ଥିତି 'a': ସ୍ଥିତି 'b': ସ୍ଥିତି 'c': ସ୍ଥିତି 'd':
    ସ୍ଥିତି 'e': ସ୍ଥିତି 'f': ସ୍ଥିତି 'g': ସ୍ଥିତି 'h':
    ସ୍ଥିତି 'i': ସ୍ଥିତି 'j': ସ୍ଥିତି 'k': ସ୍ଥିତି 'l':
    ସ୍ଥିତି 'm': ସ୍ଥିତି 'n': ସ୍ଥିତି 'o': ସ୍ଥିତି 'p':
    ସ୍ଥିତି 'q': ସ୍ଥିତି 'r': ସ୍ଥିତି 's': ସ୍ଥିତି 't':
    ସ୍ଥିତି 'u': ସ୍ଥିତି 'v': ସ୍ଥିତି 'w': ସ୍ଥିତି 'x':
    ସ୍ଥିତି 'y': ସ୍ଥିତି 'z': 
    ସ୍ଥିତି 'A': ସ୍ଥିତି 'B': ସ୍ଥିତି 'C': ସ୍ଥିତି 'D':
    ସ୍ଥିତି 'E': ସ୍ଥିତି 'F': ସ୍ଥିତି 'G': ସ୍ଥିତି 'H':
    ସ୍ଥିତି 'I': ସ୍ଥିତି 'J': ସ୍ଥିତି 'K': 
    ସ୍ଥିତି 'M': ସ୍ଥିତି 'N': ସ୍ଥିତି 'O': ସ୍ଥିତି 'P':
    ସ୍ଥିତି 'Q': ସ୍ଥିତି 'R': ସ୍ଥିତି 'S': ସ୍ଥିତି 'T':
    ସ୍ଥିତି 'U': ସ୍ଥିତି 'V': ସ୍ଥିତି 'W': ସ୍ଥିତି 'X':
    ସ୍ଥିତି 'Y': ସ୍ଥିତି 'Z': 
    ସ୍ଥିତି '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        ଯେତେବେଳେ (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_ଅଙ୍କ))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        ଯଦି (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            ପାଇଁ(;;) {
                ts = *pts;
                ଯଦି (!ts)
                    ଭାଙ୍ଗ;
                ଯଦି (ts->len == len && !memcmp(ts->str, p1, len))
                    ଯାଅ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (ଅକ୍ଷର *) p1, len);
        token_found: ;
        } ଅନ୍ୟଥା {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (ଅକ୍ଷର *) p1, len);
            p--;
            PEEKC(c, p);
            ଯେତେବେଳେ (isidnum_table[c - CH_EOF] & (IS_ID|IS_ଅଙ୍କ))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 'L':
        t = p[1];
        ଯଦି (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            ଯଦି (c == '\'' || c == '\"') {
                is_long = 1;
                ଯାଅ str_const;
            }
            *--p = c = 'L';
        }
        ଯାଅ parse_ident_fast;

    ସ୍ଥିତି '0': ସ୍ଥିତି '1': ସ୍ଥିତି '2': ସ୍ଥିତି '3':
    ସ୍ଥିତି '4': ସ୍ଥିତି '5': ସ୍ଥିତି '6': ସ୍ଥିତି '7':
    ସ୍ଥିତି '8': ସ୍ଥିତି '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_ଅଙ୍କ:
        cstr_reset(&tokcstr);
        ପାଇଁ(;;) {
            cstr_ccat(&tokcstr, t);
            ଯଦି (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_ଅଙ୍କ))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((ଅକ୍ଷର*)tokcstr.data)[0] == '0'
                                && toup(((ଅକ୍ଷର*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                ଭାଙ୍ଗ;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        ଭାଙ୍ଗ;

    ସ୍ଥିତି '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        ଯଦି (isnum(c)) {
            t = '.';
            ଯାଅ parse_ଅଙ୍କ;
        } ଅନ୍ୟଥା ଯଦି ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_ଅଙ୍କ))) {
            *--p = c = '.';
            ଯାଅ parse_ident_fast;
        } ଅନ୍ୟଥା ଯଦି (c == '.') {
            PEEKC(c, p);
            ଯଦି (c == '.') {
                p++;
                tok = TOK_DOTS;
            } ଅନ୍ୟଥା {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } ଅନ୍ୟଥା {
            tok = '.';
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '\'':
    ସ୍ଥିତି '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        ଯଦି (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        ଭାଙ୍ଗ;

    ସ୍ଥିତି '<':
        PEEKC(c, p);
        ଯଦି (c == '=') {
            p++;
            tok = TOK_LE;
        } ଅନ୍ୟଥା ଯଦି (c == '<') {
            PEEKC(c, p);
            ଯଦି (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } ଅନ୍ୟଥା {
                tok = TOK_SHL;
            }
        } ଅନ୍ୟଥା {
            tok = TOK_LT;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି '>':
        PEEKC(c, p);
        ଯଦି (c == '=') {
            p++;
            tok = TOK_GE;
        } ଅନ୍ୟଥା ଯଦି (c == '>') {
            PEEKC(c, p);
            ଯଦି (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } ଅନ୍ୟଥା {
                tok = TOK_SAR;
            }
        } ଅନ୍ୟଥା {
            tok = TOK_GT;
        }
        ଭାଙ୍ଗ;
        
    ସ୍ଥିତି '&':
        PEEKC(c, p);
        ଯଦି (c == '&') {
            p++;
            tok = TOK_LAND;
        } ଅନ୍ୟଥା ଯଦି (c == '=') {
            p++;
            tok = TOK_A_AND;
        } ଅନ୍ୟଥା {
            tok = '&';
        }
        ଭାଙ୍ଗ;
        
    ସ୍ଥିତି '|':
        PEEKC(c, p);
        ଯଦି (c == '|') {
            p++;
            tok = TOK_LOR;
        } ଅନ୍ୟଥା ଯଦି (c == '=') {
            p++;
            tok = TOK_A_OR;
        } ଅନ୍ୟଥା {
            tok = '|';
        }
        ଭାଙ୍ଗ;

    ସ୍ଥିତି '+':
        PEEKC(c, p);
        ଯଦି (c == '+') {
            p++;
            tok = TOK_INC;
        } ଅନ୍ୟଥା ଯଦି (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } ଅନ୍ୟଥା {
            tok = '+';
        }
        ଭାଙ୍ଗ;
        
    ସ୍ଥିତି '-':
        PEEKC(c, p);
        ଯଦି (c == '-') {
            p++;
            tok = TOK_DEC;
        } ଅନ୍ୟଥା ଯଦି (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } ଅନ୍ୟଥା ଯଦି (c == '>') {
            p++;
            tok = TOK_ARROW;
        } ଅନ୍ୟଥା {
            tok = '-';
        }
        ଭାଙ୍ଗ;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    ସ୍ଥିତି '/':
        PEEKC(c, p);
        ଯଦି (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            ଯାଅ maybe_space;
        } ଅନ୍ୟଥା ଯଦି (c == '/') {
            p = parse_ଧାଡ଼ି_comment(p);
            tok = ' ';
            ଯାଅ maybe_space;
        } ଅନ୍ୟଥା ଯଦି (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } ଅନ୍ୟଥା {
            tok = '/';
        }
        ଭାଙ୍ଗ;
        
        /* simple tokens */
    ସ୍ଥିତି '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_ଧାଡ଼ି_comment(p);
            ଯାଅ redo_no_start;
        }
#endif
    ସ୍ଥିତି '(':
    ସ୍ଥିତି ')':
    ସ୍ଥିତି '[':
    ସ୍ଥିତି ']':
    ସ୍ଥିତି '{':
    ସ୍ଥିତି '}':
    ସ୍ଥିତି ',':
    ସ୍ଥିତି ';':
    ସ୍ଥିତି ':':
    ସ୍ଥିତି '?':
    ସ୍ଥିତି '~':
    parse_simple:
        tok = c;
        p++;
        ଭାଙ୍ଗ;
    ସ୍ଥିତି 0xEF: /* UTF8 BOM ? */
        ଯଦି (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            ଯାଅ redo_no_start;
        }
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଯଦି (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    ଯାଅ parse_ident_fast;
        ଯଦି (parse_flags & PARSE_FLAG_ASM_FILE)
            ଯାଅ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        ଭାଙ୍ଗ;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#ଯଦି defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା indent;
ସ୍ଥିର ଶୂନ୍ୟ define_print(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v);
ସ୍ଥିର ଶୂନ୍ୟ pp_print(ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str)
{
    FILE *fp = tcc_state->ppfp;

    ଯଦି (ସନ୍ଦେଶ[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    ଅନ୍ୟଥା ଯଦି (ସନ୍ଦେଶ[0] == '+')
         ++indent, ++ସନ୍ଦେଶ;
    ଅନ୍ୟଥା ଯଦି (ସନ୍ଦେଶ[0] == '-')
        --indent, ++ସନ୍ଦେଶ;

    fprintf(fp, "%*s", indent, "");
    ଯଦି (ସନ୍ଦେଶ[0] == '#') {
        define_print(tcc_state, v);
    } ଅନ୍ୟଥା {
        tok_print(str, v ? "%s %s" : "%s", ସନ୍ଦେଶ, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#ଅନ୍ୟଥା
#define PP_PRINT(x)
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_arg_subst(Sym **nested_list, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_str, Sym *args)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, t0, t1, t2, n;
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    ପାଇଁ (s = args, n = 0; s; s = s->prev, ++n);
    ଯେତେବେଳେ (n--) {
        ପାଇଁ (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    ଯେତେବେଳେ(1) {
        TOK_GET(&t, &macro_str, &cval);
        ଯଦି (!t)
            ଭାଙ୍ଗ;
        ଯଦି (t == '#') {
            /* stringize */
            କର t = *macro_str++; ଯେତେବେଳେ (t == ' ');
            s = sym_find2(args, t);
            ଯଦି (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                ଯେତେବେଳେ (*st != TOK_EOF) {
                    ଅଚଳ ଅକ୍ଷର *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    ଯେତେବେଳେ (*s) {
                        ଯଦି (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        ଅନ୍ୟଥା
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
            } ଅନ୍ୟଥା ଯଦି ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } ଅନ୍ୟଥା {
                expect("macro parameter after '#'");
            }
        } ଅନ୍ୟଥା ଯଦି (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            ଯଦି (s) {
                st = s->d;
                n = 0;
                ଯେତେବେଳେ ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                ଯଦି (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    ଯଦି (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = str.str[str.len - 1];
                        ଯେତେବେଳେ (str.str[--str.len] != ',')
                            ;
                        ଯଦି (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } ଅନ୍ୟଥା {
                            /* suppress '##' and add variable */
                            str.len++;
                            ଯଦି (c == ' ')
                                str.str[str.len++] = c;
                            ଯାଅ add_var;
                        }
                    } ଅନ୍ୟଥା {
                        ଯଦି (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } ଅନ୍ୟଥା {
            add_var:
		    ଯଦି (!s->e) {
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
                ଯେତେବେଳେ (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } ଅନ୍ୟଥା {
                tok_str_add(&str, t);
            }
        } ଅନ୍ୟଥା {
            tok_str_add2(&str, t, &cval);
        }
        ଯଦି (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    ଫେରନ୍ତୁ str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_twosharps(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ptr0)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    ପାଇଁ (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        ଯଦି (t1 == 0)
            ଭାଙ୍ଗ;
        ପାଇଁ (;;) {
            n = 0;
            ଯେତେବେଳେ ((t2 = ptr[n]) == ' ')
                ++n;
            ଯଦି (t2 != TOK_PPJOIN)
                ଭାଙ୍ଗ;
            ptr += n;
            ଯେତେବେଳେ ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            ଯଦି (t2 == TOK_PLCHLDR)
                ଜାରି;
            ଯଦି (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        ଯଦି (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            ପାଇଁ (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                ଯଦି (*file->buf_ptr == 0)
                    ଭାଙ୍ଗ;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        ଯଦି (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    ଫେରନ୍ତୁ macro_str1.str;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ପାଇଁ (;;) {
        PEEKC(c, p);
        ବାଛ (c) {
        ସ୍ଥିତି '/':
            PEEKC(c, p);
            ଯଦି (c == '*')
                p = parse_comment(p);
            ଅନ୍ୟଥା ଯଦି (c == '/')
                p = parse_ଧାଡ଼ି_comment(p);
            ଅନ୍ୟଥା {
                c = *--p = '/';
                ଯାଅ leave;
            }
            --p, c = ' ';
            ଭାଙ୍ଗ;
        ସ୍ଥିତି ' ': ସ୍ଥିତି '\t':
            ଭାଙ୍ଗ;
        ସ୍ଥିତି '\f': ସ୍ଥିତି '\v': ସ୍ଥିତି '\r':
            ଜାରି;
        ସ୍ଥିତି '\n':
            file->ଧାଡ଼ି_ଅଙ୍କ++, tok_flags |= TOK_FLAG_BOL;
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ: leave:
            file->buf_ptr = p;
            ଫେରନ୍ତୁ c;
        }
        ଯଦି (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା next_argstream(Sym **nested_list, TokenString *ws_str)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    Sym *sa;

    ଯେତେବେଳେ (macro_ptr) {
        ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *m = macro_ptr;
        ଯେତେବେଳେ ((t = *m) != 0) {
            ଯଦି (ws_str) {
                ଯଦି (t != ' ')
                    ଫେରନ୍ତୁ t;
                ++m;
            } ଅନ୍ୟଥା {
                TOK_GET(&tok, &macro_ptr, &tokc);
                ଫେରନ୍ତୁ tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        ଯଦି (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    ଯଦି (ws_str) {
        ଫେରନ୍ତୁ peek_file(ws_str);
    } ଅନ୍ୟଥା {
        next_nomacro();
        ଯଦି (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        ଫେରନ୍ତୁ tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v = s->v;

    PP_PRINT(("#", v, s->d));
    ଯଦି (s->d) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *mstr = s->d;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *jstr;
        Sym *sa;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;

        ଯଦି (s->type.t & MACRO_FUNC) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା saved_parse_flags = parse_flags;
            TokenString str;
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            ଯଦି (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                ଯଦି (parse_flags & PARSE_FLAG_SPACES)
                    ପାଇଁ (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                ଫେରନ୍ତୁ 0;
            } ଅନ୍ୟଥା {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = ଖାଲି;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            ପାଇଁ(;;) {
                କର {
                    t = next_argstream(nested_list, ଖାଲି);
                } ଯେତେବେଳେ (t == ' ' || --i);

                ଯଦି (!sa) {
                    ଯଦି (t == ')') /* handle '()' case */
                        ଭାଙ୍ଗ;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                ଯେତେବେଳେ (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    ଯଦି (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    ଯଦି (t == '(')
                        parlevel++;
                    ଯଦି (t == ')')
                        parlevel--;
                    ଯଦି (t == ' ')
                        str.need_spc |= 1;
                    ଅନ୍ୟଥା
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, ଖାଲି);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                ଯଦି (t == ')') {
                    ଯଦି (!sa)
                        ଭାଙ୍ଗ;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    ଯଦି (sa->type.t && gnu_ext)
                        ଯାଅ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            ଯେତେବେଳେ (sa) {
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
        ଯଦି (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        ଯଦି (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        ଯଦି (jstr != mstr)
            tok_str_free_str(jstr);
        ଯଦି (mstr != s->d)
            tok_str_free_str(mstr);
        ଫେରନ୍ତୁ ret;

    } ଅନ୍ୟଥା {
        CValue cval;
        ଅକ୍ଷର buf[32], *cstrval = buf;

        /* special macros */
        ଯଦି (v == TOK_ଧାଡ଼ି_2 || v == TOK___COUNTER__) {
            t = v == TOK_ଧାଡ଼ି_2 ? file->ଧାଡ଼ି_ଅଙ୍କ : pp_counter++;
            snprintf(buf, ଆକାର(buf), "%d", t);
            t = TOK_PPNUM;
            ଯାଅ add_cstr1;

        } ଅନ୍ୟଥା ଯଦି (v == TOK___FILE__) {
            cstrval = file->filename;
            ଯାଅ add_cstr;

        } ଅନ୍ୟଥା ଯଦି (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            ସଂରଚନା tm *tm;
            time(&ti);
            tm = localtime(&ti);
            ଯଦି (v == TOK___DATE__) {
                ସ୍ଥିର ଅକ୍ଷର ଅଚଳ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, ଆକାର(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } ଅନ୍ୟଥା {
                snprintf(buf, ଆକାର(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        ଫେରନ୍ତୁ 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *macro_str
    )
{
    Sym *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    ଯେତେବେଳେ (1) {
        TOK_GET(&t, &macro_str, &cval);
        ଯଦି (t == 0 || t == TOK_EOF)
            ଭାଙ୍ଗ;
        ଯଦି (t >= TOK_IDENT) {
            s = define_find(t);
            ଯଦି (s == ଖାଲି || nosubst)
                ଯାଅ no_subst;
            /* if nested substitution, do nothing */
            ଯଦି (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                ଯାଅ no_subst;
            }
            str = tok_str_alloc();
            str->str = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            ଯଦି (macro_ଗଦା != str) {
                /* already finished by reading function macro arguments */
                ଭାଙ୍ଗ;
            }
            macro_str = macro_ptr;
            end_macro ();
        } ଅନ୍ୟଥା ଯଦି (t == ' ') {
            ଯଦି (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } ଅନ୍ୟଥା {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            ଯଦି (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            ଯଦି (t == TOK_DEFINED && pp_ପଦସମଷ୍ଟି)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    ଫେରନ୍ତୁ nosubst;
}

/* return next token with macro substitution */
ST_FUNC ଶୂନ୍ୟ next(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ଯେତେବେଳେ (macro_ptr) {
redo:
        t = *macro_ptr;
        ଯଦି (TOK_HAS_ମୂଲ୍ୟ(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            ଯଦି (t == TOK_LINENUM) {
                file->ଧାଡ଼ି_ଅଙ୍କ = tokc.i;
                ଯାଅ redo;
            }
            ଯାଅ convert;
        } ଅନ୍ୟଥା ଯଦି (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            ଜାରି;
        } ଅନ୍ୟଥା ଯଦି (t == TOK_EOF) {
            /* do nothing */
        } ଅନ୍ୟଥା {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            ଯଦି (t == '\\') {
                ଯଦି (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        ଫେରନ୍ତୁ;
    }

    next_nomacro();
    t = tok;
    ଯଦି (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        ଯଦି (s) {
            Sym *nested_list = ଖାଲି;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            ଯାଅ redo;
        }
        ଫେରନ୍ତୁ;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    ଯଦି (t == TOK_PPNUM) {
        ଯଦି  (parse_flags & PARSE_FLAG_TOK_ଅଙ୍କ)
            parse_ସଂଖ୍ୟା(tokc.str.data);
    } ଅନ୍ୟଥା ଯଦି (t == TOK_PPSTR) {
        ଯଦି (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN ଶୂନ୍ୟ unget_tok(ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_tok)
{
    TokenString *str = &unget_buf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା alloc = 0;
    ଯଦି (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    ଯଦି (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର * ଅଚଳ target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# ଯଦି PTR_SIZE == 8
    "_WIN64\0"
# endif
#ଅନ୍ୟଥା
# ଯଦି defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# ଅନ୍ୟଥା
    "__linux__\0"
    "__linux\0"
#  ଯଦି TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

ସ୍ଥିର ଶୂନ୍ୟ putdef(CString *cs, ଅଚଳ ଅକ୍ଷର *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

ସ୍ଥିର ଶୂନ୍ୟ putdefs(CString *cs, ଅଚଳ ଅକ୍ଷର *p)
{
    ଯେତେବେଳେ (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_predefs(TCCState *s1, CString *cs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    ଯଦି (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    ଯଦି (is_asm)
      putdef(cs, "__ASSEMBLER__");
    ଯଦି (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    ଯଦି (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    ଯଦି (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    ଯଦି (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    ଯଦି (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    ଯଦି (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    ଯଦି (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    ଯଦି (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#ଯଦି CONFIG_TCC_PREDEFS
        #ଅନ୍ତର୍ଭାଵ "tccdefs_.h" /* include as strings */
#ଅନ୍ୟଥା
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC ଶୂନ୍ୟ preprocess_start(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ଗଦା_ptr = s1->include_ଗଦା;
    s1->ifdef_ଗଦା_ptr = s1->ifdef_ଗଦା;
    file->ifdef_ଗଦା_ptr = s1->ifdef_ଗଦା_ptr;
    pp_ପଦସମଷ୍ଟି = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ଗଦା[0] = 0;
    s1->pack_ଗଦା_ptr = s1->pack_ଗଦା;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    ଯଦି (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        ଯଦି (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        ଯଦି (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ଗଦା_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC ଶୂନ୍ୟ preprocess_end(TCCState *s1)
{
    ଯେତେବେଳେ (macro_ଗଦା)
        end_macro();
    macro_ptr = ଖାଲି;
    ଯେତେବେଳେ (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_idnum(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    ଫେରନ୍ତୁ prev;
}

ST_FUNC ଶୂନ୍ୟ tccpp_new(TCCState *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, c;
    ଅଚଳ ଅକ୍ଷର *p, *r;

    /* init isid table */
    ପାଇଁ(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_ଅଙ୍କ
            : 0);

    ପାଇଁ(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * ଆକାର(TokenSym *));
    memset(s->cached_includes_hash, 0, ଆକାର s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    ଯେତେବେଳେ (*p) {
        r = p;
        ପାଇଁ(;;) {
            c = *r++;
            ଯଦି (c == '\0')
                ଭାଙ୍ଗ;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ଠେଲ(TOK_ଧାଡ଼ି_2, MACRO_OBJ, ଖାଲି, ଖାଲି);
    define_ଠେଲ(TOK___FILE__, MACRO_OBJ, ଖାଲି, ଖାଲି);
    define_ଠେଲ(TOK___DATE__, MACRO_OBJ, ଖାଲି, ଖାଲି);
    define_ଠେଲ(TOK___TIME__, MACRO_OBJ, ଖାଲି, ଖାଲି);
    define_ଠେଲ(TOK___COUNTER__, MACRO_OBJ, ଖାଲି, ଖାଲି);
}

ST_FUNC ଶୂନ୍ୟ tccpp_delete(TCCState *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    ଯଦି (n > total_idents)
        total_idents = n;
    ପାଇଁ (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ଖାଲି;

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

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_need_space(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b);

ସ୍ଥିର ଶୂନ୍ୟ tok_print(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *str, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, t0, s;
    CValue cval;

    va_start(ap, ସନ୍ଦେଶ);
    vfprintf(fp, ସନ୍ଦେଶ, ap);
    va_end(ap);

    s = t0 = 0;
    ଯେତେବେଳେ (str) {
	TOK_GET(&t, &str, &cval);
	ଯଦି (t == 0 || t == TOK_EOF)
	    ଭାଙ୍ଗ;
        ଯଦି (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

ସ୍ଥିର ଶୂନ୍ୟ pp_ଧାଡ଼ି(TCCState *s1, BufferedFile *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା d = f->ଧାଡ଼ି_ଅଙ୍କ - f->ଧାଡ଼ି_ref;

    ଯଦି (s1->dflag & 4)
	ଫେରନ୍ତୁ;

    ଯଦି (s1->Pflag == ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } ଅନ୍ୟଥା ଯଦି (level == 0 && f->ଧାଡ଼ି_ref && d < 8) {
	ଯେତେବେଳେ (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } ଅନ୍ୟଥା ଯଦି (s1->Pflag == ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->ଧାଡ଼ି_ଅଙ୍କ, f->filename);
    } ଅନ୍ୟଥା {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->ଧାଡ଼ି_ଅଙ୍କ, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->ଧାଡ଼ି_ref = f->ଧାଡ଼ି_ଅଙ୍କ;
}

ସ୍ଥିର ଶୂନ୍ୟ define_print(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    ଯଦି (ଖାଲି == s || ଖାଲି == s->d)
        ଫେରନ୍ତୁ;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ଖାଲି));
    ଯଦି (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        ଯଦି (a)
            ପାଇଁ (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ଖାଲି));
                ଯଦି (!(a = a->next))
                    ଭାଙ୍ଗ;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

ସ୍ଥିର ଶୂନ୍ୟ pp_debug_defines(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v, t;
    ଅଚଳ ଅକ୍ଷର *vs;
    FILE *fp;

    t = pp_debug_tok;
    ଯଦି (t == 0)
        ଫେରନ୍ତୁ;

    file->ଧାଡ଼ି_ଅଙ୍କ--;
    pp_ଧାଡ଼ି(s1, file, 0);
    file->ଧାଡ଼ି_ref = ++file->ଧାଡ଼ି_ଅଙ୍କ;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ଖାଲି);
    ଯଦି (t == TOK_DEFINE) {
        define_print(s1, v);
    } ଅନ୍ୟଥା ଯଦି (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } ଅନ୍ୟଥା ଯଦି (t == TOK_ଠେଲ_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } ଅନ୍ୟଥା ଯଦି (t == TOK_କାଢ଼_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_need_space(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଫେରନ୍ତୁ 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା pp_check_he0xE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ଅଚଳ ଅକ୍ଷର *p)
{
    ଯଦି (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        ଫେରନ୍ତୁ 'E';
    ଫେରନ୍ତୁ t;
}

/* Preprocess the current file */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା token_seen, spcs, level;
    ଅଚଳ ଅକ୍ଷର *p;
    ଅକ୍ଷର white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    ଯଦି (s1->Pflag == ଧାଡ଼ି_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_ଅଙ୍କ, s1->Pflag = 1;

    ଯଦି (s1->do_bench) {
	/* for PP benchmarks */
	କର next(); ଯେତେବେଳେ (tok != TOK_EOF);
	ଫେରନ୍ତୁ 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    ଯଦି (file->prev)
        pp_ଧାଡ଼ି(s1, file->prev, level++);
    pp_ଧାଡ଼ି(s1, file, level);

    ପାଇଁ (;;) {
        iptr = s1->include_ଗଦା_ptr;
        next();
        ଯଦି (tok == TOK_EOF)
            ଭାଙ୍ଗ;

        level = s1->include_ଗଦା_ptr - iptr;
        ଯଦି (level) {
            ଯଦି (level > 0)
                pp_ଧାଡ଼ି(s1, *iptr, 0);
            pp_ଧାଡ଼ି(s1, file, level);
        }
        ଯଦି (s1->dflag & 7) {
            pp_debug_defines(s1);
            ଯଦି (s1->dflag & 4)
                ଜାରି;
        }

        ଯଦି (is_space(tok)) {
            ଯଦି (spcs < ଆକାର white - 1)
                white[spcs++] = tok;
            ଜାରି;
        } ଅନ୍ୟଥା ଯଦି (tok == TOK_LINEFEED) {
            spcs = 0;
            ଯଦି (token_seen == TOK_LINEFEED)
                ଜାରି;
            ++file->ଧାଡ଼ି_ref;
        } ଅନ୍ୟଥା ଯଦି (token_seen == TOK_LINEFEED) {
            pp_ଧାଡ଼ି(s1, file, 0);
        } ଅନ୍ୟଥା ଯଦି (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    ଫେରନ୍ତୁ 0;
}

/* ------------------------------------------------------------------------- */
