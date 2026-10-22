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

#ако ONE_SOURCE
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
#иначе
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
ST_DATA struct TCCState *tcc_state;
TCC_SEM(static tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA void** stk_data;
ST_DATA цяло nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA цяло g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC char *normalize_slashes(char *path)
{
    char *p;
    за (p = path; *p; ++p)
        ако (*p == '\\')
            *p = '/';
    върни path;
}

#ако defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
static HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ако (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    върни TRUE;
}
#иначе
#define tcc_module NULL /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
static inline char *config_tccdir_w32(char *path)
{
    char *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    ако (p > path)
        --p;
    *p = 0;
    върни path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
static void tcc_add_systemdir(TCCState *s)
{
    char buf[1000];
    GetSystemDirectoryA(buf, sizeof buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(const char *f, const char *m) {
    върни fopen(f, m);
}
PUB_FUNC цяло tcc_fclose(FILE *f) {
    върни fclose(f);
}
#endif
/********************************************************/

PUB_FUNC void tcc_enter_state(TCCState *s1)
{
    ако (s1->error_set_jmp_enabled)
        върни;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC void tcc_exit_state(TCCState *s1)
{
    ако (s1->error_set_jmp_enabled)
        върни;
    tcc_state = NULL;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC char *pstrcpy(char *buf, size_t buf_size, const char *s)
{
    char *q, *q_end;
    цяло c;

    ако (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        докато (q < q_end) {
            c = *s++;
            ако (c == '\0')
                break;
            *q++ = c;
        }
        *q = '\0';
    }
    върни buf;
}

/* strcat and truncate. */
ST_FUNC char *pstrcat(char *buf, size_t buf_size, const char *s)
{
    size_t len;
    len = strlen(buf);
    ако (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    върни buf;
}

ST_FUNC char *pstrncpy(char *out, size_t buf_size, const char *s, size_t num)
{
    ако (num >= buf_size)
        num = buf_size - 1;
    memcpy(out, s, num);
    out[num] = '\0';
    върни out;
}

/* extract the basename of a file */
PUB_FUNC char *tcc_basename(const char *name)
{
    char *p = (char *)strchr(name, 0);
    докато (p > name && !IS_DIRSEP(p[-1]))
        --p;
    върни p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC char *tcc_fileextension (const char *name)
{
    char *b = tcc_basename(name);
    char *e = strrchr(b, '.');
    върни e ? e : strchr(b, 0);
}

ST_FUNC char *tcc_load_text(цяло fd)
{
    цяло len = lseek(fd, 0, SEEK_END);
    char *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    върни buf;
}

/* replace *pp by copy of 'str' or NULL */
static void tcc_set_str(char **pp, const char *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : NULL;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
static void tcc_concat_str(char **pp, const char *str, цяло sep)
{
    цяло l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    ако (l && sep) ((*pp)[l - 1] = sep);
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
    ако (size == 0) {
        free(ptr);
        ptr1 = NULL;
    }
    иначе {
        ptr1 = realloc(ptr, size);
        ако (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    върни ptr1;
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
    върни reallocator(0, size);
}

PUB_FUNC void *tcc_realloc(void *ptr, unsigned long size)
{
    върни reallocator(ptr, size);
}

PUB_FUNC void *tcc_mallocz(unsigned long size)
{
    void *ptr;
    ptr = tcc_malloc(size);
    ако (size)
        memset(ptr, 0, size);
    върни ptr;
}

PUB_FUNC char *tcc_strdup(const char *str)
{
    char *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    върни ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned char *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((char *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((char*)ptr - offsetof(mem_debug_header_t, magic3))

struct mem_debug_header {
    unsigned magic1;
    unsigned size;
    struct mem_debug_header *prev;
    struct mem_debug_header *next;
    цяло line_num;
    char file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned char magic3[4];
};

typedef struct mem_debug_header mem_debug_header_t;

TCC_SEM(static mem_sem);
static mem_debug_header_t *mem_debug_chain;
static unsigned mem_cur_size;
static unsigned mem_max_size;
static цяло nb_states;

static mem_debug_header_t *malloc_check(void *ptr, const char *msg)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    ако (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", msg);
        ако (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->line_num);
        exit(1);
    }
    върни header;
}

PUB_FUNC void *tcc_malloc_debug(unsigned long size, const char *file, цяло line)
{
    цяло ofs;
    mem_debug_header_t *header;
    ако (!size)
        върни NULL;
    header = tcc_malloc(sizeof(mem_debug_header_t) + size);
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
    ако (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    ако (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    върни MEM_USER_PTR(header);
}

PUB_FUNC void tcc_free_debug(void *ptr)
{
    mem_debug_header_t *header;
    ако (!ptr)
        върни;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    ако (header->next)
        header->next->prev = header->prev;
    ако (header->prev)
        header->prev->next = header->next;
    ако (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC void *tcc_mallocz_debug(unsigned long size, const char *file, цяло line)
{
    void *ptr;
    ptr = tcc_malloc_debug(size,file,line);
    ако (size)
        memset(ptr, 0, size);
    върни ptr;
}

PUB_FUNC void *tcc_realloc_debug(void *ptr, unsigned long size, const char *file, цяло line)
{
    mem_debug_header_t *header;
    цяло mem_debug_chain_update = 0;

    ако (!ptr)
        върни tcc_malloc_debug(size, file, line);
    ако (!size) {
        tcc_free_debug(ptr);
        върни NULL;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, sizeof(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    ако (header->next)
        header->next->prev = header;
    ако (header->prev)
        header->prev->next = header;
    ако (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    ако (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    върни MEM_USER_PTR(header);
}

PUB_FUNC char *tcc_strdup_debug(const char *str, const char *file, цяло line)
{
    char *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, line);
    strcpy(ptr, str);
    върни ptr;
}

PUB_FUNC void tcc_memcheck(цяло d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    ако (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        докато (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->line_num, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = NULL;
#ако MEM_DEBUG-0 == 2
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
ST_FUNC цяло normalized_PATHCMP(const char *f1, const char *f2)
{
    char *p1, *p2;
    цяло ret = 1;
    ако (!!(p1 = realpath(f1, NULL))) {
        ако (!!(p2 = realpath(f2, NULL))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    върни ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC void dynarray_add(void *ptab, цяло *nb_ptr, void *data)
{
    цяло nb, nb_alloc;
    void **pp;

    nb = *nb_ptr;
    pp = *(void ***)ptab;
    /* every power of two we double array size */
    ако ((nb & (nb - 1)) == 0) {
        ако (!nb)
            nb_alloc = 1;
        иначе
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * sizeof(void *));
        *(void***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC void dynarray_reset(void *pp, цяло *n)
{
    void **p;
    за (p = *(void***)pp; *n; ++p, --*n)
        ако (*p)
            tcc_free(*p);
    tcc_free(*(void**)pp);
    *(void**)pp = NULL;
}

static void dynarray_split(char ***argv, цяло *argc, const char *p, цяло sep)
{
    цяло qot, c;
    CString str;
    за(;;) {
        докато (c = (unsigned char)*p, c <= ' ' && c != '\0')
            ++p;
        ако (c == '\0')
            break;
        cstr_new(&str);
        qot = 0;
        do {
            ++p;
            ако (sep) { /* e.g. to split -Wl,-opt,arg */
                ако (c == sep)
                    break;
            } иначе {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ако (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } иначе ако (c == '"') {
                    qot ^= 1;
                    continue;
                } иначе ако (c <= ' ' && !qot) {
                    break;
                }
            }
            cstr_ccat(&str, c);
        } докато (c = (unsigned char)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

static void tcc_split_path(TCCState *s, void *p_ary, цяло *p_nb_ary, const char *in)
{
    const char *p;
    do {
        цяло c;
        CString str;

        cstr_new(&str);
        за (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ако (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ако (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                ако (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ако (c == 'f' && file) {
                    /* substitute current file's dir */
                    const char *f = file->true_filename;
                    const char *b = tcc_basename(f);
                    ако (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    иначе
                        cstr_cat(&str, ".", 1);
                }
            } иначе {
                cstr_ccat(&str, c);
            }
        }
        ако (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } докато (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
enum { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

static void error1(цяло mode, const char *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    цяло line = 0;

    tcc_exit_state(s1);

    ако (mode == ERROR_WARN) {
        ако (s1->warn_error)
            mode = ERROR_ERROR;
        ако (s1->warn_num) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            цяло wopt = *(&s1->warn_none + s1->warn_num);
            s1->warn_num = 0;
            ако (0 == (wopt & WARN_ON))
                върни;
            ако (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            ако (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        ако (s1->warn_none)
            върни;
    }

    cstr_new(&cs);
    ако (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        line = va_arg(ap, цяло), fmt += 3;
    f = NULL;
    ако (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        за (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ако (f) {
        за(pf = s1->include_stack; pf < s1->include_stack_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->line_num - 1);
        ако (0 == line)
            line = f->line_num - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, line);
    } иначе ако (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } иначе {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    ако (pp_expr > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    иначе
        cstr_vprintf(&cs, fmt, ap);
    ако (!s1->error_func) {
        /* default case: stderr */
        ако (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (char*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } иначе {
        s1->error_func(s1->error_opaque, (char*)cs.data);
    }
    cstr_free(&cs);
    ако (mode != ERROR_WARN)
        s1->nb_errors++;
    ако (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        докато (nb_stk_data)
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
PUB_FUNC цяло _tcc_error_noabort(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    върни -1;
}

#undef _tcc_error
PUB_FUNC void _tcc_error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC void _tcc_warning(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC void tcc_open_bf(TCCState *s1, const char *filename, цяло initlen)
{
    BufferedFile *bf;
    цяло buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(sizeof(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, sizeof(bf->filename), filename);
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
    ако (bf->fd > 0) {
        close(bf->fd);
        total_lines += bf->line_num - 1;
    }
    ако (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

static цяло _tcc_open(TCCState *s1, const char *filename)
{
    цяло fd;
    ако (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    иначе
        fd = open(filename, O_RDONLY | O_BINARY);
    ако ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (цяло)(s1->include_stack_ptr - s1->include_stack), "", filename);
    върни fd;
}

ST_FUNC цяло tcc_open(TCCState *s1, const char *filename)
{
    цяло fd = _tcc_open(s1, filename);
    ако (fd < 0)
        върни -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    върни 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
static цяло tcc_compile(TCCState *s1, цяло filetype, const char *str, цяло fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    ако (setjmp(s1->error_jmp_buf) == 0) {

        ако (fd == -1) {
            цяло len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } иначе {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        ако (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } иначе {
            tccelf_begin_file(s1);
            ако (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } иначе {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    върни s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI цяло tcc_compile_string(TCCState *s, const char *str)
{
    върни tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI void tcc_define_symbol(TCCState *s1, const char *sym, const char *value)
{
    const char *eq;
    ако (NULL == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ако (NULL == value)
        value = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (цяло)(eq-sym), sym, value);
}

/* undefine a preprocessor symbol */
LIBTCCAPI void tcc_undefine_symbol(TCCState *s1, const char *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(void)
{
    TCCState *s;

    s = tcc_mallocz(sizeof(TCCState));
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
#ако defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#ако defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
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
    върни s;
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
#ако defined TCC_TARGET_MACHO
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

LIBTCCAPI цяло tcc_set_output_type(TCCState *s, цяло output_type)
{
#ifdef CONFIG_TCC_PIE
    ако (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    ако (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ако (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        върни 0;
    }

    /* add sections */
    tccelf_new(s);

    ако (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        върни 0;
    }

    ако (!s->nostdlib_paths)
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

#иначе
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ако (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    върни s->nb_errors ? -1 : 0;
}

LIBTCCAPI цяло tcc_add_include_path(TCCState *s, const char *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    върни 0;
}

LIBTCCAPI цяло tcc_add_sysinclude_path(TCCState *s, const char *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    върни 0;
}

LIBTCCAPI цяло tcc_add_library_path(TCCState *s, const char *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    върни 0;
}

LIBTCCAPI void tcc_set_lib_path(TCCState *s, const char *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, const char *dllname, цяло level)
{
    DLLReference *ref = NULL;
    цяло i;
    за (i = 0; i < s1->nb_loaded_dlls; i++)
        ако (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            break;
        }
    ако (level == -1)
        върни ref;
    ако (ref) {
        ако (level < ref->level)
            ref->level = level;
        ref->found = 1;
        върни ref;
    }
    ref = tcc_mallocz(sizeof(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    върни ref;
}

static цяло tcc_add_binary(TCCState *s1, цяло flags, const char *filename, цяло fd)
{
    ElfW(Ehdr) ehdr;
    цяло obj_type;
    const char *saved_filename = s1->current_filename;
    цяло ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    switch (obj_type) {

    case AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        break;

    case AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        break;

#ако defined TCC_TARGET_UNIX
    case AFF_BINTYPE_DYN:
        ако (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            void* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ако (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            иначе
                ret = FILE_NOT_RECOGNIZED;
#endif
        } иначе
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        break;

    default:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        break;

#elif defined TCC_TARGET_MACHO
    case AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ако (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            void* dl;
            const char* soname = filename;
            char *tmp = 0;
            ако (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ако (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ако (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            иначе
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } иначе ако (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } иначе {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ако (ret)
            ret = FILE_NOT_RECOGNIZED;
        break;

    default:
    {
        const char *ext = tcc_fileextension(filename);
        ако (!strcmp(ext, ".tbd"))
            goto case_dyn_or_tbd;
        ако (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            goto case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        break;
    }

#elif defined TCC_TARGET_PE
    default:
        ако (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        break;
#endif

#ifdef TCC_TARGET_COFF
    case AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        break;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    ако (ret == FILE_NOT_RECOGNIZED)
        върни tcc_error_noabort("%s: unrecognized file type", filename);
    върни ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ако defined TARGETOS_OpenBSD && !defined _WIN32
#include <glob.h>
static цяло tcc_glob_so(TCCState *s1, const char *pattern, char *buf, цяло size)
{
    const char *star;
    glob_t g;
    char *p;
    цяло i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    ако (!star || glob(pattern, 0, NULL, &g))
        върни -1;
    за (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ако (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            continue;
        ако ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    върни v;
}
#endif

static цяло guess_filetype(const char *filename)
{
    цяло filetype = 0;
    ако (1) {
        /* use a file extension to detect a filetype */
        const char *ext = tcc_fileextension(filename);
        ако (ext[0]) {
            ext++;
            ако (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            иначе ако (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            иначе ако (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            иначе
                filetype |= AFF_TYPE_BIN;
        } иначе {
            filetype = AFF_TYPE_C;
        }
    }
    върни filetype;
}

ST_FUNC цяло tcc_add_file_internal(TCCState *s1, const char *filename, цяло flags)
{
    цяло fd;

#ако defined TARGETOS_OpenBSD && !defined _WIN32
    char buf[1024];
    ако (tcc_glob_so(s1, filename, buf, sizeof buf) >= 0)
        filename = buf;
#endif

    ако (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ако (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        върни 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ако (fd < 0) {
        ако (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        върни FILE_NOT_FOUND;
    }

    ако (flags & AFF_TYPE_BIN)
        върни tcc_add_binary(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    върни tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI цяло tcc_add_file(TCCState *s, const char *filename)
{
    върни tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

static цяло tcc_add_library_internal(TCCState *s1, const char *fmt,
    const char *filename, цяло flags, char **paths, цяло nb_paths)
{
    char buf[1024];
    цяло i, ret;

    за(i = 0; i < nb_paths; i++) {
        snprintf(buf, sizeof(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        ако (ret != FILE_NOT_FOUND)
            върни ret;
    }
    ако (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    върни FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC цяло tcc_add_dll(TCCState *s, const char *filename, цяло flags)
{
    върни tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC цяло tcc_add_support(TCCState *s1, const char *filename)
{
    char buf[100];
    ако (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    върни tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC цяло tcc_add_crt(TCCState *s1, const char *filename)
{
    върни tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI цяло tcc_add_library(TCCState *s, const char *libraryname)
{
    static const char * const libs[] = {
#ако defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#elif defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#elif defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#иначе
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        NULL
    };
    цяло flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ако (*libraryname == ':') {
        libraryname++;
    } иначе {
        const char * const *pp = libs;
        ако (s->static_link)
            pp += sizeof(libs) / sizeof(*libs) - 2; /* only "%s/lib%s.a" */
        докато (*pp) {
            цяло ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ако (ret != FILE_NOT_FOUND)
                върни ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    върни tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC void tcc_add_pragma_libs(TCCState *s1)
{
    цяло i;
    за (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

static цяло strstart(const char *val, const char **str)
{
    const char *p, *q;
    p = *str;
    q = val;
    докато (*q) {
        ако (*p != *q)
            върни 0;
        p++;
        q++;
    }
    *str = p;
    върни 1;
}

struct lopt {
    TCCState *s;
    const char *opt, *arg;
    цяло match;
};

/* match linker option */
static цяло link_option(struct lopt *o, const char *q)
{
    const char *p;
    цяло c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ако (*p++ != '-')
        върни 0;
    ако (*p == '-')
        p++;
    r = 1;
    ако (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ако (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        иначе ако (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    докато ((c = *q) == *p) {
        ако (c == '\0')
            goto succ; /* -Wl,-opt */
        ++p;
        ако (c == '=')
            goto succ; /* -Wl,-opt=arg */
        ++q;
    }
    ако (*p == '\0') {
        ако (c == '|')
            goto succ;
        ако (c == '=' || c == ':') {
            ако (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                goto succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            върни 0;
        }
    } иначе ако (c == ':')
        goto succ; /* -Wl,-Iarg */
    докато (*q)
        ако (*q++ == '|')
            goto redo;
    върни 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    върни r;
}

static void args_parser_add_file(TCCState *s, const char* filename, цяло filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
static цяло tcc_set_linker(TCCState *s, const char *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    докато (s->link_optind < s->link_argc) {
        char *end = NULL;
        цяло ignoring = 0;
        struct lopt o = {0};
        цяло r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ако (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } иначе ако (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } иначе ако (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } иначе ако (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } иначе ако (link_option(&o, "init=")) {
            tcc_set_str(&s->init_symbol, o.arg);
            ignoring = 1;
        } иначе ако (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_symbol, o.arg);
            ignoring = 1;
        } иначе ако (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } иначе ако (link_option(&o, "oformat=")) {
#ако defined TCC_TARGET_PE
            ако (0 == strncmp("pe-", o.arg, 3))
#elif PTR_SIZE == 8
            ако (0 == strncmp("elf64-", o.arg, 6))
#иначе
            ако (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            иначе ако (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_BINARY;
#ако defined TCC_TARGET_COFF
            иначе ако (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            иначе
                goto err;
        } иначе ако (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } иначе ако (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } иначе ако (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } иначе ако (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } иначе ако (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } иначе ако (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } иначе ако (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } иначе ако (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } иначе ако (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } иначе ако (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } иначе ако (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } иначе ако (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } иначе ако (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } иначе ако (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } иначе ако (link_option(&o, "stack=")) {
            s->pe_stack_size = strtoul(o.arg, &end, 10);
        } иначе ако (link_option(&o, "subsystem=")) {
            ако (pe_setsubsy(s, o.arg) < 0)
                goto err;
#elif defined TCC_TARGET_MACHO
        } иначе ако (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } иначе ако (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } иначе ако (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } иначе ако (link_option(&o, "as-needed")) {
            ignoring = 1;
        } иначе ако (link_option(&o, "O")) {
            ignoring = 1;
        } иначе ако (link_option(&o, "z=")) {
            ignoring = 1;
        } иначе ако (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } иначе ако (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } иначе ако (o.match) {
            върни 0; /* expecting argument with next '-Wl,' */
        } иначе {
    err:
            върни tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ако (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    върни 0;
}

typedef struct TCCOption {
    const char *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

enum {
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

typedef struct FlagDef {
    uint16_t offset;
    uint16_t flags;
    const char *name;
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

static цяло set_flag(TCCState *s, const FlagDef *flags, const char *name)
{
    цяло value, mask, ret;
    const FlagDef *p;
    const char *r;
    unsigned char *f;

    r = name, value = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ако ((flags->flags & WD_ALL) && strstart("error=", &r))
        value = value ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    за (ret = -1, p = flags; p->name; ++p) {
        ако (ret) {
            ако (strcmp(r, p->name))
                continue;
        } иначе {
            ако (0 == (p->flags & WD_ALL))
                continue;
        }

        f = (unsigned char *)s + p->offset;
        *f = (*f & mask) | (value ^ !!(p->flags & FD_INVERT));

        ако (ret) {
            ret = 0;
            ако (strcmp(r, "all"))
                break;
        }
    }
    върни ret;
}

static const char dumpmachine_str[] =
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
#иначе
    "linux-gnu"
#endif
;

#ако defined TCC_TARGET_MACHO
static uint32_t parse_version(TCCState *s1, const char *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    char* last;

    a = strtoul(version, &last, 10);
    ако (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        ако (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    ако (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    върни (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
static void insert_args(TCCState *s1, char ***pargv, цяло *pargc, цяло optind, const char *p, цяло sep)
{
    цяло argc = 0;
    char **argv = NULL;
    цяло i;
    за (i = 0; i < *pargc; ++i)
        ако (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        иначе
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

static void args_parser_add_file(TCCState *s, const char* filename, цяло filetype)
{
    struct filespec *f = tcc_malloc(sizeof *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    ако (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC цяло tcc_parse_args(TCCState *s, цяло *pargc, char ***pargv)
{
    TCCState *s1 = s;
    const TCCOption *popt;
    const char *optarg, *r;
    const char *run = NULL;
    цяло optind = 1, empty = 1, x;
    char **argv = *pargv;
    цяло argc = *pargc;

    s->link_optind = s->link_argc;

    докато (optind < argc) {
        r = argv[optind];
        ако (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            цяло fd; char *p;
            fd = open(++r, O_RDONLY | O_BINARY);
            ако (fd < 0)
                върни tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            insert_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            continue;
        }
        optind++;
        ако (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            ако (run)
                break;
            continue;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ако (r[1] == '-' && r[2] == '\0')
            goto dorun;

        /* find option in table */
        за(popt = tcc_options; ; ++popt) {
            const char *p1 = popt->name;
            const char *r1 = r + 1;
            ако (p1 == NULL)
                върни tcc_error_noabort("invalid option -- '%s'", r);
            ако (!strstart(p1, &r1))
                continue;
            optarg = r1;
            ако (popt->flags & TCC_OPTION_HAS_ARG) {
                ако (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ако (optind >= argc)
                        върни tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } иначе ако (*r1 != '\0')
                continue;
            break;
        }

        switch(popt->index) {
        case TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            break;
        case TCC_OPTION_D:
            tcc_define_symbol(s, optarg, NULL);
            break;
        case TCC_OPTION_U:
            tcc_undefine_symbol(s, optarg);
            break;
        case TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            break;
        case TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            continue;
        case TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            break;
        case TCC_OPTION_pthread:
            s->option_pthread = 1;
            break;
        case TCC_OPTION_bench:
            s->do_bench = 1;
            break;
#ifdef CONFIG_TCC_BACKTRACE
        case TCC_OPTION_bt:
            s->rt_num_callers = atoi(optarg); /* zero = default (6) */
            goto enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ако (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            break;
#ifdef CONFIG_TCC_BCHECK
        case TCC_OPTION_b:
            s->do_bounds_check = 1;
            goto enable_backtrace;
#endif
#endif
        case TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            ако (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } иначе ако (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } иначе ако (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                goto g_redo;
#ifdef TCC_TARGET_PE
            } иначе ако (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            break;
        case TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            ако (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            break;
        case TCC_OPTION_d:
            ако (*optarg == 'D')
                s->dflag = 3;
            иначе ако (*optarg == 'M')
                s->dflag = 7;
            иначе ако (*optarg == 't')
                s->dflag = 16;
            иначе ако (isnum(*optarg))
                g_debug |= atoi(optarg);
            иначе
                goto unsupported_option;
            break;
        case TCC_OPTION_static:
            s->static_link = 1;
            break;
        case TCC_OPTION_std:
            ако (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            break;
        case TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            goto set_output_type;
        case TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            break;
        case TCC_OPTION_o:
            ако (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            break;
        case TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            goto set_output_type;
        case TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            break;
        case TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            break;
        case TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            break;
        case TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            break;
        case TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            goto set_output_type;
#иначе
            върни tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        case TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            break;
#endif
        case TCC_OPTION_v:
            do ++s->verbose; докато (*optarg++ == 'v');
            continue;
        case TCC_OPTION_f:
            ако (set_flag(s, options_f, optarg) < 0)
                goto unsupported_option;
            break;
#ifdef TCC_TARGET_ARM
        case TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ако (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } иначе ако (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            иначе
                върни tcc_error_noabort("unsupported float abi '%s'", optarg);
            continue;
#endif
        case TCC_OPTION_m:
            ако (set_flag(s, options_m, optarg) < 0) {
                ако (x = atoi(optarg), x != 32 && x != 64)
                    goto unsupported_option;
                ако (PTR_SIZE != x/8)
                    върни x;
                continue;
            }
            break;
        case TCC_OPTION_W:
            ако (optarg[0] && set_flag(s, options_W, optarg) < 0)
                goto unsupported_option;
            break;
        case TCC_OPTION_w:
            s->warn_none = 1;
            break;
        case TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            break;
        case TCC_OPTION_Wl:
            ако (tcc_set_linker(s, optarg) < 0)
                върни -1;
            break;
        case TCC_OPTION_Wp:
            ако (argv[0]) /* not with tcc_set_options() */
                insert_args(s, &argv, &argc, --optind, optarg, ',');
            break;
        case TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            goto set_output_type;
        case TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            break;

        case TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        case TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ако (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            break;
        case TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        case TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ако (*optarg != ',')
                break;
            ++optarg;
            // fall through
        case TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            break;
        case TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            break;

        case TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        case TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        case TCC_OPTION_x:
            x = 0;
            ако (*optarg == 'c')
                x = AFF_TYPE_C;
            иначе ако (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            иначе ако (*optarg == 'b')
                x = AFF_TYPE_BIN;
            иначе ако (*optarg == 'n')
                x = AFF_TYPE_NONE;
            иначе
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            break;
        case TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            break;
#ако defined TCC_TARGET_MACHO
        case TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            goto set_output_type;
        case TCC_OPTION_flat_namespace:
	     break;
        case TCC_OPTION_two_levelnamespace:
	     break;
        case TCC_OPTION_undefined:
	     break;
        case TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            break;
        case TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            break;
        case TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            break;
#endif
        case TCC_OPTION_HELP:
            x = OPT_HELP;
            goto extra_action;
        case TCC_OPTION_HELP2:
            x = OPT_HELP2;
            goto extra_action;
        case TCC_OPTION_print_search_dirs:
            x = OPT_PRINT_DIRS;
            goto extra_action;
        case TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            goto extra_action;
        case TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ако (NULL == argv[0]) /* from tcc_set_options() */
                върни -1;
            ако (!empty && x)
                върни tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            върни x;
        default:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            break;
        }
        empty = 0;
    }
    ако (s->link_optind < s->link_argc)
        върни tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ако (run) {
        ако (*run && tcc_set_options(s, run) < 0)
            върни -1;
        x = 0, r = 0;
        goto extra_action;
    }
    ако (!empty)
        върни 0;
    ако (s->verbose == 2)
        върни OPT_PRINT_DIRS;
    ако (s->verbose)
        върни OPT_V;
    върни OPT_HELP;
}

LIBTCCAPI цяло tcc_set_options(TCCState *s, const char *r)
{
    char **argv = NULL;
    цяло argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    върни ret;
}

PUB_FUNC void tcc_print_stats(TCCState *s1, unsigned total_time)
{
    ако (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_lines, total_bytes,
           (double)total_time/1000,
           (unsigned)total_lines*1000/total_time,
           (double)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    ако (s1->run_size) {
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
