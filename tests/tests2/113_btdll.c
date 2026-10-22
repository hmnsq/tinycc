ကိန်းပြည့် tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#အကယ်၍ DLL==1
__declspec(dllexport) ကိန်းပြည့် f_1()
{
    hello();
    ပြန်ပေး 0;
}


#elif DLL==2
__declspec(dllexport) ကိန်းပြည့် f_2()
{
    hello();
    ပြန်ပေး 0;
}


#မဟုတ်ပါက

ကိန်းပြည့် f_1();
ကိန်းပြည့် f_2();
ကိန်းပြည့် f_main()
{
    hello();
    ပြန်ပေး 0;
}

ကိန်းပြည့် main ()
{
    f_1();
    f_2();
    f_main();
    ပြန်ပေး 0;
}

#endif
