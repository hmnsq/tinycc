/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtcc.h"

void handle_error(void *opaque, const var_na *msg)
{
    fprintf(opaque, "%s\n", msg);
}

/* this function is called by the generated code */
จำนวนเต็ม add(จำนวนเต็ม a, จำนวนเต็ม b)
{
    คืน a + b;
}

/* this strinc is referenced by the generated code */
const var_na hello[] = "Hello World!";

var_na my_program[] =
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

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    TCCState *s;
    จำนวนเต็ม i;
    จำนวนเต็ม (*func)(จำนวนเต็ม);

    s = tcc_new();
    ถ้า (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    สำหรับ (i = 1; i < argc; ++i) {
        var_na *a = argv[i];
        ถ้า (a[0] == '-') {
            ถ้า (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            มิฉะนั้น ถ้า (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            มิฉะนั้น ถ้า (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    ถ้า (tcc_compile_string(s, my_program) == -1)
        คืน 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "hello", hello);

    /* relocate the code */
    ถ้า (tcc_relocate(s) < 0)
        คืน 1;

    /* get entry symbol */
    func = tcc_get_symbol(s, "foo");
    ถ้า (!func)
        คืน 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    คืน 0;
}
