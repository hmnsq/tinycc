#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

整数 tab[TAB_SIZE];
整数 ret_sum;
char tab3[256];

整数 test1(void)
{
    整数 i, sum = 0;
    为(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    返回 sum;
}

/* error */
整数 test2(void)
{
    整数 i, sum = 0;
    为(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    返回 sum;
}

/* actually, profiling test */
整数 test3(void)
{
    整数 sum;
    整数 i, it;

    sum = 0;
    为(it=0;it<NB_ITS;it++) {
        为(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    返回 sum;
}

/* ok */
整数 test4(void)
{
    整数 i, sum = 0;
    整数 *tab4;

    tab4 = malloc(20 * sizeof(整数));
    为(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    返回 sum;
}

/* error */
整数 test5(void)
{
    整数 i, sum = 0;
    整数 *tab4;

    tab4 = malloc(20 * sizeof(整数));
    为(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    返回 sum;
}

/* error */
整数 test6(void)
{
    整数 i, sum = 0;
    整数 *tab4;
    
    tab4 = malloc(20 * sizeof(整数));
    free(tab4);
    为(i=0;i<21;i++) {
        sum += tab4[i];
    }

    返回 sum;
}

/* error */
整数 test7(void)
{
    整数 i, sum = 0;
    整数 *p;

    为(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        如果 (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    返回 sum;
}

/* ok */
整数 test8(void)
{
    整数 i, sum = 0;
    整数 tab[10];

    为(i=0;i<10;i++) {
        sum += tab[i];
    }
    返回 sum;
}

/* error */
整数 test9(void)
{
    整数 i, sum = 0;
    char tab[10];

    为(i=0;i<11;i++) {
        sum += tab[i];
    }
    返回 sum;
}

/* ok */
整数 test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    返回 0;
}

/* error */
整数 test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    返回 0;
}

/* error */
整数 test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    返回 0;
}

/* error */
整数 test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    返回 strlen(tab);
}

整数 test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    返回 ret;
}

/* error */
整数 test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    返回 ret;
}

/* ok */
整数 test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    返回 0;
}

/* error */
整数 test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    返回 0;
}

整数 test18(void)
{
    整数 i, sum = 0, n = TAB_SIZE;
    整数 tab[n];
    为(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    返回 sum;
}

整数 (*table_test[])(void) = {
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

整数 主要(整数 argc, char **argv)
{
    整数 i;
    char *cp;
    整数 index;
    整数 (*ftest)(void);
    整数 index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    为 (i = 0; i < argc; i++) {
        cp = argv[i];
        当 (*cp) {
            cp++;
        }
    }

    如果 (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    如果 (argc >= 2)
        index = atoi(argv[1]) - 1;

    如果 ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    返回 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
