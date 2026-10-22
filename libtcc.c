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

#ଯଦି ONE_SOURCE
#ଅନ୍ତର୍ଭାଵ "tccpp.c"
#ଅନ୍ତର୍ଭାଵ "tccgen.c"
#ଅନ୍ତର୍ଭାଵ "tccdbg.c"
#ଅନ୍ତର୍ଭାଵ "tccasm.c"
#ଅନ୍ତର୍ଭାଵ "tccelf.c"
#ଅନ୍ତର୍ଭାଵ "tccrun.c"
#ifdef TCC_TARGET_I386
#ଅନ୍ତର୍ଭାଵ "i386-gen.c"
#ଅନ୍ତର୍ଭାଵ "i386-link.c"
#ଅନ୍ତର୍ଭାଵ "i386-asm.c"
#ନଚେତଯଦି defined(TCC_TARGET_ARM)
#ଅନ୍ତର୍ଭାଵ "arm-gen.c"
#ଅନ୍ତର୍ଭାଵ "arm-link.c"
#ଅନ୍ତର୍ଭାଵ "arm-asm.c"
#ନଚେତଯଦି defined(TCC_TARGET_ARM64)
#ଅନ୍ତର୍ଭାଵ "arm64-gen.c"
#ଅନ୍ତର୍ଭାଵ "arm64-link.c"
#ଅନ୍ତର୍ଭାଵ "arm64-asm.c"
#ନଚେତଯଦି defined(TCC_TARGET_C67)
#ଅନ୍ତର୍ଭାଵ "c67-gen.c"
#ଅନ୍ତର୍ଭାଵ "c67-link.c"
#ଅନ୍ତର୍ଭାଵ "tcccoff.c"
#ନଚେତଯଦି defined(TCC_TARGET_X86_64)
#ଅନ୍ତର୍ଭାଵ "x86_64-gen.c"
#ଅନ୍ତର୍ଭାଵ "x86_64-link.c"
#ଅନ୍ତର୍ଭାଵ "i386-asm.c"
#ନଚେତଯଦି defined(TCC_TARGET_RISCV64)
#ଅନ୍ତର୍ଭାଵ "riscv64-gen.c"
#ଅନ୍ତର୍ଭାଵ "riscv64-link.c"
#ଅନ୍ତର୍ଭାଵ "riscv64-asm.c"
#ଅନ୍ୟଥା
#error unknown target
#endif
#ifdef TCC_TARGET_PE
#ଅନ୍ତର୍ଭାଵ "tccpe.c"
#endif
#ifdef TCC_TARGET_MACHO
#ଅନ୍ତର୍ଭାଵ "tccmacho.c"
#endif
#endif /* ONE_SOURCE */

#ଅନ୍ତର୍ଭାଵ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_DATA ସଂରଚନା TCCState *tcc_state;
TCC_SEM(ସ୍ଥିର tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_DATA ଶୂନ୍ୟ** stk_data;
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_stk_data;
/* option -d<num> (for general development purposes) */
ST_DATA ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_debug;

/********************************************************/
#ifdef _WIN32
ST_FUNC ଅକ୍ଷର *normalize_slashes(ଅକ୍ଷର *path)
{
    ଅକ୍ଷର *p;
    ପାଇଁ (p = path; *p; ++p)
        ଯଦି (*p == '\\')
            *p = '/';
    ଫେରନ୍ତୁ path;
}

#ଯଦି defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ସ୍ଥିର HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ଯଦି (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    ଫେରନ୍ତୁ TRUE;
}
#ଅନ୍ୟଥା
#define tcc_module ଖାଲି /* NULL means executable itself */
#endif

#ifndef CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଅକ୍ଷର *config_tccdir_w32(ଅକ୍ଷର *path)
{
    ଅକ୍ଷର *p;
    GetModuleFileNameA(tcc_module, path, MAX_PATH);
    p = tcc_basename(normalize_slashes(strlwr(path)));
    ଯଦି (p > path)
        --p;
    *p = 0;
    ଫେରନ୍ତୁ path;
}
#define CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_PATH))
#endif

#ifdef TCC_IS_NATIVE
ସ୍ଥିର ଶୂନ୍ୟ tcc_add_systemdir(TCCState *s)
{
    ଅକ୍ଷର buf[1000];
    GetSystemDirectoryA(buf, ଆକାର buf);
    tcc_add_library_path(s, normalize_slashes(buf));
}
#endif
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ଅଚଳ ଅକ୍ଷର *f, ଅଚଳ ଅକ୍ଷର *m) {
    ଫେରନ୍ତୁ fopen(f, m);
}
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_fclose(FILE *f) {
    ଫେରନ୍ତୁ fclose(f);
}
#endif
/********************************************************/

