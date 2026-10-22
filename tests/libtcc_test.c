/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtcc.h"

void handle_error(void *opaque, const char *msg)
{
    fprintf(opaque, "%s\n", msg);
}

/* this function is called by the generated code */
целое add(целое a, целое b)
{
    вернуть a + b;
}

/* this strinc is referenced by the generated code */
const char hello[] = "Hello World!";

char my_program[] =
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

целое основной(целое argc, char **argv)
{
    TCCState *s;
    целое i;
    целое (*func)(целое);

    s = tcc_new();
    если (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    для (i = 1; i < argc; ++i) {
        char *a = argv[i];
        если (a[0] == '-') {
            если (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            иначе если (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            иначе если (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    если (tcc_compile_string(s, my_program) == -1)
        вернуть 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "hello", hello);

    /* relocate the code */
    если (tcc_relocate(s) < 0)
        вернуть 1;

    /* get entry symbol */
    func = tcc_get_symbol(s, "foo");
    если (!func)
        вернуть 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    вернуть 0;
}
