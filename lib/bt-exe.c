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

    सचे (!p->prog_base)
        पटिनिवत्त;
    सचे (!VirtualQuery(p, &mbi, परिमाण(mbi)) || !mbi.AllocationBase)
        पटिनिवत्त;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
शून्य __bt_init(rt_context *p, पूर्णाङ्क is_exe)
{
    __attribute__((weak)) पूर्णाङ्क main();
    __attribute__((weak)) शून्य __bound_init(शून्य*, पूर्णाङ्क);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    सचे (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    सचे (is_exe) {
        /* we are the executable (not a dll) */
        p->शिखरम्_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
शून्य __bt_exit(rt_context *p)
{
    संरचना rt_context *rc, **pp;
    __attribute__((weak)) शून्य __bound_exit_dll(शून्य*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    सचे (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    अत्थाय (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        सचे (rc == p) {
            *pp = rc->next;
            भङ्ग;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC वर्ण *pstrcpy(वर्ण *buf, size_t buf_size, ध्रुव वर्ण *s)
{
    पूर्णाङ्क l = strlen(s);
    सचे (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    पटिनिवत्त buf;
}
