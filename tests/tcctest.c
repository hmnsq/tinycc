/*
 * TCC auto test program
 */
#شامل "config.h"

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

#اگر defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#وگرنه
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#اگر defined(_WIN32)
#define LONG_DOUBLE دوگانه
#define LONG_DOUBLE_LITERAL(x) x
#وگرنه
#define LONG_DOUBLE long دوگانه
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

تعریفنوع __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#شامل TCCLIB_INC

#شامل TCCLIB_INC1.TCCLIB_INC2

#شامل TCCLIB_INC1.h>

#شامل TCCLIB_INC3

#شامل <tcclib.h>

#شامل "tcclib.h"

#شامل "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#وگرنه
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#شامل INC(42test)
#شامل incname
#شامل stringify(funnyname)

صحیح fib(صحیح n);
تهی رقم(صحیح n);
تهی forward_ref(تهی);
صحیح isid(صحیح c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
تهی funny_سطر_continuation (صحیح, ..\
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
#define کم_2 کم_2 ", world"

ایستا صحیح onetwothree = 123;
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

#اگر 1
#define B3 1
#وگرنهاگر 1
#define B3 2
#وگرنهاگر 0
#define B3 3
#وگرنه
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

صحیح qq(صحیح x)
{
    بازگشت x + 40;
}
#define qq(x) x

#define spin_lock(lock) انجامبده { } وقتی (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

تهی macro_test(تهی)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(بالا_2, کم_2));
    printf("s2=%s\n", xglue(بالا_2, کم_2));
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
#وگرنه
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#وگرنه
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#وگرنه
    printf("B1 not defined\n");
#endif
#وگرنه
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#وگرنه
    printf("B2 not defined\n");
#endif
#endif

#اگر 1+1
    printf("test true1\n");
#endif
#اگر 0
    printf("test true2\n");
#endif
#اگر 1-1
    printf("test true3\n");
#endif
#اگر defined(A)
    printf("test trueA\n");
#endif
#اگر defined(B)
    printf("test trueB\n");
#endif

#اگر 0
    printf("test 0\n");
#وگرنهاگر 0
    printf("test 1\n");
#وگرنهاگر 2
    printf("test 2\n");
#وگرنه
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
        صحیح a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(پیام) printf("%s\n",پیام)

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
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ثابت نویسه *fn = get_file_from_header();
      اگر (fn[0] == '.' && fn[1] == '/')
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


ایستا تهی print_رقم(نویسه *fn, صحیح سطر, صحیح رقم) {
    printf("fn %s, line %d, num %d\n", fn, سطر, رقم);
}

تهی recursive_macro_test(تهی)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_رقم(x) print_رقم(__FILE__,__LINE__,x)
    print_رقم(123);
    WRAP(print_رقم(123));
    WRAP(WRAP(print_رقم(123)));

ایستا ساختار recursive_macro { صحیح rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#اگر __TINYC__
صحیح op(a, b)
{
    بازگشت a / b;
}

صحیح ret(a)
{
    اگر (a == 2)
        بازگشت 1;
    اگر (a == 3)
        بازگشت 2;
    بازگشت 0;
}
#endif

#اگر !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
نویسه str_ag1[] = "b";
نویسه str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
نویسه str_ag3[] = { "ab"[1], 0 };
نویسه str_x[2] = { "xy" "z"[2], 0 };
#endif
نویسه *str_ar[] = { "one", "two" };
ساختار str_SS {unsigned نویسه a[3], b; };
ساختار str_SS str_sinit15 = { "r" };
ساختار str_SS str_sinit16[] = { { "q" }, 2 };

ایستا تهی string_test2()
{
    نویسه *p = "hello";
    نویسه a3[2] = { "p" };
    نویسه a4[2] = { "ab" "c"[2], 0 };
    نویسه *pa1 = "def" + 1;
    نویسه *pa2 = { "xyz" + 1 };
    صحیح i = 0;
    ساختار str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    نویسه str_ag3[] = { "ab"[1], 0 };
    نویسه str_x[2] = { "xy" "z"[2], 0 };
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

تهی ps(ثابت نویسه *s)
{
    صحیح c;
    وقتی (1) {
        c = *s;
        اگر (c == 0)
            بشکن;
        printf("%c", c);
        s++;
    }
}

ثابت نویسه foo1_string[] = "\
bar\n\
test\14\
1";

تهی string_test()
{
    unsigned صحیح b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#اگر 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    وقتی ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    وقتی (b != 0x80000000) {
        رقم(b);
        b = b * 2;
    }
    string_test2();
}


تهی if1t(صحیح n, صحیح a, صحیح b, صحیح c)
{
    اگر (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    اگر (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    اگر (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    اگر (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    اگر (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    اگر (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    اگر (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    اگر (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    اگر (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    اگر (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    اگر (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    اگر (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    اگر (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    اگر (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

تهی if2t(تهی)
{
    اگر (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

تهی if3t(تهی)
{
    فرار long long i = 1;
    اگر (i <= 18446744073709551615ULL)
      ;
    وگرنه
      printf ("if3t:wrong 1\n");
}

تهی if_test(تهی)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

تهی loop_test()
{
    صحیح i;
    i = 0;
    وقتی (i < 10)
        printf("%d", i++);
    printf("\n");
    برای(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    انجامبده {
        printf("%d", i++);
    } وقتی (i < 10);
    printf("\n");

    نویسه شمار_2 = 123;
    /* c99 for loop init test */
    برای (size_t شمار_2 = 1; شمار_2 < 3; شمار_2++)
        printf("count=%d\n", شمار_2);
    printf("count = %d\n", شمار_2);

    /* break/continue tests */
    i = 0;
    وقتی (1) {
        اگر (i == 6)
            بشکن;
        i++;
        اگر (i == 3)
            ادامه;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    انجامبده {
        اگر (i == 6)
            بشکن;
        i++;
        اگر (i == 3)
            ادامه;
        printf("%d", i);
    } وقتی(1);
    printf("\n");

    برای(i = 0;i < 10;i++) {
        اگر (i == 3)
            ادامه;
        printf("%d", i);
    }
    printf("\n");
}

تعریفنوع صحیح typedef_and_label;

تهی goto_test()
{
    صحیح i;
    ایستا تهی *label_table[3] = { &&label1, &&label2, &&label3 };
    ساختار {
        صحیح bla;
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
    اگر (i >= 10) 
        برو s_end;
    printf("%d", i);
    i++;
    برو s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    برای(i=0;i<3;i++) {
        برو *label_table[i];
    label1:
        printf("label1\n");
        برو next;
    label2:
        printf("label2\n");
        برو next;
    label3:
        printf("label3\n");
    next: ;
    }
}

شمارش {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

شمارش test {
    E5 = 1000,
};

ساختار S_enum {
    شمارش {E6 = 42, E7, E8} e:8;
};

شمارش ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

شمارش { BIASU = -1U<<31 };
شمارش { BIASS = -1 << 31 };

ایستا صحیح getint(صحیح i)
{
  اگر (i)
    بازگشت 0;
  وگرنه
    بازگشت (صحیح)(-1U << 31);
}

تهی enum_test()
{
    شمارش test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    ساختار S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    اگر (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    وگرنه
      printf("enum unsigned: wrong\n");
    اگر (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    وگرنه
      printf("enum unsigned: wrong\n");
}

تعریفنوع صحیح *my_ptr;

تعریفنوع صحیح mytype1;
تعریفنوع صحیح mytype2;

تهی typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    صحیح b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

تهی forward_test()
{
    forward_ref();
    forward_ref();
}


تهی forward_ref(تهی)
{
    printf("forward ok\n");
}

تعریفنوع ساختار struct1 {
    صحیح f1;
    صحیح f2, f3;
    اجتماع union1 {
        صحیح v1;
        صحیح v2;
    } u;
    نویسه str[3];
} struct1;

ساختار struct2 {
    صحیح a;
    نویسه b;
};

اجتماع union2 {
    صحیح w1;
    صحیح w2;
};

ساختار struct1 st1, st2;

ساختار empty_mem {
    /* nothing */ ;
    صحیح x;
};

صحیح tab[3];
صحیح tab2[3][2];

صحیح g;

تهی f1(صحیح g)
{
    printf("g1=%d\n", g);
}

تهی scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        صحیح g;
        g = 3;
        printf("g3=%d\n", g);
        {
            صحیح g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

صحیح st2_i;
صحیح *st2_p = &st2_i;
تهی scope2_test()
{
    نویسه a[50];
    st2_i = 42;
    برای (صحیح st2_i = 1; st2_i < 10; st2_i++) {
        بیرونی صحیح st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
بیرونی صحیح st_global1;
صحیح st_global1=42;
بیرونی صحیح st_global1;
صحیح st_global1;
بیرونی صحیح st_global2;
صحیح st_global2;
بیرونی صحیح st_global2;
صحیح st_global2;

تهی array_test()
{
    صحیح i, j, a[4];

    printf("sizeof(a) = %d\n", اندازه(a));
    printf("sizeof(\"a\") = %d\n", اندازه("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", اندازه(__func__));
#endif
    printf("sizeof tab %d\n", اندازه(tab));
    printf("sizeof tab2 %d\n", اندازه tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    برای(i=0;i<3;i++)
        برای(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    برای(i=0;i<3*2;i++) {
        printf(" %3d", ((صحیح *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", اندازه(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", اندازه(ptrdiff_t));
}

تهی عبارت_test()
{
    صحیح a, b;
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

صحیح isid(صحیح c)
{
    بازگشت (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

صحیح vstack[10], *vstack_ptr;

تهی vpush(صحیح vt, صحیح vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

تهی vpop(صحیح *ft, صحیح *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

تهی expr2_test()
{
    صحیح a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

صحیح const_len_ar[اندازه(1/0)]; /* div-by-zero, but in unevaluated context */

تهی constant_عبارت_test()
{
    صحیح a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", اندازه(const_len_ar));
}

صحیح tab4[10];

تهی عبارت_ptr_test()
{
    صحیح arr[10], *p, *q;
    صحیح i = -1;

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
    p = (صحیح *)((نویسه *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ساختار size12 {
            صحیح i, j, k;
        };
        ساختار size12 s[2], *sp = s;
        صحیح i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (صحیح*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (صحیح)((p - q) / 3));
}

تهی عبارت_cmp_test()
{
    صحیح a, b;
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

ساختار empty {
};

ساختار aligntest1 {
    نویسه a[10];
};

ساختار aligntest2 {
    صحیح a;
    نویسه b[10];
};

ساختار aligntest3 {
    دوگانه a, b;
};

ساختار aligntest4 {
    دوگانه a[0];
};

ساختار __attribute__((aligned(16))) aligntest5
{
    صحیح i;
};
ساختار aligntest6
{
    صحیح i;
} __attribute__((aligned(16)));
ساختار aligntest7
{
    صحیح i;
};
ساختار aligntest5 altest5[2];
ساختار aligntest6 altest6[2];
صحیح pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ساختار aligntest7 altest7[2] __attribute__((aligned(16)));

ساختار aligntest8
{
  صحیح i;
} __attribute__((aligned(4096)));

ساختار Large {
    unsigned long flags;
    اجتماع {
	تهی *u1;
	صحیح *u2;
    };

    ساختار {
	اجتماع {
	    unsigned long index;
	    تهی *freelist;
	};
	اجتماع {
	    unsigned long counters;
	    ساختار {
		صحیح bla;
	    };
	};
    };

    اجتماع {
	ساختار {
	    long u3;
	    long u4;
	};
	تهی *u5;
	ساختار {
	    unsigned long compound_head;
	    unsigned صحیح compound_dtor;
	    unsigned صحیح compound_order;
	};
    };
} __attribute__((aligned(2 * اندازه(long))));

تعریفنوع unsigned long long __attribute__((aligned(4))) unaligned_u64;

ساختار aligntest9 {
    unsigned صحیح buf_nr;
    unaligned_u64 start_lba;
};

ساختار aligntest10 {
    unsigned صحیح buf_nr;
    unsigned long long start_lba;
};

تهی struct_test()
{
    struct1 *s;
    اجتماع union2 u;
    ساختار Large ls;

    printf("sizes: %d %d %d %d\n",
           اندازه(ساختار struct1),
           اندازه(ساختار struct2),
           اندازه(اجتماع union1),
           اندازه(اجتماع union2));
    printf("offsets: %d\n", (صحیح)((نویسه*)&st1.u.v1 - (نویسه*)&st1));
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
    printf("str_addr=%x\n", (صحیح)(uintptr_t)st1.str - (صحیح)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest1), __alignof__(ساختار aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest2), __alignof__(ساختار aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest3), __alignof__(ساختار aligntest3));
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest4), __alignof__(ساختار aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest5), __alignof__(ساختار aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest6), __alignof__(ساختار aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest7), __alignof__(ساختار aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest8), __alignof__(ساختار aligntest8));
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest9), __alignof__(ساختار aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           اندازه(ساختار aligntest10), __alignof__(ساختار aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           اندازه(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           اندازه(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           اندازه(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", اندازه(ساختار empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(ساختار empty));

    printf("Large: sizeof=%d\n", اندازه(ls));
    memset(&ls, 0, اندازه(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (صحیح)((نویسه*)&ls.compound_head - (نویسه*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ایستا صحیح __csf(صحیح x) { بازگشت x; }
ایستا تهی *_csf = __csf;
#define csf(t,n) ((t(*)(صحیح))_csf)(n)

/* XXX: depend on endianness */
تهی char_short_test()
{
    صحیح var1, var2;
    signed نویسه var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed نویسه *)&var1, *(signed نویسه *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned نویسه *)&var1, *(unsigned نویسه *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(صحیح *)&var1, *(صحیح *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned صحیح *)&var1, *(unsigned صحیح *)&var2);
    *(signed نویسه *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(صحیح *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed نویسه)(var1 + 1), (signed نویسه)(var4 + 1));
#اگر !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned نویسه,0x89898989);
    var4 = csf(signed نویسه,0xabababab);
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
    var1 = (signed نویسه)(unsigned نویسه)(var3 + 1);
    var4 = (signed نویسه)(unsigned نویسه)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(صحیح)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed نویسه)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

تعریفنوع ساختار Sym {
    صحیح v;
    صحیح t;
    صحیح c;
    ساختار Sym *next;
    ساختار Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ایستا صحیح toupper1(صحیح a)
{
    بازگشت TOUPPER(a);
}

ایستا unsigned صحیح calc_vm_flags(unsigned صحیح prot)
{
  unsigned صحیح prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  بازگشت prot_bits;
}

شمارش cast_enum { FIRST, LAST };

ایستا تهی tst_cast(شمارش cast_enum ce)
{
    printf("%d\n", ce);
}

تهی bool_test()
{
    صحیح *s, a, b, t, f, i;

    a = 0;
    s = (تهی*)0;
    printf("!s=%d\n", !s);

    اگر (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#اگر 1 && 1
    printf("a1\n");
#endif
#اگر 1 || 0
    printf("a2\n");
#endif
#اگر 1 ? 0 : 1
    printf("a3\n");
#endif
#اگر 0 ? 0 : 1
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
    printf("type of bool: %d\n", (صحیح) ( (~ ((unsigned صحیح) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned صحیح)0)) / 2 );
    /* test ? : cast */
    {
        صحیح aspect_on;
        صحیح aspect_native = 65536;
        دوگانه bfu_aspect = 1.0;
        صحیح aspect;
        برای(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ایستا صحیح v1 = 34 ? : -1; /* constant case */
        ایستا صحیح v2 = 0 ? : -1; /* constant case */
        صحیح a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    برای(i=0;i<256;i++) {
        اگر (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

بیرونی صحیح undefined_function(تهی);
بیرونی صحیح defined_function(تهی);

#ifdef __clang__
صحیح undefined_function(تهی) {}
#endif

ایستا درونخطی تهی refer_to_undefined(تهی)
{
  undefined_function();
}

تهی optimize_out_test(تهی)
{
  صحیح i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  صحیح j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  اگر (0)
    printf("oo:%d\n", undefined_function());
  وگرنه
    printf("oo:%d\n", defined_function());
  اگر (1)
    printf("oo:%d\n", defined_function());
  وگرنه
    printf("oo:%d\n", undefined_function());
  وقتی (1) {
      printf("oow:%d\n", defined_function());
      بشکن;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  انتخاب (j)
    حالت 1: بشکن;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  وقتی (1)
    بشکن;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  انجامبده
    بشکن;
  وقتی (1);
  printf ("ool2:%d\n", defined_function());
  برای (;;)
    بشکن;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  وقتی (1) {
	{
	  بشکن;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  وقتی (j) {
      اگر (j == 0)
	بشکن; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  وقتی (j) {
      اگر (1)
	j--;
      وگرنه
	breakhere: بشکن;
      printf("ool6:%d\n", defined_function());
      برو breakhere;
  }
  j = 1;
  وقتی (j) {
      j--;
      ادامه;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  اگر (0 && undefined_function())
    undefined_function();
  اگر (defined_function() && 0)
    undefined_function();
  اگر (0 && 0)
    undefined_function();
  اگر (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  اگر (1 || undefined_function())
    ;
  وگرنه
    undefined_function();
  اگر (defined_function() || 1)
    ;
  وگرنه
    undefined_function();
  اگر (1 || 1)
    ;
  وگرنه
    undefined_function();
  اگر (defined_function() || 1 || undefined_function())
    ;
  وگرنه
    undefined_function();

  اگر (defined_function() && 0)
    refer_to_undefined();

  اگر (0) {
      (تهی)اندازه( ({
		     انجامبده { } وقتی (0);
		     0;
		     }) );
      undefined_function();
  }

  اگر (0) {
      انتخاب (defined_function()) {
          حالت 0: undefined_function(); بشکن;
          پیشفرض: undefined_function(); بشکن;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  اگر (1)
    بازگشت;
  printf ("oor:%d\n", undefined_function());
}

صحیح defined_function(تهی)
{
  ایستا صحیح i = 40;
  بازگشت i++;
}

/* GCC accepts that */
ایستا صحیح tab_reinit[];
ایستا صحیح tab_reinit[10];

ایستا صحیح tentative_ar[];
ایستا صحیح tentative_ar[] = {1,2,3};

صحیح cinit1; /* a global variable can be defined several times without error ! */
صحیح cinit1; 
صحیح cinit1 = 0;
صحیح *cinit2 = (صحیح []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
نویسه ثابت * ثابت cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
تهی *cinit52 = &(تهی*){ (تهی*) 52 };

#اگر __TINYC__ || __GNUC__ >= 6
صحیح cinit4 = (صحیح){44};
تهی *cinit51 = (تهی*){ (تهی*) 51 };
ساختار _c6 { صحیح a,b; } cinit6 = (ساختار _c6){61,62}, *cinit7 = &(ساختار _c6){71,72};
#وگرنه
صحیح cinit4 = 44;
تهی *cinit51 = (تهی*)51;
ساختار _c6 { صحیح a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

تهی compound_literal_test(تهی)
{
    صحیح *p, i;
    نویسه *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (صحیح)cinit51);
    printf("cinit52 : %d\n", *(صحیح*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (صحیح []){1, 2, 3};
    برای(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    برای(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (نویسه *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (نویسه *){ q };
    printf("q3=%s\n", q3);

    q = (نویسه []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (صحیح []){1, 2, cinit1 + 3};
    برای(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    برای(i=0;i<3;i++) {
        p = (صحیح []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#اگر __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    بازگشت a + b;
}

صحیح kr_func2(a, b)
{
    بازگشت a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    بازگشت 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
نویسه invalid_function_def()[] {بازگشت 0;}

#وگرنه
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

تهی رقم(صحیح n)
{
    نویسه *tab, *p;
    tab = (نویسه*)malloc(20); 
    p = tab;
    وقتی (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        اگر (n == 0)
            بشکن;
    }
    وقتی (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    آزاد(tab);
}

/* structure assignment tests */
ساختار structa1 {
    صحیح f1;
    نویسه f2;
};

تهی struct_assign_test1(ساختار structa1 s1, صحیح t, اعشاری f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ساختار structa1 struct_assign_test2(ساختار structa1 s1, صحیح t)
{
    s1.f1 += t;
    s1.f2 -= t;
    بازگشت s1;
}

تهی struct_assign_test(تهی)
{
    ساختار S {
      ساختار structa1 lsta1, lsta2;
      صحیح i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ایستا ساختار {
        تهی (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

تهی cast1(نویسه a, short b, unsigned نویسه c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

نویسه bcast;
short scast;

تهی cast_test()
{
    صحیح a;
    نویسه c;
    نویسه tab[10];
    unsigned b,d;
    short s;
    نویسه *p = پوچ;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (نویسه)(a + 1),
           (short)(a + 1),
           (unsigned نویسه)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (نویسه)0xfffff,
           (short)0xfffff,
           (unsigned نویسه)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", اندازه(c), اندازه((صحیح)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (نویسه)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", اندازه(+(نویسه)'a'));
    printf("sizeof(-(char)'a') = %d\n", اندازه(-(نویسه)'a'));
    printf("sizeof(~(char)'a') = %d\n", اندازه(-(نویسه)'a'));

#اگر CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (صحیح)p, (unsigned صحیح)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (تهی *)a, (تهی *)b, (تهی *)c, (تهی *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(صحیح)ul);
}

/* initializers tests */
ساختار structinit1 {
    صحیح f1;
    نویسه f2;
    short f3;
    صحیح farray[3];
};

صحیح sinit1 = 2;
صحیح sinit2 = { 3 };
صحیح sinit3[3] = { 1, 2, {3}, };
صحیح sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
صحیح sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
صحیح sinit6[] = { 1, 2, 3 };
صحیح sinit7[] = { [2] = 3, [0] = 1, 2 };
نویسه sinit8[] = "hello" "trala";

ساختار structinit1 sinit9 = { 1, 2, 3 };
ساختار structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ساختار structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

نویسه *sinit12 = "hello world";
نویسه *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
نویسه sinit14[10] = { "abc" };
صحیح sinit15[3] = { اندازه(sinit15), 1, 2 };

ساختار { صحیح a[3], b; } sinit16[] = { { 1 }, 2 };

ساختار bar {
        نویسه *s;
        صحیح len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

صحیح sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ساختار complexinit0 {
    صحیح a;
    صحیح b;
};

ساختار complexinit {
    صحیح a;
    ثابت ساختار complexinit0 *b;
};

ثابت ایستا ساختار complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ثابت ساختار complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ساختار complexinit2 {
	صحیح a;
	صحیح b[];
};

ساختار complexinit2 cix20;

ساختار complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ساختار complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

تعریفنوع صحیح arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
تعریفنوع صحیح arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
صحیح sinit23[2] = { "astring" ? اندازه("astring") : -1,
		   &sinit23 ? 42 : -1 };

صحیح sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ساختار bf_SS {unsigned صحیح bit:1,bits31:31; };
ساختار bf_SS bf_init = { .bit = 1 };
ساختار bfn_SS {صحیح a,b; ساختار bf_SS c; صحیح d,e; };
ساختار bfn_SS bfn_init = { .c.bit = 1 };
ساختار bfa_SS {صحیح a,b; ساختار bf_SS c[3]; صحیح d,e; };
ساختار bfa_SS bfa_init = { .c[1].bit = 1 };
ساختار bf_SS bfaa_init[3] = { [1].bit = 1 };
ساختار bf_SS bfaa_vinit[] = { [2].bit = 1 };
ساختار b2_SS {long long صحیح field : 52; long long صحیح pad : 12; };
ساختار b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

بیرونی صحیح external_inited = 42;

تهی init_test(تهی)
{
    صحیح linit1 = 2;
    صحیح linit2 = { 3 };
    صحیح linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    صحیح linit6[] = { 1, 2, 3 };
    صحیح i, j;
    نویسه linit8[] = "hello" "trala";
    صحیح linit12[10] = { 1, 2 };
    صحیح linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    نویسه linit14[10] = "abc";
    صحیح linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ساختار linit16 { صحیح a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    صحیح linit17 = اندازه(linit17);
    صحیح zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    صحیح linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ساختار bf_SS bf_finit = { .bit = 1 };
    ساختار bfn_SS bfn_finit = { .c.bit = 1 };
    ساختار bfa_SS bfa_finit = { .c[1].bit = 1 };
    ساختار bf_SS bfaa_finit[3] = { [1].bit = 1 };
    ساختار bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    ساختار b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           اندازه(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", اندازه(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           اندازه(sinit7),
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

    برای(i=0;i<3;i++)
        برای(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", اندازه(linit6));
    printf("linit8=%d %s\n", اندازه(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           اندازه(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    برای(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    برای(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    برای(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    برای(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    برای(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", اندازه cix20, اندازه cix21, اندازه cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", اندازه(sinit19), اندازه(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", اندازه(sinit21), اندازه(sinit22));
    printf("arrtype6: %d\n", اندازه(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    برای (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

تهی switch_uc(unsigned نویسه uc)
{
	انتخاب (uc) {
	    حالت 0xfb ... 0xfe:
		printf("ucsw:1\n");
		بشکن;
	    حالت 0xff:
		printf("ucsw:2\n");
		بشکن;
	    حالت 0 ... 5:
		printf("ucsw:3\n");
		بشکن;
	    پیشفرض:
		printf("ucsw: broken!\n");
	}
}

تهی switch_sc(signed نویسه sc)
{
	انتخاب (sc) {
	    حالت -5 ... -2:
		printf("scsw:1\n");
		بشکن;
	    حالت -1:
		printf("scsw:2\n");
		بشکن;
	    حالت 0 ... 5:
		printf("scsw:3\n");
		بشکن;
	    پیشفرض:
		printf("scsw: broken!\n");
	}
}

تهی switch_test()
{
    صحیح i;
    unsigned long long ull;
    long long ll;

    برای(i=0;i<15;i++) {
        انتخاب(i) {
        حالت 0:
        حالت 1:
            printf("a");
            بشکن;
        پیشفرض:
            printf("%d", i);
            بشکن;
        حالت 8 ... 12:
            printf("c");
            بشکن;
        حالت 3:
            printf("b");
            بشکن;
        حالت 0xc33c6b9fU:
        حالت 0x7c9eeeb9U:
            بشکن;
        }
    }
    printf("\n");

    برای (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	انتخاب (ull) {
	    حالت 1ULL << 61:
		printf("ullsw:1\n");
		بشکن;
	    حالت 2ULL << 61:
		printf("ullsw:2\n");
		بشکن;
	    حالت 3ULL << 61:
		printf("ullsw:3\n");
		بشکن;
	    حالت 4ULL << 61:
		printf("ullsw:4\n");
		بشکن;
	    حالت 5ULL << 61:
		printf("ullsw:5\n");
		بشکن;
	    پیشفرض:
		printf("ullsw: broken!\n");
	}
    }

    برای (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	انتخاب (ll) {
	    حالت 1LL << 61:
		printf("llsw:1\n");
		بشکن;
	    حالت 2LL << 61:
		printf("llsw:2\n");
		بشکن;
	    حالت 3LL << 61:
		printf("llsw:3\n");
		بشکن;
	    حالت 4LL << 61:
		printf("llsw:4\n");
		بشکن;
	    حالت 5LL << 61:
		printf("llsw:5\n");
		بشکن;
	    پیشفرض:
		printf("llsw: broken!\n");
	}
    }

    برای (i = -5; i <= 5; i++) {
	switch_uc((unsigned نویسه)i);
    }

    برای (i = -5; i <= 5; i++) {
	switch_sc ((signed نویسه)i);
    }
}

/* ISOC99 _Bool type */
تهی c99_bool_test(تهی)
{
#ifdef BOOL_ISOC99
    صحیح a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", اندازه(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           اندازه ((فرار صحیح)a ? b : b2));
#endif
}

تهی bitfield_test(تهی)
{
    صحیح a;
    short sa;
    unsigned نویسه ca;
    ساختار sbf1 {
        صحیح f1 : 3;
        صحیح : 2;
        صحیح f2 : 1;
        صحیح : 0;
        صحیح f3 : 5;
        صحیح f4 : 7;
        unsigned صحیح f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", اندازه(st1));

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
    اگر (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    وگرنه 
        printf("st1.f1 != -1\n");
    اگر (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    وگرنه 
        printf("st1.f2 != -1\n");

    ساختار sbf2 {
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

#اگر 0
    Disabled برای now until further clarification re GCC compatibility
    ساختار sbf3 {
        صحیح f1 : 7;
        صحیح f2 : 1;
        نویسه f3;
        صحیح f4 : 8;
        صحیح f5 : 1;
        صحیح f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", اندازه(st3));
#endif

    ساختار sbf4 {
	صحیح x : 31;
	نویسه y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    ساختار sbf5 {
	صحیح a;
	نویسه b;
	صحیح x : 12, y : 4, : 0, : 4, z : 3;
	نویسه c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ساختار sbf6 {
	short x : 12;
	unsigned نویسه y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#وگرنه
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
دوگانه strtod(ثابت نویسه *nptr, نویسه **endptr);

#اگر defined(_WIN32)
اعشاری strtof(ثابت نویسه *nptr, نویسه **endptr) {بازگشت (اعشاری)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ثابت نویسه *nptr, نویسه **endptr) {بازگشت (LONG_DOUBLE)strtod(nptr, endptr);}
#وگرنه
اعشاری strtof(ثابت نویسه *nptr, نویسه **endptr);
LONG_DOUBLE strtold(ثابت نویسه *nptr, نویسه **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
تهی prefix ## cmp(type a, type b)\
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
تهی prefix ## fcast(type a)\
{\
    اعشاری fa;\
    دوگانه da;\
    LONG_DOUBLE la;\
    صحیح ia;\
    long long llia;\
    unsigned صحیح ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (صحیح)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned صحیح)a;\
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
    اگر (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
اعشاری prefix ## retf(type a) { بازگشت a; }\
دوگانه prefix ## retd(type a) { بازگشت a; }\
LONG_DOUBLE prefix ## retld(type a) { بازگشت a; }\
\
تهی prefix ## call(تهی)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (دوگانه)strto ## prefix("1.2", پوچ));\
}\
\
تهی prefix ## signed_zeros(تهی) \
{\
  type x = 0.0, y = -0.0, n, p;\
  اگر (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  وگرنه\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  اگر (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  وگرنه\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  اگر (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  وگرنه\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  اگر (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  وگرنه\
    printf ("x != -y; this is wrong!\n");\
}\
تهی prefix ## nan(تهی)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
تهی prefix ## test(تهی)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    اگر (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, اعشاری, اعشاری, "%f")
FTEST(d, دوگانه, دوگانه, "%f")
FTEST(ld, long دوگانه, LONG_DOUBLE, "%Lf")

دوگانه ftab1[3] = { 1.2, 3.4, -5.6 };


تهی float_test(تهی)
{
#اگر !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    فرار اعشاری fa, fb;
    فرار دوگانه da, db;
    صحیح a;
    unsigned صحیح b;
    ایستا دوگانه nan2 = 0.0/0.0;
    ایستا دوگانه inf1 = 1.0/0.0;
    ایستا دوگانه inf2 = 1e5000;
    فرار LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", اندازه(اعشاری));
    printf("sizeof(double) = %d\n", اندازه(دوگانه));
    printf("sizeof(long double) = %d\n", اندازه(LONG_DOUBLE));
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

صحیح fib(صحیح n)
{
    اگر (n <= 2)
        بازگشت 1;
    وگرنه
        بازگشت fib(n-1) + fib(n-2);
}

#اگر __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#وگرنه
تهی __attribute__((aligned(16))) aligned_function(صحیح i) {}
#endif

تهی funcptr_test()
{
    تهی (*func)(صحیح);
    صحیح a;
    ساختار {
        صحیح dummy;
        تهی (*func)(صحیح);
    } st1;
    long diff;

    func = &رقم;
    (*func)(12345);
    func = رقم;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = رقم;
    st1.func(12346);
    printf("sizeof1 = %d\n", اندازه(funcptr_test));
    printf("sizeof2 = %d\n", اندازه funcptr_test);
    printf("sizeof3 = %d\n", اندازه(&funcptr_test));
    printf("sizeof4 = %d\n", اندازه &funcptr_test);
    a = 0;
    func = رقم + a;
    diff = func - رقم;
    func(42);
    (func + diff)(42);
    (رقم + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((صحیح)(uintptr_t)func) & 15);
}

تهی lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    اگر (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*دودویی*/
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

تهی llshift(long long a, صحیح b)
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

تهی llfloat(تهی)
{
    اعشاری fa;
    دوگانه da;
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

long long llfunc1(صحیح a)
{
    بازگشت a * 2;
}

ساختار S {
    صحیح id; 
    نویسه item;
};

long long صحیح مقدار(ساختار S *v)
{
    بازگشت ((long long صحیح)v->item);
}

long long llfunc2(long long x, long long y, صحیح z)
{
    بازگشت x * y * z;
}

تهی check_opl_save_regs(نویسه *a, long long b, صحیح c)
{
    *a = b < 0 && !c;
}

تهی longlong_test(تهی)
{
    long long a, b, c;
    صحیح ia;
    unsigned صحیح ua;
    printf("sizeof(long long) = %d\n", اندازه(long long));
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
#اگر 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          ساختار S a;

          a.item = 3;
          printf("%lld\n", مقدار(&a));
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
    u = (unsigned)(صحیح)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    نویسه cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

تهی manyarg_test(تهی)
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

تهی*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ساختار X { صحیح _x; };
        ساختار X *x = va_arg(ap, ساختار X *);
        بازگشت x;
}

تهی vprintf1(ثابت نویسه *fmt, ...)
{
    va_list ap, aq;
    ثابت نویسه *p;
    صحیح c, i;
    دوگانه d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    برای(;;) {
        c = *p;
        اگر (c == '\0')
            بشکن;
        p++;
        اگر (c == '%') {
            c = *p;
            انتخاب(c) {
            حالت '\0':
                برو the_end;
            حالت 'd':
                i = va_arg(ap, صحیح);
                printf("%d", i);
                بشکن;
            حالت 'f':
                d = va_arg(ap, دوگانه);
                printf("%f", d);
                بشکن;
            حالت 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                بشکن;
            حالت 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                بشکن;
            }
            p++;
        } وگرنه {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

ساختار myspace {
    short صحیح profile;
};
ساختار myspace2 {
#اگر CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    نویسه a[1];
#وگرنه
    نویسه a[0];
#endif
};
ساختار myspace3 {
    نویسه a[1];
};
ساختار myspace4 {
    نویسه a[2];
};
ساختار mytest {
    تهی *foo, *bar, *baz;
};

ساختار mytest stdarg_for_struct(ساختار myspace bob, ...)
{
    ساختار myspace george, bill;
    ساختار myspace2 alex1;
    ساختار myspace3 alex2;
    ساختار myspace4 alex3;
    va_list ap;
    short صحیح validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ساختار myspace2);
    alex2    = va_arg(ap, ساختار myspace3);
    alex3    = va_arg(ap, ساختار myspace4);
    bill     = va_arg(ap, ساختار myspace);
    george   = va_arg(ap, ساختار myspace);
    validate = va_arg(ap, صحیح);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    بازگشت (ساختار mytest) {};
}

تهی stdarg_for_libc(ثابت نویسه *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

تهی stdarg_syntax(صحیح n, ...)
{
    صحیح i;
    va_list ap;
    اگر (1)
      va_start(ap, n);
    وگرنه
      ;
    i = va_arg(ap, صحیح);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

تعریفنوع ساختار{
    دوگانه x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ایستا تهی stdarg_double_struct(صحیح nargs, صحیح posd,...)
{
    صحیح i;
    دوگانه d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    برای(i = 0; i < nargs; i++) {
        اگر (i == posd) {
            d = va_arg (args, دوگانه);
            printf ("d %d = %g\n", i, d);
        }
        وگرنه {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

تهی stdarg_test(تهی)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ساختار myspace bob;
    ساختار myspace2 bob2;
    ساختار myspace3 bob3;
    ساختار myspace4 bob4;

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
#اگر !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

صحیح reltab[3] = { 1, 2, 3 };

صحیح *rel1 = &reltab[1];
صحیح *rel2 = &reltab[2];

تهی getmyaddress(تهی)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(تهی)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       بازگشت ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
تهی relocation_test(تهی)
{
    تهی (*fptr)(تهی) = (تهی (*)(تهی))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

تهی old_style_f(a,b,c)
     صحیح a, b;
     دوگانه c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

تهی decl_func1(صحیح cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

تهی decl_func2(cmpfn)
صحیح cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

تهی old_style_function_test(تهی)
{
#اگر CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#وگرنه
    old_style_f((تهی *)1, 2, 3.0);
#endif
    decl_func1(پوچ);
    decl_func2(پوچ);
}

تهی alloca_test()
{
    نویسه *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    نویسه *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

تهی *bounds_checking_is_enabled()
{
    نویسه ca[10], *cp = ca-1;
    بازگشت (ca != cp + 1) ? cp : پوچ;
}

تعریفنوع صحیح constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

تهی c99_vla_test_1(صحیح size1, صحیح size2)
{
    صحیح size = size1 * size2;
    صحیح tab1[size][2], tab2[10][2];
    تهی *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (اندازه tab1 == size1 * size2 * 2 * اندازه(صحیح)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (اندازه(صحیح) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * اندازه(صحیح)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((صحیح *) (tab1_ptr + (size1 * 2 + 1) * اندازه(صحیح))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    اگر (bad_ptr = bounds_checking_is_enabled()) {
        صحیح *t1 = &tab1[size1 * size2 - 1][3];
        صحیح *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        نویسه*c1 = 1 + اندازه(tab1) + (نویسه*)tab1;
        نویسه*c2 = 1 + اندازه(tab2) + (نویسه*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        صحیح *i1 = tab1[-1];
        صحیح *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        صحیح *x1 = tab1[size1 * size2 + 1];
        صحیح *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } وگرنه {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

تهی c99_vla_test_2(صحیح d, صحیح h, صحیح w)
{
    صحیح x, y, z;
    صحیح (*arr)[h][w] = malloc(اندازه(صحیح) * d*h*w);
    صحیح c = 1;
    ایستا صحیح (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    برای (z=0; z<d; z++) {
        برای (y=0; y<h; y++) {
            برای (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    برای (z=0; z<d; z++) {
        برای (y=0; y<h; y++) {
            برای (x=0; x<w; x++) {
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
        اندازه (*arr), اندازه (*arr)[0], اندازه (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == اندازه (*arr + 1) - اندازه arr,
        0 == اندازه اندازه *arr - اندازه arr,
        starr[0][2][3] == arr[1][2][3]
        );
    آزاد (arr);
}

تهی c99_vla_test_3a (صحیح arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

تهی c99_vla_test_3b(صحیح s, صحیح arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

تهی c99_vla_test_3c(صحیح s, صحیح arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

تهی c99_vla_test_3d(صحیح s, صحیح arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

تهی c99_vla_test_3e(صحیح s, صحیح arr[][3][--s])
{
    printf ("%d %d %d\n", اندازه arr, s, arr[1][2][3]);
}

تهی c99_vla_test_3(تهی)
{
    صحیح a[2][3][4];

    memset (a, 0, اندازه(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

تهی c99_vla_test(تهی)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


تهی sizeof_test(تهی)
{
    صحیح a;
    صحیح **ptr;

    printf("sizeof(int) = %d\n", اندازه(صحیح));
    printf("sizeof(unsigned int) = %d\n", اندازه(unsigned صحیح));
    printf("sizeof(long) = %d\n", اندازه(long));
    printf("sizeof(unsigned long) = %d\n", اندازه(unsigned long));
    printf("sizeof(short) = %d\n", اندازه(short));
    printf("sizeof(unsigned short) = %d\n", اندازه(unsigned short));
    printf("sizeof(char) = %d\n", اندازه(نویسه));
    printf("sizeof(unsigned char) = %d\n", اندازه(unsigned نویسه));
    printf("sizeof(func) = %d\n", اندازه sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", اندازه a++);
    printf("a=%d\n", a);
    ptr = پوچ;
    printf("sizeof(**ptr) = %d\n", اندازه (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", اندازه(اندازه(صحیح)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -اندازه(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(صحیح));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned صحیح));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(نویسه));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned نویسه));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", اندازه(نویسه[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   اندازه( (ساختار {صحیح i; صحیح j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   اندازه (ساختار {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", اندازه(t && 0));
    printf("sizeof(1 && 1) = %d\n", اندازه(1 && 1));
    printf("sizeof(t || 1) = %d\n", اندازه(t || 1));
    printf("sizeof(0 || 0) = %d\n", اندازه(0 || 0));

    صحیح arr[4], fn();
    printf("sizeof(0, arr) = %d\n", اندازه(0, arr));
    printf("sizeof(0, fn) = %d\n", اندازه(0, fn));
}

تهی typeof_test(تهی)
{
    دوگانه a;
    typeof(a) b;
    typeof(اعشاری) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


ساختار hlist_گره;
ساختار hlist_head {
    ساختار hlist_گره *first, *last;
};

تهی consume_ulong (unsigned long i)
{
    i = 0;
}

تهی statement_عبارت_test(تهی)
{
    صحیح a, i;

    /* Basic stmt expr test */
    a = 0;
    برای(i=0;i<10;i++) {
        a += 1 + 
            ( { صحیح b, j; 
                b = 0; 
                برای(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    تهی *v = (تهی*)39;
    typeof(({
	    (ساختار hlist_گره *)v;
	    })) x;
    typeof (x)
	ptr = (ساختار hlist_گره *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            ایستا ثابت نویسه *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    صحیح t = 40;
    صحیح b = ({ صحیح t = 41; t; });
    صحیح c = ({ صحیح t = 42; t; });

    /* Test that aggregate return values work.  */
    ساختار hlist_head h
	= ({
	   تعریفنوع ساختار hlist_head T;
	   long pre = 48;
	   T t = { (تهی*)43, (تهی*)44 };
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
       LBL: اگر (i++ == 0) برو LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      برو LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

تهی local_label_test(تهی)
{
    صحیح a;
    برو l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        برو l1;
    l4:
        printf("aa1\n");
        برو l3;
    l2:
        printf("aa3\n");
        برو l4;
    l1:
        printf("aa2\n");
        برو l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    بازگشت;
 l4:
    printf("bb1\n");
    برو l2;
 l1:
    printf("bb2\n");
    برو l4;
}

/* inline assembler test */
#اگر (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

تعریفنوع __SIZE_TYPE__ word;

/* from linux kernel */
ایستا نویسه * strncat1(نویسه * dest,ثابت نویسه * src,size_t شمار_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (شمار_2)
	: "memory");
بازگشت dest;
}

ایستا نویسه * strncat2(نویسه * dest,ثابت نویسه * src,size_t شمار_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (شمار_2)
	: "memory");
بازگشت dest;
}

ایستا درونخطی تهی * memcpy1(تهی * to, ثابت تهی * from, size_t n)
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
بازگشت (to);
}

ایستا درونخطی تهی * memcpy2(تهی * to, ثابت تهی * from, size_t n)
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
بازگشت (to);
}

ایستا __inline__ تهی sigaddset1(unsigned صحیح *set, صحیح _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

ایستا __inline__ تهی sigdelset1(unsigned صحیح *set, صحیح _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ایستا __inline__ __const__ unsigned صحیح swab32(unsigned صحیح x)
{
        بازگشت ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#وگرنه
ایستا __inline__ __const__ unsigned صحیح swab32(unsigned صحیح x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	بازگشت x;
}
#endif

ایستا __inline__ unsigned long long mul64(unsigned صحیح a, unsigned صحیح b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned صحیح resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#وگرنه
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    بازگشت res;
}

ایستا __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#وگرنه
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    بازگشت res;
}

ساختار struct123 {
    صحیح a;
    صحیح b;
};
ساختار struct1231 {
    word addr;
};

word mconstraint_test(ساختار struct1231 *r)
{
    word ret;
    unsigned صحیح a[2];
    a[0] = 0;
    __asm__ فرار ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ساختار struct123 *)r->addr));
    بازگشت ret + a[0];
}

#ifdef __x86_64__
صحیح fls64(unsigned long long x)
{
  صحیح bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  بازگشت bitpos + 1;
}
#endif

تهی other_constraints_test(تهی)
{
    word ret;
    صحیح var;
#اگر CC_NAME != CC_clang
    __asm__ فرار ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
تهی base_func(تهی)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
بیرونی تهی override_func1 (تهی);
بیرونی تهی override_func2 (تهی);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

تهی override_func2 (تهی)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
بیرونی صحیح bug_table[] __attribute__((section("__bug_table")));
نویسه * get_asm_string (تهی)
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
  بیرونی صحیح some_نماد;
  asm فرار (".globl some_symbol\n"
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
  نویسه * str = ((نویسه*)bug_table) + bug_table[1];
  بازگشت str;
#وگرنه
  بازگشت (نویسه *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
بیرونی unsigned نویسه alld_stuff[];
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

تهی asm_local_label_diff (تهی)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
تهی asm_local_statics (تهی)
{
  ایستا صحیح localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

ایستا
unsigned صحیح set;

تهی fancy_copy (unsigned *in, unsigned *out)
{
  asm فرار ("" : "=r" (*out) : "0" (*in));
}

تهی fancy_copy2 (unsigned *in, unsigned *out)
{
  asm فرار ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#اگر defined __x86_64__
تهی clobber_r12(تهی)
{
    asm فرار("mov $1, %%r12" ::: "r12");
}
#endif

تهی test_بالا_clobbers_really(تهی)
{
#اگر defined __x86_64__
    ثبات word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm فرار("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm فرار("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

تهی test_بالا_clobbers(تهی)
{
#اگر defined __x86_64__
    word x1, x2;
    asm فرار("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_بالا_clobbers_really();
    asm فرار("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm فرار("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

ایستا long cpu_عدد;
تهی trace_console(long len, long len2)
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
    اگر (0
        &&
            ({
              long pscr_ret__;
              انتخاب(len) {
                حالت 4:
                    {
                       long pfo_ret__;
                       انتخاب (len2) {
                         حالت 8:	printf("bla"); pfo_ret__ = 42; بشکن;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  بشکن;
                حالت 8:
                    {
                       long pfo_ret__;
                       انتخاب (len2) {
                         حالت 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_عدد));	بشکن;
                         حالت 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_عدد));	بشکن;
                         حالت 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_عدد));	بشکن;
                         حالت 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_عدد));	بشکن;
                         پیشفرض: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  بشکن;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

تهی test_asm_dead_code(تهی)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm فرار ("" : "=D" (rdi) : "0" (0));
  (تهی)اندازه (({
      صحیح var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm فرار ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

تهی test_asm_call(تهی)
{
#اگر defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ایستا نویسه str[] = "PATH";
  نویسه *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm فرار ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#اگر 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#وگرنه
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#اگر defined __x86_64__
# define RX "(%rip)"
#وگرنه
# define RX
#endif

تهی asm_dot_test(تهی)
{
#ifndef __APPLE__
    صحیح x;
    برای (x = 1;; ++x) {
        صحیح r = x;
        انتخاب (x) {
        حالت 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        حالت 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#وگرنه
            asm(".text; mov $123, %eax; jmp p0");
#endif
	حالت 3:
#اگر !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#وگرنه
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        حالت 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#وگرنه
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#وگرنه
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        حالت 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); بشکن;
	}
        اگر (r == x)
            بشکن;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

تهی asm_pcrel_test(تهی)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

تهی asm_test(تهی)
{
    نویسه buf[128];
    unsigned صحیح val, val2;
    ساختار struct123 s1;
    ساختار struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    صحیح base_func = 42;
    تهی override_func3 (تهی);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    ثبات صحیح regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm فرار ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm فرار ("xorl %eax, %eax");

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
    برو label1;
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
    asm فرار(".weak override_func3\n.set override_func3, base_func");
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
    asm فرار("" : "=r" (asmret) : "0"(s2));
    اگر (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm فرار("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    اگر (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm فرار ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_بالا_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    بازگشت;
 label1:
    برو label2;
}

#وگرنه

تهی asm_test(تهی)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

صحیح constant_p_var;

صحیح func(تهی);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ایستا تهی builtin_test_bits(unsigned long long x, صحیح cnt[])
{
#اگر GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    اگر ((unsigned صحیح) x) cnt[3] += __builtin_clz(x);
    اگر ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    اگر ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    اگر ((unsigned صحیح) x) cnt[6] += __builtin_ctz(x);
    اگر ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    اگر ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#اگر GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

تهی builtin_test(تهی)
{
    short s;
    صحیح i;
    long long ll;
#اگر GCC_MAJOR >= 3
    COMPAT_TYPE(صحیح, صحیح);
    COMPAT_TYPE(صحیح, unsigned صحیح);
    COMPAT_TYPE(صحیح, نویسه);
    COMPAT_TYPE(صحیح, ثابت صحیح);
    COMPAT_TYPE(صحیح, فرار صحیح);
    COMPAT_TYPE(صحیح[2], ثابت صحیح[2]);
    COMPAT_TYPE(صحیح[2][3], فرار صحیح[][3]);
    COMPAT_TYPE(صحیح (*)[], ثابت صحیح (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحیح (*)[2])0 : (صحیح (*)[2])0),
                ثابت صحیح (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحیح (*)[2][3])0 :
                              (فرار صحیح (*)[2][3])0),
                ثابت فرار صحیح (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (فرار صحیح (*)[2][3])0 :
                              (ثابت صحیح (*)[2][3])0),
                ثابت فرار صحیح (*)[2][3]);
#وگرنه
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(صحیح *, صحیح *);
    COMPAT_TYPE(صحیح *, تهی *);
    COMPAT_TYPE(صحیح *, ثابت صحیح *);
    COMPAT_TYPE(نویسه *, unsigned نویسه *);
    COMPAT_TYPE(نویسه *, signed نویسه *);
    COMPAT_TYPE(نویسه *, نویسه *);
    COMPAT_TYPE(نویسه **, تهی *);
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
#وگرنه
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
    i = اندازه (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = اندازه (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	صحیح cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, اندازه(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        برای (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        برای (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	برای (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#اگر defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
تهی weak_test(تهی) {}
#وگرنه
بیرونی صحیح __attribute__((weak)) weak_f1(تهی);
بیرونی صحیح __attribute__((weak)) weak_f2(تهی);
بیرونی صحیح                       weak_f3(تهی);
بیرونی صحیح __attribute__((weak)) weak_v1;
بیرونی صحیح __attribute__((weak)) weak_v2;
بیرونی صحیح                       weak_v3;

بیرونی صحیح                           (*weak_fpa)() __attribute__((weak));
بیرونی صحیح __attribute__((weak))     (*weak_fpb)();
بیرونی     __attribute__((weak)) صحیح (*weak_fpc)();

بیرونی صحیح                     weak_asm_f1(تهی) asm("weak_asm_f1x") __attribute((weak));
بیرونی صحیح __attribute((weak)) weak_asm_f2(تهی) asm("weak_asm_f2x")                    ;
بیرونی صحیح __attribute((weak)) weak_asm_f3(تهی) asm("weak_asm_f3x") __attribute((weak));
بیرونی صحیح                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
بیرونی صحیح __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
بیرونی صحیح __attribute((weak)) weak_asm_v3(تهی) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
ایستا ثابت size_t dummy = 0;
بیرونی __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
بیرونی __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
بیرونی __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

صحیح some_lib_func(تهی);
صحیح dummy_impl_of_slf(تهی) { بازگشت 444; }
#ifndef __clang__
صحیح some_lib_func(تهی) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

صحیح weak_toolate() __attribute__((weak));
صحیح weak_toolate() { بازگشت 0; }

تهی __attribute__((weak)) weak_test(تهی)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != پوچ);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != پوچ);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != پوچ);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != پوچ);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != پوچ);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != پوچ);
#ifdef __clang__
	printf("some_lib_func=444\n");
#وگرنه
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

صحیح __attribute__((weak)) weak_f2() { بازگشت 222; }
صحیح __attribute__((weak)) weak_f3() { بازگشت 333; }
صحیح __attribute__((weak)) weak_v2 = 222;
صحیح __attribute__((weak)) weak_v3 = 333;
#endif

تهی const_func(ثابت صحیح a)
{
}

تهی const_warn_test(تهی)
{
    const_func(1);
}

ساختار condstruct {
  صحیح i;
};

صحیح getme (ساختار condstruct *s, صحیح i)
{
  صحیح i1 = (i == 0 ? 0 : s)->i;
  صحیح i2 = (i == 0 ? s : 0)->i;
  صحیح i3 = (i == 0 ? (تهی*)0 : s)->i;
  صحیح i4 = (i == 0 ? s : (تهی*)0)->i;
  بازگشت i1 + i2 + i3 + i4;
}

ساختار global_data
{
  صحیح a[40];
  صحیح *b[40];
};

ساختار global_data global_data;

صحیح global_data_getstuff (صحیح *, صحیح);

تهی global_data_callit (صحیح i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

صحیح global_data_getstuff (صحیح *p, صحیح i)
{
  بازگشت *p + i;
}

تهی global_data_test (تهی)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

ساختار cmpcmpS
{
  unsigned نویسه fill : 3;
  unsigned نویسه b1 : 1;
  unsigned نویسه b2 : 1;
  unsigned نویسه fill2 : 3;
};

صحیح glob1, glob2, glob3;

تهی compare_comparisons (ساختار cmpcmpS *s)
{
  اگر (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

تهی cmp_comparison_test(تهی)
{
  ساختار cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

صحیح fcompare (دوگانه a, دوگانه b, صحیح code)
{
  انتخاب (code) {
    حالت 0: بازگشت a == b;
    حالت 1: بازگشت a != b;
    حالت 2: بازگشت a < b;
    حالت 3: بازگشت a >= b;
    حالت 4: بازگشت a > b;
    حالت 5: بازگشت a <= b;
  }
  بازگشت 0;
}

تهی math_cmp_test(تهی)
{
  دوگانه nan = 0.0/0.0;
  دوگانه one = 1.0;
  دوگانه two = 2.0;
  صحیح comp = 0;
  صحیح v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  اگر (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  اگر (a op b) \
    bug (a,b,op,iop,2); \
  اگر (a iop b) \
    ; \
  وگرنه \
    bug (a,b,op,iop,3); \
  اگر ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  اگر ((a iop b) || comp) \
    ; \
  وگرنه \
    bug (a,b,op,iop,5); \
  اگر (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  اگر (!fcompare (nan, nan, 1))
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

دوگانه get100 () { بازگشت 100.0; }

تهی callsave_test(تهی)
{
  صحیح i, s; دوگانه *d; دوگانه t;
  s = اندازه (دوگانه);
  printf ("callsavetest: %d\n", s);
  d = alloca (اندازه(دوگانه));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


تهی bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (نویسه *)__builtin_frame_address(3) + str_offset);
}
تهی bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (نویسه *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
تهی bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (نویسه *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

تهی builtin_frame_address_test(تهی)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    نویسه str[] = "__builtin_frame_address";
    نویسه *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

نویسه via_volatile (نویسه i)
{
  نویسه فرار vi;
  vi = i;
  بازگشت vi;
}

تهی volatile_test(تهی)
{
    اگر (via_volatile (42) != 42)
      printf (" broken\n");
    وگرنه
      printf (" ok\n");
}

ساختار __attribute__((__packed__)) Spacked {
    نویسه a;
    short b;
    صحیح c;
};
ساختار Spacked spacked;
تعریفنوع ساختار __attribute__((__packed__)) {
    نویسه a;
    short b;
    صحیح c;
} Spacked2;
Spacked2 spacked2;
تعریفنوع ساختار Spacked3_s {
    نویسه a;
    short b;
    صحیح c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ساختار gate_struct64 {
    unsigned short offset_کم;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_میانه;
    unsigned offset_بالا;
    unsigned zero1;
} __attribute__((packed));
تعریفنوع ساختار gate_struct64 gate_desc;
gate_desc a_gate_desc;
تهی attrib_test(تهی)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", اندازه(ساختار Spacked),
	 اندازه(spacked), اندازه(Spacked2), اندازه(spacked2));
  printf("attr: %d %d\n", اندازه(Spacked3), اندازه(spacked3));
  printf("attr: %d %d\n", اندازه(gate_desc), اندازه(a_gate_desc));
#endif
}
بیرونی __attribute__((__unused__)) نویسه * __attribute__((__unused__)) *
strange_attrib_placement (تهی);

تهی * __attribute__((__unused__)) get_void_ptr (تهی *a)
{
  بازگشت a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ایستا درونخطی
صحیح __get_order(unsigned long long size)
{
  صحیح order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ساختار S { صحیح i : 1; } s; // constructed for this '1'
    }
  order = size;
  بازگشت order;
}

/* This just forces the above inline function to be actually emitted.  */
صحیح force_get_order(unsigned long s)
{
    بازگشت __get_order(s);
}

#define pv(m) printf(اندازه (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
تهی bounds_check1_test (تهی)
{
    ساختار s {
        صحیح x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
تهی map_add(صحیح a, صحیح b, صحیح c, صحیح d, صحیح e, صحیح f, صحیح g, صحیح h, صحیح i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

تهی func_arg_test(تهی)
{
    صحیح a = 0;
    صحیح b = 1;
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
تهی whitespace_test(تهی)
{
    نویسه *str;
    صحیح tcc_test = 1;

#اگر 1
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
#وگرنه
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#اگر 0
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
#اگر 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

صحیح اصلی(صحیح argc, نویسه **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(عبارت_test);
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
    RUN(عبارت_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_عبارت_test);
    RUN(عبارت_cmp_test);
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
    RUN(statement_عبارت_test);
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

    بازگشت 0;
}
