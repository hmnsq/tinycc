/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#وگرنه
# define _(s) _##s
#endif

#ifndef _WIN32
بیرونی تهی (*_(_init_array_start)[]) (صحیح argc, نویسه **argv, نویسه **envp);
بیرونی تهی (*_(_init_array_end)[]) (صحیح argc, نویسه **argv, نویسه **envp);
ایستا تهی run_ctors(صحیح argc, نویسه **argv, نویسه **env)
{
    صحیح i = 0;
    وقتی (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

بیرونی تهی (*_(_fini_array_start)[]) (تهی);
بیرونی تهی (*_(_fini_array_end)[]) (تهی);
ایستا تهی run_dtors(تهی)
{
    صحیح i = 0;
    وقتی (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

ایستا تهی *rt_exitfunc[32];
ایستا تهی *rt_exitarg[32];
ایستا صحیح __rt_nr_exit;

تهی __run_on_exit(صحیح ret)
{
    صحیح n = __rt_nr_exit;
    وقتی (n)
	--n, ((تهی(*)(صحیح,تهی*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

صحیح on_exit(تهی *function, تهی *arg)
{
    صحیح n = __rt_nr_exit;
    اگر (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        بازگشت 0;
    }
    بازگشت 1;
}

صحیح atexit(تهی (*function)(تهی))
{
    بازگشت on_exit(function, 0);
}

تعریفنوع ساختار rt_frame {
    تهی *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) تهی __rt_exit(rt_frame *, صحیح);

تهی exit(صحیح code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
صحیح اصلی(صحیح, نویسه**, نویسه**);

صحیح _runmain(صحیح argc, نویسه **argv, نویسه **envp)
{
    صحیح ret;
    run_ctors(argc, argv, envp);
    ret = اصلی(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    بازگشت ret;
}
#endif
