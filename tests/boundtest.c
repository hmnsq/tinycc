#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

પૂર્ણાંક tab[TAB_SIZE];
પૂર્ણાંક ret_sum;
અક્ષર tab3[256];

પૂર્ણાંક test1(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    માટે(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    પાછા sum;
}

/* error */
પૂર્ણાંક test2(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    માટે(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    પાછા sum;
}

/* actually, profiling test */
પૂર્ણાંક test3(શૂન્ય)
{
    પૂર્ણાંક sum;
    પૂર્ણાંક i, it;

    sum = 0;
    માટે(it=0;it<NB_ITS;it++) {
        માટે(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    પાછા sum;
}

/* ok */
પૂર્ણાંક test4(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    પૂર્ણાંક *tab4;

    tab4 = malloc(20 * કદ(પૂર્ણાંક));
    માટે(i=0;i<20;i++) {
        sum += tab4[i];
    }
    મુક્ત(tab4);

    પાછા sum;
}

/* error */
પૂર્ણાંક test5(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    પૂર્ણાંક *tab4;

    tab4 = malloc(20 * કદ(પૂર્ણાંક));
    માટે(i=0;i<21;i++) {
        sum += tab4[i];
    }
    મુક્ત(tab4);

    પાછા sum;
}

/* error */
પૂર્ણાંક test6(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    પૂર્ણાંક *tab4;
    
    tab4 = malloc(20 * કદ(પૂર્ણાંક));
    મુક્ત(tab4);
    માટે(i=0;i<21;i++) {
        sum += tab4[i];
    }

    પાછા sum;
}

/* error */
પૂર્ણાંક test7(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    પૂર્ણાંક *p;

    માટે(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        જો (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    પાછા sum;
}

/* ok */
પૂર્ણાંક test8(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    પૂર્ણાંક tab[10];

    માટે(i=0;i<10;i++) {
        sum += tab[i];
    }
    પાછા sum;
}

/* error */
પૂર્ણાંક test9(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0;
    અક્ષર tab[10];

    માટે(i=0;i<11;i++) {
        sum += tab[i];
    }
    પાછા sum;
}

/* ok */
પૂર્ણાંક test10(શૂન્ય)
{
    અક્ષર tab[10];
    અક્ષર tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    પાછા 0;
}

/* error */
પૂર્ણાંક test11(શૂન્ય)
{
    અક્ષર tab[10];

    memset(tab, 0, 11);
    પાછા 0;
}

/* error */
પૂર્ણાંક test12(શૂન્ય)
{
    શૂન્ય *ptr;
    ptr = malloc(10);
    મુક્ત(ptr);
    મુક્ત(ptr);
    પાછા 0;
}

/* error */
પૂર્ણાંક test13(શૂન્ય)
{
    અક્ષર pad1 = 0;
    અક્ષર tab[10];
    અક્ષર pad2 = 0;
    memset(tab, 'a', કદ(tab));
    પાછા strlen(tab);
}

પૂર્ણાંક test14(શૂન્ય)
{
    અક્ષર *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    પાછા ret;
}

/* error */
પૂર્ણાંક test15(શૂન્ય)
{
    અક્ષર *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    પાછા ret;
}

/* ok */
પૂર્ણાંક test16()
{
    અક્ષર *demo = "This is only a test.";
    અક્ષર *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    પાછા 0;
}

/* error */
પૂર્ણાંક test17()
{
    અક્ષર *demo = "This is only a test.";
    અક્ષર *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    પાછા 0;
}

પૂર્ણાંક test18(શૂન્ય)
{
    પૂર્ણાંક i, sum = 0, n = TAB_SIZE;
    પૂર્ણાંક tab[n];
    માટે(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    પાછા sum;
}

પૂર્ણાંક (*table_test[])(શૂન્ય) = {
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

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક i;
    અક્ષર *cp;
    પૂર્ણાંક index;
    પૂર્ણાંક (*ftest)(શૂન્ય);
    પૂર્ણાંક index_max = કદ(table_test)/કદ(table_test[0]);

    /* check bounds checking main arg */
    માટે (i = 0; i < argc; i++) {
        cp = argv[i];
        જ્યારે (*cp) {
            cp++;
        }
    }

    જો (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    જો (argc >= 2)
        index = atoi(argv[1]) - 1;

    જો ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    પાછા 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
