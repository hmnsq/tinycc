#অন্তর্ভাৱ <stdio.h>

পূর্ণাঙ্ক atexit(শূন্য (*function)(শূন্য));
পূর্ণাঙ্ক on_exit(শূন্য (*function)(পূর্ণাঙ্ক, শূন্য *), শূন্য *arg);
শূন্য exit(পূর্ণাঙ্ক status);

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

শূন্য cleanup3(পূর্ণাঙ্ক ret, শূন্য *arg)
{
    printf ("%d %s\n", ret, (ৱর্ণ *) arg);
}

শূন্য cleanup4(পূর্ণাঙ্ক ret, শূন্য *arg)
{
    printf ("%d %s\n", ret, (ৱর্ণ *) arg);
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
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    test();
    ঘূৰাই 1;
} 

#নোচেদ্যদি defined test_128_exit
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    test();
    exit(2);
} 
#endif
