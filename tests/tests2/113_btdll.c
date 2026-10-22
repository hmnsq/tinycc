పూర్ణాంకం tcc_backtrace(స్థిరరాశి అక్షరం*, ...);
#నిర్వచించు hello() \
    tcc_backtrace("hello from %s() / %s:%d",__FUNCTION__,__FILE__,__LINE__)

#నిర్వచితం_కాకపోతే _WIN32
# define __declspec(n)
#అయితే_ముగింపు

#ఒకవేళ DLL==1
__declspec(dllexport) పూర్ణాంకం f_1()
{
    hello();
    తిరిగి 0;
}


#లేదావేళ DLL==2
__declspec(dllexport) పూర్ణాంకం f_2()
{
    hello();
    తిరిగి 0;
}


#లేకపోతే

పూర్ణాంకం f_1();
పూర్ణాంకం f_2();
పూర్ణాంకం f_main()
{
    hello();
    తిరిగి 0;
}

పూర్ణాంకం ప్రధాన ()
{
    f_1();
    f_2();
    f_main();
    తిరిగి 0;
}

#అయితే_ముగింపు
