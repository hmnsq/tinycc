#شامل <stdio.h>

صحیح atexit(تهی (*function)(تهی));
صحیح on_exit(تهی (*function)(صحیح, تهی *), تهی *arg);
تهی exit(صحیح status);

تهی __attribute((constructor)) startup5(تهی)
{
    printf ("startup5\n");
}

تهی cleanup1(تهی)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

تهی cleanup2(تهی)
{
    printf ("cleanup2\n");
}

تهی cleanup3(صحیح ret, تهی *arg)
{
    printf ("%d %s\n", ret, (نویسه *) arg);
}

تهی cleanup4(صحیح ret, تهی *arg)
{
    printf ("%d %s\n", ret, (نویسه *) arg);
}

تهی __attribute((destructor)) cleanup5(تهی)
{
    printf ("cleanup5\n");
}

تهی test(تهی)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#اگر defined test_128_return
صحیح اصلی(صحیح argc, نویسه **argv)
{
    test();
    بازگشت 1;
} 

#وگرنهاگر defined test_128_exit
صحیح اصلی(صحیح argc, نویسه **argv)
{
    test();
    exit(2);
} 
#endif
