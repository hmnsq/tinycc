#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

цео tab[TAB_SIZE];
цео ret_sum;
char tab3[256];

цео test1(void)
{
    цео i, sum = 0;
    за(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    врати sum;
}

/* error */
цео test2(void)
{
    цео i, sum = 0;
    за(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    врати sum;
}

/* actually, profiling test */
цео test3(void)
{
    цео sum;
    цео i, it;

    sum = 0;
    за(it=0;it<NB_ITS;it++) {
        за(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    врати sum;
}

/* ok */
цео test4(void)
{
    цео i, sum = 0;
    цео *tab4;

    tab4 = malloc(20 * sizeof(цео));
    за(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    врати sum;
}

/* error */
цео test5(void)
{
    цео i, sum = 0;
    цео *tab4;

    tab4 = malloc(20 * sizeof(цео));
    за(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    врати sum;
}

/* error */
цео test6(void)
{
    цео i, sum = 0;
    цео *tab4;
    
    tab4 = malloc(20 * sizeof(цео));
    free(tab4);
    за(i=0;i<21;i++) {
        sum += tab4[i];
    }

    врати sum;
}

/* error */
цео test7(void)
{
    цео i, sum = 0;
    цео *p;

    за(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ако (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    врати sum;
}

/* ok */
цео test8(void)
{
    цео i, sum = 0;
    цео tab[10];

    за(i=0;i<10;i++) {
        sum += tab[i];
    }
    врати sum;
}

/* error */
цео test9(void)
{
    цео i, sum = 0;
    char tab[10];

    за(i=0;i<11;i++) {
        sum += tab[i];
    }
    врати sum;
}

/* ok */
цео test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    врати 0;
}

/* error */
цео test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    врати 0;
}

/* error */
цео test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    врати 0;
}

/* error */
цео test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    врати strlen(tab);
}

цео test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    врати ret;
}

/* error */
цео test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    врати ret;
}

/* ok */
цео test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    врати 0;
}

/* error */
цео test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    врати 0;
}

цео test18(void)
{
    цео i, sum = 0, n = TAB_SIZE;
    цео tab[n];
    за(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    врати sum;
}

цео (*table_test[])(void) = {
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

цео main(цео argc, char **argv)
{
    цео i;
    char *cp;
    цео index;
    цео (*ftest)(void);
    цео index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    за (i = 0; i < argc; i++) {
        cp = argv[i];
        док (*cp) {
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

    врати 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
