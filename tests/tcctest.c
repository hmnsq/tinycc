/*
 * TCC auto test program
 */
#ಅನ್ತರ್ಭಾವ "config.h"

/* identify the configured reference compiler in use */
#ವ್ಯಾಖ್ಯಾನಿಸು CC_gcc 1
#ವ್ಯಾಖ್ಯಾನಿಸು CC_clang 2
#ವ್ಯಾಖ್ಯಾನಿಸು CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#ವ್ಯಾಖ್ಯಾನಿಸು ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#ವ್ಯಾಖ್ಯಾನಿಸು BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#ವ್ಯಾಖ್ಯಾನಿಸು C99_MACROS

#ಆದರೆ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_LONG_FORMAT "%lld"
#ವ್ಯಾಖ್ಯಾನಿಸು ULONG_LONG_FORMAT "%llu"
#ವ್ಯಾಖ್ಯಾನಿಸು XLONG_LONG_FORMAT "%llx"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_LONG_FORMAT "%Ld"
#ವ್ಯಾಖ್ಯಾನಿಸು ULONG_LONG_FORMAT "%Lu"
#ವ್ಯಾಖ್ಯಾನಿಸು XLONG_LONG_FORMAT "%Lx"
#ಆದರೆ_ಅಂತ್ಯ

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ಆದರೆ defined(_WIN32)
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_DOUBLE ದ್ವಿಗುಣ
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_DOUBLE_LITERAL(x) x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_DOUBLE ದೀರ್ಘ ದ್ವಿಗುಣ
#ವ್ಯಾಖ್ಯಾನಿಸು LONG_DOUBLE_LITERAL(x) x ## L
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#ವ್ಯಾಖ್ಯಾನಿಸು TCCLIB_INC <tcclib.h>
#ವ್ಯಾಖ್ಯಾನಿಸು TCCLIB_INC1 <tcclib
#ವ್ಯಾಖ್ಯಾನಿಸು TCCLIB_INC2 h>
#ವ್ಯಾಖ್ಯಾನಿಸು TCCLIB_INC3 "tcclib.h"

#ಅನ್ತರ್ಭಾವ TCCLIB_INC

#ಅನ್ತರ್ಭಾವ TCCLIB_INC1.TCCLIB_INC2

#ಅನ್ತರ್ಭಾವ TCCLIB_INC1.h>

#ಅನ್ತರ್ಭಾವ TCCLIB_INC3

#ಅನ್ತರ್ಭಾವ <tcclib.h>

#ಅನ್ತರ್ಭಾವ "tcclib.h"

#ಅನ್ತರ್ಭಾವ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#ವ್ಯಾಖ್ಯಾನಿಸು INC(name) <tests/name.h>
#ವ್ಯಾಖ್ಯಾನಿಸು funnyname 42test.h
#ವ್ಯಾಖ್ಯಾನಿಸು incdir tests/
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#ವ್ಯಾಖ್ಯಾನಿಸು incname <tests/42test.h>
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು incname < incdir funnyname >
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು __stringify(x) #x
#ವ್ಯಾಖ್ಯಾನಿಸು stringify(x) __stringify(x)
#ಅನ್ತರ್ಭಾವ INC(42test)
#ಅನ್ತರ್ಭಾವ incname
#ಅನ್ತರ್ಭಾವ stringify(funnyname)

