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

#اگر_تعریف_نشده ONE_منبع
# define ONE_منبع 1
#پایان_اگر

#إذا ONE_منبع
#ضمن "tccpp.c"
#ضمن "tccgen.c"
#ضمن "tccdbg.c"
#ضمن "tccasm.c"
#ضمن "tccelf.c"
#ضمن "tccrun.c"
#اگر_تعریف_شده TCC_هدف_I386
#ضمن "i386-gen.c"
#ضمن "i386-link.c"
#ضمن "i386-asm.c"
#وإلاإذا defined(TCC_هدف_ARM)
#ضمن "arm-gen.c"
#ضمن "arm-link.c"
#ضمن "arm-asm.c"
#وإلاإذا defined(TCC_هدف_ARM64)
#ضمن "arm64-gen.c"
#ضمن "arm64-link.c"
#ضمن "arm64-asm.c"
#وإلاإذا defined(TCC_هدف_C67)
#ضمن "c67-gen.c"
#ضمن "c67-link.c"
#ضمن "tcccoff.c"
#وإلاإذا defined(TCC_هدف_X86_64)
#ضمن "x86_64-gen.c"
#ضمن "x86_64-link.c"
#ضمن "i386-asm.c"
#وإلاإذا defined(TCC_هدف_RISCV64)
#ضمن "riscv64-gen.c"
#ضمن "riscv64-link.c"
#ضمن "riscv64-asm.c"
#وإلا
#خطا unknown هدف
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_PE
#ضمن "tccpe.c"
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_MACHO
#ضمن "tccmacho.c"
#پایان_اگر
#پایان_اگر /* ONE_SOURCE */

