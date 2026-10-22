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

#अगर_अघोषित ONE_SOURCE
# define ONE_SOURCE 1
#पूर्ण_अगर

#अगर ONE_SOURCE
#समावेश "tccpp.c"
#समावेश "tccgen.c"
#समावेश "tccdbg.c"
#समावेश "tccasm.c"
#समावेश "tccelf.c"
#समावेश "tccrun.c"
#अगर_घोषित TCC_TARGET_I386
#समावेश "i386-gen.c"
#समावेश "i386-link.c"
#समावेश "i386-asm.c"
#या_अगर defined(TCC_TARGET_ARM)
#समावेश "arm-gen.c"
#समावेश "arm-link.c"
#समावेश "arm-asm.c"
#या_अगर defined(TCC_TARGET_ARM64)
#समावेश "arm64-gen.c"
#समावेश "arm64-link.c"
#समावेश "arm64-asm.c"
#या_अगर defined(TCC_TARGET_C67)
#समावेश "c67-gen.c"
#समावेश "c67-link.c"
#समावेश "tcccoff.c"
#या_अगर defined(TCC_TARGET_X86_64)
#समावेश "x86_64-gen.c"
#समावेश "x86_64-link.c"
#समावेश "i386-asm.c"
#या_अगर defined(TCC_TARGET_RISCV64)
#समावेश "riscv64-gen.c"
#समावेश "riscv64-link.c"
#समावेश "riscv64-asm.c"
#अन्यथा
#त्रुटि unknown target
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_PE
#समावेश "tccpe.c"
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_MACHO
#समावेश "tccmacho.c"
#पूर्ण_अगर
#पूर्ण_अगर /* ONE_SOURCE */

