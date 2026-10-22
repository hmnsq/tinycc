/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#ᯀᯮᯝᯂᯪ
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (puur_naa_nka argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (puur_naa_nka argc, var_na **argv, var_na **envp);
static void run_ctors(puur_naa_nka argc, var_na **argv, var_na **env)
{
    puur_naa_nka i = 0;
    ᯀᯬᯝ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    puur_naa_nka i = 0;
    ᯀᯬᯝ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static puur_naa_nka __rt_nr_exit;

void __run_on_exit(puur_naa_nka ret)
{
    puur_naa_nka n = __rt_nr_exit;
    ᯀᯬᯝ (n)
	--n, ((void(*)(puur_naa_nka,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

puur_naa_nka on_exit(void *function, void *arg)
{
    puur_naa_nka n = __rt_nr_exit;
    ᯀᯮᯝ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ᯀᯮᯞ 0;
    }
    ᯀᯮᯞ 1;
}

puur_naa_nka atexit(void (*function)(void))
{
    ᯀᯮᯞ on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, puur_naa_nka);

void exit(puur_naa_nka code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
puur_naa_nka main(puur_naa_nka, var_na**, var_na**);

puur_naa_nka _runmain(puur_naa_nka argc, var_na **argv, var_na **envp)
{
    puur_naa_nka ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ᯀᯮᯞ ret;
}
#endif
