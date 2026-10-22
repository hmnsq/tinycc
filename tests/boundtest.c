#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>

#تعریف_کړه NB_ITS 1000000
//#define NB_ITS 1
#تعریف_کړه TAB_اندازه 100

صحيح tab[TAB_اندازه];
صحيح ret_مجموعه;
حرف tab3[256];

صحيح test1(فراغ)
{
    صحيح i, مجموعه = 0;
    لكل(i=0;i<TAB_اندازه;i++) {
        مجموعه += tab[i];
    }
    أرجع مجموعه;
}

/* error */
صحيح test2(فراغ)
{
    صحيح i, مجموعه = 0;
    لكل(i=0;i<TAB_اندازه + 1;i++) {
        مجموعه += tab[i];
    }
    أرجع مجموعه;
}

/* actually, profiling test */
صحيح test3(فراغ)
{
    صحيح مجموعه;
    صحيح i, it;

    مجموعه = 0;
    لكل(it=0;it<NB_ITS;it++) {
        لكل(i=0;i<TAB_اندازه;i++) {
            مجموعه += tab[i];
        }
    }
    أرجع مجموعه;
}

/* ok */
صحيح test4(فراغ)
{
    صحيح i, مجموعه = 0;
    صحيح *tab4;

    tab4 = حافظه_ورکړه(20 * حجم(صحيح));
    لكل(i=0;i<20;i++) {
        مجموعه += tab4[i];
    }
    حرر(tab4);

    أرجع مجموعه;
}

/* error */
صحيح test5(فراغ)
{
    صحيح i, مجموعه = 0;
    صحيح *tab4;

    tab4 = حافظه_ورکړه(20 * حجم(صحيح));
    لكل(i=0;i<21;i++) {
        مجموعه += tab4[i];
    }
    حرر(tab4);

    أرجع مجموعه;
}

/* error */
صحيح test6(فراغ)
{
    صحيح i, مجموعه = 0;
    صحيح *tab4;
    
    tab4 = حافظه_ورکړه(20 * حجم(صحيح));
    حرر(tab4);
    لكل(i=0;i<21;i++) {
        مجموعه += tab4[i];
    }

    أرجع مجموعه;
}

/* error */
صحيح test7(فراغ)
{
    صحيح i, مجموعه = 0;
    صحيح *p;

    لكل(i=0;i<TAB_اندازه + 1;i++) {
        p = &tab[i];
        إذا (i == TAB_اندازه)
            چاپ_کړه("i=%d %x\n", i, p);
        مجموعه += *p;
    }
    أرجع مجموعه;
}

/* ok */
صحيح test8(فراغ)
{
    صحيح i, مجموعه = 0;
    صحيح tab[10];

    لكل(i=0;i<10;i++) {
        مجموعه += tab[i];
    }
    أرجع مجموعه;
}

/* error */
صحيح test9(فراغ)
{
    صحيح i, مجموعه = 0;
    حرف tab[10];

    لكل(i=0;i<11;i++) {
        مجموعه += tab[i];
    }
    أرجع مجموعه;
}

/* ok */
صحيح test10(فراغ)
{
    حرف tab[10];
    حرف tab1[10];

    memset(tab, 0, 10);
    حافظه_نقل(tab, tab1, 10);
    memmove(tab, tab1, 10);
    أرجع 0;
}

/* error */
صحيح test11(فراغ)
{
    حرف tab[10];

    memset(tab, 0, 11);
    أرجع 0;
}

/* error */
صحيح test12(فراغ)
{
    فراغ *ptr;
    ptr = حافظه_ورکړه(10);
    حرر(ptr);
    حرر(ptr);
    أرجع 0;
}

/* error */
صحيح test13(فراغ)
{
    حرف pad1 = 0;
    حرف tab[10];
    حرف pad2 = 0;
    memset(tab, 'a', حجم(tab));
    أرجع مزي_اوږدوالی(tab);
}

صحيح test14(فراغ)
{
    حرف *p = alloca(TAB_اندازه);
    اندازه_t ret;
    memset(p, 'a', TAB_اندازه);
    p[TAB_اندازه-1] = 0;
    ret = مزي_اوږدوالی(p);
    أرجع ret;
}

/* error */
صحيح test15(فراغ)
{
    حرف *p = alloca(TAB_اندازه-1);
    اندازه_t ret;
    memset(p, 'a', TAB_اندازه);
    p[TAB_اندازه-1] = 0;
    ret = مزي_اوږدوالی(p);
    أرجع ret;
}

/* ok */
صحيح test16()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    چاپ_کړه("alloca : %s : %s\n", p, strcpy(q=alloca(مزي_اوږدوالی(demo)+1),demo) );

    أرجع 0;
}

/* error */
صحيح test17()
{
    حرف *demo = "This is only a test.";
    حرف *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    چاپ_کړه("alloca : %s : %s\n", p, strcpy(q=alloca(مزي_اوږدوالی(demo)),demo) );

    أرجع 0;
}

صحيح test18(فراغ)
{
    صحيح i, مجموعه = 0, n = TAB_اندازه;
    صحيح tab[n];
    لكل(i=0;i<TAB_اندازه+1;i++) {
        مجموعه += tab[i];
    }
    أرجع مجموعه;
}

صحيح (*جدول_test[])(فراغ) = {
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

صحيح اصلي(صحيح argc, حرف **argv)
{
    صحيح i;
    حرف *cp;
    صحيح شاخص;
    صحيح (*ftest)(فراغ);
    صحيح شاخص_max = حجم(جدول_test)/حجم(جدول_test[0]);

    /* check bounds checking main arg */
    لكل (i = 0; i < argc; i++) {
        cp = argv[i];
        طالما (*cp) {
            cp++;
        }
    }

    إذا (argc < 2) {
        چاپ_کړه(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", شاخص_max);
        وتل(1);
    }

    شاخص = 0;
    إذا (argc >= 2)
        شاخص = atoi(argv[1]) - 1;

    إذا ((شاخص < 0) || (شاخص >= شاخص_max)) {
        چاپ_کړه("N is outside of the valid range (%d)\n", شاخص);
        وتل(2);
    }

    /* well, we also use bounds on this ! */
    ftest = جدول_test[شاخص];
    ftest();

    أرجع 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
