#अन्तर्भाव <tcclib.h>

पूर्णाङ्क fib(पूर्णाङ्क n)
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
        म_लिखो("usage: fib n\n"
               "Compute nth Fibonacci number\n");
        प्रत्यागम 1;
    }

    n = म_से_प(argv[1]);
    म_लिखो("fib(%d) = %d\n", n, fib(n));
    प्रत्यागम 0;
}
