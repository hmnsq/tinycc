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
void create_thread(ThreadFunc f, 정수 n)
{
    DWORD tid;
    hh[n] = CreateThread(NULL, 0, f, (void*)(size_t)n, 0, &tid);
}
void wait_threads(정수 n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    동안 (n)
        CloseHandle(hh[--n]);
}
void sleep_ms(unsigned n)
{
    Sleep(n);
}
#아니면
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define TF_TYPE(func, param) void* func(void *param)
typedef TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
void create_thread(ThreadFunc f, 정수 n)
{
    pthread_create(&hh[n], NULL, f, (void*)(size_t)n);
}
void wait_threads(정수 n)
{
    동안 (n)
        pthread_join(hh[--n], NULL);

}
void sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

void handle_error(void *opaque, const char *msg)
{
    fprintf(opaque, "%s\n", msg);
}

/* this function is called by the generated code */
정수 add(정수 a, 정수 b)
{
    반환 a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    char lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

정수 g_argc; char **g_argv;

void parse_args(TCCState *s)
{
    정수 i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    위해 (i = 1; i < g_argc; ++i) {
        char *a = g_argv[i];
        만약 (a[0] == '-') {
            만약 (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            아니면 만약 (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            아니면 만약 (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            아니면 만약 (a[1] == 'D')
                tcc_define_symbol(s, a+2, NULL);
        }
    }
}

정수 backtrace_func(
    void *ud,
    void *pc,
    const char *file,
    정수 line,
    const char *func,
    const char *msg)
{
#만약 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        msg ? "at" : "by",
        file ? file : "?",
        line,
        func ? func : "?");
    반환 1; // want more backtrace levels
#아니면
    //printf(" [%d]", *(int*)ud);
    printf("!");
    반환 0; // cancel backtrace
#endif
}

TCCState *new_state(정수 w)
{
    TCCState *s = tcc_new();
    만약 (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    만약 (0 == (w & 1))
        tcc_set_options(s, "-w");
    만약 (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_symbol(s, "N_CRASH", str(M/2));
    } 아니면
        tcc_define_symbol(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    반환 s;
}

void *reloc_state(TCCState *s, const char *entry)
{
    void *func;
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "printf", printf);
    만약 (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        반환 NULL;
    }
    func = tcc_get_symbol(s, entry);
    만약 (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    반환 func;
}

/* work with several states at the same time */
정수 state_test(정수 w)
{
    TCCState *s[M];
    정수 (*funcs[M])(정수);
    정수 n;
    jmp_buf jb;

    위해 (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        만약 (a < M)
            s[a] = new_state(w);
        만약 (b < M)
            만약 (tcc_compile_string(s[b], my_program) == -1)
                break;
        만약 (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        만약 (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            만약 (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        만약 (e < M)
            tcc_delete(s[e]);
    }
    반환 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    정수 (*func)(정수);
    정수 ret;
    정수 n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    만약 (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        만약 (func) {
            만약 (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    반환 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    정수 ret;
    정수 n = (size_t)vn;
    char *argv[30], b[10];
    정수 argc = 0, i;

    sprintf(b, "%d", F(n));

    위해 (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#만약 0
    argv[argc++] = "-run";
    위해 (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
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
    만약 (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    반환 0;
}

void time_tcc(정수 n, const char *src)
{
    TCCState *s;
    정수 ret, i = 0;
    동안 (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        만약 (ret < 0)
            exit(1);
    }
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    반환 GetTickCount();
#아니면
    struct timeval tv;
    gettimeofday(&tv, NULL);
    반환 tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

정수 main(정수 argc, char **argv)
{
    정수 n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    만약 (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        반환 1;
    }

#만약 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#만약 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#만약 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    위해 (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#만약 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    위해 (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#만약 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    반환 0;
}

#아니면
#include <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    void Sleep(unsigned);
# define sleep_ms Sleep
#아니면
    정수 usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

정수 fib(n)
{
    반환 (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

정수 main(정수 argc, char **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    반환 0;
}
#endif
