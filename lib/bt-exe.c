/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#تعریف_کرو CONFIG_TCC_BACKTRACE_ONLY
#تعریف_کرو ONE_ماخذ 0
#تعریف_کرو pstrcpy tcc_pstrcpy
#شامل "../tccrun.c"

#اگر_غیر_تعریف_شدہ _WIN32
# define __declspec(n)
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
ساکن خالی bt_init_pe_prog_بنیاد(rt_context *p)
{
    حافظہ_BASIC_INFORMATION mbi;
    addr_t imagebase;

    اگر (!p->prog_بنیاد)
        واپس;
    اگر (!VirtualQuery(p, &mbi, حجم(mbi)) || !mbi.تخصیص_بنیاد)
        واپس;
    imagebase = (addr_t)mbi.تخصیص_بنیاد - p->prog_بنیاد;
    p->prog_بنیاد = (addr_t)mbi.تخصیص_بنیاد - (imagebase & 0xffffffffu);
}
#اگر_ختم

__declspec(dllexport)
خالی __bt_init(rt_context *p, صحیح is_exe)
{
    __attribute__((weak)) صحیح مین();
    __attribute__((weak)) خالی __bound_init(خالی*, صحیح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    اگر (p->bounds_آغاز)
	__bound_init(p->bounds_آغاز, -1);

#اگر_تعریف_شدہ _WIN64
    bt_init_pe_prog_بنیاد(p);
#اگر_ختم

    /* add to chain */
    rt_wait_sem();
    p->اگلا = g_rc, g_rc = p;
    rt_post_sem();
    اگر (is_exe) {
        /* we are the executable (not a dll) */
        p->چوٹی_func = مین;
        سیٹ_exception_handler();
    }
}

__declspec(dllexport)
خالی __bt_exit(rt_context *p)
{
    ساخت rt_context *rc, **pp;
    __attribute__((weak)) خالی __bound_exit_dll(خالی*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    اگر (p->bounds_آغاز)
	__bound_exit_dll(p->bounds_آغاز);

    /* remove from chain */
    rt_wait_sem();
    برائے (pp = &g_rc; rc = *pp, rc; pp = &rc->اگلا)
        اگر (rc == p) {
            *pp = rc->اگلا;
            توڑو;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC حرف *pstrcpy(حرف *buf, سائز_t buf_سائز, ثابت حرف *s)
{
    صحیح l = لڑی_لمبائی(s);
    اگر (l >= buf_سائز)
        l = buf_سائز - 1;
    حافظہ_نقل(buf, s, l);
    buf[l] = 0;
    واپس buf;
}
