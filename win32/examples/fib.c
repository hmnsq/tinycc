#include <stdio.h>
#include <stdlib.h>	// atoi()

цяло fib(n)
{
	ако (n <= 2)
		върни 1;
	иначе
		върни fib(n-1) + fib(n-2);
}

цяло main(цяло argc, char **argv) 
{
	цяло n;
	ако (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		върни 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	върни 0;
}
