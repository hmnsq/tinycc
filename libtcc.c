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

#यदि ONE_SOURCE
#अन्तर्भाव "tccpp.c"
#अन्तर्भाव "tccgen.c"
#अन्तर्भाव "tccdbg.c"
#अन्तर्भाव "tccasm.c"
#अन्तर्भाव "tccelf.c"
#अन्तर्भाव "tccrun.c"
#ifdef TCC_TARGET_I386
#अन्तर्भाव "i386-gen.c"
#अन्तर्भाव "i386-link.c"
#अन्तर्भाव "i386-asm.c"
#नोचेद्यदि defined(TCC_TARGET_ARM)
#अन्तर्भाव "arm-gen.c"
#अन्तर्भाव "arm-link.c"
#अन्तर्भाव "arm-asm.c"
#नोचेद्यदि defined(TCC_TARGET_ARM64)
#अन्तर्भाव "arm64-gen.c"
#अन्तर्भाव "arm64-link.c"
#अन्तर्भाव "arm64-asm.c"
#नोचेद्यदि defined(TCC_TARGET_C67)
#अन्तर्भाव "c67-gen.c"
#अन्तर्भाव "c67-link.c"
#अन्तर्भाव "tcccoff.c"
#नोचेद्यदि defined(TCC_TARGET_X86_64)
#अन्तर्भाव "x86_64-gen.c"
#अन्तर्भाव "x86_64-link.c"
#अन्तर्भाव "i386-asm.c"
#नोचेद्यदि defined(TCC_TARGET_RISCV64)
#अन्तर्भाव "riscv64-gen.c"
#अन्तर्भाव "riscv64-link.c"
#अन्तर्भाव "riscv64-asm.c"
#अन्यथा
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#अन्तर्भाव "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#अन्तर्भाव "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#अन्तर्भाव "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA संरचना TCCState *tcc_state;
TCC_SEM(स्थिर tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA शून्य** stk_data;
ST_DATA पूर्णाङ्क nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA पूर्णाङ्क g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC वर्ण *normalize_slashes(वर्ण *path)
{
    वर्ण *p;
    प्रति (p = path; *p; ++p)
        यदि (*p == '\\')
            *p = '/';
    प्रत्यागम path;
}

#यदि defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
स्थिर HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    यदि (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    प्रत्यागम TRUE;
}
#अन्यथा
#define tcc_module रिक्त /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
स्थिर अन्तःस्थ वर्ण *config_tccdir_w32(वर्ण *path)
{
    वर्ण *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    यदि (p > path)
        --p;
    *p = 0;
    प्रत्यागम path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
स्थिर शून्य tcc_add_systemdir(TCCState *s)
{
    वर्ण buf[1000];
    GetSystemDirectoryA(buf, परिमाण buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ध्रुव वर्ण *f, ध्रुव वर्ण *m) {
    प्रत्यागम fopen(f, m);
}
PUB_FUNC पूर्णाङ्क tcc_fclose(FILE *f) {
    प्रत्यागम fclose(f);
}
#endif
/********************************************************/

PUB_FUNC शून्य tcc_enter_state(TCCState *s1)
{
    यदि (s1->error_set_jmp_enabled)
        प्रत्यागम;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC शून्य tcc_exit_state(TCCState *s1)
{
    यदि (s1->error_set_jmp_enabled)
        प्रत्यागम;
    tcc_state = रिक्त;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC वर्ण *pstrcpy(वर्ण *buf, size_t buf_size, ध्रुव वर्ण *s)
{
    वर्ण *q, *q_end;
    पूर्णाङ्क c;

    यदि (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        यावत् (q < q_end) {
            c = *s++;
            यदि (c == '\0')
                भङ्ग;
            *q++ = c;
        }
        *q = '\0';
    }
    प्रत्यागम buf;
}

/* strcat and truncate. */
ST_FUNC वर्ण *pstrcat(वर्ण *buf, size_t buf_size, ध्रुव वर्ण *s)
{
    size_t len;
    len = strlen(buf);
    यदि (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    प्रत्यागम buf;
}

ST_FUNC वर्ण *pstrncpy(वर्ण *out, size_t buf_size, ध्रुव वर्ण *s, size_t अंक)
{
    यदि (अंक >= buf_size)
        अंक = buf_size - 1;
    memcpy(out, s, अंक);
    out[अंक] = '\0';
    प्रत्यागम out;
}

/* extract the basename of a file */
PUB_FUNC वर्ण *tcc_basename(ध्रुव वर्ण *name)
{
    वर्ण *p = (वर्ण *)strchr(name, 0);
    यावत् (p > name && !IS_DIRSEP(p[-1]))
        --p;
    प्रत्यागम p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC वर्ण *tcc_fileextension (ध्रुव वर्ण *name)
{
    वर्ण *b = tcc_basename(name);
    वर्ण *e = strrchr(b, '.');
    प्रत्यागम e ? e : strchr(b, 0);
}

ST_FUNC वर्ण *tcc_load_text(पूर्णाङ्क fd)
{
    पूर्णाङ्क len = lseek(fd, 0, SEEK_END);
    वर्ण *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    प्रत्यागम buf;
}

/* replace *pp by copy of 'str' or NULL */
स्थिर शून्य tcc_set_str(वर्ण **pp, ध्रुव वर्ण *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : रिक्त;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
स्थिर शून्य tcc_concat_str(वर्ण **pp, ध्रुव वर्ण *str, पूर्णाङ्क sep)
{
    पूर्णाङ्क l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    यदि (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef मुक्त
#undef realloc

स्थिर शून्य *default_reallocator(शून्य *ptr, unsigned long size)
{
    शून्य *ptr1;
    यदि (size == 0) {
        मुक्त(ptr);
        ptr1 = रिक्त;
    }
    अन्यथा {
        ptr1 = realloc(ptr, size);
        यदि (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    प्रत्यागम ptr1;
}

ST_FUNC शून्य libc_free(शून्य *ptr)
{
    मुक्त(ptr);
}

/* defined to be not used */
#define मुक्त(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
स्थिर शून्य *(*reallocator)(शून्य*, unsigned long) = default_reallocator;

LIBTCCAPI शून्य tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC शून्य tcc_free(शून्य *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC शून्य *tcc_malloc(unsigned long size)
{
    प्रत्यागम reallocator(0, size);
}

PUB_FUNC शून्य *tcc_realloc(शून्य *ptr, unsigned long size)
{
    प्रत्यागम reallocator(ptr, size);
}

PUB_FUNC शून्य *tcc_mallocz(unsigned long size)
{
    शून्य *ptr;
    ptr = tcc_malloc(size);
    यदि (size)
        memset(ptr, 0, size);
    प्रत्यागम ptr;
}

PUB_FUNC वर्ण *tcc_strdup(ध्रुव वर्ण *str)
{
    वर्ण *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    प्रत्यागम ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned वर्ण *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((वर्ण *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((वर्ण*)ptr - offsetof(mem_debug_header_t, magic3))

संरचना mem_debug_header {
    unsigned magic1;
    unsigned size;
    संरचना mem_debug_header *prev;
    संरचना mem_debug_header *next;
    पूर्णाङ्क पंक्ति_अंक;
    वर्ण file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned वर्ण magic3[4];
};

प्रकारनिर्देश संरचना mem_debug_header mem_debug_header_t;

TCC_SEM(स्थिर mem_sem);
स्थिर mem_debug_header_t *mem_debug_chain;
स्थिर unsigned mem_cur_size;
स्थिर unsigned mem_max_size;
स्थिर पूर्णाङ्क nb_states;

स्थिर mem_debug_header_t *malloc_check(शून्य *ptr, ध्रुव वर्ण *संदेश)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    यदि (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", संदेश);
        यदि (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->पंक्ति_अंक);
        exit(1);
    }
    प्रत्यागम header;
}

PUB_FUNC शून्य *tcc_malloc_debug(unsigned long size, ध्रुव वर्ण *file, पूर्णाङ्क पंक्ति)
{
    पूर्णाङ्क ofs;
    mem_debug_header_t *header;
    यदि (!size)
        प्रत्यागम रिक्त;
    header = tcc_malloc(परिमाण(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->पंक्ति_अंक = पंक्ति;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = रिक्त;
    यदि (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    यदि (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    प्रत्यागम MEM_USER_PTR(header);
}

PUB_FUNC शून्य tcc_free_debug(शून्य *ptr)
{
    mem_debug_header_t *header;
    यदि (!ptr)
        प्रत्यागम;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    यदि (header->next)
        header->next->prev = header->prev;
    यदि (header->prev)
        header->prev->next = header->next;
    यदि (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC शून्य *tcc_mallocz_debug(unsigned long size, ध्रुव वर्ण *file, पूर्णाङ्क पंक्ति)
{
    शून्य *ptr;
    ptr = tcc_malloc_debug(size,file,पंक्ति);
    यदि (size)
        memset(ptr, 0, size);
    प्रत्यागम ptr;
}

PUB_FUNC शून्य *tcc_realloc_debug(शून्य *ptr, unsigned long size, ध्रुव वर्ण *file, पूर्णाङ्क पंक्ति)
{
    mem_debug_header_t *header;
    पूर्णाङ्क mem_debug_chain_update = 0;

    यदि (!ptr)
        प्रत्यागम tcc_malloc_debug(size, file, पंक्ति);
    यदि (!size) {
        tcc_free_debug(ptr);
        प्रत्यागम रिक्त;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, परिमाण(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    यदि (header->next)
        header->next->prev = header;
    यदि (header->prev)
        header->prev->next = header;
    यदि (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    यदि (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    प्रत्यागम MEM_USER_PTR(header);
}

PUB_FUNC वर्ण *tcc_strdup_debug(ध्रुव वर्ण *str, ध्रुव वर्ण *file, पूर्णाङ्क पंक्ति)
{
    वर्ण *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, पंक्ति);
    strcpy(ptr, str);
    प्रत्यागम ptr;
}

PUB_FUNC शून्य tcc_memcheck(पूर्णाङ्क d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    यदि (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        यावत् (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->पंक्ति_अंक, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = रिक्त;
#यदि MEM_DEBUG-0 == 2
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
ST_FUNC पूर्णाङ्क normalized_PATHCMP(ध्रुव वर्ण *f1, ध्रुव वर्ण *f2)
{
    वर्ण *p1, *p2;
    पूर्णाङ्क ret = 1;
    यदि (!!(p1 = realpath(f1, रिक्त))) {
        यदि (!!(p2 = realpath(f2, रिक्त))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    प्रत्यागम ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC शून्य dynarray_add(शून्य *ptab, पूर्णाङ्क *nb_ptr, शून्य *data)
{
    पूर्णाङ्क nb, nb_alloc;
    शून्य **pp;

    nb = *nb_ptr;
    pp = *(शून्य ***)ptab;
    /* every power of two we double array size */
    यदि ((nb & (nb - 1)) == 0) {
        यदि (!nb)
            nb_alloc = 1;
        अन्यथा
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * परिमाण(शून्य *));
        *(शून्य***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC शून्य dynarray_reset(शून्य *pp, पूर्णाङ्क *n)
{
    शून्य **p;
    प्रति (p = *(शून्य***)pp; *n; ++p, --*n)
        यदि (*p)
            tcc_free(*p);
    tcc_free(*(शून्य**)pp);
    *(शून्य**)pp = रिक्त;
}

स्थिर शून्य dynarray_split(वर्ण ***argv, पूर्णाङ्क *argc, ध्रुव वर्ण *p, पूर्णाङ्क sep)
{
    पूर्णाङ्क qot, c;
    CString str;
    प्रति(;;) {
        यावत् (c = (unsigned वर्ण)*p, c <= ' ' && c != '\0')
            ++p;
        यदि (c == '\0')
            भङ्ग;
        cstr_new(&str);
        qot = 0;
        कुरु {
            ++p;
            यदि (sep) { /* e.g. to split -Wl,-opt,arg */
                यदि (c == sep)
                    भङ्ग;
            } अन्यथा {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                यदि (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } अन्यथा यदि (c == '"') {
                    qot ^= 1;
                    अनुवर्त;
                } अन्यथा यदि (c <= ' ' && !qot) {
                    भङ्ग;
                }
            }
            cstr_ccat(&str, c);
        } यावत् (c = (unsigned वर्ण)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

स्थिर शून्य tcc_split_path(TCCState *s, शून्य *p_ary, पूर्णाङ्क *p_nb_ary, ध्रुव वर्ण *in)
{
    ध्रुव वर्ण *p;
    कुरु {
        पूर्णाङ्क c;
        CString str;

        cstr_new(&str);
        प्रति (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            यदि (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                यदि (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                यदि (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                यदि (c == 'f' && file) {
                    /* substitute current file's dir */
                    ध्रुव वर्ण *f = file->true_filename;
                    ध्रुव वर्ण *b = tcc_basename(f);
                    यदि (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    अन्यथा
                        cstr_cat(&str, ".", 1);
                }
            } अन्यथा {
                cstr_ccat(&str, c);
            }
        }
        यदि (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } यावत् (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
गणना { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

स्थिर शून्य error1(पूर्णाङ्क mode, ध्रुव वर्ण *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    पूर्णाङ्क पंक्ति = 0;

    tcc_exit_state(s1);

    यदि (mode == ERROR_WARN) {
        यदि (s1->warn_error)
            mode = ERROR_ERROR;
        यदि (s1->warn_अंक) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            पूर्णाङ्क wopt = *(&s1->warn_none + s1->warn_अंक);
            s1->warn_अंक = 0;
            यदि (0 == (wopt & WARN_ON))
                प्रत्यागम;
            यदि (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            यदि (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        यदि (s1->warn_none)
            प्रत्यागम;
    }

    cstr_new(&cs);
    यदि (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        पंक्ति = va_arg(ap, पूर्णाङ्क), fmt += 3;
    f = रिक्त;
    यदि (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        प्रति (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    यदि (f) {
        प्रति(pf = s1->include_ढेर; pf < s1->include_ढेर_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->पंक्ति_अंक - 1);
        यदि (0 == पंक्ति)
            पंक्ति = f->पंक्ति_अंक - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, पंक्ति);
    } अन्यथा यदि (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } अन्यथा {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    यदि (pp_व्यंजक > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    अन्यथा
        cstr_vprintf(&cs, fmt, ap);
    यदि (!s1->error_func) {
        /* default case: stderr */
        यदि (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (वर्ण*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } अन्यथा {
        s1->error_func(s1->error_opaque, (वर्ण*)cs.data);
    }
    cstr_free(&cs);
    यदि (mode != ERROR_WARN)
        s1->nb_errors++;
    यदि (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        यावत् (nb_stk_data)
            tcc_free(*(शून्य**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI शून्य tcc_set_error_func(TCCState *s, शून्य *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC पूर्णाङ्क _tcc_error_noabort(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    प्रत्यागम -1;
}

#undef _tcc_error
PUB_FUNC शून्य _tcc_error(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC शून्य _tcc_warning(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC शून्य tcc_open_bf(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क initlen)
{
    BufferedFile *bf;
    पूर्णाङ्क buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(परिमाण(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, परिमाण(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->पंक्ति_अंक = 1;
    bf->ifdef_ढेर_ptr = s1->ifdef_ढेर_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC शून्य tcc_close(शून्य)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    यदि (bf->fd > 0) {
        close(bf->fd);
        total_पंक्तियाँ += bf->पंक्ति_अंक - 1;
    }
    यदि (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

स्थिर पूर्णाङ्क _tcc_open(TCCState *s1, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क fd;
    यदि (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    अन्यथा
        fd = open(filename, O_RDONLY | O_द्विआधारी_2);
    यदि ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (पूर्णाङ्क)(s1->include_ढेर_ptr - s1->include_ढेर), "", filename);
    प्रत्यागम fd;
}

ST_FUNC पूर्णाङ्क tcc_open(TCCState *s1, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क fd = _tcc_open(s1, filename);
    यदि (fd < 0)
        प्रत्यागम -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    प्रत्यागम 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
स्थिर पूर्णाङ्क tcc_compile(TCCState *s1, पूर्णाङ्क filetype, ध्रुव वर्ण *str, पूर्णाङ्क fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    यदि (setjmp(s1->error_jmp_buf) == 0) {

        यदि (fd == -1) {
            पूर्णाङ्क len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } अन्यथा {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        यदि (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } अन्यथा {
            tccelf_begin_file(s1);
            यदि (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } अन्यथा {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    प्रत्यागम s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI पूर्णाङ्क tcc_compile_string(TCCState *s, ध्रुव वर्ण *str)
{
    प्रत्यागम tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI शून्य tcc_define_प्रतीक(TCCState *s1, ध्रुव वर्ण *sym, ध्रुव वर्ण *मूल्य)
{
    ध्रुव वर्ण *eq;
    यदि (रिक्त == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    यदि (रिक्त == मूल्य)
        मूल्य = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (पूर्णाङ्क)(eq-sym), sym, मूल्य);
}

/* undefine a preprocessor symbol */
LIBTCCAPI शून्य tcc_undefine_प्रतीक(TCCState *s1, ध्रुव वर्ण *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(शून्य)
{
    TCCState *s;

    s = tcc_mallocz(परिमाण(TCCState));
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
#यदि defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#यदि defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ढेर_ptr = s->include_ढेर;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    प्रत्यागम s;
}

LIBTCCAPI शून्य tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_प्रतीक);
    tcc_free(s1->fini_प्रतीक);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#यदि defined TCC_TARGET_MACHO
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

LIBTCCAPI पूर्णाङ्क tcc_set_output_type(TCCState *s, पूर्णाङ्क output_type)
{
#ifdef CONFIG_TCC_PIE
    यदि (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    यदि (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    यदि (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        प्रत्यागम 0;
    }

    /* add sections */
    tccelf_new(s);

    यदि (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        प्रत्यागम 0;
    }

    यदि (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#नोचेद्यदि defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#अन्यथा
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    यदि (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    प्रत्यागम s->nb_errors ? -1 : 0;
}

LIBTCCAPI पूर्णाङ्क tcc_add_include_path(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI पूर्णाङ्क tcc_add_sysinclude_path(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI पूर्णाङ्क tcc_add_library_path(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI शून्य tcc_set_lib_path(TCCState *s, ध्रुव वर्ण *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ध्रुव वर्ण *dllname, पूर्णाङ्क level)
{
    DLLReference *ref = रिक्त;
    पूर्णाङ्क i;
    प्रति (i = 0; i < s1->nb_loaded_dlls; i++)
        यदि (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            भङ्ग;
        }
    यदि (level == -1)
        प्रत्यागम ref;
    यदि (ref) {
        यदि (level < ref->level)
            ref->level = level;
        ref->found = 1;
        प्रत्यागम ref;
    }
    ref = tcc_mallocz(परिमाण(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    प्रत्यागम ref;
}

स्थिर पूर्णाङ्क tcc_add_द्विआधारी(TCCState *s1, पूर्णाङ्क flags, ध्रुव वर्ण *filename, पूर्णाङ्क fd)
{
    ElfW(Ehdr) ehdr;
    पूर्णाङ्क obj_type;
    ध्रुव वर्ण *saved_filename = s1->current_filename;
    पूर्णाङ्क ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    विकल्प (obj_type) {

    पक्ष AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        भङ्ग;

    पक्ष AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        भङ्ग;

#यदि defined TCC_TARGET_UNIX
    पक्ष AFF_BINTYPE_DYN:
        यदि (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            शून्य* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            यदि (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
#endif
        } अन्यथा
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        भङ्ग;

    स्वभाव:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        भङ्ग;

#नोचेद्यदि defined TCC_TARGET_MACHO
    पक्ष AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        यदि (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            शून्य* dl;
            ध्रुव वर्ण* soname = filename;
            वर्ण *tmp = 0;
            यदि (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                यदि (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            यदि (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } अन्यथा यदि (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } अन्यथा {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        यदि (ret)
            ret = FILE_NOT_RECOGNIZED;
        भङ्ग;

    स्वभाव:
    {
        ध्रुव वर्ण *ext = tcc_fileextension(filename);
        यदि (!strcmp(ext, ".tbd"))
            गच्छ case_dyn_or_tbd;
        यदि (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            गच्छ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        भङ्ग;
    }

#नोचेद्यदि defined TCC_TARGET_PE
    स्वभाव:
        यदि (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        भङ्ग;
#endif

#ifdef TCC_TARGET_COFF
    पक्ष AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        भङ्ग;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    यदि (ret == FILE_NOT_RECOGNIZED)
        प्रत्यागम tcc_error_noabort("%s: unrecognized file type", filename);
    प्रत्यागम ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#यदि defined TARGETOS_OpenBSD && !defined _WIN32
#अन्तर्भाव <glob.h>
स्थिर पूर्णाङ्क tcc_glob_so(TCCState *s1, ध्रुव वर्ण *pattern, वर्ण *buf, पूर्णाङ्क size)
{
    ध्रुव वर्ण *star;
    glob_t g;
    वर्ण *p;
    पूर्णाङ्क i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    यदि (!star || glob(pattern, 0, रिक्त, &g))
        प्रत्यागम -1;
    प्रति (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        यदि (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            अनुवर्त;
        यदि ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    प्रत्यागम v;
}
#endif

स्थिर पूर्णाङ्क guess_filetype(ध्रुव वर्ण *filename)
{
    पूर्णाङ्क filetype = 0;
    यदि (1) {
        /* use a file extension to detect a filetype */
        ध्रुव वर्ण *ext = tcc_fileextension(filename);
        यदि (ext[0]) {
            ext++;
            यदि (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            अन्यथा यदि (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            अन्यथा यदि (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            अन्यथा
                filetype |= AFF_TYPE_BIN;
        } अन्यथा {
            filetype = AFF_TYPE_C;
        }
    }
    प्रत्यागम filetype;
}

ST_FUNC पूर्णाङ्क tcc_add_file_internal(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क flags)
{
    पूर्णाङ्क fd;

#यदि defined TARGETOS_OpenBSD && !defined _WIN32
    वर्ण buf[1024];
    यदि (tcc_glob_so(s1, filename, buf, परिमाण buf) >= 0)
        filename = buf;
#endif

    यदि (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    यदि (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        प्रत्यागम 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    यदि (fd < 0) {
        यदि (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        प्रत्यागम FILE_NOT_FOUND;
    }

    यदि (flags & AFF_TYPE_BIN)
        प्रत्यागम tcc_add_द्विआधारी(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    प्रत्यागम tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI पूर्णाङ्क tcc_add_file(TCCState *s, ध्रुव वर्ण *filename)
{
    प्रत्यागम tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

स्थिर पूर्णाङ्क tcc_add_library_internal(TCCState *s1, ध्रुव वर्ण *fmt,
    ध्रुव वर्ण *filename, पूर्णाङ्क flags, वर्ण **paths, पूर्णाङ्क nb_paths)
{
    वर्ण buf[1024];
    पूर्णाङ्क i, ret;

    प्रति(i = 0; i < nb_paths; i++) {
        snprintf(buf, परिमाण(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        यदि (ret != FILE_NOT_FOUND)
            प्रत्यागम ret;
    }
    यदि (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    प्रत्यागम FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC पूर्णाङ्क tcc_add_dll(TCCState *s, ध्रुव वर्ण *filename, पूर्णाङ्क flags)
{
    प्रत्यागम tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC पूर्णाङ्क tcc_add_support(TCCState *s1, ध्रुव वर्ण *filename)
{
    वर्ण buf[100];
    यदि (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    प्रत्यागम tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC पूर्णाङ्क tcc_add_crt(TCCState *s1, ध्रुव वर्ण *filename)
{
    प्रत्यागम tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णाङ्क tcc_add_library(TCCState *s, ध्रुव वर्ण *libraryname)
{
    स्थिर ध्रुव वर्ण * ध्रुव libs[] = {
#यदि defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#नोचेद्यदि defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#नोचेद्यदि defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#अन्यथा
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        रिक्त
    };
    पूर्णाङ्क flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    यदि (*libraryname == ':') {
        libraryname++;
    } अन्यथा {
        ध्रुव वर्ण * ध्रुव *pp = libs;
        यदि (s->static_link)
            pp += परिमाण(libs) / परिमाण(*libs) - 2; /* only "%s/lib%s.a" */
        यावत् (*pp) {
            पूर्णाङ्क ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            यदि (ret != FILE_NOT_FOUND)
                प्रत्यागम ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    प्रत्यागम tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC शून्य tcc_add_pragma_libs(TCCState *s1)
{
    पूर्णाङ्क i;
    प्रति (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

स्थिर पूर्णाङ्क strstart(ध्रुव वर्ण *val, ध्रुव वर्ण **str)
{
    ध्रुव वर्ण *p, *q;
    p = *str;
    q = val;
    यावत् (*q) {
        यदि (*p != *q)
            प्रत्यागम 0;
        p++;
        q++;
    }
    *str = p;
    प्रत्यागम 1;
}

संरचना lopt {
    TCCState *s;
    ध्रुव वर्ण *opt, *arg;
    पूर्णाङ्क match;
};

/* match linker option */
स्थिर पूर्णाङ्क link_option(संरचना lopt *o, ध्रुव वर्ण *q)
{
    ध्रुव वर्ण *p;
    पूर्णाङ्क c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    यदि (*p++ != '-')
        प्रत्यागम 0;
    यदि (*p == '-')
        p++;
    r = 1;
    यदि (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        यदि (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        अन्यथा यदि (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    यावत् ((c = *q) == *p) {
        यदि (c == '\0')
            गच्छ succ; /* -Wl,-opt */
        ++p;
        यदि (c == '=')
            गच्छ succ; /* -Wl,-opt=arg */
        ++q;
    }
    यदि (*p == '\0') {
        यदि (c == '|')
            गच्छ succ;
        यदि (c == '=' || c == ':') {
            यदि (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                गच्छ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            प्रत्यागम 0;
        }
    } अन्यथा यदि (c == ':')
        गच्छ succ; /* -Wl,-Iarg */
    यावत् (*q)
        यदि (*q++ == '|')
            गच्छ redo;
    प्रत्यागम 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    प्रत्यागम r;
}

स्थिर शून्य args_parser_add_file(TCCState *s, ध्रुव वर्ण* filename, पूर्णाङ्क filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
स्थिर पूर्णाङ्क tcc_set_linker(TCCState *s, ध्रुव वर्ण *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    यावत् (s->link_optind < s->link_argc) {
        वर्ण *end = रिक्त;
        पूर्णाङ्क ignoring = 0;
        संरचना lopt o = {0};
        पूर्णाङ्क r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        यदि (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } अन्यथा यदि (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } अन्यथा यदि (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } अन्यथा यदि (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } अन्यथा यदि (link_option(&o, "init=")) {
            tcc_set_str(&s->init_प्रतीक, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_प्रतीक, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "oformat=")) {
#यदि defined TCC_TARGET_PE
            यदि (0 == strncmp("pe-", o.arg, 3))
#नोचेद्यदि PTR_SIZE == 8
            यदि (0 == strncmp("elf64-", o.arg, 6))
#अन्यथा
            यदि (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            अन्यथा यदि (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_द्विआधारी;
#यदि defined TCC_TARGET_COFF
            अन्यथा यदि (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            अन्यथा
                गच्छ err;
        } अन्यथा यदि (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } अन्यथा यदि (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } अन्यथा यदि (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } अन्यथा यदि (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } अन्यथा यदि (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } अन्यथा यदि (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } अन्यथा यदि (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } अन्यथा यदि (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } अन्यथा यदि (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } अन्यथा यदि (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } अन्यथा यदि (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } अन्यथा यदि (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } अन्यथा यदि (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } अन्यथा यदि (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } अन्यथा यदि (link_option(&o, "stack=")) {
            s->pe_ढेर_size = strtoul(o.arg, &end, 10);
        } अन्यथा यदि (link_option(&o, "subsystem=")) {
            यदि (pe_setsubsy(s, o.arg) < 0)
                गच्छ err;
#नोचेद्यदि defined TCC_TARGET_MACHO
        } अन्यथा यदि (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } अन्यथा यदि (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } अन्यथा यदि (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } अन्यथा यदि (link_option(&o, "as-needed")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "O")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "z=")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } अन्यथा यदि (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } अन्यथा यदि (o.match) {
            प्रत्यागम 0; /* expecting argument with next '-Wl,' */
        } अन्यथा {
    err:
            प्रत्यागम tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        यदि (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    प्रत्यागम 0;
}

प्रकारनिर्देश संरचना TCCOption {
    ध्रुव वर्ण *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

गणना {
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
    TCC_OPTION_print_खोज_dirs,
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

स्थिर ध्रुव TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_खोज_dirs, 0 },
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
    { रिक्त, 0, 0 },
};

प्रकारनिर्देश संरचना FlagDef {
    uint16_t offset;
    uint16_t flags;
    ध्रुव वर्ण *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

स्थिर ध्रुव FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, रिक्त }
};

स्थिर ध्रुव FlagDef options_f[] = {
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
    { 0, 0, रिक्त }
};

स्थिर ध्रुव FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, रिक्त }
};

स्थिर पूर्णाङ्क set_flag(TCCState *s, ध्रुव FlagDef *flags, ध्रुव वर्ण *name)
{
    पूर्णाङ्क मूल्य, mask, ret;
    ध्रुव FlagDef *p;
    ध्रुव वर्ण *r;
    unsigned वर्ण *f;

    r = name, मूल्य = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    यदि ((flags->flags & WD_ALL) && strstart("error=", &r))
        मूल्य = मूल्य ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    प्रति (ret = -1, p = flags; p->name; ++p) {
        यदि (ret) {
            यदि (strcmp(r, p->name))
                अनुवर्त;
        } अन्यथा {
            यदि (0 == (p->flags & WD_ALL))
                अनुवर्त;
        }

        f = (unsigned वर्ण *)s + p->offset;
        *f = (*f & mask) | (मूल्य ^ !!(p->flags & FD_INVERT));

        यदि (ret) {
            ret = 0;
            यदि (strcmp(r, "all"))
                भङ्ग;
        }
    }
    प्रत्यागम ret;
}

स्थिर ध्रुव वर्ण dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#नोचेद्यदि defined TCC_TARGET_X86_64
    "x86_64-pc"
#नोचेद्यदि defined TCC_TARGET_C67
    "c67"
#नोचेद्यदि defined TCC_TARGET_ARM
    "arm"
#नोचेद्यदि defined TCC_TARGET_ARM64
    "aarch64"
#नोचेद्यदि defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#नोचेद्यदि defined(TCC_TARGET_MACHO)
    "apple-darwin"
#नोचेद्यदि TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#नोचेद्यदि TARGETOS_OpenBSD
    "openbsd"
#नोचेद्यदि TARGETOS_NetBSD
    "netbsd"
#नोचेद्यदि CONFIG_TCC_MUSL
    "linux-musl"
#अन्यथा
    "linux-gnu"
#endif
;

#यदि defined TCC_TARGET_MACHO
स्थिर uint32_t parse_version(TCCState *s1, ध्रुव वर्ण *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    वर्ण* last;

    a = strtoul(version, &last, 10);
    यदि (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        यदि (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    यदि (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    प्रत्यागम (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
स्थिर शून्य जोड़ो_args(TCCState *s1, वर्ण ***pargv, पूर्णाङ्क *pargc, पूर्णाङ्क optind, ध्रुव वर्ण *p, पूर्णाङ्क sep)
{
    पूर्णाङ्क argc = 0;
    वर्ण **argv = रिक्त;
    पूर्णाङ्क i;
    प्रति (i = 0; i < *pargc; ++i)
        यदि (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        अन्यथा
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

स्थिर शून्य args_parser_add_file(TCCState *s, ध्रुव वर्ण* filename, पूर्णाङ्क filetype)
{
    संरचना filespec *f = tcc_malloc(परिमाण *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    यदि (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC पूर्णाङ्क tcc_parse_args(TCCState *s, पूर्णाङ्क *pargc, वर्ण ***pargv)
{
    TCCState *s1 = s;
    ध्रुव TCCOption *popt;
    ध्रुव वर्ण *optarg, *r;
    ध्रुव वर्ण *run = रिक्त;
    पूर्णाङ्क optind = 1, empty = 1, x;
    वर्ण **argv = *pargv;
    पूर्णाङ्क argc = *pargc;

    s->link_optind = s->link_argc;

    यावत् (optind < argc) {
        r = argv[optind];
        यदि (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            पूर्णाङ्क fd; वर्ण *p;
            fd = open(++r, O_RDONLY | O_द्विआधारी_2);
            यदि (fd < 0)
                प्रत्यागम tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            जोड़ो_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            अनुवर्त;
        }
        optind++;
        यदि (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            यदि (run)
                भङ्ग;
            अनुवर्त;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        यदि (r[1] == '-' && r[2] == '\0')
            गच्छ dorun;

        /* find option in table */
        प्रति(popt = tcc_options; ; ++popt) {
            ध्रुव वर्ण *p1 = popt->name;
            ध्रुव वर्ण *r1 = r + 1;
            यदि (p1 == रिक्त)
                प्रत्यागम tcc_error_noabort("invalid option -- '%s'", r);
            यदि (!strstart(p1, &r1))
                अनुवर्त;
            optarg = r1;
            यदि (popt->flags & TCC_OPTION_HAS_ARG) {
                यदि (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    यदि (optind >= argc)
                        प्रत्यागम tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } अन्यथा यदि (*r1 != '\0')
                अनुवर्त;
            भङ्ग;
        }

        विकल्प(popt->index) {
        पक्ष TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_D:
            tcc_define_प्रतीक(s, optarg, रिक्त);
            भङ्ग;
        पक्ष TCC_OPTION_U:
            tcc_undefine_प्रतीक(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            अनुवर्त;
        पक्ष TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            भङ्ग;
        पक्ष TCC_OPTION_pthread:
            s->option_pthread = 1;
            भङ्ग;
        पक्ष TCC_OPTION_bench:
            s->do_bench = 1;
            भङ्ग;
#ifdef CONFIG_TCC_BACKTRACE
        पक्ष TCC_OPTION_bt:
            s->rt_अंक_callers = atoi(optarg); /* zero = default (6) */
            गच्छ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            यदि (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            भङ्ग;
#ifdef CONFIG_TCC_BCHECK
        पक्ष TCC_OPTION_b:
            s->do_bounds_check = 1;
            गच्छ enable_backtrace;
#endif
#endif
        पक्ष TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            यदि (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } अन्यथा यदि (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } अन्यथा यदि (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                गच्छ g_redo;
#ifdef TCC_TARGET_PE
            } अन्यथा यदि (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            भङ्ग;
        पक्ष TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            यदि (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            भङ्ग;
        पक्ष TCC_OPTION_d:
            यदि (*optarg == 'D')
                s->dflag = 3;
            अन्यथा यदि (*optarg == 'M')
                s->dflag = 7;
            अन्यथा यदि (*optarg == 't')
                s->dflag = 16;
            अन्यथा यदि (isnum(*optarg))
                g_debug |= atoi(optarg);
            अन्यथा
                गच्छ unsupported_option;
            भङ्ग;
        पक्ष TCC_OPTION_static:
            s->static_link = 1;
            भङ्ग;
        पक्ष TCC_OPTION_std:
            यदि (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            भङ्ग;
        पक्ष TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            गच्छ set_output_type;
        पक्ष TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_o:
            यदि (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            गच्छ set_output_type;
        पक्ष TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            भङ्ग;
        पक्ष TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            भङ्ग;
        पक्ष TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            भङ्ग;
        पक्ष TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            गच्छ set_output_type;
#अन्यथा
            प्रत्यागम tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        पक्ष TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            भङ्ग;
#endif
        पक्ष TCC_OPTION_v:
            कुरु ++s->verbose; यावत् (*optarg++ == 'v');
            अनुवर्त;
        पक्ष TCC_OPTION_f:
            यदि (set_flag(s, options_f, optarg) < 0)
                गच्छ unsupported_option;
            भङ्ग;
#ifdef TCC_TARGET_ARM
        पक्ष TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            यदि (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } अन्यथा यदि (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            अन्यथा
                प्रत्यागम tcc_error_noabort("unsupported float abi '%s'", optarg);
            अनुवर्त;
#endif
        पक्ष TCC_OPTION_m:
            यदि (set_flag(s, options_m, optarg) < 0) {
                यदि (x = atoi(optarg), x != 32 && x != 64)
                    गच्छ unsupported_option;
                यदि (PTR_SIZE != x/8)
                    प्रत्यागम x;
                अनुवर्त;
            }
            भङ्ग;
        पक्ष TCC_OPTION_W:
            यदि (optarg[0] && set_flag(s, options_W, optarg) < 0)
                गच्छ unsupported_option;
            भङ्ग;
        पक्ष TCC_OPTION_w:
            s->warn_none = 1;
            भङ्ग;
        पक्ष TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            भङ्ग;
        पक्ष TCC_OPTION_Wl:
            यदि (tcc_set_linker(s, optarg) < 0)
                प्रत्यागम -1;
            भङ्ग;
        पक्ष TCC_OPTION_Wp:
            यदि (argv[0]) /* not with tcc_set_options() */
                जोड़ो_args(s, &argv, &argc, --optind, optarg, ',');
            भङ्ग;
        पक्ष TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            गच्छ set_output_type;
        पक्ष TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            भङ्ग;

        पक्ष TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        पक्ष TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            यदि (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            भङ्ग;
        पक्ष TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        पक्ष TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            यदि (*optarg != ',')
                भङ्ग;
            ++optarg;
            // fall through
        पक्ष TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            भङ्ग;

        पक्ष TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        पक्ष TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        पक्ष TCC_OPTION_x:
            x = 0;
            यदि (*optarg == 'c')
                x = AFF_TYPE_C;
            अन्यथा यदि (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            अन्यथा यदि (*optarg == 'b')
                x = AFF_TYPE_BIN;
            अन्यथा यदि (*optarg == 'n')
                x = AFF_TYPE_NONE;
            अन्यथा
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            भङ्ग;
        पक्ष TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            भङ्ग;
#यदि defined TCC_TARGET_MACHO
        पक्ष TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            गच्छ set_output_type;
        पक्ष TCC_OPTION_flat_namespace:
	     भङ्ग;
        पक्ष TCC_OPTION_two_levelnamespace:
	     भङ्ग;
        पक्ष TCC_OPTION_undefined:
	     भङ्ग;
        पक्ष TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            भङ्ग;
#endif
        पक्ष TCC_OPTION_HELP:
            x = OPT_HELP;
            गच्छ extra_action;
        पक्ष TCC_OPTION_HELP2:
            x = OPT_HELP2;
            गच्छ extra_action;
        पक्ष TCC_OPTION_print_खोज_dirs:
            x = OPT_PRINT_DIRS;
            गच्छ extra_action;
        पक्ष TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            गच्छ extra_action;
        पक्ष TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            यदि (रिक्त == argv[0]) /* from tcc_set_options() */
                प्रत्यागम -1;
            यदि (!empty && x)
                प्रत्यागम tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            प्रत्यागम x;
        स्वभाव:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            भङ्ग;
        }
        empty = 0;
    }
    यदि (s->link_optind < s->link_argc)
        प्रत्यागम tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    यदि (run) {
        यदि (*run && tcc_set_options(s, run) < 0)
            प्रत्यागम -1;
        x = 0, r = 0;
        गच्छ extra_action;
    }
    यदि (!empty)
        प्रत्यागम 0;
    यदि (s->verbose == 2)
        प्रत्यागम OPT_PRINT_DIRS;
    यदि (s->verbose)
        प्रत्यागम OPT_V;
    प्रत्यागम OPT_HELP;
}

LIBTCCAPI पूर्णाङ्क tcc_set_options(TCCState *s, ध्रुव वर्ण *r)
{
    वर्ण **argv = रिक्त;
    पूर्णाङ्क argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    प्रत्यागम ret;
}

PUB_FUNC शून्य tcc_print_stats(TCCState *s1, unsigned total_time)
{
    यदि (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_पंक्तियाँ, total_bytes,
           (द्विगुण)total_time/1000,
           (unsigned)total_पंक्तियाँ*1000/total_time,
           (द्विगुण)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    यदि (s1->run_size) {
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
