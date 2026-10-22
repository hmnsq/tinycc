puur_naa_nka tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ᤀᤡ᤺ DLL==1
__declspec(dllexport) puur_naa_nka f_1()
{
    hello();
    ᤀᤡᤴ 0;
}


#elif DLL==2
__declspec(dllexport) puur_naa_nka f_2()
{
    hello();
    ᤀᤡᤴ 0;
}


#ᤀᤡ᤺ᤆᤡ

puur_naa_nka f_1();
puur_naa_nka f_2();
puur_naa_nka f_main()
{
    hello();
    ᤀᤡᤴ 0;
}

puur_naa_nka main ()
{
    f_1();
    f_2();
    f_main();
    ᤀᤡᤴ 0;
}

#endif
