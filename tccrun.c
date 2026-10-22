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

#অন্তর্ভাব "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
প্রকারলেখ কাঠামো rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    সংঘ {
	কাঠামো {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    অক্ষর *stab_str;
	};
	কাঠামো {
	    unsigned অক্ষর *dwarf_সারি;
	    unsigned অক্ষর *dwarf_সারি_end;
	    unsigned অক্ষর *dwarf_সারি_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    অক্ষর *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    শূন্য *bounds_start;
    শূন্য *শীর্ষ_func;
    কাঠামো rt_context *পরবর্তী;
    // 10 * PTR_SIZE
    পূর্ণসংখ্যা অঙ্ক_callers;
    পূর্ণসংখ্যা dwarf;
} rt_context;

/* linked list of rt_contexts */
স্থির rt_context *g_rc;
স্থির পূর্ণসংখ্যা signal_set;
স্থির শূন্য set_exception_handler(শূন্য);
#endif /* def CONFIG_TCC_BACKTRACE */

প্রকারলেখ কাঠামো rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

স্থির TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(স্থির rt_sem);
স্থির শূন্য rt_wait_sem(শূন্য) { WAIT_SEM(&rt_sem); }
স্থির শূন্য rt_post_sem(শূন্য) { POST_SEM(&rt_sem); }
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *f, পূর্ণসংখ্যা level);
স্থির শূন্য rt_exit(rt_frame *f, পূর্ণসংখ্যা code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

স্থির পূর্ণসংখ্যা protect_pages(শূন্য *ptr, unsigned long দৈর্ঘ্য, পূর্ণসংখ্যা mode);
স্থির পূর্ণসংখ্যা tcc_relocate_ex(TCCState *s1, শূন্য *ptr, unsigned ptr_diff);
স্থির শূন্য st_link(TCCState *s1);
স্থির শূন্য st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
স্থির পূর্ণসংখ্যা _tcc_backtrace(rt_frame *f, ধ্রুবক অক্ষর *fmt, va_list ap);
#endif
#ifdef _WIN64
স্থির শূন্য *win64_add_function_table(TCCState *s1);
স্থির শূন্য win64_del_function_table(শূন্য *);
#endif

#যদি !defined PAGESIZE
# যদি defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# অন্যথা
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#যদি !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#যদি defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

স্থির পূর্ণসংখ্যা rt_mem(TCCState *s1, পূর্ণসংখ্যা আকার_2)
{
    শূন্য *ptr;
    পূর্ণসংখ্যা ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    শূন্য *prw;
    অক্ষর tmpfname[] = "/tmp/.tccrunXXXXXX";
    পূর্ণসংখ্যা fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, আকার_2);

    ptr = mmap(ফাঁকা, আকার_2 * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((অক্ষর*)ptr + আকার_2, আকার_2, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    যদি (ptr == MAP_FAILED || prw == MAP_FAILED)
	ফেরত tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (অক্ষর*)prw - (অক্ষর*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    আকার_2 *= 2;
#নতুবা_যদি CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ফাঁকা, আকার_2, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    যদি (!ptr)
        ফেরত tcc_error_noabort("tccrun: could not allocate memory");
#অন্যথা
    ptr = tcc_malloc(আকার_2 += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_আকার = আকার_2;
    ফেরত ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI পূর্ণসংখ্যা tcc_relocate(TCCState *s1)
{
    পূর্ণসংখ্যা আকার_2, ret, ptr_diff;

    যদি (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->do_backtrace)
        tcc_add_প্রতীক(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    আকার_2 = tcc_relocate_ex(s1, ফাঁকা, 0);
    যদি (আকার_2 < 0)
        ফেরত -1;
    ptr_diff = rt_mem(s1, আকার_2);
    যদি (ptr_diff < 0)
        ফেরত -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    যদি (ret == 0)
        st_link(s1);
    ফেরত ret;
}

ST_FUNC শূন্য tcc_run_free(TCCState *s1)
{
    unsigned আকার_2;
    শূন্য *ptr;
    পূর্ণসংখ্যা i;

    /* free any loaded DLLs */
    জন্য ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        যদি ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#অন্যথা
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    যদি (ফাঁকা == ptr)
        ফেরত;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    আকার_2 = s1->run_আকার;
#ifdef CONFIG_SELINUX
    munmap(ptr, আকার_2);
#নতুবা_যদি CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, আকার_2, MEM_RELEASE);
#অন্যথা
    /* unprotect memory to make it usable for malloc again */
    protect_pages((শূন্য*)PAGEALIGN(ptr), আকার_2 - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI পূর্ণসংখ্যা tcc_run(TCCState *s1, পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    পূর্ণসংখ্যা (*prog_main)(পূর্ণসংখ্যা, অক্ষর **, অক্ষর **), ret;
    ধ্রুবক অক্ষর *শীর্ষ_sym;
    jmp_buf main_jb;

#যদি defined(__APPLE__)
    বাহ্যিক অক্ষর ***_NSGetEnviron(শূন্য);
    অক্ষর **envp = *_NSGetEnviron();
#নতুবা_যদি defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    বাহ্যিক অক্ষর **environ;
    অক্ষর **envp = environ;
#অন্যথা
    অক্ষর **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    যদি ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ফেরত 0;

    tcc_add_প্রতীক(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", শীর্ষ_sym = "main";
    যদি (s1->elf_entryname)
        s1->run_main = শীর্ষ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    যদি (tcc_relocate(s1) < 0)
        ফেরত -1;

    prog_main = (শূন্য*)get_sym_addr(s1, s1->run_main, 1, 1);
    যদি ((addr_t)-1 == (addr_t)prog_main)
        ফেরত -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    যদি (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ফেরত -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_প্রতীক(s1, শীর্ষ_sym));
    যদি (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } অন্যথা যদি (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    যদি (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ফেরত ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
স্থির শূন্য cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    পূর্ণসংখ্যা sym_সূচক, end_sym = s->তথ্য_offset / আকার (ElfSym);
    /* reset symtab */
    s->তথ্য_offset = s->link->তথ্য_offset = s->hash->তথ্য_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    জন্য (sym_সূচক = 1; sym_সূচক < end_sym; ++sym_সূচক) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->তথ্য)[sym_সূচক];
        ধ্রুবক অক্ষর *name = (অক্ষর *)s->link->তথ্য + sym->st_name;
        যদি (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            চালু;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_মান, sym->st_আকার, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
স্থির শূন্য cleanup_sections(TCCState *s1)
{
    কাঠামো { Section **secs; পূর্ণসংখ্যা nb_secs; } *p = (শূন্য*)&s1->sections;
    পূর্ণসংখ্যা i, f = 2;
    করো {
        জন্য (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            যদি (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->তথ্য = tcc_realloc(s->তথ্য, s->তথ্য_allocated = s->তথ্য_offset);
            } অন্যথা {
                free_section(s), tcc_free(s), p->secs[i] = ফাঁকা;
            }
        }
    } যখন (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#ifndef CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# অন্যথা
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
স্থির পূর্ণসংখ্যা tcc_relocate_ex(TCCState *s1, শূন্য *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, দৈর্ঘ্য, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    যদি (ফাঁকা == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, ফাঁকা);
#অন্যথা
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    যদি (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_আকার*2 - 8]);
    যদি (s1->nb_errors)
        ফেরত -1;
    যদি (copy == 3)
        ফেরত 0;

    জন্য (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        জন্য(i = 1; i < s1->nb_sections; i++) {
            স্থির ধ্রুবক অক্ষর shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            যদি (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                চালু;
            দৈর্ঘ্য = s->তথ্য_offset;
            যদি (copy == 2) {
                যদি (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + দৈর্ঘ্য;
                চালু;
            }
            যদি (copy) { /* final step: copy section data to memory */
                যদি (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (শূন্য*)s->sh_addr, দৈর্ঘ্য, s->sh_addralign);
                ptr = (শূন্য*)s->sh_addr;
                যদি (k == 0)
                    ptr = (শূন্য*)(s->sh_addr + ptr_diff);
                যদি (ফাঁকা == s->তথ্য || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, দৈর্ঘ্য);
                অন্যথা
                    memcpy(ptr, s->তথ্য, দৈর্ঘ্য);
                চালু;
            }

            যদি ((s->sh_flags & SHF_TLS) && দৈর্ঘ্য)
                ফেরত tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            যদি (++n == 1) {
#যদি defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                যদি (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                যদি (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += দৈর্ঘ্য;
        }
        যদি (copy == 2) { /* set permissions */
            যদি (n == 0) /* no data  */
                চালু;
#ifdef CONFIG_SELINUX
            যদি (k == 0) /* SHF_EXECINSTR has its own mapping */
                চালু;
#endif
            f = k;
            যদি (f >= CONFIG_RUNMEM_RO) {
                যদি (f != 0)
                    চালু;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            যদি (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (শূন্য*)addr, (unsigned)n);
            }
            যদি (protect_pages((শূন্য*)addr, n, f) < 0)
                ফেরত tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#অন্যথা
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    যদি (0 == mem)
        ফেরত PAGEALIGN(offset);

    যদি (++copy == 2) {
        যাও redo;
    }
    যদি (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        যাও redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    যদি (s1->nb_errors)
        যাও redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#অন্যথা
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    যাও redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

স্থির পূর্ণসংখ্যা protect_pages(শূন্য *ptr, unsigned long দৈর্ঘ্য, পূর্ণসংখ্যা mode)
{
#ifdef _WIN32
    স্থির ধ্রুবক unsigned অক্ষর protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    যদি (!VirtualProtect(ptr, দৈর্ঘ্য, protect[mode], &old))
        ফেরত -1;
#অন্যথা
    স্থির ধ্রুবক unsigned অক্ষর protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    যদি (mprotect(ptr, দৈর্ঘ্য, protect[mode]))
        ফেরত -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#যদি (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    যদি (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, দৈর্ঘ্য);
#অন্যথা
        শূন্য __clear_cache(শূন্য *beginning, শূন্য *end);
        __clear_cache(ptr, (অক্ষর *)ptr + দৈর্ঘ্য);
#endif
    }
#endif
    ফেরত 0;
}

#ifdef _WIN64
স্থির শূন্য *win64_add_function_table(TCCState *s1)
{
    শূন্য *p = ফাঁকা;
    যদি (s1->uw_pdata) {
        p = (শূন্য*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->তথ্য_offset / আকার (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ফাঁকা;
    }
    ফেরত p;
}

স্থির শূন্য win64_del_function_table(শূন্য *p)
{
    যদি (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

স্থির শূন্য bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    যদি (!s1->do_backtrace)
        ফেরত;
    rc = tcc_get_প্রতীক(s1, "__rt_info");
    যদি (!rc)
        ফেরত;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->তথ্য);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->তথ্য + symtab_section->তথ্য_offset);
    rc->elf_str = (অক্ষর *)symtab_section->link->তথ্য;
    যদি (PTR_আকার == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    যদি (s1->do_bounds_check) {
        শূন্য *p;
        যদি ((p = tcc_get_প্রতীক(s1, "__bound_init")))
            ((শূন্য(*)(শূন্য*,পূর্ণসংখ্যা))p)(rc->bounds_start, 1);
    }
#endif
    rc->পরবর্তী = g_rc, g_rc = rc, s1->rc = rc;
    যদি (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

স্থির শূন্য st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->পরবর্তী = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
স্থির শূন্য ptr_unlink(শূন্য *list, শূন্য *e, unsigned পরবর্তী)
{
    শূন্য **pp, **nn, *p;
    জন্য (pp = list; !!(p = *pp); pp = nn) {
        nn = (শূন্য*)((অক্ষর*)p + পরবর্তী); /* nn = &p->next; */
        যদি (p == e) {
            *pp = *nn;
            বিরতি;
        }
    }
}

স্থির শূন্য st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, পরবর্তী));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, পরবর্তী));
    rt_post_sem();
}

LIBTCCAPI শূন্য *_tcc_setjmp(TCCState *s1, শূন্য *p_jmp_buf, শূন্য *func, শূন্য *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->rc)
        s1->rc->শীর্ষ_func = func;
#endif
    ফেরত p_jmp_buf;
}

LIBTCCAPI শূন্য tcc_set_backtrace_func(TCCState *s1, শূন্য *তথ্য, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_তথ্য = তথ্য;
}

স্থির TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    পূর্ণসংখ্যা level;
    addr_t pc;

    s = g_s1;
    যদি (ফাঁকা == s || ফাঁকা == s->পরবর্তী) {
        /* play it safe in the simple case when there is only one state */
        ফেরত s;
    }
    জন্য (level = 0; level < 8; ++level) {
        যদি (rt_get_caller_pc(&pc, f, level) < 0)
            বিরতি;
        জন্য (s = g_s1; s; s = s->পরবর্তী) {
            যদি (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_আকার)
                ফেরত s;
        }
    }
    ফেরত ফাঁকা;
}

স্থির শূন্য rt_exit(rt_frame *f, পূর্ণসংখ্যা code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    যদি (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        যদি (f->fp) { /* called from signal */
            শূন্য *p = tcc_get_প্রতীক(s, "__bound_exit");
            যদি (p)
                ((শূন্য (*)(শূন্য))p)();
        }
#endif
        যদি (code == 0)
            code = RT_EXIT_ZERO;
        ((শূন্য(*)(শূন্য*,পূর্ণসংখ্যা))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#অন্যথা // if defined CONFIG_TCC_BACKTRACE_ONLY
স্থির শূন্য rt_exit(rt_frame *f, পূর্ণসংখ্যা code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

স্থির পূর্ণসংখ্যা rt_vprintf(ধ্রুবক অক্ষর *fmt, va_list ap)
{
    পূর্ণসংখ্যা ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ফেরত ret;
}

স্থির পূর্ণসংখ্যা rt_printf(ধ্রুবক অক্ষর *fmt, ...)
{
    va_list ap;
    পূর্ণসংখ্যা r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ফেরত r;
}

স্থির অক্ষর *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    জন্য (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        পূর্ণসংখ্যা type = ELFW(ST_TYPE)(esym->st_info);
        যদি ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_মান
            && wanted_pc < esym->st_মান + esym->st_আকার) {
            *func_addr = esym->st_মান;
            ফেরত rc->elf_str + esym->st_name;
        }
    }
    ফেরত ফাঁকা;
}

প্রকারলেখ কাঠামো bt_info
{
    অক্ষর file[100];
    পূর্ণসংখ্যা সারি;
    অক্ষর func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
স্থির addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    অক্ষর func_name[128];
    addr_t func_addr, last_pc, pc;
    ধ্রুবক অক্ষর *incl_files[INCLUDE_স্তূপ_আকার];
    পূর্ণসংখ্যা incl_সূচক, last_incl_সূচক, len, last_সারি_অঙ্ক, i;
    ধ্রুবক অক্ষর *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_সূচক = 0;
    last_pc = (addr_t)-1;
    last_সারি_অঙ্ক = 1;
    last_incl_সূচক = 0;

    জন্য (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_মান;

        নির্বাচন(sym->n_type) {
        ক্ষেত্র N_SLINE:
            যদি (func_addr)
                যাও rel_pc;
        ক্ষেত্র N_SO:
        ক্ষেত্র N_SOL:
            যাও abs_pc;
        ক্ষেত্র N_FUN:
            যদি (sym->n_strx == 0) /* end of function */
                যাও rel_pc;
        abs_pc:
#যদি PTR_আকার == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            যাও check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            যদি (pc >= wanted_pc && wanted_pc >= last_pc)
                যাও found;
            বিরতি;
        }

        নির্বাচন(sym->n_type) {
            /* function start or end */
        ক্ষেত্র N_FUN:
            যদি (sym->n_strx == 0)
                যাও reset_func;
            p = strchr(str, ':');
            যদি (0 == p || (len = p - str + 1, len > আকার func_name))
                len = আকার func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            বিরতি;
            /* line number info */
        ক্ষেত্র N_SLINE:
            last_pc = pc;
            last_সারি_অঙ্ক = sym->n_desc;
            last_incl_সূচক = incl_সূচক;
            বিরতি;
            /* include files */
        ক্ষেত্র N_BINCL:
            যদি (incl_সূচক < INCLUDE_স্তূপ_আকার)
                incl_files[incl_সূচক++] = str;
            বিরতি;
        ক্ষেত্র N_EINCL:
            যদি (incl_সূচক > 1)
                incl_সূচক--;
            বিরতি;
            /* start/end of translation unit */
        ক্ষেত্র N_SO:
            incl_সূচক = 0;
            যদি (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                যদি (len > 0 && str[len - 1] != '/')
                    incl_files[incl_সূচক++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            বিরতি;
            /* alternative file name (from #line or #include directives) */
        ক্ষেত্র N_SOL:
            যদি (incl_সূচক)
                incl_files[incl_সূচক-1] = str;
            বিরতি;
        }
    }
    last_incl_সূচক = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_সূচক;
    যদি (i > 0) {
        pstrcpy(bi->file, আকার bi->file, incl_files[--i]);
        bi->সারি = last_সারি_অঙ্ক;
    }
    pstrcpy(bi->func, আকার bi->func, func_name);
    bi->func_pc = func_addr;
    ফেরত func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_আকার	(64)
#define FILE_TABLE_আকার	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	নির্বাচন (entry_format[j].form) { \
	ক্ষেত্র DW_FORM_data1: (ln) += 1; বিরতি; \
	ক্ষেত্র DW_FORM_data2: (ln) += 2; বিরতি; \
	ক্ষেত্র DW_FORM_data4: (ln) += 3; বিরতি; \
	ক্ষেত্র DW_FORM_data8: (ln) += 8; বিরতি; \
	ক্ষেত্র DW_FORM_data16: (ln) += 16; বিরতি; \
	ক্ষেত্র DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); বিরতি; \
	পূর্বনির্ধারিত: যাও পরবর্তী_সারি; \
	}

স্থির addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned অক্ষর *ln;
    unsigned অক্ষর *cp;
    unsigned অক্ষর *end;
    unsigned অক্ষর *opcode_দৈর্ঘ্য;
    unsigned long long আকার_2;
    unsigned পূর্ণসংখ্যা দৈর্ঘ্য;
    unsigned অক্ষর version;
    unsigned পূর্ণসংখ্যা min_insn_দৈর্ঘ্য;
    unsigned পূর্ণসংখ্যা max_ops_per_insn;
    পূর্ণসংখ্যা সারি_base;
    unsigned পূর্ণসংখ্যা সারি_range;
    unsigned পূর্ণসংখ্যা opcode_base;
    unsigned পূর্ণসংখ্যা opindex;
    unsigned পূর্ণসংখ্যা col;
    unsigned পূর্ণসংখ্যা i;
    unsigned পূর্ণসংখ্যা j;
    unsigned পূর্ণসংখ্যা len;
    unsigned long long মান;
    কাঠামো {
	unsigned পূর্ণসংখ্যা type;
	unsigned পূর্ণসংখ্যা form;
    } entry_format[256];
    unsigned পূর্ণসংখ্যা dir_আকার;
#যদি 0
    অক্ষর *dirs[DIR_TABLE_আকার];
#endif
    unsigned পূর্ণসংখ্যা filename_আকার;
    কাঠামো /*dwarf_filename_struct*/ {
        unsigned পূর্ণসংখ্যা dir_entry;
        অক্ষর *name;
    } filename_table[FILE_TABLE_আকার];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    পূর্ণসংখ্যা সারি;
    অক্ষর *filename;
    অক্ষর *function;

    filename = ফাঁকা;
    function = ফাঁকা;
    func_addr = 0;
    সারি = 0;

    ln = rc->dwarf_সারি;
    যখন (ln < rc->dwarf_সারি_end) {
	dir_আকার = 0;
	filename_আকার = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        সারি = 1;
        filename = ফাঁকা;
        function = ফাঁকা;
	দৈর্ঘ্য = 4;
	আকার_2 = dwarf_read_4(ln, rc->dwarf_সারি_end);
	যদি (আকার_2 == 0xffffffffu) // dwarf 64
	    দৈর্ঘ্য = 8, আকার_2 = dwarf_read_8(ln, rc->dwarf_সারি_end);
	end = ln + আকার_2;
	যদি (end < ln || end > rc->dwarf_সারি_end)
	    বিরতি;
	version = dwarf_read_2(ln, end);
	যদি (version >= 5)
	    ln += দৈর্ঘ্য + 2; // address size, segment selector, prologue Length
	অন্যথা
	    ln += দৈর্ঘ্য; // prologue Length
	min_insn_দৈর্ঘ্য = dwarf_read_1(ln, end);
	যদি (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	অন্যথা
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	সারি_base = dwarf_read_1(ln, end);
	সারি_base |= সারি_base >= 0x80 ? ~0xff : 0;
	সারি_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_দৈর্ঘ্য = ln;
	ln += opcode_base - 1;
	opindex = 0;
	যদি (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    জন্য (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_আকার = dwarf_read_uleb128(&ln, end);
	    জন্য (i = 0; i < dir_আকার; i++) {
		জন্য (j = 0; j < col; j++) {
		    যদি (entry_format[j].type == DW_LNCT_path) {
		        যদি (entry_format[j].form != DW_FORM_সারি_strp)
			    যাও পরবর্তী_সারি;
#যদি 0
		        মান = দৈর্ঘ্য == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        যদি (i < DIR_TABLE_আকার)
		            dirs[i] = (অক্ষর *)rc->dwarf_সারি_str + মান;
#অন্যথা
			দৈর্ঘ্য == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    অন্যথা 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    জন্য (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_আকার = dwarf_read_uleb128(&ln, end);
	    জন্য (i = 0; i < filename_আকার; i++)
		জন্য (j = 0; j < col; j++) {
		    যদি (entry_format[j].type == DW_LNCT_path) {
			যদি (entry_format[j].form != DW_FORM_সারি_strp)
			    যাও পরবর্তী_সারি;
			মান = দৈর্ঘ্য == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        যদি (i < FILE_TABLE_আকার)
		            filename_table[i].name =
				(অক্ষর *)rc->dwarf_সারি_str + মান;
	            }
		    অন্যথা যদি (entry_format[j].type == DW_LNCT_directory_সূচক) {
			নির্বাচন (entry_format[j].form) {
			ক্ষেত্র DW_FORM_data1: মান = dwarf_read_1(ln, end); বিরতি;
			ক্ষেত্র DW_FORM_data2: মান = dwarf_read_2(ln, end); বিরতি;
			ক্ষেত্র DW_FORM_data4: মান = dwarf_read_4(ln, end); বিরতি;
			ক্ষেত্র DW_FORM_udata: মান = dwarf_read_uleb128(&ln, end); বিরতি;
			পূর্বনির্ধারিত: যাও পরবর্তী_সারি;
			}
		        যদি (i < FILE_TABLE_আকার)
		            filename_table[i].dir_entry = মান;
		    }
		    অন্যথা 
			dwarf_ignore_type(ln, end);
	    }
	}
	অন্যথা {
	    যখন ((dwarf_read_1(ln, end))) {
#যদি 0
		যদি (++dir_আকার < DIR_TABLE_আকার)
		    dirs[dir_আকার - 1] = (অক্ষর *)ln - 1;
#endif
		যখন (dwarf_read_1(ln, end)) {}
	    }
	    যখন ((dwarf_read_1(ln, end))) {
		যদি (++filename_আকার < FILE_TABLE_আকার) {
		    filename_table[filename_আকার - 1].name = (অক্ষর *)ln - 1;
		    যখন (dwarf_read_1(ln, end)) {}
		    filename_table[filename_আকার - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		অন্যথা {
		    যখন (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); //আকার
	    }
	}
	যদি (filename_আকার >= 1)
	    filename = filename_table[0].name;
	যখন (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    যদি (i >= opcode_base) {
	        যদি (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / সারি_range) * min_insn_দৈর্ঘ্য;
		অন্যথা {
		    pc += (opindex + (i - opcode_base) / সারি_range) /
			  max_ops_per_insn * min_insn_দৈর্ঘ্য;
		    opindex = (opindex + (i - opcode_base) / সারি_range) %
			       max_ops_per_insn;
		}
		i = (পূর্ণসংখ্যা)((i - opcode_base) % সারি_range) + সারি_base;
check_pc:
		যদি (pc >= wanted_pc && wanted_pc >= last_pc)
		    যাও found;
		সারি += i;
	    }
	    অন্যথা {
	        নির্বাচন (i) {
	        ক্ষেত্র 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    যদি (len == 0)
		        যাও পরবর্তী_সারি;
		    নির্বাচন (dwarf_read_1(cp, end)) {
		    ক্ষেত্র DW_LNE_end_sequence:
		        বিরতি;
		    ক্ষেত্র DW_LNE_set_address:
#যদি PTR_আকার == 4
		        pc = dwarf_read_4(cp, end);
#অন্যথা
		        pc = dwarf_read_8(cp, end);
#endif
#যদি defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        বিরতি;
		    ক্ষেত্র DW_LNE_define_file: /* deprecated */
		        যদি (++filename_আকার < FILE_TABLE_আকার) {
		            filename_table[filename_আকার - 1].name = (অক্ষর *)ln - 1;
		            যখন (dwarf_read_1(ln, end)) {}
		            filename_table[filename_আকার - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        অন্যথা {
		            যখন (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); //আকার
		        বিরতি;
		    ক্ষেত্র DW_LNE_hi_user - 1:
		        function = (অক্ষর *)cp;
		        func_addr = pc;
		        বিরতি;
		    পূর্বনির্ধারিত:
		        বিরতি;
		    }
		    বিরতি;
	        ক্ষেত্র DW_LNS_advance_pc:
		    যদি (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_দৈর্ঘ্য;
		    অন্যথা {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_দৈর্ঘ্য;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    যাও check_pc;
	        ক্ষেত্র DW_LNS_advance_সারি:
		    সারি += dwarf_read_sleb128(&ln, end);
		    বিরতি;
	        ক্ষেত্র DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    যদি (i < FILE_TABLE_আকার && i < filename_আকার)
		        filename = filename_table[i].name;
		    বিরতি;
	        ক্ষেত্র DW_LNS_const_add_pc:
		    যদি (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / সারি_range) * min_insn_দৈর্ঘ্য;
		    অন্যথা {
		        unsigned পূর্ণসংখ্যা off = (255 - opcode_base) / সারি_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_দৈর্ঘ্য;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    যাও check_pc;
	        ক্ষেত্র DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    যাও check_pc;
	        পূর্বনির্ধারিত:
		    জন্য (j = 0; j < opcode_দৈর্ঘ্য[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    বিরতি;
		}
	    }
	}
পরবর্তী_সারি:
	ln = end;
    }
    filename = function = ফাঁকা, func_addr = 0;
found:
    যদি (filename)
        pstrcpy(bi->file, আকার bi->file, filename), bi->সারি = সারি;
    যদি (function)
        pstrcpy(bi->func, আকার bi->func, function);
    bi->func_pc = func_addr;
    ফেরত (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
স্থির
#endif
পূর্ণসংখ্যা _tcc_backtrace(rt_frame *f, ধ্রুবক অক্ষর *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    অক্ষর skip[40], বার্তা[200];
    পূর্ণসংখ্যা i, level, ret, n, one;
    ধ্রুবক অক্ষর *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    যদি (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    যদি (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(বার্তা, আকার বার্তা, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    যদি (rc) {
        যদি (rc->dwarf)
            getinfo = rt_printline_dwarf;
        যদি (rc->অঙ্ক_callers)
            n = rc->অঙ্ক_callers;
    }

    জন্য (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        যদি (ret == -1)
            বিরতি;
        memset(&bi, 0, আকার bi);
        জন্য (rc2 = rc; rc2; rc2 = rc2->পরবর্তী) {
            যদি (getinfo(rc2, pc, &bi))
                বিরতি;
            /* we try symtab symbols (no line number info) */
            যদি (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, আকার bi.func, a);
                বিরতি;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        যদি (skip[0] && strstr(bi.file, skip))
            চালু;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            যদি (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_তথ্য,
                    (শূন্য*)pc,
                    bi.file[0] ? bi.file : ফাঁকা,
                    bi.সারি,
                    bi.func[0] ? bi.func : ফাঁকা,
                    level == 0 ? বার্তা : ফাঁকা
                    );
                যদি (ret == 0)
                    বিরতি;
                যাও check_break;
            }
        }
#endif
        যদি (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.সারি);
        } অন্যথা {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        যদি (level == 0) {
            rt_printf(": %s", বার্তা);
            যদি (one)
                বিরতি;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        যদি (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->শীর্ষ_func)
            বিরতি;
        ++level;
    }
    rt_post_sem();
    ফেরত 0;
}

/* emit a run time error at position 'pc' */
স্থির পূর্ণসংখ্যা rt_error(rt_frame *f, ধ্রুবক অক্ষর *fmt, ...)
{
    va_list ap; অক্ষর বার্তা[200]; পূর্ণসংখ্যা ret;
    va_start(ap, fmt);
    snprintf(বার্তা, আকার বার্তা, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, বার্তা, ap);
    va_end(ap);
    ফেরত ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#অন্যথা
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
স্থির শূন্য rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#যদি defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#নতুবা_যদি defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#নতুবা_যদি defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#নতুবা_যদি defined __i386__
# যদি defined(__APPLE__)
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
# অন্যথা
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#নতুবা_যদি defined(__x86_64__)
# যদি defined(__APPLE__)
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
# অন্যথা
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#নতুবা_যদি defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নতুবা_যদি defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#নতুবা_যদি defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নতুবা_যদি defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#নতুবা_যদি defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#নতুবা_যদি defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#নতুবা_যদি defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নতুবা_যদি defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#নতুবা_যদি defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#নতুবা_যদি defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#নতুবা_যদি defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
স্থির শূন্য sig_error(পূর্ণসংখ্যা signum, siginfo_t *siginf, শূন্য *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    নির্বাচন(signum) {
    ক্ষেত্র SIGFPE:
        নির্বাচন(siginf->si_code) {
        ক্ষেত্র FPE_INTDIV:
        ক্ষেত্র FPE_FLTDIV:
            rt_error(&f, "division by zero");
            বিরতি;
        পূর্বনির্ধারিত:
            rt_error(&f, "floating point exception");
            বিরতি;
        }
        বিরতি;
    ক্ষেত্র SIGBUS:
    ক্ষেত্র SIGSEGV:
        rt_error(&f, "invalid memory access");
        বিরতি;
    ক্ষেত্র SIGILL:
        rt_error(&f, "illegal instruction");
        বিরতি;
    ক্ষেত্র SIGABRT:
        rt_error(&f, "abort() called");
        বিরতি;
    পূর্বনির্ধারিত:
        rt_error(&f, "caught signal %d", signum);
        বিরতি;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ফাঁকা);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
স্থির শূন্য set_exception_handler(শূন্য)
{
    কাঠামো sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#যদি 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ফাঁকা);
    sigaction(SIGILL, &sigact, ফাঁকা);
    sigaction(SIGSEGV, &sigact, ফাঁকা);
    sigaction(SIGBUS, &sigact, ফাঁকা);
    sigaction(SIGABRT, &sigact, ফাঁকা);
#যদি 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        স্থির unsigned অক্ষর স্তূপ[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = স্তূপ;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ফাঁকা);
    }
#endif
}

#অন্যথা /* WIN32 */

/* signal handler for fatal errors */
স্থির long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    নির্বাচন (code = ex_info->ExceptionRecord->ExceptionCode) {
    ক্ষেত্র EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        বিরতি;
    ক্ষেত্র EXCEPTION_স্তূপ_OVERFLOW:
        rt_error(&f, "stack overflow");
        বিরতি;
    ক্ষেত্র EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        বিরতি;
    ক্ষেত্র EXCEPTION_BREAKPOINT:
    ক্ষেত্র EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ফেরত EXCEPTION_CONTINUE_অনুসন্ধান;
    পূর্বনির্ধারিত:
        rt_error(&f, "caught exception %08x", code);
        বিরতি;
    }
    rt_exit(&f, 255);
    ফেরত EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
স্থির শূন্য set_exception_handler(শূন্য)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#অন্যথা
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#যদি defined(__i386__) || defined(__x86_64__)
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণসংখ্যা level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যখন (1) {
            যদি (fp < 0x1000)
                ফেরত -1;
            যদি (0 == --level)
                বিরতি;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ফেরত 0;
}

/* XXX: only supports linux/bsd */
#নতুবা_যদি defined(__arm__) && !defined(_WIN32)
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণসংখ্যা level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যখন (1) {
            যদি (fp < 0x1000)
                ফেরত -1;
            যদি (0 == --level)
                বিরতি;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ফেরত 0;
}

#নতুবা_যদি defined(__aarch64__)
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণসংখ্যা level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যখন (1) {
            যদি (fp < 0x1000)
                ফেরত -1;
            যদি (0 == --level)
                বিরতি;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ফেরত 0;
}

#নতুবা_যদি defined(__riscv)
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণসংখ্যা level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যখন (1) {
            যদি (fp < 0x1000)
                ফেরত -1;
            যদি (0 == --level)
                বিরতি;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ফেরত 0;
}

#অন্যথা
#warning add arch specific rt_get_caller_pc()
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণসংখ্যা level)
{
    ফেরত -1;
}

#endif
#অন্যথা // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
স্থির পূর্ণসংখ্যা rt_get_caller_pc(addr_t *paddr, rt_frame *f, পূর্ণসংখ্যা level)
{
    যদি (level)
        ফেরত -1;
    *paddr = f->ip;
    ফেরত 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC শূন্য *dlopen(ধ্রুবক অক্ষর *filename, পূর্ণসংখ্যা flag)
{
    ফেরত ফাঁকা;
}

ST_FUNC শূন্য dlclose(শূন্য *p)
{
}

ST_FUNC ধ্রুবক অক্ষর *dlerror(শূন্য)
{
    ফেরত "error";
}

প্রকারলেখ কাঠামো TCCSyms {
    অক্ষর *str;
    শূন্য *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
স্থির TCCSyms tcc_syms[] = {
#যদি !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { ফাঁকা, ফাঁকা },
};

ST_FUNC শূন্য *dlsym(শূন্য *handle, ধ্রুবক অক্ষর *প্রতীক)
{
    TCCSyms *p;
    p = tcc_syms;
    যখন (p->str != ফাঁকা) {
        যদি (!strcmp(p->str, প্রতীক))
            ফেরত p->ptr;
        p++;
    }
    ফেরত ফাঁকা;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
