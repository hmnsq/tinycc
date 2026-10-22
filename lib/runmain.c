/* ------------------------------------------------------------- */
/* support for tcc_run() */

#నిర్వచితమైతే __leading_underscore
# define _(s) s
#లేకపోతే
# define _(s) _##s
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WIN32
బాహ్య శూన్య (*_(init_array_ప్రారంభం)[]) (పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **envp);
బాహ్య శూన్య (*_(init_array_చివర)[]) (పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **envp);
స్థిర శూన్య నిరంతరం_ctors(పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **env)
{
    పూర్ణాంకం i = 0;
    అయితే (&_(init_array_ప్రారంభం)[i] != _(init_array_చివర))
        (*_(init_array_ప్రారంభం)[i++])(argc, argv, env);
}
#అయితే_ముగింపు

బాహ్య శూన్య (*_(fini_array_ప్రారంభం)[]) (శూన్య);
బాహ్య శూన్య (*_(fini_array_చివర)[]) (శూన్య);
స్థిర శూన్య నిరంతరం_dtors(శూన్య)
{
    పూర్ణాంకం i = 0;
    అయితే (&_(fini_array_చివర)[i] != _(fini_array_ప్రారంభం))
        (*_(fini_array_చివర)[--i])();
}

స్థిర శూన్య *rt_exitfunc[32];
స్థిర శూన్య *rt_exitarg[32];
స్థిర పూర్ణాంకం __rt_nr_exit;

శూన్య __run_on_exit(పూర్ణాంకం ret)
{
    పూర్ణాంకం n = __rt_nr_exit;
    అయితే (n)
	--n, ((శూన్య(*)(పూర్ణాంకం,శూన్య*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

పూర్ణాంకం on_exit(శూన్య *function, శూన్య *arg)
{
    పూర్ణాంకం n = __rt_nr_exit;
    ఒకవేళ (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        తిరిగి 0;
    }
    తిరిగి 1;
}

పూర్ణాంకం atexit(శూన్య (*function)(శూన్య))
{
    తిరిగి on_exit(function, 0);
}

రకనిర్వచనం నిర్మాణం rt_చట్రం {
    శూన్య *ip, *fp, *sp;
} rt_చట్రం;

__attribute__((noreturn)) శూన్య __rt_exit(rt_చట్రం *, పూర్ణాంకం);

శూన్య నిష్క్రమించు(పూర్ణాంకం సంకేతం_2)
{
    rt_చట్రం f;
    నిరంతరం_dtors();
    __run_on_exit(సంకేతం_2);
    f.fp = 0;
    f.ip = నిష్క్రమించు;
    __rt_exit(&f, సంకేతం_2);
}

#నిర్వచితం_కాకపోతే _WIN32
పూర్ణాంకం ప్రధాన(పూర్ణాంకం, అక్షరం**, అక్షరం**);

పూర్ణాంకం _runmain(పూర్ణాంకం argc, అక్షరం **argv, అక్షరం **envp)
{
    పూర్ణాంకం ret;
    నిరంతరం_ctors(argc, argv, envp);
    ret = ప్రధాన(argc, argv, envp);
    నిరంతరం_dtors();
    __run_on_exit(ret);
    తిరిగి ret;
}
#అయితే_ముగింపు
