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

#ifndef ONE_SOURCE
# define ONE_SOURCE 1
#endif

#જો ONE_SOURCE
#અન્તર્ભાવ "tccpp.c"
#અન્તર્ભાવ "tccgen.c"
#અન્તર્ભાવ "tccdbg.c"
#અન્તર્ભાવ "tccasm.c"
#અન્તર્ભાવ "tccelf.c"
#અન્તર્ભાવ "tccrun.c"
#ifdef TCC_TARGET_I386
#અન્તર્ભાવ "i386-gen.c"
#અન્તર્ભાવ "i386-link.c"
#અન્તર્ભાવ "i386-asm.c"
#અથવાજો defined(TCC_TARGET_ARM)
#અન્તર્ભાવ "arm-gen.c"
#અન્તર્ભાવ "arm-link.c"
#અન્તર્ભાવ "arm-asm.c"
#અથવાજો defined(TCC_TARGET_ARM64)
#અન્તર્ભાવ "arm64-gen.c"
#અન્તર્ભાવ "arm64-link.c"
#અન્તર્ભાવ "arm64-asm.c"
#અથવાજો defined(TCC_TARGET_C67)
#અન્તર્ભાવ "c67-gen.c"
#અન્તર્ભાવ "c67-link.c"
#અન્તર્ભાવ "tcccoff.c"
#અથવાજો defined(TCC_TARGET_X86_64)
#અન્તર્ભાવ "x86_64-gen.c"
#અન્તર્ભાવ "x86_64-link.c"
#અન્તર્ભાવ "i386-asm.c"
#અથવાજો defined(TCC_TARGET_RISCV64)
#અન્તર્ભાવ "riscv64-gen.c"
#અન્તર્ભાવ "riscv64-link.c"
#અન્તર્ભાવ "riscv64-asm.c"
#નહીંતર
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#અન્તર્ભાવ "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#અન્તર્ભાવ "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#અન્તર્ભાવ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA સંરચના TCCState *tcc_state;
TCC_SEM(સ્થિર tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA શૂન્ય** stk_data;
ST_DATA પૂર્ણાંક nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA પૂર્ણાંક g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC અક્ષર *normalize_slashes(અક્ષર *path)
{
    અક્ષર *p;
    માટે (p = path; *p; ++p)
        જો (*p == '\\')
            *p = '/';
    પાછા path;
}

#જો defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
સ્થિર HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    જો (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    પાછા TRUE;
}
#નહીંતર
#define tcc_module ખાલી /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
સ્થિર અંતઃરેખ અક્ષર *config_tccdir_w32(અક્ષર *path)
{
    અક્ષર *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    જો (p > path)
        --p;
    *p = 0;
    પાછા path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
સ્થિર શૂન્ય tcc_add_systemdir(TCCState *s)
{
    અક્ષર buf[1000];
    GetSystemDirectoryA(buf, કદ buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(અચલ અક્ષર *f, અચલ અક્ષર *m) {
    પાછા fopen(f, m);
}
PUB_FUNC પૂર્ણાંક tcc_fclose(FILE *f) {
    પાછા fclose(f);
}
#endif
/********************************************************/

PUB_FUNC શૂન્ય tcc_enter_state(TCCState *s1)
{
    જો (s1->error_set_jmp_enabled)
        પાછા;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC શૂન્ય tcc_exit_state(TCCState *s1)
{
    જો (s1->error_set_jmp_enabled)
        પાછા;
    tcc_state = ખાલી;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC અક્ષર *pstrcpy(અક્ષર *buf, size_t buf_size, અચલ અક્ષર *s)
{
    અક્ષર *q, *q_end;
    પૂર્ણાંક c;

    જો (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        જ્યારે (q < q_end) {
            c = *s++;
            જો (c == '\0')
                તોડો;
            *q++ = c;
        }
        *q = '\0';
    }
    પાછા buf;
}

/* strcat and truncate. */
ST_FUNC અક્ષર *pstrcat(અક્ષર *buf, size_t buf_size, અચલ અક્ષર *s)
{
    size_t len;
    len = strlen(buf);
    જો (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    પાછા buf;
}

ST_FUNC અક્ષર *pstrncpy(અક્ષર *out, size_t buf_size, અચલ અક્ષર *s, size_t અંક)
{
    જો (અંક >= buf_size)
        અંક = buf_size - 1;
    memcpy(out, s, અંક);
    out[અંક] = '\0';
    પાછા out;
}

/* extract the basename of a file */
PUB_FUNC અક્ષર *tcc_basename(અચલ અક્ષર *name)
{
    અક્ષર *p = (અક્ષર *)strchr(name, 0);
    જ્યારે (p > name && !IS_DIRSEP(p[-1]))
        --p;
    પાછા p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC અક્ષર *tcc_fileextension (અચલ અક્ષર *name)
{
    અક્ષર *b = tcc_basename(name);
    અક્ષર *e = strrchr(b, '.');
    પાછા e ? e : strchr(b, 0);
}

ST_FUNC અક્ષર *tcc_load_text(પૂર્ણાંક fd)
{
    પૂર્ણાંક len = lseek(fd, 0, SEEK_END);
    અક્ષર *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    પાછા buf;
}

/* replace *pp by copy of 'str' or NULL */
સ્થિર શૂન્ય tcc_set_str(અક્ષર **pp, અચલ અક્ષર *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ખાલી;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
સ્થિર શૂન્ય tcc_concat_str(અક્ષર **pp, અચલ અક્ષર *str, પૂર્ણાંક sep)
{
    પૂર્ણાંક l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    જો (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef મુક્ત
#undef realloc

સ્થિર શૂન્ય *default_reallocator(શૂન્ય *ptr, unsigned long size)
{
    શૂન્ય *ptr1;
    જો (size == 0) {
        મુક્ત(ptr);
        ptr1 = ખાલી;
    }
    નહીંતર {
        ptr1 = realloc(ptr, size);
        જો (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    પાછા ptr1;
}

ST_FUNC શૂન્ય libc_free(શૂન્ય *ptr)
{
    મુક્ત(ptr);
}

/* defined to be not used */
#define મુક્ત(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
સ્થિર શૂન્ય *(*reallocator)(શૂન્ય*, unsigned long) = default_reallocator;

LIBTCCAPI શૂન્ય tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC શૂન્ય tcc_free(શૂન્ય *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC શૂન્ય *tcc_malloc(unsigned long size)
{
    પાછા reallocator(0, size);
}

PUB_FUNC શૂન્ય *tcc_realloc(શૂન્ય *ptr, unsigned long size)
{
    પાછા reallocator(ptr, size);
}

PUB_FUNC શૂન્ય *tcc_mallocz(unsigned long size)
{
    શૂન્ય *ptr;
    ptr = tcc_malloc(size);
    જો (size)
        memset(ptr, 0, size);
    પાછા ptr;
}

PUB_FUNC અક્ષર *tcc_strdup(અચલ અક્ષર *str)
{
    અક્ષર *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    પાછા ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned અક્ષર *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((અક્ષર *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((અક્ષર*)ptr - offsetof(mem_debug_header_t, magic3))

સંરચના mem_debug_header {
    unsigned magic1;
    unsigned size;
    સંરચના mem_debug_header *prev;
    સંરચના mem_debug_header *next;
    પૂર્ણાંક લીટી_અંક;
    અક્ષર file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned અક્ષર magic3[4];
};

પ્રકારવ્યાખ્યા સંરચના mem_debug_header mem_debug_header_t;

TCC_SEM(સ્થિર mem_sem);
સ્થિર mem_debug_header_t *mem_debug_chain;
સ્થિર unsigned mem_cur_size;
સ્થિર unsigned mem_max_size;
સ્થિર પૂર્ણાંક nb_states;

સ્થિર mem_debug_header_t *malloc_check(શૂન્ય *ptr, અચલ અક્ષર *સંદેશ)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    જો (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", સંદેશ);
        જો (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->લીટી_અંક);
        exit(1);
    }
    પાછા header;
}

PUB_FUNC શૂન્ય *tcc_malloc_debug(unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી)
{
    પૂર્ણાંક ofs;
    mem_debug_header_t *header;
    જો (!size)
        પાછા ખાલી;
    header = tcc_malloc(કદ(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->લીટી_અંક = લીટી;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = ખાલી;
    જો (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    જો (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    પાછા MEM_USER_PTR(header);
}

PUB_FUNC શૂન્ય tcc_free_debug(શૂન્ય *ptr)
{
    mem_debug_header_t *header;
    જો (!ptr)
        પાછા;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    જો (header->next)
        header->next->prev = header->prev;
    જો (header->prev)
        header->prev->next = header->next;
    જો (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC શૂન્ય *tcc_mallocz_debug(unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી)
{
    શૂન્ય *ptr;
    ptr = tcc_malloc_debug(size,file,લીટી);
    જો (size)
        memset(ptr, 0, size);
    પાછા ptr;
}

PUB_FUNC શૂન્ય *tcc_realloc_debug(શૂન્ય *ptr, unsigned long size, અચલ અક્ષર *file, પૂર્ણાંક લીટી)
{
    mem_debug_header_t *header;
    પૂર્ણાંક mem_debug_chain_update = 0;

    જો (!ptr)
        પાછા tcc_malloc_debug(size, file, લીટી);
    જો (!size) {
        tcc_free_debug(ptr);
        પાછા ખાલી;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, કદ(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    જો (header->next)
        header->next->prev = header;
    જો (header->prev)
        header->prev->next = header;
    જો (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    જો (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    પાછા MEM_USER_PTR(header);
}

PUB_FUNC અક્ષર *tcc_strdup_debug(અચલ અક્ષર *str, અચલ અક્ષર *file, પૂર્ણાંક લીટી)
{
    અક્ષર *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, લીટી);
    strcpy(ptr, str);
    પાછા ptr;
}

PUB_FUNC શૂન્ય tcc_memcheck(પૂર્ણાંક d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    જો (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        જ્યારે (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->લીટી_અંક, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = ખાલી;
#જો MEM_DEBUG-0 == 2
        exit(2);
#endif
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#define tcc_free(ptr)           tcc_free_debug(ptr)
#define tcc_malloc(size)        tcc_malloc_debug(size, __FILE__, __LINE__)
#define tcc_mallocz(size)       tcc_mallocz_debug(size, __FILE__, __LINE__)
#define tcc_realloc(ptr,size)   tcc_realloc_debug(ptr, size, __FILE__, __LINE__)
#define tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#endif /* MEM_DEBUG */

#ifdef _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#endif

/* for #pragma once */
ST_FUNC પૂર્ણાંક normalized_PATHCMP(અચલ અક્ષર *f1, અચલ અક્ષર *f2)
{
    અક્ષર *p1, *p2;
    પૂર્ણાંક ret = 1;
    જો (!!(p1 = realpath(f1, ખાલી))) {
        જો (!!(p2 = realpath(f2, ખાલી))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    પાછા ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC શૂન્ય dynarray_add(શૂન્ય *ptab, પૂર્ણાંક *nb_ptr, શૂન્ય *data)
{
    પૂર્ણાંક nb, nb_alloc;
    શૂન્ય **pp;

    nb = *nb_ptr;
    pp = *(શૂન્ય ***)ptab;
    /* every power of two we double array size */
    જો ((nb & (nb - 1)) == 0) {
        જો (!nb)
            nb_alloc = 1;
        નહીંતર
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * કદ(શૂન્ય *));
        *(શૂન્ય***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC શૂન્ય dynarray_reset(શૂન્ય *pp, પૂર્ણાંક *n)
{
    શૂન્ય **p;
    માટે (p = *(શૂન્ય***)pp; *n; ++p, --*n)
        જો (*p)
            tcc_free(*p);
    tcc_free(*(શૂન્ય**)pp);
    *(શૂન્ય**)pp = ખાલી;
}

સ્થિર શૂન્ય dynarray_split(અક્ષર ***argv, પૂર્ણાંક *argc, અચલ અક્ષર *p, પૂર્ણાંક sep)
{
    પૂર્ણાંક qot, c;
    CString str;
    માટે(;;) {
        જ્યારે (c = (unsigned અક્ષર)*p, c <= ' ' && c != '\0')
            ++p;
        જો (c == '\0')
            તોડો;
        cstr_new(&str);
        qot = 0;
        કરો {
            ++p;
            જો (sep) { /* e.g. to split -Wl,-opt,arg */
                જો (c == sep)
                    તોડો;
            } નહીંતર {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                જો (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } નહીંતર જો (c == '"') {
                    qot ^= 1;
                    ચાલુ;
                } નહીંતર જો (c <= ' ' && !qot) {
                    તોડો;
                }
            }
            cstr_ccat(&str, c);
        } જ્યારે (c = (unsigned અક્ષર)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

સ્થિર શૂન્ય tcc_split_path(TCCState *s, શૂન્ય *p_ary, પૂર્ણાંક *p_nb_ary, અચલ અક્ષર *in)
{
    અચલ અક્ષર *p;
    કરો {
        પૂર્ણાંક c;
        CString str;

        cstr_new(&str);
        માટે (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            જો (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                જો (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                જો (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                જો (c == 'f' && file) {
                    /* substitute current file's dir */
                    અચલ અક્ષર *f = file->true_filename;
                    અચલ અક્ષર *b = tcc_basename(f);
                    જો (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    નહીંતર
                        cstr_cat(&str, ".", 1);
                }
            } નહીંતર {
                cstr_ccat(&str, c);
            }
        }
        જો (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } જ્યારે (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ગણના { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

સ્થિર શૂન્ય error1(પૂર્ણાંક mode, અચલ અક્ષર *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    પૂર્ણાંક લીટી = 0;

    tcc_exit_state(s1);

    જો (mode == ERROR_WARN) {
        જો (s1->warn_error)
            mode = ERROR_ERROR;
        જો (s1->warn_અંક) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            પૂર્ણાંક wopt = *(&s1->warn_none + s1->warn_અંક);
            s1->warn_અંક = 0;
            જો (0 == (wopt & WARN_ON))
                પાછા;
            જો (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            જો (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        જો (s1->warn_none)
            પાછા;
    }

    cstr_new(&cs);
    જો (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        લીટી = va_arg(ap, પૂર્ણાંક), fmt += 3;
    f = ખાલી;
    જો (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        માટે (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    જો (f) {
        માટે(pf = s1->include_ઢગલો; pf < s1->include_ઢગલો_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->લીટી_અંક - 1);
        જો (0 == લીટી)
            લીટી = f->લીટી_અંક - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, લીટી);
    } નહીંતર જો (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } નહીંતર {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    જો (pp_પદાવલિ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    નહીંતર
        cstr_vprintf(&cs, fmt, ap);
    જો (!s1->error_func) {
        /* default case: stderr */
        જો (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (અક્ષર*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } નહીંતર {
        s1->error_func(s1->error_opaque, (અક્ષર*)cs.data);
    }
    cstr_free(&cs);
    જો (mode != ERROR_WARN)
        s1->nb_errors++;
    જો (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        જ્યારે (nb_stk_data)
            tcc_free(*(શૂન્ય**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI શૂન્ય tcc_set_error_func(TCCState *s, શૂન્ય *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC પૂર્ણાંક _tcc_error_noabort(અચલ અક્ષર *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    પાછા -1;
}

#undef _tcc_error
PUB_FUNC શૂન્ય _tcc_error(અચલ અક્ષર *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC શૂન્ય _tcc_warning(અચલ અક્ષર *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC શૂન્ય tcc_open_bf(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક initlen)
{
    BufferedFile *bf;
    પૂર્ણાંક buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(કદ(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, કદ(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->લીટી_અંક = 1;
    bf->ifdef_ઢગલો_ptr = s1->ifdef_ઢગલો_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC શૂન્ય tcc_close(શૂન્ય)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    જો (bf->fd > 0) {
        close(bf->fd);
        total_લીટીઓ += bf->લીટી_અંક - 1;
    }
    જો (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

સ્થિર પૂર્ણાંક _tcc_open(TCCState *s1, અચલ અક્ષર *filename)
{
    પૂર્ણાંક fd;
    જો (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    નહીંતર
        fd = open(filename, O_RDONLY | O_દ્વિઅંકી_2);
    જો ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (પૂર્ણાંક)(s1->include_ઢગલો_ptr - s1->include_ઢગલો), "", filename);
    પાછા fd;
}

ST_FUNC પૂર્ણાંક tcc_open(TCCState *s1, અચલ અક્ષર *filename)
{
    પૂર્ણાંક fd = _tcc_open(s1, filename);
    જો (fd < 0)
        પાછા -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    પાછા 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
સ્થિર પૂર્ણાંક tcc_compile(TCCState *s1, પૂર્ણાંક filetype, અચલ અક્ષર *str, પૂર્ણાંક fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    જો (setjmp(s1->error_jmp_buf) == 0) {

        જો (fd == -1) {
            પૂર્ણાંક len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } નહીંતર {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        જો (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } નહીંતર {
            tccelf_begin_file(s1);
            જો (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } નહીંતર {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    પાછા s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI પૂર્ણાંક tcc_compile_string(TCCState *s, અચલ અક્ષર *str)
{
    પાછા tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI શૂન્ય tcc_define_પ્રતીક(TCCState *s1, અચલ અક્ષર *sym, અચલ અક્ષર *કિંમત)
{
    અચલ અક્ષર *eq;
    જો (ખાલી == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    જો (ખાલી == કિંમત)
        કિંમત = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (પૂર્ણાંક)(eq-sym), sym, કિંમત);
}

/* undefine a preprocessor symbol */
LIBTCCAPI શૂન્ય tcc_undefine_પ્રતીક(TCCState *s1, અચલ અક્ષર *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(શૂન્ય)
{
    TCCState *s;

    s = tcc_mallocz(કદ(TCCState));
#ifdef MEM_DEBUG
    tcc_memcheck(1);
#endif

#undef gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_in_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#ifdef CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#endif
#ifdef TCC_TARGET_I386
    s->seg_size = 32;
#endif
    /* enable this if you want symbols with leading underscore on windows: */
#જો defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#જો defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ઢગલો_ptr = s->include_ઢગલો;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    પાછા s;
}

LIBTCCAPI શૂન્ય tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_path);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_પ્રતીક);
    tcc_free(s1->fini_પ્રતીક);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#જો defined TCC_TARGET_MACHO
    tcc_free(s1->install_name);
#endif
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#ifdef TCC_IS_NATIVE
    /* free runtime memory */
    tcc_run_free(s1);
#endif
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#ifdef MEM_DEBUG
    tcc_memcheck(-1);
#endif
}

LIBTCCAPI પૂર્ણાંક tcc_set_output_type(TCCState *s, પૂર્ણાંક output_type)
{
#ifdef CONFIG_TCC_PIE
    જો (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    જો (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    જો (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        પાછા 0;
    }

    /* add sections */
    tccelf_new(s);

    જો (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        પાછા 0;
    }

    જો (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#અથવાજો defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#નહીંતર
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    જો (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    પાછા s->nb_errors ? -1 : 0;
}

LIBTCCAPI પૂર્ણાંક tcc_add_include_path(TCCState *s, અચલ અક્ષર *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    પાછા 0;
}

LIBTCCAPI પૂર્ણાંક tcc_add_sysinclude_path(TCCState *s, અચલ અક્ષર *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    પાછા 0;
}

LIBTCCAPI પૂર્ણાંક tcc_add_library_path(TCCState *s, અચલ અક્ષર *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    પાછા 0;
}

LIBTCCAPI શૂન્ય tcc_set_lib_path(TCCState *s, અચલ અક્ષર *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, અચલ અક્ષર *dllname, પૂર્ણાંક level)
{
    DLLReference *ref = ખાલી;
    પૂર્ણાંક i;
    માટે (i = 0; i < s1->nb_loaded_dlls; i++)
        જો (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            તોડો;
        }
    જો (level == -1)
        પાછા ref;
    જો (ref) {
        જો (level < ref->level)
            ref->level = level;
        ref->found = 1;
        પાછા ref;
    }
    ref = tcc_mallocz(કદ(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    પાછા ref;
}

સ્થિર પૂર્ણાંક tcc_add_દ્વિઅંકી(TCCState *s1, પૂર્ણાંક flags, અચલ અક્ષર *filename, પૂર્ણાંક fd)
{
    ElfW(Ehdr) ehdr;
    પૂર્ણાંક obj_type;
    અચલ અક્ષર *saved_filename = s1->current_filename;
    પૂર્ણાંક ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    પસંદગી (obj_type) {

    સ્થિતિ AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        તોડો;

    સ્થિતિ AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        તોડો;

#જો defined TCC_TARGET_UNIX
    સ્થિતિ AFF_BINTYPE_DYN:
        જો (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            શૂન્ય* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            જો (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            નહીંતર
                ret = FILE_NOT_RECOGNIZED;
#endif
        } નહીંતર
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        તોડો;

    મૂળભૂત:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        તોડો;

#અથવાજો defined TCC_TARGET_MACHO
    સ્થિતિ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        જો (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            શૂન્ય* dl;
            અચલ અક્ષર* soname = filename;
            અક્ષર *tmp = 0;
            જો (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                જો (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            જો (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            નહીંતર
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } નહીંતર જો (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } નહીંતર {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        જો (ret)
            ret = FILE_NOT_RECOGNIZED;
        તોડો;

    મૂળભૂત:
    {
        અચલ અક્ષર *ext = tcc_fileextension(filename);
        જો (!strcmp(ext, ".tbd"))
            જાઓ case_dyn_or_tbd;
        જો (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            જાઓ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        તોડો;
    }

#અથવાજો defined TCC_TARGET_PE
    મૂળભૂત:
        જો (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        તોડો;
#endif

#ifdef TCC_TARGET_COFF
    સ્થિતિ AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        તોડો;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    જો (ret == FILE_NOT_RECOGNIZED)
        પાછા tcc_error_noabort("%s: unrecognized file type", filename);
    પાછા ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#જો defined TARGETOS_OpenBSD && !defined _WIN32
#અન્તર્ભાવ <glob.h>
સ્થિર પૂર્ણાંક tcc_glob_so(TCCState *s1, અચલ અક્ષર *pattern, અક્ષર *buf, પૂર્ણાંક size)
{
    અચલ અક્ષર *star;
    glob_t g;
    અક્ષર *p;
    પૂર્ણાંક i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    જો (!star || glob(pattern, 0, ખાલી, &g))
        પાછા -1;
    માટે (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        જો (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            ચાલુ;
        જો ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    પાછા v;
}
#endif

સ્થિર પૂર્ણાંક guess_filetype(અચલ અક્ષર *filename)
{
    પૂર્ણાંક filetype = 0;
    જો (1) {
        /* use a file extension to detect a filetype */
        અચલ અક્ષર *ext = tcc_fileextension(filename);
        જો (ext[0]) {
            ext++;
            જો (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            નહીંતર જો (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            નહીંતર જો (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            નહીંતર
                filetype |= AFF_TYPE_BIN;
        } નહીંતર {
            filetype = AFF_TYPE_C;
        }
    }
    પાછા filetype;
}

ST_FUNC પૂર્ણાંક tcc_add_file_internal(TCCState *s1, અચલ અક્ષર *filename, પૂર્ણાંક flags)
{
    પૂર્ણાંક fd;

#જો defined TARGETOS_OpenBSD && !defined _WIN32
    અક્ષર buf[1024];
    જો (tcc_glob_so(s1, filename, buf, કદ buf) >= 0)
        filename = buf;
#endif

    જો (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    જો (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        પાછા 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    જો (fd < 0) {
        જો (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        પાછા FILE_NOT_FOUND;
    }

    જો (flags & AFF_TYPE_BIN)
        પાછા tcc_add_દ્વિઅંકી(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    પાછા tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI પૂર્ણાંક tcc_add_file(TCCState *s, અચલ અક્ષર *filename)
{
    પાછા tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

સ્થિર પૂર્ણાંક tcc_add_library_internal(TCCState *s1, અચલ અક્ષર *fmt,
    અચલ અક્ષર *filename, પૂર્ણાંક flags, અક્ષર **paths, પૂર્ણાંક nb_paths)
{
    અક્ષર buf[1024];
    પૂર્ણાંક i, ret;

    માટે(i = 0; i < nb_paths; i++) {
        snprintf(buf, કદ(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        જો (ret != FILE_NOT_FOUND)
            પાછા ret;
    }
    જો (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    પાછા FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC પૂર્ણાંક tcc_add_dll(TCCState *s, અચલ અક્ષર *filename, પૂર્ણાંક flags)
{
    પાછા tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC પૂર્ણાંક tcc_add_support(TCCState *s1, અચલ અક્ષર *filename)
{
    અક્ષર buf[100];
    જો (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    પાછા tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC પૂર્ણાંક tcc_add_crt(TCCState *s1, અચલ અક્ષર *filename)
{
    પાછા tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI પૂર્ણાંક tcc_add_library(TCCState *s, અચલ અક્ષર *libraryname)
{
    સ્થિર અચલ અક્ષર * અચલ libs[] = {
#જો defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#અથવાજો defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#અથવાજો defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#નહીંતર
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        ખાલી
    };
    પૂર્ણાંક flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    જો (*libraryname == ':') {
        libraryname++;
    } નહીંતર {
        અચલ અક્ષર * અચલ *pp = libs;
        જો (s->static_link)
            pp += કદ(libs) / કદ(*libs) - 2; /* only "%s/lib%s.a" */
        જ્યારે (*pp) {
            પૂર્ણાંક ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            જો (ret != FILE_NOT_FOUND)
                પાછા ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    પાછા tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC શૂન્ય tcc_add_pragma_libs(TCCState *s1)
{
    પૂર્ણાંક i;
    માટે (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

સ્થિર પૂર્ણાંક strstart(અચલ અક્ષર *val, અચલ અક્ષર **str)
{
    અચલ અક્ષર *p, *q;
    p = *str;
    q = val;
    જ્યારે (*q) {
        જો (*p != *q)
            પાછા 0;
        p++;
        q++;
    }
    *str = p;
    પાછા 1;
}

સંરચના lopt {
    TCCState *s;
    અચલ અક્ષર *opt, *arg;
    પૂર્ણાંક match;
};

/* match linker option */
સ્થિર પૂર્ણાંક link_option(સંરચના lopt *o, અચલ અક્ષર *q)
{
    અચલ અક્ષર *p;
    પૂર્ણાંક c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    જો (*p++ != '-')
        પાછા 0;
    જો (*p == '-')
        p++;
    r = 1;
    જો (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        જો (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        નહીંતર જો (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    જ્યારે ((c = *q) == *p) {
        જો (c == '\0')
            જાઓ succ; /* -Wl,-opt */
        ++p;
        જો (c == '=')
            જાઓ succ; /* -Wl,-opt=arg */
        ++q;
    }
    જો (*p == '\0') {
        જો (c == '|')
            જાઓ succ;
        જો (c == '=' || c == ':') {
            જો (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                જાઓ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            પાછા 0;
        }
    } નહીંતર જો (c == ':')
        જાઓ succ; /* -Wl,-Iarg */
    જ્યારે (*q)
        જો (*q++ == '|')
            જાઓ redo;
    પાછા 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    પાછા r;
}

સ્થિર શૂન્ય args_parser_add_file(TCCState *s, અચલ અક્ષર* filename, પૂર્ણાંક filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
સ્થિર પૂર્ણાંક tcc_set_linker(TCCState *s, અચલ અક્ષર *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    જ્યારે (s->link_optind < s->link_argc) {
        અક્ષર *end = ખાલી;
        પૂર્ણાંક ignoring = 0;
        સંરચના lopt o = {0};
        પૂર્ણાંક r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        જો (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } નહીંતર જો (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } નહીંતર જો (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } નહીંતર જો (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } નહીંતર જો (link_option(&o, "init=")) {
            tcc_set_str(&s->init_પ્રતીક, o.arg);
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_પ્રતીક, o.arg);
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "oformat=")) {
#જો defined TCC_TARGET_PE
            જો (0 == strncmp("pe-", o.arg, 3))
#અથવાજો PTR_SIZE == 8
            જો (0 == strncmp("elf64-", o.arg, 6))
#નહીંતર
            જો (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            નહીંતર જો (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_દ્વિઅંકી;
#જો defined TCC_TARGET_COFF
            નહીંતર જો (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            નહીંતર
                જાઓ err;
        } નહીંતર જો (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } નહીંતર જો (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } નહીંતર જો (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } નહીંતર જો (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } નહીંતર જો (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } નહીંતર જો (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } નહીંતર જો (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } નહીંતર જો (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } નહીંતર જો (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } નહીંતર જો (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } નહીંતર જો (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } નહીંતર જો (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } નહીંતર જો (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } નહીંતર જો (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } નહીંતર જો (link_option(&o, "stack=")) {
            s->pe_ઢગલો_size = strtoul(o.arg, &end, 10);
        } નહીંતર જો (link_option(&o, "subsystem=")) {
            જો (pe_setsubsy(s, o.arg) < 0)
                જાઓ err;
#અથવાજો defined TCC_TARGET_MACHO
        } નહીંતર જો (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } નહીંતર જો (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } નહીંતર જો (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } નહીંતર જો (link_option(&o, "as-needed")) {
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "O")) {
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "z=")) {
            ignoring = 1;
        } નહીંતર જો (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } નહીંતર જો (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } નહીંતર જો (o.match) {
            પાછા 0; /* expecting argument with next '-Wl,' */
        } નહીંતર {
    err:
            પાછા tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        જો (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    પાછા 0;
}

પ્રકારવ્યાખ્યા સંરચના TCCOption {
    અચલ અક્ષર *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

ગણના {
    TCC_OPTION_ignored = 0,
    TCC_OPTION_HELP,
    TCC_OPTION_HELP2,
    TCC_OPTION_v,
    TCC_OPTION_I,
    TCC_OPTION_D,
    TCC_OPTION_U,
    TCC_OPTION_P,
    TCC_OPTION_L,
    TCC_OPTION_B,
    TCC_OPTION_l,
    TCC_OPTION_bench,
    TCC_OPTION_bt,
    TCC_OPTION_b,
    TCC_OPTION_g,
    TCC_OPTION_c,
    TCC_OPTION_dumpmachine,
    TCC_OPTION_dumpversion,
    TCC_OPTION_d,
    TCC_OPTION_static,
    TCC_OPTION_std,
    TCC_OPTION_shared,
    TCC_OPTION_soname,
    TCC_OPTION_o,
    TCC_OPTION_r,
    TCC_OPTION_Wl,
    TCC_OPTION_Wp,
    TCC_OPTION_W,
    TCC_OPTION_O,
    TCC_OPTION_mfloat_abi,
    TCC_OPTION_m,
    TCC_OPTION_f,
    TCC_OPTION_isystem,
    TCC_OPTION_iwithprefix,
    TCC_OPTION_include,
    TCC_OPTION_nostdinc,
    TCC_OPTION_nostdlib,
    TCC_OPTION_print_શોધ_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_run,
    TCC_OPTION_rstdin,
    TCC_OPTION_w,
    TCC_OPTION_E,
    TCC_OPTION_M,
    TCC_OPTION_MD,
    TCC_OPTION_MF,
    TCC_OPTION_MM,
    TCC_OPTION_MMD,
    TCC_OPTION_MP,
    TCC_OPTION_x,
    TCC_OPTION_ar,
    TCC_OPTION_impdef,
    /* macho */
    TCC_OPTION_dynamiclib,
    TCC_OPTION_flat_namespace,
    TCC_OPTION_two_levelnamespace,
    TCC_OPTION_undefined,
    TCC_OPTION_install_name,
    TCC_OPTION_compatibility_version ,
    TCC_OPTION_current_version,
};

#define TCC_OPTION_HAS_ARG 0x0001
#define TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

સ્થિર અચલ TCCOption tcc_options[] = {
    { "h", TCC_OPTION_HELP, 0 },
    { "-help", TCC_OPTION_HELP, 0 },
    { "?", TCC_OPTION_HELP, 0 },
    { "hh", TCC_OPTION_HELP2, 0 },
    { "v", TCC_OPTION_v, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "-version", TCC_OPTION_v, 0 }, /* handle as verbose, also prints version*/
    { "I", TCC_OPTION_I, TCC_OPTION_HAS_ARG },
    { "D", TCC_OPTION_D, TCC_OPTION_HAS_ARG },
    { "U", TCC_OPTION_U, TCC_OPTION_HAS_ARG },
    { "P", TCC_OPTION_P, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "L", TCC_OPTION_L, TCC_OPTION_HAS_ARG },
    { "B", TCC_OPTION_B, TCC_OPTION_HAS_ARG },
    { "l", TCC_OPTION_l, TCC_OPTION_HAS_ARG },
    { "bench", TCC_OPTION_bench, 0 },
#ifdef CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#endif
#ifdef CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#endif
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ifdef TCC_TARGET_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_version, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_version, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#endif
    { "c", TCC_OPTION_c, 0 },
    { "dumpmachine", TCC_OPTION_dumpmachine, 0},
    { "dumpversion", TCC_OPTION_dumpversion, 0},
    { "d", TCC_OPTION_d, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "static", TCC_OPTION_static, 0 },
    { "std", TCC_OPTION_std, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "shared", TCC_OPTION_shared, 0 },
    { "soname", TCC_OPTION_soname, TCC_OPTION_HAS_ARG },
    { "o", TCC_OPTION_o, TCC_OPTION_HAS_ARG },
    { "pthread", TCC_OPTION_pthread, 0},
    { "run", TCC_OPTION_run, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ifdef TCC_TARGET_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#endif
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_શોધ_dirs, 0 },
    { "w", TCC_OPTION_w, 0 },
    { "E", TCC_OPTION_E, 0},
    { "M", TCC_OPTION_M, 0},
    { "MM", TCC_OPTION_MM, 0},
    { "MD", TCC_OPTION_MD, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "MMD", TCC_OPTION_MMD, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "MF", TCC_OPTION_MF, TCC_OPTION_HAS_ARG },
    { "MP", TCC_OPTION_MP, 0},
    { "x", TCC_OPTION_x, TCC_OPTION_HAS_ARG },
    /* tcctools */
    { "ar", TCC_OPTION_ar, 0},
#ifdef TCC_TARGET_PE
    { "impdef", TCC_OPTION_impdef, 0},
#endif
    /* ignored (silently, except after -Wunsupported) */
    { "arch", 0, TCC_OPTION_HAS_ARG},
    { "C", 0, 0 },
    { "-param", 0, TCC_OPTION_HAS_ARG },
    { "pedantic", 0, 0 },
    { "pie", 0, 0 },
    { "no-pie", 0, 0 },
    { "pipe", 0, 0 },
    { "s", 0, 0 },
    { "traditional", 0, 0 },
    { ખાલી, 0, 0 },
};

પ્રકારવ્યાખ્યા સંરચના FlagDef {
    uint16_t offset;
    uint16_t flags;
    અચલ અક્ષર *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

સ્થિર અચલ FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ખાલી }
};

સ્થિર અચલ FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_in_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, reverse_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, ખાલી }
};

સ્થિર અચલ FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, ખાલી }
};

સ્થિર પૂર્ણાંક set_flag(TCCState *s, અચલ FlagDef *flags, અચલ અક્ષર *name)
{
    પૂર્ણાંક કિંમત, mask, ret;
    અચલ FlagDef *p;
    અચલ અક્ષર *r;
    unsigned અક્ષર *f;

    r = name, કિંમત = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    જો ((flags->flags & WD_ALL) && strstart("error=", &r))
        કિંમત = કિંમત ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    માટે (ret = -1, p = flags; p->name; ++p) {
        જો (ret) {
            જો (strcmp(r, p->name))
                ચાલુ;
        } નહીંતર {
            જો (0 == (p->flags & WD_ALL))
                ચાલુ;
        }

        f = (unsigned અક્ષર *)s + p->offset;
        *f = (*f & mask) | (કિંમત ^ !!(p->flags & FD_INVERT));

        જો (ret) {
            ret = 0;
            જો (strcmp(r, "all"))
                તોડો;
        }
    }
    પાછા ret;
}

સ્થિર અચલ અક્ષર dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#અથવાજો defined TCC_TARGET_X86_64
    "x86_64-pc"
#અથવાજો defined TCC_TARGET_C67
    "c67"
#અથવાજો defined TCC_TARGET_ARM
    "arm"
#અથવાજો defined TCC_TARGET_ARM64
    "aarch64"
#અથવાજો defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#અથવાજો defined(TCC_TARGET_MACHO)
    "apple-darwin"
#અથવાજો TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#અથવાજો TARGETOS_OpenBSD
    "openbsd"
#અથવાજો TARGETOS_NetBSD
    "netbsd"
#અથવાજો CONFIG_TCC_MUSL
    "linux-musl"
#નહીંતર
    "linux-gnu"
#endif
;

#જો defined TCC_TARGET_MACHO
સ્થિર uint32_t parse_version(TCCState *s1, અચલ અક્ષર *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    અક્ષર* last;

    a = strtoul(version, &last, 10);
    જો (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        જો (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    જો (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    પાછા (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
સ્થિર શૂન્ય ઉમેરો_args(TCCState *s1, અક્ષર ***pargv, પૂર્ણાંક *pargc, પૂર્ણાંક optind, અચલ અક્ષર *p, પૂર્ણાંક sep)
{
    પૂર્ણાંક argc = 0;
    અક્ષર **argv = ખાલી;
    પૂર્ણાંક i;
    માટે (i = 0; i < *pargc; ++i)
        જો (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        નહીંતર
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

સ્થિર શૂન્ય args_parser_add_file(TCCState *s, અચલ અક્ષર* filename, પૂર્ણાંક filetype)
{
    સંરચના filespec *f = tcc_malloc(કદ *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    જો (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC પૂર્ણાંક tcc_parse_args(TCCState *s, પૂર્ણાંક *pargc, અક્ષર ***pargv)
{
    TCCState *s1 = s;
    અચલ TCCOption *popt;
    અચલ અક્ષર *optarg, *r;
    અચલ અક્ષર *run = ખાલી;
    પૂર્ણાંક optind = 1, empty = 1, x;
    અક્ષર **argv = *pargv;
    પૂર્ણાંક argc = *pargc;

    s->link_optind = s->link_argc;

    જ્યારે (optind < argc) {
        r = argv[optind];
        જો (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            પૂર્ણાંક fd; અક્ષર *p;
            fd = open(++r, O_RDONLY | O_દ્વિઅંકી_2);
            જો (fd < 0)
                પાછા tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            ઉમેરો_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ચાલુ;
        }
        optind++;
        જો (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            જો (run)
                તોડો;
            ચાલુ;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        જો (r[1] == '-' && r[2] == '\0')
            જાઓ dorun;

        /* find option in table */
        માટે(popt = tcc_options; ; ++popt) {
            અચલ અક્ષર *p1 = popt->name;
            અચલ અક્ષર *r1 = r + 1;
            જો (p1 == ખાલી)
                પાછા tcc_error_noabort("invalid option -- '%s'", r);
            જો (!strstart(p1, &r1))
                ચાલુ;
            optarg = r1;
            જો (popt->flags & TCC_OPTION_HAS_ARG) {
                જો (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    જો (optind >= argc)
                        પાછા tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } નહીંતર જો (*r1 != '\0')
                ચાલુ;
            તોડો;
        }

        પસંદગી(popt->index) {
        સ્થિતિ TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_D:
            tcc_define_પ્રતીક(s, optarg, ખાલી);
            તોડો;
        સ્થિતિ TCC_OPTION_U:
            tcc_undefine_પ્રતીક(s, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            ચાલુ;
        સ્થિતિ TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            તોડો;
        સ્થિતિ TCC_OPTION_pthread:
            s->option_pthread = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_bench:
            s->do_bench = 1;
            તોડો;
#ifdef CONFIG_TCC_BACKTRACE
        સ્થિતિ TCC_OPTION_bt:
            s->rt_અંક_callers = atoi(optarg); /* zero = default (6) */
            જાઓ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            જો (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            તોડો;
#ifdef CONFIG_TCC_BCHECK
        સ્થિતિ TCC_OPTION_b:
            s->do_bounds_check = 1;
            જાઓ enable_backtrace;
#endif
#endif
        સ્થિતિ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            જો (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } નહીંતર જો (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } નહીંતર જો (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                જાઓ g_redo;
#ifdef TCC_TARGET_PE
            } નહીંતર જો (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            તોડો;
        સ્થિતિ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            જો (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            તોડો;
        સ્થિતિ TCC_OPTION_d:
            જો (*optarg == 'D')
                s->dflag = 3;
            નહીંતર જો (*optarg == 'M')
                s->dflag = 7;
            નહીંતર જો (*optarg == 't')
                s->dflag = 16;
            નહીંતર જો (isnum(*optarg))
                g_debug |= atoi(optarg);
            નહીંતર
                જાઓ unsupported_option;
            તોડો;
        સ્થિતિ TCC_OPTION_static:
            s->static_link = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_std:
            જો (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            તોડો;
        સ્થિતિ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            જાઓ set_output_type;
        સ્થિતિ TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_o:
            જો (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            જાઓ set_output_type;
        સ્થિતિ TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            જાઓ set_output_type;
#નહીંતર
            પાછા tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        સ્થિતિ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            તોડો;
#endif
        સ્થિતિ TCC_OPTION_v:
            કરો ++s->verbose; જ્યારે (*optarg++ == 'v');
            ચાલુ;
        સ્થિતિ TCC_OPTION_f:
            જો (set_flag(s, options_f, optarg) < 0)
                જાઓ unsupported_option;
            તોડો;
#ifdef TCC_TARGET_ARM
        સ્થિતિ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            જો (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } નહીંતર જો (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            નહીંતર
                પાછા tcc_error_noabort("unsupported float abi '%s'", optarg);
            ચાલુ;
#endif
        સ્થિતિ TCC_OPTION_m:
            જો (set_flag(s, options_m, optarg) < 0) {
                જો (x = atoi(optarg), x != 32 && x != 64)
                    જાઓ unsupported_option;
                જો (PTR_SIZE != x/8)
                    પાછા x;
                ચાલુ;
            }
            તોડો;
        સ્થિતિ TCC_OPTION_W:
            જો (optarg[0] && set_flag(s, options_W, optarg) < 0)
                જાઓ unsupported_option;
            તોડો;
        સ્થિતિ TCC_OPTION_w:
            s->warn_none = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            તોડો;
        સ્થિતિ TCC_OPTION_Wl:
            જો (tcc_set_linker(s, optarg) < 0)
                પાછા -1;
            તોડો;
        સ્થિતિ TCC_OPTION_Wp:
            જો (argv[0]) /* not with tcc_set_options() */
                ઉમેરો_args(s, &argv, &argc, --optind, optarg, ',');
            તોડો;
        સ્થિતિ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            જાઓ set_output_type;
        સ્થિતિ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            તોડો;

        સ્થિતિ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        સ્થિતિ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            જો (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            તોડો;
        સ્થિતિ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        સ્થિતિ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            જો (*optarg != ',')
                તોડો;
            ++optarg;
            // fall through
        સ્થિતિ TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            તોડો;

        સ્થિતિ TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        સ્થિતિ TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        સ્થિતિ TCC_OPTION_x:
            x = 0;
            જો (*optarg == 'c')
                x = AFF_TYPE_C;
            નહીંતર જો (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            નહીંતર જો (*optarg == 'b')
                x = AFF_TYPE_BIN;
            નહીંતર જો (*optarg == 'n')
                x = AFF_TYPE_NONE;
            નહીંતર
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            તોડો;
        સ્થિતિ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            તોડો;
#જો defined TCC_TARGET_MACHO
        સ્થિતિ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            જાઓ set_output_type;
        સ્થિતિ TCC_OPTION_flat_namespace:
	     તોડો;
        સ્થિતિ TCC_OPTION_two_levelnamespace:
	     તોડો;
        સ્થિતિ TCC_OPTION_undefined:
	     તોડો;
        સ્થિતિ TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            તોડો;
        સ્થિતિ TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            તોડો;
#endif
        સ્થિતિ TCC_OPTION_HELP:
            x = OPT_HELP;
            જાઓ extra_action;
        સ્થિતિ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            જાઓ extra_action;
        સ્થિતિ TCC_OPTION_print_શોધ_dirs:
            x = OPT_PRINT_DIRS;
            જાઓ extra_action;
        સ્થિતિ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            જાઓ extra_action;
        સ્થિતિ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            જો (ખાલી == argv[0]) /* from tcc_set_options() */
                પાછા -1;
            જો (!empty && x)
                પાછા tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            પાછા x;
        મૂળભૂત:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            તોડો;
        }
        empty = 0;
    }
    જો (s->link_optind < s->link_argc)
        પાછા tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    જો (run) {
        જો (*run && tcc_set_options(s, run) < 0)
            પાછા -1;
        x = 0, r = 0;
        જાઓ extra_action;
    }
    જો (!empty)
        પાછા 0;
    જો (s->verbose == 2)
        પાછા OPT_PRINT_DIRS;
    જો (s->verbose)
        પાછા OPT_V;
    પાછા OPT_HELP;
}

LIBTCCAPI પૂર્ણાંક tcc_set_options(TCCState *s, અચલ અક્ષર *r)
{
    અક્ષર **argv = ખાલી;
    પૂર્ણાંક argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    પાછા ret;
}

PUB_FUNC શૂન્ય tcc_print_stats(TCCState *s1, unsigned total_time)
{
    જો (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_લીટીઓ, total_bytes,
           (દ્વિગુણ)total_time/1000,
           (unsigned)total_લીટીઓ*1000/total_time,
           (દ્વિગુણ)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    જો (s1->run_size) {
        Section *s = s1->symtab;
        unsigned ms = s->data_offset + s->link->data_offset + s->hash->data_offset;
        unsigned rs = s1->run_size;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_size - rs - ms);
    }
#endif
    fprintf(stderr, " %d max (bytes)\n", mem_max_size);
#endif
}
