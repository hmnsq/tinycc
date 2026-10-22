/* ----------------------------------------------------------------------- */
#जर TEST == 1
{
    संरचना M P A __s
    {
        अचिन्हित x : 12;
        अचिन्हित अक्षर y : 7;
        अचिन्हित z : 28;
        अचिन्हित a: 4;
        अचिन्हित b: 5;
    };
    TEST_STRUCT(0x333,0x44,0x555555,6,7);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 2
{
    संरचना M P __s
    {
        पूर्णांक x: 12;
        अक्षर y: 6;
        दीर्घ दीर्घ z:63;
        A अक्षर a:4;
        दीर्घ दीर्घ b:2;

    };
    TEST_STRUCT(3,30,0x123456789abcdef0LL,5,2);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 3
{
    संरचना M P __s
    {
        अचिन्हित x:5, y:5, :0, z:5; अक्षर a:5; A लघु b:5;
    };
    TEST_STRUCT(21,23,25,6,14);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 4
{
    संरचना M P __s {
        पूर्णांक x : 3;
        पूर्णांक : 2;
        पूर्णांक y : 1;
        पूर्णांक : 0;
        पूर्णांक z : 5;
        पूर्णांक a : 7;
        अचिन्हित पूर्णांक b : 7;
    };
    TEST_STRUCT(3,1,15,120,120);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 5
{
    संरचना M P __s {
        दीर्घ दीर्घ x : 45;
        दीर्घ दीर्घ : 2;
        दीर्घ दीर्घ y : 30;
        अचिन्हित दीर्घ दीर्घ z : 38;
        अक्षर a; लघु b;
    };
    TEST_STRUCT(0x123456789ULL, 120<<25, 120, 0x44, 0x77);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 6
{
    संरचना M P __s {
	पूर्णांक a;
	चिन्हित अक्षर b;
	पूर्णांक x : 12, y : 4, : 0, : 4, z : 3;
	अक्षर d;
    };
    TEST_STRUCT(1,2,3,4,-3);
}

/* ----------------------------------------------------------------------- */
#किंवाजर TEST == 7
{
#ifdef _WIN32
    प्रकारव्याख्या दीर्घ दीर्घ पूर्णांक ll;
#अन्यथा
    प्रकारव्याख्या दीर्घ पूर्णांक ll;
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
#किंवाजर defined PACK

#जर PACK
# pragma pack(ढकला,1)
# define P //_P
#अन्यथा
# define P
#endif

म_लिखो("\n\n" + 2*शीर्ष);
#define TEST 1
#अन्तर्भाव SELF
शीर्ष = 0;
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

#जर PACK
# pragma pack(काढा)
#endif

#undef P
#undef PACK

/* ----------------------------------------------------------------------- */
#किंवाजर defined ALIGN

#जर ALIGN
# define A _A(16)
#अन्यथा
# define A
#endif

#define PACK 0
#अन्तर्भाव SELF
#define PACK 1
#अन्तर्भाव SELF

#undef A
#undef ALIGN

/* ----------------------------------------------------------------------- */
#किंवाजर defined MS_BF

#जर MS_BF
# ifdef __TINYC__
#  pragma comment(option, "-mms-bitfields")
# elif defined __GNUC__
#  define M __attribute__((ms_struct))
# endif
#अन्यथा
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
#अन्यथा

#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
/* some gcc headers #define __attribute__ to empty if it's not gcc */
#undef __attribute__

शून्य dump(शून्य *p, पूर्णांक s)
{
    पूर्णांक i;
    साठी (i = s; --i >= 0;)
        म_लिखो("%02X", ((अचिन्हित अक्षर*)p)[i]);
    म_लिखो("\n");
}

#define pv(m) \
    म_लिखो(आकार (s->m + 0) == 8 ? " %016llx" : " %02x", s->m)

#define TEST_STRUCT(v1,v2,v3,v4,v5) { \
        संरचना __s _s, *s = & _s; \
        म_लिखो("\n---- TEST %d%s%s%s ----\n" + शीर्ष, \
            TEST, MS_BF?" - MS-BITFIELDS":"", \
            PACK?" - PACKED":"", \
            ALIGN?" - WITH ALIGN":""); \
        स_रखो(s, 0, आकार *s); \
        s->x = -1, s->y = -1, s->z = -1, s->a = -1, s->b = -1; \
        म_लिखो("bits in use : "), dump(s, आकार *s); \
        s->x = v1, s->y = v2, s->z = v3, s->a += v4, ++s->a, s->b = v5; \
        म_लिखो("bits as set : "), dump(s, आकार *s); \
        म_लिखो("values      :"), pv(x), pv(y), pv(z), pv(a), pv(b), म_लिखो("\n"); \
        म_लिखो("align/size  : %d %d\n", alignof(संरचना __s),आकार(संरचना __s)); \
    }

#ifdef _MSC_VER
# define _A(n) __declspec(align(n))
# define _P
# define alignof(x) __alignof(x)
#अन्यथा
# define _A(n) __attribute__((aligned(n)))
# define _P __attribute__((packed))
# define alignof(x) __alignof__(x)
#endif

#ifndef MS_BITFIELDS
# define MS_BITFIELDS 0
#endif

#define SELF "95_bitfields.c"

पूर्णांक शीर्ष = 1;

पूर्णांक main()
{
#define MS_BF MS_BITFIELDS
#अन्तर्भाव SELF
    परत 0;
}

/* ----------------------------------------------------------------------- */
#endif
#undef TEST
