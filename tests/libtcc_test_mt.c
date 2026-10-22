/*
 * Multi-thread Test for libtcc
 */

#جے_بنا_تعریف FIB
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#ضمن "libtcc.h"

#تعریف_کرو M 20 /* number of states */
#تعریف_کرو F(n) (n % 20 + 2) /* fib argument */

#جے_تعریف_شدہ _WIN32
#ضمن <windows.h>
#تعریف_کرو TF_TYPE(func, param) DWORD WINAPI func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    DWORD tid;
    hh[n] = CreateThread(عدم, 0, f, (فراغ*)(ناپ_t)n, 0, &tid);
}
فراغ wait_دھاگے(صحيح n)
{
    Wait_For_مضرب_Objects(n, hh, TRUE, INFINITE);
    طالما (n)
        CloseHandle(hh[--n]);
}
فراغ sleep_ms(بنانشانی n)
{
    Sleep(n);
}
#وإلا
#ضمن <sys/time.h>
#ضمن <unistd.h>
#ضمن <pthread.h>
#تعریف_کرو TF_TYPE(func, param) فراغ* func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    pthread_create(&hh[n], عدم, f, (فراغ*)(ناپ_t)n);
}
فراغ wait_دھاگے(صحيح n)
{
    طالما (n)
        pthread_join(hh[--n], عدم);

}
فراغ sleep_ms(بنانشانی n)
{
    usleep(n * 1000);
}
#جے_انت

فراغ handle_error(فراغ *opaque, ثابت حرف *پیغام)
{
    fprintf(opaque, "%s\n", پیغام);
}

/* this function is called by the generated code */
صحيح جوڑو(صحيح a, صحيح b)
{
    أرجع a + b;
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

صحيح g_argc; حرف **g_argv;

فراغ parse_دلیلاں(TCCState *s)
{
    صحيح i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    لكل (i = 1; i < g_argc; ++i) {
        حرف *a = g_argv[i];
        إذا (a[0] == '-') {
            إذا (a[1] == 'B')
                tcc_سیٹ_lib_رستہ(s, a+2);
            وإلا إذا (a[1] == 'I')
                tcc_جوڑو_include_رستہ(s, a+2);
            وإلا إذا (a[1] == 'L')
                tcc_جوڑو_library_رستہ(s, a+2);
            وإلا إذا (a[1] == 'D')
                tcc_define_علامت(s, a+2, عدم);
        }
    }
}

صحيح backtrace_func(
    فراغ *ud,
    فراغ *pc,
    ثابت حرف *file,
    صحيح سطر,
    ثابت حرف *func,
    ثابت حرف *پیغام)
{
#إذا 0
    لکھو("\n  *** %p %s %s:%d in '%s'",
        pc,
        پیغام ? "at" : "by",
        file ? file : "?",
        سطر,
        func ? func : "?");
    أرجع 1; // want more backtrace levels
#وإلا
    //printf(" [%d]", *(int*)ud);
    لکھو("!");
    أرجع 0; // cancel backtrace
#جے_انت
}

TCCState *new_state(صحيح w)
{
    TCCState *s = tcc_new();
    إذا (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        باہر_نکلو(1);
    }
    tcc_سیٹ_error_func(s, stdout, handle_error);
    parse_دلیلاں(s);
    إذا (0 == (w & 1))
        tcc_سیٹ_options(s, "-w");
    إذا (w & 2) {
        tcc_سیٹ_options(s, "-bt");
        tcc_define_علامت(s, "N_CRASH", str(M/2));
    } وإلا
        tcc_define_علامت(s, "N_CRASH", "-1000");
    tcc_سیٹ_output_type(s, TCC_OUTPUT_حافظہ);
    أرجع s;
}

فراغ *reloc_state(TCCState *s, ثابت حرف *entry)
{
    فراغ *func;
    tcc_جوڑو_علامت(s, "add", جوڑو);
    tcc_جوڑو_علامت(s, "printf", لکھو);
    إذا (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        أرجع عدم;
    }
    func = tcc_get_علامت(s, entry);
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
        بنانشانی a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        إذا (a < M)
            s[a] = new_state(w);
        إذا (b < M)
            إذا (tcc_compile_string(s[b], my_پروگرام) == -1)
                اكسر;
        إذا (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        إذا (d < M && funcs[d]) {
            tcc_سیٹ_backtrace_func(s[d], &d, backtrace_func);
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
    صحيح n = (ناپ_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_پروگرام);
    sleep_ms(1);
    إذا (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_سیٹ_backtrace_func(s, &n, backtrace_func);
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
    صحيح n = (ناپ_t)vn;
    حرف *argv[30], b[10];
    صحيح argc = 0, i;

    sprintf(b, "%d", F(n));

    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#إذا 0
    argv[argc++] = "-run";
    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#جے_انت
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = عدم;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_جوڑو_file(s, argv[0]);
    sleep_ms(3);
    إذا (ret == 0)
        tcc_لگاتار(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    أرجع 0;
}

فراغ ویلا_tcc(صحيح n, ثابت حرف *src)
{
    TCCState *s;
    صحيح ret, i = 0;
    طالما (i++ < n) {
        s = new_state(1);
        لکھو(" %d", i), fflush(stdout);
        ret = tcc_جوڑو_file(s, src);
        tcc_delete(s);
        إذا (ret < 0)
            باہر_نکلو(1);
    }
}

ساكن بنانشانی getclock_ms(فراغ)
{
#جے_تعریف_شدہ _WIN32
    أرجع Get_Tick_گنتی();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#جے_انت
}

صحيح مکھ(صحيح argc, حرف **argv)
{
    صحيح n;
    بنانشانی t;

    g_argc = argc;
    g_argv = argv;

    إذا (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        أرجع 1;
    }

#إذا 1
    لکھو("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#جے_انت
#إذا 1
    لکھو("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#جے_انت
#إذا 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    لکھو("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_دھاگے(n);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
        //}}
#جے_انت
#إذا 1
    لکھو("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_دھاگے(n);
    لکھو("\n (%u ms)\n", getclock_ms() - t);
#جے_انت
#إذا 1
    لکھو("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    ویلا_tcc(10, argv[1]);
    لکھو("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#جے_انت
    أرجع 0;
}

#وإلا
#ضمن <tcclib.h>
#جے_تعریف_شدہ _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    فراغ Sleep(بنانشانی);
# define sleep_ms Sleep
#وإلا
    صحيح usleep(بنانشانی لما);
# define sleep_ms(x) usleep((x)*1000);
#جے_انت

صحيح fib(n)
{
    أرجع (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

صحيح مکھ(صحيح argc, حرف **argv)
{
    sleep_ms(333);
    لکھو(" %d", fib(atoi(argv[1])));
    أرجع 0;
}
#جے_انت
