#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಙ್ಕ atexit(ಶೂನ್ಯ (*function)(ಶೂನ್ಯ));
ಪೂರ್ಣಾಙ್ಕ on_exit(ಶೂನ್ಯ (*function)(ಪೂರ್ಣಾಙ್ಕ, ಶೂನ್ಯ *), ಶೂನ್ಯ *arg);
ಶೂನ್ಯ exit(ಪೂರ್ಣಾಙ್ಕ status);

ಶೂನ್ಯ __attribute((constructor)) startup5(ಶೂನ್ಯ)
{
    printf ("startup5\n");
}

ಶೂನ್ಯ cleanup1(ಶೂನ್ಯ)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

ಶೂನ್ಯ cleanup2(ಶೂನ್ಯ)
{
    printf ("cleanup2\n");
}

ಶೂನ್ಯ cleanup3(ಪೂರ್ಣಾಙ್ಕ ret, ಶೂನ್ಯ *arg)
{
    printf ("%d %s\n", ret, (ವರ್ಣ *) arg);
}

ಶೂನ್ಯ cleanup4(ಪೂರ್ಣಾಙ್ಕ ret, ಶೂನ್ಯ *arg)
{
    printf ("%d %s\n", ret, (ವರ್ಣ *) arg);
}

ಶೂನ್ಯ __attribute((destructor)) cleanup5(ಶೂನ್ಯ)
{
    printf ("cleanup5\n");
}

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ಯದಿ defined test_128_return
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    test();
    ಪ್ರತ್ಯಾಗಮ 1;
} 

#ನೋಚೇದ್ಯದಿ defined test_128_exit
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    test();
    exit(2);
} 
#endif
