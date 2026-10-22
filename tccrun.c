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
#यदि_परिभाषितम् TCC_IS_NATIVE

#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
/* runtime debug info block */
प्रकारनिर्देश संरचना rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    सङ्घ {
	संरचना {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_अन्तः;
	    वर्ण *stab_str;
	};
	संरचना {
	    अचिह्नित वर्ण *dwarf_पङ्क्तिः;
	    अचिह्नित वर्ण *dwarf_पङ्क्तिः_अन्तः;
	    अचिह्नित वर्ण *dwarf_पङ्क्तिः_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_अन्तः;
    वर्ण *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_आधारः;
    शून्य *bounds_start;
    शून्य *शिखरम्_func;
    संरचना rt_context *अग्र;
    // 10 * PTR_SIZE
    पूर्णाङ्क अङ्कः_callers;
    पूर्णाङ्क dwarf;
} rt_context;

/* linked list of rt_contexts */
स्थिर rt_context *g_rc;
स्थिर पूर्णाङ्क signal_समुच्चयः;
स्थिर शून्य समुच्चयः_exception_handler(शून्य);
#यदि_अन्तः /* def CONFIG_TCC_BACKTRACE */

प्रकारनिर्देश संरचना rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

स्थिर TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(स्थिर rt_sem);
स्थिर शून्य rt_wait_sem(शून्य) { WAIT_SEM(&rt_sem); }
स्थिर शून्य rt_post_sem(शून्य) { POST_SEM(&rt_sem); }
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णाङ्क level);
स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क संहिता);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#यदि_अपरिभाषितम् CONFIG_TCC_BACKTRACE_ONLY

#यदि_अपरिभाषितम् _WIN32
# include <sys/mman.h>
#यदि_अन्तः

स्थिर पूर्णाङ्क protect_पृष्ठानि(शून्य *ptr, अचिह्नित दीर्घ दीर्घता, पूर्णाङ्क बहुलकम्);
स्थिर पूर्णाङ्क tcc_relocate_ex(TCCState *s1, शून्य *ptr, अचिह्नित ptr_diff);
स्थिर शून्य st_link(TCCState *s1);
स्थिर शून्य st_unlink(TCCState *s1);
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
स्थिर पूर्णाङ्क _tcc_backtrace(rt_frame *f, ध्रुव वर्ण *fmt, va_list ap);
#यदि_अन्तः
#यदि_परिभाषितम् _WIN64
स्थिर शून्य *win64_सङ्कलय_function_सारणी(TCCState *s1);
स्थिर शून्य win64_del_function_सारणी(शून्य *);
#यदि_अन्तः

#यदि !defined PAGESIZE
# यदि defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# अन्यथा
#  define PAGESIZE 4096
# endif
#यदि_अन्तः

#परिभाषय PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#यदि !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#यदि_अन्तः

/* use VirtualAlloc() instead of tcc_malloc() */
#यदि defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#यदि_अन्तः

