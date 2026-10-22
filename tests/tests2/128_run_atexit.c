#அந்தர்பாவ <stdio.h>

முழு atexit(வெறுமை (*function)(வெறுமை));
முழு on_exit(வெறுமை (*function)(முழு, வெறுமை *), வெறுமை *arg);
வெறுமை exit(முழு status);

வெறுமை __attribute((constructor)) startup5(வெறுமை)
{
    printf ("startup5\n");
}

வெறுமை cleanup1(வெறுமை)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

வெறுமை cleanup2(வெறுமை)
{
    printf ("cleanup2\n");
}

வெறுமை cleanup3(முழு ret, வெறுமை *arg)
{
    printf ("%d %s\n", ret, (எழுத்து *) arg);
}

வெறுமை cleanup4(முழு ret, வெறுமை *arg)
{
    printf ("%d %s\n", ret, (எழுத்து *) arg);
}

வெறுமை __attribute((destructor)) cleanup5(வெறுமை)
{
    printf ("cleanup5\n");
}

வெறுமை test(வெறுமை)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#எனில் defined test_128_return
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    test();
    திரும்பு 1;
} 

#அல்லதெனில் defined test_128_exit
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    test();
    exit(2);
} 
#endif
