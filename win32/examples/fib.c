#include <stdio.h>
#include <stdlib.h>	// atoi()

ຈຳນວນເຕັມ fib(n)
{
	ຖ້າ (n <= 2)
		ສົ່ງຄືນ 1;
	ບໍ່ດັ່ງນັ້ນ
		ສົ່ງຄືນ fib(n-1) + fib(n-2);
}

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv) 
{
	ຈຳນວນເຕັມ n;
	ຖ້າ (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ສົ່ງຄືນ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ສົ່ງຄືນ 0;
}
