/* ----------------------------------------------------------------------- */
#ако TEST == 1
{
    struct M P A __s
    {
        unsigned x : 12;
        unsigned char y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 2
{
    struct M P __s
    {
        цео x: 12;
        char y: 6;
        long long z:63;
        A char a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 3
{
    struct M P __s
    {
        unsigned x:5, y:5, :0, z:5; char a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 4
{
    struct M P __s {
        цео x : 3;
        цео : 2;
        цео y : 1;
        цео : 0;
        цео z : 5;
        цео a : 7;
        unsigned цео b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 5
{
    struct M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        char a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 6
{
    struct M P __s {
	цео a;
	signed char b;
	цео x : 12, y : 4, : 0, : 4, z : 3;
	char d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#elif TEST == 7
{
#ifdef _WIN32
    typedef long long цео ll;
#инако
    typedef long цео ll;
#endif
    struct M P __s {
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
#elif defined PACK

#ако PACK
# pragma pack(push,1)
# define P //_P
#инако
# define P
#endif

printf("\n\n" + 2*top);
#define TEST 1
#include SELF
top = 0;
#define TEST 2
#include SELF
#define TEST 3
#include SELF
#define TEST 4
#include SELF
#define TEST 5
#include SELF
#define TEST 6
#include SELF
#define TEST 7
#include SELF

#ако PACK
# pragma pack(pop)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#elif defined ALIGN

#ако ALIGN
# define A _A(16)
#инако
# define A
#endif

#define PACK 0
#include SELF
#define PACK 1
#include SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#elif defined MS_BF

#ако MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#инако
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
#include SELF
#define ALIGN 1
#include SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#инако

#include <stdio.h>
#include <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

void dump(void *p, цео s)
{
    цео i;
    за (i = s; --i >= 0;)
        printf("%02X", ((unsigned char*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(sizeof (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        struct __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + top, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, sizeof *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, sizeof *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, sizeof *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(struct __s),sizeof(struct __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#инако
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

цео top = 1;

цео main()
{
#define MS_BF MS_BITFIELDS
#include SELF
    врати 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
