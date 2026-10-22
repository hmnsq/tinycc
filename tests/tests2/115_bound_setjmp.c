#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>

#define TST   ಪೂರ್ಣಾಙ್ಕ i, a[2], b[2];                \
              ಪ್ರತಿ (i = 0; i < 2; i++) a[i] = 0; \
              ಪ್ರತಿ (i = 0; i < 2; i++) b[i] = 0

ಸ್ಥಿರ jmp_buf jmp;

ಸ್ಥಿರ ಶೂನ್ಯ tst1 (ಶೂನ್ಯ)
{
    TST;
    longjmp(jmp, 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ tst2(ಶೂನ್ಯ)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

ಸ್ಥಿರ ಶೂನ್ಯ tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

ಸ್ಥಿರ ಶೂನ್ಯ tst (ಶೂನ್ಯ)
{
    jmp_buf loc;
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ cnt;

    cnt = 0;
    ಯದಿ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ಅನ್ಯಥಾ {
        cnt++;
    }
    ಯದಿ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ಅನ್ಯಥಾ {
        cnt++;
    }
    ಯದಿ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

ಸ್ಥಿರ jmp_buf buf1;
ಸ್ಥಿರ jmp_buf buf2;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ *p;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ n_x = 6;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ g_counter;

ಸ್ಥಿರ ಶೂನ್ಯ ರಾಶಿ (ಶೂನ್ಯ)
{
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ counter;
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ way_point1;
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ಯದಿ (setjmp (buf1) != 101) {
        ಪೂರ್ಣಾಙ್ಕ a[n_x];
        g_counter++;
        p = &a[0];
        ಯದಿ (g_counter < 5)
            longjmp (buf1, 2);
        ಅನ್ಯಥಾ ಯದಿ (g_counter == 5)
            longjmp (buf1, 101);
        ಅನ್ಯಥಾ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ಯದಿ (counter == 0) {
        counter++;
        {
            ಪೂರ್ಣಾಙ್ಕ a[n_x];
            g_counter++;
            p = &a[0];
            ಯದಿ (g_counter < 5)
                longjmp (buf1, 2);
            ಅನ್ಯಥಾ ಯದಿ (g_counter == 5)
                longjmp (buf1, 101);
            ಅನ್ಯಥಾ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ಯದಿ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ಯದಿ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ಸ್ಥಿರ jmp_buf env;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ last_ಮೌಲ್ಯ;

ಸ್ಥಿರ ಶೂನ್ಯ jump (ಪೂರ್ಣಾಙ್ಕ val)
{
    longjmp (env, val);
}

ಸ್ಥಿರ ಶೂನ್ಯ check (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ;

    last_ಮೌಲ್ಯ = -1;
    ಮೌಲ್ಯ = setjmp (env);
    ಯದಿ (ಮೌಲ್ಯ != last_ಮೌಲ್ಯ + 1) {
        printf ("incorrect value %d %d\n",
                ಮೌಲ್ಯ, last_ಮೌಲ್ಯ + 1);
        ಪ್ರತ್ಯಾಗಮ;
    }
    last_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ವಿಕಲ್ಪ (ಮೌಲ್ಯ) {
#ಯದಿ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    ಪಕ್ಷ 0:
        jump (0);
#endif
    ಸ್ವಭಾವ:
        ಯದಿ (ಮೌಲ್ಯ < 10)
          jump (ಮೌಲ್ಯ + 1);
    }
}

ಪೂರ್ಣಾಙ್ಕ
main (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 0; i < 10;  i++) {
        tst();
        ರಾಶಿ();
        check();
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}


