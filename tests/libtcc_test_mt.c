/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <setjmp.h>
#অন্তর্ভাব "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#অন্তর্ভাব <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(শূন্য *param)
প্রকারলেখ TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
শূন্য create_thread(ThreadFunc f, পূর্ণসংখ্যা n)
{
    DWORD tid;
    hh[n] = CreateThread(ফাঁকা, 0, f, (শূন্য*)(আকার_t)n, 0, &tid);
}
শূন্য wait_threads(পূর্ণসংখ্যা n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    যখন (n)
        CloseHandle(hh[--n]);
}
শূন্য sleep_ms(unsigned n)
{
    Sleep(n);
}
#অন্যথা
#অন্তর্ভাব <sys/time.h>
#অন্তর্ভাব <unistd.h>
#অন্তর্ভাব <pthread.h>
#define TF_TYPE(func, param) শূন্য* func(শূন্য *param)
প্রকারলেখ TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
শূন্য create_thread(ThreadFunc f, পূর্ণসংখ্যা n)
{
    pthread_create(&hh[n], ফাঁকা, f, (শূন্য*)(আকার_t)n);
}
শূন্য wait_threads(পূর্ণসংখ্যা n)
{
    যখন (n)
        pthread_join(hh[--n], ফাঁকা);

}
শূন্য sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

শূন্য handle_error(শূন্য *opaque, ধ্রুবক অক্ষর *বার্তা)
{
    fprintf(opaque, "%s\n", বার্তা);
}

/* this function is called by the generated code */
পূর্ণসংখ্যা add(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
    ফেরত a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    অক্ষর lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

পূর্ণসংখ্যা g_argc; অক্ষর **g_argv;

শূন্য parse_args(TCCState *s)
{
    পূর্ণসংখ্যা i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    জন্য (i = 1; i < g_argc; ++i) {
        অক্ষর *a = g_argv[i];
        যদি (a[0] == '-') {
            যদি (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            অন্যথা যদি (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            অন্যথা যদি (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            অন্যথা যদি (a[1] == 'D')
                tcc_define_প্রতীক(s, a+2, ফাঁকা);
        }
    }
}

পূর্ণসংখ্যা backtrace_func(
    শূন্য *ud,
    শূন্য *pc,
    ধ্রুবক অক্ষর *file,
    পূর্ণসংখ্যা সারি,
    ধ্রুবক অক্ষর *func,
    ধ্রুবক অক্ষর *বার্তা)
{
#যদি 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        বার্তা ? "at" : "by",
        file ? file : "?",
        সারি,
        func ? func : "?");
    ফেরত 1; // want more backtrace levels
#অন্যথা
    //printf(" [%d]", *(int*)ud);
    printf("!");
    ফেরত 0; // cancel backtrace
#endif
}

TCCState *new_state(পূর্ণসংখ্যা w)
{
    TCCState *s = tcc_new();
    যদি (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    যদি (0 == (w & 1))
        tcc_set_options(s, "-w");
    যদি (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_প্রতীক(s, "N_CRASH", str(M/2));
    } অন্যথা
        tcc_define_প্রতীক(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ফেরত s;
}

শূন্য *reloc_state(TCCState *s, ধ্রুবক অক্ষর *entry)
{
    শূন্য *func;
    tcc_add_প্রতীক(s, "add", add);
    tcc_add_প্রতীক(s, "printf", printf);
    যদি (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ফেরত ফাঁকা;
    }
    func = tcc_get_প্রতীক(s, entry);
    যদি (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ফেরত func;
}

/* work with several states at the same time */
পূর্ণসংখ্যা state_test(পূর্ণসংখ্যা w)
{
    TCCState *s[M];
    পূর্ণসংখ্যা (*funcs[M])(পূর্ণসংখ্যা);
    পূর্ণসংখ্যা n;
    jmp_buf jb;

    জন্য (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        যদি (a < M)
            s[a] = new_state(w);
        যদি (b < M)
            যদি (tcc_compile_string(s[b], my_program) == -1)
                বিরতি;
        যদি (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        যদি (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            যদি (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        যদি (e < M)
            tcc_delete(s[e]);
    }
    ফেরত 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    পূর্ণসংখ্যা (*func)(পূর্ণসংখ্যা);
    পূর্ণসংখ্যা ret;
    পূর্ণসংখ্যা n = (আকার_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    যদি (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        যদি (func) {
            যদি (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ফেরত 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    পূর্ণসংখ্যা ret;
    পূর্ণসংখ্যা n = (আকার_t)vn;
    অক্ষর *argv[30], b[10];
    পূর্ণসংখ্যা argc = 0, i;

    sprintf(b, "%d", F(n));

    জন্য (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#যদি 0
    argv[argc++] = "-run";
    জন্য (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ফাঁকা;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    যদি (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ফেরত 0;
}

শূন্য time_tcc(পূর্ণসংখ্যা n, ধ্রুবক অক্ষর *src)
{
    TCCState *s;
    পূর্ণসংখ্যা ret, i = 0;
    যখন (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        যদি (ret < 0)
            exit(1);
    }
}

স্থির unsigned getclock_ms(শূন্য)
{
#ifdef _WIN32
    ফেরত Get_Tick_গুনতি();
#অন্যথা
    কাঠামো timeval tv;
    gettimeofday(&tv, ফাঁকা);
    ফেরত tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    পূর্ণসংখ্যা n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    যদি (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ফেরত 1;
    }

#যদি 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#যদি 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#যদি 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    জন্য (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#যদি 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    জন্য (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#যদি 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    ফেরত 0;
}

#অন্যথা
#অন্তর্ভাব <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    শূন্য Sleep(unsigned);
# define sleep_ms Sleep
#অন্যথা
    পূর্ণসংখ্যা usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

পূর্ণসংখ্যা fib(n)
{
    ফেরত (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    ফেরত 0;
}
#endif
