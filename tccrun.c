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
#جيڪڏهن_وصف_ٿيل TCC_IS_NATIVE

#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
/* runtime debug info block */
تعريفنوع بنية rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اتحاد {
	بنية {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_پڇاڙي;
	    حرف *stab_str;
	};
	بنية {
	    بنانشان حرف *dwarf_سٽ;
	    بنانشان حرف *dwarf_سٽ_پڇاڙي;
	    بنانشان حرف *dwarf_سٽ_str;
	};
    };
    ElfW(Sym) *esym_شروعات;
    ElfW(Sym) *esym_پڇاڙي;
    حرف *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_بنياد;
    فراغ *bounds_شروعات;
    فراغ *چوٽي_func;
    بنية rt_context *ايندڙ;
    // 10 * PTR_SIZE
    صحيح انگ_callers;
    صحيح dwarf;
} rt_context;

/* linked list of rt_contexts */
ساكن rt_context *g_rc;
ساكن صحيح signal_سيٽ;
ساكن فراغ سيٽ_exception_handler(فراغ);
#جيڪڏهن_پورو /* def CONFIG_TCC_BACKTRACE */

تعريفنوع بنية rt_چوکٺو {
    addr_t ip, fp, sp;
} rt_چوکٺو;

ساكن TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ساكن rt_sem);
ساكن فراغ rt_wait_sem(فراغ) { WAIT_SEM(&rt_sem); }
ساكن فراغ rt_post_sem(فراغ) { POST_SEM(&rt_sem); }
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *f, صحيح level);
ساكن فراغ rt_exit(rt_چوکٺو *f, صحيح ڪوڊ);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_BACKTRACE_ONLY

#جيڪڏهن_وصف_نه_ٿيل _WIN32
# include <sys/mman.h>
#جيڪڏهن_پورو

ساكن صحيح protect_صفحا(فراغ *ptr, بنانشان ڊگهو ڊيگهائي, صحيح گهڻائي);
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بنانشان ptr_diff);
ساكن فراغ st_link(TCCState *s1);
ساكن فراغ st_unlink(TCCState *s1);
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
ساكن صحيح _tcc_backtrace(rt_چوکٺو *f, ثابت حرف *fmt, va_list ap);
#جيڪڏهن_پورو
#جيڪڏهن_وصف_ٿيل _WIN64
ساكن فراغ *win64_جوڙيو_function_جدول(TCCState *s1);
ساكن فراغ win64_del_function_جدول(فراغ *);
#جيڪڏهن_پورو

#إذا !defined PAGESIZE
# إذا defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# وإلا
#  define PAGESIZE 4096
# endif
#جيڪڏهن_پورو

#وصف_ڪريو PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#إذا !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#جيڪڏهن_پورو

/* use VirtualAlloc() instead of tcc_malloc() */
#إذا defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#جيڪڏهن_پورو

