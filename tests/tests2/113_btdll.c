पूर्णाङ्क tcc_backtrace(अचर वर्ण*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#यदि DLL==1
__declspec(dllexport) पूर्णाङ्क f_1()
{
    hello();
    फर्काऊ 0;
}


#अथवायदि DLL==2
__declspec(dllexport) पूर्णाङ्क f_2()
{
    hello();
    फर्काऊ 0;
}


#अन्यथा

पूर्णाङ्क f_1();
पूर्णाङ्क f_2();
पूर्णाङ्क f_main()
{
    hello();
    फर्काऊ 0;
}

पूर्णाङ्क main ()
{
    f_1();
    f_2();
    f_main();
    फर्काऊ 0;
}

#endif
