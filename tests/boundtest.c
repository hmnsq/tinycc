#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>

#وصف_ڪريو NB_ITS 1000000
//#define NB_ITS 1
#وصف_ڪريو TAB_سائيز 100

صحيح tab[TAB_سائيز];
صحيح ret_جوڙ;
حرف tab3[256];

صحيح test1(فراغ)
{
    صحيح i, جوڙ = 0;
    لكل(i=0;i<TAB_سائيز;i++) {
        جوڙ += tab[i];
    }
    أرجع جوڙ;
}

/* error */
صحيح test2(فراغ)
{
    صحيح i, جوڙ = 0;
    لكل(i=0;i<TAB_سائيز + 1;i++) {
        جوڙ += tab[i];
    }
    أرجع جوڙ;
}

/* actually, profiling test */
صحيح test3(فراغ)
{
    صحيح جوڙ;
    صحيح i, it;

    جوڙ = 0;
    لكل(it=0;it<NB_ITS;it++) {
        لكل(i=0;i<TAB_سائيز;i++) {
            جوڙ += tab[i];
        }
    }
    أرجع جوڙ;
}

/* ok */
صحيح test4(فراغ)
{
    صحيح i, جوڙ = 0;
    صحيح *tab4;

    tab4 = يادگيري_ڏيو(20 * حجم(صحيح));
    لكل(i=0;i<20;i++) {
        جوڙ += tab4[i];
    }
    حرر(tab4);

    أرجع جوڙ;
}

/* error */
صحيح test5(فراغ)
{
    صحيح i, جوڙ = 0;
    صحيح *tab4;

    tab4 = يادگيري_ڏيو(20 * حجم(صحيح));
    لكل(i=0;i<21;i++) {
        جوڙ += tab4[i];
    }
    حرر(tab4);

    أرجع جوڙ;
}

/* error */
صحيح test6(فراغ)
{
    صحيح i, جوڙ = 0;
    صحيح *tab4;
    
    tab4 = يادگيري_ڏيو(20 * حجم(صحيح));
    حرر(tab4);
    لكل(i=0;i<21;i++) {
        جوڙ += tab4[i];
    }

    أرجع جوڙ;
}

/* error */
صحيح test7(فراغ)
{
    صحيح i, جوڙ = 0;
    صحيح *p;

    لكل(i=0;i<TAB_سائيز + 1;i++) {
        p = &tab[i];
        إذا (i == TAB_سائيز)
            لکو("i=%d %x\n", i, p);
        جوڙ += *p;
    }
    أرجع جوڙ;
}

/* ok */
صحيح test8(فراغ)
{
    صحيح i, جوڙ = 0;
    صحيح tab[10];

    لكل(i=0;i<10;i++) {
        جوڙ += tab[i];
    }
    أرجع جوڙ;
}

/* error */
صحيح test9(فراغ)
{
    صحيح i, جوڙ = 0;
    حرف tab[10];

    لكل(i=0;i<11;i++) {
        جوڙ += tab[i];
    }
    أرجع جوڙ;
}

/* ok */
صحيح test10(فراغ)
{
    حرف tab[10];
    حرف tab1[10];

    memset(tab, 0, 10);
    يادگيري_نقل(tab, tab1, 10);
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
    ptr = يادگيري_ڏيو(10);
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
    أرجع لڙي_ڊيگهه(tab);
}

صحيح test14(فراغ)
{
    حرف *p = alloca(TAB_سائيز);
    سائيز_t ret;
    memset(p, 'a', TAB_سائيز);
    p[TAB_سائيز-1] = 0;
    ret = لڙي_ڊيگهه(p);
    أرجع ret;
}

/* error */
صحيح test15(فراغ)
{
    حرف *p = alloca(TAB_سائيز-1);
    سائيز_t ret;
    memset(p, 'a', TAB_سائيز);
    p[TAB_سائيز-1] = 0;
    ret = لڙي_ڊيگهه(p);
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
    لکو("alloca : %s : %s\n", p, strcpy(q=alloca(لڙي_ڊيگهه(demo)+1),demo) );

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
    لکو("alloca : %s : %s\n", p, strcpy(q=alloca(لڙي_ڊيگهه(demo)),demo) );

    أرجع 0;
}

صحيح test18(فراغ)
{
    صحيح i, جوڙ = 0, n = TAB_سائيز;
    صحيح tab[n];
    لكل(i=0;i<TAB_سائيز+1;i++) {
        جوڙ += tab[i];
    }
    أرجع جوڙ;
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

صحيح مکيه(صحيح argc, حرف **argv)
{
    صحيح i;
    حرف *cp;
    صحيح اشاريو;
    صحيح (*ftest)(فراغ);
    صحيح اشاريو_max = حجم(جدول_test)/حجم(جدول_test[0]);

    /* check bounds checking main arg */
    لكل (i = 0; i < argc; i++) {
        cp = argv[i];
        طالما (*cp) {
            cp++;
        }
    }

    إذا (argc < 2) {
        لکو(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", اشاريو_max);
        ٻاهر_نڪرو(1);
    }

    اشاريو = 0;
    إذا (argc >= 2)
        اشاريو = atoi(argv[1]) - 1;

    إذا ((اشاريو < 0) || (اشاريو >= اشاريو_max)) {
        لکو("N is outside of the valid range (%d)\n", اشاريو);
        ٻاهر_نڪرو(2);
    }

    /* well, we also use bounds on this ! */
    ftest = جدول_test[اشاريو];
    ftest();

    أرجع 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
