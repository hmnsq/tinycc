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

#اگر_غیر_تعریف_شدہ ONE_ماخذ
# define ONE_ماخذ 1
#اگر_ختم

#اگر ONE_ماخذ
#شامل "tccpp.c"
#شامل "tccgen.c"
#شامل "tccdbg.c"
#شامل "tccasm.c"
#شامل "tccelf.c"
#شامل "tccrun.c"
#اگر_تعریف_شدہ TCC_ہدف_I386
#شامل "i386-gen.c"
#شامل "i386-link.c"
#شامل "i386-asm.c"
#وگرنہ_اگر defined(TCC_ہدف_ARM)
#شامل "arm-gen.c"
#شامل "arm-link.c"
#شامل "arm-asm.c"
#وگرنہ_اگر defined(TCC_ہدف_ARM64)
#شامل "arm64-gen.c"
#شامل "arm64-link.c"
#شامل "arm64-asm.c"
#وگرنہ_اگر defined(TCC_ہدف_C67)
#شامل "c67-gen.c"
#شامل "c67-link.c"
#شامل "tcccoff.c"
#وگرنہ_اگر defined(TCC_ہدف_X86_64)
#شامل "x86_64-gen.c"
#شامل "x86_64-link.c"
#شامل "i386-asm.c"
#وگرنہ_اگر defined(TCC_ہدف_RISCV64)
#شامل "riscv64-gen.c"
#شامل "riscv64-link.c"
#شامل "riscv64-asm.c"
#ورنہ
#غلطی unknown ہدف
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_PE
#شامل "tccpe.c"
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_MACHO
#شامل "tccmacho.c"
#اگر_ختم
#اگر_ختم /* ONE_SOURCE */

#شامل "tcc.h"

/********************************************************/
/* global variables */

/* XXX: get rid of this ASAP (or maybe not) */
ST_ڈیٹا ساخت TCCState *tcc_state;
TCC_SEM(ساکن tcc_compile_sem);
/* an array of pointers to memory to be free'd after errors */
ST_ڈیٹا خالی** stk_ڈیٹا;
ST_ڈیٹا صحیح nb_stk_ڈیٹا;
/* option -d<num> (for general development purposes) */
ST_ڈیٹا صحیح g_debug;

/********************************************************/
#اگر_تعریف_شدہ _WIN32
ST_FUNC حرف *normalize_slashes(حرف *راستہ)
{
    حرف *p;
    برائے (p = راستہ; *p; ++p)
        اگر (*p == '\\')
            *p = '/';
    واپس راستہ;
}

#اگر defined LIBTCC_AS_DLL && !defined CONFIG_TCCDIR
ساکن HMODULE tcc_module;
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    اگر (DLL_PROCESS_ATTACH == dwReason)
        tcc_module = hDll;
    واپس TRUE;
}
#ورنہ
#تعریف_کرو tcc_module تہی /* NULL means executable itself */
#اگر_ختم

#اگر_غیر_تعریف_شدہ CONFIG_TCCDIR
/* on win32, we suppose the lib and includes are at the location of 'tcc.exe' */
ساکن اندرونی حرف *config_tccdir_w32(حرف *راستہ)
{
    حرف *p;
    GetModuleFileNameA(tcc_module, راستہ, MAX_راستہ);
    p = tcc_basename(normalize_slashes(strlwr(راستہ)));
    اگر (p > راستہ)
        --p;
    *p = 0;
    واپس راستہ;
}
#تعریف_کرو CONFIG_TCCDIR config_tccdir_w32(alloca(MAX_راستہ))
#اگر_ختم

#اگر_تعریف_شدہ TCC_IS_NATIVE
ساکن خالی tcc_جوڑو_systemdir(TCCState *s)
{
    حرف buf[1000];
    GetSystemDirectoryA(buf, حجم buf);
    tcc_جوڑو_library_راستہ(s, normalize_slashes(buf));
}
#اگر_ختم
/* for tcc -E : On windows (depending on compiler) a FILE*
   must be created by the same module where it is used. */
PUB_FUNC FILE *tcc_fopen(ثابت حرف *f, ثابت حرف *m) {
    واپس fopen(f, m);
}
PUB_FUNC صحیح tcc_fclose(FILE *f) {
    واپس fclose(f);
}
#اگر_ختم
/********************************************************/

PUB_FUNC خالی tcc_enter_state(TCCState *s1)
{
    اگر (s1->error_سیٹ_jmp_enabled)
        واپس;
    WAIT_SEM(&tcc_compile_sem);
    tcc_state = s1;
}

PUB_FUNC خالی tcc_exit_state(TCCState *s1)
{
    اگر (s1->error_سیٹ_jmp_enabled)
        واپس;
    tcc_state = تہی;
    POST_SEM(&tcc_compile_sem);
}

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, سائز_t buf_سائز, ثابت حرف *s)
{
    حرف *q, *q_انتہا;
    صحیح c;

    اگر (buf_سائز > 0) {
        q = buf;
        q_انتہا = buf + buf_سائز - 1;
        جب (q < q_انتہا) {
            c = *s++;
            اگر (c == '\0')
                توڑو;
            *q++ = c;
        }
        *q = '\0';
    }
    واپس buf;
}

/* strcat and truncate. */
ST_FUNC حرف *pstrcat(حرف *buf, سائز_t buf_سائز, ثابت حرف *s)
{
    سائز_t len;
    len = لڑی_لمبائی(buf);
    اگر (len < buf_سائز)
        pstrcpy(buf + len, buf_سائز - len, s);
    واپس buf;
}

ST_FUNC حرف *pstrncpy(حرف *برآمد, سائز_t buf_سائز, ثابت حرف *s, سائز_t عدد)
{
    اگر (عدد >= buf_سائز)
        عدد = buf_سائز - 1;
    حافظہ_نقل(برآمد, s, عدد);
    برآمد[عدد] = '\0';
    واپس برآمد;
}

