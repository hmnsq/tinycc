#ضمن <stdio.h>

صحيح atexit(فراغ (*function)(فراغ));
صحيح on_exit(فراغ (*function)(صحيح, فراغ *), فراغ *arg);
فراغ exit(صحيح status);

فراغ __attribute((constructor)) startup5(فراغ)
{
    printf ("startup5\n");
}

فراغ cleanup1(فراغ)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

فراغ cleanup2(فراغ)
{
    printf ("cleanup2\n");
}

فراغ cleanup3(صحيح ret, فراغ *arg)
{
    printf ("%d %s\n", ret, (حرف *) arg);
}

فراغ cleanup4(صحيح ret, فراغ *arg)
{
    printf ("%d %s\n", ret, (حرف *) arg);
}

فراغ __attribute((destructor)) cleanup5(فراغ)
{
    printf ("cleanup5\n");
}

فراغ test(فراغ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ܐܢ defined test_128_return
صحيح main(صحيح argc, حرف **argv)
{
    test();
    ܦܢܐ 1;
} 

#وإلاإذا defined test_128_exit
صحيح main(صحيح argc, حرف **argv)
{
    test();
    exit(2);
} 
#endif
