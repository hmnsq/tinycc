#include <stdio.h>

số_nguyên atexit(void (*function)(void));
số_nguyên on_exit(void (*function)(số_nguyên, void *), void *arg);
void exit(số_nguyên status);

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

void cleanup3(số_nguyên ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(số_nguyên ret, void *arg)
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

#nếu defined test_128_return
số_nguyên main(số_nguyên argc, char **argv)
{
    test();
    trả_về 1;
} 

#elif defined test_128_exit
số_nguyên main(số_nguyên argc, char **argv)
{
    test();
    exit(2);
} 
#endif
