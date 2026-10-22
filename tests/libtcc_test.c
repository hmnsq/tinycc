/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব "libtcc.h"

শূন্য handle_error(শূন্য *opaque, ধ্রুব বর্ণ *বার্তা)
{
    fprintf(opaque, "%s\n", বার্তা);
}

/* this function is called by the generated code */
পূর্ণাঙ্ক add(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b)
{
    প্রত্যাগম a + b;
}

/* this strinc is referenced by the generated code */
ধ্রুব বর্ণ hello[] = "Hello World!";

বর্ণ my_program[] =
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

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, বর্ণ **argv)
{
    TCCState *s;
    পূর্ণাঙ্ক i;
    পূর্ণাঙ্ক (*func)(পূর্ণাঙ্ক);

    s = tcc_new();
    যদি (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    প্রতি (i = 1; i < argc; ++i) {
        বর্ণ *a = argv[i];
        যদি (a[0] == '-') {
            যদি (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            অন্যথা যদি (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            অন্যথা যদি (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    যদি (tcc_compile_string(s, my_program) == -1)
        প্রত্যাগম 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_প্রতীক(s, "add", add);
    tcc_add_প্রতীক(s, "hello", hello);

    /* relocate the code */
    যদি (tcc_relocate(s) < 0)
        প্রত্যাগম 1;

    /* get entry symbol */
    func = tcc_get_প্রতীক(s, "foo");
    যদি (!func)
        প্রত্যাগম 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    প্রত্যাগম 0;
}
