#include <stdio.h>

цяло atexit(void (*function)(void));
цяло on_exit(void (*function)(цяло, void *), void *arg);
void exit(цяло status);

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

void cleanup3(цяло ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(цяло ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
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

#ако defined test_128_return
цяло main(цяло argc, char **argv)
{
    test();
    върни 1;
} 

#elif defined test_128_exit
цяло main(цяло argc, char **argv)
{
    test();
    exit(2);
} 
#endif
