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

#जर ONE_SOURCE
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
#किंवाजर defined(TCC_TARGET_ARM)
#अन्तर्भाव "arm-gen.c"
#अन्तर्भाव "arm-link.c"
#अन्तर्भाव "arm-asm.c"
#किंवाजर defined(TCC_TARGET_ARM64)
#अन्तर्भाव "arm64-gen.c"
#अन्तर्भाव "arm64-link.c"
#अन्तर्भाव "arm64-asm.c"
#किंवाजर defined(TCC_TARGET_C67)
#अन्तर्भाव "c67-gen.c"
#अन्तर्भाव "c67-link.c"
#अन्तर्भाव "tcccoff.c"
#किंवाजर defined(TCC_TARGET_X86_64)
#अन्तर्भाव "x86_64-gen.c"
#अन्तर्भाव "x86_64-link.c"
#अन्तर्भाव "i386-asm.c"
#किंवाजर defined(TCC_TARGET_RISCV64)
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
ST_DATA पूर्णांक nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA पूर्णांक g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC अक्षर *normalize_slashes(अक्षर *path)
{
    अक्षर *p;
    साठी (p = path; *p; ++p)
        जर (*p == '\\')
            *p = '/';
    परत path;
}

#जर defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
स्थिर HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    जर (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    परत TRUE;
}
#अन्यथा
#define tcc_module रिक्त /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
स्थिर ओळीत अक्षर *config_tccdir_w32(अक्षर *path)
{
    अक्षर *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    जर (p > path)
        --p;
    *p = 0;
    परत path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
स्थिर शून्य tcc_add_systemdir(TCCState *s)
{
    अक्षर buf[1000];
    GetSystemDirectoryA(buf, आकार buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC खाता *tcc_fopen(स्थिरांक अक्षर *f, स्थिरांक अक्षर *m) {
    परत ख_खोलो(f, m);
}
PUB_FUNC पूर्णांक tcc_fclose(खाता *f) {
    परत ख_बंद(f);
}
#endif
/********************************************************/

PUB_FUNC शून्य tcc_enter_state(TCCState *s1)
{
    जर (s1->error_set_jmp_enabled)
        परत;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC शून्य tcc_exit_state(TCCState *s1)
{
    जर (s1->error_set_jmp_enabled)
        परत;
    tcc_state = रिक्त;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC अक्षर *pstrcpy(अक्षर *buf, माप_प्रकार buf_size, स्थिरांक अक्षर *s)
{
    अक्षर *q, *q_end;
    पूर्णांक c;

    जर (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        पर्यंत (q < q_end) {
            c = *s++;
            जर (c == '\0')
                थांबा;
            *q++ = c;
        }
        *q = '\0';
    }
    परत buf;
}

/* strcat and truncate. */
ST_FUNC अक्षर *pstrcat(अक्षर *buf, माप_प्रकार buf_size, स्थिरांक अक्षर *s)
{
    माप_प्रकार len;
    len = म_माप(buf);
    जर (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    परत buf;
}

ST_FUNC अक्षर *pstrncpy(अक्षर *out, माप_प्रकार buf_size, स्थिरांक अक्षर *s, माप_प्रकार अंक)
{
    जर (अंक >= buf_size)
        अंक = buf_size - 1;
    स_नकल(out, s, अंक);
    out[अंक] = '\0';
    परत out;
}

/* extract the basename of a file */
PUB_FUNC अक्षर *tcc_basename(स्थिरांक अक्षर *name)
{
    अक्षर *p = (अक्षर *)म_अक्षर(name, 0);
    पर्यंत (p > name && !IS_DIRSEP(p[-1]))
        --p;
    परत p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC अक्षर *tcc_fileextension (स्थिरांक अक्षर *name)
{
    अक्षर *b = tcc_basename(name);
    अक्षर *e = म_खोजप(b, '.');
    परत e ? e : म_अक्षर(b, 0);
}

ST_FUNC अक्षर *tcc_load_text(पूर्णांक fd)
{
    पूर्णांक len = lseek(fd, 0, अंत_से);
    अक्षर *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    परत buf;
}

/* replace *pp by copy of 'str' or NULL */
स्थिर शून्य tcc_set_str(अक्षर **pp, स्थिरांक अक्षर *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : रिक्त;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
स्थिर शून्य tcc_concat_str(अक्षर **pp, स्थिरांक अक्षर *str, पूर्णांक sep)
{
    पूर्णांक l = *pp ? म_माप(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + म_माप(str) + 1);
    जर (l && sep) ((*pp)[l - 1] = sep);
    म_नकल(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef मुक्त
#undef पुनः_स्मृति

स्थिर शून्य *default_reallocator(शून्य *ptr, अचिन्हित दीर्घ size)
{
    शून्य *ptr1;
    जर (size == 0) {
        मुक्त(ptr);
        ptr1 = रिक्त;
    }
    अन्यथा {
        ptr1 = पुनः_स्मृति(ptr, size);
        जर (!ptr1) {
            ख_लिखो(मानक_त्रुटि, "tcc: memory full\n");
            निकास (1);
        }
    }
    परत ptr1;
}

ST_FUNC शून्य libc_free(शून्य *ptr)
{
    मुक्त(ptr);
}

/* defined to be not used */
#define मुक्त(p) use_tcc_free(p)
#define पुनः_स्मृति(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
स्थिर शून्य *(*reallocator)(शून्य*, अचिन्हित दीर्घ) = default_reallocator;

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

PUB_FUNC शून्य *tcc_malloc(अचिन्हित दीर्घ size)
{
    परत reallocator(0, size);
}

PUB_FUNC शून्य *tcc_realloc(शून्य *ptr, अचिन्हित दीर्घ size)
{
    परत reallocator(ptr, size);
}

PUB_FUNC शून्य *tcc_mallocz(अचिन्हित दीर्घ size)
{
    शून्य *ptr;
    ptr = tcc_malloc(size);
    जर (size)
        स_रखो(ptr, 0, size);
    परत ptr;
}

PUB_FUNC अक्षर *tcc_strdup(स्थिरांक अक्षर *str)
{
    अक्षर *ptr;
    ptr = tcc_malloc(म_माप(str) + 1);
    म_नकल(ptr, str);
    परत ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((अचिन्हित अक्षर *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((अक्षर *)header + दुरत्व(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((अक्षर*)ptr - दुरत्व(mem_debug_header_t, magic3))

संरचना mem_debug_header {
    अचिन्हित magic1;
    अचिन्हित size;
    संरचना mem_debug_header *prev;
    संरचना mem_debug_header *next;
    पूर्णांक ओळ_अंक;
    अक्षर file_name[MEM_DEBUG_FILE_LEN];
    अचिन्हित magic2;
    ALIGNED(16) अचिन्हित अक्षर magic3[4];
};

प्रकारव्याख्या संरचना mem_debug_header mem_debug_header_t;

TCC_SEM(स्थिर mem_sem);
स्थिर mem_debug_header_t *mem_debug_chain;
स्थिर अचिन्हित mem_cur_size;
स्थिर अचिन्हित mem_max_size;
स्थिर पूर्णांक nb_states;

स्थिर mem_debug_header_t *malloc_check(शून्य *ptr, स्थिरांक अक्षर *संदेश)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    जर (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (अचिन्हित)-1) {
        ख_लिखो(मानक_त्रुटि, "%s check failed\n", संदेश);
        जर (header->magic1 == MEM_DEBUG_MAGIC1)
            ख_लिखो(मानक_त्रुटि, "%s:%u: block allocated here.\n",
                header->file_name, header->ओळ_अंक);
        निकास(1);
    }
    परत header;
}

PUB_FUNC शून्य *tcc_malloc_debug(अचिन्हित दीर्घ size, स्थिरांक अक्षर *file, पूर्णांक ओळ)
{
    पूर्णांक ofs;
    mem_debug_header_t *header;
    जर (!size)
        परत रिक्त;
    header = tcc_malloc(आकार(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->ओळ_अंक = ओळ;
    ofs = म_माप(file) + 1 - MEM_DEBUG_FILE_LEN;
    म_नकल(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = रिक्त;
    जर (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    जर (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    परत MEM_USER_PTR(header);
}

PUB_FUNC शून्य tcc_free_debug(शून्य *ptr)
{
    mem_debug_header_t *header;
    जर (!ptr)
        परत;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (अचिन्हित)-1;
    जर (header->next)
        header->next->prev = header->prev;
    जर (header->prev)
        header->prev->next = header->next;
    जर (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC शून्य *tcc_mallocz_debug(अचिन्हित दीर्घ size, स्थिरांक अक्षर *file, पूर्णांक ओळ)
{
    शून्य *ptr;
    ptr = tcc_malloc_debug(size,file,ओळ);
    जर (size)
        स_रखो(ptr, 0, size);
    परत ptr;
}

PUB_FUNC शून्य *tcc_realloc_debug(शून्य *ptr, अचिन्हित दीर्घ size, स्थिरांक अक्षर *file, पूर्णांक ओळ)
{
    mem_debug_header_t *header;
    पूर्णांक mem_debug_chain_update = 0;

    जर (!ptr)
        परत tcc_malloc_debug(size, file, ओळ);
    जर (!size) {
        tcc_free_debug(ptr);
        परत रिक्त;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, आकार(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    जर (header->next)
        header->next->prev = header;
    जर (header->prev)
        header->prev->next = header;
    जर (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    जर (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    परत MEM_USER_PTR(header);
}

PUB_FUNC अक्षर *tcc_strdup_debug(स्थिरांक अक्षर *str, स्थिरांक अक्षर *file, पूर्णांक ओळ)
{
    अक्षर *ptr;
    ptr = tcc_malloc_debug(म_माप(str) + 1, file, ओळ);
    म_नकल(ptr, str);
    परत ptr;
}

PUB_FUNC शून्य tcc_memcheck(पूर्णांक d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    जर (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        ख_साफ(मानक_निकास);
        ख_लिखो(मानक_त्रुटि, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        पर्यंत (header) {
            ख_लिखो(मानक_त्रुटि, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->ओळ_अंक, header->size);
            header = header->next;
        }
        ख_साफ(मानक_त्रुटि);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = रिक्त;
#जर MEM_DEBUG-0 == 2
        निकास(2);
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
ST_FUNC पूर्णांक normalized_PATHCMP(स्थिरांक अक्षर *f1, स्थिरांक अक्षर *f2)
{
    अक्षर *p1, *p2;
    पूर्णांक ret = 1;
    जर (!!(p1 = realpath(f1, रिक्त))) {
        जर (!!(p2 = realpath(f2, रिक्त))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    परत ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC शून्य dynarray_add(शून्य *ptab, पूर्णांक *nb_ptr, शून्य *data)
{
    पूर्णांक nb, nb_alloc;
    शून्य **pp;

    nb = *nb_ptr;
    pp = *(शून्य ***)ptab;
    /* every power of two we double array size */
    जर ((nb & (nb - 1)) == 0) {
        जर (!nb)
            nb_alloc = 1;
        अन्यथा
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * आकार(शून्य *));
        *(शून्य***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC शून्य dynarray_reset(शून्य *pp, पूर्णांक *n)
{
    शून्य **p;
    साठी (p = *(शून्य***)pp; *n; ++p, --*n)
        जर (*p)
            tcc_free(*p);
    tcc_free(*(शून्य**)pp);
    *(शून्य**)pp = रिक्त;
}

स्थिर शून्य dynarray_split(अक्षर ***argv, पूर्णांक *argc, स्थिरांक अक्षर *p, पूर्णांक sep)
{
    पूर्णांक qot, c;
    CString str;
    साठी(;;) {
        पर्यंत (c = (अचिन्हित अक्षर)*p, c <= ' ' && c != '\0')
            ++p;
        जर (c == '\0')
            थांबा;
        cstr_new(&str);
        qot = 0;
        करा {
            ++p;
            जर (sep) { /* e.g. to split -Wl,-opt,arg */
                जर (c == sep)
                    थांबा;
            } अन्यथा {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                जर (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } अन्यथा जर (c == '"') {
                    qot ^= 1;
                    सुरूठेवा;
                } अन्यथा जर (c <= ' ' && !qot) {
                    थांबा;
                }
            }
            cstr_ccat(&str, c);
        } पर्यंत (c = (अचिन्हित अक्षर)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

स्थिर शून्य tcc_split_path(TCCState *s, शून्य *p_ary, पूर्णांक *p_nb_ary, स्थिरांक अक्षर *in)
{
    स्थिरांक अक्षर *p;
    करा {
        पूर्णांक c;
        CString str;

        cstr_new(&str);
        साठी (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            जर (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                जर (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                जर (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                जर (c == 'f' && file) {
                    /* substitute current file's dir */
                    स्थिरांक अक्षर *f = file->true_filename;
                    स्थिरांक अक्षर *b = tcc_basename(f);
                    जर (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    अन्यथा
                        cstr_cat(&str, ".", 1);
                }
            } अन्यथा {
                cstr_ccat(&str, c);
            }
        }
        जर (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } पर्यंत (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
गणना { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

स्थिर शून्य error1(पूर्णांक mode, स्थिरांक अक्षर *fmt, बहु_सूची ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    पूर्णांक ओळ = 0;

    tcc_exit_state(s1);

    जर (mode == ERROR_WARN) {
        जर (s1->warn_error)
            mode = ERROR_ERROR;
        जर (s1->warn_अंक) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            पूर्णांक wopt = *(&s1->warn_none + s1->warn_अंक);
            s1->warn_अंक = 0;
            जर (0 == (wopt & WARN_ON))
                परत;
            जर (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            जर (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        जर (s1->warn_none)
            परत;
    }

    cstr_new(&cs);
    जर (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        ओळ = बहु_तर्क(ap, पूर्णांक), fmt += 3;
    f = रिक्त;
    जर (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        साठी (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    जर (f) {
        साठी(pf = s1->include_चळत; pf < s1->include_चळत_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->ओळ_अंक - 1);
        जर (0 == ओळ)
            ओळ = f->ओळ_अंक - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, ओळ);
    } अन्यथा जर (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } अन्यथा {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    जर (pp_अभिव्यक्ती > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    अन्यथा
        cstr_vprintf(&cs, fmt, ap);
    जर (!s1->error_func) {
        /* default case: stderr */
        जर (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == मानक_निकास)
            म_लिखो("\n"); /* print a newline during tcc -E */
        ख_साफ(मानक_निकास); /* flush -v output */
        ख_लिखो(मानक_त्रुटि, "%s\n", (अक्षर*)cs.data);
        ख_साफ(मानक_त्रुटि); /* print error/warning now (win32) */
    } अन्यथा {
        s1->error_func(s1->error_opaque, (अक्षर*)cs.data);
    }
    cstr_free(&cs);
    जर (mode != ERROR_WARN)
        s1->nb_errors++;
    जर (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        पर्यंत (nb_stk_data)
            tcc_free(*(शून्य**)stk_data[--nb_stk_data]);
        दीर्घ_लाँघ(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI शून्य tcc_set_error_func(TCCState *s, शून्य *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC पूर्णांक _tcc_error_noabort(स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    बहु_पूर्ण(ap);
    परत -1;
}

#undef _tcc_error
PUB_FUNC शून्य _tcc_error(स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    निकास(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC शून्य _tcc_warning(स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    बहु_पूर्ण(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC शून्य tcc_open_bf(TCCState *s1, स्थिरांक अक्षर *filename, पूर्णांक initlen)
{
    BufferedFile *bf;
    पूर्णांक buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(आकार(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, आकार(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->ओळ_अंक = 1;
    bf->ifdef_चळत_ptr = s1->ifdef_चळत_ptr;
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
    जर (bf->fd > 0) {
        बंद(bf->fd);
        total_ओळी += bf->ओळ_अंक - 1;
    }
    जर (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

स्थिर पूर्णांक _tcc_open(TCCState *s1, स्थिरांक अक्षर *filename)
{
    पूर्णांक fd;
    जर (म_भेद(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    अन्यथा
        fd = खोलो(filename, O_RDONLY | O_द्विमान_2);
    जर ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        म_लिखो("%s %*s%s\n", fd < 0 ? "nf":"->",
               (पूर्णांक)(s1->include_चळत_ptr - s1->include_चळत), "", filename);
    परत fd;
}

ST_FUNC पूर्णांक tcc_open(TCCState *s1, स्थिरांक अक्षर *filename)
{
    पूर्णांक fd = _tcc_open(s1, filename);
    जर (fd < 0)
        परत -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    परत 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
स्थिर पूर्णांक tcc_compile(TCCState *s1, पूर्णांक filetype, स्थिरांक अक्षर *str, पूर्णांक fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    जर (बनाओ_लाँघ(s1->error_jmp_buf) == 0) {

        जर (fd == -1) {
            पूर्णांक len = म_माप(str);
            tcc_open_bf(s1, "<string>", len);
            स_नकल(file->buffer, str, len);
        } अन्यथा {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        जर (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } अन्यथा {
            tccelf_begin_file(s1);
            जर (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
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
    परत s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI पूर्णांक tcc_compile_string(TCCState *s, स्थिरांक अक्षर *str)
{
    परत tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI शून्य tcc_define_चिन्ह(TCCState *s1, स्थिरांक अक्षर *sym, स्थिरांक अक्षर *मूल्य)
{
    स्थिरांक अक्षर *eq;
    जर (रिक्त == (eq = म_अक्षर(sym, '=')))
        eq = म_अक्षर(sym, 0);
    जर (रिक्त == मूल्य)
        मूल्य = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (पूर्णांक)(eq-sym), sym, मूल्य);
}

/* undefine a preprocessor symbol */
LIBTCCAPI शून्य tcc_undefine_चिन्ह(TCCState *s1, स्थिरांक अक्षर *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(शून्य)
{
    TCCState *s;

    s = tcc_mallocz(आकार(TCCState));
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
#जर defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#जर defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = मानक_निकास;
    /* might be used in error() before preprocess_start() */
    s->include_चळत_ptr = s->include_चळत;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    परत s;
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
    tcc_free(s1->init_चिन्ह);
    tcc_free(s1->fini_चिन्ह);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#जर defined TCC_TARGET_MACHO
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

LIBTCCAPI पूर्णांक tcc_set_output_type(TCCState *s, पूर्णांक output_type)
{
#ifdef CONFIG_TCC_PIE
    जर (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    जर (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    जर (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        परत 0;
    }

    /* add sections */
    tccelf_new(s);

    जर (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        परत 0;
    }

    जर (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#किंवाजर defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#अन्यथा
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    जर (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    परत s->nb_errors ? -1 : 0;
}

LIBTCCAPI पूर्णांक tcc_add_include_path(TCCState *s, स्थिरांक अक्षर *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    परत 0;
}

LIBTCCAPI पूर्णांक tcc_add_sysinclude_path(TCCState *s, स्थिरांक अक्षर *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    परत 0;
}

LIBTCCAPI पूर्णांक tcc_add_library_path(TCCState *s, स्थिरांक अक्षर *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    परत 0;
}

LIBTCCAPI शून्य tcc_set_lib_path(TCCState *s, स्थिरांक अक्षर *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, स्थिरांक अक्षर *dllname, पूर्णांक level)
{
    DLLReference *ref = रिक्त;
    पूर्णांक i;
    साठी (i = 0; i < s1->nb_loaded_dlls; i++)
        जर (0 == म_भेद(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            थांबा;
        }
    जर (level == -1)
        परत ref;
    जर (ref) {
        जर (level < ref->level)
            ref->level = level;
        ref->found = 1;
        परत ref;
    }
    ref = tcc_mallocz(आकार(DLLReference) + म_माप(dllname));
    म_नकल(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    परत ref;
}

स्थिर पूर्णांक tcc_add_द्विमान(TCCState *s1, पूर्णांक flags, स्थिरांक अक्षर *filename, पूर्णांक fd)
{
    ElfW(Ehdr) ehdr;
    पूर्णांक obj_type;
    स्थिरांक अक्षर *saved_filename = s1->current_filename;
    पूर्णांक ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, शुरू_से);

    निवड (obj_type) {

    स्थिती AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        थांबा;

    स्थिती AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        थांबा;

#जर defined TCC_TARGET_UNIX
    स्थिती AFF_BINTYPE_DYN:
        जर (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            शून्य* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            जर (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
#endif
        } अन्यथा
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        थांबा;

    पूर्वनिर्धारित:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        थांबा;

#किंवाजर defined TCC_TARGET_MACHO
    स्थिती AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        जर (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            शून्य* dl;
            स्थिरांक अक्षर* soname = filename;
            अक्षर *tmp = 0;
            जर (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                जर (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            जर (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } अन्यथा जर (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } अन्यथा {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        जर (ret)
            ret = FILE_NOT_RECOGNIZED;
        थांबा;

    पूर्वनिर्धारित:
    {
        स्थिरांक अक्षर *ext = tcc_fileextension(filename);
        जर (!म_भेद(ext, ".tbd"))
            जा case_dyn_or_tbd;
        जर (!म_भेद(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            जा case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        थांबा;
    }

#किंवाजर defined TCC_TARGET_PE
    पूर्वनिर्धारित:
        जर (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        थांबा;
#endif

#ifdef TCC_TARGET_COFF
    स्थिती AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        थांबा;
#endif
    }

    बंद(fd);
    s1->current_filename = saved_filename;
    जर (ret == FILE_NOT_RECOGNIZED)
        परत tcc_error_noabort("%s: unrecognized file type", filename);
    परत ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#जर defined TARGETOS_OpenBSD && !defined _WIN32
#अन्तर्भाव <glob.h>
स्थिर पूर्णांक tcc_glob_so(TCCState *s1, स्थिरांक अक्षर *pattern, अक्षर *buf, पूर्णांक size)
{
    स्थिरांक अक्षर *star;
    glob_t g;
    अक्षर *p;
    पूर्णांक i, v, v1, v2, v3;

    star = म_अक्षर(pattern, '*');
    जर (!star || glob(pattern, 0, रिक्त, &g))
        परत -1;
    साठी (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        जर (2 != माला_पूछो(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            सुरूठेवा;
        जर ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    परत v;
}
#endif

स्थिर पूर्णांक guess_filetype(स्थिरांक अक्षर *filename)
{
    पूर्णांक filetype = 0;
    जर (1) {
        /* use a file extension to detect a filetype */
        स्थिरांक अक्षर *ext = tcc_fileextension(filename);
        जर (ext[0]) {
            ext++;
            जर (!म_भेद(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            अन्यथा जर (!म_भेद(ext, "s"))
                filetype = AFF_TYPE_ASM;
            अन्यथा जर (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            अन्यथा
                filetype |= AFF_TYPE_BIN;
        } अन्यथा {
            filetype = AFF_TYPE_C;
        }
    }
    परत filetype;
}

ST_FUNC पूर्णांक tcc_add_file_internal(TCCState *s1, स्थिरांक अक्षर *filename, पूर्णांक flags)
{
    पूर्णांक fd;

#जर defined TARGETOS_OpenBSD && !defined _WIN32
    अक्षर buf[1024];
    जर (tcc_glob_so(s1, filename, buf, आकार buf) >= 0)
        filename = buf;
#endif

    जर (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    जर (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        परत 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    जर (fd < 0) {
        जर (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        परत FILE_NOT_FOUND;
    }

    जर (flags & AFF_TYPE_BIN)
        परत tcc_add_द्विमान(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    परत tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI पूर्णांक tcc_add_file(TCCState *s, स्थिरांक अक्षर *filename)
{
    परत tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

स्थिर पूर्णांक tcc_add_library_internal(TCCState *s1, स्थिरांक अक्षर *fmt,
    स्थिरांक अक्षर *filename, पूर्णांक flags, अक्षर **paths, पूर्णांक nb_paths)
{
    अक्षर buf[1024];
    पूर्णांक i, ret;

    साठी(i = 0; i < nb_paths; i++) {
        snprintf(buf, आकार(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        जर (ret != FILE_NOT_FOUND)
            परत ret;
    }
    जर (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    परत FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC पूर्णांक tcc_add_dll(TCCState *s, स्थिरांक अक्षर *filename, पूर्णांक flags)
{
    परत tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC पूर्णांक tcc_add_support(TCCState *s1, स्थिरांक अक्षर *filename)
{
    अक्षर buf[100];
    जर (CONFIG_TCC_CROSSPREFIX[0])
        filename = म_जोड़ो(म_नकल(buf, CONFIG_TCC_CROSSPREFIX), filename);
    परत tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC पूर्णांक tcc_add_crt(TCCState *s1, स्थिरांक अक्षर *filename)
{
    परत tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णांक tcc_add_library(TCCState *s, स्थिरांक अक्षर *libraryname)
{
    स्थिर स्थिरांक अक्षर * स्थिरांक libs[] = {
#जर defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#किंवाजर defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#किंवाजर defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#अन्यथा
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        रिक्त
    };
    पूर्णांक flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    जर (*libraryname == ':') {
        libraryname++;
    } अन्यथा {
        स्थिरांक अक्षर * स्थिरांक *pp = libs;
        जर (s->static_link)
            pp += आकार(libs) / आकार(*libs) - 2; /* only "%s/lib%s.a" */
        पर्यंत (*pp) {
            पूर्णांक ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            जर (ret != FILE_NOT_FOUND)
                परत ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    परत tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC शून्य tcc_add_pragma_libs(TCCState *s1)
{
    पूर्णांक i;
    साठी (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

स्थिर पूर्णांक strstart(स्थिरांक अक्षर *val, स्थिरांक अक्षर **str)
{
    स्थिरांक अक्षर *p, *q;
    p = *str;
    q = val;
    पर्यंत (*q) {
        जर (*p != *q)
            परत 0;
        p++;
        q++;
    }
    *str = p;
    परत 1;
}

संरचना lopt {
    TCCState *s;
    स्थिरांक अक्षर *opt, *arg;
    पूर्णांक match;
};

/* match linker option */
स्थिर पूर्णांक link_option(संरचना lopt *o, स्थिरांक अक्षर *q)
{
    स्थिरांक अक्षर *p;
    पूर्णांक c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    जर (*p++ != '-')
        परत 0;
    जर (*p == '-')
        p++;
    r = 1;
    जर (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        जर (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        अन्यथा जर (0 == स_भेद(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    पर्यंत ((c = *q) == *p) {
        जर (c == '\0')
            जा succ; /* -Wl,-opt */
        ++p;
        जर (c == '=')
            जा succ; /* -Wl,-opt=arg */
        ++q;
    }
    जर (*p == '\0') {
        जर (c == '|')
            जा succ;
        जर (c == '=' || c == ':') {
            जर (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                जा succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            परत 0;
        }
    } अन्यथा जर (c == ':')
        जा succ; /* -Wl,-Iarg */
    पर्यंत (*q)
        जर (*q++ == '|')
            जा redo;
    परत 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    परत r;
}

स्थिर शून्य args_parser_add_file(TCCState *s, स्थिरांक अक्षर* filename, पूर्णांक filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
स्थिर पूर्णांक tcc_set_linker(TCCState *s, स्थिरांक अक्षर *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    पर्यंत (s->link_optind < s->link_argc) {
        अक्षर *end = रिक्त;
        पूर्णांक ignoring = 0;
        संरचना lopt o = {0};
        पूर्णांक r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        जर (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } अन्यथा जर (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } अन्यथा जर (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } अन्यथा जर (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } अन्यथा जर (link_option(&o, "init=")) {
            tcc_set_str(&s->init_चिन्ह, o.arg);
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_चिन्ह, o.arg);
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "oformat=")) {
#जर defined TCC_TARGET_PE
            जर (0 == म_भेदन("pe-", o.arg, 3))
#किंवाजर PTR_SIZE == 8
            जर (0 == म_भेदन("elf64-", o.arg, 6))
#अन्यथा
            जर (0 == म_भेदन("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            अन्यथा जर (0==म_भेद("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_द्विमान;
#जर defined TCC_TARGET_COFF
            अन्यथा जर (0==म_भेद("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            अन्यथा
                जा err;
        } अन्यथा जर (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } अन्यथा जर (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } अन्यथा जर (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } अन्यथा जर (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } अन्यथा जर (link_option(&o, "section-alignment=")) {
            s->section_align = म_से_अदीर्घ(o.arg, &end, 16);
        } अन्यथा जर (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } अन्यथा जर (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } अन्यथा जर (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } अन्यथा जर (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } अन्यथा जर (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } अन्यथा जर (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } अन्यथा जर (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } अन्यथा जर (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } अन्यथा जर (link_option(&o, "file-alignment=")) {
            s->pe_file_align = म_से_अदीर्घ(o.arg, &end, 16);
        } अन्यथा जर (link_option(&o, "stack=")) {
            s->pe_चळत_size = म_से_अदीर्घ(o.arg, &end, 10);
        } अन्यथा जर (link_option(&o, "subsystem=")) {
            जर (pe_setsubsy(s, o.arg) < 0)
                जा err;
#किंवाजर defined TCC_TARGET_MACHO
        } अन्यथा जर (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } अन्यथा जर (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } अन्यथा जर (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } अन्यथा जर (link_option(&o, "as-needed")) {
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "O")) {
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "z=")) {
            ignoring = 1;
        } अन्यथा जर (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } अन्यथा जर (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } अन्यथा जर (o.match) {
            परत 0; /* expecting argument with next '-Wl,' */
        } अन्यथा {
    err:
            परत tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        जर (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    परत 0;
}

प्रकारव्याख्या संरचना TCCOption {
    स्थिरांक अक्षर *name;
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
    TCC_OPTION_print_शोध_dirs,
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

स्थिर स्थिरांक TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_शोध_dirs, 0 },
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

प्रकारव्याख्या संरचना FlagDef {
    uint16_t offset;
    uint16_t flags;
    स्थिरांक अक्षर *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

स्थिर स्थिरांक FlagDef options_W[] = {
    { दुरत्व(TCCState, warn_all), WD_ALL, "all" },
    { दुरत्व(TCCState, warn_error), 0, "error" },
    { दुरत्व(TCCState, warn_write_strings), 0, "write-strings" },
    { दुरत्व(TCCState, warn_unsupported), 0, "unsupported" },
    { दुरत्व(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { दुरत्व(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, रिक्त }
};

स्थिर स्थिरांक FlagDef options_f[] = {
    { दुरत्व(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { दुरत्व(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { दुरत्व(TCCState, nocommon), FD_INVERT, "common" },
    { दुरत्व(TCCState, leading_underscore), 0, "leading-underscore" },
    { दुरत्व(TCCState, ms_extensions), 0, "ms-extensions" },
    { दुरत्व(TCCState, dollars_in_identifiers), 0, "dollars-in-identifiers" },
    { दुरत्व(TCCState, test_coverage), 0, "test-coverage" },
    { दुरत्व(TCCState, reverse_funcargs), 0, "reverse-funcargs" },
    { दुरत्व(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { दुरत्व(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, रिक्त }
};

स्थिर स्थिरांक FlagDef options_m[] = {
    { दुरत्व(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { दुरत्व(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, रिक्त }
};

स्थिर पूर्णांक set_flag(TCCState *s, स्थिरांक FlagDef *flags, स्थिरांक अक्षर *name)
{
    पूर्णांक मूल्य, mask, ret;
    स्थिरांक FlagDef *p;
    स्थिरांक अक्षर *r;
    अचिन्हित अक्षर *f;

    r = name, मूल्य = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    जर ((flags->flags & WD_ALL) && strstart("error=", &r))
        मूल्य = मूल्य ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    साठी (ret = -1, p = flags; p->name; ++p) {
        जर (ret) {
            जर (म_भेद(r, p->name))
                सुरूठेवा;
        } अन्यथा {
            जर (0 == (p->flags & WD_ALL))
                सुरूठेवा;
        }

        f = (अचिन्हित अक्षर *)s + p->offset;
        *f = (*f & mask) | (मूल्य ^ !!(p->flags & FD_INVERT));

        जर (ret) {
            ret = 0;
            जर (म_भेद(r, "all"))
                थांबा;
        }
    }
    परत ret;
}

स्थिर स्थिरांक अक्षर dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#किंवाजर defined TCC_TARGET_X86_64
    "x86_64-pc"
#किंवाजर defined TCC_TARGET_C67
    "c67"
#किंवाजर defined TCC_TARGET_ARM
    "arm"
#किंवाजर defined TCC_TARGET_ARM64
    "aarch64"
#किंवाजर defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#किंवाजर defined(TCC_TARGET_MACHO)
    "apple-darwin"
#किंवाजर TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#किंवाजर TARGETOS_OpenBSD
    "openbsd"
#किंवाजर TARGETOS_NetBSD
    "netbsd"
#किंवाजर CONFIG_TCC_MUSL
    "linux-musl"
#अन्यथा
    "linux-gnu"
#endif
;

#जर defined TCC_TARGET_MACHO
स्थिर uint32_t parse_version(TCCState *s1, स्थिरांक अक्षर *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    अक्षर* last;

    a = म_से_अदीर्घ(version, &last, 10);
    जर (*last == '.') {
        b = म_से_अदीर्घ(&last[1], &last, 10);
        जर (*last == '.')
             c = म_से_अदीर्घ(&last[1], &last, 10);
    }
    जर (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    परत (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
स्थिर शून्य घाला_args(TCCState *s1, अक्षर ***pargv, पूर्णांक *pargc, पूर्णांक optind, स्थिरांक अक्षर *p, पूर्णांक sep)
{
    पूर्णांक argc = 0;
    अक्षर **argv = रिक्त;
    पूर्णांक i;
    साठी (i = 0; i < *pargc; ++i)
        जर (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        अन्यथा
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

स्थिर शून्य args_parser_add_file(TCCState *s, स्थिरांक अक्षर* filename, पूर्णांक filetype)
{
    संरचना filespec *f = tcc_malloc(आकार *f + म_माप(filename));
    f->type = filetype;
    म_नकल(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    जर (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC पूर्णांक tcc_parse_args(TCCState *s, पूर्णांक *pargc, अक्षर ***pargv)
{
    TCCState *s1 = s;
    स्थिरांक TCCOption *popt;
    स्थिरांक अक्षर *optarg, *r;
    स्थिरांक अक्षर *run = रिक्त;
    पूर्णांक optind = 1, empty = 1, x;
    अक्षर **argv = *pargv;
    पूर्णांक argc = *pargc;

    s->link_optind = s->link_argc;

    पर्यंत (optind < argc) {
        r = argv[optind];
        जर (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            पूर्णांक fd; अक्षर *p;
            fd = खोलो(++r, O_RDONLY | O_द्विमान_2);
            जर (fd < 0)
                परत tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            घाला_args(s1, &argv, &argc, optind, p, 0);
            बंद(fd), tcc_free(p);
            सुरूठेवा;
        }
        optind++;
        जर (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            जर (run)
                थांबा;
            सुरूठेवा;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        जर (r[1] == '-' && r[2] == '\0')
            जा dorun;

        /* find option in table */
        साठी(popt = tcc_options; ; ++popt) {
            स्थिरांक अक्षर *p1 = popt->name;
            स्थिरांक अक्षर *r1 = r + 1;
            जर (p1 == रिक्त)
                परत tcc_error_noabort("invalid option -- '%s'", r);
            जर (!strstart(p1, &r1))
                सुरूठेवा;
            optarg = r1;
            जर (popt->flags & TCC_OPTION_HAS_ARG) {
                जर (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    जर (optind >= argc)
                        परत tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } अन्यथा जर (*r1 != '\0')
                सुरूठेवा;
            थांबा;
        }

        निवड(popt->index) {
        स्थिती TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            थांबा;
        स्थिती TCC_OPTION_D:
            tcc_define_चिन्ह(s, optarg, रिक्त);
            थांबा;
        स्थिती TCC_OPTION_U:
            tcc_undefine_चिन्ह(s, optarg);
            थांबा;
        स्थिती TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            थांबा;
        स्थिती TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            सुरूठेवा;
        स्थिती TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            थांबा;
        स्थिती TCC_OPTION_pthread:
            s->option_pthread = 1;
            थांबा;
        स्थिती TCC_OPTION_bench:
            s->do_bench = 1;
            थांबा;
#ifdef CONFIG_TCC_BACKTRACE
        स्थिती TCC_OPTION_bt:
            s->rt_अंक_callers = म_से_प(optarg); /* zero = default (6) */
            जा enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            जर (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            थांबा;
#ifdef CONFIG_TCC_BCHECK
        स्थिती TCC_OPTION_b:
            s->do_bounds_check = 1;
            जा enable_backtrace;
#endif
#endif
        स्थिती TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            जर (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - म_से_प(optarg)) : DEFAULT_DWARF_VERSION;
            } अन्यथा जर (0 == म_भेद("stabs", optarg)) {
                s->dwarf = 0;
            } अन्यथा जर (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                जा g_redo;
#ifdef TCC_TARGET_PE
            } अन्यथा जर (0 == म_भेद(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            थांबा;
        स्थिती TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            जर (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            थांबा;
        स्थिती TCC_OPTION_d:
            जर (*optarg == 'D')
                s->dflag = 3;
            अन्यथा जर (*optarg == 'M')
                s->dflag = 7;
            अन्यथा जर (*optarg == 't')
                s->dflag = 16;
            अन्यथा जर (isnum(*optarg))
                g_debug |= म_से_प(optarg);
            अन्यथा
                जा unsupported_option;
            थांबा;
        स्थिती TCC_OPTION_static:
            s->static_link = 1;
            थांबा;
        स्थिती TCC_OPTION_std:
            जर (म_भेद(optarg, "=c11") == 0 || म_भेद(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            थांबा;
        स्थिती TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            जा set_output_type;
        स्थिती TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            थांबा;
        स्थिती TCC_OPTION_o:
            जर (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            थांबा;
        स्थिती TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            जा set_output_type;
        स्थिती TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            थांबा;
        स्थिती TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            थांबा;
        स्थिती TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            थांबा;
        स्थिती TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            थांबा;
        स्थिती TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            जा set_output_type;
#अन्यथा
            परत tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        स्थिती TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            थांबा;
#endif
        स्थिती TCC_OPTION_v:
            करा ++s->verbose; पर्यंत (*optarg++ == 'v');
            सुरूठेवा;
        स्थिती TCC_OPTION_f:
            जर (set_flag(s, options_f, optarg) < 0)
                जा unsupported_option;
            थांबा;
#ifdef TCC_TARGET_ARM
        स्थिती TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            जर (!म_भेद(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } अन्यथा जर (!म_भेद(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            अन्यथा
                परत tcc_error_noabort("unsupported float abi '%s'", optarg);
            सुरूठेवा;
#endif
        स्थिती TCC_OPTION_m:
            जर (set_flag(s, options_m, optarg) < 0) {
                जर (x = म_से_प(optarg), x != 32 && x != 64)
                    जा unsupported_option;
                जर (PTR_SIZE != x/8)
                    परत x;
                सुरूठेवा;
            }
            थांबा;
        स्थिती TCC_OPTION_W:
            जर (optarg[0] && set_flag(s, options_W, optarg) < 0)
                जा unsupported_option;
            थांबा;
        स्थिती TCC_OPTION_w:
            s->warn_none = 1;
            थांबा;
        स्थिती TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            थांबा;
        स्थिती TCC_OPTION_Wl:
            जर (tcc_set_linker(s, optarg) < 0)
                परत -1;
            थांबा;
        स्थिती TCC_OPTION_Wp:
            जर (argv[0]) /* not with tcc_set_options() */
                घाला_args(s, &argv, &argc, --optind, optarg, ',');
            थांबा;
        स्थिती TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            जा set_output_type;
        स्थिती TCC_OPTION_P:
            s->Pflag = म_से_प(optarg) + 1;
            थांबा;

        स्थिती TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        स्थिती TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            जर (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            थांबा;
        स्थिती TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        स्थिती TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            जर (*optarg != ',')
                थांबा;
            ++optarg;
            // fall through
        स्थिती TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            थांबा;
        स्थिती TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            थांबा;

        स्थिती TCC_OPTION_dumpmachine:
            म_लिखो("%s\n", dumpmachine_str);
            निकास(0);
        स्थिती TCC_OPTION_dumpversion:
            म_लिखो ("%s\n", TCC_VERSION);
            निकास(0);

        स्थिती TCC_OPTION_x:
            x = 0;
            जर (*optarg == 'c')
                x = AFF_TYPE_C;
            अन्यथा जर (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            अन्यथा जर (*optarg == 'b')
                x = AFF_TYPE_BIN;
            अन्यथा जर (*optarg == 'n')
                x = AFF_TYPE_NONE;
            अन्यथा
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            थांबा;
        स्थिती TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            थांबा;
#जर defined TCC_TARGET_MACHO
        स्थिती TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            जा set_output_type;
        स्थिती TCC_OPTION_flat_namespace:
	     थांबा;
        स्थिती TCC_OPTION_two_levelnamespace:
	     थांबा;
        स्थिती TCC_OPTION_undefined:
	     थांबा;
        स्थिती TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            थांबा;
        स्थिती TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            थांबा;
        स्थिती TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            थांबा;
#endif
        स्थिती TCC_OPTION_HELP:
            x = OPT_HELP;
            जा extra_action;
        स्थिती TCC_OPTION_HELP2:
            x = OPT_HELP2;
            जा extra_action;
        स्थिती TCC_OPTION_print_शोध_dirs:
            x = OPT_PRINT_DIRS;
            जा extra_action;
        स्थिती TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            जा extra_action;
        स्थिती TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            जर (रिक्त == argv[0]) /* from tcc_set_options() */
                परत -1;
            जर (!empty && x)
                परत tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            परत x;
        पूर्वनिर्धारित:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            थांबा;
        }
        empty = 0;
    }
    जर (s->link_optind < s->link_argc)
        परत tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    जर (run) {
        जर (*run && tcc_set_options(s, run) < 0)
            परत -1;
        x = 0, r = 0;
        जा extra_action;
    }
    जर (!empty)
        परत 0;
    जर (s->verbose == 2)
        परत OPT_PRINT_DIRS;
    जर (s->verbose)
        परत OPT_V;
    परत OPT_HELP;
}

LIBTCCAPI पूर्णांक tcc_set_options(TCCState *s, स्थिरांक अक्षर *r)
{
    अक्षर **argv = रिक्त;
    पूर्णांक argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    परत ret;
}

PUB_FUNC शून्य tcc_print_stats(TCCState *s1, अचिन्हित total_time)
{
    जर (!total_time)
        total_time = 1;
    ख_लिखो(मानक_त्रुटि, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_ओळी, total_bytes,
           (द्विगुण)total_time/1000,
           (अचिन्हित)total_ओळी*1000/total_time,
           (द्विगुण)total_bytes/1000/total_time);
    ख_लिखो(मानक_त्रुटि, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    ख_लिखो(मानक_त्रुटि, "# memory usage");
#ifdef TCC_IS_NATIVE
    जर (s1->run_size) {
        Section *s = s1->symtab;
        अचिन्हित ms = s->data_offset + s->link->data_offset + s->hash->data_offset;
        अचिन्हित rs = s1->run_size;
        ख_लिखो(मानक_त्रुटि, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_size - rs - ms);
    }
#endif
    ख_लिखो(मानक_त्रुटि, " %d max (bytes)\n", mem_max_size);
#endif
}
