ចំនួនគត់ tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ប្រសិនបើ DLL==1
__declspec(dllexport) ចំនួនគត់ f_1()
{
    hello();
    ត្រឡប់ 0;
}


#elif DLL==2
__declspec(dllexport) ចំនួនគត់ f_2()
{
    hello();
    ត្រឡប់ 0;
}


#បើមិនដូច្នេះ

ចំនួនគត់ f_1();
ចំនួនគត់ f_2();
ចំនួនគត់ f_main()
{
    hello();
    ត្រឡប់ 0;
}

ចំនួនគត់ main ()
{
    f_1();
    f_2();
    f_main();
    ត្រឡប់ 0;
}

#endif
