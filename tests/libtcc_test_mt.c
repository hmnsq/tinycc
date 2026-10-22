/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <setjmp.h>
#અન્તર્ભાવ "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#અન્તર્ભાવ <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(શૂન્ય *param)
પ્રકારવ્યાખ્યા TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
શૂન્ય create_thread(ThreadFunc f, પૂર્ણાંક n)
{
    DWORD tid;
    hh[n] = CreateThread(ખાલી, 0, f, (શૂન્ય*)(size_t)n, 0, &tid);
}
શૂન્ય wait_threads(પૂર્ણાંક n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    જ્યારે (n)
        CloseHandle(hh[--n]);
}
શૂન્ય sleep_ms(unsigned n)
{
    Sleep(n);
}
#નહીંતર
#અન્તર્ભાવ <sys/time.h>
#અન્તર્ભાવ <unistd.h>
#અન્તર્ભાવ <pthread.h>
#define TF_TYPE(func, param) શૂન્ય* func(શૂન્ય *param)
પ્રકારવ્યાખ્યા TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
શૂન્ય create_thread(ThreadFunc f, પૂર્ણાંક n)
{
    pthread_create(&hh[n], ખાલી, f, (શૂન્ય*)(size_t)n);
}
શૂન્ય wait_threads(પૂર્ણાંક n)
{
    જ્યારે (n)
        pthread_join(hh[--n], ખાલી);

}
શૂન્ય sleep_ms(unsigned n)
{
    usleep(n * 1000);
}
#endif

શૂન્ય handle_error(શૂન્ય *opaque, અચલ અક્ષર *સંદેશ)
{
    fprintf(opaque, "%s\n", સંદેશ);
}

/* this function is called by the generated code */
પૂર્ણાંક add(પૂર્ણાંક a, પૂર્ણાંક b)
{
    પાછા a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    અક્ષર lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

પૂર્ણાંક g_argc; અક્ષર **g_argv;

શૂન્ય parse_args(TCCState *s)
{
    પૂર્ણાંક i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    માટે (i = 1; i < g_argc; ++i) {
        અક્ષર *a = g_argv[i];
        જો (a[0] == '-') {
            જો (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            નહીંતર જો (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            નહીંતર જો (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            નહીંતર જો (a[1] == 'D')
                tcc_define_પ્રતીક(s, a+2, ખાલી);
        }
    }
}

પૂર્ણાંક backtrace_func(
    શૂન્ય *ud,
    શૂન્ય *pc,
    અચલ અક્ષર *file,
    પૂર્ણાંક લીટી,
    અચલ અક્ષર *func,
    અચલ અક્ષર *સંદેશ)
{
#જો 0
    printf("\n  *** %p %s %s:%d in '%s'",
        pc,
        સંદેશ ? "at" : "by",
        file ? file : "?",
        લીટી,
        func ? func : "?");
    પાછા 1; // want more backtrace levels
#નહીંતર
    //printf(" [%d]", *(int*)ud);
    printf("!");
    પાછા 0; // cancel backtrace
#endif
}

TCCState *new_state(પૂર્ણાંક w)
{
    TCCState *s = tcc_new();
    જો (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        exit(1);
    }
    tcc_set_error_func(s, stdout, handle_error);
    parse_args(s);
    જો (0 == (w & 1))
        tcc_set_options(s, "-w");
    જો (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_પ્રતીક(s, "N_CRASH", str(M/2));
    } નહીંતર
        tcc_define_પ્રતીક(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    પાછા s;
}

શૂન્ય *reloc_state(TCCState *s, અચલ અક્ષર *entry)
{
    શૂન્ય *func;
    tcc_add_પ્રતીક(s, "add", add);
    tcc_add_પ્રતીક(s, "printf", printf);
    જો (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        પાછા ખાલી;
    }
    func = tcc_get_પ્રતીક(s, entry);
    જો (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    પાછા func;
}

/* work with several states at the same time */
પૂર્ણાંક state_test(પૂર્ણાંક w)
{
    TCCState *s[M];
    પૂર્ણાંક (*funcs[M])(પૂર્ણાંક);
    પૂર્ણાંક n;
    jmp_buf jb;

    માટે (n = 0; n < M + 4; ++n) {
        unsigned a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        જો (a < M)
            s[a] = new_state(w);
        જો (b < M)
            જો (tcc_compile_string(s[b], my_program) == -1)
                તોડો;
        જો (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        જો (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            જો (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        જો (e < M)
            tcc_delete(s[e]);
    }
    પાછા 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    પૂર્ણાંક (*func)(પૂર્ણાંક);
    પૂર્ણાંક ret;
    પૂર્ણાંક n = (size_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    જો (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        જો (func) {
            જો (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    પાછા 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    પૂર્ણાંક ret;
    પૂર્ણાંક n = (size_t)vn;
    અક્ષર *argv[30], b[10];
    પૂર્ણાંક argc = 0, i;

    sprintf(b, "%d", F(n));

    માટે (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#જો 0
    argv[argc++] = "-run";
    માટે (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = ખાલી;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    જો (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    પાછા 0;
}

શૂન્ય time_tcc(પૂર્ણાંક n, અચલ અક્ષર *src)
{
    TCCState *s;
    પૂર્ણાંક ret, i = 0;
    જ્યારે (i++ < n) {
        s = new_state(1);
        printf(" %d", i), fflush(stdout);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        જો (ret < 0)
            exit(1);
    }
}

સ્થિર unsigned getclock_ms(શૂન્ય)
{
#ifdef _WIN32
    પાછા Get_Tick_ગણતરી();
#નહીંતર
    સંરચના timeval tv;
    gettimeofday(&tv, ખાલી);
    પાછા tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક n;
    unsigned t;

    g_argc = argc;
    g_argv = argv;

    જો (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        પાછા 1;
    }

#જો 1
    printf("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#જો 1
    printf("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#જો 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    printf("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    માટે (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#જો 1
    printf("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    માટે (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    printf("\n (%u ms)\n", getclock_ms() - t);
#endif
#જો 1
    printf("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    printf("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#endif
    પાછા 0;
}

#નહીંતર
#અન્તર્ભાવ <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    શૂન્ય Sleep(unsigned);
# define sleep_ms Sleep
#નહીંતર
    પૂર્ણાંક usleep(unsigned long);
# define sleep_ms(x) usleep((x)*1000);
#endif

પૂર્ણાંક fib(n)
{
    પાછા (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    sleep_ms(333);
    printf(" %d", fib(atoi(argv[1])));
    પાછા 0;
}
#endif
