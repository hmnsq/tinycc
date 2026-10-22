/*
 * Multi-thread Test for libtcc
 */

#جيڪڏهن_وصف_نه_ٿيل FIB
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#ضمن "libtcc.h"

#وصف_ڪريو M 20 /* number of states */
#وصف_ڪريو F(n) (n % 20 + 2) /* fib argument */

#جيڪڏهن_وصف_ٿيل _WIN32
#ضمن <windows.h>
#وصف_ڪريو TF_TYPE(func, param) DWORD WINAPI func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    DWORD tid;
    hh[n] = CreateThread(عدم, 0, f, (فراغ*)(سائيز_t)n, 0, &tid);
}
فراغ wait_ڌاڳا(صحيح n)
{
    Wait_For_گڻو_Objects(n, hh, TRUE, INFINITE);
    طالما (n)
        CloseHandle(hh[--n]);
}
فراغ sleep_ms(بنانشان n)
{
    Sleep(n);
}
#وإلا
#ضمن <sys/time.h>
#ضمن <unistd.h>
#ضمن <pthread.h>
#وصف_ڪريو TF_TYPE(func, param) فراغ* func(فراغ *param)
تعريفنوع TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
فراغ create_thread(ThreadFunc f, صحيح n)
{
    pthread_create(&hh[n], عدم, f, (فراغ*)(سائيز_t)n);
}
فراغ wait_ڌاڳا(صحيح n)
{
    طالما (n)
        pthread_join(hh[--n], عدم);

}
فراغ sleep_ms(بنانشان n)
{
    usleep(n * 1000);
}
#جيڪڏهن_پورو

فراغ handle_error(فراغ *opaque, ثابت حرف *نياپو)
{
    fprintf(opaque, "%s\n", نياپو);
}

/* this function is called by the generated code */
صحيح جوڙيو(صحيح a, صحيح b)
{
    أرجع a + b;
}

#وصف_ڪريو _str(s) #s
#وصف_ڪريو str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#وصف_ڪريو PROG(lbl) \
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

فراغ parse_دليلون(TCCState *s)
{
    صحيح i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    لكل (i = 1; i < g_argc; ++i) {
        حرف *a = g_argv[i];
        إذا (a[0] == '-') {
            إذا (a[1] == 'B')
                tcc_سيٽ_lib_رستو(s, a+2);
            وإلا إذا (a[1] == 'I')
                tcc_جوڙيو_include_رستو(s, a+2);
            وإلا إذا (a[1] == 'L')
                tcc_جوڙيو_library_رستو(s, a+2);
            وإلا إذا (a[1] == 'D')
                tcc_define_نشان(s, a+2, عدم);
        }
    }
}

صحيح backtrace_func(
    فراغ *ud,
    فراغ *pc,
    ثابت حرف *file,
    صحيح سٽ,
    ثابت حرف *func,
    ثابت حرف *نياپو)
{
#إذا 0
    لکو("\n  *** %p %s %s:%d in '%s'",
        pc,
        نياپو ? "at" : "by",
        file ? file : "?",
        سٽ,
        func ? func : "?");
    أرجع 1; // want more backtrace levels
#وإلا
    //printf(" [%d]", *(int*)ud);
    لکو("!");
    أرجع 0; // cancel backtrace
#جيڪڏهن_پورو
}

TCCState *new_state(صحيح w)
{
    TCCState *s = tcc_new();
    إذا (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        ٻاهر_نڪرو(1);
    }
    tcc_سيٽ_error_func(s, stdout, handle_error);
    parse_دليلون(s);
    إذا (0 == (w & 1))
        tcc_سيٽ_options(s, "-w");
    إذا (w & 2) {
        tcc_سيٽ_options(s, "-bt");
        tcc_define_نشان(s, "N_CRASH", str(M/2));
    } وإلا
        tcc_define_نشان(s, "N_CRASH", "-1000");
    tcc_سيٽ_output_type(s, TCC_OUTPUT_يادگيري);
    أرجع s;
}

فراغ *reloc_state(TCCState *s, ثابت حرف *entry)
{
    فراغ *func;
    tcc_جوڙيو_نشان(s, "add", جوڙيو);
    tcc_جوڙيو_نشان(s, "printf", لکو);
    إذا (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        أرجع عدم;
    }
    func = tcc_get_نشان(s, entry);
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
        بنانشان a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        إذا (a < M)
            s[a] = new_state(w);
        إذا (b < M)
            إذا (tcc_compile_string(s[b], my_پروگرام) == -1)
                اكسر;
        إذا (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        إذا (d < M && funcs[d]) {
            tcc_سيٽ_backtrace_func(s[d], &d, backtrace_func);
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
    صحيح n = (سائيز_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_پروگرام);
    sleep_ms(1);
    إذا (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_سيٽ_backtrace_func(s, &n, backtrace_func);
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
    صحيح n = (سائيز_t)vn;
    حرف *argv[30], b[10];
    صحيح argc = 0, i;

    sprintf(b, "%d", F(n));

    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#إذا 0
    argv[argc++] = "-run";
    لكل (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#جيڪڏهن_پورو
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = عدم;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_جوڙيو_file(s, argv[0]);
    sleep_ms(3);
    إذا (ret == 0)
        tcc_لاڳيتو(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    أرجع 0;
}

فراغ وقت_tcc(صحيح n, ثابت حرف *src)
{
    TCCState *s;
    صحيح ret, i = 0;
    طالما (i++ < n) {
        s = new_state(1);
        لکو(" %d", i), fflush(stdout);
        ret = tcc_جوڙيو_file(s, src);
        tcc_delete(s);
        إذا (ret < 0)
            ٻاهر_نڪرو(1);
    }
}

ساكن بنانشان getclock_ms(فراغ)
{
#جيڪڏهن_وصف_ٿيل _WIN32
    أرجع Get_Tick_ڳڻپ();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#جيڪڏهن_پورو
}

صحيح مکيه(صحيح argc, حرف **argv)
{
    صحيح n;
    بنانشان t;

    g_argc = argc;
    g_argv = argv;

    إذا (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        أرجع 1;
    }

#إذا 1
    لکو("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    لکو("\n (%u ms)\n", getclock_ms() - t);
#جيڪڏهن_پورو
#إذا 1
    لکو("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    لکو("\n (%u ms)\n", getclock_ms() - t);
#جيڪڏهن_پورو
#إذا 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    لکو("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_ڌاڳا(n);
    لکو("\n (%u ms)\n", getclock_ms() - t);
        //}}
#جيڪڏهن_پورو
#إذا 1
    لکو("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    لكل (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_ڌاڳا(n);
    لکو("\n (%u ms)\n", getclock_ms() - t);
#جيڪڏهن_پورو
#إذا 1
    لکو("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    وقت_tcc(10, argv[1]);
    لکو("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#جيڪڏهن_پورو
    أرجع 0;
}

#وإلا
#ضمن <tcclib.h>
#جيڪڏهن_وصف_ٿيل _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    فراغ Sleep(بنانشان);
# define sleep_ms Sleep
#وإلا
    صحيح usleep(بنانشان ڊگهو);
# define sleep_ms(x) usleep((x)*1000);
#جيڪڏهن_پورو

صحيح fib(n)
{
    أرجع (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

صحيح مکيه(صحيح argc, حرف **argv)
{
    sleep_ms(333);
    لکو(" %d", fib(atoi(argv[1])));
    أرجع 0;
}
#جيڪڏهن_پورو
