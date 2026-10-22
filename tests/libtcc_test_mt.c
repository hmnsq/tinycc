/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#include <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(void *param)
typedef TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
void create_thread(ThreadFunc f, จำนวนเต็ม n)
{
    DWORD tid;
    hh[n] = CreateThread(NULL, 0, f, (void*)(size_t)n, 0, &tid);
}
void wait_threads(จำนวนเต็ม n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ขณะ (n)
        CloseHandle(hh[--n]);
}
void sleep_ms(unsigned n)
{
    Sleep(n);
}
#มิฉะนั้น
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define TF_TYPE(func, param) void* func(void *param)
typedef TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
void create_thread(ThreadFunc f, จำนวนเต็ม n)
{
    pthread_create(&hh[n], NULL, f, (void*)(size_t)n);
}
void wait_threads(จำนวนเต็ม n)
{
    ขณะ (n)
        pthread_join(hh[--n], NULL);

}
void sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

void handle_error(void *opaque, const var_na *msg)
{
    fprintf(opaque, "%s\n", msg);
}

/* this function is called by the generated code */
จำนวนเต็ม add(จำนวนเต็ม a, จำนวนเต็ม b)
{
    คืน a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    var_na lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

จำนวนเต็ม g_argc; var_na **g_argv;

void parse_args(TCCState *s)
{
    จำนวนเต็ม i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    สำหรับ (i = 1; i < g_argc; ++i) {
        var_na *a = g_argv[i];
        ถ้า (a[0] == '-') {
            ถ้า (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            มิฉะนั้น ถ้า (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            มิฉะนั้น ถ้า (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            มิฉะนั้น ถ้า (a[1] == 'D')
                tcc_define_symbol(s, a+2, NULL);
        }
    }
}

จำนวนเต็ม backtrace_func(
    void *ud,
    void *pc,
    const var_na *file,
    จำนวนเต็ม line,
    const var_na *func,
    const var_na *msg)
{
#ถ้า 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        msg ? "at" : "by",
        file ? file : "?",
        line,
        func ? func : "?");
    คืน 1; // want more backtrace levels
#มิฉะนั้น
    //printf(" [%d]", *(int*)ud);
    printf("!");
    คืน 0; // cancel backtrace
#endif
}

TCCState *new_state(จำนวนเต็ม w)
{
    TCCState *s = tcc_new();
    ถ้า (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    ถ้า (0 == (w & 1))
        tcc_set_options(s, "-w");
    ถ้า (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_symbol(s, "N_CRASH", str(M/2));
    } มิฉะนั้น
        tcc_define_symbol(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    คืน s;
}

void *reloc_state(TCCState *s, const var_na *entry)
{
    void *func;
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "printf", printf);
    ถ้า (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        คืน NULL;
    }
    func = tcc_get_symbol(s, entry);
    ถ้า (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    คืน func;
}

/* work with several states at the same time */
จำนวนเต็ม state_test(จำนวนเต็ม w)
{
    TCCState *s[M];
    จำนวนเต็ม (*funcs[M])(จำนวนเต็ม);
    จำนวนเต็ม n;
    jmp_buf jb;

    สำหรับ (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ถ้า (a < M)
            s[a] = new_state(w);
        ถ้า (b < M)
            ถ้า (tcc_compile_string(s[b], my_program) == -1)
                bha_nga;
        ถ้า (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ถ้า (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            ถ้า (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ถ้า (e < M)
            tcc_delete(s[e]);
    }
    คืน 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    จำนวนเต็ม (*func)(จำนวนเต็ม);
    จำนวนเต็ม ret;
    จำนวนเต็ม n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    ถ้า (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        ถ้า (func) {
            ถ้า (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    คืน 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    จำนวนเต็ม ret;
    จำนวนเต็ม n = (size_t)vn;
    var_na *argv[30], b[10];
    จำนวนเต็ม argc = 0, i;

    sprintf(b, "%d", F(n));

    สำหรับ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ถ้า 0
    argv[argc++] = "-run";
    สำหรับ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = NULL;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    ถ้า (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    คืน 0;
}

void time_tcc(จำนวนเต็ม n, const var_na *src)
{
    TCCState *s;
    จำนวนเต็ม ret, i = 0;
    ขณะ (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        ถ้า (ret < 0)
            exit(1);
    }
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    คืน GetTickCount();
#มิฉะนั้น
    sa_nracanaa timeval tv;
    gettimeofday(&tv, NULL);
    คืน tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    จำนวนเต็ม n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    ถ้า (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        คืน 1;
    }

#ถ้า 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ถ้า 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ถ้า 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    สำหรับ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#ถ้า 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    สำหรับ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ถ้า 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    คืน 0;
}

#มิฉะนั้น
#include <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    void Sleep(unsigned);
# define sleep_ms Sleep
#มิฉะนั้น
    จำนวนเต็ม usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

จำนวนเต็ม fib(n)
{
    คืน (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    คืน 0;
}
#endif
