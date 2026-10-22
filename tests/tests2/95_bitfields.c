/* ----------------------------------------------------------------------- */
#اگر TEST == 1
{
    ساختار M P A __s
    {
        unsigned x : 12;
        unsigned نویسه y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 2
{
    ساختار M P __s
    {
        صحیح x: 12;
        نویسه y: 6;
        long long z:63;
        A نویسه a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 3
{
    ساختار M P __s
    {
        unsigned x:5, y:5, :0, z:5; نویسه a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 4
{
    ساختار M P __s {
        صحیح x : 3;
        صحیح : 2;
        صحیح y : 1;
        صحیح : 0;
        صحیح z : 5;
        صحیح a : 7;
        unsigned صحیح b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 5
{
    ساختار M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        نویسه a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 6
{
    ساختار M P __s {
	صحیح a;
	signed نویسه b;
	صحیح x : 12, y : 4, : 0, : 4, z : 3;
	نویسه d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#وگرنهاگر TEST == 7
{
#ifdef _WIN32
    تعریفنوع long long صحیح ll;
#وگرنه
    تعریفنوع long صحیح ll;
#endif
    ساختار M P __s {
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
#وگرنهاگر defined PACK

#اگر PACK
# pragma pack(افزودن,1)
# define P //_P
#وگرنه
# define P
#endif

printf("\n\n" + 2*بالاترین);
#define TEST 1
#شامل SELF
بالاترین = 0;
#define TEST 2
#شامل SELF
#define TEST 3
#شامل SELF
#define TEST 4
#شامل SELF
#define TEST 5
#شامل SELF
#define TEST 6
#شامل SELF
#define TEST 7
#شامل SELF

#اگر PACK
# pragma pack(برداشت)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#وگرنهاگر defined ALIGN

#اگر ALIGN
# define A _A(16)
#وگرنه
# define A
#endif

#define PACK 0
#شامل SELF
#define PACK 1
#شامل SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#وگرنهاگر defined MS_BF

#اگر MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#وگرنه
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
#شامل SELF
#define ALIGN 1
#شامل SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#وگرنه

#شامل <stdio.h>
#شامل <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

تهی dump(تهی *p, صحیح s)
{
    صحیح i;
    برای (i = s; --i >= 0;)
        printf("%02X", ((unsigned نویسه*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(اندازه (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        ساختار __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + بالاترین, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, اندازه *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, اندازه *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, اندازه *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(ساختار __s),اندازه(ساختار __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#وگرنه
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

صحیح بالاترین = 1;

صحیح اصلی()
{
#define MS_BF MS_BITFIELDS
#شامل SELF
    بازگشت 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
