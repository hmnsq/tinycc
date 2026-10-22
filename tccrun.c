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
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
تعريفنوع بنية rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اتحاد {
	بنية {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    حرف *stab_str;
	};
	بنية {
	    unsigned حرف *dwarf_line;
	    unsigned حرف *dwarf_line_end;
	    unsigned حرف *dwarf_line_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    حرف *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    فراغ *bounds_start;
    فراغ *top_func;
    بنية rt_context *next;
    // 10 * PTR_SIZE
    صحيح num_callers;
    صحيح dwarf;
} rt_context;

/* linked list of rt_contexts */
ساكن rt_context *g_rc;
ساكن صحيح signal_set;
ساكن فراغ set_exception_handler(فراغ);
#endif /* def CONFIG_TCC_BACKTRACE */

تعريفنوع بنية rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

ساكن TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ساكن rt_sem);
ساكن فراغ rt_wait_sem(فراغ) { WAIT_SEM(&rt_sem); }
ساكن فراغ rt_post_sem(فراغ) { POST_SEM(&rt_sem); }
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *f, صحيح level);
ساكن فراغ rt_exit(rt_frame *f, صحيح code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

ساكن صحيح protect_pages(فراغ *ptr, unsigned long length, صحيح mode);
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, unsigned ptr_diff);
ساكن فراغ st_link(TCCState *s1);
ساكن فراغ st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
ساكن صحيح _tcc_backtrace(rt_frame *f, ثابت حرف *fmt, va_list ap);
#endif
#ifdef _WIN64
ساكن فراغ *win64_add_function_table(TCCState *s1);
ساكن فراغ win64_del_function_table(فراغ *);
#endif

#ܐܢ !defined PAGESIZE
# ܐܢ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ܐܚܪܢܐ
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ܐܢ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#ܐܢ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

