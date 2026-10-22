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
typedef struct rt_context
{
    /* tccelf.c:tcc_add_btstub() wants these in that order: */
    union {
	struct {
	    Stab_Sym *stab_sym;
	    Stab_Sym *stab_sym_end;
	    char *stab_str;
	};
	struct {
	    unsigned char *dwarf_line;
	    unsigned char *dwarf_line_end;
	    unsigned char *dwarf_line_str;
	};
    };
    ElfW(Sym) *esym_start;
    ElfW(Sym) *esym_end;
    char *elf_str;
    // 6 * PTR_SIZE
    addr_t prog_base;
    void *bounds_start;
    void *top_func;
    struct rt_context *next;
    // 10 * PTR_SIZE
    số_nguyên num_callers;
    số_nguyên dwarf;
} rt_context;

/* linked list of rt_contexts */
static rt_context *g_rc;
static số_nguyên signal_set;
static void set_exception_handler(void);
#endif /* def CONFIG_TCC_BACKTRACE */

typedef struct rt_frame {
    addr_t ip, fp, sp;
} rt_frame;

static TCCState *g_s1;
/* semaphore to protect it */
TCC_SEM(static rt_sem);
static void rt_wait_sem(void) { WAIT_SEM(&rt_sem); }
static void rt_post_sem(void) { POST_SEM(&rt_sem); }
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *f, số_nguyên level);
static void rt_exit(rt_frame *f, số_nguyên code);

/* ------------------------------------------------------------- */
/* defined when included from lib/bt-exe.c */
#ifndef CONFIG_TCC_BACKTRACE_ONLY

#ifndef _WIN32
# include <sys/mman.h>
#endif

static số_nguyên protect_pages(void *ptr, unsigned long length, số_nguyên mode);
static số_nguyên tcc_relocate_ex(TCCState *s1, void *ptr, unsigned ptr_diff);
static void st_link(TCCState *s1);
static void st_unlink(TCCState *s1);
#ifdef CONFIG_TCC_BACKTRACE
static số_nguyên _tcc_backtrace(rt_frame *f, const char *fmt, va_list ap);
#endif
#ifdef _WIN64
static void *win64_add_function_table(TCCState *s1);
static void win64_del_function_table(void *);
#endif

#nếu !defined PAGESIZE
# nếu defined _SC_PAGESIZE
#  define PAGESIZE sysconf(_SC_PAGESIZE)
# elif defined __APPLE__
#  include <libkern/OSCacheControl.h>
#  define PAGESIZE getpagesize()
# không_thì
#  define PAGESIZE 4096
# endif
#endif

#define PAGEALIGN(n) ((addr_t)n + (-(addr_t)n & (PAGESIZE-1)))

#nếu !_WIN32 && !__APPLE__
//#define CONFIG_SELINUX 1
#endif

/* use VirtualAlloc() instead of tcc_malloc() */
#nếu defined _WIN32 && !defined CONFIG_RUNMEM_VIRTUALALLOC
# define CONFIG_RUNMEM_VIRTUALALLOC 1
#endif

static số_nguyên rt_mem(TCCState *s1, số_nguyên size)
{
    void *ptr;
    số_nguyên ptr_diff = 0;
#ifdef CONFIG_SELINUX
    /* Using mmap instead of malloc */
    void *prw;
    char tmpfname[] = "/tmp/.tccrunXXXXXX";
    số_nguyên fd = mkstemp(tmpfname);
    unlink(tmpfname);
    ftruncate(fd, size);

    ptr = mmap(NULL, size * 2, PROT_READ|PROT_EXEC, MAP_SHARED, fd, 0);
    /* mmap RW memory at fixed distance */
    prw = mmap((char*)ptr + size, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_FIXED, fd, 0);
    close(fd);
    nếu (ptr == MAP_FAILED || prw == MAP_FAILED)
	trả_về tcc_error_noabort("tccrun: could not map memory");
    ptr_diff = (char*)prw - (char*)ptr; /* = size; */
    //printf("map %p %p %p\n", ptr, prw, (void*)ptr_diff);
    size *= 2;
#elif CONFIG_RUNMEM_VIRTUALALLOC
    /* always page-aligned */
    ptr = VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    nếu (!ptr)
        trả_về tcc_error_noabort("tccrun: could not allocate memory");
#không_thì
    ptr = tcc_malloc(size += PAGESIZE); /* one extra page to align malloc memory */
#endif
    s1->run_ptr = ptr;
    s1->run_size = size;
    trả_về ptr_diff;
}

/* ------------------------------------------------------------- */
/* Do all relocations (needed before using tcc_get_symbol())
   Returns -1 on error. */

LIBTCCAPI số_nguyên tcc_relocate(TCCState *s1)
{
    số_nguyên size, ret, ptr_diff;

    nếu (s1->run_ptr)
        exit(tcc_error_noabort("'tcc_relocate()' twice is no longer supported"));
#ifdef CONFIG_TCC_BACKTRACE
    nếu (s1->do_backtrace)
        tcc_add_symbol(s1, "_tcc_backtrace", _tcc_backtrace); /* for bt-log.c */
#endif
    size = tcc_relocate_ex(s1, NULL, 0);
    nếu (size < 0)
        trả_về -1;
    ptr_diff = rt_mem(s1, size);
    nếu (ptr_diff < 0)
        trả_về -1;
    ret = tcc_relocate_ex(s1, s1->run_ptr, ptr_diff);
    nếu (ret == 0)
        st_link(s1);
    trả_về ret;
}

ST_FUNC void tcc_run_free(TCCState *s1)
{
    unsigned size;
    void *ptr;
    số_nguyên i;

    /* free any loaded DLLs */
    cho ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        nếu ( ref->handle )
#ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
#không_thì
            dlclose(ref->handle);
#endif
    }
    /* unmap or unprotect and free memory */
    ptr = s1->run_ptr;
    nếu (NULL == ptr)
        trả_về;
    st_unlink(s1);
