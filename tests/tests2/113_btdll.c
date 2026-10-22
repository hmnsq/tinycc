صحيح tcc_backtrace(ثابت حرف*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#אם DLL==1
__declspec(dllexport) صحيح f_1()
{
    hello();
    החזר 0;
}


#وإلاإذا DLL==2
__declspec(dllexport) صحيح f_2()
{
    hello();
    החזר 0;
}


#אחרת

صحيح f_1();
صحيح f_2();
صحيح f_main()
{
    hello();
    החזר 0;
}

صحيح main ()
{
    f_1();
    f_2();
    f_main();
    החזר 0;
}

#endif
