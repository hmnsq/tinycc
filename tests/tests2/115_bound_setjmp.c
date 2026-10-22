#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <setjmp.h>

#define TST   পূর্ণসংখ্যা i, a[2], b[2];                \
              জন্য (i = 0; i < 2; i++) a[i] = 0; \
              জন্য (i = 0; i < 2; i++) b[i] = 0

স্থির jmp_buf jmp;

স্থির শূন্য tst1 (শূন্য)
{
    TST;
    longjmp(jmp, 1);
}

স্থির শূন্য tst2(শূন্য)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

স্থির শূন্য tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

স্থির শূন্য tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

স্থির শূন্য tst (শূন্য)
{
    jmp_buf loc;
    স্থির পূর্ণসংখ্যা cnt;

    cnt = 0;
    যদি (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    অন্যথা {
        cnt++;
    }
    যদি (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    অন্যথা {
        cnt++;
    }
    যদি (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

স্থির jmp_buf buf1;
স্থির jmp_buf buf2;
স্থির পূর্ণসংখ্যা *p;
স্থির পূর্ণসংখ্যা n_x = 6;
স্থির পূর্ণসংখ্যা g_গণক;

স্থির শূন্য স্তূপ (শূন্য)
{
    স্থির পূর্ণসংখ্যা গণক;
    স্থির পূর্ণসংখ্যা way_point1;
    স্থির পূর্ণসংখ্যা way_point2;

    গণক = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_গণক = 0;
    যদি (setjmp (buf1) != 101) {
        পূর্ণসংখ্যা a[n_x];
        g_গণক++;
        p = &a[0];
        যদি (g_গণক < 5)
            longjmp (buf1, 2);
        অন্যথা যদি (g_গণক == 5)
            longjmp (buf1, 101);
        অন্যথা {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    যদি (গণক == 0) {
        গণক++;
        {
            পূর্ণসংখ্যা a[n_x];
            g_গণক++;
            p = &a[0];
            যদি (g_গণক < 5)
                longjmp (buf1, 2);
            অন্যথা যদি (g_গণক == 5)
                longjmp (buf1, 101);
            অন্যথা {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    যদি (গণক == 1) {
        গণক++;
        longjmp (buf2, 2);
    }

    যদি (!(way_point1 == 0 && way_point2 == 0 &&
          g_গণক == 6 && গণক == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_গণক, গণক);
}

স্থির jmp_buf env;
স্থির পূর্ণসংখ্যা last_মান;

স্থির শূন্য jump (পূর্ণসংখ্যা val)
{
    longjmp (env, val);
}

স্থির শূন্য check (শূন্য)
{
    পূর্ণসংখ্যা মান;

    last_মান = -1;
    মান = setjmp (env);
    যদি (মান != last_মান + 1) {
        printf ("incorrect value %d %d\n",
                মান, last_মান + 1);
        ফেরত;
    }
    last_মান = মান;
    নির্বাচন (মান) {
#যদি !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    ক্ষেত্র 0:
        jump (0);
#endif
    পূর্বনির্ধারিত:
        যদি (মান < 10)
          jump (মান + 1);
    }
}

পূর্ণসংখ্যা
প্রধান (শূন্য)
{
    পূর্ণসংখ্যা i;

    জন্য (i = 0; i < 10;  i++) {
        tst();
        স্তূপ();
        check();
    }
    ফেরত 0;
}