#ifdef _WIN64
    win64_del_function_table(s1->run_function_table);
#endif
    size = s1->run_size;
#ifdef CONFIG_SELINUX
    munmap(ptr, size);
#elif CONFIG_RUNMEM_VIRTUALALLOC
    VirtualFree(ptr, size, MEM_RELEASE);
#không_thì
    /* unprotect memory to make it usable for malloc again */
    protect_pages((void*)PAGEALIGN(ptr), size - PAGESIZE, 2 /*rw*/);
    tcc_free(ptr);
#endif
}

#define RT_EXIT_ZERO 0xE0E00E0E /* passed from longjmp instead of '0' */

/* launch the compiled program with the given arguments */
LIBTCCAPI số_nguyên tcc_run(TCCState *s1, số_nguyên argc, char **argv)
{
    số_nguyên (*prog_main)(số_nguyên, char **, char **), ret;
    const char *top_sym;
    jmp_buf main_jb;

#nếu defined(__APPLE__)
    extern char ***_NSGetEnviron(void);
    char **envp = *_NSGetEnviron();
#elif defined(__OpenBSD__) || defined(__NetBSD__)  || defined(__FreeBSD__)
    extern char **environ;
    char **envp = environ;
#không_thì
    char **envp = environ;
#endif

    /* tcc -dt -run ... nothing to do if no main() */
    nếu ((s1->dflag & 16) && (addr_t)-1 == get_sym_addr(s1, "main", 0, 1))
        trả_về 0;

    tcc_add_symbol(s1, "__rt_exit", rt_exit);
    s1->run_main = "_runmain", top_sym = "main";
    nếu (s1->elf_entryname)
        s1->run_main = top_sym = s1->elf_entryname;
    tcc_add_support(s1, "runmain.o");

    nếu (tcc_relocate(s1) < 0)
        trả_về -1;

    prog_main = (void*)get_sym_addr(s1, s1->run_main, 1, 1);
    nếu ((addr_t)-1 == (addr_t)prog_main)
        trả_về -1;

    /* custom stdin for run_main, mainly if stdin is/was an input file.
     * fileno(stdin) should remain 0, as posix mandates to use the smallest
     * free fd, which is 0 after the initial fclose in freopen. windows too.
     * to set stdin to the tty, use /dev/tty (posix) or con (windows).
     */
    nếu (s1->run_stdin && !freopen(s1->run_stdin, "r", stdin)) {
        tcc_error_noabort("failed to reopen stdin from '%s'", s1->run_stdin);
        trả_về -1;
    }

    errno = 0; /* clean errno value */
    fflush(stdout);
    fflush(stderr);

    ret = tcc_setjmp(s1, main_jb, tcc_get_symbol(s1, top_sym));
    nếu (0 == ret) {
        ret = prog_main(argc, argv, envp);
    } không_thì nếu (RT_EXIT_ZERO == ret) {
        ret = 0;
    }

    nếu (s1->dflag & 16 && ret) /* tcc -dt -run ... */
        fprintf(s1->ppfp, "[returns %d]\n", ret), fflush(s1->ppfp);
    trả_về ret;
}

/* ------------------------------------------------------------- */
/* remove all STB_LOCAL symbols */
static void cleanup_symbols(TCCState *s1)
{
    Section *s = s1->symtab;
    số_nguyên sym_index, end_sym = s->data_offset / sizeof (ElfSym);
    /* reset symtab */
    s->data_offset = s->link->data_offset = s->hash->data_offset = 0;
    init_symtab(s);
    /* add global symbols again */
    cho (sym_index = 1; sym_index < end_sym; ++sym_index) {
        ElfW(Sym) *sym = &((ElfW(Sym) *)s->data)[sym_index];
        const char *name = (char *)s->link->data + sym->st_name;
        nếu (ELFW(ST_BIND)(sym->st_info) == STB_LOCAL)
            continue;
        //printf("sym %s\n", name);
        put_elf_sym(s, sym->st_value, sym->st_size, sym->st_info, sym->st_other, sym->st_shndx, name);
    }
}

