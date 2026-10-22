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
void create_thread(ThreadFunc f, 整数 n)
{
    DWORD tid;
    hh[n] = CreateThread(NULL, 0, f, (void*)(size_t)n, 0, &tid);
}
void wait_threads(整数 n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ながら (n)
        CloseHandle(hh[--n]);
}
void sleep_ms(unsigned n)
{
    Sleep(n);
}
#否则
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define TF_TYPE(func, param) void* func(void *param)
typedef TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
void create_thread(ThreadFunc f, 整数 n)
{
    pthread_create(&hh[n], NULL, f, (void*)(size_t)n);
}
void wait_threads(整数 n)
{
    ながら (n)
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
整数 add(整数 a, 整数 b)
{
    戻る a + b;
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

整数 g_argc; char **g_argv;

void parse_args(TCCState *s)
{
    整数 i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ために (i = 1; i < g_argc; ++i) {
        char *a = g_argv[i];
        もし (a[0] == '-') {
            もし (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            否则 もし (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            否则 もし (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            否则 もし (a[1] == 'D')
                tcc_define_symbol(s, a+2, NULL);
        }
    }
}

整数 backtrace_func(
    void *ud,
    void *pc,
    const char *file,
    整数 line,
    const char *func,
    const char *msg)
{
#もし 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        msg ? "at" : "by",
        file ? file : "?",
        line,
        func ? func : "?");
    戻る 1; // want more backtrace levels
#否则
    //printf(" [%d]", *(int*)ud);
    printf("!");
    戻る 0; // cancel backtrace
#endif
}

TCCState *new_state(整数 w)
{
    TCCState *s = tcc_new();
    もし (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    もし (0 == (w & 1))
        tcc_set_options(s, "-w");
    もし (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_symbol(s, "N_CRASH", str(M/2));
    } 否则
        tcc_define_symbol(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    戻る s;
}

void *reloc_state(TCCState *s, const char *entry)
{
    void *func;
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "printf", printf);
    もし (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        戻る NULL;
    }
    func = tcc_get_symbol(s, entry);
    もし (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    戻る func;
}

/* work with several states at the same time */
整数 state_test(整数 w)
{
    TCCState *s[M];
    整数 (*funcs[M])(整数);
    整数 n;
    jmp_buf jb;

    ために (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        もし (a < M)
            s[a] = new_state(w);
        もし (b < M)
            もし (tcc_compile_string(s[b], my_program) == -1)
                break;
        もし (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        もし (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            もし (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        もし (e < M)
            tcc_delete(s[e]);
    }
    戻る 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    整数 (*func)(整数);
    整数 ret;
    整数 n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    もし (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        もし (func) {
            もし (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    戻る 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    整数 ret;
    整数 n = (size_t)vn;
    char *argv[30], b[10];
    整数 argc = 0, i;

    sprintf(b, "%d", F(n));

    ために (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#もし 0
    argv[argc++] = "-run";
    ために (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
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
    もし (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    戻る 0;
}

void time_tcc(整数 n, const char *src)
{
    TCCState *s;
    整数 ret, i = 0;
    ながら (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        もし (ret < 0)
            exit(1);
    }
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    戻る GetTickCount();
#否则
    struct timeval tv;
    gettimeofday(&tv, NULL);
    戻る tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

整数 メインページ(整数 argc, char **argv)
{
    整数 n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    もし (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        戻る 1;
    }

#もし 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#もし 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#もし 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ために (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#もし 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ために (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#もし 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    戻る 0;
}

#否则
#include <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    void Sleep(unsigned);
# define sleep_ms Sleep
#否则
    整数 usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

整数 fib(n)
{
    戻る (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

整数 メインページ(整数 argc, char **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    戻る 0;
}
#endif
