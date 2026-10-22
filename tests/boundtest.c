#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ITS 1000000
//#define NB_ITS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TAB_ਮਾਪ 100

ਪੂਰਨ tab[TAB_ਮਾਪ];
ਪੂਰਨ ret_ਜੋੜ;
ਅੱਖਰ tab3[256];

ਪੂਰਨ test1(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਲਈ(i=0;i<TAB_ਮਾਪ;i++) {
        ਜੋੜ += tab[i];
    }
    ਵਾਪਸ ਜੋੜ;
}

/* error */
ਪੂਰਨ test2(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਲਈ(i=0;i<TAB_ਮਾਪ + 1;i++) {
        ਜੋੜ += tab[i];
    }
    ਵਾਪਸ ਜੋੜ;
}

/* actually, profiling test */
ਪੂਰਨ test3(ਖਾਲੀ)
{
    ਪੂਰਨ ਜੋੜ;
    ਪੂਰਨ i, it;

    ਜੋੜ = 0;
    ਲਈ(it=0;it<NB_ITS;it++) {
        ਲਈ(i=0;i<TAB_ਮਾਪ;i++) {
            ਜੋੜ += tab[i];
        }
    }
    ਵਾਪਸ ਜੋੜ;
}

/* ok */
ਪੂਰਨ test4(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਪੂਰਨ *tab4;

    tab4 = ਸਮ੍ਰਿਤੀ_ਦਿਓ(20 * ਆਕਾਰ(ਪੂਰਨ));
    ਲਈ(i=0;i<20;i++) {
        ਜੋੜ += tab4[i];
    }
    ਮੁਕਤ(tab4);

    ਵਾਪਸ ਜੋੜ;
}

/* error */
ਪੂਰਨ test5(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਪੂਰਨ *tab4;

    tab4 = ਸਮ੍ਰਿਤੀ_ਦਿਓ(20 * ਆਕਾਰ(ਪੂਰਨ));
    ਲਈ(i=0;i<21;i++) {
        ਜੋੜ += tab4[i];
    }
    ਮੁਕਤ(tab4);

    ਵਾਪਸ ਜੋੜ;
}

/* error */
ਪੂਰਨ test6(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਪੂਰਨ *tab4;
    
    tab4 = ਸਮ੍ਰਿਤੀ_ਦਿਓ(20 * ਆਕਾਰ(ਪੂਰਨ));
    ਮੁਕਤ(tab4);
    ਲਈ(i=0;i<21;i++) {
        ਜੋੜ += tab4[i];
    }

    ਵਾਪਸ ਜੋੜ;
}

/* error */
ਪੂਰਨ test7(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਪੂਰਨ *p;

    ਲਈ(i=0;i<TAB_ਮਾਪ + 1;i++) {
        p = &tab[i];
        ਜੇ (i == TAB_ਮਾਪ)
            ਲਿਖੋ("i=%d %x\n", i, p);
        ਜੋੜ += *p;
    }
    ਵਾਪਸ ਜੋੜ;
}

/* ok */
ਪੂਰਨ test8(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਪੂਰਨ tab[10];

    ਲਈ(i=0;i<10;i++) {
        ਜੋੜ += tab[i];
    }
    ਵਾਪਸ ਜੋੜ;
}

/* error */
ਪੂਰਨ test9(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0;
    ਅੱਖਰ tab[10];

    ਲਈ(i=0;i<11;i++) {
        ਜੋੜ += tab[i];
    }
    ਵਾਪਸ ਜੋੜ;
}

/* ok */
ਪੂਰਨ test10(ਖਾਲੀ)
{
    ਅੱਖਰ tab[10];
    ਅੱਖਰ tab1[10];

    memset(tab, 0, 10);
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(tab, tab1, 10);
    memmove(tab, tab1, 10);
    ਵਾਪਸ 0;
}

/* error */
ਪੂਰਨ test11(ਖਾਲੀ)
{
    ਅੱਖਰ tab[10];

    memset(tab, 0, 11);
    ਵਾਪਸ 0;
}

/* error */
ਪੂਰਨ test12(ਖਾਲੀ)
{
    ਖਾਲੀ *ptr;
    ptr = ਸਮ੍ਰਿਤੀ_ਦਿਓ(10);
    ਮੁਕਤ(ptr);
    ਮੁਕਤ(ptr);
    ਵਾਪਸ 0;
}

