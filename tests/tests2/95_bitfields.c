/* ----------------------------------------------------------------------- */
#सचे TEST == 1
{
    संरचना M P A __s
    {
        unsigned x : 12;
        unsigned वर्ण y : 7;
        unsigned z : 28;
        unsigned a: 4;
        unsigned b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 2
{
    संरचना M P __s
    {
        पूर्णाङ्क x: 12;
        वर्ण y: 6;
        long long z:63;
        A वर्ण a:4;
        long long b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 3
{
    संरचना M P __s
    {
        unsigned x:5, y:5, :0, z:5; वर्ण a:5; A short b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 4
{
    संरचना M P __s {
        पूर्णाङ्क x : 3;
        पूर्णाङ्क : 2;
        पूर्णाङ्क y : 1;
        पूर्णाङ्क : 0;
        पूर्णाङ्क z : 5;
        पूर्णाङ्क a : 7;
        unsigned पूर्णाङ्क b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 5
{
    संरचना M P __s {
        long long x : 45;
        long long : 2;
        long long y : 30;
        unsigned long long z : 38;
        वर्ण a; short b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 6
{
    संरचना M P __s {
	पूर्णाङ्क a;
	signed वर्ण b;
	पूर्णाङ्क x : 12, y : 4, : 0, : 4, z : 3;
	वर्ण d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#नोचेद्यदि TEST == 7
{
#ifdef _WIN32
    प्रकारनिर्देश long long पूर्णाङ्क ll;
#अञ्ञथा
    प्रकारनिर्देश long पूर्णाङ्क ll;
#endif
    संरचना M P __s {
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
#नोचेद्यदि defined PACK

#सचे PACK
# pragma pack(प्रक्षिप,1)
# define P //_P
#अञ्ञथा
# define P
#endif

printf("\n\n" + 2*शिखरम्);
#define TEST 1
#अन्तर्भाव SELF
शिखरम् = 0;
#define TEST 2
#अन्तर्भाव SELF
#define TEST 3
#अन्तर्भाव SELF
#define TEST 4
#अन्तर्भाव SELF
#define TEST 5
#अन्तर्भाव SELF
#define TEST 6
#अन्तर्भाव SELF
#define TEST 7
#अन्तर्भाव SELF

#सचे PACK
# pragma pack(निष्कासय)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#नोचेद्यदि defined ALIGN

#सचे ALIGN
# define A _A(16)
#अञ्ञथा
# define A
#endif

#define PACK 0
#अन्तर्भाव SELF
#define PACK 1
#अन्तर्भाव SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#नोचेद्यदि defined MS_BF

#सचे MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#अञ्ञथा
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
#अन्तर्भाव SELF
#define ALIGN 1
#अन्तर्भाव SELF

#undef M
#undef MS_BF

/* ----------------------------------------------------------------------- */
#अञ्ञथा

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

शून्य dump(शून्य *p, पूर्णाङ्क s)
{
    पूर्णाङ्क i;
    अत्थाय (i = s; --i >= 0;)
        printf("%02X", ((unsigned वर्ण*)p)[i]);
    printf("\n");
}

#define pv(m) \
    printf(परिमाण (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        संरचना __s _s, *s = & _s; \
        printf("\n---- TEST %d%s%s%s ----\n" + शिखरम्, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        memset(s, 0, परिमाण *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        printf("bits in use : "), dump(s, परिमाण *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        printf("bits as set : "), dump(s, परिमाण *s); \
        printf("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), printf("\n"); \
        printf("align/size  : %d %d\n", alignof(संरचना __s),परिमाण(संरचना __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#अञ्ञथा
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

पूर्णाङ्क शिखरम् = 1;

पूर्णाङ्क main()
{
#define MS_BF MS_BITFIELDS
#अन्तर्भाव SELF
    पटिनिवत्त 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
