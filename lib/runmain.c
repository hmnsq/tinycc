/* ------------------------------------------------------------- */
/* support for tcc_run() */

#اگر_تعریف_شدہ __leading_underscore
# define _(s) s
#ورنہ
# define _(s) _##s
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WIN32
خارجی خالی (*_(init_array_آغاز)[]) (صحیح argc, حرف **argv, حرف **envp);
خارجی خالی (*_(init_array_انتہا)[]) (صحیح argc, حرف **argv, حرف **envp);
ساکن خالی تسلسل_ctors(صحیح argc, حرف **argv, حرف **env)
{
    صحیح i = 0;
    جب (&_(init_array_آغاز)[i] != _(init_array_انتہا))
        (*_(init_array_آغاز)[i++])(argc, argv, env);
}
#اگر_ختم

خارجی خالی (*_(fini_array_آغاز)[]) (خالی);
خارجی خالی (*_(fini_array_انتہا)[]) (خالی);
ساکن خالی تسلسل_dtors(خالی)
{
    صحیح i = 0;
    جب (&_(fini_array_انتہا)[i] != _(fini_array_آغاز))
        (*_(fini_array_انتہا)[--i])();
}

ساکن خالی *rt_exitfunc[32];
ساکن خالی *rt_exitarg[32];
ساکن صحیح __rt_nr_exit;

خالی __run_on_exit(صحیح ret)
{
    صحیح n = __rt_nr_exit;
    جب (n)
	--n, ((خالی(*)(صحیح,خالی*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

صحیح on_exit(خالی *function, خالی *arg)
{
    صحیح n = __rt_nr_exit;
    اگر (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        واپس 0;
    }
    واپس 1;
}

صحیح atexit(خالی (*function)(خالی))
{
    واپس on_exit(function, 0);
}

قسمتعریف ساخت rt_چوکھٹا {
    خالی *ip, *fp, *sp;
} rt_چوکھٹا;

__attribute__((noreturn)) خالی __rt_exit(rt_چوکھٹا *, صحیح);

خالی باہر_نکلو(صحیح رمز)
{
    rt_چوکھٹا f;
    تسلسل_dtors();
    __run_on_exit(رمز);
    f.fp = 0;
    f.ip = باہر_نکلو;
    __rt_exit(&f, رمز);
}

#اگر_غیر_تعریف_شدہ _WIN32
صحیح مین(صحیح, حرف**, حرف**);

صحیح _runmain(صحیح argc, حرف **argv, حرف **envp)
{
    صحیح ret;
    تسلسل_ctors(argc, argv, envp);
    ret = مین(argc, argv, envp);
    تسلسل_dtors();
    __run_on_exit(ret);
    واپس ret;
}
#اگر_ختم
