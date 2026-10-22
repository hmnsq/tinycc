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
#جے_تعریف_شدہ TCC_IS_NATIVE

#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
/* runtime debug info block */
تعريفنوع بنية rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اتحاد {
	بنية {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_سرا;
	    حرف *stab_str;
	};
	بنية {
	    بنانشانی حرف *dwarf_سطر;
	    بنانشانی حرف *dwarf_سطر_سرا;
	    بنانشانی حرف *dwarf_سطر_str;
	};
    };
    ElfW(Sym) *esym_شروع;
    ElfW(Sym) *esym_سرا;
    حرف *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_ادھار;
    فراغ *bounds_شروع;
    فراغ *چوٹی_func;
    بنية rt_context *اگلا;
    // 10 * PTR_SIZE
    صحيح عدد_callers;
    صحيح dwarf;
} rt_context;

/* linked list of rt_contexts */
ساكن rt_context *g_rc;
ساكن صحيح signal_سیٹ;
ساكن فراغ سیٹ_exception_handler(فراغ);
#جے_انت /* def CONFIG_TCC_BACKTRACE */

تعريفنوع بنية rt_چوکھٹا {
    addr_t ip, fp, sp;
} rt_چوکھٹا;

ساكن TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ساكن rt_sem);
ساكن فراغ rt_wait_sem(فراغ) { WAIT_SEM(&rt_sem); }
ساكن فراغ rt_post_sem(فراغ) { POST_SEM(&rt_sem); }
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *f, صحيح level);
ساكن فراغ rt_exit(rt_چوکھٹا *f, صحيح کوڈ);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#جے_بنا_تعریف CONFIG_TCC_BACKTRACE_ONLY

#جے_بنا_تعریف _WIN32
# include <sys/mman.h>
#جے_انت

ساكن صحيح protect_ورقے(فراغ *ptr, بنانشانی لما لمائی, صحيح منوال);
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بنانشانی ptr_diff);
ساكن فراغ st_link(TCCState *s1);
ساكن فراغ st_unlink(TCCState *s1);
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
ساكن صحيح _tcc_backtrace(rt_چوکھٹا *f, ثابت حرف *fmt, va_list ap);
#جے_انت
#جے_تعریف_شدہ _WIN64
ساكن فراغ *win64_جوڑو_function_جدول(TCCState *s1);
ساكن فراغ win64_del_function_جدول(فراغ *);
#جے_انت

#إذا !defined PAGESIZE
# إذا defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# وإلا
#  define PAGESIZE 4096
# endif
#جے_انت

#تعریف_کرو PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#إذا !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#جے_انت

/* use VirtualAlloc() instead of tcc_malloc() */
#إذا defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#جے_انت

