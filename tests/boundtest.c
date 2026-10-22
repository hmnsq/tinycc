#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

số_nguyên tab[TAB_SIZE];
số_nguyên ret_sum;
char tab3[256];

số_nguyên test1(void)
{
    số_nguyên i, sum = 0;
    cho(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    trả_về sum;
}

/* error */
số_nguyên test2(void)
{
    số_nguyên i, sum = 0;
    cho(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    trả_về sum;
}

/* actually, profiling test */
số_nguyên test3(void)
{
    số_nguyên sum;
    số_nguyên i, it;

    sum = 0;
    cho(it=0;it<NB_ITS;it++) {
        cho(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    trả_về sum;
}

/* ok */
số_nguyên test4(void)
{
    số_nguyên i, sum = 0;
    số_nguyên *tab4;

    tab4 = malloc(20 * sizeof(số_nguyên));
    cho(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    trả_về sum;
}

/* error */
số_nguyên test5(void)
{
    số_nguyên i, sum = 0;
    số_nguyên *tab4;

    tab4 = malloc(20 * sizeof(số_nguyên));
    cho(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    trả_về sum;
}

/* error */
số_nguyên test6(void)
{
    số_nguyên i, sum = 0;
    số_nguyên *tab4;
    
    tab4 = malloc(20 * sizeof(số_nguyên));
    free(tab4);
    cho(i=0;i<21;i++) {
        sum += tab4[i];
    }

    trả_về sum;
}

/* error */
số_nguyên test7(void)
{
    số_nguyên i, sum = 0;
    số_nguyên *p;

    cho(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        nếu (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    trả_về sum;
}

/* ok */
số_nguyên test8(void)
{
    số_nguyên i, sum = 0;
    số_nguyên tab[10];

    cho(i=0;i<10;i++) {
        sum += tab[i];
    }
    trả_về sum;
}

/* error */
số_nguyên test9(void)
{
    số_nguyên i, sum = 0;
    char tab[10];

    cho(i=0;i<11;i++) {
        sum += tab[i];
    }
    trả_về sum;
}

/* ok */
số_nguyên test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    trả_về 0;
}

/* error */
số_nguyên test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    trả_về 0;
}

/* error */
số_nguyên test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    trả_về 0;
}

/* error */
số_nguyên test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    trả_về strlen(tab);
}

số_nguyên test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    trả_về ret;
}

/* error */
số_nguyên test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    trả_về ret;
}

/* ok */
số_nguyên test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    trả_về 0;
}

/* error */
số_nguyên test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    trả_về 0;
}

số_nguyên test18(void)
{
    số_nguyên i, sum = 0, n = TAB_SIZE;
    số_nguyên tab[n];
    cho(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    trả_về sum;
}

số_nguyên (*table_test[])(void) = {
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

số_nguyên main(số_nguyên argc, char **argv)
{
    số_nguyên i;
    char *cp;
    số_nguyên index;
    số_nguyên (*ftest)(void);
    số_nguyên index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    cho (i = 0; i < argc; i++) {
        cp = argv[i];
        trong_khi (*cp) {
            cp++;
        }
    }

    nếu (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    nếu (argc >= 2)
        index = atoi(argv[1]) - 1;

    nếu ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    trả_về 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
