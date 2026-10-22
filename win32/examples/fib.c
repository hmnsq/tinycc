#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <stdlib.h>	// atoi()

পূর্ণাঙ্ক fib(n)
{
	যদি (n <= 2)
		ঘূৰাই 1;
	অন্যথা
		ঘূৰাই fib(n-1) + fib(n-2);
}

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv) 
{
	পূর্ণাঙ্ক n;
	যদি (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		ঘূৰাই 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	ঘূৰাই 0;
}
