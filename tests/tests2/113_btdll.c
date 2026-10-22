ціле tcc_backtrace(const char*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#якщо DLL==1
__declspec(dllexport) ціле f_1()
{
    hello();
    повернути 0;
}


#elif DLL==2
__declspec(dllexport) ціле f_2()
{
    hello();
    повернути 0;
}


#інакше

ціле f_1();
ціле f_2();
ціле f_main()
{
    hello();
    повернути 0;
}

ціле main ()
{
    f_1();
    f_2();
    f_main();
    повернути 0;
}

#endif
