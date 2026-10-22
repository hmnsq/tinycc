/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#иначе
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (цяло argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (цяло argc, char **argv, char **envp);
static void run_ctors(цяло argc, char **argv, char **env)
{
    цяло i = 0;
    докато (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    цяло i = 0;
    докато (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static цяло __rt_nr_exit;

void __run_on_exit(цяло ret)
{
    цяло n = __rt_nr_exit;
    докато (n)
	--n, ((void(*)(цяло,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

цяло on_exit(void *function, void *arg)
{
    цяло n = __rt_nr_exit;
    ако (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        върни 0;
    }
    върни 1;
}

цяло atexit(void (*function)(void))
{
    върни on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, цяло);

void exit(цяло code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
цяло main(цяло, char**, char**);

цяло _runmain(цяло argc, char **argv, char **envp)
{
    цяло ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    върни ret;
}
#endif