ಪೂರ್ಣಾಂಕ fib(ಪೂರ್ಣಾಂಕ n);
ಶೂನ್ಯ ಅಂಕೆ(ಪೂರ್ಣಾಂಕ n);
ಶೂನ್ಯ forward_ref(ಶೂನ್ಯ);
ಪೂರ್ಣಾಂಕ isid(ಪೂರ್ಣಾಂಕ c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
ಶೂನ್ಯ funny_ಸಾಲು_continuation (ಪೂರ್ಣಾಂಕ, ..\
. );

#ವ್ಯಾಖ್ಯಾನಿಸು A 2
#ವ್ಯಾಖ್ಯಾನಿಸು N 1234 + A
#ವ್ಯಾಖ್ಯಾನಿಸು pf ಬರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು M1(a, b)  (a) + (b)

#ವ್ಯಾಖ್ಯಾನಿಸು str\
(s) # s
#ವ್ಯಾಖ್ಯಾನಿಸು glue(a, b) a ## b
#ವ್ಯಾಖ್ಯಾನಿಸು xglue(a, b) glue(a, b)
#ವ್ಯಾಖ್ಯಾನಿಸು HIGHLOW "hello"
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಳಗಿನ_2 ಕೆಳಗಿನ_2 ", world"

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ onetwothree = 123;
#ವ್ಯಾಖ್ಯಾನಿಸು onetwothree4 onetwothree
#ವ್ಯಾಖ್ಯಾನಿಸು onetwothree xglue(onetwothree,4)

#ವ್ಯಾಖ್ಯಾನಿಸು min(a, b) ((a) < (b) ? (a) : (b))

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ C99_MACROS
#ವ್ಯಾಖ್ಯಾನಿಸು dprintf(level,...) ಬರೆ(__VA_ARGS__)
#ಆದರೆ_ಅಂತ್ಯ

/* gcc vararg macros */
#ವ್ಯಾಖ್ಯಾನಿಸು dprintf1(level, fmt, ವಾದಗಳು...) ಬರೆ(fmt, ## ವಾದಗಳು)

#ವ್ಯಾಖ್ಯಾನಿಸು MACRO_NOARGS()

#ವ್ಯಾಖ್ಯಾನಿಸು TEST_CALL(f, ...) f(__VA_ARGS__)
#ವ್ಯಾಖ್ಯಾನಿಸು TEST_CONST()      123

#ವ್ಯಾಖ್ಯಾನಿಸು AAA 3
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು AAA
#ವ್ಯಾಖ್ಯಾನಿಸು AAA 4

#ಆದರೆ 1
#ವ್ಯಾಖ್ಯಾನಿಸು B3 1
#ಅಥವಾಆದರೆ 1
#ವ್ಯಾಖ್ಯಾನಿಸು B3 2
#ಅಥವಾಆದರೆ 0
#ವ್ಯಾಖ್ಯಾನಿಸು B3 3
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು B3 4
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು __INT64_C(c)	c ## LL
#ವ್ಯಾಖ್ಯಾನಿಸು INT64_MIN	(-__INT64_C(9223372036854775807)-1)

ಪೂರ್ಣಾಂಕ qq(ಪೂರ್ಣಾಂಕ x)
{
    ಹಿಂತಿರುಗಿ x + 40;
}
#ವ್ಯಾಖ್ಯಾನಿಸು qq(x) x

#ವ್ಯಾಖ್ಯಾನಿಸು spin_ಬೀಗ(ಬೀಗ) ಮಾಡು { } ಆಗ (0)
#ವ್ಯಾಖ್ಯಾನಿಸು wq_spin_ಬೀಗ spin_ಬೀಗ
#ವ್ಯಾಖ್ಯಾನಿಸು TEST2() wq_spin_ಬೀಗ(a)

ಶೂನ್ಯ macro_test(ಶೂನ್ಯ)
{
    pf("N=%d\n", N);
    ಬರೆ("aaa=%d\n", AAA);

    ಬರೆ("min=%d\n", min(1, min(2, -1)));

    ಬರೆ("s1=%s\n", glue(ಮೇಲಿನ_2, ಕೆಳಗಿನ_2));
    ಬರೆ("s2=%s\n", xglue(ಮೇಲಿನ_2, ಕೆಳಗಿನ_2));
    ಬರೆ("s3=%s\n", str("c"));
    ಬರೆ("s4=%s\n", str(a1));
    ಬರೆ("B3=%d\n", B3);

    ಬರೆ("onetwothree=%d\n", onetwothree);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ A
    ಬರೆ("A defined\n");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ B
    ಬರೆ("B defined\n");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ A
    ಬರೆ("A defined\n");
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("A not defined\n");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ B
    ಬರೆ("B defined\n");
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("B not defined\n");
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ A
    ಬರೆ("A defined\n");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ B
    ಬರೆ("B1 defined\n");
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("B1 not defined\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("A not defined\n");
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ B
    ಬರೆ("B2 defined\n");
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("B2 not defined\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ 1+1
    ಬರೆ("test true1\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 0
    ಬರೆ("test true2\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1-1
    ಬರೆ("test true3\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined(A)
    ಬರೆ("test trueA\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ defined(B)
    ಬರೆ("test trueB\n");
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ 0
    ಬರೆ("test 0\n");
#ಅಥವಾಆದರೆ 0
    ಬರೆ("test 1\n");
#ಅಥವಾಆದರೆ 2
    ಬರೆ("test 2\n");
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("test 3\n");
#ಆದರೆ_ಅಂತ್ಯ

    MACRO_NOARGS();

    ಬರೆ("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ C99_MACROS
    ಬರೆ("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#ಆದರೆ_ಅಂತ್ಯ
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    ಬರೆ("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    ಬರೆ("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        ಪೂರ್ಣಾಂಕ a;
        a = 1;
        glue(a+, +);
        ಬರೆ("a=%d\n", a);
        glue(a <, <= 2);
        ಬರೆ("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#ವ್ಯಾಖ್ಯಾನಿಸು MF_s MF_hello
#ವ್ಯಾಖ್ಯಾನಿಸು MF_hello(ಸಂದೇಶ) ಬರೆ("%s\n",ಸಂದೇಶ)

#ವ್ಯಾಖ್ಯಾನಿಸು MF_t ಬರೆ("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    ಬರೆ("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#ವ್ಯಾಖ್ಯಾನಿಸು qq1(x) 1
    ಬರೆ("qq1=%d\n", qq1( ));

    /* comment with stray handling *\
/
       /* this is a valid *\/ comment */
       /* this is a valid comment *\*/
    //  this is a valid\
comment

    /* test function macro substitution when the function name is
       substituted */
    TEST2();

    /* And again when the name and parentheses are separated by a
       comment.  */
    TEST2 /* the comment */ ();

    ಬರೆ("basefromheader %s\n", get_basefile_from_ಶೀರ್ಷಿಕೆ());
    ಬರೆ("base %s\n", __BASE_FILE__);
#ಆದರೆ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fn = get_file_from_ಶೀರ್ಷಿಕೆ();
      ಆದರೆ (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      ಬರೆ("filefromheader %s\n", fn);
    }
#ಆದರೆ_ಅಂತ್ಯ

    ಬರೆ("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_ಎರಡನೇ = 1;
    have_included_42test_h_ಮೂರನೇ = 1;

    /* Check that we don't complain about stray \ here */
    ಬರೆ("print a backslash: %s\n", stringify(\\));
}


ಸ್ಥಿರ ಶೂನ್ಯ print_ಅಂಕೆ(ಅಕ್ಷರ *fn, ಪೂರ್ಣಾಂಕ ಸಾಲು, ಪೂರ್ಣಾಂಕ ಅಂಕೆ) {
    ಬರೆ("fn %s, line %d, num %d\n", fn, ಸಾಲು, ಅಂಕೆ);
}

ಶೂನ್ಯ recursive_macro_test(ಶೂನ್ಯ)
{

#ವ್ಯಾಖ್ಯಾನಿಸು ELF32_ST_TYPE(val)              ((val) & 0xf)
#ವ್ಯಾಖ್ಯಾನಿಸು ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#ವ್ಯಾಖ್ಯಾನಿಸು STB_WEAK        2               /* Weak symbol */
#ವ್ಯಾಖ್ಯಾನಿಸು ELFW(type) ELF##32##_##type
    ಬರೆ("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#ವ್ಯಾಖ್ಯಾನಿಸು WRAP(x) x
    
#ವ್ಯಾಖ್ಯಾನಿಸು print_ಅಂಕೆ(x) print_ಅಂಕೆ(__FILE__,__LINE__,x)
    print_ಅಂಕೆ(123);
    WRAP(print_ಅಂಕೆ(123));
    WRAP(WRAP(print_ಅಂಕೆ(123)));

ಸ್ಥಿರ ರಚನೆ recursive_macro { ಪೂರ್ಣಾಂಕ rm_ಕ್ಷೇತ್ರ; } G;
#ವ್ಯಾಖ್ಯಾನಿಸು rm_ಕ್ಷೇತ್ರ (G.rm_ಕ್ಷೇತ್ರ)
    ಬರೆ("rm_field = %d\n", rm_ಕ್ಷೇತ್ರ);
    ಬರೆ("rm_field = %d\n", WRAP(rm_ಕ್ಷೇತ್ರ));
    WRAP((ಬರೆ("rm_field = %d %d\n", rm_ಕ್ಷೇತ್ರ, WRAP(rm_ಕ್ಷೇತ್ರ))));
}

#ಆದರೆ __TINYC__
ಪೂರ್ಣಾಂಕ op(a, b)
{
    ಹಿಂತಿರುಗಿ a / b;
}

ಪೂರ್ಣಾಂಕ ret(a)
{
    ಆದರೆ (a == 2)
        ಹಿಂತಿರುಗಿ 1;
    ಆದರೆ (a == 3)
        ಹಿಂತಿರುಗಿ 2;
    ಹಿಂತಿರುಗಿ 0;
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#ವ್ಯಾಖ್ಯಾನಿಸು CONSTANTINDEXEDSTRLIT
#ಆದರೆ_ಅಂತ್ಯ
ಅಕ್ಷರ str_ag1[] = "b";
ಅಕ್ಷರ str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONSTANTINDEXEDSTRLIT
ಅಕ್ಷರ str_ag3[] = { "ab"[1], 0 };
ಅಕ್ಷರ str_x[2] = { "xy" "z"[2], 0 };
#ಆದರೆ_ಅಂತ್ಯ
ಅಕ್ಷರ *str_ar[] = { "one", "two" };
ರಚನೆ str_SS {ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ a[3], b; };
ರಚನೆ str_SS str_sinit15 = { "r" };
ರಚನೆ str_SS str_sinit16[] = { { "q" }, 2 };

ಸ್ಥಿರ ಶೂನ್ಯ string_test2()
{
    ಅಕ್ಷರ *p = "hello";
    ಅಕ್ಷರ a3[2] = { "p" };
    ಅಕ್ಷರ a4[2] = { "ab" "c"[2], 0 };
    ಅಕ್ಷರ *pa1 = "def" + 1;
    ಅಕ್ಷರ *pa2 = { "xyz" + 1 };
    ಪೂರ್ಣಾಂಕ i = 0;
    ರಚನೆ str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CONSTANTINDEXEDSTRLIT
    ಅಕ್ಷರ str_ag3[] = { "ab"[1], 0 };
    ಅಕ್ಷರ str_x[2] = { "xy" "z"[2], 0 };
#ಆದರೆ_ಅಂತ್ಯ
    puts("string_test2");
    puts(str_ag1);
    puts(str_ag2);
    /*puts(str_bg1);*/
    puts(str_ag3);
    puts(str_x);
    puts(str_sinit15.a);
    puts(str_sinit16[0].a);
    puts(a3);
    puts(a4);
    puts(p);
    puts("world");
    ಬರೆ("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

ಶೂನ್ಯ ps(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *s)
{
    ಪೂರ್ಣಾಂಕ c;
    ಆಗ (1) {
        c = *s;
        ಆದರೆ (c == 0)
            ನಿಲ್ಲಿಸು;
        ಬರೆ("%c", c);
        s++;
    }
}

ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ foo1_string[] = "\
bar\n\
test\14\
1";

ಶೂನ್ಯ string_test()
{
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ b;
    ಬರೆ("string:\n");
    ಬರೆ("\141\1423\143\n");/* dezdez test */
    ಬರೆ("\x41\x42\x43\x3a\n");
    ಬರೆ("c=%c\n", 'r');
    ಬರೆ("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    ಬರೆ("foo1_string='%s'\n", foo1_string);
#ಆದರೆ 0
    ಬರೆ("wstring=%S\n", L"abc");
    ಬರೆ("wstring=%S\n", L"abc" L"def" "ghi");
    ಬರೆ("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    ಬರೆ("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#ಆದರೆ_ಅಂತ್ಯ
    ps("test\n");
    b = 32;
    ಆಗ ((b = b + 1) < 96) {
        ಬರೆ("%c", b);
    }
    ಬರೆ("\n");
    ಬರೆ("fib=%d\n", fib(33));
    b = 262144;
    ಆಗ (b != 0x80000000) {
        ಅಂಕೆ(b);
        b = b * 2;
    }
    string_test2();
}


ಶೂನ್ಯ if1t(ಪೂರ್ಣಾಂಕ n, ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ c)
{
    ಆದರೆ (a && b) ಬರೆ("if1t: %d 1 %d %d\n", n, a, b);
    ಆದರೆ (a && !b) ಬರೆ("if1t: %d 2 %d %d\n", n, a, b);
    ಆದರೆ (!a && b) ಬರೆ("if1t: %d 3 %d %d\n", n, a, b);
    ಆದರೆ (!a && !b) ಬರೆ("if1t: %d 4 %d %d\n", n, a, b);
    ಆದರೆ (a || b) ಬರೆ("if1t: %d 5 %d %d\n", n, a, b);
    ಆದರೆ (a || !b) ಬರೆ("if1t: %d 6 %d %d\n", n, a, b);
    ಆದರೆ (!a || b) ಬರೆ("if1t: %d 7 %d %d\n", n, a, b);
    ಆದರೆ (!a || !b) ಬರೆ("if1t: %d 8 %d %d\n", n, a, b);
    ಆದರೆ (a && b || c) ಬರೆ("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ಆದರೆ (a || b && c) ಬರೆ("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ಆದರೆ (a > b - 1 && c) ಬರೆ("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ಆದರೆ (a > b - 1 || c) ಬರೆ("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ಆದರೆ (a > 0 && 1) ಬರೆ("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ಆದರೆ (a > 0 || 0) ಬರೆ("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

ಶೂನ್ಯ if2t(ಶೂನ್ಯ)
{
    ಆದರೆ (0 && 1 || ಬರೆ("if2t:ok\n") || 1)
      ಬರೆ("if2t:ok2\n");
    ಬರೆ("if2t:ok3\n");
}

ಶೂನ್ಯ if3t(ಶೂನ್ಯ)
{
    ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ i = 1;
    ಆದರೆ (i <= 18446744073709551615ULL)
      ;
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ ("if3t:wrong 1\n");
}

ಶೂನ್ಯ if_test(ಶೂನ್ಯ)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

ಶೂನ್ಯ loop_test()
{
    ಪೂರ್ಣಾಂಕ i;
    i = 0;
    ಆಗ (i < 10)
        ಬರೆ("%d", i++);
    ಬರೆ("\n");
    ಗಾಗಿ(i = 0; i < 10;i++)
        ಬರೆ("%d", i);
    ಬರೆ("\n");
    i = 0;
    ಮಾಡು {
        ಬರೆ("%d", i++);
    } ಆಗ (i < 10);
    ಬರೆ("\n");

    ಅಕ್ಷರ ಎಣಿಕೆ_3 = 123;
    /* c99 for loop init test */
    ಗಾಗಿ (ಗಾತ್ರ_t ಎಣಿಕೆ_3 = 1; ಎಣಿಕೆ_3 < 3; ಎಣಿಕೆ_3++)
        ಬರೆ("count=%d\n", ಎಣಿಕೆ_3);
    ಬರೆ("count = %d\n", ಎಣಿಕೆ_3);

    /* break/continue tests */
    i = 0;
    ಆಗ (1) {
        ಆದರೆ (i == 6)
            ನಿಲ್ಲಿಸು;
        i++;
        ಆದರೆ (i == 3)
            ಮುಂದುವರಿ;
        ಬರೆ("%d", i);
    }
    ಬರೆ("\n");

    /* break/continue tests */
    i = 0;
    ಮಾಡು {
        ಆದರೆ (i == 6)
            ನಿಲ್ಲಿಸು;
        i++;
        ಆದರೆ (i == 3)
            ಮುಂದುವರಿ;
        ಬರೆ("%d", i);
    } ಆಗ(1);
    ಬರೆ("\n");

    ಗಾಗಿ(i = 0;i < 10;i++) {
        ಆದರೆ (i == 3)
            ಮುಂದುವರಿ;
        ಬರೆ("%d", i);
    }
    ಬರೆ("\n");
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ typedef_and_label;

ಶೂನ್ಯ goto_test()
{
    ಪೂರ್ಣಾಂಕ i;
    ಸ್ಥಿರ ಶೂನ್ಯ *label_ಕೋಷ್ಟಕ[3] = { &&label1, &&label2, &&label3 };
    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    ಬರೆ("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    ಆದರೆ (i >= 10) 
        ಹೋಗು s_ಕೊನೆ;
    ಬರೆ("%d", i);
    i++;
    ಹೋಗು s_loop;
 s_ಕೊನೆ:
    ಬರೆ("\n");

    /* we also test computed gotos (GCC extension) */
    ಗಾಗಿ(i=0;i<3;i++) {
        ಹೋಗು *label_ಕೋಷ್ಟಕ[i];
    label1:
        ಬರೆ("label1\n");
        ಹೋಗು ಮುಂದಿನ;
    label2:
        ಬರೆ("label2\n");
        ಹೋಗು ಮುಂದಿನ;
    label3:
        ಬರೆ("label3\n");
    ಮುಂದಿನ: ;
    }
}

ಎಣಿಕೆ {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ಎಣಿಕೆ test {
    E5 = 1000,
};

ರಚನೆ S_enum {
    ಎಣಿಕೆ {E6 = 42, E7, E8} e:8;
};

ಎಣಿಕೆ ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)0xf000 << 31) << 1,
};

ಎಣಿಕೆ { BIASU = -1U<<31 };
ಎಣಿಕೆ { BIASS = -1 << 31 };

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ getint(ಪೂರ್ಣಾಂಕ i)
{
  ಆದರೆ (i)
    ಹಿಂತಿರುಗಿ 0;
  ಇಲ್ಲದಿದ್ದರೆ
    ಹಿಂತಿರುಗಿ (ಪೂರ್ಣಾಂಕ)(-1U << 31);
}

ಶೂನ್ಯ enum_test()
{
    ಎಣಿಕೆ test b1;
    /* The following should give no warning */
    ಚಿಹ್ನೆರಹಿತ *p = &b1;
    ರಚನೆ S_enum s = {E7};
    ಬರೆ("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    ಬರೆ("b1=%d\n", b1);
    ಬರೆ("enum large: %ld\n", EL_large);

    ಆದರೆ (getint(0) == BIASU)
      ಬರೆ("enum unsigned: ok\n");
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ("enum unsigned: wrong\n");
    ಆದರೆ (getint(0) == BIASS)
      ಬರೆ("enum unsigned: ok\n");
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ("enum unsigned: wrong\n");
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ *my_ptr;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ mytype1;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ mytype2;

ಶೂನ್ಯ typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    ಪೂರ್ಣಾಂಕ b;

    a = &b;
    *a = 1234;
    ಬರೆ("a=%d\n", *a);
    mytype2 = 2;
    ಬರೆ("mytype2=%d\n", mytype2);
}

ಶೂನ್ಯ forward_test()
{
    forward_ref();
    forward_ref();
}


ಶೂನ್ಯ forward_ref(ಶೂನ್ಯ)
{
    ಬರೆ("forward ok\n");
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ struct1 {
    ಪೂರ್ಣಾಂಕ f1;
    ಪೂರ್ಣಾಂಕ f2, f3;
    ಒಕ್ಕೂಟ union1 {
        ಪೂರ್ಣಾಂಕ v1;
        ಪೂರ್ಣಾಂಕ v2;
    } u;
    ಅಕ್ಷರ str[3];
} struct1;

ರಚನೆ struct2 {
    ಪೂರ್ಣಾಂಕ a;
    ಅಕ್ಷರ b;
};

ಒಕ್ಕೂಟ union2 {
    ಪೂರ್ಣಾಂಕ w1;
    ಪೂರ್ಣಾಂಕ w2;
};

ರಚನೆ struct1 st1, st2;

ರಚನೆ ಖಾಲಿಗಳು_mem {
    /* nothing */ ;
    ಪೂರ್ಣಾಂಕ x;
};

ಪೂರ್ಣಾಂಕ tab[3];
ಪೂರ್ಣಾಂಕ tab2[3][2];

ಪೂರ್ಣಾಂಕ g;

ಶೂನ್ಯ f1(ಪೂರ್ಣಾಂಕ g)
{
    ಬರೆ("g1=%d\n", g);
}

ಶೂನ್ಯ scope_test()
{
    g = 2;
    f1(1);
    ಬರೆ("g2=%d\n", g);
    {
        ಪೂರ್ಣಾಂಕ g;
        g = 3;
        ಬರೆ("g3=%d\n", g);
        {
            ಪೂರ್ಣಾಂಕ g;
            g = 4;
            ಬರೆ("g4=%d\n", g);
        }
    }
    ಬರೆ("g5=%d\n", g);
}

ಪೂರ್ಣಾಂಕ st2_i;
ಪೂರ್ಣಾಂಕ *st2_p = &st2_i;
ಶೂನ್ಯ scope2_test()
{
    ಅಕ್ಷರ a[50];
    st2_i = 42;
    ಗಾಗಿ (ಪೂರ್ಣಾಂಕ st2_i = 1; st2_i < 10; st2_i++) {
        ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ st2_i;
        st2_i++;
        ಬರೆ("exloc: %d\n", st2_i);
    }
    ಬರೆ("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ st_global1;
ಪೂರ್ಣಾಂಕ st_global1=42;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ st_global1;
ಪೂರ್ಣಾಂಕ st_global1;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ st_global2;
ಪೂರ್ಣಾಂಕ st_global2;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ st_global2;
ಪೂರ್ಣಾಂಕ st_global2;

ಶೂನ್ಯ array_test()
{
    ಪೂರ್ಣಾಂಕ i, j, a[4];

    ಬರೆ("sizeof(a) = %d\n", ಗಾತ್ರ(a));
    ಬರೆ("sizeof(\"a\") = %d\n", ಗಾತ್ರ("a"));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ C99_MACROS
    ಬರೆ("sizeof(__func__) = %d\n", ಗಾತ್ರ(__func__));
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("sizeof tab %d\n", ಗಾತ್ರ(tab));
    ಬರೆ("sizeof tab2 %d\n", ಗಾತ್ರ tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    ಬರೆ("%d %d %d\n", tab[0], tab[1], tab[2]);
    ಗಾಗಿ(i=0;i<3;i++)
        ಗಾಗಿ(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    ಗಾಗಿ(i=0;i<3*2;i++) {
        ಬರೆ(" %3d", ((ಪೂರ್ಣಾಂಕ *)tab2)[i]);
    }
    ಬರೆ("\n");
    ಬರೆ("sizeof(size_t)=%d\n", ಗಾತ್ರ(ಗಾತ್ರ_t));
    ಬರೆ("sizeof(ptrdiff_t)=%d\n", ಗಾತ್ರ(ptrdiff_t));
}

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_test()
{
    ಪೂರ್ಣಾಂಕ a, b;
    a = 0;
    ಬರೆ("%d\n", a += 1);
    ಬರೆ("%d\n", a -= 2);
    ಬರೆ("%d\n", a *= 31232132);
    ಬರೆ("%d\n", a /= 4);
    ಬರೆ("%d\n", a %= 20);
    ಬರೆ("%d\n", a &= 6);
    ಬರೆ("%d\n", a ^= 7);
    ಬರೆ("%d\n", a |= 8);
    ಬರೆ("%d\n", a >>= 3);
    ಬರೆ("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    ಬರೆ("%d\n", a + 1);
    ಬರೆ("%d\n", a - 2);
    ಬರೆ("%d\n", a * 312);
    ಬರೆ("%d\n", a / 4);
    ಬರೆ("%d\n", b / 4);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)b / 4);
    ಬರೆ("%d\n", a % 20);
    ಬರೆ("%d\n", b % 20);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)b % 20);
    ಬರೆ("%d\n", a & 6);
    ಬರೆ("%d\n", a ^ 7);
    ಬರೆ("%d\n", a | 8);
    ಬರೆ("%d\n", a >> 3);
    ಬರೆ("%d\n", b >> 3);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)b >> 3);
    ಬರೆ("%d\n", a << 4);
    ಬರೆ("%d\n", ~a);
    ಬರೆ("%d\n", -a);
    ಬರೆ("%d\n", +a);

    ಬರೆ("%d\n", 12 + 1);
    ಬರೆ("%d\n", 12 - 2);
    ಬರೆ("%d\n", 12 * 312);
    ಬರೆ("%d\n", 12 / 4);
    ಬರೆ("%d\n", 12 % 20);
    ಬರೆ("%d\n", 12 & 6);
    ಬರೆ("%d\n", 12 ^ 7);
    ಬರೆ("%d\n", 12 | 8);
    ಬರೆ("%d\n", 12 >> 2);
    ಬರೆ("%d\n", 12 << 4);
    ಬರೆ("%d\n", ~12);
    ಬರೆ("%d\n", -12);
    ಬರೆ("%d\n", +12);
    ಬರೆ("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

ಪೂರ್ಣಾಂಕ isid(ಪೂರ್ಣಾಂಕ c)
{
    ಹಿಂತಿರುಗಿ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

ಪೂರ್ಣಾಂಕ vstack[10], *vstack_ptr;

ಶೂನ್ಯ vpush(ಪೂರ್ಣಾಂಕ vt, ಪೂರ್ಣಾಂಕ vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

ಶೂನ್ಯ vpop(ಪೂರ್ಣಾಂಕ *ft, ಪೂರ್ಣಾಂಕ *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

ಶೂನ್ಯ expr2_test()
{
    ಪೂರ್ಣಾಂಕ a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    ಬರೆ("res= %d %d\n", a, b);
}

ಪೂರ್ಣಾಂಕ const_len_ar[ಗಾತ್ರ(1/0)]; /* div-by-zero, but in unevaluated context */

ಶೂನ್ಯ constant_ಅಭಿವ್ಯಕ್ತಿ_test()
{
    ಪೂರ್ಣಾಂಕ a;
    a = 3;
    ಬರೆ("%d\n", a * 16);
    ಬರೆ("%d\n", a * 1);
    ಬರೆ("%d\n", a + 0);
    ಬರೆ("%d\n", ಗಾತ್ರ(const_len_ar));
}

ಪೂರ್ಣಾಂಕ tab4[10];

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_ptr_test()
{
    ಪೂರ್ಣಾಂಕ arr[10], *p, *q;
    ಪೂರ್ಣಾಂಕ i = -1;

    p = tab4;
    q = tab4 + 10;
    ಬರೆ("diff=%d\n", q - p);
    p++;
    ಬರೆ("inc=%d\n", p - tab4);
    p--;
    ಬರೆ("dec=%d\n", p - tab4);
    ++p;
    ಬರೆ("inc=%d\n", p - tab4);
    --p;
    ಬರೆ("dec=%d\n", p - tab4);
    ಬರೆ("add=%d\n", p + 3 - tab4);
    ಬರೆ("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    ಬರೆ("%p %p %ld\n", q, p, p-q);
    ಬರೆ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    ಬರೆ("%p %p %ld\n", q, p, p-q);
    ಬರೆ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (ಪೂರ್ಣಾಂಕ *)((ಅಕ್ಷರ *)p + 0xf0000000);
    ಬರೆ("%p %p %ld\n", q, p, p-q);
    ಬರೆ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    ಬರೆ("%p %p %ld\n", q, p, p-q);
    ಬರೆ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ರಚನೆ size12 {
            ಪೂರ್ಣಾಂಕ i, j, k;
        };
        ರಚನೆ size12 s[2], *sp = s;
        ಪೂರ್ಣಾಂಕ i, j;
        sp->i = 42;
        sp++;
        j = -1;
        ಬರೆ("%d\n", sp[j].i);
    }
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __LP64__
    i = 1;
    p = (ಪೂರ್ಣಾಂಕ*)0x100000000UL + i;
    i = ((ದೀರ್ಘ)p) >> 32;
    ಬರೆ("largeptr: %p %d\n", p, i);
#ಆದರೆ_ಅಂತ್ಯ
    p = &arr[0];
    q = p + 3;
    ಬರೆ ("%d\n", (ಪೂರ್ಣಾಂಕ)((p - q) / 3));
}

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmp_test()
{
    ಪೂರ್ಣಾಂಕ a, b;
    a = -1;
    b = 1;
    ಬರೆ("%d\n", a == a);
    ಬರೆ("%d\n", a != a);

    ಬರೆ("%d\n", a < b);
    ಬರೆ("%d\n", a <= b);
    ಬರೆ("%d\n", a <= a);
    ಬರೆ("%d\n", b >= a);
    ಬರೆ("%d\n", a >= a);
    ಬರೆ("%d\n", b > a);

    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)a < b);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)a <= b);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)a <= a);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)b >= a);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)a >= a);
    ಬರೆ("%d\n", (ಚಿಹ್ನೆರಹಿತ)b > a);
}

ರಚನೆ ಖಾಲಿಗಳು {
};

ರಚನೆ aligntest1 {
    ಅಕ್ಷರ a[10];
};

ರಚನೆ aligntest2 {
    ಪೂರ್ಣಾಂಕ a;
    ಅಕ್ಷರ b[10];
};

ರಚನೆ aligntest3 {
    ದ್ವಿಗುಣ a, b;
};

ರಚನೆ aligntest4 {
    ದ್ವಿಗುಣ a[0];
};

ರಚನೆ __attribute__((aligned(16))) aligntest5
{
    ಪೂರ್ಣಾಂಕ i;
};
ರಚನೆ aligntest6
{
    ಪೂರ್ಣಾಂಕ i;
} __attribute__((aligned(16)));
ರಚನೆ aligntest7
{
    ಪೂರ್ಣಾಂಕ i;
};
ರಚನೆ aligntest5 altest5[2];
ರಚನೆ aligntest6 altest6[2];
ಪೂರ್ಣಾಂಕ pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ರಚನೆ aligntest7 altest7[2] __attribute__((aligned(16)));

ರಚನೆ aligntest8
{
  ಪೂರ್ಣಾಂಕ i;
} __attribute__((aligned(4096)));

ರಚನೆ Large {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ flags;
    ಒಕ್ಕೂಟ {
	ಶೂನ್ಯ *u1;
	ಪೂರ್ಣಾಂಕ *u2;
    };

    ರಚನೆ {
	ಒಕ್ಕೂಟ {
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಸೂಚ್ಯಂಕ;
	    ಶೂನ್ಯ *freelist;
	};
	ಒಕ್ಕೂಟ {
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ counters;
	    ರಚನೆ {
		ಪೂರ್ಣಾಂಕ bla;
	    };
	};
    };

    ಒಕ್ಕೂಟ {
	ರಚನೆ {
	    ದೀರ್ಘ u3;
	    ದೀರ್ಘ u4;
	};
	ಶೂನ್ಯ *u5;
	ರಚನೆ {
	    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ compound_ತಲೆ;
	    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ compound_dtor;
	    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ compound_ಕ್ರಮ;
	};
    };
} __attribute__((aligned(2 * ಗಾತ್ರ(ದೀರ್ಘ))));

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ __attribute__((aligned(4))) unaligned_u64;

ರಚನೆ aligntest9 {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ buf_nr;
    unaligned_u64 ಆರಂಭ_lba;
};

ರಚನೆ aligntest10 {
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ buf_nr;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಆರಂಭ_lba;
};

ಶೂನ್ಯ struct_test()
{
    struct1 *s;
    ಒಕ್ಕೂಟ union2 u;
    ರಚನೆ Large ls;

    ಬರೆ("sizes: %d %d %d %d\n",
           ಗಾತ್ರ(ರಚನೆ struct1),
           ಗಾತ್ರ(ರಚನೆ struct2),
           ಗಾತ್ರ(ಒಕ್ಕೂಟ union1),
           ಗಾತ್ರ(ಒಕ್ಕೂಟ union2));
    ಬರೆ("offsets: %d\n", (ಪೂರ್ಣಾಂಕ)((ಅಕ್ಷರ*)&st1.u.v1 - (ಅಕ್ಷರ*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    ಬರೆ("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    ಬರೆ("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    ಬರೆ("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    ಬರೆ("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    ಬರೆ("str_addr=%x\n", (ಪೂರ್ಣಾಂಕ)(uintptr_t)st1.str - (ಪೂರ್ಣಾಂಕ)(uintptr_t)&st1.f1);

    /* align / size tests */
    ಬರೆ("aligntest1 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest1), __alignof__(ರಚನೆ aligntest1));
    ಬರೆ("aligntest2 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest2), __alignof__(ರಚನೆ aligntest2));
    ಬರೆ("aligntest3 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest3), __alignof__(ರಚನೆ aligntest3));
#ಆದರೆ !(defined _WIN32 && CC_NAME == CC_clang)
    ಬರೆ("aligntest4 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest4), __alignof__(ರಚನೆ aligntest4));
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("aligntest5 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest5), __alignof__(ರಚನೆ aligntest5));
    ಬರೆ("aligntest6 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest6), __alignof__(ರಚನೆ aligntest6));
    ಬರೆ("aligntest7 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest7), __alignof__(ರಚನೆ aligntest7));
    ಬರೆ("aligntest8 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest8), __alignof__(ರಚನೆ aligntest8));
#ಆದರೆ !(defined _WIN32 && CC_NAME == CC_clang)
    ಬರೆ("aligntest9 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest9), __alignof__(ರಚನೆ aligntest9));
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("aligntest10 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(ರಚನೆ aligntest10), __alignof__(ರಚನೆ aligntest10));
    ಬರೆ("altest5 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(altest5), __alignof__(altest5));
    ಬರೆ("altest6 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(altest6), __alignof__(altest6));
    ಬರೆ("altest7 sizeof=%d alignof=%d\n",
           ಗಾತ್ರ(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ಆದರೆ !(defined _WIN32 && CC_NAME == CC_clang)
    ಬರೆ("sizeof(struct empty) = %d\n", ಗಾತ್ರ(ರಚನೆ ಖಾಲಿಗಳು));
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("alignof(struct empty) = %d\n", __alignof__(ರಚನೆ ಖಾಲಿಗಳು));

    ಬರೆ("Large: sizeof=%d\n", ಗಾತ್ರ(ls));
    memset(&ls, 0, ಗಾತ್ರ(ls));
    ls.compound_ತಲೆ = 42;
    ಬರೆ("Large: offsetof(compound_head)=%d\n", (ಪೂರ್ಣಾಂಕ)((ಅಕ್ಷರ*)&ls.compound_ತಲೆ - (ಅಕ್ಷರ*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ __csf(ಪೂರ್ಣಾಂಕ x) { ಹಿಂತಿರುಗಿ x; }
ಸ್ಥಿರ ಶೂನ್ಯ *_csf = __csf;
#ವ್ಯಾಖ್ಯಾನಿಸು csf(t,n) ((t(*)(ಪೂರ್ಣಾಂಕ))_csf)(n)

/* XXX: depend on endianness */
ಶೂನ್ಯ char_short_test()
{
    ಪೂರ್ಣಾಂಕ var1, var2;
    ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ var3;
    ದೀರ್ಘ ದೀರ್ಘ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    ಬರೆ("s8=%d %d\n", 
           *(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ *)&var1, *(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ *)&var2);
    ಬರೆ("u8=%d %d\n", 
           *(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)&var1, *(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)&var2);
    ಬರೆ("s16=%d %d\n", 
           *(ಗಿಡ್ಡ *)&var1, *(ಗಿಡ್ಡ *)&var2);
    ಬರೆ("u16=%d %d\n", 
           *(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *)&var1, *(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *)&var2);
    ಬರೆ("s32=%d %d\n", 
           *(ಪೂರ್ಣಾಂಕ *)&var1, *(ಪೂರ್ಣಾಂಕ *)&var2);
    ಬರೆ("u32=%d %d\n", 
           *(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *)&var1, *(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *)&var2);
    *(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ *)&var1 = 0x08;
    ಬರೆ("var1=%x\n", var1);
    *(ಗಿಡ್ಡ *)&var1 = 0x0809;
    ಬರೆ("var1=%x\n", var1);
    *(ಪೂರ್ಣಾಂಕ *)&var1 = 0x08090a0b;
    ಬರೆ("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    ಬರೆ("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    ಬರೆ("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    ಬರೆ("promote char/short cast VA %d %d\n", (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)(var1 + 1), (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)(var4 + 1));
#ಆದರೆ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ,0x89898989);
    var4 = csf(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ,0xabababab);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    ಬರೆ("promote char/short fumcret VA %d %d %d %d\n",
        csf(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,0xcdcdcdcd),
        csf(ಗಿಡ್ಡ,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#ಆದರೆ_ಅಂತ್ಯ
    var3 = -10;
    var1 = (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(var3 + 1);
    var4 = (ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(var3 + 1);
    ಬರೆ("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (ಚಿಹ್ನೆರಹಿತ)(ಪೂರ್ಣಾಂಕ)(var4 + 1);
    ಬರೆ("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (ಚಿಹ್ನೆರಹಿತ)(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)(var4 + 1);
    ಬರೆ("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Sym {
    ಪೂರ್ಣಾಂಕ v;
    ಪೂರ್ಣಾಂಕ t;
    ಪೂರ್ಣಾಂಕ c;
    ರಚನೆ Sym *ಮುಂದಿನ;
    ರಚನೆ Sym *prev;
} Sym;

#ವ್ಯಾಖ್ಯಾನಿಸು ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#ವ್ಯಾಖ್ಯಾನಿಸು TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ toupper1(ಪೂರ್ಣಾಂಕ a)
{
    ಹಿಂತಿರುಗಿ TOUPPER(a);
}

ಸ್ಥಿರ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ calc_vm_flags(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ prot)
{
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ prot_ಬಿಟ್ಟುಗಳು;
  /* This used to segfault in some revisions: */
  prot_ಬಿಟ್ಟುಗಳು = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ಹಿಂತಿರುಗಿ prot_ಬಿಟ್ಟುಗಳು;
}

ಎಣಿಕೆ cast_enum { ಮೊದಲ_2, ಕೊನೆಯ_2 };

ಸ್ಥಿರ ಶೂನ್ಯ tst_cast(ಎಣಿಕೆ cast_enum ce)
{
    ಬರೆ("%d\n", ce);
}

ಶೂನ್ಯ bool_test()
{
    ಪೂರ್ಣಾಂಕ *s, a, b, t, f, i;

    a = 0;
    s = (ಶೂನ್ಯ*)0;
    ಬರೆ("!s=%d\n", !s);

    ಆದರೆ (!s || !s[0])
        a = 1;
    ಬರೆ("a=%d\n", a);

    ಬರೆ("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    ಬರೆ("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    ಬರೆ("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ಆದರೆ 1 && 1
    ಬರೆ("a1\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1 || 0
    ಬರೆ("a2\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 1 ? 0 : 1
    ಬರೆ("a3\n");
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ 0 ? 0 : 1
    ಬರೆ("a4\n");
#ಆದರೆ_ಅಂತ್ಯ

    a = 4;
    ಬರೆ("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    ಬರೆ("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    ಬರೆ("exp=%d\n", f == (32 <= a && a <= 3));
    ಬರೆ("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    ಬರೆ("type of bool: %d\n", (ಪೂರ್ಣಾಂಕ) ( (~ ((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ) (t && 1))) / 2) );
    tst_cast(t >= 0 ? ಮೊದಲ_2 : ಕೊನೆಯ_2);

    ಬರೆ("type of cond: %d\n", (~(t ? 0U : (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ)0)) / 2 );
    /* test ? : cast */
    {
        ಪೂರ್ಣಾಂಕ aspect_on;
        ಪೂರ್ಣಾಂಕ aspect_native = 65536;
        ದ್ವಿಗುಣ bfu_aspect = 1.0;
        ಪೂರ್ಣಾಂಕ aspect;
        ಗಾಗಿ(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            ಬರೆ("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ v1 = 34 ? : -1; /* constant case */
        ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ v2 = 0 ? : -1; /* constant case */
        ಪೂರ್ಣಾಂಕ a = 30;
        
        ಬರೆ("%d %d\n", v1, v2);
        ಬರೆ("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    ಗಾಗಿ(i=0;i<256;i++) {
        ಆದರೆ (toupper1 (i) != TOUPPER (i))
            ಬರೆ("error %d\n", i);
    }
    ಬರೆ ("bits = 0x%x\n", calc_vm_flags (0x1));
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ undefined_function(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ defined_function(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
ಪೂರ್ಣಾಂಕ undefined_function(ಶೂನ್ಯ) {}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ refer_ಗಮ್ಯ_undefined(ಶೂನ್ಯ)
{
  undefined_function();
}

ಶೂನ್ಯ optimize_ಹೊರಹೋಗು_test(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i = 0 ? undefined_function() : defined_function();
  ಬರೆ ("oo:%d\n", i);
  ಪೂರ್ಣಾಂಕ j = 1 ? defined_function() : undefined_function();
  ಬರೆ ("oo:%d\n", j);
  ಆದರೆ (0)
    ಬರೆ("oo:%d\n", undefined_function());
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("oo:%d\n", defined_function());
  ಆದರೆ (1)
    ಬರೆ("oo:%d\n", defined_function());
  ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("oo:%d\n", undefined_function());
  ಆಗ (1) {
      ಬರೆ("oow:%d\n", defined_function());
      ನಿಲ್ಲಿಸು;
      ಬರೆ("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ಆಯ್ಕೆ (j)
    ಸ್ಥಿತಿ 1: ನಿಲ್ಲಿಸು;
  ಬರೆ ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ಆಗ (1)
    ನಿಲ್ಲಿಸು;
  ಬರೆ ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  ಮಾಡು
    ನಿಲ್ಲಿಸು;
  ಆಗ (1);
  ಬರೆ ("ool2:%d\n", defined_function());
  ಗಾಗಿ (;;)
    ನಿಲ್ಲಿಸು;
  ಬರೆ ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ಆಗ (1) {
	{
	  ನಿಲ್ಲಿಸು;
	}
      ಬರೆ ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ಆಗ (j) {
      ಆದರೆ (j == 0)
	ನಿಲ್ಲಿಸು; /* this break shouldn't disable code outside the if. */
      ಬರೆ("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ಆಗ (j) {
      ಆದರೆ (1)
	j--;
      ಇಲ್ಲದಿದ್ದರೆ
	breakhere: ನಿಲ್ಲಿಸು;
      ಬರೆ("ool6:%d\n", defined_function());
      ಹೋಗು breakhere;
  }
  j = 1;
  ಆಗ (j) {
      j--;
      ಮುಂದುವರಿ;
      ಬರೆ("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ಆದರೆ (0 && undefined_function())
    undefined_function();
  ಆದರೆ (defined_function() && 0)
    undefined_function();
  ಆದರೆ (0 && 0)
    undefined_function();
  ಆದರೆ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ಆದರೆ (1 || undefined_function())
    ;
  ಇಲ್ಲದಿದ್ದರೆ
    undefined_function();
  ಆದರೆ (defined_function() || 1)
    ;
  ಇಲ್ಲದಿದ್ದರೆ
    undefined_function();
  ಆದರೆ (1 || 1)
    ;
  ಇಲ್ಲದಿದ್ದರೆ
    undefined_function();
  ಆದರೆ (defined_function() || 1 || undefined_function())
    ;
  ಇಲ್ಲದಿದ್ದರೆ
    undefined_function();

  ಆದರೆ (defined_function() && 0)
    refer_ಗಮ್ಯ_undefined();

  ಆದರೆ (0) {
      (ಶೂನ್ಯ)ಗಾತ್ರ( ({
		     ಮಾಡು { } ಆಗ (0);
		     0;
		     }) );
      undefined_function();
  }

  ಆದರೆ (0) {
      ಆಯ್ಕೆ (defined_function()) {
          ಸ್ಥಿತಿ 0: undefined_function(); ನಿಲ್ಲಿಸು;
          ಪೂರ್ವನಿಯೋಜಿತ: undefined_function(); ನಿಲ್ಲಿಸು;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ಆದರೆ (1)
    ಹಿಂತಿರುಗಿ;
  ಬರೆ ("oor:%d\n", undefined_function());
}

ಪೂರ್ಣಾಂಕ defined_function(ಶೂನ್ಯ)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ i = 40;
  ಹಿಂತಿರುಗಿ i++;
}

/* GCC accepts that */
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tab_reinit[];
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tab_reinit[10];

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tentative_ar[];
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ tentative_ar[] = {1,2,3};

ಪೂರ್ಣಾಂಕ cinit1; /* a global variable can be defined several times without error ! */
ಪೂರ್ಣಾಂಕ cinit1; 
ಪೂರ್ಣಾಂಕ cinit1 = 0;
ಪೂರ್ಣಾಂಕ *cinit2 = (ಪೂರ್ಣಾಂಕ []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
ಅಕ್ಷರ ಸ್ಥಿರಾಂಕ * ಸ್ಥಿರಾಂಕ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
ಶೂನ್ಯ *cinit52 = &(ಶೂನ್ಯ*){ (ಶೂನ್ಯ*) 52 };

#ಆದರೆ __TINYC__ || __GNUC__ >= 6
ಪೂರ್ಣಾಂಕ cinit4 = (ಪೂರ್ಣಾಂಕ){44};
ಶೂನ್ಯ *cinit51 = (ಶೂನ್ಯ*){ (ಶೂನ್ಯ*) 51 };
ರಚನೆ _c6 { ಪೂರ್ಣಾಂಕ a,b; } cinit6 = (ರಚನೆ _c6){61,62}, *cinit7 = &(ರಚನೆ _c6){71,72};
#ಇಲ್ಲದಿದ್ದರೆ
ಪೂರ್ಣಾಂಕ cinit4 = 44;
ಶೂನ್ಯ *cinit51 = (ಶೂನ್ಯ*)51;
ರಚನೆ _c6 { ಪೂರ್ಣಾಂಕ a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ compound_literal_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ *p, i;
    ಅಕ್ಷರ *q, *q3;

    ಬರೆ("cinit3 : %s\n", cinit3);
    ಬರೆ("cinit4 : %d\n", cinit4);
    ಬರೆ("cinit51 : %d\n", (ಪೂರ್ಣಾಂಕ)cinit51);
    ಬರೆ("cinit52 : %d\n", *(ಪೂರ್ಣಾಂಕ*)cinit52);
    ಬರೆ("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    ಬರೆ("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    ಬರೆ("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (ಪೂರ್ಣಾಂಕ []){1, 2, 3};
    ಗಾಗಿ(i=0;i<3;i++)
        ಬರೆ(" %d", p[i]);
    ಬರೆ("\n");

    ಗಾಗಿ(i=0;i<3;i++)
        ಬರೆ("%d", cinit2[i]);
    ಬರೆ("\n");

    q = "tralala1";
    ಬರೆ("q1=%s\n", q);

    q = (ಅಕ್ಷರ *){ "tralala2" };
    ಬರೆ("q2=%s\n", q);

    q3 = (ಅಕ್ಷರ *){ q };
    ಬರೆ("q3=%s\n", q3);

    q = (ಅಕ್ಷರ []){ "tralala3" };
    ಬರೆ("q4=%s\n", q);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ALL_ISOC99
    p = (ಪೂರ್ಣಾಂಕ []){1, 2, cinit1 + 3};
    ಗಾಗಿ(i=0;i<3;i++)
        ಬರೆ(" %d", p[i]);
    ಬರೆ("\n");

    ಗಾಗಿ(i=0;i<3;i++) {
        p = (ಪೂರ್ಣಾಂಕ []){1, 2, 4 + i};
        ಬರೆ("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#ಆದರೆ_ಅಂತ್ಯ
}


#ಆದರೆ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ಹಿಂತಿರುಗಿ a + b;
}

ಪೂರ್ಣಾಂಕ kr_func2(a, b)
{
    ಹಿಂತಿರುಗಿ a + b;
}

kr_test()
{
    ಬರೆ("func1=%d\n", kr_func1(3, 4));
    ಬರೆ("func2=%d\n", kr_func2(3, 4));
    ಹಿಂತಿರುಗಿ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
ಅಕ್ಷರ invalid_function_def()[] {ಹಿಂತಿರುಗಿ 0;}

#ಇಲ್ಲದಿದ್ದರೆ
# define kr_test() ಬರೆ("func1=7\nfunc2=7\n")
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ ಅಂಕೆ(ಪೂರ್ಣಾಂಕ n)
{
    ಅಕ್ಷರ *tab, *p;
    tab = (ಅಕ್ಷರ*)ಸ್ಮರಣೆ_ಕೊಡು(20); 
    p = tab;
    ಆಗ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ಆದರೆ (n == 0)
            ನಿಲ್ಲಿಸು;
    }
    ಆಗ (p != tab) {
        p--;
        ಬರೆ("%c", *p);
    }
    ಬರೆ("\n");
    ಬಿಡುಗಡೆ(tab);
}

/* structure assignment tests */
ರಚನೆ structa1 {
    ಪೂರ್ಣಾಂಕ f1;
    ಅಕ್ಷರ f2;
};

ಶೂನ್ಯ struct_ನಿಯೋಜಿಸು_test1(ರಚನೆ structa1 s1, ಪೂರ್ಣಾಂಕ t, ದಶಮಾಂಶ f)
{
    ಬರೆ("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ರಚನೆ structa1 struct_ನಿಯೋಜಿಸು_test2(ರಚನೆ structa1 s1, ಪೂರ್ಣಾಂಕ t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ಹಿಂತಿರುಗಿ s1;
}

ಶೂನ್ಯ struct_ನಿಯೋಜಿಸು_test(ಶೂನ್ಯ)
{
    ರಚನೆ S {
      ರಚನೆ structa1 lsta1, lsta2;
      ಪೂರ್ಣಾಂಕ i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_ನಿಯೋಜಿಸು_test1(ps->lsta2, 3, 4.5);
    ಬರೆ("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_ನಿಯೋಜಿಸು_test2(ps->lsta2, ps->i);
    ಬರೆ("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ಸ್ಥಿರ ರಚನೆ {
        ಶೂನ್ಯ (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_ನಿಯೋಜಿಸು_test }
    };
    ಬರೆ("%d\n", struct_ನಿಯೋಜಿಸು_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_ನಿಯೋಜಿಸು_test2(s.lsta1, 1);
    ಬರೆ("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

ಶೂನ್ಯ cast1(ಅಕ್ಷರ a, ಗಿಡ್ಡ b, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c, ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ d)
{
    ಬರೆ("%d %d %d %d\n", a, b, c, d);
}

ಅಕ್ಷರ bcast;
ಗಿಡ್ಡ scast;

ಶೂನ್ಯ cast_test()
{
    ಪೂರ್ಣಾಂಕ a;
    ಅಕ್ಷರ c;
    ಅಕ್ಷರ tab[10];
    ಚಿಹ್ನೆರಹಿತ b,d;
    ಗಿಡ್ಡ s;
    ಅಕ್ಷರ *p = ಖಾಲಿ;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    ಬರೆ("%d %d %d %d\n",
           (ಅಕ್ಷರ)(a + 1),
           (ಗಿಡ್ಡ)(a + 1),
           (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)(a + 1),
           (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)(a + 1));
    ಬರೆ("%d %d %d %d\n",
           (ಅಕ್ಷರ)0xfffff,
           (ಗಿಡ್ಡ)0xfffff,
           (ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)0xfffff,
           (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)0xfffff);

    a = (bcast = 128) + 1;
    ಬರೆ("%d\n", a);
    a = (scast = 65536) + 1;
    ಬರೆ("%d\n", a);
    
    ಬರೆ("sizeof(c) = %d, sizeof((int)c) = %d\n", ಗಾತ್ರ(c), ಗಾತ್ರ((ಪೂರ್ಣಾಂಕ)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (ಗಿಡ್ಡ)b;
    ಬರೆ("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (ಅಕ್ಷರ)b;
    ಬರೆ("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    ಬರೆ("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    ಬರೆ("sizeof(+(char)'a') = %d\n", ಗಾತ್ರ(+(ಅಕ್ಷರ)'a'));
    ಬರೆ("sizeof(-(char)'a') = %d\n", ಗಾತ್ರ(-(ಅಕ್ಷರ)'a'));
    ಬರೆ("sizeof(~(char)'a') = %d\n", ಗಾತ್ರ(-(ಅಕ್ಷರ)'a'));

#ಆದರೆ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    ಬರೆ("%d %d %ld %ld %lld %lld\n",
           (ಪೂರ್ಣಾಂಕ)p, (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ)p,
           (ದೀರ್ಘ)p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)p,
           (ದೀರ್ಘ ದೀರ್ಘ)p, (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)p);
#ಆದರೆ_ಅಂತ್ಯ

    /* from integers to pointers */
    ಬರೆ("%p %p %p %p\n",
           (ಶೂನ್ಯ *)a, (ಶೂನ್ಯ *)b, (ಶೂನ್ಯ *)c, (ಶೂನ್ಯ *)d);

    /* int to int with sign set */
    ಬರೆ("0x%lx\n", (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)(ಪೂರ್ಣಾಂಕ)ul);
}

/* initializers tests */
ರಚನೆ structinit1 {
    ಪೂರ್ಣಾಂಕ f1;
    ಅಕ್ಷರ f2;
    ಗಿಡ್ಡ f3;
    ಪೂರ್ಣಾಂಕ farray[3];
};

ಪೂರ್ಣಾಂಕ sinit1 = 2;
ಪೂರ್ಣಾಂಕ sinit2 = { 3 };
ಪೂರ್ಣಾಂಕ sinit3[3] = { 1, 2, {3}, };
ಪೂರ್ಣಾಂಕ sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
ಪೂರ್ಣಾಂಕ sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
ಪೂರ್ಣಾಂಕ sinit6[] = { 1, 2, 3 };
ಪೂರ್ಣಾಂಕ sinit7[] = { [2] = 3, [0] = 1, 2 };
ಅಕ್ಷರ sinit8[] = "hello" "trala";

ರಚನೆ structinit1 sinit9 = { 1, 2, 3 };
ರಚನೆ structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ರಚನೆ structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#ಆದರೆ_ಅಂತ್ಯ
};

ಅಕ್ಷರ *sinit12 = "hello world";
ಅಕ್ಷರ *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
ಅಕ್ಷರ sinit14[10] = { "abc" };
ಪೂರ್ಣಾಂಕ sinit15[3] = { ಗಾತ್ರ(sinit15), 1, 2 };

ರಚನೆ { ಪೂರ್ಣಾಂಕ a[3], b; } sinit16[] = { { 1 }, 2 };

ರಚನೆ bar {
        ಅಕ್ಷರ *s;
        ಪೂರ್ಣಾಂಕ len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

ಪೂರ್ಣಾಂಕ sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ರಚನೆ complexinit0 {
    ಪೂರ್ಣಾಂಕ a;
    ಪೂರ್ಣಾಂಕ b;
};

ರಚನೆ complexinit {
    ಪೂರ್ಣಾಂಕ a;
    ಸ್ಥಿರಾಂಕ ರಚನೆ complexinit0 *b;
};

ಸ್ಥಿರಾಂಕ ಸ್ಥಿರ ರಚನೆ complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ಸ್ಥಿರಾಂಕ ರಚನೆ complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ರಚನೆ complexinit2 {
	ಪೂರ್ಣಾಂಕ a;
	ಪೂರ್ಣಾಂಕ b[];
};

ರಚನೆ complexinit2 cix20;

ರಚನೆ complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ರಚನೆ complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
ಪೂರ್ಣಾಂಕ sinit23[2] = { "astring" ? ಗಾತ್ರ("astring") : -1,
		   &sinit23 ? 42 : -1 };

ಪೂರ್ಣಾಂಕ sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ರಚನೆ bf_SS {ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಬಿಟ್:1,bits31:31; };
ರಚನೆ bf_SS bf_init = { .ಬಿಟ್ = 1 };
ರಚನೆ bfn_SS {ಪೂರ್ಣಾಂಕ a,b; ರಚನೆ bf_SS c; ಪೂರ್ಣಾಂಕ d,e; };
ರಚನೆ bfn_SS bfn_init = { .c.ಬಿಟ್ = 1 };
ರಚನೆ bfa_SS {ಪೂರ್ಣಾಂಕ a,b; ರಚನೆ bf_SS c[3]; ಪೂರ್ಣಾಂಕ d,e; };
ರಚನೆ bfa_SS bfa_init = { .c[1].ಬಿಟ್ = 1 };
ರಚನೆ bf_SS bfaa_init[3] = { [1].ಬಿಟ್ = 1 };
ರಚನೆ bf_SS bfaa_vinit[] = { [2].ಬಿಟ್ = 1 };
ರಚನೆ b2_SS {ದೀರ್ಘ ದೀರ್ಘ ಪೂರ್ಣಾಂಕ ಕ್ಷೇತ್ರ : 52; ದೀರ್ಘ ದೀರ್ಘ ಪೂರ್ಣಾಂಕ pad : 12; };
ರಚನೆ b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ external_inited = 42;

ಶೂನ್ಯ init_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ linit1 = 2;
    ಪೂರ್ಣಾಂಕ linit2 = { 3 };
    ಪೂರ್ಣಾಂಕ linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    ಪೂರ್ಣಾಂಕ linit6[] = { 1, 2, 3 };
    ಪೂರ್ಣಾಂಕ i, j;
    ಅಕ್ಷರ linit8[] = "hello" "trala";
    ಪೂರ್ಣಾಂಕ linit12[10] = { 1, 2 };
    ಪೂರ್ಣಾಂಕ linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    ಅಕ್ಷರ linit14[10] = "abc";
    ಪೂರ್ಣಾಂಕ linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ರಚನೆ linit16 { ಪೂರ್ಣಾಂಕ a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    ಪೂರ್ಣಾಂಕ linit17 = ಗಾತ್ರ(linit17);
    ಪೂರ್ಣಾಂಕ zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    ಪೂರ್ಣಾಂಕ linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ರಚನೆ bf_SS bf_finit = { .ಬಿಟ್ = 1 };
    ರಚನೆ bfn_SS bfn_finit = { .c.ಬಿಟ್ = 1 };
    ರಚನೆ bfa_SS bfa_finit = { .c[1].ಬಿಟ್ = 1 };
    ರಚನೆ bf_SS bfaa_finit[3] = { [1].ಬಿಟ್ = 1 };
    ರಚನೆ bf_SS bfaa_fvinit[] = { [2].ಬಿಟ್ = 1 };
    ರಚನೆ b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    ಬರೆ("sinit1=%d\n", sinit1);
    ಬರೆ("sinit2=%d\n", sinit2);
    ಬರೆ("sinit3=%d %d %d %d\n", 
           ಗಾತ್ರ(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    ಬರೆ("sinit6=%d\n", ಗಾತ್ರ(sinit6));
    ಬರೆ("sinit7=%d %d %d %d\n", 
           ಗಾತ್ರ(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    ಬರೆ("sinit8=%s\n", sinit8);
    ಬರೆ("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    ಬರೆ("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    ಬರೆ("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    ಗಾಗಿ(i=0;i<3;i++)
        ಗಾಗಿ(j=0;j<2;j++)
            ಬರೆ("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    ಬರೆ("linit1=%d\n", linit1);
    ಬರೆ("linit2=%d\n", linit2);
    ಬರೆ("linit6=%d\n", ಗಾತ್ರ(linit6));
    ಬರೆ("linit8=%d %s\n", ಗಾತ್ರ(linit8), linit8);

    ಬರೆ("sinit12=%s\n", sinit12);
    ಬರೆ("sinit13=%d %s %s %s\n",
           ಗಾತ್ರ(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    ಬರೆ("sinit14=%s\n", sinit14);

    ಗಾಗಿ(i=0;i<10;i++) ಬರೆ(" %d", linit12[i]);
    ಬರೆ("\n");
    ಗಾಗಿ(i=0;i<10;i++) ಬರೆ(" %d", linit13[i]);
    ಬರೆ("\n");
    ಗಾಗಿ(i=0;i<10;i++) ಬರೆ(" %d", linit14[i]);
    ಬರೆ("\n");
    ಗಾಗಿ(i=0;i<10;i++) ಬರೆ(" %d", linit15[i]);
    ಬರೆ("\n");
    ಬರೆ("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    ಬರೆ("linit17=%d\n", linit17);
    ಬರೆ("sinit15=%d\n", sinit15[0]);
    ಬರೆ("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    ಬರೆ("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    ಗಾಗಿ(i=0;i<10;i++)
        ಬರೆ("%x ", sinit18[i]);
    ಬರೆ("\n");
    /* complex init check */
    ಬರೆ("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    ಬರೆ("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    ಬರೆ("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", ಗಾತ್ರ cix20, ಗಾತ್ರ cix21, ಗಾತ್ರ cix22);

    ಬರೆ("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    ಬರೆ("arrtype2: %d %d\n", ಗಾತ್ರ(sinit19), ಗಾತ್ರ(sinit20));
    ಬರೆ("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    ಬರೆ("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    ಬರೆ("arrtype5: %d %d\n", ಗಾತ್ರ(sinit21), ಗಾತ್ರ(sinit22));
    ಬರೆ("arrtype6: %d\n", ಗಾತ್ರ(arrtype2));

    ಬರೆ("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    ಬರೆ("sinit24=%d\n", sinit24);
    ಬರೆ("linit18= %d %d\n", linit18[0], linit18[1]);
    ಬರೆ ("bf1: %u %u\n", bf_init.ಬಿಟ್, bf_init.bits31);
    ಬರೆ ("bf2: %u %u\n", bf_finit.ಬಿಟ್, bf_finit.bits31);
    ಬರೆ ("bf3: %u %u\n", bfn_init.c.ಬಿಟ್, bfn_init.c.bits31);
    ಬರೆ ("bf4: %u %u\n", bfn_finit.c.ಬಿಟ್, bfn_finit.c.bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf5[%d]: %u %u\n", i, bfa_init.c[i].ಬಿಟ್, bfa_init.c[i].bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].ಬಿಟ್, bfa_finit.c[i].bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf7[%d]: %u %u\n", i, bfaa_init[i].ಬಿಟ್, bfaa_init[i].bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf8[%d]: %u %u\n", i, bfaa_finit[i].ಬಿಟ್, bfaa_finit[i].bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].ಬಿಟ್, bfaa_vinit[i].bits31);
    ಗಾಗಿ (i = 0; i < 3; i++)
        ಬರೆ ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].ಬಿಟ್, bfaa_fvinit[i].bits31);
}

ಶೂನ್ಯ switch_uc(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uc)
{
	ಆಯ್ಕೆ (uc) {
	    ಸ್ಥಿತಿ 0xfb ... 0xfe:
		ಬರೆ("ucsw:1\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 0xff:
		ಬರೆ("ucsw:2\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 0 ... 5:
		ಬರೆ("ucsw:3\n");
		ನಿಲ್ಲಿಸು;
	    ಪೂರ್ವನಿಯೋಜಿತ:
		ಬರೆ("ucsw: broken!\n");
	}
}

ಶೂನ್ಯ switch_sc(ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ sc)
{
	ಆಯ್ಕೆ (sc) {
	    ಸ್ಥಿತಿ -5 ... -2:
		ಬರೆ("scsw:1\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ -1:
		ಬರೆ("scsw:2\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 0 ... 5:
		ಬರೆ("scsw:3\n");
		ನಿಲ್ಲಿಸು;
	    ಪೂರ್ವನಿಯೋಜಿತ:
		ಬರೆ("scsw: broken!\n");
	}
}

ಶೂನ್ಯ switch_test()
{
    ಪೂರ್ಣಾಂಕ i;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ull;
    ದೀರ್ಘ ದೀರ್ಘ ll;

    ಗಾಗಿ(i=0;i<15;i++) {
        ಆಯ್ಕೆ(i) {
        ಸ್ಥಿತಿ 0:
        ಸ್ಥಿತಿ 1:
            ಬರೆ("a");
            ನಿಲ್ಲಿಸು;
        ಪೂರ್ವನಿಯೋಜಿತ:
            ಬರೆ("%d", i);
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 8 ... 12:
            ಬರೆ("c");
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 3:
            ಬರೆ("b");
            ನಿಲ್ಲಿಸು;
        ಸ್ಥಿತಿ 0xc33c6b9fU:
        ಸ್ಥಿತಿ 0x7c9eeeb9U:
            ನಿಲ್ಲಿಸು;
        }
    }
    ಬರೆ("\n");

    ಗಾಗಿ (i = 1; i <= 5; i++) {
	ull = (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)i << 61;
	ಆಯ್ಕೆ (ull) {
	    ಸ್ಥಿತಿ 1ULL << 61:
		ಬರೆ("ullsw:1\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 2ULL << 61:
		ಬರೆ("ullsw:2\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 3ULL << 61:
		ಬರೆ("ullsw:3\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 4ULL << 61:
		ಬರೆ("ullsw:4\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 5ULL << 61:
		ಬರೆ("ullsw:5\n");
		ನಿಲ್ಲಿಸು;
	    ಪೂರ್ವನಿಯೋಜಿತ:
		ಬರೆ("ullsw: broken!\n");
	}
    }

    ಗಾಗಿ (i = 1; i <= 5; i++) {
	ll = (ದೀರ್ಘ ದೀರ್ಘ)i << 61;
	ಆಯ್ಕೆ (ll) {
	    ಸ್ಥಿತಿ 1LL << 61:
		ಬರೆ("llsw:1\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 2LL << 61:
		ಬರೆ("llsw:2\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 3LL << 61:
		ಬರೆ("llsw:3\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 4LL << 61:
		ಬರೆ("llsw:4\n");
		ನಿಲ್ಲಿಸು;
	    ಸ್ಥಿತಿ 5LL << 61:
		ಬರೆ("llsw:5\n");
		ನಿಲ್ಲಿಸು;
	    ಪೂರ್ವನಿಯೋಜಿತ:
		ಬರೆ("llsw: broken!\n");
	}
    }

    ಗಾಗಿ (i = -5; i <= 5; i++) {
	switch_uc((ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ)i);
    }

    ಗಾಗಿ (i = -5; i <= 5; i++) {
	switch_sc ((ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ)i);
    }
}

/* ISOC99 _Bool type */
ಶೂನ್ಯ c99_bool_test(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BOOL_ISOC99
    ಪೂರ್ಣಾಂಕ a;
    _Bool b, b2;

    ಬರೆ("sizeof(_Bool) = %d\n", ಗಾತ್ರ(_Bool));
    a = 3;
    ಬರೆ("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    ಬರೆ("b = %d\n", b);
    b++;
    ಬರೆ("b = %d\n", b);
    b2 = 0;
    ಬರೆ("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           ಗಾತ್ರ ((ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ)a ? b : b2));
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ bitfield_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a;
    ಗಿಡ್ಡ sa;
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ca;
    ರಚನೆ sbf1 {
        ಪೂರ್ಣಾಂಕ f1 : 3;
        ಪೂರ್ಣಾಂಕ : 2;
        ಪೂರ್ಣಾಂಕ f2 : 1;
        ಪೂರ್ಣಾಂಕ : 0;
        ಪೂರ್ಣಾಂಕ f3 : 5;
        ಪೂರ್ಣಾಂಕ f4 : 7;
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ f5 : 7;
    } st1;
    ಬರೆ("sizeof(st1) = %d\n", ಗಾತ್ರ(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    ಬರೆ("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    ಬರೆ("%d %d\n", sa, ca);

    st1.f1 = 7;
    ಆದರೆ (st1.f1 == -1) 
        ಬರೆ("st1.f1 == -1\n");
    ಇಲ್ಲದಿದ್ದರೆ 
        ಬರೆ("st1.f1 != -1\n");
    ಆದರೆ (st1.f2 == -1) 
        ಬರೆ("st1.f2 == -1\n");
    ಇಲ್ಲದಿದ್ದರೆ 
        ಬರೆ("st1.f2 != -1\n");

    ರಚನೆ sbf2 {
        ದೀರ್ಘ ದೀರ್ಘ f1 : 45;
        ದೀರ್ಘ ದೀರ್ಘ : 2;
        ದೀರ್ಘ ದೀರ್ಘ f2 : 35;
        ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (ದೀರ್ಘ ದೀರ್ಘ)a << 25;
    st2.f3 = a;
    st2.f2++;
    ಬರೆ("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#ಆದರೆ 0
    Disabled ಗಾಗಿ now until further clarification re GCC compatibility
    ರಚನೆ sbf3 {
        ಪೂರ್ಣಾಂಕ f1 : 7;
        ಪೂರ್ಣಾಂಕ f2 : 1;
        ಅಕ್ಷರ f3;
        ಪೂರ್ಣಾಂಕ f4 : 8;
        ಪೂರ್ಣಾಂಕ f5 : 1;
        ಪೂರ್ಣಾಂಕ f6 : 16;
    } st3;
    ಬರೆ("sizeof(st3) = %d\n", ಗಾತ್ರ(st3));
#ಆದರೆ_ಅಂತ್ಯ

    ರಚನೆ sbf4 {
	ಪೂರ್ಣಾಂಕ x : 31;
	ಅಕ್ಷರ y : 2;
    } st4;
    st4.y = 1;
    ಬರೆ("st4.y == %d\n", st4.y);
    ರಚನೆ sbf5 {
	ಪೂರ್ಣಾಂಕ a;
	ಅಕ್ಷರ b;
	ಪೂರ್ಣಾಂಕ x : 12, y : 4, : 0, : 4, z : 3;
	ಅಕ್ಷರ c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    ಬರೆ("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ರಚನೆ sbf6 {
	ಗಿಡ್ಡ x : 12;
	ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ y : 2;
    } st6;
    st6.y = 1;
    ಬರೆ("st6.y == %d\n", st6.y);
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64__
#ವ್ಯಾಖ್ಯಾನಿಸು FLOAT_FMT "%f\n"
#ಇಲ್ಲದಿದ್ದರೆ
/* x86's float isn't compatible with GCC */
#ವ್ಯಾಖ್ಯಾನಿಸು FLOAT_FMT "%.5f\n"
#ಆದರೆ_ಅಂತ್ಯ

/* declare strto* functions as they are C99 */
ದ್ವಿಗುಣ strtod(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr);

#ಆದರೆ defined(_WIN32)
ದಶಮಾಂಶ strtof(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr) {ಹಿಂತಿರುಗಿ (ದಶಮಾಂಶ)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr) {ಹಿಂತಿರುಗಿ (LONG_DOUBLE)strtod(nptr, endptr);}
#ಇಲ್ಲದಿದ್ದರೆ
ದಶಮಾಂಶ strtof(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr);
LONG_DOUBLE strtold(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nptr, ಅಕ್ಷರ **endptr);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು FTEST(ಪೂರ್ವಪ್ರತ್ಯಯ, typename, type, fmt)\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## cmp(type a, type b)\
{\
    ಬರೆ("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    ಬರೆ(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    ಬರೆ(fmt "\n", ++a);\
    ಬರೆ(fmt "\n", a++);\
    ಬರೆ(fmt "\n", a);\
    b = 0;\
    ಬರೆ("%d %d\n", !a, !b);\
}\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## fcast(type a)\
{\
    ದಶಮಾಂಶ fa;\
    ದ್ವಿಗುಣ da;\
    LONG_DOUBLE la;\
    ಪೂರ್ಣಾಂಕ ia;\
    ದೀರ್ಘ ದೀರ್ಘ llia;\
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ua;\
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    ಬರೆ("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (ಪೂರ್ಣಾಂಕ)a;\
    llia = (ದೀರ್ಘ ದೀರ್ಘ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ)a;\
    llua = (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)a;\
    ಬರೆ("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    ಬರೆ("itof: " fmt "\n", b);\
    b = ua;\
    ಬರೆ("utof: " fmt "\n", b);\
    b = llia;\
    ಬರೆ("lltof: " fmt "\n", b);\
    b = llua;\
    ಆದರೆ (CC_NAME != CC_clang) ಬರೆ("ulltof: " fmt "\n", b);\
}\
\
ದಶಮಾಂಶ ಪೂರ್ವಪ್ರತ್ಯಯ ## retf(type a) { ಹಿಂತಿರುಗಿ a; }\
ದ್ವಿಗುಣ ಪೂರ್ವಪ್ರತ್ಯಯ ## retd(type a) { ಹಿಂತಿರುಗಿ a; }\
LONG_DOUBLE ಪೂರ್ವಪ್ರತ್ಯಯ ## retld(type a) { ಹಿಂತಿರುಗಿ a; }\
\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## call(ಶೂನ್ಯ)\
{\
    ಬರೆ("float: " FLOAT_FMT, ಪೂರ್ವಪ್ರತ್ಯಯ ## retf(42.123456789));\
    ಬರೆ("double: %f\n", ಪೂರ್ವಪ್ರತ್ಯಯ ## retd(42.123456789));\
    ಬರೆ("long double: %Lf\n", ಪೂರ್ವಪ್ರತ್ಯಯ ## retld(42.123456789));\
    ಬರೆ("strto%s: %f\n", #prefix, (ದ್ವಿಗುಣ)strto ## ಪೂರ್ವಪ್ರತ್ಯಯ("1.2", ಖಾಲಿ));\
}\
\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## signed_zeros(ಶೂನ್ಯ) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ಆದರೆ (x == y)\
    ಬರೆ ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ಇಲ್ಲದಿದ್ದರೆ\
    ಬರೆ ("x != y; this is wrong!\n");\
\
  n = -x;\
  ಆದರೆ (x == n)\
    ಬರೆ ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ಇಲ್ಲದಿದ್ದರೆ\
    ಬರೆ ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ಆದರೆ (x == p)\
    ಬರೆ ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ಇಲ್ಲದಿದ್ದರೆ\
    ಬರೆ ("x != +y; this is wrong!\n");\
  p = -y;\
  ಆದರೆ (x == p)\
    ಬರೆ ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ಇಲ್ಲದಿದ್ದರೆ\
    ಬರೆ ("x != -y; this is wrong!\n");\
}\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## nan(ಶೂನ್ಯ)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    ಬರೆ("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
ಶೂನ್ಯ ಪೂರ್ವಪ್ರತ್ಯಯ ## test(ಶೂನ್ಯ)\
{\
    ಬರೆ("testing '%s'\n", #typename);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## cmp(1, 2.5);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## cmp(2, 1.5);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## cmp(1, 1);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## fcast(234.6);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## fcast(-2334.6);\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## call();\
    ಪೂರ್ವಪ್ರತ್ಯಯ ## signed_zeros();\
    ಆದರೆ (CC_NAME != CC_clang) ಪೂರ್ವಪ್ರತ್ಯಯ ## nan();\
}

FTEST(f, ದಶಮಾಂಶ, ದಶಮಾಂಶ, "%f")
FTEST(d, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, "%f")
FTEST(ld, ದೀರ್ಘ ದ್ವಿಗುಣ, LONG_DOUBLE, "%Lf")

ದ್ವಿಗುಣ ftab1[3] = { 1.2, 3.4, -5.6 };


ಶೂನ್ಯ float_test(ಶೂನ್ಯ)
{
#ಆದರೆ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    ಅಸ್ಥಿರ ದಶಮಾಂಶ fa, fb;
    ಅಸ್ಥಿರ ದ್ವಿಗುಣ da, db;
    ಪೂರ್ಣಾಂಕ a;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ b;
    ಸ್ಥಿರ ದ್ವಿಗುಣ nan2 = 0.0/0.0;
    ಸ್ಥಿರ ದ್ವಿಗುಣ inf1 = 1.0/0.0;
    ಸ್ಥಿರ ದ್ವಿಗುಣ inf2 = 1e5000;
    ಅಸ್ಥಿರ LONG_DOUBLE la;

    ಬರೆ("sizeof(float) = %d\n", ಗಾತ್ರ(ದಶಮಾಂಶ));
    ಬರೆ("sizeof(double) = %d\n", ಗಾತ್ರ(ದ್ವಿಗುಣ));
    ಬರೆ("sizeof(long double) = %d\n", ಗಾತ್ರ(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    ಬರೆ("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    ಬರೆ("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    ಬರೆ("da=%f\n", da);
    fa = 123;
    ಬರೆ("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    ಬರೆ("da = %f\n", da);
    b = 4000000000;
    db = b;
    ಬರೆ("db = %f\n", db);
    ಬರೆ("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    ಬರೆ ("da subnormal = %a\n", da);
    ಬರೆ ("da subnormal = %.40g\n", da);
    ಬರೆ ("la subnormal = %La\n", la);
    ಬರೆ ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    ಬರೆ ("da/2 subnormal = %a\n", da);
    ಬರೆ ("da/2 subnormal = %.40g\n", da);
    ಬರೆ ("la/2 subnormal = %La\n", la);
    ಬರೆ ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    ಬರೆ ("fa subnormal = %a\n", fa);
    ಬರೆ ("fa subnormal = %.40g\n", fa);
    ಬರೆ ("la subnormal = %La\n", la);
    ಬರೆ ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    ಬರೆ ("fa/2 subnormal = %a\n", fa);
    ಬರೆ ("fa/2 subnormal = %.40g\n", fa);
    ಬರೆ ("la/2 subnormal = %La\n", la);
    ಬರೆ ("la/2 subnormal = %.40Lg\n", la);
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ fib(ಪೂರ್ಣಾಂಕ n)
{
    ಆದರೆ (n <= 2)
        ಹಿಂತಿರುಗಿ 1;
    ಇಲ್ಲದಿದ್ದರೆ
        ಹಿಂತಿರುಗಿ fib(n-1) + fib(n-2);
}

#ಆದರೆ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ಇಲ್ಲದಿದ್ದರೆ
ಶೂನ್ಯ __attribute__((aligned(16))) aligned_function(ಪೂರ್ಣಾಂಕ i) {}
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ funcptr_test()
{
    ಶೂನ್ಯ (*func)(ಪೂರ್ಣಾಂಕ);
    ಪೂರ್ಣಾಂಕ a;
    ರಚನೆ {
        ಪೂರ್ಣಾಂಕ dummy;
        ಶೂನ್ಯ (*func)(ಪೂರ್ಣಾಂಕ);
    } st1;
    ದೀರ್ಘ diff;

    func = &ಅಂಕೆ;
    (*func)(12345);
    func = ಅಂಕೆ;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = ಅಂಕೆ;
    st1.func(12346);
    ಬರೆ("sizeof1 = %d\n", ಗಾತ್ರ(funcptr_test));
    ಬರೆ("sizeof2 = %d\n", ಗಾತ್ರ funcptr_test);
    ಬರೆ("sizeof3 = %d\n", ಗಾತ್ರ(&funcptr_test));
    ಬರೆ("sizeof4 = %d\n", ಗಾತ್ರ &funcptr_test);
    a = 0;
    func = ಅಂಕೆ + a;
    diff = func - ಅಂಕೆ;
    func(42);
    (func + diff)(42);
    (ಅಂಕೆ + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    ಬರೆ("aligned_function (should be zero): %d\n", ((ಪೂರ್ಣಾಂಕ)(uintptr_t)func) & 15);
}

ಶೂನ್ಯ lloptest(ದೀರ್ಘ ದೀರ್ಘ a, ದೀರ್ಘ ದೀರ್ಘ b)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    ಬರೆ("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ಆದರೆ (b != 0) {
        ಬರೆ("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ದ್ವಿಮಾನ*/
    ಬರೆ("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    ಬರೆ("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    ಬರೆ("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    ಬರೆ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    ಬರೆ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    ಬರೆ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    ಬರೆ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    ಬರೆ("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

ಶೂನ್ಯ llshift(ದೀರ್ಘ ದೀರ್ಘ a, ಪೂರ್ಣಾಂಕ b)
{
    ಬರೆ("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)a >> b,
           a >> b,
           a << b);
    ಬರೆ("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)a >> 3,
           a >> 3,
           a << 3);
    ಬರೆ("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)a >> 35,
           a >> 35,
           a << 35);
}

ಶೂನ್ಯ llfloat(ಶೂನ್ಯ)
{
    ದಶಮಾಂಶ fa;
    ದ್ವಿಗುಣ da;
    LONG_DOUBLE lda;
    ದೀರ್ಘ ದೀರ್ಘ la, lb, lc;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    ಬರೆ("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    ಬರೆ("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    ಬರೆ("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    ಬರೆ("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    ಬರೆ("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

ದೀರ್ಘ ದೀರ್ಘ llfunc1(ಪೂರ್ಣಾಂಕ a)
{
    ಹಿಂತಿರುಗಿ a * 2;
}

ರಚನೆ S {
    ಪೂರ್ಣಾಂಕ id; 
    ಅಕ್ಷರ ಅಂಶ;
};

ದೀರ್ಘ ದೀರ್ಘ ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ(ರಚನೆ S *v)
{
    ಹಿಂತಿರುಗಿ ((ದೀರ್ಘ ದೀರ್ಘ ಪೂರ್ಣಾಂಕ)v->ಅಂಶ);
}

ದೀರ್ಘ ದೀರ್ಘ llfunc2(ದೀರ್ಘ ದೀರ್ಘ x, ದೀರ್ಘ ದೀರ್ಘ y, ಪೂರ್ಣಾಂಕ z)
{
    ಹಿಂತಿರುಗಿ x * y * z;
}

ಶೂನ್ಯ check_opl_save_regs(ಅಕ್ಷರ *a, ದೀರ್ಘ ದೀರ್ಘ b, ಪೂರ್ಣಾಂಕ c)
{
    *a = b < 0 && !c;
}

ಶೂನ್ಯ longlong_test(ಶೂನ್ಯ)
{
    ದೀರ್ಘ ದೀರ್ಘ a, b, c;
    ಪೂರ್ಣಾಂಕ ia;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ua;
    ಬರೆ("sizeof(long long) = %d\n", ಗಾತ್ರ(ದೀರ್ಘ ದೀರ್ಘ));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    ಬರೆ(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    ಬರೆ(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (ದೀರ್ಘ ದೀರ್ಘ)1,
           (ದೀರ್ಘ ದೀರ್ಘ)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    ಬರೆ(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#ಆದರೆ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    ಬರೆ(XLONG_LONG_FORMAT"\n", c);
#ಆದರೆ_ಅಂತ್ಯ

    /* long long reg spill test */
    {
          ರಚನೆ S a;

          a.ಅಂಶ = 3;
          ಬರೆ("%lld\n", ಮೌಲ್ಯ(&a));
    }
    lloptest(0x80000000, 0);

    {
        ದೀರ್ಘ ದೀರ್ಘ *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        ಬರೆ("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        ಬರೆ("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    ಬರೆ("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    ಬರೆ(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    ದೀರ್ಘ ದೀರ್ಘ *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ u = 0x8000000000000001ULL;
    u = (ಚಿಹ್ನೆರಹಿತ)(u + 1);
    ಬರೆ("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (ಚಿಹ್ನೆರಹಿತ)(ಪೂರ್ಣಾಂಕ)(u + 1);
    ಬರೆ("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    ಅಕ್ಷರ cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    ಬರೆ("check_opl_save_regs: %d\n", cc);
}

ಶೂನ್ಯ manyarg_test(ಶೂನ್ಯ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ಬರೆ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    ಬರೆ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    ಬರೆ("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    ಬರೆ("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    ಬರೆ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    ಬರೆ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

ಶೂನ್ಯ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ರಚನೆ X { ಪೂರ್ಣಾಂಕ _x; };
        ರಚನೆ X *x = va_arg(ap, ರಚನೆ X *);
        ಹಿಂತಿರುಗಿ x;
}

ಶೂನ್ಯ vprintf1(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ap, aq;
    ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *p;
    ಪೂರ್ಣಾಂಕ c, i;
    ದ್ವಿಗುಣ d;
    ದೀರ್ಘ ದೀರ್ಘ ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    ಗಾಗಿ(;;) {
        c = *p;
        ಆದರೆ (c == '\0')
            ನಿಲ್ಲಿಸು;
        p++;
        ಆದರೆ (c == '%') {
            c = *p;
            ಆಯ್ಕೆ(c) {
            ಸ್ಥಿತಿ '\0':
                ಹೋಗು the_ಕೊನೆ;
            ಸ್ಥಿತಿ 'd':
                i = va_arg(ap, ಪೂರ್ಣಾಂಕ);
                ಬರೆ("%d", i);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'f':
                d = va_arg(ap, ದ್ವಿಗುಣ);
                ಬರೆ("%f", d);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'l':
                ll = va_arg(ap, ದೀರ್ಘ ದೀರ್ಘ);
                ಬರೆ(LONG_LONG_FORMAT, ll);
                ನಿಲ್ಲಿಸು;
            ಸ್ಥಿತಿ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                ಬರೆ("%Lf", ld);
                ನಿಲ್ಲಿಸು;
            }
            p++;
        } ಇಲ್ಲದಿದ್ದರೆ {
            ಅಕ್ಷರ_ಬರೆ(c);
        }
    }
 the_ಕೊನೆ:
    va_end(aq);
    va_end(ap);
}

ರಚನೆ myspace {
    ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ profile;
};
ರಚನೆ myspace2 {
#ಆದರೆ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    ಅಕ್ಷರ a[1];
#ಇಲ್ಲದಿದ್ದರೆ
    ಅಕ್ಷರ a[0];
#ಆದರೆ_ಅಂತ್ಯ
};
ರಚನೆ myspace3 {
    ಅಕ್ಷರ a[1];
};
ರಚನೆ myspace4 {
    ಅಕ್ಷರ a[2];
};
ರಚನೆ mytest {
    ಶೂನ್ಯ *foo, *bar, *baz;
};

ರಚನೆ mytest stdarg_for_struct(ರಚನೆ myspace bob, ...)
{
    ರಚನೆ myspace george, bill;
    ರಚನೆ myspace2 alex1;
    ರಚನೆ myspace3 alex2;
    ರಚನೆ myspace4 alex3;
    va_list ap;
    ಗಿಡ್ಡ ಪೂರ್ಣಾಂಕ validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ರಚನೆ myspace2);
    alex2    = va_arg(ap, ರಚನೆ myspace3);
    alex3    = va_arg(ap, ರಚನೆ myspace4);
    bill     = va_arg(ap, ರಚನೆ myspace);
    george   = va_arg(ap, ರಚನೆ myspace);
    validate = va_arg(ap, ಪೂರ್ಣಾಂಕ);
    ಬರೆ("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ಹಿಂತಿರುಗಿ (ರಚನೆ mytest) {};
}

ಶೂನ್ಯ stdarg_for_libc(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *fmt, ...)
{
    va_list ವಾದಗಳು;
    va_start(ವಾದಗಳು, fmt);
    vprintf(fmt, ವಾದಗಳು);
    va_end(ವಾದಗಳು);
}

ಶೂನ್ಯ stdarg_syntax(ಪೂರ್ಣಾಂಕ n, ...)
{
    ಪೂರ್ಣಾಂಕ i;
    va_list ap;
    ಆದರೆ (1)
      va_start(ap, n);
    ಇಲ್ಲದಿದ್ದರೆ
      ;
    i = va_arg(ap, ಪೂರ್ಣಾಂಕ);
    ಬರೆ("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ{
    ದ್ವಿಗುಣ x,y;
} ಬಿಂದು;
ಬಿಂದು pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ಸ್ಥಿರ ಶೂನ್ಯ stdarg_double_struct(ಪೂರ್ಣಾಂಕ nargs, ಪೂರ್ಣಾಂಕ posd,...)
{
    ಪೂರ್ಣಾಂಕ i;
    ದ್ವಿಗುಣ d;
    ಬಿಂದು pi;
    va_list ವಾದಗಳು;

    ಬರೆ ("stdarg_double_struct: %d\n", posd);
    va_start(ವಾದಗಳು,posd);
    ಗಾಗಿ(i = 0; i < nargs; i++) {
        ಆದರೆ (i == posd) {
            d = va_arg (ವಾದಗಳು, ದ್ವಿಗುಣ);
            ಬರೆ ("d %d = %g\n", i, d);
        }
        ಇಲ್ಲದಿದ್ದರೆ {
            pi = va_arg (ವಾದಗಳು, ಬಿಂದು);
            ಬರೆ ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(ವಾದಗಳು);
}

ಶೂನ್ಯ stdarg_test(ಶೂನ್ಯ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ರಚನೆ myspace bob;
    ರಚನೆ myspace2 bob2;
    ರಚನೆ myspace3 bob3;
    ರಚನೆ myspace4 bob4;

    vprintf1("%d %d %d\n", 1, 2, 3);
    vprintf1("%f %d %f\n", 1.0, 2, 3.0);
    vprintf1("%l %l %d %f\n", 1234567891234LL, 987654321986LL, 3, 1234.0);
    vprintf1("%F %F %F\n", LONG_DOUBLE_LITERAL(1.2), LONG_DOUBLE_LITERAL(2.3), LONG_DOUBLE_LITERAL(3.4));
    vprintf1("%d %f %l %F %d %f %l %F\n",
             1, 1.2, 3LL, LONG_DOUBLE_LITERAL(4.5), 6, 7.8, 9LL, LONG_DOUBLE_LITERAL(0.1));
    vprintf1("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f\n",
             1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8);
    vprintf1("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
             1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    vprintf1("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
             "%l %l %f %f\n",
             1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
             1234567891234LL, 987654321986LL,
             42.0, 43.0);
    vprintf1("%F %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
             "%l %l %f %f\n",
             ld, 1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
             1234567891234LL, 987654321986LL,
             42.0, 43.0);
    vprintf1("%d %d %d %d %d %d %d %d %F\n",
             1, 2, 3, 4, 5, 6, 7, 8, ld);
    vprintf1("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
             "%l %l %f %f %F\n",
             1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
             1234567891234LL, 987654321986LL,
             42.0, 43.0, ld);
    vprintf1("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
             "%F %l %l %f %f %F\n",
             1, 2, 3, 4, 5, 6, 7, 8,
             0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
             ld, 1234567891234LL, 987654321986LL,
             42.0, 43.0, ld);

    bob.profile = 42;
    bob3.a[0] = 1;
    bob4.a[0] = 2;
    bob4.a[1] = 3;
    stdarg_for_struct(bob, bob2, bob3, bob4, bob, bob, bob.profile);
    stdarg_for_libc("stdarg_for_libc: %s %.2f %d\n", "string", 1.23, 456);
    stdarg_syntax(1, 17);
#ಆದರೆ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ reltab[3] = { 1, 2, 3 };

ಪೂರ್ಣಾಂಕ *rel1 = &reltab[1];
ಪೂರ್ಣಾಂಕ *rel2 = &reltab[2];

ಶೂನ್ಯ getmyaddress(ಶೂನ್ಯ)
{
    ಬರೆ("in getmyaddress\n");
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __LP64__
ದೀರ್ಘ __pa_symbol(ಶೂನ್ಯ)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ಹಿಂತಿರುಗಿ ((ದೀರ್ಘ)(((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)(&rel1))) - (0xffffffff80000000UL));
}
#ಆದರೆ_ಅಂತ್ಯ

uintptr_t theaddress = (uintptr_t)getmyaddress;
ಶೂನ್ಯ relocation_test(ಶೂನ್ಯ)
{
    ಶೂನ್ಯ (*fptr)(ಶೂನ್ಯ) = (ಶೂನ್ಯ (*)(ಶೂನ್ಯ))theaddress;
    ಬರೆ("*rel1=%d\n", *rel1);
    ಬರೆ("*rel2=%d\n", *rel2);
    fptr();
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    ಬರೆ("pa_symbol: %d\n", (ದೀರ್ಘ)&rel1 == __pa_symbol() - 0x80000000);
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ old_style_f(a,b,c)
     ಪೂರ್ಣಾಂಕ a, b;
     ದ್ವಿಗುಣ c;
{
    ಬರೆ("a=%d b=%d b=%f\n", a, b, c);
}

ಶೂನ್ಯ decl_func1(ಪೂರ್ಣಾಂಕ cmpfn())
{
    ಬರೆ("cmpfn=%lx\n", (ದೀರ್ಘ)cmpfn);
}

ಶೂನ್ಯ decl_func2(cmpfn)
ಪೂರ್ಣಾಂಕ cmpfn();
{
    ಬರೆ("cmpfn=%lx\n", (ದೀರ್ಘ)cmpfn);
}

ಶೂನ್ಯ old_style_function_test(ಶೂನ್ಯ)
{
#ಆದರೆ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ಇಲ್ಲದಿದ್ದರೆ
    old_style_f((ಶೂನ್ಯ *)1, 2, 3.0);
#ಆದರೆ_ಅಂತ್ಯ
    decl_func1(ಖಾಲಿ);
    decl_func2(ಖಾಲಿ);
}

ಶೂನ್ಯ alloca_test()
{
    ಅಕ್ಷರ *p = alloca(16);
    strcpy(p,"123456789012345");
    ಬರೆ("alloca: p is %s\n", p);
    ಅಕ್ಷರ *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    ಬರೆ("alloca: %s\n", strcpy(alloca(ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(demo)+1),demo) );
}

ಶೂನ್ಯ *bounds_checking_is_enabled()
{
    ಅಕ್ಷರ ca[10], *cp = ca-1;
    ಹಿಂತಿರುಗಿ (ca != cp + 1) ? cp : ಖಾಲಿ;
}

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ constant_negative_array_ಗಾತ್ರ_as_compile_ಸಮಯ_assertion_idiom[(1 ? 2 : 0) - 1];

ಶೂನ್ಯ c99_vla_test_1(ಪೂರ್ಣಾಂಕ size1, ಪೂರ್ಣಾಂಕ size2)
{
    ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 = size1 * size2;
    ಪೂರ್ಣಾಂಕ tab1[ಗಾತ್ರ_2][2], tab2[10][2];
    ಶೂನ್ಯ *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    ಗಾತ್ರ_2 = ಗಾತ್ರ_2-1;
    
    ಬರೆ("Test C99 VLA 1 (sizeof): ");
    ಬರೆ("%s\n", (ಗಾತ್ರ tab1 == size1 * size2 * 2 * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    ಬರೆ("Test C99 VLA 2 (ptrs subtract): ");
    ಬರೆ("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ) * 2)) ? "PASSED" : "FAILED");
    ಬರೆ("Test C99 VLA 3 (ptr add): ");
    ಬರೆ("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ)) ? "PASSED" : "FAILED");
    ಬರೆ("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    ಬರೆ("%s\n", (*((ಪೂರ್ಣಾಂಕ *) (tab1_ptr + (size1 * 2 + 1) * ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ))) == 42) ? "PASSED" : "FAILED");

    ಬರೆ("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ಆದರೆ (bad_ptr = bounds_checking_is_enabled()) {
        ಪೂರ್ಣಾಂಕ *t1 = &tab1[size1 * size2 - 1][3];
        ಪೂರ್ಣಾಂಕ *t2 = &tab2[9][3];
        ಬರೆ("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        ಬರೆ("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        ಅಕ್ಷರ*c1 = 1 + ಗಾತ್ರ(tab1) + (ಅಕ್ಷರ*)tab1;
        ಅಕ್ಷರ*c2 = 1 + ಗಾತ್ರ(tab2) + (ಅಕ್ಷರ*)tab2;
        ಬರೆ("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        ಬರೆ("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        ಪೂರ್ಣಾಂಕ *i1 = tab1[-1];
        ಪೂರ್ಣಾಂಕ *i2 = tab2[-1];
        ಬರೆ("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        ಬರೆ("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        ಪೂರ್ಣಾಂಕ *x1 = tab1[size1 * size2 + 1];
        ಪೂರ್ಣಾಂಕ *x2 = tab2[10 + 1];
        ಬರೆ("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        ಬರೆ("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ಇಲ್ಲದಿದ್ದರೆ {
        ಬರೆ("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    ಬರೆ("\n");
}

ಶೂನ್ಯ c99_vla_test_2(ಪೂರ್ಣಾಂಕ d, ಪೂರ್ಣಾಂಕ h, ಪೂರ್ಣಾಂಕ w)
{
    ಪೂರ್ಣಾಂಕ x, y, z;
    ಪೂರ್ಣಾಂಕ (*arr)[h][w] = ಸ್ಮರಣೆ_ಕೊಡು(ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ) * d*h*w);
    ಪೂರ್ಣಾಂಕ c = 1;
    ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*starr)[h][w];

    ಬರೆ("Test C99 VLA 6 (pointer)\n");

    ಗಾಗಿ (z=0; z<d; z++) {
        ಗಾಗಿ (y=0; y<h; y++) {
            ಗಾಗಿ (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    ಗಾಗಿ (z=0; z<d; z++) {
        ಗಾಗಿ (y=0; y<h; y++) {
            ಗಾಗಿ (x=0; x<w; x++) {
                ಬರೆ(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    ಬರೆ(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        ಗಾತ್ರ (*arr), ಗಾತ್ರ (*arr)[0], ಗಾತ್ರ (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == ಗಾತ್ರ (*arr + 1) - ಗಾತ್ರ arr,
        0 == ಗಾತ್ರ ಗಾತ್ರ *arr - ಗಾತ್ರ arr,
        starr[0][2][3] == arr[1][2][3]
        );
    ಬಿಡುಗಡೆ (arr);
}

ಶೂನ್ಯ c99_vla_test_3a (ಪೂರ್ಣಾಂಕ arr[2][3][4])
{
    ಬರೆ ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3b(ಪೂರ್ಣಾಂಕ s, ಪೂರ್ಣಾಂಕ arr[s][3][4])
{
    ಬರೆ ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3c(ಪೂರ್ಣಾಂಕ s, ಪೂರ್ಣಾಂಕ arr[2][s][4])
{
    ಬರೆ ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3d(ಪೂರ್ಣಾಂಕ s, ಪೂರ್ಣಾಂಕ arr[2][3][s])
{
    ಬರೆ ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3e(ಪೂರ್ಣಾಂಕ s, ಪೂರ್ಣಾಂಕ arr[][3][--s])
{
    ಬರೆ ("%d %d %d\n", ಗಾತ್ರ arr, s, arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a[2][3][4];

    memset (a, 0, ಗಾತ್ರ(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

ಶೂನ್ಯ c99_vla_test(ಶೂನ್ಯ)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


ಶೂನ್ಯ sizeof_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a;
    ಪೂರ್ಣಾಂಕ **ptr;

    ಬರೆ("sizeof(int) = %d\n", ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ));
    ಬರೆ("sizeof(unsigned int) = %d\n", ಗಾತ್ರ(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ));
    ಬರೆ("sizeof(long) = %d\n", ಗಾತ್ರ(ದೀರ್ಘ));
    ಬರೆ("sizeof(unsigned long) = %d\n", ಗಾತ್ರ(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ));
    ಬರೆ("sizeof(short) = %d\n", ಗಾತ್ರ(ಗಿಡ್ಡ));
    ಬರೆ("sizeof(unsigned short) = %d\n", ಗಾತ್ರ(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ));
    ಬರೆ("sizeof(char) = %d\n", ಗಾತ್ರ(ಅಕ್ಷರ));
    ಬರೆ("sizeof(unsigned char) = %d\n", ಗಾತ್ರ(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ));
    ಬರೆ("sizeof(func) = %d\n", ಗಾತ್ರ sizeof_test());
    a = 1;
    ಬರೆ("sizeof(a++) = %d\n", ಗಾತ್ರ a++);
    ಬರೆ("a=%d\n", a);
    ptr = ಖಾಲಿ;
    ಬರೆ("sizeof(**ptr) = %d\n", ಗಾತ್ರ (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    ಬರೆ("sizeof(sizeof(int) = %d\n", ಗಾತ್ರ(ಗಾತ್ರ(ಪೂರ್ಣಾಂಕ)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -ಗಾತ್ರ(uintptr_t);
    ಬರೆ ("%lu %lu\n", t, t2);

    /* some alignof tests */
    ಬರೆ("__alignof__(int) = %d\n", __alignof__(ಪೂರ್ಣಾಂಕ));
    ಬರೆ("__alignof__(unsigned int) = %d\n", __alignof__(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ));
    ಬರೆ("__alignof__(short) = %d\n", __alignof__(ಗಿಡ್ಡ));
    ಬರೆ("__alignof__(unsigned short) = %d\n", __alignof__(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ));
    ಬರೆ("__alignof__(char) = %d\n", __alignof__(ಅಕ್ಷರ));
    ಬರೆ("__alignof__(unsigned char) = %d\n", __alignof__(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ));
    ಬರೆ("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    ಬರೆ("sizeof(char[1+2*a]) = %d\n", ಗಾತ್ರ(ಅಕ್ಷರ[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    ಬರೆ("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   ಗಾತ್ರ( (ರಚನೆ {ಪೂರ್ಣಾಂಕ i; ಪೂರ್ಣಾಂಕ j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    ಬರೆ("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   ಗಾತ್ರ (ರಚನೆ {ಗಿಡ್ಡ i; ಗಿಡ್ಡ j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    ಬರೆ("sizeof(t && 0) = %d\n", ಗಾತ್ರ(t && 0));
    ಬರೆ("sizeof(1 && 1) = %d\n", ಗಾತ್ರ(1 && 1));
    ಬರೆ("sizeof(t || 1) = %d\n", ಗಾತ್ರ(t || 1));
    ಬರೆ("sizeof(0 || 0) = %d\n", ಗಾತ್ರ(0 || 0));

    ಪೂರ್ಣಾಂಕ arr[4], fn();
    ಬರೆ("sizeof(0, arr) = %d\n", ಗಾತ್ರ(0, arr));
    ಬರೆ("sizeof(0, fn) = %d\n", ಗಾತ್ರ(0, fn));
}

ಶೂನ್ಯ typeof_test(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ a;
    typeof(a) b;
    typeof(ದಶಮಾಂಶ) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    ಬರೆ("a=%f b=%f c=%f\n", a, b, c);
}


ರಚನೆ hlist_ಗಂಟು;
ರಚನೆ hlist_ತಲೆ {
    ರಚನೆ hlist_ಗಂಟು *ಮೊದಲ, *ಕೊನೆಯ;
};

ಶೂನ್ಯ consume_ulong (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ i)
{
    i = 0;
}

ಶೂನ್ಯ statement_ಅಭಿವ್ಯಕ್ತಿ_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a, i;

    /* Basic stmt expr test */
    a = 0;
    ಗಾಗಿ(i=0;i<10;i++) {
        a += 1 + 
            ( { ಪೂರ್ಣಾಂಕ b, j; 
                b = 0; 
                ಗಾಗಿ(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    ಬರೆ("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    ಶೂನ್ಯ *v = (ಶೂನ್ಯ*)39;
    typeof(({
	    (ರಚನೆ hlist_ಗಂಟು *)v;
	    })) x;
    typeof (x)
	ptr = (ರಚನೆ hlist_ಗಂಟು *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#ವ್ಯಾಖ್ಯಾನಿಸು some_attr     __attribute__((aligned(1)))
#ವ್ಯಾಖ್ಯಾನಿಸು tps(str) ({                  \
            ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *t some_attr = str; \
            t;                                    \
          })
    ಬರೆ ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    ಪೂರ್ಣಾಂಕ t = 40;
    ಪೂರ್ಣಾಂಕ b = ({ ಪೂರ್ಣಾಂಕ t = 41; t; });
    ಪೂರ್ಣಾಂಕ c = ({ ಪೂರ್ಣಾಂಕ t = 42; t; });

    /* Test that aggregate return values work.  */
    ರಚನೆ hlist_ತಲೆ h
	= ({
	   ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hlist_ತಲೆ T;
	   ದೀರ್ಘ pre = 48;
	   T t = { (ಶೂನ್ಯ*)43, (ಶೂನ್ಯ*)44 };
	   ದೀರ್ಘ post = 49;
	   t;
	   });
    ಬರೆ ("stmtexpr: %d %d %d\n", t, b, c);
    ಬರೆ ("stmtexpr: %ld %ld\n", (ದೀರ್ಘ)h.ಮೊದಲ, (ದೀರ್ಘ)h.ಕೊನೆಯ);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: ಆದರೆ (i++ == 0) ಹೋಗು LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      ಹೋಗು LBL;
    });
  LBL:
    ಬರೆ("stmtexpr: %d should be 2\n", i);
}

ಶೂನ್ಯ local_label_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a;
    ಹೋಗು l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        ಹೋಗು l1;
    l4:
        ಬರೆ("aa1\n");
        ಹೋಗು l3;
    l2:
        ಬರೆ("aa3\n");
        ಹೋಗು l4;
    l1:
        ಬರೆ("aa2\n");
        ಹೋಗು l2;
    l3:;
        1;
    });
    ಬರೆ("a=%d\n", a);
    ಹಿಂತಿರುಗಿ;
 l4:
    ಬರೆ("bb1\n");
    ಹೋಗು l2;
 l1:
    ಬರೆ("bb2\n");
    ಹೋಗು l4;
}

/* inline assembler test */
#ಆದರೆ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __SIZE_TYPE__ ಶಬ್ದ;

/* from linux kernel */
ಸ್ಥಿರ ಅಕ್ಷರ * strncat1(ಅಕ್ಷರ * dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * src,ಗಾತ್ರ_t ಎಣಿಕೆ_3)
{
ಶಬ್ದ d0, d1, d2, d3;
__asm__ __volatile__(
	"repne\n\t"
	"scasb\n\t"
	"dec %1\n\t"
	"mov %8,%3\n"
	"1:\tdec %3\n\t"
	"js 2f\n\t"
	"lodsb\n\t"
	"stosb\n\t"
	"testb %%al,%%al\n\t"
	"jne 1b\n"
	"2:\txor %2,%2\n\t"
	"stosb"
	: "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ಎಣಿಕೆ_3)
	: "memory");
ಹಿಂತಿರುಗಿ dest;
}

ಸ್ಥಿರ ಅಕ್ಷರ * strncat2(ಅಕ್ಷರ * dest,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ * src,ಗಾತ್ರ_t ಎಣಿಕೆ_3)
{
ಶಬ್ದ d0, d1, d2, d3;
__asm__ __volatile__(
	"repne scasb\n\t" /* one-line repne prefix + string op */
	"dec %1\n\t"
	"mov %8,%3\n"
	"1:\tdec %3\n\t"
	"js 2f\n\t"
	"lodsb\n\t"
	"stosb\n\t"
	"testb %%al,%%al\n\t"
	"jne 1b\n"
	"2:\txor %2,%2\n\t"
	"stosb"
	: "=&S" (d0), "=&D" (d1), "=&a" (d2), "=&c" (d3)
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ಎಣಿಕೆ_3)
	: "memory");
ಹಿಂತಿರುಗಿ dest;
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ * memcpy1(ಶೂನ್ಯ * ಗಮ್ಯ, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ * from, ಗಾತ್ರ_t n)
{
ಶಬ್ದ d0, d1, d2;
__asm__ __volatile__(
	"rep ; movsl\n\t"
	"testb $2,%b4\n\t"
	"je 1f\n\t"
	"movsw\n"
	"1:\ttestb $1,%b4\n\t"
	"je 2f\n\t"
	"movsb\n"
	"2:"
	: "=&c" (d0), "=&D" (d1), "=&S" (d2)
	:"0" (n/4), "q" (n),"1" ((ಶಬ್ದ) ಗಮ್ಯ),"2" ((ಶಬ್ದ) from)
	: "memory");
ಹಿಂತಿರುಗಿ (ಗಮ್ಯ);
}

ಸ್ಥಿರ ಸಾಲೊಳಗೆ ಶೂನ್ಯ * memcpy2(ಶೂನ್ಯ * ಗಮ್ಯ, ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ * from, ಗಾತ್ರ_t n)
{
ಶಬ್ದ d0, d1, d2;
__asm__ __volatile__(
	"rep movsl\n\t"  /* one-line rep prefix + string op */
	"testb $2,%b4\n\t"
	"je 1f\n\t"
	"movsw\n"
	"1:\ttestb $1,%b4\n\t"
	"je 2f\n\t"
	"movsb\n"
	"2:"
	: "=&c" (d0), "=&D" (d1), "=&S" (d2)
	:"0" (n/4), "q" (n),"1" ((ಶಬ್ದ) ಗಮ್ಯ),"2" ((ಶಬ್ದ) from)
	: "memory");
ಹಿಂತಿರುಗಿ (ಗಮ್ಯ);
}

ಸ್ಥಿರ __inline__ ಶೂನ್ಯ sigaddset1(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಗಣ, ಪೂರ್ಣಾಂಕ _sig)
{
	__asm__("btsl %1,%0" : "=m"(*ಗಣ) : "Ir"(_sig - 1) : "cc");
}

ಸ್ಥಿರ __inline__ ಶೂನ್ಯ sigdelset1(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ *ಗಣ, ಪೂರ್ಣಾಂಕ _sig)
{
	asm("btrl %1,%0" : "=m"(*ಗಣ) : "Ir"(_sig - 1) : "cc", "flags");
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ಸ್ಥಿರ __inline__ __const__ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ swab32(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x)
{
        ಹಿಂತಿರುಗಿ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ಇಲ್ಲದಿದ್ದರೆ
ಸ್ಥಿರ __inline__ __const__ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ swab32(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ಹಿಂತಿರುಗಿ x;
}
#ಆದರೆ_ಅಂತ್ಯ

ಸ್ಥಿರ __inline__ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ mul64(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ a, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ b)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ res;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ)resh << 32) | resl;
#ಇಲ್ಲದಿದ್ದರೆ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ res;
}

ಸ್ಥಿರ __inline__ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ inc64(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ a)
{
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ res;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ಇಲ್ಲದಿದ್ದರೆ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#ಆದರೆ_ಅಂತ್ಯ
    ಹಿಂತಿರುಗಿ res;
}

ರಚನೆ struct123 {
    ಪೂರ್ಣಾಂಕ a;
    ಪೂರ್ಣಾಂಕ b;
};
ರಚನೆ struct1231 {
    ಶಬ್ದ addr;
};

ಶಬ್ದ mconstraint_test(ರಚನೆ struct1231 *r)
{
    ಶಬ್ದ ret;
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ a[2];
    a[0] = 0;
    __asm__ ಅಸ್ಥಿರ ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ರಚನೆ struct123 *)r->addr));
    ಹಿಂತಿರುಗಿ ret + a[0];
}

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64__
ಪೂರ್ಣಾಂಕ fls64(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x)
{
  ಪೂರ್ಣಾಂಕ bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ಹಿಂತಿರುಗಿ bitpos + 1;
}
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ other_constraints_test(ಶೂನ್ಯ)
{
    ಶಬ್ದ ret;
    ಪೂರ್ಣಾಂಕ var;
#ಆದರೆ CC_NAME != CC_clang
    __asm__ ಅಸ್ಥಿರ ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    ಬರೆ ("oc1: %d\n", ret == (ಶಬ್ದ)&var);
#ಆದರೆ_ಅಂತ್ಯ
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
/* Test global asm blocks playing with aliases.  */
ಶೂನ್ಯ ತಳ_func(ಶೂನ್ಯ)
{
  ಬರೆ ("asmc: base\n");
}

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __APPLE__
ಬಾಹ್ಯ ಶೂನ್ಯ override_func1 (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ override_func2 (ಶೂನ್ಯ);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

ಶೂನ್ಯ override_func2 (ಶೂನ್ಯ)
{
  ಬರೆ ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ bug_ಕೋಷ್ಟಕ[] __attribute__((section("__bug_table")));
ಅಕ್ಷರ * get_asm_string (ಶೂನ್ಯ)
{
  /* On i386 when -fPIC is enabled this would cause a compile error with GCC,
     the problem being the "i" constraint used with a symbolic operand
     resolving to a local label.  That check is overly zealous as the code
     within the asm makes sure to use it only in PIC-possible contexts,
     but all GCC versions behave like so.  We arrange for PIC to be disabled
     for compiling tcctest.c in the Makefile.

     Additionally the usage of 'c' in "%c0" in the template is actually wrong,
     as that would expect an operand that is a condition code.  The operand
     as is (a local label) is accepted by GCC in non-PIC mode, and on x86-64.
     What the linux kernel really wanted is 'p' to disable the addition of '$'
     to the printed operand (as in "$.LC0" where the template only wants the
     bare operand ".LC0").  But the code below is what the linux kernel
     happens to use and as such is the one we want to test.  */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ some_ಚಿಹ್ನೆ;
  asm ಅಸ್ಥಿರ (".globl some_symbol\n"
		"jmp .+6\n"
		"1:\n"
		"some_symbol: .long 0\n"
		".pushsection __bug_table, \"a\"\n"
		".globl bug_table\n"
		"bug_table:\n"
		/* The first entry (1b-2b) is unused in this test,
		   but we include it to check if cross-section
		   PC-relative references work.  */
		"2:\t.long 1b - 2b, %c0 - 2b\n"
		".popsection\n" : : "i" ("A string"));
  ಅಕ್ಷರ * str = ((ಅಕ್ಷರ*)bug_ಕೋಷ್ಟಕ) + bug_ಕೋಷ್ಟಕ[1];
  ಹಿಂತಿರುಗಿ str;
#ಇಲ್ಲದಿದ್ದರೆ
  ಹಿಂತಿರುಗಿ (ಅಕ್ಷರ *) "A string";
#ಆದರೆ_ಅಂತ್ಯ
}

/* This checks another constructs with local labels.  */
ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ alld_stuff[];
asm(".data\n"
    ".byte 41\n"
    "alld_stuff:\n"
    "661:\n"
    ".byte 42\n"
    "662:\n"
    ".pushsection .data.ignore\n"
    ".long 661b - .\n" /* This reference to 661 generates an external sym
                          which shouldn't somehow overwrite the offset that's
                          already determined for it.  */
    ".popsection\n"
    ".byte 662b - 661b\n"  /* So that this value is undeniably 1.  */);

ಶೂನ್ಯ asm_local_label_diff (ಶೂನ್ಯ)
{
  ಬರೆ ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#ಆದರೆ_ಅಂತ್ಯ //!__APPLE__
#ಆದರೆ_ಅಂತ್ಯ //!_WIN32

/* This checks that static local variables are available from assembler.  */
ಶೂನ್ಯ asm_local_statics (ಶೂನ್ಯ)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ localint = 41;
  asm("incl %0" : "+m" (localint));
  ಬರೆ ("asm_local_statics: %d\n", localint);
}

ಸ್ಥಿರ
ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗಣ;

ಶೂನ್ಯ fancy_copy (ಚಿಹ್ನೆರಹಿತ *ಒಳ, ಚಿಹ್ನೆರಹಿತ *ಹೊರಹೋಗು)
{
  asm ಅಸ್ಥಿರ ("" : "=r" (*ಹೊರಹೋಗು) : "0" (*ಒಳ));
}

ಶೂನ್ಯ fancy_copy2 (ಚಿಹ್ನೆರಹಿತ *ಒಳ, ಚಿಹ್ನೆರಹಿತ *ಹೊರಹೋಗು)
{
  asm ಅಸ್ಥಿರ ("mov %0,(%1)" : : "r" (*ಒಳ), "r" (ಹೊರಹೋಗು) : "memory");
}

#ಆದರೆ defined __x86_64__
ಶೂನ್ಯ clobber_r12(ಶೂನ್ಯ)
{
    asm ಅಸ್ಥಿರ("mov $1, %%r12" ::: "r12");
}
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ test_ಮೇಲಿನ_clobbers_really(ಶೂನ್ಯ)
{
#ಆದರೆ defined __x86_64__
    ನೋಂದಣಿ ಶಬ್ದ val asm("r12");
    ಶಬ್ದ val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm ಅಸ್ಥಿರ("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm ಅಸ್ಥಿರ("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    ಬರೆ("asmhc: 0x%x\n", val2);
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ test_ಮೇಲಿನ_clobbers(ಶೂನ್ಯ)
{
#ಆದರೆ defined __x86_64__
    ಶಬ್ದ x1, x2;
    asm ಅಸ್ಥಿರ("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ಮೇಲಿನ_clobbers_really();
    asm ಅಸ್ಥಿರ("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm ಅಸ್ಥಿರ("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#ಆದರೆ_ಅಂತ್ಯ
}

ಸ್ಥಿರ ದೀರ್ಘ cpu_ಸಂಖ್ಯೆ;
ಶೂನ್ಯ trace_console(ದೀರ್ಘ len, ದೀರ್ಘ len2)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64__
    /* This generated invalid code when the emission of the switch
       table isn't disabled.  The asms are necessary to show the bug,
       normal statements don't work (they need to generate some code
       even under nocode_wanted, which normal statements don't do,
       but asms do).  Also at least these number of cases is necessary
       to generate enough "random" bytes.  They ultimately are enough
       to create invalid instruction patterns to which the first
       skip-to-decision-table jump jumps.  If decision table emission
       is disabled all of this is no problem.

       It also is necessary that the switches are in a statement expression
       (which has the property of not being enterable from outside. no
       matter what).  */
    ಆದರೆ (0
        &&
            ({
              ದೀರ್ಘ pscr_ret__;
              ಆಯ್ಕೆ(len) {
                ಸ್ಥಿತಿ 4:
                    {
                       ದೀರ್ಘ pfo_ret__;
                       ಆಯ್ಕೆ (len2) {
                         ಸ್ಥಿತಿ 8:	ಬರೆ("bla"); pfo_ret__ = 42; ನಿಲ್ಲಿಸು;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ನಿಲ್ಲಿಸು;
                ಸ್ಥಿತಿ 8:
                    {
                       ದೀರ್ಘ pfo_ret__;
                       ಆಯ್ಕೆ (len2) {
                         ಸ್ಥಿತಿ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ನಿಲ್ಲಿಸು;
                         ಸ್ಥಿತಿ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ನಿಲ್ಲಿಸು;
                         ಸ್ಥಿತಿ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ನಿಲ್ಲಿಸು;
                         ಸ್ಥಿತಿ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ನಿಲ್ಲಿಸು;
                         ಪೂರ್ವನಿಯೋಜಿತ: ಬರೆ("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ನಿಲ್ಲಿಸು;
              }
              pscr_ret__;
            }))
      {
        ಬರೆ("huh?\n");
      }
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ test_asm_dead_ಸಂಕೇತ(ಶೂನ್ಯ)
{
  ಶಬ್ದ rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm ಅಸ್ಥಿರ ("" : "=D" (rdi) : "0" (0));
  (ಶೂನ್ಯ)ಗಾತ್ರ (({
      ಪೂರ್ಣಾಂಕ var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm ಅಸ್ಥಿರ ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

ಶೂನ್ಯ test_asm_call(ಶೂನ್ಯ)
{
#ಆದರೆ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ಸ್ಥಿರ ಅಕ್ಷರ str[] = "PATH";
  ಅಕ್ಷರ *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm ಅಸ್ಥಿರ ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ಆದರೆ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ಇಲ್ಲದಿದ್ದರೆ
		"call getenv;"
#ಆದರೆ_ಅಂತ್ಯ
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  ಬರೆ("asmd: %s\n", s);
#ಆದರೆ_ಅಂತ್ಯ
}

#ಆದರೆ defined __x86_64__
# define RX "(%rip)"
#ಇಲ್ಲದಿದ್ದರೆ
# define RX
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ asm_dot_test(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __APPLE__
    ಪೂರ್ಣಾಂಕ x;
    ಗಾಗಿ (x = 1;; ++x) {
        ಪೂರ್ಣಾಂಕ r = x;
        ಆಯ್ಕೆ (x) {
        ಸ್ಥಿತಿ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        ಸ್ಥಿತಿ 2:
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ಇಲ್ಲದಿದ್ದರೆ
            asm(".text; mov $123, %eax; jmp p0");
#ಆದರೆ_ಅಂತ್ಯ
	ಸ್ಥಿತಿ 3:
#ಆದರೆ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ಇಲ್ಲದಿದ್ದರೆ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#ಆದರೆ_ಅಂತ್ಯ
            asm(".text; mov X"RX",%eax; jmp p0");
        ಸ್ಥಿತಿ 4:
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ಇಲ್ಲದಿದ್ದರೆ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#ಆದರೆ_ಅಂತ್ಯ
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#ಆದರೆ_ಅಂತ್ಯ
        ಸ್ಥಿತಿ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ನಿಲ್ಲಿಸು;
	}
        ಆದರೆ (r == x)
            ನಿಲ್ಲಿಸು;
        ಬರೆ("asm_dot_test %d: %d\n", x, r);
    }
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ asm_pcrel_test(ಶೂನ್ಯ)
{
    ಚಿಹ್ನೆರಹಿತ o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    ಬರೆ("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

ಶೂನ್ಯ asm_test(ಶೂನ್ಯ)
{
    ಅಕ್ಷರ buf[128];
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ val, val2;
    ರಚನೆ struct123 s1;
    ರಚನೆ struct1231 s2 = { (ಶಬ್ದ)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    ಪೂರ್ಣಾಂಕ ತಳ_func = 42;
    ಶೂನ್ಯ override_func3 (ಶೂನ್ಯ);
    ಶಬ್ದ asmret;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BOOL_ISOC99
    _Bool somebool;
#ಆದರೆ_ಅಂತ್ಯ
    ನೋಂದಣಿ ಪೂರ್ಣಾಂಕ regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm ಅಸ್ಥಿರ ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm ಅಸ್ಥಿರ ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    ಬರೆ("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    ಬರೆ("%s\n", buf);

    /* 'A' constraint test */
    ಬರೆ("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    ಬರೆ("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    ಬರೆ("mconstraint: %d", mconstraint_test(&s2));
    ಬರೆ(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    ಗಣ = 0xff;
    sigdelset1(&ಗಣ, 2);
    sigaddset1(&ಗಣ, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    ಹೋಗು label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(ಗಣ) : "Ir"(20) : "cc");
    ಬರೆ("set=0x%x\n", ಗಣ);
    val = 0x01020304;
    ಬರೆ("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm ಅಸ್ಥಿರ(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    ಬರೆ("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
    asm_local_statics();
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm ಅಸ್ಥಿರ("" : "=r" (asmret) : "0"(s2));
    ಆದರೆ (asmret != s2.addr)
      ಬರೆ("asmstr: failed\n");
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm ಅಸ್ಥಿರ("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ಆದರೆ (!somebool)
      ಬರೆ("asmbool: failed\n");
#ಆದರೆ_ಅಂತ್ಯ
    val = 43;
    fancy_copy (&val, &val2);
    ಬರೆ ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    ಬರೆ ("fancycpy2(%d)=%d\n", val, val2);
    asm ಅಸ್ಥಿರ ("mov $0x4243, %%esi" : "=r" (regvar));
    ಬರೆ ("regvar=%x\n", regvar);
    test_ಮೇಲಿನ_clobbers();
    trace_console(8, 8);
    test_asm_dead_ಸಂಕೇತ();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ಹಿಂತಿರುಗಿ;
 label1:
    ಹೋಗು label2;
}

#ಇಲ್ಲದಿದ್ದರೆ

ಶೂನ್ಯ asm_test(ಶೂನ್ಯ)
{
}

#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು COMPAT_TYPE(type1, type2) \
{\
    ಬರೆ("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

ಪೂರ್ಣಾಂಕ constant_p_var;

ಪೂರ್ಣಾಂಕ func(ಶೂನ್ಯ);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ಸ್ಥಿರ ಶೂನ್ಯ builtin_test_ಬಿಟ್ಟುಗಳು(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ x, ಪೂರ್ಣಾಂಕ cnt[])
{
#ಆದರೆ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ) x) cnt[3] += __builtin_clz(x);
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) x) cnt[4] += __builtin_clzl(x);
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ) x) cnt[5] += __builtin_clzll(x);

    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ) x) cnt[6] += __builtin_ctz(x);
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ) x) cnt[7] += __builtin_ctzl(x);
    ಆದರೆ ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ) x) cnt[8] += __builtin_ctzll(x);

#ಆದರೆ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#ಆದರೆ_ಅಂತ್ಯ

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#ಆದರೆ_ಅಂತ್ಯ
}

ಶೂನ್ಯ builtin_test(ಶೂನ್ಯ)
{
    ಗಿಡ್ಡ s;
    ಪೂರ್ಣಾಂಕ i;
    ದೀರ್ಘ ದೀರ್ಘ ll;
#ಆದರೆ GCC_MAJOR >= 3
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ, ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ, ಅಕ್ಷರ);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ, ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ[2], ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ[2]);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ[2][3], ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ[][3]);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ (*)[], ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ (*)[]);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
    COMPAT_TYPE(__typeof__(1 ? (ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ (*)[2])0 : (ಪೂರ್ಣಾಂಕ (*)[2])0),
                ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ (*)[2][3])0 :
                              (ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*)[2][3])0),
                ಸ್ಥಿರಾಂಕ ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*)[2][3])0 :
                              (ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ (*)[2][3])0),
                ಸ್ಥಿರಾಂಕ ಅಸ್ಥಿರ ಪೂರ್ಣಾಂಕ (*)[2][3]);
#ಇಲ್ಲದಿದ್ದರೆ
    /* clang doesn't combine qualifiers through array types */
    ಬರೆ("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    ಬರೆ("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    ಬರೆ("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#ಆದರೆ_ಅಂತ್ಯ
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ *, ಪೂರ್ಣಾಂಕ *);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ *, ಶೂನ್ಯ *);
    COMPAT_TYPE(ಪೂರ್ಣಾಂಕ *, ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ *);
    COMPAT_TYPE(ಅಕ್ಷರ *, ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *);
    COMPAT_TYPE(ಅಕ್ಷರ *, ಚಿಹ್ನೆಯುಳ್ಳ ಅಕ್ಷರ *);
    COMPAT_TYPE(ಅಕ್ಷರ *, ಅಕ್ಷರ *);
    COMPAT_TYPE(ಅಕ್ಷರ **, ಶೂನ್ಯ *);
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("res1 = %d\n", __builtin_constant_p(1));
    ಬರೆ("res2 = %d\n", __builtin_constant_p(1 + 2));
    ಬರೆ("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    ಬರೆ("res4 = %d\n", __builtin_constant_p(constant_p_var));
    ಬರೆ("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    ಬರೆ("res6 = %d\n", __builtin_constant_p(i && 1));
    ಬರೆ("res7 = %d\n", __builtin_constant_p("hi"));
    ಬರೆ("res8 = %d\n", __builtin_constant_p(func()));
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
    ಬರೆ("res10 = %d\n", __builtin_constant_p(i && 0));
    ಬರೆ("res11 = %d\n", __builtin_constant_p(i * 0));
    ಬರೆ("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    ಬರೆ("res13 = %d\n", __builtin_constant_p((1,7)));
#ಇಲ್ಲದಿದ್ದರೆ
    /* clang doesn't regard these as constant expression */
    ಬರೆ("res10 = 1\n");
    ಬರೆ("res11 = 1\n");
    ಬರೆ("res12 = 1\n");
    ಬರೆ("res13 = 0\n");
#ಆದರೆ_ಅಂತ್ಯ

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    ಬರೆ("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    ಬರೆ("bce: %d\n", i);
    i = ಗಾತ್ರ (__builtin_choose_expr (1, ll, s));
    ಬರೆ("bce: %d\n", i);
    i = ಗಾತ್ರ (__builtin_choose_expr (0, ll, s));
    ಬರೆ("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	ಪೂರ್ಣಾಂಕ cnt[18];
	ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ r = 0;

	memset(cnt, 0, ಗಾತ್ರ(cnt));
	builtin_test_ಬಿಟ್ಟುಗಳು(0, cnt);
	builtin_test_ಬಿಟ್ಟುಗಳು(0xffffffffffffffffull, cnt);
        ಗಾಗಿ (i = 0; i < 64; i++)
	    builtin_test_ಬಿಟ್ಟುಗಳು(1ull << i, cnt);
        ಗಾಗಿ (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_ಬಿಟ್ಟುಗಳು(r, cnt);
	}
	ಗಾಗಿ (i = 0; i < 18; i++)
	    ಬರೆ ("%d %d\n", i, cnt[i]);
    }
}

#ಆದರೆ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
ಶೂನ್ಯ weak_test(ಶೂನ್ಯ) {}
#ಇಲ್ಲದಿದ್ದರೆ
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_f1(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_f2(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ                       weak_f3(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_v1;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_v2;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ                       weak_v3;

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ                           (*weak_fpa)() __attribute__((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute__((weak))     (*weak_fpb)();
ಬಾಹ್ಯ     __attribute__((weak)) ಪೂರ್ಣಾಂಕ (*weak_fpc)();

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ                     weak_asm_f1(ಶೂನ್ಯ) asm("weak_asm_f1x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute((weak)) weak_asm_f2(ಶೂನ್ಯ) asm("weak_asm_f2x")                    ;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute((weak)) weak_asm_f3(ಶೂನ್ಯ) asm("weak_asm_f3x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __attribute((weak)) weak_asm_v3(ಶೂನ್ಯ) asm("weak_asm_v3x") __attribute((weak));

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಗಾತ್ರ_t dummy = 0;
ಬಾಹ್ಯ __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
ಬಾಹ್ಯ __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
ಬಾಹ್ಯ __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ some_lib_func(ಶೂನ್ಯ);
ಪೂರ್ಣಾಂಕ dummy_impl_ದ_slf(ಶೂನ್ಯ) { ಹಿಂತಿರುಗಿ 444; }
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __clang__
ಪೂರ್ಣಾಂಕ some_lib_func(ಶೂನ್ಯ) __attribute__((weak, alias("dummy_impl_of_slf")));
#ಆದರೆ_ಅಂತ್ಯ

ಪೂರ್ಣಾಂಕ weak_toolate() __attribute__((weak));
ಪೂರ್ಣಾಂಕ weak_toolate() { ಹಿಂತಿರುಗಿ 0; }

ಶೂನ್ಯ __attribute__((weak)) weak_test(ಶೂನ್ಯ)
{
	ಬರೆ("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	ಬರೆ("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	ಬರೆ("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	ಬರೆ("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	ಬರೆ("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	ಬರೆ("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	ಬರೆ("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	ಬರೆ("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	ಬರೆ("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	ಬರೆ("weak_asm_f1=%d\n", weak_asm_f1 != ಖಾಲಿ);
	ಬರೆ("weak_asm_f2=%d\n", weak_asm_f2 != ಖಾಲಿ);
	ಬರೆ("weak_asm_f3=%d\n", weak_asm_f3 != ಖಾಲಿ);
	ಬರೆ("weak_asm_v1=%d\n",&weak_asm_v1 != ಖಾಲಿ);
	ಬರೆ("weak_asm_v2=%d\n",&weak_asm_v2 != ಖಾಲಿ);
	ಬರೆ("weak_asm_v3=%d\n",&weak_asm_v3 != ಖಾಲಿ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __clang__
	ಬರೆ("some_lib_func=444\n");
#ಇಲ್ಲದಿದ್ದರೆ
	ಬರೆ("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#ಆದರೆ_ಅಂತ್ಯ
}

ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_f2() { ಹಿಂತಿರುಗಿ 222; }
ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_f3() { ಹಿಂತಿರುಗಿ 333; }
ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_v2 = 222;
ಪೂರ್ಣಾಂಕ __attribute__((weak)) weak_v3 = 333;
#ಆದರೆ_ಅಂತ್ಯ

ಶೂನ್ಯ const_func(ಸ್ಥಿರಾಂಕ ಪೂರ್ಣಾಂಕ a)
{
}

ಶೂನ್ಯ const_warn_test(ಶೂನ್ಯ)
{
    const_func(1);
}

ರಚನೆ condstruct {
  ಪೂರ್ಣಾಂಕ i;
};

ಪೂರ್ಣಾಂಕ getme (ರಚನೆ condstruct *s, ಪೂರ್ಣಾಂಕ i)
{
  ಪೂರ್ಣಾಂಕ i1 = (i == 0 ? 0 : s)->i;
  ಪೂರ್ಣಾಂಕ i2 = (i == 0 ? s : 0)->i;
  ಪೂರ್ಣಾಂಕ i3 = (i == 0 ? (ಶೂನ್ಯ*)0 : s)->i;
  ಪೂರ್ಣಾಂಕ i4 = (i == 0 ? s : (ಶೂನ್ಯ*)0)->i;
  ಹಿಂತಿರುಗಿ i1 + i2 + i3 + i4;
}

ರಚನೆ global_ದತ್ತಾಂಶ
{
  ಪೂರ್ಣಾಂಕ a[40];
  ಪೂರ್ಣಾಂಕ *b[40];
};

ರಚನೆ global_ದತ್ತಾಂಶ global_ದತ್ತಾಂಶ;

ಪೂರ್ಣಾಂಕ global_ದತ್ತಾಂಶ_getstuff (ಪೂರ್ಣಾಂಕ *, ಪೂರ್ಣಾಂಕ);

ಶೂನ್ಯ global_ದತ್ತಾಂಶ_callit (ಪೂರ್ಣಾಂಕ i)
{
  *global_ದತ್ತಾಂಶ.b[i] = global_ದತ್ತಾಂಶ_getstuff (global_ದತ್ತಾಂಶ.b[i], 1);
}

ಪೂರ್ಣಾಂಕ global_ದತ್ತಾಂಶ_getstuff (ಪೂರ್ಣಾಂಕ *p, ಪೂರ್ಣಾಂಕ i)
{
  ಹಿಂತಿರುಗಿ *p + i;
}

ಶೂನ್ಯ global_ದತ್ತಾಂಶ_test (ಶೂನ್ಯ)
{
  global_ದತ್ತಾಂಶ.a[0] = 42;
  global_ದತ್ತಾಂಶ.b[0] = &global_ದತ್ತಾಂಶ.a[0];
  global_ದತ್ತಾಂಶ_callit (0);
  ಬರೆ ("%d\n", global_ದತ್ತಾಂಶ.a[0]);
}

ರಚನೆ cmpcmpS
{
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ fill : 3;
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ b1 : 1;
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ b2 : 1;
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ fill2 : 3;
};

ಪೂರ್ಣಾಂಕ glob1, glob2, glob3;

ಶೂನ್ಯ compare_comparisons (ರಚನೆ cmpcmpS *s)
{
  ಆದರೆ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    ಬರೆ ("comparing comparisons broken\n");
}

ಶೂನ್ಯ cmp_comparison_test(ಶೂನ್ಯ)
{
  ರಚನೆ cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

ಪೂರ್ಣಾಂಕ fcompare (ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b, ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2)
{
  ಆಯ್ಕೆ (ಸಂಕೇತ_2) {
    ಸ್ಥಿತಿ 0: ಹಿಂತಿರುಗಿ a == b;
    ಸ್ಥಿತಿ 1: ಹಿಂತಿರುಗಿ a != b;
    ಸ್ಥಿತಿ 2: ಹಿಂತಿರುಗಿ a < b;
    ಸ್ಥಿತಿ 3: ಹಿಂತಿರುಗಿ a >= b;
    ಸ್ಥಿತಿ 4: ಹಿಂತಿರುಗಿ a > b;
    ಸ್ಥಿತಿ 5: ಹಿಂತಿರುಗಿ a <= b;
  }
  ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ math_cmp_test(ಶೂನ್ಯ)
{
  ದ್ವಿಗುಣ nan = 0.0/0.0;
  ದ್ವಿಗುಣ one = 1.0;
  ದ್ವಿಗುಣ two = 2.0;
  ಪೂರ್ಣಾಂಕ comp = 0;
  ಪೂರ್ಣಾಂಕ v;
#ವ್ಯಾಖ್ಯಾನಿಸು bug(a,b,op,iop,part) ಬರೆ("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#ವ್ಯಾಖ್ಯಾನಿಸು FCMP(a,b,op,iop,ಸಂಕೇತ_2) \
  ಆದರೆ (fcompare (a,b,ಸಂಕೇತ_2))    \
    bug (a,b,op,iop,1); \
  ಆದರೆ (a op b) \
    bug (a,b,op,iop,2); \
  ಆದರೆ (a iop b) \
    ; \
  ಇಲ್ಲದಿದ್ದರೆ \
    bug (a,b,op,iop,3); \
  ಆದರೆ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ಆದರೆ ((a iop b) || comp) \
    ; \
  ಇಲ್ಲದಿದ್ದರೆ \
    bug (a,b,op,iop,5); \
  ಆದರೆ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ಆದರೆ (!fcompare (nan, nan, 1))
    bug (nan, nan, !=, ==, 6);

  /* Relational tests on numbers.  */
  FCMP(two, one, <, >=, 2);
  FCMP(one, two, >=, <, 3);
  FCMP(one, two, >, <=, 4);
  FCMP(two, one, <=, >, 5);

  /* Relational tests on NaNs.  Note that the inverse op here is
     always !=, there's no operator in C that is equivalent to !(a < b),
     when NaNs are involved, same for the other relational ops.  */
  FCMP(nan, nan, <, !=, 2);
  FCMP(nan, nan, >=, !=, 3);
  FCMP(nan, nan, >, !=, 4);
  FCMP(nan, nan, <=, !=, 5);
}

ದ್ವಿಗುಣ get100 () { ಹಿಂತಿರುಗಿ 100.0; }

ಶೂನ್ಯ callsave_test(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i, s; ದ್ವಿಗುಣ *d; ದ್ವಿಗುಣ t;
  s = ಗಾತ್ರ (ದ್ವಿಗುಣ);
  ಬರೆ ("callsavetest: %d\n", s);
  d = alloca (ಗಾತ್ರ(ದ್ವಿಗುಣ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  ಬರೆ ("%d\n", i);
}


ಶೂನ್ಯ bfa3(ptrdiff_t str_ಸ್ಥಾನಾಂತರ)
{
    ಬರೆ("bfa3: %s\n", (ಅಕ್ಷರ *)__builtin_frame_address(3) + str_ಸ್ಥಾನಾಂತರ);
}
ಶೂನ್ಯ bfa2(ptrdiff_t str_ಸ್ಥಾನಾಂತರ)
{
    ಬರೆ("bfa2: %s\n", (ಅಕ್ಷರ *)__builtin_frame_address(2) + str_ಸ್ಥಾನಾಂತರ);
    bfa3(str_ಸ್ಥಾನಾಂತರ);
}
ಶೂನ್ಯ bfa1(ptrdiff_t str_ಸ್ಥಾನಾಂತರ)
{
    ಬರೆ("bfa1: %s\n", (ಅಕ್ಷರ *)__builtin_frame_address(1) + str_ಸ್ಥಾನಾಂತರ);
    bfa2(str_ಸ್ಥಾನಾಂತರ);
}

ಶೂನ್ಯ builtin_ಚೌಕಟ್ಟು_ವಿಳಾಸ_test(ಶೂನ್ಯ)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __arm__
    ಅಕ್ಷರ str[] = "__builtin_frame_address";
    ಅಕ್ಷರ *fp0 = __builtin_frame_address(0);

    ಬರೆ("str: %s\n", str);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
}

ಅಕ್ಷರ ಮೂಲಕ_volatile (ಅಕ್ಷರ i)
{
  ಅಕ್ಷರ ಅಸ್ಥಿರ vi;
  vi = i;
  ಹಿಂತಿರುಗಿ vi;
}

ಶೂನ್ಯ volatile_test(ಶೂನ್ಯ)
{
    ಆದರೆ (ಮೂಲಕ_volatile (42) != 42)
      ಬರೆ (" broken\n");
    ಇಲ್ಲದಿದ್ದರೆ
      ಬರೆ (" ok\n");
}

ರಚನೆ __attribute__((__packed__)) Spacked {
    ಅಕ್ಷರ a;
    ಗಿಡ್ಡ b;
    ಪೂರ್ಣಾಂಕ c;
};
ರಚನೆ Spacked spacked;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __attribute__((__packed__)) {
    ಅಕ್ಷರ a;
    ಗಿಡ್ಡ b;
    ಪೂರ್ಣಾಂಕ c;
} Spacked2;
Spacked2 spacked2;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Spacked3_s {
    ಅಕ್ಷರ a;
    ಗಿಡ್ಡ b;
    ಪೂರ್ಣಾಂಕ c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ರಚನೆ gate_struct64 {
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ segment;
    ಚಿಹ್ನೆರಹಿತ ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಸ್ಥಾನಾಂತರ_ಮಧ್ಯ;
    ಚಿಹ್ನೆರಹಿತ ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ;
    ಚಿಹ್ನೆರಹಿತ zero1;
} __attribute__((packed));
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ gate_struct64 gate_desc;
gate_desc a_gate_desc;
ಶೂನ್ಯ attrib_test(ಶೂನ್ಯ)
{
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32
  ಬರೆ("attr: %d %d %d %d\n", ಗಾತ್ರ(ರಚನೆ Spacked),
	 ಗಾತ್ರ(spacked), ಗಾತ್ರ(Spacked2), ಗಾತ್ರ(spacked2));
  ಬರೆ("attr: %d %d\n", ಗಾತ್ರ(Spacked3), ಗಾತ್ರ(spacked3));
  ಬರೆ("attr: %d %d\n", ಗಾತ್ರ(gate_desc), ಗಾತ್ರ(a_gate_desc));
#ಆದರೆ_ಅಂತ್ಯ
}
ಬಾಹ್ಯ __attribute__((__unused__)) ಅಕ್ಷರ * __attribute__((__unused__)) *
strange_attrib_placement (ಶೂನ್ಯ);

ಶೂನ್ಯ * __attribute__((__unused__)) get_void_ptr (ಶೂನ್ಯ *a)
{
  ಹಿಂತಿರುಗಿ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ಸ್ಥಿರ ಸಾಲೊಳಗೆ
ಪೂರ್ಣಾಂಕ __get_order(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ ಗಾತ್ರ_2)
{
  ಪೂರ್ಣಾಂಕ ಕ್ರಮ;
  ಗಾತ್ರ_2 -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ರಚನೆ S { ಪೂರ್ಣಾಂಕ i : 1; } s; // constructed for this '1'
    }
  ಕ್ರಮ = ಗಾತ್ರ_2;
  ಹಿಂತಿರುಗಿ ಕ್ರಮ;
}

/* This just forces the above inline function to be actually emitted.  */
ಪೂರ್ಣಾಂಕ force_get_ಕ್ರಮ(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ s)
{
    ಹಿಂತಿರುಗಿ __get_order(s);
}

#ವ್ಯಾಖ್ಯಾನಿಸು pv(m) ಬರೆ(ಗಾತ್ರ (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
ಶೂನ್ಯ bounds_check1_test (ಶೂನ್ಯ)
{
    ರಚನೆ s {
        ಪೂರ್ಣಾಂಕ x;
        ದೀರ್ಘ ದೀರ್ಘ y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
ಶೂನ್ಯ map_ಕೂಡಿಸು(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ d, ಪೂರ್ಣಾಂಕ e, ಪೂರ್ಣಾಂಕ f, ಪೂರ್ಣಾಂಕ g, ಪೂರ್ಣಾಂಕ h, ಪೂರ್ಣಾಂಕ i)
{
  ಬರೆ ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

ಶೂನ್ಯ func_arg_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಂಕ a = 0;
    ಪೂರ್ಣಾಂಕ b = 1;
    map_ಕೂಡಿಸು(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#ವ್ಯಾಖ್ಯಾನಿಸು CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
ಶೂನ್ಯ whitespace_test(ಶೂನ್ಯ)
{
    ಅಕ್ಷರ *str;
    ಪೂರ್ಣಾಂಕ tcc_test = 1;

#ಆದರೆ 1
    pri\
ntf("whitspace:\n");
#ಆದರೆ_ಅಂತ್ಯ
    pf("N=%d\n", 2);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#ಆದರೆ_ಅಂತ್ಯ

    pri\
\
ntf("min=%d\n", 4);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ACCEPT_LF_ಒಳ_ಅಕ್ಷರಸರಣಿಗಳು
    ಬರೆ("len1=%d\n", ಅಕ್ಷರಸರಣಿ_ಉದ್ದ("
"));
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CORRECT_CR_HANDLING
    str = "
";
    ಬರೆ("len1=%d str[0]=%d\n", ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(str), str[0]);
#ಆದರೆ_ಅಂತ್ಯ
    ಬರೆ("len1=%d\n", ಅಕ್ಷರಸರಣಿ_ಉದ್ದ("a
"));
#ಇಲ್ಲದಿದ್ದರೆ
    ಬರೆ("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#ಆದರೆ_ಅಂತ್ಯ /* ACCEPT_LF_IN_STRINGS */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __LINE__
    ಬರೆ("__LINE__ defined\n");
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ 0
    /* wrong with GCC */
    ಬರೆ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ಸಾಲು 1111
    ಬರೆ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ಸಾಲು 2222 "test"
    ಬರೆ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ಆದರೆ_ಅಂತ್ಯ

    ಬರೆ("\\
"12\\
063\\
n 456\"\n");

    ಬರೆ ("%d\n",
#ಆದರೆ 1
	    tcc_test
#ಆದರೆ_ಅಂತ್ಯ
            );

}

#ವ್ಯಾಖ್ಯಾನಿಸು ಸತತ_2(test) puts("---- " #test " ----"), test(), puts("")

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv)
{
    ಸತತ_2(whitespace_test);
    ಸತತ_2(macro_test);
    ಸತತ_2(recursive_macro_test);
    ಸತತ_2(string_test);
    ಸತತ_2(ಅಭಿವ್ಯಕ್ತಿ_test);
    ಸತತ_2(scope_test);
    ಸತತ_2(scope2_test);
    ಸತತ_2(forward_test);
    ಸತತ_2(funcptr_test);
    ಸತತ_2(if_test);
    ಸತತ_2(loop_test);
    ಸತತ_2(switch_test);
    ಸತತ_2(goto_test);
    ಸತತ_2(enum_test);
    ಸತತ_2(typedef_test);
    ಸತತ_2(struct_test);
    ಸತತ_2(array_test);
    ಸತತ_2(ಅಭಿವ್ಯಕ್ತಿ_ptr_test);
    ಸತತ_2(bool_test);
    ಸತತ_2(optimize_ಹೊರಹೋಗು_test);
    ಸತತ_2(expr2_test);
    ಸತತ_2(constant_ಅಭಿವ್ಯಕ್ತಿ_test);
    ಸತತ_2(ಅಭಿವ್ಯಕ್ತಿ_cmp_test);
    ಸತತ_2(char_short_test);
    ಸತತ_2(init_test);
    ಸತತ_2(compound_literal_test);
    ಸತತ_2(kr_test);
    ಸತತ_2(struct_ನಿಯೋಜಿಸು_test);
    ಸತತ_2(cast_test);
    ಸತತ_2(bitfield_test);
    ಸತತ_2(c99_bool_test);
    ಸತತ_2(float_test);
    ಸತತ_2(longlong_test);
    ಸತತ_2(manyarg_test);
    ಸತತ_2(stdarg_test);
    ಸತತ_2(relocation_test);
    ಸತತ_2(old_style_function_test);
    ಸತತ_2(alloca_test);
    ಸತತ_2(c99_vla_test);
    ಸತತ_2(sizeof_test);
    ಸತತ_2(typeof_test);
    ಸತತ_2(statement_ಅಭಿವ್ಯಕ್ತಿ_test);
    ಸತತ_2(local_label_test);
    ಸತತ_2(asm_test);
    ಸತತ_2(builtin_test);
    ಸತತ_2(weak_test);
    ಸತತ_2(global_ದತ್ತಾಂಶ_test);
    ಸತತ_2(cmp_comparison_test);
    ಸತತ_2(math_cmp_test);
    ಸತತ_2(callsave_test);
    ಸತತ_2(builtin_ಚೌಕಟ್ಟು_ವಿಳಾಸ_test);
    ಸತತ_2(volatile_test);
    ಸತತ_2(attrib_test);
    ಸತತ_2(bounds_check1_test);
    ಸತತ_2(func_arg_test);

    ಹಿಂತಿರುಗಿ 0;
}
