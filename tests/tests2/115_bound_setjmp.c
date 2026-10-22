#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   정수 i, a[2], b[2];                \
              위해 (i = 0; i < 2; i++) a[i] = 0; \
              위해 (i = 0; i < 2; i++) b[i] = 0

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
    static 정수 cnt;

    cnt = 0;
    만약 (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    아니면 {
        cnt++;
    }
    만약 (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    아니면 {
        cnt++;
    }
    만약 (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static 정수 *p;
static 정수 n_x = 6;
static 정수 g_counter;

static void stack (void)
{
    static 정수 counter;
    static 정수 way_point1;
    static 정수 way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    만약 (setjmp (buf1) != 101) {
        정수 a[n_x];
        g_counter++;
        p = &a[0];
        만약 (g_counter < 5)
            longjmp (buf1, 2);
        아니면 만약 (g_counter == 5)
            longjmp (buf1, 101);
        아니면 {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    만약 (counter == 0) {
        counter++;
        {
            정수 a[n_x];
            g_counter++;
            p = &a[0];
            만약 (g_counter < 5)
                longjmp (buf1, 2);
            아니면 만약 (g_counter == 5)
                longjmp (buf1, 101);
            아니면 {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    만약 (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    만약 (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static 정수 last_value;

static void jump (정수 val)
{
    longjmp (env, val);
}

static void check (void)
{
    정수 value;

    last_value = -1;
    value = setjmp (env);
    만약 (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        반환;
    }
    last_value = value;
    switch (value) {
#만약 !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    case 0:
        jump (0);
#endif
    default:
        만약 (value < 10)
          jump (value + 1);
    }
}

정수
main (void)
{
    정수 i;

    위해 (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    반환 0;
}


