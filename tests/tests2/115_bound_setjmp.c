#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TST   ਪੂਰਨ i, a[2], b[2];                \
              ਲਈ (i = 0; i < 2; i++) a[i] = 0; \
              ਲਈ (i = 0; i < 2; i++) b[i] = 0

ਸਥਿਰ jmp_buf jmp;

ਸਥਿਰ ਖਾਲੀ tst1 (ਖਾਲੀ)
{
    TST;
    longjmp(jmp, 1);
}

ਸਥਿਰ ਖਾਲੀ tst2(ਖਾਲੀ)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ਸਥਿਰ ਖਾਲੀ tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ਸਥਿਰ ਖਾਲੀ tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ਸਥਿਰ ਖਾਲੀ tst (ਖਾਲੀ)
{
    jmp_buf loc;
    ਸਥਿਰ ਪੂਰਨ cnt;

    cnt = 0;
    ਜੇ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ਨਹੀਂਤਾਂ {
        cnt++;
    }
    ਜੇ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ਨਹੀਂਤਾਂ {
        cnt++;
    }
    ਜੇ (cnt != 2)
        ਲਿਖੋ ("incorrect cnt %d\n", cnt);
}

ਸਥਿਰ jmp_buf buf1;
ਸਥਿਰ jmp_buf buf2;
ਸਥਿਰ ਪੂਰਨ *p;
ਸਥਿਰ ਪੂਰਨ n_x = 6;
ਸਥਿਰ ਪੂਰਨ g_counter;

ਸਥਿਰ ਖਾਲੀ ਢੇਰ (ਖਾਲੀ)
{
    ਸਥਿਰ ਪੂਰਨ counter;
    ਸਥਿਰ ਪੂਰਨ way_point1;
    ਸਥਿਰ ਪੂਰਨ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ਜੇ (setjmp (buf1) != 101) {
        ਪੂਰਨ a[n_x];
        g_counter++;
        p = &a[0];
        ਜੇ (g_counter < 5)
            longjmp (buf1, 2);
        ਨਹੀਂਤਾਂ ਜੇ (g_counter == 5)
            longjmp (buf1, 101);
        ਨਹੀਂਤਾਂ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ਜੇ (counter == 0) {
        counter++;
        {
            ਪੂਰਨ a[n_x];
            g_counter++;
            p = &a[0];
            ਜੇ (g_counter < 5)
                longjmp (buf1, 2);
            ਨਹੀਂਤਾਂ ਜੇ (g_counter == 5)
                longjmp (buf1, 101);
            ਨਹੀਂਤਾਂ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ਜੇ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ਜੇ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        ਲਿਖੋ ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ਸਥਿਰ jmp_buf env;
ਸਥਿਰ ਪੂਰਨ ਆਖਰੀ_ਮੁੱਲ;

ਸਥਿਰ ਖਾਲੀ jump (ਪੂਰਨ val)
{
    longjmp (env, val);
}

ਸਥਿਰ ਖਾਲੀ check (ਖਾਲੀ)
{
    ਪੂਰਨ ਮੁੱਲ;

    ਆਖਰੀ_ਮੁੱਲ = -1;
    ਮੁੱਲ = setjmp (env);
    ਜੇ (ਮੁੱਲ != ਆਖਰੀ_ਮੁੱਲ + 1) {
        ਲਿਖੋ ("incorrect value %d %d\n",
                ਮੁੱਲ, ਆਖਰੀ_ਮੁੱਲ + 1);
        ਵਾਪਸ;
    }
    ਆਖਰੀ_ਮੁੱਲ = ਮੁੱਲ;
    ਚੋਣ (ਮੁੱਲ) {
#ਜੇ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    ਹਾਲਤ 0:
        jump (0);
#ਜੇ_ਅੰਤ
    ਮੂਲ:
        ਜੇ (ਮੁੱਲ < 10)
          jump (ਮੁੱਲ + 1);
    }
}

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
    ਪੂਰਨ i;

    ਲਈ (i = 0; i < 10;  i++) {
        tst();
        ਢੇਰ();
        check();
    }
    ਵਾਪਸ 0;
}


