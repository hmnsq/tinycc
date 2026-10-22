#ضمن <tcclib.h>

صحيح fib(صحيح n)
{
    إذا (n <= 2)
        إرجاع 1;
    وإلا
        إرجاع fib(n-1) + fib(n-2);
}

صحيح الرئيسية(صحيح argc, حرف **argv)
{
    صحيح n;
    إذا (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        إرجاع 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    إرجاع 0;
}
