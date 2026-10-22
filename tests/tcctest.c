/*
 * TCC auto test program
 */
#ಅನ್ತರ್ಭಾವ "config.h"

/* identify the configured reference compiler in use */
#define CC_gcc 1
#define CC_clang 2
#define CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#define ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#define BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#define C99_MACROS

#ಯದಿ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#ಅನ್ಯಥಾ
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ಯದಿ defined(_WIN32)
#define LONG_DOUBLE ದ್ವಿಗುಣ
#define LONG_DOUBLE_LITERAL(x) x
#ಅನ್ಯಥಾ
#define LONG_DOUBLE long ದ್ವಿಗುಣ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#ಅನ್ತರ್ಭಾವ TCCLIB_INC

#ಅನ್ತರ್ಭಾವ TCCLIB_INC1.TCCLIB_INC2

#ಅನ್ತರ್ಭಾವ TCCLIB_INC1.h>

#ಅನ್ತರ್ಭಾವ TCCLIB_INC3

#ಅನ್ತರ್ಭಾವ <tcclib.h>

#ಅನ್ತರ್ಭಾವ "tcclib.h"

#ಅನ್ತರ್ಭಾವ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#ಅನ್ಯಥಾ
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#ಅನ್ತರ್ಭಾವ INC(42test)
#ಅನ್ತರ್ಭಾವ incname
#ಅನ್ತರ್ಭಾವ stringify(funnyname)

ಪೂರ್ಣಾಙ್ಕ fib(ಪೂರ್ಣಾಙ್ಕ n);
ಶೂನ್ಯ ಅಂಕೆ(ಪೂರ್ಣಾಙ್ಕ n);
ಶೂನ್ಯ forward_ref(ಶೂನ್ಯ);
ಪೂರ್ಣಾಙ್ಕ isid(ಪೂರ್ಣಾಙ್ಕ c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
ಶೂನ್ಯ funny_ಸಾಲು_continuation (ಪೂರ್ಣಾಙ್ಕ, ..\
. );

#define A 2
#define N 1234 + A
#define pf printf
#define M1(a, b)  (a) + (b)

#define str\
(s) # s
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define ಕೆಳಗಿನ_2 ಕೆಳಗಿನ_2 ", world"

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ onetwothree = 123;
#define onetwothree4 onetwothree
#define onetwothree xglue(onetwothree,4)

#define min(a, b) ((a) < (b) ? (a) : (b))

#ifdef C99_MACROS
#define dprintf(level,...) printf(__VA_ARGS__)
#endif

/* gcc vararg macros */
#define dprintf1(level, fmt, args...) printf(fmt, ## args)

#define MACRO_NOARGS()

#define TEST_CALL(f, ...) f(__VA_ARGS__)
#define TEST_CONST()      123

#define AAA 3
#undef AAA
#define AAA 4

#ಯದಿ 1
#define B3 1
#ನೋಚೇದ್ಯದಿ 1
#define B3 2
#ನೋಚೇದ್ಯದಿ 0
#define B3 3
#ಅನ್ಯಥಾ
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

ಪೂರ್ಣಾಙ್ಕ qq(ಪೂರ್ಣಾಙ್ಕ x)
{
    ಪ್ರತ್ಯಾಗಮ x + 40;
}
#define qq(x) x

#define spin_lock(lock) ಕುರು { } ಯಾವತ್ (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

ಶೂನ್ಯ macro_test(ಶೂನ್ಯ)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(ಮೇಲಿನ_2, ಕೆಳಗಿನ_2));
    printf("s2=%s\n", xglue(ಮೇಲಿನ_2, ಕೆಳಗಿನ_2));
    printf("s3=%s\n", str("c"));
    printf("s4=%s\n", str(a1));
    printf("B3=%d\n", B3);

    printf("onetwothree=%d\n", onetwothree);

#ifdef A
    printf("A defined\n");
#endif
#ifdef B
    printf("B defined\n");
#endif
#ifdef A
    printf("A defined\n");
#ಅನ್ಯಥಾ
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#ಅನ್ಯಥಾ
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#ಅನ್ಯಥಾ
    printf("B1 not defined\n");
#endif
#ಅನ್ಯಥಾ
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#ಅನ್ಯಥಾ
    printf("B2 not defined\n");
#endif
#endif

#ಯದಿ 1+1
    printf("test true1\n");
#endif
#ಯದಿ 0
    printf("test true2\n");
#endif
#ಯದಿ 1-1
    printf("test true3\n");
#endif
#ಯದಿ defined(A)
    printf("test trueA\n");
#endif
#ಯದಿ defined(B)
    printf("test trueB\n");
#endif

#ಯದಿ 0
    printf("test 0\n");
#ನೋಚೇದ್ಯದಿ 0
    printf("test 1\n");
#ನೋಚೇದ್ಯದಿ 2
    printf("test 2\n");
#ಅನ್ಯಥಾ
    printf("test 3\n");
