/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#घोषणा CONFIG_TCC_BACKTRACE_ONLY
#घोषणा ONE_SOURCE 0
#घोषणा pstrcpy tcc_pstrcpy
#समावेश "../tccrun.c"

#अगर_अघोषित _WIN32
# define __declspec(n)
#पूर्ण_अगर

#अगर_घोषित _WIN64
अटल व्योम bt_init_pe_prog_base(rt_context *p)
{
    MEMORY_BASIC_INFORMATION mbi;
    addr_t imagebase;

    अगर (!p->prog_base)
        वापस;
    अगर (!VirtualQuery(p, &mbi, माप(mbi)) || !mbi.AllocationBase)
        वापस;
    imagebase = (addr_t)mbi.AllocationBase - p->prog_base;
    p->prog_base = (addr_t)mbi.AllocationBase - (imagebase & 0xffffffffu);
}
#पूर्ण_अगर

__declspec(dllexport)
व्योम __bt_init(rt_context *p, पूर्णांक is_exe)
{
    __attribute__((weak)) पूर्णांक मुख्य();
    __attribute__((weak)) व्योम __bound_init(व्योम*, पूर्णांक);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    अगर (p->bounds_start)
	__bound_init(p->bounds_start, -1);

#अगर_घोषित _WIN64
    bt_init_pe_prog_base(p);
#पूर्ण_अगर

    /* add to chain */
    rt_wait_sem();
    p->अग्र = g_rc, g_rc = p;
    rt_post_sem();
    अगर (is_exe) {
        /* we are the executable (not a dll) */
        p->शीर्ष_func = मुख्य;
        set_exception_handler();
    }
}

__declspec(dllexport)
व्योम __bt_exit(rt_context *p)
{
    काष्ठा rt_context *rc, **pp;
    __attribute__((weak)) व्योम __bound_exit_dll(व्योम*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    अगर (p->bounds_start)
	__bound_exit_dll(p->bounds_start);

    /* remove from chain */
    rt_wait_sem();
    क्रम (pp = &g_rc; rc = *pp, rc; pp = &rc->अग्र)
        अगर (rc == p) {
            *pp = rc->अग्र;
            अवरोध;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC अक्षर *pstrcpy(अक्षर *buf, माप_प्रकार buf_आकार, स्थिर अक्षर *s)
{
    पूर्णांक l = म_माप(s);
    अगर (l >= buf_आकार)
        l = buf_आकार - 1;
    स_नकल(buf, s, l);
    buf[l] = 0;
    वापस buf;
}
