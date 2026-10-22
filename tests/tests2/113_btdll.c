පූර්ණ_සංඛ්‍යා tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#නම් DLL==1
__declspec(dllexport) පූර්ණ_සංඛ්‍යා f_1()
{
    hello();
    ආපසු 0;
}


#elif DLL==2
__declspec(dllexport) පූර්ණ_සංඛ්‍යා f_2()
{
    hello();
    ආපසු 0;
}


#නැතහොත්

පූර්ණ_සංඛ්‍යා f_1();
පූර්ණ_සංඛ්‍යා f_2();
පූර්ණ_සංඛ්‍යා f_main()
{
    hello();
    ආපසු 0;
}

පූර්ණ_සංඛ්‍යා main ()
{
    f_1();
    f_2();
    f_main();
    ආපසු 0;
}

#endif
