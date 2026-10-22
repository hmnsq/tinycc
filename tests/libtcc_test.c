/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ "libtcc.h"

ശൂന്യം handle_error(ശൂന്യം *opaque, സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
    fprintf(opaque, "%s\n", സന്ദേശം);
}

/* this function is called by the generated code */
പൂർണ്ണസംഖ്യ add(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    തിരികെ a + b;
}

/* this strinc is referenced by the generated code */
സ്ഥിരം അക്ഷരം hello[] = "Hello World!";

അക്ഷരം my_program[] =
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

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    TCCState *s;
    പൂർണ്ണസംഖ്യ i;
    പൂർണ്ണസംഖ്യ (*func)(പൂർണ്ണസംഖ്യ);

    s = tcc_new();
    എങ്കിൽ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    വേണ്ടി (i = 1; i < argc; ++i) {
        അക്ഷരം *a = argv[i];
        എങ്കിൽ (a[0] == '-') {
            എങ്കിൽ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    എങ്കിൽ (tcc_compile_string(s, my_program) == -1)
        തിരികെ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_ചിഹ്നം(s, "add", add);
    tcc_add_ചിഹ്നം(s, "hello", hello);

    /* relocate the code */
    എങ്കിൽ (tcc_relocate(s) < 0)
        തിരികെ 1;

    /* get entry symbol */
    func = tcc_get_ചിഹ്നം(s, "foo");
    എങ്കിൽ (!func)
        തിരികെ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    തിരികെ 0;
}
