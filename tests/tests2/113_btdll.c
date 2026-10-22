จำนวนเต็ม tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ถ้า DLL==1
__declspec(dllexport) จำนวนเต็ม f_1()
{
    hello();
    คืน 0;
}


#elif DLL==2
__declspec(dllexport) จำนวนเต็ม f_2()
{
    hello();
    คืน 0;
}


#มิฉะนั้น

จำนวนเต็ม f_1();
จำนวนเต็ม f_2();
จำนวนเต็ม f_main()
{
    hello();
    คืน 0;
}

จำนวนเต็ม หลัก ()
{
    f_1();
    f_2();
    f_main();
    คืน 0;
}

#endif
