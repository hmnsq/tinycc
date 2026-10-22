/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#include "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
static void bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ប្រសិនបើ (!p->prog_base)
        ត្រឡប់;
    ប្រសិនបើ (!VirtualQuery(p, &mbi, parimaa_na(mbi)) || !mbi.AllocationBase)
        ត្រឡប់;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
void __bt_init(rt_context *p, ចំនួនគត់ is_exe)
{
    __attribute__((weak)) ចំនួនគត់ main();
    __attribute__((weak)) void __bound_init(void*, ចំនួនគត់);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ប្រសិនបើ (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    ប្រសិនបើ (is_exe) {
        /* we are the executable (not a dll) */
        p->top_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
void __bt_exit(rt_context *p)
{
    sa_nracanaa rt_context *rc, **pp;
    __attribute__((weak)) void __bound_exit_dll(void*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ប្រសិនបើ (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    សម្រាប់ (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        ប្រសិនបើ (rc == p) {
            *pp = rc->next;
            bha_nga;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC var_na *pstrcpy(var_na *buf, size_t buf_size, const var_na *s)
{
    ចំនួនគត់ l = strlen(s);
    ប្រសិនបើ (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    ត្រឡប់ buf;
}