/* error */
ਪੂਰਨ test13(ਖਾਲੀ)
{
    ਅੱਖਰ pad1 = 0;
    ਅੱਖਰ tab[10];
    ਅੱਖਰ pad2 = 0;
    memset(tab, 'a', ਆਕਾਰ(tab));
    ਵਾਪਸ ਲੜੀ_ਲੰਬਾਈ(tab);
}

ਪੂਰਨ test14(ਖਾਲੀ)
{
    ਅੱਖਰ *p = alloca(TAB_ਮਾਪ);
    ਮਾਪ_t ret;
    memset(p, 'a', TAB_ਮਾਪ);
    p[TAB_ਮਾਪ-1] = 0;
    ret = ਲੜੀ_ਲੰਬਾਈ(p);
    ਵਾਪਸ ret;
}

/* error */
ਪੂਰਨ test15(ਖਾਲੀ)
{
    ਅੱਖਰ *p = alloca(TAB_ਮਾਪ-1);
    ਮਾਪ_t ret;
    memset(p, 'a', TAB_ਮਾਪ);
    p[TAB_ਮਾਪ-1] = 0;
    ret = ਲੜੀ_ਲੰਬਾਈ(p);
    ਵਾਪਸ ret;
}

/* ok */
ਪੂਰਨ test16()
{
    ਅੱਖਰ *demo = "This is only a test.";
    ਅੱਖਰ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    ਲਿਖੋ("alloca : %s : %s\n", p, strcpy(q=alloca(ਲੜੀ_ਲੰਬਾਈ(demo)+1),demo) );

    ਵਾਪਸ 0;
}

/* error */
ਪੂਰਨ test17()
{
    ਅੱਖਰ *demo = "This is only a test.";
    ਅੱਖਰ *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    ਲਿਖੋ("alloca : %s : %s\n", p, strcpy(q=alloca(ਲੜੀ_ਲੰਬਾਈ(demo)),demo) );

    ਵਾਪਸ 0;
}

ਪੂਰਨ test18(ਖਾਲੀ)
{
    ਪੂਰਨ i, ਜੋੜ = 0, n = TAB_ਮਾਪ;
    ਪੂਰਨ tab[n];
    ਲਈ(i=0;i<TAB_ਮਾਪ+1;i++) {
        ਜੋੜ += tab[i];
    }
    ਵਾਪਸ ਜੋੜ;
}

ਪੂਰਨ (*ਸਾਰਣੀ_test[])(ਖਾਲੀ) = {
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

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਪੂਰਨ i;
    ਅੱਖਰ *cp;
    ਪੂਰਨ ਸੂਚਕਾਂਕ;
    ਪੂਰਨ (*ftest)(ਖਾਲੀ);
    ਪੂਰਨ ਸੂਚਕਾਂਕ_max = ਆਕਾਰ(ਸਾਰਣੀ_test)/ਆਕਾਰ(ਸਾਰਣੀ_test[0]);

    /* check bounds checking main arg */
    ਲਈ (i = 0; i < argc; i++) {
        cp = argv[i];
        ਜਦੋਂ (*cp) {
            cp++;
        }
    }

    ਜੇ (argc < 2) {
        ਲਿਖੋ(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", ਸੂਚਕਾਂਕ_max);
        ਬਾਹਰ_ਨਿਕਲੋ(1);
    }

    ਸੂਚਕਾਂਕ = 0;
    ਜੇ (argc >= 2)
        ਸੂਚਕਾਂਕ = atoi(argv[1]) - 1;

    ਜੇ ((ਸੂਚਕਾਂਕ < 0) || (ਸੂਚਕਾਂਕ >= ਸੂਚਕਾਂਕ_max)) {
        ਲਿਖੋ("N is outside of the valid range (%d)\n", ਸੂਚਕਾਂਕ);
        ਬਾਹਰ_ਨਿਕਲੋ(2);
    }

    /* well, we also use bounds on this ! */
    ftest = ਸਾਰਣੀ_test[ਸੂਚਕਾਂਕ];
    ftest();

    ਵਾਪਸ 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