ساكن صحيح rt_mem(TCCState *s1, صحيح size)
{
    فراغ *ptr;
    صحيح ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    فراغ *prw;
    حرف tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحيح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(عدم, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((حرف*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ܐܢ (ptr == MAP_FAILED || prw == MAP_FAILED)
	ܦܢܐ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (حرف*)prw - (حرف*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(عدم, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    ܐܢ (!ptr)
        ܦܢܐ tcc_error_noabort("tccrun: could not allocate memory");
#ܐܚܪܢܐ
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    ܦܢܐ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحيح tcc_relocate(TCCState *s1)
{
    صحيح size, ret, ptr_diff;

    ܐܢ (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    ܐܢ (s1->do_backtrace)
        tcc_add_symbol(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, عدم, 0);
    ܐܢ (size < 0)
        ܦܢܐ -1;
    ptr_diff = rt_mem(s1, size);
    ܐܢ (ptr_diff < 0)
        ܦܢܐ -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    ܐܢ (ret == 0)
        st_link(s1);
    ܦܢܐ ret;
}

ST_FUNC فراغ tcc_run_free(TCCState *s1)
{
    unsigned size;
    فراغ *ptr;
    صحيح i;

    /* free any loaded DLLs */
    لكل ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ܐܢ ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ܐܚܪܢܐ
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    ܐܢ (عدم == ptr)
        ܦܢܐ;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#وإلاإذا CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#ܐܚܪܢܐ
    /* unprotect memory to make it usable for malloc again */
    protect_pages((فراغ*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحيح tcc_run(TCCState *s1, صحيح argc, حرف **argv)
{
    صحيح (*prog_main)(صحيح, حرف **, حرف **), ret;
    ثابت حرف *top_sym;
    jmp_buf main_jb;

#ܐܢ defined(__APPLE__)
    خارجي حرف ***_NSGetEnviron(فراغ);
    حرف **envp = *_NSGetEnviron();
#وإلاإذا defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    خارجي حرف **environ;
    حرف **envp = environ;
#ܐܚܪܢܐ
    حرف **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    ܐܢ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ܦܢܐ 0;

    tcc_add_symbol(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", top_sym = "main";
    ܐܢ (s1->elf_entryname)
        s1->run_main = top_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    ܐܢ (tcc_relocate(s1) < 0)
        ܦܢܐ -1;

    prog_main = (فراغ*)get_sym_addr(s1, s1->run_main, 1, 1);
    ܐܢ ((addr_t)-1 == (addr_t)prog_main)
        ܦܢܐ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ܐܢ (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ܦܢܐ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_symbol(s1, top_sym));
    ܐܢ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ܐܚܪܢܐ ܐܢ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ܐܢ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ܦܢܐ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ساكن فراغ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    صحيح sym_index, end_sym = s->data_offset / حجم (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    لكل (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ثابت حرف *name = (حرف *)s->link->data + sym->st_name;
        ܐܢ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            استمر;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_value, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ساكن فراغ cleanup_sections(TCCState *s1)
{
    بنية { Section **secs; صحيح nb_secs; } *p = (فراغ*)&s1->sections;
    صحيح i, f = 2;
    ܥܒܕ {
        لكل (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ܐܢ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } ܐܚܪܢܐ {
                free_section(s), tcc_free(s), p->secs[i] = عدم;
            }
        }
    } ܟܡܐ (++p, f);
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
# ܐܚܪܢܐ
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ساكن صحيح tcc_relocate_ex(TCCState *s1, فراغ *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    ܐܢ (عدم == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, عدم);
#ܐܚܪܢܐ
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    ܐܢ (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    ܐܢ (s1->nb_errors)
        ܦܢܐ -1;
    ܐܢ (copy == 3)
        ܦܢܐ 0;

    لكل (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        لكل(i = 1; i < s1->nb_sections; i++) {
            ساكن ثابت حرف shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ܐܢ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                استمر;
            length = s->data_offset;
            ܐܢ (copy == 2) {
                ܐܢ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                استمر;
            }
            ܐܢ (copy) { /* final step: copy section data to memory */
                ܐܢ (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (فراغ*)s->sh_addr, length, s->sh_addralign);
                ptr = (فراغ*)s->sh_addr;
                ܐܢ (k == 0)
                    ptr = (فراغ*)(s->sh_addr + ptr_diff);
                ܐܢ (عدم == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                ܐܚܪܢܐ
                    memcpy(ptr, s->data, length);
                استمر;
            }

            ܐܢ ((s->sh_flags & SHF_TLS) && length)
                ܦܢܐ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ܐܢ (++n == 1) {
#ܐܢ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ܐܢ (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                ܐܢ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        ܐܢ (copy == 2) { /* set permissions */
            ܐܢ (n == 0) /* no data  */
                استمر;
#ifdef CONFIG_SELINUX
            ܐܢ (k == 0) /* SHF_EXECINSTR has its own mapping */
                استمر;
#endif
            f = k;
            ܐܢ (f >= CONFIG_RUNMEM_RO) {
                ܐܢ (f != 0)
                    استمر;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ܐܢ (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (فراغ*)addr, (unsigned)n);
            }
            ܐܢ (protect_pages((فراغ*)addr, n, f) < 0)
                ܦܢܐ tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#ܐܚܪܢܐ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    ܐܢ (0 == mem)
        ܦܢܐ PAGEALIGN(offset);

    ܐܢ (++copy == 2) {
        اذهب redo;
    }
    ܐܢ (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        اذهب redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ܐܢ (s1->nb_errors)
        اذهب redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#ܐܚܪܢܐ
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    اذهب redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ساكن صحيح protect_pages(فراغ *ptr, unsigned long length, صحيح mode)
{
#ifdef _WIN32
    ساكن ثابت unsigned حرف protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    ܐܢ (!VirtualProtect(ptr, length, protect[mode], &old))
        ܦܢܐ -1;
#ܐܚܪܢܐ
    ساكن ثابت unsigned حرف protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ܐܢ (mprotect(ptr, length, protect[mode]))
        ܦܢܐ -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#ܐܢ (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ܐܢ (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#ܐܚܪܢܐ
        فراغ __clear_cache(فراغ *beginning, فراغ *end);
        __clear_cache(ptr, (حرف *)ptr + length);
#endif
    }
#endif
    ܦܢܐ 0;
}

#ifdef _WIN64
ساكن فراغ *win64_add_function_table(TCCState *s1)
{
    فراغ *p = عدم;
    ܐܢ (s1->uw_pdata) {
        p = (فراغ*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / حجم (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = عدم;
    }
    ܦܢܐ p;
}

ساكن فراغ win64_del_function_table(فراغ *p)
{
    ܐܢ (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

ساكن فراغ bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ܐܢ (!s1->do_backtrace)
        ܦܢܐ;
    rc = tcc_get_symbol(s1, "__rt_info");
    ܐܢ (!rc)
        ܦܢܐ;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (حرف *)symtab_section->link->data;
    ܐܢ (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    ܐܢ (s1->do_bounds_check) {
        فراغ *p;
        ܐܢ ((p = tcc_get_symbol(s1, "__bound_init")))
            ((فراغ(*)(فراغ*,صحيح))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    ܐܢ (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

ساكن فراغ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ساكن فراغ ptr_unlink(فراغ *list, فراغ *e, unsigned next)
{
    فراغ **pp, **nn, *p;
    لكل (pp = list; !!(p = *pp); pp = nn) {
        nn = (فراغ*)((حرف*)p + next); /* nn = &p->next; */
        ܐܢ (p == e) {
            *pp = *nn;
            اكسر;
        }
    }
}

ساكن فراغ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *p_jmp_buf, فراغ *func, فراغ *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    ܐܢ (s1->rc)
        s1->rc->top_func = func;
#endif
    ܦܢܐ p_jmp_buf;
}

LIBTCCAPI فراغ tcc_set_backtrace_func(TCCState *s1, فراغ *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

ساكن TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    صحيح level;
    addr_t pc;

    s = g_s1;
    ܐܢ (عدم == s || عدم == s->next) {
        /* play it safe in the simple case when there is only one state */
        ܦܢܐ s;
    }
    لكل (level = 0; level < 8; ++level) {
        ܐܢ (rt_get_caller_pc(&pc, f, level) < 0)
            اكسر;
        لكل (s = g_s1; s; s = s->next) {
            ܐܢ (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                ܦܢܐ s;
        }
    }
    ܦܢܐ عدم;
}

ساكن فراغ rt_exit(rt_frame *f, صحيح code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    ܐܢ (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        ܐܢ (f->fp) { /* called from signal */
            فراغ *p = tcc_get_symbol(s, "__bound_exit");
            ܐܢ (p)
                ((فراغ (*)(فراغ))p)();
        }
#endif
        ܐܢ (code == 0)
            code = RT_EXIT_ZERO;
        ((فراغ(*)(فراغ*,صحيح))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#ܐܚܪܢܐ // if defined CONFIG_TCC_BACKTRACE_ONLY
ساكن فراغ rt_exit(rt_frame *f, صحيح code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

ساكن صحيح rt_vprintf(ثابت حرف *fmt, va_list ap)
{
    صحيح ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ܦܢܐ ret;
}

ساكن صحيح rt_printf(ثابت حرف *fmt, ...)
{
    va_list ap;
    صحيح r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ܦܢܐ r;
}

ساكن حرف *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    لكل (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        صحيح type = ELFW(ST_TYPE)(esym->st_info);
        ܐܢ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_value
            && wanted_pc < esym->st_value + esym->st_size) {
            *func_addr = esym->st_value;
            ܦܢܐ rc->elf_str + esym->st_name;
        }
    }
    ܦܢܐ عدم;
}

تعريفنوع بنية bt_info
{
    حرف file[100];
    صحيح line;
    حرف func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ساكن addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    حرف func_name[128];
    addr_t func_addr, last_pc, pc;
    ثابت حرف *incl_files[INCLUDE_STACK_SIZE];
    صحيح incl_index, last_incl_index, len, last_line_num, i;
    ثابت حرف *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_line_num = 1;
    last_incl_index = 0;

    لكل (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_value;

        بدل(sym->n_type) {
        حالة N_SLINE:
            ܐܢ (func_addr)
                اذهب rel_pc;
        حالة N_SO:
        حالة N_SOL:
            اذهب abs_pc;
        حالة N_FUN:
            ܐܢ (sym->n_strx == 0) /* end of function */
                اذهب rel_pc;
        abs_pc:
#ܐܢ PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            اذهب check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ܐܢ (pc >= wanted_pc && wanted_pc >= last_pc)
                اذهب found;
            اكسر;
        }

        بدل(sym->n_type) {
            /* function start or end */
        حالة N_FUN:
            ܐܢ (sym->n_strx == 0)
                اذهب reset_func;
            p = strchr(str, ':');
            ܐܢ (0 == p || (len = p - str + 1, len > حجم func_name))
                len = حجم func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            اكسر;
            /* line number info */
        حالة N_SLINE:
            last_pc = pc;
            last_line_num = sym->n_desc;
            last_incl_index = incl_index;
            اكسر;
            /* include files */
        حالة N_BINCL:
            ܐܢ (incl_index < INCLUDE_STACK_SIZE)
                incl_files[incl_index++] = str;
            اكسر;
        حالة N_EINCL:
            ܐܢ (incl_index > 1)
                incl_index--;
            اكسر;
            /* start/end of translation unit */
        حالة N_SO:
            incl_index = 0;
            ܐܢ (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                ܐܢ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            اكسر;
            /* alternative file name (from #line or #include directives) */
        حالة N_SOL:
            ܐܢ (incl_index)
                incl_files[incl_index-1] = str;
            اكسر;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    ܐܢ (i > 0) {
        pstrcpy(bi->file, حجم bi->file, incl_files[--i]);
        bi->line = last_line_num;
    }
    pstrcpy(bi->func, حجم bi->func, func_name);
    bi->func_pc = func_addr;
    ܦܢܐ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	بدل (entry_format[j].form) { \
	حالة DW_FORM_data1: (ln) += 1; اكسر; \
	حالة DW_FORM_data2: (ln) += 2; اكسر; \
	حالة DW_FORM_data4: (ln) += 3; اكسر; \
	حالة DW_FORM_data8: (ln) += 8; اكسر; \
	حالة DW_FORM_data16: (ln) += 16; اكسر; \
	حالة DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); اكسر; \
	افتراضي: اذهب next_line; \
	}

ساكن addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned حرف *ln;
    unsigned حرف *cp;
    unsigned حرف *end;
    unsigned حرف *opcode_length;
    unsigned long long size;
    unsigned صحيح length;
    unsigned حرف version;
    unsigned صحيح min_insn_length;
    unsigned صحيح max_ops_per_insn;
    صحيح line_base;
    unsigned صحيح line_range;
    unsigned صحيح opcode_base;
    unsigned صحيح opindex;
    unsigned صحيح col;
    unsigned صحيح i;
    unsigned صحيح j;
    unsigned صحيح len;
    unsigned long long value;
    بنية {
	unsigned صحيح type;
	unsigned صحيح form;
    } entry_format[256];
    unsigned صحيح dir_size;
#ܐܢ 0
    حرف *dirs[DIR_TABLE_SIZE];
#endif
    unsigned صحيح filename_size;
    بنية /*dwarf_filename_struct*/ {
        unsigned صحيح dir_entry;
        حرف *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    صحيح line;
    حرف *filename;
    حرف *function;

    filename = عدم;
    function = عدم;
    func_addr = 0;
    line = 0;

    ln = rc->dwarf_line;
    ܟܡܐ (ln < rc->dwarf_line_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        line = 1;
        filename = عدم;
        function = عدم;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_line_end);
	ܐܢ (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_line_end);
	end = ln + size;
	ܐܢ (end < ln || end > rc->dwarf_line_end)
	    اكسر;
	version = dwarf_read_2(ln, end);
	ܐܢ (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	ܐܚܪܢܐ
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	ܐܢ (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	ܐܚܪܢܐ
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	line_base = dwarf_read_1(ln, end);
	line_base |= line_base >= 0x80 ? ~0xff : 0;
	line_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	ܐܢ (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    لكل (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    لكل (i = 0; i < dir_size; i++) {
		لكل (j = 0; j < col; j++) {
		    ܐܢ (entry_format[j].type == DW_LNCT_path) {
		        ܐܢ (entry_format[j].form != DW_FORM_line_strp)
			    اذهب next_line;
#ܐܢ 0
		        value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ܐܢ (i < DIR_TABLE_SIZE)
		            dirs[i] = (حرف *)rc->dwarf_line_str + value;
#ܐܚܪܢܐ
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    ܐܚܪܢܐ 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    لكل (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    لكل (i = 0; i < filename_size; i++)
		لكل (j = 0; j < col; j++) {
		    ܐܢ (entry_format[j].type == DW_LNCT_path) {
			ܐܢ (entry_format[j].form != DW_FORM_line_strp)
			    اذهب next_line;
			value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ܐܢ (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(حرف *)rc->dwarf_line_str + value;
	            }
		    ܐܚܪܢܐ ܐܢ (entry_format[j].type == DW_LNCT_directory_index) {
			بدل (entry_format[j].form) {
			حالة DW_FORM_data1: value = dwarf_read_1(ln, end); اكسر;
			حالة DW_FORM_data2: value = dwarf_read_2(ln, end); اكسر;
			حالة DW_FORM_data4: value = dwarf_read_4(ln, end); اكسر;
			حالة DW_FORM_udata: value = dwarf_read_uleb128(&ln, end); اكسر;
			افتراضي: اذهب next_line;
			}
		        ܐܢ (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = value;
		    }
		    ܐܚܪܢܐ 
			dwarf_ignore_type(ln, end);
	    }
	}
	ܐܚܪܢܐ {
	    ܟܡܐ ((dwarf_read_1(ln, end))) {
#ܐܢ 0
		ܐܢ (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (حرف *)ln - 1;
#endif
		ܟܡܐ (dwarf_read_1(ln, end)) {}
	    }
	    ܟܡܐ ((dwarf_read_1(ln, end))) {
		ܐܢ (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (حرف *)ln - 1;
		    ܟܡܐ (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		ܐܚܪܢܐ {
		    ܟܡܐ (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	ܐܢ (filename_size >= 1)
	    filename = filename_table[0].name;
	ܟܡܐ (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    ܐܢ (i >= opcode_base) {
	        ܐܢ (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / line_range) * min_insn_length;
		ܐܚܪܢܐ {
		    pc += (opindex + (i - opcode_base) / line_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / line_range) %
			       max_ops_per_insn;
		}
		i = (صحيح)((i - opcode_base) % line_range) + line_base;
check_pc:
		ܐܢ (pc >= wanted_pc && wanted_pc >= last_pc)
		    اذهب found;
		line += i;
	    }
	    ܐܚܪܢܐ {
	        بدل (i) {
	        حالة 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    ܐܢ (len == 0)
		        اذهب next_line;
		    بدل (dwarf_read_1(cp, end)) {
		    حالة DW_LNE_end_sequence:
		        اكسر;
		    حالة DW_LNE_set_address:
#ܐܢ PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#ܐܚܪܢܐ
		        pc = dwarf_read_8(cp, end);
#endif
#ܐܢ defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        اكسر;
		    حالة DW_LNE_define_file: /* deprecated */
		        ܐܢ (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (حرف *)ln - 1;
		            ܟܡܐ (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        ܐܚܪܢܐ {
		            ܟܡܐ (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
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
		    ܐܢ (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    ܐܚܪܢܐ {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_advance_line:
		    line += dwarf_read_sleb128(&ln, end);
		    اكسر;
	        حالة DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    ܐܢ (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    اكسر;
	        حالة DW_LNS_const_add_pc:
		    ܐܢ (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / line_range) * min_insn_length;
		    ܐܚܪܢܐ {
		        unsigned صحيح off = (255 - opcode_base) / line_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    اذهب check_pc;
	        حالة DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    اذهب check_pc;
	        افتراضي:
		    لكل (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    اكسر;
		}
	    }
	}
next_line:
	ln = end;
    }
    filename = function = عدم, func_addr = 0;
found:
    ܐܢ (filename)
        pstrcpy(bi->file, حجم bi->file, filename), bi->line = line;
    ܐܢ (function)
        pstrcpy(bi->func, حجم bi->func, function);
    bi->func_pc = func_addr;
    ܦܢܐ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
ساكن
#endif
صحيح _tcc_backtrace(rt_frame *f, ثابت حرف *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    حرف skip[40], msg[200];
    صحيح i, level, ret, n, one;
    ثابت حرف *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ܐܢ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ܐܢ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(msg, حجم msg, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ܐܢ (rc) {
        ܐܢ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ܐܢ (rc->num_callers)
            n = rc->num_callers;
    }

    لكل (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ܐܢ (ret == -1)
            اكسر;
        memset(&bi, 0, حجم bi);
        لكل (rc2 = rc; rc2; rc2 = rc2->next) {
            ܐܢ (getinfo(rc2, pc, &bi))
                اكسر;
            /* we try symtab symbols (no line number info) */
            ܐܢ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, حجم bi.func, a);
                اكسر;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ܐܢ (skip[0] && strstr(bi.file, skip))
            استمر;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            ܐܢ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (فراغ*)pc,
                    bi.file[0] ? bi.file : عدم,
                    bi.line,
                    bi.func[0] ? bi.func : عدم,
                    level == 0 ? msg : عدم
                    );
                ܐܢ (ret == 0)
                    اكسر;
                اذهب check_break;
            }
        }
#endif
        ܐܢ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.line);
        } ܐܚܪܢܐ {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ܐܢ (level == 0) {
            rt_printf(": %s", msg);
            ܐܢ (one)
                اكسر;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        ܐܢ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->top_func)
            اكسر;
        ++level;
    }
    rt_post_sem();
    ܦܢܐ 0;
}

/* emit a run time error at position 'pc' */
ساكن صحيح rt_error(rt_frame *f, ثابت حرف *fmt, ...)
{
    va_list ap; حرف msg[200]; صحيح ret;
    va_start(ap, fmt);
    snprintf(msg, حجم msg, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, msg, ap);
    va_end(ap);
    ܦܢܐ ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ܐܚܪܢܐ
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
ساكن فراغ rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#ܐܢ defined _WIN64 && defined __aarch64__
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
# ܐܢ defined(__APPLE__)
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
# ܐܚܪܢܐ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#وإلاإذا defined(__x86_64__)
# ܐܢ defined(__APPLE__)
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
# ܐܚܪܢܐ
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
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
ساكن فراغ sig_error(صحيح signum, siginfo_t *siginf, فراغ *puc)
{
    rt_frame f;
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

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ set_exception_handler(فراغ)
{
    بنية sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ܐܢ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, عدم);
    sigaction(SIGILL, &sigact, عدم);
    sigaction(SIGSEGV, &sigact, عدم);
    sigaction(SIGBUS, &sigact, عدم);
    sigaction(SIGABRT, &sigact, عدم);
#ܐܢ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ساكن unsigned حرف stack[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = stack;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, عدم);
    }
#endif
}

#ܐܚܪܢܐ /* WIN32 */

/* signal handler for fatal errors */
ساكن long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    بدل (code = ex_info->ExceptionRecord->ExceptionCode) {
    حالة EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        اكسر;
    حالة EXCEPTION_STACK_OVERFLOW:
        rt_error(&f, "stack overflow");
        اكسر;
    حالة EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        اكسر;
    حالة EXCEPTION_BREAKPOINT:
    حالة EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ܦܢܐ EXCEPTION_CONTINUE_SEARCH;
    افتراضي:
        rt_error(&f, "caught exception %08x", code);
        اكسر;
    }
    rt_exit(&f, 255);
    ܦܢܐ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ساكن فراغ set_exception_handler(فراغ)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#ܐܚܪܢܐ
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ܐܢ defined(__i386__) || defined(__x86_64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحيح level)
{
    ܐܢ (level == 0) {
        *paddr = rc->ip;
    } ܐܚܪܢܐ {
        addr_t fp = rc->fp;
        ܟܡܐ (1) {
            ܐܢ (fp < 0x1000)
                ܦܢܐ -1;
            ܐܢ (0 == --level)
                اكسر;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ܦܢܐ 0;
}

/* XXX: only supports linux/bsd */
#وإلاإذا defined(__arm__) && !defined(_WIN32)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحيح level)
{
    ܐܢ (level == 0) {
        *paddr = rc->ip;
    } ܐܚܪܢܐ {
        addr_t fp = rc->fp;
        ܟܡܐ (1) {
            ܐܢ (fp < 0x1000)
                ܦܢܐ -1;
            ܐܢ (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ܦܢܐ 0;
}

#وإلاإذا defined(__aarch64__)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحيح level)
{
    ܐܢ (level == 0) {
        *paddr = rc->ip;
    } ܐܚܪܢܐ {
        addr_t fp = rc->fp;
        ܟܡܐ (1) {
            ܐܢ (fp < 0x1000)
                ܦܢܐ -1;
            ܐܢ (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ܦܢܐ 0;
}

#وإلاإذا defined(__riscv)
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحيح level)
{
    ܐܢ (level == 0) {
        *paddr = rc->ip;
    } ܐܚܪܢܐ {
        addr_t fp = rc->fp;
        ܟܡܐ (1) {
            ܐܢ (fp < 0x1000)
                ܦܢܐ -1;
            ܐܢ (0 == --level)
                اكسر;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ܦܢܐ 0;
}

#ܐܚܪܢܐ
#warning add arch specific rt_get_caller_pc()
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحيح level)
{
    ܦܢܐ -1;
}

#endif
#ܐܚܪܢܐ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ساكن صحيح rt_get_caller_pc(addr_t *paddr, rt_frame *f, صحيح level)
{
    ܐܢ (level)
        ܦܢܐ -1;
    *paddr = f->ip;
    ܦܢܐ 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC فراغ *dlopen(ثابت حرف *filename, صحيح flag)
{
    ܦܢܐ عدم;
}

ST_FUNC فراغ dlclose(فراغ *p)
{
}

ST_FUNC ثابت حرف *dlerror(فراغ)
{
    ܦܢܐ "error";
}

تعريفنوع بنية TCCSyms {
    حرف *str;
    فراغ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ساكن TCCSyms tcc_syms[] = {
#ܐܢ !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { عدم, عدم },
};

ST_FUNC فراغ *dlsym(فراغ *handle, ثابت حرف *symbol)
{
    TCCSyms *p;
    p = tcc_syms;
    ܟܡܐ (p->str != عدم) {
        ܐܢ (!strcmp(p->str, symbol))
            ܦܢܐ p->ptr;
        p++;
    }
    ܦܢܐ عدم;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
