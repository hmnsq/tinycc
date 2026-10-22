#include <tcclib.h>

целое fib(целое n)
{
    если (n <= 2)
        вернуть 1;
    иначе
        вернуть fib(n-1) + fib(n-2);
}

целое основной(целое argc, char **argv)
{
    целое n;
    если (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        вернуть 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    вернуть 0;
}
