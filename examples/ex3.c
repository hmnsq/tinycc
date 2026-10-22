#include <tcclib.h>

số_nguyên fib(số_nguyên n)
{
    nếu (n <= 2)
        trả_về 1;
    không_thì
        trả_về fib(n-1) + fib(n-2);
}

số_nguyên main(số_nguyên argc, char **argv)
{
    số_nguyên n;
    nếu (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        trả_về 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    trả_về 0;
}
