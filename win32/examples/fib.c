#include <stdio.h>
#include <stdlib.h>	// atoi()

puur_naa_nka fib(n)
{
	ᨀᨘ (n <= 2)
		ᨀᨘᨒ 1;
	ᨀᨘᨁ
		ᨀᨘᨒ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv) 
{
	puur_naa_nka n;
	ᨀᨘ (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ᨀᨘᨒ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ᨀᨘᨒ 0;
}
