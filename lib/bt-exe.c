/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#अन्तर्भाव "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
स्थिर शून्य bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    जर (!p->prog_base)
        परत;
    जर (!VirtualQuery(p, &mbi, आकार(mbi)) || !mbi.AllocationBase)
        परत;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
शून्य __bt_init(rt_context *p, पूर्णांक is_exe)
{
    __attribute__((weak)) पूर्णांक main();
    __attribute__((weak)) शून्य __bound_init(शून्य*, पूर्णांक);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    जर (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    जर (is_exe) {
        /* we are the executable (not a dll) */
        p->शीर्ष_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
शून्य __bt_exit(rt_context *p)
{
    संरचना rt_context *rc, **pp;
    __attribute__((weak)) शून्य __bound_exit_dll(शून्य*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    जर (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    साठी (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        जर (rc == p) {
            *pp = rc->next;
            थांबा;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC अक्षर *pstrcpy(अक्षर *buf, माप_प्रकार buf_size, स्थिरांक अक्षर *s)
{
    पूर्णांक l = म_माप(s);
    जर (l >= buf_size)
        l = buf_size - 1;
    स_नकल(buf, s, l);
    buf[l] = 0;
    परत buf;
}