#ضمن "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_داده بنية TCCState *tcc_state;
TCC_SEM(ساكن tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_داده فراغ** stk_داده;
ST_داده صحيح nb_stk_داده;
/* option -d<num> (for general development purposes) */
ST_داده صحيح g_debug;

/********************************************************/
#اگر_تعریف_شده _WIN32
ST_FUNC حرف *normalize_slashes(حرف *مسیر)
{
    حرف *p;
    لكل (p = مسیر; *p; ++p)
        إذا (*p == '\\')
            *p = '/';
    أرجع مسیر;
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
#تعریف_کن tcc_module عدم /* NULL means executable itself */
#پایان_اگر

#اگر_تعریف_نشده CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ساكن مضمن حرف *config_tccdir_w32(حرف *مسیر)
{
    حرف *p;
    GetModuleFileNameA(tcc_module, مسیر, MAX_مسیر);
    p = tcc_basename(normalize_slashes(strlwr(مسیر)));
    إذا (p > مسیر)
        --p;
    *p = 0;
    أرجع مسیر;
}
#تعریف_کن CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_مسیر))
#پایان_اگر

#اگر_تعریف_شده TCC_IS_NATIVE
ساكن فراغ tcc_جمع_کن_systemdir(TCCState *s)
{
    حرف buf[1000];
    GetSystemDirectoryA(buf, حجم buf);
    tcc_جمع_کن_library_مسیر(s, normalize_slashes(buf));
}
#پایان_اگر
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m) {
    أرجع fopen(f, m);
}
PUB_FUNC صحيح tcc_fclose(FILE *f) {
    أرجع fclose(f);
}
#پایان_اگر
/********************************************************/

PUB_FUNC فراغ tcc_enter_state(TCCState *s1)
{
    إذا (s1->error_مجموعه_jmp_enabled)
        أرجع;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC فراغ tcc_exit_state(TCCState *s1)
{
    إذا (s1->error_مجموعه_jmp_enabled)
        أرجع;
    tcc_state = عدم;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s)
{
    حرف *q, *q_انتها;
    صحيح c;

    إذا (buf_اندازه > 0) {
        q = buf;
        q_انتها = buf + buf_اندازه - 1;
        طالما (q < q_انتها) {
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
ST_FUNC حرف *pstrcat(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s)
{
    اندازه_t len;
    len = طول_رشته(buf);
    إذا (len < buf_اندازه)
        pstrcpy(buf + len, buf_اندازه - len, s);
    أرجع buf;
}

ST_FUNC حرف *pstrncpy(حرف *بیرون, اندازه_t buf_اندازه, ثابت حرف *s, اندازه_t رقم)
{
    إذا (رقم >= buf_اندازه)
        رقم = buf_اندازه - 1;
    کپی_حافظه(بیرون, s, رقم);
    بیرون[رقم] = '\0';
    أرجع بیرون;
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

ST_FUNC حرف *tcc_بارگیری_متن(صحيح fd)
{
    صحيح len = lseek(fd, 0, SEEK_END);
    حرف *buf = بارگیری_داده(fd, 0, len + 1);
    buf[len] = 0;
    أرجع buf;
}

/* replace *pp by copy of 'str' or NULL */
ساكن فراغ tcc_مجموعه_str(حرف **pp, ثابت حرف *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : عدم;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ساكن فراغ tcc_concat_str(حرف **pp, ثابت حرف *str, صحيح sep)
{
    صحيح l = *pp ? طول_رشته(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + طول_رشته(str) + 1);
    إذا (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#لغو_تعریف حرر
#لغو_تعریف realloc

ساكن فراغ *default_reallocator(فراغ *ptr, بیعلامت دراز اندازه)
{
    فراغ *ptr1;
    إذا (اندازه == 0) {
        حرر(ptr);
        ptr1 = عدم;
    }
    وإلا {
        ptr1 = realloc(ptr, اندازه);
        إذا (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            خروج (1);
        }
    }
    أرجع ptr1;
}

ST_FUNC فراغ libc_free(فراغ *ptr)
{
    حرر(ptr);
}

/* defined to be not used */
#تعریف_کن حرر(p) use_tcc_free(p)
#تعریف_کن realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ساكن فراغ *(*reallocator)(فراغ*, بیعلامت دراز) = default_reallocator;

LIBTCCAPI فراغ tcc_مجموعه_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#لغو_تعریف tcc_free
#لغو_تعریف tcc_malloc
#لغو_تعریف tcc_realloc
#لغو_تعریف tcc_mallocz
#لغو_تعریف tcc_strdup

PUB_FUNC فراغ tcc_free(فراغ *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC فراغ *tcc_malloc(بیعلامت دراز اندازه)
{
    أرجع reallocator(0, اندازه);
}

PUB_FUNC فراغ *tcc_realloc(فراغ *ptr, بیعلامت دراز اندازه)
{
    أرجع reallocator(ptr, اندازه);
}

PUB_FUNC فراغ *tcc_mallocz(بیعلامت دراز اندازه)
{
    فراغ *ptr;
    ptr = tcc_malloc(اندازه);
    إذا (اندازه)
        memset(ptr, 0, اندازه);
    أرجع ptr;
}

PUB_FUNC حرف *tcc_strdup(ثابت حرف *str)
{
    حرف *ptr;
    ptr = tcc_malloc(طول_رشته(str) + 1);
    strcpy(ptr, str);
    أرجع ptr;
}

#اگر_تعریف_شده MEM_DEBUG

#تعریف_کن MEM_DEBUG_MAGIC1 0xFEEDDEB1
#تعریف_کن MEM_DEBUG_MAGIC2 0xFEEDDEB2
#تعریف_کن MEM_DEBUG_MAGIC3 0xFEEDDEB3
#تعریف_کن MEM_DEBUG_FILE_LEN 40
#تعریف_کن MEM_DEBUG_CHECK3(سرآیند) \
    (((بیعلامت حرف *) سرآیند->magic3) + سرآیند->اندازه)
#تعریف_کن MEM_USER_PTR(سرآیند) \
    ((حرف *)سرآیند + offsetof(mem_debug_سرآیند_t, magic3))
#تعریف_کن MEM_سرآیند_PTR(ptr) \
    (mem_debug_سرآیند_t *)((حرف*)ptr - offsetof(mem_debug_سرآیند_t, magic3))

بنية mem_debug_سرآیند {
    بیعلامت magic1;
    بیعلامت اندازه;
    بنية mem_debug_سرآیند *prev;
    بنية mem_debug_سرآیند *بعدی;
    صحيح سطر_رقم;
    حرف file_name[MEM_DEBUG_FILE_LEN];
    بیعلامت magic2;
    ALIGNED(16) بیعلامت حرف magic3[4];
};

تعريفنوع بنية mem_debug_سرآیند mem_debug_سرآیند_t;

TCC_SEM(ساكن mem_sem);
ساكن mem_debug_سرآیند_t *mem_debug_chain;
ساكن بیعلامت mem_cur_اندازه;
ساكن بیعلامت mem_max_اندازه;
ساكن صحيح nb_حالتها;

ساكن mem_debug_سرآیند_t *malloc_check(فراغ *ptr, ثابت حرف *پیام)
{
    mem_debug_سرآیند_t * سرآیند = MEM_سرآیند_PTR(ptr);
    إذا (سرآیند->magic1 != MEM_DEBUG_MAGIC1 ||
        سرآیند->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(سرآیند)) != MEM_DEBUG_MAGIC3 ||
        سرآیند->اندازه == (بیعلامت)-1) {
        fprintf(stderr, "%s check failed\n", پیام);
        إذا (سرآیند->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                سرآیند->file_name, سرآیند->سطر_رقم);
        خروج(1);
    }
    أرجع سرآیند;
}

PUB_FUNC فراغ *tcc_malloc_debug(بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر)
{
    صحيح ofs;
    mem_debug_سرآیند_t *سرآیند;
    إذا (!اندازه)
        أرجع عدم;
    سرآیند = tcc_malloc(حجم(mem_debug_سرآیند_t) + اندازه);
    سرآیند->magic1 = MEM_DEBUG_MAGIC1;
    سرآیند->magic2 = MEM_DEBUG_MAGIC2;
    سرآیند->اندازه = اندازه;
    write32le(MEM_DEBUG_CHECK3(سرآیند), MEM_DEBUG_MAGIC3);
    سرآیند->سطر_رقم = سطر;
    ofs = طول_رشته(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(سرآیند->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    سرآیند->بعدی = mem_debug_chain;
    سرآیند->prev = عدم;
    إذا (سرآیند->بعدی)
        سرآیند->بعدی->prev = سرآیند;
    mem_debug_chain = سرآیند;
    mem_cur_اندازه += اندازه;
    إذا (mem_cur_اندازه > mem_max_اندازه)
        mem_max_اندازه = mem_cur_اندازه;
    POST_SEM(&mem_sem);
    أرجع MEM_USER_PTR(سرآیند);
}

PUB_FUNC فراغ tcc_free_debug(فراغ *ptr)
{
    mem_debug_سرآیند_t *سرآیند;
    إذا (!ptr)
        أرجع;
    سرآیند = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_اندازه -= سرآیند->اندازه;
    سرآیند->اندازه = (بیعلامت)-1;
    إذا (سرآیند->بعدی)
        سرآیند->بعدی->prev = سرآیند->prev;
    إذا (سرآیند->prev)
        سرآیند->prev->بعدی = سرآیند->بعدی;
    إذا (سرآیند == mem_debug_chain)
        mem_debug_chain = سرآیند->بعدی;
    POST_SEM(&mem_sem);
    tcc_free(سرآیند);
}

PUB_FUNC فراغ *tcc_mallocz_debug(بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر)
{
    فراغ *ptr;
    ptr = tcc_malloc_debug(اندازه,file,سطر);
    إذا (اندازه)
        memset(ptr, 0, اندازه);
    أرجع ptr;
}

PUB_FUNC فراغ *tcc_realloc_debug(فراغ *ptr, بیعلامت دراز اندازه, ثابت حرف *file, صحيح سطر)
{
    mem_debug_سرآیند_t *سرآیند;
    صحيح mem_debug_chain_update = 0;

    إذا (!ptr)
        أرجع tcc_malloc_debug(اندازه, file, سطر);
    إذا (!اندازه) {
        tcc_free_debug(ptr);
        أرجع عدم;
    }
    سرآیند = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_اندازه -= سرآیند->اندازه;
    mem_debug_chain_update = (سرآیند == mem_debug_chain);
    سرآیند = tcc_realloc(سرآیند, حجم(mem_debug_سرآیند_t) + اندازه);
    سرآیند->اندازه = اندازه;
    write32le(MEM_DEBUG_CHECK3(سرآیند), MEM_DEBUG_MAGIC3);
    إذا (سرآیند->بعدی)
        سرآیند->بعدی->prev = سرآیند;
    إذا (سرآیند->prev)
        سرآیند->prev->بعدی = سرآیند;
    إذا (mem_debug_chain_update)
        mem_debug_chain = سرآیند;
    mem_cur_اندازه += اندازه;
    إذا (mem_cur_اندازه > mem_max_اندازه)
        mem_max_اندازه = mem_cur_اندازه;
    POST_SEM(&mem_sem);
    أرجع MEM_USER_PTR(سرآیند);
}

PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحيح سطر)
{
    حرف *ptr;
    ptr = tcc_malloc_debug(طول_رشته(str) + 1, file, سطر);
    strcpy(ptr, str);
    أرجع ptr;
}

PUB_FUNC فراغ tcc_memcheck(صحيح d)
{
    WAIT_SEM(&mem_sem);
    nb_حالتها += d;
    إذا (0 == nb_حالتها && mem_cur_اندازه) {
        mem_debug_سرآیند_t *سرآیند = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_اندازه, mem_max_اندازه);
        طالما (سرآیند) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                سرآیند->file_name, سرآیند->سطر_رقم, سرآیند->اندازه);
            سرآیند = سرآیند->بعدی;
        }
        fflush(stderr);
        mem_cur_اندازه = 0;
        mem_max_اندازه = 0;
        mem_debug_chain = عدم;
#إذا MEM_DEBUG-0 == 2
        خروج(2);
#پایان_اگر
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#تعریف_کن tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کن tcc_malloc(اندازه)        tcc_malloc_debug(اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_mallocz(اندازه)       tcc_mallocz_debug(اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_realloc(ptr,اندازه)   tcc_realloc_debug(ptr, اندازه, __FILE__, __LINE__)
#تعریف_کن tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#پایان_اگر /* MEM_DEBUG */

#اگر_تعریف_شده _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#پایان_اگر

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

ST_FUNC فراغ dynarray_جمع_کن(فراغ *ptab, صحيح *nb_ptr, فراغ *داده)
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
    pp[nb++] = داده;
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

ساكن فراغ dynarray_تقسیم(حرف ***argv, صحيح *argc, ثابت حرف *p, صحيح sep)
{
    صحيح qot, c;
    CString str;
    لكل(;;) {
        طالما (c = (بیعلامت حرف)*p, c <= ' ' && c != '\0')
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
        } طالما (c = (بیعلامت حرف)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_جمع_کن(argv, argc, str.داده);
    }
}

ساكن فراغ tcc_تقسیم_مسیر(TCCState *s, فراغ *p_ary, صحيح *p_nb_ary, ثابت حرف *درون)
{
    ثابت حرف *p;
    افعل {
        صحيح c;
        CString str;

        cstr_new(&str);
        لكل (p = درون; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            إذا (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                إذا (c == 'B')
                    cstr_cat(&str, s->tcc_lib_مسیر, -1);
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
        إذا (str.اندازه) {
            cstr_ccat(&str, '\0');
            dynarray_جمع_کن(p_ary, p_nb_ary, str.داده);
        }
        درون = p+1;
    } طالما (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#تعریف_کن WARN_ON  1 /* warning is on (-Woption) */
#تعریف_کن WARN_ERR 2 /* warning is an error (-Werror=option) */
#تعریف_کن WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
تعداد { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ساكن فراغ error1(صحيح نما, ثابت حرف *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    صحيح سطر = 0;

    tcc_exit_state(s1);

    إذا (نما == ERROR_WARN) {
        إذا (s1->warn_error)
            نما = ERROR_ERROR;
        إذا (s1->warn_رقم) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            صحيح wopt = *(&s1->warn_none + s1->warn_رقم);
            s1->warn_رقم = 0;
            إذا (0 == (wopt & WARN_ON))
                أرجع;
            إذا (wopt & WARN_ERR)
                نما = ERROR_ERROR;
            إذا (wopt & WARN_NOE)
                نما = ERROR_WARN;
        }
        إذا (s1->warn_none)
            أرجع;
    }

    cstr_new(&cs);
    إذا (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        سطر = va_arg(ap, صحيح), fmt += 3;
    f = عدم;
    إذا (s1->error_مجموعه_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        لكل (f = file; f && f->filename[0] == ':'; f = f->prev)
            ;
    }
    إذا (f) {
        لكل(pf = s1->include_پشته; pf < s1->include_پشته_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->سطر_رقم - 1);
        إذا (0 == سطر)
            سطر = f->سطر_رقم - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, سطر);
    } وإلا إذا (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } وإلا {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, نما == ERROR_WARN ? "warning: " : "error: ");
    إذا (pp_عبارت > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    وإلا
        cstr_vprintf(&cs, fmt, ap);
    إذا (!s1->error_func) {
        /* default case: stderr */
        إذا (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            چاپ_کن("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (حرف*)cs.داده);
        fflush(stderr); /* print error/warning now (win32) */
    } وإلا {
        s1->error_func(s1->error_opaque, (حرف*)cs.داده);
    }
    cstr_free(&cs);
    إذا (نما != ERROR_WARN)
        s1->nb_errors++;
    إذا (نما == ERROR_ERROR && s1->error_مجموعه_jmp_enabled) {
        طالما (nb_stk_داده)
            tcc_free(*(فراغ**)stk_داده[--nb_stk_داده]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI فراغ tcc_مجموعه_error_func(TCCState *s, فراغ *error_opaque, TCCErrorFunc *error_func)
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

#لغو_تعریف _tcc_error
PUB_FUNC فراغ _tcc_error(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    خروج(1);
}
#تعریف_کن _tcc_error use_tcc_error_noabort

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
    صحيح buflen = initlen ? initlen : IO_BUF_اندازه;

    bf = tcc_mallocz(حجم(BufferedFile) + buflen);
    bf->buf_ptr = bf->میانگیر;
    bf->buf_انتها = bf->میانگیر + initlen;
    bf->buf_انتها[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, حجم(bf->filename), filename);
#اگر_تعریف_شده _WIN32
    normalize_slashes(bf->filename);
#پایان_اگر
    bf->true_filename = bf->filename;
    bf->سطر_رقم = 1;
    bf->ifdef_پشته_ptr = s1->ifdef_پشته_ptr;
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
        مجموع_سطرها += bf->سطر_رقم - 1;
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
        fd = open(filename, O_RDONLY | O_دودویی_2);
    إذا ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        چاپ_کن("%s %*s%s\n", fd < 0 ? "nf":"->",
               (صحيح)(s1->include_پشته_ptr - s1->include_پشته), "", filename);
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
    s1->error_مجموعه_jmp_enabled = 1;

    إذا (setjmp(s1->error_jmp_buf) == 0) {

        إذا (fd == -1) {
            صحيح len = طول_رشته(str);
            tcc_open_bf(s1, "<string>", len);
            کپی_حافظه(file->میانگیر, str, len);
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
            tccelf_انتها_file(s1);
        }
    }
    tccgen_پایان(s1);
    preprocess_انتها(s1);
    s1->error_مجموعه_jmp_enabled = 0;
    tcc_exit_state(s1);
    أرجع s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI صحيح tcc_compile_string(TCCState *s, ثابت حرف *str)
{
    أرجع tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI فراغ tcc_define_نماد(TCCState *s1, ثابت حرف *sym, ثابت حرف *مقدار)
{
    ثابت حرف *eq;
    إذا (عدم == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    إذا (عدم == مقدار)
        مقدار = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (صحيح)(eq-sym), sym, مقدار);
}

/* undefine a preprocessor symbol */
LIBTCCAPI فراغ tcc_undefine_نماد(TCCState *s1, ثابت حرف *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(فراغ)
{
    TCCState *s;

    s = tcc_mallocz(حجم(TCCState));
#اگر_تعریف_شده MEM_DEBUG
    tcc_memcheck(1);
#پایان_اگر

#لغو_تعریف gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_درون_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#اگر_تعریف_شده CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#پایان_اگر
#اگر_تعریف_شده TCC_هدف_I386
    s->seg_اندازه = 32;
#پایان_اگر
    /* enable this if you want symbols with leading underscore on windows: */
#إذا defined TCC_هدف_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#پایان_اگر
#اگر_تعریف_شده TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#پایان_اگر
#إذا defined TCC_هدف_ARM64 && defined TCC_هدف_PE
    s->pe_dll_characteristics = 0x8160;
#پایان_اگر
#اگر_تعریف_شده CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#پایان_اگر
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_پشته_ptr = s->include_پشته;

    tcc_مجموعه_lib_مسیر(s, CONFIG_TCCDIR);
#اگر_تعریف_شده CONFIG_TCC_SWITCHES /* predefined options */
    tcc_مجموعه_options(s, CONFIG_TCC_SWITCHES);
#پایان_اگر
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

    tcc_free(s1->tcc_lib_مسیر);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_نماد);
    tcc_free(s1->fini_نماد);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#إذا defined TCC_هدف_MACHO
    tcc_free(s1->install_name);
#پایان_اگر
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->هدف_deps, &s1->nb_هدف_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#اگر_تعریف_شده TCC_IS_NATIVE
    /* free runtime memory */
    tcc_پیاپی_free(s1);
#پایان_اگر
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#اگر_تعریف_شده MEM_DEBUG
    tcc_memcheck(-1);
#پایان_اگر
}

LIBTCCAPI صحيح tcc_مجموعه_output_type(TCCState *s, صحيح output_type)
{
#اگر_تعریف_شده CONFIG_TCC_PIE
    إذا (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#پایان_اگر
    s->output_type = output_type;

    إذا (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_جمع_کن_sysinclude_مسیر(s, CONFIG_TCC_SYSINCLUDEPATHS);
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
        tcc_جمع_کن_library_مسیر(s, CONFIG_TCC_LIBPATHS);

#اگر_تعریف_شده TCC_هدف_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_جمع_کن_systemdir(s);
# endif

#وإلاإذا defined TCC_هدف_MACHO
# ifdef TCC_IS_NATIVE
    tcc_جمع_کن_macos_sdkpath(s);
# endif

#وإلا
    /* paths for crt objects */
    tcc_تقسیم_مسیر(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    إذا (output_type != TCC_OUTPUT_حافظه && !s->nostdlib)
        tccelf_جمع_کن_crtbegin(s); /* may produce errors */
#پایان_اگر
    أرجع s->nb_errors ? -1 : 0;
}

LIBTCCAPI صحيح tcc_جمع_کن_include_مسیر(TCCState *s, ثابت حرف *pathname)
{
    tcc_تقسیم_مسیر(s, &s->include_paths, &s->nb_include_paths, pathname);
    أرجع 0;
}

LIBTCCAPI صحيح tcc_جمع_کن_sysinclude_مسیر(TCCState *s, ثابت حرف *pathname)
{
    tcc_تقسیم_مسیر(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    أرجع 0;
}

LIBTCCAPI صحيح tcc_جمع_کن_library_مسیر(TCCState *s, ثابت حرف *pathname)
{
    tcc_تقسیم_مسیر(s, &s->library_paths, &s->nb_library_paths, pathname);
    أرجع 0;
}

LIBTCCAPI فراغ tcc_مجموعه_lib_مسیر(TCCState *s, ثابت حرف *مسیر)
{
    tcc_مجموعه_str(&s->tcc_lib_مسیر, مسیر);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_جمع_کن_dllref(TCCState *s1, ثابت حرف *dllname, صحيح level)
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
        ref->یافت = 1;
        أرجع ref;
    }
    ref = tcc_mallocz(حجم(DLLReference) + طول_رشته(dllname));
    strcpy(ref->name, dllname);
    dynarray_جمع_کن(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->شاخص = s1->nb_loaded_dlls;
    أرجع ref;
}

ساكن صحيح tcc_جمع_کن_دودویی(TCCState *s1, صحيح flags, ثابت حرف *filename, صحيح fd)
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
        ret = tcc_بارگیری_object_file(s1, fd, 0);
        اكسر;

    حالة AFF_BINTYPE_AR:
        ret = tcc_بارگیری_archive(s1, fd, !(flags & AFF_کامل_ARCHIVE));
        اكسر;

#إذا defined TCC_هدف_UNIX
    حالة AFF_BINTYPE_DYN:
        إذا (s1->output_type == TCC_OUTPUT_حافظه) {
#اگر_تعریف_شده TCC_IS_NATIVE
            فراغ* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            إذا (dl)
                tcc_جمع_کن_dllref(s1, filename, 0)->handle = dl;
            وإلا
                ret = FILE_NOT_RECOGNIZED;
#پایان_اگر
        } وإلا
            ret = tcc_بارگیری_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        اكسر;

    افتراضي:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_بارگیری_ldscript(s1, fd);
        اكسر;

#وإلاإذا defined TCC_هدف_MACHO
    حالة AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        إذا (s1->output_type == TCC_OUTPUT_حافظه) {
#اگر_تعریف_شده TCC_IS_NATIVE
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
                tcc_جمع_کن_dllref(s1, soname, 0)->handle = dl;
            وإلا
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#پایان_اگر
        } وإلا إذا (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_بارگیری_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } وإلا {
            ret = macho_بارگیری_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
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

#وإلاإذا defined TCC_هدف_PE
    افتراضي:
        إذا (pe_بارگیری_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        اكسر;
#پایان_اگر

#اگر_تعریف_شده TCC_هدف_COFF
    حالة AFF_BINTYPE_C67:
        ret = tcc_بارگیری_coff(s1, fd);
        اكسر;
#پایان_اگر
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
ساكن صحيح tcc_glob_so(TCCState *s1, ثابت حرف *الگو, حرف *buf, صحيح اندازه)
{
    ثابت حرف *ستاره;
    glob_t g;
    حرف *p;
    صحيح i, v, v1, v2, v3;

    ستاره = strchr(الگو, '*');
    إذا (!ستاره || glob(الگو, 0, عدم, &g))
        أرجع -1;
    لكل (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        إذا (2 != از_رشته_بخوان(p + (ستاره - الگو), "%d.%d.%d", &v1, &v2, &v3))
            استمر;
        إذا ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, اندازه, p);
    }
    globfree(&g);
    أرجع v;
}
#پایان_اگر

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

ST_FUNC صحيح tcc_جمع_کن_file_داخلی(TCCState *s1, ثابت حرف *filename, صحيح flags)
{
    صحيح fd;

#إذا defined TARGETOS_OpenBSD && !defined _WIN32
    حرف buf[1024];
    إذا (tcc_glob_so(s1, filename, buf, حجم buf) >= 0)
        filename = buf;
#پایان_اگر

    إذا (0 == (flags & AFF_TYPE_ماسک))
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
        أرجع FILE_NOT_یافت;
    }

    إذا (flags & AFF_TYPE_BIN)
        أرجع tcc_جمع_کن_دودویی(s1, flags, filename, fd);

    dynarray_جمع_کن(&s1->هدف_deps, &s1->nb_هدف_deps, tcc_strdup(filename));
    أرجع tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI صحيح tcc_جمع_کن_file(TCCState *s, ثابت حرف *filename)
{
    أرجع tcc_جمع_کن_file_داخلی(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ساكن صحيح tcc_جمع_کن_library_داخلی(TCCState *s1, ثابت حرف *fmt,
    ثابت حرف *filename, صحيح flags, حرف **paths, صحيح nb_paths)
{
    حرف buf[1024];
    صحيح i, ret;

    لكل(i = 0; i < nb_paths; i++) {
        snprintf(buf, حجم(buf), fmt, paths[i], filename);
        ret = tcc_جمع_کن_file_داخلی(s1, buf, flags & ~AFF_PRINT_ERROR);
        إذا (ret != FILE_NOT_یافت)
            أرجع ret;
    }
    إذا (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    أرجع FILE_NOT_یافت;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC صحيح tcc_جمع_کن_dll(TCCState *s, ثابت حرف *filename, صحيح flags)
{
    أرجع tcc_جمع_کن_library_داخلی(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC صحيح tcc_جمع_کن_support(TCCState *s1, ثابت حرف *filename)
{
    حرف buf[100];
    إذا (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    أرجع tcc_جمع_کن_dll(s1, filename, AFF_PRINT_ERROR);
}

#اگر_تعریف_شده TCC_هدف_UNIX
ST_FUNC صحيح tcc_جمع_کن_crt(TCCState *s1, ثابت حرف *filename)
{
    أرجع tcc_جمع_کن_library_داخلی(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#پایان_اگر

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحيح tcc_جمع_کن_library(TCCState *s, ثابت حرف *libraryname)
{
    ساكن ثابت حرف * ثابت libs[] = {
#إذا defined TCC_هدف_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#وإلاإذا defined TCC_هدف_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#وإلاإذا defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#وإلا
        "%s/lib%s.so",
#پایان_اگر
        "%s/lib%s.a",
        عدم
    };
    صحيح flags = AFF_TYPE_LIB | (s->filetype & AFF_کامل_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    إذا (*libraryname == ':') {
        libraryname++;
    } وإلا {
        ثابت حرف * ثابت *pp = libs;
        إذا (s->static_link)
            pp += حجم(libs) / حجم(*libs) - 2; /* only "%s/lib%s.a" */
        طالما (*pp) {
            صحيح ret = tcc_جمع_کن_library_داخلی(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            إذا (ret != FILE_NOT_یافت)
                أرجع ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    أرجع tcc_جمع_کن_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC فراغ tcc_جمع_کن_pragma_libs(TCCState *s1)
{
    صحيح i;
    لكل (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_جمع_کن_library(s1, s1->pragma_libs[i]);
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
    صحيح تطابق;
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
#اگر_تعریف_شده TCC_هدف_PE
        وإلا إذا (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#پایان_اگر
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
            o->تطابق = 1; /* -Wl,-opt -Wl,arg */
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

ساكن فراغ آرگومانها_parser_جمع_کن_file(TCCState *s, ثابت حرف* filename, صحيح filetype);

#تعریف_کن مجموعه_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#تعریف_کن مجموعه_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ساكن صحيح tcc_مجموعه_linker(TCCState *s, ثابت حرف *optarg)
{
    TCCState *s1 = s;

    dynarray_تقسیم(&s1->link_argv, &s1->link_argc, optarg, ',');

    طالما (s->link_optind < s->link_argc) {
        حرف *انتها = عدم;
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
            tcc_مجموعه_str(&s->elf_entryname, o.arg);
        } وإلا إذا (link_option(&o, "image-base=|Ttext=")) {
            s->متن_addr = strtoull(o.arg, &انتها, 16);
            s->has_متن_addr = 1;
        } وإلا إذا (link_option(&o, "init=")) {
            tcc_مجموعه_str(&s->init_نماد, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "fini=")) {
            tcc_مجموعه_str(&s->fini_نماد, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "Map=")) {
            tcc_مجموعه_str(&s->mapfile, o.arg);
            ignoring = 1;
        } وإلا إذا (link_option(&o, "oformat=")) {
#إذا defined TCC_هدف_PE
            إذا (0 == مقایسه_رشته("pe-", o.arg, 3))
#وإلاإذا PTR_اندازه == 8
            إذا (0 == مقایسه_رشته("elf64-", o.arg, 6))
#وإلا
            إذا (0 == مقایسه_رشته("elf32-", o.arg, 6))
#پایان_اگر
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            وإلا إذا (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_دودویی;
#إذا defined TCC_هدف_COFF
            وإلا إذا (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#پایان_اگر
            وإلا
                اذهب err;
        } وإلا إذا (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } وإلا إذا (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } وإلا إذا (link_option(&o, "dynamic-linker=|I:")) {
            tcc_مجموعه_str(&s->elfint, o.arg);
        } وإلا إذا (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } وإلا إذا (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &انتها, 16);
        } وإلا إذا (link_option(&o, "soname=|install_name=")) {
            tcc_مجموعه_str(&s->soname, o.arg);
        } وإلا إذا (!!(r = link_option(&o, "?whole-archive"))) {
            مجموعه_OR_CLEAR(s->filetype, AFF_کامل_ARCHIVE);
        } وإلا إذا (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#اگر_تعریف_شده TCC_هدف_PE
        } وإلا إذا (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } وإلا إذا (!!(r = link_option(&o, "?dynamicbase"))) {
            مجموعه_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } وإلا إذا (!!(r = link_option(&o, "?high-entropy-va"))) {
            مجموعه_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } وإلا إذا (!!(r = link_option(&o, "?nxcompat"))) {
            مجموعه_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } وإلا إذا (!!(r = link_option(&o, "?tsaware"))) {
            مجموعه_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } وإلا إذا (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &انتها, 16);
        } وإلا إذا (link_option(&o, "stack=")) {
            s->pe_پشته_اندازه = strtoul(o.arg, &انتها, 10);
        } وإلا إذا (link_option(&o, "subsystem=")) {
            إذا (pe_setsubsy(s, o.arg) < 0)
                اذهب err;
#وإلاإذا defined TCC_هدف_MACHO
        } وإلا إذا (link_option(&o, "all_load")) {
	    s->filetype |= AFF_کامل_ARCHIVE;
        } وإلا إذا (link_option(&o, "force_load=")) {
            آرگومانها_parser_جمع_کن_file(s, o.arg, AFF_TYPE_LIB | AFF_کامل_ARCHIVE);
        } وإلا إذا (link_option(&o, "single_module")) {
            ignoring = 1;
#پایان_اگر
        } وإلا إذا (link_option(&o, "as-needed")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "O")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "z=")) {
            ignoring = 1;
        } وإلا إذا (link_option(&o, "L:")) {
            tcc_جمع_کن_library_مسیر(s, o.arg);
        } وإلا إذا (link_option(&o, "l:")) {
            آرگومانها_parser_جمع_کن_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ماسک));
        } وإلا إذا (o.تطابق) {
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
    uint16_t شاخص;
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
    TCC_OPTION_print_جستجو_dirs,
    TCC_OPTION_rdynamic,
    TCC_OPTION_pthread,
    TCC_OPTION_پیاپی,
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
    TCC_OPTION_compatibility_نسخه ,
    TCC_OPTION_current_نسخه,
};

#تعریف_کن TCC_OPTION_HAS_ARG 0x0001
#تعریف_کن TCC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

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
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#پایان_اگر
#اگر_تعریف_شده CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#پایان_اگر
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#اگر_تعریف_شده TCC_هدف_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_نسخه, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_نسخه, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#پایان_اگر
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
    { "run", TCC_OPTION_پیاپی, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#اگر_تعریف_شده TCC_هدف_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#پایان_اگر
    { "m", TCC_OPTION_m, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "f", TCC_OPTION_f, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "isystem", TCC_OPTION_isystem, TCC_OPTION_HAS_ARG },
    { "include", TCC_OPTION_include, TCC_OPTION_HAS_ARG },
    { "nostdinc", TCC_OPTION_nostdinc, 0 },
    { "nostdlib", TCC_OPTION_nostdlib, 0 },
    { "print-search-dirs", TCC_OPTION_print_جستجو_dirs, 0 },
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
#اگر_تعریف_شده TCC_هدف_PE
    { "impdef", TCC_OPTION_impdef, 0},
#پایان_اگر
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
    uint16_t جابه_جایی;
    uint16_t flags;
    ثابت حرف *name;
} FlagDef;

#تعریف_کن WD_ALL    0x0001 /* warning is activated when using -Wall */
#تعریف_کن FD_INVERT 0x0002 /* invert value before storing */

ساكن ثابت FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_رشتهها), 0, "write-strings" },
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
    { offsetof(TCCState, dollars_درون_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, معکوس_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, عدم }
};

ساكن ثابت FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#اگر_تعریف_شده TCC_هدف_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#پایان_اگر
    { 0, 0, عدم }
};

ساكن صحيح مجموعه_flag(TCCState *s, ثابت FlagDef *flags, ثابت حرف *name)
{
    صحيح مقدار, ماسک, ret;
    ثابت FlagDef *p;
    ثابت حرف *r;
    بیعلامت حرف *f;

    r = name, مقدار = !strstart("no-", &r), ماسک = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    إذا ((flags->flags & WD_ALL) && strstart("error=", &r))
        مقدار = مقدار ? WARN_ON|WARN_ERR : WARN_NOE, ماسک = WARN_ON;

    لكل (ret = -1, p = flags; p->name; ++p) {
        إذا (ret) {
            إذا (strcmp(r, p->name))
                استمر;
        } وإلا {
            إذا (0 == (p->flags & WD_ALL))
                استمر;
        }

        f = (بیعلامت حرف *)s + p->جابه_جایی;
        *f = (*f & ماسک) | (مقدار ^ !!(p->flags & FD_INVERT));

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
#اگر_تعریف_شده TCC_هدف_I386
    "i386-pc"
#وإلاإذا defined TCC_هدف_X86_64
    "x86_64-pc"
#وإلاإذا defined TCC_هدف_C67
    "c67"
#وإلاإذا defined TCC_هدف_ARM
    "arm"
#وإلاإذا defined TCC_هدف_ARM64
    "aarch64"
#وإلاإذا defined TCC_هدف_RISCV64
    "riscv64"
#پایان_اگر
    "-"
#اگر_تعریف_شده TCC_هدف_PE
    "mingw32"
#وإلاإذا defined(TCC_هدف_MACHO)
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
#پایان_اگر
;

#إذا defined TCC_هدف_MACHO
ساكن uint32_t parse_نسخه(TCCState *s1, ثابت حرف *نسخه)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    حرف* آخرین;

    a = strtoul(نسخه, &آخرین, 10);
    إذا (*آخرین == '.') {
        b = strtoul(&آخرین[1], &آخرین, 10);
        إذا (*آخرین == '.')
             c = strtoul(&آخرین[1], &آخرین, 10);
    }
    إذا (*آخرین || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", نسخه);
    أرجع (a << 16) | (b << 8) | c;
}
#پایان_اگر

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ساكن فراغ درج_آرگومانها(TCCState *s1, حرف ***pargv, صحيح *pargc, صحيح optind, ثابت حرف *p, صحيح sep)
{
    صحيح argc = 0;
    حرف **argv = عدم;
    صحيح i;
    لكل (i = 0; i < *pargc; ++i)
        إذا (i == optind)
            dynarray_تقسیم(&argv, &argc, p, sep);
        وإلا
            dynarray_جمع_کن(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ساكن فراغ آرگومانها_parser_جمع_کن_file(TCCState *s, ثابت حرف* filename, صحيح filetype)
{
    بنية filespec *f = tcc_malloc(حجم *f + طول_رشته(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_جمع_کن(&s->files, &s->nb_files, f);
    إذا (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC صحيح tcc_parse_آرگومانها(TCCState *s, صحيح *pargc, حرف ***pargv)
{
    TCCState *s1 = s;
    ثابت TCCOption *popt;
    ثابت حرف *optarg, *r;
    ثابت حرف *پیاپی = عدم;
    صحيح optind = 1, خالی = 1, x;
    حرف **argv = *pargv;
    صحيح argc = *pargc;

    s->link_optind = s->link_argc;

    طالما (optind < argc) {
        r = argv[optind];
        إذا (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            صحيح fd; حرف *p;
            fd = open(++r, O_RDONLY | O_دودویی_2);
            إذا (fd < 0)
                أرجع tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_بارگیری_متن(fd);
            درج_آرگومانها(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            استمر;
        }
        optind++;
        إذا (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            آرگومانها_parser_جمع_کن_file(s, r, s->filetype);
            خالی = 0;
        dorun:
            إذا (پیاپی)
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

        بدل(popt->شاخص) {
        حالة TCC_OPTION_I:
            tcc_جمع_کن_include_مسیر(s, optarg);
            اكسر;
        حالة TCC_OPTION_D:
            tcc_define_نماد(s, optarg, عدم);
            اكسر;
        حالة TCC_OPTION_U:
            tcc_undefine_نماد(s, optarg);
            اكسر;
        حالة TCC_OPTION_L:
            tcc_جمع_کن_library_مسیر(s, optarg);
            اكسر;
        حالة TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_مجموعه_lib_مسیر(s, optarg);
            استمر;
        حالة TCC_OPTION_l:
            آرگومانها_parser_جمع_کن_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_ماسک));
            اكسر;
        حالة TCC_OPTION_pthread:
            s->option_pthread = 1;
            اكسر;
        حالة TCC_OPTION_bench:
            s->do_bench = 1;
            اكسر;
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
        حالة TCC_OPTION_bt:
            s->rt_رقم_callers = atoi(optarg); /* zero = default (6) */
            اذهب enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            إذا (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_نسخه;
            اكسر;
#اگر_تعریف_شده CONFIG_TCC_BCHECK
        حالة TCC_OPTION_b:
            s->do_bounds_check = 1;
            اذهب enable_backtrace;
#پایان_اگر
#پایان_اگر
        حالة TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_نسخه;
        g_redo:
            إذا (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_نسخه;
            } وإلا إذا (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } وإلا إذا (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                اذهب g_redo;
#اگر_تعریف_شده TCC_هدف_PE
            } وإلا إذا (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#پایان_اگر
            }
            اكسر;
        حالة TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        مجموعه_output_type:
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
            اذهب مجموعه_output_type;
        حالة TCC_OPTION_soname:
            tcc_مجموعه_str(&s->soname, optarg);
            اكسر;
        حالة TCC_OPTION_o:
            إذا (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_مجموعه_str(&s->outfile, optarg);
            اكسر;
        حالة TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            اذهب مجموعه_output_type;
        حالة TCC_OPTION_isystem:
            tcc_جمع_کن_sysinclude_مسیر(s, optarg);
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
        حالة TCC_OPTION_پیاپی:
#اگر_تعریف_شده TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            پیاپی = optarg;
            x = TCC_OUTPUT_حافظه;
            اذهب مجموعه_output_type;
#وإلا
            أرجع tcc_error_noabort("-run is not available in a cross compiler");
#پایان_اگر
#اگر_تعریف_شده TCC_IS_NATIVE
        حالة TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->پیاپی_stdin = optarg;
            اكسر;
#پایان_اگر
        حالة TCC_OPTION_v:
            افعل ++s->verbose; طالما (*optarg++ == 'v');
            استمر;
        حالة TCC_OPTION_f:
            إذا (مجموعه_flag(s, options_f, optarg) < 0)
                اذهب unsupported_option;
            اكسر;
#اگر_تعریف_شده TCC_هدف_ARM
        حالة TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            إذا (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } وإلا إذا (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            وإلا
                أرجع tcc_error_noabort("unsupported float abi '%s'", optarg);
            استمر;
#پایان_اگر
        حالة TCC_OPTION_m:
            إذا (مجموعه_flag(s, options_m, optarg) < 0) {
                إذا (x = atoi(optarg), x != 32 && x != 64)
                    اذهب unsupported_option;
                إذا (PTR_اندازه != x/8)
                    أرجع x;
                استمر;
            }
            اكسر;
        حالة TCC_OPTION_W:
            إذا (optarg[0] && مجموعه_flag(s, options_W, optarg) < 0)
                اذهب unsupported_option;
            اكسر;
        حالة TCC_OPTION_w:
            s->warn_none = 1;
            اكسر;
        حالة TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            اكسر;
        حالة TCC_OPTION_Wl:
            إذا (tcc_مجموعه_linker(s, optarg) < 0)
                أرجع -1;
            اكسر;
        حالة TCC_OPTION_Wp:
            إذا (argv[0]) /* not with tcc_set_options() */
                درج_آرگومانها(s, &argv, &argc, --optind, optarg, ',');
            اكسر;
        حالة TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            اذهب مجموعه_output_type;
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
                tcc_مجموعه_str(&s->deps_outfile, "-");
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
            tcc_مجموعه_str(&s->deps_outfile, optarg);
            اكسر;
        حالة TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            اكسر;

        حالة TCC_OPTION_dumpmachine:
            چاپ_کن("%s\n", dumpmachine_str);
            خروج(0);
        حالة TCC_OPTION_dumpversion:
            چاپ_کن ("%s\n", TCC_نسخه);
            خروج(0);

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
            s->filetype = x | (s->filetype & ~AFF_TYPE_ماسک);
            اكسر;
        حالة TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            اكسر;
#إذا defined TCC_هدف_MACHO
        حالة TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            اذهب مجموعه_output_type;
        حالة TCC_OPTION_flat_namespace:
	     اكسر;
        حالة TCC_OPTION_two_levelnamespace:
	     اكسر;
        حالة TCC_OPTION_undefined:
	     اكسر;
        حالة TCC_OPTION_install_name:
	    tcc_مجموعه_str(&s->install_name, optarg);
            اكسر;
        حالة TCC_OPTION_compatibility_نسخه:
	    s->compatibility_نسخه = parse_نسخه(s, optarg);
            اكسر;
        حالة TCC_OPTION_current_نسخه:
	    s->current_نسخه = parse_نسخه(s, optarg);;
            اكسر;
#پایان_اگر
        حالة TCC_OPTION_HELP:
            x = OPT_HELP;
            اذهب extra_action;
        حالة TCC_OPTION_HELP2:
            x = OPT_HELP2;
            اذهب extra_action;
        حالة TCC_OPTION_print_جستجو_dirs:
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
            إذا (!خالی && x)
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
        خالی = 0;
    }
    إذا (s->link_optind < s->link_argc)
        أرجع tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    إذا (پیاپی) {
        إذا (*پیاپی && tcc_مجموعه_options(s, پیاپی) < 0)
            أرجع -1;
        x = 0, r = 0;
        اذهب extra_action;
    }
    إذا (!خالی)
        أرجع 0;
    إذا (s->verbose == 2)
        أرجع OPT_PRINT_DIRS;
    إذا (s->verbose)
        أرجع OPT_V;
    أرجع OPT_HELP;
}

LIBTCCAPI صحيح tcc_مجموعه_options(TCCState *s, ثابت حرف *r)
{
    حرف **argv = عدم;
    صحيح argc = 0, ret;
    dynarray_جمع_کن(&argv, &argc, 0);
    dynarray_تقسیم(&argv, &argc, r, 0);
    ret = tcc_parse_آرگومانها(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    أرجع ret;
}

PUB_FUNC فراغ tcc_print_stats(TCCState *s1, بیعلامت مجموع_زمان)
{
    إذا (!مجموع_زمان)
        مجموع_زمان = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           مجموع_idents, مجموع_سطرها, مجموع_بایتها,
           (مزدوج)مجموع_زمان/1000,
           (بیعلامت)مجموع_سطرها*1000/مجموع_زمان,
           (مزدوج)مجموع_بایتها/1000/مجموع_زمان);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->مجموع_output[0],
           s1->مجموع_output[1],
           s1->مجموع_output[2],
           s1->مجموع_output[3]
           );
#اگر_تعریف_شده MEM_DEBUG
    fprintf(stderr, "# memory usage");
#اگر_تعریف_شده TCC_IS_NATIVE
    إذا (s1->پیاپی_اندازه) {
        Section *s = s1->symtab;
        بیعلامت ms = s->داده_جابه_جایی + s->link->داده_جابه_جایی + s->hash->داده_جابه_جایی;
        بیعلامت rs = s1->پیاپی_اندازه;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_اندازه - rs - ms);
    }
#پایان_اگر
    fprintf(stderr, " %d max (bytes)\n", mem_max_اندازه);
#پایان_اگر
}
