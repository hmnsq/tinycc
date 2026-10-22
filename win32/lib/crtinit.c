//+---------------------------------------------------------------------------

#నిర్వచితమైతే __leading_underscore
# define _(s) s
#లేకపోతే
# define _(s) _##s
#అయితే_ముగింపు

బాహ్య శూన్య (*_(init_array_ప్రారంభం)[]) (పూర్ణాంకం argc, _TCHAR **argv, _TCHAR **envp);
బాహ్య శూన్య (*_(init_array_చివర)[]) (పూర్ణాంకం argc, _TCHAR **argv, _TCHAR **envp);
బాహ్య శూన్య (*_(fini_array_ప్రారంభం)[]) (శూన్య);
బాహ్య శూన్య (*_(fini_array_చివర)[]) (శూన్య);

స్థిర శూన్య నిరంతరం_ctors(పూర్ణాంకం argc, _TCHAR **argv, _TCHAR **env)
{
    పూర్ణాంకం i = 0;
    అయితే (&_(init_array_ప్రారంభం)[i] != _(init_array_చివర))
        (*_(init_array_ప్రారంభం)[i++])(argc, argv, env);
}

స్థిర శూన్య నిరంతరం_dtors(శూన్య)
{
    పూర్ణాంకం i = 0;
    అయితే (&_(fini_array_చివర)[i] != _(fini_array_ప్రారంభం))
        (*_(fini_array_చివర)[--i])();
}
