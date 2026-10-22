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

#എങ്കിൽ ONE_SOURCE
#അന്തര്ഭാവ "tccpp.c"
#അന്തര്ഭാവ "tccgen.c"
#അന്തര്ഭാവ "tccdbg.c"
#അന്തര്ഭാവ "tccasm.c"
#അന്തര്ഭാവ "tccelf.c"
#അന്തര്ഭാവ "tccrun.c"
#ifdef TCC_TARGET_I386
#അന്തര്ഭാവ "i386-gen.c"
#അന്തര്ഭാവ "i386-link.c"
#അന്തര്ഭാവ "i386-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM)
#അന്തര്ഭാവ "arm-gen.c"
#അന്തര്ഭാവ "arm-link.c"
#അന്തര്ഭാവ "arm-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_ARM64)
#അന്തര്ഭാവ "arm64-gen.c"
#അന്തര്ഭാവ "arm64-link.c"
#അന്തര്ഭാവ "arm64-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_C67)
#അന്തര്ഭാവ "c67-gen.c"
#അന്തര്ഭാവ "c67-link.c"
#അന്തര്ഭാവ "tcccoff.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_X86_64)
#അന്തര്ഭാവ "x86_64-gen.c"
#അന്തര്ഭാവ "x86_64-link.c"
#അന്തര്ഭാവ "i386-asm.c"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_RISCV64)
#അന്തര്ഭാവ "riscv64-gen.c"
#അന്തര്ഭാവ "riscv64-link.c"
#അന്തര്ഭാവ "riscv64-asm.c"
#അല്ലെങ്കിൽ
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#അന്തര്ഭാവ "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#അന്തര്ഭാവ "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#അന്തര്ഭാവ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA ഘടന TCCState *tcc_state;
TCC_SEM(സ്ഥിതം tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA ശൂന്യം** stk_data;
ST_DATA പൂർണ്ണസംഖ്യ nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA പൂർണ്ണസംഖ്യ g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC അക്ഷരം *normalize_slashes(അക്ഷരം *path)
{
    അക്ഷരം *p;
    വേണ്ടി (p = path; *p; ++p)
        എങ്കിൽ (*p == '\\')
            *p = '/';
    തിരികെ path;
}

#എങ്കിൽ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
സ്ഥിതം HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    എങ്കിൽ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    തിരികെ TRUE;
}
#അല്ലെങ്കിൽ
#define tcc_module ശൂന്യ /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
സ്ഥിതം വരിയിൽ അക്ഷരം *config_tccdir_w32(അക്ഷരം *path)
{
    അക്ഷരം *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    എങ്കിൽ (p > path)
        --p;
    *p = 0;
    തിരികെ path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
സ്ഥിതം ശൂന്യം tcc_add_systemdir(TCCState *s)
{
    അക്ഷരം buf[1000];
    GetSystemDirectoryA(buf, വലുപ്പം buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(സ്ഥിരം അക്ഷരം *f, സ്ഥിരം അക്ഷരം *m) {
    തിരികെ fopen(f, m);
}
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_fclose(FILE *f) {
    തിരികെ fclose(f);
}
#endif
/********************************************************/

PUB_FUNC ശൂന്യം tcc_enter_state(TCCState *s1)
{
    എങ്കിൽ (s1->error_set_jmp_enabled)
        തിരികെ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC ശൂന്യം tcc_exit_state(TCCState *s1)
{
    എങ്കിൽ (s1->error_set_jmp_enabled)
        തിരികെ;
    tcc_state = ശൂന്യ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC അക്ഷരം *pstrcpy(അക്ഷരം *buf, size_t buf_size, സ്ഥിരം അക്ഷരം *s)
{
    അക്ഷരം *q, *q_end;
    പൂർണ്ണസംഖ്യ c;

    എങ്കിൽ (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        ആകുമ്പോൾ (q < q_end) {
            c = *s++;
            എങ്കിൽ (c == '\0')
                നിർത്തുക;
            *q++ = c;
        }
        *q = '\0';
    }
    തിരികെ buf;
}

/* strcat and truncate. */
ST_FUNC അക്ഷരം *pstrcat(അക്ഷരം *buf, size_t buf_size, സ്ഥിരം അക്ഷരം *s)
{
    size_t len;
    len = strlen(buf);
    എങ്കിൽ (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    തിരികെ buf;
}

ST_FUNC അക്ഷരം *pstrncpy(അക്ഷരം *out, size_t buf_size, സ്ഥിരം അക്ഷരം *s, size_t അക്കം)
{
    എങ്കിൽ (അക്കം >= buf_size)
        അക്കം = buf_size - 1;
    memcpy(out, s, അക്കം);
    out[അക്കം] = '\0';
    തിരികെ out;
}

/* extract the basename of a file */
PUB_FUNC അക്ഷരം *tcc_basename(സ്ഥിരം അക്ഷരം *name)
{
    അക്ഷരം *p = (അക്ഷരം *)strchr(name, 0);
    ആകുമ്പോൾ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    തിരികെ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC അക്ഷരം *tcc_fileextension (സ്ഥിരം അക്ഷരം *name)
{
    അക്ഷരം *b = tcc_basename(name);
    അക്ഷരം *e = strrchr(b, '.');
    തിരികെ e ? e : strchr(b, 0);
}

ST_FUNC അക്ഷരം *tcc_load_text(പൂർണ്ണസംഖ്യ fd)
{
    പൂർണ്ണസംഖ്യ len = lseek(fd, 0, SEEK_END);
    അക്ഷരം *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    തിരികെ buf;
}

/* replace *pp by copy of 'str' or NULL */
സ്ഥിതം ശൂന്യം tcc_set_str(അക്ഷരം **pp, സ്ഥിരം അക്ഷരം *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ശൂന്യ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
സ്ഥിതം ശൂന്യം tcc_concat_str(അക്ഷരം **pp, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ sep)
{
    പൂർണ്ണസംഖ്യ l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    എങ്കിൽ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef സ്വതന്ത്രം
#undef realloc

സ്ഥിതം ശൂന്യം *default_reallocator(ശൂന്യം *ptr, unsigned long size)
{
    ശൂന്യം *ptr1;
    എങ്കിൽ (size == 0) {
        സ്വതന്ത്രം(ptr);
        ptr1 = ശൂന്യ;
    }
    അല്ലെങ്കിൽ {
        ptr1 = realloc(ptr, size);
        എങ്കിൽ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    തിരികെ ptr1;
}

ST_FUNC ശൂന്യം libc_free(ശൂന്യം *ptr)
{
    സ്വതന്ത്രം(ptr);
}

/* defined to be not used */
#define സ്വതന്ത്രം(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
സ്ഥിതം ശൂന്യം *(*reallocator)(ശൂന്യം*, unsigned long) = default_reallocator;

LIBTCCAPI ശൂന്യം tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC ശൂന്യം tcc_free(ശൂന്യം *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC ശൂന്യം *tcc_malloc(unsigned long size)
{
    തിരികെ reallocator(0, size);
}

PUB_FUNC ശൂന്യം *tcc_realloc(ശൂന്യം *ptr, unsigned long size)
{
    തിരികെ reallocator(ptr, size);
}

PUB_FUNC ശൂന്യം *tcc_mallocz(unsigned long size)
{
    ശൂന്യം *ptr;
    ptr = tcc_malloc(size);
    എങ്കിൽ (size)
        memset(ptr, 0, size);
    തിരികെ ptr;
}

PUB_FUNC അക്ഷരം *tcc_strdup(സ്ഥിരം അക്ഷരം *str)
{
    അക്ഷരം *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    തിരികെ ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned അക്ഷരം *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((അക്ഷരം *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((അക്ഷരം*)ptr - offsetof(mem_debug_header_t, magic3))

ഘടന mem_debug_header {
    unsigned magic1;
    unsigned size;
    ഘടന mem_debug_header *prev;
    ഘടന mem_debug_header *next;
    പൂർണ്ണസംഖ്യ വരി_അക്കം;
    അക്ഷരം file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned അക്ഷരം magic3[4];
};

തരനിർവചനം ഘടന mem_debug_header mem_debug_header_t;

TCC_SEM(സ്ഥിതം mem_sem);
സ്ഥിതം mem_debug_header_t *mem_debug_chain;
സ്ഥിതം unsigned mem_cur_size;
സ്ഥിതം unsigned mem_max_size;
സ്ഥിതം പൂർണ്ണസംഖ്യ nb_states;

സ്ഥിതം mem_debug_header_t *malloc_check(ശൂന്യം *ptr, സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    എങ്കിൽ (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", സന്ദേശം);
        എങ്കിൽ (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->വരി_അക്കം);
        exit(1);
    }
    തിരികെ header;
}

PUB_FUNC ശൂന്യം *tcc_malloc_debug(unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി)
{
    പൂർണ്ണസംഖ്യ ofs;
    mem_debug_header_t *header;
    എങ്കിൽ (!size)
        തിരികെ ശൂന്യ;
    header = tcc_malloc(വലുപ്പം(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->വരി_അക്കം = വരി;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = ശൂന്യ;
    എങ്കിൽ (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    എങ്കിൽ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    തിരികെ MEM_USER_PTR(header);
}

PUB_FUNC ശൂന്യം tcc_free_debug(ശൂന്യം *ptr)
{
    mem_debug_header_t *header;
    എങ്കിൽ (!ptr)
        തിരികെ;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    എങ്കിൽ (header->next)
        header->next->prev = header->prev;
    എങ്കിൽ (header->prev)
        header->prev->next = header->next;
    എങ്കിൽ (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC ശൂന്യം *tcc_mallocz_debug(unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി)
{
    ശൂന്യം *ptr;
    ptr = tcc_malloc_debug(size,file,വരി);
    എങ്കിൽ (size)
        memset(ptr, 0, size);
    തിരികെ ptr;
}

PUB_FUNC ശൂന്യം *tcc_realloc_debug(ശൂന്യം *ptr, unsigned long size, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി)
{
    mem_debug_header_t *header;
    പൂർണ്ണസംഖ്യ mem_debug_chain_update = 0;

    എങ്കിൽ (!ptr)
        തിരികെ tcc_malloc_debug(size, file, വരി);
    എങ്കിൽ (!size) {
        tcc_free_debug(ptr);
        തിരികെ ശൂന്യ;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, വലുപ്പം(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    എങ്കിൽ (header->next)
        header->next->prev = header;
    എങ്കിൽ (header->prev)
        header->prev->next = header;
    എങ്കിൽ (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    എങ്കിൽ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    തിരികെ MEM_USER_PTR(header);
}

PUB_FUNC അക്ഷരം *tcc_strdup_debug(സ്ഥിരം അക്ഷരം *str, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി)
{
    അക്ഷരം *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, വരി);
    strcpy(ptr, str);
    തിരികെ ptr;
}

PUB_FUNC ശൂന്യം tcc_memcheck(പൂർണ്ണസംഖ്യ d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    എങ്കിൽ (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        ആകുമ്പോൾ (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->വരി_അക്കം, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = ശൂന്യ;
#എങ്കിൽ MEM_DEBUG-0 == 2
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
ST_FUNC പൂർണ്ണസംഖ്യ normalized_PATHCMP(സ്ഥിരം അക്ഷരം *f1, സ്ഥിരം അക്ഷരം *f2)
{
    അക്ഷരം *p1, *p2;
    പൂർണ്ണസംഖ്യ ret = 1;
    എങ്കിൽ (!!(p1 = realpath(f1, ശൂന്യ))) {
        എങ്കിൽ (!!(p2 = realpath(f2, ശൂന്യ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    തിരികെ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC ശൂന്യം dynarray_add(ശൂന്യം *ptab, പൂർണ്ണസംഖ്യ *nb_ptr, ശൂന്യം *data)
{
    പൂർണ്ണസംഖ്യ nb, nb_alloc;
    ശൂന്യം **pp;

    nb = *nb_ptr;
    pp = *(ശൂന്യം ***)ptab;
    /* every power of two we double array size */
    എങ്കിൽ ((nb & (nb - 1)) == 0) {
        എങ്കിൽ (!nb)
            nb_alloc = 1;
        അല്ലെങ്കിൽ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * വലുപ്പം(ശൂന്യം *));
        *(ശൂന്യം***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC ശൂന്യം dynarray_reset(ശൂന്യം *pp, പൂർണ്ണസംഖ്യ *n)
{
    ശൂന്യം **p;
    വേണ്ടി (p = *(ശൂന്യം***)pp; *n; ++p, --*n)
        എങ്കിൽ (*p)
            tcc_free(*p);
    tcc_free(*(ശൂന്യം**)pp);
    *(ശൂന്യം**)pp = ശൂന്യ;
}

സ്ഥിതം ശൂന്യം dynarray_split(അക്ഷരം ***argv, പൂർണ്ണസംഖ്യ *argc, സ്ഥിരം അക്ഷരം *p, പൂർണ്ണസംഖ്യ sep)
{
    പൂർണ്ണസംഖ്യ qot, c;
    CString str;
    വേണ്ടി(;;) {
        ആകുമ്പോൾ (c = (unsigned അക്ഷരം)*p, c <= ' ' && c != '\0')
            ++p;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        cstr_new(&str);
        qot = 0;
        ചെയ്യുക {
            ++p;
            എങ്കിൽ (sep) { /* e.g. to split -Wl,-opt,arg */
                എങ്കിൽ (c == sep)
                    നിർത്തുക;
            } അല്ലെങ്കിൽ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                എങ്കിൽ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } അല്ലെങ്കിൽ എങ്കിൽ (c == '"') {
                    qot ^= 1;
                    തുടരുക;
                } അല്ലെങ്കിൽ എങ്കിൽ (c <= ' ' && !qot) {
                    നിർത്തുക;
                }
            }
            cstr_ccat(&str, c);
        } ആകുമ്പോൾ (c = (unsigned അക്ഷരം)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

സ്ഥിതം ശൂന്യം tcc_split_path(TCCState *s, ശൂന്യം *p_ary, പൂർണ്ണസംഖ്യ *p_nb_ary, സ്ഥിരം അക്ഷരം *in)
{
    സ്ഥിരം അക്ഷരം *p;
    ചെയ്യുക {
        പൂർണ്ണസംഖ്യ c;
        CString str;

        cstr_new(&str);
        വേണ്ടി (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            എങ്കിൽ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                എങ്കിൽ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                എങ്കിൽ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                എങ്കിൽ (c == 'f' && file) {
                    /* substitute current file's dir */
                    സ്ഥിരം അക്ഷരം *f = file->true_filename;
                    സ്ഥിരം അക്ഷരം *b = tcc_basename(f);
                    എങ്കിൽ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    അല്ലെങ്കിൽ
                        cstr_cat(&str, ".", 1);
                }
            } അല്ലെങ്കിൽ {
                cstr_ccat(&str, c);
            }
        }
        എങ്കിൽ (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } ആകുമ്പോൾ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
എണ്ണൽ { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

സ്ഥിതം ശൂന്യം error1(പൂർണ്ണസംഖ്യ mode, സ്ഥിരം അക്ഷരം *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    പൂർണ്ണസംഖ്യ വരി = 0;

    tcc_exit_state(s1);

    എങ്കിൽ (mode == ERROR_WARN) {
        എങ്കിൽ (s1->warn_error)
            mode = ERROR_ERROR;
        എങ്കിൽ (s1->warn_അക്കം) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            പൂർണ്ണസംഖ്യ wopt = *(&s1->warn_none + s1->warn_അക്കം);
            s1->warn_അക്കം = 0;
            എങ്കിൽ (0 == (wopt & WARN_ON))
                തിരികെ;
            എങ്കിൽ (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            എങ്കിൽ (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        എങ്കിൽ (s1->warn_none)
            തിരികെ;
    }

    cstr_new(&cs);
    എങ്കിൽ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        വരി = va_arg(ap, പൂർണ്ണസംഖ്യ), fmt += 3;
    f = ശൂന്യ;
    എങ്കിൽ (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        വേണ്ടി (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    എങ്കിൽ (f) {
        വേണ്ടി(pf = s1->include_അട്ടി; pf < s1->include_അട്ടി_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->വരി_അക്കം - 1);
        എങ്കിൽ (0 == വരി)
            വരി = f->വരി_അക്കം - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, വരി);
    } അല്ലെങ്കിൽ എങ്കിൽ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } അല്ലെങ്കിൽ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    എങ്കിൽ (pp_വ്യഞ്ജകം > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    അല്ലെങ്കിൽ
        cstr_vprintf(&cs, fmt, ap);
    എങ്കിൽ (!s1->error_func) {
        /* default case: stderr */
        എങ്കിൽ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (അക്ഷരം*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } അല്ലെങ്കിൽ {
        s1->error_func(s1->error_opaque, (അക്ഷരം*)cs.data);
    }
    cstr_free(&cs);
    എങ്കിൽ (mode != ERROR_WARN)
        s1->nb_errors++;
    എങ്കിൽ (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        ആകുമ്പോൾ (nb_stk_data)
            tcc_free(*(ശൂന്യം**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI ശൂന്യം tcc_set_error_func(TCCState *s, ശൂന്യം *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC പൂർണ്ണസംഖ്യ _tcc_error_noabort(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    തിരികെ -1;
}

#undef _tcc_error
PUB_FUNC ശൂന്യം _tcc_error(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC ശൂന്യം _tcc_warning(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC ശൂന്യം tcc_open_bf(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ initlen)
{
    BufferedFile *bf;
    പൂർണ്ണസംഖ്യ buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(വലുപ്പം(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, വലുപ്പം(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->വരി_അക്കം = 1;
    bf->ifdef_അട്ടി_ptr = s1->ifdef_അട്ടി_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC ശൂന്യം tcc_close(ശൂന്യം)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    എങ്കിൽ (bf->fd > 0) {
        close(bf->fd);
        total_വരികൾ += bf->വരി_അക്കം - 1;
    }
    എങ്കിൽ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ _tcc_open(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ fd;
    എങ്കിൽ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    അല്ലെങ്കിൽ
        fd = open(filename, O_RDONLY | O_ദ്വിമാന_2);
    എങ്കിൽ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (പൂർണ്ണസംഖ്യ)(s1->include_അട്ടി_ptr - s1->include_അട്ടി), "", filename);
    തിരികെ fd;
}

ST_FUNC പൂർണ്ണസംഖ്യ tcc_open(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ fd = _tcc_open(s1, filename);
    എങ്കിൽ (fd < 0)
        തിരികെ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    തിരികെ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_compile(TCCState *s1, പൂർണ്ണസംഖ്യ filetype, സ്ഥിരം അക്ഷരം *str, പൂർണ്ണസംഖ്യ fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    എങ്കിൽ (setjmp(s1->error_jmp_buf) == 0) {

        എങ്കിൽ (fd == -1) {
            പൂർണ്ണസംഖ്യ len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } അല്ലെങ്കിൽ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        എങ്കിൽ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } അല്ലെങ്കിൽ {
            tccelf_begin_file(s1);
            എങ്കിൽ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } അല്ലെങ്കിൽ {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    തിരികെ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_compile_string(TCCState *s, സ്ഥിരം അക്ഷരം *str)
{
    തിരികെ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ശൂന്യം tcc_define_ചിഹ്നം(TCCState *s1, സ്ഥിരം അക്ഷരം *sym, സ്ഥിരം അക്ഷരം *മൂല്യം)
{
    സ്ഥിരം അക്ഷരം *eq;
    എങ്കിൽ (ശൂന്യ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    എങ്കിൽ (ശൂന്യ == മൂല്യം)
        മൂല്യം = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (പൂർണ്ണസംഖ്യ)(eq-sym), sym, മൂല്യം);
}

/* undefine a preprocessor symbol */
LIBTCCAPI ശൂന്യം tcc_undefine_ചിഹ്നം(TCCState *s1, സ്ഥിരം അക്ഷരം *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(ശൂന്യം)
{
    TCCState *s;

    s = tcc_mallocz(വലുപ്പം(TCCState));
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
#എങ്കിൽ defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#എങ്കിൽ defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_അട്ടി_ptr = s->include_അട്ടി;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    തിരികെ s;
}

LIBTCCAPI ശൂന്യം tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_ചിഹ്നം);
    tcc_free(s1->fini_ചിഹ്നം);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#എങ്കിൽ defined TCC_TARGET_MACHO
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

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_set_output_type(TCCState *s, പൂർണ്ണസംഖ്യ output_type)
{
#ifdef CONFIG_TCC_PIE
    എങ്കിൽ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    എങ്കിൽ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    എങ്കിൽ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        തിരികെ 0;
    }

    /* add sections */
    tccelf_new(s);

    എങ്കിൽ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        തിരികെ 0;
    }

    എങ്കിൽ (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#അല്ലെങ്കിൽ
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    എങ്കിൽ (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    തിരികെ s->nb_errors ? -1 : 0;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_include_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    തിരികെ 0;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_sysinclude_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    തിരികെ 0;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_library_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    തിരികെ 0;
}

LIBTCCAPI ശൂന്യം tcc_set_lib_path(TCCState *s, സ്ഥിരം അക്ഷരം *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, സ്ഥിരം അക്ഷരം *dllname, പൂർണ്ണസംഖ്യ level)
{
    DLLReference *ref = ശൂന്യ;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < s1->nb_loaded_dlls; i++)
        എങ്കിൽ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            നിർത്തുക;
        }
    എങ്കിൽ (level == -1)
        തിരികെ ref;
    എങ്കിൽ (ref) {
        എങ്കിൽ (level < ref->level)
            ref->level = level;
        ref->found = 1;
        തിരികെ ref;
    }
    ref = tcc_mallocz(വലുപ്പം(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    തിരികെ ref;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_add_ദ്വിമാന(TCCState *s1, പൂർണ്ണസംഖ്യ flags, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ fd)
{
    ElfW(Ehdr) ehdr;
    പൂർണ്ണസംഖ്യ obj_type;
    സ്ഥിരം അക്ഷരം *saved_filename = s1->current_filename;
    പൂർണ്ണസംഖ്യ ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    തിരഞ്ഞെടുപ്പ് (obj_type) {

    അവസ്ഥ AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        നിർത്തുക;

    അവസ്ഥ AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        നിർത്തുക;

#എങ്കിൽ defined TCC_TARGET_UNIX
    അവസ്ഥ AFF_BINTYPE_DYN:
        എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ശൂന്യം* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            എങ്കിൽ (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            അല്ലെങ്കിൽ
                ret = FILE_NOT_RECOGNIZED;
#endif
        } അല്ലെങ്കിൽ
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        നിർത്തുക;

    സ്ഥിരസ്ഥിതി:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        നിർത്തുക;

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_MACHO
    അവസ്ഥ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        എങ്കിൽ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ശൂന്യം* dl;
            സ്ഥിരം അക്ഷരം* soname = filename;
            അക്ഷരം *tmp = 0;
            എങ്കിൽ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                എങ്കിൽ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            എങ്കിൽ (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            അല്ലെങ്കിൽ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } അല്ലെങ്കിൽ എങ്കിൽ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } അല്ലെങ്കിൽ {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        എങ്കിൽ (ret)
            ret = FILE_NOT_RECOGNIZED;
        നിർത്തുക;

    സ്ഥിരസ്ഥിതി:
    {
        സ്ഥിരം അക്ഷരം *ext = tcc_fileextension(filename);
        എങ്കിൽ (!strcmp(ext, ".tbd"))
            പോകുക case_dyn_or_tbd;
        എങ്കിൽ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            പോകുക case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        നിർത്തുക;
    }

#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_PE
    സ്ഥിരസ്ഥിതി:
        എങ്കിൽ (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        നിർത്തുക;
#endif

#ifdef TCC_TARGET_COFF
    അവസ്ഥ AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        നിർത്തുക;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    എങ്കിൽ (ret == FILE_NOT_RECOGNIZED)
        തിരികെ tcc_error_noabort("%s: unrecognized file type", filename);
    തിരികെ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#എങ്കിൽ defined TARGETOS_OpenBSD && !defined _WIN32
#അന്തര്ഭാവ <glob.h>
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_glob_so(TCCState *s1, സ്ഥിരം അക്ഷരം *pattern, അക്ഷരം *buf, പൂർണ്ണസംഖ്യ size)
{
    സ്ഥിരം അക്ഷരം *star;
    glob_t g;
    അക്ഷരം *p;
    പൂർണ്ണസംഖ്യ i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    എങ്കിൽ (!star || glob(pattern, 0, ശൂന്യ, &g))
        തിരികെ -1;
    വേണ്ടി (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        എങ്കിൽ (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            തുടരുക;
        എങ്കിൽ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    തിരികെ v;
}
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ guess_filetype(സ്ഥിരം അക്ഷരം *filename)
{
    പൂർണ്ണസംഖ്യ filetype = 0;
    എങ്കിൽ (1) {
        /* use a file extension to detect a filetype */
        സ്ഥിരം അക്ഷരം *ext = tcc_fileextension(filename);
        എങ്കിൽ (ext[0]) {
            ext++;
            എങ്കിൽ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            അല്ലെങ്കിൽ എങ്കിൽ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            അല്ലെങ്കിൽ
                filetype |= AFF_TYPE_BIN;
        } അല്ലെങ്കിൽ {
            filetype = AFF_TYPE_C;
        }
    }
    തിരികെ filetype;
}

ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_file_internal(TCCState *s1, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flags)
{
    പൂർണ്ണസംഖ്യ fd;

#എങ്കിൽ defined TARGETOS_OpenBSD && !defined _WIN32
    അക്ഷരം buf[1024];
    എങ്കിൽ (tcc_glob_so(s1, filename, buf, വലുപ്പം buf) >= 0)
        filename = buf;
#endif

    എങ്കിൽ (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    എങ്കിൽ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        തിരികെ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    എങ്കിൽ (fd < 0) {
        എങ്കിൽ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        തിരികെ FILE_NOT_FOUND;
    }

    എങ്കിൽ (flags & AFF_TYPE_BIN)
        തിരികെ tcc_add_ദ്വിമാന(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    തിരികെ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_file(TCCState *s, സ്ഥിരം അക്ഷരം *filename)
{
    തിരികെ tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_add_library_internal(TCCState *s1, സ്ഥിരം അക്ഷരം *fmt,
    സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flags, അക്ഷരം **paths, പൂർണ്ണസംഖ്യ nb_paths)
{
    അക്ഷരം buf[1024];
    പൂർണ്ണസംഖ്യ i, ret;

    വേണ്ടി(i = 0; i < nb_paths; i++) {
        snprintf(buf, വലുപ്പം(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        എങ്കിൽ (ret != FILE_NOT_FOUND)
            തിരികെ ret;
    }
    എങ്കിൽ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    തിരികെ FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_dll(TCCState *s, സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flags)
{
    തിരികെ tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_support(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    അക്ഷരം buf[100];
    എങ്കിൽ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    തിരികെ tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC പൂർണ്ണസംഖ്യ tcc_add_crt(TCCState *s1, സ്ഥിരം അക്ഷരം *filename)
{
    തിരികെ tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_library(TCCState *s, സ്ഥിരം അക്ഷരം *libraryname)
{
    സ്ഥിതം സ്ഥിരം അക്ഷരം * സ്ഥിരം libs[] = {
#എങ്കിൽ defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#അല്ലെങ്കിലെങ്കിൽ defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#അല്ലെങ്കിൽ
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        ശൂന്യ
    };
    പൂർണ്ണസംഖ്യ flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    എങ്കിൽ (*libraryname == ':') {
        libraryname++;
    } അല്ലെങ്കിൽ {
        സ്ഥിരം അക്ഷരം * സ്ഥിരം *pp = libs;
        എങ്കിൽ (s->static_link)
            pp += വലുപ്പം(libs) / വലുപ്പം(*libs) - 2; /* only "%s/lib%s.a" */
        ആകുമ്പോൾ (*pp) {
            പൂർണ്ണസംഖ്യ ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            എങ്കിൽ (ret != FILE_NOT_FOUND)
                തിരികെ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    തിരികെ tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC ശൂന്യം tcc_add_pragma_libs(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

സ്ഥിതം പൂർണ്ണസംഖ്യ strstart(സ്ഥിരം അക്ഷരം *val, സ്ഥിരം അക്ഷരം **str)
{
    സ്ഥിരം അക്ഷരം *p, *q;
    p = *str;
    q = val;
    ആകുമ്പോൾ (*q) {
        എങ്കിൽ (*p != *q)
            തിരികെ 0;
        p++;
        q++;
    }
    *str = p;
    തിരികെ 1;
}

ഘടന lopt {
    TCCState *s;
    സ്ഥിരം അക്ഷരം *opt, *arg;
    പൂർണ്ണസംഖ്യ match;
};

/* match linker option */
സ്ഥിതം പൂർണ്ണസംഖ്യ link_option(ഘടന lopt *o, സ്ഥിരം അക്ഷരം *q)
{
    സ്ഥിരം അക്ഷരം *p;
    പൂർണ്ണസംഖ്യ c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    എങ്കിൽ (*p++ != '-')
        തിരികെ 0;
    എങ്കിൽ (*p == '-')
        p++;
    r = 1;
    എങ്കിൽ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        എങ്കിൽ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        അല്ലെങ്കിൽ എങ്കിൽ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    ആകുമ്പോൾ ((c = *q) == *p) {
        എങ്കിൽ (c == '\0')
            പോകുക succ; /* -Wl,-opt */
        ++p;
        എങ്കിൽ (c == '=')
            പോകുക succ; /* -Wl,-opt=arg */
        ++q;
    }
    എങ്കിൽ (*p == '\0') {
        എങ്കിൽ (c == '|')
            പോകുക succ;
        എങ്കിൽ (c == '=' || c == ':') {
            എങ്കിൽ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                പോകുക succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            തിരികെ 0;
        }
    } അല്ലെങ്കിൽ എങ്കിൽ (c == ':')
        പോകുക succ; /* -Wl,-Iarg */
    ആകുമ്പോൾ (*q)
        എങ്കിൽ (*q++ == '|')
            പോകുക redo;
    തിരികെ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    തിരികെ r;
}

സ്ഥിതം ശൂന്യം args_parser_add_file(TCCState *s, സ്ഥിരം അക്ഷരം* filename, പൂർണ്ണസംഖ്യ filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_set_linker(TCCState *s, സ്ഥിരം അക്ഷരം *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    ആകുമ്പോൾ (s->link_optind < s->link_argc) {
        അക്ഷരം *end = ശൂന്യ;
        പൂർണ്ണസംഖ്യ ignoring = 0;
        ഘടന lopt o = {0};
        പൂർണ്ണസംഖ്യ r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        എങ്കിൽ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "init=")) {
            tcc_set_str(&s->init_ചിഹ്നം, o.arg);
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_ചിഹ്നം, o.arg);
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "oformat=")) {
#എങ്കിൽ defined TCC_TARGET_PE
            എങ്കിൽ (0 == strncmp("pe-", o.arg, 3))
#അല്ലെങ്കിലെങ്കിൽ PTR_SIZE == 8
            എങ്കിൽ (0 == strncmp("elf64-", o.arg, 6))
#അല്ലെങ്കിൽ
            എങ്കിൽ (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            അല്ലെങ്കിൽ എങ്കിൽ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ദ്വിമാന;
#എങ്കിൽ defined TCC_TARGET_COFF
            അല്ലെങ്കിൽ എങ്കിൽ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            അല്ലെങ്കിൽ
                പോകുക err;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } അല്ലെങ്കിൽ എങ്കിൽ (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } അല്ലെങ്കിൽ എങ്കിൽ (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } അല്ലെങ്കിൽ എങ്കിൽ (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } അല്ലെങ്കിൽ എങ്കിൽ (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } അല്ലെങ്കിൽ എങ്കിൽ (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "stack=")) {
            s->pe_അട്ടി_size = strtoul(o.arg, &end, 10);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "subsystem=")) {
            എങ്കിൽ (pe_setsubsy(s, o.arg) < 0)
                പോകുക err;
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_MACHO
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "O")) {
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "z=")) {
            ignoring = 1;
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } അല്ലെങ്കിൽ എങ്കിൽ (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } അല്ലെങ്കിൽ എങ്കിൽ (o.match) {
            തിരികെ 0; /* expecting argument with next '-Wl,' */
        } അല്ലെങ്കിൽ {
    err:
            തിരികെ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        എങ്കിൽ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    തിരികെ 0;
}

തരനിർവചനം ഘടന TCCOption {
    സ്ഥിരം അക്ഷരം *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

എണ്ണൽ {
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
    TCC_OPTION_print_തിരയൽ_dirs,
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

സ്ഥിതം സ്ഥിരം TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_തിരയൽ_dirs, 0 },
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
    { ശൂന്യ, 0, 0 },
};

തരനിർവചനം ഘടന FlagDef {
    uint16_t offset;
    uint16_t flags;
    സ്ഥിരം അക്ഷരം *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

സ്ഥിതം സ്ഥിരം FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ശൂന്യ }
};

സ്ഥിതം സ്ഥിരം FlagDef options_f[] = {
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
    { 0, 0, ശൂന്യ }
};

സ്ഥിതം സ്ഥിരം FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, ശൂന്യ }
};

സ്ഥിതം പൂർണ്ണസംഖ്യ set_flag(TCCState *s, സ്ഥിരം FlagDef *flags, സ്ഥിരം അക്ഷരം *name)
{
    പൂർണ്ണസംഖ്യ മൂല്യം, mask, ret;
    സ്ഥിരം FlagDef *p;
    സ്ഥിരം അക്ഷരം *r;
    unsigned അക്ഷരം *f;

    r = name, മൂല്യം = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    എങ്കിൽ ((flags->flags & WD_ALL) && strstart("error=", &r))
        മൂല്യം = മൂല്യം ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    വേണ്ടി (ret = -1, p = flags; p->name; ++p) {
        എങ്കിൽ (ret) {
            എങ്കിൽ (strcmp(r, p->name))
                തുടരുക;
        } അല്ലെങ്കിൽ {
            എങ്കിൽ (0 == (p->flags & WD_ALL))
                തുടരുക;
        }

        f = (unsigned അക്ഷരം *)s + p->offset;
        *f = (*f & mask) | (മൂല്യം ^ !!(p->flags & FD_INVERT));

        എങ്കിൽ (ret) {
            ret = 0;
            എങ്കിൽ (strcmp(r, "all"))
                നിർത്തുക;
        }
    }
    തിരികെ ret;
}

സ്ഥിതം സ്ഥിരം അക്ഷരം dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_X86_64
    "x86_64-pc"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_C67
    "c67"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM
    "arm"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_ARM64
    "aarch64"
#അല്ലെങ്കിലെങ്കിൽ defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#അല്ലെങ്കിലെങ്കിൽ defined(TCC_TARGET_MACHO)
    "apple-darwin"
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_OpenBSD
    "openbsd"
#അല്ലെങ്കിലെങ്കിൽ TARGETOS_NetBSD
    "netbsd"
#അല്ലെങ്കിലെങ്കിൽ CONFIG_TCC_MUSL
    "linux-musl"
#അല്ലെങ്കിൽ
    "linux-gnu"
#endif
;

#എങ്കിൽ defined TCC_TARGET_MACHO
സ്ഥിതം uint32_t parse_version(TCCState *s1, സ്ഥിരം അക്ഷരം *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    അക്ഷരം* last;

    a = strtoul(version, &last, 10);
    എങ്കിൽ (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        എങ്കിൽ (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    എങ്കിൽ (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    തിരികെ (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
സ്ഥിതം ശൂന്യം തിരുകുക_args(TCCState *s1, അക്ഷരം ***pargv, പൂർണ്ണസംഖ്യ *pargc, പൂർണ്ണസംഖ്യ optind, സ്ഥിരം അക്ഷരം *p, പൂർണ്ണസംഖ്യ sep)
{
    പൂർണ്ണസംഖ്യ argc = 0;
    അക്ഷരം **argv = ശൂന്യ;
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 0; i < *pargc; ++i)
        എങ്കിൽ (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        അല്ലെങ്കിൽ
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

സ്ഥിതം ശൂന്യം args_parser_add_file(TCCState *s, സ്ഥിരം അക്ഷരം* filename, പൂർണ്ണസംഖ്യ filetype)
{
    ഘടന filespec *f = tcc_malloc(വലുപ്പം *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    എങ്കിൽ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC പൂർണ്ണസംഖ്യ tcc_parse_args(TCCState *s, പൂർണ്ണസംഖ്യ *pargc, അക്ഷരം ***pargv)
{
    TCCState *s1 = s;
    സ്ഥിരം TCCOption *popt;
    സ്ഥിരം അക്ഷരം *optarg, *r;
    സ്ഥിരം അക്ഷരം *run = ശൂന്യ;
    പൂർണ്ണസംഖ്യ optind = 1, empty = 1, x;
    അക്ഷരം **argv = *pargv;
    പൂർണ്ണസംഖ്യ argc = *pargc;

    s->link_optind = s->link_argc;

    ആകുമ്പോൾ (optind < argc) {
        r = argv[optind];
        എങ്കിൽ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            പൂർണ്ണസംഖ്യ fd; അക്ഷരം *p;
            fd = open(++r, O_RDONLY | O_ദ്വിമാന_2);
            എങ്കിൽ (fd < 0)
                തിരികെ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            തിരുകുക_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            തുടരുക;
        }
        optind++;
        എങ്കിൽ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            എങ്കിൽ (run)
                നിർത്തുക;
            തുടരുക;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        എങ്കിൽ (r[1] == '-' && r[2] == '\0')
            പോകുക dorun;

        /* find option in table */
        വേണ്ടി(popt = tcc_options; ; ++popt) {
            സ്ഥിരം അക്ഷരം *p1 = popt->name;
            സ്ഥിരം അക്ഷരം *r1 = r + 1;
            എങ്കിൽ (p1 == ശൂന്യ)
                തിരികെ tcc_error_noabort("invalid option -- '%s'", r);
            എങ്കിൽ (!strstart(p1, &r1))
                തുടരുക;
            optarg = r1;
            എങ്കിൽ (popt->flags & TCC_OPTION_HAS_ARG) {
                എങ്കിൽ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    എങ്കിൽ (optind >= argc)
                        തിരികെ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } അല്ലെങ്കിൽ എങ്കിൽ (*r1 != '\0')
                തുടരുക;
            നിർത്തുക;
        }

        തിരഞ്ഞെടുപ്പ്(popt->index) {
        അവസ്ഥ TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_D:
            tcc_define_ചിഹ്നം(s, optarg, ശൂന്യ);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_U:
            tcc_undefine_ചിഹ്നം(s, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            തുടരുക;
        അവസ്ഥ TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_pthread:
            s->option_pthread = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_bench:
            s->do_bench = 1;
            നിർത്തുക;
#ifdef CONFIG_TCC_BACKTRACE
        അവസ്ഥ TCC_OPTION_bt:
            s->rt_അക്കം_callers = atoi(optarg); /* zero = default (6) */
            പോകുക enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            എങ്കിൽ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            നിർത്തുക;
#ifdef CONFIG_TCC_BCHECK
        അവസ്ഥ TCC_OPTION_b:
            s->do_bounds_check = 1;
            പോകുക enable_backtrace;
#endif
#endif
        അവസ്ഥ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            എങ്കിൽ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } അല്ലെങ്കിൽ എങ്കിൽ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } അല്ലെങ്കിൽ എങ്കിൽ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                പോകുക g_redo;
#ifdef TCC_TARGET_PE
            } അല്ലെങ്കിൽ എങ്കിൽ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            എങ്കിൽ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_d:
            എങ്കിൽ (*optarg == 'D')
                s->dflag = 3;
            അല്ലെങ്കിൽ എങ്കിൽ (*optarg == 'M')
                s->dflag = 7;
            അല്ലെങ്കിൽ എങ്കിൽ (*optarg == 't')
                s->dflag = 16;
            അല്ലെങ്കിൽ എങ്കിൽ (isnum(*optarg))
                g_debug |= atoi(optarg);
            അല്ലെങ്കിൽ
                പോകുക unsupported_option;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_static:
            s->static_link = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_std:
            എങ്കിൽ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            പോകുക set_output_type;
        അവസ്ഥ TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_o:
            എങ്കിൽ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            പോകുക set_output_type;
        അവസ്ഥ TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            പോകുക set_output_type;
#അല്ലെങ്കിൽ
            തിരികെ tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        അവസ്ഥ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            നിർത്തുക;
#endif
        അവസ്ഥ TCC_OPTION_v:
            ചെയ്യുക ++s->verbose; ആകുമ്പോൾ (*optarg++ == 'v');
            തുടരുക;
        അവസ്ഥ TCC_OPTION_f:
            എങ്കിൽ (set_flag(s, options_f, optarg) < 0)
                പോകുക unsupported_option;
            നിർത്തുക;
#ifdef TCC_TARGET_ARM
        അവസ്ഥ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            എങ്കിൽ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } അല്ലെങ്കിൽ എങ്കിൽ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            അല്ലെങ്കിൽ
                തിരികെ tcc_error_noabort("unsupported float abi '%s'", optarg);
            തുടരുക;
#endif
        അവസ്ഥ TCC_OPTION_m:
            എങ്കിൽ (set_flag(s, options_m, optarg) < 0) {
                എങ്കിൽ (x = atoi(optarg), x != 32 && x != 64)
                    പോകുക unsupported_option;
                എങ്കിൽ (PTR_SIZE != x/8)
                    തിരികെ x;
                തുടരുക;
            }
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_W:
            എങ്കിൽ (optarg[0] && set_flag(s, options_W, optarg) < 0)
                പോകുക unsupported_option;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_w:
            s->warn_none = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_Wl:
            എങ്കിൽ (tcc_set_linker(s, optarg) < 0)
                തിരികെ -1;
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_Wp:
            എങ്കിൽ (argv[0]) /* not with tcc_set_options() */
                തിരുകുക_args(s, &argv, &argc, --optind, optarg, ',');
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            പോകുക set_output_type;
        അവസ്ഥ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            നിർത്തുക;

        അവസ്ഥ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        അവസ്ഥ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            എങ്കിൽ (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        അവസ്ഥ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            എങ്കിൽ (*optarg != ',')
                നിർത്തുക;
            ++optarg;
            // fall through
        അവസ്ഥ TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            നിർത്തുക;

        അവസ്ഥ TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        അവസ്ഥ TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        അവസ്ഥ TCC_OPTION_x:
            x = 0;
            എങ്കിൽ (*optarg == 'c')
                x = AFF_TYPE_C;
            അല്ലെങ്കിൽ എങ്കിൽ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            അല്ലെങ്കിൽ എങ്കിൽ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            അല്ലെങ്കിൽ എങ്കിൽ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            അല്ലെങ്കിൽ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            നിർത്തുക;
#എങ്കിൽ defined TCC_TARGET_MACHO
        അവസ്ഥ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            പോകുക set_output_type;
        അവസ്ഥ TCC_OPTION_flat_namespace:
	     നിർത്തുക;
        അവസ്ഥ TCC_OPTION_two_levelnamespace:
	     നിർത്തുക;
        അവസ്ഥ TCC_OPTION_undefined:
	     നിർത്തുക;
        അവസ്ഥ TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            നിർത്തുക;
        അവസ്ഥ TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            നിർത്തുക;
#endif
        അവസ്ഥ TCC_OPTION_HELP:
            x = OPT_HELP;
            പോകുക extra_action;
        അവസ്ഥ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            പോകുക extra_action;
        അവസ്ഥ TCC_OPTION_print_തിരയൽ_dirs:
            x = OPT_PRINT_DIRS;
            പോകുക extra_action;
        അവസ്ഥ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            പോകുക extra_action;
        അവസ്ഥ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            എങ്കിൽ (ശൂന്യ == argv[0]) /* from tcc_set_options() */
                തിരികെ -1;
            എങ്കിൽ (!empty && x)
                തിരികെ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            തിരികെ x;
        സ്ഥിരസ്ഥിതി:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            നിർത്തുക;
        }
        empty = 0;
    }
    എങ്കിൽ (s->link_optind < s->link_argc)
        തിരികെ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    എങ്കിൽ (run) {
        എങ്കിൽ (*run && tcc_set_options(s, run) < 0)
            തിരികെ -1;
        x = 0, r = 0;
        പോകുക extra_action;
    }
    എങ്കിൽ (!empty)
        തിരികെ 0;
    എങ്കിൽ (s->verbose == 2)
        തിരികെ OPT_PRINT_DIRS;
    എങ്കിൽ (s->verbose)
        തിരികെ OPT_V;
    തിരികെ OPT_HELP;
}

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_set_options(TCCState *s, സ്ഥിരം അക്ഷരം *r)
{
    അക്ഷരം **argv = ശൂന്യ;
    പൂർണ്ണസംഖ്യ argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    തിരികെ ret;
}

PUB_FUNC ശൂന്യം tcc_print_stats(TCCState *s1, unsigned total_time)
{
    എങ്കിൽ (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_വരികൾ, total_bytes,
           (ഇരട്ട)total_time/1000,
           (unsigned)total_വരികൾ*1000/total_time,
           (ഇരട്ട)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    എങ്കിൽ (s1->run_size) {
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
