/*
 * TCC auto test program
 */
#অন্তর্ভাৱ "config.h"

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

#যদি defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#অন্যথা
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#যদি defined(_WIN32)
#define LONG_DOUBLE দ্ৱিগুণ
#define LONG_DOUBLE_LITERAL(x) x
#অন্যথা
#define LONG_DOUBLE long দ্ৱিগুণ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

প্রকারনির্দেশ __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#অন্তর্ভাৱ TCCLIB_INC

#অন্তর্ভাৱ TCCLIB_INC1.TCCLIB_INC2

#অন্তর্ভাৱ TCCLIB_INC1.h>

#অন্তর্ভাৱ TCCLIB_INC3

#অন্তর্ভাৱ <tcclib.h>

#অন্তর্ভাৱ "tcclib.h"

#অন্তর্ভাৱ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#অন্যথা
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#অন্তর্ভাৱ INC(42test)
#অন্তর্ভাৱ incname
#অন্তর্ভাৱ stringify(funnyname)

পূর্ণাঙ্ক fib(পূর্ণাঙ্ক n);
শূন্য অঙ্ক(পূর্ণাঙ্ক n);
শূন্য forward_ref(শূন্য);
পূর্ণাঙ্ক isid(পূর্ণাঙ্ক c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
শূন্য funny_সাৰি_continuation (পূর্ণাঙ্ক, ..\
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
#define নিচেৰ_2 নিচেৰ_2 ", world"

স্থির পূর্ণাঙ্ক onetwothree = 123;
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

#যদি 1
#define B3 1
#নোচেদ্যদি 1
#define B3 2
#নোচেদ্যদি 0
#define B3 3
#অন্যথা
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

পূর্ণাঙ্ক qq(পূর্ণাঙ্ক x)
{
    ঘূৰাই x + 40;
}
#define qq(x) x

#define spin_lock(lock) কৰা { } যেতিয়ালৈ (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

শূন্য macro_test(শূন্য)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(উপৰেৰ_2, নিচেৰ_2));
    printf("s2=%s\n", xglue(উপৰেৰ_2, নিচেৰ_2));
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
#অন্যথা
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#অন্যথা
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#অন্যথা
    printf("B1 not defined\n");
#endif
#অন্যথা
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#অন্যথা
    printf("B2 not defined\n");
#endif
#endif

#যদি 1+1
    printf("test true1\n");
#endif
#যদি 0
    printf("test true2\n");
#endif
#যদি 1-1
    printf("test true3\n");
#endif
#যদি defined(A)
    printf("test trueA\n");
#endif
#যদি defined(B)
    printf("test trueB\n");
#endif

#যদি 0
    printf("test 0\n");
#নোচেদ্যদি 0
    printf("test 1\n");
#নোচেদ্যদি 2
    printf("test 2\n");
#অন্যথা
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
        পূর্ণাঙ্ক a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(বাৰ্তা) printf("%s\n",বাৰ্তা)

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
#যদি !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ধ্রুৱ ৱর্ণ *fn = get_file_from_header();
      যদি (fn[0] == '.' && fn[1] == '/')
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


স্থির শূন্য print_অঙ্ক(ৱর্ণ *fn, পূর্ণাঙ্ক সাৰি, পূর্ণাঙ্ক অঙ্ক) {
    printf("fn %s, line %d, num %d\n", fn, সাৰি, অঙ্ক);
}

শূন্য recursive_macro_test(শূন্য)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_অঙ্ক(x) print_অঙ্ক(__FILE__,__LINE__,x)
    print_অঙ্ক(123);
    WRAP(print_অঙ্ক(123));
    WRAP(WRAP(print_অঙ্ক(123)));

স্থির সংরচনা recursive_macro { পূর্ণাঙ্ক rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#যদি __TINYC__
পূর্ণাঙ্ক op(a, b)
{
    ঘূৰাই a / b;
}

পূর্ণাঙ্ক ret(a)
{
    যদি (a == 2)
        ঘূৰাই 1;
    যদি (a == 3)
        ঘূৰাই 2;
    ঘূৰাই 0;
}
#endif

#যদি !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
ৱর্ণ str_ag1[] = "b";
ৱর্ণ str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
ৱর্ণ str_ag3[] = { "ab"[1], 0 };
ৱর্ণ str_x[2] = { "xy" "z"[2], 0 };
#endif
ৱর্ণ *str_ar[] = { "one", "two" };
সংরচনা str_SS {unsigned ৱর্ণ a[3], b; };
সংরচনা str_SS str_sinit15 = { "r" };
সংরচনা str_SS str_sinit16[] = { { "q" }, 2 };

স্থির শূন্য string_test2()
{
    ৱর্ণ *p = "hello";
    ৱর্ণ a3[2] = { "p" };
    ৱর্ণ a4[2] = { "ab" "c"[2], 0 };
    ৱর্ণ *pa1 = "def" + 1;
    ৱর্ণ *pa2 = { "xyz" + 1 };
    পূর্ণাঙ্ক i = 0;
    সংরচনা str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    ৱর্ণ str_ag3[] = { "ab"[1], 0 };
    ৱর্ণ str_x[2] = { "xy" "z"[2], 0 };
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

শূন্য ps(ধ্রুৱ ৱর্ণ *s)
{
    পূর্ণাঙ্ক c;
    যেতিয়ালৈ (1) {
        c = *s;
        যদি (c == 0)
            ভঙ্গ;
        printf("%c", c);
        s++;
    }
}

ধ্রুৱ ৱর্ণ foo1_string[] = "\
bar\n\
test\14\
1";

শূন্য string_test()
{
    unsigned পূর্ণাঙ্ক b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#যদি 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    যেতিয়ালৈ ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    যেতিয়ালৈ (b != 0x80000000) {
        অঙ্ক(b);
        b = b * 2;
    }
    string_test2();
}


শূন্য if1t(পূর্ণাঙ্ক n, পূর্ণাঙ্ক a, পূর্ণাঙ্ক b, পূর্ণাঙ্ক c)
{
    যদি (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    যদি (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    যদি (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    যদি (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    যদি (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    যদি (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    যদি (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    যদি (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    যদি (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    যদি (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    যদি (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    যদি (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    যদি (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    যদি (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

শূন্য if2t(শূন্য)
{
    যদি (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

শূন্য if3t(শূন্য)
{
    চঞ্চল long long i = 1;
    যদি (i <= 18446744073709551615ULL)
      ;
    অন্যথা
      printf ("if3t:wrong 1\n");
}

শূন্য if_test(শূন্য)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

শূন্য loop_test()
{
    পূর্ণাঙ্ক i;
    i = 0;
    যেতিয়ালৈ (i < 10)
        printf("%d", i++);
    printf("\n");
    বাবে(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    কৰা {
        printf("%d", i++);
    } যেতিয়ালৈ (i < 10);
    printf("\n");

    ৱর্ণ গুনতি_2 = 123;
    /* c99 for loop init test */
    বাবে (size_t গুনতি_2 = 1; গুনতি_2 < 3; গুনতি_2++)
        printf("count=%d\n", গুনতি_2);
    printf("count = %d\n", গুনতি_2);

    /* break/continue tests */
    i = 0;
    যেতিয়ালৈ (1) {
        যদি (i == 6)
            ভঙ্গ;
        i++;
        যদি (i == 3)
            অনুৱর্ত;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    কৰা {
        যদি (i == 6)
            ভঙ্গ;
        i++;
        যদি (i == 3)
            অনুৱর্ত;
        printf("%d", i);
    } যেতিয়ালৈ(1);
    printf("\n");

    বাবে(i = 0;i < 10;i++) {
        যদি (i == 3)
            অনুৱর্ত;
        printf("%d", i);
    }
    printf("\n");
}

প্রকারনির্দেশ পূর্ণাঙ্ক typedef_and_label;

শূন্য goto_test()
{
    পূর্ণাঙ্ক i;
    স্থির শূন্য *label_table[3] = { &&label1, &&label2, &&label3 };
    সংরচনা {
        পূর্ণাঙ্ক bla;
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
    যদি (i >= 10) 
        গচ্ছ s_end;
    printf("%d", i);
    i++;
    গচ্ছ s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    বাবে(i=0;i<3;i++) {
        গচ্ছ *label_table[i];
    label1:
        printf("label1\n");
        গচ্ছ next;
    label2:
        printf("label2\n");
        গচ্ছ next;
    label3:
        printf("label3\n");
    next: ;
    }
}

গণনা {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

গণনা test {
    E5 = 1000,
};

সংরচনা S_enum {
    গণনা {E6 = 42, E7, E8} e:8;
};

গণনা ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

গণনা { BIASU = -1U<<31 };
গণনা { BIASS = -1 << 31 };

স্থির পূর্ণাঙ্ক getint(পূর্ণাঙ্ক i)
{
  যদি (i)
    ঘূৰাই 0;
  অন্যথা
    ঘূৰাই (পূর্ণাঙ্ক)(-1U << 31);
}

শূন্য enum_test()
{
    গণনা test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    সংরচনা S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    যদি (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    অন্যথা
      printf("enum unsigned: wrong\n");
    যদি (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    অন্যথা
      printf("enum unsigned: wrong\n");
}

প্রকারনির্দেশ পূর্ণাঙ্ক *my_ptr;

প্রকারনির্দেশ পূর্ণাঙ্ক mytype1;
প্রকারনির্দেশ পূর্ণাঙ্ক mytype2;

শূন্য typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    পূর্ণাঙ্ক b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

শূন্য forward_test()
{
    forward_ref();
    forward_ref();
}


শূন্য forward_ref(শূন্য)
{
    printf("forward ok\n");
}

প্রকারনির্দেশ সংরচনা struct1 {
    পূর্ণাঙ্ক f1;
    পূর্ণাঙ্ক f2, f3;
    সঙ্ঘ union1 {
        পূর্ণাঙ্ক v1;
        পূর্ণাঙ্ক v2;
    } u;
    ৱর্ণ str[3];
} struct1;

সংরচনা struct2 {
    পূর্ণাঙ্ক a;
    ৱর্ণ b;
};

সঙ্ঘ union2 {
    পূর্ণাঙ্ক w1;
    পূর্ণাঙ্ক w2;
};

সংরচনা struct1 st1, st2;

সংরচনা empty_mem {
    /* nothing */ ;
    পূর্ণাঙ্ক x;
};

পূর্ণাঙ্ক tab[3];
পূর্ণাঙ্ক tab2[3][2];

পূর্ণাঙ্ক g;

শূন্য f1(পূর্ণাঙ্ক g)
{
    printf("g1=%d\n", g);
}

শূন্য scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        পূর্ণাঙ্ক g;
        g = 3;
        printf("g3=%d\n", g);
        {
            পূর্ণাঙ্ক g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

পূর্ণাঙ্ক st2_i;
পূর্ণাঙ্ক *st2_p = &st2_i;
শূন্য scope2_test()
{
    ৱর্ণ a[50];
    st2_i = 42;
    বাবে (পূর্ণাঙ্ক st2_i = 1; st2_i < 10; st2_i++) {
        বাহ্য পূর্ণাঙ্ক st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
বাহ্য পূর্ণাঙ্ক st_global1;
পূর্ণাঙ্ক st_global1=42;
বাহ্য পূর্ণাঙ্ক st_global1;
পূর্ণাঙ্ক st_global1;
বাহ্য পূর্ণাঙ্ক st_global2;
পূর্ণাঙ্ক st_global2;
বাহ্য পূর্ণাঙ্ক st_global2;
পূর্ণাঙ্ক st_global2;

শূন্য array_test()
{
    পূর্ণাঙ্ক i, j, a[4];

    printf("sizeof(a) = %d\n", পরিমাণ(a));
    printf("sizeof(\"a\") = %d\n", পরিমাণ("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", পরিমাণ(__func__));
#endif
    printf("sizeof tab %d\n", পরিমাণ(tab));
    printf("sizeof tab2 %d\n", পরিমাণ tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    বাবে(i=0;i<3;i++)
        বাবে(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    বাবে(i=0;i<3*2;i++) {
        printf(" %3d", ((পূর্ণাঙ্ক *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", পরিমাণ(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", পরিমাণ(ptrdiff_t));
}

শূন্য ৰাশিমালা_test()
{
    পূর্ণাঙ্ক a, b;
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

পূর্ণাঙ্ক isid(পূর্ণাঙ্ক c)
{
    ঘূৰাই (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

পূর্ণাঙ্ক vstack[10], *vstack_ptr;

শূন্য vpush(পূর্ণাঙ্ক vt, পূর্ণাঙ্ক vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

শূন্য vpop(পূর্ণাঙ্ক *ft, পূর্ণাঙ্ক *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

শূন্য expr2_test()
{
    পূর্ণাঙ্ক a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

পূর্ণাঙ্ক const_len_ar[পরিমাণ(1/0)]; /* div-by-zero, but in unevaluated context */

শূন্য constant_ৰাশিমালা_test()
{
    পূর্ণাঙ্ক a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", পরিমাণ(const_len_ar));
}

পূর্ণাঙ্ক tab4[10];

শূন্য ৰাশিমালা_ptr_test()
{
    পূর্ণাঙ্ক arr[10], *p, *q;
    পূর্ণাঙ্ক i = -1;

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
    p = (পূর্ণাঙ্ক *)((ৱর্ণ *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        সংরচনা size12 {
            পূর্ণাঙ্ক i, j, k;
        };
        সংরচনা size12 s[2], *sp = s;
        পূর্ণাঙ্ক i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (পূর্ণাঙ্ক*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (পূর্ণাঙ্ক)((p - q) / 3));
}

শূন্য ৰাশিমালা_cmp_test()
{
    পূর্ণাঙ্ক a, b;
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

সংরচনা empty {
};

সংরচনা aligntest1 {
    ৱর্ণ a[10];
};

সংরচনা aligntest2 {
    পূর্ণাঙ্ক a;
    ৱর্ণ b[10];
};

সংরচনা aligntest3 {
    দ্ৱিগুণ a, b;
};

সংরচনা aligntest4 {
    দ্ৱিগুণ a[0];
};

সংরচনা __attribute__((aligned(16))) aligntest5
{
    পূর্ণাঙ্ক i;
};
সংরচনা aligntest6
{
    পূর্ণাঙ্ক i;
} __attribute__((aligned(16)));
সংরচনা aligntest7
{
    পূর্ণাঙ্ক i;
};
সংরচনা aligntest5 altest5[2];
সংরচনা aligntest6 altest6[2];
পূর্ণাঙ্ক pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
সংরচনা aligntest7 altest7[2] __attribute__((aligned(16)));

সংরচনা aligntest8
{
  পূর্ণাঙ্ক i;
} __attribute__((aligned(4096)));

সংরচনা Large {
    unsigned long flags;
    সঙ্ঘ {
	শূন্য *u1;
	পূর্ণাঙ্ক *u2;
    };

    সংরচনা {
	সঙ্ঘ {
	    unsigned long index;
	    শূন্য *freelist;
	};
	সঙ্ঘ {
	    unsigned long counters;
	    সংরচনা {
		পূর্ণাঙ্ক bla;
	    };
	};
    };

    সঙ্ঘ {
	সংরচনা {
	    long u3;
	    long u4;
	};
	শূন্য *u5;
	সংরচনা {
	    unsigned long compound_head;
	    unsigned পূর্ণাঙ্ক compound_dtor;
	    unsigned পূর্ণাঙ্ক compound_order;
	};
    };
} __attribute__((aligned(2 * পরিমাণ(long))));

প্রকারনির্দেশ unsigned long long __attribute__((aligned(4))) unaligned_u64;

সংরচনা aligntest9 {
    unsigned পূর্ণাঙ্ক buf_nr;
    unaligned_u64 start_lba;
};

সংরচনা aligntest10 {
    unsigned পূর্ণাঙ্ক buf_nr;
    unsigned long long start_lba;
};

শূন্য struct_test()
{
    struct1 *s;
    সঙ্ঘ union2 u;
    সংরচনা Large ls;

    printf("sizes: %d %d %d %d\n",
           পরিমাণ(সংরচনা struct1),
           পরিমাণ(সংরচনা struct2),
           পরিমাণ(সঙ্ঘ union1),
           পরিমাণ(সঙ্ঘ union2));
    printf("offsets: %d\n", (পূর্ণাঙ্ক)((ৱর্ণ*)&st1.u.v1 - (ৱর্ণ*)&st1));
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
    printf("str_addr=%x\n", (পূর্ণাঙ্ক)(uintptr_t)st1.str - (পূর্ণাঙ্ক)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest1), __alignof__(সংরচনা aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest2), __alignof__(সংরচনা aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest3), __alignof__(সংরচনা aligntest3));
#যদি !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest4), __alignof__(সংরচনা aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest5), __alignof__(সংরচনা aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest6), __alignof__(সংরচনা aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest7), __alignof__(সংরচনা aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest8), __alignof__(সংরচনা aligntest8));
#যদি !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest9), __alignof__(সংরচনা aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           পরিমাণ(সংরচনা aligntest10), __alignof__(সংরচনা aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           পরিমাণ(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           পরিমাণ(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           পরিমাণ(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#যদি !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", পরিমাণ(সংরচনা empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(সংরচনা empty));

    printf("Large: sizeof=%d\n", পরিমাণ(ls));
    memset(&ls, 0, পরিমাণ(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (পূর্ণাঙ্ক)((ৱর্ণ*)&ls.compound_head - (ৱর্ণ*)&ls));
}

/* simulate char/short return value with undefined upper bits */
স্থির পূর্ণাঙ্ক __csf(পূর্ণাঙ্ক x) { ঘূৰাই x; }
স্থির শূন্য *_csf = __csf;
#define csf(t,n) ((t(*)(পূর্ণাঙ্ক))_csf)(n)

/* XXX: depend on endianness */
শূন্য char_short_test()
{
    পূর্ণাঙ্ক var1, var2;
    signed ৱর্ণ var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed ৱর্ণ *)&var1, *(signed ৱর্ণ *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned ৱর্ণ *)&var1, *(unsigned ৱর্ণ *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(পূর্ণাঙ্ক *)&var1, *(পূর্ণাঙ্ক *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned পূর্ণাঙ্ক *)&var1, *(unsigned পূর্ণাঙ্ক *)&var2);
    *(signed ৱর্ণ *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(পূর্ণাঙ্ক *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed ৱর্ণ)(var1 + 1), (signed ৱর্ণ)(var4 + 1));
#যদি !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned ৱর্ণ,0x89898989);
    var4 = csf(signed ৱর্ণ,0xabababab);
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
    var1 = (signed ৱর্ণ)(unsigned ৱর্ণ)(var3 + 1);
    var4 = (signed ৱর্ণ)(unsigned ৱর্ণ)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(পূর্ণাঙ্ক)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed ৱর্ণ)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

প্রকারনির্দেশ সংরচনা Sym {
    পূর্ণাঙ্ক v;
    পূর্ণাঙ্ক t;
    পূর্ণাঙ্ক c;
    সংরচনা Sym *next;
    সংরচনা Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

স্থির পূর্ণাঙ্ক toupper1(পূর্ণাঙ্ক a)
{
    ঘূৰাই TOUPPER(a);
}

স্থির unsigned পূর্ণাঙ্ক calc_vm_flags(unsigned পূর্ণাঙ্ক prot)
{
  unsigned পূর্ণাঙ্ক prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ঘূৰাই prot_bits;
}

গণনা cast_enum { FIRST, LAST };

স্থির শূন্য tst_cast(গণনা cast_enum ce)
{
    printf("%d\n", ce);
}

শূন্য bool_test()
{
    পূর্ণাঙ্ক *s, a, b, t, f, i;

    a = 0;
    s = (শূন্য*)0;
    printf("!s=%d\n", !s);

    যদি (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#যদি 1 && 1
    printf("a1\n");
#endif
#যদি 1 || 0
    printf("a2\n");
#endif
#যদি 1 ? 0 : 1
    printf("a3\n");
#endif
#যদি 0 ? 0 : 1
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
    printf("type of bool: %d\n", (পূর্ণাঙ্ক) ( (~ ((unsigned পূর্ণাঙ্ক) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned পূর্ণাঙ্ক)0)) / 2 );
    /* test ? : cast */
    {
        পূর্ণাঙ্ক aspect_on;
        পূর্ণাঙ্ক aspect_native = 65536;
        দ্ৱিগুণ bfu_aspect = 1.0;
        পূর্ণাঙ্ক aspect;
        বাবে(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        স্থির পূর্ণাঙ্ক v1 = 34 ? : -1; /* constant case */
        স্থির পূর্ণাঙ্ক v2 = 0 ? : -1; /* constant case */
        পূর্ণাঙ্ক a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    বাবে(i=0;i<256;i++) {
        যদি (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

বাহ্য পূর্ণাঙ্ক undefined_function(শূন্য);
বাহ্য পূর্ণাঙ্ক defined_function(শূন্য);

#ifdef __clang__
পূর্ণাঙ্ক undefined_function(শূন্য) {}
#endif

স্থির অন্তঃস্থ শূন্য refer_to_undefined(শূন্য)
{
  undefined_function();
}

শূন্য optimize_out_test(শূন্য)
{
  পূর্ণাঙ্ক i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  পূর্ণাঙ্ক j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  যদি (0)
    printf("oo:%d\n", undefined_function());
  অন্যথা
    printf("oo:%d\n", defined_function());
  যদি (1)
    printf("oo:%d\n", defined_function());
  অন্যথা
    printf("oo:%d\n", undefined_function());
  যেতিয়ালৈ (1) {
      printf("oow:%d\n", defined_function());
      ভঙ্গ;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ৱিকল্প (j)
    পক্ষ 1: ভঙ্গ;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  যেতিয়ালৈ (1)
    ভঙ্গ;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  কৰা
    ভঙ্গ;
  যেতিয়ালৈ (1);
  printf ("ool2:%d\n", defined_function());
  বাবে (;;)
    ভঙ্গ;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  যেতিয়ালৈ (1) {
	{
	  ভঙ্গ;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  যেতিয়ালৈ (j) {
      যদি (j == 0)
	ভঙ্গ; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  যেতিয়ালৈ (j) {
      যদি (1)
	j--;
      অন্যথা
	breakhere: ভঙ্গ;
      printf("ool6:%d\n", defined_function());
      গচ্ছ breakhere;
  }
  j = 1;
  যেতিয়ালৈ (j) {
      j--;
      অনুৱর্ত;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  যদি (0 && undefined_function())
    undefined_function();
  যদি (defined_function() && 0)
    undefined_function();
  যদি (0 && 0)
    undefined_function();
  যদি (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  যদি (1 || undefined_function())
    ;
  অন্যথা
    undefined_function();
  যদি (defined_function() || 1)
    ;
  অন্যথা
    undefined_function();
  যদি (1 || 1)
    ;
  অন্যথা
    undefined_function();
  যদি (defined_function() || 1 || undefined_function())
    ;
  অন্যথা
    undefined_function();

  যদি (defined_function() && 0)
    refer_to_undefined();

  যদি (0) {
      (শূন্য)পরিমাণ( ({
		     কৰা { } যেতিয়ালৈ (0);
		     0;
		     }) );
      undefined_function();
  }

  যদি (0) {
      ৱিকল্প (defined_function()) {
          পক্ষ 0: undefined_function(); ভঙ্গ;
          স্ৱভাৱ: undefined_function(); ভঙ্গ;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  যদি (1)
    ঘূৰাই;
  printf ("oor:%d\n", undefined_function());
}

পূর্ণাঙ্ক defined_function(শূন্য)
{
  স্থির পূর্ণাঙ্ক i = 40;
  ঘূৰাই i++;
}

/* GCC accepts that */
স্থির পূর্ণাঙ্ক tab_reinit[];
স্থির পূর্ণাঙ্ক tab_reinit[10];

স্থির পূর্ণাঙ্ক tentative_ar[];
স্থির পূর্ণাঙ্ক tentative_ar[] = {1,2,3};

পূর্ণাঙ্ক cinit1; /* a global variable can be defined several times without error ! */
পূর্ণাঙ্ক cinit1; 
পূর্ণাঙ্ক cinit1 = 0;
পূর্ণাঙ্ক *cinit2 = (পূর্ণাঙ্ক []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
ৱর্ণ ধ্রুৱ * ধ্রুৱ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
শূন্য *cinit52 = &(শূন্য*){ (শূন্য*) 52 };

#যদি __TINYC__ || __GNUC__ >= 6
পূর্ণাঙ্ক cinit4 = (পূর্ণাঙ্ক){44};
শূন্য *cinit51 = (শূন্য*){ (শূন্য*) 51 };
সংরচনা _c6 { পূর্ণাঙ্ক a,b; } cinit6 = (সংরচনা _c6){61,62}, *cinit7 = &(সংরচনা _c6){71,72};
#অন্যথা
পূর্ণাঙ্ক cinit4 = 44;
শূন্য *cinit51 = (শূন্য*)51;
সংরচনা _c6 { পূর্ণাঙ্ক a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

শূন্য compound_literal_test(শূন্য)
{
    পূর্ণাঙ্ক *p, i;
    ৱর্ণ *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (পূর্ণাঙ্ক)cinit51);
    printf("cinit52 : %d\n", *(পূর্ণাঙ্ক*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (পূর্ণাঙ্ক []){1, 2, 3};
    বাবে(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    বাবে(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (ৱর্ণ *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (ৱর্ণ *){ q };
    printf("q3=%s\n", q3);

    q = (ৱর্ণ []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (পূর্ণাঙ্ক []){1, 2, cinit1 + 3};
    বাবে(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    বাবে(i=0;i<3;i++) {
        p = (পূর্ণাঙ্ক []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#যদি __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ঘূৰাই a + b;
}

পূর্ণাঙ্ক kr_func2(a, b)
{
    ঘূৰাই a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    ঘূৰাই 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
ৱর্ণ invalid_function_def()[] {ঘূৰাই 0;}

#অন্যথা
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

শূন্য অঙ্ক(পূর্ণাঙ্ক n)
{
    ৱর্ণ *tab, *p;
    tab = (ৱর্ণ*)malloc(20); 
    p = tab;
    যেতিয়ালৈ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        যদি (n == 0)
            ভঙ্গ;
    }
    যেতিয়ালৈ (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    মুক্ত(tab);
}

/* structure assignment tests */
সংরচনা structa1 {
    পূর্ণাঙ্ক f1;
    ৱর্ণ f2;
};

শূন্য struct_assign_test1(সংরচনা structa1 s1, পূর্ণাঙ্ক t, ভিন্ন f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

সংরচনা structa1 struct_assign_test2(সংরচনা structa1 s1, পূর্ণাঙ্ক t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ঘূৰাই s1;
}

শূন্য struct_assign_test(শূন্য)
{
    সংরচনা S {
      সংরচনা structa1 lsta1, lsta2;
      পূর্ণাঙ্ক i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    স্থির সংরচনা {
        শূন্য (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

শূন্য cast1(ৱর্ণ a, short b, unsigned ৱর্ণ c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

ৱর্ণ bcast;
short scast;

শূন্য cast_test()
{
    পূর্ণাঙ্ক a;
    ৱর্ণ c;
    ৱর্ণ tab[10];
    unsigned b,d;
    short s;
    ৱর্ণ *p = রিক্ত;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (ৱর্ণ)(a + 1),
           (short)(a + 1),
           (unsigned ৱর্ণ)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (ৱর্ণ)0xfffff,
           (short)0xfffff,
           (unsigned ৱর্ণ)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", পরিমাণ(c), পরিমাণ((পূর্ণাঙ্ক)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (ৱর্ণ)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", পরিমাণ(+(ৱর্ণ)'a'));
    printf("sizeof(-(char)'a') = %d\n", পরিমাণ(-(ৱর্ণ)'a'));
    printf("sizeof(~(char)'a') = %d\n", পরিমাণ(-(ৱর্ণ)'a'));

#যদি CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (পূর্ণাঙ্ক)p, (unsigned পূর্ণাঙ্ক)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (শূন্য *)a, (শূন্য *)b, (শূন্য *)c, (শূন্য *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(পূর্ণাঙ্ক)ul);
}

/* initializers tests */
সংরচনা structinit1 {
    পূর্ণাঙ্ক f1;
    ৱর্ণ f2;
    short f3;
    পূর্ণাঙ্ক farray[3];
};

পূর্ণাঙ্ক sinit1 = 2;
পূর্ণাঙ্ক sinit2 = { 3 };
পূর্ণাঙ্ক sinit3[3] = { 1, 2, {3}, };
পূর্ণাঙ্ক sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
পূর্ণাঙ্ক sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
পূর্ণাঙ্ক sinit6[] = { 1, 2, 3 };
পূর্ণাঙ্ক sinit7[] = { [2] = 3, [0] = 1, 2 };
ৱর্ণ sinit8[] = "hello" "trala";

সংরচনা structinit1 sinit9 = { 1, 2, 3 };
সংরচনা structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
সংরচনা structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

ৱর্ণ *sinit12 = "hello world";
ৱর্ণ *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
ৱর্ণ sinit14[10] = { "abc" };
পূর্ণাঙ্ক sinit15[3] = { পরিমাণ(sinit15), 1, 2 };

সংরচনা { পূর্ণাঙ্ক a[3], b; } sinit16[] = { { 1 }, 2 };

সংরচনা bar {
        ৱর্ণ *s;
        পূর্ণাঙ্ক len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

পূর্ণাঙ্ক sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

সংরচনা complexinit0 {
    পূর্ণাঙ্ক a;
    পূর্ণাঙ্ক b;
};

সংরচনা complexinit {
    পূর্ণাঙ্ক a;
    ধ্রুৱ সংরচনা complexinit0 *b;
};

ধ্রুৱ স্থির সংরচনা complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ধ্রুৱ সংরচনা complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

সংরচনা complexinit2 {
	পূর্ণাঙ্ক a;
	পূর্ণাঙ্ক b[];
};

সংরচনা complexinit2 cix20;

সংরচনা complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

সংরচনা complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

প্রকারনির্দেশ পূর্ণাঙ্ক arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
প্রকারনির্দেশ পূর্ণাঙ্ক arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
পূর্ণাঙ্ক sinit23[2] = { "astring" ? পরিমাণ("astring") : -1,
		   &sinit23 ? 42 : -1 };

পূর্ণাঙ্ক sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
সংরচনা bf_SS {unsigned পূর্ণাঙ্ক bit:1,bits31:31; };
সংরচনা bf_SS bf_init = { .bit = 1 };
সংরচনা bfn_SS {পূর্ণাঙ্ক a,b; সংরচনা bf_SS c; পূর্ণাঙ্ক d,e; };
সংরচনা bfn_SS bfn_init = { .c.bit = 1 };
সংরচনা bfa_SS {পূর্ণাঙ্ক a,b; সংরচনা bf_SS c[3]; পূর্ণাঙ্ক d,e; };
সংরচনা bfa_SS bfa_init = { .c[1].bit = 1 };
সংরচনা bf_SS bfaa_init[3] = { [1].bit = 1 };
সংরচনা bf_SS bfaa_vinit[] = { [2].bit = 1 };
সংরচনা b2_SS {long long পূর্ণাঙ্ক field : 52; long long পূর্ণাঙ্ক pad : 12; };
সংরচনা b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

বাহ্য পূর্ণাঙ্ক external_inited = 42;

শূন্য init_test(শূন্য)
{
    পূর্ণাঙ্ক linit1 = 2;
    পূর্ণাঙ্ক linit2 = { 3 };
    পূর্ণাঙ্ক linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    পূর্ণাঙ্ক linit6[] = { 1, 2, 3 };
    পূর্ণাঙ্ক i, j;
    ৱর্ণ linit8[] = "hello" "trala";
    পূর্ণাঙ্ক linit12[10] = { 1, 2 };
    পূর্ণাঙ্ক linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    ৱর্ণ linit14[10] = "abc";
    পূর্ণাঙ্ক linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    সংরচনা linit16 { পূর্ণাঙ্ক a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    পূর্ণাঙ্ক linit17 = পরিমাণ(linit17);
    পূর্ণাঙ্ক zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    পূর্ণাঙ্ক linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    সংরচনা bf_SS bf_finit = { .bit = 1 };
    সংরচনা bfn_SS bfn_finit = { .c.bit = 1 };
    সংরচনা bfa_SS bfa_finit = { .c[1].bit = 1 };
    সংরচনা bf_SS bfaa_finit[3] = { [1].bit = 1 };
    সংরচনা bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    সংরচনা b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           পরিমাণ(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", পরিমাণ(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           পরিমাণ(sinit7),
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

    বাবে(i=0;i<3;i++)
        বাবে(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", পরিমাণ(linit6));
    printf("linit8=%d %s\n", পরিমাণ(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           পরিমাণ(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    বাবে(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    বাবে(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    বাবে(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    বাবে(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    বাবে(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", পরিমাণ cix20, পরিমাণ cix21, পরিমাণ cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", পরিমাণ(sinit19), পরিমাণ(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", পরিমাণ(sinit21), পরিমাণ(sinit22));
    printf("arrtype6: %d\n", পরিমাণ(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    বাবে (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

শূন্য switch_uc(unsigned ৱর্ণ uc)
{
	ৱিকল্প (uc) {
	    পক্ষ 0xfb ... 0xfe:
		printf("ucsw:1\n");
		ভঙ্গ;
	    পক্ষ 0xff:
		printf("ucsw:2\n");
		ভঙ্গ;
	    পক্ষ 0 ... 5:
		printf("ucsw:3\n");
		ভঙ্গ;
	    স্ৱভাৱ:
		printf("ucsw: broken!\n");
	}
}

শূন্য switch_sc(signed ৱর্ণ sc)
{
	ৱিকল্প (sc) {
	    পক্ষ -5 ... -2:
		printf("scsw:1\n");
		ভঙ্গ;
	    পক্ষ -1:
		printf("scsw:2\n");
		ভঙ্গ;
	    পক্ষ 0 ... 5:
		printf("scsw:3\n");
		ভঙ্গ;
	    স্ৱভাৱ:
		printf("scsw: broken!\n");
	}
}

শূন্য switch_test()
{
    পূর্ণাঙ্ক i;
    unsigned long long ull;
    long long ll;

    বাবে(i=0;i<15;i++) {
        ৱিকল্প(i) {
        পক্ষ 0:
        পক্ষ 1:
            printf("a");
            ভঙ্গ;
        স্ৱভাৱ:
            printf("%d", i);
            ভঙ্গ;
        পক্ষ 8 ... 12:
            printf("c");
            ভঙ্গ;
        পক্ষ 3:
            printf("b");
            ভঙ্গ;
        পক্ষ 0xc33c6b9fU:
        পক্ষ 0x7c9eeeb9U:
            ভঙ্গ;
        }
    }
    printf("\n");

    বাবে (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	ৱিকল্প (ull) {
	    পক্ষ 1ULL << 61:
		printf("ullsw:1\n");
		ভঙ্গ;
	    পক্ষ 2ULL << 61:
		printf("ullsw:2\n");
		ভঙ্গ;
	    পক্ষ 3ULL << 61:
		printf("ullsw:3\n");
		ভঙ্গ;
	    পক্ষ 4ULL << 61:
		printf("ullsw:4\n");
		ভঙ্গ;
	    পক্ষ 5ULL << 61:
		printf("ullsw:5\n");
		ভঙ্গ;
	    স্ৱভাৱ:
		printf("ullsw: broken!\n");
	}
    }

    বাবে (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	ৱিকল্প (ll) {
	    পক্ষ 1LL << 61:
		printf("llsw:1\n");
		ভঙ্গ;
	    পক্ষ 2LL << 61:
		printf("llsw:2\n");
		ভঙ্গ;
	    পক্ষ 3LL << 61:
		printf("llsw:3\n");
		ভঙ্গ;
	    পক্ষ 4LL << 61:
		printf("llsw:4\n");
		ভঙ্গ;
	    পক্ষ 5LL << 61:
		printf("llsw:5\n");
		ভঙ্গ;
	    স্ৱভাৱ:
		printf("llsw: broken!\n");
	}
    }

    বাবে (i = -5; i <= 5; i++) {
	switch_uc((unsigned ৱর্ণ)i);
    }

    বাবে (i = -5; i <= 5; i++) {
	switch_sc ((signed ৱর্ণ)i);
    }
}

/* ISOC99 _Bool type */
শূন্য c99_bool_test(শূন্য)
{
#ifdef BOOL_ISOC99
    পূর্ণাঙ্ক a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", পরিমাণ(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           পরিমাণ ((চঞ্চল পূর্ণাঙ্ক)a ? b : b2));
#endif
}

শূন্য bitfield_test(শূন্য)
{
    পূর্ণাঙ্ক a;
    short sa;
    unsigned ৱর্ণ ca;
    সংরচনা sbf1 {
        পূর্ণাঙ্ক f1 : 3;
        পূর্ণাঙ্ক : 2;
        পূর্ণাঙ্ক f2 : 1;
        পূর্ণাঙ্ক : 0;
        পূর্ণাঙ্ক f3 : 5;
        পূর্ণাঙ্ক f4 : 7;
        unsigned পূর্ণাঙ্ক f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", পরিমাণ(st1));

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
    যদি (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    অন্যথা 
        printf("st1.f1 != -1\n");
    যদি (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    অন্যথা 
        printf("st1.f2 != -1\n");

    সংরচনা sbf2 {
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

#যদি 0
    Disabled বাবে now until further clarification re GCC compatibility
    সংরচনা sbf3 {
        পূর্ণাঙ্ক f1 : 7;
        পূর্ণাঙ্ক f2 : 1;
        ৱর্ণ f3;
        পূর্ণাঙ্ক f4 : 8;
        পূর্ণাঙ্ক f5 : 1;
        পূর্ণাঙ্ক f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", পরিমাণ(st3));
#endif

    সংরচনা sbf4 {
	পূর্ণাঙ্ক x : 31;
	ৱর্ণ y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    সংরচনা sbf5 {
	পূর্ণাঙ্ক a;
	ৱর্ণ b;
	পূর্ণাঙ্ক x : 12, y : 4, : 0, : 4, z : 3;
	ৱর্ণ c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    সংরচনা sbf6 {
	short x : 12;
	unsigned ৱর্ণ y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#অন্যথা
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
দ্ৱিগুণ strtod(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr);

#যদি defined(_WIN32)
ভিন্ন strtof(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr) {ঘূৰাই (ভিন্ন)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr) {ঘূৰাই (LONG_DOUBLE)strtod(nptr, endptr);}
#অন্যথা
ভিন্ন strtof(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr);
LONG_DOUBLE strtold(ধ্রুৱ ৱর্ণ *nptr, ৱর্ণ **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
শূন্য prefix ## cmp(type a, type b)\
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
শূন্য prefix ## fcast(type a)\
{\
    ভিন্ন fa;\
    দ্ৱিগুণ da;\
    LONG_DOUBLE la;\
    পূর্ণাঙ্ক ia;\
    long long llia;\
    unsigned পূর্ণাঙ্ক ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (পূর্ণাঙ্ক)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned পূর্ণাঙ্ক)a;\
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
    যদি (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
ভিন্ন prefix ## retf(type a) { ঘূৰাই a; }\
দ্ৱিগুণ prefix ## retd(type a) { ঘূৰাই a; }\
LONG_DOUBLE prefix ## retld(type a) { ঘূৰাই a; }\
\
শূন্য prefix ## call(শূন্য)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (দ্ৱিগুণ)strto ## prefix("1.2", রিক্ত));\
}\
\
শূন্য prefix ## signed_zeros(শূন্য) \
{\
  type x = 0.0, y = -0.0, n, p;\
  যদি (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  অন্যথা\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  যদি (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  অন্যথা\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  যদি (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  অন্যথা\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  যদি (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  অন্যথা\
    printf ("x != -y; this is wrong!\n");\
}\
শূন্য prefix ## nan(শূন্য)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
শূন্য prefix ## test(শূন্য)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    যদি (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, ভিন্ন, ভিন্ন, "%f")
FTEST(d, দ্ৱিগুণ, দ্ৱিগুণ, "%f")
FTEST(ld, long দ্ৱিগুণ, LONG_DOUBLE, "%Lf")

দ্ৱিগুণ ftab1[3] = { 1.2, 3.4, -5.6 };


শূন্য float_test(শূন্য)
{
#যদি !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    চঞ্চল ভিন্ন fa, fb;
    চঞ্চল দ্ৱিগুণ da, db;
    পূর্ণাঙ্ক a;
    unsigned পূর্ণাঙ্ক b;
    স্থির দ্ৱিগুণ nan2 = 0.0/0.0;
    স্থির দ্ৱিগুণ inf1 = 1.0/0.0;
    স্থির দ্ৱিগুণ inf2 = 1e5000;
    চঞ্চল LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", পরিমাণ(ভিন্ন));
    printf("sizeof(double) = %d\n", পরিমাণ(দ্ৱিগুণ));
    printf("sizeof(long double) = %d\n", পরিমাণ(LONG_DOUBLE));
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

পূর্ণাঙ্ক fib(পূর্ণাঙ্ক n)
{
    যদি (n <= 2)
        ঘূৰাই 1;
    অন্যথা
        ঘূৰাই fib(n-1) + fib(n-2);
}

#যদি __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#অন্যথা
শূন্য __attribute__((aligned(16))) aligned_function(পূর্ণাঙ্ক i) {}
#endif

শূন্য funcptr_test()
{
    শূন্য (*func)(পূর্ণাঙ্ক);
    পূর্ণাঙ্ক a;
    সংরচনা {
        পূর্ণাঙ্ক dummy;
        শূন্য (*func)(পূর্ণাঙ্ক);
    } st1;
    long diff;

    func = &অঙ্ক;
    (*func)(12345);
    func = অঙ্ক;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = অঙ্ক;
    st1.func(12346);
    printf("sizeof1 = %d\n", পরিমাণ(funcptr_test));
    printf("sizeof2 = %d\n", পরিমাণ funcptr_test);
    printf("sizeof3 = %d\n", পরিমাণ(&funcptr_test));
    printf("sizeof4 = %d\n", পরিমাণ &funcptr_test);
    a = 0;
    func = অঙ্ক + a;
    diff = func - অঙ্ক;
    func(42);
    (func + diff)(42);
    (অঙ্ক + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((পূর্ণাঙ্ক)(uintptr_t)func) & 15);
}

শূন্য lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    যদি (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*দ্বিমিক*/
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

শূন্য llshift(long long a, পূর্ণাঙ্ক b)
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

শূন্য llfloat(শূন্য)
{
    ভিন্ন fa;
    দ্ৱিগুণ da;
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

long long llfunc1(পূর্ণাঙ্ক a)
{
    ঘূৰাই a * 2;
}

সংরচনা S {
    পূর্ণাঙ্ক id; 
    ৱর্ণ item;
};

long long পূর্ণাঙ্ক মান(সংরচনা S *v)
{
    ঘূৰাই ((long long পূর্ণাঙ্ক)v->item);
}

long long llfunc2(long long x, long long y, পূর্ণাঙ্ক z)
{
    ঘূৰাই x * y * z;
}

শূন্য check_opl_save_regs(ৱর্ণ *a, long long b, পূর্ণাঙ্ক c)
{
    *a = b < 0 && !c;
}

শূন্য longlong_test(শূন্য)
{
    long long a, b, c;
    পূর্ণাঙ্ক ia;
    unsigned পূর্ণাঙ্ক ua;
    printf("sizeof(long long) = %d\n", পরিমাণ(long long));
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
#যদি 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          সংরচনা S a;

          a.item = 3;
          printf("%lld\n", মান(&a));
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
    u = (unsigned)(পূর্ণাঙ্ক)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    ৱর্ণ cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

শূন্য manyarg_test(শূন্য)
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

শূন্য*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        সংরচনা X { পূর্ণাঙ্ক _x; };
        সংরচনা X *x = va_arg(ap, সংরচনা X *);
        ঘূৰাই x;
}

শূন্য vprintf1(ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list ap, aq;
    ধ্রুৱ ৱর্ণ *p;
    পূর্ণাঙ্ক c, i;
    দ্ৱিগুণ d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    বাবে(;;) {
        c = *p;
        যদি (c == '\0')
            ভঙ্গ;
        p++;
        যদি (c == '%') {
            c = *p;
            ৱিকল্প(c) {
            পক্ষ '\0':
                গচ্ছ the_end;
            পক্ষ 'd':
                i = va_arg(ap, পূর্ণাঙ্ক);
                printf("%d", i);
                ভঙ্গ;
            পক্ষ 'f':
                d = va_arg(ap, দ্ৱিগুণ);
                printf("%f", d);
                ভঙ্গ;
            পক্ষ 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                ভঙ্গ;
            পক্ষ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                ভঙ্গ;
            }
            p++;
        } অন্যথা {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

সংরচনা myspace {
    short পূর্ণাঙ্ক profile;
};
সংরচনা myspace2 {
#যদি CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    ৱর্ণ a[1];
#অন্যথা
    ৱর্ণ a[0];
#endif
};
সংরচনা myspace3 {
    ৱর্ণ a[1];
};
সংরচনা myspace4 {
    ৱর্ণ a[2];
};
সংরচনা mytest {
    শূন্য *foo, *bar, *baz;
};

সংরচনা mytest stdarg_for_struct(সংরচনা myspace bob, ...)
{
    সংরচনা myspace george, bill;
    সংরচনা myspace2 alex1;
    সংরচনা myspace3 alex2;
    সংরচনা myspace4 alex3;
    va_list ap;
    short পূর্ণাঙ্ক validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, সংরচনা myspace2);
    alex2    = va_arg(ap, সংরচনা myspace3);
    alex3    = va_arg(ap, সংরচনা myspace4);
    bill     = va_arg(ap, সংরচনা myspace);
    george   = va_arg(ap, সংরচনা myspace);
    validate = va_arg(ap, পূর্ণাঙ্ক);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ঘূৰাই (সংরচনা mytest) {};
}

শূন্য stdarg_for_libc(ধ্রুৱ ৱর্ণ *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

শূন্য stdarg_syntax(পূর্ণাঙ্ক n, ...)
{
    পূর্ণাঙ্ক i;
    va_list ap;
    যদি (1)
      va_start(ap, n);
    অন্যথা
      ;
    i = va_arg(ap, পূর্ণাঙ্ক);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

প্রকারনির্দেশ সংরচনা{
    দ্ৱিগুণ x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

স্থির শূন্য stdarg_double_struct(পূর্ণাঙ্ক nargs, পূর্ণাঙ্ক posd,...)
{
    পূর্ণাঙ্ক i;
    দ্ৱিগুণ d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    বাবে(i = 0; i < nargs; i++) {
        যদি (i == posd) {
            d = va_arg (args, দ্ৱিগুণ);
            printf ("d %d = %g\n", i, d);
        }
        অন্যথা {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

শূন্য stdarg_test(শূন্য)
{
    LONG_DOUBLE ld = 1234567891234LL;
    সংরচনা myspace bob;
    সংরচনা myspace2 bob2;
    সংরচনা myspace3 bob3;
    সংরচনা myspace4 bob4;

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
#যদি !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

পূর্ণাঙ্ক reltab[3] = { 1, 2, 3 };

পূর্ণাঙ্ক *rel1 = &reltab[1];
পূর্ণাঙ্ক *rel2 = &reltab[2];

শূন্য getmyaddress(শূন্য)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(শূন্য)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ঘূৰাই ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
শূন্য relocation_test(শূন্য)
{
    শূন্য (*fptr)(শূন্য) = (শূন্য (*)(শূন্য))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

শূন্য old_style_f(a,b,c)
     পূর্ণাঙ্ক a, b;
     দ্ৱিগুণ c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

শূন্য decl_func1(পূর্ণাঙ্ক cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

শূন্য decl_func2(cmpfn)
পূর্ণাঙ্ক cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

শূন্য old_style_function_test(শূন্য)
{
#যদি CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#অন্যথা
    old_style_f((শূন্য *)1, 2, 3.0);
#endif
    decl_func1(রিক্ত);
    decl_func2(রিক্ত);
}

শূন্য alloca_test()
{
    ৱর্ণ *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    ৱর্ণ *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

শূন্য *bounds_checking_is_enabled()
{
    ৱর্ণ ca[10], *cp = ca-1;
    ঘূৰাই (ca != cp + 1) ? cp : রিক্ত;
}

প্রকারনির্দেশ পূর্ণাঙ্ক constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

শূন্য c99_vla_test_1(পূর্ণাঙ্ক size1, পূর্ণাঙ্ক size2)
{
    পূর্ণাঙ্ক size = size1 * size2;
    পূর্ণাঙ্ক tab1[size][2], tab2[10][2];
    শূন্য *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (পরিমাণ tab1 == size1 * size2 * 2 * পরিমাণ(পূর্ণাঙ্ক)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (পরিমাণ(পূর্ণাঙ্ক) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * পরিমাণ(পূর্ণাঙ্ক)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((পূর্ণাঙ্ক *) (tab1_ptr + (size1 * 2 + 1) * পরিমাণ(পূর্ণাঙ্ক))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    যদি (bad_ptr = bounds_checking_is_enabled()) {
        পূর্ণাঙ্ক *t1 = &tab1[size1 * size2 - 1][3];
        পূর্ণাঙ্ক *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        ৱর্ণ*c1 = 1 + পরিমাণ(tab1) + (ৱর্ণ*)tab1;
        ৱর্ণ*c2 = 1 + পরিমাণ(tab2) + (ৱর্ণ*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        পূর্ণাঙ্ক *i1 = tab1[-1];
        পূর্ণাঙ্ক *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        পূর্ণাঙ্ক *x1 = tab1[size1 * size2 + 1];
        পূর্ণাঙ্ক *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } অন্যথা {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

শূন্য c99_vla_test_2(পূর্ণাঙ্ক d, পূর্ণাঙ্ক h, পূর্ণাঙ্ক w)
{
    পূর্ণাঙ্ক x, y, z;
    পূর্ণাঙ্ক (*arr)[h][w] = malloc(পরিমাণ(পূর্ণাঙ্ক) * d*h*w);
    পূর্ণাঙ্ক c = 1;
    স্থির পূর্ণাঙ্ক (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    বাবে (z=0; z<d; z++) {
        বাবে (y=0; y<h; y++) {
            বাবে (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    বাবে (z=0; z<d; z++) {
        বাবে (y=0; y<h; y++) {
            বাবে (x=0; x<w; x++) {
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
        পরিমাণ (*arr), পরিমাণ (*arr)[0], পরিমাণ (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == পরিমাণ (*arr + 1) - পরিমাণ arr,
        0 == পরিমাণ পরিমাণ *arr - পরিমাণ arr,
        starr[0][2][3] == arr[1][2][3]
        );
    মুক্ত (arr);
}

শূন্য c99_vla_test_3a (পূর্ণাঙ্ক arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

শূন্য c99_vla_test_3b(পূর্ণাঙ্ক s, পূর্ণাঙ্ক arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

শূন্য c99_vla_test_3c(পূর্ণাঙ্ক s, পূর্ণাঙ্ক arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

শূন্য c99_vla_test_3d(পূর্ণাঙ্ক s, পূর্ণাঙ্ক arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

শূন্য c99_vla_test_3e(পূর্ণাঙ্ক s, পূর্ণাঙ্ক arr[][3][--s])
{
    printf ("%d %d %d\n", পরিমাণ arr, s, arr[1][2][3]);
}

শূন্য c99_vla_test_3(শূন্য)
{
    পূর্ণাঙ্ক a[2][3][4];

    memset (a, 0, পরিমাণ(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

শূন্য c99_vla_test(শূন্য)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


শূন্য sizeof_test(শূন্য)
{
    পূর্ণাঙ্ক a;
    পূর্ণাঙ্ক **ptr;

    printf("sizeof(int) = %d\n", পরিমাণ(পূর্ণাঙ্ক));
    printf("sizeof(unsigned int) = %d\n", পরিমাণ(unsigned পূর্ণাঙ্ক));
    printf("sizeof(long) = %d\n", পরিমাণ(long));
    printf("sizeof(unsigned long) = %d\n", পরিমাণ(unsigned long));
    printf("sizeof(short) = %d\n", পরিমাণ(short));
    printf("sizeof(unsigned short) = %d\n", পরিমাণ(unsigned short));
    printf("sizeof(char) = %d\n", পরিমাণ(ৱর্ণ));
    printf("sizeof(unsigned char) = %d\n", পরিমাণ(unsigned ৱর্ণ));
    printf("sizeof(func) = %d\n", পরিমাণ sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", পরিমাণ a++);
    printf("a=%d\n", a);
    ptr = রিক্ত;
    printf("sizeof(**ptr) = %d\n", পরিমাণ (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", পরিমাণ(পরিমাণ(পূর্ণাঙ্ক)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -পরিমাণ(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(পূর্ণাঙ্ক));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned পূর্ণাঙ্ক));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(ৱর্ণ));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned ৱর্ণ));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", পরিমাণ(ৱর্ণ[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   পরিমাণ( (সংরচনা {পূর্ণাঙ্ক i; পূর্ণাঙ্ক j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   পরিমাণ (সংরচনা {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", পরিমাণ(t && 0));
    printf("sizeof(1 && 1) = %d\n", পরিমাণ(1 && 1));
    printf("sizeof(t || 1) = %d\n", পরিমাণ(t || 1));
    printf("sizeof(0 || 0) = %d\n", পরিমাণ(0 || 0));

    পূর্ণাঙ্ক arr[4], fn();
    printf("sizeof(0, arr) = %d\n", পরিমাণ(0, arr));
    printf("sizeof(0, fn) = %d\n", পরিমাণ(0, fn));
}

শূন্য typeof_test(শূন্য)
{
    দ্ৱিগুণ a;
    typeof(a) b;
    typeof(ভিন্ন) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


সংরচনা hlist_গ্ৰন্থি;
সংরচনা hlist_head {
    সংরচনা hlist_গ্ৰন্থি *first, *last;
};

শূন্য consume_ulong (unsigned long i)
{
    i = 0;
}

শূন্য statement_ৰাশিমালা_test(শূন্য)
{
    পূর্ণাঙ্ক a, i;

    /* Basic stmt expr test */
    a = 0;
    বাবে(i=0;i<10;i++) {
        a += 1 + 
            ( { পূর্ণাঙ্ক b, j; 
                b = 0; 
                বাবে(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    শূন্য *v = (শূন্য*)39;
    typeof(({
	    (সংরচনা hlist_গ্ৰন্থি *)v;
	    })) x;
    typeof (x)
	ptr = (সংরচনা hlist_গ্ৰন্থি *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            স্থির ধ্রুৱ ৱর্ণ *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    পূর্ণাঙ্ক t = 40;
    পূর্ণাঙ্ক b = ({ পূর্ণাঙ্ক t = 41; t; });
    পূর্ণাঙ্ক c = ({ পূর্ণাঙ্ক t = 42; t; });

    /* Test that aggregate return values work.  */
    সংরচনা hlist_head h
	= ({
	   প্রকারনির্দেশ সংরচনা hlist_head T;
	   long pre = 48;
	   T t = { (শূন্য*)43, (শূন্য*)44 };
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
       LBL: যদি (i++ == 0) গচ্ছ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      গচ্ছ LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

শূন্য local_label_test(শূন্য)
{
    পূর্ণাঙ্ক a;
    গচ্ছ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        গচ্ছ l1;
    l4:
        printf("aa1\n");
        গচ্ছ l3;
    l2:
        printf("aa3\n");
        গচ্ছ l4;
    l1:
        printf("aa2\n");
        গচ্ছ l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    ঘূৰাই;
 l4:
    printf("bb1\n");
    গচ্ছ l2;
 l1:
    printf("bb2\n");
    গচ্ছ l4;
}

/* inline assembler test */
#যদি (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

প্রকারনির্দেশ __SIZE_TYPE__ word;

/* from linux kernel */
স্থির ৱর্ণ * strncat1(ৱর্ণ * dest,ধ্রুৱ ৱর্ণ * src,size_t গুনতি_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (গুনতি_2)
	: "memory");
ঘূৰাই dest;
}

স্থির ৱর্ণ * strncat2(ৱর্ণ * dest,ধ্রুৱ ৱর্ণ * src,size_t গুনতি_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (গুনতি_2)
	: "memory");
ঘূৰাই dest;
}

স্থির অন্তঃস্থ শূন্য * memcpy1(শূন্য * to, ধ্রুৱ শূন্য * from, size_t n)
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
ঘূৰাই (to);
}

স্থির অন্তঃস্থ শূন্য * memcpy2(শূন্য * to, ধ্রুৱ শূন্য * from, size_t n)
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
ঘূৰাই (to);
}

স্থির __inline__ শূন্য sigaddset1(unsigned পূর্ণাঙ্ক *set, পূর্ণাঙ্ক _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

স্থির __inline__ শূন্য sigdelset1(unsigned পূর্ণাঙ্ক *set, পূর্ণাঙ্ক _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
স্থির __inline__ __const__ unsigned পূর্ণাঙ্ক swab32(unsigned পূর্ণাঙ্ক x)
{
        ঘূৰাই ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#অন্যথা
স্থির __inline__ __const__ unsigned পূর্ণাঙ্ক swab32(unsigned পূর্ণাঙ্ক x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ঘূৰাই x;
}
#endif

স্থির __inline__ unsigned long long mul64(unsigned পূর্ণাঙ্ক a, unsigned পূর্ণাঙ্ক b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned পূর্ণাঙ্ক resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#অন্যথা
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    ঘূৰাই res;
}

স্থির __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#অন্যথা
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    ঘূৰাই res;
}

সংরচনা struct123 {
    পূর্ণাঙ্ক a;
    পূর্ণাঙ্ক b;
};
সংরচনা struct1231 {
    word addr;
};

word mconstraint_test(সংরচনা struct1231 *r)
{
    word ret;
    unsigned পূর্ণাঙ্ক a[2];
    a[0] = 0;
    __asm__ চঞ্চল ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(সংরচনা struct123 *)r->addr));
    ঘূৰাই ret + a[0];
}

#ifdef __x86_64__
পূর্ণাঙ্ক fls64(unsigned long long x)
{
  পূর্ণাঙ্ক bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ঘূৰাই bitpos + 1;
}
#endif

শূন্য other_constraints_test(শূন্য)
{
    word ret;
    পূর্ণাঙ্ক var;
#যদি CC_NAME != CC_clang
    __asm__ চঞ্চল ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
শূন্য base_func(শূন্য)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
বাহ্য শূন্য override_func1 (শূন্য);
বাহ্য শূন্য override_func2 (শূন্য);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

শূন্য override_func2 (শূন্য)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
বাহ্য পূর্ণাঙ্ক bug_table[] __attribute__((section("__bug_table")));
ৱর্ণ * get_asm_string (শূন্য)
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
  বাহ্য পূর্ণাঙ্ক some_প্ৰতীক;
  asm চঞ্চল (".globl some_symbol\n"
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
  ৱর্ণ * str = ((ৱর্ণ*)bug_table) + bug_table[1];
  ঘূৰাই str;
#অন্যথা
  ঘূৰাই (ৱর্ণ *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
বাহ্য unsigned ৱর্ণ alld_stuff[];
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

শূন্য asm_local_label_diff (শূন্য)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
শূন্য asm_local_statics (শূন্য)
{
  স্থির পূর্ণাঙ্ক localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

স্থির
unsigned পূর্ণাঙ্ক set;

শূন্য fancy_copy (unsigned *in, unsigned *out)
{
  asm চঞ্চল ("" : "=r" (*out) : "0" (*in));
}

শূন্য fancy_copy2 (unsigned *in, unsigned *out)
{
  asm চঞ্চল ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#যদি defined __x86_64__
শূন্য clobber_r12(শূন্য)
{
    asm চঞ্চল("mov $1, %%r12" ::: "r12");
}
#endif

শূন্য test_উপৰেৰ_clobbers_really(শূন্য)
{
#যদি defined __x86_64__
    পঞ্জিকা word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm চঞ্চল("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm চঞ্চল("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

শূন্য test_উপৰেৰ_clobbers(শূন্য)
{
#যদি defined __x86_64__
    word x1, x2;
    asm চঞ্চল("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_উপৰেৰ_clobbers_really();
    asm চঞ্চল("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm চঞ্চল("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

স্থির long cpu_সংখ্যা;
শূন্য trace_console(long len, long len2)
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
    যদি (0
        &&
            ({
              long pscr_ret__;
              ৱিকল্প(len) {
                পক্ষ 4:
                    {
                       long pfo_ret__;
                       ৱিকল্প (len2) {
                         পক্ষ 8:	printf("bla"); pfo_ret__ = 42; ভঙ্গ;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ভঙ্গ;
                পক্ষ 8:
                    {
                       long pfo_ret__;
                       ৱিকল্প (len2) {
                         পক্ষ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_সংখ্যা));	ভঙ্গ;
                         পক্ষ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_সংখ্যা));	ভঙ্গ;
                         পক্ষ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_সংখ্যা));	ভঙ্গ;
                         পক্ষ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_সংখ্যা));	ভঙ্গ;
                         স্ৱভাৱ: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ভঙ্গ;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

শূন্য test_asm_dead_code(শূন্য)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm চঞ্চল ("" : "=D" (rdi) : "0" (0));
  (শূন্য)পরিমাণ (({
      পূর্ণাঙ্ক var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm চঞ্চল ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

শূন্য test_asm_call(শূন্য)
{
#যদি defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  স্থির ৱর্ণ str[] = "PATH";
  ৱর্ণ *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm চঞ্চল ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#যদি 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#অন্যথা
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#যদি defined __x86_64__
# define RX "(%rip)"
#অন্যথা
# define RX
#endif

শূন্য asm_dot_test(শূন্য)
{
#ifndef __APPLE__
    পূর্ণাঙ্ক x;
    বাবে (x = 1;; ++x) {
        পূর্ণাঙ্ক r = x;
        ৱিকল্প (x) {
        পক্ষ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        পক্ষ 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#অন্যথা
            asm(".text; mov $123, %eax; jmp p0");
#endif
	পক্ষ 3:
#যদি !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#অন্যথা
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        পক্ষ 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#অন্যথা
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#অন্যথা
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        পক্ষ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ভঙ্গ;
	}
        যদি (r == x)
            ভঙ্গ;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

শূন্য asm_pcrel_test(শূন্য)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

শূন্য asm_test(শূন্য)
{
    ৱর্ণ buf[128];
    unsigned পূর্ণাঙ্ক val, val2;
    সংরচনা struct123 s1;
    সংরচনা struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    পূর্ণাঙ্ক base_func = 42;
    শূন্য override_func3 (শূন্য);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    পঞ্জিকা পূর্ণাঙ্ক regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm চঞ্চল ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm চঞ্চল ("xorl %eax, %eax");

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
    গচ্ছ label1;
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
    asm চঞ্চল(".weak override_func3\n.set override_func3, base_func");
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
    asm চঞ্চল("" : "=r" (asmret) : "0"(s2));
    যদি (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm চঞ্চল("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    যদি (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm চঞ্চল ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_উপৰেৰ_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ঘূৰাই;
 label1:
    গচ্ছ label2;
}

#অন্যথা

শূন্য asm_test(শূন্য)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

পূর্ণাঙ্ক constant_p_var;

পূর্ণাঙ্ক func(শূন্য);


/* __builtin_clz and __builtin_ctz return random values for 0 */
স্থির শূন্য builtin_test_bits(unsigned long long x, পূর্ণাঙ্ক cnt[])
{
#যদি GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    যদি ((unsigned পূর্ণাঙ্ক) x) cnt[3] += __builtin_clz(x);
    যদি ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    যদি ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    যদি ((unsigned পূর্ণাঙ্ক) x) cnt[6] += __builtin_ctz(x);
    যদি ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    যদি ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#যদি GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

শূন্য builtin_test(শূন্য)
{
    short s;
    পূর্ণাঙ্ক i;
    long long ll;
#যদি GCC_MAJOR >= 3
    COMPAT_TYPE(পূর্ণাঙ্ক, পূর্ণাঙ্ক);
    COMPAT_TYPE(পূর্ণাঙ্ক, unsigned পূর্ণাঙ্ক);
    COMPAT_TYPE(পূর্ণাঙ্ক, ৱর্ণ);
    COMPAT_TYPE(পূর্ণাঙ্ক, ধ্রুৱ পূর্ণাঙ্ক);
    COMPAT_TYPE(পূর্ণাঙ্ক, চঞ্চল পূর্ণাঙ্ক);
    COMPAT_TYPE(পূর্ণাঙ্ক[2], ধ্রুৱ পূর্ণাঙ্ক[2]);
    COMPAT_TYPE(পূর্ণাঙ্ক[2][3], চঞ্চল পূর্ণাঙ্ক[][3]);
    COMPAT_TYPE(পূর্ণাঙ্ক (*)[], ধ্রুৱ পূর্ণাঙ্ক (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (ধ্রুৱ পূর্ণাঙ্ক (*)[2])0 : (পূর্ণাঙ্ক (*)[2])0),
                ধ্রুৱ পূর্ণাঙ্ক (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ধ্রুৱ পূর্ণাঙ্ক (*)[2][3])0 :
                              (চঞ্চল পূর্ণাঙ্ক (*)[2][3])0),
                ধ্রুৱ চঞ্চল পূর্ণাঙ্ক (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (চঞ্চল পূর্ণাঙ্ক (*)[2][3])0 :
                              (ধ্রুৱ পূর্ণাঙ্ক (*)[2][3])0),
                ধ্রুৱ চঞ্চল পূর্ণাঙ্ক (*)[2][3]);
#অন্যথা
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(পূর্ণাঙ্ক *, পূর্ণাঙ্ক *);
    COMPAT_TYPE(পূর্ণাঙ্ক *, শূন্য *);
    COMPAT_TYPE(পূর্ণাঙ্ক *, ধ্রুৱ পূর্ণাঙ্ক *);
    COMPAT_TYPE(ৱর্ণ *, unsigned ৱর্ণ *);
    COMPAT_TYPE(ৱর্ণ *, signed ৱর্ণ *);
    COMPAT_TYPE(ৱর্ণ *, ৱর্ণ *);
    COMPAT_TYPE(ৱর্ণ **, শূন্য *);
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
#অন্যথা
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
    i = পরিমাণ (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = পরিমাণ (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	পূর্ণাঙ্ক cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, পরিমাণ(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        বাবে (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        বাবে (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	বাবে (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#যদি defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
শূন্য weak_test(শূন্য) {}
#অন্যথা
বাহ্য পূর্ণাঙ্ক __attribute__((weak)) weak_f1(শূন্য);
বাহ্য পূর্ণাঙ্ক __attribute__((weak)) weak_f2(শূন্য);
বাহ্য পূর্ণাঙ্ক                       weak_f3(শূন্য);
বাহ্য পূর্ণাঙ্ক __attribute__((weak)) weak_v1;
বাহ্য পূর্ণাঙ্ক __attribute__((weak)) weak_v2;
বাহ্য পূর্ণাঙ্ক                       weak_v3;

বাহ্য পূর্ণাঙ্ক                           (*weak_fpa)() __attribute__((weak));
বাহ্য পূর্ণাঙ্ক __attribute__((weak))     (*weak_fpb)();
বাহ্য     __attribute__((weak)) পূর্ণাঙ্ক (*weak_fpc)();

বাহ্য পূর্ণাঙ্ক                     weak_asm_f1(শূন্য) asm("weak_asm_f1x") __attribute((weak));
বাহ্য পূর্ণাঙ্ক __attribute((weak)) weak_asm_f2(শূন্য) asm("weak_asm_f2x")                    ;
বাহ্য পূর্ণাঙ্ক __attribute((weak)) weak_asm_f3(শূন্য) asm("weak_asm_f3x") __attribute((weak));
বাহ্য পূর্ণাঙ্ক                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
বাহ্য পূর্ণাঙ্ক __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
বাহ্য পূর্ণাঙ্ক __attribute((weak)) weak_asm_v3(শূন্য) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
স্থির ধ্রুৱ size_t dummy = 0;
বাহ্য __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
বাহ্য __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
বাহ্য __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

পূর্ণাঙ্ক some_lib_func(শূন্য);
পূর্ণাঙ্ক dummy_impl_of_slf(শূন্য) { ঘূৰাই 444; }
#ifndef __clang__
পূর্ণাঙ্ক some_lib_func(শূন্য) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

পূর্ণাঙ্ক weak_toolate() __attribute__((weak));
পূর্ণাঙ্ক weak_toolate() { ঘূৰাই 0; }

শূন্য __attribute__((weak)) weak_test(শূন্য)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != রিক্ত);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != রিক্ত);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != রিক্ত);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != রিক্ত);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != রিক্ত);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != রিক্ত);
#ifdef __clang__
	printf("some_lib_func=444\n");
#অন্যথা
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

পূর্ণাঙ্ক __attribute__((weak)) weak_f2() { ঘূৰাই 222; }
পূর্ণাঙ্ক __attribute__((weak)) weak_f3() { ঘূৰাই 333; }
পূর্ণাঙ্ক __attribute__((weak)) weak_v2 = 222;
পূর্ণাঙ্ক __attribute__((weak)) weak_v3 = 333;
#endif

শূন্য const_func(ধ্রুৱ পূর্ণাঙ্ক a)
{
}

শূন্য const_warn_test(শূন্য)
{
    const_func(1);
}

সংরচনা condstruct {
  পূর্ণাঙ্ক i;
};

পূর্ণাঙ্ক getme (সংরচনা condstruct *s, পূর্ণাঙ্ক i)
{
  পূর্ণাঙ্ক i1 = (i == 0 ? 0 : s)->i;
  পূর্ণাঙ্ক i2 = (i == 0 ? s : 0)->i;
  পূর্ণাঙ্ক i3 = (i == 0 ? (শূন্য*)0 : s)->i;
  পূর্ণাঙ্ক i4 = (i == 0 ? s : (শূন্য*)0)->i;
  ঘূৰাই i1 + i2 + i3 + i4;
}

সংরচনা global_data
{
  পূর্ণাঙ্ক a[40];
  পূর্ণাঙ্ক *b[40];
};

সংরচনা global_data global_data;

পূর্ণাঙ্ক global_data_getstuff (পূর্ণাঙ্ক *, পূর্ণাঙ্ক);

শূন্য global_data_callit (পূর্ণাঙ্ক i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

পূর্ণাঙ্ক global_data_getstuff (পূর্ণাঙ্ক *p, পূর্ণাঙ্ক i)
{
  ঘূৰাই *p + i;
}

শূন্য global_data_test (শূন্য)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

সংরচনা cmpcmpS
{
  unsigned ৱর্ণ fill : 3;
  unsigned ৱর্ণ b1 : 1;
  unsigned ৱর্ণ b2 : 1;
  unsigned ৱর্ণ fill2 : 3;
};

পূর্ণাঙ্ক glob1, glob2, glob3;

শূন্য compare_comparisons (সংরচনা cmpcmpS *s)
{
  যদি (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

শূন্য cmp_comparison_test(শূন্য)
{
  সংরচনা cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

পূর্ণাঙ্ক fcompare (দ্ৱিগুণ a, দ্ৱিগুণ b, পূর্ণাঙ্ক code)
{
  ৱিকল্প (code) {
    পক্ষ 0: ঘূৰাই a == b;
    পক্ষ 1: ঘূৰাই a != b;
    পক্ষ 2: ঘূৰাই a < b;
    পক্ষ 3: ঘূৰাই a >= b;
    পক্ষ 4: ঘূৰাই a > b;
    পক্ষ 5: ঘূৰাই a <= b;
  }
  ঘূৰাই 0;
}

শূন্য math_cmp_test(শূন্য)
{
  দ্ৱিগুণ nan = 0.0/0.0;
  দ্ৱিগুণ one = 1.0;
  দ্ৱিগুণ two = 2.0;
  পূর্ণাঙ্ক comp = 0;
  পূর্ণাঙ্ক v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  যদি (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  যদি (a op b) \
    bug (a,b,op,iop,2); \
  যদি (a iop b) \
    ; \
  অন্যথা \
    bug (a,b,op,iop,3); \
  যদি ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  যদি ((a iop b) || comp) \
    ; \
  অন্যথা \
    bug (a,b,op,iop,5); \
  যদি (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  যদি (!fcompare (nan, nan, 1))
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

দ্ৱিগুণ get100 () { ঘূৰাই 100.0; }

শূন্য callsave_test(শূন্য)
{
  পূর্ণাঙ্ক i, s; দ্ৱিগুণ *d; দ্ৱিগুণ t;
  s = পরিমাণ (দ্ৱিগুণ);
  printf ("callsavetest: %d\n", s);
  d = alloca (পরিমাণ(দ্ৱিগুণ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


শূন্য bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (ৱর্ণ *)__builtin_frame_address(3) + str_offset);
}
শূন্য bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (ৱর্ণ *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
শূন্য bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (ৱর্ণ *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

শূন্য builtin_frame_address_test(শূন্য)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    ৱর্ণ str[] = "__builtin_frame_address";
    ৱর্ণ *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

ৱর্ণ via_volatile (ৱর্ণ i)
{
  ৱর্ণ চঞ্চল vi;
  vi = i;
  ঘূৰাই vi;
}

শূন্য volatile_test(শূন্য)
{
    যদি (via_volatile (42) != 42)
      printf (" broken\n");
    অন্যথা
      printf (" ok\n");
}

সংরচনা __attribute__((__packed__)) Spacked {
    ৱর্ণ a;
    short b;
    পূর্ণাঙ্ক c;
};
সংরচনা Spacked spacked;
প্রকারনির্দেশ সংরচনা __attribute__((__packed__)) {
    ৱর্ণ a;
    short b;
    পূর্ণাঙ্ক c;
} Spacked2;
Spacked2 spacked2;
প্রকারনির্দেশ সংরচনা Spacked3_s {
    ৱর্ণ a;
    short b;
    পূর্ণাঙ্ক c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
সংরচনা gate_struct64 {
    unsigned short offset_নিচেৰ;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_মধ্য;
    unsigned offset_উপৰেৰ;
    unsigned zero1;
} __attribute__((packed));
প্রকারনির্দেশ সংরচনা gate_struct64 gate_desc;
gate_desc a_gate_desc;
শূন্য attrib_test(শূন্য)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", পরিমাণ(সংরচনা Spacked),
	 পরিমাণ(spacked), পরিমাণ(Spacked2), পরিমাণ(spacked2));
  printf("attr: %d %d\n", পরিমাণ(Spacked3), পরিমাণ(spacked3));
  printf("attr: %d %d\n", পরিমাণ(gate_desc), পরিমাণ(a_gate_desc));
#endif
}
বাহ্য __attribute__((__unused__)) ৱর্ণ * __attribute__((__unused__)) *
strange_attrib_placement (শূন্য);

শূন্য * __attribute__((__unused__)) get_void_ptr (শূন্য *a)
{
  ঘূৰাই a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
স্থির অন্তঃস্থ
পূর্ণাঙ্ক __get_order(unsigned long long size)
{
  পূর্ণাঙ্ক order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      সংরচনা S { পূর্ণাঙ্ক i : 1; } s; // constructed for this '1'
    }
  order = size;
  ঘূৰাই order;
}

/* This just forces the above inline function to be actually emitted.  */
পূর্ণাঙ্ক force_get_order(unsigned long s)
{
    ঘূৰাই __get_order(s);
}

#define pv(m) printf(পরিমাণ (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
শূন্য bounds_check1_test (শূন্য)
{
    সংরচনা s {
        পূর্ণাঙ্ক x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
শূন্য map_add(পূর্ণাঙ্ক a, পূর্ণাঙ্ক b, পূর্ণাঙ্ক c, পূর্ণাঙ্ক d, পূর্ণাঙ্ক e, পূর্ণাঙ্ক f, পূর্ণাঙ্ক g, পূর্ণাঙ্ক h, পূর্ণাঙ্ক i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

শূন্য func_arg_test(শূন্য)
{
    পূর্ণাঙ্ক a = 0;
    পূর্ণাঙ্ক b = 1;
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
শূন্য whitespace_test(শূন্য)
{
    ৱর্ণ *str;
    পূর্ণাঙ্ক tcc_test = 1;

#যদি 1
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
#অন্যথা
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#যদি 0
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
#যদি 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(ৰাশিমালা_test);
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
    RUN(ৰাশিমালা_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_ৰাশিমালা_test);
    RUN(ৰাশিমালা_cmp_test);
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
    RUN(statement_ৰাশিমালা_test);
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

    ঘূৰাই 0;
}
