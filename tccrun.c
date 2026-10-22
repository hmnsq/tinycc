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

#ಅನ್ತರ್ಭಾವ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    ಸಙ್ಘ {
	ಸಂರಚನಾ {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    ವರ್ಣ *stab_str;
	};
	ಸಂರಚನಾ {
	    unsigned ವರ್ಣ *dwarf_ಸಾಲು;
	    unsigned ವರ್ಣ *dwarf_ಸಾಲು_end;
	    unsigned ವರ್ಣ *dwarf_ಸಾಲು_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    ವರ್ಣ *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    ಶೂನ್ಯ *bounds_start;
    ಶೂನ್ಯ *ತುದಿ_func;
    ಸಂರಚನಾ rt_context *next;
    // 10 * PTR_SIZE
    ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_callers;
    ಪೂರ್ಣಾಙ್ಕ dwarf;
} rt_context;

/* linked list of rt_contexts */
ಸ್ಥಿರ rt_context *g_rc;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ signal_set;
ಸ್ಥಿರ ಶೂನ್ಯ set_exception_handler(ಶೂನ್ಯ);
#endif /* def CONFIG_TCC_BACKTRACE */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

ಸ್ಥಿರ TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ಸ್ಥಿರ rt_sem);
ಸ್ಥಿರ ಶೂನ್ಯ rt_wait_sem(ಶೂನ್ಯ) { WAIT_SEM(&rt_sem); }
ಸ್ಥಿರ ಶೂನ್ಯ rt_post_sem(ಶೂನ್ಯ) { POST_SEM(&rt_sem); }
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *f, ಪೂರ್ಣಾಙ್ಕ level);
ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_frame *f, ಪೂರ್ಣಾಙ್ಕ code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ protect_pages(ಶೂನ್ಯ *ptr, unsigned long length, ಪೂರ್ಣಾಙ್ಕ mode);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_relocate_ex(TCCState *s1, ಶೂನ್ಯ *ptr, unsigned ptr_diff);
ಸ್ಥಿರ ಶೂನ್ಯ st_link(TCCState *s1);
ಸ್ಥಿರ ಶೂನ್ಯ st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ _tcc_backtrace(rt_frame *f, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap);
#endif
#ifdef _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ *win64_add_function_table(TCCState *s1);
ಸ್ಥಿರ ಶೂನ್ಯ win64_del_function_table(ಶೂನ್ಯ *);
#endif

