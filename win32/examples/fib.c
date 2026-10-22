#ضمن <stdio.h>
#ضمن <stdlib.h>	// atoi()

صحيح fib(n)
{
	إذا (n <= 2)
		أرجع 1;
	وإلا
		أرجع fib(n-1) + fib(n-2);
}

صحيح مکھ(صحيح argc, حرف **argv) 
{
	صحيح n;
	إذا (argc < 2) {
		لکھو("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		أرجع 1;
	}
		
	n = atoi(argv[1]);
	لکھو("fib(%d) = %d\n", n, fib(n));
	أرجع 0;
}
