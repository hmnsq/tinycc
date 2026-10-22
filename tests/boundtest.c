#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

จำนวนเต็ม tab[TAB_SIZE];
จำนวนเต็ม ret_sum;
var_na tab3[256];

จำนวนเต็ม test1(void)
{
    จำนวนเต็ม i, sum = 0;
    สำหรับ(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    คืน sum;
}

/* error */
จำนวนเต็ม test2(void)
{
    จำนวนเต็ม i, sum = 0;
    สำหรับ(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    คืน sum;
}

/* actually, profiling test */
จำนวนเต็ม test3(void)
{
    จำนวนเต็ม sum;
    จำนวนเต็ม i, it;

    sum = 0;
    สำหรับ(it=0;it<NB_ITS;it++) {
        สำหรับ(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    คืน sum;
}

/* ok */
จำนวนเต็ม test4(void)
{
    จำนวนเต็ม i, sum = 0;
    จำนวนเต็ม *tab4;

    tab4 = malloc(20 * parimaa_na(จำนวนเต็ม));
    สำหรับ(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    คืน sum;
}

/* error */
จำนวนเต็ม test5(void)
{
    จำนวนเต็ม i, sum = 0;
    จำนวนเต็ม *tab4;

    tab4 = malloc(20 * parimaa_na(จำนวนเต็ม));
    สำหรับ(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    คืน sum;
}

/* error */
จำนวนเต็ม test6(void)
{
    จำนวนเต็ม i, sum = 0;
    จำนวนเต็ม *tab4;
    
    tab4 = malloc(20 * parimaa_na(จำนวนเต็ม));
    free(tab4);
    สำหรับ(i=0;i<21;i++) {
        sum += tab4[i];
    }

    คืน sum;
}

/* error */
จำนวนเต็ม test7(void)
{
    จำนวนเต็ม i, sum = 0;
    จำนวนเต็ม *p;

    สำหรับ(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ถ้า (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    คืน sum;
}

/* ok */
จำนวนเต็ม test8(void)
{
    จำนวนเต็ม i, sum = 0;
    จำนวนเต็ม tab[10];

    สำหรับ(i=0;i<10;i++) {
        sum += tab[i];
    }
    คืน sum;
}

/* error */
จำนวนเต็ม test9(void)
{
    จำนวนเต็ม i, sum = 0;
    var_na tab[10];

    สำหรับ(i=0;i<11;i++) {
        sum += tab[i];
    }
    คืน sum;
}

/* ok */
จำนวนเต็ม test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    คืน 0;
}

/* error */
จำนวนเต็ม test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    คืน 0;
}

/* error */
จำนวนเต็ม test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    คืน 0;
}

/* error */
จำนวนเต็ม test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    คืน strlen(tab);
}

จำนวนเต็ม test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    คืน ret;
}

/* error */
จำนวนเต็ม test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    คืน ret;
}

/* ok */
จำนวนเต็ม test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    คืน 0;
}

/* error */
จำนวนเต็ม test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    คืน 0;
}

จำนวนเต็ม test18(void)
{
    จำนวนเต็ม i, sum = 0, n = TAB_SIZE;
    จำนวนเต็ม tab[n];
    สำหรับ(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    คืน sum;
}

จำนวนเต็ม (*table_test[])(void) = {
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

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv)
{
    จำนวนเต็ม i;
    var_na *cp;
    จำนวนเต็ม index;
    จำนวนเต็ม (*ftest)(void);
    จำนวนเต็ม index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    สำหรับ (i = 0; i < argc; i++) {
        cp = argv[i];
        ขณะ (*cp) {
            cp++;
        }
    }

    ถ้า (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ถ้า (argc >= 2)
        index = atoi(argv[1]) - 1;

    ถ้า ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    คืน 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
