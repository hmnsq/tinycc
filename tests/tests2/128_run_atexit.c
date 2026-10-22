#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਪੂਰਨ atexit(ਖਾਲੀ (*function)(ਖਾਲੀ));
ਪੂਰਨ on_exit(ਖਾਲੀ (*function)(ਪੂਰਨ, ਖਾਲੀ *), ਖਾਲੀ *arg);
ਖਾਲੀ ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ ਸਥਿਤੀ);

ਖਾਲੀ __attribute((constructor)) startup5(ਖਾਲੀ)
{
    ਲਿਖੋ ("startup5\n");
}

ਖਾਲੀ cleanup1(ਖਾਲੀ)
{
    ਲਿਖੋ ("cleanup1\n");
    fflush(stdout);
}

ਖਾਲੀ cleanup2(ਖਾਲੀ)
{
    ਲਿਖੋ ("cleanup2\n");
}

ਖਾਲੀ cleanup3(ਪੂਰਨ ret, ਖਾਲੀ *arg)
{
    ਲਿਖੋ ("%d %s\n", ret, (ਅੱਖਰ *) arg);
}

ਖਾਲੀ cleanup4(ਪੂਰਨ ret, ਖਾਲੀ *arg)
{
    ਲਿਖੋ ("%d %s\n", ret, (ਅੱਖਰ *) arg);
}

ਖਾਲੀ __attribute((destructor)) cleanup5(ਖਾਲੀ)
{
    ਲਿਖੋ ("cleanup5\n");
}

ਖਾਲੀ test(ਖਾਲੀ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ਜੇ defined test_128_return
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    test();
    ਵਾਪਸ 1;
} 

#ਜਾਂਜੇ defined test_128_exit
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    test();
    ਬਾਹਰ_ਨਿਕਲੋ(2);
} 
#ਜੇ_ਅੰਤ
