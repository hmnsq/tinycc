整数 tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#如果 DLL==1
__declspec(dllexport) 整数 f_1()
{
    hello();
    返回 0;
}


#elif DLL==2
__declspec(dllexport) 整数 f_2()
{
    hello();
    返回 0;
}


#否则

整数 f_1();
整数 f_2();
整数 f_main()
{
    hello();
    返回 0;
}

整数 主要 ()
{
    f_1();
    f_2();
    f_main();
    返回 0;
}

#endif
