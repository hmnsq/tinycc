/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#endif

#ifndef _WIN32
बाह्य शून्य (*_(_init_array_start)[]) (पूर्णांक argc, अक्षर **argv, अक्षर **envp);
बाह्य शून्य (*_(_init_array_end)[]) (पूर्णांक argc, अक्षर **argv, अक्षर **envp);
स्थिर शून्य run_ctors(पूर्णांक argc, अक्षर **argv, अक्षर **env)
{
    पूर्णांक i = 0;
    पर्यंत (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

बाह्य शून्य (*_(_fini_array_start)[]) (शून्य);
बाह्य शून्य (*_(_fini_array_end)[]) (शून्य);
स्थिर शून्य run_dtors(शून्य)
{
    पूर्णांक i = 0;
    पर्यंत (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

स्थिर शून्य *rt_exitfunc[32];
स्थिर शून्य *rt_exitarg[32];
स्थिर पूर्णांक __rt_nr_exit;

शून्य __run_on_exit(पूर्णांक ret)
{
    पूर्णांक n = __rt_nr_exit;
    पर्यंत (n)
	--n, ((शून्य(*)(पूर्णांक,शून्य*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

पूर्णांक on_exit(शून्य *function, शून्य *arg)
{
    पूर्णांक n = __rt_nr_exit;
    जर (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        परत 0;
    }
    परत 1;
}

पूर्णांक निकास_पर(शून्य (*function)(शून्य))
{
    परत on_exit(function, 0);
}

प्रकारव्याख्या संरचना rt_frame {
    शून्य *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) शून्य __rt_exit(rt_frame *, पूर्णांक);

शून्य निकास(पूर्णांक code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = निकास;
    __rt_exit(&f, code);
}

#ifndef _WIN32
पूर्णांक main(पूर्णांक, अक्षर**, अक्षर**);

पूर्णांक _runmain(पूर्णांक argc, अक्षर **argv, अक्षर **envp)
{
    पूर्णांक ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    परत ret;
}
#endif
