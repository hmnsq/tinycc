정수 tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#만약 DLL==1
__declspec(dllexport) 정수 f_1()
{
    hello();
    반환 0;
}


#elif DLL==2
__declspec(dllexport) 정수 f_2()
{
    hello();
    반환 0;
}


#아니면

정수 f_1();
정수 f_2();
정수 f_main()
{
    hello();
    반환 0;
}

정수 main ()
{
    f_1();
    f_2();
    f_main();
    반환 0;
}

#endif
