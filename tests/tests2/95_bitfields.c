/* ----------------------------------------------------------------------- */
#எனில் TEST == 1
{
    கட்டமைப்பு M P A __s
    {
        unsigned x : 12;
        unsigned எழுத்து y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 2
{
    கட்டமைப்பு M P __s
    {
        முழு x: 12;
        எழுத்து y: 6;
        long long z:63;
        A எழுத்து a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 3
{
    கட்டமைப்பு M P __s
    {
        unsigned x:5, y:5, :0, z:5; எழுத்து a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 4
{
    கட்டமைப்பு M P __s {
        முழு x : 3;
        முழு : 2;
        முழு y : 1;
        முழு : 0;
        முழு z : 5;
        முழு a : 7;
        unsigned முழு b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 5
{
    கட்டமைப்பு M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        எழுத்து a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 6
{
    கட்டமைப்பு M P __s {
	முழு a;
	signed எழுத்து b;
	முழு x : 12, y : 4, : 0, : 4, z : 3;
	எழுத்து d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#அல்லதெனில் TEST == 7
{
#ifdef _WIN32
    வகைவரை long long முழு ll;
#இல்லையெனில்
    வகைவரை long முழு ll;
#endif
    கட்டமைப்பு M P __s {
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
#அல்லதெனில் defined PACK

#எனில் PACK
# pragma pack(தள்ளு,1)
# define P //_P
#இல்லையெனில்
# define P
#endif

printf("\n\n" + 2*உச்சி);
#define TEST 1
#அந்தர்பாவ SELF
உச்சி = 0;
#define TEST 2
#அந்தர்பாவ SELF
#define TEST 3
#அந்தர்பாவ SELF
#define TEST 4
#அந்தர்பாவ SELF
#define TEST 5
#அந்தர்பாவ SELF
#define TEST 6
#அந்தர்பாவ SELF
#define TEST 7
#அந்தர்பாவ SELF

#எனில் PACK
# pragma pack(எடு)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#அல்லதெனில் defined ALIGN

#எனில் ALIGN
# define A _A(16)
#இல்லையெனில்
# define A
#endif

#define PACK 0
#அந்தர்பாவ SELF
#define PACK 1
#அந்தர்பாவ SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#அல்லதெனில் defined MS_BF

#எனில் MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#இல்லையெனில்
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
#அந்தர்பாவ SELF
#define ALIGN 1
#அந்தர்பாவ SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#இல்லையெனில்

#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

வெறுமை dump(வெறுமை *p, முழு s)
{
    முழு i;
    க்கு (i = s; --i >= 0;)
        printf("%02X", ((unsigned எழுத்து*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(அளவு (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        கட்டமைப்பு __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + உச்சி, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, அளவு *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, அளவு *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, அளவு *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(கட்டமைப்பு __s),அளவு(கட்டமைப்பு __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#இல்லையெனில்
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

முழு உச்சி = 1;

முழு முதன்மை()
{
#define MS_BF MS_BITFIELDS
#அந்தர்பாவ SELF
    திரும்பு 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
