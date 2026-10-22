#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdlib.h>	// atoi()

முழு fib(n)
{
	எனில் (n <= 2)
		திரும்பு 1;
	இல்லையெனில்
		திரும்பு fib(n-1) + fib(n-2);
}

முழு முதன்மை(முழு argc, எழுத்து **argv) 
{
	முழு n;
	எனில் (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		திரும்பு 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	திரும்பு 0;
}
