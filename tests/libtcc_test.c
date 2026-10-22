/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <string.h>
#समावेश "libtcc.h"

व्योम handle_error(व्योम *opaque, स्थिर अक्षर *संदेश)
{
    ख_लिखो(opaque, "%s\n", संदेश);
}

/* this function is called by the generated code */
पूर्णांक add(पूर्णांक a, पूर्णांक b)
{
    वापस a + b;
}

/* this strinc is referenced by the generated code */
स्थिर अक्षर hello[] = "Hello World!";

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

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    TCCState *s;
    पूर्णांक i;
    पूर्णांक (*func)(पूर्णांक);

    s = tcc_new();
    अगर (!s) {
        ख_लिखो(मानक_त्रुटि, "Could not create tcc state\n");
        निकास(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, मानक_त्रुटि, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    क्रम (i = 1; i < argc; ++i) {
        अक्षर *a = argv[i];
        अगर (a[0] == '-') {
            अगर (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अन्यथा अगर (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अन्यथा अगर (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    अगर (tcc_compile_string(s, my_program) == -1)
        वापस 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_प्रतीक(s, "add", add);
    tcc_add_प्रतीक(s, "hello", hello);

    /* relocate the code */
    अगर (tcc_relocate(s) < 0)
        वापस 1;

    /* get entry symbol */
    func = tcc_get_प्रतीक(s, "foo");
    अगर (!func)
        वापस 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    वापस 0;
}
