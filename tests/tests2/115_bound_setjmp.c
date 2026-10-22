#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   целое i, a[2], b[2];                \
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
    static целое cnt;

    cnt = 0;
    если (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    иначе {
        cnt++;
    }
    если (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    иначе {
        cnt++;
    }
    если (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static целое *p;
static целое n_x = 6;
static целое g_counter;

static void stack (void)
{
    static целое counter;
    static целое way_point1;
    static целое way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    если (setjmp (buf1) != 101) {
        целое a[n_x];
        g_counter++;
        p = &a[0];
        если (g_counter < 5)
            longjmp (buf1, 2);
        иначе если (g_counter == 5)
            longjmp (buf1, 101);
        иначе {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    если (counter == 0) {
        counter++;
        {
            целое a[n_x];
            g_counter++;
            p = &a[0];
            если (g_counter < 5)
                longjmp (buf1, 2);
            иначе если (g_counter == 5)
                longjmp (buf1, 101);
            иначе {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    если (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    если (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static целое last_value;

static void jump (целое val)
{
    longjmp (env, val);
}

static void check (void)
{
    целое value;

    last_value = -1;
    value = setjmp (env);
    если (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        вернуть;
    }
    last_value = value;
    switch (value) {
#если !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    case 0:
        jump (0);
#endif
    default:
        если (value < 10)
          jump (value + 1);
    }
}

целое
основной (void)
{
    целое i;

    для (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    вернуть 0;
}


