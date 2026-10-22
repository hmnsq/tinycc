#include <tcclib.h>

ကိန်းပြည့် fib(ကိန်းပြည့် n)
{
    အကယ်၍ (n <= 2)
        ပြန်ပေး 1;
    မဟုတ်ပါက
        ပြန်ပေး fib(n-1) + fib(n-2);
}

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    ကိန်းပြည့် n;
    အကယ်၍ (argc < 2) {
        printf("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        ပြန်ပေး 1;
    }

    n = atoi(argv[1]);
    printf("fib(%d) = %d\n", n, fib(n));
    ပြန်ပေး 0;
}
