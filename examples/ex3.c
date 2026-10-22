#شامل <tcclib.h>

صحیح fib(صحیح n)
{
    اگر (n <= 2)
        بازگشت 1;
    وگرنه
        بازگشت fib(n-1) + fib(n-2);
}

صحیح اصلی(صحیح argc, نویسه **argv)
{
    صحیح n;
    اگر (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        بازگشت 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    بازگشت 0;
}
