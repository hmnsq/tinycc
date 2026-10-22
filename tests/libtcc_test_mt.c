/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>
#شامل "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#شامل <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(تهی *param)
تعریفنوع TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
تهی create_thread(ThreadFunc f, صحیح n)
{
    DWORD tid;
    hh[n] = CreateThread(پوچ, 0, f, (تهی*)(size_t)n, 0, &tid);
}
تهی wait_threads(صحیح n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    وقتی (n)
        CloseHandle(hh[--n]);
}
تهی sleep_ms(unsigned n)
{
    Sleep(n);
}
#وگرنه
#شامل <sys/time.h>
#شامل <unistd.h>
#شامل <pthread.h>
#define TF_TYPE(func, param) تهی* func(تهی *param)
تعریفنوع TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
تهی create_thread(ThreadFunc f, صحیح n)
{
    pthread_create(&hh[n], پوچ, f, (تهی*)(size_t)n);
}
تهی wait_threads(صحیح n)
{
    وقتی (n)
        pthread_join(hh[--n], پوچ);

}
تهی sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

تهی handle_error(تهی *opaque, ثابت نویسه *پیام)
{
    fprintf(opaque, "%s\n", پیام);
}

/* this function is called by the generated code */
صحیح add(صحیح a, صحیح b)
{
    بازگشت a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    نویسه lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

صحیح g_argc; نویسه **g_argv;

تهی parse_args(TCCState *s)
{
    صحیح i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    برای (i = 1; i < g_argc; ++i) {
        نویسه *a = g_argv[i];
        اگر (a[0] == '-') {
            اگر (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            وگرنه اگر (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            وگرنه اگر (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            وگرنه اگر (a[1] == 'D')
                tcc_define_نماد(s, a+2, پوچ);
        }
    }
}

صحیح backtrace_func(
    تهی *ud,
    تهی *pc,
    ثابت نویسه *file,
    صحیح سطر,
    ثابت نویسه *func,
    ثابت نویسه *پیام)
{
#اگر 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        پیام ? "at" : "by",
        file ? file : "?",
        سطر,
        func ? func : "?");
    بازگشت 1; // want more backtrace levels
#وگرنه
    //printf(" [%d]", *(int*)ud);
    printf("!");
    بازگشت 0; // cancel backtrace
#endif
}

TCCState *new_state(صحیح w)
{
    TCCState *s = tcc_new();
    اگر (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    اگر (0 == (w & 1))
        tcc_set_options(s, "-w");
    اگر (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_نماد(s, "N_CRASH", str(M/2));
    } وگرنه
        tcc_define_نماد(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    بازگشت s;
}

تهی *reloc_state(TCCState *s, ثابت نویسه *entry)
{
    تهی *func;
    tcc_add_نماد(s, "add", add);
    tcc_add_نماد(s, "printf", printf);
    اگر (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        بازگشت پوچ;
    }
    func = tcc_get_نماد(s, entry);
    اگر (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    بازگشت func;
}

/* work with several states at the same time */
صحیح state_test(صحیح w)
{
    TCCState *s[M];
    صحیح (*funcs[M])(صحیح);
    صحیح n;
    jmp_buf jb;

    برای (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        اگر (a < M)
            s[a] = new_state(w);
        اگر (b < M)
            اگر (tcc_compile_string(s[b], my_program) == -1)
                بشکن;
        اگر (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        اگر (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            اگر (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        اگر (e < M)
            tcc_delete(s[e]);
    }
    بازگشت 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    صحیح (*func)(صحیح);
    صحیح ret;
    صحیح n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    اگر (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        اگر (func) {
            اگر (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    بازگشت 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    صحیح ret;
    صحیح n = (size_t)vn;
    نویسه *argv[30], b[10];
    صحیح argc = 0, i;

    sprintf(b, "%d", F(n));

    برای (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#اگر 0
    argv[argc++] = "-run";
    برای (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = پوچ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    اگر (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    بازگشت 0;
}

تهی time_tcc(صحیح n, ثابت نویسه *src)
{
    TCCState *s;
    صحیح ret, i = 0;
    وقتی (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        اگر (ret < 0)
            exit(1);
    }
}

ایستا unsigned getclock_ms(تهی)
{
#ifdef _WIN32
    بازگشت Get_Tick_شمار();
#وگرنه
    ساختار timeval tv;
    gettimeofday(&tv, پوچ);
    بازگشت tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

صحیح اصلی(صحیح argc, نویسه **argv)
{
    صحیح n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    اگر (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        بازگشت 1;
    }

#اگر 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#اگر 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#اگر 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    برای (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#اگر 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    برای (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#اگر 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    بازگشت 0;
}

#وگرنه
#شامل <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    تهی Sleep(unsigned);
# define sleep_ms Sleep
#وگرنه
    صحیح usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

صحیح fib(n)
{
    بازگشت (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

صحیح اصلی(صحیح argc, نویسه **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    بازگشت 0;
}
#endif
