#include <tcclib.h>

ཧྲིལ fib(ཧྲིལ n)
{
    གལ་ཏེ (n <= 2)
        ཕྱིར 1;
    དེ་མིན
        ཕྱིར fib(n-1) + fib(n-2);
}

ཧྲིལ གཙོ(ཧྲིལ argc, var_na **argv)
{
    ཧྲིལ n;
    གལ་ཏེ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ཕྱིར 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ཕྱིར 0;
}
