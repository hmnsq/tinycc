/* ----------------------------------------------------------------------- */
#જો TEST == 1
{
    સંરચના M P A __s
    {
        unsigned x : 12;
        unsigned અક્ષર y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 2
{
    સંરચના M P __s
    {
        પૂર્ણાંક x: 12;
        અક્ષર y: 6;
        long long z:63;
        A અક્ષર a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 3
{
    સંરચના M P __s
    {
        unsigned x:5, y:5, :0, z:5; અક્ષર a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 4
{
    સંરચના M P __s {
        પૂર્ણાંક x : 3;
        પૂર્ણાંક : 2;
        પૂર્ણાંક y : 1;
        પૂર્ણાંક : 0;
        પૂર્ણાંક z : 5;
        પૂર્ણાંક a : 7;
        unsigned પૂર્ણાંક b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 5
{
    સંરચના M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        અક્ષર a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 6
{
    સંરચના M P __s {
	પૂર્ણાંક a;
	signed અક્ષર b;
	પૂર્ણાંક x : 12, y : 4, : 0, : 4, z : 3;
	અક્ષર d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#અથવાજો TEST == 7
{
#ifdef _WIN32
    પ્રકારવ્યાખ્યા long long પૂર્ણાંક ll;
#નહીંતર
    પ્રકારવ્યાખ્યા long પૂર્ણાંક ll;
#endif
    સંરચના M P __s {
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
#અથવાજો defined PACK

#જો PACK
# pragma pack(ધકેલો,1)
# define P //_P
#નહીંતર
# define P
#endif

printf("\n\n" + 2*ટોચ);
#define TEST 1
#અન્તર્ભાવ SELF
ટોચ = 0;
#define TEST 2
#અન્તર્ભાવ SELF
#define TEST 3
#અન્તર્ભાવ SELF
#define TEST 4
#અન્તર્ભાવ SELF
#define TEST 5
#અન્તર્ભાવ SELF
#define TEST 6
#અન્તર્ભાવ SELF
#define TEST 7
#અન્તર્ભાવ SELF

#જો PACK
# pragma pack(કાઢો)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#અથવાજો defined ALIGN

#જો ALIGN
# define A _A(16)
#નહીંતર
# define A
#endif

#define PACK 0
#અન્તર્ભાવ SELF
#define PACK 1
#અન્તર્ભાવ SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#અથવાજો defined MS_BF

#જો MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#નહીંતર
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
#અન્તર્ભાવ SELF
#define ALIGN 1
#અન્તર્ભાવ SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#નહીંતર

#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

શૂન્ય dump(શૂન્ય *p, પૂર્ણાંક s)
{
    પૂર્ણાંક i;
    માટે (i = s; --i >= 0;)
        printf("%02X", ((unsigned અક્ષર*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(કદ (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        સંરચના __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + ટોચ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, કદ *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, કદ *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, કદ *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(સંરચના __s),કદ(સંરચના __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#નહીંતર
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

પૂર્ણાંક ટોચ = 1;

પૂર્ણાંક મુખ્ય()
{
#define MS_BF MS_BITFIELDS
#અન્તર્ભાવ SELF
    પાછા 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
