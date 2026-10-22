#ଅନ୍ତର୍ଭାଵ <tcclib.h>

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fib(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଯଦି (n <= 2)
        ଫେରନ୍ତୁ 1;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ fib(n-1) + fib(n-2);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
    ଯଦି (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ଫେରନ୍ତୁ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ଫେରନ୍ତୁ 0;
}
