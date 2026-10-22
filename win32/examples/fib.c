#समावेश <stdio.h>
#समावेश <stdlib.h>	// atoi()

पूर्णांक fib(n)
{
	अगर (n <= 2)
		वापस 1;
	अन्यथा
		वापस fib(n-1) + fib(n-2);
}

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv) 
{
	पूर्णांक n;
	अगर (argc < 2) {
		म_लिखो("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		वापस 1;
	}
		
	n = म_से_प(argv[1]);
	म_लिखो("fib(%d) = %d\n", n, fib(n));
	वापस 0;
}
