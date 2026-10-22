/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#அந்தர்பாவ "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
நிலையான வெறுமை bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    எனில் (!p->prog_base)
        திரும்பு;
    எனில் (!VirtualQuery(p, &mbi, அளவு(mbi)) || !mbi.AllocationBase)
        திரும்பு;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
வெறுமை __bt_init(rt_context *p, முழு is_exe)
{
    __attribute__((weak)) முழு முதன்மை();
    __attribute__((weak)) வெறுமை __bound_init(வெறுமை*, முழு);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    எனில் (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    எனில் (is_exe) {
        /* we are the executable (not a dll) */
        p->உச்சி_func = முதன்மை;
        set_exception_handler();
    }
}

__declspec(dllexport)
வெறுமை __bt_exit(rt_context *p)
{
    கட்டமைப்பு rt_context *rc, **pp;
    __attribute__((weak)) வெறுமை __bound_exit_dll(வெறுமை*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    எனில் (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    க்கு (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        எனில் (rc == p) {
            *pp = rc->next;
            நிறுத்து;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC எழுத்து *pstrcpy(எழுத்து *buf, size_t buf_size, மாறிலி எழுத்து *s)
{
    முழு l = strlen(s);
    எனில் (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    திரும்பு buf;
}
