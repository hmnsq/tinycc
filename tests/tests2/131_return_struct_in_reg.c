#ଅନ୍ତର୍ଭାଵ<stdio.h>

ସଂରଚନା s1 {
    unsigned ଅକ୍ଷର a:4, b:4;
} g1 = { 0x05, 0x0a };

ସଂରଚନା s2 {
    unsigned ଅକ୍ଷର a, b;
} g2 = { 0x12, 0x34 };

ସଂରଚନା s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

ସଂରଚନା s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
ସଂରଚନା s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
ସଂରଚନା s_f4 {
    ଦ୍ୱିଗୁଣ a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
ସଂରଚନା s##S f##S(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x) \
{ \
    ସଂରଚନା s##S l##S = g##S, *p##S = &l##S; \
    ଯଦି (x == 0) \
        ଫେରନ୍ତୁ g##S; \
    ଅନ୍ୟଥା ଯଦି (x == 1) \
        ଫେରନ୍ତୁ l##S; \
    ଅନ୍ୟଥା \
        ଫେରନ୍ତୁ *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    ସଂରଚନା s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        ସଂରଚନା s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        ଯଦି (++x > 2)
            ଭାଙ୍ଗ;
        printf("\n");
    }
    ଫେରନ୍ତୁ 0;
}
