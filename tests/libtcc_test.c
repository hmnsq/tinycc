/*
 * Simple Test program for libtcc
 *
 * libtcc can be useful to use tcc as a "backend" for a code generator.
 */
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ "libtcc.h"

ਖਾਲੀ handle_error(ਖਾਲੀ *opaque, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
    fprintf(opaque, "%s\n", ਸੁਨੇਹਾ);
}

/* this function is called by the generated code */
ਪੂਰਨ ਜੋੜੋ(ਪੂਰਨ a, ਪੂਰਨ b)
{
    ਵਾਪਸ a + b;
}

/* this strinc is referenced by the generated code */
ਅਚਲ ਅੱਖਰ hello[] = "Hello World!";

ਅੱਖਰ my_ਪ੍ਰੋਗਰਾਮ[] =
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

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    TCCState *s;
    ਪੂਰਨ i;
    ਪੂਰਨ (*func)(ਪੂਰਨ);

    s = tcc_new();
    ਜੇ (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        ਬਾਹਰ_ਨਿਕਲੋ(1);
    }

    /* set custom error/warning printer */
    tcc_ਸੈੱਟ_error_func(s, stderr, handle_error);

    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ਲਈ (i = 1; i < argc; ++i) {
        ਅੱਖਰ *a = argv[i];
        ਜੇ (a[0] == '-') {
            ਜੇ (a[1] == 'B')
                tcc_ਸੈੱਟ_lib_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'I')
                tcc_ਜੋੜੋ_include_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'L')
                tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    tcc_ਸੈੱਟ_output_type(s, TCC_OUTPUT_ਸਮ੍ਰਿਤੀ);

    ਜੇ (tcc_compile_string(s, my_ਪ੍ਰੋਗਰਾਮ) == -1)
        ਵਾਪਸ 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with tcc_add_dll() and use symbols from that */
    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s, "add", ਜੋੜੋ);
    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s, "hello", hello);

    /* relocate the code */
    ਜੇ (tcc_relocate(s) < 0)
        ਵਾਪਸ 1;

    /* get entry symbol */
    func = tcc_get_ਚਿੰਨ੍ਹ(s, "foo");
    ਜੇ (!func)
        ਵਾਪਸ 1;

    /* run the code */
    func(32);

    /* delete the state */
    tcc_delete(s);

    ਵਾਪਸ 0;
}
