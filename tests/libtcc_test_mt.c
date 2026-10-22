/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <setjmp.h>
#அந்தர்பாவ "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#அந்தர்பாவ <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(வெறுமை *param)
வகைவரை TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
வெறுமை create_thread(ThreadFunc f, முழு n)
{
    DWORD tid;
    hh[n] = CreateThread(வெற்று, 0, f, (வெறுமை*)(size_t)n, 0, &tid);
}
வெறுமை wait_threads(முழு n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    போது (n)
        CloseHandle(hh[--n]);
}
வெறுமை sleep_ms(unsigned n)
{
    Sleep(n);
}
#இல்லையெனில்
#அந்தர்பாவ <sys/time.h>
#அந்தர்பாவ <unistd.h>
#அந்தர்பாவ <pthread.h>
#define TF_TYPE(func, param) வெறுமை* func(வெறுமை *param)
வகைவரை TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
வெறுமை create_thread(ThreadFunc f, முழு n)
{
    pthread_create(&hh[n], வெற்று, f, (வெறுமை*)(size_t)n);
}
வெறுமை wait_threads(முழு n)
{
    போது (n)
        pthread_join(hh[--n], வெற்று);

}
வெறுமை sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

வெறுமை handle_error(வெறுமை *opaque, மாறிலி எழுத்து *செய்தி)
{
    fprintf(opaque, "%s\n", செய்தி);
}

/* this function is called by the generated code */
முழு add(முழு a, முழு b)
{
    திரும்பு a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    எழுத்து lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

முழு g_argc; எழுத்து **g_argv;

வெறுமை parse_args(TCCState *s)
{
    முழு i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    க்கு (i = 1; i < g_argc; ++i) {
        எழுத்து *a = g_argv[i];
        எனில் (a[0] == '-') {
            எனில் (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            இல்லையெனில் எனில் (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            இல்லையெனில் எனில் (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            இல்லையெனில் எனில் (a[1] == 'D')
                tcc_define_குறியீடு(s, a+2, வெற்று);
        }
    }
}

முழு backtrace_func(
    வெறுமை *ud,
    வெறுமை *pc,
    மாறிலி எழுத்து *file,
    முழு வரி,
    மாறிலி எழுத்து *func,
    மாறிலி எழுத்து *செய்தி)
{
#எனில் 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        செய்தி ? "at" : "by",
        file ? file : "?",
        வரி,
        func ? func : "?");
    திரும்பு 1; // want more backtrace levels
#இல்லையெனில்
    //printf(" [%d]", *(int*)ud);
    printf("!");
    திரும்பு 0; // cancel backtrace
#endif
}

TCCState *new_state(முழு w)
{
    TCCState *s = tcc_new();
    எனில் (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    எனில் (0 == (w & 1))
        tcc_set_options(s, "-w");
    எனில் (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_குறியீடு(s, "N_CRASH", str(M/2));
    } இல்லையெனில்
        tcc_define_குறியீடு(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    திரும்பு s;
}

வெறுமை *reloc_state(TCCState *s, மாறிலி எழுத்து *entry)
{
    வெறுமை *func;
    tcc_add_குறியீடு(s, "add", add);
    tcc_add_குறியீடு(s, "printf", printf);
    எனில் (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        திரும்பு வெற்று;
    }
    func = tcc_get_குறியீடு(s, entry);
    எனில் (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    திரும்பு func;
}

/* work with several states at the same time */
முழு state_test(முழு w)
{
    TCCState *s[M];
    முழு (*funcs[M])(முழு);
    முழு n;
    jmp_buf jb;

    க்கு (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        எனில் (a < M)
            s[a] = new_state(w);
        எனில் (b < M)
            எனில் (tcc_compile_string(s[b], my_program) == -1)
                நிறுத்து;
        எனில் (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        எனில் (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            எனில் (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        எனில் (e < M)
            tcc_delete(s[e]);
    }
    திரும்பு 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    முழு (*func)(முழு);
    முழு ret;
    முழு n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    எனில் (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        எனில் (func) {
            எனில் (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    திரும்பு 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    முழு ret;
    முழு n = (size_t)vn;
    எழுத்து *argv[30], b[10];
    முழு argc = 0, i;

    sprintf(b, "%d", F(n));

    க்கு (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#எனில் 0
    argv[argc++] = "-run";
    க்கு (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = வெற்று;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    எனில் (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    திரும்பு 0;
}

வெறுமை time_tcc(முழு n, மாறிலி எழுத்து *src)
{
    TCCState *s;
    முழு ret, i = 0;
    போது (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        எனில் (ret < 0)
            exit(1);
    }
}

நிலையான unsigned getclock_ms(வெறுமை)
{
#ifdef _WIN32
    திரும்பு Get_Tick_மொத்தம்();
#இல்லையெனில்
    கட்டமைப்பு timeval tv;
    gettimeofday(&tv, வெற்று);
    திரும்பு tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    முழு n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    எனில் (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        திரும்பு 1;
    }

#எனில் 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#எனில் 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#எனில் 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    க்கு (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#எனில் 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    க்கு (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#எனில் 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    திரும்பு 0;
}

#இல்லையெனில்
#அந்தர்பாவ <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    வெறுமை Sleep(unsigned);
# define sleep_ms Sleep
#இல்லையெனில்
    முழு usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

முழு fib(n)
{
    திரும்பு (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    திரும்பு 0;
}
#endif
