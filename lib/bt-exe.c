/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#അന്തര്ഭാവ "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
സ്ഥിതം ശൂന്യം bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    എങ്കിൽ (!p->prog_base)
        തിരികെ;
    എങ്കിൽ (!VirtualQuery(p, &mbi, വലുപ്പം(mbi)) || !mbi.AllocationBase)
        തിരികെ;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
ശൂന്യം __bt_init(rt_context *p, പൂർണ്ണസംഖ്യ is_exe)
{
    __attribute__((weak)) പൂർണ്ണസംഖ്യ പ്രധാന();
    __attribute__((weak)) ശൂന്യം __bound_init(ശൂന്യം*, പൂർണ്ണസംഖ്യ);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    എങ്കിൽ (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    എങ്കിൽ (is_exe) {
        /* we are the executable (not a dll) */
        p->മുകൾ_func = പ്രധാന;
        set_exception_handler();
    }
}

__declspec(dllexport)
ശൂന്യം __bt_exit(rt_context *p)
{
    ഘടന rt_context *rc, **pp;
    __attribute__((weak)) ശൂന്യം __bound_exit_dll(ശൂന്യം*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    എങ്കിൽ (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    വേണ്ടി (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        എങ്കിൽ (rc == p) {
            *pp = rc->next;
            നിർത്തുക;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC അക്ഷരം *pstrcpy(അക്ഷരം *buf, size_t buf_size, സ്ഥിരം അക്ഷരം *s)
{
    പൂർണ്ണസംഖ്യ l = strlen(s);
    എങ്കിൽ (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    തിരികെ buf;
}
