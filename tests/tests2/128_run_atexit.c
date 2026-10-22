#include <stdio.h>

정수 atexit(void (*function)(void));
정수 on_exit(void (*function)(정수, void *), void *arg);
void exit(정수 status);

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

void cleanup3(정수 ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(정수 ret, void *arg)
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

#만약 defined test_128_return
정수 main(정수 argc, char **argv)
{
    test();
    반환 1;
} 

#elif defined test_128_exit
정수 main(정수 argc, char **argv)
{
    test();
    exit(2);
} 
#endif
