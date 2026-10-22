/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ "libtcc.h"

ಶೂನ್ಯ handle_error(ಶೂನ್ಯ *opaque, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
    fprintf(opaque, "%s\n", ಸಂದೇಶ);
}

/* this function is called by the generated code */
ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    ಹಿಂತಿರುಗಿ a + b;
}

/* this strinc is referenced by the generated code */
ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ hello[] = "Hello World!";

ಅಕ್ಷರ my_ಕಾರ್ಯಕ್ರಮ[] =
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

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    TCCState *s;
    ಪೂರ್ಣಾಂಕ i;
    ಪೂರ್ಣಾಂಕ (*func)(ಪೂರ್ಣಾಂಕ);

    s = tcc_new();
    ಆದರೆ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        ನಿರ್ಗಮಿಸು(1);
    }

    /* set custom error/warning printer */
    tcc_ಗಣ_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ಗಾಗಿ (i = 1; i < argc; ++i) {
        ಅಕ್ಷರ *a = argv[i];
        ಆದರೆ (a[0] == '-') {
            ಆದರೆ (a[1] == 'B')
                tcc_ಗಣ_lib_ಮಾರ್ಗ(s, a+2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[1] == 'I')
                tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(s, a+2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[1] == 'L')
                tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_ಗಣ_output_type(s, TCC_OUTPUT_ಸ್ಮರಣೆ);

    ಆದರೆ (tcc_compile_string(s, my_ಕಾರ್ಯಕ್ರಮ) == -1)
        ಹಿಂತಿರುಗಿ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s, "add", ಕೂಡಿಸು);
    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s, "hello", hello);

    /* relocate the code */
    ಆದರೆ (tcc_relocate(s) < 0)
        ಹಿಂತಿರುಗಿ 1;

    /* get entry symbol */
    func = tcc_get_ಚಿಹ್ನೆ(s, "foo");
    ಆದರೆ (!func)
        ಹಿಂತಿರುಗಿ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    ಹಿಂತಿರುಗಿ 0;
}
