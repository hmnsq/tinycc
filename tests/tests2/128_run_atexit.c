#അന്തര്ഭാവ <stdio.h>

പൂർണ്ണസംഖ്യ atexit(ശൂന്യം (*function)(ശൂന്യം));
പൂർണ്ണസംഖ്യ on_exit(ശൂന്യം (*function)(പൂർണ്ണസംഖ്യ, ശൂന്യം *), ശൂന്യം *arg);
ശൂന്യം exit(പൂർണ്ണസംഖ്യ status);

ശൂന്യം __attribute((constructor)) startup5(ശൂന്യം)
{
    printf ("startup5\n");
}

ശൂന്യം cleanup1(ശൂന്യം)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

ശൂന്യം cleanup2(ശൂന്യം)
{
    printf ("cleanup2\n");
}

ശൂന്യം cleanup3(പൂർണ്ണസംഖ്യ ret, ശൂന്യം *arg)
{
    printf ("%d %s\n", ret, (അക്ഷരം *) arg);
}

ശൂന്യം cleanup4(പൂർണ്ണസംഖ്യ ret, ശൂന്യം *arg)
{
    printf ("%d %s\n", ret, (അക്ഷരം *) arg);
}

ശൂന്യം __attribute((destructor)) cleanup5(ശൂന്യം)
{
    printf ("cleanup5\n");
}

ശൂന്യം test(ശൂന്യം)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#എങ്കിൽ defined test_128_return
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    test();
    തിരികെ 1;
} 

#അല്ലെങ്കിലെങ്കിൽ defined test_128_exit
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    test();
    exit(2);
} 
#endif
