#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>

#define TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

ساكن jmp_buf jmp;

ساكن فراغ tst1 (فراغ)
{
    TST;
    longjmp(jmp, 1);
}

ساكن فراغ tst2(فراغ)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ساكن فراغ tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ساكن فراغ tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ساكن فراغ tst (فراغ)
{
    jmp_buf loc;
    ساكن صحيح cnt;

    cnt = 0;
    𐤀𐤌 (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    وإلا {
        cnt++;
    }
    𐤀𐤌 (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    وإلا {
        cnt++;
    }
    𐤀𐤌 (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

ساكن jmp_buf buf1;
ساكن jmp_buf buf2;
ساكن صحيح *p;
ساكن صحيح n_x = 6;
ساكن صحيح g_counter;

ساكن فراغ stack (فراغ)
{
    ساكن صحيح counter;
    ساكن صحيح way_point1;
    ساكن صحيح way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    𐤀𐤌 (setjmp (buf1) != 101) {
        صحيح a[n_x];
        g_counter++;
        p = &a[0];
        𐤀𐤌 (g_counter < 5)
            longjmp (buf1, 2);
        وإلا 𐤀𐤌 (g_counter == 5)
            longjmp (buf1, 101);
        وإلا {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    𐤀𐤌 (counter == 0) {
        counter++;
        {
            صحيح a[n_x];
            g_counter++;
            p = &a[0];
            𐤀𐤌 (g_counter < 5)
                longjmp (buf1, 2);
            وإلا 𐤀𐤌 (g_counter == 5)
                longjmp (buf1, 101);
            وإلا {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    𐤀𐤌 (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    𐤀𐤌 (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ساكن jmp_buf env;
ساكن صحيح last_value;

ساكن فراغ jump (صحيح val)
{
    longjmp (env, val);
}

ساكن فراغ check (فراغ)
{
    صحيح value;

    last_value = -1;
    value = setjmp (env);
    𐤀𐤌 (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        أرجع;
    }
    last_value = value;
    بدل (value) {
#𐤀𐤌 !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    حالة 0:
        jump (0);
#endif
    افتراضي:
        𐤀𐤌 (value < 10)
          jump (value + 1);
    }
}

صحيح
main (فراغ)
{
    صحيح i;

    لكل (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    أرجع 0;
}


