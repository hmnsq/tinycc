/* ------------------------------------------------------------- */
/* support for tcc_run() */

#جے_تعریف_شدہ __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#جے_انت

#جے_بنا_تعریف _WIN32
خارجي فراغ (*_(init_array_شروع)[]) (صحيح argc, حرف **argv, حرف **envp);
خارجي فراغ (*_(init_array_سرا)[]) (صحيح argc, حرف **argv, حرف **envp);
ساكن فراغ لگاتار_ctors(صحيح argc, حرف **argv, حرف **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروع)[i] != _(init_array_سرا))
        (*_(init_array_شروع)[i++])(argc, argv, env);
}
#جے_انت

خارجي فراغ (*_(fini_array_شروع)[]) (فراغ);
خارجي فراغ (*_(fini_array_سرا)[]) (فراغ);
ساكن فراغ لگاتار_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_سرا)[i] != _(fini_array_شروع))
        (*_(fini_array_سرا)[--i])();
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

تعريفنوع بنية rt_چوکھٹا {
    فراغ *ip, *fp, *sp;
} rt_چوکھٹا;

__attribute__((noreturn)) فراغ __rt_exit(rt_چوکھٹا *, صحيح);

فراغ باہر_نکلو(صحيح کوڈ)
{
    rt_چوکھٹا f;
    لگاتار_dtors();
    __run_on_exit(کوڈ);
    f.fp = 0;
    f.ip = باہر_نکلو;
    __rt_exit(&f, کوڈ);
}

#جے_بنا_تعریف _WIN32
صحيح مکھ(صحيح, حرف**, حرف**);

صحيح _runmain(صحيح argc, حرف **argv, حرف **envp)
{
    صحيح ret;
    لگاتار_ctors(argc, argv, envp);
    ret = مکھ(argc, argv, envp);
    لگاتار_dtors();
    __run_on_exit(ret);
    أرجع ret;
}
#جے_انت
