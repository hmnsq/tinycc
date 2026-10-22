#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା atexit(ଶୂନ୍ୟ (*function)(ଶୂନ୍ୟ));
ପୂର୍ଣ୍ଣସଂଖ୍ୟା on_exit(ଶୂନ୍ୟ (*function)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଶୂନ୍ୟ *), ଶୂନ୍ୟ *arg);
ଶୂନ୍ୟ exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା status);

ଶୂନ୍ୟ __attribute((constructor)) startup5(ଶୂନ୍ୟ)
{
    printf ("startup5\n");
}

ଶୂନ୍ୟ cleanup1(ଶୂନ୍ୟ)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

ଶୂନ୍ୟ cleanup2(ଶୂନ୍ୟ)
{
    printf ("cleanup2\n");
}

ଶୂନ୍ୟ cleanup3(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, ଶୂନ୍ୟ *arg)
{
    printf ("%d %s\n", ret, (ଅକ୍ଷର *) arg);
}

ଶୂନ୍ୟ cleanup4(ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, ଶୂନ୍ୟ *arg)
{
    printf ("%d %s\n", ret, (ଅକ୍ଷର *) arg);
}

ଶୂନ୍ୟ __attribute((destructor)) cleanup5(ଶୂନ୍ୟ)
{
    printf ("cleanup5\n");
}

ଶୂନ୍ୟ test(ଶୂନ୍ୟ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ଯଦି defined test_128_return
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    test();
    ଫେରନ୍ତୁ 1;
} 

#ନଚେତଯଦି defined test_128_exit
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    test();
    exit(2);
} 
#endif
