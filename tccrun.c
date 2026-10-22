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
प्रकारव्याख्या संरचना rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    संघ {
	संरचना {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    अक्षर *stab_str;
	};
	संरचना {
	    अचिन्हित अक्षर *dwarf_ओळ;
	    अचिन्हित अक्षर *dwarf_ओळ_end;
	    अचिन्हित अक्षर *dwarf_ओळ_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    अक्षर *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    शून्य *bounds_start;
    शून्य *शीर्ष_func;
    संरचना rt_context *next;
    // 10 * PTR_SIZE
    पूर्णांक अंक_callers;
    पूर्णांक dwarf;
} rt_context;

/* linked list of rt_contexts */
स्थिर rt_context *g_rc;
स्थिर पूर्णांक signal_set;
स्थिर शून्य set_exception_handler(शून्य);
#endif /* def CONFIG_TCC_BACKTRACE */

प्रकारव्याख्या संरचना rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

स्थिर TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(स्थिर rt_sem);
स्थिर शून्य rt_wait_sem(शून्य) { WAIT_SEM(&rt_sem); }
स्थिर शून्य rt_post_sem(शून्य) { POST_SEM(&rt_sem); }
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णांक level);
स्थिर शून्य rt_exit(rt_frame *f, पूर्णांक code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

स्थिर पूर्णांक protect_pages(शून्य *ptr, अचिन्हित दीर्घ length, पूर्णांक mode);
स्थिर पूर्णांक tcc_relocate_ex(TCCState *s1, शून्य *ptr, अचिन्हित ptr_diff);
स्थिर शून्य st_link(TCCState *s1);
स्थिर शून्य st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
स्थिर पूर्णांक _tcc_backtrace(rt_frame *f, स्थिरांक अक्षर *fmt, बहु_सूची ap);
#endif
#ifdef _WIN64
स्थिर शून्य *win64_add_function_table(TCCState *s1);
स्थिर शून्य win64_del_function_table(शून्य *);
#endif

#जर !defined PAGESIZE
# जर defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# अन्यथा
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#जर !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#जर defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

स्थिर पूर्णांक rt_mem(TCCState *s1, पूर्णांक size)
{
    शून्य *ptr;
    पूर्णांक ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    शून्य *prw;
    अक्षर tmpfname[] = "/tmp/.tccrunXXXXXX";
    पूर्णांक fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(रिक्त, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((अक्षर*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    बंद(fd);
    जर (ptr == MAP_FAILED || prw == MAP_FAILED)
	परत tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (अक्षर*)prw - (अक्षर*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#किंवाजर CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(रिक्त, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    जर (!ptr)
        परत tcc_error_noabort("tccrun: could not allocate memory");
#अन्यथा
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    परत ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI पूर्णांक tcc_relocate(TCCState *s1)
{
    पूर्णांक size, ret, ptr_diff;

    जर (s1->run_ptr)
        निकास(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    जर (s1->do_backtrace)
        tcc_add_चिन्ह(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, रिक्त, 0);
    जर (size < 0)
        परत -1;
    ptr_diff = rt_mem(s1, size);
    जर (ptr_diff < 0)
        परत -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    जर (ret == 0)
        st_link(s1);
    परत ret;
}

ST_FUNC शून्य tcc_run_free(TCCState *s1)
{
    अचिन्हित size;
    शून्य *ptr;
    पूर्णांक i;

    /* free any loaded DLLs */
    साठी ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        जर ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#अन्यथा
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    जर (रिक्त == ptr)
        परत;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#किंवाजर CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#अन्यथा
    /* unprotect memory to make it usable for malloc again */
    protect_pages((शून्य*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI पूर्णांक tcc_run(TCCState *s1, पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक (*prog_main)(पूर्णांक, अक्षर **, अक्षर **), ret;
    स्थिरांक अक्षर *शीर्ष_sym;
    लाँघ_बफ main_jb;

#जर defined(__APPLE__)
    बाह्य अक्षर ***_NSGetEnviron(शून्य);
    अक्षर **envp = *_NSGetEnviron();
#किंवाजर defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    बाह्य अक्षर **environ;
    अक्षर **envp = environ;
#अन्यथा
    अक्षर **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    जर ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        परत 0;

    tcc_add_चिन्ह(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", शीर्ष_sym = "main";
    जर (s1->elf_entryname)
        s1->run_main = शीर्ष_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    जर (tcc_relocate(s1) < 0)
        परत -1;

    prog_main = (शून्य*)get_sym_addr(s1, s1->run_main, 1, 1);
    जर ((addr_t)-1 == (addr_t)prog_main)
        परत -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    जर (s1->run_stdin && !ख_व_खोलो(s1->run_stdin, "r", मानक_निवेश)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        परत -1;
    }

    त्रुटि_सं = 0; /* clean errno value */
    ख_साफ(मानक_निकास);
    ख_साफ(मानक_त्रुटि);

    ret = tcc_setjmp(s1, main_jb, tcc_get_चिन्ह(s1, शीर्ष_sym));
    जर (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } अन्यथा जर (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    जर (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        ख_लिखो(s1->ppfp, "[returns %d]\n", ret), ख_साफ(s1->ppfp);
    परत ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
स्थिर शून्य cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णांक sym_index, end_sym = s->data_offset / आकार (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    साठी (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        स्थिरांक अक्षर *name = (अक्षर *)s->link->data + sym->st_name;
        जर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            सुरूठेवा;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_मूल्य, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
स्थिर शून्य cleanup_sections(TCCState *s1)
{
    संरचना { Section **secs; पूर्णांक nb_secs; } *p = (शून्य*)&s1->sections;
    पूर्णांक i, f = 2;
    करा {
        साठी (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            जर (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } अन्यथा {
                free_section(s), tcc_free(s), p->secs[i] = रिक्त;
            }
        }
    } पर्यंत (++p, f);
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
# अन्यथा
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
स्थिर पूर्णांक tcc_relocate_ex(TCCState *s1, शून्य *ptr, अचिन्हित ptr_diff)
{
    Section *s;
    अचिन्हित offset, length, align, i, k, f;
    अचिन्हित n, copy;
    addr_t mem, addr;

    जर (रिक्त == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, रिक्त);
#अन्यथा
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    जर (s1->verbose == 2 && copy)
        म_लिखो(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    जर (s1->nb_errors)
        परत -1;
    जर (copy == 3)
        परत 0;

    साठी (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        साठी(i = 1; i < s1->nb_sections; i++) {
            स्थिर स्थिरांक अक्षर shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            जर (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                सुरूठेवा;
            length = s->data_offset;
            जर (copy == 2) {
                जर (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                सुरूठेवा;
            }
            जर (copy) { /* final step: copy section data to memory */
                जर (s1->verbose == 2)
                    म_लिखो("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (शून्य*)s->sh_addr, length, s->sh_addralign);
                ptr = (शून्य*)s->sh_addr;
                जर (k == 0)
                    ptr = (शून्य*)(s->sh_addr + ptr_diff);
                जर (रिक्त == s->data || s->sh_type == SHT_NOBITS)
                    स_रखो(ptr, 0, length);
                अन्यथा
                    स_नकल(ptr, s->data, length);
                सुरूठेवा;
            }

            जर ((s->sh_flags & SHF_TLS) && length)
                परत tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            जर (++n == 1) {
#जर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                जर (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                जर (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        जर (copy == 2) { /* set permissions */
            जर (n == 0) /* no data  */
                सुरूठेवा;
#ifdef CONFIG_SELINUX
            जर (k == 0) /* SHF_EXECINSTR has its own mapping */
                सुरूठेवा;
#endif
            f = k;
            जर (f >= CONFIG_RUNMEM_RO) {
                जर (f != 0)
                    सुरूठेवा;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            जर (s1->verbose == 2) {
                म_लिखो("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (शून्य*)addr, (अचिन्हित)n);
            }
            जर (protect_pages((शून्य*)addr, n, f) < 0)
                परत tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#अन्यथा
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    जर (0 == mem)
        परत PAGEALIGN(offset);

    जर (++copy == 2) {
        जा redo;
    }
    जर (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        जा redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    जर (s1->nb_errors)
        जा redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#अन्यथा
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    जा redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

स्थिर पूर्णांक protect_pages(शून्य *ptr, अचिन्हित दीर्घ length, पूर्णांक mode)
{
#ifdef _WIN32
    स्थिर स्थिरांक अचिन्हित अक्षर protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    जर (!VirtualProtect(ptr, length, protect[mode], &old))
        परत -1;
#अन्यथा
    स्थिर स्थिरांक अचिन्हित अक्षर protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    जर (mprotect(ptr, length, protect[mode]))
        परत -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#जर (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    जर (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#अन्यथा
        शून्य __clear_cache(शून्य *beginning, शून्य *end);
        __clear_cache(ptr, (अक्षर *)ptr + length);
#endif
    }
#endif
    परत 0;
}

#ifdef _WIN64
स्थिर शून्य *win64_add_function_table(TCCState *s1)
{
    शून्य *p = रिक्त;
    जर (s1->uw_pdata) {
        p = (शून्य*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / आकार (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = रिक्त;
    }
    परत p;
}

स्थिर शून्य win64_del_function_table(शून्य *p)
{
    जर (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

स्थिर शून्य bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    जर (!s1->do_backtrace)
        परत;
    rc = tcc_get_चिन्ह(s1, "__rt_info");
    जर (!rc)
        परत;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (अक्षर *)symtab_section->link->data;
    जर (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    जर (s1->do_bounds_check) {
        शून्य *p;
        जर ((p = tcc_get_चिन्ह(s1, "__bound_init")))
            ((शून्य(*)(शून्य*,पूर्णांक))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    जर (0 == signal_set)
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
स्थिर शून्य ptr_unlink(शून्य *list, शून्य *e, अचिन्हित next)
{
    शून्य **pp, **nn, *p;
    साठी (pp = list; !!(p = *pp); pp = nn) {
        nn = (शून्य*)((अक्षर*)p + next); /* nn = &p->next; */
        जर (p == e) {
            *pp = *nn;
            थांबा;
        }
    }
}

स्थिर शून्य st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, दुरत्व(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, दुरत्व(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI शून्य *_tcc_setjmp(TCCState *s1, शून्य *p_jmp_buf, शून्य *func, शून्य *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    जर (s1->rc)
        s1->rc->शीर्ष_func = func;
#endif
    परत p_jmp_buf;
}

LIBTCCAPI शून्य tcc_set_backtrace_func(TCCState *s1, शून्य *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

स्थिर TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    पूर्णांक level;
    addr_t pc;

    s = g_s1;
    जर (रिक्त == s || रिक्त == s->next) {
        /* play it safe in the simple case when there is only one state */
        परत s;
    }
    साठी (level = 0; level < 8; ++level) {
        जर (rt_get_caller_pc(&pc, f, level) < 0)
            थांबा;
        साठी (s = g_s1; s; s = s->next) {
            जर (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                परत s;
        }
    }
    परत रिक्त;
}

स्थिर शून्य rt_exit(rt_frame *f, पूर्णांक code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    जर (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        जर (f->fp) { /* called from signal */
            शून्य *p = tcc_get_चिन्ह(s, "__bound_exit");
            जर (p)
                ((शून्य (*)(शून्य))p)();
        }
#endif
        जर (code == 0)
            code = RT_EXIT_ZERO;
        ((शून्य(*)(शून्य*,पूर्णांक))s->run_lj)(s->run_jb, code);
    }
    निकास(code);
}

/* ------------------------------------------------------------- */
#अन्यथा // if defined CONFIG_TCC_BACKTRACE_ONLY
स्थिर शून्य rt_exit(rt_frame *f, पूर्णांक code)
{
    निकास(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

स्थिर पूर्णांक rt_vprintf(स्थिरांक अक्षर *fmt, बहु_सूची ap)
{
    पूर्णांक ret = भख_लिखो(मानक_त्रुटि, fmt, ap);
    ख_साफ(मानक_त्रुटि);
    परत ret;
}

स्थिर पूर्णांक rt_printf(स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap;
    पूर्णांक r;
    बहु_शुरू(ap, fmt);
    r = rt_vprintf(fmt, ap);
    बहु_पूर्ण(ap);
    परत r;
}

स्थिर अक्षर *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    साठी (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        पूर्णांक type = ELFW(ST_TYPE)(esym->st_info);
        जर ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_मूल्य
            && wanted_pc < esym->st_मूल्य + esym->st_size) {
            *func_addr = esym->st_मूल्य;
            परत rc->elf_str + esym->st_name;
        }
    }
    परत रिक्त;
}

प्रकारव्याख्या संरचना bt_info
{
    अक्षर file[100];
    पूर्णांक ओळ;
    अक्षर func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
स्थिर addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    अक्षर func_name[128];
    addr_t func_addr, last_pc, pc;
    स्थिरांक अक्षर *incl_files[INCLUDE_चळत_SIZE];
    पूर्णांक incl_index, last_incl_index, len, last_ओळ_अंक, i;
    स्थिरांक अक्षर *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_ओळ_अंक = 1;
    last_incl_index = 0;

    साठी (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_मूल्य;

        निवड(sym->n_type) {
        स्थिती N_SLINE:
            जर (func_addr)
                जा rel_pc;
        स्थिती N_SO:
        स्थिती N_SOL:
            जा abs_pc;
        स्थिती N_FUN:
            जर (sym->n_strx == 0) /* end of function */
                जा rel_pc;
        abs_pc:
#जर PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            जा check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            जर (pc >= wanted_pc && wanted_pc >= last_pc)
                जा found;
            थांबा;
        }

        निवड(sym->n_type) {
            /* function start or end */
        स्थिती N_FUN:
            जर (sym->n_strx == 0)
                जा reset_func;
            p = म_अक्षर(str, ':');
            जर (0 == p || (len = p - str + 1, len > आकार func_name))
                len = आकार func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            थांबा;
            /* line number info */
        स्थिती N_SLINE:
            last_pc = pc;
            last_ओळ_अंक = sym->n_desc;
            last_incl_index = incl_index;
            थांबा;
            /* include files */
        स्थिती N_BINCL:
            जर (incl_index < INCLUDE_चळत_SIZE)
                incl_files[incl_index++] = str;
            थांबा;
        स्थिती N_EINCL:
            जर (incl_index > 1)
                incl_index--;
            थांबा;
            /* start/end of translation unit */
        स्थिती N_SO:
            incl_index = 0;
            जर (sym->n_strx) {
                /* do not add path */
                len = म_माप(str);
                जर (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            थांबा;
            /* alternative file name (from #line or #include directives) */
        स्थिती N_SOL:
            जर (incl_index)
                incl_files[incl_index-1] = str;
            थांबा;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    जर (i > 0) {
        pstrcpy(bi->file, आकार bi->file, incl_files[--i]);
        bi->ओळ = last_ओळ_अंक;
    }
    pstrcpy(bi->func, आकार bi->func, func_name);
    bi->func_pc = func_addr;
    परत func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	निवड (entry_format[j].form) { \
	स्थिती DW_FORM_data1: (ln) += 1; थांबा; \
	स्थिती DW_FORM_data2: (ln) += 2; थांबा; \
	स्थिती DW_FORM_data4: (ln) += 3; थांबा; \
	स्थिती DW_FORM_data8: (ln) += 8; थांबा; \
	स्थिती DW_FORM_data16: (ln) += 16; थांबा; \
	स्थिती DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); थांबा; \
	पूर्वनिर्धारित: जा next_ओळ; \
	}

स्थिर addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    अचिन्हित अक्षर *ln;
    अचिन्हित अक्षर *cp;
    अचिन्हित अक्षर *end;
    अचिन्हित अक्षर *opcode_length;
    अचिन्हित दीर्घ दीर्घ size;
    अचिन्हित पूर्णांक length;
    अचिन्हित अक्षर version;
    अचिन्हित पूर्णांक min_insn_length;
    अचिन्हित पूर्णांक max_ops_per_insn;
    पूर्णांक ओळ_base;
    अचिन्हित पूर्णांक ओळ_range;
    अचिन्हित पूर्णांक opcode_base;
    अचिन्हित पूर्णांक opindex;
    अचिन्हित पूर्णांक col;
    अचिन्हित पूर्णांक i;
    अचिन्हित पूर्णांक j;
    अचिन्हित पूर्णांक len;
    अचिन्हित दीर्घ दीर्घ मूल्य;
    संरचना {
	अचिन्हित पूर्णांक type;
	अचिन्हित पूर्णांक form;
    } entry_format[256];
    अचिन्हित पूर्णांक dir_size;
#जर 0
    अक्षर *dirs[DIR_TABLE_SIZE];
#endif
    अचिन्हित पूर्णांक filename_size;
    संरचना /*dwarf_filename_struct*/ {
        अचिन्हित पूर्णांक dir_entry;
        अक्षर *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    पूर्णांक ओळ;
    अक्षर *filename;
    अक्षर *function;

    filename = रिक्त;
    function = रिक्त;
    func_addr = 0;
    ओळ = 0;

    ln = rc->dwarf_ओळ;
    पर्यंत (ln < rc->dwarf_ओळ_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        ओळ = 1;
        filename = रिक्त;
        function = रिक्त;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_ओळ_end);
	जर (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_ओळ_end);
	end = ln + size;
	जर (end < ln || end > rc->dwarf_ओळ_end)
	    थांबा;
	version = dwarf_read_2(ln, end);
	जर (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	अन्यथा
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	जर (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	अन्यथा
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	ओळ_base = dwarf_read_1(ln, end);
	ओळ_base |= ओळ_base >= 0x80 ? ~0xff : 0;
	ओळ_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	जर (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    साठी (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    साठी (i = 0; i < dir_size; i++) {
		साठी (j = 0; j < col; j++) {
		    जर (entry_format[j].type == DW_LNCT_path) {
		        जर (entry_format[j].form != DW_FORM_ओळ_strp)
			    जा next_ओळ;
#जर 0
		        मूल्य = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        जर (i < DIR_TABLE_SIZE)
		            dirs[i] = (अक्षर *)rc->dwarf_ओळ_str + मूल्य;
#अन्यथा
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    साठी (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    साठी (i = 0; i < filename_size; i++)
		साठी (j = 0; j < col; j++) {
		    जर (entry_format[j].type == DW_LNCT_path) {
			जर (entry_format[j].form != DW_FORM_ओळ_strp)
			    जा next_ओळ;
			मूल्य = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        जर (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(अक्षर *)rc->dwarf_ओळ_str + मूल्य;
	            }
		    अन्यथा जर (entry_format[j].type == DW_LNCT_directory_index) {
			निवड (entry_format[j].form) {
			स्थिती DW_FORM_data1: मूल्य = dwarf_read_1(ln, end); थांबा;
			स्थिती DW_FORM_data2: मूल्य = dwarf_read_2(ln, end); थांबा;
			स्थिती DW_FORM_data4: मूल्य = dwarf_read_4(ln, end); थांबा;
			स्थिती DW_FORM_udata: मूल्य = dwarf_read_uleb128(&ln, end); थांबा;
			पूर्वनिर्धारित: जा next_ओळ;
			}
		        जर (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = मूल्य;
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, end);
	    }
	}
	अन्यथा {
	    पर्यंत ((dwarf_read_1(ln, end))) {
#जर 0
		जर (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (अक्षर *)ln - 1;
#endif
		पर्यंत (dwarf_read_1(ln, end)) {}
	    }
	    पर्यंत ((dwarf_read_1(ln, end))) {
		जर (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (अक्षर *)ln - 1;
		    पर्यंत (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		अन्यथा {
		    पर्यंत (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	जर (filename_size >= 1)
	    filename = filename_table[0].name;
	पर्यंत (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    जर (i >= opcode_base) {
	        जर (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / ओळ_range) * min_insn_length;
		अन्यथा {
		    pc += (opindex + (i - opcode_base) / ओळ_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / ओळ_range) %
			       max_ops_per_insn;
		}
		i = (पूर्णांक)((i - opcode_base) % ओळ_range) + ओळ_base;
check_pc:
		जर (pc >= wanted_pc && wanted_pc >= last_pc)
		    जा found;
		ओळ += i;
	    }
	    अन्यथा {
	        निवड (i) {
	        स्थिती 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    जर (len == 0)
		        जा next_ओळ;
		    निवड (dwarf_read_1(cp, end)) {
		    स्थिती DW_LNE_end_sequence:
		        थांबा;
		    स्थिती DW_LNE_set_address:
#जर PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#अन्यथा
		        pc = dwarf_read_8(cp, end);
#endif
#जर defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        थांबा;
		    स्थिती DW_LNE_define_file: /* deprecated */
		        जर (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (अक्षर *)ln - 1;
		            पर्यंत (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        अन्यथा {
		            पर्यंत (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        थांबा;
		    स्थिती DW_LNE_hi_user - 1:
		        function = (अक्षर *)cp;
		        func_addr = pc;
		        थांबा;
		    पूर्वनिर्धारित:
		        थांबा;
		    }
		    थांबा;
	        स्थिती DW_LNS_advance_pc:
		    जर (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    अन्यथा {
		        अचिन्हित दीर्घ दीर्घ off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    जा check_pc;
	        स्थिती DW_LNS_advance_ओळ:
		    ओळ += dwarf_read_sleb128(&ln, end);
		    थांबा;
	        स्थिती DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    जर (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    थांबा;
	        स्थिती DW_LNS_const_add_pc:
		    जर (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / ओळ_range) * min_insn_length;
		    अन्यथा {
		        अचिन्हित पूर्णांक off = (255 - opcode_base) / ओळ_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    जा check_pc;
	        स्थिती DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    जा check_pc;
	        पूर्वनिर्धारित:
		    साठी (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    थांबा;
		}
	    }
	}
next_ओळ:
	ln = end;
    }
    filename = function = रिक्त, func_addr = 0;
found:
    जर (filename)
        pstrcpy(bi->file, आकार bi->file, filename), bi->ओळ = ओळ;
    जर (function)
        pstrcpy(bi->func, आकार bi->func, function);
    bi->func_pc = func_addr;
    परत (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
स्थिर
#endif
पूर्णांक _tcc_backtrace(rt_frame *f, स्थिरांक अक्षर *fmt, बहु_सूची ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    अक्षर skip[40], संदेश[200];
    पूर्णांक i, level, ret, n, one;
    स्थिरांक अक्षर *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    जर (fmt[0] == '^' && (b = म_अक्षर(a = fmt + 1, fmt[0]))) {
        स_नकल(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    जर (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(संदेश, आकार संदेश, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    जर (rc) {
        जर (rc->dwarf)
            getinfo = rt_printline_dwarf;
        जर (rc->अंक_callers)
            n = rc->अंक_callers;
    }

    साठी (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        जर (ret == -1)
            थांबा;
        स_रखो(&bi, 0, आकार bi);
        साठी (rc2 = rc; rc2; rc2 = rc2->next) {
            जर (getinfo(rc2, pc, &bi))
                थांबा;
            /* we try symtab symbols (no line number info) */
            जर (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, आकार bi.func, a);
                थांबा;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        जर (skip[0] && म_माला(bi.file, skip))
            सुरूठेवा;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            जर (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (शून्य*)pc,
                    bi.file[0] ? bi.file : रिक्त,
                    bi.ओळ,
                    bi.func[0] ? bi.func : रिक्त,
                    level == 0 ? संदेश : रिक्त
                    );
                जर (ret == 0)
                    थांबा;
                जा check_break;
            }
        }
#endif
        जर (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.ओळ);
        } अन्यथा {
            rt_printf("0x%08llx", (दीर्घ दीर्घ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        जर (level == 0) {
            rt_printf(": %s", संदेश);
            जर (one)
                थांबा;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        जर (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->शीर्ष_func)
            थांबा;
        ++level;
    }
    rt_post_sem();
    परत 0;
}

/* emit a run time error at position 'pc' */
स्थिर पूर्णांक rt_error(rt_frame *f, स्थिरांक अक्षर *fmt, ...)
{
    बहु_सूची ap; अक्षर संदेश[200]; पूर्णांक ret;
    बहु_शुरू(ap, fmt);
    snprintf(संदेश, आकार संदेश, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, संदेश, ap);
    बहु_पूर्ण(ap);
    परत ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#अन्यथा
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
स्थिर शून्य rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#जर defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#किंवाजर defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#किंवाजर defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#किंवाजर defined __i386__
# जर defined(__APPLE__)
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
# अन्यथा
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#किंवाजर defined(__x86_64__)
# जर defined(__APPLE__)
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
# अन्यथा
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#किंवाजर defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#किंवाजर defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#किंवाजर defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#किंवाजर defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#किंवाजर defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#किंवाजर defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#किंवाजर defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#किंवाजर defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#किंवाजर defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#किंवाजर defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#किंवाजर defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
स्थिर शून्य sig_error(पूर्णांक signum, siginfo_t *siginf, शून्य *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    निवड(signum) {
    स्थिती संक_भ_त्रुटि:
        निवड(siginf->si_code) {
        स्थिती FPE_INTDIV:
        स्थिती FPE_FLTDIV:
            rt_error(&f, "division by zero");
            थांबा;
        पूर्वनिर्धारित:
            rt_error(&f, "floating point exception");
            थांबा;
        }
        थांबा;
    स्थिती SIGBUS:
    स्थिती संक_अंश:
        rt_error(&f, "invalid memory access");
        थांबा;
    स्थिती संक_अवैध:
        rt_error(&f, "illegal instruction");
        थांबा;
    स्थिती SIGABRT:
        rt_error(&f, "abort() called");
        थांबा;
    पूर्वनिर्धारित:
        rt_error(&f, "caught signal %d", signum);
        थांबा;
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
#जर 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(संक_भ_त्रुटि, &sigact, रिक्त);
    sigaction(संक_अवैध, &sigact, रिक्त);
    sigaction(संक_अंश, &sigact, रिक्त);
    sigaction(SIGBUS, &sigact, रिक्त);
    sigaction(SIGABRT, &sigact, रिक्त);
#जर 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        स्थिर अचिन्हित अक्षर चळत[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = चळत;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, रिक्त);
    }
#endif
}

#अन्यथा /* WIN32 */

/* signal handler for fatal errors */
स्थिर दीर्घ __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    अचिन्हित code;
    rt_getcontext(ex_info->ContextRecord, &f);

    निवड (code = ex_info->ExceptionRecord->ExceptionCode) {
    स्थिती EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        थांबा;
    स्थिती EXCEPTION_चळत_OVERFLOW:
        rt_error(&f, "stack overflow");
        थांबा;
    स्थिती EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        थांबा;
    स्थिती EXCEPTION_BREAKPOINT:
    स्थिती EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        परत EXCEPTION_CONTINUE_शोध;
    पूर्वनिर्धारित:
        rt_error(&f, "caught exception %08x", code);
        थांबा;
    }
    rt_exit(&f, 255);
    परत EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
स्थिर शून्य set_exception_handler(शून्य)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#अन्यथा
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#जर defined(__i386__) || defined(__x86_64__)
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    जर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        पर्यंत (1) {
            जर (fp < 0x1000)
                परत -1;
            जर (0 == --level)
                थांबा;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    परत 0;
}

/* XXX: only supports linux/bsd */
#किंवाजर defined(__arm__) && !defined(_WIN32)
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    जर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        पर्यंत (1) {
            जर (fp < 0x1000)
                परत -1;
            जर (0 == --level)
                थांबा;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    परत 0;
}

#किंवाजर defined(__aarch64__)
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    जर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        पर्यंत (1) {
            जर (fp < 0x1000)
                परत -1;
            जर (0 == --level)
                थांबा;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    परत 0;
}

#किंवाजर defined(__riscv)
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    जर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        पर्यंत (1) {
            जर (fp < 0x1000)
                परत -1;
            जर (0 == --level)
                थांबा;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    परत 0;
}

#अन्यथा
#warning add arch specific rt_get_caller_pc()
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    परत -1;
}

#endif
#अन्यथा // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
स्थिर पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णांक level)
{
    जर (level)
        परत -1;
    *paddr = f->ip;
    परत 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC शून्य *dlopen(स्थिरांक अक्षर *filename, पूर्णांक flag)
{
    परत रिक्त;
}

ST_FUNC शून्य dlclose(शून्य *p)
{
}

ST_FUNC स्थिरांक अक्षर *dlerror(शून्य)
{
    परत "error";
}

प्रकारव्याख्या संरचना TCCSyms {
    अक्षर *str;
    शून्य *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
स्थिर TCCSyms tcc_syms[] = {
#जर !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(म_लिखो)
    TCCSYM(ख_लिखो)
    TCCSYM(ख_खोलो)
    TCCSYM(ख_बंद)
#undef TCCSYM
#endif
    { रिक्त, रिक्त },
};

ST_FUNC शून्य *dlsym(शून्य *handle, स्थिरांक अक्षर *चिन्ह)
{
    TCCSyms *p;
    p = tcc_syms;
    पर्यंत (p->str != रिक्त) {
        जर (!म_भेद(p->str, चिन्ह))
            परत p->ptr;
        p++;
    }
    परत रिक्त;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
