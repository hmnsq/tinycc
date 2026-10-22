#include <stdio.h>
#include <stdlib.h>	// atoi()

จำนวนเต็ม fib(n)
{
	ถ้า (n <= 2)
		คืน 1;
	มิฉะนั้น
		คืน fib(n-1) + fib(n-2);
}

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv) 
{
	จำนวนเต็ม n;
	ถ้า (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		คืน 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	คืน 0;
}
