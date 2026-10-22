/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#endif

#ifndef _WIN32
خارجي فراغ (*_(_init_array_start)[]) (صحيح argc, حرف **argv, حرف **envp);
خارجي فراغ (*_(_init_array_end)[]) (صحيح argc, حرف **argv, حرف **envp);
ساكن فراغ run_ctors(صحيح argc, حرف **argv, حرف **env)
{
    صحيح i = 0;
    طالما (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

خارجي فراغ (*_(_fini_array_start)[]) (فراغ);
خارجي فراغ (*_(_fini_array_end)[]) (فراغ);
ساكن فراغ run_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
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
    𐡄𐡍 (n < 32) {
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

تعريفنوع بنية rt_frame {
    فراغ *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) فراغ __rt_exit(rt_frame *, صحيح);

فراغ exit(صحيح code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
صحيح main(صحيح, حرف**, حرف**);

صحيح _runmain(صحيح argc, حرف **argv, حرف **envp)
{
    صحيح ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    أرجع ret;
}
#endif
