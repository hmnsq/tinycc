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

#ຖ້າ ONE_SOURCE
#include "tccpp.c"
#include "tccgen.c"
#include "tccdbg.c"
#include "tccasm.c"
#include "tccelf.c"
#include "tccrun.c"
#ifdef TCC_TARGET_I386
#include "i386-gen.c"
#include "i386-link.c"
#include "i386-asm.c"
#elif defined(TCC_TARGET_ARM)
#include "arm-gen.c"
#include "arm-link.c"
#include "arm-asm.c"
#elif defined(TCC_TARGET_ARM64)
#include "arm64-gen.c"
#include "arm64-link.c"
#include "arm64-asm.c"
#elif defined(TCC_TARGET_C67)
#include "c67-gen.c"
#include "c67-link.c"
#include "tcccoff.c"
#elif defined(TCC_TARGET_X86_64)
#include "x86_64-gen.c"
#include "x86_64-link.c"
#include "i386-asm.c"
#elif defined(TCC_TARGET_RISCV64)
#include "riscv64-gen.c"
#include "riscv64-link.c"
#include "riscv64-asm.c"
#ບໍ່ດັ່ງນັ້ນ
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#include "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#include "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#include "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA sa_nracanaa TCCState *tcc_state;
TCC_SEM(static tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA void** stk_data;
ST_DATA ຈຳນວນເຕັມ nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA ຈຳນວນເຕັມ g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC var_na *normalize_slashes(var_na *path)
{
    var_na *p;
    ສຳລັບ (p = path; *p; ++p)
        ຖ້າ (*p == '\\')
            *p = '/';
    ສົ່ງຄືນ path;
}

#ຖ້າ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
static HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ຖ້າ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    ສົ່ງຄືນ TRUE;
}
#ບໍ່ດັ່ງນັ້ນ
#define tcc_module NULL /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
static anta_hstha var_na *config_tccdir_w32(var_na *path)
{
    var_na *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    ຖ້າ (p > path)
        --p;
    *p = 0;
    ສົ່ງຄືນ path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
static void tcc_add_systemdir(TCCState *s)
{
    var_na buf[1000];
    GetSystemDirectoryA(buf, parimaa_na buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(const var_na *f, const var_na *m) {
    ສົ່ງຄືນ fopen(f, m);
}
PUB_FUNC ຈຳນວນເຕັມ tcc_fclose(FILE *f) {
    ສົ່ງຄືນ fclose(f);
}
#endif
/********************************************************/

PUB_FUNC void tcc_enter_state(TCCState *s1)
{
    ຖ້າ (s1->error_set_jmp_enabled)
        ສົ່ງຄືນ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC void tcc_exit_state(TCCState *s1)
{
    ຖ້າ (s1->error_set_jmp_enabled)
        ສົ່ງຄືນ;
    tcc_state = NULL;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC var_na *pstrcpy(var_na *buf, size_t buf_size, const var_na *s)
{
    var_na *q, *q_end;
    ຈຳນວນເຕັມ c;

    ຖ້າ (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        ໃນຂະນະທີ່ (q < q_end) {
            c = *s++;
            ຖ້າ (c == '\0')
                bha_nga;
            *q++ = c;
        }
        *q = '\0';
    }
    ສົ່ງຄືນ buf;
}

/* strcat and truncate. */
ST_FUNC var_na *pstrcat(var_na *buf, size_t buf_size, const var_na *s)
{
    size_t len;
    len = strlen(buf);
    ຖ້າ (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    ສົ່ງຄືນ buf;
}

ST_FUNC var_na *pstrncpy(var_na *out, size_t buf_size, const var_na *s, size_t num)
{
    ຖ້າ (num >= buf_size)
        num = buf_size - 1;
    memcpy(out, s, num);
    out[num] = '\0';
    ສົ່ງຄືນ out;
}

/* extract the basename of a file */
PUB_FUNC var_na *tcc_basename(const var_na *name)
{
    var_na *p = (var_na *)strchr(name, 0);
    ໃນຂະນະທີ່ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    ສົ່ງຄືນ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC var_na *tcc_fileextension (const var_na *name)
{
    var_na *b = tcc_basename(name);
    var_na *e = strrchr(b, '.');
    ສົ່ງຄືນ e ? e : strchr(b, 0);
}

ST_FUNC var_na *tcc_load_text(ຈຳນວນເຕັມ fd)
{
    ຈຳນວນເຕັມ len = lseek(fd, 0, SEEK_END);
    var_na *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    ສົ່ງຄືນ buf;
}

/* replace *pp by copy of 'str' or NULL */
static void tcc_set_str(var_na **pp, const var_na *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : NULL;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
static void tcc_concat_str(var_na **pp, const var_na *str, ຈຳນວນເຕັມ sep)
{
    ຈຳນວນເຕັມ l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    ຖ້າ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef free
#undef realloc

static void *default_reallocator(void *ptr, unsigned long size)
{
    void *ptr1;
    ຖ້າ (size == 0) {
        free(ptr);
        ptr1 = NULL;
    }
    ບໍ່ດັ່ງນັ້ນ {
        ptr1 = realloc(ptr, size);
        ຖ້າ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    ສົ່ງຄືນ ptr1;
}

ST_FUNC void libc_free(void *ptr)
{
    free(ptr);
}

/* defined to be not used */
#define free(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
static void *(*reallocator)(void*, unsigned long) = default_reallocator;

LIBTCCAPI void tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC void tcc_free(void *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC void *tcc_malloc(unsigned long size)
{
    ສົ່ງຄືນ reallocator(0, size);
}

PUB_FUNC void *tcc_realloc(void *ptr, unsigned long size)
{
    ສົ່ງຄືນ reallocator(ptr, size);
}

PUB_FUNC void *tcc_mallocz(unsigned long size)
{
    void *ptr;
    ptr = tcc_malloc(size);
    ຖ້າ (size)
        memset(ptr, 0, size);
    ສົ່ງຄືນ ptr;
}

PUB_FUNC var_na *tcc_strdup(const var_na *str)
{
    var_na *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    ສົ່ງຄືນ ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned var_na *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((var_na *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((var_na*)ptr - offsetof(mem_debug_header_t, magic3))

sa_nracanaa mem_debug_header {
    unsigned magic1;
    unsigned size;
    sa_nracanaa mem_debug_header *prev;
    sa_nracanaa mem_debug_header *next;
    ຈຳນວນເຕັມ line_num;
    var_na file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned var_na magic3[4];
};

typedef sa_nracanaa mem_debug_header mem_debug_header_t;

TCC_SEM(static mem_sem);
static mem_debug_header_t *mem_debug_chain;
static unsigned mem_cur_size;
static unsigned mem_max_size;
static ຈຳນວນເຕັມ nb_states;

static mem_debug_header_t *malloc_check(void *ptr, const var_na *msg)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    ຖ້າ (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", msg);
        ຖ້າ (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->line_num);
        exit(1);
    }
    ສົ່ງຄືນ header;
}

PUB_FUNC void *tcc_malloc_debug(unsigned long size, const var_na *file, ຈຳນວນເຕັມ line)
{
    ຈຳນວນເຕັມ ofs;
    mem_debug_header_t *header;
    ຖ້າ (!size)
        ສົ່ງຄືນ NULL;
    header = tcc_malloc(parimaa_na(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->line_num = line;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = NULL;
    ຖ້າ (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    ຖ້າ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ສົ່ງຄືນ MEM_USER_PTR(header);
}

PUB_FUNC void tcc_free_debug(void *ptr)
{
    mem_debug_header_t *header;
    ຖ້າ (!ptr)
        ສົ່ງຄືນ;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    ຖ້າ (header->next)
        header->next->prev = header->prev;
    ຖ້າ (header->prev)
        header->prev->next = header->next;
    ຖ້າ (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC void *tcc_mallocz_debug(unsigned long size, const var_na *file, ຈຳນວນເຕັມ line)
{
    void *ptr;
    ptr = tcc_malloc_debug(size,file,line);
    ຖ້າ (size)
        memset(ptr, 0, size);
    ສົ່ງຄືນ ptr;
}

PUB_FUNC void *tcc_realloc_debug(void *ptr, unsigned long size, const var_na *file, ຈຳນວນເຕັມ line)
{
    mem_debug_header_t *header;
    ຈຳນວນເຕັມ mem_debug_chain_update = 0;

    ຖ້າ (!ptr)
        ສົ່ງຄືນ tcc_malloc_debug(size, file, line);
    ຖ້າ (!size) {
        tcc_free_debug(ptr);
        ສົ່ງຄືນ NULL;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, parimaa_na(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    ຖ້າ (header->next)
        header->next->prev = header;
    ຖ້າ (header->prev)
        header->prev->next = header;
    ຖ້າ (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    ຖ້າ (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ສົ່ງຄືນ MEM_USER_PTR(header);
}

PUB_FUNC var_na *tcc_strdup_debug(const var_na *str, const var_na *file, ຈຳນວນເຕັມ line)
{
    var_na *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, line);
    strcpy(ptr, str);
    ສົ່ງຄືນ ptr;
}

PUB_FUNC void tcc_memcheck(ຈຳນວນເຕັມ d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    ຖ້າ (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        ໃນຂະນະທີ່ (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->line_num, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = NULL;
#ຖ້າ MEM_DEBUG-0 == 2
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
ST_FUNC ຈຳນວນເຕັມ normalized_PATHCMP(const var_na *f1, const var_na *f2)
{
    var_na *p1, *p2;
    ຈຳນວນເຕັມ ret = 1;
    ຖ້າ (!!(p1 = realpath(f1, NULL))) {
        ຖ້າ (!!(p2 = realpath(f2, NULL))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    ສົ່ງຄືນ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC void dynarray_add(void *ptab, ຈຳນວນເຕັມ *nb_ptr, void *data)
{
    ຈຳນວນເຕັມ nb, nb_alloc;
    void **pp;

    nb = *nb_ptr;
    pp = *(void ***)ptab;
    /* every power of two we double array size */
    ຖ້າ ((nb & (nb - 1)) == 0) {
        ຖ້າ (!nb)
            nb_alloc = 1;
        ບໍ່ດັ່ງນັ້ນ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * parimaa_na(void *));
        *(void***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC void dynarray_reset(void *pp, ຈຳນວນເຕັມ *n)
{
    void **p;
    ສຳລັບ (p = *(void***)pp; *n; ++p, --*n)
        ຖ້າ (*p)
            tcc_free(*p);
    tcc_free(*(void**)pp);
    *(void**)pp = NULL;
}

static void dynarray_split(var_na ***argv, ຈຳນວນເຕັມ *argc, const var_na *p, ຈຳນວນເຕັມ sep)
{
    ຈຳນວນເຕັມ qot, c;
    CString str;
    ສຳລັບ(;;) {
        ໃນຂະນະທີ່ (c = (unsigned var_na)*p, c <= ' ' && c != '\0')
            ++p;
        ຖ້າ (c == '\0')
            bha_nga;
        cstr_new(&str);
        qot = 0;
        do {
            ++p;
            ຖ້າ (sep) { /* e.g. to split -Wl,-opt,arg */
                ຖ້າ (c == sep)
                    bha_nga;
            } ບໍ່ດັ່ງນັ້ນ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ຖ້າ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ບໍ່ດັ່ງນັ້ນ ຖ້າ (c == '"') {
                    qot ^= 1;
                    continue;
                } ບໍ່ດັ່ງນັ້ນ ຖ້າ (c <= ' ' && !qot) {
                    bha_nga;
                }
            }
            cstr_ccat(&str, c);
        } ໃນຂະນະທີ່ (c = (unsigned var_na)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

static void tcc_split_path(TCCState *s, void *p_ary, ຈຳນວນເຕັມ *p_nb_ary, const var_na *in)
{
    const var_na *p;
    do {
        ຈຳນວນເຕັມ c;
        CString str;

        cstr_new(&str);
        ສຳລັບ (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ຖ້າ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ຖ້າ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                ຖ້າ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ຖ້າ (c == 'f' && file) {
                    /* substitute current file's dir */
                    const var_na *f = file->true_filename;
                    const var_na *b = tcc_basename(f);
                    ຖ້າ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ບໍ່ດັ່ງນັ້ນ
                        cstr_cat(&str, ".", 1);
                }
            } ບໍ່ດັ່ງນັ້ນ {
                cstr_ccat(&str, c);
            }
        }
        ຖ້າ (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } ໃນຂະນະທີ່ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ga_nanaa { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

static void error1(ຈຳນວນເຕັມ mode, const var_na *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    ຈຳນວນເຕັມ line = 0;

    tcc_exit_state(s1);

    ຖ້າ (mode == ERROR_WARN) {
        ຖ້າ (s1->warn_error)
            mode = ERROR_ERROR;
        ຖ້າ (s1->warn_num) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            ຈຳນວນເຕັມ wopt = *(&s1->warn_none + s1->warn_num);
            s1->warn_num = 0;
            ຖ້າ (0 == (wopt & WARN_ON))
                ສົ່ງຄືນ;
            ຖ້າ (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            ຖ້າ (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        ຖ້າ (s1->warn_none)
            ສົ່ງຄືນ;
    }

    cstr_new(&cs);
    ຖ້າ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        line = va_arg(ap, ຈຳນວນເຕັມ), fmt += 3;
    f = NULL;
    ຖ້າ (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        ສຳລັບ (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ຖ້າ (f) {
        ສຳລັບ(pf = s1->include_stack; pf < s1->include_stack_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->line_num - 1);
        ຖ້າ (0 == line)
            line = f->line_num - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, line);
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ບໍ່ດັ່ງນັ້ນ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    ຖ້າ (pp_expr > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ບໍ່ດັ່ງນັ້ນ
        cstr_vprintf(&cs, fmt, ap);
    ຖ້າ (!s1->error_func) {
        /* default case: stderr */
        ຖ້າ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (var_na*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } ບໍ່ດັ່ງນັ້ນ {
        s1->error_func(s1->error_opaque, (var_na*)cs.data);
    }
    cstr_free(&cs);
    ຖ້າ (mode != ERROR_WARN)
        s1->nb_errors++;
    ຖ້າ (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        ໃນຂະນະທີ່ (nb_stk_data)
            tcc_free(*(void**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI void tcc_set_error_func(TCCState *s, void *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC ຈຳນວນເຕັມ _tcc_error_noabort(const var_na *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    ສົ່ງຄືນ -1;
}

#undef _tcc_error
PUB_FUNC void _tcc_error(const var_na *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC void _tcc_warning(const var_na *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC void tcc_open_bf(TCCState *s1, const var_na *filename, ຈຳນວນເຕັມ initlen)
{
    BufferedFile *bf;
    ຈຳນວນເຕັມ buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(parimaa_na(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, parimaa_na(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->line_num = 1;
    bf->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC void tcc_close(void)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ຖ້າ (bf->fd > 0) {
        close(bf->fd);
        total_lines += bf->line_num - 1;
    }
    ຖ້າ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

static ຈຳນວນເຕັມ _tcc_open(TCCState *s1, const var_na *filename)
{
    ຈຳນວນເຕັມ fd;
    ຖ້າ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ບໍ່ດັ່ງນັ້ນ
        fd = open(filename, O_RDONLY | O_BINARY);
    ຖ້າ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (ຈຳນວນເຕັມ)(s1->include_stack_ptr - s1->include_stack), "", filename);
    ສົ່ງຄືນ fd;
}

ST_FUNC ຈຳນວນເຕັມ tcc_open(TCCState *s1, const var_na *filename)
{
    ຈຳນວນເຕັມ fd = _tcc_open(s1, filename);
    ຖ້າ (fd < 0)
        ສົ່ງຄືນ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    ສົ່ງຄືນ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
static ຈຳນວນເຕັມ tcc_compile(TCCState *s1, ຈຳນວນເຕັມ filetype, const var_na *str, ຈຳນວນເຕັມ fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    ຖ້າ (setjmp(s1->error_jmp_buf) == 0) {

        ຖ້າ (fd == -1) {
            ຈຳນວນເຕັມ len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } ບໍ່ດັ່ງນັ້ນ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        ຖ້າ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ບໍ່ດັ່ງນັ້ນ {
            tccelf_begin_file(s1);
            ຖ້າ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ບໍ່ດັ່ງນັ້ນ {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    ສົ່ງຄືນ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_compile_string(TCCState *s, const var_na *str)
{
    ສົ່ງຄືນ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI void tcc_define_symbol(TCCState *s1, const var_na *sym, const var_na *value)
{
    const var_na *eq;
    ຖ້າ (NULL == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ຖ້າ (NULL == value)
        value = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (ຈຳນວນເຕັມ)(eq-sym), sym, value);
}

/* undefine a preprocessor symbol */
LIBTCCAPI void tcc_undefine_symbol(TCCState *s1, const var_na *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(void)
{
    TCCState *s;

    s = tcc_mallocz(parimaa_na(TCCState));
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
#ຖ້າ defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#ຖ້າ defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_stack_ptr = s->include_stack;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    ສົ່ງຄືນ s;
}

LIBTCCAPI void tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_symbol);
    tcc_free(s1->fini_symbol);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ຖ້າ defined TCC_TARGET_MACHO
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

LIBTCCAPI ຈຳນວນເຕັມ tcc_set_output_type(TCCState *s, ຈຳນວນເຕັມ output_type)
{
#ifdef CONFIG_TCC_PIE
    ຖ້າ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    ຖ້າ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ຖ້າ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        ສົ່ງຄືນ 0;
    }

    /* add sections */
    tccelf_new(s);

    ຖ້າ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        ສົ່ງຄືນ 0;
    }

    ຖ້າ (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#elif defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#ບໍ່ດັ່ງນັ້ນ
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ຖ້າ (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    ສົ່ງຄືນ s->nb_errors ? -1 : 0;
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_add_include_path(TCCState *s, const var_na *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    ສົ່ງຄືນ 0;
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_add_sysinclude_path(TCCState *s, const var_na *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    ສົ່ງຄືນ 0;
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_add_library_path(TCCState *s, const var_na *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    ສົ່ງຄືນ 0;
}

LIBTCCAPI void tcc_set_lib_path(TCCState *s, const var_na *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, const var_na *dllname, ຈຳນວນເຕັມ level)
{
    DLLReference *ref = NULL;
    ຈຳນວນເຕັມ i;
    ສຳລັບ (i = 0; i < s1->nb_loaded_dlls; i++)
        ຖ້າ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            bha_nga;
        }
    ຖ້າ (level == -1)
        ສົ່ງຄືນ ref;
    ຖ້າ (ref) {
        ຖ້າ (level < ref->level)
            ref->level = level;
        ref->found = 1;
        ສົ່ງຄືນ ref;
    }
    ref = tcc_mallocz(parimaa_na(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    ສົ່ງຄືນ ref;
}

static ຈຳນວນເຕັມ tcc_add_binary(TCCState *s1, ຈຳນວນເຕັມ flags, const var_na *filename, ຈຳນວນເຕັມ fd)
{
    ElfW(Ehdr) ehdr;
    ຈຳນວນເຕັມ obj_type;
    const var_na *saved_filename = s1->current_filename;
    ຈຳນວນເຕັມ ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    switch (obj_type) {

    pak_sa AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        bha_nga;

    pak_sa AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        bha_nga;

#ຖ້າ defined TCC_TARGET_UNIX
    pak_sa AFF_BINTYPE_DYN:
        ຖ້າ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            void* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ຖ້າ (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            ບໍ່ດັ່ງນັ້ນ
                ret = FILE_NOT_RECOGNIZED;
#endif
        } ບໍ່ດັ່ງນັ້ນ
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        bha_nga;

    default:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        bha_nga;

#elif defined TCC_TARGET_MACHO
    pak_sa AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ຖ້າ (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            void* dl;
            const var_na* soname = filename;
            var_na *tmp = 0;
            ຖ້າ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ຖ້າ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ຖ້າ (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            ບໍ່ດັ່ງນັ້ນ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ບໍ່ດັ່ງນັ້ນ {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ຖ້າ (ret)
            ret = FILE_NOT_RECOGNIZED;
        bha_nga;

    default:
    {
        const var_na *ext = tcc_fileextension(filename);
        ຖ້າ (!strcmp(ext, ".tbd"))
            goto case_dyn_or_tbd;
        ຖ້າ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            goto case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        bha_nga;
    }

#elif defined TCC_TARGET_PE
    default:
        ຖ້າ (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        bha_nga;
#endif

#ifdef TCC_TARGET_COFF
    pak_sa AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        bha_nga;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    ຖ້າ (ret == FILE_NOT_RECOGNIZED)
        ສົ່ງຄືນ tcc_error_noabort("%s: unrecognized file type", filename);
    ສົ່ງຄືນ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ຖ້າ defined TARGETOS_OpenBSD && !defined _WIN32
#include <glob.h>
static ຈຳນວນເຕັມ tcc_glob_so(TCCState *s1, const var_na *pattern, var_na *buf, ຈຳນວນເຕັມ size)
{
    const var_na *star;
    glob_t g;
    var_na *p;
    ຈຳນວນເຕັມ i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    ຖ້າ (!star || glob(pattern, 0, NULL, &g))
        ສົ່ງຄືນ -1;
    ສຳລັບ (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ຖ້າ (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            continue;
        ຖ້າ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    ສົ່ງຄືນ v;
}
#endif

static ຈຳນວນເຕັມ guess_filetype(const var_na *filename)
{
    ຈຳນວນເຕັມ filetype = 0;
    ຖ້າ (1) {
        /* use a file extension to detect a filetype */
        const var_na *ext = tcc_fileextension(filename);
        ຖ້າ (ext[0]) {
            ext++;
            ຖ້າ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ບໍ່ດັ່ງນັ້ນ
                filetype |= AFF_TYPE_BIN;
        } ບໍ່ດັ່ງນັ້ນ {
            filetype = AFF_TYPE_C;
        }
    }
    ສົ່ງຄືນ filetype;
}

ST_FUNC ຈຳນວນເຕັມ tcc_add_file_internal(TCCState *s1, const var_na *filename, ຈຳນວນເຕັມ flags)
{
    ຈຳນວນເຕັມ fd;

#ຖ້າ defined TARGETOS_OpenBSD && !defined _WIN32
    var_na buf[1024];
    ຖ້າ (tcc_glob_so(s1, filename, buf, parimaa_na buf) >= 0)
        filename = buf;
#endif

    ຖ້າ (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ຖ້າ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        ສົ່ງຄືນ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ຖ້າ (fd < 0) {
        ຖ້າ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        ສົ່ງຄືນ FILE_NOT_FOUND;
    }

    ຖ້າ (flags & AFF_TYPE_BIN)
        ສົ່ງຄືນ tcc_add_binary(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    ສົ່ງຄືນ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_add_file(TCCState *s, const var_na *filename)
{
    ສົ່ງຄືນ tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

static ຈຳນວນເຕັມ tcc_add_library_internal(TCCState *s1, const var_na *fmt,
    const var_na *filename, ຈຳນວນເຕັມ flags, var_na **paths, ຈຳນວນເຕັມ nb_paths)
{
    var_na buf[1024];
    ຈຳນວນເຕັມ i, ret;

    ສຳລັບ(i = 0; i < nb_paths; i++) {
        snprintf(buf, parimaa_na(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        ຖ້າ (ret != FILE_NOT_FOUND)
            ສົ່ງຄືນ ret;
    }
    ຖ້າ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    ສົ່ງຄືນ FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC ຈຳນວນເຕັມ tcc_add_dll(TCCState *s, const var_na *filename, ຈຳນວນເຕັມ flags)
{
    ສົ່ງຄືນ tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC ຈຳນວນເຕັມ tcc_add_support(TCCState *s1, const var_na *filename)
{
    var_na buf[100];
    ຖ້າ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    ສົ່ງຄືນ tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC ຈຳນວນເຕັມ tcc_add_crt(TCCState *s1, const var_na *filename)
{
    ສົ່ງຄືນ tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ຈຳນວນເຕັມ tcc_add_library(TCCState *s, const var_na *libraryname)
{
    static const var_na * const libs[] = {
#ຖ້າ defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#elif defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#elif defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ບໍ່ດັ່ງນັ້ນ
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        NULL
    };
    ຈຳນວນເຕັມ flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ຖ້າ (*libraryname == ':') {
        libraryname++;
    } ບໍ່ດັ່ງນັ້ນ {
        const var_na * const *pp = libs;
        ຖ້າ (s->static_link)
            pp += parimaa_na(libs) / parimaa_na(*libs) - 2; /* only "%s/lib%s.a" */
        ໃນຂະນະທີ່ (*pp) {
            ຈຳນວນເຕັມ ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ຖ້າ (ret != FILE_NOT_FOUND)
                ສົ່ງຄືນ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    ສົ່ງຄືນ tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC void tcc_add_pragma_libs(TCCState *s1)
{
    ຈຳນວນເຕັມ i;
    ສຳລັບ (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

static ຈຳນວນເຕັມ strstart(const var_na *val, const var_na **str)
{
    const var_na *p, *q;
    p = *str;
    q = val;
    ໃນຂະນະທີ່ (*q) {
        ຖ້າ (*p != *q)
            ສົ່ງຄືນ 0;
        p++;
        q++;
    }
    *str = p;
    ສົ່ງຄືນ 1;
}

sa_nracanaa lopt {
    TCCState *s;
    const var_na *opt, *arg;
    ຈຳນວນເຕັມ match;
};

/* match linker option */
static ຈຳນວນເຕັມ link_option(sa_nracanaa lopt *o, const var_na *q)
{
    const var_na *p;
    ຈຳນວນເຕັມ c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ຖ້າ (*p++ != '-')
        ສົ່ງຄືນ 0;
    ຖ້າ (*p == '-')
        p++;
    r = 1;
    ຖ້າ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ຖ້າ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        ບໍ່ດັ່ງນັ້ນ ຖ້າ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    ໃນຂະນະທີ່ ((c = *q) == *p) {
        ຖ້າ (c == '\0')
            goto succ; /* -Wl,-opt */
        ++p;
        ຖ້າ (c == '=')
            goto succ; /* -Wl,-opt=arg */
        ++q;
    }
    ຖ້າ (*p == '\0') {
        ຖ້າ (c == '|')
            goto succ;
        ຖ້າ (c == '=' || c == ':') {
            ຖ້າ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                goto succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            ສົ່ງຄືນ 0;
        }
    } ບໍ່ດັ່ງນັ້ນ ຖ້າ (c == ':')
        goto succ; /* -Wl,-Iarg */
    ໃນຂະນະທີ່ (*q)
        ຖ້າ (*q++ == '|')
            goto redo;
    ສົ່ງຄືນ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    ສົ່ງຄືນ r;
}

static void args_parser_add_file(TCCState *s, const var_na* filename, ຈຳນວນເຕັມ filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
static ຈຳນວນເຕັມ tcc_set_linker(TCCState *s, const var_na *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    ໃນຂະນະທີ່ (s->link_optind < s->link_argc) {
        var_na *end = NULL;
        ຈຳນວນເຕັມ ignoring = 0;
        sa_nracanaa lopt o = {0};
        ຈຳນວນເຕັມ r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ຖ້າ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "init=")) {
            tcc_set_str(&s->init_symbol, o.arg);
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_symbol, o.arg);
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "oformat=")) {
#ຖ້າ defined TCC_TARGET_PE
            ຖ້າ (0 == strncmp("pe-", o.arg, 3))
#elif PTR_SIZE == 8
            ຖ້າ (0 == strncmp("elf64-", o.arg, 6))
#ບໍ່ດັ່ງນັ້ນ
            ຖ້າ (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_BINARY;
#ຖ້າ defined TCC_TARGET_COFF
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            ບໍ່ດັ່ງນັ້ນ
                goto err;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "stack=")) {
            s->pe_stack_size = strtoul(o.arg, &end, 10);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "subsystem=")) {
            ຖ້າ (pe_setsubsy(s, o.arg) < 0)
                goto err;
#elif defined TCC_TARGET_MACHO
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "O")) {
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "z=")) {
            ignoring = 1;
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } ບໍ່ດັ່ງນັ້ນ ຖ້າ (o.match) {
            ສົ່ງຄືນ 0; /* expecting argument with next '-Wl,' */
        } ບໍ່ດັ່ງນັ້ນ {
    err:
            ສົ່ງຄືນ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ຖ້າ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    ສົ່ງຄືນ 0;
}

typedef sa_nracanaa TCCOption {
    const var_na *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

ga_nanaa {
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
    TCC_OPTION_print_search_dirs,
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

static const TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_search_dirs, 0 },
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
    { NULL, 0, 0 },
};

typedef sa_nracanaa FlagDef {
    uint16_t offset;
    uint16_t flags;
    const var_na *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

static const FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, NULL }
};

static const FlagDef options_f[] = {
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
    { 0, 0, NULL }
};

static const FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, NULL }
};

static ຈຳນວນເຕັມ set_flag(TCCState *s, const FlagDef *flags, const var_na *name)
{
    ຈຳນວນເຕັມ value, mask, ret;
    const FlagDef *p;
    const var_na *r;
    unsigned var_na *f;

    r = name, value = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ຖ້າ ((flags->flags & WD_ALL) && strstart("error=", &r))
        value = value ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    ສຳລັບ (ret = -1, p = flags; p->name; ++p) {
        ຖ້າ (ret) {
            ຖ້າ (strcmp(r, p->name))
                continue;
        } ບໍ່ດັ່ງນັ້ນ {
            ຖ້າ (0 == (p->flags & WD_ALL))
                continue;
        }

        f = (unsigned var_na *)s + p->offset;
        *f = (*f & mask) | (value ^ !!(p->flags & FD_INVERT));

        ຖ້າ (ret) {
            ret = 0;
            ຖ້າ (strcmp(r, "all"))
                bha_nga;
        }
    }
    ສົ່ງຄືນ ret;
}

static const var_na dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#elif defined TCC_TARGET_X86_64
    "x86_64-pc"
#elif defined TCC_TARGET_C67
    "c67"
#elif defined TCC_TARGET_ARM
    "arm"
#elif defined TCC_TARGET_ARM64
    "aarch64"
#elif defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#elif defined(TCC_TARGET_MACHO)
    "apple-darwin"
#elif TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#elif TARGETOS_OpenBSD
    "openbsd"
#elif TARGETOS_NetBSD
    "netbsd"
#elif CONFIG_TCC_MUSL
    "linux-musl"
#ບໍ່ດັ່ງນັ້ນ
    "linux-gnu"
#endif
;

#ຖ້າ defined TCC_TARGET_MACHO
static uint32_t parse_version(TCCState *s1, const var_na *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    var_na* last;

    a = strtoul(version, &last, 10);
    ຖ້າ (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        ຖ້າ (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    ຖ້າ (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    ສົ່ງຄືນ (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
static void insert_args(TCCState *s1, var_na ***pargv, ຈຳນວນເຕັມ *pargc, ຈຳນວນເຕັມ optind, const var_na *p, ຈຳນວນເຕັມ sep)
{
    ຈຳນວນເຕັມ argc = 0;
    var_na **argv = NULL;
    ຈຳນວນເຕັມ i;
    ສຳລັບ (i = 0; i < *pargc; ++i)
        ຖ້າ (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        ບໍ່ດັ່ງນັ້ນ
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

static void args_parser_add_file(TCCState *s, const var_na* filename, ຈຳນວນເຕັມ filetype)
{
    sa_nracanaa filespec *f = tcc_malloc(parimaa_na *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    ຖ້າ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC ຈຳນວນເຕັມ tcc_parse_args(TCCState *s, ຈຳນວນເຕັມ *pargc, var_na ***pargv)
{
    TCCState *s1 = s;
    const TCCOption *popt;
    const var_na *optarg, *r;
    const var_na *run = NULL;
    ຈຳນວນເຕັມ optind = 1, empty = 1, x;
    var_na **argv = *pargv;
    ຈຳນວນເຕັມ argc = *pargc;

    s->link_optind = s->link_argc;

    ໃນຂະນະທີ່ (optind < argc) {
        r = argv[optind];
        ຖ້າ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            ຈຳນວນເຕັມ fd; var_na *p;
            fd = open(++r, O_RDONLY | O_BINARY);
            ຖ້າ (fd < 0)
                ສົ່ງຄືນ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            insert_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            continue;
        }
        optind++;
        ຖ້າ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            ຖ້າ (run)
                bha_nga;
            continue;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ຖ້າ (r[1] == '-' && r[2] == '\0')
            goto dorun;

        /* find option in table */
        ສຳລັບ(popt = tcc_options; ; ++popt) {
            const var_na *p1 = popt->name;
            const var_na *r1 = r + 1;
            ຖ້າ (p1 == NULL)
                ສົ່ງຄືນ tcc_error_noabort("invalid option -- '%s'", r);
            ຖ້າ (!strstart(p1, &r1))
                continue;
            optarg = r1;
            ຖ້າ (popt->flags & TCC_OPTION_HAS_ARG) {
                ຖ້າ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ຖ້າ (optind >= argc)
                        ສົ່ງຄືນ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ບໍ່ດັ່ງນັ້ນ ຖ້າ (*r1 != '\0')
                continue;
            bha_nga;
        }

        switch(popt->index) {
        pak_sa TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            bha_nga;
        pak_sa TCC_OPTION_D:
            tcc_define_symbol(s, optarg, NULL);
            bha_nga;
        pak_sa TCC_OPTION_U:
            tcc_undefine_symbol(s, optarg);
            bha_nga;
        pak_sa TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            bha_nga;
        pak_sa TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            continue;
        pak_sa TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            bha_nga;
        pak_sa TCC_OPTION_pthread:
            s->option_pthread = 1;
            bha_nga;
        pak_sa TCC_OPTION_bench:
            s->do_bench = 1;
            bha_nga;
#ifdef CONFIG_TCC_BACKTRACE
        pak_sa TCC_OPTION_bt:
            s->rt_num_callers = atoi(optarg); /* zero = default (6) */
            goto enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ຖ້າ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            bha_nga;
#ifdef CONFIG_TCC_BCHECK
        pak_sa TCC_OPTION_b:
            s->do_bounds_check = 1;
            goto enable_backtrace;
#endif
#endif
        pak_sa TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            ຖ້າ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } ບໍ່ດັ່ງນັ້ນ ຖ້າ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ບໍ່ດັ່ງນັ້ນ ຖ້າ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                goto g_redo;
#ifdef TCC_TARGET_PE
            } ບໍ່ດັ່ງນັ້ນ ຖ້າ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            bha_nga;
        pak_sa TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            ຖ້າ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            bha_nga;
        pak_sa TCC_OPTION_d:
            ຖ້າ (*optarg == 'D')
                s->dflag = 3;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (*optarg == 'M')
                s->dflag = 7;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (*optarg == 't')
                s->dflag = 16;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (isnum(*optarg))
                g_debug |= atoi(optarg);
            ບໍ່ດັ່ງນັ້ນ
                goto unsupported_option;
            bha_nga;
        pak_sa TCC_OPTION_static:
            s->static_link = 1;
            bha_nga;
        pak_sa TCC_OPTION_std:
            ຖ້າ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            bha_nga;
        pak_sa TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            goto set_output_type;
        pak_sa TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            bha_nga;
        pak_sa TCC_OPTION_o:
            ຖ້າ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            bha_nga;
        pak_sa TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            goto set_output_type;
        pak_sa TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            bha_nga;
        pak_sa TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            bha_nga;
        pak_sa TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            bha_nga;
        pak_sa TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            bha_nga;
        pak_sa TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            goto set_output_type;
#ບໍ່ດັ່ງນັ້ນ
            ສົ່ງຄືນ tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        pak_sa TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            bha_nga;
#endif
        pak_sa TCC_OPTION_v:
            do ++s->verbose; ໃນຂະນະທີ່ (*optarg++ == 'v');
            continue;
        pak_sa TCC_OPTION_f:
            ຖ້າ (set_flag(s, options_f, optarg) < 0)
                goto unsupported_option;
            bha_nga;
#ifdef TCC_TARGET_ARM
        pak_sa TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ຖ້າ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ບໍ່ດັ່ງນັ້ນ ຖ້າ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ບໍ່ດັ່ງນັ້ນ
                ສົ່ງຄືນ tcc_error_noabort("unsupported float abi '%s'", optarg);
            continue;
#endif
        pak_sa TCC_OPTION_m:
            ຖ້າ (set_flag(s, options_m, optarg) < 0) {
                ຖ້າ (x = atoi(optarg), x != 32 && x != 64)
                    goto unsupported_option;
                ຖ້າ (PTR_SIZE != x/8)
                    ສົ່ງຄືນ x;
                continue;
            }
            bha_nga;
        pak_sa TCC_OPTION_W:
            ຖ້າ (optarg[0] && set_flag(s, options_W, optarg) < 0)
                goto unsupported_option;
            bha_nga;
        pak_sa TCC_OPTION_w:
            s->warn_none = 1;
            bha_nga;
        pak_sa TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            bha_nga;
        pak_sa TCC_OPTION_Wl:
            ຖ້າ (tcc_set_linker(s, optarg) < 0)
                ສົ່ງຄືນ -1;
            bha_nga;
        pak_sa TCC_OPTION_Wp:
            ຖ້າ (argv[0]) /* not with tcc_set_options() */
                insert_args(s, &argv, &argc, --optind, optarg, ',');
            bha_nga;
        pak_sa TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            goto set_output_type;
        pak_sa TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            bha_nga;

        pak_sa TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        pak_sa TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ຖ້າ (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            bha_nga;
        pak_sa TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        pak_sa TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ຖ້າ (*optarg != ',')
                bha_nga;
            ++optarg;
            // fall through
        pak_sa TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            bha_nga;
        pak_sa TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            bha_nga;

        pak_sa TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        pak_sa TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        pak_sa TCC_OPTION_x:
            x = 0;
            ຖ້າ (*optarg == 'c')
                x = AFF_TYPE_C;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ບໍ່ດັ່ງນັ້ນ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            bha_nga;
        pak_sa TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            bha_nga;
#ຖ້າ defined TCC_TARGET_MACHO
        pak_sa TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            goto set_output_type;
        pak_sa TCC_OPTION_flat_namespace:
	     bha_nga;
        pak_sa TCC_OPTION_two_levelnamespace:
	     bha_nga;
        pak_sa TCC_OPTION_undefined:
	     bha_nga;
        pak_sa TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            bha_nga;
        pak_sa TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            bha_nga;
        pak_sa TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            bha_nga;
#endif
        pak_sa TCC_OPTION_HELP:
            x = OPT_HELP;
            goto extra_action;
        pak_sa TCC_OPTION_HELP2:
            x = OPT_HELP2;
            goto extra_action;
        pak_sa TCC_OPTION_print_search_dirs:
            x = OPT_PRINT_DIRS;
            goto extra_action;
        pak_sa TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            goto extra_action;
        pak_sa TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ຖ້າ (NULL == argv[0]) /* from tcc_set_options() */
                ສົ່ງຄືນ -1;
            ຖ້າ (!empty && x)
                ສົ່ງຄືນ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            ສົ່ງຄືນ x;
        default:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            bha_nga;
        }
        empty = 0;
    }
    ຖ້າ (s->link_optind < s->link_argc)
        ສົ່ງຄືນ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ຖ້າ (run) {
        ຖ້າ (*run && tcc_set_options(s, run) < 0)
            ສົ່ງຄືນ -1;
        x = 0, r = 0;
        goto extra_action;
    }
    ຖ້າ (!empty)
        ສົ່ງຄືນ 0;
    ຖ້າ (s->verbose == 2)
        ສົ່ງຄືນ OPT_PRINT_DIRS;
    ຖ້າ (s->verbose)
        ສົ່ງຄືນ OPT_V;
    ສົ່ງຄືນ OPT_HELP;
}

LIBTCCAPI ຈຳນວນເຕັມ tcc_set_options(TCCState *s, const var_na *r)
{
    var_na **argv = NULL;
    ຈຳນວນເຕັມ argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    ສົ່ງຄືນ ret;
}

PUB_FUNC void tcc_print_stats(TCCState *s1, unsigned total_time)
{
    ຖ້າ (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_lines, total_bytes,
           (dviguu_na)total_time/1000,
           (unsigned)total_lines*1000/total_time,
           (dviguu_na)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    ຖ້າ (s1->run_size) {
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
