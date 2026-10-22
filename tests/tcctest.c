/*
 * TCC auto test program
 */
#شامل "config.h"

/* identify the configured reference compiler in use */
#تعریف_کرو CC_gcc 1
#تعریف_کرو CC_clang 2
#تعریف_کرو CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#تعریف_کرو ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#تعریف_کرو BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#تعریف_کرو C99_MACROS

#اگر defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#تعریف_کرو LONG_LONG_FORMAT "%lld"
#تعریف_کرو ULONG_LONG_FORMAT "%llu"
#تعریف_کرو XLONG_LONG_FORMAT "%llx"
#ورنہ
#تعریف_کرو LONG_LONG_FORMAT "%Ld"
#تعریف_کرو ULONG_LONG_FORMAT "%Lu"
#تعریف_کرو XLONG_LONG_FORMAT "%Lx"
#اگر_ختم

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#اگر defined(_WIN32)
#تعریف_کرو LONG_DOUBLE دوہرا
#تعریف_کرو LONG_DOUBLE_LITERAL(x) x
#ورنہ
#تعریف_کرو LONG_DOUBLE طویل دوہرا
#تعریف_کرو LONG_DOUBLE_LITERAL(x) x ## L
#اگر_ختم

قسمتعریف __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#تعریف_کرو TCCLIB_INC <tcclib.h>
#تعریف_کرو TCCLIB_INC1 <tcclib
#تعریف_کرو TCCLIB_INC2 h>
#تعریف_کرو TCCLIB_INC3 "tcclib.h"

#شامل TCCLIB_INC

#شامل TCCLIB_INC1.TCCLIB_INC2

#شامل TCCLIB_INC1.h>

#شامل TCCLIB_INC3

#شامل <tcclib.h>

#شامل "tcclib.h"

#شامل "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#تعریف_کرو INC(name) <tests/name.h>
#تعریف_کرو funnyname 42test.h
#تعریف_کرو incdir tests/
#اگر_تعریف_شدہ __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#تعریف_کرو incname <tests/42test.h>
#ورنہ
#تعریف_کرو incname < incdir funnyname >
#اگر_ختم
#تعریف_کرو __stringify(x) #x
#تعریف_کرو stringify(x) __stringify(x)
#شامل INC(42test)
#شامل incname
#شامل stringify(funnyname)

