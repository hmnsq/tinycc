#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

পূর্ণাঙ্ক tab[TAB_SIZE];
পূর্ণাঙ্ক ret_sum;
ৱর্ণ tab3[256];

পূর্ণাঙ্ক test1(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    বাবে(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    ঘূৰাই sum;
}

/* error */
পূর্ণাঙ্ক test2(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    বাবে(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    ঘূৰাই sum;
}

/* actually, profiling test */
পূর্ণাঙ্ক test3(শূন্য)
{
    পূর্ণাঙ্ক sum;
    পূর্ণাঙ্ক i, it;

    sum = 0;
    বাবে(it=0;it<NB_ITS;it++) {
        বাবে(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    ঘূৰাই sum;
}

/* ok */
পূর্ণাঙ্ক test4(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    পূর্ণাঙ্ক *tab4;

    tab4 = malloc(20 * পরিমাণ(পূর্ণাঙ্ক));
    বাবে(i=0;i<20;i++) {
        sum += tab4[i];
    }
    মুক্ত(tab4);

    ঘূৰাই sum;
}

/* error */
পূর্ণাঙ্ক test5(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    পূর্ণাঙ্ক *tab4;

    tab4 = malloc(20 * পরিমাণ(পূর্ণাঙ্ক));
    বাবে(i=0;i<21;i++) {
        sum += tab4[i];
    }
    মুক্ত(tab4);

    ঘূৰাই sum;
}

/* error */
পূর্ণাঙ্ক test6(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    পূর্ণাঙ্ক *tab4;
    
    tab4 = malloc(20 * পরিমাণ(পূর্ণাঙ্ক));
    মুক্ত(tab4);
    বাবে(i=0;i<21;i++) {
        sum += tab4[i];
    }

    ঘূৰাই sum;
}

/* error */
পূর্ণাঙ্ক test7(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    পূর্ণাঙ্ক *p;

    বাবে(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        যদি (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    ঘূৰাই sum;
}

/* ok */
পূর্ণাঙ্ক test8(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    পূর্ণাঙ্ক tab[10];

    বাবে(i=0;i<10;i++) {
        sum += tab[i];
    }
    ঘূৰাই sum;
}

/* error */
পূর্ণাঙ্ক test9(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0;
    ৱর্ণ tab[10];

    বাবে(i=0;i<11;i++) {
        sum += tab[i];
    }
    ঘূৰাই sum;
}

/* ok */
পূর্ণাঙ্ক test10(শূন্য)
{
    ৱর্ণ tab[10];
    ৱর্ণ tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ঘূৰাই 0;
}

/* error */
পূর্ণাঙ্ক test11(শূন্য)
{
    ৱর্ণ tab[10];

    memset(tab, 0, 11);
    ঘূৰাই 0;
}

/* error */
পূর্ণাঙ্ক test12(শূন্য)
{
    শূন্য *ptr;
    ptr = malloc(10);
    মুক্ত(ptr);
    মুক্ত(ptr);
    ঘূৰাই 0;
}

/* error */
পূর্ণাঙ্ক test13(শূন্য)
{
    ৱর্ণ pad1 = 0;
    ৱর্ণ tab[10];
    ৱর্ণ pad2 = 0;
    memset(tab, 'a', পরিমাণ(tab));
    ঘূৰাই strlen(tab);
}

পূর্ণাঙ্ক test14(শূন্য)
{
    ৱর্ণ *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ঘূৰাই ret;
}

/* error */
পূর্ণাঙ্ক test15(শূন্য)
{
    ৱর্ণ *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    ঘূৰাই ret;
}

/* ok */
পূর্ণাঙ্ক test16()
{
    ৱর্ণ *demo = "This is only a test.";
    ৱর্ণ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    ঘূৰাই 0;
}

/* error */
পূর্ণাঙ্ক test17()
{
    ৱর্ণ *demo = "This is only a test.";
    ৱর্ণ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    ঘূৰাই 0;
}

পূর্ণাঙ্ক test18(শূন্য)
{
    পূর্ণাঙ্ক i, sum = 0, n = TAB_SIZE;
    পূর্ণাঙ্ক tab[n];
    বাবে(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    ঘূৰাই sum;
}

পূর্ণাঙ্ক (*table_test[])(শূন্য) = {
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

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    পূর্ণাঙ্ক i;
    ৱর্ণ *cp;
    পূর্ণাঙ্ক index;
    পূর্ণাঙ্ক (*ftest)(শূন্য);
    পূর্ণাঙ্ক index_max = পরিমাণ(table_test)/পরিমাণ(table_test[0]);

    /* check bounds checking main arg */
    বাবে (i = 0; i < argc; i++) {
        cp = argv[i];
        যেতিয়ালৈ (*cp) {
            cp++;
        }
    }

    যদি (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    যদি (argc >= 2)
        index = atoi(argv[1]) - 1;

    যদি ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    ঘূৰাই 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
