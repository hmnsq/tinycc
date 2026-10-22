/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#अण्णहा
# define _(s) _##s
#endif

#ifndef _WIN32
बाह्य शून्य (*_(_init_array_start)[]) (पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
बाह्य शून्य (*_(_init_array_end)[]) (पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
स्थिर शून्य run_ctors(पूर्णाङ्क argc, वर्ण **argv, वर्ण **env)
{
    पूर्णाङ्क i = 0;
    जाव (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

बाह्य शून्य (*_(_fini_array_start)[]) (शून्य);
बाह्य शून्य (*_(_fini_array_end)[]) (शून्य);
स्थिर शून्य run_dtors(शून्य)
{
    पूर्णाङ्क i = 0;
    जाव (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

स्थिर शून्य *rt_exitfunc[32];
स्थिर शून्य *rt_exitarg[32];
स्थिर पूर्णाङ्क __rt_nr_exit;

शून्य __run_on_exit(पूर्णाङ्क ret)
{
    पूर्णाङ्क n = __rt_nr_exit;
    जाव (n)
	--n, ((शून्य(*)(पूर्णाङ्क,शून्य*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

पूर्णाङ्क on_exit(शून्य *function, शून्य *arg)
{
    पूर्णाङ्क n = __rt_nr_exit;
    जइ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        प्रत्यागम 0;
    }
    प्रत्यागम 1;
}

पूर्णाङ्क atexit(शून्य (*function)(शून्य))
{
    प्रत्यागम on_exit(function, 0);
}

प्रकारनिर्देश संरचना rt_frame {
    शून्य *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) शून्य __rt_exit(rt_frame *, पूर्णाङ्क);

शून्य exit(पूर्णाङ्क code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
पूर्णाङ्क main(पूर्णाङ्क, वर्ण**, वर्ण**);

पूर्णाङ्क _runmain(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp)
{
    पूर्णाङ्क ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    प्रत्यागम ret;
}
#endif
