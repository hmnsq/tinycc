/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#નહીંતર
# define _(s) _##s
#endif

#ifndef _WIN32
બાહ્ય શૂન્ય (*_(_init_array_start)[]) (પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **envp);
બાહ્ય શૂન્ય (*_(_init_array_end)[]) (પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **envp);
સ્થિર શૂન્ય run_ctors(પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **env)
{
    પૂર્ણાંક i = 0;
    જ્યારે (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

બાહ્ય શૂન્ય (*_(_fini_array_start)[]) (શૂન્ય);
બાહ્ય શૂન્ય (*_(_fini_array_end)[]) (શૂન્ય);
સ્થિર શૂન્ય run_dtors(શૂન્ય)
{
    પૂર્ણાંક i = 0;
    જ્યારે (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

સ્થિર શૂન્ય *rt_exitfunc[32];
સ્થિર શૂન્ય *rt_exitarg[32];
સ્થિર પૂર્ણાંક __rt_nr_exit;

શૂન્ય __run_on_exit(પૂર્ણાંક ret)
{
    પૂર્ણાંક n = __rt_nr_exit;
    જ્યારે (n)
	--n, ((શૂન્ય(*)(પૂર્ણાંક,શૂન્ય*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

પૂર્ણાંક on_exit(શૂન્ય *function, શૂન્ય *arg)
{
    પૂર્ણાંક n = __rt_nr_exit;
    જો (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        પાછા 0;
    }
    પાછા 1;
}

પૂર્ણાંક atexit(શૂન્ય (*function)(શૂન્ય))
{
    પાછા on_exit(function, 0);
}

પ્રકારવ્યાખ્યા સંરચના rt_frame {
    શૂન્ય *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) શૂન્ય __rt_exit(rt_frame *, પૂર્ણાંક);

શૂન્ય exit(પૂર્ણાંક code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
પૂર્ણાંક મુખ્ય(પૂર્ણાંક, અક્ષર**, અક્ષર**);

પૂર્ણાંક _runmain(પૂર્ણાંક argc, અક્ષર **argv, અક્ષર **envp)
{
    પૂર્ણાંક ret;
    run_ctors(argc, argv, envp);
    ret = મુખ્ય(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    પાછા ret;
}
#endif
