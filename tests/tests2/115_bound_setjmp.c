#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>

#ವ್ಯಾಖ್ಯಾನಿಸು TST   ಪೂರ್ಣಾಂಕ i, a[2], b[2];                \
              ಗಾಗಿ (i = 0; i < 2; i++) a[i] = 0; \
              ಗಾಗಿ (i = 0; i < 2; i++) b[i] = 0

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
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ cnt;

    cnt = 0;
    ಆದರೆ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        cnt++;
    }
    ಆದರೆ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ಇಲ್ಲದಿದ್ದರೆ {
        cnt++;
    }
    ಆದರೆ (cnt != 2)
        ಬರೆ ("incorrect cnt %d\n", cnt);
}

ಸ್ಥಿರ jmp_buf buf1;
ಸ್ಥಿರ jmp_buf buf2;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ *p;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ n_x = 6;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ g_counter;

ಸ್ಥಿರ ಶೂನ್ಯ ರಾಶಿ (ಶೂನ್ಯ)
{
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ counter;
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ way_point1;
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ಆದರೆ (setjmp (buf1) != 101) {
        ಪೂರ್ಣಾಂಕ a[n_x];
        g_counter++;
        p = &a[0];
        ಆದರೆ (g_counter < 5)
            longjmp (buf1, 2);
        ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (g_counter == 5)
            longjmp (buf1, 101);
        ಇಲ್ಲದಿದ್ದರೆ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ಆದರೆ (counter == 0) {
        counter++;
        {
            ಪೂರ್ಣಾಂಕ a[n_x];
            g_counter++;
            p = &a[0];
            ಆದರೆ (g_counter < 5)
                longjmp (buf1, 2);
            ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (g_counter == 5)
                longjmp (buf1, 101);
            ಇಲ್ಲದಿದ್ದರೆ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ಆದರೆ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ಆದರೆ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        ಬರೆ ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

ಸ್ಥಿರ jmp_buf env;
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ ಕೊನೆಯ_ಮೌಲ್ಯ;

ಸ್ಥಿರ ಶೂನ್ಯ jump (ಪೂರ್ಣಾಂಕ val)
{
    longjmp (env, val);
}

ಸ್ಥಿರ ಶೂನ್ಯ check (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ;

    ಕೊನೆಯ_ಮೌಲ್ಯ = -1;
    ಮೌಲ್ಯ = setjmp (env);
    ಆದರೆ (ಮೌಲ್ಯ != ಕೊನೆಯ_ಮೌಲ್ಯ + 1) {
        ಬರೆ ("incorrect value %d %d\n",
                ಮೌಲ್ಯ, ಕೊನೆಯ_ಮೌಲ್ಯ + 1);
        ಹಿಂತಿರುಗಿ;
    }
    ಕೊನೆಯ_ಮೌಲ್ಯ = ಮೌಲ್ಯ;
    ಆಯ್ಕೆ (ಮೌಲ್ಯ) {
#ಆದರೆ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    ಸ್ಥಿತಿ 0:
        jump (0);
#ಆದರೆ_ಅಂತ್ಯ
    ಪೂರ್ವನಿಯೋಜಿತ:
        ಆದರೆ (ಮೌಲ್ಯ < 10)
          jump (ಮೌಲ್ಯ + 1);
    }
}

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 0; i < 10;  i++) {
        tst();
        ರಾಶಿ();
        check();
    }
    ಹಿಂತಿರುಗಿ 0;
}


