#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   ចំនួនគត់ i, a[2], b[2];                \
              សម្រាប់ (i = 0; i < 2; i++) a[i] = 0; \
              សម្រាប់ (i = 0; i < 2; i++) b[i] = 0

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
    static ចំនួនគត់ cnt;

    cnt = 0;
    ប្រសិនបើ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    បើមិនដូច្នេះ {
        cnt++;
    }
    ប្រសិនបើ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    បើមិនដូច្នេះ {
        cnt++;
    }
    ប្រសិនបើ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static ចំនួនគត់ *p;
static ចំនួនគត់ n_x = 6;
static ចំនួនគត់ g_counter;

static void stack (void)
{
    static ចំនួនគត់ counter;
    static ចំនួនគត់ way_point1;
    static ចំនួនគត់ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ប្រសិនបើ (setjmp (buf1) != 101) {
        ចំនួនគត់ a[n_x];
        g_counter++;
        p = &a[0];
        ប្រសិនបើ (g_counter < 5)
            longjmp (buf1, 2);
        បើមិនដូច្នេះ ប្រសិនបើ (g_counter == 5)
            longjmp (buf1, 101);
        បើមិនដូច្នេះ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ប្រសិនបើ (counter == 0) {
        counter++;
        {
            ចំនួនគត់ a[n_x];
            g_counter++;
            p = &a[0];
            ប្រសិនបើ (g_counter < 5)
                longjmp (buf1, 2);
            បើមិនដូច្នេះ ប្រសិនបើ (g_counter == 5)
                longjmp (buf1, 101);
            បើមិនដូច្នេះ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ប្រសិនបើ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ប្រសិនបើ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static ចំនួនគត់ last_value;

static void jump (ចំនួនគត់ val)
{
    longjmp (env, val);
}

static void check (void)
{
    ចំនួនគត់ value;

    last_value = -1;
    value = setjmp (env);
    ប្រសិនបើ (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ត្រឡប់;
    }
    last_value = value;
    switch (value) {
#ប្រសិនបើ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        ប្រសិនបើ (value < 10)
          jump (value + 1);
    }
}

ចំនួនគត់
main (void)
{
    ចំនួនគត់ i;

    សម្រាប់ (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ត្រឡប់ 0;
}


