#include <tcclib.h>

ཧྲིལ fib(ཧྲིལ n)
{
    གལ་སྲིད (n <= 2)
        ལོག 1;
    དེ་མིན
        ལོག fib(n-1) + fib(n-2);
}

ཧྲིལ main(ཧྲིལ argc, var_na **argv)
{
    ཧྲིལ n;
    གལ་སྲིད (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ལོག 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ལོག 0;
}
