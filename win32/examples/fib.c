#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <stdlib.h>	// atoi()

পূর্ণাঙ্ক fib(n)
{
	যদি (n <= 2)
		প্রত্যাগম 1;
	অন্যথা
		প্রত্যাগম fib(n-1) + fib(n-2);
}

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv) 
{
	পূর্ণাঙ্ক n;
	যদি (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		প্রত্যাগম 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	প্রত্যাগম 0;
}
