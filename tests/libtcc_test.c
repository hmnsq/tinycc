/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ "libtcc.h"

શૂન્ય handle_error(શૂન્ય *opaque, અચલ અક્ષર *સંદેશ)
{
    fprintf(opaque, "%s\n", સંદેશ);
}

/* this function is called by the generated code */
પૂર્ણાંક add(પૂર્ણાંક a, પૂર્ણાંક b)
{
    પાછા a + b;
}

/* this strinc is referenced by the generated code */
અચલ અક્ષર hello[] = "Hello World!";

અક્ષર my_program[] =
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

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    TCCState *s;
    પૂર્ણાંક i;
    પૂર્ણાંક (*func)(પૂર્ણાંક);

    s = tcc_new();
    જો (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    માટે (i = 1; i < argc; ++i) {
        અક્ષર *a = argv[i];
        જો (a[0] == '-') {
            જો (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            નહીંતર જો (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            નહીંતર જો (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    જો (tcc_compile_string(s, my_program) == -1)
        પાછા 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_પ્રતીક(s, "add", add);
    tcc_add_પ્રતીક(s, "hello", hello);

    /* relocate the code */
    જો (tcc_relocate(s) < 0)
        પાછા 1;

    /* get entry symbol */
    func = tcc_get_પ્રતીક(s, "foo");
    જો (!func)
        પાછા 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    પાછા 0;
}
