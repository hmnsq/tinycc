/*
 * TCC auto test program
 */
#ضمن "config.h"

/* identify the configured reference compiler in use */
#تعریف_کړه CC_gcc 1
#تعریف_کړه CC_clang 2
#تعریف_کړه CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#تعریف_کړه ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#تعریف_کړه BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#تعریف_کړه C99_MACROS

#إذا defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#تعریف_کړه LONG_LONG_FORMAT "%lld"
#تعریف_کړه ULONG_LONG_FORMAT "%llu"
#تعریف_کړه XLONG_LONG_FORMAT "%llx"
#وإلا
#تعریف_کړه LONG_LONG_FORMAT "%Ld"
#تعریف_کړه ULONG_LONG_FORMAT "%Lu"
#تعریف_کړه XLONG_LONG_FORMAT "%Lx"
#د_که_پای

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#إذا defined(_WIN32)
#تعریف_کړه LONG_DOUBLE مزدوج
#تعریف_کړه LONG_DOUBLE_LITERAL(x) x
#وإلا
#تعریف_کړه LONG_DOUBLE اوږد مزدوج
#تعریف_کړه LONG_DOUBLE_LITERAL(x) x ## L
#د_که_پای

تعريفنوع __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#تعریف_کړه TCCLIB_INC <tcclib.h>
#تعریف_کړه TCCLIB_INC1 <tcclib
#تعریف_کړه TCCLIB_INC2 h>
#تعریف_کړه TCCLIB_INC3 "tcclib.h"

#ضمن TCCLIB_INC

#ضمن TCCLIB_INC1.TCCLIB_INC2

#ضمن TCCLIB_INC1.h>

#ضمن TCCLIB_INC3

#ضمن <tcclib.h>

#ضمن "tcclib.h"

#ضمن "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#تعریف_کړه INC(name) <tests/name.h>
#تعریف_کړه funnyname 42test.h
#تعریف_کړه incdir tests/
#که_تعریف_شوی __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#تعریف_کړه incname <tests/42test.h>
#وإلا
#تعریف_کړه incname < incdir funnyname >
#د_که_پای
#تعریف_کړه __stringify(x) #x
#تعریف_کړه stringify(x) __stringify(x)
#ضمن INC(42test)
#ضمن incname
#ضمن stringify(funnyname)

