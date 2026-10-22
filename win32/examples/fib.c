#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdlib.h>	// atoi()

পূর্ণসংখ্যা fib(n)
{
	যদি (n <= 2)
		ফেরত 1;
	অন্যথা
		ফেরত fib(n-1) + fib(n-2);
}

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv) 
{
	পূর্ণসংখ্যা n;
	যদি (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ফেরত 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ফেরত 0;
}
