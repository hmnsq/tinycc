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

#अन्तर्भाव "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
प्रकारनिर्देश संरचना rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    सङ्घ {
	संरचना {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    वर्ण *stab_str;
	};
	संरचना {
	    unsigned वर्ण *dwarf_पङ्क्तिः;
	    unsigned वर्ण *dwarf_पङ्क्तिः_end;
	    unsigned वर्ण *dwarf_पङ्क्तिः_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    वर्ण *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    शून्य *bounds_start;
    शून्य *शिखरम्_func;
    संरचना rt_context *next;
    // 10 * PTR_SIZE
    पूर्णाङ्क अङ्कः_callers;
    पूर्णाङ्क dwarf;
} rt_context;

/* linked list of rt_contexts */
स्थिर rt_context *g_rc;
स्थिर पूर्णाङ्क signal_set;
स्थिर शून्य set_exception_handler(शून्य);
#endif /* def CONFIG_TCC_BACKTRACE */

प्रकारनिर्देश संरचना rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

स्थिर TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(स्थिर rt_sem);
स्थिर शून्य rt_wait_sem(शून्य) { WAIT_SEM(&rt_sem); }
स्थिर शून्य rt_post_sem(शून्य) { POST_SEM(&rt_sem); }
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णाङ्क level);
स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

स्थिर पूर्णाङ्क protect_pages(शून्य *ptr, unsigned long length, पूर्णाङ्क mode);
स्थिर पूर्णाङ्क tcc_relocate_ex(TCCState *s1, शून्य *ptr, unsigned ptr_diff);
स्थिर शून्य st_link(TCCState *s1);
स्थिर शून्य st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
स्थिर पूर्णाङ्क _tcc_backtrace(rt_frame *f, ध्रुव वर्ण *fmt, va_list ap);
#endif
#ifdef _WIN64
स्थिर शून्य *win64_add_function_table(TCCState *s1);
स्थिर शून्य win64_del_function_table(शून्य *);
#endif

#जइ !defined PAGESIZE
# जइ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# अण्णहा
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#जइ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#जइ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

