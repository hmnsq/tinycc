/*
 * Multi-thread Test for libtcc
 */

#ifndef FIB
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#अन्तर्भाव "libtcc.h"

#define M 20 /* number of states */
#define F(n) (n % 20 + 2) /* fib argument */

#ifdef _WIN32
#अन्तर्भाव <windows.h>
#define TF_TYPE(func, param) DWORD WINAPI func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
HANDLE hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    DWORD tid;
    hh[n] = CreateThread(रिक्त, 0, f, (शून्य*)(माप_प्रकार)n, 0, &tid);
}
शून्य wait_threads(पूर्णाङ्क n)
{
    WaitForMultipleObjects(n, hh, TRUE, INFINITE);
    जबसम्म (n)
        CloseHandle(hh[--n]);
}
शून्य sleep_ms(अचिन्हित n)
{
    Sleep(n);
}
#अन्यथा
#अन्तर्भाव <sys/time.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <pthread.h>
#define TF_TYPE(func, param) शून्य* func(शून्य *param)
प्रकारनिर्देश TF_TYPE(ThreadFunc, x);
pthread_t hh[M];
शून्य create_thread(ThreadFunc f, पूर्णाङ्क n)
{
    pthread_create(&hh[n], रिक्त, f, (शून्य*)(माप_प्रकार)n);
}
शून्य wait_threads(पूर्णाङ्क n)
{
    जबसम्म (n)
        pthread_join(hh[--n], रिक्त);

}
शून्य sleep_ms(अचिन्हित n)
{
    usleep(n * 1000);
}
#endif

शून्य handle_error(शून्य *opaque, अचर वर्ण *सन्देश)
{
    ख_लिखो(opaque, "%s\n", सन्देश);
}

/* this function is called by the generated code */
पूर्णाङ्क add(पूर्णाङ्क a, पूर्णाङ्क b)
{
    फर्काऊ a + b;
}

#define _str(s) #s
#define str(s) _str(s)
/* as a trick, prepend #line directive for better error/warning messages */
#define PROG(lbl) \
    वर्ण lbl[] = "#line " str(__LINE__) " " str(__FILE__) "\n\n"

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

पूर्णाङ्क g_argc; वर्ण **g_argv;

