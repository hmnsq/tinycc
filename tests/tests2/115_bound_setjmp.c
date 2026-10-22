#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   ຈຳນວນເຕັມ i, a[2], b[2];                \
              ສຳລັບ (i = 0; i < 2; i++) a[i] = 0; \
              ສຳລັບ (i = 0; i < 2; i++) b[i] = 0

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
    static ຈຳນວນເຕັມ cnt;

    cnt = 0;
    ຖ້າ (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    ບໍ່ດັ່ງນັ້ນ {
        cnt++;
    }
    ຖ້າ (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    ບໍ່ດັ່ງນັ້ນ {
        cnt++;
    }
    ຖ້າ (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static ຈຳນວນເຕັມ *p;
static ຈຳນວນເຕັມ n_x = 6;
static ຈຳນວນເຕັມ g_counter;

static void stack (void)
{
    static ຈຳນວນເຕັມ counter;
    static ຈຳນວນເຕັມ way_point1;
    static ຈຳນວນເຕັມ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    ຖ້າ (setjmp (buf1) != 101) {
        ຈຳນວນເຕັມ a[n_x];
        g_counter++;
        p = &a[0];
        ຖ້າ (g_counter < 5)
            longjmp (buf1, 2);
        ບໍ່ດັ່ງນັ້ນ ຖ້າ (g_counter == 5)
            longjmp (buf1, 101);
        ບໍ່ດັ່ງນັ້ນ {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    ຖ້າ (counter == 0) {
        counter++;
        {
            ຈຳນວນເຕັມ a[n_x];
            g_counter++;
            p = &a[0];
            ຖ້າ (g_counter < 5)
                longjmp (buf1, 2);
            ບໍ່ດັ່ງນັ້ນ ຖ້າ (g_counter == 5)
                longjmp (buf1, 101);
            ບໍ່ດັ່ງນັ້ນ {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    ຖ້າ (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    ຖ້າ (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static ຈຳນວນເຕັມ last_value;

static void jump (ຈຳນວນເຕັມ val)
{
    longjmp (env, val);
}

static void check (void)
{
    ຈຳນວນເຕັມ value;

    last_value = -1;
    value = setjmp (env);
    ຖ້າ (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ສົ່ງຄືນ;
    }
    last_value = value;
    switch (value) {
#ຖ້າ !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        ຖ້າ (value < 10)
          jump (value + 1);
    }
}

ຈຳນວນເຕັມ
main (void)
{
    ຈຳນວນເຕັມ i;

    ສຳລັບ (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ສົ່ງຄືນ 0;
}


