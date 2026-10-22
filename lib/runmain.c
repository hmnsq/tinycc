/* ------------------------------------------------------------- */
/* support for tcc_run() */

#ifdef __leading_underscore
# define _(s) s
#இல்லையெனில்
# define _(s) _##s
#endif

#ifndef _WIN32
வெளி வெறுமை (*_(_init_array_start)[]) (முழு argc, எழுத்து **argv, எழுத்து **envp);
வெளி வெறுமை (*_(_init_array_end)[]) (முழு argc, எழுத்து **argv, எழுத்து **envp);
நிலையான வெறுமை run_ctors(முழு argc, எழுத்து **argv, எழுத்து **env)
{
    முழு i = 0;
    போது (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#endif

வெளி வெறுமை (*_(_fini_array_start)[]) (வெறுமை);
வெளி வெறுமை (*_(_fini_array_end)[]) (வெறுமை);
நிலையான வெறுமை run_dtors(வெறுமை)
{
    முழு i = 0;
    போது (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

நிலையான வெறுமை *rt_exitfunc[32];
நிலையான வெறுமை *rt_exitarg[32];
நிலையான முழு __rt_nr_exit;

வெறுமை __run_on_exit(முழு ret)
{
    முழு n = __rt_nr_exit;
    போது (n)
	--n, ((வெறுமை(*)(முழு,வெறுமை*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

முழு on_exit(வெறுமை *function, வெறுமை *arg)
{
    முழு n = __rt_nr_exit;
    எனில் (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        திரும்பு 0;
    }
    திரும்பு 1;
}

முழு atexit(வெறுமை (*function)(வெறுமை))
{
    திரும்பு on_exit(function, 0);
}

வகைவரை கட்டமைப்பு rt_frame {
    வெறுமை *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) வெறுமை __rt_exit(rt_frame *, முழு);

வெறுமை exit(முழு code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = exit;
    __rt_exit(&f, code);
}

#ifndef _WIN32
முழு முதன்மை(முழு, எழுத்து**, எழுத்து**);

முழு _runmain(முழு argc, எழுத்து **argv, எழுத்து **envp)
{
    முழு ret;
    run_ctors(argc, argv, envp);
    ret = முதன்மை(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    திரும்பு ret;
}
#endif
