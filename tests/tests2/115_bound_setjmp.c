#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>

#define TST   صحیح i, a[2], b[2];                \
              برای (i = 0; i < 2; i++) a[i] = 0; \
              برای (i = 0; i < 2; i++) b[i] = 0

ایستا jmp_buf jmp;

ایستا تهی tst1 (تهی)
{
    TST;
    longjmp(jmp, 1);
}

ایستا تهی tst2(تهی)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ایستا تهی tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ایستا تهی tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ایستا تهی tst (تهی)
{
    jmp_buf loc;
    ایستا صحیح cnt;

    cnt = 0;
    اگر (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    وگرنه {
        cnt++;
    }
    اگر (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    وگرنه {
        cnt++;
    }
    اگر (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

ایستا jmp_buf buf1;
ایستا jmp_buf buf2;
ایستا صحیح *p;
ایستا صحیح n_x = 6;
ایستا صحیح g_counter;

ایستا تهی پشته (تهی)
{
    ایستا صحیح counter;
    ایستا صحیح way_point1;
    ایستا صحیح way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    اگر (setjmp (buf1) != 101) {
        صحیح a[n_x];
        g_counter++;
        p = &a[0];
        اگر (g_counter < 5)
            longjmp (buf1, 2);
        وگرنه اگر (g_counter == 5)
            longjmp (buf1, 101);
        وگرنه {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    اگر (counter == 0) {
        counter++;
        {
            صحیح a[n_x];
            g_counter++;
            p = &a[0];
            اگر (g_counter < 5)
                longjmp (buf1, 2);
            وگرنه اگر (g_counter == 5)
                longjmp (buf1, 101);
            وگرنه {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    اگر (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    اگر (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ایستا jmp_buf env;
ایستا صحیح last_مقدار;

ایستا تهی jump (صحیح val)
{
    longjmp (env, val);
}

ایستا تهی check (تهی)
{
    صحیح مقدار;

    last_مقدار = -1;
    مقدار = setjmp (env);
    اگر (مقدار != last_مقدار + 1) {
        printf ("incorrect value %d %d\n",
                مقدار, last_مقدار + 1);
        بازگشت;
    }
    last_مقدار = مقدار;
    انتخاب (مقدار) {
#اگر !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    حالت 0:
        jump (0);
#endif
    پیشفرض:
        اگر (مقدار < 10)
          jump (مقدار + 1);
    }
}

صحیح
اصلی (تهی)
{
    صحیح i;

    برای (i = 0; i < 10;  i++) {
        tst();
        پشته();
        check();
    }
    بازگشت 0;
}


