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

#అన్తర్భావ "tcc.h"

/* only native compiler supports -run */
#నిర్వచితమైతే TCC_IS_NATIVE

#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
/* runtime debug info block */
రకనిర్వచనం నిర్మాణం rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    సంఘం {
	నిర్మాణం {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_చివర;
	    అక్షరం *stab_str;
	};
	నిర్మాణం {
	    గుర్తులేని అక్షరం *dwarf_పంక్తి;
	    గుర్తులేని అక్షరం *dwarf_పంక్తి_చివర;
	    గుర్తులేని అక్షరం *dwarf_పంక్తి_str;
	};
    };
    ElfW(Sym) *esym_ప్రారంభం;
    ElfW(Sym) *esym_చివర;
    అక్షరం *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_పునాది;
    శూన్య *bounds_ప్రారంభం;
    శూన్య *శిఖరం_func;
    నిర్మాణం rt_context *తదుపరి;
    // 10 * PTR_SIZE
    పూర్ణాంకం అంకె_callers;
    పూర్ణాంకం dwarf;
} rt_context;

/* linked list of rt_contexts */
స్థిర rt_context *g_rc;
స్థిర పూర్ణాంకం signal_సమితి;
స్థిర శూన్య సమితి_exception_handler(శూన్య);
#అయితే_ముగింపు /* def CONFIG_TCC_BACKTRACE */

రకనిర్వచనం నిర్మాణం rt_చట్రం {
    addr_t ip, fp, sp;
} rt_చట్రం;

స్థిర TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(స్థిర rt_sem);
స్థిర శూన్య rt_wait_sem(శూన్య) { WAIT_SEM(&rt_sem); }
స్థిర శూన్య rt_post_sem(శూన్య) { POST_SEM(&rt_sem); }
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *f, పూర్ణాంకం level);
స్థిర శూన్య rt_exit(rt_చట్రం *f, పూర్ణాంకం సంకేతం_2);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#నిర్వచితం_కాకపోతే CONFIG_TCC_BACKTRACE_ONLY

#నిర్వచితం_కాకపోతే _WIN32
# include <sys/mman.h>
#అయితే_ముగింపు

స్థిర పూర్ణాంకం protect_పుటలు(శూన్య *ptr, గుర్తులేని దీర్ఘ నిడివి, పూర్ణాంకం బహుళకం);
స్థిర పూర్ణాంకం tcc_relocate_ex(TCCState *s1, శూన్య *ptr, గుర్తులేని ptr_diff);
స్థిర శూన్య st_link(TCCState *s1);
స్థిర శూన్య st_unlink(TCCState *s1);
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
స్థిర పూర్ణాంకం _tcc_backtrace(rt_చట్రం *f, స్థిరరాశి అక్షరం *fmt, va_list ap);
#అయితే_ముగింపు
#నిర్వచితమైతే _WIN64
స్థిర శూన్య *win64_కూడు_function_పట్టిక(TCCState *s1);
స్థిర శూన్య win64_del_function_పట్టిక(శూన్య *);
#అయితే_ముగింపు

#ఒకవేళ !defined PAGESIZE
# ఒకవేళ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# లేకపోతే
#  define PAGESIZE 4096
# endif
#అయితే_ముగింపు

#నిర్వచించు PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ఒకవేళ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#అయితే_ముగింపు

/* use VirtualAlloc() instead of tcc_malloc() */
#ఒకవేళ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#అయితే_ముగింపు

