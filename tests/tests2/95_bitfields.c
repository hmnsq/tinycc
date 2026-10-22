/* ----------------------------------------------------------------------- */
#എങ്കിൽ TEST == 1
{
    ഘടന M P A __s
    {
        unsigned x : 12;
        unsigned അക്ഷരം y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 2
{
    ഘടന M P __s
    {
        പൂർണ്ണസംഖ്യ x: 12;
        അക്ഷരം y: 6;
        long long z:63;
        A അക്ഷരം a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 3
{
    ഘടന M P __s
    {
        unsigned x:5, y:5, :0, z:5; അക്ഷരം a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 4
{
    ഘടന M P __s {
        പൂർണ്ണസംഖ്യ x : 3;
        പൂർണ്ണസംഖ്യ : 2;
        പൂർണ്ണസംഖ്യ y : 1;
        പൂർണ്ണസംഖ്യ : 0;
        പൂർണ്ണസംഖ്യ z : 5;
        പൂർണ്ണസംഖ്യ a : 7;
        unsigned പൂർണ്ണസംഖ്യ b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 5
{
    ഘടന M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        അക്ഷരം a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 6
{
    ഘടന M P __s {
	പൂർണ്ണസംഖ്യ a;
	signed അക്ഷരം b;
	പൂർണ്ണസംഖ്യ x : 12, y : 4, : 0, : 4, z : 3;
	അക്ഷരം d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ TEST == 7
{
#ifdef _WIN32
    തരനിർവചനം long long പൂർണ്ണസംഖ്യ ll;
#അല്ലെങ്കിൽ
    തരനിർവചനം long പൂർണ്ണസംഖ്യ ll;
#endif
    ഘടന M P __s {
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
#അല്ലെങ്കിലെങ്കിൽ defined PACK

#എങ്കിൽ PACK
# pragma pack(തള്ളുക,1)
# define P //_P
#അല്ലെങ്കിൽ
# define P
#endif

printf("\n\n" + 2*മുകൾ);
#define TEST 1
#അന്തര്ഭാവ SELF
മുകൾ = 0;
#define TEST 2
#അന്തര്ഭാവ SELF
#define TEST 3
#അന്തര്ഭാവ SELF
#define TEST 4
#അന്തര്ഭാവ SELF
#define TEST 5
#അന്തര്ഭാവ SELF
#define TEST 6
#അന്തര്ഭാവ SELF
#define TEST 7
#അന്തര്ഭാവ SELF

#എങ്കിൽ PACK
# pragma pack(എടുക്കുക)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined ALIGN

#എങ്കിൽ ALIGN
# define A _A(16)
#അല്ലെങ്കിൽ
# define A
#endif

#define PACK 0
#അന്തര്ഭാവ SELF
#define PACK 1
#അന്തര്ഭാവ SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിലെങ്കിൽ defined MS_BF

#എങ്കിൽ MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#അല്ലെങ്കിൽ
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
#അന്തര്ഭാവ SELF
#define ALIGN 1
#അന്തര്ഭാവ SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#അല്ലെങ്കിൽ

#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ശൂന്യം dump(ശൂന്യം *p, പൂർണ്ണസംഖ്യ s)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = s; --i >= 0;)
        printf("%02X", ((unsigned അക്ഷരം*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(വലുപ്പം (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        ഘടന __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + മുകൾ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, വലുപ്പം *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, വലുപ്പം *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, വലുപ്പം *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(ഘടന __s),വലുപ്പം(ഘടന __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#അല്ലെങ്കിൽ
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

പൂർണ്ണസംഖ്യ മുകൾ = 1;

പൂർണ്ണസംഖ്യ പ്രധാന()
{
#define MS_BF MS_BITFIELDS
#അന്തര്ഭാവ SELF
    തിരികെ 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
