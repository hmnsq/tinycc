#अन्तर्भाव <stdio.h>

पूर्णाङ्क atexit(शून्य (*function)(शून्य));
पूर्णाङ्क on_exit(शून्य (*function)(पूर्णाङ्क, शून्य *), शून्य *arg);
शून्य exit(पूर्णाङ्क status);

शून्य __attribute((constructor)) startup5(शून्य)
{
    printf ("startup5\n");
}

शून्य cleanup1(शून्य)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

शून्य cleanup2(शून्य)
{
    printf ("cleanup2\n");
}

शून्य cleanup3(पूर्णाङ्क ret, शून्य *arg)
{
    printf ("%d %s\n", ret, (वर्ण *) arg);
}

शून्य cleanup4(पूर्णाङ्क ret, शून्य *arg)
{
    printf ("%d %s\n", ret, (वर्ण *) arg);
}

शून्य __attribute((destructor)) cleanup5(शून्य)
{
    printf ("cleanup5\n");
}

शून्य test(शून्य)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#यदि defined test_128_return
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    test();
    प्रत्यागम 1;
} 

#नोचेद्यदि defined test_128_exit
पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    test();
    exit(2);
} 
#endif