صحیح fib(صحیح n);
خالی عدد(صحیح n);
خالی forward_ref(خالی);
صحیح isid(صحیح c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
خالی funny_سطر_continuation (صحیح, ..\
. );

#تعریف_کرو A 2
#تعریف_کرو N 1234 + A
#تعریف_کرو pf لکھو
#تعریف_کرو M1(a, b)  (a) + (b)

#تعریف_کرو str\
(s) # s
#تعریف_کرو glue(a, b) a ## b
#تعریف_کرو xglue(a, b) glue(a, b)
#تعریف_کرو HIGHLOW "hello"
#تعریف_کرو کم_2 کم_2 ", world"

ساکن صحیح onetwothree = 123;
#تعریف_کرو onetwothree4 onetwothree
#تعریف_کرو onetwothree xglue(onetwothree,4)

#تعریف_کرو min(a, b) ((a) < (b) ? (a) : (b))

#اگر_تعریف_شدہ C99_MACROS
#تعریف_کرو dprintf(level,...) لکھو(__VA_ARGS__)
#اگر_ختم

/* gcc vararg macros */
#تعریف_کرو dprintf1(level, fmt, دلائل...) لکھو(fmt, ## دلائل)

#تعریف_کرو MACRO_NOARGS()

#تعریف_کرو TEST_CALL(f, ...) f(__VA_ARGS__)
#تعریف_کرو TEST_CONST()      123

#تعریف_کرو AAA 3
#تعریف_منسوخ AAA
#تعریف_کرو AAA 4

#اگر 1
#تعریف_کرو B3 1
#وگرنہ_اگر 1
#تعریف_کرو B3 2
#وگرنہ_اگر 0
#تعریف_کرو B3 3
#ورنہ
#تعریف_کرو B3 4
#اگر_ختم

#تعریف_کرو __INT64_C(c)	c ## LL
#تعریف_کرو INT64_MIN	(-__INT64_C(9223372036854775807)-1)

صحیح qq(صحیح x)
{
    واپس x + 40;
}
#تعریف_کرو qq(x) x

#تعریف_کرو spin_تالا(تالا) کرو { } جب (0)
#تعریف_کرو wq_spin_تالا spin_تالا
#تعریف_کرو TEST2() wq_spin_تالا(a)

خالی macro_test(خالی)
{
    pf("N=%d\n", N);
    لکھو("aaa=%d\n", AAA);

    لکھو("min=%d\n", min(1, min(2, -1)));

    لکھو("s1=%s\n", glue(بلند_2, کم_2));
    لکھو("s2=%s\n", xglue(بلند_2, کم_2));
    لکھو("s3=%s\n", str("c"));
    لکھو("s4=%s\n", str(a1));
    لکھو("B3=%d\n", B3);

    لکھو("onetwothree=%d\n", onetwothree);

#اگر_تعریف_شدہ A
    لکھو("A defined\n");
#اگر_ختم
#اگر_تعریف_شدہ B
    لکھو("B defined\n");
#اگر_ختم
#اگر_تعریف_شدہ A
    لکھو("A defined\n");
#ورنہ
    لکھو("A not defined\n");
#اگر_ختم
#اگر_تعریف_شدہ B
    لکھو("B defined\n");
#ورنہ
    لکھو("B not defined\n");
#اگر_ختم

#اگر_تعریف_شدہ A
    لکھو("A defined\n");
#اگر_تعریف_شدہ B
    لکھو("B1 defined\n");
#ورنہ
    لکھو("B1 not defined\n");
#اگر_ختم
#ورنہ
    لکھو("A not defined\n");
#اگر_تعریف_شدہ B
    لکھو("B2 defined\n");
#ورنہ
    لکھو("B2 not defined\n");
#اگر_ختم
#اگر_ختم

#اگر 1+1
    لکھو("test true1\n");
#اگر_ختم
#اگر 0
    لکھو("test true2\n");
#اگر_ختم
#اگر 1-1
    لکھو("test true3\n");
#اگر_ختم
#اگر defined(A)
    لکھو("test trueA\n");
#اگر_ختم
#اگر defined(B)
    لکھو("test trueB\n");
#اگر_ختم

#اگر 0
    لکھو("test 0\n");
#وگرنہ_اگر 0
    لکھو("test 1\n");
#وگرنہ_اگر 2
    لکھو("test 2\n");
#ورنہ
    لکھو("test 3\n");
#اگر_ختم

    MACRO_NOARGS();

    لکھو("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#اگر_تعریف_شدہ C99_MACROS
    لکھو("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#اگر_ختم
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    لکھو("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    لکھو("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        صحیح a;
        a = 1;
        glue(a+, +);
        لکھو("a=%d\n", a);
        glue(a <, <= 2);
        لکھو("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#تعریف_کرو MF_s MF_hello
#تعریف_کرو MF_hello(پیغام) لکھو("%s\n",پیغام)

#تعریف_کرو MF_t لکھو("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    لکھو("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#تعریف_کرو qq1(x) 1
    لکھو("qq1=%d\n", qq1( ));

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

    لکھو("basefromheader %s\n", get_basefile_from_سرخی());
    لکھو("base %s\n", __BASE_FILE__);
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ثابت حرف *fn = get_file_from_سرخی();
      اگر (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      لکھو("filefromheader %s\n", fn);
    }
#اگر_ختم

    لکھو("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_دوسرا = 1;
    have_included_42test_h_تیسرا = 1;

    /* Check that we don't complain about stray \ here */
    لکھو("print a backslash: %s\n", stringify(\\));
}


ساکن خالی print_عدد(حرف *fn, صحیح سطر, صحیح عدد) {
    لکھو("fn %s, line %d, num %d\n", fn, سطر, عدد);
}

خالی recursive_macro_test(خالی)
{

#تعریف_کرو ELF32_ST_TYPE(val)              ((val) & 0xf)
#تعریف_کرو ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#تعریف_کرو STB_WEAK        2               /* Weak symbol */
#تعریف_کرو ELFW(type) ELF##32##_##type
    لکھو("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#تعریف_کرو WRAP(x) x
    
#تعریف_کرو print_عدد(x) print_عدد(__FILE__,__LINE__,x)
    print_عدد(123);
    WRAP(print_عدد(123));
    WRAP(WRAP(print_عدد(123)));

ساکن ساخت recursive_macro { صحیح rm_میدان; } G;
#تعریف_کرو rm_میدان (G.rm_میدان)
    لکھو("rm_field = %d\n", rm_میدان);
    لکھو("rm_field = %d\n", WRAP(rm_میدان));
    WRAP((لکھو("rm_field = %d %d\n", rm_میدان, WRAP(rm_میدان))));
}

#اگر __TINYC__
صحیح op(a, b)
{
    واپس a / b;
}

صحیح ret(a)
{
    اگر (a == 2)
        واپس 1;
    اگر (a == 3)
        واپس 2;
    واپس 0;
}
#اگر_ختم

#اگر !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#تعریف_کرو CONSTANTINDEXEDSTRLIT
#اگر_ختم
حرف str_ag1[] = "b";
حرف str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#اگر_تعریف_شدہ CONSTANTINDEXEDSTRLIT
حرف str_ag3[] = { "ab"[1], 0 };
حرف str_x[2] = { "xy" "z"[2], 0 };
#اگر_ختم
حرف *str_ar[] = { "one", "two" };
ساخت str_SS {غیرعلامتی حرف a[3], b; };
ساخت str_SS str_sinit15 = { "r" };
ساخت str_SS str_sinit16[] = { { "q" }, 2 };

ساکن خالی string_test2()
{
    حرف *p = "hello";
    حرف a3[2] = { "p" };
    حرف a4[2] = { "ab" "c"[2], 0 };
    حرف *pa1 = "def" + 1;
    حرف *pa2 = { "xyz" + 1 };
    صحیح i = 0;
    ساخت str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#اگر_غیر_تعریف_شدہ CONSTANTINDEXEDSTRLIT
    حرف str_ag3[] = { "ab"[1], 0 };
    حرف str_x[2] = { "xy" "z"[2], 0 };
#اگر_ختم
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
    لکھو("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

خالی ps(ثابت حرف *s)
{
    صحیح c;
    جب (1) {
        c = *s;
        اگر (c == 0)
            توڑو;
        لکھو("%c", c);
        s++;
    }
}

ثابت حرف foo1_string[] = "\
bar\n\
test\14\
1";

خالی string_test()
{
    غیرعلامتی صحیح b;
    لکھو("string:\n");
    لکھو("\141\1423\143\n");/* dezdez test */
    لکھو("\x41\x42\x43\x3a\n");
    لکھو("c=%c\n", 'r');
    لکھو("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    لکھو("foo1_string='%s'\n", foo1_string);
#اگر 0
    لکھو("wstring=%S\n", L"abc");
    لکھو("wstring=%S\n", L"abc" L"def" "ghi");
    لکھو("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    لکھو("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#اگر_ختم
    ps("test\n");
    b = 32;
    جب ((b = b + 1) < 96) {
        لکھو("%c", b);
    }
    لکھو("\n");
    لکھو("fib=%d\n", fib(33));
    b = 262144;
    جب (b != 0x80000000) {
        عدد(b);
        b = b * 2;
    }
    string_test2();
}


خالی if1t(صحیح n, صحیح a, صحیح b, صحیح c)
{
    اگر (a && b) لکھو("if1t: %d 1 %d %d\n", n, a, b);
    اگر (a && !b) لکھو("if1t: %d 2 %d %d\n", n, a, b);
    اگر (!a && b) لکھو("if1t: %d 3 %d %d\n", n, a, b);
    اگر (!a && !b) لکھو("if1t: %d 4 %d %d\n", n, a, b);
    اگر (a || b) لکھو("if1t: %d 5 %d %d\n", n, a, b);
    اگر (a || !b) لکھو("if1t: %d 6 %d %d\n", n, a, b);
    اگر (!a || b) لکھو("if1t: %d 7 %d %d\n", n, a, b);
    اگر (!a || !b) لکھو("if1t: %d 8 %d %d\n", n, a, b);
    اگر (a && b || c) لکھو("if1t: %d 9 %d %d %d\n", n, a, b, c);
    اگر (a || b && c) لکھو("if1t: %d 10 %d %d %d\n", n, a, b, c);
    اگر (a > b - 1 && c) لکھو("if1t: %d 11 %d %d %d\n", n, a, b, c);
    اگر (a > b - 1 || c) لکھو("if1t: %d 12 %d %d %d\n", n, a, b, c);
    اگر (a > 0 && 1) لکھو("if1t: %d 13 %d %d %d\n", n, a, b, c);
    اگر (a > 0 || 0) لکھو("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

خالی if2t(خالی)
{
    اگر (0 && 1 || لکھو("if2t:ok\n") || 1)
      لکھو("if2t:ok2\n");
    لکھو("if2t:ok3\n");
}

خالی if3t(خالی)
{
    متلون طویل طویل i = 1;
    اگر (i <= 18446744073709551615ULL)
      ;
    ورنہ
      لکھو ("if3t:wrong 1\n");
}

خالی if_test(خالی)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

خالی loop_test()
{
    صحیح i;
    i = 0;
    جب (i < 10)
        لکھو("%d", i++);
    لکھو("\n");
    برائے(i = 0; i < 10;i++)
        لکھو("%d", i);
    لکھو("\n");
    i = 0;
    کرو {
        لکھو("%d", i++);
    } جب (i < 10);
    لکھو("\n");

    حرف گنتی_2 = 123;
    /* c99 for loop init test */
    برائے (سائز_t گنتی_2 = 1; گنتی_2 < 3; گنتی_2++)
        لکھو("count=%d\n", گنتی_2);
    لکھو("count = %d\n", گنتی_2);

    /* break/continue tests */
    i = 0;
    جب (1) {
        اگر (i == 6)
            توڑو;
        i++;
        اگر (i == 3)
            جاری;
        لکھو("%d", i);
    }
    لکھو("\n");

    /* break/continue tests */
    i = 0;
    کرو {
        اگر (i == 6)
            توڑو;
        i++;
        اگر (i == 3)
            جاری;
        لکھو("%d", i);
    } جب(1);
    لکھو("\n");

    برائے(i = 0;i < 10;i++) {
        اگر (i == 3)
            جاری;
        لکھو("%d", i);
    }
    لکھو("\n");
}

قسمتعریف صحیح typedef_and_label;

خالی goto_test()
{
    صحیح i;
    ساکن خالی *label_جدول[3] = { &&label1, &&label2, &&label3 };
    ساخت {
        صحیح bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    لکھو("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    اگر (i >= 10) 
        جاؤ s_انتہا;
    لکھو("%d", i);
    i++;
    جاؤ s_loop;
 s_انتہا:
    لکھو("\n");

    /* we also test computed gotos (GCC extension) */
    برائے(i=0;i<3;i++) {
        جاؤ *label_جدول[i];
    label1:
        لکھو("label1\n");
        جاؤ اگلا;
    label2:
        لکھو("label2\n");
        جاؤ اگلا;
    label3:
        لکھو("label3\n");
    اگلا: ;
    }
}

شمار {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

شمار test {
    E5 = 1000,
};

ساخت S_enum {
    شمار {E6 = 42, E7, E8} e:8;
};

شمار ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((غیرعلامتی طویل)0xf000 << 31) << 1,
};

شمار { BIASU = -1U<<31 };
شمار { BIASS = -1 << 31 };

ساکن صحیح getint(صحیح i)
{
  اگر (i)
    واپس 0;
  ورنہ
    واپس (صحیح)(-1U << 31);
}

خالی enum_test()
{
    شمار test b1;
    /* The following should give no warning */
    غیرعلامتی *p = &b1;
    ساخت S_enum s = {E7};
    لکھو("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    لکھو("b1=%d\n", b1);
    لکھو("enum large: %ld\n", EL_large);

    اگر (getint(0) == BIASU)
      لکھو("enum unsigned: ok\n");
    ورنہ
      لکھو("enum unsigned: wrong\n");
    اگر (getint(0) == BIASS)
      لکھو("enum unsigned: ok\n");
    ورنہ
      لکھو("enum unsigned: wrong\n");
}

قسمتعریف صحیح *my_ptr;

قسمتعریف صحیح mytype1;
قسمتعریف صحیح mytype2;

خالی typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    صحیح b;

    a = &b;
    *a = 1234;
    لکھو("a=%d\n", *a);
    mytype2 = 2;
    لکھو("mytype2=%d\n", mytype2);
}

خالی forward_test()
{
    forward_ref();
    forward_ref();
}


خالی forward_ref(خالی)
{
    لکھو("forward ok\n");
}

قسمتعریف ساخت struct1 {
    صحیح f1;
    صحیح f2, f3;
    اتحاد union1 {
        صحیح v1;
        صحیح v2;
    } u;
    حرف str[3];
} struct1;

ساخت struct2 {
    صحیح a;
    حرف b;
};

اتحاد union2 {
    صحیح w1;
    صحیح w2;
};

ساخت struct1 st1, st2;

ساخت خالی_خانے_mem {
    /* nothing */ ;
    صحیح x;
};

صحیح tab[3];
صحیح tab2[3][2];

صحیح g;

خالی f1(صحیح g)
{
    لکھو("g1=%d\n", g);
}

خالی scope_test()
{
    g = 2;
    f1(1);
    لکھو("g2=%d\n", g);
    {
        صحیح g;
        g = 3;
        لکھو("g3=%d\n", g);
        {
            صحیح g;
            g = 4;
            لکھو("g4=%d\n", g);
        }
    }
    لکھو("g5=%d\n", g);
}

صحیح st2_i;
صحیح *st2_p = &st2_i;
خالی scope2_test()
{
    حرف a[50];
    st2_i = 42;
    برائے (صحیح st2_i = 1; st2_i < 10; st2_i++) {
        خارجی صحیح st2_i;
        st2_i++;
        لکھو("exloc: %d\n", st2_i);
    }
    لکھو("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
خارجی صحیح st_global1;
صحیح st_global1=42;
خارجی صحیح st_global1;
صحیح st_global1;
خارجی صحیح st_global2;
صحیح st_global2;
خارجی صحیح st_global2;
صحیح st_global2;

خالی array_test()
{
    صحیح i, j, a[4];

    لکھو("sizeof(a) = %d\n", حجم(a));
    لکھو("sizeof(\"a\") = %d\n", حجم("a"));
#اگر_تعریف_شدہ C99_MACROS
    لکھو("sizeof(__func__) = %d\n", حجم(__func__));
#اگر_ختم
    لکھو("sizeof tab %d\n", حجم(tab));
    لکھو("sizeof tab2 %d\n", حجم tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    لکھو("%d %d %d\n", tab[0], tab[1], tab[2]);
    برائے(i=0;i<3;i++)
        برائے(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    برائے(i=0;i<3*2;i++) {
        لکھو(" %3d", ((صحیح *)tab2)[i]);
    }
    لکھو("\n");
    لکھو("sizeof(size_t)=%d\n", حجم(سائز_t));
    لکھو("sizeof(ptrdiff_t)=%d\n", حجم(ptrdiff_t));
}

خالی اظہاریہ_test()
{
    صحیح a, b;
    a = 0;
    لکھو("%d\n", a += 1);
    لکھو("%d\n", a -= 2);
    لکھو("%d\n", a *= 31232132);
    لکھو("%d\n", a /= 4);
    لکھو("%d\n", a %= 20);
    لکھو("%d\n", a &= 6);
    لکھو("%d\n", a ^= 7);
    لکھو("%d\n", a |= 8);
    لکھو("%d\n", a >>= 3);
    لکھو("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    لکھو("%d\n", a + 1);
    لکھو("%d\n", a - 2);
    لکھو("%d\n", a * 312);
    لکھو("%d\n", a / 4);
    لکھو("%d\n", b / 4);
    لکھو("%d\n", (غیرعلامتی)b / 4);
    لکھو("%d\n", a % 20);
    لکھو("%d\n", b % 20);
    لکھو("%d\n", (غیرعلامتی)b % 20);
    لکھو("%d\n", a & 6);
    لکھو("%d\n", a ^ 7);
    لکھو("%d\n", a | 8);
    لکھو("%d\n", a >> 3);
    لکھو("%d\n", b >> 3);
    لکھو("%d\n", (غیرعلامتی)b >> 3);
    لکھو("%d\n", a << 4);
    لکھو("%d\n", ~a);
    لکھو("%d\n", -a);
    لکھو("%d\n", +a);

    لکھو("%d\n", 12 + 1);
    لکھو("%d\n", 12 - 2);
    لکھو("%d\n", 12 * 312);
    لکھو("%d\n", 12 / 4);
    لکھو("%d\n", 12 % 20);
    لکھو("%d\n", 12 & 6);
    لکھو("%d\n", 12 ^ 7);
    لکھو("%d\n", 12 | 8);
    لکھو("%d\n", 12 >> 2);
    لکھو("%d\n", 12 << 4);
    لکھو("%d\n", ~12);
    لکھو("%d\n", -12);
    لکھو("%d\n", +12);
    لکھو("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

صحیح isid(صحیح c)
{
    واپس (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

صحیح vstack[10], *vstack_ptr;

خالی vpush(صحیح vt, صحیح vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

خالی vpop(صحیح *ft, صحیح *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

خالی expr2_test()
{
    صحیح a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    لکھو("res= %d %d\n", a, b);
}

صحیح const_len_ar[حجم(1/0)]; /* div-by-zero, but in unevaluated context */

خالی constant_اظہاریہ_test()
{
    صحیح a;
    a = 3;
    لکھو("%d\n", a * 16);
    لکھو("%d\n", a * 1);
    لکھو("%d\n", a + 0);
    لکھو("%d\n", حجم(const_len_ar));
}

صحیح tab4[10];

خالی اظہاریہ_ptr_test()
{
    صحیح arr[10], *p, *q;
    صحیح i = -1;

    p = tab4;
    q = tab4 + 10;
    لکھو("diff=%d\n", q - p);
    p++;
    لکھو("inc=%d\n", p - tab4);
    p--;
    لکھو("dec=%d\n", p - tab4);
    ++p;
    لکھو("inc=%d\n", p - tab4);
    --p;
    لکھو("dec=%d\n", p - tab4);
    لکھو("add=%d\n", p + 3 - tab4);
    لکھو("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    لکھو("%p %p %ld\n", q, p, p-q);
    لکھو("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    لکھو("%p %p %ld\n", q, p, p-q);
    لکھو("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (صحیح *)((حرف *)p + 0xf0000000);
    لکھو("%p %p %ld\n", q, p, p-q);
    لکھو("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    لکھو("%p %p %ld\n", q, p, p-q);
    لکھو("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ساخت size12 {
            صحیح i, j, k;
        };
        ساخت size12 s[2], *sp = s;
        صحیح i, j;
        sp->i = 42;
        sp++;
        j = -1;
        لکھو("%d\n", sp[j].i);
    }
#اگر_تعریف_شدہ __LP64__
    i = 1;
    p = (صحیح*)0x100000000UL + i;
    i = ((طویل)p) >> 32;
    لکھو("largeptr: %p %d\n", p, i);
#اگر_ختم
    p = &arr[0];
    q = p + 3;
    لکھو ("%d\n", (صحیح)((p - q) / 3));
}

خالی اظہاریہ_cmp_test()
{
    صحیح a, b;
    a = -1;
    b = 1;
    لکھو("%d\n", a == a);
    لکھو("%d\n", a != a);

    لکھو("%d\n", a < b);
    لکھو("%d\n", a <= b);
    لکھو("%d\n", a <= a);
    لکھو("%d\n", b >= a);
    لکھو("%d\n", a >= a);
    لکھو("%d\n", b > a);

    لکھو("%d\n", (غیرعلامتی)a < b);
    لکھو("%d\n", (غیرعلامتی)a <= b);
    لکھو("%d\n", (غیرعلامتی)a <= a);
    لکھو("%d\n", (غیرعلامتی)b >= a);
    لکھو("%d\n", (غیرعلامتی)a >= a);
    لکھو("%d\n", (غیرعلامتی)b > a);
}

ساخت خالی_خانے {
};

ساخت aligntest1 {
    حرف a[10];
};

ساخت aligntest2 {
    صحیح a;
    حرف b[10];
};

ساخت aligntest3 {
    دوہرا a, b;
};

ساخت aligntest4 {
    دوہرا a[0];
};

ساخت __attribute__((aligned(16))) aligntest5
{
    صحیح i;
};
ساخت aligntest6
{
    صحیح i;
} __attribute__((aligned(16)));
ساخت aligntest7
{
    صحیح i;
};
ساخت aligntest5 altest5[2];
ساخت aligntest6 altest6[2];
صحیح pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ساخت aligntest7 altest7[2] __attribute__((aligned(16)));

ساخت aligntest8
{
  صحیح i;
} __attribute__((aligned(4096)));

ساخت Large {
    غیرعلامتی طویل flags;
    اتحاد {
	خالی *u1;
	صحیح *u2;
    };

    ساخت {
	اتحاد {
	    غیرعلامتی طویل اشاریہ;
	    خالی *freelist;
	};
	اتحاد {
	    غیرعلامتی طویل counters;
	    ساخت {
		صحیح bla;
	    };
	};
    };

    اتحاد {
	ساخت {
	    طویل u3;
	    طویل u4;
	};
	خالی *u5;
	ساخت {
	    غیرعلامتی طویل compound_سر;
	    غیرعلامتی صحیح compound_dtor;
	    غیرعلامتی صحیح compound_ترتیب;
	};
    };
} __attribute__((aligned(2 * حجم(طویل))));

قسمتعریف غیرعلامتی طویل طویل __attribute__((aligned(4))) unaligned_u64;

ساخت aligntest9 {
    غیرعلامتی صحیح buf_nr;
    unaligned_u64 آغاز_lba;
};

ساخت aligntest10 {
    غیرعلامتی صحیح buf_nr;
    غیرعلامتی طویل طویل آغاز_lba;
};

خالی struct_test()
{
    struct1 *s;
    اتحاد union2 u;
    ساخت Large ls;

    لکھو("sizes: %d %d %d %d\n",
           حجم(ساخت struct1),
           حجم(ساخت struct2),
           حجم(اتحاد union1),
           حجم(اتحاد union2));
    لکھو("offsets: %d\n", (صحیح)((حرف*)&st1.u.v1 - (حرف*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    لکھو("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    لکھو("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    لکھو("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    لکھو("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    لکھو("str_addr=%x\n", (صحیح)(uintptr_t)st1.str - (صحیح)(uintptr_t)&st1.f1);

    /* align / size tests */
    لکھو("aligntest1 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest1), __alignof__(ساخت aligntest1));
    لکھو("aligntest2 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest2), __alignof__(ساخت aligntest2));
    لکھو("aligntest3 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest3), __alignof__(ساخت aligntest3));
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    لکھو("aligntest4 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest4), __alignof__(ساخت aligntest4));
#اگر_ختم
    لکھو("aligntest5 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest5), __alignof__(ساخت aligntest5));
    لکھو("aligntest6 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest6), __alignof__(ساخت aligntest6));
    لکھو("aligntest7 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest7), __alignof__(ساخت aligntest7));
    لکھو("aligntest8 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest8), __alignof__(ساخت aligntest8));
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    لکھو("aligntest9 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest9), __alignof__(ساخت aligntest9));
#اگر_ختم
    لکھو("aligntest10 sizeof=%d alignof=%d\n",
           حجم(ساخت aligntest10), __alignof__(ساخت aligntest10));
    لکھو("altest5 sizeof=%d alignof=%d\n",
           حجم(altest5), __alignof__(altest5));
    لکھو("altest6 sizeof=%d alignof=%d\n",
           حجم(altest6), __alignof__(altest6));
    لکھو("altest7 sizeof=%d alignof=%d\n",
           حجم(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#اگر !(defined _WIN32 && CC_NAME == CC_clang)
    لکھو("sizeof(struct empty) = %d\n", حجم(ساخت خالی_خانے));
#اگر_ختم
    لکھو("alignof(struct empty) = %d\n", __alignof__(ساخت خالی_خانے));

    لکھو("Large: sizeof=%d\n", حجم(ls));
    memset(&ls, 0, حجم(ls));
    ls.compound_سر = 42;
    لکھو("Large: offsetof(compound_head)=%d\n", (صحیح)((حرف*)&ls.compound_سر - (حرف*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ساکن صحیح __csf(صحیح x) { واپس x; }
ساکن خالی *_csf = __csf;
#تعریف_کرو csf(t,n) ((t(*)(صحیح))_csf)(n)

/* XXX: depend on endianness */
خالی char_short_test()
{
    صحیح var1, var2;
    علامتی حرف var3;
    طویل طویل var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    لکھو("s8=%d %d\n", 
           *(علامتی حرف *)&var1, *(علامتی حرف *)&var2);
    لکھو("u8=%d %d\n", 
           *(غیرعلامتی حرف *)&var1, *(غیرعلامتی حرف *)&var2);
    لکھو("s16=%d %d\n", 
           *(مختصر *)&var1, *(مختصر *)&var2);
    لکھو("u16=%d %d\n", 
           *(غیرعلامتی مختصر *)&var1, *(غیرعلامتی مختصر *)&var2);
    لکھو("s32=%d %d\n", 
           *(صحیح *)&var1, *(صحیح *)&var2);
    لکھو("u32=%d %d\n", 
           *(غیرعلامتی صحیح *)&var1, *(غیرعلامتی صحیح *)&var2);
    *(علامتی حرف *)&var1 = 0x08;
    لکھو("var1=%x\n", var1);
    *(مختصر *)&var1 = 0x0809;
    لکھو("var1=%x\n", var1);
    *(صحیح *)&var1 = 0x08090a0b;
    لکھو("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    لکھو("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    لکھو("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    لکھو("promote char/short cast VA %d %d\n", (علامتی حرف)(var1 + 1), (علامتی حرف)(var4 + 1));
#اگر !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(غیرعلامتی حرف,0x89898989);
    var4 = csf(علامتی حرف,0xabababab);
#اگر_تعریف_شدہ __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#اگر_ختم
    لکھو("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    لکھو("promote char/short fumcret VA %d %d %d %d\n",
        csf(غیرعلامتی مختصر,0xcdcdcdcd),
        csf(مختصر,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#اگر_ختم
    var3 = -10;
    var1 = (علامتی حرف)(غیرعلامتی حرف)(var3 + 1);
    var4 = (علامتی حرف)(غیرعلامتی حرف)(var3 + 1);
    لکھو("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (غیرعلامتی)(صحیح)(var4 + 1);
    لکھو("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (غیرعلامتی)(علامتی حرف)(var4 + 1);
    لکھو("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

قسمتعریف ساخت Sym {
    صحیح v;
    صحیح t;
    صحیح c;
    ساخت Sym *اگلا;
    ساخت Sym *پچھلا;
} Sym;

#تعریف_کرو ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#تعریف_کرو TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ساکن صحیح toupper1(صحیح a)
{
    واپس TOUPPER(a);
}

ساکن غیرعلامتی صحیح calc_vm_flags(غیرعلامتی صحیح prot)
{
  غیرعلامتی صحیح prot_بٹ;
  /* This used to segfault in some revisions: */
  prot_بٹ = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  واپس prot_بٹ;
}

شمار cast_enum { پہلا_2, آخری_2 };

ساکن خالی tst_cast(شمار cast_enum ce)
{
    لکھو("%d\n", ce);
}

خالی bool_test()
{
    صحیح *s, a, b, t, f, i;

    a = 0;
    s = (خالی*)0;
    لکھو("!s=%d\n", !s);

    اگر (!s || !s[0])
        a = 1;
    لکھو("a=%d\n", a);

    لکھو("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    لکھو("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    لکھو("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#اگر 1 && 1
    لکھو("a1\n");
#اگر_ختم
#اگر 1 || 0
    لکھو("a2\n");
#اگر_ختم
#اگر 1 ? 0 : 1
    لکھو("a3\n");
#اگر_ختم
#اگر 0 ? 0 : 1
    لکھو("a4\n");
#اگر_ختم

    a = 4;
    لکھو("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    لکھو("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    لکھو("exp=%d\n", f == (32 <= a && a <= 3));
    لکھو("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    لکھو("type of bool: %d\n", (صحیح) ( (~ ((غیرعلامتی صحیح) (t && 1))) / 2) );
    tst_cast(t >= 0 ? پہلا_2 : آخری_2);

    لکھو("type of cond: %d\n", (~(t ? 0U : (غیرعلامتی صحیح)0)) / 2 );
    /* test ? : cast */
    {
        صحیح aspect_on;
        صحیح aspect_native = 65536;
        دوہرا bfu_aspect = 1.0;
        صحیح aspect;
        برائے(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            لکھو("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ساکن صحیح v1 = 34 ? : -1; /* constant case */
        ساکن صحیح v2 = 0 ? : -1; /* constant case */
        صحیح a = 30;
        
        لکھو("%d %d\n", v1, v2);
        لکھو("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    برائے(i=0;i<256;i++) {
        اگر (toupper1 (i) != TOUPPER (i))
            لکھو("error %d\n", i);
    }
    لکھو ("bits = 0x%x\n", calc_vm_flags (0x1));
}

خارجی صحیح undefined_function(خالی);
خارجی صحیح defined_function(خالی);

#اگر_تعریف_شدہ __clang__
صحیح undefined_function(خالی) {}
#اگر_ختم

ساکن اندرونی خالی refer_مقصد_undefined(خالی)
{
  undefined_function();
}

خالی optimize_برآمد_test(خالی)
{
  صحیح i = 0 ? undefined_function() : defined_function();
  لکھو ("oo:%d\n", i);
  صحیح j = 1 ? defined_function() : undefined_function();
  لکھو ("oo:%d\n", j);
  اگر (0)
    لکھو("oo:%d\n", undefined_function());
  ورنہ
    لکھو("oo:%d\n", defined_function());
  اگر (1)
    لکھو("oo:%d\n", defined_function());
  ورنہ
    لکھو("oo:%d\n", undefined_function());
  جب (1) {
      لکھو("oow:%d\n", defined_function());
      توڑو;
      لکھو("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  انتخاب (j)
    حالت 1: توڑو;
  لکھو ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  جب (1)
    توڑو;
  لکھو ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  کرو
    توڑو;
  جب (1);
  لکھو ("ool2:%d\n", defined_function());
  برائے (;;)
    توڑو;
  لکھو ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  جب (1) {
	{
	  توڑو;
	}
      لکھو ("ool4:%d\n", undefined_function());
  }
  j = 1;
  جب (j) {
      اگر (j == 0)
	توڑو; /* this break shouldn't disable code outside the if. */
      لکھو("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  جب (j) {
      اگر (1)
	j--;
      ورنہ
	breakhere: توڑو;
      لکھو("ool6:%d\n", defined_function());
      جاؤ breakhere;
  }
  j = 1;
  جب (j) {
      j--;
      جاری;
      لکھو("ool7:%d\n", undefined_function());
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
  ورنہ
    undefined_function();
  اگر (defined_function() || 1)
    ;
  ورنہ
    undefined_function();
  اگر (1 || 1)
    ;
  ورنہ
    undefined_function();
  اگر (defined_function() || 1 || undefined_function())
    ;
  ورنہ
    undefined_function();

  اگر (defined_function() && 0)
    refer_مقصد_undefined();

  اگر (0) {
      (خالی)حجم( ({
		     کرو { } جب (0);
		     0;
		     }) );
      undefined_function();
  }

  اگر (0) {
      انتخاب (defined_function()) {
          حالت 0: undefined_function(); توڑو;
          طےشدہ: undefined_function(); توڑو;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  اگر (1)
    واپس;
  لکھو ("oor:%d\n", undefined_function());
}

صحیح defined_function(خالی)
{
  ساکن صحیح i = 40;
  واپس i++;
}

/* GCC accepts that */
ساکن صحیح tab_reinit[];
ساکن صحیح tab_reinit[10];

ساکن صحیح tentative_ar[];
ساکن صحیح tentative_ar[] = {1,2,3};

صحیح cinit1; /* a global variable can be defined several times without error ! */
صحیح cinit1; 
صحیح cinit1 = 0;
صحیح *cinit2 = (صحیح []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
حرف ثابت * ثابت cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
خالی *cinit52 = &(خالی*){ (خالی*) 52 };

#اگر __TINYC__ || __GNUC__ >= 6
صحیح cinit4 = (صحیح){44};
خالی *cinit51 = (خالی*){ (خالی*) 51 };
ساخت _c6 { صحیح a,b; } cinit6 = (ساخت _c6){61,62}, *cinit7 = &(ساخت _c6){71,72};
#ورنہ
صحیح cinit4 = 44;
خالی *cinit51 = (خالی*)51;
ساخت _c6 { صحیح a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#اگر_ختم

خالی compound_literal_test(خالی)
{
    صحیح *p, i;
    حرف *q, *q3;

    لکھو("cinit3 : %s\n", cinit3);
    لکھو("cinit4 : %d\n", cinit4);
    لکھو("cinit51 : %d\n", (صحیح)cinit51);
    لکھو("cinit52 : %d\n", *(صحیح*)cinit52);
    لکھو("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    لکھو("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    لکھو("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (صحیح []){1, 2, 3};
    برائے(i=0;i<3;i++)
        لکھو(" %d", p[i]);
    لکھو("\n");

    برائے(i=0;i<3;i++)
        لکھو("%d", cinit2[i]);
    لکھو("\n");

    q = "tralala1";
    لکھو("q1=%s\n", q);

    q = (حرف *){ "tralala2" };
    لکھو("q2=%s\n", q);

    q3 = (حرف *){ q };
    لکھو("q3=%s\n", q3);

    q = (حرف []){ "tralala3" };
    لکھو("q4=%s\n", q);

#اگر_تعریف_شدہ ALL_ISOC99
    p = (صحیح []){1, 2, cinit1 + 3};
    برائے(i=0;i<3;i++)
        لکھو(" %d", p[i]);
    لکھو("\n");

    برائے(i=0;i<3;i++) {
        p = (صحیح []){1, 2, 4 + i};
        لکھو("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#اگر_ختم
}


#اگر __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    واپس a + b;
}

صحیح kr_func2(a, b)
{
    واپس a + b;
}

kr_test()
{
    لکھو("func1=%d\n", kr_func1(3, 4));
    لکھو("func2=%d\n", kr_func2(3, 4));
    واپس 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
حرف invalid_function_def()[] {واپس 0;}

#ورنہ
# define kr_test() لکھو("func1=7\nfunc2=7\n")
#اگر_ختم

خالی عدد(صحیح n)
{
    حرف *tab, *p;
    tab = (حرف*)حافظہ_دو(20); 
    p = tab;
    جب (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        اگر (n == 0)
            توڑو;
    }
    جب (p != tab) {
        p--;
        لکھو("%c", *p);
    }
    لکھو("\n");
    آزاد(tab);
}

/* structure assignment tests */
ساخت structa1 {
    صحیح f1;
    حرف f2;
};

خالی struct_تفویض_test1(ساخت structa1 s1, صحیح t, اعشاری f)
{
    لکھو("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ساخت structa1 struct_تفویض_test2(ساخت structa1 s1, صحیح t)
{
    s1.f1 += t;
    s1.f2 -= t;
    واپس s1;
}

خالی struct_تفویض_test(خالی)
{
    ساخت S {
      ساخت structa1 lsta1, lsta2;
      صحیح i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_تفویض_test1(ps->lsta2, 3, 4.5);
    لکھو("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_تفویض_test2(ps->lsta2, ps->i);
    لکھو("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ساکن ساخت {
        خالی (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_تفویض_test }
    };
    لکھو("%d\n", struct_تفویض_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_تفویض_test2(s.lsta1, 1);
    لکھو("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

خالی cast1(حرف a, مختصر b, غیرعلامتی حرف c, غیرعلامتی مختصر d)
{
    لکھو("%d %d %d %d\n", a, b, c, d);
}

حرف bcast;
مختصر scast;

خالی cast_test()
{
    صحیح a;
    حرف c;
    حرف tab[10];
    غیرعلامتی b,d;
    مختصر s;
    حرف *p = تہی;
    غیرعلامتی طویل ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    لکھو("%d %d %d %d\n",
           (حرف)(a + 1),
           (مختصر)(a + 1),
           (غیرعلامتی حرف)(a + 1),
           (غیرعلامتی مختصر)(a + 1));
    لکھو("%d %d %d %d\n",
           (حرف)0xfffff,
           (مختصر)0xfffff,
           (غیرعلامتی حرف)0xfffff,
           (غیرعلامتی مختصر)0xfffff);

    a = (bcast = 128) + 1;
    لکھو("%d\n", a);
    a = (scast = 65536) + 1;
    لکھو("%d\n", a);
    
    لکھو("sizeof(c) = %d, sizeof((int)c) = %d\n", حجم(c), حجم((صحیح)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (مختصر)b;
    لکھو("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (حرف)b;
    لکھو("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    لکھو("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    لکھو("sizeof(+(char)'a') = %d\n", حجم(+(حرف)'a'));
    لکھو("sizeof(-(char)'a') = %d\n", حجم(-(حرف)'a'));
    لکھو("sizeof(~(char)'a') = %d\n", حجم(-(حرف)'a'));

#اگر CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    لکھو("%d %d %ld %ld %lld %lld\n",
           (صحیح)p, (غیرعلامتی صحیح)p,
           (طویل)p, (غیرعلامتی طویل)p,
           (طویل طویل)p, (غیرعلامتی طویل طویل)p);
#اگر_ختم

    /* from integers to pointers */
    لکھو("%p %p %p %p\n",
           (خالی *)a, (خالی *)b, (خالی *)c, (خالی *)d);

    /* int to int with sign set */
    لکھو("0x%lx\n", (غیرعلامتی طویل)(صحیح)ul);
}

/* initializers tests */
ساخت structinit1 {
    صحیح f1;
    حرف f2;
    مختصر f3;
    صحیح farray[3];
};

صحیح sinit1 = 2;
صحیح sinit2 = { 3 };
صحیح sinit3[3] = { 1, 2, {3}, };
صحیح sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
صحیح sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
صحیح sinit6[] = { 1, 2, 3 };
صحیح sinit7[] = { [2] = 3, [0] = 1, 2 };
حرف sinit8[] = "hello" "trala";

ساخت structinit1 sinit9 = { 1, 2, 3 };
ساخت structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ساخت structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#اگر_تعریف_شدہ ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#اگر_ختم
};

حرف *sinit12 = "hello world";
حرف *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
حرف sinit14[10] = { "abc" };
صحیح sinit15[3] = { حجم(sinit15), 1, 2 };

ساخت { صحیح a[3], b; } sinit16[] = { { 1 }, 2 };

ساخت bar {
        حرف *s;
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

ساخت complexinit0 {
    صحیح a;
    صحیح b;
};

ساخت complexinit {
    صحیح a;
    ثابت ساخت complexinit0 *b;
};

ثابت ساکن ساخت complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ثابت ساخت complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ساخت complexinit2 {
	صحیح a;
	صحیح b[];
};

ساخت complexinit2 cix20;

ساخت complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ساخت complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

قسمتعریف صحیح arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
قسمتعریف صحیح arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
صحیح sinit23[2] = { "astring" ? حجم("astring") : -1,
		   &sinit23 ? 42 : -1 };

صحیح sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ساخت bf_SS {غیرعلامتی صحیح ثنائی_ہندسہ:1,bits31:31; };
ساخت bf_SS bf_init = { .ثنائی_ہندسہ = 1 };
ساخت bfn_SS {صحیح a,b; ساخت bf_SS c; صحیح d,e; };
ساخت bfn_SS bfn_init = { .c.ثنائی_ہندسہ = 1 };
ساخت bfa_SS {صحیح a,b; ساخت bf_SS c[3]; صحیح d,e; };
ساخت bfa_SS bfa_init = { .c[1].ثنائی_ہندسہ = 1 };
ساخت bf_SS bfaa_init[3] = { [1].ثنائی_ہندسہ = 1 };
ساخت bf_SS bfaa_vinit[] = { [2].ثنائی_ہندسہ = 1 };
ساخت b2_SS {طویل طویل صحیح میدان : 52; طویل طویل صحیح pad : 12; };
ساخت b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

خارجی صحیح external_inited = 42;

خالی init_test(خالی)
{
    صحیح linit1 = 2;
    صحیح linit2 = { 3 };
    صحیح linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    صحیح linit6[] = { 1, 2, 3 };
    صحیح i, j;
    حرف linit8[] = "hello" "trala";
    صحیح linit12[10] = { 1, 2 };
    صحیح linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    حرف linit14[10] = "abc";
    صحیح linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ساخت linit16 { صحیح a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    صحیح linit17 = حجم(linit17);
    صحیح zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    صحیح linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ساخت bf_SS bf_finit = { .ثنائی_ہندسہ = 1 };
    ساخت bfn_SS bfn_finit = { .c.ثنائی_ہندسہ = 1 };
    ساخت bfa_SS bfa_finit = { .c[1].ثنائی_ہندسہ = 1 };
    ساخت bf_SS bfaa_finit[3] = { [1].ثنائی_ہندسہ = 1 };
    ساخت bf_SS bfaa_fvinit[] = { [2].ثنائی_ہندسہ = 1 };
    ساخت b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    لکھو("sinit1=%d\n", sinit1);
    لکھو("sinit2=%d\n", sinit2);
    لکھو("sinit3=%d %d %d %d\n", 
           حجم(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    لکھو("sinit6=%d\n", حجم(sinit6));
    لکھو("sinit7=%d %d %d %d\n", 
           حجم(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    لکھو("sinit8=%s\n", sinit8);
    لکھو("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    لکھو("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    لکھو("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    برائے(i=0;i<3;i++)
        برائے(j=0;j<2;j++)
            لکھو("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    لکھو("linit1=%d\n", linit1);
    لکھو("linit2=%d\n", linit2);
    لکھو("linit6=%d\n", حجم(linit6));
    لکھو("linit8=%d %s\n", حجم(linit8), linit8);

    لکھو("sinit12=%s\n", sinit12);
    لکھو("sinit13=%d %s %s %s\n",
           حجم(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    لکھو("sinit14=%s\n", sinit14);

    برائے(i=0;i<10;i++) لکھو(" %d", linit12[i]);
    لکھو("\n");
    برائے(i=0;i<10;i++) لکھو(" %d", linit13[i]);
    لکھو("\n");
    برائے(i=0;i<10;i++) لکھو(" %d", linit14[i]);
    لکھو("\n");
    برائے(i=0;i<10;i++) لکھو(" %d", linit15[i]);
    لکھو("\n");
    لکھو("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    لکھو("linit17=%d\n", linit17);
    لکھو("sinit15=%d\n", sinit15[0]);
    لکھو("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    لکھو("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    برائے(i=0;i<10;i++)
        لکھو("%x ", sinit18[i]);
    لکھو("\n");
    /* complex init check */
    لکھو("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    لکھو("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    لکھو("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", حجم cix20, حجم cix21, حجم cix22);

    لکھو("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    لکھو("arrtype2: %d %d\n", حجم(sinit19), حجم(sinit20));
    لکھو("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    لکھو("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    لکھو("arrtype5: %d %d\n", حجم(sinit21), حجم(sinit22));
    لکھو("arrtype6: %d\n", حجم(arrtype2));

    لکھو("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    لکھو("sinit24=%d\n", sinit24);
    لکھو("linit18= %d %d\n", linit18[0], linit18[1]);
    لکھو ("bf1: %u %u\n", bf_init.ثنائی_ہندسہ, bf_init.bits31);
    لکھو ("bf2: %u %u\n", bf_finit.ثنائی_ہندسہ, bf_finit.bits31);
    لکھو ("bf3: %u %u\n", bfn_init.c.ثنائی_ہندسہ, bfn_init.c.bits31);
    لکھو ("bf4: %u %u\n", bfn_finit.c.ثنائی_ہندسہ, bfn_finit.c.bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf5[%d]: %u %u\n", i, bfa_init.c[i].ثنائی_ہندسہ, bfa_init.c[i].bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].ثنائی_ہندسہ, bfa_finit.c[i].bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf7[%d]: %u %u\n", i, bfaa_init[i].ثنائی_ہندسہ, bfaa_init[i].bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf8[%d]: %u %u\n", i, bfaa_finit[i].ثنائی_ہندسہ, bfaa_finit[i].bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].ثنائی_ہندسہ, bfaa_vinit[i].bits31);
    برائے (i = 0; i < 3; i++)
        لکھو ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].ثنائی_ہندسہ, bfaa_fvinit[i].bits31);
}

خالی switch_uc(غیرعلامتی حرف uc)
{
	انتخاب (uc) {
	    حالت 0xfb ... 0xfe:
		لکھو("ucsw:1\n");
		توڑو;
	    حالت 0xff:
		لکھو("ucsw:2\n");
		توڑو;
	    حالت 0 ... 5:
		لکھو("ucsw:3\n");
		توڑو;
	    طےشدہ:
		لکھو("ucsw: broken!\n");
	}
}

خالی switch_sc(علامتی حرف sc)
{
	انتخاب (sc) {
	    حالت -5 ... -2:
		لکھو("scsw:1\n");
		توڑو;
	    حالت -1:
		لکھو("scsw:2\n");
		توڑو;
	    حالت 0 ... 5:
		لکھو("scsw:3\n");
		توڑو;
	    طےشدہ:
		لکھو("scsw: broken!\n");
	}
}

خالی switch_test()
{
    صحیح i;
    غیرعلامتی طویل طویل ull;
    طویل طویل ll;

    برائے(i=0;i<15;i++) {
        انتخاب(i) {
        حالت 0:
        حالت 1:
            لکھو("a");
            توڑو;
        طےشدہ:
            لکھو("%d", i);
            توڑو;
        حالت 8 ... 12:
            لکھو("c");
            توڑو;
        حالت 3:
            لکھو("b");
            توڑو;
        حالت 0xc33c6b9fU:
        حالت 0x7c9eeeb9U:
            توڑو;
        }
    }
    لکھو("\n");

    برائے (i = 1; i <= 5; i++) {
	ull = (غیرعلامتی طویل طویل)i << 61;
	انتخاب (ull) {
	    حالت 1ULL << 61:
		لکھو("ullsw:1\n");
		توڑو;
	    حالت 2ULL << 61:
		لکھو("ullsw:2\n");
		توڑو;
	    حالت 3ULL << 61:
		لکھو("ullsw:3\n");
		توڑو;
	    حالت 4ULL << 61:
		لکھو("ullsw:4\n");
		توڑو;
	    حالت 5ULL << 61:
		لکھو("ullsw:5\n");
		توڑو;
	    طےشدہ:
		لکھو("ullsw: broken!\n");
	}
    }

    برائے (i = 1; i <= 5; i++) {
	ll = (طویل طویل)i << 61;
	انتخاب (ll) {
	    حالت 1LL << 61:
		لکھو("llsw:1\n");
		توڑو;
	    حالت 2LL << 61:
		لکھو("llsw:2\n");
		توڑو;
	    حالت 3LL << 61:
		لکھو("llsw:3\n");
		توڑو;
	    حالت 4LL << 61:
		لکھو("llsw:4\n");
		توڑو;
	    حالت 5LL << 61:
		لکھو("llsw:5\n");
		توڑو;
	    طےشدہ:
		لکھو("llsw: broken!\n");
	}
    }

    برائے (i = -5; i <= 5; i++) {
	switch_uc((غیرعلامتی حرف)i);
    }

    برائے (i = -5; i <= 5; i++) {
	switch_sc ((علامتی حرف)i);
    }
}

/* ISOC99 _Bool type */
خالی c99_bool_test(خالی)
{
#اگر_تعریف_شدہ BOOL_ISOC99
    صحیح a;
    _Bool b, b2;

    لکھو("sizeof(_Bool) = %d\n", حجم(_Bool));
    a = 3;
    لکھو("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    لکھو("b = %d\n", b);
    b++;
    لکھو("b = %d\n", b);
    b2 = 0;
    لکھو("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           حجم ((متلون صحیح)a ? b : b2));
#اگر_ختم
}

خالی bitfield_test(خالی)
{
    صحیح a;
    مختصر sa;
    غیرعلامتی حرف ca;
    ساخت sbf1 {
        صحیح f1 : 3;
        صحیح : 2;
        صحیح f2 : 1;
        صحیح : 0;
        صحیح f3 : 5;
        صحیح f4 : 7;
        غیرعلامتی صحیح f5 : 7;
    } st1;
    لکھو("sizeof(st1) = %d\n", حجم(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    لکھو("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    لکھو("%d %d\n", sa, ca);

    st1.f1 = 7;
    اگر (st1.f1 == -1) 
        لکھو("st1.f1 == -1\n");
    ورنہ 
        لکھو("st1.f1 != -1\n");
    اگر (st1.f2 == -1) 
        لکھو("st1.f2 == -1\n");
    ورنہ 
        لکھو("st1.f2 != -1\n");

    ساخت sbf2 {
        طویل طویل f1 : 45;
        طویل طویل : 2;
        طویل طویل f2 : 35;
        غیرعلامتی طویل طویل f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (طویل طویل)a << 25;
    st2.f3 = a;
    st2.f2++;
    لکھو("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#اگر 0
    Disabled برائے now until further clarification re GCC compatibility
    ساخت sbf3 {
        صحیح f1 : 7;
        صحیح f2 : 1;
        حرف f3;
        صحیح f4 : 8;
        صحیح f5 : 1;
        صحیح f6 : 16;
    } st3;
    لکھو("sizeof(st3) = %d\n", حجم(st3));
#اگر_ختم

    ساخت sbf4 {
	صحیح x : 31;
	حرف y : 2;
    } st4;
    st4.y = 1;
    لکھو("st4.y == %d\n", st4.y);
    ساخت sbf5 {
	صحیح a;
	حرف b;
	صحیح x : 12, y : 4, : 0, : 4, z : 3;
	حرف c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    لکھو("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ساخت sbf6 {
	مختصر x : 12;
	غیرعلامتی حرف y : 2;
    } st6;
    st6.y = 1;
    لکھو("st6.y == %d\n", st6.y);
}

#اگر_تعریف_شدہ __x86_64__
#تعریف_کرو FLOAT_FMT "%f\n"
#ورنہ
/* x86's float isn't compatible with GCC */
#تعریف_کرو FLOAT_FMT "%.5f\n"
#اگر_ختم

/* declare strto* functions as they are C99 */
دوہرا strtod(ثابت حرف *nptr, حرف **endptr);

#اگر defined(_WIN32)
اعشاری strtof(ثابت حرف *nptr, حرف **endptr) {واپس (اعشاری)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ثابت حرف *nptr, حرف **endptr) {واپس (LONG_DOUBLE)strtod(nptr, endptr);}
#ورنہ
اعشاری strtof(ثابت حرف *nptr, حرف **endptr);
LONG_DOUBLE strtold(ثابت حرف *nptr, حرف **endptr);
#اگر_ختم

#تعریف_کرو FTEST(سابقہ, typename, type, fmt)\
خالی سابقہ ## cmp(type a, type b)\
{\
    لکھو("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    لکھو(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    لکھو(fmt "\n", ++a);\
    لکھو(fmt "\n", a++);\
    لکھو(fmt "\n", a);\
    b = 0;\
    لکھو("%d %d\n", !a, !b);\
}\
خالی سابقہ ## fcast(type a)\
{\
    اعشاری fa;\
    دوہرا da;\
    LONG_DOUBLE la;\
    صحیح ia;\
    طویل طویل llia;\
    غیرعلامتی صحیح ua;\
    غیرعلامتی طویل طویل llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    لکھو("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (صحیح)a;\
    llia = (طویل طویل)a;\
    a = (a >= 0) ? a : -a;\
    ua = (غیرعلامتی صحیح)a;\
    llua = (غیرعلامتی طویل طویل)a;\
    لکھو("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    لکھو("itof: " fmt "\n", b);\
    b = ua;\
    لکھو("utof: " fmt "\n", b);\
    b = llia;\
    لکھو("lltof: " fmt "\n", b);\
    b = llua;\
    اگر (CC_NAME != CC_clang) لکھو("ulltof: " fmt "\n", b);\
}\
\
اعشاری سابقہ ## retf(type a) { واپس a; }\
دوہرا سابقہ ## retd(type a) { واپس a; }\
LONG_DOUBLE سابقہ ## retld(type a) { واپس a; }\
\
خالی سابقہ ## call(خالی)\
{\
    لکھو("float: " FLOAT_FMT, سابقہ ## retf(42.123456789));\
    لکھو("double: %f\n", سابقہ ## retd(42.123456789));\
    لکھو("long double: %Lf\n", سابقہ ## retld(42.123456789));\
    لکھو("strto%s: %f\n", #prefix, (دوہرا)strto ## سابقہ("1.2", تہی));\
}\
\
خالی سابقہ ## signed_zeros(خالی) \
{\
  type x = 0.0, y = -0.0, n, p;\
  اگر (x == y)\
    لکھو ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ورنہ\
    لکھو ("x != y; this is wrong!\n");\
\
  n = -x;\
  اگر (x == n)\
    لکھو ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ورنہ\
    لکھو ("x != -x; this is wrong!\n");\
\
  p = +y;\
  اگر (x == p)\
    لکھو ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ورنہ\
    لکھو ("x != +y; this is wrong!\n");\
  p = -y;\
  اگر (x == p)\
    لکھو ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ورنہ\
    لکھو ("x != -y; this is wrong!\n");\
}\
خالی سابقہ ## nan(خالی)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    لکھو("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
خالی سابقہ ## test(خالی)\
{\
    لکھو("testing '%s'\n", #typename);\
    سابقہ ## cmp(1, 2.5);\
    سابقہ ## cmp(2, 1.5);\
    سابقہ ## cmp(1, 1);\
    سابقہ ## fcast(234.6);\
    سابقہ ## fcast(-2334.6);\
    سابقہ ## call();\
    سابقہ ## signed_zeros();\
    اگر (CC_NAME != CC_clang) سابقہ ## nan();\
}

FTEST(f, اعشاری, اعشاری, "%f")
FTEST(d, دوہرا, دوہرا, "%f")
FTEST(ld, طویل دوہرا, LONG_DOUBLE, "%Lf")

دوہرا ftab1[3] = { 1.2, 3.4, -5.6 };


خالی float_test(خالی)
{
#اگر !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    متلون اعشاری fa, fb;
    متلون دوہرا da, db;
    صحیح a;
    غیرعلامتی صحیح b;
    ساکن دوہرا nan2 = 0.0/0.0;
    ساکن دوہرا inf1 = 1.0/0.0;
    ساکن دوہرا inf2 = 1e5000;
    متلون LONG_DOUBLE la;

    لکھو("sizeof(float) = %d\n", حجم(اعشاری));
    لکھو("sizeof(double) = %d\n", حجم(دوہرا));
    لکھو("sizeof(long double) = %d\n", حجم(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    لکھو("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    لکھو("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    لکھو("da=%f\n", da);
    fa = 123;
    لکھو("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    لکھو("da = %f\n", da);
    b = 4000000000;
    db = b;
    لکھو("db = %f\n", db);
    لکھو("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    لکھو ("da subnormal = %a\n", da);
    لکھو ("da subnormal = %.40g\n", da);
    لکھو ("la subnormal = %La\n", la);
    لکھو ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    لکھو ("da/2 subnormal = %a\n", da);
    لکھو ("da/2 subnormal = %.40g\n", da);
    لکھو ("la/2 subnormal = %La\n", la);
    لکھو ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    لکھو ("fa subnormal = %a\n", fa);
    لکھو ("fa subnormal = %.40g\n", fa);
    لکھو ("la subnormal = %La\n", la);
    لکھو ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    لکھو ("fa/2 subnormal = %a\n", fa);
    لکھو ("fa/2 subnormal = %.40g\n", fa);
    لکھو ("la/2 subnormal = %La\n", la);
    لکھو ("la/2 subnormal = %.40Lg\n", la);
#اگر_ختم
}

صحیح fib(صحیح n)
{
    اگر (n <= 2)
        واپس 1;
    ورنہ
        واپس fib(n-1) + fib(n-2);
}

#اگر __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ورنہ
خالی __attribute__((aligned(16))) aligned_function(صحیح i) {}
#اگر_ختم

خالی funcptr_test()
{
    خالی (*func)(صحیح);
    صحیح a;
    ساخت {
        صحیح dummy;
        خالی (*func)(صحیح);
    } st1;
    طویل diff;

    func = &عدد;
    (*func)(12345);
    func = عدد;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = عدد;
    st1.func(12346);
    لکھو("sizeof1 = %d\n", حجم(funcptr_test));
    لکھو("sizeof2 = %d\n", حجم funcptr_test);
    لکھو("sizeof3 = %d\n", حجم(&funcptr_test));
    لکھو("sizeof4 = %d\n", حجم &funcptr_test);
    a = 0;
    func = عدد + a;
    diff = func - عدد;
    func(42);
    (func + diff)(42);
    (عدد + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    لکھو("aligned_function (should be zero): %d\n", ((صحیح)(uintptr_t)func) & 15);
}

خالی lloptest(طویل طویل a, طویل طویل b)
{
    غیرعلامتی طویل طویل ua, ub;

    ua = a;
    ub = b;
    /* arith */
    لکھو("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    اگر (b != 0) {
        لکھو("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ثنائی*/
    لکھو("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    لکھو("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    لکھو("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    لکھو("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    لکھو("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    لکھو("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    لکھو("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    لکھو("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

خالی llshift(طویل طویل a, صحیح b)
{
    لکھو("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (غیرعلامتی طویل طویل)a >> b,
           a >> b,
           a << b);
    لکھو("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (غیرعلامتی طویل طویل)a >> 3,
           a >> 3,
           a << 3);
    لکھو("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (غیرعلامتی طویل طویل)a >> 35,
           a >> 35,
           a << 35);
}

خالی llfloat(خالی)
{
    اعشاری fa;
    دوہرا da;
    LONG_DOUBLE lda;
    طویل طویل la, lb, lc;
    غیرعلامتی طویل طویل ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    لکھو("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    لکھو("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    لکھو("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    لکھو("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    لکھو("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

طویل طویل llfunc1(صحیح a)
{
    واپس a * 2;
}

ساخت S {
    صحیح id; 
    حرف شے;
};

طویل طویل صحیح قدر(ساخت S *v)
{
    واپس ((طویل طویل صحیح)v->شے);
}

طویل طویل llfunc2(طویل طویل x, طویل طویل y, صحیح z)
{
    واپس x * y * z;
}

خالی check_opl_save_regs(حرف *a, طویل طویل b, صحیح c)
{
    *a = b < 0 && !c;
}

خالی longlong_test(خالی)
{
    طویل طویل a, b, c;
    صحیح ia;
    غیرعلامتی صحیح ua;
    لکھو("sizeof(long long) = %d\n", حجم(طویل طویل));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    لکھو(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    لکھو(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (طویل طویل)1,
           (طویل طویل)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    لکھو(LONG_LONG_FORMAT "\n", a);

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
    لکھو(XLONG_LONG_FORMAT"\n", c);
#اگر_ختم

    /* long long reg spill test */
    {
          ساخت S a;

          a.شے = 3;
          لکھو("%lld\n", قدر(&a));
    }
    lloptest(0x80000000, 0);

    {
        طویل طویل *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        لکھو("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        لکھو("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    لکھو("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    لکھو(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    طویل طویل *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    غیرعلامتی طویل طویل u = 0x8000000000000001ULL;
    u = (غیرعلامتی)(u + 1);
    لکھو("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (غیرعلامتی)(صحیح)(u + 1);
    لکھو("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    حرف cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    لکھو("check_opl_save_regs: %d\n", cc);
}

خالی manyarg_test(خالی)
{
    LONG_DOUBLE ld = 1234567891234LL;
    لکھو("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    لکھو("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    لکھو("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    لکھو("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    لکھو("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    لکھو("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

خالی*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ساخت X { صحیح _x; };
        ساخت X *x = va_arg(ap, ساخت X *);
        واپس x;
}

خالی vprintf1(ثابت حرف *fmt, ...)
{
    va_list ap, aq;
    ثابت حرف *p;
    صحیح c, i;
    دوہرا d;
    طویل طویل ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    برائے(;;) {
        c = *p;
        اگر (c == '\0')
            توڑو;
        p++;
        اگر (c == '%') {
            c = *p;
            انتخاب(c) {
            حالت '\0':
                جاؤ the_انتہا;
            حالت 'd':
                i = va_arg(ap, صحیح);
                لکھو("%d", i);
                توڑو;
            حالت 'f':
                d = va_arg(ap, دوہرا);
                لکھو("%f", d);
                توڑو;
            حالت 'l':
                ll = va_arg(ap, طویل طویل);
                لکھو(LONG_LONG_FORMAT, ll);
                توڑو;
            حالت 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                لکھو("%Lf", ld);
                توڑو;
            }
            p++;
        } ورنہ {
            حرف_لکھو(c);
        }
    }
 the_انتہا:
    va_end(aq);
    va_end(ap);
}

ساخت myspace {
    مختصر صحیح profile;
};
ساخت myspace2 {
#اگر CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    حرف a[1];
#ورنہ
    حرف a[0];
#اگر_ختم
};
ساخت myspace3 {
    حرف a[1];
};
ساخت myspace4 {
    حرف a[2];
};
ساخت mytest {
    خالی *foo, *bar, *baz;
};

ساخت mytest stdarg_for_struct(ساخت myspace bob, ...)
{
    ساخت myspace george, bill;
    ساخت myspace2 alex1;
    ساخت myspace3 alex2;
    ساخت myspace4 alex3;
    va_list ap;
    مختصر صحیح validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ساخت myspace2);
    alex2    = va_arg(ap, ساخت myspace3);
    alex3    = va_arg(ap, ساخت myspace4);
    bill     = va_arg(ap, ساخت myspace);
    george   = va_arg(ap, ساخت myspace);
    validate = va_arg(ap, صحیح);
    لکھو("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    واپس (ساخت mytest) {};
}

خالی stdarg_for_libc(ثابت حرف *fmt, ...)
{
    va_list دلائل;
    va_start(دلائل, fmt);
    vprintf(fmt, دلائل);
    va_end(دلائل);
}

خالی stdarg_syntax(صحیح n, ...)
{
    صحیح i;
    va_list ap;
    اگر (1)
      va_start(ap, n);
    ورنہ
      ;
    i = va_arg(ap, صحیح);
    لکھو("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

قسمتعریف ساخت{
    دوہرا x,y;
} نقطہ;
نقطہ pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ساکن خالی stdarg_double_struct(صحیح nargs, صحیح posd,...)
{
    صحیح i;
    دوہرا d;
    نقطہ pi;
    va_list دلائل;

    لکھو ("stdarg_double_struct: %d\n", posd);
    va_start(دلائل,posd);
    برائے(i = 0; i < nargs; i++) {
        اگر (i == posd) {
            d = va_arg (دلائل, دوہرا);
            لکھو ("d %d = %g\n", i, d);
        }
        ورنہ {
            pi = va_arg (دلائل, نقطہ);
            لکھو ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(دلائل);
}

خالی stdarg_test(خالی)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ساخت myspace bob;
    ساخت myspace2 bob2;
    ساخت myspace3 bob3;
    ساخت myspace4 bob4;

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
#اگر_ختم
}

صحیح reltab[3] = { 1, 2, 3 };

صحیح *rel1 = &reltab[1];
صحیح *rel2 = &reltab[2];

خالی getmyaddress(خالی)
{
    لکھو("in getmyaddress\n");
}

#اگر_تعریف_شدہ __LP64__
طویل __pa_symbol(خالی)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       واپس ((طویل)(((غیرعلامتی طویل)(&rel1))) - (0xffffffff80000000UL));
}
#اگر_ختم

uintptr_t theaddress = (uintptr_t)getmyaddress;
خالی relocation_test(خالی)
{
    خالی (*fptr)(خالی) = (خالی (*)(خالی))theaddress;
    لکھو("*rel1=%d\n", *rel1);
    لکھو("*rel2=%d\n", *rel2);
    fptr();
#اگر_تعریف_شدہ __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    لکھو("pa_symbol: %d\n", (طویل)&rel1 == __pa_symbol() - 0x80000000);
#اگر_ختم
}

خالی old_style_f(a,b,c)
     صحیح a, b;
     دوہرا c;
{
    لکھو("a=%d b=%d b=%f\n", a, b, c);
}

خالی decl_func1(صحیح cmpfn())
{
    لکھو("cmpfn=%lx\n", (طویل)cmpfn);
}

خالی decl_func2(cmpfn)
صحیح cmpfn();
{
    لکھو("cmpfn=%lx\n", (طویل)cmpfn);
}

خالی old_style_function_test(خالی)
{
#اگر CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ورنہ
    old_style_f((خالی *)1, 2, 3.0);
#اگر_ختم
    decl_func1(تہی);
    decl_func2(تہی);
}

خالی alloca_test()
{
    حرف *p = alloca(16);
    strcpy(p,"123456789012345");
    لکھو("alloca: p is %s\n", p);
    حرف *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    لکھو("alloca: %s\n", strcpy(alloca(لڑی_لمبائی(demo)+1),demo) );
}

خالی *bounds_checking_is_enabled()
{
    حرف ca[10], *cp = ca-1;
    واپس (ca != cp + 1) ? cp : تہی;
}

قسمتعریف صحیح constant_negative_array_سائز_as_compile_وقت_assertion_idiom[(1 ? 2 : 0) - 1];

خالی c99_vla_test_1(صحیح size1, صحیح size2)
{
    صحیح سائز = size1 * size2;
    صحیح tab1[سائز][2], tab2[10][2];
    خالی *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    سائز = سائز-1;
    
    لکھو("Test C99 VLA 1 (sizeof): ");
    لکھو("%s\n", (حجم tab1 == size1 * size2 * 2 * حجم(صحیح)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    لکھو("Test C99 VLA 2 (ptrs subtract): ");
    لکھو("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (حجم(صحیح) * 2)) ? "PASSED" : "FAILED");
    لکھو("Test C99 VLA 3 (ptr add): ");
    لکھو("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * حجم(صحیح)) ? "PASSED" : "FAILED");
    لکھو("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    لکھو("%s\n", (*((صحیح *) (tab1_ptr + (size1 * 2 + 1) * حجم(صحیح))) == 42) ? "PASSED" : "FAILED");

    لکھو("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    اگر (bad_ptr = bounds_checking_is_enabled()) {
        صحیح *t1 = &tab1[size1 * size2 - 1][3];
        صحیح *t2 = &tab2[9][3];
        لکھو("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        لکھو("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        حرف*c1 = 1 + حجم(tab1) + (حرف*)tab1;
        حرف*c2 = 1 + حجم(tab2) + (حرف*)tab2;
        لکھو("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        لکھو("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        صحیح *i1 = tab1[-1];
        صحیح *i2 = tab2[-1];
        لکھو("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        لکھو("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        صحیح *x1 = tab1[size1 * size2 + 1];
        صحیح *x2 = tab2[10 + 1];
        لکھو("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        لکھو("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ورنہ {
        لکھو("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    لکھو("\n");
}

خالی c99_vla_test_2(صحیح d, صحیح h, صحیح w)
{
    صحیح x, y, z;
    صحیح (*arr)[h][w] = حافظہ_دو(حجم(صحیح) * d*h*w);
    صحیح c = 1;
    ساکن صحیح (*starr)[h][w];

    لکھو("Test C99 VLA 6 (pointer)\n");

    برائے (z=0; z<d; z++) {
        برائے (y=0; y<h; y++) {
            برائے (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    برائے (z=0; z<d; z++) {
        برائے (y=0; y<h; y++) {
            برائے (x=0; x<w; x++) {
                لکھو(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    لکھو(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        حجم (*arr), حجم (*arr)[0], حجم (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == حجم (*arr + 1) - حجم arr,
        0 == حجم حجم *arr - حجم arr,
        starr[0][2][3] == arr[1][2][3]
        );
    آزاد (arr);
}

خالی c99_vla_test_3a (صحیح arr[2][3][4])
{
    لکھو ("%d\n", arr[1][2][3]);
}

خالی c99_vla_test_3b(صحیح s, صحیح arr[s][3][4])
{
    لکھو ("%d\n", arr[1][2][3]);
}

خالی c99_vla_test_3c(صحیح s, صحیح arr[2][s][4])
{
    لکھو ("%d\n", arr[1][2][3]);
}

خالی c99_vla_test_3d(صحیح s, صحیح arr[2][3][s])
{
    لکھو ("%d\n", arr[1][2][3]);
}

خالی c99_vla_test_3e(صحیح s, صحیح arr[][3][--s])
{
    لکھو ("%d %d %d\n", حجم arr, s, arr[1][2][3]);
}

خالی c99_vla_test_3(خالی)
{
    صحیح a[2][3][4];

    memset (a, 0, حجم(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

خالی c99_vla_test(خالی)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


خالی sizeof_test(خالی)
{
    صحیح a;
    صحیح **ptr;

    لکھو("sizeof(int) = %d\n", حجم(صحیح));
    لکھو("sizeof(unsigned int) = %d\n", حجم(غیرعلامتی صحیح));
    لکھو("sizeof(long) = %d\n", حجم(طویل));
    لکھو("sizeof(unsigned long) = %d\n", حجم(غیرعلامتی طویل));
    لکھو("sizeof(short) = %d\n", حجم(مختصر));
    لکھو("sizeof(unsigned short) = %d\n", حجم(غیرعلامتی مختصر));
    لکھو("sizeof(char) = %d\n", حجم(حرف));
    لکھو("sizeof(unsigned char) = %d\n", حجم(غیرعلامتی حرف));
    لکھو("sizeof(func) = %d\n", حجم sizeof_test());
    a = 1;
    لکھو("sizeof(a++) = %d\n", حجم a++);
    لکھو("a=%d\n", a);
    ptr = تہی;
    لکھو("sizeof(**ptr) = %d\n", حجم (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    لکھو("sizeof(sizeof(int) = %d\n", حجم(حجم(صحیح)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -حجم(uintptr_t);
    لکھو ("%lu %lu\n", t, t2);

    /* some alignof tests */
    لکھو("__alignof__(int) = %d\n", __alignof__(صحیح));
    لکھو("__alignof__(unsigned int) = %d\n", __alignof__(غیرعلامتی صحیح));
    لکھو("__alignof__(short) = %d\n", __alignof__(مختصر));
    لکھو("__alignof__(unsigned short) = %d\n", __alignof__(غیرعلامتی مختصر));
    لکھو("__alignof__(char) = %d\n", __alignof__(حرف));
    لکھو("__alignof__(unsigned char) = %d\n", __alignof__(غیرعلامتی حرف));
    لکھو("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    لکھو("sizeof(char[1+2*a]) = %d\n", حجم(حرف[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    لکھو("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   حجم( (ساخت {صحیح i; صحیح j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    لکھو("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   حجم (ساخت {مختصر i; مختصر j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    لکھو("sizeof(t && 0) = %d\n", حجم(t && 0));
    لکھو("sizeof(1 && 1) = %d\n", حجم(1 && 1));
    لکھو("sizeof(t || 1) = %d\n", حجم(t || 1));
    لکھو("sizeof(0 || 0) = %d\n", حجم(0 || 0));

    صحیح arr[4], fn();
    لکھو("sizeof(0, arr) = %d\n", حجم(0, arr));
    لکھو("sizeof(0, fn) = %d\n", حجم(0, fn));
}

خالی typeof_test(خالی)
{
    دوہرا a;
    typeof(a) b;
    typeof(اعشاری) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    لکھو("a=%f b=%f c=%f\n", a, b, c);
}


ساخت hlist_گرہ;
ساخت hlist_سر {
    ساخت hlist_گرہ *پہلا, *آخری;
};

خالی consume_ulong (غیرعلامتی طویل i)
{
    i = 0;
}

خالی statement_اظہاریہ_test(خالی)
{
    صحیح a, i;

    /* Basic stmt expr test */
    a = 0;
    برائے(i=0;i<10;i++) {
        a += 1 + 
            ( { صحیح b, j; 
                b = 0; 
                برائے(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    لکھو("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    خالی *v = (خالی*)39;
    typeof(({
	    (ساخت hlist_گرہ *)v;
	    })) x;
    typeof (x)
	ptr = (ساخت hlist_گرہ *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#تعریف_کرو some_attr     __attribute__((aligned(1)))
#تعریف_کرو tps(str) ({                  \
            ساکن ثابت حرف *t some_attr = str; \
            t;                                    \
          })
    لکھو ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    صحیح t = 40;
    صحیح b = ({ صحیح t = 41; t; });
    صحیح c = ({ صحیح t = 42; t; });

    /* Test that aggregate return values work.  */
    ساخت hlist_سر h
	= ({
	   قسمتعریف ساخت hlist_سر T;
	   طویل pre = 48;
	   T t = { (خالی*)43, (خالی*)44 };
	   طویل post = 49;
	   t;
	   });
    لکھو ("stmtexpr: %d %d %d\n", t, b, c);
    لکھو ("stmtexpr: %ld %ld\n", (طویل)h.پہلا, (طویل)h.آخری);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (غیرعلامتی طویل)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: اگر (i++ == 0) جاؤ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      جاؤ LBL;
    });
  LBL:
    لکھو("stmtexpr: %d should be 2\n", i);
}

خالی local_label_test(خالی)
{
    صحیح a;
    جاؤ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        جاؤ l1;
    l4:
        لکھو("aa1\n");
        جاؤ l3;
    l2:
        لکھو("aa3\n");
        جاؤ l4;
    l1:
        لکھو("aa2\n");
        جاؤ l2;
    l3:;
        1;
    });
    لکھو("a=%d\n", a);
    واپس;
 l4:
    لکھو("bb1\n");
    جاؤ l2;
 l1:
    لکھو("bb2\n");
    جاؤ l4;
}

/* inline assembler test */
#اگر (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

قسمتعریف __SIZE_TYPE__ لفظ;

/* from linux kernel */
ساکن حرف * strncat1(حرف * dest,ثابت حرف * src,سائز_t گنتی_2)
{
لفظ d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (گنتی_2)
	: "memory");
واپس dest;
}

ساکن حرف * strncat2(حرف * dest,ثابت حرف * src,سائز_t گنتی_2)
{
لفظ d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (گنتی_2)
	: "memory");
واپس dest;
}

ساکن اندرونی خالی * memcpy1(خالی * مقصد, ثابت خالی * from, سائز_t n)
{
لفظ d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((لفظ) مقصد),"2" ((لفظ) from)
	: "memory");
واپس (مقصد);
}

ساکن اندرونی خالی * memcpy2(خالی * مقصد, ثابت خالی * from, سائز_t n)
{
لفظ d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((لفظ) مقصد),"2" ((لفظ) from)
	: "memory");
واپس (مقصد);
}

ساکن __inline__ خالی sigaddset1(غیرعلامتی صحیح *سیٹ, صحیح _sig)
{
	__asm__("btsl %1,%0" : "=m"(*سیٹ) : "Ir"(_sig - 1) : "cc");
}

ساکن __inline__ خالی sigdelset1(غیرعلامتی صحیح *سیٹ, صحیح _sig)
{
	asm("btrl %1,%0" : "=m"(*سیٹ) : "Ir"(_sig - 1) : "cc", "flags");
}

#اگر_تعریف_شدہ __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ساکن __inline__ __const__ غیرعلامتی صحیح swab32(غیرعلامتی صحیح x)
{
        واپس ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ورنہ
ساکن __inline__ __const__ غیرعلامتی صحیح swab32(غیرعلامتی صحیح x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	واپس x;
}
#اگر_ختم

ساکن __inline__ غیرعلامتی طویل طویل mul64(غیرعلامتی صحیح a, غیرعلامتی صحیح b)
{
    غیرعلامتی طویل طویل res;
#اگر_تعریف_شدہ __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    غیرعلامتی صحیح resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((غیرعلامتی طویل طویل)resh << 32) | resl;
#ورنہ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#اگر_ختم
    واپس res;
}

ساکن __inline__ غیرعلامتی طویل طویل inc64(غیرعلامتی طویل طویل a)
{
    غیرعلامتی طویل طویل res;
#اگر_تعریف_شدہ __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ورنہ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#اگر_ختم
    واپس res;
}

ساخت struct123 {
    صحیح a;
    صحیح b;
};
ساخت struct1231 {
    لفظ addr;
};

لفظ mconstraint_test(ساخت struct1231 *r)
{
    لفظ ret;
    غیرعلامتی صحیح a[2];
    a[0] = 0;
    __asm__ متلون ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ساخت struct123 *)r->addr));
    واپس ret + a[0];
}

#اگر_تعریف_شدہ __x86_64__
صحیح fls64(غیرعلامتی طویل طویل x)
{
  صحیح bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  واپس bitpos + 1;
}
#اگر_ختم

خالی other_constraints_test(خالی)
{
    لفظ ret;
    صحیح var;
#اگر CC_NAME != CC_clang
    __asm__ متلون ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    لکھو ("oc1: %d\n", ret == (لفظ)&var);
#اگر_ختم
}

#اگر_غیر_تعریف_شدہ _WIN32
/* Test global asm blocks playing with aliases.  */
خالی بنیاد_func(خالی)
{
  لکھو ("asmc: base\n");
}

#اگر_غیر_تعریف_شدہ __APPLE__
خارجی خالی override_func1 (خالی);
خارجی خالی override_func2 (خالی);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

خالی override_func2 (خالی)
{
  لکھو ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
خارجی صحیح bug_جدول[] __attribute__((section("__bug_table")));
حرف * get_asm_string (خالی)
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
#اگر_غیر_تعریف_شدہ __clang__
  خارجی صحیح some_علامت;
  asm متلون (".globl some_symbol\n"
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
  واپس str;
#ورنہ
  واپس (حرف *) "A string";
#اگر_ختم
}

/* This checks another constructs with local labels.  */
خارجی غیرعلامتی حرف alld_stuff[];
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

خالی asm_local_label_diff (خالی)
{
  لکھو ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#اگر_ختم //!__APPLE__
#اگر_ختم //!_WIN32

/* This checks that static local variables are available from assembler.  */
خالی asm_local_statics (خالی)
{
  ساکن صحیح localint = 41;
  asm("incl %0" : "+m" (localint));
  لکھو ("asm_local_statics: %d\n", localint);
}

ساکن
غیرعلامتی صحیح سیٹ;

خالی fancy_copy (غیرعلامتی *اندر, غیرعلامتی *برآمد)
{
  asm متلون ("" : "=r" (*برآمد) : "0" (*اندر));
}

خالی fancy_copy2 (غیرعلامتی *اندر, غیرعلامتی *برآمد)
{
  asm متلون ("mov %0,(%1)" : : "r" (*اندر), "r" (برآمد) : "memory");
}

#اگر defined __x86_64__
خالی clobber_r12(خالی)
{
    asm متلون("mov $1, %%r12" ::: "r12");
}
#اگر_ختم

خالی test_بلند_clobbers_really(خالی)
{
#اگر defined __x86_64__
    اندراج لفظ val asm("r12");
    لفظ val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm متلون("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm متلون("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    لکھو("asmhc: 0x%x\n", val2);
#اگر_ختم
}

خالی test_بلند_clobbers(خالی)
{
#اگر defined __x86_64__
    لفظ x1, x2;
    asm متلون("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_بلند_clobbers_really();
    asm متلون("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm متلون("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#اگر_ختم
}

ساکن طویل cpu_نمبر;
خالی trace_console(طویل len, طویل len2)
{
#اگر_تعریف_شدہ __x86_64__
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
              طویل pscr_ret__;
              انتخاب(len) {
                حالت 4:
                    {
                       طویل pfo_ret__;
                       انتخاب (len2) {
                         حالت 8:	لکھو("bla"); pfo_ret__ = 42; توڑو;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  توڑو;
                حالت 8:
                    {
                       طویل pfo_ret__;
                       انتخاب (len2) {
                         حالت 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_نمبر));	توڑو;
                         حالت 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_نمبر));	توڑو;
                         حالت 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_نمبر));	توڑو;
                         حالت 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_نمبر));	توڑو;
                         طےشدہ: لکھو("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  توڑو;
              }
              pscr_ret__;
            }))
      {
        لکھو("huh?\n");
      }
#اگر_ختم
}

خالی test_asm_dead_رمز(خالی)
{
  لفظ rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm متلون ("" : "=D" (rdi) : "0" (0));
  (خالی)حجم (({
      صحیح var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm متلون ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

خالی test_asm_call(خالی)
{
#اگر defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ساکن حرف str[] = "PATH";
  حرف *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm متلون ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#اگر 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ورنہ
		"call getenv;"
#اگر_ختم
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  لکھو("asmd: %s\n", s);
#اگر_ختم
}

#اگر defined __x86_64__
# define RX "(%rip)"
#ورنہ
# define RX
#اگر_ختم

خالی asm_dot_test(خالی)
{
#اگر_غیر_تعریف_شدہ __APPLE__
    صحیح x;
    برائے (x = 1;; ++x) {
        صحیح r = x;
        انتخاب (x) {
        حالت 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        حالت 2:
#اگر_غیر_تعریف_شدہ __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ورنہ
            asm(".text; mov $123, %eax; jmp p0");
#اگر_ختم
	حالت 3:
#اگر !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ورنہ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#اگر_ختم
            asm(".text; mov X"RX",%eax; jmp p0");
        حالت 4:
#اگر_تعریف_شدہ __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ورنہ
#اگر_غیر_تعریف_شدہ _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ورنہ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#اگر_ختم
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#اگر_ختم
        حالت 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); توڑو;
	}
        اگر (r == x)
            توڑو;
        لکھو("asm_dot_test %d: %d\n", x, r);
    }
#اگر_ختم
}

خالی asm_pcrel_test(خالی)
{
    غیرعلامتی o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    لکھو("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

خالی asm_test(خالی)
{
    حرف buf[128];
    غیرعلامتی صحیح val, val2;
    ساخت struct123 s1;
    ساخت struct1231 s2 = { (لفظ)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    صحیح بنیاد_func = 42;
    خالی override_func3 (خالی);
    لفظ asmret;
#اگر_تعریف_شدہ BOOL_ISOC99
    _Bool somebool;
#اگر_ختم
    اندراج صحیح regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm متلون ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm متلون ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    لکھو("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    لکھو("%s\n", buf);

    /* 'A' constraint test */
    لکھو("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    لکھو("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    لکھو("mconstraint: %d", mconstraint_test(&s2));
    لکھو(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    سیٹ = 0xff;
    sigdelset1(&سیٹ, 2);
    sigaddset1(&سیٹ, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    جاؤ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(سیٹ) : "Ir"(20) : "cc");
    لکھو("set=0x%x\n", سیٹ);
    val = 0x01020304;
    لکھو("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#اگر_غیر_تعریف_شدہ _WIN32
#اگر_غیر_تعریف_شدہ __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm متلون(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    لکھو("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#اگر_ختم
#اگر_ختم
    asm_local_statics();
#اگر_غیر_تعریف_شدہ __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm متلون("" : "=r" (asmret) : "0"(s2));
    اگر (asmret != s2.addr)
      لکھو("asmstr: failed\n");
#اگر_ختم
#اگر_تعریف_شدہ BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm متلون("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    اگر (!somebool)
      لکھو("asmbool: failed\n");
#اگر_ختم
    val = 43;
    fancy_copy (&val, &val2);
    لکھو ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    لکھو ("fancycpy2(%d)=%d\n", val, val2);
    asm متلون ("mov $0x4243, %%esi" : "=r" (regvar));
    لکھو ("regvar=%x\n", regvar);
    test_بلند_clobbers();
    trace_console(8, 8);
    test_asm_dead_رمز();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    واپس;
 label1:
    جاؤ label2;
}

#ورنہ

خالی asm_test(خالی)
{
}

#اگر_ختم

#تعریف_کرو COMPAT_TYPE(type1, type2) \
{\
    لکھو("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

صحیح constant_p_var;

صحیح func(خالی);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ساکن خالی builtin_test_بٹ(غیرعلامتی طویل طویل x, صحیح cnt[])
{
#اگر GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    اگر ((غیرعلامتی صحیح) x) cnt[3] += __builtin_clz(x);
    اگر ((غیرعلامتی طویل) x) cnt[4] += __builtin_clzl(x);
    اگر ((غیرعلامتی طویل طویل) x) cnt[5] += __builtin_clzll(x);

    اگر ((غیرعلامتی صحیح) x) cnt[6] += __builtin_ctz(x);
    اگر ((غیرعلامتی طویل) x) cnt[7] += __builtin_ctzl(x);
    اگر ((غیرعلامتی طویل طویل) x) cnt[8] += __builtin_ctzll(x);

#اگر GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#اگر_ختم

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#اگر_ختم
}

خالی builtin_test(خالی)
{
    مختصر s;
    صحیح i;
    طویل طویل ll;
#اگر GCC_MAJOR >= 3
    COMPAT_TYPE(صحیح, صحیح);
    COMPAT_TYPE(صحیح, غیرعلامتی صحیح);
    COMPAT_TYPE(صحیح, حرف);
    COMPAT_TYPE(صحیح, ثابت صحیح);
    COMPAT_TYPE(صحیح, متلون صحیح);
    COMPAT_TYPE(صحیح[2], ثابت صحیح[2]);
    COMPAT_TYPE(صحیح[2][3], متلون صحیح[][3]);
    COMPAT_TYPE(صحیح (*)[], ثابت صحیح (*)[]);
#اگر_غیر_تعریف_شدہ __clang__
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحیح (*)[2])0 : (صحیح (*)[2])0),
                ثابت صحیح (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ثابت صحیح (*)[2][3])0 :
                              (متلون صحیح (*)[2][3])0),
                ثابت متلون صحیح (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (متلون صحیح (*)[2][3])0 :
                              (ثابت صحیح (*)[2][3])0),
                ثابت متلون صحیح (*)[2][3]);
#ورنہ
    /* clang doesn't combine qualifiers through array types */
    لکھو("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    لکھو("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    لکھو("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#اگر_ختم
    COMPAT_TYPE(صحیح *, صحیح *);
    COMPAT_TYPE(صحیح *, خالی *);
    COMPAT_TYPE(صحیح *, ثابت صحیح *);
    COMPAT_TYPE(حرف *, غیرعلامتی حرف *);
    COMPAT_TYPE(حرف *, علامتی حرف *);
    COMPAT_TYPE(حرف *, حرف *);
    COMPAT_TYPE(حرف **, خالی *);
#اگر_ختم
    لکھو("res1 = %d\n", __builtin_constant_p(1));
    لکھو("res2 = %d\n", __builtin_constant_p(1 + 2));
    لکھو("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    لکھو("res4 = %d\n", __builtin_constant_p(constant_p_var));
    لکھو("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    لکھو("res6 = %d\n", __builtin_constant_p(i && 1));
    لکھو("res7 = %d\n", __builtin_constant_p("hi"));
    لکھو("res8 = %d\n", __builtin_constant_p(func()));
#اگر_غیر_تعریف_شدہ __clang__
    لکھو("res10 = %d\n", __builtin_constant_p(i && 0));
    لکھو("res11 = %d\n", __builtin_constant_p(i * 0));
    لکھو("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    لکھو("res13 = %d\n", __builtin_constant_p((1,7)));
#ورنہ
    /* clang doesn't regard these as constant expression */
    لکھو("res10 = 1\n");
    لکھو("res11 = 1\n");
    لکھو("res12 = 1\n");
    لکھو("res13 = 0\n");
#اگر_ختم

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    لکھو("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    لکھو("bce: %d\n", i);
    i = حجم (__builtin_choose_expr (1, ll, s));
    لکھو("bce: %d\n", i);
    i = حجم (__builtin_choose_expr (0, ll, s));
    لکھو("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	صحیح cnt[18];
	غیرعلامتی طویل طویل r = 0;

	memset(cnt, 0, حجم(cnt));
	builtin_test_بٹ(0, cnt);
	builtin_test_بٹ(0xffffffffffffffffull, cnt);
        برائے (i = 0; i < 64; i++)
	    builtin_test_بٹ(1ull << i, cnt);
        برائے (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_بٹ(r, cnt);
	}
	برائے (i = 0; i < 18; i++)
	    لکھو ("%d %d\n", i, cnt[i]);
    }
}

#اگر defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
خالی weak_test(خالی) {}
#ورنہ
خارجی صحیح __attribute__((weak)) weak_f1(خالی);
خارجی صحیح __attribute__((weak)) weak_f2(خالی);
خارجی صحیح                       weak_f3(خالی);
خارجی صحیح __attribute__((weak)) weak_v1;
خارجی صحیح __attribute__((weak)) weak_v2;
خارجی صحیح                       weak_v3;

خارجی صحیح                           (*weak_fpa)() __attribute__((weak));
خارجی صحیح __attribute__((weak))     (*weak_fpb)();
خارجی     __attribute__((weak)) صحیح (*weak_fpc)();

خارجی صحیح                     weak_asm_f1(خالی) asm("weak_asm_f1x") __attribute((weak));
خارجی صحیح __attribute((weak)) weak_asm_f2(خالی) asm("weak_asm_f2x")                    ;
خارجی صحیح __attribute((weak)) weak_asm_f3(خالی) asm("weak_asm_f3x") __attribute((weak));
خارجی صحیح                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
خارجی صحیح __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
خارجی صحیح __attribute((weak)) weak_asm_v3(خالی) asm("weak_asm_v3x") __attribute((weak));

#اگر_غیر_تعریف_شدہ __clang__
ساکن ثابت سائز_t dummy = 0;
خارجی __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
خارجی __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
خارجی __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#اگر_ختم

صحیح some_lib_func(خالی);
صحیح dummy_impl_کا_slf(خالی) { واپس 444; }
#اگر_غیر_تعریف_شدہ __clang__
صحیح some_lib_func(خالی) __attribute__((weak, alias("dummy_impl_of_slf")));
#اگر_ختم

صحیح weak_toolate() __attribute__((weak));
صحیح weak_toolate() { واپس 0; }

خالی __attribute__((weak)) weak_test(خالی)
{
	لکھو("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	لکھو("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	لکھو("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	لکھو("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	لکھو("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	لکھو("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	لکھو("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	لکھو("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	لکھو("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	لکھو("weak_asm_f1=%d\n", weak_asm_f1 != تہی);
	لکھو("weak_asm_f2=%d\n", weak_asm_f2 != تہی);
	لکھو("weak_asm_f3=%d\n", weak_asm_f3 != تہی);
	لکھو("weak_asm_v1=%d\n",&weak_asm_v1 != تہی);
	لکھو("weak_asm_v2=%d\n",&weak_asm_v2 != تہی);
	لکھو("weak_asm_v3=%d\n",&weak_asm_v3 != تہی);
#اگر_تعریف_شدہ __clang__
	لکھو("some_lib_func=444\n");
#ورنہ
	لکھو("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#اگر_ختم
}

صحیح __attribute__((weak)) weak_f2() { واپس 222; }
صحیح __attribute__((weak)) weak_f3() { واپس 333; }
صحیح __attribute__((weak)) weak_v2 = 222;
صحیح __attribute__((weak)) weak_v3 = 333;
#اگر_ختم

خالی const_func(ثابت صحیح a)
{
}

خالی const_warn_test(خالی)
{
    const_func(1);
}

ساخت condstruct {
  صحیح i;
};

صحیح getme (ساخت condstruct *s, صحیح i)
{
  صحیح i1 = (i == 0 ? 0 : s)->i;
  صحیح i2 = (i == 0 ? s : 0)->i;
  صحیح i3 = (i == 0 ? (خالی*)0 : s)->i;
  صحیح i4 = (i == 0 ? s : (خالی*)0)->i;
  واپس i1 + i2 + i3 + i4;
}

ساخت global_ڈیٹا
{
  صحیح a[40];
  صحیح *b[40];
};

ساخت global_ڈیٹا global_ڈیٹا;

صحیح global_ڈیٹا_getstuff (صحیح *, صحیح);

خالی global_ڈیٹا_callit (صحیح i)
{
  *global_ڈیٹا.b[i] = global_ڈیٹا_getstuff (global_ڈیٹا.b[i], 1);
}

صحیح global_ڈیٹا_getstuff (صحیح *p, صحیح i)
{
  واپس *p + i;
}

خالی global_ڈیٹا_test (خالی)
{
  global_ڈیٹا.a[0] = 42;
  global_ڈیٹا.b[0] = &global_ڈیٹا.a[0];
  global_ڈیٹا_callit (0);
  لکھو ("%d\n", global_ڈیٹا.a[0]);
}

ساخت cmpcmpS
{
  غیرعلامتی حرف fill : 3;
  غیرعلامتی حرف b1 : 1;
  غیرعلامتی حرف b2 : 1;
  غیرعلامتی حرف fill2 : 3;
};

صحیح glob1, glob2, glob3;

خالی compare_comparisons (ساخت cmpcmpS *s)
{
  اگر (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    لکھو ("comparing comparisons broken\n");
}

خالی cmp_comparison_test(خالی)
{
  ساخت cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

صحیح fcompare (دوہرا a, دوہرا b, صحیح رمز)
{
  انتخاب (رمز) {
    حالت 0: واپس a == b;
    حالت 1: واپس a != b;
    حالت 2: واپس a < b;
    حالت 3: واپس a >= b;
    حالت 4: واپس a > b;
    حالت 5: واپس a <= b;
  }
  واپس 0;
}

خالی math_cmp_test(خالی)
{
  دوہرا nan = 0.0/0.0;
  دوہرا one = 1.0;
  دوہرا two = 2.0;
  صحیح comp = 0;
  صحیح v;
#تعریف_کرو bug(a,b,op,iop,part) لکھو("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#تعریف_کرو FCMP(a,b,op,iop,رمز) \
  اگر (fcompare (a,b,رمز))    \
    bug (a,b,op,iop,1); \
  اگر (a op b) \
    bug (a,b,op,iop,2); \
  اگر (a iop b) \
    ; \
  ورنہ \
    bug (a,b,op,iop,3); \
  اگر ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  اگر ((a iop b) || comp) \
    ; \
  ورنہ \
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

دوہرا get100 () { واپس 100.0; }

خالی callsave_test(خالی)
{
  صحیح i, s; دوہرا *d; دوہرا t;
  s = حجم (دوہرا);
  لکھو ("callsavetest: %d\n", s);
  d = alloca (حجم(دوہرا));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  لکھو ("%d\n", i);
}


خالی bfa3(ptrdiff_t str_انحراف)
{
    لکھو("bfa3: %s\n", (حرف *)__builtin_frame_address(3) + str_انحراف);
}
خالی bfa2(ptrdiff_t str_انحراف)
{
    لکھو("bfa2: %s\n", (حرف *)__builtin_frame_address(2) + str_انحراف);
    bfa3(str_انحراف);
}
خالی bfa1(ptrdiff_t str_انحراف)
{
    لکھو("bfa1: %s\n", (حرف *)__builtin_frame_address(1) + str_انحراف);
    bfa2(str_انحراف);
}

خالی builtin_چوکھٹا_پتہ_test(خالی)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#اگر_غیر_تعریف_شدہ __arm__
    حرف str[] = "__builtin_frame_address";
    حرف *fp0 = __builtin_frame_address(0);

    لکھو("str: %s\n", str);
#اگر_غیر_تعریف_شدہ __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#اگر_ختم
#اگر_ختم
}

حرف بذریعہ_volatile (حرف i)
{
  حرف متلون vi;
  vi = i;
  واپس vi;
}

خالی volatile_test(خالی)
{
    اگر (بذریعہ_volatile (42) != 42)
      لکھو (" broken\n");
    ورنہ
      لکھو (" ok\n");
}

ساخت __attribute__((__packed__)) Spacked {
    حرف a;
    مختصر b;
    صحیح c;
};
ساخت Spacked spacked;
قسمتعریف ساخت __attribute__((__packed__)) {
    حرف a;
    مختصر b;
    صحیح c;
} Spacked2;
Spacked2 spacked2;
قسمتعریف ساخت Spacked3_s {
    حرف a;
    مختصر b;
    صحیح c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ساخت gate_struct64 {
    غیرعلامتی مختصر انحراف_کم;
    غیرعلامتی مختصر segment;
    غیرعلامتی ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    غیرعلامتی مختصر انحراف_درمیان;
    غیرعلامتی انحراف_بلند;
    غیرعلامتی zero1;
} __attribute__((packed));
قسمتعریف ساخت gate_struct64 gate_desc;
gate_desc a_gate_desc;
خالی attrib_test(خالی)
{
#اگر_غیر_تعریف_شدہ _WIN32
  لکھو("attr: %d %d %d %d\n", حجم(ساخت Spacked),
	 حجم(spacked), حجم(Spacked2), حجم(spacked2));
  لکھو("attr: %d %d\n", حجم(Spacked3), حجم(spacked3));
  لکھو("attr: %d %d\n", حجم(gate_desc), حجم(a_gate_desc));
#اگر_ختم
}
خارجی __attribute__((__unused__)) حرف * __attribute__((__unused__)) *
strange_attrib_placement (خالی);

خالی * __attribute__((__unused__)) get_void_ptr (خالی *a)
{
  واپس a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ساکن اندرونی
صحیح __get_order(غیرعلامتی طویل طویل سائز)
{
  صحیح ترتیب;
  سائز -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ساخت S { صحیح i : 1; } s; // constructed for this '1'
    }
  ترتیب = سائز;
  واپس ترتیب;
}

/* This just forces the above inline function to be actually emitted.  */
صحیح force_get_ترتیب(غیرعلامتی طویل s)
{
    واپس __get_order(s);
}

#تعریف_کرو pv(m) لکھو(حجم (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
خالی bounds_check1_test (خالی)
{
    ساخت s {
        صحیح x;
        طویل طویل y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
خالی map_جوڑو(صحیح a, صحیح b, صحیح c, صحیح d, صحیح e, صحیح f, صحیح g, صحیح h, صحیح i)
{
  لکھو ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

خالی func_arg_test(خالی)
{
    صحیح a = 0;
    صحیح b = 1;
    map_جوڑو(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#تعریف_کرو CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#اگر_تعریف_شدہ __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#اگر_ختم

#تعریف_کرو	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
خالی whitespace_test(خالی)
{
    حرف *str;
    صحیح tcc_test = 1;

#اگر 1
    pri\
ntf("whitspace:\n");
#اگر_ختم
    pf("N=%d\n", 2);

#اگر_تعریف_شدہ CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#اگر_ختم

    pri\
\
ntf("min=%d\n", 4);

#اگر_تعریف_شدہ ACCEPT_LF_اندر_لڑیاں
    لکھو("len1=%d\n", لڑی_لمبائی("
"));
#اگر_تعریف_شدہ CORRECT_CR_HANDLING
    str = "
";
    لکھو("len1=%d str[0]=%d\n", لڑی_لمبائی(str), str[0]);
#اگر_ختم
    لکھو("len1=%d\n", لڑی_لمبائی("a
"));
#ورنہ
    لکھو("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#اگر_ختم /* ACCEPT_LF_IN_STRINGS */

#اگر_تعریف_شدہ __LINE__
    لکھو("__LINE__ defined\n");
#اگر_ختم

#اگر 0
    /* wrong with GCC */
    لکھو("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#سطر 1111
    لکھو("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#سطر 2222 "test"
    لکھو("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#اگر_ختم

    لکھو("\\
"12\\
063\\
n 456\"\n");

    لکھو ("%d\n",
#اگر 1
	    tcc_test
#اگر_ختم
            );

}

#تعریف_کرو تسلسل_2(test) puts("---- " #test " ----"), test(), puts("")

صحیح مین(صحیح argc, حرف **argv)
{
    تسلسل_2(whitespace_test);
    تسلسل_2(macro_test);
    تسلسل_2(recursive_macro_test);
    تسلسل_2(string_test);
    تسلسل_2(اظہاریہ_test);
    تسلسل_2(scope_test);
    تسلسل_2(scope2_test);
    تسلسل_2(forward_test);
    تسلسل_2(funcptr_test);
    تسلسل_2(if_test);
    تسلسل_2(loop_test);
    تسلسل_2(switch_test);
    تسلسل_2(goto_test);
    تسلسل_2(enum_test);
    تسلسل_2(typedef_test);
    تسلسل_2(struct_test);
    تسلسل_2(array_test);
    تسلسل_2(اظہاریہ_ptr_test);
    تسلسل_2(bool_test);
    تسلسل_2(optimize_برآمد_test);
    تسلسل_2(expr2_test);
    تسلسل_2(constant_اظہاریہ_test);
    تسلسل_2(اظہاریہ_cmp_test);
    تسلسل_2(char_short_test);
    تسلسل_2(init_test);
    تسلسل_2(compound_literal_test);
    تسلسل_2(kr_test);
    تسلسل_2(struct_تفویض_test);
    تسلسل_2(cast_test);
    تسلسل_2(bitfield_test);
    تسلسل_2(c99_bool_test);
    تسلسل_2(float_test);
    تسلسل_2(longlong_test);
    تسلسل_2(manyarg_test);
    تسلسل_2(stdarg_test);
    تسلسل_2(relocation_test);
    تسلسل_2(old_style_function_test);
    تسلسل_2(alloca_test);
    تسلسل_2(c99_vla_test);
    تسلسل_2(sizeof_test);
    تسلسل_2(typeof_test);
    تسلسل_2(statement_اظہاریہ_test);
    تسلسل_2(local_label_test);
    تسلسل_2(asm_test);
    تسلسل_2(builtin_test);
    تسلسل_2(weak_test);
    تسلسل_2(global_ڈیٹا_test);
    تسلسل_2(cmp_comparison_test);
    تسلسل_2(math_cmp_test);
    تسلسل_2(callsave_test);
    تسلسل_2(builtin_چوکھٹا_پتہ_test);
    تسلسل_2(volatile_test);
    تسلسل_2(attrib_test);
    تسلسل_2(bounds_check1_test);
    تسلسل_2(func_arg_test);

    واپس 0;
}
