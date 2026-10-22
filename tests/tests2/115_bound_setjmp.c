#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>

#تعریف_کرو TST   صحیح i, a[2], b[2];                \
              برائے (i = 0; i < 2; i++) a[i] = 0; \
              برائے (i = 0; i < 2; i++) b[i] = 0

ساکن jmp_buf jmp;

ساکن خالی tst1 (خالی)
{
    TST;
    longjmp(jmp, 1);
}

ساکن خالی tst2(خالی)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ساکن خالی tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ساکن خالی tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ساکن خالی tst (خالی)
{
    jmp_buf loc;
    ساکن صحیح cnt;

    cnt = 0;
    اگر (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ورنہ {
        cnt++;
    }
    اگر (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ورنہ {
        cnt++;
    }
    اگر (cnt != 2)
        لکھو ("incorrect cnt %d\n", cnt);
}

ساکن jmp_buf buf1;
ساکن jmp_buf buf2;
ساکن صحیح *p;
ساکن صحیح n_x = 6;
ساکن صحیح g_شمار;

ساکن خالی ڈھیر (خالی)
{
    ساکن صحیح شمار_2;
    ساکن صحیح way_point1;
    ساکن صحیح way_point2;

    شمار_2 = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_شمار = 0;
    اگر (setjmp (buf1) != 101) {
        صحیح a[n_x];
        g_شمار++;
        p = &a[0];
        اگر (g_شمار < 5)
            longjmp (buf1, 2);
        ورنہ اگر (g_شمار == 5)
            longjmp (buf1, 101);
        ورنہ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    اگر (شمار_2 == 0) {
        شمار_2++;
        {
            صحیح a[n_x];
            g_شمار++;
            p = &a[0];
            اگر (g_شمار < 5)
                longjmp (buf1, 2);
            ورنہ اگر (g_شمار == 5)
                longjmp (buf1, 101);
            ورنہ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    اگر (شمار_2 == 1) {
        شمار_2++;
        longjmp (buf2, 2);
    }

    اگر (!(way_point1 == 0 && way_point2 == 0 &&
          g_شمار == 6 && شمار_2 == 2))
        لکھو ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_شمار, شمار_2);
}

ساکن jmp_buf env;
ساکن صحیح آخری_قدر;

ساکن خالی jump (صحیح val)
{
    longjmp (env, val);
}

ساکن خالی check (خالی)
{
    صحیح قدر;

    آخری_قدر = -1;
    قدر = setjmp (env);
    اگر (قدر != آخری_قدر + 1) {
        لکھو ("incorrect value %d %d\n",
                قدر, آخری_قدر + 1);
        واپس;
    }
    آخری_قدر = قدر;
    انتخاب (قدر) {
#اگر !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    حالت 0:
        jump (0);
#اگر_ختم
    طےشدہ:
        اگر (قدر < 10)
          jump (قدر + 1);
    }
}

صحیح
مین (خالی)
{
    صحیح i;

    برائے (i = 0; i < 10;  i++) {
        tst();
        ڈھیر();
        check();
    }
    واپس 0;
}


