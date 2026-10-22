صحیح tcc_backtrace(ثابت حرف*, ...);
#تعریف_کرو hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#اگر_غیر_تعریف_شدہ _WIN32
# define __declspec(n)
#اگر_ختم

#اگر DLL==1
__declspec(dllexport) صحیح f_1()
{
    hello();
    واپس 0;
}


#وگرنہ_اگر DLL==2
__declspec(dllexport) صحیح f_2()
{
    hello();
    واپس 0;
}


#ورنہ

صحیح f_1();
صحیح f_2();
صحیح f_main()
{
    hello();
    واپس 0;
}

صحیح مین ()
{
    f_1();
    f_2();
    f_main();
    واپس 0;
}

#اگر_ختم
