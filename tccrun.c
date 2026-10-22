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

#അന്തര്ഭാവ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
തരനിർവചനം ഘടന rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    സംഘം {
	ഘടന {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    അക്ഷരം *stab_str;
	};
	ഘടന {
	    unsigned അക്ഷരം *dwarf_വരി;
	    unsigned അക്ഷരം *dwarf_വരി_end;
	    unsigned അക്ഷരം *dwarf_വരി_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    അക്ഷരം *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    ശൂന്യം *bounds_start;
    ശൂന്യം *മുകൾ_func;
    ഘടന rt_context *next;
    // 10 * PTR_SIZE
    പൂർണ്ണസംഖ്യ അക്കം_callers;
    പൂർണ്ണസംഖ്യ dwarf;
} rt_context;

/* linked list of rt_contexts */
സ്ഥിതം rt_context *g_rc;
സ്ഥിതം പൂർണ്ണസംഖ്യ signal_set;
സ്ഥിതം ശൂന്യം set_exception_handler(ശൂന്യം);
#endif /* def CONFIG_TCC_BACKTRACE */

തരനിർവചനം ഘടന rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

സ്ഥിതം TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(സ്ഥിതം rt_sem);
സ്ഥിതം ശൂന്യം rt_wait_sem(ശൂന്യം) { WAIT_SEM(&rt_sem); }
സ്ഥിതം ശൂന്യം rt_post_sem(ശൂന്യം) { POST_SEM(&rt_sem); }
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *f, പൂർണ്ണസംഖ്യ level);
സ്ഥിതം ശൂന്യം rt_exit(rt_frame *f, പൂർണ്ണസംഖ്യ code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ protect_pages(ശൂന്യം *ptr, unsigned long length, പൂർണ്ണസംഖ്യ mode);
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_relocate_ex(TCCState *s1, ശൂന്യം *ptr, unsigned ptr_diff);
സ്ഥിതം ശൂന്യം st_link(TCCState *s1);
സ്ഥിതം ശൂന്യം st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
സ്ഥിതം പൂർണ്ണസംഖ്യ _tcc_backtrace(rt_frame *f, സ്ഥിരം അക്ഷരം *fmt, va_list ap);
#endif
#ifdef _WIN64
സ്ഥിതം ശൂന്യം *win64_add_function_table(TCCState *s1);
സ്ഥിതം ശൂന്യം win64_del_function_table(ശൂന്യം *);
#endif

#എങ്കിൽ !defined PAGESIZE
# എങ്കിൽ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# അല്ലെങ്കിൽ
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#എങ്കിൽ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#എങ്കിൽ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ rt_mem(TCCState *s1, പൂർണ്ണസംഖ്യ size)
{
    ശൂന്യം *ptr;
    പൂർണ്ണസംഖ്യ ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    ശൂന്യം *prw;
    അക്ഷരം tmpfname[] = "/tmp/.tccrunXXXXXX";
    പൂർണ്ണസംഖ്യ fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(ശൂന്യ, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((അക്ഷരം*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    എങ്കിൽ (ptr == MAP_FAILED || prw == MAP_FAILED)
	തിരികെ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (അക്ഷരം*)prw - (അക്ഷരം*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#അല്ലെങ്കിലെങ്കിൽ CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ശൂന്യ, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    എങ്കിൽ (!ptr)
        തിരികെ tcc_error_noabort("tccrun: could not allocate memory");
#അല്ലെങ്കിൽ
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    തിരികെ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_relocate(TCCState *s1)
{
    പൂർണ്ണസംഖ്യ size, ret, ptr_diff;

    എങ്കിൽ (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    എങ്കിൽ (s1->do_backtrace)
        tcc_add_ചിഹ്നം(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, ശൂന്യ, 0);
    എങ്കിൽ (size < 0)
        തിരികെ -1;
    ptr_diff = rt_mem(s1, size);
    എങ്കിൽ (ptr_diff < 0)
        തിരികെ -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    എങ്കിൽ (ret == 0)
        st_link(s1);
    തിരികെ ret;
}

ST_FUNC ശൂന്യം tcc_run_free(TCCState *s1)
{
    unsigned size;
    ശൂന്യം *ptr;
    പൂർണ്ണസംഖ്യ i;

    /* free any loaded DLLs */
    വേണ്ടി ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        എങ്കിൽ ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#അല്ലെങ്കിൽ
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    എങ്കിൽ (ശൂന്യ == ptr)
        തിരികെ;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#അല്ലെങ്കിലെങ്കിൽ CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#അല്ലെങ്കിൽ
    /* unprotect memory to make it usable for malloc again */
    protect_pages((ശൂന്യം*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_run(TCCState *s1, പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ (*prog_main)(പൂർണ്ണസംഖ്യ, അക്ഷരം **, അക്ഷരം **), ret;
    സ്ഥിരം അക്ഷരം *മുകൾ_sym;
    jmp_buf main_jb;

#എങ്കിൽ defined(__APPLE__)
    ബാഹ്യ അക്ഷരം ***_NSGetEnviron(ശൂന്യം);
    അക്ഷരം **envp = *_NSGetEnviron();
#അല്ലെങ്കിലെങ്കിൽ defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    ബാഹ്യ അക്ഷരം **environ;
    അക്ഷരം **envp = environ;
#അല്ലെങ്കിൽ
    അക്ഷരം **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    എങ്കിൽ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        തിരികെ 0;

    tcc_add_ചിഹ്നം(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", മുകൾ_sym = "main";
    എങ്കിൽ (s1->elf_entryname)
        s1->run_main = മുകൾ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    എങ്കിൽ (tcc_relocate(s1) < 0)
        തിരികെ -1;

    prog_main = (ശൂന്യം*)get_sym_addr(s1, s1->run_main, 1, 1);
    എങ്കിൽ ((addr_t)-1 == (addr_t)prog_main)
        തിരികെ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    എങ്കിൽ (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        തിരികെ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_ചിഹ്നം(s1, മുകൾ_sym));
    എങ്കിൽ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } അല്ലെങ്കിൽ എങ്കിൽ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    എങ്കിൽ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    തിരികെ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
സ്ഥിതം ശൂന്യം cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    പൂർണ്ണസംഖ്യ sym_index, end_sym = s->data_offset / വലുപ്പം (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    വേണ്ടി (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        സ്ഥിരം അക്ഷരം *name = (അക്ഷരം *)s->link->data + sym->st_name;
        എങ്കിൽ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            തുടരുക;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_മൂല്യം, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
സ്ഥിതം ശൂന്യം cleanup_sections(TCCState *s1)
{
    ഘടന { Section **secs; പൂർണ്ണസംഖ്യ nb_secs; } *p = (ശൂന്യം*)&s1->sections;
    പൂർണ്ണസംഖ്യ i, f = 2;
    ചെയ്യുക {
        വേണ്ടി (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            എങ്കിൽ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } അല്ലെങ്കിൽ {
                free_section(s), tcc_free(s), p->secs[i] = ശൂന്യ;
            }
        }
    } ആകുമ്പോൾ (++p, f);
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
# അല്ലെങ്കിൽ
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
സ്ഥിതം പൂർണ്ണസംഖ്യ tcc_relocate_ex(TCCState *s1, ശൂന്യം *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    എങ്കിൽ (ശൂന്യ == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, ശൂന്യ);
#അല്ലെങ്കിൽ
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    എങ്കിൽ (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    എങ്കിൽ (s1->nb_errors)
        തിരികെ -1;
    എങ്കിൽ (copy == 3)
        തിരികെ 0;

    വേണ്ടി (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        വേണ്ടി(i = 1; i < s1->nb_sections; i++) {
            സ്ഥിതം സ്ഥിരം അക്ഷരം shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            എങ്കിൽ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                തുടരുക;
            length = s->data_offset;
            എങ്കിൽ (copy == 2) {
                എങ്കിൽ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                തുടരുക;
            }
            എങ്കിൽ (copy) { /* final step: copy section data to memory */
                എങ്കിൽ (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (ശൂന്യം*)s->sh_addr, length, s->sh_addralign);
                ptr = (ശൂന്യം*)s->sh_addr;
                എങ്കിൽ (k == 0)
                    ptr = (ശൂന്യം*)(s->sh_addr + ptr_diff);
                എങ്കിൽ (ശൂന്യ == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                അല്ലെങ്കിൽ
                    memcpy(ptr, s->data, length);
                തുടരുക;
            }

            എങ്കിൽ ((s->sh_flags & SHF_TLS) && length)
                തിരികെ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            എങ്കിൽ (++n == 1) {
#എങ്കിൽ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                എങ്കിൽ (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                എങ്കിൽ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        എങ്കിൽ (copy == 2) { /* set permissions */
            എങ്കിൽ (n == 0) /* no data  */
                തുടരുക;
#ifdef CONFIG_SELINUX
            എങ്കിൽ (k == 0) /* SHF_EXECINSTR has its own mapping */
                തുടരുക;
#endif
            f = k;
            എങ്കിൽ (f >= CONFIG_RUNMEM_RO) {
                എങ്കിൽ (f != 0)
                    തുടരുക;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            എങ്കിൽ (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (ശൂന്യം*)addr, (unsigned)n);
            }
            എങ്കിൽ (protect_pages((ശൂന്യം*)addr, n, f) < 0)
                തിരികെ tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#അല്ലെങ്കിൽ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    എങ്കിൽ (0 == mem)
        തിരികെ PAGEALIGN(offset);

    എങ്കിൽ (++copy == 2) {
        പോകുക redo;
    }
    എങ്കിൽ (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        പോകുക redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    എങ്കിൽ (s1->nb_errors)
        പോകുക redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#അല്ലെങ്കിൽ
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    പോകുക redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

സ്ഥിതം പൂർണ്ണസംഖ്യ protect_pages(ശൂന്യം *ptr, unsigned long length, പൂർണ്ണസംഖ്യ mode)
{
#ifdef _WIN32
    സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    എങ്കിൽ (!VirtualProtect(ptr, length, protect[mode], &old))
        തിരികെ -1;
#അല്ലെങ്കിൽ
    സ്ഥിതം സ്ഥിരം unsigned അക്ഷരം protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    എങ്കിൽ (mprotect(ptr, length, protect[mode]))
        തിരികെ -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#എങ്കിൽ (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    എങ്കിൽ (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#അല്ലെങ്കിൽ
        ശൂന്യം __clear_cache(ശൂന്യം *beginning, ശൂന്യം *end);
        __clear_cache(ptr, (അക്ഷരം *)ptr + length);
#endif
    }
#endif
    തിരികെ 0;
}

#ifdef _WIN64
സ്ഥിതം ശൂന്യം *win64_add_function_table(TCCState *s1)
{
    ശൂന്യം *p = ശൂന്യ;
    എങ്കിൽ (s1->uw_pdata) {
        p = (ശൂന്യം*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / വലുപ്പം (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ശൂന്യ;
    }
    തിരികെ p;
}

സ്ഥിതം ശൂന്യം win64_del_function_table(ശൂന്യം *p)
{
    എങ്കിൽ (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

സ്ഥിതം ശൂന്യം bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    എങ്കിൽ (!s1->do_backtrace)
        തിരികെ;
    rc = tcc_get_ചിഹ്നം(s1, "__rt_info");
    എങ്കിൽ (!rc)
        തിരികെ;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (അക്ഷരം *)symtab_section->link->data;
    എങ്കിൽ (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    എങ്കിൽ (s1->do_bounds_check) {
        ശൂന്യം *p;
        എങ്കിൽ ((p = tcc_get_ചിഹ്നം(s1, "__bound_init")))
            ((ശൂന്യം(*)(ശൂന്യം*,പൂർണ്ണസംഖ്യ))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    എങ്കിൽ (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

സ്ഥിതം ശൂന്യം st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
സ്ഥിതം ശൂന്യം ptr_unlink(ശൂന്യം *list, ശൂന്യം *e, unsigned next)
{
    ശൂന്യം **pp, **nn, *p;
    വേണ്ടി (pp = list; !!(p = *pp); pp = nn) {
        nn = (ശൂന്യം*)((അക്ഷരം*)p + next); /* nn = &p->next; */
        എങ്കിൽ (p == e) {
            *pp = *nn;
            നിർത്തുക;
        }
    }
}

സ്ഥിതം ശൂന്യം st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI ശൂന്യം *_tcc_setjmp(TCCState *s1, ശൂന്യം *p_jmp_buf, ശൂന്യം *func, ശൂന്യം *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    എങ്കിൽ (s1->rc)
        s1->rc->മുകൾ_func = func;
#endif
    തിരികെ p_jmp_buf;
}

LIBTCCAPI ശൂന്യം tcc_set_backtrace_func(TCCState *s1, ശൂന്യം *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

സ്ഥിതം TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    പൂർണ്ണസംഖ്യ level;
    addr_t pc;

    s = g_s1;
    എങ്കിൽ (ശൂന്യ == s || ശൂന്യ == s->next) {
        /* play it safe in the simple case when there is only one state */
        തിരികെ s;
    }
    വേണ്ടി (level = 0; level < 8; ++level) {
        എങ്കിൽ (rt_get_caller_pc(&pc, f, level) < 0)
            നിർത്തുക;
        വേണ്ടി (s = g_s1; s; s = s->next) {
            എങ്കിൽ (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                തിരികെ s;
        }
    }
    തിരികെ ശൂന്യ;
}

സ്ഥിതം ശൂന്യം rt_exit(rt_frame *f, പൂർണ്ണസംഖ്യ code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    എങ്കിൽ (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        എങ്കിൽ (f->fp) { /* called from signal */
            ശൂന്യം *p = tcc_get_ചിഹ്നം(s, "__bound_exit");
            എങ്കിൽ (p)
                ((ശൂന്യം (*)(ശൂന്യം))p)();
        }
#endif
        എങ്കിൽ (code == 0)
            code = RT_EXIT_ZERO;
        ((ശൂന്യം(*)(ശൂന്യം*,പൂർണ്ണസംഖ്യ))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#അല്ലെങ്കിൽ // if defined CONFIG_TCC_BACKTRACE_ONLY
സ്ഥിതം ശൂന്യം rt_exit(rt_frame *f, പൂർണ്ണസംഖ്യ code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

സ്ഥിതം പൂർണ്ണസംഖ്യ rt_vprintf(സ്ഥിരം അക്ഷരം *fmt, va_list ap)
{
    പൂർണ്ണസംഖ്യ ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    തിരികെ ret;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ rt_printf(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap;
    പൂർണ്ണസംഖ്യ r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    തിരികെ r;
}

സ്ഥിതം അക്ഷരം *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    വേണ്ടി (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        പൂർണ്ണസംഖ്യ type = ELFW(ST_TYPE)(esym->st_info);
        എങ്കിൽ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_മൂല്യം
            && wanted_pc < esym->st_മൂല്യം + esym->st_size) {
            *func_addr = esym->st_മൂല്യം;
            തിരികെ rc->elf_str + esym->st_name;
        }
    }
    തിരികെ ശൂന്യ;
}

തരനിർവചനം ഘടന bt_info
{
    അക്ഷരം file[100];
    പൂർണ്ണസംഖ്യ വരി;
    അക്ഷരം func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
സ്ഥിതം addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    അക്ഷരം func_name[128];
    addr_t func_addr, last_pc, pc;
    സ്ഥിരം അക്ഷരം *incl_files[INCLUDE_അട്ടി_SIZE];
    പൂർണ്ണസംഖ്യ incl_index, last_incl_index, len, last_വരി_അക്കം, i;
    സ്ഥിരം അക്ഷരം *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_വരി_അക്കം = 1;
    last_incl_index = 0;

    വേണ്ടി (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_മൂല്യം;

        തിരഞ്ഞെടുപ്പ്(sym->n_type) {
        അവസ്ഥ N_SLINE:
            എങ്കിൽ (func_addr)
                പോകുക rel_pc;
        അവസ്ഥ N_SO:
        അവസ്ഥ N_SOL:
            പോകുക abs_pc;
        അവസ്ഥ N_FUN:
            എങ്കിൽ (sym->n_strx == 0) /* end of function */
                പോകുക rel_pc;
        abs_pc:
#എങ്കിൽ PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            പോകുക check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            എങ്കിൽ (pc >= wanted_pc && wanted_pc >= last_pc)
                പോകുക found;
            നിർത്തുക;
        }

        തിരഞ്ഞെടുപ്പ്(sym->n_type) {
            /* function start or end */
        അവസ്ഥ N_FUN:
            എങ്കിൽ (sym->n_strx == 0)
                പോകുക reset_func;
            p = strchr(str, ':');
            എങ്കിൽ (0 == p || (len = p - str + 1, len > വലുപ്പം func_name))
                len = വലുപ്പം func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            നിർത്തുക;
            /* line number info */
        അവസ്ഥ N_SLINE:
            last_pc = pc;
            last_വരി_അക്കം = sym->n_desc;
            last_incl_index = incl_index;
            നിർത്തുക;
            /* include files */
        അവസ്ഥ N_BINCL:
            എങ്കിൽ (incl_index < INCLUDE_അട്ടി_SIZE)
                incl_files[incl_index++] = str;
            നിർത്തുക;
        അവസ്ഥ N_EINCL:
            എങ്കിൽ (incl_index > 1)
                incl_index--;
            നിർത്തുക;
            /* start/end of translation unit */
        അവസ്ഥ N_SO:
            incl_index = 0;
            എങ്കിൽ (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                എങ്കിൽ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            നിർത്തുക;
            /* alternative file name (from #line or #include directives) */
        അവസ്ഥ N_SOL:
            എങ്കിൽ (incl_index)
                incl_files[incl_index-1] = str;
            നിർത്തുക;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    എങ്കിൽ (i > 0) {
        pstrcpy(bi->file, വലുപ്പം bi->file, incl_files[--i]);
        bi->വരി = last_വരി_അക്കം;
    }
    pstrcpy(bi->func, വലുപ്പം bi->func, func_name);
    bi->func_pc = func_addr;
    തിരികെ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	തിരഞ്ഞെടുപ്പ് (entry_format[j].form) { \
	അവസ്ഥ DW_FORM_data1: (ln) += 1; നിർത്തുക; \
	അവസ്ഥ DW_FORM_data2: (ln) += 2; നിർത്തുക; \
	അവസ്ഥ DW_FORM_data4: (ln) += 3; നിർത്തുക; \
	അവസ്ഥ DW_FORM_data8: (ln) += 8; നിർത്തുക; \
	അവസ്ഥ DW_FORM_data16: (ln) += 16; നിർത്തുക; \
	അവസ്ഥ DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); നിർത്തുക; \
	സ്ഥിരസ്ഥിതി: പോകുക next_വരി; \
	}

സ്ഥിതം addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned അക്ഷരം *ln;
    unsigned അക്ഷരം *cp;
    unsigned അക്ഷരം *end;
    unsigned അക്ഷരം *opcode_length;
    unsigned long long size;
    unsigned പൂർണ്ണസംഖ്യ length;
    unsigned അക്ഷരം version;
    unsigned പൂർണ്ണസംഖ്യ min_insn_length;
    unsigned പൂർണ്ണസംഖ്യ max_ops_per_insn;
    പൂർണ്ണസംഖ്യ വരി_base;
    unsigned പൂർണ്ണസംഖ്യ വരി_range;
    unsigned പൂർണ്ണസംഖ്യ opcode_base;
    unsigned പൂർണ്ണസംഖ്യ opindex;
    unsigned പൂർണ്ണസംഖ്യ col;
    unsigned പൂർണ്ണസംഖ്യ i;
    unsigned പൂർണ്ണസംഖ്യ j;
    unsigned പൂർണ്ണസംഖ്യ len;
    unsigned long long മൂല്യം;
    ഘടന {
	unsigned പൂർണ്ണസംഖ്യ type;
	unsigned പൂർണ്ണസംഖ്യ form;
    } entry_format[256];
    unsigned പൂർണ്ണസംഖ്യ dir_size;
#എങ്കിൽ 0
    അക്ഷരം *dirs[DIR_TABLE_SIZE];
#endif
    unsigned പൂർണ്ണസംഖ്യ filename_size;
    ഘടന /*dwarf_filename_struct*/ {
        unsigned പൂർണ്ണസംഖ്യ dir_entry;
        അക്ഷരം *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    പൂർണ്ണസംഖ്യ വരി;
    അക്ഷരം *filename;
    അക്ഷരം *function;

    filename = ശൂന്യ;
    function = ശൂന്യ;
    func_addr = 0;
    വരി = 0;

    ln = rc->dwarf_വരി;
    ആകുമ്പോൾ (ln < rc->dwarf_വരി_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        വരി = 1;
        filename = ശൂന്യ;
        function = ശൂന്യ;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_വരി_end);
	എങ്കിൽ (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_വരി_end);
	end = ln + size;
	എങ്കിൽ (end < ln || end > rc->dwarf_വരി_end)
	    നിർത്തുക;
	version = dwarf_read_2(ln, end);
	എങ്കിൽ (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	അല്ലെങ്കിൽ
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	എങ്കിൽ (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	അല്ലെങ്കിൽ
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	വരി_base = dwarf_read_1(ln, end);
	വരി_base |= വരി_base >= 0x80 ? ~0xff : 0;
	വരി_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	എങ്കിൽ (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    വേണ്ടി (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    വേണ്ടി (i = 0; i < dir_size; i++) {
		വേണ്ടി (j = 0; j < col; j++) {
		    എങ്കിൽ (entry_format[j].type == DW_LNCT_path) {
		        എങ്കിൽ (entry_format[j].form != DW_FORM_വരി_strp)
			    പോകുക next_വരി;
#എങ്കിൽ 0
		        മൂല്യം = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        എങ്കിൽ (i < DIR_TABLE_SIZE)
		            dirs[i] = (അക്ഷരം *)rc->dwarf_വരി_str + മൂല്യം;
#അല്ലെങ്കിൽ
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    അല്ലെങ്കിൽ 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    വേണ്ടി (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    വേണ്ടി (i = 0; i < filename_size; i++)
		വേണ്ടി (j = 0; j < col; j++) {
		    എങ്കിൽ (entry_format[j].type == DW_LNCT_path) {
			എങ്കിൽ (entry_format[j].form != DW_FORM_വരി_strp)
			    പോകുക next_വരി;
			മൂല്യം = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        എങ്കിൽ (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(അക്ഷരം *)rc->dwarf_വരി_str + മൂല്യം;
	            }
		    അല്ലെങ്കിൽ എങ്കിൽ (entry_format[j].type == DW_LNCT_directory_index) {
			തിരഞ്ഞെടുപ്പ് (entry_format[j].form) {
			അവസ്ഥ DW_FORM_data1: മൂല്യം = dwarf_read_1(ln, end); നിർത്തുക;
			അവസ്ഥ DW_FORM_data2: മൂല്യം = dwarf_read_2(ln, end); നിർത്തുക;
			അവസ്ഥ DW_FORM_data4: മൂല്യം = dwarf_read_4(ln, end); നിർത്തുക;
			അവസ്ഥ DW_FORM_udata: മൂല്യം = dwarf_read_uleb128(&ln, end); നിർത്തുക;
			സ്ഥിരസ്ഥിതി: പോകുക next_വരി;
			}
		        എങ്കിൽ (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = മൂല്യം;
		    }
		    അല്ലെങ്കിൽ 
			dwarf_ignore_type(ln, end);
	    }
	}
	അല്ലെങ്കിൽ {
	    ആകുമ്പോൾ ((dwarf_read_1(ln, end))) {
#എങ്കിൽ 0
		എങ്കിൽ (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (അക്ഷരം *)ln - 1;
#endif
		ആകുമ്പോൾ (dwarf_read_1(ln, end)) {}
	    }
	    ആകുമ്പോൾ ((dwarf_read_1(ln, end))) {
		എങ്കിൽ (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (അക്ഷരം *)ln - 1;
		    ആകുമ്പോൾ (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		അല്ലെങ്കിൽ {
		    ആകുമ്പോൾ (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	എങ്കിൽ (filename_size >= 1)
	    filename = filename_table[0].name;
	ആകുമ്പോൾ (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    എങ്കിൽ (i >= opcode_base) {
	        എങ്കിൽ (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / വരി_range) * min_insn_length;
		അല്ലെങ്കിൽ {
		    pc += (opindex + (i - opcode_base) / വരി_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / വരി_range) %
			       max_ops_per_insn;
		}
		i = (പൂർണ്ണസംഖ്യ)((i - opcode_base) % വരി_range) + വരി_base;
check_pc:
		എങ്കിൽ (pc >= wanted_pc && wanted_pc >= last_pc)
		    പോകുക found;
		വരി += i;
	    }
	    അല്ലെങ്കിൽ {
	        തിരഞ്ഞെടുപ്പ് (i) {
	        അവസ്ഥ 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    എങ്കിൽ (len == 0)
		        പോകുക next_വരി;
		    തിരഞ്ഞെടുപ്പ് (dwarf_read_1(cp, end)) {
		    അവസ്ഥ DW_LNE_end_sequence:
		        നിർത്തുക;
		    അവസ്ഥ DW_LNE_set_address:
#എങ്കിൽ PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#അല്ലെങ്കിൽ
		        pc = dwarf_read_8(cp, end);
#endif
#എങ്കിൽ defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        നിർത്തുക;
		    അവസ്ഥ DW_LNE_define_file: /* deprecated */
		        എങ്കിൽ (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (അക്ഷരം *)ln - 1;
		            ആകുമ്പോൾ (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        അല്ലെങ്കിൽ {
		            ആകുമ്പോൾ (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        നിർത്തുക;
		    അവസ്ഥ DW_LNE_hi_user - 1:
		        function = (അക്ഷരം *)cp;
		        func_addr = pc;
		        നിർത്തുക;
		    സ്ഥിരസ്ഥിതി:
		        നിർത്തുക;
		    }
		    നിർത്തുക;
	        അവസ്ഥ DW_LNS_advance_pc:
		    എങ്കിൽ (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    അല്ലെങ്കിൽ {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    പോകുക check_pc;
	        അവസ്ഥ DW_LNS_advance_വരി:
		    വരി += dwarf_read_sleb128(&ln, end);
		    നിർത്തുക;
	        അവസ്ഥ DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    എങ്കിൽ (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    നിർത്തുക;
	        അവസ്ഥ DW_LNS_const_add_pc:
		    എങ്കിൽ (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / വരി_range) * min_insn_length;
		    അല്ലെങ്കിൽ {
		        unsigned പൂർണ്ണസംഖ്യ off = (255 - opcode_base) / വരി_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    പോകുക check_pc;
	        അവസ്ഥ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    പോകുക check_pc;
	        സ്ഥിരസ്ഥിതി:
		    വേണ്ടി (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    നിർത്തുക;
		}
	    }
	}
next_വരി:
	ln = end;
    }
    filename = function = ശൂന്യ, func_addr = 0;
found:
    എങ്കിൽ (filename)
        pstrcpy(bi->file, വലുപ്പം bi->file, filename), bi->വരി = വരി;
    എങ്കിൽ (function)
        pstrcpy(bi->func, വലുപ്പം bi->func, function);
    bi->func_pc = func_addr;
    തിരികെ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
സ്ഥിതം
#endif
പൂർണ്ണസംഖ്യ _tcc_backtrace(rt_frame *f, സ്ഥിരം അക്ഷരം *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    അക്ഷരം skip[40], സന്ദേശം[200];
    പൂർണ്ണസംഖ്യ i, level, ret, n, one;
    സ്ഥിരം അക്ഷരം *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    എങ്കിൽ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    എങ്കിൽ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(സന്ദേശം, വലുപ്പം സന്ദേശം, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    എങ്കിൽ (rc) {
        എങ്കിൽ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        എങ്കിൽ (rc->അക്കം_callers)
            n = rc->അക്കം_callers;
    }

    വേണ്ടി (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        എങ്കിൽ (ret == -1)
            നിർത്തുക;
        memset(&bi, 0, വലുപ്പം bi);
        വേണ്ടി (rc2 = rc; rc2; rc2 = rc2->next) {
            എങ്കിൽ (getinfo(rc2, pc, &bi))
                നിർത്തുക;
            /* we try symtab symbols (no line number info) */
            എങ്കിൽ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, വലുപ്പം bi.func, a);
                നിർത്തുക;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        എങ്കിൽ (skip[0] && strstr(bi.file, skip))
            തുടരുക;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            എങ്കിൽ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (ശൂന്യം*)pc,
                    bi.file[0] ? bi.file : ശൂന്യ,
                    bi.വരി,
                    bi.func[0] ? bi.func : ശൂന്യ,
                    level == 0 ? സന്ദേശം : ശൂന്യ
                    );
                എങ്കിൽ (ret == 0)
                    നിർത്തുക;
                പോകുക check_break;
            }
        }
#endif
        എങ്കിൽ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.വരി);
        } അല്ലെങ്കിൽ {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        എങ്കിൽ (level == 0) {
            rt_printf(": %s", സന്ദേശം);
            എങ്കിൽ (one)
                നിർത്തുക;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        എങ്കിൽ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->മുകൾ_func)
            നിർത്തുക;
        ++level;
    }
    rt_post_sem();
    തിരികെ 0;
}

/* emit a run time error at position 'pc' */
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_error(rt_frame *f, സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap; അക്ഷരം സന്ദേശം[200]; പൂർണ്ണസംഖ്യ ret;
    va_start(ap, fmt);
    snprintf(സന്ദേശം, വലുപ്പം സന്ദേശം, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, സന്ദേശം, ap);
    va_end(ap);
    തിരികെ ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#അല്ലെങ്കിൽ
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
സ്ഥിതം ശൂന്യം rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#എങ്കിൽ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#അല്ലെങ്കിലെങ്കിൽ defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#അല്ലെങ്കിലെങ്കിൽ defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#അല്ലെങ്കിലെങ്കിൽ defined __i386__
# എങ്കിൽ defined(__APPLE__)
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
# അല്ലെങ്കിൽ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#അല്ലെങ്കിലെങ്കിൽ defined(__x86_64__)
# എങ്കിൽ defined(__APPLE__)
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
# അല്ലെങ്കിൽ
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#അല്ലെങ്കിലെങ്കിൽ defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#അല്ലെങ്കിലെങ്കിൽ defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
സ്ഥിതം ശൂന്യം sig_error(പൂർണ്ണസംഖ്യ signum, siginfo_t *siginf, ശൂന്യം *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    തിരഞ്ഞെടുപ്പ്(signum) {
    അവസ്ഥ SIGFPE:
        തിരഞ്ഞെടുപ്പ്(siginf->si_code) {
        അവസ്ഥ FPE_INTDIV:
        അവസ്ഥ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            rt_error(&f, "floating point exception");
            നിർത്തുക;
        }
        നിർത്തുക;
    അവസ്ഥ SIGBUS:
    അവസ്ഥ SIGSEGV:
        rt_error(&f, "invalid memory access");
        നിർത്തുക;
    അവസ്ഥ SIGILL:
        rt_error(&f, "illegal instruction");
        നിർത്തുക;
    അവസ്ഥ SIGABRT:
        rt_error(&f, "abort() called");
        നിർത്തുക;
    സ്ഥിരസ്ഥിതി:
        rt_error(&f, "caught signal %d", signum);
        നിർത്തുക;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ശൂന്യ);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
സ്ഥിതം ശൂന്യം set_exception_handler(ശൂന്യം)
{
    ഘടന sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#എങ്കിൽ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ശൂന്യ);
    sigaction(SIGILL, &sigact, ശൂന്യ);
    sigaction(SIGSEGV, &sigact, ശൂന്യ);
    sigaction(SIGBUS, &sigact, ശൂന്യ);
    sigaction(SIGABRT, &sigact, ശൂന്യ);
#എങ്കിൽ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        സ്ഥിതം unsigned അക്ഷരം അട്ടി[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = അട്ടി;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ശൂന്യ);
    }
#endif
}

#അല്ലെങ്കിൽ /* WIN32 */

/* signal handler for fatal errors */
സ്ഥിതം long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    തിരഞ്ഞെടുപ്പ് (code = ex_info->ExceptionRecord->ExceptionCode) {
    അവസ്ഥ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        നിർത്തുക;
    അവസ്ഥ EXCEPTION_അട്ടി_OVERFLOW:
        rt_error(&f, "stack overflow");
        നിർത്തുക;
    അവസ്ഥ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        നിർത്തുക;
    അവസ്ഥ EXCEPTION_BREAKPOINT:
    അവസ്ഥ EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        തിരികെ EXCEPTION_CONTINUE_തിരയൽ;
    സ്ഥിരസ്ഥിതി:
        rt_error(&f, "caught exception %08x", code);
        നിർത്തുക;
    }
    rt_exit(&f, 255);
    തിരികെ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
സ്ഥിതം ശൂന്യം set_exception_handler(ശൂന്യം)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#അല്ലെങ്കിൽ
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#എങ്കിൽ defined(__i386__) || defined(__x86_64__)
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, പൂർണ്ണസംഖ്യ level)
{
    എങ്കിൽ (level == 0) {
        *paddr = rc->ip;
    } അല്ലെങ്കിൽ {
        addr_t fp = rc->fp;
        ആകുമ്പോൾ (1) {
            എങ്കിൽ (fp < 0x1000)
                തിരികെ -1;
            എങ്കിൽ (0 == --level)
                നിർത്തുക;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    തിരികെ 0;
}

/* XXX: only supports linux/bsd */
#അല്ലെങ്കിലെങ്കിൽ defined(__arm__) && !defined(_WIN32)
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, പൂർണ്ണസംഖ്യ level)
{
    എങ്കിൽ (level == 0) {
        *paddr = rc->ip;
    } അല്ലെങ്കിൽ {
        addr_t fp = rc->fp;
        ആകുമ്പോൾ (1) {
            എങ്കിൽ (fp < 0x1000)
                തിരികെ -1;
            എങ്കിൽ (0 == --level)
                നിർത്തുക;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined(__aarch64__)
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, പൂർണ്ണസംഖ്യ level)
{
    എങ്കിൽ (level == 0) {
        *paddr = rc->ip;
    } അല്ലെങ്കിൽ {
        addr_t fp = rc->fp;
        ആകുമ്പോൾ (1) {
            എങ്കിൽ (fp < 0x1000)
                തിരികെ -1;
            എങ്കിൽ (0 == --level)
                നിർത്തുക;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    തിരികെ 0;
}

#അല്ലെങ്കിലെങ്കിൽ defined(__riscv)
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, പൂർണ്ണസംഖ്യ level)
{
    എങ്കിൽ (level == 0) {
        *paddr = rc->ip;
    } അല്ലെങ്കിൽ {
        addr_t fp = rc->fp;
        ആകുമ്പോൾ (1) {
            എങ്കിൽ (fp < 0x1000)
                തിരികെ -1;
            എങ്കിൽ (0 == --level)
                നിർത്തുക;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    തിരികെ 0;
}

#അല്ലെങ്കിൽ
#warning add arch specific rt_get_caller_pc()
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *rc, പൂർണ്ണസംഖ്യ level)
{
    തിരികെ -1;
}

#endif
#അല്ലെങ്കിൽ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
സ്ഥിതം പൂർണ്ണസംഖ്യ rt_get_caller_pc(addr_t *paddr, rt_frame *f, പൂർണ്ണസംഖ്യ level)
{
    എങ്കിൽ (level)
        തിരികെ -1;
    *paddr = f->ip;
    തിരികെ 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC ശൂന്യം *dlopen(സ്ഥിരം അക്ഷരം *filename, പൂർണ്ണസംഖ്യ flag)
{
    തിരികെ ശൂന്യ;
}

ST_FUNC ശൂന്യം dlclose(ശൂന്യം *p)
{
}

ST_FUNC സ്ഥിരം അക്ഷരം *dlerror(ശൂന്യം)
{
    തിരികെ "error";
}

തരനിർവചനം ഘടന TCCSyms {
    അക്ഷരം *str;
    ശൂന്യം *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
സ്ഥിതം TCCSyms tcc_syms[] = {
#എങ്കിൽ !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { ശൂന്യ, ശൂന്യ },
};

ST_FUNC ശൂന്യം *dlsym(ശൂന്യം *handle, സ്ഥിരം അക്ഷരം *ചിഹ്നം)
{
    TCCSyms *p;
    p = tcc_syms;
    ആകുമ്പോൾ (p->str != ശൂന്യ) {
        എങ്കിൽ (!strcmp(p->str, ചിഹ്നം))
            തിരികെ p->ptr;
        p++;
    }
    തിരികെ ശൂന്യ;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
