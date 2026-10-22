#அந்தர்பாவ<stdio.h>

கட்டமைப்பு s1 {
    unsigned எழுத்து a:4, b:4;
} g1 = { 0x05, 0x0a };

கட்டமைப்பு s2 {
    unsigned எழுத்து a, b;
} g2 = { 0x12, 0x34 };

கட்டமைப்பு s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

கட்டமைப்பு s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
கட்டமைப்பு s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
கட்டமைப்பு s_f4 {
    இரட்டை a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
கட்டமைப்பு s##S f##S(முழு x) \
{ \
    கட்டமைப்பு s##S l##S = g##S, *p##S = &l##S; \
    எனில் (x == 0) \
        திரும்பு g##S; \
    இல்லையெனில் எனில் (x == 1) \
        திரும்பு l##S; \
    இல்லையெனில் \
        திரும்பு *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    கட்டமைப்பு s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

முழு முதன்மை()
{
    க்கு (முழு x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        கட்டமைப்பு s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        எனில் (++x > 2)
            நிறுத்து;
        printf("\n");
    }
    திரும்பு 0;
}
