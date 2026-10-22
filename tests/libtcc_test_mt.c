/*
 * Multi-thread Test for libtcc
 */

#که_نه_تعریف_شوی FIB
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#ضمن "libtcc.h"

#تعریف_کړه M 20 /* number of states */
#تعریف_کړه F(n) (n % 20 + 2) /* fib argument */

#که_تعریف_شوی _WIN32
#ضمن <windows.h>
#تعریف_کړه TF_TYPE(func, param) DWORD WINAPI func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    DWORD tid;
    hh[n] = CreateThread(عدم, 0, f, (فراغ*)(اندازه_t)n, 0, &tid);
}
فراغ wait_تارونه(صحيح n)
{
    Wait_For_مضرب_Objects(n, hh, TRUE, INFINITE);
    طالما (n)
        CloseHandle(hh[--n]);
}
فراغ sleep_ms(بینښه n)
{
    Sleep(n);
}
#وإلا
#ضمن <sys/time.h>
#ضمن <unistd.h>
#ضمن <pthread.h>
#تعریف_کړه TF_TYPE(func, param) فراغ* func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    pthread_create(&hh[n], عدم, f, (فراغ*)(اندازه_t)n);
}
فراغ wait_تارونه(صحيح n)
{
    طالما (n)
        pthread_join(hh[--n], عدم);

}
فراغ sleep_ms(بینښه n)
{
    usleep(n * 1000);
}
#د_که_پای

فراغ handle_error(فراغ *opaque, ثابت حرف *پیغام)
{
    fprintf(opaque, "%s\n", پیغام);
}

/* this function is called by the generated code */
صحيح جمع_کړه(صحيح a, صحيح b)
{
    أرجع a + b;
}

#تعریف_کړه _str(s) #s
#تعریف_کړه str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#تعریف_کړه PROG(lbl) \
    حرف lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_پروګرام)
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

صحيح g_argc; حرف **g_argv;

فراغ parse_دلیلونه(TCCState *s)
{
    صحيح i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    لكل (i = 1; i < g_argc; ++i) {
        حرف *a = g_argv[i];
        إذا (a[0] == '-') {
            إذا (a[1] == 'B')
                tcc_سېټ_lib_لار(s, a+2);
            وإلا إذا (a[1] == 'I')
                tcc_جمع_کړه_include_لار(s, a+2);
            وإلا إذا (a[1] == 'L')
                tcc_جمع_کړه_library_لار(s, a+2);
            وإلا إذا (a[1] == 'D')
                tcc_define_نښه(s, a+2, عدم);
        }
    }
}

صحيح backtrace_func(
    فراغ *ud,
    فراغ *pc,
    ثابت حرف *file,
    صحيح کرښه,
    ثابت حرف *func,
    ثابت حرف *پیغام)
{
#إذا 0
    چاپ_کړه("\n  *** %p %s %s:%d in '%s'",
        pc,
        پیغام ? "at" : "by",
        file ? file : "?",
        کرښه,
        func ? func : "?");
    أرجع 1; // want more backtrace levels
#وإلا
    //printf(" [%d]", *(int*)ud);
    چاپ_کړه("!");
    أرجع 0; // cancel backtrace
#د_که_پای
}

TCCState *new_state(صحيح w)
{
    TCCState *s = tcc_new();
    إذا (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        وتل(1);
    }
    tcc_سېټ_error_func(s, stdout, handle_error);
    parse_دلیلونه(s);
    إذا (0 == (w & 1))
        tcc_سېټ_options(s, "-w");
    إذا (w & 2) {
        tcc_سېټ_options(s, "-bt");
        tcc_define_نښه(s, "N_CRASH", str(M/2));
    } وإلا
        tcc_define_نښه(s, "N_CRASH", "-1000");
    tcc_سېټ_output_type(s, TCC_OUTPUT_حافظه);
    أرجع s;
}

