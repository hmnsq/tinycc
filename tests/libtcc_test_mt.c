/*
 * Multi-thread Test for libtcc
 */

#अगर_अघोषित FIB
#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <string.h>
#समावेश <setjmp.h>
#समावेश "libtcc.h"

#घोषणा M 20 /* number of states */
#घोषणा F(n) (n % 20 + 2) /* fib argument */

#अगर_घोषित _WIN32
#समावेश <windows.h>
#घोषणा TF_TYPE(func, param) DWORD WINAPI func(व्योम *param)
प्रकार TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
व्योम create_thread(ThreadFunc f, पूर्णांक n)
{
    DWORD tid;
    hh[n] = CreateThread(शून्य, 0, f, (व्योम*)(माप_प्रकार)n, 0, &tid);
}
व्योम wait_threads(पूर्णांक n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    जबतक (n)
        CloseHandle(hh[--n]);
}
व्योम sleep_ms(अचिन्हित n)
{
    Sleep(n);
}
#अन्यथा
#समावेश <sys/time.h>
#समावेश <unistd.h>
#समावेश <pthread.h>
#घोषणा TF_TYPE(func, param) व्योम* func(व्योम *param)
प्रकार TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
व्योम create_thread(ThreadFunc f, पूर्णांक n)
{
    pthread_create(&hh[n], शून्य, f, (व्योम*)(माप_प्रकार)n);
}
व्योम wait_threads(पूर्णांक n)
{
    जबतक (n)
        pthread_join(hh[--n], शून्य);

}
व्योम sleep_ms(अचिन्हित n)
{
    usleep(n * 1000);
}
#पूर्ण_अगर

व्योम handle_error(व्योम *opaque, स्थिर अक्षर *संदेश)
{
    ख_लिखो(opaque, "%s\n", संदेश);
}

/* this function is called by the generated code */
पूर्णांक add(पूर्णांक a, पूर्णांक b)
{
    वापस a + b;
}

#घोषणा _str(s) #s
#घोषणा str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#घोषणा PROG(lbl) \
    अक्षर lbl[] = "#line " str(__LINE__) " " str(__खाता__) "\n\n"

PROG(my_program)
"#include <tcclib.h>\n" /* include the "Simple libc header for TCC" */
"int add(int a, int b);\n"
"int fib(int n)\n"
"{\n"
"    if (n <= 2)\n"
"        return 1;\n"
"    else\n"
"        return add(fib(n-1),fib(n-2));\n"
"}\n"
"\n"
"void bar(void) { *(void**)0 = 0; }\n"
"\n"
"int foo(int n)\n"
"{\n"
"    printf(\" %d\", fib(n));\n"
"    if (n >= N_CRASH && n < N_CRASH + 8)\n"
"       bar();\n"
"    return 0;\n"
"#  warning is this the correct file:line...\n"
"}\n";

पूर्णांक g_argc; अक्षर **g_argv;

