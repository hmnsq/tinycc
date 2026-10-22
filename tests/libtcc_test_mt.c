/*
 * Multi-thread Test for libtcc
 */

#यदि_अपरिभाषितम् FIB
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#अन्तर्भाव "libtcc.h"

#परिभाषय M 20 /* number of states */
#परिभाषय F(n) (n % 20 + 2) /* fib argument */

#यदि_परिभाषितम् _WIN32
#अन्तर्भाव <windows.h>
#परिभाषय TF_TYPE(func, param) DWORD WINAPI func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    DWORD tid;
    hh[n] = CreateThread(रिक्त, 0, f, (शून्य*)(आकार_t)n, 0, &tid);
}
शून्य wait_तन्तवः(पूर्णाङ्क n)
{
    Wait_For_गुणजः_Objects(n, hh, TRUE, INFINITE);
    यावत् (n)
        CloseHandle(hh[--n]);
}
शून्य sleep_ms(अचिह्नित n)
{
    Sleep(n);
}
#अन्यथा
#अन्तर्भाव <sys/time.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <pthread.h>
#परिभाषय TF_TYPE(func, param) शून्य* func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    pthread_create(&hh[n], रिक्त, f, (शून्य*)(आकार_t)n);
}
शून्य wait_तन्तवः(पूर्णाङ्क n)
{
    यावत् (n)
        pthread_join(hh[--n], रिक्त);

}
शून्य sleep_ms(अचिह्नित n)
{
    usleep(n * 1000);
}
#यदि_अन्तः

शून्य handle_error(शून्य *opaque, ध्रुव वर्ण *सन्देशः)
{
    fprintf(opaque, "%s\n", सन्देशः);
}

/* this function is called by the generated code */
पूर्णाङ्क सङ्कलय(पूर्णाङ्क a, पूर्णाङ्क b)
{
    प्रत्यागम a + b;
}

#परिभाषय _str(s) #s
#परिभाषय str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#परिभाषय PROG(lbl) \
    वर्ण lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

PROG(my_क्रमादेशः)
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

पूर्णाङ्क g_argc; वर्ण **g_argv;

शून्य parse_तर्काः(TCCState *s)
{
    पूर्णाङ्क i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    प्रति (i = 1; i < g_argc; ++i) {
        वर्ण *a = g_argv[i];
        यदि (a[0] == '-') {
            यदि (a[1] == 'B')
                tcc_समुच्चयः_lib_मार्गः(s, a+2);
            अन्यथा यदि (a[1] == 'I')
                tcc_सङ्कलय_include_मार्गः(s, a+2);
            अन्यथा यदि (a[1] == 'L')
                tcc_सङ्कलय_library_मार्गः(s, a+2);
            अन्यथा यदि (a[1] == 'D')
                tcc_define_चिह्नम्(s, a+2, रिक्त);
        }
    }
}

पूर्णाङ्क backtrace_func(
    शून्य *ud,
    शून्य *pc,
    ध्रुव वर्ण *file,
    पूर्णाङ्क पङ्क्तिः,
    ध्रुव वर्ण *func,
    ध्रुव वर्ण *सन्देशः)
{
#यदि 0
    प्रारूप_लिख("\n  *** %p %s %s:%d in '%s'",
        pc,
        सन्देशः ? "at" : "by",
        file ? file : "?",
        पङ्क्तिः,
        func ? func : "?");
    प्रत्यागम 1; // want more backtrace levels
#अन्यथा
    //printf(" [%d]", *(int*)ud);
    प्रारूप_लिख("!");
    प्रत्यागम 0; // cancel backtrace
#यदि_अन्तः
}

TCCState *new_state(पूर्णाङ्क w)
{
    TCCState *s = tcc_new();
    यदि (!s) {
        fprintf(stderr, __FILE__ ": could not create tcc state\n");
        निर्गच्छ(1);
    }
    tcc_समुच्चयः_error_func(s, stdout, handle_error);
    parse_तर्काः(s);
    यदि (0 == (w & 1))
        tcc_समुच्चयः_options(s, "-w");
    यदि (w & 2) {
        tcc_समुच्चयः_options(s, "-bt");
        tcc_define_चिह्नम्(s, "N_CRASH", str(M/2));
    } अन्यथा
        tcc_define_चिह्नम्(s, "N_CRASH", "-1000");
    tcc_समुच्चयः_output_type(s, TCC_OUTPUT_स्मृतिः);
    प्रत्यागम s;
}

शून्य *reloc_state(TCCState *s, ध्रुव वर्ण *entry)
{
    शून्य *func;
    tcc_सङ्कलय_चिह्नम्(s, "add", सङ्कलय);
    tcc_सङ्कलय_चिह्नम्(s, "printf", प्रारूप_लिख);
    यदि (tcc_relocate(s) < 0) {
        fprintf(stderr, __FILE__ ": could not relocate tcc state.\n");
        प्रत्यागम रिक्त;
    }
    func = tcc_get_चिह्नम्(s, entry);
    यदि (!func)
        fprintf(stderr, __FILE__ ": could not get entry symbol.\n");
    प्रत्यागम func;
}

