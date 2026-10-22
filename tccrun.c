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

#অন্তর্ভাৱ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
প্রকারনির্দেশ সংরচনা rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    সঙ্ঘ {
	সংরচনা {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    ৱর্ণ *stab_str;
	};
	সংরচনা {
	    unsigned ৱর্ণ *dwarf_সাৰি;
	    unsigned ৱর্ণ *dwarf_সাৰি_end;
	    unsigned ৱর্ণ *dwarf_সাৰি_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    ৱর্ণ *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    শূন্য *bounds_start;
    শূন্য *শীৰ্ষ_func;
    সংরচনা rt_context *next;
    // 10 * PTR_SIZE
    পূর্ণাঙ্ক অঙ্ক_callers;
    পূর্ণাঙ্ক dwarf;
} rt_context;

/* linked list of rt_contexts */
স্থির rt_context *g_rc;
স্থির পূর্ণাঙ্ক signal_set;
স্থির শূন্য set_exception_handler(শূন্য);
#endif /* def CONFIG_TCC_BACKTRACE */

প্রকারনির্দেশ সংরচনা rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

স্থির TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(স্থির rt_sem);
স্থির শূন্য rt_wait_sem(শূন্য) { WAIT_SEM(&rt_sem); }
স্থির শূন্য rt_post_sem(শূন্য) { POST_SEM(&rt_sem); }
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *f, পূর্ণাঙ্ক level);
স্থির শূন্য rt_exit(rt_frame *f, পূর্ণাঙ্ক code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

স্থির পূর্ণাঙ্ক protect_pages(শূন্য *ptr, unsigned long length, পূর্ণাঙ্ক mode);
স্থির পূর্ণাঙ্ক tcc_relocate_ex(TCCState *s1, শূন্য *ptr, unsigned ptr_diff);
স্থির শূন্য st_link(TCCState *s1);
স্থির শূন্য st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
স্থির পূর্ণাঙ্ক _tcc_backtrace(rt_frame *f, ধ্রুৱ ৱর্ণ *fmt, va_list ap);
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

স্থির পূর্ণাঙ্ক rt_mem(TCCState *s1, পূর্ণাঙ্ক size)
{
    শূন্য *ptr;
    পূর্ণাঙ্ক ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    শূন্য *prw;
    ৱর্ণ tmpfname[] = "/tmp/.tccrunXXXXXX";
    পূর্ণাঙ্ক fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(রিক্ত, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((ৱর্ণ*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    যদি (ptr == MAP_FAILED || prw == MAP_FAILED)
	ঘূৰাই tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (ৱর্ণ*)prw - (ৱর্ণ*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#নোচেদ্যদি CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(রিক্ত, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    যদি (!ptr)
        ঘূৰাই tcc_error_noabort("tccrun: could not allocate memory");
#অন্যথা
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    ঘূৰাই ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI পূর্ণাঙ্ক tcc_relocate(TCCState *s1)
{
    পূর্ণাঙ্ক size, ret, ptr_diff;

    যদি (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->do_backtrace)
        tcc_add_প্ৰতীক(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, রিক্ত, 0);
    যদি (size < 0)
        ঘূৰাই -1;
    ptr_diff = rt_mem(s1, size);
    যদি (ptr_diff < 0)
        ঘূৰাই -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    যদি (ret == 0)
        st_link(s1);
    ঘূৰাই ret;
}

ST_FUNC শূন্য tcc_run_free(TCCState *s1)
{
    unsigned size;
    শূন্য *ptr;
    পূর্ণাঙ্ক i;

    /* free any loaded DLLs */
    বাবে ( i = 0; i < s1->nb_loaded_dlls; i++) {
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
    যদি (রিক্ত == ptr)
        ঘূৰাই;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#নোচেদ্যদি CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#অন্যথা
    /* unprotect memory to make it usable for malloc again */
    protect_pages((শূন্য*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI পূর্ণাঙ্ক tcc_run(TCCState *s1, পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    পূর্ণাঙ্ক (*prog_main)(পূর্ণাঙ্ক, ৱর্ণ **, ৱর্ণ **), ret;
    ধ্রুৱ ৱর্ণ *শীৰ্ষ_sym;
    jmp_buf main_jb;

#যদি defined(__APPLE__)
    বাহ্য ৱর্ণ ***_NSGetEnviron(শূন্য);
    ৱর্ণ **envp = *_NSGetEnviron();
#নোচেদ্যদি defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    বাহ্য ৱর্ণ **environ;
    ৱর্ণ **envp = environ;
#অন্যথা
    ৱর্ণ **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    যদি ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ঘূৰাই 0;

    tcc_add_প্ৰতীক(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", শীৰ্ষ_sym = "main";
    যদি (s1->elf_entryname)
        s1->run_main = শীৰ্ষ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    যদি (tcc_relocate(s1) < 0)
        ঘূৰাই -1;

    prog_main = (শূন্য*)get_sym_addr(s1, s1->run_main, 1, 1);
    যদি ((addr_t)-1 == (addr_t)prog_main)
        ঘূৰাই -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    যদি (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ঘূৰাই -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_প্ৰতীক(s1, শীৰ্ষ_sym));
    যদি (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } অন্যথা যদি (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    যদি (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ঘূৰাই ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
স্থির শূন্য cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    পূর্ণাঙ্ক sym_index, end_sym = s->data_offset / পরিমাণ (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    বাবে (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ধ্রুৱ ৱর্ণ *name = (ৱর্ণ *)s->link->data + sym->st_name;
        যদি (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            অনুৱর্ত;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_মান, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
স্থির শূন্য cleanup_sections(TCCState *s1)
{
    সংরচনা { Section **secs; পূর্ণাঙ্ক nb_secs; } *p = (শূন্য*)&s1->sections;
    পূর্ণাঙ্ক i, f = 2;
    কৰা {
        বাবে (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            যদি (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } অন্যথা {
                free_section(s), tcc_free(s), p->secs[i] = রিক্ত;
            }
        }
    } যেতিয়ালৈ (++p, f);
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
স্থির পূর্ণাঙ্ক tcc_relocate_ex(TCCState *s1, শূন্য *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    যদি (রিক্ত == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, রিক্ত);
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
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    যদি (s1->nb_errors)
        ঘূৰাই -1;
    যদি (copy == 3)
        ঘূৰাই 0;

    বাবে (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        বাবে(i = 1; i < s1->nb_sections; i++) {
            স্থির ধ্রুৱ ৱর্ণ shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            যদি (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                অনুৱর্ত;
            length = s->data_offset;
            যদি (copy == 2) {
                যদি (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                অনুৱর্ত;
            }
            যদি (copy) { /* final step: copy section data to memory */
                যদি (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (শূন্য*)s->sh_addr, length, s->sh_addralign);
                ptr = (শূন্য*)s->sh_addr;
                যদি (k == 0)
                    ptr = (শূন্য*)(s->sh_addr + ptr_diff);
                যদি (রিক্ত == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                অন্যথা
                    memcpy(ptr, s->data, length);
                অনুৱর্ত;
            }

            যদি ((s->sh_flags & SHF_TLS) && length)
                ঘূৰাই tcc_error_noabort("thread-local storage not supported with -run");

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
            offset += length;
        }
        যদি (copy == 2) { /* set permissions */
            যদি (n == 0) /* no data  */
                অনুৱর্ত;
#ifdef CONFIG_SELINUX
            যদি (k == 0) /* SHF_EXECINSTR has its own mapping */
                অনুৱর্ত;
#endif
            f = k;
            যদি (f >= CONFIG_RUNMEM_RO) {
                যদি (f != 0)
                    অনুৱর্ত;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            যদি (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (শূন্য*)addr, (unsigned)n);
            }
            যদি (protect_pages((শূন্য*)addr, n, f) < 0)
                ঘূৰাই tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#অন্যথা
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    যদি (0 == mem)
        ঘূৰাই PAGEALIGN(offset);

    যদি (++copy == 2) {
        গচ্ছ redo;
    }
    যদি (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        গচ্ছ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    যদি (s1->nb_errors)
        গচ্ছ redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#অন্যথা
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    গচ্ছ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

স্থির পূর্ণাঙ্ক protect_pages(শূন্য *ptr, unsigned long length, পূর্ণাঙ্ক mode)
{
#ifdef _WIN32
    স্থির ধ্রুৱ unsigned ৱর্ণ protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    যদি (!VirtualProtect(ptr, length, protect[mode], &old))
        ঘূৰাই -1;
#অন্যথা
    স্থির ধ্রুৱ unsigned ৱর্ণ protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    যদি (mprotect(ptr, length, protect[mode]))
        ঘূৰাই -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#যদি (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    যদি (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#অন্যথা
        শূন্য __clear_cache(শূন্য *beginning, শূন্য *end);
        __clear_cache(ptr, (ৱর্ণ *)ptr + length);
#endif
    }
#endif
    ঘূৰাই 0;
}

#ifdef _WIN64
স্থির শূন্য *win64_add_function_table(TCCState *s1)
{
    শূন্য *p = রিক্ত;
    যদি (s1->uw_pdata) {
        p = (শূন্য*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / পরিমাণ (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = রিক্ত;
    }
    ঘূৰাই p;
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
        ঘূৰাই;
    rc = tcc_get_প্ৰতীক(s1, "__rt_info");
    যদি (!rc)
        ঘূৰাই;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (ৱর্ণ *)symtab_section->link->data;
    যদি (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    যদি (s1->do_bounds_check) {
        শূন্য *p;
        যদি ((p = tcc_get_প্ৰতীক(s1, "__bound_init")))
            ((শূন্য(*)(শূন্য*,পূর্ণাঙ্ক))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    যদি (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

স্থির শূন্য st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
স্থির শূন্য ptr_unlink(শূন্য *list, শূন্য *e, unsigned next)
{
    শূন্য **pp, **nn, *p;
    বাবে (pp = list; !!(p = *pp); pp = nn) {
        nn = (শূন্য*)((ৱর্ণ*)p + next); /* nn = &p->next; */
        যদি (p == e) {
            *pp = *nn;
            ভঙ্গ;
        }
    }
}

স্থির শূন্য st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI শূন্য *_tcc_setjmp(TCCState *s1, শূন্য *p_jmp_buf, শূন্য *func, শূন্য *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    যদি (s1->rc)
        s1->rc->শীৰ্ষ_func = func;
#endif
    ঘূৰাই p_jmp_buf;
}

LIBTCCAPI শূন্য tcc_set_backtrace_func(TCCState *s1, শূন্য *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

স্থির TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    পূর্ণাঙ্ক level;
    addr_t pc;

    s = g_s1;
    যদি (রিক্ত == s || রিক্ত == s->next) {
        /* play it safe in the simple case when there is only one state */
        ঘূৰাই s;
    }
    বাবে (level = 0; level < 8; ++level) {
        যদি (rt_get_caller_pc(&pc, f, level) < 0)
            ভঙ্গ;
        বাবে (s = g_s1; s; s = s->next) {
            যদি (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                ঘূৰাই s;
        }
    }
    ঘূৰাই রিক্ত;
}

স্থির শূন্য rt_exit(rt_frame *f, পূর্ণাঙ্ক code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    যদি (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        যদি (f->fp) { /* called from signal */
            শূন্য *p = tcc_get_প্ৰতীক(s, "__bound_exit");
            যদি (p)
                ((শূন্য (*)(শূন্য))p)();
        }
#endif
        যদি (code == 0)
            code = RT_EXIT_ZERO;
        ((শূন্য(*)(শূন্য*,পূর্ণাঙ্ক))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#অন্যথা // if defined CONFIG_TCC_BACKTRACE_ONLY
স্থির শূন্য rt_exit(rt_frame *f, পূর্ণাঙ্ক code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

স্থির পূর্ণাঙ্ক rt_vprintf(ধ্রুৱ ৱর্ণ *fmt, va_list ap)
{
    পূর্ণাঙ্ক ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ঘূৰাই ret;
}

স্থির পূর্ণাঙ্ক rt_printf(ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list ap;
    পূর্ণাঙ্ক r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ঘূৰাই r;
}

স্থির ৱর্ণ *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    বাবে (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        পূর্ণাঙ্ক type = ELFW(ST_TYPE)(esym->st_info);
        যদি ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_মান
            && wanted_pc < esym->st_মান + esym->st_size) {
            *func_addr = esym->st_মান;
            ঘূৰাই rc->elf_str + esym->st_name;
        }
    }
    ঘূৰাই রিক্ত;
}

প্রকারনির্দেশ সংরচনা bt_info
{
    ৱর্ণ file[100];
    পূর্ণাঙ্ক সাৰি;
    ৱর্ণ func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
স্থির addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ৱর্ণ func_name[128];
    addr_t func_addr, last_pc, pc;
    ধ্রুৱ ৱর্ণ *incl_files[INCLUDE_স্তূপ_SIZE];
    পূর্ণাঙ্ক incl_index, last_incl_index, len, last_সাৰি_অঙ্ক, i;
    ধ্রুৱ ৱর্ণ *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_সাৰি_অঙ্ক = 1;
    last_incl_index = 0;

    বাবে (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_মান;

        ৱিকল্প(sym->n_type) {
        পক্ষ N_SLINE:
            যদি (func_addr)
                গচ্ছ rel_pc;
        পক্ষ N_SO:
        পক্ষ N_SOL:
            গচ্ছ abs_pc;
        পক্ষ N_FUN:
            যদি (sym->n_strx == 0) /* end of function */
                গচ্ছ rel_pc;
        abs_pc:
#যদি PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            গচ্ছ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            যদি (pc >= wanted_pc && wanted_pc >= last_pc)
                গচ্ছ found;
            ভঙ্গ;
        }

        ৱিকল্প(sym->n_type) {
            /* function start or end */
        পক্ষ N_FUN:
            যদি (sym->n_strx == 0)
                গচ্ছ reset_func;
            p = strchr(str, ':');
            যদি (0 == p || (len = p - str + 1, len > পরিমাণ func_name))
                len = পরিমাণ func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ভঙ্গ;
            /* line number info */
        পক্ষ N_SLINE:
            last_pc = pc;
            last_সাৰি_অঙ্ক = sym->n_desc;
            last_incl_index = incl_index;
            ভঙ্গ;
            /* include files */
        পক্ষ N_BINCL:
            যদি (incl_index < INCLUDE_স্তূপ_SIZE)
                incl_files[incl_index++] = str;
            ভঙ্গ;
        পক্ষ N_EINCL:
            যদি (incl_index > 1)
                incl_index--;
            ভঙ্গ;
            /* start/end of translation unit */
        পক্ষ N_SO:
            incl_index = 0;
            যদি (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                যদি (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            ভঙ্গ;
            /* alternative file name (from #line or #include directives) */
        পক্ষ N_SOL:
            যদি (incl_index)
                incl_files[incl_index-1] = str;
            ভঙ্গ;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    যদি (i > 0) {
        pstrcpy(bi->file, পরিমাণ bi->file, incl_files[--i]);
        bi->সাৰি = last_সাৰি_অঙ্ক;
    }
    pstrcpy(bi->func, পরিমাণ bi->func, func_name);
    bi->func_pc = func_addr;
    ঘূৰাই func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	ৱিকল্প (entry_format[j].form) { \
	পক্ষ DW_FORM_data1: (ln) += 1; ভঙ্গ; \
	পক্ষ DW_FORM_data2: (ln) += 2; ভঙ্গ; \
	পক্ষ DW_FORM_data4: (ln) += 3; ভঙ্গ; \
	পক্ষ DW_FORM_data8: (ln) += 8; ভঙ্গ; \
	পক্ষ DW_FORM_data16: (ln) += 16; ভঙ্গ; \
	পক্ষ DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); ভঙ্গ; \
	স্ৱভাৱ: গচ্ছ next_সাৰি; \
	}

স্থির addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned ৱর্ণ *ln;
    unsigned ৱর্ণ *cp;
    unsigned ৱর্ণ *end;
    unsigned ৱর্ণ *opcode_length;
    unsigned long long size;
    unsigned পূর্ণাঙ্ক length;
    unsigned ৱর্ণ version;
    unsigned পূর্ণাঙ্ক min_insn_length;
    unsigned পূর্ণাঙ্ক max_ops_per_insn;
    পূর্ণাঙ্ক সাৰি_base;
    unsigned পূর্ণাঙ্ক সাৰি_range;
    unsigned পূর্ণাঙ্ক opcode_base;
    unsigned পূর্ণাঙ্ক opindex;
    unsigned পূর্ণাঙ্ক col;
    unsigned পূর্ণাঙ্ক i;
    unsigned পূর্ণাঙ্ক j;
    unsigned পূর্ণাঙ্ক len;
    unsigned long long মান;
    সংরচনা {
	unsigned পূর্ণাঙ্ক type;
	unsigned পূর্ণাঙ্ক form;
    } entry_format[256];
    unsigned পূর্ণাঙ্ক dir_size;
#যদি 0
    ৱর্ণ *dirs[DIR_TABLE_SIZE];
#endif
    unsigned পূর্ণাঙ্ক filename_size;
    সংরচনা /*dwarf_filename_struct*/ {
        unsigned পূর্ণাঙ্ক dir_entry;
        ৱর্ণ *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    পূর্ণাঙ্ক সাৰি;
    ৱর্ণ *filename;
    ৱর্ণ *function;

    filename = রিক্ত;
    function = রিক্ত;
    func_addr = 0;
    সাৰি = 0;

    ln = rc->dwarf_সাৰি;
    যেতিয়ালৈ (ln < rc->dwarf_সাৰি_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        সাৰি = 1;
        filename = রিক্ত;
        function = রিক্ত;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_সাৰি_end);
	যদি (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_সাৰি_end);
	end = ln + size;
	যদি (end < ln || end > rc->dwarf_সাৰি_end)
	    ভঙ্গ;
	version = dwarf_read_2(ln, end);
	যদি (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	অন্যথা
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	যদি (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	অন্যথা
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	সাৰি_base = dwarf_read_1(ln, end);
	সাৰি_base |= সাৰি_base >= 0x80 ? ~0xff : 0;
	সাৰি_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	যদি (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    বাবে (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    বাবে (i = 0; i < dir_size; i++) {
		বাবে (j = 0; j < col; j++) {
		    যদি (entry_format[j].type == DW_LNCT_path) {
		        যদি (entry_format[j].form != DW_FORM_সাৰি_strp)
			    গচ্ছ next_সাৰি;
#যদি 0
		        মান = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        যদি (i < DIR_TABLE_SIZE)
		            dirs[i] = (ৱর্ণ *)rc->dwarf_সাৰি_str + মান;
#অন্যথা
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    অন্যথা 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    বাবে (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    বাবে (i = 0; i < filename_size; i++)
		বাবে (j = 0; j < col; j++) {
		    যদি (entry_format[j].type == DW_LNCT_path) {
			যদি (entry_format[j].form != DW_FORM_সাৰি_strp)
			    গচ্ছ next_সাৰি;
			মান = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        যদি (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(ৱর্ণ *)rc->dwarf_সাৰি_str + মান;
	            }
		    অন্যথা যদি (entry_format[j].type == DW_LNCT_directory_index) {
			ৱিকল্প (entry_format[j].form) {
			পক্ষ DW_FORM_data1: মান = dwarf_read_1(ln, end); ভঙ্গ;
			পক্ষ DW_FORM_data2: মান = dwarf_read_2(ln, end); ভঙ্গ;
			পক্ষ DW_FORM_data4: মান = dwarf_read_4(ln, end); ভঙ্গ;
			পক্ষ DW_FORM_udata: মান = dwarf_read_uleb128(&ln, end); ভঙ্গ;
			স্ৱভাৱ: গচ্ছ next_সাৰি;
			}
		        যদি (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = মান;
		    }
		    অন্যথা 
			dwarf_ignore_type(ln, end);
	    }
	}
	অন্যথা {
	    যেতিয়ালৈ ((dwarf_read_1(ln, end))) {
#যদি 0
		যদি (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (ৱর্ণ *)ln - 1;
#endif
		যেতিয়ালৈ (dwarf_read_1(ln, end)) {}
	    }
	    যেতিয়ালৈ ((dwarf_read_1(ln, end))) {
		যদি (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (ৱর্ণ *)ln - 1;
		    যেতিয়ালৈ (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		অন্যথা {
		    যেতিয়ালৈ (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	যদি (filename_size >= 1)
	    filename = filename_table[0].name;
	যেতিয়ালৈ (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    যদি (i >= opcode_base) {
	        যদি (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / সাৰি_range) * min_insn_length;
		অন্যথা {
		    pc += (opindex + (i - opcode_base) / সাৰি_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / সাৰি_range) %
			       max_ops_per_insn;
		}
		i = (পূর্ণাঙ্ক)((i - opcode_base) % সাৰি_range) + সাৰি_base;
check_pc:
		যদি (pc >= wanted_pc && wanted_pc >= last_pc)
		    গচ্ছ found;
		সাৰি += i;
	    }
	    অন্যথা {
	        ৱিকল্প (i) {
	        পক্ষ 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    যদি (len == 0)
		        গচ্ছ next_সাৰি;
		    ৱিকল্প (dwarf_read_1(cp, end)) {
		    পক্ষ DW_LNE_end_sequence:
		        ভঙ্গ;
		    পক্ষ DW_LNE_set_address:
#যদি PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#অন্যথা
		        pc = dwarf_read_8(cp, end);
#endif
#যদি defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        ভঙ্গ;
		    পক্ষ DW_LNE_define_file: /* deprecated */
		        যদি (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (ৱর্ণ *)ln - 1;
		            যেতিয়ালৈ (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        অন্যথা {
		            যেতিয়ালৈ (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        ভঙ্গ;
		    পক্ষ DW_LNE_hi_user - 1:
		        function = (ৱর্ণ *)cp;
		        func_addr = pc;
		        ভঙ্গ;
		    স্ৱভাৱ:
		        ভঙ্গ;
		    }
		    ভঙ্গ;
	        পক্ষ DW_LNS_advance_pc:
		    যদি (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    অন্যথা {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    গচ্ছ check_pc;
	        পক্ষ DW_LNS_advance_সাৰি:
		    সাৰি += dwarf_read_sleb128(&ln, end);
		    ভঙ্গ;
	        পক্ষ DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    যদি (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    ভঙ্গ;
	        পক্ষ DW_LNS_const_add_pc:
		    যদি (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / সাৰি_range) * min_insn_length;
		    অন্যথা {
		        unsigned পূর্ণাঙ্ক off = (255 - opcode_base) / সাৰি_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    গচ্ছ check_pc;
	        পক্ষ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    গচ্ছ check_pc;
	        স্ৱভাৱ:
		    বাবে (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    ভঙ্গ;
		}
	    }
	}
next_সাৰি:
	ln = end;
    }
    filename = function = রিক্ত, func_addr = 0;
found:
    যদি (filename)
        pstrcpy(bi->file, পরিমাণ bi->file, filename), bi->সাৰি = সাৰি;
    যদি (function)
        pstrcpy(bi->func, পরিমাণ bi->func, function);
    bi->func_pc = func_addr;
    ঘূৰাই (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
স্থির
#endif
পূর্ণাঙ্ক _tcc_backtrace(rt_frame *f, ধ্রুৱ ৱর্ণ *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    ৱর্ণ skip[40], বাৰ্তা[200];
    পূর্ণাঙ্ক i, level, ret, n, one;
    ধ্রুৱ ৱর্ণ *a, *b;
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
    vsnprintf(বাৰ্তা, পরিমাণ বাৰ্তা, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    যদি (rc) {
        যদি (rc->dwarf)
            getinfo = rt_printline_dwarf;
        যদি (rc->অঙ্ক_callers)
            n = rc->অঙ্ক_callers;
    }

    বাবে (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        যদি (ret == -1)
            ভঙ্গ;
        memset(&bi, 0, পরিমাণ bi);
        বাবে (rc2 = rc; rc2; rc2 = rc2->next) {
            যদি (getinfo(rc2, pc, &bi))
                ভঙ্গ;
            /* we try symtab symbols (no line number info) */
            যদি (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, পরিমাণ bi.func, a);
                ভঙ্গ;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        যদি (skip[0] && strstr(bi.file, skip))
            অনুৱর্ত;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            যদি (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (শূন্য*)pc,
                    bi.file[0] ? bi.file : রিক্ত,
                    bi.সাৰি,
                    bi.func[0] ? bi.func : রিক্ত,
                    level == 0 ? বাৰ্তা : রিক্ত
                    );
                যদি (ret == 0)
                    ভঙ্গ;
                গচ্ছ check_break;
            }
        }
#endif
        যদি (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.সাৰি);
        } অন্যথা {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        যদি (level == 0) {
            rt_printf(": %s", বাৰ্তা);
            যদি (one)
                ভঙ্গ;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        যদি (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->শীৰ্ষ_func)
            ভঙ্গ;
        ++level;
    }
    rt_post_sem();
    ঘূৰাই 0;
}

/* emit a run time error at position 'pc' */
স্থির পূর্ণাঙ্ক rt_error(rt_frame *f, ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list ap; ৱর্ণ বাৰ্তা[200]; পূর্ণাঙ্ক ret;
    va_start(ap, fmt);
    snprintf(বাৰ্তা, পরিমাণ বাৰ্তা, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, বাৰ্তা, ap);
    va_end(ap);
    ঘূৰাই ret;
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
#নোচেদ্যদি defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#নোচেদ্যদি defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#নোচেদ্যদি defined __i386__
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
#নোচেদ্যদি defined(__x86_64__)
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
#নোচেদ্যদি defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নোচেদ্যদি defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#নোচেদ্যদি defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নোচেদ্যদি defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#নোচেদ্যদি defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#নোচেদ্যদি defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#নোচেদ্যদি defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#নোচেদ্যদি defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#নোচেদ্যদি defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#নোচেদ্যদি defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#নোচেদ্যদি defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
স্থির শূন্য sig_error(পূর্ণাঙ্ক signum, siginfo_t *siginf, শূন্য *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    ৱিকল্প(signum) {
    পক্ষ SIGFPE:
        ৱিকল্প(siginf->si_code) {
        পক্ষ FPE_INTDIV:
        পক্ষ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ভঙ্গ;
        স্ৱভাৱ:
            rt_error(&f, "floating point exception");
            ভঙ্গ;
        }
        ভঙ্গ;
    পক্ষ SIGBUS:
    পক্ষ SIGSEGV:
        rt_error(&f, "invalid memory access");
        ভঙ্গ;
    পক্ষ SIGILL:
        rt_error(&f, "illegal instruction");
        ভঙ্গ;
    পক্ষ SIGABRT:
        rt_error(&f, "abort() called");
        ভঙ্গ;
    স্ৱভাৱ:
        rt_error(&f, "caught signal %d", signum);
        ভঙ্গ;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, রিক্ত);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
স্থির শূন্য set_exception_handler(শূন্য)
{
    সংরচনা sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#যদি 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, রিক্ত);
    sigaction(SIGILL, &sigact, রিক্ত);
    sigaction(SIGSEGV, &sigact, রিক্ত);
    sigaction(SIGBUS, &sigact, রিক্ত);
    sigaction(SIGABRT, &sigact, রিক্ত);
#যদি 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        স্থির unsigned ৱর্ণ স্তূপ[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = স্তূপ;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, রিক্ত);
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

    ৱিকল্প (code = ex_info->ExceptionRecord->ExceptionCode) {
    পক্ষ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ভঙ্গ;
    পক্ষ EXCEPTION_স্তূপ_OVERFLOW:
        rt_error(&f, "stack overflow");
        ভঙ্গ;
    পক্ষ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ভঙ্গ;
    পক্ষ EXCEPTION_BREAKPOINT:
    পক্ষ EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ঘূৰাই EXCEPTION_CONTINUE_অনুসন্ধান;
    স্ৱভাৱ:
        rt_error(&f, "caught exception %08x", code);
        ভঙ্গ;
    }
    rt_exit(&f, 255);
    ঘূৰাই EXCEPTION_EXECUTE_HANDLER;
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
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণাঙ্ক level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যেতিয়ালৈ (1) {
            যদি (fp < 0x1000)
                ঘূৰাই -1;
            যদি (0 == --level)
                ভঙ্গ;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ঘূৰাই 0;
}

/* XXX: only supports linux/bsd */
#নোচেদ্যদি defined(__arm__) && !defined(_WIN32)
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণাঙ্ক level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যেতিয়ালৈ (1) {
            যদি (fp < 0x1000)
                ঘূৰাই -1;
            যদি (0 == --level)
                ভঙ্গ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ঘূৰাই 0;
}

#নোচেদ্যদি defined(__aarch64__)
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণাঙ্ক level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যেতিয়ালৈ (1) {
            যদি (fp < 0x1000)
                ঘূৰাই -1;
            যদি (0 == --level)
                ভঙ্গ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ঘূৰাই 0;
}

#নোচেদ্যদি defined(__riscv)
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণাঙ্ক level)
{
    যদি (level == 0) {
        *paddr = rc->ip;
    } অন্যথা {
        addr_t fp = rc->fp;
        যেতিয়ালৈ (1) {
            যদি (fp < 0x1000)
                ঘূৰাই -1;
            যদি (0 == --level)
                ভঙ্গ;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ঘূৰাই 0;
}

#অন্যথা
#warning add arch specific rt_get_caller_pc()
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *rc, পূর্ণাঙ্ক level)
{
    ঘূৰাই -1;
}

#endif
#অন্যথা // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
স্থির পূর্ণাঙ্ক rt_get_caller_pc(addr_t *paddr, rt_frame *f, পূর্ণাঙ্ক level)
{
    যদি (level)
        ঘূৰাই -1;
    *paddr = f->ip;
    ঘূৰাই 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC শূন্য *dlopen(ধ্রুৱ ৱর্ণ *filename, পূর্ণাঙ্ক flag)
{
    ঘূৰাই রিক্ত;
}

ST_FUNC শূন্য dlclose(শূন্য *p)
{
}

ST_FUNC ধ্রুৱ ৱর্ণ *dlerror(শূন্য)
{
    ঘূৰাই "error";
}

প্রকারনির্দেশ সংরচনা TCCSyms {
    ৱর্ণ *str;
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
    { রিক্ত, রিক্ত },
};

ST_FUNC শূন্য *dlsym(শূন্য *handle, ধ্রুৱ ৱর্ণ *প্ৰতীক)
{
    TCCSyms *p;
    p = tcc_syms;
    যেতিয়ালৈ (p->str != রিক্ত) {
        যদি (!strcmp(p->str, প্ৰতীক))
            ঘূৰাই p->ptr;
        p++;
    }
    ঘূৰাই রিক্ত;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
