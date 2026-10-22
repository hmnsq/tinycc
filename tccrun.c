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

#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

/* only native compiler supports -run */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_IS_NATIVE

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
/* runtime debug info block */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    ਸੰਘ {
	ਬਣਤਰ {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_ਸਿਰਾ;
	    ਅੱਖਰ *stab_str;
	};
	ਬਣਤਰ {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *dwarf_ਸਤਰ;
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *dwarf_ਸਤਰ_ਸਿਰਾ;
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *dwarf_ਸਤਰ_str;
	};
    };
    ElfW(Sym) *esym_ਸ਼ੁਰੂ;
    ElfW(Sym) *esym_ਸਿਰਾ;
    ਅੱਖਰ *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_ਅਧਾਰ;
    ਖਾਲੀ *bounds_ਸ਼ੁਰੂ;
    ਖਾਲੀ *ਸਿਖਰ_func;
    ਬਣਤਰ rt_context *ਅਗਲਾ;
    // 10 * PTR_SIZE
    ਪੂਰਨ ਅੰਕ_callers;
    ਪੂਰਨ dwarf;
} rt_context;

/* linked list of rt_contexts */
ਸਥਿਰ rt_context *g_rc;
ਸਥਿਰ ਪੂਰਨ signal_ਸੈੱਟ;
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_exception_handler(ਖਾਲੀ);
#ਜੇ_ਅੰਤ /* def CONFIG_TCC_BACKTRACE */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ rt_ਚੌਖਟਾ {
    addr_t ip, fp, sp;
} rt_ਚੌਖਟਾ;

