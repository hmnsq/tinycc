/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव "libtcc.h"

शून्य handle_error(शून्य *opaque, स्थिरांक अक्षर *संदेश)
{
    ख_लिखो(opaque, "%s\n", संदेश);
}

/* this function is called by the generated code */
पूर्णांक add(पूर्णांक a, पूर्णांक b)
{
    परत a + b;
}

/* this strinc is referenced by the generated code */
स्थिरांक अक्षर hello[] = "Hello World!";

अक्षर my_program[] =
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

पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    TCCState *s;
    पूर्णांक i;
    पूर्णांक (*func)(पूर्णांक);

    s = tcc_new();
    जर (!s) {
        ख_लिखो(मानक_त्रुटि, "Could not create tcc state\n");
        निकास(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, मानक_त्रुटि, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    साठी (i = 1; i < argc; ++i) {
        अक्षर *a = argv[i];
        जर (a[0] == '-') {
            जर (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अन्यथा जर (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अन्यथा जर (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    जर (tcc_compile_string(s, my_program) == -1)
        परत 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_चिन्ह(s, "add", add);
    tcc_add_चिन्ह(s, "hello", hello);

    /* relocate the code */
    जर (tcc_relocate(s) < 0)
        परत 1;

    /* get entry symbol */
    func = tcc_get_चिन्ह(s, "foo");
    जर (!func)
        परत 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    परत 0;
}
