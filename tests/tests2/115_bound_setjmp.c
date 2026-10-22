#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   පූර්ණ_සංඛ්‍යා i, a[2], b[2];                \
              සඳහා (i = 0; i < 2; i++) a[i] = 0; \
              සඳහා (i = 0; i < 2; i++) b[i] = 0

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
    static පූර්ණ_සංඛ්‍යා cnt;

    cnt = 0;
    නම් (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    නැතහොත් {
        cnt++;
    }
    නම් (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    නැතහොත් {
        cnt++;
    }
    නම් (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static පූර්ණ_සංඛ්‍යා *p;
static පූර්ණ_සංඛ්‍යා n_x = 6;
static පූර්ණ_සංඛ්‍යා g_counter;

static void stack (void)
{
    static පූර්ණ_සංඛ්‍යා counter;
    static පූර්ණ_සංඛ්‍යා way_point1;
    static පූර්ණ_සංඛ්‍යා way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    නම් (setjmp (buf1) != 101) {
        පූර්ණ_සංඛ්‍යා a[n_x];
        g_counter++;
        p = &a[0];
        නම් (g_counter < 5)
            longjmp (buf1, 2);
        නැතහොත් නම් (g_counter == 5)
            longjmp (buf1, 101);
        නැතහොත් {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    නම් (counter == 0) {
        counter++;
        {
            පූර්ණ_සංඛ්‍යා a[n_x];
            g_counter++;
            p = &a[0];
            නම් (g_counter < 5)
                longjmp (buf1, 2);
            නැතහොත් නම් (g_counter == 5)
                longjmp (buf1, 101);
            නැතහොත් {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    නම් (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    නම් (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static පූර්ණ_සංඛ්‍යා last_value;

static void jump (පූර්ණ_සංඛ්‍යා val)
{
    longjmp (env, val);
}

static void check (void)
{
    පූර්ණ_සංඛ්‍යා value;

    last_value = -1;
    value = setjmp (env);
    නම් (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ආපසු;
    }
    last_value = value;
    switch (value) {
#නම් !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        නම් (value < 10)
          jump (value + 1);
    }
}

පූර්ණ_සංඛ්‍යා
main (void)
{
    පූර්ණ_සංඛ්‍යා i;

    සඳහා (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ආපසු 0;
}


