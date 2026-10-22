#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>

#تعریف_کرو NB_ITS 1000000
//#define NB_ITS 1
#تعریف_کرو TAB_سائز 100

صحیح tab[TAB_سائز];
صحیح ret_مجموع;
حرف tab3[256];

صحیح test1(خالی)
{
    صحیح i, مجموع = 0;
    برائے(i=0;i<TAB_سائز;i++) {
        مجموع += tab[i];
    }
    واپس مجموع;
}

/* error */
صحیح test2(خالی)
{
    صحیح i, مجموع = 0;
    برائے(i=0;i<TAB_سائز + 1;i++) {
        مجموع += tab[i];
    }
    واپس مجموع;
}

/* actually, profiling test */
صحیح test3(خالی)
{
    صحیح مجموع;
    صحیح i, it;

    مجموع = 0;
    برائے(it=0;it<NB_ITS;it++) {
        برائے(i=0;i<TAB_سائز;i++) {
            مجموع += tab[i];
        }
    }
    واپس مجموع;
}

/* ok */
صحیح test4(خالی)
{
    صحیح i, مجموع = 0;
    صحیح *tab4;

    tab4 = حافظہ_دو(20 * حجم(صحیح));
    برائے(i=0;i<20;i++) {
        مجموع += tab4[i];
    }
    آزاد(tab4);

    واپس مجموع;
}

/* error */
صحیح test5(خالی)
{
    صحیح i, مجموع = 0;
    صحیح *tab4;

    tab4 = حافظہ_دو(20 * حجم(صحیح));
    برائے(i=0;i<21;i++) {
        مجموع += tab4[i];
    }
    آزاد(tab4);

    واپس مجموع;
}

/* error */
صحیح test6(خالی)
{
    صحیح i, مجموع = 0;
    صحیح *tab4;
    
    tab4 = حافظہ_دو(20 * حجم(صحیح));
    آزاد(tab4);
    برائے(i=0;i<21;i++) {
        مجموع += tab4[i];
    }

    واپس مجموع;
}

/* error */
صحیح test7(خالی)
{
    صحیح i, مجموع = 0;
    صحیح *p;

    برائے(i=0;i<TAB_سائز + 1;i++) {
        p = &tab[i];
        اگر (i == TAB_سائز)
            لکھو("i=%d %x\n", i, p);
        مجموع += *p;
    }
    واپس مجموع;
}

/* ok */
صحیح test8(خالی)
{
    صحیح i, مجموع = 0;
    صحیح tab[10];

    برائے(i=0;i<10;i++) {
        مجموع += tab[i];
    }
    واپس مجموع;
}

/* error */
صحیح test9(خالی)
{
    صحیح i, مجموع = 0;
    حرف tab[10];

    برائے(i=0;i<11;i++) {
        مجموع += tab[i];
    }
    واپس مجموع;
}

/* ok */
صحیح test10(خالی)
{
    حرف tab[10];
    حرف tab1[10];

    memset(tab, 0, 10);
    حافظہ_نقل(tab, tab1, 10);
    memmove(tab, tab1, 10);
    واپس 0;
}

/* error */
صحیح test11(خالی)
{
    حرف tab[10];

    memset(tab, 0, 11);
    واپس 0;
}

/* error */
صحیح test12(خالی)
{
    خالی *ptr;
    ptr = حافظہ_دو(10);
    آزاد(ptr);
    آزاد(ptr);
    واپس 0;
}

/* error */
صحیح test13(خالی)
{
    حرف pad1 = 0;
    حرف tab[10];
    حرف pad2 = 0;
    memset(tab, 'a', حجم(tab));
    واپس لڑی_لمبائی(tab);
}

صحیح test14(خالی)
{
    حرف *p = alloca(TAB_سائز);
    سائز_t ret;
    memset(p, 'a', TAB_سائز);
    p[TAB_سائز-1] = 0;
    ret = لڑی_لمبائی(p);
    واپس ret;
}

/* error */
صحیح test15(خالی)
{
    حرف *p = alloca(TAB_سائز-1);
    سائز_t ret;
    memset(p, 'a', TAB_سائز);
    p[TAB_سائز-1] = 0;
    ret = لڑی_لمبائی(p);
    واپس ret;
}

/* ok */
صحیح test16()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    لکھو("alloca : %s : %s\n", p, strcpy(q=alloca(لڑی_لمبائی(demo)+1),demo) );

    واپس 0;
}

/* error */
صحیح test17()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    لکھو("alloca : %s : %s\n", p, strcpy(q=alloca(لڑی_لمبائی(demo)),demo) );

    واپس 0;
}

صحیح test18(خالی)
{
    صحیح i, مجموع = 0, n = TAB_سائز;
    صحیح tab[n];
    برائے(i=0;i<TAB_سائز+1;i++) {
        مجموع += tab[i];
    }
    واپس مجموع;
}

صحیح (*جدول_test[])(خالی) = {
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

صحیح مین(صحیح argc, حرف **argv)
{
    صحیح i;
    حرف *cp;
    صحیح اشاریہ;
    صحیح (*ftest)(خالی);
    صحیح اشاریہ_max = حجم(جدول_test)/حجم(جدول_test[0]);

    /* check bounds checking main arg */
    برائے (i = 0; i < argc; i++) {
        cp = argv[i];
        جب (*cp) {
            cp++;
        }
    }

    اگر (argc < 2) {
        لکھو(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", اشاریہ_max);
        باہر_نکلو(1);
    }

    اشاریہ = 0;
    اگر (argc >= 2)
        اشاریہ = atoi(argv[1]) - 1;

    اگر ((اشاریہ < 0) || (اشاریہ >= اشاریہ_max)) {
        لکھو("N is outside of the valid range (%d)\n", اشاریہ);
        باہر_نکلو(2);
    }

    /* well, we also use bounds on this ! */
    ftest = جدول_test[اشاریہ];
    ftest();

    واپس 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
