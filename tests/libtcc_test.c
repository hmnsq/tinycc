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
puur_naa_nka add(puur_naa_nka a, puur_naa_nka b)
{
    ᱨᱩᱣᱟᱹᱲ a + b;
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

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    TCCState *s;
    puur_naa_nka i;
    puur_naa_nka (*func)(puur_naa_nka);

    s = tcc_new();
    ᱡᱩᱫᱤ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    for (i = 1; i < argc; ++i) {
        var_na *a = argv[i];
        ᱡᱩᱫᱤ (a[0] == '-') {
            ᱡᱩᱫᱤ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ᱵᱟᱝ ᱡᱩᱫᱤ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ᱵᱟᱝ ᱡᱩᱫᱤ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    ᱡᱩᱫᱤ (tcc_compile_string(s, my_program) == -1)
        ᱨᱩᱣᱟᱹᱲ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "hello", hello);

    /* relocate the code */
    ᱡᱩᱫᱤ (tcc_relocate(s) < 0)
        ᱨᱩᱣᱟᱹᱲ 1;

    /* get entry symbol */
    func = tcc_get_symbol(s, "foo");
    ᱡᱩᱫᱤ (!func)
        ᱨᱩᱣᱟᱹᱲ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    ᱨᱩᱣᱟᱹᱲ 0;
}
