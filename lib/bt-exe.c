/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#ضمن "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
ساكن فراغ bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    إذا (!p->prog_base)
        أرجع;
    إذا (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.AllocationBase)
        أرجع;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
فراغ __bt_init(rt_context *p, صحيح is_exe)
{
    __attribute__((weak)) صحيح main();
    __attribute__((weak)) فراغ __bound_init(فراغ*, صحيح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    إذا (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    إذا (is_exe) {
        /* we are the executable (not a dll) */
        p->كولي_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
فراغ __bt_exit(rt_context *p)
{
    بنية rt_context *rc, **pp;
    __attribute__((weak)) فراغ __bound_exit_dll(فراغ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    إذا (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    لكل (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        إذا (rc == p) {
            *pp = rc->next;
            اكسر;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, size_t buf_size, ثابت حرف *s)
{
    صحيح l = strlen(s);
    إذا (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    أرجع buf;
}
