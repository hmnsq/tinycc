/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>
#شامل "libtcc.h"

خالی handle_error(خالی *opaque, ثابت حرف *پیغام)
{
    fprintf(opaque, "%s\n", پیغام);
}

/* this function is called by the generated code */
صحیح جوڑو(صحیح a, صحیح b)
{
    واپس a + b;
}

/* this strinc is referenced by the generated code */
ثابت حرف hello[] = "Hello World!";

حرف my_پروگرام[] =
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

صحیح مین(صحیح argc, حرف **argv)
{
    TCCState *s;
    صحیح i;
    صحیح (*func)(صحیح);

    s = tcc_new();
    اگر (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        باہر_نکلو(1);
    }

    /* set custom error/warning printer */
    tcc_سیٹ_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    برائے (i = 1; i < argc; ++i) {
        حرف *a = argv[i];
        اگر (a[0] == '-') {
            اگر (a[1] == 'B')
                tcc_سیٹ_lib_راستہ(s, a+2);
            ورنہ اگر (a[1] == 'I')
                tcc_جوڑو_include_راستہ(s, a+2);
            ورنہ اگر (a[1] == 'L')
                tcc_جوڑو_library_راستہ(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_سیٹ_output_type(s, TCC_OUTPUT_حافظہ);

    اگر (tcc_compile_string(s, my_پروگرام) == -1)
        واپس 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_جوڑو_علامت(s, "add", جوڑو);
    tcc_جوڑو_علامت(s, "hello", hello);

    /* relocate the code */
    اگر (tcc_relocate(s) < 0)
        واپس 1;

    /* get entry symbol */
    func = tcc_get_علامت(s, "foo");
    اگر (!func)
        واپس 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    واپس 0;
}
