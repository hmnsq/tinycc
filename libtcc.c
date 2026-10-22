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

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ONE_ಮೂಲ
# define ONE_ಮೂಲ 1
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ ONE_ಮೂಲ
#ಅನ್ತರ್ಭಾವ "tccpp.c"
#ಅನ್ತರ್ಭಾವ "tccgen.c"
#ಅನ್ತರ್ಭಾವ "tccdbg.c"
#ಅನ್ತರ್ಭಾವ "tccasm.c"
#ಅನ್ತರ್ಭಾವ "tccelf.c"
#ಅನ್ತರ್ಭಾವ "tccrun.c"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
#ಅನ್ತರ್ಭಾವ "i386-gen.c"
#ಅನ್ತರ್ಭಾವ "i386-link.c"
#ಅನ್ತರ್ಭಾವ "i386-asm.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM)
#ಅನ್ತರ್ಭಾವ "arm-gen.c"
#ಅನ್ತರ್ಭಾವ "arm-link.c"
#ಅನ್ತರ್ಭಾವ "arm-asm.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_ARM64)
#ಅನ್ತರ್ಭಾವ "arm64-gen.c"
#ಅನ್ತರ್ಭಾವ "arm64-link.c"
#ಅನ್ತರ್ಭಾವ "arm64-asm.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_C67)
#ಅನ್ತರ್ಭಾವ "c67-gen.c"
#ಅನ್ತರ್ಭಾವ "c67-link.c"
#ಅನ್ತರ್ಭಾವ "tcccoff.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_X86_64)
#ಅನ್ತರ್ಭಾವ "x86_64-gen.c"
#ಅನ್ತರ್ಭಾವ "x86_64-link.c"
#ಅನ್ತರ್ಭಾವ "i386-asm.c"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_RISCV64)
#ಅನ್ತರ್ಭಾವ "riscv64-gen.c"
#ಅನ್ತರ್ಭಾವ "riscv64-link.c"
#ಅನ್ತರ್ಭಾವ "riscv64-asm.c"
#ಇಲ್ಲದಿದ್ದರೆ
#ದೋಷ unknown ಗುರಿ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
#ಅನ್ತರ್ಭಾವ "tccpe.c"
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_MACHO
#ಅನ್ತರ್ಭಾವ "tccmacho.c"
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ /* ONE_SOURCE */

#ಅನ್ತರ್ಭಾವ "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_ದತ್ತಾಂಶ ರಚನೆ TCCState *tcc_state;
TCC_SEM(ಸ್ಥಿರ tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_ದತ್ತಾಂಶ ಶೂನ್ಯ** stk_ದತ್ತಾಂಶ;
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ nb_stk_ದತ್ತಾಂಶ;
/* option -d<num> (for general development purposes) */
ST_ದತ್ತಾಂಶ ಪೂರ್ಣಾಂಕ g_debug;

/********************************************************/
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
ST_FUNC ಅಕ್ಷರ *normalize_slashes(ಅಕ್ಷರ *ಮಾರ್ಗ)
{
    ಅಕ್ಷರ *p;
    ಗಾಗಿ (p = ಮಾರ್ಗ; *p; ++p)
        ಆದರೆ (*p == '\\')
            *p = '/';
    ಹಿಂತಿರುಗಿ ಮಾರ್ಗ;
}

#ಆದರೆ defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ಸ್ಥಿರ HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    ಆದರೆ (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    ಹಿಂತಿರುಗಿ TRUE;
}
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_module ಖಾಲಿ /* NULL means executable itself */
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಅಕ್ಷರ *config_tccdir_w32(ಅಕ್ಷರ *ಮಾರ್ಗ)
{
    ಅಕ್ಷರ *p;
    GetModuleFileNameA(tcc_module, ಮಾರ್ಗ, MAX_ಮಾರ್ಗ);
    p = tcc_basename(normalize_slashes(strlwr(ಮಾರ್ಗ)));
    ಆದರೆ (p > ಮಾರ್ಗ)
        --p;
    *p = 0;
    ಹಿಂತಿರುಗಿ ಮಾರ್ಗ;
}
#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_ಮಾರ್ಗ))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
ಸ್ಥಿರ ಶೂನ್ಯ tcc_ಕೂಡಿಸು_systemdir(TCCState *s)
{
    ಅಕ್ಷರ buf[1000];
    GetSystemDirectoryA(buf, ಗಾತ್ರ buf);
    tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, normalize_slashes(buf));
}
#ಆದರೆ_ಅಂತ್ಯ
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *m) {
    ಹಿಂತಿರುಗಿ fopen(f, m);
}
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_fclose(FILE *f) {
    ಹಿಂತಿರುಗಿ fclose(f);
}
#ಆದರೆ_ಅಂತ್ಯ
/********************************************************/

