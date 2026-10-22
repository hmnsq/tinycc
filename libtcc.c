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

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ONE_ਸਰੋਤ
# define ONE_ਸਰੋਤ 1
#ਜੇ_ਅੰਤ

#ਜੇ ONE_ਸਰੋਤ
#ਅਨ੍ਤਰ੍ਭਾਵ "tccpp.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tccgen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tccdbg.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tccasm.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tccelf.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tccrun.c"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
#ਅਨ੍ਤਰ੍ਭਾਵ "i386-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "i386-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "i386-asm.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM)
#ਅਨ੍ਤਰ੍ਭਾਵ "arm-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "arm-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "arm-asm.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_ARM64)
#ਅਨ੍ਤਰ੍ਭਾਵ "arm64-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "arm64-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "arm64-asm.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_C67)
#ਅਨ੍ਤਰ੍ਭਾਵ "c67-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "c67-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "tcccoff.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_X86_64)
#ਅਨ੍ਤਰ੍ਭਾਵ "x86_64-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "x86_64-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "i386-asm.c"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_RISCV64)
#ਅਨ੍ਤਰ੍ਭਾਵ "riscv64-gen.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "riscv64-link.c"
#ਅਨ੍ਤਰ੍ਭਾਵ "riscv64-asm.c"
#ਨਹੀਂਤਾਂ
#ਗਲਤੀ unknown ਨਿਸ਼ਾਨਾ
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
#ਅਨ੍ਤਰ੍ਭਾਵ "tccpe.c"
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
#ਅਨ੍ਤਰ੍ਭਾਵ "tccmacho.c"
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ /* ONE_SOURCE */

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_ਅੰਕੜੇ ਬਣਤਰ TCCState *tcc_state;
TCC_SEM(ਸਥਿਰ tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_ਅੰਕੜੇ ਖਾਲੀ** stk_ਅੰਕੜੇ;
ST_ਅੰਕੜੇ ਪੂਰਨ nb_stk_ਅੰਕੜੇ;
/* option -d<num> (for general development purposes) */
ST_ਅੰਕੜੇ ਪੂਰਨ g_debug;

/********************************************************/
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
ST_FUNC ਅੱਖਰ *normalize_slashes(ਅੱਖਰ *ਰਸਤਾ)
{
    ਅੱਖਰ *p;
    ਲਈ (p = ਰਸਤਾ; *p; ++p)
        ਜੇ (*p == '\\')
            *p = '/';
    ਵਾਪਸ ਰਸਤਾ;
}

#ਜੇ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ਸਥਿਰ HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ਜੇ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    ਵਾਪਸ TRUE;
}
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_module ਨਿਰਾ /* NULL means executable itself */
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਅੱਖਰ *config_tccdir_w32(ਅੱਖਰ *ਰਸਤਾ)
{
    ਅੱਖਰ *p;
    GetModuleFileNameA(tcc_module, ਰਸਤਾ, MAX_ਰਸਤਾ);
    p = tcc_basename(normalize_slashes(strlwr(ਰਸਤਾ)));
    ਜੇ (p > ਰਸਤਾ)
        --p;
    *p = 0;
    ਵਾਪਸ ਰਸਤਾ;
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_ਰਸਤਾ))
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
ਸਥਿਰ ਖਾਲੀ tcc_ਜੋੜੋ_systemdir(TCCState *s)
{
    ਅੱਖਰ buf[1000];
    GetSystemDirectoryA(buf, ਆਕਾਰ buf);
    tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, normalize_slashes(buf));
}
#ਜੇ_ਅੰਤ
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ਅਚਲ ਅੱਖਰ *f, ਅਚਲ ਅੱਖਰ *m) {
    ਵਾਪਸ fopen(f, m);
}
PUB_FUNC ਪੂਰਨ tcc_fclose(FILE *f) {
    ਵਾਪਸ fclose(f);
}
#ਜੇ_ਅੰਤ
/********************************************************/

