#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

صحيح tab[TAB_SIZE];
صحيح ret_sum;
حرف tab3[256];

صحيح test1(فراغ)
{
    صحيح i, sum = 0;
    لكل(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    أرجع sum;
}

/* error */
صحيح test2(فراغ)
{
    صحيح i, sum = 0;
    لكل(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    أرجع sum;
}

/* actually, profiling test */
صحيح test3(فراغ)
{
    صحيح sum;
    صحيح i, it;

    sum = 0;
    لكل(it=0;it<NB_ITS;it++) {
        لكل(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    أرجع sum;
}

/* ok */
صحيح test4(فراغ)
{
    صحيح i, sum = 0;
    صحيح *tab4;

    tab4 = malloc(20 * حجم(صحيح));
    لكل(i=0;i<20;i++) {
        sum += tab4[i];
    }
    حرر(tab4);

    أرجع sum;
}

/* error */
صحيح test5(فراغ)
{
    صحيح i, sum = 0;
    صحيح *tab4;

    tab4 = malloc(20 * حجم(صحيح));
    لكل(i=0;i<21;i++) {
        sum += tab4[i];
    }
    حرر(tab4);

    أرجع sum;
}

/* error */
صحيح test6(فراغ)
{
    صحيح i, sum = 0;
    صحيح *tab4;
    
    tab4 = malloc(20 * حجم(صحيح));
    حرر(tab4);
    لكل(i=0;i<21;i++) {
        sum += tab4[i];
    }

    أرجع sum;
}

/* error */
صحيح test7(فراغ)
{
    صحيح i, sum = 0;
    صحيح *p;

    لكل(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        𐡄𐡍 (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    أرجع sum;
}

/* ok */
صحيح test8(فراغ)
{
    صحيح i, sum = 0;
    صحيح tab[10];

    لكل(i=0;i<10;i++) {
        sum += tab[i];
    }
    أرجع sum;
}

/* error */
صحيح test9(فراغ)
{
    صحيح i, sum = 0;
    حرف tab[10];

    لكل(i=0;i<11;i++) {
        sum += tab[i];
    }
    أرجع sum;
}

/* ok */
صحيح test10(فراغ)
{
    حرف tab[10];
    حرف tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    أرجع 0;
}

/* error */
صحيح test11(فراغ)
{
    حرف tab[10];

    memset(tab, 0, 11);
    أرجع 0;
}

/* error */
صحيح test12(فراغ)
{
    فراغ *ptr;
    ptr = malloc(10);
    حرر(ptr);
    حرر(ptr);
    أرجع 0;
}

/* error */
صحيح test13(فراغ)
{
    حرف pad1 = 0;
    حرف tab[10];
    حرف pad2 = 0;
    memset(tab, 'a', حجم(tab));
    أرجع strlen(tab);
}

صحيح test14(فراغ)
{
    حرف *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    أرجع ret;
}

/* error */
صحيح test15(فراغ)
{
    حرف *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    أرجع ret;
}

/* ok */
صحيح test16()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    أرجع 0;
}

/* error */
صحيح test17()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    أرجع 0;
}

صحيح test18(فراغ)
{
    صحيح i, sum = 0, n = TAB_SIZE;
    صحيح tab[n];
    لكل(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    أرجع sum;
}

صحيح (*table_test[])(فراغ) = {
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

صحيح main(صحيح argc, حرف **argv)
{
    صحيح i;
    حرف *cp;
    صحيح index;
    صحيح (*ftest)(فراغ);
    صحيح index_max = حجم(table_test)/حجم(table_test[0]);

    /* check bounds checking main arg */
    لكل (i = 0; i < argc; i++) {
        cp = argv[i];
        طالما (*cp) {
            cp++;
        }
    }

    𐡄𐡍 (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    𐡄𐡍 (argc >= 2)
        index = atoi(argv[1]) - 1;

    𐡄𐡍 ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    أرجع 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
