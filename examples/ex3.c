#ಅನ್ತರ್ಭಾವ <tcclib.h>

ಪೂರ್ಣಾಂಕ fib(ಪೂರ್ಣಾಂಕ n)
{
    ಆದರೆ (n <= 2)
        ಹಿಂತಿರುಗಿ 1;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ fib(n-1) + fib(n-2);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ n;
    ಆದರೆ (argc < 2) {
        ಬರೆ("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ಹಿಂತಿರುಗಿ 1;
    }

    n = atoi(argv[1]);
    ಬರೆ("fib(%d) = %d\n", n, fib(n));
    ಹಿಂತಿರುಗಿ 0;
}
