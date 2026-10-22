/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#නැතහොත්
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (පූර්ණ_සංඛ්‍යා argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (පූර්ණ_සංඛ්‍යා argc, var_na **argv, var_na **envp);
static void run_ctors(පූර්ණ_සංඛ්‍යා argc, var_na **argv, var_na **env)
{
    පූර්ණ_සංඛ්‍යා i = 0;
    අතරතුර (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    පූර්ණ_සංඛ්‍යා i = 0;
    අතරතුර (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static පූර්ණ_සංඛ්‍යා __rt_nr_exit;

void __run_on_exit(පූර්ණ_සංඛ්‍යා ret)
{
    පූර්ණ_සංඛ්‍යා n = __rt_nr_exit;
    අතරතුර (n)
	--n, ((void(*)(පූර්ණ_සංඛ්‍යා,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

පූර්ණ_සංඛ්‍යා on_exit(void *function, void *arg)
{
    පූර්ණ_සංඛ්‍යා n = __rt_nr_exit;
    නම් (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ආපසු 0;
    }
    ආපසු 1;
}

පූර්ණ_සංඛ්‍යා atexit(void (*function)(void))
{
    ආපසු on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, පූර්ණ_සංඛ්‍යා);

void exit(පූර්ණ_සංඛ්‍යා code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා, var_na**, var_na**);

පූර්ණ_සංඛ්‍යා _runmain(පූර්ණ_සංඛ්‍යා argc, var_na **argv, var_na **envp)
{
    පූර්ණ_සංඛ්‍යා ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ආපසු ret;
}
#endif
