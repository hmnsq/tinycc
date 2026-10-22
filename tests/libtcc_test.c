/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ "libtcc.h"

ଶୂନ୍ୟ handle_error(ଶୂନ୍ୟ *opaque, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
    fprintf(opaque, "%s\n", ସନ୍ଦେଶ);
}

/* this function is called by the generated code */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା add(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଫେରନ୍ତୁ a + b;
}

/* this strinc is referenced by the generated code */
ଅଚଳ ଅକ୍ଷର hello[] = "Hello World!";

ଅକ୍ଷର my_program[] =
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    TCCState *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*func)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

    s = tcc_new();
    ଯଦି (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ପାଇଁ (i = 1; i < argc; ++i) {
        ଅକ୍ଷର *a = argv[i];
        ଯଦି (a[0] == '-') {
            ଯଦି (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ଅନ୍ୟଥା ଯଦି (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ଅନ୍ୟଥା ଯଦି (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    ଯଦି (tcc_compile_string(s, my_program) == -1)
        ଫେରନ୍ତୁ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_ପ୍ରତୀକ(s, "add", add);
    tcc_add_ପ୍ରତୀକ(s, "hello", hello);

    /* relocate the code */
    ଯଦି (tcc_relocate(s) < 0)
        ଫେରନ୍ତୁ 1;

    /* get entry symbol */
    func = tcc_get_ପ୍ରତୀକ(s, "foo");
    ଯଦି (!func)
        ଫେରନ୍ତୁ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    ଫେରନ୍ତୁ 0;
}
