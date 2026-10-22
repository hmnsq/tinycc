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

#ଅନ୍ତର୍ଭାଵ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    ସଂଘ {
	ସଂରଚନା {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    ଅକ୍ଷର *stab_str;
	};
	ସଂରଚନା {
	    unsigned ଅକ୍ଷର *dwarf_ଧାଡ଼ି;
	    unsigned ଅକ୍ଷର *dwarf_ଧାଡ଼ି_end;
	    unsigned ଅକ୍ଷର *dwarf_ଧାଡ଼ି_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    ଅକ୍ଷର *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    ଶୂନ୍ୟ *bounds_start;
    ଶୂନ୍ୟ *ଶୀର୍ଷ_func;
    ସଂରଚନା rt_context *next;
    // 10 * PTR_SIZE
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_callers;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା dwarf;
} rt_context;

/* linked list of rt_contexts */
ସ୍ଥିର rt_context *g_rc;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା signal_set;
ସ୍ଥିର ଶୂନ୍ୟ set_exception_handler(ଶୂନ୍ୟ);
#endif /* def CONFIG_TCC_BACKTRACE */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

ସ୍ଥିର TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ସ୍ଥିର rt_sem);
ସ୍ଥିର ଶୂନ୍ୟ rt_wait_sem(ଶୂନ୍ୟ) { WAIT_SEM(&rt_sem); }
ସ୍ଥିର ଶୂନ୍ୟ rt_post_sem(ଶୂନ୍ୟ) { POST_SEM(&rt_sem); }
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level);
ସ୍ଥିର ଶୂନ୍ୟ rt_exit(rt_frame *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା protect_pages(ଶୂନ୍ୟ *ptr, unsigned long length, ପୂର୍ଣ୍ଣସଂଖ୍ୟା mode);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_relocate_ex(TCCState *s1, ଶୂନ୍ୟ *ptr, unsigned ptr_diff);
ସ୍ଥିର ଶୂନ୍ୟ st_link(TCCState *s1);
ସ୍ଥିର ଶୂନ୍ୟ st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_backtrace(rt_frame *f, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap);
#endif
#ifdef _WIN64
ସ୍ଥିର ଶୂନ୍ୟ *win64_add_function_table(TCCState *s1);
ସ୍ଥିର ଶୂନ୍ୟ win64_del_function_table(ଶୂନ୍ୟ *);
#endif

#ଯଦି !defined PAGESIZE
# ଯଦି defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ଅନ୍ୟଥା
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ଯଦି !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#ଯଦି defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_mem(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size)
{
    ଶୂନ୍ୟ *ptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    ଶୂନ୍ୟ *prw;
    ଅକ୍ଷର tmpfname[] = "/tmp/.tccrunXXXXXX";
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(ଖାଲି, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((ଅକ୍ଷର*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ଯଦି (ptr == MAP_FAILED || prw == MAP_FAILED)
	ଫେରନ୍ତୁ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (ଅକ୍ଷର*)prw - (ଅକ୍ଷର*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#ନଚେତଯଦି CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ଖାଲି, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    ଯଦି (!ptr)
        ଫେରନ୍ତୁ tcc_error_noabort("tccrun: could not allocate memory");
#ଅନ୍ୟଥା
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    ଫେରନ୍ତୁ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_relocate(TCCState *s1)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size, ret, ptr_diff;

    ଯଦି (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    ଯଦି (s1->do_backtrace)
        tcc_add_ପ୍ରତୀକ(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, ଖାଲି, 0);
    ଯଦି (size < 0)
        ଫେରନ୍ତୁ -1;
    ptr_diff = rt_mem(s1, size);
    ଯଦି (ptr_diff < 0)
        ଫେରନ୍ତୁ -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    ଯଦି (ret == 0)
        st_link(s1);
    ଫେରନ୍ତୁ ret;
}

ST_FUNC ଶୂନ୍ୟ tcc_run_free(TCCState *s1)
{
    unsigned size;
    ଶୂନ୍ୟ *ptr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    /* free any loaded DLLs */
    ପାଇଁ ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ଯଦି ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ଅନ୍ୟଥା
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    ଯଦି (ଖାଲି == ptr)
        ଫେରନ୍ତୁ;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#ନଚେତଯଦି CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#ଅନ୍ୟଥା
    /* unprotect memory to make it usable for malloc again */
    protect_pages((ଶୂନ୍ୟ*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_run(TCCState *s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*prog_main)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଅକ୍ଷର **, ଅକ୍ଷର **), ret;
    ଅଚଳ ଅକ୍ଷର *ଶୀର୍ଷ_sym;
    jmp_buf main_jb;

#ଯଦି defined(__APPLE__)
    ବାହ୍ୟ ଅକ୍ଷର ***_NSGetEnviron(ଶୂନ୍ୟ);
    ଅକ୍ଷର **envp = *_NSGetEnviron();
#ନଚେତଯଦି defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    ବାହ୍ୟ ଅକ୍ଷର **environ;
    ଅକ୍ଷର **envp = environ;
#ଅନ୍ୟଥା
    ଅକ୍ଷର **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    ଯଦି ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ଫେରନ୍ତୁ 0;

    tcc_add_ପ୍ରତୀକ(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", ଶୀର୍ଷ_sym = "main";
    ଯଦି (s1->elf_entryname)
        s1->run_main = ଶୀର୍ଷ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    ଯଦି (tcc_relocate(s1) < 0)
        ଫେରନ୍ତୁ -1;

    prog_main = (ଶୂନ୍ୟ*)get_sym_addr(s1, s1->run_main, 1, 1);
    ଯଦି ((addr_t)-1 == (addr_t)prog_main)
        ଫେରନ୍ତୁ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ଯଦି (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ଫେରନ୍ତୁ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_ପ୍ରତୀକ(s1, ଶୀର୍ଷ_sym));
    ଯଦି (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ଅନ୍ୟଥା ଯଦି (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ଯଦି (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ଫେରନ୍ତୁ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ସ୍ଥିର ଶୂନ୍ୟ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sym_index, end_sym = s->data_offset / ଆକାର (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    ପାଇଁ (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        ଅଚଳ ଅକ୍ଷର *name = (ଅକ୍ଷର *)s->link->data + sym->st_name;
        ଯଦି (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ଜାରି;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_ମୂଲ୍ୟ, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ସ୍ଥିର ଶୂନ୍ୟ cleanup_sections(TCCState *s1)
{
    ସଂରଚନା { Section **secs; ପୂର୍ଣ୍ଣସଂଖ୍ୟା nb_secs; } *p = (ଶୂନ୍ୟ*)&s1->sections;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, f = 2;
    କର {
        ପାଇଁ (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ଯଦି (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } ଅନ୍ୟଥା {
                free_section(s), tcc_free(s), p->secs[i] = ଖାଲି;
            }
        }
    } ଯେତେବେଳେ (++p, f);
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
# ଅନ୍ୟଥା
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_relocate_ex(TCCState *s1, ଶୂନ୍ୟ *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    ଯଦି (ଖାଲି == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, ଖାଲି);
#ଅନ୍ୟଥା
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    ଯଦି (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    ଯଦି (s1->nb_errors)
        ଫେରନ୍ତୁ -1;
    ଯଦି (copy == 3)
        ଫେରନ୍ତୁ 0;

    ପାଇଁ (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        ପାଇଁ(i = 1; i < s1->nb_sections; i++) {
            ସ୍ଥିର ଅଚଳ ଅକ୍ଷର shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ଯଦି (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ଜାରି;
            length = s->data_offset;
            ଯଦି (copy == 2) {
                ଯଦି (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                ଜାରି;
            }
            ଯଦି (copy) { /* final step: copy section data to memory */
                ଯଦି (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (ଶୂନ୍ୟ*)s->sh_addr, length, s->sh_addralign);
                ptr = (ଶୂନ୍ୟ*)s->sh_addr;
                ଯଦି (k == 0)
                    ptr = (ଶୂନ୍ୟ*)(s->sh_addr + ptr_diff);
                ଯଦି (ଖାଲି == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                ଅନ୍ୟଥା
                    memcpy(ptr, s->data, length);
                ଜାରି;
            }

            ଯଦି ((s->sh_flags & SHF_TLS) && length)
                ଫେରନ୍ତୁ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ଯଦି (++n == 1) {
#ଯଦି defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ଯଦି (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                ଯଦି (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        ଯଦି (copy == 2) { /* set permissions */
            ଯଦି (n == 0) /* no data  */
                ଜାରି;
#ifdef CONFIG_SELINUX
            ଯଦି (k == 0) /* SHF_EXECINSTR has its own mapping */
                ଜାରି;
#endif
            f = k;
            ଯଦି (f >= CONFIG_RUNMEM_RO) {
                ଯଦି (f != 0)
                    ଜାରି;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ଯଦି (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (ଶୂନ୍ୟ*)addr, (unsigned)n);
            }
            ଯଦି (protect_pages((ଶୂନ୍ୟ*)addr, n, f) < 0)
                ଫେରନ୍ତୁ tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#ଅନ୍ୟଥା
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    ଯଦି (0 == mem)
        ଫେରନ୍ତୁ PAGEALIGN(offset);

    ଯଦି (++copy == 2) {
        ଯାଅ redo;
    }
    ଯଦି (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        ଯାଅ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ଯଦି (s1->nb_errors)
        ଯାଅ redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#ଅନ୍ୟଥା
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    ଯାଅ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା protect_pages(ଶୂନ୍ୟ *ptr, unsigned long length, ପୂର୍ଣ୍ଣସଂଖ୍ୟା mode)
{
#ifdef _WIN32
    ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    ଯଦି (!VirtualProtect(ptr, length, protect[mode], &old))
        ଫେରନ୍ତୁ -1;
#ଅନ୍ୟଥା
    ସ୍ଥିର ଅଚଳ unsigned ଅକ୍ଷର protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ଯଦି (mprotect(ptr, length, protect[mode]))
        ଫେରନ୍ତୁ -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#ଯଦି (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    ଯଦି (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#ଅନ୍ୟଥା
        ଶୂନ୍ୟ __clear_cache(ଶୂନ୍ୟ *beginning, ଶୂନ୍ୟ *end);
        __clear_cache(ptr, (ଅକ୍ଷର *)ptr + length);
#endif
    }
#endif
    ଫେରନ୍ତୁ 0;
}

#ifdef _WIN64
ସ୍ଥିର ଶୂନ୍ୟ *win64_add_function_table(TCCState *s1)
{
    ଶୂନ୍ୟ *p = ଖାଲି;
    ଯଦି (s1->uw_pdata) {
        p = (ଶୂନ୍ୟ*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / ଆକାର (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ଖାଲି;
    }
    ଫେରନ୍ତୁ p;
}

ସ୍ଥିର ଶୂନ୍ୟ win64_del_function_table(ଶୂନ୍ୟ *p)
{
    ଯଦି (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

ସ୍ଥିର ଶୂନ୍ୟ bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ଯଦି (!s1->do_backtrace)
        ଫେରନ୍ତୁ;
    rc = tcc_get_ପ୍ରତୀକ(s1, "__rt_info");
    ଯଦି (!rc)
        ଫେରନ୍ତୁ;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (ଅକ୍ଷର *)symtab_section->link->data;
    ଯଦି (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    ଯଦି (s1->do_bounds_check) {
        ଶୂନ୍ୟ *p;
        ଯଦି ((p = tcc_get_ପ୍ରତୀକ(s1, "__bound_init")))
            ((ଶୂନ୍ୟ(*)(ଶୂନ୍ୟ*,ପୂର୍ଣ୍ଣସଂଖ୍ୟା))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    ଯଦି (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

ସ୍ଥିର ଶୂନ୍ୟ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ସ୍ଥିର ଶୂନ୍ୟ ptr_unlink(ଶୂନ୍ୟ *list, ଶୂନ୍ୟ *e, unsigned next)
{
    ଶୂନ୍ୟ **pp, **nn, *p;
    ପାଇଁ (pp = list; !!(p = *pp); pp = nn) {
        nn = (ଶୂନ୍ୟ*)((ଅକ୍ଷର*)p + next); /* nn = &p->next; */
        ଯଦି (p == e) {
            *pp = *nn;
            ଭାଙ୍ଗ;
        }
    }
}

ସ୍ଥିର ଶୂନ୍ୟ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI ଶୂନ୍ୟ *_tcc_setjmp(TCCState *s1, ଶୂନ୍ୟ *p_jmp_buf, ଶୂନ୍ୟ *func, ଶୂନ୍ୟ *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    ଯଦି (s1->rc)
        s1->rc->ଶୀର୍ଷ_func = func;
#endif
    ଫେରନ୍ତୁ p_jmp_buf;
}

LIBTCCAPI ଶୂନ୍ୟ tcc_set_backtrace_func(TCCState *s1, ଶୂନ୍ୟ *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

ସ୍ଥିର TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା level;
    addr_t pc;

    s = g_s1;
    ଯଦି (ଖାଲି == s || ଖାଲି == s->next) {
        /* play it safe in the simple case when there is only one state */
        ଫେରନ୍ତୁ s;
    }
    ପାଇଁ (level = 0; level < 8; ++level) {
        ଯଦି (rt_get_caller_pc(&pc, f, level) < 0)
            ଭାଙ୍ଗ;
        ପାଇଁ (s = g_s1; s; s = s->next) {
            ଯଦି (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                ଫେରନ୍ତୁ s;
        }
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର ଶୂନ୍ୟ rt_exit(rt_frame *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    ଯଦି (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        ଯଦି (f->fp) { /* called from signal */
            ଶୂନ୍ୟ *p = tcc_get_ପ୍ରତୀକ(s, "__bound_exit");
            ଯଦି (p)
                ((ଶୂନ୍ୟ (*)(ଶୂନ୍ୟ))p)();
        }
#endif
        ଯଦି (code == 0)
            code = RT_EXIT_ZERO;
        ((ଶୂନ୍ୟ(*)(ଶୂନ୍ୟ*,ପୂର୍ଣ୍ଣସଂଖ୍ୟା))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#ଅନ୍ୟଥା // if defined CONFIG_TCC_BACKTRACE_ONLY
ସ୍ଥିର ଶୂନ୍ୟ rt_exit(rt_frame *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_vprintf(ଅଚଳ ଅକ୍ଷର *fmt, va_list ap)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ଫେରନ୍ତୁ ret;
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_printf(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ଫେରନ୍ତୁ r;
}

ସ୍ଥିର ଅକ୍ଷର *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    ପାଇଁ (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା type = ELFW(ST_TYPE)(esym->st_info);
        ଯଦି ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_ମୂଲ୍ୟ
            && wanted_pc < esym->st_ମୂଲ୍ୟ + esym->st_size) {
            *func_addr = esym->st_ମୂଲ୍ୟ;
            ଫେରନ୍ତୁ rc->elf_str + esym->st_name;
        }
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା bt_info
{
    ଅକ୍ଷର file[100];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
    ଅକ୍ଷର func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ସ୍ଥିର addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ଅକ୍ଷର func_name[128];
    addr_t func_addr, last_pc, pc;
    ଅଚଳ ଅକ୍ଷର *incl_files[INCLUDE_ଗଦା_SIZE];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା incl_index, last_incl_index, len, last_ଧାଡ଼ି_ଅଙ୍କ, i;
    ଅଚଳ ଅକ୍ଷର *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_ଧାଡ଼ି_ଅଙ୍କ = 1;
    last_incl_index = 0;

    ପାଇଁ (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_ମୂଲ୍ୟ;

        ବାଛ(sym->n_type) {
        ସ୍ଥିତି N_SLINE:
            ଯଦି (func_addr)
                ଯାଅ rel_pc;
        ସ୍ଥିତି N_SO:
        ସ୍ଥିତି N_SOL:
            ଯାଅ abs_pc;
        ସ୍ଥିତି N_FUN:
            ଯଦି (sym->n_strx == 0) /* end of function */
                ଯାଅ rel_pc;
        abs_pc:
#ଯଦି PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            ଯାଅ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ଯଦି (pc >= wanted_pc && wanted_pc >= last_pc)
                ଯାଅ found;
            ଭାଙ୍ଗ;
        }

        ବାଛ(sym->n_type) {
            /* function start or end */
        ସ୍ଥିତି N_FUN:
            ଯଦି (sym->n_strx == 0)
                ଯାଅ reset_func;
            p = strchr(str, ':');
            ଯଦି (0 == p || (len = p - str + 1, len > ଆକାର func_name))
                len = ଆକାର func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ଭାଙ୍ଗ;
            /* line number info */
        ସ୍ଥିତି N_SLINE:
            last_pc = pc;
            last_ଧାଡ଼ି_ଅଙ୍କ = sym->n_desc;
            last_incl_index = incl_index;
            ଭାଙ୍ଗ;
            /* include files */
        ସ୍ଥିତି N_BINCL:
            ଯଦି (incl_index < INCLUDE_ଗଦା_SIZE)
                incl_files[incl_index++] = str;
            ଭାଙ୍ଗ;
        ସ୍ଥିତି N_EINCL:
            ଯଦି (incl_index > 1)
                incl_index--;
            ଭାଙ୍ଗ;
            /* start/end of translation unit */
        ସ୍ଥିତି N_SO:
            incl_index = 0;
            ଯଦି (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                ଯଦି (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            ଭାଙ୍ଗ;
            /* alternative file name (from #line or #include directives) */
        ସ୍ଥିତି N_SOL:
            ଯଦି (incl_index)
                incl_files[incl_index-1] = str;
            ଭାଙ୍ଗ;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    ଯଦି (i > 0) {
        pstrcpy(bi->file, ଆକାର bi->file, incl_files[--i]);
        bi->ଧାଡ଼ି = last_ଧାଡ଼ି_ଅଙ୍କ;
    }
    pstrcpy(bi->func, ଆକାର bi->func, func_name);
    bi->func_pc = func_addr;
    ଫେରନ୍ତୁ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	ବାଛ (entry_format[j].form) { \
	ସ୍ଥିତି DW_FORM_data1: (ln) += 1; ଭାଙ୍ଗ; \
	ସ୍ଥିତି DW_FORM_data2: (ln) += 2; ଭାଙ୍ଗ; \
	ସ୍ଥିତି DW_FORM_data4: (ln) += 3; ଭାଙ୍ଗ; \
	ସ୍ଥିତି DW_FORM_data8: (ln) += 8; ଭାଙ୍ଗ; \
	ସ୍ଥିତି DW_FORM_data16: (ln) += 16; ଭାଙ୍ଗ; \
	ସ୍ଥିତି DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); ଭାଙ୍ଗ; \
	ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ଯାଅ next_ଧାଡ଼ି; \
	}

ସ୍ଥିର addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned ଅକ୍ଷର *ln;
    unsigned ଅକ୍ଷର *cp;
    unsigned ଅକ୍ଷର *end;
    unsigned ଅକ୍ଷର *opcode_length;
    unsigned long long size;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା length;
    unsigned ଅକ୍ଷର version;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା min_insn_length;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା max_ops_per_insn;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_base;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି_range;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା opcode_base;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା opindex;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା col;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
    unsigned long long ମୂଲ୍ୟ;
    ସଂରଚନା {
	unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା type;
	unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା form;
    } entry_format[256];
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା dir_size;
#ଯଦି 0
    ଅକ୍ଷର *dirs[DIR_TABLE_SIZE];
#endif
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା filename_size;
    ସଂରଚନା /*dwarf_filename_struct*/ {
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା dir_entry;
        ଅକ୍ଷର *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି;
    ଅକ୍ଷର *filename;
    ଅକ୍ଷର *function;

    filename = ଖାଲି;
    function = ଖାଲି;
    func_addr = 0;
    ଧାଡ଼ି = 0;

    ln = rc->dwarf_ଧାଡ଼ି;
    ଯେତେବେଳେ (ln < rc->dwarf_ଧାଡ଼ି_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        ଧାଡ଼ି = 1;
        filename = ଖାଲି;
        function = ଖାଲି;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_ଧାଡ଼ି_end);
	ଯଦି (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_ଧାଡ଼ି_end);
	end = ln + size;
	ଯଦି (end < ln || end > rc->dwarf_ଧାଡ଼ି_end)
	    ଭାଙ୍ଗ;
	version = dwarf_read_2(ln, end);
	ଯଦି (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	ଅନ୍ୟଥା
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	ଯଦି (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	ଅନ୍ୟଥା
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	ଧାଡ଼ି_base = dwarf_read_1(ln, end);
	ଧାଡ଼ି_base |= ଧାଡ଼ି_base >= 0x80 ? ~0xff : 0;
	ଧାଡ଼ି_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	ଯଦି (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    ପାଇଁ (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    ପାଇଁ (i = 0; i < dir_size; i++) {
		ପାଇଁ (j = 0; j < col; j++) {
		    ଯଦି (entry_format[j].type == DW_LNCT_path) {
		        ଯଦି (entry_format[j].form != DW_FORM_ଧାଡ଼ି_strp)
			    ଯାଅ next_ଧାଡ଼ି;
#ଯଦି 0
		        ମୂଲ୍ୟ = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ଯଦି (i < DIR_TABLE_SIZE)
		            dirs[i] = (ଅକ୍ଷର *)rc->dwarf_ଧାଡ଼ି_str + ମୂଲ୍ୟ;
#ଅନ୍ୟଥା
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    ଅନ୍ୟଥା 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    ପାଇଁ (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    ପାଇଁ (i = 0; i < filename_size; i++)
		ପାଇଁ (j = 0; j < col; j++) {
		    ଯଦି (entry_format[j].type == DW_LNCT_path) {
			ଯଦି (entry_format[j].form != DW_FORM_ଧାଡ଼ି_strp)
			    ଯାଅ next_ଧାଡ଼ି;
			ମୂଲ୍ୟ = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        ଯଦି (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(ଅକ୍ଷର *)rc->dwarf_ଧାଡ଼ି_str + ମୂଲ୍ୟ;
	            }
		    ଅନ୍ୟଥା ଯଦି (entry_format[j].type == DW_LNCT_directory_index) {
			ବାଛ (entry_format[j].form) {
			ସ୍ଥିତି DW_FORM_data1: ମୂଲ୍ୟ = dwarf_read_1(ln, end); ଭାଙ୍ଗ;
			ସ୍ଥିତି DW_FORM_data2: ମୂଲ୍ୟ = dwarf_read_2(ln, end); ଭାଙ୍ଗ;
			ସ୍ଥିତି DW_FORM_data4: ମୂଲ୍ୟ = dwarf_read_4(ln, end); ଭାଙ୍ଗ;
			ସ୍ଥିତି DW_FORM_udata: ମୂଲ୍ୟ = dwarf_read_uleb128(&ln, end); ଭାଙ୍ଗ;
			ପୂର୍ବନିର୍ଦ୍ଧାରିତ: ଯାଅ next_ଧାଡ଼ି;
			}
		        ଯଦି (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = ମୂଲ୍ୟ;
		    }
		    ଅନ୍ୟଥା 
			dwarf_ignore_type(ln, end);
	    }
	}
	ଅନ୍ୟଥା {
	    ଯେତେବେଳେ ((dwarf_read_1(ln, end))) {
#ଯଦି 0
		ଯଦି (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (ଅକ୍ଷର *)ln - 1;
#endif
		ଯେତେବେଳେ (dwarf_read_1(ln, end)) {}
	    }
	    ଯେତେବେଳେ ((dwarf_read_1(ln, end))) {
		ଯଦି (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (ଅକ୍ଷର *)ln - 1;
		    ଯେତେବେଳେ (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		ଅନ୍ୟଥା {
		    ଯେତେବେଳେ (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	ଯଦି (filename_size >= 1)
	    filename = filename_table[0].name;
	ଯେତେବେଳେ (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    ଯଦି (i >= opcode_base) {
	        ଯଦି (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / ଧାଡ଼ି_range) * min_insn_length;
		ଅନ୍ୟଥା {
		    pc += (opindex + (i - opcode_base) / ଧାଡ଼ି_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / ଧାଡ଼ି_range) %
			       max_ops_per_insn;
		}
		i = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((i - opcode_base) % ଧାଡ଼ି_range) + ଧାଡ଼ି_base;
check_pc:
		ଯଦି (pc >= wanted_pc && wanted_pc >= last_pc)
		    ଯାଅ found;
		ଧାଡ଼ି += i;
	    }
	    ଅନ୍ୟଥା {
	        ବାଛ (i) {
	        ସ୍ଥିତି 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    ଯଦି (len == 0)
		        ଯାଅ next_ଧାଡ଼ି;
		    ବାଛ (dwarf_read_1(cp, end)) {
		    ସ୍ଥିତି DW_LNE_end_sequence:
		        ଭାଙ୍ଗ;
		    ସ୍ଥିତି DW_LNE_set_address:
#ଯଦି PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#ଅନ୍ୟଥା
		        pc = dwarf_read_8(cp, end);
#endif
#ଯଦି defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        ଭାଙ୍ଗ;
		    ସ୍ଥିତି DW_LNE_define_file: /* deprecated */
		        ଯଦି (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (ଅକ୍ଷର *)ln - 1;
		            ଯେତେବେଳେ (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        ଅନ୍ୟଥା {
		            ଯେତେବେଳେ (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        ଭାଙ୍ଗ;
		    ସ୍ଥିତି DW_LNE_hi_user - 1:
		        function = (ଅକ୍ଷର *)cp;
		        func_addr = pc;
		        ଭାଙ୍ଗ;
		    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		        ଭାଙ୍ଗ;
		    }
		    ଭାଙ୍ଗ;
	        ସ୍ଥିତି DW_LNS_advance_pc:
		    ଯଦି (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    ଅନ୍ୟଥା {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    ଯାଅ check_pc;
	        ସ୍ଥିତି DW_LNS_advance_ଧାଡ଼ି:
		    ଧାଡ଼ି += dwarf_read_sleb128(&ln, end);
		    ଭାଙ୍ଗ;
	        ସ୍ଥିତି DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    ଯଦି (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    ଭାଙ୍ଗ;
	        ସ୍ଥିତି DW_LNS_const_add_pc:
		    ଯଦି (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / ଧାଡ଼ି_range) * min_insn_length;
		    ଅନ୍ୟଥା {
		        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା off = (255 - opcode_base) / ଧାଡ଼ି_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    ଯାଅ check_pc;
	        ସ୍ଥିତି DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    ଯାଅ check_pc;
	        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		    ପାଇଁ (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    ଭାଙ୍ଗ;
		}
	    }
	}
next_ଧାଡ଼ି:
	ln = end;
    }
    filename = function = ଖାଲି, func_addr = 0;
found:
    ଯଦି (filename)
        pstrcpy(bi->file, ଆକାର bi->file, filename), bi->ଧାଡ଼ି = ଧାଡ଼ି;
    ଯଦି (function)
        pstrcpy(bi->func, ଆକାର bi->func, function);
    bi->func_pc = func_addr;
    ଫେରନ୍ତୁ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
ସ୍ଥିର
#endif
ପୂର୍ଣ୍ଣସଂଖ୍ୟା _tcc_backtrace(rt_frame *f, ଅଚଳ ଅକ୍ଷର *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    ଅକ୍ଷର skip[40], ସନ୍ଦେଶ[200];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, level, ret, n, one;
    ଅଚଳ ଅକ୍ଷର *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ଯଦି (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ଯଦି (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(ସନ୍ଦେଶ, ଆକାର ସନ୍ଦେଶ, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ଯଦି (rc) {
        ଯଦି (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ଯଦି (rc->ଅଙ୍କ_callers)
            n = rc->ଅଙ୍କ_callers;
    }

    ପାଇଁ (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ଯଦି (ret == -1)
            ଭାଙ୍ଗ;
        memset(&bi, 0, ଆକାର bi);
        ପାଇଁ (rc2 = rc; rc2; rc2 = rc2->next) {
            ଯଦି (getinfo(rc2, pc, &bi))
                ଭାଙ୍ଗ;
            /* we try symtab symbols (no line number info) */
            ଯଦି (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, ଆକାର bi.func, a);
                ଭାଙ୍ଗ;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ଯଦି (skip[0] && strstr(bi.file, skip))
            ଜାରି;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            ଯଦି (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (ଶୂନ୍ୟ*)pc,
                    bi.file[0] ? bi.file : ଖାଲି,
                    bi.ଧାଡ଼ି,
                    bi.func[0] ? bi.func : ଖାଲି,
                    level == 0 ? ସନ୍ଦେଶ : ଖାଲି
                    );
                ଯଦି (ret == 0)
                    ଭାଙ୍ଗ;
                ଯାଅ check_break;
            }
        }
#endif
        ଯଦି (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.ଧାଡ଼ି);
        } ଅନ୍ୟଥା {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ଯଦି (level == 0) {
            rt_printf(": %s", ସନ୍ଦେଶ);
            ଯଦି (one)
                ଭାଙ୍ଗ;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        ଯଦି (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->ଶୀର୍ଷ_func)
            ଭାଙ୍ଗ;
        ++level;
    }
    rt_post_sem();
    ଫେରନ୍ତୁ 0;
}

/* emit a run time error at position 'pc' */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_error(rt_frame *f, ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap; ଅକ୍ଷର ସନ୍ଦେଶ[200]; ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
    va_start(ap, fmt);
    snprintf(ସନ୍ଦେଶ, ଆକାର ସନ୍ଦେଶ, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, ସନ୍ଦେଶ, ap);
    va_end(ap);
    ଫେରନ୍ତୁ ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ଅନ୍ୟଥା
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
ସ୍ଥିର ଶୂନ୍ୟ rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#ଯଦି defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#ନଚେତଯଦି defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#ନଚେତଯଦି defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#ନଚେତଯଦି defined __i386__
# ଯଦି defined(__APPLE__)
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
# ଅନ୍ୟଥା
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#ନଚେତଯଦି defined(__x86_64__)
# ଯଦି defined(__APPLE__)
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
# ଅନ୍ୟଥା
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#ନଚେତଯଦି defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ନଚେତଯଦି defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#ନଚେତଯଦି defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ନଚେତଯଦି defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#ନଚେତଯଦି defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#ନଚେତଯଦି defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#ନଚେତଯଦି defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ନଚେତଯଦି defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#ନଚେତଯଦି defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#ନଚେତଯଦି defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#ନଚେତଯଦି defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
ସ୍ଥିର ଶୂନ୍ୟ sig_error(ପୂର୍ଣ୍ଣସଂଖ୍ୟା signum, siginfo_t *siginf, ଶୂନ୍ୟ *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    ବାଛ(signum) {
    ସ୍ଥିତି SIGFPE:
        ବାଛ(siginf->si_code) {
        ସ୍ଥିତି FPE_INTDIV:
        ସ୍ଥିତି FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            rt_error(&f, "floating point exception");
            ଭାଙ୍ଗ;
        }
        ଭାଙ୍ଗ;
    ସ୍ଥିତି SIGBUS:
    ସ୍ଥିତି SIGSEGV:
        rt_error(&f, "invalid memory access");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି SIGILL:
        rt_error(&f, "illegal instruction");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି SIGABRT:
        rt_error(&f, "abort() called");
        ଭାଙ୍ଗ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        rt_error(&f, "caught signal %d", signum);
        ଭାଙ୍ଗ;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ଖାଲି);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
ସ୍ଥିର ଶୂନ୍ୟ set_exception_handler(ଶୂନ୍ୟ)
{
    ସଂରଚନା sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ଯଦି 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ଖାଲି);
    sigaction(SIGILL, &sigact, ଖାଲି);
    sigaction(SIGSEGV, &sigact, ଖାଲି);
    sigaction(SIGBUS, &sigact, ଖାଲି);
    sigaction(SIGABRT, &sigact, ଖାଲି);
#ଯଦି 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ସ୍ଥିର unsigned ଅକ୍ଷର ଗଦା[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ଗଦା;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ଖାଲି);
    }
#endif
}

#ଅନ୍ୟଥା /* WIN32 */

/* signal handler for fatal errors */
ସ୍ଥିର long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    ବାଛ (code = ex_info->ExceptionRecord->ExceptionCode) {
    ସ୍ଥିତି EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି EXCEPTION_ଗଦା_OVERFLOW:
        rt_error(&f, "stack overflow");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ଭାଙ୍ଗ;
    ସ୍ଥିତି EXCEPTION_BREAKPOINT:
    ସ୍ଥିତି EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ଫେରନ୍ତୁ EXCEPTION_CONTINUE_ସନ୍ଧାନ;
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        rt_error(&f, "caught exception %08x", code);
        ଭାଙ୍ଗ;
    }
    rt_exit(&f, 255);
    ଫେରନ୍ତୁ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ସ୍ଥିର ଶୂନ୍ୟ set_exception_handler(ଶୂନ୍ୟ)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#ଅନ୍ୟଥା
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ଯଦି defined(__i386__) || defined(__x86_64__)
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଯଦି (level == 0) {
        *paddr = rc->ip;
    } ଅନ୍ୟଥା {
        addr_t fp = rc->fp;
        ଯେତେବେଳେ (1) {
            ଯଦି (fp < 0x1000)
                ଫେରନ୍ତୁ -1;
            ଯଦି (0 == --level)
                ଭାଙ୍ଗ;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ଫେରନ୍ତୁ 0;
}

/* XXX: only supports linux/bsd */
#ନଚେତଯଦି defined(__arm__) && !defined(_WIN32)
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଯଦି (level == 0) {
        *paddr = rc->ip;
    } ଅନ୍ୟଥା {
        addr_t fp = rc->fp;
        ଯେତେବେଳେ (1) {
            ଯଦି (fp < 0x1000)
                ଫେରନ୍ତୁ -1;
            ଯଦି (0 == --level)
                ଭାଙ୍ଗ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined(__aarch64__)
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଯଦି (level == 0) {
        *paddr = rc->ip;
    } ଅନ୍ୟଥା {
        addr_t fp = rc->fp;
        ଯେତେବେଳେ (1) {
            ଯଦି (fp < 0x1000)
                ଫେରନ୍ତୁ -1;
            ଯଦି (0 == --level)
                ଭାଙ୍ଗ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ଫେରନ୍ତୁ 0;
}

#ନଚେତଯଦି defined(__riscv)
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଯଦି (level == 0) {
        *paddr = rc->ip;
    } ଅନ୍ୟଥା {
        addr_t fp = rc->fp;
        ଯେତେବେଳେ (1) {
            ଯଦି (fp < 0x1000)
                ଫେରନ୍ତୁ -1;
            ଯଦି (0 == --level)
                ଭାଙ୍ଗ;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ଫେରନ୍ତୁ 0;
}

#ଅନ୍ୟଥା
#warning add arch specific rt_get_caller_pc()
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଫେରନ୍ତୁ -1;
}

#endif
#ଅନ୍ୟଥା // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା rt_get_caller_pc(addr_t *paddr, rt_frame *f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା level)
{
    ଯଦି (level)
        ଫେରନ୍ତୁ -1;
    *paddr = f->ip;
    ଫେରନ୍ତୁ 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC ଶୂନ୍ୟ *dlopen(ଅଚଳ ଅକ୍ଷର *filename, ପୂର୍ଣ୍ଣସଂଖ୍ୟା flag)
{
    ଫେରନ୍ତୁ ଖାଲି;
}

ST_FUNC ଶୂନ୍ୟ dlclose(ଶୂନ୍ୟ *p)
{
}

ST_FUNC ଅଚଳ ଅକ୍ଷର *dlerror(ଶୂନ୍ୟ)
{
    ଫେରନ୍ତୁ "error";
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TCCSyms {
    ଅକ୍ଷର *str;
    ଶୂନ୍ୟ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ସ୍ଥିର TCCSyms tcc_syms[] = {
#ଯଦି !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { ଖାଲି, ଖାଲି },
};

ST_FUNC ଶୂନ୍ୟ *dlsym(ଶୂନ୍ୟ *handle, ଅଚଳ ଅକ୍ଷର *ପ୍ରତୀକ)
{
    TCCSyms *p;
    p = tcc_syms;
    ଯେତେବେଳେ (p->str != ଖାଲି) {
        ଯଦି (!strcmp(p->str, ପ୍ରତୀକ))
            ଫେରନ୍ତୁ p->ptr;
        p++;
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
