#include <stdio.h>
#include <stdlib.h>	// atoi()

puur_naa_nka fib(n)
{
	ပေႃး (n <= 2)
		ပွၵ်ႈ 1;
	ပေႃးဢမ်ႇ
		ပွၵ်ႈ fib(n-1) + fib(n-2);
}

puur_naa_nka main(puur_naa_nka argc, var_na **argv) 
{
	puur_naa_nka n;
	ပေႃး (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ပွၵ်ႈ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ပွၵ်ႈ 0;
}