#endif

    MACRO_NOARGS();

    printf("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#ifdef C99_MACROS
    printf("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#endif
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    printf("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    printf("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        ಪೂರ್ಣಾಙ್ಕ a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(ಸಂದೇಶ) printf("%s\n",ಸಂದೇಶ)

#define MF_t printf("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    printf("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#define qq1(x) 1
    printf("qq1=%d\n", qq1( ));

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

    printf("basefromheader %s\n", get_basefile_from_header());
    printf("base %s\n", __BASE_FILE__);
#ಯದಿ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ಧ್ರುವ ವರ್ಣ *fn = get_file_from_header();
      ಯದಿ (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      printf("filefromheader %s\n", fn);
    }
#endif

    printf("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_second = 1;
    have_included_42test_h_third = 1;

    /* Check that we don't complain about stray \ here */
    printf("print a backslash: %s\n", stringify(\\));
}


ಸ್ಥಿರ ಶೂನ್ಯ print_ಅಂಕೆ(ವರ್ಣ *fn, ಪೂರ್ಣಾಙ್ಕ ಸಾಲು, ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ) {
    printf("fn %s, line %d, num %d\n", fn, ಸಾಲು, ಅಂಕೆ);
}

ಶೂನ್ಯ recursive_macro_test(ಶೂನ್ಯ)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_ಅಂಕೆ(x) print_ಅಂಕೆ(__FILE__,__LINE__,x)
    print_ಅಂಕೆ(123);
    WRAP(print_ಅಂಕೆ(123));
    WRAP(WRAP(print_ಅಂಕೆ(123)));

ಸ್ಥಿರ ಸಂರಚನಾ recursive_macro { ಪೂರ್ಣಾಙ್ಕ rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#ಯದಿ __TINYC__
ಪೂರ್ಣಾಙ್ಕ op(a, b)
{
    ಪ್ರತ್ಯಾಗಮ a / b;
}

ಪೂರ್ಣಾಙ್ಕ ret(a)
{
    ಯದಿ (a == 2)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಯದಿ (a == 3)
        ಪ್ರತ್ಯಾಗಮ 2;
    ಪ್ರತ್ಯಾಗಮ 0;
}
#endif

#ಯದಿ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
ವರ್ಣ str_ag1[] = "b";
ವರ್ಣ str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
ವರ್ಣ str_ag3[] = { "ab"[1], 0 };
ವರ್ಣ str_x[2] = { "xy" "z"[2], 0 };
#endif
ವರ್ಣ *str_ar[] = { "one", "two" };
ಸಂರಚನಾ str_SS {unsigned ವರ್ಣ a[3], b; };
ಸಂರಚನಾ str_SS str_sinit15 = { "r" };
ಸಂರಚನಾ str_SS str_sinit16[] = { { "q" }, 2 };

ಸ್ಥಿರ ಶೂನ್ಯ string_test2()
{
    ವರ್ಣ *p = "hello";
    ವರ್ಣ a3[2] = { "p" };
    ವರ್ಣ a4[2] = { "ab" "c"[2], 0 };
    ವರ್ಣ *pa1 = "def" + 1;
    ವರ್ಣ *pa2 = { "xyz" + 1 };
    ಪೂರ್ಣಾಙ್ಕ i = 0;
    ಸಂರಚನಾ str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    ವರ್ಣ str_ag3[] = { "ab"[1], 0 };
    ವರ್ಣ str_x[2] = { "xy" "z"[2], 0 };
#endif
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
    printf("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

ಶೂನ್ಯ ps(ಧ್ರುವ ವರ್ಣ *s)
{
    ಪೂರ್ಣಾಙ್ಕ c;
    ಯಾವತ್ (1) {
        c = *s;
        ಯದಿ (c == 0)
            ಭಙ್ಗ;
        printf("%c", c);
        s++;
    }
}

ಧ್ರುವ ವರ್ಣ foo1_string[] = "\
bar\n\
test\14\
1";

ಶೂನ್ಯ string_test()
{
    unsigned ಪೂರ್ಣಾಙ್ಕ b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#ಯದಿ 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    ಯಾವತ್ ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    ಯಾವತ್ (b != 0x80000000) {
        ಅಂಕೆ(b);
        b = b * 2;
    }
    string_test2();
}


ಶೂನ್ಯ if1t(ಪೂರ್ಣಾಙ್ಕ n, ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಯದಿ (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    ಯದಿ (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    ಯದಿ (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    ಯದಿ (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    ಯದಿ (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    ಯದಿ (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    ಯದಿ (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    ಯದಿ (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    ಯದಿ (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ಯದಿ (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ಯದಿ (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ಯದಿ (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ಯದಿ (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ಯದಿ (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

ಶೂನ್ಯ if2t(ಶೂನ್ಯ)
{
    ಯದಿ (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

ಶೂನ್ಯ if3t(ಶೂನ್ಯ)
{
    ಚಞ್ಚಲ long long i = 1;
    ಯದಿ (i <= 18446744073709551615ULL)
      ;
    ಅನ್ಯಥಾ
      printf ("if3t:wrong 1\n");
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
    ಪೂರ್ಣಾಙ್ಕ i;
    i = 0;
    ಯಾವತ್ (i < 10)
        printf("%d", i++);
    printf("\n");
    ಪ್ರತಿ(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    ಕುರು {
        printf("%d", i++);
    } ಯಾವತ್ (i < 10);
    printf("\n");

    ವರ್ಣ ಎಣಿಕೆ_2 = 123;
    /* c99 for loop init test */
    ಪ್ರತಿ (size_t ಎಣಿಕೆ_2 = 1; ಎಣಿಕೆ_2 < 3; ಎಣಿಕೆ_2++)
        printf("count=%d\n", ಎಣಿಕೆ_2);
    printf("count = %d\n", ಎಣಿಕೆ_2);

    /* break/continue tests */
    i = 0;
    ಯಾವತ್ (1) {
        ಯದಿ (i == 6)
            ಭಙ್ಗ;
        i++;
        ಯದಿ (i == 3)
            ಅನುವರ್ತ;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    ಕುರು {
        ಯದಿ (i == 6)
            ಭಙ್ಗ;
        i++;
        ಯದಿ (i == 3)
            ಅನುವರ್ತ;
        printf("%d", i);
    } ಯಾವತ್(1);
    printf("\n");

    ಪ್ರತಿ(i = 0;i < 10;i++) {
        ಯದಿ (i == 3)
            ಅನುವರ್ತ;
        printf("%d", i);
    }
    printf("\n");
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ typedef_and_label;

ಶೂನ್ಯ goto_test()
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಸ್ಥಿರ ಶೂನ್ಯ *label_table[3] = { &&label1, &&label2, &&label3 };
    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    printf("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    ಯದಿ (i >= 10) 
        ಗಚ್ಛ s_end;
    printf("%d", i);
    i++;
    ಗಚ್ಛ s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    ಪ್ರತಿ(i=0;i<3;i++) {
        ಗಚ್ಛ *label_table[i];
    label1:
        printf("label1\n");
        ಗಚ್ಛ next;
    label2:
        printf("label2\n");
        ಗಚ್ಛ next;
    label3:
        printf("label3\n");
    next: ;
    }
}

ಗಣನಾ {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ಗಣನಾ test {
    E5 = 1000,
};

ಸಂರಚನಾ S_enum {
    ಗಣನಾ {E6 = 42, E7, E8} e:8;
};

ಗಣನಾ ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

ಗಣನಾ { BIASU = -1U<<31 };
ಗಣನಾ { BIASS = -1 << 31 };

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ getint(ಪೂರ್ಣಾಙ್ಕ i)
{
  ಯದಿ (i)
    ಪ್ರತ್ಯಾಗಮ 0;
  ಅನ್ಯಥಾ
    ಪ್ರತ್ಯಾಗಮ (ಪೂರ್ಣಾಙ್ಕ)(-1U << 31);
}

ಶೂನ್ಯ enum_test()
{
    ಗಣನಾ test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    ಸಂರಚನಾ S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    ಯದಿ (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    ಅನ್ಯಥಾ
      printf("enum unsigned: wrong\n");
    ಯದಿ (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    ಅನ್ಯಥಾ
      printf("enum unsigned: wrong\n");
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *my_ptr;

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ mytype1;
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ mytype2;

ಶೂನ್ಯ typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    ಪೂರ್ಣಾಙ್ಕ b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

ಶೂನ್ಯ forward_test()
{
    forward_ref();
    forward_ref();
}


ಶೂನ್ಯ forward_ref(ಶೂನ್ಯ)
{
    printf("forward ok\n");
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ struct1 {
    ಪೂರ್ಣಾಙ್ಕ f1;
    ಪೂರ್ಣಾಙ್ಕ f2, f3;
    ಸಙ್ಘ union1 {
        ಪೂರ್ಣಾಙ್ಕ v1;
        ಪೂರ್ಣಾಙ್ಕ v2;
    } u;
    ವರ್ಣ str[3];
} struct1;

ಸಂರಚನಾ struct2 {
    ಪೂರ್ಣಾಙ್ಕ a;
    ವರ್ಣ b;
};

ಸಙ್ಘ union2 {
    ಪೂರ್ಣಾಙ್ಕ w1;
    ಪೂರ್ಣಾಙ್ಕ w2;
};

ಸಂರಚನಾ struct1 st1, st2;

ಸಂರಚನಾ empty_mem {
    /* nothing */ ;
    ಪೂರ್ಣಾಙ್ಕ x;
};

ಪೂರ್ಣಾಙ್ಕ tab[3];
ಪೂರ್ಣಾಙ್ಕ tab2[3][2];

ಪೂರ್ಣಾಙ್ಕ g;

ಶೂನ್ಯ f1(ಪೂರ್ಣಾಙ್ಕ g)
{
    printf("g1=%d\n", g);
}

ಶೂನ್ಯ scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        ಪೂರ್ಣಾಙ್ಕ g;
        g = 3;
        printf("g3=%d\n", g);
        {
            ಪೂರ್ಣಾಙ್ಕ g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

ಪೂರ್ಣಾಙ್ಕ st2_i;
ಪೂರ್ಣಾಙ್ಕ *st2_p = &st2_i;
ಶೂನ್ಯ scope2_test()
{
    ವರ್ಣ a[50];
    st2_i = 42;
    ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ st2_i = 1; st2_i < 10; st2_i++) {
        ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ st_global1;
ಪೂರ್ಣಾಙ್ಕ st_global1=42;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ st_global1;
ಪೂರ್ಣಾಙ್ಕ st_global1;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ st_global2;
ಪೂರ್ಣಾಙ್ಕ st_global2;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ st_global2;
ಪೂರ್ಣಾಙ್ಕ st_global2;

ಶೂನ್ಯ array_test()
{
    ಪೂರ್ಣಾಙ್ಕ i, j, a[4];

    printf("sizeof(a) = %d\n", ಪರಿಮಾಣ(a));
    printf("sizeof(\"a\") = %d\n", ಪರಿಮಾಣ("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", ಪರಿಮಾಣ(__func__));
#endif
    printf("sizeof tab %d\n", ಪರಿಮಾಣ(tab));
    printf("sizeof tab2 %d\n", ಪರಿಮಾಣ tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    ಪ್ರತಿ(i=0;i<3;i++)
        ಪ್ರತಿ(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    ಪ್ರತಿ(i=0;i<3*2;i++) {
        printf(" %3d", ((ಪೂರ್ಣಾಙ್ಕ *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", ಪರಿಮಾಣ(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", ಪರಿಮಾಣ(ptrdiff_t));
}

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_test()
{
    ಪೂರ್ಣಾಙ್ಕ a, b;
    a = 0;
    printf("%d\n", a += 1);
    printf("%d\n", a -= 2);
    printf("%d\n", a *= 31232132);
    printf("%d\n", a /= 4);
    printf("%d\n", a %= 20);
    printf("%d\n", a &= 6);
    printf("%d\n", a ^= 7);
    printf("%d\n", a |= 8);
    printf("%d\n", a >>= 3);
    printf("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    printf("%d\n", a + 1);
    printf("%d\n", a - 2);
    printf("%d\n", a * 312);
    printf("%d\n", a / 4);
    printf("%d\n", b / 4);
    printf("%d\n", (unsigned)b / 4);
    printf("%d\n", a % 20);
    printf("%d\n", b % 20);
    printf("%d\n", (unsigned)b % 20);
    printf("%d\n", a & 6);
    printf("%d\n", a ^ 7);
    printf("%d\n", a | 8);
    printf("%d\n", a >> 3);
    printf("%d\n", b >> 3);
    printf("%d\n", (unsigned)b >> 3);
    printf("%d\n", a << 4);
    printf("%d\n", ~a);
    printf("%d\n", -a);
    printf("%d\n", +a);

    printf("%d\n", 12 + 1);
    printf("%d\n", 12 - 2);
    printf("%d\n", 12 * 312);
    printf("%d\n", 12 / 4);
    printf("%d\n", 12 % 20);
    printf("%d\n", 12 & 6);
    printf("%d\n", 12 ^ 7);
    printf("%d\n", 12 | 8);
    printf("%d\n", 12 >> 2);
    printf("%d\n", 12 << 4);
    printf("%d\n", ~12);
    printf("%d\n", -12);
    printf("%d\n", +12);
    printf("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

ಪೂರ್ಣಾಙ್ಕ isid(ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪ್ರತ್ಯಾಗಮ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

ಪೂರ್ಣಾಙ್ಕ vstack[10], *vstack_ptr;

ಶೂನ್ಯ vpush(ಪೂರ್ಣಾಙ್ಕ vt, ಪೂರ್ಣಾಙ್ಕ vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

ಶೂನ್ಯ vpop(ಪೂರ್ಣಾಙ್ಕ *ft, ಪೂರ್ಣಾಙ್ಕ *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

ಶೂನ್ಯ expr2_test()
{
    ಪೂರ್ಣಾಙ್ಕ a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

ಪೂರ್ಣಾಙ್ಕ const_len_ar[ಪರಿಮಾಣ(1/0)]; /* div-by-zero, but in unevaluated context */

ಶೂನ್ಯ constant_ಅಭಿವ್ಯಕ್ತಿ_test()
{
    ಪೂರ್ಣಾಙ್ಕ a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", ಪರಿಮಾಣ(const_len_ar));
}

ಪೂರ್ಣಾಙ್ಕ tab4[10];

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_ptr_test()
{
    ಪೂರ್ಣಾಙ್ಕ arr[10], *p, *q;
    ಪೂರ್ಣಾಙ್ಕ i = -1;

    p = tab4;
    q = tab4 + 10;
    printf("diff=%d\n", q - p);
    p++;
    printf("inc=%d\n", p - tab4);
    p--;
    printf("dec=%d\n", p - tab4);
    ++p;
    printf("inc=%d\n", p - tab4);
    --p;
    printf("dec=%d\n", p - tab4);
    printf("add=%d\n", p + 3 - tab4);
    printf("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (ಪೂರ್ಣಾಙ್ಕ *)((ವರ್ಣ *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ಸಂರಚನಾ size12 {
            ಪೂರ್ಣಾಙ್ಕ i, j, k;
        };
        ಸಂರಚನಾ size12 s[2], *sp = s;
        ಪೂರ್ಣಾಙ್ಕ i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (ಪೂರ್ಣಾಙ್ಕ*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (ಪೂರ್ಣಾಙ್ಕ)((p - q) / 3));
}

ಶೂನ್ಯ ಅಭಿವ್ಯಕ್ತಿ_cmp_test()
{
    ಪೂರ್ಣಾಙ್ಕ a, b;
    a = -1;
    b = 1;
    printf("%d\n", a == a);
    printf("%d\n", a != a);

    printf("%d\n", a < b);
    printf("%d\n", a <= b);
    printf("%d\n", a <= a);
    printf("%d\n", b >= a);
    printf("%d\n", a >= a);
    printf("%d\n", b > a);

    printf("%d\n", (unsigned)a < b);
    printf("%d\n", (unsigned)a <= b);
    printf("%d\n", (unsigned)a <= a);
    printf("%d\n", (unsigned)b >= a);
    printf("%d\n", (unsigned)a >= a);
    printf("%d\n", (unsigned)b > a);
}

ಸಂರಚನಾ empty {
};

ಸಂರಚನಾ aligntest1 {
    ವರ್ಣ a[10];
};

ಸಂರಚನಾ aligntest2 {
    ಪೂರ್ಣಾಙ್ಕ a;
    ವರ್ಣ b[10];
};

ಸಂರಚನಾ aligntest3 {
    ದ್ವಿಗುಣ a, b;
};

ಸಂರಚನಾ aligntest4 {
    ದ್ವಿಗುಣ a[0];
};

ಸಂರಚನಾ __attribute__((aligned(16))) aligntest5
{
    ಪೂರ್ಣಾಙ್ಕ i;
};
ಸಂರಚನಾ aligntest6
{
    ಪೂರ್ಣಾಙ್ಕ i;
} __attribute__((aligned(16)));
ಸಂರಚನಾ aligntest7
{
    ಪೂರ್ಣಾಙ್ಕ i;
};
ಸಂರಚನಾ aligntest5 altest5[2];
ಸಂರಚನಾ aligntest6 altest6[2];
ಪೂರ್ಣಾಙ್ಕ pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ಸಂರಚನಾ aligntest7 altest7[2] __attribute__((aligned(16)));

ಸಂರಚನಾ aligntest8
{
  ಪೂರ್ಣಾಙ್ಕ i;
} __attribute__((aligned(4096)));

ಸಂರಚನಾ Large {
    unsigned long flags;
    ಸಙ್ಘ {
	ಶೂನ್ಯ *u1;
	ಪೂರ್ಣಾಙ್ಕ *u2;
    };

    ಸಂರಚನಾ {
	ಸಙ್ಘ {
	    unsigned long index;
	    ಶೂನ್ಯ *freelist;
	};
	ಸಙ್ಘ {
	    unsigned long counters;
	    ಸಂರಚನಾ {
		ಪೂರ್ಣಾಙ್ಕ bla;
	    };
	};
    };

    ಸಙ್ಘ {
	ಸಂರಚನಾ {
	    long u3;
	    long u4;
	};
	ಶೂನ್ಯ *u5;
	ಸಂರಚನಾ {
	    unsigned long compound_head;
	    unsigned ಪೂರ್ಣಾಙ್ಕ compound_dtor;
	    unsigned ಪೂರ್ಣಾಙ್ಕ compound_order;
	};
    };
} __attribute__((aligned(2 * ಪರಿಮಾಣ(long))));

ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long long __attribute__((aligned(4))) unaligned_u64;

ಸಂರಚನಾ aligntest9 {
    unsigned ಪೂರ್ಣಾಙ್ಕ buf_nr;
    unaligned_u64 start_lba;
};

ಸಂರಚನಾ aligntest10 {
    unsigned ಪೂರ್ಣಾಙ್ಕ buf_nr;
    unsigned long long start_lba;
};

ಶೂನ್ಯ struct_test()
{
    struct1 *s;
    ಸಙ್ಘ union2 u;
    ಸಂರಚನಾ Large ls;

    printf("sizes: %d %d %d %d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ struct1),
           ಪರಿಮಾಣ(ಸಂರಚನಾ struct2),
           ಪರಿಮಾಣ(ಸಙ್ಘ union1),
           ಪರಿಮಾಣ(ಸಙ್ಘ union2));
    printf("offsets: %d\n", (ಪೂರ್ಣಾಙ್ಕ)((ವರ್ಣ*)&st1.u.v1 - (ವರ್ಣ*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    printf("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    printf("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    printf("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    printf("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    printf("str_addr=%x\n", (ಪೂರ್ಣಾಙ್ಕ)(uintptr_t)st1.str - (ಪೂರ್ಣಾಙ್ಕ)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest1), __alignof__(ಸಂರಚನಾ aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest2), __alignof__(ಸಂರಚನಾ aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest3), __alignof__(ಸಂರಚನಾ aligntest3));
#ಯದಿ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest4), __alignof__(ಸಂರಚನಾ aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest5), __alignof__(ಸಂರಚನಾ aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest6), __alignof__(ಸಂರಚನಾ aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest7), __alignof__(ಸಂರಚನಾ aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest8), __alignof__(ಸಂರಚನಾ aligntest8));
#ಯದಿ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest9), __alignof__(ಸಂರಚನಾ aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(ಸಂರಚನಾ aligntest10), __alignof__(ಸಂರಚನಾ aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           ಪರಿಮಾಣ(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ಯದಿ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", ಪರಿಮಾಣ(ಸಂರಚನಾ empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(ಸಂರಚನಾ empty));

    printf("Large: sizeof=%d\n", ಪರಿಮಾಣ(ls));
    memset(&ls, 0, ಪರಿಮಾಣ(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (ಪೂರ್ಣಾಙ್ಕ)((ವರ್ಣ*)&ls.compound_head - (ವರ್ಣ*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ __csf(ಪೂರ್ಣಾಙ್ಕ x) { ಪ್ರತ್ಯಾಗಮ x; }
ಸ್ಥಿರ ಶೂನ್ಯ *_csf = __csf;
#define csf(t,n) ((t(*)(ಪೂರ್ಣಾಙ್ಕ))_csf)(n)

/* XXX: depend on endianness */
ಶೂನ್ಯ char_short_test()
{
    ಪೂರ್ಣಾಙ್ಕ var1, var2;
    signed ವರ್ಣ var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed ವರ್ಣ *)&var1, *(signed ವರ್ಣ *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned ವರ್ಣ *)&var1, *(unsigned ವರ್ಣ *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(ಪೂರ್ಣಾಙ್ಕ *)&var1, *(ಪೂರ್ಣಾಙ್ಕ *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned ಪೂರ್ಣಾಙ್ಕ *)&var1, *(unsigned ಪೂರ್ಣಾಙ್ಕ *)&var2);
    *(signed ವರ್ಣ *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(ಪೂರ್ಣಾಙ್ಕ *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed ವರ್ಣ)(var1 + 1), (signed ವರ್ಣ)(var4 + 1));
#ಯದಿ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned ವರ್ಣ,0x89898989);
    var4 = csf(signed ವರ್ಣ,0xabababab);
#ifdef __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#endif
    printf("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    printf("promote char/short fumcret VA %d %d %d %d\n",
        csf(unsigned short,0xcdcdcdcd),
        csf(short,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#endif
    var3 = -10;
    var1 = (signed ವರ್ಣ)(unsigned ವರ್ಣ)(var3 + 1);
    var4 = (signed ವರ್ಣ)(unsigned ವರ್ಣ)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(ಪೂರ್ಣಾಙ್ಕ)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed ವರ್ಣ)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Sym {
    ಪೂರ್ಣಾಙ್ಕ v;
    ಪೂರ್ಣಾಙ್ಕ t;
    ಪೂರ್ಣಾಙ್ಕ c;
    ಸಂರಚನಾ Sym *next;
    ಸಂರಚನಾ Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ toupper1(ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪ್ರತ್ಯಾಗಮ TOUPPER(a);
}

ಸ್ಥಿರ unsigned ಪೂರ್ಣಾಙ್ಕ calc_vm_flags(unsigned ಪೂರ್ಣಾಙ್ಕ prot)
{
  unsigned ಪೂರ್ಣಾಙ್ಕ prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ಪ್ರತ್ಯಾಗಮ prot_bits;
}

ಗಣನಾ cast_enum { FIRST, LAST };

ಸ್ಥಿರ ಶೂನ್ಯ tst_cast(ಗಣನಾ cast_enum ce)
{
    printf("%d\n", ce);
}

ಶೂನ್ಯ bool_test()
{
    ಪೂರ್ಣಾಙ್ಕ *s, a, b, t, f, i;

    a = 0;
    s = (ಶೂನ್ಯ*)0;
    printf("!s=%d\n", !s);

    ಯದಿ (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ಯದಿ 1 && 1
    printf("a1\n");
#endif
#ಯದಿ 1 || 0
    printf("a2\n");
#endif
#ಯದಿ 1 ? 0 : 1
    printf("a3\n");
#endif
#ಯದಿ 0 ? 0 : 1
    printf("a4\n");
#endif

    a = 4;
    printf("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    printf("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    printf("exp=%d\n", f == (32 <= a && a <= 3));
    printf("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    printf("type of bool: %d\n", (ಪೂರ್ಣಾಙ್ಕ) ( (~ ((unsigned ಪೂರ್ಣಾಙ್ಕ) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned ಪೂರ್ಣಾಙ್ಕ)0)) / 2 );
    /* test ? : cast */
    {
        ಪೂರ್ಣಾಙ್ಕ aspect_on;
        ಪೂರ್ಣಾಙ್ಕ aspect_native = 65536;
        ದ್ವಿಗುಣ bfu_aspect = 1.0;
        ಪೂರ್ಣಾಙ್ಕ aspect;
        ಪ್ರತಿ(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ v1 = 34 ? : -1; /* constant case */
        ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ v2 = 0 ? : -1; /* constant case */
        ಪೂರ್ಣಾಙ್ಕ a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    ಪ್ರತಿ(i=0;i<256;i++) {
        ಯದಿ (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ undefined_function(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ defined_function(ಶೂನ್ಯ);

#ifdef __clang__
ಪೂರ್ಣಾಙ್ಕ undefined_function(ಶೂನ್ಯ) {}
#endif

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ refer_to_undefined(ಶೂನ್ಯ)
{
  undefined_function();
}

ಶೂನ್ಯ optimize_out_test(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  ಪೂರ್ಣಾಙ್ಕ j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  ಯದಿ (0)
    printf("oo:%d\n", undefined_function());
  ಅನ್ಯಥಾ
    printf("oo:%d\n", defined_function());
  ಯದಿ (1)
    printf("oo:%d\n", defined_function());
  ಅನ್ಯಥಾ
    printf("oo:%d\n", undefined_function());
  ಯಾವತ್ (1) {
      printf("oow:%d\n", defined_function());
      ಭಙ್ಗ;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ವಿಕಲ್ಪ (j)
    ಪಕ್ಷ 1: ಭಙ್ಗ;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ಯಾವತ್ (1)
    ಭಙ್ಗ;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  ಕುರು
    ಭಙ್ಗ;
  ಯಾವತ್ (1);
  printf ("ool2:%d\n", defined_function());
  ಪ್ರತಿ (;;)
    ಭಙ್ಗ;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ಯಾವತ್ (1) {
	{
	  ಭಙ್ಗ;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ಯಾವತ್ (j) {
      ಯದಿ (j == 0)
	ಭಙ್ಗ; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ಯಾವತ್ (j) {
      ಯದಿ (1)
	j--;
      ಅನ್ಯಥಾ
	breakhere: ಭಙ್ಗ;
      printf("ool6:%d\n", defined_function());
      ಗಚ್ಛ breakhere;
  }
  j = 1;
  ಯಾವತ್ (j) {
      j--;
      ಅನುವರ್ತ;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ಯದಿ (0 && undefined_function())
    undefined_function();
  ಯದಿ (defined_function() && 0)
    undefined_function();
  ಯದಿ (0 && 0)
    undefined_function();
  ಯದಿ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ಯದಿ (1 || undefined_function())
    ;
  ಅನ್ಯಥಾ
    undefined_function();
  ಯದಿ (defined_function() || 1)
    ;
  ಅನ್ಯಥಾ
    undefined_function();
  ಯದಿ (1 || 1)
    ;
  ಅನ್ಯಥಾ
    undefined_function();
  ಯದಿ (defined_function() || 1 || undefined_function())
    ;
  ಅನ್ಯಥಾ
    undefined_function();

  ಯದಿ (defined_function() && 0)
    refer_to_undefined();

  ಯದಿ (0) {
      (ಶೂನ್ಯ)ಪರಿಮಾಣ( ({
		     ಕುರು { } ಯಾವತ್ (0);
		     0;
		     }) );
      undefined_function();
  }

  ಯದಿ (0) {
      ವಿಕಲ್ಪ (defined_function()) {
          ಪಕ್ಷ 0: undefined_function(); ಭಙ್ಗ;
          ಸ್ವಭಾವ: undefined_function(); ಭಙ್ಗ;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ಯದಿ (1)
    ಪ್ರತ್ಯಾಗಮ;
  printf ("oor:%d\n", undefined_function());
}

ಪೂರ್ಣಾಙ್ಕ defined_function(ಶೂನ್ಯ)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ i = 40;
  ಪ್ರತ್ಯಾಗಮ i++;
}

/* GCC accepts that */
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tab_reinit[];
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tab_reinit[10];

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tentative_ar[];
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ tentative_ar[] = {1,2,3};

ಪೂರ್ಣಾಙ್ಕ cinit1; /* a global variable can be defined several times without error ! */
ಪೂರ್ಣಾಙ್ಕ cinit1; 
ಪೂರ್ಣಾಙ್ಕ cinit1 = 0;
ಪೂರ್ಣಾಙ್ಕ *cinit2 = (ಪೂರ್ಣಾಙ್ಕ []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
ವರ್ಣ ಧ್ರುವ * ಧ್ರುವ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
ಶೂನ್ಯ *cinit52 = &(ಶೂನ್ಯ*){ (ಶೂನ್ಯ*) 52 };

#ಯದಿ __TINYC__ || __GNUC__ >= 6
ಪೂರ್ಣಾಙ್ಕ cinit4 = (ಪೂರ್ಣಾಙ್ಕ){44};
ಶೂನ್ಯ *cinit51 = (ಶೂನ್ಯ*){ (ಶೂನ್ಯ*) 51 };
ಸಂರಚನಾ _c6 { ಪೂರ್ಣಾಙ್ಕ a,b; } cinit6 = (ಸಂರಚನಾ _c6){61,62}, *cinit7 = &(ಸಂರಚನಾ _c6){71,72};
#ಅನ್ಯಥಾ
ಪೂರ್ಣಾಙ್ಕ cinit4 = 44;
ಶೂನ್ಯ *cinit51 = (ಶೂನ್ಯ*)51;
ಸಂರಚನಾ _c6 { ಪೂರ್ಣಾಙ್ಕ a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

ಶೂನ್ಯ compound_literal_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ *p, i;
    ವರ್ಣ *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (ಪೂರ್ಣಾಙ್ಕ)cinit51);
    printf("cinit52 : %d\n", *(ಪೂರ್ಣಾಙ್ಕ*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (ಪೂರ್ಣಾಙ್ಕ []){1, 2, 3};
    ಪ್ರತಿ(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    ಪ್ರತಿ(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (ವರ್ಣ *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (ವರ್ಣ *){ q };
    printf("q3=%s\n", q3);

    q = (ವರ್ಣ []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (ಪೂರ್ಣಾಙ್ಕ []){1, 2, cinit1 + 3};
    ಪ್ರತಿ(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    ಪ್ರತಿ(i=0;i<3;i++) {
        p = (ಪೂರ್ಣಾಙ್ಕ []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#ಯದಿ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ಪ್ರತ್ಯಾಗಮ a + b;
}

ಪೂರ್ಣಾಙ್ಕ kr_func2(a, b)
{
    ಪ್ರತ್ಯಾಗಮ a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    ಪ್ರತ್ಯಾಗಮ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
ವರ್ಣ invalid_function_def()[] {ಪ್ರತ್ಯಾಗಮ 0;}

#ಅನ್ಯಥಾ
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

ಶೂನ್ಯ ಅಂಕೆ(ಪೂರ್ಣಾಙ್ಕ n)
{
    ವರ್ಣ *tab, *p;
    tab = (ವರ್ಣ*)malloc(20); 
    p = tab;
    ಯಾವತ್ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ಯದಿ (n == 0)
            ಭಙ್ಗ;
    }
    ಯಾವತ್ (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    ಮುಕ್ತ(tab);
}

/* structure assignment tests */
ಸಂರಚನಾ structa1 {
    ಪೂರ್ಣಾಙ್ಕ f1;
    ವರ್ಣ f2;
};

ಶೂನ್ಯ struct_assign_test1(ಸಂರಚನಾ structa1 s1, ಪೂರ್ಣಾಙ್ಕ t, ಭಿನ್ನ f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ಸಂರಚನಾ structa1 struct_assign_test2(ಸಂರಚನಾ structa1 s1, ಪೂರ್ಣಾಙ್ಕ t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ಪ್ರತ್ಯಾಗಮ s1;
}

ಶೂನ್ಯ struct_assign_test(ಶೂನ್ಯ)
{
    ಸಂರಚನಾ S {
      ಸಂರಚನಾ structa1 lsta1, lsta2;
      ಪೂರ್ಣಾಙ್ಕ i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ಸ್ಥಿರ ಸಂರಚನಾ {
        ಶೂನ್ಯ (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

ಶೂನ್ಯ cast1(ವರ್ಣ a, short b, unsigned ವರ್ಣ c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

ವರ್ಣ bcast;
short scast;

ಶೂನ್ಯ cast_test()
{
    ಪೂರ್ಣಾಙ್ಕ a;
    ವರ್ಣ c;
    ವರ್ಣ tab[10];
    unsigned b,d;
    short s;
    ವರ್ಣ *p = ರಿಕ್ತ;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (ವರ್ಣ)(a + 1),
           (short)(a + 1),
           (unsigned ವರ್ಣ)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (ವರ್ಣ)0xfffff,
           (short)0xfffff,
           (unsigned ವರ್ಣ)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", ಪರಿಮಾಣ(c), ಪರಿಮಾಣ((ಪೂರ್ಣಾಙ್ಕ)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (ವರ್ಣ)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", ಪರಿಮಾಣ(+(ವರ್ಣ)'a'));
    printf("sizeof(-(char)'a') = %d\n", ಪರಿಮಾಣ(-(ವರ್ಣ)'a'));
    printf("sizeof(~(char)'a') = %d\n", ಪರಿಮಾಣ(-(ವರ್ಣ)'a'));

#ಯದಿ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (ಪೂರ್ಣಾಙ್ಕ)p, (unsigned ಪೂರ್ಣಾಙ್ಕ)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (ಶೂನ್ಯ *)a, (ಶೂನ್ಯ *)b, (ಶೂನ್ಯ *)c, (ಶೂನ್ಯ *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(ಪೂರ್ಣಾಙ್ಕ)ul);
}

/* initializers tests */
ಸಂರಚನಾ structinit1 {
    ಪೂರ್ಣಾಙ್ಕ f1;
    ವರ್ಣ f2;
    short f3;
    ಪೂರ್ಣಾಙ್ಕ farray[3];
};

ಪೂರ್ಣಾಙ್ಕ sinit1 = 2;
ಪೂರ್ಣಾಙ್ಕ sinit2 = { 3 };
ಪೂರ್ಣಾಙ್ಕ sinit3[3] = { 1, 2, {3}, };
ಪೂರ್ಣಾಙ್ಕ sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
ಪೂರ್ಣಾಙ್ಕ sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
ಪೂರ್ಣಾಙ್ಕ sinit6[] = { 1, 2, 3 };
ಪೂರ್ಣಾಙ್ಕ sinit7[] = { [2] = 3, [0] = 1, 2 };
ವರ್ಣ sinit8[] = "hello" "trala";

ಸಂರಚನಾ structinit1 sinit9 = { 1, 2, 3 };
ಸಂರಚನಾ structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ಸಂರಚನಾ structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

ವರ್ಣ *sinit12 = "hello world";
ವರ್ಣ *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
ವರ್ಣ sinit14[10] = { "abc" };
ಪೂರ್ಣಾಙ್ಕ sinit15[3] = { ಪರಿಮಾಣ(sinit15), 1, 2 };

ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ a[3], b; } sinit16[] = { { 1 }, 2 };

ಸಂರಚನಾ bar {
        ವರ್ಣ *s;
        ಪೂರ್ಣಾಙ್ಕ len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

ಪೂರ್ಣಾಙ್ಕ sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ಸಂರಚನಾ complexinit0 {
    ಪೂರ್ಣಾಙ್ಕ a;
    ಪೂರ್ಣಾಙ್ಕ b;
};

ಸಂರಚನಾ complexinit {
    ಪೂರ್ಣಾಙ್ಕ a;
    ಧ್ರುವ ಸಂರಚನಾ complexinit0 *b;
};

ಧ್ರುವ ಸ್ಥಿರ ಸಂರಚನಾ complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ಧ್ರುವ ಸಂರಚನಾ complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ಸಂರಚನಾ complexinit2 {
	ಪೂರ್ಣಾಙ್ಕ a;
	ಪೂರ್ಣಾಙ್ಕ b[];
};

ಸಂರಚನಾ complexinit2 cix20;

ಸಂರಚನಾ complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ಸಂರಚನಾ complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
ಪೂರ್ಣಾಙ್ಕ sinit23[2] = { "astring" ? ಪರಿಮಾಣ("astring") : -1,
		   &sinit23 ? 42 : -1 };

ಪೂರ್ಣಾಙ್ಕ sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ಸಂರಚನಾ bf_SS {unsigned ಪೂರ್ಣಾಙ್ಕ bit:1,bits31:31; };
ಸಂರಚನಾ bf_SS bf_init = { .bit = 1 };
ಸಂರಚನಾ bfn_SS {ಪೂರ್ಣಾಙ್ಕ a,b; ಸಂರಚನಾ bf_SS c; ಪೂರ್ಣಾಙ್ಕ d,e; };
ಸಂರಚನಾ bfn_SS bfn_init = { .c.bit = 1 };
ಸಂರಚನಾ bfa_SS {ಪೂರ್ಣಾಙ್ಕ a,b; ಸಂರಚನಾ bf_SS c[3]; ಪೂರ್ಣಾಙ್ಕ d,e; };
ಸಂರಚನಾ bfa_SS bfa_init = { .c[1].bit = 1 };
ಸಂರಚನಾ bf_SS bfaa_init[3] = { [1].bit = 1 };
ಸಂರಚನಾ bf_SS bfaa_vinit[] = { [2].bit = 1 };
ಸಂರಚನಾ b2_SS {long long ಪೂರ್ಣಾಙ್ಕ field : 52; long long ಪೂರ್ಣಾಙ್ಕ pad : 12; };
ಸಂರಚನಾ b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ external_inited = 42;

ಶೂನ್ಯ init_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ linit1 = 2;
    ಪೂರ್ಣಾಙ್ಕ linit2 = { 3 };
    ಪೂರ್ಣಾಙ್ಕ linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    ಪೂರ್ಣಾಙ್ಕ linit6[] = { 1, 2, 3 };
    ಪೂರ್ಣಾಙ್ಕ i, j;
    ವರ್ಣ linit8[] = "hello" "trala";
    ಪೂರ್ಣಾಙ್ಕ linit12[10] = { 1, 2 };
    ಪೂರ್ಣಾಙ್ಕ linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    ವರ್ಣ linit14[10] = "abc";
    ಪೂರ್ಣಾಙ್ಕ linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ಸಂರಚನಾ linit16 { ಪೂರ್ಣಾಙ್ಕ a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    ಪೂರ್ಣಾಙ್ಕ linit17 = ಪರಿಮಾಣ(linit17);
    ಪೂರ್ಣಾಙ್ಕ zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    ಪೂರ್ಣಾಙ್ಕ linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ಸಂರಚನಾ bf_SS bf_finit = { .bit = 1 };
    ಸಂರಚನಾ bfn_SS bfn_finit = { .c.bit = 1 };
    ಸಂರಚನಾ bfa_SS bfa_finit = { .c[1].bit = 1 };
    ಸಂರಚನಾ bf_SS bfaa_finit[3] = { [1].bit = 1 };
    ಸಂರಚನಾ bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    ಸಂರಚನಾ b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           ಪರಿಮಾಣ(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", ಪರಿಮಾಣ(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           ಪರಿಮಾಣ(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    printf("sinit8=%s\n", sinit8);
    printf("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    printf("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    printf("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    ಪ್ರತಿ(i=0;i<3;i++)
        ಪ್ರತಿ(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", ಪರಿಮಾಣ(linit6));
    printf("linit8=%d %s\n", ಪರಿಮಾಣ(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           ಪರಿಮಾಣ(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    ಪ್ರತಿ(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    ಪ್ರತಿ(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    ಪ್ರತಿ(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    ಪ್ರತಿ(i=0;i<10;i++) printf(" %d", linit15[i]);
    printf("\n");
    printf("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    printf("linit17=%d\n", linit17);
    printf("sinit15=%d\n", sinit15[0]);
    printf("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    printf("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    ಪ್ರತಿ(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", ಪರಿಮಾಣ cix20, ಪರಿಮಾಣ cix21, ಪರಿಮಾಣ cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", ಪರಿಮಾಣ(sinit19), ಪರಿಮಾಣ(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", ಪರಿಮಾಣ(sinit21), ಪರಿಮಾಣ(sinit22));
    printf("arrtype6: %d\n", ಪರಿಮಾಣ(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    ಪ್ರತಿ (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

ಶೂನ್ಯ switch_uc(unsigned ವರ್ಣ uc)
{
	ವಿಕಲ್ಪ (uc) {
	    ಪಕ್ಷ 0xfb ... 0xfe:
		printf("ucsw:1\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 0xff:
		printf("ucsw:2\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 0 ... 5:
		printf("ucsw:3\n");
		ಭಙ್ಗ;
	    ಸ್ವಭಾವ:
		printf("ucsw: broken!\n");
	}
}

ಶೂನ್ಯ switch_sc(signed ವರ್ಣ sc)
{
	ವಿಕಲ್ಪ (sc) {
	    ಪಕ್ಷ -5 ... -2:
		printf("scsw:1\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ -1:
		printf("scsw:2\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 0 ... 5:
		printf("scsw:3\n");
		ಭಙ್ಗ;
	    ಸ್ವಭಾವ:
		printf("scsw: broken!\n");
	}
}

ಶೂನ್ಯ switch_test()
{
    ಪೂರ್ಣಾಙ್ಕ i;
    unsigned long long ull;
    long long ll;

    ಪ್ರತಿ(i=0;i<15;i++) {
        ವಿಕಲ್ಪ(i) {
        ಪಕ್ಷ 0:
        ಪಕ್ಷ 1:
            printf("a");
            ಭಙ್ಗ;
        ಸ್ವಭಾವ:
            printf("%d", i);
            ಭಙ್ಗ;
        ಪಕ್ಷ 8 ... 12:
            printf("c");
            ಭಙ್ಗ;
        ಪಕ್ಷ 3:
            printf("b");
            ಭಙ್ಗ;
        ಪಕ್ಷ 0xc33c6b9fU:
        ಪಕ್ಷ 0x7c9eeeb9U:
            ಭಙ್ಗ;
        }
    }
    printf("\n");

    ಪ್ರತಿ (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	ವಿಕಲ್ಪ (ull) {
	    ಪಕ್ಷ 1ULL << 61:
		printf("ullsw:1\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 2ULL << 61:
		printf("ullsw:2\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 3ULL << 61:
		printf("ullsw:3\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 4ULL << 61:
		printf("ullsw:4\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 5ULL << 61:
		printf("ullsw:5\n");
		ಭಙ್ಗ;
	    ಸ್ವಭಾವ:
		printf("ullsw: broken!\n");
	}
    }

    ಪ್ರತಿ (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	ವಿಕಲ್ಪ (ll) {
	    ಪಕ್ಷ 1LL << 61:
		printf("llsw:1\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 2LL << 61:
		printf("llsw:2\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 3LL << 61:
		printf("llsw:3\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 4LL << 61:
		printf("llsw:4\n");
		ಭಙ್ಗ;
	    ಪಕ್ಷ 5LL << 61:
		printf("llsw:5\n");
		ಭಙ್ಗ;
	    ಸ್ವಭಾವ:
		printf("llsw: broken!\n");
	}
    }

    ಪ್ರತಿ (i = -5; i <= 5; i++) {
	switch_uc((unsigned ವರ್ಣ)i);
    }

    ಪ್ರತಿ (i = -5; i <= 5; i++) {
	switch_sc ((signed ವರ್ಣ)i);
    }
}

/* ISOC99 _Bool type */
ಶೂನ್ಯ c99_bool_test(ಶೂನ್ಯ)
{
#ifdef BOOL_ISOC99
    ಪೂರ್ಣಾಙ್ಕ a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", ಪರಿಮಾಣ(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           ಪರಿಮಾಣ ((ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ)a ? b : b2));
#endif
}

ಶೂನ್ಯ bitfield_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a;
    short sa;
    unsigned ವರ್ಣ ca;
    ಸಂರಚನಾ sbf1 {
        ಪೂರ್ಣಾಙ್ಕ f1 : 3;
        ಪೂರ್ಣಾಙ್ಕ : 2;
        ಪೂರ್ಣಾಙ್ಕ f2 : 1;
        ಪೂರ್ಣಾಙ್ಕ : 0;
        ಪೂರ್ಣಾಙ್ಕ f3 : 5;
        ಪೂರ್ಣಾಙ್ಕ f4 : 7;
        unsigned ಪೂರ್ಣಾಙ್ಕ f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", ಪರಿಮಾಣ(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    printf("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    printf("%d %d\n", sa, ca);

    st1.f1 = 7;
    ಯದಿ (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    ಅನ್ಯಥಾ 
        printf("st1.f1 != -1\n");
    ಯದಿ (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    ಅನ್ಯಥಾ 
        printf("st1.f2 != -1\n");

    ಸಂರಚನಾ sbf2 {
        long long f1 : 45;
        long long : 2;
        long long f2 : 35;
        unsigned long long f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (long long)a << 25;
    st2.f3 = a;
    st2.f2++;
    printf("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#ಯದಿ 0
    Disabled ಪ್ರತಿ now until further clarification re GCC compatibility
    ಸಂರಚನಾ sbf3 {
        ಪೂರ್ಣಾಙ್ಕ f1 : 7;
        ಪೂರ್ಣಾಙ್ಕ f2 : 1;
        ವರ್ಣ f3;
        ಪೂರ್ಣಾಙ್ಕ f4 : 8;
        ಪೂರ್ಣಾಙ್ಕ f5 : 1;
        ಪೂರ್ಣಾಙ್ಕ f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", ಪರಿಮಾಣ(st3));
#endif

    ಸಂರಚನಾ sbf4 {
	ಪೂರ್ಣಾಙ್ಕ x : 31;
	ವರ್ಣ y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    ಸಂರಚನಾ sbf5 {
	ಪೂರ್ಣಾಙ್ಕ a;
	ವರ್ಣ b;
	ಪೂರ್ಣಾಙ್ಕ x : 12, y : 4, : 0, : 4, z : 3;
	ವರ್ಣ c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ಸಂರಚನಾ sbf6 {
	short x : 12;
	unsigned ವರ್ಣ y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#ಅನ್ಯಥಾ
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
ದ್ವಿಗುಣ strtod(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr);

#ಯದಿ defined(_WIN32)
ಭಿನ್ನ strtof(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr) {ಪ್ರತ್ಯಾಗಮ (ಭಿನ್ನ)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr) {ಪ್ರತ್ಯಾಗಮ (LONG_DOUBLE)strtod(nptr, endptr);}
#ಅನ್ಯಥಾ
ಭಿನ್ನ strtof(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr);
LONG_DOUBLE strtold(ಧ್ರುವ ವರ್ಣ *nptr, ವರ್ಣ **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
ಶೂನ್ಯ prefix ## cmp(type a, type b)\
{\
    printf("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    printf(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    printf(fmt "\n", ++a);\
    printf(fmt "\n", a++);\
    printf(fmt "\n", a);\
    b = 0;\
    printf("%d %d\n", !a, !b);\
}\
ಶೂನ್ಯ prefix ## fcast(type a)\
{\
    ಭಿನ್ನ fa;\
    ದ್ವಿಗುಣ da;\
    LONG_DOUBLE la;\
    ಪೂರ್ಣಾಙ್ಕ ia;\
    long long llia;\
    unsigned ಪೂರ್ಣಾಙ್ಕ ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (ಪೂರ್ಣಾಙ್ಕ)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned ಪೂರ್ಣಾಙ್ಕ)a;\
    llua = (unsigned long long)a;\
    printf("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    printf("itof: " fmt "\n", b);\
    b = ua;\
    printf("utof: " fmt "\n", b);\
    b = llia;\
    printf("lltof: " fmt "\n", b);\
    b = llua;\
    ಯದಿ (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
ಭಿನ್ನ prefix ## retf(type a) { ಪ್ರತ್ಯಾಗಮ a; }\
ದ್ವಿಗುಣ prefix ## retd(type a) { ಪ್ರತ್ಯಾಗಮ a; }\
LONG_DOUBLE prefix ## retld(type a) { ಪ್ರತ್ಯಾಗಮ a; }\
\
ಶೂನ್ಯ prefix ## call(ಶೂನ್ಯ)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (ದ್ವಿಗುಣ)strto ## prefix("1.2", ರಿಕ್ತ));\
}\
\
ಶೂನ್ಯ prefix ## signed_zeros(ಶೂನ್ಯ) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ಯದಿ (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ಅನ್ಯಥಾ\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  ಯದಿ (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ಅನ್ಯಥಾ\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ಯದಿ (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ಅನ್ಯಥಾ\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  ಯದಿ (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ಅನ್ಯಥಾ\
    printf ("x != -y; this is wrong!\n");\
}\
ಶೂನ್ಯ prefix ## nan(ಶೂನ್ಯ)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
ಶೂನ್ಯ prefix ## test(ಶೂನ್ಯ)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    ಯದಿ (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, ಭಿನ್ನ, ಭಿನ್ನ, "%f")
FTEST(d, ದ್ವಿಗುಣ, ದ್ವಿಗುಣ, "%f")
FTEST(ld, long ದ್ವಿಗುಣ, LONG_DOUBLE, "%Lf")

ದ್ವಿಗುಣ ftab1[3] = { 1.2, 3.4, -5.6 };


ಶೂನ್ಯ float_test(ಶೂನ್ಯ)
{
#ಯದಿ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    ಚಞ್ಚಲ ಭಿನ್ನ fa, fb;
    ಚಞ್ಚಲ ದ್ವಿಗುಣ da, db;
    ಪೂರ್ಣಾಙ್ಕ a;
    unsigned ಪೂರ್ಣಾಙ್ಕ b;
    ಸ್ಥಿರ ದ್ವಿಗುಣ nan2 = 0.0/0.0;
    ಸ್ಥಿರ ದ್ವಿಗುಣ inf1 = 1.0/0.0;
    ಸ್ಥಿರ ದ್ವಿಗುಣ inf2 = 1e5000;
    ಚಞ್ಚಲ LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", ಪರಿಮಾಣ(ಭಿನ್ನ));
    printf("sizeof(double) = %d\n", ಪರಿಮಾಣ(ದ್ವಿಗುಣ));
    printf("sizeof(long double) = %d\n", ಪರಿಮಾಣ(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    printf("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    printf("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    printf("da=%f\n", da);
    fa = 123;
    printf("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    printf("da = %f\n", da);
    b = 4000000000;
    db = b;
    printf("db = %f\n", db);
    printf("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    printf ("da subnormal = %a\n", da);
    printf ("da subnormal = %.40g\n", da);
    printf ("la subnormal = %La\n", la);
    printf ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    printf ("da/2 subnormal = %a\n", da);
    printf ("da/2 subnormal = %.40g\n", da);
    printf ("la/2 subnormal = %La\n", la);
    printf ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    printf ("fa subnormal = %a\n", fa);
    printf ("fa subnormal = %.40g\n", fa);
    printf ("la subnormal = %La\n", la);
    printf ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    printf ("fa/2 subnormal = %a\n", fa);
    printf ("fa/2 subnormal = %.40g\n", fa);
    printf ("la/2 subnormal = %La\n", la);
    printf ("la/2 subnormal = %.40Lg\n", la);
#endif
}

ಪೂರ್ಣಾಙ್ಕ fib(ಪೂರ್ಣಾಙ್ಕ n)
{
    ಯದಿ (n <= 2)
        ಪ್ರತ್ಯಾಗಮ 1;
    ಅನ್ಯಥಾ
        ಪ್ರತ್ಯಾಗಮ fib(n-1) + fib(n-2);
}

#ಯದಿ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ಅನ್ಯಥಾ
ಶೂನ್ಯ __attribute__((aligned(16))) aligned_function(ಪೂರ್ಣಾಙ್ಕ i) {}
#endif

ಶೂನ್ಯ funcptr_test()
{
    ಶೂನ್ಯ (*func)(ಪೂರ್ಣಾಙ್ಕ);
    ಪೂರ್ಣಾಙ್ಕ a;
    ಸಂರಚನಾ {
        ಪೂರ್ಣಾಙ್ಕ dummy;
        ಶೂನ್ಯ (*func)(ಪೂರ್ಣಾಙ್ಕ);
    } st1;
    long diff;

    func = &ಅಂಕೆ;
    (*func)(12345);
    func = ಅಂಕೆ;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = ಅಂಕೆ;
    st1.func(12346);
    printf("sizeof1 = %d\n", ಪರಿಮಾಣ(funcptr_test));
    printf("sizeof2 = %d\n", ಪರಿಮಾಣ funcptr_test);
    printf("sizeof3 = %d\n", ಪರಿಮಾಣ(&funcptr_test));
    printf("sizeof4 = %d\n", ಪರಿಮಾಣ &funcptr_test);
    a = 0;
    func = ಅಂಕೆ + a;
    diff = func - ಅಂಕೆ;
    func(42);
    (func + diff)(42);
    (ಅಂಕೆ + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((ಪೂರ್ಣಾಙ್ಕ)(uintptr_t)func) & 15);
}

ಶೂನ್ಯ lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ಯದಿ (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ದ್ವಿಮಾನ*/
    printf("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    printf("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    printf("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    printf("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    printf("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    printf("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    printf("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    printf("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

ಶೂನ್ಯ llshift(long long a, ಪೂರ್ಣಾಙ್ಕ b)
{
    printf("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (unsigned long long)a >> b,
           a >> b,
           a << b);
    printf("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (unsigned long long)a >> 3,
           a >> 3,
           a << 3);
    printf("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (unsigned long long)a >> 35,
           a >> 35,
           a << 35);
}

ಶೂನ್ಯ llfloat(ಶೂನ್ಯ)
{
    ಭಿನ್ನ fa;
    ದ್ವಿಗುಣ da;
    LONG_DOUBLE lda;
    long long la, lb, lc;
    unsigned long long ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    printf("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    printf("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    printf("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    printf("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    printf("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

long long llfunc1(ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪ್ರತ್ಯಾಗಮ a * 2;
}

ಸಂರಚನಾ S {
    ಪೂರ್ಣಾಙ್ಕ id; 
    ವರ್ಣ item;
};

long long ಪೂರ್ಣಾಙ್ಕ ಮೌಲ್ಯ(ಸಂರಚನಾ S *v)
{
    ಪ್ರತ್ಯಾಗಮ ((long long ಪೂರ್ಣಾಙ್ಕ)v->item);
}

long long llfunc2(long long x, long long y, ಪೂರ್ಣಾಙ್ಕ z)
{
    ಪ್ರತ್ಯಾಗಮ x * y * z;
}

ಶೂನ್ಯ check_opl_save_regs(ವರ್ಣ *a, long long b, ಪೂರ್ಣಾಙ್ಕ c)
{
    *a = b < 0 && !c;
}

ಶೂನ್ಯ longlong_test(ಶೂನ್ಯ)
{
    long long a, b, c;
    ಪೂರ್ಣಾಙ್ಕ ia;
    unsigned ಪೂರ್ಣಾಙ್ಕ ua;
    printf("sizeof(long long) = %d\n", ಪರಿಮಾಣ(long long));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    printf(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    printf(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (long long)1,
           (long long)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    printf(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#ಯದಿ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          ಸಂರಚನಾ S a;

          a.item = 3;
          printf("%lld\n", ಮೌಲ್ಯ(&a));
    }
    lloptest(0x80000000, 0);

    {
        long long *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        printf("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        printf("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    printf("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    printf(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    long long *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    unsigned long long u = 0x8000000000000001ULL;
    u = (unsigned)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (unsigned)(ಪೂರ್ಣಾಙ್ಕ)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    ವರ್ಣ cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

ಶೂನ್ಯ manyarg_test(ಶೂನ್ಯ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    printf("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    printf("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    printf("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    printf("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    printf("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    printf("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
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
        ಸಂರಚನಾ X { ಪೂರ್ಣಾಙ್ಕ _x; };
        ಸಂರಚನಾ X *x = va_arg(ap, ಸಂರಚನಾ X *);
        ಪ್ರತ್ಯಾಗಮ x;
}

ಶೂನ್ಯ vprintf1(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list ap, aq;
    ಧ್ರುವ ವರ್ಣ *p;
    ಪೂರ್ಣಾಙ್ಕ c, i;
    ದ್ವಿಗುಣ d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    ಪ್ರತಿ(;;) {
        c = *p;
        ಯದಿ (c == '\0')
            ಭಙ್ಗ;
        p++;
        ಯದಿ (c == '%') {
            c = *p;
            ವಿಕಲ್ಪ(c) {
            ಪಕ್ಷ '\0':
                ಗಚ್ಛ the_end;
            ಪಕ್ಷ 'd':
                i = va_arg(ap, ಪೂರ್ಣಾಙ್ಕ);
                printf("%d", i);
                ಭಙ್ಗ;
            ಪಕ್ಷ 'f':
                d = va_arg(ap, ದ್ವಿಗುಣ);
                printf("%f", d);
                ಭಙ್ಗ;
            ಪಕ್ಷ 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                ಭಙ್ಗ;
            ಪಕ್ಷ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                ಭಙ್ಗ;
            }
            p++;
        } ಅನ್ಯಥಾ {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

ಸಂರಚನಾ myspace {
    short ಪೂರ್ಣಾಙ್ಕ profile;
};
ಸಂರಚನಾ myspace2 {
#ಯದಿ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    ವರ್ಣ a[1];
#ಅನ್ಯಥಾ
    ವರ್ಣ a[0];
#endif
};
ಸಂರಚನಾ myspace3 {
    ವರ್ಣ a[1];
};
ಸಂರಚನಾ myspace4 {
    ವರ್ಣ a[2];
};
ಸಂರಚನಾ mytest {
    ಶೂನ್ಯ *foo, *bar, *baz;
};

ಸಂರಚನಾ mytest stdarg_for_struct(ಸಂರಚನಾ myspace bob, ...)
{
    ಸಂರಚನಾ myspace george, bill;
    ಸಂರಚನಾ myspace2 alex1;
    ಸಂರಚನಾ myspace3 alex2;
    ಸಂರಚನಾ myspace4 alex3;
    va_list ap;
    short ಪೂರ್ಣಾಙ್ಕ validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ಸಂರಚನಾ myspace2);
    alex2    = va_arg(ap, ಸಂರಚನಾ myspace3);
    alex3    = va_arg(ap, ಸಂರಚನಾ myspace4);
    bill     = va_arg(ap, ಸಂರಚನಾ myspace);
    george   = va_arg(ap, ಸಂರಚನಾ myspace);
    validate = va_arg(ap, ಪೂರ್ಣಾಙ್ಕ);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ಪ್ರತ್ಯಾಗಮ (ಸಂರಚನಾ mytest) {};
}

ಶೂನ್ಯ stdarg_for_libc(ಧ್ರುವ ವರ್ಣ *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

ಶೂನ್ಯ stdarg_syntax(ಪೂರ್ಣಾಙ್ಕ n, ...)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    va_list ap;
    ಯದಿ (1)
      va_start(ap, n);
    ಅನ್ಯಥಾ
      ;
    i = va_arg(ap, ಪೂರ್ಣಾಙ್ಕ);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ{
    ದ್ವಿಗುಣ x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ಸ್ಥಿರ ಶೂನ್ಯ stdarg_double_struct(ಪೂರ್ಣಾಙ್ಕ nargs, ಪೂರ್ಣಾಙ್ಕ posd,...)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ದ್ವಿಗುಣ d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    ಪ್ರತಿ(i = 0; i < nargs; i++) {
        ಯದಿ (i == posd) {
            d = va_arg (args, ದ್ವಿಗುಣ);
            printf ("d %d = %g\n", i, d);
        }
        ಅನ್ಯಥಾ {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

ಶೂನ್ಯ stdarg_test(ಶೂನ್ಯ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ಸಂರಚನಾ myspace bob;
    ಸಂರಚನಾ myspace2 bob2;
    ಸಂರಚನಾ myspace3 bob3;
    ಸಂರಚನಾ myspace4 bob4;

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
#ಯದಿ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

ಪೂರ್ಣಾಙ್ಕ reltab[3] = { 1, 2, 3 };

ಪೂರ್ಣಾಙ್ಕ *rel1 = &reltab[1];
ಪೂರ್ಣಾಙ್ಕ *rel2 = &reltab[2];

ಶೂನ್ಯ getmyaddress(ಶೂನ್ಯ)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(ಶೂನ್ಯ)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ಪ್ರತ್ಯಾಗಮ ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
ಶೂನ್ಯ relocation_test(ಶೂನ್ಯ)
{
    ಶೂನ್ಯ (*fptr)(ಶೂನ್ಯ) = (ಶೂನ್ಯ (*)(ಶೂನ್ಯ))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

ಶೂನ್ಯ old_style_f(a,b,c)
     ಪೂರ್ಣಾಙ್ಕ a, b;
     ದ್ವಿಗುಣ c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

ಶೂನ್ಯ decl_func1(ಪೂರ್ಣಾಙ್ಕ cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ಶೂನ್ಯ decl_func2(cmpfn)
ಪೂರ್ಣಾಙ್ಕ cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ಶೂನ್ಯ old_style_function_test(ಶೂನ್ಯ)
{
#ಯದಿ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ಅನ್ಯಥಾ
    old_style_f((ಶೂನ್ಯ *)1, 2, 3.0);
#endif
    decl_func1(ರಿಕ್ತ);
    decl_func2(ರಿಕ್ತ);
}

ಶೂನ್ಯ alloca_test()
{
    ವರ್ಣ *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    ವರ್ಣ *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

ಶೂನ್ಯ *bounds_checking_is_enabled()
{
    ವರ್ಣ ca[10], *cp = ca-1;
    ಪ್ರತ್ಯಾಗಮ (ca != cp + 1) ? cp : ರಿಕ್ತ;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

ಶೂನ್ಯ c99_vla_test_1(ಪೂರ್ಣಾಙ್ಕ size1, ಪೂರ್ಣಾಙ್ಕ size2)
{
    ಪೂರ್ಣಾಙ್ಕ size = size1 * size2;
    ಪೂರ್ಣಾಙ್ಕ tab1[size][2], tab2[10][2];
    ಶೂನ್ಯ *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (ಪರಿಮಾಣ tab1 == size1 * size2 * 2 * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((ಪೂರ್ಣಾಙ್ಕ *) (tab1_ptr + (size1 * 2 + 1) * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ಯದಿ (bad_ptr = bounds_checking_is_enabled()) {
        ಪೂರ್ಣಾಙ್ಕ *t1 = &tab1[size1 * size2 - 1][3];
        ಪೂರ್ಣಾಙ್ಕ *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        ವರ್ಣ*c1 = 1 + ಪರಿಮಾಣ(tab1) + (ವರ್ಣ*)tab1;
        ವರ್ಣ*c2 = 1 + ಪರಿಮಾಣ(tab2) + (ವರ್ಣ*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        ಪೂರ್ಣಾಙ್ಕ *i1 = tab1[-1];
        ಪೂರ್ಣಾಙ್ಕ *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        ಪೂರ್ಣಾಙ್ಕ *x1 = tab1[size1 * size2 + 1];
        ಪೂರ್ಣಾಙ್ಕ *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ಅನ್ಯಥಾ {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

ಶೂನ್ಯ c99_vla_test_2(ಪೂರ್ಣಾಙ್ಕ d, ಪೂರ್ಣಾಙ್ಕ h, ಪೂರ್ಣಾಙ್ಕ w)
{
    ಪೂರ್ಣಾಙ್ಕ x, y, z;
    ಪೂರ್ಣಾಙ್ಕ (*arr)[h][w] = malloc(ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ) * d*h*w);
    ಪೂರ್ಣಾಙ್ಕ c = 1;
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    ಪ್ರತಿ (z=0; z<d; z++) {
        ಪ್ರತಿ (y=0; y<h; y++) {
            ಪ್ರತಿ (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    ಪ್ರತಿ (z=0; z<d; z++) {
        ಪ್ರತಿ (y=0; y<h; y++) {
            ಪ್ರತಿ (x=0; x<w; x++) {
                printf(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    printf(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        ಪರಿಮಾಣ (*arr), ಪರಿಮಾಣ (*arr)[0], ಪರಿಮಾಣ (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == ಪರಿಮಾಣ (*arr + 1) - ಪರಿಮಾಣ arr,
        0 == ಪರಿಮಾಣ ಪರಿಮಾಣ *arr - ಪರಿಮಾಣ arr,
        starr[0][2][3] == arr[1][2][3]
        );
    ಮುಕ್ತ (arr);
}

ಶೂನ್ಯ c99_vla_test_3a (ಪೂರ್ಣಾಙ್ಕ arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3b(ಪೂರ್ಣಾಙ್ಕ s, ಪೂರ್ಣಾಙ್ಕ arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3c(ಪೂರ್ಣಾಙ್ಕ s, ಪೂರ್ಣಾಙ್ಕ arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3d(ಪೂರ್ಣಾಙ್ಕ s, ಪೂರ್ಣಾಙ್ಕ arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3e(ಪೂರ್ಣಾಙ್ಕ s, ಪೂರ್ಣಾಙ್ಕ arr[][3][--s])
{
    printf ("%d %d %d\n", ಪರಿಮಾಣ arr, s, arr[1][2][3]);
}

ಶೂನ್ಯ c99_vla_test_3(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a[2][3][4];

    memset (a, 0, ಪರಿಮಾಣ(a));
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
    ಪೂರ್ಣಾಙ್ಕ a;
    ಪೂರ್ಣಾಙ್ಕ **ptr;

    printf("sizeof(int) = %d\n", ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
    printf("sizeof(unsigned int) = %d\n", ಪರಿಮಾಣ(unsigned ಪೂರ್ಣಾಙ್ಕ));
    printf("sizeof(long) = %d\n", ಪರಿಮಾಣ(long));
    printf("sizeof(unsigned long) = %d\n", ಪರಿಮಾಣ(unsigned long));
    printf("sizeof(short) = %d\n", ಪರಿಮಾಣ(short));
    printf("sizeof(unsigned short) = %d\n", ಪರಿಮಾಣ(unsigned short));
    printf("sizeof(char) = %d\n", ಪರಿಮಾಣ(ವರ್ಣ));
    printf("sizeof(unsigned char) = %d\n", ಪರಿಮಾಣ(unsigned ವರ್ಣ));
    printf("sizeof(func) = %d\n", ಪರಿಮಾಣ sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", ಪರಿಮಾಣ a++);
    printf("a=%d\n", a);
    ptr = ರಿಕ್ತ;
    printf("sizeof(**ptr) = %d\n", ಪರಿಮಾಣ (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", ಪರಿಮಾಣ(ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -ಪರಿಮಾಣ(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(ಪೂರ್ಣಾಙ್ಕ));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned ಪೂರ್ಣಾಙ್ಕ));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(ವರ್ಣ));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned ವರ್ಣ));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", ಪರಿಮಾಣ(ವರ್ಣ[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   ಪರಿಮಾಣ( (ಸಂರಚನಾ {ಪೂರ್ಣಾಙ್ಕ i; ಪೂರ್ಣಾಙ್ಕ j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   ಪರಿಮಾಣ (ಸಂರಚನಾ {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", ಪರಿಮಾಣ(t && 0));
    printf("sizeof(1 && 1) = %d\n", ಪರಿಮಾಣ(1 && 1));
    printf("sizeof(t || 1) = %d\n", ಪರಿಮಾಣ(t || 1));
    printf("sizeof(0 || 0) = %d\n", ಪರಿಮಾಣ(0 || 0));

    ಪೂರ್ಣಾಙ್ಕ arr[4], fn();
    printf("sizeof(0, arr) = %d\n", ಪರಿಮಾಣ(0, arr));
    printf("sizeof(0, fn) = %d\n", ಪರಿಮಾಣ(0, fn));
}

ಶೂನ್ಯ typeof_test(ಶೂನ್ಯ)
{
    ದ್ವಿಗುಣ a;
    typeof(a) b;
    typeof(ಭಿನ್ನ) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


ಸಂರಚನಾ hlist_ಗಂಟು;
ಸಂರಚನಾ hlist_head {
    ಸಂರಚನಾ hlist_ಗಂಟು *first, *last;
};

ಶೂನ್ಯ consume_ulong (unsigned long i)
{
    i = 0;
}

ಶೂನ್ಯ statement_ಅಭಿವ್ಯಕ್ತಿ_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a, i;

    /* Basic stmt expr test */
    a = 0;
    ಪ್ರತಿ(i=0;i<10;i++) {
        a += 1 + 
            ( { ಪೂರ್ಣಾಙ್ಕ b, j; 
                b = 0; 
                ಪ್ರತಿ(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    ಶೂನ್ಯ *v = (ಶೂನ್ಯ*)39;
    typeof(({
	    (ಸಂರಚನಾ hlist_ಗಂಟು *)v;
	    })) x;
    typeof (x)
	ptr = (ಸಂರಚನಾ hlist_ಗಂಟು *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            ಸ್ಥಿರ ಧ್ರುವ ವರ್ಣ *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    ಪೂರ್ಣಾಙ್ಕ t = 40;
    ಪೂರ್ಣಾಙ್ಕ b = ({ ಪೂರ್ಣಾಙ್ಕ t = 41; t; });
    ಪೂರ್ಣಾಙ್ಕ c = ({ ಪೂರ್ಣಾಙ್ಕ t = 42; t; });

    /* Test that aggregate return values work.  */
    ಸಂರಚನಾ hlist_head h
	= ({
	   ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ hlist_head T;
	   long pre = 48;
	   T t = { (ಶೂನ್ಯ*)43, (ಶೂನ್ಯ*)44 };
	   long post = 49;
	   t;
	   });
    printf ("stmtexpr: %d %d %d\n", t, b, c);
    printf ("stmtexpr: %ld %ld\n", (long)h.first, (long)h.last);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (unsigned long)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: ಯದಿ (i++ == 0) ಗಚ್ಛ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      ಗಚ್ಛ LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

ಶೂನ್ಯ local_label_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a;
    ಗಚ್ಛ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        ಗಚ್ಛ l1;
    l4:
        printf("aa1\n");
        ಗಚ್ಛ l3;
    l2:
        printf("aa3\n");
        ಗಚ್ಛ l4;
    l1:
        printf("aa2\n");
        ಗಚ್ಛ l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    ಪ್ರತ್ಯಾಗಮ;
 l4:
    printf("bb1\n");
    ಗಚ್ಛ l2;
 l1:
    printf("bb2\n");
    ಗಚ್ಛ l4;
}

/* inline assembler test */
#ಯದಿ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

ಪ್ರಕಾರನಿರ್ದೇಶ __SIZE_TYPE__ word;

/* from linux kernel */
ಸ್ಥಿರ ವರ್ಣ * strncat1(ವರ್ಣ * dest,ಧ್ರುವ ವರ್ಣ * src,size_t ಎಣಿಕೆ_2)
{
word d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ಎಣಿಕೆ_2)
	: "memory");
ಪ್ರತ್ಯಾಗಮ dest;
}

ಸ್ಥಿರ ವರ್ಣ * strncat2(ವರ್ಣ * dest,ಧ್ರುವ ವರ್ಣ * src,size_t ಎಣಿಕೆ_2)
{
word d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ಎಣಿಕೆ_2)
	: "memory");
ಪ್ರತ್ಯಾಗಮ dest;
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ * memcpy1(ಶೂನ್ಯ * to, ಧ್ರುವ ಶೂನ್ಯ * from, size_t n)
{
word d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((word) to),"2" ((word) from)
	: "memory");
ಪ್ರತ್ಯಾಗಮ (to);
}

ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ ಶೂನ್ಯ * memcpy2(ಶೂನ್ಯ * to, ಧ್ರುವ ಶೂನ್ಯ * from, size_t n)
{
word d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((word) to),"2" ((word) from)
	: "memory");
ಪ್ರತ್ಯಾಗಮ (to);
}

ಸ್ಥಿರ __inline__ ಶೂನ್ಯ sigaddset1(unsigned ಪೂರ್ಣಾಙ್ಕ *set, ಪೂರ್ಣಾಙ್ಕ _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

ಸ್ಥಿರ __inline__ ಶೂನ್ಯ sigdelset1(unsigned ಪೂರ್ಣಾಙ್ಕ *set, ಪೂರ್ಣಾಙ್ಕ _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ಸ್ಥಿರ __inline__ __const__ unsigned ಪೂರ್ಣಾಙ್ಕ swab32(unsigned ಪೂರ್ಣಾಙ್ಕ x)
{
        ಪ್ರತ್ಯಾಗಮ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ಅನ್ಯಥಾ
ಸ್ಥಿರ __inline__ __const__ unsigned ಪೂರ್ಣಾಙ್ಕ swab32(unsigned ಪೂರ್ಣಾಙ್ಕ x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ಪ್ರತ್ಯಾಗಮ x;
}
#endif

ಸ್ಥಿರ __inline__ unsigned long long mul64(unsigned ಪೂರ್ಣಾಙ್ಕ a, unsigned ಪೂರ್ಣಾಙ್ಕ b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned ಪೂರ್ಣಾಙ್ಕ resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#ಅನ್ಯಥಾ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    ಪ್ರತ್ಯಾಗಮ res;
}

ಸ್ಥಿರ __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ಅನ್ಯಥಾ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    ಪ್ರತ್ಯಾಗಮ res;
}

ಸಂರಚನಾ struct123 {
    ಪೂರ್ಣಾಙ್ಕ a;
    ಪೂರ್ಣಾಙ್ಕ b;
};
ಸಂರಚನಾ struct1231 {
    word addr;
};

word mconstraint_test(ಸಂರಚನಾ struct1231 *r)
{
    word ret;
    unsigned ಪೂರ್ಣಾಙ್ಕ a[2];
    a[0] = 0;
    __asm__ ಚಞ್ಚಲ ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ಸಂರಚನಾ struct123 *)r->addr));
    ಪ್ರತ್ಯಾಗಮ ret + a[0];
}

#ifdef __x86_64__
ಪೂರ್ಣಾಙ್ಕ fls64(unsigned long long x)
{
  ಪೂರ್ಣಾಙ್ಕ bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ಪ್ರತ್ಯಾಗಮ bitpos + 1;
}
#endif

ಶೂನ್ಯ other_constraints_test(ಶೂನ್ಯ)
{
    word ret;
    ಪೂರ್ಣಾಙ್ಕ var;
#ಯದಿ CC_NAME != CC_clang
    __asm__ ಚಞ್ಚಲ ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
ಶೂನ್ಯ base_func(ಶೂನ್ಯ)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
ಬಾಹ್ಯ ಶೂನ್ಯ override_func1 (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಶೂನ್ಯ override_func2 (ಶೂನ್ಯ);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

ಶೂನ್ಯ override_func2 (ಶೂನ್ಯ)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ bug_table[] __attribute__((section("__bug_table")));
ವರ್ಣ * get_asm_string (ಶೂನ್ಯ)
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
#ifndef __clang__
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ some_ಚಿಹ್ನೆ;
  asm ಚಞ್ಚಲ (".globl some_symbol\n"
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
  ವರ್ಣ * str = ((ವರ್ಣ*)bug_table) + bug_table[1];
  ಪ್ರತ್ಯಾಗಮ str;
#ಅನ್ಯಥಾ
  ಪ್ರತ್ಯಾಗಮ (ವರ್ಣ *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
ಬಾಹ್ಯ unsigned ವರ್ಣ alld_stuff[];
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
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
ಶೂನ್ಯ asm_local_statics (ಶೂನ್ಯ)
{
  ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

ಸ್ಥಿರ
unsigned ಪೂರ್ಣಾಙ್ಕ set;

ಶೂನ್ಯ fancy_copy (unsigned *in, unsigned *out)
{
  asm ಚಞ್ಚಲ ("" : "=r" (*out) : "0" (*in));
}

ಶೂನ್ಯ fancy_copy2 (unsigned *in, unsigned *out)
{
  asm ಚಞ್ಚಲ ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#ಯದಿ defined __x86_64__
ಶೂನ್ಯ clobber_r12(ಶೂನ್ಯ)
{
    asm ಚಞ್ಚಲ("mov $1, %%r12" ::: "r12");
}
#endif

ಶೂನ್ಯ test_ಮೇಲಿನ_clobbers_really(ಶೂನ್ಯ)
{
#ಯದಿ defined __x86_64__
    ಪಞ್ಜಿಕಾ word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm ಚಞ್ಚಲ("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm ಚಞ್ಚಲ("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

ಶೂನ್ಯ test_ಮೇಲಿನ_clobbers(ಶೂನ್ಯ)
{
#ಯದಿ defined __x86_64__
    word x1, x2;
    asm ಚಞ್ಚಲ("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ಮೇಲಿನ_clobbers_really();
    asm ಚಞ್ಚಲ("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm ಚಞ್ಚಲ("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

ಸ್ಥಿರ long cpu_ಸಂಖ್ಯೆ;
ಶೂನ್ಯ trace_console(long len, long len2)
{
#ifdef __x86_64__
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
    ಯದಿ (0
        &&
            ({
              long pscr_ret__;
              ವಿಕಲ್ಪ(len) {
                ಪಕ್ಷ 4:
                    {
                       long pfo_ret__;
                       ವಿಕಲ್ಪ (len2) {
                         ಪಕ್ಷ 8:	printf("bla"); pfo_ret__ = 42; ಭಙ್ಗ;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ಭಙ್ಗ;
                ಪಕ್ಷ 8:
                    {
                       long pfo_ret__;
                       ವಿಕಲ್ಪ (len2) {
                         ಪಕ್ಷ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ಭಙ್ಗ;
                         ಪಕ್ಷ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ಭಙ್ಗ;
                         ಪಕ್ಷ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ಭಙ್ಗ;
                         ಪಕ್ಷ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ಸಂಖ್ಯೆ));	ಭಙ್ಗ;
                         ಸ್ವಭಾವ: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ಭಙ್ಗ;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

ಶೂನ್ಯ test_asm_dead_code(ಶೂನ್ಯ)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm ಚಞ್ಚಲ ("" : "=D" (rdi) : "0" (0));
  (ಶೂನ್ಯ)ಪರಿಮಾಣ (({
      ಪೂರ್ಣಾಙ್ಕ var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm ಚಞ್ಚಲ ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

ಶೂನ್ಯ test_asm_call(ಶೂನ್ಯ)
{
#ಯದಿ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ಸ್ಥಿರ ವರ್ಣ str[] = "PATH";
  ವರ್ಣ *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm ಚಞ್ಚಲ ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ಯದಿ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ಅನ್ಯಥಾ
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#ಯದಿ defined __x86_64__
# define RX "(%rip)"
#ಅನ್ಯಥಾ
# define RX
#endif

ಶೂನ್ಯ asm_dot_test(ಶೂನ್ಯ)
{
#ifndef __APPLE__
    ಪೂರ್ಣಾಙ್ಕ x;
    ಪ್ರತಿ (x = 1;; ++x) {
        ಪೂರ್ಣಾಙ್ಕ r = x;
        ವಿಕಲ್ಪ (x) {
        ಪಕ್ಷ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        ಪಕ್ಷ 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ಅನ್ಯಥಾ
            asm(".text; mov $123, %eax; jmp p0");
#endif
	ಪಕ್ಷ 3:
#ಯದಿ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ಅನ್ಯಥಾ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        ಪಕ್ಷ 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ಅನ್ಯಥಾ
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ಅನ್ಯಥಾ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        ಪಕ್ಷ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ಭಙ್ಗ;
	}
        ಯದಿ (r == x)
            ಭಙ್ಗ;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

ಶೂನ್ಯ asm_pcrel_test(ಶೂನ್ಯ)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

ಶೂನ್ಯ asm_test(ಶೂನ್ಯ)
{
    ವರ್ಣ buf[128];
    unsigned ಪೂರ್ಣಾಙ್ಕ val, val2;
    ಸಂರಚನಾ struct123 s1;
    ಸಂರಚನಾ struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    ಪೂರ್ಣಾಙ್ಕ base_func = 42;
    ಶೂನ್ಯ override_func3 (ಶೂನ್ಯ);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    ಪಞ್ಜಿಕಾ ಪೂರ್ಣಾಙ್ಕ regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm ಚಞ್ಚಲ ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm ಚಞ್ಚಲ ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    printf("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    printf("%s\n", buf);

    /* 'A' constraint test */
    printf("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    printf("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    printf("mconstraint: %d", mconstraint_test(&s2));
    printf(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    set = 0xff;
    sigdelset1(&set, 2);
    sigaddset1(&set, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    ಗಚ್ಛ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(set) : "Ir"(20) : "cc");
    printf("set=0x%x\n", set);
    val = 0x01020304;
    printf("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#ifndef _WIN32
#ifndef __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm ಚಞ್ಚಲ(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    printf("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#endif
#endif
    asm_local_statics();
#ifndef __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm ಚಞ್ಚಲ("" : "=r" (asmret) : "0"(s2));
    ಯದಿ (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm ಚಞ್ಚಲ("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ಯದಿ (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm ಚಞ್ಚಲ ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_ಮೇಲಿನ_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ಪ್ರತ್ಯಾಗಮ;
 label1:
    ಗಚ್ಛ label2;
}

#ಅನ್ಯಥಾ

ಶೂನ್ಯ asm_test(ಶೂನ್ಯ)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

ಪೂರ್ಣಾಙ್ಕ constant_p_var;

ಪೂರ್ಣಾಙ್ಕ func(ಶೂನ್ಯ);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ಸ್ಥಿರ ಶೂನ್ಯ builtin_test_bits(unsigned long long x, ಪೂರ್ಣಾಙ್ಕ cnt[])
{
#ಯದಿ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ಯದಿ ((unsigned ಪೂರ್ಣಾಙ್ಕ) x) cnt[3] += __builtin_clz(x);
    ಯದಿ ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    ಯದಿ ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    ಯದಿ ((unsigned ಪೂರ್ಣಾಙ್ಕ) x) cnt[6] += __builtin_ctz(x);
    ಯದಿ ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    ಯದಿ ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#ಯದಿ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#endif

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#endif
}

ಶೂನ್ಯ builtin_test(ಶೂನ್ಯ)
{
    short s;
    ಪೂರ್ಣಾಙ್ಕ i;
    long long ll;
#ಯದಿ GCC_MAJOR >= 3
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ, unsigned ಪೂರ್ಣಾಙ್ಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ, ವರ್ಣ);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ, ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ[2], ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ[2]);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ[2][3], ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ[][3]);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ (*)[], ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ (*)[2])0 : (ಪೂರ್ಣಾಙ್ಕ (*)[2])0),
                ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ (*)[2][3])0 :
                              (ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ (*)[2][3])0),
                ಧ್ರುವ ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ (*)[2][3])0 :
                              (ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ (*)[2][3])0),
                ಧ್ರುವ ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ (*)[2][3]);
#ಅನ್ಯಥಾ
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ *, ಪೂರ್ಣಾಙ್ಕ *);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ *, ಶೂನ್ಯ *);
    COMPAT_TYPE(ಪೂರ್ಣಾಙ್ಕ *, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ *);
    COMPAT_TYPE(ವರ್ಣ *, unsigned ವರ್ಣ *);
    COMPAT_TYPE(ವರ್ಣ *, signed ವರ್ಣ *);
    COMPAT_TYPE(ವರ್ಣ *, ವರ್ಣ *);
    COMPAT_TYPE(ವರ್ಣ **, ಶೂನ್ಯ *);
#endif
    printf("res1 = %d\n", __builtin_constant_p(1));
    printf("res2 = %d\n", __builtin_constant_p(1 + 2));
    printf("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    printf("res4 = %d\n", __builtin_constant_p(constant_p_var));
    printf("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    printf("res6 = %d\n", __builtin_constant_p(i && 1));
    printf("res7 = %d\n", __builtin_constant_p("hi"));
    printf("res8 = %d\n", __builtin_constant_p(func()));
#ifndef __clang__
    printf("res10 = %d\n", __builtin_constant_p(i && 0));
    printf("res11 = %d\n", __builtin_constant_p(i * 0));
    printf("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    printf("res13 = %d\n", __builtin_constant_p((1,7)));
#ಅನ್ಯಥಾ
    /* clang doesn't regard these as constant expression */
    printf("res10 = 1\n");
    printf("res11 = 1\n");
    printf("res12 = 1\n");
    printf("res13 = 0\n");
#endif

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    printf("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    printf("bce: %d\n", i);
    i = ಪರಿಮಾಣ (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = ಪರಿಮಾಣ (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	ಪೂರ್ಣಾಙ್ಕ cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, ಪರಿಮಾಣ(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        ಪ್ರತಿ (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        ಪ್ರತಿ (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	ಪ್ರತಿ (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#ಯದಿ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
ಶೂನ್ಯ weak_test(ಶೂನ್ಯ) {}
#ಅನ್ಯಥಾ
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_f1(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_f2(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ                       weak_f3(ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_v1;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_v2;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ                       weak_v3;

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ                           (*weak_fpa)() __attribute__((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute__((weak))     (*weak_fpb)();
ಬಾಹ್ಯ     __attribute__((weak)) ಪೂರ್ಣಾಙ್ಕ (*weak_fpc)();

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ                     weak_asm_f1(ಶೂನ್ಯ) asm("weak_asm_f1x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute((weak)) weak_asm_f2(ಶೂನ್ಯ) asm("weak_asm_f2x")                    ;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute((weak)) weak_asm_f3(ಶೂನ್ಯ) asm("weak_asm_f3x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ __attribute((weak)) weak_asm_v3(ಶೂನ್ಯ) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
ಸ್ಥಿರ ಧ್ರುವ size_t dummy = 0;
ಬಾಹ್ಯ __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
ಬಾಹ್ಯ __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
ಬಾಹ್ಯ __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

ಪೂರ್ಣಾಙ್ಕ some_lib_func(ಶೂನ್ಯ);
ಪೂರ್ಣಾಙ್ಕ dummy_impl_of_slf(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 444; }
#ifndef __clang__
ಪೂರ್ಣಾಙ್ಕ some_lib_func(ಶೂನ್ಯ) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

ಪೂರ್ಣಾಙ್ಕ weak_toolate() __attribute__((weak));
ಪೂರ್ಣಾಙ್ಕ weak_toolate() { ಪ್ರತ್ಯಾಗಮ 0; }

ಶೂನ್ಯ __attribute__((weak)) weak_test(ಶೂನ್ಯ)
{
	printf("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	printf("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	printf("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	printf("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	printf("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	printf("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	printf("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	printf("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	printf("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != ರಿಕ್ತ);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != ರಿಕ್ತ);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != ರಿಕ್ತ);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != ರಿಕ್ತ);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != ರಿಕ್ತ);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != ರಿಕ್ತ);
#ifdef __clang__
	printf("some_lib_func=444\n");
#ಅನ್ಯಥಾ
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_f2() { ಪ್ರತ್ಯಾಗಮ 222; }
ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_f3() { ಪ್ರತ್ಯಾಗಮ 333; }
ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_v2 = 222;
ಪೂರ್ಣಾಙ್ಕ __attribute__((weak)) weak_v3 = 333;
#endif

ಶೂನ್ಯ const_func(ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ a)
{
}

ಶೂನ್ಯ const_warn_test(ಶೂನ್ಯ)
{
    const_func(1);
}

ಸಂರಚನಾ condstruct {
  ಪೂರ್ಣಾಙ್ಕ i;
};

ಪೂರ್ಣಾಙ್ಕ getme (ಸಂರಚನಾ condstruct *s, ಪೂರ್ಣಾಙ್ಕ i)
{
  ಪೂರ್ಣಾಙ್ಕ i1 = (i == 0 ? 0 : s)->i;
  ಪೂರ್ಣಾಙ್ಕ i2 = (i == 0 ? s : 0)->i;
  ಪೂರ್ಣಾಙ್ಕ i3 = (i == 0 ? (ಶೂನ್ಯ*)0 : s)->i;
  ಪೂರ್ಣಾಙ್ಕ i4 = (i == 0 ? s : (ಶೂನ್ಯ*)0)->i;
  ಪ್ರತ್ಯಾಗಮ i1 + i2 + i3 + i4;
}

ಸಂರಚನಾ global_data
{
  ಪೂರ್ಣಾಙ್ಕ a[40];
  ಪೂರ್ಣಾಙ್ಕ *b[40];
};

ಸಂರಚನಾ global_data global_data;

ಪೂರ್ಣಾಙ್ಕ global_data_getstuff (ಪೂರ್ಣಾಙ್ಕ *, ಪೂರ್ಣಾಙ್ಕ);

ಶೂನ್ಯ global_data_callit (ಪೂರ್ಣಾಙ್ಕ i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

ಪೂರ್ಣಾಙ್ಕ global_data_getstuff (ಪೂರ್ಣಾಙ್ಕ *p, ಪೂರ್ಣಾಙ್ಕ i)
{
  ಪ್ರತ್ಯಾಗಮ *p + i;
}

ಶೂನ್ಯ global_data_test (ಶೂನ್ಯ)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

ಸಂರಚನಾ cmpcmpS
{
  unsigned ವರ್ಣ fill : 3;
  unsigned ವರ್ಣ b1 : 1;
  unsigned ವರ್ಣ b2 : 1;
  unsigned ವರ್ಣ fill2 : 3;
};

ಪೂರ್ಣಾಙ್ಕ glob1, glob2, glob3;

ಶೂನ್ಯ compare_comparisons (ಸಂರಚನಾ cmpcmpS *s)
{
  ಯದಿ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

ಶೂನ್ಯ cmp_comparison_test(ಶೂನ್ಯ)
{
  ಸಂರಚನಾ cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

ಪೂರ್ಣಾಙ್ಕ fcompare (ದ್ವಿಗುಣ a, ದ್ವಿಗುಣ b, ಪೂರ್ಣಾಙ್ಕ code)
{
  ವಿಕಲ್ಪ (code) {
    ಪಕ್ಷ 0: ಪ್ರತ್ಯಾಗಮ a == b;
    ಪಕ್ಷ 1: ಪ್ರತ್ಯಾಗಮ a != b;
    ಪಕ್ಷ 2: ಪ್ರತ್ಯಾಗಮ a < b;
    ಪಕ್ಷ 3: ಪ್ರತ್ಯಾಗಮ a >= b;
    ಪಕ್ಷ 4: ಪ್ರತ್ಯಾಗಮ a > b;
    ಪಕ್ಷ 5: ಪ್ರತ್ಯಾಗಮ a <= b;
  }
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ math_cmp_test(ಶೂನ್ಯ)
{
  ದ್ವಿಗುಣ nan = 0.0/0.0;
  ದ್ವಿಗುಣ one = 1.0;
  ದ್ವಿಗುಣ two = 2.0;
  ಪೂರ್ಣಾಙ್ಕ comp = 0;
  ಪೂರ್ಣಾಙ್ಕ v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  ಯದಿ (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  ಯದಿ (a op b) \
    bug (a,b,op,iop,2); \
  ಯದಿ (a iop b) \
    ; \
  ಅನ್ಯಥಾ \
    bug (a,b,op,iop,3); \
  ಯದಿ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ಯದಿ ((a iop b) || comp) \
    ; \
  ಅನ್ಯಥಾ \
    bug (a,b,op,iop,5); \
  ಯದಿ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ಯದಿ (!fcompare (nan, nan, 1))
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

ದ್ವಿಗುಣ get100 () { ಪ್ರತ್ಯಾಗಮ 100.0; }

ಶೂನ್ಯ callsave_test(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i, s; ದ್ವಿಗುಣ *d; ದ್ವಿಗುಣ t;
  s = ಪರಿಮಾಣ (ದ್ವಿಗುಣ);
  printf ("callsavetest: %d\n", s);
  d = alloca (ಪರಿಮಾಣ(ದ್ವಿಗುಣ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


ಶೂನ್ಯ bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (ವರ್ಣ *)__builtin_frame_address(3) + str_offset);
}
ಶೂನ್ಯ bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (ವರ್ಣ *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
ಶೂನ್ಯ bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (ವರ್ಣ *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

ಶೂನ್ಯ builtin_frame_address_test(ಶೂನ್ಯ)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    ವರ್ಣ str[] = "__builtin_frame_address";
    ವರ್ಣ *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

ವರ್ಣ via_volatile (ವರ್ಣ i)
{
  ವರ್ಣ ಚಞ್ಚಲ vi;
  vi = i;
  ಪ್ರತ್ಯಾಗಮ vi;
}

ಶೂನ್ಯ volatile_test(ಶೂನ್ಯ)
{
    ಯದಿ (via_volatile (42) != 42)
      printf (" broken\n");
    ಅನ್ಯಥಾ
      printf (" ok\n");
}

ಸಂರಚನಾ __attribute__((__packed__)) Spacked {
    ವರ್ಣ a;
    short b;
    ಪೂರ್ಣಾಙ್ಕ c;
};
ಸಂರಚನಾ Spacked spacked;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ __attribute__((__packed__)) {
    ವರ್ಣ a;
    short b;
    ಪೂರ್ಣಾಙ್ಕ c;
} Spacked2;
Spacked2 spacked2;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ Spacked3_s {
    ವರ್ಣ a;
    short b;
    ಪೂರ್ಣಾಙ್ಕ c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ಸಂರಚನಾ gate_struct64 {
    unsigned short offset_ಕೆಳಗಿನ;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_ಮಧ್ಯ;
    unsigned offset_ಮೇಲಿನ;
    unsigned zero1;
} __attribute__((packed));
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ gate_struct64 gate_desc;
gate_desc a_gate_desc;
ಶೂನ್ಯ attrib_test(ಶೂನ್ಯ)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", ಪರಿಮಾಣ(ಸಂರಚನಾ Spacked),
	 ಪರಿಮಾಣ(spacked), ಪರಿಮಾಣ(Spacked2), ಪರಿಮಾಣ(spacked2));
  printf("attr: %d %d\n", ಪರಿಮಾಣ(Spacked3), ಪರಿಮಾಣ(spacked3));
  printf("attr: %d %d\n", ಪರಿಮಾಣ(gate_desc), ಪರಿಮಾಣ(a_gate_desc));
#endif
}
ಬಾಹ್ಯ __attribute__((__unused__)) ವರ್ಣ * __attribute__((__unused__)) *
strange_attrib_placement (ಶೂನ್ಯ);

ಶೂನ್ಯ * __attribute__((__unused__)) get_void_ptr (ಶೂನ್ಯ *a)
{
  ಪ್ರತ್ಯಾಗಮ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ಸ್ಥಿರ ಅನ್ತಃಸ್ಥ
ಪೂರ್ಣಾಙ್ಕ __get_order(unsigned long long size)
{
  ಪೂರ್ಣಾಙ್ಕ order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ಸಂರಚನಾ S { ಪೂರ್ಣಾಙ್ಕ i : 1; } s; // constructed for this '1'
    }
  order = size;
  ಪ್ರತ್ಯಾಗಮ order;
}

/* This just forces the above inline function to be actually emitted.  */
ಪೂರ್ಣಾಙ್ಕ force_get_order(unsigned long s)
{
    ಪ್ರತ್ಯಾಗಮ __get_order(s);
}

#define pv(m) printf(ಪರಿಮಾಣ (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
ಶೂನ್ಯ bounds_check1_test (ಶೂನ್ಯ)
{
    ಸಂರಚನಾ s {
        ಪೂರ್ಣಾಙ್ಕ x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
ಶೂನ್ಯ map_add(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ d, ಪೂರ್ಣಾಙ್ಕ e, ಪೂರ್ಣಾಙ್ಕ f, ಪೂರ್ಣಾಙ್ಕ g, ಪೂರ್ಣಾಙ್ಕ h, ಪೂರ್ಣಾಙ್ಕ i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

ಶೂನ್ಯ func_arg_test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ a = 0;
    ಪೂರ್ಣಾಙ್ಕ b = 1;
    map_add(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#define CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#ifdef __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#endif

#define	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
ಶೂನ್ಯ whitespace_test(ಶೂನ್ಯ)
{
    ವರ್ಣ *str;
    ಪೂರ್ಣಾಙ್ಕ tcc_test = 1;

#ಯದಿ 1
    pri\
ntf("whitspace:\n");
#endif
    pf("N=%d\n", 2);

#ifdef CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#endif

    pri\
\
ntf("min=%d\n", 4);

#ifdef ACCEPT_LF_IN_STRINGS
    printf("len1=%d\n", strlen("
"));
#ifdef CORRECT_CR_HANDLING
    str = "
";
    printf("len1=%d str[0]=%d\n", strlen(str), str[0]);
#endif
    printf("len1=%d\n", strlen("a
"));
#ಅನ್ಯಥಾ
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#ಯದಿ 0
    /* wrong with GCC */
    printf("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#line 1111
    printf("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#line 2222 "test"
    printf("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#endif

    printf("\\
"12\\
063\\
n 456\"\n");

    printf ("%d\n",
#ಯದಿ 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(ಅಭಿವ್ಯಕ್ತಿ_test);
    RUN(scope_test);
    RUN(scope2_test);
    RUN(forward_test);
    RUN(funcptr_test);
    RUN(if_test);
    RUN(loop_test);
    RUN(switch_test);
    RUN(goto_test);
    RUN(enum_test);
    RUN(typedef_test);
    RUN(struct_test);
    RUN(array_test);
    RUN(ಅಭಿವ್ಯಕ್ತಿ_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_ಅಭಿವ್ಯಕ್ತಿ_test);
    RUN(ಅಭಿವ್ಯಕ್ತಿ_cmp_test);
    RUN(char_short_test);
    RUN(init_test);
    RUN(compound_literal_test);
    RUN(kr_test);
    RUN(struct_assign_test);
    RUN(cast_test);
    RUN(bitfield_test);
    RUN(c99_bool_test);
    RUN(float_test);
    RUN(longlong_test);
    RUN(manyarg_test);
    RUN(stdarg_test);
    RUN(relocation_test);
    RUN(old_style_function_test);
    RUN(alloca_test);
    RUN(c99_vla_test);
    RUN(sizeof_test);
    RUN(typeof_test);
    RUN(statement_ಅಭಿವ್ಯಕ್ತಿ_test);
    RUN(local_label_test);
    RUN(asm_test);
    RUN(builtin_test);
    RUN(weak_test);
    RUN(global_data_test);
    RUN(cmp_comparison_test);
    RUN(math_cmp_test);
    RUN(callsave_test);
    RUN(builtin_frame_address_test);
    RUN(volatile_test);
    RUN(attrib_test);
    RUN(bounds_check1_test);
    RUN(func_arg_test);

    ಪ್ರತ್ಯಾಗಮ 0;
}
