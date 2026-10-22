/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_BACKTRACE_ONLY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ONE_ਸਰੋਤ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pstrcpy tcc_pstrcpy
#ਅਨ੍ਤਰ੍ਭਾਵ "../tccrun.c"

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
# define __declspec(n)
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
ਸਥਿਰ ਖਾਲੀ bt_init_pe_prog_ਅਧਾਰ(rt_context *p)
{
    ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ਜੇ (!p->prog_ਅਧਾਰ)
        ਵਾਪਸ;
    ਜੇ (!VirtualQuery(p, &mbi, ਆਕਾਰ(mbi)) || !mbi.ਵੰਡ_ਅਧਾਰ)
        ਵਾਪਸ;
    imagebase = (addr_t)mbi.ਵੰਡ_ਅਧਾਰ - p->prog_ਅਧਾਰ;
    p->prog_ਅਧਾਰ = (addr_t)mbi.ਵੰਡ_ਅਧਾਰ - (imagebase & 0xffffffffu);
}
#ਜੇ_ਅੰਤ

__declspec(dllexport)
ਖਾਲੀ __bt_init(rt_context *p, ਪੂਰਨ is_exe)
{
    __attribute__((weak)) ਪੂਰਨ ਮੁੱਖ();
    __attribute__((weak)) ਖਾਲੀ __bound_init(ਖਾਲੀ*, ਪੂਰਨ);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ਜੇ (p->bounds_ਸ਼ੁਰੂ)
	__bound_init(p->bounds_ਸ਼ੁਰੂ, -1);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    bt_init_pe_prog_ਅਧਾਰ(p);
#ਜੇ_ਅੰਤ

    /* add to chain */
    rt_wait_sem();
    p->ਅਗਲਾ = g_rc, g_rc = p;
    rt_post_sem();
    ਜੇ (is_exe) {
        /* we are the executable (not a dll) */
        p->ਸਿਖਰ_func = ਮੁੱਖ;
        ਸੈੱਟ_exception_handler();
    }
}

__declspec(dllexport)
ਖਾਲੀ __bt_exit(rt_context *p)
{
    ਬਣਤਰ rt_context *rc, **pp;
    __attribute__((weak)) ਖਾਲੀ __bound_exit_dll(ਖਾਲੀ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ਜੇ (p->bounds_ਸ਼ੁਰੂ)
	__bound_exit_dll(p->bounds_ਸ਼ੁਰੂ);

    /* remove from chain */
    rt_wait_sem();
    ਲਈ (pp = &g_rc; rc = *pp, rc; pp = &rc->ਅਗਲਾ)
        ਜੇ (rc == p) {
            *pp = rc->ਅਗਲਾ;
            ਰੋਕੋ;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC ਅੱਖਰ *pstrcpy(ਅੱਖਰ *buf, ਮਾਪ_t buf_ਮਾਪ, ਅਚਲ ਅੱਖਰ *s)
{
    ਪੂਰਨ l = ਲੜੀ_ਲੰਬਾਈ(s);
    ਜੇ (l >= buf_ਮਾਪ)
        l = buf_ਮਾਪ - 1;
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(buf, s, l);
    buf[l] = 0;
    ਵਾਪਸ buf;
}
