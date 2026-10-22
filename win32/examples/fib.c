#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <stdlib.h>	// atoi()

പൂർണ്ണസംഖ്യ fib(n)
{
	എങ്കിൽ (n <= 2)
		തിരികെ 1;
	അല്ലെങ്കിൽ
		തിരികെ fib(n-1) + fib(n-2);
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv) 
{
	പൂർണ്ണസംഖ്യ n;
	എങ്കിൽ (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		തിരികെ 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	തിരികെ 0;
}
