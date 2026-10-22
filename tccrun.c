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

#ضمن "tcc.h"

/* only native compiler supports -run */
#اگر_تعریف_شده TCC_IS_NATIVE

#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
/* runtime debug info block */
تعريفنوع بنية rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اتحاد {
	بنية {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_انتها;
	    حرف *stab_str;
	};
	بنية {
	    بیعلامت حرف *dwarf_سطر;
	    بیعلامت حرف *dwarf_سطر_انتها;
	    بیعلامت حرف *dwarf_سطر_str;
	};
    };
    ElfW(Sym) *esym_شروع;
    ElfW(Sym) *esym_انتها;
    حرف *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_پایه;
    فراغ *bounds_شروع;
    فراغ *بالاترین_func;
    بنية rt_context *بعدی;
    // 10 * PTR_SIZE
    صحيح رقم_callers;
    صحيح dwarf;
} rt_context;

/* linked list of rt_contexts */
ساكن rt_context *g_rc;
ساكن صحيح signal_مجموعه;
ساكن فراغ مجموعه_exception_handler(فراغ);
#پایان_اگر /* def CONFIG_TCC_BACKTRACE */

تعريفنوع بنية rt_قاب {
    addr_t ip, fp, sp;
} rt_قاب;

ساكن TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ساكن rt_sem);
ساكن فراغ rt_wait_sem(فراغ) { WAIT_SEM(&rt_sem); }
ساكن فراغ rt_post_sem(فراغ) { POST_SEM(&rt_sem); }
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *f, صحيح level);
ساكن فراغ rt_exit(rt_قاب *f, صحيح کد);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#اگر_تعریف_نشده CONFIG_TCC_BACKTRACE_ONLY

#اگر_تعریف_نشده _WIN32
# include <sys/mman.h>
#پایان_اگر

ساكن صحيح protect_صفحات(فراغ *ptr, بیعلامت دراز درازی, صحيح نما);
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بیعلامت ptr_diff);
ساكن فراغ st_link(TCCState *s1);
ساكن فراغ st_unlink(TCCState *s1);
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
ساكن صحيح _tcc_backtrace(rt_قاب *f, ثابت حرف *fmt, va_list ap);
#پایان_اگر
#اگر_تعریف_شده _WIN64
ساكن فراغ *win64_جمع_کن_function_جدول(TCCState *s1);
ساكن فراغ win64_del_function_جدول(فراغ *);
#پایان_اگر

#إذا !defined PAGESIZE
# إذا defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# وإلا
#  define PAGESIZE 4096
# endif
#پایان_اگر

#تعریف_کن PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#إذا !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#پایان_اگر

/* use VirtualAlloc() instead of tcc_malloc() */
#إذا defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#پایان_اگر

