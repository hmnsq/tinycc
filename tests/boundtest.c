#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

puur_naa_nka tab[TAB_SIZE];
puur_naa_nka ret_sum;
var_na tab3[256];

puur_naa_nka test1(void)
{
    puur_naa_nka i, sum = 0;
    for(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ᯀᯮᯞ sum;
}

/* error */
puur_naa_nka test2(void)
{
    puur_naa_nka i, sum = 0;
    for(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ᯀᯮᯞ sum;
}

/* actually, profiling test */
puur_naa_nka test3(void)
{
    puur_naa_nka sum;
    puur_naa_nka i, it;

    sum = 0;
    for(it=0;it<NB_ITS;it++) {
        for(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ᯀᯮᯞ sum;
}

/* ok */
puur_naa_nka test4(void)
{
    puur_naa_nka i, sum = 0;
    puur_naa_nka *tab4;

    tab4 = malloc(20 * parimaa_na(puur_naa_nka));
    for(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ᯀᯮᯞ sum;
}

/* error */
puur_naa_nka test5(void)
{
    puur_naa_nka i, sum = 0;
    puur_naa_nka *tab4;

    tab4 = malloc(20 * parimaa_na(puur_naa_nka));
    for(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ᯀᯮᯞ sum;
}

/* error */
puur_naa_nka test6(void)
{
    puur_naa_nka i, sum = 0;
    puur_naa_nka *tab4;
    
    tab4 = malloc(20 * parimaa_na(puur_naa_nka));
    free(tab4);
    for(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ᯀᯮᯞ sum;
}

/* error */
puur_naa_nka test7(void)
{
    puur_naa_nka i, sum = 0;
    puur_naa_nka *p;

    for(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ᯀᯮᯝ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ᯀᯮᯞ sum;
}

/* ok */
puur_naa_nka test8(void)
{
    puur_naa_nka i, sum = 0;
    puur_naa_nka tab[10];

    for(i=0;i<10;i++) {
        sum += tab[i];
    }
    ᯀᯮᯞ sum;
}

/* error */
puur_naa_nka test9(void)
{
    puur_naa_nka i, sum = 0;
    var_na tab[10];

    for(i=0;i<11;i++) {
        sum += tab[i];
    }
    ᯀᯮᯞ sum;
}

/* ok */
puur_naa_nka test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ᯀᯮᯞ 0;
}

/* error */
puur_naa_nka test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ᯀᯮᯞ 0;
}

/* error */
puur_naa_nka test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ᯀᯮᯞ 0;
}

/* error */
puur_naa_nka test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ᯀᯮᯞ strlen(tab);
}

puur_naa_nka test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ᯀᯮᯞ ret;
}

/* error */
puur_naa_nka test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ᯀᯮᯞ ret;
}

/* ok */
puur_naa_nka test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ᯀᯮᯞ 0;
}

/* error */
puur_naa_nka test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ᯀᯮᯞ 0;
}

puur_naa_nka test18(void)
{
    puur_naa_nka i, sum = 0, n = TAB_SIZE;
    puur_naa_nka tab[n];
    for(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ᯀᯮᯞ sum;
}

puur_naa_nka (*table_test[])(void) = {
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

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    puur_naa_nka i;
    var_na *cp;
    puur_naa_nka index;
    puur_naa_nka (*ftest)(void);
    puur_naa_nka index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    for (i = 0; i < argc; i++) {
        cp = argv[i];
        ᯀᯬᯝ (*cp) {
            cp++;
        }
    }

    ᯀᯮᯝ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ᯀᯮᯝ (argc >= 2)
        index = atoi(argv[1]) - 1;

    ᯀᯮᯝ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ᯀᯮᯞ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
