/* ----------------------------------------------------------------------- */
#ଯଦି TEST == 1
{
    ସଂରଚନା M P A __s
    {
        unsigned x : 12;
        unsigned ଅକ୍ଷର y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 2
{
    ସଂରଚନା M P __s
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x: 12;
        ଅକ୍ଷର y: 6;
        long long z:63;
        A ଅକ୍ଷର a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 3
{
    ସଂରଚନା M P __s
    {
        unsigned x:5, y:5, :0, z:5; ଅକ୍ଷର a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 4
{
    ସଂରଚନା M P __s {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x : 3;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା : 2;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା y : 1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା : 0;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା z : 5;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a : 7;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 5
{
    ସଂରଚନା M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        ଅକ୍ଷର a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 6
{
    ସଂରଚନା M P __s {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
	signed ଅକ୍ଷର b;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା x : 12, y : 4, : 0, : 4, z : 3;
	ଅକ୍ଷର d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି TEST == 7
{
#ifdef _WIN32
    ପ୍ରକାରବ୍ୟାଖ୍ୟା long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା ll;
#ଅନ୍ୟଥା
    ପ୍ରକାରବ୍ୟାଖ୍ୟା long ପୂର୍ଣ୍ଣସଂଖ୍ୟା ll;
#endif
    ସଂରଚନା M P __s {
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
#ନଚେତଯଦି defined PACK

#ଯଦି PACK
# pragma pack(ଠେଲ,1)
# define P //_P
#ଅନ୍ୟଥା
# define P
#endif

printf("\n\n" + 2*ଶୀର୍ଷ);
#define TEST 1
#ଅନ୍ତର୍ଭାଵ SELF
ଶୀର୍ଷ = 0;
#define TEST 2
#ଅନ୍ତର୍ଭାଵ SELF
#define TEST 3
#ଅନ୍ତର୍ଭାଵ SELF
#define TEST 4
#ଅନ୍ତର୍ଭାଵ SELF
#define TEST 5
#ଅନ୍ତର୍ଭାଵ SELF
#define TEST 6
#ଅନ୍ତର୍ଭାଵ SELF
#define TEST 7
#ଅନ୍ତର୍ଭାଵ SELF

#ଯଦି PACK
# pragma pack(କାଢ଼)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି defined ALIGN

#ଯଦି ALIGN
# define A _A(16)
#ଅନ୍ୟଥା
# define A
#endif

#define PACK 0
#ଅନ୍ତର୍ଭାଵ SELF
#define PACK 1
#ଅନ୍ତର୍ଭାଵ SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#ନଚେତଯଦି defined MS_BF

#ଯଦି MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#ଅନ୍ୟଥା
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
#ଅନ୍ତର୍ଭାଵ SELF
#define ALIGN 1
#ଅନ୍ତର୍ଭାଵ SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#ଅନ୍ୟଥା

#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

ଶୂନ୍ୟ dump(ଶୂନ୍ୟ *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପାଇଁ (i = s; --i >= 0;)
        printf("%02X", ((unsigned ଅକ୍ଷର*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(ଆକାର (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        ସଂରଚନା __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + ଶୀର୍ଷ, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, ଆକାର *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, ଆକାର *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, ଆକାର *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(ସଂରଚନା __s),ଆକାର(ସଂରଚନା __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#ଅନ୍ୟଥା
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଶୀର୍ଷ = 1;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
#define MS_BF MS_BITFIELDS
#ଅନ୍ତର୍ଭାଵ SELF
    ଫେରନ୍ତୁ 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
