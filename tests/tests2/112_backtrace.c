#ଅନ୍ତର୍ଭାଵ <stdio.h>

/* ------------------------------------------------------- */
#ଯଦି defined test_backtrace_1

ଶୂନ୍ୟ f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(ଶୂନ୍ୟ**)0 = 0;
}
ଶୂନ୍ୟ f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
ଶୂନ୍ୟ f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ଫେରନ୍ତୁ 0;
}

/* ------------------------------------------------------- */
#ନଚେତଯଦି defined test_bcheck_1

ସଂରଚନା s { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b,c,d,e; };
ସଂରଚନା s s[3];
ସଂରଚନା s *ps = s;
ଶୂନ୍ୟ f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ଫେରନ୍ତୁ 0;
}

/* ------------------------------------------------------- */
#ନଚେତଯଦି defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_backtrace(ଅଚଳ ଅକ୍ଷର *fmt, ...);
ଶୂନ୍ୟ exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

ଶୂନ୍ୟ f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
ଶୂନ୍ୟ f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ଫେରନ୍ତୁ 0;
}

/* ------------------------------------------------------- */
#ନଚେତଯଦି defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    printf("* main\n"), fflush(stdout);
    ଫେରନ୍ତୁ 1;
}

/* ------------------------------------------------------- */
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
ଅକ୍ଷର *strdup();
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଅକ୍ଷର pad1[10];
    ଅକ୍ଷର a[10];
    ଅକ୍ଷର pad2[10];
    ଅକ୍ଷର b[10];
    ଅକ୍ଷର pad3[10];
    memset (pad1, 0, ଆକାର(pad1));
    memset (pad2, 0, ଆକାର(pad2));
    memset (pad3, 0, ଆକାର(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#ଯଦି defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#ନଚେତଯଦି defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#ନଚେତଯଦି defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#ନଚେତଯଦି defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#ନଚେତଯଦି defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#ନଚେତଯଦି defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#ନଚେତଯଦି defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#ନଚେତଯଦି defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#ନଚେତଯଦି defined test_bcheck_108
    memset(&b[1],'b',10);
#ନଚେତଯଦି defined test_bcheck_109
    strlen(&b[0]);
#ନଚେତଯଦି defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#ନଚେତଯଦି defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#ନଚେତଯଦି defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#ନଚେତଯଦି defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#ନଚେତଯଦି defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#ନଚେତଯଦି defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#ନଚେତଯଦି defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#ନଚେତଯଦି defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#ନଚେତଯଦି defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#ନଚେତଯଦି defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#ନଚେତଯଦି defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#ନଚେତଯଦି defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#ନଚେତଯଦି defined test_bcheck_122
    strcat(&a[7], &a[0]);
#ନଚେତଯଦି defined test_bcheck_123
    strcat(&a[0], &b[3]);
#ନଚେତଯଦି defined test_bcheck_124
    strcat(&a[0], &a[4]);
#ନଚେତଯଦି defined test_bcheck_125
    strcat(&a[3], &a[0]);
#ନଚେତଯଦି defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#ନଚେତଯଦି defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#ନଚେତଯଦି defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#ନଚେତଯଦି defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#ନଚେତଯଦି defined test_bcheck_130
    strchr(&b[0], 'a');
#ନଚେତଯଦି defined test_bcheck_131
    strrchr(&b[0], 'a');
#ନଚେତଯଦି defined test_bcheck_132
    ମୁକ୍ତ(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
