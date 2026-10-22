/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#아니면
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (정수 argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (정수 argc, char **argv, char **envp);
static void run_ctors(정수 argc, char **argv, char **env)
{
    정수 i = 0;
    동안 (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    정수 i = 0;
    동안 (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static 정수 __rt_nr_exit;

void __run_on_exit(정수 ret)
{
    정수 n = __rt_nr_exit;
    동안 (n)
	--n, ((void(*)(정수,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

정수 on_exit(void *function, void *arg)
{
    정수 n = __rt_nr_exit;
    만약 (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        반환 0;
    }
    반환 1;
}

정수 atexit(void (*function)(void))
{
    반환 on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, 정수);

void exit(정수 code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
정수 main(정수, char**, char**);

정수 _runmain(정수 argc, char **argv, char **envp)
{
    정수 ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    반환 ret;
}
#endif
