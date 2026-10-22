#അന്തര്ഭാവ<stdio.h>

ഘടന s1 {
    unsigned അക്ഷരം a:4, b:4;
} g1 = { 0x05, 0x0a };

ഘടന s2 {
    unsigned അക്ഷരം a, b;
} g2 = { 0x12, 0x34 };

ഘടന s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

ഘടന s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
ഘടന s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
ഘടന s_f4 {
    ഇരട്ട a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
ഘടന s##S f##S(പൂർണ്ണസംഖ്യ x) \
{ \
    ഘടന s##S l##S = g##S, *p##S = &l##S; \
    എങ്കിൽ (x == 0) \
        തിരികെ g##S; \
    അല്ലെങ്കിൽ എങ്കിൽ (x == 1) \
        തിരികെ l##S; \
    അല്ലെങ്കിൽ \
        തിരികെ *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    ഘടന s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    വേണ്ടി (പൂർണ്ണസംഖ്യ x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        ഘടന s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        എങ്കിൽ (++x > 2)
            നിർത്തുക;
        printf("\n");
    }
    തിരികെ 0;
}
