/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ "libtcc.h"

ಶೂನ್ಯ handle_error(ಶೂನ್ಯ *opaque, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
    fprintf(opaque, "%s\n", ಸಂದೇಶ);
}

/* this function is called by the generated code */
ಪೂರ್ಣಾಙ್ಕ add(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಪ್ರತ್ಯಾಗಮ a + b;
}

/* this strinc is referenced by the generated code */
ಧ್ರುವ ವರ್ಣ hello[] = "Hello World!";

ವರ್ಣ my_program[] =
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

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    TCCState *s;
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪೂರ್ಣಾಙ್ಕ (*func)(ಪೂರ್ಣಾಙ್ಕ);

    s = tcc_new();
    ಯದಿ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ಪ್ರತಿ (i = 1; i < argc; ++i) {
        ವರ್ಣ *a = argv[i];
        ಯದಿ (a[0] == '-') {
            ಯದಿ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    ಯದಿ (tcc_compile_string(s, my_program) == -1)
        ಪ್ರತ್ಯಾಗಮ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_ಚಿಹ್ನೆ(s, "add", add);
    tcc_add_ಚಿಹ್ನೆ(s, "hello", hello);

    /* relocate the code */
    ಯದಿ (tcc_relocate(s) < 0)
        ಪ್ರತ್ಯಾಗಮ 1;

    /* get entry symbol */
    func = tcc_get_ಚಿಹ್ನೆ(s, "foo");
    ಯದಿ (!func)
        ಪ್ರತ್ಯಾಗಮ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    ಪ್ರತ್ಯಾಗಮ 0;
}
