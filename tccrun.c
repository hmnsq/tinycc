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

#समावेश "tcc.h"

/* only native compiler supports -run */
#अगर_घोषित TCC_IS_NATIVE

#अगर_घोषित CONFIG_TCC_BACKTRACE
/* runtime debug info block */
प्रकार काष्ठा rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    जोड़ {
	काष्ठा {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    अक्षर *stab_str;
	};
	काष्ठा {
	    अचिन्हित अक्षर *dwarf_पंक्ति;
	    अचिन्हित अक्षर *dwarf_पंक्ति_end;
	    अचिन्हित अक्षर *dwarf_पंक्ति_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    अक्षर *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    व्योम *bounds_start;
    व्योम *शीर्ष_func;
    काष्ठा rt_context *अग्र;
    // 10 * PTR_SIZE
    पूर्णांक अंक_callers;
    पूर्णांक dwarf;
} rt_context;

/* linked list of rt_contexts */
अटल rt_context *g_rc;
अटल पूर्णांक signal_set;
अटल व्योम set_exception_handler(व्योम);
#पूर्ण_अगर /* def CONFIG_TCC_BACKTRACE */

प्रकार काष्ठा rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

अटल TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(अटल rt_sem);
अटल व्योम rt_wait_sem(व्योम) { WAIT_SEM(&rt_sem); }
अटल व्योम rt_post_sem(व्योम) { POST_SEM(&rt_sem); }
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णांक level);
अटल व्योम rt_exit(rt_frame *f, पूर्णांक code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#अगर_अघोषित CONFIG_TCC_BACKTRACE_ONLY

#अगर_अघोषित _WIN32
# include <sys/mman.h>
#पूर्ण_अगर

अटल पूर्णांक protect_pages(व्योम *ptr, अचिन्हित दीर्घ लंबाई, पूर्णांक mode);
अटल पूर्णांक tcc_relocate_ex(TCCState *s1, व्योम *ptr, अचिन्हित ptr_diff);
अटल व्योम st_link(TCCState *s1);
अटल व्योम st_unlink(TCCState *s1);
#अगर_घोषित CONFIG_TCC_BACKTRACE
अटल पूर्णांक _tcc_backtrace(rt_frame *f, स्थिर अक्षर *fmt, बहु_सूची ap);
#पूर्ण_अगर
#अगर_घोषित _WIN64
अटल व्योम *win64_add_function_table(TCCState *s1);
अटल व्योम win64_del_function_table(व्योम *);
#पूर्ण_अगर

#अगर !defined PAGESIZE
# अगर defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# अन्यथा
#  define PAGESIZE 4096
# endif
#पूर्ण_अगर

#घोषणा PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#अगर !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#पूर्ण_अगर

/* use VirtualAlloc() instead of tcc_malloc() */
#अगर defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#पूर्ण_अगर

अटल पूर्णांक rt_mem(TCCState *s1, पूर्णांक आकार)
{
    व्योम *ptr;
    पूर्णांक ptr_diff = 0;
#अगर_घोषित CONFIG_SELINUX
    /* Using mmap instead of malloc */
    व्योम *prw;
    अक्षर tmpfname[] = "/tmp/.tccrunXXXXXX";
    पूर्णांक fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, आकार);

    ptr = mmap(शून्य, आकार * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((अक्षर*)ptr + आकार, आकार, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    बंद(fd);
    अगर (ptr == MAP_FAILED || prw == MAP_FAILED)
	वापस tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (अक्षर*)prw - (अक्षर*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    आकार *= 2;
#या_अगर CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(शून्य, आकार, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    अगर (!ptr)
        वापस tcc_error_noabort("tccrun: could not allocate memory");
#अन्यथा
    ptr = tcc_malloc(आकार += PAGESIZE); /* one extra page to align malloc memory */
#पूर्ण_अगर
    s1->run_ptr = ptr;
    s1->run_आकार = आकार;
    वापस ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI पूर्णांक tcc_relocate(TCCState *s1)
{
    पूर्णांक आकार, ret, ptr_diff;

    अगर (s1->run_ptr)
        निकास(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#अगर_घोषित CONFIG_TCC_BACKTRACE
    अगर (s1->do_backtrace)
        tcc_add_प्रतीक(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#पूर्ण_अगर
    आकार = tcc_relocate_ex(s1, शून्य, 0);
    अगर (आकार < 0)
        वापस -1;
    ptr_diff = rt_mem(s1, आकार);
    अगर (ptr_diff < 0)
        वापस -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    अगर (ret == 0)
        st_link(s1);
    वापस ret;
}

ST_FUNC व्योम tcc_run_free(TCCState *s1)
{
    अचिन्हित आकार;
    व्योम *ptr;
    पूर्णांक i;

    /* free any loaded DLLs */
    क्रम ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        अगर ( ref->handle )
#अगर_घोषित _WIN32
            FreeLibrary((HMODULE)ref->handle);
#अन्यथा
            dlclose(ref->handle);
#पूर्ण_अगर
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    अगर (शून्य == ptr)
        वापस;
    st_unlink(s1);
#अगर_घोषित _WIN64
    win64_del_function_table(s1->run_function_table);
#पूर्ण_अगर
    आकार = s1->run_आकार;
#अगर_घोषित CONFIG_SELINUX
    munmap(ptr, आकार);
#या_अगर CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, आकार, MEM_RELEASE);
#अन्यथा
    /* unprotect memory to make it usable for malloc again */
    protect_pages((व्योम*)PAGEALIGN(ptr), आकार - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#पूर्ण_अगर
}

#घोषणा RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI पूर्णांक tcc_run(TCCState *s1, पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक (*prog_main)(पूर्णांक, अक्षर **, अक्षर **), ret;
    स्थिर अक्षर *शीर्ष_sym;
    लाँघ_बफ main_jb;

#अगर defined(__APPLE__)
    बाह्य अक्षर ***_NSGetEnviron(व्योम);
    अक्षर **envp = *_NSGetEnviron();
#या_अगर defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    बाह्य अक्षर **environ;
    अक्षर **envp = environ;
#अन्यथा
    अक्षर **envp = environ;
#पूर्ण_अगर

    /* tcc -dt -run ... nothing to do if no main() */
    अगर ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        वापस 0;

    tcc_add_प्रतीक(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", शीर्ष_sym = "main";
    अगर (s1->elf_entryname)
        s1->run_main = शीर्ष_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    अगर (tcc_relocate(s1) < 0)
        वापस -1;

    prog_main = (व्योम*)get_sym_addr(s1, s1->run_main, 1, 1);
    अगर ((addr_t)-1 == (addr_t)prog_main)
        वापस -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    अगर (s1->run_stdin && !ख_व_खोलो(s1->run_stdin, "r", मानक_निवेश)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        वापस -1;
    }

    त्रुटि_सं = 0; /* clean errno value */
    ख_साफ(मानक_निकास);
    ख_साफ(मानक_त्रुटि);

    ret = tcc_setjmp(s1, main_jb, tcc_get_प्रतीक(s1, शीर्ष_sym));
    अगर (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } अन्यथा अगर (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    अगर (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        ख_लिखो(s1->ppfp, "[returns %d]\n", ret), ख_साफ(s1->ppfp);
    वापस ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
अटल व्योम cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णांक sym_सूचकांक, end_sym = s->तथ्य_offset / माप (ElfSym);
    /* reset symtab */
    s->तथ्य_offset = s->link->तथ्य_offset = s->hash->तथ्य_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    क्रम (sym_सूचकांक = 1; sym_सूचकांक < end_sym; ++sym_सूचकांक) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->तथ्य)[sym_सूचकांक];
        स्थिर अक्षर *name = (अक्षर *)s->link->तथ्य + sym->st_name;
        अगर (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            जारी;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_मूल्य, sym->st_आकार, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
अटल व्योम cleanup_sections(TCCState *s1)
{
    काष्ठा { Section **secs; पूर्णांक nb_secs; } *p = (व्योम*)&s1->sections;
    पूर्णांक i, f = 2;
    करो {
        क्रम (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            अगर (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->तथ्य = tcc_realloc(s->तथ्य, s->तथ्य_allocated = s->तथ्य_offset);
            } अन्यथा {
                free_section(s), tcc_free(s), p->secs[i] = शून्य;
            }
        }
    } जबतक (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#अगर_अघोषित CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# अन्यथा
#   define CONFIG_RUNMEM_RO 0
#  endif
#पूर्ण_अगर

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
अटल पूर्णांक tcc_relocate_ex(TCCState *s1, व्योम *ptr, अचिन्हित ptr_diff)
{
    Section *s;
    अचिन्हित offset, लंबाई, align, i, k, f;
    अचिन्हित n, copy;
    addr_t mem, addr;

    अगर (शून्य == ptr) {
        s1->nb_errors = 0;
#अगर_घोषित TCC_TARGET_PE
        pe_output_file(s1, शून्य);
#अन्यथा
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#पूर्ण_अगर
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    अगर (s1->verbose == 2 && copy)
        म_लिखो(&"-----------------------------------------------------\n"[PTR_आकार*2 - 8]);
    अगर (s1->nb_errors)
        वापस -1;
    अगर (copy == 3)
        वापस 0;

    क्रम (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        क्रम(i = 1; i < s1->nb_sections; i++) {
            अटल स्थिर अक्षर shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            अगर (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                जारी;
            लंबाई = s->तथ्य_offset;
            अगर (copy == 2) {
                अगर (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + लंबाई;
                जारी;
            }
            अगर (copy) { /* final step: copy section data to memory */
                अगर (s1->verbose == 2)
                    म_लिखो("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (व्योम*)s->sh_addr, लंबाई, s->sh_addralign);
                ptr = (व्योम*)s->sh_addr;
                अगर (k == 0)
                    ptr = (व्योम*)(s->sh_addr + ptr_diff);
                अगर (शून्य == s->तथ्य || s->sh_type == SHT_NOBITS)
                    स_रखो(ptr, 0, लंबाई);
                अन्यथा
                    स_नकल(ptr, s->तथ्य, लंबाई);
                जारी;
            }

            अगर ((s->sh_flags & SHF_TLS) && लंबाई)
                वापस tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            अगर (++n == 1) {
#अगर defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                अगर (align < 64)
                    align = 64;
#पूर्ण_अगर
                /* start new page for different permissions */
                अगर (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += लंबाई;
        }
        अगर (copy == 2) { /* set permissions */
            अगर (n == 0) /* no data  */
                जारी;
#अगर_घोषित CONFIG_SELINUX
            अगर (k == 0) /* SHF_EXECINSTR has its own mapping */
                जारी;
#पूर्ण_अगर
            f = k;
            अगर (f >= CONFIG_RUNMEM_RO) {
                अगर (f != 0)
                    जारी;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            अगर (s1->verbose == 2) {
                म_लिखो("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (व्योम*)addr, (अचिन्हित)n);
            }
            अगर (protect_pages((व्योम*)addr, n, f) < 0)
                वापस tcc_error_noabort(
#अगर_घोषित _WIN32
                    "VirtualProtect failed");
#अन्यथा
                    "mprotect failed (did you mean to configure --with-selinux?)");
#पूर्ण_अगर
        }
    }

    अगर (0 == mem)
        वापस PAGEALIGN(offset);

    अगर (++copy == 2) {
        जाओ redo;
    }
    अगर (copy == 3) {
#अगर_घोषित _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#पूर्ण_अगर
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        जाओ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    अगर (s1->nb_errors)
        जाओ redo;
    /* relocate sections */
#अगर_घोषित TCC_TARGET_PE
    s1->pe_imagebase = mem;
#अन्यथा
    relocate_plt(s1);
#पूर्ण_अगर
    relocate_sections(s1);
    जाओ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

अटल पूर्णांक protect_pages(व्योम *ptr, अचिन्हित दीर्घ लंबाई, पूर्णांक mode)
{
#अगर_घोषित _WIN32
    अटल स्थिर अचिन्हित अक्षर protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    अगर (!VirtualProtect(ptr, लंबाई, protect[mode], &old))
        वापस -1;
#अन्यथा
    अटल स्थिर अचिन्हित अक्षर protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    अगर (mprotect(ptr, लंबाई, protect[mode]))
        वापस -1;
#पूर्ण_अगर
/* XXX: BSD sometimes dump core with bad system call */
#अगर (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    अगर (mode == 0 || mode == 3) {
#अगर_घोषित _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, लंबाई);
#अन्यथा
        व्योम __clear_cache(व्योम *beginning, व्योम *end);
        __clear_cache(ptr, (अक्षर *)ptr + लंबाई);
#पूर्ण_अगर
    }
#पूर्ण_अगर
    वापस 0;
}

#अगर_घोषित _WIN64
अटल व्योम *win64_add_function_table(TCCState *s1)
{
    व्योम *p = शून्य;
    अगर (s1->uw_pdata) {
        p = (व्योम*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->तथ्य_offset / माप (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = शून्य;
    }
    वापस p;
}

अटल व्योम win64_del_function_table(व्योम *p)
{
    अगर (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#पूर्ण_अगर

अटल व्योम bt_link(TCCState *s1)
{
#अगर_घोषित CONFIG_TCC_BACKTRACE
    rt_context *rc;
    अगर (!s1->do_backtrace)
        वापस;
    rc = tcc_get_प्रतीक(s1, "__rt_info");
    अगर (!rc)
        वापस;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->तथ्य);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->तथ्य + symtab_section->तथ्य_offset);
    rc->elf_str = (अक्षर *)symtab_section->link->तथ्य;
    अगर (PTR_आकार == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#अगर_घोषित CONFIG_TCC_BCHECK
    अगर (s1->do_bounds_check) {
        व्योम *p;
        अगर ((p = tcc_get_प्रतीक(s1, "__bound_init")))
            ((व्योम(*)(व्योम*,पूर्णांक))p)(rc->bounds_start, 1);
    }
#पूर्ण_अगर
    rc->अग्र = g_rc, g_rc = rc, s1->rc = rc;
    अगर (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#पूर्ण_अगर
}

अटल व्योम st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->अग्र = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
अटल व्योम ptr_unlink(व्योम *list, व्योम *e, अचिन्हित अग्र)
{
    व्योम **pp, **nn, *p;
    क्रम (pp = list; !!(p = *pp); pp = nn) {
        nn = (व्योम*)((अक्षर*)p + अग्र); /* nn = &p->next; */
        अगर (p == e) {
            *pp = *nn;
            अवरोध;
        }
    }
}

अटल व्योम st_unlink(TCCState *s1)
{
    rt_wait_sem();
#अगर_घोषित CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, दुरत्व(rt_context, अग्र));
#पूर्ण_अगर
    ptr_unlink(&g_s1, s1, दुरत्व(TCCState, अग्र));
    rt_post_sem();
}

LIBTCCAPI व्योम *_tcc_setjmp(TCCState *s1, व्योम *p_jmp_buf, व्योम *func, व्योम *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#अगर_घोषित CONFIG_TCC_BACKTRACE
    अगर (s1->rc)
        s1->rc->शीर्ष_func = func;
#पूर्ण_अगर
    वापस p_jmp_buf;
}

LIBTCCAPI व्योम tcc_set_backtrace_func(TCCState *s1, व्योम *तथ्य, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_तथ्य = तथ्य;
}

अटल TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    पूर्णांक level;
    addr_t pc;

    s = g_s1;
    अगर (शून्य == s || शून्य == s->अग्र) {
        /* play it safe in the simple case when there is only one state */
        वापस s;
    }
    क्रम (level = 0; level < 8; ++level) {
        अगर (rt_get_caller_pc(&pc, f, level) < 0)
            अवरोध;
        क्रम (s = g_s1; s; s = s->अग्र) {
            अगर (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_आकार)
                वापस s;
        }
    }
    वापस शून्य;
}

अटल व्योम rt_exit(rt_frame *f, पूर्णांक code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    अगर (s && s->run_lj) {
#अगर_घोषित CONFIG_TCC_BCHECK
        अगर (f->fp) { /* called from signal */
            व्योम *p = tcc_get_प्रतीक(s, "__bound_exit");
            अगर (p)
                ((व्योम (*)(व्योम))p)();
        }
#पूर्ण_अगर
        अगर (code == 0)
            code = RT_EXIT_ZERO;
        ((व्योम(*)(व्योम*,पूर्णांक))s->run_lj)(s->run_jb, code);
    }
    निकास(code);
}

/* ------------------------------------------------------------- */
#अन्यथा // if defined CONFIG_TCC_BACKTRACE_ONLY
अटल व्योम rt_exit(rt_frame *f, पूर्णांक code)
{
    निकास(code);
}
#पूर्ण_अगर //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#अगर_घोषित CONFIG_TCC_BACKTRACE

अटल पूर्णांक rt_vprintf(स्थिर अक्षर *fmt, बहु_सूची ap)
{
    पूर्णांक ret = भख_लिखो(मानक_त्रुटि, fmt, ap);
    ख_साफ(मानक_त्रुटि);
    वापस ret;
}

अटल पूर्णांक rt_printf(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap;
    पूर्णांक r;
    बहु_शुरू(ap, fmt);
    r = rt_vprintf(fmt, ap);
    बहु_पूर्ण(ap);
    वापस r;
}

अटल अक्षर *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    क्रम (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        पूर्णांक type = ELFW(ST_TYPE)(esym->st_info);
        अगर ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_मूल्य
            && wanted_pc < esym->st_मूल्य + esym->st_आकार) {
            *func_addr = esym->st_मूल्य;
            वापस rc->elf_str + esym->st_name;
        }
    }
    वापस शून्य;
}

प्रकार काष्ठा bt_info
{
    अक्षर file[100];
    पूर्णांक पंक्ति_2;
    अक्षर func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
अटल addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    अक्षर func_name[128];
    addr_t func_addr, last_pc, pc;
    स्थिर अक्षर *incl_files[INCLUDE_ढेर_आकार];
    पूर्णांक incl_सूचकांक, last_incl_सूचकांक, len, last_पंक्ति_अंक, i;
    स्थिर अक्षर *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_सूचकांक = 0;
    last_pc = (addr_t)-1;
    last_पंक्ति_अंक = 1;
    last_incl_सूचकांक = 0;

    क्रम (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_मूल्य;

        चयन(sym->n_type) {
        हाल N_SLINE:
            अगर (func_addr)
                जाओ rel_pc;
        हाल N_SO:
        हाल N_SOL:
            जाओ abs_pc;
        हाल N_FUN:
            अगर (sym->n_strx == 0) /* end of function */
                जाओ rel_pc;
        abs_pc:
#अगर PTR_आकार == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#पूर्ण_अगर
            जाओ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            अगर (pc >= wanted_pc && wanted_pc >= last_pc)
                जाओ found;
            अवरोध;
        }

        चयन(sym->n_type) {
            /* function start or end */
        हाल N_FUN:
            अगर (sym->n_strx == 0)
                जाओ reset_func;
            p = म_अक्षर(str, ':');
            अगर (0 == p || (len = p - str + 1, len > माप func_name))
                len = माप func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            अवरोध;
            /* line number info */
        हाल N_SLINE:
            last_pc = pc;
            last_पंक्ति_अंक = sym->n_desc;
            last_incl_सूचकांक = incl_सूचकांक;
            अवरोध;
            /* include files */
        हाल N_BINCL:
            अगर (incl_सूचकांक < INCLUDE_ढेर_आकार)
                incl_files[incl_सूचकांक++] = str;
            अवरोध;
        हाल N_EINCL:
            अगर (incl_सूचकांक > 1)
                incl_सूचकांक--;
            अवरोध;
            /* start/end of translation unit */
        हाल N_SO:
            incl_सूचकांक = 0;
            अगर (sym->n_strx) {
                /* do not add path */
                len = म_माप(str);
                अगर (len > 0 && str[len - 1] != '/')
                    incl_files[incl_सूचकांक++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            अवरोध;
            /* alternative file name (from #line or #include directives) */
        हाल N_SOL:
            अगर (incl_सूचकांक)
                incl_files[incl_सूचकांक-1] = str;
            अवरोध;
        }
    }
    last_incl_सूचकांक = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_सूचकांक;
    अगर (i > 0) {
        pstrcpy(bi->file, माप bi->file, incl_files[--i]);
        bi->पंक्ति_2 = last_पंक्ति_अंक;
    }
    pstrcpy(bi->func, माप bi->func, func_name);
    bi->func_pc = func_addr;
    वापस func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#घोषणा DIR_TABLE_आकार	(64)
#घोषणा FILE_TABLE_आकार	(512)

#घोषणा	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	चयन (entry_format[j].form) { \
	हाल DW_FORM_data1: (ln) += 1; अवरोध; \
	हाल DW_FORM_data2: (ln) += 2; अवरोध; \
	हाल DW_FORM_data4: (ln) += 3; अवरोध; \
	हाल DW_FORM_data8: (ln) += 8; अवरोध; \
	हाल DW_FORM_data16: (ln) += 16; अवरोध; \
	हाल DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); अवरोध; \
	शेष: जाओ अग्र_पंक्ति; \
	}

अटल addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    अचिन्हित अक्षर *ln;
    अचिन्हित अक्षर *cp;
    अचिन्हित अक्षर *end;
    अचिन्हित अक्षर *opcode_लंबाई;
    अचिन्हित दीर्घ दीर्घ आकार;
    अचिन्हित पूर्णांक लंबाई;
    अचिन्हित अक्षर version;
    अचिन्हित पूर्णांक min_insn_लंबाई;
    अचिन्हित पूर्णांक max_ops_per_insn;
    पूर्णांक पंक्ति_base;
    अचिन्हित पूर्णांक पंक्ति_range;
    अचिन्हित पूर्णांक opcode_base;
    अचिन्हित पूर्णांक opindex;
    अचिन्हित पूर्णांक col;
    अचिन्हित पूर्णांक i;
    अचिन्हित पूर्णांक j;
    अचिन्हित पूर्णांक len;
    अचिन्हित दीर्घ दीर्घ मूल्य;
    काष्ठा {
	अचिन्हित पूर्णांक type;
	अचिन्हित पूर्णांक form;
    } entry_format[256];
    अचिन्हित पूर्णांक dir_आकार;
#अगर 0
    अक्षर *dirs[DIR_TABLE_आकार];
#पूर्ण_अगर
    अचिन्हित पूर्णांक filename_आकार;
    काष्ठा /*dwarf_filename_struct*/ {
        अचिन्हित पूर्णांक dir_entry;
        अक्षर *name;
    } filename_table[FILE_TABLE_आकार];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    पूर्णांक पंक्ति_2;
    अक्षर *filename;
    अक्षर *function;

    filename = शून्य;
    function = शून्य;
    func_addr = 0;
    पंक्ति_2 = 0;

    ln = rc->dwarf_पंक्ति;
    जबतक (ln < rc->dwarf_पंक्ति_end) {
	dir_आकार = 0;
	filename_आकार = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        पंक्ति_2 = 1;
        filename = शून्य;
        function = शून्य;
	लंबाई = 4;
	आकार = dwarf_read_4(ln, rc->dwarf_पंक्ति_end);
	अगर (आकार == 0xffffffffu) // dwarf 64
	    लंबाई = 8, आकार = dwarf_read_8(ln, rc->dwarf_पंक्ति_end);
	end = ln + आकार;
	अगर (end < ln || end > rc->dwarf_पंक्ति_end)
	    अवरोध;
	version = dwarf_read_2(ln, end);
	अगर (version >= 5)
	    ln += लंबाई + 2; // address size, segment selector, prologue Length
	अन्यथा
	    ln += लंबाई; // prologue Length
	min_insn_लंबाई = dwarf_read_1(ln, end);
	अगर (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	अन्यथा
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	पंक्ति_base = dwarf_read_1(ln, end);
	पंक्ति_base |= पंक्ति_base >= 0x80 ? ~0xff : 0;
	पंक्ति_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_लंबाई = ln;
	ln += opcode_base - 1;
	opindex = 0;
	अगर (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    क्रम (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_आकार = dwarf_read_uleb128(&ln, end);
	    क्रम (i = 0; i < dir_आकार; i++) {
		क्रम (j = 0; j < col; j++) {
		    अगर (entry_format[j].type == DW_LNCT_path) {
		        अगर (entry_format[j].form != DW_FORM_पंक्ति_strp)
			    जाओ अग्र_पंक्ति;
#अगर 0
		        मूल्य = लंबाई == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        अगर (i < DIR_TABLE_आकार)
		            dirs[i] = (अक्षर *)rc->dwarf_पंक्ति_str + मूल्य;
#अन्यथा
			लंबाई == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#पूर्ण_अगर
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    क्रम (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_आकार = dwarf_read_uleb128(&ln, end);
	    क्रम (i = 0; i < filename_आकार; i++)
		क्रम (j = 0; j < col; j++) {
		    अगर (entry_format[j].type == DW_LNCT_path) {
			अगर (entry_format[j].form != DW_FORM_पंक्ति_strp)
			    जाओ अग्र_पंक्ति;
			मूल्य = लंबाई == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        अगर (i < FILE_TABLE_आकार)
		            filename_table[i].name =
				(अक्षर *)rc->dwarf_पंक्ति_str + मूल्य;
	            }
		    अन्यथा अगर (entry_format[j].type == DW_LNCT_directory_सूचकांक) {
			चयन (entry_format[j].form) {
			हाल DW_FORM_data1: मूल्य = dwarf_read_1(ln, end); अवरोध;
			हाल DW_FORM_data2: मूल्य = dwarf_read_2(ln, end); अवरोध;
			हाल DW_FORM_data4: मूल्य = dwarf_read_4(ln, end); अवरोध;
			हाल DW_FORM_udata: मूल्य = dwarf_read_uleb128(&ln, end); अवरोध;
			शेष: जाओ अग्र_पंक्ति;
			}
		        अगर (i < FILE_TABLE_आकार)
		            filename_table[i].dir_entry = मूल्य;
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, end);
	    }
	}
	अन्यथा {
	    जबतक ((dwarf_read_1(ln, end))) {
#अगर 0
		अगर (++dir_आकार < DIR_TABLE_आकार)
		    dirs[dir_आकार - 1] = (अक्षर *)ln - 1;
#पूर्ण_अगर
		जबतक (dwarf_read_1(ln, end)) {}
	    }
	    जबतक ((dwarf_read_1(ln, end))) {
		अगर (++filename_आकार < FILE_TABLE_आकार) {
		    filename_table[filename_आकार - 1].name = (अक्षर *)ln - 1;
		    जबतक (dwarf_read_1(ln, end)) {}
		    filename_table[filename_आकार - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		अन्यथा {
		    जबतक (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); //आकार
	    }
	}
	अगर (filename_आकार >= 1)
	    filename = filename_table[0].name;
	जबतक (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    अगर (i >= opcode_base) {
	        अगर (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / पंक्ति_range) * min_insn_लंबाई;
		अन्यथा {
		    pc += (opindex + (i - opcode_base) / पंक्ति_range) /
			  max_ops_per_insn * min_insn_लंबाई;
		    opindex = (opindex + (i - opcode_base) / पंक्ति_range) %
			       max_ops_per_insn;
		}
		i = (पूर्णांक)((i - opcode_base) % पंक्ति_range) + पंक्ति_base;
check_pc:
		अगर (pc >= wanted_pc && wanted_pc >= last_pc)
		    जाओ found;
		पंक्ति_2 += i;
	    }
	    अन्यथा {
	        चयन (i) {
	        हाल 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    अगर (len == 0)
		        जाओ अग्र_पंक्ति;
		    चयन (dwarf_read_1(cp, end)) {
		    हाल DW_LNE_end_sequence:
		        अवरोध;
		    हाल DW_LNE_set_address:
#अगर PTR_आकार == 4
		        pc = dwarf_read_4(cp, end);
#अन्यथा
		        pc = dwarf_read_8(cp, end);
#पूर्ण_अगर
#अगर defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#पूर्ण_अगर
		        opindex = 0;
		        अवरोध;
		    हाल DW_LNE_define_file: /* deprecated */
		        अगर (++filename_आकार < FILE_TABLE_आकार) {
		            filename_table[filename_आकार - 1].name = (अक्षर *)ln - 1;
		            जबतक (dwarf_read_1(ln, end)) {}
		            filename_table[filename_आकार - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        अन्यथा {
		            जबतक (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); //आकार
		        अवरोध;
		    हाल DW_LNE_hi_user - 1:
		        function = (अक्षर *)cp;
		        func_addr = pc;
		        अवरोध;
		    शेष:
		        अवरोध;
		    }
		    अवरोध;
	        हाल DW_LNS_advance_pc:
		    अगर (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_लंबाई;
		    अन्यथा {
		        अचिन्हित दीर्घ दीर्घ off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_लंबाई;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    जाओ check_pc;
	        हाल DW_LNS_advance_पंक्ति:
		    पंक्ति_2 += dwarf_read_sleb128(&ln, end);
		    अवरोध;
	        हाल DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    अगर (i < FILE_TABLE_आकार && i < filename_आकार)
		        filename = filename_table[i].name;
		    अवरोध;
	        हाल DW_LNS_const_add_pc:
		    अगर (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / पंक्ति_range) * min_insn_लंबाई;
		    अन्यथा {
		        अचिन्हित पूर्णांक off = (255 - opcode_base) / पंक्ति_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_लंबाई;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    जाओ check_pc;
	        हाल DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    जाओ check_pc;
	        शेष:
		    क्रम (j = 0; j < opcode_लंबाई[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    अवरोध;
		}
	    }
	}
अग्र_पंक्ति:
	ln = end;
    }
    filename = function = शून्य, func_addr = 0;
found:
    अगर (filename)
        pstrcpy(bi->file, माप bi->file, filename), bi->पंक्ति_2 = पंक्ति_2;
    अगर (function)
        pstrcpy(bi->func, माप bi->func, function);
    bi->func_pc = func_addr;
    वापस (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#अगर_अघोषित CONFIG_TCC_BACKTRACE_ONLY
अटल
#पूर्ण_अगर
पूर्णांक _tcc_backtrace(rt_frame *f, स्थिर अक्षर *fmt, बहु_सूची ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    अक्षर skip[40], संदेश[200];
    पूर्णांक i, level, ret, n, one;
    स्थिर अक्षर *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    अगर (fmt[0] == '^' && (b = म_अक्षर(a = fmt + 1, fmt[0]))) {
        स_नकल(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    अगर (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(संदेश, माप संदेश, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    अगर (rc) {
        अगर (rc->dwarf)
            getinfo = rt_printline_dwarf;
        अगर (rc->अंक_callers)
            n = rc->अंक_callers;
    }

    क्रम (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        अगर (ret == -1)
            अवरोध;
        स_रखो(&bi, 0, माप bi);
        क्रम (rc2 = rc; rc2; rc2 = rc2->अग्र) {
            अगर (getinfo(rc2, pc, &bi))
                अवरोध;
            /* we try symtab symbols (no line number info) */
            अगर (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, माप bi.func, a);
                अवरोध;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        अगर (skip[0] && म_माला(bi.file, skip))
            जारी;
#अगर_अघोषित CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            अगर (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_तथ्य,
                    (व्योम*)pc,
                    bi.file[0] ? bi.file : शून्य,
                    bi.पंक्ति_2,
                    bi.func[0] ? bi.func : शून्य,
                    level == 0 ? संदेश : शून्य
                    );
                अगर (ret == 0)
                    अवरोध;
                जाओ check_break;
            }
        }
#पूर्ण_अगर
        अगर (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.पंक्ति_2);
        } अन्यथा {
            rt_printf("0x%08llx", (दीर्घ दीर्घ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        अगर (level == 0) {
            rt_printf(": %s", संदेश);
            अगर (one)
                अवरोध;
        }
        rt_printf("\n");

#अगर_अघोषित CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#पूर्ण_अगर
        अगर (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->शीर्ष_func)
            अवरोध;
        ++level;
    }
    rt_post_sem();
    वापस 0;
}

/* emit a run time error at position 'pc' */
अटल पूर्णांक rt_error(rt_frame *f, स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap; अक्षर संदेश[200]; पूर्णांक ret;
    बहु_शुरू(ap, fmt);
    snprintf(संदेश, माप संदेश, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, संदेश, ap);
    बहु_पूर्ण(ap);
    वापस ret;
}

/* ------------------------------------------------------------- */

#अगर_अघोषित _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#अन्यथा
# define ucontext_t CONTEXT
#पूर्ण_अगर

/* translate from ucontext_t* to internal rt_context * */
अटल व्योम rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#अगर defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#या_अगर defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#या_अगर defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#या_अगर defined __i386__
# अगर defined(__APPLE__)
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
#या_अगर defined(__x86_64__)
# अगर defined(__APPLE__)
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
#या_अगर defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#या_अगर defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#या_अगर defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#या_अगर defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#या_अगर defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#या_अगर defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#या_अगर defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#या_अगर defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#या_अगर defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#या_अगर defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#या_अगर defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#पूर्ण_अगर
}

/* ------------------------------------------------------------- */
#अगर_अघोषित _WIN32
/* signal handler for fatal errors */
अटल व्योम sig_error(पूर्णांक signum, siginfo_t *siginf, व्योम *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    चयन(signum) {
    हाल संक_भ_त्रुटि:
        चयन(siginf->si_code) {
        हाल FPE_INTDIV:
        हाल FPE_FLTDIV:
            rt_error(&f, "division by zero");
            अवरोध;
        शेष:
            rt_error(&f, "floating point exception");
            अवरोध;
        }
        अवरोध;
    हाल SIGBUS:
    हाल संक_अंश:
        rt_error(&f, "invalid memory access");
        अवरोध;
    हाल संक_अवैध:
        rt_error(&f, "illegal instruction");
        अवरोध;
    हाल SIGABRT:
        rt_error(&f, "abort() called");
        अवरोध;
    शेष:
        rt_error(&f, "caught signal %d", signum);
        अवरोध;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, शून्य);
    }
    rt_exit(&f, 255);
}

#अगर_अघोषित SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#पूर्ण_अगर

/* Generate a stack backtrace when a CPU exception occurs. */
अटल व्योम set_exception_handler(व्योम)
{
    काष्ठा sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#अगर 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#पूर्ण_अगर
    sigact.sa_sigaction = sig_error;
    sigaction(संक_भ_त्रुटि, &sigact, शून्य);
    sigaction(संक_अवैध, &sigact, शून्य);
    sigaction(संक_अंश, &sigact, शून्य);
    sigaction(SIGBUS, &sigact, शून्य);
    sigaction(SIGABRT, &sigact, शून्य);
#अगर 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        अटल अचिन्हित अक्षर ढेर[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = ढेर;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, शून्य);
    }
#पूर्ण_अगर
}

#अन्यथा /* WIN32 */

/* signal handler for fatal errors */
अटल दीर्घ __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    अचिन्हित code;
    rt_getcontext(ex_info->ContextRecord, &f);

    चयन (code = ex_info->ExceptionRecord->ExceptionCode) {
    हाल EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        अवरोध;
    हाल EXCEPTION_ढेर_OVERFLOW:
        rt_error(&f, "stack overflow");
        अवरोध;
    हाल EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        अवरोध;
    हाल EXCEPTION_BREAKPOINT:
    हाल EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        वापस EXCEPTION_CONTINUE_खोज;
    शेष:
        rt_error(&f, "caught exception %08x", code);
        अवरोध;
    }
    rt_exit(&f, 255);
    वापस EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
अटल व्योम set_exception_handler(व्योम)
{
#अगर_घोषित _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#अन्यथा
    SetUnhandledExceptionFilter(cpu_exception_handler);
#पूर्ण_अगर
}

#पूर्ण_अगर

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#अगर defined(__i386__) || defined(__x86_64__)
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    अगर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        जबतक (1) {
            अगर (fp < 0x1000)
                वापस -1;
            अगर (0 == --level)
                अवरोध;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    वापस 0;
}

/* XXX: only supports linux/bsd */
#या_अगर defined(__arm__) && !defined(_WIN32)
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    अगर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        जबतक (1) {
            अगर (fp < 0x1000)
                वापस -1;
            अगर (0 == --level)
                अवरोध;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    वापस 0;
}

#या_अगर defined(__aarch64__)
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    अगर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        जबतक (1) {
            अगर (fp < 0x1000)
                वापस -1;
            अगर (0 == --level)
                अवरोध;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    वापस 0;
}

#या_अगर defined(__riscv)
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    अगर (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        जबतक (1) {
            अगर (fp < 0x1000)
                वापस -1;
            अगर (0 == --level)
                अवरोध;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    वापस 0;
}

#अन्यथा
#warning add arch specific rt_get_caller_pc()
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णांक level)
{
    वापस -1;
}

#पूर्ण_अगर
#अन्यथा // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
अटल पूर्णांक rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णांक level)
{
    अगर (level)
        वापस -1;
    *paddr = f->ip;
    वापस 0;
}
#पूर्ण_अगर /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#अगर_घोषित CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC व्योम *dlopen(स्थिर अक्षर *filename, पूर्णांक flag)
{
    वापस शून्य;
}

ST_FUNC व्योम dlclose(व्योम *p)
{
}

ST_FUNC स्थिर अक्षर *dlerror(व्योम)
{
    वापस "error";
}

प्रकार काष्ठा TCCSyms {
    अक्षर *str;
    व्योम *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
अटल TCCSyms tcc_syms[] = {
#अगर !defined(CONFIG_TCCBOOT)
#घोषणा TCCSYM(a) { #a, &a, },
    TCCSYM(म_लिखो)
    TCCSYM(ख_लिखो)
    TCCSYM(ख_खोलो)
    TCCSYM(ख_बंद)
#अघोषित TCCSYM
#पूर्ण_अगर
    { शून्य, शून्य },
};

ST_FUNC व्योम *dlsym(व्योम *handle, स्थिर अक्षर *प्रतीक)
{
    TCCSyms *p;
    p = tcc_syms;
    जबतक (p->str != शून्य) {
        अगर (!म_भेद(p->str, प्रतीक))
            वापस p->ptr;
        p++;
    }
    वापस शून्य;
}

#पूर्ण_अगर /* CONFIG_TCC_STATIC */
#पूर्ण_अगर /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
