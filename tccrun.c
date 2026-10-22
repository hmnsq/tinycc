/*
 *  TCC - Tiny C Compiler - Support for -run switch
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

#شامل "tcc.h"

/* only native compiler supports -run */
#اگر_تعریف_شدہ TCC_IS_NATIVE

#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
/* runtime debug info block */
قسمتعریف ساخت rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اتحاد {
	ساخت {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_انتہا;
	    حرف *stab_str;
	};
	ساخت {
	    غیرعلامتی حرف *dwarf_سطر;
	    غیرعلامتی حرف *dwarf_سطر_انتہا;
	    غیرعلامتی حرف *dwarf_سطر_str;
	};
    };
    ElfW(Sym) *esym_آغاز;
    ElfW(Sym) *esym_انتہا;
    حرف *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_بنیاد;
    خالی *bounds_آغاز;
    خالی *چوٹی_func;
    ساخت rt_context *اگلا;
    // 10 * PTR_SIZE
    صحیح عدد_callers;
    صحیح dwarf;
} rt_context;

/* linked list of rt_contexts */
ساکن rt_context *g_rc;
ساکن صحیح signal_سیٹ;
ساکن خالی سیٹ_exception_handler(خالی);
#اگر_ختم /* def CONFIG_TCC_BACKTRACE */

قسمتعریف ساخت rt_چوکھٹا {
    addr_t ip, fp, sp;
} rt_چوکھٹا;

ساکن TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ساکن rt_sem);
ساکن خالی rt_wait_sem(خالی) { WAIT_SEM(&rt_sem); }
ساکن خالی rt_post_sem(خالی) { POST_SEM(&rt_sem); }
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *f, صحیح level);
ساکن خالی rt_exit(rt_چوکھٹا *f, صحیح رمز);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_BACKTRACE_ONLY

#اگر_غیر_تعریف_شدہ _WIN32
# include <sys/mman.h>
#اگر_ختم

ساکن صحیح protect_صفحات(خالی *ptr, غیرعلامتی طویل لمبائی, صحیح منوال);
ساکن صحیح tcc_relocate_ex(TCCState *s1, خالی *ptr, غیرعلامتی ptr_diff);
ساکن خالی st_link(TCCState *s1);
ساکن خالی st_unlink(TCCState *s1);
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
ساکن صحیح _tcc_backtrace(rt_چوکھٹا *f, ثابت حرف *fmt, va_list ap);
#اگر_ختم
#اگر_تعریف_شدہ _WIN64
ساکن خالی *win64_جوڑو_function_جدول(TCCState *s1);
ساکن خالی win64_del_function_جدول(خالی *);
#اگر_ختم

#اگر !defined PAGESIZE
# اگر defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ورنہ
#  define PAGESIZE 4096
# endif
#اگر_ختم

#تعریف_کرو PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#اگر !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#اگر_ختم

/* use VirtualAlloc() instead of tcc_malloc() */
#اگر defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#اگر_ختم

