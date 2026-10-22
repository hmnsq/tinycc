#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>	// atoi()

ਪੂਰਨ fib(n)
{
	ਜੇ (n <= 2)
		ਵਾਪਸ 1;
	ਨਹੀਂਤਾਂ
		ਵਾਪਸ fib(n-1) + fib(n-2);
}

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv) 
{
	ਪੂਰਨ n;
	ਜੇ (argc < 2) {
		ਲਿਖੋ("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ਵਾਪਸ 1;
	}
		
	n = atoi(argv[1]);
	ਲਿਖੋ("fib(%d) = %d\n", n, fib(n));
	ਵਾਪਸ 0;
}
