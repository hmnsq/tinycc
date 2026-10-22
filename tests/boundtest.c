#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

முழு tab[TAB_SIZE];
முழு ret_sum;
எழுத்து tab3[256];

முழு test1(வெறுமை)
{
    முழு i, sum = 0;
    க்கு(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    திரும்பு sum;
}

/* error */
முழு test2(வெறுமை)
{
    முழு i, sum = 0;
    க்கு(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    திரும்பு sum;
}

/* actually, profiling test */
முழு test3(வெறுமை)
{
    முழு sum;
    முழு i, it;

    sum = 0;
    க்கு(it=0;it<NB_ITS;it++) {
        க்கு(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    திரும்பு sum;
}

/* ok */
முழு test4(வெறுமை)
{
    முழு i, sum = 0;
    முழு *tab4;

    tab4 = malloc(20 * அளவு(முழு));
    க்கு(i=0;i<20;i++) {
        sum += tab4[i];
    }
    விடுவி(tab4);

    திரும்பு sum;
}

/* error */
முழு test5(வெறுமை)
{
    முழு i, sum = 0;
    முழு *tab4;

    tab4 = malloc(20 * அளவு(முழு));
    க்கு(i=0;i<21;i++) {
        sum += tab4[i];
    }
    விடுவி(tab4);

    திரும்பு sum;
}

/* error */
முழு test6(வெறுமை)
{
    முழு i, sum = 0;
    முழு *tab4;
    
    tab4 = malloc(20 * அளவு(முழு));
    விடுவி(tab4);
    க்கு(i=0;i<21;i++) {
        sum += tab4[i];
    }

    திரும்பு sum;
}

/* error */
முழு test7(வெறுமை)
{
    முழு i, sum = 0;
    முழு *p;

    க்கு(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        எனில் (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    திரும்பு sum;
}

/* ok */
முழு test8(வெறுமை)
{
    முழு i, sum = 0;
    முழு tab[10];

    க்கு(i=0;i<10;i++) {
        sum += tab[i];
    }
    திரும்பு sum;
}

/* error */
முழு test9(வெறுமை)
{
    முழு i, sum = 0;
    எழுத்து tab[10];

    க்கு(i=0;i<11;i++) {
        sum += tab[i];
    }
    திரும்பு sum;
}

/* ok */
முழு test10(வெறுமை)
{
    எழுத்து tab[10];
    எழுத்து tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    திரும்பு 0;
}

/* error */
முழு test11(வெறுமை)
{
    எழுத்து tab[10];

    memset(tab, 0, 11);
    திரும்பு 0;
}

/* error */
முழு test12(வெறுமை)
{
    வெறுமை *ptr;
    ptr = malloc(10);
    விடுவி(ptr);
    விடுவி(ptr);
    திரும்பு 0;
}

/* error */
முழு test13(வெறுமை)
{
    எழுத்து pad1 = 0;
    எழுத்து tab[10];
    எழுத்து pad2 = 0;
    memset(tab, 'a', அளவு(tab));
    திரும்பு strlen(tab);
}

முழு test14(வெறுமை)
{
    எழுத்து *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    திரும்பு ret;
}

/* error */
முழு test15(வெறுமை)
{
    எழுத்து *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    திரும்பு ret;
}

/* ok */
முழு test16()
{
    எழுத்து *demo = "This is only a test.";
    எழுத்து *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    திரும்பு 0;
}

/* error */
முழு test17()
{
    எழுத்து *demo = "This is only a test.";
    எழுத்து *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    திரும்பு 0;
}

முழு test18(வெறுமை)
{
    முழு i, sum = 0, n = TAB_SIZE;
    முழு tab[n];
    க்கு(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    திரும்பு sum;
}

முழு (*table_test[])(வெறுமை) = {
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

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    முழு i;
    எழுத்து *cp;
    முழு index;
    முழு (*ftest)(வெறுமை);
    முழு index_max = அளவு(table_test)/அளவு(table_test[0]);

    /* check bounds checking main arg */
    க்கு (i = 0; i < argc; i++) {
        cp = argv[i];
        போது (*cp) {
            cp++;
        }
    }

    எனில் (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    எனில் (argc >= 2)
        index = atoi(argv[1]) - 1;

    எனில் ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    திரும்பு 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
