/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <setjmp.h>
#അന്തര്ഭാവ "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#അന്തര്ഭാവ <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(ശൂന്യം *param)
തരനിർവചനം TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
ശൂന്യം create_thread(ThreadFunc f, പൂർണ്ണസംഖ്യ n)
{
    DWORD tid;
    hh[n] = CreateThread(ശൂന്യ, 0, f, (ശൂന്യം*)(size_t)n, 0, &tid);
}
ശൂന്യം wait_threads(പൂർണ്ണസംഖ്യ n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    ആകുമ്പോൾ (n)
        CloseHandle(hh[--n]);
}
ശൂന്യം sleep_ms(unsigned n)
{
    Sleep(n);
}
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <sys/time.h>
#അന്തര്ഭാവ <unistd.h>
#അന്തര്ഭാവ <pthread.h>
#define TF_TYPE(func, param) ശൂന്യം* func(ശൂന്യം *param)
തരനിർവചനം TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
ശൂന്യം create_thread(ThreadFunc f, പൂർണ്ണസംഖ്യ n)
{
    pthread_create(&hh[n], ശൂന്യ, f, (ശൂന്യം*)(size_t)n);
}
ശൂന്യം wait_threads(പൂർണ്ണസംഖ്യ n)
{
    ആകുമ്പോൾ (n)
        pthread_join(hh[--n], ശൂന്യ);

}
ശൂന്യം sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

ശൂന്യം handle_error(ശൂന്യം *opaque, സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
    fprintf(opaque, "%s\n", സന്ദേശം);
}

/* this function is called by the generated code */
പൂർണ്ണസംഖ്യ add(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    തിരികെ a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    അക്ഷരം lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

പൂർണ്ണസംഖ്യ g_argc; അക്ഷരം **g_argv;

ശൂന്യം parse_args(TCCState *s)
{
    പൂർണ്ണസംഖ്യ i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    വേണ്ടി (i = 1; i < g_argc; ++i) {
        അക്ഷരം *a = g_argv[i];
        എങ്കിൽ (a[0] == '-') {
            എങ്കിൽ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'D')
                tcc_define_ചിഹ്നം(s, a+2, ശൂന്യ);
        }
    }
}

പൂർണ്ണസംഖ്യ backtrace_func(
    ശൂന്യം *ud,
    ശൂന്യം *pc,
    സ്ഥിരം അക്ഷരം *file,
    പൂർണ്ണസംഖ്യ വരി,
    സ്ഥിരം അക്ഷരം *func,
    സ്ഥിരം അക്ഷരം *സന്ദേശം)
{
#എങ്കിൽ 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        സന്ദേശം ? "at" : "by",
        file ? file : "?",
        വരി,
        func ? func : "?");
    തിരികെ 1; // want more backtrace levels
#അല്ലെങ്കിൽ
    //printf(" [%d]", *(int*)ud);
    printf("!");
    തിരികെ 0; // cancel backtrace
#endif
}

TCCState *new_state(പൂർണ്ണസംഖ്യ w)
{
    TCCState *s = tcc_new();
    എങ്കിൽ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    എങ്കിൽ (0 == (w & 1))
        tcc_set_options(s, "-w");
    എങ്കിൽ (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_ചിഹ്നം(s, "N_CRASH", str(M/2));
    } അല്ലെങ്കിൽ
        tcc_define_ചിഹ്നം(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    തിരികെ s;
}

ശൂന്യം *reloc_state(TCCState *s, സ്ഥിരം അക്ഷരം *entry)
{
    ശൂന്യം *func;
    tcc_add_ചിഹ്നം(s, "add", add);
    tcc_add_ചിഹ്നം(s, "printf", printf);
    എങ്കിൽ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        തിരികെ ശൂന്യ;
    }
    func = tcc_get_ചിഹ്നം(s, entry);
    എങ്കിൽ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    തിരികെ func;
}

/* work with several states at the same time */
പൂർണ്ണസംഖ്യ state_test(പൂർണ്ണസംഖ്യ w)
{
    TCCState *s[M];
    പൂർണ്ണസംഖ്യ (*funcs[M])(പൂർണ്ണസംഖ്യ);
    പൂർണ്ണസംഖ്യ n;
    jmp_buf jb;

    വേണ്ടി (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        എങ്കിൽ (a < M)
            s[a] = new_state(w);
        എങ്കിൽ (b < M)
            എങ്കിൽ (tcc_compile_string(s[b], my_program) == -1)
                നിർത്തുക;
        എങ്കിൽ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        എങ്കിൽ (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            എങ്കിൽ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        എങ്കിൽ (e < M)
            tcc_delete(s[e]);
    }
    തിരികെ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    പൂർണ്ണസംഖ്യ (*func)(പൂർണ്ണസംഖ്യ);
    പൂർണ്ണസംഖ്യ ret;
    പൂർണ്ണസംഖ്യ n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    എങ്കിൽ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        എങ്കിൽ (func) {
            എങ്കിൽ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    തിരികെ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    പൂർണ്ണസംഖ്യ ret;
    പൂർണ്ണസംഖ്യ n = (size_t)vn;
    അക്ഷരം *argv[30], b[10];
    പൂർണ്ണസംഖ്യ argc = 0, i;

    sprintf(b, "%d", F(n));

    വേണ്ടി (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#എങ്കിൽ 0
    argv[argc++] = "-run";
    വേണ്ടി (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ശൂന്യ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    എങ്കിൽ (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    തിരികെ 0;
}

ശൂന്യം time_tcc(പൂർണ്ണസംഖ്യ n, സ്ഥിരം അക്ഷരം *src)
{
    TCCState *s;
    പൂർണ്ണസംഖ്യ ret, i = 0;
    ആകുമ്പോൾ (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        എങ്കിൽ (ret < 0)
            exit(1);
    }
}

സ്ഥിതം unsigned getclock_ms(ശൂന്യം)
{
#ifdef _WIN32
    തിരികെ Get_Tick_എണ്ണം();
#അല്ലെങ്കിൽ
    ഘടന timeval tv;
    gettimeofday(&tv, ശൂന്യ);
    തിരികെ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    എങ്കിൽ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        തിരികെ 1;
    }

#എങ്കിൽ 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#എങ്കിൽ 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#എങ്കിൽ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    വേണ്ടി (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#എങ്കിൽ 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    വേണ്ടി (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#എങ്കിൽ 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    തിരികെ 0;
}

#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    ശൂന്യം Sleep(unsigned);
# define sleep_ms Sleep
#അല്ലെങ്കിൽ
    പൂർണ്ണസംഖ്യ usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

പൂർണ്ണസംഖ്യ fib(n)
{
    തിരികെ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    തിരികെ 0;
}
#endif
