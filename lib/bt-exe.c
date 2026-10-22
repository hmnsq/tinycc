/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#ଅନ୍ତର୍ଭାଵ "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
ସ୍ଥିର ଶୂନ୍ୟ bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ଯଦି (!p->prog_base)
        ଫେରନ୍ତୁ;
    ଯଦି (!VirtualQuery(p, &mbi, ଆକାର(mbi)) || !mbi.AllocationBase)
        ଫେରନ୍ତୁ;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
ଶୂନ୍ୟ __bt_init(rt_context *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା is_exe)
{
    __attribute__((weak)) ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ();
    __attribute__((weak)) ଶୂନ୍ୟ __bound_init(ଶୂନ୍ୟ*, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ଯଦି (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    ଯଦି (is_exe) {
        /* we are the executable (not a dll) */
        p->ଶୀର୍ଷ_func = ମୁଖ୍ୟ;
        set_exception_handler();
    }
}

__declspec(dllexport)
ଶୂନ୍ୟ __bt_exit(rt_context *p)
{
    ସଂରଚନା rt_context *rc, **pp;
    __attribute__((weak)) ଶୂନ୍ୟ __bound_exit_dll(ଶୂନ୍ୟ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ଯଦି (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    ପାଇଁ (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        ଯଦି (rc == p) {
            *pp = rc->next;
            ଭାଙ୍ଗ;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC ଅକ୍ଷର *pstrcpy(ଅକ୍ଷର *buf, size_t buf_size, ଅଚଳ ଅକ୍ଷର *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା l = strlen(s);
    ଯଦି (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    ଫେରନ୍ତୁ buf;
}
