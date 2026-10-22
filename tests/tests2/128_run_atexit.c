#include <stdio.h>

จำนวนเต็ม atexit(void (*function)(void));
จำนวนเต็ม on_exit(void (*function)(จำนวนเต็ม, void *), void *arg);
void exit(จำนวนเต็ม status);

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

void cleanup3(จำนวนเต็ม ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(จำนวนเต็ม ret, void *arg)
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

#ถ้า defined test_128_return
จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    test();
    คืน 1;
} 

#elif defined test_128_exit
จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
