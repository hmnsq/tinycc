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
        ফেরত;
    যদি (!VirtualQuery(p, &mbi, আকার(mbi)) || !mbi.AllocationBase)
        ফেরত;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
শূন্য __bt_init(rt_context *p, পূর্ণসংখ্যা is_exe)
{
    __attribute__((weak)) পূর্ণসংখ্যা প্রধান();
    __attribute__((weak)) শূন্য __bound_init(শূন্য*, পূর্ণসংখ্যা);

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
    p->পরবর্তী = g_rc, g_rc = p;
    rt_post_sem();
    যদি (is_exe) {
        /* we are the executable (not a dll) */
        p->শীর্ষ_func = প্রধান;
        set_exception_handler();
    }
}

__declspec(dllexport)
শূন্য __bt_exit(rt_context *p)
{
    কাঠামো rt_context *rc, **pp;
    __attribute__((weak)) শূন্য __bound_exit_dll(শূন্য*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    যদি (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    জন্য (pp = &g_rc; rc = *pp, rc; pp = &rc->পরবর্তী)
        যদি (rc == p) {
            *pp = rc->পরবর্তী;
            বিরতি;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC অক্ষর *pstrcpy(অক্ষর *buf, আকার_t buf_আকার, ধ্রুবক অক্ষর *s)
{
    পূর্ণসংখ্যা l = strlen(s);
    যদি (l >= buf_আকার)
        l = buf_আকার - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    ফেরত buf;
}
