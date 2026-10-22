#شامل<stdio.h>

ساختار s1 {
    unsigned نویسه a:4, b:4;
} g1 = { 0x05, 0x0a };

ساختار s2 {
    unsigned نویسه a, b;
} g2 = { 0x12, 0x34 };

ساختار s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

ساختار s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
ساختار s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
ساختار s_f4 {
    دوگانه a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
ساختار s##S f##S(صحیح x) \
{ \
    ساختار s##S l##S = g##S, *p##S = &l##S; \
    اگر (x == 0) \
        بازگشت g##S; \
    وگرنه اگر (x == 1) \
        بازگشت l##S; \
    وگرنه \
        بازگشت *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    ساختار s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

صحیح اصلی()
{
    برای (صحیح x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        ساختار s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        اگر (++x > 2)
            بشکن;
        printf("\n");
    }
    بازگشت 0;
}
