#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

صحیح tab[TAB_SIZE];
صحیح ret_sum;
نویسه tab3[256];

صحیح test1(تهی)
{
    صحیح i, sum = 0;
    برای(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    بازگشت sum;
}

/* error */
صحیح test2(تهی)
{
    صحیح i, sum = 0;
    برای(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    بازگشت sum;
}

/* actually, profiling test */
صحیح test3(تهی)
{
    صحیح sum;
    صحیح i, it;

    sum = 0;
    برای(it=0;it<NB_ITS;it++) {
        برای(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    بازگشت sum;
}

/* ok */
صحیح test4(تهی)
{
    صحیح i, sum = 0;
    صحیح *tab4;

    tab4 = malloc(20 * اندازه(صحیح));
    برای(i=0;i<20;i++) {
        sum += tab4[i];
    }
    آزاد(tab4);

    بازگشت sum;
}

/* error */
صحیح test5(تهی)
{
    صحیح i, sum = 0;
    صحیح *tab4;

    tab4 = malloc(20 * اندازه(صحیح));
    برای(i=0;i<21;i++) {
        sum += tab4[i];
    }
    آزاد(tab4);

    بازگشت sum;
}

/* error */
صحیح test6(تهی)
{
    صحیح i, sum = 0;
    صحیح *tab4;
    
    tab4 = malloc(20 * اندازه(صحیح));
    آزاد(tab4);
    برای(i=0;i<21;i++) {
        sum += tab4[i];
    }

    بازگشت sum;
}

/* error */
صحیح test7(تهی)
{
    صحیح i, sum = 0;
    صحیح *p;

    برای(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        اگر (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    بازگشت sum;
}

/* ok */
صحیح test8(تهی)
{
    صحیح i, sum = 0;
    صحیح tab[10];

    برای(i=0;i<10;i++) {
        sum += tab[i];
    }
    بازگشت sum;
}

/* error */
صحیح test9(تهی)
{
    صحیح i, sum = 0;
    نویسه tab[10];

    برای(i=0;i<11;i++) {
        sum += tab[i];
    }
    بازگشت sum;
}

/* ok */
صحیح test10(تهی)
{
    نویسه tab[10];
    نویسه tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    بازگشت 0;
}

/* error */
صحیح test11(تهی)
{
    نویسه tab[10];

    memset(tab, 0, 11);
    بازگشت 0;
}

/* error */
صحیح test12(تهی)
{
    تهی *ptr;
    ptr = malloc(10);
    آزاد(ptr);
    آزاد(ptr);
    بازگشت 0;
}

/* error */
صحیح test13(تهی)
{
    نویسه pad1 = 0;
    نویسه tab[10];
    نویسه pad2 = 0;
    memset(tab, 'a', اندازه(tab));
    بازگشت strlen(tab);
}

صحیح test14(تهی)
{
    نویسه *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    بازگشت ret;
}

/* error */
صحیح test15(تهی)
{
    نویسه *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    بازگشت ret;
}

/* ok */
صحیح test16()
{
    نویسه *demo = "This is only a test.";
    نویسه *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    بازگشت 0;
}

/* error */
صحیح test17()
{
    نویسه *demo = "This is only a test.";
    نویسه *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    بازگشت 0;
}

صحیح test18(تهی)
{
    صحیح i, sum = 0, n = TAB_SIZE;
    صحیح tab[n];
    برای(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    بازگشت sum;
}

صحیح (*table_test[])(تهی) = {
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

صحیح اصلی(صحیح argc, نویسه **argv)
{
    صحیح i;
    نویسه *cp;
    صحیح index;
    صحیح (*ftest)(تهی);
    صحیح index_max = اندازه(table_test)/اندازه(table_test[0]);

    /* check bounds checking main arg */
    برای (i = 0; i < argc; i++) {
        cp = argv[i];
        وقتی (*cp) {
            cp++;
        }
    }

    اگر (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    اگر (argc >= 2)
        index = atoi(argv[1]) - 1;

    اگر ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    بازگشت 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
