#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>

#تعریف_کن NB_ITS 1000000
//#define NB_ITS 1
#تعریف_کن TAB_اندازه 100

صحيح tab[TAB_اندازه];
صحيح ret_جمع;
حرف tab3[256];

صحيح test1(فراغ)
{
    صحيح i, جمع = 0;
    لكل(i=0;i<TAB_اندازه;i++) {
        جمع += tab[i];
    }
    أرجع جمع;
}

/* error */
صحيح test2(فراغ)
{
    صحيح i, جمع = 0;
    لكل(i=0;i<TAB_اندازه + 1;i++) {
        جمع += tab[i];
    }
    أرجع جمع;
}

/* actually, profiling test */
صحيح test3(فراغ)
{
    صحيح جمع;
    صحيح i, it;

    جمع = 0;
    لكل(it=0;it<NB_ITS;it++) {
        لكل(i=0;i<TAB_اندازه;i++) {
            جمع += tab[i];
        }
    }
    أرجع جمع;
}

/* ok */
صحيح test4(فراغ)
{
    صحيح i, جمع = 0;
    صحيح *tab4;

    tab4 = حافظه_بده(20 * حجم(صحيح));
    لكل(i=0;i<20;i++) {
        جمع += tab4[i];
    }
    حرر(tab4);

    أرجع جمع;
}

/* error */
صحيح test5(فراغ)
{
    صحيح i, جمع = 0;
    صحيح *tab4;

    tab4 = حافظه_بده(20 * حجم(صحيح));
    لكل(i=0;i<21;i++) {
        جمع += tab4[i];
    }
    حرر(tab4);

    أرجع جمع;
}

/* error */
صحيح test6(فراغ)
{
    صحيح i, جمع = 0;
    صحيح *tab4;
    
    tab4 = حافظه_بده(20 * حجم(صحيح));
    حرر(tab4);
    لكل(i=0;i<21;i++) {
        جمع += tab4[i];
    }

    أرجع جمع;
}

/* error */
صحيح test7(فراغ)
{
    صحيح i, جمع = 0;
    صحيح *p;

    لكل(i=0;i<TAB_اندازه + 1;i++) {
        p = &tab[i];
        إذا (i == TAB_اندازه)
            چاپ_کن("i=%d %x\n", i, p);
        جمع += *p;
    }
    أرجع جمع;
}

/* ok */
صحيح test8(فراغ)
{
    صحيح i, جمع = 0;
    صحيح tab[10];

    لكل(i=0;i<10;i++) {
        جمع += tab[i];
    }
    أرجع جمع;
}

/* error */
صحيح test9(فراغ)
{
    صحيح i, جمع = 0;
    حرف tab[10];

    لكل(i=0;i<11;i++) {
        جمع += tab[i];
    }
    أرجع جمع;
}

/* ok */
صحيح test10(فراغ)
{
    حرف tab[10];
    حرف tab1[10];

    memset(tab, 0, 10);
    کپی_حافظه(tab, tab1, 10);
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
    ptr = حافظه_بده(10);
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
    أرجع طول_رشته(tab);
}

صحيح test14(فراغ)
{
    حرف *p = alloca(TAB_اندازه);
    اندازه_t ret;
    memset(p, 'a', TAB_اندازه);
    p[TAB_اندازه-1] = 0;
    ret = طول_رشته(p);
    أرجع ret;
}

/* error */
صحيح test15(فراغ)
{
    حرف *p = alloca(TAB_اندازه-1);
    اندازه_t ret;
    memset(p, 'a', TAB_اندازه);
    p[TAB_اندازه-1] = 0;
    ret = طول_رشته(p);
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
    چاپ_کن("alloca : %s : %s\n", p, strcpy(q=alloca(طول_رشته(demo)+1),demo) );

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
    چاپ_کن("alloca : %s : %s\n", p, strcpy(q=alloca(طول_رشته(demo)),demo) );

    أرجع 0;
}

صحيح test18(فراغ)
{
    صحيح i, جمع = 0, n = TAB_اندازه;
    صحيح tab[n];
    لكل(i=0;i<TAB_اندازه+1;i++) {
        جمع += tab[i];
    }
    أرجع جمع;
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

صحيح اصلی(صحيح argc, حرف **argv)
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
        چاپ_کن(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", شاخص_max);
        خروج(1);
    }

    شاخص = 0;
    إذا (argc >= 2)
        شاخص = atoi(argv[1]) - 1;

    إذا ((شاخص < 0) || (شاخص >= شاخص_max)) {
        چاپ_کن("N is outside of the valid range (%d)\n", شاخص);
        خروج(2);
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
