صحيح tcc_backtrace(ثابت حرف*, ...);
#تعریف_کړه hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#که_نه_تعریف_شوی _WIN32
# define __declspec(n)
#د_که_پای

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

صحيح اصلي ()
{
    f_1();
    f_2();
    f_main();
    أرجع 0;
}

#د_که_پای
