#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ཧྲིལ tab[TAB_SIZE];
ཧྲིལ ret_sum;
var_na tab3[256];

ཧྲིལ test1(void)
{
    ཧྲིལ i, sum = 0;
    དོན་ལུ(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ལོག sum;
}

/* error */
ཧྲིལ test2(void)
{
    ཧྲིལ i, sum = 0;
    དོན་ལུ(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ལོག sum;
}

/* actually, profiling test */
ཧྲིལ test3(void)
{
    ཧྲིལ sum;
    ཧྲིལ i, it;

    sum = 0;
    དོན་ལུ(it=0;it<NB_ITS;it++) {
        དོན་ལུ(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ལོག sum;
}

/* ok */
ཧྲིལ test4(void)
{
    ཧྲིལ i, sum = 0;
    ཧྲིལ *tab4;

    tab4 = malloc(20 * parimaa_na(ཧྲིལ));
    དོན་ལུ(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ལོག sum;
}

/* error */
ཧྲིལ test5(void)
{
    ཧྲིལ i, sum = 0;
    ཧྲིལ *tab4;

    tab4 = malloc(20 * parimaa_na(ཧྲིལ));
    དོན་ལུ(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ལོག sum;
}

/* error */
ཧྲིལ test6(void)
{
    ཧྲིལ i, sum = 0;
    ཧྲིལ *tab4;
    
    tab4 = malloc(20 * parimaa_na(ཧྲིལ));
    free(tab4);
    དོན་ལུ(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ལོག sum;
}

/* error */
ཧྲིལ test7(void)
{
    ཧྲིལ i, sum = 0;
    ཧྲིལ *p;

    དོན་ལུ(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        གལ་སྲིད (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ལོག sum;
}

/* ok */
ཧྲིལ test8(void)
{
    ཧྲིལ i, sum = 0;
    ཧྲིལ tab[10];

    དོན་ལུ(i=0;i<10;i++) {
        sum += tab[i];
    }
    ལོག sum;
}

/* error */
ཧྲིལ test9(void)
{
    ཧྲིལ i, sum = 0;
    var_na tab[10];

    དོན་ལུ(i=0;i<11;i++) {
        sum += tab[i];
    }
    ལོག sum;
}

/* ok */
ཧྲིལ test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ལོག 0;
}

/* error */
ཧྲིལ test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ལོག 0;
}

/* error */
ཧྲིལ test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ལོག 0;
}

/* error */
ཧྲིལ test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ལོག strlen(tab);
}

ཧྲིལ test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ལོག ret;
}

/* error */
ཧྲིལ test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ལོག ret;
}

/* ok */
ཧྲིལ test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ལོག 0;
}

/* error */
ཧྲིལ test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ལོག 0;
}

ཧྲིལ test18(void)
{
    ཧྲིལ i, sum = 0, n = TAB_SIZE;
    ཧྲིལ tab[n];
    དོན་ལུ(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ལོག sum;
}

ཧྲིལ (*table_test[])(void) = {
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

ཧྲིལ main(ཧྲིལ argc, var_na **argv)
{
    ཧྲིལ i;
    var_na *cp;
    ཧྲིལ index;
    ཧྲིལ (*ftest)(void);
    ཧྲིལ index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    དོན་ལུ (i = 0; i < argc; i++) {
        cp = argv[i];
        སྐབས (*cp) {
            cp++;
        }
    }

    གལ་སྲིད (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    གལ་སྲིད (argc >= 2)
        index = atoi(argv[1]) - 1;

    གལ་སྲིད ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ལོག 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
