/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#অন্তর্ভাব "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
স্থির শূন্য bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    যদি (!p->prog_base)
        প্রত্যাগম;
    যদি (!VirtualQuery(p, &mbi, পরিমাণ(mbi)) || !mbi.AllocationBase)
        প্রত্যাগম;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
শূন্য __bt_init(rt_context *p, পূর্ণাঙ্ক is_exe)
{
    __attribute__((weak)) পূর্ণাঙ্ক main();
    __attribute__((weak)) শূন্য __bound_init(শূন্য*, পূর্ণাঙ্ক);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    যদি (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    যদি (is_exe) {
        /* we are the executable (not a dll) */
        p->শীর্ষ_func = main;
        set_exception_handler();
    }
}

__declspec(dllexport)
শূন্য __bt_exit(rt_context *p)
{
    সংরচনা rt_context *rc, **pp;
    __attribute__((weak)) শূন্য __bound_exit_dll(শূন্য*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    যদি (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    প্রতি (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        যদি (rc == p) {
            *pp = rc->next;
            ভঙ্গ;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC বর্ণ *pstrcpy(বর্ণ *buf, size_t buf_size, ধ্রুব বর্ণ *s)
{
    পূর্ণাঙ্ক l = strlen(s);
    যদি (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    প্রত্যাগম buf;
}
