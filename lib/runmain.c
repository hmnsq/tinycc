/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#অন্যথা
# define _(s) _##s
#endif

#ifndef _WIN32
বাহ্যিক শূন্য (*_(_init_array_start)[]) (পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **envp);
বাহ্যিক শূন্য (*_(_init_array_end)[]) (পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **envp);
স্থির শূন্য run_ctors(পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **env)
{
    পূর্ণসংখ্যা i = 0;
    যখন (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

বাহ্যিক শূন্য (*_(_fini_array_start)[]) (শূন্য);
বাহ্যিক শূন্য (*_(_fini_array_end)[]) (শূন্য);
স্থির শূন্য run_dtors(শূন্য)
{
    পূর্ণসংখ্যা i = 0;
    যখন (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

স্থির শূন্য *rt_exitfunc[32];
স্থির শূন্য *rt_exitarg[32];
স্থির পূর্ণসংখ্যা __rt_nr_exit;

শূন্য __run_on_exit(পূর্ণসংখ্যা ret)
{
    পূর্ণসংখ্যা n = __rt_nr_exit;
    যখন (n)
	--n, ((শূন্য(*)(পূর্ণসংখ্যা,শূন্য*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

পূর্ণসংখ্যা on_exit(শূন্য *function, শূন্য *arg)
{
    পূর্ণসংখ্যা n = __rt_nr_exit;
    যদি (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ফেরত 0;
    }
    ফেরত 1;
}

পূর্ণসংখ্যা atexit(শূন্য (*function)(শূন্য))
{
    ফেরত on_exit(function, 0);
}

প্রকারলেখ কাঠামো rt_frame {
    শূন্য *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) শূন্য __rt_exit(rt_frame *, পূর্ণসংখ্যা);

শূন্য exit(পূর্ণসংখ্যা code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা, অক্ষর**, অক্ষর**);

পূর্ণসংখ্যা _runmain(পূর্ণসংখ্যা argc, অক্ষর **argv, অক্ষর **envp)
{
    পূর্ণসংখ্যা ret;
    run_ctors(argc, argv, envp);
    ret = প্রধান(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ফেরত ret;
}
#endif