/* work with several states at the same time */
पूर्णाङ्क state_test(पूर्णाङ्क w)
{
    TCCState *s[M];
    पूर्णाङ्क (*funcs[M])(पूर्णाङ्क);
    पूर्णाङ्क n;
    jmp_buf jb;

    प्रति (n = 0; n < M + 4; ++n) {
        अचिह्नित a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        यदि (a < M)
            s[a] = new_state(w);
        यदि (b < M)
            यदि (tcc_compile_string(s[b], my_क्रमादेशः) == -1)
                भङ्ग;
        यदि (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        यदि (d < M && funcs[d]) {
            tcc_समुच्चयः_backtrace_func(s[d], &d, backtrace_func);
            यदि (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        यदि (e < M)
            tcc_delete(s[e]);
    }
    प्रत्यागम 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    पूर्णाङ्क (*func)(पूर्णाङ्क);
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (आकार_t)vn;
    jmp_buf jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_क्रमादेशः);
    sleep_ms(1);
    यदि (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_समुच्चयः_backtrace_func(s, &n, backtrace_func);
        यदि (func) {
            यदि (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    प्रत्यागम 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (आकार_t)vn;
    वर्ण *argv[30], b[10];
    पूर्णाङ्क argc = 0, i;

    sprintf(b, "%d", F(n));

    प्रति (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#यदि 0
    argv[argc++] = "-run";
    प्रति (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#यदि_अन्तः
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = रिक्त;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_सङ्कलय_file(s, argv[0]);
    sleep_ms(3);
    यदि (ret == 0)
        tcc_सततम्(s, argc, argv);
    tcc_delete(s);
    fflush(stdout);
    प्रत्यागम 0;
}

शून्य time_tcc(पूर्णाङ्क n, ध्रुव वर्ण *src)
{
    TCCState *s;
    पूर्णाङ्क ret, i = 0;
    यावत् (i++ < n) {
        s = new_state(1);
        प्रारूप_लिख(" %d", i), fflush(stdout);
        ret = tcc_सङ्कलय_file(s, src);
        tcc_delete(s);
        यदि (ret < 0)
            निर्गच्छ(1);
    }
}

स्थिर अचिह्नित getclock_ms(शून्य)
{
#यदि_परिभाषितम् _WIN32
    प्रत्यागम Get_Tick_गणनम्();
#अन्यथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    प्रत्यागम tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#यदि_अन्तः
}

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क n;
    अचिह्नित t;

    g_argc = argc;
    g_argv = argv;

    यदि (argc < 2) {
        fprintf(stderr, "usage: libtcc_test_mt tcc.c <options>\n");
        प्रत्यागम 1;
    }

#यदि 1
    प्रारूप_लिख("running fib with mixed calls\n "), fflush(stdout);
    t = getclock_ms();
    state_test(0);
    प्रारूप_लिख("\n (%u ms)\n", getclock_ms() - t);
#यदि_अन्तः
#यदि 1
    प्रारूप_लिख("producing some exceptions (!)\n "), fflush(stdout);
    t = getclock_ms();
    state_test(2);
    प्रारूप_लिख("\n (%u ms)\n", getclock_ms() - t);
#यदि_अन्तः
#यदि 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    प्रारूप_लिख("running fib in threads\n "), fflush(stdout);
    t = getclock_ms();
    प्रति (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_तन्तवः(n);
    प्रारूप_लिख("\n (%u ms)\n", getclock_ms() - t);
        //}}
#यदि_अन्तः
#यदि 1
    प्रारूप_लिख("running tcc.c in threads to run fib\n "), fflush(stdout);
    t = getclock_ms();
    प्रति (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_तन्तवः(n);
    प्रारूप_लिख("\n (%u ms)\n", getclock_ms() - t);
#यदि_अन्तः
#यदि 1
    प्रारूप_लिख("compiling tcc.c 10 times\n "), fflush(stdout);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    प्रारूप_लिख("\n (%u ms)\n", getclock_ms() - t), fflush(stdout);
#यदि_अन्तः
    प्रत्यागम 0;
}

#अन्यथा
#अन्तर्भाव <tcclib.h>
#यदि_परिभाषितम् _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    शून्य Sleep(अचिह्नित);
# define sleep_ms Sleep
#अन्यथा
    पूर्णाङ्क usleep(अचिह्नित दीर्घ);
# define sleep_ms(x) usleep((x)*1000);
#यदि_अन्तः

पूर्णाङ्क fib(n)
{
    प्रत्यागम (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    sleep_ms(333);
    प्रारूप_लिख(" %d", fib(atoi(argv[1])));
    प्रत्यागम 0;
}
#यदि_अन्तः
