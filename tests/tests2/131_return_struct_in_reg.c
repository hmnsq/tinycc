#ಅನ್ತರ್ಭಾವ<stdio.h>

ಸಂರಚನಾ s1 {
    unsigned ವರ್ಣ a:4, b:4;
} g1 = { 0x05, 0x0a };

ಸಂರಚನಾ s2 {
    unsigned ವರ್ಣ a, b;
} g2 = { 0x12, 0x34 };

ಸಂರಚನಾ s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

ಸಂರಚನಾ s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
ಸಂರಚನಾ s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
ಸಂರಚನಾ s_f4 {
    ದ್ವಿಗುಣ a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
ಸಂರಚನಾ s##S f##S(ಪೂರ್ಣಾಙ್ಕ x) \
{ \
    ಸಂರಚನಾ s##S l##S = g##S, *p##S = &l##S; \
    ಯದಿ (x == 0) \
        ಪ್ರತ್ಯಾಗಮ g##S; \
    ಅನ್ಯಥಾ ಯದಿ (x == 1) \
        ಪ್ರತ್ಯಾಗಮ l##S; \
    ಅನ್ಯಥಾ \
        ಪ್ರತ್ಯಾಗಮ *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    ಸಂರಚನಾ s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        ಸಂರಚನಾ s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        ಯದಿ (++x > 2)
            ಭಙ್ಗ;
        printf("\n");
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}
