#include <tcclib.h>

цео fib(цео n)
{
    ако (n <= 2)
        врати 1;
    инако
        врати fib(n-1) + fib(n-2);
}

цео main(цео argc, char **argv)
{
    цео n;
    ако (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        врати 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    врати 0;
}
