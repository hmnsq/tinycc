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
#અન્તર્ભાવ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA પૂર્ણાંક tok_flags;
ST_DATA પૂર્ણાંક parse_flags;

ST_DATA સંરચના BufferedFile *file;
ST_DATA પૂર્ણાંક tok;
ST_DATA CValue tokc;
ST_DATA અચલ પૂર્ણાંક *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA પૂર્ણાંક tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA પૂર્ણાંક pp_પદાવલિ;

/* ------------------------------------------------------------------------- */

સ્થિર TokenSym *hash_ident[TOK_HASH_SIZE];
સ્થિર અક્ષર token_buf[STRING_MAX_SIZE + 1];
સ્થિર CString cstr_buf;
સ્થિર TokenString tokstr_buf;
સ્થિર TokenString unget_buf;
સ્થિર unsigned અક્ષર isidnum_table[256 - CH_EOF];
સ્થિર પૂર્ણાંક pp_debug_tok, pp_debug_symv;
સ્થિર પૂર્ણાંક pp_counter;
સ્થિર શૂન્ય tok_print(અચલ પૂર્ણાંક *str, અચલ અક્ષર *સંદેશ, ...);
સ્થિર શૂન્ય next_nomacro(શૂન્ય);
સ્થિર શૂન્ય parse_સંખ્યા(અચલ અક્ષર *p);
સ્થિર શૂન્ય parse_string(અચલ અક્ષર *p, પૂર્ણાંક len);

સ્થિર સંરચના TinyAlloc *toksym_alloc;
સ્થિર સંરચના TinyAlloc *tokstr_alloc;

સ્થિર TokenString *macro_ઢગલો;

સ્થિર અચલ અક્ષર tcc_keywords[] = 
#define DEF(id, str) str "\0"
#અન્તર્ભાવ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
સ્થિર અચલ unsigned અક્ષર tok_two_chars[] =
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

ST_FUNC શૂન્ય skip(પૂર્ણાંક c)
{
    જો (tok != c) {
        અક્ષર tmp[40];
        pstrcpy(tmp, કદ tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC શૂન્ય expect(અચલ અક્ષર *સંદેશ)
{
    tcc_error("%s expected", સંદેશ);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#નહીંતર
#જો !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#નહીંતર
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , અચલ અક્ષર *sfile, પૂર્ણાંક sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

પ્રકારવ્યાખ્યા સંરચના TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    સંરચના TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#જો TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    સંઘ {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

પ્રકારવ્યાખ્યા સંરચના tal_header_t {
    size_t  size; /* word align */
#જો TAL_DEBUG
    પૂર્ણાંક     લીટી_અંક; /* negative line_num used for double free check */
    અક્ષર    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (કદ (size_t) - 1)) & ~(કદ (size_t) - 1))

/* ------------------------------------------------------------------------- */

સ્થિર TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(કદ(TinyAlloc) - કદ (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#જો TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    પાછા al;
}

સ્થિર શૂન્ય tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#જો TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#જો TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#જો TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    જો (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        જ્યારે (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            જો (header->લીટી_અંક > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->લીટી_અંક, (પૂર્ણાંક)header->size);
            }
            p += header->size + કદ(tal_header_t);
        }
#જો TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    જો (al)
        જાઓ tail_call;
    *pal = al;
}

સ્થિર શૂન્ય tal_free_impl(TinyAlloc **pal, શૂન્ય *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **ટોચ = pal;
    tal_header_t *header;

    જો (!p)
        પાછા;
    header = (tal_header_t *)p - 1;
#જો TAL_DEBUG
    જો (header->લીટી_અંક < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (પૂર્ણાંક)-header->લીટી_અંક, (પૂર્ણાંક)header->size);
    } નહીંતર
        header->લીટી_અંક = -header->લીટી_અંક;
#endif
    al = *pal;
    જ્યારે ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    જો (0 == --al->nb_allocs) {
        *pal = al->next;
        જો ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } નહીંતર {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *ટોચ, *ટોચ = al;
        }
    } નહીંતર જો ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

