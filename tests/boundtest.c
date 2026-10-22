#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

정수 tab[TAB_SIZE];
정수 ret_sum;
char tab3[256];

정수 test1(void)
{
    정수 i, sum = 0;
    위해(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    반환 sum;
}

/* error */
정수 test2(void)
{
    정수 i, sum = 0;
    위해(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    반환 sum;
}

/* actually, profiling test */
정수 test3(void)
{
    정수 sum;
    정수 i, it;

    sum = 0;
    위해(it=0;it<NB_ITS;it++) {
        위해(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    반환 sum;
}

/* ok */
정수 test4(void)
{
    정수 i, sum = 0;
    정수 *tab4;

    tab4 = malloc(20 * sizeof(정수));
    위해(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    반환 sum;
}

/* error */
정수 test5(void)
{
    정수 i, sum = 0;
    정수 *tab4;

    tab4 = malloc(20 * sizeof(정수));
    위해(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    반환 sum;
}

/* error */
정수 test6(void)
{
    정수 i, sum = 0;
    정수 *tab4;
    
    tab4 = malloc(20 * sizeof(정수));
    free(tab4);
    위해(i=0;i<21;i++) {
        sum += tab4[i];
    }

    반환 sum;
}

/* error */
정수 test7(void)
{
    정수 i, sum = 0;
    정수 *p;

    위해(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        만약 (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    반환 sum;
}

/* ok */
정수 test8(void)
{
    정수 i, sum = 0;
    정수 tab[10];

    위해(i=0;i<10;i++) {
        sum += tab[i];
    }
    반환 sum;
}

/* error */
정수 test9(void)
{
    정수 i, sum = 0;
    char tab[10];

    위해(i=0;i<11;i++) {
        sum += tab[i];
    }
    반환 sum;
}

/* ok */
정수 test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    반환 0;
}

/* error */
정수 test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    반환 0;
}

/* error */
정수 test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    반환 0;
}

/* error */
정수 test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    반환 strlen(tab);
}

정수 test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    반환 ret;
}

/* error */
정수 test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    반환 ret;
}

/* ok */
정수 test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    반환 0;
}

/* error */
정수 test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    반환 0;
}

정수 test18(void)
{
    정수 i, sum = 0, n = TAB_SIZE;
    정수 tab[n];
    위해(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    반환 sum;
}

정수 (*table_test[])(void) = {
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

정수 main(정수 argc, char **argv)
{
    정수 i;
    char *cp;
    정수 index;
    정수 (*ftest)(void);
    정수 index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    위해 (i = 0; i < argc; i++) {
        cp = argv[i];
        동안 (*cp) {
            cp++;
        }
    }

    만약 (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    만약 (argc >= 2)
        index = atoi(argv[1]) - 1;

    만약 ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    반환 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
