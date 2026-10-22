#ضمن <stdio.h>

/* ------------------------------------------------------- */
#إذا defined test_backtrace_1

فراغ f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(فراغ**)0 = 0;
}
فراغ f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
فراغ f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
صحيح الرئيسية(صحيح argc, حرف **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    إرجاع 0;
}

/* ------------------------------------------------------- */
#وإلاإذا defined test_bcheck_1

بنية s { صحيح a,b,c,d,e; };
بنية s s[3];
بنية s *ps = s;
فراغ f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
صحيح الرئيسية(صحيح argc, حرف **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    إرجاع 0;
}

/* ------------------------------------------------------- */
#وإلاإذا defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
صحيح tcc_backtrace(ثابت حرف *fmt, ...);
فراغ exit(صحيح);

فراغ f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
فراغ f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
صحيح الرئيسية(صحيح argc, حرف **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    إرجاع 0;
}

/* ------------------------------------------------------- */
#وإلاإذا defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
صحيح الرئيسية(صحيح argc, حرف **argv)
{
    printf("* main\n"), fflush(stdout);
    إرجاع 1;
}

/* ------------------------------------------------------- */
#وإلا
#ضمن <stdlib.h>
#ضمن <string.h>
حرف *strdup();
صحيح الرئيسية()
{
    حرف pad1[10];
    حرف a[10];
    حرف pad2[10];
    حرف b[10];
    حرف pad3[10];
    memset (pad1, 0, حجم(pad1));
    memset (pad2, 0, حجم(pad2));
    memset (pad3, 0, حجم(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#إذا defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#وإلاإذا defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#وإلاإذا defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#وإلاإذا defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#وإلاإذا defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#وإلاإذا defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#وإلاإذا defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#وإلاإذا defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#وإلاإذا defined test_bcheck_108
    memset(&b[1],'b',10);
#وإلاإذا defined test_bcheck_109
    strlen(&b[0]);
#وإلاإذا defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#وإلاإذا defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#وإلاإذا defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#وإلاإذا defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#وإلاإذا defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#وإلاإذا defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#وإلاإذا defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#وإلاإذا defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#وإلاإذا defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#وإلاإذا defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#وإلاإذا defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#وإلاإذا defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#وإلاإذا defined test_bcheck_122
    strcat(&a[7], &a[0]);
#وإلاإذا defined test_bcheck_123
    strcat(&a[0], &b[3]);
#وإلاإذا defined test_bcheck_124
    strcat(&a[0], &a[4]);
#وإلاإذا defined test_bcheck_125
    strcat(&a[3], &a[0]);
#وإلاإذا defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#وإلاإذا defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#وإلاإذا defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#وإلاإذا defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#وإلاإذا defined test_bcheck_130
    strchr(&b[0], 'a');
#وإلاإذا defined test_bcheck_131
    strrchr(&b[0], 'a');
#وإلاإذا defined test_bcheck_132
    حرر(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
