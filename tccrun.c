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

#અન્તર્ભાવ "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
પ્રકારવ્યાખ્યા સંરચના rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    સંઘ {
	સંરચના {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    અક્ષર *stab_str;
	};
	સંરચના {
	    unsigned અક્ષર *dwarf_લીટી;
	    unsigned અક્ષર *dwarf_લીટી_end;
	    unsigned અક્ષર *dwarf_લીટી_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    અક્ષર *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    શૂન્ય *bounds_start;
    શૂન્ય *ટોચ_func;
    સંરચના rt_context *next;
    // 10 * PTR_SIZE
    પૂર્ણાંક અંક_callers;
    પૂર્ણાંક dwarf;
} rt_context;

/* linked list of rt_contexts */
સ્થિર rt_context *g_rc;
સ્થિર પૂર્ણાંક signal_set;
સ્થિર શૂન્ય set_exception_handler(શૂન્ય);
#endif /* def CONFIG_TCC_BACKTRACE */

પ્રકારવ્યાખ્યા સંરચના rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

સ્થિર TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(સ્થિર rt_sem);
સ્થિર શૂન્ય rt_wait_sem(શૂન્ય) { WAIT_SEM(&rt_sem); }
સ્થિર શૂન્ય rt_post_sem(શૂન્ય) { POST_SEM(&rt_sem); }
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *f, પૂર્ણાંક level);
સ્થિર શૂન્ય rt_exit(rt_frame *f, પૂર્ણાંક code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

સ્થિર પૂર્ણાંક protect_pages(શૂન્ય *ptr, unsigned long length, પૂર્ણાંક mode);
સ્થિર પૂર્ણાંક tcc_relocate_ex(TCCState *s1, શૂન્ય *ptr, unsigned ptr_diff);
સ્થિર શૂન્ય st_link(TCCState *s1);
સ્થિર શૂન્ય st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
સ્થિર પૂર્ણાંક _tcc_backtrace(rt_frame *f, અચલ અક્ષર *fmt, va_list ap);
#endif
#ifdef _WIN64
સ્થિર શૂન્ય *win64_add_function_table(TCCState *s1);
સ્થિર શૂન્ય win64_del_function_table(શૂન્ય *);
#endif

#જો !defined PAGESIZE
# જો defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# નહીંતર
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#જો !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#જો defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

સ્થિર પૂર્ણાંક rt_mem(TCCState *s1, પૂર્ણાંક size)
{
    શૂન્ય *ptr;
    પૂર્ણાંક ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    શૂન્ય *prw;
    અક્ષર tmpfname[] = "/tmp/.tccrunXXXXXX";
    પૂર્ણાંક fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(ખાલી, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((અક્ષર*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    જો (ptr == MAP_FAILED || prw == MAP_FAILED)
	પાછા tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (અક્ષર*)prw - (અક્ષર*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#અથવાજો CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ખાલી, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    જો (!ptr)
        પાછા tcc_error_noabort("tccrun: could not allocate memory");
#નહીંતર
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    પાછા ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI પૂર્ણાંક tcc_relocate(TCCState *s1)
{
    પૂર્ણાંક size, ret, ptr_diff;

    જો (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    જો (s1->do_backtrace)
        tcc_add_પ્રતીક(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, ખાલી, 0);
    જો (size < 0)
        પાછા -1;
    ptr_diff = rt_mem(s1, size);
    જો (ptr_diff < 0)
        પાછા -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    જો (ret == 0)
        st_link(s1);
    પાછા ret;
}

ST_FUNC શૂન્ય tcc_run_free(TCCState *s1)
{
    unsigned size;
    શૂન્ય *ptr;
    પૂર્ણાંક i;

    /* free any loaded DLLs */
    માટે ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        જો ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#નહીંતર
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    જો (ખાલી == ptr)
        પાછા;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#અથવાજો CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#નહીંતર
    /* unprotect memory to make it usable for malloc again */
    protect_pages((શૂન્ય*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI પૂર્ણાંક tcc_run(TCCState *s1, પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક (*prog_main)(પૂર્ણાંક, અક્ષર **, અક્ષર **), ret;
    અચલ અક્ષર *ટોચ_sym;
    jmp_buf main_jb;

#જો defined(__APPLE__)
    બાહ્ય અક્ષર ***_NSGetEnviron(શૂન્ય);
    અક્ષર **envp = *_NSGetEnviron();
#અથવાજો defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    બાહ્ય અક્ષર **environ;
    અક્ષર **envp = environ;
#નહીંતર
    અક્ષર **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    જો ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        પાછા 0;

    tcc_add_પ્રતીક(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", ટોચ_sym = "main";
    જો (s1->elf_entryname)
        s1->run_main = ટોચ_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    જો (tcc_relocate(s1) < 0)
        પાછા -1;

    prog_main = (શૂન્ય*)get_sym_addr(s1, s1->run_main, 1, 1);
    જો ((addr_t)-1 == (addr_t)prog_main)
        પાછા -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    જો (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        પાછા -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_પ્રતીક(s1, ટોચ_sym));
    જો (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } નહીંતર જો (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    જો (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    પાછા ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
સ્થિર શૂન્ય cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    પૂર્ણાંક sym_index, end_sym = s->data_offset / કદ (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    માટે (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        અચલ અક્ષર *name = (અક્ષર *)s->link->data + sym->st_name;
        જો (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ચાલુ;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_કિંમત, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
સ્થિર શૂન્ય cleanup_sections(TCCState *s1)
{
    સંરચના { Section **secs; પૂર્ણાંક nb_secs; } *p = (શૂન્ય*)&s1->sections;
    પૂર્ણાંક i, f = 2;
    કરો {
        માટે (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            જો (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } નહીંતર {
                free_section(s), tcc_free(s), p->secs[i] = ખાલી;
            }
        }
    } જ્યારે (++p, f);
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
# નહીંતર
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
સ્થિર પૂર્ણાંક tcc_relocate_ex(TCCState *s1, શૂન્ય *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    જો (ખાલી == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, ખાલી);
#નહીંતર
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    જો (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    જો (s1->nb_errors)
        પાછા -1;
    જો (copy == 3)
        પાછા 0;

    માટે (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        માટે(i = 1; i < s1->nb_sections; i++) {
            સ્થિર અચલ અક્ષર shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            જો (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ચાલુ;
            length = s->data_offset;
            જો (copy == 2) {
                જો (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                ચાલુ;
            }
            જો (copy) { /* final step: copy section data to memory */
                જો (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (શૂન્ય*)s->sh_addr, length, s->sh_addralign);
                ptr = (શૂન્ય*)s->sh_addr;
                જો (k == 0)
                    ptr = (શૂન્ય*)(s->sh_addr + ptr_diff);
                જો (ખાલી == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                નહીંતર
                    memcpy(ptr, s->data, length);
                ચાલુ;
            }

            જો ((s->sh_flags & SHF_TLS) && length)
                પાછા tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            જો (++n == 1) {
#જો defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                જો (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                જો (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        જો (copy == 2) { /* set permissions */
            જો (n == 0) /* no data  */
                ચાલુ;
#ifdef CONFIG_SELINUX
            જો (k == 0) /* SHF_EXECINSTR has its own mapping */
                ચાલુ;
#endif
            f = k;
            જો (f >= CONFIG_RUNMEM_RO) {
                જો (f != 0)
                    ચાલુ;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            જો (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (શૂન્ય*)addr, (unsigned)n);
            }
            જો (protect_pages((શૂન્ય*)addr, n, f) < 0)
                પાછા tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#નહીંતર
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    જો (0 == mem)
        પાછા PAGEALIGN(offset);

    જો (++copy == 2) {
        જાઓ redo;
    }
    જો (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        જાઓ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    જો (s1->nb_errors)
        જાઓ redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#નહીંતર
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    જાઓ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

સ્થિર પૂર્ણાંક protect_pages(શૂન્ય *ptr, unsigned long length, પૂર્ણાંક mode)
{
#ifdef _WIN32
    સ્થિર અચલ unsigned અક્ષર protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    જો (!VirtualProtect(ptr, length, protect[mode], &old))
        પાછા -1;
#નહીંતર
    સ્થિર અચલ unsigned અક્ષર protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    જો (mprotect(ptr, length, protect[mode]))
        પાછા -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#જો (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    જો (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#નહીંતર
        શૂન્ય __clear_cache(શૂન્ય *beginning, શૂન્ય *end);
        __clear_cache(ptr, (અક્ષર *)ptr + length);
#endif
    }
#endif
    પાછા 0;
}

#ifdef _WIN64
સ્થિર શૂન્ય *win64_add_function_table(TCCState *s1)
{
    શૂન્ય *p = ખાલી;
    જો (s1->uw_pdata) {
        p = (શૂન્ય*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / કદ (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ખાલી;
    }
    પાછા p;
}

સ્થિર શૂન્ય win64_del_function_table(શૂન્ય *p)
{
    જો (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

સ્થિર શૂન્ય bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    જો (!s1->do_backtrace)
        પાછા;
    rc = tcc_get_પ્રતીક(s1, "__rt_info");
    જો (!rc)
        પાછા;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (અક્ષર *)symtab_section->link->data;
    જો (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    જો (s1->do_bounds_check) {
        શૂન્ય *p;
        જો ((p = tcc_get_પ્રતીક(s1, "__bound_init")))
            ((શૂન્ય(*)(શૂન્ય*,પૂર્ણાંક))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    જો (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

સ્થિર શૂન્ય st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
સ્થિર શૂન્ય ptr_unlink(શૂન્ય *list, શૂન્ય *e, unsigned next)
{
    શૂન્ય **pp, **nn, *p;
    માટે (pp = list; !!(p = *pp); pp = nn) {
        nn = (શૂન્ય*)((અક્ષર*)p + next); /* nn = &p->next; */
        જો (p == e) {
            *pp = *nn;
            તોડો;
        }
    }
}

સ્થિર શૂન્ય st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI શૂન્ય *_tcc_setjmp(TCCState *s1, શૂન્ય *p_jmp_buf, શૂન્ય *func, શૂન્ય *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    જો (s1->rc)
        s1->rc->ટોચ_func = func;
#endif
    પાછા p_jmp_buf;
}

LIBTCCAPI શૂન્ય tcc_set_backtrace_func(TCCState *s1, શૂન્ય *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

સ્થિર TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    પૂર્ણાંક level;
    addr_t pc;

    s = g_s1;
    જો (ખાલી == s || ખાલી == s->next) {
        /* play it safe in the simple case when there is only one state */
        પાછા s;
    }
    માટે (level = 0; level < 8; ++level) {
        જો (rt_get_caller_pc(&pc, f, level) < 0)
            તોડો;
        માટે (s = g_s1; s; s = s->next) {
            જો (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                પાછા s;
        }
    }
    પાછા ખાલી;
}

સ્થિર શૂન્ય rt_exit(rt_frame *f, પૂર્ણાંક code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    જો (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        જો (f->fp) { /* called from signal */
            શૂન્ય *p = tcc_get_પ્રતીક(s, "__bound_exit");
            જો (p)
                ((શૂન્ય (*)(શૂન્ય))p)();
        }
#endif
        જો (code == 0)
            code = RT_EXIT_ZERO;
        ((શૂન્ય(*)(શૂન્ય*,પૂર્ણાંક))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#નહીંતર // if defined CONFIG_TCC_BACKTRACE_ONLY
સ્થિર શૂન્ય rt_exit(rt_frame *f, પૂર્ણાંક code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

સ્થિર પૂર્ણાંક rt_vprintf(અચલ અક્ષર *fmt, va_list ap)
{
    પૂર્ણાંક ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    પાછા ret;
}

સ્થિર પૂર્ણાંક rt_printf(અચલ અક્ષર *fmt, ...)
{
    va_list ap;
    પૂર્ણાંક r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    પાછા r;
}

સ્થિર અક્ષર *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    માટે (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        પૂર્ણાંક type = ELFW(ST_TYPE)(esym->st_info);
        જો ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_કિંમત
            && wanted_pc < esym->st_કિંમત + esym->st_size) {
            *func_addr = esym->st_કિંમત;
            પાછા rc->elf_str + esym->st_name;
        }
    }
    પાછા ખાલી;
}

પ્રકારવ્યાખ્યા સંરચના bt_info
{
    અક્ષર file[100];
    પૂર્ણાંક લીટી;
    અક્ષર func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
સ્થિર addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    અક્ષર func_name[128];
    addr_t func_addr, last_pc, pc;
    અચલ અક્ષર *incl_files[INCLUDE_ઢગલો_SIZE];
    પૂર્ણાંક incl_index, last_incl_index, len, last_લીટી_અંક, i;
    અચલ અક્ષર *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_લીટી_અંક = 1;
    last_incl_index = 0;

    માટે (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_કિંમત;

        પસંદગી(sym->n_type) {
        સ્થિતિ N_SLINE:
            જો (func_addr)
                જાઓ rel_pc;
        સ્થિતિ N_SO:
        સ્થિતિ N_SOL:
            જાઓ abs_pc;
        સ્થિતિ N_FUN:
            જો (sym->n_strx == 0) /* end of function */
                જાઓ rel_pc;
        abs_pc:
#જો PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            જાઓ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            જો (pc >= wanted_pc && wanted_pc >= last_pc)
                જાઓ found;
            તોડો;
        }

        પસંદગી(sym->n_type) {
            /* function start or end */
        સ્થિતિ N_FUN:
            જો (sym->n_strx == 0)
                જાઓ reset_func;
            p = strchr(str, ':');
            જો (0 == p || (len = p - str + 1, len > કદ func_name))
                len = કદ func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            તોડો;
            /* line number info */
        સ્થિતિ N_SLINE:
            last_pc = pc;
            last_લીટી_અંક = sym->n_desc;
            last_incl_index = incl_index;
            તોડો;
            /* include files */
        સ્થિતિ N_BINCL:
            જો (incl_index < INCLUDE_ઢગલો_SIZE)
                incl_files[incl_index++] = str;
            તોડો;
        સ્થિતિ N_EINCL:
            જો (incl_index > 1)
                incl_index--;
            તોડો;
            /* start/end of translation unit */
        સ્થિતિ N_SO:
            incl_index = 0;
            જો (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                જો (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            તોડો;
            /* alternative file name (from #line or #include directives) */
        સ્થિતિ N_SOL:
            જો (incl_index)
                incl_files[incl_index-1] = str;
            તોડો;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    જો (i > 0) {
        pstrcpy(bi->file, કદ bi->file, incl_files[--i]);
        bi->લીટી = last_લીટી_અંક;
    }
    pstrcpy(bi->func, કદ bi->func, func_name);
    bi->func_pc = func_addr;
    પાછા func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	પસંદગી (entry_format[j].form) { \
	સ્થિતિ DW_FORM_data1: (ln) += 1; તોડો; \
	સ્થિતિ DW_FORM_data2: (ln) += 2; તોડો; \
	સ્થિતિ DW_FORM_data4: (ln) += 3; તોડો; \
	સ્થિતિ DW_FORM_data8: (ln) += 8; તોડો; \
	સ્થિતિ DW_FORM_data16: (ln) += 16; તોડો; \
	સ્થિતિ DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); તોડો; \
	મૂળભૂત: જાઓ next_લીટી; \
	}

સ્થિર addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned અક્ષર *ln;
    unsigned અક્ષર *cp;
    unsigned અક્ષર *end;
    unsigned અક્ષર *opcode_length;
    unsigned long long size;
    unsigned પૂર્ણાંક length;
    unsigned અક્ષર version;
    unsigned પૂર્ણાંક min_insn_length;
    unsigned પૂર્ણાંક max_ops_per_insn;
    પૂર્ણાંક લીટી_base;
    unsigned પૂર્ણાંક લીટી_range;
    unsigned પૂર્ણાંક opcode_base;
    unsigned પૂર્ણાંક opindex;
    unsigned પૂર્ણાંક col;
    unsigned પૂર્ણાંક i;
    unsigned પૂર્ણાંક j;
    unsigned પૂર્ણાંક len;
    unsigned long long કિંમત;
    સંરચના {
	unsigned પૂર્ણાંક type;
	unsigned પૂર્ણાંક form;
    } entry_format[256];
    unsigned પૂર્ણાંક dir_size;
#જો 0
    અક્ષર *dirs[DIR_TABLE_SIZE];
#endif
    unsigned પૂર્ણાંક filename_size;
    સંરચના /*dwarf_filename_struct*/ {
        unsigned પૂર્ણાંક dir_entry;
        અક્ષર *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    પૂર્ણાંક લીટી;
    અક્ષર *filename;
    અક્ષર *function;

    filename = ખાલી;
    function = ખાલી;
    func_addr = 0;
    લીટી = 0;

    ln = rc->dwarf_લીટી;
    જ્યારે (ln < rc->dwarf_લીટી_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        લીટી = 1;
        filename = ખાલી;
        function = ખાલી;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_લીટી_end);
	જો (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_લીટી_end);
	end = ln + size;
	જો (end < ln || end > rc->dwarf_લીટી_end)
	    તોડો;
	version = dwarf_read_2(ln, end);
	જો (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	નહીંતર
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	જો (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	નહીંતર
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	લીટી_base = dwarf_read_1(ln, end);
	લીટી_base |= લીટી_base >= 0x80 ? ~0xff : 0;
	લીટી_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	જો (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    માટે (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    માટે (i = 0; i < dir_size; i++) {
		માટે (j = 0; j < col; j++) {
		    જો (entry_format[j].type == DW_LNCT_path) {
		        જો (entry_format[j].form != DW_FORM_લીટી_strp)
			    જાઓ next_લીટી;
#જો 0
		        કિંમત = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        જો (i < DIR_TABLE_SIZE)
		            dirs[i] = (અક્ષર *)rc->dwarf_લીટી_str + કિંમત;
#નહીંતર
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    નહીંતર 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    માટે (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    માટે (i = 0; i < filename_size; i++)
		માટે (j = 0; j < col; j++) {
		    જો (entry_format[j].type == DW_LNCT_path) {
			જો (entry_format[j].form != DW_FORM_લીટી_strp)
			    જાઓ next_લીટી;
			કિંમત = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        જો (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(અક્ષર *)rc->dwarf_લીટી_str + કિંમત;
	            }
		    નહીંતર જો (entry_format[j].type == DW_LNCT_directory_index) {
			પસંદગી (entry_format[j].form) {
			સ્થિતિ DW_FORM_data1: કિંમત = dwarf_read_1(ln, end); તોડો;
			સ્થિતિ DW_FORM_data2: કિંમત = dwarf_read_2(ln, end); તોડો;
			સ્થિતિ DW_FORM_data4: કિંમત = dwarf_read_4(ln, end); તોડો;
			સ્થિતિ DW_FORM_udata: કિંમત = dwarf_read_uleb128(&ln, end); તોડો;
			મૂળભૂત: જાઓ next_લીટી;
			}
		        જો (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = કિંમત;
		    }
		    નહીંતર 
			dwarf_ignore_type(ln, end);
	    }
	}
	નહીંતર {
	    જ્યારે ((dwarf_read_1(ln, end))) {
#જો 0
		જો (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (અક્ષર *)ln - 1;
#endif
		જ્યારે (dwarf_read_1(ln, end)) {}
	    }
	    જ્યારે ((dwarf_read_1(ln, end))) {
		જો (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (અક્ષર *)ln - 1;
		    જ્યારે (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		નહીંતર {
		    જ્યારે (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	જો (filename_size >= 1)
	    filename = filename_table[0].name;
	જ્યારે (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    જો (i >= opcode_base) {
	        જો (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / લીટી_range) * min_insn_length;
		નહીંતર {
		    pc += (opindex + (i - opcode_base) / લીટી_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / લીટી_range) %
			       max_ops_per_insn;
		}
		i = (પૂર્ણાંક)((i - opcode_base) % લીટી_range) + લીટી_base;
check_pc:
		જો (pc >= wanted_pc && wanted_pc >= last_pc)
		    જાઓ found;
		લીટી += i;
	    }
	    નહીંતર {
	        પસંદગી (i) {
	        સ્થિતિ 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    જો (len == 0)
		        જાઓ next_લીટી;
		    પસંદગી (dwarf_read_1(cp, end)) {
		    સ્થિતિ DW_LNE_end_sequence:
		        તોડો;
		    સ્થિતિ DW_LNE_set_address:
#જો PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#નહીંતર
		        pc = dwarf_read_8(cp, end);
#endif
#જો defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        તોડો;
		    સ્થિતિ DW_LNE_define_file: /* deprecated */
		        જો (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (અક્ષર *)ln - 1;
		            જ્યારે (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        નહીંતર {
		            જ્યારે (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        તોડો;
		    સ્થિતિ DW_LNE_hi_user - 1:
		        function = (અક્ષર *)cp;
		        func_addr = pc;
		        તોડો;
		    મૂળભૂત:
		        તોડો;
		    }
		    તોડો;
	        સ્થિતિ DW_LNS_advance_pc:
		    જો (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    નહીંતર {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    જાઓ check_pc;
	        સ્થિતિ DW_LNS_advance_લીટી:
		    લીટી += dwarf_read_sleb128(&ln, end);
		    તોડો;
	        સ્થિતિ DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    જો (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    તોડો;
	        સ્થિતિ DW_LNS_const_add_pc:
		    જો (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / લીટી_range) * min_insn_length;
		    નહીંતર {
		        unsigned પૂર્ણાંક off = (255 - opcode_base) / લીટી_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    જાઓ check_pc;
	        સ્થિતિ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    જાઓ check_pc;
	        મૂળભૂત:
		    માટે (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    તોડો;
		}
	    }
	}
next_લીટી:
	ln = end;
    }
    filename = function = ખાલી, func_addr = 0;
found:
    જો (filename)
        pstrcpy(bi->file, કદ bi->file, filename), bi->લીટી = લીટી;
    જો (function)
        pstrcpy(bi->func, કદ bi->func, function);
    bi->func_pc = func_addr;
    પાછા (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
સ્થિર
#endif
પૂર્ણાંક _tcc_backtrace(rt_frame *f, અચલ અક્ષર *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    અક્ષર skip[40], સંદેશ[200];
    પૂર્ણાંક i, level, ret, n, one;
    અચલ અક્ષર *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    જો (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    જો (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(સંદેશ, કદ સંદેશ, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    જો (rc) {
        જો (rc->dwarf)
            getinfo = rt_printline_dwarf;
        જો (rc->અંક_callers)
            n = rc->અંક_callers;
    }

    માટે (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        જો (ret == -1)
            તોડો;
        memset(&bi, 0, કદ bi);
        માટે (rc2 = rc; rc2; rc2 = rc2->next) {
            જો (getinfo(rc2, pc, &bi))
                તોડો;
            /* we try symtab symbols (no line number info) */
            જો (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, કદ bi.func, a);
                તોડો;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        જો (skip[0] && strstr(bi.file, skip))
            ચાલુ;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            જો (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (શૂન્ય*)pc,
                    bi.file[0] ? bi.file : ખાલી,
                    bi.લીટી,
                    bi.func[0] ? bi.func : ખાલી,
                    level == 0 ? સંદેશ : ખાલી
                    );
                જો (ret == 0)
                    તોડો;
                જાઓ check_break;
            }
        }
#endif
        જો (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.લીટી);
        } નહીંતર {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        જો (level == 0) {
            rt_printf(": %s", સંદેશ);
            જો (one)
                તોડો;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        જો (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->ટોચ_func)
            તોડો;
        ++level;
    }
    rt_post_sem();
    પાછા 0;
}

/* emit a run time error at position 'pc' */
સ્થિર પૂર્ણાંક rt_error(rt_frame *f, અચલ અક્ષર *fmt, ...)
{
    va_list ap; અક્ષર સંદેશ[200]; પૂર્ણાંક ret;
    va_start(ap, fmt);
    snprintf(સંદેશ, કદ સંદેશ, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, સંદેશ, ap);
    va_end(ap);
    પાછા ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#નહીંતર
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
સ્થિર શૂન્ય rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#જો defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#અથવાજો defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#અથવાજો defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#અથવાજો defined __i386__
# જો defined(__APPLE__)
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
# નહીંતર
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#અથવાજો defined(__x86_64__)
# જો defined(__APPLE__)
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
# નહીંતર
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#અથવાજો defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#અથવાજો defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#અથવાજો defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#અથવાજો defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#અથવાજો defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#અથવાજો defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#અથવાજો defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#અથવાજો defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#અથવાજો defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#અથવાજો defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#અથવાજો defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
સ્થિર શૂન્ય sig_error(પૂર્ણાંક signum, siginfo_t *siginf, શૂન્ય *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    પસંદગી(signum) {
    સ્થિતિ SIGFPE:
        પસંદગી(siginf->si_code) {
        સ્થિતિ FPE_INTDIV:
        સ્થિતિ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            તોડો;
        મૂળભૂત:
            rt_error(&f, "floating point exception");
            તોડો;
        }
        તોડો;
    સ્થિતિ SIGBUS:
    સ્થિતિ SIGSEGV:
        rt_error(&f, "invalid memory access");
        તોડો;
    સ્થિતિ SIGILL:
        rt_error(&f, "illegal instruction");
        તોડો;
    સ્થિતિ SIGABRT:
        rt_error(&f, "abort() called");
        તોડો;
    મૂળભૂત:
        rt_error(&f, "caught signal %d", signum);
        તોડો;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ખાલી);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
સ્થિર શૂન્ય set_exception_handler(શૂન્ય)
{
    સંરચના sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#જો 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ખાલી);
    sigaction(SIGILL, &sigact, ખાલી);
    sigaction(SIGSEGV, &sigact, ખાલી);
    sigaction(SIGBUS, &sigact, ખાલી);
    sigaction(SIGABRT, &sigact, ખાલી);
#જો 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        સ્થિર unsigned અક્ષર ઢગલો[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ઢગલો;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ખાલી);
    }
#endif
}

#નહીંતર /* WIN32 */

/* signal handler for fatal errors */
સ્થિર long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    પસંદગી (code = ex_info->ExceptionRecord->ExceptionCode) {
    સ્થિતિ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        તોડો;
    સ્થિતિ EXCEPTION_ઢગલો_OVERFLOW:
        rt_error(&f, "stack overflow");
        તોડો;
    સ્થિતિ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        તોડો;
    સ્થિતિ EXCEPTION_BREAKPOINT:
    સ્થિતિ EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        પાછા EXCEPTION_CONTINUE_શોધ;
    મૂળભૂત:
        rt_error(&f, "caught exception %08x", code);
        તોડો;
    }
    rt_exit(&f, 255);
    પાછા EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
સ્થિર શૂન્ય set_exception_handler(શૂન્ય)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#નહીંતર
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#જો defined(__i386__) || defined(__x86_64__)
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *rc, પૂર્ણાંક level)
{
    જો (level == 0) {
        *paddr = rc->ip;
    } નહીંતર {
        addr_t fp = rc->fp;
        જ્યારે (1) {
            જો (fp < 0x1000)
                પાછા -1;
            જો (0 == --level)
                તોડો;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    પાછા 0;
}

/* XXX: only supports linux/bsd */
#અથવાજો defined(__arm__) && !defined(_WIN32)
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *rc, પૂર્ણાંક level)
{
    જો (level == 0) {
        *paddr = rc->ip;
    } નહીંતર {
        addr_t fp = rc->fp;
        જ્યારે (1) {
            જો (fp < 0x1000)
                પાછા -1;
            જો (0 == --level)
                તોડો;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    પાછા 0;
}

#અથવાજો defined(__aarch64__)
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *rc, પૂર્ણાંક level)
{
    જો (level == 0) {
        *paddr = rc->ip;
    } નહીંતર {
        addr_t fp = rc->fp;
        જ્યારે (1) {
            જો (fp < 0x1000)
                પાછા -1;
            જો (0 == --level)
                તોડો;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    પાછા 0;
}

#અથવાજો defined(__riscv)
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *rc, પૂર્ણાંક level)
{
    જો (level == 0) {
        *paddr = rc->ip;
    } નહીંતર {
        addr_t fp = rc->fp;
        જ્યારે (1) {
            જો (fp < 0x1000)
                પાછા -1;
            જો (0 == --level)
                તોડો;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    પાછા 0;
}

#નહીંતર
#warning add arch specific rt_get_caller_pc()
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *rc, પૂર્ણાંક level)
{
    પાછા -1;
}

#endif
#નહીંતર // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
સ્થિર પૂર્ણાંક rt_get_caller_pc(addr_t *paddr, rt_frame *f, પૂર્ણાંક level)
{
    જો (level)
        પાછા -1;
    *paddr = f->ip;
    પાછા 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC શૂન્ય *dlopen(અચલ અક્ષર *filename, પૂર્ણાંક flag)
{
    પાછા ખાલી;
}

ST_FUNC શૂન્ય dlclose(શૂન્ય *p)
{
}

ST_FUNC અચલ અક્ષર *dlerror(શૂન્ય)
{
    પાછા "error";
}

પ્રકારવ્યાખ્યા સંરચના TCCSyms {
    અક્ષર *str;
    શૂન્ય *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
સ્થિર TCCSyms tcc_syms[] = {
#જો !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { ખાલી, ખાલી },
};

ST_FUNC શૂન્ય *dlsym(શૂન્ય *handle, અચલ અક્ષર *પ્રતીક)
{
    TCCSyms *p;
    p = tcc_syms;
    જ્યારે (p->str != ખાલી) {
        જો (!strcmp(p->str, પ્રતીક))
            પાછા p->ptr;
        p++;
    }
    પાછા ખાલી;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
