#include <stdio.h>
#include <string.h>
#include <setjmp.h>

#define TST   ཧྲིལ i, a[2], b[2];                \
              དོན་ལུ (i = 0; i < 2; i++) a[i] = 0; \
              དོན་ལུ (i = 0; i < 2; i++) b[i] = 0

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
    static ཧྲིལ cnt;

    cnt = 0;
    གལ་སྲིད (setjmp (jmp) == 0) {
        TST;
        tst2();
    }
    དེ་མིན {
        cnt++;
    }
    གལ་སྲིད (setjmp (loc) == 0) {
        TST;
        tst4(loc);
    }
    དེ་མིན {
        cnt++;
    }
    གལ་སྲིད (cnt != 2)
        printf ("incorrect cnt %d\n", cnt);
}

static jmp_buf buf1;
static jmp_buf buf2;
static ཧྲིལ *p;
static ཧྲིལ n_x = 6;
static ཧྲིལ g_counter;

static void stack (void)
{
    static ཧྲིལ counter;
    static ཧྲིལ way_point1;
    static ཧྲིལ way_point2;

    counter = 0;
    way_point1 = 3;
    way_point2 = 2;
    g_counter = 0;
    གལ་སྲིད (setjmp (buf1) != 101) {
        ཧྲིལ a[n_x];
        g_counter++;
        p = &a[0];
        གལ་སྲིད (g_counter < 5)
            longjmp (buf1, 2);
        དེ་མིན གལ་སྲིད (g_counter == 5)
            longjmp (buf1, 101);
        དེ་མིན {
            setjmp (buf2); 
            longjmp (buf1, 101);
        }
    }
    
    way_point1--;

    གལ་སྲིད (counter == 0) {
        counter++;
        {
            ཧྲིལ a[n_x];
            g_counter++;
            p = &a[0];
            གལ་སྲིད (g_counter < 5)
                longjmp (buf1, 2);
            དེ་མིན གལ་སྲིད (g_counter == 5)
                longjmp (buf1, 101);
            དེ་མིན {
                setjmp (buf2);
                longjmp (buf1, 101);
            }
        }
    }

    way_point2--;

    གལ་སྲིད (counter == 1) {
        counter++;
        longjmp (buf2, 2);
    }

    གལ་སྲིད (!(way_point1 == 0 && way_point2 == 0 &&
          g_counter == 6 && counter == 2))
        printf ("Failed %d %d %d %d\n",
                way_point1, way_point2, g_counter, counter);
}

static jmp_buf env;
static ཧྲིལ last_value;

static void jump (ཧྲིལ val)
{
    longjmp (env, val);
}

static void check (void)
{
    ཧྲིལ value;

    last_value = -1;
    value = setjmp (env);
    གལ་སྲིད (value != last_value + 1) {
        printf ("incorrect value %d %d\n",
                value, last_value + 1);
        ལོག;
    }
    last_value = value;
    switch (value) {
#གལ་སྲིད !(defined(__FreeBSD__) || defined(__NetBSD__))
    /* longjmp(jmp_buf, 0) not supported */
    pak_sa 0:
        jump (0);
#endif
    default:
        གལ་སྲིད (value < 10)
          jump (value + 1);
    }
}

ཧྲིལ
main (void)
{
    ཧྲིལ i;

    དོན་ལུ (i = 0; i < 10;  i++) {
        tst();
        stack();
        check();
    }
    ལོག 0;
}


