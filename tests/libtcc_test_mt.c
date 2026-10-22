/*
 * Multi-thread Test for libtcc
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ FIB
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>
#ਅਨ੍ਤਰ੍ਭਾਵ "libtcc.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M 20 /* number of states */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ F(n) (n % 20 + 2) /* fib argument */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TF_TYPE(func, param) DWORD WINAPI func(ਖਾਲੀ *param)
ਕਿਸਮਪਰਿਭਾਸ਼ਾ TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
ਖਾਲੀ create_thread(ThreadFunc f, ਪੂਰਨ n)
{
    DWORD tid;
    hh[n] = CreateThread(ਨਿਰਾ, 0, f, (ਖਾਲੀ*)(ਮਾਪ_t)n, 0, &tid);
}
ਖਾਲੀ wait_ਧਾਗੇ(ਪੂਰਨ n)
{
    Wait_For_ਗੁਣਜ_Objects(n, hh, TRUE, INFINITE);
    ਜਦੋਂ (n)
        CloseHandle(hh[--n]);
}
ਖਾਲੀ sleep_ms(ਬਿਨਾਨਿਸ਼ਾਨੀ n)
{
    Sleep(n);
}
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/time.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TF_TYPE(func, param) ਖਾਲੀ* func(ਖਾਲੀ *param)
ਕਿਸਮਪਰਿਭਾਸ਼ਾ TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
ਖਾਲੀ create_thread(ThreadFunc f, ਪੂਰਨ n)
{
    pthread_create(&hh[n], ਨਿਰਾ, f, (ਖਾਲੀ*)(ਮਾਪ_t)n);
}
ਖਾਲੀ wait_ਧਾਗੇ(ਪੂਰਨ n)
{
    ਜਦੋਂ (n)
        pthread_join(hh[--n], ਨਿਰਾ);

}
ਖਾਲੀ sleep_ms(ਬਿਨਾਨਿਸ਼ਾਨੀ n)
{
    usleep(n * 1000);
}
#ਜੇ_ਅੰਤ

ਖਾਲੀ handle_error(ਖਾਲੀ *opaque, ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
    fprintf(opaque, "%s\n", ਸੁਨੇਹਾ);
}

/* this function is called by the generated code */
ਪੂਰਨ ਜੋੜੋ(ਪੂਰਨ a, ਪੂਰਨ b)
{
    ਵਾਪਸ a + b;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _str(s) #s
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROG(lbl) \
    ਅੱਖਰ lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_ਪ੍ਰੋਗਰਾਮ)
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

ਪੂਰਨ g_argc; ਅੱਖਰ **g_argv;

ਖਾਲੀ parse_ਦਲੀਲਾਂ(TCCState *s)
{
    ਪੂਰਨ i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    ਲਈ (i = 1; i < g_argc; ++i) {
        ਅੱਖਰ *a = g_argv[i];
        ਜੇ (a[0] == '-') {
            ਜੇ (a[1] == 'B')
                tcc_ਸੈੱਟ_lib_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'I')
                tcc_ਜੋੜੋ_include_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'L')
                tcc_ਜੋੜੋ_library_ਰਸਤਾ(s, a+2);
            ਨਹੀਂਤਾਂ ਜੇ (a[1] == 'D')
                tcc_define_ਚਿੰਨ੍ਹ(s, a+2, ਨਿਰਾ);
        }
    }
}

ਪੂਰਨ backtrace_func(
    ਖਾਲੀ *ud,
    ਖਾਲੀ *pc,
    ਅਚਲ ਅੱਖਰ *file,
    ਪੂਰਨ ਸਤਰ,
    ਅਚਲ ਅੱਖਰ *func,
    ਅਚਲ ਅੱਖਰ *ਸੁਨੇਹਾ)
{
#ਜੇ 0
    ਲਿਖੋ("\n  *** %p %s %s:%d in '%s'",
        pc,
        ਸੁਨੇਹਾ ? "at" : "by",
        file ? file : "?",
        ਸਤਰ,
        func ? func : "?");
    ਵਾਪਸ 1; // want more backtrace levels
#ਨਹੀਂਤਾਂ
    //printf(" [%d]", *(int*)ud);
    ਲਿਖੋ("!");
    ਵਾਪਸ 0; // cancel backtrace
#ਜੇ_ਅੰਤ
}

TCCState *new_state(ਪੂਰਨ w)
{
    TCCState *s = tcc_new();
    ਜੇ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        ਬਾਹਰ_ਨਿਕਲੋ(1);
    }
    tcc_ਸੈੱਟ_error_func(s, stdout, handle_error);
    parse_ਦਲੀਲਾਂ(s);
    ਜੇ (0 == (w & 1))
        tcc_ਸੈੱਟ_options(s, "-w");
    ਜੇ (w & 2) {
        tcc_ਸੈੱਟ_options(s, "-bt");
        tcc_define_ਚਿੰਨ੍ਹ(s, "N_CRASH", str(M/2));
    } ਨਹੀਂਤਾਂ
        tcc_define_ਚਿੰਨ੍ਹ(s, "N_CRASH", "-1000");
    tcc_ਸੈੱਟ_output_type(s, TCC_OUTPUT_ਸਮ੍ਰਿਤੀ);
    ਵਾਪਸ s;
}

