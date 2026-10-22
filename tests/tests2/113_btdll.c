целое tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#если DLL==1
__declspec(dllexport) целое f_1()
{
    hello();
    вернуть 0;
}


#elif DLL==2
__declspec(dllexport) целое f_2()
{
    hello();
    вернуть 0;
}


#иначе

целое f_1();
целое f_2();
целое f_main()
{
    hello();
    вернуть 0;
}

целое основной ()
{
    f_1();
    f_2();
    f_main();
    вернуть 0;
}

#endif