/* extract the basename of a file */
PUB_FUNC حرف *tcc_basename(ثابت حرف *name)
{
    حرف *p = (حرف *)strchr(name, 0);
    جب (p > name && !IS_DIRSEP(p[-1]))
        --p;
    واپس p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC حرف *tcc_fileextension (ثابت حرف *name)
{
    حرف *b = tcc_basename(name);
    حرف *e = strrchr(b, '.');
    واپس e ? e : strchr(b, 0);
}

ST_FUNC حرف *tcc_بھرو_متن(صحیح fd)
{
    صحیح len = lseek(fd, 0, SEEK_END);
    حرف *buf = بھرو_ڈیٹا(fd, 0, len + 1);
    buf[len] = 0;
    واپس buf;
}

/* replace *pp by copy of 'str' or NULL */
ساکن خالی tcc_سیٹ_str(حرف **pp, ثابت حرف *str)
{
    tcc_free(*pp);
    *pp = str ? tcc_strdup(str) : تہی;
}

/* set/append 'str' to *pp (separated by 'sep' unless 0) */
ساکن خالی tcc_concat_str(حرف **pp, ثابت حرف *str, صحیح sep)
{
    صحیح l = *pp ? لڑی_لمبائی(*pp) + !!sep : 0;
    *pp = tcc_realloc(*pp, l + لڑی_لمبائی(str) + 1);
    اگر (l && sep) ((*pp)[l - 1] = sep);
    strcpy(*pp + l, str);
}

/********************************************************/
/* memory management */

/* we'll need the actual versions for a minute */
#تعریف_منسوخ آزاد
#تعریف_منسوخ realloc

ساکن خالی *default_reallocator(خالی *ptr, غیرعلامتی طویل سائز)
{
    خالی *ptr1;
    اگر (سائز == 0) {
        آزاد(ptr);
        ptr1 = تہی;
    }
    ورنہ {
        ptr1 = realloc(ptr, سائز);
        اگر (!ptr1) {
            fprintf(stderr, "tcc: memory full\n");
            باہر_نکلو (1);
        }
    }
    واپس ptr1;
}

ST_FUNC خالی libc_free(خالی *ptr)
{
    آزاد(ptr);
}

/* defined to be not used */
#تعریف_کرو آزاد(p) use_tcc_free(p)
#تعریف_کرو realloc(p, s) use_tcc_realloc(p, s)

/* global so that every tcc_alloc()/tcc_free() call doesn't need to be changed */
ساکن خالی *(*reallocator)(خالی*, غیرعلامتی طویل) = default_reallocator;

LIBTCCAPI خالی tcc_سیٹ_realloc(TCCReallocFunc *my_realloc)
{
    reallocator = my_realloc ? my_realloc : default_reallocator;
}

/* in case MEM_DEBUG is #defined */
#تعریف_منسوخ tcc_free
#تعریف_منسوخ tcc_malloc
#تعریف_منسوخ tcc_realloc
#تعریف_منسوخ tcc_mallocz
#تعریف_منسوخ tcc_strdup

PUB_FUNC خالی tcc_free(خالی *ptr)
{
    reallocator(ptr, 0);
}

PUB_FUNC خالی *tcc_malloc(غیرعلامتی طویل سائز)
{
    واپس reallocator(0, سائز);
}

PUB_FUNC خالی *tcc_realloc(خالی *ptr, غیرعلامتی طویل سائز)
{
    واپس reallocator(ptr, سائز);
}

PUB_FUNC خالی *tcc_mallocz(غیرعلامتی طویل سائز)
{
    خالی *ptr;
    ptr = tcc_malloc(سائز);
    اگر (سائز)
        memset(ptr, 0, سائز);
    واپس ptr;
}

PUB_FUNC حرف *tcc_strdup(ثابت حرف *str)
{
    حرف *ptr;
    ptr = tcc_malloc(لڑی_لمبائی(str) + 1);
    strcpy(ptr, str);
    واپس ptr;
}

#اگر_تعریف_شدہ MEM_DEBUG

#تعریف_کرو MEM_DEBUG_MAGIC1 0xFEEDDEB1
#تعریف_کرو MEM_DEBUG_MAGIC2 0xFEEDDEB2
#تعریف_کرو MEM_DEBUG_MAGIC3 0xFEEDDEB3
#تعریف_کرو MEM_DEBUG_FILE_LEN 40
#تعریف_کرو MEM_DEBUG_CHECK3(سرخی) \
    (((غیرعلامتی حرف *) سرخی->magic3) + سرخی->سائز)
#تعریف_کرو MEM_USER_PTR(سرخی) \
    ((حرف *)سرخی + offsetof(mem_debug_سرخی_t, magic3))
#تعریف_کرو MEM_سرخی_PTR(ptr) \
    (mem_debug_سرخی_t *)((حرف*)ptr - offsetof(mem_debug_سرخی_t, magic3))

ساخت mem_debug_سرخی {
    غیرعلامتی magic1;
    غیرعلامتی سائز;
    ساخت mem_debug_سرخی *پچھلا;
    ساخت mem_debug_سرخی *اگلا;
    صحیح سطر_عدد;
    حرف file_name[MEM_DEBUG_FILE_LEN];
    غیرعلامتی magic2;
    ALIGNED(16) غیرعلامتی حرف magic3[4];
};

قسمتعریف ساخت mem_debug_سرخی mem_debug_سرخی_t;

TCC_SEM(ساکن mem_sem);
ساکن mem_debug_سرخی_t *mem_debug_chain;
ساکن غیرعلامتی mem_cur_سائز;
ساکن غیرعلامتی mem_max_سائز;
ساکن صحیح nb_حالتیں;

ساکن mem_debug_سرخی_t *malloc_check(خالی *ptr, ثابت حرف *پیغام)
{
    mem_debug_سرخی_t * سرخی = MEM_سرخی_PTR(ptr);
    اگر (سرخی->magic1 != MEM_DEBUG_MAGIC1 ||
        سرخی->magic2 != MEM_DEBUG_MAGIC2 ||
        read32le(MEM_DEBUG_CHECK3(سرخی)) != MEM_DEBUG_MAGIC3 ||
        سرخی->سائز == (غیرعلامتی)-1) {
        fprintf(stderr, "%s check failed\n", پیغام);
        اگر (سرخی->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                سرخی->file_name, سرخی->سطر_عدد);
        باہر_نکلو(1);
    }
    واپس سرخی;
}

PUB_FUNC خالی *tcc_malloc_debug(غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر)
{
    صحیح ofs;
    mem_debug_سرخی_t *سرخی;
    اگر (!سائز)
        واپس تہی;
    سرخی = tcc_malloc(حجم(mem_debug_سرخی_t) + سائز);
    سرخی->magic1 = MEM_DEBUG_MAGIC1;
    سرخی->magic2 = MEM_DEBUG_MAGIC2;
    سرخی->سائز = سائز;
    write32le(MEM_DEBUG_CHECK3(سرخی), MEM_DEBUG_MAGIC3);
    سرخی->سطر_عدد = سطر;
    ofs = لڑی_لمبائی(file) + 1 - MEM_DEBUG_FILE_LEN;
    strcpy(سرخی->file_name, file + (ofs > 0 ? ofs : 0));
    WAIT_SEM(&mem_sem);
    سرخی->اگلا = mem_debug_chain;
    سرخی->پچھلا = تہی;
    اگر (سرخی->اگلا)
        سرخی->اگلا->پچھلا = سرخی;
    mem_debug_chain = سرخی;
    mem_cur_سائز += سائز;
    اگر (mem_cur_سائز > mem_max_سائز)
        mem_max_سائز = mem_cur_سائز;
    POST_SEM(&mem_sem);
    واپس MEM_USER_PTR(سرخی);
}

PUB_FUNC خالی tcc_free_debug(خالی *ptr)
{
    mem_debug_سرخی_t *سرخی;
    اگر (!ptr)
        واپس;
    سرخی = malloc_check(ptr, "tcc_free");
    WAIT_SEM(&mem_sem);
    mem_cur_سائز -= سرخی->سائز;
    سرخی->سائز = (غیرعلامتی)-1;
    اگر (سرخی->اگلا)
        سرخی->اگلا->پچھلا = سرخی->پچھلا;
    اگر (سرخی->پچھلا)
        سرخی->پچھلا->اگلا = سرخی->اگلا;
    اگر (سرخی == mem_debug_chain)
        mem_debug_chain = سرخی->اگلا;
    POST_SEM(&mem_sem);
    tcc_free(سرخی);
}

PUB_FUNC خالی *tcc_mallocz_debug(غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر)
{
    خالی *ptr;
    ptr = tcc_malloc_debug(سائز,file,سطر);
    اگر (سائز)
        memset(ptr, 0, سائز);
    واپس ptr;
}

PUB_FUNC خالی *tcc_realloc_debug(خالی *ptr, غیرعلامتی طویل سائز, ثابت حرف *file, صحیح سطر)
{
    mem_debug_سرخی_t *سرخی;
    صحیح mem_debug_chain_update = 0;

    اگر (!ptr)
        واپس tcc_malloc_debug(سائز, file, سطر);
    اگر (!سائز) {
        tcc_free_debug(ptr);
        واپس تہی;
    }
    سرخی = malloc_check(ptr, "tcc_realloc");
    WAIT_SEM(&mem_sem);
    mem_cur_سائز -= سرخی->سائز;
    mem_debug_chain_update = (سرخی == mem_debug_chain);
    سرخی = tcc_realloc(سرخی, حجم(mem_debug_سرخی_t) + سائز);
    سرخی->سائز = سائز;
    write32le(MEM_DEBUG_CHECK3(سرخی), MEM_DEBUG_MAGIC3);
    اگر (سرخی->اگلا)
        سرخی->اگلا->پچھلا = سرخی;
    اگر (سرخی->پچھلا)
        سرخی->پچھلا->اگلا = سرخی;
    اگر (mem_debug_chain_update)
        mem_debug_chain = سرخی;
    mem_cur_سائز += سائز;
    اگر (mem_cur_سائز > mem_max_سائز)
        mem_max_سائز = mem_cur_سائز;
    POST_SEM(&mem_sem);
    واپس MEM_USER_PTR(سرخی);
}

PUB_FUNC حرف *tcc_strdup_debug(ثابت حرف *str, ثابت حرف *file, صحیح سطر)
{
    حرف *ptr;
    ptr = tcc_malloc_debug(لڑی_لمبائی(str) + 1, file, سطر);
    strcpy(ptr, str);
    واپس ptr;
}

PUB_FUNC خالی tcc_memcheck(صحیح d)
{
    WAIT_SEM(&mem_sem);
    nb_حالتیں += d;
    اگر (0 == nb_حالتیں && mem_cur_سائز) {
        mem_debug_سرخی_t *سرخی = mem_debug_chain;
        fflush(stdout);
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_سائز, mem_max_سائز);
        جب (سرخی) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                سرخی->file_name, سرخی->سطر_عدد, سرخی->سائز);
            سرخی = سرخی->اگلا;
        }
        fflush(stderr);
        mem_cur_سائز = 0;
        mem_max_سائز = 0;
        mem_debug_chain = تہی;
#اگر MEM_DEBUG-0 == 2
        باہر_نکلو(2);
#اگر_ختم
    }
    POST_SEM(&mem_sem);
}

/* restore the debug versions */
#تعریف_کرو tcc_free(ptr)           tcc_free_debug(ptr)
#تعریف_کرو tcc_malloc(سائز)        tcc_malloc_debug(سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_mallocz(سائز)       tcc_mallocz_debug(سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_realloc(ptr,سائز)   tcc_realloc_debug(ptr, سائز, __FILE__, __LINE__)
#تعریف_کرو tcc_strdup(str)         tcc_strdup_debug(str, __FILE__, __LINE__)

#اگر_ختم /* MEM_DEBUG */

#اگر_تعریف_شدہ _WIN32
# define realpath(file, buf) _fullpath(buf, file, 260)
#اگر_ختم

/* for #pragma once */
ST_FUNC صحیح normalized_PATHCMP(ثابت حرف *f1, ثابت حرف *f2)
{
    حرف *p1, *p2;
    صحیح ret = 1;
    اگر (!!(p1 = realpath(f1, تہی))) {
        اگر (!!(p2 = realpath(f2, تہی))) {
            ret = PATHCMP(p1, p2);
            libc_free(p2); /* realpath() requirement */
        }
        libc_free(p1);
    }
    واپس ret;
}

/********************************************************/
/* dynarrays */

ST_FUNC خالی dynarray_جوڑو(خالی *ptab, صحیح *nb_ptr, خالی *ڈیٹا)
{
    صحیح nb, nb_alloc;
    خالی **pp;

    nb = *nb_ptr;
    pp = *(خالی ***)ptab;
    /* every power of two we double array size */
    اگر ((nb & (nb - 1)) == 0) {
        اگر (!nb)
            nb_alloc = 1;
        ورنہ
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * حجم(خالی *));
        *(خالی***)ptab = pp;
    }
    pp[nb++] = ڈیٹا;
    *nb_ptr = nb;
}

ST_FUNC خالی dynarray_reset(خالی *pp, صحیح *n)
{
    خالی **p;
    برائے (p = *(خالی***)pp; *n; ++p, --*n)
        اگر (*p)
            tcc_free(*p);
    tcc_free(*(خالی**)pp);
    *(خالی**)pp = تہی;
}

ساکن خالی dynarray_بانٹو(حرف ***argv, صحیح *argc, ثابت حرف *p, صحیح sep)
{
    صحیح qot, c;
    CString str;
    برائے(;;) {
        جب (c = (غیرعلامتی حرف)*p, c <= ' ' && c != '\0')
            ++p;
        اگر (c == '\0')
            توڑو;
        cstr_new(&str);
        qot = 0;
        کرو {
            ++p;
            اگر (sep) { /* e.g. to split -Wl,-opt,arg */
                اگر (c == sep)
                    توڑو;
            } ورنہ {
                /* e.g. for tcc_set_options() or "tcc @listfile" */
                اگر (c == '\\' && (*p == '"' || *p == '\\')) {
                    c = *p++;
                } ورنہ اگر (c == '"') {
                    qot ^= 1;
                    جاری;
                } ورنہ اگر (c <= ' ' && !qot) {
                    توڑو;
                }
            }
            cstr_ccat(&str, c);
        } جب (c = (غیرعلامتی حرف)*p, c != '\0');
        cstr_ccat(&str, '\0');
        //printf("<%s>\n", str.data);
        dynarray_جوڑو(argv, argc, str.ڈیٹا);
    }
}

