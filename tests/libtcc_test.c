/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव "libtcc.h"

शून्य handle_error(शून्य *opaque, अचर वर्ण *सन्देश)
{
    ख_लिखो(opaque, "%s\n", सन्देश);
}

/* this function is called by the generated code */
पूर्णाङ्क add(पूर्णाङ्क a, पूर्णाङ्क b)
{
    फर्काऊ a + b;
}

/* this strinc is referenced by the generated code */
अचर वर्ण hello[] = "Hello World!";

वर्ण my_program[] =
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

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    TCCState *s;
    पूर्णाङ्क i;
    पूर्णाङ्क (*func)(पूर्णाङ्क);

    s = tcc_new();
    यदि (!s) {
        ख_लिखो(मानक_त्रुटि, "Could not create tcc state\n");
        निकास(1);
    }

    /* set custom error/warning printer */
    tcc_set_error_func(s, मानक_त्रुटि, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    लागि (i = 1; i < argc; ++i) {
        वर्ण *a = argv[i];
        यदि (a[0] == '-') {
            यदि (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अन्यथा यदि (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अन्यथा यदि (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    यदि (tcc_compile_string(s, my_program) == -1)
        फर्काऊ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_add_चिह्न(s, "add", add);
    tcc_add_चिह्न(s, "hello", hello);

    /* relocate the code */
    यदि (tcc_relocate(s) < 0)
        फर्काऊ 1;

    /* get entry symbol */
    func = tcc_get_चिह्न(s, "foo");
    यदि (!func)
        फर्काऊ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    फर्काऊ 0;
}
