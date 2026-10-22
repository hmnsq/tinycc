#include <stdio.h>

цео atexit(void (*function)(void));
цео on_exit(void (*function)(цео, void *), void *arg);
void exit(цео status);

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

void cleanup3(цео ret, void *arg)
{
    printf ("%d %s\n", ret, (char *) arg);
}

void cleanup4(цео ret, void *arg)
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
цео main(цео argc, char **argv)
{
    test();
    врати 1;
} 

#elif defined test_128_exit
цео main(цео argc, char **argv)
{
    test();
    exit(2);
} 
#endif
