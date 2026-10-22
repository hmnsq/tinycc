#include <stdio.h>

ကိန်းပြည့် atexit(void (*function)(void));
ကိန်းပြည့် on_exit(void (*function)(ကိန်းပြည့်, void *), void *arg);
void exit(ကိန်းပြည့် status);

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

void cleanup3(ကိန်းပြည့် ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(ကိန်းပြည့် ret, void *arg)
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

#အကယ်၍ defined test_128_return
ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    test();
    ပြန်ပေး 1;
} 

#elif defined test_128_exit
ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
