#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <setjmp.h>

#నిర్వచించు TST   పూర్ణాంకం i, a[2], b[2];                \
              కొరకు (i = 0; i < 2; i++) a[i] = 0; \
              కొరకు (i = 0; i < 2; i++) b[i] = 0

స్థిర jmp_buf jmp;

స్థిర శూన్య tst1 (శూన్య)
{
    TST;
    longjmp(jmp, 1);
}

స్థిర శూన్య tst2(శూన్య)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

స్థిర శూన్య tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

స్థిర శూన్య tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

స్థిర శూన్య tst (శూన్య)
{
    jmp_buf loc;
    స్థిర పూర్ణాంకం cnt;

    cnt = 0;
    ఒకవేళ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    లేకపోతే {
        cnt++;
    }
    ఒకవేళ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    లేకపోతే {
        cnt++;
    }
    ఒకవేళ (cnt != 2)
        రాయి ("incorrect cnt %d\n", cnt);
}

స్థిర jmp_buf buf1;
స్థిర jmp_buf buf2;
స్థిర పూర్ణాంకం *p;
స్థిర పూర్ణాంకం n_x = 6;
స్థిర పూర్ణాంకం g_counter;

స్థిర శూన్య దొంతర (శూన్య)
{
    స్థిర పూర్ణాంకం counter;
    స్థిర పూర్ణాంకం way_point1;
    స్థిర పూర్ణాంకం way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ఒకవేళ (setjmp (buf1) != 101) {
        పూర్ణాంకం a[n_x];
        g_counter++;
        p = &a[0];
        ఒకవేళ (g_counter < 5)
            longjmp (buf1, 2);
        లేకపోతే ఒకవేళ (g_counter == 5)
            longjmp (buf1, 101);
        లేకపోతే {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ఒకవేళ (counter == 0) {
        counter++;
        {
            పూర్ణాంకం a[n_x];
            g_counter++;
            p = &a[0];
            ఒకవేళ (g_counter < 5)
                longjmp (buf1, 2);
            లేకపోతే ఒకవేళ (g_counter == 5)
                longjmp (buf1, 101);
            లేకపోతే {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ఒకవేళ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ఒకవేళ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        రాయి ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

స్థిర jmp_buf env;
స్థిర పూర్ణాంకం చివరి_విలువ;

స్థిర శూన్య jump (పూర్ణాంకం val)
{
    longjmp (env, val);
}

స్థిర శూన్య check (శూన్య)
{
    పూర్ణాంకం విలువ;

    చివరి_విలువ = -1;
    విలువ = setjmp (env);
    ఒకవేళ (విలువ != చివరి_విలువ + 1) {
        రాయి ("incorrect value %d %d\n",
                విలువ, చివరి_విలువ + 1);
        తిరిగి;
    }
    చివరి_విలువ = విలువ;
    ఎంపిక (విలువ) {
#ఒకవేళ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    స్థితి 0:
        jump (0);
#అయితే_ముగింపు
    అప్రమేయ:
        ఒకవేళ (విలువ < 10)
          jump (విలువ + 1);
    }
}

పూర్ణాంకం
ప్రధాన (శూన్య)
{
    పూర్ణాంకం i;

    కొరకు (i = 0; i < 10;  i++) {
        tst();
        దొంతర();
        check();
    }
    తిరిగి 0;
}


