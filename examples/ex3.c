#ضمن <tcclib.h>

صحيح fib(صحيح n)
{
    אם (n <= 2)
        החזר 1;
    אחרת
        החזר fib(n-1) + fib(n-2);
}

صحيح main(صحيح argc, حرف **argv)
{
    صحيح n;
    אם (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        החזר 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    החזר 0;
}
