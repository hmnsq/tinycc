/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#অন্যথা
# define _(s) _##s
#endif

#ifndef _WIN32
বাহ্য শূন্য (*_(_init_array_start)[]) (পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **envp);
বাহ্য শূন্য (*_(_init_array_end)[]) (পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **envp);
স্থির শূন্য run_ctors(পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **env)
{
    পূর্ণাঙ্ক i = 0;
    যেতিয়ালৈ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

বাহ্য শূন্য (*_(_fini_array_start)[]) (শূন্য);
বাহ্য শূন্য (*_(_fini_array_end)[]) (শূন্য);
স্থির শূন্য run_dtors(শূন্য)
{
    পূর্ণাঙ্ক i = 0;
    যেতিয়ালৈ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

স্থির শূন্য *rt_exitfunc[32];
স্থির শূন্য *rt_exitarg[32];
স্থির পূর্ণাঙ্ক __rt_nr_exit;

শূন্য __run_on_exit(পূর্ণাঙ্ক ret)
{
    পূর্ণাঙ্ক n = __rt_nr_exit;
    যেতিয়ালৈ (n)
	--n, ((শূন্য(*)(পূর্ণাঙ্ক,শূন্য*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

পূর্ণাঙ্ক on_exit(শূন্য *function, শূন্য *arg)
{
    পূর্ণাঙ্ক n = __rt_nr_exit;
    যদি (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ঘূৰাই 0;
    }
    ঘূৰাই 1;
}

পূর্ণাঙ্ক atexit(শূন্য (*function)(শূন্য))
{
    ঘূৰাই on_exit(function, 0);
}

প্রকারনির্দেশ সংরচনা rt_frame {
    শূন্য *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) শূন্য __rt_exit(rt_frame *, পূর্ণাঙ্ক);

শূন্য exit(পূর্ণাঙ্ক code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
পূর্ণাঙ্ক main(পূর্ণাঙ্ক, ৱর্ণ**, ৱর্ণ**);

পূর্ণাঙ্ক _runmain(পূর্ণাঙ্ক argc, ৱর্ণ **argv, ৱর্ণ **envp)
{
    পূর্ণাঙ্ক ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ঘূৰাই ret;
}
#endif