#ಯದಿ !defined PAGESIZE
# ಯದಿ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ಅನ್ಯಥಾ
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ಯದಿ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#ಯದಿ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_mem(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ size)
{
    ಶೂನ್ಯ *ptr;
    ಪೂರ್ಣಾಙ್ಕ ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    ಶೂನ್ಯ *prw;
    ವರ್ಣ tmpfname[] = "/tmp/.tccrunXXXXXX";
    ಪೂರ್ಣಾಙ್ಕ fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(ರಿಕ್ತ, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((ವರ್ಣ*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ಯದಿ (ptr == MAP_FAILED || prw == MAP_FAILED)
	ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (ವರ್ಣ*)prw - (ವರ್ಣ*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#ನೋಚೇದ್ಯದಿ CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ರಿಕ್ತ, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    ಯದಿ (!ptr)
        ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("tccrun: could not allocate memory");
#ಅನ್ಯಥಾ
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    ಪ್ರತ್ಯಾಗಮ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_relocate(TCCState *s1)
{
    ಪೂರ್ಣಾಙ್ಕ size, ret, ptr_diff;

    ಯದಿ (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    ಯದಿ (s1->do_backtrace)
        tcc_add_ಚಿಹ್ನೆ(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, ರಿಕ್ತ, 0);
    ಯದಿ (size < 0)
        ಪ್ರತ್ಯಾಗಮ -1;
    ptr_diff = rt_mem(s1, size);
    ಯದಿ (ptr_diff < 0)
        ಪ್ರತ್ಯಾಗಮ -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    ಯದಿ (ret == 0)
        st_link(s1);
    ಪ್ರತ್ಯಾಗಮ ret;
}

ST_FUNC ಶೂನ್ಯ tcc_run_free(TCCState *s1)
{
    unsigned size;
    ಶೂನ್ಯ *ptr;
    ಪೂರ್ಣಾಙ್ಕ i;

    /* free any loaded DLLs */
    ಪ್ರತಿ ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ಯದಿ ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ಅನ್ಯಥಾ
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    ಯದಿ (ರಿಕ್ತ == ptr)
        ಪ್ರತ್ಯಾಗಮ;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#ನೋಚೇದ್ಯದಿ CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#ಅನ್ಯಥಾ
    /* unprotect memory to make it usable for malloc again */
    protect_pages((ಶೂನ್ಯ*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI ಪೂರ್ಣಾಙ್ಕ tcc_run(TCCState *s1, ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ (*prog_main)(ಪೂರ್ಣಾಙ್ಕ, ವರ್ಣ **, ವರ್ಣ **), ret;
    ಧ್ರುವ ವರ್ಣ *ತುದಿ_sym;
    jmp_buf main_jb;

#ಯದಿ defined(__APPLE__)
    ಬಾಹ್ಯ ವರ್ಣ ***_NSGetEnviron(ಶೂನ್ಯ);
    ವರ್ಣ **envp = *_NSGetEnviron();
#ನೋಚೇದ್ಯದಿ defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    ಬಾಹ್ಯ ವರ್ಣ **environ;
    ವರ್ಣ **envp = environ;
#ಅನ್ಯಥಾ
    ವರ್ಣ **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    ಯದಿ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ಪ್ರತ್ಯಾಗಮ 0;

    tcc_add_ಚಿಹ್ನೆ(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", ತುದಿ_sym = "main";
    ಯದಿ (s1->elf_entryname)
        s1->run_main = ತುದಿ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    ಯದಿ (tcc_relocate(s1) < 0)
        ಪ್ರತ್ಯಾಗಮ -1;

    prog_main = (ಶೂನ್ಯ*)get_sym_addr(s1, s1->run_main, 1, 1);
    ಯದಿ ((addr_t)-1 == (addr_t)prog_main)
        ಪ್ರತ್ಯಾಗಮ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ಯದಿ (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ಪ್ರತ್ಯಾಗಮ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_ಚಿಹ್ನೆ(s1, ತುದಿ_sym));
    ಯದಿ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ಅನ್ಯಥಾ ಯದಿ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ಯದಿ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ಸ್ಥಿರ ಶೂನ್ಯ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    ಪೂರ್ಣಾಙ್ಕ sym_index, end_sym = s->data_offset / ಪರಿಮಾಣ (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    ಪ್ರತಿ (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ಧ್ರುವ ವರ್ಣ *name = (ವರ್ಣ *)s->link->data + sym->st_name;
        ಯದಿ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ಅನುವರ್ತ;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_ಮೌಲ್ಯ, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ಸ್ಥಿರ ಶೂನ್ಯ cleanup_sections(TCCState *s1)
{
    ಸಂರಚನಾ { Section **secs; ಪೂರ್ಣಾಙ್ಕ nb_secs; } *p = (ಶೂನ್ಯ*)&s1->sections;
    ಪೂರ್ಣಾಙ್ಕ i, f = 2;
    ಕುರು {
        ಪ್ರತಿ (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ಯದಿ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } ಅನ್ಯಥಾ {
                free_section(s), tcc_free(s), p->secs[i] = ರಿಕ್ತ;
            }
        }
    } ಯಾವತ್ (++p, f);
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
# ಅನ್ಯಥಾ
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tcc_relocate_ex(TCCState *s1, ಶೂನ್ಯ *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    ಯದಿ (ರಿಕ್ತ == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, ರಿಕ್ತ);
#ಅನ್ಯಥಾ
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    ಯದಿ (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    ಯದಿ (s1->nb_errors)
        ಪ್ರತ್ಯಾಗಮ -1;
    ಯದಿ (copy == 3)
        ಪ್ರತ್ಯಾಗಮ 0;

    ಪ್ರತಿ (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        ಪ್ರತಿ(i = 1; i < s1->nb_sections; i++) {
            ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ಯದಿ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ಅನುವರ್ತ;
            length = s->data_offset;
            ಯದಿ (copy == 2) {
                ಯದಿ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                ಅನುವರ್ತ;
            }
            ಯದಿ (copy) { /* final step: copy section data to memory */
                ಯದಿ (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (ಶೂನ್ಯ*)s->sh_addr, length, s->sh_addralign);
                ptr = (ಶೂನ್ಯ*)s->sh_addr;
                ಯದಿ (k == 0)
                    ptr = (ಶೂನ್ಯ*)(s->sh_addr + ptr_diff);
                ಯದಿ (ರಿಕ್ತ == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                ಅನ್ಯಥಾ
                    memcpy(ptr, s->data, length);
                ಅನುವರ್ತ;
            }

            ಯದಿ ((s->sh_flags & SHF_TLS) && length)
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ಯದಿ (++n == 1) {
#ಯದಿ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ಯದಿ (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                ಯದಿ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        ಯದಿ (copy == 2) { /* set permissions */
            ಯದಿ (n == 0) /* no data  */
                ಅನುವರ್ತ;
#ifdef CONFIG_SELINUX
            ಯದಿ (k == 0) /* SHF_EXECINSTR has its own mapping */
                ಅನುವರ್ತ;
#endif
            f = k;
            ಯದಿ (f >= CONFIG_RUNMEM_RO) {
                ಯದಿ (f != 0)
                    ಅನುವರ್ತ;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ಯದಿ (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (ಶೂನ್ಯ*)addr, (unsigned)n);
            }
            ಯದಿ (protect_pages((ಶೂನ್ಯ*)addr, n, f) < 0)
                ಪ್ರತ್ಯಾಗಮ tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#ಅನ್ಯಥಾ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    ಯದಿ (0 == mem)
        ಪ್ರತ್ಯಾಗಮ PAGEALIGN(offset);

    ಯದಿ (++copy == 2) {
        ಗಚ್ಛ redo;
    }
    ಯದಿ (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        ಗಚ್ಛ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ಯದಿ (s1->nb_errors)
        ಗಚ್ಛ redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#ಅನ್ಯಥಾ
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    ಗಚ್ಛ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ protect_pages(ಶೂನ್ಯ *ptr, unsigned long length, ಪೂರ್ಣಾಙ್ಕ mode)
{
#ifdef _WIN32
    ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    ಯದಿ (!VirtualProtect(ptr, length, protect[mode], &old))
        ಪ್ರತ್ಯಾಗಮ -1;
#ಅನ್ಯಥಾ
    ಸ್ಥಿರ ಧ್ರುವ unsigned ವರ್ಣ protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ಯದಿ (mprotect(ptr, length, protect[mode]))
        ಪ್ರತ್ಯಾಗಮ -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#ಯದಿ (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ಯದಿ (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#ಅನ್ಯಥಾ
        ಶೂನ್ಯ __clear_cache(ಶೂನ್ಯ *beginning, ಶೂನ್ಯ *end);
        __clear_cache(ptr, (ವರ್ಣ *)ptr + length);
#endif
    }
#endif
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ifdef _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ *win64_add_function_table(TCCState *s1)
{
    ಶೂನ್ಯ *p = ರಿಕ್ತ;
    ಯದಿ (s1->uw_pdata) {
        p = (ಶೂನ್ಯ*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / ಪರಿಮಾಣ (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ರಿಕ್ತ;
    }
    ಪ್ರತ್ಯಾಗಮ p;
}

ಸ್ಥಿರ ಶೂನ್ಯ win64_del_function_table(ಶೂನ್ಯ *p)
{
    ಯದಿ (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

ಸ್ಥಿರ ಶೂನ್ಯ bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ಯದಿ (!s1->do_backtrace)
        ಪ್ರತ್ಯಾಗಮ;
    rc = tcc_get_ಚಿಹ್ನೆ(s1, "__rt_info");
    ಯದಿ (!rc)
        ಪ್ರತ್ಯಾಗಮ;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (ವರ್ಣ *)symtab_section->link->data;
    ಯದಿ (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    ಯದಿ (s1->do_bounds_check) {
        ಶೂನ್ಯ *p;
        ಯದಿ ((p = tcc_get_ಚಿಹ್ನೆ(s1, "__bound_init")))
            ((ಶೂನ್ಯ(*)(ಶೂನ್ಯ*,ಪೂರ್ಣಾಙ್ಕ))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    ಯದಿ (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

ಸ್ಥಿರ ಶೂನ್ಯ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ಸ್ಥಿರ ಶೂನ್ಯ ptr_unlink(ಶೂನ್ಯ *list, ಶೂನ್ಯ *e, unsigned next)
{
    ಶೂನ್ಯ **pp, **nn, *p;
    ಪ್ರತಿ (pp = list; !!(p = *pp); pp = nn) {
        nn = (ಶೂನ್ಯ*)((ವರ್ಣ*)p + next); /* nn = &p->next; */
        ಯದಿ (p == e) {
            *pp = *nn;
            ಭಙ್ಗ;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI ಶೂನ್ಯ *_tcc_setjmp(TCCState *s1, ಶೂನ್ಯ *p_jmp_buf, ಶೂನ್ಯ *func, ಶೂನ್ಯ *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    ಯದಿ (s1->rc)
        s1->rc->ತುದಿ_func = func;
#endif
    ಪ್ರತ್ಯಾಗಮ p_jmp_buf;
}

LIBTCCAPI ಶೂನ್ಯ tcc_set_backtrace_func(TCCState *s1, ಶೂನ್ಯ *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

ಸ್ಥಿರ TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    ಪೂರ್ಣಾಙ್ಕ level;
    addr_t pc;

    s = g_s1;
    ಯದಿ (ರಿಕ್ತ == s || ರಿಕ್ತ == s->next) {
        /* play it safe in the simple case when there is only one state */
        ಪ್ರತ್ಯಾಗಮ s;
    }
    ಪ್ರತಿ (level = 0; level < 8; ++level) {
        ಯದಿ (rt_get_caller_pc(&pc, f, level) < 0)
            ಭಙ್ಗ;
        ಪ್ರತಿ (s = g_s1; s; s = s->next) {
            ಯದಿ (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                ಪ್ರತ್ಯಾಗಮ s;
        }
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_frame *f, ಪೂರ್ಣಾಙ್ಕ code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    ಯದಿ (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        ಯದಿ (f->fp) { /* called from signal */
            ಶೂನ್ಯ *p = tcc_get_ಚಿಹ್ನೆ(s, "__bound_exit");
            ಯದಿ (p)
                ((ಶೂನ್ಯ (*)(ಶೂನ್ಯ))p)();
        }
#endif
        ಯದಿ (code == 0)
            code = RT_EXIT_ZERO;
        ((ಶೂನ್ಯ(*)(ಶೂನ್ಯ*,ಪೂರ್ಣಾಙ್ಕ))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#ಅನ್ಯಥಾ // if defined CONFIG_TCC_BACKTRACE_ONLY
ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_frame *f, ಪೂರ್ಣಾಙ್ಕ code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_vprintf(ಧ್ರುವ ವರ್ಣ *fmt, va_list ap)
{
    ಪೂರ್ಣಾಙ್ಕ ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ಪ್ರತ್ಯಾಗಮ ret;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_printf(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap;
    ಪೂರ್ಣಾಙ್ಕ r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ಪ್ರತ್ಯಾಗಮ r;
}

ಸ್ಥಿರ ವರ್ಣ *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    ಪ್ರತಿ (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        ಪೂರ್ಣಾಙ್ಕ type = ELFW(ST_TYPE)(esym->st_info);
        ಯದಿ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_ಮೌಲ್ಯ
            && wanted_pc < esym->st_ಮೌಲ್ಯ + esym->st_size) {
            *func_addr = esym->st_ಮೌಲ್ಯ;
            ಪ್ರತ್ಯಾಗಮ rc->elf_str + esym->st_name;
        }
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ bt_info
{
    ವರ್ಣ file[100];
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
    ವರ್ಣ func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ಸ್ಥಿರ addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ವರ್ಣ func_name[128];
    addr_t func_addr, last_pc, pc;
    ಧ್ರುವ ವರ್ಣ *incl_files[INCLUDE_ರಾಶಿ_SIZE];
    ಪೂರ್ಣಾಙ್ಕ incl_index, last_incl_index, len, last_ಸಾಲು_ಅಂಕೆ, i;
    ಧ್ರುವ ವರ್ಣ *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_ಸಾಲು_ಅಂಕೆ = 1;
    last_incl_index = 0;

    ಪ್ರತಿ (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_ಮೌಲ್ಯ;

        ವಿಕಲ್ಪ(sym->n_type) {
        ಪಕ್ಷ N_SLINE:
            ಯದಿ (func_addr)
                ಗಚ್ಛ rel_pc;
        ಪಕ್ಷ N_SO:
        ಪಕ್ಷ N_SOL:
            ಗಚ್ಛ abs_pc;
        ಪಕ್ಷ N_FUN:
            ಯದಿ (sym->n_strx == 0) /* end of function */
                ಗಚ್ಛ rel_pc;
        abs_pc:
#ಯದಿ PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            ಗಚ್ಛ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ಯದಿ (pc >= wanted_pc && wanted_pc >= last_pc)
                ಗಚ್ಛ found;
            ಭಙ್ಗ;
        }

        ವಿಕಲ್ಪ(sym->n_type) {
            /* function start or end */
        ಪಕ್ಷ N_FUN:
            ಯದಿ (sym->n_strx == 0)
                ಗಚ್ಛ reset_func;
            p = strchr(str, ':');
            ಯದಿ (0 == p || (len = p - str + 1, len > ಪರಿಮಾಣ func_name))
                len = ಪರಿಮಾಣ func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ಭಙ್ಗ;
            /* line number info */
        ಪಕ್ಷ N_SLINE:
            last_pc = pc;
            last_ಸಾಲು_ಅಂಕೆ = sym->n_desc;
            last_incl_index = incl_index;
            ಭಙ್ಗ;
            /* include files */
        ಪಕ್ಷ N_BINCL:
            ಯದಿ (incl_index < INCLUDE_ರಾಶಿ_SIZE)
                incl_files[incl_index++] = str;
            ಭಙ್ಗ;
        ಪಕ್ಷ N_EINCL:
            ಯದಿ (incl_index > 1)
                incl_index--;
            ಭಙ್ಗ;
            /* start/end of translation unit */
        ಪಕ್ಷ N_SO:
            incl_index = 0;
            ಯದಿ (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                ಯದಿ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            ಭಙ್ಗ;
            /* alternative file name (from #line or #include directives) */
        ಪಕ್ಷ N_SOL:
            ಯದಿ (incl_index)
                incl_files[incl_index-1] = str;
            ಭಙ್ಗ;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    ಯದಿ (i > 0) {
        pstrcpy(bi->file, ಪರಿಮಾಣ bi->file, incl_files[--i]);
        bi->ಸಾಲು = last_ಸಾಲು_ಅಂಕೆ;
    }
    pstrcpy(bi->func, ಪರಿಮಾಣ bi->func, func_name);
    bi->func_pc = func_addr;
    ಪ್ರತ್ಯಾಗಮ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	ವಿಕಲ್ಪ (entry_format[j].form) { \
	ಪಕ್ಷ DW_FORM_data1: (ln) += 1; ಭಙ್ಗ; \
	ಪಕ್ಷ DW_FORM_data2: (ln) += 2; ಭಙ್ಗ; \
	ಪಕ್ಷ DW_FORM_data4: (ln) += 3; ಭಙ್ಗ; \
	ಪಕ್ಷ DW_FORM_data8: (ln) += 8; ಭಙ್ಗ; \
	ಪಕ್ಷ DW_FORM_data16: (ln) += 16; ಭಙ್ಗ; \
	ಪಕ್ಷ DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); ಭಙ್ಗ; \
	ಸ್ವಭಾವ: ಗಚ್ಛ next_ಸಾಲು; \
	}

ಸ್ಥಿರ addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned ವರ್ಣ *ln;
    unsigned ವರ್ಣ *cp;
    unsigned ವರ್ಣ *end;
    unsigned ವರ್ಣ *opcode_length;
    unsigned long long size;
    unsigned ಪೂರ್ಣಾಙ್ಕ length;
    unsigned ವರ್ಣ version;
    unsigned ಪೂರ್ಣಾಙ್ಕ min_insn_length;
    unsigned ಪೂರ್ಣಾಙ್ಕ max_ops_per_insn;
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_base;
    unsigned ಪೂರ್ಣಾಙ್ಕ ಸಾಲು_range;
    unsigned ಪೂರ್ಣಾಙ್ಕ opcode_base;
    unsigned ಪೂರ್ಣಾಙ್ಕ opindex;
    unsigned ಪೂರ್ಣಾಙ್ಕ col;
    unsigned ಪೂರ್ಣಾಙ್ಕ i;
    unsigned ಪೂರ್ಣಾಙ್ಕ j;
    unsigned ಪೂರ್ಣಾಙ್ಕ len;
    unsigned long long ಮೌಲ್ಯ;
    ಸಂರಚನಾ {
	unsigned ಪೂರ್ಣಾಙ್ಕ type;
	unsigned ಪೂರ್ಣಾಙ್ಕ form;
    } entry_format[256];
    unsigned ಪೂರ್ಣಾಙ್ಕ dir_size;
#ಯದಿ 0
    ವರ್ಣ *dirs[DIR_TABLE_SIZE];
#endif
    unsigned ಪೂರ್ಣಾಙ್ಕ filename_size;
    ಸಂರಚನಾ /*dwarf_filename_struct*/ {
        unsigned ಪೂರ್ಣಾಙ್ಕ dir_entry;
        ವರ್ಣ *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು;
    ವರ್ಣ *filename;
    ವರ್ಣ *function;

    filename = ರಿಕ್ತ;
    function = ರಿಕ್ತ;
    func_addr = 0;
    ಸಾಲು = 0;

    ln = rc->dwarf_ಸಾಲು;
    ಯಾವತ್ (ln < rc->dwarf_ಸಾಲು_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        ಸಾಲು = 1;
        filename = ರಿಕ್ತ;
        function = ರಿಕ್ತ;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_ಸಾಲು_end);
	ಯದಿ (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_ಸಾಲು_end);
	end = ln + size;
	ಯದಿ (end < ln || end > rc->dwarf_ಸಾಲು_end)
	    ಭಙ್ಗ;
	version = dwarf_read_2(ln, end);
	ಯದಿ (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	ಅನ್ಯಥಾ
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	ಯದಿ (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	ಅನ್ಯಥಾ
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	ಸಾಲು_base = dwarf_read_1(ln, end);
	ಸಾಲು_base |= ಸಾಲು_base >= 0x80 ? ~0xff : 0;
	ಸಾಲು_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	ಯದಿ (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    ಪ್ರತಿ (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    ಪ್ರತಿ (i = 0; i < dir_size; i++) {
		ಪ್ರತಿ (j = 0; j < col; j++) {
		    ಯದಿ (entry_format[j].type == DW_LNCT_path) {
		        ಯದಿ (entry_format[j].form != DW_FORM_ಸಾಲು_strp)
			    ಗಚ್ಛ next_ಸಾಲು;
#ಯದಿ 0
		        ಮೌಲ್ಯ = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ಯದಿ (i < DIR_TABLE_SIZE)
		            dirs[i] = (ವರ್ಣ *)rc->dwarf_ಸಾಲು_str + ಮೌಲ್ಯ;
#ಅನ್ಯಥಾ
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    ಅನ್ಯಥಾ 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    ಪ್ರತಿ (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    ಪ್ರತಿ (i = 0; i < filename_size; i++)
		ಪ್ರತಿ (j = 0; j < col; j++) {
		    ಯದಿ (entry_format[j].type == DW_LNCT_path) {
			ಯದಿ (entry_format[j].form != DW_FORM_ಸಾಲು_strp)
			    ಗಚ್ಛ next_ಸಾಲು;
			ಮೌಲ್ಯ = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ಯದಿ (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(ವರ್ಣ *)rc->dwarf_ಸಾಲು_str + ಮೌಲ್ಯ;
	            }
		    ಅನ್ಯಥಾ ಯದಿ (entry_format[j].type == DW_LNCT_directory_index) {
			ವಿಕಲ್ಪ (entry_format[j].form) {
			ಪಕ್ಷ DW_FORM_data1: ಮೌಲ್ಯ = dwarf_read_1(ln, end); ಭಙ್ಗ;
			ಪಕ್ಷ DW_FORM_data2: ಮೌಲ್ಯ = dwarf_read_2(ln, end); ಭಙ್ಗ;
			ಪಕ್ಷ DW_FORM_data4: ಮೌಲ್ಯ = dwarf_read_4(ln, end); ಭಙ್ಗ;
			ಪಕ್ಷ DW_FORM_udata: ಮೌಲ್ಯ = dwarf_read_uleb128(&ln, end); ಭಙ್ಗ;
			ಸ್ವಭಾವ: ಗಚ್ಛ next_ಸಾಲು;
			}
		        ಯದಿ (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = ಮೌಲ್ಯ;
		    }
		    ಅನ್ಯಥಾ 
			dwarf_ignore_type(ln, end);
	    }
	}
	ಅನ್ಯಥಾ {
	    ಯಾವತ್ ((dwarf_read_1(ln, end))) {
#ಯದಿ 0
		ಯದಿ (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (ವರ್ಣ *)ln - 1;
#endif
		ಯಾವತ್ (dwarf_read_1(ln, end)) {}
	    }
	    ಯಾವತ್ ((dwarf_read_1(ln, end))) {
		ಯದಿ (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (ವರ್ಣ *)ln - 1;
		    ಯಾವತ್ (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		ಅನ್ಯಥಾ {
		    ಯಾವತ್ (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	ಯದಿ (filename_size >= 1)
	    filename = filename_table[0].name;
	ಯಾವತ್ (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    ಯದಿ (i >= opcode_base) {
	        ಯದಿ (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / ಸಾಲು_range) * min_insn_length;
		ಅನ್ಯಥಾ {
		    pc += (opindex + (i - opcode_base) / ಸಾಲು_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / ಸಾಲು_range) %
			       max_ops_per_insn;
		}
		i = (ಪೂರ್ಣಾಙ್ಕ)((i - opcode_base) % ಸಾಲು_range) + ಸಾಲು_base;
check_pc:
		ಯದಿ (pc >= wanted_pc && wanted_pc >= last_pc)
		    ಗಚ್ಛ found;
		ಸಾಲು += i;
	    }
	    ಅನ್ಯಥಾ {
	        ವಿಕಲ್ಪ (i) {
	        ಪಕ್ಷ 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    ಯದಿ (len == 0)
		        ಗಚ್ಛ next_ಸಾಲು;
		    ವಿಕಲ್ಪ (dwarf_read_1(cp, end)) {
		    ಪಕ್ಷ DW_LNE_end_sequence:
		        ಭಙ್ಗ;
		    ಪಕ್ಷ DW_LNE_set_address:
#ಯದಿ PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#ಅನ್ಯಥಾ
		        pc = dwarf_read_8(cp, end);
#endif
#ಯದಿ defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        ಭಙ್ಗ;
		    ಪಕ್ಷ DW_LNE_define_file: /* deprecated */
		        ಯದಿ (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (ವರ್ಣ *)ln - 1;
		            ಯಾವತ್ (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        ಅನ್ಯಥಾ {
		            ಯಾವತ್ (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        ಭಙ್ಗ;
		    ಪಕ್ಷ DW_LNE_hi_user - 1:
		        function = (ವರ್ಣ *)cp;
		        func_addr = pc;
		        ಭಙ್ಗ;
		    ಸ್ವಭಾವ:
		        ಭಙ್ಗ;
		    }
		    ಭಙ್ಗ;
	        ಪಕ್ಷ DW_LNS_advance_pc:
		    ಯದಿ (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    ಅನ್ಯಥಾ {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    ಗಚ್ಛ check_pc;
	        ಪಕ್ಷ DW_LNS_advance_ಸಾಲು:
		    ಸಾಲು += dwarf_read_sleb128(&ln, end);
		    ಭಙ್ಗ;
	        ಪಕ್ಷ DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    ಯದಿ (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    ಭಙ್ಗ;
	        ಪಕ್ಷ DW_LNS_const_add_pc:
		    ಯದಿ (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / ಸಾಲು_range) * min_insn_length;
		    ಅನ್ಯಥಾ {
		        unsigned ಪೂರ್ಣಾಙ್ಕ off = (255 - opcode_base) / ಸಾಲು_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    ಗಚ್ಛ check_pc;
	        ಪಕ್ಷ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    ಗಚ್ಛ check_pc;
	        ಸ್ವಭಾವ:
		    ಪ್ರತಿ (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    ಭಙ್ಗ;
		}
	    }
	}
next_ಸಾಲು:
	ln = end;
    }
    filename = function = ರಿಕ್ತ, func_addr = 0;
found:
    ಯದಿ (filename)
        pstrcpy(bi->file, ಪರಿಮಾಣ bi->file, filename), bi->ಸಾಲು = ಸಾಲು;
    ಯದಿ (function)
        pstrcpy(bi->func, ಪರಿಮಾಣ bi->func, function);
    bi->func_pc = func_addr;
    ಪ್ರತ್ಯಾಗಮ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
ಸ್ಥಿರ
#endif
ಪೂರ್ಣಾಙ್ಕ _tcc_backtrace(rt_frame *f, ಧ್ರುವ ವರ್ಣ *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    ವರ್ಣ skip[40], ಸಂದೇಶ[200];
    ಪೂರ್ಣಾಙ್ಕ i, level, ret, n, one;
    ಧ್ರುವ ವರ್ಣ *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ಯದಿ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ಯದಿ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(ಸಂದೇಶ, ಪರಿಮಾಣ ಸಂದೇಶ, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ಯದಿ (rc) {
        ಯದಿ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ಯದಿ (rc->ಅಂಕೆ_callers)
            n = rc->ಅಂಕೆ_callers;
    }

    ಪ್ರತಿ (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ಯದಿ (ret == -1)
            ಭಙ್ಗ;
        memset(&bi, 0, ಪರಿಮಾಣ bi);
        ಪ್ರತಿ (rc2 = rc; rc2; rc2 = rc2->next) {
            ಯದಿ (getinfo(rc2, pc, &bi))
                ಭಙ್ಗ;
            /* we try symtab symbols (no line number info) */
            ಯದಿ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, ಪರಿಮಾಣ bi.func, a);
                ಭಙ್ಗ;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ಯದಿ (skip[0] && strstr(bi.file, skip))
            ಅನುವರ್ತ;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            ಯದಿ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (ಶೂನ್ಯ*)pc,
                    bi.file[0] ? bi.file : ರಿಕ್ತ,
                    bi.ಸಾಲು,
                    bi.func[0] ? bi.func : ರಿಕ್ತ,
                    level == 0 ? ಸಂದೇಶ : ರಿಕ್ತ
                    );
                ಯದಿ (ret == 0)
                    ಭಙ್ಗ;
                ಗಚ್ಛ check_break;
            }
        }
#endif
        ಯದಿ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.ಸಾಲು);
        } ಅನ್ಯಥಾ {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ಯದಿ (level == 0) {
            rt_printf(": %s", ಸಂದೇಶ);
            ಯದಿ (one)
                ಭಙ್ಗ;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        ಯದಿ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->ತುದಿ_func)
            ಭಙ್ಗ;
        ++level;
    }
    rt_post_sem();
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* emit a run time error at position 'pc' */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_error(rt_frame *f, ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap; ವರ್ಣ ಸಂದೇಶ[200]; ಪೂರ್ಣಾಙ್ಕ ret;
    va_start(ap, fmt);
    snprintf(ಸಂದೇಶ, ಪರಿಮಾಣ ಸಂದೇಶ, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, ಸಂದೇಶ, ap);
    va_end(ap);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ಅನ್ಯಥಾ
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
ಸ್ಥಿರ ಶೂನ್ಯ rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#ಯದಿ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#ನೋಚೇದ್ಯದಿ defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#ನೋಚೇದ್ಯದಿ defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#ನೋಚೇದ್ಯದಿ defined __i386__
# ಯದಿ defined(__APPLE__)
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
# ಅನ್ಯಥಾ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#ನೋಚೇದ್ಯದಿ defined(__x86_64__)
# ಯದಿ defined(__APPLE__)
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
# ಅನ್ಯಥಾ
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#ನೋಚೇದ್ಯದಿ defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ನೋಚೇದ್ಯದಿ defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#ನೋಚೇದ್ಯದಿ defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ನೋಚೇದ್ಯದಿ defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#ನೋಚೇದ್ಯದಿ defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#ನೋಚೇದ್ಯದಿ defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#ನೋಚೇದ್ಯದಿ defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ನೋಚೇದ್ಯದಿ defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#ನೋಚೇದ್ಯದಿ defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#ನೋಚೇದ್ಯದಿ defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#ನೋಚೇದ್ಯದಿ defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
ಸ್ಥಿರ ಶೂನ್ಯ sig_error(ಪೂರ್ಣಾಙ್ಕ signum, siginfo_t *siginf, ಶೂನ್ಯ *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    ವಿಕಲ್ಪ(signum) {
    ಪಕ್ಷ SIGFPE:
        ವಿಕಲ್ಪ(siginf->si_code) {
        ಪಕ್ಷ FPE_INTDIV:
        ಪಕ್ಷ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            rt_error(&f, "floating point exception");
            ಭಙ್ಗ;
        }
        ಭಙ್ಗ;
    ಪಕ್ಷ SIGBUS:
    ಪಕ್ಷ SIGSEGV:
        rt_error(&f, "invalid memory access");
        ಭಙ್ಗ;
    ಪಕ್ಷ SIGILL:
        rt_error(&f, "illegal instruction");
        ಭಙ್ಗ;
    ಪಕ್ಷ SIGABRT:
        rt_error(&f, "abort() called");
        ಭಙ್ಗ;
    ಸ್ವಭಾವ:
        rt_error(&f, "caught signal %d", signum);
        ಭಙ್ಗ;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ರಿಕ್ತ);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
ಸ್ಥಿರ ಶೂನ್ಯ set_exception_handler(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ಯದಿ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ರಿಕ್ತ);
    sigaction(SIGILL, &sigact, ರಿಕ್ತ);
    sigaction(SIGSEGV, &sigact, ರಿಕ್ತ);
    sigaction(SIGBUS, &sigact, ರಿಕ್ತ);
    sigaction(SIGABRT, &sigact, ರಿಕ್ತ);
#ಯದಿ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ಸ್ಥಿರ unsigned ವರ್ಣ ರಾಶಿ[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ರಾಶಿ;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ರಿಕ್ತ);
    }
#endif
}

#ಅನ್ಯಥಾ /* WIN32 */

/* signal handler for fatal errors */
ಸ್ಥಿರ long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    ವಿಕಲ್ಪ (code = ex_info->ExceptionRecord->ExceptionCode) {
    ಪಕ್ಷ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ಭಙ್ಗ;
    ಪಕ್ಷ EXCEPTION_ರಾಶಿ_OVERFLOW:
        rt_error(&f, "stack overflow");
        ಭಙ್ಗ;
    ಪಕ್ಷ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ಭಙ್ಗ;
    ಪಕ್ಷ EXCEPTION_BREAKPOINT:
    ಪಕ್ಷ EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ಪ್ರತ್ಯಾಗಮ EXCEPTION_CONTINUE_ಹುಡುಕು;
    ಸ್ವಭಾವ:
        rt_error(&f, "caught exception %08x", code);
        ಭಙ್ಗ;
    }
    rt_exit(&f, 255);
    ಪ್ರತ್ಯಾಗಮ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ಸ್ಥಿರ ಶೂನ್ಯ set_exception_handler(ಶೂನ್ಯ)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#ಅನ್ಯಥಾ
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ಯದಿ defined(__i386__) || defined(__x86_64__)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಯದಿ (level == 0) {
        *paddr = rc->ip;
    } ಅನ್ಯಥಾ {
        addr_t fp = rc->fp;
        ಯಾವತ್ (1) {
            ಯದಿ (fp < 0x1000)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಯದಿ (0 == --level)
                ಭಙ್ಗ;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* XXX: only supports linux/bsd */
#ನೋಚೇದ್ಯದಿ defined(__arm__) && !defined(_WIN32)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಯದಿ (level == 0) {
        *paddr = rc->ip;
    } ಅನ್ಯಥಾ {
        addr_t fp = rc->fp;
        ಯಾವತ್ (1) {
            ಯದಿ (fp < 0x1000)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಯದಿ (0 == --level)
                ಭಙ್ಗ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined(__aarch64__)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಯದಿ (level == 0) {
        *paddr = rc->ip;
    } ಅನ್ಯಥಾ {
        addr_t fp = rc->fp;
        ಯಾವತ್ (1) {
            ಯದಿ (fp < 0x1000)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಯದಿ (0 == --level)
                ಭಙ್ಗ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ನೋಚೇದ್ಯದಿ defined(__riscv)
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಯದಿ (level == 0) {
        *paddr = rc->ip;
    } ಅನ್ಯಥಾ {
        addr_t fp = rc->fp;
        ಯಾವತ್ (1) {
            ಯದಿ (fp < 0x1000)
                ಪ್ರತ್ಯಾಗಮ -1;
            ಯದಿ (0 == --level)
                ಭಙ್ಗ;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ಅನ್ಯಥಾ
#warning add arch specific rt_get_caller_pc()
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಪ್ರತ್ಯಾಗಮ -1;
}

#endif
#ಅನ್ಯಥಾ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ rt_get_caller_pc(addr_t *paddr, rt_frame *f, ಪೂರ್ಣಾಙ್ಕ level)
{
    ಯದಿ (level)
        ಪ್ರತ್ಯಾಗಮ -1;
    *paddr = f->ip;
    ಪ್ರತ್ಯಾಗಮ 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC ಶೂನ್ಯ *dlopen(ಧ್ರುವ ವರ್ಣ *filename, ಪೂರ್ಣಾಙ್ಕ flag)
{
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ST_FUNC ಶೂನ್ಯ dlclose(ಶೂನ್ಯ *p)
{
}

ST_FUNC ಧ್ರುವ ವರ್ಣ *dlerror(ಶೂನ್ಯ)
{
    ಪ್ರತ್ಯಾಗಮ "error";
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ TCCSyms {
    ವರ್ಣ *str;
    ಶೂನ್ಯ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ಸ್ಥಿರ TCCSyms tcc_syms[] = {
#ಯದಿ !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { ರಿಕ್ತ, ರಿಕ್ತ },
};

ST_FUNC ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ಧ್ರುವ ವರ್ಣ *ಚಿಹ್ನೆ)
{
    TCCSyms *p;
    p = tcc_syms;
    ಯಾವತ್ (p->str != ರಿಕ್ತ) {
        ಯದಿ (!strcmp(p->str, ಚಿಹ್ನೆ))
            ಪ್ರತ್ಯಾಗಮ p->ptr;
        p++;
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
