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

#அந்தர்பாவ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
வகைவரை கட்டமைப்பு rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    ஒன்றிப்பு {
	கட்டமைப்பு {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    எழுத்து *stab_str;
	};
	கட்டமைப்பு {
	    unsigned எழுத்து *dwarf_வரி;
	    unsigned எழுத்து *dwarf_வரி_end;
	    unsigned எழுத்து *dwarf_வரி_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    எழுத்து *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    வெறுமை *bounds_start;
    வெறுமை *உச்சி_func;
    கட்டமைப்பு rt_context *next;
    // 10 * PTR_SIZE
    முழு இலக்கம்_callers;
    முழு dwarf;
} rt_context;

/* linked list of rt_contexts */
நிலையான rt_context *g_rc;
நிலையான முழு signal_set;
நிலையான வெறுமை set_exception_handler(வெறுமை);
#endif /* def CONFIG_TCC_BACKTRACE */

வகைவரை கட்டமைப்பு rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

நிலையான TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(நிலையான rt_sem);
நிலையான வெறுமை rt_wait_sem(வெறுமை) { WAIT_SEM(&rt_sem); }
நிலையான வெறுமை rt_post_sem(வெறுமை) { POST_SEM(&rt_sem); }
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *f, முழு level);
நிலையான வெறுமை rt_exit(rt_frame *f, முழு code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

நிலையான முழு protect_pages(வெறுமை *ptr, unsigned long length, முழு mode);
நிலையான முழு tcc_relocate_ex(TCCState *s1, வெறுமை *ptr, unsigned ptr_diff);
நிலையான வெறுமை st_link(TCCState *s1);
நிலையான வெறுமை st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
நிலையான முழு _tcc_backtrace(rt_frame *f, மாறிலி எழுத்து *fmt, va_list ap);
#endif
#ifdef _WIN64
நிலையான வெறுமை *win64_add_function_table(TCCState *s1);
நிலையான வெறுமை win64_del_function_table(வெறுமை *);
#endif

#எனில் !defined PAGESIZE
# எனில் defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# இல்லையெனில்
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#எனில் !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#எனில் defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

நிலையான முழு rt_mem(TCCState *s1, முழு size)
{
    வெறுமை *ptr;
    முழு ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    வெறுமை *prw;
    எழுத்து tmpfname[] = "/tmp/.tccrunXXXXXX";
    முழு fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(வெற்று, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((எழுத்து*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    எனில் (ptr == MAP_FAILED || prw == MAP_FAILED)
	திரும்பு tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (எழுத்து*)prw - (எழுத்து*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#அல்லதெனில் CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(வெற்று, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    எனில் (!ptr)
        திரும்பு tcc_error_noabort("tccrun: could not allocate memory");
#இல்லையெனில்
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    திரும்பு ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI முழு tcc_relocate(TCCState *s1)
{
    முழு size, ret, ptr_diff;

    எனில் (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    எனில் (s1->do_backtrace)
        tcc_add_குறியீடு(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, வெற்று, 0);
    எனில் (size < 0)
        திரும்பு -1;
    ptr_diff = rt_mem(s1, size);
    எனில் (ptr_diff < 0)
        திரும்பு -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    எனில் (ret == 0)
        st_link(s1);
    திரும்பு ret;
}

ST_FUNC வெறுமை tcc_run_free(TCCState *s1)
{
    unsigned size;
    வெறுமை *ptr;
    முழு i;

    /* free any loaded DLLs */
    க்கு ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        எனில் ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#இல்லையெனில்
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    எனில் (வெற்று == ptr)
        திரும்பு;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#அல்லதெனில் CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#இல்லையெனில்
    /* unprotect memory to make it usable for malloc again */
    protect_pages((வெறுமை*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI முழு tcc_run(TCCState *s1, முழு argc, எழுத்து **argv)
{
    முழு (*prog_main)(முழு, எழுத்து **, எழுத்து **), ret;
    மாறிலி எழுத்து *உச்சி_sym;
    jmp_buf main_jb;

#எனில் defined(__APPLE__)
    வெளி எழுத்து ***_NSGetEnviron(வெறுமை);
    எழுத்து **envp = *_NSGetEnviron();
#அல்லதெனில் defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    வெளி எழுத்து **environ;
    எழுத்து **envp = environ;
#இல்லையெனில்
    எழுத்து **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    எனில் ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        திரும்பு 0;

    tcc_add_குறியீடு(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", உச்சி_sym = "main";
    எனில் (s1->elf_entryname)
        s1->run_main = உச்சி_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    எனில் (tcc_relocate(s1) < 0)
        திரும்பு -1;

    prog_main = (வெறுமை*)get_sym_addr(s1, s1->run_main, 1, 1);
    எனில் ((addr_t)-1 == (addr_t)prog_main)
        திரும்பு -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    எனில் (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        திரும்பு -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_குறியீடு(s1, உச்சி_sym));
    எனில் (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } இல்லையெனில் எனில் (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    எனில் (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    திரும்பு ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
நிலையான வெறுமை cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    முழு sym_index, end_sym = s->data_offset / அளவு (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    க்கு (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        மாறிலி எழுத்து *name = (எழுத்து *)s->link->data + sym->st_name;
        எனில் (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            தொடர்;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_மதிப்பு, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
நிலையான வெறுமை cleanup_sections(TCCState *s1)
{
    கட்டமைப்பு { Section **secs; முழு nb_secs; } *p = (வெறுமை*)&s1->sections;
    முழு i, f = 2;
    செய் {
        க்கு (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            எனில் (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } இல்லையெனில் {
                free_section(s), tcc_free(s), p->secs[i] = வெற்று;
            }
        }
    } போது (++p, f);
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
# இல்லையெனில்
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
நிலையான முழு tcc_relocate_ex(TCCState *s1, வெறுமை *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    எனில் (வெற்று == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, வெற்று);
#இல்லையெனில்
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    எனில் (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    எனில் (s1->nb_errors)
        திரும்பு -1;
    எனில் (copy == 3)
        திரும்பு 0;

    க்கு (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        க்கு(i = 1; i < s1->nb_sections; i++) {
            நிலையான மாறிலி எழுத்து shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            எனில் (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                தொடர்;
            length = s->data_offset;
            எனில் (copy == 2) {
                எனில் (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                தொடர்;
            }
            எனில் (copy) { /* final step: copy section data to memory */
                எனில் (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (வெறுமை*)s->sh_addr, length, s->sh_addralign);
                ptr = (வெறுமை*)s->sh_addr;
                எனில் (k == 0)
                    ptr = (வெறுமை*)(s->sh_addr + ptr_diff);
                எனில் (வெற்று == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                இல்லையெனில்
                    memcpy(ptr, s->data, length);
                தொடர்;
            }

            எனில் ((s->sh_flags & SHF_TLS) && length)
                திரும்பு tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            எனில் (++n == 1) {
#எனில் defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                எனில் (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                எனில் (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        எனில் (copy == 2) { /* set permissions */
            எனில் (n == 0) /* no data  */
                தொடர்;
#ifdef CONFIG_SELINUX
            எனில் (k == 0) /* SHF_EXECINSTR has its own mapping */
                தொடர்;
#endif
            f = k;
            எனில் (f >= CONFIG_RUNMEM_RO) {
                எனில் (f != 0)
                    தொடர்;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            எனில் (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (வெறுமை*)addr, (unsigned)n);
            }
            எனில் (protect_pages((வெறுமை*)addr, n, f) < 0)
                திரும்பு tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#இல்லையெனில்
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    எனில் (0 == mem)
        திரும்பு PAGEALIGN(offset);

    எனில் (++copy == 2) {
        செல் redo;
    }
    எனில் (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        செல் redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    எனில் (s1->nb_errors)
        செல் redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#இல்லையெனில்
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    செல் redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

நிலையான முழு protect_pages(வெறுமை *ptr, unsigned long length, முழு mode)
{
#ifdef _WIN32
    நிலையான மாறிலி unsigned எழுத்து protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    எனில் (!VirtualProtect(ptr, length, protect[mode], &old))
        திரும்பு -1;
#இல்லையெனில்
    நிலையான மாறிலி unsigned எழுத்து protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    எனில் (mprotect(ptr, length, protect[mode]))
        திரும்பு -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#எனில் (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    எனில் (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#இல்லையெனில்
        வெறுமை __clear_cache(வெறுமை *beginning, வெறுமை *end);
        __clear_cache(ptr, (எழுத்து *)ptr + length);
#endif
    }
#endif
    திரும்பு 0;
}

#ifdef _WIN64
நிலையான வெறுமை *win64_add_function_table(TCCState *s1)
{
    வெறுமை *p = வெற்று;
    எனில் (s1->uw_pdata) {
        p = (வெறுமை*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / அளவு (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = வெற்று;
    }
    திரும்பு p;
}

நிலையான வெறுமை win64_del_function_table(வெறுமை *p)
{
    எனில் (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

நிலையான வெறுமை bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    எனில் (!s1->do_backtrace)
        திரும்பு;
    rc = tcc_get_குறியீடு(s1, "__rt_info");
    எனில் (!rc)
        திரும்பு;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (எழுத்து *)symtab_section->link->data;
    எனில் (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    எனில் (s1->do_bounds_check) {
        வெறுமை *p;
        எனில் ((p = tcc_get_குறியீடு(s1, "__bound_init")))
            ((வெறுமை(*)(வெறுமை*,முழு))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    எனில் (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

நிலையான வெறுமை st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
நிலையான வெறுமை ptr_unlink(வெறுமை *list, வெறுமை *e, unsigned next)
{
    வெறுமை **pp, **nn, *p;
    க்கு (pp = list; !!(p = *pp); pp = nn) {
        nn = (வெறுமை*)((எழுத்து*)p + next); /* nn = &p->next; */
        எனில் (p == e) {
            *pp = *nn;
            நிறுத்து;
        }
    }
}

நிலையான வெறுமை st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI வெறுமை *_tcc_setjmp(TCCState *s1, வெறுமை *p_jmp_buf, வெறுமை *func, வெறுமை *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    எனில் (s1->rc)
        s1->rc->உச்சி_func = func;
#endif
    திரும்பு p_jmp_buf;
}

LIBTCCAPI வெறுமை tcc_set_backtrace_func(TCCState *s1, வெறுமை *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

நிலையான TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    முழு level;
    addr_t pc;

    s = g_s1;
    எனில் (வெற்று == s || வெற்று == s->next) {
        /* play it safe in the simple case when there is only one state */
        திரும்பு s;
    }
    க்கு (level = 0; level < 8; ++level) {
        எனில் (rt_get_caller_pc(&pc, f, level) < 0)
            நிறுத்து;
        க்கு (s = g_s1; s; s = s->next) {
            எனில் (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                திரும்பு s;
        }
    }
    திரும்பு வெற்று;
}

நிலையான வெறுமை rt_exit(rt_frame *f, முழு code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    எனில் (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        எனில் (f->fp) { /* called from signal */
            வெறுமை *p = tcc_get_குறியீடு(s, "__bound_exit");
            எனில் (p)
                ((வெறுமை (*)(வெறுமை))p)();
        }
#endif
        எனில் (code == 0)
            code = RT_EXIT_ZERO;
        ((வெறுமை(*)(வெறுமை*,முழு))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#இல்லையெனில் // if defined CONFIG_TCC_BACKTRACE_ONLY
நிலையான வெறுமை rt_exit(rt_frame *f, முழு code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

நிலையான முழு rt_vprintf(மாறிலி எழுத்து *fmt, va_list ap)
{
    முழு ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    திரும்பு ret;
}

நிலையான முழு rt_printf(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap;
    முழு r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    திரும்பு r;
}

நிலையான எழுத்து *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    க்கு (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        முழு type = ELFW(ST_TYPE)(esym->st_info);
        எனில் ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_மதிப்பு
            && wanted_pc < esym->st_மதிப்பு + esym->st_size) {
            *func_addr = esym->st_மதிப்பு;
            திரும்பு rc->elf_str + esym->st_name;
        }
    }
    திரும்பு வெற்று;
}

வகைவரை கட்டமைப்பு bt_info
{
    எழுத்து file[100];
    முழு வரி;
    எழுத்து func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
நிலையான addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    எழுத்து func_name[128];
    addr_t func_addr, last_pc, pc;
    மாறிலி எழுத்து *incl_files[INCLUDE_அடுக்கு_SIZE];
    முழு incl_index, last_incl_index, len, last_வரி_இலக்கம், i;
    மாறிலி எழுத்து *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_வரி_இலக்கம் = 1;
    last_incl_index = 0;

    க்கு (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_மதிப்பு;

        தேர்வு(sym->n_type) {
        நிலை N_SLINE:
            எனில் (func_addr)
                செல் rel_pc;
        நிலை N_SO:
        நிலை N_SOL:
            செல் abs_pc;
        நிலை N_FUN:
            எனில் (sym->n_strx == 0) /* end of function */
                செல் rel_pc;
        abs_pc:
#எனில் PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            செல் check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            எனில் (pc >= wanted_pc && wanted_pc >= last_pc)
                செல் found;
            நிறுத்து;
        }

        தேர்வு(sym->n_type) {
            /* function start or end */
        நிலை N_FUN:
            எனில் (sym->n_strx == 0)
                செல் reset_func;
            p = strchr(str, ':');
            எனில் (0 == p || (len = p - str + 1, len > அளவு func_name))
                len = அளவு func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            நிறுத்து;
            /* line number info */
        நிலை N_SLINE:
            last_pc = pc;
            last_வரி_இலக்கம் = sym->n_desc;
            last_incl_index = incl_index;
            நிறுத்து;
            /* include files */
        நிலை N_BINCL:
            எனில் (incl_index < INCLUDE_அடுக்கு_SIZE)
                incl_files[incl_index++] = str;
            நிறுத்து;
        நிலை N_EINCL:
            எனில் (incl_index > 1)
                incl_index--;
            நிறுத்து;
            /* start/end of translation unit */
        நிலை N_SO:
            incl_index = 0;
            எனில் (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                எனில் (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            நிறுத்து;
            /* alternative file name (from #line or #include directives) */
        நிலை N_SOL:
            எனில் (incl_index)
                incl_files[incl_index-1] = str;
            நிறுத்து;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    எனில் (i > 0) {
        pstrcpy(bi->file, அளவு bi->file, incl_files[--i]);
        bi->வரி = last_வரி_இலக்கம்;
    }
    pstrcpy(bi->func, அளவு bi->func, func_name);
    bi->func_pc = func_addr;
    திரும்பு func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	தேர்வு (entry_format[j].form) { \
	நிலை DW_FORM_data1: (ln) += 1; நிறுத்து; \
	நிலை DW_FORM_data2: (ln) += 2; நிறுத்து; \
	நிலை DW_FORM_data4: (ln) += 3; நிறுத்து; \
	நிலை DW_FORM_data8: (ln) += 8; நிறுத்து; \
	நிலை DW_FORM_data16: (ln) += 16; நிறுத்து; \
	நிலை DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); நிறுத்து; \
	இயல்பு: செல் next_வரி; \
	}

நிலையான addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned எழுத்து *ln;
    unsigned எழுத்து *cp;
    unsigned எழுத்து *end;
    unsigned எழுத்து *opcode_length;
    unsigned long long size;
    unsigned முழு length;
    unsigned எழுத்து version;
    unsigned முழு min_insn_length;
    unsigned முழு max_ops_per_insn;
    முழு வரி_base;
    unsigned முழு வரி_range;
    unsigned முழு opcode_base;
    unsigned முழு opindex;
    unsigned முழு col;
    unsigned முழு i;
    unsigned முழு j;
    unsigned முழு len;
    unsigned long long மதிப்பு;
    கட்டமைப்பு {
	unsigned முழு type;
	unsigned முழு form;
    } entry_format[256];
    unsigned முழு dir_size;
#எனில் 0
    எழுத்து *dirs[DIR_TABLE_SIZE];
#endif
    unsigned முழு filename_size;
    கட்டமைப்பு /*dwarf_filename_struct*/ {
        unsigned முழு dir_entry;
        எழுத்து *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    முழு வரி;
    எழுத்து *filename;
    எழுத்து *function;

    filename = வெற்று;
    function = வெற்று;
    func_addr = 0;
    வரி = 0;

    ln = rc->dwarf_வரி;
    போது (ln < rc->dwarf_வரி_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        வரி = 1;
        filename = வெற்று;
        function = வெற்று;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_வரி_end);
	எனில் (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_வரி_end);
	end = ln + size;
	எனில் (end < ln || end > rc->dwarf_வரி_end)
	    நிறுத்து;
	version = dwarf_read_2(ln, end);
	எனில் (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	இல்லையெனில்
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	எனில் (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	இல்லையெனில்
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	வரி_base = dwarf_read_1(ln, end);
	வரி_base |= வரி_base >= 0x80 ? ~0xff : 0;
	வரி_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	எனில் (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    க்கு (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    க்கு (i = 0; i < dir_size; i++) {
		க்கு (j = 0; j < col; j++) {
		    எனில் (entry_format[j].type == DW_LNCT_path) {
		        எனில் (entry_format[j].form != DW_FORM_வரி_strp)
			    செல் next_வரி;
#எனில் 0
		        மதிப்பு = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        எனில் (i < DIR_TABLE_SIZE)
		            dirs[i] = (எழுத்து *)rc->dwarf_வரி_str + மதிப்பு;
#இல்லையெனில்
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    இல்லையெனில் 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    க்கு (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    க்கு (i = 0; i < filename_size; i++)
		க்கு (j = 0; j < col; j++) {
		    எனில் (entry_format[j].type == DW_LNCT_path) {
			எனில் (entry_format[j].form != DW_FORM_வரி_strp)
			    செல் next_வரி;
			மதிப்பு = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        எனில் (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(எழுத்து *)rc->dwarf_வரி_str + மதிப்பு;
	            }
		    இல்லையெனில் எனில் (entry_format[j].type == DW_LNCT_directory_index) {
			தேர்வு (entry_format[j].form) {
			நிலை DW_FORM_data1: மதிப்பு = dwarf_read_1(ln, end); நிறுத்து;
			நிலை DW_FORM_data2: மதிப்பு = dwarf_read_2(ln, end); நிறுத்து;
			நிலை DW_FORM_data4: மதிப்பு = dwarf_read_4(ln, end); நிறுத்து;
			நிலை DW_FORM_udata: மதிப்பு = dwarf_read_uleb128(&ln, end); நிறுத்து;
			இயல்பு: செல் next_வரி;
			}
		        எனில் (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = மதிப்பு;
		    }
		    இல்லையெனில் 
			dwarf_ignore_type(ln, end);
	    }
	}
	இல்லையெனில் {
	    போது ((dwarf_read_1(ln, end))) {
#எனில் 0
		எனில் (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (எழுத்து *)ln - 1;
#endif
		போது (dwarf_read_1(ln, end)) {}
	    }
	    போது ((dwarf_read_1(ln, end))) {
		எனில் (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (எழுத்து *)ln - 1;
		    போது (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		இல்லையெனில் {
		    போது (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	எனில் (filename_size >= 1)
	    filename = filename_table[0].name;
	போது (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    எனில் (i >= opcode_base) {
	        எனில் (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / வரி_range) * min_insn_length;
		இல்லையெனில் {
		    pc += (opindex + (i - opcode_base) / வரி_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / வரி_range) %
			       max_ops_per_insn;
		}
		i = (முழு)((i - opcode_base) % வரி_range) + வரி_base;
check_pc:
		எனில் (pc >= wanted_pc && wanted_pc >= last_pc)
		    செல் found;
		வரி += i;
	    }
	    இல்லையெனில் {
	        தேர்வு (i) {
	        நிலை 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    எனில் (len == 0)
		        செல் next_வரி;
		    தேர்வு (dwarf_read_1(cp, end)) {
		    நிலை DW_LNE_end_sequence:
		        நிறுத்து;
		    நிலை DW_LNE_set_address:
#எனில் PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#இல்லையெனில்
		        pc = dwarf_read_8(cp, end);
#endif
#எனில் defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        நிறுத்து;
		    நிலை DW_LNE_define_file: /* deprecated */
		        எனில் (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (எழுத்து *)ln - 1;
		            போது (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        இல்லையெனில் {
		            போது (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        நிறுத்து;
		    நிலை DW_LNE_hi_user - 1:
		        function = (எழுத்து *)cp;
		        func_addr = pc;
		        நிறுத்து;
		    இயல்பு:
		        நிறுத்து;
		    }
		    நிறுத்து;
	        நிலை DW_LNS_advance_pc:
		    எனில் (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    இல்லையெனில் {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    செல் check_pc;
	        நிலை DW_LNS_advance_வரி:
		    வரி += dwarf_read_sleb128(&ln, end);
		    நிறுத்து;
	        நிலை DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    எனில் (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    நிறுத்து;
	        நிலை DW_LNS_const_add_pc:
		    எனில் (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / வரி_range) * min_insn_length;
		    இல்லையெனில் {
		        unsigned முழு off = (255 - opcode_base) / வரி_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    செல் check_pc;
	        நிலை DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    செல் check_pc;
	        இயல்பு:
		    க்கு (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    நிறுத்து;
		}
	    }
	}
next_வரி:
	ln = end;
    }
    filename = function = வெற்று, func_addr = 0;
found:
    எனில் (filename)
        pstrcpy(bi->file, அளவு bi->file, filename), bi->வரி = வரி;
    எனில் (function)
        pstrcpy(bi->func, அளவு bi->func, function);
    bi->func_pc = func_addr;
    திரும்பு (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
நிலையான
#endif
முழு _tcc_backtrace(rt_frame *f, மாறிலி எழுத்து *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    எழுத்து skip[40], செய்தி[200];
    முழு i, level, ret, n, one;
    மாறிலி எழுத்து *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    எனில் (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    எனில் (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(செய்தி, அளவு செய்தி, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    எனில் (rc) {
        எனில் (rc->dwarf)
            getinfo = rt_printline_dwarf;
        எனில் (rc->இலக்கம்_callers)
            n = rc->இலக்கம்_callers;
    }

    க்கு (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        எனில் (ret == -1)
            நிறுத்து;
        memset(&bi, 0, அளவு bi);
        க்கு (rc2 = rc; rc2; rc2 = rc2->next) {
            எனில் (getinfo(rc2, pc, &bi))
                நிறுத்து;
            /* we try symtab symbols (no line number info) */
            எனில் (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, அளவு bi.func, a);
                நிறுத்து;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        எனில் (skip[0] && strstr(bi.file, skip))
            தொடர்;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            எனில் (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (வெறுமை*)pc,
                    bi.file[0] ? bi.file : வெற்று,
                    bi.வரி,
                    bi.func[0] ? bi.func : வெற்று,
                    level == 0 ? செய்தி : வெற்று
                    );
                எனில் (ret == 0)
                    நிறுத்து;
                செல் check_break;
            }
        }
#endif
        எனில் (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.வரி);
        } இல்லையெனில் {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        எனில் (level == 0) {
            rt_printf(": %s", செய்தி);
            எனில் (one)
                நிறுத்து;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        எனில் (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->உச்சி_func)
            நிறுத்து;
        ++level;
    }
    rt_post_sem();
    திரும்பு 0;
}

/* emit a run time error at position 'pc' */
நிலையான முழு rt_error(rt_frame *f, மாறிலி எழுத்து *fmt, ...)
{
    va_list ap; எழுத்து செய்தி[200]; முழு ret;
    va_start(ap, fmt);
    snprintf(செய்தி, அளவு செய்தி, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, செய்தி, ap);
    va_end(ap);
    திரும்பு ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#இல்லையெனில்
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
நிலையான வெறுமை rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#எனில் defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#அல்லதெனில் defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#அல்லதெனில் defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#அல்லதெனில் defined __i386__
# எனில் defined(__APPLE__)
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
# இல்லையெனில்
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#அல்லதெனில் defined(__x86_64__)
# எனில் defined(__APPLE__)
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
# இல்லையெனில்
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#அல்லதெனில் defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#அல்லதெனில் defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#அல்லதெனில் defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#அல்லதெனில் defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#அல்லதெனில் defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#அல்லதெனில் defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#அல்லதெனில் defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#அல்லதெனில் defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#அல்லதெனில் defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#அல்லதெனில் defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#அல்லதெனில் defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
நிலையான வெறுமை sig_error(முழு signum, siginfo_t *siginf, வெறுமை *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    தேர்வு(signum) {
    நிலை SIGFPE:
        தேர்வு(siginf->si_code) {
        நிலை FPE_INTDIV:
        நிலை FPE_FLTDIV:
            rt_error(&f, "division by zero");
            நிறுத்து;
        இயல்பு:
            rt_error(&f, "floating point exception");
            நிறுத்து;
        }
        நிறுத்து;
    நிலை SIGBUS:
    நிலை SIGSEGV:
        rt_error(&f, "invalid memory access");
        நிறுத்து;
    நிலை SIGILL:
        rt_error(&f, "illegal instruction");
        நிறுத்து;
    நிலை SIGABRT:
        rt_error(&f, "abort() called");
        நிறுத்து;
    இயல்பு:
        rt_error(&f, "caught signal %d", signum);
        நிறுத்து;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, வெற்று);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
நிலையான வெறுமை set_exception_handler(வெறுமை)
{
    கட்டமைப்பு sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#எனில் 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, வெற்று);
    sigaction(SIGILL, &sigact, வெற்று);
    sigaction(SIGSEGV, &sigact, வெற்று);
    sigaction(SIGBUS, &sigact, வெற்று);
    sigaction(SIGABRT, &sigact, வெற்று);
#எனில் 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        நிலையான unsigned எழுத்து அடுக்கு[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = அடுக்கு;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, வெற்று);
    }
#endif
}

#இல்லையெனில் /* WIN32 */

/* signal handler for fatal errors */
நிலையான long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    தேர்வு (code = ex_info->ExceptionRecord->ExceptionCode) {
    நிலை EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        நிறுத்து;
    நிலை EXCEPTION_அடுக்கு_OVERFLOW:
        rt_error(&f, "stack overflow");
        நிறுத்து;
    நிலை EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        நிறுத்து;
    நிலை EXCEPTION_BREAKPOINT:
    நிலை EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        திரும்பு EXCEPTION_CONTINUE_தேடல்;
    இயல்பு:
        rt_error(&f, "caught exception %08x", code);
        நிறுத்து;
    }
    rt_exit(&f, 255);
    திரும்பு EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
நிலையான வெறுமை set_exception_handler(வெறுமை)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#இல்லையெனில்
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#எனில் defined(__i386__) || defined(__x86_64__)
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *rc, முழு level)
{
    எனில் (level == 0) {
        *paddr = rc->ip;
    } இல்லையெனில் {
        addr_t fp = rc->fp;
        போது (1) {
            எனில் (fp < 0x1000)
                திரும்பு -1;
            எனில் (0 == --level)
                நிறுத்து;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    திரும்பு 0;
}

/* XXX: only supports linux/bsd */
#அல்லதெனில் defined(__arm__) && !defined(_WIN32)
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *rc, முழு level)
{
    எனில் (level == 0) {
        *paddr = rc->ip;
    } இல்லையெனில் {
        addr_t fp = rc->fp;
        போது (1) {
            எனில் (fp < 0x1000)
                திரும்பு -1;
            எனில் (0 == --level)
                நிறுத்து;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    திரும்பு 0;
}

#அல்லதெனில் defined(__aarch64__)
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *rc, முழு level)
{
    எனில் (level == 0) {
        *paddr = rc->ip;
    } இல்லையெனில் {
        addr_t fp = rc->fp;
        போது (1) {
            எனில் (fp < 0x1000)
                திரும்பு -1;
            எனில் (0 == --level)
                நிறுத்து;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    திரும்பு 0;
}

#அல்லதெனில் defined(__riscv)
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *rc, முழு level)
{
    எனில் (level == 0) {
        *paddr = rc->ip;
    } இல்லையெனில் {
        addr_t fp = rc->fp;
        போது (1) {
            எனில் (fp < 0x1000)
                திரும்பு -1;
            எனில் (0 == --level)
                நிறுத்து;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    திரும்பு 0;
}

#இல்லையெனில்
#warning add arch specific rt_get_caller_pc()
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *rc, முழு level)
{
    திரும்பு -1;
}

#endif
#இல்லையெனில் // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
நிலையான முழு rt_get_caller_pc(addr_t *paddr, rt_frame *f, முழு level)
{
    எனில் (level)
        திரும்பு -1;
    *paddr = f->ip;
    திரும்பு 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC வெறுமை *dlopen(மாறிலி எழுத்து *filename, முழு flag)
{
    திரும்பு வெற்று;
}

ST_FUNC வெறுமை dlclose(வெறுமை *p)
{
}

ST_FUNC மாறிலி எழுத்து *dlerror(வெறுமை)
{
    திரும்பு "error";
}

வகைவரை கட்டமைப்பு TCCSyms {
    எழுத்து *str;
    வெறுமை *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
நிலையான TCCSyms tcc_syms[] = {
#எனில் !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { வெற்று, வெற்று },
};

ST_FUNC வெறுமை *dlsym(வெறுமை *handle, மாறிலி எழுத்து *குறியீடு)
{
    TCCSyms *p;
    p = tcc_syms;
    போது (p->str != வெற்று) {
        எனில் (!strcmp(p->str, குறியீடு))
            திரும்பு p->ptr;
        p++;
    }
    திரும்பு வெற்று;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
