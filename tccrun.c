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
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_IS_NATIVE

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
/* runtime debug info block */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    ಒಕ್ಕೂಟ {
	ರಚನೆ {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_ಕೊನೆ;
	    ಅಕ್ಷರ *stab_str;
	};
	ರಚನೆ {
	    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *dwarf_ಸಾಲು;
	    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *dwarf_ಸಾಲು_ಕೊನೆ;
	    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *dwarf_ಸಾಲು_str;
	};
    };
    ElfW(Sym) *esym_ಆರಂಭ;
    ElfW(Sym) *esym_ಕೊನೆ;
    ಅಕ್ಷರ *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_ತಳ;
    ಶೂನ್ಯ *bounds_ಆರಂಭ;
    ಶೂನ್ಯ *ತುದಿ_func;
    ರಚನೆ rt_context *ಮುಂದಿನ;
    // 10 * PTR_SIZE
    ಪೂರ್ಣಾಂಕ ಅಂಕೆ_callers;
    ಪೂರ್ಣಾಂಕ dwarf;
} rt_context;

/* linked list of rt_contexts */
ಸ್ಥಿರ rt_context *g_rc;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ signal_ಗಣ;
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_exception_handler(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ /* def CONFIG_TCC_BACKTRACE */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ rt_ಚೌಕಟ್ಟು {
    addr_t ip, fp, sp;
} rt_ಚೌಕಟ್ಟು;

ಸ್ಥಿರ TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(ಸ್ಥಿರ rt_sem);
ಸ್ಥಿರ ಶೂನ್ಯ rt_wait_sem(ಶೂನ್ಯ) { WAIT_SEM(&rt_sem); }
ಸ್ಥಿರ ಶೂನ್ಯ rt_post_sem(ಶೂನ್ಯ) { POST_SEM(&rt_sem); }
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *f, ಪೂರ್ಣಾಂಕ level);
ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_ಚೌಕಟ್ಟು *f, ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_BACKTRACE_ONLY

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
# include <sys/mman.h>
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ protect_ಪುಟಗಳು(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಉದ್ದಳತೆ, ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_relocate_ex(TCCState *s1, ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ptr_diff);
ಸ್ಥಿರ ಶೂನ್ಯ st_link(TCCState *s1);
ಸ್ಥಿರ ಶೂನ್ಯ st_unlink(TCCState *s1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ _tcc_backtrace(rt_ಚೌಕಟ್ಟು *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap);
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ *win64_ಕೂಡಿಸು_function_ಕೋಷ್ಟಕ(TCCState *s1);
ಸ್ಥಿರ ಶೂನ್ಯ win64_del_function_ಕೋಷ್ಟಕ(ಶೂನ್ಯ *);
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined PAGESIZE
# ಆದರೆ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# ಇಲ್ಲದಿದ್ದರೆ
#  define PAGESIZE 4096
# endif
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#ಆದರೆ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#ಆದರೆ_ಅಂತ್ಯ

/* use VirtualAlloc() instead of tcc_malloc() */
#ಆದರೆ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_mem(TCCState *s1, ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2)
{
    ಶೂನ್ಯ *ptr;
    ಪೂರ್ಣಾಂಕ ptr_diff = 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_SELINUX
    /* Using mmap instead of malloc */
    ಶೂನ್ಯ *prw;
    ಅಕ್ಷರ tmpfname[] = "/tmp/.tccrunXXXXXX";
    ಪೂರ್ಣಾಂಕ fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, ಗಾತ್ರ_2);

    ptr = mmap(ಖಾಲಿ, ಗಾತ್ರ_2 * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((ಅಕ್ಷರ*)ptr + ಗಾತ್ರ_2, ಗಾತ್ರ_2, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    ಆದರೆ (ptr == MAP_FAILED || prw == MAP_FAILED)
	ಹಿಂತಿರುಗಿ tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (ಅಕ್ಷರ*)prw - (ಅಕ್ಷರ*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    ಗಾತ್ರ_2 *= 2;
#ಅಥವಾಆದರೆ CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(ಖಾಲಿ, ಗಾತ್ರ_2, MEM_RESERVE | MEM_COMMIT, ಪುಟ_READWRITE);
    ಆದರೆ (!ptr)
        ಹಿಂತಿರುಗಿ tcc_error_noabort("tccrun: could not allocate memory");
#ಇಲ್ಲದಿದ್ದರೆ
    ptr = tcc_malloc(ಗಾತ್ರ_2 += PAGESIZE); /* one extra page to align malloc memory */
#ಆದರೆ_ಅಂತ್ಯ
    s1->ಸತತ_ptr = ptr;
    s1->ಸತತ_ಗಾತ್ರ = ಗಾತ್ರ_2;
    ಹಿಂತಿರುಗಿ ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_relocate(TCCState *s1)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2, ret, ptr_diff;

    ಆದರೆ (s1->ಸತತ_ptr)
        ನಿರ್ಗಮಿಸು(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ಆದರೆ (s1->do_backtrace)
        tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#ಆದರೆ_ಅಂತ್ಯ
    ಗಾತ್ರ_2 = tcc_relocate_ex(s1, ಖಾಲಿ, 0);
    ಆದರೆ (ಗಾತ್ರ_2 < 0)
        ಹಿಂತಿರುಗಿ -1;
    ptr_diff = rt_mem(s1, ಗಾತ್ರ_2);
    ಆದರೆ (ptr_diff < 0)
        ಹಿಂತಿರುಗಿ -1;
    ret = tcc_relocate_ex(s1, s1->ಸತತ_ptr, ptr_diff);
    ಆದರೆ (ret == 0)
        st_link(s1);
    ಹಿಂತಿರುಗಿ ret;
}

ST_FUNC ಶೂನ್ಯ tcc_ಸತತ_free(TCCState *s1)
{
    ಚಿಹ್ನೆರಹಿತ ಗಾತ್ರ_2;
    ಶೂನ್ಯ *ptr;
    ಪೂರ್ಣಾಂಕ i;

    /* free any loaded DLLs */
    ಗಾಗಿ ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        ಆದರೆ ( ref->handle )
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
            FreeLibrary((HMODULE)ref->handle);
#ಇಲ್ಲದಿದ್ದರೆ
            dlclose(ref->handle);
#ಆದರೆ_ಅಂತ್ಯ
    }
    /* unmap or unprotect and free memory */
    ptr = s1->ಸತತ_ptr;
    ಆದರೆ (ಖಾಲಿ == ptr)
        ಹಿಂತಿರುಗಿ;
    st_unlink(s1);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    win64_del_function_ಕೋಷ್ಟಕ(s1->ಸತತ_function_ಕೋಷ್ಟಕ);
#ಆದರೆ_ಅಂತ್ಯ
    ಗಾತ್ರ_2 = s1->ಸತತ_ಗಾತ್ರ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_SELINUX
    munmap(ptr, ಗಾತ್ರ_2);
#ಅಥವಾಆದರೆ CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, ಗಾತ್ರ_2, MEM_RELEASE);
#ಇಲ್ಲದಿದ್ದರೆ
    /* unprotect memory to make it usable for malloc again */
    protect_ಪುಟಗಳು((ಶೂನ್ಯ*)PAGEALIGN(ptr), ಗಾತ್ರ_2 - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#ಆದರೆ_ಅಂತ್ಯ
}

#ವ್ಯಾಖ್ಯಾನಿಸು RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI ಪೂರ್ಣಾಂಕ tcc_ಸತತ(TCCState *s1, ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ (*prog_main)(ಪೂರ್ಣಾಂಕ, ಅಕ್ಷರ **, ಅಕ್ಷರ **), ret;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ತುದಿ_sym;
    jmp_buf main_jb;

#ಆದರೆ defined(__APPLE__)
    ಬಾಹ್ಯ ಅಕ್ಷರ ***_NSGetEnviron(ಶೂನ್ಯ);
    ಅಕ್ಷರ **envp = *_NSGetEnviron();
#ಅಥವಾಆದರೆ defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    ಬಾಹ್ಯ ಅಕ್ಷರ **environ;
    ಅಕ್ಷರ **envp = environ;
#ಇಲ್ಲದಿದ್ದರೆ
    ಅಕ್ಷರ **envp = environ;
#ಆದರೆ_ಅಂತ್ಯ

    /* tcc -dt -run ... nothing to do if no main() */
    ಆದರೆ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ಹಿಂತಿರುಗಿ 0;

    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s1, "__rt_exit", rt_exit);
    s1->ಸತತ_main = "_runmain", ತುದಿ_sym = "main";
    ಆದರೆ (s1->elf_entryname)
        s1->ಸತತ_main = ತುದಿ_sym = s1->elf_entryname;
    tcc_ಕೂಡಿಸು_support(s1, "runmain.o");

    ಆದರೆ (tcc_relocate(s1) < 0)
        ಹಿಂತಿರುಗಿ -1;

    prog_main = (ಶೂನ್ಯ*)get_sym_addr(s1, s1->ಸತತ_main, 1, 1);
    ಆದರೆ ((addr_t)-1 == (addr_t)prog_main)
        ಹಿಂತಿರುಗಿ -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    ಆದರೆ (s1->ಸತತ_stdin && !freopen(s1->ಸತತ_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->ಸತತ_stdin);
        ಹಿಂತಿರುಗಿ -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_ಚಿಹ್ನೆ(s1, ತುದಿ_sym));
    ಆದರೆ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    ಆದರೆ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ಹಿಂತಿರುಗಿ ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
ಸ್ಥಿರ ಶೂನ್ಯ cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    ಪೂರ್ಣಾಂಕ sym_ಸೂಚ್ಯಂಕ, ಕೊನೆ_sym = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (ElfSym);
    /* reset symtab */
    s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = s->link->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = s->hash->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ = 0;
    init_symtab(s);
    /* add global symbols again */
    ಗಾಗಿ (sym_ಸೂಚ್ಯಂಕ = 1; sym_ಸೂಚ್ಯಂಕ < ಕೊನೆ_sym; ++sym_ಸೂಚ್ಯಂಕ) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->ದತ್ತಾಂಶ)[sym_ಸೂಚ್ಯಂಕ];
        ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name = (ಅಕ್ಷರ *)s->link->ದತ್ತಾಂಶ + sym->st_name;
        ಆದರೆ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            ಮುಂದುವರಿ;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_ಮೌಲ್ಯ, sym->st_ಗಾತ್ರ, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
ಸ್ಥಿರ ಶೂನ್ಯ cleanup_sections(TCCState *s1)
{
    ರಚನೆ { Section **secs; ಪೂರ್ಣಾಂಕ nb_secs; } *p = (ಶೂನ್ಯ*)&s1->sections;
    ಪೂರ್ಣಾಂಕ i, f = 2;
    ಮಾಡು {
        ಗಾಗಿ (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            ಆದರೆ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->ದತ್ತಾಂಶ = tcc_realloc(s->ದತ್ತಾಂಶ, s->ದತ್ತಾಂಶ_allocated = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
            } ಇಲ್ಲದಿದ್ದರೆ {
                free_section(s), tcc_free(s), p->secs[i] = ಖಾಲಿ;
            }
        }
    } ಆಗ (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# ಇಲ್ಲದಿದ್ದರೆ
#   define CONFIG_RUNMEM_RO 0
#  endif
#ಆದರೆ_ಅಂತ್ಯ

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tcc_relocate_ex(TCCState *s1, ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ptr_diff)
{
    Section *s;
    ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ, ಉದ್ದಳತೆ, align, i, k, f;
    ಚಿಹ್ನೆರಹಿತ n, copy;
    addr_t mem, addr;

    ಆದರೆ (ಖಾಲಿ == ptr) {
        s1->nb_errors = 0;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
        pe_output_file(s1, ಖಾಲಿ);
#ಇಲ್ಲದಿದ್ದರೆ
        tcc_ಕೂಡಿಸು_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#ಆದರೆ_ಅಂತ್ಯ
    }

    ಸ್ಥಾನಾಂತರ = copy = 0;
    mem = (addr_t)ptr;
redo:
    ಆದರೆ (s1->verbose == 2 && copy)
        ಬರೆ(&"-----------------------------------------------------\n"[PTR_ಗಾತ್ರ*2 - 8]);
    ಆದರೆ (s1->nb_errors)
        ಹಿಂತಿರುಗಿ -1;
    ಆದರೆ (copy == 3)
        ಹಿಂತಿರುಗಿ 0;

    ಗಾಗಿ (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        ಗಾಗಿ(i = 1; i < s1->nb_sections; i++) {
            ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            ಆದರೆ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                ಮುಂದುವರಿ;
            ಉದ್ದಳತೆ = s->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ;
            ಆದರೆ (copy == 2) {
                ಆದರೆ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + ಉದ್ದಳತೆ;
                ಮುಂದುವರಿ;
            }
            ಆದರೆ (copy) { /* final step: copy section data to memory */
                ಆದರೆ (s1->verbose == 2)
                    ಬರೆ("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (ಶೂನ್ಯ*)s->sh_addr, ಉದ್ದಳತೆ, s->sh_addralign);
                ptr = (ಶೂನ್ಯ*)s->sh_addr;
                ಆದರೆ (k == 0)
                    ptr = (ಶೂನ್ಯ*)(s->sh_addr + ptr_diff);
                ಆದರೆ (ಖಾಲಿ == s->ದತ್ತಾಂಶ || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, ಉದ್ದಳತೆ);
                ಇಲ್ಲದಿದ್ದರೆ
                    ಸ್ಮರಣೆ_ನಕಲು(ptr, s->ದತ್ತಾಂಶ, ಉದ್ದಳತೆ);
                ಮುಂದುವರಿ;
            }

            ಆದರೆ ((s->sh_flags & SHF_TLS) && ಉದ್ದಳತೆ)
                ಹಿಂತಿರುಗಿ tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            ಆದರೆ (++n == 1) {
#ಆದರೆ defined TCC_ಗುರಿ_I386 || defined TCC_ಗುರಿ_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                ಆದರೆ (align < 64)
                    align = 64;
#ಆದರೆ_ಅಂತ್ಯ
                /* start new page for different permissions */
                ಆದರೆ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            ಸ್ಥಾನಾಂತರ += -(addr + ಸ್ಥಾನಾಂತರ) & (align - 1);
            s->sh_addr = mem ? addr + ಸ್ಥಾನಾಂತರ : 0;
            ಸ್ಥಾನಾಂತರ += ಉದ್ದಳತೆ;
        }
        ಆದರೆ (copy == 2) { /* set permissions */
            ಆದರೆ (n == 0) /* no data  */
                ಮುಂದುವರಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_SELINUX
            ಆದರೆ (k == 0) /* SHF_EXECINSTR has its own mapping */
                ಮುಂದುವರಿ;
#ಆದರೆ_ಅಂತ್ಯ
            f = k;
            ಆದರೆ (f >= CONFIG_RUNMEM_RO) {
                ಆದರೆ (f != 0)
                    ಮುಂದುವರಿ;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            ಆದರೆ (s1->verbose == 2) {
                ಬರೆ("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (ಶೂನ್ಯ*)addr, (ಚಿಹ್ನೆರಹಿತ)n);
            }
            ಆದರೆ (protect_ಪುಟಗಳು((ಶೂನ್ಯ*)addr, n, f) < 0)
                ಹಿಂತಿರುಗಿ tcc_error_noabort(
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
                    "VirtualProtect failed");
#ಇಲ್ಲದಿದ್ದರೆ
                    "mprotect failed (did you mean to configure --with-selinux?)");
#ಆದರೆ_ಅಂತ್ಯ
        }
    }

    ಆದರೆ (0 == mem)
        ಹಿಂತಿರುಗಿ PAGEALIGN(ಸ್ಥಾನಾಂತರ);

    ಆದರೆ (++copy == 2) {
        ಹೋಗು redo;
    }
    ಆದರೆ (copy == 3) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
        s1->ಸತತ_function_ಕೋಷ್ಟಕ = win64_ಕೂಡಿಸು_function_ಕೋಷ್ಟಕ(s1);
#ಆದರೆ_ಅಂತ್ಯ
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        ಹೋಗು redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    ಆದರೆ (s1->nb_errors)
        ಹೋಗು redo;
    /* relocate sections */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ TCC_ಗುರಿ_PE
    s1->pe_imagebase = mem;
#ಇಲ್ಲದಿದ್ದರೆ
    relocate_plt(s1);
#ಆದರೆ_ಅಂತ್ಯ
    relocate_sections(s1);
    ಹೋಗು redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ protect_ಪುಟಗಳು(ಶೂನ್ಯ *ptr, ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಉದ್ದಳತೆ, ಪೂರ್ಣಾಂಕ ಬಹುಲಕ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ protect[] = {
        ಪುಟ_EXECUTE_READ,
        ಪುಟ_READONLY,
        ಪುಟ_READWRITE,
        ಪುಟ_EXECUTE_READWRITE
        };
    DWORD old;
    ಆದರೆ (!VirtualProtect(ptr, ಉದ್ದಳತೆ, protect[ಬಹುಲಕ], &old))
        ಹಿಂತಿರುಗಿ -1;
#ಇಲ್ಲದಿದ್ದರೆ
    ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    ಆದರೆ (mprotect(ptr, ಉದ್ದಳತೆ, protect[ಬಹುಲಕ]))
        ಹಿಂತಿರುಗಿ -1;
#ಆದರೆ_ಅಂತ್ಯ
/* XXX: BSD sometimes dump core with bad system call */
#ಆದರೆ (defined TCC_ಗುರಿ_ARM && !TARGETOS_BSD) \
    || defined TCC_ಗುರಿ_ARM64 || defined TCC_ಗುರಿ_RISCV64
    ಆದರೆ (ಬಹುಲಕ == 0 || ಬಹುಲಕ == 3) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, ಉದ್ದಳತೆ);
#ಇಲ್ಲದಿದ್ದರೆ
        ಶೂನ್ಯ __clear_cache(ಶೂನ್ಯ *beginning, ಶೂನ್ಯ *ಕೊನೆ);
        __clear_cache(ptr, (ಅಕ್ಷರ *)ptr + ಉದ್ದಳತೆ);
#ಆದರೆ_ಅಂತ್ಯ
    }
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ 0;
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ *win64_ಕೂಡಿಸು_function_ಕೋಷ್ಟಕ(TCCState *s1)
{
    ಶೂನ್ಯ *p = ಖಾಲಿ;
    ಆದರೆ (s1->uw_pdata) {
        p = (ಶೂನ್ಯ*)s1->uw_pdata->sh_addr;
        Rtl_ಕೂಡಿಸು_Function_ಕೋಷ್ಟಕ(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ / ಗಾತ್ರ (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = ಖಾಲಿ;
    }
    ಹಿಂತಿರುಗಿ p;
}

ಸ್ಥಿರ ಶೂನ್ಯ win64_del_function_ಕೋಷ್ಟಕ(ಶೂನ್ಯ *p)
{
    ಆದರೆ (p) {
        Rtl_Delete_Function_ಕೋಷ್ಟಕ((RUNTIME_FUNCTION*)p);
    }
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಶೂನ್ಯ bt_link(TCCState *s1)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    rt_context *rc;
    ಆದರೆ (!s1->do_backtrace)
        ಹಿಂತಿರುಗಿ;
    rc = tcc_get_ಚಿಹ್ನೆ(s1, "__rt_info");
    ಆದರೆ (!rc)
        ಹಿಂತಿರುಗಿ;
    rc->esym_ಆರಂಭ = (ElfW(Sym) *)(symtab_section->ದತ್ತಾಂಶ);
    rc->esym_ಕೊನೆ = (ElfW(Sym) *)(symtab_section->ದತ್ತಾಂಶ + symtab_section->ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ);
    rc->elf_str = (ಅಕ್ಷರ *)symtab_section->link->ದತ್ತಾಂಶ;
    ಆದರೆ (PTR_ಗಾತ್ರ == 8 && !s1->dwarf)
        rc->prog_ತಳ &= 0xffffffff00000000ULL;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
    ಆದರೆ (s1->do_bounds_check) {
        ಶೂನ್ಯ *p;
        ಆದರೆ ((p = tcc_get_ಚಿಹ್ನೆ(s1, "__bound_init")))
            ((ಶೂನ್ಯ(*)(ಶೂನ್ಯ*,ಪೂರ್ಣಾಂಕ))p)(rc->bounds_ಆರಂಭ, 1);
    }
#ಆದರೆ_ಅಂತ್ಯ
    rc->ಮುಂದಿನ = g_rc, g_rc = rc, s1->rc = rc;
    ಆದರೆ (0 == signal_ಗಣ)
        ಗಣ_exception_handler(), signal_ಗಣ = 1;
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ಶೂನ್ಯ st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->ಮುಂದಿನ = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
ಸ್ಥಿರ ಶೂನ್ಯ ptr_unlink(ಶೂನ್ಯ *list, ಶೂನ್ಯ *e, ಚಿಹ್ನೆರಹಿತ ಮುಂದಿನ)
{
    ಶೂನ್ಯ **pp, **nn, *p;
    ಗಾಗಿ (pp = list; !!(p = *pp); pp = nn) {
        nn = (ಶೂನ್ಯ*)((ಅಕ್ಷರ*)p + ಮುಂದಿನ); /* nn = &p->next; */
        ಆದರೆ (p == e) {
            *pp = *nn;
            ನಿಲ್ಲಿಸು;
        }
    }
}

ಸ್ಥಿರ ಶೂನ್ಯ st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, ಮುಂದಿನ));
#ಆದರೆ_ಅಂತ್ಯ
    ptr_unlink(&g_s1, s1, offsetof(TCCState, ಮುಂದಿನ));
    rt_post_sem();
}

LIBTCCAPI ಶೂನ್ಯ *_tcc_setjmp(TCCState *s1, ಶೂನ್ಯ *p_jmp_buf, ಶೂನ್ಯ *func, ಶೂನ್ಯ *p_longjmp)
{
    s1->ಸತತ_lj = p_longjmp;
    s1->ಸತತ_jb = p_jmp_buf;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE
    ಆದರೆ (s1->rc)
        s1->rc->ತುದಿ_func = func;
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ p_jmp_buf;
}

LIBTCCAPI ಶೂನ್ಯ tcc_ಗಣ_backtrace_func(TCCState *s1, ಶೂನ್ಯ *ದತ್ತಾಂಶ, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_ದತ್ತಾಂಶ = ದತ್ತಾಂಶ;
}

ಸ್ಥಿರ TCCState *rt_ಕಂಡುಹಿಡಿ_state(rt_ಚೌಕಟ್ಟು *f)
{
    TCCState *s;
    ಪೂರ್ಣಾಂಕ level;
    addr_t pc;

    s = g_s1;
    ಆದರೆ (ಖಾಲಿ == s || ಖಾಲಿ == s->ಮುಂದಿನ) {
        /* play it safe in the simple case when there is only one state */
        ಹಿಂತಿರುಗಿ s;
    }
    ಗಾಗಿ (level = 0; level < 8; ++level) {
        ಆದರೆ (rt_get_caller_pc(&pc, f, level) < 0)
            ನಿಲ್ಲಿಸು;
        ಗಾಗಿ (s = g_s1; s; s = s->ಮುಂದಿನ) {
            ಆದರೆ (pc >= (addr_t)s->ಸತತ_ptr
             && pc  < (addr_t)s->ಸತತ_ptr + s->ಸತತ_ಗಾತ್ರ)
                ಹಿಂತಿರುಗಿ s;
        }
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_ಚೌಕಟ್ಟು *f, ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_ಕಂಡುಹಿಡಿ_state(f);
    rt_post_sem();
    ಆದರೆ (s && s->ಸತತ_lj) {
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BCHECK
        ಆದರೆ (f->fp) { /* called from signal */
            ಶೂನ್ಯ *p = tcc_get_ಚಿಹ್ನೆ(s, "__bound_exit");
            ಆದರೆ (p)
                ((ಶೂನ್ಯ (*)(ಶೂನ್ಯ))p)();
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (ಸಂಕೇತ_2 == 0)
            ಸಂಕೇತ_2 = RT_EXIT_ZERO;
        ((ಶೂನ್ಯ(*)(ಶೂನ್ಯ*,ಪೂರ್ಣಾಂಕ))s->ಸತತ_lj)(s->ಸತತ_jb, ಸಂಕೇತ_2);
    }
    ನಿರ್ಗಮಿಸು(ಸಂಕೇತ_2);
}

/* ------------------------------------------------------------- */
#ಇಲ್ಲದಿದ್ದರೆ // if defined CONFIG_TCC_BACKTRACE_ONLY
ಸ್ಥಿರ ಶೂನ್ಯ rt_exit(rt_ಚೌಕಟ್ಟು *f, ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2)
{
    ನಿರ್ಗಮಿಸು(ಸಂಕೇತ_2);
}
#ಆದರೆ_ಅಂತ್ಯ //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_BACKTRACE

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_vprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap)
{
    ಪೂರ್ಣಾಂಕ ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ಹಿಂತಿರುಗಿ ret;
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_printf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap;
    ಪೂರ್ಣಾಂಕ r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ಹಿಂತಿರುಗಿ r;
}

ಸ್ಥಿರ ಅಕ್ಷರ *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    ಗಾಗಿ (esym = rc->esym_ಆರಂಭ + 1; esym < rc->esym_ಕೊನೆ; ++esym) {
        ಪೂರ್ಣಾಂಕ type = ELFW(ST_TYPE)(esym->st_info);
        ಆದರೆ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_ಮೌಲ್ಯ
            && wanted_pc < esym->st_ಮೌಲ್ಯ + esym->st_ಗಾತ್ರ) {
            *func_addr = esym->st_ಮೌಲ್ಯ;
            ಹಿಂತಿರುಗಿ rc->elf_str + esym->st_name;
        }
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ bt_info
{
    ಅಕ್ಷರ file[100];
    ಪೂರ್ಣಾಂಕ ಸಾಲು;
    ಅಕ್ಷರ func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
ಸ್ಥಿರ addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ಅಕ್ಷರ func_name[128];
    addr_t func_addr, ಕೊನೆಯ_pc, pc;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *incl_files[INCLUDE_ರಾಶಿ_ಗಾತ್ರ];
    ಪೂರ್ಣಾಂಕ incl_ಸೂಚ್ಯಂಕ, ಕೊನೆಯ_incl_ಸೂಚ್ಯಂಕ, len, ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ, i;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_ಸೂಚ್ಯಂಕ = 0;
    ಕೊನೆಯ_pc = (addr_t)-1;
    ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = 1;
    ಕೊನೆಯ_incl_ಸೂಚ್ಯಂಕ = 0;

    ಗಾಗಿ (sym = rc->stab_sym + 1; sym < rc->stab_sym_ಕೊನೆ; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_ಮೌಲ್ಯ;

        ಆಯ್ಕೆ(sym->n_type) {
        ಸ್ಥಿತಿ N_SLINE:
            ಆದರೆ (func_addr)
                ಹೋಗು rel_pc;
        ಸ್ಥಿತಿ N_SO:
        ಸ್ಥಿತಿ N_SOL:
            ಹೋಗು abs_pc;
        ಸ್ಥಿತಿ N_FUN:
            ಆದರೆ (sym->n_strx == 0) /* end of function */
                ಹೋಗು rel_pc;
        abs_pc:
#ಆದರೆ PTR_ಗಾತ್ರ == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_ತಳ;
#ಆದರೆ_ಅಂತ್ಯ
            ಹೋಗು check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            ಆದರೆ (pc >= wanted_pc && wanted_pc >= ಕೊನೆಯ_pc)
                ಹೋಗು ಸಿಕ್ಕಿತು;
            ನಿಲ್ಲಿಸು;
        }

        ಆಯ್ಕೆ(sym->n_type) {
            /* function start or end */
        ಸ್ಥಿತಿ N_FUN:
            ಆದರೆ (sym->n_strx == 0)
                ಹೋಗು reset_func;
            p = strchr(str, ':');
            ಆದರೆ (0 == p || (len = p - str + 1, len > ಗಾತ್ರ func_name))
                len = ಗಾತ್ರ func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            ನಿಲ್ಲಿಸು;
            /* line number info */
        ಸ್ಥಿತಿ N_SLINE:
            ಕೊನೆಯ_pc = pc;
            ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ = sym->n_desc;
            ಕೊನೆಯ_incl_ಸೂಚ್ಯಂಕ = incl_ಸೂಚ್ಯಂಕ;
            ನಿಲ್ಲಿಸು;
            /* include files */
        ಸ್ಥಿತಿ N_BINCL:
            ಆದರೆ (incl_ಸೂಚ್ಯಂಕ < INCLUDE_ರಾಶಿ_ಗಾತ್ರ)
                incl_files[incl_ಸೂಚ್ಯಂಕ++] = str;
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ N_EINCL:
            ಆದರೆ (incl_ಸೂಚ್ಯಂಕ > 1)
                incl_ಸೂಚ್ಯಂಕ--;
            ನಿಲ್ಲಿಸು;
            /* start/end of translation unit */
        ಸ್ಥಿತಿ N_SO:
            incl_ಸೂಚ್ಯಂಕ = 0;
            ಆದರೆ (sym->n_strx) {
                /* do not add path */
                len = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str);
                ಆದರೆ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_ಸೂಚ್ಯಂಕ++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            ಕೊನೆಯ_pc = (addr_t)-1;
            ನಿಲ್ಲಿಸು;
            /* alternative file name (from #line or #include directives) */
        ಸ್ಥಿತಿ N_SOL:
            ಆದರೆ (incl_ಸೂಚ್ಯಂಕ)
                incl_files[incl_ಸೂಚ್ಯಂಕ-1] = str;
            ನಿಲ್ಲಿಸು;
        }
    }
    ಕೊನೆಯ_incl_ಸೂಚ್ಯಂಕ = 0, func_name[0] = 0, func_addr = 0;
ಸಿಕ್ಕಿತು:
    i = ಕೊನೆಯ_incl_ಸೂಚ್ಯಂಕ;
    ಆದರೆ (i > 0) {
        pstrcpy(bi->file, ಗಾತ್ರ bi->file, incl_files[--i]);
        bi->ಸಾಲು = ಕೊನೆಯ_ಸಾಲು_ಅಂಕೆ;
    }
    pstrcpy(bi->func, ಗಾತ್ರ bi->func, func_name);
    bi->func_pc = func_addr;
    ಹಿಂತಿರುಗಿ func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#ವ್ಯಾಖ್ಯಾನಿಸು DIR_ಕೋಷ್ಟಕ_ಗಾತ್ರ	(64)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ	(512)

#ವ್ಯಾಖ್ಯಾನಿಸು	dwarf_ignore_type(ln, ಕೊನೆ) /* timestamp/size/md5/... */ \
	ಆಯ್ಕೆ (ನಮೂದು_format[j].form) { \
	ಸ್ಥಿತಿ DW_FORM_data1: (ln) += 1; ನಿಲ್ಲಿಸು; \
	ಸ್ಥಿತಿ DW_FORM_data2: (ln) += 2; ನಿಲ್ಲಿಸು; \
	ಸ್ಥಿತಿ DW_FORM_data4: (ln) += 3; ನಿಲ್ಲಿಸು; \
	ಸ್ಥಿತಿ DW_FORM_data8: (ln) += 8; ನಿಲ್ಲಿಸು; \
	ಸ್ಥಿತಿ DW_FORM_data16: (ln) += 16; ನಿಲ್ಲಿಸು; \
	ಸ್ಥಿತಿ DW_FORM_udata: dwarf_read_uleb128(&(ln), (ಕೊನೆ)); ನಿಲ್ಲಿಸು; \
	ಪೂರ್ವನಿಯೋಜಿತ: ಹೋಗು ಮುಂದಿನ_ಸಾಲು; \
	}

ಸ್ಥಿರ addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ln;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *cp;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಕೊನೆ;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *opcode_ಉದ್ದಳತೆ;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಗಾತ್ರ_2;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಉದ್ದಳತೆ;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಆವೃತ್ತಿ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ min_insn_ಉದ್ದಳತೆ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ max_ops_ಪ್ರತಿ_insn;
    ಪೂರ್ಣಾಂಕ ಸಾಲು_ತಳ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಸಾಲು_range;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ opcode_ತಳ;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ opindex;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಲಂಬಸಾಲು;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ i;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ j;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ len;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಮೌಲ್ಯ;
    ರಚನೆ {
	ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ type;
	ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ form;
    } ನಮೂದು_format[256];
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ dir_ಗಾತ್ರ;
#ಆದರೆ 0
    ಅಕ್ಷರ *dirs[DIR_ಕೋಷ್ಟಕ_ಗಾತ್ರ];
#ಆದರೆ_ಅಂತ್ಯ
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ filename_ಗಾತ್ರ;
    ರಚನೆ /*dwarf_filename_struct*/ {
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ dir_ನಮೂದು;
        ಅಕ್ಷರ *name;
    } filename_ಕೋಷ್ಟಕ[FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ];
    addr_t ಕೊನೆಯ_pc;
    addr_t pc;
    addr_t func_addr;
    ಪೂರ್ಣಾಂಕ ಸಾಲು;
    ಅಕ್ಷರ *filename;
    ಅಕ್ಷರ *function;

    filename = ಖಾಲಿ;
    function = ಖಾಲಿ;
    func_addr = 0;
    ಸಾಲು = 0;

    ln = rc->dwarf_ಸಾಲು;
    ಆಗ (ln < rc->dwarf_ಸಾಲು_ಕೊನೆ) {
	dir_ಗಾತ್ರ = 0;
	filename_ಗಾತ್ರ = 0;
        ಕೊನೆಯ_pc = 0;
        pc = 0;
        func_addr = 0;
        ಸಾಲು = 1;
        filename = ಖಾಲಿ;
        function = ಖಾಲಿ;
	ಉದ್ದಳತೆ = 4;
	ಗಾತ್ರ_2 = dwarf_read_4(ln, rc->dwarf_ಸಾಲು_ಕೊನೆ);
	ಆದರೆ (ಗಾತ್ರ_2 == 0xffffffffu) // dwarf 64
	    ಉದ್ದಳತೆ = 8, ಗಾತ್ರ_2 = dwarf_read_8(ln, rc->dwarf_ಸಾಲು_ಕೊನೆ);
	ಕೊನೆ = ln + ಗಾತ್ರ_2;
	ಆದರೆ (ಕೊನೆ < ln || ಕೊನೆ > rc->dwarf_ಸಾಲು_ಕೊನೆ)
	    ನಿಲ್ಲಿಸು;
	ಆವೃತ್ತಿ = dwarf_read_2(ln, ಕೊನೆ);
	ಆದರೆ (ಆವೃತ್ತಿ >= 5)
	    ln += ಉದ್ದಳತೆ + 2; // address size, segment selector, prologue Length
	ಇಲ್ಲದಿದ್ದರೆ
	    ln += ಉದ್ದಳತೆ; // prologue Length
	min_insn_ಉದ್ದಳತೆ = dwarf_read_1(ln, ಕೊನೆ);
	ಆದರೆ (ಆವೃತ್ತಿ >= 4)
	    max_ops_ಪ್ರತಿ_insn = dwarf_read_1(ln, ಕೊನೆ);
	ಇಲ್ಲದಿದ್ದರೆ
	    max_ops_ಪ್ರತಿ_insn = 1;
	ln++; // Initial value of 'is_stmt'
	ಸಾಲು_ತಳ = dwarf_read_1(ln, ಕೊನೆ);
	ಸಾಲು_ತಳ |= ಸಾಲು_ತಳ >= 0x80 ? ~0xff : 0;
	ಸಾಲು_range = dwarf_read_1(ln, ಕೊನೆ);
	opcode_ತಳ = dwarf_read_1(ln, ಕೊನೆ);
	opcode_ಉದ್ದಳತೆ = ln;
	ln += opcode_ತಳ - 1;
	opindex = 0;
	ಆದರೆ (ಆವೃತ್ತಿ >= 5) {
	    ಲಂಬಸಾಲು = dwarf_read_1(ln, ಕೊನೆ);
	    ಗಾಗಿ (i = 0; i < ಲಂಬಸಾಲು; i++) {
	        ನಮೂದು_format[i].type = dwarf_read_uleb128(&ln, ಕೊನೆ);
	        ನಮೂದು_format[i].form = dwarf_read_uleb128(&ln, ಕೊನೆ);
	    }
	    dir_ಗಾತ್ರ = dwarf_read_uleb128(&ln, ಕೊನೆ);
	    ಗಾಗಿ (i = 0; i < dir_ಗಾತ್ರ; i++) {
		ಗಾಗಿ (j = 0; j < ಲಂಬಸಾಲು; j++) {
		    ಆದರೆ (ನಮೂದು_format[j].type == DW_LNCT_ಮಾರ್ಗ) {
		        ಆದರೆ (ನಮೂದು_format[j].form != DW_FORM_ಸಾಲು_strp)
			    ಹೋಗು ಮುಂದಿನ_ಸಾಲು;
#ಆದರೆ 0
		        ಮೌಲ್ಯ = ಉದ್ದಳತೆ == 4 ? dwarf_read_4(ln, ಕೊನೆ)
					    : dwarf_read_8(ln, ಕೊನೆ);
		        ಆದರೆ (i < DIR_ಕೋಷ್ಟಕ_ಗಾತ್ರ)
		            dirs[i] = (ಅಕ್ಷರ *)rc->dwarf_ಸಾಲು_str + ಮೌಲ್ಯ;
#ಇಲ್ಲದಿದ್ದರೆ
			ಉದ್ದಳತೆ == 4 ? dwarf_read_4(ln, ಕೊನೆ)
				    : dwarf_read_8(ln, ಕೊನೆ);
#ಆದರೆ_ಅಂತ್ಯ
		    }
		    ಇಲ್ಲದಿದ್ದರೆ 
			dwarf_ignore_type(ln, ಕೊನೆ);
		}
	    }
	    ಲಂಬಸಾಲು = dwarf_read_1(ln, ಕೊನೆ);
	    ಗಾಗಿ (i = 0; i < ಲಂಬಸಾಲು; i++) {
	        ನಮೂದು_format[i].type = dwarf_read_uleb128(&ln, ಕೊನೆ);
	        ನಮೂದು_format[i].form = dwarf_read_uleb128(&ln, ಕೊನೆ);
	    }
	    filename_ಗಾತ್ರ = dwarf_read_uleb128(&ln, ಕೊನೆ);
	    ಗಾಗಿ (i = 0; i < filename_ಗಾತ್ರ; i++)
		ಗಾಗಿ (j = 0; j < ಲಂಬಸಾಲು; j++) {
		    ಆದರೆ (ನಮೂದು_format[j].type == DW_LNCT_ಮಾರ್ಗ) {
			ಆದರೆ (ನಮೂದು_format[j].form != DW_FORM_ಸಾಲು_strp)
			    ಹೋಗು ಮುಂದಿನ_ಸಾಲು;
			ಮೌಲ್ಯ = ಉದ್ದಳತೆ == 4 ? dwarf_read_4(ln, ಕೊನೆ)
					    : dwarf_read_8(ln, ಕೊನೆ);
		        ಆದರೆ (i < FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ)
		            filename_ಕೋಷ್ಟಕ[i].name =
				(ಅಕ್ಷರ *)rc->dwarf_ಸಾಲು_str + ಮೌಲ್ಯ;
	            }
		    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ನಮೂದು_format[j].type == DW_LNCT_directory_ಸೂಚ್ಯಂಕ) {
			ಆಯ್ಕೆ (ನಮೂದು_format[j].form) {
			ಸ್ಥಿತಿ DW_FORM_data1: ಮೌಲ್ಯ = dwarf_read_1(ln, ಕೊನೆ); ನಿಲ್ಲಿಸು;
			ಸ್ಥಿತಿ DW_FORM_data2: ಮೌಲ್ಯ = dwarf_read_2(ln, ಕೊನೆ); ನಿಲ್ಲಿಸು;
			ಸ್ಥಿತಿ DW_FORM_data4: ಮೌಲ್ಯ = dwarf_read_4(ln, ಕೊನೆ); ನಿಲ್ಲಿಸು;
			ಸ್ಥಿತಿ DW_FORM_udata: ಮೌಲ್ಯ = dwarf_read_uleb128(&ln, ಕೊನೆ); ನಿಲ್ಲಿಸು;
			ಪೂರ್ವನಿಯೋಜಿತ: ಹೋಗು ಮುಂದಿನ_ಸಾಲು;
			}
		        ಆದರೆ (i < FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ)
		            filename_ಕೋಷ್ಟಕ[i].dir_ನಮೂದು = ಮೌಲ್ಯ;
		    }
		    ಇಲ್ಲದಿದ್ದರೆ 
			dwarf_ignore_type(ln, ಕೊನೆ);
	    }
	}
	ಇಲ್ಲದಿದ್ದರೆ {
	    ಆಗ ((dwarf_read_1(ln, ಕೊನೆ))) {
#ಆದರೆ 0
		ಆದರೆ (++dir_ಗಾತ್ರ < DIR_ಕೋಷ್ಟಕ_ಗಾತ್ರ)
		    dirs[dir_ಗಾತ್ರ - 1] = (ಅಕ್ಷರ *)ln - 1;
#ಆದರೆ_ಅಂತ್ಯ
		ಆಗ (dwarf_read_1(ln, ಕೊನೆ)) {}
	    }
	    ಆಗ ((dwarf_read_1(ln, ಕೊನೆ))) {
		ಆದರೆ (++filename_ಗಾತ್ರ < FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ) {
		    filename_ಕೋಷ್ಟಕ[filename_ಗಾತ್ರ - 1].name = (ಅಕ್ಷರ *)ln - 1;
		    ಆಗ (dwarf_read_1(ln, ಕೊನೆ)) {}
		    filename_ಕೋಷ್ಟಕ[filename_ಗಾತ್ರ - 1].dir_ನಮೂದು =
		        dwarf_read_uleb128(&ln, ಕೊನೆ);
		}
		ಇಲ್ಲದಿದ್ದರೆ {
		    ಆಗ (dwarf_read_1(ln, ಕೊನೆ)) {}
		    dwarf_read_uleb128(&ln, ಕೊನೆ);
		}
		dwarf_read_uleb128(&ln, ಕೊನೆ); //ಸಮಯ
		dwarf_read_uleb128(&ln, ಕೊನೆ); //ಗಾತ್ರ
	    }
	}
	ಆದರೆ (filename_ಗಾತ್ರ >= 1)
	    filename = filename_ಕೋಷ್ಟಕ[0].name;
	ಆಗ (ln < ಕೊನೆ) {
	    ಕೊನೆಯ_pc = pc;
	    i = dwarf_read_1(ln, ಕೊನೆ);
	    ಆದರೆ (i >= opcode_ತಳ) {
	        ಆದರೆ (max_ops_ಪ್ರತಿ_insn == 1)
		    pc += ((i - opcode_ತಳ) / ಸಾಲು_range) * min_insn_ಉದ್ದಳತೆ;
		ಇಲ್ಲದಿದ್ದರೆ {
		    pc += (opindex + (i - opcode_ತಳ) / ಸಾಲು_range) /
			  max_ops_ಪ್ರತಿ_insn * min_insn_ಉದ್ದಳತೆ;
		    opindex = (opindex + (i - opcode_ತಳ) / ಸಾಲು_range) %
			       max_ops_ಪ್ರತಿ_insn;
		}
		i = (ಪೂರ್ಣಾಂಕ)((i - opcode_ತಳ) % ಸಾಲು_range) + ಸಾಲು_ತಳ;
check_pc:
		ಆದರೆ (pc >= wanted_pc && wanted_pc >= ಕೊನೆಯ_pc)
		    ಹೋಗು ಸಿಕ್ಕಿತು;
		ಸಾಲು += i;
	    }
	    ಇಲ್ಲದಿದ್ದರೆ {
	        ಆಯ್ಕೆ (i) {
	        ಸ್ಥಿತಿ 0:
		    len = dwarf_read_uleb128(&ln, ಕೊನೆ);
		    cp = ln;
		    ln += len;
		    ಆದರೆ (len == 0)
		        ಹೋಗು ಮುಂದಿನ_ಸಾಲು;
		    ಆಯ್ಕೆ (dwarf_read_1(cp, ಕೊನೆ)) {
		    ಸ್ಥಿತಿ DW_LNE_ಕೊನೆ_sequence:
		        ನಿಲ್ಲಿಸು;
		    ಸ್ಥಿತಿ DW_LNE_ಗಣ_ವಿಳಾಸ:
#ಆದರೆ PTR_ಗಾತ್ರ == 4
		        pc = dwarf_read_4(cp, ಕೊನೆ);
#ಇಲ್ಲದಿದ್ದರೆ
		        pc = dwarf_read_8(cp, ಕೊನೆ);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined TCC_ಗುರಿ_MACHO
			pc += rc->prog_ತಳ;
#ಆದರೆ_ಅಂತ್ಯ
		        opindex = 0;
		        ನಿಲ್ಲಿಸು;
		    ಸ್ಥಿತಿ DW_LNE_define_file: /* deprecated */
		        ಆದರೆ (++filename_ಗಾತ್ರ < FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ) {
		            filename_ಕೋಷ್ಟಕ[filename_ಗಾತ್ರ - 1].name = (ಅಕ್ಷರ *)ln - 1;
		            ಆಗ (dwarf_read_1(ln, ಕೊನೆ)) {}
		            filename_ಕೋಷ್ಟಕ[filename_ಗಾತ್ರ - 1].dir_ನಮೂದು =
		                dwarf_read_uleb128(&ln, ಕೊನೆ);
		        }
		        ಇಲ್ಲದಿದ್ದರೆ {
		            ಆಗ (dwarf_read_1(ln, ಕೊನೆ)) {}
		            dwarf_read_uleb128(&ln, ಕೊನೆ);
		        }
		        dwarf_read_uleb128(&ln, ಕೊನೆ); //ಸಮಯ
		        dwarf_read_uleb128(&ln, ಕೊನೆ); //ಗಾತ್ರ
		        ನಿಲ್ಲಿಸು;
		    ಸ್ಥಿತಿ DW_LNE_hi_user - 1:
		        function = (ಅಕ್ಷರ *)cp;
		        func_addr = pc;
		        ನಿಲ್ಲಿಸು;
		    ಪೂರ್ವನಿಯೋಜಿತ:
		        ನಿಲ್ಲಿಸು;
		    }
		    ನಿಲ್ಲಿಸು;
	        ಸ್ಥಿತಿ DW_LNS_advance_pc:
		    ಆದರೆ (max_ops_ಪ್ರತಿ_insn == 1)
		        pc += dwarf_read_uleb128(&ln, ಕೊನೆ) * min_insn_ಉದ್ದಳತೆ;
		    ಇಲ್ಲದಿದ್ದರೆ {
		        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ off = dwarf_read_uleb128(&ln, ಕೊನೆ);

		        pc += (opindex + off) / max_ops_ಪ್ರತಿ_insn *
			      min_insn_ಉದ್ದಳತೆ;
		        opindex = (opindex + off) % max_ops_ಪ್ರತಿ_insn;
		    }
		    i = 0;
		    ಹೋಗು check_pc;
	        ಸ್ಥಿತಿ DW_LNS_advance_ಸಾಲು:
		    ಸಾಲು += dwarf_read_sleb128(&ln, ಕೊನೆ);
		    ನಿಲ್ಲಿಸು;
	        ಸ್ಥಿತಿ DW_LNS_ಗಣ_file:
		    i = dwarf_read_uleb128(&ln, ಕೊನೆ);
		    i -= i > 0 && ಆವೃತ್ತಿ < 5;
		    ಆದರೆ (i < FILE_ಕೋಷ್ಟಕ_ಗಾತ್ರ && i < filename_ಗಾತ್ರ)
		        filename = filename_ಕೋಷ್ಟಕ[i].name;
		    ನಿಲ್ಲಿಸು;
	        ಸ್ಥಿತಿ DW_LNS_const_ಕೂಡಿಸು_pc:
		    ಆದರೆ (max_ops_ಪ್ರತಿ_insn ==  1)
		        pc += ((255 - opcode_ತಳ) / ಸಾಲು_range) * min_insn_ಉದ್ದಳತೆ;
		    ಇಲ್ಲದಿದ್ದರೆ {
		        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ off = (255 - opcode_ತಳ) / ಸಾಲು_range;

		        pc += ((opindex + off) / max_ops_ಪ್ರತಿ_insn) *
			      min_insn_ಉದ್ದಳತೆ;
		        opindex = (opindex + off) % max_ops_ಪ್ರತಿ_insn;
		    }
		    i = 0;
		    ಹೋಗು check_pc;
	        ಸ್ಥಿತಿ DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, ಕೊನೆ);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    ಹೋಗು check_pc;
	        ಪೂರ್ವನಿಯೋಜಿತ:
		    ಗಾಗಿ (j = 0; j < opcode_ಉದ್ದಳತೆ[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, ಕೊನೆ);
		    ನಿಲ್ಲಿಸು;
		}
	    }
	}
ಮುಂದಿನ_ಸಾಲು:
	ln = ಕೊನೆ;
    }
    filename = function = ಖಾಲಿ, func_addr = 0;
ಸಿಕ್ಕಿತು:
    ಆದರೆ (filename)
        pstrcpy(bi->file, ಗಾತ್ರ bi->file, filename), bi->ಸಾಲು = ಸಾಲು;
    ಆದರೆ (function)
        pstrcpy(bi->func, ಗಾತ್ರ bi->func, function);
    bi->func_pc = func_addr;
    ಹಿಂತಿರುಗಿ (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_BACKTRACE_ONLY
ಸ್ಥಿರ
#ಆದರೆ_ಅಂತ್ಯ
ಪೂರ್ಣಾಂಕ _tcc_backtrace(rt_ಚೌಕಟ್ಟು *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    ಅಕ್ಷರ skip[40], ಸಂದೇಶ[200];
    ಪೂರ್ಣಾಂಕ i, level, ret, n, one;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    ಆದರೆ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        ಸ್ಮರಣೆ_ನಕಲು(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    ಆದರೆ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(ಸಂದೇಶ, ಗಾತ್ರ ಸಂದೇಶ, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    ಆದರೆ (rc) {
        ಆದರೆ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        ಆದರೆ (rc->ಅಂಕೆ_callers)
            n = rc->ಅಂಕೆ_callers;
    }

    ಗಾಗಿ (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        ಆದರೆ (ret == -1)
            ನಿಲ್ಲಿಸು;
        memset(&bi, 0, ಗಾತ್ರ bi);
        ಗಾಗಿ (rc2 = rc; rc2; rc2 = rc2->ಮುಂದಿನ) {
            ಆದರೆ (getinfo(rc2, pc, &bi))
                ನಿಲ್ಲಿಸು;
            /* we try symtab symbols (no line number info) */
            ಆದರೆ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, ಗಾತ್ರ bi.func, a);
                ನಿಲ್ಲಿಸು;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        ಆದರೆ (skip[0] && ಅಕ್ಷರಸರಣಿ_ಹುಡುಕು(bi.file, skip))
            ಮುಂದುವರಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_ಕಂಡುಹಿಡಿ_state(f);
            ಆದರೆ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_ದತ್ತಾಂಶ,
                    (ಶೂನ್ಯ*)pc,
                    bi.file[0] ? bi.file : ಖಾಲಿ,
                    bi.ಸಾಲು,
                    bi.func[0] ? bi.func : ಖಾಲಿ,
                    level == 0 ? ಸಂದೇಶ : ಖಾಲಿ
                    );
                ಆದರೆ (ret == 0)
                    ನಿಲ್ಲಿಸು;
                ಹೋಗು check_break;
            }
        }
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.ಸಾಲು);
        } ಇಲ್ಲದಿದ್ದರೆ {
            rt_printf("0x%08llx", (ದೀರ್ಘ ದೀರ್ಘ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        ಆದರೆ (level == 0) {
            rt_printf(": %s", ಸಂದೇಶ);
            ಆದರೆ (one)
                ನಿಲ್ಲಿಸು;
        }
        rt_printf("\n");

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#ಆದರೆ_ಅಂತ್ಯ
        ಆದರೆ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->ತುದಿ_func)
            ನಿಲ್ಲಿಸು;
        ++level;
    }
    rt_post_sem();
    ಹಿಂತಿರುಗಿ 0;
}

/* emit a run time error at position 'pc' */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_error(rt_ಚೌಕಟ್ಟು *f, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap; ಅಕ್ಷರ ಸಂದೇಶ[200]; ಪೂರ್ಣಾಂಕ ret;
    va_start(ap, fmt);
    snprintf(ಸಂದೇಶ, ಗಾತ್ರ ಸಂದೇಶ, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, ಸಂದೇಶ, ap);
    va_end(ap);
    ಹಿಂತಿರುಗಿ ret;
}

/* ------------------------------------------------------------- */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#ಇಲ್ಲದಿದ್ದರೆ
# define ucontext_t CONTEXT
#ಆದರೆ_ಅಂತ್ಯ

/* translate from ucontext_t* to internal rt_context * */
ಸ್ಥಿರ ಶೂನ್ಯ rt_getcontext(ucontext_t *uc, rt_ಚೌಕಟ್ಟು *rc)
{
#ಆದರೆ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#ಅಥವಾಆದರೆ defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#ಅಥವಾಆದರೆ defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#ಅಥವಾಆದರೆ defined __i386__
# ಆದರೆ defined(__APPLE__)
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
# ಇಲ್ಲದಿದ್ದರೆ
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#ಅಥವಾಆದರೆ defined(__x86_64__)
# ಆದರೆ defined(__APPLE__)
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
# ಇಲ್ಲದಿದ್ದರೆ
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#ಅಥವಾಆದರೆ defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ಅಥವಾಆದರೆ defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#ಅಥವಾಆದರೆ defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ಅಥವಾಆದರೆ defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#ಅಥವಾಆದರೆ defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#ಅಥವಾಆದರೆ defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#ಅಥವಾಆದರೆ defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#ಅಥವಾಆದರೆ defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#ಅಥವಾಆದರೆ defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#ಅಥವಾಆದರೆ defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#ಅಥವಾಆದರೆ defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#ಆದರೆ_ಅಂತ್ಯ
}

/* ------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
/* signal handler for fatal errors */
ಸ್ಥಿರ ಶೂನ್ಯ sig_error(ಪೂರ್ಣಾಂಕ signum, siginfo_t *siginf, ಶೂನ್ಯ *puc)
{
    rt_ಚೌಕಟ್ಟು f;
    rt_getcontext(puc, &f);

    ಆಯ್ಕೆ(signum) {
    ಸ್ಥಿತಿ SIGFPE:
        ಆಯ್ಕೆ(siginf->si_code) {
        ಸ್ಥಿತಿ FPE_INTDIV:
        ಸ್ಥಿತಿ FPE_FLTDIV:
            rt_error(&f, "division by zero");
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            rt_error(&f, "floating point exception");
            ನಿಲ್ಲಿಸು;
        }
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ SIGBUS:
    ಸ್ಥಿತಿ SIGSEGV:
        rt_error(&f, "invalid memory access");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ SIGILL:
        rt_error(&f, "illegal instruction");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ SIGABRT:
        rt_error(&f, "abort() called");
        ನಿಲ್ಲಿಸು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        rt_error(&f, "caught signal %d", signum);
        ನಿಲ್ಲಿಸು;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, ಖಾಲಿ);
    }
    rt_exit(&f, 255);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#ಆದರೆ_ಅಂತ್ಯ

/* Generate a stack backtrace when a CPU exception occurs. */
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_exception_handler(ಶೂನ್ಯ)
{
    ರಚನೆ sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#ಆದರೆ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#ಆದರೆ_ಅಂತ್ಯ
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, ಖಾಲಿ);
    sigaction(SIGILL, &sigact, ಖಾಲಿ);
    sigaction(SIGSEGV, &sigact, ಖಾಲಿ);
    sigaction(SIGBUS, &sigact, ಖಾಲಿ);
    sigaction(SIGABRT, &sigact, ಖಾಲಿ);
#ಆದರೆ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ರಾಶಿ[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ರಾಶಿ;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, ಖಾಲಿ);
    }
#ಆದರೆ_ಅಂತ್ಯ
}

#ಇಲ್ಲದಿದ್ದರೆ /* WIN32 */

/* signal handler for fatal errors */
ಸ್ಥಿರ ದೀರ್ಘ __stdcall cpu_exception_handler(EXCEPTION_ಸೂಚಕಗಳು *ex_info)
{
    rt_ಚೌಕಟ್ಟು f;
    ಚಿಹ್ನೆರಹಿತ ಸಂಕೇತ_2;
    rt_getcontext(ex_info->Context_ದಾಖಲೆ, &f);

    ಆಯ್ಕೆ (ಸಂಕೇತ_2 = ex_info->Exception_ದಾಖಲೆ->Exception_ಸಂಕೇತ) {
    ಸ್ಥಿತಿ EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ EXCEPTION_ರಾಶಿ_ಅತಿಪ್ರವಾಹ:
        rt_error(&f, "stack overflow");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        ನಿಲ್ಲಿಸು;
    ಸ್ಥಿತಿ EXCEPTION_BREAKPOINT:
    ಸ್ಥಿತಿ EXCEPTION_SINGLE_ಹೆಜ್ಜೆ:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ಹಿಂತಿರುಗಿ EXCEPTION_CONTINUE_ಹುಡುಕು;
    ಪೂರ್ವನಿಯೋಜಿತ:
        rt_error(&f, "caught exception %08x", ಸಂಕೇತ_2);
        ನಿಲ್ಲಿಸು;
    }
    rt_exit(&f, 255);
    ಹಿಂತಿರುಗಿ EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
ಸ್ಥಿರ ಶೂನ್ಯ ಗಣ_exception_handler(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಕೂಡಿಸು_Vectored_Exception_Handler(1, cpu_exception_handler);
#ಇಲ್ಲದಿದ್ದರೆ
    ಗಣ_Unhandled_Exception_Filter(cpu_exception_handler);
#ಆದರೆ_ಅಂತ್ಯ
}

#ಆದರೆ_ಅಂತ್ಯ

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#ಆದರೆ defined(__i386__) || defined(__x86_64__)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *rc, ಪೂರ್ಣಾಂಕ level)
{
    ಆದರೆ (level == 0) {
        *paddr = rc->ip;
    } ಇಲ್ಲದಿದ್ದರೆ {
        addr_t fp = rc->fp;
        ಆಗ (1) {
            ಆದರೆ (fp < 0x1000)
                ಹಿಂತಿರುಗಿ -1;
            ಆದರೆ (0 == --level)
                ನಿಲ್ಲಿಸು;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* XXX: only supports linux/bsd */
#ಅಥವಾಆದರೆ defined(__arm__) && !defined(_WIN32)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *rc, ಪೂರ್ಣಾಂಕ level)
{
    ಆದರೆ (level == 0) {
        *paddr = rc->ip;
    } ಇಲ್ಲದಿದ್ದರೆ {
        addr_t fp = rc->fp;
        ಆಗ (1) {
            ಆದರೆ (fp < 0x1000)
                ಹಿಂತಿರುಗಿ -1;
            ಆದರೆ (0 == --level)
                ನಿಲ್ಲಿಸು;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined(__aarch64__)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *rc, ಪೂರ್ಣಾಂಕ level)
{
    ಆದರೆ (level == 0) {
        *paddr = rc->ip;
    } ಇಲ್ಲದಿದ್ದರೆ {
        addr_t fp = rc->fp;
        ಆಗ (1) {
            ಆದರೆ (fp < 0x1000)
                ಹಿಂತಿರುಗಿ -1;
            ಆದರೆ (0 == --level)
                ನಿಲ್ಲಿಸು;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ಹಿಂತಿರುಗಿ 0;
}

#ಅಥವಾಆದರೆ defined(__riscv)
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *rc, ಪೂರ್ಣಾಂಕ level)
{
    ಆದರೆ (level == 0) {
        *paddr = rc->ip;
    } ಇಲ್ಲದಿದ್ದರೆ {
        addr_t fp = rc->fp;
        ಆಗ (1) {
            ಆದರೆ (fp < 0x1000)
                ಹಿಂತಿರುಗಿ -1;
            ಆದರೆ (0 == --level)
                ನಿಲ್ಲಿಸು;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ಹಿಂತಿರುಗಿ 0;
}

#ಇಲ್ಲದಿದ್ದರೆ
#warning ಕೂಡಿಸು arch specific rt_get_caller_pc()
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *rc, ಪೂರ್ಣಾಂಕ level)
{
    ಹಿಂತಿರುಗಿ -1;
}

#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ rt_get_caller_pc(addr_t *paddr, rt_ಚೌಕಟ್ಟು *f, ಪೂರ್ಣಾಂಕ level)
{
    ಆದರೆ (level)
        ಹಿಂತಿರುಗಿ -1;
    *paddr = f->ip;
    ಹಿಂತಿರುಗಿ 0;
}
#ಆದರೆ_ಅಂತ್ಯ /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC ಶೂನ್ಯ *dlopen(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *filename, ಪೂರ್ಣಾಂಕ flag)
{
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

ST_FUNC ಶೂನ್ಯ dlclose(ಶೂನ್ಯ *p)
{
}

ST_FUNC ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *dlerror(ಶೂನ್ಯ)
{
    ಹಿಂತಿರುಗಿ "error";
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TCCSyms {
    ಅಕ್ಷರ *str;
    ಶೂನ್ಯ *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
ಸ್ಥಿರ TCCSyms tcc_syms[] = {
#ಆದರೆ !defined(CONFIG_TCCBOOT)
#ವ್ಯಾಖ್ಯಾನಿಸು TCCSYM(a) { #a, &a, },
    TCCSYM(ಬರೆ)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು TCCSYM
#ಆದರೆ_ಅಂತ್ಯ
    { ಖಾಲಿ, ಖಾಲಿ },
};

ST_FUNC ಶೂನ್ಯ *dlsym(ಶೂನ್ಯ *handle, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಚಿಹ್ನೆ)
{
    TCCSyms *p;
    p = tcc_syms;
    ಆಗ (p->str != ಖಾಲಿ) {
        ಆದರೆ (!strcmp(p->str, ಚಿಹ್ನೆ))
            ಹಿಂತಿರುಗಿ p->ptr;
        p++;
    }
    ಹಿಂತಿರುಗಿ ಖಾಲಿ;
}

#ಆದರೆ_ಅಂತ್ಯ /* CONFIG_TCC_STATIC */
#ಆದರೆ_ಅಂತ್ಯ /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
