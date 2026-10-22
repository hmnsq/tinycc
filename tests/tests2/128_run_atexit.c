#अन्तर्भाव <stdio.h>

पूर्णाङ्क निकास_पर(शून्य (*function)(शून्य));
पूर्णाङ्क on_exit(शून्य (*function)(पूर्णाङ्क, शून्य *), शून्य *arg);
शून्य निकास(पूर्णाङ्क status);

शून्य __attribute((constructor)) startup5(शून्य)
{
    म_लिखो ("startup5\n");
}

शून्य cleanup1(शून्य)
{
    म_लिखो ("cleanup1\n");
    ख_साफ(मानक_निकास);
}

शून्य cleanup2(शून्य)
{
    म_लिखो ("cleanup2\n");
}

शून्य cleanup3(पूर्णाङ्क ret, शून्य *arg)
{
    म_लिखो ("%d %s\n", ret, (वर्ण *) arg);
}

शून्य cleanup4(पूर्णाङ्क ret, शून्य *arg)
{
    म_लिखो ("%d %s\n", ret, (वर्ण *) arg);
}

शून्य __attribute((destructor)) cleanup5(शून्य)
{
    म_लिखो ("cleanup5\n");
}

शून्य test(शून्य)
{
    निकास_पर(cleanup1);
    निकास_पर(cleanup2);
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
    निकास(2);
} 
#endif
