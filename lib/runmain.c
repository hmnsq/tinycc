/* ------------------------------------------------------------- */
/* support for tcc_run() */

#که_تعریف_شوی __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#د_که_پای

#که_نه_تعریف_شوی _WIN32
خارجي فراغ (*_(init_array_پیل)[]) (صحيح argc, حرف **argv, حرف **envp);
خارجي فراغ (*_(init_array_پای_ټکی)[]) (صحيح argc, حرف **argv, حرف **envp);
ساكن فراغ پرلپسې_ctors(صحيح argc, حرف **argv, حرف **env)
{
    صحيح i = 0;
    طالما (&_(init_array_پیل)[i] != _(init_array_پای_ټکی))
        (*_(init_array_پیل)[i++])(argc, argv, env);
}
#د_که_پای

خارجي فراغ (*_(fini_array_پیل)[]) (فراغ);
خارجي فراغ (*_(fini_array_پای_ټکی)[]) (فراغ);
ساكن فراغ پرلپسې_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_پای_ټکی)[i] != _(fini_array_پیل))
        (*_(fini_array_پای_ټکی)[--i])();
}

ساكن فراغ *rt_exitfunc[32];
ساكن فراغ *rt_exitarg[32];
ساكن صحيح __rt_nr_exit;

فراغ __run_on_exit(صحيح ret)
{
    صحيح n = __rt_nr_exit;
    طالما (n)
	--n, ((فراغ(*)(صحيح,فراغ*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

صحيح on_exit(فراغ *function, فراغ *arg)
{
    صحيح n = __rt_nr_exit;
    إذا (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        أرجع 0;
    }
    أرجع 1;
}

صحيح atexit(فراغ (*function)(فراغ))
{
    أرجع on_exit(function, 0);
}

تعريفنوع بنية rt_چوکاټ {
    فراغ *ip, *fp, *sp;
} rt_چوکاټ;

__attribute__((noreturn)) فراغ __rt_exit(rt_چوکاټ *, صحيح);

فراغ وتل(صحيح کوډ)
{
    rt_چوکاټ f;
    پرلپسې_dtors();
    __run_on_exit(کوډ);
    f.fp = 0;
    f.ip = وتل;
    __rt_exit(&f, کوډ);
}

#که_نه_تعریف_شوی _WIN32
صحيح اصلي(صحيح, حرف**, حرف**);

صحيح _runmain(صحيح argc, حرف **argv, حرف **envp)
{
    صحيح ret;
    پرلپسې_ctors(argc, argv, envp);
    ret = اصلي(argc, argv, envp);
    پرلپسې_dtors();
    __run_on_exit(ret);
    أرجع ret;
}
#د_که_پای
