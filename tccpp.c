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
#அந்தர்பாவ "tcc.h"

/* #define to 1 to enable (see parse_pp_string()) */
#define ACCEPT_LF_IN_STRINGS 0

/********************************************************/
/* global variables */

ST_DATA முழு tok_flags;
ST_DATA முழு parse_flags;

ST_DATA கட்டமைப்பு BufferedFile *file;
ST_DATA முழு tok;
ST_DATA CValue tokc;
ST_DATA மாறிலி முழு *macro_ptr;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA முழு tok_ident;
ST_DATA TokenSym **table_ident;
ST_DATA முழு pp_கோவை;

/* ------------------------------------------------------------------------- */

நிலையான TokenSym *hash_ident[TOK_HASH_SIZE];
நிலையான எழுத்து token_buf[STRING_MAX_SIZE + 1];
நிலையான CString cstr_buf;
நிலையான TokenString tokstr_buf;
நிலையான TokenString unget_buf;
நிலையான unsigned எழுத்து isidnum_table[256 - CH_EOF];
நிலையான முழு pp_debug_tok, pp_debug_symv;
நிலையான முழு pp_counter;
நிலையான வெறுமை tok_print(மாறிலி முழு *str, மாறிலி எழுத்து *செய்தி, ...);
நிலையான வெறுமை next_nomacro(வெறுமை);
நிலையான வெறுமை parse_எண்(மாறிலி எழுத்து *p);
நிலையான வெறுமை parse_string(மாறிலி எழுத்து *p, முழு len);

நிலையான கட்டமைப்பு TinyAlloc *toksym_alloc;
நிலையான கட்டமைப்பு TinyAlloc *tokstr_alloc;

நிலையான TokenString *macro_அடுக்கு;

நிலையான மாறிலி எழுத்து tcc_keywords[] = 
#define DEF(id, str) str "\0"
#அந்தர்பாவ "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
நிலையான மாறிலி unsigned எழுத்து tok_two_chars[] =
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

ST_FUNC வெறுமை skip(முழு c)
{
    எனில் (tok != c) {
        எழுத்து tmp[40];
        pstrcpy(tmp, அளவு tmp, get_tok_str(c, &tokc));
        tcc_error("'%s' expected (got '%s')", tmp, get_tok_str(tok, &tokc));
	}
    next();
}

ST_FUNC வெறுமை expect(மாறிலி எழுத்து *செய்தி)
{
    tcc_error("%s expected", செய்தி);
}

/* ------------------------------------------------------------------------- */
/* Custom allocator for tiny objects */

#define USE_TAL

#ifndef USE_TAL /* may cause memory leaks after errors */
#define tal_free(al, p) tcc_free(p)
#define tal_realloc(al, p, size) tcc_realloc(p, size)
#define tal_new(a,b)
#define tal_delete(a)
#இல்லையெனில்
#எனில் !defined(MEM_DEBUG)
#define tal_free(al, p) tal_free_impl(al, p)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size)
#define TAL_DEBUG_PARAMS
#இல்லையெனில்
#define TAL_DEBUG MEM_DEBUG
//#define TAL_INFO 1 /* collect and dump allocators stats */
#define tal_free(al, p) tal_free_impl(al, p, __FILE__, __LINE__)
#define tal_realloc(al, p, size) tal_realloc_impl(al, p, size, __FILE__, __LINE__)
#define TAL_DEBUG_PARAMS , மாறிலி எழுத்து *sfile, முழு sline
#endif

#define TOKSYM_TAL_SIZE (256 * 1024) /* allocator for TokenSym in table_ident */
#define TOKSTR_TAL_SIZE (256 * 1024) /* allocator for TokenString instances */

வகைவரை கட்டமைப்பு TinyAlloc {
    uint8_t *p;
    uint8_t *bufend;
    கட்டமைப்பு TinyAlloc *next;
    unsigned nb_allocs;
    unsigned size;
#எனில் TAL_INFO
    unsigned nb_peak;
    unsigned nb_total;
    uint8_t *peak_p;
#endif
    ஒன்றிப்பு {
        uint8_t buffer[1];
        size_t _aligner_;
    };
} TinyAlloc;

வகைவரை கட்டமைப்பு tal_header_t {
    size_t  size; /* word align */
#எனில் TAL_DEBUG
    முழு     வரி_இலக்கம்; /* negative line_num used for double free check */
    எழுத்து    file_name[40];
#endif
} tal_header_t;

#define TAL_ALIGN(size) \
    (((size) + (அளவு (size_t) - 1)) & ~(அளவு (size_t) - 1))

/* ------------------------------------------------------------------------- */

நிலையான TinyAlloc *tal_new(TinyAlloc **pal, unsigned size)
{
    TinyAlloc *al = tcc_malloc(அளவு(TinyAlloc) - அளவு (size_t) + size);
    al->p = al->buffer;
    al->bufend = al->buffer + size;
    al->nb_allocs = 0;
    al->next = *pal, *pal = al;
    al->size = al->next ? al->next->size : size;
#எனில் TAL_INFO
    al->nb_peak = 0;
    al->nb_total = 0;
    al->peak_p = al->p;
#endif
    திரும்பு al;
}

நிலையான வெறுமை tal_delete(TinyAlloc **pal)
{
    TinyAlloc *al = *pal, *next;

#எனில் TAL_INFO
    fprintf(stderr, "tal_delete (&tok%s_alloc):\n", pal == &toksym_alloc ? "sym" : "str");
#endif
tail_call:
#எனில் TAL_DEBUG && TAL_DEBUG != 3 /* do not check TAL leaks with -DMEM_DEBUG=3 */
#எனில் TAL_INFO
    fprintf(stderr, "  size %7d  nb_peak %5d  nb_total %6d  usage %5.1f%%\n",
            al->bufend - al->buffer, al->nb_peak, al->nb_total,
            (al->peak_p - al->buffer) * 100.0 / (al->bufend - al->buffer));
#endif
    எனில் (al->nb_allocs > 0) {
        uint8_t *p;
        fprintf(stderr, "TAL_DEBUG: memory leak %d chunk(s)\n", al->nb_allocs);
        p = al->buffer;
        போது (p < al->p) {
            tal_header_t *header = (tal_header_t *)p;
            எனில் (header->வரி_இலக்கம் > 0) {
                fprintf(stderr, "%s:%d: chunk of %d bytes leaked\n",
                        header->file_name, header->வரி_இலக்கம், (முழு)header->size);
            }
            p += header->size + அளவு(tal_header_t);
        }
#எனில் TAL_DEBUG == 2
        exit(2);
#endif
    }
#endif
    next = al->next;
    tcc_free(al);
    al = next;
    எனில் (al)
        செல் tail_call;
    *pal = al;
}

நிலையான வெறுமை tal_free_impl(TinyAlloc **pal, வெறுமை *p TAL_DEBUG_PARAMS)
{
    TinyAlloc *al, **உச்சி = pal;
    tal_header_t *header;

    எனில் (!p)
        திரும்பு;
    header = (tal_header_t *)p - 1;
#எனில் TAL_DEBUG
    எனில் (header->வரி_இலக்கம் < 0) {
        fprintf(stderr, "%s:%d: TAL_DEBUG: double frees chunk from\n",
                sfile, sline);
        fprintf(stderr, "%s:%d: %d bytes\n",
                header->file_name, (முழு)-header->வரி_இலக்கம், (முழு)header->size);
    } இல்லையெனில்
        header->வரி_இலக்கம் = -header->வரி_இலக்கம்;
#endif
    al = *pal;
    போது ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
        al = *(pal = &al->next);
    எனில் (0 == --al->nb_allocs) {
        *pal = al->next;
        எனில் ((al->bufend - al->buffer) > al->size) {
            //fprintf(stderr, "free big tal: %u\n", header->size);
            tcc_free(al);
        } இல்லையெனில் {
            /* reset and move to front */
            al->p = al->buffer;
            al->next = *உச்சி, *உச்சி = al;
        }
    } இல்லையெனில் எனில் ((uint8_t*)p + header->size == al->p) {
        al->p = (uint8_t*)header;
    }
}

நிலையான வெறுமை *tal_realloc_impl(TinyAlloc **pal, வெறுமை *p, unsigned size TAL_DEBUG_PARAMS)
{
    tal_header_t *header;
    வெறுமை *ret;
    unsigned adj_size = TAL_ALIGN(size) + அளவு(tal_header_t);
    TinyAlloc *al = *pal;

    எனில் (p) {
        /* reallpc case */
        போது ((uint8_t*)p < al->buffer || (uint8_t*)p > al->bufend)
            al = al->next;
        header = (tal_header_t *)p - 1;
        எனில் ((uint8_t*)p + header->size == al->p)
            al->p = (uint8_t*)header; /* maybe reuse */
        எனில் (al->p + adj_size > al->bufend) {
            ret = tal_realloc(pal, 0, size);
            memcpy(ret, p, header->size);
            tal_free(pal, p);
            திரும்பு ret;
        } இல்லையெனில் எனில் (al->p != (uint8_t*)header) {
            memcpy((tal_header_t*)al->p + 1, p, header->size);
#எனில் TAL_DEBUG
            header->வரி_இலக்கம் = -header->வரி_இலக்கம்;
#endif
        }
    } இல்லையெனில் {
        /* new alloc case */
        போது (al->p + adj_size > al->bufend) {
            al = al->next;
            எனில் (!al) {
                unsigned new_size = (*pal)->size;
                எனில் (adj_size > new_size) {
                    new_size = adj_size;
                    //fprintf(stderr, "%s:%d: alloc big tal: %u\n", file->filename, file->line_num, adj_size - sizeof(tal_header_t));
                }
                al = tal_new(pal, new_size);
                நிறுத்து;
            }
        }
        al->nb_allocs++;
    }
    header = (tal_header_t *)al->p;
    header->size = adj_size - அளவு(tal_header_t);
    al->p += adj_size;
    ret = header + 1;
#எனில்  TAL_DEBUG
    {
        முழு ofs = strlen(sfile) + 1 - அளவு header->file_name;
        strcpy(header->file_name, sfile + (ofs > 0 ? ofs : 0));
        header->வரி_இலக்கம் = sline;
#எனில் TAL_INFO
        எனில் (al->nb_peak < al->nb_allocs)
            al->nb_peak = al->nb_allocs;
        எனில் (al->peak_p < al->p)
            al->peak_p = al->p;
        al->nb_total++;
#endif
    }
#endif
    திரும்பு ret;
}

#endif /* USE_TAL */

/* ------------------------------------------------------------------------- */
/* CString handling */
நிலையான வெறுமை cstr_realloc(CString *cstr, முழு new_size)
{
    முழு size;

    size = cstr->size_allocated;
    எனில் (size < 8)
        size = 8; /* no need to allocate a too small first string */
    போது (size < new_size)
        size = size * 2;
    cstr->data = tcc_realloc(cstr->data, size);
    cstr->size_allocated = size;
}

