পূর্ণাঙ্ক tcc_backtrace(ধ্রুৱ ৱর্ণ*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#যদি DLL==1
__declspec(dllexport) পূর্ণাঙ্ক f_1()
{
    hello();
    ঘূৰাই 0;
}


#নোচেদ্যদি DLL==2
__declspec(dllexport) পূর্ণাঙ্ক f_2()
{
    hello();
    ঘূৰাই 0;
}


#অন্যথা

পূর্ণাঙ্ক f_1();
পূর্ণাঙ্ক f_2();
পূর্ণাঙ্ক f_main()
{
    hello();
    ঘূৰাই 0;
}

পূর্ণাঙ্ক main ()
{
    f_1();
    f_2();
    f_main();
    ঘূৰাই 0;
}

#endif
