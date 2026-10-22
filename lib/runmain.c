/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#དེ་མིན
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (ཧྲིལ argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (ཧྲིལ argc, var_na **argv, var_na **envp);
static void run_ctors(ཧྲིལ argc, var_na **argv, var_na **env)
{
    ཧྲིལ i = 0;
    སྐབས (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    ཧྲིལ i = 0;
    སྐབས (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static ཧྲིལ __rt_nr_exit;

void __run_on_exit(ཧྲིལ ret)
{
    ཧྲིལ n = __rt_nr_exit;
    སྐབས (n)
	--n, ((void(*)(ཧྲིལ,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ཧྲིལ on_exit(void *function, void *arg)
{
    ཧྲིལ n = __rt_nr_exit;
    གལ་ཏེ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ཕྱིར 0;
    }
    ཕྱིར 1;
}

ཧྲིལ atexit(void (*function)(void))
{
    ཕྱིར on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, ཧྲིལ);

void exit(ཧྲིལ code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ཧྲིལ གཙོ(ཧྲིལ, var_na**, var_na**);

ཧྲིལ _runmain(ཧྲིལ argc, var_na **argv, var_na **envp)
{
    ཧྲིལ ret;
    run_ctors(argc, argv, envp);
    ret = གཙོ(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ཕྱིར ret;
}
#endif
