#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ကိန်းပြည့် tab[TAB_SIZE];
ကိန်းပြည့် ret_sum;
var_na tab3[256];

ကိန်းပြည့် test1(void)
{
    ကိန်းပြည့် i, sum = 0;
    အတွက်(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ပြန်ပေး sum;
}

/* error */
ကိန်းပြည့် test2(void)
{
    ကိန်းပြည့် i, sum = 0;
    အတွက်(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ပြန်ပေး sum;
}

/* actually, profiling test */
ကိန်းပြည့် test3(void)
{
    ကိန်းပြည့် sum;
    ကိန်းပြည့် i, it;

    sum = 0;
    အတွက်(it=0;it<NB_ITS;it++) {
        အတွက်(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ပြန်ပေး sum;
}

/* ok */
ကိန်းပြည့် test4(void)
{
    ကိန်းပြည့် i, sum = 0;
    ကိန်းပြည့် *tab4;

    tab4 = malloc(20 * parimaa_na(ကိန်းပြည့်));
    အတွက်(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ပြန်ပေး sum;
}

/* error */
ကိန်းပြည့် test5(void)
{
    ကိန်းပြည့် i, sum = 0;
    ကိန်းပြည့် *tab4;

    tab4 = malloc(20 * parimaa_na(ကိန်းပြည့်));
    အတွက်(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ပြန်ပေး sum;
}

/* error */
ကိန်းပြည့် test6(void)
{
    ကိန်းပြည့် i, sum = 0;
    ကိန်းပြည့် *tab4;
    
    tab4 = malloc(20 * parimaa_na(ကိန်းပြည့်));
    free(tab4);
    အတွက်(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ပြန်ပေး sum;
}

/* error */
ကိန်းပြည့် test7(void)
{
    ကိန်းပြည့် i, sum = 0;
    ကိန်းပြည့် *p;

    အတွက်(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        အကယ်၍ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ပြန်ပေး sum;
}

/* ok */
ကိန်းပြည့် test8(void)
{
    ကိန်းပြည့် i, sum = 0;
    ကိန်းပြည့် tab[10];

    အတွက်(i=0;i<10;i++) {
        sum += tab[i];
    }
    ပြန်ပေး sum;
}

/* error */
ကိန်းပြည့် test9(void)
{
    ကိန်းပြည့် i, sum = 0;
    var_na tab[10];

    အတွက်(i=0;i<11;i++) {
        sum += tab[i];
    }
    ပြန်ပေး sum;
}

/* ok */
ကိန်းပြည့် test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ပြန်ပေး 0;
}

/* error */
ကိန်းပြည့် test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ပြန်ပေး 0;
}

/* error */
ကိန်းပြည့် test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ပြန်ပေး 0;
}

/* error */
ကိန်းပြည့် test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ပြန်ပေး strlen(tab);
}

ကိန်းပြည့် test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ပြန်ပေး ret;
}

/* error */
ကိန်းပြည့် test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ပြန်ပေး ret;
}

/* ok */
ကိန်းပြည့် test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ပြန်ပေး 0;
}

/* error */
ကိန်းပြည့် test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ပြန်ပေး 0;
}

ကိန်းပြည့် test18(void)
{
    ကိန်းပြည့် i, sum = 0, n = TAB_SIZE;
    ကိန်းပြည့် tab[n];
    အတွက်(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ပြန်ပေး sum;
}

ကိန်းပြည့် (*table_test[])(void) = {
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

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv)
{
    ကိန်းပြည့် i;
    var_na *cp;
    ကိန်းပြည့် index;
    ကိန်းပြည့် (*ftest)(void);
    ကိန်းပြည့် index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    အတွက် (i = 0; i < argc; i++) {
        cp = argv[i];
        နေစဉ် (*cp) {
            cp++;
        }
    }

    အကယ်၍ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    အကယ်၍ (argc >= 2)
        index = atoi(argv[1]) - 1;

    အကယ်၍ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ပြန်ပေး 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
