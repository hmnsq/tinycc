#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ຈຳນວນເຕັມ tab[TAB_SIZE];
ຈຳນວນເຕັມ ret_sum;
var_na tab3[256];

ຈຳນວນເຕັມ test1(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ສຳລັບ(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ສົ່ງຄືນ sum;
}

/* error */
ຈຳນວນເຕັມ test2(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ສຳລັບ(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ສົ່ງຄືນ sum;
}

/* actually, profiling test */
ຈຳນວນເຕັມ test3(void)
{
    ຈຳນວນເຕັມ sum;
    ຈຳນວນເຕັມ i, it;

    sum = 0;
    ສຳລັບ(it=0;it<NB_ITS;it++) {
        ສຳລັບ(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ສົ່ງຄືນ sum;
}

/* ok */
ຈຳນວນເຕັມ test4(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ຈຳນວນເຕັມ *tab4;

    tab4 = malloc(20 * parimaa_na(ຈຳນວນເຕັມ));
    ສຳລັບ(i=0;i<20;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ສົ່ງຄືນ sum;
}

/* error */
ຈຳນວນເຕັມ test5(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ຈຳນວນເຕັມ *tab4;

    tab4 = malloc(20 * parimaa_na(ຈຳນວນເຕັມ));
    ສຳລັບ(i=0;i<21;i++) {
        sum += tab4[i];
    }
    free(tab4);

    ສົ່ງຄືນ sum;
}

/* error */
ຈຳນວນເຕັມ test6(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ຈຳນວນເຕັມ *tab4;
    
    tab4 = malloc(20 * parimaa_na(ຈຳນວນເຕັມ));
    free(tab4);
    ສຳລັບ(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ສົ່ງຄືນ sum;
}

/* error */
ຈຳນວນເຕັມ test7(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ຈຳນວນເຕັມ *p;

    ສຳລັບ(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ຖ້າ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ສົ່ງຄືນ sum;
}

/* ok */
ຈຳນວນເຕັມ test8(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    ຈຳນວນເຕັມ tab[10];

    ສຳລັບ(i=0;i<10;i++) {
        sum += tab[i];
    }
    ສົ່ງຄືນ sum;
}

/* error */
ຈຳນວນເຕັມ test9(void)
{
    ຈຳນວນເຕັມ i, sum = 0;
    var_na tab[10];

    ສຳລັບ(i=0;i<11;i++) {
        sum += tab[i];
    }
    ສົ່ງຄືນ sum;
}

/* ok */
ຈຳນວນເຕັມ test10(void)
{
    var_na tab[10];
    var_na tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ສົ່ງຄືນ 0;
}

/* error */
ຈຳນວນເຕັມ test11(void)
{
    var_na tab[10];

    memset(tab, 0, 11);
    ສົ່ງຄືນ 0;
}

/* error */
ຈຳນວນເຕັມ test12(void)
{
    void *ptr;
    ptr = malloc(10);
    free(ptr);
    free(ptr);
    ສົ່ງຄືນ 0;
}

/* error */
ຈຳນວນເຕັມ test13(void)
{
    var_na pad1 = 0;
    var_na tab[10];
    var_na pad2 = 0;
    memset(tab, 'a', parimaa_na(tab));
    ສົ່ງຄືນ strlen(tab);
}

ຈຳນວນເຕັມ test14(void)
{
    var_na *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ສົ່ງຄືນ ret;
}

/* error */
ຈຳນວນເຕັມ test15(void)
{
    var_na *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ສົ່ງຄືນ ret;
}

/* ok */
ຈຳນວນເຕັມ test16()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ສົ່ງຄືນ 0;
}

/* error */
ຈຳນວນເຕັມ test17()
{
    var_na *demo = "This is only a test.";
    var_na *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ test18(void)
{
    ຈຳນວນເຕັມ i, sum = 0, n = TAB_SIZE;
    ຈຳນວນເຕັມ tab[n];
    ສຳລັບ(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ສົ່ງຄືນ sum;
}

ຈຳນວນເຕັມ (*table_test[])(void) = {
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

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv)
{
    ຈຳນວນເຕັມ i;
    var_na *cp;
    ຈຳນວນເຕັມ index;
    ຈຳນວນເຕັມ (*ftest)(void);
    ຈຳນວນເຕັມ index_max = parimaa_na(table_test)/parimaa_na(table_test[0]);

    /* check bounds checking main arg */
    ສຳລັບ (i = 0; i < argc; i++) {
        cp = argv[i];
        ໃນຂະນະທີ່ (*cp) {
            cp++;
        }
    }

    ຖ້າ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ຖ້າ (argc >= 2)
        index = atoi(argv[1]) - 1;

    ຖ້າ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ສົ່ງຄືນ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
