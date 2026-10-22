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

#include "tcc.h"

/* only native compiler supports -run */
#ifdef TCC_IS_NATIVE

#ifdef CONFIG_TCC_BACKTRACE
/* runtime debug info block */
typedef sa_nracanaa rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    sa_ngha {
	sa_nracanaa {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    var_na *stab_str;
	};
	sa_nracanaa {
	    unsigned var_na *dwarf_line;
	    unsigned var_na *dwarf_line_end;
	    unsigned var_na *dwarf_line_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    var_na *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    void *bounds_start;
    void *top_func;
    sa_nracanaa rt_context *next;
    // 10 * PTR_SIZE
    ကိန်းပြည့် num_callers;
    ကိန်းပြည့် dwarf;
} rt_context;

/* linked list of rt_contexts */
static rt_context *g_rc;
static ကိန်းပြည့် signal_set;
static void set_exception_handler(void);
#endif /* def CONFIG_TCC_BACKTRACE */

typedef sa_nracanaa rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

static TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(static rt_sem);
static void rt_wait_sem(void) { WAIT_SEM(&rt_sem); }
static void rt_post_sem(void) { POST_SEM(&rt_sem); }
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *f, ကိန်းပြည့် level);
static void rt_exit(rt_frame *f, ကိန်းပြည့် code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

static ကိန်းပြည့် protect_pages(void *ptr, unsigned long length, ကိန်းပြည့် mode);
static ကိန်းပြည့် tcc_relocate_ex(TCCState *s1, void *ptr, unsigned ptr_diff);
static void st_link(TCCState *s1);
static void st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
static ကိန်းပြည့် _tcc_backtrace(rt_frame *f, const var_na *fmt, va_list ap);
#endif
#ifdef _WIN64
static void *win64_add_function_table(TCCState *s1);
static void win64_del_function_table(void *);
#endif

#အကယ်၍ !defined PAGESIZE
# အကယ်၍ defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# မဟုတ်ပါက
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#အကယ်၍ !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#အကယ်၍ defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

static ကိန်းပြည့် rt_mem(TCCState *s1, ကိန်းပြည့် size)
{
    void *ptr;
    ကိန်းပြည့် ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    void *prw;
    var_na tmpfname[] = "/tmp/.tccrunXXXXXX";
    ကိန်းပြည့် fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(NULL, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((var_na*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    အကယ်၍ (ptr == MAP_FAILED || prw == MAP_FAILED)
	ပြန်ပေး tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (var_na*)prw - (var_na*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#elif CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    အကယ်၍ (!ptr)
        ပြန်ပေး tcc_error_noabort("tccrun: could not allocate memory");
#မဟုတ်ပါက
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    ပြန်ပေး ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI ကိန်းပြည့် tcc_relocate(TCCState *s1)
{
    ကိန်းပြည့် size, ret, ptr_diff;

    အကယ်၍ (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    အကယ်၍ (s1->do_backtrace)
        tcc_add_symbol(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, NULL, 0);
    အကယ်၍ (size < 0)
        ပြန်ပေး -1;
    ptr_diff = rt_mem(s1, size);
    အကယ်၍ (ptr_diff < 0)
        ပြန်ပေး -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    အကယ်၍ (ret == 0)
        st_link(s1);
    ပြန်ပေး ret;
}

ST_FUNC void tcc_run_free(TCCState *s1)
{
    unsigned size;
    void *ptr;
    ကိန်းပြည့် i;

    /* free any loaded DLLs */
    အတွက် ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        အကယ်၍ ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#မဟုတ်ပါက
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    အကယ်၍ (NULL == ptr)
        ပြန်ပေး;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#elif CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#မဟုတ်ပါက
    /* unprotect memory to make it usable for malloc again */
    protect_pages((void*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI ကိန်းပြည့် tcc_run(TCCState *s1, ကိန်းပြည့် argc, var_na **argv)
{
    ကိန်းပြည့် (*prog_main)(ကိန်းပြည့်, var_na **, var_na **), ret;
    const var_na *top_sym;
    jmp_buf main_jb;

#အကယ်၍ defined(__APPLE__)
    extern var_na ***_NSGetEnviron(void);
    var_na **envp = *_NSGetEnviron();
#elif defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    extern var_na **environ;
    var_na **envp = environ;
#မဟုတ်ပါက
    var_na **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    အကယ်၍ ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        ပြန်ပေး 0;

    tcc_add_symbol(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", top_sym = "main";
    အကယ်၍ (s1->elf_entryname)
        s1->run_main = top_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    အကယ်၍ (tcc_relocate(s1) < 0)
        ပြန်ပေး -1;

    prog_main = (void*)get_sym_addr(s1, s1->run_main, 1, 1);
    အကယ်၍ ((addr_t)-1 == (addr_t)prog_main)
        ပြန်ပေး -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    အကယ်၍ (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        ပြန်ပေး -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_symbol(s1, top_sym));
    အကယ်၍ (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } မဟုတ်ပါက အကယ်၍ (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    အကယ်၍ (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    ပြန်ပေး ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
static void cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    ကိန်းပြည့် sym_index, end_sym = s->data_offset / parimaa_na (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    အတွက် (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        const var_na *name = (var_na *)s->link->data + sym->st_name;
        အကယ်၍ (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            continue;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_value, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
static void cleanup_sections(TCCState *s1)
{
    sa_nracanaa { Section **secs; ကိန်းပြည့် nb_secs; } *p = (void*)&s1->sections;
    ကိန်းပြည့် i, f = 2;
    do {
        အတွက် (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            အကယ်၍ (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } မဟုတ်ပါက {
                free_section(s), tcc_free(s), p->secs[i] = NULL;
            }
        }
    } နေစဉ် (++p, f);
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
# မဟုတ်ပါက
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
static ကိန်းပြည့် tcc_relocate_ex(TCCState *s1, void *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    အကယ်၍ (NULL == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, NULL);
#မဟုတ်ပါက
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    အကယ်၍ (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    အကယ်၍ (s1->nb_errors)
        ပြန်ပေး -1;
    အကယ်၍ (copy == 3)
        ပြန်ပေး 0;

    အတွက် (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        အတွက်(i = 1; i < s1->nb_sections; i++) {
            static const var_na shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            အကယ်၍ (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                continue;
            length = s->data_offset;
            အကယ်၍ (copy == 2) {
                အကယ်၍ (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                continue;
            }
            အကယ်၍ (copy) { /* final step: copy section data to memory */
                အကယ်၍ (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (void*)s->sh_addr, length, s->sh_addralign);
                ptr = (void*)s->sh_addr;
                အကယ်၍ (k == 0)
                    ptr = (void*)(s->sh_addr + ptr_diff);
                အကယ်၍ (NULL == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                မဟုတ်ပါက
                    memcpy(ptr, s->data, length);
                continue;
            }

            အကယ်၍ ((s->sh_flags & SHF_TLS) && length)
                ပြန်ပေး tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            အကယ်၍ (++n == 1) {
#အကယ်၍ defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                အကယ်၍ (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                အကယ်၍ (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        အကယ်၍ (copy == 2) { /* set permissions */
            အကယ်၍ (n == 0) /* no data  */
                continue;
#ifdef CONFIG_SELINUX
            အကယ်၍ (k == 0) /* SHF_EXECINSTR has its own mapping */
                continue;
#endif
            f = k;
            အကယ်၍ (f >= CONFIG_RUNMEM_RO) {
                အကယ်၍ (f != 0)
                    continue;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            အကယ်၍ (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (void*)addr, (unsigned)n);
            }
            အကယ်၍ (protect_pages((void*)addr, n, f) < 0)
                ပြန်ပေး tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#မဟုတ်ပါက
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    အကယ်၍ (0 == mem)
        ပြန်ပေး PAGEALIGN(offset);

    အကယ်၍ (++copy == 2) {
        goto redo;
    }
    အကယ်၍ (copy == 3) {
#ifdef _WIN64
        s1->run_function_table = win64_add_function_table(s1);
#endif
        /* remove local symbols and free sections except symtab */
        cleanup_symbols(s1);
        cleanup_sections(s1);
        goto redo;
    }

    /* relocate symbols */
    relocate_syms(s1, s1->symtab, 1);
    အကယ်၍ (s1->nb_errors)
        goto redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#မဟုတ်ပါက
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    goto redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

static ကိန်းပြည့် protect_pages(void *ptr, unsigned long length, ကိန်းပြည့် mode)
{
#ifdef _WIN32
    static const unsigned var_na protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    အကယ်၍ (!VirtualProtect(ptr, length, protect[mode], &old))
        ပြန်ပေး -1;
#မဟုတ်ပါက
    static const unsigned var_na protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    အကယ်၍ (mprotect(ptr, length, protect[mode]))
        ပြန်ပေး -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#အကယ်၍ (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    အကယ်၍ (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#မဟုတ်ပါက
        void __clear_cache(void *beginning, void *end);
        __clear_cache(ptr, (var_na *)ptr + length);
#endif
    }
#endif
    ပြန်ပေး 0;
}

#ifdef _WIN64
static void *win64_add_function_table(TCCState *s1)
{
    void *p = NULL;
    အကယ်၍ (s1->uw_pdata) {
        p = (void*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / parimaa_na (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = NULL;
    }
    ပြန်ပေး p;
}

static void win64_del_function_table(void *p)
{
    အကယ်၍ (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

static void bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    အကယ်၍ (!s1->do_backtrace)
        ပြန်ပေး;
    rc = tcc_get_symbol(s1, "__rt_info");
    အကယ်၍ (!rc)
        ပြန်ပေး;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (var_na *)symtab_section->link->data;
    အကယ်၍ (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    အကယ်၍ (s1->do_bounds_check) {
        void *p;
        အကယ်၍ ((p = tcc_get_symbol(s1, "__bound_init")))
            ((void(*)(void*,ကိန်းပြည့်))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    အကယ်၍ (0 == signal_set)
        set_exception_handler(), signal_set = 1;
#endif
}

static void st_link(TCCState *s1)
{
    rt_wait_sem();
    s1->next = g_s1, g_s1 = s1;
    bt_link(s1);
    rt_post_sem();
}

/* remove 'el' from 'list' */
static void ptr_unlink(void *list, void *e, unsigned next)
{
    void **pp, **nn, *p;
    အတွက် (pp = list; !!(p = *pp); pp = nn) {
        nn = (void*)((var_na*)p + next); /* nn = &p->next; */
        အကယ်၍ (p == e) {
            *pp = *nn;
            bha_nga;
        }
    }
}

static void st_unlink(TCCState *s1)
{
    rt_wait_sem();
#ifdef CONFIG_TCC_BACKTRACE
    ptr_unlink(&g_rc, s1->rc, offsetof(rt_context, next));
#endif
    ptr_unlink(&g_s1, s1, offsetof(TCCState, next));
    rt_post_sem();
}

LIBTCCAPI void *_tcc_setjmp(TCCState *s1, void *p_jmp_buf, void *func, void *p_longjmp)
{
    s1->run_lj = p_longjmp;
    s1->run_jb = p_jmp_buf;
#ifdef CONFIG_TCC_BACKTRACE
    အကယ်၍ (s1->rc)
        s1->rc->top_func = func;
#endif
    ပြန်ပေး p_jmp_buf;
}

LIBTCCAPI void tcc_set_backtrace_func(TCCState *s1, void *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

static TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    ကိန်းပြည့် level;
    addr_t pc;

    s = g_s1;
    အကယ်၍ (NULL == s || NULL == s->next) {
        /* play it safe in the simple case when there is only one state */
        ပြန်ပေး s;
    }
    အတွက် (level = 0; level < 8; ++level) {
        အကယ်၍ (rt_get_caller_pc(&pc, f, level) < 0)
            bha_nga;
        အတွက် (s = g_s1; s; s = s->next) {
            အကယ်၍ (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                ပြန်ပေး s;
        }
    }
    ပြန်ပေး NULL;
}

static void rt_exit(rt_frame *f, ကိန်းပြည့် code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    အကယ်၍ (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        အကယ်၍ (f->fp) { /* called from signal */
            void *p = tcc_get_symbol(s, "__bound_exit");
            အကယ်၍ (p)
                ((void (*)(void))p)();
        }
#endif
        အကယ်၍ (code == 0)
            code = RT_EXIT_ZERO;
        ((void(*)(void*,ကိန်းပြည့်))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#မဟုတ်ပါက // if defined CONFIG_TCC_BACKTRACE_ONLY
static void rt_exit(rt_frame *f, ကိန်းပြည့် code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

static ကိန်းပြည့် rt_vprintf(const var_na *fmt, va_list ap)
{
    ကိန်းပြည့် ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    ပြန်ပေး ret;
}

static ကိန်းပြည့် rt_printf(const var_na *fmt, ...)
{
    va_list ap;
    ကိန်းပြည့် r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    ပြန်ပေး r;
}

static var_na *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    အတွက် (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        ကိန်းပြည့် type = ELFW(ST_TYPE)(esym->st_info);
        အကယ်၍ ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_value
            && wanted_pc < esym->st_value + esym->st_size) {
            *func_addr = esym->st_value;
            ပြန်ပေး rc->elf_str + esym->st_name;
        }
    }
    ပြန်ပေး NULL;
}

typedef sa_nracanaa bt_info
{
    var_na file[100];
    ကိန်းပြည့် line;
    var_na func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
static addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    var_na func_name[128];
    addr_t func_addr, last_pc, pc;
    const var_na *incl_files[INCLUDE_STACK_SIZE];
    ကိန်းပြည့် incl_index, last_incl_index, len, last_line_num, i;
    const var_na *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_line_num = 1;
    last_incl_index = 0;

    အတွက် (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_value;

        switch(sym->n_type) {
        pak_sa N_SLINE:
            အကယ်၍ (func_addr)
                goto rel_pc;
        pak_sa N_SO:
        pak_sa N_SOL:
            goto abs_pc;
        pak_sa N_FUN:
            အကယ်၍ (sym->n_strx == 0) /* end of function */
                goto rel_pc;
        abs_pc:
#အကယ်၍ PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            goto check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            အကယ်၍ (pc >= wanted_pc && wanted_pc >= last_pc)
                goto found;
            bha_nga;
        }

        switch(sym->n_type) {
            /* function start or end */
        pak_sa N_FUN:
            အကယ်၍ (sym->n_strx == 0)
                goto reset_func;
            p = strchr(str, ':');
            အကယ်၍ (0 == p || (len = p - str + 1, len > parimaa_na func_name))
                len = parimaa_na func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            bha_nga;
            /* line number info */
        pak_sa N_SLINE:
            last_pc = pc;
            last_line_num = sym->n_desc;
            last_incl_index = incl_index;
            bha_nga;
            /* include files */
        pak_sa N_BINCL:
            အကယ်၍ (incl_index < INCLUDE_STACK_SIZE)
                incl_files[incl_index++] = str;
            bha_nga;
        pak_sa N_EINCL:
            အကယ်၍ (incl_index > 1)
                incl_index--;
            bha_nga;
            /* start/end of translation unit */
        pak_sa N_SO:
            incl_index = 0;
            အကယ်၍ (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                အကယ်၍ (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            bha_nga;
            /* alternative file name (from #line or #include directives) */
        pak_sa N_SOL:
            အကယ်၍ (incl_index)
                incl_files[incl_index-1] = str;
            bha_nga;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    အကယ်၍ (i > 0) {
        pstrcpy(bi->file, parimaa_na bi->file, incl_files[--i]);
        bi->line = last_line_num;
    }
    pstrcpy(bi->func, parimaa_na bi->func, func_name);
    bi->func_pc = func_addr;
    ပြန်ပေး func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	switch (entry_format[j].form) { \
	pak_sa DW_FORM_data1: (ln) += 1; bha_nga; \
	pak_sa DW_FORM_data2: (ln) += 2; bha_nga; \
	pak_sa DW_FORM_data4: (ln) += 3; bha_nga; \
	pak_sa DW_FORM_data8: (ln) += 8; bha_nga; \
	pak_sa DW_FORM_data16: (ln) += 16; bha_nga; \
	pak_sa DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); bha_nga; \
	default: goto next_line; \
	}

static addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned var_na *ln;
    unsigned var_na *cp;
    unsigned var_na *end;
    unsigned var_na *opcode_length;
    unsigned long long size;
    unsigned ကိန်းပြည့် length;
    unsigned var_na version;
    unsigned ကိန်းပြည့် min_insn_length;
    unsigned ကိန်းပြည့် max_ops_per_insn;
    ကိန်းပြည့် line_base;
    unsigned ကိန်းပြည့် line_range;
    unsigned ကိန်းပြည့် opcode_base;
    unsigned ကိန်းပြည့် opindex;
    unsigned ကိန်းပြည့် col;
    unsigned ကိန်းပြည့် i;
    unsigned ကိန်းပြည့် j;
    unsigned ကိန်းပြည့် len;
    unsigned long long value;
    sa_nracanaa {
	unsigned ကိန်းပြည့် type;
	unsigned ကိန်းပြည့် form;
    } entry_format[256];
    unsigned ကိန်းပြည့် dir_size;
#အကယ်၍ 0
    var_na *dirs[DIR_TABLE_SIZE];
#endif
    unsigned ကိန်းပြည့် filename_size;
    sa_nracanaa /*dwarf_filename_struct*/ {
        unsigned ကိန်းပြည့် dir_entry;
        var_na *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    ကိန်းပြည့် line;
    var_na *filename;
    var_na *function;

    filename = NULL;
    function = NULL;
    func_addr = 0;
    line = 0;

    ln = rc->dwarf_line;
    နေစဉ် (ln < rc->dwarf_line_end) {
	dir_size = 0;
	filename_size = 0;
        last_pc = 0;
        pc = 0;
        func_addr = 0;
        line = 1;
        filename = NULL;
        function = NULL;
	length = 4;
	size = dwarf_read_4(ln, rc->dwarf_line_end);
	အကယ်၍ (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_line_end);
	end = ln + size;
	အကယ်၍ (end < ln || end > rc->dwarf_line_end)
	    bha_nga;
	version = dwarf_read_2(ln, end);
	အကယ်၍ (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	မဟုတ်ပါက
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	အကယ်၍ (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	မဟုတ်ပါက
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	line_base = dwarf_read_1(ln, end);
	line_base |= line_base >= 0x80 ? ~0xff : 0;
	line_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	အကယ်၍ (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    အတွက် (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    အတွက် (i = 0; i < dir_size; i++) {
		အတွက် (j = 0; j < col; j++) {
		    အကယ်၍ (entry_format[j].type == DW_LNCT_path) {
		        အကယ်၍ (entry_format[j].form != DW_FORM_line_strp)
			    goto next_line;
#အကယ်၍ 0
		        value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        အကယ်၍ (i < DIR_TABLE_SIZE)
		            dirs[i] = (var_na *)rc->dwarf_line_str + value;
#မဟုတ်ပါက
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    မဟုတ်ပါက 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    အတွက် (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    အတွက် (i = 0; i < filename_size; i++)
		အတွက် (j = 0; j < col; j++) {
		    အကယ်၍ (entry_format[j].type == DW_LNCT_path) {
			အကယ်၍ (entry_format[j].form != DW_FORM_line_strp)
			    goto next_line;
			value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        အကယ်၍ (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(var_na *)rc->dwarf_line_str + value;
	            }
		    မဟုတ်ပါက အကယ်၍ (entry_format[j].type == DW_LNCT_directory_index) {
			switch (entry_format[j].form) {
			pak_sa DW_FORM_data1: value = dwarf_read_1(ln, end); bha_nga;
			pak_sa DW_FORM_data2: value = dwarf_read_2(ln, end); bha_nga;
			pak_sa DW_FORM_data4: value = dwarf_read_4(ln, end); bha_nga;
			pak_sa DW_FORM_udata: value = dwarf_read_uleb128(&ln, end); bha_nga;
			default: goto next_line;
			}
		        အကယ်၍ (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = value;
		    }
		    မဟုတ်ပါက 
			dwarf_ignore_type(ln, end);
	    }
	}
	မဟုတ်ပါက {
	    နေစဉ် ((dwarf_read_1(ln, end))) {
#အကယ်၍ 0
		အကယ်၍ (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (var_na *)ln - 1;
#endif
		နေစဉ် (dwarf_read_1(ln, end)) {}
	    }
	    နေစဉ် ((dwarf_read_1(ln, end))) {
		အကယ်၍ (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (var_na *)ln - 1;
		    နေစဉ် (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		မဟုတ်ပါက {
		    နေစဉ် (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	အကယ်၍ (filename_size >= 1)
	    filename = filename_table[0].name;
	နေစဉ် (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    အကယ်၍ (i >= opcode_base) {
	        အကယ်၍ (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / line_range) * min_insn_length;
		မဟုတ်ပါက {
		    pc += (opindex + (i - opcode_base) / line_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / line_range) %
			       max_ops_per_insn;
		}
		i = (ကိန်းပြည့်)((i - opcode_base) % line_range) + line_base;
check_pc:
		အကယ်၍ (pc >= wanted_pc && wanted_pc >= last_pc)
		    goto found;
		line += i;
	    }
	    မဟုတ်ပါက {
	        switch (i) {
	        pak_sa 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    အကယ်၍ (len == 0)
		        goto next_line;
		    switch (dwarf_read_1(cp, end)) {
		    pak_sa DW_LNE_end_sequence:
		        bha_nga;
		    pak_sa DW_LNE_set_address:
#အကယ်၍ PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#မဟုတ်ပါက
		        pc = dwarf_read_8(cp, end);
#endif
#အကယ်၍ defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        bha_nga;
		    pak_sa DW_LNE_define_file: /* deprecated */
		        အကယ်၍ (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (var_na *)ln - 1;
		            နေစဉ် (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        မဟုတ်ပါက {
		            နေစဉ် (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        bha_nga;
		    pak_sa DW_LNE_hi_user - 1:
		        function = (var_na *)cp;
		        func_addr = pc;
		        bha_nga;
		    default:
		        bha_nga;
		    }
		    bha_nga;
	        pak_sa DW_LNS_advance_pc:
		    အကယ်၍ (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    မဟုတ်ပါက {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    goto check_pc;
	        pak_sa DW_LNS_advance_line:
		    line += dwarf_read_sleb128(&ln, end);
		    bha_nga;
	        pak_sa DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    အကယ်၍ (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    bha_nga;
	        pak_sa DW_LNS_const_add_pc:
		    အကယ်၍ (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / line_range) * min_insn_length;
		    မဟုတ်ပါက {
		        unsigned ကိန်းပြည့် off = (255 - opcode_base) / line_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    goto check_pc;
	        pak_sa DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    goto check_pc;
	        default:
		    အတွက် (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    bha_nga;
		}
	    }
	}
next_line:
	ln = end;
    }
    filename = function = NULL, func_addr = 0;
found:
    အကယ်၍ (filename)
        pstrcpy(bi->file, parimaa_na bi->file, filename), bi->line = line;
    အကယ်၍ (function)
        pstrcpy(bi->func, parimaa_na bi->func, function);
    bi->func_pc = func_addr;
    ပြန်ပေး (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
static
#endif
ကိန်းပြည့် _tcc_backtrace(rt_frame *f, const var_na *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    var_na skip[40], msg[200];
    ကိန်းပြည့် i, level, ret, n, one;
    const var_na *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    အကယ်၍ (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    အကယ်၍ (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(msg, parimaa_na msg, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    အကယ်၍ (rc) {
        အကယ်၍ (rc->dwarf)
            getinfo = rt_printline_dwarf;
        အကယ်၍ (rc->num_callers)
            n = rc->num_callers;
    }

    အတွက် (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        အကယ်၍ (ret == -1)
            bha_nga;
        memset(&bi, 0, parimaa_na bi);
        အတွက် (rc2 = rc; rc2; rc2 = rc2->next) {
            အကယ်၍ (getinfo(rc2, pc, &bi))
                bha_nga;
            /* we try symtab symbols (no line number info) */
            အကယ်၍ (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, parimaa_na bi.func, a);
                bha_nga;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        အကယ်၍ (skip[0] && strstr(bi.file, skip))
            continue;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            အကယ်၍ (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (void*)pc,
                    bi.file[0] ? bi.file : NULL,
                    bi.line,
                    bi.func[0] ? bi.func : NULL,
                    level == 0 ? msg : NULL
                    );
                အကယ်၍ (ret == 0)
                    bha_nga;
                goto check_break;
            }
        }
#endif
        အကယ်၍ (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.line);
        } မဟုတ်ပါက {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        အကယ်၍ (level == 0) {
            rt_printf(": %s", msg);
            အကယ်၍ (one)
                bha_nga;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        အကယ်၍ (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->top_func)
            bha_nga;
        ++level;
    }
    rt_post_sem();
    ပြန်ပေး 0;
}

/* emit a run time error at position 'pc' */
static ကိန်းပြည့် rt_error(rt_frame *f, const var_na *fmt, ...)
{
    va_list ap; var_na msg[200]; ကိန်းပြည့် ret;
    va_start(ap, fmt);
    snprintf(msg, parimaa_na msg, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, msg, ap);
    va_end(ap);
    ပြန်ပေး ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#မဟုတ်ပါက
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
static void rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#အကယ်၍ defined _WIN64 && defined __aarch64__
    rc->ip = uc->Pc;      /* Program Counter */
    rc->fp = uc->Fp;      /* Frame Pointer (X29) */
    rc->sp = uc->Sp;      /* Stack Pointer (X30 is LR, but SP is separate) */
#elif defined _WIN64
    rc->ip = uc->Rip;
    rc->fp = uc->Rbp;
    rc->sp = uc->Rsp;
#elif defined _WIN32
    rc->ip = uc->Eip;
    rc->fp = uc->Ebp;
    rc->sp = uc->Esp;
#elif defined __i386__
# အကယ်၍ defined(__APPLE__)
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
# မဟုတ်ပါက
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#elif defined(__x86_64__)
# အကယ်၍ defined(__APPLE__)
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
# မဟုတ်ပါက
    rc->ip = uc->uc_mcontext.gregs[REG_RIP];
    rc->fp = uc->uc_mcontext.gregs[REG_RBP];
# endif
#elif defined(__arm__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#elif defined(__arm__) && defined(__OpenBSD__)
    rc->ip = uc->sc_pc;
    rc->fp = uc->sc_r11;
#elif defined(__arm__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#elif defined(__arm__)
    rc->ip = uc->uc_mcontext.arm_pc;
    rc->fp = uc->uc_mcontext.arm_fp;
#elif defined(__aarch64__) && defined(__APPLE__)
    // see:
    // /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/usr/include/mach/arm/_structs.h
    rc->ip = uc->uc_mcontext->__ss.__pc;
    rc->fp = uc->uc_mcontext->__ss.__fp;
#elif defined(__aarch64__) && defined(__FreeBSD__)
    rc->ip = uc->uc_mcontext.mc_gpregs.gp_elr; /* aka REG_PC */
    rc->fp = uc->uc_mcontext.mc_gpregs.gp_x[29];
#elif defined(__aarch64__) && defined(__NetBSD__)
    rc->ip = uc->uc_mcontext.__gregs[_REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[_REG_FP];
#elif defined(__aarch64__) && defined(__OpenBSD__)
    rc->ip = uc->sc_elr;
    rc->fp = uc->sc_x[29];
#elif defined(__aarch64__)
    rc->ip = uc->uc_mcontext.pc;
    rc->fp = uc->uc_mcontext.regs[29];
#elif defined(__riscv) && defined(__OpenBSD__)
    rc->ip = uc->sc_sepc;
    rc->fp = uc->sc_s[0];
#elif defined(__riscv)
    rc->ip = uc->uc_mcontext.__gregs[REG_PC];
    rc->fp = uc->uc_mcontext.__gregs[REG_S0];
#endif
}

/* ------------------------------------------------------------- */
#ifndef _WIN32
/* signal handler for fatal errors */
static void sig_error(ကိန်းပြည့် signum, siginfo_t *siginf, void *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    switch(signum) {
    pak_sa SIGFPE:
        switch(siginf->si_code) {
        pak_sa FPE_INTDIV:
        pak_sa FPE_FLTDIV:
            rt_error(&f, "division by zero");
            bha_nga;
        default:
            rt_error(&f, "floating point exception");
            bha_nga;
        }
        bha_nga;
    pak_sa SIGBUS:
    pak_sa SIGSEGV:
        rt_error(&f, "invalid memory access");
        bha_nga;
    pak_sa SIGILL:
        rt_error(&f, "illegal instruction");
        bha_nga;
    pak_sa SIGABRT:
        rt_error(&f, "abort() called");
        bha_nga;
    default:
        rt_error(&f, "caught signal %d", signum);
        bha_nga;
    }
    {
        sigset_t s;
        sigemptyset(&s);
        sigaddset(&s, signum);
        sigprocmask(SIG_UNBLOCK, &s, NULL);
    }
    rt_exit(&f, 255);
}

#ifndef SA_SIGINFO
# define SA_SIGINFO 0x00000004u
#endif

/* Generate a stack backtrace when a CPU exception occurs. */
static void set_exception_handler(void)
{
    sa_nracanaa sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#အကယ်၍ 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, NULL);
    sigaction(SIGILL, &sigact, NULL);
    sigaction(SIGSEGV, &sigact, NULL);
    sigaction(SIGBUS, &sigact, NULL);
    sigaction(SIGABRT, &sigact, NULL);
#အကယ်၍ 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        static unsigned var_na stack[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = stack;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, NULL);
    }
#endif
}

#မဟုတ်ပါက /* WIN32 */

/* signal handler for fatal errors */
static long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    switch (code = ex_info->ExceptionRecord->ExceptionCode) {
    pak_sa EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        bha_nga;
    pak_sa EXCEPTION_STACK_OVERFLOW:
        rt_error(&f, "stack overflow");
        bha_nga;
    pak_sa EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        bha_nga;
    pak_sa EXCEPTION_BREAKPOINT:
    pak_sa EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        ပြန်ပေး EXCEPTION_CONTINUE_SEARCH;
    default:
        rt_error(&f, "caught exception %08x", code);
        bha_nga;
    }
    rt_exit(&f, 255);
    ပြန်ပေး EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
static void set_exception_handler(void)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#မဟုတ်ပါက
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#အကယ်၍ defined(__i386__) || defined(__x86_64__)
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ကိန်းပြည့် level)
{
    အကယ်၍ (level == 0) {
        *paddr = rc->ip;
    } မဟုတ်ပါက {
        addr_t fp = rc->fp;
        နေစဉ် (1) {
            အကယ်၍ (fp < 0x1000)
                ပြန်ပေး -1;
            အကယ်၍ (0 == --level)
                bha_nga;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ပြန်ပေး 0;
}

/* XXX: only supports linux/bsd */
#elif defined(__arm__) && !defined(_WIN32)
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ကိန်းပြည့် level)
{
    အကယ်၍ (level == 0) {
        *paddr = rc->ip;
    } မဟုတ်ပါက {
        addr_t fp = rc->fp;
        နေစဉ် (1) {
            အကယ်၍ (fp < 0x1000)
                ပြန်ပေး -1;
            အကယ်၍ (0 == --level)
                bha_nga;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    ပြန်ပေး 0;
}

#elif defined(__aarch64__)
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ကိန်းပြည့် level)
{
    အကယ်၍ (level == 0) {
        *paddr = rc->ip;
    } မဟုတ်ပါက {
        addr_t fp = rc->fp;
        နေစဉ် (1) {
            အကယ်၍ (fp < 0x1000)
                ပြန်ပေး -1;
            အကယ်၍ (0 == --level)
                bha_nga;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    ပြန်ပေး 0;
}

#elif defined(__riscv)
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ကိန်းပြည့် level)
{
    အကယ်၍ (level == 0) {
        *paddr = rc->ip;
    } မဟုတ်ပါက {
        addr_t fp = rc->fp;
        နေစဉ် (1) {
            အကယ်၍ (fp < 0x1000)
                ပြန်ပေး -1;
            အကယ်၍ (0 == --level)
                bha_nga;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    ပြန်ပေး 0;
}

#မဟုတ်ပါက
#warning add arch specific rt_get_caller_pc()
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *rc, ကိန်းပြည့် level)
{
    ပြန်ပေး -1;
}

#endif
#မဟုတ်ပါက // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
static ကိန်းပြည့် rt_get_caller_pc(addr_t *paddr, rt_frame *f, ကိန်းပြည့် level)
{
    အကယ်၍ (level)
        ပြန်ပေး -1;
    *paddr = f->ip;
    ပြန်ပေး 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC void *dlopen(const var_na *filename, ကိန်းပြည့် flag)
{
    ပြန်ပေး NULL;
}

ST_FUNC void dlclose(void *p)
{
}

ST_FUNC const var_na *dlerror(void)
{
    ပြန်ပေး "error";
}

typedef sa_nracanaa TCCSyms {
    var_na *str;
    void *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
static TCCSyms tcc_syms[] = {
#အကယ်၍ !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { NULL, NULL },
};

ST_FUNC void *dlsym(void *handle, const var_na *symbol)
{
    TCCSyms *p;
    p = tcc_syms;
    နေစဉ် (p->str != NULL) {
        အကယ်၍ (!strcmp(p->str, symbol))
            ပြန်ပေး p->ptr;
        p++;
    }
    ပြန်ပေး NULL;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