ਸਥਿਰ TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ਸਥਿਰ rt_sem);
ਸਥਿਰ ਖਾਲੀ rt_wait_sem(ਖਾਲੀ) { WAIT_SEM(&rt_sem); }
ਸਥਿਰ ਖਾਲੀ rt_post_sem(ਖਾਲੀ) { POST_SEM(&rt_sem); }
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *f, ਪੂਰਨ level);
ਸਥਿਰ ਖਾਲੀ rt_exit(rt_ਚੌਖਟਾ *f, ਪੂਰਨ ਕੋਡ);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE_ONLY

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
# include <sys/mman.h>
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ protect_ਪੰਨੇ(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾਈ, ਪੂਰਨ ਬਹੁਲਕ);
ਸਥਿਰ ਪੂਰਨ tcc_relocate_ex(TCCState *s1, ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ptr_diff);
ਸਥਿਰ ਖਾਲੀ st_link(TCCState *s1);
ਸਥਿਰ ਖਾਲੀ st_unlink(TCCState *s1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
ਸਥਿਰ ਪੂਰਨ _tcc_backtrace(rt_ਚੌਖਟਾ *f, ਅਚਲ ਅੱਖਰ *fmt, va_list ap);
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
ਸਥਿਰ ਖਾਲੀ *win64_ਜੋੜੋ_function_ਸਾਰਣੀ(TCCState *s1);
ਸਥਿਰ ਖਾਲੀ win64_del_function_ਸਾਰਣੀ(ਖਾਲੀ *);
#ਜੇ_ਅੰਤ

#ਜੇ !defined PAGESIZE
# ਜੇ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ਨਹੀਂਤਾਂ
#  define PAGESIZE 4096
# endif
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ਜੇ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#ਜੇ_ਅੰਤ

/* use VirtualAlloc() instead of tcc_malloc() */
#ਜੇ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਪੂਰਨ rt_mem(TCCState *s1, ਪੂਰਨ ਮਾਪ)
{
    ਖਾਲੀ *ptr;
    ਪੂਰਨ ptr_diff = 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_SELINUX
    /* Using mmap instead of malloc */
    ਖਾਲੀ *prw;
    ਅੱਖਰ tmpfname[] = "/tmp/.tccrunXXXXXX";
    ਪੂਰਨ fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, ਮਾਪ);

    ptr = mmap(ਨਿਰਾ, ਮਾਪ * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((ਅੱਖਰ*)ptr + ਮਾਪ, ਮਾਪ, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ਜੇ (ptr == MAP_FAILED || prw == MAP_FAILED)
	ਵਾਪਸ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (ਅੱਖਰ*)prw - (ਅੱਖਰ*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    ਮਾਪ *= 2;
#ਜਾਂਜੇ CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ਨਿਰਾ, ਮਾਪ, MEM_RESERVE | MEM_COMMIT, ਪੰਨਾ_READWRITE);
    ਜੇ (!ptr)
        ਵਾਪਸ tcc_error_noabort("tccrun: could not allocate memory");
#ਨਹੀਂਤਾਂ
    ptr = tcc_malloc(ਮਾਪ += PAGESIZE); /* one extra page to align malloc memory */
#ਜੇ_ਅੰਤ
    s1->ਲੜੀਵਾਰ_ptr = ptr;
    s1->ਲੜੀਵਾਰ_ਮਾਪ = ਮਾਪ;
    ਵਾਪਸ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI ਪੂਰਨ tcc_relocate(TCCState *s1)
{
    ਪੂਰਨ ਮਾਪ, ret, ptr_diff;

    ਜੇ (s1->ਲੜੀਵਾਰ_ptr)
        ਬਾਹਰ_ਨਿਕਲੋ(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ਜੇ (s1->do_backtrace)
        tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#ਜੇ_ਅੰਤ
    ਮਾਪ = tcc_relocate_ex(s1, ਨਿਰਾ, 0);
    ਜੇ (ਮਾਪ < 0)
        ਵਾਪਸ -1;
    ptr_diff = rt_mem(s1, ਮਾਪ);
    ਜੇ (ptr_diff < 0)
        ਵਾਪਸ -1;
    ret = tcc_relocate_ex(s1, s1->ਲੜੀਵਾਰ_ptr, ptr_diff);
    ਜੇ (ret == 0)
        st_link(s1);
    ਵਾਪਸ ret;
}

ST_FUNC ਖਾਲੀ tcc_ਲੜੀਵਾਰ_free(TCCState *s1)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਮਾਪ;
    ਖਾਲੀ *ptr;
    ਪੂਰਨ i;

    /* free any loaded DLLs */
    ਲਈ ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ਜੇ ( ref->handle )
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ਨਹੀਂਤਾਂ
            dlclose(ref->handle);
#ਜੇ_ਅੰਤ
    }
    /* unmap or unprotect and free memory */
    ptr = s1->ਲੜੀਵਾਰ_ptr;
    ਜੇ (ਨਿਰਾ == ptr)
        ਵਾਪਸ;
    st_unlink(s1);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    win64_del_function_ਸਾਰਣੀ(s1->ਲੜੀਵਾਰ_function_ਸਾਰਣੀ);
#ਜੇ_ਅੰਤ
    ਮਾਪ = s1->ਲੜੀਵਾਰ_ਮਾਪ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_SELINUX
    munmap(ptr, ਮਾਪ);
#ਜਾਂਜੇ CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, ਮਾਪ, MEM_RELEASE);
#ਨਹੀਂਤਾਂ
    /* unprotect memory to make it usable for malloc again */
    protect_ਪੰਨੇ((ਖਾਲੀ*)PAGEALIGN(ptr), ਮਾਪ - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#ਜੇ_ਅੰਤ
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI ਪੂਰਨ tcc_ਲੜੀਵਾਰ(TCCState *s1, ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਪੂਰਨ (*prog_main)(ਪੂਰਨ, ਅੱਖਰ **, ਅੱਖਰ **), ret;
    ਅਚਲ ਅੱਖਰ *ਸਿਖਰ_sym;
    jmp_buf main_jb;

#ਜੇ defined(__APPLE__)
    ਬਾਹਰੀ ਅੱਖਰ ***_NSGetEnviron(ਖਾਲੀ);
    ਅੱਖਰ **envp = *_NSGetEnviron();
#ਜਾਂਜੇ defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    ਬਾਹਰੀ ਅੱਖਰ **environ;
    ਅੱਖਰ **envp = environ;
#ਨਹੀਂਤਾਂ
    ਅੱਖਰ **envp = environ;
#ਜੇ_ਅੰਤ

    /* tcc -dt -run ... nothing to do if no main() */
    ਜੇ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ਵਾਪਸ 0;

    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s1, "__rt_exit", rt_exit);
    s1->ਲੜੀਵਾਰ_main = "_runmain", ਸਿਖਰ_sym = "main";
    ਜੇ (s1->elf_entryname)
        s1->ਲੜੀਵਾਰ_main = ਸਿਖਰ_sym = s1->elf_entryname;
    tcc_ਜੋੜੋ_support(s1, "runmain.o");

    ਜੇ (tcc_relocate(s1) < 0)
        ਵਾਪਸ -1;

    prog_main = (ਖਾਲੀ*)get_sym_addr(s1, s1->ਲੜੀਵਾਰ_main, 1, 1);
    ਜੇ ((addr_t)-1 == (addr_t)prog_main)
        ਵਾਪਸ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ਜੇ (s1->ਲੜੀਵਾਰ_stdin && !freopen(s1->ਲੜੀਵਾਰ_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->ਲੜੀਵਾਰ_stdin);
        ਵਾਪਸ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_ਚਿੰਨ੍ਹ(s1, ਸਿਖਰ_sym));
    ਜੇ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ਨਹੀਂਤਾਂ ਜੇ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ਜੇ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ਵਾਪਸ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ਸਥਿਰ ਖਾਲੀ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    ਪੂਰਨ sym_ਸੂਚਕਾਂਕ, ਸਿਰਾ_sym = s->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (ElfSym);
    /* reset symtab */
    s->ਅੰਕੜੇ_ਵਿੱਥ = s->link->ਅੰਕੜੇ_ਵਿੱਥ = s->hash->ਅੰਕੜੇ_ਵਿੱਥ = 0;
    init_symtab(s);
    /* add global symbols again */
    ਲਈ (sym_ਸੂਚਕਾਂਕ = 1; sym_ਸੂਚਕਾਂਕ < ਸਿਰਾ_sym; ++sym_ਸੂਚਕਾਂਕ) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->ਅੰਕੜੇ)[sym_ਸੂਚਕਾਂਕ];
        ਅਚਲ ਅੱਖਰ *name = (ਅੱਖਰ *)s->link->ਅੰਕੜੇ + sym->st_name;
        ਜੇ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ਜਾਰੀ;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_ਮੁੱਲ, sym->st_ਮਾਪ, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ਸਥਿਰ ਖਾਲੀ cleanup_sections(TCCState *s1)
{
    ਬਣਤਰ { Section **secs; ਪੂਰਨ nb_secs; } *p = (ਖਾਲੀ*)&s1->sections;
    ਪੂਰਨ i, f = 2;
    ਕਰੋ {
        ਲਈ (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ਜੇ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->ਅੰਕੜੇ = tcc_realloc(s->ਅੰਕੜੇ, s->ਅੰਕੜੇ_allocated = s->ਅੰਕੜੇ_ਵਿੱਥ);
            } ਨਹੀਂਤਾਂ {
                free_section(s), tcc_free(s), p->secs[i] = ਨਿਰਾ;
            }
        }
    } ਜਦੋਂ (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# ਨਹੀਂਤਾਂ
#   define CONFIG_RUNMEM_RO 0
#  endif
#ਜੇ_ਅੰਤ

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ਸਥਿਰ ਪੂਰਨ tcc_relocate_ex(TCCState *s1, ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ptr_diff)
{
    Section *s;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ, ਲੰਮਾਈ, align, i, k, f;
    ਬਿਨਾਨਿਸ਼ਾਨੀ n, copy;
    addr_t mem, addr;

    ਜੇ (ਨਿਰਾ == ptr) {
        s1->nb_errors = 0;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
        pe_output_file(s1, ਨਿਰਾ);
#ਨਹੀਂਤਾਂ
        tcc_ਜੋੜੋ_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#ਜੇ_ਅੰਤ
    }

    ਵਿੱਥ = copy = 0;
    mem = (addr_t)ptr;
redo:
    ਜੇ (s1->verbose == 2 && copy)
        ਲਿਖੋ(&"-----------------------------------------------------\n"[PTR_ਮਾਪ*2 - 8]);
    ਜੇ (s1->nb_errors)
        ਵਾਪਸ -1;
    ਜੇ (copy == 3)
        ਵਾਪਸ 0;

    ਲਈ (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        ਲਈ(i = 1; i < s1->nb_sections; i++) {
            ਸਥਿਰ ਅਚਲ ਅੱਖਰ shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ਜੇ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ਜਾਰੀ;
            ਲੰਮਾਈ = s->ਅੰਕੜੇ_ਵਿੱਥ;
            ਜੇ (copy == 2) {
                ਜੇ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + ਲੰਮਾਈ;
                ਜਾਰੀ;
            }
            ਜੇ (copy) { /* final step: copy section data to memory */
                ਜੇ (s1->verbose == 2)
                    ਲਿਖੋ("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (ਖਾਲੀ*)s->sh_addr, ਲੰਮਾਈ, s->sh_addralign);
                ptr = (ਖਾਲੀ*)s->sh_addr;
                ਜੇ (k == 0)
                    ptr = (ਖਾਲੀ*)(s->sh_addr + ptr_diff);
                ਜੇ (ਨਿਰਾ == s->ਅੰਕੜੇ || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, ਲੰਮਾਈ);
                ਨਹੀਂਤਾਂ
                    ਸਮ੍ਰਿਤੀ_ਨਕਲ(ptr, s->ਅੰਕੜੇ, ਲੰਮਾਈ);
                ਜਾਰੀ;
            }

            ਜੇ ((s->sh_flags & SHF_TLS) && ਲੰਮਾਈ)
                ਵਾਪਸ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ਜੇ (++n == 1) {
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_I386 || defined TCC_ਨਿਸ਼ਾਨਾ_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ਜੇ (align < 64)
                    align = 64;
#ਜੇ_ਅੰਤ
                /* start new page for different permissions */
                ਜੇ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            ਵਿੱਥ += -(addr + ਵਿੱਥ) & (align - 1);
            s->sh_addr = mem ? addr + ਵਿੱਥ : 0;
            ਵਿੱਥ += ਲੰਮਾਈ;
        }
        ਜੇ (copy == 2) { /* set permissions */
            ਜੇ (n == 0) /* no data  */
                ਜਾਰੀ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_SELINUX
            ਜੇ (k == 0) /* SHF_EXECINSTR has its own mapping */
                ਜਾਰੀ;
#ਜੇ_ਅੰਤ
            f = k;
            ਜੇ (f >= CONFIG_RUNMEM_RO) {
                ਜੇ (f != 0)
                    ਜਾਰੀ;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ਜੇ (s1->verbose == 2) {
                ਲਿਖੋ("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (ਖਾਲੀ*)addr, (ਬਿਨਾਨਿਸ਼ਾਨੀ)n);
            }
            ਜੇ (protect_ਪੰਨੇ((ਖਾਲੀ*)addr, n, f) < 0)
                ਵਾਪਸ tcc_error_noabort(
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
                    "VirtualProtect failed");
#ਨਹੀਂਤਾਂ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#ਜੇ_ਅੰਤ
        }
    }

    ਜੇ (0 == mem)
        ਵਾਪਸ PAGEALIGN(ਵਿੱਥ);

    ਜੇ (++copy == 2) {
        ਜਾਓ redo;
    }
    ਜੇ (copy == 3) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
        s1->ਲੜੀਵਾਰ_function_ਸਾਰਣੀ = win64_ਜੋੜੋ_function_ਸਾਰਣੀ(s1);
#ਜੇ_ਅੰਤ
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        ਜਾਓ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ਜੇ (s1->nb_errors)
        ਜਾਓ redo;
    /* relocate sections */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ TCC_ਨਿਸ਼ਾਨਾ_PE
    s1->pe_imagebase = mem;
#ਨਹੀਂਤਾਂ
    relocate_plt(s1);
#ਜੇ_ਅੰਤ
    relocate_sections(s1);
    ਜਾਓ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ਸਥਿਰ ਪੂਰਨ protect_ਪੰਨੇ(ਖਾਲੀ *ptr, ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾਈ, ਪੂਰਨ ਬਹੁਲਕ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ protect[] = {
        ਪੰਨਾ_EXECUTE_READ,
        ਪੰਨਾ_READONLY,
        ਪੰਨਾ_READWRITE,
        ਪੰਨਾ_EXECUTE_READWRITE
        };
    DWORD old;
    ਜੇ (!VirtualProtect(ptr, ਲੰਮਾਈ, protect[ਬਹੁਲਕ], &old))
        ਵਾਪਸ -1;
#ਨਹੀਂਤਾਂ
    ਸਥਿਰ ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ਜੇ (mprotect(ptr, ਲੰਮਾਈ, protect[ਬਹੁਲਕ]))
        ਵਾਪਸ -1;
#ਜੇ_ਅੰਤ
/* XXX: BSD sometimes dump core with bad system call */
#ਜੇ (defined TCC_ਨਿਸ਼ਾਨਾ_ARM && !TARGETOS_BSD) \
    || defined TCC_ਨਿਸ਼ਾਨਾ_ARM64 || defined TCC_ਨਿਸ਼ਾਨਾ_RISCV64
    ਜੇ (ਬਹੁਲਕ == 0 || ਬਹੁਲਕ == 3) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, ਲੰਮਾਈ);
#ਨਹੀਂਤਾਂ
        ਖਾਲੀ __clear_cache(ਖਾਲੀ *beginning, ਖਾਲੀ *ਸਿਰਾ);
        __clear_cache(ptr, (ਅੱਖਰ *)ptr + ਲੰਮਾਈ);
#ਜੇ_ਅੰਤ
    }
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
ਸਥਿਰ ਖਾਲੀ *win64_ਜੋੜੋ_function_ਸਾਰਣੀ(TCCState *s1)
{
    ਖਾਲੀ *p = ਨਿਰਾ;
    ਜੇ (s1->uw_pdata) {
        p = (ਖਾਲੀ*)s1->uw_pdata->sh_addr;
        Rtl_ਜੋੜੋ_Function_ਸਾਰਣੀ(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->ਅੰਕੜੇ_ਵਿੱਥ / ਆਕਾਰ (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ਨਿਰਾ;
    }
    ਵਾਪਸ p;
}

ਸਥਿਰ ਖਾਲੀ win64_del_function_ਸਾਰਣੀ(ਖਾਲੀ *p)
{
    ਜੇ (p) {
        Rtl_Delete_Function_ਸਾਰਣੀ((RUNTIME_FUNCTION*)p);
    }
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ bt_link(TCCState *s1)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ਜੇ (!s1->do_backtrace)
        ਵਾਪਸ;
    rc = tcc_get_ਚਿੰਨ੍ਹ(s1, "__rt_info");
    ਜੇ (!rc)
        ਵਾਪਸ;
    rc->esym_ਸ਼ੁਰੂ = (ElfW(Sym) *)(symtab_section->ਅੰਕੜੇ);
    rc->esym_ਸਿਰਾ = (ElfW(Sym) *)(symtab_section->ਅੰਕੜੇ + symtab_section->ਅੰਕੜੇ_ਵਿੱਥ);
    rc->elf_str = (ਅੱਖਰ *)symtab_section->link->ਅੰਕੜੇ;
    ਜੇ (PTR_ਮਾਪ == 8 && !s1->dwarf)
        rc->prog_ਅਧਾਰ &= 0xffffffff00000000ULL;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
    ਜੇ (s1->do_bounds_check) {
        ਖਾਲੀ *p;
        ਜੇ ((p = tcc_get_ਚਿੰਨ੍ਹ(s1, "__bound_init")))
            ((ਖਾਲੀ(*)(ਖਾਲੀ*,ਪੂਰਨ))p)(rc->bounds_ਸ਼ੁਰੂ, 1);
    }
#ਜੇ_ਅੰਤ
    rc->ਅਗਲਾ = g_rc, g_rc = rc, s1->rc = rc;
    ਜੇ (0 == signal_ਸੈੱਟ)
        ਸੈੱਟ_exception_handler(), signal_ਸੈੱਟ = 1;
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਖਾਲੀ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->ਅਗਲਾ = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ਸਥਿਰ ਖਾਲੀ ptr_unlink(ਖਾਲੀ *list, ਖਾਲੀ *e, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅਗਲਾ)
{
    ਖਾਲੀ **pp, **nn, *p;
    ਲਈ (pp = list; !!(p = *pp); pp = nn) {
        nn = (ਖਾਲੀ*)((ਅੱਖਰ*)p + ਅਗਲਾ); /* nn = &p->next; */
        ਜੇ (p == e) {
            *pp = *nn;
            ਰੋਕੋ;
        }
    }
}

ਸਥਿਰ ਖਾਲੀ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, ਅਗਲਾ));
#ਜੇ_ਅੰਤ
    ptr_unlink(&g_s1, s1, offsetof(TCCState, ਅਗਲਾ));
    rt_post_sem();
}

LIBTCCAPI ਖਾਲੀ *_tcc_setjmp(TCCState *s1, ਖਾਲੀ *p_jmp_buf, ਖਾਲੀ *func, ਖਾਲੀ *p_longjmp)
{
    s1->ਲੜੀਵਾਰ_lj = p_longjmp;
    s1->ਲੜੀਵਾਰ_jb = p_jmp_buf;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE
    ਜੇ (s1->rc)
        s1->rc->ਸਿਖਰ_func = func;
#ਜੇ_ਅੰਤ
    ਵਾਪਸ p_jmp_buf;
}

LIBTCCAPI ਖਾਲੀ tcc_ਸੈੱਟ_backtrace_func(TCCState *s1, ਖਾਲੀ *ਅੰਕੜੇ, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_ਅੰਕੜੇ = ਅੰਕੜੇ;
}

ਸਥਿਰ TCCState *rt_ਲੱਭੋ_state(rt_ਚੌਖਟਾ *f)
{
    TCCState *s;
    ਪੂਰਨ level;
    addr_t pc;

    s = g_s1;
    ਜੇ (ਨਿਰਾ == s || ਨਿਰਾ == s->ਅਗਲਾ) {
        /* play it safe in the simple case when there is only one state */
        ਵਾਪਸ s;
    }
    ਲਈ (level = 0; level < 8; ++level) {
        ਜੇ (rt_get_caller_pc(&pc, f, level) < 0)
            ਰੋਕੋ;
        ਲਈ (s = g_s1; s; s = s->ਅਗਲਾ) {
            ਜੇ (pc >= (addr_t)s->ਲੜੀਵਾਰ_ptr
             && pc  < (addr_t)s->ਲੜੀਵਾਰ_ptr + s->ਲੜੀਵਾਰ_ਮਾਪ)
                ਵਾਪਸ s;
        }
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ ਖਾਲੀ rt_exit(rt_ਚੌਖਟਾ *f, ਪੂਰਨ ਕੋਡ)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_ਲੱਭੋ_state(f);
    rt_post_sem();
    ਜੇ (s && s->ਲੜੀਵਾਰ_lj) {
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BCHECK
        ਜੇ (f->fp) { /* called from signal */
            ਖਾਲੀ *p = tcc_get_ਚਿੰਨ੍ਹ(s, "__bound_exit");
            ਜੇ (p)
                ((ਖਾਲੀ (*)(ਖਾਲੀ))p)();
        }
#ਜੇ_ਅੰਤ
        ਜੇ (ਕੋਡ == 0)
            ਕੋਡ = RT_EXIT_ZERO;
        ((ਖਾਲੀ(*)(ਖਾਲੀ*,ਪੂਰਨ))s->ਲੜੀਵਾਰ_lj)(s->ਲੜੀਵਾਰ_jb, ਕੋਡ);
    }
    ਬਾਹਰ_ਨਿਕਲੋ(ਕੋਡ);
}

/* ------------------------------------------------------------- */
#ਨਹੀਂਤਾਂ // if defined CONFIG_TCC_BACKTRACE_ONLY
ਸਥਿਰ ਖਾਲੀ rt_exit(rt_ਚੌਖਟਾ *f, ਪੂਰਨ ਕੋਡ)
{
    ਬਾਹਰ_ਨਿਕਲੋ(ਕੋਡ);
}
#ਜੇ_ਅੰਤ //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE

ਸਥਿਰ ਪੂਰਨ rt_vprintf(ਅਚਲ ਅੱਖਰ *fmt, va_list ap)
{
    ਪੂਰਨ ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ਵਾਪਸ ret;
}

ਸਥਿਰ ਪੂਰਨ rt_printf(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap;
    ਪੂਰਨ r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ਵਾਪਸ r;
}

ਸਥਿਰ ਅੱਖਰ *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    ਲਈ (esym = rc->esym_ਸ਼ੁਰੂ + 1; esym < rc->esym_ਸਿਰਾ; ++esym) {
        ਪੂਰਨ type = ELFW(ST_TYPE)(esym->st_info);
        ਜੇ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_ਮੁੱਲ
            && wanted_pc < esym->st_ਮੁੱਲ + esym->st_ਮਾਪ) {
            *func_addr = esym->st_ਮੁੱਲ;
            ਵਾਪਸ rc->elf_str + esym->st_name;
        }
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ bt_info
{
    ਅੱਖਰ file[100];
    ਪੂਰਨ ਸਤਰ;
    ਅੱਖਰ func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ਸਥਿਰ addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ਅੱਖਰ func_name[128];
    addr_t func_addr, ਆਖਰੀ_pc, pc;
    ਅਚਲ ਅੱਖਰ *incl_files[INCLUDE_ਢੇਰ_ਮਾਪ];
    ਪੂਰਨ incl_ਸੂਚਕਾਂਕ, ਆਖਰੀ_incl_ਸੂਚਕਾਂਕ, len, ਆਖਰੀ_ਸਤਰ_ਅੰਕ, i;
    ਅਚਲ ਅੱਖਰ *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_ਸੂਚਕਾਂਕ = 0;
    ਆਖਰੀ_pc = (addr_t)-1;
    ਆਖਰੀ_ਸਤਰ_ਅੰਕ = 1;
    ਆਖਰੀ_incl_ਸੂਚਕਾਂਕ = 0;

    ਲਈ (sym = rc->stab_sym + 1; sym < rc->stab_sym_ਸਿਰਾ; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_ਮੁੱਲ;

        ਚੋਣ(sym->n_type) {
        ਹਾਲਤ N_SLINE:
            ਜੇ (func_addr)
                ਜਾਓ rel_pc;
        ਹਾਲਤ N_SO:
        ਹਾਲਤ N_SOL:
            ਜਾਓ abs_pc;
        ਹਾਲਤ N_FUN:
            ਜੇ (sym->n_strx == 0) /* end of function */
                ਜਾਓ rel_pc;
        abs_pc:
#ਜੇ PTR_ਮਾਪ == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_ਅਧਾਰ;
#ਜੇ_ਅੰਤ
            ਜਾਓ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ਜੇ (pc >= wanted_pc && wanted_pc >= ਆਖਰੀ_pc)
                ਜਾਓ ਮਿਲਿਆ;
            ਰੋਕੋ;
        }

        ਚੋਣ(sym->n_type) {
            /* function start or end */
        ਹਾਲਤ N_FUN:
            ਜੇ (sym->n_strx == 0)
                ਜਾਓ reset_func;
            p = strchr(str, ':');
            ਜੇ (0 == p || (len = p - str + 1, len > ਆਕਾਰ func_name))
                len = ਆਕਾਰ func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ਰੋਕੋ;
            /* line number info */
        ਹਾਲਤ N_SLINE:
            ਆਖਰੀ_pc = pc;
            ਆਖਰੀ_ਸਤਰ_ਅੰਕ = sym->n_desc;
            ਆਖਰੀ_incl_ਸੂਚਕਾਂਕ = incl_ਸੂਚਕਾਂਕ;
            ਰੋਕੋ;
            /* include files */
        ਹਾਲਤ N_BINCL:
            ਜੇ (incl_ਸੂਚਕਾਂਕ < INCLUDE_ਢੇਰ_ਮਾਪ)
                incl_files[incl_ਸੂਚਕਾਂਕ++] = str;
            ਰੋਕੋ;
        ਹਾਲਤ N_EINCL:
            ਜੇ (incl_ਸੂਚਕਾਂਕ > 1)
                incl_ਸੂਚਕਾਂਕ--;
            ਰੋਕੋ;
            /* start/end of translation unit */
        ਹਾਲਤ N_SO:
            incl_ਸੂਚਕਾਂਕ = 0;
            ਜੇ (sym->n_strx) {
                /* do not add path */
                len = ਲੜੀ_ਲੰਬਾਈ(str);
                ਜੇ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_ਸੂਚਕਾਂਕ++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            ਆਖਰੀ_pc = (addr_t)-1;
            ਰੋਕੋ;
            /* alternative file name (from #line or #include directives) */
        ਹਾਲਤ N_SOL:
            ਜੇ (incl_ਸੂਚਕਾਂਕ)
                incl_files[incl_ਸੂਚਕਾਂਕ-1] = str;
            ਰੋਕੋ;
        }
    }
    ਆਖਰੀ_incl_ਸੂਚਕਾਂਕ = 0, func_name[0] = 0, func_addr = 0;
ਮਿਲਿਆ:
    i = ਆਖਰੀ_incl_ਸੂਚਕਾਂਕ;
    ਜੇ (i > 0) {
        pstrcpy(bi->file, ਆਕਾਰ bi->file, incl_files[--i]);
        bi->ਸਤਰ = ਆਖਰੀ_ਸਤਰ_ਅੰਕ;
    }
    pstrcpy(bi->func, ਆਕਾਰ bi->func, func_name);
    bi->func_pc = func_addr;
    ਵਾਪਸ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIR_ਸਾਰਣੀ_ਮਾਪ	(64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ਸਾਰਣੀ_ਮਾਪ	(512)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	dwarf_ignore_type(ln, ਸਿਰਾ) /* timestamp/size/md5/... */ \
	ਚੋਣ (ਇੰਦਰਾਜ_format[j].form) { \
	ਹਾਲਤ DW_FORM_data1: (ln) += 1; ਰੋਕੋ; \
	ਹਾਲਤ DW_FORM_data2: (ln) += 2; ਰੋਕੋ; \
	ਹਾਲਤ DW_FORM_data4: (ln) += 3; ਰੋਕੋ; \
	ਹਾਲਤ DW_FORM_data8: (ln) += 8; ਰੋਕੋ; \
	ਹਾਲਤ DW_FORM_data16: (ln) += 16; ਰੋਕੋ; \
	ਹਾਲਤ DW_FORM_udata: dwarf_read_uleb128(&(ln), (ਸਿਰਾ)); ਰੋਕੋ; \
	ਮੂਲ: ਜਾਓ ਅਗਲਾ_ਸਤਰ; \
	}

ਸਥਿਰ addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ln;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *cp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਸਿਰਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *opcode_ਲੰਮਾਈ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮਾਪ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਲੰਮਾਈ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਸੰਸਕਰਣ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ min_insn_ਲੰਮਾਈ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ max_ops_ਪ੍ਰਤੀ_insn;
    ਪੂਰਨ ਸਤਰ_ਅਧਾਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਸਤਰ_range;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ opcode_ਅਧਾਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ opindex;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਖਾਨਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ i;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ j;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ len;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮੁੱਲ;
    ਬਣਤਰ {
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ type;
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ form;
    } ਇੰਦਰਾਜ_format[256];
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ dir_ਮਾਪ;
#ਜੇ 0
    ਅੱਖਰ *dirs[DIR_ਸਾਰਣੀ_ਮਾਪ];
#ਜੇ_ਅੰਤ
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ filename_ਮਾਪ;
    ਬਣਤਰ /*dwarf_filename_struct*/ {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ dir_ਇੰਦਰਾਜ;
        ਅੱਖਰ *name;
    } filename_ਸਾਰਣੀ[FILE_ਸਾਰਣੀ_ਮਾਪ];
    addr_t ਆਖਰੀ_pc;
    addr_t pc;
    addr_t func_addr;
    ਪੂਰਨ ਸਤਰ;
    ਅੱਖਰ *filename;
    ਅੱਖਰ *function;

    filename = ਨਿਰਾ;
    function = ਨਿਰਾ;
    func_addr = 0;
    ਸਤਰ = 0;

    ln = rc->dwarf_ਸਤਰ;
    ਜਦੋਂ (ln < rc->dwarf_ਸਤਰ_ਸਿਰਾ) {
	dir_ਮਾਪ = 0;
	filename_ਮਾਪ = 0;
        ਆਖਰੀ_pc = 0;
        pc = 0;
        func_addr = 0;
        ਸਤਰ = 1;
        filename = ਨਿਰਾ;
        function = ਨਿਰਾ;
	ਲੰਮਾਈ = 4;
	ਮਾਪ = dwarf_read_4(ln, rc->dwarf_ਸਤਰ_ਸਿਰਾ);
	ਜੇ (ਮਾਪ == 0xffffffffu) // dwarf 64
	    ਲੰਮਾਈ = 8, ਮਾਪ = dwarf_read_8(ln, rc->dwarf_ਸਤਰ_ਸਿਰਾ);
	ਸਿਰਾ = ln + ਮਾਪ;
	ਜੇ (ਸਿਰਾ < ln || ਸਿਰਾ > rc->dwarf_ਸਤਰ_ਸਿਰਾ)
	    ਰੋਕੋ;
	ਸੰਸਕਰਣ = dwarf_read_2(ln, ਸਿਰਾ);
	ਜੇ (ਸੰਸਕਰਣ >= 5)
	    ln += ਲੰਮਾਈ + 2; // address size, segment selector, prologue Length
	ਨਹੀਂਤਾਂ
	    ln += ਲੰਮਾਈ; // prologue Length
	min_insn_ਲੰਮਾਈ = dwarf_read_1(ln, ਸਿਰਾ);
	ਜੇ (ਸੰਸਕਰਣ >= 4)
	    max_ops_ਪ੍ਰਤੀ_insn = dwarf_read_1(ln, ਸਿਰਾ);
	ਨਹੀਂਤਾਂ
	    max_ops_ਪ੍ਰਤੀ_insn = 1;
	ln++; // Initial value of 'is_stmt'
	ਸਤਰ_ਅਧਾਰ = dwarf_read_1(ln, ਸਿਰਾ);
	ਸਤਰ_ਅਧਾਰ |= ਸਤਰ_ਅਧਾਰ >= 0x80 ? ~0xff : 0;
	ਸਤਰ_range = dwarf_read_1(ln, ਸਿਰਾ);
	opcode_ਅਧਾਰ = dwarf_read_1(ln, ਸਿਰਾ);
	opcode_ਲੰਮਾਈ = ln;
	ln += opcode_ਅਧਾਰ - 1;
	opindex = 0;
	ਜੇ (ਸੰਸਕਰਣ >= 5) {
	    ਖਾਨਾ = dwarf_read_1(ln, ਸਿਰਾ);
	    ਲਈ (i = 0; i < ਖਾਨਾ; i++) {
	        ਇੰਦਰਾਜ_format[i].type = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	        ਇੰਦਰਾਜ_format[i].form = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	    }
	    dir_ਮਾਪ = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	    ਲਈ (i = 0; i < dir_ਮਾਪ; i++) {
		ਲਈ (j = 0; j < ਖਾਨਾ; j++) {
		    ਜੇ (ਇੰਦਰਾਜ_format[j].type == DW_LNCT_ਰਸਤਾ) {
		        ਜੇ (ਇੰਦਰਾਜ_format[j].form != DW_FORM_ਸਤਰ_strp)
			    ਜਾਓ ਅਗਲਾ_ਸਤਰ;
#ਜੇ 0
		        ਮੁੱਲ = ਲੰਮਾਈ == 4 ? dwarf_read_4(ln, ਸਿਰਾ)
					    : dwarf_read_8(ln, ਸਿਰਾ);
		        ਜੇ (i < DIR_ਸਾਰਣੀ_ਮਾਪ)
		            dirs[i] = (ਅੱਖਰ *)rc->dwarf_ਸਤਰ_str + ਮੁੱਲ;
#ਨਹੀਂਤਾਂ
			ਲੰਮਾਈ == 4 ? dwarf_read_4(ln, ਸਿਰਾ)
				    : dwarf_read_8(ln, ਸਿਰਾ);
#ਜੇ_ਅੰਤ
		    }
		    ਨਹੀਂਤਾਂ 
			dwarf_ignore_type(ln, ਸਿਰਾ);
		}
	    }
	    ਖਾਨਾ = dwarf_read_1(ln, ਸਿਰਾ);
	    ਲਈ (i = 0; i < ਖਾਨਾ; i++) {
	        ਇੰਦਰਾਜ_format[i].type = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	        ਇੰਦਰਾਜ_format[i].form = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	    }
	    filename_ਮਾਪ = dwarf_read_uleb128(&ln, ਸਿਰਾ);
	    ਲਈ (i = 0; i < filename_ਮਾਪ; i++)
		ਲਈ (j = 0; j < ਖਾਨਾ; j++) {
		    ਜੇ (ਇੰਦਰਾਜ_format[j].type == DW_LNCT_ਰਸਤਾ) {
			ਜੇ (ਇੰਦਰਾਜ_format[j].form != DW_FORM_ਸਤਰ_strp)
			    ਜਾਓ ਅਗਲਾ_ਸਤਰ;
			ਮੁੱਲ = ਲੰਮਾਈ == 4 ? dwarf_read_4(ln, ਸਿਰਾ)
					    : dwarf_read_8(ln, ਸਿਰਾ);
		        ਜੇ (i < FILE_ਸਾਰਣੀ_ਮਾਪ)
		            filename_ਸਾਰਣੀ[i].name =
				(ਅੱਖਰ *)rc->dwarf_ਸਤਰ_str + ਮੁੱਲ;
	            }
		    ਨਹੀਂਤਾਂ ਜੇ (ਇੰਦਰਾਜ_format[j].type == DW_LNCT_directory_ਸੂਚਕਾਂਕ) {
			ਚੋਣ (ਇੰਦਰਾਜ_format[j].form) {
			ਹਾਲਤ DW_FORM_data1: ਮੁੱਲ = dwarf_read_1(ln, ਸਿਰਾ); ਰੋਕੋ;
			ਹਾਲਤ DW_FORM_data2: ਮੁੱਲ = dwarf_read_2(ln, ਸਿਰਾ); ਰੋਕੋ;
			ਹਾਲਤ DW_FORM_data4: ਮੁੱਲ = dwarf_read_4(ln, ਸਿਰਾ); ਰੋਕੋ;
			ਹਾਲਤ DW_FORM_udata: ਮੁੱਲ = dwarf_read_uleb128(&ln, ਸਿਰਾ); ਰੋਕੋ;
			ਮੂਲ: ਜਾਓ ਅਗਲਾ_ਸਤਰ;
			}
		        ਜੇ (i < FILE_ਸਾਰਣੀ_ਮਾਪ)
		            filename_ਸਾਰਣੀ[i].dir_ਇੰਦਰਾਜ = ਮੁੱਲ;
		    }
		    ਨਹੀਂਤਾਂ 
			dwarf_ignore_type(ln, ਸਿਰਾ);
	    }
	}
	ਨਹੀਂਤਾਂ {
	    ਜਦੋਂ ((dwarf_read_1(ln, ਸਿਰਾ))) {
#ਜੇ 0
		ਜੇ (++dir_ਮਾਪ < DIR_ਸਾਰਣੀ_ਮਾਪ)
		    dirs[dir_ਮਾਪ - 1] = (ਅੱਖਰ *)ln - 1;
#ਜੇ_ਅੰਤ
		ਜਦੋਂ (dwarf_read_1(ln, ਸਿਰਾ)) {}
	    }
	    ਜਦੋਂ ((dwarf_read_1(ln, ਸਿਰਾ))) {
		ਜੇ (++filename_ਮਾਪ < FILE_ਸਾਰਣੀ_ਮਾਪ) {
		    filename_ਸਾਰਣੀ[filename_ਮਾਪ - 1].name = (ਅੱਖਰ *)ln - 1;
		    ਜਦੋਂ (dwarf_read_1(ln, ਸਿਰਾ)) {}
		    filename_ਸਾਰਣੀ[filename_ਮਾਪ - 1].dir_ਇੰਦਰਾਜ =
		        dwarf_read_uleb128(&ln, ਸਿਰਾ);
		}
		ਨਹੀਂਤਾਂ {
		    ਜਦੋਂ (dwarf_read_1(ln, ਸਿਰਾ)) {}
		    dwarf_read_uleb128(&ln, ਸਿਰਾ);
		}
		dwarf_read_uleb128(&ln, ਸਿਰਾ); //ਸਮਾਂ
		dwarf_read_uleb128(&ln, ਸਿਰਾ); //ਮਾਪ
	    }
	}
	ਜੇ (filename_ਮਾਪ >= 1)
	    filename = filename_ਸਾਰਣੀ[0].name;
	ਜਦੋਂ (ln < ਸਿਰਾ) {
	    ਆਖਰੀ_pc = pc;
	    i = dwarf_read_1(ln, ਸਿਰਾ);
	    ਜੇ (i >= opcode_ਅਧਾਰ) {
	        ਜੇ (max_ops_ਪ੍ਰਤੀ_insn == 1)
		    pc += ((i - opcode_ਅਧਾਰ) / ਸਤਰ_range) * min_insn_ਲੰਮਾਈ;
		ਨਹੀਂਤਾਂ {
		    pc += (opindex + (i - opcode_ਅਧਾਰ) / ਸਤਰ_range) /
			  max_ops_ਪ੍ਰਤੀ_insn * min_insn_ਲੰਮਾਈ;
		    opindex = (opindex + (i - opcode_ਅਧਾਰ) / ਸਤਰ_range) %
			       max_ops_ਪ੍ਰਤੀ_insn;
		}
		i = (ਪੂਰਨ)((i - opcode_ਅਧਾਰ) % ਸਤਰ_range) + ਸਤਰ_ਅਧਾਰ;
check_pc:
		ਜੇ (pc >= wanted_pc && wanted_pc >= ਆਖਰੀ_pc)
		    ਜਾਓ ਮਿਲਿਆ;
		ਸਤਰ += i;
	    }
	    ਨਹੀਂਤਾਂ {
	        ਚੋਣ (i) {
	        ਹਾਲਤ 0:
		    len = dwarf_read_uleb128(&ln, ਸਿਰਾ);
		    cp = ln;
		    ln += len;
		    ਜੇ (len == 0)
		        ਜਾਓ ਅਗਲਾ_ਸਤਰ;
		    ਚੋਣ (dwarf_read_1(cp, ਸਿਰਾ)) {
		    ਹਾਲਤ DW_LNE_ਸਿਰਾ_sequence:
		        ਰੋਕੋ;
		    ਹਾਲਤ DW_LNE_ਸੈੱਟ_ਪਤਾ:
#ਜੇ PTR_ਮਾਪ == 4
		        pc = dwarf_read_4(cp, ਸਿਰਾ);
#ਨਹੀਂਤਾਂ
		        pc = dwarf_read_8(cp, ਸਿਰਾ);
#ਜੇ_ਅੰਤ
#ਜੇ defined TCC_ਨਿਸ਼ਾਨਾ_MACHO
			pc += rc->prog_ਅਧਾਰ;
#ਜੇ_ਅੰਤ
		        opindex = 0;
		        ਰੋਕੋ;
		    ਹਾਲਤ DW_LNE_define_file: /* deprecated */
		        ਜੇ (++filename_ਮਾਪ < FILE_ਸਾਰਣੀ_ਮਾਪ) {
		            filename_ਸਾਰਣੀ[filename_ਮਾਪ - 1].name = (ਅੱਖਰ *)ln - 1;
		            ਜਦੋਂ (dwarf_read_1(ln, ਸਿਰਾ)) {}
		            filename_ਸਾਰਣੀ[filename_ਮਾਪ - 1].dir_ਇੰਦਰਾਜ =
		                dwarf_read_uleb128(&ln, ਸਿਰਾ);
		        }
		        ਨਹੀਂਤਾਂ {
		            ਜਦੋਂ (dwarf_read_1(ln, ਸਿਰਾ)) {}
		            dwarf_read_uleb128(&ln, ਸਿਰਾ);
		        }
		        dwarf_read_uleb128(&ln, ਸਿਰਾ); //ਸਮਾਂ
		        dwarf_read_uleb128(&ln, ਸਿਰਾ); //ਮਾਪ
		        ਰੋਕੋ;
		    ਹਾਲਤ DW_LNE_hi_user - 1:
		        function = (ਅੱਖਰ *)cp;
		        func_addr = pc;
		        ਰੋਕੋ;
		    ਮੂਲ:
		        ਰੋਕੋ;
		    }
		    ਰੋਕੋ;
	        ਹਾਲਤ DW_LNS_advance_pc:
		    ਜੇ (max_ops_ਪ੍ਰਤੀ_insn == 1)
		        pc += dwarf_read_uleb128(&ln, ਸਿਰਾ) * min_insn_ਲੰਮਾਈ;
		    ਨਹੀਂਤਾਂ {
		        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ off = dwarf_read_uleb128(&ln, ਸਿਰਾ);

		        pc += (opindex + off) / max_ops_ਪ੍ਰਤੀ_insn *
			      min_insn_ਲੰਮਾਈ;
		        opindex = (opindex + off) % max_ops_ਪ੍ਰਤੀ_insn;
		    }
		    i = 0;
		    ਜਾਓ check_pc;
	        ਹਾਲਤ DW_LNS_advance_ਸਤਰ:
		    ਸਤਰ += dwarf_read_sleb128(&ln, ਸਿਰਾ);
		    ਰੋਕੋ;
	        ਹਾਲਤ DW_LNS_ਸੈੱਟ_file:
		    i = dwarf_read_uleb128(&ln, ਸਿਰਾ);
		    i -= i > 0 && ਸੰਸਕਰਣ < 5;
		    ਜੇ (i < FILE_ਸਾਰਣੀ_ਮਾਪ && i < filename_ਮਾਪ)
		        filename = filename_ਸਾਰਣੀ[i].name;
		    ਰੋਕੋ;
	        ਹਾਲਤ DW_LNS_const_ਜੋੜੋ_pc:
		    ਜੇ (max_ops_ਪ੍ਰਤੀ_insn ==  1)
		        pc += ((255 - opcode_ਅਧਾਰ) / ਸਤਰ_range) * min_insn_ਲੰਮਾਈ;
		    ਨਹੀਂਤਾਂ {
		        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ off = (255 - opcode_ਅਧਾਰ) / ਸਤਰ_range;

		        pc += ((opindex + off) / max_ops_ਪ੍ਰਤੀ_insn) *
			      min_insn_ਲੰਮਾਈ;
		        opindex = (opindex + off) % max_ops_ਪ੍ਰਤੀ_insn;
		    }
		    i = 0;
		    ਜਾਓ check_pc;
	        ਹਾਲਤ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, ਸਿਰਾ);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    ਜਾਓ check_pc;
	        ਮੂਲ:
		    ਲਈ (j = 0; j < opcode_ਲੰਮਾਈ[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, ਸਿਰਾ);
		    ਰੋਕੋ;
		}
	    }
	}
ਅਗਲਾ_ਸਤਰ:
	ln = ਸਿਰਾ;
    }
    filename = function = ਨਿਰਾ, func_addr = 0;
ਮਿਲਿਆ:
    ਜੇ (filename)
        pstrcpy(bi->file, ਆਕਾਰ bi->file, filename), bi->ਸਤਰ = ਸਤਰ;
    ਜੇ (function)
        pstrcpy(bi->func, ਆਕਾਰ bi->func, function);
    bi->func_pc = func_addr;
    ਵਾਪਸ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE_ONLY
ਸਥਿਰ
#ਜੇ_ਅੰਤ
ਪੂਰਨ _tcc_backtrace(rt_ਚੌਖਟਾ *f, ਅਚਲ ਅੱਖਰ *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    ਅੱਖਰ skip[40], ਸੁਨੇਹਾ[200];
    ਪੂਰਨ i, level, ret, n, one;
    ਅਚਲ ਅੱਖਰ *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ਜੇ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ਜੇ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(ਸੁਨੇਹਾ, ਆਕਾਰ ਸੁਨੇਹਾ, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ਜੇ (rc) {
        ਜੇ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ਜੇ (rc->ਅੰਕ_callers)
            n = rc->ਅੰਕ_callers;
    }

    ਲਈ (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ਜੇ (ret == -1)
            ਰੋਕੋ;
        memset(&bi, 0, ਆਕਾਰ bi);
        ਲਈ (rc2 = rc; rc2; rc2 = rc2->ਅਗਲਾ) {
            ਜੇ (getinfo(rc2, pc, &bi))
                ਰੋਕੋ;
            /* we try symtab symbols (no line number info) */
            ਜੇ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, ਆਕਾਰ bi.func, a);
                ਰੋਕੋ;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ਜੇ (skip[0] && ਲੜੀ_ਖੋਜ(bi.file, skip))
            ਜਾਰੀ;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_ਲੱਭੋ_state(f);
            ਜੇ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_ਅੰਕੜੇ,
                    (ਖਾਲੀ*)pc,
                    bi.file[0] ? bi.file : ਨਿਰਾ,
                    bi.ਸਤਰ,
                    bi.func[0] ? bi.func : ਨਿਰਾ,
                    level == 0 ? ਸੁਨੇਹਾ : ਨਿਰਾ
                    );
                ਜੇ (ret == 0)
                    ਰੋਕੋ;
                ਜਾਓ check_break;
            }
        }
#ਜੇ_ਅੰਤ
        ਜੇ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.ਸਤਰ);
        } ਨਹੀਂਤਾਂ {
            rt_printf("0x%08llx", (ਲੰਮਾ ਲੰਮਾ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ਜੇ (level == 0) {
            rt_printf(": %s", ਸੁਨੇਹਾ);
            ਜੇ (one)
                ਰੋਕੋ;
        }
        rt_printf("\n");

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#ਜੇ_ਅੰਤ
        ਜੇ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->ਸਿਖਰ_func)
            ਰੋਕੋ;
        ++level;
    }
    rt_post_sem();
    ਵਾਪਸ 0;
}

/* emit a run time error at position 'pc' */
ਸਥਿਰ ਪੂਰਨ rt_error(rt_ਚੌਖਟਾ *f, ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap; ਅੱਖਰ ਸੁਨੇਹਾ[200]; ਪੂਰਨ ret;
    va_start(ap, fmt);
    snprintf(ਸੁਨੇਹਾ, ਆਕਾਰ ਸੁਨੇਹਾ, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, ਸੁਨੇਹਾ, ap);
    va_end(ap);
    ਵਾਪਸ ret;
}

/* ------------------------------------------------------------- */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ਨਹੀਂਤਾਂ
# define ucontext_t CONTEXT
#ਜੇ_ਅੰਤ

/* translate from ucontext_t* to internal rt_context * */
ਸਥਿਰ ਖਾਲੀ rt_getcontext(ucontext_t *uc, rt_ਚੌਖਟਾ *rc)
{
#ਜੇ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#ਜਾਂਜੇ defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#ਜਾਂਜੇ defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#ਜਾਂਜੇ defined __i386__
# ਜੇ defined(__APPLE__)
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
# ਨਹੀਂਤਾਂ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#ਜਾਂਜੇ defined(__x86_64__)
# ਜੇ defined(__APPLE__)
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
# ਨਹੀਂਤਾਂ
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#ਜਾਂਜੇ defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ਜਾਂਜੇ defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#ਜਾਂਜੇ defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ਜਾਂਜੇ defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#ਜਾਂਜੇ defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#ਜਾਂਜੇ defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#ਜਾਂਜੇ defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ਜਾਂਜੇ defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#ਜਾਂਜੇ defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#ਜਾਂਜੇ defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#ਜਾਂਜੇ defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#ਜੇ_ਅੰਤ
}

/* ------------------------------------------------------------- */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
/* signal handler for fatal errors */
ਸਥਿਰ ਖਾਲੀ sig_error(ਪੂਰਨ signum, siginfo_t *siginf, ਖਾਲੀ *puc)
{
    rt_ਚੌਖਟਾ f;
    rt_getcontext(puc, &f);

    ਚੋਣ(signum) {
    ਹਾਲਤ SIGFPE:
        ਚੋਣ(siginf->si_code) {
        ਹਾਲਤ FPE_INTDIV:
        ਹਾਲਤ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ਰੋਕੋ;
        ਮੂਲ:
            rt_error(&f, "floating point exception");
            ਰੋਕੋ;
        }
        ਰੋਕੋ;
    ਹਾਲਤ SIGBUS:
    ਹਾਲਤ SIGSEGV:
        rt_error(&f, "invalid memory access");
        ਰੋਕੋ;
    ਹਾਲਤ SIGILL:
        rt_error(&f, "illegal instruction");
        ਰੋਕੋ;
    ਹਾਲਤ SIGABRT:
        rt_error(&f, "abort() called");
        ਰੋਕੋ;
    ਮੂਲ:
        rt_error(&f, "caught signal %d", signum);
        ਰੋਕੋ;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ਨਿਰਾ);
    }
    rt_exit(&f, 255);
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#ਜੇ_ਅੰਤ

/* Generate a stack backtrace when a CPU exception occurs. */
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_exception_handler(ਖਾਲੀ)
{
    ਬਣਤਰ sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ਜੇ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#ਜੇ_ਅੰਤ
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ਨਿਰਾ);
    sigaction(SIGILL, &sigact, ਨਿਰਾ);
    sigaction(SIGSEGV, &sigact, ਨਿਰਾ);
    sigaction(SIGBUS, &sigact, ਨਿਰਾ);
    sigaction(SIGABRT, &sigact, ਨਿਰਾ);
#ਜੇ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਢੇਰ[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ਢੇਰ;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ਨਿਰਾ);
    }
#ਜੇ_ਅੰਤ
}

#ਨਹੀਂਤਾਂ /* WIN32 */

/* signal handler for fatal errors */
ਸਥਿਰ ਲੰਮਾ __stdcall cpu_exception_handler(EXCEPTION_ਸੂਚਕ_ਸਾਰੇ *ex_info)
{
    rt_ਚੌਖਟਾ f;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਕੋਡ;
    rt_getcontext(ex_info->Context_ਰਿਕਾਰਡ, &f);

    ਚੋਣ (ਕੋਡ = ex_info->Exception_ਰਿਕਾਰਡ->Exception_ਕੋਡ) {
    ਹਾਲਤ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ਰੋਕੋ;
    ਹਾਲਤ EXCEPTION_ਢੇਰ_ਉਛਾਲ:
        rt_error(&f, "stack overflow");
        ਰੋਕੋ;
    ਹਾਲਤ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ਰੋਕੋ;
    ਹਾਲਤ EXCEPTION_BREAKPOINT:
    ਹਾਲਤ EXCEPTION_SINGLE_ਕਦਮ:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ਵਾਪਸ EXCEPTION_CONTINUE_ਖੋਜ;
    ਮੂਲ:
        rt_error(&f, "caught exception %08x", ਕੋਡ);
        ਰੋਕੋ;
    }
    rt_exit(&f, 255);
    ਵਾਪਸ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ਸਥਿਰ ਖਾਲੀ ਸੈੱਟ_exception_handler(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਜੋੜੋ_Vectored_Exception_Handler(1, cpu_exception_handler);
#ਨਹੀਂਤਾਂ
    ਸੈੱਟ_Unhandled_Exception_Filter(cpu_exception_handler);
#ਜੇ_ਅੰਤ
}

#ਜੇ_ਅੰਤ

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ਜੇ defined(__i386__) || defined(__x86_64__)
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *rc, ਪੂਰਨ level)
{
    ਜੇ (level == 0) {
        *paddr = rc->ip;
    } ਨਹੀਂਤਾਂ {
        addr_t fp = rc->fp;
        ਜਦੋਂ (1) {
            ਜੇ (fp < 0x1000)
                ਵਾਪਸ -1;
            ਜੇ (0 == --level)
                ਰੋਕੋ;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ਵਾਪਸ 0;
}

/* XXX: only supports linux/bsd */
#ਜਾਂਜੇ defined(__arm__) && !defined(_WIN32)
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *rc, ਪੂਰਨ level)
{
    ਜੇ (level == 0) {
        *paddr = rc->ip;
    } ਨਹੀਂਤਾਂ {
        addr_t fp = rc->fp;
        ਜਦੋਂ (1) {
            ਜੇ (fp < 0x1000)
                ਵਾਪਸ -1;
            ਜੇ (0 == --level)
                ਰੋਕੋ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined(__aarch64__)
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *rc, ਪੂਰਨ level)
{
    ਜੇ (level == 0) {
        *paddr = rc->ip;
    } ਨਹੀਂਤਾਂ {
        addr_t fp = rc->fp;
        ਜਦੋਂ (1) {
            ਜੇ (fp < 0x1000)
                ਵਾਪਸ -1;
            ਜੇ (0 == --level)
                ਰੋਕੋ;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ਵਾਪਸ 0;
}

#ਜਾਂਜੇ defined(__riscv)
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *rc, ਪੂਰਨ level)
{
    ਜੇ (level == 0) {
        *paddr = rc->ip;
    } ਨਹੀਂਤਾਂ {
        addr_t fp = rc->fp;
        ਜਦੋਂ (1) {
            ਜੇ (fp < 0x1000)
                ਵਾਪਸ -1;
            ਜੇ (0 == --level)
                ਰੋਕੋ;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ਵਾਪਸ 0;
}

#ਨਹੀਂਤਾਂ
#warning ਜੋੜੋ arch specific rt_get_caller_pc()
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *rc, ਪੂਰਨ level)
{
    ਵਾਪਸ -1;
}

#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ਸਥਿਰ ਪੂਰਨ rt_get_caller_pc(addr_t *paddr, rt_ਚੌਖਟਾ *f, ਪੂਰਨ level)
{
    ਜੇ (level)
        ਵਾਪਸ -1;
    *paddr = f->ip;
    ਵਾਪਸ 0;
}
#ਜੇ_ਅੰਤ /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC ਖਾਲੀ *dlopen(ਅਚਲ ਅੱਖਰ *filename, ਪੂਰਨ flag)
{
    ਵਾਪਸ ਨਿਰਾ;
}

ST_FUNC ਖਾਲੀ dlclose(ਖਾਲੀ *p)
{
}

ST_FUNC ਅਚਲ ਅੱਖਰ *dlerror(ਖਾਲੀ)
{
    ਵਾਪਸ "error";
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TCCSyms {
    ਅੱਖਰ *str;
    ਖਾਲੀ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ਸਥਿਰ TCCSyms tcc_syms[] = {
#ਜੇ !defined(CONFIG_TCCBOOT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCSYM(a) { #a, &a, },
    TCCSYM(ਲਿਖੋ)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ TCCSYM
#ਜੇ_ਅੰਤ
    { ਨਿਰਾ, ਨਿਰਾ },
};

ST_FUNC ਖਾਲੀ *dlsym(ਖਾਲੀ *handle, ਅਚਲ ਅੱਖਰ *ਚਿੰਨ੍ਹ)
{
    TCCSyms *p;
    p = tcc_syms;
    ਜਦੋਂ (p->str != ਨਿਰਾ) {
        ਜੇ (!strcmp(p->str, ਚਿੰਨ੍ਹ))
            ਵਾਪਸ p->ptr;
        p++;
    }
    ਵਾਪਸ ਨਿਰਾ;
}

#ਜੇ_ਅੰਤ /* CONFIG_TCC_STATIC */
#ਜੇ_ਅੰਤ /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
