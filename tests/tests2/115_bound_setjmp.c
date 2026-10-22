#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <setjmp.h>

#define TST   પૂર્ણાંક i, a[2], b[2];                \
              માટે (i = 0; i < 2; i++) a[i] = 0; \
              માટે (i = 0; i < 2; i++) b[i] = 0

સ્થિર jmp_buf jmp;

સ્થિર શૂન્ય tst1 (શૂન્ય)
{
    TST;
    longjmp(jmp, 1);
}

સ્થિર શૂન્ય tst2(શૂન્ય)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

સ્થિર શૂન્ય tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

સ્થિર શૂન્ય tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

સ્થિર શૂન્ય tst (શૂન્ય)
{
    jmp_buf loc;
    સ્થિર પૂર્ણાંક cnt;

    cnt = 0;
    જો (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    નહીંતર {
        cnt++;
    }
    જો (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    નહીંતર {
        cnt++;
    }
    જો (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

સ્થિર jmp_buf buf1;
સ્થિર jmp_buf buf2;
સ્થિર પૂર્ણાંક *p;
સ્થિર પૂર્ણાંક n_x = 6;
સ્થિર પૂર્ણાંક g_counter;

સ્થિર શૂન્ય ઢગલો (શૂન્ય)
{
    સ્થિર પૂર્ણાંક counter;
    સ્થિર પૂર્ણાંક way_point1;
    સ્થિર પૂર્ણાંક way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    જો (setjmp (buf1) != 101) {
        પૂર્ણાંક a[n_x];
        g_counter++;
        p = &a[0];
        જો (g_counter < 5)
            longjmp (buf1, 2);
        નહીંતર જો (g_counter == 5)
            longjmp (buf1, 101);
        નહીંતર {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    જો (counter == 0) {
        counter++;
        {
            પૂર્ણાંક a[n_x];
            g_counter++;
            p = &a[0];
            જો (g_counter < 5)
                longjmp (buf1, 2);
            નહીંતર જો (g_counter == 5)
                longjmp (buf1, 101);
            નહીંતર {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    જો (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    જો (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

સ્થિર jmp_buf env;
સ્થિર પૂર્ણાંક last_કિંમત;

સ્થિર શૂન્ય jump (પૂર્ણાંક val)
{
    longjmp (env, val);
}

સ્થિર શૂન્ય check (શૂન્ય)
{
    પૂર્ણાંક કિંમત;

    last_કિંમત = -1;
    કિંમત = setjmp (env);
    જો (કિંમત != last_કિંમત + 1) {
        printf ("incorrect value %d %d\n",
                કિંમત, last_કિંમત + 1);
        પાછા;
    }
    last_કિંમત = કિંમત;
    પસંદગી (કિંમત) {
#જો !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    સ્થિતિ 0:
        jump (0);
#endif
    મૂળભૂત:
        જો (કિંમત < 10)
          jump (કિંમત + 1);
    }
}

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
    પૂર્ણાંક i;

    માટે (i = 0; i < 10;  i++) {
        tst();
        ઢગલો();
        check();
    }
    પાછા 0;
}


