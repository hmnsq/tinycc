/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#અન્તર્ભાવ "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
સ્થિર શૂન્ય bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    જો (!p->prog_base)
        પાછા;
    જો (!VirtualQuery(p, &mbi, કદ(mbi)) || !mbi.AllocationBase)
        પાછા;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
શૂન્ય __bt_init(rt_context *p, પૂર્ણાંક is_exe)
{
    __attribute__((weak)) પૂર્ણાંક મુખ્ય();
    __attribute__((weak)) શૂન્ય __bound_init(શૂન્ય*, પૂર્ણાંક);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    જો (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    જો (is_exe) {
        /* we are the executable (not a dll) */
        p->ટોચ_func = મુખ્ય;
        set_exception_handler();
    }
}

__declspec(dllexport)
શૂન્ય __bt_exit(rt_context *p)
{
    સંરચના rt_context *rc, **pp;
    __attribute__((weak)) શૂન્ય __bound_exit_dll(શૂન્ય*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    જો (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    માટે (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        જો (rc == p) {
            *pp = rc->next;
            તોડો;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC અક્ષર *pstrcpy(અક્ષર *buf, size_t buf_size, અચલ અક્ષર *s)
{
    પૂર્ણાંક l = strlen(s);
    જો (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    પાછા buf;
}
