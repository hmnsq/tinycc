/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#မဟုတ်ပါက
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (ကိန်းပြည့် argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (ကိန်းပြည့် argc, var_na **argv, var_na **envp);
static void run_ctors(ကိန်းပြည့် argc, var_na **argv, var_na **env)
{
    ကိန်းပြည့် i = 0;
    နေစဉ် (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    ကိန်းပြည့် i = 0;
    နေစဉ် (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static ကိန်းပြည့် __rt_nr_exit;

void __run_on_exit(ကိန်းပြည့် ret)
{
    ကိန်းပြည့် n = __rt_nr_exit;
    နေစဉ် (n)
	--n, ((void(*)(ကိန်းပြည့်,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ကိန်းပြည့် on_exit(void *function, void *arg)
{
    ကိန်းပြည့် n = __rt_nr_exit;
    အကယ်၍ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ပြန်ပေး 0;
    }
    ပြန်ပေး 1;
}

ကိန်းပြည့် atexit(void (*function)(void))
{
    ပြန်ပေး on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, ကိန်းပြည့်);

void exit(ကိန်းပြည့် code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ကိန်းပြည့် main(ကိန်းပြည့်, var_na**, var_na**);

ကိန်းပြည့် _runmain(ကိန်းပြည့် argc, var_na **argv, var_na **envp)
{
    ကိန်းပြည့် ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ပြန်ပေး ret;
}
#endif
