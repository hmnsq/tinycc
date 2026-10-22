#include <stdio.h>
#include <stdlib.h>	// atoi()

整数 fib(n)
{
	もし (n <= 2)
		戻る 1;
	否则
		戻る fib(n-1) + fib(n-2);
}

整数 メインページ(整数 argc, char **argv) 
{
	整数 n;
	もし (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		戻る 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	戻る 0;
}