PUB_FUNC ਖਾਲੀ tcc_enter_state(TCCState *s1)
{
    ਜੇ (s1->error_ਸੈੱਟ_jmp_enabled)
        ਵਾਪਸ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC ਖਾਲੀ tcc_exit_state(TCCState *s1)
{
    ਜੇ (s1->error_ਸੈੱਟ_jmp_enabled)
        ਵਾਪਸ;
    tcc_state = ਨਿਰਾ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC ਅੱਖਰ *pstrcpy(ਅੱਖਰ *buf, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s)
{
    ਅੱਖਰ *q, *q_ਸਿਰਾ;
    ਪੂਰਨ c;

    ਜੇ (buf_ਮਾਪ > 0) {
        q = buf;
        q_ਸਿਰਾ = buf + buf_ਮਾਪ - 1;
        ਜਦੋਂ (q < q_ਸਿਰਾ) {
            c = *s++;
            ਜੇ (c == '\0')
                ਰੋਕੋ;
            *q++ = c;
        }
        *q = '\0';
    }
    ਵਾਪਸ buf;
}

/* strcat and truncate. */
ST_FUNC ਅੱਖਰ *pstrcat(ਅੱਖਰ *buf, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s)
{
    ਮਾਪ_t len;
    len = ਲੜੀ_ਲੰਬਾਈ(buf);
    ਜੇ (len < buf_ਮਾਪ)
        pstrcpy(buf + len, buf_ਮਾਪ - len, s);
    ਵਾਪਸ buf;
}

ST_FUNC ਅੱਖਰ *pstrncpy(ਅੱਖਰ *ਬਾਹਰਲਾ, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s, ਮਾਪ_t ਅੰਕ)
{
    ਜੇ (ਅੰਕ >= buf_ਮਾਪ)
        ਅੰਕ = buf_ਮਾਪ - 1;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਬਾਹਰਲਾ, s, ਅੰਕ);
    ਬਾਹਰਲਾ[ਅੰਕ] = '\0';
    ਵਾਪਸ ਬਾਹਰਲਾ;
}

/* extract the basename of a file */
PUB_FUNC ਅੱਖਰ *tcc_basename(ਅਚਲ ਅੱਖਰ *name)
{
    ਅੱਖਰ *p = (ਅੱਖਰ *)strchr(name, 0);
    ਜਦੋਂ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    ਵਾਪਸ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC ਅੱਖਰ *tcc_fileextension (ਅਚਲ ਅੱਖਰ *name)
{
    ਅੱਖਰ *b = tcc_basename(name);
    ਅੱਖਰ *e = strrchr(b, '.');
    ਵਾਪਸ e ? e : strchr(b, 0);
}

ST_FUNC ਅੱਖਰ *tcc_ਲੱਦੋ_ਪਾਠ(ਪੂਰਨ fd)
{
    ਪੂਰਨ len = lseek(fd, 0, SEEK_END);
    ਅੱਖਰ *buf = ਲੱਦੋ_ਅੰਕੜੇ(fd, 0, len + 1);
    buf[len] = 0;
    ਵਾਪਸ buf;
}

/* replace *pp by copy of 'str' or NULL */
ਸਥਿਰ ਖਾਲੀ tcc_ਸੈੱਟ_str(ਅੱਖਰ **pp, ਅਚਲ ਅੱਖਰ *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ਨਿਰਾ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ਸਥਿਰ ਖਾਲੀ tcc_concat_str(ਅੱਖਰ **pp, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ sep)
{
    ਪੂਰਨ l = *pp ? ਲੜੀ_ਲੰਬਾਈ(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + ਲੜੀ_ਲੰਬਾਈ(str) + 1);
    ਜੇ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ ਮੁਕਤ
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ realloc

ਸਥਿਰ ਖਾਲੀ *default_reallocator(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਖਾਲੀ *ptr1;
    ਜੇ (ਮਾਪ == 0) {
        ਮੁਕਤ(ptr);
        ptr1 = ਨਿਰਾ;
    }
    ਨਹੀਂਤਾਂ {
        ptr1 = realloc(ptr, ਮਾਪ);
        ਜੇ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            ਬਾਹਰ_ਨਿਕਲੋ (1);
        }
    }
    ਵਾਪਸ ptr1;
}

ST_FUNC ਖਾਲੀ libc_free(ਖਾਲੀ *ptr)
{
    ਮੁਕਤ(ptr);
}

/* defined to be not used */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮੁਕਤ(p) use_tcc_free(p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ਸਥਿਰ ਖਾਲੀ *(*reallocator)(ਖਾਲੀ*, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) = default_reallocator;

LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcc_free
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcc_malloc
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcc_realloc
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcc_mallocz
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ tcc_strdup

PUB_FUNC ਖਾਲੀ tcc_free(ਖਾਲੀ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC ਖਾਲੀ *tcc_malloc(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਵਾਪਸ reallocator(0, ਮਾਪ);
}

PUB_FUNC ਖਾਲੀ *tcc_realloc(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਵਾਪਸ reallocator(ptr, ਮਾਪ);
}

PUB_FUNC ਖਾਲੀ *tcc_mallocz(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ)
{
    ਖਾਲੀ *ptr;
    ptr = tcc_malloc(ਮਾਪ);
    ਜੇ (ਮਾਪ)
        memset(ptr, 0, ਮਾਪ);
    ਵਾਪਸ ptr;
}

PUB_FUNC ਅੱਖਰ *tcc_strdup(ਅਚਲ ਅੱਖਰ *str)
{
    ਅੱਖਰ *ptr;
    ptr = tcc_malloc(ਲੜੀ_ਲੰਬਾਈ(str) + 1);
    strcpy(ptr, str);
    ਵਾਪਸ ptr;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ MEM_DEBUG

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DEBUG_MAGIC1 0xFEEDDEB1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DEBUG_MAGIC2 0xFEEDDEB2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DEBUG_MAGIC3 0xFEEDDEB3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DEBUG_FILE_LEN 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DEBUG_CHECK3(ਸਿਰਲੇਖ) \
    (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *) ਸਿਰਲੇਖ->magic3) + ਸਿਰਲੇਖ->ਮਾਪ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_USER_PTR(ਸਿਰਲੇਖ) \
    ((ਅੱਖਰ *)ਸਿਰਲੇਖ + offsetof(mem_debug_ਸਿਰਲੇਖ_t, magic3))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_ਸਿਰਲੇਖ_PTR(ptr) \
    (mem_debug_ਸਿਰਲੇਖ_t *)((ਅੱਖਰ*)ptr - offsetof(mem_debug_ਸਿਰਲੇਖ_t, magic3))

ਬਣਤਰ mem_debug_ਸਿਰਲੇਖ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ magic1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਮਾਪ;
    ਬਣਤਰ mem_debug_ਸਿਰਲੇਖ *prev;
    ਬਣਤਰ mem_debug_ਸਿਰਲੇਖ *ਅਗਲਾ;
    ਪੂਰਨ ਸਤਰ_ਅੰਕ;
    ਅੱਖਰ file_name[MEM_DEBUG_FILE_LEN];
    ਬਿਨਾਨਿਸ਼ਾਨੀ magic2;
    ALIGNED(16) ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ magic3[4];
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ mem_debug_ਸਿਰਲੇਖ mem_debug_ਸਿਰਲੇਖ_t;

TCC_SEM(ਸਥਿਰ mem_sem);
ਸਥਿਰ mem_debug_ਸਿਰਲੇਖ_t *mem_debug_chain;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ mem_cur_ਮਾਪ;
ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ mem_max_ਮਾਪ;
ਸਥਿਰ ਪੂਰਨ nb_ਹਾਲਤਾਂ;

ਸਥਿਰ mem_debug_ਸਿਰਲੇਖ_t *malloc_check(ਖਾਲੀ *ptr, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
    mem_debug_ਸਿਰਲੇਖ_t * ਸਿਰਲੇਖ = MEM_ਸਿਰਲੇਖ_PTR(ptr);
    ਜੇ (ਸਿਰਲੇਖ->magic1 != MEM_DEBUG_MAGIC1 ||
        ਸਿਰਲੇਖ->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(ਸਿਰਲੇਖ)) != MEM_DEBUG_MAGIC3 ||
        ਸਿਰਲੇਖ->ਮਾਪ == (ਬਿਨਾਨਿਸ਼ਾਨੀ)-1) {
        fprintf(stderr, "%s check failed\n", ਸੁਨੇਹਾ);
        ਜੇ (ਸਿਰਲੇਖ->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                ਸਿਰਲੇਖ->file_name, ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ);
        ਬਾਹਰ_ਨਿਕਲੋ(1);
    }
    ਵਾਪਸ ਸਿਰਲੇਖ;
}

PUB_FUNC ਖਾਲੀ *tcc_malloc_debug(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ)
{
    ਪੂਰਨ ofs;
    mem_debug_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ;
    ਜੇ (!ਮਾਪ)
        ਵਾਪਸ ਨਿਰਾ;
    ਸਿਰਲੇਖ = tcc_malloc(ਆਕਾਰ(mem_debug_ਸਿਰਲੇਖ_t) + ਮਾਪ);
    ਸਿਰਲੇਖ->magic1 = MEM_DEBUG_MAGIC1;
    ਸਿਰਲੇਖ->magic2 = MEM_DEBUG_MAGIC2;
    ਸਿਰਲੇਖ->ਮਾਪ = ਮਾਪ;
    write32le(MEM_DEBUG_CHECK3(ਸਿਰਲੇਖ), MEM_DEBUG_MAGIC3);
    ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ = ਸਤਰ;
    ofs = ਲੜੀ_ਲੰਬਾਈ(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(ਸਿਰਲੇਖ->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    ਸਿਰਲੇਖ->ਅਗਲਾ = mem_debug_chain;
    ਸਿਰਲੇਖ->prev = ਨਿਰਾ;
    ਜੇ (ਸਿਰਲੇਖ->ਅਗਲਾ)
        ਸਿਰਲੇਖ->ਅਗਲਾ->prev = ਸਿਰਲੇਖ;
    mem_debug_chain = ਸਿਰਲੇਖ;
    mem_cur_ਮਾਪ += ਮਾਪ;
    ਜੇ (mem_cur_ਮਾਪ > mem_max_ਮਾਪ)
        mem_max_ਮਾਪ = mem_cur_ਮਾਪ;
    POST_SEM(&mem_sem);
    ਵਾਪਸ MEM_USER_PTR(ਸਿਰਲੇਖ);
}

PUB_FUNC ਖਾਲੀ tcc_free_debug(ਖਾਲੀ *ptr)
{
    mem_debug_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ;
    ਜੇ (!ptr)
        ਵਾਪਸ;
    ਸਿਰਲੇਖ = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_ਮਾਪ -= ਸਿਰਲੇਖ->ਮਾਪ;
    ਸਿਰਲੇਖ->ਮਾਪ = (ਬਿਨਾਨਿਸ਼ਾਨੀ)-1;
    ਜੇ (ਸਿਰਲੇਖ->ਅਗਲਾ)
        ਸਿਰਲੇਖ->ਅਗਲਾ->prev = ਸਿਰਲੇਖ->prev;
    ਜੇ (ਸਿਰਲੇਖ->prev)
        ਸਿਰਲੇਖ->prev->ਅਗਲਾ = ਸਿਰਲੇਖ->ਅਗਲਾ;
    ਜੇ (ਸਿਰਲੇਖ == mem_debug_chain)
        mem_debug_chain = ਸਿਰਲੇਖ->ਅਗਲਾ;
    POST_SEM(&mem_sem);
    tcc_free(ਸਿਰਲੇਖ);
}

PUB_FUNC ਖਾਲੀ *tcc_mallocz_debug(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ)
{
    ਖਾਲੀ *ptr;
    ptr = tcc_malloc_debug(ਮਾਪ,file,ਸਤਰ);
    ਜੇ (ਮਾਪ)
        memset(ptr, 0, ਮਾਪ);
    ਵਾਪਸ ptr;
}

PUB_FUNC ਖਾਲੀ *tcc_realloc_debug(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮਾਪ, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ)
{
    mem_debug_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ;
    ਪੂਰਨ mem_debug_chain_update = 0;

    ਜੇ (!ptr)
        ਵਾਪਸ tcc_malloc_debug(ਮਾਪ, file, ਸਤਰ);
    ਜੇ (!ਮਾਪ) {
        tcc_free_debug(ptr);
        ਵਾਪਸ ਨਿਰਾ;
    }
    ਸਿਰਲੇਖ = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_ਮਾਪ -= ਸਿਰਲੇਖ->ਮਾਪ;
    mem_debug_chain_update = (ਸਿਰਲੇਖ == mem_debug_chain);
    ਸਿਰਲੇਖ = tcc_realloc(ਸਿਰਲੇਖ, ਆਕਾਰ(mem_debug_ਸਿਰਲੇਖ_t) + ਮਾਪ);
    ਸਿਰਲੇਖ->ਮਾਪ = ਮਾਪ;
    write32le(MEM_DEBUG_CHECK3(ਸਿਰਲੇਖ), MEM_DEBUG_MAGIC3);
    ਜੇ (ਸਿਰਲੇਖ->ਅਗਲਾ)
        ਸਿਰਲੇਖ->ਅਗਲਾ->prev = ਸਿਰਲੇਖ;
    ਜੇ (ਸਿਰਲੇਖ->prev)
        ਸਿਰਲੇਖ->prev->ਅਗਲਾ = ਸਿਰਲੇਖ;
    ਜੇ (mem_debug_chain_update)
        mem_debug_chain = ਸਿਰਲੇਖ;
    mem_cur_ਮਾਪ += ਮਾਪ;
    ਜੇ (mem_cur_ਮਾਪ > mem_max_ਮਾਪ)
        mem_max_ਮਾਪ = mem_cur_ਮਾਪ;
    POST_SEM(&mem_sem);
    ਵਾਪਸ MEM_USER_PTR(ਸਿਰਲੇਖ);
}

PUB_FUNC ਅੱਖਰ *tcc_strdup_debug(ਅਚਲ ਅੱਖਰ *str, ਅਚਲ ਅੱਖਰ *file, ਪੂਰਨ ਸਤਰ)
{
    ਅੱਖਰ *ptr;
    ptr = tcc_malloc_debug(ਲੜੀ_ਲੰਬਾਈ(str) + 1, file, ਸਤਰ);
    strcpy(ptr, str);
    ਵਾਪਸ ptr;
}

PUB_FUNC ਖਾਲੀ tcc_memcheck(ਪੂਰਨ d)
{
    WAIT_SEM(&mem_sem);
    nb_ਹਾਲਤਾਂ += d;
    ਜੇ (0 == nb_ਹਾਲਤਾਂ && mem_cur_ਮਾਪ) {
        mem_debug_ਸਿਰਲੇਖ_t *ਸਿਰਲੇਖ = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_ਮਾਪ, mem_max_ਮਾਪ);
        ਜਦੋਂ (ਸਿਰਲੇਖ) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                ਸਿਰਲੇਖ->file_name, ਸਿਰਲੇਖ->ਸਤਰ_ਅੰਕ, ਸਿਰਲੇਖ->ਮਾਪ);
            ਸਿਰਲੇਖ = ਸਿਰਲੇਖ->ਅਗਲਾ;
        }
        fflush(stderr);
        mem_cur_ਮਾਪ = 0;
        mem_max_ਮਾਪ = 0;
        mem_debug_chain = ਨਿਰਾ;
#ਜੇ MEM_DEBUG-0 == 2
        ਬਾਹਰ_ਨਿਕਲੋ(2);
#ਜੇ_ਅੰਤ
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_free(ptr)           tcc_free_debug(ptr)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_malloc(ਮਾਪ)        tcc_malloc_debug(ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_mallocz(ਮਾਪ)       tcc_mallocz_debug(ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_realloc(ptr,ਮਾਪ)   tcc_realloc_debug(ptr, ਮਾਪ, __FILE__, __LINE__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#ਜੇ_ਅੰਤ /* MEM_DEBUG */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#ਜੇ_ਅੰਤ

/* for #pragma once */
ST_FUNC ਪੂਰਨ normalized_PATHCMP(ਅਚਲ ਅੱਖਰ *f1, ਅਚਲ ਅੱਖਰ *f2)
{
    ਅੱਖਰ *p1, *p2;
    ਪੂਰਨ ret = 1;
    ਜੇ (!!(p1 = realpath(f1, ਨਿਰਾ))) {
        ਜੇ (!!(p2 = realpath(f2, ਨਿਰਾ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    ਵਾਪਸ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC ਖਾਲੀ dynarray_ਜੋੜੋ(ਖਾਲੀ *ptab, ਪੂਰਨ *nb_ptr, ਖਾਲੀ *ਅੰਕੜੇ)
{
    ਪੂਰਨ nb, nb_alloc;
    ਖਾਲੀ **pp;

    nb = *nb_ptr;
    pp = *(ਖਾਲੀ ***)ptab;
    /* every power of two we double array size */
    ਜੇ ((nb & (nb - 1)) == 0) {
        ਜੇ (!nb)
            nb_alloc = 1;
        ਨਹੀਂਤਾਂ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * ਆਕਾਰ(ਖਾਲੀ *));
        *(ਖਾਲੀ***)ptab = pp;
    }
    pp[nb++] = ਅੰਕੜੇ;
    *nb_ptr = nb;
}

ST_FUNC ਖਾਲੀ dynarray_reset(ਖਾਲੀ *pp, ਪੂਰਨ *n)
{
    ਖਾਲੀ **p;
    ਲਈ (p = *(ਖਾਲੀ***)pp; *n; ++p, --*n)
        ਜੇ (*p)
            tcc_free(*p);
    tcc_free(*(ਖਾਲੀ**)pp);
    *(ਖਾਲੀ**)pp = ਨਿਰਾ;
}

ਸਥਿਰ ਖਾਲੀ dynarray_ਵੰਡੋ(ਅੱਖਰ ***argv, ਪੂਰਨ *argc, ਅਚਲ ਅੱਖਰ *p, ਪੂਰਨ sep)
{
    ਪੂਰਨ qot, c;
    CString str;
    ਲਈ(;;) {
        ਜਦੋਂ (c = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)*p, c <= ' ' && c != '\0')
            ++p;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        cstr_new(&str);
        qot = 0;
        ਕਰੋ {
            ++p;
            ਜੇ (sep) { /* e.g. to split -Wl,-opt,arg */
                ਜੇ (c == sep)
                    ਰੋਕੋ;
            } ਨਹੀਂਤਾਂ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ਜੇ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ਨਹੀਂਤਾਂ ਜੇ (c == '"') {
                    qot ^= 1;
                    ਜਾਰੀ;
                } ਨਹੀਂਤਾਂ ਜੇ (c <= ' ' && !qot) {
                    ਰੋਕੋ;
                }
            }
            cstr_ccat(&str, c);
        } ਜਦੋਂ (c = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_ਜੋੜੋ(argv, argc, str.ਅੰਕੜੇ);
    }
}

ਸਥਿਰ ਖਾਲੀ tcc_ਵੰਡੋ_ਰਸਤਾ(TCCState *s, ਖਾਲੀ *p_ary, ਪੂਰਨ *p_nb_ary, ਅਚਲ ਅੱਖਰ *ਵਿੱਚ)
{
    ਅਚਲ ਅੱਖਰ *p;
    ਕਰੋ {
        ਪੂਰਨ c;
        CString str;

        cstr_new(&str);
        ਲਈ (p = ਵਿੱਚ; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ਜੇ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ਜੇ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_ਰਸਤਾ, -1);
                ਜੇ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ਜੇ (c == 'f' && file) {
                    /* substitute current file's dir */
                    ਅਚਲ ਅੱਖਰ *f = file->true_filename;
                    ਅਚਲ ਅੱਖਰ *b = tcc_basename(f);
                    ਜੇ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ਨਹੀਂਤਾਂ
                        cstr_cat(&str, ".", 1);
                }
            } ਨਹੀਂਤਾਂ {
                cstr_ccat(&str, c);
            }
        }
        ਜੇ (str.ਮਾਪ) {
            cstr_ccat(&str, '\0');
            dynarray_ਜੋੜੋ(p_ary, p_nb_ary, str.ਅੰਕੜੇ);
        }
        ਵਿੱਚ = p+1;
    } ਜਦੋਂ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WARN_ON  1 /* warning is on (-Woption) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WARN_ERR 2 /* warning is an error (-Werror=option) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ਗਿਣਤੀ { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ਸਥਿਰ ਖਾਲੀ error1(ਪੂਰਨ ਬਹੁਲਕ, ਅਚਲ ਅੱਖਰ *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    ਪੂਰਨ ਸਤਰ = 0;

    tcc_exit_state(s1);

    ਜੇ (ਬਹੁਲਕ == ERROR_WARN) {
        ਜੇ (s1->warn_error)
            ਬਹੁਲਕ = ERROR_ERROR;
        ਜੇ (s1->warn_ਅੰਕ) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            ਪੂਰਨ wopt = *(&s1->warn_none + s1->warn_ਅੰਕ);
            s1->warn_ਅੰਕ = 0;
            ਜੇ (0 == (wopt & WARN_ON))
                ਵਾਪਸ;
            ਜੇ (wopt & WARN_ERR)
                ਬਹੁਲਕ = ERROR_ERROR;
            ਜੇ (wopt & WARN_NOE)
                ਬਹੁਲਕ = ERROR_WARN;
        }
        ਜੇ (s1->warn_none)
            ਵਾਪਸ;
    }

    cstr_new(&cs);
    ਜੇ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        ਸਤਰ = va_arg(ap, ਪੂਰਨ), fmt += 3;
    f = ਨਿਰਾ;
    ਜੇ (s1->error_ਸੈੱਟ_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        ਲਈ (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ਜੇ (f) {
        ਲਈ(pf = s1->include_ਢੇਰ; pf < s1->include_ਢੇਰ_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->ਸਤਰ_ਅੰਕ - 1);
        ਜੇ (0 == ਸਤਰ)
            ਸਤਰ = f->ਸਤਰ_ਅੰਕ - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, ਸਤਰ);
    } ਨਹੀਂਤਾਂ ਜੇ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ਨਹੀਂਤਾਂ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, ਬਹੁਲਕ == ERROR_WARN ? "warning: " : "error: ");
    ਜੇ (pp_ਵਿਅੰਜਕ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ਨਹੀਂਤਾਂ
        cstr_vprintf(&cs, fmt, ap);
    ਜੇ (!s1->error_func) {
        /* default case: stderr */
        ਜੇ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            ਲਿਖੋ("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (ਅੱਖਰ*)cs.ਅੰਕੜੇ);
        fflush(stderr); /* print error/warning now (win32) */
    } ਨਹੀਂਤਾਂ {
        s1->error_func(s1->error_opaque, (ਅੱਖਰ*)cs.ਅੰਕੜੇ);
    }
    cstr_free(&cs);
    ਜੇ (ਬਹੁਲਕ != ERROR_WARN)
        s1->nb_errors++;
    ਜੇ (ਬਹੁਲਕ == ERROR_ERROR && s1->error_ਸੈੱਟ_jmp_enabled) {
        ਜਦੋਂ (nb_stk_ਅੰਕੜੇ)
            tcc_free(*(ਖਾਲੀ**)stk_ਅੰਕੜੇ[--nb_stk_ਅੰਕੜੇ]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_error_func(TCCState *s, ਖਾਲੀ *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC ਪੂਰਨ _tcc_error_noabort(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    ਵਾਪਸ -1;
}

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ _tcc_error
PUB_FUNC ਖਾਲੀ _tcc_error(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    ਬਾਹਰ_ਨਿਕਲੋ(1);
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _tcc_error use_tcc_error_noabort

PUB_FUNC ਖਾਲੀ _tcc_warning(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC ਖਾਲੀ tcc_open_bf(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ initlen)
{
    BufferedFile *bf;
    ਪੂਰਨ buflen = initlen ? initlen : IO_BUF_ਮਾਪ;

    bf = tcc_mallocz(ਆਕਾਰ(BufferedFile) + buflen);
    bf->buf_ptr = bf->ਬਫਰ;
    bf->buf_ਸਿਰਾ = bf->ਬਫਰ + initlen;
    bf->buf_ਸਿਰਾ[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, ਆਕਾਰ(bf->filename), filename);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    normalize_slashes(bf->filename);
#ਜੇ_ਅੰਤ
    bf->true_filename = bf->filename;
    bf->ਸਤਰ_ਅੰਕ = 1;
    bf->ifdef_ਢੇਰ_ptr = s1->ifdef_ਢੇਰ_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC ਖਾਲੀ tcc_close(ਖਾਲੀ)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ਜੇ (bf->fd > 0) {
        close(bf->fd);
        ਕੁੱਲ_ਸਤਰਾਂ += bf->ਸਤਰ_ਅੰਕ - 1;
    }
    ਜੇ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ਸਥਿਰ ਪੂਰਨ _tcc_open(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ fd;
    ਜੇ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ਨਹੀਂਤਾਂ
        fd = open(filename, O_RDONLY | O_ਦੁਆਧਾਰੀ_2);
    ਜੇ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        ਲਿਖੋ("%s %*s%s\n", fd < 0 ? "nf":"->",
               (ਪੂਰਨ)(s1->include_ਢੇਰ_ptr - s1->include_ਢੇਰ), "", filename);
    ਵਾਪਸ fd;
}

ST_FUNC ਪੂਰਨ tcc_open(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ fd = _tcc_open(s1, filename);
    ਜੇ (fd < 0)
        ਵਾਪਸ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    ਵਾਪਸ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ਸਥਿਰ ਪੂਰਨ tcc_compile(TCCState *s1, ਪੂਰਨ filetype, ਅਚਲ ਅੱਖਰ *str, ਪੂਰਨ fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_ਸੈੱਟ_jmp_enabled = 1;

    ਜੇ (setjmp(s1->error_jmp_buf) == 0) {

        ਜੇ (fd == -1) {
            ਪੂਰਨ len = ਲੜੀ_ਲੰਬਾਈ(str);
            tcc_open_bf(s1, "<string>", len);
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(file->ਬਫਰ, str, len);
        } ਨਹੀਂਤਾਂ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_ਸ਼ੁਰੂ(s1, filetype);
        tccgen_init(s1);

        ਜੇ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ਨਹੀਂਤਾਂ {
            tccelf_begin_file(s1);
            ਜੇ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ਨਹੀਂਤਾਂ {
                tccgen_compile(s1);
            }
            tccelf_ਸਿਰਾ_file(s1);
        }
    }
    tccgen_ਅੰਤ(s1);
    preprocess_ਸਿਰਾ(s1);
    s1->error_ਸੈੱਟ_jmp_enabled = 0;
    tcc_exit_state(s1);
    ਵਾਪਸ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI ਪੂਰਨ tcc_compile_string(TCCState *s, ਅਚਲ ਅੱਖਰ *str)
{
    ਵਾਪਸ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ਖਾਲੀ tcc_define_ਚਿੰਨ੍ਹ(TCCState *s1, ਅਚਲ ਅੱਖਰ *sym, ਅਚਲ ਅੱਖਰ *ਮੁੱਲ)
{
    ਅਚਲ ਅੱਖਰ *eq;
    ਜੇ (ਨਿਰਾ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ਜੇ (ਨਿਰਾ == ਮੁੱਲ)
        ਮੁੱਲ = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (ਪੂਰਨ)(eq-sym), sym, ਮੁੱਲ);
}

/* undefine a preprocessor symbol */
LIBTCCAPI ਖਾਲੀ tcc_undefine_ਚਿੰਨ੍ਹ(TCCState *s1, ਅਚਲ ਅੱਖਰ *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(ਖਾਲੀ)
{
    TCCState *s;

    s = tcc_mallocz(ਆਕਾਰ(TCCState));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ MEM_DEBUG
    tcc_memcheck(1);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_ਵਿੱਚ_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
    s->seg_ਮਾਪ = 32;
#ਜੇ_ਅੰਤ
    /* enable this if you want symbols with leading underscore on windows: */
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 && defined TCC_ਨਿਸ਼ਾਨਾ_PE
    s->pe_dll_characteristics = 0x8160;
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#ਜੇ_ਅੰਤ
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ਢੇਰ_ptr = s->include_ਢੇਰ;

    tcc_ਸੈੱਟ_lib_ਰਸਤਾ(s, CONFIG_TCCDIR);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_SWITCHES /* predefined options */
    tcc_ਸੈੱਟ_options(s, CONFIG_TCC_SWITCHES);
#ਜੇ_ਅੰਤ
    ਵਾਪਸ s;
}

LIBTCCAPI ਖਾਲੀ tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_ਰਸਤਾ);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_ਚਿੰਨ੍ਹ);
    tcc_free(s1->fini_ਚਿੰਨ੍ਹ);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
    tcc_free(s1->install_name);
#ਜੇ_ਅੰਤ
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->ਨਿਸ਼ਾਨਾ_deps, &s1->nb_ਨਿਸ਼ਾਨਾ_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
    /* free runtime memory */
    tcc_ਲੜੀਵਾਰ_free(s1);
#ਜੇ_ਅੰਤ
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ MEM_DEBUG
    tcc_memcheck(-1);
#ਜੇ_ਅੰਤ
}

LIBTCCAPI ਪੂਰਨ tcc_ਸੈੱਟ_output_type(TCCState *s, ਪੂਰਨ output_type)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_PIE
    ਜੇ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#ਜੇ_ਅੰਤ
    s->output_type = output_type;

    ਜੇ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_ਜੋੜੋ_sysinclude_ਰਸਤਾ(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ਜੇ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        ਵਾਪਸ 0;
    }

    /* add sections */
    tccelf_new(s);

    ਜੇ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        ਵਾਪਸ 0;
    }

    ਜੇ (!s->nostdlib_paths)
        tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, CONFIG_TCC_LIBPATHS);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_ਜੋੜੋ_systemdir(s);
# endif

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
# ifdef TCC_IS_NATIVE
    tcc_ਜੋੜੋ_macos_sdkpath(s);
# endif

#ਨਹੀਂਤਾਂ
    /* paths for crt objects */
    tcc_ਵੰਡੋ_ਰਸਤਾ(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ਜੇ (output_type != TCC_OUTPUT_ਸਮ੍ਰਿਤੀ && !s->nostdlib)
        tccelf_ਜੋੜੋ_crtbegin(s); /* may produce errors */
#ਜੇ_ਅੰਤ
    ਵਾਪਸ s->nb_errors ? -1 : 0;
}

LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_include_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname)
{
    tcc_ਵੰਡੋ_ਰਸਤਾ(s, &s->include_paths, &s->nb_include_paths, pathname);
    ਵਾਪਸ 0;
}

LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_sysinclude_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname)
{
    tcc_ਵੰਡੋ_ਰਸਤਾ(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    ਵਾਪਸ 0;
}

LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_library_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *pathname)
{
    tcc_ਵੰਡੋ_ਰਸਤਾ(s, &s->library_paths, &s->nb_library_paths, pathname);
    ਵਾਪਸ 0;
}

LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_lib_ਰਸਤਾ(TCCState *s, ਅਚਲ ਅੱਖਰ *ਰਸਤਾ)
{
    tcc_ਸੈੱਟ_str(&s->tcc_lib_ਰਸਤਾ, ਰਸਤਾ);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_ਜੋੜੋ_dllref(TCCState *s1, ਅਚਲ ਅੱਖਰ *dllname, ਪੂਰਨ level)
{
    DLLReference *ref = ਨਿਰਾ;
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < s1->nb_loaded_dlls; i++)
        ਜੇ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ਰੋਕੋ;
        }
    ਜੇ (level == -1)
        ਵਾਪਸ ref;
    ਜੇ (ref) {
        ਜੇ (level < ref->level)
            ref->level = level;
        ref->ਮਿਲਿਆ = 1;
        ਵਾਪਸ ref;
    }
    ref = tcc_mallocz(ਆਕਾਰ(DLLReference) + ਲੜੀ_ਲੰਬਾਈ(dllname));
    strcpy(ref->name, dllname);
    dynarray_ਜੋੜੋ(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->ਸੂਚਕਾਂਕ = s1->nb_loaded_dlls;
    ਵਾਪਸ ref;
}

ਸਥਿਰ ਪੂਰਨ tcc_ਜੋੜੋ_ਦੁਆਧਾਰੀ(TCCState *s1, ਪੂਰਨ flags, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ fd)
{
    ElfW(Ehdr) ehdr;
    ਪੂਰਨ obj_type;
    ਅਚਲ ਅੱਖਰ *saved_filename = s1->current_filename;
    ਪੂਰਨ ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    ਚੋਣ (obj_type) {

    ਹਾਲਤ AFF_BINTYPE_REL:
        ret = tcc_ਲੱਦੋ_object_file(s1, fd, 0);
        ਰੋਕੋ;

    ਹਾਲਤ AFF_BINTYPE_AR:
        ret = tcc_ਲੱਦੋ_archive(s1, fd, !(flags & AFF_ਸਾਰਾ_ARCHIVE));
        ਰੋਕੋ;

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_UNIX
    ਹਾਲਤ AFF_BINTYPE_DYN:
        ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
            ਖਾਲੀ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ਜੇ (dl)
                tcc_ਜੋੜੋ_dllref(s1, filename, 0)->handle = dl;
            ਨਹੀਂਤਾਂ
                ret = FILE_NOT_RECOGNIZED;
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ
            ret = tcc_ਲੱਦੋ_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ਰੋਕੋ;

    ਮੂਲ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_ਲੱਦੋ_ldscript(s1, fd);
        ਰੋਕੋ;

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
    ਹਾਲਤ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ਜੇ (s1->output_type == TCC_OUTPUT_ਸਮ੍ਰਿਤੀ) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
            ਖਾਲੀ* dl;
            ਅਚਲ ਅੱਖਰ* soname = filename;
            ਅੱਖਰ *tmp = 0;
            ਜੇ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ਜੇ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ਜੇ (dl)
                tcc_ਜੋੜੋ_dllref(s1, soname, 0)->handle = dl;
            ਨਹੀਂਤਾਂ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ ਜੇ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_ਲੱਦੋ_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ਨਹੀਂਤਾਂ {
            ret = macho_ਲੱਦੋ_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ਜੇ (ret)
            ret = FILE_NOT_RECOGNIZED;
        ਰੋਕੋ;

    ਮੂਲ:
    {
        ਅਚਲ ਅੱਖਰ *ext = tcc_fileextension(filename);
        ਜੇ (!strcmp(ext, ".tbd"))
            ਜਾਓ case_dyn_or_tbd;
        ਜੇ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            ਜਾਓ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ਰੋਕੋ;
    }

#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE
    ਮੂਲ:
        ਜੇ (pe_ਲੱਦੋ_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_COFF
    ਹਾਲਤ AFF_BINTYPE_C67:
        ret = tcc_ਲੱਦੋ_coff(s1, fd);
        ਰੋਕੋ;
#ਜੇ_ਅੰਤ
    }

    close(fd);
    s1->current_filename = saved_filename;
    ਜੇ (ret == FILE_NOT_RECOGNIZED)
        ਵਾਪਸ tcc_error_noabort("%s: unrecognized file type", filename);
    ਵਾਪਸ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ਜੇ defined TARGETOS_OpenBSD && !defined _WIN32
#ਅਨ੍ਤਰ੍ਭਾਵ <glob.h>
ਸਥਿਰ ਪੂਰਨ tcc_glob_so(TCCState *s1, ਅਚਲ ਅੱਖਰ *ਨਮੂਨਾ, ਅੱਖਰ *buf, ਪੂਰਨ ਮਾਪ)
{
    ਅਚਲ ਅੱਖਰ *ਤਾਰਾ;
    glob_t g;
    ਅੱਖਰ *p;
    ਪੂਰਨ i, v, v1, v2, v3;

    ਤਾਰਾ = strchr(ਨਮੂਨਾ, '*');
    ਜੇ (!ਤਾਰਾ || glob(ਨਮੂਨਾ, 0, ਨਿਰਾ, &g))
        ਵਾਪਸ -1;
    ਲਈ (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ਜੇ (2 != ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ(p + (ਤਾਰਾ - ਨਮੂਨਾ), "%d.%d.%d", &v1, &v2, &v3))
            ਜਾਰੀ;
        ਜੇ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, ਮਾਪ, p);
    }
    globfree(&g);
    ਵਾਪਸ v;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ guess_filetype(ਅਚਲ ਅੱਖਰ *filename)
{
    ਪੂਰਨ filetype = 0;
    ਜੇ (1) {
        /* use a file extension to detect a filetype */
        ਅਚਲ ਅੱਖਰ *ext = tcc_fileextension(filename);
        ਜੇ (ext[0]) {
            ext++;
            ਜੇ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ਨਹੀਂਤਾਂ ਜੇ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ਨਹੀਂਤਾਂ ਜੇ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ਨਹੀਂਤਾਂ
                filetype |= AFF_TYPE_BIN;
        } ਨਹੀਂਤਾਂ {
            filetype = AFF_TYPE_C;
        }
    }
    ਵਾਪਸ filetype;
}

ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_file_ਅੰਦਰੂਨੀ(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flags)
{
    ਪੂਰਨ fd;

#ਜੇ defined TARGETOS_OpenBSD && !defined _WIN32
    ਅੱਖਰ buf[1024];
    ਜੇ (tcc_glob_so(s1, filename, buf, ਆਕਾਰ buf) >= 0)
        filename = buf;
#ਜੇ_ਅੰਤ

    ਜੇ (0 == (flags & AFF_TYPE_ਨਕਾਬ))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ਜੇ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        ਵਾਪਸ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ਜੇ (fd < 0) {
        ਜੇ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        ਵਾਪਸ FILE_NOT_ਮਿਲਿਆ;
    }

    ਜੇ (flags & AFF_TYPE_BIN)
        ਵਾਪਸ tcc_ਜੋੜੋ_ਦੁਆਧਾਰੀ(s1, flags, filename, fd);

    dynarray_ਜੋੜੋ(&s1->ਨਿਸ਼ਾਨਾ_deps, &s1->nb_ਨਿਸ਼ਾਨਾ_deps, tcc_strdup(filename));
    ਵਾਪਸ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_file(TCCState *s, ਅਚਲ ਅੱਖਰ *filename)
{
    ਵਾਪਸ tcc_ਜੋੜੋ_file_ਅੰਦਰੂਨੀ(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ਸਥਿਰ ਪੂਰਨ tcc_ਜੋੜੋ_library_ਅੰਦਰੂਨੀ(TCCState *s1, ਅਚਲ ਅੱਖਰ *fmt,
    ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flags, ਅੱਖਰ **paths, ਪੂਰਨ nb_paths)
{
    ਅੱਖਰ buf[1024];
    ਪੂਰਨ i, ret;

    ਲਈ(i = 0; i < nb_paths; i++) {
        snprintf(buf, ਆਕਾਰ(buf), fmt, paths[i], filename);
        ret = tcc_ਜੋੜੋ_file_ਅੰਦਰੂਨੀ(s1, buf, flags & ~AFF_PRINT_ERROR);
        ਜੇ (ret != FILE_NOT_ਮਿਲਿਆ)
            ਵਾਪਸ ret;
    }
    ਜੇ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    ਵਾਪਸ FILE_NOT_ਮਿਲਿਆ;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_dll(TCCState *s, ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flags)
{
    ਵਾਪਸ tcc_ਜੋੜੋ_library_ਅੰਦਰੂਨੀ(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_support(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਅੱਖਰ buf[100];
    ਜੇ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    ਵਾਪਸ tcc_ਜੋੜੋ_dll(s1, filename, AFF_PRINT_ERROR);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_UNIX
ST_FUNC ਪੂਰਨ tcc_ਜੋੜੋ_crt(TCCState *s1, ਅਚਲ ਅੱਖਰ *filename)
{
    ਵਾਪਸ tcc_ਜੋੜੋ_library_ਅੰਦਰੂਨੀ(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#ਜੇ_ਅੰਤ

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ਪੂਰਨ tcc_ਜੋੜੋ_library(TCCState *s, ਅਚਲ ਅੱਖਰ *libraryname)
{
    ਸਥਿਰ ਅਚਲ ਅੱਖਰ * ਅਚਲ libs[] = {
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#ਜਾਂਜੇ defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ਨਹੀਂਤਾਂ
        "%s/lib%s.so",
#ਜੇ_ਅੰਤ
        "%s/lib%s.a",
        ਨਿਰਾ
    };
    ਪੂਰਨ flags = AFF_TYPE_LIB | (s->filetype & AFF_ਸਾਰਾ_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ਜੇ (*libraryname == ':') {
        libraryname++;
    } ਨਹੀਂਤਾਂ {
        ਅਚਲ ਅੱਖਰ * ਅਚਲ *pp = libs;
        ਜੇ (s->static_link)
            pp += ਆਕਾਰ(libs) / ਆਕਾਰ(*libs) - 2; /* only "%s/lib%s.a" */
        ਜਦੋਂ (*pp) {
            ਪੂਰਨ ret = tcc_ਜੋੜੋ_library_ਅੰਦਰੂਨੀ(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ਜੇ (ret != FILE_NOT_ਮਿਲਿਆ)
                ਵਾਪਸ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    ਵਾਪਸ tcc_ਜੋੜੋ_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC ਖਾਲੀ tcc_ਜੋੜੋ_pragma_libs(TCCState *s1)
{
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_ਜੋੜੋ_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ਸਥਿਰ ਪੂਰਨ strstart(ਅਚਲ ਅੱਖਰ *val, ਅਚਲ ਅੱਖਰ **str)
{
    ਅਚਲ ਅੱਖਰ *p, *q;
    p = *str;
    q = val;
    ਜਦੋਂ (*q) {
        ਜੇ (*p != *q)
            ਵਾਪਸ 0;
        p++;
        q++;
    }
    *str = p;
    ਵਾਪਸ 1;
}

ਬਣਤਰ lopt {
    TCCState *s;
    ਅਚਲ ਅੱਖਰ *opt, *arg;
    ਪੂਰਨ ਮੇਲ;
};

/* match linker option */
ਸਥਿਰ ਪੂਰਨ link_option(ਬਣਤਰ lopt *o, ਅਚਲ ਅੱਖਰ *q)
{
    ਅਚਲ ਅੱਖਰ *p;
    ਪੂਰਨ c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ਜੇ (*p++ != '-')
        ਵਾਪਸ 0;
    ਜੇ (*p == '-')
        p++;
    r = 1;
    ਜੇ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ਜੇ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        ਨਹੀਂਤਾਂ ਜੇ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#ਜੇ_ਅੰਤ
    }
    ਜਦੋਂ ((c = *q) == *p) {
        ਜੇ (c == '\0')
            ਜਾਓ succ; /* -Wl,-opt */
        ++p;
        ਜੇ (c == '=')
            ਜਾਓ succ; /* -Wl,-opt=arg */
        ++q;
    }
    ਜੇ (*p == '\0') {
        ਜੇ (c == '|')
            ਜਾਓ succ;
        ਜੇ (c == '=' || c == ':') {
            ਜੇ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                ਜਾਓ succ; /* -Wl,-opt,arg */
            }
            o->ਮੇਲ = 1; /* -Wl,-opt -Wl,arg */
            ਵਾਪਸ 0;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (c == ':')
        ਜਾਓ succ; /* -Wl,-Iarg */
    ਜਦੋਂ (*q)
        ਜੇ (*q++ == '|')
            ਜਾਓ redo;
    ਵਾਪਸ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    ਵਾਪਸ r;
}

ਸਥਿਰ ਖਾਲੀ ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(TCCState *s, ਅਚਲ ਅੱਖਰ* filename, ਪੂਰਨ filetype);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ਸਥਿਰ ਪੂਰਨ tcc_ਸੈੱਟ_linker(TCCState *s, ਅਚਲ ਅੱਖਰ *optarg)
{
    TCCState *s1 = s;

    dynarray_ਵੰਡੋ(&s1->link_argv, &s1->link_argc, optarg, ',');

    ਜਦੋਂ (s->link_optind < s->link_argc) {
        ਅੱਖਰ *ਸਿਰਾ = ਨਿਰਾ;
        ਪੂਰਨ ignoring = 0;
        ਬਣਤਰ lopt o = {0};
        ਪੂਰਨ r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ਜੇ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "e=|entry=")) {
            tcc_ਸੈੱਟ_str(&s->elf_entryname, o.arg);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "image-base=|Ttext=")) {
            s->ਪਾਠ_addr = strtoull(o.arg, &ਸਿਰਾ, 16);
            s->has_ਪਾਠ_addr = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "init=")) {
            tcc_ਸੈੱਟ_str(&s->init_ਚਿੰਨ੍ਹ, o.arg);
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "fini=")) {
            tcc_ਸੈੱਟ_str(&s->fini_ਚਿੰਨ੍ਹ, o.arg);
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "Map=")) {
            tcc_ਸੈੱਟ_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "oformat=")) {
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_PE
            ਜੇ (0 == ਲੜੀ_ਤੁਲਨਾ("pe-", o.arg, 3))
#ਜਾਂਜੇ PTR_ਮਾਪ == 8
            ਜੇ (0 == ਲੜੀ_ਤੁਲਨਾ("elf64-", o.arg, 6))
#ਨਹੀਂਤਾਂ
            ਜੇ (0 == ਲੜੀ_ਤੁਲਨਾ("elf32-", o.arg, 6))
#ਜੇ_ਅੰਤ
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ਨਹੀਂਤਾਂ ਜੇ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ਦੁਆਧਾਰੀ;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_COFF
            ਨਹੀਂਤਾਂ ਜੇ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#ਜੇ_ਅੰਤ
            ਨਹੀਂਤਾਂ
                ਜਾਓ err;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_ਸੈੱਟ_str(&s->elfint, o.arg);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &ਸਿਰਾ, 16);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "soname=|install_name=")) {
            tcc_ਸੈੱਟ_str(&s->soname, o.arg);
        } ਨਹੀਂਤਾਂ ਜੇ (!!(r = link_option(&o, "?whole-archive"))) {
            ਸੈੱਟ_OR_CLEAR(s->filetype, AFF_ਸਾਰਾ_ARCHIVE);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ਨਹੀਂਤਾਂ ਜੇ (!!(r = link_option(&o, "?dynamicbase"))) {
            ਸੈੱਟ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ਨਹੀਂਤਾਂ ਜੇ (!!(r = link_option(&o, "?high-entropy-va"))) {
            ਸੈੱਟ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ਨਹੀਂਤਾਂ ਜੇ (!!(r = link_option(&o, "?nxcompat"))) {
            ਸੈੱਟ_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ਨਹੀਂਤਾਂ ਜੇ (!!(r = link_option(&o, "?tsaware"))) {
            ਸੈੱਟ_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &ਸਿਰਾ, 16);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "stack=")) {
            s->pe_ਢੇਰ_ਮਾਪ = strtoul(o.arg, &ਸਿਰਾ, 10);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "subsystem=")) {
            ਜੇ (pe_setsubsy(s, o.arg) < 0)
                ਜਾਓ err;
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_ਸਾਰਾ_ARCHIVE;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "force_load=")) {
            ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(s, o.arg, AFF_TYPE_LIB | AFF_ਸਾਰਾ_ARCHIVE);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "single_module")) {
            ignoring = 1;
#ਜੇ_ਅੰਤ
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "O")) {
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "z=")) {
            ignoring = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "L:")) {
            tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, o.arg);
        } ਨਹੀਂਤਾਂ ਜੇ (link_option(&o, "l:")) {
            ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ਨਕਾਬ));
        } ਨਹੀਂਤਾਂ ਜੇ (o.ਮੇਲ) {
            ਵਾਪਸ 0; /* expecting argument with next '-Wl,' */
        } ਨਹੀਂਤਾਂ {
    err:
            ਵਾਪਸ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ਜੇ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    ਵਾਪਸ 0;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TCCOption {
    ਅਚਲ ਅੱਖਰ *name;
    uint16_t ਸੂਚਕਾਂਕ;
    uint16_t flags;
} TCCOption;

ਗਿਣਤੀ {
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
    TCC_OPTION_print_ਖੋਜ_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_ਲੜੀਵਾਰ,
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
    TCC_OPTION_compatibility_ਸੰਸਕਰਣ ,
    TCC_OPTION_current_ਸੰਸਕਰਣ,
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OPTION_HAS_ARG 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

ਸਥਿਰ ਅਚਲ TCCOption tcc_options[] = {
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
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#ਜੇ_ਅੰਤ
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_ਸੰਸਕਰਣ, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_ਸੰਸਕਰਣ, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#ਜੇ_ਅੰਤ
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
    { "run", TCC_OPTION_ਲੜੀਵਾਰ, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#ਜੇ_ਅੰਤ
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_ਖੋਜ_dirs, 0 },
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
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    { "impdef", TCC_OPTION_impdef, 0},
#ਜੇ_ਅੰਤ
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
    { ਨਿਰਾ, 0, 0 },
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ FlagDef {
    uint16_t ਵਿੱਥ;
    uint16_t flags;
    ਅਚਲ ਅੱਖਰ *name;
} FlagDef;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WD_ALL    0x0001 /* warning is activated when using -Wall */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_INVERT 0x0002 /* invert value before storing */

ਸਥਿਰ ਅਚਲ FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_ਲੜੀਆਂ), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ਨਿਰਾ }
};

ਸਥਿਰ ਅਚਲ FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_ਵਿੱਚ_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, ਉਲਟ_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, ਨਿਰਾ }
};

ਸਥਿਰ ਅਚਲ FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#ਜੇ_ਅੰਤ
    { 0, 0, ਨਿਰਾ }
};

ਸਥਿਰ ਪੂਰਨ ਸੈੱਟ_flag(TCCState *s, ਅਚਲ FlagDef *flags, ਅਚਲ ਅੱਖਰ *name)
{
    ਪੂਰਨ ਮੁੱਲ, ਨਕਾਬ, ret;
    ਅਚਲ FlagDef *p;
    ਅਚਲ ਅੱਖਰ *r;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *f;

    r = name, ਮੁੱਲ = !strstart("no-", &r), ਨਕਾਬ = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ਜੇ ((flags->flags & WD_ALL) && strstart("error=", &r))
        ਮੁੱਲ = ਮੁੱਲ ? WARN_ON|WARN_ERR : WARN_NOE, ਨਕਾਬ = WARN_ON;

    ਲਈ (ret = -1, p = flags; p->name; ++p) {
        ਜੇ (ret) {
            ਜੇ (strcmp(r, p->name))
                ਜਾਰੀ;
        } ਨਹੀਂਤਾਂ {
            ਜੇ (0 == (p->flags & WD_ALL))
                ਜਾਰੀ;
        }

        f = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)s + p->ਵਿੱਥ;
        *f = (*f & ਨਕਾਬ) | (ਮੁੱਲ ^ !!(p->flags & FD_INVERT));

        ਜੇ (ret) {
            ret = 0;
            ਜੇ (strcmp(r, "all"))
                ਰੋਕੋ;
        }
    }
    ਵਾਪਸ ret;
}

ਸਥਿਰ ਅਚਲ ਅੱਖਰ dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_I386
    "i386-pc"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
    "x86_64-pc"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_C67
    "c67"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM
    "arm"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_ARM64
    "aarch64"
#ਜਾਂਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    "riscv64"
#ਜੇ_ਅੰਤ
    "-"
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    "mingw32"
#ਜਾਂਜੇ defined(TCC_ਨਿਸ਼ਾਨਾ_MACHO)
    "apple-darwin"
#ਜਾਂਜੇ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#ਜਾਂਜੇ TARGETOS_OpenBSD
    "openbsd"
#ਜਾਂਜੇ TARGETOS_NetBSD
    "netbsd"
#ਜਾਂਜੇ CONFIG_TCC_MUSL
    "linux-musl"
#ਨਹੀਂਤਾਂ
    "linux-gnu"
#ਜੇ_ਅੰਤ
;

#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
ਸਥਿਰ uint32_t parse_ਸੰਸਕਰਣ(TCCState *s1, ਅਚਲ ਅੱਖਰ *ਸੰਸਕਰਣ)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    ਅੱਖਰ* ਆਖਰੀ;

    a = strtoul(ਸੰਸਕਰਣ, &ਆਖਰੀ, 10);
    ਜੇ (*ਆਖਰੀ == '.') {
        b = strtoul(&ਆਖਰੀ[1], &ਆਖਰੀ, 10);
        ਜੇ (*ਆਖਰੀ == '.')
             c = strtoul(&ਆਖਰੀ[1], &ਆਖਰੀ, 10);
    }
    ਜੇ (*ਆਖਰੀ || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", ਸੰਸਕਰਣ);
    ਵਾਪਸ (a << 16) | (b << 8) | c;
}
#ਜੇ_ਅੰਤ

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ਸਥਿਰ ਖਾਲੀ ਪਾਓ_ਦਲੀਲਾਂ(TCCState *s1, ਅੱਖਰ ***pargv, ਪੂਰਨ *pargc, ਪੂਰਨ optind, ਅਚਲ ਅੱਖਰ *p, ਪੂਰਨ sep)
{
    ਪੂਰਨ argc = 0;
    ਅੱਖਰ **argv = ਨਿਰਾ;
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < *pargc; ++i)
        ਜੇ (i == optind)
            dynarray_ਵੰਡੋ(&argv, &argc, p, sep);
        ਨਹੀਂਤਾਂ
            dynarray_ਜੋੜੋ(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ਸਥਿਰ ਖਾਲੀ ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(TCCState *s, ਅਚਲ ਅੱਖਰ* filename, ਪੂਰਨ filetype)
{
    ਬਣਤਰ filespec *f = tcc_malloc(ਆਕਾਰ *f + ਲੜੀ_ਲੰਬਾਈ(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_ਜੋੜੋ(&s->files, &s->nb_files, f);
    ਜੇ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC ਪੂਰਨ tcc_parse_ਦਲੀਲਾਂ(TCCState *s, ਪੂਰਨ *pargc, ਅੱਖਰ ***pargv)
{
    TCCState *s1 = s;
    ਅਚਲ TCCOption *popt;
    ਅਚਲ ਅੱਖਰ *optarg, *r;
    ਅਚਲ ਅੱਖਰ *ਲੜੀਵਾਰ = ਨਿਰਾ;
    ਪੂਰਨ optind = 1, ਖਾਲੀ_ਥਾਵਾਂ = 1, x;
    ਅੱਖਰ **argv = *pargv;
    ਪੂਰਨ argc = *pargc;

    s->link_optind = s->link_argc;

    ਜਦੋਂ (optind < argc) {
        r = argv[optind];
        ਜੇ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            ਪੂਰਨ fd; ਅੱਖਰ *p;
            fd = open(++r, O_RDONLY | O_ਦੁਆਧਾਰੀ_2);
            ਜੇ (fd < 0)
                ਵਾਪਸ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_ਲੱਦੋ_ਪਾਠ(fd);
            ਪਾਓ_ਦਲੀਲਾਂ(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ਜਾਰੀ;
        }
        optind++;
        ਜੇ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(s, r, s->filetype);
            ਖਾਲੀ_ਥਾਵਾਂ = 0;
        dorun:
            ਜੇ (ਲੜੀਵਾਰ)
                ਰੋਕੋ;
            ਜਾਰੀ;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ਜੇ (r[1] == '-' && r[2] == '\0')
            ਜਾਓ dorun;

        /* find option in table */
        ਲਈ(popt = tcc_options; ; ++popt) {
            ਅਚਲ ਅੱਖਰ *p1 = popt->name;
            ਅਚਲ ਅੱਖਰ *r1 = r + 1;
            ਜੇ (p1 == ਨਿਰਾ)
                ਵਾਪਸ tcc_error_noabort("invalid option -- '%s'", r);
            ਜੇ (!strstart(p1, &r1))
                ਜਾਰੀ;
            optarg = r1;
            ਜੇ (popt->flags & TCC_OPTION_HAS_ARG) {
                ਜੇ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ਜੇ (optind >= argc)
                        ਵਾਪਸ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ਨਹੀਂਤਾਂ ਜੇ (*r1 != '\0')
                ਜਾਰੀ;
            ਰੋਕੋ;
        }

        ਚੋਣ(popt->ਸੂਚਕਾਂਕ) {
        ਹਾਲਤ TCC_OPTION_I:
            tcc_ਜੋੜੋ_include_ਰਸਤਾ(s, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_D:
            tcc_define_ਚਿੰਨ੍ਹ(s, optarg, ਨਿਰਾ);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_U:
            tcc_undefine_ਚਿੰਨ੍ਹ(s, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_L:
            tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_ਸੈੱਟ_lib_ਰਸਤਾ(s, optarg);
            ਜਾਰੀ;
        ਹਾਲਤ TCC_OPTION_l:
            ਦਲੀਲਾਂ_parser_ਜੋੜੋ_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ਨਕਾਬ));
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_pthread:
            s->option_pthread = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_bench:
            s->do_bench = 1;
            ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
        ਹਾਲਤ TCC_OPTION_bt:
            s->rt_ਅੰਕ_callers = atoi(optarg); /* zero = default (6) */
            ਜਾਓ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ਜੇ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_ਸੰਸਕਰਣ;
            ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਹਾਲਤ TCC_OPTION_b:
            s->do_bounds_check = 1;
            ਜਾਓ enable_backtrace;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
        ਹਾਲਤ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_ਸੰਸਕਰਣ;
        g_redo:
            ਜੇ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_ਸੰਸਕਰਣ;
            } ਨਹੀਂਤਾਂ ਜੇ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ਨਹੀਂਤਾਂ ਜੇ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                ਜਾਓ g_redo;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
            } ਨਹੀਂਤਾਂ ਜੇ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#ਜੇ_ਅੰਤ
            }
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        ਸੈੱਟ_output_type:
            ਜੇ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_d:
            ਜੇ (*optarg == 'D')
                s->dflag = 3;
            ਨਹੀਂਤਾਂ ਜੇ (*optarg == 'M')
                s->dflag = 7;
            ਨਹੀਂਤਾਂ ਜੇ (*optarg == 't')
                s->dflag = 16;
            ਨਹੀਂਤਾਂ ਜੇ (isnum(*optarg))
                g_debug |= atoi(optarg);
            ਨਹੀਂਤਾਂ
                ਜਾਓ unsupported_option;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_static:
            s->static_link = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_std:
            ਜੇ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            ਜਾਓ ਸੈੱਟ_output_type;
        ਹਾਲਤ TCC_OPTION_soname:
            tcc_ਸੈੱਟ_str(&s->soname, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_o:
            ਜੇ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_ਸੈੱਟ_str(&s->outfile, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            ਜਾਓ ਸੈੱਟ_output_type;
        ਹਾਲਤ TCC_OPTION_isystem:
            tcc_ਜੋੜੋ_sysinclude_ਰਸਤਾ(s, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_ਲੜੀਵਾਰ:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            ਲੜੀਵਾਰ = optarg;
            x = TCC_OUTPUT_ਸਮ੍ਰਿਤੀ;
            ਜਾਓ ਸੈੱਟ_output_type;
#ਨਹੀਂਤਾਂ
            ਵਾਪਸ tcc_error_noabort("-run is not available in a cross compiler");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
        ਹਾਲਤ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->ਲੜੀਵਾਰ_stdin = optarg;
            ਰੋਕੋ;
#ਜੇ_ਅੰਤ
        ਹਾਲਤ TCC_OPTION_v:
            ਕਰੋ ++s->verbose; ਜਦੋਂ (*optarg++ == 'v');
            ਜਾਰੀ;
        ਹਾਲਤ TCC_OPTION_f:
            ਜੇ (ਸੈੱਟ_flag(s, options_f, optarg) < 0)
                ਜਾਓ unsupported_option;
            ਰੋਕੋ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_ARM
        ਹਾਲਤ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ਜੇ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ਨਹੀਂਤਾਂ ਜੇ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ਨਹੀਂਤਾਂ
                ਵਾਪਸ tcc_error_noabort("unsupported float abi '%s'", optarg);
            ਜਾਰੀ;
#ਜੇ_ਅੰਤ
        ਹਾਲਤ TCC_OPTION_m:
            ਜੇ (ਸੈੱਟ_flag(s, options_m, optarg) < 0) {
                ਜੇ (x = atoi(optarg), x != 32 && x != 64)
                    ਜਾਓ unsupported_option;
                ਜੇ (PTR_ਮਾਪ != x/8)
                    ਵਾਪਸ x;
                ਜਾਰੀ;
            }
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_W:
            ਜੇ (optarg[0] && ਸੈੱਟ_flag(s, options_W, optarg) < 0)
                ਜਾਓ unsupported_option;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_w:
            s->warn_none = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_Wl:
            ਜੇ (tcc_ਸੈੱਟ_linker(s, optarg) < 0)
                ਵਾਪਸ -1;
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_Wp:
            ਜੇ (argv[0]) /* not with tcc_set_options() */
                ਪਾਓ_ਦਲੀਲਾਂ(s, &argv, &argc, --optind, optarg, ',');
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            ਜਾਓ ਸੈੱਟ_output_type;
        ਹਾਲਤ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ਰੋਕੋ;

        ਹਾਲਤ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        ਹਾਲਤ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ਜੇ (!s->deps_outfile)
                tcc_ਸੈੱਟ_str(&s->deps_outfile, "-");
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        ਹਾਲਤ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ਜੇ (*optarg != ',')
                ਰੋਕੋ;
            ++optarg;
            // fall through
        ਹਾਲਤ TCC_OPTION_MF:
            tcc_ਸੈੱਟ_str(&s->deps_outfile, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ਰੋਕੋ;

        ਹਾਲਤ TCC_OPTION_dumpmachine:
            ਲਿਖੋ("%s\n", dumpmachine_str);
            ਬਾਹਰ_ਨਿਕਲੋ(0);
        ਹਾਲਤ TCC_OPTION_dumpversion:
            ਲਿਖੋ ("%s\n", TCC_ਸੰਸਕਰਣ);
            ਬਾਹਰ_ਨਿਕਲੋ(0);

        ਹਾਲਤ TCC_OPTION_x:
            x = 0;
            ਜੇ (*optarg == 'c')
                x = AFF_TYPE_C;
            ਨਹੀਂਤਾਂ ਜੇ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ਨਹੀਂਤਾਂ ਜੇ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ਨਹੀਂਤਾਂ ਜੇ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ਨਹੀਂਤਾਂ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_ਨਕਾਬ);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ਰੋਕੋ;
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
        ਹਾਲਤ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            ਜਾਓ ਸੈੱਟ_output_type;
        ਹਾਲਤ TCC_OPTION_flat_namespace:
	     ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_two_levelnamespace:
	     ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_undefined:
	     ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_install_name:
	    tcc_ਸੈੱਟ_str(&s->install_name, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_compatibility_ਸੰਸਕਰਣ:
	    s->compatibility_ਸੰਸਕਰਣ = parse_ਸੰਸਕਰਣ(s, optarg);
            ਰੋਕੋ;
        ਹਾਲਤ TCC_OPTION_current_ਸੰਸਕਰਣ:
	    s->current_ਸੰਸਕਰਣ = parse_ਸੰਸਕਰਣ(s, optarg);;
            ਰੋਕੋ;
#ਜੇ_ਅੰਤ
        ਹਾਲਤ TCC_OPTION_HELP:
            x = OPT_HELP;
            ਜਾਓ extra_action;
        ਹਾਲਤ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            ਜਾਓ extra_action;
        ਹਾਲਤ TCC_OPTION_print_ਖੋਜ_dirs:
            x = OPT_PRINT_DIRS;
            ਜਾਓ extra_action;
        ਹਾਲਤ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            ਜਾਓ extra_action;
        ਹਾਲਤ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ਜੇ (ਨਿਰਾ == argv[0]) /* from tcc_set_options() */
                ਵਾਪਸ -1;
            ਜੇ (!ਖਾਲੀ_ਥਾਵਾਂ && x)
                ਵਾਪਸ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            ਵਾਪਸ x;
        ਮੂਲ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ਰੋਕੋ;
        }
        ਖਾਲੀ_ਥਾਵਾਂ = 0;
    }
    ਜੇ (s->link_optind < s->link_argc)
        ਵਾਪਸ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ਜੇ (ਲੜੀਵਾਰ) {
        ਜੇ (*ਲੜੀਵਾਰ && tcc_ਸੈੱਟ_options(s, ਲੜੀਵਾਰ) < 0)
            ਵਾਪਸ -1;
        x = 0, r = 0;
        ਜਾਓ extra_action;
    }
    ਜੇ (!ਖਾਲੀ_ਥਾਵਾਂ)
        ਵਾਪਸ 0;
    ਜੇ (s->verbose == 2)
        ਵਾਪਸ OPT_PRINT_DIRS;
    ਜੇ (s->verbose)
        ਵਾਪਸ OPT_V;
    ਵਾਪਸ OPT_HELP;
}

LIBTCCAPI ਪੂਰਨ tcc_ਸੈੱਟ_options(TCCState *s, ਅਚਲ ਅੱਖਰ *r)
{
    ਅੱਖਰ **argv = ਨਿਰਾ;
    ਪੂਰਨ argc = 0, ret;
    dynarray_ਜੋੜੋ(&argv, &argc, 0);
    dynarray_ਵੰਡੋ(&argv, &argc, r, 0);
    ret = tcc_parse_ਦਲੀਲਾਂ(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    ਵਾਪਸ ret;
}

PUB_FUNC ਖਾਲੀ tcc_print_stats(TCCState *s1, ਬਿਨਾਨਿਸ਼ਾਨੀ ਕੁੱਲ_ਸਮਾਂ)
{
    ਜੇ (!ਕੁੱਲ_ਸਮਾਂ)
        ਕੁੱਲ_ਸਮਾਂ = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           ਕੁੱਲ_idents, ਕੁੱਲ_ਸਤਰਾਂ, ਕੁੱਲ_ਬਾਈਟਾਂ,
           (ਦੁੱਗਣਾ)ਕੁੱਲ_ਸਮਾਂ/1000,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ)ਕੁੱਲ_ਸਤਰਾਂ*1000/ਕੁੱਲ_ਸਮਾਂ,
           (ਦੁੱਗਣਾ)ਕੁੱਲ_ਬਾਈਟਾਂ/1000/ਕੁੱਲ_ਸਮਾਂ);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->ਕੁੱਲ_output[0],
           s1->ਕੁੱਲ_output[1],
           s1->ਕੁੱਲ_output[2],
           s1->ਕੁੱਲ_output[3]
           );
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE
    ਜੇ (s1->ਲੜੀਵਾਰ_ਮਾਪ) {
        Section *s = s1->symtab;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ms = s->ਅੰਕੜੇ_ਵਿੱਥ + s->link->ਅੰਕੜੇ_ਵਿੱਥ + s->hash->ਅੰਕੜੇ_ਵਿੱਥ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ rs = s1->ਲੜੀਵਾਰ_ਮਾਪ;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_ਮਾਪ - rs - ms);
    }
#ਜੇ_ਅੰਤ
    fprintf(stderr, " %d max (bytes)\n", mem_max_ਮਾਪ);
#ਜੇ_ਅੰਤ
}
