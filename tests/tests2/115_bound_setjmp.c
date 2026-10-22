#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <setjmp.h>

#define TST   முழு i, a[2], b[2];                \
              க்கு (i = 0; i < 2; i++) a[i] = 0; \
              க்கு (i = 0; i < 2; i++) b[i] = 0

நிலையான jmp_buf jmp;

நிலையான வெறுமை tst1 (வெறுமை)
{
    TST;
    longjmp(jmp, 1);
}

நிலையான வெறுமை tst2(வெறுமை)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

நிலையான வெறுமை tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

நிலையான வெறுமை tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

நிலையான வெறுமை tst (வெறுமை)
{
    jmp_buf loc;
    நிலையான முழு cnt;

    cnt = 0;
    எனில் (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    இல்லையெனில் {
        cnt++;
    }
    எனில் (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    இல்லையெனில் {
        cnt++;
    }
    எனில் (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

நிலையான jmp_buf buf1;
நிலையான jmp_buf buf2;
நிலையான முழு *p;
நிலையான முழு n_x = 6;
நிலையான முழு g_counter;

நிலையான வெறுமை அடுக்கு (வெறுமை)
{
    நிலையான முழு counter;
    நிலையான முழு way_point1;
    நிலையான முழு way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    எனில் (setjmp (buf1) != 101) {
        முழு a[n_x];
        g_counter++;
        p = &a[0];
        எனில் (g_counter < 5)
            longjmp (buf1, 2);
        இல்லையெனில் எனில் (g_counter == 5)
            longjmp (buf1, 101);
        இல்லையெனில் {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    எனில் (counter == 0) {
        counter++;
        {
            முழு a[n_x];
            g_counter++;
            p = &a[0];
            எனில் (g_counter < 5)
                longjmp (buf1, 2);
            இல்லையெனில் எனில் (g_counter == 5)
                longjmp (buf1, 101);
            இல்லையெனில் {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    எனில் (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    எனில் (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

நிலையான jmp_buf env;
நிலையான முழு last_மதிப்பு;

நிலையான வெறுமை jump (முழு val)
{
    longjmp (env, val);
}

நிலையான வெறுமை check (வெறுமை)
{
    முழு மதிப்பு;

    last_மதிப்பு = -1;
    மதிப்பு = setjmp (env);
    எனில் (மதிப்பு != last_மதிப்பு + 1) {
        printf ("incorrect value %d %d\n",
                மதிப்பு, last_மதிப்பு + 1);
        திரும்பு;
    }
    last_மதிப்பு = மதிப்பு;
    தேர்வு (மதிப்பு) {
#எனில் !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    நிலை 0:
        jump (0);
#endif
    இயல்பு:
        எனில் (மதிப்பு < 10)
          jump (மதிப்பு + 1);
    }
}

முழு
முதன்மை (வெறுமை)
{
    முழு i;

    க்கு (i = 0; i < 10;  i++) {
        tst();
        அடுக்கு();
        check();
    }
    திரும்பு 0;
}


