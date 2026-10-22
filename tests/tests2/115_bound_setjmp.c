#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>

#define TST   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, a[2], b[2];                \
              ପାଇଁ (i = 0; i < 2; i++) a[i] = 0; \
              ପାଇଁ (i = 0; i < 2; i++) b[i] = 0

ସ୍ଥିର jmp_buf jmp;

ସ୍ଥିର ଶୂନ୍ୟ tst1 (ଶୂନ୍ୟ)
{
    TST;
    longjmp(jmp, 1);
}

ସ୍ଥିର ଶୂନ୍ୟ tst2(ଶୂନ୍ୟ)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ସ୍ଥିର ଶୂନ୍ୟ tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ସ୍ଥିର ଶୂନ୍ୟ tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ସ୍ଥିର ଶୂନ୍ୟ tst (ଶୂନ୍ୟ)
{
    jmp_buf loc;
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା cnt;

    cnt = 0;
    ଯଦି (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ଅନ୍ୟଥା {
        cnt++;
    }
    ଯଦି (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ଅନ୍ୟଥା {
        cnt++;
    }
    ଯଦି (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

ସ୍ଥିର jmp_buf buf1;
ସ୍ଥିର jmp_buf buf2;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା n_x = 6;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା g_counter;

ସ୍ଥିର ଶୂନ୍ୟ ଗଦା (ଶୂନ୍ୟ)
{
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା counter;
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା way_point1;
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ଯଦି (setjmp (buf1) != 101) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[n_x];
        g_counter++;
        p = &a[0];
        ଯଦି (g_counter < 5)
            longjmp (buf1, 2);
        ଅନ୍ୟଥା ଯଦି (g_counter == 5)
            longjmp (buf1, 101);
        ଅନ୍ୟଥା {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ଯଦି (counter == 0) {
        counter++;
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[n_x];
            g_counter++;
            p = &a[0];
            ଯଦି (g_counter < 5)
                longjmp (buf1, 2);
            ଅନ୍ୟଥା ଯଦି (g_counter == 5)
                longjmp (buf1, 101);
            ଅନ୍ୟଥା {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ଯଦି (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ଯଦି (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ସ୍ଥିର jmp_buf env;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା last_ମୂଲ୍ୟ;

ସ୍ଥିର ଶୂନ୍ୟ jump (ପୂର୍ଣ୍ଣସଂଖ୍ୟା val)
{
    longjmp (env, val);
}

ସ୍ଥିର ଶୂନ୍ୟ check (ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ;

    last_ମୂଲ୍ୟ = -1;
    ମୂଲ୍ୟ = setjmp (env);
    ଯଦି (ମୂଲ୍ୟ != last_ମୂଲ୍ୟ + 1) {
        printf ("incorrect value %d %d\n",
                ମୂଲ୍ୟ, last_ମୂଲ୍ୟ + 1);
        ଫେରନ୍ତୁ;
    }
    last_ମୂଲ୍ୟ = ମୂଲ୍ୟ;
    ବାଛ (ମୂଲ୍ୟ) {
#ଯଦି !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    ସ୍ଥିତି 0:
        jump (0);
#endif
    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
        ଯଦି (ମୂଲ୍ୟ < 10)
          jump (ମୂଲ୍ୟ + 1);
    }
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 0; i < 10;  i++) {
        tst();
        ଗଦା();
        check();
    }
    ଫେରନ୍ତୁ 0;
}


