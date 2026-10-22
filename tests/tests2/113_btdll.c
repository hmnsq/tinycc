цяло tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ако DLL==1
__declspec(dllexport) цяло f_1()
{
    hello();
    върни 0;
}


#elif DLL==2
__declspec(dllexport) цяло f_2()
{
    hello();
    върни 0;
}


#иначе

цяло f_1();
цяло f_2();
цяло f_main()
{
    hello();
    върни 0;
}

цяло main ()
{
    f_1();
    f_2();
    f_main();
    върни 0;
}

#endif
