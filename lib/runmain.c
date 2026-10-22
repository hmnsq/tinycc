/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#иначе
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (целое argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (целое argc, char **argv, char **envp);
static void run_ctors(целое argc, char **argv, char **env)
{
    целое i = 0;
    пока (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    целое i = 0;
    пока (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static целое __rt_nr_exit;

void __run_on_exit(целое ret)
{
    целое n = __rt_nr_exit;
    пока (n)
	--n, ((void(*)(целое,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

целое on_exit(void *function, void *arg)
{
    целое n = __rt_nr_exit;
    если (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        вернуть 0;
    }
    вернуть 1;
}

целое atexit(void (*function)(void))
{
    вернуть on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, целое);

void exit(целое code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
целое основной(целое, char**, char**);

целое _runmain(целое argc, char **argv, char **envp)
{
    целое ret;
    run_ctors(argc, argv, envp);
    ret = основной(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    вернуть ret;
}
#endif
