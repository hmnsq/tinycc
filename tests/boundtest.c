#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

പൂർണ്ണസംഖ്യ tab[TAB_SIZE];
പൂർണ്ണസംഖ്യ ret_sum;
അക്ഷരം tab3[256];

പൂർണ്ണസംഖ്യ test1(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    വേണ്ടി(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    തിരികെ sum;
}

/* error */
പൂർണ്ണസംഖ്യ test2(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    വേണ്ടി(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    തിരികെ sum;
}

/* actually, profiling test */
പൂർണ്ണസംഖ്യ test3(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ sum;
    പൂർണ്ണസംഖ്യ i, it;

    sum = 0;
    വേണ്ടി(it=0;it<NB_ITS;it++) {
        വേണ്ടി(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    തിരികെ sum;
}

/* ok */
പൂർണ്ണസംഖ്യ test4(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    പൂർണ്ണസംഖ്യ *tab4;

    tab4 = malloc(20 * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    വേണ്ടി(i=0;i<20;i++) {
        sum += tab4[i];
    }
    സ്വതന്ത്രം(tab4);

    തിരികെ sum;
}

/* error */
പൂർണ്ണസംഖ്യ test5(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    പൂർണ്ണസംഖ്യ *tab4;

    tab4 = malloc(20 * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    വേണ്ടി(i=0;i<21;i++) {
        sum += tab4[i];
    }
    സ്വതന്ത്രം(tab4);

    തിരികെ sum;
}

/* error */
പൂർണ്ണസംഖ്യ test6(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    പൂർണ്ണസംഖ്യ *tab4;
    
    tab4 = malloc(20 * വലുപ്പം(പൂർണ്ണസംഖ്യ));
    സ്വതന്ത്രം(tab4);
    വേണ്ടി(i=0;i<21;i++) {
        sum += tab4[i];
    }

    തിരികെ sum;
}

/* error */
പൂർണ്ണസംഖ്യ test7(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    പൂർണ്ണസംഖ്യ *p;

    വേണ്ടി(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        എങ്കിൽ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    തിരികെ sum;
}

/* ok */
പൂർണ്ണസംഖ്യ test8(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    പൂർണ്ണസംഖ്യ tab[10];

    വേണ്ടി(i=0;i<10;i++) {
        sum += tab[i];
    }
    തിരികെ sum;
}

/* error */
പൂർണ്ണസംഖ്യ test9(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0;
    അക്ഷരം tab[10];

    വേണ്ടി(i=0;i<11;i++) {
        sum += tab[i];
    }
    തിരികെ sum;
}

/* ok */
പൂർണ്ണസംഖ്യ test10(ശൂന്യം)
{
    അക്ഷരം tab[10];
    അക്ഷരം tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    തിരികെ 0;
}

/* error */
പൂർണ്ണസംഖ്യ test11(ശൂന്യം)
{
    അക്ഷരം tab[10];

    memset(tab, 0, 11);
    തിരികെ 0;
}

/* error */
പൂർണ്ണസംഖ്യ test12(ശൂന്യം)
{
    ശൂന്യം *ptr;
    ptr = malloc(10);
    സ്വതന്ത്രം(ptr);
    സ്വതന്ത്രം(ptr);
    തിരികെ 0;
}

/* error */
പൂർണ്ണസംഖ്യ test13(ശൂന്യം)
{
    അക്ഷരം pad1 = 0;
    അക്ഷരം tab[10];
    അക്ഷരം pad2 = 0;
    memset(tab, 'a', വലുപ്പം(tab));
    തിരികെ strlen(tab);
}

പൂർണ്ണസംഖ്യ test14(ശൂന്യം)
{
    അക്ഷരം *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    തിരികെ ret;
}

/* error */
പൂർണ്ണസംഖ്യ test15(ശൂന്യം)
{
    അക്ഷരം *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    തിരികെ ret;
}

/* ok */
പൂർണ്ണസംഖ്യ test16()
{
    അക്ഷരം *demo = "This is only a test.";
    അക്ഷരം *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    തിരികെ 0;
}

/* error */
പൂർണ്ണസംഖ്യ test17()
{
    അക്ഷരം *demo = "This is only a test.";
    അക്ഷരം *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    തിരികെ 0;
}

പൂർണ്ണസംഖ്യ test18(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i, sum = 0, n = TAB_SIZE;
    പൂർണ്ണസംഖ്യ tab[n];
    വേണ്ടി(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    തിരികെ sum;
}

പൂർണ്ണസംഖ്യ (*table_test[])(ശൂന്യം) = {
    test1,
    test2,
    test3,
    test4,
    test5,
    test6,
    test7,
    test8,
    test9,
    test10,
    test11,
    test12,
    test13,
    test14,
    test15,
    test16,
    test17,
    test18
};

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ i;
    അക്ഷരം *cp;
    പൂർണ്ണസംഖ്യ index;
    പൂർണ്ണസംഖ്യ (*ftest)(ശൂന്യം);
    പൂർണ്ണസംഖ്യ index_max = വലുപ്പം(table_test)/വലുപ്പം(table_test[0]);

    /* check bounds checking main arg */
    വേണ്ടി (i = 0; i < argc; i++) {
        cp = argv[i];
        ആകുമ്പോൾ (*cp) {
            cp++;
        }
    }

    എങ്കിൽ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    എങ്കിൽ (argc >= 2)
        index = atoi(argv[1]) - 1;

    എങ്കിൽ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    തിരികെ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
