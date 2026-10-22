/* ----------------------------------------------------------------------- */
#إذا TEST == 1
{
    بنية M P A __s
    {
        unsigned x : 12;
        unsigned حرف y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 2
{
    بنية M P __s
    {
        صحيح x: 12;
        حرف y: 6;
        long long z:63;
        A حرف a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 3
{
    بنية M P __s
    {
        unsigned x:5, y:5, :0, z:5; حرف a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 4
{
    بنية M P __s {
        صحيح x : 3;
        صحيح : 2;
        صحيح y : 1;
        صحيح : 0;
        صحيح z : 5;
        صحيح a : 7;
        unsigned صحيح b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 5
{
    بنية M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        حرف a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 6
{
    بنية M P __s {
	صحيح a;
	signed حرف b;
	صحيح x : 12, y : 4, : 0, : 4, z : 3;
	حرف d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#وإلاإذا TEST == 7
{
#ifdef _WIN32
    تعريفنوع long long صحيح ll;
#وإلا
    تعريفنوع long صحيح ll;
#endif
    بنية M P __s {
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
#وإلاإذا defined PACK

#إذا PACK
# pragma pack(ڈالو,1)
# define P //_P
#وإلا
# define P
#endif

printf("\n\n" + 2*چوٹی);
#define TEST 1
#ضمن SELF
چوٹی = 0;
#define TEST 2
#ضمن SELF
#define TEST 3
#ضمن SELF
#define TEST 4
#ضمن SELF
#define TEST 5
#ضمن SELF
#define TEST 6
#ضمن SELF
#define TEST 7
#ضمن SELF

#إذا PACK
# pragma pack(نکالو)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#وإلاإذا defined ALIGN

#إذا ALIGN
# define A _A(16)
#وإلا
# define A
#endif

#define PACK 0
#ضمن SELF
#define PACK 1
#ضمن SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#وإلاإذا defined MS_BF

#إذا MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#وإلا
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
#ضمن SELF
#define ALIGN 1
#ضمن SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#وإلا

#ضمن <stdio.h>
#ضمن <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

فراغ dump(فراغ *p, صحيح s)
{
    صحيح i;
    لكل (i = s; --i >= 0;)
        printf("%02X", ((unsigned حرف*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(حجم (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        بنية __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + چوٹی, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, حجم *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, حجم *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, حجم *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(بنية __s),حجم(بنية __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#وإلا
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

صحيح چوٹی = 1;

صحيح main()
{
#define MS_BF MS_BITFIELDS
#ضمن SELF
    أرجع 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
