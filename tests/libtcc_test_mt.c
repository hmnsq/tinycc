/*
 * Multi-thread Test for libtcc
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ FIB
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಅನ್ತರ್ಭಾವ "libtcc.h"

#ವ್ಯಾಖ್ಯಾನಿಸು M 20 /* number of states */
#ವ್ಯಾಖ್ಯಾನಿಸು F(n) (n % 20 + 2) /* fib argument */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
#ಅನ್ತರ್ಭಾವ <windows.h>
#ವ್ಯಾಖ್ಯಾನಿಸು TF_TYPE(func, param) DWORD WINAPI func(ಶೂನ್ಯ *param)
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
ಶೂನ್ಯ create_thread(ThreadFunc f, ಪೂರ್ಣಾಂಕ n)
{
    DWORD tid;
    hh[n] = CreateThread(ಖಾಲಿ, 0, f, (ಶೂನ್ಯ*)(ಗಾತ್ರ_t)n, 0, &tid);
}
ಶೂನ್ಯ wait_ಎಳೆಗಳು(ಪೂರ್ಣಾಂಕ n)
{
    Wait_For_ಅಪವರ್ತ್ಯ_Objects(n, hh, TRUE, INFINITE);
    ಆಗ (n)
        CloseHandle(hh[--n]);
}
ಶೂನ್ಯ sleep_ms(ಚಿಹ್ನೆರಹಿತ n)
{
    Sleep(n);
}
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <sys/time.h>
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ವ್ಯಾಖ್ಯಾನಿಸು TF_TYPE(func, param) ಶೂನ್ಯ* func(ಶೂನ್ಯ *param)
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
ಶೂನ್ಯ create_thread(ThreadFunc f, ಪೂರ್ಣಾಂಕ n)
{
    pthread_create(&hh[n], ಖಾಲಿ, f, (ಶೂನ್ಯ*)(ಗಾತ್ರ_t)n);
}
ಶೂನ್ಯ wait_ಎಳೆಗಳು(ಪೂರ್ಣಾಂಕ n)
{
    ಆಗ (n)
        pthread_join(hh[--n], ಖಾಲಿ);

}
ಶೂನ್ಯ sleep_ms(ಚಿಹ್ನೆರಹಿತ n)
{
    usleep(n * 1000);
}
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ handle_error(ಶೂನ್ಯ *opaque, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
    fprintf(opaque, "%s\n", ಸಂದೇಶ);
}

/* this function is called by the generated code */
ಪೂರ್ಣಾಂಕ ಕೂಡಿಸು(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    ಹಿಂತಿರುಗಿ a + b;
}

#ವ್ಯಾಖ್ಯಾನಿಸು _str(s) #s
#ವ್ಯಾಖ್ಯಾನಿಸು str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#ವ್ಯಾಖ್ಯಾನಿಸು PROG(lbl) \
    ಅಕ್ಷರ lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_ಕಾರ್ಯಕ್ರಮ)
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

ಪೂರ್ಣಾಂಕ g_argc; ಅಕ್ಷರ **g_argv;

ಶೂನ್ಯ parse_ವಾದಗಳು(TCCState *s)
{
    ಪೂರ್ಣಾಂಕ i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ಗಾಗಿ (i = 1; i < g_argc; ++i) {
        ಅಕ್ಷರ *a = g_argv[i];
        ಆದರೆ (a[0] == '-') {
            ಆದರೆ (a[1] == 'B')
                tcc_ಗಣ_lib_ಮಾರ್ಗ(s, a+2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[1] == 'I')
                tcc_ಕೂಡಿಸು_include_ಮಾರ್ಗ(s, a+2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[1] == 'L')
                tcc_ಕೂಡಿಸು_library_ಮಾರ್ಗ(s, a+2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (a[1] == 'D')
                tcc_define_ಚಿಹ್ನೆ(s, a+2, ಖಾಲಿ);
        }
    }
}

ಪೂರ್ಣಾಂಕ backtrace_func(
    ಶೂನ್ಯ *ud,
    ಶೂನ್ಯ *pc,
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *file,
    ಪೂರ್ಣಾಂಕ ಸಾಲು,
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *func,
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂದೇಶ)
{
#ಆದರೆ 0
    ಬರೆ("\n  *** %p %s %s:%d in '%s'",
        pc,
        ಸಂದೇಶ ? "at" : "by",
        file ? file : "?",
        ಸಾಲು,
        func ? func : "?");
    ಹಿಂತಿರುಗಿ 1; // want more backtrace levels
#ಇಲ್ಲದಿದ್ದರೆ
    //printf(" [%d]", *(int*)ud);
    ಬರೆ("!");
    ಹಿಂತಿರುಗಿ 0; // cancel backtrace
#ಆದರೆ_ಅಂತ್ಯ
}

TCCState *new_state(ಪೂರ್ಣಾಂಕ w)
{
    TCCState *s = tcc_new();
    ಆದರೆ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        ನಿರ್ಗಮಿಸು(1);
    }
    tcc_ಗಣ_error_func(s, stdout, handle_error);
    parse_ವಾದಗಳು(s);
    ಆದರೆ (0 == (w & 1))
        tcc_ಗಣ_options(s, "-w");
    ಆದರೆ (w & 2) {
        tcc_ಗಣ_options(s, "-bt");
        tcc_define_ಚಿಹ್ನೆ(s, "N_CRASH", str(M/2));
    } ಇಲ್ಲದಿದ್ದರೆ
        tcc_define_ಚಿಹ್ನೆ(s, "N_CRASH", "-1000");
    tcc_ಗಣ_output_type(s, TCC_OUTPUT_ಸ್ಮರಣೆ);
    ಹಿಂತಿರುಗಿ s;
}