PUB_FUNC ಶೂನ್ಯ tcc_enter_state(TCCState *s1)
{
    ಆದರೆ (s1->error_ಗಣ_jmp_enabled)
        ಹಿಂತಿರುಗಿ;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC ಶೂನ್ಯ tcc_exit_state(TCCState *s1)
{
    ಆದರೆ (s1->error_ಗಣ_jmp_enabled)
        ಹಿಂತಿರುಗಿ;
    tcc_state = ಖಾಲಿ;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC ಅಕ್ಷರ *pstrcpy(ಅಕ್ಷರ *buf, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಅಕ್ಷರ *q, *q_ಕೊನೆ;
    ಪೂರ್ಣಾಂಕ c;

    ಆದರೆ (buf_ಗಾತ್ರ > 0) {
        q = buf;
        q_ಕೊನೆ = buf + buf_ಗಾತ್ರ - 1;
        ಆಗ (q < q_ಕೊನೆ) {
            c = *s++;
            ಆದರೆ (c == '\0')
                ನಿಲ್ಲಿಸು;
            *q++ = c;
        }
        *q = '\0';
    }
    ಹಿಂತಿರುಗಿ buf;
}

/* strcat and truncate. */
ST_FUNC ಅಕ್ಷರ *pstrcat(ಅಕ್ಷರ *buf, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಗಾತ್ರ_t len;
    len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(buf);
    ಆದರೆ (len < buf_ಗಾತ್ರ)
        pstrcpy(buf + len, buf_ಗಾತ್ರ - len, s);
    ಹಿಂತಿರುಗಿ buf;
}

ST_FUNC ಅಕ್ಷರ *pstrncpy(ಅಕ್ಷರ *ಹೊರಹೋಗು, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s, ಗಾತ್ರ_t ಅಂಕೆ)
{
    ಆದರೆ (ಅಂಕೆ >= buf_ಗಾತ್ರ)
        ಅಂಕೆ = buf_ಗಾತ್ರ - 1;
    ಸ್ಮರಣೆ_ನಕಲು(ಹೊರಹೋಗು, s, ಅಂಕೆ);
    ಹೊರಹೋಗು[ಅಂಕೆ] = '\0';
    ಹಿಂತಿರುಗಿ ಹೊರಹೋಗು;
}

/* extract the basename of a file */
PUB_FUNC ಅಕ್ಷರ *tcc_basename(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ಅಕ್ಷರ *p = (ಅಕ್ಷರ *)strchr(name, 0);
    ಆಗ (p > name && !IS_DIRSEP(p[-1]))
        --p;
    ಹಿಂತಿರುಗಿ p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC ಅಕ್ಷರ *tcc_fileextension (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ಅಕ್ಷರ *b = tcc_basename(name);
    ಅಕ್ಷರ *e = strrchr(b, '.');
    ಹಿಂತಿರುಗಿ e ? e : strchr(b, 0);
}

ST_FUNC ಅಕ್ಷರ *tcc_ತುಂಬು_ಪಠ್ಯ(ಪೂರ್ಣಾಂಕ fd)
{
    ಪೂರ್ಣಾಂಕ len = lseek(fd, 0, SEEK_END);
    ಅಕ್ಷರ *buf = ತುಂಬು_ದತ್ತಾಂಶ(fd, 0, len + 1);
    buf[len] = 0;
    ಹಿಂತಿರುಗಿ buf;
}

/* replace *pp by copy of 'str' or NULL */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_ಗಣ_str(ಅಕ್ಷರ **pp, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : ಖಾಲಿ;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ಸ್ಥಿರ ಶೂನ್ಯ tcc_concat_str(ಅಕ್ಷರ **pp, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ sep)
{
    ಪೂರ್ಣಾಂಕ l = *pp ? ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str) + 1);
    ಆದರೆ (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು ಬಿಡುಗಡೆ
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು realloc

ಸ್ಥಿರ ಶೂನ್ಯ *default_reallocator(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಶೂನ್ಯ *ptr1;
    ಆದರೆ (ಗಾತ್ರ_2 == 0) {
        ಬಿಡುಗಡೆ(ptr);
        ptr1 = ಖಾಲಿ;
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        ptr1 = realloc(ptr, ಗಾತ್ರ_2);
        ಆದರೆ (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            ನಿರ್ಗಮಿಸು (1);
        }
    }
    ಹಿಂತಿರುಗಿ ptr1;
}

ST_FUNC ಶೂನ್ಯ libc_free(ಶೂನ್ಯ *ptr)
{
    ಬಿಡುಗಡೆ(ptr);
}

/* defined to be not used */
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಡುಗಡೆ(p) use_tcc_free(p)
#ವ್ಯಾಖ್ಯಾನಿಸು realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ಸ್ಥಿರ ಶೂನ್ಯ *(*reallocator)(ಶೂನ್ಯ*, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) = default_reallocator;

LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcc_free
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcc_malloc
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcc_realloc
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcc_mallocz
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು tcc_strdup

PUB_FUNC ಶೂನ್ಯ tcc_free(ಶೂನ್ಯ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC ಶೂನ್ಯ *tcc_malloc(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಹಿಂತಿರುಗಿ reallocator(0, ಗಾತ್ರ_2);
}

PUB_FUNC ಶೂನ್ಯ *tcc_realloc(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಹಿಂತಿರುಗಿ reallocator(ptr, ಗಾತ್ರ_2);
}

PUB_FUNC ಶೂನ್ಯ *tcc_mallocz(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2)
{
    ಶೂನ್ಯ *ptr;
    ptr = tcc_malloc(ಗಾತ್ರ_2);
    ಆದರೆ (ಗಾತ್ರ_2)
        memset(ptr, 0, ಗಾತ್ರ_2);
    ಹಿಂತಿರುಗಿ ptr;
}

PUB_FUNC ಅಕ್ಷರ *tcc_strdup(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಅಕ್ಷರ *ptr;
    ptr = tcc_malloc(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str) + 1);
    strcpy(ptr, str);
    ಹಿಂತಿರುಗಿ ptr;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ MEM_DEBUG

#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DEBUG_MAGIC1 0xFEEDDEB1
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DEBUG_MAGIC2 0xFEEDDEB2
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DEBUG_MAGIC3 0xFEEDDEB3
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DEBUG_FILE_LEN 40
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DEBUG_CHECK3(ಶೀರ್ಷಿಕೆ) \
    (((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *) ಶೀರ್ಷಿಕೆ->magic3) + ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_USER_PTR(ಶೀರ್ಷಿಕೆ) \
    ((ಅಕ್ಷರ *)ಶೀರ್ಷಿಕೆ + offsetof(mem_debug_ಶೀರ್ಷಿಕೆ_t, magic3))
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_ಶೀರ್ಷಿಕೆ_PTR(ptr) \
    (mem_debug_ಶೀರ್ಷಿಕೆ_t *)((ಅಕ್ಷರ*)ptr - offsetof(mem_debug_ಶೀರ್ಷಿಕೆ_t, magic3))

ರಚನೆ mem_debug_ಶೀರ್ಷಿಕೆ {
    ಚಿಹ್ನೆರಹಿತ magic1;
    ಚಿಹ್ನೆರಹಿತ ಗಾತ್ರ_2;
    ರಚನೆ mem_debug_ಶೀರ್ಷಿಕೆ *prev;
    ರಚನೆ mem_debug_ಶೀರ್ಷಿಕೆ *ಮುಂದಿನ;
    ಪೂರ್ಣಾಂಕ ಸಾಲು_ಅಂಕೆ;
    ಅಕ್ಷರ file_name[MEM_DEBUG_FILE_LEN];
    ಚಿಹ್ನೆರಹಿತ magic2;
    ALIGNED(16) ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ magic3[4];
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ mem_debug_ಶೀರ್ಷಿಕೆ mem_debug_ಶೀರ್ಷಿಕೆ_t;

TCC_SEM(ಸ್ಥಿರ mem_sem);
ಸ್ಥಿರ mem_debug_ಶೀರ್ಷಿಕೆ_t *mem_debug_chain;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ mem_cur_ಗಾತ್ರ;
ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ mem_max_ಗಾತ್ರ;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ nb_ಸ್ಥಿತಿಗಳು;

ಸ್ಥಿರ mem_debug_ಶೀರ್ಷಿಕೆ_t *malloc_check(ಶೂನ್ಯ *ptr, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
    mem_debug_ಶೀರ್ಷಿಕೆ_t * ಶೀರ್ಷಿಕೆ = MEM_ಶೀರ್ಷಿಕೆ_PTR(ptr);
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->magic1 != MEM_DEBUG_MAGIC1 ||
        ಶೀರ್ಷಿಕೆ->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(ಶೀರ್ಷಿಕೆ)) != MEM_DEBUG_MAGIC3 ||
        ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 == (ಚಿಹ್ನೆರಹಿತ)-1) {
        fprintf(stderr, "%s check failed\n", ಸಂದೇಶ);
        ಆದರೆ (ಶೀರ್ಷಿಕೆ->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                ಶೀರ್ಷಿಕೆ->file_name, ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ);
        ನಿರ್ಗಮಿಸು(1);
    }
    ಹಿಂತಿರುಗಿ ಶೀರ್ಷಿಕೆ;
}

PUB_FUNC ಶೂನ್ಯ *tcc_malloc_debug(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು)
{
    ಪೂರ್ಣಾಂಕ ofs;
    mem_debug_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ;
    ಆದರೆ (!ಗಾತ್ರ_2)
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    ಶೀರ್ಷಿಕೆ = tcc_malloc(ಗಾತ್ರ(mem_debug_ಶೀರ್ಷಿಕೆ_t) + ಗಾತ್ರ_2);
    ಶೀರ್ಷಿಕೆ->magic1 = MEM_DEBUG_MAGIC1;
    ಶೀರ್ಷಿಕೆ->magic2 = MEM_DEBUG_MAGIC2;
    ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
    write32le(MEM_DEBUG_CHECK3(ಶೀರ್ಷಿಕೆ), MEM_DEBUG_MAGIC3);
    ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ = ಸಾಲು;
    ofs = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(ಶೀರ್ಷಿಕೆ->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ = mem_debug_chain;
    ಶೀರ್ಷಿಕೆ->prev = ಖಾಲಿ;
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ)
        ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ->prev = ಶೀರ್ಷಿಕೆ;
    mem_debug_chain = ಶೀರ್ಷಿಕೆ;
    mem_cur_ಗಾತ್ರ += ಗಾತ್ರ_2;
    ಆದರೆ (mem_cur_ಗಾತ್ರ > mem_max_ಗಾತ್ರ)
        mem_max_ಗಾತ್ರ = mem_cur_ಗಾತ್ರ;
    POST_SEM(&mem_sem);
    ಹಿಂತಿರುಗಿ MEM_USER_PTR(ಶೀರ್ಷಿಕೆ);
}

PUB_FUNC ಶೂನ್ಯ tcc_free_debug(ಶೂನ್ಯ *ptr)
{
    mem_debug_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ;
    ಆದರೆ (!ptr)
        ಹಿಂತಿರುಗಿ;
    ಶೀರ್ಷಿಕೆ = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_ಗಾತ್ರ -= ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2;
    ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 = (ಚಿಹ್ನೆರಹಿತ)-1;
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ)
        ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ->prev = ಶೀರ್ಷಿಕೆ->prev;
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->prev)
        ಶೀರ್ಷಿಕೆ->prev->ಮುಂದಿನ = ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ;
    ಆದರೆ (ಶೀರ್ಷಿಕೆ == mem_debug_chain)
        mem_debug_chain = ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ;
    POST_SEM(&mem_sem);
    tcc_free(ಶೀರ್ಷಿಕೆ);
}

PUB_FUNC ಶೂನ್ಯ *tcc_mallocz_debug(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು)
{
    ಶೂನ್ಯ *ptr;
    ptr = tcc_malloc_debug(ಗಾತ್ರ_2,file,ಸಾಲು);
    ಆದರೆ (ಗಾತ್ರ_2)
        memset(ptr, 0, ಗಾತ್ರ_2);
    ಹಿಂತಿರುಗಿ ptr;
}

PUB_FUNC ಶೂನ್ಯ *tcc_realloc_debug(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಗಾತ್ರ_2, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು)
{
    mem_debug_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ;
    ಪೂರ್ಣಾಂಕ mem_debug_chain_update = 0;

    ಆದರೆ (!ptr)
        ಹಿಂತಿರುಗಿ tcc_malloc_debug(ಗಾತ್ರ_2, file, ಸಾಲು);
    ಆದರೆ (!ಗಾತ್ರ_2) {
        tcc_free_debug(ptr);
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    }
    ಶೀರ್ಷಿಕೆ = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_ಗಾತ್ರ -= ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2;
    mem_debug_chain_update = (ಶೀರ್ಷಿಕೆ == mem_debug_chain);
    ಶೀರ್ಷಿಕೆ = tcc_realloc(ಶೀರ್ಷಿಕೆ, ಗಾತ್ರ(mem_debug_ಶೀರ್ಷಿಕೆ_t) + ಗಾತ್ರ_2);
    ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2 = ಗಾತ್ರ_2;
    write32le(MEM_DEBUG_CHECK3(ಶೀರ್ಷಿಕೆ), MEM_DEBUG_MAGIC3);
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ)
        ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ->prev = ಶೀರ್ಷಿಕೆ;
    ಆದರೆ (ಶೀರ್ಷಿಕೆ->prev)
        ಶೀರ್ಷಿಕೆ->prev->ಮುಂದಿನ = ಶೀರ್ಷಿಕೆ;
    ಆದರೆ (mem_debug_chain_update)
        mem_debug_chain = ಶೀರ್ಷಿಕೆ;
    mem_cur_ಗಾತ್ರ += ಗಾತ್ರ_2;
    ಆದರೆ (mem_cur_ಗಾತ್ರ > mem_max_ಗಾತ್ರ)
        mem_max_ಗಾತ್ರ = mem_cur_ಗಾತ್ರ;
    POST_SEM(&mem_sem);
    ಹಿಂತಿರುಗಿ MEM_USER_PTR(ಶೀರ್ಷಿಕೆ);
}

PUB_FUNC ಅಕ್ಷರ *tcc_strdup_debug(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file, ಪೂರ್ಣಾಂಕ ಸಾಲು)
{
    ಅಕ್ಷರ *ptr;
    ptr = tcc_malloc_debug(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str) + 1, file, ಸಾಲು);
    strcpy(ptr, str);
    ಹಿಂತಿರುಗಿ ptr;
}

PUB_FUNC ಶೂನ್ಯ tcc_memcheck(ಪೂರ್ಣಾಂಕ d)
{
    WAIT_SEM(&mem_sem);
    nb_ಸ್ಥಿತಿಗಳು += d;
    ಆದರೆ (0 == nb_ಸ್ಥಿತಿಗಳು && mem_cur_ಗಾತ್ರ) {
        mem_debug_ಶೀರ್ಷಿಕೆ_t *ಶೀರ್ಷಿಕೆ = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_ಗಾತ್ರ, mem_max_ಗಾತ್ರ);
        ಆಗ (ಶೀರ್ಷಿಕೆ) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                ಶೀರ್ಷಿಕೆ->file_name, ಶೀರ್ಷಿಕೆ->ಸಾಲು_ಅಂಕೆ, ಶೀರ್ಷಿಕೆ->ಗಾತ್ರ_2);
            ಶೀರ್ಷಿಕೆ = ಶೀರ್ಷಿಕೆ->ಮುಂದಿನ;
        }
        fflush(stderr);
        mem_cur_ಗಾತ್ರ = 0;
        mem_max_ಗಾತ್ರ = 0;
        mem_debug_chain = ಖಾಲಿ;
