#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   จำนวนเต็ม i, a[2], b[2];                \
              สำหรับ (i = 0; i < 2; i++) a[i] = 0; \
              สำหรับ (i = 0; i < 2; i++) b[i] = 0

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
    static จำนวนเต็ม cnt;

    cnt = 0;
    ถ้า (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    มิฉะนั้น {
        cnt++;
    }
    ถ้า (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    มิฉะนั้น {
        cnt++;
    }
    ถ้า (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static จำนวนเต็ม *p;
static จำนวนเต็ม n_x = 6;
static จำนวนเต็ม g_counter;

static void stack (void)
{
    static จำนวนเต็ม counter;
    static จำนวนเต็ม way_point1;
    static จำนวนเต็ม way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ถ้า (setjmp (buf1) != 101) {
        จำนวนเต็ม a[n_x];
        g_counter++;
        p = &a[0];
        ถ้า (g_counter < 5)
            longjmp (buf1, 2);
        มิฉะนั้น ถ้า (g_counter == 5)
            longjmp (buf1, 101);
        มิฉะนั้น {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ถ้า (counter == 0) {
        counter++;
        {
            จำนวนเต็ม a[n_x];
            g_counter++;
            p = &a[0];
            ถ้า (g_counter < 5)
                longjmp (buf1, 2);
            มิฉะนั้น ถ้า (g_counter == 5)
                longjmp (buf1, 101);
            มิฉะนั้น {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ถ้า (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ถ้า (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static จำนวนเต็ม last_value;

static void jump (จำนวนเต็ม val)
{
    longjmp (env, val);
}

static void check (void)
{
    จำนวนเต็ม value;

    last_value = -1;
    value = setjmp (env);
    ถ้า (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        คืน;
    }
    last_value = value;
    switch (value) {
#ถ้า !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        ถ้า (value < 10)
          jump (value + 1);
    }
}

จำนวนเต็ม
หลัก (void)
{
    จำนวนเต็ม i;

    สำหรับ (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    คืน 0;
}