فراغ *reloc_state(TCCState *s, ثابت حرف *entry)
{
    فراغ *func;
    tcc_جمع_کړه_نښه(s, "add", جمع_کړه);
    tcc_جمع_کړه_نښه(s, "printf", چاپ_کړه);
    إذا (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        أرجع عدم;
    }
    func = tcc_get_نښه(s, entry);
    إذا (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    أرجع func;
}

/* work with several states at the same time */
صحيح state_test(صحيح w)
{
    TCCState *s[M];
    صحيح (*funcs[M])(صحيح);
    صحيح n;
    jmp_buf jb;

    لكل (n = 0; n < M + 4; ++n) {
        بینښه a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        إذا (a < M)
            s[a] = new_state(w);
        إذا (b < M)
            إذا (tcc_compile_string(s[b], my_پروګرام) == -1)
                اكسر;
        إذا (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        إذا (d < M && funcs[d]) {
            tcc_سېټ_backtrace_func(s[d], &d, backtrace_func);
            إذا (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        إذا (e < M)
            tcc_delete(s[e]);
    }
    أرجع 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    صحيح (*func)(صحيح);
    صحيح ret;
    صحيح n = (اندازه_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_پروګرام);
    sleep_ms(1);
    إذا (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_سېټ_backtrace_func(s, &n, backtrace_func);
        إذا (func) {
            إذا (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    أرجع 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    صحيح ret;
    صحيح n = (اندازه_t)vn;
    حرف *argv[30], b[10];
    صحيح argc = 0, i;

    sprintf(b, "%d", F(n));

    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#إذا 0
    argv[argc++] = "-run";
    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#د_که_پای
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = عدم;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_جمع_کړه_file(s, argv[0]);
    sleep_ms(3);
    إذا (ret == 0)
        tcc_پرلپسې(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    أرجع 0;
}

فراغ وخت_tcc(صحيح n, ثابت حرف *src)
{
    TCCState *s;
    صحيح ret, i = 0;
    طالما (i++ < n) {
        s = new_state(1);
        چاپ_کړه(" %d", i), fflush(stdout);
        ret = tcc_جمع_کړه_file(s, src);
        tcc_delete(s);
        إذا (ret < 0)
            وتل(1);
    }
}

ساكن بینښه getclock_ms(فراغ)
{
#که_تعریف_شوی _WIN32
    أرجع Get_Tick_شمېر();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#د_که_پای
}

صحيح اصلي(صحيح argc, حرف **argv)
{
    صحيح n;
    بینښه t;

    g_argc = argc;
    g_argv = argv;

    إذا (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        أرجع 1;
    }

#إذا 1
    چاپ_کړه("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    چاپ_کړه("\n (%u ms)\n", getclock_ms() - t);
#د_که_پای
#إذا 1
    چاپ_کړه("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    چاپ_کړه("\n (%u ms)\n", getclock_ms() - t);
#د_که_پای
#إذا 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    چاپ_کړه("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_تارونه(n);
    چاپ_کړه("\n (%u ms)\n", getclock_ms() - t);
        //}}
#د_که_پای
#إذا 1
    چاپ_کړه("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_تارونه(n);
    چاپ_کړه("\n (%u ms)\n", getclock_ms() - t);
#د_که_پای
#إذا 1
    چاپ_کړه("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    وخت_tcc(10, argv[1]);
    چاپ_کړه("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#د_که_پای
    أرجع 0;
}

#وإلا
#ضمن <tcclib.h>
#که_تعریف_شوی _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    فراغ Sleep(بینښه);
# define sleep_ms Sleep
#وإلا
    صحيح usleep(بینښه اوږد);
# define sleep_ms(x) usleep((x)*1000);
#د_که_پای

صحيح fib(n)
{
    أرجع (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

صحيح اصلي(صحيح argc, حرف **argv)
{
    sleep_ms(333);
    چاپ_کړه(" %d", fib(atoi(argv[1])));
    أرجع 0;
}
#د_که_پای
