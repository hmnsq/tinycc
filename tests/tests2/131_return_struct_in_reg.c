#include<stdio.h>

sa_nracanaa s1 {
    unsigned var_na a:4, b:4;
} g1 = { 0x05, 0x0a };

sa_nracanaa s2 {
    unsigned var_na a, b;
} g2 = { 0x12, 0x34 };

sa_nracanaa s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

sa_nracanaa s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
sa_nracanaa s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
sa_nracanaa s_f4 {
    dviguu_na a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
sa_nracanaa s##S f##S(පූර්ණ_සංඛ්‍යා x) \
{ \
    sa_nracanaa s##S l##S = g##S, *p##S = &l##S; \
    නම් (x == 0) \
        ආපසු g##S; \
    නැතහොත් නම් (x == 1) \
        ආපසු l##S; \
    නැතහොත් \
        ආපසු *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    sa_nracanaa s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

පූර්ණ_සංඛ්‍යා main()
{
    සඳහා (පූර්ණ_සංඛ්‍යා x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        sa_nracanaa s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        නම් (++x > 2)
            bha_nga;
        printf("\n");
    }
    ආපසු 0;
}