व्योम parse_args(TCCState *s)
{
    पूर्णांक i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    क्रम (i = 1; i < g_argc; ++i) {
        अक्षर *a = g_argv[i];
        अगर (a[0] == '-') {
            अगर (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अन्यथा अगर (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अन्यथा अगर (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            अन्यथा अगर (a[1] == 'D')
                tcc_define_प्रतीक(s, a+2, शून्य);
        }
    }
}

पूर्णांक backtrace_func(
    व्योम *ud,
    व्योम *pc,
    स्थिर अक्षर *file,
    पूर्णांक पंक्ति_2,
    स्थिर अक्षर *func,
    स्थिर अक्षर *संदेश)
{
#अगर 0
    म_लिखो("\n  *** %p %s %s:%d in '%s'",
        pc,
        संदेश ? "at" : "by",
        file ? file : "?",
        पंक्ति_2,
        func ? func : "?");
    वापस 1; // want more backtrace levels
#अन्यथा
    //printf(" [%d]", *(int*)ud);
    म_लिखो("!");
    वापस 0; // cancel backtrace
#पूर्ण_अगर
}

TCCState *new_state(पूर्णांक w)
{
    TCCState *s = tcc_new();
    अगर (!s) {
        ख_लिखो(मानक_त्रुटि, __खाता__ ": could not create tcc state\n");
        निकास(1);
    }
    tcc_set_error_func(s, मानक_निकास, handle_error);
    parse_args(s);
    अगर (0 == (w & 1))
        tcc_set_options(s, "-w");
    अगर (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_प्रतीक(s, "N_CRASH", str(M/2));
    } अन्यथा
        tcc_define_प्रतीक(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    वापस s;
}

व्योम *reloc_state(TCCState *s, स्थिर अक्षर *entry)
{
    व्योम *func;
    tcc_add_प्रतीक(s, "add", add);
    tcc_add_प्रतीक(s, "printf", म_लिखो);
    अगर (tcc_relocate(s) < 0) {
        ख_लिखो(मानक_त्रुटि, __खाता__ ": could not relocate tcc state.\n");
        वापस शून्य;
    }
    func = tcc_get_प्रतीक(s, entry);
    अगर (!func)
        ख_लिखो(मानक_त्रुटि, __खाता__ ": could not get entry symbol.\n");
    वापस func;
}

/* work with several states at the same time */
पूर्णांक state_test(पूर्णांक w)
{
    TCCState *s[M];
    पूर्णांक (*funcs[M])(पूर्णांक);
    पूर्णांक n;
    लाँघ_बफ jb;

    क्रम (n = 0; n < M + 4; ++n) {
        अचिन्हित a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        अगर (a < M)
            s[a] = new_state(w);
        अगर (b < M)
            अगर (tcc_compile_string(s[b], my_program) == -1)
                अवरोध;
        अगर (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        अगर (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            अगर (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        अगर (e < M)
            tcc_delete(s[e]);
    }
    वापस 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    पूर्णांक (*func)(पूर्णांक);
    पूर्णांक ret;
    पूर्णांक n = (माप_प्रकार)vn;
    लाँघ_बफ jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    अगर (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        अगर (func) {
            अगर (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    वापस 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    पूर्णांक ret;
    पूर्णांक n = (माप_प्रकार)vn;
    अक्षर *argv[30], b[10];
    पूर्णांक argc = 0, i;

    प्र_लिखो(b, "%d", F(n));

    क्रम (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#अगर 0
    argv[argc++] = "-run";
    क्रम (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#पूर्ण_अगर
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __खाता__;
    argv[argc++] = b;
    argv[argc] = शून्य;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    अगर (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    ख_साफ(मानक_निकास);
    वापस 0;
}

व्योम time_tcc(पूर्णांक n, स्थिर अक्षर *src)
{
    TCCState *s;
    पूर्णांक ret, i = 0;
    जबतक (i++ < n) {
        s = new_state(1);
        म_लिखो(" %d", i), ख_साफ(मानक_निकास);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        अगर (ret < 0)
            निकास(1);
    }
}

अटल अचिन्हित getclock_ms(व्योम)
{
#अगर_घोषित _WIN32
    वापस Get_Tick_गिनती();
#अन्यथा
    काष्ठा timeval tv;
    gettimeofday(&tv, शून्य);
    वापस tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#पूर्ण_अगर
}

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक n;
    अचिन्हित t;

    g_argc = argc;
    g_argv = argv;

    अगर (argc < 2) {
        ख_लिखो(मानक_त्रुटि, "usage: libtcc_test_mt tcc.c <options>\n");
        वापस 1;
    }

#अगर 1
    म_लिखो("running fib with mixed calls\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    state_test(0);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#पूर्ण_अगर
#अगर 1
    म_लिखो("producing some exceptions (!)\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    state_test(2);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#पूर्ण_अगर
#अगर 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    म_लिखो("running fib in threads\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    क्रम (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
        //}}
#पूर्ण_अगर
#अगर 1
    म_लिखो("running tcc.c in threads to run fib\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    क्रम (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#पूर्ण_अगर
#अगर 1
    म_लिखो("compiling tcc.c 10 times\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t), ख_साफ(मानक_निकास);
#पूर्ण_अगर
    वापस 0;
}

#अन्यथा
#समावेश <tcclib.h>
#अगर_घोषित _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    व्योम Sleep(अचिन्हित);
# define sleep_ms Sleep
#अन्यथा
    पूर्णांक usleep(अचिन्हित दीर्घ);
# define sleep_ms(x) usleep((x)*1000);
#पूर्ण_अगर

पूर्णांक fib(n)
{
    वापस (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    sleep_ms(333);
    म_लिखो(" %d", fib(म_से_प(argv[1])));
    वापस 0;
}
#पूर्ण_अगर
