#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <setjmp.h>

#define TST   পূর্ণাঙ্ক i, a[2], b[2];                \
              প্রতি (i = 0; i < 2; i++) a[i] = 0; \
              প্রতি (i = 0; i < 2; i++) b[i] = 0

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
    স্থির পূর্ণাঙ্ক cnt;

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
স্থির পূর্ণাঙ্ক *p;
স্থির পূর্ণাঙ্ক n_x = 6;
স্থির পূর্ণাঙ্ক g_counter;

স্থির শূন্য স্তূপ (শূন্য)
{
    স্থির পূর্ণাঙ্ক counter;
    স্থির পূর্ণাঙ্ক way_point1;
    স্থির পূর্ণাঙ্ক way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    যদি (setjmp (buf1) != 101) {
        পূর্ণাঙ্ক a[n_x];
        g_counter++;
        p = &a[0];
        যদি (g_counter < 5)
            longjmp (buf1, 2);
        অন্যথা যদি (g_counter == 5)
            longjmp (buf1, 101);
        অন্যথা {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    যদি (counter == 0) {
        counter++;
        {
            পূর্ণাঙ্ক a[n_x];
            g_counter++;
            p = &a[0];
            যদি (g_counter < 5)
                longjmp (buf1, 2);
            অন্যথা যদি (g_counter == 5)
                longjmp (buf1, 101);
            অন্যথা {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    যদি (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    যদি (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

স্থির jmp_buf env;
স্থির পূর্ণাঙ্ক last_মান;

স্থির শূন্য jump (পূর্ণাঙ্ক val)
{
    longjmp (env, val);
}

স্থির শূন্য check (শূন্য)
{
    পূর্ণাঙ্ক মান;

    last_মান = -1;
    মান = setjmp (env);
    যদি (মান != last_মান + 1) {
        printf ("incorrect value %d %d\n",
                মান, last_মান + 1);
        প্রত্যাগম;
    }
    last_মান = মান;
    বিকল্প (মান) {
#যদি !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    পক্ষ 0:
        jump (0);
#endif
    স্বভাব:
        যদি (মান < 10)
          jump (মান + 1);
    }
}

পূর্ণাঙ্ক
main (শূন্য)
{
    পূর্ণাঙ্ক i;

    প্রতি (i = 0; i < 10;  i++) {
        tst();
        স্তূপ();
        check();
    }
    প্রত্যাগম 0;
}