ساكن صحيح rt_mem(TCCState *s1, صحيح اندازه)
{
    فراغ *ptr;
    صحيح ptr_diff = 0;
#اگر_تعریف_شده CONFIG_SELINUX
    /* Using mmap instead of malloc */
    فراغ *prw;
    حرف tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحيح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, اندازه);

    ptr = mmap(عدم, اندازه * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((حرف*)ptr + اندازه, اندازه, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    إذا (ptr == MAP_FAILED || prw == MAP_FAILED)
	أرجع tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (حرف*)prw - (حرف*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    اندازه *= 2;
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(عدم, اندازه, MEM_RESERVE | MEM_COMMIT, صفحه_READWRITE);
    إذا (!ptr)
        أرجع tcc_error_noabort("tccrun: could not allocate memory");
#وإلا
    ptr = tcc_malloc(اندازه += PAGESIZE); /* one extra page to align malloc memory */
#پایان_اگر
    s1->پیاپی_ptr = ptr;
    s1->پیاپی_اندازه = اندازه;
    أرجع ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحيح tcc_relocate(TCCState *s1)
{
    صحيح اندازه, ret, ptr_diff;

    إذا (s1->پیاپی_ptr)
        خروج(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace)
        tcc_جمع_کن_نماد(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#پایان_اگر
    اندازه = tcc_relocate_ex(s1, عدم, 0);
    إذا (اندازه < 0)
        أرجع -1;
    ptr_diff = rt_mem(s1, اندازه);
    إذا (ptr_diff < 0)
        أرجع -1;
    ret = tcc_relocate_ex(s1, s1->پیاپی_ptr, ptr_diff);
    إذا (ret == 0)
        st_link(s1);
    أرجع ret;
}

ST_FUNC فراغ tcc_پیاپی_free(TCCState *s1)
{
    بیعلامت اندازه;
    فراغ *ptr;
    صحيح i;

    /* free any loaded DLLs */
    لكل ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        إذا ( ref->handle )
#اگر_تعریف_شده _WIN32
            FreeLibrary((HMODULE)ref->handle);
#وإلا
            dlclose(ref->handle);
#پایان_اگر
    }
    /* unmap or unprotect and free memory */
    ptr = s1->پیاپی_ptr;
    إذا (عدم == ptr)
        أرجع;
    st_unlink(s1);
#اگر_تعریف_شده _WIN64
    win64_del_function_جدول(s1->پیاپی_function_جدول);
#پایان_اگر
    اندازه = s1->پیاپی_اندازه;
#اگر_تعریف_شده CONFIG_SELINUX
    munmap(ptr, اندازه);
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, اندازه, MEM_RELEASE);
#وإلا
    /* unprotect memory to make it usable for malloc again */
    protect_صفحات((فراغ*)PAGEALIGN(ptr), اندازه - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#پایان_اگر
}

#تعریف_کن RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحيح tcc_پیاپی(TCCState *s1, صحيح argc, حرف **argv)
{
    صحيح (*prog_main)(صحيح, حرف **, حرف **), ret;
    ثابت حرف *بالاترین_sym;
    jmp_buf main_jb;

#إذا defined(__APPLE__)
    خارجي حرف ***_NSGetEnviron(فراغ);
    حرف **envp = *_NSGetEnviron();
#وإلاإذا defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    خارجي حرف **environ;
    حرف **envp = environ;
#وإلا
    حرف **envp = environ;
#پایان_اگر

    /* tcc -dt -run ... nothing to do if no main() */
    إذا ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        أرجع 0;

    tcc_جمع_کن_نماد(s1, "__rt_exit", rt_exit);
    s1->پیاپی_main = "_runmain", بالاترین_sym = "main";
    إذا (s1->elf_entryname)
        s1->پیاپی_main = بالاترین_sym = s1->elf_entryname;
    tcc_جمع_کن_support(s1, "runmain.o");

    إذا (tcc_relocate(s1) < 0)
        أرجع -1;

    prog_main = (فراغ*)get_sym_addr(s1, s1->پیاپی_main, 1, 1);
    إذا ((addr_t)-1 == (addr_t)prog_main)
        أرجع -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    إذا (s1->پیاپی_stdin && !freopen(s1->پیاپی_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->پیاپی_stdin);
        أرجع -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_نماد(s1, بالاترین_sym));
    إذا (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } وإلا إذا (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    إذا (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    أرجع ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ساكن فراغ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    صحيح sym_شاخص, انتها_sym = s->داده_جابه_جایی / حجم (ElfSym);
    /* reset symtab */
    s->داده_جابه_جایی = s->link->داده_جابه_جایی = s->hash->داده_جابه_جایی = 0;
    init_symtab(s);
    /* add global symbols again */
    لكل (sym_شاخص = 1; sym_شاخص < انتها_sym; ++sym_شاخص) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->داده)[sym_شاخص];
        ثابت حرف *name = (حرف *)s->link->داده + sym->st_name;
        إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            استمر;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_مقدار, sym->st_اندازه, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ساكن فراغ cleanup_sections(TCCState *s1)
{
    بنية { Section **secs; صحيح nb_secs; } *p = (فراغ*)&s1->sections;
    صحيح i, f = 2;
    افعل {
        لكل (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            إذا (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->داده = tcc_realloc(s->داده, s->داده_allocated = s->داده_جابه_جایی);
            } وإلا {
                free_section(s), tcc_free(s), p->secs[i] = عدم;
            }
        }
    } طالما (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#اگر_تعریف_نشده CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# وإلا
#   define CONFIG_RUNMEM_RO 0
#  endif
#پایان_اگر

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بیعلامت ptr_diff)
{
    Section *s;
    بیعلامت جابه_جایی, درازی, align, i, k, f;
    بیعلامت n, copy;
    addr_t mem, addr;

    إذا (عدم == ptr) {
        s1->nb_errors = 0;
#اگر_تعریف_شده TCC_هدف_PE
        pe_output_file(s1, عدم);
#وإلا
        tcc_جمع_کن_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#پایان_اگر
    }

    جابه_جایی = copy = 0;
    mem = (addr_t)ptr;
redo:
    إذا (s1->verbose == 2 && copy)
        چاپ_کن(&"-----------------------------------------------------\n"[PTR_اندازه*2 - 8]);
    إذا (s1->nb_errors)
        أرجع -1;
    إذا (copy == 3)
        أرجع 0;

    لكل (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        لكل(i = 1; i < s1->nb_sections; i++) {
            ساكن ثابت حرف shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            إذا (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                استمر;
            درازی = s->داده_جابه_جایی;
            إذا (copy == 2) {
                إذا (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + درازی;
                استمر;
            }
            إذا (copy) { /* final step: copy section data to memory */
                إذا (s1->verbose == 2)
                    چاپ_کن("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (فراغ*)s->sh_addr, درازی, s->sh_addralign);
                ptr = (فراغ*)s->sh_addr;
                إذا (k == 0)
                    ptr = (فراغ*)(s->sh_addr + ptr_diff);
                إذا (عدم == s->داده || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, درازی);
                وإلا
                    کپی_حافظه(ptr, s->داده, درازی);
                استمر;
            }

            إذا ((s->sh_flags & SHF_TLS) && درازی)
                أرجع tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            إذا (++n == 1) {
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                إذا (align < 64)
                    align = 64;
#پایان_اگر
                /* start new page for different permissions */
                إذا (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            جابه_جایی += -(addr + جابه_جایی) & (align - 1);
            s->sh_addr = mem ? addr + جابه_جایی : 0;
            جابه_جایی += درازی;
        }
        إذا (copy == 2) { /* set permissions */
            إذا (n == 0) /* no data  */
                استمر;
#اگر_تعریف_شده CONFIG_SELINUX
            إذا (k == 0) /* SHF_EXECINSTR has its own mapping */
                استمر;
#پایان_اگر
            f = k;
            إذا (f >= CONFIG_RUNMEM_RO) {
                إذا (f != 0)
                    استمر;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            إذا (s1->verbose == 2) {
                چاپ_کن("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (فراغ*)addr, (بیعلامت)n);
            }
            إذا (protect_صفحات((فراغ*)addr, n, f) < 0)
                أرجع tcc_error_noabort(
#اگر_تعریف_شده _WIN32
                    "VirtualProtect failed");
#وإلا
                    "mprotect failed (did you mean to configure --with-selinux?)");
#پایان_اگر
        }
    }

    إذا (0 == mem)
        أرجع PAGEALIGN(جابه_جایی);

    إذا (++copy == 2) {
        اذهب redo;
    }
    إذا (copy == 3) {
#اگر_تعریف_شده _WIN64
        s1->پیاپی_function_جدول = win64_جمع_کن_function_جدول(s1);
#پایان_اگر
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        اذهب redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    إذا (s1->nb_errors)
        اذهب redo;
    /* relocate sections */
#اگر_تعریف_شده TCC_هدف_PE
    s1->pe_imagebase = mem;
#وإلا
    relocate_plt(s1);
#پایان_اگر
    relocate_sections(s1);
    اذهب redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ساكن صحيح protect_صفحات(فراغ *ptr, بیعلامت دراز درازی, صحيح نما)
{
#اگر_تعریف_شده _WIN32
    ساكن ثابت بیعلامت حرف protect[] = {
        صفحه_EXECUTE_READ,
        صفحه_READONLY,
        صفحه_READWRITE,
        صفحه_EXECUTE_READWRITE
        };
    DWORD old;
    إذا (!VirtualProtect(ptr, درازی, protect[نما], &old))
        أرجع -1;
#وإلا
    ساكن ثابت بیعلامت حرف protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    إذا (mprotect(ptr, درازی, protect[نما]))
        أرجع -1;
#پایان_اگر
/* XXX: BSD sometimes dump core with bad system call */
#إذا (defined TCC_هدف_ARM && !TARGETOS_BSD) \
    || defined TCC_هدف_ARM64 || defined TCC_هدف_RISCV64
    إذا (نما == 0 || نما == 3) {
#اگر_تعریف_شده _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, درازی);
#وإلا
        فراغ __clear_cache(فراغ *beginning, فراغ *انتها);
        __clear_cache(ptr, (حرف *)ptr + درازی);
#پایان_اگر
    }
#پایان_اگر
    أرجع 0;
}

#اگر_تعریف_شده _WIN64
ساكن فراغ *win64_جمع_کن_function_جدول(TCCState *s1)
{
    فراغ *p = عدم;
    إذا (s1->uw_pdata) {
        p = (فراغ*)s1->uw_pdata->sh_addr;
        Rtl_جمع_کن_Function_جدول(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->داده_جابه_جایی / حجم (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = عدم;
    }
    أرجع p;
}

ساكن فراغ win64_del_function_جدول(فراغ *p)
{
    إذا (p) {
        Rtl_Delete_Function_جدول((RUNTIME_FUNCTION*)p);
    }
}
#پایان_اگر

ساكن فراغ bt_link(TCCState *s1)
{
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    rt_context *rc;
    إذا (!s1->do_backtrace)
        أرجع;
    rc = tcc_get_نماد(s1, "__rt_info");
    إذا (!rc)
        أرجع;
    rc->esym_شروع = (ElfW(Sym) *)(symtab_section->داده);
    rc->esym_انتها = (ElfW(Sym) *)(symtab_section->داده + symtab_section->داده_جابه_جایی);
    rc->elf_str = (حرف *)symtab_section->link->داده;
    إذا (PTR_اندازه == 8 && !s1->dwarf)
        rc->prog_پایه &= 0xffffffff00000000ULL;
#اگر_تعریف_شده CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check) {
        فراغ *p;
        إذا ((p = tcc_get_نماد(s1, "__bound_init")))
            ((فراغ(*)(فراغ*,صحيح))p)(rc->bounds_شروع, 1);
    }
#پایان_اگر
    rc->بعدی = g_rc, g_rc = rc, s1->rc = rc;
    إذا (0 == signal_مجموعه)
        مجموعه_exception_handler(), signal_مجموعه = 1;
#پایان_اگر
}

ساكن فراغ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->بعدی = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ساكن فراغ ptr_unlink(فراغ *list, فراغ *e, بیعلامت بعدی)
{
    فراغ **pp, **nn, *p;
    لكل (pp = list; !!(p = *pp); pp = nn) {
        nn = (فراغ*)((حرف*)p + بعدی); /* nn = &p->next; */
        إذا (p == e) {
            *pp = *nn;
            اكسر;
        }
    }
}

ساكن فراغ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, بعدی));
#پایان_اگر
    ptr_unlink(&g_s1, s1, offsetof(TCCState, بعدی));
    rt_post_sem();
}

LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *p_jmp_buf, فراغ *func, فراغ *p_longjmp)
{
    s1->پیاپی_lj = p_longjmp;
    s1->پیاپی_jb = p_jmp_buf;
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE
    إذا (s1->rc)
        s1->rc->بالاترین_func = func;
#پایان_اگر
    أرجع p_jmp_buf;
}

LIBTCCAPI فراغ tcc_مجموعه_backtrace_func(TCCState *s1, فراغ *داده, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_داده = داده;
}

ساكن TCCState *rt_پیدا_کن_state(rt_قاب *f)
{
    TCCState *s;
    صحيح level;
    addr_t pc;

    s = g_s1;
    إذا (عدم == s || عدم == s->بعدی) {
        /* play it safe in the simple case when there is only one state */
        أرجع s;
    }
    لكل (level = 0; level < 8; ++level) {
        إذا (rt_get_caller_pc(&pc, f, level) < 0)
            اكسر;
        لكل (s = g_s1; s; s = s->بعدی) {
            إذا (pc >= (addr_t)s->پیاپی_ptr
             && pc  < (addr_t)s->پیاپی_ptr + s->پیاپی_اندازه)
                أرجع s;
        }
    }
    أرجع عدم;
}

ساكن فراغ rt_exit(rt_قاب *f, صحيح کد)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_پیدا_کن_state(f);
    rt_post_sem();
    إذا (s && s->پیاپی_lj) {
#اگر_تعریف_شده CONFIG_TCC_BCHECK
        إذا (f->fp) { /* called from signal */
            فراغ *p = tcc_get_نماد(s, "__bound_exit");
            إذا (p)
                ((فراغ (*)(فراغ))p)();
        }
#پایان_اگر
        إذا (کد == 0)
            کد = RT_EXIT_ZERO;
        ((فراغ(*)(فراغ*,صحيح))s->پیاپی_lj)(s->پیاپی_jb, کد);
    }
    خروج(کد);
}

/* ------------------------------------------------------------- */
#وإلا // if defined CONFIG_TCC_BACKTRACE_ONLY
ساكن فراغ rt_exit(rt_قاب *f, صحيح کد)
{
    خروج(کد);
}
#پایان_اگر //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#اگر_تعریف_شده CONFIG_TCC_BACKTRACE

ساكن صحيح rt_vprintf(ثابت حرف *fmt, va_list ap)
{
    صحيح ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    أرجع ret;
}

ساكن صحيح rt_printf(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحيح r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    أرجع r;
}

ساكن حرف *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    لكل (esym = rc->esym_شروع + 1; esym < rc->esym_انتها; ++esym) {
        صحيح type = ELFW(ST_TYPE)(esym->st_info);
        إذا ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_مقدار
            && wanted_pc < esym->st_مقدار + esym->st_اندازه) {
            *func_addr = esym->st_مقدار;
            أرجع rc->elf_str + esym->st_name;
        }
    }
    أرجع عدم;
}

تعريفنوع بنية bt_info
{
    حرف file[100];
    صحيح سطر;
    حرف func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ساكن addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    حرف func_name[128];
    addr_t func_addr, آخرین_pc, pc;
    ثابت حرف *incl_files[INCLUDE_پشته_اندازه];
    صحيح incl_شاخص, آخرین_incl_شاخص, len, آخرین_سطر_رقم, i;
    ثابت حرف *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_شاخص = 0;
    آخرین_pc = (addr_t)-1;
    آخرین_سطر_رقم = 1;
    آخرین_incl_شاخص = 0;

    لكل (sym = rc->stab_sym + 1; sym < rc->stab_sym_انتها; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_مقدار;

        بدل(sym->n_type) {
        حالة N_SLINE:
            إذا (func_addr)
                اذهب rel_pc;
        حالة N_SO:
        حالة N_SOL:
            اذهب abs_pc;
        حالة N_FUN:
            إذا (sym->n_strx == 0) /* end of function */
                اذهب rel_pc;
        abs_pc:
#إذا PTR_اندازه == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_پایه;
#پایان_اگر
            اذهب check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            إذا (pc >= wanted_pc && wanted_pc >= آخرین_pc)
                اذهب یافت;
            اكسر;
        }

        بدل(sym->n_type) {
            /* function start or end */
        حالة N_FUN:
            إذا (sym->n_strx == 0)
                اذهب reset_func;
            p = strchr(str, ':');
            إذا (0 == p || (len = p - str + 1, len > حجم func_name))
                len = حجم func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            اكسر;
            /* line number info */
        حالة N_SLINE:
            آخرین_pc = pc;
            آخرین_سطر_رقم = sym->n_desc;
            آخرین_incl_شاخص = incl_شاخص;
            اكسر;
            /* include files */
        حالة N_BINCL:
            إذا (incl_شاخص < INCLUDE_پشته_اندازه)
                incl_files[incl_شاخص++] = str;
            اكسر;
        حالة N_EINCL:
            إذا (incl_شاخص > 1)
                incl_شاخص--;
            اكسر;
            /* start/end of translation unit */
        حالة N_SO:
            incl_شاخص = 0;
            إذا (sym->n_strx) {
                /* do not add path */
                len = طول_رشته(str);
                إذا (len > 0 && str[len - 1] != '/')
                    incl_files[incl_شاخص++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            آخرین_pc = (addr_t)-1;
            اكسر;
            /* alternative file name (from #line or #include directives) */
        حالة N_SOL:
            إذا (incl_شاخص)
                incl_files[incl_شاخص-1] = str;
            اكسر;
        }
    }
    آخرین_incl_شاخص = 0, func_name[0] = 0, func_addr = 0;
یافت:
    i = آخرین_incl_شاخص;
    إذا (i > 0) {
        pstrcpy(bi->file, حجم bi->file, incl_files[--i]);
        bi->سطر = آخرین_سطر_رقم;
    }
    pstrcpy(bi->func, حجم bi->func, func_name);
    bi->func_pc = func_addr;
    أرجع func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#تعریف_کن DIR_جدول_اندازه	(64)
#تعریف_کن FILE_جدول_اندازه	(512)

#تعریف_کن	dwarf_ignore_type(ln, انتها) /* timestamp/size/md5/... */ \
	بدل (مدخل_format[j].form) { \
	حالة DW_FORM_data1: (ln) += 1; اكسر; \
	حالة DW_FORM_data2: (ln) += 2; اكسر; \
	حالة DW_FORM_data4: (ln) += 3; اكسر; \
	حالة DW_FORM_data8: (ln) += 8; اكسر; \
	حالة DW_FORM_data16: (ln) += 16; اكسر; \
	حالة DW_FORM_udata: dwarf_read_uleb128(&(ln), (انتها)); اكسر; \
	افتراضي: اذهب بعدی_سطر; \
	}

ساكن addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    بیعلامت حرف *ln;
    بیعلامت حرف *cp;
    بیعلامت حرف *انتها;
    بیعلامت حرف *opcode_درازی;
    بیعلامت دراز دراز اندازه;
    بیعلامت صحيح درازی;
    بیعلامت حرف نسخه;
    بیعلامت صحيح min_insn_درازی;
    بیعلامت صحيح max_ops_در_هر_insn;
    صحيح سطر_پایه;
    بیعلامت صحيح سطر_range;
    بیعلامت صحيح opcode_پایه;
    بیعلامت صحيح opindex;
    بیعلامت صحيح ستون;
    بیعلامت صحيح i;
    بیعلامت صحيح j;
    بیعلامت صحيح len;
    بیعلامت دراز دراز مقدار;
    بنية {
	بیعلامت صحيح type;
	بیعلامت صحيح form;
    } مدخل_format[256];
    بیعلامت صحيح dir_اندازه;
#إذا 0
    حرف *dirs[DIR_جدول_اندازه];
#پایان_اگر
    بیعلامت صحيح filename_اندازه;
    بنية /*dwarf_filename_struct*/ {
        بیعلامت صحيح dir_مدخل;
        حرف *name;
    } filename_جدول[FILE_جدول_اندازه];
    addr_t آخرین_pc;
    addr_t pc;
    addr_t func_addr;
    صحيح سطر;
    حرف *filename;
    حرف *function;

    filename = عدم;
    function = عدم;
    func_addr = 0;
    سطر = 0;

    ln = rc->dwarf_سطر;
    طالما (ln < rc->dwarf_سطر_انتها) {
	dir_اندازه = 0;
	filename_اندازه = 0;
        آخرین_pc = 0;
        pc = 0;
        func_addr = 0;
        سطر = 1;
        filename = عدم;
        function = عدم;
	درازی = 4;
	اندازه = dwarf_read_4(ln, rc->dwarf_سطر_انتها);
	إذا (اندازه == 0xffffffffu) // dwarf 64
	    درازی = 8, اندازه = dwarf_read_8(ln, rc->dwarf_سطر_انتها);
	انتها = ln + اندازه;
	إذا (انتها < ln || انتها > rc->dwarf_سطر_انتها)
	    اكسر;
	نسخه = dwarf_read_2(ln, انتها);
	إذا (نسخه >= 5)
	    ln += درازی + 2; // address size, segment selector, prologue Length
	وإلا
	    ln += درازی; // prologue Length
	min_insn_درازی = dwarf_read_1(ln, انتها);
	إذا (نسخه >= 4)
	    max_ops_در_هر_insn = dwarf_read_1(ln, انتها);
	وإلا
	    max_ops_در_هر_insn = 1;
	ln++; // Initial value of 'is_stmt'
	سطر_پایه = dwarf_read_1(ln, انتها);
	سطر_پایه |= سطر_پایه >= 0x80 ? ~0xff : 0;
	سطر_range = dwarf_read_1(ln, انتها);
	opcode_پایه = dwarf_read_1(ln, انتها);
	opcode_درازی = ln;
	ln += opcode_پایه - 1;
	opindex = 0;
	إذا (نسخه >= 5) {
	    ستون = dwarf_read_1(ln, انتها);
	    لكل (i = 0; i < ستون; i++) {
	        مدخل_format[i].type = dwarf_read_uleb128(&ln, انتها);
	        مدخل_format[i].form = dwarf_read_uleb128(&ln, انتها);
	    }
	    dir_اندازه = dwarf_read_uleb128(&ln, انتها);
	    لكل (i = 0; i < dir_اندازه; i++) {
		لكل (j = 0; j < ستون; j++) {
		    إذا (مدخل_format[j].type == DW_LNCT_مسیر) {
		        إذا (مدخل_format[j].form != DW_FORM_سطر_strp)
			    اذهب بعدی_سطر;
#إذا 0
		        مقدار = درازی == 4 ? dwarf_read_4(ln, انتها)
					    : dwarf_read_8(ln, انتها);
		        إذا (i < DIR_جدول_اندازه)
		            dirs[i] = (حرف *)rc->dwarf_سطر_str + مقدار;
#وإلا
			درازی == 4 ? dwarf_read_4(ln, انتها)
				    : dwarf_read_8(ln, انتها);
#پایان_اگر
		    }
		    وإلا 
			dwarf_ignore_type(ln, انتها);
		}
	    }
	    ستون = dwarf_read_1(ln, انتها);
	    لكل (i = 0; i < ستون; i++) {
	        مدخل_format[i].type = dwarf_read_uleb128(&ln, انتها);
	        مدخل_format[i].form = dwarf_read_uleb128(&ln, انتها);
	    }
	    filename_اندازه = dwarf_read_uleb128(&ln, انتها);
	    لكل (i = 0; i < filename_اندازه; i++)
		لكل (j = 0; j < ستون; j++) {
		    إذا (مدخل_format[j].type == DW_LNCT_مسیر) {
			إذا (مدخل_format[j].form != DW_FORM_سطر_strp)
			    اذهب بعدی_سطر;
			مقدار = درازی == 4 ? dwarf_read_4(ln, انتها)
					    : dwarf_read_8(ln, انتها);
		        إذا (i < FILE_جدول_اندازه)
		            filename_جدول[i].name =
				(حرف *)rc->dwarf_سطر_str + مقدار;
	            }
		    وإلا إذا (مدخل_format[j].type == DW_LNCT_directory_شاخص) {
			بدل (مدخل_format[j].form) {
			حالة DW_FORM_data1: مقدار = dwarf_read_1(ln, انتها); اكسر;
			حالة DW_FORM_data2: مقدار = dwarf_read_2(ln, انتها); اكسر;
			حالة DW_FORM_data4: مقدار = dwarf_read_4(ln, انتها); اكسر;
			حالة DW_FORM_udata: مقدار = dwarf_read_uleb128(&ln, انتها); اكسر;
			افتراضي: اذهب بعدی_سطر;
			}
		        إذا (i < FILE_جدول_اندازه)
		            filename_جدول[i].dir_مدخل = مقدار;
		    }
		    وإلا 
			dwarf_ignore_type(ln, انتها);
	    }
	}
	وإلا {
	    طالما ((dwarf_read_1(ln, انتها))) {
#إذا 0
		إذا (++dir_اندازه < DIR_جدول_اندازه)
		    dirs[dir_اندازه - 1] = (حرف *)ln - 1;
#پایان_اگر
		طالما (dwarf_read_1(ln, انتها)) {}
	    }
	    طالما ((dwarf_read_1(ln, انتها))) {
		إذا (++filename_اندازه < FILE_جدول_اندازه) {
		    filename_جدول[filename_اندازه - 1].name = (حرف *)ln - 1;
		    طالما (dwarf_read_1(ln, انتها)) {}
		    filename_جدول[filename_اندازه - 1].dir_مدخل =
		        dwarf_read_uleb128(&ln, انتها);
		}
		وإلا {
		    طالما (dwarf_read_1(ln, انتها)) {}
		    dwarf_read_uleb128(&ln, انتها);
		}
		dwarf_read_uleb128(&ln, انتها); //زمان
		dwarf_read_uleb128(&ln, انتها); //اندازه
	    }
	}
	إذا (filename_اندازه >= 1)
	    filename = filename_جدول[0].name;
	طالما (ln < انتها) {
	    آخرین_pc = pc;
	    i = dwarf_read_1(ln, انتها);
	    إذا (i >= opcode_پایه) {
	        إذا (max_ops_در_هر_insn == 1)
		    pc += ((i - opcode_پایه) / سطر_range) * min_insn_درازی;
		وإلا {
		    pc += (opindex + (i - opcode_پایه) / سطر_range) /
			  max_ops_در_هر_insn * min_insn_درازی;
		    opindex = (opindex + (i - opcode_پایه) / سطر_range) %
			       max_ops_در_هر_insn;
		}
		i = (صحيح)((i - opcode_پایه) % سطر_range) + سطر_پایه;
check_pc:
		إذا (pc >= wanted_pc && wanted_pc >= آخرین_pc)
		    اذهب یافت;
		سطر += i;
	    }
	    وإلا {
	        بدل (i) {
	        حالة 0:
		    len = dwarf_read_uleb128(&ln, انتها);
		    cp = ln;
		    ln += len;
		    إذا (len == 0)
		        اذهب بعدی_سطر;
		    بدل (dwarf_read_1(cp, انتها)) {
		    حالة DW_LNE_انتها_sequence:
		        اكسر;
		    حالة DW_LNE_مجموعه_آدرس:
#إذا PTR_اندازه == 4
		        pc = dwarf_read_4(cp, انتها);
#وإلا
		        pc = dwarf_read_8(cp, انتها);
#پایان_اگر
#إذا defined TCC_هدف_MACHO
			pc += rc->prog_پایه;
#پایان_اگر
		        opindex = 0;
		        اكسر;
		    حالة DW_LNE_define_file: /* deprecated */
		        إذا (++filename_اندازه < FILE_جدول_اندازه) {
		            filename_جدول[filename_اندازه - 1].name = (حرف *)ln - 1;
		            طالما (dwarf_read_1(ln, انتها)) {}
		            filename_جدول[filename_اندازه - 1].dir_مدخل =
		                dwarf_read_uleb128(&ln, انتها);
		        }
		        وإلا {
		            طالما (dwarf_read_1(ln, انتها)) {}
		            dwarf_read_uleb128(&ln, انتها);
		        }
		        dwarf_read_uleb128(&ln, انتها); //زمان
		        dwarf_read_uleb128(&ln, انتها); //اندازه
		        اكسر;
		    حالة DW_LNE_hi_user - 1:
		        function = (حرف *)cp;
		        func_addr = pc;
		        اكسر;
		    افتراضي:
		        اكسر;
		    }
		    اكسر;
	        حالة DW_LNS_advance_pc:
		    إذا (max_ops_در_هر_insn == 1)
		        pc += dwarf_read_uleb128(&ln, انتها) * min_insn_درازی;
		    وإلا {
		        بیعلامت دراز دراز off = dwarf_read_uleb128(&ln, انتها);

		        pc += (opindex + off) / max_ops_در_هر_insn *
			      min_insn_درازی;
		        opindex = (opindex + off) % max_ops_در_هر_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_advance_سطر:
		    سطر += dwarf_read_sleb128(&ln, انتها);
		    اكسر;
	        حالة DW_LNS_مجموعه_file:
		    i = dwarf_read_uleb128(&ln, انتها);
		    i -= i > 0 && نسخه < 5;
		    إذا (i < FILE_جدول_اندازه && i < filename_اندازه)
		        filename = filename_جدول[i].name;
		    اكسر;
	        حالة DW_LNS_const_جمع_کن_pc:
		    إذا (max_ops_در_هر_insn ==  1)
		        pc += ((255 - opcode_پایه) / سطر_range) * min_insn_درازی;
		    وإلا {
		        بیعلامت صحيح off = (255 - opcode_پایه) / سطر_range;

		        pc += ((opindex + off) / max_ops_در_هر_insn) *
			      min_insn_درازی;
		        opindex = (opindex + off) % max_ops_در_هر_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, انتها);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    اذهب check_pc;
	        افتراضي:
		    لكل (j = 0; j < opcode_درازی[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, انتها);
		    اكسر;
		}
	    }
	}
بعدی_سطر:
	ln = انتها;
    }
    filename = function = عدم, func_addr = 0;
یافت:
    إذا (filename)
        pstrcpy(bi->file, حجم bi->file, filename), bi->سطر = سطر;
    إذا (function)
        pstrcpy(bi->func, حجم bi->func, function);
    bi->func_pc = func_addr;
    أرجع (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#اگر_تعریف_نشده CONFIG_TCC_BACKTRACE_ONLY
ساكن
#پایان_اگر
صحيح _tcc_backtrace(rt_قاب *f, ثابت حرف *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    حرف skip[40], پیام[200];
    صحيح i, level, ret, n, one;
    ثابت حرف *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    إذا (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        کپی_حافظه(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    إذا (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(پیام, حجم پیام, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    إذا (rc) {
        إذا (rc->dwarf)
            getinfo = rt_printline_dwarf;
        إذا (rc->رقم_callers)
            n = rc->رقم_callers;
    }

    لكل (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        إذا (ret == -1)
            اكسر;
        memset(&bi, 0, حجم bi);
        لكل (rc2 = rc; rc2; rc2 = rc2->بعدی) {
            إذا (getinfo(rc2, pc, &bi))
                اكسر;
            /* we try symtab symbols (no line number info) */
            إذا (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, حجم bi.func, a);
                اكسر;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        إذا (skip[0] && جستجوی_رشته(bi.file, skip))
            استمر;
#اگر_تعریف_نشده CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_پیدا_کن_state(f);
            إذا (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_داده,
                    (فراغ*)pc,
                    bi.file[0] ? bi.file : عدم,
                    bi.سطر,
                    bi.func[0] ? bi.func : عدم,
                    level == 0 ? پیام : عدم
                    );
                إذا (ret == 0)
                    اكسر;
                اذهب check_break;
            }
        }
#پایان_اگر
        إذا (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.سطر);
        } وإلا {
            rt_printf("0x%08llx", (دراز دراز)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        إذا (level == 0) {
            rt_printf(": %s", پیام);
            إذا (one)
                اكسر;
        }
        rt_printf("\n");

#اگر_تعریف_نشده CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#پایان_اگر
        إذا (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->بالاترین_func)
            اكسر;
        ++level;
    }
    rt_post_sem();
    أرجع 0;
}

/* emit a run time error at position 'pc' */
ساكن صحيح rt_error(rt_قاب *f, ثابت حرف *fmt, ...)
{
    va_list ap; حرف پیام[200]; صحيح ret;
    va_start(ap, fmt);
    snprintf(پیام, حجم پیام, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, پیام, ap);
    va_end(ap);
    أرجع ret;
}

/* ------------------------------------------------------------- */

#اگر_تعریف_نشده _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#وإلا
# define ucontext_t CONTEXT
#پایان_اگر

/* translate from ucontext_t* to internal rt_context * */
ساكن فراغ rt_getcontext(ucontext_t *uc, rt_قاب *rc)
{
#إذا defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#وإلاإذا defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#وإلاإذا defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#وإلاإذا defined __i386__
# إذا defined(__APPLE__)
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
# وإلا
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#وإلاإذا defined(__x86_64__)
# إذا defined(__APPLE__)
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
# وإلا
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#وإلاإذا defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وإلاإذا defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#وإلاإذا defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وإلاإذا defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#وإلاإذا defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#وإلاإذا defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#وإلاإذا defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وإلاإذا defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#وإلاإذا defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#وإلاإذا defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#وإلاإذا defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#پایان_اگر
}

/* ------------------------------------------------------------- */
#اگر_تعریف_نشده _WIN32
/* signal handler for fatal errors */
ساكن فراغ sig_error(صحيح signum, siginfo_t *siginf, فراغ *puc)
{
    rt_قاب f;
    rt_getcontext(puc, &f);

    بدل(signum) {
    حالة SIGFPE:
        بدل(siginf->si_code) {
        حالة FPE_INTDIV:
        حالة FPE_FLTDIV:
            rt_error(&f, "division by zero");
            اكسر;
        افتراضي:
            rt_error(&f, "floating point exception");
            اكسر;
        }
        اكسر;
    حالة SIGBUS:
    حالة SIGSEGV:
        rt_error(&f, "invalid memory access");
        اكسر;
    حالة SIGILL:
        rt_error(&f, "illegal instruction");
        اكسر;
    حالة SIGABRT:
        rt_error(&f, "abort() called");
        اكسر;
    افتراضي:
        rt_error(&f, "caught signal %d", signum);
        اكسر;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, عدم);
    }
    rt_exit(&f, 255);
}

#اگر_تعریف_نشده SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#پایان_اگر

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ مجموعه_exception_handler(فراغ)
{
    بنية sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#إذا 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#پایان_اگر
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, عدم);
    sigaction(SIGILL, &sigact, عدم);
    sigaction(SIGSEGV, &sigact, عدم);
    sigaction(SIGBUS, &sigact, عدم);
    sigaction(SIGABRT, &sigact, عدم);
#إذا 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ساكن بیعلامت حرف پشته[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = پشته;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, عدم);
    }
#پایان_اگر
}

#وإلا /* WIN32 */

/* signal handler for fatal errors */
ساكن دراز __stdcall cpu_exception_handler(EXCEPTION_اشارهگرها *ex_info)
{
    rt_قاب f;
    بیعلامت کد;
    rt_getcontext(ex_info->Context_رکورد, &f);

    بدل (کد = ex_info->Exception_رکورد->Exception_کد) {
    حالة EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        اكسر;
    حالة EXCEPTION_پشته_سرریز:
        rt_error(&f, "stack overflow");
        اكسر;
    حالة EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        اكسر;
    حالة EXCEPTION_BREAKPOINT:
    حالة EXCEPTION_SINGLE_گام:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        أرجع EXCEPTION_CONTINUE_جستجو;
    افتراضي:
        rt_error(&f, "caught exception %08x", کد);
        اكسر;
    }
    rt_exit(&f, 255);
    أرجع EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ مجموعه_exception_handler(فراغ)
{
#اگر_تعریف_شده _WIN64
    جمع_کن_Vectored_Exception_Handler(1, cpu_exception_handler);
#وإلا
    مجموعه_Unhandled_Exception_Filter(cpu_exception_handler);
#پایان_اگر
}

#پایان_اگر

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#إذا defined(__i386__) || defined(__x86_64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *rc, صحيح level)
{
    إذا (level == 0) {
        *paddr = rc->ip;
    } وإلا {
        addr_t fp = rc->fp;
        طالما (1) {
            إذا (fp < 0x1000)
                أرجع -1;
            إذا (0 == --level)
                اكسر;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    أرجع 0;
}

/* XXX: only supports linux/bsd */
#وإلاإذا defined(__arm__) && !defined(_WIN32)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *rc, صحيح level)
{
    إذا (level == 0) {
        *paddr = rc->ip;
    } وإلا {
        addr_t fp = rc->fp;
        طالما (1) {
            إذا (fp < 0x1000)
                أرجع -1;
            إذا (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    أرجع 0;
}

#وإلاإذا defined(__aarch64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *rc, صحيح level)
{
    إذا (level == 0) {
        *paddr = rc->ip;
    } وإلا {
        addr_t fp = rc->fp;
        طالما (1) {
            إذا (fp < 0x1000)
                أرجع -1;
            إذا (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    أرجع 0;
}

#وإلاإذا defined(__riscv)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *rc, صحيح level)
{
    إذا (level == 0) {
        *paddr = rc->ip;
    } وإلا {
        addr_t fp = rc->fp;
        طالما (1) {
            إذا (fp < 0x1000)
                أرجع -1;
            إذا (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    أرجع 0;
}

#وإلا
#warning جمع_کن arch specific rt_get_caller_pc()
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *rc, صحيح level)
{
    أرجع -1;
}

#پایان_اگر
#وإلا // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_قاب *f, صحيح level)
{
    إذا (level)
        أرجع -1;
    *paddr = f->ip;
    أرجع 0;
}
#پایان_اگر /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#اگر_تعریف_شده CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag)
{
    أرجع عدم;
}

ST_FUNC فراغ dlclose(فراغ *p)
{
}

ST_FUNC ثابت حرف *dlerror(فراغ)
{
    أرجع "error";
}

تعريفنوع بنية TCCSyms {
    حرف *str;
    فراغ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ساكن TCCSyms tcc_syms[] = {
#إذا !defined(CONFIG_TCCBOOT)
#تعریف_کن TCCSYM(a) { #a, &a, },
    TCCSYM(چاپ_کن)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#لغو_تعریف TCCSYM
#پایان_اگر
    { عدم, عدم },
};

ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *نماد)
{
    TCCSyms *p;
    p = tcc_syms;
    طالما (p->str != عدم) {
        إذا (!strcmp(p->str, نماد))
            أرجع p->ptr;
        p++;
    }
    أرجع عدم;
}

#پایان_اگر /* CONFIG_TCC_STATIC */
#پایان_اگر /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
