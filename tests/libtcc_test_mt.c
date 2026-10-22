/*
 * Multi-thread Test for libtcc
 */

#నిర్వచితం_కాకపోతే FIB
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <setjmp.h>
#అన్తర్భావ "libtcc.h"

#నిర్వచించు M 20 /* number of states */
#నిర్వచించు F(n) (n % 20 + 2) /* fib argument */

#నిర్వచితమైతే _WIN32
#అన్తర్భావ <windows.h>
#నిర్వచించు TF_TYPE(func, param) DWORD WINAPI func(శూన్య *param)
రకనిర్వచనం TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
శూన్య create_thread(ThreadFunc f, పూర్ణాంకం n)
{
    DWORD tid;
    hh[n] = CreateThread(ఖాళీ, 0, f, (శూన్య*)(కొలత_t)n, 0, &tid);
}
శూన్య wait_దారాలు(పూర్ణాంకం n)
{
    Wait_For_గుణిజం_Objects(n, hh, TRUE, INFINITE);
    అయితే (n)
        CloseHandle(hh[--n]);
}
శూన్య sleep_ms(గుర్తులేని n)
{
    Sleep(n);
}
#లేకపోతే
#అన్తర్భావ <sys/time.h>
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <pthread.h>
#నిర్వచించు TF_TYPE(func, param) శూన్య* func(శూన్య *param)
రకనిర్వచనం TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
శూన్య create_thread(ThreadFunc f, పూర్ణాంకం n)
{
    pthread_create(&hh[n], ఖాళీ, f, (శూన్య*)(కొలత_t)n);
}
శూన్య wait_దారాలు(పూర్ణాంకం n)
{
    అయితే (n)
        pthread_join(hh[--n], ఖాళీ);

}
శూన్య sleep_ms(గుర్తులేని n)
{
    usleep(n * 1000);
}
#అయితే_ముగింపు

శూన్య handle_error(శూన్య *opaque, స్థిరరాశి అక్షరం *సందేశం)
{
    fprintf(opaque, "%s\n", సందేశం);
}

/* this function is called by the generated code */
పూర్ణాంకం కూడు(పూర్ణాంకం a, పూర్ణాంకం b)
{
    తిరిగి a + b;
}

#నిర్వచించు _str(s) #s
#నిర్వచించు str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#నిర్వచించు PROG(lbl) \
    అక్షరం lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_కార్యక్రమం)
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

పూర్ణాంకం g_argc; అక్షరం **g_argv;

శూన్య parse_వాదనలు(TCCState *s)
{
    పూర్ణాంకం i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    కొరకు (i = 1; i < g_argc; ++i) {
        అక్షరం *a = g_argv[i];
        ఒకవేళ (a[0] == '-') {
            ఒకవేళ (a[1] == 'B')
                tcc_సమితి_lib_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'I')
                tcc_కూడు_include_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'L')
                tcc_కూడు_library_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'D')
                tcc_define_చిహ్నం(s, a+2, ఖాళీ);
        }
    }
}

పూర్ణాంకం backtrace_func(
    శూన్య *ud,
    శూన్య *pc,
    స్థిరరాశి అక్షరం *file,
    పూర్ణాంకం పంక్తి,
    స్థిరరాశి అక్షరం *func,
    స్థిరరాశి అక్షరం *సందేశం)
{
#ఒకవేళ 0
    రాయి("\n  *** %p %s %s:%d in '%s'",
        pc,
        సందేశం ? "at" : "by",
        file ? file : "?",
        పంక్తి,
        func ? func : "?");
    తిరిగి 1; // want more backtrace levels
#లేకపోతే
    //printf(" [%d]", *(int*)ud);
    రాయి("!");
    తిరిగి 0; // cancel backtrace
#అయితే_ముగింపు
}

TCCState *new_state(పూర్ణాంకం w)
{
    TCCState *s = tcc_new();
    ఒకవేళ (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        నిష్క్రమించు(1);
    }
    tcc_సమితి_error_func(s, stdout, handle_error);
    parse_వాదనలు(s);
    ఒకవేళ (0 == (w & 1))
        tcc_సమితి_options(s, "-w");
    ఒకవేళ (w & 2) {
        tcc_సమితి_options(s, "-bt");
        tcc_define_చిహ్నం(s, "N_CRASH", str(M/2));
    } లేకపోతే
        tcc_define_చిహ్నం(s, "N_CRASH", "-1000");
    tcc_సమితి_output_type(s, TCC_OUTPUT_జ్ఞాపకం);
    తిరిగి s;
}

