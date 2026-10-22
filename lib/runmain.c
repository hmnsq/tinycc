/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#否则
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (整数 argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (整数 argc, char **argv, char **envp);
static void run_ctors(整数 argc, char **argv, char **env)
{
    整数 i = 0;
    ながら (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    整数 i = 0;
    ながら (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static 整数 __rt_nr_exit;

void __run_on_exit(整数 ret)
{
    整数 n = __rt_nr_exit;
    ながら (n)
	--n, ((void(*)(整数,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

整数 on_exit(void *function, void *arg)
{
    整数 n = __rt_nr_exit;
    もし (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        戻る 0;
    }
    戻る 1;
}

整数 atexit(void (*function)(void))
{
    戻る on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, 整数);

void exit(整数 code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
整数 メインページ(整数, char**, char**);

整数 _runmain(整数 argc, char **argv, char **envp)
{
    整数 ret;
    run_ctors(argc, argv, envp);
    ret = メインページ(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    戻る ret;
}
#endif
