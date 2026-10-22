#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

ಪೂರ್ಣಾಙ್ಕ tab[TAB_SIZE];
ಪೂರ್ಣಾಙ್ಕ ret_sum;
ವರ್ಣ tab3[256];

ಪೂರ್ಣಾಙ್ಕ test1(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪ್ರತಿ(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test2(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪ್ರತಿ(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* actually, profiling test */
ಪೂರ್ಣಾಙ್ಕ test3(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ sum;
    ಪೂರ್ಣಾಙ್ಕ i, it;

    sum = 0;
    ಪ್ರತಿ(it=0;it<NB_ITS;it++) {
        ಪ್ರತಿ(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* ok */
ಪೂರ್ಣಾಙ್ಕ test4(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪೂರ್ಣಾಙ್ಕ *tab4;

    tab4 = malloc(20 * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ಪ್ರತಿ(i=0;i<20;i++) {
        sum += tab4[i];
    }
    ಮುಕ್ತ(tab4);

    ಪ್ರತ್ಯಾಗಮ sum;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test5(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪೂರ್ಣಾಙ್ಕ *tab4;

    tab4 = malloc(20 * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ಪ್ರತಿ(i=0;i<21;i++) {
        sum += tab4[i];
    }
    ಮುಕ್ತ(tab4);

    ಪ್ರತ್ಯಾಗಮ sum;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test6(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪೂರ್ಣಾಙ್ಕ *tab4;
    
    tab4 = malloc(20 * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    ಮುಕ್ತ(tab4);
    ಪ್ರತಿ(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ಪ್ರತ್ಯಾಗಮ sum;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test7(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪೂರ್ಣಾಙ್ಕ *p;

    ಪ್ರತಿ(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        ಯದಿ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* ok */
ಪೂರ್ಣಾಙ್ಕ test8(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ಪೂರ್ಣಾಙ್ಕ tab[10];

    ಪ್ರತಿ(i=0;i<10;i++) {
        sum += tab[i];
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test9(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0;
    ವರ್ಣ tab[10];

    ಪ್ರತಿ(i=0;i<11;i++) {
        sum += tab[i];
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

/* ok */
ಪೂರ್ಣಾಙ್ಕ test10(ಶೂನ್ಯ)
{
    ವರ್ಣ tab[10];
    ವರ್ಣ tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test11(ಶೂನ್ಯ)
{
    ವರ್ಣ tab[10];

    memset(tab, 0, 11);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test12(ಶೂನ್ಯ)
{
    ಶೂನ್ಯ *ptr;
    ptr = malloc(10);
    ಮುಕ್ತ(ptr);
    ಮುಕ್ತ(ptr);
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test13(ಶೂನ್ಯ)
{
    ವರ್ಣ pad1 = 0;
    ವರ್ಣ tab[10];
    ವರ್ಣ pad2 = 0;
    memset(tab, 'a', ಪರಿಮಾಣ(tab));
    ಪ್ರತ್ಯಾಗಮ strlen(tab);
}

ಪೂರ್ಣಾಙ್ಕ test14(ಶೂನ್ಯ)
{
    ವರ್ಣ *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test15(ಶೂನ್ಯ)
{
    ವರ್ಣ *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ಪ್ರತ್ಯಾಗಮ ret;
}

/* ok */
ಪೂರ್ಣಾಙ್ಕ test16()
{
    ವರ್ಣ *demo = "This is only a test.";
    ವರ್ಣ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ಪ್ರತ್ಯಾಗಮ 0;
}

/* error */
ಪೂರ್ಣಾಙ್ಕ test17()
{
    ವರ್ಣ *demo = "This is only a test.";
    ವರ್ಣ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ test18(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i, sum = 0, n = TAB_SIZE;
    ಪೂರ್ಣಾಙ್ಕ tab[n];
    ಪ್ರತಿ(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ಪ್ರತ್ಯಾಗಮ sum;
}

ಪೂರ್ಣಾಙ್ಕ (*table_test[])(ಶೂನ್ಯ) = {
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

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ವರ್ಣ *cp;
    ಪೂರ್ಣಾಙ್ಕ index;
    ಪೂರ್ಣಾಙ್ಕ (*ftest)(ಶೂನ್ಯ);
    ಪೂರ್ಣಾಙ್ಕ index_max = ಪರಿಮಾಣ(table_test)/ಪರಿಮಾಣ(table_test[0]);

    /* check bounds checking main arg */
    ಪ್ರತಿ (i = 0; i < argc; i++) {
        cp = argv[i];
        ಯಾವತ್ (*cp) {
            cp++;
        }
    }

    ಯದಿ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    ಯದಿ (argc >= 2)
        index = atoi(argv[1]) - 1;

    ಯದಿ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ಪ್ರತ್ಯಾಗಮ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
