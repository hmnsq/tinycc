صحیح tcc_backtrace(ثابت نویسه*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#اگر DLL==1
__declspec(dllexport) صحیح f_1()
{
    hello();
    بازگشت 0;
}


#وگرنهاگر DLL==2
__declspec(dllexport) صحیح f_2()
{
    hello();
    بازگشت 0;
}


#وگرنه

صحیح f_1();
صحیح f_2();
صحیح f_main()
{
    hello();
    بازگشت 0;
}

صحیح اصلی ()
{
    f_1();
    f_2();
    f_main();
    بازگشت 0;
}

#endif
