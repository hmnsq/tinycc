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
void create_thread(ThreadFunc f, ကိန်းပြည့် n)
{
    DWORD tid;
    hh[n] = CreateThread(NULL, 0, f, (void*)(size_t)n, 0, &tid);
}
void wait_threads(ကိန်းပြည့် n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    နေစဉ် (n)
        CloseHandle(hh[--n]);
}
void sleep_ms(unsigned n)
{
    Sleep(n);
}
#မဟုတ်ပါက
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define TF_TYPE(func, param) void* func(void *param)
typedef TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
void create_thread(ThreadFunc f, ကိန်းပြည့် n)
{
    pthread_create(&hh[n], NULL, f, (void*)(size_t)n);
}
void wait_threads(ကိန်းပြည့် n)
{
    နေစဉ် (n)
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
ကိန်းပြည့် add(ကိန်းပြည့် a, ကိန်းပြည့် b)
{
    ပြန်ပေး a + b;
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

ကိန်းပြည့် g_argc; var_na **g_argv;

void parse_args(TCCState *s)
{
    ကိန်းပြည့် i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    အတွက် (i = 1; i < g_argc; ++i) {
        var_na *a = g_argv[i];
        အကယ်၍ (a[0] == '-') {
            အကယ်၍ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            မဟုတ်ပါက အကယ်၍ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            မဟုတ်ပါက အကယ်၍ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            မဟုတ်ပါက အကယ်၍ (a[1] == 'D')
                tcc_define_symbol(s, a+2, NULL);
        }
    }
}

ကိန်းပြည့် backtrace_func(
    void *ud,
    void *pc,
    const var_na *file,
    ကိန်းပြည့် line,
    const var_na *func,
    const var_na *msg)
{
#အကယ်၍ 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        msg ? "at" : "by",
        file ? file : "?",
        line,
        func ? func : "?");
    ပြန်ပေး 1; // want more backtrace levels
#မဟုတ်ပါက
    //printf(" [%d]", *(int*)ud);
    printf("!");
    ပြန်ပေး 0; // cancel backtrace
#endif
}

TCCState *new_state(ကိန်းပြည့် w)
{
    TCCState *s = tcc_new();
    အကယ်၍ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    အကယ်၍ (0 == (w & 1))
        tcc_set_options(s, "-w");
    အကယ်၍ (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_symbol(s, "N_CRASH", str(M/2));
    } မဟုတ်ပါက
        tcc_define_symbol(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ပြန်ပေး s;
}

void *reloc_state(TCCState *s, const var_na *entry)
{
    void *func;
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "printf", printf);
    အကယ်၍ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ပြန်ပေး NULL;
    }
    func = tcc_get_symbol(s, entry);
    အကယ်၍ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ပြန်ပေး func;
}

/* work with several states at the same time */
ကိန်းပြည့် state_test(ကိန်းပြည့် w)
{
    TCCState *s[M];
    ကိန်းပြည့် (*funcs[M])(ကိန်းပြည့်);
    ကိန်းပြည့် n;
    jmp_buf jb;

    အတွက် (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        အကယ်၍ (a < M)
            s[a] = new_state(w);
        အကယ်၍ (b < M)
            အကယ်၍ (tcc_compile_string(s[b], my_program) == -1)
                bha_nga;
        အကယ်၍ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        အကယ်၍ (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            အကယ်၍ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        အကယ်၍ (e < M)
            tcc_delete(s[e]);
    }
    ပြန်ပေး 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ကိန်းပြည့် (*func)(ကိန်းပြည့်);
    ကိန်းပြည့် ret;
    ကိန်းပြည့် n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    အကယ်၍ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        အကယ်၍ (func) {
            အကယ်၍ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ပြန်ပေး 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ကိန်းပြည့် ret;
    ကိန်းပြည့် n = (size_t)vn;
    var_na *argv[30], b[10];
    ကိန်းပြည့် argc = 0, i;

    sprintf(b, "%d", F(n));

    အတွက် (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#အကယ်၍ 0
    argv[argc++] = "-run";
    အတွက် (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
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
    အကယ်၍ (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ပြန်ပေး 0;
}

void time_tcc(ကိန်းပြည့် n, const var_na *src)
{
    TCCState *s;
    ကိန်းပြည့် ret, i = 0;
    နေစဉ် (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        အကယ်၍ (ret < 0)
            exit(1);
    }
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    ပြန်ပေး GetTickCount();
#မဟုတ်ပါက
    sa_nracanaa timeval tv;
    gettimeofday(&tv, NULL);
    ပြန်ပေး tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    ကိန်းပြည့် n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    အကယ်၍ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ပြန်ပေး 1;
    }

#အကယ်၍ 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#အကယ်၍ 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#အကယ်၍ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    အတွက် (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#အကယ်၍ 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    အတွက် (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#အကယ်၍ 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    ပြန်ပေး 0;
}

#မဟုတ်ပါက
#include <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    void Sleep(unsigned);
# define sleep_ms Sleep
#မဟုတ်ပါက
    ကိန်းပြည့် usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

ကိန်းပြည့် fib(n)
{
    ပြန်ပေး (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    ပြန်ပေး 0;
}
#endif
