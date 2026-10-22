/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#ಅನ್ಯಥಾ
# define _(s) _##s
#endif

#ifndef _WIN32
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_init_array_start)[]) (ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **envp);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_init_array_end)[]) (ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **envp);
ಸ್ಥಿರ ಶೂನ್ಯ run_ctors(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **env)
{
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಯಾವತ್ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_fini_array_start)[]) (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ (*_(_fini_array_end)[]) (ಶೂನ್ಯ);
ಸ್ಥಿರ ಶೂನ್ಯ run_dtors(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಯಾವತ್ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

ಸ್ಥಿರ ಶೂನ್ಯ *rt_exitfunc[32];
ಸ್ಥಿರ ಶೂನ್ಯ *rt_exitarg[32];
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ __rt_nr_exit;

ಶೂನ್ಯ __run_on_exit(ಪೂರ್ಣಾಙ್ಕ ret)
{
    ಪೂರ್ಣಾಙ್ಕ n = __rt_nr_exit;
    ಯಾವತ್ (n)
	--n, ((ಶೂನ್ಯ(*)(ಪೂರ್ಣಾಙ್ಕ,ಶೂನ್ಯ*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ಪೂರ್ಣಾಙ್ಕ on_exit(ಶೂನ್ಯ *function, ಶೂನ್ಯ *arg)
{
    ಪೂರ್ಣಾಙ್ಕ n = __rt_nr_exit;
    ಯದಿ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ಪ್ರತ್ಯಾಗಮ 0;
    }
    ಪ್ರತ್ಯಾಗಮ 1;
}

ಪೂರ್ಣಾಙ್ಕ atexit(ಶೂನ್ಯ (*function)(ಶೂನ್ಯ))
{
    ಪ್ರತ್ಯಾಗಮ on_exit(function, 0);
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ rt_frame {
    ಶೂನ್ಯ *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) ಶೂನ್ಯ __rt_exit(rt_frame *, ಪೂರ್ಣಾಙ್ಕ);

ಶೂನ್ಯ exit(ಪೂರ್ಣಾಙ್ಕ code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ, ವರ್ಣ**, ವರ್ಣ**);

ಪೂರ್ಣಾಙ್ಕ _runmain(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv, ವರ್ಣ **envp)
{
    ಪೂರ್ಣಾಙ್ಕ ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ಪ್ರತ್ಯಾಗಮ ret;
}
#endif
