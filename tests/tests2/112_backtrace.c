#అన్తర్భావ <stdio.h>

/* ------------------------------------------------------- */
#ఒకవేళ defined test_backtrace_1

శూన్య f3()
{
    రాయి("* f3()\n"), fflush(stdout);
    *(శూన్య**)0 = 0;
}
శూన్య f2()
{
    రాయి("* f2()\n"), fflush(stdout);
    f3();
}
శూన్య f1()
{
    రాయి("* f1()\n"), fflush(stdout);
    f2();
}
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    రాయి("* main\n"), fflush(stdout);
    f1();
    రాయి("* exit main\n"), fflush(stdout);
    తిరిగి 0;
}

/* ------------------------------------------------------- */
#లేదావేళ defined test_bcheck_1

నిర్మాణం s { పూర్ణాంకం a,b,c,d,e; };
నిర్మాణం s s[3];
నిర్మాణం s *ps = s;
శూన్య f1()
{
    రాయి("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    రాయి("* main\n"), fflush(stdout);
    f1();
    రాయి("* exit main\n"), fflush(stdout);
    తిరిగి 0;
}

/* ------------------------------------------------------- */
#లేదావేళ defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
పూర్ణాంకం tcc_backtrace(స్థిరరాశి అక్షరం *fmt, ...);
శూన్య నిష్క్రమించు(పూర్ణాంకం);

శూన్య f2()
{
    రాయి("* f2()\n");
    రాయి("* exit f2\n"), fflush(stdout);
    నిష్క్రమించు(34);
}
శూన్య f1()
{
    రాయి("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    రాయి("* main\n"), fflush(stdout);
    f1();
    రాయి("* exit main\n"), fflush(stdout);
    తిరిగి 0;
}

/* ------------------------------------------------------- */
#లేదావేళ defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    రాయి("* main\n"), fflush(stdout);
    తిరిగి 1;
}

/* ------------------------------------------------------- */
#లేకపోతే
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <string.h>
అక్షరం *strdup();
పూర్ణాంకం ప్రధాన()
{
    అక్షరం pad1[10];
    అక్షరం a[10];
    అక్షరం pad2[10];
    అక్షరం b[10];
    అక్షరం pad3[10];
    memset (pad1, 0, పరిమాణం(pad1));
    memset (pad2, 0, పరిమాణం(pad2));
    memset (pad3, 0, పరిమాణం(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#ఒకవేళ defined test_bcheck_100
    జ్ఞాపకం_నకలు(&a[1],&b[0],10);
#లేదావేళ defined test_bcheck_101
    జ్ఞాపకం_నకలు(&a[0],&b[1],10);
#లేదావేళ defined test_bcheck_102
    జ్ఞాపకం_నకలు(&a[0],&a[3],4);
#లేదావేళ defined test_bcheck_103
    జ్ఞాపకం_నకలు(&a[3],&a[0],4);
#లేదావేళ defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#లేదావేళ defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#లేదావేళ defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#లేదావేళ defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#లేదావేళ defined test_bcheck_108
    memset(&b[1],'b',10);
#లేదావేళ defined test_bcheck_109
    అక్షరశ్రేణి_పొడవు(&b[0]);
#లేదావేళ defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#లేదావేళ defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#లేదావేళ defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#లేదావేళ defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#లేదావేళ defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#లేదావేళ defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#లేదావేళ defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#లేదావేళ defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#లేదావేళ defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#లేదావేళ defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#లేదావేళ defined test_bcheck_120
    అక్షరశ్రేణి_పోలిక(&b[5], &b[0], 10);
#లేదావేళ defined test_bcheck_121
    అక్షరశ్రేణి_పోలిక(&b[0], &b[5], 10);
#లేదావేళ defined test_bcheck_122
    strcat(&a[7], &a[0]);
#లేదావేళ defined test_bcheck_123
    strcat(&a[0], &b[3]);
#లేదావేళ defined test_bcheck_124
    strcat(&a[0], &a[4]);
#లేదావేళ defined test_bcheck_125
    strcat(&a[3], &a[0]);
#లేదావేళ defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#లేదావేళ defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#లేదావేళ defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#లేదావేళ defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#లేదావేళ defined test_bcheck_130
    strchr(&b[0], 'a');
#లేదావేళ defined test_bcheck_131
    strrchr(&b[0], 'a');
#లేదావేళ defined test_bcheck_132
    విడుదల(strdup(&b[0]));
#అయితే_ముగింపు
}
/* ------------------------------------------------------- */
#అయితే_ముగింపు
