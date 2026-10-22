/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#अन्तर्भाव "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#अन्तर्भाव <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    DWORD tid;
    hh[n] = CreateThread(रिक्त, 0, f, (शून्य*)(size_t)n, 0, &tid);
}
शून्य wait_threads(पूर्णाङ्क n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    जाव (n)
        CloseHandle(hh[--n]);
}
शून्य sleep_ms(unsigned n)
{
    Sleep(n);
}
#अण्णहा
#अन्तर्भाव <sys/time.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <pthread.h>
#define TF_TYPE(func, param) शून्य* func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    pthread_create(&hh[n], रिक्त, f, (शून्य*)(size_t)n);
}
शून्य wait_threads(पूर्णाङ्क n)
{
    जाव (n)
        pthread_join(hh[--n], रिक्त);

}
शून्य sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

शून्य handle_error(शून्य *opaque, ध्रुव वर्ण *सन्देशः)
{
    fprintf(opaque, "%s\n", सन्देशः);
}

/* this function is called by the generated code */
पूर्णाङ्क add(पूर्णाङ्क a, पूर्णाङ्क b)
{
    प्रत्यागम a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    वर्ण lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

पूर्णाङ्क g_argc; वर्ण **g_argv;

शून्य parse_args(TCCState *s)
{
    पूर्णाङ्क i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    प्रति (i = 1; i < g_argc; ++i) {
        वर्ण *a = g_argv[i];
        जइ (a[0] == '-') {
            जइ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अण्णहा जइ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अण्णहा जइ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            अण्णहा जइ (a[1] == 'D')
                tcc_define_चिह्नम्(s, a+2, रिक्त);
        }
    }
}

पूर्णाङ्क backtrace_func(
    शून्य *ud,
    शून्य *pc,
    ध्रुव वर्ण *file,
    पूर्णाङ्क पङ्क्तिः,
    ध्रुव वर्ण *func,
    ध्रुव वर्ण *सन्देशः)
{
#जइ 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        सन्देशः ? "at" : "by",
        file ? file : "?",
        पङ्क्तिः,
        func ? func : "?");
    प्रत्यागम 1; // want more backtrace levels
#अण्णहा
    //printf(" [%d]", *(int*)ud);
    printf("!");
    प्रत्यागम 0; // cancel backtrace
#endif
}

TCCState *new_state(पूर्णाङ्क w)
{
    TCCState *s = tcc_new();
    जइ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    जइ (0 == (w & 1))
        tcc_set_options(s, "-w");
    जइ (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_चिह्नम्(s, "N_CRASH", str(M/2));
    } अण्णहा
        tcc_define_चिह्नम्(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    प्रत्यागम s;
}

शून्य *reloc_state(TCCState *s, ध्रुव वर्ण *entry)
{
    शून्य *func;
    tcc_add_चिह्नम्(s, "add", add);
    tcc_add_चिह्नम्(s, "printf", printf);
    जइ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        प्रत्यागम रिक्त;
    }
    func = tcc_get_चिह्नम्(s, entry);
    जइ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    प्रत्यागम func;
}

/* work with several states at the same time */
पूर्णाङ्क state_test(पूर्णाङ्क w)
{
    TCCState *s[M];
    पूर्णाङ्क (*funcs[M])(पूर्णाङ्क);
    पूर्णाङ्क n;
    jmp_buf jb;

    प्रति (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        जइ (a < M)
            s[a] = new_state(w);
        जइ (b < M)
            जइ (tcc_compile_string(s[b], my_program) == -1)
                भङ्ग;
        जइ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        जइ (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            जइ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        जइ (e < M)
            tcc_delete(s[e]);
    }
    प्रत्यागम 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    पूर्णाङ्क (*func)(पूर्णाङ्क);
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    जइ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        जइ (func) {
            जइ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    प्रत्यागम 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (size_t)vn;
    वर्ण *argv[30], b[10];
    पूर्णाङ्क argc = 0, i;

    sprintf(b, "%d", F(n));

    प्रति (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#जइ 0
    argv[argc++] = "-run";
    प्रति (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = रिक्त;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    जइ (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    प्रत्यागम 0;
}

शून्य time_tcc(पूर्णाङ्क n, ध्रुव वर्ण *src)
{
    TCCState *s;
    पूर्णाङ्क ret, i = 0;
    जाव (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        जइ (ret < 0)
            exit(1);
    }
}

स्थिर unsigned getclock_ms(शून्य)
{
#ifdef _WIN32
    प्रत्यागम Get_Tick_गणनम्();
#अण्णहा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    प्रत्यागम tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    जइ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        प्रत्यागम 1;
    }

#जइ 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#जइ 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#जइ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    प्रति (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#जइ 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    प्रति (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#जइ 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    प्रत्यागम 0;
}

#अण्णहा
#अन्तर्भाव <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    शून्य Sleep(unsigned);
# define sleep_ms Sleep
#अण्णहा
    पूर्णाङ्क usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

पूर्णाङ्क fib(n)
{
    प्रत्यागम (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    प्रत्यागम 0;
}
#endif
