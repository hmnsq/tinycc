#অন্তর্ভাৱ <stdio.h>

/* ------------------------------------------------------- */
#যদি defined test_backtrace_1

শূন্য f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(শূন্য**)0 = 0;
}
শূন্য f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
শূন্য f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ঘূৰাই 0;
}

/* ------------------------------------------------------- */
#নোচেদ্যদি defined test_bcheck_1

সংরচনা s { পূর্ণাঙ্ক a,b,c,d,e; };
সংরচনা s s[3];
সংরচনা s *ps = s;
শূন্য f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ঘূৰাই 0;
}

/* ------------------------------------------------------- */
#নোচেদ্যদি defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
পূর্ণাঙ্ক tcc_backtrace(ধ্রুৱ ৱর্ণ *fmt, ...);
শূন্য exit(পূর্ণাঙ্ক);

শূন্য f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
শূন্য f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ঘূৰাই 0;
}

/* ------------------------------------------------------- */
#নোচেদ্যদি defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    printf("* main\n"), fflush(stdout);
    ঘূৰাই 1;
}

/* ------------------------------------------------------- */
#অন্যথা
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <string.h>
ৱর্ণ *strdup();
পূর্ণাঙ্ক main()
{
    ৱর্ণ pad1[10];
    ৱর্ণ a[10];
    ৱর্ণ pad2[10];
    ৱর্ণ b[10];
    ৱর্ণ pad3[10];
    memset (pad1, 0, পরিমাণ(pad1));
    memset (pad2, 0, পরিমাণ(pad2));
    memset (pad3, 0, পরিমাণ(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#যদি defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#নোচেদ্যদি defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#নোচেদ্যদি defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#নোচেদ্যদি defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#নোচেদ্যদি defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#নোচেদ্যদি defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#নোচেদ্যদি defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#নোচেদ্যদি defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#নোচেদ্যদি defined test_bcheck_108
    memset(&b[1],'b',10);
#নোচেদ্যদি defined test_bcheck_109
    strlen(&b[0]);
#নোচেদ্যদি defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#নোচেদ্যদি defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#নোচেদ্যদি defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#নোচেদ্যদি defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#নোচেদ্যদি defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#নোচেদ্যদি defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#নোচেদ্যদি defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#নোচেদ্যদি defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#নোচেদ্যদি defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#নোচেদ্যদি defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#নোচেদ্যদি defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#নোচেদ্যদি defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#নোচেদ্যদি defined test_bcheck_122
    strcat(&a[7], &a[0]);
#নোচেদ্যদি defined test_bcheck_123
    strcat(&a[0], &b[3]);
#নোচেদ্যদি defined test_bcheck_124
    strcat(&a[0], &a[4]);
#নোচেদ্যদি defined test_bcheck_125
    strcat(&a[3], &a[0]);
#নোচেদ্যদি defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#নোচেদ্যদি defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#নোচেদ্যদি defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#নোচেদ্যদি defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#নোচেদ্যদি defined test_bcheck_130
    strchr(&b[0], 'a');
#নোচেদ্যদি defined test_bcheck_131
    strrchr(&b[0], 'a');
#নোচেদ্যদি defined test_bcheck_132
    মুক্ত(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
