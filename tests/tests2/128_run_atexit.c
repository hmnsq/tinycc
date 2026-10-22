#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪೂರ್ಣಾಂಕ atexit(ಶೂನ್ಯ (*function)(ಶೂನ್ಯ));
ಪೂರ್ಣಾಂಕ on_exit(ಶೂನ್ಯ (*function)(ಪೂರ್ಣಾಂಕ, ಶೂನ್ಯ *), ಶೂನ್ಯ *arg);
ಶೂನ್ಯ ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ ಸ್ಥಿತಿ_2);

ಶೂನ್ಯ __attribute((constructor)) startup5(ಶೂನ್ಯ)
{
    ಬರೆ ("startup5\n");
}

ಶೂನ್ಯ cleanup1(ಶೂನ್ಯ)
{
    ಬರೆ ("cleanup1\n");
    fflush(stdout);
}

ಶೂನ್ಯ cleanup2(ಶೂನ್ಯ)
{
    ಬರೆ ("cleanup2\n");
}

ಶೂನ್ಯ cleanup3(ಪೂರ್ಣಾಂಕ ret, ಶೂನ್ಯ *arg)
{
    ಬರೆ ("%d %s\n", ret, (ಅಕ್ಷರ *) arg);
}

ಶೂನ್ಯ cleanup4(ಪೂರ್ಣಾಂಕ ret, ಶೂನ್ಯ *arg)
{
    ಬರೆ ("%d %s\n", ret, (ಅಕ್ಷರ *) arg);
}

ಶೂನ್ಯ __attribute((destructor)) cleanup5(ಶೂನ್ಯ)
{
    ಬರೆ ("cleanup5\n");
}

ಶೂನ್ಯ test(ಶೂನ್ಯ)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ಆದರೆ defined test_128_return
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    test();
    ಹಿಂತಿರುಗಿ 1;
} 

#ಅಥವಾಆದರೆ defined test_128_exit
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    test();
    ನಿರ್ಗಮಿಸು(2);
} 
#ಆದರೆ_ಅಂತ್ಯ
