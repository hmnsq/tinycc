#అన్తర్భావ <stdio.h>

పూర్ణాంకం atexit(శూన్య (*function)(శూన్య));
పూర్ణాంకం on_exit(శూన్య (*function)(పూర్ణాంకం, శూన్య *), శూన్య *arg);
శూన్య నిష్క్రమించు(పూర్ణాంకం స్థితి_2);

శూన్య __attribute((constructor)) startup5(శూన్య)
{
    రాయి ("startup5\n");
}

శూన్య cleanup1(శూన్య)
{
    రాయి ("cleanup1\n");
    fflush(stdout);
}

శూన్య cleanup2(శూన్య)
{
    రాయి ("cleanup2\n");
}

శూన్య cleanup3(పూర్ణాంకం ret, శూన్య *arg)
{
    రాయి ("%d %s\n", ret, (అక్షరం *) arg);
}

శూన్య cleanup4(పూర్ణాంకం ret, శూన్య *arg)
{
    రాయి ("%d %s\n", ret, (అక్షరం *) arg);
}

శూన్య __attribute((destructor)) cleanup5(శూన్య)
{
    రాయి ("cleanup5\n");
}

శూన్య test(శూన్య)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ఒకవేళ defined test_128_return
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    test();
    తిరిగి 1;
} 

#లేదావేళ defined test_128_exit
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    test();
    నిష్క్రమించు(2);
} 
#అయితే_ముగింపు