शून्य parse_args(TCCState *s)
{
    पूर्णाङ्क i;
    /* if tcclib.h and libtcc1.a are not installed, where can we find them */
    लागि (i = 1; i < g_argc; ++i) {
        वर्ण *a = g_argv[i];
        यदि (a[0] == '-') {
            यदि (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            अन्यथा यदि (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            अन्यथा यदि (a[1] == 'L')
                tcc_add_library_path(s, a+2);
            अन्यथा यदि (a[1] == 'D')
                tcc_define_चिह्न(s, a+2, रिक्त);
        }
    }
}

पूर्णाङ्क backtrace_func(
    शून्य *ud,
    शून्य *pc,
    अचर वर्ण *file,
    पूर्णाङ्क पङ्क्ति,
    अचर वर्ण *func,
    अचर वर्ण *सन्देश)
{
#यदि 0
    म_लिखो("\n  *** %p %s %s:%d in '%s'",
        pc,
        सन्देश ? "at" : "by",
        file ? file : "?",
        पङ्क्ति,
        func ? func : "?");
    फर्काऊ 1; // want more backtrace levels
#अन्यथा
    //printf(" [%d]", *(int*)ud);
    म_लिखो("!");
    फर्काऊ 0; // cancel backtrace
#endif
}

TCCState *new_state(पूर्णाङ्क w)
{
    TCCState *s = tcc_new();
    यदि (!s) {
        ख_लिखो(मानक_त्रुटि, __FILE__ ": could not create tcc state\n");
        निकास(1);
    }
    tcc_set_error_func(s, मानक_निकास, handle_error);
    parse_args(s);
    यदि (0 == (w & 1))
        tcc_set_options(s, "-w");
    यदि (w & 2) {
        tcc_set_options(s, "-bt");
        tcc_define_चिह्न(s, "N_CRASH", str(M/2));
    } अन्यथा
        tcc_define_चिह्न(s, "N_CRASH", "-1000");
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);
    फर्काऊ s;
}

शून्य *reloc_state(TCCState *s, अचर वर्ण *entry)
{
    शून्य *func;
    tcc_add_चिह्न(s, "add", add);
    tcc_add_चिह्न(s, "printf", म_लिखो);
    यदि (tcc_relocate(s) < 0) {
        ख_लिखो(मानक_त्रुटि, __FILE__ ": could not relocate tcc state.\n");
        फर्काऊ रिक्त;
    }
    func = tcc_get_चिह्न(s, entry);
    यदि (!func)
        ख_लिखो(मानक_त्रुटि, __FILE__ ": could not get entry symbol.\n");
    फर्काऊ func;
}

/* work with several states at the same time */
पूर्णाङ्क state_test(पूर्णाङ्क w)
{
    TCCState *s[M];
    पूर्णाङ्क (*funcs[M])(पूर्णाङ्क);
    पूर्णाङ्क n;
    लाँघ_बफ jb;

    लागि (n = 0; n < M + 4; ++n) {
        अचिन्हित a = n, b = n - 1, c = n - 2, d = n - 3, e = n - 4;
        यदि (a < M)
            s[a] = new_state(w);
        यदि (b < M)
            यदि (tcc_compile_string(s[b], my_program) == -1)
                रोक;
        यदि (c < M)
            funcs[c] = reloc_state(s[c], "foo");
        यदि (d < M && funcs[d]) {
            tcc_set_backtrace_func(s[d], &d, backtrace_func);
            यदि (0 == tcc_setjmp(s[d], jb, funcs[d]))
                funcs[d](F(d));
        }
        यदि (e < M)
            tcc_delete(s[e]);
    }
    फर्काऊ 0;
}

/* simple compilation in threads */
TF_TYPE(thread_test_simple, vn)
{
    TCCState *s;
    पूर्णाङ्क (*func)(पूर्णाङ्क);
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (माप_प्रकार)vn;
    लाँघ_बफ jb;

    s = new_state(0); /* '2' for exceptions */
    sleep_ms(1);
    ret = tcc_compile_string(s, my_program);
    sleep_ms(1);
    यदि (ret >= 0) {
        func = reloc_state(s, "foo");
        tcc_set_backtrace_func(s, &n, backtrace_func);
        यदि (func) {
            यदि (0 == tcc_setjmp(s, jb, func))
                func(F(n));
        }
    }
    tcc_delete(s);
    फर्काऊ 0;
}

/* more complex compilation in threads */
TF_TYPE(thread_test_complex, vn)
{
    TCCState *s;
    पूर्णाङ्क ret;
    पूर्णाङ्क n = (माप_प्रकार)vn;
    वर्ण *argv[30], b[10];
    पूर्णाङ्क argc = 0, i;

    प्र_लिखो(b, "%d", F(n));

    लागि (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#यदि 0
    argv[argc++] = "-run";
    लागि (i = 1; i < g_argc; ++i) argv[argc++] = g_argv[i];
#endif
    argv[argc++] = "-DFIB";
    argv[argc++] = "-run";
    argv[argc++] = __FILE__;
    argv[argc++] = b;
    argv[argc] = रिक्त;

    s = new_state(1);
    sleep_ms(2);
    ret = tcc_add_file(s, argv[0]);
    sleep_ms(3);
    यदि (ret == 0)
        tcc_run(s, argc, argv);
    tcc_delete(s);
    ख_साफ(मानक_निकास);
    फर्काऊ 0;
}

शून्य time_tcc(पूर्णाङ्क n, अचर वर्ण *src)
{
    TCCState *s;
    पूर्णाङ्क ret, i = 0;
    जबसम्म (i++ < n) {
        s = new_state(1);
        म_लिखो(" %d", i), ख_साफ(मानक_निकास);
        ret = tcc_add_file(s, src);
        tcc_delete(s);
        यदि (ret < 0)
            निकास(1);
    }
}

स्थिर अचिन्हित getclock_ms(शून्य)
{
#ifdef _WIN32
    फर्काऊ Get_Tick_गन्ती();
#अन्यथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    फर्काऊ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क n;
    अचिन्हित t;

    g_argc = argc;
    g_argv = argv;

    यदि (argc < 2) {
        ख_लिखो(मानक_त्रुटि, "usage: libtcc_test_mt tcc.c <options>\n");
        फर्काऊ 1;
    }

#यदि 1
    म_लिखो("running fib with mixed calls\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    state_test(0);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#endif
#यदि 1
    म_लिखो("producing some exceptions (!)\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    state_test(2);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#endif
#यदि 1
    //{ int i; for (i = 0; i < 100; ++i) { printf("(%d) ", i);
    म_लिखो("running fib in threads\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    लागि (n = 0; n < M; ++n)
        create_thread(thread_test_simple, n);
    wait_threads(n);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
        //}}
#endif
#यदि 1
    म_लिखो("running tcc.c in threads to run fib\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    लागि (n = 0; n < M; ++n)
        create_thread(thread_test_complex, n);
    wait_threads(n);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t);
#endif
#यदि 1
    म_लिखो("compiling tcc.c 10 times\n "), ख_साफ(मानक_निकास);
    t = getclock_ms();
    time_tcc(10, argv[1]);
    म_लिखो("\n (%u ms)\n", getclock_ms() - t), ख_साफ(मानक_निकास);
#endif
    फर्काऊ 0;
}

#अन्यथा
#अन्तर्भाव <tcclib.h>
#ifdef _WIN32
# ifndef _WIN64
    __declspec(stdcall)
# endif
    शून्य Sleep(अचिन्हित);
# define sleep_ms Sleep
#अन्यथा
    पूर्णाङ्क usleep(अचिन्हित दीर्घ);
# define sleep_ms(x) usleep((x)*1000);
#endif

पूर्णाङ्क fib(n)
{
    फर्काऊ (n <= 2) ? 1 : fib(n-1) + fib(n-2);
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    sleep_ms(333);
    म_लिखो(" %d", fib(म_से_प(argv[1])));
    फर्काऊ 0;
}
#endif
