#ಅನ್ತರ್ಭಾವ <tcclib.h>

ಪೂರ್ಣಾಙ್ಕ fib(ಪೂರ್ಣಾಙ್ಕ n)
{
    ಯದಿ (n <= 2)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ fib(n-1) + fib(n-2);
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ n;
    ಯದಿ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ಪ್ರತ್ಯಾಗಮ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ಪ್ರತ್ಯಾಗಮ 0;
}
