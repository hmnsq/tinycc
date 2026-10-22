#include <stdio.h>

puur_naa_nka atexit(void (*function)(void));
puur_naa_nka on_exit(void (*function)(puur_naa_nka, void *), void *arg);
void exit(puur_naa_nka status);

void __attribute((constructor)) startup5(void)
{
    printf ("startup5\n");
}

void cleanup1(void)
{
    printf ("cleanup1\n");
    fflush(stdout);
}

void cleanup2(void)
{
    printf ("cleanup2\n");
}

void cleanup3(puur_naa_nka ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(puur_naa_nka ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void __attribute((destructor)) cleanup5(void)
{
    printf ("cleanup5\n");
}

void test(void)
{
    atexit(cleanup1);
    atexit(cleanup2);
    on_exit(cleanup3, "cleanup3");
    on_exit(cleanup4, "cleanup4");
}

#ᤀᤡ᤺ defined test_128_return
puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    test();
    ᤀᤡᤴ 1;
} 

#elif defined test_128_exit
puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
