#अन्तर्भाव <tcclib.h>

पूर्णाङ्क fib(पूर्णाङ्क n)
{
    सचे (n <= 2)
        पटिनिवत्त 1;
    अञ्ञथा
        पटिनिवत्त fib(n-1) + fib(n-2);
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क n;
    सचे (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        पटिनिवत्त 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    पटिनिवत्त 0;
}
