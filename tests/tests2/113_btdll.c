puur_naa_nka tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ᬬᬾᬦ᭄ DLL==1
__declspec(dllexport) puur_naa_nka f_1()
{
    hello();
    ᬯᬮᬶ 0;
}


#elif DLL==2
__declspec(dllexport) puur_naa_nka f_2()
{
    hello();
    ᬯᬮᬶ 0;
}


#ᬮᬶᬬ

puur_naa_nka f_1();
puur_naa_nka f_2();
puur_naa_nka f_main()
{
    hello();
    ᬯᬮᬶ 0;
}

puur_naa_nka main ()
{
    f_1();
    f_2();
    f_main();
    ᬯᬮᬶ 0;
}

#endif
