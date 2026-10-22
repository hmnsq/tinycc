#अन्तर्भाव<stdio.h>

संरचना s1 {
    unsigned वर्ण a:4, b:4;
} g1 = { 0x05, 0x0a };

संरचना s2 {
    unsigned वर्ण a, b;
} g2 = { 0x12, 0x34 };

संरचना s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

संरचना s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
संरचना s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
संरचना s_f4 {
    द्विगुण a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
संरचना s##S f##S(पूर्णाङ्क x) \
{ \
    संरचना s##S l##S = g##S, *p##S = &l##S; \
    सचे (x == 0) \
        पटिनिवत्त g##S; \
    अञ्ञथा सचे (x == 1) \
        पटिनिवत्त l##S; \
    अञ्ञथा \
        पटिनिवत्त *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    संरचना s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

पूर्णाङ्क main()
{
    अत्थाय (पूर्णाङ्क x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        संरचना s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        सचे (++x > 2)
            भङ्ग;
        printf("\n");
    }
    पटिनिवत्त 0;
}
