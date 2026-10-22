/* ------------------------------------------------------------- */
/* support for tcc_run() */

#اگر_تعریف_شده __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#پایان_اگر

#اگر_تعریف_نشده _WIN32
خارجي فراغ (*_(init_array_شروع)[]) (صحيح argc, حرف **argv, حرف **envp);
خارجي فراغ (*_(init_array_انتها)[]) (صحيح argc, حرف **argv, حرف **envp);
ساكن فراغ پیاپی_ctors(صحيح argc, حرف **argv, حرف **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروع)[i] != _(init_array_انتها))
        (*_(init_array_شروع)[i++])(argc, argv, env);
}
#پایان_اگر

خارجي فراغ (*_(fini_array_شروع)[]) (فراغ);
خارجي فراغ (*_(fini_array_انتها)[]) (فراغ);
ساكن فراغ پیاپی_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_انتها)[i] != _(fini_array_شروع))
        (*_(fini_array_انتها)[--i])();
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

تعريفنوع بنية rt_قاب {
    فراغ *ip, *fp, *sp;
} rt_قاب;

__attribute__((noreturn)) فراغ __rt_exit(rt_قاب *, صحيح);

فراغ خروج(صحيح کد)
{
    rt_قاب f;
    پیاپی_dtors();
    __run_on_exit(کد);
    f.fp = 0;
    f.ip = خروج;
    __rt_exit(&f, کد);
}

#اگر_تعریف_نشده _WIN32
صحيح اصلی(صحيح, حرف**, حرف**);

صحيح _runmain(صحيح argc, حرف **argv, حرف **envp)
{
    صحيح ret;
    پیاپی_ctors(argc, argv, envp);
    ret = اصلی(argc, argv, envp);
    پیاپی_dtors();
    __run_on_exit(ret);
    أرجع ret;
}
#پایان_اگر