శూన్య *reloc_state(TCCState *s, స్థిరరాశి అక్షరం *entry)
{
    శూన్య *func;
    tcc_కూడు_చిహ్నం(s, "add", కూడు);
    tcc_కూడు_చిహ్నం(s, "printf", రాయి);
    ఒకవేళ (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        తిరిగి ఖాళీ;
    }
    func = tcc_get_చిహ్నం(s, entry);
    ఒకవేళ (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    తిరిగి func;
}

/* work with several states at the same time */
పూర్ణాంకం state_test(పూర్ణాంకం w)
{
    TCCState *s[M];
    పూర్ణాంకం (*funcs[M])(పూర్ణాంకం);
    పూర్ణాంకం n;
    jmp_buf jb;

    కొరకు (n = 0; n < M + 4; ++n) {
        గుర్తులేని a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        ఒకవేళ (a < M)
            s[a] = new_state(w);
        ఒకవేళ (b < M)
            ఒకవేళ (tcc_compile_string(s[b], my_కార్యక్రమం) == -1)
                ఆపు;
        ఒకవేళ (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        ఒకవేళ (d < M && funcs[d]) {
            tcc_సమితి_backtrace_func(s[d], &d, backtrace_func);
            ఒకవేళ (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        ఒకవేళ (e < M)
            tcc_delete(s[e]);
    }
    తిరిగి 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    పూర్ణాంకం (*func)(పూర్ణాంకం);
    పూర్ణాంకం ret;
    పూర్ణాంకం n = (కొలత_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_కార్యక్రమం);
    sleep_ms(1);
    ఒకవేళ (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_సమితి_backtrace_func(s, &n, backtrace_func);
        ఒకవేళ (func) {
            ఒకవేళ (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    తిరిగి 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    పూర్ణాంకం ret;
    పూర్ణాంకం n = (కొలత_t)vn;
    అక్షరం *argv[30], b[10];
    పూర్ణాంకం argc = 0, i;

    sprintf(b, "%d", F(n));

    కొరకు (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#ఒకవేళ 0
    argv[argc++] = "-run";
    కొరకు (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#అయితే_ముగింపు
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ఖాళీ;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_కూడు_file(s, argv[0]);
    sleep_ms(3);
    ఒకవేళ (ret == 0)
        tcc_నిరంతరం(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    తిరిగి 0;
}

శూన్య సమయం_tcc(పూర్ణాంకం n, స్థిరరాశి అక్షరం *src)
{
    TCCState *s;
    పూర్ణాంకం ret, i = 0;
    అయితే (i++ < n) {
        s = new_state(1);
        రాయి(" %d", i), fflush(stdout);
        ret = tcc_కూడు_file(s, src);
        tcc_delete(s);
        ఒకవేళ (ret < 0)
            నిష్క్రమించు(1);
    }
}

స్థిర గుర్తులేని getclock_ms(శూన్య)
{
#నిర్వచితమైతే _WIN32
    తిరిగి Get_Tick_లెక్క();
#లేకపోతే
    నిర్మాణం timeval tv;
    gettimeofday(&tv, ఖాళీ);
    తిరిగి tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#అయితే_ముగింపు
}

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    పూర్ణాంకం n;
    గుర్తులేని t;

    g_argc = argc;
    g_argv = argv;

    ఒకవేళ (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        తిరిగి 1;
    }

#ఒకవేళ 1
    రాయి("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    రాయి("\n (%u ms)\n", getclock_ms() - t);
#అయితే_ముగింపు
#ఒకవేళ 1
    రాయి("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    రాయి("\n (%u ms)\n", getclock_ms() - t);
#అయితే_ముగింపు
#ఒకవేళ 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    రాయి("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    కొరకు (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_దారాలు(n);
    రాయి("\n (%u ms)\n", getclock_ms() - t);
        //}}
#అయితే_ముగింపు
#ఒకవేళ 1
    రాయి("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    కొరకు (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_దారాలు(n);
    రాయి("\n (%u ms)\n", getclock_ms() - t);
#అయితే_ముగింపు
#ఒకవేళ 1
    రాయి("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    సమయం_tcc(10, argv[1]);
    రాయి("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#అయితే_ముగింపు
    తిరిగి 0;
}

#లేకపోతే
#అన్తర్భావ <tcclib.h>
#నిర్వచితమైతే _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    శూన్య Sleep(గుర్తులేని);
# define sleep_ms Sleep
#లేకపోతే
    పూర్ణాంకం usleep(గుర్తులేని దీర్ఘ);
# define sleep_ms(x) usleep((x)*1000);
#అయితే_ముగింపు

పూర్ణాంకం fib(n)
{
    తిరిగి (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    sleep_ms(333);
    రాయి(" %d", fib(atoi(argv[1])));
    తిరిగి 0;
}
#అయితే_ముగింపు
