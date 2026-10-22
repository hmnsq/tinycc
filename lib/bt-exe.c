/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#وصف_ڪريو CONFIG_TCC_BACKTRACE_ONLY
#وصف_ڪريو ONE_ذريعو 0
#وصف_ڪريو pstrcpy tcc_pstrcpy
#ضمن "../tccrun.c"

#جيڪڏهن_وصف_نه_ٿيل _WIN32
# define __declspec(n)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
ساكن فراغ bt_init_pe_prog_بنياد(rt_context *p)
{
    يادگيري_BASIC_INFORMATION mbi;
    addr_t imagebase;

    إذا (!p->prog_بنياد)
        أرجع;
    إذا (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.ورهاست_بنياد)
        أرجع;
    imagebase = (addr_t)mbi.ورهاست_بنياد - p->prog_بنياد;
    p->prog_بنياد = (addr_t)mbi.ورهاست_بنياد - (imagebase & 0xffffffffu);
}
#جيڪڏهن_پورو

__declspec(dllexport)
فراغ __bt_init(rt_context *p, صحيح is_exe)
{
    __attribute__((weak)) صحيح مکيه();
    __attribute__((weak)) فراغ __bound_init(فراغ*, صحيح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    إذا (p->bounds_شروعات)
	__bound_init(p->bounds_شروعات, -1);

#جيڪڏهن_وصف_ٿيل _WIN64
    bt_init_pe_prog_بنياد(p);
#جيڪڏهن_پورو

    /* add to chain */
    rt_wait_sem();
    p->ايندڙ = g_rc, g_rc = p;
    rt_post_sem();
    إذا (is_exe) {
        /* we are the executable (not a dll) */
        p->چوٽي_func = مکيه;
        سيٽ_exception_handler();
    }
}

__declspec(dllexport)
فراغ __bt_exit(rt_context *p)
{
    بنية rt_context *rc, **pp;
    __attribute__((weak)) فراغ __bound_exit_dll(فراغ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    إذا (p->bounds_شروعات)
	__bound_exit_dll(p->bounds_شروعات);

    /* remove from chain */
    rt_wait_sem();
    لكل (pp = &g_rc; rc = *pp, rc; pp = &rc->ايندڙ)
        إذا (rc == p) {
            *pp = rc->ايندڙ;
            اكسر;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, سائيز_t buf_سائيز, ثابت حرف *s)
{
    صحيح l = لڙي_ڊيگهه(s);
    إذا (l >= buf_سائيز)
        l = buf_سائيز - 1;
    يادگيري_نقل(buf, s, l);
    buf[l] = 0;
    أرجع buf;
}
