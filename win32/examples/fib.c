#include <stdio.h>
#include <stdlib.h>	// atoi()

puur_naa_nka fib(n)
{
	ᤀᤡ᤺ (n <= 2)
		ᤀᤡᤴ 1;
	ᤀᤡ᤺ᤆᤡ
		ᤀᤡᤴ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv) 
{
	puur_naa_nka n;
	ᤀᤡ᤺ (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ᤀᤡᤴ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ᤀᤡᤴ 0;
}
