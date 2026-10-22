#ضمن <stdio.h>

صحيح atexit(فراغ (*function)(فراغ));
صحيح on_exit(فراغ (*function)(صحيح, فراغ *), فراغ *arg);
فراغ ٻاهر_نڪرو(صحيح حالت);

فراغ __attribute((constructor)) startup5(فراغ)
{
    لکو ("startup5\n");
}

فراغ cleanup1(فراغ)
{
    لکو ("cleanup1\n");
    fflush(stdout);
}

فراغ cleanup2(فراغ)
{
    لکو ("cleanup2\n");
}

فراغ cleanup3(صحيح ret, فراغ *arg)
{
    لکو ("%d %s\n", ret, (حرف *) arg);
}

فراغ cleanup4(صحيح ret, فراغ *arg)
{
    لکو ("%d %s\n", ret, (حرف *) arg);
}

فراغ __attribute((destructor)) cleanup5(فراغ)
{
    لکو ("cleanup5\n");
}

فراغ test(فراغ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#إذا defined test_128_return
صحيح مکيه(صحيح argc, حرف **argv)
{
    test();
    أرجع 1;
} 

#وإلاإذا defined test_128_exit
صحيح مکيه(صحيح argc, حرف **argv)
{
    test();
    ٻاهر_نڪرو(2);
} 
#جيڪڏهن_پورو