/* free all sections except symbols */
static void cleanup_sections(TCCState *s1)
{
    struct { Section **secs; số_nguyên nb_secs; } *p = (void*)&s1->sections;
    số_nguyên i, f = 2;
    do {
        cho (i = --f; i < p->nb_secs; i++) {
            Section *s = p->secs[i];
            nếu (s == s1->symtab || s == s1->symtab->link || s == s1->symtab->hash) {
                s->data = tcc_realloc(s->data, s->data_allocated = s->data_offset);
            } không_thì {
                free_section(s), tcc_free(s), p->secs[i] = NULL;
            }
        }
    } trong_khi (++p, f);
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
# không_thì
#   define CONFIG_RUNMEM_RO 0
#  endif
#endif

/* relocate code. Return -1 on error, required size if ptr is NULL,
   otherwise copy code into buffer passed by the caller */
static số_nguyên tcc_relocate_ex(TCCState *s1, void *ptr, unsigned ptr_diff)
{
    Section *s;
    unsigned offset, length, align, i, k, f;
    unsigned n, copy;
    addr_t mem, addr;

    nếu (NULL == ptr) {
        s1->nb_errors = 0;
#ifdef TCC_TARGET_PE
        pe_output_file(s1, NULL);
#không_thì
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        build_got_entries(s1, 0);
#endif
    }

    offset = copy = 0;
    mem = (addr_t)ptr;
redo:
    nếu (s1->verbose == 2 && copy)
        printf(&"-----------------------------------------------------\n"[PTR_SIZE*2 - 8]);
    nếu (s1->nb_errors)
        trả_về -1;
    nếu (copy == 3)
        trả_về 0;

    cho (k = 0; k < 3; ++k) { /* 0:rx, 1:ro, 2:rw sections */
        n = 0; addr = 0;
        cho(i = 1; i < s1->nb_sections; i++) {
            static const char shf[] = {
                SHF_ALLOC|SHF_EXECINSTR, SHF_ALLOC, SHF_ALLOC|SHF_WRITE
                };
            s = s1->sections[i];
            nếu (shf[k] != (s->sh_flags & (SHF_ALLOC|SHF_WRITE|SHF_EXECINSTR)))
                continue;
            length = s->data_offset;
            nếu (copy == 2) {
                nếu (addr == 0)
                    addr = s->sh_addr;
                n = (s->sh_addr - addr) + length;
                continue;
            }
            nếu (copy) { /* final step: copy section data to memory */
                nếu (s1->verbose == 2)
                    printf("%d: %-16s %p  len %05x  align %04x\n",
                        k, s->name, (void*)s->sh_addr, length, s->sh_addralign);
                ptr = (void*)s->sh_addr;
                nếu (k == 0)
                    ptr = (void*)(s->sh_addr + ptr_diff);
                nếu (NULL == s->data || s->sh_type == SHT_NOBITS)
                    memset(ptr, 0, length);
                không_thì
                    memcpy(ptr, s->data, length);
                continue;
            }

            nếu ((s->sh_flags & SHF_TLS) && length)
                trả_về tcc_error_noabort("thread-local storage not supported with -run");

            align = s->sh_addralign;
            nếu (++n == 1) {
#nếu defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64
                /* To avoid that x86 processors would reload cached instructions
                   each time when data is written in the near, we need to make
                   sure that code and data do not share the same 64 byte unit */
                nếu (align < 64)
                    align = 64;
#endif
                /* start new page for different permissions */
                nếu (k <= CONFIG_RUNMEM_RO)
                    align = PAGESIZE;
            }
            s->sh_addralign = align;
            addr = k ? mem + ptr_diff : mem;
            offset += -(addr + offset) & (align - 1);
            s->sh_addr = mem ? addr + offset : 0;
            offset += length;
        }
        nếu (copy == 2) { /* set permissions */
            nếu (n == 0) /* no data  */
                continue;
#ifdef CONFIG_SELINUX
            nếu (k == 0) /* SHF_EXECINSTR has its own mapping */
                continue;
#endif
            f = k;
            nếu (f >= CONFIG_RUNMEM_RO) {
                nếu (f != 0)
                    continue;
                f = 3; /* change only SHF_EXECINSTR to rwx */
            }
            n = PAGEALIGN(n);
            nếu (s1->verbose == 2) {
                printf("protect         %3s %p  len %05x\n",
                    &"rx\0ro\0rw\0rwx"[f*3], (void*)addr, (unsigned)n);
            }
            nếu (protect_pages((void*)addr, n, f) < 0)
                trả_về tcc_error_noabort(
#ifdef _WIN32
                    "VirtualProtect failed");
#không_thì
                    "mprotect failed (did you mean to configure --with-selinux?)");
#endif
        }
    }

    nếu (0 == mem)
        trả_về PAGEALIGN(offset);

    nếu (++copy == 2) {
        goto redo;
    }
    nếu (copy == 3) {
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
    nếu (s1->nb_errors)
        goto redo;
    /* relocate sections */
#ifdef TCC_TARGET_PE
    s1->pe_imagebase = mem;
#không_thì
    relocate_plt(s1);
#endif
    relocate_sections(s1);
    goto redo;
}

/* ------------------------------------------------------------- */
/* allow to run code in memory */

static số_nguyên protect_pages(void *ptr, unsigned long length, số_nguyên mode)
{
#ifdef _WIN32
    static const unsigned char protect[] = {
        PAGE_EXECUTE_READ,
        PAGE_READONLY,
        PAGE_READWRITE,
        PAGE_EXECUTE_READWRITE
        };
    DWORD old;
    nếu (!VirtualProtect(ptr, length, protect[mode], &old))
        trả_về -1;
#không_thì
    static const unsigned char protect[] = {
        PROT_READ | PROT_EXEC,
        PROT_READ,
        PROT_READ | PROT_WRITE,
        PROT_READ | PROT_WRITE | PROT_EXEC
        };
    nếu (mprotect(ptr, length, protect[mode]))
        trả_về -1;
#endif
/* XXX: BSD sometimes dump core with bad system call */
#nếu (defined TCC_TARGET_ARM && !TARGETOS_BSD) \
    || defined TCC_TARGET_ARM64 || defined TCC_TARGET_RISCV64
    nếu (mode == 0 || mode == 3) {
#ifdef _WIN32
        FlushInstructionCache(GetCurrentProcess(), ptr, length);
#không_thì
        void __clear_cache(void *beginning, void *end);
        __clear_cache(ptr, (char *)ptr + length);
#endif
    }
#endif
    trả_về 0;
}

#ifdef _WIN64
static void *win64_add_function_table(TCCState *s1)
{
    void *p = NULL;
    nếu (s1->uw_pdata) {
        p = (void*)s1->uw_pdata->sh_addr;
        RtlAddFunctionTable(
            (RUNTIME_FUNCTION*)p,
            s1->uw_pdata->data_offset / sizeof (RUNTIME_FUNCTION),
            s1->pe_imagebase
            );
        s1->uw_pdata = NULL;
    }
    trả_về p;
}

static void win64_del_function_table(void *p)
{
    nếu (p) {
        RtlDeleteFunctionTable((RUNTIME_FUNCTION*)p);
    }
}
#endif

static void bt_link(TCCState *s1)
{
#ifdef CONFIG_TCC_BACKTRACE
    rt_context *rc;
    nếu (!s1->do_backtrace)
        trả_về;
    rc = tcc_get_symbol(s1, "__rt_info");
    nếu (!rc)
        trả_về;
    rc->esym_start = (ElfW(Sym) *)(symtab_section->data);
    rc->esym_end = (ElfW(Sym) *)(symtab_section->data + symtab_section->data_offset);
    rc->elf_str = (char *)symtab_section->link->data;
    nếu (PTR_SIZE == 8 && !s1->dwarf)
        rc->prog_base &= 0xffffffff00000000ULL;
#ifdef CONFIG_TCC_BCHECK
    nếu (s1->do_bounds_check) {
        void *p;
        nếu ((p = tcc_get_symbol(s1, "__bound_init")))
            ((void(*)(void*,số_nguyên))p)(rc->bounds_start, 1);
    }
#endif
    rc->next = g_rc, g_rc = rc, s1->rc = rc;
    nếu (0 == signal_set)
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
    cho (pp = list; !!(p = *pp); pp = nn) {
        nn = (void*)((char*)p + next); /* nn = &p->next; */
        nếu (p == e) {
            *pp = *nn;
            break;
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
    nếu (s1->rc)
        s1->rc->top_func = func;
#endif
    trả_về p_jmp_buf;
}

LIBTCCAPI void tcc_set_backtrace_func(TCCState *s1, void *data, TCCBtFunc *func)
{
    s1->bt_func = func;
    s1->bt_data = data;
}

static TCCState *rt_find_state(rt_frame *f)
{
    TCCState *s;
    số_nguyên level;
    addr_t pc;

    s = g_s1;
    nếu (NULL == s || NULL == s->next) {
        /* play it safe in the simple case when there is only one state */
        trả_về s;
    }
    cho (level = 0; level < 8; ++level) {
        nếu (rt_get_caller_pc(&pc, f, level) < 0)
            break;
        cho (s = g_s1; s; s = s->next) {
            nếu (pc >= (addr_t)s->run_ptr
             && pc  < (addr_t)s->run_ptr + s->run_size)
                trả_về s;
        }
    }
    trả_về NULL;
}

static void rt_exit(rt_frame *f, số_nguyên code)
{
    TCCState *s;
    rt_wait_sem();
    s = rt_find_state(f);
    rt_post_sem();
    nếu (s && s->run_lj) {
#ifdef CONFIG_TCC_BCHECK
        nếu (f->fp) { /* called from signal */
            void *p = tcc_get_symbol(s, "__bound_exit");
            nếu (p)
                ((void (*)(void))p)();
        }
#endif
        nếu (code == 0)
            code = RT_EXIT_ZERO;
        ((void(*)(void*,số_nguyên))s->run_lj)(s->run_jb, code);
    }
    exit(code);
}

/* ------------------------------------------------------------- */
#không_thì // if defined CONFIG_TCC_BACKTRACE_ONLY
static void rt_exit(rt_frame *f, số_nguyên code)
{
    exit(code);
}
#endif //ndef CONFIG_TCC_BACKTRACE_ONLY
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_BACKTRACE

static số_nguyên rt_vprintf(const char *fmt, va_list ap)
{
    số_nguyên ret = vfprintf(stderr, fmt, ap);
    fflush(stderr);
    trả_về ret;
}

static số_nguyên rt_printf(const char *fmt, ...)
{
    va_list ap;
    số_nguyên r;
    va_start(ap, fmt);
    r = rt_vprintf(fmt, ap);
    va_end(ap);
    trả_về r;
}

static char *rt_elfsym(rt_context *rc, addr_t wanted_pc, addr_t *func_addr)
{
    ElfW(Sym) *esym;
    cho (esym = rc->esym_start + 1; esym < rc->esym_end; ++esym) {
        số_nguyên type = ELFW(ST_TYPE)(esym->st_info);
        nếu ((type == STT_FUNC || type == STT_GNU_IFUNC)
            && wanted_pc >= esym->st_value
            && wanted_pc < esym->st_value + esym->st_size) {
            *func_addr = esym->st_value;
            trả_về rc->elf_str + esym->st_name;
        }
    }
    trả_về NULL;
}

typedef struct bt_info
{
    char file[100];
    số_nguyên line;
    char func[100];
    addr_t func_pc;
} bt_info;

/* print the position in the source file of PC value 'pc' by reading
   the stabs debug information */
static addr_t rt_printline (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    char func_name[128];
    addr_t func_addr, last_pc, pc;
    const char *incl_files[INCLUDE_STACK_SIZE];
    số_nguyên incl_index, last_incl_index, len, last_line_num, i;
    const char *str, *p;
    Stab_Sym *sym;

    func_name[0] = '\0';
    func_addr = 0;
    incl_index = 0;
    last_pc = (addr_t)-1;
    last_line_num = 1;
    last_incl_index = 0;

    cho (sym = rc->stab_sym + 1; sym < rc->stab_sym_end; ++sym) {
        str = rc->stab_str + sym->n_strx;
        pc = sym->n_value;

        switch(sym->n_type) {
        case N_SLINE:
            nếu (func_addr)
                goto rel_pc;
        case N_SO:
        case N_SOL:
            goto abs_pc;
        case N_FUN:
            nếu (sym->n_strx == 0) /* end of function */
                goto rel_pc;
        abs_pc:
#nếu PTR_SIZE == 8
            /* Stab_Sym.n_value is only 32bits */
            pc += rc->prog_base;
#endif
            goto check_pc;
        rel_pc:
            pc += func_addr;
        check_pc:
            nếu (pc >= wanted_pc && wanted_pc >= last_pc)
                goto found;
            break;
        }

        switch(sym->n_type) {
            /* function start or end */
        case N_FUN:
            nếu (sym->n_strx == 0)
                goto reset_func;
            p = strchr(str, ':');
            nếu (0 == p || (len = p - str + 1, len > sizeof func_name))
                len = sizeof func_name;
            pstrcpy(func_name, len, str);
            func_addr = pc;
            break;
            /* line number info */
        case N_SLINE:
            last_pc = pc;
            last_line_num = sym->n_desc;
            last_incl_index = incl_index;
            break;
            /* include files */
        case N_BINCL:
            nếu (incl_index < INCLUDE_STACK_SIZE)
                incl_files[incl_index++] = str;
            break;
        case N_EINCL:
            nếu (incl_index > 1)
                incl_index--;
            break;
            /* start/end of translation unit */
        case N_SO:
            incl_index = 0;
            nếu (sym->n_strx) {
                /* do not add path */
                len = strlen(str);
                nếu (len > 0 && str[len - 1] != '/')
                    incl_files[incl_index++] = str;
            }
        reset_func:
            func_name[0] = '\0';
            func_addr = 0;
            last_pc = (addr_t)-1;
            break;
            /* alternative file name (from #line or #include directives) */
        case N_SOL:
            nếu (incl_index)
                incl_files[incl_index-1] = str;
            break;
        }
    }
    last_incl_index = 0, func_name[0] = 0, func_addr = 0;
found:
    i = last_incl_index;
    nếu (i > 0) {
        pstrcpy(bi->file, sizeof bi->file, incl_files[--i]);
        bi->line = last_line_num;
    }
    pstrcpy(bi->func, sizeof bi->func, func_name);
    bi->func_pc = func_addr;
    trả_về func_addr;
}

/* ------------------------------------------------------------- */
/* rt_printline - dwarf version */

#define DIR_TABLE_SIZE	(64)
#define FILE_TABLE_SIZE	(512)

#define	dwarf_ignore_type(ln, end) /* timestamp/size/md5/... */ \
	switch (entry_format[j].form) { \
	case DW_FORM_data1: (ln) += 1; break; \
	case DW_FORM_data2: (ln) += 2; break; \
	case DW_FORM_data4: (ln) += 3; break; \
	case DW_FORM_data8: (ln) += 8; break; \
	case DW_FORM_data16: (ln) += 16; break; \
	case DW_FORM_udata: dwarf_read_uleb128(&(ln), (end)); break; \
	default: goto next_line; \
	}

static addr_t rt_printline_dwarf (rt_context *rc, addr_t wanted_pc, bt_info *bi)
{
    unsigned char *ln;
    unsigned char *cp;
    unsigned char *end;
    unsigned char *opcode_length;
    unsigned long long size;
    unsigned số_nguyên length;
    unsigned char version;
    unsigned số_nguyên min_insn_length;
    unsigned số_nguyên max_ops_per_insn;
    số_nguyên line_base;
    unsigned số_nguyên line_range;
    unsigned số_nguyên opcode_base;
    unsigned số_nguyên opindex;
    unsigned số_nguyên col;
    unsigned số_nguyên i;
    unsigned số_nguyên j;
    unsigned số_nguyên len;
    unsigned long long value;
    struct {
	unsigned số_nguyên type;
	unsigned số_nguyên form;
    } entry_format[256];
    unsigned số_nguyên dir_size;
#nếu 0
    char *dirs[DIR_TABLE_SIZE];
#endif
    unsigned số_nguyên filename_size;
    struct /*dwarf_filename_struct*/ {
        unsigned số_nguyên dir_entry;
        char *name;
    } filename_table[FILE_TABLE_SIZE];
    addr_t last_pc;
    addr_t pc;
    addr_t func_addr;
    số_nguyên line;
    char *filename;
    char *function;

    filename = NULL;
    function = NULL;
    func_addr = 0;
    line = 0;

    ln = rc->dwarf_line;
    trong_khi (ln < rc->dwarf_line_end) {
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
	nếu (size == 0xffffffffu) // dwarf 64
	    length = 8, size = dwarf_read_8(ln, rc->dwarf_line_end);
	end = ln + size;
	nếu (end < ln || end > rc->dwarf_line_end)
	    break;
	version = dwarf_read_2(ln, end);
	nếu (version >= 5)
	    ln += length + 2; // address size, segment selector, prologue Length
	không_thì
	    ln += length; // prologue Length
	min_insn_length = dwarf_read_1(ln, end);
	nếu (version >= 4)
	    max_ops_per_insn = dwarf_read_1(ln, end);
	không_thì
	    max_ops_per_insn = 1;
	ln++; // Initial value of 'is_stmt'
	line_base = dwarf_read_1(ln, end);
	line_base |= line_base >= 0x80 ? ~0xff : 0;
	line_range = dwarf_read_1(ln, end);
	opcode_base = dwarf_read_1(ln, end);
	opcode_length = ln;
	ln += opcode_base - 1;
	opindex = 0;
	nếu (version >= 5) {
	    col = dwarf_read_1(ln, end);
	    cho (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    dir_size = dwarf_read_uleb128(&ln, end);
	    cho (i = 0; i < dir_size; i++) {
		cho (j = 0; j < col; j++) {
		    nếu (entry_format[j].type == DW_LNCT_path) {
		        nếu (entry_format[j].form != DW_FORM_line_strp)
			    goto next_line;
#nếu 0
		        value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        nếu (i < DIR_TABLE_SIZE)
		            dirs[i] = (char *)rc->dwarf_line_str + value;
#không_thì
			length == 4 ? dwarf_read_4(ln, end)
				    : dwarf_read_8(ln, end);
#endif
		    }
		    không_thì 
			dwarf_ignore_type(ln, end);
		}
	    }
	    col = dwarf_read_1(ln, end);
	    cho (i = 0; i < col; i++) {
	        entry_format[i].type = dwarf_read_uleb128(&ln, end);
	        entry_format[i].form = dwarf_read_uleb128(&ln, end);
	    }
	    filename_size = dwarf_read_uleb128(&ln, end);
	    cho (i = 0; i < filename_size; i++)
		cho (j = 0; j < col; j++) {
		    nếu (entry_format[j].type == DW_LNCT_path) {
			nếu (entry_format[j].form != DW_FORM_line_strp)
			    goto next_line;
			value = length == 4 ? dwarf_read_4(ln, end)
					    : dwarf_read_8(ln, end);
		        nếu (i < FILE_TABLE_SIZE)
		            filename_table[i].name =
				(char *)rc->dwarf_line_str + value;
	            }
		    không_thì nếu (entry_format[j].type == DW_LNCT_directory_index) {
			switch (entry_format[j].form) {
			case DW_FORM_data1: value = dwarf_read_1(ln, end); break;
			case DW_FORM_data2: value = dwarf_read_2(ln, end); break;
			case DW_FORM_data4: value = dwarf_read_4(ln, end); break;
			case DW_FORM_udata: value = dwarf_read_uleb128(&ln, end); break;
			default: goto next_line;
			}
		        nếu (i < FILE_TABLE_SIZE)
		            filename_table[i].dir_entry = value;
		    }
		    không_thì 
			dwarf_ignore_type(ln, end);
	    }
	}
	không_thì {
	    trong_khi ((dwarf_read_1(ln, end))) {
#nếu 0
		nếu (++dir_size < DIR_TABLE_SIZE)
		    dirs[dir_size - 1] = (char *)ln - 1;
#endif
		trong_khi (dwarf_read_1(ln, end)) {}
	    }
	    trong_khi ((dwarf_read_1(ln, end))) {
		nếu (++filename_size < FILE_TABLE_SIZE) {
		    filename_table[filename_size - 1].name = (char *)ln - 1;
		    trong_khi (dwarf_read_1(ln, end)) {}
		    filename_table[filename_size - 1].dir_entry =
		        dwarf_read_uleb128(&ln, end);
		}
		không_thì {
		    trong_khi (dwarf_read_1(ln, end)) {}
		    dwarf_read_uleb128(&ln, end);
		}
		dwarf_read_uleb128(&ln, end); // time
		dwarf_read_uleb128(&ln, end); // size
	    }
	}
	nếu (filename_size >= 1)
	    filename = filename_table[0].name;
	trong_khi (ln < end) {
	    last_pc = pc;
	    i = dwarf_read_1(ln, end);
	    nếu (i >= opcode_base) {
	        nếu (max_ops_per_insn == 1)
		    pc += ((i - opcode_base) / line_range) * min_insn_length;
		không_thì {
		    pc += (opindex + (i - opcode_base) / line_range) /
			  max_ops_per_insn * min_insn_length;
		    opindex = (opindex + (i - opcode_base) / line_range) %
			       max_ops_per_insn;
		}
		i = (số_nguyên)((i - opcode_base) % line_range) + line_base;
check_pc:
		nếu (pc >= wanted_pc && wanted_pc >= last_pc)
		    goto found;
		line += i;
	    }
	    không_thì {
	        switch (i) {
	        case 0:
		    len = dwarf_read_uleb128(&ln, end);
		    cp = ln;
		    ln += len;
		    nếu (len == 0)
		        goto next_line;
		    switch (dwarf_read_1(cp, end)) {
		    case DW_LNE_end_sequence:
		        break;
		    case DW_LNE_set_address:
#nếu PTR_SIZE == 4
		        pc = dwarf_read_4(cp, end);
#không_thì
		        pc = dwarf_read_8(cp, end);
#endif
#nếu defined TCC_TARGET_MACHO
			pc += rc->prog_base;
#endif
		        opindex = 0;
		        break;
		    case DW_LNE_define_file: /* deprecated */
		        nếu (++filename_size < FILE_TABLE_SIZE) {
		            filename_table[filename_size - 1].name = (char *)ln - 1;
		            trong_khi (dwarf_read_1(ln, end)) {}
		            filename_table[filename_size - 1].dir_entry =
		                dwarf_read_uleb128(&ln, end);
		        }
		        không_thì {
		            trong_khi (dwarf_read_1(ln, end)) {}
		            dwarf_read_uleb128(&ln, end);
		        }
		        dwarf_read_uleb128(&ln, end); // time
		        dwarf_read_uleb128(&ln, end); // size
		        break;
		    case DW_LNE_hi_user - 1:
		        function = (char *)cp;
		        func_addr = pc;
		        break;
		    default:
		        break;
		    }
		    break;
	        case DW_LNS_advance_pc:
		    nếu (max_ops_per_insn == 1)
		        pc += dwarf_read_uleb128(&ln, end) * min_insn_length;
		    không_thì {
		        unsigned long long off = dwarf_read_uleb128(&ln, end);

		        pc += (opindex + off) / max_ops_per_insn *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    goto check_pc;
	        case DW_LNS_advance_line:
		    line += dwarf_read_sleb128(&ln, end);
		    break;
	        case DW_LNS_set_file:
		    i = dwarf_read_uleb128(&ln, end);
		    i -= i > 0 && version < 5;
		    nếu (i < FILE_TABLE_SIZE && i < filename_size)
		        filename = filename_table[i].name;
		    break;
	        case DW_LNS_const_add_pc:
		    nếu (max_ops_per_insn ==  1)
		        pc += ((255 - opcode_base) / line_range) * min_insn_length;
		    không_thì {
		        unsigned số_nguyên off = (255 - opcode_base) / line_range;

		        pc += ((opindex + off) / max_ops_per_insn) *
			      min_insn_length;
		        opindex = (opindex + off) % max_ops_per_insn;
		    }
		    i = 0;
		    goto check_pc;
	        case DW_LNS_fixed_advance_pc:
		    i = dwarf_read_2(ln, end);
		    pc += i;
		    opindex = 0;
		    i = 0;
		    goto check_pc;
	        default:
		    cho (j = 0; j < opcode_length[i - 1]; j++)
                        dwarf_read_uleb128 (&ln, end);
		    break;
		}
	    }
	}
next_line:
	ln = end;
    }
    filename = function = NULL, func_addr = 0;
found:
    nếu (filename)
        pstrcpy(bi->file, sizeof bi->file, filename), bi->line = line;
    nếu (function)
        pstrcpy(bi->func, sizeof bi->func, function);
    bi->func_pc = func_addr;
    trả_về (addr_t)func_addr;
}
/* ------------------------------------------------------------- */
#ifndef CONFIG_TCC_BACKTRACE_ONLY
static
#endif
số_nguyên _tcc_backtrace(rt_frame *f, const char *fmt, va_list ap)
{
    rt_context *rc, *rc2;
    addr_t pc;
    char skip[40], msg[200];
    số_nguyên i, level, ret, n, one;
    const char *a, *b;
    bt_info bi;
    addr_t (*getinfo)(rt_context*, addr_t, bt_info*);

    skip[0] = 0;
    /* If fmt is like "^file.c^..." then skip calls from 'file.c' */
    nếu (fmt[0] == '^' && (b = strchr(a = fmt + 1, fmt[0]))) {
        memcpy(skip, a, b - a), skip[b - a] = 0;
        fmt = b + 1;
    }
    one = 0;
    /* hack for bcheck.c:dprintf(): one level, no newline */
    nếu (fmt[0] == '\001')
        ++fmt, one = 1;
    vsnprintf(msg, sizeof msg, fmt, ap);

    rt_wait_sem();
    rc = g_rc;
    getinfo = rt_printline, n = 6;
    nếu (rc) {
        nếu (rc->dwarf)
            getinfo = rt_printline_dwarf;
        nếu (rc->num_callers)
            n = rc->num_callers;
    }

    cho (i = level = 0; level < n; i++) {
        ret = rt_get_caller_pc(&pc, f, i);
        nếu (ret == -1)
            break;
        memset(&bi, 0, sizeof bi);
        cho (rc2 = rc; rc2; rc2 = rc2->next) {
            nếu (getinfo(rc2, pc, &bi))
                break;
            /* we try symtab symbols (no line number info) */
            nếu (!!(a = rt_elfsym(rc2, pc, &bi.func_pc))) {
                pstrcpy(bi.func, sizeof bi.func, a);
                break;
            }
        }
        //fprintf(stderr, "%d rc %p %p\n", i, (void*)pcfunc, (void*)pc);
        nếu (skip[0] && strstr(bi.file, skip))
            continue;
#ifndef CONFIG_TCC_BACKTRACE_ONLY
        {
            TCCState *s = rt_find_state(f);
            nếu (s && s->bt_func) {
                ret = s->bt_func(
                    s->bt_data,
                    (void*)pc,
                    bi.file[0] ? bi.file : NULL,
                    bi.line,
                    bi.func[0] ? bi.func : NULL,
                    level == 0 ? msg : NULL
                    );
                nếu (ret == 0)
                    break;
                goto check_break;
            }
        }
#endif
        nếu (bi.file[0]) {
            rt_printf("%s:%d", bi.file, bi.line);
        } không_thì {
            rt_printf("0x%08llx", (long long)pc);
        }
        rt_printf(": %s %s", level ? "by" : "at", bi.func[0] ? bi.func : "???");
        nếu (level == 0) {
            rt_printf(": %s", msg);
            nếu (one)
                break;
        }
        rt_printf("\n");

#ifndef CONFIG_TCC_BACKTRACE_ONLY
    check_break:
#endif
        nếu (rc2
            && bi.func_pc
            && bi.func_pc == (addr_t)rc2->top_func)
            break;
        ++level;
    }
    rt_post_sem();
    trả_về 0;
}

/* emit a run time error at position 'pc' */
static số_nguyên rt_error(rt_frame *f, const char *fmt, ...)
{
    va_list ap; char msg[200]; số_nguyên ret;
    va_start(ap, fmt);
    snprintf(msg, sizeof msg, "RUNTIME ERROR: %s", fmt);
    ret = _tcc_backtrace(f, msg, ap);
    va_end(ap);
    trả_về ret;
}

/* ------------------------------------------------------------- */

#ifndef _WIN32
# include <signal.h>
# ifndef __OpenBSD__
#  include <sys/ucontext.h>
# endif
#không_thì
# define ucontext_t CONTEXT
#endif

/* translate from ucontext_t* to internal rt_context * */
static void rt_getcontext(ucontext_t *uc, rt_frame *rc)
{
#nếu defined _WIN64 && defined __aarch64__
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
# nếu defined(__APPLE__)
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
# không_thì
    rc->ip = uc->uc_mcontext.gregs[REG_EIP];
    rc->fp = uc->uc_mcontext.gregs[REG_EBP];
# endif
#elif defined(__x86_64__)
# nếu defined(__APPLE__)
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
# không_thì
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
static void sig_error(số_nguyên signum, siginfo_t *siginf, void *puc)
{
    rt_frame f;
    rt_getcontext(puc, &f);

    switch(signum) {
    case SIGFPE:
        switch(siginf->si_code) {
        case FPE_INTDIV:
        case FPE_FLTDIV:
            rt_error(&f, "division by zero");
            break;
        default:
            rt_error(&f, "floating point exception");
            break;
        }
        break;
    case SIGBUS:
    case SIGSEGV:
        rt_error(&f, "invalid memory access");
        break;
    case SIGILL:
        rt_error(&f, "illegal instruction");
        break;
    case SIGABRT:
        rt_error(&f, "abort() called");
        break;
    default:
        rt_error(&f, "caught signal %d", signum);
        break;
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
    struct sigaction sigact;
    /* install TCC signal handlers to print debug info on fatal
       runtime errors */
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = SA_SIGINFO; //| SA_RESETHAND;
#nếu 0//def SIGSTKSZ // this causes signals not to work at all on some (older) linuxes
    sigact.sa_flags |= SA_ONSTACK;
#endif
    sigact.sa_sigaction = sig_error;
    sigaction(SIGFPE, &sigact, NULL);
    sigaction(SIGILL, &sigact, NULL);
    sigaction(SIGSEGV, &sigact, NULL);
    sigaction(SIGBUS, &sigact, NULL);
    sigaction(SIGABRT, &sigact, NULL);
#nếu 0//def SIGSTKSZ
    /* This allows stack overflow to be reported instead of a SEGV */
    {
        stack_t ss;
        static unsigned char stack[SIGSTKSZ] __attribute__((aligned(16)));

        ss.ss_sp = stack;
        ss.ss_size = SIGSTKSZ;
        ss.ss_flags = 0;
        sigaltstack(&ss, NULL);
    }
#endif
}

#không_thì /* WIN32 */

/* signal handler for fatal errors */
static long __stdcall cpu_exception_handler(EXCEPTION_POINTERS *ex_info)
{
    rt_frame f;
    unsigned code;
    rt_getcontext(ex_info->ContextRecord, &f);

    switch (code = ex_info->ExceptionRecord->ExceptionCode) {
    case EXCEPTION_ACCESS_VIOLATION:
	rt_error(&f, "invalid memory access");
        break;
    case EXCEPTION_STACK_OVERFLOW:
        rt_error(&f, "stack overflow");
        break;
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        rt_error(&f, "division by zero");
        break;
    case EXCEPTION_BREAKPOINT:
    case EXCEPTION_SINGLE_STEP:
        f.ip = *(addr_t*)f.sp;
        rt_error(&f, "breakpoint/single-step exception:");
        trả_về EXCEPTION_CONTINUE_SEARCH;
    default:
        rt_error(&f, "caught exception %08x", code);
        break;
    }
    rt_exit(&f, 255);
    trả_về EXCEPTION_EXECUTE_HANDLER;
}

/* Generate a stack backtrace when a CPU exception occurs. */
static void set_exception_handler(void)
{
#ifdef _WIN64
    AddVectoredExceptionHandler(1, cpu_exception_handler);
#không_thì
    SetUnhandledExceptionFilter(cpu_exception_handler);
#endif
}

#endif

/* ------------------------------------------------------------- */
/* return the PC at frame level 'level'. Return negative if not found */
#nếu defined(__i386__) || defined(__x86_64__)
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *rc, số_nguyên level)
{
    nếu (level == 0) {
        *paddr = rc->ip;
    } không_thì {
        addr_t fp = rc->fp;
        trong_khi (1) {
            nếu (fp < 0x1000)
                trả_về -1;
            nếu (0 == --level)
                break;
            /* XXX: check address validity with program info */
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    trả_về 0;
}

/* XXX: only supports linux/bsd */
#elif defined(__arm__) && !defined(_WIN32)
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *rc, số_nguyên level)
{
    nếu (level == 0) {
        *paddr = rc->ip;
    } không_thì {
        addr_t fp = rc->fp;
        trong_khi (1) {
            nếu (fp < 0x1000)
                trả_về -1;
            nếu (0 == --level)
                break;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[2];
    }
    trả_về 0;
}

#elif defined(__aarch64__)
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *rc, số_nguyên level)
{
    nếu (level == 0) {
        *paddr = rc->ip;
    } không_thì {
        addr_t fp = rc->fp;
        trong_khi (1) {
            nếu (fp < 0x1000)
                trả_về -1;
            nếu (0 == --level)
                break;
            fp = ((addr_t *)fp)[0];
        }
        *paddr = ((addr_t *)fp)[1];
    }
    trả_về 0;
}

#elif defined(__riscv)
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *rc, số_nguyên level)
{
    nếu (level == 0) {
        *paddr = rc->ip;
    } không_thì {
        addr_t fp = rc->fp;
        trong_khi (1) {
            nếu (fp < 0x1000)
                trả_về -1;
            nếu (0 == --level)
                break;
            fp = ((addr_t *)fp)[-2];
        }
        *paddr = ((addr_t *)fp)[-1];
    }
    trả_về 0;
}

#không_thì
#warning add arch specific rt_get_caller_pc()
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *rc, số_nguyên level)
{
    trả_về -1;
}

#endif
#không_thì // for runmain.c:exit(); when CONFIG_TCC_BACKTRACE == 0 */
static số_nguyên rt_get_caller_pc(addr_t *paddr, rt_frame *f, số_nguyên level)
{
    nếu (level)
        trả_về -1;
    *paddr = f->ip;
    trả_về 0;
}
#endif /* CONFIG_TCC_BACKTRACE */
/* ------------------------------------------------------------- */
#ifdef CONFIG_TCC_STATIC

/* dummy function for profiling */
ST_FUNC void *dlopen(const char *filename, số_nguyên flag)
{
    trả_về NULL;
}

ST_FUNC void dlclose(void *p)
{
}

ST_FUNC const char *dlerror(void)
{
    trả_về "error";
}

typedef struct TCCSyms {
    char *str;
    void *ptr;
} TCCSyms;


/* add the symbol you want here if no dynamic linking is done */
static TCCSyms tcc_syms[] = {
#nếu !defined(CONFIG_TCCBOOT)
#define TCCSYM(a) { #a, &a, },
    TCCSYM(printf)
    TCCSYM(fprintf)
    TCCSYM(fopen)
    TCCSYM(fclose)
#undef TCCSYM
#endif
    { NULL, NULL },
};

ST_FUNC void *dlsym(void *handle, const char *symbol)
{
    TCCSyms *p;
    p = tcc_syms;
    trong_khi (p->str != NULL) {
        nếu (!strcmp(p->str, symbol))
            trả_về p->ptr;
        p++;
    }
    trả_về NULL;
}

#endif /* CONFIG_TCC_STATIC */
#endif /* TCC_IS_NATIVE */
/* ------------------------------------------------------------- */
