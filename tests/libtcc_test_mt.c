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
void create_thread(ThreadFunc f, ຈຳນວນເຕັມ n)
{
    DWORD tid;
    hh[n] = CreateThread(NULL, 0, f, (void*)(size_t)n, 0, &tid);
}
void wait_threads(ຈຳນວນເຕັມ n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ໃນຂະນະທີ່ (n)
        CloseHandle(hh[--n]);
}
void sleep_ms(unsigned n)
{
    Sleep(n);
}
#ບໍ່ດັ່ງນັ້ນ
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#define TF_TYPE(func, param) void* func(void *param)
typedef TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
void create_thread(ThreadFunc f, ຈຳນວນເຕັມ n)
{
    pthread_create(&hh[n], NULL, f, (void*)(size_t)n);
}
void wait_threads(ຈຳນວນເຕັມ n)
{
    ໃນຂະນະທີ່ (n)
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
ຈຳນວນເຕັມ add(ຈຳນວນເຕັມ a, ຈຳນວນເຕັມ b)
{
    ສົ່ງຄືນ a + b;
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

ຈຳນວນເຕັມ g_argc; var_na **g_argv;

void parse_args(TCCState *s)
{
    ຈຳນວນເຕັມ i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ສຳລັບ (i = 1; i < g_argc; ++i) {
        var_na *a = g_argv[i];
        ຖ້າ (a[0] == '-') {
            ຖ້າ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (a[1] == 'D')
                tcc_define_symbol(s, a+2, NULL);
        }
    }
}

ຈຳນວນເຕັມ backtrace_func(
    void *ud,
    void *pc,
    const var_na *file,
    ຈຳນວນເຕັມ line,
    const var_na *func,
    const var_na *msg)
{
#ຖ້າ 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        msg ? "at" : "by",
        file ? file : "?",
        line,
        func ? func : "?");
    ສົ່ງຄືນ 1; // want more backtrace levels
#ບໍ່ດັ່ງນັ້ນ
    //printf(" [%d]", *(int*)ud);
    printf("!");
    ສົ່ງຄືນ 0; // cancel backtrace
#endif
}

TCCState *new_state(ຈຳນວນເຕັມ w)
{
    TCCState *s = tcc_new();
    ຖ້າ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    ຖ້າ (0 == (w & 1))
        tcc_set_options(s, "-w");
    ຖ້າ (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_symbol(s, "N_CRASH", str(M/2));
    } ບໍ່ດັ່ງນັ້ນ
        tcc_define_symbol(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ສົ່ງຄືນ s;
}

void *reloc_state(TCCState *s, const var_na *entry)
{
    void *func;
    tcc_add_symbol(s, "add", add);
    tcc_add_symbol(s, "printf", printf);
    ຖ້າ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ສົ່ງຄືນ NULL;
    }
    func = tcc_get_symbol(s, entry);
    ຖ້າ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ສົ່ງຄືນ func;
}

/* work with several states at the same time */
ຈຳນວນເຕັມ state_test(ຈຳນວນເຕັມ w)
{
    TCCState *s[M];
    ຈຳນວນເຕັມ (*funcs[M])(ຈຳນວນເຕັມ);
    ຈຳນວນເຕັມ n;
    jmp_buf jb;

    ສຳລັບ (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ຖ້າ (a < M)
            s[a] = new_state(w);
        ຖ້າ (b < M)
            ຖ້າ (tcc_compile_string(s[b], my_program) == -1)
                bha_nga;
        ຖ້າ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ຖ້າ (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            ຖ້າ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ຖ້າ (e < M)
            tcc_delete(s[e]);
    }
    ສົ່ງຄືນ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ຈຳນວນເຕັມ (*func)(ຈຳນວນເຕັມ);
    ຈຳນວນເຕັມ ret;
    ຈຳນວນເຕັມ n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    ຖ້າ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        ຖ້າ (func) {
            ຖ້າ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ສົ່ງຄືນ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ຈຳນວນເຕັມ ret;
    ຈຳນວນເຕັມ n = (size_t)vn;
    var_na *argv[30], b[10];
    ຈຳນວນເຕັມ argc = 0, i;

    sprintf(b, "%d", F(n));

    ສຳລັບ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ຖ້າ 0
    argv[argc++] = "-run";
    ສຳລັບ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
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
    ຖ້າ (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ສົ່ງຄືນ 0;
}

void time_tcc(ຈຳນວນເຕັມ n, const var_na *src)
{
    TCCState *s;
    ຈຳນວນເຕັມ ret, i = 0;
    ໃນຂະນະທີ່ (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        ຖ້າ (ret < 0)
            exit(1);
    }
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    ສົ່ງຄືນ GetTickCount();
#ບໍ່ດັ່ງນັ້ນ
    sa_nracanaa timeval tv;
    gettimeofday(&tv, NULL);
    ສົ່ງຄືນ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    ຈຳນວນເຕັມ n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    ຖ້າ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ສົ່ງຄືນ 1;
    }

#ຖ້າ 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ຖ້າ 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ຖ້າ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ສຳລັບ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#ຖ້າ 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ສຳລັບ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ຖ້າ 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    ສົ່ງຄືນ 0;
}

#ບໍ່ດັ່ງນັ້ນ
#include <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    void Sleep(unsigned);
# define sleep_ms Sleep
#ບໍ່ດັ່ງນັ້ນ
    ຈຳນວນເຕັມ usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

ຈຳນວນເຕັມ fib(n)
{
    ສົ່ງຄືນ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    ສົ່ງຄືນ 0;
}
#endif
