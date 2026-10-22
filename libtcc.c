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

#నిర్వచితం_కాకపోతే ONE_ఆధారం
# define ONE_ఆధారం 1
#అయితే_ముగింపు

#ఒకవేళ ONE_ఆధారం
#అన్తర్భావ "tccpp.c"
#అన్తర్భావ "tccgen.c"
#అన్తర్భావ "tccdbg.c"
#అన్తర్భావ "tccasm.c"
#అన్తర్భావ "tccelf.c"
#అన్తర్భావ "tccrun.c"
#నిర్వచితమైతే TCC_లక్ష్యం_I386
#అన్తర్భావ "i386-gen.c"
#అన్తర్భావ "i386-link.c"
#అన్తర్భావ "i386-asm.c"
#లేదావేళ defined(TCC_లక్ష్యం_ARM)
#అన్తర్భావ "arm-gen.c"
#అన్తర్భావ "arm-link.c"
#అన్తర్భావ "arm-asm.c"
#లేదావేళ defined(TCC_లక్ష్యం_ARM64)
#అన్తర్భావ "arm64-gen.c"
#అన్తర్భావ "arm64-link.c"
#అన్తర్భావ "arm64-asm.c"
#లేదావేళ defined(TCC_లక్ష్యం_C67)
#అన్తర్భావ "c67-gen.c"
#అన్తర్భావ "c67-link.c"
#అన్తర్భావ "tcccoff.c"
#లేదావేళ defined(TCC_లక్ష్యం_X86_64)
#అన్తర్భావ "x86_64-gen.c"
#అన్తర్భావ "x86_64-link.c"
#అన్తర్భావ "i386-asm.c"
#లేదావేళ defined(TCC_లక్ష్యం_RISCV64)
#అన్తర్భావ "riscv64-gen.c"
#అన్తర్భావ "riscv64-link.c"
#అన్తర్భావ "riscv64-asm.c"
#లేకపోతే
#దోషం unknown లక్ష్యం
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_PE
#అన్తర్భావ "tccpe.c"
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_MACHO
#అన్తర్భావ "tccmacho.c"
#అయితే_ముగింపు
#అయితే_ముగింపు /* ONE_SOURCE */

#అన్తర్భావ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_దత్తాంశం నిర్మాణం TCCState *tcc_state;
TCC_SEM(స్థిర tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_దత్తాంశం శూన్య** stk_దత్తాంశం;
ST_దత్తాంశం పూర్ణాంకం nb_stk_దత్తాంశం;
/* option -d<num> (for general development purposes) */
ST_దత్తాంశం పూర్ణాంకం g_debug;

/********************************************************/
#నిర్వచితమైతే _WIN32
ST_FUNC అక్షరం *normalize_slashes(అక్షరం *మార్గం)
{
    అక్షరం *p;
    కొరకు (p = మార్గం; *p; ++p)
        ఒకవేళ (*p == '\\')
            *p = '/';
    తిరిగి మార్గం;
}

#ఒకవేళ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
స్థిర HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ఒకవేళ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    తిరిగి TRUE;
}
#లేకపోతే
#నిర్వచించు tcc_module ఖాళీ /* NULL means executable itself */
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
స్థిర అంతఃవరుస అక్షరం *config_tccdir_w32(అక్షరం *మార్గం)
{
    అక్షరం *p;
    GetModuleFileNameA(tcc_module, మార్గం, MAX_మార్గం);
    p = tcc_basename(normalize_slashes(strlwr(మార్గం)));
    ఒకవేళ (p > మార్గం)
        --p;
    *p = 0;
    తిరిగి మార్గం;
}
#నిర్వచించు CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_మార్గం))
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_IS_NATIVE
స్థిర శూన్య tcc_కూడు_systemdir(TCCState *s)
{
    అక్షరం buf[1000];
    GetSystemDirectoryA(buf, పరిమాణం buf);
    tcc_కూడు_library_మార్గం(s, normalize_slashes(buf));
}
#అయితే_ముగింపు
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(స్థిరరాశి అక్షరం *f, స్థిరరాశి అక్షరం *m) {
    తిరిగి fopen(f, m);
}
PUB_FUNC పూర్ణాంకం tcc_fclose(FILE *f) {
    తిరిగి fclose(f);
}
#అయితే_ముగింపు
/********************************************************/

