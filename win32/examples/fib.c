#include <stdio.h>
#include <stdlib.h>	// atoi()

පූර්ණ_සංඛ්‍යා fib(n)
{
	නම් (n <= 2)
		ආපසු 1;
	නැතහොත්
		ආපසු fib(n-1) + fib(n-2);
}

පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv) 
{
	පූර්ණ_සංඛ්‍යා n;
	නම් (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ආපසු 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ආපසු 0;
}
