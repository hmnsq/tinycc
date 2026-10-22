ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_backtrace(ଅଚଳ ଅକ୍ଷର*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ଯଦି DLL==1
__declspec(dllexport) ପୂର୍ଣ୍ଣସଂଖ୍ୟା f_1()
{
    hello();
    ଫେରନ୍ତୁ 0;
}


#ନଚେତଯଦି DLL==2
__declspec(dllexport) ପୂର୍ଣ୍ଣସଂଖ୍ୟା f_2()
{
    hello();
    ଫେରନ୍ତୁ 0;
}


#ଅନ୍ୟଥା

ପୂର୍ଣ୍ଣସଂଖ୍ୟା f_1();
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f_2();
ପୂର୍ଣ୍ଣସଂଖ୍ୟା f_main()
{
    hello();
    ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ ()
{
    f_1();
    f_2();
    f_main();
    ଫେରନ୍ତୁ 0;
}

#endif
