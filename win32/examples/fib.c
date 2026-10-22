#شامل <stdio.h>
#شامل <stdlib.h>	// atoi()

صحیح fib(n)
{
	اگر (n <= 2)
		واپس 1;
	ورنہ
		واپس fib(n-1) + fib(n-2);
}

صحیح مین(صحیح argc, حرف **argv) 
{
	صحیح n;
	اگر (argc < 2) {
		لکھو("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		واپس 1;
	}
		
	n = atoi(argv[1]);
	لکھو("fib(%d) = %d\n", n, fib(n));
	واپس 0;
}
