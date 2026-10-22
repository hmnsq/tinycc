#include <tcclib.h>

정수 fib(정수 n)
{
    만약 (n <= 2)
        반환 1;
    아니면
        반환 fib(n-1) + fib(n-2);
}

정수 main(정수 argc, char **argv)
{
    정수 n;
    만약 (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        반환 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    반환 0;
}
