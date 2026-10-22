#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_আকার 100

পূর্ণসংখ্যা tab[TAB_আকার];
পূর্ণসংখ্যা ret_যোগ;
অক্ষর tab3[256];

পূর্ণসংখ্যা test1(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    জন্য(i=0;i<TAB_আকার;i++) {
        যোগ += tab[i];
    }
    ফেরত যোগ;
}

/* error */
পূর্ণসংখ্যা test2(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    জন্য(i=0;i<TAB_আকার + 1;i++) {
        যোগ += tab[i];
    }
    ফেরত যোগ;
}

/* actually, profiling test */
পূর্ণসংখ্যা test3(শূন্য)
{
    পূর্ণসংখ্যা যোগ;
    পূর্ণসংখ্যা i, it;

    যোগ = 0;
    জন্য(it=0;it<NB_ITS;it++) {
        জন্য(i=0;i<TAB_আকার;i++) {
            যোগ += tab[i];
        }
    }
    ফেরত যোগ;
}

/* ok */
পূর্ণসংখ্যা test4(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    পূর্ণসংখ্যা *tab4;

    tab4 = malloc(20 * আকার(পূর্ণসংখ্যা));
    জন্য(i=0;i<20;i++) {
        যোগ += tab4[i];
    }
    মুক্ত(tab4);

    ফেরত যোগ;
}

/* error */
পূর্ণসংখ্যা test5(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    পূর্ণসংখ্যা *tab4;

    tab4 = malloc(20 * আকার(পূর্ণসংখ্যা));
    জন্য(i=0;i<21;i++) {
        যোগ += tab4[i];
    }
    মুক্ত(tab4);

    ফেরত যোগ;
}

/* error */
পূর্ণসংখ্যা test6(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    পূর্ণসংখ্যা *tab4;
    
    tab4 = malloc(20 * আকার(পূর্ণসংখ্যা));
    মুক্ত(tab4);
    জন্য(i=0;i<21;i++) {
        যোগ += tab4[i];
    }

    ফেরত যোগ;
}

/* error */
পূর্ণসংখ্যা test7(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    পূর্ণসংখ্যা *p;

    জন্য(i=0;i<TAB_আকার + 1;i++) {
        p = &tab[i];
        যদি (i == TAB_আকার)
            printf("i=%d %x\n", i, p);
        যোগ += *p;
    }
    ফেরত যোগ;
}

/* ok */
পূর্ণসংখ্যা test8(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    পূর্ণসংখ্যা tab[10];

    জন্য(i=0;i<10;i++) {
        যোগ += tab[i];
    }
    ফেরত যোগ;
}

/* error */
পূর্ণসংখ্যা test9(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0;
    অক্ষর tab[10];

    জন্য(i=0;i<11;i++) {
        যোগ += tab[i];
    }
    ফেরত যোগ;
}

/* ok */
পূর্ণসংখ্যা test10(শূন্য)
{
    অক্ষর tab[10];
    অক্ষর tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ফেরত 0;
}

/* error */
পূর্ণসংখ্যা test11(শূন্য)
{
    অক্ষর tab[10];

    memset(tab, 0, 11);
    ফেরত 0;
}

/* error */
পূর্ণসংখ্যা test12(শূন্য)
{
    শূন্য *ptr;
    ptr = malloc(10);
    মুক্ত(ptr);
    মুক্ত(ptr);
    ফেরত 0;
}

/* error */
পূর্ণসংখ্যা test13(শূন্য)
{
    অক্ষর pad1 = 0;
    অক্ষর tab[10];
    অক্ষর pad2 = 0;
    memset(tab, 'a', আকার(tab));
    ফেরত strlen(tab);
}

পূর্ণসংখ্যা test14(শূন্য)
{
    অক্ষর *p = alloca(TAB_আকার);
    আকার_t ret;
    memset(p, 'a', TAB_আকার);
    p[TAB_আকার-1] = 0;
    ret = strlen(p);
    ফেরত ret;
}

/* error */
পূর্ণসংখ্যা test15(শূন্য)
{
    অক্ষর *p = alloca(TAB_আকার-1);
    আকার_t ret;
    memset(p, 'a', TAB_আকার);
    p[TAB_আকার-1] = 0;
    ret = strlen(p);
    ফেরত ret;
}

/* ok */
পূর্ণসংখ্যা test16()
{
    অক্ষর *demo = "This is only a test.";
    অক্ষর *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ফেরত 0;
}

/* error */
পূর্ণসংখ্যা test17()
{
    অক্ষর *demo = "This is only a test.";
    অক্ষর *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ফেরত 0;
}

পূর্ণসংখ্যা test18(শূন্য)
{
    পূর্ণসংখ্যা i, যোগ = 0, n = TAB_আকার;
    পূর্ণসংখ্যা tab[n];
    জন্য(i=0;i<TAB_আকার+1;i++) {
        যোগ += tab[i];
    }
    ফেরত যোগ;
}

পূর্ণসংখ্যা (*table_test[])(শূন্য) = {
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

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv)
{
    পূর্ণসংখ্যা i;
    অক্ষর *cp;
    পূর্ণসংখ্যা সূচক;
    পূর্ণসংখ্যা (*ftest)(শূন্য);
    পূর্ণসংখ্যা সূচক_max = আকার(table_test)/আকার(table_test[0]);

    /* check bounds checking main arg */
    জন্য (i = 0; i < argc; i++) {
        cp = argv[i];
        যখন (*cp) {
            cp++;
        }
    }

    যদি (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", সূচক_max);
        exit(1);
    }

    সূচক = 0;
    যদি (argc >= 2)
        সূচক = atoi(argv[1]) - 1;

    যদি ((সূচক < 0) || (সূচক >= সূচক_max)) {
        printf("N is outside of the valid range (%d)\n", সূচক);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[সূচক];
    ftest();

    ফেরত 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
