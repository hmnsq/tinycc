#ضمن <tcclib.h>

صحيح fib(صحيح n)
{
    إذا (n <= 2)
        أرجع 1;
    وإلا
        أرجع fib(n-1) + fib(n-2);
}

صحيح اصلی(صحيح argc, حرف **argv)
{
    صحيح n;
    إذا (argc < 2) {
        چاپ_کن("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        أرجع 1;
    }

    n = atoi(argv[1]);
    چاپ_کن("fib(%d) = %d\n", n, fib(n));
    أرجع 0;
}
