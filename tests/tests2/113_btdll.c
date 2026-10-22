पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#यदि DLL==1
__declspec(dllexport) पूर्णाङ्क f_1()
{
    hello();
    प्रत्यागम 0;
}


#नोचेद्यदि DLL==2
__declspec(dllexport) पूर्णाङ्क f_2()
{
    hello();
    प्रत्यागम 0;
}


#अन्यथा

पूर्णाङ्क f_1();
पूर्णाङ्क f_2();
पूर्णाङ्क f_main()
{
    hello();
    प्रत्यागम 0;
}

पूर्णाङ्क main ()
{
    f_1();
    f_2();
    f_main();
    प्रत्यागम 0;
}

#endif
