#include <stdio.h>

ចំនួនគត់ atexit(void (*function)(void));
ចំនួនគត់ on_exit(void (*function)(ចំនួនគត់, void *), void *arg);
void exit(ចំនួនគត់ status);

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

void cleanup3(ចំនួនគត់ ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(ចំនួនគត់ ret, void *arg)
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

#ប្រសិនបើ defined test_128_return
ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    test();
    ត្រឡប់ 1;
} 

#elif defined test_128_exit
ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
