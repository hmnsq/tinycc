#include <stdio.h>

целое atexit(void (*function)(void));
целое on_exit(void (*function)(целое, void *), void *arg);
void exit(целое status);

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

void cleanup3(целое ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(целое ret, void *arg)
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

#если defined test_128_return
целое основной(целое argc, char **argv)
{
    test();
    вернуть 1;
} 

#elif defined test_128_exit
целое основной(целое argc, char **argv)
{
    test();
    exit(2);
} 
#endif
