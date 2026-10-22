/* ----------------------------------------------------------------------- */
#যদি TEST == 1
{
    সংরচনা M P A __s
    {
        unsigned x : 12;
        unsigned বর্ণ y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 2
{
    সংরচনা M P __s
    {
        পূর্ণাঙ্ক x: 12;
        বর্ণ y: 6;
        long long z:63;
        A বর্ণ a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 3
{
    সংরচনা M P __s
    {
        unsigned x:5, y:5, :0, z:5; বর্ণ a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 4
{
    সংরচনা M P __s {
        পূর্ণাঙ্ক x : 3;
        পূর্ণাঙ্ক : 2;
        পূর্ণাঙ্ক y : 1;
        পূর্ণাঙ্ক : 0;
        পূর্ণাঙ্ক z : 5;
        পূর্ণাঙ্ক a : 7;
        unsigned পূর্ণাঙ্ক b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 5
{
    সংরচনা M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        বর্ণ a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 6
{
    সংরচনা M P __s {
	পূর্ণাঙ্ক a;
	signed বর্ণ b;
	পূর্ণাঙ্ক x : 12, y : 4, : 0, : 4, z : 3;
	বর্ণ d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#নোচেদ্যদি TEST == 7
{
#ifdef _WIN32
    প্রকারনির্দেশ long long পূর্ণাঙ্ক ll;
#অন্যথা
    প্রকারনির্দেশ long পূর্ণাঙ্ক ll;
#endif
    সংরচনা M P __s {
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
#নোচেদ্যদি defined PACK

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
#নোচেদ্যদি defined ALIGN

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
#নোচেদ্যদি defined MS_BF

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

শূন্য dump(শূন্য *p, পূর্ণাঙ্ক s)
{
    পূর্ণাঙ্ক i;
    প্রতি (i = s; --i >= 0;)
        printf("%02X", ((unsigned বর্ণ*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(পরিমাণ (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        সংরচনা __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + শীর্ষ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, পরিমাণ *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, পরিমাণ *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, পরিমাণ *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(সংরচনা __s),পরিমাণ(সংরচনা __s)); \
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

পূর্ণাঙ্ক শীর্ষ = 1;

পূর্ণাঙ্ক main()
{
#define MS_BF MS_BITFIELDS
#অন্তর্ভাব SELF
    প্রত্যাগম 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
