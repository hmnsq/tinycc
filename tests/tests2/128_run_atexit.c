#شامل <stdio.h>

صحیح atexit(خالی (*function)(خالی));
صحیح on_exit(خالی (*function)(صحیح, خالی *), خالی *arg);
خالی باہر_نکلو(صحیح حالت_2);

خالی __attribute((constructor)) startup5(خالی)
{
    لکھو ("startup5\n");
}

خالی cleanup1(خالی)
{
    لکھو ("cleanup1\n");
    fflush(stdout);
}

خالی cleanup2(خالی)
{
    لکھو ("cleanup2\n");
}

خالی cleanup3(صحیح ret, خالی *arg)
{
    لکھو ("%d %s\n", ret, (حرف *) arg);
}

خالی cleanup4(صحیح ret, خالی *arg)
{
    لکھو ("%d %s\n", ret, (حرف *) arg);
}

خالی __attribute((destructor)) cleanup5(خالی)
{
    لکھو ("cleanup5\n");
}

خالی test(خالی)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#اگر defined test_128_return
صحیح مین(صحیح argc, حرف **argv)
{
    test();
    واپس 1;
} 

#وگرنہ_اگر defined test_128_exit
صحیح مین(صحیح argc, حرف **argv)
{
    test();
    باہر_نکلو(2);
} 
#اگر_ختم