PUB_FUNC శూన్య tcc_enter_state(TCCState *s1)
{
    ఒకవేళ (s1->error_సమితి_jmp_enabled)
        తిరిగి;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC శూన్య tcc_exit_state(TCCState *s1)
{
    ఒకవేళ (s1->error_సమితి_jmp_enabled)
        తిరిగి;
    tcc_state = ఖాళీ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC అక్షరం *pstrcpy(అక్షరం *buf, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s)
{
    అక్షరం *q, *q_చివర;
    పూర్ణాంకం c;

    ఒకవేళ (buf_కొలత > 0) {
        q = buf;
        q_చివర = buf + buf_కొలత - 1;
        అయితే (q < q_చివర) {
            c = *s++;
            ఒకవేళ (c == '\0')
                ఆపు;
            *q++ = c;
        }
        *q = '\0';
    }
    తిరిగి buf;
}

/* strcat and truncate. */
ST_FUNC అక్షరం *pstrcat(అక్షరం *buf, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s)
{
    కొలత_t len;
    len = అక్షరశ్రేణి_పొడవు(buf);
    ఒకవేళ (len < buf_కొలత)
        pstrcpy(buf + len, buf_కొలత - len, s);
    తిరిగి buf;
}

ST_FUNC అక్షరం *pstrncpy(అక్షరం *బహిర్గతం, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s, కొలత_t అంకె)
{
    ఒకవేళ (అంకె >= buf_కొలత)
        అంకె = buf_కొలత - 1;
    జ్ఞాపకం_నకలు(బహిర్గతం, s, అంకె);
    బహిర్గతం[అంకె] = '\0';
    తిరిగి బహిర్గతం;
}

/* extract the basename of a file */
PUB_FUNC అక్షరం *tcc_basename(స్థిరరాశి అక్షరం *name)
{
    అక్షరం *p = (అక్షరం *)strchr(name, 0);
    అయితే (p > name && !IS_DIRSEP(p[-1]))
        --p;
    తిరిగి p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC అక్షరం *tcc_fileextension (స్థిరరాశి అక్షరం *name)
{
    అక్షరం *b = tcc_basename(name);
    అక్షరం *e = strrchr(b, '.');
    తిరిగి e ? e : strchr(b, 0);
}

ST_FUNC అక్షరం *tcc_ఎక్కించు_పాఠ్యం(పూర్ణాంకం fd)
{
    పూర్ణాంకం len = lseek(fd, 0, SEEK_END);
    అక్షరం *buf = ఎక్కించు_దత్తాంశం(fd, 0, len + 1);
    buf[len] = 0;
    తిరిగి buf;
}

/* replace *pp by copy of 'str' or NULL */
స్థిర శూన్య tcc_సమితి_str(అక్షరం **pp, స్థిరరాశి అక్షరం *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ఖాళీ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
స్థిర శూన్య tcc_concat_str(అక్షరం **pp, స్థిరరాశి అక్షరం *str, పూర్ణాంకం sep)
{
    పూర్ణాంకం l = *pp ? అక్షరశ్రేణి_పొడవు(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + అక్షరశ్రేణి_పొడవు(str) + 1);
    ఒకవేళ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#నిర్వచనం_రద్దు విడుదల
#నిర్వచనం_రద్దు realloc

స్థిర శూన్య *default_reallocator(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత)
{
    శూన్య *ptr1;
    ఒకవేళ (కొలత == 0) {
        విడుదల(ptr);
        ptr1 = ఖాళీ;
    }
    లేకపోతే {
        ptr1 = realloc(ptr, కొలత);
        ఒకవేళ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            నిష్క్రమించు (1);
        }
    }
    తిరిగి ptr1;
}

ST_FUNC శూన్య libc_free(శూన్య *ptr)
{
    విడుదల(ptr);
}

/* defined to be not used */
#నిర్వచించు విడుదల(p) use_tcc_free(p)
#నిర్వచించు realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
స్థిర శూన్య *(*reallocator)(శూన్య*, గుర్తులేని దీర్ఘ) = default_reallocator;

LIBTCCAPI శూన్య tcc_సమితి_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#నిర్వచనం_రద్దు tcc_free
#నిర్వచనం_రద్దు tcc_malloc
#నిర్వచనం_రద్దు tcc_realloc
#నిర్వచనం_రద్దు tcc_mallocz
#నిర్వచనం_రద్దు tcc_strdup

PUB_FUNC శూన్య tcc_free(శూన్య *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC శూన్య *tcc_malloc(గుర్తులేని దీర్ఘ కొలత)
{
    తిరిగి reallocator(0, కొలత);
}

PUB_FUNC శూన్య *tcc_realloc(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత)
{
    తిరిగి reallocator(ptr, కొలత);
}

PUB_FUNC శూన్య *tcc_mallocz(గుర్తులేని దీర్ఘ కొలత)
{
    శూన్య *ptr;
    ptr = tcc_malloc(కొలత);
    ఒకవేళ (కొలత)
        memset(ptr, 0, కొలత);
    తిరిగి ptr;
}

PUB_FUNC అక్షరం *tcc_strdup(స్థిరరాశి అక్షరం *str)
{
    అక్షరం *ptr;
    ptr = tcc_malloc(అక్షరశ్రేణి_పొడవు(str) + 1);
    strcpy(ptr, str);
    తిరిగి ptr;
}

#నిర్వచితమైతే MEM_DEBUG

#నిర్వచించు MEM_DEBUG_MAGIC1 0xFEEDDEB1
#నిర్వచించు MEM_DEBUG_MAGIC2 0xFEEDDEB2
#నిర్వచించు MEM_DEBUG_MAGIC3 0xFEEDDEB3
#నిర్వచించు MEM_DEBUG_FILE_LEN 40
#నిర్వచించు MEM_DEBUG_CHECK3(శీర్షిక) \
    (((గుర్తులేని అక్షరం *) శీర్షిక->magic3) + శీర్షిక->కొలత)
#నిర్వచించు MEM_USER_PTR(శీర్షిక) \
    ((అక్షరం *)శీర్షిక + offsetof(mem_debug_శీర్షిక_t, magic3))
#నిర్వచించు MEM_శీర్షిక_PTR(ptr) \
    (mem_debug_శీర్షిక_t *)((అక్షరం*)ptr - offsetof(mem_debug_శీర్షిక_t, magic3))

నిర్మాణం mem_debug_శీర్షిక {
    గుర్తులేని magic1;
    గుర్తులేని కొలత;
    నిర్మాణం mem_debug_శీర్షిక *prev;
    నిర్మాణం mem_debug_శీర్షిక *తదుపరి;
    పూర్ణాంకం పంక్తి_అంకె;
    అక్షరం file_name[MEM_DEBUG_FILE_LEN];
    గుర్తులేని magic2;
    ALIGNED(16) గుర్తులేని అక్షరం magic3[4];
};

రకనిర్వచనం నిర్మాణం mem_debug_శీర్షిక mem_debug_శీర్షిక_t;

TCC_SEM(స్థిర mem_sem);
స్థిర mem_debug_శీర్షిక_t *mem_debug_chain;
స్థిర గుర్తులేని mem_cur_కొలత;
స్థిర గుర్తులేని mem_max_కొలత;
స్థిర పూర్ణాంకం nb_స్థితులు;

స్థిర mem_debug_శీర్షిక_t *malloc_check(శూన్య *ptr, స్థిరరాశి అక్షరం *సందేశం)
{
    mem_debug_శీర్షిక_t * శీర్షిక = MEM_శీర్షిక_PTR(ptr);
    ఒకవేళ (శీర్షిక->magic1 != MEM_DEBUG_MAGIC1 ||
        శీర్షిక->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(శీర్షిక)) != MEM_DEBUG_MAGIC3 ||
        శీర్షిక->కొలత == (గుర్తులేని)-1) {
        fprintf(stderr, "%s check failed\n", సందేశం);
        ఒకవేళ (శీర్షిక->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                శీర్షిక->file_name, శీర్షిక->పంక్తి_అంకె);
        నిష్క్రమించు(1);
    }
    తిరిగి శీర్షిక;
}

PUB_FUNC శూన్య *tcc_malloc_debug(గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి)
{
    పూర్ణాంకం ofs;
    mem_debug_శీర్షిక_t *శీర్షిక;
    ఒకవేళ (!కొలత)
        తిరిగి ఖాళీ;
    శీర్షిక = tcc_malloc(పరిమాణం(mem_debug_శీర్షిక_t) + కొలత);
    శీర్షిక->magic1 = MEM_DEBUG_MAGIC1;
    శీర్షిక->magic2 = MEM_DEBUG_MAGIC2;
    శీర్షిక->కొలత = కొలత;
    write32le(MEM_DEBUG_CHECK3(శీర్షిక), MEM_DEBUG_MAGIC3);
    శీర్షిక->పంక్తి_అంకె = పంక్తి;
    ofs = అక్షరశ్రేణి_పొడవు(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(శీర్షిక->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    శీర్షిక->తదుపరి = mem_debug_chain;
    శీర్షిక->prev = ఖాళీ;
    ఒకవేళ (శీర్షిక->తదుపరి)
        శీర్షిక->తదుపరి->prev = శీర్షిక;
    mem_debug_chain = శీర్షిక;
    mem_cur_కొలత += కొలత;
    ఒకవేళ (mem_cur_కొలత > mem_max_కొలత)
        mem_max_కొలత = mem_cur_కొలత;
    POST_SEM(&mem_sem);
    తిరిగి MEM_USER_PTR(శీర్షిక);
}

PUB_FUNC శూన్య tcc_free_debug(శూన్య *ptr)
{
    mem_debug_శీర్షిక_t *శీర్షిక;
    ఒకవేళ (!ptr)
        తిరిగి;
    శీర్షిక = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_కొలత -= శీర్షిక->కొలత;
    శీర్షిక->కొలత = (గుర్తులేని)-1;
    ఒకవేళ (శీర్షిక->తదుపరి)
        శీర్షిక->తదుపరి->prev = శీర్షిక->prev;
    ఒకవేళ (శీర్షిక->prev)
        శీర్షిక->prev->తదుపరి = శీర్షిక->తదుపరి;
    ఒకవేళ (శీర్షిక == mem_debug_chain)
        mem_debug_chain = శీర్షిక->తదుపరి;
    POST_SEM(&mem_sem);
    tcc_free(శీర్షిక);
}

PUB_FUNC శూన్య *tcc_mallocz_debug(గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి)
{
    శూన్య *ptr;
    ptr = tcc_malloc_debug(కొలత,file,పంక్తి);
    ఒకవేళ (కొలత)
        memset(ptr, 0, కొలత);
    తిరిగి ptr;
}

PUB_FUNC శూన్య *tcc_realloc_debug(శూన్య *ptr, గుర్తులేని దీర్ఘ కొలత, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి)
{
    mem_debug_శీర్షిక_t *శీర్షిక;
    పూర్ణాంకం mem_debug_chain_update = 0;

    ఒకవేళ (!ptr)
        తిరిగి tcc_malloc_debug(కొలత, file, పంక్తి);
    ఒకవేళ (!కొలత) {
        tcc_free_debug(ptr);
        తిరిగి ఖాళీ;
    }
    శీర్షిక = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_కొలత -= శీర్షిక->కొలత;
    mem_debug_chain_update = (శీర్షిక == mem_debug_chain);
    శీర్షిక = tcc_realloc(శీర్షిక, పరిమాణం(mem_debug_శీర్షిక_t) + కొలత);
    శీర్షిక->కొలత = కొలత;
    write32le(MEM_DEBUG_CHECK3(శీర్షిక), MEM_DEBUG_MAGIC3);
    ఒకవేళ (శీర్షిక->తదుపరి)
        శీర్షిక->తదుపరి->prev = శీర్షిక;
    ఒకవేళ (శీర్షిక->prev)
        శీర్షిక->prev->తదుపరి = శీర్షిక;
    ఒకవేళ (mem_debug_chain_update)
        mem_debug_chain = శీర్షిక;
    mem_cur_కొలత += కొలత;
    ఒకవేళ (mem_cur_కొలత > mem_max_కొలత)
        mem_max_కొలత = mem_cur_కొలత;
    POST_SEM(&mem_sem);
    తిరిగి MEM_USER_PTR(శీర్షిక);
}

PUB_FUNC అక్షరం *tcc_strdup_debug(స్థిరరాశి అక్షరం *str, స్థిరరాశి అక్షరం *file, పూర్ణాంకం పంక్తి)
{
    అక్షరం *ptr;
    ptr = tcc_malloc_debug(అక్షరశ్రేణి_పొడవు(str) + 1, file, పంక్తి);
    strcpy(ptr, str);
    తిరిగి ptr;
}

PUB_FUNC శూన్య tcc_memcheck(పూర్ణాంకం d)
{
    WAIT_SEM(&mem_sem);
    nb_స్థితులు += d;
    ఒకవేళ (0 == nb_స్థితులు && mem_cur_కొలత) {
        mem_debug_శీర్షిక_t *శీర్షిక = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_కొలత, mem_max_కొలత);
        అయితే (శీర్షిక) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                శీర్షిక->file_name, శీర్షిక->పంక్తి_అంకె, శీర్షిక->కొలత);
            శీర్షిక = శీర్షిక->తదుపరి;
        }
        fflush(stderr);
        mem_cur_కొలత = 0;
        mem_max_కొలత = 0;
        mem_debug_chain = ఖాళీ;
#ఒకవేళ MEM_DEBUG-0 == 2
        నిష్క్రమించు(2);
#అయితే_ముగింపు
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#నిర్వచించు tcc_free(ptr)           tcc_free_debug(ptr)
#నిర్వచించు tcc_malloc(కొలత)        tcc_malloc_debug(కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_mallocz(కొలత)       tcc_mallocz_debug(కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_realloc(ptr,కొలత)   tcc_realloc_debug(ptr, కొలత, __FILE__, __LINE__)
#నిర్వచించు tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#అయితే_ముగింపు /* MEM_DEBUG */

#నిర్వచితమైతే _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#అయితే_ముగింపు

/* for #pragma once */
ST_FUNC పూర్ణాంకం normalized_PATHCMP(స్థిరరాశి అక్షరం *f1, స్థిరరాశి అక్షరం *f2)
{
    అక్షరం *p1, *p2;
    పూర్ణాంకం ret = 1;
    ఒకవేళ (!!(p1 = realpath(f1, ఖాళీ))) {
        ఒకవేళ (!!(p2 = realpath(f2, ఖాళీ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    తిరిగి ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC శూన్య dynarray_కూడు(శూన్య *ptab, పూర్ణాంకం *nb_ptr, శూన్య *దత్తాంశం)
{
    పూర్ణాంకం nb, nb_alloc;
    శూన్య **pp;

    nb = *nb_ptr;
    pp = *(శూన్య ***)ptab;
    /* every power of two we double array size */
    ఒకవేళ ((nb & (nb - 1)) == 0) {
        ఒకవేళ (!nb)
            nb_alloc = 1;
        లేకపోతే
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * పరిమాణం(శూన్య *));
        *(శూన్య***)ptab = pp;
    }
    pp[nb++] = దత్తాంశం;
    *nb_ptr = nb;
}

ST_FUNC శూన్య dynarray_reset(శూన్య *pp, పూర్ణాంకం *n)
{
    శూన్య **p;
    కొరకు (p = *(శూన్య***)pp; *n; ++p, --*n)
        ఒకవేళ (*p)
            tcc_free(*p);
    tcc_free(*(శూన్య**)pp);
    *(శూన్య**)pp = ఖాళీ;
}

స్థిర శూన్య dynarray_విభజించు(అక్షరం ***argv, పూర్ణాంకం *argc, స్థిరరాశి అక్షరం *p, పూర్ణాంకం sep)
{
    పూర్ణాంకం qot, c;
    CString str;
    కొరకు(;;) {
        అయితే (c = (గుర్తులేని అక్షరం)*p, c <= ' ' && c != '\0')
            ++p;
        ఒకవేళ (c == '\0')
            ఆపు;
        cstr_new(&str);
        qot = 0;
        చేయి {
            ++p;
            ఒకవేళ (sep) { /* e.g. to split -Wl,-opt,arg */
                ఒకవేళ (c == sep)
                    ఆపు;
            } లేకపోతే {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ఒకవేళ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } లేకపోతే ఒకవేళ (c == '"') {
                    qot ^= 1;
                    కొనసాగు;
                } లేకపోతే ఒకవేళ (c <= ' ' && !qot) {
                    ఆపు;
                }
            }
            cstr_ccat(&str, c);
        } అయితే (c = (గుర్తులేని అక్షరం)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_కూడు(argv, argc, str.దత్తాంశం);
    }
}

స్థిర శూన్య tcc_విభజించు_మార్గం(TCCState *s, శూన్య *p_ary, పూర్ణాంకం *p_nb_ary, స్థిరరాశి అక్షరం *లోపల)
{
    స్థిరరాశి అక్షరం *p;
    చేయి {
        పూర్ణాంకం c;
        CString str;

        cstr_new(&str);
        కొరకు (p = లోపల; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ఒకవేళ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ఒకవేళ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_మార్గం, -1);
                ఒకవేళ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ఒకవేళ (c == 'f' && file) {
                    /* substitute current file's dir */
                    స్థిరరాశి అక్షరం *f = file->true_filename;
                    స్థిరరాశి అక్షరం *b = tcc_basename(f);
                    ఒకవేళ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    లేకపోతే
                        cstr_cat(&str, ".", 1);
                }
            } లేకపోతే {
                cstr_ccat(&str, c);
            }
        }
        ఒకవేళ (str.కొలత) {
            cstr_ccat(&str, '\0');
            dynarray_కూడు(p_ary, p_nb_ary, str.దత్తాంశం);
        }
        లోపల = p+1;
    } అయితే (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#నిర్వచించు WARN_ON  1 /* warning is on (-Woption) */
#నిర్వచించు WARN_ERR 2 /* warning is an error (-Werror=option) */
#నిర్వచించు WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
గణన { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

స్థిర శూన్య error1(పూర్ణాంకం బహుళకం, స్థిరరాశి అక్షరం *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    పూర్ణాంకం పంక్తి = 0;

    tcc_exit_state(s1);

    ఒకవేళ (బహుళకం == ERROR_WARN) {
        ఒకవేళ (s1->warn_error)
            బహుళకం = ERROR_ERROR;
        ఒకవేళ (s1->warn_అంకె) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            పూర్ణాంకం wopt = *(&s1->warn_none + s1->warn_అంకె);
            s1->warn_అంకె = 0;
            ఒకవేళ (0 == (wopt & WARN_ON))
                తిరిగి;
            ఒకవేళ (wopt & WARN_ERR)
                బహుళకం = ERROR_ERROR;
            ఒకవేళ (wopt & WARN_NOE)
                బహుళకం = ERROR_WARN;
        }
        ఒకవేళ (s1->warn_none)
            తిరిగి;
    }

    cstr_new(&cs);
    ఒకవేళ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        పంక్తి = va_arg(ap, పూర్ణాంకం), fmt += 3;
    f = ఖాళీ;
    ఒకవేళ (s1->error_సమితి_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        కొరకు (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ఒకవేళ (f) {
        కొరకు(pf = s1->include_దొంతర; pf < s1->include_దొంతర_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->పంక్తి_అంకె - 1);
        ఒకవేళ (0 == పంక్తి)
            పంక్తి = f->పంక్తి_అంకె - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, పంక్తి);
    } లేకపోతే ఒకవేళ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } లేకపోతే {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, బహుళకం == ERROR_WARN ? "warning: " : "error: ");
    ఒకవేళ (pp_సమాసం > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    లేకపోతే
        cstr_vprintf(&cs, fmt, ap);
    ఒకవేళ (!s1->error_func) {
        /* default case: stderr */
        ఒకవేళ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            రాయి("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (అక్షరం*)cs.దత్తాంశం);
        fflush(stderr); /* print error/warning now (win32) */
    } లేకపోతే {
        s1->error_func(s1->error_opaque, (అక్షరం*)cs.దత్తాంశం);
    }
    cstr_free(&cs);
    ఒకవేళ (బహుళకం != ERROR_WARN)
        s1->nb_errors++;
    ఒకవేళ (బహుళకం == ERROR_ERROR && s1->error_సమితి_jmp_enabled) {
        అయితే (nb_stk_దత్తాంశం)
            tcc_free(*(శూన్య**)stk_దత్తాంశం[--nb_stk_దత్తాంశం]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI శూన్య tcc_సమితి_error_func(TCCState *s, శూన్య *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC పూర్ణాంకం _tcc_error_noabort(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    తిరిగి -1;
}

#నిర్వచనం_రద్దు _tcc_error
PUB_FUNC శూన్య _tcc_error(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    నిష్క్రమించు(1);
}
#నిర్వచించు _tcc_error use_tcc_error_noabort

PUB_FUNC శూన్య _tcc_warning(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC శూన్య tcc_open_bf(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం initlen)
{
    BufferedFile *bf;
    పూర్ణాంకం buflen = initlen ? initlen : IO_BUF_కొలత;

    bf = tcc_mallocz(పరిమాణం(BufferedFile) + buflen);
    bf->buf_ptr = bf->బఫరు;
    bf->buf_చివర = bf->బఫరు + initlen;
    bf->buf_చివర[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, పరిమాణం(bf->filename), filename);
#నిర్వచితమైతే _WIN32
    normalize_slashes(bf->filename);
#అయితే_ముగింపు
    bf->true_filename = bf->filename;
    bf->పంక్తి_అంకె = 1;
    bf->ifdef_దొంతర_ptr = s1->ifdef_దొంతర_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC శూన్య tcc_close(శూన్య)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ఒకవేళ (bf->fd > 0) {
        close(bf->fd);
        మొత్తం_పంక్తులు += bf->పంక్తి_అంకె - 1;
    }
    ఒకవేళ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

స్థిర పూర్ణాంకం _tcc_open(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం fd;
    ఒకవేళ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    లేకపోతే
        fd = open(filename, O_RDONLY | O_ద్విమాన_2);
    ఒకవేళ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        రాయి("%s %*s%s\n", fd < 0 ? "nf":"->",
               (పూర్ణాంకం)(s1->include_దొంతర_ptr - s1->include_దొంతర), "", filename);
    తిరిగి fd;
}

ST_FUNC పూర్ణాంకం tcc_open(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం fd = _tcc_open(s1, filename);
    ఒకవేళ (fd < 0)
        తిరిగి -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    తిరిగి 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
స్థిర పూర్ణాంకం tcc_compile(TCCState *s1, పూర్ణాంకం filetype, స్థిరరాశి అక్షరం *str, పూర్ణాంకం fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_సమితి_jmp_enabled = 1;

    ఒకవేళ (setjmp(s1->error_jmp_buf) == 0) {

        ఒకవేళ (fd == -1) {
            పూర్ణాంకం len = అక్షరశ్రేణి_పొడవు(str);
            tcc_open_bf(s1, "<string>", len);
            జ్ఞాపకం_నకలు(file->బఫరు, str, len);
        } లేకపోతే {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_ప్రారంభం(s1, filetype);
        tccgen_init(s1);

        ఒకవేళ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } లేకపోతే {
            tccelf_begin_file(s1);
            ఒకవేళ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } లేకపోతే {
                tccgen_compile(s1);
            }
            tccelf_చివర_file(s1);
        }
    }
    tccgen_ముగింపు(s1);
    preprocess_చివర(s1);
    s1->error_సమితి_jmp_enabled = 0;
    tcc_exit_state(s1);
    తిరిగి s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI పూర్ణాంకం tcc_compile_string(TCCState *s, స్థిరరాశి అక్షరం *str)
{
    తిరిగి tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI శూన్య tcc_define_చిహ్నం(TCCState *s1, స్థిరరాశి అక్షరం *sym, స్థిరరాశి అక్షరం *విలువ)
{
    స్థిరరాశి అక్షరం *eq;
    ఒకవేళ (ఖాళీ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ఒకవేళ (ఖాళీ == విలువ)
        విలువ = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (పూర్ణాంకం)(eq-sym), sym, విలువ);
}

/* undefine a preprocessor symbol */
LIBTCCAPI శూన్య tcc_undefine_చిహ్నం(TCCState *s1, స్థిరరాశి అక్షరం *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(శూన్య)
{
    TCCState *s;

    s = tcc_mallocz(పరిమాణం(TCCState));
#నిర్వచితమైతే MEM_DEBUG
    tcc_memcheck(1);
#అయితే_ముగింపు

#నిర్వచనం_రద్దు gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_లోపల_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#నిర్వచితమైతే CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_లక్ష్యం_I386
    s->seg_కొలత = 32;
#అయితే_ముగింపు
    /* enable this if you want symbols with leading underscore on windows: */
#ఒకవేళ defined TCC_లక్ష్యం_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#అయితే_ముగింపు
#ఒకవేళ defined TCC_లక్ష్యం_ARM64 && defined TCC_లక్ష్యం_PE
    s->pe_dll_characteristics = 0x8160;
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#అయితే_ముగింపు
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_దొంతర_ptr = s->include_దొంతర;

    tcc_సమితి_lib_మార్గం(s, CONFIG_TCCDIR);
#నిర్వచితమైతే CONFIG_TCC_SWITCHES /* predefined options */
    tcc_సమితి_options(s, CONFIG_TCC_SWITCHES);
#అయితే_ముగింపు
    తిరిగి s;
}

LIBTCCAPI శూన్య tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_మార్గం);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_చిహ్నం);
    tcc_free(s1->fini_చిహ్నం);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ఒకవేళ defined TCC_లక్ష్యం_MACHO
    tcc_free(s1->install_name);
#అయితే_ముగింపు
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->లక్ష్యం_deps, &s1->nb_లక్ష్యం_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#నిర్వచితమైతే TCC_IS_NATIVE
    /* free runtime memory */
    tcc_నిరంతరం_free(s1);
#అయితే_ముగింపు
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#నిర్వచితమైతే MEM_DEBUG
    tcc_memcheck(-1);
#అయితే_ముగింపు
}

LIBTCCAPI పూర్ణాంకం tcc_సమితి_output_type(TCCState *s, పూర్ణాంకం output_type)
{
#నిర్వచితమైతే CONFIG_TCC_PIE
    ఒకవేళ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#అయితే_ముగింపు
    s->output_type = output_type;

    ఒకవేళ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_కూడు_sysinclude_మార్గం(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ఒకవేళ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        తిరిగి 0;
    }

    /* add sections */
    tccelf_new(s);

    ఒకవేళ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        తిరిగి 0;
    }

    ఒకవేళ (!s->nostdlib_paths)
        tcc_కూడు_library_మార్గం(s, CONFIG_TCC_LIBPATHS);

#నిర్వచితమైతే TCC_లక్ష్యం_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_కూడు_systemdir(s);
# endif

#లేదావేళ defined TCC_లక్ష్యం_MACHO
# ifdef TCC_IS_NATIVE
    tcc_కూడు_macos_sdkpath(s);
# endif

#లేకపోతే
    /* paths for crt objects */
    tcc_విభజించు_మార్గం(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ఒకవేళ (output_type != TCC_OUTPUT_జ్ఞాపకం && !s->nostdlib)
        tccelf_కూడు_crtbegin(s); /* may produce errors */
#అయితే_ముగింపు
    తిరిగి s->nb_errors ? -1 : 0;
}

LIBTCCAPI పూర్ణాంకం tcc_కూడు_include_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname)
{
    tcc_విభజించు_మార్గం(s, &s->include_paths, &s->nb_include_paths, pathname);
    తిరిగి 0;
}

LIBTCCAPI పూర్ణాంకం tcc_కూడు_sysinclude_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname)
{
    tcc_విభజించు_మార్గం(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    తిరిగి 0;
}

LIBTCCAPI పూర్ణాంకం tcc_కూడు_library_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *pathname)
{
    tcc_విభజించు_మార్గం(s, &s->library_paths, &s->nb_library_paths, pathname);
    తిరిగి 0;
}

LIBTCCAPI శూన్య tcc_సమితి_lib_మార్గం(TCCState *s, స్థిరరాశి అక్షరం *మార్గం)
{
    tcc_సమితి_str(&s->tcc_lib_మార్గం, మార్గం);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_కూడు_dllref(TCCState *s1, స్థిరరాశి అక్షరం *dllname, పూర్ణాంకం level)
{
    DLLReference *ref = ఖాళీ;
    పూర్ణాంకం i;
    కొరకు (i = 0; i < s1->nb_loaded_dlls; i++)
        ఒకవేళ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ఆపు;
        }
    ఒకవేళ (level == -1)
        తిరిగి ref;
    ఒకవేళ (ref) {
        ఒకవేళ (level < ref->level)
            ref->level = level;
        ref->దొరికింది = 1;
        తిరిగి ref;
    }
    ref = tcc_mallocz(పరిమాణం(DLLReference) + అక్షరశ్రేణి_పొడవు(dllname));
    strcpy(ref->name, dllname);
    dynarray_కూడు(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->సూచీ = s1->nb_loaded_dlls;
    తిరిగి ref;
}

స్థిర పూర్ణాంకం tcc_కూడు_ద్విమాన(TCCState *s1, పూర్ణాంకం flags, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం fd)
{
    ElfW(Ehdr) ehdr;
    పూర్ణాంకం obj_type;
    స్థిరరాశి అక్షరం *saved_filename = s1->current_filename;
    పూర్ణాంకం ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    ఎంపిక (obj_type) {

    స్థితి AFF_BINTYPE_REL:
        ret = tcc_ఎక్కించు_object_file(s1, fd, 0);
        ఆపు;

    స్థితి AFF_BINTYPE_AR:
        ret = tcc_ఎక్కించు_archive(s1, fd, !(flags & AFF_సంపూర్ణ_ARCHIVE));
        ఆపు;

#ఒకవేళ defined TCC_లక్ష్యం_UNIX
    స్థితి AFF_BINTYPE_DYN:
        ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం) {
#నిర్వచితమైతే TCC_IS_NATIVE
            శూన్య* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ఒకవేళ (dl)
                tcc_కూడు_dllref(s1, filename, 0)->handle = dl;
            లేకపోతే
                ret = FILE_NOT_RECOGNIZED;
#అయితే_ముగింపు
        } లేకపోతే
            ret = tcc_ఎక్కించు_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ఆపు;

    అప్రమేయ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_ఎక్కించు_ldscript(s1, fd);
        ఆపు;

#లేదావేళ defined TCC_లక్ష్యం_MACHO
    స్థితి AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ఒకవేళ (s1->output_type == TCC_OUTPUT_జ్ఞాపకం) {
#నిర్వచితమైతే TCC_IS_NATIVE
            శూన్య* dl;
            స్థిరరాశి అక్షరం* soname = filename;
            అక్షరం *tmp = 0;
            ఒకవేళ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ఒకవేళ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ఒకవేళ (dl)
                tcc_కూడు_dllref(s1, soname, 0)->handle = dl;
            లేకపోతే
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#అయితే_ముగింపు
        } లేకపోతే ఒకవేళ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_ఎక్కించు_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } లేకపోతే {
            ret = macho_ఎక్కించు_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ఒకవేళ (ret)
            ret = FILE_NOT_RECOGNIZED;
        ఆపు;

    అప్రమేయ:
    {
        స్థిరరాశి అక్షరం *ext = tcc_fileextension(filename);
        ఒకవేళ (!strcmp(ext, ".tbd"))
            వెళ్ళు case_dyn_or_tbd;
        ఒకవేళ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            వెళ్ళు case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ఆపు;
    }

#లేదావేళ defined TCC_లక్ష్యం_PE
    అప్రమేయ:
        ఒకవేళ (pe_ఎక్కించు_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ఆపు;
#అయితే_ముగింపు

#నిర్వచితమైతే TCC_లక్ష్యం_COFF
    స్థితి AFF_BINTYPE_C67:
        ret = tcc_ఎక్కించు_coff(s1, fd);
        ఆపు;
#అయితే_ముగింపు
    }

    close(fd);
    s1->current_filename = saved_filename;
    ఒకవేళ (ret == FILE_NOT_RECOGNIZED)
        తిరిగి tcc_error_noabort("%s: unrecognized file type", filename);
    తిరిగి ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ఒకవేళ defined TARGETOS_OpenBSD && !defined _WIN32
#అన్తర్భావ <glob.h>
స్థిర పూర్ణాంకం tcc_glob_so(TCCState *s1, స్థిరరాశి అక్షరం *నమూనా, అక్షరం *buf, పూర్ణాంకం కొలత)
{
    స్థిరరాశి అక్షరం *నక్షత్రం;
    glob_t g;
    అక్షరం *p;
    పూర్ణాంకం i, v, v1, v2, v3;

    నక్షత్రం = strchr(నమూనా, '*');
    ఒకవేళ (!నక్షత్రం || glob(నమూనా, 0, ఖాళీ, &g))
        తిరిగి -1;
    కొరకు (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ఒకవేళ (2 != అక్షరశ్రేణి_చదువు(p + (నక్షత్రం - నమూనా), "%d.%d.%d", &v1, &v2, &v3))
            కొనసాగు;
        ఒకవేళ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, కొలత, p);
    }
    globfree(&g);
    తిరిగి v;
}
#అయితే_ముగింపు

స్థిర పూర్ణాంకం guess_filetype(స్థిరరాశి అక్షరం *filename)
{
    పూర్ణాంకం filetype = 0;
    ఒకవేళ (1) {
        /* use a file extension to detect a filetype */
        స్థిరరాశి అక్షరం *ext = tcc_fileextension(filename);
        ఒకవేళ (ext[0]) {
            ext++;
            ఒకవేళ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            లేకపోతే ఒకవేళ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            లేకపోతే ఒకవేళ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            లేకపోతే
                filetype |= AFF_TYPE_BIN;
        } లేకపోతే {
            filetype = AFF_TYPE_C;
        }
    }
    తిరిగి filetype;
}

ST_FUNC పూర్ణాంకం tcc_కూడు_file_అంతర్గత(TCCState *s1, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flags)
{
    పూర్ణాంకం fd;

#ఒకవేళ defined TARGETOS_OpenBSD && !defined _WIN32
    అక్షరం buf[1024];
    ఒకవేళ (tcc_glob_so(s1, filename, buf, పరిమాణం buf) >= 0)
        filename = buf;
#అయితే_ముగింపు

    ఒకవేళ (0 == (flags & AFF_TYPE_ముసుగు))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ఒకవేళ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        తిరిగి 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ఒకవేళ (fd < 0) {
        ఒకవేళ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        తిరిగి FILE_NOT_దొరికింది;
    }

    ఒకవేళ (flags & AFF_TYPE_BIN)
        తిరిగి tcc_కూడు_ద్విమాన(s1, flags, filename, fd);

    dynarray_కూడు(&s1->లక్ష్యం_deps, &s1->nb_లక్ష్యం_deps, tcc_strdup(filename));
    తిరిగి tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI పూర్ణాంకం tcc_కూడు_file(TCCState *s, స్థిరరాశి అక్షరం *filename)
{
    తిరిగి tcc_కూడు_file_అంతర్గత(s, filename, s->filetype | AFF_PRINT_ERROR);
}

స్థిర పూర్ణాంకం tcc_కూడు_library_అంతర్గత(TCCState *s1, స్థిరరాశి అక్షరం *fmt,
    స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flags, అక్షరం **paths, పూర్ణాంకం nb_paths)
{
    అక్షరం buf[1024];
    పూర్ణాంకం i, ret;

    కొరకు(i = 0; i < nb_paths; i++) {
        snprintf(buf, పరిమాణం(buf), fmt, paths[i], filename);
        ret = tcc_కూడు_file_అంతర్గత(s1, buf, flags & ~AFF_PRINT_ERROR);
        ఒకవేళ (ret != FILE_NOT_దొరికింది)
            తిరిగి ret;
    }
    ఒకవేళ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    తిరిగి FILE_NOT_దొరికింది;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC పూర్ణాంకం tcc_కూడు_dll(TCCState *s, స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flags)
{
    తిరిగి tcc_కూడు_library_అంతర్గత(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC పూర్ణాంకం tcc_కూడు_support(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    అక్షరం buf[100];
    ఒకవేళ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    తిరిగి tcc_కూడు_dll(s1, filename, AFF_PRINT_ERROR);
}

#నిర్వచితమైతే TCC_లక్ష్యం_UNIX
ST_FUNC పూర్ణాంకం tcc_కూడు_crt(TCCState *s1, స్థిరరాశి అక్షరం *filename)
{
    తిరిగి tcc_కూడు_library_అంతర్గత(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#అయితే_ముగింపు

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI పూర్ణాంకం tcc_కూడు_library(TCCState *s, స్థిరరాశి అక్షరం *libraryname)
{
    స్థిర స్థిరరాశి అక్షరం * స్థిరరాశి libs[] = {
#ఒకవేళ defined TCC_లక్ష్యం_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#లేదావేళ defined TCC_లక్ష్యం_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#లేదావేళ defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#లేకపోతే
        "%s/lib%s.so",
#అయితే_ముగింపు
        "%s/lib%s.a",
        ఖాళీ
    };
    పూర్ణాంకం flags = AFF_TYPE_LIB | (s->filetype & AFF_సంపూర్ణ_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ఒకవేళ (*libraryname == ':') {
        libraryname++;
    } లేకపోతే {
        స్థిరరాశి అక్షరం * స్థిరరాశి *pp = libs;
        ఒకవేళ (s->static_link)
            pp += పరిమాణం(libs) / పరిమాణం(*libs) - 2; /* only "%s/lib%s.a" */
        అయితే (*pp) {
            పూర్ణాంకం ret = tcc_కూడు_library_అంతర్గత(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ఒకవేళ (ret != FILE_NOT_దొరికింది)
                తిరిగి ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    తిరిగి tcc_కూడు_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC శూన్య tcc_కూడు_pragma_libs(TCCState *s1)
{
    పూర్ణాంకం i;
    కొరకు (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_కూడు_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

స్థిర పూర్ణాంకం strstart(స్థిరరాశి అక్షరం *val, స్థిరరాశి అక్షరం **str)
{
    స్థిరరాశి అక్షరం *p, *q;
    p = *str;
    q = val;
    అయితే (*q) {
        ఒకవేళ (*p != *q)
            తిరిగి 0;
        p++;
        q++;
    }
    *str = p;
    తిరిగి 1;
}

నిర్మాణం lopt {
    TCCState *s;
    స్థిరరాశి అక్షరం *opt, *arg;
    పూర్ణాంకం సరిపోలిక;
};

/* match linker option */
స్థిర పూర్ణాంకం link_option(నిర్మాణం lopt *o, స్థిరరాశి అక్షరం *q)
{
    స్థిరరాశి అక్షరం *p;
    పూర్ణాంకం c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ఒకవేళ (*p++ != '-')
        తిరిగి 0;
    ఒకవేళ (*p == '-')
        p++;
    r = 1;
    ఒకవేళ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ఒకవేళ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        లేకపోతే ఒకవేళ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#అయితే_ముగింపు
    }
    అయితే ((c = *q) == *p) {
        ఒకవేళ (c == '\0')
            వెళ్ళు succ; /* -Wl,-opt */
        ++p;
        ఒకవేళ (c == '=')
            వెళ్ళు succ; /* -Wl,-opt=arg */
        ++q;
    }
    ఒకవేళ (*p == '\0') {
        ఒకవేళ (c == '|')
            వెళ్ళు succ;
        ఒకవేళ (c == '=' || c == ':') {
            ఒకవేళ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                వెళ్ళు succ; /* -Wl,-opt,arg */
            }
            o->సరిపోలిక = 1; /* -Wl,-opt -Wl,arg */
            తిరిగి 0;
        }
    } లేకపోతే ఒకవేళ (c == ':')
        వెళ్ళు succ; /* -Wl,-Iarg */
    అయితే (*q)
        ఒకవేళ (*q++ == '|')
            వెళ్ళు redo;
    తిరిగి 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    తిరిగి r;
}

స్థిర శూన్య వాదనలు_parser_కూడు_file(TCCState *s, స్థిరరాశి అక్షరం* filename, పూర్ణాంకం filetype);

#నిర్వచించు సమితి_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#నిర్వచించు సమితి_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
స్థిర పూర్ణాంకం tcc_సమితి_linker(TCCState *s, స్థిరరాశి అక్షరం *optarg)
{
    TCCState *s1 = s;

    dynarray_విభజించు(&s1->link_argv, &s1->link_argc, optarg, ',');

    అయితే (s->link_optind < s->link_argc) {
        అక్షరం *చివర = ఖాళీ;
        పూర్ణాంకం ignoring = 0;
        నిర్మాణం lopt o = {0};
        పూర్ణాంకం r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ఒకవేళ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "e=|entry=")) {
            tcc_సమితి_str(&s->elf_entryname, o.arg);
        } లేకపోతే ఒకవేళ (link_option(&o, "image-base=|Ttext=")) {
            s->పాఠ్యం_addr = strtoull(o.arg, &చివర, 16);
            s->has_పాఠ్యం_addr = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "init=")) {
            tcc_సమితి_str(&s->init_చిహ్నం, o.arg);
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "fini=")) {
            tcc_సమితి_str(&s->fini_చిహ్నం, o.arg);
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "Map=")) {
            tcc_సమితి_str(&s->mapfile, o.arg);
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "oformat=")) {
#ఒకవేళ defined TCC_లక్ష్యం_PE
            ఒకవేళ (0 == అక్షరశ్రేణి_పోలిక("pe-", o.arg, 3))
#లేదావేళ PTR_కొలత == 8
            ఒకవేళ (0 == అక్షరశ్రేణి_పోలిక("elf64-", o.arg, 6))
#లేకపోతే
            ఒకవేళ (0 == అక్షరశ్రేణి_పోలిక("elf32-", o.arg, 6))
#అయితే_ముగింపు
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            లేకపోతే ఒకవేళ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ద్విమాన;
#ఒకవేళ defined TCC_లక్ష్యం_COFF
            లేకపోతే ఒకవేళ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#అయితే_ముగింపు
            లేకపోతే
                వెళ్ళు err;
        } లేకపోతే ఒకవేళ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } లేకపోతే ఒకవేళ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_సమితి_str(&s->elfint, o.arg);
        } లేకపోతే ఒకవేళ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &చివర, 16);
        } లేకపోతే ఒకవేళ (link_option(&o, "soname=|install_name=")) {
            tcc_సమితి_str(&s->soname, o.arg);
        } లేకపోతే ఒకవేళ (!!(r = link_option(&o, "?whole-archive"))) {
            సమితి_OR_CLEAR(s->filetype, AFF_సంపూర్ణ_ARCHIVE);
        } లేకపోతే ఒకవేళ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        } లేకపోతే ఒకవేళ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } లేకపోతే ఒకవేళ (!!(r = link_option(&o, "?dynamicbase"))) {
            సమితి_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } లేకపోతే ఒకవేళ (!!(r = link_option(&o, "?high-entropy-va"))) {
            సమితి_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } లేకపోతే ఒకవేళ (!!(r = link_option(&o, "?nxcompat"))) {
            సమితి_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } లేకపోతే ఒకవేళ (!!(r = link_option(&o, "?tsaware"))) {
            సమితి_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } లేకపోతే ఒకవేళ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &చివర, 16);
        } లేకపోతే ఒకవేళ (link_option(&o, "stack=")) {
            s->pe_దొంతర_కొలత = strtoul(o.arg, &చివర, 10);
        } లేకపోతే ఒకవేళ (link_option(&o, "subsystem=")) {
            ఒకవేళ (pe_setsubsy(s, o.arg) < 0)
                వెళ్ళు err;
#లేదావేళ defined TCC_లక్ష్యం_MACHO
        } లేకపోతే ఒకవేళ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_సంపూర్ణ_ARCHIVE;
        } లేకపోతే ఒకవేళ (link_option(&o, "force_load=")) {
            వాదనలు_parser_కూడు_file(s, o.arg, AFF_TYPE_LIB | AFF_సంపూర్ణ_ARCHIVE);
        } లేకపోతే ఒకవేళ (link_option(&o, "single_module")) {
            ignoring = 1;
#అయితే_ముగింపు
        } లేకపోతే ఒకవేళ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "O")) {
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "z=")) {
            ignoring = 1;
        } లేకపోతే ఒకవేళ (link_option(&o, "L:")) {
            tcc_కూడు_library_మార్గం(s, o.arg);
        } లేకపోతే ఒకవేళ (link_option(&o, "l:")) {
            వాదనలు_parser_కూడు_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ముసుగు));
        } లేకపోతే ఒకవేళ (o.సరిపోలిక) {
            తిరిగి 0; /* expecting argument with next '-Wl,' */
        } లేకపోతే {
    err:
            తిరిగి tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ఒకవేళ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    తిరిగి 0;
}

రకనిర్వచనం నిర్మాణం TCCOption {
    స్థిరరాశి అక్షరం *name;
    uint16_t సూచీ;
    uint16_t flags;
} TCCOption;

గణన {
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
    TCC_OPTION_print_శోధన_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_నిరంతరం,
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
    TCC_OPTION_compatibility_సంస్కరణ ,
    TCC_OPTION_current_సంస్కరణ,
};

#నిర్వచించు TCC_OPTION_HAS_ARG 0x0001
#నిర్వచించు TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

స్థిర స్థిరరాశి TCCOption tcc_options[] = {
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
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#అయితే_ముగింపు
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#అయితే_ముగింపు
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#నిర్వచితమైతే TCC_లక్ష్యం_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_సంస్కరణ, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_సంస్కరణ, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#అయితే_ముగింపు
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
    { "run", TCC_OPTION_నిరంతరం, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#అయితే_ముగింపు
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_శోధన_dirs, 0 },
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
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    { "impdef", TCC_OPTION_impdef, 0},
#అయితే_ముగింపు
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
    { ఖాళీ, 0, 0 },
};

రకనిర్వచనం నిర్మాణం FlagDef {
    uint16_t స్థానభ్రంశం;
    uint16_t flags;
    స్థిరరాశి అక్షరం *name;
} FlagDef;

#నిర్వచించు WD_ALL    0x0001 /* warning is activated when using -Wall */
#నిర్వచించు FD_INVERT 0x0002 /* invert value before storing */

స్థిర స్థిరరాశి FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_అక్షరశ్రేణులు), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ఖాళీ }
};

స్థిర స్థిరరాశి FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_లోపల_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, తిరగేయి_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, ఖాళీ }
};

స్థిర స్థిరరాశి FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#నిర్వచితమైతే TCC_లక్ష్యం_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#అయితే_ముగింపు
    { 0, 0, ఖాళీ }
};

స్థిర పూర్ణాంకం సమితి_flag(TCCState *s, స్థిరరాశి FlagDef *flags, స్థిరరాశి అక్షరం *name)
{
    పూర్ణాంకం విలువ, ముసుగు, ret;
    స్థిరరాశి FlagDef *p;
    స్థిరరాశి అక్షరం *r;
    గుర్తులేని అక్షరం *f;

    r = name, విలువ = !strstart("no-", &r), ముసుగు = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ఒకవేళ ((flags->flags & WD_ALL) && strstart("error=", &r))
        విలువ = విలువ ? WARN_ON|WARN_ERR : WARN_NOE, ముసుగు = WARN_ON;

    కొరకు (ret = -1, p = flags; p->name; ++p) {
        ఒకవేళ (ret) {
            ఒకవేళ (strcmp(r, p->name))
                కొనసాగు;
        } లేకపోతే {
            ఒకవేళ (0 == (p->flags & WD_ALL))
                కొనసాగు;
        }

        f = (గుర్తులేని అక్షరం *)s + p->స్థానభ్రంశం;
        *f = (*f & ముసుగు) | (విలువ ^ !!(p->flags & FD_INVERT));

        ఒకవేళ (ret) {
            ret = 0;
            ఒకవేళ (strcmp(r, "all"))
                ఆపు;
        }
    }
    తిరిగి ret;
}

స్థిర స్థిరరాశి అక్షరం dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#నిర్వచితమైతే TCC_లక్ష్యం_I386
    "i386-pc"
#లేదావేళ defined TCC_లక్ష్యం_X86_64
    "x86_64-pc"
#లేదావేళ defined TCC_లక్ష్యం_C67
    "c67"
#లేదావేళ defined TCC_లక్ష్యం_ARM
    "arm"
#లేదావేళ defined TCC_లక్ష్యం_ARM64
    "aarch64"
#లేదావేళ defined TCC_లక్ష్యం_RISCV64
    "riscv64"
#అయితే_ముగింపు
    "-"
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    "mingw32"
#లేదావేళ defined(TCC_లక్ష్యం_MACHO)
    "apple-darwin"
#లేదావేళ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#లేదావేళ TARGETOS_OpenBSD
    "openbsd"
#లేదావేళ TARGETOS_NetBSD
    "netbsd"
#లేదావేళ CONFIG_TCC_MUSL
    "linux-musl"
#లేకపోతే
    "linux-gnu"
#అయితే_ముగింపు
;

#ఒకవేళ defined TCC_లక్ష్యం_MACHO
స్థిర uint32_t parse_సంస్కరణ(TCCState *s1, స్థిరరాశి అక్షరం *సంస్కరణ)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    అక్షరం* చివరి;

    a = strtoul(సంస్కరణ, &చివరి, 10);
    ఒకవేళ (*చివరి == '.') {
        b = strtoul(&చివరి[1], &చివరి, 10);
        ఒకవేళ (*చివరి == '.')
             c = strtoul(&చివరి[1], &చివరి, 10);
    }
    ఒకవేళ (*చివరి || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", సంస్కరణ);
    తిరిగి (a << 16) | (b << 8) | c;
}
#అయితే_ముగింపు

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
స్థిర శూన్య చొప్పించు_వాదనలు(TCCState *s1, అక్షరం ***pargv, పూర్ణాంకం *pargc, పూర్ణాంకం optind, స్థిరరాశి అక్షరం *p, పూర్ణాంకం sep)
{
    పూర్ణాంకం argc = 0;
    అక్షరం **argv = ఖాళీ;
    పూర్ణాంకం i;
    కొరకు (i = 0; i < *pargc; ++i)
        ఒకవేళ (i == optind)
            dynarray_విభజించు(&argv, &argc, p, sep);
        లేకపోతే
            dynarray_కూడు(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

స్థిర శూన్య వాదనలు_parser_కూడు_file(TCCState *s, స్థిరరాశి అక్షరం* filename, పూర్ణాంకం filetype)
{
    నిర్మాణం filespec *f = tcc_malloc(పరిమాణం *f + అక్షరశ్రేణి_పొడవు(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_కూడు(&s->files, &s->nb_files, f);
    ఒకవేళ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC పూర్ణాంకం tcc_parse_వాదనలు(TCCState *s, పూర్ణాంకం *pargc, అక్షరం ***pargv)
{
    TCCState *s1 = s;
    స్థిరరాశి TCCOption *popt;
    స్థిరరాశి అక్షరం *optarg, *r;
    స్థిరరాశి అక్షరం *నిరంతరం = ఖాళీ;
    పూర్ణాంకం optind = 1, ఖాళీలు = 1, x;
    అక్షరం **argv = *pargv;
    పూర్ణాంకం argc = *pargc;

    s->link_optind = s->link_argc;

    అయితే (optind < argc) {
        r = argv[optind];
        ఒకవేళ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            పూర్ణాంకం fd; అక్షరం *p;
            fd = open(++r, O_RDONLY | O_ద్విమాన_2);
            ఒకవేళ (fd < 0)
                తిరిగి tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_ఎక్కించు_పాఠ్యం(fd);
            చొప్పించు_వాదనలు(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            కొనసాగు;
        }
        optind++;
        ఒకవేళ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            వాదనలు_parser_కూడు_file(s, r, s->filetype);
            ఖాళీలు = 0;
        dorun:
            ఒకవేళ (నిరంతరం)
                ఆపు;
            కొనసాగు;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ఒకవేళ (r[1] == '-' && r[2] == '\0')
            వెళ్ళు dorun;

        /* find option in table */
        కొరకు(popt = tcc_options; ; ++popt) {
            స్థిరరాశి అక్షరం *p1 = popt->name;
            స్థిరరాశి అక్షరం *r1 = r + 1;
            ఒకవేళ (p1 == ఖాళీ)
                తిరిగి tcc_error_noabort("invalid option -- '%s'", r);
            ఒకవేళ (!strstart(p1, &r1))
                కొనసాగు;
            optarg = r1;
            ఒకవేళ (popt->flags & TCC_OPTION_HAS_ARG) {
                ఒకవేళ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ఒకవేళ (optind >= argc)
                        తిరిగి tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } లేకపోతే ఒకవేళ (*r1 != '\0')
                కొనసాగు;
            ఆపు;
        }

        ఎంపిక(popt->సూచీ) {
        స్థితి TCC_OPTION_I:
            tcc_కూడు_include_మార్గం(s, optarg);
            ఆపు;
        స్థితి TCC_OPTION_D:
            tcc_define_చిహ్నం(s, optarg, ఖాళీ);
            ఆపు;
        స్థితి TCC_OPTION_U:
            tcc_undefine_చిహ్నం(s, optarg);
            ఆపు;
        స్థితి TCC_OPTION_L:
            tcc_కూడు_library_మార్గం(s, optarg);
            ఆపు;
        స్థితి TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_సమితి_lib_మార్గం(s, optarg);
            కొనసాగు;
        స్థితి TCC_OPTION_l:
            వాదనలు_parser_కూడు_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ముసుగు));
            ఆపు;
        స్థితి TCC_OPTION_pthread:
            s->option_pthread = 1;
            ఆపు;
        స్థితి TCC_OPTION_bench:
            s->do_bench = 1;
            ఆపు;
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
        స్థితి TCC_OPTION_bt:
            s->rt_అంకె_callers = atoi(optarg); /* zero = default (6) */
            వెళ్ళు enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ఒకవేళ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_సంస్కరణ;
            ఆపు;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        స్థితి TCC_OPTION_b:
            s->do_bounds_check = 1;
            వెళ్ళు enable_backtrace;
#అయితే_ముగింపు
#అయితే_ముగింపు
        స్థితి TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_సంస్కరణ;
        g_redo:
            ఒకవేళ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_సంస్కరణ;
            } లేకపోతే ఒకవేళ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } లేకపోతే ఒకవేళ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                వెళ్ళు g_redo;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
            } లేకపోతే ఒకవేళ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#అయితే_ముగింపు
            }
            ఆపు;
        స్థితి TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        సమితి_output_type:
            ఒకవేళ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ఆపు;
        స్థితి TCC_OPTION_d:
            ఒకవేళ (*optarg == 'D')
                s->dflag = 3;
            లేకపోతే ఒకవేళ (*optarg == 'M')
                s->dflag = 7;
            లేకపోతే ఒకవేళ (*optarg == 't')
                s->dflag = 16;
            లేకపోతే ఒకవేళ (isnum(*optarg))
                g_debug |= atoi(optarg);
            లేకపోతే
                వెళ్ళు unsupported_option;
            ఆపు;
        స్థితి TCC_OPTION_static:
            s->static_link = 1;
            ఆపు;
        స్థితి TCC_OPTION_std:
            ఒకవేళ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ఆపు;
        స్థితి TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            వెళ్ళు సమితి_output_type;
        స్థితి TCC_OPTION_soname:
            tcc_సమితి_str(&s->soname, optarg);
            ఆపు;
        స్థితి TCC_OPTION_o:
            ఒకవేళ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_సమితి_str(&s->outfile, optarg);
            ఆపు;
        స్థితి TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            వెళ్ళు సమితి_output_type;
        స్థితి TCC_OPTION_isystem:
            tcc_కూడు_sysinclude_మార్గం(s, optarg);
            ఆపు;
        స్థితి TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ఆపు;
        స్థితి TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ఆపు;
        స్థితి TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ఆపు;
        స్థితి TCC_OPTION_నిరంతరం:
#నిర్వచితమైతే TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            నిరంతరం = optarg;
            x = TCC_OUTPUT_జ్ఞాపకం;
            వెళ్ళు సమితి_output_type;
#లేకపోతే
            తిరిగి tcc_error_noabort("-run is not available in a cross compiler");
#అయితే_ముగింపు
#నిర్వచితమైతే TCC_IS_NATIVE
        స్థితి TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->నిరంతరం_stdin = optarg;
            ఆపు;
#అయితే_ముగింపు
        స్థితి TCC_OPTION_v:
            చేయి ++s->verbose; అయితే (*optarg++ == 'v');
            కొనసాగు;
        స్థితి TCC_OPTION_f:
            ఒకవేళ (సమితి_flag(s, options_f, optarg) < 0)
                వెళ్ళు unsupported_option;
            ఆపు;
#నిర్వచితమైతే TCC_లక్ష్యం_ARM
        స్థితి TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ఒకవేళ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } లేకపోతే ఒకవేళ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            లేకపోతే
                తిరిగి tcc_error_noabort("unsupported float abi '%s'", optarg);
            కొనసాగు;
#అయితే_ముగింపు
        స్థితి TCC_OPTION_m:
            ఒకవేళ (సమితి_flag(s, options_m, optarg) < 0) {
                ఒకవేళ (x = atoi(optarg), x != 32 && x != 64)
                    వెళ్ళు unsupported_option;
                ఒకవేళ (PTR_కొలత != x/8)
                    తిరిగి x;
                కొనసాగు;
            }
            ఆపు;
        స్థితి TCC_OPTION_W:
            ఒకవేళ (optarg[0] && సమితి_flag(s, options_W, optarg) < 0)
                వెళ్ళు unsupported_option;
            ఆపు;
        స్థితి TCC_OPTION_w:
            s->warn_none = 1;
            ఆపు;
        స్థితి TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ఆపు;
        స్థితి TCC_OPTION_Wl:
            ఒకవేళ (tcc_సమితి_linker(s, optarg) < 0)
                తిరిగి -1;
            ఆపు;
        స్థితి TCC_OPTION_Wp:
            ఒకవేళ (argv[0]) /* not with tcc_set_options() */
                చొప్పించు_వాదనలు(s, &argv, &argc, --optind, optarg, ',');
            ఆపు;
        స్థితి TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            వెళ్ళు సమితి_output_type;
        స్థితి TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ఆపు;

        స్థితి TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        స్థితి TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ఒకవేళ (!s->deps_outfile)
                tcc_సమితి_str(&s->deps_outfile, "-");
            ఆపు;
        స్థితి TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        స్థితి TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ఒకవేళ (*optarg != ',')
                ఆపు;
            ++optarg;
            // fall through
        స్థితి TCC_OPTION_MF:
            tcc_సమితి_str(&s->deps_outfile, optarg);
            ఆపు;
        స్థితి TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ఆపు;

        స్థితి TCC_OPTION_dumpmachine:
            రాయి("%s\n", dumpmachine_str);
            నిష్క్రమించు(0);
        స్థితి TCC_OPTION_dumpversion:
            రాయి ("%s\n", TCC_సంస్కరణ);
            నిష్క్రమించు(0);

        స్థితి TCC_OPTION_x:
            x = 0;
            ఒకవేళ (*optarg == 'c')
                x = AFF_TYPE_C;
            లేకపోతే ఒకవేళ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            లేకపోతే ఒకవేళ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            లేకపోతే ఒకవేళ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            లేకపోతే
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_ముసుగు);
            ఆపు;
        స్థితి TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ఆపు;
#ఒకవేళ defined TCC_లక్ష్యం_MACHO
        స్థితి TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            వెళ్ళు సమితి_output_type;
        స్థితి TCC_OPTION_flat_namespace:
	     ఆపు;
        స్థితి TCC_OPTION_two_levelnamespace:
	     ఆపు;
        స్థితి TCC_OPTION_undefined:
	     ఆపు;
        స్థితి TCC_OPTION_install_name:
	    tcc_సమితి_str(&s->install_name, optarg);
            ఆపు;
        స్థితి TCC_OPTION_compatibility_సంస్కరణ:
	    s->compatibility_సంస్కరణ = parse_సంస్కరణ(s, optarg);
            ఆపు;
        స్థితి TCC_OPTION_current_సంస్కరణ:
	    s->current_సంస్కరణ = parse_సంస్కరణ(s, optarg);;
            ఆపు;
#అయితే_ముగింపు
        స్థితి TCC_OPTION_HELP:
            x = OPT_HELP;
            వెళ్ళు extra_action;
        స్థితి TCC_OPTION_HELP2:
            x = OPT_HELP2;
            వెళ్ళు extra_action;
        స్థితి TCC_OPTION_print_శోధన_dirs:
            x = OPT_PRINT_DIRS;
            వెళ్ళు extra_action;
        స్థితి TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            వెళ్ళు extra_action;
        స్థితి TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ఒకవేళ (ఖాళీ == argv[0]) /* from tcc_set_options() */
                తిరిగి -1;
            ఒకవేళ (!ఖాళీలు && x)
                తిరిగి tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            తిరిగి x;
        అప్రమేయ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ఆపు;
        }
        ఖాళీలు = 0;
    }
    ఒకవేళ (s->link_optind < s->link_argc)
        తిరిగి tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ఒకవేళ (నిరంతరం) {
        ఒకవేళ (*నిరంతరం && tcc_సమితి_options(s, నిరంతరం) < 0)
            తిరిగి -1;
        x = 0, r = 0;
        వెళ్ళు extra_action;
    }
    ఒకవేళ (!ఖాళీలు)
        తిరిగి 0;
    ఒకవేళ (s->verbose == 2)
        తిరిగి OPT_PRINT_DIRS;
    ఒకవేళ (s->verbose)
        తిరిగి OPT_V;
    తిరిగి OPT_HELP;
}

