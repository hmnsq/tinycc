/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#ଅନ୍ୟଥା
# define _(s) _##s
#endif

#ifndef _WIN32
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_init_array_start)[]) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **envp);
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_init_array_end)[]) (ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **envp);
ସ୍ଥିର ଶୂନ୍ୟ run_ctors(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **env)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ଯେତେବେଳେ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

ବାହ୍ୟ ଶୂନ୍ୟ (*_(_fini_array_start)[]) (ଶୂନ୍ୟ);
ବାହ୍ୟ ଶୂନ୍ୟ (*_(_fini_array_end)[]) (ଶୂନ୍ୟ);
ସ୍ଥିର ଶୂନ୍ୟ run_dtors(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ଯେତେବେଳେ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

ସ୍ଥିର ଶୂନ୍ୟ *rt_exitfunc[32];
ସ୍ଥିର ଶୂନ୍ୟ *rt_exitarg[32];
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା __rt_nr_exit;

ଶୂନ୍ୟ __run_on_exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = __rt_nr_exit;
    ଯେତେବେଳେ (n)
	--n, ((ଶୂନ୍ୟ(*)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଶୂନ୍ୟ*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା on_exit(ଶୂନ୍ୟ *function, ଶୂନ୍ୟ *arg)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = __rt_nr_exit;
    ଯଦି (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ଫେରନ୍ତୁ 0;
    }
    ଫେରନ୍ତୁ 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା atexit(ଶୂନ୍ୟ (*function)(ଶୂନ୍ୟ))
{
    ଫେରନ୍ତୁ on_exit(function, 0);
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା rt_frame {
    ଶୂନ୍ୟ *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) ଶୂନ୍ୟ __rt_exit(rt_frame *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

ଶୂନ୍ୟ exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଅକ୍ଷର**, ଅକ୍ଷର**);

ପୂର୍ଣ୍ଣସଂଖ୍ୟା _runmain(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv, ଅକ୍ଷର **envp)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
    run_ctors(argc, argv, envp);
    ret = ମୁଖ୍ୟ(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ଫେରନ୍ତୁ ret;
}
#endif
