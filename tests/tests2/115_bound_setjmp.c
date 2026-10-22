#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   puur_naa_nka i, a[2], b[2];                \
              for (i = 0; i < 2; i++) a[i] = 0; \
              for (i = 0; i < 2; i++) b[i] = 0

static jmp_buf jmp;

static void tst1 (void)
{
    TST;
    longjmp(jmp, 1);
}

static void tst2(void)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1();
}

static void tst3 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

static void tst4(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst3(loc);
}

static void tst (void)
{
    jmp_buf loc;
    static puur_naa_nka cnt;

    cnt = 0;
    ᯀᯮᯝ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ᯀᯮᯝᯂᯪ {
        cnt++;
    }
    ᯀᯮᯝ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ᯀᯮᯝᯂᯪ {
        cnt++;
    }
    ᯀᯮᯝ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static puur_naa_nka *p;
static puur_naa_nka n_x = 6;
static puur_naa_nka g_counter;

static void stack (void)
{
    static puur_naa_nka counter;
    static puur_naa_nka way_point1;
    static puur_naa_nka way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ᯀᯮᯝ (setjmp (buf1) != 101) {
        puur_naa_nka a[n_x];
        g_counter++;
        p = &a[0];
        ᯀᯮᯝ (g_counter < 5)
            longjmp (buf1, 2);
        ᯀᯮᯝᯂᯪ ᯀᯮᯝ (g_counter == 5)
            longjmp (buf1, 101);
        ᯀᯮᯝᯂᯪ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ᯀᯮᯝ (counter == 0) {
        counter++;
        {
            puur_naa_nka a[n_x];
            g_counter++;
            p = &a[0];
            ᯀᯮᯝ (g_counter < 5)
                longjmp (buf1, 2);
            ᯀᯮᯝᯂᯪ ᯀᯮᯝ (g_counter == 5)
                longjmp (buf1, 101);
            ᯀᯮᯝᯂᯪ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ᯀᯮᯝ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ᯀᯮᯝ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static puur_naa_nka last_value;

static void jump (puur_naa_nka val)
{
    longjmp (env, val);
}

static void check (void)
{
    puur_naa_nka value;

    last_value = -1;
    value = setjmp (env);
    ᯀᯮᯝ (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ᯀᯮᯞ;
    }
    last_value = value;
    switch (value) {
#ᯀᯮᯝ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        ᯀᯮᯝ (value < 10)
          jump (value + 1);
    }
}

puur_naa_nka
main (void)
{
    puur_naa_nka i;

    for (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ᯀᯮᯞ 0;
}


