#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

цяло tab[TAB_SIZE];
цяло ret_sum;
char tab3[256];

цяло test1(void)
{
    цяло i, sum = 0;
    за(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    върни sum;
}

/* error */
цяло test2(void)
{
    цяло i, sum = 0;
    за(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    върни sum;
}

/* actually, profiling test */
цяло test3(void)
{
    цяло sum;
    цяло i, it;

    sum = 0;
    за(it=0;it<NB_ITS;it++) {
        за(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    върни sum;
}

/* ok */
цяло test4(void)
{
    цяло i, sum = 0;
    цяло *tab4;

    tab4 = malloc(20 * sizeof(цяло));
    за(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    върни sum;
}

/* error */
цяло test5(void)
{
    цяло i, sum = 0;
    цяло *tab4;

    tab4 = malloc(20 * sizeof(цяло));
    за(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    върни sum;
}

/* error */
цяло test6(void)
{
    цяло i, sum = 0;
    цяло *tab4;
    
    tab4 = malloc(20 * sizeof(цяло));
    free(tab4);
    за(i=0;i<21;i++) {
        sum += tab4[i];
    }

    върни sum;
}

/* error */
цяло test7(void)
{
    цяло i, sum = 0;
    цяло *p;

    за(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ако (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    върни sum;
}

/* ok */
цяло test8(void)
{
    цяло i, sum = 0;
    цяло tab[10];

    за(i=0;i<10;i++) {
        sum += tab[i];
    }
    върни sum;
}

/* error */
цяло test9(void)
{
    цяло i, sum = 0;
    char tab[10];

    за(i=0;i<11;i++) {
        sum += tab[i];
    }
    върни sum;
}

/* ok */
цяло test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    върни 0;
}

/* error */
цяло test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    върни 0;
}

/* error */
цяло test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    върни 0;
}

/* error */
цяло test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    върни strlen(tab);
}

цяло test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    върни ret;
}

/* error */
цяло test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    върни ret;
}

/* ok */
цяло test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    върни 0;
}

/* error */
цяло test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    върни 0;
}

цяло test18(void)
{
    цяло i, sum = 0, n = TAB_SIZE;
    цяло tab[n];
    за(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    върни sum;
}

цяло (*table_test[])(void) = {
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

цяло main(цяло argc, char **argv)
{
    цяло i;
    char *cp;
    цяло index;
    цяло (*ftest)(void);
    цяло index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    за (i = 0; i < argc; i++) {
        cp = argv[i];
        докато (*cp) {
            cp++;
        }
    }

    ако (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ако (argc >= 2)
        index = atoi(argv[1]) - 1;

    ако ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    върни 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
