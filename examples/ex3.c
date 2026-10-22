#include <tcclib.h>

puur_naa_nka fib(puur_naa_nka n)
{
    ᬬᬾᬦ᭄ (n <= 2)
        ᬯᬮᬶ 1;
    ᬮᬶᬬ
        ᬯᬮᬶ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    puur_naa_nka n;
    ᬬᬾᬦ᭄ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ᬯᬮᬶ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ᬯᬮᬶ 0;
}
