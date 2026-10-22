#অন্তর্ভাব <stdio.h>

পূর্ণসংখ্যা atexit(শূন্য (*function)(শূন্য));
পূর্ণসংখ্যা on_exit(শূন্য (*function)(পূর্ণসংখ্যা, শূন্য *), শূন্য *arg);
শূন্য exit(পূর্ণসংখ্যা status);

শূন্য __attribute((constructor)) startup5(শূন্য)
{
    printf ("startup5\n");
}

শূন্য cleanup1(শূন্য)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

শূন্য cleanup2(শূন্য)
{
    printf ("cleanup2\n");
}

শূন্য cleanup3(পূর্ণসংখ্যা ret, শূন্য *arg)
{
    printf ("%d %s\n", ret, (অক্ষর *) arg);
}

শূন্য cleanup4(পূর্ণসংখ্যা ret, শূন্য *arg)
{
    printf ("%d %s\n", ret, (অক্ষর *) arg);
}

শূন্য __attribute((destructor)) cleanup5(শূন্য)
{
    printf ("cleanup5\n");
}

শূন্য test(শূন্য)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#যদি defined test_128_return
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    test();
    ফেরত 1;
} 

#নতুবা_যদি defined test_128_exit
পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    test();
    exit(2);
} 
#endif