ساكن صحيح rt_mem(TCCState *s1, صحيح سائيز)
{
    فراغ *ptr;
    صحيح ptr_diff = 0;
#جيڪڏهن_وصف_ٿيل CONFIG_SELINUX
    /* Using mmap instead of malloc */
    فراغ *prw;
    حرف tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحيح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, سائيز);

    ptr = mmap(عدم, سائيز * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((حرف*)ptr + سائيز, سائيز, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    إذا (ptr == MAP_FAILED || prw == MAP_FAILED)
	أرجع tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (حرف*)prw - (حرف*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    سائيز *= 2;
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(عدم, سائيز, MEM_RESERVE | MEM_COMMIT, صفحو_READWRITE);
    إذا (!ptr)
        أرجع tcc_error_noabort("tccrun: could not allocate memory");
#وإلا
    ptr = tcc_malloc(سائيز += PAGESIZE); /* one extra page to align malloc memory */
#جيڪڏهن_پورو
    s1->لاڳيتو_ptr = ptr;
    s1->لاڳيتو_سائيز = سائيز;
    أرجع ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحيح tcc_relocate(TCCState *s1)
{
    صحيح سائيز, ret, ptr_diff;

    إذا (s1->لاڳيتو_ptr)
        ٻاهر_نڪرو(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    إذا (s1->do_backtrace)
        tcc_جوڙيو_نشان(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#جيڪڏهن_پورو
    سائيز = tcc_relocate_ex(s1, عدم, 0);
    إذا (سائيز < 0)
        أرجع -1;
    ptr_diff = rt_mem(s1, سائيز);
    إذا (ptr_diff < 0)
        أرجع -1;
    ret = tcc_relocate_ex(s1, s1->لاڳيتو_ptr, ptr_diff);
    إذا (ret == 0)
        st_link(s1);
    أرجع ret;
}

ST_FUNC فراغ tcc_لاڳيتو_free(TCCState *s1)
{
    بنانشان سائيز;
    فراغ *ptr;
    صحيح i;

    /* free any loaded DLLs */
    لكل ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        إذا ( ref->handle )
#جيڪڏهن_وصف_ٿيل _WIN32
            FreeLibrary((HMODULE)ref->handle);
#وإلا
            dlclose(ref->handle);
#جيڪڏهن_پورو
    }
    /* unmap or unprotect and free memory */
    ptr = s1->لاڳيتو_ptr;
    إذا (عدم == ptr)
        أرجع;
    st_unlink(s1);
#جيڪڏهن_وصف_ٿيل _WIN64
    win64_del_function_جدول(s1->لاڳيتو_function_جدول);
#جيڪڏهن_پورو
    سائيز = s1->لاڳيتو_سائيز;
#جيڪڏهن_وصف_ٿيل CONFIG_SELINUX
    munmap(ptr, سائيز);
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, سائيز, MEM_RELEASE);
#وإلا
    /* unprotect memory to make it usable for malloc again */
    protect_صفحا((فراغ*)PAGEALIGN(ptr), سائيز - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#جيڪڏهن_پورو
}

#وصف_ڪريو RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحيح tcc_لاڳيتو(TCCState *s1, صحيح argc, حرف **argv)
{
    صحيح (*prog_main)(صحيح, حرف **, حرف **), ret;
    ثابت حرف *چوٽي_sym;
    jmp_buf main_jb;

#إذا defined(__APPLE__)
    خارجي حرف ***_NSGetEnviron(فراغ);
    حرف **envp = *_NSGetEnviron();
#وإلاإذا defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    خارجي حرف **environ;
    حرف **envp = environ;
#وإلا
    حرف **envp = environ;
#جيڪڏهن_پورو

    /* tcc -dt -run ... nothing to do if no main() */
    إذا ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        أرجع 0;

    tcc_جوڙيو_نشان(s1, "__rt_exit", rt_exit);
    s1->لاڳيتو_main = "_runmain", چوٽي_sym = "main";
    إذا (s1->elf_entryname)
        s1->لاڳيتو_main = چوٽي_sym = s1->elf_entryname;
    tcc_جوڙيو_support(s1, "runmain.o");

    إذا (tcc_relocate(s1) < 0)
        أرجع -1;

    prog_main = (فراغ*)get_sym_addr(s1, s1->لاڳيتو_main, 1, 1);
    إذا ((addr_t)-1 == (addr_t)prog_main)
        أرجع -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    إذا (s1->لاڳيتو_stdin && !freopen(s1->لاڳيتو_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->لاڳيتو_stdin);
        أرجع -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_نشان(s1, چوٽي_sym));
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
    صحيح sym_اشاريو, پڇاڙي_sym = s->معلومات_وٿي / حجم (ElfSym);
    /* reset symtab */
    s->معلومات_وٿي = s->link->معلومات_وٿي = s->hash->معلومات_وٿي = 0;
    init_symtab(s);
    /* add global symbols again */
    لكل (sym_اشاريو = 1; sym_اشاريو < پڇاڙي_sym; ++sym_اشاريو) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->معلومات)[sym_اشاريو];
        ثابت حرف *name = (حرف *)s->link->معلومات + sym->st_name;
        إذا (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            استمر;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_قدر, sym->st_سائيز, sym->st_info, sym->st_other, sym->st_shndx, name);
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
                s->معلومات = tcc_realloc(s->معلومات, s->معلومات_allocated = s->معلومات_وٿي);
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

#جيڪڏهن_وصف_نه_ٿيل CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# وإلا
#   define CONFIG_RUNMEM_RO 0
#  endif
#جيڪڏهن_پورو

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, بنانشان ptr_diff)
{
    Section *s;
    بنانشان وٿي, ڊيگهائي, align, i, k, f;
    بنانشان n, copy;
    addr_t mem, addr;

    إذا (عدم == ptr) {
        s1->nb_errors = 0;
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
        pe_output_file(s1, عدم);
#وإلا
        tcc_جوڙيو_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#جيڪڏهن_پورو
    }

    وٿي = copy = 0;
    mem = (addr_t)ptr;
redo:
    إذا (s1->verbose == 2 && copy)
        لکو(&"-----------------------------------------------------\n"[PTR_سائيز*2 - 8]);
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
            ڊيگهائي = s->معلومات_وٿي;
            إذا (copy == 2) {
                إذا (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + ڊيگهائي;
                استمر;
            }
            إذا (copy) { /* final step: copy section data to memory */
                إذا (s1->verbose == 2)
                    لکو("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (فراغ*)s->sh_addr, ڊيگهائي, s->sh_addralign);
                ptr = (فراغ*)s->sh_addr;
                إذا (k == 0)
                    ptr = (فراغ*)(s->sh_addr + ptr_diff);
                إذا (عدم == s->معلومات || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, ڊيگهائي);
                وإلا
                    يادگيري_نقل(ptr, s->معلومات, ڊيگهائي);
                استمر;
            }

            إذا ((s->sh_flags & SHF_TLS) && ڊيگهائي)
                أرجع tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            إذا (++n == 1) {
#إذا defined TCC_هدف_I386 || defined TCC_هدف_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                إذا (align < 64)
                    align = 64;
#جيڪڏهن_پورو
                /* start new page for different permissions */
                إذا (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            وٿي += -(addr + وٿي) & (align - 1);
            s->sh_addr = mem ? addr + وٿي : 0;
            وٿي += ڊيگهائي;
        }
        إذا (copy == 2) { /* set permissions */
            إذا (n == 0) /* no data  */
                استمر;
#جيڪڏهن_وصف_ٿيل CONFIG_SELINUX
            إذا (k == 0) /* SHF_EXECINSTR has its own mapping */
                استمر;
#جيڪڏهن_پورو
            f = k;
            إذا (f >= CONFIG_RUNMEM_RO) {
                إذا (f != 0)
                    استمر;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            إذا (s1->verbose == 2) {
                لکو("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (فراغ*)addr, (بنانشان)n);
            }
            إذا (protect_صفحا((فراغ*)addr, n, f) < 0)
                أرجع tcc_error_noabort(
#جيڪڏهن_وصف_ٿيل _WIN32
                    "VirtualProtect failed");
#وإلا
                    "mprotect failed (did you mean to configure --with-selinux?)");
#جيڪڏهن_پورو
        }
    }

    إذا (0 == mem)
        أرجع PAGEALIGN(وٿي);

    إذا (++copy == 2) {
        اذهب redo;
    }
    إذا (copy == 3) {
#جيڪڏهن_وصف_ٿيل _WIN64
        s1->لاڳيتو_function_جدول = win64_جوڙيو_function_جدول(s1);
#جيڪڏهن_پورو
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
#جيڪڏهن_وصف_ٿيل TCC_هدف_PE
    s1->pe_imagebase = mem;
#وإلا
    relocate_plt(s1);
#جيڪڏهن_پورو
    relocate_sections(s1);
    اذهب redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ساكن صحيح protect_صفحا(فراغ *ptr, بنانشان ڊگهو ڊيگهائي, صحيح گهڻائي)
{
#جيڪڏهن_وصف_ٿيل _WIN32
    ساكن ثابت بنانشان حرف protect[] = {
        صفحو_EXECUTE_READ,
        صفحو_READONLY,
        صفحو_READWRITE,
        صفحو_EXECUTE_READWRITE
        };
    DWORD old;
    إذا (!VirtualProtect(ptr, ڊيگهائي, protect[گهڻائي], &old))
        أرجع -1;
#وإلا
    ساكن ثابت بنانشان حرف protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    إذا (mprotect(ptr, ڊيگهائي, protect[گهڻائي]))
        أرجع -1;
#جيڪڏهن_پورو
/* XXX: BSD sometimes dump core with bad system call */
#إذا (defined TCC_هدف_ARM && !TARGETOS_BSD) \
    || defined TCC_هدف_ARM64 || defined TCC_هدف_RISCV64
    إذا (گهڻائي == 0 || گهڻائي == 3) {
#جيڪڏهن_وصف_ٿيل _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, ڊيگهائي);
#وإلا
        فراغ __clear_cache(فراغ *beginning, فراغ *پڇاڙي);
        __clear_cache(ptr, (حرف *)ptr + ڊيگهائي);
#جيڪڏهن_پورو
    }
#جيڪڏهن_پورو
    أرجع 0;
}

#جيڪڏهن_وصف_ٿيل _WIN64
ساكن فراغ *win64_جوڙيو_function_جدول(TCCState *s1)
{
    فراغ *p = عدم;
    إذا (s1->uw_pdata) {
        p = (فراغ*)s1->uw_pdata->sh_addr;
        Rtl_جوڙيو_Function_جدول(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->معلومات_وٿي / حجم (RUNTIME_FUNCTION),
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
#جيڪڏهن_پورو

ساكن فراغ bt_link(TCCState *s1)
{
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    rt_context *rc;
    إذا (!s1->do_backtrace)
        أرجع;
    rc = tcc_get_نشان(s1, "__rt_info");
    إذا (!rc)
        أرجع;
    rc->esym_شروعات = (ElfW(Sym) *)(symtab_section->معلومات);
    rc->esym_پڇاڙي = (ElfW(Sym) *)(symtab_section->معلومات + symtab_section->معلومات_وٿي);
    rc->elf_str = (حرف *)symtab_section->link->معلومات;
    إذا (PTR_سائيز == 8 && !s1->dwarf)
        rc->prog_بنياد &= 0xffffffff00000000ULL;
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
    إذا (s1->do_bounds_check) {
        فراغ *p;
        إذا ((p = tcc_get_نشان(s1, "__bound_init")))
            ((فراغ(*)(فراغ*,صحيح))p)(rc->bounds_شروعات, 1);
    }
#جيڪڏهن_پورو
    rc->ايندڙ = g_rc, g_rc = rc, s1->rc = rc;
    إذا (0 == signal_سيٽ)
        سيٽ_exception_handler(), signal_سيٽ = 1;
#جيڪڏهن_پورو
}

ساكن فراغ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->ايندڙ = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ساكن فراغ ptr_unlink(فراغ *list, فراغ *e, بنانشان ايندڙ)
{
    فراغ **pp, **nn, *p;
    لكل (pp = list; !!(p = *pp); pp = nn) {
        nn = (فراغ*)((حرف*)p + ايندڙ); /* nn = &p->next; */
        إذا (p == e) {
            *pp = *nn;
            اكسر;
        }
    }
}

ساكن فراغ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, ايندڙ));
#جيڪڏهن_پورو
    ptr_unlink(&g_s1, s1, offsetof(TCCState, ايندڙ));
    rt_post_sem();
}

LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *p_jmp_buf, فراغ *func, فراغ *p_longjmp)
{
    s1->لاڳيتو_lj = p_longjmp;
    s1->لاڳيتو_jb = p_jmp_buf;
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE
    إذا (s1->rc)
        s1->rc->چوٽي_func = func;
#جيڪڏهن_پورو
    أرجع p_jmp_buf;
}

LIBTCCAPI فراغ tcc_سيٽ_backtrace_func(TCCState *s1, فراغ *معلومات, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_معلومات = معلومات;
}

ساكن TCCState *rt_ڳوليو_state(rt_چوکٺو *f)
{
    TCCState *s;
    صحيح level;
    addr_t pc;

    s = g_s1;
    إذا (عدم == s || عدم == s->ايندڙ) {
        /* play it safe in the simple case when there is only one state */
        أرجع s;
    }
    لكل (level = 0; level < 8; ++level) {
        إذا (rt_get_caller_pc(&pc, f, level) < 0)
            اكسر;
        لكل (s = g_s1; s; s = s->ايندڙ) {
            إذا (pc >= (addr_t)s->لاڳيتو_ptr
             && pc  < (addr_t)s->لاڳيتو_ptr + s->لاڳيتو_سائيز)
                أرجع s;
        }
    }
    أرجع عدم;
}

ساكن فراغ rt_exit(rt_چوکٺو *f, صحيح ڪوڊ)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_ڳوليو_state(f);
    rt_post_sem();
    إذا (s && s->لاڳيتو_lj) {
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BCHECK
        إذا (f->fp) { /* called from signal */
            فراغ *p = tcc_get_نشان(s, "__bound_exit");
            إذا (p)
                ((فراغ (*)(فراغ))p)();
        }
#جيڪڏهن_پورو
        إذا (ڪوڊ == 0)
            ڪوڊ = RT_EXIT_ZERO;
        ((فراغ(*)(فراغ*,صحيح))s->لاڳيتو_lj)(s->لاڳيتو_jb, ڪوڊ);
    }
    ٻاهر_نڪرو(ڪوڊ);
}

/* ------------------------------------------------------------- */
#وإلا // if defined CONFIG_TCC_BACKTRACE_ONLY
ساكن فراغ rt_exit(rt_چوکٺو *f, صحيح ڪوڊ)
{
    ٻاهر_نڪرو(ڪوڊ);
}
#جيڪڏهن_پورو //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_BACKTRACE

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
    لكل (esym = rc->esym_شروعات + 1; esym < rc->esym_پڇاڙي; ++esym) {
        صحيح type = ELFW(ST_TYPE)(esym->st_info);
        إذا ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_قدر
            && wanted_pc < esym->st_قدر + esym->st_سائيز) {
            *func_addr = esym->st_قدر;
            أرجع rc->elf_str + esym->st_name;
        }
    }
    أرجع عدم;
}

تعريفنوع بنية bt_info
{
    حرف file[100];
    صحيح سٽ;
    حرف func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ساكن addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    حرف func_name[128];
    addr_t func_addr, آخري_pc, pc;
    ثابت حرف *incl_files[INCLUDE_ڍير_سائيز];
    صحيح incl_اشاريو, آخري_incl_اشاريو, len, آخري_سٽ_انگ, i;
    ثابت حرف *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_اشاريو = 0;
    آخري_pc = (addr_t)-1;
    آخري_سٽ_انگ = 1;
    آخري_incl_اشاريو = 0;

    لكل (sym = rc->stab_sym + 1; sym < rc->stab_sym_پڇاڙي; ++sym) {
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
#إذا PTR_سائيز == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_بنياد;
#جيڪڏهن_پورو
            اذهب check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            إذا (pc >= wanted_pc && wanted_pc >= آخري_pc)
                اذهب مليو;
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
            آخري_pc = pc;
            آخري_سٽ_انگ = sym->n_desc;
            آخري_incl_اشاريو = incl_اشاريو;
            اكسر;
            /* include files */
        حالة N_BINCL:
            إذا (incl_اشاريو < INCLUDE_ڍير_سائيز)
                incl_files[incl_اشاريو++] = str;
            اكسر;
        حالة N_EINCL:
            إذا (incl_اشاريو > 1)
                incl_اشاريو--;
            اكسر;
            /* start/end of translation unit */
        حالة N_SO:
            incl_اشاريو = 0;
            إذا (sym->n_strx) {
                /* do not add path */
                len = لڙي_ڊيگهه(str);
                إذا (len > 0 && str[len - 1] != '/')
                    incl_files[incl_اشاريو++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            آخري_pc = (addr_t)-1;
            اكسر;
            /* alternative file name (from #line or #include directives) */
        حالة N_SOL:
            إذا (incl_اشاريو)
                incl_files[incl_اشاريو-1] = str;
            اكسر;
        }
    }
    آخري_incl_اشاريو = 0, func_name[0] = 0, func_addr = 0;
مليو:
    i = آخري_incl_اشاريو;
    إذا (i > 0) {
        pstrcpy(bi->file, حجم bi->file, incl_files[--i]);
        bi->سٽ = آخري_سٽ_انگ;
    }
    pstrcpy(bi->func, حجم bi->func, func_name);
    bi->func_pc = func_addr;
    أرجع func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#وصف_ڪريو DIR_جدول_سائيز	(64)
#وصف_ڪريو FILE_جدول_سائيز	(512)

#وصف_ڪريو	dwarf_ignore_type(ln, پڇاڙي) /* timestamp/size/md5/... */ \
	بدل (داخلا_format[j].form) { \
	حالة DW_FORM_data1: (ln) += 1; اكسر; \
	حالة DW_FORM_data2: (ln) += 2; اكسر; \
	حالة DW_FORM_data4: (ln) += 3; اكسر; \
	حالة DW_FORM_data8: (ln) += 8; اكسر; \
	حالة DW_FORM_data16: (ln) += 16; اكسر; \
	حالة DW_FORM_udata: dwarf_read_uleb128(&(ln), (پڇاڙي)); اكسر; \
	افتراضي: اذهب ايندڙ_سٽ; \
	}

ساكن addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    بنانشان حرف *ln;
    بنانشان حرف *cp;
    بنانشان حرف *پڇاڙي;
    بنانشان حرف *opcode_ڊيگهائي;
    بنانشان ڊگهو ڊگهو سائيز;
    بنانشان صحيح ڊيگهائي;
    بنانشان حرف نسخو;
    بنانشان صحيح min_insn_ڊيگهائي;
    بنانشان صحيح max_ops_في_insn;
    صحيح سٽ_بنياد;
    بنانشان صحيح سٽ_range;
    بنانشان صحيح opcode_بنياد;
    بنانشان صحيح opindex;
    بنانشان صحيح کانو;
    بنانشان صحيح i;
    بنانشان صحيح j;
    بنانشان صحيح len;
    بنانشان ڊگهو ڊگهو قدر;
    بنية {
	بنانشان صحيح type;
	بنانشان صحيح form;
    } داخلا_format[256];
    بنانشان صحيح dir_سائيز;
#إذا 0
    حرف *dirs[DIR_جدول_سائيز];
#جيڪڏهن_پورو
    بنانشان صحيح filename_سائيز;
    بنية /*dwarf_filename_struct*/ {
        بنانشان صحيح dir_داخلا;
        حرف *name;
    } filename_جدول[FILE_جدول_سائيز];
    addr_t آخري_pc;
    addr_t pc;
    addr_t func_addr;
    صحيح سٽ;
    حرف *filename;
    حرف *function;

    filename = عدم;
    function = عدم;
    func_addr = 0;
    سٽ = 0;

    ln = rc->dwarf_سٽ;
    طالما (ln < rc->dwarf_سٽ_پڇاڙي) {
	dir_سائيز = 0;
	filename_سائيز = 0;
        آخري_pc = 0;
        pc = 0;
        func_addr = 0;
        سٽ = 1;
        filename = عدم;
        function = عدم;
	ڊيگهائي = 4;
	سائيز = dwarf_read_4(ln, rc->dwarf_سٽ_پڇاڙي);
	إذا (سائيز == 0xffffffffu) // dwarf 64
	    ڊيگهائي = 8, سائيز = dwarf_read_8(ln, rc->dwarf_سٽ_پڇاڙي);
	پڇاڙي = ln + سائيز;
	إذا (پڇاڙي < ln || پڇاڙي > rc->dwarf_سٽ_پڇاڙي)
	    اكسر;
	نسخو = dwarf_read_2(ln, پڇاڙي);
	إذا (نسخو >= 5)
	    ln += ڊيگهائي + 2; // address size, segment selector, prologue Length
	وإلا
	    ln += ڊيگهائي; // prologue Length
	min_insn_ڊيگهائي = dwarf_read_1(ln, پڇاڙي);
	إذا (نسخو >= 4)
	    max_ops_في_insn = dwarf_read_1(ln, پڇاڙي);
	وإلا
	    max_ops_في_insn = 1;
	ln++; // Initial value of 'is_stmt'
	سٽ_بنياد = dwarf_read_1(ln, پڇاڙي);
	سٽ_بنياد |= سٽ_بنياد >= 0x80 ? ~0xff : 0;
	سٽ_range = dwarf_read_1(ln, پڇاڙي);
	opcode_بنياد = dwarf_read_1(ln, پڇاڙي);
	opcode_ڊيگهائي = ln;
	ln += opcode_بنياد - 1;
	opindex = 0;
	إذا (نسخو >= 5) {
	    کانو = dwarf_read_1(ln, پڇاڙي);
	    لكل (i = 0; i < کانو; i++) {
	        داخلا_format[i].type = dwarf_read_uleb128(&ln, پڇاڙي);
	        داخلا_format[i].form = dwarf_read_uleb128(&ln, پڇاڙي);
	    }
	    dir_سائيز = dwarf_read_uleb128(&ln, پڇاڙي);
	    لكل (i = 0; i < dir_سائيز; i++) {
		لكل (j = 0; j < کانو; j++) {
		    إذا (داخلا_format[j].type == DW_LNCT_رستو) {
		        إذا (داخلا_format[j].form != DW_FORM_سٽ_strp)
			    اذهب ايندڙ_سٽ;
#إذا 0
		        قدر = ڊيگهائي == 4 ? dwarf_read_4(ln, پڇاڙي)
					    : dwarf_read_8(ln, پڇاڙي);
		        إذا (i < DIR_جدول_سائيز)
		            dirs[i] = (حرف *)rc->dwarf_سٽ_str + قدر;
#وإلا
			ڊيگهائي == 4 ? dwarf_read_4(ln, پڇاڙي)
				    : dwarf_read_8(ln, پڇاڙي);
#جيڪڏهن_پورو
		    }
		    وإلا 
			dwarf_ignore_type(ln, پڇاڙي);
		}
	    }
	    کانو = dwarf_read_1(ln, پڇاڙي);
	    لكل (i = 0; i < کانو; i++) {
	        داخلا_format[i].type = dwarf_read_uleb128(&ln, پڇاڙي);
	        داخلا_format[i].form = dwarf_read_uleb128(&ln, پڇاڙي);
	    }
	    filename_سائيز = dwarf_read_uleb128(&ln, پڇاڙي);
	    لكل (i = 0; i < filename_سائيز; i++)
		لكل (j = 0; j < کانو; j++) {
		    إذا (داخلا_format[j].type == DW_LNCT_رستو) {
			إذا (داخلا_format[j].form != DW_FORM_سٽ_strp)
			    اذهب ايندڙ_سٽ;
			قدر = ڊيگهائي == 4 ? dwarf_read_4(ln, پڇاڙي)
					    : dwarf_read_8(ln, پڇاڙي);
		        إذا (i < FILE_جدول_سائيز)
		            filename_جدول[i].name =
				(حرف *)rc->dwarf_سٽ_str + قدر;
	            }
		    وإلا إذا (داخلا_format[j].type == DW_LNCT_directory_اشاريو) {
			بدل (داخلا_format[j].form) {
			حالة DW_FORM_data1: قدر = dwarf_read_1(ln, پڇاڙي); اكسر;
			حالة DW_FORM_data2: قدر = dwarf_read_2(ln, پڇاڙي); اكسر;
			حالة DW_FORM_data4: قدر = dwarf_read_4(ln, پڇاڙي); اكسر;
			حالة DW_FORM_udata: قدر = dwarf_read_uleb128(&ln, پڇاڙي); اكسر;
			افتراضي: اذهب ايندڙ_سٽ;
			}
		        إذا (i < FILE_جدول_سائيز)
		            filename_جدول[i].dir_داخلا = قدر;
		    }
		    وإلا 
			dwarf_ignore_type(ln, پڇاڙي);
	    }
	}
	وإلا {
	    طالما ((dwarf_read_1(ln, پڇاڙي))) {
#إذا 0
		إذا (++dir_سائيز < DIR_جدول_سائيز)
		    dirs[dir_سائيز - 1] = (حرف *)ln - 1;
#جيڪڏهن_پورو
		طالما (dwarf_read_1(ln, پڇاڙي)) {}
	    }
	    طالما ((dwarf_read_1(ln, پڇاڙي))) {
		إذا (++filename_سائيز < FILE_جدول_سائيز) {
		    filename_جدول[filename_سائيز - 1].name = (حرف *)ln - 1;
		    طالما (dwarf_read_1(ln, پڇاڙي)) {}
		    filename_جدول[filename_سائيز - 1].dir_داخلا =
		        dwarf_read_uleb128(&ln, پڇاڙي);
		}
		وإلا {
		    طالما (dwarf_read_1(ln, پڇاڙي)) {}
		    dwarf_read_uleb128(&ln, پڇاڙي);
		}
		dwarf_read_uleb128(&ln, پڇاڙي); //وقت
		dwarf_read_uleb128(&ln, پڇاڙي); //سائيز
	    }
	}
	إذا (filename_سائيز >= 1)
	    filename = filename_جدول[0].name;
	طالما (ln < پڇاڙي) {
	    آخري_pc = pc;
	    i = dwarf_read_1(ln, پڇاڙي);
	    إذا (i >= opcode_بنياد) {
	        إذا (max_ops_في_insn == 1)
		    pc += ((i - opcode_بنياد) / سٽ_range) * min_insn_ڊيگهائي;
		وإلا {
		    pc += (opindex + (i - opcode_بنياد) / سٽ_range) /
			  max_ops_في_insn * min_insn_ڊيگهائي;
		    opindex = (opindex + (i - opcode_بنياد) / سٽ_range) %
			       max_ops_في_insn;
		}
		i = (صحيح)((i - opcode_بنياد) % سٽ_range) + سٽ_بنياد;
check_pc:
		إذا (pc >= wanted_pc && wanted_pc >= آخري_pc)
		    اذهب مليو;
		سٽ += i;
	    }
	    وإلا {
	        بدل (i) {
	        حالة 0:
		    len = dwarf_read_uleb128(&ln, پڇاڙي);
		    cp = ln;
		    ln += len;
		    إذا (len == 0)
		        اذهب ايندڙ_سٽ;
		    بدل (dwarf_read_1(cp, پڇاڙي)) {
		    حالة DW_LNE_پڇاڙي_sequence:
		        اكسر;
		    حالة DW_LNE_سيٽ_پتو:
#إذا PTR_سائيز == 4
		        pc = dwarf_read_4(cp, پڇاڙي);
#وإلا
		        pc = dwarf_read_8(cp, پڇاڙي);
#جيڪڏهن_پورو
#إذا defined TCC_هدف_MACHO
			pc += rc->prog_بنياد;
#جيڪڏهن_پورو
		        opindex = 0;
		        اكسر;
		    حالة DW_LNE_define_file: /* deprecated */
		        إذا (++filename_سائيز < FILE_جدول_سائيز) {
		            filename_جدول[filename_سائيز - 1].name = (حرف *)ln - 1;
		            طالما (dwarf_read_1(ln, پڇاڙي)) {}
		            filename_جدول[filename_سائيز - 1].dir_داخلا =
		                dwarf_read_uleb128(&ln, پڇاڙي);
		        }
		        وإلا {
		            طالما (dwarf_read_1(ln, پڇاڙي)) {}
		            dwarf_read_uleb128(&ln, پڇاڙي);
		        }
		        dwarf_read_uleb128(&ln, پڇاڙي); //وقت
		        dwarf_read_uleb128(&ln, پڇاڙي); //سائيز
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
		    إذا (max_ops_في_insn == 1)
		        pc += dwarf_read_uleb128(&ln, پڇاڙي) * min_insn_ڊيگهائي;
		    وإلا {
		        بنانشان ڊگهو ڊگهو off = dwarf_read_uleb128(&ln, پڇاڙي);

		        pc += (opindex + off) / max_ops_في_insn *
			      min_insn_ڊيگهائي;
		        opindex = (opindex + off) % max_ops_في_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_advance_سٽ:
		    سٽ += dwarf_read_sleb128(&ln, پڇاڙي);
		    اكسر;
	        حالة DW_LNS_سيٽ_file:
		    i = dwarf_read_uleb128(&ln, پڇاڙي);
		    i -= i > 0 && نسخو < 5;
		    إذا (i < FILE_جدول_سائيز && i < filename_سائيز)
		        filename = filename_جدول[i].name;
		    اكسر;
	        حالة DW_LNS_const_جوڙيو_pc:
		    إذا (max_ops_في_insn ==  1)
		        pc += ((255 - opcode_بنياد) / سٽ_range) * min_insn_ڊيگهائي;
		    وإلا {
		        بنانشان صحيح off = (255 - opcode_بنياد) / سٽ_range;

		        pc += ((opindex + off) / max_ops_في_insn) *
			      min_insn_ڊيگهائي;
		        opindex = (opindex + off) % max_ops_في_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, پڇاڙي);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    اذهب check_pc;
	        افتراضي:
		    لكل (j = 0; j < opcode_ڊيگهائي[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, پڇاڙي);
		    اكسر;
		}
	    }
	}
ايندڙ_سٽ:
	ln = پڇاڙي;
    }
    filename = function = عدم, func_addr = 0;
مليو:
    إذا (filename)
        pstrcpy(bi->file, حجم bi->file, filename), bi->سٽ = سٽ;
    إذا (function)
        pstrcpy(bi->func, حجم bi->func, function);
    bi->func_pc = func_addr;
    أرجع (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_BACKTRACE_ONLY
ساكن
#جيڪڏهن_پورو
صحيح _tcc_backtrace(rt_چوکٺو *f, ثابت حرف *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    حرف skip[40], نياپو[200];
    صحيح i, level, ret, n, one;
    ثابت حرف *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    إذا (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        يادگيري_نقل(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    إذا (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(نياپو, حجم نياپو, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    إذا (rc) {
        إذا (rc->dwarf)
            getinfo = rt_printline_dwarf;
        إذا (rc->انگ_callers)
            n = rc->انگ_callers;
    }

    لكل (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        إذا (ret == -1)
            اكسر;
        memset(&bi, 0, حجم bi);
        لكل (rc2 = rc; rc2; rc2 = rc2->ايندڙ) {
            إذا (getinfo(rc2, pc, &bi))
                اكسر;
            /* we try symtab symbols (no line number info) */
            إذا (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, حجم bi.func, a);
                اكسر;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        إذا (skip[0] && لڙي_ڳولا(bi.file, skip))
            استمر;
#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_ڳوليو_state(f);
            إذا (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_معلومات,
                    (فراغ*)pc,
                    bi.file[0] ? bi.file : عدم,
                    bi.سٽ,
                    bi.func[0] ? bi.func : عدم,
                    level == 0 ? نياپو : عدم
                    );
                إذا (ret == 0)
                    اكسر;
                اذهب check_break;
            }
        }
#جيڪڏهن_پورو
        إذا (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.سٽ);
        } وإلا {
            rt_printf("0x%08llx", (ڊگهو ڊگهو)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        إذا (level == 0) {
            rt_printf(": %s", نياپو);
            إذا (one)
                اكسر;
        }
        rt_printf("\n");

#جيڪڏهن_وصف_نه_ٿيل CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#جيڪڏهن_پورو
        إذا (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->چوٽي_func)
            اكسر;
        ++level;
    }
    rt_post_sem();
    أرجع 0;
}

/* emit a run time error at position 'pc' */
ساكن صحيح rt_error(rt_چوکٺو *f, ثابت حرف *fmt, ...)
{
    va_list ap; حرف نياپو[200]; صحيح ret;
    va_start(ap, fmt);
    snprintf(نياپو, حجم نياپو, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, نياپو, ap);
    va_end(ap);
    أرجع ret;
}

/* ------------------------------------------------------------- */

#جيڪڏهن_وصف_نه_ٿيل _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#وإلا
# define ucontext_t CONTEXT
#جيڪڏهن_پورو

/* translate from ucontext_t* to internal rt_context * */
ساكن فراغ rt_getcontext(ucontext_t *uc, rt_چوکٺو *rc)
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
#جيڪڏهن_پورو
}

/* ------------------------------------------------------------- */
#جيڪڏهن_وصف_نه_ٿيل _WIN32
/* signal handler for fatal errors */
ساكن فراغ sig_error(صحيح signum, siginfo_t *siginf, فراغ *puc)
{
    rt_چوکٺو f;
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

#جيڪڏهن_وصف_نه_ٿيل SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#جيڪڏهن_پورو

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ سيٽ_exception_handler(فراغ)
{
    بنية sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#إذا 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#جيڪڏهن_پورو
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
        ساكن بنانشان حرف ڍير[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ڍير;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, عدم);
    }
#جيڪڏهن_پورو
}

#وإلا /* WIN32 */

/* signal handler for fatal errors */
ساكن ڊگهو __stdcall cpu_exception_handler(EXCEPTION_اشارا *ex_info)
{
    rt_چوکٺو f;
    بنانشان ڪوڊ;
    rt_getcontext(ex_info->Context_رڪارڊ, &f);

    بدل (ڪوڊ = ex_info->Exception_رڪارڊ->Exception_ڪوڊ) {
    حالة EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        اكسر;
    حالة EXCEPTION_ڍير_حد_کان_مٿي:
        rt_error(&f, "stack overflow");
        اكسر;
    حالة EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        اكسر;
    حالة EXCEPTION_BREAKPOINT:
    حالة EXCEPTION_SINGLE_قدم:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        أرجع EXCEPTION_CONTINUE_ڳولا;
    افتراضي:
        rt_error(&f, "caught exception %08x", ڪوڊ);
        اكسر;
    }
    rt_exit(&f, 255);
    أرجع EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ سيٽ_exception_handler(فراغ)
{
#جيڪڏهن_وصف_ٿيل _WIN64
    جوڙيو_Vectored_Exception_Handler(1, cpu_exception_handler);
#وإلا
    سيٽ_Unhandled_Exception_Filter(cpu_exception_handler);
#جيڪڏهن_پورو
}

#جيڪڏهن_پورو

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#إذا defined(__i386__) || defined(__x86_64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *rc, صحيح level)
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
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *rc, صحيح level)
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
#warning جوڙيو arch specific rt_get_caller_pc()
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *rc, صحيح level)
{
    أرجع -1;
}

#جيڪڏهن_پورو
#وإلا // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_چوکٺو *f, صحيح level)
{
    إذا (level)
        أرجع -1;
    *paddr = f->ip;
    أرجع 0;
}
#جيڪڏهن_پورو /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#جيڪڏهن_وصف_ٿيل CONFIG_TCC_STATIC

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
#وصف_ڪريو TCCSYM(a) { #a, &a, },
    TCCSYM(لکو)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#وصف_رد TCCSYM
#جيڪڏهن_پورو
    { عدم, عدم },
};

ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *نشان)
{
    TCCSyms *p;
    p = tcc_syms;
    طالما (p->str != عدم) {
        إذا (!strcmp(p->str, نشان))
            أرجع p->ptr;
        p++;
    }
    أرجع عدم;
}

#جيڪڏهن_پورو /* CONFIG_TCC_STATIC */
#جيڪڏهن_پورو /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