#ಆದರೆ MEM_DEBUG-0 == 2
        ನಿರ್ಗಮಿಸು(2);
#ಆದರೆ_ಅಂತ್ಯ
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_free(ptr)           tcc_free_debug(ptr)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_malloc(ಗಾತ್ರ_2)        tcc_malloc_debug(ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_mallocz(ಗಾತ್ರ_2)       tcc_mallocz_debug(ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_realloc(ptr,ಗಾತ್ರ_2)   tcc_realloc_debug(ptr, ಗಾತ್ರ_2, __FILE__, __LINE__)
#ವ್ಯಾಖ್ಯಾನಿಸು tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#ಆದರೆ_ಅಂತ್ಯ /* MEM_DEBUG */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#ಆದರೆ_ಅಂತ್ಯ

/* for #pragma once */
ST_FUNC ಪೂರ್ಣಾಂಕ normalized_PATHCMP(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f2)
{
    ಅಕ್ಷರ *p1, *p2;
    ಪೂರ್ಣಾಂಕ ret = 1;
    ಆದರೆ (!!(p1 = realpath(f1, ಖಾಲಿ))) {
        ಆದರೆ (!!(p2 = realpath(f2, ಖಾಲಿ))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    ಹಿಂತಿರುಗಿ ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC ಶೂನ್ಯ dynarray_ಕೂಡಿಸು(ಶೂನ್ಯ *ptab, ಪೂರ್ಣಾಂಕ *nb_ptr, ಶೂನ್ಯ *ದತ್ತಾಂಶ)
{
    ಪೂರ್ಣಾಂಕ nb, nb_alloc;
    ಶೂನ್ಯ **pp;

    nb = *nb_ptr;
    pp = *(ಶೂನ್ಯ ***)ptab;
    /* every power of two we double array size */
    ಆದರೆ ((nb & (nb - 1)) == 0) {
        ಆದರೆ (!nb)
            nb_alloc = 1;
        ಇಲ್ಲದಿದ್ದರೆ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * ಗಾತ್ರ(ಶೂನ್ಯ *));
        *(ಶೂನ್ಯ***)ptab = pp;
    }
    pp[nb++] = ದತ್ತಾಂಶ;
    *nb_ptr = nb;
}

ST_FUNC ಶೂನ್ಯ dynarray_reset(ಶೂನ್ಯ *pp, ಪೂರ್ಣಾಂಕ *n)
{
    ಶೂನ್ಯ **p;
    ಗಾಗಿ (p = *(ಶೂನ್ಯ***)pp; *n; ++p, --*n)
        ಆದರೆ (*p)
            tcc_free(*p);
    tcc_free(*(ಶೂನ್ಯ**)pp);
    *(ಶೂನ್ಯ**)pp = ಖಾಲಿ;
}

ಸ್ಥಿರ ಶೂನ್ಯ dynarray_ವಿಭಜಿಸು(ಅಕ್ಷರ ***argv, ಪೂರ್ಣಾಂಕ *argc, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, ಪೂರ್ಣಾಂಕ sep)
{
    ಪೂರ್ಣಾಂಕ qot, c;
    CString str;
    ಗಾಗಿ(;;) {
        ಆಗ (c = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)*p, c <= ' ' && c != '\0')
            ++p;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        cstr_new(&str);
        qot = 0;
        ಮಾಡು {
            ++p;
            ಆದರೆ (sep) { /* e.g. to split -Wl,-opt,arg */
                ಆದರೆ (c == sep)
                    ನಿಲ್ಲಿಸು;
            } ಇಲ್ಲದಿದ್ದರೆ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                ಆದರೆ (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == '"') {
                    qot ^= 1;
                    ಮುಂದುವರಿ;
                } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c <= ' ' && !qot) {
                    ನಿಲ್ಲಿಸು;
                }
            }
            cstr_ccat(&str, c);
        } ಆಗ (c = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_ಕೂಡಿಸು(argv, argc, str.ದತ್ತಾಂಶ);
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ tcc_ವಿಭಜಿಸು_ಮಾರ್ಗ(TCCState *s, ಶೂನ್ಯ *p_ary, ಪೂರ್ಣಾಂಕ *p_nb_ary, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಒಳ)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
    ಮಾಡು {
        ಪೂರ್ಣಾಂಕ c;
        CString str;

        cstr_new(&str);
        ಗಾಗಿ (p = ಒಳ; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            ಆದರೆ (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                ಆದರೆ (c == 'B')
                    cstr_cat(&str, s->tcc_lib_ಮಾರ್ಗ, -1);
                ಆದರೆ (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                ಆದರೆ (c == 'f' && file) {
                    /* substitute current file's dir */
                    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *f = file->true_filename;
                    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *b = tcc_basename(f);
                    ಆದರೆ (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ಇಲ್ಲದಿದ್ದರೆ
                        cstr_cat(&str, ".", 1);
                }
            } ಇಲ್ಲದಿದ್ದರೆ {
                cstr_ccat(&str, c);
            }
        }
        ಆದರೆ (str.ಗಾತ್ರ_2) {
            cstr_ccat(&str, '\0');
            dynarray_ಕೂಡಿಸು(p_ary, p_nb_ary, str.ದತ್ತಾಂಶ);
        }
        ಒಳ = p+1;
    } ಆಗ (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#ವ್ಯಾಖ್ಯಾನಿಸು WARN_ON  1 /* warning is on (-Woption) */
#ವ್ಯಾಖ್ಯಾನಿಸು WARN_ERR 2 /* warning is an error (-Werror=option) */
#ವ್ಯಾಖ್ಯಾನಿಸು WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
ಎಣಿಕೆ { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ಸ್ಥಿರ ಶೂನ್ಯ error1(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    ಪೂರ್ಣಾಂಕ ಸಾಲು = 0;

    tcc_exit_state(s1);

    ಆದರೆ (ಬಹುಲಕ == ERROR_WARN) {
        ಆದರೆ (s1->warn_error)
            ಬಹುಲಕ = ERROR_ERROR;
        ಆದರೆ (s1->warn_ಅಂಕೆ) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            ಪೂರ್ಣಾಂಕ wopt = *(&s1->warn_none + s1->warn_ಅಂಕೆ);
            s1->warn_ಅಂಕೆ = 0;
            ಆದರೆ (0 == (wopt & WARN_ON))
                ಹಿಂತಿರುಗಿ;
            ಆದರೆ (wopt & WARN_ERR)
                ಬಹುಲಕ = ERROR_ERROR;
            ಆದರೆ (wopt & WARN_NOE)
                ಬಹುಲಕ = ERROR_WARN;
        }
        ಆದರೆ (s1->warn_none)
            ಹಿಂತಿರುಗಿ;
    }

    cstr_new(&cs);
    ಆದರೆ (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        ಸಾಲು = va_arg(ap, ಪೂರ್ಣಾಂಕ), fmt += 3;
    f = ಖಾಲಿ;
    ಆದರೆ (s1->error_ಗಣ_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        ಗಾಗಿ (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    ಆದರೆ (f) {
        ಗಾಗಿ(pf = s1->include_ರಾಶಿ; pf < s1->include_ರಾಶಿ_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->ಸಾಲು_ಅಂಕೆ - 1);
        ಆದರೆ (0 == ಸಾಲು)
            ಸಾಲು = f->ಸಾಲು_ಅಂಕೆ - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, ಸಾಲು);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ಇಲ್ಲದಿದ್ದರೆ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, ಬಹುಲಕ == ERROR_WARN ? "warning: " : "error: ");
    ಆದರೆ (pp_ಅಭಿವ್ಯಕ್ತಿ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ಇಲ್ಲದಿದ್ದರೆ
        cstr_vprintf(&cs, fmt, ap);
    ಆದರೆ (!s1->error_func) {
        /* default case: stderr */
        ಆದರೆ (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            ಬರೆ("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (ಅಕ್ಷರ*)cs.ದತ್ತಾಂಶ);
        fflush(stderr); /* print error/warning now (win32) */
    } ಇಲ್ಲದಿದ್ದರೆ {
        s1->error_func(s1->error_opaque, (ಅಕ್ಷರ*)cs.ದತ್ತಾಂಶ);
    }
    cstr_free(&cs);
    ಆದರೆ (ಬಹುಲಕ != ERROR_WARN)
        s1->nb_errors++;
    ಆದರೆ (ಬಹುಲಕ == ERROR_ERROR && s1->error_ಗಣ_jmp_enabled) {
        ಆಗ (nb_stk_ದತ್ತಾಂಶ)
            tcc_free(*(ಶೂನ್ಯ**)stk_ದತ್ತಾಂಶ[--nb_stk_ದತ್ತಾಂಶ]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_error_func(TCCState *s, ಶೂನ್ಯ *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC ಪೂರ್ಣಾಂಕ _tcc_error_noabort(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    ಹಿಂತಿರುಗಿ -1;
}

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು _tcc_error
PUB_FUNC ಶೂನ್ಯ _tcc_error(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    ನಿರ್ಗಮಿಸು(1);
}
#ವ್ಯಾಖ್ಯಾನಿಸು _tcc_error use_tcc_error_noabort

PUB_FUNC ಶೂನ್ಯ _tcc_warning(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC ಶೂನ್ಯ tcc_open_bf(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ initlen)
{
    BufferedFile *bf;
    ಪೂರ್ಣಾಂಕ buflen = initlen ? initlen : IO_BUF_ಗಾತ್ರ;

    bf = tcc_mallocz(ಗಾತ್ರ(BufferedFile) + buflen);
    bf->buf_ptr = bf->ಬಫರ್;
    bf->buf_ಕೊನೆ = bf->ಬಫರ್ + initlen;
    bf->buf_ಕೊನೆ[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, ಗಾತ್ರ(bf->filename), filename);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    normalize_slashes(bf->filename);
#ಆದರೆ_ಅಂತ್ಯ
    bf->true_filename = bf->filename;
    bf->ಸಾಲು_ಅಂಕೆ = 1;
    bf->ifdef_ರಾಶಿ_ptr = s1->ifdef_ರಾಶಿ_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC ಶೂನ್ಯ tcc_close(ಶೂನ್ಯ)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    ಆದರೆ (bf->fd > 0) {
        close(bf->fd);
        ಒಟ್ಟು_ಸಾಲುಗಳು += bf->ಸಾಲು_ಅಂಕೆ - 1;
    }
    ಆದರೆ (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ _tcc_open(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ fd;
    ಆದರೆ (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ಇಲ್ಲದಿದ್ದರೆ
        fd = open(filename, O_RDONLY | O_ದ್ವಿಮಾನ_2);
    ಆದರೆ ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        ಬರೆ("%s %*s%s\n", fd < 0 ? "nf":"->",
               (ಪೂರ್ಣಾಂಕ)(s1->include_ರಾಶಿ_ptr - s1->include_ರಾಶಿ), "", filename);
    ಹಿಂತಿರುಗಿ fd;
}

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_open(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ fd = _tcc_open(s1, filename);
    ಆದರೆ (fd < 0)
        ಹಿಂತಿರುಗಿ -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    ಹಿಂತಿರುಗಿ 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_compile(TCCState *s1, ಪೂರ್ಣಾಂಕ filetype, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, ಪೂರ್ಣಾಂಕ fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_ಗಣ_jmp_enabled = 1;

    ಆದರೆ (setjmp(s1->error_jmp_buf) == 0) {

        ಆದರೆ (fd == -1) {
            ಪೂರ್ಣಾಂಕ len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str);
            tcc_open_bf(s1, "<string>", len);
            ಸ್ಮರಣೆ_ನಕಲು(file->ಬಫರ್, str, len);
        } ಇಲ್ಲದಿದ್ದರೆ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_ಆರಂಭ(s1, filetype);
        tccgen_init(s1);

        ಆದರೆ (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ಇಲ್ಲದಿದ್ದರೆ {
            tccelf_begin_file(s1);
            ಆದರೆ (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ಇಲ್ಲದಿದ್ದರೆ {
                tccgen_compile(s1);
            }
            tccelf_ಕೊನೆ_file(s1);
        }
    }
    tccgen_ಮುಕ್ತಾಯ(s1);
    preprocess_ಕೊನೆ(s1);
    s1->error_ಗಣ_jmp_enabled = 0;
    tcc_exit_state(s1);
    ಹಿಂತಿರುಗಿ s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_compile_string(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str)
{
    ಹಿಂತಿರುಗಿ tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ಶೂನ್ಯ tcc_define_ಚಿಹ್ನೆ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮೌಲ್ಯ)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *eq;
    ಆದರೆ (ಖಾಲಿ == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    ಆದರೆ (ಖಾಲಿ == ಮೌಲ್ಯ)
        ಮೌಲ್ಯ = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (ಪೂರ್ಣಾಂಕ)(eq-sym), sym, ಮೌಲ್ಯ);
}

/* undefine a preprocessor symbol */
LIBTCCAPI ಶೂನ್ಯ tcc_undefine_ಚಿಹ್ನೆ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(ಶೂನ್ಯ)
{
    TCCState *s;

    s = tcc_mallocz(ಗಾತ್ರ(TCCState));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ MEM_DEBUG
    tcc_memcheck(1);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_ಒಳ_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
    s->seg_ಗಾತ್ರ = 32;
#ಆದರೆ_ಅಂತ್ಯ
    /* enable this if you want symbols with leading underscore on windows: */
#ಆದರೆ defined TCC_ಗುರಿ_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_ಗುರಿ_ARM64 && defined TCC_ಗುರಿ_PE
    s->pe_dll_characteristics = 0x8160;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#ಆದರೆ_ಅಂತ್ಯ
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ರಾಶಿ_ptr = s->include_ರಾಶಿ;

    tcc_ಗಣ_lib_ಮಾರ್ಗ(s, CONFIG_TCCDIR);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_SWITCHES /* predefined options */
    tcc_ಗಣ_options(s, CONFIG_TCC_SWITCHES);
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ s;
}

LIBTCCAPI ಶೂನ್ಯ tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_ಮಾರ್ಗ);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_ಚಿಹ್ನೆ);
    tcc_free(s1->fini_ಚಿಹ್ನೆ);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#ಆದರೆ defined TCC_ಗುರಿ_MACHO
    tcc_free(s1->install_name);
#ಆದರೆ_ಅಂತ್ಯ
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->ಗುರಿ_deps, &s1->nb_ಗುರಿ_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
    /* free runtime memory */
    tcc_ಸತತ_free(s1);
#ಆದರೆ_ಅಂತ್ಯ
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ MEM_DEBUG
    tcc_memcheck(-1);
#ಆದರೆ_ಅಂತ್ಯ
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಗಣ_output_type(TCCState *s, ಪೂರ್ಣಾಂಕ output_type)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_PIE
    ಆದರೆ (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#ಆದರೆ_ಅಂತ್ಯ
    s->output_type = output_type;

    ಆದರೆ (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_ಕೂಡಿಸು_sysinclude_ಮಾರ್ಗ(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    ಆದರೆ (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        ಹಿಂತಿರುಗಿ 0;
    }

    /* add sections */
    tccelf_new(s);

    ಆದರೆ (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        ಹಿಂತಿರುಗಿ 0;
    }

    ಆದರೆ (!s->nostdlib_paths)
        tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, CONFIG_TCC_LIBPATHS);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_ಕೂಡಿಸು_systemdir(s);
# endif

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_MACHO
# ifdef TCC_IS_NATIVE
    tcc_ಕೂಡಿಸು_macos_sdkpath(s);
# endif

#ಇಲ್ಲದಿದ್ದರೆ
    /* paths for crt objects */
    tcc_ವಿಭಜಿಸು_ಮಾರ್ಗ(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    ಆದರೆ (output_type != TCC_OUTPUT_ಸ್ಮರಣೆ && !s->nostdlib)
        tccelf_ಕೂಡಿಸು_crtbegin(s); /* may produce errors */
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ s->nb_errors ? -1 : 0;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname)
{
    tcc_ವಿಭಜಿಸು_ಮಾರ್ಗ(s, &s->include_paths, &s->nb_include_paths, pathname);
    ಹಿಂತಿರುಗಿ 0;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_sysinclude_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname)
{
    tcc_ವಿಭಜಿಸು_ಮಾರ್ಗ(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    ಹಿಂತಿರುಗಿ 0;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *pathname)
{
    tcc_ವಿಭಜಿಸು_ಮಾರ್ಗ(s, &s->library_paths, &s->nb_library_paths, pathname);
    ಹಿಂತಿರುಗಿ 0;
}

LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_lib_ಮಾರ್ಗ(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಮಾರ್ಗ)
{
    tcc_ಗಣ_str(&s->tcc_lib_ಮಾರ್ಗ, ಮಾರ್ಗ);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_ಕೂಡಿಸು_dllref(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dllname, ಪೂರ್ಣಾಂಕ level)
{
    DLLReference *ref = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < s1->nb_loaded_dlls; i++)
        ಆದರೆ (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            ನಿಲ್ಲಿಸು;
        }
    ಆದರೆ (level == -1)
        ಹಿಂತಿರುಗಿ ref;
    ಆದರೆ (ref) {
        ಆದರೆ (level < ref->level)
            ref->level = level;
        ref->ಸಿಕ್ಕಿತು = 1;
        ಹಿಂತಿರುಗಿ ref;
    }
    ref = tcc_mallocz(ಗಾತ್ರ(DLLReference) + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(dllname));
    strcpy(ref->name, dllname);
    dynarray_ಕೂಡಿಸು(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->ಸೂಚ್ಯಂಕ = s1->nb_loaded_dlls;
    ಹಿಂತಿರುಗಿ ref;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_ದ್ವಿಮಾನ(TCCState *s1, ಪೂರ್ಣಾಂಕ flags, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ fd)
{
    ElfW(Ehdr) ehdr;
    ಪೂರ್ಣಾಂಕ obj_type;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *saved_filename = s1->current_filename;
    ಪೂರ್ಣಾಂಕ ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    ಆಯ್ಕೆ (obj_type) {

    ಸ್ಥಿತಿ AFF_BINTYPE_REL:
        ret = tcc_ತುಂಬು_object_file(s1, fd, 0);
        ನಿಲ್ಲಿಸು;

    ಸ್ಥಿತಿ AFF_BINTYPE_AR:
        ret = tcc_ತುಂಬು_archive(s1, fd, !(flags & AFF_ಸಂಪೂರ್ಣ_ARCHIVE));
        ನಿಲ್ಲಿಸು;

#ಆದರೆ defined TCC_ಗುರಿ_UNIX
    ಸ್ಥಿತಿ AFF_BINTYPE_DYN:
        ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
            ಶೂನ್ಯ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            ಆದರೆ (dl)
                tcc_ಕೂಡಿಸು_dllref(s1, filename, 0)->handle = dl;
            ಇಲ್ಲದಿದ್ದರೆ
                ret = FILE_NOT_RECOGNIZED;
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ
            ret = tcc_ತುಂಬು_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        ನಿಲ್ಲಿಸು;

    ಪೂರ್ವನಿಯೋಜಿತ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_ತುಂಬು_ldscript(s1, fd);
        ನಿಲ್ಲಿಸು;

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_MACHO
    ಸ್ಥಿತಿ AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        ಆದರೆ (s1->output_type == TCC_OUTPUT_ಸ್ಮರಣೆ) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
            ಶೂನ್ಯ* dl;
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* soname = filename;
            ಅಕ್ಷರ *tmp = 0;
            ಆದರೆ (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                ಆದರೆ (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            ಆದರೆ (dl)
                tcc_ಕೂಡಿಸು_dllref(s1, soname, 0)->handle = dl;
            ಇಲ್ಲದಿದ್ದರೆ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_ತುಂಬು_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ಇಲ್ಲದಿದ್ದರೆ {
            ret = macho_ತುಂಬು_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        ಆದರೆ (ret)
            ret = FILE_NOT_RECOGNIZED;
        ನಿಲ್ಲಿಸು;

    ಪೂರ್ವನಿಯೋಜಿತ:
    {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ext = tcc_fileextension(filename);
        ಆದರೆ (!strcmp(ext, ".tbd"))
            ಹೋಗು case_dyn_or_tbd;
        ಆದರೆ (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            ಹೋಗು case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        ನಿಲ್ಲಿಸು;
    }

#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_PE
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಆದರೆ (pe_ತುಂಬು_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_COFF
    ಸ್ಥಿತಿ AFF_BINTYPE_C67:
        ret = tcc_ತುಂಬು_coff(s1, fd);
        ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
    }

    close(fd);
    s1->current_filename = saved_filename;
    ಆದರೆ (ret == FILE_NOT_RECOGNIZED)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("%s: unrecognized file type", filename);
    ಹಿಂತಿರುಗಿ ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#ಆದರೆ defined TARGETOS_OpenBSD && !defined _WIN32
#ಅನ್ತರ್ಭಾವ <glob.h>
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_glob_so(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ನಮೂನೆ, ಅಕ್ಷರ *buf, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ನಕ್ಷತ್ರ;
    glob_t g;
    ಅಕ್ಷರ *p;
    ಪೂರ್ಣಾಂಕ i, v, v1, v2, v3;

    ನಕ್ಷತ್ರ = strchr(ನಮೂನೆ, '*');
    ಆದರೆ (!ನಕ್ಷತ್ರ || glob(ನಮೂನೆ, 0, ಖಾಲಿ, &g))
        ಹಿಂತಿರುಗಿ -1;
    ಗಾಗಿ (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        ಆದರೆ (2 != ಅಕ್ಷರಸರಣಿ_ಓದು(p + (ನಕ್ಷತ್ರ - ನಮೂನೆ), "%d.%d.%d", &v1, &v2, &v3))
            ಮುಂದುವರಿ;
        ಆದರೆ ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, ಗಾತ್ರ_2, p);
    }
    globfree(&g);
    ಹಿಂತಿರುಗಿ v;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ guess_filetype(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಪೂರ್ಣಾಂಕ filetype = 0;
    ಆದರೆ (1) {
        /* use a file extension to detect a filetype */
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ext = tcc_fileextension(filename);
        ಆದರೆ (ext[0]) {
            ext++;
            ಆದರೆ (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ಇಲ್ಲದಿದ್ದರೆ
                filetype |= AFF_TYPE_BIN;
        } ಇಲ್ಲದಿದ್ದರೆ {
            filetype = AFF_TYPE_C;
        }
    }
    ಹಿಂತಿರುಗಿ filetype;
}

ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_file_ಆಂತರಿಕ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flags)
{
    ಪೂರ್ಣಾಂಕ fd;

#ಆದರೆ defined TARGETOS_OpenBSD && !defined _WIN32
    ಅಕ್ಷರ buf[1024];
    ಆದರೆ (tcc_glob_so(s1, filename, buf, ಗಾತ್ರ buf) >= 0)
        filename = buf;
#ಆದರೆ_ಅಂತ್ಯ

    ಆದರೆ (0 == (flags & AFF_TYPE_ಮುಖವಾಡ))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    ಆದರೆ (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        ಹಿಂತಿರುಗಿ 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    ಆದರೆ (fd < 0) {
        ಆದರೆ (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        ಹಿಂತಿರುಗಿ FILE_NOT_ಸಿಕ್ಕಿತು;
    }

    ಆದರೆ (flags & AFF_TYPE_BIN)
        ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_ದ್ವಿಮಾನ(s1, flags, filename, fd);

    dynarray_ಕೂಡಿಸು(&s1->ಗುರಿ_deps, &s1->nb_ಗುರಿ_deps, tcc_strdup(filename));
    ಹಿಂತಿರುಗಿ tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_file_ಆಂತರಿಕ(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library_ಆಂತರಿಕ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt,
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flags, ಅಕ್ಷರ **paths, ಪೂರ್ಣಾಂಕ nb_paths)
{
    ಅಕ್ಷರ buf[1024];
    ಪೂರ್ಣಾಂಕ i, ret;

    ಗಾಗಿ(i = 0; i < nb_paths; i++) {
        snprintf(buf, ಗಾತ್ರ(buf), fmt, paths[i], filename);
        ret = tcc_ಕೂಡಿಸು_file_ಆಂತರಿಕ(s1, buf, flags & ~AFF_PRINT_ERROR);
        ಆದರೆ (ret != FILE_NOT_ಸಿಕ್ಕಿತು)
            ಹಿಂತಿರುಗಿ ret;
    }
    ಆದರೆ (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    ಹಿಂತಿರುಗಿ FILE_NOT_ಸಿಕ್ಕಿತು;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_dll(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flags)
{
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_library_ಆಂತರಿಕ(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_support(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಅಕ್ಷರ buf[100];
    ಆದರೆ (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_dll(s1, filename, AFF_PRINT_ERROR);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_UNIX
ST_FUNC ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_crt(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename)
{
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_library_ಆಂತರಿಕ(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#ಆದರೆ_ಅಂತ್ಯ

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಕೂಡಿಸು_library(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *libraryname)
{
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ libs[] = {
#ಆದರೆ defined TCC_ಗುರಿ_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#ಅಥವಾಆದರೆ defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ಇಲ್ಲದಿದ್ದರೆ
        "%s/lib%s.so",
#ಆದರೆ_ಅಂತ್ಯ
        "%s/lib%s.a",
        ಖಾಲಿ
    };
    ಪೂರ್ಣಾಂಕ flags = AFF_TYPE_LIB | (s->filetype & AFF_ಸಂಪೂರ್ಣ_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    ಆದರೆ (*libraryname == ':') {
        libraryname++;
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * ಸ್ಥಿರಾಂಕ *pp = libs;
        ಆದರೆ (s->static_link)
            pp += ಗಾತ್ರ(libs) / ಗಾತ್ರ(*libs) - 2; /* only "%s/lib%s.a" */
        ಆಗ (*pp) {
            ಪೂರ್ಣಾಂಕ ret = tcc_ಕೂಡಿಸು_library_ಆಂತರಿಕ(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            ಆದರೆ (ret != FILE_NOT_ಸಿಕ್ಕಿತು)
                ಹಿಂತಿರುಗಿ ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    ಹಿಂತಿರುಗಿ tcc_ಕೂಡಿಸು_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC ಶೂನ್ಯ tcc_ಕೂಡಿಸು_pragma_libs(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_ಕೂಡಿಸು_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ strstart(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *val, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ **str)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, *q;
    p = *str;
    q = val;
    ಆಗ (*q) {
        ಆದರೆ (*p != *q)
            ಹಿಂತಿರುಗಿ 0;
        p++;
        q++;
    }
    *str = p;
    ಹಿಂತಿರುಗಿ 1;
}

ರಚನೆ lopt {
    TCCState *s;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *opt, *arg;
    ಪೂರ್ಣಾಂಕ ಹೊಂದಿಕೆ;
};

/* match linker option */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ link_option(ರಚನೆ lopt *o, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *q)
{
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
    ಪೂರ್ಣಾಂಕ c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    ಆದರೆ (*p++ != '-')
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (*p == '-')
        p++;
    r = 1;
    ಆದರೆ (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        ಆದರೆ (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#ಆದರೆ_ಅಂತ್ಯ
    }
    ಆಗ ((c = *q) == *p) {
        ಆದರೆ (c == '\0')
            ಹೋಗು succ; /* -Wl,-opt */
        ++p;
        ಆದರೆ (c == '=')
            ಹೋಗು succ; /* -Wl,-opt=arg */
        ++q;
    }
    ಆದರೆ (*p == '\0') {
        ಆದರೆ (c == '|')
            ಹೋಗು succ;
        ಆದರೆ (c == '=' || c == ':') {
            ಆದರೆ (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                ಹೋಗು succ; /* -Wl,-opt,arg */
            }
            o->ಹೊಂದಿಕೆ = 1; /* -Wl,-opt -Wl,arg */
            ಹಿಂತಿರುಗಿ 0;
        }
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (c == ':')
        ಹೋಗು succ; /* -Wl,-Iarg */
    ಆಗ (*q)
        ಆದರೆ (*q++ == '|')
            ಹೋಗು redo;
    ಹಿಂತಿರುಗಿ 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    ಹಿಂತಿರುಗಿ r;
}

ಸ್ಥಿರ ಶೂನ್ಯ ವಾದಗಳು_parser_ಕೂಡಿಸು_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* filename, ಪೂರ್ಣಾಂಕ filetype);

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_ಗಣ_linker(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *optarg)
{
    TCCState *s1 = s;

    dynarray_ವಿಭಜಿಸು(&s1->link_argv, &s1->link_argc, optarg, ',');

    ಆಗ (s->link_optind < s->link_argc) {
        ಅಕ್ಷರ *ಕೊನೆ = ಖಾಲಿ;
        ಪೂರ್ಣಾಂಕ ignoring = 0;
        ರಚನೆ lopt o = {0};
        ಪೂರ್ಣಾಂಕ r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        ಆದರೆ (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "e=|entry=")) {
            tcc_ಗಣ_str(&s->elf_entryname, o.arg);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "image-base=|Ttext=")) {
            s->ಪಠ್ಯ_addr = strtoull(o.arg, &ಕೊನೆ, 16);
            s->has_ಪಠ್ಯ_addr = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "init=")) {
            tcc_ಗಣ_str(&s->init_ಚಿಹ್ನೆ, o.arg);
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "fini=")) {
            tcc_ಗಣ_str(&s->fini_ಚಿಹ್ನೆ, o.arg);
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "Map=")) {
            tcc_ಗಣ_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "oformat=")) {
#ಆದರೆ defined TCC_ಗುರಿ_PE
            ಆದರೆ (0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ("pe-", o.arg, 3))
#ಅಥವಾಆದರೆ PTR_ಗಾತ್ರ == 8
            ಆದರೆ (0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ("elf64-", o.arg, 6))
#ಇಲ್ಲದಿದ್ದರೆ
            ಆದರೆ (0 == ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ("elf32-", o.arg, 6))
#ಆದರೆ_ಅಂತ್ಯ
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ದ್ವಿಮಾನ;
#ಆದರೆ defined TCC_ಗುರಿ_COFF
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#ಆದರೆ_ಅಂತ್ಯ
            ಇಲ್ಲದಿದ್ದರೆ
                ಹೋಗು err;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "dynamic-linker=|I:")) {
            tcc_ಗಣ_str(&s->elfint, o.arg);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &ಕೊನೆ, 16);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "soname=|install_name=")) {
            tcc_ಗಣ_str(&s->soname, o.arg);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!!(r = link_option(&o, "?whole-archive"))) {
            ಗಣ_OR_CLEAR(s->filetype, AFF_ಸಂಪೂರ್ಣ_ARCHIVE);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!!(r = link_option(&o, "?dynamicbase"))) {
            ಗಣ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!!(r = link_option(&o, "?high-entropy-va"))) {
            ಗಣ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!!(r = link_option(&o, "?nxcompat"))) {
            ಗಣ_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!!(r = link_option(&o, "?tsaware"))) {
            ಗಣ_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &ಕೊನೆ, 16);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "stack=")) {
            s->pe_ರಾಶಿ_ಗಾತ್ರ = strtoul(o.arg, &ಕೊನೆ, 10);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "subsystem=")) {
            ಆದರೆ (pe_setsubsy(s, o.arg) < 0)
                ಹೋಗು err;
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_MACHO
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "all_load")) {
	    s->filetype |= AFF_ಸಂಪೂರ್ಣ_ARCHIVE;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "force_load=")) {
            ವಾದಗಳು_parser_ಕೂಡಿಸು_file(s, o.arg, AFF_TYPE_LIB | AFF_ಸಂಪೂರ್ಣ_ARCHIVE);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "single_module")) {
            ignoring = 1;
#ಆದರೆ_ಅಂತ್ಯ
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "O")) {
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "z=")) {
            ignoring = 1;
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "L:")) {
            tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, o.arg);
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (link_option(&o, "l:")) {
            ವಾದಗಳು_parser_ಕೂಡಿಸು_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ಮುಖವಾಡ));
        } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (o.ಹೊಂದಿಕೆ) {
            ಹಿಂತಿರುಗಿ 0; /* expecting argument with next '-Wl,' */
        } ಇಲ್ಲದಿದ್ದರೆ {
    err:
            ಹಿಂತಿರುಗಿ tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        ಆದರೆ (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TCCOption {
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
    uint16_t ಸೂಚ್ಯಂಕ;
    uint16_t flags;
} TCCOption;

ಎಣಿಕೆ {
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
    TCC_OPTION_print_ಹುಡುಕು_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_ಸತತ,
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
    TCC_OPTION_compatibility_ಆವೃತ್ತಿ ,
    TCC_OPTION_current_ಆವೃತ್ತಿ,
};

#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OPTION_HAS_ARG 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ TCCOption tcc_options[] = {
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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#ಆದರೆ_ಅಂತ್ಯ
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_ಆವೃತ್ತಿ, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_ಆವೃತ್ತಿ, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#ಆದರೆ_ಅಂತ್ಯ
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
    { "run", TCC_OPTION_ಸತತ, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#ಆದರೆ_ಅಂತ್ಯ
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_ಹುಡುಕು_dirs, 0 },
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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    { "impdef", TCC_OPTION_impdef, 0},
#ಆದರೆ_ಅಂತ್ಯ
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
    { ಖಾಲಿ, 0, 0 },
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ FlagDef {
    uint16_t ಸ್ಥಾನಾಂತರ;
    uint16_t flags;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name;
} FlagDef;

#ವ್ಯಾಖ್ಯಾನಿಸು WD_ALL    0x0001 /* warning is activated when using -Wall */
#ವ್ಯಾಖ್ಯಾನಿಸು FD_INVERT 0x0002 /* invert value before storing */

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_ಅಕ್ಷರಸರಣಿಗಳು), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, ಖಾಲಿ }
};

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_ಒಳ_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, ಹಿಮ್ಮುಖ_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, ಖಾಲಿ }
};

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#ಆದರೆ_ಅಂತ್ಯ
    { 0, 0, ಖಾಲಿ }
};

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಗಣ_flag(TCCState *s, ಸ್ಥಿರಾಂಕ FlagDef *flags, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name)
{
    ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ, ಮುಖವಾಡ, ret;
    ಸ್ಥಿರಾಂಕ FlagDef *p;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *r;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *f;

    r = name, ಮೌಲ್ಯ = !strstart("no-", &r), ಮುಖವಾಡ = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    ಆದರೆ ((flags->flags & WD_ALL) && strstart("error=", &r))
        ಮೌಲ್ಯ = ಮೌಲ್ಯ ? WARN_ON|WARN_ERR : WARN_NOE, ಮುಖವಾಡ = WARN_ON;

    ಗಾಗಿ (ret = -1, p = flags; p->name; ++p) {
        ಆದರೆ (ret) {
            ಆದರೆ (strcmp(r, p->name))
                ಮುಂದುವರಿ;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಆದರೆ (0 == (p->flags & WD_ALL))
                ಮುಂದುವರಿ;
        }

        f = (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)s + p->ಸ್ಥಾನಾಂತರ;
        *f = (*f & ಮುಖವಾಡ) | (ಮೌಲ್ಯ ^ !!(p->flags & FD_INVERT));

        ಆದರೆ (ret) {
            ret = 0;
            ಆದರೆ (strcmp(r, "all"))
                ನಿಲ್ಲಿಸು;
        }
    }
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_I386
    "i386-pc"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_X86_64
    "x86_64-pc"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_C67
    "c67"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM
    "arm"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_ARM64
    "aarch64"
#ಅಥವಾಆದರೆ defined TCC_ಗುರಿ_RISCV64
    "riscv64"
#ಆದರೆ_ಅಂತ್ಯ
    "-"
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    "mingw32"
#ಅಥವಾಆದರೆ defined(TCC_ಗುರಿ_MACHO)
    "apple-darwin"
#ಅಥವಾಆದರೆ TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#ಅಥವಾಆದರೆ TARGETOS_OpenBSD
    "openbsd"
#ಅಥವಾಆದರೆ TARGETOS_NetBSD
    "netbsd"
#ಅಥವಾಆದರೆ CONFIG_TCC_MUSL
    "linux-musl"
#ಇಲ್ಲದಿದ್ದರೆ
    "linux-gnu"
#ಆದರೆ_ಅಂತ್ಯ
;

#ಆದರೆ defined TCC_ಗುರಿ_MACHO
ಸ್ಥಿರ uint32_t parse_ಆವೃತ್ತಿ(TCCState *s1, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಆವೃತ್ತಿ)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    ಅಕ್ಷರ* ಕೊನೆಯ;

    a = strtoul(ಆವೃತ್ತಿ, &ಕೊನೆಯ, 10);
    ಆದರೆ (*ಕೊನೆಯ == '.') {
        b = strtoul(&ಕೊನೆಯ[1], &ಕೊನೆಯ, 10);
        ಆದರೆ (*ಕೊನೆಯ == '.')
             c = strtoul(&ಕೊನೆಯ[1], &ಕೊನೆಯ, 10);
    }
    ಆದರೆ (*ಕೊನೆಯ || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", ಆವೃತ್ತಿ);
    ಹಿಂತಿರುಗಿ (a << 16) | (b << 8) | c;
}
#ಆದರೆ_ಅಂತ್ಯ

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ಸ್ಥಿರ ಶೂನ್ಯ ಸೇರಿಸು_ವಾದಗಳು(TCCState *s1, ಅಕ್ಷರ ***pargv, ಪೂರ್ಣಾಂಕ *pargc, ಪೂರ್ಣಾಂಕ optind, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p, ಪೂರ್ಣಾಂಕ sep)
{
    ಪೂರ್ಣಾಂಕ argc = 0;
    ಅಕ್ಷರ **argv = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ i;
    ಗಾಗಿ (i = 0; i < *pargc; ++i)
        ಆದರೆ (i == optind)
            dynarray_ವಿಭಜಿಸು(&argv, &argc, p, sep);
        ಇಲ್ಲದಿದ್ದರೆ
            dynarray_ಕೂಡಿಸು(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ಸ್ಥಿರ ಶೂನ್ಯ ವಾದಗಳು_parser_ಕೂಡಿಸು_file(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ* filename, ಪೂರ್ಣಾಂಕ filetype)
{
    ರಚನೆ filespec *f = tcc_malloc(ಗಾತ್ರ *f + ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_ಕೂಡಿಸು(&s->files, &s->nb_files, f);
    ಆದರೆ (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC ಪೂರ್ಣಾಂಕ tcc_parse_ವಾದಗಳು(TCCState *s, ಪೂರ್ಣಾಂಕ *pargc, ಅಕ್ಷರ ***pargv)
{
    TCCState *s1 = s;
    ಸ್ಥಿರಾಂಕ TCCOption *popt;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *optarg, *r;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸತತ = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ optind = 1, ಖಾಲಿಗಳು = 1, x;
    ಅಕ್ಷರ **argv = *pargv;
    ಪೂರ್ಣಾಂಕ argc = *pargc;

    s->link_optind = s->link_argc;

    ಆಗ (optind < argc) {
        r = argv[optind];
        ಆದರೆ (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            ಪೂರ್ಣಾಂಕ fd; ಅಕ್ಷರ *p;
            fd = open(++r, O_RDONLY | O_ದ್ವಿಮಾನ_2);
            ಆದರೆ (fd < 0)
                ಹಿಂತಿರುಗಿ tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_ತುಂಬು_ಪಠ್ಯ(fd);
            ಸೇರಿಸು_ವಾದಗಳು(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            ಮುಂದುವರಿ;
        }
        optind++;
        ಆದರೆ (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            ವಾದಗಳು_parser_ಕೂಡಿಸು_file(s, r, s->filetype);
            ಖಾಲಿಗಳು = 0;
        dorun:
            ಆದರೆ (ಸತತ)
                ನಿಲ್ಲಿಸು;
            ಮುಂದುವರಿ;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        ಆದರೆ (r[1] == '-' && r[2] == '\0')
            ಹೋಗು dorun;

        /* find option in table */
        ಗಾಗಿ(popt = tcc_options; ; ++popt) {
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p1 = popt->name;
            ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *r1 = r + 1;
            ಆದರೆ (p1 == ಖಾಲಿ)
                ಹಿಂತಿರುಗಿ tcc_error_noabort("invalid option -- '%s'", r);
            ಆದರೆ (!strstart(p1, &r1))
                ಮುಂದುವರಿ;
            optarg = r1;
            ಆದರೆ (popt->flags & TCC_OPTION_HAS_ARG) {
                ಆದರೆ (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    ಆದರೆ (optind >= argc)
                        ಹಿಂತಿರುಗಿ tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*r1 != '\0')
                ಮುಂದುವರಿ;
            ನಿಲ್ಲಿಸು;
        }

        ಆಯ್ಕೆ(popt->ಸೂಚ್ಯಂಕ) {
        ಸ್ಥಿತಿ TCC_OPTION_I:
            tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(s, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_D:
            tcc_define_ಚಿಹ್ನೆ(s, optarg, ಖಾಲಿ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_U:
            tcc_undefine_ಚಿಹ್ನೆ(s, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_L:
            tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_ಗಣ_lib_ಮಾರ್ಗ(s, optarg);
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ TCC_OPTION_l:
            ವಾದಗಳು_parser_ಕೂಡಿಸು_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ಮುಖವಾಡ));
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_pthread:
            s->option_pthread = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_bench:
            s->do_bench = 1;
            ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
        ಸ್ಥಿತಿ TCC_OPTION_bt:
            s->rt_ಅಂಕೆ_callers = atoi(optarg); /* zero = default (6) */
            ಹೋಗು enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            ಆದರೆ (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_ಆವೃತ್ತಿ;
            ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಸ್ಥಿತಿ TCC_OPTION_b:
            s->do_bounds_check = 1;
            ಹೋಗು enable_backtrace;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_ಆವೃತ್ತಿ;
        g_redo:
            ಆದರೆ (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_ಆವೃತ್ತಿ;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                ಹೋಗು g_redo;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#ಆದರೆ_ಅಂತ್ಯ
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        ಗಣ_output_type:
            ಆದರೆ (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_d:
            ಆದರೆ (*optarg == 'D')
                s->dflag = 3;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*optarg == 'M')
                s->dflag = 7;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*optarg == 't')
                s->dflag = 16;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (isnum(*optarg))
                g_debug |= atoi(optarg);
            ಇಲ್ಲದಿದ್ದರೆ
                ಹೋಗು unsupported_option;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_static:
            s->static_link = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_std:
            ಆದರೆ (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            ಹೋಗು ಗಣ_output_type;
        ಸ್ಥಿತಿ TCC_OPTION_soname:
            tcc_ಗಣ_str(&s->soname, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_o:
            ಆದರೆ (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_ಗಣ_str(&s->outfile, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            ಹೋಗು ಗಣ_output_type;
        ಸ್ಥಿತಿ TCC_OPTION_isystem:
            tcc_ಕೂಡಿಸು_sysinclude_ಮಾರ್ಗ(s, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_ಸತತ:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            ಸತತ = optarg;
            x = TCC_OUTPUT_ಸ್ಮರಣೆ;
            ಹೋಗು ಗಣ_output_type;
#ಇಲ್ಲದಿದ್ದರೆ
            ಹಿಂತಿರುಗಿ tcc_error_noabort("-run is not available in a cross compiler");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
        ಸ್ಥಿತಿ TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->ಸತತ_stdin = optarg;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ TCC_OPTION_v:
            ಮಾಡು ++s->verbose; ಆಗ (*optarg++ == 'v');
            ಮುಂದುವರಿ;
        ಸ್ಥಿತಿ TCC_OPTION_f:
            ಆದರೆ (ಗಣ_flag(s, options_f, optarg) < 0)
                ಹೋಗು unsupported_option;
            ನಿಲ್ಲಿಸು;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_ARM
        ಸ್ಥಿತಿ TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            ಆದರೆ (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ಇಲ್ಲದಿದ್ದರೆ
                ಹಿಂತಿರುಗಿ tcc_error_noabort("unsupported float abi '%s'", optarg);
            ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ TCC_OPTION_m:
            ಆದರೆ (ಗಣ_flag(s, options_m, optarg) < 0) {
                ಆದರೆ (x = atoi(optarg), x != 32 && x != 64)
                    ಹೋಗು unsupported_option;
                ಆದರೆ (PTR_ಗಾತ್ರ != x/8)
                    ಹಿಂತಿರುಗಿ x;
                ಮುಂದುವರಿ;
            }
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_W:
            ಆದರೆ (optarg[0] && ಗಣ_flag(s, options_W, optarg) < 0)
                ಹೋಗು unsupported_option;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_w:
            s->warn_none = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_Wl:
            ಆದರೆ (tcc_ಗಣ_linker(s, optarg) < 0)
                ಹಿಂತಿರುಗಿ -1;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_Wp:
            ಆದರೆ (argv[0]) /* not with tcc_set_options() */
                ಸೇರಿಸು_ವಾದಗಳು(s, &argv, &argc, --optind, optarg, ',');
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            ಹೋಗು ಗಣ_output_type;
        ಸ್ಥಿತಿ TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        ಸ್ಥಿತಿ TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            ಆದರೆ (!s->deps_outfile)
                tcc_ಗಣ_str(&s->deps_outfile, "-");
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        ಸ್ಥಿತಿ TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            ಆದರೆ (*optarg != ',')
                ನಿಲ್ಲಿಸು;
            ++optarg;
            // fall through
        ಸ್ಥಿತಿ TCC_OPTION_MF:
            tcc_ಗಣ_str(&s->deps_outfile, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            ನಿಲ್ಲಿಸು;

        ಸ್ಥಿತಿ TCC_OPTION_dumpmachine:
            ಬರೆ("%s\n", dumpmachine_str);
            ನಿರ್ಗಮಿಸು(0);
        ಸ್ಥಿತಿ TCC_OPTION_dumpversion:
            ಬರೆ ("%s\n", TCC_ಆವೃತ್ತಿ);
            ನಿರ್ಗಮಿಸು(0);

        ಸ್ಥಿತಿ TCC_OPTION_x:
            x = 0;
            ಆದರೆ (*optarg == 'c')
                x = AFF_TYPE_C;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ಇಲ್ಲದಿದ್ದರೆ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_ಮುಖವಾಡ);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ defined TCC_ಗುರಿ_MACHO
        ಸ್ಥಿತಿ TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            ಹೋಗು ಗಣ_output_type;
        ಸ್ಥಿತಿ TCC_OPTION_flat_namespace:
	     ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_two_levelnamespace:
	     ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_undefined:
	     ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_install_name:
	    tcc_ಗಣ_str(&s->install_name, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_compatibility_ಆವೃತ್ತಿ:
	    s->compatibility_ಆವೃತ್ತಿ = parse_ಆವೃತ್ತಿ(s, optarg);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ TCC_OPTION_current_ಆವೃತ್ತಿ:
	    s->current_ಆವೃತ್ತಿ = parse_ಆವೃತ್ತಿ(s, optarg);;
            ನಿಲ್ಲಿಸು;
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ TCC_OPTION_HELP:
            x = OPT_HELP;
            ಹೋಗು extra_action;
        ಸ್ಥಿತಿ TCC_OPTION_HELP2:
            x = OPT_HELP2;
            ಹೋಗು extra_action;
        ಸ್ಥಿತಿ TCC_OPTION_print_ಹುಡುಕು_dirs:
            x = OPT_PRINT_DIRS;
            ಹೋಗು extra_action;
        ಸ್ಥಿತಿ TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            ಹೋಗು extra_action;
        ಸ್ಥಿತಿ TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            ಆದರೆ (ಖಾಲಿ == argv[0]) /* from tcc_set_options() */
                ಹಿಂತಿರುಗಿ -1;
            ಆದರೆ (!ಖಾಲಿಗಳು && x)
                ಹಿಂತಿರುಗಿ tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            ಹಿಂತಿರುಗಿ x;
        ಪೂರ್ವನಿಯೋಜಿತ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            ನಿಲ್ಲಿಸು;
        }
        ಖಾಲಿಗಳು = 0;
    }
    ಆದರೆ (s->link_optind < s->link_argc)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    ಆದರೆ (ಸತತ) {
        ಆದರೆ (*ಸತತ && tcc_ಗಣ_options(s, ಸತತ) < 0)
            ಹಿಂತಿರುಗಿ -1;
        x = 0, r = 0;
        ಹೋಗು extra_action;
    }
    ಆದರೆ (!ಖಾಲಿಗಳು)
        ಹಿಂತಿರುಗಿ 0;
    ಆದರೆ (s->verbose == 2)
        ಹಿಂತಿರುಗಿ OPT_PRINT_DIRS;
    ಆದರೆ (s->verbose)
        ಹಿಂತಿರುಗಿ OPT_V;
    ಹಿಂತಿರುಗಿ OPT_HELP;
}

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಗಣ_options(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *r)
{
    ಅಕ್ಷರ **argv = ಖಾಲಿ;
    ಪೂರ್ಣಾಂಕ argc = 0, ret;
    dynarray_ಕೂಡಿಸು(&argv, &argc, 0);
    dynarray_ವಿಭಜಿಸು(&argv, &argc, r, 0);
    ret = tcc_parse_ವಾದಗಳು(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    ಹಿಂತಿರುಗಿ ret;
}

PUB_FUNC ಶೂನ್ಯ tcc_print_stats(TCCState *s1, ಚಿಹ್ನೆರಹಿತ ಒಟ್ಟು_ಸಮಯ)
{
    ಆದರೆ (!ಒಟ್ಟು_ಸಮಯ)
        ಒಟ್ಟು_ಸಮಯ = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           ಒಟ್ಟು_idents, ಒಟ್ಟು_ಸಾಲುಗಳು, ಒಟ್ಟು_ಬೈಟುಗಳು,
           (ದ್ವಿಗುಣ)ಒಟ್ಟು_ಸಮಯ/1000,
           (ಚಿಹ್ನೆರಹಿತ)ಒಟ್ಟು_ಸಾಲುಗಳು*1000/ಒಟ್ಟು_ಸಮಯ,
           (ದ್ವಿಗುಣ)ಒಟ್ಟು_ಬೈಟುಗಳು/1000/ಒಟ್ಟು_ಸಮಯ);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->ಒಟ್ಟು_output[0],
           s1->ಒಟ್ಟು_output[1],
           s1->ಒಟ್ಟು_output[2],
           s1->ಒಟ್ಟು_output[3]
           );
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ MEM_DEBUG
    fprintf(stderr, "# memory usage");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE
    ಆದರೆ (s1->ಸತತ_ಗಾತ್ರ) {
        Section *s = s1->symtab;
        ಚಿಹ್ನೆರಹಿತ ms = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + s->link->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ + s->hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
        ಚಿಹ್ನೆರಹಿತ rs = s1->ಸತತ_ಗಾತ್ರ;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_ಗಾತ್ರ - rs - ms);
    }
#ಆದರೆ_ಅಂತ್ಯ
    fprintf(stderr, " %d max (bytes)\n", mem_max_ಗಾತ್ರ);
#ಆದರೆ_ಅಂತ್ಯ
}