स्थिर पूर्णाङ्क rt_mem(TCCState *s1, पूर्णाङ्क आकार)
{
    शून्य *ptr;
    पूर्णाङ्क ptr_diff = 0;
#यदि_परिभाषितम् CONFIG_SELINUX
    /* Using mmap instead of malloc */
    शून्य *prw;
    वर्ण tmpfname[] = "/tmp/.tccrunXXXXXX";
    पूर्णाङ्क fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, आकार);

    ptr = mmap(रिक्त, आकार * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((वर्ण*)ptr + आकार, आकार, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    यदि (ptr == MAP_FAILED || prw == MAP_FAILED)
	प्रत्यागम tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (वर्ण*)prw - (वर्ण*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    आकार *= 2;
#नोचेद्यदि CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(रिक्त, आकार, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    यदि (!ptr)
        प्रत्यागम tcc_error_noabort("tccrun: could not allocate memory");
#अन्यथा
    ptr = tcc_malloc(आकार += PAGESIZE); /* one extra page to align malloc memory */
#यदि_अन्तः
    s1->सततम्_ptr = ptr;
    s1->सततम्_आकार = आकार;
    प्रत्यागम ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI पूर्णाङ्क tcc_relocate(TCCState *s1)
{
    पूर्णाङ्क आकार, ret, ptr_diff;

    यदि (s1->सततम्_ptr)
        निर्गच्छ(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    यदि (s1->do_backtrace)
        tcc_सङ्कलय_चिह्नम्(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#यदि_अन्तः
    आकार = tcc_relocate_ex(s1, रिक्त, 0);
    यदि (आकार < 0)
        प्रत्यागम -1;
    ptr_diff = rt_mem(s1, आकार);
    यदि (ptr_diff < 0)
        प्रत्यागम -1;
    ret = tcc_relocate_ex(s1, s1->सततम्_ptr, ptr_diff);
    यदि (ret == 0)
        st_link(s1);
    प्रत्यागम ret;
}

ST_FUNC शून्य tcc_सततम्_free(TCCState *s1)
{
    अचिह्नित आकार;
    शून्य *ptr;
    पूर्णाङ्क i;

    /* free any loaded DLLs */
    प्रति ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        यदि ( ref->handle )
#यदि_परिभाषितम् _WIN32
            FreeLibrary((HMODULE)ref->handle);
#अन्यथा
            dlclose(ref->handle);
#यदि_अन्तः
    }
    /* unmap or unprotect and free memory */
    ptr = s1->सततम्_ptr;
    यदि (रिक्त == ptr)
        प्रत्यागम;
    st_unlink(s1);
#यदि_परिभाषितम् _WIN64
    win64_del_function_सारणी(s1->सततम्_function_सारणी);
#यदि_अन्तः
    आकार = s1->सततम्_आकार;
#यदि_परिभाषितम् CONFIG_SELINUX
    munmap(ptr, आकार);
#नोचेद्यदि CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, आकार, MEM_RELEASE);
#अन्यथा
    /* unprotect memory to make it usable for malloc again */
    protect_पृष्ठानि((शून्य*)PAGEALIGN(ptr), आकार - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#यदि_अन्तः
}

#परिभाषय RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI पूर्णाङ्क tcc_सततम्(TCCState *s1, पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क (*prog_main)(पूर्णाङ्क, वर्ण **, वर्ण **), ret;
    ध्रुव वर्ण *शिखरम्_sym;
    jmp_buf main_jb;

#यदि defined(__APPLE__)
    बाह्य वर्ण ***_NSGetEnviron(शून्य);
    वर्ण **envp = *_NSGetEnviron();
#नोचेद्यदि defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    बाह्य वर्ण **environ;
    वर्ण **envp = environ;
#अन्यथा
    वर्ण **envp = environ;
#यदि_अन्तः

    /* tcc -dt -run ... nothing to do if no main() */
    यदि ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        प्रत्यागम 0;

    tcc_सङ्कलय_चिह्नम्(s1, "__rt_exit", rt_exit);
    s1->सततम्_main = "_runmain", शिखरम्_sym = "main";
    यदि (s1->elf_entryname)
        s1->सततम्_main = शिखरम्_sym = s1->elf_entryname;
    tcc_सङ्कलय_support(s1, "runmain.o");

    यदि (tcc_relocate(s1) < 0)
        प्रत्यागम -1;

    prog_main = (शून्य*)get_sym_addr(s1, s1->सततम्_main, 1, 1);
    यदि ((addr_t)-1 == (addr_t)prog_main)
        प्रत्यागम -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    यदि (s1->सततम्_stdin && !freopen(s1->सततम्_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->सततम्_stdin);
        प्रत्यागम -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_चिह्नम्(s1, शिखरम्_sym));
    यदि (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } अन्यथा यदि (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    यदि (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    प्रत्यागम ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
स्थिर शून्य cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    पूर्णाङ्क sym_सूचकांक, अन्तः_sym = s->दत्त_विस्थापनम् / परिमाण (ElfSym);
    /* reset symtab */
    s->दत्त_विस्थापनम् = s->link->दत्त_विस्थापनम् = s->hash->दत्त_विस्थापनम् = 0;
    init_symtab(s);
    /* add global symbols again */
    प्रति (sym_सूचकांक = 1; sym_सूचकांक < अन्तः_sym; ++sym_सूचकांक) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->दत्त)[sym_सूचकांक];
        ध्रुव वर्ण *name = (वर्ण *)s->link->दत्त + sym->st_name;
        यदि (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            अनुवर्त;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_मानम्, sym->st_आकार, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
स्थिर शून्य cleanup_sections(TCCState *s1)
{
    संरचना { Section **secs; पूर्णाङ्क nb_secs; } *p = (शून्य*)&s1->sections;
    पूर्णाङ्क i, f = 2;
    कुरु {
        प्रति (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            यदि (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->दत्त = tcc_realloc(s->दत्त, s->दत्त_allocated = s->दत्त_विस्थापनम्);
            } अन्यथा {
                free_section(s), tcc_free(s), p->secs[i] = रिक्त;
            }
        }
    } यावत् (++p, f);
}

/* ------------------------------------------------------------- */
/* 0 = .text rwx  other rwx (memory >= 2 pages a 4096 bytes) */
/* 1 = .text rx   other rw (memory >= 3 pages) */
/* 2 = .text rx  .rdata ro  .data/.bss rw (memory >= 4 pages) */

/* Some targets implement secutiry options that do not allow write in
   executable code. These targets need CONFIG_RUNMEM_RO=1.
   The disadvantage of this is that it requires a little bit more memory. */

#यदि_अपरिभाषितम् CONFIG_RUNMEM_RO
# ifdef __APPLE__
#   define CONFIG_RUNMEM_RO 1
# अन्यथा
#   define CONFIG_RUNMEM_RO 0
#  endif
#यदि_अन्तः

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
स्थिर पूर्णाङ्क tcc_relocate_ex(TCCState *s1, शून्य *ptr, अचिह्नित ptr_diff)
{
    Section *s;
    अचिह्नित विस्थापनम्, दीर्घता, align, i, k, f;
    अचिह्नित n, copy;
    addr_t mem, addr;

    यदि (रिक्त == ptr) {
        s1->nb_errors = 0;
#यदि_परिभाषितम् TCC_TARGET_PE
        pe_output_file(s1, रिक्त);
#अन्यथा
        tcc_सङ्कलय_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#यदि_अन्तः
    }

    विस्थापनम् = copy = 0;
    mem = (addr_t)ptr;
redo:
    यदि (s1->verbose == 2 && copy)
        प्रारूप_लिख(&"-----------------------------------------------------\n"[PTR_आकार*2 - 8]);
    यदि (s1->nb_errors)
        प्रत्यागम -1;
    यदि (copy == 3)
        प्रत्यागम 0;

    प्रति (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        प्रति(i = 1; i < s1->nb_sections; i++) {
            स्थिर ध्रुव वर्ण shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            यदि (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                अनुवर्त;
            दीर्घता = s->दत्त_विस्थापनम्;
            यदि (copy == 2) {
                यदि (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + दीर्घता;
                अनुवर्त;
            }
            यदि (copy) { /* final step: copy section data to memory */
                यदि (s1->verbose == 2)
                    प्रारूप_लिख("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (शून्य*)s->sh_addr, दीर्घता, s->sh_addralign);
                ptr = (शून्य*)s->sh_addr;
                यदि (k == 0)
                    ptr = (शून्य*)(s->sh_addr + ptr_diff);
                यदि (रिक्त == s->दत्त || s->sh_type == SHT_NOBITS)
                    स्मृतिं_पूरय(ptr, 0, दीर्घता);
                अन्यथा
                    स्मृतिं_प्रतिलिख(ptr, s->दत्त, दीर्घता);
                अनुवर्त;
            }

            यदि ((s->sh_flags & SHF_TLS) && दीर्घता)
                प्रत्यागम tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            यदि (++n == 1) {
#यदि defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                यदि (align < 64)
                    align = 64;
#यदि_अन्तः
                /* start new page for different permissions */
                यदि (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            विस्थापनम् += -(addr + विस्थापनम्) & (align - 1);
            s->sh_addr = mem ? addr + विस्थापनम् : 0;
            विस्थापनम् += दीर्घता;
        }
        यदि (copy == 2) { /* set permissions */
            यदि (n == 0) /* no data  */
                अनुवर्त;
#यदि_परिभाषितम् CONFIG_SELINUX
            यदि (k == 0) /* SHF_EXECINSTR has its own mapping */
                अनुवर्त;
#यदि_अन्तः
            f = k;
            यदि (f >= CONFIG_RUNMEM_RO) {
                यदि (f != 0)
                    अनुवर्त;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            यदि (s1->verbose == 2) {
                प्रारूप_लिख("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (शून्य*)addr, (अचिह्नित)n);
            }
            यदि (protect_पृष्ठानि((शून्य*)addr, n, f) < 0)
                प्रत्यागम tcc_error_noabort(
#यदि_परिभाषितम् _WIN32
                    "VirtualProtect failed");
#अन्यथा
                    "mprotect failed (did you mean to configure --with-selinux?)");
#यदि_अन्तः
        }
    }

    यदि (0 == mem)
        प्रत्यागम PAGEALIGN(विस्थापनम्);

    यदि (++copy == 2) {
        गच्छ redo;
    }
    यदि (copy == 3) {
#यदि_परिभाषितम् _WIN64
        s1->सततम्_function_सारणी = win64_सङ्कलय_function_सारणी(s1);
#यदि_अन्तः
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        गच्छ redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    यदि (s1->nb_errors)
        गच्छ redo;
    /* relocate sections */
#यदि_परिभाषितम् TCC_TARGET_PE
    s1->pe_imagebase = mem;
#अन्यथा
    relocate_plt(s1);
#यदि_अन्तः
    relocate_sections(s1);
    गच्छ redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

स्थिर पूर्णाङ्क protect_पृष्ठानि(शून्य *ptr, अचिह्नित दीर्घ दीर्घता, पूर्णाङ्क बहुलकम्)
{
#यदि_परिभाषितम् _WIN32
    स्थिर ध्रुव अचिह्नित वर्ण protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    यदि (!VirtualProtect(ptr, दीर्घता, protect[बहुलकम्], &old))
        प्रत्यागम -1;
#अन्यथा
    स्थिर ध्रुव अचिह्नित वर्ण protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    यदि (mprotect(ptr, दीर्घता, protect[बहुलकम्]))
        प्रत्यागम -1;
#यदि_अन्तः
/* XXX: BSD sometimes dump core with bad system call */
#यदि (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    यदि (बहुलकम् == 0 || बहुलकम् == 3) {
#यदि_परिभाषितम् _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, दीर्घता);
#अन्यथा
        शून्य __clear_cache(शून्य *beginning, शून्य *अन्तः);
        __clear_cache(ptr, (वर्ण *)ptr + दीर्घता);
#यदि_अन्तः
    }
#यदि_अन्तः
    प्रत्यागम 0;
}

#यदि_परिभाषितम् _WIN64
स्थिर शून्य *win64_सङ्कलय_function_सारणी(TCCState *s1)
{
    शून्य *p = रिक्त;
    यदि (s1->uw_pdata) {
        p = (शून्य*)s1->uw_pdata->sh_addr;
        Rtl_सङ्कलय_Function_सारणी(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->दत्त_विस्थापनम् / परिमाण (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = रिक्त;
    }
    प्रत्यागम p;
}

स्थिर शून्य win64_del_function_सारणी(शून्य *p)
{
    यदि (p) {
        Rtl_Delete_Function_सारणी((RUNTIME_FUNCTION*)p);
    }
}
#यदि_अन्तः

स्थिर शून्य bt_link(TCCState *s1)
{
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    rt_context *rc;
    यदि (!s1->do_backtrace)
        प्रत्यागम;
    rc = tcc_get_चिह्नम्(s1, "__rt_info");
    यदि (!rc)
        प्रत्यागम;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->दत्त);
    rc->esym_अन्तः = (ElfW(Sym) *)(symtab_section->दत्त + symtab_section->दत्त_विस्थापनम्);
    rc->elf_str = (वर्ण *)symtab_section->link->दत्त;
    यदि (PTR_आकार == 8 && !s1->dwarf)
        rc->prog_आधारः &= 0xffffffff00000000ULL;
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
    यदि (s1->do_bounds_check) {
        शून्य *p;
        यदि ((p = tcc_get_चिह्नम्(s1, "__bound_init")))
            ((शून्य(*)(शून्य*,पूर्णाङ्क))p)(rc->bounds_start, 1);
    }
#यदि_अन्तः
    rc->अग्र = g_rc, g_rc = rc, s1->rc = rc;
    यदि (0 == signal_समुच्चयः)
        समुच्चयः_exception_handler(), signal_समुच्चयः = 1;
#यदि_अन्तः
}

स्थिर शून्य st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->अग्र = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
स्थिर शून्य ptr_unlink(शून्य *list, शून्य *e, अचिह्नित अग्र)
{
    शून्य **pp, **nn, *p;
    प्रति (pp = list; !!(p = *pp); pp = nn) {
        nn = (शून्य*)((वर्ण*)p + अग्र); /* nn = &p->next; */
        यदि (p == e) {
            *pp = *nn;
            भङ्ग;
        }
    }
}

स्थिर शून्य st_unlink(TCCState *s1)
{
    rt_wait_sem();
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, अग्र));
#यदि_अन्तः
    ptr_unlink(&g_s1, s1, offsetof(TCCState, अग्र));
    rt_post_sem();
}

LIBTCCAPI शून्य *_tcc_setjmp(TCCState *s1, शून्य *p_jmp_buf, शून्य *func, शून्य *p_longjmp)
{
    s1->सततम्_lj = p_longjmp;
    s1->सततम्_jb = p_jmp_buf;
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE
    यदि (s1->rc)
        s1->rc->शिखरम्_func = func;
#यदि_अन्तः
    प्रत्यागम p_jmp_buf;
}

LIBTCCAPI शून्य tcc_समुच्चयः_backtrace_func(TCCState *s1, शून्य *दत्त, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_दत्त = दत्त;
}

स्थिर TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    पूर्णाङ्क level;
    addr_t pc;

    s = g_s1;
    यदि (रिक्त == s || रिक्त == s->अग्र) {
        /* play it safe in the simple case when there is only one state */
        प्रत्यागम s;
    }
    प्रति (level = 0; level < 8; ++level) {
        यदि (rt_get_caller_pc(&pc, f, level) < 0)
            भङ्ग;
        प्रति (s = g_s1; s; s = s->अग्र) {
            यदि (pc >= (addr_t)s->सततम्_ptr
             && pc  < (addr_t)s->सततम्_ptr + s->सततम्_आकार)
                प्रत्यागम s;
        }
    }
    प्रत्यागम रिक्त;
}

स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क संहिता)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    यदि (s && s->सततम्_lj) {
#यदि_परिभाषितम् CONFIG_TCC_BCHECK
        यदि (f->fp) { /* called from signal */
            शून्य *p = tcc_get_चिह्नम्(s, "__bound_exit");
            यदि (p)
                ((शून्य (*)(शून्य))p)();
        }
#यदि_अन्तः
        यदि (संहिता == 0)
            संहिता = RT_EXIT_ZERO;
        ((शून्य(*)(शून्य*,पूर्णाङ्क))s->सततम्_lj)(s->सततम्_jb, संहिता);
    }
    निर्गच्छ(संहिता);
}

/* ------------------------------------------------------------- */
#अन्यथा // if defined CONFIG_TCC_BACKTRACE_ONLY
स्थिर शून्य rt_exit(rt_frame *f, पूर्णाङ्क संहिता)
{
    निर्गच्छ(संहिता);
}
#यदि_अन्तः //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#यदि_परिभाषितम् CONFIG_TCC_BACKTRACE

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
    प्रति (esym = rc->esym_start + 1; esym < rc->esym_अन्तः; ++esym) {
        पूर्णाङ्क type = ELFW(ST_TYPE)(esym->st_info);
        यदि ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_मानम्
            && wanted_pc < esym->st_मानम् + esym->st_आकार) {
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
    addr_t func_addr, चरमः_pc, pc;
    ध्रुव वर्ण *incl_files[INCLUDE_राशिः_आकार];
    पूर्णाङ्क incl_सूचकांक, चरमः_incl_सूचकांक, len, चरमः_पङ्क्तिः_अङ्कः, i;
    ध्रुव वर्ण *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_सूचकांक = 0;
    चरमः_pc = (addr_t)-1;
    चरमः_पङ्क्तिः_अङ्कः = 1;
    चरमः_incl_सूचकांक = 0;

    प्रति (sym = rc->stab_sym + 1; sym < rc->stab_sym_अन्तः; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_मानम्;

        विकल्प(sym->n_type) {
        पक्ष N_SLINE:
            यदि (func_addr)
                गच्छ rel_pc;
        पक्ष N_SO:
        पक्ष N_SOL:
            गच्छ abs_pc;
        पक्ष N_FUN:
            यदि (sym->n_strx == 0) /* end of function */
                गच्छ rel_pc;
        abs_pc:
#यदि PTR_आकार == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_आधारः;
#यदि_अन्तः
            गच्छ check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            यदि (pc >= wanted_pc && wanted_pc >= चरमः_pc)
                गच्छ प्राप्तम्;
            भङ्ग;
        }

        विकल्प(sym->n_type) {
            /* function start or end */
        पक्ष N_FUN:
            यदि (sym->n_strx == 0)
                गच्छ reset_func;
            p = strchr(str, ':');
            यदि (0 == p || (len = p - str + 1, len > परिमाण func_name))
                len = परिमाण func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            भङ्ग;
            /* line number info */
        पक्ष N_SLINE:
            चरमः_pc = pc;
            चरमः_पङ्क्तिः_अङ्कः = sym->n_desc;
            चरमः_incl_सूचकांक = incl_सूचकांक;
            भङ्ग;
            /* include files */
        पक्ष N_BINCL:
            यदि (incl_सूचकांक < INCLUDE_राशिः_आकार)
                incl_files[incl_सूचकांक++] = str;
            भङ्ग;
        पक्ष N_EINCL:
            यदि (incl_सूचकांक > 1)
                incl_सूचकांक--;
            भङ्ग;
            /* start/end of translation unit */
        पक्ष N_SO:
            incl_सूचकांक = 0;
            यदि (sym->n_strx) {
                /* do not add path */
                len = वाक्यदैर्घ्यम्(str);
                यदि (len > 0 && str[len - 1] != '/')
                    incl_files[incl_सूचकांक++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            चरमः_pc = (addr_t)-1;
            भङ्ग;
            /* alternative file name (from #line or #include directives) */
        पक्ष N_SOL:
            यदि (incl_सूचकांक)
                incl_files[incl_सूचकांक-1] = str;
            भङ्ग;
        }
    }
    चरमः_incl_सूचकांक = 0, func_name[0] = 0, func_addr = 0;
प्राप्तम्:
    i = चरमः_incl_सूचकांक;
    यदि (i > 0) {
        pstrcpy(bi->file, परिमाण bi->file, incl_files[--i]);
        bi->पङ्क्तिः = चरमः_पङ्क्तिः_अङ्कः;
    }
    pstrcpy(bi->func, परिमाण bi->func, func_name);
    bi->func_pc = func_addr;
    प्रत्यागम func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#परिभाषय DIR_सारणी_आकार	(64)
#परिभाषय FILE_सारणी_आकार	(512)

#परिभाषय	dwarf_ignore_type(ln, अन्तः) /* timestamp/size/md5/... */ \
	विकल्प (प्रविष्टिः_format[j].form) { \
	पक्ष DW_FORM_data1: (ln) += 1; भङ्ग; \
	पक्ष DW_FORM_data2: (ln) += 2; भङ्ग; \
	पक्ष DW_FORM_data4: (ln) += 3; भङ्ग; \
	पक्ष DW_FORM_data8: (ln) += 8; भङ्ग; \
	पक्ष DW_FORM_data16: (ln) += 16; भङ्ग; \
	पक्ष DW_FORM_udata: dwarf_read_uleb128(&(ln), (अन्तः)); भङ्ग; \
	स्वभाव: गच्छ अग्र_पङ्क्तिः; \
	}

स्थिर addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    अचिह्नित वर्ण *ln;
    अचिह्नित वर्ण *cp;
    अचिह्नित वर्ण *अन्तः;
    अचिह्नित वर्ण *opcode_दीर्घता;
    अचिह्नित दीर्घ दीर्घ आकार;
    अचिह्नित पूर्णाङ्क दीर्घता;
    अचिह्नित वर्ण संस्करणम्;
    अचिह्नित पूर्णाङ्क min_insn_दीर्घता;
    अचिह्नित पूर्णाङ्क max_ops_प्रत्येकम्_insn;
    पूर्णाङ्क पङ्क्तिः_आधारः;
    अचिह्नित पूर्णाङ्क पङ्क्तिः_range;
    अचिह्नित पूर्णाङ्क opcode_आधारः;
    अचिह्नित पूर्णाङ्क opindex;
    अचिह्नित पूर्णाङ्क col;
    अचिह्नित पूर्णाङ्क i;
    अचिह्नित पूर्णाङ्क j;
    अचिह्नित पूर्णाङ्क len;
    अचिह्नित दीर्घ दीर्घ मानम्;
    संरचना {
	अचिह्नित पूर्णाङ्क type;
	अचिह्नित पूर्णाङ्क form;
    } प्रविष्टिः_format[256];
    अचिह्नित पूर्णाङ्क dir_आकार;
#यदि 0
    वर्ण *dirs[DIR_सारणी_आकार];
#यदि_अन्तः
    अचिह्नित पूर्णाङ्क filename_आकार;
    संरचना /*dwarf_filename_struct*/ {
        अचिह्नित पूर्णाङ्क dir_प्रविष्टिः;
        वर्ण *name;
    } filename_सारणी[FILE_सारणी_आकार];
    addr_t चरमः_pc;
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
    यावत् (ln < rc->dwarf_पङ्क्तिः_अन्तः) {
	dir_आकार = 0;
	filename_आकार = 0;
        चरमः_pc = 0;
        pc = 0;
        func_addr = 0;
        पङ्क्तिः = 1;
        filename = रिक्त;
        function = रिक्त;
	दीर्घता = 4;
	आकार = dwarf_read_4(ln, rc->dwarf_पङ्क्तिः_अन्तः);
	यदि (आकार == 0xffffffffu) // dwarf 64
	    दीर्घता = 8, आकार = dwarf_read_8(ln, rc->dwarf_पङ्क्तिः_अन्तः);
	अन्तः = ln + आकार;
	यदि (अन्तः < ln || अन्तः > rc->dwarf_पङ्क्तिः_अन्तः)
	    भङ्ग;
	संस्करणम् = dwarf_read_2(ln, अन्तः);
	यदि (संस्करणम् >= 5)
	    ln += दीर्घता + 2; // address size, segment selector, prologue Length
	अन्यथा
	    ln += दीर्घता; // prologue Length
	min_insn_दीर्घता = dwarf_read_1(ln, अन्तः);
	यदि (संस्करणम् >= 4)
	    max_ops_प्रत्येकम्_insn = dwarf_read_1(ln, अन्तः);
	अन्यथा
	    max_ops_प्रत्येकम्_insn = 1;
	ln++; // Initial value of 'is_stmt'
	पङ्क्तिः_आधारः = dwarf_read_1(ln, अन्तः);
	पङ्क्तिः_आधारः |= पङ्क्तिः_आधारः >= 0x80 ? ~0xff : 0;
	पङ्क्तिः_range = dwarf_read_1(ln, अन्तः);
	opcode_आधारः = dwarf_read_1(ln, अन्तः);
	opcode_दीर्घता = ln;
	ln += opcode_आधारः - 1;
	opindex = 0;
	यदि (संस्करणम् >= 5) {
	    col = dwarf_read_1(ln, अन्तः);
	    प्रति (i = 0; i < col; i++) {
	        प्रविष्टिः_format[i].type = dwarf_read_uleb128(&ln, अन्तः);
	        प्रविष्टिः_format[i].form = dwarf_read_uleb128(&ln, अन्तः);
	    }
	    dir_आकार = dwarf_read_uleb128(&ln, अन्तः);
	    प्रति (i = 0; i < dir_आकार; i++) {
		प्रति (j = 0; j < col; j++) {
		    यदि (प्रविष्टिः_format[j].type == DW_LNCT_मार्गः) {
		        यदि (प्रविष्टिः_format[j].form != DW_FORM_पङ्क्तिः_strp)
			    गच्छ अग्र_पङ्क्तिः;
#यदि 0
		        मानम् = दीर्घता == 4 ? dwarf_read_4(ln, अन्तः)
					    : dwarf_read_8(ln, अन्तः);
		        यदि (i < DIR_सारणी_आकार)
		            dirs[i] = (वर्ण *)rc->dwarf_पङ्क्तिः_str + मानम्;
#अन्यथा
			दीर्घता == 4 ? dwarf_read_4(ln, अन्तः)
				    : dwarf_read_8(ln, अन्तः);
#यदि_अन्तः
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, अन्तः);
		}
	    }
	    col = dwarf_read_1(ln, अन्तः);
	    प्रति (i = 0; i < col; i++) {
	        प्रविष्टिः_format[i].type = dwarf_read_uleb128(&ln, अन्तः);
	        प्रविष्टिः_format[i].form = dwarf_read_uleb128(&ln, अन्तः);
	    }
	    filename_आकार = dwarf_read_uleb128(&ln, अन्तः);
	    प्रति (i = 0; i < filename_आकार; i++)
		प्रति (j = 0; j < col; j++) {
		    यदि (प्रविष्टिः_format[j].type == DW_LNCT_मार्गः) {
			यदि (प्रविष्टिः_format[j].form != DW_FORM_पङ्क्तिः_strp)
			    गच्छ अग्र_पङ्क्तिः;
			मानम् = दीर्घता == 4 ? dwarf_read_4(ln, अन्तः)
					    : dwarf_read_8(ln, अन्तः);
		        यदि (i < FILE_सारणी_आकार)
		            filename_सारणी[i].name =
				(वर्ण *)rc->dwarf_पङ्क्तिः_str + मानम्;
	            }
		    अन्यथा यदि (प्रविष्टिः_format[j].type == DW_LNCT_directory_सूचकांक) {
			विकल्प (प्रविष्टिः_format[j].form) {
			पक्ष DW_FORM_data1: मानम् = dwarf_read_1(ln, अन्तः); भङ्ग;
			पक्ष DW_FORM_data2: मानम् = dwarf_read_2(ln, अन्तः); भङ्ग;
			पक्ष DW_FORM_data4: मानम् = dwarf_read_4(ln, अन्तः); भङ्ग;
			पक्ष DW_FORM_udata: मानम् = dwarf_read_uleb128(&ln, अन्तः); भङ्ग;
			स्वभाव: गच्छ अग्र_पङ्क्तिः;
			}
		        यदि (i < FILE_सारणी_आकार)
		            filename_सारणी[i].dir_प्रविष्टिः = मानम्;
		    }
		    अन्यथा 
			dwarf_ignore_type(ln, अन्तः);
	    }
	}
	अन्यथा {
	    यावत् ((dwarf_read_1(ln, अन्तः))) {
#यदि 0
		यदि (++dir_आकार < DIR_सारणी_आकार)
		    dirs[dir_आकार - 1] = (वर्ण *)ln - 1;
#यदि_अन्तः
		यावत् (dwarf_read_1(ln, अन्तः)) {}
	    }
	    यावत् ((dwarf_read_1(ln, अन्तः))) {
		यदि (++filename_आकार < FILE_सारणी_आकार) {
		    filename_सारणी[filename_आकार - 1].name = (वर्ण *)ln - 1;
		    यावत् (dwarf_read_1(ln, अन्तः)) {}
		    filename_सारणी[filename_आकार - 1].dir_प्रविष्टिः =
		        dwarf_read_uleb128(&ln, अन्तः);
		}
		अन्यथा {
		    यावत् (dwarf_read_1(ln, अन्तः)) {}
		    dwarf_read_uleb128(&ln, अन्तः);
		}
		dwarf_read_uleb128(&ln, अन्तः); // time
		dwarf_read_uleb128(&ln, अन्तः); //आकार
	    }
	}
	यदि (filename_आकार >= 1)
	    filename = filename_सारणी[0].name;
	यावत् (ln < अन्तः) {
	    चरमः_pc = pc;
	    i = dwarf_read_1(ln, अन्तः);
	    यदि (i >= opcode_आधारः) {
	        यदि (max_ops_प्रत्येकम्_insn == 1)
		    pc += ((i - opcode_आधारः) / पङ्क्तिः_range) * min_insn_दीर्घता;
		अन्यथा {
		    pc += (opindex + (i - opcode_आधारः) / पङ्क्तिः_range) /
			  max_ops_प्रत्येकम्_insn * min_insn_दीर्घता;
		    opindex = (opindex + (i - opcode_आधारः) / पङ्क्तिः_range) %
			       max_ops_प्रत्येकम्_insn;
		}
		i = (पूर्णाङ्क)((i - opcode_आधारः) % पङ्क्तिः_range) + पङ्क्तिः_आधारः;
check_pc:
		यदि (pc >= wanted_pc && wanted_pc >= चरमः_pc)
		    गच्छ प्राप्तम्;
		पङ्क्तिः += i;
	    }
	    अन्यथा {
	        विकल्प (i) {
	        पक्ष 0:
		    len = dwarf_read_uleb128(&ln, अन्तः);
		    cp = ln;
		    ln += len;
		    यदि (len == 0)
		        गच्छ अग्र_पङ्क्तिः;
		    विकल्प (dwarf_read_1(cp, अन्तः)) {
		    पक्ष DW_LNE_अन्तः_sequence:
		        भङ्ग;
		    पक्ष DW_LNE_समुच्चयः_स्थानाङ्कः:
#यदि PTR_आकार == 4
		        pc = dwarf_read_4(cp, अन्तः);
#अन्यथा
		        pc = dwarf_read_8(cp, अन्तः);
#यदि_अन्तः
#यदि defined TCC_TARGET_MACHO
			pc += rc->prog_आधारः;
#यदि_अन्तः
		        opindex = 0;
		        भङ्ग;
		    पक्ष DW_LNE_define_file: /* deprecated */
		        यदि (++filename_आकार < FILE_सारणी_आकार) {
		            filename_सारणी[filename_आकार - 1].name = (वर्ण *)ln - 1;
		            यावत् (dwarf_read_1(ln, अन्तः)) {}
		            filename_सारणी[filename_आकार - 1].dir_प्रविष्टिः =
		                dwarf_read_uleb128(&ln, अन्तः);
		        }
		        अन्यथा {
		            यावत् (dwarf_read_1(ln, अन्तः)) {}
		            dwarf_read_uleb128(&ln, अन्तः);
		        }
		        dwarf_read_uleb128(&ln, अन्तः); // time
		        dwarf_read_uleb128(&ln, अन्तः); //आकार
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
		    यदि (max_ops_प्रत्येकम्_insn == 1)
		        pc += dwarf_read_uleb128(&ln, अन्तः) * min_insn_दीर्घता;
		    अन्यथा {
		        अचिह्नित दीर्घ दीर्घ off = dwarf_read_uleb128(&ln, अन्तः);

		        pc += (opindex + off) / max_ops_प्रत्येकम्_insn *
			      min_insn_दीर्घता;
		        opindex = (opindex + off) % max_ops_प्रत्येकम्_insn;
		    }
		    i = 0;
		    गच्छ check_pc;
	        पक्ष DW_LNS_advance_पङ्क्तिः:
		    पङ्क्तिः += dwarf_read_sleb128(&ln, अन्तः);
		    भङ्ग;
	        पक्ष DW_LNS_समुच्चयः_file:
		    i = dwarf_read_uleb128(&ln, अन्तः);
		    i -= i > 0 && संस्करणम् < 5;
		    यदि (i < FILE_सारणी_आकार && i < filename_आकार)
		        filename = filename_सारणी[i].name;
		    भङ्ग;
	        पक्ष DW_LNS_const_सङ्कलय_pc:
		    यदि (max_ops_प्रत्येकम्_insn ==  1)
		        pc += ((255 - opcode_आधारः) / पङ्क्तिः_range) * min_insn_दीर्घता;
		    अन्यथा {
		        अचिह्नित पूर्णाङ्क off = (255 - opcode_आधारः) / पङ्क्तिः_range;

		        pc += ((opindex + off) / max_ops_प्रत्येकम्_insn) *
			      min_insn_दीर्घता;
		        opindex = (opindex + off) % max_ops_प्रत्येकम्_insn;
		    }
		    i = 0;
		    गच्छ check_pc;
	        पक्ष DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, अन्तः);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    गच्छ check_pc;
	        स्वभाव:
		    प्रति (j = 0; j < opcode_दीर्घता[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, अन्तः);
		    भङ्ग;
		}
	    }
	}
अग्र_पङ्क्तिः:
	ln = अन्तः;
    }
    filename = function = रिक्त, func_addr = 0;
प्राप्तम्:
    यदि (filename)
        pstrcpy(bi->file, परिमाण bi->file, filename), bi->पङ्क्तिः = पङ्क्तिः;
    यदि (function)
        pstrcpy(bi->func, परिमाण bi->func, function);
    bi->func_pc = func_addr;
    प्रत्यागम (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#यदि_अपरिभाषितम् CONFIG_TCC_BACKTRACE_ONLY
स्थिर
#यदि_अन्तः
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
    यदि (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        स्मृतिं_प्रतिलिख(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    यदि (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(सन्देशः, परिमाण सन्देशः, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    यदि (rc) {
        यदि (rc->dwarf)
            getinfo = rt_printline_dwarf;
        यदि (rc->अङ्कः_callers)
            n = rc->अङ्कः_callers;
    }

    प्रति (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        यदि (ret == -1)
            भङ्ग;
        स्मृतिं_पूरय(&bi, 0, परिमाण bi);
        प्रति (rc2 = rc; rc2; rc2 = rc2->अग्र) {
            यदि (getinfo(rc2, pc, &bi))
                भङ्ग;
            /* we try symtab symbols (no line number info) */
            यदि (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, परिमाण bi.func, a);
                भङ्ग;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        यदि (skip[0] && वाक्ये_अन्विष(bi.file, skip))
            अनुवर्त;
#यदि_अपरिभाषितम् CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            यदि (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_दत्त,
                    (शून्य*)pc,
                    bi.file[0] ? bi.file : रिक्त,
                    bi.पङ्क्तिः,
                    bi.func[0] ? bi.func : रिक्त,
                    level == 0 ? सन्देशः : रिक्त
                    );
                यदि (ret == 0)
                    भङ्ग;
                गच्छ check_break;
            }
        }
#यदि_अन्तः
        यदि (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.पङ्क्तिः);
        } अन्यथा {
            rt_printf("0x%08llx", (दीर्घ दीर्घ)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        यदि (level == 0) {
            rt_printf(": %s", सन्देशः);
            यदि (one)
                भङ्ग;
        }
        rt_printf("\n");

#यदि_अपरिभाषितम् CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#यदि_अन्तः
        यदि (rc2
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

#यदि_अपरिभाषितम् _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#अन्यथा
# define ucontext_t CONTEXT
#यदि_अन्तः

/* translate from ucontext_t* to internal rt_context * */
स्थिर शून्य rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#यदि defined _WIN64 && defined __aarch64__
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
# यदि defined(__APPLE__)
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
#नोचेद्यदि defined(__x86_64__)
# यदि defined(__APPLE__)
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
#यदि_अन्तः
}

/* ------------------------------------------------------------- */
#यदि_अपरिभाषितम् _WIN32
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

#यदि_अपरिभाषितम् SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#यदि_अन्तः

/* Generate a stack backtrace when a CPU exception occurs. */
स्थिर शून्य समुच्चयः_exception_handler(शून्य)
{
    संरचना sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#यदि 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#यदि_अन्तः
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, रिक्त);
    sigaction(SIGILL, &sigact, रिक्त);
    sigaction(SIGSEGV, &sigact, रिक्त);
    sigaction(SIGBUS, &sigact, रिक्त);
    sigaction(SIGABRT, &sigact, रिक्त);
#यदि 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        स्थिर अचिह्नित वर्ण राशिः[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = राशिः;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, रिक्त);
    }
#यदि_अन्तः
}

#अन्यथा /* WIN32 */

/* signal handler for fatal errors */
स्थिर दीर्घ __stdcall cpu_exception_handler(EXCEPTION_सूचकाः *ex_info)
{
    rt_frame f;
    अचिह्नित संहिता;
    rt_getcontext(ex_info->Context_लेखः, &f);

    विकल्प (संहिता = ex_info->Exception_लेखः->Exception_संहिता) {
    पक्ष EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        भङ्ग;
    पक्ष EXCEPTION_राशिः_अतिप्रवाहः:
        rt_error(&f, "stack overflow");
        भङ्ग;
    पक्ष EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        भङ्ग;
    पक्ष EXCEPTION_BREAKPOINT:
    पक्ष EXCEPTION_SINGLE_चरणः:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        प्रत्यागम EXCEPTION_CONTINUE_अन्वेषणम्;
    स्वभाव:
        rt_error(&f, "caught exception %08x", संहिता);
        भङ्ग;
    }
    rt_exit(&f, 255);
    प्रत्यागम EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
स्थिर शून्य समुच्चयः_exception_handler(शून्य)
{
#यदि_परिभाषितम् _WIN64
    सङ्कलय_Vectored_Exception_Handler(1, cpu_exception_handler);
#अन्यथा
    समुच्चयः_Unhandled_Exception_Filter(cpu_exception_handler);
#यदि_अन्तः
}

#यदि_अन्तः

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#यदि defined(__i386__) || defined(__x86_64__)
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    यदि (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        यावत् (1) {
            यदि (fp < 0x1000)
                प्रत्यागम -1;
            यदि (0 == --level)
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
    यदि (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        यावत् (1) {
            यदि (fp < 0x1000)
                प्रत्यागम -1;
            यदि (0 == --level)
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
    यदि (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        यावत् (1) {
            यदि (fp < 0x1000)
                प्रत्यागम -1;
            यदि (0 == --level)
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
    यदि (level == 0) {
        *paddr = rc->ip;
    } अन्यथा {
        addr_t fp = rc->fp;
        यावत् (1) {
            यदि (fp < 0x1000)
                प्रत्यागम -1;
            यदि (0 == --level)
                भङ्ग;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    प्रत्यागम 0;
}

#अन्यथा
#warning सङ्कलय arch specific rt_get_caller_pc()
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *rc, पूर्णाङ्क level)
{
    प्रत्यागम -1;
}

#यदि_अन्तः
#अन्यथा // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
स्थिर पूर्णाङ्क rt_get_caller_pc(addr_t *paddr, rt_frame *f, पूर्णाङ्क level)
{
    यदि (level)
        प्रत्यागम -1;
    *paddr = f->ip;
    प्रत्यागम 0;
}
#यदि_अन्तः /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#यदि_परिभाषितम् CONFIG_TCC_STATIC

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
#यदि !defined(CONFIG_TCCBOOT)
#परिभाषय TCCSYM(a) { #a, &a, },
    TCCSYM(प्रारूप_लिख)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#अपरिभाषय TCCSYM
#यदि_अन्तः
    { रिक्त, रिक्त },
};

ST_FUNC शून्य *dlsym(शून्य *handle, ध्रुव वर्ण *चिह्नम्)
{
    TCCSyms *p;
    p = tcc_syms;
    यावत् (p->str != रिक्त) {
        यदि (!वाक्यं_तुलय(p->str, चिह्नम्))
            प्रत्यागम p->ptr;
        p++;
    }
    प्रत्यागम रिक्त;
}

#यदि_अन्तः /* CONFIG_TCC_STATIC */
#यदि_अन्तः /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
