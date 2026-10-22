#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>	// atoi()

पूर्णांक fib(n)
{
	जर (n <= 2)
		परत 1;
	अन्यथा
		परत fib(n-1) + fib(n-2);
}

पूर्णांक main(पूर्णांक argc, अक्षर **argv) 
{
	पूर्णांक n;
	जर (argc < 2) {
		म_लिखो("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		परत 1;
	}
		
	n = म_से_प(argv[1]);
	म_लिखो("fib(%d) = %d\n", n, fib(n));
	परत 0;
}
