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

#جے_بنا_تعریف ONE_سروت
# define ONE_سروت 1
#جے_انت

#إذا ONE_سروت
#ضمن "tccpp.c"
#ضمن "tccgen.c"
#ضمن "tccdbg.c"
#ضمن "tccasm.c"
#ضمن "tccelf.c"
#ضمن "tccrun.c"
#جے_تعریف_شدہ TCC_نشانہ_I386
#ضمن "i386-gen.c"
#ضمن "i386-link.c"
#ضمن "i386-asm.c"
#وإلاإذا defined(TCC_نشانہ_ARM)
#ضمن "arm-gen.c"
#ضمن "arm-link.c"
#ضمن "arm-asm.c"
#وإلاإذا defined(TCC_نشانہ_ARM64)
#ضمن "arm64-gen.c"
#ضمن "arm64-link.c"
#ضمن "arm64-asm.c"
#وإلاإذا defined(TCC_نشانہ_C67)
#ضمن "c67-gen.c"
#ضمن "c67-link.c"
#ضمن "tcccoff.c"
#وإلاإذا defined(TCC_نشانہ_X86_64)
#ضمن "x86_64-gen.c"
#ضمن "x86_64-link.c"
#ضمن "i386-asm.c"
#وإلاإذا defined(TCC_نشانہ_RISCV64)
#ضمن "riscv64-gen.c"
#ضمن "riscv64-link.c"
#ضمن "riscv64-asm.c"
#وإلا
#غلطی unknown نشانہ
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_PE
#ضمن "tccpe.c"
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_MACHO
#ضمن "tccmacho.c"
#جے_انت
#جے_انت /* ONE_SOURCE */

#ضمن "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_انکڑے بنية TCCState *tcc_state;
TCC_SEM(ساكن tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_انکڑے فراغ** stk_انکڑے;
ST_انکڑے صحيح nb_stk_انکڑے;
/* option -d<num> (for general development purposes) */
ST_انکڑے صحيح g_debug;

/********************************************************/
#جے_تعریف_شدہ _WIN32
ST_FUNC حرف *normalize_slashes(حرف *رستہ)
{
    حرف *p;
    لكل (p = رستہ; *p; ++p)
        إذا (*p == '\\')
            *p = '/';
    أرجع رستہ;
}

#إذا defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ساكن HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    إذا (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    أرجع TRUE;
}
#وإلا
#تعریف_کرو tcc_module عدم /* NULL means executable itself */
#جے_انت

#جے_بنا_تعریف CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ساكن مضمن حرف *config_tccdir_w32(حرف *رستہ)
{
    حرف *p;
    GetModuleFileNameA(tcc_module, رستہ, MAX_رستہ);
    p = tcc_basename(normalize_slashes(strlwr(رستہ)));
    إذا (p > رستہ)
        --p;
    *p = 0;
    أرجع رستہ;
}
#تعریف_کرو CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_رستہ))
#جے_انت

#جے_تعریف_شدہ TCC_IS_NATIVE
ساكن فراغ tcc_جوڑو_systemdir(TCCState *s)
{
    حرف buf[1000];
    GetSystemDirectoryA(buf, حجم buf);
    tcc_جوڑو_library_رستہ(s, normalize_slashes(buf));
}
#جے_انت
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m) {
    أرجع fopen(f, m);
}
PUB_FUNC صحيح tcc_fclose(FILE *f) {
    أرجع fclose(f);
}
#جے_انت
/********************************************************/

