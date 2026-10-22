#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   số_nguyên i, a[2], b[2];                \
              cho (i = 0; i < 2; i++) a[i] = 0; \
              cho (i = 0; i < 2; i++) b[i] = 0

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
    static số_nguyên cnt;

    cnt = 0;
    nếu (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    không_thì {
        cnt++;
    }
    nếu (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    không_thì {
        cnt++;
    }
    nếu (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static số_nguyên *p;
static số_nguyên n_x = 6;
static số_nguyên g_counter;

static void stack (void)
{
    static số_nguyên counter;
    static số_nguyên way_point1;
    static số_nguyên way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    nếu (setjmp (buf1) != 101) {
        số_nguyên a[n_x];
        g_counter++;
        p = &a[0];
        nếu (g_counter < 5)
            longjmp (buf1, 2);
        không_thì nếu (g_counter == 5)
            longjmp (buf1, 101);
        không_thì {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    nếu (counter == 0) {
        counter++;
        {
            số_nguyên a[n_x];
            g_counter++;
            p = &a[0];
            nếu (g_counter < 5)
                longjmp (buf1, 2);
            không_thì nếu (g_counter == 5)
                longjmp (buf1, 101);
            không_thì {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    nếu (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    nếu (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static số_nguyên last_value;

static void jump (số_nguyên val)
{
    longjmp (env, val);
}

static void check (void)
{
    số_nguyên value;

    last_value = -1;
    value = setjmp (env);
    nếu (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        trả_về;
    }
    last_value = value;
    switch (value) {
#nếu !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    case 0:
        jump (0);
#endif
    default:
        nếu (value < 10)
          jump (value + 1);
    }
}

số_nguyên
main (void)
{
    số_nguyên i;

    cho (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    trả_về 0;
}


