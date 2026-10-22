#include <stdio.h>
#include <stdlib.h>	// atoi()

puur_naa_nka fib(n)
{
	ᯀᯮᯝ (n <= 2)
		ᯀᯮᯞ 1;
	ᯀᯮᯝᯂᯪ
		ᯀᯮᯞ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv) 
{
	puur_naa_nka n;
	ᯀᯮᯝ (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ᯀᯮᯞ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ᯀᯮᯞ 0;
}
