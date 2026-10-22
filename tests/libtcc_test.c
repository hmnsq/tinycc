/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>
#ضمن "libtcc.h"

فراغ handle_error(فراغ *opaque, ثابت حرف *رسالة)
{
    fprintf(opaque, "%s\n", رسالة);
}

/* this function is called by the generated code */
صحيح add(صحيح a, صحيح b)
{
    أرجع a + b;
}

/* this strinc is referenced by the generated code */
ثابت حرف hello[] = "Hello World!";

حرف my_program[] =
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

صحيح main(صحيح argc, حرف **argv)
{
    TCCState *s;
    صحيح i;
    صحيح (*func)(صحيح);

    s = tcc_new();
    إذا (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    لكل (i = 1; i < argc; ++i) {
        حرف *a = argv[i];
        إذا (a[0] == '-') {
            إذا (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            وإلا إذا (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            وإلا إذا (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    إذا (tcc_compile_string(s, my_program) == -1)
        أرجع 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_رمز(s, "add", add);
    tcc_add_رمز(s, "hello", hello);

    /* relocate the code */
    إذا (tcc_relocate(s) < 0)
        أرجع 1;

    /* get entry symbol */
    func = tcc_get_رمز(s, "foo");
    إذا (!func)
        أرجع 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    أرجع 0;
}
