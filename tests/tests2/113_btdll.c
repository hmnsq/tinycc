ਪੂਰਨ tcc_backtrace(ਅਚਲ ਅੱਖਰ*, ...);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
# define __declspec(n)
#ਜੇ_ਅੰਤ

#ਜੇ DLL==1
__declspec(dllexport) ਪੂਰਨ f_1()
{
    hello();
    ਵਾਪਸ 0;
}


#ਜਾਂਜੇ DLL==2
__declspec(dllexport) ਪੂਰਨ f_2()
{
    hello();
    ਵਾਪਸ 0;
}


#ਨਹੀਂਤਾਂ

ਪੂਰਨ f_1();
ਪੂਰਨ f_2();
ਪੂਰਨ f_main()
{
    hello();
    ਵਾਪਸ 0;
}

ਪੂਰਨ ਮੁੱਖ ()
{
    f_1();
    f_2();
    f_main();
    ਵਾਪਸ 0;
}

#ਜੇ_ਅੰਤ