ਖਾਲੀ *reloc_state(TCCState *s, ਅਚਲ ਅੱਖਰ *entry)
{
    ਖਾਲੀ *func;
    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s, "add", ਜੋੜੋ);
    tcc_ਜੋੜੋ_ਚਿੰਨ੍ਹ(s, "printf", ਲਿਖੋ);
    ਜੇ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        ਵਾਪਸ ਨਿਰਾ;
    }
    func = tcc_get_ਚਿੰਨ੍ਹ(s, entry);
    ਜੇ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    ਵਾਪਸ func;
}

/* work with several states at the same time */
ਪੂਰਨ state_test(ਪੂਰਨ w)
{
    TCCState *s[M];
    ਪੂਰਨ (*funcs[M])(ਪੂਰਨ);
    ਪੂਰਨ n;
    jmp_buf jb;

    ਲਈ (n = 0; n < M + 4; ++n) {
        ਬਿਨਾਨਿਸ਼ਾਨੀ a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ਜੇ (a < M)
            s[a] = new_state(w);
        ਜੇ (b < M)
            ਜੇ (tcc_compile_string(s[b], my_ਪ੍ਰੋਗਰਾਮ) == -1)
                ਰੋਕੋ;
        ਜੇ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ਜੇ (d < M && funcs[d]) {
            tcc_ਸੈੱਟ_backtrace_func(s[d], &d, backtrace_func);
            ਜੇ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ਜੇ (e < M)
            tcc_delete(s[e]);
    }
    ਵਾਪਸ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    ਪੂਰਨ (*func)(ਪੂਰਨ);
    ਪੂਰਨ ret;
    ਪੂਰਨ n = (ਮਾਪ_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_ਪ੍ਰੋਗਰਾਮ);
    sleep_ms(1);
    ਜੇ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_ਸੈੱਟ_backtrace_func(s, &n, backtrace_func);
        ਜੇ (func) {
            ਜੇ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    ਵਾਪਸ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    ਪੂਰਨ ret;
    ਪੂਰਨ n = (ਮਾਪ_t)vn;
    ਅੱਖਰ *argv[30], b[10];
    ਪੂਰਨ argc = 0, i;

    sprintf(b, "%d", F(n));

    ਲਈ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ਜੇ 0
    argv[argc++] = "-run";
    ਲਈ (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ਜੇ_ਅੰਤ
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ਨਿਰਾ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_ਜੋੜੋ_file(s, argv[0]);
    sleep_ms(3);
    ਜੇ (ret == 0)
        tcc_ਲੜੀਵਾਰ(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    ਵਾਪਸ 0;
}

ਖਾਲੀ ਸਮਾਂ_tcc(ਪੂਰਨ n, ਅਚਲ ਅੱਖਰ *src)
{
    TCCState *s;
    ਪੂਰਨ ret, i = 0;
    ਜਦੋਂ (i++ < n) {
        s = new_state(1);
        ਲਿਖੋ(" %d", i), fflush(stdout);
        ret = tcc_ਜੋੜੋ_file(s, src);
        tcc_delete(s);
        ਜੇ (ret < 0)
            ਬਾਹਰ_ਨਿਕਲੋ(1);
    }
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ getclock_ms(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਵਾਪਸ Get_Tick_ਗਿਣਤੀ();
#ਨਹੀਂਤਾਂ
    ਬਣਤਰ timeval tv;
    gettimeofday(&tv, ਨਿਰਾ);
    ਵਾਪਸ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਪੂਰਨ n;
    ਬਿਨਾਨਿਸ਼ਾਨੀ t;

    g_argc = argc;
    g_argv = argv;

    ਜੇ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        ਵਾਪਸ 1;
    }

#ਜੇ 1
    ਲਿਖੋ("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    ਲਿਖੋ("\n (%u ms)\n", getclock_ms() - t);
#ਜੇ_ਅੰਤ
#ਜੇ 1
    ਲਿਖੋ("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    ਲਿਖੋ("\n (%u ms)\n", getclock_ms() - t);
#ਜੇ_ਅੰਤ
#ਜੇ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    ਲਿਖੋ("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    ਲਈ (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_ਧਾਗੇ(n);
    ਲਿਖੋ("\n (%u ms)\n", getclock_ms() - t);
        //}}
#ਜੇ_ਅੰਤ
#ਜੇ 1
    ਲਿਖੋ("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    ਲਈ (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_ਧਾਗੇ(n);
    ਲਿਖੋ("\n (%u ms)\n", getclock_ms() - t);
#ਜੇ_ਅੰਤ
#ਜੇ 1
    ਲਿਖੋ("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    ਸਮਾਂ_tcc(10, argv[1]);
    ਲਿਖੋ("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#ਜੇ_ਅੰਤ
    ਵਾਪਸ 0;
}

#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <tcclib.h>
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    ਖਾਲੀ Sleep(ਬਿਨਾਨਿਸ਼ਾਨੀ);
# define sleep_ms Sleep
#ਨਹੀਂਤਾਂ
    ਪੂਰਨ usleep(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ);
# define sleep_ms(x) usleep((x)*1000);
#ਜੇ_ਅੰਤ

ਪੂਰਨ fib(n)
{
    ਵਾਪਸ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    sleep_ms(333);
    ਲਿਖੋ(" %d", fib(atoi(argv[1])));
    ਵਾਪਸ 0;
}
#ਜੇ_ਅੰਤ
