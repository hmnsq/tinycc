#include <stdio.h>
#include <stdlib.h>	// atoi()

ціле fib(n)
{
	якщо (n <= 2)
		повернути 1;
	інакше
		повернути fib(n-1) + fib(n-2);
}

ціле main(ціле argc, char **argv) 
{
	ціле n;
	якщо (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		повернути 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	повернути 0;
}
