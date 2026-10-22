/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>
#شامل "libtcc.h"

تهی handle_error(تهی *opaque, ثابت نویسه *پیام)
{
    fprintf(opaque, "%s\n", پیام);
}

/* this function is called by the generated code */
صحیح add(صحیح a, صحیح b)
{
    بازگشت a + b;
}

/* this strinc is referenced by the generated code */
ثابت نویسه hello[] = "Hello World!";

نویسه my_program[] =
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

صحیح اصلی(صحیح argc, نویسه **argv)
{
    TCCState *s;
    صحیح i;
    صحیح (*func)(صحیح);

    s = tcc_new();
    اگر (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    برای (i = 1; i < argc; ++i) {
        نویسه *a = argv[i];
        اگر (a[0] == '-') {
            اگر (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            وگرنه اگر (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            وگرنه اگر (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    اگر (tcc_compile_string(s, my_program) == -1)
        بازگشت 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_نماد(s, "add", add);
    tcc_add_نماد(s, "hello", hello);

    /* relocate the code */
    اگر (tcc_relocate(s) < 0)
        بازگشت 1;

    /* get entry symbol */
    func = tcc_get_نماد(s, "foo");
    اگر (!func)
        بازگشت 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    بازگشت 0;
}
