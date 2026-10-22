ಪೂರ್ಣಾಂಕ tcc_backtrace(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);
#ವ್ಯಾಖ್ಯಾನಿಸು hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
# define __declspec(n)
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ DLL==1
__declspec(dllexport) ಪೂರ್ಣಾಂಕ f_1()
{
    hello();
    ಹಿಂತಿರುಗಿ 0;
}


#ಅಥವಾಆದರೆ DLL==2
__declspec(dllexport) ಪೂರ್ಣಾಂಕ f_2()
{
    hello();
    ಹಿಂತಿರುಗಿ 0;
}


#ಇಲ್ಲದಿದ್ದರೆ

ಪೂರ್ಣಾಂಕ f_1();
ಪೂರ್ಣಾಂಕ f_2();
ಪೂರ್ಣಾಂಕ f_main()
{
    hello();
    ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ ()
{
    f_1();
    f_2();
    f_main();
    ಹಿಂತಿರುಗಿ 0;
}

#ಆದರೆ_ಅಂತ್ಯ
