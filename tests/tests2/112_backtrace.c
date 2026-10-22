#ಅನ್ತರ್ಭಾವ <stdio.h>

/* ------------------------------------------------------- */
#ಆದರೆ defined test_backtrace_1

ಶೂನ್ಯ f3()
{
    ಬರೆ("* f3()\n"), fflush(stdout);
    *(ಶೂನ್ಯ**)0 = 0;
}
ಶೂನ್ಯ f2()
{
    ಬರೆ("* f2()\n"), fflush(stdout);
    f3();
}
ಶೂನ್ಯ f1()
{
    ಬರೆ("* f1()\n"), fflush(stdout);
    f2();
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಬರೆ("* main\n"), fflush(stdout);
    f1();
    ಬರೆ("* exit main\n"), fflush(stdout);
    ಹಿಂತಿರುಗಿ 0;
}

/* ------------------------------------------------------- */
#ಅಥವಾಆದರೆ defined test_bcheck_1

ರಚನೆ s { ಪೂರ್ಣಾಂಕ a,b,c,d,e; };
ರಚನೆ s s[3];
ರಚನೆ s *ps = s;
ಶೂನ್ಯ f1()
{
    ಬರೆ("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಬರೆ("* main\n"), fflush(stdout);
    f1();
    ಬರೆ("* exit main\n"), fflush(stdout);
    ಹಿಂತಿರುಗಿ 0;
}

/* ------------------------------------------------------- */
#ಅಥವಾಆದರೆ defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
ಪೂರ್ಣಾಂಕ tcc_backtrace(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...);
ಶೂನ್ಯ ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ);

ಶೂನ್ಯ f2()
{
    ಬರೆ("* f2()\n");
    ಬರೆ("* exit f2\n"), fflush(stdout);
    ನಿರ್ಗಮಿಸು(34);
}
ಶೂನ್ಯ f1()
{
    ಬರೆ("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಬರೆ("* main\n"), fflush(stdout);
    f1();
    ಬರೆ("* exit main\n"), fflush(stdout);
    ಹಿಂತಿರುಗಿ 0;
}

/* ------------------------------------------------------- */
#ಅಥವಾಆದರೆ defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಬರೆ("* main\n"), fflush(stdout);
    ಹಿಂತಿರುಗಿ 1;
}

/* ------------------------------------------------------- */
#ಇಲ್ಲದಿದ್ದರೆ
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <string.h>
ಅಕ್ಷರ *strdup();
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಅಕ್ಷರ pad1[10];
    ಅಕ್ಷರ a[10];
    ಅಕ್ಷರ pad2[10];
    ಅಕ್ಷರ b[10];
    ಅಕ್ಷರ pad3[10];
    memset (pad1, 0, ಗಾತ್ರ(pad1));
    memset (pad2, 0, ಗಾತ್ರ(pad2));
    memset (pad3, 0, ಗಾತ್ರ(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#ಆದರೆ defined test_bcheck_100
    ಸ್ಮರಣೆ_ನಕಲು(&a[1],&b[0],10);
#ಅಥವಾಆದರೆ defined test_bcheck_101
    ಸ್ಮರಣೆ_ನಕಲು(&a[0],&b[1],10);
#ಅಥವಾಆದರೆ defined test_bcheck_102
    ಸ್ಮರಣೆ_ನಕಲು(&a[0],&a[3],4);
#ಅಥವಾಆದರೆ defined test_bcheck_103
    ಸ್ಮರಣೆ_ನಕಲು(&a[3],&a[0],4);
#ಅಥವಾಆದರೆ defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#ಅಥವಾಆದರೆ defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#ಅಥವಾಆದರೆ defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#ಅಥವಾಆದರೆ defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#ಅಥವಾಆದರೆ defined test_bcheck_108
    memset(&b[1],'b',10);
#ಅಥವಾಆದರೆ defined test_bcheck_109
    ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(&b[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#ಅಥವಾಆದರೆ defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#ಅಥವಾಆದರೆ defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#ಅಥವಾಆದರೆ defined test_bcheck_120
    ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(&b[5], &b[0], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_121
    ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(&b[0], &b[5], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_122
    strcat(&a[7], &a[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_123
    strcat(&a[0], &b[3]);
#ಅಥವಾಆದರೆ defined test_bcheck_124
    strcat(&a[0], &a[4]);
#ಅಥವಾಆದರೆ defined test_bcheck_125
    strcat(&a[3], &a[0]);
#ಅಥವಾಆದರೆ defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#ಅಥವಾಆದರೆ defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#ಅಥವಾಆದರೆ defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#ಅಥವಾಆದರೆ defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#ಅಥವಾಆದರೆ defined test_bcheck_130
    strchr(&b[0], 'a');
#ಅಥವಾಆದರೆ defined test_bcheck_131
    strrchr(&b[0], 'a');
#ಅಥವಾಆದರೆ defined test_bcheck_132
    ಬಿಡುಗಡೆ(strdup(&b[0]));
#ಆದರೆ_ಅಂತ್ಯ
}
/* ------------------------------------------------------- */
#ಆದರೆ_ಅಂತ್ಯ
