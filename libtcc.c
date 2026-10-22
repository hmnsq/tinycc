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

#اگر ONE_SOURCE
#شامل "tccpp.c"
#شامل "tccgen.c"
#شامل "tccdbg.c"
#شامل "tccasm.c"
#شامل "tccelf.c"
#شامل "tccrun.c"
#ifdef TCC_TARGET_I386
#شامل "i386-gen.c"
#شامل "i386-link.c"
#شامل "i386-asm.c"
#وگرنهاگر defined(TCC_TARGET_ARM)
#شامل "arm-gen.c"
#شامل "arm-link.c"
#شامل "arm-asm.c"
#وگرنهاگر defined(TCC_TARGET_ARM64)
#شامل "arm64-gen.c"
#شامل "arm64-link.c"
#شامل "arm64-asm.c"
#وگرنهاگر defined(TCC_TARGET_C67)
#شامل "c67-gen.c"
#شامل "c67-link.c"
#شامل "tcccoff.c"
#وگرنهاگر defined(TCC_TARGET_X86_64)
#شامل "x86_64-gen.c"
#شامل "x86_64-link.c"
#شامل "i386-asm.c"
#وگرنهاگر defined(TCC_TARGET_RISCV64)
#شامل "riscv64-gen.c"
#شامل "riscv64-link.c"
#شامل "riscv64-asm.c"
#وگرنه
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#شامل "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#شامل "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#شامل "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA ساختار TCCState *tcc_state;
TCC_SEM(ایستا tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA تهی** stk_data;
ST_DATA صحیح nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA صحیح g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC نویسه *normalize_slashes(نویسه *path)
{
    نویسه *p;
    برای (p = path; *p; ++p)
        اگر (*p == '\\')
            *p = '/';
    بازگشت path;
}

#اگر defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ایستا HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    اگر (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    بازگشت TRUE;
}
#وگرنه
#define tcc_module پوچ /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ایستا درونخطی نویسه *config_tccdir_w32(نویسه *path)
{
    نویسه *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    اگر (p > path)
        --p;
    *p = 0;
    بازگشت path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
ایستا تهی tcc_add_systemdir(TCCState *s)
{
    نویسه buf[1000];
    GetSystemDirectoryA(buf, اندازه buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ثابت نویسه *f, ثابت نویسه *m) {
    بازگشت fopen(f, m);
}
PUB_FUNC صحیح tcc_fclose(FILE *f) {
    بازگشت fclose(f);
}
#endif
/********************************************************/

PUB_FUNC تهی tcc_enter_state(TCCState *s1)
{
    اگر (s1->error_set_jmp_enabled)
        بازگشت;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC تهی tcc_exit_state(TCCState *s1)
{
    اگر (s1->error_set_jmp_enabled)
        بازگشت;
    tcc_state = پوچ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC نویسه *pstrcpy(نویسه *buf, size_t buf_size, ثابت نویسه *s)
{
    نویسه *q, *q_end;
    صحیح c;

    اگر (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        وقتی (q < q_end) {
            c = *s++;
            اگر (c == '\0')
                بشکن;
            *q++ = c;
        }
        *q = '\0';
    }
    بازگشت buf;
}

/* strcat and truncate. */
ST_FUNC نویسه *pstrcat(نویسه *buf, size_t buf_size, ثابت نویسه *s)
{
    size_t len;
    len = strlen(buf);
    اگر (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    بازگشت buf;
}

ST_FUNC نویسه *pstrncpy(نویسه *out, size_t buf_size, ثابت نویسه *s, size_t رقم)
{
    اگر (رقم >= buf_size)
        رقم = buf_size - 1;
    memcpy(out, s, رقم);
    out[رقم] = '\0';
    بازگشت out;
}

/* extract the basename of a file */
PUB_FUNC نویسه *tcc_basename(ثابت نویسه *name)
{
    نویسه *p = (نویسه *)strchr(name, 0);
    وقتی (p > name && !IS_DIRSEP(p[-1]))
        --p;
    بازگشت p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC نویسه *tcc_fileextension (ثابت نویسه *name)
{
    نویسه *b = tcc_basename(name);
    نویسه *e = strrchr(b, '.');
    بازگشت e ? e : strchr(b, 0);
}

ST_FUNC نویسه *tcc_load_text(صحیح fd)
{
    صحیح len = lseek(fd, 0, SEEK_END);
    نویسه *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    بازگشت buf;
}

/* replace *pp by copy of 'str' or NULL */
ایستا تهی tcc_set_str(نویسه **pp, ثابت نویسه *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : پوچ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ایستا تهی tcc_concat_str(نویسه **pp, ثابت نویسه *str, صحیح sep)
{
    صحیح l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    اگر (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef آزاد
#undef realloc

ایستا تهی *default_reallocator(تهی *ptr, unsigned long size)
{
    تهی *ptr1;
    اگر (size == 0) {
        آزاد(ptr);
        ptr1 = پوچ;
    }
    وگرنه {
        ptr1 = realloc(ptr, size);
        اگر (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    بازگشت ptr1;
}

ST_FUNC تهی libc_free(تهی *ptr)
{
    آزاد(ptr);
}

/* defined to be not used */
#define آزاد(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ایستا تهی *(*reallocator)(تهی*, unsigned long) = default_reallocator;

LIBTCCAPI تهی tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC تهی tcc_free(تهی *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC تهی *tcc_malloc(unsigned long size)
{
    بازگشت reallocator(0, size);
}

PUB_FUNC تهی *tcc_realloc(تهی *ptr, unsigned long size)
{
    بازگشت reallocator(ptr, size);
}

PUB_FUNC تهی *tcc_mallocz(unsigned long size)
{
    تهی *ptr;
    ptr = tcc_malloc(size);
    اگر (size)
        memset(ptr, 0, size);
    بازگشت ptr;
}

PUB_FUNC نویسه *tcc_strdup(ثابت نویسه *str)
{
    نویسه *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    بازگشت ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned نویسه *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((نویسه *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((نویسه*)ptr - offsetof(mem_debug_header_t, magic3))

ساختار mem_debug_header {
    unsigned magic1;
    unsigned size;
    ساختار mem_debug_header *prev;
    ساختار mem_debug_header *next;
    صحیح سطر_رقم;
    نویسه file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned نویسه magic3[4];
};

تعریفنوع ساختار mem_debug_header mem_debug_header_t;

TCC_SEM(ایستا mem_sem);
ایستا mem_debug_header_t *mem_debug_chain;
ایستا unsigned mem_cur_size;
ایستا unsigned mem_max_size;
ایستا صحیح nb_states;

ایستا mem_debug_header_t *malloc_check(تهی *ptr, ثابت نویسه *پیام)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    اگر (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", پیام);
        اگر (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->سطر_رقم);
        exit(1);
    }
    بازگشت header;
}

PUB_FUNC تهی *tcc_malloc_debug(unsigned long size, ثابت نویسه *file, صحیح سطر)
{
    صحیح ofs;
    mem_debug_header_t *header;
    اگر (!size)
        بازگشت پوچ;
    header = tcc_malloc(اندازه(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->سطر_رقم = سطر;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = پوچ;
    اگر (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    اگر (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    بازگشت MEM_USER_PTR(header);
}

PUB_FUNC تهی tcc_free_debug(تهی *ptr)
{
    mem_debug_header_t *header;
    اگر (!ptr)
        بازگشت;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    اگر (header->next)
        header->next->prev = header->prev;
    اگر (header->prev)
        header->prev->next = header->next;
    اگر (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC تهی *tcc_mallocz_debug(unsigned long size, ثابت نویسه *file, صحیح سطر)
{
    تهی *ptr;
    ptr = tcc_malloc_debug(size,file,سطر);
    اگر (size)
        memset(ptr, 0, size);
    بازگشت ptr;
}

PUB_FUNC تهی *tcc_realloc_debug(تهی *ptr, unsigned long size, ثابت نویسه *file, صحیح سطر)
{
    mem_debug_header_t *header;
    صحیح mem_debug_chain_update = 0;

    اگر (!ptr)
        بازگشت tcc_malloc_debug(size, file, سطر);
    اگر (!size) {
        tcc_free_debug(ptr);
        بازگشت پوچ;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, اندازه(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    اگر (header->next)
        header->next->prev = header;
    اگر (header->prev)
        header->prev->next = header;
    اگر (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    اگر (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    بازگشت MEM_USER_PTR(header);
}

PUB_FUNC نویسه *tcc_strdup_debug(ثابت نویسه *str, ثابت نویسه *file, صحیح سطر)
{
    نویسه *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, سطر);
    strcpy(ptr, str);
    بازگشت ptr;
}

PUB_FUNC تهی tcc_memcheck(صحیح d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    اگر (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        وقتی (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->سطر_رقم, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = پوچ;
#اگر MEM_DEBUG-0 == 2
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
ST_FUNC صحیح normalized_PATHCMP(ثابت نویسه *f1, ثابت نویسه *f2)
{
    نویسه *p1, *p2;
    صحیح ret = 1;
    اگر (!!(p1 = realpath(f1, پوچ))) {
        اگر (!!(p2 = realpath(f2, پوچ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    بازگشت ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC تهی dynarray_add(تهی *ptab, صحیح *nb_ptr, تهی *data)
{
    صحیح nb, nb_alloc;
    تهی **pp;

    nb = *nb_ptr;
    pp = *(تهی ***)ptab;
    /* every power of two we double array size */
    اگر ((nb & (nb - 1)) == 0) {
        اگر (!nb)
            nb_alloc = 1;
        وگرنه
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * اندازه(تهی *));
        *(تهی***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC تهی dynarray_reset(تهی *pp, صحیح *n)
{
    تهی **p;
    برای (p = *(تهی***)pp; *n; ++p, --*n)
        اگر (*p)
            tcc_free(*p);
    tcc_free(*(تهی**)pp);
    *(تهی**)pp = پوچ;
}

ایستا تهی dynarray_split(نویسه ***argv, صحیح *argc, ثابت نویسه *p, صحیح sep)
{
    صحیح qot, c;
    CString str;
    برای(;;) {
        وقتی (c = (unsigned نویسه)*p, c <= ' ' && c != '\0')
            ++p;
        اگر (c == '\0')
            بشکن;
        cstr_new(&str);
        qot = 0;
        انجامبده {
            ++p;
            اگر (sep) { /* e.g. to split -Wl,-opt,arg */
                اگر (c == sep)
                    بشکن;
            } وگرنه {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                اگر (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } وگرنه اگر (c == '"') {
                    qot ^= 1;
                    ادامه;
                } وگرنه اگر (c <= ' ' && !qot) {
                    بشکن;
                }
            }
            cstr_ccat(&str, c);
        } وقتی (c = (unsigned نویسه)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

ایستا تهی tcc_split_path(TCCState *s, تهی *p_ary, صحیح *p_nb_ary, ثابت نویسه *in)
{
    ثابت نویسه *p;
    انجامبده {
        صحیح c;
        CString str;

        cstr_new(&str);
        برای (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            اگر (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                اگر (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                اگر (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                اگر (c == 'f' && file) {
                    /* substitute current file's dir */
                    ثابت نویسه *f = file->true_filename;
                    ثابت نویسه *b = tcc_basename(f);
                    اگر (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    وگرنه
                        cstr_cat(&str, ".", 1);
                }
            } وگرنه {
                cstr_ccat(&str, c);
            }
        }
        اگر (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } وقتی (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
شمارش { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ایستا تهی error1(صحیح mode, ثابت نویسه *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    صحیح سطر = 0;

    tcc_exit_state(s1);

    اگر (mode == ERROR_WARN) {
        اگر (s1->warn_error)
            mode = ERROR_ERROR;
        اگر (s1->warn_رقم) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            صحیح wopt = *(&s1->warn_none + s1->warn_رقم);
            s1->warn_رقم = 0;
            اگر (0 == (wopt & WARN_ON))
                بازگشت;
            اگر (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            اگر (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        اگر (s1->warn_none)
            بازگشت;
    }

    cstr_new(&cs);
    اگر (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        سطر = va_arg(ap, صحیح), fmt += 3;
    f = پوچ;
    اگر (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        برای (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    اگر (f) {
        برای(pf = s1->include_پشته; pf < s1->include_پشته_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->سطر_رقم - 1);
        اگر (0 == سطر)
            سطر = f->سطر_رقم - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, سطر);
    } وگرنه اگر (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } وگرنه {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    اگر (pp_عبارت > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    وگرنه
        cstr_vprintf(&cs, fmt, ap);
    اگر (!s1->error_func) {
        /* default case: stderr */
        اگر (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (نویسه*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } وگرنه {
        s1->error_func(s1->error_opaque, (نویسه*)cs.data);
    }
    cstr_free(&cs);
    اگر (mode != ERROR_WARN)
        s1->nb_errors++;
    اگر (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        وقتی (nb_stk_data)
            tcc_free(*(تهی**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI تهی tcc_set_error_func(TCCState *s, تهی *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC صحیح _tcc_error_noabort(ثابت نویسه *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    بازگشت -1;
}

#undef _tcc_error
PUB_FUNC تهی _tcc_error(ثابت نویسه *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC تهی _tcc_warning(ثابت نویسه *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC تهی tcc_open_bf(TCCState *s1, ثابت نویسه *filename, صحیح initlen)
{
    BufferedFile *bf;
    صحیح buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(اندازه(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, اندازه(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->سطر_رقم = 1;
    bf->ifdef_پشته_ptr = s1->ifdef_پشته_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC تهی tcc_close(تهی)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    اگر (bf->fd > 0) {
        close(bf->fd);
        total_سطرها += bf->سطر_رقم - 1;
    }
    اگر (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ایستا صحیح _tcc_open(TCCState *s1, ثابت نویسه *filename)
{
    صحیح fd;
    اگر (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    وگرنه
        fd = open(filename, O_RDONLY | O_دودویی_2);
    اگر ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (صحیح)(s1->include_پشته_ptr - s1->include_پشته), "", filename);
    بازگشت fd;
}

ST_FUNC صحیح tcc_open(TCCState *s1, ثابت نویسه *filename)
{
    صحیح fd = _tcc_open(s1, filename);
    اگر (fd < 0)
        بازگشت -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    بازگشت 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ایستا صحیح tcc_compile(TCCState *s1, صحیح filetype, ثابت نویسه *str, صحیح fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    اگر (setjmp(s1->error_jmp_buf) == 0) {

        اگر (fd == -1) {
            صحیح len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } وگرنه {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        اگر (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } وگرنه {
            tccelf_begin_file(s1);
            اگر (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } وگرنه {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    بازگشت s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI صحیح tcc_compile_string(TCCState *s, ثابت نویسه *str)
{
    بازگشت tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI تهی tcc_define_نماد(TCCState *s1, ثابت نویسه *sym, ثابت نویسه *مقدار)
{
    ثابت نویسه *eq;
    اگر (پوچ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    اگر (پوچ == مقدار)
        مقدار = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (صحیح)(eq-sym), sym, مقدار);
}

/* undefine a preprocessor symbol */
LIBTCCAPI تهی tcc_undefine_نماد(TCCState *s1, ثابت نویسه *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(تهی)
{
    TCCState *s;

    s = tcc_mallocz(اندازه(TCCState));
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
#اگر defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#اگر defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_پشته_ptr = s->include_پشته;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    بازگشت s;
}

LIBTCCAPI تهی tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_نماد);
    tcc_free(s1->fini_نماد);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#اگر defined TCC_TARGET_MACHO
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

LIBTCCAPI صحیح tcc_set_output_type(TCCState *s, صحیح output_type)
{
#ifdef CONFIG_TCC_PIE
    اگر (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    اگر (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    اگر (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        بازگشت 0;
    }

    /* add sections */
    tccelf_new(s);

    اگر (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        بازگشت 0;
    }

    اگر (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#وگرنهاگر defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#وگرنه
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    اگر (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    بازگشت s->nb_errors ? -1 : 0;
}

LIBTCCAPI صحیح tcc_add_include_path(TCCState *s, ثابت نویسه *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    بازگشت 0;
}

LIBTCCAPI صحیح tcc_add_sysinclude_path(TCCState *s, ثابت نویسه *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    بازگشت 0;
}

LIBTCCAPI صحیح tcc_add_library_path(TCCState *s, ثابت نویسه *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    بازگشت 0;
}

LIBTCCAPI تهی tcc_set_lib_path(TCCState *s, ثابت نویسه *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ثابت نویسه *dllname, صحیح level)
{
    DLLReference *ref = پوچ;
    صحیح i;
    برای (i = 0; i < s1->nb_loaded_dlls; i++)
        اگر (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            بشکن;
        }
    اگر (level == -1)
        بازگشت ref;
    اگر (ref) {
        اگر (level < ref->level)
            ref->level = level;
        ref->found = 1;
        بازگشت ref;
    }
    ref = tcc_mallocz(اندازه(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    بازگشت ref;
}

ایستا صحیح tcc_add_دودویی(TCCState *s1, صحیح flags, ثابت نویسه *filename, صحیح fd)
{
    ElfW(Ehdr) ehdr;
    صحیح obj_type;
    ثابت نویسه *saved_filename = s1->current_filename;
    صحیح ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    انتخاب (obj_type) {

    حالت AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        بشکن;

    حالت AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        بشکن;

#اگر defined TCC_TARGET_UNIX
    حالت AFF_BINTYPE_DYN:
        اگر (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            تهی* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            اگر (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            وگرنه
                ret = FILE_NOT_RECOGNIZED;
#endif
        } وگرنه
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        بشکن;

    پیشفرض:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        بشکن;

#وگرنهاگر defined TCC_TARGET_MACHO
    حالت AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        اگر (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            تهی* dl;
            ثابت نویسه* soname = filename;
            نویسه *tmp = 0;
            اگر (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                اگر (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            اگر (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            وگرنه
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } وگرنه اگر (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } وگرنه {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        اگر (ret)
            ret = FILE_NOT_RECOGNIZED;
        بشکن;

    پیشفرض:
    {
        ثابت نویسه *ext = tcc_fileextension(filename);
        اگر (!strcmp(ext, ".tbd"))
            برو case_dyn_or_tbd;
        اگر (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            برو case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        بشکن;
    }

#وگرنهاگر defined TCC_TARGET_PE
    پیشفرض:
        اگر (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        بشکن;
#endif

#ifdef TCC_TARGET_COFF
    حالت AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        بشکن;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    اگر (ret == FILE_NOT_RECOGNIZED)
        بازگشت tcc_error_noabort("%s: unrecognized file type", filename);
    بازگشت ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#اگر defined TARGETOS_OpenBSD && !defined _WIN32
#شامل <glob.h>
ایستا صحیح tcc_glob_so(TCCState *s1, ثابت نویسه *pattern, نویسه *buf, صحیح size)
{
    ثابت نویسه *star;
    glob_t g;
    نویسه *p;
    صحیح i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    اگر (!star || glob(pattern, 0, پوچ, &g))
        بازگشت -1;
    برای (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        اگر (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            ادامه;
        اگر ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    بازگشت v;
}
#endif

ایستا صحیح guess_filetype(ثابت نویسه *filename)
{
    صحیح filetype = 0;
    اگر (1) {
        /* use a file extension to detect a filetype */
        ثابت نویسه *ext = tcc_fileextension(filename);
        اگر (ext[0]) {
            ext++;
            اگر (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            وگرنه اگر (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            وگرنه اگر (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            وگرنه
                filetype |= AFF_TYPE_BIN;
        } وگرنه {
            filetype = AFF_TYPE_C;
        }
    }
    بازگشت filetype;
}

ST_FUNC صحیح tcc_add_file_internal(TCCState *s1, ثابت نویسه *filename, صحیح flags)
{
    صحیح fd;

#اگر defined TARGETOS_OpenBSD && !defined _WIN32
    نویسه buf[1024];
    اگر (tcc_glob_so(s1, filename, buf, اندازه buf) >= 0)
        filename = buf;
#endif

    اگر (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    اگر (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        بازگشت 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    اگر (fd < 0) {
        اگر (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        بازگشت FILE_NOT_FOUND;
    }

    اگر (flags & AFF_TYPE_BIN)
        بازگشت tcc_add_دودویی(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    بازگشت tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI صحیح tcc_add_file(TCCState *s, ثابت نویسه *filename)
{
    بازگشت tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ایستا صحیح tcc_add_library_internal(TCCState *s1, ثابت نویسه *fmt,
    ثابت نویسه *filename, صحیح flags, نویسه **paths, صحیح nb_paths)
{
    نویسه buf[1024];
    صحیح i, ret;

    برای(i = 0; i < nb_paths; i++) {
        snprintf(buf, اندازه(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        اگر (ret != FILE_NOT_FOUND)
            بازگشت ret;
    }
    اگر (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    بازگشت FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC صحیح tcc_add_dll(TCCState *s, ثابت نویسه *filename, صحیح flags)
{
    بازگشت tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC صحیح tcc_add_support(TCCState *s1, ثابت نویسه *filename)
{
    نویسه buf[100];
    اگر (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    بازگشت tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC صحیح tcc_add_crt(TCCState *s1, ثابت نویسه *filename)
{
    بازگشت tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحیح tcc_add_library(TCCState *s, ثابت نویسه *libraryname)
{
    ایستا ثابت نویسه * ثابت libs[] = {
#اگر defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#وگرنهاگر defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#وگرنهاگر defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#وگرنه
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        پوچ
    };
    صحیح flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    اگر (*libraryname == ':') {
        libraryname++;
    } وگرنه {
        ثابت نویسه * ثابت *pp = libs;
        اگر (s->static_link)
            pp += اندازه(libs) / اندازه(*libs) - 2; /* only "%s/lib%s.a" */
        وقتی (*pp) {
            صحیح ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            اگر (ret != FILE_NOT_FOUND)
                بازگشت ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    بازگشت tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC تهی tcc_add_pragma_libs(TCCState *s1)
{
    صحیح i;
    برای (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ایستا صحیح strstart(ثابت نویسه *val, ثابت نویسه **str)
{
    ثابت نویسه *p, *q;
    p = *str;
    q = val;
    وقتی (*q) {
        اگر (*p != *q)
            بازگشت 0;
        p++;
        q++;
    }
    *str = p;
    بازگشت 1;
}

ساختار lopt {
    TCCState *s;
    ثابت نویسه *opt, *arg;
    صحیح match;
};

/* match linker option */
ایستا صحیح link_option(ساختار lopt *o, ثابت نویسه *q)
{
    ثابت نویسه *p;
    صحیح c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    اگر (*p++ != '-')
        بازگشت 0;
    اگر (*p == '-')
        p++;
    r = 1;
    اگر (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        اگر (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        وگرنه اگر (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    وقتی ((c = *q) == *p) {
        اگر (c == '\0')
            برو succ; /* -Wl,-opt */
        ++p;
        اگر (c == '=')
            برو succ; /* -Wl,-opt=arg */
        ++q;
    }
    اگر (*p == '\0') {
        اگر (c == '|')
            برو succ;
        اگر (c == '=' || c == ':') {
            اگر (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                برو succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            بازگشت 0;
        }
    } وگرنه اگر (c == ':')
        برو succ; /* -Wl,-Iarg */
    وقتی (*q)
        اگر (*q++ == '|')
            برو redo;
    بازگشت 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    بازگشت r;
}

ایستا تهی args_parser_add_file(TCCState *s, ثابت نویسه* filename, صحیح filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ایستا صحیح tcc_set_linker(TCCState *s, ثابت نویسه *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    وقتی (s->link_optind < s->link_argc) {
        نویسه *end = پوچ;
        صحیح ignoring = 0;
        ساختار lopt o = {0};
        صحیح r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        اگر (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } وگرنه اگر (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } وگرنه اگر (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } وگرنه اگر (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } وگرنه اگر (link_option(&o, "init=")) {
            tcc_set_str(&s->init_نماد, o.arg);
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_نماد, o.arg);
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "oformat=")) {
#اگر defined TCC_TARGET_PE
            اگر (0 == strncmp("pe-", o.arg, 3))
#وگرنهاگر PTR_SIZE == 8
            اگر (0 == strncmp("elf64-", o.arg, 6))
#وگرنه
            اگر (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            وگرنه اگر (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_دودویی;
#اگر defined TCC_TARGET_COFF
            وگرنه اگر (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            وگرنه
                برو err;
        } وگرنه اگر (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } وگرنه اگر (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } وگرنه اگر (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } وگرنه اگر (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } وگرنه اگر (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } وگرنه اگر (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } وگرنه اگر (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } وگرنه اگر (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } وگرنه اگر (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } وگرنه اگر (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } وگرنه اگر (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } وگرنه اگر (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } وگرنه اگر (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } وگرنه اگر (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } وگرنه اگر (link_option(&o, "stack=")) {
            s->pe_پشته_size = strtoul(o.arg, &end, 10);
        } وگرنه اگر (link_option(&o, "subsystem=")) {
            اگر (pe_setsubsy(s, o.arg) < 0)
                برو err;
#وگرنهاگر defined TCC_TARGET_MACHO
        } وگرنه اگر (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } وگرنه اگر (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } وگرنه اگر (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } وگرنه اگر (link_option(&o, "as-needed")) {
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "O")) {
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "z=")) {
            ignoring = 1;
        } وگرنه اگر (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } وگرنه اگر (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } وگرنه اگر (o.match) {
            بازگشت 0; /* expecting argument with next '-Wl,' */
        } وگرنه {
    err:
            بازگشت tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        اگر (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    بازگشت 0;
}

تعریفنوع ساختار TCCOption {
    ثابت نویسه *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

شمارش {
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
    TCC_OPTION_print_جستجو_dirs,
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

ایستا ثابت TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_جستجو_dirs, 0 },
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
    { پوچ, 0, 0 },
};

تعریفنوع ساختار FlagDef {
    uint16_t offset;
    uint16_t flags;
    ثابت نویسه *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

ایستا ثابت FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, پوچ }
};

ایستا ثابت FlagDef options_f[] = {
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
    { 0, 0, پوچ }
};

ایستا ثابت FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, پوچ }
};

ایستا صحیح set_flag(TCCState *s, ثابت FlagDef *flags, ثابت نویسه *name)
{
    صحیح مقدار, mask, ret;
    ثابت FlagDef *p;
    ثابت نویسه *r;
    unsigned نویسه *f;

    r = name, مقدار = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    اگر ((flags->flags & WD_ALL) && strstart("error=", &r))
        مقدار = مقدار ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    برای (ret = -1, p = flags; p->name; ++p) {
        اگر (ret) {
            اگر (strcmp(r, p->name))
                ادامه;
        } وگرنه {
            اگر (0 == (p->flags & WD_ALL))
                ادامه;
        }

        f = (unsigned نویسه *)s + p->offset;
        *f = (*f & mask) | (مقدار ^ !!(p->flags & FD_INVERT));

        اگر (ret) {
            ret = 0;
            اگر (strcmp(r, "all"))
                بشکن;
        }
    }
    بازگشت ret;
}

ایستا ثابت نویسه dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#وگرنهاگر defined TCC_TARGET_X86_64
    "x86_64-pc"
#وگرنهاگر defined TCC_TARGET_C67
    "c67"
#وگرنهاگر defined TCC_TARGET_ARM
    "arm"
#وگرنهاگر defined TCC_TARGET_ARM64
    "aarch64"
#وگرنهاگر defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#وگرنهاگر defined(TCC_TARGET_MACHO)
    "apple-darwin"
#وگرنهاگر TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#وگرنهاگر TARGETOS_OpenBSD
    "openbsd"
#وگرنهاگر TARGETOS_NetBSD
    "netbsd"
#وگرنهاگر CONFIG_TCC_MUSL
    "linux-musl"
#وگرنه
    "linux-gnu"
#endif
;

#اگر defined TCC_TARGET_MACHO
ایستا uint32_t parse_version(TCCState *s1, ثابت نویسه *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    نویسه* last;

    a = strtoul(version, &last, 10);
    اگر (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        اگر (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    اگر (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    بازگشت (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ایستا تهی درج_args(TCCState *s1, نویسه ***pargv, صحیح *pargc, صحیح optind, ثابت نویسه *p, صحیح sep)
{
    صحیح argc = 0;
    نویسه **argv = پوچ;
    صحیح i;
    برای (i = 0; i < *pargc; ++i)
        اگر (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        وگرنه
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ایستا تهی args_parser_add_file(TCCState *s, ثابت نویسه* filename, صحیح filetype)
{
    ساختار filespec *f = tcc_malloc(اندازه *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    اگر (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC صحیح tcc_parse_args(TCCState *s, صحیح *pargc, نویسه ***pargv)
{
    TCCState *s1 = s;
    ثابت TCCOption *popt;
    ثابت نویسه *optarg, *r;
    ثابت نویسه *run = پوچ;
    صحیح optind = 1, empty = 1, x;
    نویسه **argv = *pargv;
    صحیح argc = *pargc;

    s->link_optind = s->link_argc;

    وقتی (optind < argc) {
        r = argv[optind];
        اگر (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            صحیح fd; نویسه *p;
            fd = open(++r, O_RDONLY | O_دودویی_2);
            اگر (fd < 0)
                بازگشت tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            درج_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ادامه;
        }
        optind++;
        اگر (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            اگر (run)
                بشکن;
            ادامه;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        اگر (r[1] == '-' && r[2] == '\0')
            برو dorun;

        /* find option in table */
        برای(popt = tcc_options; ; ++popt) {
            ثابت نویسه *p1 = popt->name;
            ثابت نویسه *r1 = r + 1;
            اگر (p1 == پوچ)
                بازگشت tcc_error_noabort("invalid option -- '%s'", r);
            اگر (!strstart(p1, &r1))
                ادامه;
            optarg = r1;
            اگر (popt->flags & TCC_OPTION_HAS_ARG) {
                اگر (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    اگر (optind >= argc)
                        بازگشت tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } وگرنه اگر (*r1 != '\0')
                ادامه;
            بشکن;
        }

        انتخاب(popt->index) {
        حالت TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            بشکن;
        حالت TCC_OPTION_D:
            tcc_define_نماد(s, optarg, پوچ);
            بشکن;
        حالت TCC_OPTION_U:
            tcc_undefine_نماد(s, optarg);
            بشکن;
        حالت TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            بشکن;
        حالت TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            ادامه;
        حالت TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            بشکن;
        حالت TCC_OPTION_pthread:
            s->option_pthread = 1;
            بشکن;
        حالت TCC_OPTION_bench:
            s->do_bench = 1;
            بشکن;
#ifdef CONFIG_TCC_BACKTRACE
        حالت TCC_OPTION_bt:
            s->rt_رقم_callers = atoi(optarg); /* zero = default (6) */
            برو enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            اگر (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            بشکن;
#ifdef CONFIG_TCC_BCHECK
        حالت TCC_OPTION_b:
            s->do_bounds_check = 1;
            برو enable_backtrace;
#endif
#endif
        حالت TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            اگر (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } وگرنه اگر (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } وگرنه اگر (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                برو g_redo;
#ifdef TCC_TARGET_PE
            } وگرنه اگر (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            بشکن;
        حالت TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            اگر (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            بشکن;
        حالت TCC_OPTION_d:
            اگر (*optarg == 'D')
                s->dflag = 3;
            وگرنه اگر (*optarg == 'M')
                s->dflag = 7;
            وگرنه اگر (*optarg == 't')
                s->dflag = 16;
            وگرنه اگر (isnum(*optarg))
                g_debug |= atoi(optarg);
            وگرنه
                برو unsupported_option;
            بشکن;
        حالت TCC_OPTION_static:
            s->static_link = 1;
            بشکن;
        حالت TCC_OPTION_std:
            اگر (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            بشکن;
        حالت TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            برو set_output_type;
        حالت TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            بشکن;
        حالت TCC_OPTION_o:
            اگر (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            بشکن;
        حالت TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            برو set_output_type;
        حالت TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            بشکن;
        حالت TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            بشکن;
        حالت TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            بشکن;
        حالت TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            بشکن;
        حالت TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            برو set_output_type;
#وگرنه
            بازگشت tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        حالت TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            بشکن;
#endif
        حالت TCC_OPTION_v:
            انجامبده ++s->verbose; وقتی (*optarg++ == 'v');
            ادامه;
        حالت TCC_OPTION_f:
            اگر (set_flag(s, options_f, optarg) < 0)
                برو unsupported_option;
            بشکن;
#ifdef TCC_TARGET_ARM
        حالت TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            اگر (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } وگرنه اگر (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            وگرنه
                بازگشت tcc_error_noabort("unsupported float abi '%s'", optarg);
            ادامه;
#endif
        حالت TCC_OPTION_m:
            اگر (set_flag(s, options_m, optarg) < 0) {
                اگر (x = atoi(optarg), x != 32 && x != 64)
                    برو unsupported_option;
                اگر (PTR_SIZE != x/8)
                    بازگشت x;
                ادامه;
            }
            بشکن;
        حالت TCC_OPTION_W:
            اگر (optarg[0] && set_flag(s, options_W, optarg) < 0)
                برو unsupported_option;
            بشکن;
        حالت TCC_OPTION_w:
            s->warn_none = 1;
            بشکن;
        حالت TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            بشکن;
        حالت TCC_OPTION_Wl:
            اگر (tcc_set_linker(s, optarg) < 0)
                بازگشت -1;
            بشکن;
        حالت TCC_OPTION_Wp:
            اگر (argv[0]) /* not with tcc_set_options() */
                درج_args(s, &argv, &argc, --optind, optarg, ',');
            بشکن;
        حالت TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            برو set_output_type;
        حالت TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            بشکن;

        حالت TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        حالت TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            اگر (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            بشکن;
        حالت TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        حالت TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            اگر (*optarg != ',')
                بشکن;
            ++optarg;
            // fall through
        حالت TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            بشکن;
        حالت TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            بشکن;

        حالت TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        حالت TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        حالت TCC_OPTION_x:
            x = 0;
            اگر (*optarg == 'c')
                x = AFF_TYPE_C;
            وگرنه اگر (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            وگرنه اگر (*optarg == 'b')
                x = AFF_TYPE_BIN;
            وگرنه اگر (*optarg == 'n')
                x = AFF_TYPE_NONE;
            وگرنه
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            بشکن;
        حالت TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            بشکن;
#اگر defined TCC_TARGET_MACHO
        حالت TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            برو set_output_type;
        حالت TCC_OPTION_flat_namespace:
	     بشکن;
        حالت TCC_OPTION_two_levelnamespace:
	     بشکن;
        حالت TCC_OPTION_undefined:
	     بشکن;
        حالت TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            بشکن;
        حالت TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            بشکن;
        حالت TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            بشکن;
#endif
        حالت TCC_OPTION_HELP:
            x = OPT_HELP;
            برو extra_action;
        حالت TCC_OPTION_HELP2:
            x = OPT_HELP2;
            برو extra_action;
        حالت TCC_OPTION_print_جستجو_dirs:
            x = OPT_PRINT_DIRS;
            برو extra_action;
        حالت TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            برو extra_action;
        حالت TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            اگر (پوچ == argv[0]) /* from tcc_set_options() */
                بازگشت -1;
            اگر (!empty && x)
                بازگشت tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            بازگشت x;
        پیشفرض:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            بشکن;
        }
        empty = 0;
    }
    اگر (s->link_optind < s->link_argc)
        بازگشت tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    اگر (run) {
        اگر (*run && tcc_set_options(s, run) < 0)
            بازگشت -1;
        x = 0, r = 0;
        برو extra_action;
    }
    اگر (!empty)
        بازگشت 0;
    اگر (s->verbose == 2)
        بازگشت OPT_PRINT_DIRS;
    اگر (s->verbose)
        بازگشت OPT_V;
    بازگشت OPT_HELP;
}

LIBTCCAPI صحیح tcc_set_options(TCCState *s, ثابت نویسه *r)
{
    نویسه **argv = پوچ;
    صحیح argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    بازگشت ret;
}

PUB_FUNC تهی tcc_print_stats(TCCState *s1, unsigned total_time)
{
    اگر (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_سطرها, total_bytes,
           (دوگانه)total_time/1000,
           (unsigned)total_سطرها*1000/total_time,
           (دوگانه)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    اگر (s1->run_size) {
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
