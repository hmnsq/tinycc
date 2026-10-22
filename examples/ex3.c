#include <tcclib.h>

puur_naa_nka fib(puur_naa_nka n)
{
    ᮚᮦᮔ᮪ (n <= 2)
        ᮝᮜᮤ 1;
    ᮜᮤᮚ
        ᮝᮜᮤ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    puur_naa_nka n;
    ᮚᮦᮔ᮪ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ᮝᮜᮤ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ᮝᮜᮤ 0;
}
