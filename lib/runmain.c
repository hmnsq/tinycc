/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#інакше
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (ціле argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (ціле argc, char **argv, char **envp);
static void run_ctors(ціле argc, char **argv, char **env)
{
    ціле i = 0;
    поки (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    ціле i = 0;
    поки (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static ціле __rt_nr_exit;

void __run_on_exit(ціле ret)
{
    ціле n = __rt_nr_exit;
    поки (n)
	--n, ((void(*)(ціле,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ціле on_exit(void *function, void *arg)
{
    ціле n = __rt_nr_exit;
    якщо (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        повернути 0;
    }
    повернути 1;
}

ціле atexit(void (*function)(void))
{
    повернути on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, ціле);

void exit(ціле code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ціле main(ціле, char**, char**);

ціле _runmain(ціле argc, char **argv, char **envp)
{
    ціле ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    повернути ret;
}
#endif