ساکن خالی tcc_بانٹو_راستہ(TCCState *s, خالی *p_ary, صحیح *p_nb_ary, ثابت حرف *اندر)
{
    ثابت حرف *p;
    کرو {
        صحیح c;
        CString str;

        cstr_new(&str);
        برائے (p = اندر; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            اگر (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                اگر (c == 'B')
                    cstr_cat(&str, s->tcc_lib_راستہ, -1);
                اگر (c == 'R')
                    cstr_cat(&str, CONFIG_SYSROOT, -1);
                اگر (c == 'f' && file) {
                    /* substitute current file's dir */
                    ثابت حرف *f = file->true_filename;
                    ثابت حرف *b = tcc_basename(f);
                    اگر (b > f)
                        cstr_cat(&str, f, b - f - 1);
                    ورنہ
                        cstr_cat(&str, ".", 1);
                }
            } ورنہ {
                cstr_ccat(&str, c);
            }
        }
        اگر (str.سائز) {
            cstr_ccat(&str, '\0');
            dynarray_جوڑو(p_ary, p_nb_ary, str.ڈیٹا);
        }
        اندر = p+1;
    } جب (*p);
}

/********************************************************/
/* warning / error */

/* warn_... option bits */
#تعریف_کرو WARN_ON  1 /* warning is on (-Woption) */
#تعریف_کرو WARN_ERR 2 /* warning is an error (-Werror=option) */
#تعریف_کرو WARN_NOE 4 /* warning is not an error (-Wno-error=option) */

/* error1() modes */
شمار { ERROR_WARN, ERROR_NOABORT, ERROR_ERROR };

ساکن خالی error1(صحیح منوال, ثابت حرف *fmt, va_list ap)
{
    BufferedFile **pf, *f;
    TCCState *s1 = tcc_state;
    CString cs;
    صحیح سطر = 0;

    tcc_exit_state(s1);

    اگر (منوال == ERROR_WARN) {
        اگر (s1->warn_error)
            منوال = ERROR_ERROR;
        اگر (s1->warn_عدد) {
            /* handle tcc_warning_c(warn_option)(fmt, ...) */
            صحیح wopt = *(&s1->warn_none + s1->warn_عدد);
            s1->warn_عدد = 0;
            اگر (0 == (wopt & WARN_ON))
                واپس;
            اگر (wopt & WARN_ERR)
                منوال = ERROR_ERROR;
            اگر (wopt & WARN_NOE)
                منوال = ERROR_WARN;
        }
        اگر (s1->warn_none)
            واپس;
    }

    cstr_new(&cs);
    اگر (fmt[0] == '%' && fmt[1] == 'i' && fmt[2] == ':')
        سطر = va_arg(ap, صحیح), fmt += 3;
    f = تہی;
    اگر (s1->error_سیٹ_jmp_enabled) { /* we're called while parsing a file */
        /* use upper file if inline ":asm:" or token ":paste:" */
        برائے (f = file; f && f->filename[0] == ':'; f = f->پچھلا)
            ;
    }
    اگر (f) {
        برائے(pf = s1->include_ڈھیر; pf < s1->include_ڈھیر_ptr; pf++)
            cstr_printf(&cs, "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->سطر_عدد - 1);
        اگر (0 == سطر)
            سطر = f->سطر_عدد - ((tok_flags & TOK_FLAG_BOL) && !macro_ptr);
        cstr_printf(&cs, "%s:%d: ", f->filename, سطر);
    } ورنہ اگر (s1->current_filename) {
        cstr_printf(&cs, "%s: ", s1->current_filename);
    } ورنہ {
        cstr_printf(&cs, "tcc: ");
    }
    cstr_printf(&cs, منوال == ERROR_WARN ? "warning: " : "error: ");
    اگر (pp_اظہاریہ > 1)
        pp_error(&cs); /* special handler for preprocessor expression errors */
    ورنہ
        cstr_vprintf(&cs, fmt, ap);
    اگر (!s1->error_func) {
        /* default case: stderr */
        اگر (s1 && s1->output_type == TCC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            لکھو("\n"); /* print a newline during tcc -E */
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", (حرف*)cs.ڈیٹا);
        fflush(stderr); /* print error/warning now (win32) */
    } ورنہ {
        s1->error_func(s1->error_opaque, (حرف*)cs.ڈیٹا);
    }
    cstr_free(&cs);
    اگر (منوال != ERROR_WARN)
        s1->nb_errors++;
    اگر (منوال == ERROR_ERROR && s1->error_سیٹ_jmp_enabled) {
        جب (nb_stk_ڈیٹا)
            tcc_free(*(خالی**)stk_ڈیٹا[--nb_stk_ڈیٹا]);
        longjmp(s1->error_jmp_buf, 1);
    }
}

LIBTCCAPI خالی tcc_سیٹ_error_func(TCCState *s, خالی *error_opaque, TCCErrorFunc *error_func)
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC صحیح _tcc_error_noabort(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_NOABORT, fmt, ap);
    va_end(ap);
    واپس -1;
}

#تعریف_منسوخ _tcc_error
PUB_FUNC خالی _tcc_error(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_ERROR, fmt, ap);
    باہر_نکلو(1);
}
#تعریف_کرو _tcc_error use_tcc_error_noabort

PUB_FUNC خالی _tcc_warning(ثابت حرف *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    error1(ERROR_WARN, fmt, ap);
    va_end(ap);
}


/********************************************************/
/* I/O layer */

ST_FUNC خالی tcc_open_bf(TCCState *s1, ثابت حرف *filename, صحیح initlen)
{
    BufferedFile *bf;
    صحیح buflen = initlen ? initlen : IO_BUF_سائز;

    bf = tcc_mallocz(حجم(BufferedFile) + buflen);
    bf->buf_ptr = bf->بفر;
    bf->buf_انتہا = bf->بفر + initlen;
    bf->buf_انتہا[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, حجم(bf->filename), filename);
#اگر_تعریف_شدہ _WIN32
    normalize_slashes(bf->filename);
#اگر_ختم
    bf->true_filename = bf->filename;
    bf->سطر_عدد = 1;
    bf->ifdef_ڈھیر_ptr = s1->ifdef_ڈھیر_ptr;
    bf->fd = -1;
    bf->پچھلا = file;
    bf->پچھلا_tok_flags = tok_flags;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC خالی tcc_close(خالی)
{
    TCCState *s1 = tcc_state;
    BufferedFile *bf = file;
    اگر (bf->fd > 0) {
        close(bf->fd);
        کل_سطریں += bf->سطر_عدد - 1;
    }
    اگر (bf->true_filename != bf->filename)
        tcc_free(bf->true_filename);
    file = bf->پچھلا;
    tok_flags = bf->پچھلا_tok_flags;
    tcc_free(bf);
}

ساکن صحیح _tcc_open(TCCState *s1, ثابت حرف *filename)
{
    صحیح fd;
    اگر (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    ورنہ
        fd = open(filename, O_RDONLY | O_ثنائی_2);
    اگر ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        لکھو("%s %*s%s\n", fd < 0 ? "nf":"->",
               (صحیح)(s1->include_ڈھیر_ptr - s1->include_ڈھیر), "", filename);
    واپس fd;
}

ST_FUNC صحیح tcc_open(TCCState *s1, ثابت حرف *filename)
{
    صحیح fd = _tcc_open(s1, filename);
    اگر (fd < 0)
        واپس -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    واپس 0;
}

/* compile the file opened in 'file'. Return non zero if errors. */
ساکن صحیح tcc_compile(TCCState *s1, صحیح filetype, ثابت حرف *str, صحیح fd)
{
    /* Here we enter the code section where we use the global variables for
       parsing and code generation (tccpp.c, tccgen.c, <target>-gen.c).
       Other threads need to wait until we're done.

       Alternatively we could use thread local storage for those global
       variables, which may or may not have advantages */

    tcc_enter_state(s1);
    s1->error_سیٹ_jmp_enabled = 1;

    اگر (setjmp(s1->error_jmp_buf) == 0) {

        اگر (fd == -1) {
            صحیح len = لڑی_لمبائی(str);
            tcc_open_bf(s1, "<string>", len);
            حافظہ_نقل(file->بفر, str, len);
        } ورنہ {
            tcc_open_bf(s1, str, 0);
            file->fd = fd;
        }

        preprocess_آغاز(s1, filetype);
        tccgen_init(s1);

        اگر (s1->output_type == TCC_OUTPUT_PREPROCESS) {
            tcc_preprocess(s1);
        } ورنہ {
            tccelf_begin_file(s1);
            اگر (filetype & (AFF_TYPE_ASM | AFF_TYPE_ASMPP)) {
                tcc_assemble(s1, !!(filetype & AFF_TYPE_ASMPP));
            } ورنہ {
                tccgen_compile(s1);
            }
            tccelf_انتہا_file(s1);
        }
    }
    tccgen_اختتام(s1);
    preprocess_انتہا(s1);
    s1->error_سیٹ_jmp_enabled = 0;
    tcc_exit_state(s1);
    واپس s1->nb_errors != 0 ? -1 : 0;
}

LIBTCCAPI صحیح tcc_compile_string(TCCState *s, ثابت حرف *str)
{
    واپس tcc_compile(s, s->filetype, str, -1);
}

/* define a preprocessor symbol. value can be NULL, sym can be "sym=val" */
LIBTCCAPI خالی tcc_define_علامت(TCCState *s1, ثابت حرف *sym, ثابت حرف *قدر)
{
    ثابت حرف *eq;
    اگر (تہی == (eq = strchr(sym, '=')))
        eq = strchr(sym, 0);
    اگر (تہی == قدر)
        قدر = *eq ? eq + 1 : "1";
    cstr_printf(&s1->cmdline_defs, "#define %.*s %s\n", (صحیح)(eq-sym), sym, قدر);
}

/* undefine a preprocessor symbol */
LIBTCCAPI خالی tcc_undefine_علامت(TCCState *s1, ثابت حرف *sym)
{
    cstr_printf(&s1->cmdline_defs, "#undef %s\n", sym);
}


LIBTCCAPI TCCState *tcc_new(خالی)
{
    TCCState *s;

    s = tcc_mallocz(حجم(TCCState));
#اگر_تعریف_شدہ MEM_DEBUG
    tcc_memcheck(1);
#اگر_ختم

#تعریف_منسوخ gnu_ext
    s->gnu_ext = 1;
    s->tcc_ext = 1;
    s->nocommon = 1;
    s->dollars_اندر_identifiers = 1; /*on by default like in gcc/clang*/
    s->cversion = 199901; /* default unless -std=c11 is supplied */
    s->warn_implicit_function_declaration = 1;
    s->warn_discarded_qualifiers = 1;
    s->ms_extensions = 1;
    s->unwind_tables = 1;

#اگر_تعریف_شدہ CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ہدف_I386
    s->seg_سائز = 32;
#اگر_ختم
    /* enable this if you want symbols with leading underscore on windows: */
#اگر defined TCC_ہدف_MACHO /* || defined TCC_TARGET_PE */
    s->leading_underscore = 1;
#اگر_ختم
#اگر_تعریف_شدہ TCC_ARM_HARDFLOAT
    s->float_abi = ARM_HARD_FLOAT;
#اگر_ختم
#اگر defined TCC_ہدف_ARM64 && defined TCC_ہدف_PE
    s->pe_dll_characteristics = 0x8160;
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_NEW_DTAGS
    s->enable_new_dtags = 1;
#اگر_ختم
    s->ppfp = stdout;
    /* might be used in error() before preprocess_start() */
    s->include_ڈھیر_ptr = s->include_ڈھیر;

    tcc_سیٹ_lib_راستہ(s, CONFIG_TCCDIR);
#اگر_تعریف_شدہ CONFIG_TCC_SWITCHES /* predefined options */
    tcc_سیٹ_options(s, CONFIG_TCC_SWITCHES);
#اگر_ختم
    واپس s;
}

LIBTCCAPI خالی tcc_delete(TCCState *s1)
{
    /* free sections */
    tccelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);

    tcc_free(s1->tcc_lib_راستہ);
    tcc_free(s1->soname);
    tcc_free(s1->rpath);
    tcc_free(s1->elfint);
    tcc_free(s1->elf_entryname);
    tcc_free(s1->init_علامت);
    tcc_free(s1->fini_علامت);
    tcc_free(s1->mapfile);
    tcc_free(s1->outfile);
    tcc_free(s1->deps_outfile);
#اگر defined TCC_ہدف_MACHO
    tcc_free(s1->install_name);
#اگر_ختم
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->ہدف_deps, &s1->nb_ہدف_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);
    dynarray_reset(&s1->link_argv, &s1->link_argc);
    cstr_free(&s1->cmdline_defs);
    cstr_free(&s1->cmdline_incl);
    tcc_free(s1->dState);
#اگر_تعریف_شدہ TCC_IS_NATIVE
    /* free runtime memory */
    tcc_تسلسل_free(s1);
#اگر_ختم
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1);
#اگر_تعریف_شدہ MEM_DEBUG
    tcc_memcheck(-1);