PUB_FUNC فراغ tcc_enter_state(TCCState *s1)
{
    إذا (s1->error_سیٹ_jmp_enabled)
        أرجع;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC فراغ tcc_exit_state(TCCState *s1)
{
    إذا (s1->error_سیٹ_jmp_enabled)
        أرجع;
    tcc_state = عدم;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, ناپ_t buf_ناپ, ثابت حرف *s)
{
    حرف *q, *q_سرا;
    صحيح c;

    إذا (buf_ناپ > 0) {
        q = buf;
        q_سرا = buf + buf_ناپ - 1;
        طالما (q < q_سرا) {
            c = *s++;
            إذا (c == '\0')
                اكسر;
            *q++ = c;
        }
        *q = '\0';
    }
    أرجع buf;
}

/* strcat and truncate. */
ST_FUNC حرف *pstrcat(حرف *buf, ناپ_t buf_ناپ, ثابت حرف *s)
{
    ناپ_t len;
    len = لڑی_لمبائی(buf);
    إذا (len < buf_ناپ)
        pstrcpy(buf + len, buf_ناپ - len, s);
    أرجع buf;
}

ST_FUNC حرف *pstrncpy(حرف *باہرلا, ناپ_t buf_ناپ, ثابت حرف *s, ناپ_t عدد)
{
    إذا (عدد >= buf_ناپ)
        عدد = buf_ناپ - 1;
    حافظہ_نقل(باہرلا, s, عدد);
    باہرلا[عدد] = '\0';
    أرجع باہرلا;
}

/* extract the basename of a file */
PUB_FUNC حرف *tcc_basename(ثابت حرف *name)
{
    حرف *p = (حرف *)strchr(name, 0);
    طالما (p > name && !IS_DIRSEP(p[-1]))
        --p;
    أرجع p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name)
{
    حرف *b = tcc_basename(name);
    حرف *e = strrchr(b, '.');
    أرجع e ? e : strchr(b, 0);
}

ST_FUNC حرف *tcc_لدو_متن(صحيح fd)
{
    صحيح len = lseek(fd, 0, SEEK_END);
    حرف *buf = لدو_انکڑے(fd, 0, len + 1);
    buf[len] = 0;
    أرجع buf;
}

/* replace *pp by copy of 'str' or NULL */
ساكن فراغ tcc_سیٹ_str(حرف **pp, ثابت حرف *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : عدم;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ساكن فراغ tcc_concat_str(حرف **pp, ثابت حرف *str, صحيح sep)
{
    صحيح l = *pp ? لڑی_لمبائی(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + لڑی_لمبائی(str) + 1);
    إذا (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#تعریف_رد حرر
#تعریف_رد realloc

ساكن فراغ *default_reallocator(فراغ *ptr, بنانشانی لما ناپ)
{
    فراغ *ptr1;
    إذا (ناپ == 0) {
        حرر(ptr);
        ptr1 = عدم;
    }
    وإلا {
        ptr1 = realloc(ptr, ناپ);
        إذا (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            باہر_نکلو (1);
        }
    }
    أرجع ptr1;
}

ST_FUNC فراغ libc_free(فراغ *ptr)
{
    حرر(ptr);
}

/* defined to be not used */
#تعریف_کرو حرر(p) use_tcc_free(p)
#تعریف_کرو realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ساكن فراغ *(*reallocator)(فراغ*, بنانشانی لما) = default_reallocator;

LIBTCCAPI فراغ tcc_سیٹ_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#تعریف_رد tcc_free
#تعریف_رد tcc_malloc
#تعریف_رد tcc_realloc
#تعریف_رد tcc_mallocz
#تعریف_رد tcc_strdup

PUB_FUNC فراغ tcc_free(فراغ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC فراغ *tcc_malloc(بنانشانی لما ناپ)
{
    أرجع reallocator(0, ناپ);
}

PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بنانشانی لما ناپ)
{
    أرجع reallocator(ptr, ناپ);
}

PUB_FUNC فراغ *tcc_mallocz(بنانشانی لما ناپ)
{
    فراغ *ptr;
    ptr = tcc_malloc(ناپ);
    إذا (ناپ)
        memset(ptr, 0, ناپ);
    أرجع ptr;
}

PUB_FUNC حرف *tcc_strdup(ثابت حرف *str)
{
    حرف *ptr;
    ptr = tcc_malloc(لڑی_لمبائی(str) + 1);
    strcpy(ptr, str);
    أرجع ptr;
}

#جے_تعریف_شدہ MEM_DEBUG

#تعریف_کرو MEM_DEBUG_MAGIC1 0xFEEDDEB1
#تعریف_کرو MEM_DEBUG_MAGIC2 0xFEEDDEB2
#تعریف_کرو MEM_DEBUG_MAGIC3 0xFEEDDEB3
#تعریف_کرو MEM_DEBUG_FILE_LEN 40
#تعریف_کرو MEM_DEBUG_CHECK3(سرخی) \
    (((بنانشانی حرف *) سرخی->magic3) + سرخی->ناپ)
#تعریف_کرو MEM_USER_PTR(سرخی) \
    ((حرف *)سرخی + offsetof(mem_debug_سرخی_t, magic3))
#تعریف_کرو MEM_سرخی_PTR(ptr) \
    (mem_debug_سرخی_t *)((حرف*)ptr - offsetof(mem_debug_سرخی_t, magic3))

بنية mem_debug_سرخی {
    بنانشانی magic1;
    بنانشانی ناپ;
    بنية mem_debug_سرخی *prev;
    بنية mem_debug_سرخی *اگلا;
    صحيح سطر_عدد;
    حرف file_name[MEM_DEBUG_FILE_LEN];
    بنانشانی magic2;
    ALIGNED(16) بنانشانی حرف magic3[4];
};

تعريفنوع بنية mem_debug_سرخی mem_debug_سرخی_t;

TCC_SEM(ساكن mem_sem);
ساكن mem_debug_سرخی_t *mem_debug_chain;
ساكن بنانشانی mem_cur_ناپ;
ساكن بنانشانی mem_max_ناپ;
ساكن صحيح nb_حالتاں;

ساكن mem_debug_سرخی_t *malloc_check(فراغ *ptr, ثابت حرف *پیغام)
{
    mem_debug_سرخی_t * سرخی = MEM_سرخی_PTR(ptr);
    إذا (سرخی->magic1 != MEM_DEBUG_MAGIC1 ||
        سرخی->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(سرخی)) != MEM_DEBUG_MAGIC3 ||
        سرخی->ناپ == (بنانشانی)-1) {
        fprintf(stderr, "%s check failed\n", پیغام);
        إذا (سرخی->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                سرخی->file_name, سرخی->سطر_عدد);
        باہر_نکلو(1);
    }
    أرجع سرخی;
}

PUB_FUNC فراغ *tcc_malloc_debug(بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر)
{
    صحيح ofs;
    mem_debug_سرخی_t *سرخی;
    إذا (!ناپ)
        أرجع عدم;
    سرخی = tcc_malloc(حجم(mem_debug_سرخی_t) + ناپ);
    سرخی->magic1 = MEM_DEBUG_MAGIC1;
    سرخی->magic2 = MEM_DEBUG_MAGIC2;
    سرخی->ناپ = ناپ;
    write32le(MEM_DEBUG_CHECK3(سرخی), MEM_DEBUG_MAGIC3);
    سرخی->سطر_عدد = سطر;
    ofs = لڑی_لمبائی(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(سرخی->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    سرخی->اگلا = mem_debug_chain;
    سرخی->prev = عدم;
    إذا (سرخی->اگلا)
        سرخی->اگلا->prev = سرخی;
    mem_debug_chain = سرخی;
    mem_cur_ناپ += ناپ;
    إذا (mem_cur_ناپ > mem_max_ناپ)
        mem_max_ناپ = mem_cur_ناپ;
    POST_SEM(&mem_sem);
    أرجع MEM_USER_PTR(سرخی);
}

PUB_FUNC فراغ tcc_free_debug(فراغ *ptr)
{
    mem_debug_سرخی_t *سرخی;
    إذا (!ptr)
        أرجع;
    سرخی = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_ناپ -= سرخی->ناپ;
    سرخی->ناپ = (بنانشانی)-1;
    إذا (سرخی->اگلا)
        سرخی->اگلا->prev = سرخی->prev;
    إذا (سرخی->prev)
        سرخی->prev->اگلا = سرخی->اگلا;
    إذا (سرخی == mem_debug_chain)
        mem_debug_chain = سرخی->اگلا;
    POST_SEM(&mem_sem);
    tcc_free(سرخی);
}

PUB_FUNC فراغ *tcc_mallocz_debug(بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر)
{
    فراغ *ptr;
    ptr = tcc_malloc_debug(ناپ,file,سطر);
    إذا (ناپ)
        memset(ptr, 0, ناپ);
    أرجع ptr;
}

PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بنانشانی لما ناپ, ثابت حرف *file, صحيح سطر)
{
    mem_debug_سرخی_t *سرخی;
    صحيح mem_debug_chain_update = 0;

    إذا (!ptr)
        أرجع tcc_malloc_debug(ناپ, file, سطر);
    إذا (!ناپ) {
        tcc_free_debug(ptr);
        أرجع عدم;
    }
    سرخی = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_ناپ -= سرخی->ناپ;
    mem_debug_chain_update = (سرخی == mem_debug_chain);
    سرخی = tcc_realloc(سرخی, حجم(mem_debug_سرخی_t) + ناپ);
    سرخی->ناپ = ناپ;
    write32le(MEM_DEBUG_CHECK3(سرخی), MEM_DEBUG_MAGIC3);
    إذا (سرخی->اگلا)
        سرخی->اگلا->prev = سرخی;
    إذا (سرخی->prev)
        سرخی->prev->اگلا = سرخی;
    إذا (mem_debug_chain_update)
        mem_debug_chain = سرخی;
    mem_cur_ناپ += ناپ;
    إذا (mem_cur_ناپ > mem_max_ناپ)
        mem_max_ناپ = mem_cur_ناپ;
    POST_SEM(&mem_sem);
    أرجع MEM_USER_PTR(سرخی);
}

PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سطر)
{
    حرف *ptr;
    ptr = tcc_malloc_debug(لڑی_لمبائی(str) + 1, file, سطر);
    strcpy(ptr, str);
    أرجع ptr;
}

PUB_FUNC فراغ tcc_memcheck(صحيح d)
{
    WAIT_SEM(&mem_sem);
    nb_حالتاں += d;
    إذا (0 == nb_حالتاں && mem_cur_ناپ) {
        mem_debug_سرخی_t *سرخی = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_ناپ, mem_max_ناپ);
        طالما (سرخی) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                سرخی->file_name, سرخی->سطر_عدد, سرخی->ناپ);
            سرخی = سرخی->اگلا;
        }
        fflush(stderr);
        mem_cur_ناپ = 0;
        mem_max_ناپ = 0;
        mem_debug_chain = عدم;
#إذا MEM_DEBUG-0 == 2
        باہر_نکلو(2);
#جے_انت
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#تعریف_کرو tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کرو tcc_malloc(ناپ)        tcc_malloc_debug(ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_mallocz(ناپ)       tcc_mallocz_debug(ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_realloc(ptr,ناپ)   tcc_realloc_debug(ptr, ناپ, __FILE__, __LINE__)
#تعریف_کرو tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#جے_انت /* MEM_DEBUG */

#جے_تعریف_شدہ _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#جے_انت

/* for #pragma once */
ST_FUNC صحيح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2)
{
    حرف *p1, *p2;
    صحيح ret = 1;
    إذا (!!(p1 = realpath(f1, عدم))) {
        إذا (!!(p2 = realpath(f2, عدم))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    أرجع ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC فراغ dynarray_جوڑو(فراغ *ptab, صحيح *nb_ptr, فراغ *انکڑے)
{
    صحيح nb, nb_alloc;
    فراغ **pp;

    nb = *nb_ptr;
    pp = *(فراغ ***)ptab;
    /* every power of two we double array size */
    إذا ((nb & (nb - 1)) == 0) {
        إذا (!nb)
            nb_alloc = 1;
        وإلا
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * حجم(فراغ *));
        *(فراغ***)ptab = pp;
    }
    pp[nb++] = انکڑے;
    *nb_ptr = nb;
}

ST_FUNC فراغ dynarray_reset(فراغ *pp, صحيح *n)
{
    فراغ **p;
    لكل (p = *(فراغ***)pp; *n; ++p, --*n)
        إذا (*p)
            tcc_free(*p);
    tcc_free(*(فراغ**)pp);
    *(فراغ**)pp = عدم;
}

ساكن فراغ dynarray_ونڈو(حرف ***argv, صحيح *argc, ثابت حرف *p, صحيح sep)
{
    صحيح qot, c;
    CString str;
    لكل(;;) {
        طالما (c = (بنانشانی حرف)*p, c <= ' ' && c != '\0')
            ++p;
        إذا (c == '\0')
            اكسر;
        cstr_new(&str);
        qot = 0;
        افعل {
            ++p;
            إذا (sep) { /* e.g. to split -Wl,-opt,arg */
                إذا (c == sep)
                    اكسر;
            } وإلا {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                إذا (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } وإلا إذا (c == '"') {
                    qot ^= 1;
                    استمر;
                } وإلا إذا (c <= ' ' && !qot) {
                    اكسر;
                }
            }
            cstr_ccat(&str, c);
        } طالما (c = (بنانشانی حرف)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_جوڑو(argv, argc, str.انکڑے);
    }
}

ساكن فراغ tcc_ونڈو_رستہ(TCCState *s, فراغ *p_ary, صحيح *p_nb_ary, ثابت حرف *وچ)
{
    ثابت حرف *p;
    افعل {
        صحيح c;
        CString str;

        cstr_new(&str);
        لكل (p = وچ; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            إذا (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                إذا (c == 'B')
                    cstr_cat(&str, s->tcc_lib_رستہ, -1);
                إذا (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                إذا (c == 'f' && file) {
                    /* substitute current file's dir */
                    ثابت حرف *f = file->true_filename;
                    ثابت حرف *b = tcc_basename(f);
                    إذا (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    وإلا
                        cstr_cat(&str, ".", 1);
                }
            } وإلا {
                cstr_ccat(&str, c);
            }
        }
        إذا (str.ناپ) {
            cstr_ccat(&str, '\0');
            dynarray_جوڑو(p_ary, p_nb_ary, str.انکڑے);
        }
        وچ = p+1;
    } طالما (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#تعریف_کرو WARN_ON  1 /* warning is on (-Woption) */
#تعریف_کرو WARN_ERR 2 /* warning is an error (-Werror=option) */
#تعریف_کرو WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
تعداد { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ساكن فراغ error1(صحيح منوال, ثابت حرف *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    صحيح سطر = 0;

    tcc_exit_state(s1);

    إذا (منوال == ERROR_WARN) {
        إذا (s1->warn_error)
            منوال = ERROR_ERROR;
        إذا (s1->warn_عدد) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            صحيح wopt = *(&s1->warn_none + s1->warn_عدد);
            s1->warn_عدد = 0;
            إذا (0 == (wopt & WARN_ON))
                أرجع;
            إذا (wopt & WARN_ERR)
                منوال = ERROR_ERROR;
            إذا (wopt & WARN_NOE)
                منوال = ERROR_WARN;
        }
        إذا (s1->warn_none)
            أرجع;
    }

    cstr_new(&cs);
    إذا (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        سطر = va_arg(ap, صحيح), fmt += 3;
    f = عدم;
    إذا (s1->error_سیٹ_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        لكل (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    إذا (f) {
        لكل(pf = s1->include_ڈھیر; pf < s1->include_ڈھیر_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->سطر_عدد - 1);
        إذا (0 == سطر)
            سطر = f->سطر_عدد - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, سطر);
    } وإلا إذا (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } وإلا {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, منوال == ERROR_WARN ? "warning: " : "error: ");
    إذا (pp_اظہاریہ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    وإلا
        cstr_vprintf(&cs, fmt, ap);
    إذا (!s1->error_func) {
        /* default case: stderr */
        إذا (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            لکھو("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (حرف*)cs.انکڑے);
        fflush(stderr); /* print error/warning now (win32) */
    } وإلا {
        s1->error_func(s1->error_opaque, (حرف*)cs.انکڑے);
    }
    cstr_free(&cs);
    إذا (منوال != ERROR_WARN)
        s1->nb_errors++;
    إذا (منوال == ERROR_ERROR && s1->error_سیٹ_jmp_enabled) {
        طالما (nb_stk_انکڑے)
            tcc_free(*(فراغ**)stk_انکڑے[--nb_stk_انکڑے]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI فراغ tcc_سیٹ_error_func(TCCState *s, فراغ *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC صحيح _tcc_error_noabort(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    أرجع -1;
}

#تعریف_رد _tcc_error
PUB_FUNC فراغ _tcc_error(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    باہر_نکلو(1);
}
#تعریف_کرو _tcc_error use_tcc_error_noabort

PUB_FUNC فراغ _tcc_warning(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC فراغ tcc_open_bf(TCCState *s1, ثابت حرف *filename, صحيح initlen)
{
    BufferedFile *bf;
    صحيح buflen = initlen ? initlen : IO_BUF_ناپ;

    bf = tcc_mallocz(حجم(BufferedFile) + buflen);
    bf->buf_ptr = bf->بفر;
    bf->buf_سرا = bf->بفر + initlen;
    bf->buf_سرا[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, حجم(bf->filename), filename);
#جے_تعریف_شدہ _WIN32
    normalize_slashes(bf->filename);
#جے_انت
    bf->true_filename = bf->filename;
    bf->سطر_عدد = 1;
    bf->ifdef_ڈھیر_ptr = s1->ifdef_ڈھیر_ptr;
    bf->fd = -1;
    bf->prev = file;
    bf->prev_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC فراغ tcc_close(فراغ)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    إذا (bf->fd > 0) {
        close(bf->fd);
        کل_سطریں += bf->سطر_عدد - 1;
    }
    إذا (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->prev;
    tok_flags = bf->prev_tok_flags;
    tcc_free(bf);
}

ساكن صحيح _tcc_open(TCCState *s1, ثابت حرف *filename)
{
    صحيح fd;
    إذا (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    وإلا
        fd = open(filename, O_RDONLY | O_ثنائی_2);
    إذا ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        لکھو("%s %*s%s\n", fd < 0 ? "nf":"->",
               (صحيح)(s1->include_ڈھیر_ptr - s1->include_ڈھیر), "", filename);
    أرجع fd;
}

ST_FUNC صحيح tcc_open(TCCState *s1, ثابت حرف *filename)
{
    صحيح fd = _tcc_open(s1, filename);
    إذا (fd < 0)
        أرجع -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    أرجع 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ساكن صحيح tcc_compile(TCCState *s1, صحيح filetype, ثابت حرف *str, صحيح fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_سیٹ_jmp_enabled = 1;

    إذا (setjmp(s1->error_jmp_buf) == 0) {

        إذا (fd == -1) {
            صحيح len = لڑی_لمبائی(str);
            tcc_open_bf(s1, "<string>", len);
            حافظہ_نقل(file->بفر, str, len);
        } وإلا {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_شروع(s1, filetype);
        tccgen_init(s1);

        إذا (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } وإلا {
            tccelf_begin_file(s1);
            إذا (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } وإلا {
                tccgen_compile(s1);
            }
            tccelf_سرا_file(s1);
        }
    }
    tccgen_انت(s1);
    preprocess_سرا(s1);
    s1->error_سیٹ_jmp_enabled = 0;
    tcc_exit_state(s1);
    أرجع s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI صحيح tcc_compile_string(TCCState *s, ثابت حرف *str)
{
    أرجع tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI فراغ tcc_define_علامت(TCCState *s1, ثابت حرف *sym, ثابت حرف *قدر)
{
    ثابت حرف *eq;
    إذا (عدم == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    إذا (عدم == قدر)
        قدر = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (صحيح)(eq-sym), sym, قدر);
}

/* undefine a preprocessor symbol */
LIBTCCAPI فراغ tcc_undefine_علامت(TCCState *s1, ثابت حرف *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(فراغ)
{
    TCCState *s;

    s = tcc_mallocz(حجم(TCCState));
#جے_تعریف_شدہ MEM_DEBUG
    tcc_memcheck(1);
#جے_انت

#تعریف_رد gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_وچ_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#جے_تعریف_شدہ CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#جے_انت
#جے_تعریف_شدہ TCC_نشانہ_I386
    s->seg_ناپ = 32;
#جے_انت
    /* enable this if you want symbols with leading underscore on windows: */
#إذا defined TCC_نشانہ_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#جے_انت
#جے_تعریف_شدہ TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#جے_انت
#إذا defined TCC_نشانہ_ARM64 && defined TCC_نشانہ_PE
    s->pe_dll_characteristics = 0x8160;
#جے_انت
#جے_تعریف_شدہ CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#جے_انت
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ڈھیر_ptr = s->include_ڈھیر;

    tcc_سیٹ_lib_رستہ(s, CONFIG_TCCDIR);
#جے_تعریف_شدہ CONFIG_TCC_SWITCHES /* predefined options */
    tcc_سیٹ_options(s, CONFIG_TCC_SWITCHES);
#جے_انت
    أرجع s;
}

LIBTCCAPI فراغ tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_رستہ);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_علامت);
    tcc_free(s1->fini_علامت);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#إذا defined TCC_نشانہ_MACHO
    tcc_free(s1->install_name);
#جے_انت
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->نشانہ_deps, &s1->nb_نشانہ_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#جے_تعریف_شدہ TCC_IS_NATIVE
    /* free runtime memory */
    tcc_لگاتار_free(s1);
#جے_انت
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#جے_تعریف_شدہ MEM_DEBUG
    tcc_memcheck(-1);
#جے_انت
}

LIBTCCAPI صحيح tcc_سیٹ_output_type(TCCState *s, صحيح output_type)
{
#جے_تعریف_شدہ CONFIG_TCC_PIE
    إذا (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#جے_انت
    s->output_type = output_type;

    إذا (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_جوڑو_sysinclude_رستہ(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    إذا (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        أرجع 0;
    }

    /* add sections */
    tccelf_new(s);

    إذا (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        أرجع 0;
    }

    إذا (!s->nostdlib_paths)
        tcc_جوڑو_library_رستہ(s, CONFIG_TCC_LIBPATHS);

#جے_تعریف_شدہ TCC_نشانہ_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_جوڑو_systemdir(s);
# endif

#وإلاإذا defined TCC_نشانہ_MACHO
# ifdef TCC_IS_NATIVE
    tcc_جوڑو_macos_sdkpath(s);
# endif

#وإلا
    /* paths for crt objects */
    tcc_ونڈو_رستہ(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    إذا (output_type != TCC_OUTPUT_حافظہ && !s->nostdlib)
        tccelf_جوڑو_crtbegin(s); /* may produce errors */
#جے_انت
    أرجع s->nb_errors ? -1 : 0;
}

LIBTCCAPI صحيح tcc_جوڑو_include_رستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_ونڈو_رستہ(s, &s->include_paths, &s->nb_include_paths, pathname);
    أرجع 0;
}

LIBTCCAPI صحيح tcc_جوڑو_sysinclude_رستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_ونڈو_رستہ(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    أرجع 0;
}

LIBTCCAPI صحيح tcc_جوڑو_library_رستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_ونڈو_رستہ(s, &s->library_paths, &s->nb_library_paths, pathname);
    أرجع 0;
}

LIBTCCAPI فراغ tcc_سیٹ_lib_رستہ(TCCState *s, ثابت حرف *رستہ)
{
    tcc_سیٹ_str(&s->tcc_lib_رستہ, رستہ);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_جوڑو_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level)
{
    DLLReference *ref = عدم;
    صحيح i;
    لكل (i = 0; i < s1->nb_loaded_dlls; i++)
        إذا (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            اكسر;
        }
    إذا (level == -1)
        أرجع ref;
    إذا (ref) {
        إذا (level < ref->level)
            ref->level = level;
        ref->لبھیا = 1;
        أرجع ref;
    }
    ref = tcc_mallocz(حجم(DLLReference) + لڑی_لمبائی(dllname));
    strcpy(ref->name, dllname);
    dynarray_جوڑو(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->اشاریہ = s1->nb_loaded_dlls;
    أرجع ref;
}

ساكن صحيح tcc_جوڑو_ثنائی(TCCState *s1, صحيح flags, ثابت حرف *filename, صحيح fd)
{
    ElfW(Ehdr) ehdr;
    صحيح obj_type;
    ثابت حرف *saved_filename = s1->current_filename;
    صحيح ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    بدل (obj_type) {

    حالة AFF_BINTYPE_REL:
        ret = tcc_لدو_object_file(s1, fd, 0);
        اكسر;

    حالة AFF_BINTYPE_AR:
        ret = tcc_لدو_archive(s1, fd, !(flags & AFF_سارا_ARCHIVE));
        اكسر;

#إذا defined TCC_نشانہ_UNIX
    حالة AFF_BINTYPE_DYN:
        إذا (s1->output_type == TCC_OUTPUT_حافظہ) {
#جے_تعریف_شدہ TCC_IS_NATIVE
            فراغ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            إذا (dl)
                tcc_جوڑو_dllref(s1, filename, 0)->handle = dl;
            وإلا
                ret = FILE_NOT_RECOGNIZED;
#جے_انت
        } وإلا
            ret = tcc_لدو_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        اكسر;

    افتراضي:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_لدو_ldscript(s1, fd);
        اكسر;

#وإلاإذا defined TCC_نشانہ_MACHO
    حالة AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        إذا (s1->output_type == TCC_OUTPUT_حافظہ) {
#جے_تعریف_شدہ TCC_IS_NATIVE
            فراغ* dl;
            ثابت حرف* soname = filename;
            حرف *tmp = 0;
            إذا (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                إذا (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            إذا (dl)
                tcc_جوڑو_dllref(s1, soname, 0)->handle = dl;
            وإلا
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#جے_انت
        } وإلا إذا (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_لدو_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } وإلا {
            ret = macho_لدو_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        إذا (ret)
            ret = FILE_NOT_RECOGNIZED;
        اكسر;

    افتراضي:
    {
        ثابت حرف *ext = tcc_fileextension(filename);
        إذا (!strcmp(ext, ".tbd"))
            اذهب case_dyn_or_tbd;
        إذا (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            اذهب case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        اكسر;
    }

#وإلاإذا defined TCC_نشانہ_PE
    افتراضي:
        إذا (pe_لدو_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        اكسر;
#جے_انت

#جے_تعریف_شدہ TCC_نشانہ_COFF
    حالة AFF_BINTYPE_C67:
        ret = tcc_لدو_coff(s1, fd);
        اكسر;
#جے_انت
    }

    close(fd);
    s1->current_filename = saved_filename;
    إذا (ret == FILE_NOT_RECOGNIZED)
        أرجع tcc_error_noabort("%s: unrecognized file type", filename);
    أرجع ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#إذا defined TARGETOS_OpenBSD && !defined _WIN32
#ضمن <glob.h>
ساكن صحيح tcc_glob_so(TCCState *s1, ثابت حرف *نمونہ, حرف *buf, صحيح ناپ)
{
    ثابت حرف *تارا;
    glob_t g;
    حرف *p;
    صحيح i, v, v1, v2, v3;

    تارا = strchr(نمونہ, '*');
    إذا (!تارا || glob(نمونہ, 0, عدم, &g))
        أرجع -1;
    لكل (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        إذا (2 != لڑی_توں_پڑھو(p + (تارا - نمونہ), "%d.%d.%d", &v1, &v2, &v3))
            استمر;
        إذا ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, ناپ, p);
    }
    globfree(&g);
    أرجع v;
}
#جے_انت

ساكن صحيح guess_filetype(ثابت حرف *filename)
{
    صحيح filetype = 0;
    إذا (1) {
        /* use a file extension to detect a filetype */
        ثابت حرف *ext = tcc_fileextension(filename);
        إذا (ext[0]) {
            ext++;
            إذا (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            وإلا إذا (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            وإلا إذا (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            وإلا
                filetype |= AFF_TYPE_BIN;
        } وإلا {
            filetype = AFF_TYPE_C;
        }
    }
    أرجع filetype;
}

ST_FUNC صحيح tcc_جوڑو_file_اندرونی(TCCState *s1, ثابت حرف *filename, صحيح flags)
{
    صحيح fd;

#إذا defined TARGETOS_OpenBSD && !defined _WIN32
    حرف buf[1024];
    إذا (tcc_glob_so(s1, filename, buf, حجم buf) >= 0)
        filename = buf;
#جے_انت

    إذا (0 == (flags & AFF_TYPE_نقاب))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    إذا (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        أرجع 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    إذا (fd < 0) {
        إذا (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        أرجع FILE_NOT_لبھیا;
    }

    إذا (flags & AFF_TYPE_BIN)
        أرجع tcc_جوڑو_ثنائی(s1, flags, filename, fd);

    dynarray_جوڑو(&s1->نشانہ_deps, &s1->nb_نشانہ_deps, tcc_strdup(filename));
    أرجع tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI صحيح tcc_جوڑو_file(TCCState *s, ثابت حرف *filename)
{
    أرجع tcc_جوڑو_file_اندرونی(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ساكن صحيح tcc_جوڑو_library_اندرونی(TCCState *s1, ثابت حرف *fmt,
    ثابت حرف *filename, صحيح flags, حرف **paths, صحيح nb_paths)
{
    حرف buf[1024];
    صحيح i, ret;

    لكل(i = 0; i < nb_paths; i++) {
        snprintf(buf, حجم(buf), fmt, paths[i], filename);
        ret = tcc_جوڑو_file_اندرونی(s1, buf, flags & ~AFF_PRINT_ERROR);
        إذا (ret != FILE_NOT_لبھیا)
            أرجع ret;
    }
    إذا (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    أرجع FILE_NOT_لبھیا;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC صحيح tcc_جوڑو_dll(TCCState *s, ثابت حرف *filename, صحيح flags)
{
    أرجع tcc_جوڑو_library_اندرونی(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC صحيح tcc_جوڑو_support(TCCState *s1, ثابت حرف *filename)
{
    حرف buf[100];
    إذا (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    أرجع tcc_جوڑو_dll(s1, filename, AFF_PRINT_ERROR);
}

#جے_تعریف_شدہ TCC_نشانہ_UNIX
ST_FUNC صحيح tcc_جوڑو_crt(TCCState *s1, ثابت حرف *filename)
{
    أرجع tcc_جوڑو_library_اندرونی(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#جے_انت

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحيح tcc_جوڑو_library(TCCState *s, ثابت حرف *libraryname)
{
    ساكن ثابت حرف * ثابت libs[] = {
#إذا defined TCC_نشانہ_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#وإلاإذا defined TCC_نشانہ_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#وإلاإذا defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#وإلا
        "%s/lib%s.so",
#جے_انت
        "%s/lib%s.a",
        عدم
    };
    صحيح flags = AFF_TYPE_LIB | (s->filetype & AFF_سارا_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    إذا (*libraryname == ':') {
        libraryname++;
    } وإلا {
        ثابت حرف * ثابت *pp = libs;
        إذا (s->static_link)
            pp += حجم(libs) / حجم(*libs) - 2; /* only "%s/lib%s.a" */
        طالما (*pp) {
            صحيح ret = tcc_جوڑو_library_اندرونی(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            إذا (ret != FILE_NOT_لبھیا)
                أرجع ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    أرجع tcc_جوڑو_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC فراغ tcc_جوڑو_pragma_libs(TCCState *s1)
{
    صحيح i;
    لكل (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_جوڑو_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ساكن صحيح strstart(ثابت حرف *val, ثابت حرف **str)
{
    ثابت حرف *p, *q;
    p = *str;
    q = val;
    طالما (*q) {
        إذا (*p != *q)
            أرجع 0;
        p++;
        q++;
    }
    *str = p;
    أرجع 1;
}

بنية lopt {
    TCCState *s;
    ثابت حرف *opt, *arg;
    صحيح میل;
};

/* match linker option */
ساكن صحيح link_option(بنية lopt *o, ثابت حرف *q)
{
    ثابت حرف *p;
    صحيح c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    إذا (*p++ != '-')
        أرجع 0;
    إذا (*p == '-')
        p++;
    r = 1;
    إذا (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        إذا (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#جے_تعریف_شدہ TCC_نشانہ_PE
        وإلا إذا (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#جے_انت
    }
    طالما ((c = *q) == *p) {
        إذا (c == '\0')
            اذهب succ; /* -Wl,-opt */
        ++p;
        إذا (c == '=')
            اذهب succ; /* -Wl,-opt=arg */
        ++q;
    }
    إذا (*p == '\0') {
        إذا (c == '|')
            اذهب succ;
        إذا (c == '=' || c == ':') {
            إذا (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                اذهب succ; /* -Wl,-opt,arg */
            }
            o->میل = 1; /* -Wl,-opt -Wl,arg */
            أرجع 0;
        }
    } وإلا إذا (c == ':')
        اذهب succ; /* -Wl,-Iarg */
    طالما (*q)
        إذا (*q++ == '|')
            اذهب redo;
    أرجع 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    أرجع r;
}

ساكن فراغ دلیلاں_parser_جوڑو_file(TCCState *s, ثابت حرف* filename, صحيح filetype);

#تعریف_کرو سیٹ_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#تعریف_کرو سیٹ_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ساكن صحيح tcc_سیٹ_linker(TCCState *s, ثابت حرف *optarg)
{
    TCCState *s1 = s;

    dynarray_ونڈو(&s1->link_argv, &s1->link_argc, optarg, ',');

    طالما (s->link_optind < s->link_argc) {
        حرف *سرا = عدم;
        صحيح ignoring = 0;
        بنية lopt o = {0};
        صحيح r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        إذا (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } وإلا إذا (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } وإلا إذا (link_option(&o, "e=|entry=")) {
            tcc_سیٹ_str(&s->elf_entryname, o.arg);
        } وإلا إذا (link_option(&o, "image-base=|Ttext=")) {
            s->متن_addr = strtoull(o.arg, &سرا, 16);
            s->has_متن_addr = 1;
        } وإلا إذا (link_option(&o, "init=")) {
            tcc_سیٹ_str(&s->init_علامت, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "fini=")) {
            tcc_سیٹ_str(&s->fini_علامت, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "Map=")) {
            tcc_سیٹ_str(&s->mapfile, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "oformat=")) {
#إذا defined TCC_نشانہ_PE
            إذا (0 == لڑی_مقابلہ("pe-", o.arg, 3))
#وإلاإذا PTR_ناپ == 8
            إذا (0 == لڑی_مقابلہ("elf64-", o.arg, 6))
#وإلا
            إذا (0 == لڑی_مقابلہ("elf32-", o.arg, 6))
#جے_انت
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            وإلا إذا (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ثنائی;
#إذا defined TCC_نشانہ_COFF
            وإلا إذا (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#جے_انت
            وإلا
                اذهب err;
        } وإلا إذا (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } وإلا إذا (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } وإلا إذا (link_option(&o, "dynamic-linker=|I:")) {
            tcc_سیٹ_str(&s->elfint, o.arg);
        } وإلا إذا (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } وإلا إذا (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &سرا, 16);
        } وإلا إذا (link_option(&o, "soname=|install_name=")) {
            tcc_سیٹ_str(&s->soname, o.arg);
        } وإلا إذا (!!(r = link_option(&o, "?whole-archive"))) {
            سیٹ_OR_CLEAR(s->filetype, AFF_سارا_ARCHIVE);
        } وإلا إذا (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#جے_تعریف_شدہ TCC_نشانہ_PE
        } وإلا إذا (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } وإلا إذا (!!(r = link_option(&o, "?dynamicbase"))) {
            سیٹ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } وإلا إذا (!!(r = link_option(&o, "?high-entropy-va"))) {
            سیٹ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } وإلا إذا (!!(r = link_option(&o, "?nxcompat"))) {
            سیٹ_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } وإلا إذا (!!(r = link_option(&o, "?tsaware"))) {
            سیٹ_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } وإلا إذا (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &سرا, 16);
        } وإلا إذا (link_option(&o, "stack=")) {
            s->pe_ڈھیر_ناپ = strtoul(o.arg, &سرا, 10);
        } وإلا إذا (link_option(&o, "subsystem=")) {
            إذا (pe_setsubsy(s, o.arg) < 0)
                اذهب err;
#وإلاإذا defined TCC_نشانہ_MACHO
        } وإلا إذا (link_option(&o, "all_load")) {
	    s->filetype |= AFF_سارا_ARCHIVE;
        } وإلا إذا (link_option(&o, "force_load=")) {
            دلیلاں_parser_جوڑو_file(s, o.arg, AFF_TYPE_LIB | AFF_سارا_ARCHIVE);
        } وإلا إذا (link_option(&o, "single_module")) {
            ignoring = 1;
#جے_انت
        } وإلا إذا (link_option(&o, "as-needed")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "O")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "z=")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "L:")) {
            tcc_جوڑو_library_رستہ(s, o.arg);
        } وإلا إذا (link_option(&o, "l:")) {
            دلیلاں_parser_جوڑو_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_نقاب));
        } وإلا إذا (o.میل) {
            أرجع 0; /* expecting argument with next '-Wl,' */
        } وإلا {
    err:
            أرجع tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        إذا (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    أرجع 0;
}

تعريفنوع بنية TCCOption {
    ثابت حرف *name;
    uint16_t اشاریہ;
    uint16_t flags;
} TCCOption;

تعداد {
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
    TCC_OPTION_print_تلاش_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_لگاتار,
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
    TCC_OPTION_compatibility_نسخہ ,
    TCC_OPTION_current_نسخہ,
};

#تعریف_کرو TCC_OPTION_HAS_ARG 0x0001
#تعریف_کرو TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

ساكن ثابت TCCOption tcc_options[] = {
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
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#جے_انت
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#جے_انت
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#جے_تعریف_شدہ TCC_نشانہ_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_نسخہ, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_نسخہ, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#جے_انت
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
    { "run", TCC_OPTION_لگاتار, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#جے_تعریف_شدہ TCC_نشانہ_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#جے_انت
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_تلاش_dirs, 0 },
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
#جے_تعریف_شدہ TCC_نشانہ_PE
    { "impdef", TCC_OPTION_impdef, 0},
#جے_انت
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
    { عدم, 0, 0 },
};

تعريفنوع بنية FlagDef {
    uint16_t وتھ;
    uint16_t flags;
    ثابت حرف *name;
} FlagDef;

#تعریف_کرو WD_ALL    0x0001 /* warning is activated when using -Wall */
#تعریف_کرو FD_INVERT 0x0002 /* invert value before storing */

ساكن ثابت FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_لڑیاں), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, عدم }
};

ساكن ثابت FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_وچ_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, الٹ_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, عدم }
};

ساكن ثابت FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#جے_تعریف_شدہ TCC_نشانہ_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#جے_انت
    { 0, 0, عدم }
};

ساكن صحيح سیٹ_flag(TCCState *s, ثابت FlagDef *flags, ثابت حرف *name)
{
    صحيح قدر, نقاب, ret;
    ثابت FlagDef *p;
    ثابت حرف *r;
    بنانشانی حرف *f;

    r = name, قدر = !strstart("no-", &r), نقاب = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    إذا ((flags->flags & WD_ALL) && strstart("error=", &r))
        قدر = قدر ? WARN_ON|WARN_ERR : WARN_NOE, نقاب = WARN_ON;

    لكل (ret = -1, p = flags; p->name; ++p) {
        إذا (ret) {
            إذا (strcmp(r, p->name))
                استمر;
        } وإلا {
            إذا (0 == (p->flags & WD_ALL))
                استمر;
        }

        f = (بنانشانی حرف *)s + p->وتھ;
        *f = (*f & نقاب) | (قدر ^ !!(p->flags & FD_INVERT));

        إذا (ret) {
            ret = 0;
            إذا (strcmp(r, "all"))
                اكسر;
        }
    }
    أرجع ret;
}

ساكن ثابت حرف dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#جے_تعریف_شدہ TCC_نشانہ_I386
    "i386-pc"
#وإلاإذا defined TCC_نشانہ_X86_64
    "x86_64-pc"
#وإلاإذا defined TCC_نشانہ_C67
    "c67"
#وإلاإذا defined TCC_نشانہ_ARM
    "arm"
#وإلاإذا defined TCC_نشانہ_ARM64
    "aarch64"
#وإلاإذا defined TCC_نشانہ_RISCV64
    "riscv64"
#جے_انت
    "-"
#جے_تعریف_شدہ TCC_نشانہ_PE
    "mingw32"
#وإلاإذا defined(TCC_نشانہ_MACHO)
    "apple-darwin"
#وإلاإذا TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#وإلاإذا TARGETOS_OpenBSD
    "openbsd"
#وإلاإذا TARGETOS_NetBSD
    "netbsd"
#وإلاإذا CONFIG_TCC_MUSL
    "linux-musl"
#وإلا
    "linux-gnu"
#جے_انت
;

#إذا defined TCC_نشانہ_MACHO
ساكن uint32_t parse_نسخہ(TCCState *s1, ثابت حرف *نسخہ)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    حرف* آخری;

    a = strtoul(نسخہ, &آخری, 10);
    إذا (*آخری == '.') {
        b = strtoul(&آخری[1], &آخری, 10);
        إذا (*آخری == '.')
             c = strtoul(&آخری[1], &آخری, 10);
    }
    إذا (*آخری || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", نسخہ);
    أرجع (a << 16) | (b << 8) | c;
}
#جے_انت

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ساكن فراغ داخل_کرو_دلیلاں(TCCState *s1, حرف ***pargv, صحيح *pargc, صحيح optind, ثابت حرف *p, صحيح sep)
{
    صحيح argc = 0;
    حرف **argv = عدم;
    صحيح i;
    لكل (i = 0; i < *pargc; ++i)
        إذا (i == optind)
            dynarray_ونڈو(&argv, &argc, p, sep);
        وإلا
            dynarray_جوڑو(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ساكن فراغ دلیلاں_parser_جوڑو_file(TCCState *s, ثابت حرف* filename, صحيح filetype)
{
    بنية filespec *f = tcc_malloc(حجم *f + لڑی_لمبائی(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_جوڑو(&s->files, &s->nb_files, f);
    إذا (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC صحيح tcc_parse_دلیلاں(TCCState *s, صحيح *pargc, حرف ***pargv)
{
    TCCState *s1 = s;
    ثابت TCCOption *popt;
    ثابت حرف *optarg, *r;
    ثابت حرف *لگاتار = عدم;
    صحيح optind = 1, خالی_تھاواں = 1, x;
    حرف **argv = *pargv;
    صحيح argc = *pargc;

    s->link_optind = s->link_argc;

    طالما (optind < argc) {
        r = argv[optind];
        إذا (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            صحيح fd; حرف *p;
            fd = open(++r, O_RDONLY | O_ثنائی_2);
            إذا (fd < 0)
                أرجع tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_لدو_متن(fd);
            داخل_کرو_دلیلاں(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            استمر;
        }
        optind++;
        إذا (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            دلیلاں_parser_جوڑو_file(s, r, s->filetype);
            خالی_تھاواں = 0;
        dorun:
            إذا (لگاتار)
                اكسر;
            استمر;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        إذا (r[1] == '-' && r[2] == '\0')
            اذهب dorun;

        /* find option in table */
        لكل(popt = tcc_options; ; ++popt) {
            ثابت حرف *p1 = popt->name;
            ثابت حرف *r1 = r + 1;
            إذا (p1 == عدم)
                أرجع tcc_error_noabort("invalid option -- '%s'", r);
            إذا (!strstart(p1, &r1))
                استمر;
            optarg = r1;
            إذا (popt->flags & TCC_OPTION_HAS_ARG) {
                إذا (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    إذا (optind >= argc)
                        أرجع tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } وإلا إذا (*r1 != '\0')
                استمر;
            اكسر;
        }

        بدل(popt->اشاریہ) {
        حالة TCC_OPTION_I:
            tcc_جوڑو_include_رستہ(s, optarg);
            اكسر;
        حالة TCC_OPTION_D:
            tcc_define_علامت(s, optarg, عدم);
            اكسر;
        حالة TCC_OPTION_U:
            tcc_undefine_علامت(s, optarg);
            اكسر;
        حالة TCC_OPTION_L:
            tcc_جوڑو_library_رستہ(s, optarg);
            اكسر;
        حالة TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_سیٹ_lib_رستہ(s, optarg);
            استمر;
        حالة TCC_OPTION_l:
            دلیلاں_parser_جوڑو_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_نقاب));
            اكسر;
        حالة TCC_OPTION_pthread:
            s->option_pthread = 1;
            اكسر;
        حالة TCC_OPTION_bench:
            s->do_bench = 1;
            اكسر;
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
        حالة TCC_OPTION_bt:
            s->rt_عدد_callers = atoi(optarg); /* zero = default (6) */
            اذهب enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            إذا (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_نسخہ;
            اكسر;
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        حالة TCC_OPTION_b:
            s->do_bounds_check = 1;
            اذهب enable_backtrace;
#جے_انت
#جے_انت
        حالة TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_نسخہ;
        g_redo:
            إذا (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_نسخہ;
            } وإلا إذا (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } وإلا إذا (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                اذهب g_redo;
#جے_تعریف_شدہ TCC_نشانہ_PE
            } وإلا إذا (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#جے_انت
            }
            اكسر;
        حالة TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        سیٹ_output_type:
            إذا (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            اكسر;
        حالة TCC_OPTION_d:
            إذا (*optarg == 'D')
                s->dflag = 3;
            وإلا إذا (*optarg == 'M')
                s->dflag = 7;
            وإلا إذا (*optarg == 't')
                s->dflag = 16;
            وإلا إذا (isnum(*optarg))
                g_debug |= atoi(optarg);
            وإلا
                اذهب unsupported_option;
            اكسر;
        حالة TCC_OPTION_static:
            s->static_link = 1;
            اكسر;
        حالة TCC_OPTION_std:
            إذا (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            اكسر;
        حالة TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            اذهب سیٹ_output_type;
        حالة TCC_OPTION_soname:
            tcc_سیٹ_str(&s->soname, optarg);
            اكسر;
        حالة TCC_OPTION_o:
            إذا (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_سیٹ_str(&s->outfile, optarg);
            اكسر;
        حالة TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            اذهب سیٹ_output_type;
        حالة TCC_OPTION_isystem:
            tcc_جوڑو_sysinclude_رستہ(s, optarg);
            اكسر;
        حالة TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            اكسر;
        حالة TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            اكسر;
        حالة TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            اكسر;
        حالة TCC_OPTION_لگاتار:
#جے_تعریف_شدہ TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            لگاتار = optarg;
            x = TCC_OUTPUT_حافظہ;
            اذهب سیٹ_output_type;
#وإلا
            أرجع tcc_error_noabort("-run is not available in a cross compiler");
#جے_انت
#جے_تعریف_شدہ TCC_IS_NATIVE
        حالة TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->لگاتار_stdin = optarg;
            اكسر;
#جے_انت
        حالة TCC_OPTION_v:
            افعل ++s->verbose; طالما (*optarg++ == 'v');
            استمر;
        حالة TCC_OPTION_f:
            إذا (سیٹ_flag(s, options_f, optarg) < 0)
                اذهب unsupported_option;
            اكسر;
#جے_تعریف_شدہ TCC_نشانہ_ARM
        حالة TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            إذا (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } وإلا إذا (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            وإلا
                أرجع tcc_error_noabort("unsupported float abi '%s'", optarg);
            استمر;
#جے_انت
        حالة TCC_OPTION_m:
            إذا (سیٹ_flag(s, options_m, optarg) < 0) {
                إذا (x = atoi(optarg), x != 32 && x != 64)
                    اذهب unsupported_option;
                إذا (PTR_ناپ != x/8)
                    أرجع x;
                استمر;
            }
            اكسر;
        حالة TCC_OPTION_W:
            إذا (optarg[0] && سیٹ_flag(s, options_W, optarg) < 0)
                اذهب unsupported_option;
            اكسر;
        حالة TCC_OPTION_w:
            s->warn_none = 1;
            اكسر;
        حالة TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            اكسر;
        حالة TCC_OPTION_Wl:
            إذا (tcc_سیٹ_linker(s, optarg) < 0)
                أرجع -1;
            اكسر;
        حالة TCC_OPTION_Wp:
            إذا (argv[0]) /* not with tcc_set_options() */
                داخل_کرو_دلیلاں(s, &argv, &argc, --optind, optarg, ',');
            اكسر;
        حالة TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            اذهب سیٹ_output_type;
        حالة TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            اكسر;

        حالة TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        حالة TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            إذا (!s->deps_outfile)
                tcc_سیٹ_str(&s->deps_outfile, "-");
            اكسر;
        حالة TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        حالة TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            إذا (*optarg != ',')
                اكسر;
            ++optarg;
            // fall through
        حالة TCC_OPTION_MF:
            tcc_سیٹ_str(&s->deps_outfile, optarg);
            اكسر;
        حالة TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            اكسر;

        حالة TCC_OPTION_dumpmachine:
            لکھو("%s\n", dumpmachine_str);
            باہر_نکلو(0);
        حالة TCC_OPTION_dumpversion:
            لکھو ("%s\n", TCC_نسخہ);
            باہر_نکلو(0);

        حالة TCC_OPTION_x:
            x = 0;
            إذا (*optarg == 'c')
                x = AFF_TYPE_C;
            وإلا إذا (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            وإلا إذا (*optarg == 'b')
                x = AFF_TYPE_BIN;
            وإلا إذا (*optarg == 'n')
                x = AFF_TYPE_NONE;
            وإلا
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_نقاب);
            اكسر;
        حالة TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            اكسر;
#إذا defined TCC_نشانہ_MACHO
        حالة TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            اذهب سیٹ_output_type;
        حالة TCC_OPTION_flat_namespace:
	     اكسر;
        حالة TCC_OPTION_two_levelnamespace:
	     اكسر;
        حالة TCC_OPTION_undefined:
	     اكسر;
        حالة TCC_OPTION_install_name:
	    tcc_سیٹ_str(&s->install_name, optarg);
            اكسر;
        حالة TCC_OPTION_compatibility_نسخہ:
	    s->compatibility_نسخہ = parse_نسخہ(s, optarg);
            اكسر;
        حالة TCC_OPTION_current_نسخہ:
	    s->current_نسخہ = parse_نسخہ(s, optarg);;
            اكسر;
#جے_انت
        حالة TCC_OPTION_HELP:
            x = OPT_HELP;
            اذهب extra_action;
        حالة TCC_OPTION_HELP2:
            x = OPT_HELP2;
            اذهب extra_action;
        حالة TCC_OPTION_print_تلاش_dirs:
            x = OPT_PRINT_DIRS;
            اذهب extra_action;
        حالة TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            اذهب extra_action;
        حالة TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            إذا (عدم == argv[0]) /* from tcc_set_options() */
                أرجع -1;
            إذا (!خالی_تھاواں && x)
                أرجع tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            أرجع x;
        افتراضي:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            اكسر;
        }
        خالی_تھاواں = 0;
    }
    إذا (s->link_optind < s->link_argc)
        أرجع tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    إذا (لگاتار) {
        إذا (*لگاتار && tcc_سیٹ_options(s, لگاتار) < 0)
            أرجع -1;
        x = 0, r = 0;
        اذهب extra_action;
    }
    إذا (!خالی_تھاواں)
        أرجع 0;
    إذا (s->verbose == 2)
        أرجع OPT_PRINT_DIRS;
    إذا (s->verbose)
        أرجع OPT_V;
    أرجع OPT_HELP;
}

LIBTCCAPI صحيح tcc_سیٹ_options(TCCState *s, ثابت حرف *r)
{
    حرف **argv = عدم;
    صحيح argc = 0, ret;
    dynarray_جوڑو(&argv, &argc, 0);
    dynarray_ونڈو(&argv, &argc, r, 0);
    ret = tcc_parse_دلیلاں(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    أرجع ret;
}

PUB_FUNC فراغ tcc_print_stats(TCCState *s1, بنانشانی کل_ویلا)
{
    إذا (!کل_ویلا)
        کل_ویلا = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           کل_idents, کل_سطریں, کل_بائٹاں,
           (مزدوج)کل_ویلا/1000,
           (بنانشانی)کل_سطریں*1000/کل_ویلا,
           (مزدوج)کل_بائٹاں/1000/کل_ویلا);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->کل_output[0],
           s1->کل_output[1],
           s1->کل_output[2],
           s1->کل_output[3]
           );
#جے_تعریف_شدہ MEM_DEBUG
    fprintf(stderr, "# memory usage");
#جے_تعریف_شدہ TCC_IS_NATIVE
    إذا (s1->لگاتار_ناپ) {
        Section *s = s1->symtab;
        بنانشانی ms = s->انکڑے_وتھ + s->link->انکڑے_وتھ + s->hash->انکڑے_وتھ;
        بنانشانی rs = s1->لگاتار_ناپ;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_ناپ - rs - ms);
    }
#جے_انت
    fprintf(stderr, " %d max (bytes)\n", mem_max_ناپ);
#جے_انت
}
