/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#ಅನ್ತರ್ಭಾವ "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ಯದಿ (!p->prog_base)
        ಪ್ರತ್ಯಾಗಮ;
    ಯದಿ (!VirtualQuery(p, &mbi, ಪರಿಮಾಣ(mbi)) || !mbi.AllocationBase)
        ಪ್ರತ್ಯಾಗಮ;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
ಶೂನ್ಯ __bt_init(rt_context *p, ಪೂರ್ಣಾಙ್ಕ is_exe)
{
    __attribute__((weak)) ಪೂರ್ಣಾಙ್ಕ main();
    __attribute__((weak)) ಶೂನ್ಯ __bound_init(ಶೂನ್ಯ*, ಪೂರ್ಣಾಙ್ಕ);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ಯದಿ (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    ಯದಿ (is_exe) {
        /* we are the executable (not a dll) */
        p->ತುದಿ_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
ಶೂನ್ಯ __bt_exit(rt_context *p)
{
    ಸಂರಚನಾ rt_context *rc, **pp;
    __attribute__((weak)) ಶೂನ್ಯ __bound_exit_dll(ಶೂನ್ಯ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ಯದಿ (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    ಪ್ರತಿ (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        ಯದಿ (rc == p) {
            *pp = rc->next;
            ಭಙ್ಗ;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC ವರ್ಣ *pstrcpy(ವರ್ಣ *buf, size_t buf_size, ಧ್ರುವ ವರ್ಣ *s)
{
    ಪೂರ್ಣಾಙ್ಕ l = strlen(s);
    ಯದಿ (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    ಪ್ರತ್ಯಾಗಮ buf;
}