صحيح fib(صحيح n);
فراغ عدد(صحيح n);
فراغ forward_ref(فراغ);
صحيح isid(صحيح c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
فراغ funny_کرښه_continuation (صحيح, ..\
. );

#تعریف_کړه A 2
#تعریف_کړه N 1234 + A
#تعریف_کړه pf چاپ_کړه
#تعریف_کړه M1(a, b)  (a) + (b)

#تعریف_کړه str\
(s) # s
#تعریف_کړه glue(a, b) a ## b
#تعریف_کړه xglue(a, b) glue(a, b)
#تعریف_کړه HIGHLOW "hello"
#تعریف_کړه ټیټ_2 ټیټ_2 ", world"

ساكن صحيح onetwothree = 123;
#تعریف_کړه onetwothree4 onetwothree
#تعریف_کړه onetwothree xglue(onetwothree,4)

#تعریف_کړه min(a, b) ((a) < (b) ? (a) : (b))

#که_تعریف_شوی C99_MACROS
#تعریف_کړه dprintf(level,...) چاپ_کړه(__VA_ARGS__)
#د_که_پای

/* gcc vararg macros */
#تعریف_کړه dprintf1(level, fmt, دلیلونه...) چاپ_کړه(fmt, ## دلیلونه)

#تعریف_کړه MACRO_NOARGS()

#تعریف_کړه TEST_CALL(f, ...) f(__VA_ARGS__)
#تعریف_کړه TEST_CONST()      123

#تعریف_کړه AAA 3
#تعریف_لغوه AAA
#تعریف_کړه AAA 4

#إذا 1
#تعریف_کړه B3 1
#وإلاإذا 1
#تعریف_کړه B3 2
#وإلاإذا 0
#تعریف_کړه B3 3
#وإلا
#تعریف_کړه B3 4
#د_که_پای

#تعریف_کړه __INT64_C(c)	c ## LL
#تعریف_کړه INT64_MIN	(-__INT64_C(9223372036854775807)-1)

صحيح qq(صحيح x)
{
    أرجع x + 40;
}
#تعریف_کړه qq(x) x

#تعریف_کړه spin_قلف(قلف) افعل { } طالما (0)
#تعریف_کړه wq_spin_قلف spin_قلف
#تعریف_کړه TEST2() wq_spin_قلف(a)

فراغ macro_test(فراغ)
{
    pf("N=%d\n", N);
    چاپ_کړه("aaa=%d\n", AAA);

    چاپ_کړه("min=%d\n", min(1, min(2, -1)));

    چاپ_کړه("s1=%s\n", glue(لوړ_2, ټیټ_2));
    چاپ_کړه("s2=%s\n", xglue(لوړ_2, ټیټ_2));
    چاپ_کړه("s3=%s\n", str("c"));
    چاپ_کړه("s4=%s\n", str(a1));
    چاپ_کړه("B3=%d\n", B3);

    چاپ_کړه("onetwothree=%d\n", onetwothree);

#که_تعریف_شوی A
    چاپ_کړه("A defined\n");
#د_که_پای
#که_تعریف_شوی B
    چاپ_کړه("B defined\n");
#د_که_پای
#که_تعریف_شوی A
    چاپ_کړه("A defined\n");
#وإلا
    چاپ_کړه("A not defined\n");
#د_که_پای
#که_تعریف_شوی B
    چاپ_کړه("B defined\n");
#وإلا
    چاپ_کړه("B not defined\n");
#د_که_پای

#که_تعریف_شوی A
    چاپ_کړه("A defined\n");
#که_تعریف_شوی B
    چاپ_کړه("B1 defined\n");
#وإلا
    چاپ_کړه("B1 not defined\n");
#د_که_پای
#وإلا
    چاپ_کړه("A not defined\n");
#که_تعریف_شوی B
    چاپ_کړه("B2 defined\n");
#وإلا
    چاپ_کړه("B2 not defined\n");
#د_که_پای
#د_که_پای

#إذا 1+1
    چاپ_کړه("test true1\n");
#د_که_پای
#إذا 0
    چاپ_کړه("test true2\n");
#د_که_پای
#إذا 1-1
    چاپ_کړه("test true3\n");
#د_که_پای
#إذا defined(A)
    چاپ_کړه("test trueA\n");
#د_که_پای
#إذا defined(B)
    چاپ_کړه("test trueB\n");
#د_که_پای

#إذا 0
    چاپ_کړه("test 0\n");
#وإلاإذا 0
    چاپ_کړه("test 1\n");
#وإلاإذا 2
    چاپ_کړه("test 2\n");
#وإلا
    چاپ_کړه("test 3\n");
#د_که_پای

    MACRO_NOARGS();

    چاپ_کړه("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#که_تعریف_شوی C99_MACROS
    چاپ_کړه("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#د_که_پای
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    چاپ_کړه("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    چاپ_کړه("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        صحيح a;
        a = 1;
        glue(a+, +);
        چاپ_کړه("a=%d\n", a);
        glue(a <, <= 2);
        چاپ_کړه("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#تعریف_کړه MF_s MF_hello
#تعریف_کړه MF_hello(پیغام) چاپ_کړه("%s\n",پیغام)

#تعریف_کړه MF_t چاپ_کړه("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    چاپ_کړه("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#تعریف_کړه qq1(x) 1
    چاپ_کړه("qq1=%d\n", qq1( ));

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

    چاپ_کړه("basefromheader %s\n", get_basefile_from_سرلیک());
    چاپ_کړه("base %s\n", __BASE_FILE__);
#إذا !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ثابت حرف *fn = get_file_from_سرلیک();
      إذا (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      چاپ_کړه("filefromheader %s\n", fn);
    }
#د_که_پای

    چاپ_کړه("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_دوهم = 1;
    have_included_42test_h_دریم = 1;

    /* Check that we don't complain about stray \ here */
    چاپ_کړه("print a backslash: %s\n", stringify(\\));
}


ساكن فراغ print_عدد(حرف *fn, صحيح کرښه, صحيح عدد) {
    چاپ_کړه("fn %s, line %d, num %d\n", fn, کرښه, عدد);
}

فراغ recursive_macro_test(فراغ)
{

#تعریف_کړه ELF32_ST_TYPE(val)              ((val) & 0xf)
#تعریف_کړه ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#تعریف_کړه STB_WEAK        2               /* Weak symbol */
#تعریف_کړه ELFW(type) ELF##32##_##type
    چاپ_کړه("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#تعریف_کړه WRAP(x) x
    
#تعریف_کړه print_عدد(x) print_عدد(__FILE__,__LINE__,x)
    print_عدد(123);
    WRAP(print_عدد(123));
    WRAP(WRAP(print_عدد(123)));

ساكن بنية recursive_macro { صحيح rm_ډګر; } G;
#تعریف_کړه rm_ډګر (G.rm_ډګر)
    چاپ_کړه("rm_field = %d\n", rm_ډګر);
    چاپ_کړه("rm_field = %d\n", WRAP(rm_ډګر));
    WRAP((چاپ_کړه("rm_field = %d %d\n", rm_ډګر, WRAP(rm_ډګر))));
}

#إذا __TINYC__
صحيح op(a, b)
{
    أرجع a / b;
}

صحيح ret(a)
{
    إذا (a == 2)
        أرجع 1;
    إذا (a == 3)
        أرجع 2;
    أرجع 0;
}
#د_که_پای

#إذا !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#تعریف_کړه CONSTANTINDEXEDSTRLIT
#د_که_پای
حرف str_ag1[] = "b";
حرف str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#که_تعریف_شوی CONSTANTINDEXEDSTRLIT
حرف str_ag3[] = { "ab"[1], 0 };
حرف str_x[2] = { "xy" "z"[2], 0 };
#د_که_پای
حرف *str_ar[] = { "one", "two" };
بنية str_SS {بینښه حرف a[3], b; };
بنية str_SS str_sinit15 = { "r" };
بنية str_SS str_sinit16[] = { { "q" }, 2 };

ساكن فراغ string_test2()
{
    حرف *p = "hello";
    حرف a3[2] = { "p" };
    حرف a4[2] = { "ab" "c"[2], 0 };
    حرف *pa1 = "def" + 1;
    حرف *pa2 = { "xyz" + 1 };
    صحيح i = 0;
    بنية str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#که_نه_تعریف_شوی CONSTANTINDEXEDSTRLIT
    حرف str_ag3[] = { "ab"[1], 0 };
    حرف str_x[2] = { "xy" "z"[2], 0 };
#د_که_پای
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
    چاپ_کړه("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

فراغ ps(ثابت حرف *s)
{
    صحيح c;
    طالما (1) {
        c = *s;
        إذا (c == 0)
            اكسر;
        چاپ_کړه("%c", c);
        s++;
    }
}

ثابت حرف foo1_string[] = "\
bar\n\
test\14\
1";

فراغ string_test()
{
    بینښه صحيح b;
    چاپ_کړه("string:\n");
    چاپ_کړه("\141\1423\143\n");/* dezdez test */
    چاپ_کړه("\x41\x42\x43\x3a\n");
    چاپ_کړه("c=%c\n", 'r');
    چاپ_کړه("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    چاپ_کړه("foo1_string='%s'\n", foo1_string);
#إذا 0
    چاپ_کړه("wstring=%S\n", L"abc");
    چاپ_کړه("wstring=%S\n", L"abc" L"def" "ghi");
    چاپ_کړه("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    چاپ_کړه("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#د_که_پای
    ps("test\n");
    b = 32;
    طالما ((b = b + 1) < 96) {
        چاپ_کړه("%c", b);
    }
    چاپ_کړه("\n");
    چاپ_کړه("fib=%d\n", fib(33));
    b = 262144;
    طالما (b != 0x80000000) {
        عدد(b);
        b = b * 2;
    }
    string_test2();
}


فراغ if1t(صحيح n, صحيح a, صحيح b, صحيح c)
{
    إذا (a && b) چاپ_کړه("if1t: %d 1 %d %d\n", n, a, b);
    إذا (a && !b) چاپ_کړه("if1t: %d 2 %d %d\n", n, a, b);
    إذا (!a && b) چاپ_کړه("if1t: %d 3 %d %d\n", n, a, b);
    إذا (!a && !b) چاپ_کړه("if1t: %d 4 %d %d\n", n, a, b);
    إذا (a || b) چاپ_کړه("if1t: %d 5 %d %d\n", n, a, b);
    إذا (a || !b) چاپ_کړه("if1t: %d 6 %d %d\n", n, a, b);
    إذا (!a || b) چاپ_کړه("if1t: %d 7 %d %d\n", n, a, b);
    إذا (!a || !b) چاپ_کړه("if1t: %d 8 %d %d\n", n, a, b);
    إذا (a && b || c) چاپ_کړه("if1t: %d 9 %d %d %d\n", n, a, b, c);
    إذا (a || b && c) چاپ_کړه("if1t: %d 10 %d %d %d\n", n, a, b, c);
    إذا (a > b - 1 && c) چاپ_کړه("if1t: %d 11 %d %d %d\n", n, a, b, c);
    إذا (a > b - 1 || c) چاپ_کړه("if1t: %d 12 %d %d %d\n", n, a, b, c);
    إذا (a > 0 && 1) چاپ_کړه("if1t: %d 13 %d %d %d\n", n, a, b, c);
    إذا (a > 0 || 0) چاپ_کړه("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

فراغ if2t(فراغ)
{
    إذا (0 && 1 || چاپ_کړه("if2t:ok\n") || 1)
      چاپ_کړه("if2t:ok2\n");
    چاپ_کړه("if2t:ok3\n");
}

فراغ if3t(فراغ)
{
    متطاير اوږد اوږد i = 1;
    إذا (i <= 18446744073709551615ULL)
      ;
    وإلا
      چاپ_کړه ("if3t:wrong 1\n");
}

فراغ if_test(فراغ)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

فراغ loop_test()
{
    صحيح i;
    i = 0;
    طالما (i < 10)
        چاپ_کړه("%d", i++);
    چاپ_کړه("\n");
    لكل(i = 0; i < 10;i++)
        چاپ_کړه("%d", i);
    چاپ_کړه("\n");
    i = 0;
    افعل {
        چاپ_کړه("%d", i++);
    } طالما (i < 10);
    چاپ_کړه("\n");

    حرف شمېر_2 = 123;
    /* c99 for loop init test */
    لكل (اندازه_t شمېر_2 = 1; شمېر_2 < 3; شمېر_2++)
        چاپ_کړه("count=%d\n", شمېر_2);
    چاپ_کړه("count = %d\n", شمېر_2);

    /* break/continue tests */
    i = 0;
    طالما (1) {
        إذا (i == 6)
            اكسر;
        i++;
        إذا (i == 3)
            استمر;
        چاپ_کړه("%d", i);
    }
    چاپ_کړه("\n");

    /* break/continue tests */
    i = 0;
    افعل {
        إذا (i == 6)
            اكسر;
        i++;
        إذا (i == 3)
            استمر;
        چاپ_کړه("%d", i);
    } طالما(1);
    چاپ_کړه("\n");

    لكل(i = 0;i < 10;i++) {
        إذا (i == 3)
            استمر;
        چاپ_کړه("%d", i);
    }
    چاپ_کړه("\n");
}

تعريفنوع صحيح typedef_and_label;

فراغ goto_test()
{
    صحيح i;
    ساكن فراغ *label_جدول[3] = { &&label1, &&label2, &&label3 };
    بنية {
        صحيح bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    چاپ_کړه("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    إذا (i >= 10) 
        اذهب s_پای_ټکی;
    چاپ_کړه("%d", i);
    i++;
    اذهب s_loop;
 s_پای_ټکی:
    چاپ_کړه("\n");

    /* we also test computed gotos (GCC extension) */
    لكل(i=0;i<3;i++) {
        اذهب *label_جدول[i];
    label1:
        چاپ_کړه("label1\n");
        اذهب بل;
    label2:
        چاپ_کړه("label2\n");
        اذهب بل;
    label3:
        چاپ_کړه("label3\n");
    بل: ;
    }
}

تعداد {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

تعداد test {
    E5 = 1000,
};

بنية S_enum {
    تعداد {E6 = 42, E7, E8} e:8;
};

تعداد ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((بینښه اوږد)0xf000 << 31) << 1,
};

تعداد { BIASU = -1U<<31 };
تعداد { BIASS = -1 << 31 };

ساكن صحيح getint(صحيح i)
{
  إذا (i)
    أرجع 0;
  وإلا
    أرجع (صحيح)(-1U << 31);
}

فراغ enum_test()
{
    تعداد test b1;
    /* The following should give no warning */
    بینښه *p = &b1;
    بنية S_enum s = {E7};
    چاپ_کړه("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    چاپ_کړه("b1=%d\n", b1);
    چاپ_کړه("enum large: %ld\n", EL_large);

    إذا (getint(0) == BIASU)
      چاپ_کړه("enum unsigned: ok\n");
    وإلا
      چاپ_کړه("enum unsigned: wrong\n");
    إذا (getint(0) == BIASS)
      چاپ_کړه("enum unsigned: ok\n");
    وإلا
      چاپ_کړه("enum unsigned: wrong\n");
}

تعريفنوع صحيح *my_ptr;

تعريفنوع صحيح mytype1;
تعريفنوع صحيح mytype2;

فراغ typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    صحيح b;

    a = &b;
    *a = 1234;
    چاپ_کړه("a=%d\n", *a);
    mytype2 = 2;
    چاپ_کړه("mytype2=%d\n", mytype2);
}

فراغ forward_test()
{
    forward_ref();
    forward_ref();
}


فراغ forward_ref(فراغ)
{
    چاپ_کړه("forward ok\n");
}

تعريفنوع بنية struct1 {
    صحيح f1;
    صحيح f2, f3;
    اتحاد union1 {
        صحيح v1;
        صحيح v2;
    } u;
    حرف str[3];
} struct1;

بنية struct2 {
    صحيح a;
    حرف b;
};

اتحاد union2 {
    صحيح w1;
    صحيح w2;
};

بنية struct1 st1, st2;

بنية تشه_mem {
    /* nothing */ ;
    صحيح x;
};

صحيح tab[3];
صحيح tab2[3][2];

صحيح g;

فراغ f1(صحيح g)
{
    چاپ_کړه("g1=%d\n", g);
}

فراغ scope_test()
{
    g = 2;
    f1(1);
    چاپ_کړه("g2=%d\n", g);
    {
        صحيح g;
        g = 3;
        چاپ_کړه("g3=%d\n", g);
        {
            صحيح g;
            g = 4;
            چاپ_کړه("g4=%d\n", g);
        }
    }
    چاپ_کړه("g5=%d\n", g);
}

صحيح st2_i;
صحيح *st2_p = &st2_i;
فراغ scope2_test()
{
    حرف a[50];
    st2_i = 42;
    لكل (صحيح st2_i = 1; st2_i < 10; st2_i++) {
        خارجي صحيح st2_i;
        st2_i++;
        چاپ_کړه("exloc: %d\n", st2_i);
    }
    چاپ_کړه("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
خارجي صحيح st_global1;
صحيح st_global1=42;
خارجي صحيح st_global1;
صحيح st_global1;
خارجي صحيح st_global2;
صحيح st_global2;
خارجي صحيح st_global2;
صحيح st_global2;

فراغ array_test()
{
    صحيح i, j, a[4];

    چاپ_کړه("sizeof(a) = %d\n", حجم(a));
    چاپ_کړه("sizeof(\"a\") = %d\n", حجم("a"));
#که_تعریف_شوی C99_MACROS
    چاپ_کړه("sizeof(__func__) = %d\n", حجم(__func__));
#د_که_پای
    چاپ_کړه("sizeof tab %d\n", حجم(tab));
    چاپ_کړه("sizeof tab2 %d\n", حجم tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    چاپ_کړه("%d %d %d\n", tab[0], tab[1], tab[2]);
    لكل(i=0;i<3;i++)
        لكل(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    لكل(i=0;i<3*2;i++) {
        چاپ_کړه(" %3d", ((صحيح *)tab2)[i]);
    }
    چاپ_کړه("\n");
    چاپ_کړه("sizeof(size_t)=%d\n", حجم(اندازه_t));
    چاپ_کړه("sizeof(ptrdiff_t)=%d\n", حجم(ptrdiff_t));
}

فراغ بیان_test()
{
    صحيح a, b;
    a = 0;
    چاپ_کړه("%d\n", a += 1);
    چاپ_کړه("%d\n", a -= 2);
    چاپ_کړه("%d\n", a *= 31232132);
    چاپ_کړه("%d\n", a /= 4);
    چاپ_کړه("%d\n", a %= 20);
    چاپ_کړه("%d\n", a &= 6);
    چاپ_کړه("%d\n", a ^= 7);
    چاپ_کړه("%d\n", a |= 8);
    چاپ_کړه("%d\n", a >>= 3);
    چاپ_کړه("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    چاپ_کړه("%d\n", a + 1);
    چاپ_کړه("%d\n", a - 2);
    چاپ_کړه("%d\n", a * 312);
    چاپ_کړه("%d\n", a / 4);
    چاپ_کړه("%d\n", b / 4);
    چاپ_کړه("%d\n", (بینښه)b / 4);
    چاپ_کړه("%d\n", a % 20);
    چاپ_کړه("%d\n", b % 20);
    چاپ_کړه("%d\n", (بینښه)b % 20);
    چاپ_کړه("%d\n", a & 6);
    چاپ_کړه("%d\n", a ^ 7);
    چاپ_کړه("%d\n", a | 8);
    چاپ_کړه("%d\n", a >> 3);
    چاپ_کړه("%d\n", b >> 3);
    چاپ_کړه("%d\n", (بینښه)b >> 3);
    چاپ_کړه("%d\n", a << 4);
    چاپ_کړه("%d\n", ~a);
    چاپ_کړه("%d\n", -a);
    چاپ_کړه("%d\n", +a);

    چاپ_کړه("%d\n", 12 + 1);
    چاپ_کړه("%d\n", 12 - 2);
    چاپ_کړه("%d\n", 12 * 312);
    چاپ_کړه("%d\n", 12 / 4);
    چاپ_کړه("%d\n", 12 % 20);
    چاپ_کړه("%d\n", 12 & 6);
    چاپ_کړه("%d\n", 12 ^ 7);
    چاپ_کړه("%d\n", 12 | 8);
    چاپ_کړه("%d\n", 12 >> 2);
    چاپ_کړه("%d\n", 12 << 4);
    چاپ_کړه("%d\n", ~12);
    چاپ_کړه("%d\n", -12);
    چاپ_کړه("%d\n", +12);
    چاپ_کړه("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

صحيح isid(صحيح c)
{
    أرجع (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

صحيح vstack[10], *vstack_ptr;

فراغ vpush(صحيح vt, صحيح vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

فراغ vpop(صحيح *ft, صحيح *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

فراغ expr2_test()
{
    صحيح a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    چاپ_کړه("res= %d %d\n", a, b);
}

صحيح const_len_ar[حجم(1/0)]; /* div-by-zero, but in unevaluated context */

فراغ constant_بیان_test()
{
    صحيح a;
    a = 3;
    چاپ_کړه("%d\n", a * 16);
    چاپ_کړه("%d\n", a * 1);
    چاپ_کړه("%d\n", a + 0);
    چاپ_کړه("%d\n", حجم(const_len_ar));
}

صحيح tab4[10];

فراغ بیان_ptr_test()
{
    صحيح arr[10], *p, *q;
    صحيح i = -1;

    p = tab4;
    q = tab4 + 10;
    چاپ_کړه("diff=%d\n", q - p);
    p++;
    چاپ_کړه("inc=%d\n", p - tab4);
    p--;
    چاپ_کړه("dec=%d\n", p - tab4);
    ++p;
    چاپ_کړه("inc=%d\n", p - tab4);
    --p;
    چاپ_کړه("dec=%d\n", p - tab4);
    چاپ_کړه("add=%d\n", p + 3 - tab4);
    چاپ_کړه("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    چاپ_کړه("%p %p %ld\n", q, p, p-q);
    چاپ_کړه("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    چاپ_کړه("%p %p %ld\n", q, p, p-q);
    چاپ_کړه("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (صحيح *)((حرف *)p + 0xf0000000);
    چاپ_کړه("%p %p %ld\n", q, p, p-q);
    چاپ_کړه("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    چاپ_کړه("%p %p %ld\n", q, p, p-q);
    چاپ_کړه("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        بنية size12 {
            صحيح i, j, k;
        };
        بنية size12 s[2], *sp = s;
        صحيح i, j;
        sp->i = 42;
        sp++;
        j = -1;
        چاپ_کړه("%d\n", sp[j].i);
    }
#که_تعریف_شوی __LP64__
    i = 1;
    p = (صحيح*)0x100000000UL + i;
    i = ((اوږد)p) >> 32;
    چاپ_کړه("largeptr: %p %d\n", p, i);
#د_که_پای
    p = &arr[0];
    q = p + 3;
    چاپ_کړه ("%d\n", (صحيح)((p - q) / 3));
}

فراغ بیان_cmp_test()
{
    صحيح a, b;
    a = -1;
    b = 1;
    چاپ_کړه("%d\n", a == a);
    چاپ_کړه("%d\n", a != a);

    چاپ_کړه("%d\n", a < b);
    چاپ_کړه("%d\n", a <= b);
    چاپ_کړه("%d\n", a <= a);
    چاپ_کړه("%d\n", b >= a);
    چاپ_کړه("%d\n", a >= a);
    چاپ_کړه("%d\n", b > a);

    چاپ_کړه("%d\n", (بینښه)a < b);
    چاپ_کړه("%d\n", (بینښه)a <= b);
    چاپ_کړه("%d\n", (بینښه)a <= a);
    چاپ_کړه("%d\n", (بینښه)b >= a);
    چاپ_کړه("%d\n", (بینښه)a >= a);
    چاپ_کړه("%d\n", (بینښه)b > a);
}

بنية تشه {
};

بنية aligntest1 {
    حرف a[10];
};

بنية aligntest2 {
    صحيح a;
    حرف b[10];
};

بنية aligntest3 {
    مزدوج a, b;
};

بنية aligntest4 {
    مزدوج a[0];
};

بنية __attribute__((aligned(16))) aligntest5
{
    صحيح i;
};
بنية aligntest6
{
    صحيح i;
} __attribute__((aligned(16)));
بنية aligntest7
{
    صحيح i;
};
بنية aligntest5 altest5[2];
بنية aligntest6 altest6[2];
صحيح pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
بنية aligntest7 altest7[2] __attribute__((aligned(16)));

بنية aligntest8
{
  صحيح i;
} __attribute__((aligned(4096)));

بنية Large {
    بینښه اوږد flags;
    اتحاد {
	فراغ *u1;
	صحيح *u2;
    };

    بنية {
	اتحاد {
	    بینښه اوږد شاخص;
	    فراغ *freelist;
	};
	اتحاد {
	    بینښه اوږد counters;
	    بنية {
		صحيح bla;
	    };
	};
    };

    اتحاد {
	بنية {
	    اوږد u3;
	    اوږد u4;
	};
	فراغ *u5;
	بنية {
	    بینښه اوږد compound_سر;
	    بینښه صحيح compound_dtor;
	    بینښه صحيح compound_ترتیب;
	};
    };
} __attribute__((aligned(2 * حجم(اوږد))));

تعريفنوع بینښه اوږد اوږد __attribute__((aligned(4))) unaligned_u64;

بنية aligntest9 {
    بینښه صحيح buf_nr;
    unaligned_u64 پیل_lba;
};

بنية aligntest10 {
    بینښه صحيح buf_nr;
    بینښه اوږد اوږد پیل_lba;
};

فراغ struct_test()
{
    struct1 *s;
    اتحاد union2 u;
    بنية Large ls;

    چاپ_کړه("sizes: %d %d %d %d\n",
           حجم(بنية struct1),
           حجم(بنية struct2),
           حجم(اتحاد union1),
           حجم(اتحاد union2));
    چاپ_کړه("offsets: %d\n", (صحيح)((حرف*)&st1.u.v1 - (حرف*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    چاپ_کړه("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    چاپ_کړه("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    چاپ_کړه("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    چاپ_کړه("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    چاپ_کړه("str_addr=%x\n", (صحيح)(uintptr_t)st1.str - (صحيح)(uintptr_t)&st1.f1);

    /* align / size tests */
    چاپ_کړه("aligntest1 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest1), __alignof__(بنية aligntest1));
    چاپ_کړه("aligntest2 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest2), __alignof__(بنية aligntest2));
    چاپ_کړه("aligntest3 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest3), __alignof__(بنية aligntest3));
#إذا !(defined _WIN32 && CC_NAME == CC_clang)
    چاپ_کړه("aligntest4 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest4), __alignof__(بنية aligntest4));
#د_که_پای
    چاپ_کړه("aligntest5 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest5), __alignof__(بنية aligntest5));
    چاپ_کړه("aligntest6 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest6), __alignof__(بنية aligntest6));
    چاپ_کړه("aligntest7 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest7), __alignof__(بنية aligntest7));
    چاپ_کړه("aligntest8 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest8), __alignof__(بنية aligntest8));
#إذا !(defined _WIN32 && CC_NAME == CC_clang)
    چاپ_کړه("aligntest9 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest9), __alignof__(بنية aligntest9));
#د_که_پای
    چاپ_کړه("aligntest10 sizeof=%d alignof=%d\n",
           حجم(بنية aligntest10), __alignof__(بنية aligntest10));
    چاپ_کړه("altest5 sizeof=%d alignof=%d\n",
           حجم(altest5), __alignof__(altest5));
    چاپ_کړه("altest6 sizeof=%d alignof=%d\n",
           حجم(altest6), __alignof__(altest6));
    چاپ_کړه("altest7 sizeof=%d alignof=%d\n",
           حجم(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#إذا !(defined _WIN32 && CC_NAME == CC_clang)
    چاپ_کړه("sizeof(struct empty) = %d\n", حجم(بنية تشه));
#د_که_پای
    چاپ_کړه("alignof(struct empty) = %d\n", __alignof__(بنية تشه));

    چاپ_کړه("Large: sizeof=%d\n", حجم(ls));
    memset(&ls, 0, حجم(ls));
    ls.compound_سر = 42;
    چاپ_کړه("Large: offsetof(compound_head)=%d\n", (صحيح)((حرف*)&ls.compound_سر - (حرف*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ساكن صحيح __csf(صحيح x) { أرجع x; }
ساكن فراغ *_csf = __csf;
#تعریف_کړه csf(t,n) ((t(*)(صحيح))_csf)(n)

/* XXX: depend on endianness */
فراغ char_short_test()
{
    صحيح var1, var2;
    نښهدار حرف var3;
    اوږد اوږد var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    چاپ_کړه("s8=%d %d\n", 
           *(نښهدار حرف *)&var1, *(نښهدار حرف *)&var2);
    چاپ_کړه("u8=%d %d\n", 
           *(بینښه حرف *)&var1, *(بینښه حرف *)&var2);
    چاپ_کړه("s16=%d %d\n", 
           *(لنډ *)&var1, *(لنډ *)&var2);
    چاپ_کړه("u16=%d %d\n", 
           *(بینښه لنډ *)&var1, *(بینښه لنډ *)&var2);
    چاپ_کړه("s32=%d %d\n", 
           *(صحيح *)&var1, *(صحيح *)&var2);
    چاپ_کړه("u32=%d %d\n", 
           *(بینښه صحيح *)&var1, *(بینښه صحيح *)&var2);
    *(نښهدار حرف *)&var1 = 0x08;
    چاپ_کړه("var1=%x\n", var1);
    *(لنډ *)&var1 = 0x0809;
    چاپ_کړه("var1=%x\n", var1);
    *(صحيح *)&var1 = 0x08090a0b;
    چاپ_کړه("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    چاپ_کړه("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    چاپ_کړه("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    چاپ_کړه("promote char/short cast VA %d %d\n", (نښهدار حرف)(var1 + 1), (نښهدار حرف)(var4 + 1));
#إذا !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(بینښه حرف,0x89898989);
    var4 = csf(نښهدار حرف,0xabababab);
#که_تعریف_شوی __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#د_که_پای
    چاپ_کړه("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    چاپ_کړه("promote char/short fumcret VA %d %d %d %d\n",
        csf(بینښه لنډ,0xcdcdcdcd),
        csf(لنډ,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#د_که_پای
    var3 = -10;
    var1 = (نښهدار حرف)(بینښه حرف)(var3 + 1);
    var4 = (نښهدار حرف)(بینښه حرف)(var3 + 1);
    چاپ_کړه("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (بینښه)(صحيح)(var4 + 1);
    چاپ_کړه("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (بینښه)(نښهدار حرف)(var4 + 1);
    چاپ_کړه("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

تعريفنوع بنية Sym {
    صحيح v;
    صحيح t;
    صحيح c;
    بنية Sym *بل;
    بنية Sym *prev;
} Sym;

#تعریف_کړه ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#تعریف_کړه TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ساكن صحيح toupper1(صحيح a)
{
    أرجع TOUPPER(a);
}

ساكن بینښه صحيح calc_vm_flags(بینښه صحيح prot)
{
  بینښه صحيح prot_بټونه;
  /* This used to segfault in some revisions: */
  prot_بټونه = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  أرجع prot_بټونه;
}

تعداد cast_enum { لومړی_2, وروستی_2 };

ساكن فراغ tst_cast(تعداد cast_enum ce)
{
    چاپ_کړه("%d\n", ce);
}

فراغ bool_test()
{
    صحيح *s, a, b, t, f, i;

    a = 0;
    s = (فراغ*)0;
    چاپ_کړه("!s=%d\n", !s);

    إذا (!s || !s[0])
        a = 1;
    چاپ_کړه("a=%d\n", a);

    چاپ_کړه("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    چاپ_کړه("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    چاپ_کړه("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#إذا 1 && 1
    چاپ_کړه("a1\n");
#د_که_پای
#إذا 1 || 0
    چاپ_کړه("a2\n");
#د_که_پای
#إذا 1 ? 0 : 1
    چاپ_کړه("a3\n");
#د_که_پای
#إذا 0 ? 0 : 1
    چاپ_کړه("a4\n");
#د_که_پای

    a = 4;
    چاپ_کړه("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    چاپ_کړه("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    چاپ_کړه("exp=%d\n", f == (32 <= a && a <= 3));
    چاپ_کړه("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    چاپ_کړه("type of bool: %d\n", (صحيح) ( (~ ((بینښه صحيح) (t && 1))) / 2) );
    tst_cast(t >= 0 ? لومړی_2 : وروستی_2);

    چاپ_کړه("type of cond: %d\n", (~(t ? 0U : (بینښه صحيح)0)) / 2 );
    /* test ? : cast */
    {
        صحيح aspect_on;
        صحيح aspect_native = 65536;
        مزدوج bfu_aspect = 1.0;
        صحيح aspect;
        لكل(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            چاپ_کړه("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ساكن صحيح v1 = 34 ? : -1; /* constant case */
        ساكن صحيح v2 = 0 ? : -1; /* constant case */
        صحيح a = 30;
        
        چاپ_کړه("%d %d\n", v1, v2);
        چاپ_کړه("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    لكل(i=0;i<256;i++) {
        إذا (toupper1 (i) != TOUPPER (i))
            چاپ_کړه("error %d\n", i);
    }
    چاپ_کړه ("bits = 0x%x\n", calc_vm_flags (0x1));
}

خارجي صحيح undefined_function(فراغ);
خارجي صحيح defined_function(فراغ);

#که_تعریف_شوی __clang__
صحيح undefined_function(فراغ) {}
#د_که_پای

ساكن مضمن فراغ refer_منزل_undefined(فراغ)
{
  undefined_function();
}

فراغ optimize_بهر_test(فراغ)
{
  صحيح i = 0 ? undefined_function() : defined_function();
  چاپ_کړه ("oo:%d\n", i);
  صحيح j = 1 ? defined_function() : undefined_function();
  چاپ_کړه ("oo:%d\n", j);
  إذا (0)
    چاپ_کړه("oo:%d\n", undefined_function());
  وإلا
    چاپ_کړه("oo:%d\n", defined_function());
  إذا (1)
    چاپ_کړه("oo:%d\n", defined_function());
  وإلا
    چاپ_کړه("oo:%d\n", undefined_function());
  طالما (1) {
      چاپ_کړه("oow:%d\n", defined_function());
      اكسر;
      چاپ_کړه("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  بدل (j)
    حالة 1: اكسر;
  چاپ_کړه ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  طالما (1)
    اكسر;
  چاپ_کړه ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  افعل
    اكسر;
  طالما (1);
  چاپ_کړه ("ool2:%d\n", defined_function());
  لكل (;;)
    اكسر;
  چاپ_کړه ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  طالما (1) {
	{
	  اكسر;
	}
      چاپ_کړه ("ool4:%d\n", undefined_function());
  }
  j = 1;
  طالما (j) {
      إذا (j == 0)
	اكسر; /* this break shouldn't disable code outside the if. */
      چاپ_کړه("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  طالما (j) {
      إذا (1)
	j--;
      وإلا
	breakhere: اكسر;
      چاپ_کړه("ool6:%d\n", defined_function());
      اذهب breakhere;
  }
  j = 1;
  طالما (j) {
      j--;
      استمر;
      چاپ_کړه("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  إذا (0 && undefined_function())
    undefined_function();
  إذا (defined_function() && 0)
    undefined_function();
  إذا (0 && 0)
    undefined_function();
  إذا (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  إذا (1 || undefined_function())
    ;
  وإلا
    undefined_function();
  إذا (defined_function() || 1)
    ;
  وإلا
    undefined_function();
  إذا (1 || 1)
    ;
  وإلا
    undefined_function();
  إذا (defined_function() || 1 || undefined_function())
    ;
  وإلا
    undefined_function();

  إذا (defined_function() && 0)
    refer_منزل_undefined();

  إذا (0) {
      (فراغ)حجم( ({
		     افعل { } طالما (0);
		     0;
		     }) );
      undefined_function();
  }

  إذا (0) {
      بدل (defined_function()) {
          حالة 0: undefined_function(); اكسر;
          افتراضي: undefined_function(); اكسر;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  إذا (1)
    أرجع;
  چاپ_کړه ("oor:%d\n", undefined_function());
}

صحيح defined_function(فراغ)
{
  ساكن صحيح i = 40;
  أرجع i++;
}

/* GCC accepts that */
ساكن صحيح tab_reinit[];
ساكن صحيح tab_reinit[10];

ساكن صحيح tentative_ar[];
ساكن صحيح tentative_ar[] = {1,2,3};

صحيح cinit1; /* a global variable can be defined several times without error ! */
صحيح cinit1; 
صحيح cinit1 = 0;
صحيح *cinit2 = (صحيح []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
حرف ثابت * ثابت cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
فراغ *cinit52 = &(فراغ*){ (فراغ*) 52 };

#إذا __TINYC__ || __GNUC__ >= 6
صحيح cinit4 = (صحيح){44};
فراغ *cinit51 = (فراغ*){ (فراغ*) 51 };
بنية _c6 { صحيح a,b; } cinit6 = (بنية _c6){61,62}, *cinit7 = &(بنية _c6){71,72};
#وإلا
صحيح cinit4 = 44;
فراغ *cinit51 = (فراغ*)51;
بنية _c6 { صحيح a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#د_که_پای

فراغ compound_literal_test(فراغ)
{
    صحيح *p, i;
    حرف *q, *q3;

    چاپ_کړه("cinit3 : %s\n", cinit3);
    چاپ_کړه("cinit4 : %d\n", cinit4);
    چاپ_کړه("cinit51 : %d\n", (صحيح)cinit51);
    چاپ_کړه("cinit52 : %d\n", *(صحيح*)cinit52);
    چاپ_کړه("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    چاپ_کړه("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    چاپ_کړه("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (صحيح []){1, 2, 3};
    لكل(i=0;i<3;i++)
        چاپ_کړه(" %d", p[i]);
    چاپ_کړه("\n");

    لكل(i=0;i<3;i++)
        چاپ_کړه("%d", cinit2[i]);
    چاپ_کړه("\n");

    q = "tralala1";
    چاپ_کړه("q1=%s\n", q);

    q = (حرف *){ "tralala2" };
    چاپ_کړه("q2=%s\n", q);

    q3 = (حرف *){ q };
    چاپ_کړه("q3=%s\n", q3);

    q = (حرف []){ "tralala3" };
    چاپ_کړه("q4=%s\n", q);

#که_تعریف_شوی ALL_ISOC99
    p = (صحيح []){1, 2, cinit1 + 3};
    لكل(i=0;i<3;i++)
        چاپ_کړه(" %d", p[i]);
    چاپ_کړه("\n");

    لكل(i=0;i<3;i++) {
        p = (صحيح []){1, 2, 4 + i};
        چاپ_کړه("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#د_که_پای
}


#إذا __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    أرجع a + b;
}

صحيح kr_func2(a, b)
{
    أرجع a + b;
}

kr_test()
{
    چاپ_کړه("func1=%d\n", kr_func1(3, 4));
    چاپ_کړه("func2=%d\n", kr_func2(3, 4));
    أرجع 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
حرف invalid_function_def()[] {أرجع 0;}

#وإلا
# define kr_test() چاپ_کړه("func1=7\nfunc2=7\n")
#د_که_پای

فراغ عدد(صحيح n)
{
    حرف *tab, *p;
    tab = (حرف*)حافظه_ورکړه(20); 
    p = tab;
    طالما (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        إذا (n == 0)
            اكسر;
    }
    طالما (p != tab) {
        p--;
        چاپ_کړه("%c", *p);
    }
    چاپ_کړه("\n");
    حرر(tab);
}

/* structure assignment tests */
بنية structa1 {
    صحيح f1;
    حرف f2;
};

فراغ struct_ټاکل_test1(بنية structa1 s1, صحيح t, عائم f)
{
    چاپ_کړه("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

بنية structa1 struct_ټاکل_test2(بنية structa1 s1, صحيح t)
{
    s1.f1 += t;
    s1.f2 -= t;
    أرجع s1;
}

فراغ struct_ټاکل_test(فراغ)
{
    بنية S {
      بنية structa1 lsta1, lsta2;
      صحيح i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_ټاکل_test1(ps->lsta2, 3, 4.5);
    چاپ_کړه("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_ټاکل_test2(ps->lsta2, ps->i);
    چاپ_کړه("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ساكن بنية {
        فراغ (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_ټاکل_test }
    };
    چاپ_کړه("%d\n", struct_ټاکل_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_ټاکل_test2(s.lsta1, 1);
    چاپ_کړه("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

فراغ cast1(حرف a, لنډ b, بینښه حرف c, بینښه لنډ d)
{
    چاپ_کړه("%d %d %d %d\n", a, b, c, d);
}

حرف bcast;
لنډ scast;

فراغ cast_test()
{
    صحيح a;
    حرف c;
    حرف tab[10];
    بینښه b,d;
    لنډ s;
    حرف *p = عدم;
    بینښه اوږد ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    چاپ_کړه("%d %d %d %d\n",
           (حرف)(a + 1),
           (لنډ)(a + 1),
           (بینښه حرف)(a + 1),
           (بینښه لنډ)(a + 1));
    چاپ_کړه("%d %d %d %d\n",
           (حرف)0xfffff,
           (لنډ)0xfffff,
           (بینښه حرف)0xfffff,
           (بینښه لنډ)0xfffff);

    a = (bcast = 128) + 1;
    چاپ_کړه("%d\n", a);
    a = (scast = 65536) + 1;
    چاپ_کړه("%d\n", a);
    
    چاپ_کړه("sizeof(c) = %d, sizeof((int)c) = %d\n", حجم(c), حجم((صحيح)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (لنډ)b;
    چاپ_کړه("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (حرف)b;
    چاپ_کړه("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    چاپ_کړه("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    چاپ_کړه("sizeof(+(char)'a') = %d\n", حجم(+(حرف)'a'));
    چاپ_کړه("sizeof(-(char)'a') = %d\n", حجم(-(حرف)'a'));
    چاپ_کړه("sizeof(~(char)'a') = %d\n", حجم(-(حرف)'a'));

#إذا CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    چاپ_کړه("%d %d %ld %ld %lld %lld\n",
           (صحيح)p, (بینښه صحيح)p,
           (اوږد)p, (بینښه اوږد)p,
           (اوږد اوږد)p, (بینښه اوږد اوږد)p);
#د_که_پای

    /* from integers to pointers */
    چاپ_کړه("%p %p %p %p\n",
           (فراغ *)a, (فراغ *)b, (فراغ *)c, (فراغ *)d);

    /* int to int with sign set */
    چاپ_کړه("0x%lx\n", (بینښه اوږد)(صحيح)ul);
}

/* initializers tests */
بنية structinit1 {
    صحيح f1;
    حرف f2;
    لنډ f3;
    صحيح farray[3];
};

صحيح sinit1 = 2;
صحيح sinit2 = { 3 };
صحيح sinit3[3] = { 1, 2, {3}, };
صحيح sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
صحيح sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
صحيح sinit6[] = { 1, 2, 3 };
صحيح sinit7[] = { [2] = 3, [0] = 1, 2 };
حرف sinit8[] = "hello" "trala";

بنية structinit1 sinit9 = { 1, 2, 3 };
بنية structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
بنية structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#که_تعریف_شوی ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#د_که_پای
};

حرف *sinit12 = "hello world";
حرف *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
حرف sinit14[10] = { "abc" };
صحيح sinit15[3] = { حجم(sinit15), 1, 2 };

بنية { صحيح a[3], b; } sinit16[] = { { 1 }, 2 };

بنية bar {
        حرف *s;
        صحيح len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

صحيح sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

بنية complexinit0 {
    صحيح a;
    صحيح b;
};

بنية complexinit {
    صحيح a;
    ثابت بنية complexinit0 *b;
};

ثابت ساكن بنية complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ثابت بنية complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

بنية complexinit2 {
	صحيح a;
	صحيح b[];
};

بنية complexinit2 cix20;

بنية complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

بنية complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

تعريفنوع صحيح arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
تعريفنوع صحيح arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
صحيح sinit23[2] = { "astring" ? حجم("astring") : -1,
		   &sinit23 ? 42 : -1 };

صحيح sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
بنية bf_SS {بینښه صحيح بټ:1,bits31:31; };
بنية bf_SS bf_init = { .بټ = 1 };
بنية bfn_SS {صحيح a,b; بنية bf_SS c; صحيح d,e; };
بنية bfn_SS bfn_init = { .c.بټ = 1 };
بنية bfa_SS {صحيح a,b; بنية bf_SS c[3]; صحيح d,e; };
بنية bfa_SS bfa_init = { .c[1].بټ = 1 };
بنية bf_SS bfaa_init[3] = { [1].بټ = 1 };
بنية bf_SS bfaa_vinit[] = { [2].بټ = 1 };
بنية b2_SS {اوږد اوږد صحيح ډګر : 52; اوږد اوږد صحيح pad : 12; };
بنية b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

خارجي صحيح external_inited = 42;

فراغ init_test(فراغ)
{
    صحيح linit1 = 2;
    صحيح linit2 = { 3 };
    صحيح linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    صحيح linit6[] = { 1, 2, 3 };
    صحيح i, j;
    حرف linit8[] = "hello" "trala";
    صحيح linit12[10] = { 1, 2 };
    صحيح linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    حرف linit14[10] = "abc";
    صحيح linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    بنية linit16 { صحيح a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    صحيح linit17 = حجم(linit17);
    صحيح zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    صحيح linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    بنية bf_SS bf_finit = { .بټ = 1 };
    بنية bfn_SS bfn_finit = { .c.بټ = 1 };
    بنية bfa_SS bfa_finit = { .c[1].بټ = 1 };
    بنية bf_SS bfaa_finit[3] = { [1].بټ = 1 };
    بنية bf_SS bfaa_fvinit[] = { [2].بټ = 1 };
    بنية b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    چاپ_کړه("sinit1=%d\n", sinit1);
    چاپ_کړه("sinit2=%d\n", sinit2);
    چاپ_کړه("sinit3=%d %d %d %d\n", 
           حجم(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    چاپ_کړه("sinit6=%d\n", حجم(sinit6));
    چاپ_کړه("sinit7=%d %d %d %d\n", 
           حجم(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    چاپ_کړه("sinit8=%s\n", sinit8);
    چاپ_کړه("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    چاپ_کړه("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    چاپ_کړه("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    لكل(i=0;i<3;i++)
        لكل(j=0;j<2;j++)
            چاپ_کړه("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    چاپ_کړه("linit1=%d\n", linit1);
    چاپ_کړه("linit2=%d\n", linit2);
    چاپ_کړه("linit6=%d\n", حجم(linit6));
    چاپ_کړه("linit8=%d %s\n", حجم(linit8), linit8);

    چاپ_کړه("sinit12=%s\n", sinit12);
    چاپ_کړه("sinit13=%d %s %s %s\n",
           حجم(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    چاپ_کړه("sinit14=%s\n", sinit14);

    لكل(i=0;i<10;i++) چاپ_کړه(" %d", linit12[i]);
    چاپ_کړه("\n");
    لكل(i=0;i<10;i++) چاپ_کړه(" %d", linit13[i]);
    چاپ_کړه("\n");
    لكل(i=0;i<10;i++) چاپ_کړه(" %d", linit14[i]);
    چاپ_کړه("\n");
    لكل(i=0;i<10;i++) چاپ_کړه(" %d", linit15[i]);
    چاپ_کړه("\n");
    چاپ_کړه("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    چاپ_کړه("linit17=%d\n", linit17);
    چاپ_کړه("sinit15=%d\n", sinit15[0]);
    چاپ_کړه("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    چاپ_کړه("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    لكل(i=0;i<10;i++)
        چاپ_کړه("%x ", sinit18[i]);
    چاپ_کړه("\n");
    /* complex init check */
    چاپ_کړه("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    چاپ_کړه("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    چاپ_کړه("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", حجم cix20, حجم cix21, حجم cix22);

    چاپ_کړه("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    چاپ_کړه("arrtype2: %d %d\n", حجم(sinit19), حجم(sinit20));
    چاپ_کړه("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    چاپ_کړه("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    چاپ_کړه("arrtype5: %d %d\n", حجم(sinit21), حجم(sinit22));
    چاپ_کړه("arrtype6: %d\n", حجم(arrtype2));

    چاپ_کړه("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    چاپ_کړه("sinit24=%d\n", sinit24);
    چاپ_کړه("linit18= %d %d\n", linit18[0], linit18[1]);
    چاپ_کړه ("bf1: %u %u\n", bf_init.بټ, bf_init.bits31);
    چاپ_کړه ("bf2: %u %u\n", bf_finit.بټ, bf_finit.bits31);
    چاپ_کړه ("bf3: %u %u\n", bfn_init.c.بټ, bfn_init.c.bits31);
    چاپ_کړه ("bf4: %u %u\n", bfn_finit.c.بټ, bfn_finit.c.bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf5[%d]: %u %u\n", i, bfa_init.c[i].بټ, bfa_init.c[i].bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].بټ, bfa_finit.c[i].bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf7[%d]: %u %u\n", i, bfaa_init[i].بټ, bfaa_init[i].bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf8[%d]: %u %u\n", i, bfaa_finit[i].بټ, bfaa_finit[i].bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].بټ, bfaa_vinit[i].bits31);
    لكل (i = 0; i < 3; i++)
        چاپ_کړه ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].بټ, bfaa_fvinit[i].bits31);
}

فراغ switch_uc(بینښه حرف uc)
{
	بدل (uc) {
	    حالة 0xfb ... 0xfe:
		چاپ_کړه("ucsw:1\n");
		اكسر;
	    حالة 0xff:
		چاپ_کړه("ucsw:2\n");
		اكسر;
	    حالة 0 ... 5:
		چاپ_کړه("ucsw:3\n");
		اكسر;
	    افتراضي:
		چاپ_کړه("ucsw: broken!\n");
	}
}

فراغ switch_sc(نښهدار حرف sc)
{
	بدل (sc) {
	    حالة -5 ... -2:
		چاپ_کړه("scsw:1\n");
		اكسر;
	    حالة -1:
		چاپ_کړه("scsw:2\n");
		اكسر;
	    حالة 0 ... 5:
		چاپ_کړه("scsw:3\n");
		اكسر;
	    افتراضي:
		چاپ_کړه("scsw: broken!\n");
	}
}

فراغ switch_test()
{
    صحيح i;
    بینښه اوږد اوږد ull;
    اوږد اوږد ll;

    لكل(i=0;i<15;i++) {
        بدل(i) {
        حالة 0:
        حالة 1:
            چاپ_کړه("a");
            اكسر;
        افتراضي:
            چاپ_کړه("%d", i);
            اكسر;
        حالة 8 ... 12:
            چاپ_کړه("c");
            اكسر;
        حالة 3:
            چاپ_کړه("b");
            اكسر;
        حالة 0xc33c6b9fU:
        حالة 0x7c9eeeb9U:
            اكسر;
        }
    }
    چاپ_کړه("\n");

    لكل (i = 1; i <= 5; i++) {
	ull = (بینښه اوږد اوږد)i << 61;
	بدل (ull) {
	    حالة 1ULL << 61:
		چاپ_کړه("ullsw:1\n");
		اكسر;
	    حالة 2ULL << 61:
		چاپ_کړه("ullsw:2\n");
		اكسر;
	    حالة 3ULL << 61:
		چاپ_کړه("ullsw:3\n");
		اكسر;
	    حالة 4ULL << 61:
		چاپ_کړه("ullsw:4\n");
		اكسر;
	    حالة 5ULL << 61:
		چاپ_کړه("ullsw:5\n");
		اكسر;
	    افتراضي:
		چاپ_کړه("ullsw: broken!\n");
	}
    }

    لكل (i = 1; i <= 5; i++) {
	ll = (اوږد اوږد)i << 61;
	بدل (ll) {
	    حالة 1LL << 61:
		چاپ_کړه("llsw:1\n");
		اكسر;
	    حالة 2LL << 61:
		چاپ_کړه("llsw:2\n");
		اكسر;
	    حالة 3LL << 61:
		چاپ_کړه("llsw:3\n");
		اكسر;
	    حالة 4LL << 61:
		چاپ_کړه("llsw:4\n");
		اكسر;
	    حالة 5LL << 61:
		چاپ_کړه("llsw:5\n");
		اكسر;
	    افتراضي:
		چاپ_کړه("llsw: broken!\n");
	}
    }

    لكل (i = -5; i <= 5; i++) {
	switch_uc((بینښه حرف)i);
    }

    لكل (i = -5; i <= 5; i++) {
	switch_sc ((نښهدار حرف)i);
    }
}

/* ISOC99 _Bool type */
فراغ c99_bool_test(فراغ)
{
#که_تعریف_شوی BOOL_ISOC99
    صحيح a;
    _Bool b, b2;

    چاپ_کړه("sizeof(_Bool) = %d\n", حجم(_Bool));
    a = 3;
    چاپ_کړه("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    چاپ_کړه("b = %d\n", b);
    b++;
    چاپ_کړه("b = %d\n", b);
    b2 = 0;
    چاپ_کړه("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           حجم ((متطاير صحيح)a ? b : b2));
#د_که_پای
}

فراغ bitfield_test(فراغ)
{
    صحيح a;
    لنډ sa;
    بینښه حرف ca;
    بنية sbf1 {
        صحيح f1 : 3;
        صحيح : 2;
        صحيح f2 : 1;
        صحيح : 0;
        صحيح f3 : 5;
        صحيح f4 : 7;
        بینښه صحيح f5 : 7;
    } st1;
    چاپ_کړه("sizeof(st1) = %d\n", حجم(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    چاپ_کړه("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    چاپ_کړه("%d %d\n", sa, ca);

    st1.f1 = 7;
    إذا (st1.f1 == -1) 
        چاپ_کړه("st1.f1 == -1\n");
    وإلا 
        چاپ_کړه("st1.f1 != -1\n");
    إذا (st1.f2 == -1) 
        چاپ_کړه("st1.f2 == -1\n");
    وإلا 
        چاپ_کړه("st1.f2 != -1\n");

    بنية sbf2 {
        اوږد اوږد f1 : 45;
        اوږد اوږد : 2;
        اوږد اوږد f2 : 35;
        بینښه اوږد اوږد f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (اوږد اوږد)a << 25;
    st2.f3 = a;
    st2.f2++;
    چاپ_کړه("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#إذا 0
    Disabled لكل now until further clarification re GCC compatibility
    بنية sbf3 {
        صحيح f1 : 7;
        صحيح f2 : 1;
        حرف f3;
        صحيح f4 : 8;
        صحيح f5 : 1;
        صحيح f6 : 16;
    } st3;
    چاپ_کړه("sizeof(st3) = %d\n", حجم(st3));
#د_که_پای

    بنية sbf4 {
	صحيح x : 31;
	حرف y : 2;
    } st4;
    st4.y = 1;
    چاپ_کړه("st4.y == %d\n", st4.y);
    بنية sbf5 {
	صحيح a;
	حرف b;
	صحيح x : 12, y : 4, : 0, : 4, z : 3;
	حرف c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    چاپ_کړه("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    بنية sbf6 {
	لنډ x : 12;
	بینښه حرف y : 2;
    } st6;
    st6.y = 1;
    چاپ_کړه("st6.y == %d\n", st6.y);
}

#که_تعریف_شوی __x86_64__
#تعریف_کړه FLOAT_FMT "%f\n"
#وإلا
/* x86's float isn't compatible with GCC */
#تعریف_کړه FLOAT_FMT "%.5f\n"
#د_که_پای

/* declare strto* functions as they are C99 */
مزدوج strtod(ثابت حرف *nptr, حرف **endptr);

#إذا defined(_WIN32)
عائم strtof(ثابت حرف *nptr, حرف **endptr) {أرجع (عائم)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ثابت حرف *nptr, حرف **endptr) {أرجع (LONG_DOUBLE)strtod(nptr, endptr);}
#وإلا
عائم strtof(ثابت حرف *nptr, حرف **endptr);
LONG_DOUBLE strtold(ثابت حرف *nptr, حرف **endptr);
#د_که_پای

#تعریف_کړه FTEST(مختاړی, typename, type, fmt)\
فراغ مختاړی ## cmp(type a, type b)\
{\
    چاپ_کړه("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    چاپ_کړه(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    چاپ_کړه(fmt "\n", ++a);\
    چاپ_کړه(fmt "\n", a++);\
    چاپ_کړه(fmt "\n", a);\
    b = 0;\
    چاپ_کړه("%d %d\n", !a, !b);\
}\
فراغ مختاړی ## fcast(type a)\
{\
    عائم fa;\
    مزدوج da;\
    LONG_DOUBLE la;\
    صحيح ia;\
    اوږد اوږد llia;\
    بینښه صحيح ua;\
    بینښه اوږد اوږد llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    چاپ_کړه("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (صحيح)a;\
    llia = (اوږد اوږد)a;\
    a = (a >= 0) ? a : -a;\
    ua = (بینښه صحيح)a;\
    llua = (بینښه اوږد اوږد)a;\
    چاپ_کړه("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    چاپ_کړه("itof: " fmt "\n", b);\
    b = ua;\
    چاپ_کړه("utof: " fmt "\n", b);\
    b = llia;\
    چاپ_کړه("lltof: " fmt "\n", b);\
    b = llua;\
    إذا (CC_NAME != CC_clang) چاپ_کړه("ulltof: " fmt "\n", b);\
}\
\
عائم مختاړی ## retf(type a) { أرجع a; }\
مزدوج مختاړی ## retd(type a) { أرجع a; }\
LONG_DOUBLE مختاړی ## retld(type a) { أرجع a; }\
\
فراغ مختاړی ## call(فراغ)\
{\
    چاپ_کړه("float: " FLOAT_FMT, مختاړی ## retf(42.123456789));\
    چاپ_کړه("double: %f\n", مختاړی ## retd(42.123456789));\
    چاپ_کړه("long double: %Lf\n", مختاړی ## retld(42.123456789));\
    چاپ_کړه("strto%s: %f\n", #prefix, (مزدوج)strto ## مختاړی("1.2", عدم));\
}\
\
فراغ مختاړی ## signed_zeros(فراغ) \
{\
  type x = 0.0, y = -0.0, n, p;\
  إذا (x == y)\
    چاپ_کړه ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  وإلا\
    چاپ_کړه ("x != y; this is wrong!\n");\
\
  n = -x;\
  إذا (x == n)\
    چاپ_کړه ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  وإلا\
    چاپ_کړه ("x != -x; this is wrong!\n");\
\
  p = +y;\
  إذا (x == p)\
    چاپ_کړه ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  وإلا\
    چاپ_کړه ("x != +y; this is wrong!\n");\
  p = -y;\
  إذا (x == p)\
    چاپ_کړه ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  وإلا\
    چاپ_کړه ("x != -y; this is wrong!\n");\
}\
فراغ مختاړی ## nan(فراغ)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    چاپ_کړه("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
فراغ مختاړی ## test(فراغ)\
{\
    چاپ_کړه("testing '%s'\n", #typename);\
    مختاړی ## cmp(1, 2.5);\
    مختاړی ## cmp(2, 1.5);\
    مختاړی ## cmp(1, 1);\
    مختاړی ## fcast(234.6);\
    مختاړی ## fcast(-2334.6);\
    مختاړی ## call();\
    مختاړی ## signed_zeros();\
    إذا (CC_NAME != CC_clang) مختاړی ## nan();\
}

FTEST(f, عائم, عائم, "%f")
FTEST(d, مزدوج, مزدوج, "%f")
FTEST(ld, اوږد مزدوج, LONG_DOUBLE, "%Lf")

مزدوج ftab1[3] = { 1.2, 3.4, -5.6 };


فراغ float_test(فراغ)
{
#إذا !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    متطاير عائم fa, fb;
    متطاير مزدوج da, db;
    صحيح a;
    بینښه صحيح b;
    ساكن مزدوج nan2 = 0.0/0.0;
    ساكن مزدوج inf1 = 1.0/0.0;
    ساكن مزدوج inf2 = 1e5000;
    متطاير LONG_DOUBLE la;

    چاپ_کړه("sizeof(float) = %d\n", حجم(عائم));
    چاپ_کړه("sizeof(double) = %d\n", حجم(مزدوج));
    چاپ_کړه("sizeof(long double) = %d\n", حجم(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    چاپ_کړه("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    چاپ_کړه("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    چاپ_کړه("da=%f\n", da);
    fa = 123;
    چاپ_کړه("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    چاپ_کړه("da = %f\n", da);
    b = 4000000000;
    db = b;
    چاپ_کړه("db = %f\n", db);
    چاپ_کړه("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    چاپ_کړه ("da subnormal = %a\n", da);
    چاپ_کړه ("da subnormal = %.40g\n", da);
    چاپ_کړه ("la subnormal = %La\n", la);
    چاپ_کړه ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    چاپ_کړه ("da/2 subnormal = %a\n", da);
    چاپ_کړه ("da/2 subnormal = %.40g\n", da);
    چاپ_کړه ("la/2 subnormal = %La\n", la);
    چاپ_کړه ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    چاپ_کړه ("fa subnormal = %a\n", fa);
    چاپ_کړه ("fa subnormal = %.40g\n", fa);
    چاپ_کړه ("la subnormal = %La\n", la);
    چاپ_کړه ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    چاپ_کړه ("fa/2 subnormal = %a\n", fa);
    چاپ_کړه ("fa/2 subnormal = %.40g\n", fa);
    چاپ_کړه ("la/2 subnormal = %La\n", la);
    چاپ_کړه ("la/2 subnormal = %.40Lg\n", la);
#د_که_پای
}

صحيح fib(صحيح n)
{
    إذا (n <= 2)
        أرجع 1;
    وإلا
        أرجع fib(n-1) + fib(n-2);
}

#إذا __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#وإلا
فراغ __attribute__((aligned(16))) aligned_function(صحيح i) {}
#د_که_پای

فراغ funcptr_test()
{
    فراغ (*func)(صحيح);
    صحيح a;
    بنية {
        صحيح dummy;
        فراغ (*func)(صحيح);
    } st1;
    اوږد diff;

    func = &عدد;
    (*func)(12345);
    func = عدد;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = عدد;
    st1.func(12346);
    چاپ_کړه("sizeof1 = %d\n", حجم(funcptr_test));
    چاپ_کړه("sizeof2 = %d\n", حجم funcptr_test);
    چاپ_کړه("sizeof3 = %d\n", حجم(&funcptr_test));
    چاپ_کړه("sizeof4 = %d\n", حجم &funcptr_test);
    a = 0;
    func = عدد + a;
    diff = func - عدد;
    func(42);
    (func + diff)(42);
    (عدد + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    چاپ_کړه("aligned_function (should be zero): %d\n", ((صحيح)(uintptr_t)func) & 15);
}

فراغ lloptest(اوږد اوږد a, اوږد اوږد b)
{
    بینښه اوږد اوږد ua, ub;

    ua = a;
    ub = b;
    /* arith */
    چاپ_کړه("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    إذا (b != 0) {
        چاپ_کړه("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*دوګونی*/
    چاپ_کړه("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    چاپ_کړه("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    چاپ_کړه("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    چاپ_کړه("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    چاپ_کړه("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    چاپ_کړه("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    چاپ_کړه("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    چاپ_کړه("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

فراغ llshift(اوږد اوږد a, صحيح b)
{
    چاپ_کړه("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (بینښه اوږد اوږد)a >> b,
           a >> b,
           a << b);
    چاپ_کړه("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (بینښه اوږد اوږد)a >> 3,
           a >> 3,
           a << 3);
    چاپ_کړه("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (بینښه اوږد اوږد)a >> 35,
           a >> 35,
           a << 35);
}

فراغ llfloat(فراغ)
{
    عائم fa;
    مزدوج da;
    LONG_DOUBLE lda;
    اوږد اوږد la, lb, lc;
    بینښه اوږد اوږد ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    چاپ_کړه("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    چاپ_کړه("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    چاپ_کړه("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    چاپ_کړه("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    چاپ_کړه("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

اوږد اوږد llfunc1(صحيح a)
{
    أرجع a * 2;
}

بنية S {
    صحيح id; 
    حرف توکی;
};

اوږد اوږد صحيح ارزښت(بنية S *v)
{
    أرجع ((اوږد اوږد صحيح)v->توکی);
}

اوږد اوږد llfunc2(اوږد اوږد x, اوږد اوږد y, صحيح z)
{
    أرجع x * y * z;
}

فراغ check_opl_save_regs(حرف *a, اوږد اوږد b, صحيح c)
{
    *a = b < 0 && !c;
}

فراغ longlong_test(فراغ)
{
    اوږد اوږد a, b, c;
    صحيح ia;
    بینښه صحيح ua;
    چاپ_کړه("sizeof(long long) = %d\n", حجم(اوږد اوږد));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    چاپ_کړه(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    چاپ_کړه(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (اوږد اوږد)1,
           (اوږد اوږد)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    چاپ_کړه(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#إذا 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    چاپ_کړه(XLONG_LONG_FORMAT"\n", c);
#د_که_پای

    /* long long reg spill test */
    {
          بنية S a;

          a.توکی = 3;
          چاپ_کړه("%lld\n", ارزښت(&a));
    }
    lloptest(0x80000000, 0);

    {
        اوږد اوږد *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        چاپ_کړه("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        چاپ_کړه("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    چاپ_کړه("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    چاپ_کړه(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    اوږد اوږد *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    بینښه اوږد اوږد u = 0x8000000000000001ULL;
    u = (بینښه)(u + 1);
    چاپ_کړه("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (بینښه)(صحيح)(u + 1);
    چاپ_کړه("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    حرف cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    چاپ_کړه("check_opl_save_regs: %d\n", cc);
}

فراغ manyarg_test(فراغ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    چاپ_کړه("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    چاپ_کړه("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    چاپ_کړه("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    چاپ_کړه("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    چاپ_کړه("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    چاپ_کړه("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

فراغ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        بنية X { صحيح _x; };
        بنية X *x = va_arg(ap, بنية X *);
        أرجع x;
}

فراغ vprintf1(ثابت حرف *fmt, ...)
{
    va_list ap, aq;
    ثابت حرف *p;
    صحيح c, i;
    مزدوج d;
    اوږد اوږد ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    لكل(;;) {
        c = *p;
        إذا (c == '\0')
            اكسر;
        p++;
        إذا (c == '%') {
            c = *p;
            بدل(c) {
            حالة '\0':
                اذهب the_پای_ټکی;
            حالة 'd':
                i = va_arg(ap, صحيح);
                چاپ_کړه("%d", i);
                اكسر;
            حالة 'f':
                d = va_arg(ap, مزدوج);
                چاپ_کړه("%f", d);
                اكسر;
            حالة 'l':
                ll = va_arg(ap, اوږد اوږد);
                چاپ_کړه(LONG_LONG_FORMAT, ll);
                اكسر;
            حالة 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                چاپ_کړه("%Lf", ld);
                اكسر;
            }
            p++;
        } وإلا {
            توری_چاپ_کړه(c);
        }
    }
 the_پای_ټکی:
    va_end(aq);
    va_end(ap);
}

بنية myspace {
    لنډ صحيح profile;
};
بنية myspace2 {
#إذا CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    حرف a[1];
#وإلا
    حرف a[0];
#د_که_پای
};
بنية myspace3 {
    حرف a[1];
};
بنية myspace4 {
    حرف a[2];
};
بنية mytest {
    فراغ *foo, *bar, *baz;
};

بنية mytest stdarg_for_struct(بنية myspace bob, ...)
{
    بنية myspace george, bill;
    بنية myspace2 alex1;
    بنية myspace3 alex2;
    بنية myspace4 alex3;
    va_list ap;
    لنډ صحيح validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, بنية myspace2);
    alex2    = va_arg(ap, بنية myspace3);
    alex3    = va_arg(ap, بنية myspace4);
    bill     = va_arg(ap, بنية myspace);
    george   = va_arg(ap, بنية myspace);
    validate = va_arg(ap, صحيح);
    چاپ_کړه("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    أرجع (بنية mytest) {};
}

فراغ stdarg_for_libc(ثابت حرف *fmt, ...)
{
    va_list دلیلونه;
    va_start(دلیلونه, fmt);
    vprintf(fmt, دلیلونه);
    va_end(دلیلونه);
}

فراغ stdarg_syntax(صحيح n, ...)
{
    صحيح i;
    va_list ap;
    إذا (1)
      va_start(ap, n);
    وإلا
      ;
    i = va_arg(ap, صحيح);
    چاپ_کړه("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

تعريفنوع بنية{
    مزدوج x,y;
} ټکی;
ټکی pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ساكن فراغ stdarg_double_struct(صحيح nargs, صحيح posd,...)
{
    صحيح i;
    مزدوج d;
    ټکی pi;
    va_list دلیلونه;

    چاپ_کړه ("stdarg_double_struct: %d\n", posd);
    va_start(دلیلونه,posd);
    لكل(i = 0; i < nargs; i++) {
        إذا (i == posd) {
            d = va_arg (دلیلونه, مزدوج);
            چاپ_کړه ("d %d = %g\n", i, d);
        }
        وإلا {
            pi = va_arg (دلیلونه, ټکی);
            چاپ_کړه ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(دلیلونه);
}

فراغ stdarg_test(فراغ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    بنية myspace bob;
    بنية myspace2 bob2;
    بنية myspace3 bob3;
    بنية myspace4 bob4;

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
#إذا !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#د_که_پای
}

صحيح reltab[3] = { 1, 2, 3 };

صحيح *rel1 = &reltab[1];
صحيح *rel2 = &reltab[2];

فراغ getmyaddress(فراغ)
{
    چاپ_کړه("in getmyaddress\n");
}

#که_تعریف_شوی __LP64__
اوږد __pa_symbol(فراغ)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       أرجع ((اوږد)(((بینښه اوږد)(&rel1))) - (0xffffffff80000000UL));
}
#د_که_پای

uintptr_t theaddress = (uintptr_t)getmyaddress;
فراغ relocation_test(فراغ)
{
    فراغ (*fptr)(فراغ) = (فراغ (*)(فراغ))theaddress;
    چاپ_کړه("*rel1=%d\n", *rel1);
    چاپ_کړه("*rel2=%d\n", *rel2);
    fptr();
#که_تعریف_شوی __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    چاپ_کړه("pa_symbol: %d\n", (اوږد)&rel1 == __pa_symbol() - 0x80000000);
#د_که_پای
}

فراغ old_style_f(a,b,c)
     صحيح a, b;
     مزدوج c;
{
    چاپ_کړه("a=%d b=%d b=%f\n", a, b, c);
}

فراغ decl_func1(صحيح cmpfn())
{
    چاپ_کړه("cmpfn=%lx\n", (اوږد)cmpfn);
}

فراغ decl_func2(cmpfn)
صحيح cmpfn();
{
    چاپ_کړه("cmpfn=%lx\n", (اوږد)cmpfn);
}

فراغ old_style_function_test(فراغ)
{
#إذا CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#وإلا
    old_style_f((فراغ *)1, 2, 3.0);
#د_که_پای
    decl_func1(عدم);
    decl_func2(عدم);
}

فراغ alloca_test()
{
    حرف *p = alloca(16);
    strcpy(p,"123456789012345");
    چاپ_کړه("alloca: p is %s\n", p);
    حرف *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    چاپ_کړه("alloca: %s\n", strcpy(alloca(مزي_اوږدوالی(demo)+1),demo) );
}

فراغ *bounds_checking_is_enabled()
{
    حرف ca[10], *cp = ca-1;
    أرجع (ca != cp + 1) ? cp : عدم;
}

تعريفنوع صحيح constant_negative_array_اندازه_as_compile_وخت_assertion_idiom[(1 ? 2 : 0) - 1];

فراغ c99_vla_test_1(صحيح size1, صحيح size2)
{
    صحيح اندازه = size1 * size2;
    صحيح tab1[اندازه][2], tab2[10][2];
    فراغ *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    اندازه = اندازه-1;
    
    چاپ_کړه("Test C99 VLA 1 (sizeof): ");
    چاپ_کړه("%s\n", (حجم tab1 == size1 * size2 * 2 * حجم(صحيح)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    چاپ_کړه("Test C99 VLA 2 (ptrs subtract): ");
    چاپ_کړه("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (حجم(صحيح) * 2)) ? "PASSED" : "FAILED");
    چاپ_کړه("Test C99 VLA 3 (ptr add): ");
    چاپ_کړه("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * حجم(صحيح)) ? "PASSED" : "FAILED");
    چاپ_کړه("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    چاپ_کړه("%s\n", (*((صحيح *) (tab1_ptr + (size1 * 2 + 1) * حجم(صحيح))) == 42) ? "PASSED" : "FAILED");

    چاپ_کړه("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    إذا (bad_ptr = bounds_checking_is_enabled()) {
        صحيح *t1 = &tab1[size1 * size2 - 1][3];
        صحيح *t2 = &tab2[9][3];
        چاپ_کړه("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        چاپ_کړه("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        حرف*c1 = 1 + حجم(tab1) + (حرف*)tab1;
        حرف*c2 = 1 + حجم(tab2) + (حرف*)tab2;
        چاپ_کړه("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        چاپ_کړه("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        صحيح *i1 = tab1[-1];
        صحيح *i2 = tab2[-1];
        چاپ_کړه("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        چاپ_کړه("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        صحيح *x1 = tab1[size1 * size2 + 1];
        صحيح *x2 = tab2[10 + 1];
        چاپ_کړه("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        چاپ_کړه("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } وإلا {
        چاپ_کړه("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    چاپ_کړه("\n");
}

فراغ c99_vla_test_2(صحيح d, صحيح h, صحيح w)
{
    صحيح x, y, z;
    صحيح (*arr)[h][w] = حافظه_ورکړه(حجم(صحيح) * d*h*w);
    صحيح c = 1;
    ساكن صحيح (*starr)[h][w];

    چاپ_کړه("Test C99 VLA 6 (pointer)\n");

    لكل (z=0; z<d; z++) {
        لكل (y=0; y<h; y++) {
            لكل (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    لكل (z=0; z<d; z++) {
        لكل (y=0; y<h; y++) {
            لكل (x=0; x<w; x++) {
                چاپ_کړه(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    چاپ_کړه(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        حجم (*arr), حجم (*arr)[0], حجم (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == حجم (*arr + 1) - حجم arr,
        0 == حجم حجم *arr - حجم arr,
        starr[0][2][3] == arr[1][2][3]
        );
    حرر (arr);
}

فراغ c99_vla_test_3a (صحيح arr[2][3][4])
{
    چاپ_کړه ("%d\n", arr[1][2][3]);
}

فراغ c99_vla_test_3b(صحيح s, صحيح arr[s][3][4])
{
    چاپ_کړه ("%d\n", arr[1][2][3]);
}

فراغ c99_vla_test_3c(صحيح s, صحيح arr[2][s][4])
{
    چاپ_کړه ("%d\n", arr[1][2][3]);
}

فراغ c99_vla_test_3d(صحيح s, صحيح arr[2][3][s])
{
    چاپ_کړه ("%d\n", arr[1][2][3]);
}

فراغ c99_vla_test_3e(صحيح s, صحيح arr[][3][--s])
{
    چاپ_کړه ("%d %d %d\n", حجم arr, s, arr[1][2][3]);
}

فراغ c99_vla_test_3(فراغ)
{
    صحيح a[2][3][4];

    memset (a, 0, حجم(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

فراغ c99_vla_test(فراغ)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


فراغ sizeof_test(فراغ)
{
    صحيح a;
    صحيح **ptr;

    چاپ_کړه("sizeof(int) = %d\n", حجم(صحيح));
    چاپ_کړه("sizeof(unsigned int) = %d\n", حجم(بینښه صحيح));
    چاپ_کړه("sizeof(long) = %d\n", حجم(اوږد));
    چاپ_کړه("sizeof(unsigned long) = %d\n", حجم(بینښه اوږد));
    چاپ_کړه("sizeof(short) = %d\n", حجم(لنډ));
    چاپ_کړه("sizeof(unsigned short) = %d\n", حجم(بینښه لنډ));
    چاپ_کړه("sizeof(char) = %d\n", حجم(حرف));
    چاپ_کړه("sizeof(unsigned char) = %d\n", حجم(بینښه حرف));
    چاپ_کړه("sizeof(func) = %d\n", حجم sizeof_test());
    a = 1;
    چاپ_کړه("sizeof(a++) = %d\n", حجم a++);
    چاپ_کړه("a=%d\n", a);
    ptr = عدم;
    چاپ_کړه("sizeof(**ptr) = %d\n", حجم (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    چاپ_کړه("sizeof(sizeof(int) = %d\n", حجم(حجم(صحيح)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -حجم(uintptr_t);
    چاپ_کړه ("%lu %lu\n", t, t2);

    /* some alignof tests */
    چاپ_کړه("__alignof__(int) = %d\n", __alignof__(صحيح));
    چاپ_کړه("__alignof__(unsigned int) = %d\n", __alignof__(بینښه صحيح));
    چاپ_کړه("__alignof__(short) = %d\n", __alignof__(لنډ));
    چاپ_کړه("__alignof__(unsigned short) = %d\n", __alignof__(بینښه لنډ));
    چاپ_کړه("__alignof__(char) = %d\n", __alignof__(حرف));
    چاپ_کړه("__alignof__(unsigned char) = %d\n", __alignof__(بینښه حرف));
    چاپ_کړه("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    چاپ_کړه("sizeof(char[1+2*a]) = %d\n", حجم(حرف[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    چاپ_کړه("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   حجم( (بنية {صحيح i; صحيح j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    چاپ_کړه("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   حجم (بنية {لنډ i; لنډ j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    چاپ_کړه("sizeof(t && 0) = %d\n", حجم(t && 0));
    چاپ_کړه("sizeof(1 && 1) = %d\n", حجم(1 && 1));
    چاپ_کړه("sizeof(t || 1) = %d\n", حجم(t || 1));
    چاپ_کړه("sizeof(0 || 0) = %d\n", حجم(0 || 0));

    صحيح arr[4], fn();
    چاپ_کړه("sizeof(0, arr) = %d\n", حجم(0, arr));
    چاپ_کړه("sizeof(0, fn) = %d\n", حجم(0, fn));
}

فراغ typeof_test(فراغ)
{
    مزدوج a;
    typeof(a) b;
    typeof(عائم) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    چاپ_کړه("a=%f b=%f c=%f\n", a, b, c);
}


بنية hlist_غوټه;
بنية hlist_سر {
    بنية hlist_غوټه *لومړی, *وروستی;
};

فراغ consume_ulong (بینښه اوږد i)
{
    i = 0;
}

فراغ statement_بیان_test(فراغ)
{
    صحيح a, i;

    /* Basic stmt expr test */
    a = 0;
    لكل(i=0;i<10;i++) {
        a += 1 + 
            ( { صحيح b, j; 
                b = 0; 
                لكل(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    چاپ_کړه("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    فراغ *v = (فراغ*)39;
    typeof(({
	    (بنية hlist_غوټه *)v;
	    })) x;
    typeof (x)
	ptr = (بنية hlist_غوټه *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#تعریف_کړه some_attr     __attribute__((aligned(1)))
#تعریف_کړه tps(str) ({                  \
            ساكن ثابت حرف *t some_attr = str; \
            t;                                    \
          })
    چاپ_کړه ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    صحيح t = 40;
    صحيح b = ({ صحيح t = 41; t; });
    صحيح c = ({ صحيح t = 42; t; });

    /* Test that aggregate return values work.  */
    بنية hlist_سر h
	= ({
	   تعريفنوع بنية hlist_سر T;
	   اوږد pre = 48;
	   T t = { (فراغ*)43, (فراغ*)44 };
	   اوږد post = 49;
	   t;
	   });
    چاپ_کړه ("stmtexpr: %d %d %d\n", t, b, c);
    چاپ_کړه ("stmtexpr: %ld %ld\n", (اوږد)h.لومړی, (اوږد)h.وروستی);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (بینښه اوږد)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: إذا (i++ == 0) اذهب LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      اذهب LBL;
    });
  LBL:
    چاپ_کړه("stmtexpr: %d should be 2\n", i);
}

فراغ local_label_test(فراغ)
{
    صحيح a;
    اذهب l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        اذهب l1;
    l4:
        چاپ_کړه("aa1\n");
        اذهب l3;
    l2:
        چاپ_کړه("aa3\n");
        اذهب l4;
    l1:
        چاپ_کړه("aa2\n");
        اذهب l2;
    l3:;
        1;
    });
    چاپ_کړه("a=%d\n", a);
    أرجع;
 l4:
    چاپ_کړه("bb1\n");
    اذهب l2;
 l1:
    چاپ_کړه("bb2\n");
    اذهب l4;
}

/* inline assembler test */
#إذا (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

تعريفنوع __SIZE_TYPE__ کلمه;

/* from linux kernel */
ساكن حرف * strncat1(حرف * dest,ثابت حرف * src,اندازه_t شمېر_2)
{
کلمه d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (شمېر_2)
	: "memory");
أرجع dest;
}

ساكن حرف * strncat2(حرف * dest,ثابت حرف * src,اندازه_t شمېر_2)
{
کلمه d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (شمېر_2)
	: "memory");
أرجع dest;
}

ساكن مضمن فراغ * memcpy1(فراغ * منزل, ثابت فراغ * from, اندازه_t n)
{
کلمه d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((کلمه) منزل),"2" ((کلمه) from)
	: "memory");
أرجع (منزل);
}

ساكن مضمن فراغ * memcpy2(فراغ * منزل, ثابت فراغ * from, اندازه_t n)
{
کلمه d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((کلمه) منزل),"2" ((کلمه) from)
	: "memory");
أرجع (منزل);
}

ساكن __inline__ فراغ sigaddset1(بینښه صحيح *سېټ, صحيح _sig)
{
	__asm__("btsl %1,%0" : "=m"(*سېټ) : "Ir"(_sig - 1) : "cc");
}

ساكن __inline__ فراغ sigdelset1(بینښه صحيح *سېټ, صحيح _sig)
{
	asm("btrl %1,%0" : "=m"(*سېټ) : "Ir"(_sig - 1) : "cc", "flags");
}

#که_تعریف_شوی __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ساكن __inline__ __const__ بینښه صحيح swab32(بینښه صحيح x)
{
        أرجع ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#وإلا
ساكن __inline__ __const__ بینښه صحيح swab32(بینښه صحيح x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	أرجع x;
}
#د_که_پای

ساكن __inline__ بینښه اوږد اوږد mul64(بینښه صحيح a, بینښه صحيح b)
{
    بینښه اوږد اوږد res;
#که_تعریف_شوی __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    بینښه صحيح resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((بینښه اوږد اوږد)resh << 32) | resl;
#وإلا
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#د_که_پای
    أرجع res;
}

ساكن __inline__ بینښه اوږد اوږد inc64(بینښه اوږد اوږد a)
{
    بینښه اوږد اوږد res;
#که_تعریف_شوی __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#وإلا
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#د_که_پای
    أرجع res;
}

بنية struct123 {
    صحيح a;
    صحيح b;
};
بنية struct1231 {
    کلمه addr;
};

کلمه mconstraint_test(بنية struct1231 *r)
{
    کلمه ret;
    بینښه صحيح a[2];
    a[0] = 0;
    __asm__ متطاير ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(بنية struct123 *)r->addr));
    أرجع ret + a[0];
}

#که_تعریف_شوی __x86_64__
صحيح fls64(بینښه اوږد اوږد x)
{
  صحيح bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  أرجع bitpos + 1;
}
#د_که_پای

فراغ other_constraints_test(فراغ)
{
    کلمه ret;
    صحيح var;
#إذا CC_NAME != CC_clang
    __asm__ متطاير ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    چاپ_کړه ("oc1: %d\n", ret == (کلمه)&var);
#د_که_پای
}

#که_نه_تعریف_شوی _WIN32
/* Test global asm blocks playing with aliases.  */
فراغ بنسټ_func(فراغ)
{
  چاپ_کړه ("asmc: base\n");
}

#که_نه_تعریف_شوی __APPLE__
خارجي فراغ override_func1 (فراغ);
خارجي فراغ override_func2 (فراغ);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

فراغ override_func2 (فراغ)
{
  چاپ_کړه ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
خارجي صحيح bug_جدول[] __attribute__((section("__bug_table")));
حرف * get_asm_string (فراغ)
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
#که_نه_تعریف_شوی __clang__
  خارجي صحيح some_نښه;
  asm متطاير (".globl some_symbol\n"
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
  حرف * str = ((حرف*)bug_جدول) + bug_جدول[1];
  أرجع str;
#وإلا
  أرجع (حرف *) "A string";
#د_که_پای
}

/* This checks another constructs with local labels.  */
خارجي بینښه حرف alld_stuff[];
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

فراغ asm_local_label_diff (فراغ)
{
  چاپ_کړه ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#د_که_پای //!__APPLE__
#د_که_پای //!_WIN32

/* This checks that static local variables are available from assembler.  */
فراغ asm_local_statics (فراغ)
{
  ساكن صحيح localint = 41;
  asm("incl %0" : "+m" (localint));
  چاپ_کړه ("asm_local_statics: %d\n", localint);
}

ساكن
بینښه صحيح سېټ;

فراغ fancy_copy (بینښه *دننه, بینښه *بهر)
{
  asm متطاير ("" : "=r" (*بهر) : "0" (*دننه));
}

فراغ fancy_copy2 (بینښه *دننه, بینښه *بهر)
{
  asm متطاير ("mov %0,(%1)" : : "r" (*دننه), "r" (بهر) : "memory");
}

#إذا defined __x86_64__
فراغ clobber_r12(فراغ)
{
    asm متطاير("mov $1, %%r12" ::: "r12");
}
#د_که_پای

فراغ test_لوړ_clobbers_really(فراغ)
{
#إذا defined __x86_64__
    سجل کلمه val asm("r12");
    کلمه val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm متطاير("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm متطاير("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    چاپ_کړه("asmhc: 0x%x\n", val2);
#د_که_پای
}

فراغ test_لوړ_clobbers(فراغ)
{
#إذا defined __x86_64__
    کلمه x1, x2;
    asm متطاير("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_لوړ_clobbers_really();
    asm متطاير("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm متطاير("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#د_که_پای
}

ساكن اوږد cpu_شمېره;
فراغ trace_console(اوږد len, اوږد len2)
{
#که_تعریف_شوی __x86_64__
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
    إذا (0
        &&
            ({
              اوږد pscr_ret__;
              بدل(len) {
                حالة 4:
                    {
                       اوږد pfo_ret__;
                       بدل (len2) {
                         حالة 8:	چاپ_کړه("bla"); pfo_ret__ = 42; اكسر;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  اكسر;
                حالة 8:
                    {
                       اوږد pfo_ret__;
                       بدل (len2) {
                         حالة 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_شمېره));	اكسر;
                         حالة 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_شمېره));	اكسر;
                         حالة 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_شمېره));	اكسر;
                         حالة 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_شمېره));	اكسر;
                         افتراضي: چاپ_کړه("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  اكسر;
              }
              pscr_ret__;
            }))
      {
        چاپ_کړه("huh?\n");
      }
#د_که_پای
}

فراغ test_asm_dead_کوډ(فراغ)
{
  کلمه rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm متطاير ("" : "=D" (rdi) : "0" (0));
  (فراغ)حجم (({
      صحيح var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm متطاير ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

فراغ test_asm_call(فراغ)
{
#إذا defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ساكن حرف str[] = "PATH";
  حرف *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm متطاير ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#إذا 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#وإلا
		"call getenv;"
#د_که_پای
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  چاپ_کړه("asmd: %s\n", s);
#د_که_پای
}

#إذا defined __x86_64__
# define RX "(%rip)"
#وإلا
# define RX
#د_که_پای

فراغ asm_dot_test(فراغ)
{
#که_نه_تعریف_شوی __APPLE__
    صحيح x;
    لكل (x = 1;; ++x) {
        صحيح r = x;
        بدل (x) {
        حالة 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        حالة 2:
#که_نه_تعریف_شوی __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#وإلا
            asm(".text; mov $123, %eax; jmp p0");
#د_که_پای
	حالة 3:
#إذا !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#وإلا
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#د_که_پای
            asm(".text; mov X"RX",%eax; jmp p0");
        حالة 4:
#که_تعریف_شوی __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#وإلا
#که_نه_تعریف_شوی _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#وإلا
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#د_که_پای
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#د_که_پای
        حالة 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); اكسر;
	}
        إذا (r == x)
            اكسر;
        چاپ_کړه("asm_dot_test %d: %d\n", x, r);
    }
#د_که_پای
}

فراغ asm_pcrel_test(فراغ)
{
    بینښه o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    چاپ_کړه("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

فراغ asm_test(فراغ)
{
    حرف buf[128];
    بینښه صحيح val, val2;
    بنية struct123 s1;
    بنية struct1231 s2 = { (کلمه)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    صحيح بنسټ_func = 42;
    فراغ override_func3 (فراغ);
    کلمه asmret;
#که_تعریف_شوی BOOL_ISOC99
    _Bool somebool;
#د_که_پای
    سجل صحيح regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm متطاير ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm متطاير ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    چاپ_کړه("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    چاپ_کړه("%s\n", buf);

    /* 'A' constraint test */
    چاپ_کړه("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    چاپ_کړه("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    چاپ_کړه("mconstraint: %d", mconstraint_test(&s2));
    چاپ_کړه(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    سېټ = 0xff;
    sigdelset1(&سېټ, 2);
    sigaddset1(&سېټ, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    اذهب label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(سېټ) : "Ir"(20) : "cc");
    چاپ_کړه("set=0x%x\n", سېټ);
    val = 0x01020304;
    چاپ_کړه("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#که_نه_تعریف_شوی _WIN32
#که_نه_تعریف_شوی __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm متطاير(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    چاپ_کړه("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#د_که_پای
#د_که_پای
    asm_local_statics();
#که_نه_تعریف_شوی __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm متطاير("" : "=r" (asmret) : "0"(s2));
    إذا (asmret != s2.addr)
      چاپ_کړه("asmstr: failed\n");
#د_که_پای
#که_تعریف_شوی BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm متطاير("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    إذا (!somebool)
      چاپ_کړه("asmbool: failed\n");
#د_که_پای
    val = 43;
    fancy_copy (&val, &val2);
    چاپ_کړه ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    چاپ_کړه ("fancycpy2(%d)=%d\n", val, val2);
    asm متطاير ("mov $0x4243, %%esi" : "=r" (regvar));
    چاپ_کړه ("regvar=%x\n", regvar);
    test_لوړ_clobbers();
    trace_console(8, 8);
    test_asm_dead_کوډ();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    أرجع;
 label1:
    اذهب label2;
}

#وإلا

فراغ asm_test(فراغ)
{
}

#د_که_پای

#تعریف_کړه COMPAT_TYPE(type1, type2) \
{\
    چاپ_کړه("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

صحيح constant_p_var;

صحيح func(فراغ);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ساكن فراغ builtin_test_بټونه(بینښه اوږد اوږد x, صحيح cnt[])
{
#إذا GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    إذا ((بینښه صحيح) x) cnt[3] += __builtin_clz(x);
    إذا ((بینښه اوږد) x) cnt[4] += __builtin_clzl(x);
    إذا ((بینښه اوږد اوږد) x) cnt[5] += __builtin_clzll(x);

    إذا ((بینښه صحيح) x) cnt[6] += __builtin_ctz(x);
    إذا ((بینښه اوږد) x) cnt[7] += __builtin_ctzl(x);
    إذا ((بینښه اوږد اوږد) x) cnt[8] += __builtin_ctzll(x);

#إذا GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#د_که_پای

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#د_که_پای
}

فراغ builtin_test(فراغ)
{
    لنډ s;
    صحيح i;
    اوږد اوږد ll;
#إذا GCC_MAJOR >= 3
    COMPAT_TYPE(صحيح, صحيح);
    COMPAT_TYPE(صحيح, بینښه صحيح);
    COMPAT_TYPE(صحيح, حرف);
    COMPAT_TYPE(صحيح, ثابت صحيح);
    COMPAT_TYPE(صحيح, متطاير صحيح);
    COMPAT_TYPE(صحيح[2], ثابت صحيح[2]);
    COMPAT_TYPE(صحيح[2][3], متطاير صحيح[][3]);
    COMPAT_TYPE(صحيح (*)[], ثابت صحيح (*)[]);
#که_نه_تعریف_شوی __clang__
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحيح (*)[2])0 : (صحيح (*)[2])0),
                ثابت صحيح (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحيح (*)[2][3])0 :
                              (متطاير صحيح (*)[2][3])0),
                ثابت متطاير صحيح (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (متطاير صحيح (*)[2][3])0 :
                              (ثابت صحيح (*)[2][3])0),
                ثابت متطاير صحيح (*)[2][3]);
#وإلا
    /* clang doesn't combine qualifiers through array types */
    چاپ_کړه("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    چاپ_کړه("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    چاپ_کړه("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#د_که_پای
    COMPAT_TYPE(صحيح *, صحيح *);
    COMPAT_TYPE(صحيح *, فراغ *);
    COMPAT_TYPE(صحيح *, ثابت صحيح *);
    COMPAT_TYPE(حرف *, بینښه حرف *);
    COMPAT_TYPE(حرف *, نښهدار حرف *);
    COMPAT_TYPE(حرف *, حرف *);
    COMPAT_TYPE(حرف **, فراغ *);
#د_که_پای
    چاپ_کړه("res1 = %d\n", __builtin_constant_p(1));
    چاپ_کړه("res2 = %d\n", __builtin_constant_p(1 + 2));
    چاپ_کړه("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    چاپ_کړه("res4 = %d\n", __builtin_constant_p(constant_p_var));
    چاپ_کړه("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    چاپ_کړه("res6 = %d\n", __builtin_constant_p(i && 1));
    چاپ_کړه("res7 = %d\n", __builtin_constant_p("hi"));
    چاپ_کړه("res8 = %d\n", __builtin_constant_p(func()));
#که_نه_تعریف_شوی __clang__
    چاپ_کړه("res10 = %d\n", __builtin_constant_p(i && 0));
    چاپ_کړه("res11 = %d\n", __builtin_constant_p(i * 0));
    چاپ_کړه("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    چاپ_کړه("res13 = %d\n", __builtin_constant_p((1,7)));
#وإلا
    /* clang doesn't regard these as constant expression */
    چاپ_کړه("res10 = 1\n");
    چاپ_کړه("res11 = 1\n");
    چاپ_کړه("res12 = 1\n");
    چاپ_کړه("res13 = 0\n");
#د_که_پای

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    چاپ_کړه("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    چاپ_کړه("bce: %d\n", i);
    i = حجم (__builtin_choose_expr (1, ll, s));
    چاپ_کړه("bce: %d\n", i);
    i = حجم (__builtin_choose_expr (0, ll, s));
    چاپ_کړه("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	صحيح cnt[18];
	بینښه اوږد اوږد r = 0;

	memset(cnt, 0, حجم(cnt));
	builtin_test_بټونه(0, cnt);
	builtin_test_بټونه(0xffffffffffffffffull, cnt);
        لكل (i = 0; i < 64; i++)
	    builtin_test_بټونه(1ull << i, cnt);
        لكل (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_بټونه(r, cnt);
	}
	لكل (i = 0; i < 18; i++)
	    چاپ_کړه ("%d %d\n", i, cnt[i]);
    }
}

#إذا defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
فراغ weak_test(فراغ) {}
#وإلا
خارجي صحيح __attribute__((weak)) weak_f1(فراغ);
خارجي صحيح __attribute__((weak)) weak_f2(فراغ);
خارجي صحيح                       weak_f3(فراغ);
خارجي صحيح __attribute__((weak)) weak_v1;
خارجي صحيح __attribute__((weak)) weak_v2;
خارجي صحيح                       weak_v3;

خارجي صحيح                           (*weak_fpa)() __attribute__((weak));
خارجي صحيح __attribute__((weak))     (*weak_fpb)();
خارجي     __attribute__((weak)) صحيح (*weak_fpc)();

خارجي صحيح                     weak_asm_f1(فراغ) asm("weak_asm_f1x") __attribute((weak));
خارجي صحيح __attribute((weak)) weak_asm_f2(فراغ) asm("weak_asm_f2x")                    ;
خارجي صحيح __attribute((weak)) weak_asm_f3(فراغ) asm("weak_asm_f3x") __attribute((weak));
خارجي صحيح                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
خارجي صحيح __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
خارجي صحيح __attribute((weak)) weak_asm_v3(فراغ) asm("weak_asm_v3x") __attribute((weak));

#که_نه_تعریف_شوی __clang__
ساكن ثابت اندازه_t dummy = 0;
خارجي __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
خارجي __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
خارجي __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#د_که_پای

صحيح some_lib_func(فراغ);
صحيح dummy_impl_د_slf(فراغ) { أرجع 444; }
#که_نه_تعریف_شوی __clang__
صحيح some_lib_func(فراغ) __attribute__((weak, alias("dummy_impl_of_slf")));
#د_که_پای

صحيح weak_toolate() __attribute__((weak));
صحيح weak_toolate() { أرجع 0; }

فراغ __attribute__((weak)) weak_test(فراغ)
{
	چاپ_کړه("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	چاپ_کړه("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	چاپ_کړه("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	چاپ_کړه("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	چاپ_کړه("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	چاپ_کړه("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	چاپ_کړه("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	چاپ_کړه("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	چاپ_کړه("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	چاپ_کړه("weak_asm_f1=%d\n", weak_asm_f1 != عدم);
	چاپ_کړه("weak_asm_f2=%d\n", weak_asm_f2 != عدم);
	چاپ_کړه("weak_asm_f3=%d\n", weak_asm_f3 != عدم);
	چاپ_کړه("weak_asm_v1=%d\n",&weak_asm_v1 != عدم);
	چاپ_کړه("weak_asm_v2=%d\n",&weak_asm_v2 != عدم);
	چاپ_کړه("weak_asm_v3=%d\n",&weak_asm_v3 != عدم);
#که_تعریف_شوی __clang__
	چاپ_کړه("some_lib_func=444\n");
#وإلا
	چاپ_کړه("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#د_که_پای
}

صحيح __attribute__((weak)) weak_f2() { أرجع 222; }
صحيح __attribute__((weak)) weak_f3() { أرجع 333; }
صحيح __attribute__((weak)) weak_v2 = 222;
صحيح __attribute__((weak)) weak_v3 = 333;
#د_که_پای

فراغ const_func(ثابت صحيح a)
{
}

فراغ const_warn_test(فراغ)
{
    const_func(1);
}

بنية condstruct {
  صحيح i;
};

صحيح getme (بنية condstruct *s, صحيح i)
{
  صحيح i1 = (i == 0 ? 0 : s)->i;
  صحيح i2 = (i == 0 ? s : 0)->i;
  صحيح i3 = (i == 0 ? (فراغ*)0 : s)->i;
  صحيح i4 = (i == 0 ? s : (فراغ*)0)->i;
  أرجع i1 + i2 + i3 + i4;
}

بنية global_معلومات
{
  صحيح a[40];
  صحيح *b[40];
};

بنية global_معلومات global_معلومات;

صحيح global_معلومات_getstuff (صحيح *, صحيح);

فراغ global_معلومات_callit (صحيح i)
{
  *global_معلومات.b[i] = global_معلومات_getstuff (global_معلومات.b[i], 1);
}

صحيح global_معلومات_getstuff (صحيح *p, صحيح i)
{
  أرجع *p + i;
}

فراغ global_معلومات_test (فراغ)
{
  global_معلومات.a[0] = 42;
  global_معلومات.b[0] = &global_معلومات.a[0];
  global_معلومات_callit (0);
  چاپ_کړه ("%d\n", global_معلومات.a[0]);
}

بنية cmpcmpS
{
  بینښه حرف fill : 3;
  بینښه حرف b1 : 1;
  بینښه حرف b2 : 1;
  بینښه حرف fill2 : 3;
};

صحيح glob1, glob2, glob3;

فراغ compare_comparisons (بنية cmpcmpS *s)
{
  إذا (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    چاپ_کړه ("comparing comparisons broken\n");
}

فراغ cmp_comparison_test(فراغ)
{
  بنية cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

صحيح fcompare (مزدوج a, مزدوج b, صحيح کوډ)
{
  بدل (کوډ) {
    حالة 0: أرجع a == b;
    حالة 1: أرجع a != b;
    حالة 2: أرجع a < b;
    حالة 3: أرجع a >= b;
    حالة 4: أرجع a > b;
    حالة 5: أرجع a <= b;
  }
  أرجع 0;
}

فراغ math_cmp_test(فراغ)
{
  مزدوج nan = 0.0/0.0;
  مزدوج one = 1.0;
  مزدوج two = 2.0;
  صحيح comp = 0;
  صحيح v;
#تعریف_کړه bug(a,b,op,iop,part) چاپ_کړه("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#تعریف_کړه FCMP(a,b,op,iop,کوډ) \
  إذا (fcompare (a,b,کوډ))    \
    bug (a,b,op,iop,1); \
  إذا (a op b) \
    bug (a,b,op,iop,2); \
  إذا (a iop b) \
    ; \
  وإلا \
    bug (a,b,op,iop,3); \
  إذا ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  إذا ((a iop b) || comp) \
    ; \
  وإلا \
    bug (a,b,op,iop,5); \
  إذا (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  إذا (!fcompare (nan, nan, 1))
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

مزدوج get100 () { أرجع 100.0; }

فراغ callsave_test(فراغ)
{
  صحيح i, s; مزدوج *d; مزدوج t;
  s = حجم (مزدوج);
  چاپ_کړه ("callsavetest: %d\n", s);
  d = alloca (حجم(مزدوج));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  چاپ_کړه ("%d\n", i);
}


فراغ bfa3(ptrdiff_t str_دننه_واټن)
{
    چاپ_کړه("bfa3: %s\n", (حرف *)__builtin_frame_address(3) + str_دننه_واټن);
}
فراغ bfa2(ptrdiff_t str_دننه_واټن)
{
    چاپ_کړه("bfa2: %s\n", (حرف *)__builtin_frame_address(2) + str_دننه_واټن);
    bfa3(str_دننه_واټن);
}
فراغ bfa1(ptrdiff_t str_دننه_واټن)
{
    چاپ_کړه("bfa1: %s\n", (حرف *)__builtin_frame_address(1) + str_دننه_واټن);
    bfa2(str_دننه_واټن);
}

فراغ builtin_چوکاټ_پته_test(فراغ)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#که_نه_تعریف_شوی __arm__
    حرف str[] = "__builtin_frame_address";
    حرف *fp0 = __builtin_frame_address(0);

    چاپ_کړه("str: %s\n", str);
#که_نه_تعریف_شوی __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#د_که_پای
#د_که_پای
}

حرف له_لارې_volatile (حرف i)
{
  حرف متطاير vi;
  vi = i;
  أرجع vi;
}

فراغ volatile_test(فراغ)
{
    إذا (له_لارې_volatile (42) != 42)
      چاپ_کړه (" broken\n");
    وإلا
      چاپ_کړه (" ok\n");
}

بنية __attribute__((__packed__)) Spacked {
    حرف a;
    لنډ b;
    صحيح c;
};
بنية Spacked spacked;
تعريفنوع بنية __attribute__((__packed__)) {
    حرف a;
    لنډ b;
    صحيح c;
} Spacked2;
Spacked2 spacked2;
تعريفنوع بنية Spacked3_s {
    حرف a;
    لنډ b;
    صحيح c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
بنية gate_struct64 {
    بینښه لنډ دننه_واټن_ټیټ;
    بینښه لنډ segment;
    بینښه ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    بینښه لنډ دننه_واټن_منځ;
    بینښه دننه_واټن_لوړ;
    بینښه zero1;
} __attribute__((packed));
تعريفنوع بنية gate_struct64 gate_desc;
gate_desc a_gate_desc;
فراغ attrib_test(فراغ)
{
#که_نه_تعریف_شوی _WIN32
  چاپ_کړه("attr: %d %d %d %d\n", حجم(بنية Spacked),
	 حجم(spacked), حجم(Spacked2), حجم(spacked2));
  چاپ_کړه("attr: %d %d\n", حجم(Spacked3), حجم(spacked3));
  چاپ_کړه("attr: %d %d\n", حجم(gate_desc), حجم(a_gate_desc));
#د_که_پای
}
خارجي __attribute__((__unused__)) حرف * __attribute__((__unused__)) *
strange_attrib_placement (فراغ);

فراغ * __attribute__((__unused__)) get_void_ptr (فراغ *a)
{
  أرجع a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ساكن مضمن
صحيح __get_order(بینښه اوږد اوږد اندازه)
{
  صحيح ترتیب;
  اندازه -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      بنية S { صحيح i : 1; } s; // constructed for this '1'
    }
  ترتیب = اندازه;
  أرجع ترتیب;
}

/* This just forces the above inline function to be actually emitted.  */
صحيح force_get_ترتیب(بینښه اوږد s)
{
    أرجع __get_order(s);
}

#تعریف_کړه pv(m) چاپ_کړه(حجم (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
فراغ bounds_check1_test (فراغ)
{
    بنية s {
        صحيح x;
        اوږد اوږد y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
فراغ map_جمع_کړه(صحيح a, صحيح b, صحيح c, صحيح d, صحيح e, صحيح f, صحيح g, صحيح h, صحيح i)
{
  چاپ_کړه ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

فراغ func_arg_test(فراغ)
{
    صحيح a = 0;
    صحيح b = 1;
    map_جمع_کړه(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#تعریف_کړه CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#که_تعریف_شوی __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#د_که_پای

#تعریف_کړه	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
فراغ whitespace_test(فراغ)
{
    حرف *str;
    صحيح tcc_test = 1;

#إذا 1
    pri\
ntf("whitspace:\n");
#د_که_پای
    pf("N=%d\n", 2);

#که_تعریف_شوی CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#د_که_پای

    pri\
\
ntf("min=%d\n", 4);

#که_تعریف_شوی ACCEPT_LF_دننه_مزي_ګانې
    چاپ_کړه("len1=%d\n", مزي_اوږدوالی("
"));
#که_تعریف_شوی CORRECT_CR_HANDLING
    str = "
";
    چاپ_کړه("len1=%d str[0]=%d\n", مزي_اوږدوالی(str), str[0]);
#د_که_پای
    چاپ_کړه("len1=%d\n", مزي_اوږدوالی("a
"));
#وإلا
    چاپ_کړه("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#د_که_پای /* ACCEPT_LF_IN_STRINGS */

#که_تعریف_شوی __LINE__
    چاپ_کړه("__LINE__ defined\n");
#د_که_پای

#إذا 0
    /* wrong with GCC */
    چاپ_کړه("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#کرښه 1111
    چاپ_کړه("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#کرښه 2222 "test"
    چاپ_کړه("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#د_که_پای

    چاپ_کړه("\\
"12\\
063\\
n 456\"\n");

    چاپ_کړه ("%d\n",
#إذا 1
	    tcc_test
#د_که_پای
            );

}

#تعریف_کړه پرلپسې_2(test) puts("---- " #test " ----"), test(), puts("")

صحيح اصلي(صحيح argc, حرف **argv)
{
    پرلپسې_2(whitespace_test);
    پرلپسې_2(macro_test);
    پرلپسې_2(recursive_macro_test);
    پرلپسې_2(string_test);
    پرلپسې_2(بیان_test);
    پرلپسې_2(scope_test);
    پرلپسې_2(scope2_test);
    پرلپسې_2(forward_test);
    پرلپسې_2(funcptr_test);
    پرلپسې_2(if_test);
    پرلپسې_2(loop_test);
    پرلپسې_2(switch_test);
    پرلپسې_2(goto_test);
    پرلپسې_2(enum_test);
    پرلپسې_2(typedef_test);
    پرلپسې_2(struct_test);
    پرلپسې_2(array_test);
    پرلپسې_2(بیان_ptr_test);
    پرلپسې_2(bool_test);
    پرلپسې_2(optimize_بهر_test);
    پرلپسې_2(expr2_test);
    پرلپسې_2(constant_بیان_test);
    پرلپسې_2(بیان_cmp_test);
    پرلپسې_2(char_short_test);
    پرلپسې_2(init_test);
    پرلپسې_2(compound_literal_test);
    پرلپسې_2(kr_test);
    پرلپسې_2(struct_ټاکل_test);
    پرلپسې_2(cast_test);
    پرلپسې_2(bitfield_test);
    پرلپسې_2(c99_bool_test);
    پرلپسې_2(float_test);
    پرلپسې_2(longlong_test);
    پرلپسې_2(manyarg_test);
    پرلپسې_2(stdarg_test);
    پرلپسې_2(relocation_test);
    پرلپسې_2(old_style_function_test);
    پرلپسې_2(alloca_test);
    پرلپسې_2(c99_vla_test);
    پرلپسې_2(sizeof_test);
    پرلپسې_2(typeof_test);
    پرلپسې_2(statement_بیان_test);
    پرلپسې_2(local_label_test);
    پرلپسې_2(asm_test);
    پرلپسې_2(builtin_test);
    پرلپسې_2(weak_test);
    پرلپسې_2(global_معلومات_test);
    پرلپسې_2(cmp_comparison_test);
    پرلپسې_2(math_cmp_test);
    پرلپسې_2(callsave_test);
    پرلپسې_2(builtin_چوکاټ_پته_test);
    پرلپسې_2(volatile_test);
    پرلپسې_2(attrib_test);
    پرلپسې_2(bounds_check1_test);
    پرلپسې_2(func_arg_test);

    أرجع 0;
}
