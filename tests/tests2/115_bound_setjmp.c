#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   ကိန်းပြည့် i, a[2], b[2];                \
              အတွက် (i = 0; i < 2; i++) a[i] = 0; \
              အတွက် (i = 0; i < 2; i++) b[i] = 0

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
    static ကိန်းပြည့် cnt;

    cnt = 0;
    အကယ်၍ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    မဟုတ်ပါက {
        cnt++;
    }
    အကယ်၍ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    မဟုတ်ပါက {
        cnt++;
    }
    အကယ်၍ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static ကိန်းပြည့် *p;
static ကိန်းပြည့် n_x = 6;
static ကိန်းပြည့် g_counter;

static void stack (void)
{
    static ကိန်းပြည့် counter;
    static ကိန်းပြည့် way_point1;
    static ကိန်းပြည့် way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    အကယ်၍ (setjmp (buf1) != 101) {
        ကိန်းပြည့် a[n_x];
        g_counter++;
        p = &a[0];
        အကယ်၍ (g_counter < 5)
            longjmp (buf1, 2);
        မဟုတ်ပါက အကယ်၍ (g_counter == 5)
            longjmp (buf1, 101);
        မဟုတ်ပါက {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    အကယ်၍ (counter == 0) {
        counter++;
        {
            ကိန်းပြည့် a[n_x];
            g_counter++;
            p = &a[0];
            အကယ်၍ (g_counter < 5)
                longjmp (buf1, 2);
            မဟုတ်ပါက အကယ်၍ (g_counter == 5)
                longjmp (buf1, 101);
            မဟုတ်ပါက {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    အကယ်၍ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    အကယ်၍ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static ကိန်းပြည့် last_value;

static void jump (ကိန်းပြည့် val)
{
    longjmp (env, val);
}

static void check (void)
{
    ကိန်းပြည့် value;

    last_value = -1;
    value = setjmp (env);
    အကယ်၍ (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ပြန်ပေး;
    }
    last_value = value;
    switch (value) {
#အကယ်၍ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        အကယ်၍ (value < 10)
          jump (value + 1);
    }
}

ကိန်းပြည့်
main (void)
{
    ကိန်းပြည့် i;

    အတွက် (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ပြန်ပေး 0;
}


