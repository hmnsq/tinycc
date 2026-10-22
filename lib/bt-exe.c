/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#تعریف_کن CONFIG_TCC_BACKTRACE_ONLY
#تعریف_کن ONE_منبع 0
#تعریف_کن pstrcpy tcc_pstrcpy
#ضمن "../tccrun.c"

#اگر_تعریف_نشده _WIN32
# define __declspec(n)
#پایان_اگر

#اگر_تعریف_شده _WIN64
ساكن فراغ bt_init_pe_prog_پایه(rt_context *p)
{
    حافظه_BASIC_INFORMATION mbi;
    addr_t imagebase;

    إذا (!p->prog_پایه)
        أرجع;
    إذا (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.تخصیص_پایه)
        أرجع;
    imagebase = (addr_t)mbi.تخصیص_پایه - p->prog_پایه;
    p->prog_پایه = (addr_t)mbi.تخصیص_پایه - (imagebase & 0xffffffffu);
}
#پایان_اگر

__declspec(dllexport)
فراغ __bt_init(rt_context *p, صحيح is_exe)
{
    __attribute__((weak)) صحيح اصلی();
    __attribute__((weak)) فراغ __bound_init(فراغ*, صحيح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    إذا (p->bounds_شروع)
	__bound_init(p->bounds_شروع, -1);

#اگر_تعریف_شده _WIN64
    bt_init_pe_prog_پایه(p);
#پایان_اگر

    /* add to chain */
    rt_wait_sem();
    p->بعدی = g_rc, g_rc = p;
    rt_post_sem();
    إذا (is_exe) {
        /* we are the executable (not a dll) */
        p->بالاترین_func = اصلی;
        مجموعه_exception_handler();
    }
}

__declspec(dllexport)
فراغ __bt_exit(rt_context *p)
{
    بنية rt_context *rc, **pp;
    __attribute__((weak)) فراغ __bound_exit_dll(فراغ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    إذا (p->bounds_شروع)
	__bound_exit_dll(p->bounds_شروع);

    /* remove from chain */
    rt_wait_sem();
    لكل (pp = &g_rc; rc = *pp, rc; pp = &rc->بعدی)
        إذا (rc == p) {
            *pp = rc->بعدی;
            اكسر;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s)
{
    صحيح l = طول_رشته(s);
    إذا (l >= buf_اندازه)
        l = buf_اندازه - 1;
    کپی_حافظه(buf, s, l);
    buf[l] = 0;
    أرجع buf;
}
