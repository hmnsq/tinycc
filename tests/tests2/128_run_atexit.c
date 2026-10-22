#અન્તર્ભાવ <stdio.h>

પૂર્ણાંક atexit(શૂન્ય (*function)(શૂન્ય));
પૂર્ણાંક on_exit(શૂન્ય (*function)(પૂર્ણાંક, શૂન્ય *), શૂન્ય *arg);
શૂન્ય exit(પૂર્ણાંક status);

શૂન્ય __attribute((constructor)) startup5(શૂન્ય)
{
    printf ("startup5\n");
}

શૂન્ય cleanup1(શૂન્ય)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

શૂન્ય cleanup2(શૂન્ય)
{
    printf ("cleanup2\n");
}

શૂન્ય cleanup3(પૂર્ણાંક ret, શૂન્ય *arg)
{
    printf ("%d %s\n", ret, (અક્ષર *) arg);
}

શૂન્ય cleanup4(પૂર્ણાંક ret, શૂન્ય *arg)
{
    printf ("%d %s\n", ret, (અક્ષર *) arg);
}

શૂન્ય __attribute((destructor)) cleanup5(શૂન્ય)
{
    printf ("cleanup5\n");
}

શૂન્ય test(શૂન્ય)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#જો defined test_128_return
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    test();
    પાછા 1;
} 

#અથવાજો defined test_128_exit
પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    test();
    exit(2);
} 
#endif
