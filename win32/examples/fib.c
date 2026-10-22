#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>	// atoi()

పూర్ణాంకం fib(n)
{
	ఒకవేళ (n <= 2)
		తిరిగి 1;
	లేకపోతే
		తిరిగి fib(n-1) + fib(n-2);
}

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv) 
{
	పూర్ణాంకం n;
	ఒకవేళ (argc < 2) {
		రాయి("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		తిరిగి 1;
	}
		
	n = atoi(argv[1]);
	రాయి("fib(%d) = %d\n", n, fib(n));
	తిరిగి 0;
}
