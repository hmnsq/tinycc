முழு tcc_backtrace(மாறிலி எழுத்து*, ...);
#define hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ifndef _WIN32
# define __declspec(n)
#endif

#எனில் DLL==1
__declspec(dllexport) முழு f_1()
{
    hello();
    திரும்பு 0;
}


#அல்லதெனில் DLL==2
__declspec(dllexport) முழு f_2()
{
    hello();
    திரும்பு 0;
}


#இல்லையெனில்

முழு f_1();
முழு f_2();
முழு f_main()
{
    hello();
    திரும்பு 0;
}

முழு முதன்மை ()
{
    f_1();
    f_2();
    f_main();
    திரும்பு 0;
}

#endif
