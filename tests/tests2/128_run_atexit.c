#ضمن <stdio.h>

صحيح atexit(فراغ (*function)(فراغ));
صحيح on_exit(فراغ (*function)(صحيح, فراغ *), فراغ *arg);
فراغ باہر_نکلو(صحيح حالت);

فراغ __attribute((constructor)) startup5(فراغ)
{
    لکھو ("startup5\n");
}

فراغ cleanup1(فراغ)
{
    لکھو ("cleanup1\n");
    fflush(stdout);
}

فراغ cleanup2(فراغ)
{
    لکھو ("cleanup2\n");
}

فراغ cleanup3(صحيح ret, فراغ *arg)
{
    لکھو ("%d %s\n", ret, (حرف *) arg);
}

فراغ cleanup4(صحيح ret, فراغ *arg)
{
    لکھو ("%d %s\n", ret, (حرف *) arg);
}

فراغ __attribute((destructor)) cleanup5(فراغ)
{
    لکھو ("cleanup5\n");
}

فراغ test(فراغ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#إذا defined test_128_return
صحيح مکھ(صحيح argc, حرف **argv)
{
    test();
    أرجع 1;
} 

#وإلاإذا defined test_128_exit
صحيح مکھ(صحيح argc, حرف **argv)
{
    test();
    باہر_نکلو(2);
} 
#جے_انت
