/* ----------------------------------------------------------------------- */
#যদি TEST == 1
{
    কাঠামো M P A __s
    {
        unsigned x : 12;
        unsigned অক্ষর y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 2
{
    কাঠামো M P __s
    {
        পূর্ণসংখ্যা x: 12;
        অক্ষর y: 6;
        long long z:63;
        A অক্ষর a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 3
{
    কাঠামো M P __s
    {
        unsigned x:5, y:5, :0, z:5; অক্ষর a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 4
{
    কাঠামো M P __s {
        পূর্ণসংখ্যা x : 3;
        পূর্ণসংখ্যা : 2;
        পূর্ণসংখ্যা y : 1;
        পূর্ণসংখ্যা : 0;
        পূর্ণসংখ্যা z : 5;
        পূর্ণসংখ্যা a : 7;
        unsigned পূর্ণসংখ্যা b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 5
{
    কাঠামো M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        অক্ষর a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 6
{
    কাঠামো M P __s {
	পূর্ণসংখ্যা a;
	signed অক্ষর b;
	পূর্ণসংখ্যা x : 12, y : 4, : 0, : 4, z : 3;
	অক্ষর d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি TEST == 7
{
#ifdef _WIN32
    প্রকারলেখ long long পূর্ণসংখ্যা ll;
#অন্যথা
    প্রকারলেখ long পূর্ণসংখ্যা ll;
#endif
    কাঠামো M P __s {
        ll d : 16;
        ll b : 16;
        ll x : 16;
        ll y : 1;
        ll z : 2;
        ll a : 11;
        ll e : 1;
        ll f : 1;
    };
    TEST_STRUCT(1,2,3,4,5);
}

/* ----------------------------------------------------------------------- */
#নতুবা_যদি defined PACK

#যদি PACK
# pragma pack(ঠেলো,1)
# define P //_P
#অন্যথা
# define P
#endif

printf("\n\n" + 2*শীর্ষ);
#define TEST 1
#অন্তর্ভাব SELF
শীর্ষ = 0;
#define TEST 2
#অন্তর্ভাব SELF
#define TEST 3
#অন্তর্ভাব SELF
#define TEST 4
#অন্তর্ভাব SELF
#define TEST 5
#অন্তর্ভাব SELF
#define TEST 6
#অন্তর্ভাব SELF
#define TEST 7
#অন্তর্ভাব SELF

#যদি PACK
# pragma pack(বের_করো)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#নতুবা_যদি defined ALIGN

#যদি ALIGN
# define A _A(16)
#অন্যথা
# define A
#endif

#define PACK 0
#অন্তর্ভাব SELF
#define PACK 1
#অন্তর্ভাব SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#নতুবা_যদি defined MS_BF

#যদি MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#অন্যথা
# ifdef __TINYC__
#  pragma comment(option, "-mno-ms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((gcc_struct))
# endif
#endif
#ifndef M
# define M
#endif

#define ALIGN 0
#অন্তর্ভাব SELF
#define ALIGN 1
#অন্তর্ভাব SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#অন্যথা

#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

শূন্য dump(শূন্য *p, পূর্ণসংখ্যা s)
{
    পূর্ণসংখ্যা i;
    জন্য (i = s; --i >= 0;)
        printf("%02X", ((unsigned অক্ষর*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(আকার (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        কাঠামো __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + শীর্ষ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, আকার *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, আকার *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, আকার *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(কাঠামো __s),আকার(কাঠামো __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#অন্যথা
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

পূর্ণসংখ্যা শীর্ষ = 1;

পূর্ণসংখ্যা প্রধান()
{
#define MS_BF MS_BITFIELDS
#অন্তর্ভাব SELF
    ফেরত 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