#समावेश "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_तथ्य काष्ठा TCCState *tcc_state;
TCC_SEM(अटल tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_तथ्य व्योम** stk_तथ्य;
ST_तथ्य पूर्णांक nb_stk_तथ्य;
/* option -d<num> (for general development purposes) */
ST_तथ्य पूर्णांक g_debug;

/********************************************************/
#अगर_घोषित _WIN32
ST_FUNC अक्षर *normalize_slashes(अक्षर *path)
{
    अक्षर *p;
    क्रम (p = path; *p; ++p)
        अगर (*p == '\\')
            *p = '/';
    वापस path;
}

#अगर defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
अटल HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    अगर (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    वापस TRUE;
}
#अन्यथा
#घोषणा tcc_module शून्य /* NULL means executable itself */
#पूर्ण_अगर

#अगर_अघोषित CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
अटल अंतरभूत अक्षर *config_tccdir_w32(अक्षर *path)
{
    अक्षर *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    अगर (p > path)
        --p;
    *p = 0;
    वापस path;
}
#घोषणा CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#पूर्ण_अगर

#अगर_घोषित TCC_IS_NATIVE
अटल व्योम tcc_add_systemdir(TCCState *s)
{
    अक्षर buf[1000];
    GetSystemDirectoryA(buf, माप buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#पूर्ण_अगर
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC खाता *tcc_fopen(स्थिर अक्षर *f, स्थिर अक्षर *m) {
    वापस ख_खोलो(f, m);
}
PUB_FUNC पूर्णांक tcc_fclose(खाता *f) {
    वापस ख_बंद(f);
}
#पूर्ण_अगर
/********************************************************/

PUB_FUNC व्योम tcc_enter_state(TCCState *s1)
{
    अगर (s1->error_set_jmp_enabled)
        वापस;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC व्योम tcc_exit_state(TCCState *s1)
{
    अगर (s1->error_set_jmp_enabled)
        वापस;
    tcc_state = शून्य;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC अक्षर *pstrcpy(अक्षर *buf, माप_प्रकार buf_आकार, स्थिर अक्षर *s)
{
    अक्षर *q, *q_end;
    पूर्णांक c;

    अगर (buf_आकार > 0) {
        q = buf;
        q_end = buf + buf_आकार - 1;
        जबतक (q < q_end) {
            c = *s++;
            अगर (c == '\0')
                अवरोध;
            *q++ = c;
        }
        *q = '\0';
    }
    वापस buf;
}

/* strcat and truncate. */
ST_FUNC अक्षर *pstrcat(अक्षर *buf, माप_प्रकार buf_आकार, स्थिर अक्षर *s)
{
    माप_प्रकार len;
    len = म_माप(buf);
    अगर (len < buf_आकार)
        pstrcpy(buf + len, buf_आकार - len, s);
    वापस buf;
}

ST_FUNC अक्षर *pstrncpy(अक्षर *out, माप_प्रकार buf_आकार, स्थिर अक्षर *s, माप_प्रकार अंक)
{
    अगर (अंक >= buf_आकार)
        अंक = buf_आकार - 1;
    स_नकल(out, s, अंक);
    out[अंक] = '\0';
    वापस out;
}

/* extract the basename of a file */
PUB_FUNC अक्षर *tcc_basename(स्थिर अक्षर *name)
{
    अक्षर *p = (अक्षर *)म_अक्षर(name, 0);
    जबतक (p > name && !IS_DIRSEP(p[-1]))
        --p;
    वापस p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC अक्षर *tcc_fileextension (स्थिर अक्षर *name)
{
    अक्षर *b = tcc_basename(name);
    अक्षर *e = म_खोजप(b, '.');
    वापस e ? e : म_अक्षर(b, 0);
}

ST_FUNC अक्षर *tcc_load_text(पूर्णांक fd)
{
    पूर्णांक len = lseek(fd, 0, अंत_से);
    अक्षर *buf = load_तथ्य(fd, 0, len + 1);
    buf[len] = 0;
    वापस buf;
}

/* replace *pp by copy of 'str' or NULL */
अटल व्योम tcc_set_str(अक्षर **pp, स्थिर अक्षर *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : शून्य;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
अटल व्योम tcc_concat_str(अक्षर **pp, स्थिर अक्षर *str, पूर्णांक sep)
{
    पूर्णांक l = *pp ? म_माप(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + म_माप(str) + 1);
    अगर (l && sep) ((*pp)[l - 1] = sep);
    म_नकल(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#अघोषित मुक्त
#अघोषित पुनः_स्मृति

अटल व्योम *default_reallocator(व्योम *ptr, अचिन्हित दीर्घ आकार)
{
    व्योम *ptr1;
    अगर (आकार == 0) {
        मुक्त(ptr);
        ptr1 = शून्य;
    }
    अन्यथा {
        ptr1 = पुनः_स्मृति(ptr, आकार);
        अगर (!ptr1) {
            ख_लिखो(मानक_त्रुटि, "tcc: memory full\n");
            निकास (1);
        }
    }
    वापस ptr1;
}

ST_FUNC व्योम libc_free(व्योम *ptr)
{
    मुक्त(ptr);
}

/* defined to be not used */
#घोषणा मुक्त(p) use_tcc_free(p)
#घोषणा पुनः_स्मृति(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
अटल व्योम *(*reallocator)(व्योम*, अचिन्हित दीर्घ) = default_reallocator;

LIBTCCAPI व्योम tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#अघोषित tcc_free
#अघोषित tcc_malloc
#अघोषित tcc_realloc
#अघोषित tcc_mallocz
#अघोषित tcc_strdup

PUB_FUNC व्योम tcc_free(व्योम *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC व्योम *tcc_malloc(अचिन्हित दीर्घ आकार)
{
    वापस reallocator(0, आकार);
}

PUB_FUNC व्योम *tcc_realloc(व्योम *ptr, अचिन्हित दीर्घ आकार)
{
    वापस reallocator(ptr, आकार);
}

PUB_FUNC व्योम *tcc_mallocz(अचिन्हित दीर्घ आकार)
{
    व्योम *ptr;
    ptr = tcc_malloc(आकार);
    अगर (आकार)
        स_रखो(ptr, 0, आकार);
    वापस ptr;
}

PUB_FUNC अक्षर *tcc_strdup(स्थिर अक्षर *str)
{
    अक्षर *ptr;
    ptr = tcc_malloc(म_माप(str) + 1);
    म_नकल(ptr, str);
    वापस ptr;
}

#अगर_घोषित MEM_DEBUG

#घोषणा MEM_DEBUG_MAGIC1 0xFEEDDEB1
#घोषणा MEM_DEBUG_MAGIC2 0xFEEDDEB2
#घोषणा MEM_DEBUG_MAGIC3 0xFEEDDEB3
#घोषणा MEM_DEBUG_FILE_LEN 40
#घोषणा MEM_DEBUG_CHECK3(header) \
    (((अचिन्हित अक्षर *) header->magic3) + header->आकार)
#घोषणा MEM_USER_PTR(header) \
    ((अक्षर *)header + दुरत्व(mem_debug_header_t, magic3))
#घोषणा MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((अक्षर*)ptr - दुरत्व(mem_debug_header_t, magic3))

काष्ठा mem_debug_header {
    अचिन्हित magic1;
    अचिन्हित आकार;
    काष्ठा mem_debug_header *पूर्व;
    काष्ठा mem_debug_header *अग्र;
    पूर्णांक पंक्ति_अंक;
    अक्षर file_name[MEM_DEBUG_FILE_LEN];
    अचिन्हित magic2;
    ALIGNED(16) अचिन्हित अक्षर magic3[4];
};

प्रकार काष्ठा mem_debug_header mem_debug_header_t;

TCC_SEM(अटल mem_sem);
अटल mem_debug_header_t *mem_debug_chain;
अटल अचिन्हित mem_cur_आकार;
अटल अचिन्हित mem_max_आकार;
अटल पूर्णांक nb_states;

अटल mem_debug_header_t *malloc_check(व्योम *ptr, स्थिर अक्षर *संदेश)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    अगर (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->आकार == (अचिन्हित)-1) {
        ख_लिखो(मानक_त्रुटि, "%s check failed\n", संदेश);
        अगर (header->magic1 == MEM_DEBUG_MAGIC1)
            ख_लिखो(मानक_त्रुटि, "%s:%u: block allocated here.\n",
                header->file_name, header->पंक्ति_अंक);
        निकास(1);
    }
    वापस header;
}

PUB_FUNC व्योम *tcc_malloc_debug(अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2)
{
    पूर्णांक ofs;
    mem_debug_header_t *header;
    अगर (!आकार)
        वापस शून्य;
    header = tcc_malloc(माप(mem_debug_header_t) + आकार);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->आकार = आकार;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->पंक्ति_अंक = पंक्ति_2;
    ofs = म_माप(file) + 1 - MEM_DEBUG_FILE_LEN;
    म_नकल(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->अग्र = mem_debug_chain;
    header->पूर्व = शून्य;
    अगर (header->अग्र)
        header->अग्र->पूर्व = header;
    mem_debug_chain = header;
    mem_cur_आकार += आकार;
    अगर (mem_cur_आकार > mem_max_आकार)
        mem_max_आकार = mem_cur_आकार;
    POST_SEM(&mem_sem);
    वापस MEM_USER_PTR(header);
}

PUB_FUNC व्योम tcc_free_debug(व्योम *ptr)
{
    mem_debug_header_t *header;
    अगर (!ptr)
        वापस;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_आकार -= header->आकार;
    header->आकार = (अचिन्हित)-1;
    अगर (header->अग्र)
        header->अग्र->पूर्व = header->पूर्व;
    अगर (header->पूर्व)
        header->पूर्व->अग्र = header->अग्र;
    अगर (header == mem_debug_chain)
        mem_debug_chain = header->अग्र;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC व्योम *tcc_mallocz_debug(अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2)
{
    व्योम *ptr;
    ptr = tcc_malloc_debug(आकार,file,पंक्ति_2);
    अगर (आकार)
        स_रखो(ptr, 0, आकार);
    वापस ptr;
}

PUB_FUNC व्योम *tcc_realloc_debug(व्योम *ptr, अचिन्हित दीर्घ आकार, स्थिर अक्षर *file, पूर्णांक पंक्ति_2)
{
    mem_debug_header_t *header;
    पूर्णांक mem_debug_chain_update = 0;

    अगर (!ptr)
        वापस tcc_malloc_debug(आकार, file, पंक्ति_2);
    अगर (!आकार) {
        tcc_free_debug(ptr);
        वापस शून्य;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_आकार -= header->आकार;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, माप(mem_debug_header_t) + आकार);
    header->आकार = आकार;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    अगर (header->अग्र)
        header->अग्र->पूर्व = header;
    अगर (header->पूर्व)
        header->पूर्व->अग्र = header;
    अगर (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_आकार += आकार;
    अगर (mem_cur_आकार > mem_max_आकार)
        mem_max_आकार = mem_cur_आकार;
    POST_SEM(&mem_sem);
    वापस MEM_USER_PTR(header);
}

PUB_FUNC अक्षर *tcc_strdup_debug(स्थिर अक्षर *str, स्थिर अक्षर *file, पूर्णांक पंक्ति_2)
{
    अक्षर *ptr;
    ptr = tcc_malloc_debug(म_माप(str) + 1, file, पंक्ति_2);
    म_नकल(ptr, str);
    वापस ptr;
}

PUB_FUNC व्योम tcc_memcheck(पूर्णांक d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    अगर (0 == nb_states && mem_cur_आकार) {
        mem_debug_header_t *header = mem_debug_chain;
        ख_साफ(मानक_निकास);
        ख_लिखो(मानक_त्रुटि, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_आकार, mem_max_आकार);
        जबतक (header) {
            ख_लिखो(मानक_त्रुटि, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->पंक्ति_अंक, header->आकार);
            header = header->अग्र;
        }
        ख_साफ(मानक_त्रुटि);
        mem_cur_आकार = 0;
        mem_max_आकार = 0;
        mem_debug_chain = शून्य;
#अगर MEM_DEBUG-0 == 2
        निकास(2);
#पूर्ण_अगर
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#घोषणा tcc_free(ptr)           tcc_free_debug(ptr)
#घोषणा tcc_malloc(आकार)        tcc_malloc_debug(आकार, __खाता__, __LINE__)
#घोषणा tcc_mallocz(आकार)       tcc_mallocz_debug(आकार, __खाता__, __LINE__)
#घोषणा tcc_realloc(ptr,आकार)   tcc_realloc_debug(ptr, आकार, __खाता__, __LINE__)
#घोषणा tcc_strdup(str)         tcc_strdup_debug(str, __खाता__, __LINE__)

#पूर्ण_अगर /* MEM_DEBUG */

#अगर_घोषित _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#पूर्ण_अगर

/* for #pragma once */
ST_FUNC पूर्णांक normalized_PATHCMP(स्थिर अक्षर *f1, स्थिर अक्षर *f2)
{
    अक्षर *p1, *p2;
    पूर्णांक ret = 1;
    अगर (!!(p1 = realpath(f1, शून्य))) {
        अगर (!!(p2 = realpath(f2, शून्य))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    वापस ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC व्योम dynarray_add(व्योम *ptab, पूर्णांक *nb_ptr, व्योम *तथ्य)
{
    पूर्णांक nb, nb_alloc;
    व्योम **pp;

    nb = *nb_ptr;
    pp = *(व्योम ***)ptab;
    /* every power of two we double array size */
    अगर ((nb & (nb - 1)) == 0) {
        अगर (!nb)
            nb_alloc = 1;
        अन्यथा
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * माप(व्योम *));
        *(व्योम***)ptab = pp;
    }
    pp[nb++] = तथ्य;
    *nb_ptr = nb;
}

ST_FUNC व्योम dynarray_reset(व्योम *pp, पूर्णांक *n)
{
    व्योम **p;
    क्रम (p = *(व्योम***)pp; *n; ++p, --*n)
        अगर (*p)
            tcc_free(*p);
    tcc_free(*(व्योम**)pp);
    *(व्योम**)pp = शून्य;
}

अटल व्योम dynarray_split(अक्षर ***argv, पूर्णांक *argc, स्थिर अक्षर *p, पूर्णांक sep)
{
    पूर्णांक qot, c;
    CString str;
    क्रम(;;) {
        जबतक (c = (अचिन्हित अक्षर)*p, c <= ' ' && c != '\0')
            ++p;
        अगर (c == '\0')
            अवरोध;
        cstr_new(&str);
        qot = 0;
        करो {
            ++p;
            अगर (sep) { /* e.g. to split -Wl,-opt,arg */
                अगर (c == sep)
                    अवरोध;
            } अन्यथा {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                अगर (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } अन्यथा अगर (c == '"') {
                    qot ^= 1;
                    जारी;
                } अन्यथा अगर (c <= ' ' && !qot) {
                    अवरोध;
                }
            }
            cstr_ccat(&str, c);
        } जबतक (c = (अचिन्हित अक्षर)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.तथ्य);
    }
}

अटल व्योम tcc_split_path(TCCState *s, व्योम *p_ary, पूर्णांक *p_nb_ary, स्थिर अक्षर *in)
{
    स्थिर अक्षर *p;
    करो {
        पूर्णांक c;
        CString str;

        cstr_new(&str);
        क्रम (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            अगर (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                अगर (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                अगर (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                अगर (c == 'f' && file) {
                    /* substitute current file's dir */
                    स्थिर अक्षर *f = file->true_filename;
                    स्थिर अक्षर *b = tcc_basename(f);
                    अगर (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    अन्यथा
                        cstr_cat(&str, ".", 1);
                }
            } अन्यथा {
                cstr_ccat(&str, c);
            }
        }
        अगर (str.आकार) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.तथ्य);
        }
        in = p+1;
    } जबतक (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#घोषणा WARN_ON  1 /* warning is on (-Woption) */
#घोषणा WARN_ERR 2 /* warning is an error (-Werror=option) */
#घोषणा WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
क्रमागत { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

अटल व्योम error1(पूर्णांक mode, स्थिर अक्षर *fmt, बहु_सूची ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    पूर्णांक पंक्ति_2 = 0;

    tcc_exit_state(s1);

    अगर (mode == ERROR_WARN) {
        अगर (s1->warn_error)
            mode = ERROR_ERROR;
        अगर (s1->warn_अंक) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            पूर्णांक wopt = *(&s1->warn_none + s1->warn_अंक);
            s1->warn_अंक = 0;
            अगर (0 == (wopt & WARN_ON))
                वापस;
            अगर (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            अगर (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        अगर (s1->warn_none)
            वापस;
    }

    cstr_new(&cs);
    अगर (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        पंक्ति_2 = बहु_तर्क(ap, पूर्णांक), fmt += 3;
    f = शून्य;
    अगर (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        क्रम (f = file; f && f->filename[0] == ':'; f = f->पूर्व)
            ;
    }
    अगर (f) {
        क्रम(pf = s1->include_ढेर; pf < s1->include_ढेर_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->पंक्ति_अंक - 1);
        अगर (0 == पंक्ति_2)
            पंक्ति_2 = f->पंक्ति_अंक - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, पंक्ति_2);
    } अन्यथा अगर (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } अन्यथा {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    अगर (pp_व्यंजक > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    अन्यथा
        cstr_vprintf(&cs, fmt, ap);
    अगर (!s1->error_func) {
        /* default case: stderr */
        अगर (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == मानक_निकास)
            म_लिखो("\n"); /* print a newline during tcc -E */
        ख_साफ(मानक_निकास); /* flush -v output */
        ख_लिखो(मानक_त्रुटि, "%s\n", (अक्षर*)cs.तथ्य);
        ख_साफ(मानक_त्रुटि); /* print error/warning now (win32) */
    } अन्यथा {
        s1->error_func(s1->error_opaque, (अक्षर*)cs.तथ्य);
    }
    cstr_free(&cs);
    अगर (mode != ERROR_WARN)
        s1->nb_errors++;
    अगर (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        जबतक (nb_stk_तथ्य)
            tcc_free(*(व्योम**)stk_तथ्य[--nb_stk_तथ्य]);
        दीर्घ_लाँघ(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI व्योम tcc_set_error_func(TCCState *s, व्योम *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC पूर्णांक _tcc_error_noabort(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    बहु_पूर्ण(ap);
    वापस -1;
}

#अघोषित _tcc_error
PUB_FUNC व्योम _tcc_error(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    निकास(1);
}
#घोषणा _tcc_error use_tcc_error_noabort

PUB_FUNC व्योम _tcc_warning(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap;
    बहु_शुरू(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    बहु_पूर्ण(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC व्योम tcc_open_bf(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक initlen)
{
    BufferedFile *bf;
    पूर्णांक buflen = initlen ? initlen : IO_BUF_आकार;

    bf = tcc_mallocz(माप(BufferedFile) + buflen);
    bf->buf_ptr = bf->बफर;
    bf->buf_end = bf->बफर + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, माप(bf->filename), filename);
#अगर_घोषित _WIN32
    normalize_slashes(bf->filename);
#पूर्ण_अगर
    bf->true_filename = bf->filename;
    bf->पंक्ति_अंक = 1;
    bf->ifdef_ढेर_ptr = s1->ifdef_ढेर_ptr;
    bf->fd = -1;
    bf->पूर्व = file;
    bf->पूर्व_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC व्योम tcc_close(व्योम)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    अगर (bf->fd > 0) {
        बंद(bf->fd);
        योग_पंक्तियाँ += bf->पंक्ति_अंक - 1;
    }
    अगर (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->पूर्व;
    tok_flags = bf->पूर्व_tok_flags;
    tcc_free(bf);
}

अटल पूर्णांक _tcc_open(TCCState *s1, स्थिर अक्षर *filename)
{
    पूर्णांक fd;
    अगर (म_भेद(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    अन्यथा
        fd = खोलो(filename, O_RDONLY | O_द्विआधारी_2);
    अगर ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        म_लिखो("%s %*s%s\n", fd < 0 ? "nf":"->",
               (पूर्णांक)(s1->include_ढेर_ptr - s1->include_ढेर), "", filename);
    वापस fd;
}

ST_FUNC पूर्णांक tcc_open(TCCState *s1, स्थिर अक्षर *filename)
{
    पूर्णांक fd = _tcc_open(s1, filename);
    अगर (fd < 0)
        वापस -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    वापस 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
अटल पूर्णांक tcc_compile(TCCState *s1, पूर्णांक filetype, स्थिर अक्षर *str, पूर्णांक fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    अगर (बनाओ_लाँघ(s1->error_jmp_buf) == 0) {

        अगर (fd == -1) {
            पूर्णांक len = म_माप(str);
            tcc_open_bf(s1, "<string>", len);
            स_नकल(file->बफर, str, len);
        } अन्यथा {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        अगर (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } अन्यथा {
            tccelf_begin_file(s1);
            अगर (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
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
    वापस s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI पूर्णांक tcc_compile_string(TCCState *s, स्थिर अक्षर *str)
{
    वापस tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI व्योम tcc_define_प्रतीक(TCCState *s1, स्थिर अक्षर *sym, स्थिर अक्षर *मूल्य)
{
    स्थिर अक्षर *eq;
    अगर (शून्य == (eq = म_अक्षर(sym, '=')))
        eq = म_अक्षर(sym, 0);
    अगर (शून्य == मूल्य)
        मूल्य = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (पूर्णांक)(eq-sym), sym, मूल्य);
}

/* undefine a preprocessor symbol */
LIBTCCAPI व्योम tcc_undefine_प्रतीक(TCCState *s1, स्थिर अक्षर *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(व्योम)
{
    TCCState *s;

    s = tcc_mallocz(माप(TCCState));
#अगर_घोषित MEM_DEBUG
    tcc_memcheck(1);
#पूर्ण_अगर

#अघोषित gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_in_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#अगर_घोषित CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#पूर्ण_अगर
#अगर_घोषित TCC_TARGET_I386
    s->seg_आकार = 32;
#पूर्ण_अगर
    /* enable this if you want symbols with leading underscore on windows: */
#अगर defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#पूर्ण_अगर
#अगर_घोषित TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#पूर्ण_अगर
#अगर defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#पूर्ण_अगर
#अगर_घोषित CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#पूर्ण_अगर
    s->ppfp = मानक_निकास;
    /* might be used in error() before preprocess_start() */
    s->include_ढेर_ptr = s->include_ढेर;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#अगर_घोषित CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#पूर्ण_अगर
    वापस s;
}

LIBTCCAPI व्योम tcc_delete(TCCState *s1)
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
#अगर defined TCC_TARGET_MACHO
    tcc_free(s1->install_name);
#पूर्ण_अगर
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#अगर_घोषित TCC_IS_NATIVE
    /* free runtime memory */
    tcc_run_free(s1);
#पूर्ण_अगर
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#अगर_घोषित MEM_DEBUG
    tcc_memcheck(-1);
#पूर्ण_अगर
}

LIBTCCAPI पूर्णांक tcc_set_output_type(TCCState *s, पूर्णांक output_type)
{
#अगर_घोषित CONFIG_TCC_PIE
    अगर (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#पूर्ण_अगर
    s->output_type = output_type;

    अगर (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    अगर (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        वापस 0;
    }

    /* add sections */
    tccelf_new(s);

    अगर (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        वापस 0;
    }

    अगर (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#अगर_घोषित TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#या_अगर defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#अन्यथा
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    अगर (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#पूर्ण_अगर
    वापस s->nb_errors ? -1 : 0;
}

LIBTCCAPI पूर्णांक tcc_add_include_path(TCCState *s, स्थिर अक्षर *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    वापस 0;
}

LIBTCCAPI पूर्णांक tcc_add_sysinclude_path(TCCState *s, स्थिर अक्षर *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    वापस 0;
}

LIBTCCAPI पूर्णांक tcc_add_library_path(TCCState *s, स्थिर अक्षर *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    वापस 0;
}

LIBTCCAPI व्योम tcc_set_lib_path(TCCState *s, स्थिर अक्षर *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, स्थिर अक्षर *dllname, पूर्णांक level)
{
    DLLReference *ref = शून्य;
    पूर्णांक i;
    क्रम (i = 0; i < s1->nb_loaded_dlls; i++)
        अगर (0 == म_भेद(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            अवरोध;
        }
    अगर (level == -1)
        वापस ref;
    अगर (ref) {
        अगर (level < ref->level)
            ref->level = level;
        ref->found = 1;
        वापस ref;
    }
    ref = tcc_mallocz(माप(DLLReference) + म_माप(dllname));
    म_नकल(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->सूचकांक = s1->nb_loaded_dlls;
    वापस ref;
}

अटल पूर्णांक tcc_add_द्विआधारी(TCCState *s1, पूर्णांक flags, स्थिर अक्षर *filename, पूर्णांक fd)
{
    ElfW(Ehdr) ehdr;
    पूर्णांक obj_type;
    स्थिर अक्षर *saved_filename = s1->current_filename;
    पूर्णांक ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, शुरू_से);

    चयन (obj_type) {

    हाल AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        अवरोध;

    हाल AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        अवरोध;

#अगर defined TCC_TARGET_UNIX
    हाल AFF_BINTYPE_DYN:
        अगर (s1->output_type == TCC_OUTPUT_MEMORY) {
#अगर_घोषित TCC_IS_NATIVE
            व्योम* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            अगर (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
#पूर्ण_अगर
        } अन्यथा
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        अवरोध;

    शेष:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        अवरोध;

#या_अगर defined TCC_TARGET_MACHO
    हाल AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        अगर (s1->output_type == TCC_OUTPUT_MEMORY) {
#अगर_घोषित TCC_IS_NATIVE
            व्योम* dl;
            स्थिर अक्षर* soname = filename;
            अक्षर *tmp = 0;
            अगर (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                अगर (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            अगर (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#पूर्ण_अगर
        } अन्यथा अगर (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } अन्यथा {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        अगर (ret)
            ret = FILE_NOT_RECOGNIZED;
        अवरोध;

    शेष:
    {
        स्थिर अक्षर *ext = tcc_fileextension(filename);
        अगर (!म_भेद(ext, ".tbd"))
            जाओ case_dyn_or_tbd;
        अगर (!म_भेद(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            जाओ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        अवरोध;
    }

#या_अगर defined TCC_TARGET_PE
    शेष:
        अगर (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        अवरोध;
#पूर्ण_अगर

#अगर_घोषित TCC_TARGET_COFF
    हाल AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        अवरोध;
#पूर्ण_अगर
    }

    बंद(fd);
    s1->current_filename = saved_filename;
    अगर (ret == FILE_NOT_RECOGNIZED)
        वापस tcc_error_noabort("%s: unrecognized file type", filename);
    वापस ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#अगर defined TARGETOS_OpenBSD && !defined _WIN32
#समावेश <glob.h>
अटल पूर्णांक tcc_glob_so(TCCState *s1, स्थिर अक्षर *pattern, अक्षर *buf, पूर्णांक आकार)
{
    स्थिर अक्षर *star;
    glob_t g;
    अक्षर *p;
    पूर्णांक i, v, v1, v2, v3;

    star = म_अक्षर(pattern, '*');
    अगर (!star || glob(pattern, 0, शून्य, &g))
        वापस -1;
    क्रम (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        अगर (2 != माला_पूछो(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            जारी;
        अगर ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, आकार, p);
    }
    globfree(&g);
    वापस v;
}
#पूर्ण_अगर

अटल पूर्णांक guess_filetype(स्थिर अक्षर *filename)
{
    पूर्णांक filetype = 0;
    अगर (1) {
        /* use a file extension to detect a filetype */
        स्थिर अक्षर *ext = tcc_fileextension(filename);
        अगर (ext[0]) {
            ext++;
            अगर (!म_भेद(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            अन्यथा अगर (!म_भेद(ext, "s"))
                filetype = AFF_TYPE_ASM;
            अन्यथा अगर (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            अन्यथा
                filetype |= AFF_TYPE_BIN;
        } अन्यथा {
            filetype = AFF_TYPE_C;
        }
    }
    वापस filetype;
}

ST_FUNC पूर्णांक tcc_add_file_internal(TCCState *s1, स्थिर अक्षर *filename, पूर्णांक flags)
{
    पूर्णांक fd;

#अगर defined TARGETOS_OpenBSD && !defined _WIN32
    अक्षर buf[1024];
    अगर (tcc_glob_so(s1, filename, buf, माप buf) >= 0)
        filename = buf;
#पूर्ण_अगर

    अगर (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    अगर (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        वापस 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    अगर (fd < 0) {
        अगर (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        वापस FILE_NOT_FOUND;
    }

    अगर (flags & AFF_TYPE_BIN)
        वापस tcc_add_द्विआधारी(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    वापस tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI पूर्णांक tcc_add_file(TCCState *s, स्थिर अक्षर *filename)
{
    वापस tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

अटल पूर्णांक tcc_add_library_internal(TCCState *s1, स्थिर अक्षर *fmt,
    स्थिर अक्षर *filename, पूर्णांक flags, अक्षर **paths, पूर्णांक nb_paths)
{
    अक्षर buf[1024];
    पूर्णांक i, ret;

    क्रम(i = 0; i < nb_paths; i++) {
        snprintf(buf, माप(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        अगर (ret != FILE_NOT_FOUND)
            वापस ret;
    }
    अगर (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    वापस FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC पूर्णांक tcc_add_dll(TCCState *s, स्थिर अक्षर *filename, पूर्णांक flags)
{
    वापस tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC पूर्णांक tcc_add_support(TCCState *s1, स्थिर अक्षर *filename)
{
    अक्षर buf[100];
    अगर (CONFIG_TCC_CROSSPREFIX[0])
        filename = म_जोड़ो(म_नकल(buf, CONFIG_TCC_CROSSPREFIX), filename);
    वापस tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#अगर_घोषित TCC_TARGET_UNIX
ST_FUNC पूर्णांक tcc_add_crt(TCCState *s1, स्थिर अक्षर *filename)
{
    वापस tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#पूर्ण_अगर

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णांक tcc_add_library(TCCState *s, स्थिर अक्षर *libraryname)
{
    अटल स्थिर अक्षर * स्थिर libs[] = {
#अगर defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#या_अगर defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#या_अगर defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#अन्यथा
        "%s/lib%s.so",
#पूर्ण_अगर
        "%s/lib%s.a",
        शून्य
    };
    पूर्णांक flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    अगर (*libraryname == ':') {
        libraryname++;
    } अन्यथा {
        स्थिर अक्षर * स्थिर *pp = libs;
        अगर (s->static_link)
            pp += माप(libs) / माप(*libs) - 2; /* only "%s/lib%s.a" */
        जबतक (*pp) {
            पूर्णांक ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            अगर (ret != FILE_NOT_FOUND)
                वापस ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    वापस tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC व्योम tcc_add_pragma_libs(TCCState *s1)
{
    पूर्णांक i;
    क्रम (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

अटल पूर्णांक strstart(स्थिर अक्षर *val, स्थिर अक्षर **str)
{
    स्थिर अक्षर *p, *q;
    p = *str;
    q = val;
    जबतक (*q) {
        अगर (*p != *q)
            वापस 0;
        p++;
        q++;
    }
    *str = p;
    वापस 1;
}

काष्ठा lopt {
    TCCState *s;
    स्थिर अक्षर *opt, *arg;
    पूर्णांक match;
};

/* match linker option */
अटल पूर्णांक link_option(काष्ठा lopt *o, स्थिर अक्षर *q)
{
    स्थिर अक्षर *p;
    पूर्णांक c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    अगर (*p++ != '-')
        वापस 0;
    अगर (*p == '-')
        p++;
    r = 1;
    अगर (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        अगर (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#अगर_घोषित TCC_TARGET_PE
        अन्यथा अगर (0 == स_भेद(p, "disable-", 8))
            p += 8, r = -1;
#पूर्ण_अगर
    }
    जबतक ((c = *q) == *p) {
        अगर (c == '\0')
            जाओ succ; /* -Wl,-opt */
        ++p;
        अगर (c == '=')
            जाओ succ; /* -Wl,-opt=arg */
        ++q;
    }
    अगर (*p == '\0') {
        अगर (c == '|')
            जाओ succ;
        अगर (c == '=' || c == ':') {
            अगर (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                जाओ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            वापस 0;
        }
    } अन्यथा अगर (c == ':')
        जाओ succ; /* -Wl,-Iarg */
    जबतक (*q)
        अगर (*q++ == '|')
            जाओ redo;
    वापस 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    वापस r;
}

अटल व्योम args_parser_add_file(TCCState *s, स्थिर अक्षर* filename, पूर्णांक filetype);

#घोषणा SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#घोषणा SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
अटल पूर्णांक tcc_set_linker(TCCState *s, स्थिर अक्षर *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    जबतक (s->link_optind < s->link_argc) {
        अक्षर *end = शून्य;
        पूर्णांक ignoring = 0;
        काष्ठा lopt o = {0};
        पूर्णांक r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        अगर (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } अन्यथा अगर (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } अन्यथा अगर (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } अन्यथा अगर (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } अन्यथा अगर (link_option(&o, "init=")) {
            tcc_set_str(&s->init_प्रतीक, o.arg);
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_प्रतीक, o.arg);
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "oformat=")) {
#अगर defined TCC_TARGET_PE
            अगर (0 == म_भेदन("pe-", o.arg, 3))
#या_अगर PTR_आकार == 8
            अगर (0 == म_भेदन("elf64-", o.arg, 6))
#अन्यथा
            अगर (0 == म_भेदन("elf32-", o.arg, 6))
#पूर्ण_अगर
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            अन्यथा अगर (0==म_भेद("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_द्विआधारी;
#अगर defined TCC_TARGET_COFF
            अन्यथा अगर (0==म_भेद("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#पूर्ण_अगर
            अन्यथा
                जाओ err;
        } अन्यथा अगर (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } अन्यथा अगर (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } अन्यथा अगर (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } अन्यथा अगर (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } अन्यथा अगर (link_option(&o, "section-alignment=")) {
            s->section_align = म_से_अदीर्घ(o.arg, &end, 16);
        } अन्यथा अगर (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } अन्यथा अगर (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } अन्यथा अगर (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#अगर_घोषित TCC_TARGET_PE
        } अन्यथा अगर (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } अन्यथा अगर (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } अन्यथा अगर (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } अन्यथा अगर (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } अन्यथा अगर (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } अन्यथा अगर (link_option(&o, "file-alignment=")) {
            s->pe_file_align = म_से_अदीर्घ(o.arg, &end, 16);
        } अन्यथा अगर (link_option(&o, "stack=")) {
            s->pe_ढेर_आकार = म_से_अदीर्घ(o.arg, &end, 10);
        } अन्यथा अगर (link_option(&o, "subsystem=")) {
            अगर (pe_setsubsy(s, o.arg) < 0)
                जाओ err;
#या_अगर defined TCC_TARGET_MACHO
        } अन्यथा अगर (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } अन्यथा अगर (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } अन्यथा अगर (link_option(&o, "single_module")) {
            ignoring = 1;
#पूर्ण_अगर
        } अन्यथा अगर (link_option(&o, "as-needed")) {
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "O")) {
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "z=")) {
            ignoring = 1;
        } अन्यथा अगर (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } अन्यथा अगर (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } अन्यथा अगर (o.match) {
            वापस 0; /* expecting argument with next '-Wl,' */
        } अन्यथा {
    err:
            वापस tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        अगर (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    वापस 0;
}

प्रकार काष्ठा TCCOption {
    स्थिर अक्षर *name;
    uint16_t सूचकांक;
    uint16_t flags;
} TCCOption;

क्रमागत {
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

#घोषणा TCC_OPTION_HAS_ARG 0x0001
#घोषणा TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

अटल स्थिर TCCOption tcc_options[] = {
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
#अगर_घोषित CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#पूर्ण_अगर
#अगर_घोषित CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#पूर्ण_अगर
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#अगर_घोषित TCC_TARGET_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_version, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_version, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#पूर्ण_अगर
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
#अगर_घोषित TCC_TARGET_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#पूर्ण_अगर
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
#अगर_घोषित TCC_TARGET_PE
    { "impdef", TCC_OPTION_impdef, 0},
#पूर्ण_अगर
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
    { शून्य, 0, 0 },
};

प्रकार काष्ठा FlagDef {
    uint16_t offset;
    uint16_t flags;
    स्थिर अक्षर *name;
} FlagDef;

#घोषणा WD_ALL    0x0001 /* warning is activated when using -Wall */
#घोषणा FD_INVERT 0x0002 /* invert value before storing */

अटल स्थिर FlagDef options_W[] = {
    { दुरत्व(TCCState, warn_all), WD_ALL, "all" },
    { दुरत्व(TCCState, warn_error), 0, "error" },
    { दुरत्व(TCCState, warn_write_strings), 0, "write-strings" },
    { दुरत्व(TCCState, warn_unsupported), 0, "unsupported" },
    { दुरत्व(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { दुरत्व(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, शून्य }
};

अटल स्थिर FlagDef options_f[] = {
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
    { 0, 0, शून्य }
};

अटल स्थिर FlagDef options_m[] = {
    { दुरत्व(TCCState, ms_bitfields), 0, "ms-bitfields" },
#अगर_घोषित TCC_TARGET_X86_64
    { दुरत्व(TCCState, nosse), FD_INVERT, "sse" },
#पूर्ण_अगर
    { 0, 0, शून्य }
};

अटल पूर्णांक set_flag(TCCState *s, स्थिर FlagDef *flags, स्थिर अक्षर *name)
{
    पूर्णांक मूल्य, mask, ret;
    स्थिर FlagDef *p;
    स्थिर अक्षर *r;
    अचिन्हित अक्षर *f;

    r = name, मूल्य = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    अगर ((flags->flags & WD_ALL) && strstart("error=", &r))
        मूल्य = मूल्य ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    क्रम (ret = -1, p = flags; p->name; ++p) {
        अगर (ret) {
            अगर (म_भेद(r, p->name))
                जारी;
        } अन्यथा {
            अगर (0 == (p->flags & WD_ALL))
                जारी;
        }

        f = (अचिन्हित अक्षर *)s + p->offset;
        *f = (*f & mask) | (मूल्य ^ !!(p->flags & FD_INVERT));

        अगर (ret) {
            ret = 0;
            अगर (म_भेद(r, "all"))
                अवरोध;
        }
    }
    वापस ret;
}

अटल स्थिर अक्षर dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#अगर_घोषित TCC_TARGET_I386
    "i386-pc"
#या_अगर defined TCC_TARGET_X86_64
    "x86_64-pc"
#या_अगर defined TCC_TARGET_C67
    "c67"
#या_अगर defined TCC_TARGET_ARM
    "arm"
#या_अगर defined TCC_TARGET_ARM64
    "aarch64"
#या_अगर defined TCC_TARGET_RISCV64
    "riscv64"
#पूर्ण_अगर
    "-"
#अगर_घोषित TCC_TARGET_PE
    "mingw32"
#या_अगर defined(TCC_TARGET_MACHO)
    "apple-darwin"
#या_अगर TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#या_अगर TARGETOS_OpenBSD
    "openbsd"
#या_अगर TARGETOS_NetBSD
    "netbsd"
#या_अगर CONFIG_TCC_MUSL
    "linux-musl"
#अन्यथा
    "linux-gnu"
#पूर्ण_अगर
;

#अगर defined TCC_TARGET_MACHO
अटल uint32_t parse_version(TCCState *s1, स्थिर अक्षर *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    अक्षर* last;

    a = म_से_अदीर्घ(version, &last, 10);
    अगर (*last == '.') {
        b = म_से_अदीर्घ(&last[1], &last, 10);
        अगर (*last == '.')
             c = म_से_अदीर्घ(&last[1], &last, 10);
    }
    अगर (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    वापस (a << 16) | (b << 8) | c;
}
#पूर्ण_अगर

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
अटल व्योम जोड़ो_args(TCCState *s1, अक्षर ***pargv, पूर्णांक *pargc, पूर्णांक optind, स्थिर अक्षर *p, पूर्णांक sep)
{
    पूर्णांक argc = 0;
    अक्षर **argv = शून्य;
    पूर्णांक i;
    क्रम (i = 0; i < *pargc; ++i)
        अगर (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        अन्यथा
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

अटल व्योम args_parser_add_file(TCCState *s, स्थिर अक्षर* filename, पूर्णांक filetype)
{
    काष्ठा filespec *f = tcc_malloc(माप *f + म_माप(filename));
    f->type = filetype;
    म_नकल(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    अगर (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC पूर्णांक tcc_parse_args(TCCState *s, पूर्णांक *pargc, अक्षर ***pargv)
{
    TCCState *s1 = s;
    स्थिर TCCOption *popt;
    स्थिर अक्षर *optarg, *r;
    स्थिर अक्षर *run = शून्य;
    पूर्णांक optind = 1, empty = 1, x;
    अक्षर **argv = *pargv;
    पूर्णांक argc = *pargc;

    s->link_optind = s->link_argc;

    जबतक (optind < argc) {
        r = argv[optind];
        अगर (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            पूर्णांक fd; अक्षर *p;
            fd = खोलो(++r, O_RDONLY | O_द्विआधारी_2);
            अगर (fd < 0)
                वापस tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            जोड़ो_args(s1, &argv, &argc, optind, p, 0);
            बंद(fd), tcc_free(p);
            जारी;
        }
        optind++;
        अगर (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            अगर (run)
                अवरोध;
            जारी;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        अगर (r[1] == '-' && r[2] == '\0')
            जाओ dorun;

        /* find option in table */
        क्रम(popt = tcc_options; ; ++popt) {
            स्थिर अक्षर *p1 = popt->name;
            स्थिर अक्षर *r1 = r + 1;
            अगर (p1 == शून्य)
                वापस tcc_error_noabort("invalid option -- '%s'", r);
            अगर (!strstart(p1, &r1))
                जारी;
            optarg = r1;
            अगर (popt->flags & TCC_OPTION_HAS_ARG) {
                अगर (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    अगर (optind >= argc)
                        वापस tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } अन्यथा अगर (*r1 != '\0')
                जारी;
            अवरोध;
        }

        चयन(popt->सूचकांक) {
        हाल TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            अवरोध;
        हाल TCC_OPTION_D:
            tcc_define_प्रतीक(s, optarg, शून्य);
            अवरोध;
        हाल TCC_OPTION_U:
            tcc_undefine_प्रतीक(s, optarg);
            अवरोध;
        हाल TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            अवरोध;
        हाल TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            जारी;
        हाल TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            अवरोध;
        हाल TCC_OPTION_pthread:
            s->option_pthread = 1;
            अवरोध;
        हाल TCC_OPTION_bench:
            s->do_bench = 1;
            अवरोध;
#अगर_घोषित CONFIG_TCC_BACKTRACE
        हाल TCC_OPTION_bt:
            s->rt_अंक_callers = म_से_प(optarg); /* zero = default (6) */
            जाओ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            अगर (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            अवरोध;
#अगर_घोषित CONFIG_TCC_BCHECK
        हाल TCC_OPTION_b:
            s->do_bounds_check = 1;
            जाओ enable_backtrace;
#पूर्ण_अगर
#पूर्ण_अगर
        हाल TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            अगर (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - म_से_प(optarg)) : DEFAULT_DWARF_VERSION;
            } अन्यथा अगर (0 == म_भेद("stabs", optarg)) {
                s->dwarf = 0;
            } अन्यथा अगर (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                जाओ g_redo;
#अगर_घोषित TCC_TARGET_PE
            } अन्यथा अगर (0 == म_भेद(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#पूर्ण_अगर
            }
            अवरोध;
        हाल TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            अगर (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            अवरोध;
        हाल TCC_OPTION_d:
            अगर (*optarg == 'D')
                s->dflag = 3;
            अन्यथा अगर (*optarg == 'M')
                s->dflag = 7;
            अन्यथा अगर (*optarg == 't')
                s->dflag = 16;
            अन्यथा अगर (isnum(*optarg))
                g_debug |= म_से_प(optarg);
            अन्यथा
                जाओ unsupported_option;
            अवरोध;
        हाल TCC_OPTION_static:
            s->static_link = 1;
            अवरोध;
        हाल TCC_OPTION_std:
            अगर (म_भेद(optarg, "=c11") == 0 || म_भेद(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            अवरोध;
        हाल TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            जाओ set_output_type;
        हाल TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            अवरोध;
        हाल TCC_OPTION_o:
            अगर (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            अवरोध;
        हाल TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            जाओ set_output_type;
        हाल TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            अवरोध;
        हाल TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            अवरोध;
        हाल TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            अवरोध;
        हाल TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            अवरोध;
        हाल TCC_OPTION_run:
#अगर_घोषित TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            जाओ set_output_type;
#अन्यथा
            वापस tcc_error_noabort("-run is not available in a cross compiler");
#पूर्ण_अगर
#अगर_घोषित TCC_IS_NATIVE
        हाल TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            अवरोध;
#पूर्ण_अगर
        हाल TCC_OPTION_v:
            करो ++s->verbose; जबतक (*optarg++ == 'v');
            जारी;
        हाल TCC_OPTION_f:
            अगर (set_flag(s, options_f, optarg) < 0)
                जाओ unsupported_option;
            अवरोध;
#अगर_घोषित TCC_TARGET_ARM
        हाल TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            अगर (!म_भेद(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } अन्यथा अगर (!म_भेद(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            अन्यथा
                वापस tcc_error_noabort("unsupported float abi '%s'", optarg);
            जारी;
#पूर्ण_अगर
        हाल TCC_OPTION_m:
            अगर (set_flag(s, options_m, optarg) < 0) {
                अगर (x = म_से_प(optarg), x != 32 && x != 64)
                    जाओ unsupported_option;
                अगर (PTR_आकार != x/8)
                    वापस x;
                जारी;
            }
            अवरोध;
        हाल TCC_OPTION_W:
            अगर (optarg[0] && set_flag(s, options_W, optarg) < 0)
                जाओ unsupported_option;
            अवरोध;
        हाल TCC_OPTION_w:
            s->warn_none = 1;
            अवरोध;
        हाल TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            अवरोध;
        हाल TCC_OPTION_Wl:
            अगर (tcc_set_linker(s, optarg) < 0)
                वापस -1;
            अवरोध;
        हाल TCC_OPTION_Wp:
            अगर (argv[0]) /* not with tcc_set_options() */
                जोड़ो_args(s, &argv, &argc, --optind, optarg, ',');
            अवरोध;
        हाल TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            जाओ set_output_type;
        हाल TCC_OPTION_P:
            s->Pflag = म_से_प(optarg) + 1;
            अवरोध;

        हाल TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        हाल TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            अगर (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            अवरोध;
        हाल TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        हाल TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            अगर (*optarg != ',')
                अवरोध;
            ++optarg;
            // fall through
        हाल TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            अवरोध;
        हाल TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            अवरोध;

        हाल TCC_OPTION_dumpmachine:
            म_लिखो("%s\n", dumpmachine_str);
            निकास(0);
        हाल TCC_OPTION_dumpversion:
            म_लिखो ("%s\n", TCC_VERSION);
            निकास(0);

        हाल TCC_OPTION_x:
            x = 0;
            अगर (*optarg == 'c')
                x = AFF_TYPE_C;
            अन्यथा अगर (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            अन्यथा अगर (*optarg == 'b')
                x = AFF_TYPE_BIN;
            अन्यथा अगर (*optarg == 'n')
                x = AFF_TYPE_NONE;
            अन्यथा
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            अवरोध;
        हाल TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            अवरोध;
#अगर defined TCC_TARGET_MACHO
        हाल TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            जाओ set_output_type;
        हाल TCC_OPTION_flat_namespace:
	     अवरोध;
        हाल TCC_OPTION_two_levelnamespace:
	     अवरोध;
        हाल TCC_OPTION_undefined:
	     अवरोध;
        हाल TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            अवरोध;
        हाल TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            अवरोध;
        हाल TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            अवरोध;
#पूर्ण_अगर
        हाल TCC_OPTION_HELP:
            x = OPT_HELP;
            जाओ extra_action;
        हाल TCC_OPTION_HELP2:
            x = OPT_HELP2;
            जाओ extra_action;
        हाल TCC_OPTION_print_खोज_dirs:
            x = OPT_PRINT_DIRS;
            जाओ extra_action;
        हाल TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            जाओ extra_action;
        हाल TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            अगर (शून्य == argv[0]) /* from tcc_set_options() */
                वापस -1;
            अगर (!empty && x)
                वापस tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            वापस x;
        शेष:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            अवरोध;
        }
        empty = 0;
    }
    अगर (s->link_optind < s->link_argc)
        वापस tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    अगर (run) {
        अगर (*run && tcc_set_options(s, run) < 0)
            वापस -1;
        x = 0, r = 0;
        जाओ extra_action;
    }
    अगर (!empty)
        वापस 0;
    अगर (s->verbose == 2)
        वापस OPT_PRINT_DIRS;
    अगर (s->verbose)
        वापस OPT_V;
    वापस OPT_HELP;
}

LIBTCCAPI पूर्णांक tcc_set_options(TCCState *s, स्थिर अक्षर *r)
{
    अक्षर **argv = शून्य;
    पूर्णांक argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    वापस ret;
}

PUB_FUNC व्योम tcc_print_stats(TCCState *s1, अचिन्हित योग_time)
{
    अगर (!योग_time)
        योग_time = 1;
    ख_लिखो(मानक_त्रुटि, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           योग_idents, योग_पंक्तियाँ, योग_bytes,
           (द्विगुन)योग_time/1000,
           (अचिन्हित)योग_पंक्तियाँ*1000/योग_time,
           (द्विगुन)योग_bytes/1000/योग_time);
    ख_लिखो(मानक_त्रुटि, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->योग_output[0],
           s1->योग_output[1],
           s1->योग_output[2],
           s1->योग_output[3]
           );
#अगर_घोषित MEM_DEBUG
    ख_लिखो(मानक_त्रुटि, "# memory usage");
#अगर_घोषित TCC_IS_NATIVE
    अगर (s1->run_आकार) {
        Section *s = s1->symtab;
        अचिन्हित ms = s->तथ्य_offset + s->link->तथ्य_offset + s->hash->तथ्य_offset;
        अचिन्हित rs = s1->run_आकार;
        ख_लिखो(मानक_त्रुटि, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_आकार - rs - ms);
    }
#पूर्ण_अगर
    ख_लिखो(मानक_त्रुटि, " %d max (bytes)\n", mem_max_आकार);
#पूर्ण_अगर
}
