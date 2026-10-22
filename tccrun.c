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
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
تعریفنوع ساختار rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    اجتماع {
	ساختار {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    نویسه *stab_str;
	};
	ساختار {
	    unsigned نویسه *dwarf_سطر;
	    unsigned نویسه *dwarf_سطر_end;
	    unsigned نویسه *dwarf_سطر_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    نویسه *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    تهی *bounds_start;
    تهی *بالاترین_func;
    ساختار rt_context *next;
    // 10 * PTR_SIZE
    صحیح رقم_callers;
    صحیح dwarf;
} rt_context;

/* linked list of rt_contexts */
ایستا rt_context *g_rc;
ایستا صحیح signal_set;
ایستا تهی set_exception_handler(تهی);
#endif /* def CONFIG_TCC_BACKTRACE */

تعریفنوع ساختار rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

ایستا TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ایستا rt_sem);
ایستا تهی rt_wait_sem(تهی) { WAIT_SEM(&rt_sem); }
ایستا تهی rt_post_sem(تهی) { POST_SEM(&rt_sem); }
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *f, صحیح level);
ایستا تهی rt_exit(rt_frame *f, صحیح code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

ایستا صحیح protect_pages(تهی *ptr, unsigned long length, صحیح mode);
ایستا صحیح tcc_relocate_ex(TCCState *s1, تهی *ptr, unsigned ptr_diff);
ایستا تهی st_link(TCCState *s1);
ایستا تهی st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
ایستا صحیح _tcc_backtrace(rt_frame *f, ثابت نویسه *fmt, va_list ap);
#endif
#ifdef _WIN64
ایستا تهی *win64_add_function_table(TCCState *s1);
ایستا تهی win64_del_function_table(تهی *);
#endif

#اگر !defined PAGESIZE
# اگر defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# وگرنه
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#اگر !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#اگر defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

ایستا صحیح rt_mem(TCCState *s1, صحیح size)
{
    تهی *ptr;
    صحیح ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    تهی *prw;
    نویسه tmpfname[] = "/tmp/.tccrunXXXXXX";
    صحیح fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(پوچ, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((نویسه*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    اگر (ptr == MAP_FAILED || prw == MAP_FAILED)
	بازگشت tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (نویسه*)prw - (نویسه*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#وگرنهاگر CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(پوچ, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    اگر (!ptr)
        بازگشت tcc_error_noabort("tccrun: could not allocate memory");
#وگرنه
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    بازگشت ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI صحیح tcc_relocate(TCCState *s1)
{
    صحیح size, ret, ptr_diff;

    اگر (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    اگر (s1->do_backtrace)
        tcc_add_نماد(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, پوچ, 0);
    اگر (size < 0)
        بازگشت -1;
    ptr_diff = rt_mem(s1, size);
    اگر (ptr_diff < 0)
        بازگشت -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    اگر (ret == 0)
        st_link(s1);
    بازگشت ret;
}

ST_FUNC تهی tcc_run_free(TCCState *s1)
{
    unsigned size;
    تهی *ptr;
    صحیح i;

    /* free any loaded DLLs */
    برای ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        اگر ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#وگرنه
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    اگر (پوچ == ptr)
        بازگشت;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#وگرنهاگر CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#وگرنه
    /* unprotect memory to make it usable for malloc again */
    protect_pages((تهی*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI صحیح tcc_run(TCCState *s1, صحیح argc, نویسه **argv)
{
    صحیح (*prog_main)(صحیح, نویسه **, نویسه **), ret;
    ثابت نویسه *بالاترین_sym;
    jmp_buf main_jb;

#اگر defined(__APPLE__)
    بیرونی نویسه ***_NSGetEnviron(تهی);
    نویسه **envp = *_NSGetEnviron();
#وگرنهاگر defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    بیرونی نویسه **environ;
    نویسه **envp = environ;
#وگرنه
    نویسه **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    اگر ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        بازگشت 0;

    tcc_add_نماد(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", بالاترین_sym = "main";
    اگر (s1->elf_entryname)
        s1->run_main = بالاترین_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    اگر (tcc_relocate(s1) < 0)
        بازگشت -1;

    prog_main = (تهی*)get_sym_addr(s1, s1->run_main, 1, 1);
    اگر ((addr_t)-1 == (addr_t)prog_main)
        بازگشت -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    اگر (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        بازگشت -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_نماد(s1, بالاترین_sym));
    اگر (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } وگرنه اگر (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    اگر (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    بازگشت ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ایستا تهی cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    صحیح sym_index, end_sym = s->data_offset / اندازه (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    برای (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ثابت نویسه *name = (نویسه *)s->link->data + sym->st_name;
        اگر (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ادامه;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_مقدار, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ایستا تهی cleanup_sections(TCCState *s1)
{
    ساختار { Section **secs; صحیح nb_secs; } *p = (تهی*)&s1->sections;
    صحیح i, f = 2;
    انجامبده {
        برای (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            اگر (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } وگرنه {
                free_section(s), tcc_free(s), p->secs[i] = پوچ;
            }
        }
    } وقتی (++p, f);
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
# وگرنه
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ایستا صحیح tcc_relocate_ex(TCCState *s1, تهی *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    اگر (پوچ == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, پوچ);
#وگرنه
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    اگر (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    اگر (s1->nb_errors)
        بازگشت -1;
    اگر (copy == 3)
        بازگشت 0;

    برای (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        برای(i = 1; i < s1->nb_sections; i++) {
            ایستا ثابت نویسه shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            اگر (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ادامه;
            length = s->data_offset;
            اگر (copy == 2) {
                اگر (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                ادامه;
            }
            اگر (copy) { /* final step: copy section data to memory */
                اگر (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (تهی*)s->sh_addr, length, s->sh_addralign);
                ptr = (تهی*)s->sh_addr;
                اگر (k == 0)
                    ptr = (تهی*)(s->sh_addr + ptr_diff);
                اگر (پوچ == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                وگرنه
                    memcpy(ptr, s->data, length);
                ادامه;
            }

            اگر ((s->sh_flags & SHF_TLS) && length)
                بازگشت tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            اگر (++n == 1) {
#اگر defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                اگر (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                اگر (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        اگر (copy == 2) { /* set permissions */
            اگر (n == 0) /* no data  */
                ادامه;
#ifdef CONFIG_SELINUX
            اگر (k == 0) /* SHF_EXECINSTR has its own mapping */
                ادامه;
#endif
            f = k;
            اگر (f >= CONFIG_RUNMEM_RO) {
                اگر (f != 0)
                    ادامه;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            اگر (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (تهی*)addr, (unsigned)n);
            }
            اگر (protect_pages((تهی*)addr, n, f) < 0)
                بازگشت tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#وگرنه
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    اگر (0 == mem)
        بازگشت PAGEALIGN(offset);

    اگر (++copy == 2) {
        برو redo;
    }
    اگر (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        برو redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    اگر (s1->nb_errors)
        برو redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#وگرنه
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    برو redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ایستا صحیح protect_pages(تهی *ptr, unsigned long length, صحیح mode)
{
#ifdef _WIN32
    ایستا ثابت unsigned نویسه protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    اگر (!VirtualProtect(ptr, length, protect[mode], &old))
        بازگشت -1;
#وگرنه
    ایستا ثابت unsigned نویسه protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    اگر (mprotect(ptr, length, protect[mode]))
        بازگشت -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#اگر (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    اگر (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#وگرنه
        تهی __clear_cache(تهی *beginning, تهی *end);
        __clear_cache(ptr, (نویسه *)ptr + length);
#endif
    }
#endif
    بازگشت 0;
}

#ifdef _WIN64
ایستا تهی *win64_add_function_table(TCCState *s1)
{
    تهی *p = پوچ;
    اگر (s1->uw_pdata) {
        p = (تهی*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / اندازه (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = پوچ;
    }
    بازگشت p;
}

ایستا تهی win64_del_function_table(تهی *p)
{
    اگر (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

ایستا تهی bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    اگر (!s1->do_backtrace)
        بازگشت;
    rc = tcc_get_نماد(s1, "__rt_info");
    اگر (!rc)
        بازگشت;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (نویسه *)symtab_section->link->data;
    اگر (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    اگر (s1->do_bounds_check) {
        تهی *p;
        اگر ((p = tcc_get_نماد(s1, "__bound_init")))
            ((تهی(*)(تهی*,صحیح))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    اگر (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

ایستا تهی st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ایستا تهی ptr_unlink(تهی *list, تهی *e, unsigned next)
{
    تهی **pp, **nn, *p;
    برای (pp = list; !!(p = *pp); pp = nn) {
        nn = (تهی*)((نویسه*)p + next); /* nn = &p->next; */
        اگر (p == e) {
            *pp = *nn;
            بشکن;
        }
    }
}

ایستا تهی st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI تهی *_tcc_setjmp(TCCState *s1, تهی *p_jmp_buf, تهی *func, تهی *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    اگر (s1->rc)
        s1->rc->بالاترین_func = func;
#endif
    بازگشت p_jmp_buf;
}

LIBTCCAPI تهی tcc_set_backtrace_func(TCCState *s1, تهی *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

ایستا TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    صحیح level;
    addr_t pc;

    s = g_s1;
    اگر (پوچ == s || پوچ == s->next) {
        /* play it safe in the simple case when there is only one state */
        بازگشت s;
    }
    برای (level = 0; level < 8; ++level) {
        اگر (rt_get_caller_pc(&pc, f, level) < 0)
            بشکن;
        برای (s = g_s1; s; s = s->next) {
            اگر (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                بازگشت s;
        }
    }
    بازگشت پوچ;
}

ایستا تهی rt_exit(rt_frame *f, صحیح code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    اگر (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        اگر (f->fp) { /* called from signal */
            تهی *p = tcc_get_نماد(s, "__bound_exit");
            اگر (p)
                ((تهی (*)(تهی))p)();
        }
#endif
        اگر (code == 0)
            code = RT_EXIT_ZERO;
        ((تهی(*)(تهی*,صحیح))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#وگرنه // if defined CONFIG_TCC_BACKTRACE_ONLY
ایستا تهی rt_exit(rt_frame *f, صحیح code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

ایستا صحیح rt_vprintf(ثابت نویسه *fmt, va_list ap)
{
    صحیح ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    بازگشت ret;
}

ایستا صحیح rt_printf(ثابت نویسه *fmt, ...)
{
    va_list ap;
    صحیح r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    بازگشت r;
}

ایستا نویسه *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    برای (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        صحیح type = ELFW(ST_TYPE)(esym->st_info);
        اگر ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_مقدار
            && wanted_pc < esym->st_مقدار + esym->st_size) {
            *func_addr = esym->st_مقدار;
            بازگشت rc->elf_str + esym->st_name;
        }
    }
    بازگشت پوچ;
}

تعریفنوع ساختار bt_info
{
    نویسه file[100];
    صحیح سطر;
    نویسه func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ایستا addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    نویسه func_name[128];
    addr_t func_addr, last_pc, pc;
    ثابت نویسه *incl_files[INCLUDE_پشته_SIZE];
    صحیح incl_index, last_incl_index, len, last_سطر_رقم, i;
    ثابت نویسه *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_سطر_رقم = 1;
    last_incl_index = 0;

    برای (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_مقدار;

        انتخاب(sym->n_type) {
        حالت N_SLINE:
            اگر (func_addr)
                برو rel_pc;
        حالت N_SO:
        حالت N_SOL:
            برو abs_pc;
        حالت N_FUN:
            اگر (sym->n_strx == 0) /* end of function */
                برو rel_pc;
        abs_pc:
#اگر PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            برو check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            اگر (pc >= wanted_pc && wanted_pc >= last_pc)
                برو found;
            بشکن;
        }

        انتخاب(sym->n_type) {
            /* function start or end */
        حالت N_FUN:
            اگر (sym->n_strx == 0)
                برو reset_func;
            p = strchr(str, ':');
            اگر (0 == p || (len = p - str + 1, len > اندازه func_name))
                len = اندازه func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            بشکن;
            /* line number info */
        حالت N_SLINE:
            last_pc = pc;
            last_سطر_رقم = sym->n_desc;
            last_incl_index = incl_index;
            بشکن;
            /* include files */
        حالت N_BINCL:
            اگر (incl_index < INCLUDE_پشته_SIZE)
                incl_files[incl_index++] = str;
            بشکن;
        حالت N_EINCL:
            اگر (incl_index > 1)
                incl_index--;
            بشکن;
            /* start/end of translation unit */
        حالت N_SO:
            incl_index = 0;
            اگر (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                اگر (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            بشکن;
            /* alternative file name (from #line or #include directives) */
        حالت N_SOL:
            اگر (incl_index)
                incl_files[incl_index-1] = str;
            بشکن;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    اگر (i > 0) {
        pstrcpy(bi->file, اندازه bi->file, incl_files[--i]);
        bi->سطر = last_سطر_رقم;
    }
    pstrcpy(bi->func, اندازه bi->func, func_name);
    bi->func_pc = func_addr;
    بازگشت func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	انتخاب (entry_format[j].form) { \
	حالت DW_FORM_data1: (ln) += 1; بشکن; \
	حالت DW_FORM_data2: (ln) += 2; بشکن; \
	حالت DW_FORM_data4: (ln) += 3; بشکن; \
	حالت DW_FORM_data8: (ln) += 8; بشکن; \
	حالت DW_FORM_data16: (ln) += 16; بشکن; \
	حالت DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); بشکن; \
	پیشفرض: برو next_سطر; \
	}

ایستا addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned نویسه *ln;
    unsigned نویسه *cp;
    unsigned نویسه *end;
    unsigned نویسه *opcode_length;
    unsigned long long size;
    unsigned صحیح length;
    unsigned نویسه version;
    unsigned صحیح min_insn_length;
    unsigned صحیح max_ops_per_insn;
    صحیح سطر_base;
    unsigned صحیح سطر_range;
    unsigned صحیح opcode_base;
    unsigned صحیح opindex;
    unsigned صحیح col;
    unsigned صحیح i;
    unsigned صحیح j;
    unsigned صحیح len;
    unsigned long long مقدار;
    ساختار {
	unsigned صحیح type;
	unsigned صحیح form;
    } entry_format[256];
    unsigned صحیح dir_size;
#اگر 0
    نویسه *dirs[DIR_TABLE_SIZE];
#endif
    unsigned صحیح filename_size;
    ساختار /*dwarf_filename_struct*/ {
        unsigned صحیح dir_entry;
        نویسه *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    صحیح سطر;
    نویسه *filename;
    نویسه *function;

    filename = پوچ;
    function = پوچ;
    func_addr = 0;
    سطر = 0;

    ln = rc->dwarf_سطر;
    وقتی (ln < rc->dwarf_سطر_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        سطر = 1;
        filename = پوچ;
        function = پوچ;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_سطر_end);
	اگر (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_سطر_end);
	end = ln + size;
	اگر (end < ln || end > rc->dwarf_سطر_end)
	    بشکن;
	version = dwarf_read_2(ln, end);
	اگر (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	وگرنه
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	اگر (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	وگرنه
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	سطر_base = dwarf_read_1(ln, end);
	سطر_base |= سطر_base >= 0x80 ? ~0xff : 0;
	سطر_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	اگر (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    برای (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    برای (i = 0; i < dir_size; i++) {
		برای (j = 0; j < col; j++) {
		    اگر (entry_format[j].type == DW_LNCT_path) {
		        اگر (entry_format[j].form != DW_FORM_سطر_strp)
			    برو next_سطر;
#اگر 0
		        مقدار = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        اگر (i < DIR_TABLE_SIZE)
		            dirs[i] = (نویسه *)rc->dwarf_سطر_str + مقدار;
#وگرنه
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    وگرنه 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    برای (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    برای (i = 0; i < filename_size; i++)
		برای (j = 0; j < col; j++) {
		    اگر (entry_format[j].type == DW_LNCT_path) {
			اگر (entry_format[j].form != DW_FORM_سطر_strp)
			    برو next_سطر;
			مقدار = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        اگر (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(نویسه *)rc->dwarf_سطر_str + مقدار;
	            }
		    وگرنه اگر (entry_format[j].type == DW_LNCT_directory_index) {
			انتخاب (entry_format[j].form) {
			حالت DW_FORM_data1: مقدار = dwarf_read_1(ln, end); بشکن;
			حالت DW_FORM_data2: مقدار = dwarf_read_2(ln, end); بشکن;
			حالت DW_FORM_data4: مقدار = dwarf_read_4(ln, end); بشکن;
			حالت DW_FORM_udata: مقدار = dwarf_read_uleb128(&ln, end); بشکن;
			پیشفرض: برو next_سطر;
			}
		        اگر (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = مقدار;
		    }
		    وگرنه 
			dwarf_ignore_type(ln, end);
	    }
	}
	وگرنه {
	    وقتی ((dwarf_read_1(ln, end))) {
#اگر 0
		اگر (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (نویسه *)ln - 1;
#endif
		وقتی (dwarf_read_1(ln, end)) {}
	    }
	    وقتی ((dwarf_read_1(ln, end))) {
		اگر (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (نویسه *)ln - 1;
		    وقتی (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		وگرنه {
		    وقتی (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	اگر (filename_size >= 1)
	    filename = filename_table[0].name;
	وقتی (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    اگر (i >= opcode_base) {
	        اگر (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / سطر_range) * min_insn_length;
		وگرنه {
		    pc += (opindex + (i - opcode_base) / سطر_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / سطر_range) %
			       max_ops_per_insn;
		}
		i = (صحیح)((i - opcode_base) % سطر_range) + سطر_base;
check_pc:
		اگر (pc >= wanted_pc && wanted_pc >= last_pc)
		    برو found;
		سطر += i;
	    }
	    وگرنه {
	        انتخاب (i) {
	        حالت 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    اگر (len == 0)
		        برو next_سطر;
		    انتخاب (dwarf_read_1(cp, end)) {
		    حالت DW_LNE_end_sequence:
		        بشکن;
		    حالت DW_LNE_set_address:
#اگر PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#وگرنه
		        pc = dwarf_read_8(cp, end);
#endif
#اگر defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        بشکن;
		    حالت DW_LNE_define_file: /* deprecated */
		        اگر (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (نویسه *)ln - 1;
		            وقتی (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        وگرنه {
		            وقتی (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        بشکن;
		    حالت DW_LNE_hi_user - 1:
		        function = (نویسه *)cp;
		        func_addr = pc;
		        بشکن;
		    پیشفرض:
		        بشکن;
		    }
		    بشکن;
	        حالت DW_LNS_advance_pc:
		    اگر (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    وگرنه {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    برو check_pc;
	        حالت DW_LNS_advance_سطر:
		    سطر += dwarf_read_sleb128(&ln, end);
		    بشکن;
	        حالت DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    اگر (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    بشکن;
	        حالت DW_LNS_const_add_pc:
		    اگر (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / سطر_range) * min_insn_length;
		    وگرنه {
		        unsigned صحیح off = (255 - opcode_base) / سطر_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    برو check_pc;
	        حالت DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    برو check_pc;
	        پیشفرض:
		    برای (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    بشکن;
		}
	    }
	}
next_سطر:
	ln = end;
    }
    filename = function = پوچ, func_addr = 0;
found:
    اگر (filename)
        pstrcpy(bi->file, اندازه bi->file, filename), bi->سطر = سطر;
    اگر (function)
        pstrcpy(bi->func, اندازه bi->func, function);
    bi->func_pc = func_addr;
    بازگشت (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
ایستا
#endif
صحیح _tcc_backtrace(rt_frame *f, ثابت نویسه *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    نویسه skip[40], پیام[200];
    صحیح i, level, ret, n, one;
    ثابت نویسه *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    اگر (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    اگر (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(پیام, اندازه پیام, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    اگر (rc) {
        اگر (rc->dwarf)
            getinfo = rt_printline_dwarf;
        اگر (rc->رقم_callers)
            n = rc->رقم_callers;
    }

    برای (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        اگر (ret == -1)
            بشکن;
        memset(&bi, 0, اندازه bi);
        برای (rc2 = rc; rc2; rc2 = rc2->next) {
            اگر (getinfo(rc2, pc, &bi))
                بشکن;
            /* we try symtab symbols (no line number info) */
            اگر (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, اندازه bi.func, a);
                بشکن;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        اگر (skip[0] && strstr(bi.file, skip))
            ادامه;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            اگر (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (تهی*)pc,
                    bi.file[0] ? bi.file : پوچ,
                    bi.سطر,
                    bi.func[0] ? bi.func : پوچ,
                    level == 0 ? پیام : پوچ
                    );
                اگر (ret == 0)
                    بشکن;
                برو check_break;
            }
        }
#endif
        اگر (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.سطر);
        } وگرنه {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        اگر (level == 0) {
            rt_printf(": %s", پیام);
            اگر (one)
                بشکن;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        اگر (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->بالاترین_func)
            بشکن;
        ++level;
    }
    rt_post_sem();
    بازگشت 0;
}

/* emit a run time error at position 'pc' */
ایستا صحیح rt_error(rt_frame *f, ثابت نویسه *fmt, ...)
{
    va_list ap; نویسه پیام[200]; صحیح ret;
    va_start(ap, fmt);
    snprintf(پیام, اندازه پیام, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, پیام, ap);
    va_end(ap);
    بازگشت ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#وگرنه
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
ایستا تهی rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#اگر defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#وگرنهاگر defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#وگرنهاگر defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#وگرنهاگر defined __i386__
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
# وگرنه
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#وگرنهاگر defined(__x86_64__)
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
# وگرنه
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#وگرنهاگر defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنهاگر defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#وگرنهاگر defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنهاگر defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#وگرنهاگر defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#وگرنهاگر defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#وگرنهاگر defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#وگرنهاگر defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#وگرنهاگر defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#وگرنهاگر defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#وگرنهاگر defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
ایستا تهی sig_error(صحیح signum, siginfo_t *siginf, تهی *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    انتخاب(signum) {
    حالت SIGFPE:
        انتخاب(siginf->si_code) {
        حالت FPE_INTDIV:
        حالت FPE_FLTDIV:
            rt_error(&f, "division by zero");
            بشکن;
        پیشفرض:
            rt_error(&f, "floating point exception");
            بشکن;
        }
        بشکن;
    حالت SIGBUS:
    حالت SIGSEGV:
        rt_error(&f, "invalid memory access");
        بشکن;
    حالت SIGILL:
        rt_error(&f, "illegal instruction");
        بشکن;
    حالت SIGABRT:
        rt_error(&f, "abort() called");
        بشکن;
    پیشفرض:
        rt_error(&f, "caught signal %d", signum);
        بشکن;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, پوچ);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
ایستا تهی set_exception_handler(تهی)
{
    ساختار sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#اگر 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, پوچ);
    sigaction(SIGILL, &sigact, پوچ);
    sigaction(SIGSEGV, &sigact, پوچ);
    sigaction(SIGBUS, &sigact, پوچ);
    sigaction(SIGABRT, &sigact, پوچ);
#اگر 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ایستا unsigned نویسه پشته[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = پشته;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, پوچ);
    }
#endif
}

#وگرنه /* WIN32 */

/* signal handler for fatal errors */
ایستا long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    انتخاب (code = ex_info->ExceptionRecord->ExceptionCode) {
    حالت EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        بشکن;
    حالت EXCEPTION_پشته_OVERFLOW:
        rt_error(&f, "stack overflow");
        بشکن;
    حالت EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        بشکن;
    حالت EXCEPTION_BREAKPOINT:
    حالت EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        بازگشت EXCEPTION_CONTINUE_جستجو;
    پیشفرض:
        rt_error(&f, "caught exception %08x", code);
        بشکن;
    }
    rt_exit(&f, 255);
    بازگشت EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ایستا تهی set_exception_handler(تهی)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#وگرنه
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#اگر defined(__i386__) || defined(__x86_64__)
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } وگرنه {
        addr_t fp = rc->fp;
        وقتی (1) {
            اگر (fp < 0x1000)
                بازگشت -1;
            اگر (0 == --level)
                بشکن;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    بازگشت 0;
}

/* XXX: only supports linux/bsd */
#وگرنهاگر defined(__arm__) && !defined(_WIN32)
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } وگرنه {
        addr_t fp = rc->fp;
        وقتی (1) {
            اگر (fp < 0x1000)
                بازگشت -1;
            اگر (0 == --level)
                بشکن;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    بازگشت 0;
}

#وگرنهاگر defined(__aarch64__)
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } وگرنه {
        addr_t fp = rc->fp;
        وقتی (1) {
            اگر (fp < 0x1000)
                بازگشت -1;
            اگر (0 == --level)
                بشکن;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    بازگشت 0;
}

#وگرنهاگر defined(__riscv)
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحیح level)
{
    اگر (level == 0) {
        *paddr = rc->ip;
    } وگرنه {
        addr_t fp = rc->fp;
        وقتی (1) {
            اگر (fp < 0x1000)
                بازگشت -1;
            اگر (0 == --level)
                بشکن;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    بازگشت 0;
}

#وگرنه
#warning add arch specific rt_get_caller_pc()
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *rc, صحیح level)
{
    بازگشت -1;
}

#endif
#وگرنه // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ایستا صحیح rt_get_caller_pc(addr_t *paddr, rt_frame *f, صحیح level)
{
    اگر (level)
        بازگشت -1;
    *paddr = f->ip;
    بازگشت 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC تهی *dlopen(ثابت نویسه *filename, صحیح flag)
{
    بازگشت پوچ;
}

ST_FUNC تهی dlclose(تهی *p)
{
}

ST_FUNC ثابت نویسه *dlerror(تهی)
{
    بازگشت "error";
}

تعریفنوع ساختار TCCSyms {
    نویسه *str;
    تهی *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ایستا TCCSyms tcc_syms[] = {
#اگر !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { پوچ, پوچ },
};

ST_FUNC تهی *dlsym(تهی *handle, ثابت نویسه *نماد)
{
    TCCSyms *p;
    p = tcc_syms;
    وقتی (p->str != پوچ) {
        اگر (!strcmp(p->str, نماد))
            بازگشت p->ptr;
        p++;
    }
    بازگشت پوچ;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
