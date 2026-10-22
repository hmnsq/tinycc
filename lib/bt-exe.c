/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#నిర్వచించు CONFIG_TCC_BACKTRACE_ONLY
#నిర్వచించు ONE_ఆధారం 0
#నిర్వచించు pstrcpy tcc_pstrcpy
#అన్తర్భావ "../tccrun.c"

#నిర్వచితం_కాకపోతే _WIN32
# define __declspec(n)
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
స్థిర శూన్య bt_init_pe_prog_పునాది(rt_context *p)
{
    జ్ఞాపకం_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ఒకవేళ (!p->prog_పునాది)
        తిరిగి;
    ఒకవేళ (!VirtualQuery(p, &mbi, పరిమాణం(mbi)) || !mbi.కేటాయింపు_పునాది)
        తిరిగి;
    imagebase = (addr_t)mbi.కేటాయింపు_పునాది - p->prog_పునాది;
    p->prog_పునాది = (addr_t)mbi.కేటాయింపు_పునాది - (imagebase & 0xffffffffu);
}
#అయితే_ముగింపు

__declspec(dllexport)
శూన్య __bt_init(rt_context *p, పూర్ణాంకం is_exe)
{
    __attribute__((weak)) పూర్ణాంకం ప్రధాన();
    __attribute__((weak)) శూన్య __bound_init(శూన్య*, పూర్ణాంకం);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ఒకవేళ (p->bounds_ప్రారంభం)
	__bound_init(p->bounds_ప్రారంభం, -1);

#నిర్వచితమైతే _WIN64
    bt_init_pe_prog_పునాది(p);
#అయితే_ముగింపు

    /* add to chain */
    rt_wait_sem();
    p->తదుపరి = g_rc, g_rc = p;
    rt_post_sem();
    ఒకవేళ (is_exe) {
        /* we are the executable (not a dll) */
        p->శిఖరం_func = ప్రధాన;
        సమితి_exception_handler();
    }
}

__declspec(dllexport)
శూన్య __bt_exit(rt_context *p)
{
    నిర్మాణం rt_context *rc, **pp;
    __attribute__((weak)) శూన్య __bound_exit_dll(శూన్య*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ఒకవేళ (p->bounds_ప్రారంభం)
	__bound_exit_dll(p->bounds_ప్రారంభం);

    /* remove from chain */
    rt_wait_sem();
    కొరకు (pp = &g_rc; rc = *pp, rc; pp = &rc->తదుపరి)
        ఒకవేళ (rc == p) {
            *pp = rc->తదుపరి;
            ఆపు;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC అక్షరం *pstrcpy(అక్షరం *buf, కొలత_t buf_కొలత, స్థిరరాశి అక్షరం *s)
{
    పూర్ణాంకం l = అక్షరశ్రేణి_పొడవు(s);
    ఒకవేళ (l >= buf_కొలత)
        l = buf_కొలత - 1;
    జ్ఞాపకం_నకలు(buf, s, l);
    buf[l] = 0;
    తిరిగి buf;
}
