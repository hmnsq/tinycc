#شامل <stdio.h>

/* ------------------------------------------------------- */
#اگر defined test_backtrace_1

خالی f3()
{
    لکھو("* f3()\n"), fflush(stdout);
    *(خالی**)0 = 0;
}
خالی f2()
{
    لکھو("* f2()\n"), fflush(stdout);
    f3();
}
خالی f1()
{
    لکھو("* f1()\n"), fflush(stdout);
    f2();
}
صحیح مین(صحیح argc, حرف **argv)
{
    لکھو("* main\n"), fflush(stdout);
    f1();
    لکھو("* exit main\n"), fflush(stdout);
    واپس 0;
}

/* ------------------------------------------------------- */
#وگرنہ_اگر defined test_bcheck_1

ساخت s { صحیح a,b,c,d,e; };
ساخت s s[3];
ساخت s *ps = s;
خالی f1()
{
    لکھو("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
صحیح مین(صحیح argc, حرف **argv)
{
    لکھو("* main\n"), fflush(stdout);
    f1();
    لکھو("* exit main\n"), fflush(stdout);
    واپس 0;
}

/* ------------------------------------------------------- */
#وگرنہ_اگر defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
صحیح tcc_backtrace(ثابت حرف *fmt, ...);
خالی باہر_نکلو(صحیح);

خالی f2()
{
    لکھو("* f2()\n");
    لکھو("* exit f2\n"), fflush(stdout);
    باہر_نکلو(34);
}
خالی f1()
{
    لکھو("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
صحیح مین(صحیح argc, حرف **argv)
{
    لکھو("* main\n"), fflush(stdout);
    f1();
    لکھو("* exit main\n"), fflush(stdout);
    واپس 0;
}

/* ------------------------------------------------------- */
#وگرنہ_اگر defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
صحیح مین(صحیح argc, حرف **argv)
{
    لکھو("* main\n"), fflush(stdout);
    واپس 1;
}

/* ------------------------------------------------------- */
#ورنہ
#شامل <stdlib.h>
#شامل <string.h>
حرف *strdup();
صحیح مین()
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

#اگر defined test_bcheck_100
    حافظہ_نقل(&a[1],&b[0],10);
#وگرنہ_اگر defined test_bcheck_101
    حافظہ_نقل(&a[0],&b[1],10);
#وگرنہ_اگر defined test_bcheck_102
    حافظہ_نقل(&a[0],&a[3],4);
#وگرنہ_اگر defined test_bcheck_103
    حافظہ_نقل(&a[3],&a[0],4);
#وگرنہ_اگر defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#وگرنہ_اگر defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#وگرنہ_اگر defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#وگرنہ_اگر defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#وگرنہ_اگر defined test_bcheck_108
    memset(&b[1],'b',10);
#وگرنہ_اگر defined test_bcheck_109
    لڑی_لمبائی(&b[0]);
#وگرنہ_اگر defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#وگرنہ_اگر defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#وگرنہ_اگر defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#وگرنہ_اگر defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#وگرنہ_اگر defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#وگرنہ_اگر defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#وگرنہ_اگر defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#وگرنہ_اگر defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#وگرنہ_اگر defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#وگرنہ_اگر defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#وگرنہ_اگر defined test_bcheck_120
    لڑی_موازنہ(&b[5], &b[0], 10);
#وگرنہ_اگر defined test_bcheck_121
    لڑی_موازنہ(&b[0], &b[5], 10);
#وگرنہ_اگر defined test_bcheck_122
    strcat(&a[7], &a[0]);
#وگرنہ_اگر defined test_bcheck_123
    strcat(&a[0], &b[3]);
#وگرنہ_اگر defined test_bcheck_124
    strcat(&a[0], &a[4]);
#وگرنہ_اگر defined test_bcheck_125
    strcat(&a[3], &a[0]);
#وگرنہ_اگر defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#وگرنہ_اگر defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#وگرنہ_اگر defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#وگرنہ_اگر defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#وگرنہ_اگر defined test_bcheck_130
    strchr(&b[0], 'a');
#وگرنہ_اگر defined test_bcheck_131
    strrchr(&b[0], 'a');
#وگرنہ_اگر defined test_bcheck_132
    آزاد(strdup(&b[0]));
#اگر_ختم
}
/* ------------------------------------------------------- */
#اگر_ختم
