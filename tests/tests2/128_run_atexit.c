#include <stdio.h>

පූර්ණ_සංඛ්‍යා atexit(void (*function)(void));
පූර්ණ_සංඛ්‍යා on_exit(void (*function)(පූර්ණ_සංඛ්‍යා, void *), void *arg);
void exit(පූර්ණ_සංඛ්‍යා status);

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

void cleanup3(පූර්ණ_සංඛ්‍යා ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(පූර්ණ_සංඛ්‍යා ret, void *arg)
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

#නම් defined test_128_return
පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv)
{
    test();
    ආපසු 1;
} 

#elif defined test_128_exit
පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
