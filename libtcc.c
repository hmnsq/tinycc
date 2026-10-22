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

#যদি ONE_SOURCE
#অন্তর্ভাব "tccpp.c"
#অন্তর্ভাব "tccgen.c"
#অন্তর্ভাব "tccdbg.c"
#অন্তর্ভাব "tccasm.c"
#অন্তর্ভাব "tccelf.c"
#অন্তর্ভাব "tccrun.c"
#ifdef TCC_TARGET_I386
#অন্তর্ভাব "i386-gen.c"
#অন্তর্ভাব "i386-link.c"
#অন্তর্ভাব "i386-asm.c"
#নোচেদ্যদি defined(TCC_TARGET_ARM)
#অন্তর্ভাব "arm-gen.c"
#অন্তর্ভাব "arm-link.c"
#অন্তর্ভাব "arm-asm.c"
#নোচেদ্যদি defined(TCC_TARGET_ARM64)
#অন্তর্ভাব "arm64-gen.c"
#অন্তর্ভাব "arm64-link.c"
#অন্তর্ভাব "arm64-asm.c"
#নোচেদ্যদি defined(TCC_TARGET_C67)
#অন্তর্ভাব "c67-gen.c"
#অন্তর্ভাব "c67-link.c"
#অন্তর্ভাব "tcccoff.c"
#নোচেদ্যদি defined(TCC_TARGET_X86_64)
#অন্তর্ভাব "x86_64-gen.c"
#অন্তর্ভাব "x86_64-link.c"
#অন্তর্ভাব "i386-asm.c"
#নোচেদ্যদি defined(TCC_TARGET_RISCV64)
#অন্তর্ভাব "riscv64-gen.c"
#অন্তর্ভাব "riscv64-link.c"
#অন্তর্ভাব "riscv64-asm.c"
#অন্যথা
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#অন্তর্ভাব "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#অন্তর্ভাব "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#অন্তর্ভাব "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA সংরচনা TCCState *tcc_state;
TCC_SEM(স্থির tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA শূন্য** stk_data;
ST_DATA পূর্ণাঙ্ক nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA পূর্ণাঙ্ক g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC বর্ণ *normalize_slashes(বর্ণ *path)
{
    বর্ণ *p;
    প্রতি (p = path; *p; ++p)
        যদি (*p == '\\')
            *p = '/';
    প্রত্যাগম path;
}

#যদি defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
স্থির HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    যদি (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    প্রত্যাগম TRUE;
}
#অন্যথা
#define tcc_module রিক্ত /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
স্থির অন্তঃস্থ বর্ণ *config_tccdir_w32(বর্ণ *path)
{
    বর্ণ *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    যদি (p > path)
        --p;
    *p = 0;
    প্রত্যাগম path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
স্থির শূন্য tcc_add_systemdir(TCCState *s)
{
    বর্ণ buf[1000];
    GetSystemDirectoryA(buf, পরিমাণ buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ধ্রুব বর্ণ *f, ধ্রুব বর্ণ *m) {
    প্রত্যাগম fopen(f, m);
}
PUB_FUNC পূর্ণাঙ্ক tcc_fclose(FILE *f) {
    প্রত্যাগম fclose(f);
}
#endif
/********************************************************/

PUB_FUNC শূন্য tcc_enter_state(TCCState *s1)
{
    যদি (s1->error_set_jmp_enabled)
        প্রত্যাগম;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC শূন্য tcc_exit_state(TCCState *s1)
{
    যদি (s1->error_set_jmp_enabled)
        প্রত্যাগম;
    tcc_state = রিক্ত;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC বর্ণ *pstrcpy(বর্ণ *buf, size_t buf_size, ধ্রুব বর্ণ *s)
{
    বর্ণ *q, *q_end;
    পূর্ণাঙ্ক c;

    যদি (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        যাবত্ (q < q_end) {
            c = *s++;
            যদি (c == '\0')
                ভঙ্গ;
            *q++ = c;
        }
        *q = '\0';
    }
    প্রত্যাগম buf;
}

/* strcat and truncate. */
ST_FUNC বর্ণ *pstrcat(বর্ণ *buf, size_t buf_size, ধ্রুব বর্ণ *s)
{
    size_t len;
    len = strlen(buf);
    যদি (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    প্রত্যাগম buf;
}

ST_FUNC বর্ণ *pstrncpy(বর্ণ *out, size_t buf_size, ধ্রুব বর্ণ *s, size_t অঙ্ক)
{
    যদি (অঙ্ক >= buf_size)
        অঙ্ক = buf_size - 1;
    memcpy(out, s, অঙ্ক);
    out[অঙ্ক] = '\0';
    প্রত্যাগম out;
}

/* extract the basename of a file */
PUB_FUNC বর্ণ *tcc_basename(ধ্রুব বর্ণ *name)
{
    বর্ণ *p = (বর্ণ *)strchr(name, 0);
    যাবত্ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    প্রত্যাগম p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC বর্ণ *tcc_fileextension (ধ্রুব বর্ণ *name)
{
    বর্ণ *b = tcc_basename(name);
    বর্ণ *e = strrchr(b, '.');
    প্রত্যাগম e ? e : strchr(b, 0);
}

ST_FUNC বর্ণ *tcc_load_text(পূর্ণাঙ্ক fd)
{
    পূর্ণাঙ্ক len = lseek(fd, 0, SEEK_END);
    বর্ণ *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    প্রত্যাগম buf;
}

/* replace *pp by copy of 'str' or NULL */
স্থির শূন্য tcc_set_str(বর্ণ **pp, ধ্রুব বর্ণ *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : রিক্ত;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
স্থির শূন্য tcc_concat_str(বর্ণ **pp, ধ্রুব বর্ণ *str, পূর্ণাঙ্ক sep)
{
    পূর্ণাঙ্ক l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    যদি (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef মুক্ত
#undef realloc

স্থির শূন্য *default_reallocator(শূন্য *ptr, unsigned long size)
{
    শূন্য *ptr1;
    যদি (size == 0) {
        মুক্ত(ptr);
        ptr1 = রিক্ত;
    }
    অন্যথা {
        ptr1 = realloc(ptr, size);
        যদি (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    প্রত্যাগম ptr1;
}

ST_FUNC শূন্য libc_free(শূন্য *ptr)
{
    মুক্ত(ptr);
}

/* defined to be not used */
#define মুক্ত(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
স্থির শূন্য *(*reallocator)(শূন্য*, unsigned long) = default_reallocator;

LIBTCCAPI শূন্য tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC শূন্য tcc_free(শূন্য *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC শূন্য *tcc_malloc(unsigned long size)
{
    প্রত্যাগম reallocator(0, size);
}

PUB_FUNC শূন্য *tcc_realloc(শূন্য *ptr, unsigned long size)
{
    প্রত্যাগম reallocator(ptr, size);
}

PUB_FUNC শূন্য *tcc_mallocz(unsigned long size)
{
    শূন্য *ptr;
    ptr = tcc_malloc(size);
    যদি (size)
        memset(ptr, 0, size);
    প্রত্যাগম ptr;
}

PUB_FUNC বর্ণ *tcc_strdup(ধ্রুব বর্ণ *str)
{
    বর্ণ *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    প্রত্যাগম ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned বর্ণ *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((বর্ণ *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((বর্ণ*)ptr - offsetof(mem_debug_header_t, magic3))

সংরচনা mem_debug_header {
    unsigned magic1;
    unsigned size;
    সংরচনা mem_debug_header *prev;
    সংরচনা mem_debug_header *next;
    পূর্ণাঙ্ক সারি_অঙ্ক;
    বর্ণ file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned বর্ণ magic3[4];
};

প্রকারনির্দেশ সংরচনা mem_debug_header mem_debug_header_t;

TCC_SEM(স্থির mem_sem);
স্থির mem_debug_header_t *mem_debug_chain;
স্থির unsigned mem_cur_size;
স্থির unsigned mem_max_size;
স্থির পূর্ণাঙ্ক nb_states;

স্থির mem_debug_header_t *malloc_check(শূন্য *ptr, ধ্রুব বর্ণ *বার্তা)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    যদি (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", বার্তা);
        যদি (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->সারি_অঙ্ক);
        exit(1);
    }
    প্রত্যাগম header;
}

PUB_FUNC শূন্য *tcc_malloc_debug(unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি)
{
    পূর্ণাঙ্ক ofs;
    mem_debug_header_t *header;
    যদি (!size)
        প্রত্যাগম রিক্ত;
    header = tcc_malloc(পরিমাণ(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->সারি_অঙ্ক = সারি;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = রিক্ত;
    যদি (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    যদি (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    প্রত্যাগম MEM_USER_PTR(header);
}

PUB_FUNC শূন্য tcc_free_debug(শূন্য *ptr)
{
    mem_debug_header_t *header;
    যদি (!ptr)
        প্রত্যাগম;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    যদি (header->next)
        header->next->prev = header->prev;
    যদি (header->prev)
        header->prev->next = header->next;
    যদি (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC শূন্য *tcc_mallocz_debug(unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি)
{
    শূন্য *ptr;
    ptr = tcc_malloc_debug(size,file,সারি);
    যদি (size)
        memset(ptr, 0, size);
    প্রত্যাগম ptr;
}

PUB_FUNC শূন্য *tcc_realloc_debug(শূন্য *ptr, unsigned long size, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি)
{
    mem_debug_header_t *header;
    পূর্ণাঙ্ক mem_debug_chain_update = 0;

    যদি (!ptr)
        প্রত্যাগম tcc_malloc_debug(size, file, সারি);
    যদি (!size) {
        tcc_free_debug(ptr);
        প্রত্যাগম রিক্ত;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, পরিমাণ(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    যদি (header->next)
        header->next->prev = header;
    যদি (header->prev)
        header->prev->next = header;
    যদি (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    যদি (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    প্রত্যাগম MEM_USER_PTR(header);
}

PUB_FUNC বর্ণ *tcc_strdup_debug(ধ্রুব বর্ণ *str, ধ্রুব বর্ণ *file, পূর্ণাঙ্ক সারি)
{
    বর্ণ *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, সারি);
    strcpy(ptr, str);
    প্রত্যাগম ptr;
}

PUB_FUNC শূন্য tcc_memcheck(পূর্ণাঙ্ক d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    যদি (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        যাবত্ (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->সারি_অঙ্ক, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = রিক্ত;
#যদি MEM_DEBUG-0 == 2
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
ST_FUNC পূর্ণাঙ্ক normalized_PATHCMP(ধ্রুব বর্ণ *f1, ধ্রুব বর্ণ *f2)
{
    বর্ণ *p1, *p2;
    পূর্ণাঙ্ক ret = 1;
    যদি (!!(p1 = realpath(f1, রিক্ত))) {
        যদি (!!(p2 = realpath(f2, রিক্ত))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    প্রত্যাগম ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC শূন্য dynarray_add(শূন্য *ptab, পূর্ণাঙ্ক *nb_ptr, শূন্য *data)
{
    পূর্ণাঙ্ক nb, nb_alloc;
    শূন্য **pp;

    nb = *nb_ptr;
    pp = *(শূন্য ***)ptab;
    /* every power of two we double array size */
    যদি ((nb & (nb - 1)) == 0) {
        যদি (!nb)
            nb_alloc = 1;
        অন্যথা
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * পরিমাণ(শূন্য *));
        *(শূন্য***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC শূন্য dynarray_reset(শূন্য *pp, পূর্ণাঙ্ক *n)
{
    শূন্য **p;
    প্রতি (p = *(শূন্য***)pp; *n; ++p, --*n)
        যদি (*p)
            tcc_free(*p);
    tcc_free(*(শূন্য**)pp);
    *(শূন্য**)pp = রিক্ত;
}

স্থির শূন্য dynarray_split(বর্ণ ***argv, পূর্ণাঙ্ক *argc, ধ্রুব বর্ণ *p, পূর্ণাঙ্ক sep)
{
    পূর্ণাঙ্ক qot, c;
    CString str;
    প্রতি(;;) {
        যাবত্ (c = (unsigned বর্ণ)*p, c <= ' ' && c != '\0')
            ++p;
        যদি (c == '\0')
            ভঙ্গ;
        cstr_new(&str);
        qot = 0;
        কুরু {
            ++p;
            যদি (sep) { /* e.g. to split -Wl,-opt,arg */
                যদি (c == sep)
                    ভঙ্গ;
            } অন্যথা {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                যদি (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } অন্যথা যদি (c == '"') {
                    qot ^= 1;
                    অনুবর্ত;
                } অন্যথা যদি (c <= ' ' && !qot) {
                    ভঙ্গ;
                }
            }
            cstr_ccat(&str, c);
        } যাবত্ (c = (unsigned বর্ণ)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

স্থির শূন্য tcc_split_path(TCCState *s, শূন্য *p_ary, পূর্ণাঙ্ক *p_nb_ary, ধ্রুব বর্ণ *in)
{
    ধ্রুব বর্ণ *p;
    কুরু {
        পূর্ণাঙ্ক c;
        CString str;

        cstr_new(&str);
        প্রতি (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            যদি (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                যদি (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                যদি (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                যদি (c == 'f' && file) {
                    /* substitute current file's dir */
                    ধ্রুব বর্ণ *f = file->true_filename;
                    ধ্রুব বর্ণ *b = tcc_basename(f);
                    যদি (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    অন্যথা
                        cstr_cat(&str, ".", 1);
                }
            } অন্যথা {
                cstr_ccat(&str, c);
            }
        }
        যদি (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } যাবত্ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
গণনা { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

স্থির শূন্য error1(পূর্ণাঙ্ক mode, ধ্রুব বর্ণ *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    পূর্ণাঙ্ক সারি = 0;

    tcc_exit_state(s1);

    যদি (mode == ERROR_WARN) {
        যদি (s1->warn_error)
            mode = ERROR_ERROR;
        যদি (s1->warn_অঙ্ক) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            পূর্ণাঙ্ক wopt = *(&s1->warn_none + s1->warn_অঙ্ক);
            s1->warn_অঙ্ক = 0;
            যদি (0 == (wopt & WARN_ON))
                প্রত্যাগম;
            যদি (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            যদি (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        যদি (s1->warn_none)
            প্রত্যাগম;
    }

    cstr_new(&cs);
    যদি (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        সারি = va_arg(ap, পূর্ণাঙ্ক), fmt += 3;
    f = রিক্ত;
    যদি (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        প্রতি (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    যদি (f) {
        প্রতি(pf = s1->include_স্তূপ; pf < s1->include_স্তূপ_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->সারি_অঙ্ক - 1);
        যদি (0 == সারি)
            সারি = f->সারি_অঙ্ক - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, সারি);
    } অন্যথা যদি (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } অন্যথা {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    যদি (pp_রাশিমালা > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    অন্যথা
        cstr_vprintf(&cs, fmt, ap);
    যদি (!s1->error_func) {
        /* default case: stderr */
        যদি (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (বর্ণ*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } অন্যথা {
        s1->error_func(s1->error_opaque, (বর্ণ*)cs.data);
    }
    cstr_free(&cs);
    যদি (mode != ERROR_WARN)
        s1->nb_errors++;
    যদি (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        যাবত্ (nb_stk_data)
            tcc_free(*(শূন্য**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI শূন্য tcc_set_error_func(TCCState *s, শূন্য *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC পূর্ণাঙ্ক _tcc_error_noabort(ধ্রুব বর্ণ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    প্রত্যাগম -1;
}

#undef _tcc_error
PUB_FUNC শূন্য _tcc_error(ধ্রুব বর্ণ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC শূন্য _tcc_warning(ধ্রুব বর্ণ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC শূন্য tcc_open_bf(TCCState *s1, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক initlen)
{
    BufferedFile *bf;
    পূর্ণাঙ্ক buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(পরিমাণ(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, পরিমাণ(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->সারি_অঙ্ক = 1;
    bf->ifdef_স্তূপ_ptr = s1->ifdef_স্তূপ_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC শূন্য tcc_close(শূন্য)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    যদি (bf->fd > 0) {
        close(bf->fd);
        total_সারিগুলি += bf->সারি_অঙ্ক - 1;
    }
    যদি (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

স্থির পূর্ণাঙ্ক _tcc_open(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    পূর্ণাঙ্ক fd;
    যদি (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    অন্যথা
        fd = open(filename, O_RDONLY | O_দ্বিমিক_2);
    যদি ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (পূর্ণাঙ্ক)(s1->include_স্তূপ_ptr - s1->include_স্তূপ), "", filename);
    প্রত্যাগম fd;
}

ST_FUNC পূর্ণাঙ্ক tcc_open(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    পূর্ণাঙ্ক fd = _tcc_open(s1, filename);
    যদি (fd < 0)
        প্রত্যাগম -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    প্রত্যাগম 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
স্থির পূর্ণাঙ্ক tcc_compile(TCCState *s1, পূর্ণাঙ্ক filetype, ধ্রুব বর্ণ *str, পূর্ণাঙ্ক fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    যদি (setjmp(s1->error_jmp_buf) == 0) {

        যদি (fd == -1) {
            পূর্ণাঙ্ক len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } অন্যথা {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        যদি (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } অন্যথা {
            tccelf_begin_file(s1);
            যদি (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } অন্যথা {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    প্রত্যাগম s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_compile_string(TCCState *s, ধ্রুব বর্ণ *str)
{
    প্রত্যাগম tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI শূন্য tcc_define_প্রতীক(TCCState *s1, ধ্রুব বর্ণ *sym, ধ্রুব বর্ণ *মান)
{
    ধ্রুব বর্ণ *eq;
    যদি (রিক্ত == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    যদি (রিক্ত == মান)
        মান = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (পূর্ণাঙ্ক)(eq-sym), sym, মান);
}

/* undefine a preprocessor symbol */
LIBTCCAPI শূন্য tcc_undefine_প্রতীক(TCCState *s1, ধ্রুব বর্ণ *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(শূন্য)
{
    TCCState *s;

    s = tcc_mallocz(পরিমাণ(TCCState));
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
#যদি defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#যদি defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_স্তূপ_ptr = s->include_স্তূপ;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    প্রত্যাগম s;
}

LIBTCCAPI শূন্য tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_প্রতীক);
    tcc_free(s1->fini_প্রতীক);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#যদি defined TCC_TARGET_MACHO
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

LIBTCCAPI পূর্ণাঙ্ক tcc_set_output_type(TCCState *s, পূর্ণাঙ্ক output_type)
{
#ifdef CONFIG_TCC_PIE
    যদি (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    যদি (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    যদি (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        প্রত্যাগম 0;
    }

    /* add sections */
    tccelf_new(s);

    যদি (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        প্রত্যাগম 0;
    }

    যদি (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#নোচেদ্যদি defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#অন্যথা
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    যদি (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    প্রত্যাগম s->nb_errors ? -1 : 0;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_add_include_path(TCCState *s, ধ্রুব বর্ণ *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    প্রত্যাগম 0;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_add_sysinclude_path(TCCState *s, ধ্রুব বর্ণ *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    প্রত্যাগম 0;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_add_library_path(TCCState *s, ধ্রুব বর্ণ *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    প্রত্যাগম 0;
}

LIBTCCAPI শূন্য tcc_set_lib_path(TCCState *s, ধ্রুব বর্ণ *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ধ্রুব বর্ণ *dllname, পূর্ণাঙ্ক level)
{
    DLLReference *ref = রিক্ত;
    পূর্ণাঙ্ক i;
    প্রতি (i = 0; i < s1->nb_loaded_dlls; i++)
        যদি (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ভঙ্গ;
        }
    যদি (level == -1)
        প্রত্যাগম ref;
    যদি (ref) {
        যদি (level < ref->level)
            ref->level = level;
        ref->found = 1;
        প্রত্যাগম ref;
    }
    ref = tcc_mallocz(পরিমাণ(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    প্রত্যাগম ref;
}

স্থির পূর্ণাঙ্ক tcc_add_দ্বিমিক(TCCState *s1, পূর্ণাঙ্ক flags, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক fd)
{
    ElfW(Ehdr) ehdr;
    পূর্ণাঙ্ক obj_type;
    ধ্রুব বর্ণ *saved_filename = s1->current_filename;
    পূর্ণাঙ্ক ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    বিকল্প (obj_type) {

    পক্ষ AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        ভঙ্গ;

    পক্ষ AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        ভঙ্গ;

#যদি defined TCC_TARGET_UNIX
    পক্ষ AFF_BINTYPE_DYN:
        যদি (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            শূন্য* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            যদি (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            অন্যথা
                ret = FILE_NOT_RECOGNIZED;
#endif
        } অন্যথা
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ভঙ্গ;

    স্বভাব:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        ভঙ্গ;

#নোচেদ্যদি defined TCC_TARGET_MACHO
    পক্ষ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        যদি (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            শূন্য* dl;
            ধ্রুব বর্ণ* soname = filename;
            বর্ণ *tmp = 0;
            যদি (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                যদি (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            যদি (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            অন্যথা
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } অন্যথা যদি (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } অন্যথা {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        যদি (ret)
            ret = FILE_NOT_RECOGNIZED;
        ভঙ্গ;

    স্বভাব:
    {
        ধ্রুব বর্ণ *ext = tcc_fileextension(filename);
        যদি (!strcmp(ext, ".tbd"))
            গচ্ছ case_dyn_or_tbd;
        যদি (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            গচ্ছ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ভঙ্গ;
    }

#নোচেদ্যদি defined TCC_TARGET_PE
    স্বভাব:
        যদি (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ভঙ্গ;
#endif

#ifdef TCC_TARGET_COFF
    পক্ষ AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        ভঙ্গ;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    যদি (ret == FILE_NOT_RECOGNIZED)
        প্রত্যাগম tcc_error_noabort("%s: unrecognized file type", filename);
    প্রত্যাগম ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#যদি defined TARGETOS_OpenBSD && !defined _WIN32
#অন্তর্ভাব <glob.h>
স্থির পূর্ণাঙ্ক tcc_glob_so(TCCState *s1, ধ্রুব বর্ণ *pattern, বর্ণ *buf, পূর্ণাঙ্ক size)
{
    ধ্রুব বর্ণ *star;
    glob_t g;
    বর্ণ *p;
    পূর্ণাঙ্ক i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    যদি (!star || glob(pattern, 0, রিক্ত, &g))
        প্রত্যাগম -1;
    প্রতি (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        যদি (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            অনুবর্ত;
        যদি ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    প্রত্যাগম v;
}
#endif

স্থির পূর্ণাঙ্ক guess_filetype(ধ্রুব বর্ণ *filename)
{
    পূর্ণাঙ্ক filetype = 0;
    যদি (1) {
        /* use a file extension to detect a filetype */
        ধ্রুব বর্ণ *ext = tcc_fileextension(filename);
        যদি (ext[0]) {
            ext++;
            যদি (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            অন্যথা যদি (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            অন্যথা যদি (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            অন্যথা
                filetype |= AFF_TYPE_BIN;
        } অন্যথা {
            filetype = AFF_TYPE_C;
        }
    }
    প্রত্যাগম filetype;
}

ST_FUNC পূর্ণাঙ্ক tcc_add_file_internal(TCCState *s1, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flags)
{
    পূর্ণাঙ্ক fd;

#যদি defined TARGETOS_OpenBSD && !defined _WIN32
    বর্ণ buf[1024];
    যদি (tcc_glob_so(s1, filename, buf, পরিমাণ buf) >= 0)
        filename = buf;
#endif

    যদি (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    যদি (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        প্রত্যাগম 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    যদি (fd < 0) {
        যদি (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        প্রত্যাগম FILE_NOT_FOUND;
    }

    যদি (flags & AFF_TYPE_BIN)
        প্রত্যাগম tcc_add_দ্বিমিক(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    প্রত্যাগম tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI পূর্ণাঙ্ক tcc_add_file(TCCState *s, ধ্রুব বর্ণ *filename)
{
    প্রত্যাগম tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

স্থির পূর্ণাঙ্ক tcc_add_library_internal(TCCState *s1, ধ্রুব বর্ণ *fmt,
    ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flags, বর্ণ **paths, পূর্ণাঙ্ক nb_paths)
{
    বর্ণ buf[1024];
    পূর্ণাঙ্ক i, ret;

    প্রতি(i = 0; i < nb_paths; i++) {
        snprintf(buf, পরিমাণ(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        যদি (ret != FILE_NOT_FOUND)
            প্রত্যাগম ret;
    }
    যদি (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    প্রত্যাগম FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC পূর্ণাঙ্ক tcc_add_dll(TCCState *s, ধ্রুব বর্ণ *filename, পূর্ণাঙ্ক flags)
{
    প্রত্যাগম tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC পূর্ণাঙ্ক tcc_add_support(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    বর্ণ buf[100];
    যদি (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    প্রত্যাগম tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC পূর্ণাঙ্ক tcc_add_crt(TCCState *s1, ধ্রুব বর্ণ *filename)
{
    প্রত্যাগম tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_library(TCCState *s, ধ্রুব বর্ণ *libraryname)
{
    স্থির ধ্রুব বর্ণ * ধ্রুব libs[] = {
#যদি defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#নোচেদ্যদি defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#নোচেদ্যদি defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#অন্যথা
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        রিক্ত
    };
    পূর্ণাঙ্ক flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    যদি (*libraryname == ':') {
        libraryname++;
    } অন্যথা {
        ধ্রুব বর্ণ * ধ্রুব *pp = libs;
        যদি (s->static_link)
            pp += পরিমাণ(libs) / পরিমাণ(*libs) - 2; /* only "%s/lib%s.a" */
        যাবত্ (*pp) {
            পূর্ণাঙ্ক ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            যদি (ret != FILE_NOT_FOUND)
                প্রত্যাগম ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    প্রত্যাগম tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC শূন্য tcc_add_pragma_libs(TCCState *s1)
{
    পূর্ণাঙ্ক i;
    প্রতি (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

স্থির পূর্ণাঙ্ক strstart(ধ্রুব বর্ণ *val, ধ্রুব বর্ণ **str)
{
    ধ্রুব বর্ণ *p, *q;
    p = *str;
    q = val;
    যাবত্ (*q) {
        যদি (*p != *q)
            প্রত্যাগম 0;
        p++;
        q++;
    }
    *str = p;
    প্রত্যাগম 1;
}

সংরচনা lopt {
    TCCState *s;
    ধ্রুব বর্ণ *opt, *arg;
    পূর্ণাঙ্ক match;
};

/* match linker option */
স্থির পূর্ণাঙ্ক link_option(সংরচনা lopt *o, ধ্রুব বর্ণ *q)
{
    ধ্রুব বর্ণ *p;
    পূর্ণাঙ্ক c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    যদি (*p++ != '-')
        প্রত্যাগম 0;
    যদি (*p == '-')
        p++;
    r = 1;
    যদি (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        যদি (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        অন্যথা যদি (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    যাবত্ ((c = *q) == *p) {
        যদি (c == '\0')
            গচ্ছ succ; /* -Wl,-opt */
        ++p;
        যদি (c == '=')
            গচ্ছ succ; /* -Wl,-opt=arg */
        ++q;
    }
    যদি (*p == '\0') {
        যদি (c == '|')
            গচ্ছ succ;
        যদি (c == '=' || c == ':') {
            যদি (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                গচ্ছ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            প্রত্যাগম 0;
        }
    } অন্যথা যদি (c == ':')
        গচ্ছ succ; /* -Wl,-Iarg */
    যাবত্ (*q)
        যদি (*q++ == '|')
            গচ্ছ redo;
    প্রত্যাগম 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    প্রত্যাগম r;
}

স্থির শূন্য args_parser_add_file(TCCState *s, ধ্রুব বর্ণ* filename, পূর্ণাঙ্ক filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
স্থির পূর্ণাঙ্ক tcc_set_linker(TCCState *s, ধ্রুব বর্ণ *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    যাবত্ (s->link_optind < s->link_argc) {
        বর্ণ *end = রিক্ত;
        পূর্ণাঙ্ক ignoring = 0;
        সংরচনা lopt o = {0};
        পূর্ণাঙ্ক r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        যদি (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } অন্যথা যদি (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } অন্যথা যদি (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } অন্যথা যদি (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } অন্যথা যদি (link_option(&o, "init=")) {
            tcc_set_str(&s->init_প্রতীক, o.arg);
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_প্রতীক, o.arg);
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "oformat=")) {
#যদি defined TCC_TARGET_PE
            যদি (0 == strncmp("pe-", o.arg, 3))
#নোচেদ্যদি PTR_SIZE == 8
            যদি (0 == strncmp("elf64-", o.arg, 6))
#অন্যথা
            যদি (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            অন্যথা যদি (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_দ্বিমিক;
#যদি defined TCC_TARGET_COFF
            অন্যথা যদি (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            অন্যথা
                গচ্ছ err;
        } অন্যথা যদি (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } অন্যথা যদি (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } অন্যথা যদি (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } অন্যথা যদি (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } অন্যথা যদি (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } অন্যথা যদি (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } অন্যথা যদি (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } অন্যথা যদি (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } অন্যথা যদি (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } অন্যথা যদি (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } অন্যথা যদি (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } অন্যথা যদি (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } অন্যথা যদি (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } অন্যথা যদি (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } অন্যথা যদি (link_option(&o, "stack=")) {
            s->pe_স্তূপ_size = strtoul(o.arg, &end, 10);
        } অন্যথা যদি (link_option(&o, "subsystem=")) {
            যদি (pe_setsubsy(s, o.arg) < 0)
                গচ্ছ err;
#নোচেদ্যদি defined TCC_TARGET_MACHO
        } অন্যথা যদি (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } অন্যথা যদি (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } অন্যথা যদি (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } অন্যথা যদি (link_option(&o, "as-needed")) {
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "O")) {
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "z=")) {
            ignoring = 1;
        } অন্যথা যদি (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } অন্যথা যদি (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } অন্যথা যদি (o.match) {
            প্রত্যাগম 0; /* expecting argument with next '-Wl,' */
        } অন্যথা {
    err:
            প্রত্যাগম tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        যদি (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    প্রত্যাগম 0;
}

প্রকারনির্দেশ সংরচনা TCCOption {
    ধ্রুব বর্ণ *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

গণনা {
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
    TCC_OPTION_print_অনুসন্ধান_dirs,
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

স্থির ধ্রুব TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_অনুসন্ধান_dirs, 0 },
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
    { রিক্ত, 0, 0 },
};

প্রকারনির্দেশ সংরচনা FlagDef {
    uint16_t offset;
    uint16_t flags;
    ধ্রুব বর্ণ *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

স্থির ধ্রুব FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, রিক্ত }
};

স্থির ধ্রুব FlagDef options_f[] = {
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
    { 0, 0, রিক্ত }
};

স্থির ধ্রুব FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, রিক্ত }
};

স্থির পূর্ণাঙ্ক set_flag(TCCState *s, ধ্রুব FlagDef *flags, ধ্রুব বর্ণ *name)
{
    পূর্ণাঙ্ক মান, mask, ret;
    ধ্রুব FlagDef *p;
    ধ্রুব বর্ণ *r;
    unsigned বর্ণ *f;

    r = name, মান = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    যদি ((flags->flags & WD_ALL) && strstart("error=", &r))
        মান = মান ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    প্রতি (ret = -1, p = flags; p->name; ++p) {
        যদি (ret) {
            যদি (strcmp(r, p->name))
                অনুবর্ত;
        } অন্যথা {
            যদি (0 == (p->flags & WD_ALL))
                অনুবর্ত;
        }

        f = (unsigned বর্ণ *)s + p->offset;
        *f = (*f & mask) | (মান ^ !!(p->flags & FD_INVERT));

        যদি (ret) {
            ret = 0;
            যদি (strcmp(r, "all"))
                ভঙ্গ;
        }
    }
    প্রত্যাগম ret;
}

স্থির ধ্রুব বর্ণ dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#নোচেদ্যদি defined TCC_TARGET_X86_64
    "x86_64-pc"
#নোচেদ্যদি defined TCC_TARGET_C67
    "c67"
#নোচেদ্যদি defined TCC_TARGET_ARM
    "arm"
#নোচেদ্যদি defined TCC_TARGET_ARM64
    "aarch64"
#নোচেদ্যদি defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#নোচেদ্যদি defined(TCC_TARGET_MACHO)
    "apple-darwin"
#নোচেদ্যদি TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#নোচেদ্যদি TARGETOS_OpenBSD
    "openbsd"
#নোচেদ্যদি TARGETOS_NetBSD
    "netbsd"
#নোচেদ্যদি CONFIG_TCC_MUSL
    "linux-musl"
#অন্যথা
    "linux-gnu"
#endif
;

#যদি defined TCC_TARGET_MACHO
স্থির uint32_t parse_version(TCCState *s1, ধ্রুব বর্ণ *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    বর্ণ* last;

    a = strtoul(version, &last, 10);
    যদি (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        যদি (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    যদি (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    প্রত্যাগম (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
স্থির শূন্য ঢোকাও_args(TCCState *s1, বর্ণ ***pargv, পূর্ণাঙ্ক *pargc, পূর্ণাঙ্ক optind, ধ্রুব বর্ণ *p, পূর্ণাঙ্ক sep)
{
    পূর্ণাঙ্ক argc = 0;
    বর্ণ **argv = রিক্ত;
    পূর্ণাঙ্ক i;
    প্রতি (i = 0; i < *pargc; ++i)
        যদি (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        অন্যথা
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

স্থির শূন্য args_parser_add_file(TCCState *s, ধ্রুব বর্ণ* filename, পূর্ণাঙ্ক filetype)
{
    সংরচনা filespec *f = tcc_malloc(পরিমাণ *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    যদি (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC পূর্ণাঙ্ক tcc_parse_args(TCCState *s, পূর্ণাঙ্ক *pargc, বর্ণ ***pargv)
{
    TCCState *s1 = s;
    ধ্রুব TCCOption *popt;
    ধ্রুব বর্ণ *optarg, *r;
    ধ্রুব বর্ণ *run = রিক্ত;
    পূর্ণাঙ্ক optind = 1, empty = 1, x;
    বর্ণ **argv = *pargv;
    পূর্ণাঙ্ক argc = *pargc;

    s->link_optind = s->link_argc;

    যাবত্ (optind < argc) {
        r = argv[optind];
        যদি (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            পূর্ণাঙ্ক fd; বর্ণ *p;
            fd = open(++r, O_RDONLY | O_দ্বিমিক_2);
            যদি (fd < 0)
                প্রত্যাগম tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            ঢোকাও_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            অনুবর্ত;
        }
        optind++;
        যদি (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            যদি (run)
                ভঙ্গ;
            অনুবর্ত;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        যদি (r[1] == '-' && r[2] == '\0')
            গচ্ছ dorun;

        /* find option in table */
        প্রতি(popt = tcc_options; ; ++popt) {
            ধ্রুব বর্ণ *p1 = popt->name;
            ধ্রুব বর্ণ *r1 = r + 1;
            যদি (p1 == রিক্ত)
                প্রত্যাগম tcc_error_noabort("invalid option -- '%s'", r);
            যদি (!strstart(p1, &r1))
                অনুবর্ত;
            optarg = r1;
            যদি (popt->flags & TCC_OPTION_HAS_ARG) {
                যদি (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    যদি (optind >= argc)
                        প্রত্যাগম tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } অন্যথা যদি (*r1 != '\0')
                অনুবর্ত;
            ভঙ্গ;
        }

        বিকল্প(popt->index) {
        পক্ষ TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_D:
            tcc_define_প্রতীক(s, optarg, রিক্ত);
            ভঙ্গ;
        পক্ষ TCC_OPTION_U:
            tcc_undefine_প্রতীক(s, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            অনুবর্ত;
        পক্ষ TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            ভঙ্গ;
        পক্ষ TCC_OPTION_pthread:
            s->option_pthread = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_bench:
            s->do_bench = 1;
            ভঙ্গ;
#ifdef CONFIG_TCC_BACKTRACE
        পক্ষ TCC_OPTION_bt:
            s->rt_অঙ্ক_callers = atoi(optarg); /* zero = default (6) */
            গচ্ছ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            যদি (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            ভঙ্গ;
#ifdef CONFIG_TCC_BCHECK
        পক্ষ TCC_OPTION_b:
            s->do_bounds_check = 1;
            গচ্ছ enable_backtrace;
#endif
#endif
        পক্ষ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            যদি (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } অন্যথা যদি (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } অন্যথা যদি (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                গচ্ছ g_redo;
#ifdef TCC_TARGET_PE
            } অন্যথা যদি (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            ভঙ্গ;
        পক্ষ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            যদি (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ভঙ্গ;
        পক্ষ TCC_OPTION_d:
            যদি (*optarg == 'D')
                s->dflag = 3;
            অন্যথা যদি (*optarg == 'M')
                s->dflag = 7;
            অন্যথা যদি (*optarg == 't')
                s->dflag = 16;
            অন্যথা যদি (isnum(*optarg))
                g_debug |= atoi(optarg);
            অন্যথা
                গচ্ছ unsupported_option;
            ভঙ্গ;
        পক্ষ TCC_OPTION_static:
            s->static_link = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_std:
            যদি (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ভঙ্গ;
        পক্ষ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            গচ্ছ set_output_type;
        পক্ষ TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_o:
            যদি (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            গচ্ছ set_output_type;
        পক্ষ TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            গচ্ছ set_output_type;
#অন্যথা
            প্রত্যাগম tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        পক্ষ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            ভঙ্গ;
#endif
        পক্ষ TCC_OPTION_v:
            কুরু ++s->verbose; যাবত্ (*optarg++ == 'v');
            অনুবর্ত;
        পক্ষ TCC_OPTION_f:
            যদি (set_flag(s, options_f, optarg) < 0)
                গচ্ছ unsupported_option;
            ভঙ্গ;
#ifdef TCC_TARGET_ARM
        পক্ষ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            যদি (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } অন্যথা যদি (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            অন্যথা
                প্রত্যাগম tcc_error_noabort("unsupported float abi '%s'", optarg);
            অনুবর্ত;
#endif
        পক্ষ TCC_OPTION_m:
            যদি (set_flag(s, options_m, optarg) < 0) {
                যদি (x = atoi(optarg), x != 32 && x != 64)
                    গচ্ছ unsupported_option;
                যদি (PTR_SIZE != x/8)
                    প্রত্যাগম x;
                অনুবর্ত;
            }
            ভঙ্গ;
        পক্ষ TCC_OPTION_W:
            যদি (optarg[0] && set_flag(s, options_W, optarg) < 0)
                গচ্ছ unsupported_option;
            ভঙ্গ;
        পক্ষ TCC_OPTION_w:
            s->warn_none = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_Wl:
            যদি (tcc_set_linker(s, optarg) < 0)
                প্রত্যাগম -1;
            ভঙ্গ;
        পক্ষ TCC_OPTION_Wp:
            যদি (argv[0]) /* not with tcc_set_options() */
                ঢোকাও_args(s, &argv, &argc, --optind, optarg, ',');
            ভঙ্গ;
        পক্ষ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            গচ্ছ set_output_type;
        পক্ষ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ভঙ্গ;

        পক্ষ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        পক্ষ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            যদি (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            ভঙ্গ;
        পক্ষ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        পক্ষ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            যদি (*optarg != ',')
                ভঙ্গ;
            ++optarg;
            // fall through
        পক্ষ TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ভঙ্গ;

        পক্ষ TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        পক্ষ TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        পক্ষ TCC_OPTION_x:
            x = 0;
            যদি (*optarg == 'c')
                x = AFF_TYPE_C;
            অন্যথা যদি (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            অন্যথা যদি (*optarg == 'b')
                x = AFF_TYPE_BIN;
            অন্যথা যদি (*optarg == 'n')
                x = AFF_TYPE_NONE;
            অন্যথা
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            ভঙ্গ;
        পক্ষ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ভঙ্গ;
#যদি defined TCC_TARGET_MACHO
        পক্ষ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            গচ্ছ set_output_type;
        পক্ষ TCC_OPTION_flat_namespace:
	     ভঙ্গ;
        পক্ষ TCC_OPTION_two_levelnamespace:
	     ভঙ্গ;
        পক্ষ TCC_OPTION_undefined:
	     ভঙ্গ;
        পক্ষ TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            ভঙ্গ;
        পক্ষ TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            ভঙ্গ;
#endif
        পক্ষ TCC_OPTION_HELP:
            x = OPT_HELP;
            গচ্ছ extra_action;
        পক্ষ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            গচ্ছ extra_action;
        পক্ষ TCC_OPTION_print_অনুসন্ধান_dirs:
            x = OPT_PRINT_DIRS;
            গচ্ছ extra_action;
        পক্ষ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            গচ্ছ extra_action;
        পক্ষ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            যদি (রিক্ত == argv[0]) /* from tcc_set_options() */
                প্রত্যাগম -1;
            যদি (!empty && x)
                প্রত্যাগম tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            প্রত্যাগম x;
        স্বভাব:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ভঙ্গ;
        }
        empty = 0;
    }
    যদি (s->link_optind < s->link_argc)
        প্রত্যাগম tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    যদি (run) {
        যদি (*run && tcc_set_options(s, run) < 0)
            প্রত্যাগম -1;
        x = 0, r = 0;
        গচ্ছ extra_action;
    }
    যদি (!empty)
        প্রত্যাগম 0;
    যদি (s->verbose == 2)
        প্রত্যাগম OPT_PRINT_DIRS;
    যদি (s->verbose)
        প্রত্যাগম OPT_V;
    প্রত্যাগম OPT_HELP;
}

LIBTCCAPI পূর্ণাঙ্ক tcc_set_options(TCCState *s, ধ্রুব বর্ণ *r)
{
    বর্ণ **argv = রিক্ত;
    পূর্ণাঙ্ক argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    প্রত্যাগম ret;
}

PUB_FUNC শূন্য tcc_print_stats(TCCState *s1, unsigned total_time)
{
    যদি (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_সারিগুলি, total_bytes,
           (দ্বিগুণ)total_time/1000,
           (unsigned)total_সারিগুলি*1000/total_time,
           (দ্বিগুণ)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    যদি (s1->run_size) {
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