#اگر_ختم
}

LIBTCCAPI صحیح tcc_سیٹ_output_type(TCCState *s, صحیح output_type)
{
#اگر_تعریف_شدہ CONFIG_TCC_PIE
    اگر (output_type == TCC_OUTPUT_EXE)
        output_type |= TCC_OUTPUT_DYN;
#اگر_ختم
    s->output_type = output_type;

    اگر (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        tcc_جوڑو_sysinclude_راستہ(s, CONFIG_TCC_SYSINCLUDEPATHS);
    }

    اگر (output_type == TCC_OUTPUT_PREPROCESS) {
        s->do_debug = 0;
        واپس 0;
    }

    /* add sections */
    tccelf_new(s);

    اگر (output_type == TCC_OUTPUT_OBJ) {
        /* always elf for objects */
        s->output_format = TCC_OUTPUT_FORMAT_ELF;
        واپس 0;
    }

    اگر (!s->nostdlib_paths)
        tcc_جوڑو_library_راستہ(s, CONFIG_TCC_LIBPATHS);

#اگر_تعریف_شدہ TCC_ہدف_PE
# ifdef TCC_IS_NATIVE
    /* allow linking with system dll's directly */
    tcc_جوڑو_systemdir(s);
# endif

#وگرنہ_اگر defined TCC_ہدف_MACHO
# ifdef TCC_IS_NATIVE
    tcc_جوڑو_macos_sdkpath(s);
# endif

#ورنہ
    /* paths for crt objects */
    tcc_بانٹو_راستہ(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_TCC_CRTPREFIX);
    اگر (output_type != TCC_OUTPUT_حافظہ && !s->nostdlib)
        tccelf_جوڑو_crtbegin(s); /* may produce errors */
#اگر_ختم
    واپس s->nb_errors ? -1 : 0;
}

LIBTCCAPI صحیح tcc_جوڑو_include_راستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_بانٹو_راستہ(s, &s->include_paths, &s->nb_include_paths, pathname);
    واپس 0;
}

LIBTCCAPI صحیح tcc_جوڑو_sysinclude_راستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_بانٹو_راستہ(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    واپس 0;
}

LIBTCCAPI صحیح tcc_جوڑو_library_راستہ(TCCState *s, ثابت حرف *pathname)
{
    tcc_بانٹو_راستہ(s, &s->library_paths, &s->nb_library_paths, pathname);
    واپس 0;
}

LIBTCCAPI خالی tcc_سیٹ_lib_راستہ(TCCState *s, ثابت حرف *راستہ)
{
    tcc_سیٹ_str(&s->tcc_lib_راستہ, راستہ);
}

/* add/update a 'DLLReference', Just find if level == -1  */
ST_FUNC DLLReference *tcc_جوڑو_dllref(TCCState *s1, ثابت حرف *dllname, صحیح level)
{
    DLLReference *ref = تہی;
    صحیح i;
    برائے (i = 0; i < s1->nb_loaded_dlls; i++)
        اگر (0 == strcmp(s1->loaded_dlls[i]->name, dllname)) {
            ref = s1->loaded_dlls[i];
            توڑو;
        }
    اگر (level == -1)
        واپس ref;
    اگر (ref) {
        اگر (level < ref->level)
            ref->level = level;
        ref->ملا = 1;
        واپس ref;
    }
    ref = tcc_mallocz(حجم(DLLReference) + لڑی_لمبائی(dllname));
    strcpy(ref->name, dllname);
    dynarray_جوڑو(&s1->loaded_dlls, &s1->nb_loaded_dlls, ref);
    ref->level = level;
    ref->اشاریہ = s1->nb_loaded_dlls;
    واپس ref;
}

