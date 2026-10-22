/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#បើមិនដូច្នេះ
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (ចំនួនគត់ argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (ចំនួនគត់ argc, var_na **argv, var_na **envp);
static void run_ctors(ចំនួនគត់ argc, var_na **argv, var_na **env)
{
    ចំនួនគត់ i = 0;
    ខណៈពេល (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    ចំនួនគត់ i = 0;
    ខណៈពេល (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static ចំនួនគត់ __rt_nr_exit;

void __run_on_exit(ចំនួនគត់ ret)
{
    ចំនួនគត់ n = __rt_nr_exit;
    ខណៈពេល (n)
	--n, ((void(*)(ចំនួនគត់,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ចំនួនគត់ on_exit(void *function, void *arg)
{
    ចំនួនគត់ n = __rt_nr_exit;
    ប្រសិនបើ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ត្រឡប់ 0;
    }
    ត្រឡប់ 1;
}

ចំនួនគត់ atexit(void (*function)(void))
{
    ត្រឡប់ on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, ចំនួនគត់);

void exit(ចំនួនគត់ code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ចំនួនគត់ main(ចំនួនគត់, var_na**, var_na**);

ចំនួនគត់ _runmain(ចំនួនគត់ argc, var_na **argv, var_na **envp)
{
    ចំនួនគត់ ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ត្រឡប់ ret;
}
#endif
