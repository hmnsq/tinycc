પૂર્ણાંક tcc_backtrace(અચલ અક્ષર*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#જો DLL==1
__declspec(dllexport) પૂર્ણાંક f_1()
{
    hello();
    પાછા 0;
}


#અથવાજો DLL==2
__declspec(dllexport) પૂર્ણાંક f_2()
{
    hello();
    પાછા 0;
}


#નહીંતર

પૂર્ણાંક f_1();
પૂર્ણાંક f_2();
પૂર્ણાંક f_main()
{
    hello();
    પાછા 0;
}

પૂર્ણાંક મુખ્ય ()
{
    f_1();
    f_2();
    f_main();
    પાછા 0;
}

#endif
