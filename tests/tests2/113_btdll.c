ཧྲིལ tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#གལ་སྲིད DLL==1
__declspec(dllexport) ཧྲིལ f_1()
{
    hello();
    ལོག 0;
}


#elif DLL==2
__declspec(dllexport) ཧྲིལ f_2()
{
    hello();
    ལོག 0;
}


#དེ་མིན

ཧྲིལ f_1();
ཧྲིལ f_2();
ཧྲིལ f_main()
{
    hello();
    ལོག 0;
}

ཧྲིལ main ()
{
    f_1();
    f_2();
    f_main();
    ལོག 0;
}

#endif
