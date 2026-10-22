#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[TAB_SIZE];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret_sum;
ଅକ୍ଷର tab3[256];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test1(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପାଇଁ(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ଫେରନ୍ତୁ sum;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test2(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପାଇଁ(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ଫେରନ୍ତୁ sum;
}

/* actually, profiling test */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test3(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sum;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, it;

    sum = 0;
    ପାଇଁ(it=0;it<NB_ITS;it++) {
        ପାଇଁ(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ଫେରନ୍ତୁ sum;
}

/* ok */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test4(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *tab4;

    tab4 = malloc(20 * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    ପାଇଁ(i=0;i<20;i++) {
        sum += tab4[i];
    }
    ମୁକ୍ତ(tab4);

    ଫେରନ୍ତୁ sum;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test5(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *tab4;

    tab4 = malloc(20 * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    ପାଇଁ(i=0;i<21;i++) {
        sum += tab4[i];
    }
    ମୁକ୍ତ(tab4);

    ଫେରନ୍ତୁ sum;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test6(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *tab4;
    
    tab4 = malloc(20 * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    ମୁକ୍ତ(tab4);
    ପାଇଁ(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ଫେରନ୍ତୁ sum;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test7(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p;

    ପାଇଁ(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ଯଦି (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ଫେରନ୍ତୁ sum;
}

/* ok */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test8(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[10];

    ପାଇଁ(i=0;i<10;i++) {
        sum += tab[i];
    }
    ଫେରନ୍ତୁ sum;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test9(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0;
    ଅକ୍ଷର tab[10];

    ପାଇଁ(i=0;i<11;i++) {
        sum += tab[i];
    }
    ଫେରନ୍ତୁ sum;
}

/* ok */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test10(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର tab[10];
    ଅକ୍ଷର tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ଫେରନ୍ତୁ 0;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test11(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର tab[10];

    memset(tab, 0, 11);
    ଫେରନ୍ତୁ 0;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test12(ଶୂନ୍ୟ)
{
    ଶୂନ୍ୟ *ptr;
    ptr = malloc(10);
    ମୁକ୍ତ(ptr);
    ମୁକ୍ତ(ptr);
    ଫେରନ୍ତୁ 0;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test13(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର pad1 = 0;
    ଅକ୍ଷର tab[10];
    ଅକ୍ଷର pad2 = 0;
    memset(tab, 'a', ଆକାର(tab));
    ଫେରନ୍ତୁ strlen(tab);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test14(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ଫେରନ୍ତୁ ret;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test15(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ଫେରନ୍ତୁ ret;
}

/* ok */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test16()
{
    ଅକ୍ଷର *demo = "This is only a test.";
    ଅକ୍ଷର *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ଫେରନ୍ତୁ 0;
}

/* error */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test17()
{
    ଅକ୍ଷର *demo = "This is only a test.";
    ଅକ୍ଷର *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test18(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, sum = 0, n = TAB_SIZE;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[n];
    ପାଇଁ(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ଫେରନ୍ତୁ sum;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*table_test[])(ଶୂନ୍ୟ) = {
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ଅକ୍ଷର *cp;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*ftest)(ଶୂନ୍ୟ);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index_max = ଆକାର(table_test)/ଆକାର(table_test[0]);

    /* check bounds checking main arg */
    ପାଇଁ (i = 0; i < argc; i++) {
        cp = argv[i];
        ଯେତେବେଳେ (*cp) {
            cp++;
        }
    }

    ଯଦି (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ଯଦି (argc >= 2)
        index = atoi(argv[1]) - 1;

    ଯଦି ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ଫେରନ୍ତୁ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
