/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಅನ್ತರ್ಭಾವ "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#ಅನ್ತರ್ಭಾವ <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(ಶೂನ್ಯ *param)
ಪ್ರಕಾರನಿರ್ದೇಶ TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
ಶೂನ್ಯ create_thread(ThreadFunc f, ಪೂರ್ಣಾಙ್ಕ n)
{
    DWORD tid;
    hh[n] = CreateThread(ರಿಕ್ತ, 0, f, (ಶೂನ್ಯ*)(size_t)n, 0, &tid);
}
ಶೂನ್ಯ wait_threads(ಪೂರ್ಣಾಙ್ಕ n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ಯಾವತ್ (n)
        CloseHandle(hh[--n]);
}
ಶೂನ್ಯ sleep_ms(unsigned n)
{
    Sleep(n);
}
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <sys/time.h>
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#define TF_TYPE(func, param) ಶೂನ್ಯ* func(ಶೂನ್ಯ *param)
ಪ್ರಕಾರನಿರ್ದೇಶ TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
ಶೂನ್ಯ create_thread(ThreadFunc f, ಪೂರ್ಣಾಙ್ಕ n)
{
    pthread_create(&hh[n], ರಿಕ್ತ, f, (ಶೂನ್ಯ*)(size_t)n);
}
ಶೂನ್ಯ wait_threads(ಪೂರ್ಣಾಙ್ಕ n)
{
    ಯಾವತ್ (n)
        pthread_join(hh[--n], ರಿಕ್ತ);

}
ಶೂನ್ಯ sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

ಶೂನ್ಯ handle_error(ಶೂನ್ಯ *opaque, ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
    fprintf(opaque, "%s\n", ಸಂದೇಶ);
}

/* this function is called by the generated code */
ಪೂರ್ಣಾಙ್ಕ add(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಪ್ರತ್ಯಾಗಮ a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    ವರ್ಣ lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

ಪೂರ್ಣಾಙ್ಕ g_argc; ವರ್ಣ **g_argv;

ಶೂನ್ಯ parse_args(TCCState *s)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ಪ್ರತಿ (i = 1; i < g_argc; ++i) {
        ವರ್ಣ *a = g_argv[i];
        ಯದಿ (a[0] == '-') {
            ಯದಿ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            ಅನ್ಯಥಾ ಯದಿ (a[1] == 'D')
                tcc_define_ಚಿಹ್ನೆ(s, a+2, ರಿಕ್ತ);
        }
    }
}

ಪೂರ್ಣಾಙ್ಕ backtrace_func(
    ಶೂನ್ಯ *ud,
    ಶೂನ್ಯ *pc,
    ಧ್ರುವ ವರ್ಣ *file,
    ಪೂರ್ಣಾಙ್ಕ ಸಾಲು,
    ಧ್ರುವ ವರ್ಣ *func,
    ಧ್ರುವ ವರ್ಣ *ಸಂದೇಶ)
{
#ಯದಿ 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        ಸಂದೇಶ ? "at" : "by",
        file ? file : "?",
        ಸಾಲು,
        func ? func : "?");
    ಪ್ರತ್ಯಾಗಮ 1; // want more backtrace levels
#ಅನ್ಯಥಾ
    //printf(" [%d]", *(int*)ud);
    printf("!");
    ಪ್ರತ್ಯಾಗಮ 0; // cancel backtrace
#endif
}

TCCState *new_state(ಪೂರ್ಣಾಙ್ಕ w)
{
    TCCState *s = tcc_new();
    ಯದಿ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    ಯದಿ (0 == (w & 1))
        tcc_set_options(s, "-w");
    ಯದಿ (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_ಚಿಹ್ನೆ(s, "N_CRASH", str(M/2));
    } ಅನ್ಯಥಾ
        tcc_define_ಚಿಹ್ನೆ(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ಪ್ರತ್ಯಾಗಮ s;
}

ಶೂನ್ಯ *reloc_state(TCCState *s, ಧ್ರುವ ವರ್ಣ *entry)
{
    ಶೂನ್ಯ *func;
    tcc_add_ಚಿಹ್ನೆ(s, "add", add);
    tcc_add_ಚಿಹ್ನೆ(s, "printf", printf);
    ಯದಿ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
    }
    func = tcc_get_ಚಿಹ್ನೆ(s, entry);
    ಯದಿ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ಪ್ರತ್ಯಾಗಮ func;
}

/* work with several states at the same time */
ಪೂರ್ಣಾಙ್ಕ state_test(ಪೂರ್ಣಾಙ್ಕ w)
{
    TCCState *s[M];
    ಪೂರ್ಣಾಙ್ಕ (*funcs[M])(ಪೂರ್ಣಾಙ್ಕ);
    ಪೂರ್ಣಾಙ್ಕ n;
    jmp_buf jb;

    ಪ್ರತಿ (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ಯದಿ (a < M)
            s[a] = new_state(w);
        ಯದಿ (b < M)
            ಯದಿ (tcc_compile_string(s[b], my_program) == -1)
                ಭಙ್ಗ;
        ಯದಿ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ಯದಿ (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            ಯದಿ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ಯದಿ (e < M)
            tcc_delete(s[e]);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ಪೂರ್ಣಾಙ್ಕ (*func)(ಪೂರ್ಣಾಙ್ಕ);
    ಪೂರ್ಣಾಙ್ಕ ret;
    ಪೂರ್ಣಾಙ್ಕ n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    ಯದಿ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        ಯದಿ (func) {
            ಯದಿ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ಪೂರ್ಣಾಙ್ಕ ret;
    ಪೂರ್ಣಾಙ್ಕ n = (size_t)vn;
    ವರ್ಣ *argv[30], b[10];
    ಪೂರ್ಣಾಙ್ಕ argc = 0, i;

    sprintf(b, "%d", F(n));

    ಪ್ರತಿ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ಯದಿ 0
    argv[argc++] = "-run";
    ಪ್ರತಿ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ರಿಕ್ತ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    ಯದಿ (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ time_tcc(ಪೂರ್ಣಾಙ್ಕ n, ಧ್ರುವ ವರ್ಣ *src)
{
    TCCState *s;
    ಪೂರ್ಣಾಙ್ಕ ret, i = 0;
    ಯಾವತ್ (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        ಯದಿ (ret < 0)
            exit(1);
    }
}

ಸ್ಥಿರ unsigned getclock_ms(ಶೂನ್ಯ)
{
#ifdef _WIN32
    ಪ್ರತ್ಯಾಗಮ Get_Tick_ಎಣಿಕೆ();
#ಅನ್ಯಥಾ
    ಸಂರಚನಾ timeval tv;
    gettimeofday(&tv, ರಿಕ್ತ);
    ಪ್ರತ್ಯಾಗಮ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    ಯದಿ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ಪ್ರತ್ಯಾಗಮ 1;
    }

#ಯದಿ 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ಯದಿ 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ಯದಿ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ಪ್ರತಿ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#ಯದಿ 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ಪ್ರತಿ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ಯದಿ 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    ಪ್ರತ್ಯಾಗಮ 0;
}

#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    ಶೂನ್ಯ Sleep(unsigned);
# define sleep_ms Sleep
#ಅನ್ಯಥಾ
    ಪೂರ್ಣಾಙ್ಕ usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

ಪೂರ್ಣಾಙ್ಕ fib(n)
{
    ಪ್ರತ್ಯಾಗಮ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    ಪ್ರತ್ಯಾಗಮ 0;
}
#endif
