/*
 * TCC auto test program
 */
#ଅନ୍ତର୍ଭାଵ "config.h"

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

#ଯଦି defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#ଅନ୍ୟଥା
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ଯଦି defined(_WIN32)
#define LONG_DOUBLE ଦ୍ୱିଗୁଣ
#define LONG_DOUBLE_LITERAL(x) x
#ଅନ୍ୟଥା
#define LONG_DOUBLE long ଦ୍ୱିଗୁଣ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#ଅନ୍ତର୍ଭାଵ TCCLIB_INC

#ଅନ୍ତର୍ଭାଵ TCCLIB_INC1.TCCLIB_INC2

#ଅନ୍ତର୍ଭାଵ TCCLIB_INC1.h>

#ଅନ୍ତର୍ଭାଵ TCCLIB_INC3

#ଅନ୍ତର୍ଭାଵ <tcclib.h>

#ଅନ୍ତର୍ଭାଵ "tcclib.h"

#ଅନ୍ତର୍ଭାଵ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#ଅନ୍ୟଥା
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#ଅନ୍ତର୍ଭାଵ INC(42test)
#ଅନ୍ତର୍ଭାଵ incname
#ଅନ୍ତର୍ଭାଵ stringify(funnyname)

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fib(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ଶୂନ୍ୟ ଅଙ୍କ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n);
ଶୂନ୍ୟ forward_ref(ଶୂନ୍ୟ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା isid(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
ଶୂନ୍ୟ funny_ଧାଡ଼ି_continuation (ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ..\
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
#define ତଳ_2 ତଳ_2 ", world"

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା onetwothree = 123;
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

#ଯଦି 1
#define B3 1
#ନଚେତଯଦି 1
#define B3 2
#ନଚେତଯଦି 0
#define B3 3
#ଅନ୍ୟଥା
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

ପୂର୍ଣ୍ଣସଂଖ୍ୟା qq(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
    ଫେରନ୍ତୁ x + 40;
}
#define qq(x) x

#define spin_lock(lock) କର { } ଯେତେବେଳେ (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

ଶୂନ୍ୟ macro_test(ଶୂନ୍ୟ)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(ଉପର_2, ତଳ_2));
    printf("s2=%s\n", xglue(ଉପର_2, ତଳ_2));
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
#ଅନ୍ୟଥା
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#ଅନ୍ୟଥା
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#ଅନ୍ୟଥା
    printf("B1 not defined\n");
#endif
#ଅନ୍ୟଥା
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#ଅନ୍ୟଥା
    printf("B2 not defined\n");
#endif
#endif

#ଯଦି 1+1
    printf("test true1\n");
#endif
#ଯଦି 0
    printf("test true2\n");
#endif
#ଯଦି 1-1
    printf("test true3\n");
#endif
#ଯଦି defined(A)
    printf("test trueA\n");
#endif
#ଯଦି defined(B)
    printf("test trueB\n");
#endif

#ଯଦି 0
    printf("test 0\n");
#ନଚେତଯଦି 0
    printf("test 1\n");
#ନଚେତଯଦି 2
    printf("test 2\n");
#ଅନ୍ୟଥା
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
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(ସନ୍ଦେଶ) printf("%s\n",ସନ୍ଦେଶ)

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
#ଯଦି !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ଅଚଳ ଅକ୍ଷର *fn = get_file_from_header();
      ଯଦି (fn[0] == '.' && fn[1] == '/')
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


ସ୍ଥିର ଶୂନ୍ୟ print_ଅଙ୍କ(ଅକ୍ଷର *fn, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ) {
    printf("fn %s, line %d, num %d\n", fn, ଧାଡ଼ି, ଅଙ୍କ);
}

ଶୂନ୍ୟ recursive_macro_test(ଶୂନ୍ୟ)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_ଅଙ୍କ(x) print_ଅଙ୍କ(__FILE__,__LINE__,x)
    print_ଅଙ୍କ(123);
    WRAP(print_ଅଙ୍କ(123));
    WRAP(WRAP(print_ଅଙ୍କ(123)));

ସ୍ଥିର ସଂରଚନା recursive_macro { ପୂର୍ଣ୍ଣସଂଖ୍ୟା rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#ଯଦି __TINYC__
ପୂର୍ଣ୍ଣସଂଖ୍ୟା op(a, b)
{
    ଫେରନ୍ତୁ a / b;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ret(a)
{
    ଯଦି (a == 2)
        ଫେରନ୍ତୁ 1;
    ଯଦି (a == 3)
        ଫେରନ୍ତୁ 2;
    ଫେରନ୍ତୁ 0;
}
#endif

#ଯଦି !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
ଅକ୍ଷର str_ag1[] = "b";
ଅକ୍ଷର str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
ଅକ୍ଷର str_ag3[] = { "ab"[1], 0 };
ଅକ୍ଷର str_x[2] = { "xy" "z"[2], 0 };
#endif
ଅକ୍ଷର *str_ar[] = { "one", "two" };
ସଂରଚନା str_SS {unsigned ଅକ୍ଷର a[3], b; };
ସଂରଚନା str_SS str_sinit15 = { "r" };
ସଂରଚନା str_SS str_sinit16[] = { { "q" }, 2 };

ସ୍ଥିର ଶୂନ୍ୟ string_test2()
{
    ଅକ୍ଷର *p = "hello";
    ଅକ୍ଷର a3[2] = { "p" };
    ଅକ୍ଷର a4[2] = { "ab" "c"[2], 0 };
    ଅକ୍ଷର *pa1 = "def" + 1;
    ଅକ୍ଷର *pa2 = { "xyz" + 1 };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
    ସଂରଚନା str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    ଅକ୍ଷର str_ag3[] = { "ab"[1], 0 };
    ଅକ୍ଷର str_x[2] = { "xy" "z"[2], 0 };
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

ଶୂନ୍ୟ ps(ଅଚଳ ଅକ୍ଷର *s)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ଯେତେବେଳେ (1) {
        c = *s;
        ଯଦି (c == 0)
            ଭାଙ୍ଗ;
        printf("%c", c);
        s++;
    }
}

ଅଚଳ ଅକ୍ଷର foo1_string[] = "\
bar\n\
test\14\
1";

ଶୂନ୍ୟ string_test()
{
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#ଯଦି 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    ଯେତେବେଳେ ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    ଯେତେବେଳେ (b != 0x80000000) {
        ଅଙ୍କ(b);
        b = b * 2;
    }
    string_test2();
}


ଶୂନ୍ୟ if1t(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଯଦି (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    ଯଦି (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    ଯଦି (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    ଯଦି (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    ଯଦି (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    ଯଦି (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    ଯଦି (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    ଯଦି (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    ଯଦି (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ଯଦି (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ଯଦି (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ଯଦି (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ଯଦି (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ଯଦି (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

ଶୂନ୍ୟ if2t(ଶୂନ୍ୟ)
{
    ଯଦି (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

ଶୂନ୍ୟ if3t(ଶୂନ୍ୟ)
{
    ଅସ୍ଥିର long long i = 1;
    ଯଦି (i <= 18446744073709551615ULL)
      ;
    ଅନ୍ୟଥା
      printf ("if3t:wrong 1\n");
}

ଶୂନ୍ୟ if_test(ଶୂନ୍ୟ)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

ଶୂନ୍ୟ loop_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    i = 0;
    ଯେତେବେଳେ (i < 10)
        printf("%d", i++);
    printf("\n");
    ପାଇଁ(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    କର {
        printf("%d", i++);
    } ଯେତେବେଳେ (i < 10);
    printf("\n");

    ଅକ୍ଷର ଗଣନା_3 = 123;
    /* c99 for loop init test */
    ପାଇଁ (size_t ଗଣନା_3 = 1; ଗଣନା_3 < 3; ଗଣନା_3++)
        printf("count=%d\n", ଗଣନା_3);
    printf("count = %d\n", ଗଣନା_3);

    /* break/continue tests */
    i = 0;
    ଯେତେବେଳେ (1) {
        ଯଦି (i == 6)
            ଭାଙ୍ଗ;
        i++;
        ଯଦି (i == 3)
            ଜାରି;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    କର {
        ଯଦି (i == 6)
            ଭାଙ୍ଗ;
        i++;
        ଯଦି (i == 3)
            ଜାରି;
        printf("%d", i);
    } ଯେତେବେଳେ(1);
    printf("\n");

    ପାଇଁ(i = 0;i < 10;i++) {
        ଯଦି (i == 3)
            ଜାରି;
        printf("%d", i);
    }
    printf("\n");
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା typedef_and_label;

ଶୂନ୍ୟ goto_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ସ୍ଥିର ଶୂନ୍ୟ *label_table[3] = { &&label1, &&label2, &&label3 };
    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା bla;
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
    ଯଦି (i >= 10) 
        ଯାଅ s_end;
    printf("%d", i);
    i++;
    ଯାଅ s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    ପାଇଁ(i=0;i<3;i++) {
        ଯାଅ *label_table[i];
    label1:
        printf("label1\n");
        ଯାଅ next;
    label2:
        printf("label2\n");
        ଯାଅ next;
    label3:
        printf("label3\n");
    next: ;
    }
}

ଗଣନା {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ଗଣନା test {
    E5 = 1000,
};

ସଂରଚନା S_enum {
    ଗଣନା {E6 = 42, E7, E8} e:8;
};

ଗଣନା ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

ଗଣନା { BIASU = -1U<<31 };
ଗଣନା { BIASS = -1 << 31 };

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା getint(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  ଯଦି (i)
    ଫେରନ୍ତୁ 0;
  ଅନ୍ୟଥା
    ଫେରନ୍ତୁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(-1U << 31);
}

ଶୂନ୍ୟ enum_test()
{
    ଗଣନା test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    ସଂରଚନା S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    ଯଦି (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    ଅନ୍ୟଥା
      printf("enum unsigned: wrong\n");
    ଯଦି (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    ଅନ୍ୟଥା
      printf("enum unsigned: wrong\n");
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *my_ptr;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା mytype1;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା mytype2;

ଶୂନ୍ୟ typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

ଶୂନ୍ୟ forward_test()
{
    forward_ref();
    forward_ref();
}


ଶୂନ୍ୟ forward_ref(ଶୂନ୍ୟ)
{
    printf("forward ok\n");
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା struct1 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା f2, f3;
    ସଂଘ union1 {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା v2;
    } u;
    ଅକ୍ଷର str[3];
} struct1;

ସଂରଚନା struct2 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ଅକ୍ଷର b;
};

ସଂଘ union2 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା w1;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା w2;
};

ସଂରଚନା struct1 st1, st2;

ସଂରଚନା empty_mem {
    /* nothing */ ;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab[3];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab2[3][2];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା g;

ଶୂନ୍ୟ f1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା g)
{
    printf("g1=%d\n", g);
}

ଶୂନ୍ୟ scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା g;
        g = 3;
        printf("g3=%d\n", g);
        {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା st2_i;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା *st2_p = &st2_i;
ଶୂନ୍ୟ scope2_test()
{
    ଅକ୍ଷର a[50];
    st2_i = 42;
    ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା st2_i = 1; st2_i < 10; st2_i++) {
        ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global1;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global1=42;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global1;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global1;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global2;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global2;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global2;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା st_global2;

ଶୂନ୍ୟ array_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, a[4];

    printf("sizeof(a) = %d\n", ଆକାର(a));
    printf("sizeof(\"a\") = %d\n", ଆକାର("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", ଆକାର(__func__));
#endif
    printf("sizeof tab %d\n", ଆକାର(tab));
    printf("sizeof tab2 %d\n", ଆକାର tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    ପାଇଁ(i=0;i<3;i++)
        ପାଇଁ(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    ପାଇଁ(i=0;i<3*2;i++) {
        printf(" %3d", ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", ଆକାର(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", ଆକାର(ptrdiff_t));
}

ଶୂନ୍ୟ ପଦସମଷ୍ଟି_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା isid(ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଫେରନ୍ତୁ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

ପୂର୍ଣ୍ଣସଂଖ୍ୟା vstack[10], *vstack_ptr;

ଶୂନ୍ୟ vpush(ପୂର୍ଣ୍ଣସଂଖ୍ୟା vt, ପୂର୍ଣ୍ଣସଂଖ୍ୟା vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

ଶୂନ୍ୟ vpop(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ft, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

ଶୂନ୍ୟ expr2_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା const_len_ar[ଆକାର(1/0)]; /* div-by-zero, but in unevaluated context */

ଶୂନ୍ୟ constant_ପଦସମଷ୍ଟି_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", ଆକାର(const_len_ar));
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab4[10];

ଶୂନ୍ୟ ପଦସମଷ୍ଟି_ptr_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[10], *p, *q;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = -1;

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
    p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)((ଅକ୍ଷର *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ସଂରଚନା size12 {
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j, k;
        };
        ସଂରଚନା size12 s[2], *sp = s;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((p - q) / 3));
}

ଶୂନ୍ୟ ପଦସମଷ୍ଟି_cmp_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;
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

ସଂରଚନା empty {
};

ସଂରଚନା aligntest1 {
    ଅକ୍ଷର a[10];
};

ସଂରଚନା aligntest2 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ଅକ୍ଷର b[10];
};

ସଂରଚନା aligntest3 {
    ଦ୍ୱିଗୁଣ a, b;
};

ସଂରଚନା aligntest4 {
    ଦ୍ୱିଗୁଣ a[0];
};

ସଂରଚନା __attribute__((aligned(16))) aligntest5
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
};
ସଂରଚନା aligntest6
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
} __attribute__((aligned(16)));
ସଂରଚନା aligntest7
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
};
ସଂରଚନା aligntest5 altest5[2];
ସଂରଚନା aligntest6 altest6[2];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ସଂରଚନା aligntest7 altest7[2] __attribute__((aligned(16)));

ସଂରଚନା aligntest8
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
} __attribute__((aligned(4096)));

ସଂରଚନା Large {
    unsigned long flags;
    ସଂଘ {
	ଶୂନ୍ୟ *u1;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା *u2;
    };

    ସଂରଚନା {
	ସଂଘ {
	    unsigned long index;
	    ଶୂନ୍ୟ *freelist;
	};
	ସଂଘ {
	    unsigned long counters;
	    ସଂରଚନା {
		ପୂର୍ଣ୍ଣସଂଖ୍ୟା bla;
	    };
	};
    };

    ସଂଘ {
	ସଂରଚନା {
	    long u3;
	    long u4;
	};
	ଶୂନ୍ୟ *u5;
	ସଂରଚନା {
	    unsigned long compound_head;
	    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା compound_dtor;
	    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା compound_order;
	};
    };
} __attribute__((aligned(2 * ଆକାର(long))));

ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long long __attribute__((aligned(4))) unaligned_u64;

ସଂରଚନା aligntest9 {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା buf_nr;
    unaligned_u64 start_lba;
};

ସଂରଚନା aligntest10 {
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା buf_nr;
    unsigned long long start_lba;
};

ଶୂନ୍ୟ struct_test()
{
    struct1 *s;
    ସଂଘ union2 u;
    ସଂରଚନା Large ls;

    printf("sizes: %d %d %d %d\n",
           ଆକାର(ସଂରଚନା struct1),
           ଆକାର(ସଂରଚନା struct2),
           ଆକାର(ସଂଘ union1),
           ଆକାର(ସଂଘ union2));
    printf("offsets: %d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((ଅକ୍ଷର*)&st1.u.v1 - (ଅକ୍ଷର*)&st1));
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
    printf("str_addr=%x\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(uintptr_t)st1.str - (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest1), __alignof__(ସଂରଚନା aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest2), __alignof__(ସଂରଚନା aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest3), __alignof__(ସଂରଚନା aligntest3));
#ଯଦି !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest4), __alignof__(ସଂରଚନା aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest5), __alignof__(ସଂରଚନା aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest6), __alignof__(ସଂରଚନା aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest7), __alignof__(ସଂରଚନା aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest8), __alignof__(ସଂରଚନା aligntest8));
#ଯଦି !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest9), __alignof__(ସଂରଚନା aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           ଆକାର(ସଂରଚନା aligntest10), __alignof__(ସଂରଚନା aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           ଆକାର(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           ଆକାର(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           ଆକାର(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ଯଦି !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", ଆକାର(ସଂରଚନା empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(ସଂରଚନା empty));

    printf("Large: sizeof=%d\n", ଆକାର(ls));
    memset(&ls, 0, ଆକାର(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)((ଅକ୍ଷର*)&ls.compound_head - (ଅକ୍ଷର*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା __csf(ପୂର୍ଣ୍ଣସଂଖ୍ୟା x) { ଫେରନ୍ତୁ x; }
ସ୍ଥିର ଶୂନ୍ୟ *_csf = __csf;
#define csf(t,n) ((t(*)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା))_csf)(n)

/* XXX: depend on endianness */
ଶୂନ୍ୟ char_short_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା var1, var2;
    signed ଅକ୍ଷର var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed ଅକ୍ଷର *)&var1, *(signed ଅକ୍ଷର *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned ଅକ୍ଷର *)&var1, *(unsigned ଅକ୍ଷର *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)&var1, *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)&var1, *(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)&var2);
    *(signed ଅକ୍ଷର *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed ଅକ୍ଷର)(var1 + 1), (signed ଅକ୍ଷର)(var4 + 1));
#ଯଦି !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned ଅକ୍ଷର,0x89898989);
    var4 = csf(signed ଅକ୍ଷର,0xabababab);
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
    var1 = (signed ଅକ୍ଷର)(unsigned ଅକ୍ଷର)(var3 + 1);
    var4 = (signed ଅକ୍ଷର)(unsigned ଅକ୍ଷର)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed ଅକ୍ଷର)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Sym {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
    ସଂରଚନା Sym *next;
    ସଂରଚନା Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା toupper1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ଫେରନ୍ତୁ TOUPPER(a);
}

ସ୍ଥିର unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା calc_vm_flags(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା prot)
{
  unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ଫେରନ୍ତୁ prot_bits;
}

ଗଣନା cast_enum { FIRST, LAST };

ସ୍ଥିର ଶୂନ୍ୟ tst_cast(ଗଣନା cast_enum ce)
{
    printf("%d\n", ce);
}

ଶୂନ୍ୟ bool_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *s, a, b, t, f, i;

    a = 0;
    s = (ଶୂନ୍ୟ*)0;
    printf("!s=%d\n", !s);

    ଯଦି (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ଯଦି 1 && 1
    printf("a1\n");
#endif
#ଯଦି 1 || 0
    printf("a2\n");
#endif
#ଯଦି 1 ? 0 : 1
    printf("a3\n");
#endif
#ଯଦି 0 ? 0 : 1
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
    printf("type of bool: %d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା) ( (~ ((unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା)0)) / 2 );
    /* test ? : cast */
    {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା aspect_on;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା aspect_native = 65536;
        ଦ୍ୱିଗୁଣ bfu_aspect = 1.0;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା aspect;
        ପାଇଁ(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା v1 = 34 ? : -1; /* constant case */
        ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା v2 = 0 ? : -1; /* constant case */
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    ପାଇଁ(i=0;i<256;i++) {
        ଯଦି (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା undefined_function(ଶୂନ୍ୟ);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା defined_function(ଶୂନ୍ୟ);

#ifdef __clang__
ପୂର୍ଣ୍ଣସଂଖ୍ୟା undefined_function(ଶୂନ୍ୟ) {}
#endif

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ refer_to_undefined(ଶୂନ୍ୟ)
{
  undefined_function();
}

ଶୂନ୍ୟ optimize_out_test(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  ଯଦି (0)
    printf("oo:%d\n", undefined_function());
  ଅନ୍ୟଥା
    printf("oo:%d\n", defined_function());
  ଯଦି (1)
    printf("oo:%d\n", defined_function());
  ଅନ୍ୟଥା
    printf("oo:%d\n", undefined_function());
  ଯେତେବେଳେ (1) {
      printf("oow:%d\n", defined_function());
      ଭାଙ୍ଗ;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ବାଛ (j)
    ସ୍ଥିତି 1: ଭାଙ୍ଗ;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ଯେତେବେଳେ (1)
    ଭାଙ୍ଗ;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  କର
    ଭାଙ୍ଗ;
  ଯେତେବେଳେ (1);
  printf ("ool2:%d\n", defined_function());
  ପାଇଁ (;;)
    ଭାଙ୍ଗ;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ଯେତେବେଳେ (1) {
	{
	  ଭାଙ୍ଗ;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ଯେତେବେଳେ (j) {
      ଯଦି (j == 0)
	ଭାଙ୍ଗ; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ଯେତେବେଳେ (j) {
      ଯଦି (1)
	j--;
      ଅନ୍ୟଥା
	breakhere: ଭାଙ୍ଗ;
      printf("ool6:%d\n", defined_function());
      ଯାଅ breakhere;
  }
  j = 1;
  ଯେତେବେଳେ (j) {
      j--;
      ଜାରି;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ଯଦି (0 && undefined_function())
    undefined_function();
  ଯଦି (defined_function() && 0)
    undefined_function();
  ଯଦି (0 && 0)
    undefined_function();
  ଯଦି (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ଯଦି (1 || undefined_function())
    ;
  ଅନ୍ୟଥା
    undefined_function();
  ଯଦି (defined_function() || 1)
    ;
  ଅନ୍ୟଥା
    undefined_function();
  ଯଦି (1 || 1)
    ;
  ଅନ୍ୟଥା
    undefined_function();
  ଯଦି (defined_function() || 1 || undefined_function())
    ;
  ଅନ୍ୟଥା
    undefined_function();

  ଯଦି (defined_function() && 0)
    refer_to_undefined();

  ଯଦି (0) {
      (ଶୂନ୍ୟ)ଆକାର( ({
		     କର { } ଯେତେବେଳେ (0);
		     0;
		     }) );
      undefined_function();
  }

  ଯଦି (0) {
      ବାଛ (defined_function()) {
          ସ୍ଥିତି 0: undefined_function(); ଭାଙ୍ଗ;
          ପୂର୍ବନିର୍ଦ୍ଧାରିତ: undefined_function(); ଭାଙ୍ଗ;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ଯଦି (1)
    ଫେରନ୍ତୁ;
  printf ("oor:%d\n", undefined_function());
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା defined_function(ଶୂନ୍ୟ)
{
  ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 40;
  ଫେରନ୍ତୁ i++;
}

/* GCC accepts that */
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab_reinit[];
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab_reinit[10];

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tentative_ar[];
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା tentative_ar[] = {1,2,3};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା cinit1; /* a global variable can be defined several times without error ! */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା cinit1; 
ପୂର୍ଣ୍ଣସଂଖ୍ୟା cinit1 = 0;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା *cinit2 = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
ଅକ୍ଷର ଅଚଳ * ଅଚଳ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
ଶୂନ୍ୟ *cinit52 = &(ଶୂନ୍ୟ*){ (ଶୂନ୍ୟ*) 52 };

#ଯଦି __TINYC__ || __GNUC__ >= 6
ପୂର୍ଣ୍ଣସଂଖ୍ୟା cinit4 = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା){44};
ଶୂନ୍ୟ *cinit51 = (ଶୂନ୍ୟ*){ (ଶୂନ୍ୟ*) 51 };
ସଂରଚନା _c6 { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b; } cinit6 = (ସଂରଚନା _c6){61,62}, *cinit7 = &(ସଂରଚନା _c6){71,72};
#ଅନ୍ୟଥା
ପୂର୍ଣ୍ଣସଂଖ୍ୟା cinit4 = 44;
ଶୂନ୍ୟ *cinit51 = (ଶୂନ୍ୟ*)51;
ସଂରଚନା _c6 { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

ଶୂନ୍ୟ compound_literal_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p, i;
    ଅକ୍ଷର *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)cinit51);
    printf("cinit52 : %d\n", *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା []){1, 2, 3};
    ପାଇଁ(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    ପାଇଁ(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (ଅକ୍ଷର *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (ଅକ୍ଷର *){ q };
    printf("q3=%s\n", q3);

    q = (ଅକ୍ଷର []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା []){1, 2, cinit1 + 3};
    ପାଇଁ(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    ପାଇଁ(i=0;i<3;i++) {
        p = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#ଯଦି __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ଫେରନ୍ତୁ a + b;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା kr_func2(a, b)
{
    ଫେରନ୍ତୁ a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    ଫେରନ୍ତୁ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
ଅକ୍ଷର invalid_function_def()[] {ଫେରନ୍ତୁ 0;}

#ଅନ୍ୟଥା
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

ଶୂନ୍ୟ ଅଙ୍କ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଅକ୍ଷର *tab, *p;
    tab = (ଅକ୍ଷର*)malloc(20); 
    p = tab;
    ଯେତେବେଳେ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ଯଦି (n == 0)
            ଭାଙ୍ଗ;
    }
    ଯେତେବେଳେ (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    ମୁକ୍ତ(tab);
}

/* structure assignment tests */
ସଂରଚନା structa1 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1;
    ଅକ୍ଷର f2;
};

ଶୂନ୍ୟ struct_assign_test1(ସଂରଚନା structa1 s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t, ଦଶମିକ f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ସଂରଚନା structa1 struct_assign_test2(ସଂରଚନା structa1 s1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ଫେରନ୍ତୁ s1;
}

ଶୂନ୍ୟ struct_assign_test(ଶୂନ୍ୟ)
{
    ସଂରଚନା S {
      ସଂରଚନା structa1 lsta1, lsta2;
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ସ୍ଥିର ସଂରଚନା {
        ଶୂନ୍ୟ (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

ଶୂନ୍ୟ cast1(ଅକ୍ଷର a, short b, unsigned ଅକ୍ଷର c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

ଅକ୍ଷର bcast;
short scast;

ଶୂନ୍ୟ cast_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ଅକ୍ଷର c;
    ଅକ୍ଷର tab[10];
    unsigned b,d;
    short s;
    ଅକ୍ଷର *p = ଖାଲି;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (ଅକ୍ଷର)(a + 1),
           (short)(a + 1),
           (unsigned ଅକ୍ଷର)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (ଅକ୍ଷର)0xfffff,
           (short)0xfffff,
           (unsigned ଅକ୍ଷର)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", ଆକାର(c), ଆକାର((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (ଅକ୍ଷର)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", ଆକାର(+(ଅକ୍ଷର)'a'));
    printf("sizeof(-(char)'a') = %d\n", ଆକାର(-(ଅକ୍ଷର)'a'));
    printf("sizeof(~(char)'a') = %d\n", ଆକାର(-(ଅକ୍ଷର)'a'));

#ଯଦି CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)p, (unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (ଶୂନ୍ୟ *)a, (ଶୂନ୍ୟ *)b, (ଶୂନ୍ୟ *)c, (ଶୂନ୍ୟ *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)ul);
}

/* initializers tests */
ସଂରଚନା structinit1 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1;
    ଅକ୍ଷର f2;
    short f3;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା farray[3];
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit1 = 2;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit2 = { 3 };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit3[3] = { 1, 2, {3}, };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit6[] = { 1, 2, 3 };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit7[] = { [2] = 3, [0] = 1, 2 };
ଅକ୍ଷର sinit8[] = "hello" "trala";

ସଂରଚନା structinit1 sinit9 = { 1, 2, 3 };
ସଂରଚନା structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ସଂରଚନା structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

ଅକ୍ଷର *sinit12 = "hello world";
ଅକ୍ଷର *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
ଅକ୍ଷର sinit14[10] = { "abc" };
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit15[3] = { ଆକାର(sinit15), 1, 2 };

ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[3], b; } sinit16[] = { { 1 }, 2 };

ସଂରଚନା bar {
        ଅକ୍ଷର *s;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ସଂରଚନା complexinit0 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
};

ସଂରଚନା complexinit {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ଅଚଳ ସଂରଚନା complexinit0 *b;
};

ଅଚଳ ସ୍ଥିର ସଂରଚନା complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ଅଚଳ ସଂରଚନା complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ସଂରଚନା complexinit2 {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା b[];
};

ସଂରଚନା complexinit2 cix20;

ସଂରଚନା complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ସଂରଚନା complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit23[2] = { "astring" ? ଆକାର("astring") : -1,
		   &sinit23 ? 42 : -1 };

ପୂର୍ଣ୍ଣସଂଖ୍ୟା sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ସଂରଚନା bf_SS {unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା bit:1,bits31:31; };
ସଂରଚନା bf_SS bf_init = { .bit = 1 };
ସଂରଚନା bfn_SS {ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b; ସଂରଚନା bf_SS c; ପୂର୍ଣ୍ଣସଂଖ୍ୟା d,e; };
ସଂରଚନା bfn_SS bfn_init = { .c.bit = 1 };
ସଂରଚନା bfa_SS {ପୂର୍ଣ୍ଣସଂଖ୍ୟା a,b; ସଂରଚନା bf_SS c[3]; ପୂର୍ଣ୍ଣସଂଖ୍ୟା d,e; };
ସଂରଚନା bfa_SS bfa_init = { .c[1].bit = 1 };
ସଂରଚନା bf_SS bfaa_init[3] = { [1].bit = 1 };
ସଂରଚନା bf_SS bfaa_vinit[] = { [2].bit = 1 };
ସଂରଚନା b2_SS {long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା field : 52; long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା pad : 12; };
ସଂରଚନା b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା external_inited = 42;

ଶୂନ୍ୟ init_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit1 = 2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit2 = { 3 };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit6[] = { 1, 2, 3 };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, j;
    ଅକ୍ଷର linit8[] = "hello" "trala";
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit12[10] = { 1, 2 };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    ଅକ୍ଷର linit14[10] = "abc";
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ସଂରଚନା linit16 { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit17 = ଆକାର(linit17);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ସଂରଚନା bf_SS bf_finit = { .bit = 1 };
    ସଂରଚନା bfn_SS bfn_finit = { .c.bit = 1 };
    ସଂରଚନା bfa_SS bfa_finit = { .c[1].bit = 1 };
    ସଂରଚନା bf_SS bfaa_finit[3] = { [1].bit = 1 };
    ସଂରଚନା bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    ସଂରଚନା b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           ଆକାର(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", ଆକାର(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           ଆକାର(sinit7),
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

    ପାଇଁ(i=0;i<3;i++)
        ପାଇଁ(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", ଆକାର(linit6));
    printf("linit8=%d %s\n", ଆକାର(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           ଆକାର(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    ପାଇଁ(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    ପାଇଁ(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    ପାଇଁ(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    ପାଇଁ(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    ପାଇଁ(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", ଆକାର cix20, ଆକାର cix21, ଆକାର cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", ଆକାର(sinit19), ଆକାର(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", ଆକାର(sinit21), ଆକାର(sinit22));
    printf("arrtype6: %d\n", ଆକାର(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    ପାଇଁ (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

ଶୂନ୍ୟ switch_uc(unsigned ଅକ୍ଷର uc)
{
	ବାଛ (uc) {
	    ସ୍ଥିତି 0xfb ... 0xfe:
		printf("ucsw:1\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 0xff:
		printf("ucsw:2\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 0 ... 5:
		printf("ucsw:3\n");
		ଭାଙ୍ଗ;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		printf("ucsw: broken!\n");
	}
}

ଶୂନ୍ୟ switch_sc(signed ଅକ୍ଷର sc)
{
	ବାଛ (sc) {
	    ସ୍ଥିତି -5 ... -2:
		printf("scsw:1\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି -1:
		printf("scsw:2\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 0 ... 5:
		printf("scsw:3\n");
		ଭାଙ୍ଗ;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		printf("scsw: broken!\n");
	}
}

ଶୂନ୍ୟ switch_test()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    unsigned long long ull;
    long long ll;

    ପାଇଁ(i=0;i<15;i++) {
        ବାଛ(i) {
        ସ୍ଥିତି 0:
        ସ୍ଥିତି 1:
            printf("a");
            ଭାଙ୍ଗ;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            printf("%d", i);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 8 ... 12:
            printf("c");
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 3:
            printf("b");
            ଭାଙ୍ଗ;
        ସ୍ଥିତି 0xc33c6b9fU:
        ସ୍ଥିତି 0x7c9eeeb9U:
            ଭାଙ୍ଗ;
        }
    }
    printf("\n");

    ପାଇଁ (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	ବାଛ (ull) {
	    ସ୍ଥିତି 1ULL << 61:
		printf("ullsw:1\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 2ULL << 61:
		printf("ullsw:2\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 3ULL << 61:
		printf("ullsw:3\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 4ULL << 61:
		printf("ullsw:4\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 5ULL << 61:
		printf("ullsw:5\n");
		ଭାଙ୍ଗ;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		printf("ullsw: broken!\n");
	}
    }

    ପାଇଁ (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	ବାଛ (ll) {
	    ସ୍ଥିତି 1LL << 61:
		printf("llsw:1\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 2LL << 61:
		printf("llsw:2\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 3LL << 61:
		printf("llsw:3\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 4LL << 61:
		printf("llsw:4\n");
		ଭାଙ୍ଗ;
	    ସ୍ଥିତି 5LL << 61:
		printf("llsw:5\n");
		ଭାଙ୍ଗ;
	    ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
		printf("llsw: broken!\n");
	}
    }

    ପାଇଁ (i = -5; i <= 5; i++) {
	switch_uc((unsigned ଅକ୍ଷର)i);
    }

    ପାଇଁ (i = -5; i <= 5; i++) {
	switch_sc ((signed ଅକ୍ଷର)i);
    }
}

/* ISOC99 _Bool type */
ଶୂନ୍ୟ c99_bool_test(ଶୂନ୍ୟ)
{
#ifdef BOOL_ISOC99
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", ଆକାର(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           ଆକାର ((ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା)a ? b : b2));
#endif
}

ଶୂନ୍ୟ bitfield_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    short sa;
    unsigned ଅକ୍ଷର ca;
    ସଂରଚନା sbf1 {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1 : 3;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା : 2;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f2 : 1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା : 0;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f3 : 5;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f4 : 7;
        unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", ଆକାର(st1));

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
    ଯଦି (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    ଅନ୍ୟଥା 
        printf("st1.f1 != -1\n");
    ଯଦି (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    ଅନ୍ୟଥା 
        printf("st1.f2 != -1\n");

    ସଂରଚନା sbf2 {
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

#ଯଦି 0
    Disabled ପାଇଁ now until further clarification re GCC compatibility
    ସଂରଚନା sbf3 {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f1 : 7;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f2 : 1;
        ଅକ୍ଷର f3;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f4 : 8;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f5 : 1;
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", ଆକାର(st3));
#endif

    ସଂରଚନା sbf4 {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା x : 31;
	ଅକ୍ଷର y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    ସଂରଚନା sbf5 {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
	ଅକ୍ଷର b;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା x : 12, y : 4, : 0, : 4, z : 3;
	ଅକ୍ଷର c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ସଂରଚନା sbf6 {
	short x : 12;
	unsigned ଅକ୍ଷର y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#ଅନ୍ୟଥା
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
ଦ୍ୱିଗୁଣ strtod(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr);

#ଯଦି defined(_WIN32)
ଦଶମିକ strtof(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr) {ଫେରନ୍ତୁ (ଦଶମିକ)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr) {ଫେରନ୍ତୁ (LONG_DOUBLE)strtod(nptr, endptr);}
#ଅନ୍ୟଥା
ଦଶମିକ strtof(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr);
LONG_DOUBLE strtold(ଅଚଳ ଅକ୍ଷର *nptr, ଅକ୍ଷର **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
ଶୂନ୍ୟ prefix ## cmp(type a, type b)\
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
ଶୂନ୍ୟ prefix ## fcast(type a)\
{\
    ଦଶମିକ fa;\
    ଦ୍ୱିଗୁଣ da;\
    LONG_DOUBLE la;\
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ia;\
    long long llia;\
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (ପୂର୍ଣ୍ଣସଂଖ୍ୟା)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା)a;\
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
    ଯଦି (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
ଦଶମିକ prefix ## retf(type a) { ଫେରନ୍ତୁ a; }\
ଦ୍ୱିଗୁଣ prefix ## retd(type a) { ଫେରନ୍ତୁ a; }\
LONG_DOUBLE prefix ## retld(type a) { ଫେରନ୍ତୁ a; }\
\
ଶୂନ୍ୟ prefix ## call(ଶୂନ୍ୟ)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (ଦ୍ୱିଗୁଣ)strto ## prefix("1.2", ଖାଲି));\
}\
\
ଶୂନ୍ୟ prefix ## signed_zeros(ଶୂନ୍ୟ) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ଯଦି (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ଅନ୍ୟଥା\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  ଯଦି (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ଅନ୍ୟଥା\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ଯଦି (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ଅନ୍ୟଥା\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  ଯଦି (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ଅନ୍ୟଥା\
    printf ("x != -y; this is wrong!\n");\
}\
ଶୂନ୍ୟ prefix ## nan(ଶୂନ୍ୟ)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
ଶୂନ୍ୟ prefix ## test(ଶୂନ୍ୟ)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    ଯଦି (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, ଦଶମିକ, ଦଶମିକ, "%f")
FTEST(d, ଦ୍ୱିଗୁଣ, ଦ୍ୱିଗୁଣ, "%f")
FTEST(ld, long ଦ୍ୱିଗୁଣ, LONG_DOUBLE, "%Lf")

ଦ୍ୱିଗୁଣ ftab1[3] = { 1.2, 3.4, -5.6 };


ଶୂନ୍ୟ float_test(ଶୂନ୍ୟ)
{
#ଯଦି !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    ଅସ୍ଥିର ଦଶମିକ fa, fb;
    ଅସ୍ଥିର ଦ୍ୱିଗୁଣ da, db;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
    ସ୍ଥିର ଦ୍ୱିଗୁଣ nan2 = 0.0/0.0;
    ସ୍ଥିର ଦ୍ୱିଗୁଣ inf1 = 1.0/0.0;
    ସ୍ଥିର ଦ୍ୱିଗୁଣ inf2 = 1e5000;
    ଅସ୍ଥିର LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", ଆକାର(ଦଶମିକ));
    printf("sizeof(double) = %d\n", ଆକାର(ଦ୍ୱିଗୁଣ));
    printf("sizeof(long double) = %d\n", ଆକାର(LONG_DOUBLE));
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

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fib(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ଯଦି (n <= 2)
        ଫେରନ୍ତୁ 1;
    ଅନ୍ୟଥା
        ଫେରନ୍ତୁ fib(n-1) + fib(n-2);
}

#ଯଦି __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ଅନ୍ୟଥା
ଶୂନ୍ୟ __attribute__((aligned(16))) aligned_function(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i) {}
#endif

ଶୂନ୍ୟ funcptr_test()
{
    ଶୂନ୍ୟ (*func)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ସଂରଚନା {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy;
        ଶୂନ୍ୟ (*func)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    } st1;
    long diff;

    func = &ଅଙ୍କ;
    (*func)(12345);
    func = ଅଙ୍କ;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = ଅଙ୍କ;
    st1.func(12346);
    printf("sizeof1 = %d\n", ଆକାର(funcptr_test));
    printf("sizeof2 = %d\n", ଆକାର funcptr_test);
    printf("sizeof3 = %d\n", ଆକାର(&funcptr_test));
    printf("sizeof4 = %d\n", ଆକାର &funcptr_test);
    a = 0;
    func = ଅଙ୍କ + a;
    diff = func - ଅଙ୍କ;
    func(42);
    (func + diff)(42);
    (ଅଙ୍କ + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(uintptr_t)func) & 15);
}

ଶୂନ୍ୟ lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ଯଦି (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ଦ୍ୱିମିକ*/
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

ଶୂନ୍ୟ llshift(long long a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
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

ଶୂନ୍ୟ llfloat(ଶୂନ୍ୟ)
{
    ଦଶମିକ fa;
    ଦ୍ୱିଗୁଣ da;
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

long long llfunc1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ଫେରନ୍ତୁ a * 2;
}

ସଂରଚନା S {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା id; 
    ଅକ୍ଷର item;
};

long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ(ସଂରଚନା S *v)
{
    ଫେରନ୍ତୁ ((long long ପୂର୍ଣ୍ଣସଂଖ୍ୟା)v->item);
}

long long llfunc2(long long x, long long y, ପୂର୍ଣ୍ଣସଂଖ୍ୟା z)
{
    ଫେରନ୍ତୁ x * y * z;
}

ଶୂନ୍ୟ check_opl_save_regs(ଅକ୍ଷର *a, long long b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    *a = b < 0 && !c;
}

ଶୂନ୍ୟ longlong_test(ଶୂନ୍ୟ)
{
    long long a, b, c;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା ia;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ua;
    printf("sizeof(long long) = %d\n", ଆକାର(long long));
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
#ଯଦି 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          ସଂରଚନା S a;

          a.item = 3;
          printf("%lld\n", ମୂଲ୍ୟ(&a));
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
    u = (unsigned)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    ଅକ୍ଷର cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

ଶୂନ୍ୟ manyarg_test(ଶୂନ୍ୟ)
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

ଶୂନ୍ୟ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ସଂରଚନା X { ପୂର୍ଣ୍ଣସଂଖ୍ୟା _x; };
        ସଂରଚନା X *x = va_arg(ap, ସଂରଚନା X *);
        ଫେରନ୍ତୁ x;
}

ଶୂନ୍ୟ vprintf1(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list ap, aq;
    ଅଚଳ ଅକ୍ଷର *p;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, i;
    ଦ୍ୱିଗୁଣ d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    ପାଇଁ(;;) {
        c = *p;
        ଯଦି (c == '\0')
            ଭାଙ୍ଗ;
        p++;
        ଯଦି (c == '%') {
            c = *p;
            ବାଛ(c) {
            ସ୍ଥିତି '\0':
                ଯାଅ the_end;
            ସ୍ଥିତି 'd':
                i = va_arg(ap, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
                printf("%d", i);
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'f':
                d = va_arg(ap, ଦ୍ୱିଗୁଣ);
                printf("%f", d);
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                ଭାଙ୍ଗ;
            ସ୍ଥିତି 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                ଭାଙ୍ଗ;
            }
            p++;
        } ଅନ୍ୟଥା {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

ସଂରଚନା myspace {
    short ପୂର୍ଣ୍ଣସଂଖ୍ୟା profile;
};
ସଂରଚନା myspace2 {
#ଯଦି CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    ଅକ୍ଷର a[1];
#ଅନ୍ୟଥା
    ଅକ୍ଷର a[0];
#endif
};
ସଂରଚନା myspace3 {
    ଅକ୍ଷର a[1];
};
ସଂରଚନା myspace4 {
    ଅକ୍ଷର a[2];
};
ସଂରଚନା mytest {
    ଶୂନ୍ୟ *foo, *bar, *baz;
};

ସଂରଚନା mytest stdarg_for_struct(ସଂରଚନା myspace bob, ...)
{
    ସଂରଚନା myspace george, bill;
    ସଂରଚନା myspace2 alex1;
    ସଂରଚନା myspace3 alex2;
    ସଂରଚନା myspace4 alex3;
    va_list ap;
    short ପୂର୍ଣ୍ଣସଂଖ୍ୟା validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ସଂରଚନା myspace2);
    alex2    = va_arg(ap, ସଂରଚନା myspace3);
    alex3    = va_arg(ap, ସଂରଚନା myspace4);
    bill     = va_arg(ap, ସଂରଚନା myspace);
    george   = va_arg(ap, ସଂରଚନା myspace);
    validate = va_arg(ap, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ଫେରନ୍ତୁ (ସଂରଚନା mytest) {};
}

ଶୂନ୍ୟ stdarg_for_libc(ଅଚଳ ଅକ୍ଷର *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

ଶୂନ୍ୟ stdarg_syntax(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n, ...)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    va_list ap;
    ଯଦି (1)
      va_start(ap, n);
    ଅନ୍ୟଥା
      ;
    i = va_arg(ap, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା{
    ଦ୍ୱିଗୁଣ x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ସ୍ଥିର ଶୂନ୍ୟ stdarg_double_struct(ପୂର୍ଣ୍ଣସଂଖ୍ୟା nargs, ପୂର୍ଣ୍ଣସଂଖ୍ୟା posd,...)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ଦ୍ୱିଗୁଣ d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    ପାଇଁ(i = 0; i < nargs; i++) {
        ଯଦି (i == posd) {
            d = va_arg (args, ଦ୍ୱିଗୁଣ);
            printf ("d %d = %g\n", i, d);
        }
        ଅନ୍ୟଥା {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

ଶୂନ୍ୟ stdarg_test(ଶୂନ୍ୟ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ସଂରଚନା myspace bob;
    ସଂରଚନା myspace2 bob2;
    ସଂରଚନା myspace3 bob3;
    ସଂରଚନା myspace4 bob4;

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
#ଯଦି !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା reltab[3] = { 1, 2, 3 };

ପୂର୍ଣ୍ଣସଂଖ୍ୟା *rel1 = &reltab[1];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା *rel2 = &reltab[2];

ଶୂନ୍ୟ getmyaddress(ଶୂନ୍ୟ)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(ଶୂନ୍ୟ)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ଫେରନ୍ତୁ ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
ଶୂନ୍ୟ relocation_test(ଶୂନ୍ୟ)
{
    ଶୂନ୍ୟ (*fptr)(ଶୂନ୍ୟ) = (ଶୂନ୍ୟ (*)(ଶୂନ୍ୟ))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

ଶୂନ୍ୟ old_style_f(a,b,c)
     ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b;
     ଦ୍ୱିଗୁଣ c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

ଶୂନ୍ୟ decl_func1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ଶୂନ୍ୟ decl_func2(cmpfn)
ପୂର୍ଣ୍ଣସଂଖ୍ୟା cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ଶୂନ୍ୟ old_style_function_test(ଶୂନ୍ୟ)
{
#ଯଦି CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ଅନ୍ୟଥା
    old_style_f((ଶୂନ୍ୟ *)1, 2, 3.0);
#endif
    decl_func1(ଖାଲି);
    decl_func2(ଖାଲି);
}

ଶୂନ୍ୟ alloca_test()
{
    ଅକ୍ଷର *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    ଅକ୍ଷର *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

ଶୂନ୍ୟ *bounds_checking_is_enabled()
{
    ଅକ୍ଷର ca[10], *cp = ca-1;
    ଫେରନ୍ତୁ (ca != cp + 1) ? cp : ଖାଲି;
}

ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

ଶୂନ୍ୟ c99_vla_test_1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା size1, ପୂର୍ଣ୍ଣସଂଖ୍ୟା size2)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା size = size1 * size2;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tab1[size][2], tab2[10][2];
    ଶୂନ୍ୟ *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (ଆକାର tab1 == size1 * size2 * 2 * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) (tab1_ptr + (size1 * 2 + 1) * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ଯଦି (bad_ptr = bounds_checking_is_enabled()) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *t1 = &tab1[size1 * size2 - 1][3];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        ଅକ୍ଷର*c1 = 1 + ଆକାର(tab1) + (ଅକ୍ଷର*)tab1;
        ଅକ୍ଷର*c2 = 1 + ଆକାର(tab2) + (ଅକ୍ଷର*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *i1 = tab1[-1];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *x1 = tab1[size1 * size2 + 1];
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ଅନ୍ୟଥା {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

ଶୂନ୍ୟ c99_vla_test_2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ପୂର୍ଣ୍ଣସଂଖ୍ୟା h, ପୂର୍ଣ୍ଣସଂଖ୍ୟା w)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x, y, z;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*arr)[h][w] = malloc(ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା) * d*h*w);
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = 1;
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    ପାଇଁ (z=0; z<d; z++) {
        ପାଇଁ (y=0; y<h; y++) {
            ପାଇଁ (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    ପାଇଁ (z=0; z<d; z++) {
        ପାଇଁ (y=0; y<h; y++) {
            ପାଇଁ (x=0; x<w; x++) {
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
        ଆକାର (*arr), ଆକାର (*arr)[0], ଆକାର (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == ଆକାର (*arr + 1) - ଆକାର arr,
        0 == ଆକାର ଆକାର *arr - ଆକାର arr,
        starr[0][2][3] == arr[1][2][3]
        );
    ମୁକ୍ତ (arr);
}

ଶୂନ୍ୟ c99_vla_test_3a (ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ଶୂନ୍ୟ c99_vla_test_3b(ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ଶୂନ୍ୟ c99_vla_test_3c(ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ଶୂନ୍ୟ c99_vla_test_3d(ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

ଶୂନ୍ୟ c99_vla_test_3e(ପୂର୍ଣ୍ଣସଂଖ୍ୟା s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[][3][--s])
{
    printf ("%d %d %d\n", ଆକାର arr, s, arr[1][2][3]);
}

ଶୂନ୍ୟ c99_vla_test_3(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[2][3][4];

    memset (a, 0, ଆକାର(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

ଶୂନ୍ୟ c99_vla_test(ଶୂନ୍ୟ)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


ଶୂନ୍ୟ sizeof_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା **ptr;

    printf("sizeof(int) = %d\n", ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    printf("sizeof(unsigned int) = %d\n", ଆକାର(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    printf("sizeof(long) = %d\n", ଆକାର(long));
    printf("sizeof(unsigned long) = %d\n", ଆକାର(unsigned long));
    printf("sizeof(short) = %d\n", ଆକାର(short));
    printf("sizeof(unsigned short) = %d\n", ଆକାର(unsigned short));
    printf("sizeof(char) = %d\n", ଆକାର(ଅକ୍ଷର));
    printf("sizeof(unsigned char) = %d\n", ଆକାର(unsigned ଅକ୍ଷର));
    printf("sizeof(func) = %d\n", ଆକାର sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", ଆକାର a++);
    printf("a=%d\n", a);
    ptr = ଖାଲି;
    printf("sizeof(**ptr) = %d\n", ଆକାର (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", ଆକାର(ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -ଆକାର(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(ଅକ୍ଷର));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned ଅକ୍ଷର));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", ଆକାର(ଅକ୍ଷର[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   ଆକାର( (ସଂରଚନା {ପୂର୍ଣ୍ଣସଂଖ୍ୟା i; ପୂର୍ଣ୍ଣସଂଖ୍ୟା j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   ଆକାର (ସଂରଚନା {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", ଆକାର(t && 0));
    printf("sizeof(1 && 1) = %d\n", ଆକାର(1 && 1));
    printf("sizeof(t || 1) = %d\n", ଆକାର(t || 1));
    printf("sizeof(0 || 0) = %d\n", ଆକାର(0 || 0));

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[4], fn();
    printf("sizeof(0, arr) = %d\n", ଆକାର(0, arr));
    printf("sizeof(0, fn) = %d\n", ଆକାର(0, fn));
}

ଶୂନ୍ୟ typeof_test(ଶୂନ୍ୟ)
{
    ଦ୍ୱିଗୁଣ a;
    typeof(a) b;
    typeof(ଦଶମିକ) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


ସଂରଚନା hlist_ଗଣ୍ଠି;
ସଂରଚନା hlist_head {
    ସଂରଚନା hlist_ଗଣ୍ଠି *first, *last;
};

ଶୂନ୍ୟ consume_ulong (unsigned long i)
{
    i = 0;
}

ଶୂନ୍ୟ statement_ପଦସମଷ୍ଟି_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, i;

    /* Basic stmt expr test */
    a = 0;
    ପାଇଁ(i=0;i<10;i++) {
        a += 1 + 
            ( { ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, j; 
                b = 0; 
                ପାଇଁ(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    ଶୂନ୍ୟ *v = (ଶୂନ୍ୟ*)39;
    typeof(({
	    (ସଂରଚନା hlist_ଗଣ୍ଠି *)v;
	    })) x;
    typeof (x)
	ptr = (ସଂରଚନା hlist_ଗଣ୍ଠି *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            ସ୍ଥିର ଅଚଳ ଅକ୍ଷର *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = 40;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b = ({ ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = 41; t; });
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c = ({ ପୂର୍ଣ୍ଣସଂଖ୍ୟା t = 42; t; });

    /* Test that aggregate return values work.  */
    ସଂରଚନା hlist_head h
	= ({
	   ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା hlist_head T;
	   long pre = 48;
	   T t = { (ଶୂନ୍ୟ*)43, (ଶୂନ୍ୟ*)44 };
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
       LBL: ଯଦି (i++ == 0) ଯାଅ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      ଯାଅ LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

ଶୂନ୍ୟ local_label_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ଯାଅ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        ଯାଅ l1;
    l4:
        printf("aa1\n");
        ଯାଅ l3;
    l2:
        printf("aa3\n");
        ଯାଅ l4;
    l1:
        printf("aa2\n");
        ଯାଅ l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    ଫେରନ୍ତୁ;
 l4:
    printf("bb1\n");
    ଯାଅ l2;
 l1:
    printf("bb2\n");
    ଯାଅ l4;
}

/* inline assembler test */
#ଯଦି (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

ପ୍ରକାରବ୍ୟାଖ୍ୟା __SIZE_TYPE__ word;

/* from linux kernel */
ସ୍ଥିର ଅକ୍ଷର * strncat1(ଅକ୍ଷର * dest,ଅଚଳ ଅକ୍ଷର * src,size_t ଗଣନା_3)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ଗଣନା_3)
	: "memory");
ଫେରନ୍ତୁ dest;
}

ସ୍ଥିର ଅକ୍ଷର * strncat2(ଅକ୍ଷର * dest,ଅଚଳ ଅକ୍ଷର * src,size_t ଗଣନା_3)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ଗଣନା_3)
	: "memory");
ଫେରନ୍ତୁ dest;
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ * memcpy1(ଶୂନ୍ୟ * to, ଅଚଳ ଶୂନ୍ୟ * from, size_t n)
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
ଫେରନ୍ତୁ (to);
}

ସ୍ଥିର ଧାଡ଼ିଭିତରେ ଶୂନ୍ୟ * memcpy2(ଶୂନ୍ୟ * to, ଅଚଳ ଶୂନ୍ୟ * from, size_t n)
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
ଫେରନ୍ତୁ (to);
}

ସ୍ଥିର __inline__ ଶୂନ୍ୟ sigaddset1(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *set, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

ସ୍ଥିର __inline__ ଶୂନ୍ୟ sigdelset1(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *set, ପୂର୍ଣ୍ଣସଂଖ୍ୟା _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ସ୍ଥିର __inline__ __const__ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା swab32(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
        ଫେରନ୍ତୁ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ଅନ୍ୟଥା
ସ୍ଥିର __inline__ __const__ unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା swab32(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ଫେରନ୍ତୁ x;
}
#endif

ସ୍ଥିର __inline__ unsigned long long mul64(unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#ଅନ୍ୟଥା
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    ଫେରନ୍ତୁ res;
}

ସ୍ଥିର __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ଅନ୍ୟଥା
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    ଫେରନ୍ତୁ res;
}

ସଂରଚନା struct123 {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b;
};
ସଂରଚନା struct1231 {
    word addr;
};

word mconstraint_test(ସଂରଚନା struct1231 *r)
{
    word ret;
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[2];
    a[0] = 0;
    __asm__ ଅସ୍ଥିର ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ସଂରଚନା struct123 *)r->addr));
    ଫେରନ୍ତୁ ret + a[0];
}

#ifdef __x86_64__
ପୂର୍ଣ୍ଣସଂଖ୍ୟା fls64(unsigned long long x)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ଫେରନ୍ତୁ bitpos + 1;
}
#endif

ଶୂନ୍ୟ other_constraints_test(ଶୂନ୍ୟ)
{
    word ret;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା var;
#ଯଦି CC_NAME != CC_clang
    __asm__ ଅସ୍ଥିର ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
ଶୂନ୍ୟ base_func(ଶୂନ୍ୟ)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
ବାହ୍ୟ ଶୂନ୍ୟ override_func1 (ଶୂନ୍ୟ);
ବାହ୍ୟ ଶୂନ୍ୟ override_func2 (ଶୂନ୍ୟ);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

ଶୂନ୍ୟ override_func2 (ଶୂନ୍ୟ)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା bug_table[] __attribute__((section("__bug_table")));
ଅକ୍ଷର * get_asm_string (ଶୂନ୍ୟ)
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
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା some_ପ୍ରତୀକ;
  asm ଅସ୍ଥିର (".globl some_symbol\n"
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
  ଅକ୍ଷର * str = ((ଅକ୍ଷର*)bug_table) + bug_table[1];
  ଫେରନ୍ତୁ str;
#ଅନ୍ୟଥା
  ଫେରନ୍ତୁ (ଅକ୍ଷର *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
ବାହ୍ୟ unsigned ଅକ୍ଷର alld_stuff[];
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

ଶୂନ୍ୟ asm_local_label_diff (ଶୂନ୍ୟ)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
ଶୂନ୍ୟ asm_local_statics (ଶୂନ୍ୟ)
{
  ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

ସ୍ଥିର
unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା set;

ଶୂନ୍ୟ fancy_copy (unsigned *in, unsigned *out)
{
  asm ଅସ୍ଥିର ("" : "=r" (*out) : "0" (*in));
}

ଶୂନ୍ୟ fancy_copy2 (unsigned *in, unsigned *out)
{
  asm ଅସ୍ଥିର ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#ଯଦି defined __x86_64__
ଶୂନ୍ୟ clobber_r12(ଶୂନ୍ୟ)
{
    asm ଅସ୍ଥିର("mov $1, %%r12" ::: "r12");
}
#endif

ଶୂନ୍ୟ test_ଉପର_clobbers_really(ଶୂନ୍ୟ)
{
#ଯଦି defined __x86_64__
    ପଞ୍ଜିକରଣ word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm ଅସ୍ଥିର("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm ଅସ୍ଥିର("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

ଶୂନ୍ୟ test_ଉପର_clobbers(ଶୂନ୍ୟ)
{
#ଯଦି defined __x86_64__
    word x1, x2;
    asm ଅସ୍ଥିର("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ଉପର_clobbers_really();
    asm ଅସ୍ଥିର("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm ଅସ୍ଥିର("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

ସ୍ଥିର long cpu_ସଂଖ୍ୟା;
ଶୂନ୍ୟ trace_console(long len, long len2)
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
    ଯଦି (0
        &&
            ({
              long pscr_ret__;
              ବାଛ(len) {
                ସ୍ଥିତି 4:
                    {
                       long pfo_ret__;
                       ବାଛ (len2) {
                         ସ୍ଥିତି 8:	printf("bla"); pfo_ret__ = 42; ଭାଙ୍ଗ;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ଭାଙ୍ଗ;
                ସ୍ଥିତି 8:
                    {
                       long pfo_ret__;
                       ବାଛ (len2) {
                         ସ୍ଥିତି 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ସଂଖ୍ୟା));	ଭାଙ୍ଗ;
                         ସ୍ଥିତି 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ସଂଖ୍ୟା));	ଭାଙ୍ଗ;
                         ସ୍ଥିତି 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ସଂଖ୍ୟା));	ଭାଙ୍ଗ;
                         ସ୍ଥିତି 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ସଂଖ୍ୟା));	ଭାଙ୍ଗ;
                         ପୂର୍ବନିର୍ଦ୍ଧାରିତ: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ଭାଙ୍ଗ;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

ଶୂନ୍ୟ test_asm_dead_code(ଶୂନ୍ୟ)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm ଅସ୍ଥିର ("" : "=D" (rdi) : "0" (0));
  (ଶୂନ୍ୟ)ଆକାର (({
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm ଅସ୍ଥିର ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

ଶୂନ୍ୟ test_asm_call(ଶୂନ୍ୟ)
{
#ଯଦି defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ସ୍ଥିର ଅକ୍ଷର str[] = "PATH";
  ଅକ୍ଷର *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm ଅସ୍ଥିର ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ଯଦି 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ଅନ୍ୟଥା
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#ଯଦି defined __x86_64__
# define RX "(%rip)"
#ଅନ୍ୟଥା
# define RX
#endif

ଶୂନ୍ୟ asm_dot_test(ଶୂନ୍ୟ)
{
#ifndef __APPLE__
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
    ପାଇଁ (x = 1;; ++x) {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା r = x;
        ବାଛ (x) {
        ସ୍ଥିତି 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        ସ୍ଥିତି 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ଅନ୍ୟଥା
            asm(".text; mov $123, %eax; jmp p0");
#endif
	ସ୍ଥିତି 3:
#ଯଦି !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ଅନ୍ୟଥା
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        ସ୍ଥିତି 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ଅନ୍ୟଥା
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ଅନ୍ୟଥା
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        ସ୍ଥିତି 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ଭାଙ୍ଗ;
	}
        ଯଦି (r == x)
            ଭାଙ୍ଗ;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

ଶୂନ୍ୟ asm_pcrel_test(ଶୂନ୍ୟ)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

ଶୂନ୍ୟ asm_test(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର buf[128];
    unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା val, val2;
    ସଂରଚନା struct123 s1;
    ସଂରଚନା struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା base_func = 42;
    ଶୂନ୍ୟ override_func3 (ଶୂନ୍ୟ);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    ପଞ୍ଜିକରଣ ପୂର୍ଣ୍ଣସଂଖ୍ୟା regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm ଅସ୍ଥିର ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm ଅସ୍ଥିର ("xorl %eax, %eax");

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
    ଯାଅ label1;
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
    asm ଅସ୍ଥିର(".weak override_func3\n.set override_func3, base_func");
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
    asm ଅସ୍ଥିର("" : "=r" (asmret) : "0"(s2));
    ଯଦି (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm ଅସ୍ଥିର("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ଯଦି (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm ଅସ୍ଥିର ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_ଉପର_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ଫେରନ୍ତୁ;
 label1:
    ଯାଅ label2;
}

#ଅନ୍ୟଥା

ଶୂନ୍ୟ asm_test(ଶୂନ୍ୟ)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା constant_p_var;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା func(ଶୂନ୍ୟ);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ସ୍ଥିର ଶୂନ୍ୟ builtin_test_bits(unsigned long long x, ପୂର୍ଣ୍ଣସଂଖ୍ୟା cnt[])
{
#ଯଦି GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ଯଦି ((unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା) x) cnt[3] += __builtin_clz(x);
    ଯଦି ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    ଯଦି ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    ଯଦି ((unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା) x) cnt[6] += __builtin_ctz(x);
    ଯଦି ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    ଯଦି ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#ଯଦି GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

ଶୂନ୍ୟ builtin_test(ଶୂନ୍ୟ)
{
    short s;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    long long ll;
#ଯଦି GCC_MAJOR >= 3
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଅକ୍ଷର);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା[2], ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା[2]);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା[2][3], ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା[][3]);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[], ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2])0 : (ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2])0),
                ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3])0 :
                              (ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3])0),
                ଅଚଳ ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3])0 :
                              (ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3])0),
                ଅଚଳ ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*)[2][3]);
#ଅନ୍ୟଥା
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *, ଶୂନ୍ୟ *);
    COMPAT_TYPE(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *, ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା *);
    COMPAT_TYPE(ଅକ୍ଷର *, unsigned ଅକ୍ଷର *);
    COMPAT_TYPE(ଅକ୍ଷର *, signed ଅକ୍ଷର *);
    COMPAT_TYPE(ଅକ୍ଷର *, ଅକ୍ଷର *);
    COMPAT_TYPE(ଅକ୍ଷର **, ଶୂନ୍ୟ *);
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
#ଅନ୍ୟଥା
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
    i = ଆକାର (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = ଆକାର (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, ଆକାର(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        ପାଇଁ (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        ପାଇଁ (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	ପାଇଁ (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#ଯଦି defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
ଶୂନ୍ୟ weak_test(ଶୂନ୍ୟ) {}
#ଅନ୍ୟଥା
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_f1(ଶୂନ୍ୟ);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_f2(ଶୂନ୍ୟ);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା                       weak_f3(ଶୂନ୍ୟ);
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_v1;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_v2;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା                       weak_v3;

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା                           (*weak_fpa)() __attribute__((weak));
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak))     (*weak_fpb)();
ବାହ୍ୟ     __attribute__((weak)) ପୂର୍ଣ୍ଣସଂଖ୍ୟା (*weak_fpc)();

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା                     weak_asm_f1(ଶୂନ୍ୟ) asm("weak_asm_f1x") __attribute((weak));
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute((weak)) weak_asm_f2(ଶୂନ୍ୟ) asm("weak_asm_f2x")                    ;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute((weak)) weak_asm_f3(ଶୂନ୍ୟ) asm("weak_asm_f3x") __attribute((weak));
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute((weak)) weak_asm_v3(ଶୂନ୍ୟ) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
ସ୍ଥିର ଅଚଳ size_t dummy = 0;
ବାହ୍ୟ __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
ବାହ୍ୟ __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
ବାହ୍ୟ __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା some_lib_func(ଶୂନ୍ୟ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା dummy_impl_of_slf(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 444; }
#ifndef __clang__
ପୂର୍ଣ୍ଣସଂଖ୍ୟା some_lib_func(ଶୂନ୍ୟ) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

ପୂର୍ଣ୍ଣସଂଖ୍ୟା weak_toolate() __attribute__((weak));
ପୂର୍ଣ୍ଣସଂଖ୍ୟା weak_toolate() { ଫେରନ୍ତୁ 0; }

ଶୂନ୍ୟ __attribute__((weak)) weak_test(ଶୂନ୍ୟ)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != ଖାଲି);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != ଖାଲି);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != ଖାଲି);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != ଖାଲି);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != ଖାଲି);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != ଖାଲି);
#ifdef __clang__
	printf("some_lib_func=444\n");
#ଅନ୍ୟଥା
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_f2() { ଫେରନ୍ତୁ 222; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_f3() { ଫେରନ୍ତୁ 333; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_v2 = 222;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((weak)) weak_v3 = 333;
#endif

ଶୂନ୍ୟ const_func(ଅଚଳ ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
}

ଶୂନ୍ୟ const_warn_test(ଶୂନ୍ୟ)
{
    const_func(1);
}

ସଂରଚନା condstruct {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା getme (ସଂରଚନା condstruct *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i1 = (i == 0 ? 0 : s)->i;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i2 = (i == 0 ? s : 0)->i;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i3 = (i == 0 ? (ଶୂନ୍ୟ*)0 : s)->i;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i4 = (i == 0 ? s : (ଶୂନ୍ୟ*)0)->i;
  ଫେରନ୍ତୁ i1 + i2 + i3 + i4;
}

ସଂରଚନା global_data
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା a[40];
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା *b[40];
};

ସଂରଚନା global_data global_data;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା global_data_getstuff (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *, ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

ଶୂନ୍ୟ global_data_callit (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା global_data_getstuff (ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  ଫେରନ୍ତୁ *p + i;
}

ଶୂନ୍ୟ global_data_test (ଶୂନ୍ୟ)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

ସଂରଚନା cmpcmpS
{
  unsigned ଅକ୍ଷର fill : 3;
  unsigned ଅକ୍ଷର b1 : 1;
  unsigned ଅକ୍ଷର b2 : 1;
  unsigned ଅକ୍ଷର fill2 : 3;
};

ପୂର୍ଣ୍ଣସଂଖ୍ୟା glob1, glob2, glob3;

ଶୂନ୍ୟ compare_comparisons (ସଂରଚନା cmpcmpS *s)
{
  ଯଦି (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

ଶୂନ୍ୟ cmp_comparison_test(ଶୂନ୍ୟ)
{
  ସଂରଚନା cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା fcompare (ଦ୍ୱିଗୁଣ a, ଦ୍ୱିଗୁଣ b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା code)
{
  ବାଛ (code) {
    ସ୍ଥିତି 0: ଫେରନ୍ତୁ a == b;
    ସ୍ଥିତି 1: ଫେରନ୍ତୁ a != b;
    ସ୍ଥିତି 2: ଫେରନ୍ତୁ a < b;
    ସ୍ଥିତି 3: ଫେରନ୍ତୁ a >= b;
    ସ୍ଥିତି 4: ଫେରନ୍ତୁ a > b;
    ସ୍ଥିତି 5: ଫେରନ୍ତୁ a <= b;
  }
  ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ math_cmp_test(ଶୂନ୍ୟ)
{
  ଦ୍ୱିଗୁଣ nan = 0.0/0.0;
  ଦ୍ୱିଗୁଣ one = 1.0;
  ଦ୍ୱିଗୁଣ two = 2.0;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା comp = 0;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  ଯଦି (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  ଯଦି (a op b) \
    bug (a,b,op,iop,2); \
  ଯଦି (a iop b) \
    ; \
  ଅନ୍ୟଥା \
    bug (a,b,op,iop,3); \
  ଯଦି ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ଯଦି ((a iop b) || comp) \
    ; \
  ଅନ୍ୟଥା \
    bug (a,b,op,iop,5); \
  ଯଦି (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ଯଦି (!fcompare (nan, nan, 1))
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

ଦ୍ୱିଗୁଣ get100 () { ଫେରନ୍ତୁ 100.0; }

ଶୂନ୍ୟ callsave_test(ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, s; ଦ୍ୱିଗୁଣ *d; ଦ୍ୱିଗୁଣ t;
  s = ଆକାର (ଦ୍ୱିଗୁଣ);
  printf ("callsavetest: %d\n", s);
  d = alloca (ଆକାର(ଦ୍ୱିଗୁଣ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


ଶୂନ୍ୟ bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (ଅକ୍ଷର *)__builtin_frame_address(3) + str_offset);
}
ଶୂନ୍ୟ bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (ଅକ୍ଷର *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
ଶୂନ୍ୟ bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (ଅକ୍ଷର *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

ଶୂନ୍ୟ builtin_frame_address_test(ଶୂନ୍ୟ)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    ଅକ୍ଷର str[] = "__builtin_frame_address";
    ଅକ୍ଷର *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

ଅକ୍ଷର via_volatile (ଅକ୍ଷର i)
{
  ଅକ୍ଷର ଅସ୍ଥିର vi;
  vi = i;
  ଫେରନ୍ତୁ vi;
}

ଶୂନ୍ୟ volatile_test(ଶୂନ୍ୟ)
{
    ଯଦି (via_volatile (42) != 42)
      printf (" broken\n");
    ଅନ୍ୟଥା
      printf (" ok\n");
}

ସଂରଚନା __attribute__((__packed__)) Spacked {
    ଅକ୍ଷର a;
    short b;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
};
ସଂରଚନା Spacked spacked;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __attribute__((__packed__)) {
    ଅକ୍ଷର a;
    short b;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
} Spacked2;
Spacked2 spacked2;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା Spacked3_s {
    ଅକ୍ଷର a;
    short b;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ସଂରଚନା gate_struct64 {
    unsigned short offset_ତଳ;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_ମଧ୍ୟ;
    unsigned offset_ଉପର;
    unsigned zero1;
} __attribute__((packed));
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା gate_struct64 gate_desc;
gate_desc a_gate_desc;
ଶୂନ୍ୟ attrib_test(ଶୂନ୍ୟ)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", ଆକାର(ସଂରଚନା Spacked),
	 ଆକାର(spacked), ଆକାର(Spacked2), ଆକାର(spacked2));
  printf("attr: %d %d\n", ଆକାର(Spacked3), ଆକାର(spacked3));
  printf("attr: %d %d\n", ଆକାର(gate_desc), ଆକାର(a_gate_desc));
#endif
}
ବାହ୍ୟ __attribute__((__unused__)) ଅକ୍ଷର * __attribute__((__unused__)) *
strange_attrib_placement (ଶୂନ୍ୟ);

ଶୂନ୍ୟ * __attribute__((__unused__)) get_void_ptr (ଶୂନ୍ୟ *a)
{
  ଫେରନ୍ତୁ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ସ୍ଥିର ଧାଡ଼ିଭିତରେ
ପୂର୍ଣ୍ଣସଂଖ୍ୟା __get_order(unsigned long long size)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ସଂରଚନା S { ପୂର୍ଣ୍ଣସଂଖ୍ୟା i : 1; } s; // constructed for this '1'
    }
  order = size;
  ଫେରନ୍ତୁ order;
}

/* This just forces the above inline function to be actually emitted.  */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା force_get_order(unsigned long s)
{
    ଫେରନ୍ତୁ __get_order(s);
}

#define pv(m) printf(ଆକାର (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
ଶୂନ୍ୟ bounds_check1_test (ଶୂନ୍ୟ)
{
    ସଂରଚନା s {
        ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
ଶୂନ୍ୟ map_add(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ପୂର୍ଣ୍ଣସଂଖ୍ୟା e, ପୂର୍ଣ୍ଣସଂଖ୍ୟା f, ପୂର୍ଣ୍ଣସଂଖ୍ୟା g, ପୂର୍ଣ୍ଣସଂଖ୍ୟା h, ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

ଶୂନ୍ୟ func_arg_test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 0;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b = 1;
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
ଶୂନ୍ୟ whitespace_test(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର *str;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_test = 1;

#ଯଦି 1
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
#ଅନ୍ୟଥା
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#ଯଦି 0
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
#ଯଦି 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(ପଦସମଷ୍ଟି_test);
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
    RUN(ପଦସମଷ୍ଟି_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_ପଦସମଷ୍ଟି_test);
    RUN(ପଦସମଷ୍ଟି_cmp_test);
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
    RUN(statement_ପଦସମଷ୍ଟି_test);
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

    ଫେରନ୍ତୁ 0;
}
