#include <stdio.h>

ཧྲིལ atexit(void (*function)(void));
ཧྲིལ on_exit(void (*function)(ཧྲིལ, void *), void *arg);
void exit(ཧྲིལ status);

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

void cleanup3(ཧྲིལ ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(ཧྲིལ ret, void *arg)
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

#གལ་སྲིད defined test_128_return
ཧྲིལ main(ཧྲིལ argc, var_na **argv)
{
    test();
    ལོག 1;
} 

#elif defined test_128_exit
ཧྲིལ main(ཧྲིལ argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
