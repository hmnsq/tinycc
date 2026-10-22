/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#инако
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (цео argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (цео argc, char **argv, char **envp);
static void run_ctors(цео argc, char **argv, char **env)
{
    цео i = 0;
    док (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    цео i = 0;
    док (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static цео __rt_nr_exit;

void __run_on_exit(цео ret)
{
    цео n = __rt_nr_exit;
    док (n)
	--n, ((void(*)(цео,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

цео on_exit(void *function, void *arg)
{
    цео n = __rt_nr_exit;
    ако (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        врати 0;
    }
    врати 1;
}

цео atexit(void (*function)(void))
{
    врати on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, цео);

void exit(цео code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
цео main(цео, char**, char**);

цео _runmain(цео argc, char **argv, char **envp)
{
    цео ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    врати ret;
}
#endif
