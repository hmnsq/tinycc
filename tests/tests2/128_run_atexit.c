#समावेश <stdio.h>

पूर्णांक निकास_पर(व्योम (*function)(व्योम));
पूर्णांक on_exit(व्योम (*function)(पूर्णांक, व्योम *), व्योम *arg);
व्योम निकास(पूर्णांक status);

व्योम __attribute((constructor)) startup5(व्योम)
{
    म_लिखो ("startup5\n");
}

व्योम cleanup1(व्योम)
{
    म_लिखो ("cleanup1\n");
    ख_साफ(मानक_निकास);
}

व्योम cleanup2(व्योम)
{
    म_लिखो ("cleanup2\n");
}

व्योम cleanup3(पूर्णांक ret, व्योम *arg)
{
    म_लिखो ("%d %s\n", ret, (अक्षर *) arg);
}

व्योम cleanup4(पूर्णांक ret, व्योम *arg)
{
    म_लिखो ("%d %s\n", ret, (अक्षर *) arg);
}

व्योम __attribute((destructor)) cleanup5(व्योम)
{
    म_लिखो ("cleanup5\n");
}

व्योम test(व्योम)
{
    निकास_पर(cleanup1);
    निकास_पर(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#अगर defined test_128_return
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    test();
    वापस 1;
} 

#या_अगर defined test_128_exit
पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    test();
    निकास(2);
} 
#पूर्ण_अगर
