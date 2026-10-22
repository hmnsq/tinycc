#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

/* ------------------------------------------------------- */
#ਜੇ defined test_backtrace_1

ਖਾਲੀ f3()
{
    ਲਿਖੋ("* f3()\n"), fflush(stdout);
    *(ਖਾਲੀ**)0 = 0;
}
ਖਾਲੀ f2()
{
    ਲਿਖੋ("* f2()\n"), fflush(stdout);
    f3();
}
ਖਾਲੀ f1()
{
    ਲਿਖੋ("* f1()\n"), fflush(stdout);
    f2();
}
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲਿਖੋ("* main\n"), fflush(stdout);
    f1();
    ਲਿਖੋ("* exit main\n"), fflush(stdout);
    ਵਾਪਸ 0;
}

/* ------------------------------------------------------- */
#ਜਾਂਜੇ defined test_bcheck_1

ਬਣਤਰ s { ਪੂਰਨ a,b,c,d,e; };
ਬਣਤਰ s s[3];
ਬਣਤਰ s *ps = s;
ਖਾਲੀ f1()
{
    ਲਿਖੋ("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲਿਖੋ("* main\n"), fflush(stdout);
    f1();
    ਲਿਖੋ("* exit main\n"), fflush(stdout);
    ਵਾਪਸ 0;
}

/* ------------------------------------------------------- */
#ਜਾਂਜੇ defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
ਪੂਰਨ tcc_backtrace(ਅਚਲ ਅੱਖਰ *fmt, ...);
ਖਾਲੀ ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ);

ਖਾਲੀ f2()
{
    ਲਿਖੋ("* f2()\n");
    ਲਿਖੋ("* exit f2\n"), fflush(stdout);
    ਬਾਹਰ_ਨਿਕਲੋ(34);
}
ਖਾਲੀ f1()
{
    ਲਿਖੋ("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲਿਖੋ("* main\n"), fflush(stdout);
    f1();
    ਲਿਖੋ("* exit main\n"), fflush(stdout);
    ਵਾਪਸ 0;
}

/* ------------------------------------------------------- */
#ਜਾਂਜੇ defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲਿਖੋ("* main\n"), fflush(stdout);
    ਵਾਪਸ 1;
}

/* ------------------------------------------------------- */
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
ਅੱਖਰ *strdup();
ਪੂਰਨ ਮੁੱਖ()
{
    ਅੱਖਰ pad1[10];
    ਅੱਖਰ a[10];
    ਅੱਖਰ pad2[10];
    ਅੱਖਰ b[10];
    ਅੱਖਰ pad3[10];
    memset (pad1, 0, ਆਕਾਰ(pad1));
    memset (pad2, 0, ਆਕਾਰ(pad2));
    memset (pad3, 0, ਆਕਾਰ(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#ਜੇ defined test_bcheck_100
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&a[1],&b[0],10);
#ਜਾਂਜੇ defined test_bcheck_101
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&a[0],&b[1],10);
#ਜਾਂਜੇ defined test_bcheck_102
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&a[0],&a[3],4);
#ਜਾਂਜੇ defined test_bcheck_103
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(&a[3],&a[0],4);
#ਜਾਂਜੇ defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#ਜਾਂਜੇ defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#ਜਾਂਜੇ defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#ਜਾਂਜੇ defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#ਜਾਂਜੇ defined test_bcheck_108
    memset(&b[1],'b',10);
#ਜਾਂਜੇ defined test_bcheck_109
    ਲੜੀ_ਲੰਬਾਈ(&b[0]);
#ਜਾਂਜੇ defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#ਜਾਂਜੇ defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#ਜਾਂਜੇ defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#ਜਾਂਜੇ defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#ਜਾਂਜੇ defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#ਜਾਂਜੇ defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#ਜਾਂਜੇ defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#ਜਾਂਜੇ defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#ਜਾਂਜੇ defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#ਜਾਂਜੇ defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#ਜਾਂਜੇ defined test_bcheck_120
    ਲੜੀ_ਤੁਲਨਾ(&b[5], &b[0], 10);
#ਜਾਂਜੇ defined test_bcheck_121
    ਲੜੀ_ਤੁਲਨਾ(&b[0], &b[5], 10);
#ਜਾਂਜੇ defined test_bcheck_122
    strcat(&a[7], &a[0]);
#ਜਾਂਜੇ defined test_bcheck_123
    strcat(&a[0], &b[3]);
#ਜਾਂਜੇ defined test_bcheck_124
    strcat(&a[0], &a[4]);
#ਜਾਂਜੇ defined test_bcheck_125
    strcat(&a[3], &a[0]);
#ਜਾਂਜੇ defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#ਜਾਂਜੇ defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#ਜਾਂਜੇ defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#ਜਾਂਜੇ defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#ਜਾਂਜੇ defined test_bcheck_130
    strchr(&b[0], 'a');
#ਜਾਂਜੇ defined test_bcheck_131
    strrchr(&b[0], 'a');
#ਜਾਂਜੇ defined test_bcheck_132
    ਮੁਕਤ(strdup(&b[0]));
#ਜੇ_ਅੰਤ
}
/* ------------------------------------------------------- */
#ਜੇ_ਅੰਤ
