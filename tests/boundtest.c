#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

целое tab[TAB_SIZE];
целое ret_sum;
char tab3[256];

целое test1(void)
{
    целое i, sum = 0;
    для(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    вернуть sum;
}

/* error */
целое test2(void)
{
    целое i, sum = 0;
    для(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    вернуть sum;
}

/* actually, profiling test */
целое test3(void)
{
    целое sum;
    целое i, it;

    sum = 0;
    для(it=0;it<NB_ITS;it++) {
        для(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    вернуть sum;
}

/* ok */
целое test4(void)
{
    целое i, sum = 0;
    целое *tab4;

    tab4 = malloc(20 * sizeof(целое));
    для(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    вернуть sum;
}

/* error */
целое test5(void)
{
    целое i, sum = 0;
    целое *tab4;

    tab4 = malloc(20 * sizeof(целое));
    для(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    вернуть sum;
}

/* error */
целое test6(void)
{
    целое i, sum = 0;
    целое *tab4;
    
    tab4 = malloc(20 * sizeof(целое));
    free(tab4);
    для(i=0;i<21;i++) {
        sum += tab4[i];
    }

    вернуть sum;
}

/* error */
целое test7(void)
{
    целое i, sum = 0;
    целое *p;

    для(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        если (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    вернуть sum;
}

/* ok */
целое test8(void)
{
    целое i, sum = 0;
    целое tab[10];

    для(i=0;i<10;i++) {
        sum += tab[i];
    }
    вернуть sum;
}

/* error */
целое test9(void)
{
    целое i, sum = 0;
    char tab[10];

    для(i=0;i<11;i++) {
        sum += tab[i];
    }
    вернуть sum;
}

/* ok */
целое test10(void)
{
    char tab[10];
    char tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    вернуть 0;
}

/* error */
целое test11(void)
{
    char tab[10];

    memset(tab, 0, 11);
    вернуть 0;
}

/* error */
целое test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    вернуть 0;
}

/* error */
целое test13(void)
{
    char pad1 = 0;
    char tab[10];
    char pad2 = 0;
    memset(tab, 'a', sizeof(tab));
    вернуть strlen(tab);
}

целое test14(void)
{
    char *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    вернуть ret;
}

/* error */
целое test15(void)
{
    char *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    вернуть ret;
}

/* ok */
целое test16()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    вернуть 0;
}

/* error */
целое test17()
{
    char *demo = "This is only a test.";
    char *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    вернуть 0;
}

целое test18(void)
{
    целое i, sum = 0, n = TAB_SIZE;
    целое tab[n];
    для(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    вернуть sum;
}

целое (*table_test[])(void) = {
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

целое основной(целое argc, char **argv)
{
    целое i;
    char *cp;
    целое index;
    целое (*ftest)(void);
    целое index_max = sizeof(table_test)/sizeof(table_test[0]);

    /* check bounds checking main arg */
    для (i = 0; i < argc; i++) {
        cp = argv[i];
        пока (*cp) {
            cp++;
        }
    }

    если (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    если (argc >= 2)
        index = atoi(argv[1]) - 1;

    если ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    вернуть 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
