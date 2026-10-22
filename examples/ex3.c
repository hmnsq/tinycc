#include <tcclib.h>

ចំនួនគត់ fib(ចំនួនគត់ n)
{
    ប្រសិនបើ (n <= 2)
        ត្រឡប់ 1;
    បើមិនដូច្នេះ
        ត្រឡប់ fib(n-1) + fib(n-2);
}

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    ចំនួនគត់ n;
    ប្រសិនបើ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ត្រឡប់ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ត្រឡប់ 0;
}
