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

#எனில் ONE_SOURCE
#அந்தர்பாவ "tccpp.c"
#அந்தர்பாவ "tccgen.c"
#அந்தர்பாவ "tccdbg.c"
#அந்தர்பாவ "tccasm.c"
#அந்தர்பாவ "tccelf.c"
#அந்தர்பாவ "tccrun.c"
#ifdef TCC_TARGET_I386
#அந்தர்பாவ "i386-gen.c"
#அந்தர்பாவ "i386-link.c"
#அந்தர்பாவ "i386-asm.c"
#அல்லதெனில் defined(TCC_TARGET_ARM)
#அந்தர்பாவ "arm-gen.c"
#அந்தர்பாவ "arm-link.c"
#அந்தர்பாவ "arm-asm.c"
#அல்லதெனில் defined(TCC_TARGET_ARM64)
#அந்தர்பாவ "arm64-gen.c"
#அந்தர்பாவ "arm64-link.c"
#அந்தர்பாவ "arm64-asm.c"
#அல்லதெனில் defined(TCC_TARGET_C67)
#அந்தர்பாவ "c67-gen.c"
#அந்தர்பாவ "c67-link.c"
#அந்தர்பாவ "tcccoff.c"
#அல்லதெனில் defined(TCC_TARGET_X86_64)
#அந்தர்பாவ "x86_64-gen.c"
#அந்தர்பாவ "x86_64-link.c"
#அந்தர்பாவ "i386-asm.c"
#அல்லதெனில் defined(TCC_TARGET_RISCV64)
#அந்தர்பாவ "riscv64-gen.c"
#அந்தர்பாவ "riscv64-link.c"
#அந்தர்பாவ "riscv64-asm.c"
#இல்லையெனில்
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#அந்தர்பாவ "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#அந்தர்பாவ "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#அந்தர்பாவ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA கட்டமைப்பு TCCState *tcc_state;
TCC_SEM(நிலையான tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA வெறுமை** stk_data;
ST_DATA முழு nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA முழு g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC எழுத்து *normalize_slashes(எழுத்து *path)
{
    எழுத்து *p;
    க்கு (p = path; *p; ++p)
        எனில் (*p == '\\')
            *p = '/';
    திரும்பு path;
}

#எனில் defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
நிலையான HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    எனில் (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    திரும்பு TRUE;
}
#இல்லையெனில்
#define tcc_module வெற்று /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
நிலையான உள்வரி எழுத்து *config_tccdir_w32(எழுத்து *path)
{
    எழுத்து *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    எனில் (p > path)
        --p;
    *p = 0;
    திரும்பு path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
நிலையான வெறுமை tcc_add_systemdir(TCCState *s)
{
    எழுத்து buf[1000];
    GetSystemDirectoryA(buf, அளவு buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(மாறிலி எழுத்து *f, மாறிலி எழுத்து *m) {
    திரும்பு fopen(f, m);
}
PUB_FUNC முழு tcc_fclose(FILE *f) {
    திரும்பு fclose(f);
}
#endif
/********************************************************/

PUB_FUNC வெறுமை tcc_enter_state(TCCState *s1)
{
    எனில் (s1->error_set_jmp_enabled)
        திரும்பு;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC வெறுமை tcc_exit_state(TCCState *s1)
{
    எனில் (s1->error_set_jmp_enabled)
        திரும்பு;
    tcc_state = வெற்று;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC எழுத்து *pstrcpy(எழுத்து *buf, size_t buf_size, மாறிலி எழுத்து *s)
{
    எழுத்து *q, *q_end;
    முழு c;

    எனில் (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        போது (q < q_end) {
            c = *s++;
            எனில் (c == '\0')
                நிறுத்து;
            *q++ = c;
        }
        *q = '\0';
    }
    திரும்பு buf;
}

/* strcat and truncate. */
ST_FUNC எழுத்து *pstrcat(எழுத்து *buf, size_t buf_size, மாறிலி எழுத்து *s)
{
    size_t len;
    len = strlen(buf);
    எனில் (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    திரும்பு buf;
}

ST_FUNC எழுத்து *pstrncpy(எழுத்து *out, size_t buf_size, மாறிலி எழுத்து *s, size_t இலக்கம்)
{
    எனில் (இலக்கம் >= buf_size)
        இலக்கம் = buf_size - 1;
    memcpy(out, s, இலக்கம்);
    out[இலக்கம்] = '\0';
    திரும்பு out;
}

/* extract the basename of a file */
PUB_FUNC எழுத்து *tcc_basename(மாறிலி எழுத்து *name)
{
    எழுத்து *p = (எழுத்து *)strchr(name, 0);
    போது (p > name && !IS_DIRSEP(p[-1]))
        --p;
    திரும்பு p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC எழுத்து *tcc_fileextension (மாறிலி எழுத்து *name)
{
    எழுத்து *b = tcc_basename(name);
    எழுத்து *e = strrchr(b, '.');
    திரும்பு e ? e : strchr(b, 0);
}

ST_FUNC எழுத்து *tcc_load_text(முழு fd)
{
    முழு len = lseek(fd, 0, SEEK_END);
    எழுத்து *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    திரும்பு buf;
}

/* replace *pp by copy of 'str' or NULL */
நிலையான வெறுமை tcc_set_str(எழுத்து **pp, மாறிலி எழுத்து *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : வெற்று;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
நிலையான வெறுமை tcc_concat_str(எழுத்து **pp, மாறிலி எழுத்து *str, முழு sep)
{
    முழு l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    எனில் (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef விடுவி
#undef realloc

நிலையான வெறுமை *default_reallocator(வெறுமை *ptr, unsigned long size)
{
    வெறுமை *ptr1;
    எனில் (size == 0) {
        விடுவி(ptr);
        ptr1 = வெற்று;
    }
    இல்லையெனில் {
        ptr1 = realloc(ptr, size);
        எனில் (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    திரும்பு ptr1;
}

ST_FUNC வெறுமை libc_free(வெறுமை *ptr)
{
    விடுவி(ptr);
}

/* defined to be not used */
#define விடுவி(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
நிலையான வெறுமை *(*reallocator)(வெறுமை*, unsigned long) = default_reallocator;

LIBTCCAPI வெறுமை tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC வெறுமை tcc_free(வெறுமை *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC வெறுமை *tcc_malloc(unsigned long size)
{
    திரும்பு reallocator(0, size);
}

PUB_FUNC வெறுமை *tcc_realloc(வெறுமை *ptr, unsigned long size)
{
    திரும்பு reallocator(ptr, size);
}

PUB_FUNC வெறுமை *tcc_mallocz(unsigned long size)
{
    வெறுமை *ptr;
    ptr = tcc_malloc(size);
    எனில் (size)
        memset(ptr, 0, size);
    திரும்பு ptr;
}

PUB_FUNC எழுத்து *tcc_strdup(மாறிலி எழுத்து *str)
{
    எழுத்து *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    திரும்பு ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned எழுத்து *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((எழுத்து *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((எழுத்து*)ptr - offsetof(mem_debug_header_t, magic3))

கட்டமைப்பு mem_debug_header {
    unsigned magic1;
    unsigned size;
    கட்டமைப்பு mem_debug_header *prev;
    கட்டமைப்பு mem_debug_header *next;
    முழு வரி_இலக்கம்;
    எழுத்து file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned எழுத்து magic3[4];
};

வகைவரை கட்டமைப்பு mem_debug_header mem_debug_header_t;

TCC_SEM(நிலையான mem_sem);
நிலையான mem_debug_header_t *mem_debug_chain;
நிலையான unsigned mem_cur_size;
நிலையான unsigned mem_max_size;
நிலையான முழு nb_states;

நிலையான mem_debug_header_t *malloc_check(வெறுமை *ptr, மாறிலி எழுத்து *செய்தி)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    எனில் (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", செய்தி);
        எனில் (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->வரி_இலக்கம்);
        exit(1);
    }
    திரும்பு header;
}

PUB_FUNC வெறுமை *tcc_malloc_debug(unsigned long size, மாறிலி எழுத்து *file, முழு வரி)
{
    முழு ofs;
    mem_debug_header_t *header;
    எனில் (!size)
        திரும்பு வெற்று;
    header = tcc_malloc(அளவு(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->வரி_இலக்கம் = வரி;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = வெற்று;
    எனில் (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    எனில் (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    திரும்பு MEM_USER_PTR(header);
}

PUB_FUNC வெறுமை tcc_free_debug(வெறுமை *ptr)
{
    mem_debug_header_t *header;
    எனில் (!ptr)
        திரும்பு;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    எனில் (header->next)
        header->next->prev = header->prev;
    எனில் (header->prev)
        header->prev->next = header->next;
    எனில் (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC வெறுமை *tcc_mallocz_debug(unsigned long size, மாறிலி எழுத்து *file, முழு வரி)
{
    வெறுமை *ptr;
    ptr = tcc_malloc_debug(size,file,வரி);
    எனில் (size)
        memset(ptr, 0, size);
    திரும்பு ptr;
}

PUB_FUNC வெறுமை *tcc_realloc_debug(வெறுமை *ptr, unsigned long size, மாறிலி எழுத்து *file, முழு வரி)
{
    mem_debug_header_t *header;
    முழு mem_debug_chain_update = 0;

    எனில் (!ptr)
        திரும்பு tcc_malloc_debug(size, file, வரி);
    எனில் (!size) {
        tcc_free_debug(ptr);
        திரும்பு வெற்று;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, அளவு(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    எனில் (header->next)
        header->next->prev = header;
    எனில் (header->prev)
        header->prev->next = header;
    எனில் (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    எனில் (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    திரும்பு MEM_USER_PTR(header);
}

PUB_FUNC எழுத்து *tcc_strdup_debug(மாறிலி எழுத்து *str, மாறிலி எழுத்து *file, முழு வரி)
{
    எழுத்து *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, வரி);
    strcpy(ptr, str);
    திரும்பு ptr;
}

PUB_FUNC வெறுமை tcc_memcheck(முழு d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    எனில் (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        போது (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->வரி_இலக்கம், header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = வெற்று;
#எனில் MEM_DEBUG-0 == 2
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
ST_FUNC முழு normalized_PATHCMP(மாறிலி எழுத்து *f1, மாறிலி எழுத்து *f2)
{
    எழுத்து *p1, *p2;
    முழு ret = 1;
    எனில் (!!(p1 = realpath(f1, வெற்று))) {
        எனில் (!!(p2 = realpath(f2, வெற்று))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    திரும்பு ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC வெறுமை dynarray_add(வெறுமை *ptab, முழு *nb_ptr, வெறுமை *data)
{
    முழு nb, nb_alloc;
    வெறுமை **pp;

    nb = *nb_ptr;
    pp = *(வெறுமை ***)ptab;
    /* every power of two we double array size */
    எனில் ((nb & (nb - 1)) == 0) {
        எனில் (!nb)
            nb_alloc = 1;
        இல்லையெனில்
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * அளவு(வெறுமை *));
        *(வெறுமை***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC வெறுமை dynarray_reset(வெறுமை *pp, முழு *n)
{
    வெறுமை **p;
    க்கு (p = *(வெறுமை***)pp; *n; ++p, --*n)
        எனில் (*p)
            tcc_free(*p);
    tcc_free(*(வெறுமை**)pp);
    *(வெறுமை**)pp = வெற்று;
}

நிலையான வெறுமை dynarray_split(எழுத்து ***argv, முழு *argc, மாறிலி எழுத்து *p, முழு sep)
{
    முழு qot, c;
    CString str;
    க்கு(;;) {
        போது (c = (unsigned எழுத்து)*p, c <= ' ' && c != '\0')
            ++p;
        எனில் (c == '\0')
            நிறுத்து;
        cstr_new(&str);
        qot = 0;
        செய் {
            ++p;
            எனில் (sep) { /* e.g. to split -Wl,-opt,arg */
                எனில் (c == sep)
                    நிறுத்து;
            } இல்லையெனில் {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                எனில் (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } இல்லையெனில் எனில் (c == '"') {
                    qot ^= 1;
                    தொடர்;
                } இல்லையெனில் எனில் (c <= ' ' && !qot) {
                    நிறுத்து;
                }
            }
            cstr_ccat(&str, c);
        } போது (c = (unsigned எழுத்து)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

நிலையான வெறுமை tcc_split_path(TCCState *s, வெறுமை *p_ary, முழு *p_nb_ary, மாறிலி எழுத்து *in)
{
    மாறிலி எழுத்து *p;
    செய் {
        முழு c;
        CString str;

        cstr_new(&str);
        க்கு (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            எனில் (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                எனில் (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                எனில் (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                எனில் (c == 'f' && file) {
                    /* substitute current file's dir */
                    மாறிலி எழுத்து *f = file->true_filename;
                    மாறிலி எழுத்து *b = tcc_basename(f);
                    எனில் (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    இல்லையெனில்
                        cstr_cat(&str, ".", 1);
                }
            } இல்லையெனில் {
                cstr_ccat(&str, c);
            }
        }
        எனில் (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } போது (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
எண்ணிக்கை { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

நிலையான வெறுமை error1(முழு mode, மாறிலி எழுத்து *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    முழு வரி = 0;

    tcc_exit_state(s1);

    எனில் (mode == ERROR_WARN) {
        எனில் (s1->warn_error)
            mode = ERROR_ERROR;
        எனில் (s1->warn_இலக்கம்) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            முழு wopt = *(&s1->warn_none + s1->warn_இலக்கம்);
            s1->warn_இலக்கம் = 0;
            எனில் (0 == (wopt & WARN_ON))
                திரும்பு;
            எனில் (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            எனில் (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        எனில் (s1->warn_none)
            திரும்பு;
    }

    cstr_new(&cs);
    எனில் (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        வரி = va_arg(ap, முழு), fmt += 3;
    f = வெற்று;
    எனில் (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        க்கு (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    எனில் (f) {
        க்கு(pf = s1->include_அடுக்கு; pf < s1->include_அடுக்கு_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->வரி_இலக்கம் - 1);
        எனில் (0 == வரி)
            வரி = f->வரி_இலக்கம் - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, வரி);
    } இல்லையெனில் எனில் (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } இல்லையெனில் {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    எனில் (pp_கோவை > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    இல்லையெனில்
        cstr_vprintf(&cs, fmt, ap);
    எனில் (!s1->error_func) {
        /* default case: stderr */
        எனில் (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (எழுத்து*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } இல்லையெனில் {
        s1->error_func(s1->error_opaque, (எழுத்து*)cs.data);
    }
    cstr_free(&cs);
    எனில் (mode != ERROR_WARN)
        s1->nb_errors++;
    எனில் (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        போது (nb_stk_data)
            tcc_free(*(வெறுமை**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI வெறுமை tcc_set_error_func(TCCState *s, வெறுமை *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC முழு _tcc_error_noabort(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    திரும்பு -1;
}

#undef _tcc_error
PUB_FUNC வெறுமை _tcc_error(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC வெறுமை _tcc_warning(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC வெறுமை tcc_open_bf(TCCState *s1, மாறிலி எழுத்து *filename, முழு initlen)
{
    BufferedFile *bf;
    முழு buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(அளவு(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, அளவு(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->வரி_இலக்கம் = 1;
    bf->ifdef_அடுக்கு_ptr = s1->ifdef_அடுக்கு_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC வெறுமை tcc_close(வெறுமை)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    எனில் (bf->fd > 0) {
        close(bf->fd);
        total_வரிகள் += bf->வரி_இலக்கம் - 1;
    }
    எனில் (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

நிலையான முழு _tcc_open(TCCState *s1, மாறிலி எழுத்து *filename)
{
    முழு fd;
    எனில் (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    இல்லையெனில்
        fd = open(filename, O_RDONLY | O_இருமம்_2);
    எனில் ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (முழு)(s1->include_அடுக்கு_ptr - s1->include_அடுக்கு), "", filename);
    திரும்பு fd;
}

ST_FUNC முழு tcc_open(TCCState *s1, மாறிலி எழுத்து *filename)
{
    முழு fd = _tcc_open(s1, filename);
    எனில் (fd < 0)
        திரும்பு -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    திரும்பு 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
நிலையான முழு tcc_compile(TCCState *s1, முழு filetype, மாறிலி எழுத்து *str, முழு fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    எனில் (setjmp(s1->error_jmp_buf) == 0) {

        எனில் (fd == -1) {
            முழு len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } இல்லையெனில் {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        எனில் (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } இல்லையெனில் {
            tccelf_begin_file(s1);
            எனில் (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } இல்லையெனில் {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    திரும்பு s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI முழு tcc_compile_string(TCCState *s, மாறிலி எழுத்து *str)
{
    திரும்பு tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI வெறுமை tcc_define_குறியீடு(TCCState *s1, மாறிலி எழுத்து *sym, மாறிலி எழுத்து *மதிப்பு)
{
    மாறிலி எழுத்து *eq;
    எனில் (வெற்று == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    எனில் (வெற்று == மதிப்பு)
        மதிப்பு = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (முழு)(eq-sym), sym, மதிப்பு);
}

/* undefine a preprocessor symbol */
LIBTCCAPI வெறுமை tcc_undefine_குறியீடு(TCCState *s1, மாறிலி எழுத்து *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(வெறுமை)
{
    TCCState *s;

    s = tcc_mallocz(அளவு(TCCState));
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
#எனில் defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#எனில் defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_அடுக்கு_ptr = s->include_அடுக்கு;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    திரும்பு s;
}

LIBTCCAPI வெறுமை tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_குறியீடு);
    tcc_free(s1->fini_குறியீடு);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#எனில் defined TCC_TARGET_MACHO
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

LIBTCCAPI முழு tcc_set_output_type(TCCState *s, முழு output_type)
{
#ifdef CONFIG_TCC_PIE
    எனில் (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    எனில் (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    எனில் (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        திரும்பு 0;
    }

    /* add sections */
    tccelf_new(s);

    எனில் (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        திரும்பு 0;
    }

    எனில் (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#அல்லதெனில் defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#இல்லையெனில்
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    எனில் (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    திரும்பு s->nb_errors ? -1 : 0;
}

LIBTCCAPI முழு tcc_add_include_path(TCCState *s, மாறிலி எழுத்து *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    திரும்பு 0;
}

LIBTCCAPI முழு tcc_add_sysinclude_path(TCCState *s, மாறிலி எழுத்து *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    திரும்பு 0;
}

LIBTCCAPI முழு tcc_add_library_path(TCCState *s, மாறிலி எழுத்து *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    திரும்பு 0;
}

LIBTCCAPI வெறுமை tcc_set_lib_path(TCCState *s, மாறிலி எழுத்து *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, மாறிலி எழுத்து *dllname, முழு level)
{
    DLLReference *ref = வெற்று;
    முழு i;
    க்கு (i = 0; i < s1->nb_loaded_dlls; i++)
        எனில் (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            நிறுத்து;
        }
    எனில் (level == -1)
        திரும்பு ref;
    எனில் (ref) {
        எனில் (level < ref->level)
            ref->level = level;
        ref->found = 1;
        திரும்பு ref;
    }
    ref = tcc_mallocz(அளவு(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    திரும்பு ref;
}

நிலையான முழு tcc_add_இருமம்(TCCState *s1, முழு flags, மாறிலி எழுத்து *filename, முழு fd)
{
    ElfW(Ehdr) ehdr;
    முழு obj_type;
    மாறிலி எழுத்து *saved_filename = s1->current_filename;
    முழு ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    தேர்வு (obj_type) {

    நிலை AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        நிறுத்து;

    நிலை AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        நிறுத்து;

#எனில் defined TCC_TARGET_UNIX
    நிலை AFF_BINTYPE_DYN:
        எனில் (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            வெறுமை* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            எனில் (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            இல்லையெனில்
                ret = FILE_NOT_RECOGNIZED;
#endif
        } இல்லையெனில்
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        நிறுத்து;

    இயல்பு:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        நிறுத்து;

#அல்லதெனில் defined TCC_TARGET_MACHO
    நிலை AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        எனில் (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            வெறுமை* dl;
            மாறிலி எழுத்து* soname = filename;
            எழுத்து *tmp = 0;
            எனில் (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                எனில் (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            எனில் (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            இல்லையெனில்
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } இல்லையெனில் எனில் (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } இல்லையெனில் {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        எனில் (ret)
            ret = FILE_NOT_RECOGNIZED;
        நிறுத்து;

    இயல்பு:
    {
        மாறிலி எழுத்து *ext = tcc_fileextension(filename);
        எனில் (!strcmp(ext, ".tbd"))
            செல் case_dyn_or_tbd;
        எனில் (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            செல் case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        நிறுத்து;
    }

#அல்லதெனில் defined TCC_TARGET_PE
    இயல்பு:
        எனில் (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        நிறுத்து;
#endif

#ifdef TCC_TARGET_COFF
    நிலை AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        நிறுத்து;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    எனில் (ret == FILE_NOT_RECOGNIZED)
        திரும்பு tcc_error_noabort("%s: unrecognized file type", filename);
    திரும்பு ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#எனில் defined TARGETOS_OpenBSD && !defined _WIN32
#அந்தர்பாவ <glob.h>
நிலையான முழு tcc_glob_so(TCCState *s1, மாறிலி எழுத்து *pattern, எழுத்து *buf, முழு size)
{
    மாறிலி எழுத்து *star;
    glob_t g;
    எழுத்து *p;
    முழு i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    எனில் (!star || glob(pattern, 0, வெற்று, &g))
        திரும்பு -1;
    க்கு (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        எனில் (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            தொடர்;
        எனில் ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    திரும்பு v;
}
#endif

நிலையான முழு guess_filetype(மாறிலி எழுத்து *filename)
{
    முழு filetype = 0;
    எனில் (1) {
        /* use a file extension to detect a filetype */
        மாறிலி எழுத்து *ext = tcc_fileextension(filename);
        எனில் (ext[0]) {
            ext++;
            எனில் (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            இல்லையெனில் எனில் (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            இல்லையெனில் எனில் (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            இல்லையெனில்
                filetype |= AFF_TYPE_BIN;
        } இல்லையெனில் {
            filetype = AFF_TYPE_C;
        }
    }
    திரும்பு filetype;
}

ST_FUNC முழு tcc_add_file_internal(TCCState *s1, மாறிலி எழுத்து *filename, முழு flags)
{
    முழு fd;

#எனில் defined TARGETOS_OpenBSD && !defined _WIN32
    எழுத்து buf[1024];
    எனில் (tcc_glob_so(s1, filename, buf, அளவு buf) >= 0)
        filename = buf;
#endif

    எனில் (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    எனில் (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        திரும்பு 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    எனில் (fd < 0) {
        எனில் (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        திரும்பு FILE_NOT_FOUND;
    }

    எனில் (flags & AFF_TYPE_BIN)
        திரும்பு tcc_add_இருமம்(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    திரும்பு tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI முழு tcc_add_file(TCCState *s, மாறிலி எழுத்து *filename)
{
    திரும்பு tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

நிலையான முழு tcc_add_library_internal(TCCState *s1, மாறிலி எழுத்து *fmt,
    மாறிலி எழுத்து *filename, முழு flags, எழுத்து **paths, முழு nb_paths)
{
    எழுத்து buf[1024];
    முழு i, ret;

    க்கு(i = 0; i < nb_paths; i++) {
        snprintf(buf, அளவு(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        எனில் (ret != FILE_NOT_FOUND)
            திரும்பு ret;
    }
    எனில் (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    திரும்பு FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC முழு tcc_add_dll(TCCState *s, மாறிலி எழுத்து *filename, முழு flags)
{
    திரும்பு tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC முழு tcc_add_support(TCCState *s1, மாறிலி எழுத்து *filename)
{
    எழுத்து buf[100];
    எனில் (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    திரும்பு tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC முழு tcc_add_crt(TCCState *s1, மாறிலி எழுத்து *filename)
{
    திரும்பு tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI முழு tcc_add_library(TCCState *s, மாறிலி எழுத்து *libraryname)
{
    நிலையான மாறிலி எழுத்து * மாறிலி libs[] = {
#எனில் defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#அல்லதெனில் defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#அல்லதெனில் defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#இல்லையெனில்
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        வெற்று
    };
    முழு flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    எனில் (*libraryname == ':') {
        libraryname++;
    } இல்லையெனில் {
        மாறிலி எழுத்து * மாறிலி *pp = libs;
        எனில் (s->static_link)
            pp += அளவு(libs) / அளவு(*libs) - 2; /* only "%s/lib%s.a" */
        போது (*pp) {
            முழு ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            எனில் (ret != FILE_NOT_FOUND)
                திரும்பு ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    திரும்பு tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC வெறுமை tcc_add_pragma_libs(TCCState *s1)
{
    முழு i;
    க்கு (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

நிலையான முழு strstart(மாறிலி எழுத்து *val, மாறிலி எழுத்து **str)
{
    மாறிலி எழுத்து *p, *q;
    p = *str;
    q = val;
    போது (*q) {
        எனில் (*p != *q)
            திரும்பு 0;
        p++;
        q++;
    }
    *str = p;
    திரும்பு 1;
}

கட்டமைப்பு lopt {
    TCCState *s;
    மாறிலி எழுத்து *opt, *arg;
    முழு match;
};

/* match linker option */
நிலையான முழு link_option(கட்டமைப்பு lopt *o, மாறிலி எழுத்து *q)
{
    மாறிலி எழுத்து *p;
    முழு c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    எனில் (*p++ != '-')
        திரும்பு 0;
    எனில் (*p == '-')
        p++;
    r = 1;
    எனில் (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        எனில் (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        இல்லையெனில் எனில் (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    போது ((c = *q) == *p) {
        எனில் (c == '\0')
            செல் succ; /* -Wl,-opt */
        ++p;
        எனில் (c == '=')
            செல் succ; /* -Wl,-opt=arg */
        ++q;
    }
    எனில் (*p == '\0') {
        எனில் (c == '|')
            செல் succ;
        எனில் (c == '=' || c == ':') {
            எனில் (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                செல் succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            திரும்பு 0;
        }
    } இல்லையெனில் எனில் (c == ':')
        செல் succ; /* -Wl,-Iarg */
    போது (*q)
        எனில் (*q++ == '|')
            செல் redo;
    திரும்பு 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    திரும்பு r;
}

நிலையான வெறுமை args_parser_add_file(TCCState *s, மாறிலி எழுத்து* filename, முழு filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
நிலையான முழு tcc_set_linker(TCCState *s, மாறிலி எழுத்து *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    போது (s->link_optind < s->link_argc) {
        எழுத்து *end = வெற்று;
        முழு ignoring = 0;
        கட்டமைப்பு lopt o = {0};
        முழு r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        எனில் (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } இல்லையெனில் எனில் (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } இல்லையெனில் எனில் (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } இல்லையெனில் எனில் (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } இல்லையெனில் எனில் (link_option(&o, "init=")) {
            tcc_set_str(&s->init_குறியீடு, o.arg);
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_குறியீடு, o.arg);
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "oformat=")) {
#எனில் defined TCC_TARGET_PE
            எனில் (0 == strncmp("pe-", o.arg, 3))
#அல்லதெனில் PTR_SIZE == 8
            எனில் (0 == strncmp("elf64-", o.arg, 6))
#இல்லையெனில்
            எனில் (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            இல்லையெனில் எனில் (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_இருமம்;
#எனில் defined TCC_TARGET_COFF
            இல்லையெனில் எனில் (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            இல்லையெனில்
                செல் err;
        } இல்லையெனில் எனில் (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } இல்லையெனில் எனில் (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } இல்லையெனில் எனில் (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } இல்லையெனில் எனில் (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } இல்லையெனில் எனில் (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } இல்லையெனில் எனில் (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } இல்லையெனில் எனில் (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } இல்லையெனில் எனில் (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } இல்லையெனில் எனில் (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } இல்லையெனில் எனில் (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } இல்லையெனில் எனில் (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } இல்லையெனில் எனில் (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } இல்லையெனில் எனில் (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } இல்லையெனில் எனில் (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } இல்லையெனில் எனில் (link_option(&o, "stack=")) {
            s->pe_அடுக்கு_size = strtoul(o.arg, &end, 10);
        } இல்லையெனில் எனில் (link_option(&o, "subsystem=")) {
            எனில் (pe_setsubsy(s, o.arg) < 0)
                செல் err;
#அல்லதெனில் defined TCC_TARGET_MACHO
        } இல்லையெனில் எனில் (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } இல்லையெனில் எனில் (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } இல்லையெனில் எனில் (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } இல்லையெனில் எனில் (link_option(&o, "as-needed")) {
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "O")) {
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "z=")) {
            ignoring = 1;
        } இல்லையெனில் எனில் (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } இல்லையெனில் எனில் (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } இல்லையெனில் எனில் (o.match) {
            திரும்பு 0; /* expecting argument with next '-Wl,' */
        } இல்லையெனில் {
    err:
            திரும்பு tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        எனில் (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    திரும்பு 0;
}

வகைவரை கட்டமைப்பு TCCOption {
    மாறிலி எழுத்து *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

எண்ணிக்கை {
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
    TCC_OPTION_print_தேடல்_dirs,
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

நிலையான மாறிலி TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_தேடல்_dirs, 0 },
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
    { வெற்று, 0, 0 },
};

வகைவரை கட்டமைப்பு FlagDef {
    uint16_t offset;
    uint16_t flags;
    மாறிலி எழுத்து *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

நிலையான மாறிலி FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, வெற்று }
};

நிலையான மாறிலி FlagDef options_f[] = {
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
    { 0, 0, வெற்று }
};

நிலையான மாறிலி FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, வெற்று }
};

நிலையான முழு set_flag(TCCState *s, மாறிலி FlagDef *flags, மாறிலி எழுத்து *name)
{
    முழு மதிப்பு, mask, ret;
    மாறிலி FlagDef *p;
    மாறிலி எழுத்து *r;
    unsigned எழுத்து *f;

    r = name, மதிப்பு = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    எனில் ((flags->flags & WD_ALL) && strstart("error=", &r))
        மதிப்பு = மதிப்பு ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    க்கு (ret = -1, p = flags; p->name; ++p) {
        எனில் (ret) {
            எனில் (strcmp(r, p->name))
                தொடர்;
        } இல்லையெனில் {
            எனில் (0 == (p->flags & WD_ALL))
                தொடர்;
        }

        f = (unsigned எழுத்து *)s + p->offset;
        *f = (*f & mask) | (மதிப்பு ^ !!(p->flags & FD_INVERT));

        எனில் (ret) {
            ret = 0;
            எனில் (strcmp(r, "all"))
                நிறுத்து;
        }
    }
    திரும்பு ret;
}

நிலையான மாறிலி எழுத்து dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#அல்லதெனில் defined TCC_TARGET_X86_64
    "x86_64-pc"
#அல்லதெனில் defined TCC_TARGET_C67
    "c67"
#அல்லதெனில் defined TCC_TARGET_ARM
    "arm"
#அல்லதெனில் defined TCC_TARGET_ARM64
    "aarch64"
#அல்லதெனில் defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#அல்லதெனில் defined(TCC_TARGET_MACHO)
    "apple-darwin"
#அல்லதெனில் TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#அல்லதெனில் TARGETOS_OpenBSD
    "openbsd"
#அல்லதெனில் TARGETOS_NetBSD
    "netbsd"
#அல்லதெனில் CONFIG_TCC_MUSL
    "linux-musl"
#இல்லையெனில்
    "linux-gnu"
#endif
;

#எனில் defined TCC_TARGET_MACHO
நிலையான uint32_t parse_version(TCCState *s1, மாறிலி எழுத்து *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    எழுத்து* last;

    a = strtoul(version, &last, 10);
    எனில் (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        எனில் (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    எனில் (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    திரும்பு (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
நிலையான வெறுமை செருகு_args(TCCState *s1, எழுத்து ***pargv, முழு *pargc, முழு optind, மாறிலி எழுத்து *p, முழு sep)
{
    முழு argc = 0;
    எழுத்து **argv = வெற்று;
    முழு i;
    க்கு (i = 0; i < *pargc; ++i)
        எனில் (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        இல்லையெனில்
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

நிலையான வெறுமை args_parser_add_file(TCCState *s, மாறிலி எழுத்து* filename, முழு filetype)
{
    கட்டமைப்பு filespec *f = tcc_malloc(அளவு *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    எனில் (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC முழு tcc_parse_args(TCCState *s, முழு *pargc, எழுத்து ***pargv)
{
    TCCState *s1 = s;
    மாறிலி TCCOption *popt;
    மாறிலி எழுத்து *optarg, *r;
    மாறிலி எழுத்து *run = வெற்று;
    முழு optind = 1, empty = 1, x;
    எழுத்து **argv = *pargv;
    முழு argc = *pargc;

    s->link_optind = s->link_argc;

    போது (optind < argc) {
        r = argv[optind];
        எனில் (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            முழு fd; எழுத்து *p;
            fd = open(++r, O_RDONLY | O_இருமம்_2);
            எனில் (fd < 0)
                திரும்பு tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            செருகு_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            தொடர்;
        }
        optind++;
        எனில் (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            எனில் (run)
                நிறுத்து;
            தொடர்;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        எனில் (r[1] == '-' && r[2] == '\0')
            செல் dorun;

        /* find option in table */
        க்கு(popt = tcc_options; ; ++popt) {
            மாறிலி எழுத்து *p1 = popt->name;
            மாறிலி எழுத்து *r1 = r + 1;
            எனில் (p1 == வெற்று)
                திரும்பு tcc_error_noabort("invalid option -- '%s'", r);
            எனில் (!strstart(p1, &r1))
                தொடர்;
            optarg = r1;
            எனில் (popt->flags & TCC_OPTION_HAS_ARG) {
                எனில் (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    எனில் (optind >= argc)
                        திரும்பு tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } இல்லையெனில் எனில் (*r1 != '\0')
                தொடர்;
            நிறுத்து;
        }

        தேர்வு(popt->index) {
        நிலை TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_D:
            tcc_define_குறியீடு(s, optarg, வெற்று);
            நிறுத்து;
        நிலை TCC_OPTION_U:
            tcc_undefine_குறியீடு(s, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            தொடர்;
        நிலை TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            நிறுத்து;
        நிலை TCC_OPTION_pthread:
            s->option_pthread = 1;
            நிறுத்து;
        நிலை TCC_OPTION_bench:
            s->do_bench = 1;
            நிறுத்து;
#ifdef CONFIG_TCC_BACKTRACE
        நிலை TCC_OPTION_bt:
            s->rt_இலக்கம்_callers = atoi(optarg); /* zero = default (6) */
            செல் enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            எனில் (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            நிறுத்து;
#ifdef CONFIG_TCC_BCHECK
        நிலை TCC_OPTION_b:
            s->do_bounds_check = 1;
            செல் enable_backtrace;
#endif
#endif
        நிலை TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            எனில் (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } இல்லையெனில் எனில் (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } இல்லையெனில் எனில் (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                செல் g_redo;
#ifdef TCC_TARGET_PE
            } இல்லையெனில் எனில் (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            நிறுத்து;
        நிலை TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            எனில் (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            நிறுத்து;
        நிலை TCC_OPTION_d:
            எனில் (*optarg == 'D')
                s->dflag = 3;
            இல்லையெனில் எனில் (*optarg == 'M')
                s->dflag = 7;
            இல்லையெனில் எனில் (*optarg == 't')
                s->dflag = 16;
            இல்லையெனில் எனில் (isnum(*optarg))
                g_debug |= atoi(optarg);
            இல்லையெனில்
                செல் unsupported_option;
            நிறுத்து;
        நிலை TCC_OPTION_static:
            s->static_link = 1;
            நிறுத்து;
        நிலை TCC_OPTION_std:
            எனில் (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            நிறுத்து;
        நிலை TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            செல் set_output_type;
        நிலை TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_o:
            எனில் (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            செல் set_output_type;
        நிலை TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            நிறுத்து;
        நிலை TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            நிறுத்து;
        நிலை TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            நிறுத்து;
        நிலை TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            செல் set_output_type;
#இல்லையெனில்
            திரும்பு tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        நிலை TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            நிறுத்து;
#endif
        நிலை TCC_OPTION_v:
            செய் ++s->verbose; போது (*optarg++ == 'v');
            தொடர்;
        நிலை TCC_OPTION_f:
            எனில் (set_flag(s, options_f, optarg) < 0)
                செல் unsupported_option;
            நிறுத்து;
#ifdef TCC_TARGET_ARM
        நிலை TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            எனில் (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } இல்லையெனில் எனில் (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            இல்லையெனில்
                திரும்பு tcc_error_noabort("unsupported float abi '%s'", optarg);
            தொடர்;
#endif
        நிலை TCC_OPTION_m:
            எனில் (set_flag(s, options_m, optarg) < 0) {
                எனில் (x = atoi(optarg), x != 32 && x != 64)
                    செல் unsupported_option;
                எனில் (PTR_SIZE != x/8)
                    திரும்பு x;
                தொடர்;
            }
            நிறுத்து;
        நிலை TCC_OPTION_W:
            எனில் (optarg[0] && set_flag(s, options_W, optarg) < 0)
                செல் unsupported_option;
            நிறுத்து;
        நிலை TCC_OPTION_w:
            s->warn_none = 1;
            நிறுத்து;
        நிலை TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            நிறுத்து;
        நிலை TCC_OPTION_Wl:
            எனில் (tcc_set_linker(s, optarg) < 0)
                திரும்பு -1;
            நிறுத்து;
        நிலை TCC_OPTION_Wp:
            எனில் (argv[0]) /* not with tcc_set_options() */
                செருகு_args(s, &argv, &argc, --optind, optarg, ',');
            நிறுத்து;
        நிலை TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            செல் set_output_type;
        நிலை TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            நிறுத்து;

        நிலை TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        நிலை TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            எனில் (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            நிறுத்து;
        நிலை TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        நிலை TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            எனில் (*optarg != ',')
                நிறுத்து;
            ++optarg;
            // fall through
        நிலை TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            நிறுத்து;

        நிலை TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        நிலை TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        நிலை TCC_OPTION_x:
            x = 0;
            எனில் (*optarg == 'c')
                x = AFF_TYPE_C;
            இல்லையெனில் எனில் (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            இல்லையெனில் எனில் (*optarg == 'b')
                x = AFF_TYPE_BIN;
            இல்லையெனில் எனில் (*optarg == 'n')
                x = AFF_TYPE_NONE;
            இல்லையெனில்
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            நிறுத்து;
        நிலை TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            நிறுத்து;
#எனில் defined TCC_TARGET_MACHO
        நிலை TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            செல் set_output_type;
        நிலை TCC_OPTION_flat_namespace:
	     நிறுத்து;
        நிலை TCC_OPTION_two_levelnamespace:
	     நிறுத்து;
        நிலை TCC_OPTION_undefined:
	     நிறுத்து;
        நிலை TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            நிறுத்து;
        நிலை TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            நிறுத்து;
#endif
        நிலை TCC_OPTION_HELP:
            x = OPT_HELP;
            செல் extra_action;
        நிலை TCC_OPTION_HELP2:
            x = OPT_HELP2;
            செல் extra_action;
        நிலை TCC_OPTION_print_தேடல்_dirs:
            x = OPT_PRINT_DIRS;
            செல் extra_action;
        நிலை TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            செல் extra_action;
        நிலை TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            எனில் (வெற்று == argv[0]) /* from tcc_set_options() */
                திரும்பு -1;
            எனில் (!empty && x)
                திரும்பு tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            திரும்பு x;
        இயல்பு:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            நிறுத்து;
        }
        empty = 0;
    }
    எனில் (s->link_optind < s->link_argc)
        திரும்பு tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    எனில் (run) {
        எனில் (*run && tcc_set_options(s, run) < 0)
            திரும்பு -1;
        x = 0, r = 0;
        செல் extra_action;
    }
    எனில் (!empty)
        திரும்பு 0;
    எனில் (s->verbose == 2)
        திரும்பு OPT_PRINT_DIRS;
    எனில் (s->verbose)
        திரும்பு OPT_V;
    திரும்பு OPT_HELP;
}

LIBTCCAPI முழு tcc_set_options(TCCState *s, மாறிலி எழுத்து *r)
{
    எழுத்து **argv = வெற்று;
    முழு argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    திரும்பு ret;
}

PUB_FUNC வெறுமை tcc_print_stats(TCCState *s1, unsigned total_time)
{
    எனில் (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_வரிகள், total_bytes,
           (இரட்டை)total_time/1000,
           (unsigned)total_வரிகள்*1000/total_time,
           (இரட்டை)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    எனில் (s1->run_size) {
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
