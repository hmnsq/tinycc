/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ "libtcc.h"

శూన్య handle_error(శూన్య *opaque, స్థిరరాశి అక్షరం *సందేశం)
{
    fprintf(opaque, "%s\n", సందేశం);
}

/* this function is called by the generated code */
పూర్ణాంకం కూడు(పూర్ణాంకం a, పూర్ణాంకం b)
{
    తిరిగి a + b;
}

/* this strinc is referenced by the generated code */
స్థిరరాశి అక్షరం hello[] = "Hello World!";

అక్షరం my_కార్యక్రమం[] =
"#include <tcclib.h>\n" /* include the "Simple libc header for TCC" */
"extern int add(int a, int b);\n"
"#ifdef _WIN32\n" /* dynamically linked data needs 'dllimport' */
" __attribute__((dllimport))\n"
"#endif\n"
"extern const char hello[];\n"
"int fib(int n)\n"
"{\n"
"    if (n <= 2)\n"
"        return 1;\n"
"    else\n"
"        return fib(n-1) + fib(n-2);\n"
"}\n"
"\n"
"int foo(int n)\n"
"{\n"
"    printf(\"%s\\n\", hello);\n"
"    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
"    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
"    return 0;\n"
"}\n";

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    TCCState *s;
    పూర్ణాంకం i;
    పూర్ణాంకం (*func)(పూర్ణాంకం);

    s = tcc_new();
    ఒకవేళ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        నిష్క్రమించు(1);
    }

    /* set custom error/warning printer */
    tcc_సమితి_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    కొరకు (i = 1; i < argc; ++i) {
        అక్షరం *a = argv[i];
        ఒకవేళ (a[0] == '-') {
            ఒకవేళ (a[1] == 'B')
                tcc_సమితి_lib_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'I')
                tcc_కూడు_include_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'L')
                tcc_కూడు_library_మార్గం(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_సమితి_output_type(s, TCC_OUTPUT_జ్ఞాపకం);

    ఒకవేళ (tcc_compile_string(s, my_కార్యక్రమం) == -1)
        తిరిగి 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_కూడు_చిహ్నం(s, "add", కూడు);
    tcc_కూడు_చిహ్నం(s, "hello", hello);

    /* relocate the code */
    ఒకవేళ (tcc_relocate(s) < 0)
        తిరిగి 1;

    /* get entry symbol */
    func = tcc_get_చిహ్నం(s, "foo");
    ఒకవేళ (!func)
        తిరిగి 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    తిరిగి 0;
}