స్థిర పూర్ణాంకం rt_mem(TCCState *s1, పూర్ణాంకం కొలత)
{
    శూన్య *ptr;
    పూర్ణాంకం ptr_diff = 0;
#నిర్వచితమైతే CONFIG_SELINUX
    /* Using mmap instead of malloc */
    శూన్య *prw;
    అక్షరం tmpfname[] = "/tmp/.tccrunXXXXXX";
    పూర్ణాంకం fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, కొలత);

    ptr = mmap(ఖాళీ, కొలత * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((అక్షరం*)ptr + కొలత, కొలత, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ఒకవేళ (ptr == MAP_FAILED || prw == MAP_FAILED)
	తిరిగి tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (అక్షరం*)prw - (అక్షరం*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    కొలత *= 2;
#లేదావేళ CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ఖాళీ, కొలత, MEM_RESERVE | MEM_COMMIT, పుట_READWRITE);
    ఒకవేళ (!ptr)
        తిరిగి tcc_error_noabort("tccrun: could not allocate memory");
#లేకపోతే
    ptr = tcc_malloc(కొలత += PAGESIZE); /* one extra page to align malloc memory */
#అయితే_ముగింపు
    s1->నిరంతరం_ptr = ptr;
    s1->నిరంతరం_కొలత = కొలత;
    తిరిగి ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI పూర్ణాంకం tcc_relocate(TCCState *s1)
{
    పూర్ణాంకం కొలత, ret, ptr_diff;

    ఒకవేళ (s1->నిరంతరం_ptr)
        నిష్క్రమించు(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    ఒకవేళ (s1->do_backtrace)
        tcc_కూడు_చిహ్నం(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#అయితే_ముగింపు
    కొలత = tcc_relocate_ex(s1, ఖాళీ, 0);
    ఒకవేళ (కొలత < 0)
        తిరిగి -1;
    ptr_diff = rt_mem(s1, కొలత);
    ఒకవేళ (ptr_diff < 0)
        తిరిగి -1;
    ret = tcc_relocate_ex(s1, s1->నిరంతరం_ptr, ptr_diff);
    ఒకవేళ (ret == 0)
        st_link(s1);
    తిరిగి ret;
}

ST_FUNC శూన్య tcc_నిరంతరం_free(TCCState *s1)
{
    గుర్తులేని కొలత;
    శూన్య *ptr;
    పూర్ణాంకం i;

    /* free any loaded DLLs */
    కొరకు ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ఒకవేళ ( ref->handle )
#నిర్వచితమైతే _WIN32
            FreeLibrary((HMODULE)ref->handle);
#లేకపోతే
            dlclose(ref->handle);
#అయితే_ముగింపు
    }
    /* unmap or unprotect and free memory */
    ptr = s1->నిరంతరం_ptr;
    ఒకవేళ (ఖాళీ == ptr)
        తిరిగి;
    st_unlink(s1);
#నిర్వచితమైతే _WIN64
    win64_del_function_పట్టిక(s1->నిరంతరం_function_పట్టిక);
#అయితే_ముగింపు
    కొలత = s1->నిరంతరం_కొలత;
#నిర్వచితమైతే CONFIG_SELINUX
    munmap(ptr, కొలత);
#లేదావేళ CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, కొలత, MEM_RELEASE);
#లేకపోతే
    /* unprotect memory to make it usable for malloc again */
    protect_పుటలు((శూన్య*)PAGEALIGN(ptr), కొలత - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#అయితే_ముగింపు
}

#నిర్వచించు RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI పూర్ణాంకం tcc_నిరంతరం(TCCState *s1, పూర్ణాంకం argc, అక్షరం **argv)
{
    పూర్ణాంకం (*prog_main)(పూర్ణాంకం, అక్షరం **, అక్షరం **), ret;
    స్థిరరాశి అక్షరం *శిఖరం_sym;
    jmp_buf main_jb;

#ఒకవేళ defined(__APPLE__)
    బాహ్య అక్షరం ***_NSGetEnviron(శూన్య);
    అక్షరం **envp = *_NSGetEnviron();
#లేదావేళ defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    బాహ్య అక్షరం **environ;
    అక్షరం **envp = environ;
#లేకపోతే
    అక్షరం **envp = environ;
#అయితే_ముగింపు

    /* tcc -dt -run ... nothing to do if no main() */
    ఒకవేళ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        తిరిగి 0;

    tcc_కూడు_చిహ్నం(s1, "__rt_exit", rt_exit);
    s1->నిరంతరం_main = "_runmain", శిఖరం_sym = "main";
    ఒకవేళ (s1->elf_entryname)
        s1->నిరంతరం_main = శిఖరం_sym = s1->elf_entryname;
    tcc_కూడు_support(s1, "runmain.o");

    ఒకవేళ (tcc_relocate(s1) < 0)
        తిరిగి -1;

    prog_main = (శూన్య*)get_sym_addr(s1, s1->నిరంతరం_main, 1, 1);
    ఒకవేళ ((addr_t)-1 == (addr_t)prog_main)
        తిరిగి -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ఒకవేళ (s1->నిరంతరం_stdin && !freopen(s1->నిరంతరం_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->నిరంతరం_stdin);
        తిరిగి -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_చిహ్నం(s1, శిఖరం_sym));
    ఒకవేళ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } లేకపోతే ఒకవేళ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ఒకవేళ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    తిరిగి ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
స్థిర శూన్య cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    పూర్ణాంకం sym_సూచీ, చివర_sym = s->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (ElfSym);
    /* reset symtab */
    s->దత్తాంశం_స్థానభ్రంశం = s->link->దత్తాంశం_స్థానభ్రంశం = s->hash->దత్తాంశం_స్థానభ్రంశం = 0;
    init_symtab(s);
    /* add global symbols again */
    కొరకు (sym_సూచీ = 1; sym_సూచీ < చివర_sym; ++sym_సూచీ) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->దత్తాంశం)[sym_సూచీ];
        స్థిరరాశి అక్షరం *name = (అక్షరం *)s->link->దత్తాంశం + sym->st_name;
        ఒకవేళ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            కొనసాగు;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_విలువ, sym->st_కొలత, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
స్థిర శూన్య cleanup_sections(TCCState *s1)
{
    నిర్మాణం { Section **secs; పూర్ణాంకం nb_secs; } *p = (శూన్య*)&s1->sections;
    పూర్ణాంకం i, f = 2;
    చేయి {
        కొరకు (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ఒకవేళ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->దత్తాంశం = tcc_realloc(s->దత్తాంశం, s->దత్తాంశం_allocated = s->దత్తాంశం_స్థానభ్రంశం);
            } లేకపోతే {
                free_section(s), tcc_free(s), p->secs[i] = ఖాళీ;
            }
        }
    } అయితే (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#నిర్వచితం_కాకపోతే CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# లేకపోతే
#   define CONFIG_RUNMEM_RO 0
#  endif
#అయితే_ముగింపు

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
స్థిర పూర్ణాంకం tcc_relocate_ex(TCCState *s1, శూన్య *ptr, గుర్తులేని ptr_diff)
{
    Section *s;
    గుర్తులేని స్థానభ్రంశం, నిడివి, align, i, k, f;
    గుర్తులేని n, copy;
    addr_t mem, addr;

    ఒకవేళ (ఖాళీ == ptr) {
        s1->nb_errors = 0;
#నిర్వచితమైతే TCC_లక్ష్యం_PE
        pe_output_file(s1, ఖాళీ);
#లేకపోతే
        tcc_కూడు_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#అయితే_ముగింపు
    }

    స్థానభ్రంశం = copy = 0;
    mem = (addr_t)ptr;
redo:
    ఒకవేళ (s1->verbose == 2 && copy)
        రాయి(&"-----------------------------------------------------\n"[PTR_కొలత*2 - 8]);
    ఒకవేళ (s1->nb_errors)
        తిరిగి -1;
    ఒకవేళ (copy == 3)
        తిరిగి 0;

    కొరకు (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        కొరకు(i = 1; i < s1->nb_sections; i++) {
            స్థిర స్థిరరాశి అక్షరం shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ఒకవేళ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                కొనసాగు;
            నిడివి = s->దత్తాంశం_స్థానభ్రంశం;
            ఒకవేళ (copy == 2) {
                ఒకవేళ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + నిడివి;
                కొనసాగు;
            }
            ఒకవేళ (copy) { /* final step: copy section data to memory */
                ఒకవేళ (s1->verbose == 2)
                    రాయి("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (శూన్య*)s->sh_addr, నిడివి, s->sh_addralign);
                ptr = (శూన్య*)s->sh_addr;
                ఒకవేళ (k == 0)
                    ptr = (శూన్య*)(s->sh_addr + ptr_diff);
                ఒకవేళ (ఖాళీ == s->దత్తాంశం || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, నిడివి);
                లేకపోతే
                    జ్ఞాపకం_నకలు(ptr, s->దత్తాంశం, నిడివి);
                కొనసాగు;
            }

            ఒకవేళ ((s->sh_flags & SHF_TLS) && నిడివి)
                తిరిగి tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ఒకవేళ (++n == 1) {
#ఒకవేళ defined TCC_లక్ష్యం_I386 || defined TCC_లక్ష్యం_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ఒకవేళ (align < 64)
                    align = 64;
#అయితే_ముగింపు
                /* start new page for different permissions */
                ఒకవేళ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            స్థానభ్రంశం += -(addr + స్థానభ్రంశం) & (align - 1);
            s->sh_addr = mem ? addr + స్థానభ్రంశం : 0;
            స్థానభ్రంశం += నిడివి;
        }
        ఒకవేళ (copy == 2) { /* set permissions */
            ఒకవేళ (n == 0) /* no data  */
                కొనసాగు;
#నిర్వచితమైతే CONFIG_SELINUX
            ఒకవేళ (k == 0) /* SHF_EXECINSTR has its own mapping */
                కొనసాగు;
#అయితే_ముగింపు
            f = k;
            ఒకవేళ (f >= CONFIG_RUNMEM_RO) {
                ఒకవేళ (f != 0)
                    కొనసాగు;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ఒకవేళ (s1->verbose == 2) {
                రాయి("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (శూన్య*)addr, (గుర్తులేని)n);
            }
            ఒకవేళ (protect_పుటలు((శూన్య*)addr, n, f) < 0)
                తిరిగి tcc_error_noabort(
#నిర్వచితమైతే _WIN32
                    "VirtualProtect failed");
#లేకపోతే
                    "mprotect failed (did you mean to configure --with-selinux?)");
#అయితే_ముగింపు
        }
    }

    ఒకవేళ (0 == mem)
        తిరిగి PAGEALIGN(స్థానభ్రంశం);

    ఒకవేళ (++copy == 2) {
        వెళ్ళు redo;
    }
    ఒకవేళ (copy == 3) {
#నిర్వచితమైతే _WIN64
        s1->నిరంతరం_function_పట్టిక = win64_కూడు_function_పట్టిక(s1);
#అయితే_ముగింపు
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        వెళ్ళు redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ఒకవేళ (s1->nb_errors)
        వెళ్ళు redo;
    /* relocate sections */
#నిర్వచితమైతే TCC_లక్ష్యం_PE
    s1->pe_imagebase = mem;
#లేకపోతే
    relocate_plt(s1);
#అయితే_ముగింపు
    relocate_sections(s1);
    వెళ్ళు redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

స్థిర పూర్ణాంకం protect_పుటలు(శూన్య *ptr, గుర్తులేని దీర్ఘ నిడివి, పూర్ణాంకం బహుళకం)
{
#నిర్వచితమైతే _WIN32
    స్థిర స్థిరరాశి గుర్తులేని అక్షరం protect[] = {
        పుట_EXECUTE_READ,
        పుట_READONLY,
        పుట_READWRITE,
        పుట_EXECUTE_READWRITE
        };
    DWORD old;
    ఒకవేళ (!VirtualProtect(ptr, నిడివి, protect[బహుళకం], &old))
        తిరిగి -1;
#లేకపోతే
    స్థిర స్థిరరాశి గుర్తులేని అక్షరం protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ఒకవేళ (mprotect(ptr, నిడివి, protect[బహుళకం]))
        తిరిగి -1;
#అయితే_ముగింపు
/* XXX: BSD sometimes dump core with bad system call */
#ఒకవేళ (defined TCC_లక్ష్యం_ARM && !TARGETOS_BSD) \
    || defined TCC_లక్ష్యం_ARM64 || defined TCC_లక్ష్యం_RISCV64
    ఒకవేళ (బహుళకం == 0 || బహుళకం == 3) {
#నిర్వచితమైతే _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, నిడివి);
#లేకపోతే
        శూన్య __clear_cache(శూన్య *beginning, శూన్య *చివర);
        __clear_cache(ptr, (అక్షరం *)ptr + నిడివి);
#అయితే_ముగింపు
    }
#అయితే_ముగింపు
    తిరిగి 0;
}

#నిర్వచితమైతే _WIN64
స్థిర శూన్య *win64_కూడు_function_పట్టిక(TCCState *s1)
{
    శూన్య *p = ఖాళీ;
    ఒకవేళ (s1->uw_pdata) {
        p = (శూన్య*)s1->uw_pdata->sh_addr;
        Rtl_కూడు_Function_పట్టిక(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->దత్తాంశం_స్థానభ్రంశం / పరిమాణం (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ఖాళీ;
    }
    తిరిగి p;
}

స్థిర శూన్య win64_del_function_పట్టిక(శూన్య *p)
{
    ఒకవేళ (p) {
        Rtl_Delete_Function_పట్టిక((RUNTIME_FUNCTION*)p);
    }
}
#అయితే_ముగింపు

స్థిర శూన్య bt_link(TCCState *s1)
{
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ఒకవేళ (!s1->do_backtrace)
        తిరిగి;
    rc = tcc_get_చిహ్నం(s1, "__rt_info");
    ఒకవేళ (!rc)
        తిరిగి;
    rc->esym_ప్రారంభం = (ElfW(Sym) *)(symtab_section->దత్తాంశం);
    rc->esym_చివర = (ElfW(Sym) *)(symtab_section->దత్తాంశం + symtab_section->దత్తాంశం_స్థానభ్రంశం);
    rc->elf_str = (అక్షరం *)symtab_section->link->దత్తాంశం;
    ఒకవేళ (PTR_కొలత == 8 && !s1->dwarf)
        rc->prog_పునాది &= 0xffffffff00000000ULL;
#నిర్వచితమైతే CONFIG_TCC_BCHECK
    ఒకవేళ (s1->do_bounds_check) {
        శూన్య *p;
        ఒకవేళ ((p = tcc_get_చిహ్నం(s1, "__bound_init")))
            ((శూన్య(*)(శూన్య*,పూర్ణాంకం))p)(rc->bounds_ప్రారంభం, 1);
    }
#అయితే_ముగింపు
    rc->తదుపరి = g_rc, g_rc = rc, s1->rc = rc;
    ఒకవేళ (0 == signal_సమితి)
        సమితి_exception_handler(), signal_సమితి = 1;
#అయితే_ముగింపు
}

స్థిర శూన్య st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->తదుపరి = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
స్థిర శూన్య ptr_unlink(శూన్య *list, శూన్య *e, గుర్తులేని తదుపరి)
{
    శూన్య **pp, **nn, *p;
    కొరకు (pp = list; !!(p = *pp); pp = nn) {
        nn = (శూన్య*)((అక్షరం*)p + తదుపరి); /* nn = &p->next; */
        ఒకవేళ (p == e) {
            *pp = *nn;
            ఆపు;
        }
    }
}

స్థిర శూన్య st_unlink(TCCState *s1)
{
    rt_wait_sem();
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, తదుపరి));
#అయితే_ముగింపు
    ptr_unlink(&g_s1, s1, offsetof(TCCState, తదుపరి));
    rt_post_sem();
}

LIBTCCAPI శూన్య *_tcc_setjmp(TCCState *s1, శూన్య *p_jmp_buf, శూన్య *func, శూన్య *p_longjmp)
{
    s1->నిరంతరం_lj = p_longjmp;
    s1->నిరంతరం_jb = p_jmp_buf;
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE
    ఒకవేళ (s1->rc)
        s1->rc->శిఖరం_func = func;
#అయితే_ముగింపు
    తిరిగి p_jmp_buf;
}

LIBTCCAPI శూన్య tcc_సమితి_backtrace_func(TCCState *s1, శూన్య *దత్తాంశం, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_దత్తాంశం = దత్తాంశం;
}

స్థిర TCCState *rt_కనుగొను_state(rt_చట్రం *f)
{
    TCCState *s;
    పూర్ణాంకం level;
    addr_t pc;

    s = g_s1;
    ఒకవేళ (ఖాళీ == s || ఖాళీ == s->తదుపరి) {
        /* play it safe in the simple case when there is only one state */
        తిరిగి s;
    }
    కొరకు (level = 0; level < 8; ++level) {
        ఒకవేళ (rt_get_caller_pc(&pc, f, level) < 0)
            ఆపు;
        కొరకు (s = g_s1; s; s = s->తదుపరి) {
            ఒకవేళ (pc >= (addr_t)s->నిరంతరం_ptr
             && pc  < (addr_t)s->నిరంతరం_ptr + s->నిరంతరం_కొలత)
                తిరిగి s;
        }
    }
    తిరిగి ఖాళీ;
}

స్థిర శూన్య rt_exit(rt_చట్రం *f, పూర్ణాంకం సంకేతం_2)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_కనుగొను_state(f);
    rt_post_sem();
    ఒకవేళ (s && s->నిరంతరం_lj) {
#నిర్వచితమైతే CONFIG_TCC_BCHECK
        ఒకవేళ (f->fp) { /* called from signal */
            శూన్య *p = tcc_get_చిహ్నం(s, "__bound_exit");
            ఒకవేళ (p)
                ((శూన్య (*)(శూన్య))p)();
        }
#అయితే_ముగింపు
        ఒకవేళ (సంకేతం_2 == 0)
            సంకేతం_2 = RT_EXIT_ZERO;
        ((శూన్య(*)(శూన్య*,పూర్ణాంకం))s->నిరంతరం_lj)(s->నిరంతరం_jb, సంకేతం_2);
    }
    నిష్క్రమించు(సంకేతం_2);
}

/* ------------------------------------------------------------- */
#లేకపోతే // if defined CONFIG_TCC_BACKTRACE_ONLY
స్థిర శూన్య rt_exit(rt_చట్రం *f, పూర్ణాంకం సంకేతం_2)
{
    నిష్క్రమించు(సంకేతం_2);
}
#అయితే_ముగింపు //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#నిర్వచితమైతే CONFIG_TCC_BACKTRACE

స్థిర పూర్ణాంకం rt_vprintf(స్థిరరాశి అక్షరం *fmt, va_list ap)
{
    పూర్ణాంకం ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    తిరిగి ret;
}

స్థిర పూర్ణాంకం rt_printf(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap;
    పూర్ణాంకం r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    తిరిగి r;
}

స్థిర అక్షరం *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    కొరకు (esym = rc->esym_ప్రారంభం + 1; esym < rc->esym_చివర; ++esym) {
        పూర్ణాంకం type = ELFW(ST_TYPE)(esym->st_info);
        ఒకవేళ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_విలువ
            && wanted_pc < esym->st_విలువ + esym->st_కొలత) {
            *func_addr = esym->st_విలువ;
            తిరిగి rc->elf_str + esym->st_name;
        }
    }
    తిరిగి ఖాళీ;
}

రకనిర్వచనం నిర్మాణం bt_info
{
    అక్షరం file[100];
    పూర్ణాంకం పంక్తి;
    అక్షరం func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
స్థిర addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    అక్షరం func_name[128];
    addr_t func_addr, చివరి_pc, pc;
    స్థిరరాశి అక్షరం *incl_files[INCLUDE_దొంతర_కొలత];
    పూర్ణాంకం incl_సూచీ, చివరి_incl_సూచీ, len, చివరి_పంక్తి_అంకె, i;
    స్థిరరాశి అక్షరం *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_సూచీ = 0;
    చివరి_pc = (addr_t)-1;
    చివరి_పంక్తి_అంకె = 1;
    చివరి_incl_సూచీ = 0;

    కొరకు (sym = rc->stab_sym + 1; sym < rc->stab_sym_చివర; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_విలువ;

        ఎంపిక(sym->n_type) {
        స్థితి N_SLINE:
            ఒకవేళ (func_addr)
                వెళ్ళు rel_pc;
        స్థితి N_SO:
        స్థితి N_SOL:
            వెళ్ళు abs_pc;
        స్థితి N_FUN:
            ఒకవేళ (sym->n_strx == 0) /* end of function */
                వెళ్ళు rel_pc;
        abs_pc:
#ఒకవేళ PTR_కొలత == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_పునాది;
#అయితే_ముగింపు
            వెళ్ళు check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ఒకవేళ (pc >= wanted_pc && wanted_pc >= చివరి_pc)
                వెళ్ళు దొరికింది;
            ఆపు;
        }

        ఎంపిక(sym->n_type) {
            /* function start or end */
        స్థితి N_FUN:
            ఒకవేళ (sym->n_strx == 0)
                వెళ్ళు reset_func;
            p = strchr(str, ':');
            ఒకవేళ (0 == p || (len = p - str + 1, len > పరిమాణం func_name))
                len = పరిమాణం func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ఆపు;
            /* line number info */
        స్థితి N_SLINE:
            చివరి_pc = pc;
            చివరి_పంక్తి_అంకె = sym->n_desc;
            చివరి_incl_సూచీ = incl_సూచీ;
            ఆపు;
            /* include files */
        స్థితి N_BINCL:
            ఒకవేళ (incl_సూచీ < INCLUDE_దొంతర_కొలత)
                incl_files[incl_సూచీ++] = str;
            ఆపు;
        స్థితి N_EINCL:
            ఒకవేళ (incl_సూచీ > 1)
                incl_సూచీ--;
            ఆపు;
            /* start/end of translation unit */
        స్థితి N_SO:
            incl_సూచీ = 0;
            ఒకవేళ (sym->n_strx) {
                /* do not add path */
                len = అక్షరశ్రేణి_పొడవు(str);
                ఒకవేళ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_సూచీ++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            చివరి_pc = (addr_t)-1;
            ఆపు;
            /* alternative file name (from #line or #include directives) */
        స్థితి N_SOL:
            ఒకవేళ (incl_సూచీ)
                incl_files[incl_సూచీ-1] = str;
            ఆపు;
        }
    }
    చివరి_incl_సూచీ = 0, func_name[0] = 0, func_addr = 0;
దొరికింది:
    i = చివరి_incl_సూచీ;
    ఒకవేళ (i > 0) {
        pstrcpy(bi->file, పరిమాణం bi->file, incl_files[--i]);
        bi->పంక్తి = చివరి_పంక్తి_అంకె;
    }
    pstrcpy(bi->func, పరిమాణం bi->func, func_name);
    bi->func_pc = func_addr;
    తిరిగి func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#నిర్వచించు DIR_పట్టిక_కొలత	(64)
#నిర్వచించు FILE_పట్టిక_కొలత	(512)

#నిర్వచించు	dwarf_ignore_type(ln, చివర) /* timestamp/size/md5/... */ \
	ఎంపిక (నమోదు_format[j].form) { \
	స్థితి DW_FORM_data1: (ln) += 1; ఆపు; \
	స్థితి DW_FORM_data2: (ln) += 2; ఆపు; \
	స్థితి DW_FORM_data4: (ln) += 3; ఆపు; \
	స్థితి DW_FORM_data8: (ln) += 8; ఆపు; \
	స్థితి DW_FORM_data16: (ln) += 16; ఆపు; \
	స్థితి DW_FORM_udata: dwarf_read_uleb128(&(ln), (చివర)); ఆపు; \
	అప్రమేయ: వెళ్ళు తదుపరి_పంక్తి; \
	}

స్థిర addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    గుర్తులేని అక్షరం *ln;
    గుర్తులేని అక్షరం *cp;
    గుర్తులేని అక్షరం *చివర;
    గుర్తులేని అక్షరం *opcode_నిడివి;
    గుర్తులేని దీర్ఘ దీర్ఘ కొలత;
    గుర్తులేని పూర్ణాంకం నిడివి;
    గుర్తులేని అక్షరం సంస్కరణ;
    గుర్తులేని పూర్ణాంకం min_insn_నిడివి;
    గుర్తులేని పూర్ణాంకం max_ops_చొప్పున_insn;
    పూర్ణాంకం పంక్తి_పునాది;
    గుర్తులేని పూర్ణాంకం పంక్తి_range;
    గుర్తులేని పూర్ణాంకం opcode_పునాది;
    గుర్తులేని పూర్ణాంకం opindex;
    గుర్తులేని పూర్ణాంకం నిలువు;
    గుర్తులేని పూర్ణాంకం i;
    గుర్తులేని పూర్ణాంకం j;
    గుర్తులేని పూర్ణాంకం len;
    గుర్తులేని దీర్ఘ దీర్ఘ విలువ;
    నిర్మాణం {
	గుర్తులేని పూర్ణాంకం type;
	గుర్తులేని పూర్ణాంకం form;
    } నమోదు_format[256];
    గుర్తులేని పూర్ణాంకం dir_కొలత;
#ఒకవేళ 0
    అక్షరం *dirs[DIR_పట్టిక_కొలత];
#అయితే_ముగింపు
    గుర్తులేని పూర్ణాంకం filename_కొలత;
    నిర్మాణం /*dwarf_filename_struct*/ {
        గుర్తులేని పూర్ణాంకం dir_నమోదు;
        అక్షరం *name;
    } filename_పట్టిక[FILE_పట్టిక_కొలత];
    addr_t చివరి_pc;
    addr_t pc;
    addr_t func_addr;
    పూర్ణాంకం పంక్తి;
    అక్షరం *filename;
    అక్షరం *function;

    filename = ఖాళీ;
    function = ఖాళీ;
    func_addr = 0;
    పంక్తి = 0;

    ln = rc->dwarf_పంక్తి;
    అయితే (ln < rc->dwarf_పంక్తి_చివర) {
	dir_కొలత = 0;
	filename_కొలత = 0;
        చివరి_pc = 0;
        pc = 0;
        func_addr = 0;
        పంక్తి = 1;
        filename = ఖాళీ;
        function = ఖాళీ;
	నిడివి = 4;
	కొలత = dwarf_read_4(ln, rc->dwarf_పంక్తి_చివర);
	ఒకవేళ (కొలత == 0xffffffffu) // dwarf 64
	    నిడివి = 8, కొలత = dwarf_read_8(ln, rc->dwarf_పంక్తి_చివర);
	చివర = ln + కొలత;
	ఒకవేళ (చివర < ln || చివర > rc->dwarf_పంక్తి_చివర)
	    ఆపు;
	సంస్కరణ = dwarf_read_2(ln, చివర);
	ఒకవేళ (సంస్కరణ >= 5)
	    ln += నిడివి + 2; // address size, segment selector, prologue Length
	లేకపోతే
	    ln += నిడివి; // prologue Length
	min_insn_నిడివి = dwarf_read_1(ln, చివర);
	ఒకవేళ (సంస్కరణ >= 4)
	    max_ops_చొప్పున_insn = dwarf_read_1(ln, చివర);
	లేకపోతే
	    max_ops_చొప్పున_insn = 1;
	ln++; // Initial value of 'is_stmt'
	పంక్తి_పునాది = dwarf_read_1(ln, చివర);
	పంక్తి_పునాది |= పంక్తి_పునాది >= 0x80 ? ~0xff : 0;
	పంక్తి_range = dwarf_read_1(ln, చివర);
	opcode_పునాది = dwarf_read_1(ln, చివర);
	opcode_నిడివి = ln;
	ln += opcode_పునాది - 1;
	opindex = 0;
	ఒకవేళ (సంస్కరణ >= 5) {
	    నిలువు = dwarf_read_1(ln, చివర);
	    కొరకు (i = 0; i < నిలువు; i++) {
	        నమోదు_format[i].type = dwarf_read_uleb128(&ln, చివర);
	        నమోదు_format[i].form = dwarf_read_uleb128(&ln, చివర);
	    }
	    dir_కొలత = dwarf_read_uleb128(&ln, చివర);
	    కొరకు (i = 0; i < dir_కొలత; i++) {
		కొరకు (j = 0; j < నిలువు; j++) {
		    ఒకవేళ (నమోదు_format[j].type == DW_LNCT_మార్గం) {
		        ఒకవేళ (నమోదు_format[j].form != DW_FORM_పంక్తి_strp)
			    వెళ్ళు తదుపరి_పంక్తి;
#ఒకవేళ 0
		        విలువ = నిడివి == 4 ? dwarf_read_4(ln, చివర)
					    : dwarf_read_8(ln, చివర);
		        ఒకవేళ (i < DIR_పట్టిక_కొలత)
		            dirs[i] = (అక్షరం *)rc->dwarf_పంక్తి_str + విలువ;
#లేకపోతే
			నిడివి == 4 ? dwarf_read_4(ln, చివర)
				    : dwarf_read_8(ln, చివర);
#అయితే_ముగింపు
		    }
		    లేకపోతే 
			dwarf_ignore_type(ln, చివర);
		}
	    }
	    నిలువు = dwarf_read_1(ln, చివర);
	    కొరకు (i = 0; i < నిలువు; i++) {
	        నమోదు_format[i].type = dwarf_read_uleb128(&ln, చివర);
	        నమోదు_format[i].form = dwarf_read_uleb128(&ln, చివర);
	    }
	    filename_కొలత = dwarf_read_uleb128(&ln, చివర);
	    కొరకు (i = 0; i < filename_కొలత; i++)
		కొరకు (j = 0; j < నిలువు; j++) {
		    ఒకవేళ (నమోదు_format[j].type == DW_LNCT_మార్గం) {
			ఒకవేళ (నమోదు_format[j].form != DW_FORM_పంక్తి_strp)
			    వెళ్ళు తదుపరి_పంక్తి;
			విలువ = నిడివి == 4 ? dwarf_read_4(ln, చివర)
					    : dwarf_read_8(ln, చివర);
		        ఒకవేళ (i < FILE_పట్టిక_కొలత)
		            filename_పట్టిక[i].name =
				(అక్షరం *)rc->dwarf_పంక్తి_str + విలువ;
	            }
		    లేకపోతే ఒకవేళ (నమోదు_format[j].type == DW_LNCT_directory_సూచీ) {
			ఎంపిక (నమోదు_format[j].form) {
			స్థితి DW_FORM_data1: విలువ = dwarf_read_1(ln, చివర); ఆపు;
			స్థితి DW_FORM_data2: విలువ = dwarf_read_2(ln, చివర); ఆపు;
			స్థితి DW_FORM_data4: విలువ = dwarf_read_4(ln, చివర); ఆపు;
			స్థితి DW_FORM_udata: విలువ = dwarf_read_uleb128(&ln, చివర); ఆపు;
			అప్రమేయ: వెళ్ళు తదుపరి_పంక్తి;
			}
		        ఒకవేళ (i < FILE_పట్టిక_కొలత)
		            filename_పట్టిక[i].dir_నమోదు = విలువ;
		    }
		    లేకపోతే 
			dwarf_ignore_type(ln, చివర);
	    }
	}
	లేకపోతే {
	    అయితే ((dwarf_read_1(ln, చివర))) {
#ఒకవేళ 0
		ఒకవేళ (++dir_కొలత < DIR_పట్టిక_కొలత)
		    dirs[dir_కొలత - 1] = (అక్షరం *)ln - 1;
#అయితే_ముగింపు
		అయితే (dwarf_read_1(ln, చివర)) {}
	    }
	    అయితే ((dwarf_read_1(ln, చివర))) {
		ఒకవేళ (++filename_కొలత < FILE_పట్టిక_కొలత) {
		    filename_పట్టిక[filename_కొలత - 1].name = (అక్షరం *)ln - 1;
		    అయితే (dwarf_read_1(ln, చివర)) {}
		    filename_పట్టిక[filename_కొలత - 1].dir_నమోదు =
		        dwarf_read_uleb128(&ln, చివర);
		}
		లేకపోతే {
		    అయితే (dwarf_read_1(ln, చివర)) {}
		    dwarf_read_uleb128(&ln, చివర);
		}
		dwarf_read_uleb128(&ln, చివర); //సమయం
		dwarf_read_uleb128(&ln, చివర); //కొలత
	    }
	}
	ఒకవేళ (filename_కొలత >= 1)
	    filename = filename_పట్టిక[0].name;
	అయితే (ln < చివర) {
	    చివరి_pc = pc;
	    i = dwarf_read_1(ln, చివర);
	    ఒకవేళ (i >= opcode_పునాది) {
	        ఒకవేళ (max_ops_చొప్పున_insn == 1)
		    pc += ((i - opcode_పునాది) / పంక్తి_range) * min_insn_నిడివి;
		లేకపోతే {
		    pc += (opindex + (i - opcode_పునాది) / పంక్తి_range) /
			  max_ops_చొప్పున_insn * min_insn_నిడివి;
		    opindex = (opindex + (i - opcode_పునాది) / పంక్తి_range) %
			       max_ops_చొప్పున_insn;
		}
		i = (పూర్ణాంకం)((i - opcode_పునాది) % పంక్తి_range) + పంక్తి_పునాది;
check_pc:
		ఒకవేళ (pc >= wanted_pc && wanted_pc >= చివరి_pc)
		    వెళ్ళు దొరికింది;
		పంక్తి += i;
	    }
	    లేకపోతే {
	        ఎంపిక (i) {
	        స్థితి 0:
		    len = dwarf_read_uleb128(&ln, చివర);
		    cp = ln;
		    ln += len;
		    ఒకవేళ (len == 0)
		        వెళ్ళు తదుపరి_పంక్తి;
		    ఎంపిక (dwarf_read_1(cp, చివర)) {
		    స్థితి DW_LNE_చివర_sequence:
		        ఆపు;
		    స్థితి DW_LNE_సమితి_చిరునామా:
#ఒకవేళ PTR_కొలత == 4
		        pc = dwarf_read_4(cp, చివర);
#లేకపోతే
		        pc = dwarf_read_8(cp, చివర);
#అయితే_ముగింపు
#ఒకవేళ defined TCC_లక్ష్యం_MACHO
			pc += rc->prog_పునాది;
#అయితే_ముగింపు
		        opindex = 0;
		        ఆపు;
		    స్థితి DW_LNE_define_file: /* deprecated */
		        ఒకవేళ (++filename_కొలత < FILE_పట్టిక_కొలత) {
		            filename_పట్టిక[filename_కొలత - 1].name = (అక్షరం *)ln - 1;
		            అయితే (dwarf_read_1(ln, చివర)) {}
		            filename_పట్టిక[filename_కొలత - 1].dir_నమోదు =
		                dwarf_read_uleb128(&ln, చివర);
		        }
		        లేకపోతే {
		            అయితే (dwarf_read_1(ln, చివర)) {}
		            dwarf_read_uleb128(&ln, చివర);
		        }
		        dwarf_read_uleb128(&ln, చివర); //సమయం
		        dwarf_read_uleb128(&ln, చివర); //కొలత
		        ఆపు;
		    స్థితి DW_LNE_hi_user - 1:
		        function = (అక్షరం *)cp;
		        func_addr = pc;
		        ఆపు;
		    అప్రమేయ:
		        ఆపు;
		    }
		    ఆపు;
	        స్థితి DW_LNS_advance_pc:
		    ఒకవేళ (max_ops_చొప్పున_insn == 1)
		        pc += dwarf_read_uleb128(&ln, చివర) * min_insn_నిడివి;
		    లేకపోతే {
		        గుర్తులేని దీర్ఘ దీర్ఘ off = dwarf_read_uleb128(&ln, చివర);

		        pc += (opindex + off) / max_ops_చొప్పున_insn *
			      min_insn_నిడివి;
		        opindex = (opindex + off) % max_ops_చొప్పున_insn;
		    }
		    i = 0;
		    వెళ్ళు check_pc;
	        స్థితి DW_LNS_advance_పంక్తి:
		    పంక్తి += dwarf_read_sleb128(&ln, చివర);
		    ఆపు;
	        స్థితి DW_LNS_సమితి_file:
		    i = dwarf_read_uleb128(&ln, చివర);
		    i -= i > 0 && సంస్కరణ < 5;
		    ఒకవేళ (i < FILE_పట్టిక_కొలత && i < filename_కొలత)
		        filename = filename_పట్టిక[i].name;
		    ఆపు;
	        స్థితి DW_LNS_const_కూడు_pc:
		    ఒకవేళ (max_ops_చొప్పున_insn ==  1)
		        pc += ((255 - opcode_పునాది) / పంక్తి_range) * min_insn_నిడివి;
		    లేకపోతే {
		        గుర్తులేని పూర్ణాంకం off = (255 - opcode_పునాది) / పంక్తి_range;

		        pc += ((opindex + off) / max_ops_చొప్పున_insn) *
			      min_insn_నిడివి;
		        opindex = (opindex + off) % max_ops_చొప్పున_insn;
		    }
		    i = 0;
		    వెళ్ళు check_pc;
	        స్థితి DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, చివర);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    వెళ్ళు check_pc;
	        అప్రమేయ:
		    కొరకు (j = 0; j < opcode_నిడివి[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, చివర);
		    ఆపు;
		}
	    }
	}
తదుపరి_పంక్తి:
	ln = చివర;
    }
    filename = function = ఖాళీ, func_addr = 0;
దొరికింది:
    ఒకవేళ (filename)
        pstrcpy(bi->file, పరిమాణం bi->file, filename), bi->పంక్తి = పంక్తి;
    ఒకవేళ (function)
        pstrcpy(bi->func, పరిమాణం bi->func, function);
    bi->func_pc = func_addr;
    తిరిగి (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#నిర్వచితం_కాకపోతే CONFIG_TCC_BACKTRACE_ONLY
స్థిర
#అయితే_ముగింపు
పూర్ణాంకం _tcc_backtrace(rt_చట్రం *f, స్థిరరాశి అక్షరం *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    అక్షరం skip[40], సందేశం[200];
    పూర్ణాంకం i, level, ret, n, one;
    స్థిరరాశి అక్షరం *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ఒకవేళ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        జ్ఞాపకం_నకలు(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ఒకవేళ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(సందేశం, పరిమాణం సందేశం, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ఒకవేళ (rc) {
        ఒకవేళ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ఒకవేళ (rc->అంకె_callers)
            n = rc->అంకె_callers;
    }

    కొరకు (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ఒకవేళ (ret == -1)
            ఆపు;
        memset(&bi, 0, పరిమాణం bi);
        కొరకు (rc2 = rc; rc2; rc2 = rc2->తదుపరి) {
            ఒకవేళ (getinfo(rc2, pc, &bi))
                ఆపు;
            /* we try symtab symbols (no line number info) */
            ఒకవేళ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, పరిమాణం bi.func, a);
                ఆపు;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ఒకవేళ (skip[0] && అక్షరశ్రేణి_శోధన(bi.file, skip))
            కొనసాగు;
#నిర్వచితం_కాకపోతే CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_కనుగొను_state(f);
            ఒకవేళ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_దత్తాంశం,
                    (శూన్య*)pc,
                    bi.file[0] ? bi.file : ఖాళీ,
                    bi.పంక్తి,
                    bi.func[0] ? bi.func : ఖాళీ,
                    level == 0 ? సందేశం : ఖాళీ
                    );
                ఒకవేళ (ret == 0)
                    ఆపు;
                వెళ్ళు check_break;
            }
        }
#అయితే_ముగింపు
        ఒకవేళ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.పంక్తి);
        } లేకపోతే {
            rt_printf("0x%08llx", (దీర్ఘ దీర్ఘ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ఒకవేళ (level == 0) {
            rt_printf(": %s", సందేశం);
            ఒకవేళ (one)
                ఆపు;
        }
        rt_printf("\n");

#నిర్వచితం_కాకపోతే CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#అయితే_ముగింపు
        ఒకవేళ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->శిఖరం_func)
            ఆపు;
        ++level;
    }
    rt_post_sem();
    తిరిగి 0;
}

/* emit a run time error at position 'pc' */
స్థిర పూర్ణాంకం rt_error(rt_చట్రం *f, స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap; అక్షరం సందేశం[200]; పూర్ణాంకం ret;
    va_start(ap, fmt);
    snprintf(సందేశం, పరిమాణం సందేశం, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, సందేశం, ap);
    va_end(ap);
    తిరిగి ret;
}

/* ------------------------------------------------------------- */

#నిర్వచితం_కాకపోతే _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#లేకపోతే
# define ucontext_t CONTEXT
#అయితే_ముగింపు

/* translate from ucontext_t* to internal rt_context * */
స్థిర శూన్య rt_getcontext(ucontext_t *uc, rt_చట్రం *rc)
{
#ఒకవేళ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#లేదావేళ defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#లేదావేళ defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#లేదావేళ defined __i386__
# ఒకవేళ defined(__APPLE__)
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
# లేకపోతే
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#లేదావేళ defined(__x86_64__)
# ఒకవేళ defined(__APPLE__)
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
# లేకపోతే
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#లేదావేళ defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#లేదావేళ defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#లేదావేళ defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#లేదావేళ defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#లేదావేళ defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#లేదావేళ defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#లేదావేళ defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#లేదావేళ defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#లేదావేళ defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#లేదావేళ defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#లేదావేళ defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#అయితే_ముగింపు
}

/* ------------------------------------------------------------- */
#నిర్వచితం_కాకపోతే _WIN32
/* signal handler for fatal errors */
స్థిర శూన్య sig_error(పూర్ణాంకం signum, siginfo_t *siginf, శూన్య *puc)
{
    rt_చట్రం f;
    rt_getcontext(puc, &f);

    ఎంపిక(signum) {
    స్థితి SIGFPE:
        ఎంపిక(siginf->si_code) {
        స్థితి FPE_INTDIV:
        స్థితి FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ఆపు;
        అప్రమేయ:
            rt_error(&f, "floating point exception");
            ఆపు;
        }
        ఆపు;
    స్థితి SIGBUS:
    స్థితి SIGSEGV:
        rt_error(&f, "invalid memory access");
        ఆపు;
    స్థితి SIGILL:
        rt_error(&f, "illegal instruction");
        ఆపు;
    స్థితి SIGABRT:
        rt_error(&f, "abort() called");
        ఆపు;
    అప్రమేయ:
        rt_error(&f, "caught signal %d", signum);
        ఆపు;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ఖాళీ);
    }
    rt_exit(&f, 255);
}

#నిర్వచితం_కాకపోతే SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#అయితే_ముగింపు

/* Generate a stack backtrace when a CPU exception occurs. */
స్థిర శూన్య సమితి_exception_handler(శూన్య)
{
    నిర్మాణం sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ఒకవేళ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#అయితే_ముగింపు
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ఖాళీ);
    sigaction(SIGILL, &sigact, ఖాళీ);
    sigaction(SIGSEGV, &sigact, ఖాళీ);
    sigaction(SIGBUS, &sigact, ఖాళీ);
    sigaction(SIGABRT, &sigact, ఖాళీ);
#ఒకవేళ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        స్థిర గుర్తులేని అక్షరం దొంతర[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = దొంతర;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ఖాళీ);
    }
#అయితే_ముగింపు
}

#లేకపోతే /* WIN32 */

/* signal handler for fatal errors */
స్థిర దీర్ఘ __stdcall cpu_exception_handler(EXCEPTION_సూచికలు *ex_info)
{
    rt_చట్రం f;
    గుర్తులేని సంకేతం_2;
    rt_getcontext(ex_info->Context_రికార్డు, &f);

    ఎంపిక (సంకేతం_2 = ex_info->Exception_రికార్డు->Exception_సంకేతం) {
    స్థితి EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ఆపు;
    స్థితి EXCEPTION_దొంతర_అధికప్రవాహం:
        rt_error(&f, "stack overflow");
        ఆపు;
    స్థితి EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ఆపు;
    స్థితి EXCEPTION_BREAKPOINT:
    స్థితి EXCEPTION_SINGLE_అడుగు:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        తిరిగి EXCEPTION_CONTINUE_శోధన;
    అప్రమేయ:
        rt_error(&f, "caught exception %08x", సంకేతం_2);
        ఆపు;
    }
    rt_exit(&f, 255);
    తిరిగి EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
స్థిర శూన్య సమితి_exception_handler(శూన్య)
{
#నిర్వచితమైతే _WIN64
    కూడు_Vectored_Exception_Handler(1, cpu_exception_handler);
#లేకపోతే
    సమితి_Unhandled_Exception_Filter(cpu_exception_handler);
#అయితే_ముగింపు
}

#అయితే_ముగింపు

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ఒకవేళ defined(__i386__) || defined(__x86_64__)
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *rc, పూర్ణాంకం level)
{
    ఒకవేళ (level == 0) {
        *paddr = rc->ip;
    } లేకపోతే {
        addr_t fp = rc->fp;
        అయితే (1) {
            ఒకవేళ (fp < 0x1000)
                తిరిగి -1;
            ఒకవేళ (0 == --level)
                ఆపు;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    తిరిగి 0;
}

/* XXX: only supports linux/bsd */
#లేదావేళ defined(__arm__) && !defined(_WIN32)
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *rc, పూర్ణాంకం level)
{
    ఒకవేళ (level == 0) {
        *paddr = rc->ip;
    } లేకపోతే {
        addr_t fp = rc->fp;
        అయితే (1) {
            ఒకవేళ (fp < 0x1000)
                తిరిగి -1;
            ఒకవేళ (0 == --level)
                ఆపు;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    తిరిగి 0;
}

#లేదావేళ defined(__aarch64__)
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *rc, పూర్ణాంకం level)
{
    ఒకవేళ (level == 0) {
        *paddr = rc->ip;
    } లేకపోతే {
        addr_t fp = rc->fp;
        అయితే (1) {
            ఒకవేళ (fp < 0x1000)
                తిరిగి -1;
            ఒకవేళ (0 == --level)
                ఆపు;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    తిరిగి 0;
}

#లేదావేళ defined(__riscv)
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *rc, పూర్ణాంకం level)
{
    ఒకవేళ (level == 0) {
        *paddr = rc->ip;
    } లేకపోతే {
        addr_t fp = rc->fp;
        అయితే (1) {
            ఒకవేళ (fp < 0x1000)
                తిరిగి -1;
            ఒకవేళ (0 == --level)
                ఆపు;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    తిరిగి 0;
}

#లేకపోతే
#warning కూడు arch specific rt_get_caller_pc()
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *rc, పూర్ణాంకం level)
{
    తిరిగి -1;
}

#అయితే_ముగింపు
#లేకపోతే // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
స్థిర పూర్ణాంకం rt_get_caller_pc(addr_t *paddr, rt_చట్రం *f, పూర్ణాంకం level)
{
    ఒకవేళ (level)
        తిరిగి -1;
    *paddr = f->ip;
    తిరిగి 0;
}
#అయితే_ముగింపు /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#నిర్వచితమైతే CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC శూన్య *dlopen(స్థిరరాశి అక్షరం *filename, పూర్ణాంకం flag)
{
    తిరిగి ఖాళీ;
}

ST_FUNC శూన్య dlclose(శూన్య *p)
{
}

ST_FUNC స్థిరరాశి అక్షరం *dlerror(శూన్య)
{
    తిరిగి "error";
}

రకనిర్వచనం నిర్మాణం TCCSyms {
    అక్షరం *str;
    శూన్య *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
స్థిర TCCSyms tcc_syms[] = {
#ఒకవేళ !defined(CONFIG_TCCBOOT)
#నిర్వచించు TCCSYM(a) { #a, &a, },
    TCCSYM(రాయి)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#నిర్వచనం_రద్దు TCCSYM
#అయితే_ముగింపు
    { ఖాళీ, ఖాళీ },
};

ST_FUNC శూన్య *dlsym(శూన్య *handle, స్థిరరాశి అక్షరం *చిహ్నం)
{
    TCCSyms *p;
    p = tcc_syms;
    అయితే (p->str != ఖాళీ) {
        ఒకవేళ (!strcmp(p->str, చిహ్నం))
            తిరిగి p->ptr;
        p++;
    }
    తిరిగి ఖాళీ;
}

#అయితే_ముగింపు /* CONFIG_TCC_STATIC */
#అయితే_ముగింపు /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
