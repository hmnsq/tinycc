#अन्तर्भाव <stdio.h>

/* ------------------------------------------------------- */
#यदि defined test_backtrace_1

शून्य f3()
{
    प्रारूप_लिख("* f3()\n"), fflush(stdout);
    *(शून्य**)0 = 0;
}
शून्य f2()
{
    प्रारूप_लिख("* f2()\n"), fflush(stdout);
    f3();
}
शून्य f1()
{
    प्रारूप_लिख("* f1()\n"), fflush(stdout);
    f2();
}
पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    प्रारूप_लिख("* main\n"), fflush(stdout);
    f1();
    प्रारूप_लिख("* exit main\n"), fflush(stdout);
    प्रत्यागम 0;
}

/* ------------------------------------------------------- */
#नोचेद्यदि defined test_bcheck_1

संरचना s { पूर्णाङ्क a,b,c,d,e; };
संरचना s s[3];
संरचना s *ps = s;
शून्य f1()
{
    प्रारूप_लिख("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    प्रारूप_लिख("* main\n"), fflush(stdout);
    f1();
    प्रारूप_लिख("* exit main\n"), fflush(stdout);
    प्रत्यागम 0;
}

/* ------------------------------------------------------- */
#नोचेद्यदि defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
पूर्णाङ्क tcc_backtrace(ध्रुव वर्ण *fmt, ...);
शून्य निर्गच्छ(पूर्णाङ्क);

शून्य f2()
{
    प्रारूप_लिख("* f2()\n");
    प्रारूप_लिख("* exit f2\n"), fflush(stdout);
    निर्गच्छ(34);
}
शून्य f1()
{
    प्रारूप_लिख("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    प्रारूप_लिख("* main\n"), fflush(stdout);
    f1();
    प्रारूप_लिख("* exit main\n"), fflush(stdout);
    प्रत्यागम 0;
}

/* ------------------------------------------------------- */
#नोचेद्यदि defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    प्रारूप_लिख("* main\n"), fflush(stdout);
    प्रत्यागम 1;
}

/* ------------------------------------------------------- */
#अन्यथा
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <string.h>
वर्ण *strdup();
पूर्णाङ्क मुख्यम्()
{
    वर्ण pad1[10];
    वर्ण a[10];
    वर्ण pad2[10];
    वर्ण b[10];
    वर्ण pad3[10];
    स्मृतिं_पूरय (pad1, 0, परिमाण(pad1));
    स्मृतिं_पूरय (pad2, 0, परिमाण(pad2));
    स्मृतिं_पूरय (pad3, 0, परिमाण(pad3));

    स्मृतिं_पूरय (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    स्मृतिं_पूरय (b, 'b', 10);

#यदि defined test_bcheck_100
    स्मृतिं_प्रतिलिख(&a[1],&b[0],10);
#नोचेद्यदि defined test_bcheck_101
    स्मृतिं_प्रतिलिख(&a[0],&b[1],10);
#नोचेद्यदि defined test_bcheck_102
    स्मृतिं_प्रतिलिख(&a[0],&a[3],4);
#नोचेद्यदि defined test_bcheck_103
    स्मृतिं_प्रतिलिख(&a[3],&a[0],4);
#नोचेद्यदि defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#नोचेद्यदि defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#नोचेद्यदि defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#नोचेद्यदि defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#नोचेद्यदि defined test_bcheck_108
    स्मृतिं_पूरय(&b[1],'b',10);
#नोचेद्यदि defined test_bcheck_109
    वाक्यदैर्घ्यम्(&b[0]);
#नोचेद्यदि defined test_bcheck_110
    वाक्यं_प्रतिलिख(&a[7], &a[0]);
#नोचेद्यदि defined test_bcheck_111
    वाक्यं_प्रतिलिख(&a[0], &b[7]);
#नोचेद्यदि defined test_bcheck_112
    वाक्यं_प्रतिलिख(&a[0], &a[1]);
#नोचेद्यदि defined test_bcheck_113
    वाक्यं_प्रतिलिख(&a[2], &a[0]);
#नोचेद्यदि defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#नोचेद्यदि defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#नोचेद्यदि defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#नोचेद्यदि defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#नोचेद्यदि defined test_bcheck_118
    वाक्यं_तुलय(&b[2], &b[0]);
#नोचेद्यदि defined test_bcheck_119
    वाक्यं_तुलय(&b[0], &b[2]);
#नोचेद्यदि defined test_bcheck_120
    वाक्ये_तुलय(&b[5], &b[0], 10);
#नोचेद्यदि defined test_bcheck_121
    वाक्ये_तुलय(&b[0], &b[5], 10);
#नोचेद्यदि defined test_bcheck_122
    वाक्यं_योजय(&a[7], &a[0]);
#नोचेद्यदि defined test_bcheck_123
    वाक्यं_योजय(&a[0], &b[3]);
#नोचेद्यदि defined test_bcheck_124
    वाक्यं_योजय(&a[0], &a[4]);
#नोचेद्यदि defined test_bcheck_125
    वाक्यं_योजय(&a[3], &a[0]);
#नोचेद्यदि defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#नोचेद्यदि defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#नोचेद्यदि defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#नोचेद्यदि defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#नोचेद्यदि defined test_bcheck_130
    strchr(&b[0], 'a');
#नोचेद्यदि defined test_bcheck_131
    strrchr(&b[0], 'a');
#नोचेद्यदि defined test_bcheck_132
    मुक्त(strdup(&b[0]));
#यदि_अन्तः
}
/* ------------------------------------------------------- */
#यदि_अन्तः
