പൂർണ്ണസംഖ്യ tcc_backtrace(സ്ഥിരം അക്ഷരം*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#എങ്കിൽ DLL==1
__declspec(dllexport) പൂർണ്ണസംഖ്യ f_1()
{
    hello();
    തിരികെ 0;
}


#അല്ലെങ്കിലെങ്കിൽ DLL==2
__declspec(dllexport) പൂർണ്ണസംഖ്യ f_2()
{
    hello();
    തിരികെ 0;
}


#അല്ലെങ്കിൽ

പൂർണ്ണസംഖ്യ f_1();
പൂർണ്ണസംഖ്യ f_2();
പൂർണ്ണസംഖ്യ f_main()
{
    hello();
    തിരികെ 0;
}

പൂർണ്ണസംഖ്യ പ്രധാന ()
{
    f_1();
    f_2();
    f_main();
    തിരികെ 0;
}

#endif
