/* ----------------------------------------------------------------------- */
#ಯದಿ TEST == 1
{
    ಸಂರಚನಾ M P A __s
    {
        unsigned x : 12;
        unsigned ವರ್ಣ y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 2
{
    ಸಂರಚನಾ M P __s
    {
        ಪೂರ್ಣಾಙ್ಕ x: 12;
        ವರ್ಣ y: 6;
        long long z:63;
        A ವರ್ಣ a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 3
{
    ಸಂರಚನಾ M P __s
    {
        unsigned x:5, y:5, :0, z:5; ವರ್ಣ a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 4
{
    ಸಂರಚನಾ M P __s {
        ಪೂರ್ಣಾಙ್ಕ x : 3;
        ಪೂರ್ಣಾಙ್ಕ : 2;
        ಪೂರ್ಣಾಙ್ಕ y : 1;
        ಪೂರ್ಣಾಙ್ಕ : 0;
        ಪೂರ್ಣಾಙ್ಕ z : 5;
        ಪೂರ್ಣಾಙ್ಕ a : 7;
        unsigned ಪೂರ್ಣಾಙ್ಕ b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 5
{
    ಸಂರಚನಾ M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        ವರ್ಣ a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 6
{
    ಸಂರಚನಾ M P __s {
	ಪೂರ್ಣಾಙ್ಕ a;
	signed ವರ್ಣ b;
	ಪೂರ್ಣಾಙ್ಕ x : 12, y : 4, : 0, : 4, z : 3;
	ವರ್ಣ d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ TEST == 7
{
#ifdef _WIN32
    ಪ್ರಕಾರನಿರ್ದೇಶ long long ಪೂರ್ಣಾಙ್ಕ ll;
#ಅನ್ಯಥಾ
    ಪ್ರಕಾರನಿರ್ದೇಶ long ಪೂರ್ಣಾಙ್ಕ ll;
#endif
    ಸಂರಚನಾ M P __s {
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
#ನೋಚೇದ್ಯದಿ defined PACK

#ಯದಿ PACK
# pragma pack(ತಳ್ಳು,1)
# define P //_P
#ಅನ್ಯಥಾ
# define P
#endif

printf("\n\n" + 2*ತುದಿ);
#define TEST 1
#ಅನ್ತರ್ಭಾವ SELF
ತುದಿ = 0;
#define TEST 2
#ಅನ್ತರ್ಭಾವ SELF
#define TEST 3
#ಅನ್ತರ್ಭಾವ SELF
#define TEST 4
#ಅನ್ತರ್ಭಾವ SELF
#define TEST 5
#ಅನ್ತರ್ಭಾವ SELF
#define TEST 6
#ಅನ್ತರ್ಭಾವ SELF
#define TEST 7
#ಅನ್ತರ್ಭಾವ SELF

#ಯದಿ PACK
# pragma pack(ತೆಗೆ)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ defined ALIGN

#ಯದಿ ALIGN
# define A _A(16)
#ಅನ್ಯಥಾ
# define A
#endif

#define PACK 0
#ಅನ್ತರ್ಭಾವ SELF
#define PACK 1
#ಅನ್ತರ್ಭಾವ SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#ನೋಚೇದ್ಯದಿ defined MS_BF

#ಯದಿ MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#ಅನ್ಯಥಾ
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
#ಅನ್ತರ್ಭಾವ SELF
#define ALIGN 1
#ಅನ್ತರ್ಭಾವ SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#ಅನ್ಯಥಾ

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ಶೂನ್ಯ dump(ಶೂನ್ಯ *p, ಪೂರ್ಣಾಙ್ಕ s)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪ್ರತಿ (i = s; --i >= 0;)
        printf("%02X", ((unsigned ವರ್ಣ*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(ಪರಿಮಾಣ (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        ಸಂರಚನಾ __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + ತುದಿ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, ಪರಿಮಾಣ *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, ಪರಿಮಾಣ *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, ಪರಿಮಾಣ *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(ಸಂರಚನಾ __s),ಪರಿಮಾಣ(ಸಂರಚನಾ __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#ಅನ್ಯಥಾ
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

ಪೂರ್ಣಾಙ್ಕ ತುದಿ = 1;

ಪೂರ್ಣಾಙ್ಕ main()
{
#define MS_BF MS_BITFIELDS
#ಅನ್ತರ್ಭಾವ SELF
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
