/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#define CONFIG_TCC_BACKTRACE_ONLY
#define ONE_SOURCE 0
#define pstrcpy tcc_pstrcpy
#شامل "../tccrun.c"

#ifndef _WIN32
# define __declspec(n)
#endif

#ifdef _WIN64
ایستا تهی bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    اگر (!p->prog_base)
        بازگشت;
    اگر (!VirtualQuery(p, &mbi, اندازه(mbi)) || !mbi.AllocationBase)
        بازگشت;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#endif

__declspec(dllexport)
تهی __bt_init(rt_context *p, صحیح is_exe)
{
    __attribute__((weak)) صحیح اصلی();
    __attribute__((weak)) تهی __bound_init(تهی*, صحیح);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    اگر (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#ifdef _WIN64
    bt_init_pe_prog_base(p);
#endif

    /* add to chain */
    rt_wait_sem();
    p->next = g_rc, g_rc = p;
    rt_post_sem();
    اگر (is_exe) {
        /* we are the executable (not a dll) */
        p->بالاترین_func = اصلی;
        set_exception_handler();
    }
}

__declspec(dllexport)
تهی __bt_exit(rt_context *p)
{
    ساختار rt_context *rc, **pp;
    __attribute__((weak)) تهی __bound_exit_dll(تهی*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    اگر (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    برای (pp = &g_rc; rc = *pp, rc; pp = &rc->next)
        اگر (rc == p) {
            *pp = rc->next;
            بشکن;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC نویسه *pstrcpy(نویسه *buf, size_t buf_size, ثابت نویسه *s)
{
    صحیح l = strlen(s);
    اگر (l >= buf_size)
        l = buf_size - 1;
    memcpy(buf, s, l);
    buf[l] = 0;
    بازگشت buf;
}
