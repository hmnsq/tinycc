#অন্তর্ভাব<stdio.h>

কাঠামো s1 {
    unsigned অক্ষর a:4, b:4;
} g1 = { 0x05, 0x0a };

কাঠামো s2 {
    unsigned অক্ষর a, b;
} g2 = { 0x12, 0x34 };

কাঠামো s4 {
    unsigned short a, b;
} g4 = { 0x1245, 0x5678 };

কাঠামো s8 {
    unsigned a, b;
} g8 = { 0x12345678, 0x9abcdef0 };

/* returned in 2 registers on riscv64 */
কাঠামো s16 {
    unsigned long long a, b;
} g16 = { 0x123456789abcdef0ULL, 0xfedcba9876543210ULL };

/* Homogeneous float aggregate on ARM hard-float */
কাঠামো s_f4 {
    দ্বিগুণ a, b, c, d;
} g_f4 = { 1,2,3,4 };

#define def(S) \
কাঠামো s##S f##S(পূর্ণসংখ্যা x) \
{ \
    কাঠামো s##S l##S = g##S, *p##S = &l##S; \
    যদি (x == 0) \
        ফেরত g##S; \
    অন্যথা যদি (x == 1) \
        ফেরত l##S; \
    অন্যথা \
        ফেরত *p##S; \
}

def(1)
def(2)
def(4)
def(8)
def(16)
def(_f4)

#define chk(S,x) \
    কাঠামো s##S l##S = f##S(x); \
    printf("%02llx %02llx\n", \
        (unsigned long long)l##S.a, \
        (unsigned long long)l##S.b \
        );

পূর্ণসংখ্যা প্রধান()
{
    জন্য (পূর্ণসংখ্যা x = 0;;) {
        chk(1,x);
        chk(2,x);
        chk(4,x);
        chk(8,x);
        chk(16,x);
        কাঠামো s_f4 l_f4 = f_f4(x);
        printf("%.1f %.1f %.1f %.1f\n", l_f4.a, l_f4.b, l_f4.c, l_f4.d);
        যদি (++x > 2)
            বিরতি;
        printf("\n");
    }
    ফেরত 0;
}