स्थिर पूर्णाङ्क rt_mem(TCCState *s1, पूर्णाङ्क size)
{
    शून्य *ptr;
    पूर्णाङ्क ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    शून्य *prw;
    वर्ण tmpfname[] = "/tmp/.tccrunXXXXXX";
    पूर्णाङ्क fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(रिक्त, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((वर्ण*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    जइ (ptr == MAP_FAILED || prw == MAP_FAILED)
	प्रत्यागम tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (वर्ण*)prw - (वर्ण*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#नोचेद्यदि CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(रिक्त, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    जइ (!ptr)
        प्रत्यागम tcc_error_noabort("tccrun: could not allocate memory");
#अण्णहा
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    प्रत्यागम ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI पूर्णाङ्क tcc_relocate(TCCState *s1)
{
    पूर्णाङ्क size, ret, ptr_diff;

    जइ (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    जइ (s1->do_backtrace)
        tcc_add_चिह्नम्(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, रिक्त, 0);
    जइ (size < 0)
        प्रत्यागम -1;
    ptr_diff = rt_mem(s1, size);
    जइ (ptr_diff < 0)
        प्रत्यागम -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    जइ (ret == 0)
        st_link(s1);
    प्रत्यागम ret;
}

ST_FUNC शून्य tcc_run_free(TCCState *s1)
{
    unsigned size;
    शून्य *ptr;
    पूर्णाङ्क i;

    /* free any loaded DLLs */
    प्रति ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        जइ ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#अण्णहा
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    जइ (रिक्त == ptr)
        प्रत्यागम;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#नोचेद्यदि CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#अण्णहा
    /* unprotect memory to make it usable for malloc again */
    protect_pages((शून्य*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI पूर्णाङ्क tcc_run(TCCState *s1, पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क (*prog_main)(पूर्णाङ्क, वर्ण **, वर्ण **), ret;
    ध्रुव वर्ण *शिखरम्_sym;
    jmp_buf main_jb;

#जइ defined(__APPLE__)
    बाह्य वर्ण ***_NSGetEnviron(शून्य);
    वर्ण **envp = *_NSGetEnviron();
#नोचेद्यदि defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    बाह्य वर्ण **environ;
    वर्ण **envp = environ;
#अण्णहा
    वर्ण **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    जइ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        प्रत्यागम 0;

    tcc_add_चिह्नम्(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", शिखरम्_sym = "main";
    जइ (s1->elf_entryname)
        s1->run_main = शिखरम्_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    जइ (tcc_relocate(s1) < 0)
        प्रत्यागम -1;

    prog_main = (शून्य*)get_sym_addr(s1, s1->run_main, 1, 1);
    जइ ((addr_t)-1 == (addr_t)prog_main)
        प्रत्यागम -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    जइ (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        प्रत्यागम -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_चिह्नम्(s1, शिखरम्_sym));
    जइ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } अण्णहा जइ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    जइ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
स्थिर शून्य cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णाङ्क sym_index, end_sym = s->data_offset / परिमाण (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    प्रति (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ध्रुव वर्ण *name = (वर्ण *)s->link->data + sym->st_name;
        जइ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            अनुवर्त;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_मानम्, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
स्थिर शून्य cleanup_sections(TCCState *s1)
{
    संरचना { Section **secs; पूर्णाङ्क nb_secs; } *p = (शून्य*)&s1->sections;
    पूर्णाङ्क i, f = 2;
    करेहि {
        प्रति (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            जइ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } अण्णहा {
                free_section(s), tcc_free(s), p->secs[i] = रिक्त;
            }
        }
    } जाव (++p, f);
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
# अण्णहा
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
स्थिर पूर्णाङ्क tcc_relocate_ex(TCCState *s1, शून्य *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    जइ (रिक्त == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, रिक्त);
#अण्णहा
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    जइ (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    जइ (s1->nb_errors)
        प्रत्यागम -1;
    जइ (copy == 3)
        प्रत्यागम 0;

    प्रति (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        प्रति(i = 1; i < s1->nb_sections; i++) {
            स्थिर ध्रुव वर्ण shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            जइ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                अनुवर्त;
            length = s->data_offset;
            जइ (copy == 2) {
                जइ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                अनुवर्त;
            }
            जइ (copy) { /* final step: copy section data to memory */
                जइ (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (शून्य*)s->sh_addr, length, s->sh_addralign);
                ptr = (शून्य*)s->sh_addr;
                जइ (k == 0)
                    ptr = (शून्य*)(s->sh_addr + ptr_diff);
                जइ (रिक्त == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                अण्णहा
                    memcpy(ptr, s->data, length);
                अनुवर्त;
            }

            जइ ((s->sh_flags & SHF_TLS) && length)
                प्रत्यागम tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            जइ (++n == 1) {
#जइ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                जइ (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                जइ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        जइ (copy == 2) { /* set permissions */
            जइ (n == 0) /* no data  */
                अनुवर्त;
#ifdef CONFIG_SELINUX
            जइ (k == 0) /* SHF_EXECINSTR has its own mapping */
                अनुवर्त;
#endif
            f = k;
            जइ (f >= CONFIG_RUNMEM_RO) {
                जइ (f != 0)
                    अनुवर्त;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            जइ (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (शून्य*)addr, (unsigned)n);
            }
            जइ (protect_pages((शून्य*)addr, n, f) < 0)
                प्रत्यागम tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#अण्णहा
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    जइ (0 == mem)
        प्रत्यागम PAGEALIGN(offset);

    जइ (++copy == 2) {
        गच्छ redo;
    }
    जइ (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        गच्छ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    जइ (s1->nb_errors)
        गच्छ redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#अण्णहा
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    गच्छ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

स्थिर पूर्णाङ्क protect_pages(शून्य *ptr, unsigned long length, पूर्णाङ्क mode)
{
#ifdef _WIN32
    स्थिर ध्रुव unsigned वर्ण protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    जइ (!VirtualProtect(ptr, length, protect[mode], &old))
        प्रत्यागम -1;
#अण्णहा
    स्थिर ध्रुव unsigned वर्ण protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    जइ (mprotect(ptr, length, protect[mode]))
        प्रत्यागम -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#जइ (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    जइ (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#अण्णहा
        शून्य __clear_cache(शून्य *beginning, शून्य *end);
        __clear_cache(ptr, (वर्ण *)ptr + length);
#endif
    }
#endif
    प्रत्यागम 0;
}

#ifdef _WIN64
स्थिर शून्य *win64_add_function_table(TCCState *s1)
{
    शून्य *p = रिक्त;
    जइ (s1->uw_pdata) {
        p = (शून्य*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / परिमाण (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = रिक्त;
    }
    प्रत्यागम p;
}

स्थिर शून्य win64_del_function_table(शून्य *p)
{
    जइ (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

स्थिर शून्य bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    जइ (!s1->do_backtrace)
        प्रत्यागम;
    rc = tcc_get_चिह्नम्(s1, "__rt_info");
    जइ (!rc)
        प्रत्यागम;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (वर्ण *)symtab_section->link->data;
    जइ (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    जइ (s1->do_bounds_check) {
        शून्य *p;
        जइ ((p = tcc_get_चिह्नम्(s1, "__bound_init")))
            ((शून्य(*)(शून्य*,पूर्णाङ्क))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    जइ (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

स्थिर शून्य st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
स्थिर शून्य ptr_unlink(शून्य *list, शून्य *e, unsigned next)
{
    शून्य **pp, **nn, *p;
    प्रति (pp = list; !!(p = *pp); pp = nn) {
        nn = (शून्य*)((वर्ण*)p + next); /* nn = &p->next; */
        जइ (p == e) {
            *pp = *nn;
            भङ्ग;
        }
    }
}

स्थिर शून्य st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI शून्य *_tcc_setjmp(TCCState *s1, शून्य *p_jmp_buf, शून्य *func, शून्य *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    जइ (s1->rc)
        s1->rc->शिखरम्_func = func;
#endif
    प्रत्यागम p_jmp_buf;
}

LIBTCCAPI शून्य tcc_set_backtrace_func(TCCState *s1, शून्य *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

स्थिर TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    पूर्णाङ्क level;
    addr_t pc;

    s = g_s1;
    जइ (रिक्त == s || रिक्त == s->next) {
        /* play it safe in the simple case when there is only one state */
        प्रत्यागम s;
    }
    प्रति (level = 0; level < 8; ++level) {
        जइ (rt_get_caller_pc(&pc, f, level) < 0)
            भङ्ग;
        प्रति (s = g_s1; s; s = s->next) {
            जइ (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                प्रत्यागम s;
        }
    }
    प्रत्यागम रिक्त;
}

स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    जइ (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        जइ (f->fp) { /* called from signal */
            शून्य *p = tcc_get_चिह्नम्(s, "__bound_exit");
            जइ (p)
                ((शून्य (*)(शून्य))p)();
        }
#endif
        जइ (code == 0)
            code = RT_EXIT_ZERO;
        ((शून्य(*)(शून्य*,पूर्णाङ्क))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#अण्णहा // if defined CONFIG_TCC_BACKTRACE_ONLY
स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

स्थिर पूर्णाङ्क rt_vprintf(ध्रुव वर्ण *fmt, va_list ap)
{
    पूर्णाङ्क ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    प्रत्यागम ret;
}

स्थिर पूर्णाङ्क rt_printf(ध्रुव वर्ण *fmt, ...)
{
    va_list ap;
    पूर्णाङ्क r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    प्रत्यागम r;
}

स्थिर वर्ण *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    प्रति (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        पूर्णाङ्क type = ELFW(ST_TYPE)(esym->st_info);
        जइ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_मानम्
            && wanted_pc < esym->st_मानम् + esym->st_size) {
            *func_addr = esym->st_मानम्;
            प्रत्यागम rc->elf_str + esym->st_name;
        }
    }
    प्रत्यागम रिक्त;
}

प्रकारनिर्देश संरचना bt_info
{
    वर्ण file[100];
    पूर्णाङ्क पङ्क्तिः;
    वर्ण func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
स्थिर addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    वर्ण func_name[128];
    addr_t func_addr, last_pc, pc;
    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_SIZE];
    पूर्णाङ्क incl_index, last_incl_index, len, last_पङ्क्तिः_अङ्कः, i;
    ध्रुव वर्ण *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_पङ्क्तिः_अङ्कः = 1;
    last_incl_index = 0;

    प्रति (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_मानम्;

        विकल्प(sym->n_type) {
        पक्ष N_SLINE:
            जइ (func_addr)
                गच्छ rel_pc;
        पक्ष N_SO:
        पक्ष N_SOL:
            गच्छ abs_pc;
        पक्ष N_FUN:
            जइ (sym->n_strx == 0) /* end of function */
                गच्छ rel_pc;
        abs_pc:
#जइ PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            गच्छ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            जइ (pc >= wanted_pc && wanted_pc >= last_pc)
                गच्छ found;
            भङ्ग;
        }

        विकल्प(sym->n_type) {
            /* function start or end */
        पक्ष N_FUN:
            जइ (sym->n_strx == 0)
                गच्छ reset_func;
            p = strchr(str, ':');
            जइ (0 == p || (len = p - str + 1, len > परिमाण func_name))
                len = परिमाण func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            भङ्ग;
            /* line number info */
        पक्ष N_SLINE:
            last_pc = pc;
            last_पङ्क्तिः_अङ्कः = sym->n_desc;
            last_incl_index = incl_index;
            भङ्ग;
            /* include files */
        पक्ष N_BINCL:
            जइ (incl_index < INCLUDE_राशिः_SIZE)
                incl_files[incl_index++] = str;
            भङ्ग;
        पक्ष N_EINCL:
            जइ (incl_index > 1)
                incl_index--;
            भङ्ग;
            /* start/end of translation unit */
        पक्ष N_SO:
            incl_index = 0;
            जइ (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                जइ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            भङ्ग;
            /* alternative file name (from #line or #include directives) */
        पक्ष N_SOL:
            जइ (incl_index)
                incl_files[incl_index-1] = str;
            भङ्ग;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    जइ (i > 0) {
        pstrcpy(bi->file, परिमाण bi->file, incl_files[--i]);
        bi->पङ्क्तिः = last_पङ्क्तिः_अङ्कः;
    }
    pstrcpy(bi->func, परिमाण bi->func, func_name);
    bi->func_pc = func_addr;
    प्रत्यागम func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	विकल्प (entry_format[j].form) { \
	पक्ष DW_FORM_data1: (ln) += 1; भङ्ग; \
	पक्ष DW_FORM_data2: (ln) += 2; भङ्ग; \
	पक्ष DW_FORM_data4: (ln) += 3; भङ्ग; \
	पक्ष DW_FORM_data8: (ln) += 8; भङ्ग; \
	पक्ष DW_FORM_data16: (ln) += 16; भङ्ग; \
	पक्ष DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); भङ्ग; \
	स्वभाव: गच्छ next_पङ्क्तिः; \
	}

स्थिर addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned वर्ण *ln;
    unsigned वर्ण *cp;
    unsigned वर्ण *end;
    unsigned वर्ण *opcode_length;
    unsigned long long size;
    unsigned पूर्णाङ्क length;
    unsigned वर्ण version;
    unsigned पूर्णाङ्क min_insn_length;
    unsigned पूर्णाङ्क max_ops_per_insn;
    पूर्णाङ्क पङ्क्तिः_base;
    unsigned पूर्णाङ्क पङ्क्तिः_range;
    unsigned पूर्णाङ्क opcode_base;
    unsigned पूर्णाङ्क opindex;
    unsigned पूर्णाङ्क col;
    unsigned पूर्णाङ्क i;
    unsigned पूर्णाङ्क j;
    unsigned पूर्णाङ्क len;
    unsigned long long मानम्;
    संरचना {
	unsigned पूर्णाङ्क type;
	unsigned पूर्णाङ्क form;
    } entry_format[256];
    unsigned पूर्णाङ्क dir_size;
#जइ 0
    वर्ण *dirs[DIR_TABLE_SIZE];
#endif
    unsigned पूर्णाङ्क filename_size;
    संरचना /*dwarf_filename_struct*/ {
        unsigned पूर्णाङ्क dir_entry;
        वर्ण *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    पूर्णाङ्क पङ्क्तिः;
    वर्ण *filename;
    वर्ण *function;

    filename = रिक्त;
    function = रिक्त;
    func_addr = 0;
    पङ्क्तिः = 0;

    ln = rc->dwarf_पङ्क्तिः;
    जाव (ln < rc->dwarf_पङ्क्तिः_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        पङ्क्तिः = 1;
        filename = रिक्त;
        function = रिक्त;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_पङ्क्तिः_end);
	जइ (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_पङ्क्तिः_end);
	end = ln + size;
	जइ (end < ln || end > rc->dwarf_पङ्क्तिः_end)
	    भङ्ग;
	version = dwarf_read_2(ln, end);
	जइ (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	अण्णहा
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	जइ (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	अण्णहा
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	पङ्क्तिः_base = dwarf_read_1(ln, end);
	पङ्क्तिः_base |= पङ्क्तिः_base >= 0x80 ? ~0xff : 0;
	पङ्क्तिः_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	जइ (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    प्रति (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    प्रति (i = 0; i < dir_size; i++) {
		प्रति (j = 0; j < col; j++) {
		    जइ (entry_format[j].type == DW_LNCT_path) {
		        जइ (entry_format[j].form != DW_FORM_पङ्क्तिः_strp)
			    गच्छ next_पङ्क्तिः;
#जइ 0
		        मानम् = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        जइ (i < DIR_TABLE_SIZE)
		            dirs[i] = (वर्ण *)rc->dwarf_पङ्क्तिः_str + मानम्;
#अण्णहा
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    अण्णहा 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    प्रति (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    प्रति (i = 0; i < filename_size; i++)
		प्रति (j = 0; j < col; j++) {
		    जइ (entry_format[j].type == DW_LNCT_path) {
			जइ (entry_format[j].form != DW_FORM_पङ्क्तिः_strp)
			    गच्छ next_पङ्क्तिः;
			मानम् = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        जइ (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(वर्ण *)rc->dwarf_पङ्क्तिः_str + मानम्;
	            }
		    अण्णहा जइ (entry_format[j].type == DW_LNCT_directory_index) {
			विकल्प (entry_format[j].form) {
			पक्ष DW_FORM_data1: मानम् = dwarf_read_1(ln, end); भङ्ग;
			पक्ष DW_FORM_data2: मानम् = dwarf_read_2(ln, end); भङ्ग;
			पक्ष DW_FORM_data4: मानम् = dwarf_read_4(ln, end); भङ्ग;
			पक्ष DW_FORM_udata: मानम् = dwarf_read_uleb128(&ln, end); भङ्ग;
			स्वभाव: गच्छ next_पङ्क्तिः;
			}
		        जइ (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = मानम्;
		    }
		    अण्णहा 
			dwarf_ignore_type(ln, end);
	    }
	}
	अण्णहा {
	    जाव ((dwarf_read_1(ln, end))) {
#जइ 0
		जइ (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (वर्ण *)ln - 1;
#endif
		जाव (dwarf_read_1(ln, end)) {}
	    }
	    जाव ((dwarf_read_1(ln, end))) {
		जइ (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (वर्ण *)ln - 1;
		    जाव (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		अण्णहा {
		    जाव (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	जइ (filename_size >= 1)
	    filename = filename_table[0].name;
	जाव (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    जइ (i >= opcode_base) {
	        जइ (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / पङ्क्तिः_range) * min_insn_length;
		अण्णहा {
		    pc += (opindex + (i - opcode_base) / पङ्क्तिः_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / पङ्क्तिः_range) %
			       max_ops_per_insn;
		}
		i = (पूर्णाङ्क)((i - opcode_base) % पङ्क्तिः_range) + पङ्क्तिः_base;
check_pc:
		जइ (pc >= wanted_pc && wanted_pc >= last_pc)
		    गच्छ found;
		पङ्क्तिः += i;
	    }
	    अण्णहा {
	        विकल्प (i) {
	        पक्ष 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    जइ (len == 0)
		        गच्छ next_पङ्क्तिः;
		    विकल्प (dwarf_read_1(cp, end)) {
		    पक्ष DW_LNE_end_sequence:
		        भङ्ग;
		    पक्ष DW_LNE_set_address:
#जइ PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#अण्णहा
		        pc = dwarf_read_8(cp, end);
#endif
#जइ defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        भङ्ग;
		    पक्ष DW_LNE_define_file: /* deprecated */
		        जइ (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (वर्ण *)ln - 1;
		            जाव (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        अण्णहा {
		            जाव (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        भङ्ग;
		    पक्ष DW_LNE_hi_user - 1:
		        function = (वर्ण *)cp;
		        func_addr = pc;
		        भङ्ग;
		    स्वभाव:
		        भङ्ग;
		    }
		    भङ्ग;
	        पक्ष DW_LNS_advance_pc:
		    जइ (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    अण्णहा {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    गच्छ check_pc;
	        पक्ष DW_LNS_advance_पङ्क्तिः:
		    पङ्क्तिः += dwarf_read_sleb128(&ln, end);
		    भङ्ग;
	        पक्ष DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    जइ (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    भङ्ग;
	        पक्ष DW_LNS_const_add_pc:
		    जइ (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / पङ्क्तिः_range) * min_insn_length;
		    अण्णहा {
		        unsigned पूर्णाङ्क off = (255 - opcode_base) / पङ्क्तिः_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    गच्छ check_pc;
	        पक्ष DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    गच्छ check_pc;
	        स्वभाव:
		    प्रति (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    भङ्ग;
		}
	    }
	}
next_पङ्क्तिः:
	ln = end;
    }
    filename = function = रिक्त, func_addr = 0;
found:
    जइ (filename)
        pstrcpy(bi->file, परिमाण bi->file, filename), bi->पङ्क्तिः = पङ्क्तिः;
    जइ (function)
        pstrcpy(bi->func, परिमाण bi->func, function);
    bi->func_pc = func_addr;
    प्रत्यागम (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
स्थिर
#endif
पूर्णाङ्क _tcc_backtrace(rt_frame *f, ध्रुव वर्ण *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    वर्ण skip[40], सन्देशः[200];
    पूर्णाङ्क i, level, ret, n, one;
    ध्रुव वर्ण *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    जइ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    जइ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(सन्देशः, परिमाण सन्देशः, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    जइ (rc) {
        जइ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        जइ (rc->अङ्कः_callers)
            n = rc->अङ्कः_callers;
    }

    प्रति (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        जइ (ret == -1)
            भङ्ग;
        memset(&bi, 0, परिमाण bi);
        प्रति (rc2 = rc; rc2; rc2 = rc2->next) {
            जइ (getinfo(rc2, pc, &bi))
                भङ्ग;
            /* we try symtab symbols (no line number info) */
            जइ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, परिमाण bi.func, a);
                भङ्ग;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        जइ (skip[0] && strstr(bi.file, skip))
            अनुवर्त;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            जइ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (शून्य*)pc,
                    bi.file[0] ? bi.file : रिक्त,
                    bi.पङ्क्तिः,
                    bi.func[0] ? bi.func : रिक्त,
                    level == 0 ? सन्देशः : रिक्त
                    );
                जइ (ret == 0)
                    भङ्ग;
                गच्छ check_break;
            }
        }
#endif
        जइ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.पङ्क्तिः);
        } अण्णहा {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        जइ (level == 0) {
            rt_printf(": %s", सन्देशः);
            जइ (one)
                भङ्ग;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        जइ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->शिखरम्_func)
            भङ्ग;
        ++level;
    }
    rt_post_sem();
    प्रत्यागम 0;
}

/* emit a run time error at position 'pc' */
स्थिर पूर्णाङ्क rt_error(rt_frame *f, ध्रुव वर्ण *fmt, ...)
{
    va_list ap; वर्ण सन्देशः[200]; पूर्णाङ्क ret;
    va_start(ap, fmt);
    snprintf(सन्देशः, परिमाण सन्देशः, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, सन्देशः, ap);
    va_end(ap);
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#अण्णहा
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
स्थिर शून्य rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#जइ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#नोचेद्यदि defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#नोचेद्यदि defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#नोचेद्यदि defined __i386__
# जइ defined(__APPLE__)
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
# अण्णहा
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#नोचेद्यदि defined(__x86_64__)
# जइ defined(__APPLE__)
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
# अण्णहा
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#नोचेद्यदि defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#नोचेद्यदि defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#नोचेद्यदि defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#नोचेद्यदि defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#नोचेद्यदि defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#नोचेद्यदि defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#नोचेद्यदि defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#नोचेद्यदि defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#नोचेद्यदि defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#नोचेद्यदि defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#नोचेद्यदि defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
स्थिर शून्य sig_error(पूर्णाङ्क signum, siginfo_t *siginf, शून्य *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    विकल्प(signum) {
    पक्ष SIGFPE:
        विकल्प(siginf->si_code) {
        पक्ष FPE_INTDIV:
        पक्ष FPE_FLTDIV:
            rt_error(&f, "division by zero");
            भङ्ग;
        स्वभाव:
            rt_error(&f, "floating point exception");
            भङ्ग;
        }
        भङ्ग;
    पक्ष SIGBUS:
    पक्ष SIGSEGV:
        rt_error(&f, "invalid memory access");
        भङ्ग;
    पक्ष SIGILL:
        rt_error(&f, "illegal instruction");
        भङ्ग;
    पक्ष SIGABRT:
        rt_error(&f, "abort() called");
        भङ्ग;
    स्वभाव:
        rt_error(&f, "caught signal %d", signum);
        भङ्ग;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, रिक्त);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
स्थिर शून्य set_exception_handler(शून्य)
{
    संरचना sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#जइ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, रिक्त);
    sigaction(SIGILL, &sigact, रिक्त);
    sigaction(SIGSEGV, &sigact, रिक्त);
    sigaction(SIGBUS, &sigact, रिक्त);
    sigaction(SIGABRT, &sigact, रिक्त);
#जइ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        स्थिर unsigned वर्ण राशिः[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = राशिः;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, रिक्त);
    }
#endif
}

#अण्णहा /* WIN32 */

/* signal handler for fatal errors */
स्थिर long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    विकल्प (code = ex_info->ExceptionRecord->ExceptionCode) {
    पक्ष EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        भङ्ग;
    पक्ष EXCEPTION_राशिः_OVERFLOW:
        rt_error(&f, "stack overflow");
        भङ्ग;
    पक्ष EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        भङ्ग;
    पक्ष EXCEPTION_BREAKPOINT:
    पक्ष EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        प्रत्यागम EXCEPTION_CONTINUE_अन्वेषणम्;
    स्वभाव:
        rt_error(&f, "caught exception %08x", code);
        भङ्ग;
    }
    rt_exit(&f, 255);
    प्रत्यागम EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
स्थिर शून्य set_exception_handler(शून्य)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#अण्णहा
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#जइ defined(__i386__) || defined(__x86_64__)
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    जइ (level == 0) {
        *paddr = rc->ip;
    } अण्णहा {
        addr_t fp = rc->fp;
        जाव (1) {
            जइ (fp < 0x1000)
                प्रत्यागम -1;
            जइ (0 == --level)
                भङ्ग;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    प्रत्यागम 0;
}

/* XXX: only supports linux/bsd */
#नोचेद्यदि defined(__arm__) && !defined(_WIN32)
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    जइ (level == 0) {
        *paddr = rc->ip;
    } अण्णहा {
        addr_t fp = rc->fp;
        जाव (1) {
            जइ (fp < 0x1000)
                प्रत्यागम -1;
            जइ (0 == --level)
                भङ्ग;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    प्रत्यागम 0;
}

#नोचेद्यदि defined(__aarch64__)
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    जइ (level == 0) {
        *paddr = rc->ip;
    } अण्णहा {
        addr_t fp = rc->fp;
        जाव (1) {
            जइ (fp < 0x1000)
                प्रत्यागम -1;
            जइ (0 == --level)
                भङ्ग;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    प्रत्यागम 0;
}

#नोचेद्यदि defined(__riscv)
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    जइ (level == 0) {
        *paddr = rc->ip;
    } अण्णहा {
        addr_t fp = rc->fp;
        जाव (1) {
            जइ (fp < 0x1000)
                प्रत्यागम -1;
            जइ (0 == --level)
                भङ्ग;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    प्रत्यागम 0;
}

#अण्णहा
#warning add arch specific rt_get_caller_pc()
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    प्रत्यागम -1;
}

#endif
#अण्णहा // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णाङ्क level)
{
    जइ (level)
        प्रत्यागम -1;
    *paddr = f->ip;
    प्रत्यागम 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC शून्य *dlopen(ध्रुव वर्ण *filename, पूर्णाङ्क flag)
{
    प्रत्यागम रिक्त;
}

ST_FUNC शून्य dlclose(शून्य *p)
{
}

ST_FUNC ध्रुव वर्ण *dlerror(शून्य)
{
    प्रत्यागम "error";
}

प्रकारनिर्देश संरचना TCCSyms {
    वर्ण *str;
    शून्य *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
स्थिर TCCSyms tcc_syms[] = {
#जइ !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { रिक्त, रिक्त },
};

ST_FUNC शून्य *dlsym(शून्य *handle, ध्रुव वर्ण *चिह्नम्)
{
    TCCSyms *p;
    p = tcc_syms;
    जाव (p->str != रिक्त) {
        जइ (!strcmp(p->str, चिह्नम्))
            प्रत्यागम p->ptr;
        p++;
    }
    प्रत्यागम रिक्त;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
