#അന്തര്ഭാവ <stdio.h>

/* ------------------------------------------------------- */
#എങ്കിൽ defined test_backtrace_1

ശൂന്യം f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(ശൂന്യം**)0 = 0;
}
ശൂന്യം f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
ശൂന്യം f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    തിരികെ 0;
}

/* ------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_1

ഘടന s { പൂർണ്ണസംഖ്യ a,b,c,d,e; };
ഘടന s s[3];
ഘടന s *ps = s;
ശൂന്യം f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    തിരികെ 0;
}

/* ------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
പൂർണ്ണസംഖ്യ tcc_backtrace(സ്ഥിരം അക്ഷരം *fmt, ...);
ശൂന്യം exit(പൂർണ്ണസംഖ്യ);

ശൂന്യം f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
ശൂന്യം f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    തിരികെ 0;
}

/* ------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    printf("* main\n"), fflush(stdout);
    തിരികെ 1;
}

/* ------------------------------------------------------- */
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <string.h>
അക്ഷരം *strdup();
പൂർണ്ണസംഖ്യ പ്രധാന()
{
    അക്ഷരം pad1[10];
    അക്ഷരം a[10];
    അക്ഷരം pad2[10];
    അക്ഷരം b[10];
    അക്ഷരം pad3[10];
    memset (pad1, 0, വലുപ്പം(pad1));
    memset (pad2, 0, വലുപ്പം(pad2));
    memset (pad3, 0, വലുപ്പം(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#എങ്കിൽ defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_108
    memset(&b[1],'b',10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_109
    strlen(&b[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_122
    strcat(&a[7], &a[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_123
    strcat(&a[0], &b[3]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_124
    strcat(&a[0], &a[4]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_125
    strcat(&a[3], &a[0]);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_130
    strchr(&b[0], 'a');
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_131
    strrchr(&b[0], 'a');
#അല്ലെങ്കിലെങ്കിൽ defined test_bcheck_132
    സ്വതന്ത്രം(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
