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

#यदि_अपरिभाषितम् ONE_SOURCE
# define ONE_SOURCE 1
#यदि_अन्तः

#यदि ONE_SOURCE
#अन्तर्भाव "tccpp.c"
#अन्तर्भाव "tccgen.c"
#अन्तर्भाव "tccdbg.c"
#अन्तर्भाव "tccasm.c"
#अन्तर्भाव "tccelf.c"
#अन्तर्भाव "tccrun.c"
#यदि_परिभाषितम् TCC_TARGET_I386
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
#दोषः unknown target
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_PE
#अन्तर्भाव "tccpe.c"
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_MACHO
#अन्तर्भाव "tccmacho.c"
#यदि_अन्तः
#यदि_अन्तः /* ONE_SOURCE */

#अन्तर्भाव "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_दत्त संरचना TCCState *tcc_state;
TCC_SEM(स्थिर tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_दत्त शून्य** stk_दत्त;
ST_दत्त पूर्णाङ्क nb_stk_दत्त;
/* option -d<num> (for general development purposes) */
ST_दत्त पूर्णाङ्क g_debug;

/********************************************************/
#यदि_परिभाषितम् _WIN32
ST_FUNC वर्ण *normalize_slashes(वर्ण *मार्गः)
{
    वर्ण *p;
    प्रति (p = मार्गः; *p; ++p)
        यदि (*p == '\\')
            *p = '/';
    प्रत्यागम मार्गः;
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
#परिभाषय tcc_module रिक्त /* NULL means executable itself */
#यदि_अन्तः

#यदि_अपरिभाषितम् CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
स्थिर अन्तःस्थ वर्ण *config_tccdir_w32(वर्ण *मार्गः)
{
    वर्ण *p;
    GetModuleFileNameA(tcc_module, मार्गः, MAX_मार्गः);
    p = tcc_basename(normalize_slashes(strlwr(मार्गः)));
    यदि (p > मार्गः)
        --p;
    *p = 0;
    प्रत्यागम मार्गः;
}
#परिभाषय CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_मार्गः))
#यदि_अन्तः

#यदि_परिभाषितम् TCC_IS_NATIVE
स्थिर शून्य tcc_सङ्कलय_systemdir(TCCState *s)
{
    वर्ण buf[1000];
    GetSystemDirectoryA(buf, परिमाण buf);
    tcc_सङ्कलय_library_मार्गः(s, normalize_slashes(buf));
}
#यदि_अन्तः
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ध्रुव वर्ण *f, ध्रुव वर्ण *m) {
    प्रत्यागम fopen(f, m);
}
PUB_FUNC पूर्णाङ्क tcc_fclose(FILE *f) {
    प्रत्यागम fclose(f);
}
#यदि_अन्तः
/********************************************************/

PUB_FUNC शून्य tcc_enter_state(TCCState *s1)
{
    यदि (s1->error_समुच्चयः_jmp_enabled)
        प्रत्यागम;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC शून्य tcc_exit_state(TCCState *s1)
{
    यदि (s1->error_समुच्चयः_jmp_enabled)
        प्रत्यागम;
    tcc_state = रिक्त;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC वर्ण *pstrcpy(वर्ण *buf, आकार_t buf_आकार, ध्रुव वर्ण *s)
{
    वर्ण *q, *q_अन्तः;
    पूर्णाङ्क c;

    यदि (buf_आकार > 0) {
        q = buf;
        q_अन्तः = buf + buf_आकार - 1;
        यावत् (q < q_अन्तः) {
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
ST_FUNC वर्ण *pstrcat(वर्ण *buf, आकार_t buf_आकार, ध्रुव वर्ण *s)
{
    आकार_t len;
    len = वाक्यदैर्घ्यम्(buf);
    यदि (len < buf_आकार)
        pstrcpy(buf + len, buf_आकार - len, s);
    प्रत्यागम buf;
}

ST_FUNC वर्ण *pstrncpy(वर्ण *बहिर्गमनम्, आकार_t buf_आकार, ध्रुव वर्ण *s, आकार_t अङ्कः)
{
    यदि (अङ्कः >= buf_आकार)
        अङ्कः = buf_आकार - 1;
    स्मृतिं_प्रतिलिख(बहिर्गमनम्, s, अङ्कः);
    बहिर्गमनम्[अङ्कः] = '\0';
    प्रत्यागम बहिर्गमनम्;
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

ST_FUNC वर्ण *tcc_आरोपय_text(पूर्णाङ्क fd)
{
    पूर्णाङ्क len = lseek(fd, 0, SEEK_END);
    वर्ण *buf = आरोपय_दत्त(fd, 0, len + 1);
    buf[len] = 0;
    प्रत्यागम buf;
}

/* replace *pp by copy of 'str' or NULL */
स्थिर शून्य tcc_समुच्चयः_str(वर्ण **pp, ध्रुव वर्ण *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : रिक्त;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
स्थिर शून्य tcc_concat_str(वर्ण **pp, ध्रुव वर्ण *str, पूर्णाङ्क sep)
{
    पूर्णाङ्क l = *pp ? वाक्यदैर्घ्यम्(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + वाक्यदैर्घ्यम्(str) + 1);
    यदि (l && sep) ((*pp)[l - 1] = sep);
    वाक्यं_प्रतिलिख(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#अपरिभाषय मुक्त
#अपरिभाषय realloc

स्थिर शून्य *default_reallocator(शून्य *ptr, अचिह्नित दीर्घ आकार)
{
    शून्य *ptr1;
    यदि (आकार == 0) {
        मुक्त(ptr);
        ptr1 = रिक्त;
    }
    अन्यथा {
        ptr1 = realloc(ptr, आकार);
        यदि (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            निर्गच्छ (1);
        }
    }
    प्रत्यागम ptr1;
}

ST_FUNC शून्य libc_free(शून्य *ptr)
{
    मुक्त(ptr);
}

/* defined to be not used */
#परिभाषय मुक्त(p) use_tcc_free(p)
#परिभाषय realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
स्थिर शून्य *(*reallocator)(शून्य*, अचिह्नित दीर्घ) = default_reallocator;

LIBTCCAPI शून्य tcc_समुच्चयः_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#अपरिभाषय tcc_free
#अपरिभाषय tcc_malloc
#अपरिभाषय tcc_realloc
#अपरिभाषय tcc_mallocz
#अपरिभाषय tcc_strdup

PUB_FUNC शून्य tcc_free(शून्य *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC शून्य *tcc_malloc(अचिह्नित दीर्घ आकार)
{
    प्रत्यागम reallocator(0, आकार);
}

PUB_FUNC शून्य *tcc_realloc(शून्य *ptr, अचिह्नित दीर्घ आकार)
{
    प्रत्यागम reallocator(ptr, आकार);
}

PUB_FUNC शून्य *tcc_mallocz(अचिह्नित दीर्घ आकार)
{
    शून्य *ptr;
    ptr = tcc_malloc(आकार);
    यदि (आकार)
        स्मृतिं_पूरय(ptr, 0, आकार);
    प्रत्यागम ptr;
}

PUB_FUNC वर्ण *tcc_strdup(ध्रुव वर्ण *str)
{
    वर्ण *ptr;
    ptr = tcc_malloc(वाक्यदैर्घ्यम्(str) + 1);
    वाक्यं_प्रतिलिख(ptr, str);
    प्रत्यागम ptr;
}

#यदि_परिभाषितम् MEM_DEBUG

#परिभाषय MEM_DEBUG_MAGIC1 0xFEEDDEB1
#परिभाषय MEM_DEBUG_MAGIC2 0xFEEDDEB2
#परिभाषय MEM_DEBUG_MAGIC3 0xFEEDDEB3
#परिभाषय MEM_DEBUG_FILE_LEN 40
#परिभाषय MEM_DEBUG_CHECK3(शीर्षकम्) \
    (((अचिह्नित वर्ण *) शीर्षकम्->magic3) + शीर्षकम्->आकार)
#परिभाषय MEM_USER_PTR(शीर्षकम्) \
    ((वर्ण *)शीर्षकम् + offsetof(mem_debug_शीर्षकम्_t, magic3))
#परिभाषय MEM_शीर्षकम्_PTR(ptr) \
    (mem_debug_शीर्षकम्_t *)((वर्ण*)ptr - offsetof(mem_debug_शीर्षकम्_t, magic3))

संरचना mem_debug_शीर्षकम् {
    अचिह्नित magic1;
    अचिह्नित आकार;
    संरचना mem_debug_शीर्षकम् *पूर्व;
    संरचना mem_debug_शीर्षकम् *अग्र;
    पूर्णाङ्क पङ्क्तिः_अङ्कः;
    वर्ण file_name[MEM_DEBUG_FILE_LEN];
    अचिह्नित magic2;
    ALIGNED(16) अचिह्नित वर्ण magic3[4];
};

प्रकारनिर्देश संरचना mem_debug_शीर्षकम् mem_debug_शीर्षकम्_t;

TCC_SEM(स्थिर mem_sem);
स्थिर mem_debug_शीर्षकम्_t *mem_debug_chain;
स्थिर अचिह्नित mem_cur_आकार;
स्थिर अचिह्नित mem_max_आकार;
स्थिर पूर्णाङ्क nb_अवस्थाः;

स्थिर mem_debug_शीर्षकम्_t *malloc_check(शून्य *ptr, ध्रुव वर्ण *सन्देशः)
{
    mem_debug_शीर्षकम्_t * शीर्षकम् = MEM_शीर्षकम्_PTR(ptr);
    यदि (शीर्षकम्->magic1 != MEM_DEBUG_MAGIC1 ||
        शीर्षकम्->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(शीर्षकम्)) != MEM_DEBUG_MAGIC3 ||
        शीर्षकम्->आकार == (अचिह्नित)-1) {
        fprintf(stderr, "%s check failed\n", सन्देशः);
        यदि (शीर्षकम्->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                शीर्षकम्->file_name, शीर्षकम्->पङ्क्तिः_अङ्कः);
        निर्गच्छ(1);
    }
    प्रत्यागम शीर्षकम्;
}

PUB_FUNC शून्य *tcc_malloc_debug(अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः)
{
    पूर्णाङ्क ofs;
    mem_debug_शीर्षकम्_t *शीर्षकम्;
    यदि (!आकार)
        प्रत्यागम रिक्त;
    शीर्षकम् = tcc_malloc(परिमाण(mem_debug_शीर्षकम्_t) + आकार);
    शीर्षकम्->magic1 = MEM_DEBUG_MAGIC1;
    शीर्षकम्->magic2 = MEM_DEBUG_MAGIC2;
    शीर्षकम्->आकार = आकार;
    write32le(MEM_DEBUG_CHECK3(शीर्षकम्), MEM_DEBUG_MAGIC3);
    शीर्षकम्->पङ्क्तिः_अङ्कः = पङ्क्तिः;
    ofs = वाक्यदैर्घ्यम्(file) + 1 - MEM_DEBUG_FILE_LEN;
    वाक्यं_प्रतिलिख(शीर्षकम्->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    शीर्षकम्->अग्र = mem_debug_chain;
    शीर्षकम्->पूर्व = रिक्त;
    यदि (शीर्षकम्->अग्र)
        शीर्षकम्->अग्र->पूर्व = शीर्षकम्;
    mem_debug_chain = शीर्षकम्;
    mem_cur_आकार += आकार;
    यदि (mem_cur_आकार > mem_max_आकार)
        mem_max_आकार = mem_cur_आकार;
    POST_SEM(&mem_sem);
    प्रत्यागम MEM_USER_PTR(शीर्षकम्);
}

PUB_FUNC शून्य tcc_free_debug(शून्य *ptr)
{
    mem_debug_शीर्षकम्_t *शीर्षकम्;
    यदि (!ptr)
        प्रत्यागम;
    शीर्षकम् = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_आकार -= शीर्षकम्->आकार;
    शीर्षकम्->आकार = (अचिह्नित)-1;
    यदि (शीर्षकम्->अग्र)
        शीर्षकम्->अग्र->पूर्व = शीर्षकम्->पूर्व;
    यदि (शीर्षकम्->पूर्व)
        शीर्षकम्->पूर्व->अग्र = शीर्षकम्->अग्र;
    यदि (शीर्षकम् == mem_debug_chain)
        mem_debug_chain = शीर्षकम्->अग्र;
    POST_SEM(&mem_sem);
    tcc_free(शीर्षकम्);
}

PUB_FUNC शून्य *tcc_mallocz_debug(अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः)
{
    शून्य *ptr;
    ptr = tcc_malloc_debug(आकार,file,पङ्क्तिः);
    यदि (आकार)
        स्मृतिं_पूरय(ptr, 0, आकार);
    प्रत्यागम ptr;
}

PUB_FUNC शून्य *tcc_realloc_debug(शून्य *ptr, अचिह्नित दीर्घ आकार, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः)
{
    mem_debug_शीर्षकम्_t *शीर्षकम्;
    पूर्णाङ्क mem_debug_chain_update = 0;

    यदि (!ptr)
        प्रत्यागम tcc_malloc_debug(आकार, file, पङ्क्तिः);
    यदि (!आकार) {
        tcc_free_debug(ptr);
        प्रत्यागम रिक्त;
    }
    शीर्षकम् = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_आकार -= शीर्षकम्->आकार;
    mem_debug_chain_update = (शीर्षकम् == mem_debug_chain);
    शीर्षकम् = tcc_realloc(शीर्षकम्, परिमाण(mem_debug_शीर्षकम्_t) + आकार);
    शीर्षकम्->आकार = आकार;
    write32le(MEM_DEBUG_CHECK3(शीर्षकम्), MEM_DEBUG_MAGIC3);
    यदि (शीर्षकम्->अग्र)
        शीर्षकम्->अग्र->पूर्व = शीर्षकम्;
    यदि (शीर्षकम्->पूर्व)
        शीर्षकम्->पूर्व->अग्र = शीर्षकम्;
    यदि (mem_debug_chain_update)
        mem_debug_chain = शीर्षकम्;
    mem_cur_आकार += आकार;
    यदि (mem_cur_आकार > mem_max_आकार)
        mem_max_आकार = mem_cur_आकार;
    POST_SEM(&mem_sem);
    प्रत्यागम MEM_USER_PTR(शीर्षकम्);
}

PUB_FUNC वर्ण *tcc_strdup_debug(ध्रुव वर्ण *str, ध्रुव वर्ण *file, पूर्णाङ्क पङ्क्तिः)
{
    वर्ण *ptr;
    ptr = tcc_malloc_debug(वाक्यदैर्घ्यम्(str) + 1, file, पङ्क्तिः);
    वाक्यं_प्रतिलिख(ptr, str);
    प्रत्यागम ptr;
}

PUB_FUNC शून्य tcc_memcheck(पूर्णाङ्क d)
{
    WAIT_SEM(&mem_sem);
    nb_अवस्थाः += d;
    यदि (0 == nb_अवस्थाः && mem_cur_आकार) {
        mem_debug_शीर्षकम्_t *शीर्षकम् = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_आकार, mem_max_आकार);
        यावत् (शीर्षकम्) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                शीर्षकम्->file_name, शीर्षकम्->पङ्क्तिः_अङ्कः, शीर्षकम्->आकार);
            शीर्षकम् = शीर्षकम्->अग्र;
        }
        fflush(stderr);
        mem_cur_आकार = 0;
        mem_max_आकार = 0;
        mem_debug_chain = रिक्त;
#यदि MEM_DEBUG-0 == 2
        निर्गच्छ(2);
#यदि_अन्तः
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#परिभाषय tcc_free(ptr)           tcc_free_debug(ptr)
#परिभाषय tcc_malloc(आकार)        tcc_malloc_debug(आकार, __FILE__, __LINE__)
#परिभाषय tcc_mallocz(आकार)       tcc_mallocz_debug(आकार, __FILE__, __LINE__)
#परिभाषय tcc_realloc(ptr,आकार)   tcc_realloc_debug(ptr, आकार, __FILE__, __LINE__)
#परिभाषय tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#यदि_अन्तः /* MEM_DEBUG */

#यदि_परिभाषितम् _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#यदि_अन्तः

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

ST_FUNC शून्य dynarray_सङ्कलय(शून्य *ptab, पूर्णाङ्क *nb_ptr, शून्य *दत्त)
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
    pp[nb++] = दत्त;
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

स्थिर शून्य dynarray_विभज(वर्ण ***argv, पूर्णाङ्क *argc, ध्रुव वर्ण *p, पूर्णाङ्क sep)
{
    पूर्णाङ्क qot, c;
    CString str;
    प्रति(;;) {
        यावत् (c = (अचिह्नित वर्ण)*p, c <= ' ' && c != '\0')
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
        } यावत् (c = (अचिह्नित वर्ण)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_सङ्कलय(argv, argc, str.दत्त);
    }
}

स्थिर शून्य tcc_विभज_मार्गः(TCCState *s, शून्य *p_ary, पूर्णाङ्क *p_nb_ary, ध्रुव वर्ण *अन्तर्)
{
    ध्रुव वर्ण *p;
    कुरु {
        पूर्णाङ्क c;
        CString str;

        cstr_new(&str);
        प्रति (p = अन्तर्; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            यदि (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                यदि (c == 'B')
                    cstr_cat(&str, s->tcc_lib_मार्गः, -1);
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
        यदि (str.आकार) {
            cstr_ccat(&str, '\0');
            dynarray_सङ्कलय(p_ary, p_nb_ary, str.दत्त);
        }
        अन्तर् = p+1;
    } यावत् (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#परिभाषय WARN_ON  1 /* warning is on (-Woption) */
#परिभाषय WARN_ERR 2 /* warning is an error (-Werror=option) */
#परिभाषय WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
गणना { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

स्थिर शून्य error1(पूर्णाङ्क बहुलकम्, ध्रुव वर्ण *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    पूर्णाङ्क पङ्क्तिः = 0;

    tcc_exit_state(s1);

    यदि (बहुलकम् == ERROR_WARN) {
        यदि (s1->warn_error)
            बहुलकम् = ERROR_ERROR;
        यदि (s1->warn_अङ्कः) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            पूर्णाङ्क wopt = *(&s1->warn_none + s1->warn_अङ्कः);
            s1->warn_अङ्कः = 0;
            यदि (0 == (wopt & WARN_ON))
                प्रत्यागम;
            यदि (wopt & WARN_ERR)
                बहुलकम् = ERROR_ERROR;
            यदि (wopt & WARN_NOE)
                बहुलकम् = ERROR_WARN;
        }
        यदि (s1->warn_none)
            प्रत्यागम;
    }

    cstr_new(&cs);
    यदि (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        पङ्क्तिः = va_arg(ap, पूर्णाङ्क), fmt += 3;
    f = रिक्त;
    यदि (s1->error_समुच्चयः_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        प्रति (f = file; f && f->filename[0] == ':'; f = f->पूर्व)
            ;
    }
    यदि (f) {
        प्रति(pf = s1->include_राशिः; pf < s1->include_राशिः_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->पङ्क्तिः_अङ्कः - 1);
        यदि (0 == पङ्क्तिः)
            पङ्क्तिः = f->पङ्क्तिः_अङ्कः - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, पङ्क्तिः);
    } अन्यथा यदि (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } अन्यथा {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, बहुलकम् == ERROR_WARN ? "warning: " : "error: ");
    यदि (pp_व्यञ्जकम् > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    अन्यथा
        cstr_vprintf(&cs, fmt, ap);
    यदि (!s1->error_func) {
        /* default case: stderr */
        यदि (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            प्रारूप_लिख("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (वर्ण*)cs.दत्त);
        fflush(stderr); /* print error/warning now (win32) */
    } अन्यथा {
        s1->error_func(s1->error_opaque, (वर्ण*)cs.दत्त);
    }
    cstr_free(&cs);
    यदि (बहुलकम् != ERROR_WARN)
        s1->nb_errors++;
    यदि (बहुलकम् == ERROR_ERROR && s1->error_समुच्चयः_jmp_enabled) {
        यावत् (nb_stk_दत्त)
            tcc_free(*(शून्य**)stk_दत्त[--nb_stk_दत्त]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI शून्य tcc_समुच्चयः_error_func(TCCState *s, शून्य *error_opaque, TCCErrorFunc *error_func)
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

#अपरिभाषय _tcc_error
PUB_FUNC शून्य _tcc_error(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    निर्गच्छ(1);
}
#परिभाषय _tcc_error use_tcc_error_noabort

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
    पूर्णाङ्क buflen = initlen ? initlen : IO_BUF_आकार;

    bf = tcc_mallocz(परिमाण(BufferedFile) + buflen);
    bf->buf_ptr = bf->बफर;
    bf->buf_अन्तः = bf->बफर + initlen;
    bf->buf_अन्तः[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, परिमाण(bf->filename), filename);
#यदि_परिभाषितम् _WIN32
    normalize_slashes(bf->filename);
#यदि_अन्तः
    bf->true_filename = bf->filename;
    bf->पङ्क्तिः_अङ्कः = 1;
    bf->ifdef_राशिः_ptr = s1->ifdef_राशिः_ptr;
    bf->fd = -1;
    bf->पूर्व = file;
    bf->पूर्व_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC शून्य tcc_close(शून्य)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    यदि (bf->fd > 0) {
        close(bf->fd);
        योग_पङ्क्तयः += bf->पङ्क्तिः_अङ्कः - 1;
    }
    यदि (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->पूर्व;
    tok_flags = bf->पूर्व_tok_flags;
    tcc_free(bf);
}

स्थिर पूर्णाङ्क _tcc_open(TCCState *s1, ध्रुव वर्ण *filename)
{
    पूर्णाङ्क fd;
    यदि (वाक्यं_तुलय(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    अन्यथा
        fd = उद्घाटय(filename, O_RDONLY | O_द्विमान_2);
    यदि ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        प्रारूप_लिख("%s %*s%s\n", fd < 0 ? "nf":"->",
               (पूर्णाङ्क)(s1->include_राशिः_ptr - s1->include_राशिः), "", filename);
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
    s1->error_समुच्चयः_jmp_enabled = 1;

    यदि (setjmp(s1->error_jmp_buf) == 0) {

        यदि (fd == -1) {
            पूर्णाङ्क len = वाक्यदैर्घ्यम्(str);
            tcc_open_bf(s1, "<string>", len);
            स्मृतिं_प्रतिलिख(file->बफर, str, len);
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
            tccelf_अन्तः_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_अन्तः(s1);
    s1->error_समुच्चयः_jmp_enabled = 0;
    tcc_exit_state(s1);
    प्रत्यागम s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI पूर्णाङ्क tcc_compile_string(TCCState *s, ध्रुव वर्ण *str)
{
    प्रत्यागम tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI शून्य tcc_define_चिह्नम्(TCCState *s1, ध्रुव वर्ण *sym, ध्रुव वर्ण *मानम्)
{
    ध्रुव वर्ण *eq;
    यदि (रिक्त == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    यदि (रिक्त == मानम्)
        मानम् = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (पूर्णाङ्क)(eq-sym), sym, मानम्);
}

/* undefine a preprocessor symbol */
LIBTCCAPI शून्य tcc_undefine_चिह्नम्(TCCState *s1, ध्रुव वर्ण *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(शून्य)
{
    TCCState *s;

    s = tcc_mallocz(परिमाण(TCCState));
#यदि_परिभाषितम् MEM_DEBUG
    tcc_memcheck(1);
#यदि_अन्तः

#अपरिभाषय gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_अन्तर्_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#यदि_परिभाषितम् CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#यदि_अन्तः
#यदि_परिभाषितम् TCC_TARGET_I386
    s->seg_आकार = 32;
#यदि_अन्तः
    /* enable this if you want symbols with leading underscore on windows: */
#यदि defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#यदि_अन्तः
#यदि_परिभाषितम् TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#यदि_अन्तः
#यदि defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#यदि_अन्तः
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_राशिः_ptr = s->include_राशिः;

    tcc_समुच्चयः_lib_मार्गः(s, CONFIG_TCCDIR);
#यदि_परिभाषितम् CONFIG_TCC_SWITCHES /* predefined options */
    tcc_समुच्चयः_options(s, CONFIG_TCC_SWITCHES);
#यदि_अन्तः
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

    tcc_free(s1->tcc_lib_मार्गः);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_चिह्नम्);
    tcc_free(s1->fini_चिह्नम्);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#यदि defined TCC_TARGET_MACHO
    tcc_free(s1->install_name);
#यदि_अन्तः
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#यदि_परिभाषितम् TCC_IS_NATIVE
    /* free runtime memory */
    tcc_सततम्_free(s1);
#यदि_अन्तः
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#यदि_परिभाषितम् MEM_DEBUG
    tcc_memcheck(-1);
#यदि_अन्तः
}

LIBTCCAPI पूर्णाङ्क tcc_समुच्चयः_output_type(TCCState *s, पूर्णाङ्क output_type)
{
#यदि_परिभाषितम् CONFIG_TCC_PIE
    यदि (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#यदि_अन्तः
    s->output_type = output_type;

    यदि (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_सङ्कलय_sysinclude_मार्गः(s, CONFIG_TCC_SYSINCLUDEPATHS);
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
        tcc_सङ्कलय_library_मार्गः(s, CONFIG_TCC_LIBPATHS);

#यदि_परिभाषितम् TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_सङ्कलय_systemdir(s);
# endif

#नोचेद्यदि defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_सङ्कलय_macos_sdkpath(s);
# endif

#अन्यथा
    /* paths for crt objects */
    tcc_विभज_मार्गः(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    यदि (output_type != TCC_OUTPUT_स्मृतिः && !s->nostdlib)
        tccelf_सङ्कलय_crtbegin(s); /* may produce errors */
#यदि_अन्तः
    प्रत्यागम s->nb_errors ? -1 : 0;
}

LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_include_मार्गः(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_विभज_मार्गः(s, &s->include_paths, &s->nb_include_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_sysinclude_मार्गः(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_विभज_मार्गः(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_library_मार्गः(TCCState *s, ध्रुव वर्ण *pathname)
{
    tcc_विभज_मार्गः(s, &s->library_paths, &s->nb_library_paths, pathname);
    प्रत्यागम 0;
}

LIBTCCAPI शून्य tcc_समुच्चयः_lib_मार्गः(TCCState *s, ध्रुव वर्ण *मार्गः)
{
    tcc_समुच्चयः_str(&s->tcc_lib_मार्गः, मार्गः);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_सङ्कलय_dllref(TCCState *s1, ध्रुव वर्ण *dllname, पूर्णाङ्क level)
{
    DLLReference *ref = रिक्त;
    पूर्णाङ्क i;
    प्रति (i = 0; i < s1->nb_loaded_dlls; i++)
        यदि (0 == वाक्यं_तुलय(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            भङ्ग;
        }
    यदि (level == -1)
        प्रत्यागम ref;
    यदि (ref) {
        यदि (level < ref->level)
            ref->level = level;
        ref->प्राप्तम् = 1;
        प्रत्यागम ref;
    }
    ref = tcc_mallocz(परिमाण(DLLReference) + वाक्यदैर्घ्यम्(dllname));
    वाक्यं_प्रतिलिख(ref->name, dllname);
    dynarray_सङ्कलय(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->सूचकांक = s1->nb_loaded_dlls;
    प्रत्यागम ref;
}

स्थिर पूर्णाङ्क tcc_सङ्कलय_द्विमान(TCCState *s1, पूर्णाङ्क flags, ध्रुव वर्ण *filename, पूर्णाङ्क fd)
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
        ret = tcc_आरोपय_object_file(s1, fd, 0);
        भङ्ग;

    पक्ष AFF_BINTYPE_AR:
        ret = tcc_आरोपय_archive(s1, fd, !(flags & AFF_सम्पूर्णम्_ARCHIVE));
        भङ्ग;

#यदि defined TCC_TARGET_UNIX
    पक्ष AFF_BINTYPE_DYN:
        यदि (s1->output_type == TCC_OUTPUT_स्मृतिः) {
#यदि_परिभाषितम् TCC_IS_NATIVE
            शून्य* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            यदि (dl)
                tcc_सङ्कलय_dllref(s1, filename, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
#यदि_अन्तः
        } अन्यथा
            ret = tcc_आरोपय_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        भङ्ग;

    स्वभाव:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_आरोपय_ldscript(s1, fd);
        भङ्ग;

#नोचेद्यदि defined TCC_TARGET_MACHO
    पक्ष AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        यदि (s1->output_type == TCC_OUTPUT_स्मृतिः) {
#यदि_परिभाषितम् TCC_IS_NATIVE
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
                tcc_सङ्कलय_dllref(s1, soname, 0)->handle = dl;
            अन्यथा
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#यदि_अन्तः
        } अन्यथा यदि (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_आरोपय_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } अन्यथा {
            ret = macho_आरोपय_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        यदि (ret)
            ret = FILE_NOT_RECOGNIZED;
        भङ्ग;

    स्वभाव:
    {
        ध्रुव वर्ण *ext = tcc_fileextension(filename);
        यदि (!वाक्यं_तुलय(ext, ".tbd"))
            गच्छ case_dyn_or_tbd;
        यदि (!वाक्यं_तुलय(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            गच्छ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        भङ्ग;
    }

#नोचेद्यदि defined TCC_TARGET_PE
    स्वभाव:
        यदि (pe_आरोपय_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        भङ्ग;
#यदि_अन्तः

#यदि_परिभाषितम् TCC_TARGET_COFF
    पक्ष AFF_BINTYPE_C67:
        ret = tcc_आरोपय_coff(s1, fd);
        भङ्ग;
#यदि_अन्तः
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
स्थिर पूर्णाङ्क tcc_glob_so(TCCState *s1, ध्रुव वर्ण *आदर्शः, वर्ण *buf, पूर्णाङ्क आकार)
{
    ध्रुव वर्ण *तारकम्;
    glob_t g;
    वर्ण *p;
    पूर्णाङ्क i, v, v1, v2, v3;

    तारकम् = strchr(आदर्शः, '*');
    यदि (!तारकम् || glob(आदर्शः, 0, रिक्त, &g))
        प्रत्यागम -1;
    प्रति (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        यदि (2 != वाक्यात्_पठ(p + (तारकम् - आदर्शः), "%d.%d.%d", &v1, &v2, &v3))
            अनुवर्त;
        यदि ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, आकार, p);
    }
    globfree(&g);
    प्रत्यागम v;
}
#यदि_अन्तः

स्थिर पूर्णाङ्क guess_filetype(ध्रुव वर्ण *filename)
{
    पूर्णाङ्क filetype = 0;
    यदि (1) {
        /* use a file extension to detect a filetype */
        ध्रुव वर्ण *ext = tcc_fileextension(filename);
        यदि (ext[0]) {
            ext++;
            यदि (!वाक्यं_तुलय(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            अन्यथा यदि (!वाक्यं_तुलय(ext, "s"))
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

ST_FUNC पूर्णाङ्क tcc_सङ्कलय_file_आन्तरिकम्(TCCState *s1, ध्रुव वर्ण *filename, पूर्णाङ्क flags)
{
    पूर्णाङ्क fd;

#यदि defined TARGETOS_OpenBSD && !defined _WIN32
    वर्ण buf[1024];
    यदि (tcc_glob_so(s1, filename, buf, परिमाण buf) >= 0)
        filename = buf;
#यदि_अन्तः

    यदि (0 == (flags & AFF_TYPE_आवरणम्))
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
        प्रत्यागम FILE_NOT_प्राप्तम्;
    }

    यदि (flags & AFF_TYPE_BIN)
        प्रत्यागम tcc_सङ्कलय_द्विमान(s1, flags, filename, fd);

    dynarray_सङ्कलय(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    प्रत्यागम tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_file(TCCState *s, ध्रुव वर्ण *filename)
{
    प्रत्यागम tcc_सङ्कलय_file_आन्तरिकम्(s, filename, s->filetype | AFF_PRINT_ERROR);
}

स्थिर पूर्णाङ्क tcc_सङ्कलय_library_आन्तरिकम्(TCCState *s1, ध्रुव वर्ण *fmt,
    ध्रुव वर्ण *filename, पूर्णाङ्क flags, वर्ण **paths, पूर्णाङ्क nb_paths)
{
    वर्ण buf[1024];
    पूर्णाङ्क i, ret;

    प्रति(i = 0; i < nb_paths; i++) {
        snprintf(buf, परिमाण(buf), fmt, paths[i], filename);
        ret = tcc_सङ्कलय_file_आन्तरिकम्(s1, buf, flags & ~AFF_PRINT_ERROR);
        यदि (ret != FILE_NOT_प्राप्तम्)
            प्रत्यागम ret;
    }
    यदि (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    प्रत्यागम FILE_NOT_प्राप्तम्;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_dll(TCCState *s, ध्रुव वर्ण *filename, पूर्णाङ्क flags)
{
    प्रत्यागम tcc_सङ्कलय_library_आन्तरिकम्(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_support(TCCState *s1, ध्रुव वर्ण *filename)
{
    वर्ण buf[100];
    यदि (CONFIG_TCC_CROSSPREFIX[0])
        filename = वाक्यं_योजय(वाक्यं_प्रतिलिख(buf, CONFIG_TCC_CROSSPREFIX), filename);
    प्रत्यागम tcc_सङ्कलय_dll(s1, filename, AFF_PRINT_ERROR);
}

#यदि_परिभाषितम् TCC_TARGET_UNIX
ST_FUNC पूर्णाङ्क tcc_सङ्कलय_crt(TCCState *s1, ध्रुव वर्ण *filename)
{
    प्रत्यागम tcc_सङ्कलय_library_आन्तरिकम्(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#यदि_अन्तः

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI पूर्णाङ्क tcc_सङ्कलय_library(TCCState *s, ध्रुव वर्ण *libraryname)
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
#यदि_अन्तः
        "%s/lib%s.a",
        रिक्त
    };
    पूर्णाङ्क flags = AFF_TYPE_LIB | (s->filetype & AFF_सम्पूर्णम्_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    यदि (*libraryname == ':') {
        libraryname++;
    } अन्यथा {
        ध्रुव वर्ण * ध्रुव *pp = libs;
        यदि (s->static_link)
            pp += परिमाण(libs) / परिमाण(*libs) - 2; /* only "%s/lib%s.a" */
        यावत् (*pp) {
            पूर्णाङ्क ret = tcc_सङ्कलय_library_आन्तरिकम्(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            यदि (ret != FILE_NOT_प्राप्तम्)
                प्रत्यागम ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    प्रत्यागम tcc_सङ्कलय_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC शून्य tcc_सङ्कलय_pragma_libs(TCCState *s1)
{
    पूर्णाङ्क i;
    प्रति (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_सङ्कलय_library(s1, s1->pragma_libs[i]);
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
    पूर्णाङ्क मेलनम्;
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
#यदि_परिभाषितम् TCC_TARGET_PE
        अन्यथा यदि (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#यदि_अन्तः
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
            o->मेलनम् = 1; /* -Wl,-opt -Wl,arg */
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

स्थिर शून्य तर्काः_parser_सङ्कलय_file(TCCState *s, ध्रुव वर्ण* filename, पूर्णाङ्क filetype);

#परिभाषय समुच्चयः_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#परिभाषय समुच्चयः_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
स्थिर पूर्णाङ्क tcc_समुच्चयः_linker(TCCState *s, ध्रुव वर्ण *optarg)
{
    TCCState *s1 = s;

    dynarray_विभज(&s1->link_argv, &s1->link_argc, optarg, ',');

    यावत् (s->link_optind < s->link_argc) {
        वर्ण *अन्तः = रिक्त;
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
            tcc_समुच्चयः_str(&s->elf_entryname, o.arg);
        } अन्यथा यदि (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &अन्तः, 16);
            s->has_text_addr = 1;
        } अन्यथा यदि (link_option(&o, "init=")) {
            tcc_समुच्चयः_str(&s->init_चिह्नम्, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "fini=")) {
            tcc_समुच्चयः_str(&s->fini_चिह्नम्, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "Map=")) {
            tcc_समुच्चयः_str(&s->mapfile, o.arg);
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "oformat=")) {
#यदि defined TCC_TARGET_PE
            यदि (0 == वाक्ये_तुलय("pe-", o.arg, 3))
#नोचेद्यदि PTR_आकार == 8
            यदि (0 == वाक्ये_तुलय("elf64-", o.arg, 6))
#अन्यथा
            यदि (0 == वाक्ये_तुलय("elf32-", o.arg, 6))
#यदि_अन्तः
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            अन्यथा यदि (0==वाक्यं_तुलय("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_द्विमान;
#यदि defined TCC_TARGET_COFF
            अन्यथा यदि (0==वाक्यं_तुलय("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#यदि_अन्तः
            अन्यथा
                गच्छ err;
        } अन्यथा यदि (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } अन्यथा यदि (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } अन्यथा यदि (link_option(&o, "dynamic-linker=|I:")) {
            tcc_समुच्चयः_str(&s->elfint, o.arg);
        } अन्यथा यदि (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } अन्यथा यदि (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &अन्तः, 16);
        } अन्यथा यदि (link_option(&o, "soname=|install_name=")) {
            tcc_समुच्चयः_str(&s->soname, o.arg);
        } अन्यथा यदि (!!(r = link_option(&o, "?whole-archive"))) {
            समुच्चयः_OR_CLEAR(s->filetype, AFF_सम्पूर्णम्_ARCHIVE);
        } अन्यथा यदि (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#यदि_परिभाषितम् TCC_TARGET_PE
        } अन्यथा यदि (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } अन्यथा यदि (!!(r = link_option(&o, "?dynamicbase"))) {
            समुच्चयः_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } अन्यथा यदि (!!(r = link_option(&o, "?high-entropy-va"))) {
            समुच्चयः_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } अन्यथा यदि (!!(r = link_option(&o, "?nxcompat"))) {
            समुच्चयः_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } अन्यथा यदि (!!(r = link_option(&o, "?tsaware"))) {
            समुच्चयः_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } अन्यथा यदि (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &अन्तः, 16);
        } अन्यथा यदि (link_option(&o, "stack=")) {
            s->pe_राशिः_आकार = strtoul(o.arg, &अन्तः, 10);
        } अन्यथा यदि (link_option(&o, "subsystem=")) {
            यदि (pe_setsubsy(s, o.arg) < 0)
                गच्छ err;
#नोचेद्यदि defined TCC_TARGET_MACHO
        } अन्यथा यदि (link_option(&o, "all_load")) {
	    s->filetype |= AFF_सम्पूर्णम्_ARCHIVE;
        } अन्यथा यदि (link_option(&o, "force_load=")) {
            तर्काः_parser_सङ्कलय_file(s, o.arg, AFF_TYPE_LIB | AFF_सम्पूर्णम्_ARCHIVE);
        } अन्यथा यदि (link_option(&o, "single_module")) {
            ignoring = 1;
#यदि_अन्तः
        } अन्यथा यदि (link_option(&o, "as-needed")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "O")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "z=")) {
            ignoring = 1;
        } अन्यथा यदि (link_option(&o, "L:")) {
            tcc_सङ्कलय_library_मार्गः(s, o.arg);
        } अन्यथा यदि (link_option(&o, "l:")) {
            तर्काः_parser_सङ्कलय_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_आवरणम्));
        } अन्यथा यदि (o.मेलनम्) {
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
    uint16_t सूचकांक;
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
    TCC_OPTION_print_अन्वेषणम्_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_सततम्,
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
    TCC_OPTION_compatibility_संस्करणम् ,
    TCC_OPTION_current_संस्करणम्,
};

#परिभाषय TCC_OPTION_HAS_ARG 0x0001
#परिभाषय TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

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
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#यदि_अन्तः
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#यदि_अन्तः
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#यदि_परिभाषितम् TCC_TARGET_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_संस्करणम्, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_संस्करणम्, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#यदि_अन्तः
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
    { "run", TCC_OPTION_सततम्, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#यदि_परिभाषितम् TCC_TARGET_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#यदि_अन्तः
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_अन्वेषणम्_dirs, 0 },
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
#यदि_परिभाषितम् TCC_TARGET_PE
    { "impdef", TCC_OPTION_impdef, 0},
#यदि_अन्तः
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
    uint16_t विस्थापनम्;
    uint16_t flags;
    ध्रुव वर्ण *name;
} FlagDef;

#परिभाषय WD_ALL    0x0001 /* warning is activated when using -Wall */
#परिभाषय FD_INVERT 0x0002 /* invert value before storing */

स्थिर ध्रुव FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_वाक्यानि), 0, "write-strings" },
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
    { offsetof(TCCState, dollars_अन्तर्_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, reverse_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, रिक्त }
};

स्थिर ध्रुव FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#यदि_परिभाषितम् TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#यदि_अन्तः
    { 0, 0, रिक्त }
};

स्थिर पूर्णाङ्क समुच्चयः_flag(TCCState *s, ध्रुव FlagDef *flags, ध्रुव वर्ण *name)
{
    पूर्णाङ्क मानम्, आवरणम्, ret;
    ध्रुव FlagDef *p;
    ध्रुव वर्ण *r;
    अचिह्नित वर्ण *f;

    r = name, मानम् = !strstart("no-", &r), आवरणम् = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    यदि ((flags->flags & WD_ALL) && strstart("error=", &r))
        मानम् = मानम् ? WARN_ON|WARN_ERR : WARN_NOE, आवरणम् = WARN_ON;

    प्रति (ret = -1, p = flags; p->name; ++p) {
        यदि (ret) {
            यदि (वाक्यं_तुलय(r, p->name))
                अनुवर्त;
        } अन्यथा {
            यदि (0 == (p->flags & WD_ALL))
                अनुवर्त;
        }

        f = (अचिह्नित वर्ण *)s + p->विस्थापनम्;
        *f = (*f & आवरणम्) | (मानम् ^ !!(p->flags & FD_INVERT));

        यदि (ret) {
            ret = 0;
            यदि (वाक्यं_तुलय(r, "all"))
                भङ्ग;
        }
    }
    प्रत्यागम ret;
}

स्थिर ध्रुव वर्ण dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#यदि_परिभाषितम् TCC_TARGET_I386
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
#यदि_अन्तः
    "-"
#यदि_परिभाषितम् TCC_TARGET_PE
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
#यदि_अन्तः
;

#यदि defined TCC_TARGET_MACHO
स्थिर uint32_t parse_संस्करणम्(TCCState *s1, ध्रुव वर्ण *संस्करणम्)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    वर्ण* चरमः;

    a = strtoul(संस्करणम्, &चरमः, 10);
    यदि (*चरमः == '.') {
        b = strtoul(&चरमः[1], &चरमः, 10);
        यदि (*चरमः == '.')
             c = strtoul(&चरमः[1], &चरमः, 10);
    }
    यदि (*चरमः || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", संस्करणम्);
    प्रत्यागम (a << 16) | (b << 8) | c;
}
#यदि_अन्तः

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
स्थिर शून्य निवेशय_तर्काः(TCCState *s1, वर्ण ***pargv, पूर्णाङ्क *pargc, पूर्णाङ्क optind, ध्रुव वर्ण *p, पूर्णाङ्क sep)
{
    पूर्णाङ्क argc = 0;
    वर्ण **argv = रिक्त;
    पूर्णाङ्क i;
    प्रति (i = 0; i < *pargc; ++i)
        यदि (i == optind)
            dynarray_विभज(&argv, &argc, p, sep);
        अन्यथा
            dynarray_सङ्कलय(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

स्थिर शून्य तर्काः_parser_सङ्कलय_file(TCCState *s, ध्रुव वर्ण* filename, पूर्णाङ्क filetype)
{
    संरचना filespec *f = tcc_malloc(परिमाण *f + वाक्यदैर्घ्यम्(filename));
    f->type = filetype;
    वाक्यं_प्रतिलिख(f->name, filename);
    dynarray_सङ्कलय(&s->files, &s->nb_files, f);
    यदि (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC पूर्णाङ्क tcc_parse_तर्काः(TCCState *s, पूर्णाङ्क *pargc, वर्ण ***pargv)
{
    TCCState *s1 = s;
    ध्रुव TCCOption *popt;
    ध्रुव वर्ण *optarg, *r;
    ध्रुव वर्ण *सततम् = रिक्त;
    पूर्णाङ्क optind = 1, रिक्तानि = 1, x;
    वर्ण **argv = *pargv;
    पूर्णाङ्क argc = *pargc;

    s->link_optind = s->link_argc;

    यावत् (optind < argc) {
        r = argv[optind];
        यदि (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            पूर्णाङ्क fd; वर्ण *p;
            fd = उद्घाटय(++r, O_RDONLY | O_द्विमान_2);
            यदि (fd < 0)
                प्रत्यागम tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_आरोपय_text(fd);
            निवेशय_तर्काः(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            अनुवर्त;
        }
        optind++;
        यदि (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            तर्काः_parser_सङ्कलय_file(s, r, s->filetype);
            रिक्तानि = 0;
        dorun:
            यदि (सततम्)
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

        विकल्प(popt->सूचकांक) {
        पक्ष TCC_OPTION_I:
            tcc_सङ्कलय_include_मार्गः(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_D:
            tcc_define_चिह्नम्(s, optarg, रिक्त);
            भङ्ग;
        पक्ष TCC_OPTION_U:
            tcc_undefine_चिह्नम्(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_L:
            tcc_सङ्कलय_library_मार्गः(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_समुच्चयः_lib_मार्गः(s, optarg);
            अनुवर्त;
        पक्ष TCC_OPTION_l:
            तर्काः_parser_सङ्कलय_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_आवरणम्));
            भङ्ग;
        पक्ष TCC_OPTION_pthread:
            s->option_pthread = 1;
            भङ्ग;
        पक्ष TCC_OPTION_bench:
            s->do_bench = 1;
            भङ्ग;
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
        पक्ष TCC_OPTION_bt:
            s->rt_अङ्कः_callers = atoi(optarg); /* zero = default (6) */
            गच्छ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            यदि (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_संस्करणम्;
            भङ्ग;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        पक्ष TCC_OPTION_b:
            s->do_bounds_check = 1;
            गच्छ enable_backtrace;
#यदि_अन्तः
#यदि_अन्तः
        पक्ष TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_संस्करणम्;
        g_redo:
            यदि (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_संस्करणम्;
            } अन्यथा यदि (0 == वाक्यं_तुलय("stabs", optarg)) {
                s->dwarf = 0;
            } अन्यथा यदि (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                गच्छ g_redo;
#यदि_परिभाषितम् TCC_TARGET_PE
            } अन्यथा यदि (0 == वाक्यं_तुलय(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#यदि_अन्तः
            }
            भङ्ग;
        पक्ष TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        समुच्चयः_output_type:
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
            यदि (वाक्यं_तुलय(optarg, "=c11") == 0 || वाक्यं_तुलय(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            भङ्ग;
        पक्ष TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            गच्छ समुच्चयः_output_type;
        पक्ष TCC_OPTION_soname:
            tcc_समुच्चयः_str(&s->soname, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_o:
            यदि (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_समुच्चयः_str(&s->outfile, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            गच्छ समुच्चयः_output_type;
        पक्ष TCC_OPTION_isystem:
            tcc_सङ्कलय_sysinclude_मार्गः(s, optarg);
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
        पक्ष TCC_OPTION_सततम्:
#यदि_परिभाषितम् TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            सततम् = optarg;
            x = TCC_OUTPUT_स्मृतिः;
            गच्छ समुच्चयः_output_type;
#अन्यथा
            प्रत्यागम tcc_error_noabort("-run is not available in a cross compiler");
#यदि_अन्तः
#यदि_परिभाषितम् TCC_IS_NATIVE
        पक्ष TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->सततम्_stdin = optarg;
            भङ्ग;
#यदि_अन्तः
        पक्ष TCC_OPTION_v:
            कुरु ++s->verbose; यावत् (*optarg++ == 'v');
            अनुवर्त;
        पक्ष TCC_OPTION_f:
            यदि (समुच्चयः_flag(s, options_f, optarg) < 0)
                गच्छ unsupported_option;
            भङ्ग;
#यदि_परिभाषितम् TCC_TARGET_ARM
        पक्ष TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            यदि (!वाक्यं_तुलय(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } अन्यथा यदि (!वाक्यं_तुलय(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            अन्यथा
                प्रत्यागम tcc_error_noabort("unsupported float abi '%s'", optarg);
            अनुवर्त;
#यदि_अन्तः
        पक्ष TCC_OPTION_m:
            यदि (समुच्चयः_flag(s, options_m, optarg) < 0) {
                यदि (x = atoi(optarg), x != 32 && x != 64)
                    गच्छ unsupported_option;
                यदि (PTR_आकार != x/8)
                    प्रत्यागम x;
                अनुवर्त;
            }
            भङ्ग;
        पक्ष TCC_OPTION_W:
            यदि (optarg[0] && समुच्चयः_flag(s, options_W, optarg) < 0)
                गच्छ unsupported_option;
            भङ्ग;
        पक्ष TCC_OPTION_w:
            s->warn_none = 1;
            भङ्ग;
        पक्ष TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            भङ्ग;
        पक्ष TCC_OPTION_Wl:
            यदि (tcc_समुच्चयः_linker(s, optarg) < 0)
                प्रत्यागम -1;
            भङ्ग;
        पक्ष TCC_OPTION_Wp:
            यदि (argv[0]) /* not with tcc_set_options() */
                निवेशय_तर्काः(s, &argv, &argc, --optind, optarg, ',');
            भङ्ग;
        पक्ष TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            गच्छ समुच्चयः_output_type;
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
                tcc_समुच्चयः_str(&s->deps_outfile, "-");
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
            tcc_समुच्चयः_str(&s->deps_outfile, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            भङ्ग;

        पक्ष TCC_OPTION_dumpmachine:
            प्रारूप_लिख("%s\n", dumpmachine_str);
            निर्गच्छ(0);
        पक्ष TCC_OPTION_dumpversion:
            प्रारूप_लिख ("%s\n", TCC_संस्करणम्);
            निर्गच्छ(0);

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
            s->filetype = x | (s->filetype & ~AFF_TYPE_आवरणम्);
            भङ्ग;
        पक्ष TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            भङ्ग;
#यदि defined TCC_TARGET_MACHO
        पक्ष TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            गच्छ समुच्चयः_output_type;
        पक्ष TCC_OPTION_flat_namespace:
	     भङ्ग;
        पक्ष TCC_OPTION_two_levelnamespace:
	     भङ्ग;
        पक्ष TCC_OPTION_undefined:
	     भङ्ग;
        पक्ष TCC_OPTION_install_name:
	    tcc_समुच्चयः_str(&s->install_name, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_compatibility_संस्करणम्:
	    s->compatibility_संस्करणम् = parse_संस्करणम्(s, optarg);
            भङ्ग;
        पक्ष TCC_OPTION_current_संस्करणम्:
	    s->current_संस्करणम् = parse_संस्करणम्(s, optarg);;
            भङ्ग;
#यदि_अन्तः
        पक्ष TCC_OPTION_HELP:
            x = OPT_HELP;
            गच्छ extra_action;
        पक्ष TCC_OPTION_HELP2:
            x = OPT_HELP2;
            गच्छ extra_action;
        पक्ष TCC_OPTION_print_अन्वेषणम्_dirs:
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
            यदि (!रिक्तानि && x)
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
        रिक्तानि = 0;
    }
    यदि (s->link_optind < s->link_argc)
        प्रत्यागम tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    यदि (सततम्) {
        यदि (*सततम् && tcc_समुच्चयः_options(s, सततम्) < 0)
            प्रत्यागम -1;
        x = 0, r = 0;
        गच्छ extra_action;
    }
    यदि (!रिक्तानि)
        प्रत्यागम 0;
    यदि (s->verbose == 2)
        प्रत्यागम OPT_PRINT_DIRS;
    यदि (s->verbose)
        प्रत्यागम OPT_V;
    प्रत्यागम OPT_HELP;
}

LIBTCCAPI पूर्णाङ्क tcc_समुच्चयः_options(TCCState *s, ध्रुव वर्ण *r)
{
    वर्ण **argv = रिक्त;
    पूर्णाङ्क argc = 0, ret;
    dynarray_सङ्कलय(&argv, &argc, 0);
    dynarray_विभज(&argv, &argc, r, 0);
    ret = tcc_parse_तर्काः(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    प्रत्यागम ret;
}

PUB_FUNC शून्य tcc_print_stats(TCCState *s1, अचिह्नित योग_time)
{
    यदि (!योग_time)
        योग_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           योग_idents, योग_पङ्क्तयः, योग_अष्टकानि,
           (द्विगुण)योग_time/1000,
           (अचिह्नित)योग_पङ्क्तयः*1000/योग_time,
           (द्विगुण)योग_अष्टकानि/1000/योग_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->योग_output[0],
           s1->योग_output[1],
           s1->योग_output[2],
           s1->योग_output[3]
           );
#यदि_परिभाषितम् MEM_DEBUG
    fprintf(stderr, "# memory usage");
#यदि_परिभाषितम् TCC_IS_NATIVE
    यदि (s1->सततम्_आकार) {
        Section *s = s1->symtab;
        अचिह्नित ms = s->दत्त_विस्थापनम् + s->link->दत्त_विस्थापनम् + s->hash->दत्त_विस्थापनम्;
        अचिह्नित rs = s1->सततम्_आकार;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_आकार - rs - ms);
    }
#यदि_अन्तः
    fprintf(stderr, " %d max (bytes)\n", mem_max_आकार);
#यदि_अन्तः
}
