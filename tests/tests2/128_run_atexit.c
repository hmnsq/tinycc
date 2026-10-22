#include <stdio.h>

ຈຳນວນເຕັມ atexit(void (*function)(void));
ຈຳນວນເຕັມ on_exit(void (*function)(ຈຳນວນເຕັມ, void *), void *arg);
void exit(ຈຳນວນເຕັມ status);

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

void cleanup3(ຈຳນວນເຕັມ ret, void *arg)
{
    printf ("%d %s\n", ret, (var_na *) arg);
}

void cleanup4(ຈຳນວນເຕັມ ret, void *arg)
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

#ຖ້າ defined test_128_return
ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    test();
    ສົ່ງຄືນ 1;
} 

#elif defined test_128_exit
ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    test();
    exit(2);
} 
#endif
