/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#ບໍ່ດັ່ງນັ້ນ
# define _(s) _##s
#endif

#ifndef _WIN32
extern void (*_(_init_array_start)[]) (ຈຳນວນເຕັມ argc, var_na **argv, var_na **envp);
extern void (*_(_init_array_end)[]) (ຈຳນວນເຕັມ argc, var_na **argv, var_na **envp);
static void run_ctors(ຈຳນວນເຕັມ argc, var_na **argv, var_na **env)
{
    ຈຳນວນເຕັມ i = 0;
    ໃນຂະນະທີ່ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);
static void run_dtors(void)
{
    ຈຳນວນເຕັມ i = 0;
    ໃນຂະນະທີ່ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

static void *rt_exitfunc[32];
static void *rt_exitarg[32];
static ຈຳນວນເຕັມ __rt_nr_exit;

void __run_on_exit(ຈຳນວນເຕັມ ret)
{
    ຈຳນວນເຕັມ n = __rt_nr_exit;
    ໃນຂະນະທີ່ (n)
	--n, ((void(*)(ຈຳນວນເຕັມ,void*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

ຈຳນວນເຕັມ on_exit(void *function, void *arg)
{
    ຈຳນວນເຕັມ n = __rt_nr_exit;
    ຖ້າ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        ສົ່ງຄືນ 0;
    }
    ສົ່ງຄືນ 1;
}

ຈຳນວນເຕັມ atexit(void (*function)(void))
{
    ສົ່ງຄືນ on_exit(function, 0);
}

typedef sa_nracanaa rt_frame {
    void *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) void __rt_exit(rt_frame *, ຈຳນວນເຕັມ);

void exit(ຈຳນວນເຕັມ code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ, var_na**, var_na**);

ຈຳນວນເຕັມ _runmain(ຈຳນວນເຕັມ argc, var_na **argv, var_na **envp)
{
    ຈຳນວນເຕັມ ret;
    run_ctors(argc, argv, envp);
    ret = main(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    ສົ່ງຄືນ ret;
}
#endif
