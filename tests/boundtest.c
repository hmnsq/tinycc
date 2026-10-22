#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ចំនួនគត់ tab[TAB_SIZE];
ចំនួនគត់ ret_sum;
var_na tab3[256];

ចំនួនគត់ test1(void)
{
    ចំនួនគត់ i, sum = 0;
    សម្រាប់(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ត្រឡប់ sum;
}

/* error */
ចំនួនគត់ test2(void)
{
    ចំនួនគត់ i, sum = 0;
    សម្រាប់(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ត្រឡប់ sum;
}

/* actually, profiling test */
ចំនួនគត់ test3(void)
{
    ចំនួនគត់ sum;
    ចំនួនគត់ i, it;

    sum = 0;
    សម្រាប់(it=0;it<NB_ITS;it++) {
        សម្រាប់(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ត្រឡប់ sum;
}

/* ok */
ចំនួនគត់ test4(void)
{
    ចំនួនគត់ i, sum = 0;
    ចំនួនគត់ *tab4;

    tab4 = malloc(20 * parimaa_na(ចំនួនគត់));
    សម្រាប់(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ត្រឡប់ sum;
}

/* error */
ចំនួនគត់ test5(void)
{
    ចំនួនគត់ i, sum = 0;
    ចំនួនគត់ *tab4;

    tab4 = malloc(20 * parimaa_na(ចំនួនគត់));
    សម្រាប់(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ត្រឡប់ sum;
}

/* error */
ចំនួនគត់ test6(void)
{
    ចំនួនគត់ i, sum = 0;
    ចំនួនគត់ *tab4;
    
    tab4 = malloc(20 * parimaa_na(ចំនួនគត់));
    free(tab4);
    សម្រាប់(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ត្រឡប់ sum;
}

/* error */
ចំនួនគត់ test7(void)
{
    ចំនួនគត់ i, sum = 0;
    ចំនួនគត់ *p;

    សម្រាប់(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ប្រសិនបើ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ត្រឡប់ sum;
}

/* ok */
ចំនួនគត់ test8(void)
{
    ចំនួនគត់ i, sum = 0;
    ចំនួនគត់ tab[10];

    សម្រាប់(i=0;i<10;i++) {
        sum += tab[i];
    }
    ត្រឡប់ sum;
}

/* error */
ចំនួនគត់ test9(void)
{
    ចំនួនគត់ i, sum = 0;
    var_na tab[10];

    សម្រាប់(i=0;i<11;i++) {
        sum += tab[i];
    }
    ត្រឡប់ sum;
}

/* ok */
ចំនួនគត់ test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ត្រឡប់ 0;
}

/* error */
ចំនួនគត់ test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ត្រឡប់ 0;
}

/* error */
ចំនួនគត់ test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ត្រឡប់ 0;
}

/* error */
ចំនួនគត់ test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ត្រឡប់ strlen(tab);
}

ចំនួនគត់ test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ត្រឡប់ ret;
}

/* error */
ចំនួនគត់ test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ត្រឡប់ ret;
}

/* ok */
ចំនួនគត់ test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ត្រឡប់ 0;
}

/* error */
ចំនួនគត់ test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ត្រឡប់ 0;
}

ចំនួនគត់ test18(void)
{
    ចំនួនគត់ i, sum = 0, n = TAB_SIZE;
    ចំនួនគត់ tab[n];
    សម្រាប់(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ត្រឡប់ sum;
}

ចំនួនគត់ (*table_test[])(void) = {
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

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv)
{
    ចំនួនគត់ i;
    var_na *cp;
    ចំនួនគត់ index;
    ចំនួនគត់ (*ftest)(void);
    ចំនួនគត់ index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    សម្រាប់ (i = 0; i < argc; i++) {
        cp = argv[i];
        ខណៈពេល (*cp) {
            cp++;
        }
    }

    ប្រសិនបើ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ប្រសិនបើ (argc >= 2)
        index = atoi(argv[1]) - 1;

    ប្រសិនបើ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ត្រឡប់ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
