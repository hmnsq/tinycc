#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   цяло i, a[2], b[2];                \
              за (i = 0; i < 2; i++) a[i] = 0; \
              за (i = 0; i < 2; i++) b[i] = 0

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
    static цяло cnt;

    cnt = 0;
    ако (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    иначе {
        cnt++;
    }
    ако (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    иначе {
        cnt++;
    }
    ако (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static цяло *p;
static цяло n_x = 6;
static цяло g_counter;

static void stack (void)
{
    static цяло counter;
    static цяло way_point1;
    static цяло way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ако (setjmp (buf1) != 101) {
        цяло a[n_x];
        g_counter++;
        p = &a[0];
        ако (g_counter < 5)
            longjmp (buf1, 2);
        иначе ако (g_counter == 5)
            longjmp (buf1, 101);
        иначе {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ако (counter == 0) {
        counter++;
        {
            цяло a[n_x];
            g_counter++;
            p = &a[0];
            ако (g_counter < 5)
                longjmp (buf1, 2);
            иначе ако (g_counter == 5)
                longjmp (buf1, 101);
            иначе {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ако (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ако (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static цяло last_value;

static void jump (цяло val)
{
    longjmp (env, val);
}

static void check (void)
{
    цяло value;

    last_value = -1;
    value = setjmp (env);
    ако (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        върни;
    }
    last_value = value;
    switch (value) {
#ако !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    case 0:
        jump (0);
#endif
    default:
        ако (value < 10)
          jump (value + 1);
    }
}

цяло
main (void)
{
    цяло i;

    за (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    върни 0;
}


