/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#تعریف_کړه CONFIG_TCC_BACKTRACE_ONLY
#تعریف_کړه ONE_سرچینه 0
#تعریف_کړه pstrcpy tcc_pstrcpy
#ضمن "../tccrun.c"

#که_نه_تعریف_شوی _WIN32
# define __declspec(n)
#د_که_پای

#که_تعریف_شوی _WIN64
ساكن فراغ bt_init_pe_prog_بنسټ(rt_context *p)
{
    حافظه_BASIC_INFORMATION mbi;
    addr_t imagebase;

    إذا (!p->prog_بنسټ)
        أرجع;
    إذا (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.ویش_بنسټ)
        أرجع;
    imagebase = (addr_t)mbi.ویش_بنسټ - p->prog_بنسټ;
    p->prog_بنسټ = (addr_t)mbi.ویش_بنسټ - (imagebase & 0xffffffffu);
}
#د_که_پای

__declspec(dllexport)
فراغ __bt_init(rt_context *p, صحيح is_exe)
{
    __attribute__((weak)) صحيح اصلي();
    __attribute__((weak)) فراغ __bound_init(فراغ*, صحيح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    إذا (p->bounds_پیل)
	__bound_init(p->bounds_پیل, -1);

#که_تعریف_شوی _WIN64
    bt_init_pe_prog_بنسټ(p);
#د_که_پای

    /* add to chain */
    rt_wait_sem();
    p->بل = g_rc, g_rc = p;
    rt_post_sem();
    إذا (is_exe) {
        /* we are the executable (not a dll) */
        p->سر_func = اصلي;
        سېټ_exception_handler();
    }
}

__declspec(dllexport)
فراغ __bt_exit(rt_context *p)
{
    بنية rt_context *rc, **pp;
    __attribute__((weak)) فراغ __bound_exit_dll(فراغ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    إذا (p->bounds_پیل)
	__bound_exit_dll(p->bounds_پیل);

    /* remove from chain */
    rt_wait_sem();
    لكل (pp = &g_rc; rc = *pp, rc; pp = &rc->بل)
        إذا (rc == p) {
            *pp = rc->بل;
            اكسر;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, اندازه_t buf_اندازه, ثابت حرف *s)
{
    صحيح l = مزي_اوږدوالی(s);
    إذا (l >= buf_اندازه)
        l = buf_اندازه - 1;
    حافظه_نقل(buf, s, l);
    buf[l] = 0;
    أرجع buf;
}
