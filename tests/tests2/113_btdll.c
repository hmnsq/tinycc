ಪೂರ್ಣಾಙ್ಕ tcc_backtrace(ಧ್ರುವ ವರ್ಣ*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ಯದಿ DLL==1
__declspec(dllexport) ಪೂರ್ಣಾಙ್ಕ f_1()
{
    hello();
    ಪ್ರತ್ಯಾಗಮ 0;
}


#ನೋಚೇದ್ಯದಿ DLL==2
__declspec(dllexport) ಪೂರ್ಣಾಙ್ಕ f_2()
{
    hello();
    ಪ್ರತ್ಯಾಗಮ 0;
}


#ಅನ್ಯಥಾ

ಪೂರ್ಣಾಙ್ಕ f_1();
ಪೂರ್ಣಾಙ್ಕ f_2();
ಪೂರ್ಣಾಙ್ಕ f_main()
{
    hello();
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ main ()
{
    f_1();
    f_2();
    f_main();
    ಪ್ರತ್ಯಾಗಮ 0;
}

#endif
