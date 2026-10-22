#અન્તર્ભાવ <tcclib.h>

પૂર્ણાંક fib(પૂર્ણાંક n)
{
    જો (n <= 2)
        પાછા 1;
    નહીંતર
        પાછા fib(n-1) + fib(n-2);
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક n;
    જો (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        પાછા 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    પાછા 0;
}
