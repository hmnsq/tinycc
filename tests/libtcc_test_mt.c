/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>
#ଅନ୍ତର୍ଭାଵ "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#ଅନ୍ତର୍ଭାଵ <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(ଶୂନ୍ୟ *param)
ପ୍ରକାରବ୍ୟାଖ୍ୟା TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
ଶୂନ୍ୟ create_thread(ThreadFunc f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    DWORD tid;
    hh[n] = CreateThread(ଖାଲି, 0, f, (ଶୂନ୍ୟ*)(size_t)n, 0, &tid);
}
ଶୂନ୍ୟ wait_threads(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ଯେତେବେଳେ (n)
        CloseHandle(hh[--n]);
}
ଶୂନ୍ୟ sleep_ms(unsigned n)
{
    Sleep(n);
}
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <sys/time.h>
#ଅନ୍ତର୍ଭାଵ <unistd.h>
#ଅନ୍ତର୍ଭାଵ <pthread.h>
#define TF_TYPE(func, param) ଶୂନ୍ୟ* func(ଶୂନ୍ୟ *param)
ପ୍ରକାରବ୍ୟାଖ୍ୟା TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
ଶୂନ୍ୟ create_thread(ThreadFunc f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    pthread_create(&hh[n], ଖାଲି, f, (ଶୂନ୍ୟ*)(size_t)n);
}
ଶୂନ୍ୟ wait_threads(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଯେତେବେଳେ (n)
        pthread_join(hh[--n], ଖାଲି);

}
ଶୂନ୍ୟ sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

ଶୂନ୍ୟ handle_error(ଶୂନ୍ୟ *opaque, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
    fprintf(opaque, "%s\n", ସନ୍ଦେଶ);
}

/* this function is called by the generated code */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା add(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଫେରନ୍ତୁ a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    ଅକ୍ଷର lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_argc; ଅକ୍ଷର **g_argv;

ଶୂନ୍ୟ parse_args(TCCState *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ପାଇଁ (i = 1; i < g_argc; ++i) {
        ଅକ୍ଷର *a = g_argv[i];
        ଯଦି (a[0] == '-') {
            ଯଦି (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            ଅନ୍ୟଥା ଯଦି (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            ଅନ୍ୟଥା ଯଦି (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            ଅନ୍ୟଥା ଯଦି (a[1] == 'D')
                tcc_define_ପ୍ରତୀକ(s, a+2, ଖାଲି);
        }
    }
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା backtrace_func(
    ଶୂନ୍ୟ *ud,
    ଶୂନ୍ୟ *pc,
    ଅଚଳ ଅକ୍ଷର *file,
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି,
    ଅଚଳ ଅକ୍ଷର *func,
    ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ)
{
#ଯଦି 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        ସନ୍ଦେଶ ? "at" : "by",
        file ? file : "?",
        ଧାଡ଼ି,
        func ? func : "?");
    ଫେରନ୍ତୁ 1; // want more backtrace levels
#ଅନ୍ୟଥା
    //printf(" [%d]", *(int*)ud);
    printf("!");
    ଫେରନ୍ତୁ 0; // cancel backtrace
#endif
}

TCCState *new_state(ପୂର୍ଣ୍ଣସଂଖ୍ୟା w)
{
    TCCState *s = tcc_new();
    ଯଦି (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    ଯଦି (0 == (w & 1))
        tcc_set_options(s, "-w");
    ଯଦି (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_ପ୍ରତୀକ(s, "N_CRASH", str(M/2));
    } ଅନ୍ୟଥା
        tcc_define_ପ୍ରତୀକ(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    ଫେରନ୍ତୁ s;
}

ଶୂନ୍ୟ *reloc_state(TCCState *s, ଅଚଳ ଅକ୍ଷର *entry)
{
    ଶୂନ୍ୟ *func;
    tcc_add_ପ୍ରତୀକ(s, "add", add);
    tcc_add_ପ୍ରତୀକ(s, "printf", printf);
    ଯଦି (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ଫେରନ୍ତୁ ଖାଲି;
    }
    func = tcc_get_ପ୍ରତୀକ(s, entry);
    ଯଦି (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ଫେରନ୍ତୁ func;
}

/* work with several states at the same time */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା state_test(ପୂର୍ଣ୍ଣସଂଖ୍ୟା w)
{
    TCCState *s[M];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*funcs[M])(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
    jmp_buf jb;

    ପାଇଁ (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ଯଦି (a < M)
            s[a] = new_state(w);
        ଯଦି (b < M)
            ଯଦି (tcc_compile_string(s[b], my_program) == -1)
                ଭାଙ୍ଗ;
        ଯଦି (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ଯଦି (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            ଯଦି (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ଯଦି (e < M)
            tcc_delete(s[e]);
    }
    ଫେରନ୍ତୁ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*func)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    ଯଦି (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        ଯଦି (func) {
            ଯଦି (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ଫେରନ୍ତୁ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = (size_t)vn;
    ଅକ୍ଷର *argv[30], b[10];
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc = 0, i;

    sprintf(b, "%d", F(n));

    ପାଇଁ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ଯଦି 0
    argv[argc++] = "-run";
    ପାଇଁ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ଖାଲି;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    ଯଦି (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ time_tcc(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ଅଚଳ ଅକ୍ଷର *src)
{
    TCCState *s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret, i = 0;
    ଯେତେବେଳେ (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        ଯଦି (ret < 0)
            exit(1);
    }
}

ସ୍ଥିର unsigned getclock_ms(ଶୂନ୍ୟ)
{
#ifdef _WIN32
    ଫେରନ୍ତୁ Get_Tick_ଗଣନା();
#ଅନ୍ୟଥା
    ସଂରଚନା timeval tv;
    gettimeofday(&tv, ଖାଲି);
    ଫେରନ୍ତୁ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    ଯଦି (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ଫେରନ୍ତୁ 1;
    }

#ଯଦି 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ଯଦି 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ଯଦି 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ପାଇଁ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#ଯଦି 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ପାଇଁ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#ଯଦି 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    ଫେରନ୍ତୁ 0;
}

#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    ଶୂନ୍ୟ Sleep(unsigned);
# define sleep_ms Sleep
#ଅନ୍ୟଥା
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fib(n)
{
    ଫେରନ୍ତୁ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    ଫେରନ୍ତୁ 0;
}
#endif
