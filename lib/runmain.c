/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __leading_underscore
# define _(s) s
#ਨਹੀਂਤਾਂ
# define _(s) _##s
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
ਬਾਹਰੀ ਖਾਲੀ (*_(init_array_ਸ਼ੁਰੂ)[]) (ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **envp);
ਬਾਹਰੀ ਖਾਲੀ (*_(init_array_ਸਿਰਾ)[]) (ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **envp);
ਸਥਿਰ ਖਾਲੀ ਲੜੀਵਾਰ_ctors(ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **env)
{
    ਪੂਰਨ i = 0;
    ਜਦੋਂ (&_(init_array_ਸ਼ੁਰੂ)[i] != _(init_array_ਸਿਰਾ))
        (*_(init_array_ਸ਼ੁਰੂ)[i++])(argc, argv, env);
}
#ਜੇ_ਅੰਤ

ਬਾਹਰੀ ਖਾਲੀ (*_(fini_array_ਸ਼ੁਰੂ)[]) (ਖਾਲੀ);
ਬਾਹਰੀ ਖਾਲੀ (*_(fini_array_ਸਿਰਾ)[]) (ਖਾਲੀ);
ਸਥਿਰ ਖਾਲੀ ਲੜੀਵਾਰ_dtors(ਖਾਲੀ)
{
    ਪੂਰਨ i = 0;
    ਜਦੋਂ (&_(fini_array_ਸਿਰਾ)[i] != _(fini_array_ਸ਼ੁਰੂ))
        (*_(fini_array_ਸਿਰਾ)[--i])();
}

ਸਥਿਰ ਖਾਲੀ *rt_exitfunc[32];
ਸਥਿਰ ਖਾਲੀ *rt_exitarg[32];
ਸਥਿਰ ਪੂਰਨ __rt_nr_exit;

ਖਾਲੀ __run_on_exit(ਪੂਰਨ ret)
{
    ਪੂਰਨ n = __rt_nr_exit;
    ਜਦੋਂ (n)
	--n, ((ਖਾਲੀ(*)(ਪੂਰਨ,ਖਾਲੀ*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ਪੂਰਨ on_exit(ਖਾਲੀ *function, ਖਾਲੀ *arg)
{
    ਪੂਰਨ n = __rt_nr_exit;
    ਜੇ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ਵਾਪਸ 0;
    }
    ਵਾਪਸ 1;
}

ਪੂਰਨ atexit(ਖਾਲੀ (*function)(ਖਾਲੀ))
{
    ਵਾਪਸ on_exit(function, 0);
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ rt_ਚੌਖਟਾ {
    ਖਾਲੀ *ip, *fp, *sp;
} rt_ਚੌਖਟਾ;

__attribute__((noreturn)) ਖਾਲੀ __rt_exit(rt_ਚੌਖਟਾ *, ਪੂਰਨ);

ਖਾਲੀ ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ ਕੋਡ)
{
    rt_ਚੌਖਟਾ f;
    ਲੜੀਵਾਰ_dtors();
    __run_on_exit(ਕੋਡ);
    f.fp = 0;
    f.ip = ਬਾਹਰ_ਨਿਕਲੋ;
    __rt_exit(&f, ਕੋਡ);
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ, ਅੱਖਰ**, ਅੱਖਰ**);

ਪੂਰਨ _runmain(ਪੂਰਨ argc, ਅੱਖਰ **argv, ਅੱਖਰ **envp)
{
    ਪੂਰਨ ret;
    ਲੜੀਵਾਰ_ctors(argc, argv, envp);
    ret = ਮੁੱਖ(argc, argv, envp);
    ਲੜੀਵਾਰ_dtors();
    __run_on_exit(ret);
    ਵਾਪਸ ret;
}
#ਜੇ_ਅੰਤ
