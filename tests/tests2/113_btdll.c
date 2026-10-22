ຈຳນວນເຕັມ tcc_backtrace(const var_na*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#ຖ້າ DLL==1
__declspec(dllexport) ຈຳນວນເຕັມ f_1()
{
    hello();
    ສົ່ງຄືນ 0;
}


#elif DLL==2
__declspec(dllexport) ຈຳນວນເຕັມ f_2()
{
    hello();
    ສົ່ງຄືນ 0;
}


#ບໍ່ດັ່ງນັ້ນ

ຈຳນວນເຕັມ f_1();
ຈຳນວນເຕັມ f_2();
ຈຳນວນເຕັມ f_main()
{
    hello();
    ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ main ()
{
    f_1();
    f_2();
    f_main();
    ສົ່ງຄືນ 0;
}

#endif
