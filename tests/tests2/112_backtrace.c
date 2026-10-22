#அந்தர்பாவ <stdio.h>

/* ------------------------------------------------------- */
#எனில் defined test_backtrace_1

வெறுமை f3()
{
    printf("* f3()\n"), fflush(stdout);
    *(வெறுமை**)0 = 0;
}
வெறுமை f2()
{
    printf("* f2()\n"), fflush(stdout);
    f3();
}
வெறுமை f1()
{
    printf("* f1()\n"), fflush(stdout);
    f2();
}
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    திரும்பு 0;
}

/* ------------------------------------------------------- */
#அல்லதெனில் defined test_bcheck_1

கட்டமைப்பு s { முழு a,b,c,d,e; };
கட்டமைப்பு s s[3];
கட்டமைப்பு s *ps = s;
வெறுமை f1()
{
    printf("* f1()\n"), fflush(stdout);
    ps[3] = ps[2];
}
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    திரும்பு 0;
}

/* ------------------------------------------------------- */
#அல்லதெனில் defined test_tcc_backtrace_2

/* test custom backtrace and 'exit()' redirection */
முழு tcc_backtrace(மாறிலி எழுத்து *fmt, ...);
வெறுமை exit(முழு);

வெறுமை f2()
{
    printf("* f2()\n");
    printf("* exit f2\n"), fflush(stdout);
    exit(34);
}
வெறுமை f1()
{
    printf("* f1()\n"), fflush(stdout);
    tcc_backtrace("Hello from %s!", "f1");
    f2();
}
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    printf("* main\n"), fflush(stdout);
    f1();
    printf("* exit main\n"), fflush(stdout);
    திரும்பு 0;
}

/* ------------------------------------------------------- */
#அல்லதெனில் defined test_tcc_backtrace_3

/* this test should be run despite of the exit(34) above */
முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    printf("* main\n"), fflush(stdout);
    திரும்பு 1;
}

/* ------------------------------------------------------- */
#இல்லையெனில்
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <string.h>
எழுத்து *strdup();
முழு முதன்மை()
{
    எழுத்து pad1[10];
    எழுத்து a[10];
    எழுத்து pad2[10];
    எழுத்து b[10];
    எழுத்து pad3[10];
    memset (pad1, 0, அளவு(pad1));
    memset (pad2, 0, அளவு(pad2));
    memset (pad3, 0, அளவு(pad3));

    memset (a, 'a', 10);
    a[3] = 0;
    a[9] = 0;
    memset (b, 'b', 10);

#எனில் defined test_bcheck_100
    memcpy(&a[1],&b[0],10);
#அல்லதெனில் defined test_bcheck_101
    memcpy(&a[0],&b[1],10);
#அல்லதெனில் defined test_bcheck_102
    memcpy(&a[0],&a[3],4);
#அல்லதெனில் defined test_bcheck_103
    memcpy(&a[3],&a[0],4);
#அல்லதெனில் defined test_bcheck_104
    memcmp(&b[1],&b[0],10);
#அல்லதெனில் defined test_bcheck_105
    memcmp(&b[0],&b[1],10);
#அல்லதெனில் defined test_bcheck_106
    memmove(&b[1],&b[0],10);
#அல்லதெனில் defined test_bcheck_107
    memmove(&b[0],&b[1],10);
#அல்லதெனில் defined test_bcheck_108
    memset(&b[1],'b',10);
#அல்லதெனில் defined test_bcheck_109
    strlen(&b[0]);
#அல்லதெனில் defined test_bcheck_110
    strcpy(&a[7], &a[0]);
#அல்லதெனில் defined test_bcheck_111
    strcpy(&a[0], &b[7]);
#அல்லதெனில் defined test_bcheck_112
    strcpy(&a[0], &a[1]);
#அல்லதெனில் defined test_bcheck_113
    strcpy(&a[2], &a[0]);
#அல்லதெனில் defined test_bcheck_114
    strncpy(&a[7], &a[0], 10);
#அல்லதெனில் defined test_bcheck_115
    strncpy(&a[0], &b[7], 10);
#அல்லதெனில் defined test_bcheck_116
    strncpy(&a[0], &a[1], 10);
#அல்லதெனில் defined test_bcheck_117
    strncpy(&a[2], &a[0], 10);
#அல்லதெனில் defined test_bcheck_118
    strcmp(&b[2], &b[0]);
#அல்லதெனில் defined test_bcheck_119
    strcmp(&b[0], &b[2]);
#அல்லதெனில் defined test_bcheck_120
    strncmp(&b[5], &b[0], 10);
#அல்லதெனில் defined test_bcheck_121
    strncmp(&b[0], &b[5], 10);
#அல்லதெனில் defined test_bcheck_122
    strcat(&a[7], &a[0]);
#அல்லதெனில் defined test_bcheck_123
    strcat(&a[0], &b[3]);
#அல்லதெனில் defined test_bcheck_124
    strcat(&a[0], &a[4]);
#அல்லதெனில் defined test_bcheck_125
    strcat(&a[3], &a[0]);
#அல்லதெனில் defined test_bcheck_126
    strncat(&a[7], &a[0], 3);
#அல்லதெனில் defined test_bcheck_127
    strncat(&a[0], &b[3], 8);
#அல்லதெனில் defined test_bcheck_128
    strncat(&a[0], &a[4], 3);
#அல்லதெனில் defined test_bcheck_129
    strncat(&a[3], &a[0], 10);
#அல்லதெனில் defined test_bcheck_130
    strchr(&b[0], 'a');
#அல்லதெனில் defined test_bcheck_131
    strrchr(&b[0], 'a');
#அல்லதெனில் defined test_bcheck_132
    விடுவி(strdup(&b[0]));
#endif
}
/* ------------------------------------------------------- */
#endif
