/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#không_thì
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (số_nguyên argc, char **argv, char **envp);
extern void (*_(_init_array_end)[]) (số_nguyên argc, char **argv, char **envp);
static void run_ctors(số_nguyên argc, char **argv, char **env)
{
    số_nguyên i = 0;
    trong_khi (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    số_nguyên i = 0;
    trong_khi (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static số_nguyên __rt_nr_exit;

void __run_on_exit(số_nguyên ret)
{
    số_nguyên n = __rt_nr_exit;
    trong_khi (n)
	--n, ((void(*)(số_nguyên,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

số_nguyên on_exit(void *function, void *arg)
{
    số_nguyên n = __rt_nr_exit;
    nếu (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        trả_về 0;
    }
    trả_về 1;
}

số_nguyên atexit(void (*function)(void))
{
    trả_về on_exit(function, 0);
}

typedef struct rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, số_nguyên);

void exit(số_nguyên code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
số_nguyên main(số_nguyên, char**, char**);

số_nguyên _runmain(số_nguyên argc, char **argv, char **envp)
{
    số_nguyên ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    trả_về ret;
}
#endif
