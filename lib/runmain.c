/* ------------------------------------------------------------- */
/* support for tcc_run() */

#جيڪڏهن_وصف_ٿيل __leading_underscore
# define _(s) s
#وإلا
# define _(s) _##s
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WIN32
خارجي فراغ (*_(init_array_شروعات)[]) (صحيح argc, حرف **argv, حرف **envp);
خارجي فراغ (*_(init_array_پڇاڙي)[]) (صحيح argc, حرف **argv, حرف **envp);
ساكن فراغ لاڳيتو_ctors(صحيح argc, حرف **argv, حرف **env)
{
    صحيح i = 0;
    طالما (&_(init_array_شروعات)[i] != _(init_array_پڇاڙي))
        (*_(init_array_شروعات)[i++])(argc, argv, env);
}
#جيڪڏهن_پورو

خارجي فراغ (*_(fini_array_شروعات)[]) (فراغ);
خارجي فراغ (*_(fini_array_پڇاڙي)[]) (فراغ);
ساكن فراغ لاڳيتو_dtors(فراغ)
{
    صحيح i = 0;
    طالما (&_(fini_array_پڇاڙي)[i] != _(fini_array_شروعات))
        (*_(fini_array_پڇاڙي)[--i])();
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

تعريفنوع بنية rt_چوکٺو {
    فراغ *ip, *fp, *sp;
} rt_چوکٺو;

__attribute__((noreturn)) فراغ __rt_exit(rt_چوکٺو *, صحيح);

فراغ ٻاهر_نڪرو(صحيح ڪوڊ)
{
    rt_چوکٺو f;
    لاڳيتو_dtors();
    __run_on_exit(ڪوڊ);
    f.fp = 0;
    f.ip = ٻاهر_نڪرو;
    __rt_exit(&f, ڪوڊ);
}

#جيڪڏهن_وصف_نه_ٿيل _WIN32
صحيح مکيه(صحيح, حرف**, حرف**);

صحيح _runmain(صحيح argc, حرف **argv, حرف **envp)
{
    صحيح ret;
    لاڳيتو_ctors(argc, argv, envp);
    ret = مکيه(argc, argv, envp);
    لاڳيتو_dtors();
    __run_on_exit(ret);
    أرجع ret;
}
#جيڪڏهن_پورو
