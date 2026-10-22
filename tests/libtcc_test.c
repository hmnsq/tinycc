/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ "libtcc.h"

வெறுமை handle_error(வெறுமை *opaque, மாறிலி எழுத்து *செய்தி)
{
    fprintf(opaque, "%s\n", செய்தி);
}

/* this function is called by the generated code */
முழு add(முழு a, முழு b)
{
    திரும்பு a + b;
}

/* this strinc is referenced by the generated code */
மாறிலி எழுத்து hello[] = "Hello World!";

எழுத்து my_program[] =
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

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    TCCState *s;
    முழு i;
    முழு (*func)(முழு);

    s = tcc_new();
    எனில் (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    க்கு (i = 1; i < argc; ++i) {
        எழுத்து *a = argv[i];
        எனில் (a[0] == '-') {
            எனில் (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            இல்லையெனில் எனில் (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            இல்லையெனில் எனில் (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    எனில் (tcc_compile_string(s, my_program) == -1)
        திரும்பு 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_குறியீடு(s, "add", add);
    tcc_add_குறியீடு(s, "hello", hello);

    /* relocate the code */
    எனில் (tcc_relocate(s) < 0)
        திரும்பு 1;

    /* get entry symbol */
    func = tcc_get_குறியீடு(s, "foo");
    எனில் (!func)
        திரும்பு 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    திரும்பு 0;
}
