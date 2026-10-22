số_nguyên tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#nếu DLL==1
__declspec(dllexport) số_nguyên f_1()
{
    hello();
    trả_về 0;
}


#elif DLL==2
__declspec(dllexport) số_nguyên f_2()
{
    hello();
    trả_về 0;
}


#không_thì

số_nguyên f_1();
số_nguyên f_2();
số_nguyên f_main()
{
    hello();
    trả_về 0;
}

số_nguyên main ()
{
    f_1();
    f_2();
    f_main();
    trả_về 0;
}

#endif
