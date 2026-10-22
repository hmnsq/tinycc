#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

පූර්ණ_සංඛ්‍යා tab[TAB_SIZE];
පූර්ණ_සංඛ්‍යා ret_sum;
var_na tab3[256];

පූර්ණ_සංඛ්‍යා test1(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    සඳහා(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ආපසු sum;
}

/* error */
පූර්ණ_සංඛ්‍යා test2(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    සඳහා(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ආපසු sum;
}

/* actually, profiling test */
පූර්ණ_සංඛ්‍යා test3(void)
{
    පූර්ණ_සංඛ්‍යා sum;
    පූර්ණ_සංඛ්‍යා i, it;

    sum = 0;
    සඳහා(it=0;it<NB_ITS;it++) {
        සඳහා(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ආපසු sum;
}

/* ok */
පූර්ණ_සංඛ්‍යා test4(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    පූර්ණ_සංඛ්‍යා *tab4;

    tab4 = malloc(20 * parimaa_na(පූර්ණ_සංඛ්‍යා));
    සඳහා(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ආපසු sum;
}

/* error */
පූර්ණ_සංඛ්‍යා test5(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    පූර්ණ_සංඛ්‍යා *tab4;

    tab4 = malloc(20 * parimaa_na(පූර්ණ_සංඛ්‍යා));
    සඳහා(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ආපසු sum;
}

/* error */
පූර්ණ_සංඛ්‍යා test6(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    පූර්ණ_සංඛ්‍යා *tab4;
    
    tab4 = malloc(20 * parimaa_na(පූර්ණ_සංඛ්‍යා));
    free(tab4);
    සඳහා(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ආපසු sum;
}

/* error */
පූර්ණ_සංඛ්‍යා test7(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    පූර්ණ_සංඛ්‍යා *p;

    සඳහා(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        නම් (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ආපසු sum;
}

/* ok */
පූර්ණ_සංඛ්‍යා test8(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    පූර්ණ_සංඛ්‍යා tab[10];

    සඳහා(i=0;i<10;i++) {
        sum += tab[i];
    }
    ආපසු sum;
}

/* error */
පූර්ණ_සංඛ්‍යා test9(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0;
    var_na tab[10];

    සඳහා(i=0;i<11;i++) {
        sum += tab[i];
    }
    ආපසු sum;
}

/* ok */
පූර්ණ_සංඛ්‍යා test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ආපසු 0;
}

/* error */
පූර්ණ_සංඛ්‍යා test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ආපසු 0;
}

/* error */
පූර්ණ_සංඛ්‍යා test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ආපසු 0;
}

/* error */
පූර්ණ_සංඛ්‍යා test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ආපසු strlen(tab);
}

පූර්ණ_සංඛ්‍යා test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ආපසු ret;
}

/* error */
පූර්ණ_සංඛ්‍යා test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ආපසු ret;
}

/* ok */
පූර්ණ_සංඛ්‍යා test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ආපසු 0;
}

/* error */
පූර්ණ_සංඛ්‍යා test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ආපසු 0;
}

පූර්ණ_සංඛ්‍යා test18(void)
{
    පූර්ණ_සංඛ්‍යා i, sum = 0, n = TAB_SIZE;
    පූර්ණ_සංඛ්‍යා tab[n];
    සඳහා(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ආපසු sum;
}

පූර්ණ_සංඛ්‍යා (*table_test[])(void) = {
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

පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv)
{
    පූර්ණ_සංඛ්‍යා i;
    var_na *cp;
    පූර්ණ_සංඛ්‍යා index;
    පූර්ණ_සංඛ්‍යා (*ftest)(void);
    පූර්ණ_සංඛ්‍යා index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    සඳහා (i = 0; i < argc; i++) {
        cp = argv[i];
        අතරතුර (*cp) {
            cp++;
        }
    }

    නම් (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    නම් (argc >= 2)
        index = atoi(argv[1]) - 1;

    නම් ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ආපසු 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
