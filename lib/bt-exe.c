/* ------------------------------------------------------------- */
/* for linking rt_printline and the signal/exception handler
   from tccrun.c into executables. */

#ವ್ಯಾಖ್ಯಾನಿಸು CONFIG_TCC_BACKTRACE_ONLY
#ವ್ಯಾಖ್ಯಾನಿಸು ONE_ಮೂಲ 0
#ವ್ಯಾಖ್ಯಾನಿಸು pstrcpy tcc_pstrcpy
#ಅನ್ತರ್ಭಾವ "../tccrun.c"

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
# define __declspec(n)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
ಸ್ಥಿರ ಶೂನ್ಯ bt_init_pe_prog_ತಳ(rt_context *p)
{
    ಸ್ಮರಣೆ_BASIC_INFORMATION mbi;
    addr_t imagebase;

    ಆದರೆ (!p->prog_ತಳ)
        ಹಿಂತಿರುಗಿ;
    ಆದರೆ (!VirtualQuery(p, &mbi, ಗಾತ್ರ(mbi)) || !mbi.ಹಂಚಿಕೆ_ತಳ)
        ಹಿಂತಿರುಗಿ;
    imagebase = (addr_t)mbi.ಹಂಚಿಕೆ_ತಳ - p->prog_ತಳ;
    p->prog_ತಳ = (addr_t)mbi.ಹಂಚಿಕೆ_ತಳ - (imagebase & 0xffffffffu);
}
#ಆದರೆ_ಅಂತ್ಯ

__declspec(dllexport)
ಶೂನ್ಯ __bt_init(rt_context *p, ಪೂರ್ಣಾಂಕ is_exe)
{
    __attribute__((weak)) ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ();
    __attribute__((weak)) ಶೂನ್ಯ __bound_init(ಶೂನ್ಯ*, ಪೂರ್ಣಾಂಕ);

    //fprintf(stderr, "__bt_init %d %p %p %p\n", is_exe, p, p->stab_sym, p->bounds_start), fflush(stderr);

    /* call __bound_init here due to redirection of sigaction */
    /* needed to add global symbols */
    ಆದರೆ (p->bounds_ಆರಂಭ)
	__bound_init(p->bounds_ಆರಂಭ, -1);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    bt_init_pe_prog_ತಳ(p);
#ಆದರೆ_ಅಂತ್ಯ

    /* add to chain */
    rt_wait_sem();
    p->ಮುಂದಿನ = g_rc, g_rc = p;
    rt_post_sem();
    ಆದರೆ (is_exe) {
        /* we are the executable (not a dll) */
        p->ತುದಿ_func = ಮುಖ್ಯ;
        ಗಣ_exception_handler();
    }
}

__declspec(dllexport)
ಶೂನ್ಯ __bt_exit(rt_context *p)
{
    ರಚನೆ rt_context *rc, **pp;
    __attribute__((weak)) ಶೂನ್ಯ __bound_exit_dll(ಶೂನ್ಯ*);

    //fprintf(stderr, "__bt_exit %d %p\n", !!p->top_func, p);

    ಆದರೆ (p->bounds_ಆರಂಭ)
	__bound_exit_dll(p->bounds_ಆರಂಭ);

    /* remove from chain */
    rt_wait_sem();
    ಗಾಗಿ (pp = &g_rc; rc = *pp, rc; pp = &rc->ಮುಂದಿನ)
        ಆದರೆ (rc == p) {
            *pp = rc->ಮುಂದಿನ;
            ನಿಲ್ಲಿಸು;
        }
    rt_post_sem();
}

/* copy a string and truncate it. */
ST_FUNC ಅಕ್ಷರ *pstrcpy(ಅಕ್ಷರ *buf, ಗಾತ್ರ_t buf_ಗಾತ್ರ, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಪೂರ್ಣಾಂಕ l = ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(s);
    ಆದರೆ (l >= buf_ಗಾತ್ರ)
        l = buf_ಗಾತ್ರ - 1;
    ಸ್ಮರಣೆ_ನಕಲು(buf, s, l);
    buf[l] = 0;
    ಹಿಂತಿರುಗಿ buf;
}
