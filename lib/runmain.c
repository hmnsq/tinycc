/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#มิฉะนั้น
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (จำนวนเต็ม argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (จำนวนเต็ม argc, var_na **argv, var_na **envp);
static void run_ctors(จำนวนเต็ม argc, var_na **argv, var_na **env)
{
    จำนวนเต็ม i = 0;
    ขณะ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    จำนวนเต็ม i = 0;
    ขณะ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static จำนวนเต็ม __rt_nr_exit;

void __run_on_exit(จำนวนเต็ม ret)
{
    จำนวนเต็ม n = __rt_nr_exit;
    ขณะ (n)
	--n, ((void(*)(จำนวนเต็ม,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

จำนวนเต็ม on_exit(void *function, void *arg)
{
    จำนวนเต็ม n = __rt_nr_exit;
    ถ้า (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        คืน 0;
    }
    คืน 1;
}

จำนวนเต็ม atexit(void (*function)(void))
{
    คืน on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, จำนวนเต็ม);

void exit(จำนวนเต็ม code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
จำนวนเต็ม หลัก(จำนวนเต็ม, var_na**, var_na**);

จำนวนเต็ม _runmain(จำนวนเต็ม argc, var_na **argv, var_na **envp)
{
    จำนวนเต็ม ret;
    run_ctors(argc, argv, envp);
    ret = หลัก(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    คืน ret;
}
#endif
