#include <stdio.h>

整数 atexit(void (*function)(void));
整数 on_exit(void (*function)(整数, void *), void *arg);
void exit(整数 status);

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

void cleanup3(整数 ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(整数 ret, void *arg)
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

#もし defined test_128_return
整数 メインページ(整数 argc, char **argv)
{
    test();
    戻る 1;
} 

#elif defined test_128_exit
整数 メインページ(整数 argc, char **argv)
{
    test();
    exit(2);
} 
#endif
