#ضمن <tcclib.h>

صحيح fib(صحيح n)
{
    𐤀𐤌 (n <= 2)
        أرجع 1;
    وإلا
        أرجع fib(n-1) + fib(n-2);
}

صحيح main(صحيح argc, حرف **argv)
{
    صحيح n;
    𐤀𐤌 (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        أرجع 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    أرجع 0;
}