LIBTCCAPI పూర్ణాంకం tcc_సమితి_options(TCCState *s, స్థిరరాశి అక్షరం *r)
{
    అక్షరం **argv = ఖాళీ;
    పూర్ణాంకం argc = 0, ret;
    dynarray_కూడు(&argv, &argc, 0);
    dynarray_విభజించు(&argv, &argc, r, 0);
    ret = tcc_parse_వాదనలు(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    తిరిగి ret;
}

PUB_FUNC శూన్య tcc_print_stats(TCCState *s1, గుర్తులేని మొత్తం_సమయం)
{
    ఒకవేళ (!మొత్తం_సమయం)
        మొత్తం_సమయం = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           మొత్తం_idents, మొత్తం_పంక్తులు, మొత్తం_బైట్లు,
           (ద్విగుణ)మొత్తం_సమయం/1000,
           (గుర్తులేని)మొత్తం_పంక్తులు*1000/మొత్తం_సమయం,
           (ద్విగుణ)మొత్తం_బైట్లు/1000/మొత్తం_సమయం);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->మొత్తం_output[0],
           s1->మొత్తం_output[1],
           s1->మొత్తం_output[2],
           s1->మొత్తం_output[3]
           );
#నిర్వచితమైతే MEM_DEBUG
    fprintf(stderr, "# memory usage");
#నిర్వచితమైతే TCC_IS_NATIVE
    ఒకవేళ (s1->నిరంతరం_కొలత) {
        Section *s = s1->symtab;
        గుర్తులేని ms = s->దత్తాంశం_స్థానభ్రంశం + s->link->దత్తాంశం_స్థానభ్రంశం + s->hash->దత్తాంశం_స్థానభ్రంశం;
        గుర్తులేని rs = s1->నిరంతరం_కొలత;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_కొలత - rs - ms);
    }
#అయితే_ముగింపు
    fprintf(stderr, " %d max (bytes)\n", mem_max_కొలత);
#అయితే_ముగింపు
}
