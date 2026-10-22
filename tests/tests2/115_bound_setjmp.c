#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>

#define TST   पूर्णांक i, a[2], b[2];                \
              साठी (i = 0; i < 2; i++) a[i] = 0; \
              साठी (i = 0; i < 2; i++) b[i] = 0

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
    स्थिर पूर्णांक cnt;

    cnt = 0;
    जर (बनाओ_लाँघ (jmp) == 0) {
        TST;
        tst2();
    }
    अन्यथा {
        cnt++;
    }
    जर (बनाओ_लाँघ (loc) == 0) {
        TST;
        tst4(loc);
    }
    अन्यथा {
        cnt++;
    }
    जर (cnt != 2)
        म_लिखो ("incorrect cnt %d\n", cnt);
}

स्थिर लाँघ_बफ buf1;
स्थिर लाँघ_बफ buf2;
स्थिर पूर्णांक *p;
स्थिर पूर्णांक n_x = 6;
स्थिर पूर्णांक g_counter;

स्थिर शून्य चळत (शून्य)
{
    स्थिर पूर्णांक counter;
    स्थिर पूर्णांक way_point1;
    स्थिर पूर्णांक way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    जर (बनाओ_लाँघ (buf1) != 101) {
        पूर्णांक a[n_x];
        g_counter++;
        p = &a[0];
        जर (g_counter < 5)
            दीर्घ_लाँघ (buf1, 2);
        अन्यथा जर (g_counter == 5)
            दीर्घ_लाँघ (buf1, 101);
        अन्यथा {
            बनाओ_लाँघ (buf2); 
            दीर्घ_लाँघ (buf1, 101);
        }
    }
    
    way_point1--;

    जर (counter == 0) {
        counter++;
        {
            पूर्णांक a[n_x];
            g_counter++;
            p = &a[0];
            जर (g_counter < 5)
                दीर्घ_लाँघ (buf1, 2);
            अन्यथा जर (g_counter == 5)
                दीर्घ_लाँघ (buf1, 101);
            अन्यथा {
                बनाओ_लाँघ (buf2);
                दीर्घ_लाँघ (buf1, 101);
            }
        }
    }

    way_point2--;

    जर (counter == 1) {
        counter++;
        दीर्घ_लाँघ (buf2, 2);
    }

    जर (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        म_लिखो ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

स्थिर लाँघ_बफ env;
स्थिर पूर्णांक last_मूल्य;

स्थिर शून्य jump (पूर्णांक val)
{
    दीर्घ_लाँघ (env, val);
}

स्थिर शून्य check (शून्य)
{
    पूर्णांक मूल्य;

    last_मूल्य = -1;
    मूल्य = बनाओ_लाँघ (env);
    जर (मूल्य != last_मूल्य + 1) {
        म_लिखो ("incorrect value %d %d\n",
                मूल्य, last_मूल्य + 1);
        परत;
    }
    last_मूल्य = मूल्य;
    निवड (मूल्य) {
#जर !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    स्थिती 0:
        jump (0);
#endif
    पूर्वनिर्धारित:
        जर (मूल्य < 10)
          jump (मूल्य + 1);
    }
}

पूर्णांक
main (शून्य)
{
    पूर्णांक i;

    साठी (i = 0; i < 10;  i++) {
        tst();
        चळत();
        check();
    }
    परत 0;
}


