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

#ಯದಿ ONE_SOURCE
#ಅನ್ತರ್ಭಾವ "tccpp.c"
#ಅನ್ತರ್ಭಾವ "tccgen.c"
#ಅನ್ತರ್ಭಾವ "tccdbg.c"
#ಅನ್ತರ್ಭಾವ "tccasm.c"
#ಅನ್ತರ್ಭಾವ "tccelf.c"
#ಅನ್ತರ್ಭಾವ "tccrun.c"
#ifdef TCC_TARGET_I386
#ಅನ್ತರ್ಭಾವ "i386-gen.c"
#ಅನ್ತರ್ಭಾವ "i386-link.c"
#ಅನ್ತರ್ಭಾವ "i386-asm.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM)
#ಅನ್ತರ್ಭಾವ "arm-gen.c"
#ಅನ್ತರ್ಭಾವ "arm-link.c"
#ಅನ್ತರ್ಭಾವ "arm-asm.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_ARM64)
#ಅನ್ತರ್ಭಾವ "arm64-gen.c"
#ಅನ್ತರ್ಭಾವ "arm64-link.c"
#ಅನ್ತರ್ಭಾವ "arm64-asm.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_C67)
#ಅನ್ತರ್ಭಾವ "c67-gen.c"
#ಅನ್ತರ್ಭಾವ "c67-link.c"
#ಅನ್ತರ್ಭಾವ "tcccoff.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_X86_64)
#ಅನ್ತರ್ಭಾವ "x86_64-gen.c"
#ಅನ್ತರ್ಭಾವ "x86_64-link.c"
#ಅನ್ತರ್ಭಾವ "i386-asm.c"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_RISCV64)
#ಅನ್ತರ್ಭಾವ "riscv64-gen.c"
#ಅನ್ತರ್ಭಾವ "riscv64-link.c"
#ಅನ್ತರ್ಭಾವ "riscv64-asm.c"
#ಅನ್ಯಥಾ
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#ಅನ್ತರ್ಭಾವ "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#ಅನ್ತರ್ಭಾವ "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#ಅನ್ತರ್ಭಾವ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA ಸಂರಚನಾ TCCState *tcc_state;
TCC_SEM(ಸ್ಥಿರ tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA ಶೂನ್ಯ** stk_data;
ST_DATA ಪೂರ್ಣಾಙ್ಕ nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA ಪೂರ್ಣಾಙ್ಕ g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC ವರ್ಣ *normalize_slashes(ವರ್ಣ *path)
{
    ವರ್ಣ *p;
    ಪ್ರತಿ (p = path; *p; ++p)
        ಯದಿ (*p == '\\')
            *p = '/';
    ಪ್ರತ್ಯಾಗಮ path;
}

#ಯದಿ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ಸ್ಥಿರ HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ಯದಿ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    ಪ್ರತ್ಯಾಗಮ TRUE;
}
#ಅನ್ಯಥಾ
#define tcc_module ರಿಕ್ತ /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ವರ್ಣ *config_tccdir_w32(ವರ್ಣ *path)
{
    ವರ್ಣ *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    ಯದಿ (p > path)
        --p;
    *p = 0;
    ಪ್ರತ್ಯಾಗಮ path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
ಸ್ಥಿರ ಶೂನ್ಯ tcc_add_systemdir(TCCState *s)
{
    ವರ್ಣ buf[1000];
    GetSystemDirectoryA(buf, ಪರಿಮಾಣ buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ಧ್ರುವ ವರ್ಣ *f, ಧ್ರುವ ವರ್ಣ *m) {
    ಪ್ರತ್ಯಾಗಮ fopen(f, m);
}
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_fclose(FILE *f) {
    ಪ್ರತ್ಯಾಗಮ fclose(f);
}
#endif
/********************************************************/

PUB_FUNC ಶೂನ್ಯ tcc_enter_state(TCCState *s1)
{
    ಯದಿ (s1->error_set_jmp_enabled)
        ಪ್ರತ್ಯಾಗಮ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC ಶೂನ್ಯ tcc_exit_state(TCCState *s1)
{
    ಯದಿ (s1->error_set_jmp_enabled)
        ಪ್ರತ್ಯಾಗಮ;
    tcc_state = ರಿಕ್ತ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC ವರ್ಣ *pstrcpy(ವರ್ಣ *buf, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s)
{
    ವರ್ಣ *q, *q_end;
    ಪೂರ್ಣಾಙ್ಕ c;

    ಯದಿ (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        ಯಾವತ್ (q < q_end) {
            c = *s++;
            ಯದಿ (c == '\0')
                ಭಙ್ಗ;
            *q++ = c;
        }
        *q = '\0';
    }
    ಪ್ರತ್ಯಾಗಮ buf;
}

/* strcat and truncate. */
ST_FUNC ವರ್ಣ *pstrcat(ವರ್ಣ *buf, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s)
{
    size_t len;
    len = strlen(buf);
    ಯದಿ (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    ಪ್ರತ್ಯಾಗಮ buf;
}

ST_FUNC ವರ್ಣ *pstrncpy(ವರ್ಣ *out, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s, size_t ಅಂಕೆ)
{
    ಯದಿ (ಅಂಕೆ >= buf_size)
        ಅಂಕೆ = buf_size - 1;
    memcpy(out, s, ಅಂಕೆ);
    out[ಅಂಕೆ] = '\0';
    ಪ್ರತ್ಯಾಗಮ out;
}

/* extract the basename of a file */
PUB_FUNC ವರ್ಣ *tcc_basename(ಧ್ರುವ ವರ್ಣ *name)
{
    ವರ್ಣ *p = (ವರ್ಣ *)strchr(name, 0);
    ಯಾವತ್ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    ಪ್ರತ್ಯಾಗಮ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC ವರ್ಣ *tcc_fileextension (ಧ್ರುವ ವರ್ಣ *name)
{
    ವರ್ಣ *b = tcc_basename(name);
    ವರ್ಣ *e = strrchr(b, '.');
    ಪ್ರತ್ಯಾಗಮ e ? e : strchr(b, 0);
}

ST_FUNC ವರ್ಣ *tcc_load_text(ಪೂರ್ಣಾಙ್ಕ fd)
{
    ಪೂರ್ಣಾಙ್ಕ len = lseek(fd, 0, SEEK_END);
    ವರ್ಣ *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    ಪ್ರತ್ಯಾಗಮ buf;
}

/* replace *pp by copy of 'str' or NULL */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_set_str(ವರ್ಣ **pp, ಧ್ರುವ ವರ್ಣ *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ರಿಕ್ತ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_concat_str(ವರ್ಣ **pp, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ sep)
{
    ಪೂರ್ಣಾಙ್ಕ l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    ಯದಿ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef ಮುಕ್ತ
#undef realloc

ಸ್ಥಿರ ಶೂನ್ಯ *default_reallocator(ಶೂನ್ಯ *ptr, unsigned long size)
{
    ಶೂನ್ಯ *ptr1;
    ಯದಿ (size == 0) {
        ಮುಕ್ತ(ptr);
        ptr1 = ರಿಕ್ತ;
    }
    ಅನ್ಯಥಾ {
        ptr1 = realloc(ptr, size);
        ಯದಿ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    ಪ್ರತ್ಯಾಗಮ ptr1;
}

ST_FUNC ಶೂನ್ಯ libc_free(ಶೂನ್ಯ *ptr)
{
    ಮುಕ್ತ(ptr);
}

/* defined to be not used */
#define ಮುಕ್ತ(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ಸ್ಥಿರ ಶೂನ್ಯ *(*reallocator)(ಶೂನ್ಯ*, unsigned long) = default_reallocator;

LIBTCCAPI ಶೂನ್ಯ tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC ಶೂನ್ಯ tcc_free(ಶೂನ್ಯ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC ಶೂನ್ಯ *tcc_malloc(unsigned long size)
{
    ಪ್ರತ್ಯಾಗಮ reallocator(0, size);
}

PUB_FUNC ಶೂನ್ಯ *tcc_realloc(ಶೂನ್ಯ *ptr, unsigned long size)
{
    ಪ್ರತ್ಯಾಗಮ reallocator(ptr, size);
}

PUB_FUNC ಶೂನ್ಯ *tcc_mallocz(unsigned long size)
{
    ಶೂನ್ಯ *ptr;
    ptr = tcc_malloc(size);
    ಯದಿ (size)
        memset(ptr, 0, size);
    ಪ್ರತ್ಯಾಗಮ ptr;
}

PUB_FUNC ವರ್ಣ *tcc_strdup(ಧ್ರುವ ವರ್ಣ *str)
{
    ವರ್ಣ *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    ಪ್ರತ್ಯಾಗಮ ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned ವರ್ಣ *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((ವರ್ಣ *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((ವರ್ಣ*)ptr - offsetof(mem_debug_header_t, magic3))

ಸಂರಚನಾ mem_debug_header {
    unsigned magic1;
    unsigned size;
    ಸಂರಚನಾ mem_debug_header *prev;
    ಸಂರಚನಾ mem_debug_header *next;
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_ಅಂಕೆ;
    ವರ್ಣ file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned ವರ್ಣ magic3[4];
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ mem_debug_header mem_debug_header_t;

TCC_SEM(ಸ್ಥಿರ mem_sem);
ಸ್ಥಿರ mem_debug_header_t *mem_debug_chain;
ಸ್ಥಿರ unsigned mem_cur_size;
ಸ್ಥಿರ unsigned mem_max_size;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ nb_states;

ಸ್ಥಿರ mem_debug_header_t *malloc_check(ಶೂನ್ಯ *ptr, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    ಯದಿ (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", ಸಂದೇಶ);
        ಯದಿ (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->ಸಾಲು_ಅಂಕೆ);
        exit(1);
    }
    ಪ್ರತ್ಯಾಗಮ header;
}

PUB_FUNC ಶೂನ್ಯ *tcc_malloc_debug(unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು)
{
    ಪೂರ್ಣಾಙ್ಕ ofs;
    mem_debug_header_t *header;
    ಯದಿ (!size)
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    header = tcc_malloc(ಪರಿಮಾಣ(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->ಸಾಲು_ಅಂಕೆ = ಸಾಲು;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = ರಿಕ್ತ;
    ಯದಿ (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    ಯದಿ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ಪ್ರತ್ಯಾಗಮ MEM_USER_PTR(header);
}

PUB_FUNC ಶೂನ್ಯ tcc_free_debug(ಶೂನ್ಯ *ptr)
{
    mem_debug_header_t *header;
    ಯದಿ (!ptr)
        ಪ್ರತ್ಯಾಗಮ;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    ಯದಿ (header->next)
        header->next->prev = header->prev;
    ಯದಿ (header->prev)
        header->prev->next = header->next;
    ಯದಿ (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC ಶೂನ್ಯ *tcc_mallocz_debug(unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು)
{
    ಶೂನ್ಯ *ptr;
    ptr = tcc_malloc_debug(size,file,ಸಾಲು);
    ಯದಿ (size)
        memset(ptr, 0, size);
    ಪ್ರತ್ಯಾಗಮ ptr;
}

PUB_FUNC ಶೂನ್ಯ *tcc_realloc_debug(ಶೂನ್ಯ *ptr, unsigned long size, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು)
{
    mem_debug_header_t *header;
    ಪೂರ್ಣಾಙ್ಕ mem_debug_chain_update = 0;

    ಯದಿ (!ptr)
        ಪ್ರತ್ಯಾಗಮ tcc_malloc_debug(size, file, ಸಾಲು);
    ಯದಿ (!size) {
        tcc_free_debug(ptr);
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, ಪರಿಮಾಣ(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    ಯದಿ (header->next)
        header->next->prev = header;
    ಯದಿ (header->prev)
        header->prev->next = header;
    ಯದಿ (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    ಯದಿ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ಪ್ರತ್ಯಾಗಮ MEM_USER_PTR(header);
}

PUB_FUNC ವರ್ಣ *tcc_strdup_debug(ಧ್ರುವ ವರ್ಣ *str, ಧ್ರುವ ವರ್ಣ *file, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು)
{
    ವರ್ಣ *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, ಸಾಲು);
    strcpy(ptr, str);
    ಪ್ರತ್ಯಾಗಮ ptr;
}

PUB_FUNC ಶೂನ್ಯ tcc_memcheck(ಪೂರ್ಣಾಙ್ಕ d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    ಯದಿ (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        ಯಾವತ್ (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->ಸಾಲು_ಅಂಕೆ, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = ರಿಕ್ತ;
#ಯದಿ MEM_DEBUG-0 == 2
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
ST_FUNC ಪೂರ್ಣಾಙ್ಕ normalized_PATHCMP(ಧ್ರುವ ವರ್ಣ *f1, ಧ್ರುವ ವರ್ಣ *f2)
{
    ವರ್ಣ *p1, *p2;
    ಪೂರ್ಣಾಙ್ಕ ret = 1;
    ಯದಿ (!!(p1 = realpath(f1, ರಿಕ್ತ))) {
        ಯದಿ (!!(p2 = realpath(f2, ರಿಕ್ತ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    ಪ್ರತ್ಯಾಗಮ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC ಶೂನ್ಯ dynarray_add(ಶೂನ್ಯ *ptab, ಪೂರ್ಣಾಙ್ಕ *nb_ptr, ಶೂನ್ಯ *data)
{
    ಪೂರ್ಣಾಙ್ಕ nb, nb_alloc;
    ಶೂನ್ಯ **pp;

    nb = *nb_ptr;
    pp = *(ಶೂನ್ಯ ***)ptab;
    /* every power of two we double array size */
    ಯದಿ ((nb & (nb - 1)) == 0) {
        ಯದಿ (!nb)
            nb_alloc = 1;
        ಅನ್ಯಥಾ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * ಪರಿಮಾಣ(ಶೂನ್ಯ *));
        *(ಶೂನ್ಯ***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC ಶೂನ್ಯ dynarray_reset(ಶೂನ್ಯ *pp, ಪೂರ್ಣಾಙ್ಕ *n)
{
    ಶೂನ್ಯ **p;
    ಪ್ರತಿ (p = *(ಶೂನ್ಯ***)pp; *n; ++p, --*n)
        ಯದಿ (*p)
            tcc_free(*p);
    tcc_free(*(ಶೂನ್ಯ**)pp);
    *(ಶೂನ್ಯ**)pp = ರಿಕ್ತ;
}

ಸ್ಥಿರ ಶೂನ್ಯ dynarray_split(ವರ್ಣ ***argv, ಪೂರ್ಣಾಙ್ಕ *argc, ಧ್ರುವ ವರ್ಣ *p, ಪೂರ್ಣಾಙ್ಕ sep)
{
    ಪೂರ್ಣಾಙ್ಕ qot, c;
    CString str;
    ಪ್ರತಿ(;;) {
        ಯಾವತ್ (c = (unsigned ವರ್ಣ)*p, c <= ' ' && c != '\0')
            ++p;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        cstr_new(&str);
        qot = 0;
        ಕುರು {
            ++p;
            ಯದಿ (sep) { /* e.g. to split -Wl,-opt,arg */
                ಯದಿ (c == sep)
                    ಭಙ್ಗ;
            } ಅನ್ಯಥಾ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ಯದಿ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ಅನ್ಯಥಾ ಯದಿ (c == '"') {
                    qot ^= 1;
                    ಅನುವರ್ತ;
                } ಅನ್ಯಥಾ ಯದಿ (c <= ' ' && !qot) {
                    ಭಙ್ಗ;
                }
            }
            cstr_ccat(&str, c);
        } ಯಾವತ್ (c = (unsigned ವರ್ಣ)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_split_path(TCCState *s, ಶೂನ್ಯ *p_ary, ಪೂರ್ಣಾಙ್ಕ *p_nb_ary, ಧ್ರುವ ವರ್ಣ *in)
{
    ಧ್ರುವ ವರ್ಣ *p;
    ಕುರು {
        ಪೂರ್ಣಾಙ್ಕ c;
        CString str;

        cstr_new(&str);
        ಪ್ರತಿ (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ಯದಿ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ಯದಿ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                ಯದಿ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ಯದಿ (c == 'f' && file) {
                    /* substitute current file's dir */
                    ಧ್ರುವ ವರ್ಣ *f = file->true_filename;
                    ಧ್ರುವ ವರ್ಣ *b = tcc_basename(f);
                    ಯದಿ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ಅನ್ಯಥಾ
                        cstr_cat(&str, ".", 1);
                }
            } ಅನ್ಯಥಾ {
                cstr_ccat(&str, c);
            }
        }
        ಯದಿ (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } ಯಾವತ್ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ಗಣನಾ { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ಸ್ಥಿರ ಶೂನ್ಯ error1(ಪೂರ್ಣಾಙ್ಕ mode, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು = 0;

    tcc_exit_state(s1);

    ಯದಿ (mode == ERROR_WARN) {
        ಯದಿ (s1->warn_error)
            mode = ERROR_ERROR;
        ಯದಿ (s1->warn_ಅಂಕೆ) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            ಪೂರ್ಣಾಙ್ಕ wopt = *(&s1->warn_none + s1->warn_ಅಂಕೆ);
            s1->warn_ಅಂಕೆ = 0;
            ಯದಿ (0 == (wopt & WARN_ON))
                ಪ್ರತ್ಯಾಗಮ;
            ಯದಿ (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            ಯದಿ (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        ಯದಿ (s1->warn_none)
            ಪ್ರತ್ಯಾಗಮ;
    }

    cstr_new(&cs);
    ಯದಿ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        ಸಾಲು = va_arg(ap, ಪೂರ್ಣಾಙ್ಕ), fmt += 3;
    f = ರಿಕ್ತ;
    ಯದಿ (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        ಪ್ರತಿ (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ಯದಿ (f) {
        ಪ್ರತಿ(pf = s1->include_ರಾಶಿ; pf < s1->include_ರಾಶಿ_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->ಸಾಲು_ಅಂಕೆ - 1);
        ಯದಿ (0 == ಸಾಲು)
            ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, ಸಾಲು);
    } ಅನ್ಯಥಾ ಯದಿ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ಅನ್ಯಥಾ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    ಯದಿ (pp_ಅಭಿವ್ಯಕ್ತಿ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ಅನ್ಯಥಾ
        cstr_vprintf(&cs, fmt, ap);
    ಯದಿ (!s1->error_func) {
        /* default case: stderr */
        ಯದಿ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (ವರ್ಣ*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } ಅನ್ಯಥಾ {
        s1->error_func(s1->error_opaque, (ವರ್ಣ*)cs.data);
    }
    cstr_free(&cs);
    ಯದಿ (mode != ERROR_WARN)
        s1->nb_errors++;
    ಯದಿ (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        ಯಾವತ್ (nb_stk_data)
            tcc_free(*(ಶೂನ್ಯ**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI ಶೂನ್ಯ tcc_set_error_func(TCCState *s, ಶೂನ್ಯ *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ _tcc_error_noabort(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    ಪ್ರತ್ಯಾಗಮ -1;
}

#undef _tcc_error
PUB_FUNC ಶೂನ್ಯ _tcc_error(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC ಶೂನ್ಯ _tcc_warning(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC ಶೂನ್ಯ tcc_open_bf(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ initlen)
{
    BufferedFile *bf;
    ಪೂರ್ಣಾಙ್ಕ buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(ಪರಿಮಾಣ(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, ಪರಿಮಾಣ(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->ಸಾಲು_ಅಂಕೆ = 1;
    bf->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC ಶೂನ್ಯ tcc_close(ಶೂನ್ಯ)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ಯದಿ (bf->fd > 0) {
        close(bf->fd);
        total_ಸಾಲುಗಳು += bf->ಸಾಲು_ಅಂಕೆ - 1;
    }
    ಯದಿ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ _tcc_open(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪೂರ್ಣಾಙ್ಕ fd;
    ಯದಿ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ಅನ್ಯಥಾ
        fd = open(filename, O_RDONLY | O_ದ್ವಿಮಾನ_2);
    ಯದಿ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (ಪೂರ್ಣಾಙ್ಕ)(s1->include_ರಾಶಿ_ptr - s1->include_ರಾಶಿ), "", filename);
    ಪ್ರತ್ಯಾಗಮ fd;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_open(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪೂರ್ಣಾಙ್ಕ fd = _tcc_open(s1, filename);
    ಯದಿ (fd < 0)
        ಪ್ರತ್ಯಾಗಮ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_compile(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ filetype, ಧ್ರುವ ವರ್ಣ *str, ಪೂರ್ಣಾಙ್ಕ fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    ಯದಿ (setjmp(s1->error_jmp_buf) == 0) {

        ಯದಿ (fd == -1) {
            ಪೂರ್ಣಾಙ್ಕ len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } ಅನ್ಯಥಾ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        ಯದಿ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ಅನ್ಯಥಾ {
            tccelf_begin_file(s1);
            ಯದಿ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ಅನ್ಯಥಾ {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    ಪ್ರತ್ಯಾಗಮ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_compile_string(TCCState *s, ಧ್ರುವ ವರ್ಣ *str)
{
    ಪ್ರತ್ಯಾಗಮ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ಶೂನ್ಯ tcc_define_ಚಿಹ್ನೆ(TCCState *s1, ಧ್ರುವ ವರ್ಣ *sym, ಧ್ರುವ ವರ್ಣ *ಮೌಲ್ಯ)
{
    ಧ್ರುವ ವರ್ಣ *eq;
    ಯದಿ (ರಿಕ್ತ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ಯದಿ (ರಿಕ್ತ == ಮೌಲ್ಯ)
        ಮೌಲ್ಯ = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (ಪೂರ್ಣಾಙ್ಕ)(eq-sym), sym, ಮೌಲ್ಯ);
}

/* undefine a preprocessor symbol */
LIBTCCAPI ಶೂನ್ಯ tcc_undefine_ಚಿಹ್ನೆ(TCCState *s1, ಧ್ರುವ ವರ್ಣ *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(ಶೂನ್ಯ)
{
    TCCState *s;

    s = tcc_mallocz(ಪರಿಮಾಣ(TCCState));
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
#ಯದಿ defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#ಯದಿ defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ರಾಶಿ_ptr = s->include_ರಾಶಿ;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    ಪ್ರತ್ಯಾಗಮ s;
}

LIBTCCAPI ಶೂನ್ಯ tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_ಚಿಹ್ನೆ);
    tcc_free(s1->fini_ಚಿಹ್ನೆ);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ಯದಿ defined TCC_TARGET_MACHO
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

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_set_output_type(TCCState *s, ಪೂರ್ಣಾಙ್ಕ output_type)
{
#ifdef CONFIG_TCC_PIE
    ಯದಿ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    ಯದಿ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ಯದಿ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        ಪ್ರತ್ಯಾಗಮ 0;
    }

    /* add sections */
    tccelf_new(s);

    ಯದಿ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        ಪ್ರತ್ಯಾಗಮ 0;
    }

    ಯದಿ (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#ಅನ್ಯಥಾ
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ಯದಿ (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    ಪ್ರತ್ಯಾಗಮ s->nb_errors ? -1 : 0;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_include_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    ಪ್ರತ್ಯಾಗಮ 0;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_sysinclude_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    ಪ್ರತ್ಯಾಗಮ 0;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_library_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    ಪ್ರತ್ಯಾಗಮ 0;
}

LIBTCCAPI ಶೂನ್ಯ tcc_set_lib_path(TCCState *s, ಧ್ರುವ ವರ್ಣ *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ಧ್ರುವ ವರ್ಣ *dllname, ಪೂರ್ಣಾಙ್ಕ level)
{
    DLLReference *ref = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < s1->nb_loaded_dlls; i++)
        ಯದಿ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ಭಙ್ಗ;
        }
    ಯದಿ (level == -1)
        ಪ್ರತ್ಯಾಗಮ ref;
    ಯದಿ (ref) {
        ಯದಿ (level < ref->level)
            ref->level = level;
        ref->found = 1;
        ಪ್ರತ್ಯಾಗಮ ref;
    }
    ref = tcc_mallocz(ಪರಿಮಾಣ(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    ಪ್ರತ್ಯಾಗಮ ref;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_add_ದ್ವಿಮಾನ(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ flags, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ fd)
{
    ElfW(Ehdr) ehdr;
    ಪೂರ್ಣಾಙ್ಕ obj_type;
    ಧ್ರುವ ವರ್ಣ *saved_filename = s1->current_filename;
    ಪೂರ್ಣಾಙ್ಕ ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    ವಿಕಲ್ಪ (obj_type) {

    ಪಕ್ಷ AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        ಭಙ್ಗ;

    ಪಕ್ಷ AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        ಭಙ್ಗ;

#ಯದಿ defined TCC_TARGET_UNIX
    ಪಕ್ಷ AFF_BINTYPE_DYN:
        ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ಶೂನ್ಯ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ಯದಿ (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            ಅನ್ಯಥಾ
                ret = FILE_NOT_RECOGNIZED;
#endif
        } ಅನ್ಯಥಾ
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ಭಙ್ಗ;

    ಸ್ವಭಾವ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        ಭಙ್ಗ;

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_MACHO
    ಪಕ್ಷ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ಯದಿ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ಶೂನ್ಯ* dl;
            ಧ್ರುವ ವರ್ಣ* soname = filename;
            ವರ್ಣ *tmp = 0;
            ಯದಿ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ಯದಿ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ಯದಿ (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            ಅನ್ಯಥಾ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } ಅನ್ಯಥಾ ಯದಿ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ಅನ್ಯಥಾ {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ಯದಿ (ret)
            ret = FILE_NOT_RECOGNIZED;
        ಭಙ್ಗ;

    ಸ್ವಭಾವ:
    {
        ಧ್ರುವ ವರ್ಣ *ext = tcc_fileextension(filename);
        ಯದಿ (!strcmp(ext, ".tbd"))
            ಗಚ್ಛ case_dyn_or_tbd;
        ಯದಿ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            ಗಚ್ಛ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ಭಙ್ಗ;
    }

#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_PE
    ಸ್ವಭಾವ:
        ಯದಿ (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ಭಙ್ಗ;
#endif

#ifdef TCC_TARGET_COFF
    ಪಕ್ಷ AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        ಭಙ್ಗ;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    ಯದಿ (ret == FILE_NOT_RECOGNIZED)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("%s: unrecognized file type", filename);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ಯದಿ defined TARGETOS_OpenBSD && !defined _WIN32
#ಅನ್ತರ್ಭಾವ <glob.h>
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_glob_so(TCCState *s1, ಧ್ರುವ ವರ್ಣ *pattern, ವರ್ಣ *buf, ಪೂರ್ಣಾಙ್ಕ size)
{
    ಧ್ರುವ ವರ್ಣ *star;
    glob_t g;
    ವರ್ಣ *p;
    ಪೂರ್ಣಾಙ್ಕ i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    ಯದಿ (!star || glob(pattern, 0, ರಿಕ್ತ, &g))
        ಪ್ರತ್ಯಾಗಮ -1;
    ಪ್ರತಿ (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ಯದಿ (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            ಅನುವರ್ತ;
        ಯದಿ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    ಪ್ರತ್ಯಾಗಮ v;
}
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ guess_filetype(ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪೂರ್ಣಾಙ್ಕ filetype = 0;
    ಯದಿ (1) {
        /* use a file extension to detect a filetype */
        ಧ್ರುವ ವರ್ಣ *ext = tcc_fileextension(filename);
        ಯದಿ (ext[0]) {
            ext++;
            ಯದಿ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ಅನ್ಯಥಾ ಯದಿ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ಅನ್ಯಥಾ ಯದಿ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ಅನ್ಯಥಾ
                filetype |= AFF_TYPE_BIN;
        } ಅನ್ಯಥಾ {
            filetype = AFF_TYPE_C;
        }
    }
    ಪ್ರತ್ಯಾಗಮ filetype;
}

ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_file_internal(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flags)
{
    ಪೂರ್ಣಾಙ್ಕ fd;

#ಯದಿ defined TARGETOS_OpenBSD && !defined _WIN32
    ವರ್ಣ buf[1024];
    ಯದಿ (tcc_glob_so(s1, filename, buf, ಪರಿಮಾಣ buf) >= 0)
        filename = buf;
#endif

    ಯದಿ (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ಯದಿ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        ಪ್ರತ್ಯಾಗಮ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ಯದಿ (fd < 0) {
        ಯದಿ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        ಪ್ರತ್ಯಾಗಮ FILE_NOT_FOUND;
    }

    ಯದಿ (flags & AFF_TYPE_BIN)
        ಪ್ರತ್ಯಾಗಮ tcc_add_ದ್ವಿಮಾನ(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    ಪ್ರತ್ಯಾಗಮ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_file(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪ್ರತ್ಯಾಗಮ tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_add_library_internal(TCCState *s1, ಧ್ರುವ ವರ್ಣ *fmt,
    ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flags, ವರ್ಣ **paths, ಪೂರ್ಣಾಙ್ಕ nb_paths)
{
    ವರ್ಣ buf[1024];
    ಪೂರ್ಣಾಙ್ಕ i, ret;

    ಪ್ರತಿ(i = 0; i < nb_paths; i++) {
        snprintf(buf, ಪರಿಮಾಣ(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        ಯದಿ (ret != FILE_NOT_FOUND)
            ಪ್ರತ್ಯಾಗಮ ret;
    }
    ಯದಿ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    ಪ್ರತ್ಯಾಗಮ FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_dll(TCCState *s, ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flags)
{
    ಪ್ರತ್ಯಾಗಮ tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_support(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ವರ್ಣ buf[100];
    ಯದಿ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    ಪ್ರತ್ಯಾಗಮ tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_add_crt(TCCState *s1, ಧ್ರುವ ವರ್ಣ *filename)
{
    ಪ್ರತ್ಯಾಗಮ tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_add_library(TCCState *s, ಧ್ರುವ ವರ್ಣ *libraryname)
{
    ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ libs[] = {
#ಯದಿ defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#ನೋಚೇದ್ಯದಿ defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ಅನ್ಯಥಾ
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        ರಿಕ್ತ
    };
    ಪೂರ್ಣಾಙ್ಕ flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ಯದಿ (*libraryname == ':') {
        libraryname++;
    } ಅನ್ಯಥಾ {
        ಧ್ರುವ ವರ್ಣ * ಧ್ರುವ *pp = libs;
        ಯದಿ (s->static_link)
            pp += ಪರಿಮಾಣ(libs) / ಪರಿಮಾಣ(*libs) - 2; /* only "%s/lib%s.a" */
        ಯಾವತ್ (*pp) {
            ಪೂರ್ಣಾಙ್ಕ ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ಯದಿ (ret != FILE_NOT_FOUND)
                ಪ್ರತ್ಯಾಗಮ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    ಪ್ರತ್ಯಾಗಮ tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC ಶೂನ್ಯ tcc_add_pragma_libs(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ strstart(ಧ್ರುವ ವರ್ಣ *val, ಧ್ರುವ ವರ್ಣ **str)
{
    ಧ್ರುವ ವರ್ಣ *p, *q;
    p = *str;
    q = val;
    ಯಾವತ್ (*q) {
        ಯದಿ (*p != *q)
            ಪ್ರತ್ಯಾಗಮ 0;
        p++;
        q++;
    }
    *str = p;
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಸಂರಚನಾ lopt {
    TCCState *s;
    ಧ್ರುವ ವರ್ಣ *opt, *arg;
    ಪೂರ್ಣಾಙ್ಕ match;
};

/* match linker option */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ link_option(ಸಂರಚನಾ lopt *o, ಧ್ರುವ ವರ್ಣ *q)
{
    ಧ್ರುವ ವರ್ಣ *p;
    ಪೂರ್ಣಾಙ್ಕ c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ಯದಿ (*p++ != '-')
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (*p == '-')
        p++;
    r = 1;
    ಯದಿ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ಯದಿ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        ಅನ್ಯಥಾ ಯದಿ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    ಯಾವತ್ ((c = *q) == *p) {
        ಯದಿ (c == '\0')
            ಗಚ್ಛ succ; /* -Wl,-opt */
        ++p;
        ಯದಿ (c == '=')
            ಗಚ್ಛ succ; /* -Wl,-opt=arg */
        ++q;
    }
    ಯದಿ (*p == '\0') {
        ಯದಿ (c == '|')
            ಗಚ್ಛ succ;
        ಯದಿ (c == '=' || c == ':') {
            ಯದಿ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                ಗಚ್ಛ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            ಪ್ರತ್ಯಾಗಮ 0;
        }
    } ಅನ್ಯಥಾ ಯದಿ (c == ':')
        ಗಚ್ಛ succ; /* -Wl,-Iarg */
    ಯಾವತ್ (*q)
        ಯದಿ (*q++ == '|')
            ಗಚ್ಛ redo;
    ಪ್ರತ್ಯಾಗಮ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    ಪ್ರತ್ಯಾಗಮ r;
}

ಸ್ಥಿರ ಶೂನ್ಯ args_parser_add_file(TCCState *s, ಧ್ರುವ ವರ್ಣ* filename, ಪೂರ್ಣಾಙ್ಕ filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_set_linker(TCCState *s, ಧ್ರುವ ವರ್ಣ *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    ಯಾವತ್ (s->link_optind < s->link_argc) {
        ವರ್ಣ *end = ರಿಕ್ತ;
        ಪೂರ್ಣಾಙ್ಕ ignoring = 0;
        ಸಂರಚನಾ lopt o = {0};
        ಪೂರ್ಣಾಙ್ಕ r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ಯದಿ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "init=")) {
            tcc_set_str(&s->init_ಚಿಹ್ನೆ, o.arg);
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_ಚಿಹ್ನೆ, o.arg);
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "oformat=")) {
#ಯದಿ defined TCC_TARGET_PE
            ಯದಿ (0 == strncmp("pe-", o.arg, 3))
#ನೋಚೇದ್ಯದಿ PTR_SIZE == 8
            ಯದಿ (0 == strncmp("elf64-", o.arg, 6))
#ಅನ್ಯಥಾ
            ಯದಿ (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ಅನ್ಯಥಾ ಯದಿ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ;
#ಯದಿ defined TCC_TARGET_COFF
            ಅನ್ಯಥಾ ಯದಿ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            ಅನ್ಯಥಾ
                ಗಚ್ಛ err;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } ಅನ್ಯಥಾ ಯದಿ (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ಅನ್ಯಥಾ ಯದಿ (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ಅನ್ಯಥಾ ಯದಿ (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ಅನ್ಯಥಾ ಯದಿ (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ಅನ್ಯಥಾ ಯದಿ (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "stack=")) {
            s->pe_ರಾಶಿ_size = strtoul(o.arg, &end, 10);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "subsystem=")) {
            ಯದಿ (pe_setsubsy(s, o.arg) < 0)
                ಗಚ್ಛ err;
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_MACHO
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "O")) {
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "z=")) {
            ignoring = 1;
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } ಅನ್ಯಥಾ ಯದಿ (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } ಅನ್ಯಥಾ ಯದಿ (o.match) {
            ಪ್ರತ್ಯಾಗಮ 0; /* expecting argument with next '-Wl,' */
        } ಅನ್ಯಥಾ {
    err:
            ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ಯದಿ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TCCOption {
    ಧ್ರುವ ವರ್ಣ *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

ಗಣನಾ {
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
    TCC_OPTION_print_ಹುಡುಕು_dirs,
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

ಸ್ಥಿರ ಧ್ರುವ TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_ಹುಡುಕು_dirs, 0 },
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
    { ರಿಕ್ತ, 0, 0 },
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ FlagDef {
    uint16_t offset;
    uint16_t flags;
    ಧ್ರುವ ವರ್ಣ *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

ಸ್ಥಿರ ಧ್ರುವ FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ರಿಕ್ತ }
};

ಸ್ಥಿರ ಧ್ರುವ FlagDef options_f[] = {
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
    { 0, 0, ರಿಕ್ತ }
};

ಸ್ಥಿರ ಧ್ರುವ FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, ರಿಕ್ತ }
};

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ set_flag(TCCState *s, ಧ್ರುವ FlagDef *flags, ಧ್ರುವ ವರ್ಣ *name)
{
    ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ, mask, ret;
    ಧ್ರುವ FlagDef *p;
    ಧ್ರುವ ವರ್ಣ *r;
    unsigned ವರ್ಣ *f;

    r = name, ಮೌಲ್ಯ = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ಯದಿ ((flags->flags & WD_ALL) && strstart("error=", &r))
        ಮೌಲ್ಯ = ಮೌಲ್ಯ ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    ಪ್ರತಿ (ret = -1, p = flags; p->name; ++p) {
        ಯದಿ (ret) {
            ಯದಿ (strcmp(r, p->name))
                ಅನುವರ್ತ;
        } ಅನ್ಯಥಾ {
            ಯದಿ (0 == (p->flags & WD_ALL))
                ಅನುವರ್ತ;
        }

        f = (unsigned ವರ್ಣ *)s + p->offset;
        *f = (*f & mask) | (ಮೌಲ್ಯ ^ !!(p->flags & FD_INVERT));

        ಯದಿ (ret) {
            ret = 0;
            ಯದಿ (strcmp(r, "all"))
                ಭಙ್ಗ;
        }
    }
    ಪ್ರತ್ಯಾಗಮ ret;
}

ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_X86_64
    "x86_64-pc"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_C67
    "c67"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM
    "arm"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_ARM64
    "aarch64"
#ನೋಚೇದ್ಯದಿ defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#ನೋಚೇದ್ಯದಿ defined(TCC_TARGET_MACHO)
    "apple-darwin"
#ನೋಚೇದ್ಯದಿ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#ನೋಚೇದ್ಯದಿ TARGETOS_OpenBSD
    "openbsd"
#ನೋಚೇದ್ಯದಿ TARGETOS_NetBSD
    "netbsd"
#ನೋಚೇದ್ಯದಿ CONFIG_TCC_MUSL
    "linux-musl"
#ಅನ್ಯಥಾ
    "linux-gnu"
#endif
;

#ಯದಿ defined TCC_TARGET_MACHO
ಸ್ಥಿರ uint32_t parse_version(TCCState *s1, ಧ್ರುವ ವರ್ಣ *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    ವರ್ಣ* last;

    a = strtoul(version, &last, 10);
    ಯದಿ (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        ಯದಿ (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    ಯದಿ (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    ಪ್ರತ್ಯಾಗಮ (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ಸ್ಥಿರ ಶೂನ್ಯ ಸೇರಿಸು_args(TCCState *s1, ವರ್ಣ ***pargv, ಪೂರ್ಣಾಙ್ಕ *pargc, ಪೂರ್ಣಾಙ್ಕ optind, ಧ್ರುವ ವರ್ಣ *p, ಪೂರ್ಣಾಙ್ಕ sep)
{
    ಪೂರ್ಣಾಙ್ಕ argc = 0;
    ವರ್ಣ **argv = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = 0; i < *pargc; ++i)
        ಯದಿ (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        ಅನ್ಯಥಾ
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ಸ್ಥಿರ ಶೂನ್ಯ args_parser_add_file(TCCState *s, ಧ್ರುವ ವರ್ಣ* filename, ಪೂರ್ಣಾಙ್ಕ filetype)
{
    ಸಂರಚನಾ filespec *f = tcc_malloc(ಪರಿಮಾಣ *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    ಯದಿ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC ಪೂರ್ಣಾಙ್ಕ tcc_parse_args(TCCState *s, ಪೂರ್ಣಾಙ್ಕ *pargc, ವರ್ಣ ***pargv)
{
    TCCState *s1 = s;
    ಧ್ರುವ TCCOption *popt;
    ಧ್ರುವ ವರ್ಣ *optarg, *r;
    ಧ್ರುವ ವರ್ಣ *run = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ optind = 1, empty = 1, x;
    ವರ್ಣ **argv = *pargv;
    ಪೂರ್ಣಾಙ್ಕ argc = *pargc;

    s->link_optind = s->link_argc;

    ಯಾವತ್ (optind < argc) {
        r = argv[optind];
        ಯದಿ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            ಪೂರ್ಣಾಙ್ಕ fd; ವರ್ಣ *p;
            fd = open(++r, O_RDONLY | O_ದ್ವಿಮಾನ_2);
            ಯದಿ (fd < 0)
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            ಸೇರಿಸು_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ಅನುವರ್ತ;
        }
        optind++;
        ಯದಿ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            ಯದಿ (run)
                ಭಙ್ಗ;
            ಅನುವರ್ತ;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ಯದಿ (r[1] == '-' && r[2] == '\0')
            ಗಚ್ಛ dorun;

        /* find option in table */
        ಪ್ರತಿ(popt = tcc_options; ; ++popt) {
            ಧ್ರುವ ವರ್ಣ *p1 = popt->name;
            ಧ್ರುವ ವರ್ಣ *r1 = r + 1;
            ಯದಿ (p1 == ರಿಕ್ತ)
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("invalid option -- '%s'", r);
            ಯದಿ (!strstart(p1, &r1))
                ಅನುವರ್ತ;
            optarg = r1;
            ಯದಿ (popt->flags & TCC_OPTION_HAS_ARG) {
                ಯದಿ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ಯದಿ (optind >= argc)
                        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ಅನ್ಯಥಾ ಯದಿ (*r1 != '\0')
                ಅನುವರ್ತ;
            ಭಙ್ಗ;
        }

        ವಿಕಲ್ಪ(popt->index) {
        ಪಕ್ಷ TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_D:
            tcc_define_ಚಿಹ್ನೆ(s, optarg, ರಿಕ್ತ);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_U:
            tcc_undefine_ಚಿಹ್ನೆ(s, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            ಅನುವರ್ತ;
        ಪಕ್ಷ TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_pthread:
            s->option_pthread = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_bench:
            s->do_bench = 1;
            ಭಙ್ಗ;
#ifdef CONFIG_TCC_BACKTRACE
        ಪಕ್ಷ TCC_OPTION_bt:
            s->rt_ಅಂಕೆ_callers = atoi(optarg); /* zero = default (6) */
            ಗಚ್ಛ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ಯದಿ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            ಭಙ್ಗ;
#ifdef CONFIG_TCC_BCHECK
        ಪಕ್ಷ TCC_OPTION_b:
            s->do_bounds_check = 1;
            ಗಚ್ಛ enable_backtrace;
#endif
#endif
        ಪಕ್ಷ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            ಯದಿ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } ಅನ್ಯಥಾ ಯದಿ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ಅನ್ಯಥಾ ಯದಿ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                ಗಚ್ಛ g_redo;
#ifdef TCC_TARGET_PE
            } ಅನ್ಯಥಾ ಯದಿ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            ಯದಿ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_d:
            ಯದಿ (*optarg == 'D')
                s->dflag = 3;
            ಅನ್ಯಥಾ ಯದಿ (*optarg == 'M')
                s->dflag = 7;
            ಅನ್ಯಥಾ ಯದಿ (*optarg == 't')
                s->dflag = 16;
            ಅನ್ಯಥಾ ಯದಿ (isnum(*optarg))
                g_debug |= atoi(optarg);
            ಅನ್ಯಥಾ
                ಗಚ್ಛ unsupported_option;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_static:
            s->static_link = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_std:
            ಯದಿ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            ಗಚ್ಛ set_output_type;
        ಪಕ್ಷ TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_o:
            ಯದಿ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            ಗಚ್ಛ set_output_type;
        ಪಕ್ಷ TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            ಗಚ್ಛ set_output_type;
#ಅನ್ಯಥಾ
            ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        ಪಕ್ಷ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            ಭಙ್ಗ;
#endif
        ಪಕ್ಷ TCC_OPTION_v:
            ಕುರು ++s->verbose; ಯಾವತ್ (*optarg++ == 'v');
            ಅನುವರ್ತ;
        ಪಕ್ಷ TCC_OPTION_f:
            ಯದಿ (set_flag(s, options_f, optarg) < 0)
                ಗಚ್ಛ unsupported_option;
            ಭಙ್ಗ;
#ifdef TCC_TARGET_ARM
        ಪಕ್ಷ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ಯದಿ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ಅನ್ಯಥಾ ಯದಿ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ಅನ್ಯಥಾ
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("unsupported float abi '%s'", optarg);
            ಅನುವರ್ತ;
#endif
        ಪಕ್ಷ TCC_OPTION_m:
            ಯದಿ (set_flag(s, options_m, optarg) < 0) {
                ಯದಿ (x = atoi(optarg), x != 32 && x != 64)
                    ಗಚ್ಛ unsupported_option;
                ಯದಿ (PTR_SIZE != x/8)
                    ಪ್ರತ್ಯಾಗಮ x;
                ಅನುವರ್ತ;
            }
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_W:
            ಯದಿ (optarg[0] && set_flag(s, options_W, optarg) < 0)
                ಗಚ್ಛ unsupported_option;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_w:
            s->warn_none = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_Wl:
            ಯದಿ (tcc_set_linker(s, optarg) < 0)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_Wp:
            ಯದಿ (argv[0]) /* not with tcc_set_options() */
                ಸೇರಿಸು_args(s, &argv, &argc, --optind, optarg, ',');
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            ಗಚ್ಛ set_output_type;
        ಪಕ್ಷ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ಭಙ್ಗ;

        ಪಕ್ಷ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        ಪಕ್ಷ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ಯದಿ (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        ಪಕ್ಷ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ಯದಿ (*optarg != ',')
                ಭಙ್ಗ;
            ++optarg;
            // fall through
        ಪಕ್ಷ TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ಭಙ್ಗ;

        ಪಕ್ಷ TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        ಪಕ್ಷ TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        ಪಕ್ಷ TCC_OPTION_x:
            x = 0;
            ಯದಿ (*optarg == 'c')
                x = AFF_TYPE_C;
            ಅನ್ಯಥಾ ಯದಿ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ಅನ್ಯಥಾ ಯದಿ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ಅನ್ಯಥಾ ಯದಿ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ಅನ್ಯಥಾ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ಭಙ್ಗ;
#ಯದಿ defined TCC_TARGET_MACHO
        ಪಕ್ಷ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            ಗಚ್ಛ set_output_type;
        ಪಕ್ಷ TCC_OPTION_flat_namespace:
	     ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_two_levelnamespace:
	     ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_undefined:
	     ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            ಭಙ್ಗ;
        ಪಕ್ಷ TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            ಭಙ್ಗ;
#endif
        ಪಕ್ಷ TCC_OPTION_HELP:
            x = OPT_HELP;
            ಗಚ್ಛ extra_action;
        ಪಕ್ಷ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            ಗಚ್ಛ extra_action;
        ಪಕ್ಷ TCC_OPTION_print_ಹುಡುಕು_dirs:
            x = OPT_PRINT_DIRS;
            ಗಚ್ಛ extra_action;
        ಪಕ್ಷ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            ಗಚ್ಛ extra_action;
        ಪಕ್ಷ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ಯದಿ (ರಿಕ್ತ == argv[0]) /* from tcc_set_options() */
                ಪ್ರತ್ಯಾಗಮ -1;
            ಯದಿ (!empty && x)
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            ಪ್ರತ್ಯಾಗಮ x;
        ಸ್ವಭಾವ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ಭಙ್ಗ;
        }
        empty = 0;
    }
    ಯದಿ (s->link_optind < s->link_argc)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ಯದಿ (run) {
        ಯದಿ (*run && tcc_set_options(s, run) < 0)
            ಪ್ರತ್ಯಾಗಮ -1;
        x = 0, r = 0;
        ಗಚ್ಛ extra_action;
    }
    ಯದಿ (!empty)
        ಪ್ರತ್ಯಾಗಮ 0;
    ಯದಿ (s->verbose == 2)
        ಪ್ರತ್ಯಾಗಮ OPT_PRINT_DIRS;
    ಯದಿ (s->verbose)
        ಪ್ರತ್ಯಾಗಮ OPT_V;
    ಪ್ರತ್ಯಾಗಮ OPT_HELP;
}

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_set_options(TCCState *s, ಧ್ರುವ ವರ್ಣ *r)
{
    ವರ್ಣ **argv = ರಿಕ್ತ;
    ಪೂರ್ಣಾಙ್ಕ argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    ಪ್ರತ್ಯಾಗಮ ret;
}

PUB_FUNC ಶೂನ್ಯ tcc_print_stats(TCCState *s1, unsigned total_time)
{
    ಯದಿ (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_ಸಾಲುಗಳು, total_bytes,
           (ದ್ವಿಗುಣ)total_time/1000,
           (unsigned)total_ಸಾಲುಗಳು*1000/total_time,
           (ದ್ವಿಗುಣ)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    ಯದಿ (s1->run_size) {
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