/* add a byte */
ST_INLN வெறுமை cstr_ccat(CString *cstr, முழு ch)
{
    முழு size;
    size = cstr->size + 1;
    எனில் (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    cstr->data[size - 1] = ch;
    cstr->size = size;
}

ST_INLN எழுத்து *unicode_to_utf8 (எழுத்து *b, uint32_t Uc)
{
    எனில் (Uc<0x80) *b++=Uc;
    இல்லையெனில் எனில் (Uc<0x800) *b++=192+Uc/64, *b++=128+Uc%64;
    இல்லையெனில் எனில் (Uc-0xd800u<0x800) செல் error;
    இல்லையெனில் எனில் (Uc<0x10000) *b++=224+Uc/4096, *b++=128+Uc/64%64, *b++=128+Uc%64;
    இல்லையெனில் எனில் (Uc<0x110000) *b++=240+Uc/262144, *b++=128+Uc/4096%64, *b++=128+Uc/64%64, *b++=128+Uc%64;
    இல்லையெனில் error: tcc_error("0x%x is not a valid universal character", Uc);
    திரும்பு b;
}

/* add a unicode character expanded into utf8 */
ST_INLN வெறுமை cstr_u8cat(CString *cstr, முழு ch)
{
    எழுத்து buf[4], *e;
    e = unicode_to_utf8(buf, (uint32_t)ch);
    cstr_cat(cstr, buf, e - buf);
}

/* add string of 'len', or of its len/len+1 when 'len' == -1/0 */
ST_FUNC வெறுமை cstr_cat(CString *cstr, மாறிலி எழுத்து *str, முழு len)
{
    முழு size;
    எனில் (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    எனில் (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(cstr->data + cstr->size, str, len);
    cstr->size = size;
}

/* add a wide char */
ST_FUNC வெறுமை cstr_wccat(CString *cstr, முழு ch)
{
    முழு size;
    size = cstr->size + அளவு(nwchar_t);
    எனில் (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    *(nwchar_t *)(cstr->data + size - அளவு(nwchar_t)) = ch;
    cstr->size = size;
}

ST_FUNC வெறுமை cstr_new(CString *cstr)
{
    memset(cstr, 0, அளவு(CString));
}

/* free string and reset it to NULL */
ST_FUNC வெறுமை cstr_free(CString *cstr)
{
    tcc_free(cstr->data);
}

/* reset string to empty */
ST_FUNC வெறுமை cstr_reset(CString *cstr)
{
    cstr->size = 0;
}

ST_FUNC முழு cstr_vprintf(CString *cstr, மாறிலி எழுத்து *fmt, va_list ap)
{
    va_list v;
    முழு len, size = 80;
    க்கு (;;) {
        size += cstr->size;
        எனில் (size > cstr->size_allocated)
            cstr_realloc(cstr, size);
        size = cstr->size_allocated - cstr->size;
        va_copy(v, ap);
        len = vsnprintf(cstr->data + cstr->size, size, fmt, v);
        va_end(v);
        எனில் (len >= 0 && len < size)
            நிறுத்து;
        size *= 2;
    }
    cstr->size += len;
    திரும்பு len;
}

ST_FUNC முழு cstr_printf(CString *cstr, மாறிலி எழுத்து *fmt, ...)
{
    va_list ap; முழு len;
    va_start(ap, fmt);
    len = cstr_vprintf(cstr, fmt, ap);
    va_end(ap);
    திரும்பு len;
}

/* XXX: unicode ? */
நிலையான வெறுமை add_char(CString *cstr, முழு c)
{
    எனில் (c == '\'' || c == '\"' || c == '\\') {
        /* XXX: could be more precise if char or string */
        cstr_ccat(cstr, '\\');
    }
    எனில் (c >= 32 && c <= 126) {
        cstr_ccat(cstr, c);
    } இல்லையெனில் {
        cstr_ccat(cstr, '\\');
        எனில் (c == '\n') {
            cstr_ccat(cstr, 'n');
        } இல்லையெனில் {
            cstr_ccat(cstr, '0' + ((c >> 6) & 7));
            cstr_ccat(cstr, '0' + ((c >> 3) & 7));
            cstr_ccat(cstr, '0' + (c & 7));
        }
    }
}

/* ------------------------------------------------------------------------- */
/* allocate a new token */
நிலையான TokenSym *tok_alloc_new(TokenSym **pts, மாறிலி எழுத்து *str, முழு len)
{
    TokenSym *ts, **ptable;
    முழு i;

    எனில் (tok_ident >= SYM_FIRST_ANOM) 
        tcc_error("memory full (symbols)");

    /* expand token table if needed */
    i = tok_ident - TOK_IDENT;
    எனில் ((i % TOK_ALLOC_INCR) == 0) {
        ptable = tcc_realloc(table_ident, (i + TOK_ALLOC_INCR) * அளவு(TokenSym *));
        table_ident = ptable;
    }

    ts = tal_realloc(&toksym_alloc, 0, அளவு(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_define = வெற்று;
    ts->sym_label = வெற்று;
    ts->sym_struct = வெற்று;
    ts->sym_identifier = வெற்று;
    ts->len = len;
    ts->hash_next = வெற்று;
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    திரும்பு ts;
}

#define TOK_HASH_INIT 1
#define TOK_HASH_FUNC(h, c) ((h) + ((h) << 5) + ((h) >> 27) + (c))


/* find a token and add it if not found */
ST_FUNC TokenSym *tok_alloc(மாறிலி எழுத்து *str, முழு len)
{
    TokenSym *ts, **pts;
    முழு i;
    unsigned முழு h;
    
    h = TOK_HASH_INIT;
    க்கு(i=0;i<len;i++)
        h = TOK_HASH_FUNC(h, ((unsigned எழுத்து *)str)[i]);
    h &= (TOK_HASH_SIZE - 1);

    pts = &hash_ident[h];
    க்கு(;;) {
        ts = *pts;
        எனில் (!ts)
            நிறுத்து;
        எனில் (ts->len == len && !memcmp(ts->str, str, len))
            திரும்பு ts;
        pts = &(ts->hash_next);
    }
    திரும்பு tok_alloc_new(pts, str, len);
}

ST_FUNC முழு tok_alloc_const(மாறிலி எழுத்து *str)
{
    திரும்பு tok_alloc(str, strlen(str))->tok;
}


/* XXX: buffer overflow */
/* XXX: float tokens */
ST_FUNC மாறிலி எழுத்து *get_tok_str(முழு v, CValue *cv)
{
    எழுத்து *p;
    முழு i, len;

    cstr_reset(&cstr_buf);
    p = cstr_buf.data;

    தேர்வு(v) {
    நிலை TOK_CINT:
    நிலை TOK_CUINT:
    நிலை TOK_CLONG:
    நிலை TOK_CULONG:
    நிலை TOK_CLLONG:
    நிலை TOK_CULLONG:
        /* XXX: not quite exact, but only useful for testing  */
        sprintf(p, "%llu", (unsigned long long)cv->i);
        நிறுத்து;
    நிலை TOK_LCHAR:
        cstr_ccat(&cstr_buf, 'L');
    நிலை TOK_CCHAR:
        cstr_ccat(&cstr_buf, '\'');
        add_char(&cstr_buf, cv->i);
        cstr_ccat(&cstr_buf, '\'');
        cstr_ccat(&cstr_buf, '\0');
        நிறுத்து;
    நிலை TOK_PPNUM:
    நிலை TOK_PPSTR:
        திரும்பு (எழுத்து*)cv->str.data;
    நிலை TOK_LSTR:
        cstr_ccat(&cstr_buf, 'L');
    நிலை TOK_STR:
        cstr_ccat(&cstr_buf, '\"');
        எனில் (v == TOK_STR) {
            len = cv->str.size - 1;
            க்கு(i=0;i<len;i++)
                add_char(&cstr_buf, ((unsigned எழுத்து *)cv->str.data)[i]);
        } இல்லையெனில் {
            len = (cv->str.size / அளவு(nwchar_t)) - 1;
            க்கு(i=0;i<len;i++)
                add_char(&cstr_buf, ((nwchar_t *)cv->str.data)[i]);
        }
        cstr_ccat(&cstr_buf, '\"');
        cstr_ccat(&cstr_buf, '\0');
        நிறுத்து;

    நிலை TOK_CFLOAT:
        திரும்பு strcpy(p, "<float>");
    நிலை TOK_CDOUBLE:
        திரும்பு strcpy(p, "<double>");
    நிலை TOK_CLDOUBLE:
        திரும்பு strcpy(p, "<long double>");
    நிலை TOK_LINENUM:
        திரும்பு strcpy(p, "<linenumber>");

    /* above tokens have value, the ones below don't */
    நிலை TOK_LT:
        v = '<';
        செல் addv;
    நிலை TOK_GT:
        v = '>';
        செல் addv;
    நிலை TOK_DOTS:
        திரும்பு strcpy(p, "...");
    நிலை TOK_A_SHL:
        திரும்பு strcpy(p, "<<=");
    நிலை TOK_A_SAR:
        திரும்பு strcpy(p, ">>=");
    நிலை TOK_EOF:
        திரும்பு strcpy(p, "<eof>");
    நிலை 0: /* anonymous nameless symbols */
        திரும்பு strcpy(p, "<no name>");
    இயல்பு:
        v &= ~(SYM_FIELD | SYM_STRUCT);
        எனில் (v < TOK_IDENT) {
            /* search in two bytes table */
            மாறிலி unsigned எழுத்து *q = tok_two_chars;
            போது (*q) {
                எனில் (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
                    திரும்பு cstr_buf.data;
                }
                q += 3;
            }
            எனில் (v >= 127 || (v < 32 && !is_space(v) && v != '\n')) {
                sprintf(p, "<\\x%02x>", v);
                நிறுத்து;
            }
    addv:
            *p++ = v;
            *p = '\0';
        } இல்லையெனில் எனில் (v < tok_ident) {
            திரும்பு table_ident[v - TOK_IDENT]->str;
        } இல்லையெனில் எனில் (v >= SYM_FIRST_ANOM) {
            /* special name for anonymous symbol */
            sprintf(p, "L.%u", v - SYM_FIRST_ANOM);
        } இல்லையெனில் {
            /* should never happen */
            திரும்பு வெற்று;
        }
        நிறுத்து;
    }
    திரும்பு cstr_buf.data;
}

/* return the current character, handling end of block if necessary
   (but not stray) */
நிலையான முழு handle_eob(வெறுமை)
{
    BufferedFile *bf = file;
    முழு len;

    /* only tries to read if really end of buffer */
    எனில் (bf->buf_ptr >= bf->buf_end) {
        எனில் (bf->fd >= 0) {
#எனில் defined(PARSE_DEBUG)
            len = 1;
#இல்லையெனில்
            len = IO_BUF_SIZE;
#endif
            len = பட(bf->fd, bf->buffer, len);
            எனில் (len < 0)
                len = 0;
        } இல்லையெனில் {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = CH_EOB;
    }
    எனில் (bf->buf_ptr < bf->buf_end) {
        திரும்பு bf->buf_ptr[0];
    } இல்லையெனில் {
        bf->buf_ptr = bf->buf_end;
        திரும்பு CH_EOF;
    }
}

/* read next char from current input file and handle end of input buffer */
நிலையான முழு next_c(வெறுமை)
{
    முழு ch = *++file->buf_ptr;
    /* end of buffer/file handling */
    எனில் (ch == CH_EOB && file->buf_ptr >= file->buf_end)
        ch = handle_eob();
    திரும்பு ch;
}

/* input with '\[\r]\n' handling. */
நிலையான முழு handle_stray_noerror(முழு err)
{
    முழு ch;
    போது ((ch = next_c()) == '\\') {
        ch = next_c();
        எனில் (ch == '\n') {
    newl:
            file->வரி_இலக்கம்++;
        } இல்லையெனில் {
            எனில் (ch == '\r') {
                ch = next_c();
                எனில் (ch == '\n')
                    செல் newl;
                *--file->buf_ptr = '\r';
            }
            எனில் (err)
                tcc_error("stray '\\' in program");
            /* may take advantage of 'BufferedFile.unget[4}' */
            திரும்பு *--file->buf_ptr = '\\';
        }
    }
    திரும்பு ch;
}

#define ninp() handle_stray_noerror(0)

/* handle '\\' in strings, comments and skipped regions */
நிலையான முழு handle_bs(uint8_t **p)
{
    முழு c;
    file->buf_ptr = *p - 1;
    c = ninp();
    *p = file->buf_ptr;
    திரும்பு c;
}

/* skip the stray and handle the \\n case. Output an error if
   incorrect char after the stray */
நிலையான முழு handle_stray(uint8_t **p)
{
    முழு c;
    file->buf_ptr = *p - 1;
    c = handle_stray_noerror(!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS));
    *p = file->buf_ptr;
    திரும்பு c;
}

/* handle the complicated stray case */
#define PEEKC(c, p)\
{\
    c = *++p;\
    எனில் (c == '\\')\
        c = handle_stray(&p); \
}

நிலையான முழு skip_spaces(வெறுமை)
{
    முழு ch;
    --file->buf_ptr;
    செய் {
        ch = ninp();
    } போது (isidnum_table[ch - CH_EOF] & IS_SPC);
    திரும்பு ch;
}

/* single line C++ comments */
நிலையான uint8_t *parse_வரி_comment(uint8_t *p)
{
    முழு c;
    க்கு(;;) {
        க்கு (;;) {
            c = *++p;
    redo:
            எனில் (c == '\n' || c == '\\')
                நிறுத்து;
            c = *++p;
            எனில் (c == '\n' || c == '\\')
                நிறுத்து;
        }
        எனில் (c == '\n')
            நிறுத்து;
        c = handle_bs(&p);
        எனில் (c == CH_EOF)
            நிறுத்து;
        எனில் (c != '\\')
            செல் redo;
    }
    திரும்பு p;
}

/* C comments */
நிலையான uint8_t *parse_comment(uint8_t *p)
{
    முழு c;
    க்கு(;;) {
        /* fast skip loop */
        க்கு(;;) {
            c = *++p;
        redo:
            எனில் (c == '\n' || c == '*' || c == '\\')
                நிறுத்து;
            c = *++p;
            எனில் (c == '\n' || c == '*' || c == '\\')
                நிறுத்து;
        }
        /* now we can handle all the cases */
        எனில் (c == '\n') {
            file->வரி_இலக்கம்++;
        } இல்லையெனில் எனில் (c == '*') {
            செய் {
                c = *++p;
            } போது (c == '*');
            எனில் (c == '\\')
                c = handle_bs(&p);
            எனில் (c == '/')
                நிறுத்து;
            செல் check_eof;
        } இல்லையெனில் {
            c = handle_bs(&p);
        check_eof:
            எனில் (c == CH_EOF)
                tcc_error("unexpected end of file in comment");
            எனில் (c != '\\')
                செல் redo;
        }
    }
    திரும்பு p + 1;
}

/* parse a string without interpreting escapes */
நிலையான uint8_t *parse_pp_string(uint8_t *p, முழு sep, CString *str)
{
    முழு c;
    க்கு(;;) {
        c = *++p;
    redo:
        எனில் (c == sep) {
            நிறுத்து;
        } இல்லையெனில் எனில் (c == '\\') {
            c = handle_bs(&p);
            எனில் (c == CH_EOF) {
        unterminated_string:
                /* XXX: indicate line number of start of string */
                tok_flags &= ~TOK_FLAG_BOL;
                tcc_error("missing terminating %c character", sep);
            } இல்லையெனில் எனில் (c == '\\') {
                எனில் (str)
                    cstr_ccat(str, c);
                c = *++p;
                /* add char after '\\' unconditionally */
                எனில் (c == '\\') {
                    c = handle_bs(&p);
                    எனில் (c == CH_EOF)
                        செல் unterminated_string;
                }
                செல் add_char;
            } இல்லையெனில் {
                செல் redo;
            }
        } இல்லையெனில் எனில் (c == '\n') {
        add_lf:
            எனில் (ACCEPT_LF_IN_STRINGS) {
                file->வரி_இலக்கம்++;
                செல் add_char;
            } இல்லையெனில் எனில் (str) { /* not skipping */
                செல் unterminated_string;
            } இல்லையெனில் {
                //tcc_warning("missing terminating %c character", sep);
                திரும்பு p;
            }
        } இல்லையெனில் எனில் (c == '\r') {
            c = *++p;
            எனில் (c == '\\')
                c = handle_bs(&p);
            எனில் (c == '\n')
                செல் add_lf;
            எனில் (c == CH_EOF)
                செல் unterminated_string;
            எனில் (str)
                cstr_ccat(str, '\r');
            செல் redo;
        } இல்லையெனில் {
        add_char:
            எனில் (str)
                cstr_ccat(str, c);
        }
    }
    p++;
    திரும்பு p;
}

/* skip block of text until #else, #elif or #endif. skip also pairs of
   #if/#endif */
நிலையான வெறுமை preprocess_skip(வெறுமை)
{
    முழு a, start_of_வரி, c, in_warn_or_error;
    uint8_t *p;

    p = file->buf_ptr;
    a = 0;
redo_start:
    start_of_வரி = 1;
    in_warn_or_error = 0;
    க்கு(;;) {
        c = *p;
        தேர்வு(c) {
        நிலை ' ':
        நிலை '\t':
        நிலை '\f':
        நிலை '\v':
        நிலை '\r':
            p++;
            தொடர்;
        நிலை '\n':
            file->வரி_இலக்கம்++;
            p++;
            செல் redo_start;
        நிலை '\\':
            c = handle_bs(&p);
            எனில் (c == CH_EOF)
                expect("#endif");
            எனில் (c == '\\')
                ++p;
            தொடர்;
        /* skip strings */
        நிலை '\"':
        நிலை '\'':
            எனில் (in_warn_or_error)
                செல் _default;
            tok_flags &= ~TOK_FLAG_BOL;
            p = parse_pp_string(p, c, வெற்று);
            நிறுத்து;
        /* skip comments */
        நிலை '/':
            எனில் (in_warn_or_error)
                செல் _default;
            ++p;
            c = handle_bs(&p);
            எனில் (c == '*') {
                p = parse_comment(p);
            } இல்லையெனில் எனில் (c == '/') {
                p = parse_வரி_comment(p);
            }
            தொடர்;
        நிலை '#':
            p++;
            எனில் (start_of_வரி) {
                file->buf_ptr = p;
                next_nomacro();
                p = file->buf_ptr;
                எனில் (a == 0 && 
                    (tok == TOK_ELSE || tok == TOK_ELIF || tok == TOK_ENDIF))
                    செல் the_end;
                எனில் (tok == TOK_IF || tok == TOK_IFDEF || tok == TOK_IFNDEF)
                    a++;
                இல்லையெனில் எனில் (tok == TOK_ENDIF)
                    a--;
                இல்லையெனில் எனில்( tok == TOK_ERROR || tok == TOK_WARNING)
                    in_warn_or_error = 1;
                இல்லையெனில் எனில் (tok == TOK_LINEFEED)
                    செல் redo_start;
                இல்லையெனில் எனில் (parse_flags & PARSE_FLAG_ASM_FILE)
                    p = parse_வரி_comment(p - 1);
            }
#எனில் !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
            இல்லையெனில் எனில் (parse_flags & PARSE_FLAG_ASM_FILE)
                p = parse_வரி_comment(p - 1);
#இல்லையெனில்
            /* ARM/ARM64 assembly uses '#' for constants */
#endif
            நிறுத்து;
_default:
        இயல்பு:
            p++;
            நிறுத்து;
        }
        start_of_வரி = 0;
    }
 the_end: ;
    file->buf_ptr = p;
}

#எனில் 0
/* return the number of additional 'ints' necessary to store the
   token */
நிலையான உள்வரி முழு tok_size(மாறிலி முழு *p)
{
    தேர்வு(*p) {
        /* 4 bytes */
    நிலை TOK_CINT:
    நிலை TOK_CUINT:
    நிலை TOK_CCHAR:
    நிலை TOK_LCHAR:
    நிலை TOK_CFLOAT:
    நிலை TOK_LINENUM:
        திரும்பு 1 + 1;
    நிலை TOK_STR:
    நிலை TOK_LSTR:
    நிலை TOK_PPNUM:
    நிலை TOK_PPSTR:
        திரும்பு 1 + 1 + (p[1] + 3) / 4;
    நிலை TOK_CLONG:
    நிலை TOK_CULONG:
	திரும்பு 1 + LONG_SIZE / 4;
    நிலை TOK_CDOUBLE:
    நிலை TOK_CLLONG:
    நிலை TOK_CULLONG:
        திரும்பு 1 + 2;
    நிலை TOK_CLDOUBLE:
        திரும்பு 1 + LDOUBLE_சொற்கள்;
    இயல்பு:
        திரும்பு 1 + 0;
    }
}
#endif

/* token string handling */
ST_INLN வெறுமை tok_str_new(TokenString *s)
{
    s->str = வெற்று;
    s->len = s->need_spc = 0;
    s->allocated_len = 0;
    s->last_வரி_இலக்கம் = -1;
}

ST_FUNC TokenString *tok_str_alloc(வெறுமை)
{
    TokenString *str = tal_realloc(&tokstr_alloc, 0, அளவு *str);
    tok_str_new(str);
    திரும்பு str;
}

ST_FUNC வெறுமை tok_str_free_str(முழு *str)
{
    tal_free(&tokstr_alloc, str);
}

ST_FUNC வெறுமை tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free(&tokstr_alloc, str);
}

ST_FUNC முழு *tok_str_realloc(TokenString *s, முழு new_size)
{
    முழு *str, size;

    size = s->allocated_len;
    எனில் (size < 16)
        size = 16;
    போது (size < new_size)
        size = size * 2;
    எனில் (size > s->allocated_len) {
        str = tal_realloc(&tokstr_alloc, s->str, size * அளவு(முழு));
        s->allocated_len = size;
        s->str = str;
    }
    திரும்பு s->str;
}

ST_FUNC வெறுமை tok_str_add(TokenString *s, முழு t)
{
    முழு len, *str;

    len = s->len;
    str = s->str;
    எனில் (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}

ST_FUNC வெறுமை begin_macro(TokenString *str, முழு alloc)
{
    str->alloc = alloc;
    str->prev = macro_அடுக்கு;
    str->prev_ptr = macro_ptr;
    str->save_வரி_இலக்கம் = file->வரி_இலக்கம்;
    macro_ptr = str->str;
    macro_அடுக்கு = str;
}

ST_FUNC வெறுமை end_macro(வெறுமை)
{
    TokenString *str = macro_அடுக்கு;
    macro_அடுக்கு = str->prev;
    macro_ptr = str->prev_ptr;
    file->வரி_இலக்கம் = str->save_வரி_இலக்கம்;
    எனில் (str->alloc == 0) {
        /* matters if str not alloced, may be tokstr_buf */
        str->len = str->need_spc = 0;
    } இல்லையெனில் {
        எனில் (str->alloc == 2)
            str->str = வெற்று; /* don't free */
        tok_str_free(str);
    }
}

நிலையான வெறுமை tok_str_add2(TokenString *s, முழு t, CValue *cv)
{
    முழு len, *str;

    len = s->len;
    str = s->str;

    /* allocate space for worst case */
    எனில் (len + TOK_MAX_SIZE >= s->allocated_len)
        str = tok_str_realloc(s, len + TOK_MAX_SIZE + 1);
    str[len++] = t;
    தேர்வு(t) {
    நிலை TOK_CINT:
    நிலை TOK_CUINT:
    நிலை TOK_CCHAR:
    நிலை TOK_LCHAR:
    நிலை TOK_CFLOAT:
    நிலை TOK_LINENUM:
#எனில் LONG_SIZE == 4
    நிலை TOK_CLONG:
    நிலை TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        நிறுத்து;
    நிலை TOK_PPNUM:
    நிலை TOK_PPSTR:
    நிலை TOK_STR:
    நிலை TOK_LSTR:
        {
            /* Insert the string into the int array. */
            size_t nb_சொற்கள் =
                1 + (cv->str.size + அளவு(முழு) - 1) / அளவு(முழு);
            எனில் (len + nb_சொற்கள் >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_சொற்கள் + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_சொற்கள்;
        }
        நிறுத்து;
    நிலை TOK_CDOUBLE:
    நிலை TOK_CLLONG:
    நிலை TOK_CULLONG:
#எனில் LONG_SIZE == 8
    நிலை TOK_CLONG:
    நிலை TOK_CULONG:
#endif
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        நிறுத்து;
    நிலை TOK_CLDOUBLE:
        str[len++] = cv->tab[0];
        str[len++] = cv->tab[1];
        எனில் (LDOUBLE_சொற்கள் >= 3)
        str[len++] = cv->tab[2];
        எனில் (LDOUBLE_சொற்கள் >= 4)
        str[len++] = cv->tab[3];
    இயல்பு:
        நிறுத்து;
    }
    s->len = len;
}

/* add the current parse token in token string 's' */
ST_FUNC வெறுமை tok_str_add_tok(TokenString *s)
{
    CValue cval;

    /* save line number info */
    எனில் (file->வரி_இலக்கம் != s->last_வரி_இலக்கம்) {
        s->last_வரி_இலக்கம் = file->வரி_இலக்கம்;
        cval.i = s->last_வரி_இலக்கம்;
        tok_str_add2(s, TOK_LINENUM, &cval);
    }
    tok_str_add2(s, tok, &tokc);
}

/* like tok_str_add2(), add a space if needed */
நிலையான வெறுமை tok_str_add2_spc(TokenString *s, முழு t, CValue *cv)
{
    எனில் (s->need_spc == 3)
        tok_str_add(s, ' ');
    s->need_spc = 2;
    tok_str_add2(s, t, cv);
}

/* get a token from an integer array and increment pointer. */
நிலையான உள்வரி வெறுமை tok_get(முழு *t, மாறிலி முழு **pp, CValue *cv)
{
    மாறிலி முழு *p = *pp;
    முழு n, *tab;

    tab = cv->tab;
    தேர்வு(*t = *p++) {
#எனில் LONG_SIZE == 4
    நிலை TOK_CLONG:
#endif
    நிலை TOK_CINT:
    நிலை TOK_CCHAR:
    நிலை TOK_LCHAR:
    நிலை TOK_LINENUM:
        cv->i = *p++;
        நிறுத்து;
#எனில் LONG_SIZE == 4
    நிலை TOK_CULONG:
#endif
    நிலை TOK_CUINT:
        cv->i = (unsigned)*p++;
        நிறுத்து;
    நிலை TOK_CFLOAT:
	tab[0] = *p++;
	நிறுத்து;
    நிலை TOK_STR:
    நிலை TOK_LSTR:
    நிலை TOK_PPNUM:
    நிலை TOK_PPSTR:
        cv->str.size = *p++;
        cv->str.data = (எழுத்து*)p;
        p += (cv->str.size + அளவு(முழு) - 1) / அளவு(முழு);
        நிறுத்து;
    நிலை TOK_CDOUBLE:
    நிலை TOK_CLLONG:
    நிலை TOK_CULLONG:
#எனில் LONG_SIZE == 8
    நிலை TOK_CLONG:
    நிலை TOK_CULONG:
#endif
        n = 2;
        செல் copy;
    நிலை TOK_CLDOUBLE:
        n = LDOUBLE_சொற்கள்;
    copy:
        செய்
            *tab++ = *p++;
        போது (--n);
        நிறுத்து;
    இயல்பு:
        நிறுத்து;
    }
    *pp = p;
}

#எனில் 0
# define TOK_GET(t,p,c) tok_get(t,p,c)
#இல்லையெனில்
# define TOK_GET(t,p,c) செய் { \
    முழு _t = **(p); \
    எனில் (TOK_HAS_மதிப்பு(_t)) \
        tok_get(t, p, c); \
    இல்லையெனில் \
        *(t) = _t, ++*(p); \
    } போது (0)
#endif

நிலையான முழு macro_is_equal(மாறிலி முழு *a, மாறிலி முழு *b)
{
    CValue cv;
    முழு t;

    எனில் (!a || !b)
        திரும்பு 1;

    போது (*a && *b) {
        cstr_reset(&tokcstr);
        TOK_GET(&t, &a, &cv);
        cstr_cat(&tokcstr, get_tok_str(t, &cv), 0);
        TOK_GET(&t, &b, &cv);
        எனில் (strcmp(tokcstr.data, get_tok_str(t, &cv)))
            திரும்பு 0;
    }
    திரும்பு !(*a || *b);
}

/* defines handling */
ST_INLN வெறுமை define_தள்ளு(முழு v, முழு macro_type, முழு *str, Sym *first_arg)
{
    Sym *s, *o;

    o = define_find(v);
    s = sym_push2(&define_அடுக்கு, v, macro_type, 0);
    s->d = str;
    s->next = first_arg;
    table_ident[v - TOK_IDENT]->sym_define = s;

    எனில் (o && !macro_is_equal(o->d, s->d))
	tcc_warning("%s redefined", get_tok_str(v, வெற்று));
}

/* undefined a define symbol. Its name is just set to zero */
ST_FUNC வெறுமை define_undef(Sym *s)
{
    முழு v = s->v;
    எனில் (v >= TOK_IDENT && v < tok_ident)
        table_ident[v - TOK_IDENT]->sym_define = வெற்று;
}

ST_INLN Sym *define_find(முழு v)
{
    v -= TOK_IDENT;
    எனில் ((unsigned)v >= (unsigned)(tok_ident - TOK_IDENT))
        திரும்பு வெற்று;
    திரும்பு table_ident[v]->sym_define;
}

/* free define stack until top reaches 'b' */
ST_FUNC வெறுமை free_defines(Sym *b)
{
    போது (define_அடுக்கு != b) {
        Sym *உச்சி = define_அடுக்கு;
        define_அடுக்கு = உச்சி->prev;
        tok_str_free_str(உச்சி->d);
        define_undef(உச்சி);
        sym_free(உச்சி);
    }
}

/* fake the nth "#if defined test_..." for tcc -dt -run */
நிலையான வெறுமை maybe_run_test(TCCState *s)
{
    மாறிலி எழுத்து *p;
    எனில் (s->include_அடுக்கு_ptr != s->include_அடுக்கு)
        திரும்பு;
    p = get_tok_str(tok, வெற்று);
    எனில் (0 != memcmp(p, "test_", 5))
        திரும்பு;
    எனில் (0 != --s->run_test)
        திரும்பு;
    fprintf(s->ppfp, &"\n[%s]\n"[!(s->dflag & 32)], p), fflush(s->ppfp);
    define_தள்ளு(tok, MACRO_OBJ, வெற்று, வெற்று);
}

ST_FUNC வெறுமை skip_to_eol(முழு warn)
{
    எனில் (tok == TOK_LINEFEED)
        திரும்பு;
    எனில் (warn)
        tcc_warning("extra tokens after directive");
    போது (macro_அடுக்கு)
        end_macro();
    file->buf_ptr = parse_வரி_comment(file->buf_ptr - 1);
    next_nomacro();
}

நிலையான CachedInclude *
தேடல்_cached_include(TCCState *s1, மாறிலி எழுத்து *filename, முழு add);

நிலையான முழு parse_include(TCCState *s1, முழு do_next, முழு test)
{
    முழு c, i;
    எழுத்து name[1024], buf[1024], *p;
    CachedInclude *e;

    c = skip_spaces();
    எனில் (c == '<' || c == '\"') {
        cstr_reset(&tokcstr);
        file->buf_ptr = parse_pp_string(file->buf_ptr, c == '<' ? '>' : c, &tokcstr);
        i = tokcstr.size;
        pstrncpy(name, அளவு name, tokcstr.data, i);
        next_nomacro();
    } இல்லையெனில் {
        /* computed #include : concatenate tokens until result is one of
           the two accepted forms.  Don't convert pp-tokens to tokens here. */
	parse_flags = PARSE_FLAG_PREPROCESS
                    | PARSE_FLAG_LINEFEED
                    | (parse_flags & PARSE_FLAG_ASM_FILE);
        name[0] = 0;
        க்கு (;;) {
            next();
            p = name, i = strlen(p) - 1;
            எனில் (i > 0
                && ((p[0] == '"' && p[i] == '"')
                 || (p[0] == '<' && p[i] == '>')))
                நிறுத்து;
            எனில் (tok == TOK_LINEFEED)
                tcc_error("'#include' expects \"FILENAME\" or <FILENAME>");
            pstrcat(name, அளவு name, get_tok_str(tok, &tokc));
	}
        c = p[0];
        /* remove '<>|""' */
        memmove(p, p + 1, i - 1), p[i - 1] = 0;
    }

    எனில் (!test)
        skip_to_eol(1);

    i = do_next ? file->include_next_index : -1;
    க்கு (;;) {
        ++i;
        எனில் (i == 0) {
            /* check absolute include path */
            எனில் (!IS_ABSPATH(name))
                தொடர்;
            buf[0] = '\0';
        } இல்லையெனில் எனில் (i == 1) {
            /* search in file's dir if "header.h" */
            எனில் (c != '\"')
                தொடர்;
            p = file->true_filename;
            pstrncpy(buf, அளவு buf, p, tcc_basename(p) - p);
        } இல்லையெனில் {
            முழு j = i - 2, k = j - s1->nb_include_paths;
            எனில் (k < 0)
                p = s1->include_paths[j];
            இல்லையெனில் எனில் (k < s1->nb_sysinclude_paths)
                p = s1->sysinclude_paths[k];
            இல்லையெனில் எனில் (test)
                திரும்பு 0;
            இல்லையெனில்
                tcc_error("include file '%s' not found", name);
            pstrcpy(buf, அளவு buf, p);
            pstrcat(buf, அளவு buf, "/");
        }
        pstrcat(buf, அளவு buf, name);
        e = தேடல்_cached_include(s1, buf, 0);
        எனில் (e && (define_find(e->ifndef_macro) || e->once)) {
            /* no need to parse the include because the 'ifndef macro'
               is defined (or had #pragma once) */
#ifdef INC_DEBUG
            printf("%s: skipping cached %s\n", file->filename, buf);
#endif
            எனில் ((s1->verbose | 1) == 3) /* -vv[v] */
                printf("=> %*s%s\n",
                   (முழு)(s1->include_அடுக்கு_ptr - s1->include_அடுக்கு), "", buf);
            திரும்பு 1;
        }
        எனில் (tcc_open(s1, buf) >= 0)
            நிறுத்து;
    }

    எனில் (test) {
        tcc_close();
    } இல்லையெனில் {
        எனில் (s1->include_அடுக்கு_ptr >= s1->include_அடுக்கு + INCLUDE_அடுக்கு_SIZE)
            tcc_error("#include recursion too deep");
        /* push previous file on stack */
        *s1->include_அடுக்கு_ptr++ = file->prev;
        file->include_next_index = i;
#ifdef INC_DEBUG
        printf("%s: including %s\n", file->prev->filename, file->filename);
#endif
        /* update target deps */
        எனில் (s1->gen_deps) {
            BufferedFile *bf = file;
            போது (i == 1 && (bf = bf->prev))
                i = bf->include_next_index;
            /* skip system include files */
            எனில் (s1->include_sys_deps || i - 2 < s1->nb_include_paths)
                dynarray_add(&s1->target_deps, &s1->nb_target_deps,
                    tcc_strdup(buf));
        }
        /* add include file debug info */
        tcc_debug_bincl(s1);
    }
    திரும்பு 1;
}

/* eval an expression for #if/#elif */
நிலையான முழு கோவை_preprocess(TCCState *s1)
{
    முழு c, t;
    முழு t0 = tok;
    TokenString *str;
    
    str = tok_str_alloc();
    pp_கோவை = 1;
    போது (1) {
        next(); /* do macro subst */
        t = tok;
        எனில் (tok < TOK_IDENT) {
            எனில் (tok == TOK_LINEFEED || tok == TOK_EOF)
                நிறுத்து;
            எனில் (tok >= TOK_STR && tok <= TOK_CLDOUBLE)
                tcc_error("invalid constant in preprocessor expression");

        } இல்லையெனில் எனில் (tok == TOK_DEFINED) {
            parse_flags &= ~PARSE_FLAG_PREPROCESS; /* no macro subst */
            next();
            t = tok;
            எனில் (t == '(') 
                next();
            parse_flags |= PARSE_FLAG_PREPROCESS;
            எனில் (tok < TOK_IDENT)
                expect("identifier after 'defined'");
            எனில் (s1->run_test)
                maybe_run_test(s1);
            c = 0;
            எனில் (define_find(tok)
                || tok == TOK___HAS_INCLUDE
                || tok == TOK___HAS_INCLUDE_NEXT)
                c = 1;
            எனில் (t == '(') {
                next();
                எனில் (tok != ')')
                    expect("')'");
            }
            செல் c_எண்;
        } இல்லையெனில் எனில் (tok == TOK___HAS_INCLUDE ||
                   tok == TOK___HAS_INCLUDE_NEXT) {
            t = tok;
            next();
	    எனில் (tok != '(')
		expect("'('");
            c = parse_include(s1, t - TOK___HAS_INCLUDE, 1);
            எனில் (tok != ')')
                expect("')'");
            செல் c_எண்;
        } இல்லையெனில் {
            /* if undefined macro, replace with zero */
            c = 0;
        c_எண்:
            tok = TOK_CLLONG; /* type intmax_t */
            tokc.i = c;
        }
        tok_str_add_tok(str);
    }
    எனில் (0 == str->len)
        tcc_error("#%s with no expression", get_tok_str(t0, 0));
    tok_str_add(str, TOK_EOF); /* simulate end of file */
    pp_கோவை = t0; /* redirect pre-processor expression error messages */
    t = tok;
    /* now evaluate C constant expression */
    begin_macro(str, 1);
    next();
    c = கோவை_const();
    எனில் (tok != TOK_EOF)
        tcc_error("...");
    pp_கோவை = 0;
    end_macro();
    tok = t; /* restore LF or EOF */
    திரும்பு c != 0;
}

ST_FUNC வெறுமை pp_error(CString *cs)
{
    cstr_printf(cs, "bad preprocessor expression: #%s", get_tok_str(pp_கோவை, 0));
    macro_ptr = macro_அடுக்கு->str;
    போது (next(), tok != TOK_EOF)
        cstr_printf(cs, " %s", get_tok_str(tok, &tokc));
}

/* parse after #define */
ST_FUNC வெறுமை parse_define(வெறுமை)
{
    Sym *s, *first, **ps;
    முழு v, t, varg, is_vaargs, t0;
    முழு saved_parse_flags = parse_flags;
    TokenString str;

    v = tok;
    எனில் (v < TOK_IDENT || v == TOK_DEFINED)
        tcc_error("invalid macro name '%s'", get_tok_str(tok, &tokc));
    first = வெற்று;
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
    எனில் (tok == '(') {
        முழு dotid = set_idnum('.', 0);
        next_nomacro();
        ps = &first;
        எனில் (tok != ')') க்கு (;;) {
            varg = tok;
            next_nomacro();
            is_vaargs = 0;
            எனில் (varg == TOK_DOTS) {
                varg = TOK___VA_ARGS__;
                is_vaargs = 1;
            } இல்லையெனில் எனில் (tok == TOK_DOTS && gnu_ext) {
                is_vaargs = 1;
                next_nomacro();
            }
            எனில் (varg < TOK_IDENT)
        bad_list:
                tcc_error("bad macro parameter list");
            s = sym_push2(&define_அடுக்கு, varg | SYM_FIELD, is_vaargs, 0);
            *ps = s;
            ps = &s->next;
            எனில் (tok == ')')
                நிறுத்து;
            எனில் (tok != ',' || is_vaargs)
                செல் bad_list;
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
    போது (tok != TOK_LINEFEED && tok != TOK_EOF) {
        எனில் (is_space(tok)) {
            str.need_spc |= 1;
        } இல்லையெனில் {
            எனில் (TOK_TWOSHARPS == tok) {
                எனில் (0 == t0)
                    செல் bad_twosharp;
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
    எனில் (t0 == TOK_PPJOIN)
bad_twosharp:
        tcc_error("'##' cannot appear at either end of macro");
    define_தள்ளு(v, t, str.str, first);
    //tok_print(str.str, "#define (%d) %s %d:", t | is_vaargs * 4, get_tok_str(v, 0));
}

நிலையான CachedInclude *தேடல்_cached_include(TCCState *s1, மாறிலி எழுத்து *filename, முழு add)
{
    மாறிலி எழுத்து *s, *basename;
    unsigned முழு h;
    CachedInclude *e;
    முழு c, i, len;

    s = basename = tcc_basename(filename);
    h = TOK_HASH_INIT;
    போது ((c = (unsigned எழுத்து)*s) != 0) {
#ifdef _WIN32
        h = TOK_HASH_FUNC(h, toup(c));
#இல்லையெனில்
        h = TOK_HASH_FUNC(h, c);
#endif
        s++;
    }
    h &= (CACHED_INCLUDES_HASH_SIZE - 1);

    i = s1->cached_includes_hash[h];
    க்கு(;;) {
        எனில் (i == 0)
            நிறுத்து;
        e = s1->cached_includes[i - 1];
        எனில் (0 == PATHCMP(filename, e->filename))
            திரும்பு e;
        எனில் (e->once
            && 0 == PATHCMP(basename, tcc_basename(e->filename))
            && 0 == normalized_PATHCMP(filename, e->filename)
            )
            திரும்பு e;
        i = e->hash_next;
    }
    எனில் (!add)
        திரும்பு வெற்று;

    e = tcc_malloc(அளவு(CachedInclude) + (len = strlen(filename)));
    memcpy(e->filename, filename, len + 1);
    e->ifndef_macro = e->once = 0;
    dynarray_add(&s1->cached_includes, &s1->nb_cached_includes, e);
    /* add in hash table */
    e->hash_next = s1->cached_includes_hash[h];
    s1->cached_includes_hash[h] = s1->nb_cached_includes;
#ifdef INC_DEBUG
    printf("adding cached '%s'\n", filename);
#endif
    திரும்பு e;
}

நிலையான முழு pragma_parse(TCCState *s1)
{
    next_nomacro();
    எனில் (tok == TOK_தள்ளு_macro || tok == TOK_எடு_macro) {
        முழு t = tok, v;
        Sym *s;

        எனில் (next(), tok != '(')
            செல் pragma_err;
        எனில் (next(), tok != TOK_STR)
            செல் pragma_err;
        v = tok_alloc(tokc.str.data, tokc.str.size - 1)->tok;
        எனில் (next(), tok != ')')
            செல் pragma_err;
        எனில் (t == TOK_தள்ளு_macro) {
            போது (வெற்று == (s = define_find(v)))
                define_தள்ளு(v, 0, வெற்று, வெற்று);
            s->type.ref = s; /* set push boundary */
        } இல்லையெனில் {
            க்கு (s = define_அடுக்கு; s; s = s->prev)
                எனில் (s->v == v && s->type.ref == s) {
                    s->type.ref = வெற்று;
                    நிறுத்து;
                }
        }
        எனில் (s)
            table_ident[v - TOK_IDENT]->sym_define = s->d ? s : வெற்று;
        இல்லையெனில்
            tcc_warning("unbalanced #pragma pop_macro");
        pp_debug_tok = t, pp_debug_symv = v;

    } இல்லையெனில் எனில் (tok == TOK_once) {
        தேடல்_cached_include(s1, file->true_filename, 1)->once = 1;

    } இல்லையெனில் எனில் (s1->output_type == TCC_OUTPUT_PREPROCESS) {
        /* tcc -E: keep pragmas below unchanged */
        unget_tok(' ');
        unget_tok(TOK_PRAGMA);
        unget_tok('#');
        unget_tok(TOK_LINEFEED);
        திரும்பு 1;

    } இல்லையெனில் எனில் (tok == TOK_pack) {
        /* This may be:
           #pragma pack(1) // set
           #pragma pack() // reset to default
           #pragma pack(push) // push current
           #pragma pack(push,1) // push & set
           #pragma pack(pop) // restore previous */
        next();
        skip('(');
        எனில் (tok == TOK_ASM_எடு) {
            next();
            எனில் (s1->pack_அடுக்கு_ptr <= s1->pack_அடுக்கு) {
            stk_error:
                tcc_error("out of pack stack");
            }
            s1->pack_அடுக்கு_ptr--;
        } இல்லையெனில் {
            முழு val = 0;
            எனில் (tok != ')') {
                எனில் (tok == TOK_ASM_தள்ளு) {
                    next();
                    எனில் (s1->pack_அடுக்கு_ptr >= s1->pack_அடுக்கு + PACK_அடுக்கு_SIZE - 1)
                        செல் stk_error;
                    val = *s1->pack_அடுக்கு_ptr++;
                    எனில் (tok != ',')
                        செல் pack_set;
                    next();
                }
                எனில் (tok != TOK_CINT)
                    செல் pragma_err;
                val = tokc.i;
                எனில் (val < 1 || val > 16 || (val & (val - 1)) != 0)
                    செல் pragma_err;
                next();
            }
        pack_set:
            *s1->pack_அடுக்கு_ptr = val;
        }
        எனில் (tok != ')')
            செல் pragma_err;

    } இல்லையெனில் எனில் (tok == TOK_comment) {
        எழுத்து *p; முழு t;
        next();
        skip('(');
        t = tok;
        next();
        skip(',');
        எனில் (tok != TOK_STR)
            செல் pragma_err;
        p = tcc_strdup(tokc.str.data);
        next();
        எனில் (tok != ')')
            செல் pragma_err;
        எனில் (t == TOK_lib) {
            dynarray_add(&s1->pragma_libs, &s1->nb_pragma_libs, p);
        } இல்லையெனில் {
            எனில் (t == TOK_option)
                tcc_set_options(s1, p);
            tcc_free(p);
        }

    } இல்லையெனில் {
        tcc_warning_c(warn_all)("#pragma %s ignored", get_tok_str(tok, &tokc));
        திரும்பு 0;
    }
    next();
    திரும்பு 1;
pragma_err:
    tcc_error("malformed #pragma directive");
}

/* put alternative filename */
ST_FUNC வெறுமை tccpp_putfile(மாறிலி எழுத்து *filename)
{
    எழுத்து buf[1024];
    buf[0] = 0;
    எனில் (!IS_ABSPATH(filename)) {
        /* prepend directory from real file */
        pstrcpy(buf, அளவு buf, file->true_filename);
        *tcc_basename(buf) = 0;
    }
    pstrcat(buf, அளவு buf, filename);
#ifdef _WIN32
    normalize_slashes(buf);
#endif
    எனில் (0 == strcmp(file->filename, buf))
        திரும்பு;
    //printf("new file '%s'\n", buf);
    எனில் (file->true_filename == file->filename)
        file->true_filename = tcc_strdup(file->filename);
    pstrcpy(file->filename, அளவு file->filename, buf);
    tcc_debug_newfile(tcc_state);
}

/* is_bof is true if first non space token at beginning of file */
ST_FUNC வெறுமை preprocess(முழு is_bof)
{
    TCCState *s1 = tcc_state;
    முழு c, n, saved_parse_flags;
    எழுத்து buf[1024], *q;
    Sym *s;

    saved_parse_flags = parse_flags;
    parse_flags = PARSE_FLAG_PREPROCESS
        | PARSE_FLAG_TOK_இலக்கம்
        | PARSE_FLAG_TOK_STR
        | PARSE_FLAG_LINEFEED
        | (parse_flags & PARSE_FLAG_ASM_FILE)
        ;

    next_nomacro();
 redo:
    தேர்வு(tok) {
    நிலை TOK_DEFINE:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        parse_define();
        நிறுத்து;
    நிலை TOK_UNDEF:
        pp_debug_tok = tok;
        next_nomacro();
        pp_debug_symv = tok;
        s = define_find(tok);
        /* undefine symbol by putting an invalid name */
        எனில் (s)
            define_undef(s);
        next_nomacro();
        நிறுத்து;
    நிலை TOK_INCLUDE:
    நிலை TOK_INCLUDE_NEXT:
        parse_include(s1, tok - TOK_INCLUDE, 0);
        செல் the_end;
    நிலை TOK_IFNDEF:
        c = 1;
        செல் do_ifdef;
    நிலை TOK_IF:
        c = கோவை_preprocess(s1);
        செல் do_if;
    நிலை TOK_IFDEF:
        c = 0;
    do_ifdef:
        next_nomacro();
        எனில் (tok < TOK_IDENT)
            tcc_error("invalid argument for '#if%sdef'", c ? "n" : "");
        எனில் (is_bof) {
            எனில் (c) {
#ifdef INC_DEBUG
                printf("#ifndef %s\n", get_tok_str(tok, வெற்று));
#endif
                file->ifndef_macro = tok;
            }
        }
        எனில் (define_find(tok)
            || tok == TOK___HAS_INCLUDE
            || tok == TOK___HAS_INCLUDE_NEXT)
            c ^= 1;
        next_nomacro();
    do_if:
        எனில் (s1->ifdef_அடுக்கு_ptr >= s1->ifdef_அடுக்கு + IFDEF_அடுக்கு_SIZE)
            tcc_error("memory full (ifdef)");
        *s1->ifdef_அடுக்கு_ptr++ = c;
        செல் test_skip;
    நிலை TOK_ELSE:
        next_nomacro();
        எனில் (s1->ifdef_அடுக்கு_ptr == s1->ifdef_அடுக்கு)
            tcc_error("#else without matching #if");
        எனில் (s1->ifdef_அடுக்கு_ptr[-1] & 2)
            tcc_error("#else after #else");
        c = (s1->ifdef_அடுக்கு_ptr[-1] ^= 3);
        செல் test_else;
    நிலை TOK_ELIF:
        எனில் (s1->ifdef_அடுக்கு_ptr == s1->ifdef_அடுக்கு)
            tcc_error("#elif without matching #if");
        c = s1->ifdef_அடுக்கு_ptr[-1];
        எனில் (c > 1)
            tcc_error("#elif after #else");
        /* last #if/#elif expression was true: we skip */
        எனில் (c == 1) {
            skip_to_eol(0);
            c = 0;
        } இல்லையெனில் {
            c = கோவை_preprocess(s1);
            s1->ifdef_அடுக்கு_ptr[-1] = c;
        }
    test_else:
        எனில் (s1->ifdef_அடுக்கு_ptr == file->ifdef_அடுக்கு_ptr + 1)
            file->ifndef_macro = 0;
    test_skip:
        எனில் (!(c & 1)) {
            skip_to_eol(1);
            preprocess_skip();
            is_bof = 0;
            செல் redo;
        }
        நிறுத்து;
    நிலை TOK_ENDIF:
        next_nomacro();
        எனில் (s1->ifdef_அடுக்கு_ptr <= file->ifdef_அடுக்கு_ptr)
            tcc_error("#endif without matching #if");
        s1->ifdef_அடுக்கு_ptr--;
        /* '#ifndef macro' was at the start of file. Now we check if
           an '#endif' is exactly at the end of file */
        எனில் (file->ifndef_macro &&
            s1->ifdef_அடுக்கு_ptr == file->ifdef_அடுக்கு_ptr) {
            file->ifndef_macro_saved = file->ifndef_macro;
            /* need to set to zero to avoid false matches if another
               #ifndef at middle of file */
            file->ifndef_macro = 0;
            tok_flags |= TOK_FLAG_ENDIF;
        }
        நிறுத்து;

    நிலை TOK_வரி:
        parse_flags &= ~PARSE_FLAG_TOK_இலக்கம்;
        next();
        எனில் (tok != TOK_PPNUM) {
    வரி_err:
            tcc_error("wrong #line format");
        }
        c = 1;
        செல் வரி_இலக்கம்_2;
    நிலை TOK_PPNUM:
        எனில் (parse_flags & PARSE_FLAG_ASM_FILE)
            செல் ignore;
        c = 0; /* no error with extra tokens */
    வரி_இலக்கம்_2:
        க்கு (n = 0, q = tokc.str.data; *q; ++q) {
            எனில் (!isnum(*q))
                செல் வரி_err;
            n = n * 10 + *q - '0';
        }
        parse_flags &= ~PARSE_FLAG_TOK_STR; /* don't parse escape sequences */
        next();
        எனில் (tok != TOK_LINEFEED) {
            எனில் (tok != TOK_PPSTR || tokc.str.data[0] != '"')
                செல் வரி_err;
            tokc.str.data[tokc.str.size - 2] = 0;
            tccpp_putfile(tokc.str.data + 1);
            next();
            /* skip optional level number & advance to next line */
            skip_to_eol(c);
        }
        எனில் (file->fd > 0)
            total_வரிகள் += file->வரி_இலக்கம் - n;
        file->வரி_இலக்கம் = n;
        நிறுத்து;

    நிலை TOK_ERROR:
    நிலை TOK_WARNING:
    {
        q = buf;
        c = skip_spaces();
        போது (c != '\n' && c != CH_EOF) {
            எனில் ((q - buf) < அளவு(buf) - 1)
                *q++ = c;
            c = ninp();
        }
        *q = '\0';
        எனில் (tok == TOK_ERROR)
            tcc_error("#error %s", buf);
        இல்லையெனில்
            tcc_warning("#warning %s", buf);
        next_nomacro();
        நிறுத்து;
    }
    நிலை TOK_PRAGMA:
        எனில் (!pragma_parse(s1))
            செல் ignore;
        நிறுத்து;
    நிலை TOK_LINEFEED:
        செல் the_end;
    இயல்பு:
        /* ignore gas line comment in an 'S' file. */
        எனில் (saved_parse_flags & PARSE_FLAG_ASM_FILE)
            செல் ignore;
        எனில் (tok == '!' && is_bof)
            /* '#!' is ignored at beginning to allow C scripts. */
            செல் ignore;
        tcc_warning("ignoring unknown preprocessing directive #%s", get_tok_str(tok, &tokc));
    ignore:
        skip_to_eol(0);
        செல் the_end;
    }
    skip_to_eol(1);
 the_end:
    parse_flags = saved_parse_flags;
}

/* evaluate escape codes in a string. */
நிலையான வெறுமை parse_escape_string(CString *outstr, மாறிலி uint8_t *buf, முழு is_long)
{
    முழு c, n, i;
    மாறிலி uint8_t *p;

    p = buf;
    க்கு(;;) {
        c = *p;
        எனில் (c == '\0')
            நிறுத்து;
        எனில் (c == '\\') {
            p++;
            /* escape */
            c = *p;
            தேர்வு(c) {
            நிலை '0': நிலை '1': நிலை '2': நிலை '3':
            நிலை '4': நிலை '5': நிலை '6': நிலை '7':
                /* at most three octal digits */
                n = c - '0';
                p++;
                c = *p;
                எனில் (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    எனில் (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                செல் add_char_nonext;
            நிலை 'x': i = 0; செல் parse_hex_or_ucn;
            நிலை 'u': i = 4; செல் parse_hex_or_ucn;
            நிலை 'U': i = 8; செல் parse_hex_or_ucn;
    parse_hex_or_ucn:
                p++;
                n = 0;
                செய் {
                    c = *p;
                    எனில் (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    இல்லையெனில் எனில் (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    இல்லையெனில் எனில் (isnum(c))
                        c = c - '0';
                    இல்லையெனில் எனில் (i >= 0)
                        expect("more hex digits in universal-character-name");
                    இல்லையெனில்
                        செல் add_hex_or_ucn;
                    n = (unsigned) n * 16 + c;
                    p++;
                } போது (--i);
		எனில் (is_long) {
    add_hex_or_ucn:
                    c = n;
		    செல் add_char_nonext;
		}
                cstr_u8cat(outstr, n);
                தொடர்;
            நிலை 'a':
                c = '\a';
                நிறுத்து;
            நிலை 'b':
                c = '\b';
                நிறுத்து;
            நிலை 'f':
                c = '\f';
                நிறுத்து;
            நிலை 'n':
                c = '\n';
                நிறுத்து;
            நிலை 'r':
                c = '\r';
                நிறுத்து;
            நிலை 't':
                c = '\t';
                நிறுத்து;
            நிலை 'v':
                c = '\v';
                நிறுத்து;
            நிலை 'e':
                எனில் (!gnu_ext)
                    செல் invalid_escape;
                c = 27;
                நிறுத்து;
            நிலை '\'':
            நிலை '\"':
            நிலை '\\': 
            நிலை '?':
                நிறுத்து;
            இயல்பு:
            invalid_escape:
                எனில் (c >= '!' && c <= '~')
                    tcc_warning("unknown escape sequence: \'\\%c\'", c);
                இல்லையெனில்
                    tcc_warning("unknown escape sequence: \'\\x%x\'", c);
                நிறுத்து;
            }
        } இல்லையெனில் எனில் (is_long && c >= 0x80) {
            /* assume we are processing UTF-8 sequence */
            /* reference: The Unicode Standard, Version 10.0, ch3.9 */

            முழு cont; /* count of continuation bytes */
            முழு skip; /* how many bytes should skip when error occurred */
            முழு i;

            /* decode leading byte */
            எனில் (c < 0xC2) {
	            skip = 1; செல் invalid_utf8_sequence;
            } இல்லையெனில் எனில் (c <= 0xDF) {
	            cont = 1; n = c & 0x1f;
            } இல்லையெனில் எனில் (c <= 0xEF) {
	            cont = 2; n = c & 0xf;
            } இல்லையெனில் எனில் (c <= 0xF4) {
	            cont = 3; n = c & 0x7;
            } இல்லையெனில் {
	            skip = 1; செல் invalid_utf8_sequence;
            }

            /* decode continuation bytes */
            க்கு (i = 1; i <= cont; i++) {
                முழு l = 0x80, h = 0xBF;

                /* adjust limit for second byte */
                எனில் (i == 1) {
                    தேர்வு (c) {
                    நிலை 0xE0: l = 0xA0; நிறுத்து;
                    நிலை 0xED: h = 0x9F; நிறுத்து;
                    நிலை 0xF0: l = 0x90; நிறுத்து;
                    நிலை 0xF4: h = 0x8F; நிறுத்து;
                    }
                }

                எனில் (p[i] < l || p[i] > h) {
                    skip = i; செல் invalid_utf8_sequence;
                }

                n = (n << 6) | (p[i] & 0x3f);
            }

            /* advance pointer */
            p += 1 + cont;
            c = n;
            செல் add_char_nonext;

            /* error handling */
        invalid_utf8_sequence:
            tcc_warning("ill-formed UTF-8 subsequence starting with: \'\\x%x\'", c);
            c = 0xFFFD;
            p += skip;
            செல் add_char_nonext;

        }
        p++;
    add_char_nonext:
        எனில் (!is_long)
            cstr_ccat(outstr, c);
        இல்லையெனில் {
#ifdef TCC_TARGET_PE
            /* store as UTF-16 */
            எனில் (c < 0x10000) {
                cstr_wccat(outstr, c);
            } இல்லையெனில் {
                c -= 0x10000;
                cstr_wccat(outstr, (c >> 10) + 0xD800);
                cstr_wccat(outstr, (c & 0x3FF) + 0xDC00);
            }
#இல்லையெனில்
            cstr_wccat(outstr, c);
#endif
        }
    }
    /* add a trailing '\0' */
    எனில் (!is_long)
        cstr_ccat(outstr, '\0');
    இல்லையெனில்
        cstr_wccat(outstr, '\0');
}

நிலையான வெறுமை parse_string(மாறிலி எழுத்து *s, முழு len)
{
    uint8_t buf[1000], *p = buf;
    முழு is_long, sep;

    எனில் ((is_long = *s == 'L'))
        ++s, --len;
    sep = *s++;
    len -= 2;
    எனில் (len >= அளவு buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;

    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p, is_long);
    எனில் (p != buf)
        tcc_free(p);

    எனில் (sep == '\'') {
        முழு char_size, i, n, c;
        /* XXX: make it portable */
        எனில் (!is_long)
            tok = TOK_CCHAR, char_size = 1;
        இல்லையெனில்
            tok = TOK_LCHAR, char_size = அளவு(nwchar_t);
        n = tokcstr.size / char_size - 1;
        எனில் (n < 1)
            tcc_error("empty character constant");
        எனில் (n > 1)
            tcc_warning_c(warn_all)("multi-character character constant");
        க்கு (c = i = 0; i < n; ++i) {
            எனில் (is_long)
                c = ((nwchar_t *)tokcstr.data)[i];
            இல்லையெனில்
                c = (c << 8) | ((எழுத்து *)tokcstr.data)[i];
        }
        tokc.i = c;
    } இல்லையெனில் {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        எனில் (!is_long)
            tok = TOK_STR;
        இல்லையெனில்
            tok = TOK_LSTR;
    }
}

/* we use 128 bit (64/112 needed) numbers */
#define BN_SIZE 4

/* bn = (bn << shift) | or_val */
நிலையான முழு bn_lshift(unsigned முழு *bn, முழு shift, முழு or_val)
{
    முழு i;
    unsigned முழு v;
    எனில் (bn[BN_SIZE - 1] >> (32 - shift))
	திரும்பு shift;
    க்கு(i=0;i<BN_SIZE;i++) {
        v = bn[i];
        bn[i] = (v << shift) | or_val;
        or_val = v >> (32 - shift);
    }
    திரும்பு 0;
}

நிலையான வெறுமை bn_zero(unsigned முழு *bn)
{
    முழு i;
    க்கு(i=0;i<BN_SIZE;i++) {
        bn[i] = 0;
    }
}

/* parse number in null terminated string 'p' and return it in the
   current token */
நிலையான வெறுமை parse_எண்(மாறிலி எழுத்து *p)
{
    முழு b, t, shift, frac_bits, s, exp_val, ch;
    எழுத்து *q;
    unsigned முழு bn[BN_SIZE];
    long இரட்டை d;

    /*எண்*/
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    எனில் (t == '.') {
        செல் float_frac_parse;
    } இல்லையெனில் எனில் (t == '0') {
        எனில் (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } இல்லையெனில் எனில் (tcc_state->tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    போது (1) {
        எனில் (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        இல்லையெனில் எனில் (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        இல்லையெனில் எனில் (isnum(ch))
            t = ch - '0';
        இல்லையெனில்
            நிறுத்து;
        எனில் (t >= b)
            நிறுத்து;
        எனில் (q >= token_buf + STRING_MAX_SIZE) {
        இலக்கம்_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    எனில் (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        எனில் (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            frac_bits = 0;
            *q = '\0';
            எனில் (b == 16)
                shift = 4;
            இல்லையெனில் 
                shift = 1;
            bn_zero(bn);
            q = token_buf;
            போது (1) {
                t = *q++;
                எனில் (t == '\0') {
                    நிறுத்து;
                } இல்லையெனில் எனில் (t >= 'a') {
                    t = t - 'a' + 10;
                } இல்லையெனில் எனில் (t >= 'A') {
                    t = t - 'A' + 10;
                } இல்லையெனில் {
                    t = t - '0';
                }
                frac_bits -= bn_lshift(bn, shift, t);
            }
            எனில் (ch == '.') {
                ch = *p++;
                போது (1) {
                    t = ch;
                    எனில் (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } இல்லையெனில் எனில் (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } இல்லையெனில் எனில் (t >= '0' && t <= '9') {
                        t = t - '0';
                    } இல்லையெனில் {
                        நிறுத்து;
                    }
                    எனில் (t >= b)
                        tcc_error("invalid digit");
                    frac_bits -= bn_lshift(bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            எனில் (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            எனில் (ch == '+') {
                ch = *p++;
            } இல்லையெனில் எனில் (ch == '-') {
                s = -1;
                ch = *p++;
            }
            எனில் (ch < '0' || ch > '9')
                expect("exponent digits");
            போது (ch >= '0' && ch <= '9') {
		/* If exp_val is this large ldexp will return HUGE_VAL */
		எனில் (exp_val < 100000000)
                    exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;

            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (long இரட்டை)bn[3] * 79228162514264337593543950336.0L +
	        (long இரட்டை)bn[2] * 18446744073709551616.0L +
	        (long இரட்டை)bn[1] * 4294967296.0L +
	        (long இரட்டை)bn[0];
            d = ldexpl(d, exp_val - frac_bits);
            t = toup(ch);
            எனில் (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (தசம)d;
            } இல்லையெனில் எனில் (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = d;
            } இல்லையெனில் {
                tok = TOK_CDOUBLE;
                tokc.d = (இரட்டை)d;
            }
        } இல்லையெனில் {
            /* decimal floats */
            எனில் (ch == '.') {
                எனில் (q >= token_buf + STRING_MAX_SIZE)
                    செல் இலக்கம்_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                போது (ch >= '0' && ch <= '9') {
                    எனில் (q >= token_buf + STRING_MAX_SIZE)
                        செல் இலக்கம்_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            எனில் (ch == 'e' || ch == 'E') {
                எனில் (q >= token_buf + STRING_MAX_SIZE)
                    செல் இலக்கம்_too_long;
                *q++ = ch;
                ch = *p++;
                எனில் (ch == '-' || ch == '+') {
                    எனில் (q >= token_buf + STRING_MAX_SIZE)
                        செல் இலக்கம்_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                எனில் (ch < '0' || ch > '9')
                    expect("exponent digits");
                போது (ch >= '0' && ch <= '9') {
                    எனில் (q >= token_buf + STRING_MAX_SIZE)
                        செல் இலக்கம்_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
            errno = 0;
            எனில் (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, வெற்று);
            } இல்லையெனில் எனில் (t == 'L') {
                ch = *p++;
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, வெற்று);
            } இல்லையெனில் {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, வெற்று);
            }
        }
    } இல்லையெனில் {
        unsigned long long n, n1;
        முழு lcount, ucount, ov = 0;
        மாறிலி எழுத்து *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        எனில் (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        போது(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            எனில் (t == '\0')
                நிறுத்து;
            இல்லையெனில் எனில் (t >= 'a')
                t = t - 'a' + 10;
            இல்லையெனில் எனில் (t >= 'A')
                t = t - 'A' + 10;
            இல்லையெனில்
                t = t - '0';
            எனில் (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            எனில் (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        க்கு(;;) {
            t = toup(ch);
            எனில் (t == 'L') {
                எனில் (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                எனில் (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } இல்லையெனில் எனில் (t == 'U') {
                எனில் (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } இல்லையெனில் {
                நிறுத்து;
            }
        }

        /* in #if/#elif expressions, all numbers have type (u)intmax_t anyway */
        எனில் (pp_கோவை)
            lcount = 2;

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        எனில் (ucount == 0 && b == 10) {
            எனில் (lcount <= (LONG_SIZE == 4)) {
                எனில் (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            எனில் (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } இல்லையெனில் {
            எனில் (lcount <= (LONG_SIZE == 4)) {
                எனில் (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                இல்லையெனில் எனில் (n >= 0x80000000U)
                    ucount = 1;
            }
            எனில் (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        எனில் (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	எனில் (lcount) {
            tok = TOK_CLONG;
            எனில் (lcount == 2)
                tok = TOK_CLLONG;
	}
	எனில் (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    எனில் (ch)
        tcc_error("invalid number");
}


#define PARSE2(c1, tok1, c2, tok2)              \
    நிலை c1:                                    \
        PEEKC(c, p);                            \
        எனில் (c == c2) {                          \
            p++;                                \
            tok = tok2;                         \
        } இல்லையெனில் {                                \
            tok = tok1;                         \
        }                                       \
        நிறுத்து;

/* return next token without macro substitution */
நிலையான வெறுமை next_nomacro(வெறுமை)
{
    முழு t, c, is_long, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned முழு h;

    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    தேர்வு(c) {
    நிலை ' ':
    நிலை '\t':
        tok = c;
        p++;
 maybe_space:
        எனில் (parse_flags & PARSE_FLAG_SPACES)
            செல் keep_tok_flags;
        போது (isidnum_table[*p - CH_EOF] & IS_SPC)
            ++p;
        செல் redo_no_start;
    நிலை '\f':
    நிலை '\v':
    நிலை '\r':
        p++;
        செல் redo_no_start;
    நிலை '\\':
        /* first look if it is in fact an end of buffer */
        c = handle_stray(&p);
        எனில் (c == '\\')
            செல் parse_simple;
        எனில் (c == CH_EOF) {
            TCCState *s1 = tcc_state;
            எனில் (!(tok_flags & TOK_FLAG_BOL)) {
                /* add implicit newline */
                செல் maybe_newline;
            } இல்லையெனில் எனில் (!(parse_flags & PARSE_FLAG_PREPROCESS)) {
                tok = TOK_EOF;
            } இல்லையெனில் எனில் (s1->ifdef_அடுக்கு_ptr != file->ifdef_அடுக்கு_ptr) {
                tcc_error("missing #endif");
            } இல்லையெனில் எனில் (s1->include_அடுக்கு_ptr == s1->include_அடுக்கு) {
                /* no include left : end of file. */
                tok = TOK_EOF;
            } இல்லையெனில் {
                /* pop include file */

                /* test if previous '#endif' was after a #ifdef at
                   start of file */
                எனில் (tok_flags & TOK_FLAG_ENDIF) {
#ifdef INC_DEBUG
                    printf("#endif %s\n", get_tok_str(file->ifndef_macro_saved, வெற்று));
#endif
                    தேடல்_cached_include(s1, file->true_filename, 1)
                        ->ifndef_macro = file->ifndef_macro_saved;
                    tok_flags &= ~TOK_FLAG_ENDIF;
                }

                /* add end of include file debug info */
                tcc_debug_eincl(tcc_state);
                /* pop include stack */
                tcc_close();
                s1->include_அடுக்கு_ptr--;
                p = file->buf_ptr;
                செல் maybe_newline;
            }
        } இல்லையெனில் {
            செல் redo_no_start;
        }
        நிறுத்து;

    நிலை '\n':
        file->வரி_இலக்கம்++;
        p++;
maybe_newline:
        tok_flags |= TOK_FLAG_BOL;
        எனில் (0 == (parse_flags & PARSE_FLAG_LINEFEED))
            செல் redo_no_start;
        tok = TOK_LINEFEED;
        செல் keep_tok_flags;

    நிலை '#':
        /* XXX: simplify */
        PEEKC(c, p);
        எனில் ((tok_flags & TOK_FLAG_BOL) && 
            (parse_flags & PARSE_FLAG_PREPROCESS)) {
            tok_flags &= ~TOK_FLAG_BOL;
            file->buf_ptr = p;
            preprocess(tok_flags & TOK_FLAG_BOF);
            p = file->buf_ptr;
            செல் maybe_newline;
        } இல்லையெனில் {
            எனில் (c == '#') {
                p++;
                tok = TOK_TWOSHARPS;
            } இல்லையெனில் {
#எனில் !defined(TCC_TARGET_ARM) && !defined(TCC_TARGET_ARM64)
                எனில் (parse_flags & PARSE_FLAG_ASM_FILE) {
                    p = parse_வரி_comment(p - 1);
                    செல் redo_no_start;
                } இல்லையெனில்
#endif
                {
                    tok = '#';
                }
            }
        }
        நிறுத்து;
    
    /* dollar is allowed to start identifiers when not parsing asm */
    நிலை '$':
        எனில் (!(isidnum_table['$' - CH_EOF] & IS_ID)
         || (parse_flags & PARSE_FLAG_ASM_FILE))
            செல் parse_simple;

    நிலை 'a': நிலை 'b': நிலை 'c': நிலை 'd':
    நிலை 'e': நிலை 'f': நிலை 'g': நிலை 'h':
    நிலை 'i': நிலை 'j': நிலை 'k': நிலை 'l':
    நிலை 'm': நிலை 'n': நிலை 'o': நிலை 'p':
    நிலை 'q': நிலை 'r': நிலை 's': நிலை 't':
    நிலை 'u': நிலை 'v': நிலை 'w': நிலை 'x':
    நிலை 'y': நிலை 'z': 
    நிலை 'A': நிலை 'B': நிலை 'C': நிலை 'D':
    நிலை 'E': நிலை 'F': நிலை 'G': நிலை 'H':
    நிலை 'I': நிலை 'J': நிலை 'K': 
    நிலை 'M': நிலை 'N': நிலை 'O': நிலை 'P':
    நிலை 'Q': நிலை 'R': நிலை 'S': நிலை 'T':
    நிலை 'U': நிலை 'V': நிலை 'W': நிலை 'X':
    நிலை 'Y': நிலை 'Z': 
    நிலை '_':
    parse_ident_fast:
        p1 = p;
        h = TOK_HASH_INIT;
        h = TOK_HASH_FUNC(h, c);
        போது (c = *++p, isidnum_table[c - CH_EOF] & (IS_ID|IS_இலக்கம்))
            h = TOK_HASH_FUNC(h, c);
        len = p - p1;
        எனில் (c != '\\') {
            TokenSym **pts;

            /* fast case : no stray found, so we have the full token
               and we have already hashed it */
            h &= (TOK_HASH_SIZE - 1);
            pts = &hash_ident[h];
            க்கு(;;) {
                ts = *pts;
                எனில் (!ts)
                    நிறுத்து;
                எனில் (ts->len == len && !memcmp(ts->str, p1, len))
                    செல் token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (எழுத்து *) p1, len);
        token_found: ;
        } இல்லையெனில் {
            /* slower case */
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (எழுத்து *) p1, len);
            p--;
            PEEKC(c, p);
            போது (isidnum_table[c - CH_EOF] & (IS_ID|IS_இலக்கம்))
            {
                cstr_ccat(&tokcstr, c);
                PEEKC(c, p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        நிறுத்து;
    நிலை 'L':
        t = p[1];
        எனில் (t == '\'' || t == '\"' || t == '\\') {
            PEEKC(c, p);
            எனில் (c == '\'' || c == '\"') {
                is_long = 1;
                செல் str_const;
            }
            *--p = c = 'L';
        }
        செல் parse_ident_fast;

    நிலை '0': நிலை '1': நிலை '2': நிலை '3':
    நிலை '4': நிலை '5': நிலை '6': நிலை '7':
    நிலை '8': நிலை '9':
        t = c;
        PEEKC(c, p);
        /* after the first digit, accept digits, alpha, '.' or sign if
           prefixed by 'eEpP' */
    parse_இலக்கம்:
        cstr_reset(&tokcstr);
        க்கு(;;) {
            cstr_ccat(&tokcstr, t);
            எனில் (!((isidnum_table[c - CH_EOF] & (IS_ID|IS_இலக்கம்))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(parse_flags & PARSE_FLAG_ASM_FILE
                                /* 0xe+1 is 3 tokens in asm */
                                && ((எழுத்து*)tokcstr.data)[0] == '0'
                                && toup(((எழுத்து*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                நிறுத்து;
            t = c;
            PEEKC(c, p);
        }
        /* We add a trailing '\0' to ease parsing */
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPNUM;
        நிறுத்து;

    நிலை '.':
        /* special dot handling because it can also start a number */
        PEEKC(c, p);
        எனில் (isnum(c)) {
            t = '.';
            செல் parse_இலக்கம்;
        } இல்லையெனில் எனில் ((isidnum_table['.' - CH_EOF] & IS_ID)
                   && (isidnum_table[c - CH_EOF] & (IS_ID|IS_இலக்கம்))) {
            *--p = c = '.';
            செல் parse_ident_fast;
        } இல்லையெனில் எனில் (c == '.') {
            PEEKC(c, p);
            எனில் (c == '.') {
                p++;
                tok = TOK_DOTS;
            } இல்லையெனில் {
                *--p = '.'; /* may underflow into file->unget[] */
                tok = '.';
            }
        } இல்லையெனில் {
            tok = '.';
        }
        நிறுத்து;
    நிலை '\'':
    நிலை '\"':
        is_long = 0;
    str_const:
        cstr_reset(&tokcstr);
        எனில் (is_long)
            cstr_ccat(&tokcstr, 'L');
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = TOK_PPSTR;
        நிறுத்து;

    நிலை '<':
        PEEKC(c, p);
        எனில் (c == '=') {
            p++;
            tok = TOK_LE;
        } இல்லையெனில் எனில் (c == '<') {
            PEEKC(c, p);
            எனில் (c == '=') {
                p++;
                tok = TOK_A_SHL;
            } இல்லையெனில் {
                tok = TOK_SHL;
            }
        } இல்லையெனில் {
            tok = TOK_LT;
        }
        நிறுத்து;
    நிலை '>':
        PEEKC(c, p);
        எனில் (c == '=') {
            p++;
            tok = TOK_GE;
        } இல்லையெனில் எனில் (c == '>') {
            PEEKC(c, p);
            எனில் (c == '=') {
                p++;
                tok = TOK_A_SAR;
            } இல்லையெனில் {
                tok = TOK_SAR;
            }
        } இல்லையெனில் {
            tok = TOK_GT;
        }
        நிறுத்து;
        
    நிலை '&':
        PEEKC(c, p);
        எனில் (c == '&') {
            p++;
            tok = TOK_LAND;
        } இல்லையெனில் எனில் (c == '=') {
            p++;
            tok = TOK_A_AND;
        } இல்லையெனில் {
            tok = '&';
        }
        நிறுத்து;
        
    நிலை '|':
        PEEKC(c, p);
        எனில் (c == '|') {
            p++;
            tok = TOK_LOR;
        } இல்லையெனில் எனில் (c == '=') {
            p++;
            tok = TOK_A_OR;
        } இல்லையெனில் {
            tok = '|';
        }
        நிறுத்து;

    நிலை '+':
        PEEKC(c, p);
        எனில் (c == '+') {
            p++;
            tok = TOK_INC;
        } இல்லையெனில் எனில் (c == '=') {
            p++;
            tok = TOK_A_ADD;
        } இல்லையெனில் {
            tok = '+';
        }
        நிறுத்து;
        
    நிலை '-':
        PEEKC(c, p);
        எனில் (c == '-') {
            p++;
            tok = TOK_DEC;
        } இல்லையெனில் எனில் (c == '=') {
            p++;
            tok = TOK_A_SUB;
        } இல்லையெனில் எனில் (c == '>') {
            p++;
            tok = TOK_ARROW;
        } இல்லையெனில் {
            tok = '-';
        }
        நிறுத்து;

    PARSE2('!', '!', '=', TOK_NE)
    PARSE2('=', '=', '=', TOK_EQ)
    PARSE2('*', '*', '=', TOK_A_MUL)
    PARSE2('%', '%', '=', TOK_A_MOD)
    PARSE2('^', '^', '=', TOK_A_XOR)
        
        /* comments or operator */
    நிலை '/':
        PEEKC(c, p);
        எனில் (c == '*') {
            p = parse_comment(p);
            /* comments replaced by a blank */
            tok = ' ';
            செல் maybe_space;
        } இல்லையெனில் எனில் (c == '/') {
            p = parse_வரி_comment(p);
            tok = ' ';
            செல் maybe_space;
        } இல்லையெனில் எனில் (c == '=') {
            p++;
            tok = TOK_A_DIV;
        } இல்லையெனில் {
            tok = '/';
        }
        நிறுத்து;
        
        /* simple tokens */
    நிலை '@': /* only used in assembler */
#ifdef TCC_TARGET_ARM /* comment on arm asm */
        எனில் (parse_flags & PARSE_FLAG_ASM_FILE) {
            p = parse_வரி_comment(p);
            செல் redo_no_start;
        }
#endif
    நிலை '(':
    நிலை ')':
    நிலை '[':
    நிலை ']':
    நிலை '{':
    நிலை '}':
    நிலை ',':
    நிலை ';':
    நிலை ':':
    நிலை '?':
    நிலை '~':
    parse_simple:
        tok = c;
        p++;
        நிறுத்து;
    நிலை 0xEF: /* UTF8 BOM ? */
        எனில் (p[1] == 0xBB && p[2] == 0xBF && p == file->buffer) {
            p += 3;
            செல் redo_no_start;
        }
    இயல்பு:
        எனில் (c >= 0x80 && c <= 0xFF) /* utf8 identifiers */
	    செல் parse_ident_fast;
        எனில் (parse_flags & PARSE_FLAG_ASM_FILE)
            செல் parse_simple;
        tcc_error("unrecognized character \\x%02x", c);
        நிறுத்து;
    }
    tok_flags = 0;
keep_tok_flags:
    file->buf_ptr = p;
#எனில் defined(PARSE_DEBUG)
    printf("token = %d %s\n", tok, get_tok_str(tok, &tokc));
#endif
}

#ifdef PP_DEBUG
நிலையான முழு indent;
நிலையான வெறுமை define_print(TCCState *s1, முழு v);
நிலையான வெறுமை pp_print(மாறிலி எழுத்து *செய்தி, முழு v, மாறிலி முழு *str)
{
    FILE *fp = tcc_state->ppfp;

    எனில் (செய்தி[0] == '#' && indent == 0)
        fprintf(fp, "\n");
    இல்லையெனில் எனில் (செய்தி[0] == '+')
         ++indent, ++செய்தி;
    இல்லையெனில் எனில் (செய்தி[0] == '-')
        --indent, ++செய்தி;

    fprintf(fp, "%*s", indent, "");
    எனில் (செய்தி[0] == '#') {
        define_print(tcc_state, v);
    } இல்லையெனில் {
        tok_print(str, v ? "%s %s" : "%s", செய்தி, get_tok_str(v, 0));
    }
}
#define PP_PRINT(x) pp_print x
#இல்லையெனில்
#define PP_PRINT(x)
#endif

நிலையான முழு macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    மாறிலி முழு *macro_str
    );

/* substitute arguments in replacement lists in macro_str by the values in
   args (field d) and return allocated string */
நிலையான முழு *macro_arg_subst(Sym **nested_list, மாறிலி முழு *macro_str, Sym *args)
{
    முழு t, t0, t1, t2, n;
    மாறிலி முழு *st;
    Sym *s;
    CValue cval;
    TokenString str;

#ifdef PP_DEBUG
    PP_PRINT(("asubst:", 0, macro_str));
    க்கு (s = args, n = 0; s; s = s->prev, ++n);
    போது (n--) {
        க்கு (s = args, t = 0; t < n; s = s->prev, ++t);
        tok_print(s->d, "%*s - arg: %s:", indent, "", get_tok_str(s->v, 0));
    }
#endif

    tok_str_new(&str);
    t0 = t1 = 0;
    போது(1) {
        TOK_GET(&t, &macro_str, &cval);
        எனில் (!t)
            நிறுத்து;
        எனில் (t == '#') {
            /* stringize */
            செய் t = *macro_str++; போது (t == ' ');
            s = sym_find2(args, t);
            எனில் (s) {
                cstr_reset(&tokcstr);
                cstr_ccat(&tokcstr, '\"');
                st = s->d;
                போது (*st != TOK_EOF) {
                    மாறிலி எழுத்து *s;
                    TOK_GET(&t, &st, &cval);
                    s = get_tok_str(t, &cval);
                    போது (*s) {
                        எனில் (t == TOK_PPSTR && *s != '\'')
                            add_char(&tokcstr, *s);
                        இல்லையெனில்
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
            } இல்லையெனில் எனில் ((parse_flags & PARSE_FLAG_ASM_FILE) && t == TOK_PPNUM) {
                /* for example: mov r1,#0 */
                --macro_str, tok_str_add(&str, '#');
#endif
            } இல்லையெனில் {
                expect("macro parameter after '#'");
            }
        } இல்லையெனில் எனில் (t >= TOK_IDENT) {
            s = sym_find2(args, t);
            எனில் (s) {
                st = s->d;
                n = 0;
                போது ((t2 = macro_str[n]) == ' ')
                    ++n;
                /* if '##' is present before or after, no arg substitution */
                எனில் (t2 == TOK_PPJOIN || t1 == TOK_PPJOIN) {
                    /* special case for var arg macros : ## eats the ','
                       if empty VA_ARGS variable. */
                    எனில் (t1 == TOK_PPJOIN && t0 == ',' && gnu_ext && s->type.t) {
                        முழு c = str.str[str.len - 1];
                        போது (str.str[--str.len] != ',')
                            ;
                        எனில் (*st == TOK_EOF) {
                            /* suppress ',' '##' */
                        } இல்லையெனில் {
                            /* suppress '##' and add variable */
                            str.len++;
                            எனில் (c == ' ')
                                str.str[str.len++] = c;
                            செல் add_var;
                        }
                    } இல்லையெனில் {
                        எனில் (*st == TOK_EOF)
                            tok_str_add(&str, TOK_PLCHLDR);
                    }
                } இல்லையெனில் {
            add_var:
		    எனில் (!s->e) {
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
                போது (*st != TOK_EOF) {
                    TOK_GET(&t2, &st, &cval);
                    tok_str_add2(&str, t2, &cval);
                }
            } இல்லையெனில் {
                tok_str_add(&str, t);
            }
        } இல்லையெனில் {
            tok_str_add2(&str, t, &cval);
        }
        எனில் (t != ' ')
            t0 = t1, t1 = t;
    }
    tok_str_add(&str, 0);
    PP_PRINT(("areslt:", 0, str.str));
    திரும்பு str.str;
}

/* handle the '##' operator. return the resulting string (which must be freed). */
நிலையான உள்வரி முழு *macro_twosharps(மாறிலி முழு *ptr0)
{
    முழு t1, t2, n, l;
    CValue cv1, cv2;
    TokenString macro_str1;
    மாறிலி முழு *ptr;

    tok_str_new(&macro_str1);
    cstr_reset(&tokcstr);
    க்கு (ptr = ptr0;;) {
        TOK_GET(&t1, &ptr, &cv1);
        எனில் (t1 == 0)
            நிறுத்து;
        க்கு (;;) {
            n = 0;
            போது ((t2 = ptr[n]) == ' ')
                ++n;
            எனில் (t2 != TOK_PPJOIN)
                நிறுத்து;
            ptr += n;
            போது ((t2 = *++ptr) == ' ' || t2 == TOK_PPJOIN)
                ;
            TOK_GET(&t2, &ptr, &cv2);
            எனில் (t2 == TOK_PLCHLDR)
                தொடர்;
            எனில் (t1 != TOK_PLCHLDR) {
                cstr_cat(&tokcstr, get_tok_str(t1, &cv1), -1);
                t1 = TOK_PLCHLDR;
            }
            cstr_cat(&tokcstr, get_tok_str(t2, &cv2), -1);
        }
        எனில் (tokcstr.size) {
            cstr_ccat(&tokcstr, 0);
            tcc_open_bf(tcc_state, ":paste:", tokcstr.size);
            memcpy(file->buffer, tokcstr.data, tokcstr.size);
            tok_flags = 0; /* don't interpret '#' */
            க்கு (n = 0;;n = l) {
                next_nomacro();
                tok_str_add2(&macro_str1, tok, &tokc);
                எனில் (*file->buf_ptr == 0)
                    நிறுத்து;
                tok_str_add(&macro_str1, ' ');
                l = file->buf_ptr - file->buffer;
                tcc_warning("pasting \"%.*s\" and \"%s\" does not give a valid"
                    " preprocessing token", l - n, file->buffer + n, file->buf_ptr);
            }
            tcc_close();
            cstr_reset(&tokcstr);
        }
        எனில் (t1 != TOK_PLCHLDR)
            tok_str_add2(&macro_str1, t1, &cv1);
    }
    tok_str_add(&macro_str1, 0);
    PP_PRINT(("pasted:", 0, macro_str1.str));
    திரும்பு macro_str1.str;
}

நிலையான முழு peek_file (TokenString *ws_str)
{
    uint8_t *p = file->buf_ptr - 1;
    முழு c;
    க்கு (;;) {
        PEEKC(c, p);
        தேர்வு (c) {
        நிலை '/':
            PEEKC(c, p);
            எனில் (c == '*')
                p = parse_comment(p);
            இல்லையெனில் எனில் (c == '/')
                p = parse_வரி_comment(p);
            இல்லையெனில் {
                c = *--p = '/';
                செல் leave;
            }
            --p, c = ' ';
            நிறுத்து;
        நிலை ' ': நிலை '\t':
            நிறுத்து;
        நிலை '\f': நிலை '\v': நிலை '\r':
            தொடர்;
        நிலை '\n':
            file->வரி_இலக்கம்++, tok_flags |= TOK_FLAG_BOL;
            நிறுத்து;
        இயல்பு: leave:
            file->buf_ptr = p;
            திரும்பு c;
        }
        எனில் (ws_str)
            tok_str_add(ws_str, c);
    }
}

/* peek or read [ws_str == NULL] next token from function macro call,
   walking up macro levels up to the file if necessary */
நிலையான முழு next_argstream(Sym **nested_list, TokenString *ws_str)
{
    முழு t;
    Sym *sa;

    போது (macro_ptr) {
        மாறிலி முழு *m = macro_ptr;
        போது ((t = *m) != 0) {
            எனில் (ws_str) {
                எனில் (t != ' ')
                    திரும்பு t;
                ++m;
            } இல்லையெனில் {
                TOK_GET(&tok, &macro_ptr, &tokc);
                திரும்பு tok;
            }
        }
        end_macro();
        /* also, end of scope for nested defined symbol */
        sa = *nested_list;
        எனில் (sa)
            *nested_list = sa->prev, sym_free(sa);
    }
    எனில் (ws_str) {
        திரும்பு peek_file(ws_str);
    } இல்லையெனில் {
        next_nomacro();
        எனில் (tok == '\t' || tok == TOK_LINEFEED)
            tok = ' ';
        திரும்பு tok;
    }
}

/* do macro substitution of current token with macro 's' and add
   result to (tok_str,tok_len). 'nested_list' is the list of all
   macros we got inside to avoid recursing. Return non zero if no
   substitution needs to be done */
நிலையான முழு macro_subst_tok(
    TokenString *tok_str,
    Sym **nested_list,
    Sym *s)
{
    முழு t;
    முழு v = s->v;

    PP_PRINT(("#", v, s->d));
    எனில் (s->d) {
        முழு *mstr = s->d;
        முழு *jstr;
        Sym *sa;
        முழு ret;

        எனில் (s->type.t & MACRO_FUNC) {
            முழு saved_parse_flags = parse_flags;
            TokenString str;
            முழு parlevel, i;
            Sym *sa1, *args;

            parse_flags |= PARSE_FLAG_SPACES | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_ACCEPT_STRAYS;

            tok_str_new(&str);
            /* peek next token from argument stream */
            t = next_argstream(nested_list, &str);
            எனில் (t != '(') {
                /* not a macro substitution after all, restore the
                 * macro token plus all whitespace we've read.
                 * whitespace is intentionally not merged to preserve
                 * newlines. */
                parse_flags = saved_parse_flags;
                tok_str_add2_spc(tok_str, v, 0);
                எனில் (parse_flags & PARSE_FLAG_SPACES)
                    க்கு (i = 0; i < str.len; i++)
                        tok_str_add(tok_str, str.str[i]);
                tok_str_free_str(str.str);
                திரும்பு 0;
            } இல்லையெனில் {
                tok_str_free_str(str.str);
            }

            /* argument macro */
            args = வெற்று;
            sa = s->next;
            /* NOTE: empty args are allowed, except if no args */
            i = 2; /* eat '(' */
            க்கு(;;) {
                செய் {
                    t = next_argstream(nested_list, வெற்று);
                } போது (t == ' ' || --i);

                எனில் (!sa) {
                    எனில் (t == ')') /* handle '()' case */
                        நிறுத்து;
                    tcc_error("macro '%s' used with too many args",
                        get_tok_str(v, 0));
                }
            empty_arg:
                tok_str_new(&str);
                parlevel = 0;
                /* NOTE: non zero sa->type.t indicates VA_ARGS */
                போது (parlevel > 0
                        || (t != ')' && (t != ',' || sa->type.t))) {
                    எனில் (t == TOK_EOF)
                        tcc_error("EOF in invocation of macro '%s'",
                            get_tok_str(v, 0));
                    எனில் (t == '(')
                        parlevel++;
                    எனில் (t == ')')
                        parlevel--;
                    எனில் (t == ' ')
                        str.need_spc |= 1;
                    இல்லையெனில்
                        tok_str_add2_spc(&str, t, &tokc);
                    t = next_argstream(nested_list, வெற்று);
                }
                tok_str_add(&str, TOK_EOF);
                sa1 = sym_push2(&args, sa->v & ~SYM_FIELD, sa->type.t, 0);
                sa1->d = str.str;
                sa = sa->next;
                எனில் (t == ')') {
                    எனில் (!sa)
                        நிறுத்து;
                    /* special case for gcc var args: add an empty
                       var arg argument if it is omitted */
                    எனில் (sa->type.t && gnu_ext)
                        செல் empty_arg;
                    tcc_error("macro '%s' used with too few args",
                        get_tok_str(v, 0));
                }
                i = 1;
            }

            /* now subst each arg */
            mstr = macro_arg_subst(nested_list, mstr, args);
            /* free memory */
            sa = args;
            போது (sa) {
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
        எனில் (s->type.t & MACRO_JOIN)
            jstr = macro_twosharps(mstr);

        sa = sym_push2(nested_list, v, 0, 0);
        ret = macro_subst(tok_str, nested_list, jstr);
        /* pop nested defined symbol */
        எனில் (sa == *nested_list)
            *nested_list = sa->prev, sym_free(sa);

        எனில் (jstr != mstr)
            tok_str_free_str(jstr);
        எனில் (mstr != s->d)
            tok_str_free_str(mstr);
        திரும்பு ret;

    } இல்லையெனில் {
        CValue cval;
        எழுத்து buf[32], *cstrval = buf;

        /* special macros */
        எனில் (v == TOK_வரி_2 || v == TOK___COUNTER__) {
            t = v == TOK_வரி_2 ? file->வரி_இலக்கம் : pp_counter++;
            snprintf(buf, அளவு(buf), "%d", t);
            t = TOK_PPNUM;
            செல் add_cstr1;

        } இல்லையெனில் எனில் (v == TOK___FILE__) {
            cstrval = file->filename;
            செல் add_cstr;

        } இல்லையெனில் எனில் (v == TOK___DATE__ || v == TOK___TIME__) {
            time_t ti;
            கட்டமைப்பு tm *tm;
            time(&ti);
            tm = localtime(&ti);
            எனில் (v == TOK___DATE__) {
                நிலையான எழுத்து மாறிலி ab_month_name[12][4] = {
                    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
                };
                snprintf(buf, அளவு(buf), "%s %2d %d",
                    ab_month_name[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
            } இல்லையெனில் {
                snprintf(buf, அளவு(buf), "%02d:%02d:%02d",
                    tm->tm_hour, tm->tm_min, tm->tm_sec);
            }
        add_cstr:
            t = TOK_STR;
        add_cstr1:
            cval.str.size = strlen(cstrval) + 1;
            cval.str.data = cstrval;
            tok_str_add2_spc(tok_str, t, &cval);
        }
        திரும்பு 0;
    }
}

/* do macro substitution of macro_str and add result to
   (tok_str,tok_len). 'nested_list' is the list of all macros we got
   inside to avoid recursing. */
நிலையான முழு macro_subst(
    TokenString *tok_str,
    Sym **nested_list,
    மாறிலி முழு *macro_str
    )
{
    Sym *s;
    முழு t, nosubst = 0;
    CValue cval;
    TokenString *str;

#ifdef PP_DEBUG
    முழு tlen = tok_str->len;
    PP_PRINT(("+expand:", 0, macro_str));
#endif

    போது (1) {
        TOK_GET(&t, &macro_str, &cval);
        எனில் (t == 0 || t == TOK_EOF)
            நிறுத்து;
        எனில் (t >= TOK_IDENT) {
            s = define_find(t);
            எனில் (s == வெற்று || nosubst)
                செல் no_subst;
            /* if nested substitution, do nothing */
            எனில் (sym_find2(*nested_list, t)) {
                /* and mark so it doesn't get subst'd again */
                t |= SYM_FIELD;
                செல் no_subst;
            }
            str = tok_str_alloc();
            str->str = (முழு*)macro_str; /* setup stream for possible arguments */
            begin_macro(str, 2);
            nosubst = macro_subst_tok(tok_str, nested_list, s);
            எனில் (macro_அடுக்கு != str) {
                /* already finished by reading function macro arguments */
                நிறுத்து;
            }
            macro_str = macro_ptr;
            end_macro ();
        } இல்லையெனில் எனில் (t == ' ') {
            எனில் (parse_flags & PARSE_FLAG_SPACES)
                tok_str->need_spc |= 1;
        } இல்லையெனில் {
    no_subst:
            tok_str_add2_spc(tok_str, t, &cval);
            எனில் (nosubst && t != '(')
                nosubst = 0;
            /* GCC supports 'defined' as result of a macro substitution */
            எனில் (t == TOK_DEFINED && pp_கோவை)
                nosubst = 1;
        }
    }

#ifdef PP_DEBUG
    tok_str_add(tok_str, 0), --tok_str->len;
    PP_PRINT(("-result:", 0, tok_str->str + tlen));
#endif
    திரும்பு nosubst;
}

/* return next token with macro substitution */
ST_FUNC வெறுமை next(வெறுமை)
{
    முழு t;
    போது (macro_ptr) {
redo:
        t = *macro_ptr;
        எனில் (TOK_HAS_மதிப்பு(t)) {
            tok_get(&tok, &macro_ptr, &tokc);
            எனில் (t == TOK_LINENUM) {
                file->வரி_இலக்கம் = tokc.i;
                செல் redo;
            }
            செல் convert;
        } இல்லையெனில் எனில் (t == 0) {
            /* end of macro or unget token string */
            end_macro();
            தொடர்;
        } இல்லையெனில் எனில் (t == TOK_EOF) {
            /* do nothing */
        } இல்லையெனில் {
            ++macro_ptr;
            t &= ~SYM_FIELD; /* remove 'nosubst' marker */
            எனில் (t == '\\') {
                எனில் (!(parse_flags & PARSE_FLAG_ACCEPT_STRAYS))
                    tcc_error("stray '\\' in program");
            }
        }
        tok = t;
        திரும்பு;
    }

    next_nomacro();
    t = tok;
    எனில் (t >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        /* if reading from file, try to substitute macros */
        Sym *s = define_find(t);
        எனில் (s) {
            Sym *nested_list = வெற்று;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 0);
            செல் redo;
        }
        திரும்பு;
    }

convert:
    /* convert preprocessor tokens into C tokens */
    எனில் (t == TOK_PPNUM) {
        எனில்  (parse_flags & PARSE_FLAG_TOK_இலக்கம்)
            parse_எண்(tokc.str.data);
    } இல்லையெனில் எனில் (t == TOK_PPSTR) {
        எனில் (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string(tokc.str.data, tokc.str.size - 1);
    }
}

/* push back current token and set current token to 'last_tok'. Only
   identifier case handled for labels. */
ST_INLN வெறுமை unget_tok(முழு last_tok)
{
    TokenString *str = &unget_buf;
    முழு alloc = 0;
    எனில் (str->len) /* use static buffer except if already in use */
        str = tok_str_alloc(), alloc = 1;
    எனில் (tok != TOK_EOF)
        tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, alloc);
    tok = last_tok;
}

/* ------------------------------------------------------------------------- */
/* init preprocessor */

நிலையான மாறிலி எழுத்து * மாறிலி target_os_defs =
#ifdef TCC_TARGET_PE
    "_WIN32\0"
# எனில் PTR_SIZE == 8
    "_WIN64\0"
# endif
#இல்லையெனில்
# எனில் defined TCC_TARGET_MACHO
    "__APPLE__\0"
# elif TARGETOS_FreeBSD
    "__FreeBSD__ 12\0"
# elif TARGETOS_FreeBSD_kernel
    "__FreeBSD_kernel__\0"
# elif TARGETOS_NetBSD
    "__NetBSD__\0"
# elif TARGETOS_OpenBSD
    "__OpenBSD__\0"
# இல்லையெனில்
    "__linux__\0"
    "__linux\0"
#  எனில் TARGETOS_ANDROID
    "__ANDROID__\0"
#  endif
# endif
    "__unix__\0"
    "__unix\0"
#endif
    ;

நிலையான வெறுமை putdef(CString *cs, மாறிலி எழுத்து *p)
{
    cstr_printf(cs, "#define %s%s\n", p, &" 1"[!!strchr(p, ' ')*2]);
}

நிலையான வெறுமை putdefs(CString *cs, மாறிலி எழுத்து *p)
{
    போது (*p)
        putdef(cs, p), p = strchr(p, 0) + 1;
}

நிலையான வெறுமை tcc_predefs(TCCState *s1, CString *cs, முழு is_asm)
{
    cstr_printf(cs, "#define __TINYC__ 9%.2s\n", &TCC_VERSION[4]);
    putdefs(cs, target_machine_defs);
    putdefs(cs, target_os_defs);

#ifdef TCC_TARGET_ARM
    எனில் (s1->float_abi == ARM_HARD_FLOAT)
      putdef(cs, "__ARM_PCS_VFP");
#endif
    எனில் (is_asm)
      putdef(cs, "__ASSEMBLER__");
    எனில் (s1->output_type == TCC_OUTPUT_PREPROCESS)
      putdef(cs, "__TCC_PP__");
    எனில் (s1->output_type == TCC_OUTPUT_MEMORY)
      putdef(cs, "__TCC_RUN__");
#ifdef CONFIG_TCC_BACKTRACE
    எனில் (s1->do_backtrace)
      putdef(cs, "__TCC_BACKTRACE__");
#endif
#ifdef CONFIG_TCC_BCHECK
    எனில் (s1->do_bounds_check)
      putdef(cs, "__TCC_BCHECK__");
#endif
    எனில் (s1->char_is_unsigned)
      putdef(cs, "__CHAR_UNSIGNED__");
    எனில் (s1->optimize > 0)
      putdef(cs, "__OPTIMIZE__");
    எனில் (s1->option_pthread)
      putdef(cs, "_REENTRANT");
    எனில் (s1->leading_underscore)
      putdef(cs, "__leading_underscore");
    cstr_printf(cs, "#define __SIZEOF_POINTER__ %d\n", PTR_SIZE);
    cstr_printf(cs, "#define __SIZEOF_LONG__ %d\n", LONG_SIZE);
    எனில் (!is_asm) {
      putdef(cs, "__STDC__");
      cstr_printf(cs, "#define __STDC_HOSTED__ %d\n", s1->nostdlib ? 0 : 1);
      cstr_printf(cs, "#define __STDC_VERSION__ %dL\n", s1->cversion);
      cstr_cat(cs,
        /* load more predefs and __builtins */
#எனில் CONFIG_TCC_PREDEFS
        #அந்தர்பாவ "tccdefs_.h" /* include as strings */
#இல்லையெனில்
        "#include <tccdefs.h>\n" /* load at runtime */
#endif
        , -1);
    }
    cstr_printf(cs, "#define __BASE_FILE__ \"%s\"\n", file->filename);
}

ST_FUNC வெறுமை preprocess_start(TCCState *s1, முழு filetype)
{
    முழு is_asm = !!(filetype & (AFF_TYPE_ASM|AFF_TYPE_ASMPP));

    tccpp_new(s1);

    s1->include_அடுக்கு_ptr = s1->include_அடுக்கு;
    s1->ifdef_அடுக்கு_ptr = s1->ifdef_அடுக்கு;
    file->ifdef_அடுக்கு_ptr = s1->ifdef_அடுக்கு_ptr;
    pp_கோவை = 0;
    pp_counter = 0;
    pp_debug_tok = pp_debug_symv = 0;
    s1->pack_அடுக்கு[0] = 0;
    s1->pack_அடுக்கு_ptr = s1->pack_அடுக்கு;

    set_idnum('$', s1->dollars_in_identifiers ? IS_ID : 0);
    set_idnum('.', is_asm ? IS_ID : 0);

    எனில் (!(filetype & AFF_TYPE_ASM)) {
        CString cstr;
        cstr_new(&cstr);
        tcc_predefs(s1, &cstr, is_asm);
        எனில் (s1->cmdline_defs.size)
          cstr_cat(&cstr, s1->cmdline_defs.data, s1->cmdline_defs.size);
        எனில் (s1->cmdline_incl.size)
          cstr_cat(&cstr, s1->cmdline_incl.data, s1->cmdline_incl.size);
        //printf("%.*s\n", cstr.size, (char*)cstr.data);
        *s1->include_அடுக்கு_ptr++ = file;
        tcc_open_bf(s1, "<command line>", cstr.size);
        memcpy(file->buffer, cstr.data, cstr.size);
        cstr_free(&cstr);
    }
    parse_flags = is_asm ? PARSE_FLAG_ASM_FILE : 0;
}

/* cleanup from error/setjmp */
ST_FUNC வெறுமை preprocess_end(TCCState *s1)
{
    போது (macro_அடுக்கு)
        end_macro();
    macro_ptr = வெற்று;
    போது (file)
        tcc_close();
    tccpp_delete(s1);
}

ST_FUNC முழு set_idnum(முழு c, முழு val)
{
    முழு prev = isidnum_table[c - CH_EOF];
    isidnum_table[c - CH_EOF] = val;
    திரும்பு prev;
}

ST_FUNC வெறுமை tccpp_new(TCCState *s)
{
    முழு i, c;
    மாறிலி எழுத்து *p, *r;

    /* init isid table */
    க்கு(i = CH_EOF; i<128; i++)
        set_idnum(i,
            is_space(i) ? IS_SPC
            : isid(i) ? IS_ID
            : isnum(i) ? IS_இலக்கம்
            : 0);

    க்கு(i = 128; i<256; i++)
        set_idnum(i, IS_ID);

    /* init allocators */
    tal_new(&toksym_alloc, TOKSYM_TAL_SIZE);
    tal_new(&tokstr_alloc, TOKSTR_TAL_SIZE);

    memset(hash_ident, 0, TOK_HASH_SIZE * அளவு(TokenSym *));
    memset(s->cached_includes_hash, 0, அளவு s->cached_includes_hash);

    cstr_new(&tokcstr);
    cstr_new(&cstr_buf);
    cstr_realloc(&cstr_buf, STRING_MAX_SIZE);
    tok_str_new(&unget_buf);
    tok_str_realloc(&unget_buf, TOKSTR_MAX_SIZE);
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, TOKSTR_MAX_SIZE);

    tok_ident = TOK_IDENT;
    p = tcc_keywords;
    போது (*p) {
        r = p;
        க்கு(;;) {
            c = *r++;
            எனில் (c == '\0')
                நிறுத்து;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_தள்ளு(TOK_வரி_2, MACRO_OBJ, வெற்று, வெற்று);
    define_தள்ளு(TOK___FILE__, MACRO_OBJ, வெற்று, வெற்று);
    define_தள்ளு(TOK___DATE__, MACRO_OBJ, வெற்று, வெற்று);
    define_தள்ளு(TOK___TIME__, MACRO_OBJ, வெற்று, வெற்று);
    define_தள்ளு(TOK___COUNTER__, MACRO_OBJ, வெற்று, வெற்று);
}

ST_FUNC வெறுமை tccpp_delete(TCCState *s)
{
    முழு i, n;

    dynarray_reset(&s->cached_includes, &s->nb_cached_includes);

    /* free tokens */
    n = tok_ident - TOK_IDENT;
    எனில் (n > total_idents)
        total_idents = n;
    க்கு (i = n; --i >= 0;)
        tal_free(&toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = வெற்று;

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

நிலையான முழு pp_need_space(முழு a, முழு b);

நிலையான வெறுமை tok_print(மாறிலி முழு *str, மாறிலி எழுத்து *செய்தி, ...)
{
    FILE *fp = tcc_state->ppfp;
    va_list ap;
    முழு t, t0, s;
    CValue cval;

    va_start(ap, செய்தி);
    vfprintf(fp, செய்தி, ap);
    va_end(ap);

    s = t0 = 0;
    போது (str) {
	TOK_GET(&t, &str, &cval);
	எனில் (t == 0 || t == TOK_EOF)
	    நிறுத்து;
        எனில் (pp_need_space(t0, t))
            s = 0;
	fprintf(fp, &" %s"[s], t == TOK_PLCHLDR ? "<>" : get_tok_str(t, &cval));
        s = 1, t0 = t;
    }
    fprintf(fp, "\n");
}

நிலையான வெறுமை pp_வரி(TCCState *s1, BufferedFile *f, முழு level)
{
    முழு d = f->வரி_இலக்கம் - f->வரி_ref;

    எனில் (s1->dflag & 4)
	திரும்பு;

    எனில் (s1->Pflag == வரி_MACRO_OUTPUT_FORMAT_NONE) {
        ;
    } இல்லையெனில் எனில் (level == 0 && f->வரி_ref && d < 8) {
	போது (d > 0)
	    fputs("\n", s1->ppfp), --d;
    } இல்லையெனில் எனில் (s1->Pflag == வரி_MACRO_OUTPUT_FORMAT_STD) {
	fprintf(s1->ppfp, "#line %d \"%s\"\n", f->வரி_இலக்கம், f->filename);
    } இல்லையெனில் {
	fprintf(s1->ppfp, "# %d \"%s\"%s\n", f->வரி_இலக்கம், f->filename,
	    level > 0 ? " 1" : level < 0 ? " 2" : "");
    }
    f->வரி_ref = f->வரி_இலக்கம்;
}

நிலையான வெறுமை define_print(TCCState *s1, முழு v)
{
    FILE *fp;
    Sym *s;

    s = define_find(v);
    எனில் (வெற்று == s || வெற்று == s->d)
        திரும்பு;

    fp = s1->ppfp;
    fprintf(fp, "#define %s", get_tok_str(v, வெற்று));
    எனில் (s->type.t & MACRO_FUNC) {
        Sym *a = s->next;
        fprintf(fp,"(");
        எனில் (a)
            க்கு (;;) {
                fprintf(fp,"%s", get_tok_str(a->v, வெற்று));
                எனில் (!(a = a->next))
                    நிறுத்து;
                fprintf(fp,",");
            }
        fprintf(fp,")");
    }
    tok_print(s->d, "");
}

நிலையான வெறுமை pp_debug_defines(TCCState *s1)
{
    முழு v, t;
    மாறிலி எழுத்து *vs;
    FILE *fp;

    t = pp_debug_tok;
    எனில் (t == 0)
        திரும்பு;

    file->வரி_இலக்கம்--;
    pp_வரி(s1, file, 0);
    file->வரி_ref = ++file->வரி_இலக்கம்;

    fp = s1->ppfp;
    v = pp_debug_symv;
    vs = get_tok_str(v, வெற்று);
    எனில் (t == TOK_DEFINE) {
        define_print(s1, v);
    } இல்லையெனில் எனில் (t == TOK_UNDEF) {
        fprintf(fp, "#undef %s\n", vs);
    } இல்லையெனில் எனில் (t == TOK_தள்ளு_macro) {
        fprintf(fp, "#pragma push_macro(\"%s\")\n", vs);
    } இல்லையெனில் எனில் (t == TOK_எடு_macro) {
        fprintf(fp, "#pragma pop_macro(\"%s\")\n", vs);
    }
    pp_debug_tok = 0;
}

/* Add a space between tokens a and b to avoid unwanted textual pasting */
நிலையான முழு pp_need_space(முழு a, முழு b)
{
    திரும்பு 'E' == a ? '+' == b || '-' == b
        : '+' == a ? TOK_INC == b || '+' == b
        : '-' == a ? TOK_DEC == b || '-' == b
        : a >= TOK_IDENT || a == TOK_PPNUM ? b >= TOK_IDENT || b == TOK_PPNUM
        : 0;
}

/* maybe hex like 0x1e */
நிலையான முழு pp_check_he0xE(முழு t, மாறிலி எழுத்து *p)
{
    எனில் (t == TOK_PPNUM && toup(strchr(p, 0)[-1]) == 'E')
        திரும்பு 'E';
    திரும்பு t;
}

/* Preprocess the current file */
ST_FUNC முழு tcc_preprocess(TCCState *s1)
{
    BufferedFile **iptr;
    முழு token_seen, spcs, level;
    மாறிலி எழுத்து *p;
    எழுத்து white[400];

    parse_flags = PARSE_FLAG_PREPROCESS
                | (parse_flags & PARSE_FLAG_ASM_FILE)
                | PARSE_FLAG_LINEFEED
                | PARSE_FLAG_SPACES
                | PARSE_FLAG_ACCEPT_STRAYS
                ;
    /* Credits to Fabrice Bellard's initial revision to demonstrate its
       capability to compile and run itself, provided all numbers are
       given as decimals. tcc -E -P10 will do. */
    எனில் (s1->Pflag == வரி_MACRO_OUTPUT_FORMAT_P10)
        parse_flags |= PARSE_FLAG_TOK_இலக்கம், s1->Pflag = 1;

    எனில் (s1->do_bench) {
	/* for PP benchmarks */
	செய் next(); போது (tok != TOK_EOF);
	திரும்பு 0;
    }

    token_seen = TOK_LINEFEED, spcs = 0, level = 0;
    எனில் (file->prev)
        pp_வரி(s1, file->prev, level++);
    pp_வரி(s1, file, level);

    க்கு (;;) {
        iptr = s1->include_அடுக்கு_ptr;
        next();
        எனில் (tok == TOK_EOF)
            நிறுத்து;

        level = s1->include_அடுக்கு_ptr - iptr;
        எனில் (level) {
            எனில் (level > 0)
                pp_வரி(s1, *iptr, 0);
            pp_வரி(s1, file, level);
        }
        எனில் (s1->dflag & 7) {
            pp_debug_defines(s1);
            எனில் (s1->dflag & 4)
                தொடர்;
        }

        எனில் (is_space(tok)) {
            எனில் (spcs < அளவு white - 1)
                white[spcs++] = tok;
            தொடர்;
        } இல்லையெனில் எனில் (tok == TOK_LINEFEED) {
            spcs = 0;
            எனில் (token_seen == TOK_LINEFEED)
                தொடர்;
            ++file->வரி_ref;
        } இல்லையெனில் எனில் (token_seen == TOK_LINEFEED) {
            pp_வரி(s1, file, 0);
        } இல்லையெனில் எனில் (spcs == 0 && pp_need_space(token_seen, tok)) {
            white[spcs++] = ' ';
        }

        white[spcs] = 0, fputs(white, s1->ppfp), spcs = 0;
        fputs(p = get_tok_str(tok, &tokc), s1->ppfp);
        token_seen = pp_check_he0xE(tok, p);
    }
    திரும்பு 0;
}

/* ------------------------------------------------------------------------- */
