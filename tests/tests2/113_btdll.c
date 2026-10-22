цео tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ако DLL==1
__declspec(dllexport) цео f_1()
{
    hello();
    врати 0;
}


#elif DLL==2
__declspec(dllexport) цео f_2()
{
    hello();
    врати 0;
}


#инако

цео f_1();
цео f_2();
цео f_main()
{
    hello();
    врати 0;
}

цео main ()
{
    f_1();
    f_2();
    f_main();
    врати 0;
}

#endif
