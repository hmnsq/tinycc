/* ------------------------------------------------------------- */
/* support for tcc_run() */

#यदि_परिभाषितम् __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#यदि_अन्तः

#यदि_अपरिभाषितम् _WIN32
बाह्य शून्य (*_(_init_array_start)[]) (पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
बाह्य शून्य (*_(init_array_अन्तः)[]) (पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp);
स्थिर शून्य सततम्_ctors(पूर्णाङ्क argc, वर्ण **argv, वर्ण **env)
{
    पूर्णाङ्क i = 0;
    यावत् (&_(_init_array_start)[i] != _(init_array_अन्तः))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#यदि_अन्तः

बाह्य शून्य (*_(_fini_array_start)[]) (शून्य);
बाह्य शून्य (*_(fini_array_अन्तः)[]) (शून्य);
स्थिर शून्य सततम्_dtors(शून्य)
{
    पूर्णाङ्क i = 0;
    यावत् (&_(fini_array_अन्तः)[i] != _(_fini_array_start))
        (*_(fini_array_अन्तः)[--i])();
}

स्थिर शून्य *rt_exitfunc[32];
स्थिर शून्य *rt_exitarg[32];
स्थिर पूर्णाङ्क __rt_nr_exit;

शून्य __run_on_exit(पूर्णाङ्क ret)
{
    पूर्णाङ्क n = __rt_nr_exit;
    यावत् (n)
	--n, ((शून्य(*)(पूर्णाङ्क,शून्य*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

पूर्णाङ्क on_exit(शून्य *function, शून्य *arg)
{
    पूर्णाङ्क n = __rt_nr_exit;
    यदि (n < 32) {
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

शून्य निर्गच्छ(पूर्णाङ्क संहिता)
{
    rt_frame f;
    सततम्_dtors();
    __run_on_exit(संहिता);
    f.fp = 0;
    f.ip = निर्गच्छ;
    __rt_exit(&f, संहिता);
}

#यदि_अपरिभाषितम् _WIN32
पूर्णाङ्क मुख्यम्(पूर्णाङ्क, वर्ण**, वर्ण**);

पूर्णाङ्क _runmain(पूर्णाङ्क argc, वर्ण **argv, वर्ण **envp)
{
    पूर्णाङ्क ret;
    सततम्_ctors(argc, argv, envp);
    ret = मुख्यम्(argc, argv, envp);
    सततम्_dtors();
    __run_on_exit(ret);
    प्रत्यागम ret;
}
#यदि_अन्तः
