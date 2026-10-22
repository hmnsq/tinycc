#include <tcclib.h>

整数 fib(整数 n)
{
    如果 (n <= 2)
        返回 1;
    否则
        返回 fib(n-1) + fib(n-2);
}

整数 主要(整数 argc, char **argv)
{
    整数 n;
    如果 (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        返回 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    返回 0;
}
