#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>

#define TST   पूर्णाङ्क i, a[2], b[2];                \
              लागि (i = 0; i < 2; i++) a[i] = 0; \
              लागि (i = 0; i < 2; i++) b[i] = 0

स्थिर लाँघ_बफ jmp;

स्थिर शून्य tst1 (शून्य)
{
    TST;
    दीर्घ_लाँघ(jmp, 1);
}

स्थिर शून्य tst2(शून्य)
{
    लाँघ_बफ jmp;

    बनाओ_लाँघ (jmp);
    TST;
    tst1();
}

स्थिर शून्य tst3 (लाँघ_बफ loc)
{
    TST;
    दीर्घ_लाँघ(loc, 1);
}

स्थिर शून्य tst4(लाँघ_बफ loc)
{
    लाँघ_बफ jmp;

    बनाओ_लाँघ (jmp);
    TST;
    tst3(loc);
}

स्थिर शून्य tst (शून्य)
{
    लाँघ_बफ loc;
    स्थिर पूर्णाङ्क cnt;

    cnt = 0;
    यदि (बनाओ_लाँघ (jmp) == 0) {
        TST;
        tst2();
    }
    अन्यथा {
        cnt++;
    }
    यदि (बनाओ_लाँघ (loc) == 0) {
        TST;
        tst4(loc);
    }
    अन्यथा {
        cnt++;
    }
    यदि (cnt != 2)
        म_लिखो ("incorrect cnt %d\n", cnt);
}

स्थिर लाँघ_बफ buf1;
स्थिर लाँघ_बफ buf2;
स्थिर पूर्णाङ्क *p;
स्थिर पूर्णाङ्क n_x = 6;
स्थिर पूर्णाङ्क g_counter;

स्थिर शून्य थाक (शून्य)
{
    स्थिर पूर्णाङ्क counter;
    स्थिर पूर्णाङ्क way_point1;
    स्थिर पूर्णाङ्क way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    यदि (बनाओ_लाँघ (buf1) != 101) {
        पूर्णाङ्क a[n_x];
        g_counter++;
        p = &a[0];
        यदि (g_counter < 5)
            दीर्घ_लाँघ (buf1, 2);
        अन्यथा यदि (g_counter == 5)
            दीर्घ_लाँघ (buf1, 101);
        अन्यथा {
            बनाओ_लाँघ (buf2); 
            दीर्घ_लाँघ (buf1, 101);
        }
    }
    
    way_point1--;

    यदि (counter == 0) {
        counter++;
        {
            पूर्णाङ्क a[n_x];
            g_counter++;
            p = &a[0];
            यदि (g_counter < 5)
                दीर्घ_लाँघ (buf1, 2);
            अन्यथा यदि (g_counter == 5)
                दीर्घ_लाँघ (buf1, 101);
            अन्यथा {
                बनाओ_लाँघ (buf2);
                दीर्घ_लाँघ (buf1, 101);
            }
        }
    }

    way_point2--;

    यदि (counter == 1) {
        counter++;
        दीर्घ_लाँघ (buf2, 2);
    }

    यदि (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        म_लिखो ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

स्थिर लाँघ_बफ env;
स्थिर पूर्णाङ्क last_मान;

स्थिर शून्य jump (पूर्णाङ्क val)
{
    दीर्घ_लाँघ (env, val);
}

स्थिर शून्य check (शून्य)
{
    पूर्णाङ्क मान;

    last_मान = -1;
    मान = बनाओ_लाँघ (env);
    यदि (मान != last_मान + 1) {
        म_लिखो ("incorrect value %d %d\n",
                मान, last_मान + 1);
        फर्काऊ;
    }
    last_मान = मान;
    विकल्प (मान) {
#यदि !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    पक्ष 0:
        jump (0);
#endif
    स्वभाव:
        यदि (मान < 10)
          jump (मान + 1);
    }
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;

    लागि (i = 0; i < 10;  i++) {
        tst();
        थाक();
        check();
    }
    फर्काऊ 0;
}


