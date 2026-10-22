पूर्णांक tcc_backtrace(स्थिरांक अक्षर*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#जर DLL==1
__declspec(dllexport) पूर्णांक f_1()
{
    hello();
    परत 0;
}


#किंवाजर DLL==2
__declspec(dllexport) पूर्णांक f_2()
{
    hello();
    परत 0;
}


#अन्यथा

पूर्णांक f_1();
पूर्णांक f_2();
पूर्णांक f_main()
{
    hello();
    परत 0;
}

पूर्णांक main ()
{
    f_1();
    f_2();
    f_main();
    परत 0;
}

#endif
