/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#تعریف_کرو CONFIG_TCC_BACKTRACE_ONLY
#تعریف_کرو ONE_سروت 0
#تعریف_کرو pstrcpy tcc_pstrcpy
#ضمن "../tccrun.c"

#جے_بنا_تعریف _WIN32
# define __declspec(n)
#جے_انت

#جے_تعریف_شدہ _WIN64
ساكن فراغ bt_init_pe_prog_ادھار(rt_context *p)
{
    حافظہ_BASIC_INFORMATION mbi;
    addr_t imagebase;

    إذا (!p->prog_ادھار)
        أرجع;
    إذا (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.ونڈ_ادھار)
        أرجع;
    imagebase = (addr_t)mbi.ونڈ_ادھار - p->prog_ادھار;
    p->prog_ادھار = (addr_t)mbi.ونڈ_ادھار - (imagebase & 0xffffffffu);
}
#جے_انت

__declspec(dllexport)
فراغ __bt_init(rt_context *p, صحيح is_exe)
{
    __attribute__((weak)) صحيح مکھ();
    __attribute__((weak)) فراغ __bound_init(فراغ*, صحيح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    إذا (p->bounds_شروع)
	__bound_init(p->bounds_شروع, -1);

#جے_تعریف_شدہ _WIN64
    bt_init_pe_prog_ادھار(p);
#جے_انت

    /* add to chain */
    rt_wait_sem();
    p->اگلا = g_rc, g_rc = p;
    rt_post_sem();
    إذا (is_exe) {
        /* we are the executable (not a dll) */
        p->چوٹی_func = مکھ;
        سیٹ_exception_handler();
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
    لكل (pp = &g_rc; rc = *pp, rc; pp = &rc->اگلا)
        إذا (rc == p) {
            *pp = rc->اگلا;
            اكسر;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, ناپ_t buf_ناپ, ثابت حرف *s)
{
    صحيح l = لڑی_لمبائی(s);
    إذا (l >= buf_ناپ)
        l = buf_ناپ - 1;
    حافظہ_نقل(buf, s, l);
    buf[l] = 0;
    أرجع buf;
}