સ્થિર શૂન્ય *tal_realloc_impl(TinyAlloc **pal, શૂન્ય *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    શૂન્ય *ret;
    unsigned adj_size = TAL_ALIGN(size) + કદ(tal_header_t);
    TinyAlloc *al = *pal;

    જો (p) {
        /* reallpc case */
        જ્યારે ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        જો ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        જો (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            પાછા ret;
        } નહીંતર જો (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#જો TAL_DEBUG
            header->લીટી_અંક = -header->લીટી_અંક;
#endif
        }
    } નહીંતર {
        /* new alloc case */
        જ્યારે (al->p + adj_size > al->bufend) {
            al = al->next;
            જો (!al) {
                unsigned new_size = (*pal)->size;
                જો (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                તોડો;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - કદ(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#જો  TAL_DEBUG
    {
        પૂર્ણાંક ofs = strlen(sfile) + 1 - કદ header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->લીટી_અંક = sline;
#જો TAL_INFO
        જો (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        જો (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    પાછા ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
સ્થિર શૂન્ય cstr_realloc(CString *cstr, પૂર્ણાંક new_size)
{
    પૂર્ણાંક size;

    size = cstr->size_allocated;
    જો (size < 8)
        size = 8; /* no need to allocate a too small first string */
    જ્યારે (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN શૂન્ય cstr_ccat(CString *cstr, પૂર્ણાંક ch)
{
    પૂર્ણાંક size;
    size = cstr->size + 1;
    જો (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN અક્ષર *unicode_to_utf8 (અક્ષર *b, uint32_t Uc)
{
    જો (Uc<0x80) *b++=Uc;
    નહીંતર જો (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    નહીંતર જો (Uc-0xd800u<0x800) જાઓ error;
    નહીંતર જો (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    નહીંતર જો (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    નહીંતર error: tcc_error("0x%x is not a valid universal character", Uc);
    પાછા b;
}

/* add a unicode character expanded into utf8 */
ST_INLN શૂન્ય cstr_u8cat(CString *cstr, પૂર્ણાંક ch)
{
    અક્ષર buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC શૂન્ય cstr_cat(CString *cstr, અચલ અક્ષર *str, પૂર્ણાંક len)
{
    પૂર્ણાંક size;
    જો (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    જો (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC શૂન્ય cstr_wccat(CString *cstr, પૂર્ણાંક ch)
{
    પૂર્ણાંક size;
    size = cstr->size + કદ(nwchar_t);
    જો (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - કદ(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC શૂન્ય cstr_new(CString *cstr)
{
    memset(cstr, 0, કદ(CString));
}

/* free string and reset it to NULL */
ST_FUNC શૂન્ય cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC શૂન્ય cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC પૂર્ણાંક cstr_vprintf(CString *cstr, અચલ અક્ષર *fmt, va_list ap)
{
    va_list v;
    પૂર્ણાંક len, size = 80;
    માટે (;;) {
        size += cstr->size;
        જો (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        જો (len >= 0 && len < size)
            તોડો;
        size *= 2;
    }
    cstr->size += len;
    પાછા len;
}

ST_FUNC પૂર્ણાંક cstr_printf(CString *cstr, અચલ અક્ષર *fmt, ...)
{
    va_list ap; પૂર્ણાંક len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    પાછા len;
}

/* XXX: unicode ? */
સ્થિર શૂન્ય add_char(CString *cstr, પૂર્ણાંક c)
{
    જો (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    જો (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } નહીંતર {
        cstr_ccat(cstr, '\\');
        જો (c == '\n') {
            cstr_ccat(cstr, 'n');
        } નહીંતર {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
સ્થિર TokenSym *tok_alloc_new(TokenSym **pts, અચલ અક્ષર *str, પૂર્ણાંક len)
{
    TokenSym *ts, **ptable;
    પૂર્ણાંક i;

    જો (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    જો ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * કદ(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, કદ(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = ખાલી;
    ts->sym_label = ખાલી;
    ts->sym_struct = ખાલી;
    ts->sym_identifier = ખાલી;
    ts->len = len;
    ts->hash_next = ખાલી;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    પાછા ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(અચલ અક્ષર *str, પૂર્ણાંક len)
{
    TokenSym *ts, **pts;
    પૂર્ણાંક i;
    unsigned પૂર્ણાંક h;
    
    h = TOK_HASH_INIT;
    માટે(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned અક્ષર *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    માટે(;;) {
        ts = *pts;
        જો (!ts)
            તોડો;
        જો (ts->len == len && !memcmp(ts->str, str, len))
            પાછા ts;
        pts = &(ts->hash_next);
    }
    પાછા tok_alloc_new(pts, str, len);
}

ST_FUNC પૂર્ણાંક tok_alloc_const(અચલ અક્ષર *str)
{
    પાછા tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC અચલ અક્ષર *get_tok_str(પૂર્ણાંક v, CValue *cv)
{
    અક્ષર *p;
    પૂર્ણાંક i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    પસંદગી(v) {
    સ્થિતિ TOK_CINT:
    સ્થિતિ TOK_CUINT:
    સ્થિતિ TOK_CLONG:
    સ્થિતિ TOK_CULONG:
    સ્થિતિ TOK_CLLONG:
    સ્થિતિ TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        તોડો;
    સ્થિતિ TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    સ્થિતિ TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        તોડો;
    સ્થિતિ TOK_PPNUM:
    સ્થિતિ TOK_PPSTR:
        પાછા (અક્ષર*)cv->str.data;
    સ્થિતિ TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    સ્થિતિ TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        જો (v == TOK_STR) {
            len = cv->str.size - 1;
            માટે(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned અક્ષર *)cv->str.data)[i]);
        } નહીંતર {
            len = (cv->str.size / કદ(nwchar_t)) - 1;
            માટે(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        તોડો;

    સ્થિતિ TOK_CFLOAT:
        પાછા strcpy(p, "<float>");
    સ્થિતિ TOK_CDOUBLE:
        પાછા strcpy(p, "<double>");
    સ્થિતિ TOK_CLDOUBLE:
        પાછા strcpy(p, "<long double>");
    સ્થિતિ TOK_LINENUM:
        પાછા strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    સ્થિતિ TOK_LT:
        v = '<';
        જાઓ addv;
    સ્થિતિ TOK_GT:
        v = '>';
        જાઓ addv;
    સ્થિતિ TOK_DOTS:
        પાછા strcpy(p, "...");
    સ્થિતિ TOK_A_SHL:
        પાછા strcpy(p, "<<=");
    સ્થિતિ TOK_A_SAR:
        પાછા strcpy(p, ">>=");
    સ્થિતિ TOK_EOF:
        પાછા strcpy(p, "<eof>");
    સ્થિતિ 0: /* anonymous nameless symbols */
        પાછા strcpy(p, "<no name>");
    મૂળભૂત:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        જો (v < TOK_IDENT) {
            /* search in two bytes table */
            અચલ unsigned અક્ષર *q = tok_two_chars;
            જ્યારે (*q) {
                જો (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    પાછા cstr_buf.data;
                }
                q += 3;
            }
            જો (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                તોડો;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } નહીંતર જો (v < tok_ident) {
            પાછા table_ident[v - TOK_IDENT]->str;
        } નહીંતર જો (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } નહીંતર {
            /* should never happen */
            પાછા ખાલી;
        }
        તોડો;
    }
    પાછા cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
સ્થિર પૂર્ણાંક handle_eob(શૂન્ય)
{
    BufferedFile *bf = file;
    પૂર્ણાંક len;

    /* only tries to read if really end of buffer */
    જો (bf->buf_ptr >= bf->buf_end) {
        જો (bf->fd >= 0) {
#જો defined(PARSE_DEBUG)
            len = 1;
#નહીંતર
            len = IO_BUF_SIZE;
#endif
            len = પઠ(bf->fd, bf->buffer, len);
            જો (len < 0)
                len = 0;
        } નહીંતર {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    જો (bf->buf_ptr < bf->buf_end) {
        પાછા bf->buf_ptr[0];
    } નહીંતર {
        bf->buf_ptr = bf->buf_end;
        પાછા CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
સ્થિર પૂર્ણાંક next_c(શૂન્ય)
{
    પૂર્ણાંક ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    જો (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    પાછા ch;
}

/* input with '\[\r]\n' handling. */
સ્થિર પૂર્ણાંક handle_stray_noerror(પૂર્ણાંક err)
{
    પૂર્ણાંક ch;
    જ્યારે ((ch = next_c()) == '\\') {
        ch = next_c();
        જો (ch == '\n') {
    newl:
            file->લીટી_અંક++;
        } નહીંતર {
            જો (ch == '\r') {
                ch = next_c();
                જો (ch == '\n')
                    જાઓ newl;
                *--file->buf_ptr = '\r';
            }
            જો (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            પાછા *--file->buf_ptr = '\\';
        }
    }
    પાછા ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
સ્થિર પૂર્ણાંક handle_bs(uint8_t **p)
{
    પૂર્ણાંક c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    પાછા c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
સ્થિર પૂર્ણાંક handle_stray(uint8_t **p)
{
    પૂર્ણાંક c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    પાછા c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    જો (c == '\\')\
        c = handle_stray(&p); \
}

સ્થિર પૂર્ણાંક skip_spaces(શૂન્ય)
{
    પૂર્ણાંક ch;
    --file->buf_ptr;
    કરો {
        ch = ninp();
    } જ્યારે (isidnum_table[ch - CH_EOF] & IS_SPC);
    પાછા ch;
}

/* single line C++ comments */
સ્થિર uint8_t *parse_લીટી_comment(uint8_t *p)
{
    પૂર્ણાંક c;
    માટે(;;) {
        માટે (;;) {
            c = *++p;
    redo:
            જો (c == '\n' || c == '\\')
                તોડો;
            c = *++p;
            જો (c == '\n' || c == '\\')
                તોડો;
        }
        જો (c == '\n')
            તોડો;
        c = handle_bs(&p);
        જો (c == CH_EOF)
            તોડો;
        જો (c != '\\')
            જાઓ redo;
    }
    પાછા p;
}

/* C comments */
સ્થિર uint8_t *parse_comment(uint8_t *p)
{
    પૂર્ણાંક c;
    માટે(;;) {
        /* fast skip loop */
        માટે(;;) {
            c = *++p;
        redo:
            જો (c == '\n' || c == '*' || c == '\\')
                તોડો;
            c = *++p;
            જો (c == '\n' || c == '*' || c == '\\')
                તોડો;
        }
        /* now we can handle all the cases */
        જો (c == '\n') {
            file->લીટી_અંક++;
        } નહીંતર જો (c == '*') {
            કરો {
                c = *++p;
            } જ્યારે (c == '*');
            જો (c == '\\')
                c = handle_bs(&p);
            જો (c == '/')
                તોડો;
            જાઓ check_eof;
        } નહીંતર {
            c = handle_bs(&p);
        check_eof:
            જો (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            જો (c != '\\')
                જાઓ redo;
        }
    }
    પાછા p + 1;
}

/* parse a string without interpreting escapes */
સ્થિર uint8_t *parse_pp_string(uint8_t *p, પૂર્ણાંક sep, CString *str)
{
    પૂર્ણાંક c;
    માટે(;;) {
        c = *++p;
    redo:
        જો (c == sep) {
            તોડો;
        } નહીંતર જો (c == '\\') {
            c = handle_bs(&p);
            જો (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } નહીંતર જો (c == '\\') {
                જો (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                જો (c == '\\') {
                    c = handle_bs(&p);
                    જો (c == CH_EOF)
                        જાઓ unterminated_string;
                }
                જાઓ add_char;
            } નહીંતર {
                જાઓ redo;
            }
        } નહીંતર જો (c == '\n') {
        add_lf:
            જો (ACCEPT_LF_IN_STRINGS) {
                file->લીટી_અંક++;
                જાઓ add_char;
            } નહીંતર જો (str) { /* not skipping */
                જાઓ unterminated_string;
            } નહીંતર {
                //tcc_warning("missing terminating %c character", sep);
                પાછા p;
            }
        } નહીંતર જો (c == '\r') {
            c = *++p;
            જો (c == '\\')
                c = handle_bs(&p);
            જો (c == '\n')
                જાઓ add_lf;
            જો (c == CH_EOF)
                જાઓ unterminated_string;
            જો (str)
                cstr_ccat(str, '\r');
            જાઓ redo;
        } નહીંતર {
        add_char:
            જો (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    પાછા p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
સ્થિર શૂન્ય preprocess_skip(શૂન્ય)
{
    પૂર્ણાંક a, start_of_લીટી, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_લીટી = 1;
    in_warn_or_error = 0;
    માટે(;;) {
        c = *p;
        પસંદગી(c) {
        સ્થિતિ ' ':
        સ્થિતિ '\t':
        સ્થિતિ '\f':
        સ્થિતિ '\v':
        સ્થિતિ '\r':
            p++;
            ચાલુ;
        સ્થિતિ '\n':
            file->લીટી_અંક++;
            p++;
            જાઓ redo_start;
        સ્થિતિ '\\':
            c = handle_bs(&p);
            જો (c == CH_EOF)
                expect("#endif");
            જો (c == '\\')
                ++p;
            ચાલુ;
        /* skip strings */
        સ્થિતિ '\"':
        સ્થિતિ '\'':
            જો (in_warn_or_error)
                જાઓ _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, ખાલી);
            તોડો;
        /* skip comments */
        સ્થિતિ '/':
            જો (in_warn_or_error)
                જાઓ _default;
            ++p;
            c = handle_bs(&p);
            જો (c == '*') {
                p = parse_comment(p);
            } નહીંતર જો (c == '/') {
                p = parse_લીટી_comment(p);
            }
            ચાલુ;
        સ્થિતિ '#':
            p++;
            જો (start_of_લીટી) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                જો (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    જાઓ the_end;
                જો (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                નહીંતર જો (tok == TOK_ENDIF)
                    a--;
                નહીંતર જો( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                નહીંતર જો (tok == TOK_LINEFEED)
                    જાઓ redo_start;
                નહીંતર જો (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_લીટી_comment(p - 1);
            }
#જો !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            નહીંતર જો (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_લીટી_comment(p - 1);
#નહીંતર
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            તોડો;
_default:
        મૂળભૂત:
            p++;
            તોડો;
        }
        start_of_લીટી = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#જો 0
/* return the number of additional 'ints' necessary to store the
   token */
સ્થિર અંતઃરેખ પૂર્ણાંક tok_size(અચલ પૂર્ણાંક *p)
{
    પસંદગી(*p) {
        /* 4 bytes */
    સ્થિતિ TOK_CINT:
    સ્થિતિ TOK_CUINT:
    સ્થિતિ TOK_CCHAR:
    સ્થિતિ TOK_LCHAR:
    સ્થિતિ TOK_CFLOAT:
    સ્થિતિ TOK_LINENUM:
        પાછા 1 + 1;
    સ્થિતિ TOK_STR:
    સ્થિતિ TOK_LSTR:
    સ્થિતિ TOK_PPNUM:
    સ્થિતિ TOK_PPSTR:
        પાછા 1 + 1 + (p[1] + 3) / 4;
    સ્થિતિ TOK_CLONG:
    સ્થિતિ TOK_CULONG:
	પાછા 1 + LONG_SIZE / 4;
    સ્થિતિ TOK_CDOUBLE:
    સ્થિતિ TOK_CLLONG:
    સ્થિતિ TOK_CULLONG:
        પાછા 1 + 2;
    સ્થિતિ TOK_CLDOUBLE:
        પાછા 1 + LDOUBLE_શબ્દો;
    મૂળભૂત:
        પાછા 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN શૂન્ય tok_str_new(TokenString *s)
{
    s->str = ખાલી;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_લીટી_અંક = -1;
}

ST_FUNC TokenString *tok_str_alloc(શૂન્ય)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, કદ *str);
    tok_str_new(str);
    પાછા str;
}

ST_FUNC શૂન્ય tok_str_free_str(પૂર્ણાંક *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC શૂન્ય tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC પૂર્ણાંક *tok_str_realloc(TokenString *s, પૂર્ણાંક new_size)
{
    પૂર્ણાંક *str, size;

    size = s->allocated_len;
    જો (size < 16)
        size = 16;
    જ્યારે (size < new_size)
        size = size * 2;
    જો (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * કદ(પૂર્ણાંક));
        s->allocated_len = size;
        s->str = str;
    }
    પાછા s->str;
}

ST_FUNC શૂન્ય tok_str_add(TokenString *s, પૂર્ણાંક t)
{
    પૂર્ણાંક len, *str;

    len = s->len;
    str = s->str;
    જો (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC શૂન્ય begin_macro(TokenString *str, પૂર્ણાંક alloc)
{
    str->alloc = alloc;
    str->prev = macro_ઢગલો;
    str->prev_ptr = macro_ptr;
    str->save_લીટી_અંક = file->લીટી_અંક;
    macro_ptr = str->str;
    macro_ઢગલો = str;
}

ST_FUNC શૂન્ય end_macro(શૂન્ય)
{
    TokenString *str = macro_ઢગલો;
    macro_ઢગલો = str->prev;
    macro_ptr = str->prev_ptr;
    file->લીટી_અંક = str->save_લીટી_અંક;
    જો (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } નહીંતર {
        જો (str->alloc == 2)
            str->str = ખાલી; /* don't free */
        tok_str_free(str);
    }
}

સ્થિર શૂન્ય tok_str_add2(TokenString *s, પૂર્ણાંક t, CValue *cv)
{
    પૂર્ણાંક len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    જો (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    પસંદગી(t) {
    સ્થિતિ TOK_CINT:
    સ્થિતિ TOK_CUINT:
    સ્થિતિ TOK_CCHAR:
    સ્થિતિ TOK_LCHAR:
    સ્થિતિ TOK_CFLOAT:
    સ્થિતિ TOK_LINENUM:
#જો LONG_SIZE == 4
    સ્થિતિ TOK_CLONG:
    સ્થિતિ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        તોડો;
    સ્થિતિ TOK_PPNUM:
    સ્થિતિ TOK_PPSTR:
    સ્થિતિ TOK_STR:
    સ્થિતિ TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_શબ્દો =
                1 + (cv->str.size + કદ(પૂર્ણાંક) - 1) / કદ(પૂર્ણાંક);
            જો (len + nb_શબ્દો >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_શબ્દો + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_શબ્દો;
        }
        તોડો;
    સ્થિતિ TOK_CDOUBLE:
    સ્થિતિ TOK_CLLONG:
    સ્થિતિ TOK_CULLONG:
#જો LONG_SIZE == 8
    સ્થિતિ TOK_CLONG:
    સ્થિતિ TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        તોડો;
    સ્થિતિ TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        જો (LDOUBLE_શબ્દો >= 3)
        str[len++] = cv->tab[2];
        જો (LDOUBLE_શબ્દો >= 4)
        str[len++] = cv->tab[3];
    મૂળભૂત:
        તોડો;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC શૂન્ય tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    જો (file->લીટી_અંક != s->last_લીટી_અંક) {
        s->last_લીટી_અંક = file->લીટી_અંક;
        cval.i = s->last_લીટી_અંક;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
સ્થિર શૂન્ય tok_str_add2_spc(TokenString *s, પૂર્ણાંક t, CValue *cv)
{
    જો (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
સ્થિર અંતઃરેખ શૂન્ય tok_get(પૂર્ણાંક *t, અચલ પૂર્ણાંક **pp, CValue *cv)
{
    અચલ પૂર્ણાંક *p = *pp;
    પૂર્ણાંક n, *tab;

    tab = cv->tab;
    પસંદગી(*t = *p++) {
#જો LONG_SIZE == 4
    સ્થિતિ TOK_CLONG:
#endif
    સ્થિતિ TOK_CINT:
    સ્થિતિ TOK_CCHAR:
    સ્થિતિ TOK_LCHAR:
    સ્થિતિ TOK_LINENUM:
        cv->i = *p++;
        તોડો;
#જો LONG_SIZE == 4
    સ્થિતિ TOK_CULONG:
#endif
    સ્થિતિ TOK_CUINT:
        cv->i = (unsigned)*p++;
        તોડો;
    સ્થિતિ TOK_CFLOAT:
	tab[0] = *p++;
	તોડો;
    સ્થિતિ TOK_STR:
    સ્થિતિ TOK_LSTR:
    સ્થિતિ TOK_PPNUM:
    સ્થિતિ TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (અક્ષર*)p;
        p += (cv->str.size + કદ(પૂર્ણાંક) - 1) / કદ(પૂર્ણાંક);
        તોડો;
    સ્થિતિ TOK_CDOUBLE:
    સ્થિતિ TOK_CLLONG:
    સ્થિતિ TOK_CULLONG:
#જો LONG_SIZE == 8
    સ્થિતિ TOK_CLONG:
    સ્થિતિ TOK_CULONG:
#endif
        n = 2;
        જાઓ copy;
    સ્થિતિ TOK_CLDOUBLE:
        n = LDOUBLE_શબ્દો;
    copy:
        કરો
            *tab++ = *p++;
        જ્યારે (--n);
        તોડો;
    મૂળભૂત:
        તોડો;
    }
    *pp = p;
}

#જો 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#નહીંતર
# define TOK_GET(t,p,c) કરો { \
    પૂર્ણાંક _t = **(p); \
    જો (TOK_HAS_કિંમત(_t)) \
        tok_get(t, p, c); \
    નહીંતર \
        *(t) = _t, ++*(p); \
    } જ્યારે (0)
#endif

સ્થિર પૂર્ણાંક macro_is_equal(અચલ પૂર્ણાંક *a, અચલ પૂર્ણાંક *b)
{
    CValue cv;
    પૂર્ણાંક t;

    જો (!a || !b)
        પાછા 1;

    જ્યારે (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        જો (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            પાછા 0;
    }
    પાછા !(*a || *b);
}

/* defines handling */
ST_INLN શૂન્ય define_ધકેલો(પૂર્ણાંક v, પૂર્ણાંક macro_type, પૂર્ણાંક *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_ઢગલો, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    જો (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, ખાલી));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC શૂન્ય define_undef(Sym *s)
{
    પૂર્ણાંક v = s->v;
    જો (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = ખાલી;
}

ST_INLN Sym *define_find(પૂર્ણાંક v)
{
    v -= TOK_IDENT;
    જો ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        પાછા ખાલી;
    પાછા table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC શૂન્ય free_defines(Sym *b)
{
    જ્યારે (define_ઢગલો != b) {
        Sym *ટોચ = define_ઢગલો;
        define_ઢગલો = ટોચ->prev;
        tok_str_free_str(ટોચ->d);
        define_undef(ટોચ);
        sym_free(ટોચ);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
સ્થિર શૂન્ય maybe_run_test(TCCState *s)
{
    અચલ અક્ષર *p;
    જો (s->include_ઢગલો_ptr != s->include_ઢગલો)
        પાછા;
    p = get_tok_str(tok, ખાલી);
    જો (0 != memcmp(p, "test_", 5))
        પાછા;
    જો (0 != --s->run_test)
        પાછા;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_ધકેલો(tok, MACRO_OBJ, ખાલી, ખાલી);
}

ST_FUNC શૂન્ય skip_to_eol(પૂર્ણાંક warn)
{
    જો (tok == TOK_LINEFEED)
        પાછા;
    જો (warn)
        tcc_warning("extra tokens after directive");
    જ્યારે (macro_ઢગલો)
        end_macro();
    file->buf_ptr = parse_લીટી_comment(file->buf_ptr - 1);
    next_nomacro();
}

સ્થિર CachedInclude *
શોધ_cached_include(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક add);

સ્થિર પૂર્ણાંક parse_include(TCCState *s1, પૂર્ણાંક do_next, પૂર્ણાંક test)
{
    પૂર્ણાંક c, i;
    અક્ષર name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    જો (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, કદ name, tokcstr.data, i);
        next_nomacro();
    } નહીંતર {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        માટે (;;) {
            next();
            p = name, i = strlen(p) - 1;
            જો (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                તોડો;
            જો (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, કદ name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    જો (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    માટે (;;) {
        ++i;
        જો (i == 0) {
            /* check absolute include path */
            જો (!IS_ABSPATH(name))
                ચાલુ;
            buf[0] = '\0';
        } નહીંતર જો (i == 1) {
            /* search in file's dir if "header.h" */
            જો (c != '\"')
                ચાલુ;
            p = file->true_filename;
            pstrncpy(buf, કદ buf, p, tcc_basename(p) - p);
        } નહીંતર {
            પૂર્ણાંક j = i - 2, k = j - s1->nb_include_paths;
            જો (k < 0)
                p = s1->include_paths[j];
            નહીંતર જો (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            નહીંતર જો (test)
                પાછા 0;
            નહીંતર
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, કદ buf, p);
            pstrcat(buf, કદ buf, "/");
        }
        pstrcat(buf, કદ buf, name);
        e = શોધ_cached_include(s1, buf, 0);
        જો (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            જો ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (પૂર્ણાંક)(s1->include_ઢગલો_ptr - s1->include_ઢગલો), "", buf);
            પાછા 1;
        }
        જો (tcc_open(s1, buf) >= 0)
            તોડો;
    }

    જો (test) {
        tcc_close();
    } નહીંતર {
        જો (s1->include_ઢગલો_ptr >= s1->include_ઢગલો + INCLUDE_ઢગલો_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_ઢગલો_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        જો (s1->gen_deps) {
            BufferedFile *bf = file;
            જ્યારે (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            જો (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    પાછા 1;
}

/* eval an expression for #if/#elif */
સ્થિર પૂર્ણાંક પદાવલિ_preprocess(TCCState *s1)
{
    પૂર્ણાંક c, t;
    પૂર્ણાંક t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_પદાવલિ = 1;
    જ્યારે (1) {
        next(); /* do macro subst */
        t = tok;
        જો (tok < TOK_IDENT) {
            જો (tok == TOK_LINEFEED || tok == TOK_EOF)
                તોડો;
            જો (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } નહીંતર જો (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            જો (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            જો (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            જો (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            જો (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            જો (t == '(') {
                next();
                જો (tok != ')')
                    expect("')'");
            }
            જાઓ c_સંખ્યા;
        } નહીંતર જો (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    જો (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            જો (tok != ')')
                expect("')'");
            જાઓ c_સંખ્યા;
        } નહીંતર {
            /* if undefined macro, replace with zero */
            c = 0;
        c_સંખ્યા:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    જો (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_પદાવલિ = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = પદાવલિ_const();
    જો (tok != TOK_EOF)
        tcc_error("...");
    pp_પદાવલિ = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    પાછા c != 0;
}

ST_FUNC શૂન્ય pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_પદાવલિ, 0));
    macro_ptr = macro_ઢગલો->str;
    જ્યારે (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC શૂન્ય parse_define(શૂન્ય)
{
    Sym *s, *first, **ps;
    પૂર્ણાંક v, t, varg, is_vaargs, t0;
    પૂર્ણાંક saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    જો (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = ખાલી;
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
    જો (tok == '(') {
        પૂર્ણાંક dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        જો (tok != ')') માટે (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            જો (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } નહીંતર જો (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            જો (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_ઢગલો, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            જો (tok == ')')
                તોડો;
            જો (tok != ',' || is_vaargs)
                જાઓ bad_list;
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
    જ્યારે (tok != TOK_LINEFEED && tok != TOK_EOF) {
        જો (is_space(tok)) {
            str.need_spc |= 1;
        } નહીંતર {
            જો (TOK_TWOSHARPS == tok) {
                જો (0 == t0)
                    જાઓ bad_twosharp;
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
    જો (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_ધકેલો(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

સ્થિર CachedInclude *શોધ_cached_include(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક add)
{
    અચલ અક્ષર *s, *basename;
    unsigned પૂર્ણાંક h;
    CachedInclude *e;
    પૂર્ણાંક c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    જ્યારે ((c = (unsigned અક્ષર)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#નહીંતર
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    માટે(;;) {
        જો (i == 0)
            તોડો;
        e = s1->cached_includes[i - 1];
        જો (0 == PATHCMP(filename, e->filename))
            પાછા e;
        જો (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            પાછા e;
        i = e->hash_next;
    }
    જો (!add)
        પાછા ખાલી;

    e = tcc_malloc(કદ(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    પાછા e;
}

સ્થિર પૂર્ણાંક pragma_parse(TCCState *s1)
{
    next_nomacro();
    જો (tok == TOK_ધકેલો_macro || tok == TOK_કાઢો_macro) {
        પૂર્ણાંક t = tok, v;
        Sym *s;

        જો (next(), tok != '(')
            જાઓ pragma_err;
        જો (next(), tok != TOK_STR)
            જાઓ pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        જો (next(), tok != ')')
            જાઓ pragma_err;
        જો (t == TOK_ધકેલો_macro) {
            જ્યારે (ખાલી == (s = define_find(v)))
                define_ધકેલો(v, 0, ખાલી, ખાલી);
            s->type.ref = s; /* set push boundary */
        } નહીંતર {
            માટે (s = define_ઢગલો; s; s = s->prev)
                જો (s->v == v && s->type.ref == s) {
                    s->type.ref = ખાલી;
                    તોડો;
                }
        }
        જો (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : ખાલી;
        નહીંતર
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } નહીંતર જો (tok == TOK_once) {
        શોધ_cached_include(s1, file->true_filename, 1)->once = 1;

    } નહીંતર જો (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        પાછા 1;

    } નહીંતર જો (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        જો (tok == TOK_ASM_કાઢો) {
            next();
            જો (s1->pack_ઢગલો_ptr <= s1->pack_ઢગલો) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_ઢગલો_ptr--;
        } નહીંતર {
            પૂર્ણાંક val = 0;
            જો (tok != ')') {
                જો (tok == TOK_ASM_ધકેલો) {
                    next();
                    જો (s1->pack_ઢગલો_ptr >= s1->pack_ઢગલો + PACK_ઢગલો_SIZE - 1)
                        જાઓ stk_error;
                    val = *s1->pack_ઢગલો_ptr++;
                    જો (tok != ',')
                        જાઓ pack_set;
                    next();
                }
                જો (tok != TOK_CINT)
                    જાઓ pragma_err;
                val = tokc.i;
                જો (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    જાઓ pragma_err;
                next();
            }
        pack_set:
            *s1->pack_ઢગલો_ptr = val;
        }
        જો (tok != ')')
            જાઓ pragma_err;

    } નહીંતર જો (tok == TOK_comment) {
        અક્ષર *p; પૂર્ણાંક t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        જો (tok != TOK_STR)
            જાઓ pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        જો (tok != ')')
            જાઓ pragma_err;
        જો (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } નહીંતર {
            જો (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } નહીંતર {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        પાછા 0;
    }
    next();
    પાછા 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC શૂન્ય tccpp_putfile(અચલ અક્ષર *filename)
{
    અક્ષર buf[1024];
    buf[0] = 0;
    જો (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, કદ buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, કદ buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    જો (0 == strcmp(file->filename, buf))
        પાછા;
    //printf("new file '%s'\n", buf);
    જો (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, કદ file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC શૂન્ય preprocess(પૂર્ણાંક is_bof)
{
    TCCState *s1 = tcc_state;
    પૂર્ણાંક c, n, saved_parse_flags;
    અક્ષર buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_અંક
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    પસંદગી(tok) {
    સ્થિતિ TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        તોડો;
    સ્થિતિ TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        જો (s)
            define_undef(s);
        next_nomacro();
        તોડો;
    સ્થિતિ TOK_INCLUDE:
    સ્થિતિ TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        જાઓ the_end;
    સ્થિતિ TOK_IFNDEF:
        c = 1;
        જાઓ do_ifdef;
    સ્થિતિ TOK_IF:
        c = પદાવલિ_preprocess(s1);
        જાઓ do_if;
    સ્થિતિ TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        જો (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        જો (is_bof) {
            જો (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, ખાલી));
#endif
                file->ifndef_macro = tok;
            }
        }
        જો (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        જો (s1->ifdef_ઢગલો_ptr >= s1->ifdef_ઢગલો + IFDEF_ઢગલો_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_ઢગલો_ptr++ = c;
        જાઓ test_skip;
    સ્થિતિ TOK_ELSE:
        next_nomacro();
        જો (s1->ifdef_ઢગલો_ptr == s1->ifdef_ઢગલો)
            tcc_error("#else without matching #if");
        જો (s1->ifdef_ઢગલો_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_ઢગલો_ptr[-1] ^= 3);
        જાઓ test_else;
    સ્થિતિ TOK_ELIF:
        જો (s1->ifdef_ઢગલો_ptr == s1->ifdef_ઢગલો)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_ઢગલો_ptr[-1];
        જો (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        જો (c == 1) {
            skip_to_eol(0);
            c = 0;
        } નહીંતર {
            c = પદાવલિ_preprocess(s1);
            s1->ifdef_ઢગલો_ptr[-1] = c;
        }
    test_else:
        જો (s1->ifdef_ઢગલો_ptr == file->ifdef_ઢગલો_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        જો (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            જાઓ redo;
        }
        તોડો;
    સ્થિતિ TOK_ENDIF:
        next_nomacro();
        જો (s1->ifdef_ઢગલો_ptr <= file->ifdef_ઢગલો_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_ઢગલો_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        જો (file->ifndef_macro &&
            s1->ifdef_ઢગલો_ptr == file->ifdef_ઢગલો_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        તોડો;

    સ્થિતિ TOK_લીટી:
        parse_flags &= ~PARSE_FLAG_TOK_અંક;
        next();
        જો (tok != TOK_PPNUM) {
    લીટી_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        જાઓ લીટી_અંક_2;
    સ્થિતિ TOK_PPNUM:
        જો (parse_flags & PARSE_FLAG_ASM_FILE)
            જાઓ ignore;
        c = 0; /* no error with extra tokens */
    લીટી_અંક_2:
        માટે (n = 0, q = tokc.str.data; *q; ++q) {
            જો (!isnum(*q))
                જાઓ લીટી_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        જો (tok != TOK_LINEFEED) {
            જો (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                જાઓ લીટી_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        જો (file->fd > 0)
            total_લીટીઓ += file->લીટી_અંક - n;
        file->લીટી_અંક = n;
        તોડો;

    સ્થિતિ TOK_ERROR:
    સ્થિતિ TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        જ્યારે (c != '\n' && c != CH_EOF) {
            જો ((q - buf) < કદ(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        જો (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        નહીંતર
            tcc_warning("#warning %s", buf);
        next_nomacro();
        તોડો;
    }
    સ્થિતિ TOK_PRAGMA:
        જો (!pragma_parse(s1))
            જાઓ ignore;
        તોડો;
    સ્થિતિ TOK_LINEFEED:
        જાઓ the_end;
    મૂળભૂત:
        /* ignore gas line comment in an 'S' file. */
        જો (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            જાઓ ignore;
        જો (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            જાઓ ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        જાઓ the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
સ્થિર શૂન્ય parse_escape_string(CString *outstr, અચલ uint8_t *buf, પૂર્ણાંક is_long)
{
    પૂર્ણાંક c, n, i;
    અચલ uint8_t *p;

    p = buf;
    માટે(;;) {
        c = *p;
        જો (c == '\0')
            તોડો;
        જો (c == '\\') {
            p++;
            /* escape */
            c = *p;
            પસંદગી(c) {
            સ્થિતિ '0': સ્થિતિ '1': સ્થિતિ '2': સ્થિતિ '3':
            સ્થિતિ '4': સ્થિતિ '5': સ્થિતિ '6': સ્થિતિ '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                જો (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    જો (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                જાઓ add_char_nonext;
            સ્થિતિ 'x': i = 0; જાઓ parse_hex_or_ucn;
            સ્થિતિ 'u': i = 4; જાઓ parse_hex_or_ucn;
            સ્થિતિ 'U': i = 8; જાઓ parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                કરો {
                    c = *p;
                    જો (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    નહીંતર જો (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    નહીંતર જો (isnum(c))
                        c = c - '0';
                    નહીંતર જો (i >= 0)
                        expect("more hex digits in universal-character-name");
                    નહીંતર
                        જાઓ add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } જ્યારે (--i);
		જો (is_long) {
    add_hex_or_ucn:
                    c = n;
		    જાઓ add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                ચાલુ;
            સ્થિતિ 'a':
                c = '\a';
                તોડો;
            સ્થિતિ 'b':
                c = '\b';
                તોડો;
            સ્થિતિ 'f':
                c = '\f';
                તોડો;
            સ્થિતિ 'n':
                c = '\n';
                તોડો;
            સ્થિતિ 'r':
                c = '\r';
                તોડો;
            સ્થિતિ 't':
                c = '\t';
                તોડો;
            સ્થિતિ 'v':
                c = '\v';
                તોડો;
            સ્થિતિ 'e':
                જો (!gnu_ext)
                    જાઓ invalid_escape;
                c = 27;
                તોડો;
            સ્થિતિ '\'':
            સ્થિતિ '\"':
            સ્થિતિ '\\': 
            સ્થિતિ '?':
                તોડો;
            મૂળભૂત:
            invalid_escape:
                જો (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                નહીંતર
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                તોડો;
            }
        } નહીંતર જો (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            પૂર્ણાંક cont; /* count of continuation bytes */
            પૂર્ણાંક skip; /* how many bytes should skip when error occurred */
            પૂર્ણાંક i;

            /* decode leading byte */
            જો (c < 0xC2) {
	            skip = 1; જાઓ invalid_utf8_sequence;
            } નહીંતર જો (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } નહીંતર જો (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } નહીંતર જો (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } નહીંતર {
	            skip = 1; જાઓ invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            માટે (i = 1; i <= cont; i++) {
                પૂર્ણાંક l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                જો (i == 1) {
                    પસંદગી (c) {
                    સ્થિતિ 0xE0: l = 0xA0; તોડો;
                    સ્થિતિ 0xED: h = 0x9F; તોડો;
                    સ્થિતિ 0xF0: l = 0x90; તોડો;
                    સ્થિતિ 0xF4: h = 0x8F; તોડો;
                    }
                }

                જો (p[i] < l || p[i] > h) {
                    skip = i; જાઓ invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            જાઓ add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            જાઓ add_char_nonext;

        }
        p++;
    add_char_nonext:
        જો (!is_long)
            cstr_ccat(outstr, c);
        નહીંતર {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            જો (c < 0x10000) {
                cstr_wccat(outstr, c);
            } નહીંતર {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#નહીંતર
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    જો (!is_long)
        cstr_ccat(outstr, '\0');
    નહીંતર
        cstr_wccat(outstr, '\0');
}

સ્થિર શૂન્ય parse_string(અચલ અક્ષર *s, પૂર્ણાંક len)
{
    uint8_t buf[1000], *p = buf;
    પૂર્ણાંક is_long, sep;

    જો ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    જો (len >= કદ buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    જો (p != buf)
        tcc_free(p);

    જો (sep == '\'') {
        પૂર્ણાંક char_size, i, n, c;
        /* XXX: make it portable */
        જો (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        નહીંતર
            tok = TOK_LCHAR, char_size = કદ(nwchar_t);
        n = tokcstr.size / char_size - 1;
        જો (n < 1)
            tcc_error("empty character constant");
        જો (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        માટે (c = i = 0; i < n; ++i) {
            જો (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            નહીંતર
                c = (c << 8) | ((અક્ષર *)tokcstr.data)[i];
        }
        tokc.i = c;
    } નહીંતર {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        જો (!is_long)
            tok = TOK_STR;
        નહીંતર
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
સ્થિર પૂર્ણાંક bn_lshift(unsigned પૂર્ણાંક *bn, પૂર્ણાંક shift, પૂર્ણાંક or_val)
{
    પૂર્ણાંક i;
    unsigned પૂર્ણાંક v;
    જો (bn[BN_SIZE - 1] >> (32 - shift))
	પાછા shift;
    માટે(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    પાછા 0;
}

સ્થિર શૂન્ય bn_zero(unsigned પૂર્ણાંક *bn)
{
    પૂર્ણાંક i;
    માટે(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
સ્થિર શૂન્ય parse_સંખ્યા(અચલ અક્ષર *p)
{
    પૂર્ણાંક b, t, shift, frac_bits, s, exp_val, ch;
    અક્ષર *q;
    unsigned પૂર્ણાંક bn[BN_SIZE];
    long દ્વિગુણ d;

    /*સંખ્યા*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    જો (t == '.') {
        જાઓ float_frac_parse;
    } નહીંતર જો (t == '0') {
        જો (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } નહીંતર જો (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    જ્યારે (1) {
        જો (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        નહીંતર જો (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        નહીંતર જો (isnum(ch))
            t = ch - '0';
        નહીંતર
            તોડો;
        જો (t >= b)
            તોડો;
        જો (q >= token_buf + STRING_MAX_SIZE) {
        અંક_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    જો (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        જો (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            જો (b == 16)
                shift = 4;
            નહીંતર 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            જ્યારે (1) {
                t = *q++;
                જો (t == '\0') {
                    તોડો;
                } નહીંતર જો (t >= 'a') {
                    t = t - 'a' + 10;
                } નહીંતર જો (t >= 'A') {
                    t = t - 'A' + 10;
                } નહીંતર {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            જો (ch == '.') {
                ch = *p++;
                જ્યારે (1) {
                    t = ch;
                    જો (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } નહીંતર જો (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } નહીંતર જો (t >= '0' && t <= '9') {
                        t = t - '0';
                    } નહીંતર {
                        તોડો;
                    }
                    જો (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            જો (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            જો (ch == '+') {
                ch = *p++;
            } નહીંતર જો (ch == '-') {
                s = -1;
                ch = *p++;
            }
            જો (ch < '0' || ch > '9')
                expect("exponent digits");
            જ્યારે (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		જો (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long દ્વિગુણ)bn[3] * 79228162514264337593543950336.0L +
	        (long દ્વિગુણ)bn[2] * 18446744073709551616.0L +
	        (long દ્વિગુણ)bn[1] * 4294967296.0L +
	        (long દ્વિગુણ)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            જો (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (દશાંશ)d;
            } નહીંતર જો (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } નહીંતર {
                tok = TOK_CDOUBLE;
                tokc.d = (દ્વિગુણ)d;
            }
        } નહીંતર {
            /* decimal floats */
            જો (ch == '.') {
                જો (q >= token_buf + STRING_MAX_SIZE)
                    જાઓ અંક_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                જ્યારે (ch >= '0' && ch <= '9') {
                    જો (q >= token_buf + STRING_MAX_SIZE)
                        જાઓ અંક_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            જો (ch == 'e' || ch == 'E') {
                જો (q >= token_buf + STRING_MAX_SIZE)
                    જાઓ અંક_too_long;
                *q++ = ch;
                ch = *p++;
                જો (ch == '-' || ch == '+') {
                    જો (q >= token_buf + STRING_MAX_SIZE)
                        જાઓ અંક_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                જો (ch < '0' || ch > '9')
                    expect("exponent digits");
                જ્યારે (ch >= '0' && ch <= '9') {
                    જો (q >= token_buf + STRING_MAX_SIZE)
                        જાઓ અંક_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            જો (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, ખાલી);
            } નહીંતર જો (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, ખાલી);
            } નહીંતર {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, ખાલી);
            }
        }
    } નહીંતર {
        unsigned long long n, n1;
        પૂર્ણાંક lcount, ucount, ov = 0;
        અચલ અક્ષર *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        જો (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        જ્યારે(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            જો (t == '\0')
                તોડો;
            નહીંતર જો (t >= 'a')
                t = t - 'a' + 10;
            નહીંતર જો (t >= 'A')
                t = t - 'A' + 10;
            નહીંતર
                t = t - '0';
            જો (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            જો (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        માટે(;;) {
            t = toup(ch);
            જો (t == 'L') {
                જો (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                જો (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } નહીંતર જો (t == 'U') {
                જો (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } નહીંતર {
                તોડો;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        જો (pp_પદાવલિ)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        જો (ucount == 0 && b == 10) {
            જો (lcount <= (LONG_SIZE == 4)) {
                જો (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            જો (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } નહીંતર {
            જો (lcount <= (LONG_SIZE == 4)) {
                જો (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                નહીંતર જો (n >= 0x80000000U)
                    ucount = 1;
            }
            જો (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        જો (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	જો (lcount) {
            tok = TOK_CLONG;
            જો (lcount == 2)
                tok = TOK_CLLONG;
	}
	જો (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    જો (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    સ્થિતિ c1:                                    \
        PEEKC(c, p);                            \
        જો (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } નહીંતર {                                \
            tok = tok1;                         \
        }                                       \
        તોડો;

/* return next token without macro substitution */
સ્થિર શૂન્ય next_nomacro(શૂન્ય)
{
    પૂર્ણાંક t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned પૂર્ણાંક h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    પસંદગી(c) {
    સ્થિતિ ' ':
    સ્થિતિ '\t':
        tok = c;
        p++;
 maybe_space:
        જો (parse_flags & PARSE_FLAG_SPACES)
            જાઓ keep_tok_flags;
        જ્યારે (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        જાઓ redo_no_start;
    સ્થિતિ '\f':
    સ્થિતિ '\v':
    સ્થિતિ '\r':
        p++;
        જાઓ redo_no_start;
    સ્થિતિ '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        જો (c == '\\')
            જાઓ parse_simple;
        જો (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            જો (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                જાઓ maybe_newline;
            } નહીંતર જો (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } નહીંતર જો (s1->ifdef_ઢગલો_ptr != file->ifdef_ઢગલો_ptr) {
                tcc_error("missing #endif");
            } નહીંતર જો (s1->include_ઢગલો_ptr == s1->include_ઢગલો) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } નહીંતર {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                જો (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, ખાલી));
#endif
                    શોધ_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_ઢગલો_ptr--;
                p = file->buf_ptr;
                જાઓ maybe_newline;
            }
        } નહીંતર {
            જાઓ redo_no_start;
        }
        તોડો;

    સ્થિતિ '\n':
        file->લીટી_અંક++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        જો (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            જાઓ redo_no_start;
        tok = TOK_LINEFEED;
        જાઓ keep_tok_flags;

    સ્થિતિ '#':
        /* XXX: simplify */
        PEEKC(c, p);
        જો ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            જાઓ maybe_newline;
        } નહીંતર {
            જો (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } નહીંતર {
#જો !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                જો (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_લીટી_comment(p - 1);
                    જાઓ redo_no_start;
                } નહીંતર
#endif
                {
                    tok = '#';
                }
            }
        }
        તોડો;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    સ્થિતિ '$':
        જો (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            જાઓ parse_simple;

    સ્થિતિ 'a': સ્થિતિ 'b': સ્થિતિ 'c': સ્થિતિ 'd':
    સ્થિતિ 'e': સ્થિતિ 'f': સ્થિતિ 'g': સ્થિતિ 'h':
    સ્થિતિ 'i': સ્થિતિ 'j': સ્થિતિ 'k': સ્થિતિ 'l':
    સ્થિતિ 'm': સ્થિતિ 'n': સ્થિતિ 'o': સ્થિતિ 'p':
    સ્થિતિ 'q': સ્થિતિ 'r': સ્થિતિ 's': સ્થિતિ 't':
    સ્થિતિ 'u': સ્થિતિ 'v': સ્થિતિ 'w': સ્થિતિ 'x':
    સ્થિતિ 'y': સ્થિતિ 'z': 
    સ્થિતિ 'A': સ્થિતિ 'B': સ્થિતિ 'C': સ્થિતિ 'D':
    સ્થિતિ 'E': સ્થિતિ 'F': સ્થિતિ 'G': સ્થિતિ 'H':
    સ્થિતિ 'I': સ્થિતિ 'J': સ્થિતિ 'K': 
    સ્થિતિ 'M': સ્થિતિ 'N': સ્થિતિ 'O': સ્થિતિ 'P':
    સ્થિતિ 'Q': સ્થિતિ 'R': સ્થિતિ 'S': સ્થિતિ 'T':
    સ્થિતિ 'U': સ્થિતિ 'V': સ્થિતિ 'W': સ્થિતિ 'X':
    સ્થિતિ 'Y': સ્થિતિ 'Z': 
    સ્થિતિ '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        જ્યારે (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_અંક))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        જો (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            માટે(;;) {
                ts = *pts;
                જો (!ts)
                    તોડો;
                જો (ts->len == len && !memcmp(ts->str, p1, len))
                    જાઓ token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (અક્ષર *) p1, len);
        token_found: ;
        } નહીંતર {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (અક્ષર *) p1, len);
            p--;
            PEEKC(c, p);
            જ્યારે (isidnum_table[c - CH_EOF] & (IS_ID|IS_અંક))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        તોડો;
    સ્થિતિ 'L':
        t = p[1];
        જો (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            જો (c == '\'' || c == '\"') {
                is_long = 1;
                જાઓ str_const;
            }
            *--p = c = 'L';
        }
        જાઓ parse_ident_fast;

    સ્થિતિ '0': સ્થિતિ '1': સ્થિતિ '2': સ્થિતિ '3':
    સ્થિતિ '4': સ્થિતિ '5': સ્થિતિ '6': સ્થિતિ '7':
    સ્થિતિ '8': સ્થિતિ '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_અંક:
        cstr_reset(&tokcstr);
        માટે(;;) {
            cstr_ccat(&tokcstr, t);
            જો (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_અંક))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((અક્ષર*)tokcstr.data)[0] == '0'
                                && toup(((અક્ષર*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                તોડો;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        તોડો;

    સ્થિતિ '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        જો (isnum(c)) {
            t = '.';
            જાઓ parse_અંક;
        } નહીંતર જો ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_અંક))) {
            *--p = c = '.';
            જાઓ parse_ident_fast;
        } નહીંતર જો (c == '.') {
            PEEKC(c, p);
            જો (c == '.') {
                p++;
                tok = TOK_DOTS;
            } નહીંતર {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } નહીંતર {
            tok = '.';
        }
        તોડો;
    સ્થિતિ '\'':
    સ્થિતિ '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        જો (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        તોડો;

    સ્થિતિ '<':
        PEEKC(c, p);
        જો (c == '=') {
            p++;
            tok = TOK_LE;
        } નહીંતર જો (c == '<') {
            PEEKC(c, p);
            જો (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } નહીંતર {
                tok = TOK_SHL;
            }
        } નહીંતર {
            tok = TOK_LT;
        }
        તોડો;
    સ્થિતિ '>':
        PEEKC(c, p);
        જો (c == '=') {
            p++;
            tok = TOK_GE;
        } નહીંતર જો (c == '>') {
            PEEKC(c, p);
            જો (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } નહીંતર {
                tok = TOK_SAR;
            }
        } નહીંતર {
            tok = TOK_GT;
        }
        તોડો;
        
    સ્થિતિ '&':
        PEEKC(c, p);
        જો (c == '&') {
            p++;
            tok = TOK_LAND;
        } નહીંતર જો (c == '=') {
            p++;
            tok = TOK_A_AND;
        } નહીંતર {
            tok = '&';
        }
        તોડો;
        
    સ્થિતિ '|':
        PEEKC(c, p);
        જો (c == '|') {
            p++;
            tok = TOK_LOR;
        } નહીંતર જો (c == '=') {
            p++;
            tok = TOK_A_OR;
        } નહીંતર {
            tok = '|';
        }
        તોડો;

    સ્થિતિ '+':
        PEEKC(c, p);
        જો (c == '+') {
            p++;
            tok = TOK_INC;
        } નહીંતર જો (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } નહીંતર {
            tok = '+';
        }
        તોડો;
        
    સ્થિતિ '-':
        PEEKC(c, p);
        જો (c == '-') {
            p++;
            tok = TOK_DEC;
        } નહીંતર જો (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } નહીંતર જો (c == '>') {
            p++;
            tok = TOK_ARROW;
        } નહીંતર {
            tok = '-';
        }
        તોડો;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    સ્થિતિ '/':
        PEEKC(c, p);
        જો (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            જાઓ maybe_space;
        } નહીંતર જો (c == '/') {
            p = parse_લીટી_comment(p);
            tok = ' ';
            જાઓ maybe_space;
        } નહીંતર જો (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } નહીંતર {
            tok = '/';
        }
        તોડો;
        
        /* simple tokens */
    સ્થિતિ '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        જો (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_લીટી_comment(p);
            જાઓ redo_no_start;
        }
#endif
    સ્થિતિ '(':
    સ્થિતિ ')':
    સ્થિતિ '[':
    સ્થિતિ ']':
    સ્થિતિ '{':
    સ્થિતિ '}':
    સ્થિતિ ',':
    સ્થિતિ ';':
    સ્થિતિ ':':
    સ્થિતિ '?':
    સ્થિતિ '~':
    parse_simple:
        tok = c;
        p++;
        તોડો;
    સ્થિતિ 0xEF: /* UTF8 BOM ? */
        જો (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            જાઓ redo_no_start;
        }
    મૂળભૂત:
        જો (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    જાઓ parse_ident_fast;
        જો (parse_flags & PARSE_FLAG_ASM_FILE)
            જાઓ parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        તોડો;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#જો defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
સ્થિર પૂર્ણાંક indent;
સ્થિર શૂન્ય define_print(TCCState *s1, પૂર્ણાંક v);
સ્થિર શૂન્ય pp_print(અચલ અક્ષર *સંદેશ, પૂર્ણાંક v, અચલ પૂર્ણાંક *str)
{
    FILE *fp = tcc_state->ppfp;

    જો (સંદેશ[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    નહીંતર જો (સંદેશ[0] == '+')
         ++indent, ++સંદેશ;
    નહીંતર જો (સંદેશ[0] == '-')
        --indent, ++સંદેશ;

    fprintf(fp, "%*s", indent, "");
    જો (સંદેશ[0] == '#') {
        define_print(tcc_state, v);
    } નહીંતર {
        tok_print(str, v ? "%s %s" : "%s", સંદેશ, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#નહીંતર
#define PP_PRINT(x)
#endif

સ્થિર પૂર્ણાંક macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    અચલ પૂર્ણાંક *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
સ્થિર પૂર્ણાંક *macro_arg_subst(Sym **nested_list, અચલ પૂર્ણાંક *macro_str, Sym *args)
{
    પૂર્ણાંક t, t0, t1, t2, n;
    અચલ પૂર્ણાંક *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    માટે (s = args, n = 0; s; s = s->prev, ++n);
    જ્યારે (n--) {
        માટે (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    જ્યારે(1) {
        TOK_GET(&t, &macro_str, &cval);
        જો (!t)
            તોડો;
        જો (t == '#') {
            /* stringize */
            કરો t = *macro_str++; જ્યારે (t == ' ');
            s = sym_find2(args, t);
            જો (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                જ્યારે (*st != TOK_EOF) {
                    અચલ અક્ષર *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    જ્યારે (*s) {
                        જો (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        નહીંતર
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
            } નહીંતર જો ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } નહીંતર {
                expect("macro parameter after '#'");
            }
        } નહીંતર જો (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            જો (s) {
                st = s->d;
                n = 0;
                જ્યારે ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                જો (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    જો (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        પૂર્ણાંક c = str.str[str.len - 1];
                        જ્યારે (str.str[--str.len] != ',')
                            ;
                        જો (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } નહીંતર {
                            /* suppress '##' and add variable */
                            str.len++;
                            જો (c == ' ')
                                str.str[str.len++] = c;
                            જાઓ add_var;
                        }
                    } નહીંતર {
                        જો (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } નહીંતર {
            add_var:
		    જો (!s->e) {
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
                જ્યારે (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } નહીંતર {
                tok_str_add(&str, t);
            }
        } નહીંતર {
            tok_str_add2(&str, t, &cval);
        }
        જો (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    પાછા str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
સ્થિર અંતઃરેખ પૂર્ણાંક *macro_twosharps(અચલ પૂર્ણાંક *ptr0)
{
    પૂર્ણાંક t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    અચલ પૂર્ણાંક *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    માટે (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        જો (t1 == 0)
            તોડો;
        માટે (;;) {
            n = 0;
            જ્યારે ((t2 = ptr[n]) == ' ')
                ++n;
            જો (t2 != TOK_PPJOIN)
                તોડો;
            ptr += n;
            જ્યારે ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            જો (t2 == TOK_PLCHLDR)
                ચાલુ;
            જો (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        જો (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            માટે (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                જો (*file->buf_ptr == 0)
                    તોડો;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        જો (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    પાછા macro_str1.str;
}

સ્થિર પૂર્ણાંક peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    પૂર્ણાંક c;
    માટે (;;) {
        PEEKC(c, p);
        પસંદગી (c) {
        સ્થિતિ '/':
            PEEKC(c, p);
            જો (c == '*')
                p = parse_comment(p);
            નહીંતર જો (c == '/')
                p = parse_લીટી_comment(p);
            નહીંતર {
                c = *--p = '/';
                જાઓ leave;
            }
            --p, c = ' ';
            તોડો;
        સ્થિતિ ' ': સ્થિતિ '\t':
            તોડો;
        સ્થિતિ '\f': સ્થિતિ '\v': સ્થિતિ '\r':
            ચાલુ;
        સ્થિતિ '\n':
            file->લીટી_અંક++, tok_flags |= TOK_FLAG_BOL;
            તોડો;
        મૂળભૂત: leave:
            file->buf_ptr = p;
            પાછા c;
        }
        જો (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
સ્થિર પૂર્ણાંક next_argstream(Sym **nested_list, TokenString *ws_str)
{
    પૂર્ણાંક t;
    Sym *sa;

    જ્યારે (macro_ptr) {
        અચલ પૂર્ણાંક *m = macro_ptr;
        જ્યારે ((t = *m) != 0) {
            જો (ws_str) {
                જો (t != ' ')
                    પાછા t;
                ++m;
            } નહીંતર {
                TOK_GET(&tok, &macro_ptr, &tokc);
                પાછા tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        જો (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    જો (ws_str) {
        પાછા peek_file(ws_str);
    } નહીંતર {
        next_nomacro();
        જો (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        પાછા tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
સ્થિર પૂર્ણાંક macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    પૂર્ણાંક t;
    પૂર્ણાંક v = s->v;

    PP_PRINT(("#", v, s->d));
    જો (s->d) {
        પૂર્ણાંક *mstr = s->d;
        પૂર્ણાંક *jstr;
        Sym *sa;
        પૂર્ણાંક ret;

        જો (s->type.t & MACRO_FUNC) {
            પૂર્ણાંક saved_parse_flags = parse_flags;
            TokenString str;
            પૂર્ણાંક parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            જો (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                જો (parse_flags & PARSE_FLAG_SPACES)
                    માટે (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                પાછા 0;
            } નહીંતર {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = ખાલી;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            માટે(;;) {
                કરો {
                    t = next_argstream(nested_list, ખાલી);
                } જ્યારે (t == ' ' || --i);

                જો (!sa) {
                    જો (t == ')') /* handle '()' case */
                        તોડો;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                જ્યારે (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    જો (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    જો (t == '(')
                        parlevel++;
                    જો (t == ')')
                        parlevel--;
                    જો (t == ' ')
                        str.need_spc |= 1;
                    નહીંતર
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, ખાલી);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                જો (t == ')') {
                    જો (!sa)
                        તોડો;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    જો (sa->type.t && gnu_ext)
                        જાઓ empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            જ્યારે (sa) {
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
        જો (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        જો (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        જો (jstr != mstr)
            tok_str_free_str(jstr);
        જો (mstr != s->d)
            tok_str_free_str(mstr);
        પાછા ret;

    } નહીંતર {
        CValue cval;
        અક્ષર buf[32], *cstrval = buf;

        /* special macros */
        જો (v == TOK_લીટી_2 || v == TOK___COUNTER__) {
            t = v == TOK_લીટી_2 ? file->લીટી_અંક : pp_counter++;
            snprintf(buf, કદ(buf), "%d", t);
            t = TOK_PPNUM;
            જાઓ add_cstr1;

        } નહીંતર જો (v == TOK___FILE__) {
            cstrval = file->filename;
            જાઓ add_cstr;

        } નહીંતર જો (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            સંરચના tm *tm;
            time(&ti);
            tm = localtime(&ti);
            જો (v == TOK___DATE__) {
                સ્થિર અક્ષર અચલ ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, કદ(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } નહીંતર {
                snprintf(buf, કદ(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        પાછા 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
સ્થિર પૂર્ણાંક macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    અચલ પૂર્ણાંક *macro_str
    )
{
    Sym *s;
    પૂર્ણાંક t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    પૂર્ણાંક tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    જ્યારે (1) {
        TOK_GET(&t, &macro_str, &cval);
        જો (t == 0 || t == TOK_EOF)
            તોડો;
        જો (t >= TOK_IDENT) {
            s = define_find(t);
            જો (s == ખાલી || nosubst)
                જાઓ no_subst;
            /* if nested substitution, do nothing */
            જો (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                જાઓ no_subst;
            }
            str = tok_str_alloc();
            str->str = (પૂર્ણાંક*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            જો (macro_ઢગલો != str) {
                /* already finished by reading function macro arguments */
                તોડો;
            }
            macro_str = macro_ptr;
            end_macro ();
        } નહીંતર જો (t == ' ') {
            જો (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } નહીંતર {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            જો (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            જો (t == TOK_DEFINED && pp_પદાવલિ)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    પાછા nosubst;
}

/* return next token with macro substitution */
ST_FUNC શૂન્ય next(શૂન્ય)
{
    પૂર્ણાંક t;
    જ્યારે (macro_ptr) {
redo:
        t = *macro_ptr;
        જો (TOK_HAS_કિંમત(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            જો (t == TOK_LINENUM) {
                file->લીટી_અંક = tokc.i;
                જાઓ redo;
            }
            જાઓ convert;
        } નહીંતર જો (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            ચાલુ;
        } નહીંતર જો (t == TOK_EOF) {
            /* do nothing */
        } નહીંતર {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            જો (t == '\\') {
                જો (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        પાછા;
    }

    next_nomacro();
    t = tok;
    જો (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        જો (s) {
            Sym *nested_list = ખાલી;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            જાઓ redo;
        }
        પાછા;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    જો (t == TOK_PPNUM) {
        જો  (parse_flags & PARSE_FLAG_TOK_અંક)
            parse_સંખ્યા(tokc.str.data);
    } નહીંતર જો (t == TOK_PPSTR) {
        જો (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN શૂન્ય unget_tok(પૂર્ણાંક last_tok)
{
    TokenString *str = &unget_buf;
    પૂર્ણાંક alloc = 0;
    જો (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    જો (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

સ્થિર અચલ અક્ષર * અચલ target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# જો PTR_SIZE == 8
    "_WIN64\0"
# endif
#નહીંતર
# જો defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# નહીંતર
    "__linux__\0"
    "__linux\0"
#  જો TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

સ્થિર શૂન્ય putdef(CString *cs, અચલ અક્ષર *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

સ્થિર શૂન્ય putdefs(CString *cs, અચલ અક્ષર *p)
{
    જ્યારે (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

સ્થિર શૂન્ય tcc_predefs(TCCState *s1, CString *cs, પૂર્ણાંક is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    જો (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    જો (is_asm)
      putdef(cs, "__ASSEMBLER__");
    જો (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    જો (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    જો (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    જો (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    જો (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    જો (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    જો (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    જો (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    જો (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#જો CONFIG_TCC_PREDEFS
        #અન્તર્ભાવ "tccdefs_.h" /* include as strings */
#નહીંતર
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC શૂન્ય preprocess_start(TCCState *s1, પૂર્ણાંક filetype)
{
    પૂર્ણાંક is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_ઢગલો_ptr = s1->include_ઢગલો;
    s1->ifdef_ઢગલો_ptr = s1->ifdef_ઢગલો;
    file->ifdef_ઢગલો_ptr = s1->ifdef_ઢગલો_ptr;
    pp_પદાવલિ = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_ઢગલો[0] = 0;
    s1->pack_ઢગલો_ptr = s1->pack_ઢગલો;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    જો (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        જો (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        જો (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_ઢગલો_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC શૂન્ય preprocess_end(TCCState *s1)
{
    જ્યારે (macro_ઢગલો)
        end_macro();
    macro_ptr = ખાલી;
    જ્યારે (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC પૂર્ણાંક set_idnum(પૂર્ણાંક c, પૂર્ણાંક val)
{
    પૂર્ણાંક prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    પાછા prev;
}

ST_FUNC શૂન્ય tccpp_new(TCCState *s)
{
    પૂર્ણાંક i, c;
    અચલ અક્ષર *p, *r;

    /* init isid table */
    માટે(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_અંક
            : 0);

    માટે(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * કદ(TokenSym *));
    memset(s->cached_includes_hash, 0, કદ s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    જ્યારે (*p) {
        r = p;
        માટે(;;) {
            c = *r++;
            જો (c == '\0')
                તોડો;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_ધકેલો(TOK_લીટી_2, MACRO_OBJ, ખાલી, ખાલી);
    define_ધકેલો(TOK___FILE__, MACRO_OBJ, ખાલી, ખાલી);
    define_ધકેલો(TOK___DATE__, MACRO_OBJ, ખાલી, ખાલી);
    define_ધકેલો(TOK___TIME__, MACRO_OBJ, ખાલી, ખાલી);
    define_ધકેલો(TOK___COUNTER__, MACRO_OBJ, ખાલી, ખાલી);
}

ST_FUNC શૂન્ય tccpp_delete(TCCState *s)
{
    પૂર્ણાંક i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    જો (n > total_idents)
        total_idents = n;
    માટે (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ખાલી;

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

સ્થિર પૂર્ણાંક pp_need_space(પૂર્ણાંક a, પૂર્ણાંક b);

સ્થિર શૂન્ય tok_print(અચલ પૂર્ણાંક *str, અચલ અક્ષર *સંદેશ, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    પૂર્ણાંક t, t0, s;
    CValue cval;

    va_start(ap, સંદેશ);
    vfprintf(fp, સંદેશ, ap);
    va_end(ap);

    s = t0 = 0;
    જ્યારે (str) {
	TOK_GET(&t, &str, &cval);
	જો (t == 0 || t == TOK_EOF)
	    તોડો;
        જો (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

સ્થિર શૂન્ય pp_લીટી(TCCState *s1, BufferedFile *f, પૂર્ણાંક level)
{
    પૂર્ણાંક d = f->લીટી_અંક - f->લીટી_ref;

    જો (s1->dflag & 4)
	પાછા;

    જો (s1->Pflag == લીટી_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } નહીંતર જો (level == 0 && f->લીટી_ref && d < 8) {
	જ્યારે (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } નહીંતર જો (s1->Pflag == લીટી_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->લીટી_અંક, f->filename);
    } નહીંતર {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->લીટી_અંક, f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->લીટી_ref = f->લીટી_અંક;
}

સ્થિર શૂન્ય define_print(TCCState *s1, પૂર્ણાંક v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    જો (ખાલી == s || ખાલી == s->d)
        પાછા;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, ખાલી));
    જો (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        જો (a)
            માટે (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, ખાલી));
                જો (!(a = a->next))
                    તોડો;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

સ્થિર શૂન્ય pp_debug_defines(TCCState *s1)
{
    પૂર્ણાંક v, t;
    અચલ અક્ષર *vs;
    FILE *fp;

    t = pp_debug_tok;
    જો (t == 0)
        પાછા;

    file->લીટી_અંક--;
    pp_લીટી(s1, file, 0);
    file->લીટી_ref = ++file->લીટી_અંક;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, ખાલી);
    જો (t == TOK_DEFINE) {
        define_print(s1, v);
    } નહીંતર જો (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } નહીંતર જો (t == TOK_ધકેલો_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } નહીંતર જો (t == TOK_કાઢો_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
સ્થિર પૂર્ણાંક pp_need_space(પૂર્ણાંક a, પૂર્ણાંક b)
{
    પાછા 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
સ્થિર પૂર્ણાંક pp_check_he0xE(પૂર્ણાંક t, અચલ અક્ષર *p)
{
    જો (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        પાછા 'E';
    પાછા t;
}

/* Preprocess the current file */
ST_FUNC પૂર્ણાંક tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    પૂર્ણાંક token_seen, spcs, level;
    અચલ અક્ષર *p;
    અક્ષર white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    જો (s1->Pflag == લીટી_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_અંક, s1->Pflag = 1;

    જો (s1->do_bench) {
	/* for PP benchmarks */
	કરો next(); જ્યારે (tok != TOK_EOF);
	પાછા 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    જો (file->prev)
        pp_લીટી(s1, file->prev, level++);
    pp_લીટી(s1, file, level);

    માટે (;;) {
        iptr = s1->include_ઢગલો_ptr;
        next();
        જો (tok == TOK_EOF)
            તોડો;

        level = s1->include_ઢગલો_ptr - iptr;
        જો (level) {
            જો (level > 0)
                pp_લીટી(s1, *iptr, 0);
            pp_લીટી(s1, file, level);
        }
        જો (s1->dflag & 7) {
            pp_debug_defines(s1);
            જો (s1->dflag & 4)
                ચાલુ;
        }

        જો (is_space(tok)) {
            જો (spcs < કદ white - 1)
                white[spcs++] = tok;
            ચાલુ;
        } નહીંતર જો (tok == TOK_LINEFEED) {
            spcs = 0;
            જો (token_seen == TOK_LINEFEED)
                ચાલુ;
            ++file->લીટી_ref;
        } નહીંતર જો (token_seen == TOK_LINEFEED) {
            pp_લીટી(s1, file, 0);
        } નહીંતર જો (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    પાછા 0;
}

/* ------------------------------------------------------------------------- */
