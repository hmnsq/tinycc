#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ціле tab[TAB_SIZE];
ціле ret_sum;
char tab3[256];

ціле test1(void)
{
    ціле i, sum = 0;
    для(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    повернути sum;
}

/* error */
ціле test2(void)
{
    ціле i, sum = 0;
    для(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    повернути sum;
}

/* actually, profiling test */
ціле test3(void)
{
    ціле sum;
    ціле i, it;

    sum = 0;
    для(it=0;it<NB_ITS;it++) {
        для(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    повернути sum;
}

/* ok */
ціле test4(void)
{
    ціле i, sum = 0;
    ціле *tab4;

    tab4 = malloc(20 * sizeof(ціле));
    для(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    повернути sum;
}

/* error */
ціле test5(void)
{
    ціле i, sum = 0;
    ціле *tab4;

    tab4 = malloc(20 * sizeof(ціле));
    для(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    повернути sum;
}

/* error */
ціле test6(void)
{
    ціле i, sum = 0;
    ціле *tab4;
    
    tab4 = malloc(20 * sizeof(ціле));
    free(tab4);
    для(i=0;i<21;i++) {
        sum += tab4[i];
    }

    повернути sum;
}

/* error */
ціле test7(void)
{
    ціле i, sum = 0;
    ціле *p;

    для(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        якщо (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    повернути sum;
}

/* ok */
ціле test8(void)
{
    ціле i, sum = 0;
    ціле tab[10];

    для(i=0;i<10;i++) {
        sum += tab[i];
    }
    повернути sum;
}

/* error */
ціле test9(void)
{
    ціле i, sum = 0;
    char tab[10];

    для(i=0;i<11;i++) {
        sum += tab[i];
    }
    повернути sum;
}

/* ok */
ціле test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    повернути 0;
}

/* error */
ціле test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    повернути 0;
}

/* error */
ціле test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    повернути 0;
}

/* error */
ціле test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    повернути strlen(tab);
}

ціле test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    повернути ret;
}

/* error */
ціле test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    повернути ret;
}

/* ok */
ціле test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    повернути 0;
}

/* error */
ціле test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    повернути 0;
}

ціле test18(void)
{
    ціле i, sum = 0, n = TAB_SIZE;
    ціле tab[n];
    для(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    повернути sum;
}

ціле (*table_test[])(void) = {
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

ціле main(ціле argc, char **argv)
{
    ціле i;
    char *cp;
    ціле index;
    ціле (*ftest)(void);
    ціле index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    для (i = 0; i < argc; i++) {
        cp = argv[i];
        поки (*cp) {
            cp++;
        }
    }

    якщо (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    якщо (argc >= 2)
        index = atoi(argv[1]) - 1;

    якщо ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    повернути 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