ساکن صحیح tcc_جوڑو_ثنائی(TCCState *s1, صحیح flags, ثابت حرف *filename, صحیح fd)
{
    ElfW(Ehdr) ehdr;
    صحیح obj_type;
    ثابت حرف *saved_filename = s1->current_filename;
    صحیح ret = 0;

    s1->current_filename = filename;
    obj_type = tcc_object_type(fd, &ehdr);
    lseek(fd, 0, SEEK_SET);

    انتخاب (obj_type) {

    حالت AFF_BINTYPE_REL:
        ret = tcc_بھرو_object_file(s1, fd, 0);
        توڑو;

    حالت AFF_BINTYPE_AR:
        ret = tcc_بھرو_archive(s1, fd, !(flags & AFF_پورا_ARCHIVE));
        توڑو;

#اگر defined TCC_ہدف_UNIX
    حالت AFF_BINTYPE_DYN:
        اگر (s1->output_type == TCC_OUTPUT_حافظہ) {
#اگر_تعریف_شدہ TCC_IS_NATIVE
            خالی* dl = dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
            اگر (dl)
                tcc_جوڑو_dllref(s1, filename, 0)->handle = dl;
            ورنہ
                ret = FILE_NOT_RECOGNIZED;
#اگر_ختم
        } ورنہ
            ret = tcc_بھرو_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        توڑو;

    طےشدہ:
        /* as GNU ld, consider it is an ld script if not recognized */
        ret = tcc_بھرو_ldscript(s1, fd);
        توڑو;

#وگرنہ_اگر defined TCC_ہدف_MACHO
    حالت AFF_BINTYPE_DYN:
    case_dyn_or_tbd:
        اگر (s1->output_type == TCC_OUTPUT_حافظہ) {
#اگر_تعریف_شدہ TCC_IS_NATIVE
            خالی* dl;
            ثابت حرف* soname = filename;
            حرف *tmp = 0;
            اگر (obj_type != AFF_BINTYPE_DYN) {
                tmp = macho_tbd_soname(fd);
                اگر (tmp)
                    soname = tmp;
            }
            dl = dlopen(soname, RTLD_GLOBAL | RTLD_LAZY);
            اگر (dl)
                tcc_جوڑو_dllref(s1, soname, 0)->handle = dl;
            ورنہ
                ret = FILE_NOT_RECOGNIZED;
	    tcc_free(tmp);
#اگر_ختم
        } ورنہ اگر (obj_type == AFF_BINTYPE_DYN) {
            ret = macho_بھرو_dll(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        } ورنہ {
            ret = macho_بھرو_tbd(s1, fd, filename, (flags & AFF_REFERENCED_DLL) != 0);
        }
        اگر (ret)
            ret = FILE_NOT_RECOGNIZED;
        توڑو;

    طےشدہ:
    {
        ثابت حرف *ext = tcc_fileextension(filename);
        اگر (!strcmp(ext, ".tbd"))
            جاؤ case_dyn_or_tbd;
        اگر (!strcmp(ext, ".dylib")) {
            obj_type = AFF_BINTYPE_DYN;
            جاؤ case_dyn_or_tbd;
        }
        ret = FILE_NOT_RECOGNIZED;
        توڑو;
    }

#وگرنہ_اگر defined TCC_ہدف_PE
    طےشدہ:
        اگر (pe_بھرو_file(s1, fd, filename))
            ret = FILE_NOT_RECOGNIZED;
        توڑو;
#اگر_ختم

#اگر_تعریف_شدہ TCC_ہدف_COFF
    حالت AFF_BINTYPE_C67:
        ret = tcc_بھرو_coff(s1, fd);
        توڑو;
#اگر_ختم
    }

    close(fd);
    s1->current_filename = saved_filename;
    اگر (ret == FILE_NOT_RECOGNIZED)
        واپس tcc_error_noabort("%s: unrecognized file type", filename);
    واپس ret;
}

/* OpenBSD: choose latest from libxxx.so.x.y versions */
#اگر defined TARGETOS_OpenBSD && !defined _WIN32
#شامل <glob.h>
ساکن صحیح tcc_glob_so(TCCState *s1, ثابت حرف *نمونہ, حرف *buf, صحیح سائز)
{
    ثابت حرف *ستارہ;
    glob_t g;
    حرف *p;
    صحیح i, v, v1, v2, v3;

    ستارہ = strchr(نمونہ, '*');
    اگر (!ستارہ || glob(نمونہ, 0, تہی, &g))
        واپس -1;
    برائے (v = -1, i = 0; i < g.gl_pathc; ++i) {
        p = g.gl_pathv[i];
        اگر (2 != لڑی_سے_پڑھو(p + (ستارہ - نمونہ), "%d.%d.%d", &v1, &v2, &v3))
            جاری;
        اگر ((v1 = v1 * 1000 + v2) > v)
            v = v1, pstrcpy(buf, سائز, p);
    }
    globfree(&g);
    واپس v;
}
#اگر_ختم

ساکن صحیح guess_filetype(ثابت حرف *filename)
{
    صحیح filetype = 0;
    اگر (1) {
        /* use a file extension to detect a filetype */
        ثابت حرف *ext = tcc_fileextension(filename);
        اگر (ext[0]) {
            ext++;
            اگر (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            ورنہ اگر (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            ورنہ اگر (!PATHCMP(ext, "c")
                     || !PATHCMP(ext, "h")
                     || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            ورنہ
                filetype |= AFF_TYPE_BIN;
        } ورنہ {
            filetype = AFF_TYPE_C;
        }
    }
    واپس filetype;
}

ST_FUNC صحیح tcc_جوڑو_file_اندرونی(TCCState *s1, ثابت حرف *filename, صحیح flags)
{
    صحیح fd;

#اگر defined TARGETOS_OpenBSD && !defined _WIN32
    حرف buf[1024];
    اگر (tcc_glob_so(s1, filename, buf, حجم buf) >= 0)
        filename = buf;
#اگر_ختم

    اگر (0 == (flags & AFF_TYPE_نقاب))
        flags |= guess_filetype(filename);

    /* ignore binary files with -E */
    اگر (s1->output_type == TCC_OUTPUT_PREPROCESS
        && (flags & AFF_TYPE_BIN))
        واپس 0;

    /* open the file */
    fd = _tcc_open(s1, filename);
    اگر (fd < 0) {
        اگر (flags & AFF_PRINT_ERROR)
            tcc_error_noabort("file '%s' not found", filename);
        واپس FILE_NOT_ملا;
    }

    اگر (flags & AFF_TYPE_BIN)
        واپس tcc_جوڑو_ثنائی(s1, flags, filename, fd);

    dynarray_جوڑو(&s1->ہدف_deps, &s1->nb_ہدف_deps, tcc_strdup(filename));
    واپس tcc_compile(s1, flags, filename, fd);
}

LIBTCCAPI صحیح tcc_جوڑو_file(TCCState *s, ثابت حرف *filename)
{
    واپس tcc_جوڑو_file_اندرونی(s, filename, s->filetype | AFF_PRINT_ERROR);
}

ساکن صحیح tcc_جوڑو_library_اندرونی(TCCState *s1, ثابت حرف *fmt,
    ثابت حرف *filename, صحیح flags, حرف **paths, صحیح nb_paths)
{
    حرف buf[1024];
    صحیح i, ret;

    برائے(i = 0; i < nb_paths; i++) {
        snprintf(buf, حجم(buf), fmt, paths[i], filename);
        ret = tcc_جوڑو_file_اندرونی(s1, buf, flags & ~AFF_PRINT_ERROR);
        اگر (ret != FILE_NOT_ملا)
            واپس ret;
    }
    اگر (flags & AFF_PRINT_ERROR)
        tcc_error_noabort("%s '%s' not found",
            flags & AFF_TYPE_LIB ? "library" : "file", filename);
    واپس FILE_NOT_ملا;
}

/* find and load a dll. Return non zero if not found */
ST_FUNC صحیح tcc_جوڑو_dll(TCCState *s, ثابت حرف *filename, صحیح flags)
{
    واپس tcc_جوڑو_library_اندرونی(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

/* find [cross-]libtcc1.a and tcc helper objects in library path */
ST_FUNC صحیح tcc_جوڑو_support(TCCState *s1, ثابت حرف *filename)
{
    حرف buf[100];
    اگر (CONFIG_TCC_CROSSPREFIX[0])
        filename = strcat(strcpy(buf, CONFIG_TCC_CROSSPREFIX), filename);
    واپس tcc_جوڑو_dll(s1, filename, AFF_PRINT_ERROR);
}

#اگر_تعریف_شدہ TCC_ہدف_UNIX
ST_FUNC صحیح tcc_جوڑو_crt(TCCState *s1, ثابت حرف *filename)
{
    واپس tcc_جوڑو_library_اندرونی(s1, "%s/%s",
        filename, AFF_PRINT_ERROR, s1->crt_paths, s1->nb_crt_paths);
}
#اگر_ختم

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحیح tcc_جوڑو_library(TCCState *s, ثابت حرف *libraryname)
{
    ساکن ثابت حرف * ثابت libs[] = {
#اگر defined TCC_ہدف_PE
        "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll",
#وگرنہ_اگر defined TCC_ہدف_MACHO
        "%s/lib%s.dylib", "%s/lib%s.tbd",
#وگرنہ_اگر defined TARGETOS_OpenBSD
        "%s/lib%s.so.*",
#ورنہ
        "%s/lib%s.so",
#اگر_ختم
        "%s/lib%s.a",
        تہی
    };
    صحیح flags = AFF_TYPE_LIB | (s->filetype & AFF_پورا_ARCHIVE);
    /* if libraryname begins with a colon, it means search lib paths for
       exactly the following file, without lib prefix or anything */
    اگر (*libraryname == ':') {
        libraryname++;
    } ورنہ {
        ثابت حرف * ثابت *pp = libs;
        اگر (s->static_link)
            pp += حجم(libs) / حجم(*libs) - 2; /* only "%s/lib%s.a" */
        جب (*pp) {
            صحیح ret = tcc_جوڑو_library_اندرونی(s, *pp,
                libraryname, flags, s->library_paths, s->nb_library_paths);
            اگر (ret != FILE_NOT_ملا)
                واپس ret;
            ++pp;
        }
    }
    /* fallback to try file without pre- or sufffix */
    واپس tcc_جوڑو_dll(s, libraryname, flags | AFF_PRINT_ERROR);
}

/* handle #pragma comment(lib,) */
ST_FUNC خالی tcc_جوڑو_pragma_libs(TCCState *s1)
{
    صحیح i;
    برائے (i = 0; i < s1->nb_pragma_libs; i++)
        tcc_جوڑو_library(s1, s1->pragma_libs[i]);
}

/********************************************************/
/* options parser */

ساکن صحیح strstart(ثابت حرف *val, ثابت حرف **str)
{
    ثابت حرف *p, *q;
    p = *str;
    q = val;
    جب (*q) {
        اگر (*p != *q)
            واپس 0;
        p++;
        q++;
    }
    *str = p;
    واپس 1;
}

ساخت lopt {
    TCCState *s;
    ثابت حرف *opt, *arg;
    صحیح مطابقت;
};

/* match linker option */
ساکن صحیح link_option(ساخت lopt *o, ثابت حرف *q)
{
    ثابت حرف *p;
    صحیح c, r;
redo:
    /* there should be 1 or 2 dashes */
    p = o->opt;
    اگر (*p++ != '-')
        واپس 0;
    اگر (*p == '-')
        p++;
    r = 1;
    اگر (q[0] == '?') { /* check for no-/disable- prefix */
        ++q;
        اگر (p[0] == 'n' && p[1] == 'o' && p[2] == '-')
            p += 3, r = -1;
#اگر_تعریف_شدہ TCC_ہدف_PE
        ورنہ اگر (0 == memcmp(p, "disable-", 8))
            p += 8, r = -1;
#اگر_ختم
    }
    جب ((c = *q) == *p) {
        اگر (c == '\0')
            جاؤ succ; /* -Wl,-opt */
        ++p;
        اگر (c == '=')
            جاؤ succ; /* -Wl,-opt=arg */
        ++q;
    }
    اگر (*p == '\0') {
        اگر (c == '|')
            جاؤ succ;
        اگر (c == '=' || c == ':') {
            اگر (o->s->link_optind + 1 < o->s->link_argc) {
                p = o->s->link_argv[++o->s->link_optind];
                جاؤ succ; /* -Wl,-opt,arg */
            }
            o->مطابقت = 1; /* -Wl,-opt -Wl,arg */
            واپس 0;
        }
    } ورنہ اگر (c == ':')
        جاؤ succ; /* -Wl,-Iarg */
    جب (*q)
        اگر (*q++ == '|')
            جاؤ redo;
    واپس 0;
succ:
    o->arg = p;
    //printf("set %s '%s'\n", o->opt, o->arg);
    واپس r;
}

ساکن خالی دلائل_parser_جوڑو_file(TCCState *s, ثابت حرف* filename, صحیح filetype);

#تعریف_کرو سیٹ_OR_CLEAR(v,f) (v = r > 0 ? v | f : v & ~f)
#تعریف_کرو سیٹ_OR_CLEAR_2(v,f1,f2) (v = r > 0 ? v | f1 : v & ~f2)

/* set linker options */
ساکن صحیح tcc_سیٹ_linker(TCCState *s, ثابت حرف *optarg)
{
    TCCState *s1 = s;

    dynarray_بانٹو(&s1->link_argv, &s1->link_argc, optarg, ',');

    جب (s->link_optind < s->link_argc) {
        حرف *انتہا = تہی;
        صحیح ignoring = 0;
        ساخت lopt o = {0};
        صحیح r;
        o.s = s;
        o.opt = s->link_argv[s->link_optind];

        اگر (link_option(&o, "Bsymbolic")) {
            s->symbolic = 1;
        } ورنہ اگر (link_option(&o, "nostdlib")) {
            s->nostdlib_paths = 1;
        } ورنہ اگر (link_option(&o, "e=|entry=")) {
            tcc_سیٹ_str(&s->elf_entryname, o.arg);
        } ورنہ اگر (link_option(&o, "image-base=|Ttext=")) {
            s->متن_addr = strtoull(o.arg, &انتہا, 16);
            s->has_متن_addr = 1;
        } ورنہ اگر (link_option(&o, "init=")) {
            tcc_سیٹ_str(&s->init_علامت, o.arg);
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "fini=")) {
            tcc_سیٹ_str(&s->fini_علامت, o.arg);
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "Map=")) {
            tcc_سیٹ_str(&s->mapfile, o.arg);
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "oformat=")) {
#اگر defined TCC_ہدف_PE
            اگر (0 == لڑی_موازنہ("pe-", o.arg, 3))
#وگرنہ_اگر PTR_سائز == 8
            اگر (0 == لڑی_موازنہ("elf64-", o.arg, 6))
#ورنہ
            اگر (0 == لڑی_موازنہ("elf32-", o.arg, 6))
#اگر_ختم
                s->output_format = TCC_OUTPUT_FORMAT_ELF;
            ورنہ اگر (0==strcmp("binary", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_ثنائی;
#اگر defined TCC_ہدف_COFF
            ورنہ اگر (0==strcmp("coff", o.arg))
                s->output_format = TCC_OUTPUT_FORMAT_COFF;
#اگر_ختم
            ورنہ
                جاؤ err;
        } ورنہ اگر (link_option(&o, "export-all-symbols|export-dynamic|E")) {
            s->rdynamic = 1;
        } ورنہ اگر (link_option(&o, "rpath=")) {
            tcc_concat_str(&s->rpath, o.arg, ':');
        } ورنہ اگر (link_option(&o, "dynamic-linker=|I:")) {
            tcc_سیٹ_str(&s->elfint, o.arg);
        } ورنہ اگر (link_option(&o, "enable-new-dtags")) {
            s->enable_new_dtags = 1;
        } ورنہ اگر (link_option(&o, "section-alignment=")) {
            s->section_align = strtoul(o.arg, &انتہا, 16);
        } ورنہ اگر (link_option(&o, "soname=|install_name=")) {
            tcc_سیٹ_str(&s->soname, o.arg);
        } ورنہ اگر (!!(r = link_option(&o, "?whole-archive"))) {
            سیٹ_OR_CLEAR(s->filetype, AFF_پورا_ARCHIVE);
        } ورنہ اگر (link_option(&o, "znodelete")) {
            s->znodelete = 1;
#اگر_تعریف_شدہ TCC_ہدف_PE
        } ورنہ اگر (link_option(&o, "large-address-aware")) {
            s->pe_characteristics |= 0x20;
        } ورنہ اگر (!!(r = link_option(&o, "?dynamicbase"))) {
            سیٹ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x40, 0x60);
        } ورنہ اگر (!!(r = link_option(&o, "?high-entropy-va"))) {
            سیٹ_OR_CLEAR_2(s1->pe_dll_characteristics, 0x60, 0x20);
        } ورنہ اگر (!!(r = link_option(&o, "?nxcompat"))) {
            سیٹ_OR_CLEAR(s1->pe_dll_characteristics, 0x100);
        } ورنہ اگر (!!(r = link_option(&o, "?tsaware"))) {
            سیٹ_OR_CLEAR(s1->pe_dll_characteristics, 0x8000);
        } ورنہ اگر (link_option(&o, "file-alignment=")) {
            s->pe_file_align = strtoul(o.arg, &انتہا, 16);
        } ورنہ اگر (link_option(&o, "stack=")) {
            s->pe_ڈھیر_سائز = strtoul(o.arg, &انتہا, 10);
        } ورنہ اگر (link_option(&o, "subsystem=")) {
            اگر (pe_setsubsy(s, o.arg) < 0)
                جاؤ err;
#وگرنہ_اگر defined TCC_ہدف_MACHO
        } ورنہ اگر (link_option(&o, "all_load")) {
	    s->filetype |= AFF_پورا_ARCHIVE;
        } ورنہ اگر (link_option(&o, "force_load=")) {
            دلائل_parser_جوڑو_file(s, o.arg, AFF_TYPE_LIB | AFF_پورا_ARCHIVE);
        } ورنہ اگر (link_option(&o, "single_module")) {
            ignoring = 1;
#اگر_ختم
        } ورنہ اگر (link_option(&o, "as-needed")) {
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "O")) {
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "z=")) {
            ignoring = 1;
        } ورنہ اگر (link_option(&o, "L:")) {
            tcc_جوڑو_library_راستہ(s, o.arg);
        } ورنہ اگر (link_option(&o, "l:")) {
            دلائل_parser_جوڑو_file(s, o.arg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_نقاب));
        } ورنہ اگر (o.مطابقت) {
            واپس 0; /* expecting argument with next '-Wl,' */
        } ورنہ {
    err:
            واپس tcc_error_noabort("unsupported linker option '%s'", o.opt);
        }
        اگر (ignoring)
            tcc_warning_c(warn_unsupported)("unsupported linker option '%s'", o.opt);
        ++s->link_optind;
    }
    واپس 0;
}

قسمتعریف ساخت TCCOption {
    ثابت حرف *name;
    uint16_t اشاریہ;
    uint16_t flags;
} TCCOption;

شمار {
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
    TCC_OPTION_تسلسل,
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

ساکن ثابت TCCOption tcc_options[] = {
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
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    { "bt", TCC_OPTION_bt, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#اگر_ختم
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    { "b", TCC_OPTION_b, 0 },
#اگر_ختم
    { "g", TCC_OPTION_g, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#اگر_تعریف_شدہ TCC_ہدف_MACHO
    { "compatibility_version", TCC_OPTION_compatibility_نسخہ, TCC_OPTION_HAS_ARG },
    { "current_version", TCC_OPTION_current_نسخہ, TCC_OPTION_HAS_ARG },
    { "dynamiclib", TCC_OPTION_dynamiclib, 0 },
    { "flat_namespace", TCC_OPTION_flat_namespace, 0 },
    { "install_name", TCC_OPTION_install_name, TCC_OPTION_HAS_ARG },
    { "two_levelnamespace", TCC_OPTION_two_levelnamespace, 0 },
    { "undefined", TCC_OPTION_undefined, TCC_OPTION_HAS_ARG },
#اگر_ختم
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
    { "run", TCC_OPTION_تسلسل, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "rstdin", TCC_OPTION_rstdin, TCC_OPTION_HAS_ARG },
    { "rdynamic", TCC_OPTION_rdynamic, 0 },
    { "r", TCC_OPTION_r, 0 },
    { "Wl,", TCC_OPTION_Wl, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "Wp,", TCC_OPTION_Wp, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "W", TCC_OPTION_W, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
    { "O", TCC_OPTION_O, TCC_OPTION_HAS_ARG | TCC_OPTION_NOSEP },
#اگر_تعریف_شدہ TCC_ہدف_ARM
    { "mfloat-abi", TCC_OPTION_mfloat_abi, TCC_OPTION_HAS_ARG },
#اگر_ختم
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
#اگر_تعریف_شدہ TCC_ہدف_PE
    { "impdef", TCC_OPTION_impdef, 0},
#اگر_ختم
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
    { تہی, 0, 0 },
};

قسمتعریف ساخت FlagDef {
    uint16_t انحراف;
    uint16_t flags;
    ثابت حرف *name;
} FlagDef;

#تعریف_کرو WD_ALL    0x0001 /* warning is activated when using -Wall */
#تعریف_کرو FD_INVERT 0x0002 /* invert value before storing */

ساکن ثابت FlagDef options_W[] = {
    { offsetof(TCCState, warn_all), WD_ALL, "all" },
    { offsetof(TCCState, warn_error), 0, "error" },
    { offsetof(TCCState, warn_write_لڑیاں), 0, "write-strings" },
    { offsetof(TCCState, warn_unsupported), 0, "unsupported" },
    { offsetof(TCCState, warn_implicit_function_declaration), WD_ALL, "implicit-function-declaration" },
    { offsetof(TCCState, warn_discarded_qualifiers), WD_ALL, "discarded-qualifiers" },
    { 0, 0, تہی }
};

ساکن ثابت FlagDef options_f[] = {
    { offsetof(TCCState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(TCCState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(TCCState, nocommon), FD_INVERT, "common" },
    { offsetof(TCCState, leading_underscore), 0, "leading-underscore" },
    { offsetof(TCCState, ms_extensions), 0, "ms-extensions" },
    { offsetof(TCCState, dollars_اندر_identifiers), 0, "dollars-in-identifiers" },
    { offsetof(TCCState, test_coverage), 0, "test-coverage" },
    { offsetof(TCCState, الٹ_funcargs), 0, "reverse-funcargs" },
    { offsetof(TCCState, gnu89_inline), 0, "gnu89-inline" },
    { offsetof(TCCState, unwind_tables), 0, "asynchronous-unwind-tables" },
    { 0, 0, تہی }
};

ساکن ثابت FlagDef options_m[] = {
    { offsetof(TCCState, ms_bitfields), 0, "ms-bitfields" },
#اگر_تعریف_شدہ TCC_ہدف_X86_64
    { offsetof(TCCState, nosse), FD_INVERT, "sse" },
#اگر_ختم
    { 0, 0, تہی }
};

ساکن صحیح سیٹ_flag(TCCState *s, ثابت FlagDef *flags, ثابت حرف *name)
{
    صحیح قدر, نقاب, ret;
    ثابت FlagDef *p;
    ثابت حرف *r;
    غیرعلامتی حرف *f;

    r = name, قدر = !strstart("no-", &r), نقاب = 0;

    /* when called with options_W, look for -W[no-]error=<option> */
    اگر ((flags->flags & WD_ALL) && strstart("error=", &r))
        قدر = قدر ? WARN_ON|WARN_ERR : WARN_NOE, نقاب = WARN_ON;

    برائے (ret = -1, p = flags; p->name; ++p) {
        اگر (ret) {
            اگر (strcmp(r, p->name))
                جاری;
        } ورنہ {
            اگر (0 == (p->flags & WD_ALL))
                جاری;
        }

        f = (غیرعلامتی حرف *)s + p->انحراف;
        *f = (*f & نقاب) | (قدر ^ !!(p->flags & FD_INVERT));

        اگر (ret) {
            ret = 0;
            اگر (strcmp(r, "all"))
                توڑو;
        }
    }
    واپس ret;
}

ساکن ثابت حرف dumpmachine_str[] =
/* this is a best guess, please refine as necessary */
#اگر_تعریف_شدہ TCC_ہدف_I386
    "i386-pc"
#وگرنہ_اگر defined TCC_ہدف_X86_64
    "x86_64-pc"
#وگرنہ_اگر defined TCC_ہدف_C67
    "c67"
#وگرنہ_اگر defined TCC_ہدف_ARM
    "arm"
#وگرنہ_اگر defined TCC_ہدف_ARM64
    "aarch64"
#وگرنہ_اگر defined TCC_ہدف_RISCV64
    "riscv64"
#اگر_ختم
    "-"
#اگر_تعریف_شدہ TCC_ہدف_PE
    "mingw32"
#وگرنہ_اگر defined(TCC_ہدف_MACHO)
    "apple-darwin"
#وگرنہ_اگر TARGETOS_FreeBSD || TARGETOS_FreeBSD_kernel
    "freebsd"
#وگرنہ_اگر TARGETOS_OpenBSD
    "openbsd"
#وگرنہ_اگر TARGETOS_NetBSD
    "netbsd"
#وگرنہ_اگر CONFIG_TCC_MUSL
    "linux-musl"
#ورنہ
    "linux-gnu"
#اگر_ختم
;

#اگر defined TCC_ہدف_MACHO
ساکن uint32_t parse_نسخہ(TCCState *s1, ثابت حرف *نسخہ)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t c = 0;
    حرف* آخری;

    a = strtoul(نسخہ, &آخری, 10);
    اگر (*آخری == '.') {
        b = strtoul(&آخری[1], &آخری, 10);
        اگر (*آخری == '.')
             c = strtoul(&آخری[1], &آخری, 10);
    }
    اگر (*آخری || a > 0xffff || b > 0xff || c > 0xff)
        tcc_error_noabort("version a.b.c not correct: %s", نسخہ);
    واپس (a << 16) | (b << 8) | c;
}
#اگر_ختم

/* insert args from 'p' (separated by sep or ' ') into argv at position 'optind' */
ساکن خالی داخل_کرو_دلائل(TCCState *s1, حرف ***pargv, صحیح *pargc, صحیح optind, ثابت حرف *p, صحیح sep)
{
    صحیح argc = 0;
    حرف **argv = تہی;
    صحیح i;
    برائے (i = 0; i < *pargc; ++i)
        اگر (i == optind)
            dynarray_بانٹو(&argv, &argc, p, sep);
        ورنہ
            dynarray_جوڑو(&argv, &argc, tcc_strdup((*pargv)[i]));
    dynarray_reset(&s1->argv, &s1->argc);
    *pargc = s1->argc = argc;
    *pargv = s1->argv = argv;
}

ساکن خالی دلائل_parser_جوڑو_file(TCCState *s, ثابت حرف* filename, صحیح filetype)
{
    ساخت filespec *f = tcc_malloc(حجم *f + لڑی_لمبائی(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_جوڑو(&s->files, &s->nb_files, f);
    اگر (filetype & AFF_TYPE_LIB)
        ++s->nb_libraries;
}

/* using * to argc/argv to let "tcc -ar" benefit from @listfile expansion */
PUB_FUNC صحیح tcc_parse_دلائل(TCCState *s, صحیح *pargc, حرف ***pargv)
{
    TCCState *s1 = s;
    ثابت TCCOption *popt;
    ثابت حرف *optarg, *r;
    ثابت حرف *تسلسل = تہی;
    صحیح optind = 1, خالی_خانے = 1, x;
    حرف **argv = *pargv;
    صحیح argc = *pargc;

    s->link_optind = s->link_argc;

    جب (optind < argc) {
        r = argv[optind];
        اگر (r[0] == '@' && r[1] != '\0') { /* read @listfile */
            صحیح fd; حرف *p;
            fd = open(++r, O_RDONLY | O_ثنائی_2);
            اگر (fd < 0)
                واپس tcc_error_noabort("listfile '%s' not found", r);
            p = tcc_بھرو_متن(fd);
            داخل_کرو_دلائل(s1, &argv, &argc, optind, p, 0);
            close(fd), tcc_free(p);
            جاری;
        }
        optind++;
        اگر (r[0] != '-' || r[1] == '\0') { /* file or '-' (stdin) */
            دلائل_parser_جوڑو_file(s, r, s->filetype);
            خالی_خانے = 0;
        dorun:
            اگر (تسلسل)
                توڑو;
            جاری;
        }
        /* Also allow "tcc <files...> -run -- <args...>" */
        اگر (r[1] == '-' && r[2] == '\0')
            جاؤ dorun;

        /* find option in table */
        برائے(popt = tcc_options; ; ++popt) {
            ثابت حرف *p1 = popt->name;
            ثابت حرف *r1 = r + 1;
            اگر (p1 == تہی)
                واپس tcc_error_noabort("invalid option -- '%s'", r);
            اگر (!strstart(p1, &r1))
                جاری;
            optarg = r1;
            اگر (popt->flags & TCC_OPTION_HAS_ARG) {
                اگر (*r1 == '\0' && !(popt->flags & TCC_OPTION_NOSEP)) {
                    اگر (optind >= argc)
                        واپس tcc_error_noabort("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } ورنہ اگر (*r1 != '\0')
                جاری;
            توڑو;
        }

        انتخاب(popt->اشاریہ) {
        حالت TCC_OPTION_I:
            tcc_جوڑو_include_راستہ(s, optarg);
            توڑو;
        حالت TCC_OPTION_D:
            tcc_define_علامت(s, optarg, تہی);
            توڑو;
        حالت TCC_OPTION_U:
            tcc_undefine_علامت(s, optarg);
            توڑو;
        حالت TCC_OPTION_L:
            tcc_جوڑو_library_راستہ(s, optarg);
            توڑو;
        حالت TCC_OPTION_B:
            /* set tcc utilities path (mainly for tcc development) */
            tcc_سیٹ_lib_راستہ(s, optarg);
            جاری;
        حالت TCC_OPTION_l:
            دلائل_parser_جوڑو_file(s, optarg, AFF_TYPE_LIB | (s->filetype & ~AFF_TYPE_نقاب));
            توڑو;
        حالت TCC_OPTION_pthread:
            s->option_pthread = 1;
            توڑو;
        حالت TCC_OPTION_bench:
            s->do_bench = 1;
            توڑو;
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
        حالت TCC_OPTION_bt:
            s->rt_عدد_callers = atoi(optarg); /* zero = default (6) */
            جاؤ enable_backtrace;
        enable_backtrace:
            s->do_backtrace = 1;
            اگر (0 == s->do_debug)
                s->do_debug = 1;
	    s->dwarf = CONFIG_DWARF_نسخہ;
            توڑو;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        حالت TCC_OPTION_b:
            s->do_bounds_check = 1;
            جاؤ enable_backtrace;
#اگر_ختم
#اگر_ختم
        حالت TCC_OPTION_g:
            s->do_debug = 2;
            s->dwarf = CONFIG_DWARF_نسخہ;
        g_redo:
            اگر (strstart("dwarf", &optarg)) {
                s->dwarf = (*optarg) ? (0 - atoi(optarg)) : DEFAULT_DWARF_نسخہ;
            } ورنہ اگر (0 == strcmp("stabs", optarg)) {
                s->dwarf = 0;
            } ورنہ اگر (isnum(*optarg)) {
                x = *optarg++ - '0';
                /* -g0 = no info, -g1 = lines/functions only, -g2 = full info */
                s->do_debug = x > 2 ? 2 : x == 0 && s->do_backtrace ? 1 : x;
                جاؤ g_redo;
#اگر_تعریف_شدہ TCC_ہدف_PE
            } ورنہ اگر (0 == strcmp(".pdb", optarg)) {
                s->dwarf = 5, s->do_debug |= 16;
#اگر_ختم
            }
            توڑو;
        حالت TCC_OPTION_c:
            x = TCC_OUTPUT_OBJ;
        سیٹ_output_type:
            اگر (s->output_type)
                tcc_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            توڑو;
        حالت TCC_OPTION_d:
            اگر (*optarg == 'D')
                s->dflag = 3;
            ورنہ اگر (*optarg == 'M')
                s->dflag = 7;
            ورنہ اگر (*optarg == 't')
                s->dflag = 16;
            ورنہ اگر (isnum(*optarg))
                g_debug |= atoi(optarg);
            ورنہ
                جاؤ unsupported_option;
            توڑو;
        حالت TCC_OPTION_static:
            s->static_link = 1;
            توڑو;
        حالت TCC_OPTION_std:
            اگر (strcmp(optarg, "=c11") == 0 || strcmp(optarg, "=gnu11") == 0)
                s->cversion = 201112;
            توڑو;
        حالت TCC_OPTION_shared:
            x = TCC_OUTPUT_DLL;
            جاؤ سیٹ_output_type;
        حالت TCC_OPTION_soname:
            tcc_سیٹ_str(&s->soname, optarg);
            توڑو;
        حالت TCC_OPTION_o:
            اگر (s->outfile) {
                tcc_warning("multiple -o option");
            }
            tcc_سیٹ_str(&s->outfile, optarg);
            توڑو;
        حالت TCC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = TCC_OUTPUT_OBJ;
            جاؤ سیٹ_output_type;
        حالت TCC_OPTION_isystem:
            tcc_جوڑو_sysinclude_راستہ(s, optarg);
            توڑو;
        حالت TCC_OPTION_include:
            cstr_printf(&s->cmdline_incl, "#include \"%s\"\n", optarg);
            توڑو;
        حالت TCC_OPTION_nostdinc:
            s->nostdinc = 1;
            توڑو;
        حالت TCC_OPTION_nostdlib:
            s->nostdlib = 1;
            توڑو;
        حالت TCC_OPTION_تسلسل:
#اگر_تعریف_شدہ TCC_IS_NATIVE
            /* When from script "#!/usr/bin/tcc -run <options>",
               argv[1] is "-run <options>" and argv[2] is <script-name> */
            تسلسل = optarg;
            x = TCC_OUTPUT_حافظہ;
            جاؤ سیٹ_output_type;
#ورنہ
            واپس tcc_error_noabort("-run is not available in a cross compiler");
#اگر_ختم
#اگر_تعریف_شدہ TCC_IS_NATIVE
        حالت TCC_OPTION_rstdin:
            /* custom stdin for run_main */
            s->تسلسل_stdin = optarg;
            توڑو;
#اگر_ختم
        حالت TCC_OPTION_v:
            کرو ++s->verbose; جب (*optarg++ == 'v');
            جاری;
        حالت TCC_OPTION_f:
            اگر (سیٹ_flag(s, options_f, optarg) < 0)
                جاؤ unsupported_option;
            توڑو;
#اگر_تعریف_شدہ TCC_ہدف_ARM
        حالت TCC_OPTION_mfloat_abi:
            /* tcc doesn't support soft float yet */
            اگر (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
            } ورنہ اگر (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            ورنہ
                واپس tcc_error_noabort("unsupported float abi '%s'", optarg);
            جاری;
#اگر_ختم
        حالت TCC_OPTION_m:
            اگر (سیٹ_flag(s, options_m, optarg) < 0) {
                اگر (x = atoi(optarg), x != 32 && x != 64)
                    جاؤ unsupported_option;
                اگر (PTR_سائز != x/8)
                    واپس x;
                جاری;
            }
            توڑو;
        حالت TCC_OPTION_W:
            اگر (optarg[0] && سیٹ_flag(s, options_W, optarg) < 0)
                جاؤ unsupported_option;
            توڑو;
        حالت TCC_OPTION_w:
            s->warn_none = 1;
            توڑو;
        حالت TCC_OPTION_rdynamic:
            s->rdynamic = 1;
            توڑو;
        حالت TCC_OPTION_Wl:
            اگر (tcc_سیٹ_linker(s, optarg) < 0)
                واپس -1;
            توڑو;
        حالت TCC_OPTION_Wp:
            اگر (argv[0]) /* not with tcc_set_options() */
                داخل_کرو_دلائل(s, &argv, &argc, --optind, optarg, ',');
            توڑو;
        حالت TCC_OPTION_E:
            x = TCC_OUTPUT_PREPROCESS;
            جاؤ سیٹ_output_type;
        حالت TCC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            توڑو;

        حالت TCC_OPTION_M:
            s->include_sys_deps = 1;
            // fall through
        حالت TCC_OPTION_MM:
            s->just_deps = 1;
            s->gen_deps = 1;
            اگر (!s->deps_outfile)
                tcc_سیٹ_str(&s->deps_outfile, "-");
            توڑو;
        حالت TCC_OPTION_MD:
            s->include_sys_deps = 1;
            // fall through
        حالت TCC_OPTION_MMD:
            s->gen_deps = 1;
            /* usually, only "-MMD" is used */
            /* but the Linux Kernel uses "-MMD,depfile" */
            اگر (*optarg != ',')
                توڑو;
            ++optarg;
            // fall through
        حالت TCC_OPTION_MF:
            tcc_سیٹ_str(&s->deps_outfile, optarg);
            توڑو;
        حالت TCC_OPTION_MP:
            s->gen_phony_deps = 1;
            توڑو;

        حالت TCC_OPTION_dumpmachine:
            لکھو("%s\n", dumpmachine_str);
            باہر_نکلو(0);
        حالت TCC_OPTION_dumpversion:
            لکھو ("%s\n", TCC_نسخہ);
            باہر_نکلو(0);

        حالت TCC_OPTION_x:
            x = 0;
            اگر (*optarg == 'c')
                x = AFF_TYPE_C;
            ورنہ اگر (*optarg == 'a')
                x = AFF_TYPE_ASMPP;
            ورنہ اگر (*optarg == 'b')
                x = AFF_TYPE_BIN;
            ورنہ اگر (*optarg == 'n')
                x = AFF_TYPE_NONE;
            ورنہ
                tcc_warning("unsupported language '%s'", optarg);
            s->filetype = x | (s->filetype & ~AFF_TYPE_نقاب);
            توڑو;
        حالت TCC_OPTION_O:
            s->optimize = isnum(optarg[0]) ? optarg[0]-'0' : 1 /* -O -Os */;
            توڑو;
#اگر defined TCC_ہدف_MACHO
        حالت TCC_OPTION_dynamiclib:
            x = TCC_OUTPUT_DLL;
            جاؤ سیٹ_output_type;
        حالت TCC_OPTION_flat_namespace:
	     توڑو;
        حالت TCC_OPTION_two_levelnamespace:
	     توڑو;
        حالت TCC_OPTION_undefined:
	     توڑو;
        حالت TCC_OPTION_install_name:
	    tcc_سیٹ_str(&s->install_name, optarg);
            توڑو;
        حالت TCC_OPTION_compatibility_نسخہ:
	    s->compatibility_نسخہ = parse_نسخہ(s, optarg);
            توڑو;
        حالت TCC_OPTION_current_نسخہ:
	    s->current_نسخہ = parse_نسخہ(s, optarg);;
            توڑو;
#اگر_ختم
        حالت TCC_OPTION_HELP:
            x = OPT_HELP;
            جاؤ extra_action;
        حالت TCC_OPTION_HELP2:
            x = OPT_HELP2;
            جاؤ extra_action;
        حالت TCC_OPTION_print_تلاش_dirs:
            x = OPT_PRINT_DIRS;
            جاؤ extra_action;
        حالت TCC_OPTION_impdef:
            x = OPT_IMPDEF;
            جاؤ extra_action;
        حالت TCC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            اگر (تہی == argv[0]) /* from tcc_set_options() */
                واپس -1;
            اگر (!خالی_خانے && x)
                واپس tcc_error_noabort("cannot parse %s here", r);
            --optind;
            *pargc = argc - optind;
            *pargv = argv + optind;
            واپس x;
        طےشدہ:
unsupported_option:
            tcc_warning_c(warn_unsupported)("unsupported option '%s'", r);
            توڑو;
        }
        خالی_خانے = 0;
    }
    اگر (s->link_optind < s->link_argc)
        واپس tcc_error_noabort("argument to '-Wl,%s' is missing", s->link_argv[s->link_optind]);
    اگر (تسلسل) {
        اگر (*تسلسل && tcc_سیٹ_options(s, تسلسل) < 0)
            واپس -1;
        x = 0, r = 0;
        جاؤ extra_action;
    }
    اگر (!خالی_خانے)
        واپس 0;
    اگر (s->verbose == 2)
        واپس OPT_PRINT_DIRS;
    اگر (s->verbose)
        واپس OPT_V;
    واپس OPT_HELP;
}

LIBTCCAPI صحیح tcc_سیٹ_options(TCCState *s, ثابت حرف *r)
{
    حرف **argv = تہی;
    صحیح argc = 0, ret;
    dynarray_جوڑو(&argv, &argc, 0);
    dynarray_بانٹو(&argv, &argc, r, 0);
    ret = tcc_parse_دلائل(s, &argc, &argv);
    dynarray_reset(&argv, &argc);
    واپس ret;
}

PUB_FUNC خالی tcc_print_stats(TCCState *s1, غیرعلامتی کل_وقت)
{
    اگر (!کل_وقت)
        کل_وقت = 1;
    fprintf(stderr, "# %d idents, %d lines, %u bytes\n"
                    "# %0.3f s, %u lines/s, %0.1f MB/s\n",
           کل_idents, کل_سطریں, کل_بائٹیں,
           (دوہرا)کل_وقت/1000,
           (غیرعلامتی)کل_سطریں*1000/کل_وقت,
           (دوہرا)کل_بائٹیں/1000/کل_وقت);
    fprintf(stderr, "# text %u, data.rw %u, data.ro %u, bss %u bytes\n",
           s1->کل_output[0],
           s1->کل_output[1],
           s1->کل_output[2],
           s1->کل_output[3]
           );
#اگر_تعریف_شدہ MEM_DEBUG
    fprintf(stderr, "# memory usage");
#اگر_تعریف_شدہ TCC_IS_NATIVE
    اگر (s1->تسلسل_سائز) {
        Section *s = s1->symtab;
        غیرعلامتی ms = s->ڈیٹا_انحراف + s->link->ڈیٹا_انحراف + s->hash->ڈیٹا_انحراف;
        غیرعلامتی rs = s1->تسلسل_سائز;
        fprintf(stderr, ": %d to run, %d symbols, %d other,",
            rs, ms, mem_cur_سائز - rs - ms);
    }
#اگر_ختم
    fprintf(stderr, " %d max (bytes)\n", mem_max_سائز);
#اگر_ختم
}
