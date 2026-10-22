#ಅನ್ತರ್ಭಾವ <stdio.h>

/* ------------------------------------------------------- */
#ಯದಿ defined test_backtrace_1

ಶೂನ್ಯ f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(ಶೂನ್ಯ**)0 = 0;
}
ಶೂನ್ಯ f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
ಶೂನ್ಯ f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ defined test_bcheck_1

ಸಂರಚನಾ s { ಪೂರ್ಣಾಙ್ಕ a,b,c,d,e; };
ಸಂರಚನಾ s s[3];
ಸಂರಚನಾ s *ps = s;
ಶೂನ್ಯ f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
ಪೂರ್ಣಾಙ್ಕ tcc_backtrace(ಧ್ರುವ ವರ್ಣ *fmt, ...);
ಶೂನ್ಯ exit(ಪೂರ್ಣಾಙ್ಕ);

ಶೂನ್ಯ f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
ಶೂನ್ಯ f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    printf("* main\n"), fflush(stdout);
    ಪ್ರತ್ಯಾಗಮ 1;
}

/* ------------------------------------------------------- */
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <string.h>
ವರ್ಣ *strdup();
ಪೂರ್ಣಾಙ್ಕ main()
{
    ವರ್ಣ pad1[10];
    ವರ್ಣ a[10];
    ವರ್ಣ pad2[10];
    ವರ್ಣ b[10];
    ವರ್ಣ pad3[10];
    memset (pad1, 0, ಪರಿಮಾಣ(pad1));
    memset (pad2, 0, ಪರಿಮಾಣ(pad2));
    memset (pad3, 0, ಪರಿಮಾಣ(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#ಯದಿ defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_108
    memset(&b[1],'b',10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_109
    strlen(&b[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_122
    strcat(&a[7], &a[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_123
    strcat(&a[0], &b[3]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_124
    strcat(&a[0], &a[4]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_125
    strcat(&a[3], &a[0]);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#ನೋಚೇದ್ಯದಿ defined test_bcheck_130
    strchr(&b[0], 'a');
#ನೋಚೇದ್ಯದಿ defined test_bcheck_131
    strrchr(&b[0], 'a');
#ನೋಚೇದ್ಯದಿ defined test_bcheck_132
    ಮುಕ್ತ(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
