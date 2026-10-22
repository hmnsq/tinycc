#ضمن <tcclib.h>

صحيح fib(صحيح n)
{
    ܐܢ (n <= 2)
        ܦܢܐ 1;
    ܐܚܪܢܐ
        ܦܢܐ fib(n-1) + fib(n-2);
}

صحيح main(صحيح argc, حرف **argv)
{
    صحيح n;
    ܐܢ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ܦܢܐ 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ܦܢܐ 0;
}