PUB_FUNC ଶୂନ୍ୟ tcc_enter_state(TCCState *s1)
{
    ଯଦି (s1->error_set_jmp_enabled)
        ଫେରନ୍ତୁ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC ଶୂନ୍ୟ tcc_exit_state(TCCState *s1)
{
    ଯଦି (s1->error_set_jmp_enabled)
        ଫେରନ୍ତୁ;
    tcc_state = ଖାଲି;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC ଅକ୍ଷର *pstrcpy(ଅକ୍ଷର *buf, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s)
{
    ଅକ୍ଷର *q, *q_end;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;

    ଯଦି (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        ଯେତେବେଳେ (q < q_end) {
            c = *s++;
            ଯଦି (c == '\0')
                ଭାଙ୍ଗ;
            *q++ = c;
        }
        *q = '\0';
    }
    ଫେରନ୍ତୁ buf;
}

/* strcat and truncate. */
ST_FUNC ଅକ୍ଷର *pstrcat(ଅକ୍ଷର *buf, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s)
{
    size_t len;
    len = strlen(buf);
    ଯଦି (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    ଫେରନ୍ତୁ buf;
}

ST_FUNC ଅକ୍ଷର *pstrncpy(ଅକ୍ଷର *out, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s, size_t ଅଙ୍କ)
{
    ଯଦି (ଅଙ୍କ >= buf_size)
        ଅଙ୍କ = buf_size - 1;
    memcpy(out, s, ଅଙ୍କ);
    out[ଅଙ୍କ] = '\0';
    ଫେରନ୍ତୁ out;
}

/* extract the basename of a file */
PUB_FUNC ଅକ୍ଷର *tcc_basename(ଅଚଳ ଅକ୍ଷର *name)
{
    ଅକ୍ଷର *p = (ଅକ୍ଷର *)strchr(name, 0);
    ଯେତେବେଳେ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    ଫେରନ୍ତୁ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC ଅକ୍ଷର *tcc_fileextension (ଅଚଳ ଅକ୍ଷର *name)
{
    ଅକ୍ଷର *b = tcc_basename(name);
    ଅକ୍ଷର *e = strrchr(b, '.');
    ଫେରନ୍ତୁ e ? e : strchr(b, 0);
}

ST_FUNC ଅକ୍ଷର *tcc_load_text(ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା len = lseek(fd, 0, SEEK_END);
    ଅକ୍ଷର *buf = load_data(fd, 0, len + 1);
    buf[len] = 0;
    ଫେରନ୍ତୁ buf;
}

/* replace *pp by copy of 'str' or NULL */
ସ୍ଥିର ଶୂନ୍ୟ tcc_set_str(ଅକ୍ଷର **pp, ଅଚଳ ଅକ୍ଷର *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ଖାଲି;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ସ୍ଥିର ଶୂନ୍ୟ tcc_concat_str(ଅକ୍ଷର **pp, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sep)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା l = *pp ? strlen(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + strlen(str) + 1);
    ଯଦି (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#undef ମୁକ୍ତ
#undef realloc

ସ୍ଥିର ଶୂନ୍ୟ *default_reallocator(ଶୂନ୍ୟ *ptr, unsigned long size)
{
    ଶୂନ୍ୟ *ptr1;
    ଯଦି (size == 0) {
        ମୁକ୍ତ(ptr);
        ptr1 = ଖାଲି;
    }
    ଅନ୍ୟଥା {
        ptr1 = realloc(ptr, size);
        ଯଦି (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            exit (1);
        }
    }
    ଫେରନ୍ତୁ ptr1;
}

ST_FUNC ଶୂନ୍ୟ libc_free(ଶୂନ୍ୟ *ptr)
{
    ମୁକ୍ତ(ptr);
}

/* defined to be not used */
#define ମୁକ୍ତ(p) use_tcc_free(p)
#define realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ସ୍ଥିର ଶୂନ୍ୟ *(*reallocator)(ଶୂନ୍ୟ*, unsigned long) = default_reallocator;

LIBTCCAPI ଶୂନ୍ୟ tcc_set_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#undef tcc_free
#undef tcc_malloc
#undef tcc_realloc
#undef tcc_mallocz
#undef tcc_strdup

PUB_FUNC ଶୂନ୍ୟ tcc_free(ଶୂନ୍ୟ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC ଶୂନ୍ୟ *tcc_malloc(unsigned long size)
{
    ଫେରନ୍ତୁ reallocator(0, size);
}

PUB_FUNC ଶୂନ୍ୟ *tcc_realloc(ଶୂନ୍ୟ *ptr, unsigned long size)
{
    ଫେରନ୍ତୁ reallocator(ptr, size);
}

PUB_FUNC ଶୂନ୍ୟ *tcc_mallocz(unsigned long size)
{
    ଶୂନ୍ୟ *ptr;
    ptr = tcc_malloc(size);
    ଯଦି (size)
        memset(ptr, 0, size);
    ଫେରନ୍ତୁ ptr;
}

PUB_FUNC ଅକ୍ଷର *tcc_strdup(ଅଚଳ ଅକ୍ଷର *str)
{
    ଅକ୍ଷର *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    ଫେରନ୍ତୁ ptr;
}

#ifdef MEM_DEBUG

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    (((unsigned ଅକ୍ଷର *) header->magic3) + header->size)
#define MEM_USER_PTR(header) \
    ((ଅକ୍ଷର *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((ଅକ୍ଷର*)ptr - offsetof(mem_debug_header_t, magic3))

ସଂରଚନା mem_debug_header {
    unsigned magic1;
    unsigned size;
    ସଂରଚନା mem_debug_header *prev;
    ସଂରଚନା mem_debug_header *next;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_ଅଙ୍କ;
    ଅକ୍ଷର file_name[MEM_DEBUG_FILE_LEN];
    unsigned magic2;
    ALIGNED(16) unsigned ଅକ୍ଷର magic3[4];
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା mem_debug_header mem_debug_header_t;

TCC_SEM(ସ୍ଥିର mem_sem);
ସ୍ଥିର mem_debug_header_t *mem_debug_chain;
ସ୍ଥିର unsigned mem_cur_size;
ସ୍ଥିର unsigned mem_max_size;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_states;

ସ୍ଥିର mem_debug_header_t *malloc_check(ଶୂନ୍ୟ *ptr, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    ଯଦି (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(header)) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", ସନ୍ଦେଶ);
        ଯଦି (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->ଧାଡ଼ି_ଅଙ୍କ);
        exit(1);
    }
    ଫେରନ୍ତୁ header;
}

PUB_FUNC ଶୂନ୍ୟ *tcc_malloc_debug(unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ofs;
    mem_debug_header_t *header;
    ଯଦି (!size)
        ଫେରନ୍ତୁ ଖାଲି;
    header = tcc_malloc(ଆକାର(mem_debug_header_t) + size);
    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    header->ଧାଡ଼ି_ଅଙ୍କ = ଧାଡ଼ି;
    ofs = strlen(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(header->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    header->next = mem_debug_chain;
    header->prev = ଖାଲି;
    ଯଦି (header->next)
        header->next->prev = header;
    mem_debug_chain = header;
    mem_cur_size += size;
    ଯଦି (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ଫେରନ୍ତୁ MEM_USER_PTR(header);
}

PUB_FUNC ଶୂନ୍ୟ tcc_free_debug(ଶୂନ୍ୟ *ptr)
{
    mem_debug_header_t *header;
    ଯଦି (!ptr)
        ଫେରନ୍ତୁ;
    header = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    ଯଦି (header->next)
        header->next->prev = header->prev;
    ଯଦି (header->prev)
        header->prev->next = header->next;
    ଯଦି (header == mem_debug_chain)
        mem_debug_chain = header->next;
    POST_SEM(&mem_sem);
    tcc_free(header);
}

PUB_FUNC ଶୂନ୍ୟ *tcc_mallocz_debug(unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    ଶୂନ୍ୟ *ptr;
    ptr = tcc_malloc_debug(size,file,ଧାଡ଼ି);
    ଯଦି (size)
        memset(ptr, 0, size);
    ଫେରନ୍ତୁ ptr;
}

PUB_FUNC ଶୂନ୍ୟ *tcc_realloc_debug(ଶୂନ୍ୟ *ptr, unsigned long size, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    mem_debug_header_t *header;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା mem_debug_chain_update = 0;

    ଯଦି (!ptr)
        ଫେରନ୍ତୁ tcc_malloc_debug(size, file, ଧାଡ଼ି);
    ଯଦି (!size) {
        tcc_free_debug(ptr);
        ଫେରନ୍ତୁ ଖାଲି;
    }
    header = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = tcc_realloc(header, ଆକାର(mem_debug_header_t) + size);
    header->size = size;
    write32le(MEM_DEBUG_CHECK3(header), MEM_DEBUG_MAGIC3);
    ଯଦି (header->next)
        header->next->prev = header;
    ଯଦି (header->prev)
        header->prev->next = header;
    ଯଦି (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    ଯଦି (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    POST_SEM(&mem_sem);
    ଫେରନ୍ତୁ MEM_USER_PTR(header);
}

PUB_FUNC ଅକ୍ଷର *tcc_strdup_debug(ଅଚଳ ଅକ୍ଷର *str, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି)
{
    ଅକ୍ଷର *ptr;
    ptr = tcc_malloc_debug(strlen(str) + 1, file, ଧାଡ଼ି);
    strcpy(ptr, str);
    ଫେରନ୍ତୁ ptr;
}

PUB_FUNC ଶୂନ୍ୟ tcc_memcheck(ପୂର୍ଣ୍ଣସଂଖ୍ୟା d)
{
    WAIT_SEM(&mem_sem);
    nb_states += d;
    ଯଦି (0 == nb_states && mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        ଯେତେବେଳେ (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->ଧାଡ଼ି_ଅଙ୍କ, header->size);
            header = header->next;
        }
        fflush(stderr);
        mem_cur_size = 0;
        mem_max_size = 0;
        mem_debug_chain = ଖାଲି;
#ଯଦି MEM_DEBUG-0 == 2
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
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା normalized_PATHCMP(ଅଚଳ ଅକ୍ଷର *f1, ଅଚଳ ଅକ୍ଷର *f2)
{
    ଅକ୍ଷର *p1, *p2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = 1;
    ଯଦି (!!(p1 = realpath(f1, ଖାଲି))) {
        ଯଦି (!!(p2 = realpath(f2, ଖାଲି))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    ଫେରନ୍ତୁ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC ଶୂନ୍ୟ dynarray_add(ଶୂନ୍ୟ *ptab, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *nb_ptr, ଶୂନ୍ୟ *data)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb, nb_alloc;
    ଶୂନ୍ୟ **pp;

    nb = *nb_ptr;
    pp = *(ଶୂନ୍ୟ ***)ptab;
    /* every power of two we double array size */
    ଯଦି ((nb & (nb - 1)) == 0) {
        ଯଦି (!nb)
            nb_alloc = 1;
        ଅନ୍ୟଥା
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * ଆକାର(ଶୂନ୍ୟ *));
        *(ଶୂନ୍ୟ***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC ଶୂନ୍ୟ dynarray_reset(ଶୂନ୍ୟ *pp, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *n)
{
    ଶୂନ୍ୟ **p;
    ପାଇଁ (p = *(ଶୂନ୍ୟ***)pp; *n; ++p, --*n)
        ଯଦି (*p)
            tcc_free(*p);
    tcc_free(*(ଶୂନ୍ୟ**)pp);
    *(ଶୂନ୍ୟ**)pp = ଖାଲି;
}

ସ୍ଥିର ଶୂନ୍ୟ dynarray_split(ଅକ୍ଷର ***argv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *argc, ଅଚଳ ଅକ୍ଷର *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sep)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା qot, c;
    CString str;
    ପାଇଁ(;;) {
        ଯେତେବେଳେ (c = (unsigned ଅକ୍ଷର)*p, c <= ' ' && c != '\0')
            ++p;
        ଯଦି (c == '\0')
            ଭାଙ୍ଗ;
        cstr_new(&str);
        qot = 0;
        କର {
            ++p;
            ଯଦି (sep) { /* e.g. to split -Wl,-opt,arg */
                ଯଦି (c == sep)
                    ଭାଙ୍ଗ;
            } ଅନ୍ୟଥା {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ଯଦି (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ଅନ୍ୟଥା ଯଦି (c == '"') {
                    qot ^= 1;
                    ଜାରି;
                } ଅନ୍ୟଥା ଯଦି (c <= ' ' && !qot) {
                    ଭାଙ୍ଗ;
                }
            }
            cstr_ccat(&str, c);
        } ଯେତେବେଳେ (c = (unsigned ଅକ୍ଷର)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_add(argv, argc, str.data);
    }
}

ସ୍ଥିର ଶୂନ୍ୟ tcc_split_path(TCCState *s, ଶୂନ୍ୟ *p_ary, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p_nb_ary, ଅଚଳ ଅକ୍ଷର *in)
{
    ଅଚଳ ଅକ୍ଷର *p;
    କର {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
        CString str;

        cstr_new(&str);
        ପାଇଁ (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ଯଦି (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ଯଦି (c == 'B')
                    cstr_cat(&str, s->tcc_lib_path, -1);
                ଯଦି (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ଯଦି (c == 'f' && file) {
                    /* substitute current file's dir */
                    ଅଚଳ ଅକ୍ଷର *f = file->true_filename;
                    ଅଚଳ ଅକ୍ଷର *b = tcc_basename(f);
                    ଯଦି (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ଅନ୍ୟଥା
                        cstr_cat(&str, ".", 1);
                }
            } ଅନ୍ୟଥା {
                cstr_ccat(&str, c);
            }
        }
        ଯଦି (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, str.data);
        }
        in = p+1;
    } ଯେତେବେଳେ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#define WARN_ON  1 /* warning is on (-Woption) */
#define WARN_ERR 2 /* warning is an error (-Werror=option) */
#define WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ଗଣନା { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ସ୍ଥିର ଶୂନ୍ୟ error1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା mode, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି = 0;

    tcc_exit_state(s1);

    ଯଦି (mode == ERROR_WARN) {
        ଯଦି (s1->warn_error)
            mode = ERROR_ERROR;
        ଯଦି (s1->warn_ଅଙ୍କ) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା wopt = *(&s1->warn_none + s1->warn_ଅଙ୍କ);
            s1->warn_ଅଙ୍କ = 0;
            ଯଦି (0 == (wopt & WARN_ON))
                ଫେରନ୍ତୁ;
            ଯଦି (wopt & WARN_ERR)
                mode = ERROR_ERROR;
            ଯଦି (wopt & WARN_NOE)
                mode = ERROR_WARN;
        }
        ଯଦି (s1->warn_none)
            ଫେରନ୍ତୁ;
    }

    cstr_new(&cs);
    ଯଦି (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        ଧାଡ଼ି = va_arg(ap, ପୂର୍ଣ୍ଣସଂଖ୍ୟା), fmt += 3;
    f = ଖାଲି;
    ଯଦି (s1->error_set_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        ପାଇଁ (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ଯଦି (f) {
        ପାଇଁ(pf = s1->include_ଗଦା; pf < s1->include_ଗଦା_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->ଧାଡ଼ି_ଅଙ୍କ - 1);
        ଯଦି (0 == ଧାଡ଼ି)
            ଧାଡ଼ି = f->ଧାଡ଼ି_ଅଙ୍କ - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, ଧାଡ଼ି);
    } ଅନ୍ୟଥା ଯଦି (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ଅନ୍ୟଥା {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, mode == ERROR_WARN ? "warning: " : "error: ");
    ଯଦି (pp_ପଦସମଷ୍ଟି > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ଅନ୍ୟଥା
        cstr_vprintf(&cs, fmt, ap);
    ଯଦି (!s1->error_func) {
        /* default case: stderr */
        ଯଦି (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            printf("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (ଅକ୍ଷର*)cs.data);
        fflush(stderr); /* print error/warning now (win32) */
    } ଅନ୍ୟଥା {
        s1->error_func(s1->error_opaque, (ଅକ୍ଷର*)cs.data);
    }
    cstr_free(&cs);
    ଯଦି (mode != ERROR_WARN)
        s1->nb_errors++;
    ଯଦି (mode == ERROR_ERROR && s1->error_set_jmp_enabled) {
        ଯେତେବେଳେ (nb_stk_data)
            tcc_free(*(ଶୂନ୍ୟ**)stk_data[--nb_stk_data]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI ଶୂନ୍ୟ tcc_set_error_func(TCCState *s, ଶୂନ୍ୟ *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_error_noabort(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    ଫେରନ୍ତୁ -1;
}

#undef _tcc_error
PUB_FUNC ଶୂନ୍ୟ _tcc_error(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    exit(1);
}
#define _tcc_error use_tcc_error_noabort

PUB_FUNC ଶୂନ୍ୟ _tcc_warning(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC ଶୂନ୍ୟ tcc_open_bf(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା initlen)
{
    BufferedFile *bf;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = tcc_mallocz(ଆକାର(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, ଆକାର(bf->filename), filename);
#ifdef _WIN32
    normalize_slashes(bf->filename);
#endif
    bf->true_filename = bf->filename;
    bf->ଧାଡ଼ି_ଅଙ୍କ = 1;
    bf->ifdef_ଗଦା_ptr = s1->ifdef_ଗଦା_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC ଶୂନ୍ୟ tcc_close(ଶୂନ୍ୟ)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ଯଦି (bf->fd > 0) {
        close(bf->fd);
        total_ଧାଡ଼ିଗୁଡ଼ିକ += bf->ଧାଡ଼ି_ଅଙ୍କ - 1;
    }
    ଯଦି (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_open(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd;
    ଯଦି (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ଅନ୍ୟଥା
        fd = open(filename, O_RDONLY | O_ଦ୍ୱିମିକ_2);
    ଯଦି ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(s1->include_ଗଦା_ptr - s1->include_ଗଦା), "", filename);
    ଫେରନ୍ତୁ fd;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_open(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd = _tcc_open(s1, filename);
    ଯଦି (fd < 0)
        ଫେରନ୍ତୁ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    ଫେରନ୍ତୁ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_compile(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype, ଅଚଳ ଅକ୍ଷର *str, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_set_jmp_enabled = 1;

    ଯଦି (setjmp(s1->error_jmp_buf) == 0) {

        ଯଦି (fd == -1) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା len = strlen(str);
            tcc_open_bf(s1, "<string>", len);
            memcpy(file->buffer, str, len);
        } ଅନ୍ୟଥା {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_start(s1, filetype);
        tccgen_init(s1);

        ଯଦି (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ଅନ୍ୟଥା {
            tccelf_begin_file(s1);
            ଯଦି (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ଅନ୍ୟଥା {
                tccgen_compile(s1);
            }
            tccelf_end_file(s1);
        }
    }
    tccgen_finish(s1);
    preprocess_end(s1);
    s1->error_set_jmp_enabled = 0;
    tcc_exit_state(s1);
    ଫେରନ୍ତୁ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_compile_string(TCCState *s, ଅଚଳ ଅକ୍ଷର *str)
{
    ଫେରନ୍ତୁ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ଶୂନ୍ୟ tcc_define_ପ୍ରତୀକ(TCCState *s1, ଅଚଳ ଅକ୍ଷର *sym, ଅଚଳ ଅକ୍ଷର *ମୂଲ୍ୟ)
{
    ଅଚଳ ଅକ୍ଷର *eq;
    ଯଦି (ଖାଲି == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ଯଦି (ଖାଲି == ମୂଲ୍ୟ)
        ମୂଲ୍ୟ = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(eq-sym), sym, ମୂଲ୍ୟ);
}

/* undefine a preprocessor symbol */
LIBTCCAPI ଶୂନ୍ୟ tcc_undefine_ପ୍ରତୀକ(TCCState *s1, ଅଚଳ ଅକ୍ଷର *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(ଶୂନ୍ୟ)
{
    TCCState *s;

    s = tcc_mallocz(ଆକାର(TCCState));
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
#ଯଦି defined TCC_TARGET_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#endif
#ଯଦି defined TCC_TARGET_ARM64 && defined TCC_TARGET_PE
    s->pe_dll_characteristics = 0x8160;
#endif
#ifdef CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#endif
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ଗଦା_ptr = s->include_ଗଦା;

    tcc_set_lib_path(s, CONFIG_TCCDIR);
#ifdef CONFIG_TCC_SWITCHES /* predefined options */
    tcc_set_options(s, CONFIG_TCC_SWITCHES);
#endif
    ଫେରନ୍ତୁ s;
}

LIBTCCAPI ଶୂନ୍ୟ tcc_delete(TCCState *s1)
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
    tcc_free(s1->init_ପ୍ରତୀକ);
    tcc_free(s1->fini_ପ୍ରତୀକ);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ଯଦି defined TCC_TARGET_MACHO
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

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_set_output_type(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା output_type)
{
#ifdef CONFIG_TCC_PIE
    ଯଦି (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#endif
    s->output_type = output_type;

    ଯଦି (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_add_sysinclude_path(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ଯଦି (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        ଫେରନ୍ତୁ 0;
    }

    /* add sections */
    tccelf_new(s);

    ଯଦି (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        ଫେରନ୍ତୁ 0;
    }

    ଯଦି (!s->nostdlib_paths)
        tcc_add_library_path(s, CONFIG_TCC_LIBPATHS);

#ifdef TCC_TARGET_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_add_systemdir(s);
# endif

#ନଚେତଯଦି defined TCC_TARGET_MACHO
# ifdef TCC_IS_NATIVE
    tcc_add_macos_sdkpath(s);
# endif

#ଅନ୍ୟଥା
    /* paths for crt objects */
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ଯଦି (output_type != TCC_OUTPUT_MEMORY && !s->nostdlib)
        tccelf_add_crtbegin(s); /* may produce errors */
#endif
    ଫେରନ୍ତୁ s->nb_errors ? -1 : 0;
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_include_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname)
{
    tcc_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    ଫେରନ୍ତୁ 0;
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_sysinclude_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname)
{
    tcc_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    ଫେରନ୍ତୁ 0;
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname)
{
    tcc_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    ଫେରନ୍ତୁ 0;
}

LIBTCCAPI ଶୂନ୍ୟ tcc_set_lib_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *path)
{
    tcc_set_str(&s->tcc_lib_path, path);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_add_dllref(TCCState *s1, ଅଚଳ ଅକ୍ଷର *dllname, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    DLLReference *ref = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < s1->nb_loaded_dlls; i++)
        ଯଦି (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ଭାଙ୍ଗ;
        }
    ଯଦି (level == -1)
        ଫେରନ୍ତୁ ref;
    ଯଦି (ref) {
        ଯଦି (level < ref->level)
            ref->level = level;
        ref->found = 1;
        ଫେରନ୍ତୁ ref;
    }
    ref = tcc_mallocz(ଆକାର(DLLReference) + strlen(dllname));
    strcpy(ref->name, dllname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->index = s1->nb_loaded_dlls;
    ଫେରନ୍ତୁ ref;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_ଦ୍ୱିମିକ(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd)
{
    ElfW(Ehdr) ehdr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା obj_type;
    ଅଚଳ ଅକ୍ଷର *saved_filename = s1->current_filename;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    ବାଛ (obj_type) {

    ସ୍ଥିତି AFF_BINTYPE_REL:
        ret = tcc_load_object_file(s1, fd, 0);
        ଭାଙ୍ଗ;

    ସ୍ଥିତି AFF_BINTYPE_AR:
        ret = tcc_load_archive(s1, fd, !(flags & AFF_WHOLE_ARCHIVE));
        ଭାଙ୍ଗ;

#ଯଦି defined TCC_TARGET_UNIX
    ସ୍ଥିତି AFF_BINTYPE_DYN:
        ଯଦି (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ଶୂନ୍ୟ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ଯଦି (dl)
                tcc_add_dllref(s1, filename, 0)->handle = dl;
            ଅନ୍ୟଥା
                ret = FILE_NOT_RECOGNIZED;
#endif
        } ଅନ୍ୟଥା
            ret = tcc_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ଭାଙ୍ଗ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_load_ldscript(s1, fd);
        ଭାଙ୍ଗ;

#ନଚେତଯଦି defined TCC_TARGET_MACHO
    ସ୍ଥିତି AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ଯଦି (s1->output_type == TCC_OUTPUT_MEMORY) {
#ifdef TCC_IS_NATIVE
            ଶୂନ୍ୟ* dl;
            ଅଚଳ ଅକ୍ଷର* soname = filename;
            ଅକ୍ଷର *tmp = 0;
            ଯଦି (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ଯଦି (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ଯଦି (dl)
                tcc_add_dllref(s1, soname, 0)->handle = dl;
            ଅନ୍ୟଥା
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#endif
        } ଅନ୍ୟଥା ଯଦି (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_load_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ଅନ୍ୟଥା {
            ret = macho_load_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ଯଦି (ret)
            ret = FILE_NOT_RECOGNIZED;
        ଭାଙ୍ଗ;

    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
    {
        ଅଚଳ ଅକ୍ଷର *ext = tcc_fileextension(filename);
        ଯଦି (!strcmp(ext, ".tbd"))
            ଯାଅ case_dyn_or_tbd;
        ଯଦି (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            ଯାଅ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ଭାଙ୍ଗ;
    }

#ନଚେତଯଦି defined TCC_TARGET_PE
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଯଦି (pe_load_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ଭାଙ୍ଗ;
#endif

#ifdef TCC_TARGET_COFF
    ସ୍ଥିତି AFF_BINTYPE_C67:
        ret = tcc_load_coff(s1, fd);
        ଭାଙ୍ଗ;
#endif
    }

    close(fd);
    s1->current_filename = saved_filename;
    ଯଦି (ret == FILE_NOT_RECOGNIZED)
        ଫେରନ୍ତୁ tcc_error_noabort("%s: unrecognized file type", filename);
    ଫେରନ୍ତୁ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ଯଦି defined TARGETOS_OpenBSD && !defined _WIN32
#ଅନ୍ତର୍ଭାଵ <glob.h>
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_glob_so(TCCState *s1, ଅଚଳ ଅକ୍ଷର *pattern, ଅକ୍ଷର *buf, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ଅଚଳ ଅକ୍ଷର *star;
    glob_t g;
    ଅକ୍ଷର *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, v, v1, v2, v3;

    star = strchr(pattern, '*');
    ଯଦି (!star || glob(pattern, 0, ଖାଲି, &g))
        ଫେରନ୍ତୁ -1;
    ପାଇଁ (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ଯଦି (2 != sscanf(p + (star - pattern), "%d.%d.%d", &v1, &v2, &v3))
            ଜାରି;
        ଯଦି ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, size, p);
    }
    globfree(&g);
    ଫେରନ୍ତୁ v;
}
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା guess_filetype(ଅଚଳ ଅକ୍ଷର *filename)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype = 0;
    ଯଦି (1) {
        /* use a file extension to detect a filetype */
        ଅଚଳ ଅକ୍ଷର *ext = tcc_fileextension(filename);
        ଯଦି (ext[0]) {
            ext++;
            ଯଦି (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ଅନ୍ୟଥା ଯଦି (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ଅନ୍ୟଥା ଯଦି (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ଅନ୍ୟଥା
                filetype |= AFF_TYPE_BIN;
        } ଅନ୍ୟଥା {
            filetype = AFF_TYPE_C;
        }
    }
    ଫେରନ୍ତୁ filetype;
}

ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_file_internal(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd;

#ଯଦି defined TARGETOS_OpenBSD && !defined _WIN32
    ଅକ୍ଷର buf[1024];
    ଯଦି (tcc_glob_so(s1, filename, buf, ଆକାର buf) >= 0)
        filename = buf;
#endif

    ଯଦି (0 == (flags & AFF_TYPE_MASK))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ଯଦି (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        ଫେରନ୍ତୁ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ଯଦି (fd < 0) {
        ଯଦି (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        ଫେରନ୍ତୁ FILE_NOT_FOUND;
    }

    ଯଦି (flags & AFF_TYPE_BIN)
        ଫେରନ୍ତୁ tcc_add_ଦ୍ୱିମିକ(s1, flags, filename, fd);

    dynarray_add(&s1->target_deps, &s1->nb_target_deps, tcc_strdup(filename));
    ଫେରନ୍ତୁ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_file(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename)
{
    ଫେରନ୍ତୁ tcc_add_file_internal(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library_internal(TCCState *s1, ଅଚଳ ଅକ୍ଷର *fmt,
    ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags, ଅକ୍ଷର **paths, ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_paths)
{
    ଅକ୍ଷର buf[1024];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, ret;

    ପାଇଁ(i = 0; i < nb_paths; i++) {
        snprintf(buf, ଆକାର(buf), fmt, paths[i], filename);
        ret = tcc_add_file_internal(s1, buf, flags & ~AFF_PRINT_ERROR);
        ଯଦି (ret != FILE_NOT_FOUND)
            ଫେରନ୍ତୁ ret;
    }
    ଯଦି (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    ଫେରନ୍ତୁ FILE_NOT_FOUND;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_dll(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags)
{
    ଫେରନ୍ତୁ tcc_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_support(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename)
{
    ଅକ୍ଷର buf[100];
    ଯଦି (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    ଫେରନ୍ତୁ tcc_add_dll(s1, filename, AFF_PRINT_ERROR);
}

#ifdef TCC_TARGET_UNIX
ST_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_crt(TCCState *s1, ଅଚଳ ଅକ୍ଷର *filename)
{
    ଫେରନ୍ତୁ tcc_add_library_internal(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#endif

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library(TCCState *s, ଅଚଳ ଅକ୍ଷର *libraryname)
{
    ସ୍ଥିର ଅଚଳ ଅକ୍ଷର * ଅଚଳ libs[] = {
#ଯଦି defined TCC_TARGET_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#ନଚେତଯଦି defined TCC_TARGET_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#ନଚେତଯଦି defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ଅନ୍ୟଥା
        "%s/lib%s.so",
#endif
        "%s/lib%s.a",
        ଖାଲି
    };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags = AFF_TYPE_LIB | (s->filetype & AFF_WHOLE_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ଯଦି (*libraryname == ':') {
        libraryname++;
    } ଅନ୍ୟଥା {
        ଅଚଳ ଅକ୍ଷର * ଅଚଳ *pp = libs;
        ଯଦି (s->static_link)
            pp += ଆକାର(libs) / ଆକାର(*libs) - 2; /* only "%s/lib%s.a" */
        ଯେତେବେଳେ (*pp) {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = tcc_add_library_internal(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ଯଦି (ret != FILE_NOT_FOUND)
                ଫେରନ୍ତୁ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    ଫେରନ୍ତୁ tcc_add_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC ଶୂନ୍ୟ tcc_add_pragma_libs(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_add_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା strstart(ଅଚଳ ଅକ୍ଷର *val, ଅଚଳ ଅକ୍ଷର **str)
{
    ଅଚଳ ଅକ୍ଷର *p, *q;
    p = *str;
    q = val;
    ଯେତେବେଳେ (*q) {
        ଯଦି (*p != *q)
            ଫେରନ୍ତୁ 0;
        p++;
        q++;
    }
    *str = p;
    ଫେରନ୍ତୁ 1;
}

ସଂରଚନା lopt {
    TCCState *s;
    ଅଚଳ ଅକ୍ଷର *opt, *arg;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା match;
};

/* match linker option */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା link_option(ସଂରଚନା lopt *o, ଅଚଳ ଅକ୍ଷର *q)
{
    ଅଚଳ ଅକ୍ଷର *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ଯଦି (*p++ != '-')
        ଫେରନ୍ତୁ 0;
    ଯଦି (*p == '-')
        p++;
    r = 1;
    ଯଦି (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ଯଦି (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ifdef TCC_TARGET_PE
        ଅନ୍ୟଥା ଯଦି (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#endif
    }
    ଯେତେବେଳେ ((c = *q) == *p) {
        ଯଦି (c == '\0')
            ଯାଅ succ; /* -Wl,-opt */
        ++p;
        ଯଦି (c == '=')
            ଯାଅ succ; /* -Wl,-opt=arg */
        ++q;
    }
    ଯଦି (*p == '\0') {
        ଯଦି (c == '|')
            ଯାଅ succ;
        ଯଦି (c == '=' || c == ':') {
            ଯଦି (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                ଯାଅ succ; /* -Wl,-opt,arg */
            }
            o->match = 1; /* -Wl,-opt -Wl,arg */
            ଫେରନ୍ତୁ 0;
        }
    } ଅନ୍ୟଥା ଯଦି (c == ':')
        ଯାଅ succ; /* -Wl,-Iarg */
    ଯେତେବେଳେ (*q)
        ଯଦି (*q++ == '|')
            ଯାଅ redo;
    ଫେରନ୍ତୁ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    ଫେରନ୍ତୁ r;
}

ସ୍ଥିର ଶୂନ୍ୟ args_parser_add_file(TCCState *s, ଅଚଳ ଅକ୍ଷର* filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype);

#define SET_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#define SET_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_set_linker(TCCState *s, ଅଚଳ ଅକ୍ଷର *optarg)
{
    TCCState *s1 = s;

    dynarray_split(&s1->link_argv, &s1->link_argc, optarg, ',');

    ଯେତେବେଳେ (s->link_optind < s->link_argc) {
        ଅକ୍ଷର *end = ଖାଲି;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା ignoring = 0;
        ସଂରଚନା lopt o = {0};
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ଯଦି (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "e=|entry=")) {
            tcc_set_str(&s->elf_entryname, o.arg);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "image-base=|Ttext=")) {
            s->text_addr = strtoull(o.arg, &end, 16);
            s->has_text_addr = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "init=")) {
            tcc_set_str(&s->init_ପ୍ରତୀକ, o.arg);
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "fini=")) {
            tcc_set_str(&s->fini_ପ୍ରତୀକ, o.arg);
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "Map=")) {
            tcc_set_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "oformat=")) {
#ଯଦି defined TCC_TARGET_PE
            ଯଦି (0 == strncmp("pe-", o.arg, 3))
#ନଚେତଯଦି PTR_SIZE == 8
            ଯଦି (0 == strncmp("elf64-", o.arg, 6))
#ଅନ୍ୟଥା
            ଯଦି (0 == strncmp("elf32-", o.arg, 6))
#endif
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ଅନ୍ୟଥା ଯଦି (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ଦ୍ୱିମିକ;
#ଯଦି defined TCC_TARGET_COFF
            ଅନ୍ୟଥା ଯଦି (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#endif
            ଅନ୍ୟଥା
                ଯାଅ err;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "dynamic-linker=|I:")) {
            tcc_set_str(&s->elfint, o.arg);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &end, 16);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "soname=|install_name=")) {
            tcc_set_str(&s->soname, o.arg);
        } ଅନ୍ୟଥା ଯଦି (!!(r = link_option(&o, "?whole-archive"))) {
            SET_OR_CLEAR(s->filetype, AFF_WHOLE_ARCHIVE);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ifdef TCC_TARGET_PE
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ଅନ୍ୟଥା ଯଦି (!!(r = link_option(&o, "?dynamicbase"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ଅନ୍ୟଥା ଯଦି (!!(r = link_option(&o, "?high-entropy-va"))) {
            SET_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ଅନ୍ୟଥା ଯଦି (!!(r = link_option(&o, "?nxcompat"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ଅନ୍ୟଥା ଯଦି (!!(r = link_option(&o, "?tsaware"))) {
            SET_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &end, 16);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "stack=")) {
            s->pe_ଗଦା_size = strtoul(o.arg, &end, 10);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "subsystem=")) {
            ଯଦି (pe_setsubsy(s, o.arg) < 0)
                ଯାଅ err;
#ନଚେତଯଦି defined TCC_TARGET_MACHO
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "all_load")) {
	    s->filetype |= AFF_WHOLE_ARCHIVE;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "force_load=")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | AFF_WHOLE_ARCHIVE);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "single_module")) {
            ignoring = 1;
#endif
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "O")) {
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "z=")) {
            ignoring = 1;
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "L:")) {
            tcc_add_library_path(s, o.arg);
        } ଅନ୍ୟଥା ଯଦି (link_option(&o, "l:")) {
            args_parser_add_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
        } ଅନ୍ୟଥା ଯଦି (o.match) {
            ଫେରନ୍ତୁ 0; /* expecting argument with next '-Wl,' */
        } ଅନ୍ୟଥା {
    err:
            ଫେରନ୍ତୁ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ଯଦି (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    ଫେରନ୍ତୁ 0;
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TCCOption {
    ଅଚଳ ଅକ୍ଷର *name;
    uint16_t index;
    uint16_t flags;
} TCCOption;

ଗଣନା {
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
    TCC_OPTION_print_ସନ୍ଧାନ_dirs,
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

ସ୍ଥିର ଅଚଳ TCCOption tcc_options[] = {
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
    { "print-search-dirs", TCC_OPTION_print_ସନ୍ଧାନ_dirs, 0 },
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
    { ଖାଲି, 0, 0 },
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା FlagDef {
    uint16_t offset;
    uint16_t flags;
    ଅଚଳ ଅକ୍ଷର *name;
} FlagDef;

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

ସ୍ଥିର ଅଚଳ FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_strings), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ଖାଲି }
};

ସ୍ଥିର ଅଚଳ FlagDef options_f[] = {
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
    { 0, 0, ଖାଲି }
};

ସ୍ଥିର ଅଚଳ FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ifdef TCC_TARGET_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, ଖାଲି }
};

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା set_flag(TCCState *s, ଅଚଳ FlagDef *flags, ଅଚଳ ଅକ୍ଷର *name)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ, mask, ret;
    ଅଚଳ FlagDef *p;
    ଅଚଳ ଅକ୍ଷର *r;
    unsigned ଅକ୍ଷର *f;

    r = name, ମୂଲ୍ୟ = !strstart("no-", &r), mask = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ଯଦି ((flags->flags & WD_ALL) && strstart("error=", &r))
        ମୂଲ୍ୟ = ମୂଲ୍ୟ ? WARN_ON|WARN_ERR : WARN_NOE, mask = WARN_ON;

    ପାଇଁ (ret = -1, p = flags; p->name; ++p) {
        ଯଦି (ret) {
            ଯଦି (strcmp(r, p->name))
                ଜାରି;
        } ଅନ୍ୟଥା {
            ଯଦି (0 == (p->flags & WD_ALL))
                ଜାରି;
        }

        f = (unsigned ଅକ୍ଷର *)s + p->offset;
        *f = (*f & mask) | (ମୂଲ୍ୟ ^ !!(p->flags & FD_INVERT));

        ଯଦି (ret) {
            ret = 0;
            ଯଦି (strcmp(r, "all"))
                ଭାଙ୍ଗ;
        }
    }
    ଫେରନ୍ତୁ ret;
}

ସ୍ଥିର ଅଚଳ ଅକ୍ଷର dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ifdef TCC_TARGET_I386
    "i386-pc"
#ନଚେତଯଦି defined TCC_TARGET_X86_64
    "x86_64-pc"
#ନଚେତଯଦି defined TCC_TARGET_C67
    "c67"
#ନଚେତଯଦି defined TCC_TARGET_ARM
    "arm"
#ନଚେତଯଦି defined TCC_TARGET_ARM64
    "aarch64"
#ନଚେତଯଦି defined TCC_TARGET_RISCV64
    "riscv64"
#endif
    "-"
#ifdef TCC_TARGET_PE
    "mingw32"
#ନଚେତଯଦି defined(TCC_TARGET_MACHO)
    "apple-darwin"
#ନଚେତଯଦି TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#ନଚେତଯଦି TARGETOS_OpenBSD
    "openbsd"
#ନଚେତଯଦି TARGETOS_NetBSD
    "netbsd"
#ନଚେତଯଦି CONFIG_TCC_MUSL
    "linux-musl"
#ଅନ୍ୟଥା
    "linux-gnu"
#endif
;

#ଯଦି defined TCC_TARGET_MACHO
ସ୍ଥିର uint32_t parse_version(TCCState *s1, ଅଚଳ ଅକ୍ଷର *version)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    ଅକ୍ଷର* last;

    a = strtoul(version, &last, 10);
    ଯଦି (*last == '.') {
        b = strtoul(&last[1], &last, 10);
        ଯଦି (*last == '.')
             c = strtoul(&last[1], &last, 10);
    }
    ଯଦି (*last || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", version);
    ଫେରନ୍ତୁ (a << 16) | (b << 8) | c;
}
#endif

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ସ୍ଥିର ଶୂନ୍ୟ ଭର୍ତ୍ତି_args(TCCState *s1, ଅକ୍ଷର ***pargv, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pargc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା optind, ଅଚଳ ଅକ୍ଷର *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା sep)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc = 0;
    ଅକ୍ଷର **argv = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = 0; i < *pargc; ++i)
        ଯଦି (i == optind)
            dynarray_split(&argv, &argc, p, sep);
        ଅନ୍ୟଥା
            dynarray_add(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ସ୍ଥିର ଶୂନ୍ୟ args_parser_add_file(TCCState *s, ଅଚଳ ଅକ୍ଷର* filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା filetype)
{
    ସଂରଚନା filespec *f = tcc_malloc(ଆକାର *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
    ଯଦି (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_parse_args(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *pargc, ଅକ୍ଷର ***pargv)
{
    TCCState *s1 = s;
    ଅଚଳ TCCOption *popt;
    ଅଚଳ ଅକ୍ଷର *optarg, *r;
    ଅଚଳ ଅକ୍ଷର *run = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା optind = 1, empty = 1, x;
    ଅକ୍ଷର **argv = *pargv;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc = *pargc;

    s->link_optind = s->link_argc;

    ଯେତେବେଳେ (optind < argc) {
        r = argv[optind];
        ଯଦି (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd; ଅକ୍ଷର *p;
            fd = open(++r, O_RDONLY | O_ଦ୍ୱିମିକ_2);
            ଯଦି (fd < 0)
                ଫେରନ୍ତୁ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_load_text(fd);
            ଭର୍ତ୍ତି_args(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ଜାରି;
        }
        optind++;
        ଯଦି (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            args_parser_add_file(s, r, s->filetype);
            empty = 0;
        dorun:
            ଯଦି (run)
                ଭାଙ୍ଗ;
            ଜାରି;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ଯଦି (r[1] == '-' && r[2] == '\0')
            ଯାଅ dorun;

        /* find option in table */
        ପାଇଁ(popt = tcc_options; ; ++popt) {
            ଅଚଳ ଅକ୍ଷର *p1 = popt->name;
            ଅଚଳ ଅକ୍ଷର *r1 = r + 1;
            ଯଦି (p1 == ଖାଲି)
                ଫେରନ୍ତୁ tcc_error_noabort("invalid option -- '%s'", r);
            ଯଦି (!strstart(p1, &r1))
                ଜାରି;
            optarg = r1;
            ଯଦି (popt->flags & TCC_OPTION_HAS_ARG) {
                ଯଦି (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ଯଦି (optind >= argc)
                        ଫେରନ୍ତୁ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ଅନ୍ୟଥା ଯଦି (*r1 != '\0')
                ଜାରି;
            ଭାଙ୍ଗ;
        }

        ବାଛ(popt->index) {
        ସ୍ଥିତି TCC_OPTION_I:
            tcc_add_include_path(s, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_D:
            tcc_define_ପ୍ରତୀକ(s, optarg, ଖାଲି);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_U:
            tcc_undefine_ପ୍ରତୀକ(s, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_L:
            tcc_add_library_path(s, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_set_lib_path(s, optarg);
            ଜାରି;
        ସ୍ଥିତି TCC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_MASK));
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_pthread:
            s->option_pthread = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_bench:
            s->do_bench = 1;
            ଭାଙ୍ଗ;
#ifdef CONFIG_TCC_BACKTRACE
        ସ୍ଥିତି TCC_OPTION_bt:
            s->rt_ଅଙ୍କ_callers = atoi(optarg); /* zero = default (6) */
            ଯାଅ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ଯଦି (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_VERSION;
            ଭାଙ୍ଗ;
#ifdef CONFIG_TCC_BCHECK
        ସ୍ଥିତି TCC_OPTION_b:
            s->do_bounds_check = 1;
            ଯାଅ enable_backtrace;
#endif
#endif
        ସ୍ଥିତି TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_VERSION;
        g_redo:
            ଯଦି (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_VERSION;
            } ଅନ୍ୟଥା ଯଦି (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ଅନ୍ୟଥା ଯଦି (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                ଯାଅ g_redo;
#ifdef TCC_TARGET_PE
            } ଅନ୍ୟଥା ଯଦି (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#endif
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        set_output_type:
            ଯଦି (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_d:
            ଯଦି (*optarg == 'D')
                s->dflag = 3;
            ଅନ୍ୟଥା ଯଦି (*optarg == 'M')
                s->dflag = 7;
            ଅନ୍ୟଥା ଯଦି (*optarg == 't')
                s->dflag = 16;
            ଅନ୍ୟଥା ଯଦି (isnum(*optarg))
                g_debug |= atoi(optarg);
            ଅନ୍ୟଥା
                ଯାଅ unsupported_option;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_static:
            s->static_link = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_std:
            ଯଦି (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            ଯାଅ set_output_type;
        ସ୍ଥିତି TCC_OPTION_soname:
            tcc_set_str(&s->soname, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_o:
            ଯଦି (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_set_str(&s->outfile, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            ଯାଅ set_output_type;
        ସ୍ଥିତି TCC_OPTION_isystem:
            tcc_add_sysinclude_path(s, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_run:
#ifdef TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            run = optarg;
            x = TCC_OUTPUT_MEMORY;
            ଯାଅ set_output_type;
#ଅନ୍ୟଥା
            ଫେରନ୍ତୁ tcc_error_noabort("-run is not available in a cross compiler");
#endif
#ifdef TCC_IS_NATIVE
        ସ୍ଥିତି TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->run_stdin = optarg;
            ଭାଙ୍ଗ;
#endif
        ସ୍ଥିତି TCC_OPTION_v:
            କର ++s->verbose; ଯେତେବେଳେ (*optarg++ == 'v');
            ଜାରି;
        ସ୍ଥିତି TCC_OPTION_f:
            ଯଦି (set_flag(s, options_f, optarg) < 0)
                ଯାଅ unsupported_option;
            ଭାଙ୍ଗ;
#ifdef TCC_TARGET_ARM
        ସ୍ଥିତି TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ଯଦି (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ଅନ୍ୟଥା ଯଦି (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ଅନ୍ୟଥା
                ଫେରନ୍ତୁ tcc_error_noabort("unsupported float abi '%s'", optarg);
            ଜାରି;
#endif
        ସ୍ଥିତି TCC_OPTION_m:
            ଯଦି (set_flag(s, options_m, optarg) < 0) {
                ଯଦି (x = atoi(optarg), x != 32 && x != 64)
                    ଯାଅ unsupported_option;
                ଯଦି (PTR_SIZE != x/8)
                    ଫେରନ୍ତୁ x;
                ଜାରି;
            }
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_W:
            ଯଦି (optarg[0] && set_flag(s, options_W, optarg) < 0)
                ଯାଅ unsupported_option;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_w:
            s->warn_none = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_Wl:
            ଯଦି (tcc_set_linker(s, optarg) < 0)
                ଫେରନ୍ତୁ -1;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_Wp:
            ଯଦି (argv[0]) /* not with tcc_set_options() */
                ଭର୍ତ୍ତି_args(s, &argv, &argc, --optind, optarg, ',');
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            ଯାଅ set_output_type;
        ସ୍ଥିତି TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ଭାଙ୍ଗ;

        ସ୍ଥିତି TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        ସ୍ଥିତି TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ଯଦି (!s->deps_outfile)
                tcc_set_str(&s->deps_outfile, "-");
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        ସ୍ଥିତି TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ଯଦି (*optarg != ',')
                ଭାଙ୍ଗ;
            ++optarg;
            // fall through
        ସ୍ଥିତି TCC_OPTION_MF:
            tcc_set_str(&s->deps_outfile, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ଭାଙ୍ଗ;

        ସ୍ଥିତି TCC_OPTION_dumpmachine:
            printf("%s\n", dumpmachine_str);
            exit(0);
        ସ୍ଥିତି TCC_OPTION_dumpversion:
            printf ("%s\n", TCC_VERSION);
            exit(0);

        ସ୍ଥିତି TCC_OPTION_x:
            x = 0;
            ଯଦି (*optarg == 'c')
                x = AFF_TYPE_C;
            ଅନ୍ୟଥା ଯଦି (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ଅନ୍ୟଥା ଯଦି (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ଅନ୍ୟଥା ଯଦି (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ଅନ୍ୟଥା
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_MASK);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ଭାଙ୍ଗ;
#ଯଦି defined TCC_TARGET_MACHO
        ସ୍ଥିତି TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            ଯାଅ set_output_type;
        ସ୍ଥିତି TCC_OPTION_flat_namespace:
	     ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_two_levelnamespace:
	     ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_undefined:
	     ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_install_name:
	    tcc_set_str(&s->install_name, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_compatibility_version:
	    s->compatibility_version = parse_version(s, optarg);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି TCC_OPTION_current_version:
	    s->current_version = parse_version(s, optarg);;
            ଭାଙ୍ଗ;
#endif
        ସ୍ଥିତି TCC_OPTION_HELP:
            x = OPT_HELP;
            ଯାଅ extra_action;
        ସ୍ଥିତି TCC_OPTION_HELP2:
            x = OPT_HELP2;
            ଯାଅ extra_action;
        ସ୍ଥିତି TCC_OPTION_print_ସନ୍ଧାନ_dirs:
            x = OPT_PRINT_DIRS;
            ଯାଅ extra_action;
        ସ୍ଥିତି TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            ଯାଅ extra_action;
        ସ୍ଥିତି TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ଯଦି (ଖାଲି == argv[0]) /* from tcc_set_options() */
                ଫେରନ୍ତୁ -1;
            ଯଦି (!empty && x)
                ଫେରନ୍ତୁ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            ଫେରନ୍ତୁ x;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ଭାଙ୍ଗ;
        }
        empty = 0;
    }
    ଯଦି (s->link_optind < s->link_argc)
        ଫେରନ୍ତୁ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ଯଦି (run) {
        ଯଦି (*run && tcc_set_options(s, run) < 0)
            ଫେରନ୍ତୁ -1;
        x = 0, r = 0;
        ଯାଅ extra_action;
    }
    ଯଦି (!empty)
        ଫେରନ୍ତୁ 0;
    ଯଦି (s->verbose == 2)
        ଫେରନ୍ତୁ OPT_PRINT_DIRS;
    ଯଦି (s->verbose)
        ଫେରନ୍ତୁ OPT_V;
    ଫେରନ୍ତୁ OPT_HELP;
}

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_set_options(TCCState *s, ଅଚଳ ଅକ୍ଷର *r)
{
    ଅକ୍ଷର **argv = ଖାଲି;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc = 0, ret;
    dynarray_add(&argv, &argc, 0);
    dynarray_split(&argv, &argc, r, 0);
    ret = tcc_parse_args(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    ଫେରନ୍ତୁ ret;
}

PUB_FUNC ଶୂନ୍ୟ tcc_print_stats(TCCState *s1, unsigned total_time)
{
    ଯଦି (!total_time)
        total_time = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           total_idents, total_ଧାଡ଼ିଗୁଡ଼ିକ, total_bytes,
           (ଦ୍ୱିଗୁଣ)total_time/1000,
           (unsigned)total_ଧାଡ଼ିଗୁଡ଼ିକ*1000/total_time,
           (ଦ୍ୱିଗୁଣ)total_bytes/1000/total_time);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->total_output[0],
           s1->total_output[1],
           s1->total_output[2],
           s1->total_output[3]
           );
#ifdef MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ifdef TCC_IS_NATIVE
    ଯଦି (s1->run_size) {
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
