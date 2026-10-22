#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   ціле i, a[2], b[2];                \
              для (i = 0; i < 2; i++) a[i] = 0; \
              для (i = 0; i < 2; i++) b[i] = 0

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
    static ціле cnt;

    cnt = 0;
    якщо (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    інакше {
        cnt++;
    }
    якщо (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    інакше {
        cnt++;
    }
    якщо (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static ціле *p;
static ціле n_x = 6;
static ціле g_counter;

static void stack (void)
{
    static ціле counter;
    static ціле way_point1;
    static ціле way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    якщо (setjmp (buf1) != 101) {
        ціле a[n_x];
        g_counter++;
        p = &a[0];
        якщо (g_counter < 5)
            longjmp (buf1, 2);
        інакше якщо (g_counter == 5)
            longjmp (buf1, 101);
        інакше {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    якщо (counter == 0) {
        counter++;
        {
            ціле a[n_x];
            g_counter++;
            p = &a[0];
            якщо (g_counter < 5)
                longjmp (buf1, 2);
            інакше якщо (g_counter == 5)
                longjmp (buf1, 101);
            інакше {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    якщо (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    якщо (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static ціле last_value;

static void jump (ціле val)
{
    longjmp (env, val);
}

static void check (void)
{
    ціле value;

    last_value = -1;
    value = setjmp (env);
    якщо (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        повернути;
    }
    last_value = value;
    switch (value) {
#якщо !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    case 0:
        jump (0);
#endif
    default:
        якщо (value < 10)
          jump (value + 1);
    }
}

ціле
main (void)
{
    ціле i;

    для (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    повернути 0;
}


