/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#അല്ലെങ്കിൽ
# define _(s) _##s
#endif

#ifndef _WIN32
ബാഹ്യ ശൂന്യം (*_(_init_array_start)[]) (പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **envp);
ബാഹ്യ ശൂന്യം (*_(_init_array_end)[]) (പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **envp);
സ്ഥിതം ശൂന്യം run_ctors(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **env)
{
    പൂർണ്ണസംഖ്യ i = 0;
    ആകുമ്പോൾ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

ബാഹ്യ ശൂന്യം (*_(_fini_array_start)[]) (ശൂന്യം);
ബാഹ്യ ശൂന്യം (*_(_fini_array_end)[]) (ശൂന്യം);
സ്ഥിതം ശൂന്യം run_dtors(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i = 0;
    ആകുമ്പോൾ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

സ്ഥിതം ശൂന്യം *rt_exitfunc[32];
സ്ഥിതം ശൂന്യം *rt_exitarg[32];
സ്ഥിതം പൂർണ്ണസംഖ്യ __rt_nr_exit;

ശൂന്യം __run_on_exit(പൂർണ്ണസംഖ്യ ret)
{
    പൂർണ്ണസംഖ്യ n = __rt_nr_exit;
    ആകുമ്പോൾ (n)
	--n, ((ശൂന്യം(*)(പൂർണ്ണസംഖ്യ,ശൂന്യം*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

പൂർണ്ണസംഖ്യ on_exit(ശൂന്യം *function, ശൂന്യം *arg)
{
    പൂർണ്ണസംഖ്യ n = __rt_nr_exit;
    എങ്കിൽ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        തിരികെ 0;
    }
    തിരികെ 1;
}

പൂർണ്ണസംഖ്യ atexit(ശൂന്യം (*function)(ശൂന്യം))
{
    തിരികെ on_exit(function, 0);
}

തരനിർവചനം ഘടന rt_frame {
    ശൂന്യം *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) ശൂന്യം __rt_exit(rt_frame *, പൂർണ്ണസംഖ്യ);

ശൂന്യം exit(പൂർണ്ണസംഖ്യ code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ, അക്ഷരം**, അക്ഷരം**);

പൂർണ്ണസംഖ്യ _runmain(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv, അക്ഷരം **envp)
{
    പൂർണ്ണസംഖ്യ ret;
    run_ctors(argc, argv, envp);
    ret = പ്രധാന(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    തിരികെ ret;
}
#endif
