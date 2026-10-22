#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>

#define TST   पूर्णाङ्क i, a[2], b[2];                \
              प्रति (i = 0; i < 2; i++) a[i] = 0; \
              प्रति (i = 0; i < 2; i++) b[i] = 0

स्थिर jmp_buf jmp;

स्थिर शून्य tst1 (शून्य)
{
    TST;
    longjmp(jmp, 1);
}

स्थिर शून्य tst2(शून्य)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

स्थिर शून्य tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

स्थिर शून्य tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

स्थिर शून्य tst (शून्य)
{
    jmp_buf loc;
    स्थिर पूर्णाङ्क cnt;

    cnt = 0;
    जइ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    अण्णहा {
        cnt++;
    }
    जइ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    अण्णहा {
        cnt++;
    }
    जइ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

स्थिर jmp_buf buf1;
स्थिर jmp_buf buf2;
स्थिर पूर्णाङ्क *p;
स्थिर पूर्णाङ्क n_x = 6;
स्थिर पूर्णाङ्क g_counter;

स्थिर शून्य राशिः (शून्य)
{
    स्थिर पूर्णाङ्क counter;
    स्थिर पूर्णाङ्क way_point1;
    स्थिर पूर्णाङ्क way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    जइ (setjmp (buf1) != 101) {
        पूर्णाङ्क a[n_x];
        g_counter++;
        p = &a[0];
        जइ (g_counter < 5)
            longjmp (buf1, 2);
        अण्णहा जइ (g_counter == 5)
            longjmp (buf1, 101);
        अण्णहा {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    जइ (counter == 0) {
        counter++;
        {
            पूर्णाङ्क a[n_x];
            g_counter++;
            p = &a[0];
            जइ (g_counter < 5)
                longjmp (buf1, 2);
            अण्णहा जइ (g_counter == 5)
                longjmp (buf1, 101);
            अण्णहा {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    जइ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    जइ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

स्थिर jmp_buf env;
स्थिर पूर्णाङ्क last_मानम्;

स्थिर शून्य jump (पूर्णाङ्क val)
{
    longjmp (env, val);
}

स्थिर शून्य check (शून्य)
{
    पूर्णाङ्क मानम्;

    last_मानम् = -1;
    मानम् = setjmp (env);
    जइ (मानम् != last_मानम् + 1) {
        printf ("incorrect value %d %d\n",
                मानम्, last_मानम् + 1);
        प्रत्यागम;
    }
    last_मानम् = मानम्;
    विकल्प (मानम्) {
#जइ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    पक्ष 0:
        jump (0);
#endif
    स्वभाव:
        जइ (मानम् < 10)
          jump (मानम् + 1);
    }
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;

    प्रति (i = 0; i < 10;  i++) {
        tst();
        राशिः();
        check();
    }
    प्रत्यागम 0;
}


