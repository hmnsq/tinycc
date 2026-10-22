#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>

#وصف_ڪريو TST   صحيح i, a[2], b[2];                \
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
    إذا (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    وإلا {
        cnt++;
    }
    إذا (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    وإلا {
        cnt++;
    }
    إذا (cnt != 2)
        لکو ("incorrect cnt %d\n", cnt);
}

ساكن jmp_buf buf1;
ساكن jmp_buf buf2;
ساكن صحيح *p;
ساكن صحيح n_x = 6;
ساكن صحيح g_counter;

ساكن فراغ ڍير (فراغ)
{
    ساكن صحيح counter;
    ساكن صحيح way_point1;
    ساكن صحيح way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    إذا (setjmp (buf1) != 101) {
        صحيح a[n_x];
        g_counter++;
        p = &a[0];
        إذا (g_counter < 5)
            longjmp (buf1, 2);
        وإلا إذا (g_counter == 5)
            longjmp (buf1, 101);
        وإلا {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    إذا (counter == 0) {
        counter++;
        {
            صحيح a[n_x];
            g_counter++;
            p = &a[0];
            إذا (g_counter < 5)
                longjmp (buf1, 2);
            وإلا إذا (g_counter == 5)
                longjmp (buf1, 101);
            وإلا {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    إذا (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    إذا (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        لکو ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ساكن jmp_buf env;
ساكن صحيح آخري_قدر;

ساكن فراغ jump (صحيح val)
{
    longjmp (env, val);
}

ساكن فراغ check (فراغ)
{
    صحيح قدر;

    آخري_قدر = -1;
    قدر = setjmp (env);
    إذا (قدر != آخري_قدر + 1) {
        لکو ("incorrect value %d %d\n",
                قدر, آخري_قدر + 1);
        أرجع;
    }
    آخري_قدر = قدر;
    بدل (قدر) {
#إذا !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    حالة 0:
        jump (0);
#جيڪڏهن_پورو
    افتراضي:
        إذا (قدر < 10)
          jump (قدر + 1);
    }
}

صحيح
مکيه (فراغ)
{
    صحيح i;

    لكل (i = 0; i < 10;  i++) {
        tst();
        ڍير();
        check();
    }
    أرجع 0;
}


