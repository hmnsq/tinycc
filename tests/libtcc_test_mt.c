/*
 * Multi-thread Test for libtcc
 */

#اگر_غیر_تعریف_شدہ FIB
#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>
#شامل "libtcc.h"

#تعریف_کرو M 20 /* number of states */
#تعریف_کرو F(n) (n % 20 + 2) /* fib argument */

#اگر_تعریف_شدہ _WIN32
#شامل <windows.h>
#تعریف_کرو TF_TYPE(func, param) DWORD WINAPI func(خالی *param)
قسمتعریف TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
خالی create_thread(ThreadFunc f, صحیح n)
{
    DWORD tid;
    hh[n] = CreateThread(تہی, 0, f, (خالی*)(سائز_t)n, 0, &tid);
}
خالی wait_دھاگے(صحیح n)
{
    Wait_For_مضرب_Objects(n, hh, TRUE, INFINITE);
    جب (n)
        CloseHandle(hh[--n]);
}
خالی sleep_ms(غیرعلامتی n)
{
    Sleep(n);
}
#ورنہ
#شامل <sys/time.h>
#شامل <unistd.h>
#شامل <pthread.h>
#تعریف_کرو TF_TYPE(func, param) خالی* func(خالی *param)
قسمتعریف TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
خالی create_thread(ThreadFunc f, صحیح n)
{
    pthread_create(&hh[n], تہی, f, (خالی*)(سائز_t)n);
}
خالی wait_دھاگے(صحیح n)
{
    جب (n)
        pthread_join(hh[--n], تہی);

}
خالی sleep_ms(غیرعلامتی n)
{
    usleep(n * 1000);
}
#اگر_ختم

خالی handle_error(خالی *opaque, ثابت حرف *پیغام)
{
    fprintf(opaque, "%s\n", پیغام);
}

/* this function is called by the generated code */
صحیح جوڑو(صحیح a, صحیح b)
{
    واپس a + b;
}

#تعریف_کرو _str(s) #s
#تعریف_کرو str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#تعریف_کرو PROG(lbl) \
    حرف lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_پروگرام)
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

صحیح g_argc; حرف **g_argv;

خالی parse_دلائل(TCCState *s)
{
    صحیح i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    برائے (i = 1; i < g_argc; ++i) {
        حرف *a = g_argv[i];
        اگر (a[0] == '-') {
            اگر (a[1] == 'B')
                tcc_سیٹ_lib_راستہ(s, a+2);
            ورنہ اگر (a[1] == 'I')
                tcc_جوڑو_include_راستہ(s, a+2);
            ورنہ اگر (a[1] == 'L')
                tcc_جوڑو_library_راستہ(s, a+2);
            ورنہ اگر (a[1] == 'D')
                tcc_define_علامت(s, a+2, تہی);
        }
    }
}

صحیح backtrace_func(
    خالی *ud,
    خالی *pc,
    ثابت حرف *file,
    صحیح سطر,
    ثابت حرف *func,
    ثابت حرف *پیغام)
{
#اگر 0
    لکھو("\n  *** %p %s %s:%d in '%s'",
        pc,
        پیغام ? "at" : "by",
        file ? file : "?",
        سطر,
        func ? func : "?");
    واپس 1; // want more backtrace levels
#ورنہ
    //printf(" [%d]", *(int*)ud);
    لکھو("!");
    واپس 0; // cancel backtrace
#اگر_ختم
}

TCCState *new_state(صحیح w)
{
    TCCState *s = tcc_new();
    اگر (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        باہر_نکلو(1);
    }
    tcc_سیٹ_error_func(s, stdout, handle_error);
    parse_دلائل(s);
    اگر (0 == (w & 1))
        tcc_سیٹ_options(s, "-w");
    اگر (w & 2) {
        tcc_سیٹ_options(s, "-bt");
        tcc_define_علامت(s, "N_CRASH", str(M/2));
    } ورنہ
        tcc_define_علامت(s, "N_CRASH", "-1000");
    tcc_سیٹ_output_type(s, TCC_OUTPUT_حافظہ);
    واپس s;
}

