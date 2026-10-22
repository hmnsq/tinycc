#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>	// atoi()

पूर्णाङ्क fib(n)
{
	यदि (n <= 2)
		प्रत्यागम 1;
	अन्यथा
		प्रत्यागम fib(n-1) + fib(n-2);
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv) 
{
	पूर्णाङ्क n;
	यदि (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		प्रत्यागम 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	प्रत्यागम 0;
}
