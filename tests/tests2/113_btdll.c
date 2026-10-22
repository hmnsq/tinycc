صحيح tcc_backtrace(ثابت حرف*, ...);
#تعریف_کرو hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#جے_بنا_تعریف _WIN32
# define __declspec(n)
#جے_انت

#إذا DLL==1
__declspec(dllexport) صحيح f_1()
{
    hello();
    أرجع 0;
}


#وإلاإذا DLL==2
__declspec(dllexport) صحيح f_2()
{
    hello();
    أرجع 0;
}


#وإلا

صحيح f_1();
صحيح f_2();
صحيح f_main()
{
    hello();
    أرجع 0;
}

صحيح مکھ ()
{
    f_1();
    f_2();
    f_main();
    أرجع 0;
}

#جے_انت
