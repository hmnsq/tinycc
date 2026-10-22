#અન્તર્ભાવ<stdio.h>

સંરચના s1 {
    unsigned અક્ષર a:4, b:4;
} g1 = { 0x05, 0x0a };

સંરચના s2 {
    unsigned અક્ષર a, b;
} g2 = { 0x12, 0x34 };

સંરચના s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

સંરચના s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
સંરચના s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
સંરચના s_f4 {
    દ્વિગુણ a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
સંરચના s##S f##S(પૂર્ણાંક x) \
{ \
    સંરચના s##S l##S = g##S, *p##S = &l##S; \
    જો (x == 0) \
        પાછા g##S; \
    નહીંતર જો (x == 1) \
        પાછા l##S; \
    નહીંતર \
        પાછા *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    સંરચના s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

પૂર્ણાંક મુખ્ય()
{
    માટે (પૂર્ણાંક x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        સંરચના s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        જો (++x > 2)
            તોડો;
        printf("\n");
    }
    પાછા 0;
}