ಶೂನ್ಯ *reloc_state(TCCState *s, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *entry)
{
    ಶೂನ್ಯ *func;
    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s, "add", ಕೂಡಿಸು);
    tcc_ಕೂಡಿಸು_ಚಿಹ್ನೆ(s, "printf", ಬರೆ);
    ಆದರೆ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ಹಿಂತಿರುಗಿ ಖಾಲಿ;
    }
    func = tcc_get_ಚಿಹ್ನೆ(s, entry);
    ಆದರೆ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ಹಿಂತಿರುಗಿ func;
}

/* work with several states at the same time */
ಪೂರ್ಣಾಂಕ state_test(ಪೂರ್ಣಾಂಕ w)
{
    TCCState *s[M];
    ಪೂರ್ಣಾಂಕ (*funcs[M])(ಪೂರ್ಣಾಂಕ);
    ಪೂರ್ಣಾಂಕ n;
    jmp_buf jb;

    ಗಾಗಿ (n = 0; n < M + 4; ++n) {
        ಚಿಹ್ನೆರಹಿತ a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ಆದರೆ (a < M)
            s[a] = new_state(w);
        ಆದರೆ (b < M)
            ಆದರೆ (tcc_compile_string(s[b], my_ಕಾರ್ಯಕ್ರಮ) == -1)
                ನಿಲ್ಲಿಸು;
        ಆದರೆ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ಆದರೆ (d < M && funcs[d]) {
            tcc_ಗಣ_backtrace_func(s[d], &d, backtrace_func);
            ಆದರೆ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ಆದರೆ (e < M)
            tcc_delete(s[e]);
    }
    ಹಿಂತಿರುಗಿ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ಪೂರ್ಣಾಂಕ (*func)(ಪೂರ್ಣಾಂಕ);
    ಪೂರ್ಣಾಂಕ ret;
    ಪೂರ್ಣಾಂಕ n = (ಗಾತ್ರ_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_ಕಾರ್ಯಕ್ರಮ);
    sleep_ms(1);
    ಆದರೆ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_ಗಣ_backtrace_func(s, &n, backtrace_func);
        ಆದರೆ (func) {
            ಆದರೆ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ಹಿಂತಿರುಗಿ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ಪೂರ್ಣಾಂಕ ret;
    ಪೂರ್ಣಾಂಕ n = (ಗಾತ್ರ_t)vn;
    ಅಕ್ಷರ *argv[30], b[10];
    ಪೂರ್ಣಾಂಕ argc = 0, i;

    sprintf(b, "%d", F(n));

    ಗಾಗಿ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ಆದರೆ 0
    argv[argc++] = "-run";
    ಗಾಗಿ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ಆದರೆ_ಅಂತ್ಯ
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ಖಾಲಿ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_ಕೂಡಿಸು_file(s, argv[0]);
    sleep_ms(3);
    ಆದರೆ (ret == 0)
        tcc_ಸತತ(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ ಸಮಯ_tcc(ಪೂರ್ಣಾಂಕ n, ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *src)
{
    TCCState *s;
    ಪೂರ್ಣಾಂಕ ret, i = 0;
    ಆಗ (i++ < n) {
        s = new_state(1);
        ಬರೆ(" %d", i), fflush(stdout);
        ret = tcc_ಕೂಡಿಸು_file(s, src);
        tcc_delete(s);
        ಆದರೆ (ret < 0)
            ನಿರ್ಗಮಿಸು(1);
    }
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ getclock_ms(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
    ಹಿಂತಿರುಗಿ Get_Tick_ಎಣಿಕೆ();
#ಇಲ್ಲದಿದ್ದರೆ
    ರಚನೆ timeval tv;
    gettimeofday(&tv, ಖಾಲಿ);
    ಹಿಂತಿರುಗಿ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಪೂರ್ಣಾಂಕ n;
    ಚಿಹ್ನೆರಹಿತ t;

    g_argc = argc;
    g_argv = argv;

    ಆದರೆ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ಹಿಂತಿರುಗಿ 1;
    }

#ಆದರೆ 1
    ಬರೆ("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    ಬರೆ("\n (%u ms)\n", getclock_ms() - t);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1
    ಬರೆ("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    ಬರೆ("\n (%u ms)\n", getclock_ms() - t);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    ಬರೆ("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ಗಾಗಿ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_ಎಳೆಗಳು(n);
    ಬರೆ("\n (%u ms)\n", getclock_ms() - t);
        //}}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1
    ಬರೆ("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ಗಾಗಿ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_ಎಳೆಗಳು(n);
    ಬರೆ("\n (%u ms)\n", getclock_ms() - t);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1
    ಬರೆ("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    ಸಮಯ_tcc(10, argv[1]);
    ಬರೆ("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ 0;
}

#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <tcclib.h>
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    ಶೂನ್ಯ Sleep(ಚಿಹ್ನೆರಹಿತ);
# define sleep_ms Sleep
#ಇಲ್ಲದಿದ್ದರೆ
    ಪೂರ್ಣಾಂಕ usleep(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ);
# define sleep_ms(x) usleep((x)*1000);
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ fib(n)
{
    ಹಿಂತಿರುಗಿ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    sleep_ms(333);
    ಬರೆ(" %d", fib(atoi(argv[1])));
    ಹಿಂತಿರುಗಿ 0;
}
#ಆದರೆ_ಅಂತ್ಯ
