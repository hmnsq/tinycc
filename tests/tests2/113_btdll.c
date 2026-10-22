पूर्णांक tcc_backtrace(स्थिर अक्षर*, ...);
#घोषणा hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__खाता__,__LINE__)

#अगर_अघोषित _WIN32
# define __declspec(n)
#पूर्ण_अगर

#अगर DLL==1
__declspec(dllexport) पूर्णांक f_1()
{
    hello();
    वापस 0;
}


#या_अगर DLL==2
__declspec(dllexport) पूर्णांक f_2()
{
    hello();
    वापस 0;
}


#अन्यथा

पूर्णांक f_1();
पूर्णांक f_2();
पूर्णांक f_main()
{
    hello();
    वापस 0;
}

पूर्णांक मुख्य ()
{
    f_1();
    f_2();
    f_main();
    वापस 0;
}

#पूर्ण_अगर