ساكن صحيح rt_mem(TCCState *s1, صحيح ناپ)
{
    فراغ *ptr;
    صحيح ptr_diff = 0;
#جے_تعریف_شدہ CONFIG_SELINUX
    /* Using mmap instead of malloc */
    فراغ *prw;
    حرف tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحيح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, ناپ);

    ptr = mmap(عدم, ناپ * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((حرف*)ptr + ناپ, ناپ, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    إذا (ptr == MAP_FAILED || prw == MAP_FAILED)
	أرجع tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (حرف*)prw - (حرف*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    ناپ *= 2;
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(عدم, ناپ, MEM_RESERVE | MEM_COMMIT, ورقہ_READWRITE);
    إذا (!ptr)
        أرجع tcc_error_noabort("tccrun: could not allocate memory");
#وإلا
    ptr = tcc_malloc(ناپ += PAGESIZE); /* one extra page to align malloc memory */
#جے_انت
    s1->لگاتار_ptr = ptr;
    s1->لگاتار_ناپ = ناپ;
    أرجع ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحيح tcc_relocate(TCCState *s1)
{
    صحيح ناپ, ret, ptr_diff;

    إذا (s1->لگاتار_ptr)
        باہر_نکلو(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace)
        tcc_جوڑو_علامت(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#جے_انت
    ناپ = tcc_relocate_ex(s1, عدم, 0);
    إذا (ناپ < 0)
        أرجع -1;
    ptr_diff = rt_mem(s1, ناپ);
    إذا (ptr_diff < 0)
        أرجع -1;
    ret = tcc_relocate_ex(s1, s1->لگاتار_ptr, ptr_diff);
    إذا (ret == 0)
        st_link(s1);
    أرجع ret;
}

ST_FUNC فراغ tcc_لگاتار_free(TCCState *s1)
{
    بنانشانی ناپ;
    فراغ *ptr;
    صحيح i;

    /* free any loaded DLLs */
    لكل ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        إذا ( ref->handle )
#جے_تعریف_شدہ _WIN32
            FreeLibrary((HMODULE)ref->handle);
#وإلا
            dlclose(ref->handle);
#جے_انت
    }
    /* unmap or unprotect and free memory */
    ptr = s1->لگاتار_ptr;
    إذا (عدم == ptr)
        أرجع;
    st_unlink(s1);
#جے_تعریف_شدہ _WIN64
    win64_del_function_جدول(s1->لگاتار_function_جدول);
#جے_انت
    ناپ = s1->لگاتار_ناپ;
#جے_تعریف_شدہ CONFIG_SELINUX
    munmap(ptr, ناپ);
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, ناپ, MEM_RELEASE);
#وإلا
    /* unprotect memory to make it usable for malloc again */
    protect_ورقے((فراغ*)PAGEALIGN(ptr), ناپ - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#جے_انت
}

#تعریف_کرو RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحيح tcc_لگاتار(TCCState *s1, صحيح argc, حرف **argv)
{
    صحيح (*prog_main)(صحيح, حرف **, حرف **), ret;
    ثابت حرف *چوٹی_sym;
    jmp_buf main_jb;

#إذا defined(__APPLE__)
    خارجي حرف ***_NSGetEnviron(فراغ);
    حرف **envp = *_NSGetEnviron();
#وإلاإذا defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    خارجي حرف **environ;
    حرف **envp = environ;
#وإلا
    حرف **envp = environ;
#جے_انت

    /* tcc -dt -run ... nothing to do if no main() */
    إذا ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        أرجع 0;

    tcc_جوڑو_علامت(s1, "__rt_exit", rt_exit);
    s1->لگاتار_main = "_runmain", چوٹی_sym = "main";
    إذا (s1->elf_entryname)
        s1->لگاتار_main = چوٹی_sym = s1->elf_entryname;
    tcc_جوڑو_support(s1, "runmain.o");

    إذا (tcc_relocate(s1) < 0)
        أرجع -1;

    prog_main = (فراغ*)get_sym_addr(s1, s1->لگاتار_main, 1, 1);
    إذا ((addr_t)-1 == (addr_t)prog_main)
        أرجع -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    إذا (s1->لگاتار_stdin && !freopen(s1->لگاتار_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->لگاتار_stdin);
        أرجع -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_علامت(s1, چوٹی_sym));
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
    صحيح sym_اشاریہ, سرا_sym = s->انکڑے_وتھ / حجم (ElfSym);
    /* reset symtab */
    s->انکڑے_وتھ = s->link->انکڑے_وتھ = s->hash->انکڑے_وتھ = 0;
    init_symtab(s);
    /* add global symbols again */
    لكل (sym_اشاریہ = 1; sym_اشاریہ < سرا_sym; ++sym_اشاریہ) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->انکڑے)[sym_اشاریہ];
        ثابت حرف *name = (حرف *)s->link->انکڑے + sym->st_name;
        إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            استمر;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_قدر, sym->st_ناپ, sym->st_info, sym->st_other, sym->st_shndx, name);
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
                s->انکڑے = tcc_realloc(s->انکڑے, s->انکڑے_allocated = s->انکڑے_وتھ);
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

#جے_بنا_تعریف CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# وإلا
#   define CONFIG_RUNMEM_RO 0
#  endif
#جے_انت

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بنانشانی ptr_diff)
{
    Section *s;
    بنانشانی وتھ, لمائی, align, i, k, f;
    بنانشانی n, copy;
    addr_t mem, addr;

    إذا (عدم == ptr) {
        s1->nb_errors = 0;
#جے_تعریف_شدہ TCC_نشانہ_PE
        pe_output_file(s1, عدم);
#وإلا
        tcc_جوڑو_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#جے_انت
    }

    وتھ = copy = 0;
    mem = (addr_t)ptr;
redo:
    إذا (s1->verbose == 2 && copy)
        لکھو(&"-----------------------------------------------------\n"[PTR_ناپ*2 - 8]);
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
            لمائی = s->انکڑے_وتھ;
            إذا (copy == 2) {
                إذا (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + لمائی;
                استمر;
            }
            إذا (copy) { /* final step: copy section data to memory */
                إذا (s1->verbose == 2)
                    لکھو("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (فراغ*)s->sh_addr, لمائی, s->sh_addralign);
                ptr = (فراغ*)s->sh_addr;
                إذا (k == 0)
                    ptr = (فراغ*)(s->sh_addr + ptr_diff);
                إذا (عدم == s->انکڑے || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, لمائی);
                وإلا
                    حافظہ_نقل(ptr, s->انکڑے, لمائی);
                استمر;
            }

            إذا ((s->sh_flags & SHF_TLS) && لمائی)
                أرجع tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            إذا (++n == 1) {
#إذا defined TCC_نشانہ_I386 || defined TCC_نشانہ_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                إذا (align < 64)
                    align = 64;
#جے_انت
                /* start new page for different permissions */
                إذا (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            وتھ += -(addr + وتھ) & (align - 1);
            s->sh_addr = mem ? addr + وتھ : 0;
            وتھ += لمائی;
        }
        إذا (copy == 2) { /* set permissions */
            إذا (n == 0) /* no data  */
                استمر;
#جے_تعریف_شدہ CONFIG_SELINUX
            إذا (k == 0) /* SHF_EXECINSTR has its own mapping */
                استمر;
#جے_انت
            f = k;
            إذا (f >= CONFIG_RUNMEM_RO) {
                إذا (f != 0)
                    استمر;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            إذا (s1->verbose == 2) {
                لکھو("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (فراغ*)addr, (بنانشانی)n);
            }
            إذا (protect_ورقے((فراغ*)addr, n, f) < 0)
                أرجع tcc_error_noabort(
#جے_تعریف_شدہ _WIN32
                    "VirtualProtect failed");
#وإلا
                    "mprotect failed (did you mean to configure --with-selinux?)");
#جے_انت
        }
    }

    إذا (0 == mem)
        أرجع PAGEALIGN(وتھ);

    إذا (++copy == 2) {
        اذهب redo;
    }
    إذا (copy == 3) {
#جے_تعریف_شدہ _WIN64
        s1->لگاتار_function_جدول = win64_جوڑو_function_جدول(s1);
#جے_انت
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
#جے_تعریف_شدہ TCC_نشانہ_PE
    s1->pe_imagebase = mem;
#وإلا
    relocate_plt(s1);
#جے_انت
    relocate_sections(s1);
    اذهب redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ساكن صحيح protect_ورقے(فراغ *ptr, بنانشانی لما لمائی, صحيح منوال)
{
#جے_تعریف_شدہ _WIN32
    ساكن ثابت بنانشانی حرف protect[] = {
        ورقہ_EXECUTE_READ,
        ورقہ_READONLY,
        ورقہ_READWRITE,
        ورقہ_EXECUTE_READWRITE
        };
    DWORD old;
    إذا (!VirtualProtect(ptr, لمائی, protect[منوال], &old))
        أرجع -1;
#وإلا
    ساكن ثابت بنانشانی حرف protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    إذا (mprotect(ptr, لمائی, protect[منوال]))
        أرجع -1;
#جے_انت
/* XXX: BSD sometimes dump core with bad system call */
#إذا (defined TCC_نشانہ_ARM && !TARGETOS_BSD) \
    || defined TCC_نشانہ_ARM64 || defined TCC_نشانہ_RISCV64
    إذا (منوال == 0 || منوال == 3) {
#جے_تعریف_شدہ _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, لمائی);
#وإلا
        فراغ __clear_cache(فراغ *beginning, فراغ *سرا);
        __clear_cache(ptr, (حرف *)ptr + لمائی);
#جے_انت
    }
#جے_انت
    أرجع 0;
}

#جے_تعریف_شدہ _WIN64
ساكن فراغ *win64_جوڑو_function_جدول(TCCState *s1)
{
    فراغ *p = عدم;
    إذا (s1->uw_pdata) {
        p = (فراغ*)s1->uw_pdata->sh_addr;
        Rtl_جوڑو_Function_جدول(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->انکڑے_وتھ / حجم (RUNTIME_FUNCTION),
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
#جے_انت

ساكن فراغ bt_link(TCCState *s1)
{
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    rt_context *rc;
    إذا (!s1->do_backtrace)
        أرجع;
    rc = tcc_get_علامت(s1, "__rt_info");
    إذا (!rc)
        أرجع;
    rc->esym_شروع = (ElfW(Sym) *)(symtab_section->انکڑے);
    rc->esym_سرا = (ElfW(Sym) *)(symtab_section->انکڑے + symtab_section->انکڑے_وتھ);
    rc->elf_str = (حرف *)symtab_section->link->انکڑے;
    إذا (PTR_ناپ == 8 && !s1->dwarf)
        rc->prog_ادھار &= 0xffffffff00000000ULL;
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check) {
        فراغ *p;
        إذا ((p = tcc_get_علامت(s1, "__bound_init")))
            ((فراغ(*)(فراغ*,صحيح))p)(rc->bounds_شروع, 1);
    }
#جے_انت
    rc->اگلا = g_rc, g_rc = rc, s1->rc = rc;
    إذا (0 == signal_سیٹ)
        سیٹ_exception_handler(), signal_سیٹ = 1;
#جے_انت
}

ساكن فراغ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->اگلا = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ساكن فراغ ptr_unlink(فراغ *list, فراغ *e, بنانشانی اگلا)
{
    فراغ **pp, **nn, *p;
    لكل (pp = list; !!(p = *pp); pp = nn) {
        nn = (فراغ*)((حرف*)p + اگلا); /* nn = &p->next; */
        إذا (p == e) {
            *pp = *nn;
            اكسر;
        }
    }
}

ساكن فراغ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, اگلا));
#جے_انت
    ptr_unlink(&g_s1, s1, offsetof(TCCState, اگلا));
    rt_post_sem();
}

LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *p_jmp_buf, فراغ *func, فراغ *p_longjmp)
{
    s1->لگاتار_lj = p_longjmp;
    s1->لگاتار_jb = p_jmp_buf;
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE
    إذا (s1->rc)
        s1->rc->چوٹی_func = func;
#جے_انت
    أرجع p_jmp_buf;
}

LIBTCCAPI فراغ tcc_سیٹ_backtrace_func(TCCState *s1, فراغ *انکڑے, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_انکڑے = انکڑے;
}

ساكن TCCState *rt_لبھو_state(rt_چوکھٹا *f)
{
    TCCState *s;
    صحيح level;
    addr_t pc;

    s = g_s1;
    إذا (عدم == s || عدم == s->اگلا) {
        /* play it safe in the simple case when there is only one state */
        أرجع s;
    }
    لكل (level = 0; level < 8; ++level) {
        إذا (rt_get_caller_pc(&pc, f, level) < 0)
            اكسر;
        لكل (s = g_s1; s; s = s->اگلا) {
            إذا (pc >= (addr_t)s->لگاتار_ptr
             && pc  < (addr_t)s->لگاتار_ptr + s->لگاتار_ناپ)
                أرجع s;
        }
    }
    أرجع عدم;
}

ساكن فراغ rt_exit(rt_چوکھٹا *f, صحيح کوڈ)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_لبھو_state(f);
    rt_post_sem();
    إذا (s && s->لگاتار_lj) {
#جے_تعریف_شدہ CONFIG_TCC_BCHECK
        إذا (f->fp) { /* called from signal */
            فراغ *p = tcc_get_علامت(s, "__bound_exit");
            إذا (p)
                ((فراغ (*)(فراغ))p)();
        }
#جے_انت
        إذا (کوڈ == 0)
            کوڈ = RT_EXIT_ZERO;
        ((فراغ(*)(فراغ*,صحيح))s->لگاتار_lj)(s->لگاتار_jb, کوڈ);
    }
    باہر_نکلو(کوڈ);
}

/* ------------------------------------------------------------- */
#وإلا // if defined CONFIG_TCC_BACKTRACE_ONLY
ساكن فراغ rt_exit(rt_چوکھٹا *f, صحيح کوڈ)
{
    باہر_نکلو(کوڈ);
}
#جے_انت //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#جے_تعریف_شدہ CONFIG_TCC_BACKTRACE

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
    لكل (esym = rc->esym_شروع + 1; esym < rc->esym_سرا; ++esym) {
        صحيح type = ELFW(ST_TYPE)(esym->st_info);
        إذا ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_قدر
            && wanted_pc < esym->st_قدر + esym->st_ناپ) {
            *func_addr = esym->st_قدر;
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
    addr_t func_addr, آخری_pc, pc;
    ثابت حرف *incl_files[INCLUDE_ڈھیر_ناپ];
    صحيح incl_اشاریہ, آخری_incl_اشاریہ, len, آخری_سطر_عدد, i;
    ثابت حرف *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_اشاریہ = 0;
    آخری_pc = (addr_t)-1;
    آخری_سطر_عدد = 1;
    آخری_incl_اشاریہ = 0;

    لكل (sym = rc->stab_sym + 1; sym < rc->stab_sym_سرا; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_قدر;

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
#إذا PTR_ناپ == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_ادھار;
#جے_انت
            اذهب check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            إذا (pc >= wanted_pc && wanted_pc >= آخری_pc)
                اذهب لبھیا;
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
            آخری_pc = pc;
            آخری_سطر_عدد = sym->n_desc;
            آخری_incl_اشاریہ = incl_اشاریہ;
            اكسر;
            /* include files */
        حالة N_BINCL:
            إذا (incl_اشاریہ < INCLUDE_ڈھیر_ناپ)
                incl_files[incl_اشاریہ++] = str;
            اكسر;
        حالة N_EINCL:
            إذا (incl_اشاریہ > 1)
                incl_اشاریہ--;
            اكسر;
            /* start/end of translation unit */
        حالة N_SO:
            incl_اشاریہ = 0;
            إذا (sym->n_strx) {
                /* do not add path */
                len = لڑی_لمبائی(str);
                إذا (len > 0 && str[len - 1] != '/')
                    incl_files[incl_اشاریہ++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            آخری_pc = (addr_t)-1;
            اكسر;
            /* alternative file name (from #line or #include directives) */
        حالة N_SOL:
            إذا (incl_اشاریہ)
                incl_files[incl_اشاریہ-1] = str;
            اكسر;
        }
    }
    آخری_incl_اشاریہ = 0, func_name[0] = 0, func_addr = 0;
لبھیا:
    i = آخری_incl_اشاریہ;
    إذا (i > 0) {
        pstrcpy(bi->file, حجم bi->file, incl_files[--i]);
        bi->سطر = آخری_سطر_عدد;
    }
    pstrcpy(bi->func, حجم bi->func, func_name);
    bi->func_pc = func_addr;
    أرجع func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#تعریف_کرو DIR_جدول_ناپ	(64)
#تعریف_کرو FILE_جدول_ناپ	(512)

#تعریف_کرو	dwarf_ignore_type(ln, سرا) /* timestamp/size/md5/... */ \
	بدل (اندراج_format[j].form) { \
	حالة DW_FORM_data1: (ln) += 1; اكسر; \
	حالة DW_FORM_data2: (ln) += 2; اكسر; \
	حالة DW_FORM_data4: (ln) += 3; اكسر; \
	حالة DW_FORM_data8: (ln) += 8; اكسر; \
	حالة DW_FORM_data16: (ln) += 16; اكسر; \
	حالة DW_FORM_udata: dwarf_read_uleb128(&(ln), (سرا)); اكسر; \
	افتراضي: اذهب اگلا_سطر; \
	}

ساكن addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    بنانشانی حرف *ln;
    بنانشانی حرف *cp;
    بنانشانی حرف *سرا;
    بنانشانی حرف *opcode_لمائی;
    بنانشانی لما لما ناپ;
    بنانشانی صحيح لمائی;
    بنانشانی حرف نسخہ;
    بنانشانی صحيح min_insn_لمائی;
    بنانشانی صحيح max_ops_فی_insn;
    صحيح سطر_ادھار;
    بنانشانی صحيح سطر_range;
    بنانشانی صحيح opcode_ادھار;
    بنانشانی صحيح opindex;
    بنانشانی صحيح خانہ;
    بنانشانی صحيح i;
    بنانشانی صحيح j;
    بنانشانی صحيح len;
    بنانشانی لما لما قدر;
    بنية {
	بنانشانی صحيح type;
	بنانشانی صحيح form;
    } اندراج_format[256];
    بنانشانی صحيح dir_ناپ;
#إذا 0
    حرف *dirs[DIR_جدول_ناپ];
#جے_انت
    بنانشانی صحيح filename_ناپ;
    بنية /*dwarf_filename_struct*/ {
        بنانشانی صحيح dir_اندراج;
        حرف *name;
    } filename_جدول[FILE_جدول_ناپ];
    addr_t آخری_pc;
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
    طالما (ln < rc->dwarf_سطر_سرا) {
	dir_ناپ = 0;
	filename_ناپ = 0;
        آخری_pc = 0;
        pc = 0;
        func_addr = 0;
        سطر = 1;
        filename = عدم;
        function = عدم;
	لمائی = 4;
	ناپ = dwarf_read_4(ln, rc->dwarf_سطر_سرا);
	إذا (ناپ == 0xffffffffu) // dwarf 64
	    لمائی = 8, ناپ = dwarf_read_8(ln, rc->dwarf_سطر_سرا);
	سرا = ln + ناپ;
	إذا (سرا < ln || سرا > rc->dwarf_سطر_سرا)
	    اكسر;
	نسخہ = dwarf_read_2(ln, سرا);
	إذا (نسخہ >= 5)
	    ln += لمائی + 2; // address size, segment selector, prologue Length
	وإلا
	    ln += لمائی; // prologue Length
	min_insn_لمائی = dwarf_read_1(ln, سرا);
	إذا (نسخہ >= 4)
	    max_ops_فی_insn = dwarf_read_1(ln, سرا);
	وإلا
	    max_ops_فی_insn = 1;
	ln++; // Initial value of 'is_stmt'
	سطر_ادھار = dwarf_read_1(ln, سرا);
	سطر_ادھار |= سطر_ادھار >= 0x80 ? ~0xff : 0;
	سطر_range = dwarf_read_1(ln, سرا);
	opcode_ادھار = dwarf_read_1(ln, سرا);
	opcode_لمائی = ln;
	ln += opcode_ادھار - 1;
	opindex = 0;
	إذا (نسخہ >= 5) {
	    خانہ = dwarf_read_1(ln, سرا);
	    لكل (i = 0; i < خانہ; i++) {
	        اندراج_format[i].type = dwarf_read_uleb128(&ln, سرا);
	        اندراج_format[i].form = dwarf_read_uleb128(&ln, سرا);
	    }
	    dir_ناپ = dwarf_read_uleb128(&ln, سرا);
	    لكل (i = 0; i < dir_ناپ; i++) {
		لكل (j = 0; j < خانہ; j++) {
		    إذا (اندراج_format[j].type == DW_LNCT_رستہ) {
		        إذا (اندراج_format[j].form != DW_FORM_سطر_strp)
			    اذهب اگلا_سطر;
#إذا 0
		        قدر = لمائی == 4 ? dwarf_read_4(ln, سرا)
					    : dwarf_read_8(ln, سرا);
		        إذا (i < DIR_جدول_ناپ)
		            dirs[i] = (حرف *)rc->dwarf_سطر_str + قدر;
#وإلا
			لمائی == 4 ? dwarf_read_4(ln, سرا)
				    : dwarf_read_8(ln, سرا);
#جے_انت
		    }
		    وإلا 
			dwarf_ignore_type(ln, سرا);
		}
	    }
	    خانہ = dwarf_read_1(ln, سرا);
	    لكل (i = 0; i < خانہ; i++) {
	        اندراج_format[i].type = dwarf_read_uleb128(&ln, سرا);
	        اندراج_format[i].form = dwarf_read_uleb128(&ln, سرا);
	    }
	    filename_ناپ = dwarf_read_uleb128(&ln, سرا);
	    لكل (i = 0; i < filename_ناپ; i++)
		لكل (j = 0; j < خانہ; j++) {
		    إذا (اندراج_format[j].type == DW_LNCT_رستہ) {
			إذا (اندراج_format[j].form != DW_FORM_سطر_strp)
			    اذهب اگلا_سطر;
			قدر = لمائی == 4 ? dwarf_read_4(ln, سرا)
					    : dwarf_read_8(ln, سرا);
		        إذا (i < FILE_جدول_ناپ)
		            filename_جدول[i].name =
				(حرف *)rc->dwarf_سطر_str + قدر;
	            }
		    وإلا إذا (اندراج_format[j].type == DW_LNCT_directory_اشاریہ) {
			بدل (اندراج_format[j].form) {
			حالة DW_FORM_data1: قدر = dwarf_read_1(ln, سرا); اكسر;
			حالة DW_FORM_data2: قدر = dwarf_read_2(ln, سرا); اكسر;
			حالة DW_FORM_data4: قدر = dwarf_read_4(ln, سرا); اكسر;
			حالة DW_FORM_udata: قدر = dwarf_read_uleb128(&ln, سرا); اكسر;
			افتراضي: اذهب اگلا_سطر;
			}
		        إذا (i < FILE_جدول_ناپ)
		            filename_جدول[i].dir_اندراج = قدر;
		    }
		    وإلا 
			dwarf_ignore_type(ln, سرا);
	    }
	}
	وإلا {
	    طالما ((dwarf_read_1(ln, سرا))) {
#إذا 0
		إذا (++dir_ناپ < DIR_جدول_ناپ)
		    dirs[dir_ناپ - 1] = (حرف *)ln - 1;
#جے_انت
		طالما (dwarf_read_1(ln, سرا)) {}
	    }
	    طالما ((dwarf_read_1(ln, سرا))) {
		إذا (++filename_ناپ < FILE_جدول_ناپ) {
		    filename_جدول[filename_ناپ - 1].name = (حرف *)ln - 1;
		    طالما (dwarf_read_1(ln, سرا)) {}
		    filename_جدول[filename_ناپ - 1].dir_اندراج =
		        dwarf_read_uleb128(&ln, سرا);
		}
		وإلا {
		    طالما (dwarf_read_1(ln, سرا)) {}
		    dwarf_read_uleb128(&ln, سرا);
		}
		dwarf_read_uleb128(&ln, سرا); //ویلا
		dwarf_read_uleb128(&ln, سرا); //ناپ
	    }
	}
	إذا (filename_ناپ >= 1)
	    filename = filename_جدول[0].name;
	طالما (ln < سرا) {
	    آخری_pc = pc;
	    i = dwarf_read_1(ln, سرا);
	    إذا (i >= opcode_ادھار) {
	        إذا (max_ops_فی_insn == 1)
		    pc += ((i - opcode_ادھار) / سطر_range) * min_insn_لمائی;
		وإلا {
		    pc += (opindex + (i - opcode_ادھار) / سطر_range) /
			  max_ops_فی_insn * min_insn_لمائی;
		    opindex = (opindex + (i - opcode_ادھار) / سطر_range) %
			       max_ops_فی_insn;
		}
		i = (صحيح)((i - opcode_ادھار) % سطر_range) + سطر_ادھار;
check_pc:
		إذا (pc >= wanted_pc && wanted_pc >= آخری_pc)
		    اذهب لبھیا;
		سطر += i;
	    }
	    وإلا {
	        بدل (i) {
	        حالة 0:
		    len = dwarf_read_uleb128(&ln, سرا);
		    cp = ln;
		    ln += len;
		    إذا (len == 0)
		        اذهب اگلا_سطر;
		    بدل (dwarf_read_1(cp, سرا)) {
		    حالة DW_LNE_سرا_sequence:
		        اكسر;
		    حالة DW_LNE_سیٹ_پتہ:
#إذا PTR_ناپ == 4
		        pc = dwarf_read_4(cp, سرا);
#وإلا
		        pc = dwarf_read_8(cp, سرا);
#جے_انت
#إذا defined TCC_نشانہ_MACHO
			pc += rc->prog_ادھار;
#جے_انت
		        opindex = 0;
		        اكسر;
		    حالة DW_LNE_define_file: /* deprecated */
		        إذا (++filename_ناپ < FILE_جدول_ناپ) {
		            filename_جدول[filename_ناپ - 1].name = (حرف *)ln - 1;
		            طالما (dwarf_read_1(ln, سرا)) {}
		            filename_جدول[filename_ناپ - 1].dir_اندراج =
		                dwarf_read_uleb128(&ln, سرا);
		        }
		        وإلا {
		            طالما (dwarf_read_1(ln, سرا)) {}
		            dwarf_read_uleb128(&ln, سرا);
		        }
		        dwarf_read_uleb128(&ln, سرا); //ویلا
		        dwarf_read_uleb128(&ln, سرا); //ناپ
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
		    إذا (max_ops_فی_insn == 1)
		        pc += dwarf_read_uleb128(&ln, سرا) * min_insn_لمائی;
		    وإلا {
		        بنانشانی لما لما off = dwarf_read_uleb128(&ln, سرا);

		        pc += (opindex + off) / max_ops_فی_insn *
			      min_insn_لمائی;
		        opindex = (opindex + off) % max_ops_فی_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_advance_سطر:
		    سطر += dwarf_read_sleb128(&ln, سرا);
		    اكسر;
	        حالة DW_LNS_سیٹ_file:
		    i = dwarf_read_uleb128(&ln, سرا);
		    i -= i > 0 && نسخہ < 5;
		    إذا (i < FILE_جدول_ناپ && i < filename_ناپ)
		        filename = filename_جدول[i].name;
		    اكسر;
	        حالة DW_LNS_const_جوڑو_pc:
		    إذا (max_ops_فی_insn ==  1)
		        pc += ((255 - opcode_ادھار) / سطر_range) * min_insn_لمائی;
		    وإلا {
		        بنانشانی صحيح off = (255 - opcode_ادھار) / سطر_range;

		        pc += ((opindex + off) / max_ops_فی_insn) *
			      min_insn_لمائی;
		        opindex = (opindex + off) % max_ops_فی_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, سرا);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    اذهب check_pc;
	        افتراضي:
		    لكل (j = 0; j < opcode_لمائی[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, سرا);
		    اكسر;
		}
	    }
	}
اگلا_سطر:
	ln = سرا;
    }
    filename = function = عدم, func_addr = 0;
لبھیا:
    إذا (filename)
        pstrcpy(bi->file, حجم bi->file, filename), bi->سطر = سطر;
    إذا (function)
        pstrcpy(bi->func, حجم bi->func, function);
    bi->func_pc = func_addr;
    أرجع (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#جے_بنا_تعریف CONFIG_TCC_BACKTRACE_ONLY
ساكن
#جے_انت
صحيح _tcc_backtrace(rt_چوکھٹا *f, ثابت حرف *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    حرف skip[40], پیغام[200];
    صحيح i, level, ret, n, one;
    ثابت حرف *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    إذا (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        حافظہ_نقل(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    إذا (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(پیغام, حجم پیغام, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    إذا (rc) {
        إذا (rc->dwarf)
            getinfo = rt_printline_dwarf;
        إذا (rc->عدد_callers)
            n = rc->عدد_callers;
    }

    لكل (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        إذا (ret == -1)
            اكسر;
        memset(&bi, 0, حجم bi);
        لكل (rc2 = rc; rc2; rc2 = rc2->اگلا) {
            إذا (getinfo(rc2, pc, &bi))
                اكسر;
            /* we try symtab symbols (no line number info) */
            إذا (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, حجم bi.func, a);
                اكسر;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        إذا (skip[0] && لڑی_کھوج(bi.file, skip))
            استمر;
#جے_بنا_تعریف CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_لبھو_state(f);
            إذا (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_انکڑے,
                    (فراغ*)pc,
                    bi.file[0] ? bi.file : عدم,
                    bi.سطر,
                    bi.func[0] ? bi.func : عدم,
                    level == 0 ? پیغام : عدم
                    );
                إذا (ret == 0)
                    اكسر;
                اذهب check_break;
            }
        }
#جے_انت
        إذا (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.سطر);
        } وإلا {
            rt_printf("0x%08llx", (لما لما)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        إذا (level == 0) {
            rt_printf(": %s", پیغام);
            إذا (one)
                اكسر;
        }
        rt_printf("\n");

#جے_بنا_تعریف CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#جے_انت
        إذا (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->چوٹی_func)
            اكسر;
        ++level;
    }
    rt_post_sem();
    أرجع 0;
}

/* emit a run time error at position 'pc' */
ساكن صحيح rt_error(rt_چوکھٹا *f, ثابت حرف *fmt, ...)
{
    va_list ap; حرف پیغام[200]; صحيح ret;
    va_start(ap, fmt);
    snprintf(پیغام, حجم پیغام, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, پیغام, ap);
    va_end(ap);
    أرجع ret;
}

/* ------------------------------------------------------------- */

#جے_بنا_تعریف _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#وإلا
# define ucontext_t CONTEXT
#جے_انت

/* translate from ucontext_t* to internal rt_context * */
ساكن فراغ rt_getcontext(ucontext_t *uc, rt_چوکھٹا *rc)
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
#جے_انت
}

/* ------------------------------------------------------------- */
#جے_بنا_تعریف _WIN32
/* signal handler for fatal errors */
ساكن فراغ sig_error(صحيح signum, siginfo_t *siginf, فراغ *puc)
{
    rt_چوکھٹا f;
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

#جے_بنا_تعریف SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#جے_انت

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ سیٹ_exception_handler(فراغ)
{
    بنية sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#إذا 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#جے_انت
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
        ساكن بنانشانی حرف ڈھیر[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ڈھیر;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, عدم);
    }
#جے_انت
}

#وإلا /* WIN32 */

/* signal handler for fatal errors */
ساكن لما __stdcall cpu_exception_handler(EXCEPTION_سوچکاں *ex_info)
{
    rt_چوکھٹا f;
    بنانشانی کوڈ;
    rt_getcontext(ex_info->Context_ریکارڈ, &f);

    بدل (کوڈ = ex_info->Exception_ریکارڈ->Exception_کوڈ) {
    حالة EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        اكسر;
    حالة EXCEPTION_ڈھیر_حد_توں_ودھ:
        rt_error(&f, "stack overflow");
        اكسر;
    حالة EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        اكسر;
    حالة EXCEPTION_BREAKPOINT:
    حالة EXCEPTION_SINGLE_قدم:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        أرجع EXCEPTION_CONTINUE_تلاش;
    افتراضي:
        rt_error(&f, "caught exception %08x", کوڈ);
        اكسر;
    }
    rt_exit(&f, 255);
    أرجع EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ سیٹ_exception_handler(فراغ)
{
#جے_تعریف_شدہ _WIN64
    جوڑو_Vectored_Exception_Handler(1, cpu_exception_handler);
#وإلا
    سیٹ_Unhandled_Exception_Filter(cpu_exception_handler);
#جے_انت
}

#جے_انت

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#إذا defined(__i386__) || defined(__x86_64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحيح level)
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
#warning جوڑو arch specific rt_get_caller_pc()
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *rc, صحيح level)
{
    أرجع -1;
}

#جے_انت
#وإلا // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکھٹا *f, صحيح level)
{
    إذا (level)
        أرجع -1;
    *paddr = f->ip;
    أرجع 0;
}
#جے_انت /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#جے_تعریف_شدہ CONFIG_TCC_STATIC

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
#تعریف_کرو TCCSYM(a) { #a, &a, },
    TCCSYM(لکھو)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#تعریف_رد TCCSYM
#جے_انت
    { عدم, عدم },
};

ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *علامت)
{
    TCCSyms *p;
    p = tcc_syms;
    طالما (p->str != عدم) {
        إذا (!strcmp(p->str, علامت))
            أرجع p->ptr;
        p++;
    }
    أرجع عدم;
}

#جے_انت /* CONFIG_TCC_STATIC */
#جے_انت /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