خالی *reloc_state(TCCState *s, ثابت حرف *entry)
{
    خالی *func;
    tcc_جوڑو_علامت(s, "add", جوڑو);
    tcc_جوڑو_علامت(s, "printf", لکھو);
    اگر (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        واپس تہی;
    }
    func = tcc_get_علامت(s, entry);
    اگر (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    واپس func;
}

/* work with several states at the same time */
صحیح state_test(صحیح w)
{
    TCCState *s[M];
    صحیح (*funcs[M])(صحیح);
    صحیح n;
    jmp_buf jb;

    برائے (n = 0; n < M + 4; ++n) {
        غیرعلامتی a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        اگر (a < M)
            s[a] = new_state(w);
        اگر (b < M)
            اگر (tcc_compile_string(s[b], my_پروگرام) == -1)
                توڑو;
        اگر (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        اگر (d < M && funcs[d]) {
            tcc_سیٹ_backtrace_func(s[d], &d, backtrace_func);
            اگر (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        اگر (e < M)
            tcc_delete(s[e]);
    }
    واپس 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    صحیح (*func)(صحیح);
    صحیح ret;
    صحیح n = (سائز_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_پروگرام);
    sleep_ms(1);
    اگر (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_سیٹ_backtrace_func(s, &n, backtrace_func);
        اگر (func) {
            اگر (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    واپس 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    صحیح ret;
    صحیح n = (سائز_t)vn;
    حرف *argv[30], b[10];
    صحیح argc = 0, i;

    sprintf(b, "%d", F(n));

    برائے (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#اگر 0
    argv[argc++] = "-run";
    برائے (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#اگر_ختم
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = تہی;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_جوڑو_file(s, argv[0]);
    sleep_ms(3);
    اگر (ret == 0)
        tcc_تسلسل(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    واپس 0;
}

خالی وقت_tcc(صحیح n, ثابت حرف *src)
{
    TCCState *s;
    صحیح ret, i = 0;
    جب (i++ < n) {
        s = new_state(1);
        لکھو(" %d", i), fflush(stdout);
        ret = tcc_جوڑو_file(s, src);
        tcc_delete(s);
        اگر (ret < 0)
            باہر_نکلو(1);
    }
}

ساکن غیرعلامتی getclock_ms(خالی)
{
#اگر_تعریف_شدہ _WIN32
    واپس Get_Tick_گنتی();
#ورنہ
    ساخت timeval tv;
    gettimeofday(&tv, تہی);
    واپس tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#اگر_ختم
}

صحیح مین(صحیح argc, حرف **argv)
{
    صحیح n;
    غیرعلامتی t;

    g_argc = argc;
    g_argv = argv;

    اگر (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        واپس 1;
    }

#اگر 1
    لکھو("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#اگر_ختم
#اگر 1
    لکھو("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#اگر_ختم
#اگر 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    لکھو("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    برائے (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_دھاگے(n);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
        //}}
#اگر_ختم
#اگر 1
    لکھو("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    برائے (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_دھاگے(n);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#اگر_ختم
#اگر 1
    لکھو("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    وقت_tcc(10, argv[1]);
    لکھو("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#اگر_ختم
    واپس 0;
}

#ورنہ
#شامل <tcclib.h>
#اگر_تعریف_شدہ _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    خالی Sleep(غیرعلامتی);
# define sleep_ms Sleep
#ورنہ
    صحیح usleep(غیرعلامتی طویل);
# define sleep_ms(x) usleep((x)*1000);
#اگر_ختم

صحیح fib(n)
{
    واپس (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

صحیح مین(صحیح argc, حرف **argv)
{
    sleep_ms(333);
    لکھو(" %d", fib(atoi(argv[1])));
    واپس 0;
}
#اگر_ختم