ساکن صحیح rt_mem(TCCState *s1, صحیح سائز)
{
    خالی *ptr;
    صحیح ptr_diff = 0;
#اگر_تعریف_شدہ CONFIG_SELINUX
    /* Using mmap instead of malloc */
    خالی *prw;
    حرف tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحیح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, سائز);

    ptr = mmap(تہی, سائز * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((حرف*)ptr + سائز, سائز, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    اگر (ptr == MAP_FAILED || prw == MAP_FAILED)
	واپس tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (حرف*)prw - (حرف*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    سائز *= 2;
#وگرنہ_اگر CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(تہی, سائز, MEM_RESERVE | MEM_COMMIT, صفحہ_READWRITE);
    اگر (!ptr)
        واپس tcc_error_noabort("tccrun: could not allocate memory");
#ورنہ
    ptr = tcc_malloc(سائز += PAGESIZE); /* one extra page to align malloc memory */
#اگر_ختم
    s1->تسلسل_ptr = ptr;
    s1->تسلسل_سائز = سائز;
    واپس ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحیح tcc_relocate(TCCState *s1)
{
    صحیح سائز, ret, ptr_diff;

    اگر (s1->تسلسل_ptr)
        باہر_نکلو(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace)
        tcc_جوڑو_علامت(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#اگر_ختم
    سائز = tcc_relocate_ex(s1, تہی, 0);
    اگر (سائز < 0)
        واپس -1;
    ptr_diff = rt_mem(s1, سائز);
    اگر (ptr_diff < 0)
        واپس -1;
    ret = tcc_relocate_ex(s1, s1->تسلسل_ptr, ptr_diff);
    اگر (ret == 0)
        st_link(s1);
    واپس ret;
}

ST_FUNC خالی tcc_تسلسل_free(TCCState *s1)
{
    غیرعلامتی سائز;
    خالی *ptr;
    صحیح i;

    /* free any loaded DLLs */
    برائے ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        اگر ( ref->handle )
#اگر_تعریف_شدہ _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ورنہ
            dlclose(ref->handle);
#اگر_ختم
    }
    /* unmap or unprotect and free memory */
    ptr = s1->تسلسل_ptr;
    اگر (تہی == ptr)
        واپس;
    st_unlink(s1);
#اگر_تعریف_شدہ _WIN64
    win64_del_function_جدول(s1->تسلسل_function_جدول);
#اگر_ختم
    سائز = s1->تسلسل_سائز;
#اگر_تعریف_شدہ CONFIG_SELINUX
    munmap(ptr, سائز);
#وگرنہ_اگر CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, سائز, MEM_RELEASE);
#ورنہ
    /* unprotect memory to make it usable for malloc again */
    protect_صفحات((خالی*)PAGEALIGN(ptr), سائز - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#اگر_ختم
}

#تعریف_کرو RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحیح tcc_تسلسل(TCCState *s1, صحیح argc, حرف **argv)
{
    صحیح (*prog_main)(صحیح, حرف **, حرف **), ret;
    ثابت حرف *چوٹی_sym;
    jmp_buf main_jb;

#اگر defined(__APPLE__)
    خارجی حرف ***_NSGetEnviron(خالی);
    حرف **envp = *_NSGetEnviron();
#وگرنہ_اگر defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    خارجی حرف **environ;
    حرف **envp = environ;
#ورنہ
    حرف **envp = environ;
#اگر_ختم

    /* tcc -dt -run ... nothing to do if no main() */
    اگر ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        واپس 0;

    tcc_جوڑو_علامت(s1, "__rt_exit", rt_exit);
    s1->تسلسل_main = "_runmain", چوٹی_sym = "main";
    اگر (s1->elf_entryname)
        s1->تسلسل_main = چوٹی_sym = s1->elf_entryname;
    tcc_جوڑو_support(s1, "runmain.o");

    اگر (tcc_relocate(s1) < 0)
        واپس -1;

    prog_main = (خالی*)get_sym_addr(s1, s1->تسلسل_main, 1, 1);
    اگر ((addr_t)-1 == (addr_t)prog_main)
        واپس -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    اگر (s1->تسلسل_stdin && !freopen(s1->تسلسل_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->تسلسل_stdin);
        واپس -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_علامت(s1, چوٹی_sym));
    اگر (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ورنہ اگر (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    اگر (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    واپس ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ساکن خالی cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    صحیح sym_اشاریہ, انتہا_sym = s->ڈیٹا_انحراف / حجم (ElfSym);
    /* reset symtab */
    s->ڈیٹا_انحراف = s->link->ڈیٹا_انحراف = s->hash->ڈیٹا_انحراف = 0;
    init_symtab(s);
    /* add global symbols again */
    برائے (sym_اشاریہ = 1; sym_اشاریہ < انتہا_sym; ++sym_اشاریہ) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->ڈیٹا)[sym_اشاریہ];
        ثابت حرف *name = (حرف *)s->link->ڈیٹا + sym->st_name;
        اگر (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            جاری;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_قدر, sym->st_سائز, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ساکن خالی cleanup_sections(TCCState *s1)
{
    ساخت { Section **secs; صحیح nb_secs; } *p = (خالی*)&s1->sections;
    صحیح i, f = 2;
    کرو {
        برائے (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            اگر (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->ڈیٹا = tcc_realloc(s->ڈیٹا, s->ڈیٹا_allocated = s->ڈیٹا_انحراف);
            } ورنہ {
                free_section(s), tcc_free(s), p->secs[i] = تہی;
            }
        }
    } جب (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#اگر_غیر_تعریف_شدہ CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# ورنہ
#   define CONFIG_RUNMEM_RO 0
#  endif
#اگر_ختم

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ساکن صحیح tcc_relocate_ex(TCCState *s1, خالی *ptr, غیرعلامتی ptr_diff)
{
    Section *s;
    غیرعلامتی انحراف, لمبائی, align, i, k, f;
    غیرعلامتی n, copy;
    addr_t mem, addr;

    اگر (تہی == ptr) {
        s1->nb_errors = 0;
#اگر_تعریف_شدہ TCC_ہدف_PE
        pe_output_file(s1, تہی);
#ورنہ
        tcc_جوڑو_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#اگر_ختم
    }

    انحراف = copy = 0;
    mem = (addr_t)ptr;
redo:
    اگر (s1->verbose == 2 && copy)
        لکھو(&"-----------------------------------------------------\n"[PTR_سائز*2 - 8]);
    اگر (s1->nb_errors)
        واپس -1;
    اگر (copy == 3)
        واپس 0;

    برائے (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        برائے(i = 1; i < s1->nb_sections; i++) {
            ساکن ثابت حرف shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            اگر (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                جاری;
            لمبائی = s->ڈیٹا_انحراف;
            اگر (copy == 2) {
                اگر (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + لمبائی;
                جاری;
            }
            اگر (copy) { /* final step: copy section data to memory */
                اگر (s1->verbose == 2)
                    لکھو("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (خالی*)s->sh_addr, لمبائی, s->sh_addralign);
                ptr = (خالی*)s->sh_addr;
                اگر (k == 0)
                    ptr = (خالی*)(s->sh_addr + ptr_diff);
                اگر (تہی == s->ڈیٹا || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, لمبائی);
                ورنہ
                    حافظہ_نقل(ptr, s->ڈیٹا, لمبائی);
                جاری;
            }

            اگر ((s->sh_flags & SHF_TLS) && لمبائی)
                واپس tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            اگر (++n == 1) {
#اگر defined TCC_ہدف_I386 || defined TCC_ہدف_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                اگر (align < 64)
                    align = 64;
#اگر_ختم
                /* start new page for different permissions */
                اگر (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            انحراف += -(addr + انحراف) & (align - 1);
            s->sh_addr = mem ? addr + انحراف : 0;
            انحراف += لمبائی;
        }
        اگر (copy == 2) { /* set permissions */
            اگر (n == 0) /* no data  */
                جاری;
#اگر_تعریف_شدہ CONFIG_SELINUX
            اگر (k == 0) /* SHF_EXECINSTR has its own mapping */
                جاری;
#اگر_ختم
            f = k;
            اگر (f >= CONFIG_RUNMEM_RO) {
                اگر (f != 0)
                    جاری;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            اگر (s1->verbose == 2) {
                لکھو("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (خالی*)addr, (غیرعلامتی)n);
            }
            اگر (protect_صفحات((خالی*)addr, n, f) < 0)
                واپس tcc_error_noabort(
#اگر_تعریف_شدہ _WIN32
                    "VirtualProtect failed");
#ورنہ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#اگر_ختم
        }
    }

    اگر (0 == mem)
        واپس PAGEALIGN(انحراف);

    اگر (++copy == 2) {
        جاؤ redo;
    }
    اگر (copy == 3) {
#اگر_تعریف_شدہ _WIN64
        s1->تسلسل_function_جدول = win64_جوڑو_function_جدول(s1);
#اگر_ختم
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        جاؤ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    اگر (s1->nb_errors)
        جاؤ redo;
    /* relocate sections */
#اگر_تعریف_شدہ TCC_ہدف_PE
    s1->pe_imagebase = mem;
#ورنہ
    relocate_plt(s1);
#اگر_ختم
    relocate_sections(s1);
    جاؤ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ساکن صحیح protect_صفحات(خالی *ptr, غیرعلامتی طویل لمبائی, صحیح منوال)
{
#اگر_تعریف_شدہ _WIN32
    ساکن ثابت غیرعلامتی حرف protect[] = {
        صفحہ_EXECUTE_READ,
        صفحہ_READONLY,
        صفحہ_READWRITE,
        صفحہ_EXECUTE_READWRITE
        };
    DWORD old;
    اگر (!VirtualProtect(ptr, لمبائی, protect[منوال], &old))
        واپس -1;
#ورنہ
    ساکن ثابت غیرعلامتی حرف protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    اگر (mprotect(ptr, لمبائی, protect[منوال]))
        واپس -1;
#اگر_ختم
/* XXX: BSD sometimes dump core with bad system call */
#اگر (defined TCC_ہدف_ARM && !TARGETOS_BSD) \
    || defined TCC_ہدف_ARM64 || defined TCC_ہدف_RISCV64
    اگر (منوال == 0 || منوال == 3) {
#اگر_تعریف_شدہ _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, لمبائی);
#ورنہ
        خالی __clear_cache(خالی *beginning, خالی *انتہا);
        __clear_cache(ptr, (حرف *)ptr + لمبائی);
#اگر_ختم
    }
#اگر_ختم
    واپس 0;
}

#اگر_تعریف_شدہ _WIN64
ساکن خالی *win64_جوڑو_function_جدول(TCCState *s1)
{
    خالی *p = تہی;
    اگر (s1->uw_pdata) {
        p = (خالی*)s1->uw_pdata->sh_addr;
        Rtl_جوڑو_Function_جدول(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->ڈیٹا_انحراف / حجم (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = تہی;
    }
    واپس p;
}

ساکن خالی win64_del_function_جدول(خالی *p)
{
    اگر (p) {
        Rtl_Delete_Function_جدول((RUNTIME_FUNCTION*)p);
    }
}
#اگر_ختم

ساکن خالی bt_link(TCCState *s1)
{
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    rt_context *rc;
    اگر (!s1->do_backtrace)
        واپس;
    rc = tcc_get_علامت(s1, "__rt_info");
    اگر (!rc)
        واپس;
    rc->esym_آغاز = (ElfW(Sym) *)(symtab_section->ڈیٹا);
    rc->esym_انتہا = (ElfW(Sym) *)(symtab_section->ڈیٹا + symtab_section->ڈیٹا_انحراف);
    rc->elf_str = (حرف *)symtab_section->link->ڈیٹا;
    اگر (PTR_سائز == 8 && !s1->dwarf)
        rc->prog_بنیاد &= 0xffffffff00000000ULL;
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
    اگر (s1->do_bounds_check) {
        خالی *p;
        اگر ((p = tcc_get_علامت(s1, "__bound_init")))
            ((خالی(*)(خالی*,صحیح))p)(rc->bounds_آغاز, 1);
    }
#اگر_ختم
    rc->اگلا = g_rc, g_rc = rc, s1->rc = rc;
    اگر (0 == signal_سیٹ)
        سیٹ_exception_handler(), signal_سیٹ = 1;
#اگر_ختم
}

ساکن خالی st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->اگلا = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ساکن خالی ptr_unlink(خالی *list, خالی *e, غیرعلامتی اگلا)
{
    خالی **pp, **nn, *p;
    برائے (pp = list; !!(p = *pp); pp = nn) {
        nn = (خالی*)((حرف*)p + اگلا); /* nn = &p->next; */
        اگر (p == e) {
            *pp = *nn;
            توڑو;
        }
    }
}

ساکن خالی st_unlink(TCCState *s1)
{
    rt_wait_sem();
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, اگلا));
#اگر_ختم
    ptr_unlink(&g_s1, s1, offsetof(TCCState, اگلا));
    rt_post_sem();
}

LIBTCCAPI خالی *_tcc_setjmp(TCCState *s1, خالی *p_jmp_buf, خالی *func, خالی *p_longjmp)
{
    s1->تسلسل_lj = p_longjmp;
    s1->تسلسل_jb = p_jmp_buf;
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE
    اگر (s1->rc)
        s1->rc->چوٹی_func = func;
#اگر_ختم
    واپس p_jmp_buf;
}

LIBTCCAPI خالی tcc_سیٹ_backtrace_func(TCCState *s1, خالی *ڈیٹا, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_ڈیٹا = ڈیٹا;
}

ساکن TCCState *rt_ڈھونڈو_state(rt_چوکھٹا *f)
{
    TCCState *s;
    صحیح level;
    addr_t pc;

    s = g_s1;
    اگر (تہی == s || تہی == s->اگلا) {
        /* play it safe in the simple case when there is only one state */
        واپس s;
    }
    برائے (level = 0; level < 8; ++level) {
        اگر (rt_get_caller_pc(&pc, f, level) < 0)
            توڑو;
        برائے (s = g_s1; s; s = s->اگلا) {
            اگر (pc >= (addr_t)s->تسلسل_ptr
             && pc  < (addr_t)s->تسلسل_ptr + s->تسلسل_سائز)
                واپس s;
        }
    }
    واپس تہی;
}

ساکن خالی rt_exit(rt_چوکھٹا *f, صحیح رمز)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_ڈھونڈو_state(f);
    rt_post_sem();
    اگر (s && s->تسلسل_lj) {
#اگر_تعریف_شدہ CONFIG_TCC_BCHECK
        اگر (f->fp) { /* called from signal */
            خالی *p = tcc_get_علامت(s, "__bound_exit");
            اگر (p)
                ((خالی (*)(خالی))p)();
        }
#اگر_ختم
        اگر (رمز == 0)
            رمز = RT_EXIT_ZERO;
        ((خالی(*)(خالی*,صحیح))s->تسلسل_lj)(s->تسلسل_jb, رمز);
    }
    باہر_نکلو(رمز);
}

/* ------------------------------------------------------------- */
#ورنہ // if defined CONFIG_TCC_BACKTRACE_ONLY
ساکن خالی rt_exit(rt_چوکھٹا *f, صحیح رمز)
{
    باہر_نکلو(رمز);
}
#اگر_ختم //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#اگر_تعریف_شدہ CONFIG_TCC_BACKTRACE

ساکن صحیح rt_vprintf(ثابت حرف *fmt, va_list ap)
{
    صحیح ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    واپس ret;
}

ساکن صحیح rt_printf(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحیح r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    واپس r;
}

ساکن حرف *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    برائے (esym = rc->esym_آغاز + 1; esym < rc->esym_انتہا; ++esym) {
        صحیح type = ELFW(ST_TYPE)(esym->st_info);
        اگر ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_قدر
            && wanted_pc < esym->st_قدر + esym->st_سائز) {
            *func_addr = esym->st_قدر;
            واپس rc->elf_str + esym->st_name;
        }
    }
    واپس تہی;
}

قسمتعریف ساخت bt_info
{
    حرف file[100];
    صحیح سطر;
    حرف func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ساکن addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    حرف func_name[128];
    addr_t func_addr, آخری_pc, pc;
    ثابت حرف *incl_files[INCLUDE_ڈھیر_سائز];
    صحیح incl_اشاریہ, آخری_incl_اشاریہ, len, آخری_سطر_عدد, i;
    ثابت حرف *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_اشاریہ = 0;
    آخری_pc = (addr_t)-1;
    آخری_سطر_عدد = 1;
    آخری_incl_اشاریہ = 0;

    برائے (sym = rc->stab_sym + 1; sym < rc->stab_sym_انتہا; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_قدر;

        انتخاب(sym->n_type) {
        حالت N_SLINE:
            اگر (func_addr)
                جاؤ rel_pc;
        حالت N_SO:
        حالت N_SOL:
            جاؤ abs_pc;
        حالت N_FUN:
            اگر (sym->n_strx == 0) /* end of function */
                جاؤ rel_pc;
        abs_pc:
#اگر PTR_سائز == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_بنیاد;
#اگر_ختم
            جاؤ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            اگر (pc >= wanted_pc && wanted_pc >= آخری_pc)
                جاؤ ملا;
            توڑو;
        }

        انتخاب(sym->n_type) {
            /* function start or end */
        حالت N_FUN:
            اگر (sym->n_strx == 0)
                جاؤ reset_func;
            p = strchr(str, ':');
            اگر (0 == p || (len = p - str + 1, len > حجم func_name))
                len = حجم func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            توڑو;
            /* line number info */
        حالت N_SLINE:
            آخری_pc = pc;
            آخری_سطر_عدد = sym->n_desc;
            آخری_incl_اشاریہ = incl_اشاریہ;
            توڑو;
            /* include files */
        حالت N_BINCL:
            اگر (incl_اشاریہ < INCLUDE_ڈھیر_سائز)
                incl_files[incl_اشاریہ++] = str;
            توڑو;
        حالت N_EINCL:
            اگر (incl_اشاریہ > 1)
                incl_اشاریہ--;
            توڑو;
            /* start/end of translation unit */
        حالت N_SO:
            incl_اشاریہ = 0;
            اگر (sym->n_strx) {
                /* do not add path */
                len = لڑی_لمبائی(str);
                اگر (len > 0 && str[len - 1] != '/')
                    incl_files[incl_اشاریہ++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            آخری_pc = (addr_t)-1;
            توڑو;
            /* alternative file name (from #line or #include directives) */
        حالت N_SOL:
            اگر (incl_اشاریہ)
                incl_files[incl_اشاریہ-1] = str;
            توڑو;
        }
    }
    آخری_incl_اشاریہ = 0, func_name[0] = 0, func_addr = 0;
ملا:
    i = آخری_incl_اشاریہ;
    اگر (i > 0) {
        pstrcpy(bi->file, حجم bi->file, incl_files[--i]);
        bi->سطر = آخری_سطر_عدد;
    }
    pstrcpy(bi->func, حجم bi->func, func_name);
    bi->func_pc = func_addr;
    واپس func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#تعریف_کرو DIR_جدول_سائز	(64)
#تعریف_کرو FILE_جدول_سائز	(512)

#تعریف_کرو	dwarf_ignore_type(ln, انتہا) /* timestamp/size/md5/... */ \
	انتخاب (اندراج_format[j].form) { \
	حالت DW_FORM_data1: (ln) += 1; توڑو; \
	حالت DW_FORM_data2: (ln) += 2; توڑو; \
	حالت DW_FORM_data4: (ln) += 3; توڑو; \
	حالت DW_FORM_data8: (ln) += 8; توڑو; \
	حالت DW_FORM_data16: (ln) += 16; توڑو; \
	حالت DW_FORM_udata: dwarf_read_uleb128(&(ln), (انتہا)); توڑو; \
	طےشدہ: جاؤ اگلا_سطر; \
	}

ساکن addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    غیرعلامتی حرف *ln;
    غیرعلامتی حرف *cp;
    غیرعلامتی حرف *انتہا;
    غیرعلامتی حرف *opcode_لمبائی;
    غیرعلامتی طویل طویل سائز;
    غیرعلامتی صحیح لمبائی;
    غیرعلامتی حرف نسخہ;
    غیرعلامتی صحیح min_insn_لمبائی;
    غیرعلامتی صحیح max_ops_فی_insn;
    صحیح سطر_بنیاد;
    غیرعلامتی صحیح سطر_range;
    غیرعلامتی صحیح opcode_بنیاد;
    غیرعلامتی صحیح opindex;
    غیرعلامتی صحیح ستون;
    غیرعلامتی صحیح i;
    غیرعلامتی صحیح j;
    غیرعلامتی صحیح len;
    غیرعلامتی طویل طویل قدر;
    ساخت {
	غیرعلامتی صحیح type;
	غیرعلامتی صحیح form;
    } اندراج_format[256];
    غیرعلامتی صحیح dir_سائز;
#اگر 0
    حرف *dirs[DIR_جدول_سائز];
#اگر_ختم
    غیرعلامتی صحیح filename_سائز;
    ساخت /*dwarf_filename_struct*/ {
        غیرعلامتی صحیح dir_اندراج;
        حرف *name;
    } filename_جدول[FILE_جدول_سائز];
    addr_t آخری_pc;
    addr_t pc;
    addr_t func_addr;
    صحیح سطر;
    حرف *filename;
    حرف *function;

    filename = تہی;
    function = تہی;
    func_addr = 0;
    سطر = 0;

    ln = rc->dwarf_سطر;
    جب (ln < rc->dwarf_سطر_انتہا) {
	dir_سائز = 0;
	filename_سائز = 0;
        آخری_pc = 0;
        pc = 0;
        func_addr = 0;
        سطر = 1;
        filename = تہی;
        function = تہی;
	لمبائی = 4;
	سائز = dwarf_read_4(ln, rc->dwarf_سطر_انتہا);
	اگر (سائز == 0xffffffffu) // dwarf 64
	    لمبائی = 8, سائز = dwarf_read_8(ln, rc->dwarf_سطر_انتہا);
	انتہا = ln + سائز;
	اگر (انتہا < ln || انتہا > rc->dwarf_سطر_انتہا)
	    توڑو;
	نسخہ = dwarf_read_2(ln, انتہا);
	اگر (نسخہ >= 5)
	    ln += لمبائی + 2; // address size, segment selector, prologue Length
	ورنہ
	    ln += لمبائی; // prologue Length
	min_insn_لمبائی = dwarf_read_1(ln, انتہا);
	اگر (نسخہ >= 4)
	    max_ops_فی_insn = dwarf_read_1(ln, انتہا);
	ورنہ
	    max_ops_فی_insn = 1;
	ln++; // Initial value of 'is_stmt'
	سطر_بنیاد = dwarf_read_1(ln, انتہا);
	سطر_بنیاد |= سطر_بنیاد >= 0x80 ? ~0xff : 0;
	سطر_range = dwarf_read_1(ln, انتہا);
	opcode_بنیاد = dwarf_read_1(ln, انتہا);
	opcode_لمبائی = ln;
	ln += opcode_بنیاد - 1;
	opindex = 0;
	اگر (نسخہ >= 5) {
	    ستون = dwarf_read_1(ln, انتہا);
	    برائے (i = 0; i < ستون; i++) {
	        اندراج_format[i].type = dwarf_read_uleb128(&ln, انتہا);
	        اندراج_format[i].form = dwarf_read_uleb128(&ln, انتہا);
	    }
	    dir_سائز = dwarf_read_uleb128(&ln, انتہا);
	    برائے (i = 0; i < dir_سائز; i++) {
		برائے (j = 0; j < ستون; j++) {
		    اگر (اندراج_format[j].type == DW_LNCT_راستہ) {
		        اگر (اندراج_format[j].form != DW_FORM_سطر_strp)
			    جاؤ اگلا_سطر;
#اگر 0
		        قدر = لمبائی == 4 ? dwarf_read_4(ln, انتہا)
					    : dwarf_read_8(ln, انتہا);
		        اگر (i < DIR_جدول_سائز)
		            dirs[i] = (حرف *)rc->dwarf_سطر_str + قدر;
#ورنہ
			لمبائی == 4 ? dwarf_read_4(ln, انتہا)
				    : dwarf_read_8(ln, انتہا);
#اگر_ختم
		    }
		    ورنہ 
			dwarf_ignore_type(ln, انتہا);
		}
	    }
	    ستون = dwarf_read_1(ln, انتہا);
	    برائے (i = 0; i < ستون; i++) {
	        اندراج_format[i].type = dwarf_read_uleb128(&ln, انتہا);
	        اندراج_format[i].form = dwarf_read_uleb128(&ln, انتہا);
	    }
	    filename_سائز = dwarf_read_uleb128(&ln, انتہا);
	    برائے (i = 0; i < filename_سائز; i++)
		برائے (j = 0; j < ستون; j++) {
		    اگر (اندراج_format[j].type == DW_LNCT_راستہ) {
			اگر (اندراج_format[j].form != DW_FORM_سطر_strp)
			    جاؤ اگلا_سطر;
			قدر = لمبائی == 4 ? dwarf_read_4(ln, انتہا)
					    : dwarf_read_8(ln, انتہا);
		        اگر (i < FILE_جدول_سائز)
		            filename_جدول[i].name =
				(حرف *)rc->dwarf_سطر_str + قدر;
	            }
		    ورنہ اگر (اندراج_format[j].type == DW_LNCT_directory_اشاریہ) {
			انتخاب (اندراج_format[j].form) {
			حالت DW_FORM_data1: قدر = dwarf_read_1(ln, انتہا); توڑو;
			حالت DW_FORM_data2: قدر = dwarf_read_2(ln, انتہا); توڑو;
			حالت DW_FORM_data4: قدر = dwarf_read_4(ln, انتہا); توڑو;
			حالت DW_FORM_udata: قدر = dwarf_read_uleb128(&ln, انتہا); توڑو;
			طےشدہ: جاؤ اگلا_سطر;
			}
		        اگر (i < FILE_جدول_سائز)
		            filename_جدول[i].dir_اندراج = قدر;
		    }
		    ورنہ 
			dwarf_ignore_type(ln, انتہا);
	    }
	}
	ورنہ {
	    جب ((dwarf_read_1(ln, انتہا))) {
#اگر 0
		اگر (++dir_سائز < DIR_جدول_سائز)
		    dirs[dir_سائز - 1] = (حرف *)ln - 1;
#اگر_ختم
		جب (dwarf_read_1(ln, انتہا)) {}
	    }
	    جب ((dwarf_read_1(ln, انتہا))) {
		اگر (++filename_سائز < FILE_جدول_سائز) {
		    filename_جدول[filename_سائز - 1].name = (حرف *)ln - 1;
		    جب (dwarf_read_1(ln, انتہا)) {}
		    filename_جدول[filename_سائز - 1].dir_اندراج =
		        dwarf_read_uleb128(&ln, انتہا);
		}
		ورنہ {
		    جب (dwarf_read_1(ln, انتہا)) {}
		    dwarf_read_uleb128(&ln, انتہا);
		}
		dwarf_read_uleb128(&ln, انتہا); //وقت
		dwarf_read_uleb128(&ln, انتہا); //سائز
	    }
	}
	اگر (filename_سائز >= 1)
	    filename = filename_جدول[0].name;
	جب (ln < انتہا) {
	    آخری_pc = pc;
	    i = dwarf_read_1(ln, انتہا);
	    اگر (i >= opcode_بنیاد) {
	        اگر (max_ops_فی_insn == 1)
		    pc += ((i - opcode_بنیاد) / سطر_range) * min_insn_لمبائی;
		ورنہ {
		    pc += (opindex + (i - opcode_بنیاد) / سطر_range) /
			  max_ops_فی_insn * min_insn_لمبائی;
		    opindex = (opindex + (i - opcode_بنیاد) / سطر_range) %
			       max_ops_فی_insn;
		}
		i = (صحیح)((i - opcode_بنیاد) % سطر_range) + سطر_بنیاد;
check_pc:
		اگر (pc >= wanted_pc && wanted_pc >= آخری_pc)
		    جاؤ ملا;
		سطر += i;
	    }
	    ورنہ {
	        انتخاب (i) {
	        حالت 0:
		    len = dwarf_read_uleb128(&ln, انتہا);
		    cp = ln;
		    ln += len;
		    اگر (len == 0)
		        جاؤ اگلا_سطر;
		    انتخاب (dwarf_read_1(cp, انتہا)) {
		    حالت DW_LNE_انتہا_sequence:
		        توڑو;
		    حالت DW_LNE_سیٹ_پتہ:
#اگر PTR_سائز == 4
		        pc = dwarf_read_4(cp, انتہا);
#ورنہ
		        pc = dwarf_read_8(cp, انتہا);
#اگر_ختم
#اگر defined TCC_ہدف_MACHO
			pc += rc->prog_بنیاد;
#اگر_ختم
		        opindex = 0;
		        توڑو;
		    حالت DW_LNE_define_file: /* deprecated */
		        اگر (++filename_سائز < FILE_جدول_سائز) {
		            filename_جدول[filename_سائز - 1].name = (حرف *)ln - 1;
		            جب (dwarf_read_1(ln, انتہا)) {}
		            filename_جدول[filename_سائز - 1].dir_اندراج =
		                dwarf_read_uleb128(&ln, انتہا);
		        }
		        ورنہ {
		            جب (dwarf_read_1(ln, انتہا)) {}
		            dwarf_read_uleb128(&ln, انتہا);
		        }
		        dwarf_read_uleb128(&ln, انتہا); //وقت
		        dwarf_read_uleb128(&ln, انتہا); //سائز
		        توڑو;
		    حالت DW_LNE_hi_user - 1:
		        function = (حرف *)cp;
		        func_addr = pc;
		        توڑو;
		    طےشدہ:
		        توڑو;
		    }
		    توڑو;
	        حالت DW_LNS_advance_pc:
		    اگر (max_ops_فی_insn == 1)
		        pc += dwarf_read_uleb128(&ln, انتہا) * min_insn_لمبائی;
		    ورنہ {
		        غیرعلامتی طویل طویل off = dwarf_read_uleb128(&ln, انتہا);

		        pc += (opindex + off) / max_ops_فی_insn *
			      min_insn_لمبائی;
		        opindex = (opindex + off) % max_ops_فی_insn;
		    }
		    i = 0;
		    جاؤ check_pc;
	        حالت DW_LNS_advance_سطر:
		    سطر += dwarf_read_sleb128(&ln, انتہا);
		    توڑو;
	        حالت DW_LNS_سیٹ_file:
		    i = dwarf_read_uleb128(&ln, انتہا);
		    i -= i > 0 && نسخہ < 5;
		    اگر (i < FILE_جدول_سائز && i < filename_سائز)
		        filename = filename_جدول[i].name;
		    توڑو;
	        حالت DW_LNS_const_جوڑو_pc:
		    اگر (max_ops_فی_insn ==  1)
		        pc += ((255 - opcode_بنیاد) / سطر_range) * min_insn_لمبائی;
		    ورنہ {
		        غیرعلامتی صحیح off = (255 - opcode_بنیاد) / سطر_range;

		        pc += ((opindex + off) / max_ops_فی_insn) *
			      min_insn_لمبائی;
		        opindex = (opindex + off) % max_ops_فی_insn;
		    }
		    i = 0;
		    جاؤ check_pc;
	        حالت DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, انتہا);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    جاؤ check_pc;
	        طےشدہ:
		    برائے (j = 0; j < opcode_لمبائی[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, انتہا);
		    توڑو;
		}
	    }
	}
اگلا_سطر:
	ln = انتہا;
    }
    filename = function = تہی, func_addr = 0;
ملا:
    اگر (filename)
        pstrcpy(bi->file, حجم bi->file, filename), bi->سطر = سطر;
    اگر (function)
        pstrcpy(bi->func, حجم bi->func, function);
    bi->func_pc = func_addr;
    واپس (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#اگر_غیر_تعریف_شدہ CONFIG_TCC_BACKTRACE_ONLY
ساکن
#اگر_ختم
صحیح _tcc_backtrace(rt_چوکھٹا *f, ثابت حرف *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    حرف skip[40], پیغام[200];
    صحیح i, level, ret, n, one;
    ثابت حرف *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    اگر (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        حافظہ_نقل(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    اگر (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(پیغام, حجم پیغام, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    اگر (rc) {
        اگر (rc->dwarf)
            getinfo = rt_printline_dwarf;
        اگر (rc->عدد_callers)
            n = rc->عدد_callers;
    }

    برائے (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        اگر (ret == -1)
            توڑو;
        memset(&bi, 0, حجم bi);
        برائے (rc2 = rc; rc2; rc2 = rc2->اگلا) {
            اگر (getinfo(rc2, pc, &bi))
                توڑو;
            /* we try symtab symbols (no line number info) */
            اگر (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, حجم bi.func, a);
                توڑو;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        اگر (skip[0] && لڑی_تلاش(bi.file, skip))
            جاری;
#اگر_غیر_تعریف_شدہ CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_ڈھونڈو_state(f);
            اگر (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_ڈیٹا,
                    (خالی*)pc,
                    bi.file[0] ? bi.file : تہی,
                    bi.سطر,
                    bi.func[0] ? bi.func : تہی,
                    level == 0 ? پیغام : تہی
                    );
                اگر (ret == 0)
                    توڑو;
                جاؤ check_break;
            }
        }
#اگر_ختم
        اگر (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.سطر);
        } ورنہ {
            rt_printf("0x%08llx", (طویل طویل)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        اگر (level == 0) {
            rt_printf(": %s", پیغام);
            اگر (one)
                توڑو;
        }
        rt_printf("\n");

#اگر_غیر_تعریف_شدہ CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#اگر_ختم
        اگر (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->چوٹی_func)
            توڑو;
        ++level;
    }
    rt_post_sem();
    واپس 0;
}

/* emit a run time error at position 'pc' */
ساکن صحیح rt_error(rt_چوکھٹا *f, ثابت حرف *fmt, ...)
{
    va_list ap; حرف پیغام[200]; صحیح ret;
    va_start(ap, fmt);
    snprintf(پیغام, حجم پیغام, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, پیغام, ap);
    va_end(ap);
    واپس ret;
}

/* ------------------------------------------------------------- */

#اگر_غیر_تعریف_شدہ _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ورنہ
# define ucontext_t CONTEXT
#اگر_ختم

/* translate from ucontext_t* to internal rt_context * */
ساکن خالی rt_getcontext(ucontext_t *uc, rt_چوکھٹا *rc)
{
#اگر defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#وگرنہ_اگر defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#وگرنہ_اگر defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#وگرنہ_اگر defined __i386__
# اگر defined(__APPLE__)
    rc->ip = uc->uc_mcontext->__ss.__eip;
    rc->fp = uc->uc_mcontext->__ss.__ebp;
# elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
    rc->ip = uc->uc_mcontext.mc_eip;
    rc->fp = uc->uc_mcontext.mc_ebp;
# elif defined(__dietlibc__)
    rc->ip = uc->uc_mcontext.eip;
    rc->fp = uc->uc_mcontext.ebp;
# elif defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_EIP];
    rc->fp = uc->uc_mcontext.__gregs[_REG_EBP];
# elif defined(__OpenBSD__)
    rc->ip = uc->sc_eip;
    rc->fp = uc->sc_ebp;
# elif !defined REG_EIP && defined EIP /* fix for glibc 2.1 */
    rc->ip = uc->uc_mcontext.gregs[EIP];
    rc->fp = uc->uc_mcontext.gregs[EBP];
# ورنہ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#وگرنہ_اگر defined(__x86_64__)
# اگر defined(__APPLE__)
    rc->ip = uc->uc_mcontext->__ss.__rip;
    rc->fp = uc->uc_mcontext->__ss.__rbp;
# elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
    rc->ip = uc->uc_mcontext.mc_rip;
    rc->fp = uc->uc_mcontext.mc_rbp;
# elif defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_RIP];
    rc->fp = uc->uc_mcontext.__gregs[_REG_RBP];
# elif defined(__OpenBSD__)
    rc->ip = uc->sc_rip;
    rc->fp = uc->sc_rbp;
# ورنہ
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#وگرنہ_اگر defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنہ_اگر defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#وگرنہ_اگر defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنہ_اگر defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#وگرنہ_اگر defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#وگرنہ_اگر defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#وگرنہ_اگر defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنہ_اگر defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#وگرنہ_اگر defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#وگرنہ_اگر defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#وگرنہ_اگر defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#اگر_ختم
}

/* ------------------------------------------------------------- */
#اگر_غیر_تعریف_شدہ _WIN32
/* signal handler for fatal errors */
ساکن خالی sig_error(صحیح signum, siginfo_t *siginf, خالی *puc)
{
    rt_چوکھٹا f;
    rt_getcontext(puc, &f);

    انتخاب(signum) {
    حالت SIGFPE:
        انتخاب(siginf->si_code) {
        حالت FPE_INTDIV:
        حالت FPE_FLTDIV:
            rt_error(&f, "division by zero");
            توڑو;
        طےشدہ:
            rt_error(&f, "floating point exception");
            توڑو;
        }
        توڑو;
    حالت SIGBUS:
    حالت SIGSEGV:
        rt_error(&f, "invalid memory access");
        توڑو;
    حالت SIGILL:
        rt_error(&f, "illegal instruction");
        توڑو;
    حالت SIGABRT:
        rt_error(&f, "abort() called");
        توڑو;
    طےشدہ:
        rt_error(&f, "caught signal %d", signum);
        توڑو;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, تہی);
    }
    rt_exit(&f, 255);
}

#اگر_غیر_تعریف_شدہ SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#اگر_ختم

/* Generate a stack backtrace when a CPU exception occurs. */
ساکن خالی سیٹ_exception_handler(خالی)
{
    ساخت sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#اگر 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#اگر_ختم
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, تہی);
    sigaction(SIGILL, &sigact, تہی);
    sigaction(SIGSEGV, &sigact, تہی);
    sigaction(SIGBUS, &sigact, تہی);
    sigaction(SIGABRT, &sigact, تہی);
#اگر 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ساکن غیرعلامتی حرف ڈھیر[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ڈھیر;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, تہی);
    }
#اگر_ختم
}

#ورنہ /* WIN32 */

/* signal handler for fatal errors */
ساکن طویل __stdcall cpu_exception_handler(EXCEPTION_اشارے *ex_info)
{
    rt_چوکھٹا f;
    غیرعلامتی رمز;
    rt_getcontext(ex_info->Context_ریکارڈ, &f);

    انتخاب (رمز = ex_info->Exception_ریکارڈ->Exception_رمز) {
    حالت EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        توڑو;
    حالت EXCEPTION_ڈھیر_حد_سے_تجاوز:
        rt_error(&f, "stack overflow");
        توڑو;
    حالت EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        توڑو;
    حالت EXCEPTION_BREAKPOINT:
    حالت EXCEPTION_SINGLE_قدم:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        واپس EXCEPTION_CONTINUE_تلاش;
    طےشدہ:
        rt_error(&f, "caught exception %08x", رمز);
        توڑو;
    }
    rt_exit(&f, 255);
    واپس EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ساکن خالی سیٹ_exception_handler(خالی)
{
#اگر_تعریف_شدہ _WIN64
    جوڑو_Vectored_Exception_Handler(1, cpu_exception_handler);
#ورنہ
    سیٹ_Unhandled_Exception_Filter(cpu_exception_handler);
#اگر_ختم
}

#اگر_ختم

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#اگر defined(__i386__) || defined(__x86_64__)
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } ورنہ {
        addr_t fp = rc->fp;
        جب (1) {
            اگر (fp < 0x1000)
                واپس -1;
            اگر (0 == --level)
                توڑو;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    واپس 0;
}

/* XXX: only supports linux/bsd */
#وگرنہ_اگر defined(__arm__) && !defined(_WIN32)
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } ورنہ {
        addr_t fp = rc->fp;
        جب (1) {
            اگر (fp < 0x1000)
                واپس -1;
            اگر (0 == --level)
                توڑو;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    واپس 0;
}

#وگرنہ_اگر defined(__aarch64__)
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } ورنہ {
        addr_t fp = rc->fp;
        جب (1) {
            اگر (fp < 0x1000)
                واپس -1;
            اگر (0 == --level)
                توڑو;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    واپس 0;
}

#وگرنہ_اگر defined(__riscv)
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } ورنہ {
        addr_t fp = rc->fp;
        جب (1) {
            اگر (fp < 0x1000)
                واپس -1;
            اگر (0 == --level)
                توڑو;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    واپس 0;
}

#ورنہ
#warning جوڑو arch specific rt_get_caller_pc()
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحیح level)
{
    واپس -1;
}

#اگر_ختم
#ورنہ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ساکن صحیح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *f, صحیح level)
{
    اگر (level)
        واپس -1;
    *paddr = f->ip;
    واپس 0;
}
#اگر_ختم /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#اگر_تعریف_شدہ CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC خالی *dlopen(ثابت حرف *filename, صحیح flag)
{
    واپس تہی;
}

ST_FUNC خالی dlclose(خالی *p)
{
}

ST_FUNC ثابت حرف *dlerror(خالی)
{
    واپس "error";
}

قسمتعریف ساخت TCCSyms {
    حرف *str;
    خالی *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ساکن TCCSyms tcc_syms[] = {
#اگر !defined(CONFIG_TCCBOOT)
#تعریف_کرو TCCSYM(a) { #a, &a, },
    TCCSYM(لکھو)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#تعریف_منسوخ TCCSYM
#اگر_ختم
    { تہی, تہی },
};

ST_FUNC خالی *dlsym(خالی *handle, ثابت حرف *علامت)
{
    TCCSyms *p;
    p = tcc_syms;
    جب (p->str != تہی) {
        اگر (!strcmp(p->str, علامت))
            واپس p->ptr;
        p++;
    }
    واپس تہی;
}

#اگر_ختم /* CONFIG_TCC_STATIC */
#اگر_ختم /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
