পূর্ণসংখ্যা tcc_backtrace(ধ্রুবক অক্ষর*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#যদি DLL==1
__declspec(dllexport) পূর্ণসংখ্যা f_1()
{
    hello();
    ফেরত 0;
}


#নতুবা_যদি DLL==2
__declspec(dllexport) পূর্ণসংখ্যা f_2()
{
    hello();
    ফেরত 0;
}


#অন্যথা

পূর্ণসংখ্যা f_1();
পূর্ণসংখ্যা f_2();
পূর্ণসংখ্যা f_main()
{
    hello();
    ফেরত 0;
}

পূর্ণসংখ্যা প্রধান ()
{
    f_1();
    f_2();
    f_main();
    ফেরত 0;
}

#endif
