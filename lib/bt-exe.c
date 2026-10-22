/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#परिभाषय CONFIG_TCC_BACKTRACE_ONLY
#परिभाषय ONE_SOURCE 0
#परिभाषय pstrcpy tcc_pstrcpy
#अन्तर्भाव "../tccrun.c"

#यदि_अपरिभाषितम् _WIN32
# define __declspec(n)
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
स्थिर शून्य bt_init_pe_prog_आधारः(rt_context *p)
{
    स्मृतिः_BASIC_INFORMATION mbi;
    addr_t imagebase;

    यदि (!p->prog_आधारः)
        प्रत्यागम;
    यदि (!VirtualQuery(p, &mbi, परिमाण(mbi)) || !mbi.आवण्टनम्_आधारः)
        प्रत्यागम;
    imagebase = (addr_t)mbi.आवण्टनम्_आधारः - p->prog_आधारः;
    p->prog_आधारः = (addr_t)mbi.आवण्टनम्_आधारः - (imagebase & 0xffffffffu);
}
#यदि_अन्तः

__declspec(dllexport)
शून्य __bt_init(rt_context *p, पूर्णाङ्क is_exe)
{
    __attribute__((weak)) पूर्णाङ्क मुख्यम्();
    __attribute__((weak)) शून्य __bound_init(शून्य*, पूर्णाङ्क);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    यदि (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#यदि_परिभाषितम् _WIN64
    bt_init_pe_prog_आधारः(p);
#यदि_अन्तः

    /* add to chain */
    rt_wait_sem();
    p->अग्र = g_rc, g_rc = p;
    rt_post_sem();
    यदि (is_exe) {
        /* we are the executable (not a dll) */
        p->शिखरम्_func = मुख्यम्;
        समुच्चयः_exception_handler();
    }
}

__declspec(dllexport)
शून्य __bt_exit(rt_context *p)
{
    संरचना rt_context *rc, **pp;
    __attribute__((weak)) शून्य __bound_exit_dll(शून्य*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    यदि (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    प्रति (pp = &g_rc; rc = *pp, rc; pp = &rc->अग्र)
        यदि (rc == p) {
            *pp = rc->अग्र;
            भङ्ग;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC वर्ण *pstrcpy(वर्ण *buf, आकार_t buf_आकार, ध्रुव वर्ण *s)
{
    पूर्णाङ्क l = वाक्यदैर्घ्यम्(s);
    यदि (l >= buf_आकार)
        l = buf_आकार - 1;
    स्मृतिं_प्रतिलिख(buf, s, l);
    buf[l] = 0;
    प्रत्यागम buf;
}
