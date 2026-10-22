/*
 * TCC auto test program
 */
#अन्तर्भाव "config.h"

/* identify the configured reference compiler in use */
#परिभाषय CC_gcc 1
#परिभाषय CC_clang 2
#परिभाषय CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#परिभाषय ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#परिभाषय BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#परिभाषय C99_MACROS

#यदि defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#परिभाषय LONG_LONG_FORMAT "%lld"
#परिभाषय ULONG_LONG_FORMAT "%llu"
#परिभाषय XLONG_LONG_FORMAT "%llx"
#अन्यथा
#परिभाषय LONG_LONG_FORMAT "%Ld"
#परिभाषय ULONG_LONG_FORMAT "%Lu"
#परिभाषय XLONG_LONG_FORMAT "%Lx"
#यदि_अन्तः

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#यदि defined(_WIN32)
#परिभाषय LONG_DOUBLE द्विगुण
#परिभाषय LONG_DOUBLE_LITERAL(x) x
#अन्यथा
#परिभाषय LONG_DOUBLE दीर्घ द्विगुण
#परिभाषय LONG_DOUBLE_LITERAL(x) x ## L
#यदि_अन्तः

प्रकारनिर्देश __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#परिभाषय TCCLIB_INC <tcclib.h>
#परिभाषय TCCLIB_INC1 <tcclib
#परिभाषय TCCLIB_INC2 h>
#परिभाषय TCCLIB_INC3 "tcclib.h"

#अन्तर्भाव TCCLIB_INC

#अन्तर्भाव TCCLIB_INC1.TCCLIB_INC2

#अन्तर्भाव TCCLIB_INC1.h>

#अन्तर्भाव TCCLIB_INC3

#अन्तर्भाव <tcclib.h>

#अन्तर्भाव "tcclib.h"

#अन्तर्भाव "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#परिभाषय INC(name) <tests/name.h>
#परिभाषय funnyname 42test.h
#परिभाषय incdir tests/
#यदि_परिभाषितम् __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#परिभाषय incname <tests/42test.h>
#अन्यथा
#परिभाषय incname < incdir funnyname >
#यदि_अन्तः
#परिभाषय __stringify(x) #x
#परिभाषय stringify(x) __stringify(x)
#अन्तर्भाव INC(42test)
#अन्तर्भाव incname
#अन्तर्भाव stringify(funnyname)

पूर्णाङ्क fib(पूर्णाङ्क n);
शून्य अङ्कः(पूर्णाङ्क n);
शून्य forward_ref(शून्य);
पूर्णाङ्क isid(पूर्णाङ्क c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
शून्य funny_पङ्क्तिः_continuation (पूर्णाङ्क, ..\
. );

#परिभाषय A 2
#परिभाषय N 1234 + A
#परिभाषय pf प्रारूप_लिख
#परिभाषय M1(a, b)  (a) + (b)

#परिभाषय str\
(s) # s
#परिभाषय glue(a, b) a ## b
#परिभाषय xglue(a, b) glue(a, b)
#परिभाषय HIGHLOW "hello"
#परिभाषय नीचः_2 नीचः_2 ", world"

स्थिर पूर्णाङ्क onetwothree = 123;
#परिभाषय onetwothree4 onetwothree
#परिभाषय onetwothree xglue(onetwothree,4)

#परिभाषय min(a, b) ((a) < (b) ? (a) : (b))

#यदि_परिभाषितम् C99_MACROS
#परिभाषय dprintf(level,...) प्रारूप_लिख(__VA_ARGS__)
#यदि_अन्तः

/* gcc vararg macros */
#परिभाषय dprintf1(level, fmt, तर्काः...) प्रारूप_लिख(fmt, ## तर्काः)

#परिभाषय MACRO_NOARGS()

#परिभाषय TEST_CALL(f, ...) f(__VA_ARGS__)
#परिभाषय TEST_CONST()      123

#परिभाषय AAA 3
#अपरिभाषय AAA
#परिभाषय AAA 4

#यदि 1
#परिभाषय B3 1
#नोचेद्यदि 1
#परिभाषय B3 2
#नोचेद्यदि 0
#परिभाषय B3 3
#अन्यथा
#परिभाषय B3 4
#यदि_अन्तः

#परिभाषय __INT64_C(c)	c ## LL
#परिभाषय INT64_MIN	(-__INT64_C(9223372036854775807)-1)

पूर्णाङ्क qq(पूर्णाङ्क x)
{
    प्रत्यागम x + 40;
}
#परिभाषय qq(x) x

#परिभाषय spin_तालकम्(तालकम्) कुरु { } यावत् (0)
#परिभाषय wq_spin_तालकम् spin_तालकम्
#परिभाषय TEST2() wq_spin_तालकम्(a)

शून्य macro_test(शून्य)
{
    pf("N=%d\n", N);
    प्रारूप_लिख("aaa=%d\n", AAA);

    प्रारूप_लिख("min=%d\n", min(1, min(2, -1)));

    प्रारूप_लिख("s1=%s\n", glue(उच्चः_2, नीचः_2));
    प्रारूप_लिख("s2=%s\n", xglue(उच्चः_2, नीचः_2));
    प्रारूप_लिख("s3=%s\n", str("c"));
    प्रारूप_लिख("s4=%s\n", str(a1));
    प्रारूप_लिख("B3=%d\n", B3);

    प्रारूप_लिख("onetwothree=%d\n", onetwothree);

#यदि_परिभाषितम् A
    प्रारूप_लिख("A defined\n");
#यदि_अन्तः
#यदि_परिभाषितम् B
    प्रारूप_लिख("B defined\n");
#यदि_अन्तः
#यदि_परिभाषितम् A
    प्रारूप_लिख("A defined\n");
#अन्यथा
    प्रारूप_लिख("A not defined\n");
#यदि_अन्तः
#यदि_परिभाषितम् B
    प्रारूप_लिख("B defined\n");
#अन्यथा
    प्रारूप_लिख("B not defined\n");
#यदि_अन्तः

#यदि_परिभाषितम् A
    प्रारूप_लिख("A defined\n");
#यदि_परिभाषितम् B
    प्रारूप_लिख("B1 defined\n");
#अन्यथा
    प्रारूप_लिख("B1 not defined\n");
#यदि_अन्तः
#अन्यथा
    प्रारूप_लिख("A not defined\n");
#यदि_परिभाषितम् B
    प्रारूप_लिख("B2 defined\n");
#अन्यथा
    प्रारूप_लिख("B2 not defined\n");
#यदि_अन्तः
#यदि_अन्तः

#यदि 1+1
    प्रारूप_लिख("test true1\n");
#यदि_अन्तः
#यदि 0
    प्रारूप_लिख("test true2\n");
#यदि_अन्तः
#यदि 1-1
    प्रारूप_लिख("test true3\n");
#यदि_अन्तः
#यदि defined(A)
    प्रारूप_लिख("test trueA\n");
#यदि_अन्तः
#यदि defined(B)
    प्रारूप_लिख("test trueB\n");
#यदि_अन्तः

#यदि 0
    प्रारूप_लिख("test 0\n");
#नोचेद्यदि 0
    प्रारूप_लिख("test 1\n");
#नोचेद्यदि 2
    प्रारूप_लिख("test 2\n");
#अन्यथा
    प्रारूप_लिख("test 3\n");
#यदि_अन्तः

    MACRO_NOARGS();

    प्रारूप_लिख("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#यदि_परिभाषितम् C99_MACROS
    प्रारूप_लिख("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#यदि_अन्तः
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    प्रारूप_लिख("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    प्रारूप_लिख("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        पूर्णाङ्क a;
        a = 1;
        glue(a+, +);
        प्रारूप_लिख("a=%d\n", a);
        glue(a <, <= 2);
        प्रारूप_लिख("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#परिभाषय MF_s MF_hello
#परिभाषय MF_hello(सन्देशः) प्रारूप_लिख("%s\n",सन्देशः)

#परिभाषय MF_t प्रारूप_लिख("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    प्रारूप_लिख("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#परिभाषय qq1(x) 1
    प्रारूप_लिख("qq1=%d\n", qq1( ));

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

    प्रारूप_लिख("basefromheader %s\n", get_basefile_from_शीर्षकम्());
    प्रारूप_लिख("base %s\n", __BASE_FILE__);
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ध्रुव वर्ण *fn = get_file_from_शीर्षकम्();
      यदि (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      प्रारूप_लिख("filefromheader %s\n", fn);
    }
#यदि_अन्तः

    प्रारूप_लिख("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_second = 1;
    have_included_42test_h_third = 1;

    /* Check that we don't complain about stray \ here */
    प्रारूप_लिख("print a backslash: %s\n", stringify(\\));
}


स्थिर शून्य print_अङ्कः(वर्ण *fn, पूर्णाङ्क पङ्क्तिः, पूर्णाङ्क अङ्कः) {
    प्रारूप_लिख("fn %s, line %d, num %d\n", fn, पङ्क्तिः, अङ्कः);
}

शून्य recursive_macro_test(शून्य)
{

#परिभाषय ELF32_ST_TYPE(val)              ((val) & 0xf)
#परिभाषय ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#परिभाषय STB_WEAK        2               /* Weak symbol */
#परिभाषय ELFW(type) ELF##32##_##type
    प्रारूप_लिख("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#परिभाषय WRAP(x) x
    
#परिभाषय print_अङ्कः(x) print_अङ्कः(__FILE__,__LINE__,x)
    print_अङ्कः(123);
    WRAP(print_अङ्कः(123));
    WRAP(WRAP(print_अङ्कः(123)));

स्थिर संरचना recursive_macro { पूर्णाङ्क rm_क्षेत्रम्; } G;
#परिभाषय rm_क्षेत्रम् (G.rm_क्षेत्रम्)
    प्रारूप_लिख("rm_field = %d\n", rm_क्षेत्रम्);
    प्रारूप_लिख("rm_field = %d\n", WRAP(rm_क्षेत्रम्));
    WRAP((प्रारूप_लिख("rm_field = %d %d\n", rm_क्षेत्रम्, WRAP(rm_क्षेत्रम्))));
}

#यदि __TINYC__
पूर्णाङ्क op(a, b)
{
    प्रत्यागम a / b;
}

पूर्णाङ्क ret(a)
{
    यदि (a == 2)
        प्रत्यागम 1;
    यदि (a == 3)
        प्रत्यागम 2;
    प्रत्यागम 0;
}
#यदि_अन्तः

#यदि !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#परिभाषय CONSTANTINDEXEDSTRLIT
#यदि_अन्तः
वर्ण str_ag1[] = "b";
वर्ण str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#यदि_परिभाषितम् CONSTANTINDEXEDSTRLIT
वर्ण str_ag3[] = { "ab"[1], 0 };
वर्ण str_x[2] = { "xy" "z"[2], 0 };
#यदि_अन्तः
वर्ण *str_ar[] = { "one", "two" };
संरचना str_SS {अचिह्नित वर्ण a[3], b; };
संरचना str_SS str_sinit15 = { "r" };
संरचना str_SS str_sinit16[] = { { "q" }, 2 };

स्थिर शून्य string_test2()
{
    वर्ण *p = "hello";
    वर्ण a3[2] = { "p" };
    वर्ण a4[2] = { "ab" "c"[2], 0 };
    वर्ण *pa1 = "def" + 1;
    वर्ण *pa2 = { "xyz" + 1 };
    पूर्णाङ्क i = 0;
    संरचना str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#यदि_अपरिभाषितम् CONSTANTINDEXEDSTRLIT
    वर्ण str_ag3[] = { "ab"[1], 0 };
    वर्ण str_x[2] = { "xy" "z"[2], 0 };
#यदि_अन्तः
    पङ्क्तिं_लिख("string_test2");
    पङ्क्तिं_लिख(str_ag1);
    पङ्क्तिं_लिख(str_ag2);
    /*puts(str_bg1);*/
    पङ्क्तिं_लिख(str_ag3);
    पङ्क्तिं_लिख(str_x);
    पङ्क्तिं_लिख(str_sinit15.a);
    पङ्क्तिं_लिख(str_sinit16[0].a);
    पङ्क्तिं_लिख(a3);
    पङ्क्तिं_लिख(a4);
    पङ्क्तिं_लिख(p);
    पङ्क्तिं_लिख("world");
    प्रारूप_लिख("%s\n", "bla");
    पङ्क्तिं_लिख(str_ar[0]);
    पङ्क्तिं_लिख(str_ar[1]);
    पङ्क्तिं_लिख(ss.a);
    पङ्क्तिं_लिख(i >= 0 ? "one" : "two");
    पङ्क्तिं_लिख(pa1);
    पङ्क्तिं_लिख(pa2);
}

शून्य ps(ध्रुव वर्ण *s)
{
    पूर्णाङ्क c;
    यावत् (1) {
        c = *s;
        यदि (c == 0)
            भङ्ग;
        प्रारूप_लिख("%c", c);
        s++;
    }
}

ध्रुव वर्ण foo1_string[] = "\
bar\n\
test\14\
1";

शून्य string_test()
{
    अचिह्नित पूर्णाङ्क b;
    प्रारूप_लिख("string:\n");
    प्रारूप_लिख("\141\1423\143\n");/* dezdez test */
    प्रारूप_लिख("\x41\x42\x43\x3a\n");
    प्रारूप_लिख("c=%c\n", 'r');
    प्रारूप_लिख("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    प्रारूप_लिख("foo1_string='%s'\n", foo1_string);
#यदि 0
    प्रारूप_लिख("wstring=%S\n", L"abc");
    प्रारूप_लिख("wstring=%S\n", L"abc" L"def" "ghi");
    प्रारूप_लिख("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    प्रारूप_लिख("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#यदि_अन्तः
    ps("test\n");
    b = 32;
    यावत् ((b = b + 1) < 96) {
        प्रारूप_लिख("%c", b);
    }
    प्रारूप_लिख("\n");
    प्रारूप_लिख("fib=%d\n", fib(33));
    b = 262144;
    यावत् (b != 0x80000000) {
        अङ्कः(b);
        b = b * 2;
    }
    string_test2();
}


शून्य if1t(पूर्णाङ्क n, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c)
{
    यदि (a && b) प्रारूप_लिख("if1t: %d 1 %d %d\n", n, a, b);
    यदि (a && !b) प्रारूप_लिख("if1t: %d 2 %d %d\n", n, a, b);
    यदि (!a && b) प्रारूप_लिख("if1t: %d 3 %d %d\n", n, a, b);
    यदि (!a && !b) प्रारूप_लिख("if1t: %d 4 %d %d\n", n, a, b);
    यदि (a || b) प्रारूप_लिख("if1t: %d 5 %d %d\n", n, a, b);
    यदि (a || !b) प्रारूप_लिख("if1t: %d 6 %d %d\n", n, a, b);
    यदि (!a || b) प्रारूप_लिख("if1t: %d 7 %d %d\n", n, a, b);
    यदि (!a || !b) प्रारूप_लिख("if1t: %d 8 %d %d\n", n, a, b);
    यदि (a && b || c) प्रारूप_लिख("if1t: %d 9 %d %d %d\n", n, a, b, c);
    यदि (a || b && c) प्रारूप_लिख("if1t: %d 10 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 && c) प्रारूप_लिख("if1t: %d 11 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 || c) प्रारूप_लिख("if1t: %d 12 %d %d %d\n", n, a, b, c);
    यदि (a > 0 && 1) प्रारूप_लिख("if1t: %d 13 %d %d %d\n", n, a, b, c);
    यदि (a > 0 || 0) प्रारूप_लिख("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

शून्य if2t(शून्य)
{
    यदि (0 && 1 || प्रारूप_लिख("if2t:ok\n") || 1)
      प्रारूप_लिख("if2t:ok2\n");
    प्रारूप_लिख("if2t:ok3\n");
}

शून्य if3t(शून्य)
{
    चञ्चल दीर्घ दीर्घ i = 1;
    यदि (i <= 18446744073709551615ULL)
      ;
    अन्यथा
      प्रारूप_लिख ("if3t:wrong 1\n");
}

शून्य if_test(शून्य)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

शून्य loop_test()
{
    पूर्णाङ्क i;
    i = 0;
    यावत् (i < 10)
        प्रारूप_लिख("%d", i++);
    प्रारूप_लिख("\n");
    प्रति(i = 0; i < 10;i++)
        प्रारूप_लिख("%d", i);
    प्रारूप_लिख("\n");
    i = 0;
    कुरु {
        प्रारूप_लिख("%d", i++);
    } यावत् (i < 10);
    प्रारूप_लिख("\n");

    वर्ण गणनम्_2 = 123;
    /* c99 for loop init test */
    प्रति (आकार_t गणनम्_2 = 1; गणनम्_2 < 3; गणनम्_2++)
        प्रारूप_लिख("count=%d\n", गणनम्_2);
    प्रारूप_लिख("count = %d\n", गणनम्_2);

    /* break/continue tests */
    i = 0;
    यावत् (1) {
        यदि (i == 6)
            भङ्ग;
        i++;
        यदि (i == 3)
            अनुवर्त;
        प्रारूप_लिख("%d", i);
    }
    प्रारूप_लिख("\n");

    /* break/continue tests */
    i = 0;
    कुरु {
        यदि (i == 6)
            भङ्ग;
        i++;
        यदि (i == 3)
            अनुवर्त;
        प्रारूप_लिख("%d", i);
    } यावत्(1);
    प्रारूप_लिख("\n");

    प्रति(i = 0;i < 10;i++) {
        यदि (i == 3)
            अनुवर्त;
        प्रारूप_लिख("%d", i);
    }
    प्रारूप_लिख("\n");
}

प्रकारनिर्देश पूर्णाङ्क typedef_and_label;

शून्य goto_test()
{
    पूर्णाङ्क i;
    स्थिर शून्य *label_सारणी[3] = { &&label1, &&label2, &&label3 };
    संरचना {
        पूर्णाङ्क bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    प्रारूप_लिख("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    यदि (i >= 10) 
        गच्छ s_अन्तः;
    प्रारूप_लिख("%d", i);
    i++;
    गच्छ s_loop;
 s_अन्तः:
    प्रारूप_लिख("\n");

    /* we also test computed gotos (GCC extension) */
    प्रति(i=0;i<3;i++) {
        गच्छ *label_सारणी[i];
    label1:
        प्रारूप_लिख("label1\n");
        गच्छ अग्र;
    label2:
        प्रारूप_लिख("label2\n");
        गच्छ अग्र;
    label3:
        प्रारूप_लिख("label3\n");
    अग्र: ;
    }
}

गणना {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

गणना test {
    E5 = 1000,
};

संरचना S_enum {
    गणना {E6 = 42, E7, E8} e:8;
};

गणना ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((अचिह्नित दीर्घ)0xf000 << 31) << 1,
};

गणना { BIASU = -1U<<31 };
गणना { BIASS = -1 << 31 };

स्थिर पूर्णाङ्क getint(पूर्णाङ्क i)
{
  यदि (i)
    प्रत्यागम 0;
  अन्यथा
    प्रत्यागम (पूर्णाङ्क)(-1U << 31);
}

शून्य enum_test()
{
    गणना test b1;
    /* The following should give no warning */
    अचिह्नित *p = &b1;
    संरचना S_enum s = {E7};
    प्रारूप_लिख("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    प्रारूप_लिख("b1=%d\n", b1);
    प्रारूप_लिख("enum large: %ld\n", EL_large);

    यदि (getint(0) == BIASU)
      प्रारूप_लिख("enum unsigned: ok\n");
    अन्यथा
      प्रारूप_लिख("enum unsigned: wrong\n");
    यदि (getint(0) == BIASS)
      प्रारूप_लिख("enum unsigned: ok\n");
    अन्यथा
      प्रारूप_लिख("enum unsigned: wrong\n");
}

प्रकारनिर्देश पूर्णाङ्क *my_ptr;

प्रकारनिर्देश पूर्णाङ्क mytype1;
प्रकारनिर्देश पूर्णाङ्क mytype2;

शून्य typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    पूर्णाङ्क b;

    a = &b;
    *a = 1234;
    प्रारूप_लिख("a=%d\n", *a);
    mytype2 = 2;
    प्रारूप_लिख("mytype2=%d\n", mytype2);
}

शून्य forward_test()
{
    forward_ref();
    forward_ref();
}


शून्य forward_ref(शून्य)
{
    प्रारूप_लिख("forward ok\n");
}

प्रकारनिर्देश संरचना struct1 {
    पूर्णाङ्क f1;
    पूर्णाङ्क f2, f3;
    सङ्घ union1 {
        पूर्णाङ्क v1;
        पूर्णाङ्क v2;
    } u;
    वर्ण str[3];
} struct1;

संरचना struct2 {
    पूर्णाङ्क a;
    वर्ण b;
};

सङ्घ union2 {
    पूर्णाङ्क w1;
    पूर्णाङ्क w2;
};

संरचना struct1 st1, st2;

संरचना रिक्तानि_mem {
    /* nothing */ ;
    पूर्णाङ्क x;
};

पूर्णाङ्क tab[3];
पूर्णाङ्क tab2[3][2];

पूर्णाङ्क g;

शून्य f1(पूर्णाङ्क g)
{
    प्रारूप_लिख("g1=%d\n", g);
}

शून्य scope_test()
{
    g = 2;
    f1(1);
    प्रारूप_लिख("g2=%d\n", g);
    {
        पूर्णाङ्क g;
        g = 3;
        प्रारूप_लिख("g3=%d\n", g);
        {
            पूर्णाङ्क g;
            g = 4;
            प्रारूप_लिख("g4=%d\n", g);
        }
    }
    प्रारूप_लिख("g5=%d\n", g);
}

पूर्णाङ्क st2_i;
पूर्णाङ्क *st2_p = &st2_i;
शून्य scope2_test()
{
    वर्ण a[50];
    st2_i = 42;
    प्रति (पूर्णाङ्क st2_i = 1; st2_i < 10; st2_i++) {
        बाह्य पूर्णाङ्क st2_i;
        st2_i++;
        प्रारूप_लिख("exloc: %d\n", st2_i);
    }
    प्रारूप_लिख("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
बाह्य पूर्णाङ्क st_global1;
पूर्णाङ्क st_global1=42;
बाह्य पूर्णाङ्क st_global1;
पूर्णाङ्क st_global1;
बाह्य पूर्णाङ्क st_global2;
पूर्णाङ्क st_global2;
बाह्य पूर्णाङ्क st_global2;
पूर्णाङ्क st_global2;

शून्य array_test()
{
    पूर्णाङ्क i, j, a[4];

    प्रारूप_लिख("sizeof(a) = %d\n", परिमाण(a));
    प्रारूप_लिख("sizeof(\"a\") = %d\n", परिमाण("a"));
#यदि_परिभाषितम् C99_MACROS
    प्रारूप_लिख("sizeof(__func__) = %d\n", परिमाण(__func__));
#यदि_अन्तः
    प्रारूप_लिख("sizeof tab %d\n", परिमाण(tab));
    प्रारूप_लिख("sizeof tab2 %d\n", परिमाण tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    प्रारूप_लिख("%d %d %d\n", tab[0], tab[1], tab[2]);
    प्रति(i=0;i<3;i++)
        प्रति(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    प्रति(i=0;i<3*2;i++) {
        प्रारूप_लिख(" %3d", ((पूर्णाङ्क *)tab2)[i]);
    }
    प्रारूप_लिख("\n");
    प्रारूप_लिख("sizeof(size_t)=%d\n", परिमाण(आकार_t));
    प्रारूप_लिख("sizeof(ptrdiff_t)=%d\n", परिमाण(ptrdiff_t));
}

शून्य व्यञ्जकम्_test()
{
    पूर्णाङ्क a, b;
    a = 0;
    प्रारूप_लिख("%d\n", a += 1);
    प्रारूप_लिख("%d\n", a -= 2);
    प्रारूप_लिख("%d\n", a *= 31232132);
    प्रारूप_लिख("%d\n", a /= 4);
    प्रारूप_लिख("%d\n", a %= 20);
    प्रारूप_लिख("%d\n", a &= 6);
    प्रारूप_लिख("%d\n", a ^= 7);
    प्रारूप_लिख("%d\n", a |= 8);
    प्रारूप_लिख("%d\n", a >>= 3);
    प्रारूप_लिख("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    प्रारूप_लिख("%d\n", a + 1);
    प्रारूप_लिख("%d\n", a - 2);
    प्रारूप_लिख("%d\n", a * 312);
    प्रारूप_लिख("%d\n", a / 4);
    प्रारूप_लिख("%d\n", b / 4);
    प्रारूप_लिख("%d\n", (अचिह्नित)b / 4);
    प्रारूप_लिख("%d\n", a % 20);
    प्रारूप_लिख("%d\n", b % 20);
    प्रारूप_लिख("%d\n", (अचिह्नित)b % 20);
    प्रारूप_लिख("%d\n", a & 6);
    प्रारूप_लिख("%d\n", a ^ 7);
    प्रारूप_लिख("%d\n", a | 8);
    प्रारूप_लिख("%d\n", a >> 3);
    प्रारूप_लिख("%d\n", b >> 3);
    प्रारूप_लिख("%d\n", (अचिह्नित)b >> 3);
    प्रारूप_लिख("%d\n", a << 4);
    प्रारूप_लिख("%d\n", ~a);
    प्रारूप_लिख("%d\n", -a);
    प्रारूप_लिख("%d\n", +a);

    प्रारूप_लिख("%d\n", 12 + 1);
    प्रारूप_लिख("%d\n", 12 - 2);
    प्रारूप_लिख("%d\n", 12 * 312);
    प्रारूप_लिख("%d\n", 12 / 4);
    प्रारूप_लिख("%d\n", 12 % 20);
    प्रारूप_लिख("%d\n", 12 & 6);
    प्रारूप_लिख("%d\n", 12 ^ 7);
    प्रारूप_लिख("%d\n", 12 | 8);
    प्रारूप_लिख("%d\n", 12 >> 2);
    प्रारूप_लिख("%d\n", 12 << 4);
    प्रारूप_लिख("%d\n", ~12);
    प्रारूप_लिख("%d\n", -12);
    प्रारूप_लिख("%d\n", +12);
    प्रारूप_लिख("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

पूर्णाङ्क isid(पूर्णाङ्क c)
{
    प्रत्यागम (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

पूर्णाङ्क vstack[10], *vstack_ptr;

शून्य vpush(पूर्णाङ्क vt, पूर्णाङ्क vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

शून्य vpop(पूर्णाङ्क *ft, पूर्णाङ्क *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

शून्य expr2_test()
{
    पूर्णाङ्क a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    प्रारूप_लिख("res= %d %d\n", a, b);
}

पूर्णाङ्क const_len_ar[परिमाण(1/0)]; /* div-by-zero, but in unevaluated context */

शून्य constant_व्यञ्जकम्_test()
{
    पूर्णाङ्क a;
    a = 3;
    प्रारूप_लिख("%d\n", a * 16);
    प्रारूप_लिख("%d\n", a * 1);
    प्रारूप_लिख("%d\n", a + 0);
    प्रारूप_लिख("%d\n", परिमाण(const_len_ar));
}

पूर्णाङ्क tab4[10];

शून्य व्यञ्जकम्_ptr_test()
{
    पूर्णाङ्क arr[10], *p, *q;
    पूर्णाङ्क i = -1;

    p = tab4;
    q = tab4 + 10;
    प्रारूप_लिख("diff=%d\n", q - p);
    p++;
    प्रारूप_लिख("inc=%d\n", p - tab4);
    p--;
    प्रारूप_लिख("dec=%d\n", p - tab4);
    ++p;
    प्रारूप_लिख("inc=%d\n", p - tab4);
    --p;
    प्रारूप_लिख("dec=%d\n", p - tab4);
    प्रारूप_लिख("add=%d\n", p + 3 - tab4);
    प्रारूप_लिख("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    प्रारूप_लिख("%p %p %ld\n", q, p, p-q);
    प्रारूप_लिख("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    प्रारूप_लिख("%p %p %ld\n", q, p, p-q);
    प्रारूप_लिख("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (पूर्णाङ्क *)((वर्ण *)p + 0xf0000000);
    प्रारूप_लिख("%p %p %ld\n", q, p, p-q);
    प्रारूप_लिख("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    प्रारूप_लिख("%p %p %ld\n", q, p, p-q);
    प्रारूप_लिख("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        संरचना size12 {
            पूर्णाङ्क i, j, k;
        };
        संरचना size12 s[2], *sp = s;
        पूर्णाङ्क i, j;
        sp->i = 42;
        sp++;
        j = -1;
        प्रारूप_लिख("%d\n", sp[j].i);
    }
#यदि_परिभाषितम् __LP64__
    i = 1;
    p = (पूर्णाङ्क*)0x100000000UL + i;
    i = ((दीर्घ)p) >> 32;
    प्रारूप_लिख("largeptr: %p %d\n", p, i);
#यदि_अन्तः
    p = &arr[0];
    q = p + 3;
    प्रारूप_लिख ("%d\n", (पूर्णाङ्क)((p - q) / 3));
}

शून्य व्यञ्जकम्_cmp_test()
{
    पूर्णाङ्क a, b;
    a = -1;
    b = 1;
    प्रारूप_लिख("%d\n", a == a);
    प्रारूप_लिख("%d\n", a != a);

    प्रारूप_लिख("%d\n", a < b);
    प्रारूप_लिख("%d\n", a <= b);
    प्रारूप_लिख("%d\n", a <= a);
    प्रारूप_लिख("%d\n", b >= a);
    प्रारूप_लिख("%d\n", a >= a);
    प्रारूप_लिख("%d\n", b > a);

    प्रारूप_लिख("%d\n", (अचिह्नित)a < b);
    प्रारूप_लिख("%d\n", (अचिह्नित)a <= b);
    प्रारूप_लिख("%d\n", (अचिह्नित)a <= a);
    प्रारूप_लिख("%d\n", (अचिह्नित)b >= a);
    प्रारूप_लिख("%d\n", (अचिह्नित)a >= a);
    प्रारूप_लिख("%d\n", (अचिह्नित)b > a);
}

संरचना रिक्तानि {
};

संरचना aligntest1 {
    वर्ण a[10];
};

संरचना aligntest2 {
    पूर्णाङ्क a;
    वर्ण b[10];
};

संरचना aligntest3 {
    द्विगुण a, b;
};

संरचना aligntest4 {
    द्विगुण a[0];
};

संरचना __attribute__((aligned(16))) aligntest5
{
    पूर्णाङ्क i;
};
संरचना aligntest6
{
    पूर्णाङ्क i;
} __attribute__((aligned(16)));
संरचना aligntest7
{
    पूर्णाङ्क i;
};
संरचना aligntest5 altest5[2];
संरचना aligntest6 altest6[2];
पूर्णाङ्क pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
संरचना aligntest7 altest7[2] __attribute__((aligned(16)));

संरचना aligntest8
{
  पूर्णाङ्क i;
} __attribute__((aligned(4096)));

संरचना Large {
    अचिह्नित दीर्घ flags;
    सङ्घ {
	शून्य *u1;
	पूर्णाङ्क *u2;
    };

    संरचना {
	सङ्घ {
	    अचिह्नित दीर्घ सूचकांक;
	    शून्य *freelist;
	};
	सङ्घ {
	    अचिह्नित दीर्घ counters;
	    संरचना {
		पूर्णाङ्क bla;
	    };
	};
    };

    सङ्घ {
	संरचना {
	    दीर्घ u3;
	    दीर्घ u4;
	};
	शून्य *u5;
	संरचना {
	    अचिह्नित दीर्घ compound_शीर्ष;
	    अचिह्नित पूर्णाङ्क compound_dtor;
	    अचिह्नित पूर्णाङ्क compound_क्रमः;
	};
    };
} __attribute__((aligned(2 * परिमाण(दीर्घ))));

प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ __attribute__((aligned(4))) unaligned_u64;

संरचना aligntest9 {
    अचिह्नित पूर्णाङ्क buf_nr;
    unaligned_u64 start_lba;
};

संरचना aligntest10 {
    अचिह्नित पूर्णाङ्क buf_nr;
    अचिह्नित दीर्घ दीर्घ start_lba;
};

शून्य struct_test()
{
    struct1 *s;
    सङ्घ union2 u;
    संरचना Large ls;

    प्रारूप_लिख("sizes: %d %d %d %d\n",
           परिमाण(संरचना struct1),
           परिमाण(संरचना struct2),
           परिमाण(सङ्घ union1),
           परिमाण(सङ्घ union2));
    प्रारूप_लिख("offsets: %d\n", (पूर्णाङ्क)((वर्ण*)&st1.u.v1 - (वर्ण*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    प्रारूप_लिख("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    प्रारूप_लिख("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    प्रारूप_लिख("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    प्रारूप_लिख("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    प्रारूप_लिख("str_addr=%x\n", (पूर्णाङ्क)(uintptr_t)st1.str - (पूर्णाङ्क)(uintptr_t)&st1.f1);

    /* align / size tests */
    प्रारूप_लिख("aligntest1 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest1), __alignof__(संरचना aligntest1));
    प्रारूप_लिख("aligntest2 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest2), __alignof__(संरचना aligntest2));
    प्रारूप_लिख("aligntest3 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest3), __alignof__(संरचना aligntest3));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    प्रारूप_लिख("aligntest4 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest4), __alignof__(संरचना aligntest4));
#यदि_अन्तः
    प्रारूप_लिख("aligntest5 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest5), __alignof__(संरचना aligntest5));
    प्रारूप_लिख("aligntest6 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest6), __alignof__(संरचना aligntest6));
    प्रारूप_लिख("aligntest7 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest7), __alignof__(संरचना aligntest7));
    प्रारूप_लिख("aligntest8 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest8), __alignof__(संरचना aligntest8));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    प्रारूप_लिख("aligntest9 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest9), __alignof__(संरचना aligntest9));
#यदि_अन्तः
    प्रारूप_लिख("aligntest10 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest10), __alignof__(संरचना aligntest10));
    प्रारूप_लिख("altest5 sizeof=%d alignof=%d\n",
           परिमाण(altest5), __alignof__(altest5));
    प्रारूप_लिख("altest6 sizeof=%d alignof=%d\n",
           परिमाण(altest6), __alignof__(altest6));
    प्रारूप_लिख("altest7 sizeof=%d alignof=%d\n",
           परिमाण(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    प्रारूप_लिख("sizeof(struct empty) = %d\n", परिमाण(संरचना रिक्तानि));
#यदि_अन्तः
    प्रारूप_लिख("alignof(struct empty) = %d\n", __alignof__(संरचना रिक्तानि));

    प्रारूप_लिख("Large: sizeof=%d\n", परिमाण(ls));
    स्मृतिं_पूरय(&ls, 0, परिमाण(ls));
    ls.compound_शीर्ष = 42;
    प्रारूप_लिख("Large: offsetof(compound_head)=%d\n", (पूर्णाङ्क)((वर्ण*)&ls.compound_शीर्ष - (वर्ण*)&ls));
}

/* simulate char/short return value with undefined upper bits */
स्थिर पूर्णाङ्क __csf(पूर्णाङ्क x) { प्रत्यागम x; }
स्थिर शून्य *_csf = __csf;
#परिभाषय csf(t,n) ((t(*)(पूर्णाङ्क))_csf)(n)

/* XXX: depend on endianness */
शून्य char_short_test()
{
    पूर्णाङ्क var1, var2;
    चिह्नित वर्ण var3;
    दीर्घ दीर्घ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    प्रारूप_लिख("s8=%d %d\n", 
           *(चिह्नित वर्ण *)&var1, *(चिह्नित वर्ण *)&var2);
    प्रारूप_लिख("u8=%d %d\n", 
           *(अचिह्नित वर्ण *)&var1, *(अचिह्नित वर्ण *)&var2);
    प्रारूप_लिख("s16=%d %d\n", 
           *(ह्रस्व *)&var1, *(ह्रस्व *)&var2);
    प्रारूप_लिख("u16=%d %d\n", 
           *(अचिह्नित ह्रस्व *)&var1, *(अचिह्नित ह्रस्व *)&var2);
    प्रारूप_लिख("s32=%d %d\n", 
           *(पूर्णाङ्क *)&var1, *(पूर्णाङ्क *)&var2);
    प्रारूप_लिख("u32=%d %d\n", 
           *(अचिह्नित पूर्णाङ्क *)&var1, *(अचिह्नित पूर्णाङ्क *)&var2);
    *(चिह्नित वर्ण *)&var1 = 0x08;
    प्रारूप_लिख("var1=%x\n", var1);
    *(ह्रस्व *)&var1 = 0x0809;
    प्रारूप_लिख("var1=%x\n", var1);
    *(पूर्णाङ्क *)&var1 = 0x08090a0b;
    प्रारूप_लिख("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    प्रारूप_लिख("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    प्रारूप_लिख("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    प्रारूप_लिख("promote char/short cast VA %d %d\n", (चिह्नित वर्ण)(var1 + 1), (चिह्नित वर्ण)(var4 + 1));
#यदि !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(अचिह्नित वर्ण,0x89898989);
    var4 = csf(चिह्नित वर्ण,0xabababab);
#यदि_परिभाषितम् __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#यदि_अन्तः
    प्रारूप_लिख("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    प्रारूप_लिख("promote char/short fumcret VA %d %d %d %d\n",
        csf(अचिह्नित ह्रस्व,0xcdcdcdcd),
        csf(ह्रस्व,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#यदि_अन्तः
    var3 = -10;
    var1 = (चिह्नित वर्ण)(अचिह्नित वर्ण)(var3 + 1);
    var4 = (चिह्नित वर्ण)(अचिह्नित वर्ण)(var3 + 1);
    प्रारूप_लिख("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (अचिह्नित)(पूर्णाङ्क)(var4 + 1);
    प्रारूप_लिख("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (अचिह्नित)(चिह्नित वर्ण)(var4 + 1);
    प्रारूप_लिख("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

प्रकारनिर्देश संरचना Sym {
    पूर्णाङ्क v;
    पूर्णाङ्क t;
    पूर्णाङ्क c;
    संरचना Sym *अग्र;
    संरचना Sym *पूर्व;
} Sym;

#परिभाषय ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#परिभाषय TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

स्थिर पूर्णाङ्क toupper1(पूर्णाङ्क a)
{
    प्रत्यागम TOUPPER(a);
}

स्थिर अचिह्नित पूर्णाङ्क calc_vm_flags(अचिह्नित पूर्णाङ्क prot)
{
  अचिह्नित पूर्णाङ्क prot_द्वयङ्काः;
  /* This used to segfault in some revisions: */
  prot_द्वयङ्काः = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  प्रत्यागम prot_द्वयङ्काः;
}

गणना cast_enum { FIRST, चरमः_2 };

स्थिर शून्य tst_cast(गणना cast_enum ce)
{
    प्रारूप_लिख("%d\n", ce);
}

शून्य bool_test()
{
    पूर्णाङ्क *s, a, b, t, f, i;

    a = 0;
    s = (शून्य*)0;
    प्रारूप_लिख("!s=%d\n", !s);

    यदि (!s || !s[0])
        a = 1;
    प्रारूप_लिख("a=%d\n", a);

    प्रारूप_लिख("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    प्रारूप_लिख("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    प्रारूप_लिख("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#यदि 1 && 1
    प्रारूप_लिख("a1\n");
#यदि_अन्तः
#यदि 1 || 0
    प्रारूप_लिख("a2\n");
#यदि_अन्तः
#यदि 1 ? 0 : 1
    प्रारूप_लिख("a3\n");
#यदि_अन्तः
#यदि 0 ? 0 : 1
    प्रारूप_लिख("a4\n");
#यदि_अन्तः

    a = 4;
    प्रारूप_लिख("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    प्रारूप_लिख("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    प्रारूप_लिख("exp=%d\n", f == (32 <= a && a <= 3));
    प्रारूप_लिख("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    प्रारूप_लिख("type of bool: %d\n", (पूर्णाङ्क) ( (~ ((अचिह्नित पूर्णाङ्क) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : चरमः_2);

    प्रारूप_लिख("type of cond: %d\n", (~(t ? 0U : (अचिह्नित पूर्णाङ्क)0)) / 2 );
    /* test ? : cast */
    {
        पूर्णाङ्क aspect_on;
        पूर्णाङ्क aspect_native = 65536;
        द्विगुण bfu_aspect = 1.0;
        पूर्णाङ्क aspect;
        प्रति(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            प्रारूप_लिख("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        स्थिर पूर्णाङ्क v1 = 34 ? : -1; /* constant case */
        स्थिर पूर्णाङ्क v2 = 0 ? : -1; /* constant case */
        पूर्णाङ्क a = 30;
        
        प्रारूप_लिख("%d %d\n", v1, v2);
        प्रारूप_लिख("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    प्रति(i=0;i<256;i++) {
        यदि (toupper1 (i) != TOUPPER (i))
            प्रारूप_लिख("error %d\n", i);
    }
    प्रारूप_लिख ("bits = 0x%x\n", calc_vm_flags (0x1));
}

बाह्य पूर्णाङ्क undefined_function(शून्य);
बाह्य पूर्णाङ्क defined_function(शून्य);

#यदि_परिभाषितम् __clang__
पूर्णाङ्क undefined_function(शून्य) {}
#यदि_अन्तः

स्थिर अन्तःस्थ शून्य refer_गन्तव्यम्_undefined(शून्य)
{
  undefined_function();
}

शून्य optimize_बहिर्गमनम्_test(शून्य)
{
  पूर्णाङ्क i = 0 ? undefined_function() : defined_function();
  प्रारूप_लिख ("oo:%d\n", i);
  पूर्णाङ्क j = 1 ? defined_function() : undefined_function();
  प्रारूप_लिख ("oo:%d\n", j);
  यदि (0)
    प्रारूप_लिख("oo:%d\n", undefined_function());
  अन्यथा
    प्रारूप_लिख("oo:%d\n", defined_function());
  यदि (1)
    प्रारूप_लिख("oo:%d\n", defined_function());
  अन्यथा
    प्रारूप_लिख("oo:%d\n", undefined_function());
  यावत् (1) {
      प्रारूप_लिख("oow:%d\n", defined_function());
      भङ्ग;
      प्रारूप_लिख("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  विकल्प (j)
    पक्ष 1: भङ्ग;
  प्रारूप_लिख ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  यावत् (1)
    भङ्ग;
  प्रारूप_लिख ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  कुरु
    भङ्ग;
  यावत् (1);
  प्रारूप_लिख ("ool2:%d\n", defined_function());
  प्रति (;;)
    भङ्ग;
  प्रारूप_लिख ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  यावत् (1) {
	{
	  भङ्ग;
	}
      प्रारूप_लिख ("ool4:%d\n", undefined_function());
  }
  j = 1;
  यावत् (j) {
      यदि (j == 0)
	भङ्ग; /* this break shouldn't disable code outside the if. */
      प्रारूप_लिख("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  यावत् (j) {
      यदि (1)
	j--;
      अन्यथा
	breakhere: भङ्ग;
      प्रारूप_लिख("ool6:%d\n", defined_function());
      गच्छ breakhere;
  }
  j = 1;
  यावत् (j) {
      j--;
      अनुवर्त;
      प्रारूप_लिख("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  यदि (0 && undefined_function())
    undefined_function();
  यदि (defined_function() && 0)
    undefined_function();
  यदि (0 && 0)
    undefined_function();
  यदि (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  यदि (1 || undefined_function())
    ;
  अन्यथा
    undefined_function();
  यदि (defined_function() || 1)
    ;
  अन्यथा
    undefined_function();
  यदि (1 || 1)
    ;
  अन्यथा
    undefined_function();
  यदि (defined_function() || 1 || undefined_function())
    ;
  अन्यथा
    undefined_function();

  यदि (defined_function() && 0)
    refer_गन्तव्यम्_undefined();

  यदि (0) {
      (शून्य)परिमाण( ({
		     कुरु { } यावत् (0);
		     0;
		     }) );
      undefined_function();
  }

  यदि (0) {
      विकल्प (defined_function()) {
          पक्ष 0: undefined_function(); भङ्ग;
          स्वभाव: undefined_function(); भङ्ग;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  यदि (1)
    प्रत्यागम;
  प्रारूप_लिख ("oor:%d\n", undefined_function());
}

पूर्णाङ्क defined_function(शून्य)
{
  स्थिर पूर्णाङ्क i = 40;
  प्रत्यागम i++;
}

/* GCC accepts that */
स्थिर पूर्णाङ्क tab_reinit[];
स्थिर पूर्णाङ्क tab_reinit[10];

स्थिर पूर्णाङ्क tentative_ar[];
स्थिर पूर्णाङ्क tentative_ar[] = {1,2,3};

पूर्णाङ्क cinit1; /* a global variable can be defined several times without error ! */
पूर्णाङ्क cinit1; 
पूर्णाङ्क cinit1 = 0;
पूर्णाङ्क *cinit2 = (पूर्णाङ्क []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
वर्ण ध्रुव * ध्रुव cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
शून्य *cinit52 = &(शून्य*){ (शून्य*) 52 };

#यदि __TINYC__ || __GNUC__ >= 6
पूर्णाङ्क cinit4 = (पूर्णाङ्क){44};
शून्य *cinit51 = (शून्य*){ (शून्य*) 51 };
संरचना _c6 { पूर्णाङ्क a,b; } cinit6 = (संरचना _c6){61,62}, *cinit7 = &(संरचना _c6){71,72};
#अन्यथा
पूर्णाङ्क cinit4 = 44;
शून्य *cinit51 = (शून्य*)51;
संरचना _c6 { पूर्णाङ्क a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#यदि_अन्तः

शून्य compound_literal_test(शून्य)
{
    पूर्णाङ्क *p, i;
    वर्ण *q, *q3;

    प्रारूप_लिख("cinit3 : %s\n", cinit3);
    प्रारूप_लिख("cinit4 : %d\n", cinit4);
    प्रारूप_लिख("cinit51 : %d\n", (पूर्णाङ्क)cinit51);
    प्रारूप_लिख("cinit52 : %d\n", *(पूर्णाङ्क*)cinit52);
    प्रारूप_लिख("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    प्रारूप_लिख("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    प्रारूप_लिख("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (पूर्णाङ्क []){1, 2, 3};
    प्रति(i=0;i<3;i++)
        प्रारूप_लिख(" %d", p[i]);
    प्रारूप_लिख("\n");

    प्रति(i=0;i<3;i++)
        प्रारूप_लिख("%d", cinit2[i]);
    प्रारूप_लिख("\n");

    q = "tralala1";
    प्रारूप_लिख("q1=%s\n", q);

    q = (वर्ण *){ "tralala2" };
    प्रारूप_लिख("q2=%s\n", q);

    q3 = (वर्ण *){ q };
    प्रारूप_लिख("q3=%s\n", q3);

    q = (वर्ण []){ "tralala3" };
    प्रारूप_लिख("q4=%s\n", q);

#यदि_परिभाषितम् ALL_ISOC99
    p = (पूर्णाङ्क []){1, 2, cinit1 + 3};
    प्रति(i=0;i<3;i++)
        प्रारूप_लिख(" %d", p[i]);
    प्रारूप_लिख("\n");

    प्रति(i=0;i<3;i++) {
        p = (पूर्णाङ्क []){1, 2, 4 + i};
        प्रारूप_लिख("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#यदि_अन्तः
}


#यदि __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    प्रत्यागम a + b;
}

पूर्णाङ्क kr_func2(a, b)
{
    प्रत्यागम a + b;
}

kr_test()
{
    प्रारूप_लिख("func1=%d\n", kr_func1(3, 4));
    प्रारूप_लिख("func2=%d\n", kr_func2(3, 4));
    प्रत्यागम 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
वर्ण invalid_function_def()[] {प्रत्यागम 0;}

#अन्यथा
# define kr_test() प्रारूप_लिख("func1=7\nfunc2=7\n")
#यदि_अन्तः

शून्य अङ्कः(पूर्णाङ्क n)
{
    वर्ण *tab, *p;
    tab = (वर्ण*)स्मृतिं_देहि(20); 
    p = tab;
    यावत् (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        यदि (n == 0)
            भङ्ग;
    }
    यावत् (p != tab) {
        p--;
        प्रारूप_लिख("%c", *p);
    }
    प्रारूप_लिख("\n");
    मुक्त(tab);
}

/* structure assignment tests */
संरचना structa1 {
    पूर्णाङ्क f1;
    वर्ण f2;
};

शून्य struct_नियोजय_test1(संरचना structa1 s1, पूर्णाङ्क t, भिन्न f)
{
    प्रारूप_लिख("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

संरचना structa1 struct_नियोजय_test2(संरचना structa1 s1, पूर्णाङ्क t)
{
    s1.f1 += t;
    s1.f2 -= t;
    प्रत्यागम s1;
}

शून्य struct_नियोजय_test(शून्य)
{
    संरचना S {
      संरचना structa1 lsta1, lsta2;
      पूर्णाङ्क i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_नियोजय_test1(ps->lsta2, 3, 4.5);
    प्रारूप_लिख("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_नियोजय_test2(ps->lsta2, ps->i);
    प्रारूप_लिख("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    स्थिर संरचना {
        शून्य (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_नियोजय_test }
    };
    प्रारूप_लिख("%d\n", struct_नियोजय_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_नियोजय_test2(s.lsta1, 1);
    प्रारूप_लिख("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

शून्य cast1(वर्ण a, ह्रस्व b, अचिह्नित वर्ण c, अचिह्नित ह्रस्व d)
{
    प्रारूप_लिख("%d %d %d %d\n", a, b, c, d);
}

वर्ण bcast;
ह्रस्व scast;

शून्य cast_test()
{
    पूर्णाङ्क a;
    वर्ण c;
    वर्ण tab[10];
    अचिह्नित b,d;
    ह्रस्व s;
    वर्ण *p = रिक्त;
    अचिह्नित दीर्घ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    प्रारूप_लिख("%d %d %d %d\n",
           (वर्ण)(a + 1),
           (ह्रस्व)(a + 1),
           (अचिह्नित वर्ण)(a + 1),
           (अचिह्नित ह्रस्व)(a + 1));
    प्रारूप_लिख("%d %d %d %d\n",
           (वर्ण)0xfffff,
           (ह्रस्व)0xfffff,
           (अचिह्नित वर्ण)0xfffff,
           (अचिह्नित ह्रस्व)0xfffff);

    a = (bcast = 128) + 1;
    प्रारूप_लिख("%d\n", a);
    a = (scast = 65536) + 1;
    प्रारूप_लिख("%d\n", a);
    
    प्रारूप_लिख("sizeof(c) = %d, sizeof((int)c) = %d\n", परिमाण(c), परिमाण((पूर्णाङ्क)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (ह्रस्व)b;
    प्रारूप_लिख("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (वर्ण)b;
    प्रारूप_लिख("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    प्रारूप_लिख("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    प्रारूप_लिख("sizeof(+(char)'a') = %d\n", परिमाण(+(वर्ण)'a'));
    प्रारूप_लिख("sizeof(-(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));
    प्रारूप_लिख("sizeof(~(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));

#यदि CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    प्रारूप_लिख("%d %d %ld %ld %lld %lld\n",
           (पूर्णाङ्क)p, (अचिह्नित पूर्णाङ्क)p,
           (दीर्घ)p, (अचिह्नित दीर्घ)p,
           (दीर्घ दीर्घ)p, (अचिह्नित दीर्घ दीर्घ)p);
#यदि_अन्तः

    /* from integers to pointers */
    प्रारूप_लिख("%p %p %p %p\n",
           (शून्य *)a, (शून्य *)b, (शून्य *)c, (शून्य *)d);

    /* int to int with sign set */
    प्रारूप_लिख("0x%lx\n", (अचिह्नित दीर्घ)(पूर्णाङ्क)ul);
}

/* initializers tests */
संरचना structinit1 {
    पूर्णाङ्क f1;
    वर्ण f2;
    ह्रस्व f3;
    पूर्णाङ्क farray[3];
};

पूर्णाङ्क sinit1 = 2;
पूर्णाङ्क sinit2 = { 3 };
पूर्णाङ्क sinit3[3] = { 1, 2, {3}, };
पूर्णाङ्क sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
पूर्णाङ्क sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
पूर्णाङ्क sinit6[] = { 1, 2, 3 };
पूर्णाङ्क sinit7[] = { [2] = 3, [0] = 1, 2 };
वर्ण sinit8[] = "hello" "trala";

संरचना structinit1 sinit9 = { 1, 2, 3 };
संरचना structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
संरचना structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#यदि_परिभाषितम् ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#यदि_अन्तः
};

वर्ण *sinit12 = "hello world";
वर्ण *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
वर्ण sinit14[10] = { "abc" };
पूर्णाङ्क sinit15[3] = { परिमाण(sinit15), 1, 2 };

संरचना { पूर्णाङ्क a[3], b; } sinit16[] = { { 1 }, 2 };

संरचना bar {
        वर्ण *s;
        पूर्णाङ्क len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

पूर्णाङ्क sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

संरचना complexinit0 {
    पूर्णाङ्क a;
    पूर्णाङ्क b;
};

संरचना complexinit {
    पूर्णाङ्क a;
    ध्रुव संरचना complexinit0 *b;
};

ध्रुव स्थिर संरचना complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ध्रुव संरचना complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

संरचना complexinit2 {
	पूर्णाङ्क a;
	पूर्णाङ्क b[];
};

संरचना complexinit2 cix20;

संरचना complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

संरचना complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

प्रकारनिर्देश पूर्णाङ्क arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
प्रकारनिर्देश पूर्णाङ्क arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
पूर्णाङ्क sinit23[2] = { "astring" ? परिमाण("astring") : -1,
		   &sinit23 ? 42 : -1 };

पूर्णाङ्क sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
संरचना bf_SS {अचिह्नित पूर्णाङ्क bit:1,bits31:31; };
संरचना bf_SS bf_init = { .bit = 1 };
संरचना bfn_SS {पूर्णाङ्क a,b; संरचना bf_SS c; पूर्णाङ्क d,e; };
संरचना bfn_SS bfn_init = { .c.bit = 1 };
संरचना bfa_SS {पूर्णाङ्क a,b; संरचना bf_SS c[3]; पूर्णाङ्क d,e; };
संरचना bfa_SS bfa_init = { .c[1].bit = 1 };
संरचना bf_SS bfaa_init[3] = { [1].bit = 1 };
संरचना bf_SS bfaa_vinit[] = { [2].bit = 1 };
संरचना b2_SS {दीर्घ दीर्घ पूर्णाङ्क क्षेत्रम् : 52; दीर्घ दीर्घ पूर्णाङ्क pad : 12; };
संरचना b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

बाह्य पूर्णाङ्क external_inited = 42;

शून्य init_test(शून्य)
{
    पूर्णाङ्क linit1 = 2;
    पूर्णाङ्क linit2 = { 3 };
    पूर्णाङ्क linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    पूर्णाङ्क linit6[] = { 1, 2, 3 };
    पूर्णाङ्क i, j;
    वर्ण linit8[] = "hello" "trala";
    पूर्णाङ्क linit12[10] = { 1, 2 };
    पूर्णाङ्क linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    वर्ण linit14[10] = "abc";
    पूर्णाङ्क linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    संरचना linit16 { पूर्णाङ्क a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    पूर्णाङ्क linit17 = परिमाण(linit17);
    पूर्णाङ्क zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    पूर्णाङ्क linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    संरचना bf_SS bf_finit = { .bit = 1 };
    संरचना bfn_SS bfn_finit = { .c.bit = 1 };
    संरचना bfa_SS bfa_finit = { .c[1].bit = 1 };
    संरचना bf_SS bfaa_finit[3] = { [1].bit = 1 };
    संरचना bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    संरचना b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    प्रारूप_लिख("sinit1=%d\n", sinit1);
    प्रारूप_लिख("sinit2=%d\n", sinit2);
    प्रारूप_लिख("sinit3=%d %d %d %d\n", 
           परिमाण(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    प्रारूप_लिख("sinit6=%d\n", परिमाण(sinit6));
    प्रारूप_लिख("sinit7=%d %d %d %d\n", 
           परिमाण(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    प्रारूप_लिख("sinit8=%s\n", sinit8);
    प्रारूप_लिख("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    प्रारूप_लिख("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    प्रारूप_लिख("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    प्रति(i=0;i<3;i++)
        प्रति(j=0;j<2;j++)
            प्रारूप_लिख("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    प्रारूप_लिख("linit1=%d\n", linit1);
    प्रारूप_लिख("linit2=%d\n", linit2);
    प्रारूप_लिख("linit6=%d\n", परिमाण(linit6));
    प्रारूप_लिख("linit8=%d %s\n", परिमाण(linit8), linit8);

    प्रारूप_लिख("sinit12=%s\n", sinit12);
    प्रारूप_लिख("sinit13=%d %s %s %s\n",
           परिमाण(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    प्रारूप_लिख("sinit14=%s\n", sinit14);

    प्रति(i=0;i<10;i++) प्रारूप_लिख(" %d", linit12[i]);
    प्रारूप_लिख("\n");
    प्रति(i=0;i<10;i++) प्रारूप_लिख(" %d", linit13[i]);
    प्रारूप_लिख("\n");
    प्रति(i=0;i<10;i++) प्रारूप_लिख(" %d", linit14[i]);
    प्रारूप_लिख("\n");
    प्रति(i=0;i<10;i++) प्रारूप_लिख(" %d", linit15[i]);
    प्रारूप_लिख("\n");
    प्रारूप_लिख("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    प्रारूप_लिख("linit17=%d\n", linit17);
    प्रारूप_लिख("sinit15=%d\n", sinit15[0]);
    प्रारूप_लिख("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    प्रारूप_लिख("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    प्रति(i=0;i<10;i++)
        प्रारूप_लिख("%x ", sinit18[i]);
    प्रारूप_लिख("\n");
    /* complex init check */
    प्रारूप_लिख("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    प्रारूप_लिख("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    प्रारूप_लिख("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", परिमाण cix20, परिमाण cix21, परिमाण cix22);

    प्रारूप_लिख("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    प्रारूप_लिख("arrtype2: %d %d\n", परिमाण(sinit19), परिमाण(sinit20));
    प्रारूप_लिख("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    प्रारूप_लिख("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    प्रारूप_लिख("arrtype5: %d %d\n", परिमाण(sinit21), परिमाण(sinit22));
    प्रारूप_लिख("arrtype6: %d\n", परिमाण(arrtype2));

    प्रारूप_लिख("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    प्रारूप_लिख("sinit24=%d\n", sinit24);
    प्रारूप_लिख("linit18= %d %d\n", linit18[0], linit18[1]);
    प्रारूप_लिख ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    प्रारूप_लिख ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    प्रारूप_लिख ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    प्रारूप_लिख ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    प्रति (i = 0; i < 3; i++)
        प्रारूप_लिख ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

शून्य switch_uc(अचिह्नित वर्ण uc)
{
	विकल्प (uc) {
	    पक्ष 0xfb ... 0xfe:
		प्रारूप_लिख("ucsw:1\n");
		भङ्ग;
	    पक्ष 0xff:
		प्रारूप_लिख("ucsw:2\n");
		भङ्ग;
	    पक्ष 0 ... 5:
		प्रारूप_लिख("ucsw:3\n");
		भङ्ग;
	    स्वभाव:
		प्रारूप_लिख("ucsw: broken!\n");
	}
}

शून्य switch_sc(चिह्नित वर्ण sc)
{
	विकल्प (sc) {
	    पक्ष -5 ... -2:
		प्रारूप_लिख("scsw:1\n");
		भङ्ग;
	    पक्ष -1:
		प्रारूप_लिख("scsw:2\n");
		भङ्ग;
	    पक्ष 0 ... 5:
		प्रारूप_लिख("scsw:3\n");
		भङ्ग;
	    स्वभाव:
		प्रारूप_लिख("scsw: broken!\n");
	}
}

शून्य switch_test()
{
    पूर्णाङ्क i;
    अचिह्नित दीर्घ दीर्घ ull;
    दीर्घ दीर्घ ll;

    प्रति(i=0;i<15;i++) {
        विकल्प(i) {
        पक्ष 0:
        पक्ष 1:
            प्रारूप_लिख("a");
            भङ्ग;
        स्वभाव:
            प्रारूप_लिख("%d", i);
            भङ्ग;
        पक्ष 8 ... 12:
            प्रारूप_लिख("c");
            भङ्ग;
        पक्ष 3:
            प्रारूप_लिख("b");
            भङ्ग;
        पक्ष 0xc33c6b9fU:
        पक्ष 0x7c9eeeb9U:
            भङ्ग;
        }
    }
    प्रारूप_लिख("\n");

    प्रति (i = 1; i <= 5; i++) {
	ull = (अचिह्नित दीर्घ दीर्घ)i << 61;
	विकल्प (ull) {
	    पक्ष 1ULL << 61:
		प्रारूप_लिख("ullsw:1\n");
		भङ्ग;
	    पक्ष 2ULL << 61:
		प्रारूप_लिख("ullsw:2\n");
		भङ्ग;
	    पक्ष 3ULL << 61:
		प्रारूप_लिख("ullsw:3\n");
		भङ्ग;
	    पक्ष 4ULL << 61:
		प्रारूप_लिख("ullsw:4\n");
		भङ्ग;
	    पक्ष 5ULL << 61:
		प्रारूप_लिख("ullsw:5\n");
		भङ्ग;
	    स्वभाव:
		प्रारूप_लिख("ullsw: broken!\n");
	}
    }

    प्रति (i = 1; i <= 5; i++) {
	ll = (दीर्घ दीर्घ)i << 61;
	विकल्प (ll) {
	    पक्ष 1LL << 61:
		प्रारूप_लिख("llsw:1\n");
		भङ्ग;
	    पक्ष 2LL << 61:
		प्रारूप_लिख("llsw:2\n");
		भङ्ग;
	    पक्ष 3LL << 61:
		प्रारूप_लिख("llsw:3\n");
		भङ्ग;
	    पक्ष 4LL << 61:
		प्रारूप_लिख("llsw:4\n");
		भङ्ग;
	    पक्ष 5LL << 61:
		प्रारूप_लिख("llsw:5\n");
		भङ्ग;
	    स्वभाव:
		प्रारूप_लिख("llsw: broken!\n");
	}
    }

    प्रति (i = -5; i <= 5; i++) {
	switch_uc((अचिह्नित वर्ण)i);
    }

    प्रति (i = -5; i <= 5; i++) {
	switch_sc ((चिह्नित वर्ण)i);
    }
}

/* ISOC99 _Bool type */
शून्य c99_bool_test(शून्य)
{
#यदि_परिभाषितम् BOOL_ISOC99
    पूर्णाङ्क a;
    _Bool b, b2;

    प्रारूप_लिख("sizeof(_Bool) = %d\n", परिमाण(_Bool));
    a = 3;
    प्रारूप_लिख("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    प्रारूप_लिख("b = %d\n", b);
    b++;
    प्रारूप_लिख("b = %d\n", b);
    b2 = 0;
    प्रारूप_लिख("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           परिमाण ((चञ्चल पूर्णाङ्क)a ? b : b2));
#यदि_अन्तः
}

शून्य bitfield_test(शून्य)
{
    पूर्णाङ्क a;
    ह्रस्व sa;
    अचिह्नित वर्ण ca;
    संरचना sbf1 {
        पूर्णाङ्क f1 : 3;
        पूर्णाङ्क : 2;
        पूर्णाङ्क f2 : 1;
        पूर्णाङ्क : 0;
        पूर्णाङ्क f3 : 5;
        पूर्णाङ्क f4 : 7;
        अचिह्नित पूर्णाङ्क f5 : 7;
    } st1;
    प्रारूप_लिख("sizeof(st1) = %d\n", परिमाण(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    प्रारूप_लिख("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    प्रारूप_लिख("%d %d\n", sa, ca);

    st1.f1 = 7;
    यदि (st1.f1 == -1) 
        प्रारूप_लिख("st1.f1 == -1\n");
    अन्यथा 
        प्रारूप_लिख("st1.f1 != -1\n");
    यदि (st1.f2 == -1) 
        प्रारूप_लिख("st1.f2 == -1\n");
    अन्यथा 
        प्रारूप_लिख("st1.f2 != -1\n");

    संरचना sbf2 {
        दीर्घ दीर्घ f1 : 45;
        दीर्घ दीर्घ : 2;
        दीर्घ दीर्घ f2 : 35;
        अचिह्नित दीर्घ दीर्घ f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (दीर्घ दीर्घ)a << 25;
    st2.f3 = a;
    st2.f2++;
    प्रारूप_लिख("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#यदि 0
    Disabled प्रति now until further clarification re GCC compatibility
    संरचना sbf3 {
        पूर्णाङ्क f1 : 7;
        पूर्णाङ्क f2 : 1;
        वर्ण f3;
        पूर्णाङ्क f4 : 8;
        पूर्णाङ्क f5 : 1;
        पूर्णाङ्क f6 : 16;
    } st3;
    प्रारूप_लिख("sizeof(st3) = %d\n", परिमाण(st3));
#यदि_अन्तः

    संरचना sbf4 {
	पूर्णाङ्क x : 31;
	वर्ण y : 2;
    } st4;
    st4.y = 1;
    प्रारूप_लिख("st4.y == %d\n", st4.y);
    संरचना sbf5 {
	पूर्णाङ्क a;
	वर्ण b;
	पूर्णाङ्क x : 12, y : 4, : 0, : 4, z : 3;
	वर्ण c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    प्रारूप_लिख("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    संरचना sbf6 {
	ह्रस्व x : 12;
	अचिह्नित वर्ण y : 2;
    } st6;
    st6.y = 1;
    प्रारूप_लिख("st6.y == %d\n", st6.y);
}

#यदि_परिभाषितम् __x86_64__
#परिभाषय FLOAT_FMT "%f\n"
#अन्यथा
/* x86's float isn't compatible with GCC */
#परिभाषय FLOAT_FMT "%.5f\n"
#यदि_अन्तः

/* declare strto* functions as they are C99 */
द्विगुण strtod(ध्रुव वर्ण *nptr, वर्ण **endptr);

#यदि defined(_WIN32)
भिन्न strtof(ध्रुव वर्ण *nptr, वर्ण **endptr) {प्रत्यागम (भिन्न)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ध्रुव वर्ण *nptr, वर्ण **endptr) {प्रत्यागम (LONG_DOUBLE)strtod(nptr, endptr);}
#अन्यथा
भिन्न strtof(ध्रुव वर्ण *nptr, वर्ण **endptr);
LONG_DOUBLE strtold(ध्रुव वर्ण *nptr, वर्ण **endptr);
#यदि_अन्तः

#परिभाषय FTEST(उपसर्गः, typename, type, fmt)\
शून्य उपसर्गः ## cmp(type a, type b)\
{\
    प्रारूप_लिख("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    प्रारूप_लिख(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    प्रारूप_लिख(fmt "\n", ++a);\
    प्रारूप_लिख(fmt "\n", a++);\
    प्रारूप_लिख(fmt "\n", a);\
    b = 0;\
    प्रारूप_लिख("%d %d\n", !a, !b);\
}\
शून्य उपसर्गः ## fcast(type a)\
{\
    भिन्न fa;\
    द्विगुण da;\
    LONG_DOUBLE la;\
    पूर्णाङ्क ia;\
    दीर्घ दीर्घ llia;\
    अचिह्नित पूर्णाङ्क ua;\
    अचिह्नित दीर्घ दीर्घ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    प्रारूप_लिख("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (पूर्णाङ्क)a;\
    llia = (दीर्घ दीर्घ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (अचिह्नित पूर्णाङ्क)a;\
    llua = (अचिह्नित दीर्घ दीर्घ)a;\
    प्रारूप_लिख("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    प्रारूप_लिख("itof: " fmt "\n", b);\
    b = ua;\
    प्रारूप_लिख("utof: " fmt "\n", b);\
    b = llia;\
    प्रारूप_लिख("lltof: " fmt "\n", b);\
    b = llua;\
    यदि (CC_NAME != CC_clang) प्रारूप_लिख("ulltof: " fmt "\n", b);\
}\
\
भिन्न उपसर्गः ## retf(type a) { प्रत्यागम a; }\
द्विगुण उपसर्गः ## retd(type a) { प्रत्यागम a; }\
LONG_DOUBLE उपसर्गः ## retld(type a) { प्रत्यागम a; }\
\
शून्य उपसर्गः ## call(शून्य)\
{\
    प्रारूप_लिख("float: " FLOAT_FMT, उपसर्गः ## retf(42.123456789));\
    प्रारूप_लिख("double: %f\n", उपसर्गः ## retd(42.123456789));\
    प्रारूप_लिख("long double: %Lf\n", उपसर्गः ## retld(42.123456789));\
    प्रारूप_लिख("strto%s: %f\n", #prefix, (द्विगुण)strto ## उपसर्गः("1.2", रिक्त));\
}\
\
शून्य उपसर्गः ## signed_zeros(शून्य) \
{\
  type x = 0.0, y = -0.0, n, p;\
  यदि (x == y)\
    प्रारूप_लिख ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  अन्यथा\
    प्रारूप_लिख ("x != y; this is wrong!\n");\
\
  n = -x;\
  यदि (x == n)\
    प्रारूप_लिख ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  अन्यथा\
    प्रारूप_लिख ("x != -x; this is wrong!\n");\
\
  p = +y;\
  यदि (x == p)\
    प्रारूप_लिख ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    प्रारूप_लिख ("x != +y; this is wrong!\n");\
  p = -y;\
  यदि (x == p)\
    प्रारूप_लिख ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    प्रारूप_लिख ("x != -y; this is wrong!\n");\
}\
शून्य उपसर्गः ## nan(शून्य)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    प्रारूप_लिख("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
शून्य उपसर्गः ## test(शून्य)\
{\
    प्रारूप_लिख("testing '%s'\n", #typename);\
    उपसर्गः ## cmp(1, 2.5);\
    उपसर्गः ## cmp(2, 1.5);\
    उपसर्गः ## cmp(1, 1);\
    उपसर्गः ## fcast(234.6);\
    उपसर्गः ## fcast(-2334.6);\
    उपसर्गः ## call();\
    उपसर्गः ## signed_zeros();\
    यदि (CC_NAME != CC_clang) उपसर्गः ## nan();\
}

FTEST(f, भिन्न, भिन्न, "%f")
FTEST(d, द्विगुण, द्विगुण, "%f")
FTEST(ld, दीर्घ द्विगुण, LONG_DOUBLE, "%Lf")

द्विगुण ftab1[3] = { 1.2, 3.4, -5.6 };


शून्य float_test(शून्य)
{
#यदि !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    चञ्चल भिन्न fa, fb;
    चञ्चल द्विगुण da, db;
    पूर्णाङ्क a;
    अचिह्नित पूर्णाङ्क b;
    स्थिर द्विगुण nan2 = 0.0/0.0;
    स्थिर द्विगुण inf1 = 1.0/0.0;
    स्थिर द्विगुण inf2 = 1e5000;
    चञ्चल LONG_DOUBLE la;

    प्रारूप_लिख("sizeof(float) = %d\n", परिमाण(भिन्न));
    प्रारूप_लिख("sizeof(double) = %d\n", परिमाण(द्विगुण));
    प्रारूप_लिख("sizeof(long double) = %d\n", परिमाण(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    प्रारूप_लिख("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    प्रारूप_लिख("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    प्रारूप_लिख("da=%f\n", da);
    fa = 123;
    प्रारूप_लिख("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    प्रारूप_लिख("da = %f\n", da);
    b = 4000000000;
    db = b;
    प्रारूप_लिख("db = %f\n", db);
    प्रारूप_लिख("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    प्रारूप_लिख ("da subnormal = %a\n", da);
    प्रारूप_लिख ("da subnormal = %.40g\n", da);
    प्रारूप_लिख ("la subnormal = %La\n", la);
    प्रारूप_लिख ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    प्रारूप_लिख ("da/2 subnormal = %a\n", da);
    प्रारूप_लिख ("da/2 subnormal = %.40g\n", da);
    प्रारूप_लिख ("la/2 subnormal = %La\n", la);
    प्रारूप_लिख ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    प्रारूप_लिख ("fa subnormal = %a\n", fa);
    प्रारूप_लिख ("fa subnormal = %.40g\n", fa);
    प्रारूप_लिख ("la subnormal = %La\n", la);
    प्रारूप_लिख ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    प्रारूप_लिख ("fa/2 subnormal = %a\n", fa);
    प्रारूप_लिख ("fa/2 subnormal = %.40g\n", fa);
    प्रारूप_लिख ("la/2 subnormal = %La\n", la);
    प्रारूप_लिख ("la/2 subnormal = %.40Lg\n", la);
#यदि_अन्तः
}

पूर्णाङ्क fib(पूर्णाङ्क n)
{
    यदि (n <= 2)
        प्रत्यागम 1;
    अन्यथा
        प्रत्यागम fib(n-1) + fib(n-2);
}

#यदि __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#अन्यथा
शून्य __attribute__((aligned(16))) aligned_function(पूर्णाङ्क i) {}
#यदि_अन्तः

शून्य funcptr_test()
{
    शून्य (*func)(पूर्णाङ्क);
    पूर्णाङ्क a;
    संरचना {
        पूर्णाङ्क dummy;
        शून्य (*func)(पूर्णाङ्क);
    } st1;
    दीर्घ diff;

    func = &अङ्कः;
    (*func)(12345);
    func = अङ्कः;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = अङ्कः;
    st1.func(12346);
    प्रारूप_लिख("sizeof1 = %d\n", परिमाण(funcptr_test));
    प्रारूप_लिख("sizeof2 = %d\n", परिमाण funcptr_test);
    प्रारूप_लिख("sizeof3 = %d\n", परिमाण(&funcptr_test));
    प्रारूप_लिख("sizeof4 = %d\n", परिमाण &funcptr_test);
    a = 0;
    func = अङ्कः + a;
    diff = func - अङ्कः;
    func(42);
    (func + diff)(42);
    (अङ्कः + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    प्रारूप_लिख("aligned_function (should be zero): %d\n", ((पूर्णाङ्क)(uintptr_t)func) & 15);
}

शून्य lloptest(दीर्घ दीर्घ a, दीर्घ दीर्घ b)
{
    अचिह्नित दीर्घ दीर्घ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    प्रारूप_लिख("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    यदि (b != 0) {
        प्रारूप_लिख("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*द्विमान*/
    प्रारूप_लिख("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    प्रारूप_लिख("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    प्रारूप_लिख("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    प्रारूप_लिख("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    प्रारूप_लिख("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    प्रारूप_लिख("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    प्रारूप_लिख("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    प्रारूप_लिख("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

शून्य llshift(दीर्घ दीर्घ a, पूर्णाङ्क b)
{
    प्रारूप_लिख("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिह्नित दीर्घ दीर्घ)a >> b,
           a >> b,
           a << b);
    प्रारूप_लिख("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिह्नित दीर्घ दीर्घ)a >> 3,
           a >> 3,
           a << 3);
    प्रारूप_लिख("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिह्नित दीर्घ दीर्घ)a >> 35,
           a >> 35,
           a << 35);
}

शून्य llfloat(शून्य)
{
    भिन्न fa;
    द्विगुण da;
    LONG_DOUBLE lda;
    दीर्घ दीर्घ la, lb, lc;
    अचिह्नित दीर्घ दीर्घ ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    प्रारूप_लिख("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    प्रारूप_लिख("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    प्रारूप_लिख("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    प्रारूप_लिख("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    प्रारूप_लिख("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

दीर्घ दीर्घ llfunc1(पूर्णाङ्क a)
{
    प्रत्यागम a * 2;
}

संरचना S {
    पूर्णाङ्क id; 
    वर्ण item;
};

दीर्घ दीर्घ पूर्णाङ्क मानम्(संरचना S *v)
{
    प्रत्यागम ((दीर्घ दीर्घ पूर्णाङ्क)v->item);
}

दीर्घ दीर्घ llfunc2(दीर्घ दीर्घ x, दीर्घ दीर्घ y, पूर्णाङ्क z)
{
    प्रत्यागम x * y * z;
}

शून्य check_opl_save_regs(वर्ण *a, दीर्घ दीर्घ b, पूर्णाङ्क c)
{
    *a = b < 0 && !c;
}

शून्य longlong_test(शून्य)
{
    दीर्घ दीर्घ a, b, c;
    पूर्णाङ्क ia;
    अचिह्नित पूर्णाङ्क ua;
    प्रारूप_लिख("sizeof(long long) = %d\n", परिमाण(दीर्घ दीर्घ));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    प्रारूप_लिख(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    प्रारूप_लिख(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (दीर्घ दीर्घ)1,
           (दीर्घ दीर्घ)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    प्रारूप_लिख(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#यदि 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    प्रारूप_लिख(XLONG_LONG_FORMAT"\n", c);
#यदि_अन्तः

    /* long long reg spill test */
    {
          संरचना S a;

          a.item = 3;
          प्रारूप_लिख("%lld\n", मानम्(&a));
    }
    lloptest(0x80000000, 0);

    {
        दीर्घ दीर्घ *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        प्रारूप_लिख("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        प्रारूप_लिख("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    प्रारूप_लिख("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    प्रारूप_लिख(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    दीर्घ दीर्घ *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    अचिह्नित दीर्घ दीर्घ u = 0x8000000000000001ULL;
    u = (अचिह्नित)(u + 1);
    प्रारूप_लिख("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (अचिह्नित)(पूर्णाङ्क)(u + 1);
    प्रारूप_लिख("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    वर्ण cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    प्रारूप_लिख("check_opl_save_regs: %d\n", cc);
}

शून्य manyarg_test(शून्य)
{
    LONG_DOUBLE ld = 1234567891234LL;
    प्रारूप_लिख("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    प्रारूप_लिख("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    प्रारूप_लिख("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    प्रारूप_लिख("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    प्रारूप_लिख("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    प्रारूप_लिख("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

शून्य*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        संरचना X { पूर्णाङ्क _x; };
        संरचना X *x = va_arg(ap, संरचना X *);
        प्रत्यागम x;
}

शून्य vprintf1(ध्रुव वर्ण *fmt, ...)
{
    va_list ap, aq;
    ध्रुव वर्ण *p;
    पूर्णाङ्क c, i;
    द्विगुण d;
    दीर्घ दीर्घ ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    प्रति(;;) {
        c = *p;
        यदि (c == '\0')
            भङ्ग;
        p++;
        यदि (c == '%') {
            c = *p;
            विकल्प(c) {
            पक्ष '\0':
                गच्छ the_अन्तः;
            पक्ष 'd':
                i = va_arg(ap, पूर्णाङ्क);
                प्रारूप_लिख("%d", i);
                भङ्ग;
            पक्ष 'f':
                d = va_arg(ap, द्विगुण);
                प्रारूप_लिख("%f", d);
                भङ्ग;
            पक्ष 'l':
                ll = va_arg(ap, दीर्घ दीर्घ);
                प्रारूप_लिख(LONG_LONG_FORMAT, ll);
                भङ्ग;
            पक्ष 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                प्रारूप_लिख("%Lf", ld);
                भङ्ग;
            }
            p++;
        } अन्यथा {
            अक्षरं_लिख(c);
        }
    }
 the_अन्तः:
    va_end(aq);
    va_end(ap);
}

संरचना myspace {
    ह्रस्व पूर्णाङ्क profile;
};
संरचना myspace2 {
#यदि CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    वर्ण a[1];
#अन्यथा
    वर्ण a[0];
#यदि_अन्तः
};
संरचना myspace3 {
    वर्ण a[1];
};
संरचना myspace4 {
    वर्ण a[2];
};
संरचना mytest {
    शून्य *foo, *bar, *baz;
};

संरचना mytest stdarg_for_struct(संरचना myspace bob, ...)
{
    संरचना myspace george, bill;
    संरचना myspace2 alex1;
    संरचना myspace3 alex2;
    संरचना myspace4 alex3;
    va_list ap;
    ह्रस्व पूर्णाङ्क validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, संरचना myspace2);
    alex2    = va_arg(ap, संरचना myspace3);
    alex3    = va_arg(ap, संरचना myspace4);
    bill     = va_arg(ap, संरचना myspace);
    george   = va_arg(ap, संरचना myspace);
    validate = va_arg(ap, पूर्णाङ्क);
    प्रारूप_लिख("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    प्रत्यागम (संरचना mytest) {};
}

शून्य stdarg_for_libc(ध्रुव वर्ण *fmt, ...)
{
    va_list तर्काः;
    va_start(तर्काः, fmt);
    vprintf(fmt, तर्काः);
    va_end(तर्काः);
}

शून्य stdarg_syntax(पूर्णाङ्क n, ...)
{
    पूर्णाङ्क i;
    va_list ap;
    यदि (1)
      va_start(ap, n);
    अन्यथा
      ;
    i = va_arg(ap, पूर्णाङ्क);
    प्रारूप_लिख("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

प्रकारनिर्देश संरचना{
    द्विगुण x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

स्थिर शून्य stdarg_double_struct(पूर्णाङ्क nargs, पूर्णाङ्क posd,...)
{
    पूर्णाङ्क i;
    द्विगुण d;
    point pi;
    va_list तर्काः;

    प्रारूप_लिख ("stdarg_double_struct: %d\n", posd);
    va_start(तर्काः,posd);
    प्रति(i = 0; i < nargs; i++) {
        यदि (i == posd) {
            d = va_arg (तर्काः, द्विगुण);
            प्रारूप_लिख ("d %d = %g\n", i, d);
        }
        अन्यथा {
            pi = va_arg (तर्काः, point);
            प्रारूप_लिख ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(तर्काः);
}

शून्य stdarg_test(शून्य)
{
    LONG_DOUBLE ld = 1234567891234LL;
    संरचना myspace bob;
    संरचना myspace2 bob2;
    संरचना myspace3 bob3;
    संरचना myspace4 bob4;

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
#यदि !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#यदि_अन्तः
}

पूर्णाङ्क reltab[3] = { 1, 2, 3 };

पूर्णाङ्क *rel1 = &reltab[1];
पूर्णाङ्क *rel2 = &reltab[2];

शून्य getmyaddress(शून्य)
{
    प्रारूप_लिख("in getmyaddress\n");
}

#यदि_परिभाषितम् __LP64__
दीर्घ __pa_symbol(शून्य)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       प्रत्यागम ((दीर्घ)(((अचिह्नित दीर्घ)(&rel1))) - (0xffffffff80000000UL));
}
#यदि_अन्तः

uintptr_t theaddress = (uintptr_t)getmyaddress;
शून्य relocation_test(शून्य)
{
    शून्य (*fptr)(शून्य) = (शून्य (*)(शून्य))theaddress;
    प्रारूप_लिख("*rel1=%d\n", *rel1);
    प्रारूप_लिख("*rel2=%d\n", *rel2);
    fptr();
#यदि_परिभाषितम् __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    प्रारूप_लिख("pa_symbol: %d\n", (दीर्घ)&rel1 == __pa_symbol() - 0x80000000);
#यदि_अन्तः
}

शून्य old_style_f(a,b,c)
     पूर्णाङ्क a, b;
     द्विगुण c;
{
    प्रारूप_लिख("a=%d b=%d b=%f\n", a, b, c);
}

शून्य decl_func1(पूर्णाङ्क cmpfn())
{
    प्रारूप_लिख("cmpfn=%lx\n", (दीर्घ)cmpfn);
}

शून्य decl_func2(cmpfn)
पूर्णाङ्क cmpfn();
{
    प्रारूप_लिख("cmpfn=%lx\n", (दीर्घ)cmpfn);
}

शून्य old_style_function_test(शून्य)
{
#यदि CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#अन्यथा
    old_style_f((शून्य *)1, 2, 3.0);
#यदि_अन्तः
    decl_func1(रिक्त);
    decl_func2(रिक्त);
}

शून्य alloca_test()
{
    वर्ण *p = alloca(16);
    वाक्यं_प्रतिलिख(p,"123456789012345");
    प्रारूप_लिख("alloca: p is %s\n", p);
    वर्ण *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    प्रारूप_लिख("alloca: %s\n", वाक्यं_प्रतिलिख(alloca(वाक्यदैर्घ्यम्(demo)+1),demo) );
}

शून्य *bounds_checking_is_enabled()
{
    वर्ण ca[10], *cp = ca-1;
    प्रत्यागम (ca != cp + 1) ? cp : रिक्त;
}

प्रकारनिर्देश पूर्णाङ्क constant_negative_array_आकार_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

शून्य c99_vla_test_1(पूर्णाङ्क size1, पूर्णाङ्क size2)
{
    पूर्णाङ्क आकार = size1 * size2;
    पूर्णाङ्क tab1[आकार][2], tab2[10][2];
    शून्य *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    आकार = आकार-1;
    
    प्रारूप_लिख("Test C99 VLA 1 (sizeof): ");
    प्रारूप_लिख("%s\n", (परिमाण tab1 == size1 * size2 * 2 * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    प्रारूप_लिख("Test C99 VLA 2 (ptrs subtract): ");
    प्रारूप_लिख("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (परिमाण(पूर्णाङ्क) * 2)) ? "PASSED" : "FAILED");
    प्रारूप_लिख("Test C99 VLA 3 (ptr add): ");
    प्रारूप_लिख("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    प्रारूप_लिख("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    प्रारूप_लिख("%s\n", (*((पूर्णाङ्क *) (tab1_ptr + (size1 * 2 + 1) * परिमाण(पूर्णाङ्क))) == 42) ? "PASSED" : "FAILED");

    प्रारूप_लिख("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    यदि (bad_ptr = bounds_checking_is_enabled()) {
        पूर्णाङ्क *t1 = &tab1[size1 * size2 - 1][3];
        पूर्णाङ्क *t2 = &tab2[9][3];
        प्रारूप_लिख("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        प्रारूप_लिख("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        वर्ण*c1 = 1 + परिमाण(tab1) + (वर्ण*)tab1;
        वर्ण*c2 = 1 + परिमाण(tab2) + (वर्ण*)tab2;
        प्रारूप_लिख("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        प्रारूप_लिख("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *i1 = tab1[-1];
        पूर्णाङ्क *i2 = tab2[-1];
        प्रारूप_लिख("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        प्रारूप_लिख("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *x1 = tab1[size1 * size2 + 1];
        पूर्णाङ्क *x2 = tab2[10 + 1];
        प्रारूप_लिख("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        प्रारूप_लिख("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } अन्यथा {
        प्रारूप_लिख("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    प्रारूप_लिख("\n");
}

शून्य c99_vla_test_2(पूर्णाङ्क d, पूर्णाङ्क h, पूर्णाङ्क w)
{
    पूर्णाङ्क x, y, z;
    पूर्णाङ्क (*arr)[h][w] = स्मृतिं_देहि(परिमाण(पूर्णाङ्क) * d*h*w);
    पूर्णाङ्क c = 1;
    स्थिर पूर्णाङ्क (*starr)[h][w];

    प्रारूप_लिख("Test C99 VLA 6 (pointer)\n");

    प्रति (z=0; z<d; z++) {
        प्रति (y=0; y<h; y++) {
            प्रति (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    प्रति (z=0; z<d; z++) {
        प्रति (y=0; y<h; y++) {
            प्रति (x=0; x<w; x++) {
                प्रारूप_लिख(" %2d", arr[z][y][x]);
            }
            पङ्क्तिं_लिख("");
        }
        पङ्क्तिं_लिख("");
    }
    starr = &arr[1];
    प्रारूप_लिख(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        परिमाण (*arr), परिमाण (*arr)[0], परिमाण (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == परिमाण (*arr + 1) - परिमाण arr,
        0 == परिमाण परिमाण *arr - परिमाण arr,
        starr[0][2][3] == arr[1][2][3]
        );
    मुक्त (arr);
}

शून्य c99_vla_test_3a (पूर्णाङ्क arr[2][3][4])
{
    प्रारूप_लिख ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3b(पूर्णाङ्क s, पूर्णाङ्क arr[s][3][4])
{
    प्रारूप_लिख ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3c(पूर्णाङ्क s, पूर्णाङ्क arr[2][s][4])
{
    प्रारूप_लिख ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3d(पूर्णाङ्क s, पूर्णाङ्क arr[2][3][s])
{
    प्रारूप_लिख ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3e(पूर्णाङ्क s, पूर्णाङ्क arr[][3][--s])
{
    प्रारूप_लिख ("%d %d %d\n", परिमाण arr, s, arr[1][2][3]);
}

शून्य c99_vla_test_3(शून्य)
{
    पूर्णाङ्क a[2][3][4];

    स्मृतिं_पूरय (a, 0, परिमाण(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

शून्य c99_vla_test(शून्य)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


शून्य sizeof_test(शून्य)
{
    पूर्णाङ्क a;
    पूर्णाङ्क **ptr;

    प्रारूप_लिख("sizeof(int) = %d\n", परिमाण(पूर्णाङ्क));
    प्रारूप_लिख("sizeof(unsigned int) = %d\n", परिमाण(अचिह्नित पूर्णाङ्क));
    प्रारूप_लिख("sizeof(long) = %d\n", परिमाण(दीर्घ));
    प्रारूप_लिख("sizeof(unsigned long) = %d\n", परिमाण(अचिह्नित दीर्घ));
    प्रारूप_लिख("sizeof(short) = %d\n", परिमाण(ह्रस्व));
    प्रारूप_लिख("sizeof(unsigned short) = %d\n", परिमाण(अचिह्नित ह्रस्व));
    प्रारूप_लिख("sizeof(char) = %d\n", परिमाण(वर्ण));
    प्रारूप_लिख("sizeof(unsigned char) = %d\n", परिमाण(अचिह्नित वर्ण));
    प्रारूप_लिख("sizeof(func) = %d\n", परिमाण sizeof_test());
    a = 1;
    प्रारूप_लिख("sizeof(a++) = %d\n", परिमाण a++);
    प्रारूप_लिख("a=%d\n", a);
    ptr = रिक्त;
    प्रारूप_लिख("sizeof(**ptr) = %d\n", परिमाण (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    प्रारूप_लिख("sizeof(sizeof(int) = %d\n", परिमाण(परिमाण(पूर्णाङ्क)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -परिमाण(uintptr_t);
    प्रारूप_लिख ("%lu %lu\n", t, t2);

    /* some alignof tests */
    प्रारूप_लिख("__alignof__(int) = %d\n", __alignof__(पूर्णाङ्क));
    प्रारूप_लिख("__alignof__(unsigned int) = %d\n", __alignof__(अचिह्नित पूर्णाङ्क));
    प्रारूप_लिख("__alignof__(short) = %d\n", __alignof__(ह्रस्व));
    प्रारूप_लिख("__alignof__(unsigned short) = %d\n", __alignof__(अचिह्नित ह्रस्व));
    प्रारूप_लिख("__alignof__(char) = %d\n", __alignof__(वर्ण));
    प्रारूप_लिख("__alignof__(unsigned char) = %d\n", __alignof__(अचिह्नित वर्ण));
    प्रारूप_लिख("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    प्रारूप_लिख("sizeof(char[1+2*a]) = %d\n", परिमाण(वर्ण[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    प्रारूप_लिख("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   परिमाण( (संरचना {पूर्णाङ्क i; पूर्णाङ्क j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    प्रारूप_लिख("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   परिमाण (संरचना {ह्रस्व i; ह्रस्व j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    प्रारूप_लिख("sizeof(t && 0) = %d\n", परिमाण(t && 0));
    प्रारूप_लिख("sizeof(1 && 1) = %d\n", परिमाण(1 && 1));
    प्रारूप_लिख("sizeof(t || 1) = %d\n", परिमाण(t || 1));
    प्रारूप_लिख("sizeof(0 || 0) = %d\n", परिमाण(0 || 0));

    पूर्णाङ्क arr[4], fn();
    प्रारूप_लिख("sizeof(0, arr) = %d\n", परिमाण(0, arr));
    प्रारूप_लिख("sizeof(0, fn) = %d\n", परिमाण(0, fn));
}

शून्य typeof_test(शून्य)
{
    द्विगुण a;
    typeof(a) b;
    typeof(भिन्न) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    प्रारूप_लिख("a=%f b=%f c=%f\n", a, b, c);
}


संरचना hlist_ग्रन्थिः;
संरचना hlist_शीर्ष {
    संरचना hlist_ग्रन्थिः *first, *चरमः;
};

शून्य consume_ulong (अचिह्नित दीर्घ i)
{
    i = 0;
}

शून्य statement_व्यञ्जकम्_test(शून्य)
{
    पूर्णाङ्क a, i;

    /* Basic stmt expr test */
    a = 0;
    प्रति(i=0;i<10;i++) {
        a += 1 + 
            ( { पूर्णाङ्क b, j; 
                b = 0; 
                प्रति(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    प्रारूप_लिख("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    शून्य *v = (शून्य*)39;
    typeof(({
	    (संरचना hlist_ग्रन्थिः *)v;
	    })) x;
    typeof (x)
	ptr = (संरचना hlist_ग्रन्थिः *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#परिभाषय some_attr     __attribute__((aligned(1)))
#परिभाषय tps(str) ({                  \
            स्थिर ध्रुव वर्ण *t some_attr = str; \
            t;                                    \
          })
    प्रारूप_लिख ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    पूर्णाङ्क t = 40;
    पूर्णाङ्क b = ({ पूर्णाङ्क t = 41; t; });
    पूर्णाङ्क c = ({ पूर्णाङ्क t = 42; t; });

    /* Test that aggregate return values work.  */
    संरचना hlist_शीर्ष h
	= ({
	   प्रकारनिर्देश संरचना hlist_शीर्ष T;
	   दीर्घ pre = 48;
	   T t = { (शून्य*)43, (शून्य*)44 };
	   दीर्घ post = 49;
	   t;
	   });
    प्रारूप_लिख ("stmtexpr: %d %d %d\n", t, b, c);
    प्रारूप_लिख ("stmtexpr: %ld %ld\n", (दीर्घ)h.first, (दीर्घ)h.चरमः);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (अचिह्नित दीर्घ)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: यदि (i++ == 0) गच्छ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      गच्छ LBL;
    });
  LBL:
    प्रारूप_लिख("stmtexpr: %d should be 2\n", i);
}

शून्य local_label_test(शून्य)
{
    पूर्णाङ्क a;
    गच्छ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        गच्छ l1;
    l4:
        प्रारूप_लिख("aa1\n");
        गच्छ l3;
    l2:
        प्रारूप_लिख("aa3\n");
        गच्छ l4;
    l1:
        प्रारूप_लिख("aa2\n");
        गच्छ l2;
    l3:;
        1;
    });
    प्रारूप_लिख("a=%d\n", a);
    प्रत्यागम;
 l4:
    प्रारूप_लिख("bb1\n");
    गच्छ l2;
 l1:
    प्रारूप_लिख("bb2\n");
    गच्छ l4;
}

/* inline assembler test */
#यदि (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

प्रकारनिर्देश __SIZE_TYPE__ word;

/* from linux kernel */
स्थिर वर्ण * strncat1(वर्ण * dest,ध्रुव वर्ण * src,आकार_t गणनम्_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गणनम्_2)
	: "memory");
प्रत्यागम dest;
}

स्थिर वर्ण * strncat2(वर्ण * dest,ध्रुव वर्ण * src,आकार_t गणनम्_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गणनम्_2)
	: "memory");
प्रत्यागम dest;
}

स्थिर अन्तःस्थ शून्य * memcpy1(शून्य * गन्तव्यम्, ध्रुव शून्य * from, आकार_t n)
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
	:"0" (n/4), "q" (n),"1" ((word) गन्तव्यम्),"2" ((word) from)
	: "memory");
प्रत्यागम (गन्तव्यम्);
}

स्थिर अन्तःस्थ शून्य * memcpy2(शून्य * गन्तव्यम्, ध्रुव शून्य * from, आकार_t n)
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
	:"0" (n/4), "q" (n),"1" ((word) गन्तव्यम्),"2" ((word) from)
	: "memory");
प्रत्यागम (गन्तव्यम्);
}

स्थिर __inline__ शून्य sigaddset1(अचिह्नित पूर्णाङ्क *समुच्चयः, पूर्णाङ्क _sig)
{
	__asm__("btsl %1,%0" : "=m"(*समुच्चयः) : "Ir"(_sig - 1) : "cc");
}

स्थिर __inline__ शून्य sigdelset1(अचिह्नित पूर्णाङ्क *समुच्चयः, पूर्णाङ्क _sig)
{
	asm("btrl %1,%0" : "=m"(*समुच्चयः) : "Ir"(_sig - 1) : "cc", "flags");
}

#यदि_परिभाषितम् __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
स्थिर __inline__ __const__ अचिह्नित पूर्णाङ्क swab32(अचिह्नित पूर्णाङ्क x)
{
        प्रत्यागम ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#अन्यथा
स्थिर __inline__ __const__ अचिह्नित पूर्णाङ्क swab32(अचिह्नित पूर्णाङ्क x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	प्रत्यागम x;
}
#यदि_अन्तः

स्थिर __inline__ अचिह्नित दीर्घ दीर्घ mul64(अचिह्नित पूर्णाङ्क a, अचिह्नित पूर्णाङ्क b)
{
    अचिह्नित दीर्घ दीर्घ res;
#यदि_परिभाषितम् __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    अचिह्नित पूर्णाङ्क resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((अचिह्नित दीर्घ दीर्घ)resh << 32) | resl;
#अन्यथा
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#यदि_अन्तः
    प्रत्यागम res;
}

स्थिर __inline__ अचिह्नित दीर्घ दीर्घ inc64(अचिह्नित दीर्घ दीर्घ a)
{
    अचिह्नित दीर्घ दीर्घ res;
#यदि_परिभाषितम् __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#अन्यथा
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#यदि_अन्तः
    प्रत्यागम res;
}

संरचना struct123 {
    पूर्णाङ्क a;
    पूर्णाङ्क b;
};
संरचना struct1231 {
    word addr;
};

word mconstraint_test(संरचना struct1231 *r)
{
    word ret;
    अचिह्नित पूर्णाङ्क a[2];
    a[0] = 0;
    __asm__ चञ्चल ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(संरचना struct123 *)r->addr));
    प्रत्यागम ret + a[0];
}

#यदि_परिभाषितम् __x86_64__
पूर्णाङ्क fls64(अचिह्नित दीर्घ दीर्घ x)
{
  पूर्णाङ्क bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  प्रत्यागम bitpos + 1;
}
#यदि_अन्तः

शून्य other_constraints_test(शून्य)
{
    word ret;
    पूर्णाङ्क var;
#यदि CC_NAME != CC_clang
    __asm__ चञ्चल ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    प्रारूप_लिख ("oc1: %d\n", ret == (word)&var);
#यदि_अन्तः
}

#यदि_अपरिभाषितम् _WIN32
/* Test global asm blocks playing with aliases.  */
शून्य आधारः_func(शून्य)
{
  प्रारूप_लिख ("asmc: base\n");
}

#यदि_अपरिभाषितम् __APPLE__
बाह्य शून्य override_func1 (शून्य);
बाह्य शून्य override_func2 (शून्य);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

शून्य override_func2 (शून्य)
{
  प्रारूप_लिख ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
बाह्य पूर्णाङ्क bug_सारणी[] __attribute__((section("__bug_table")));
वर्ण * get_asm_string (शून्य)
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
#यदि_अपरिभाषितम् __clang__
  बाह्य पूर्णाङ्क some_चिह्नम्;
  asm चञ्चल (".globl some_symbol\n"
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
  वर्ण * str = ((वर्ण*)bug_सारणी) + bug_सारणी[1];
  प्रत्यागम str;
#अन्यथा
  प्रत्यागम (वर्ण *) "A string";
#यदि_अन्तः
}

/* This checks another constructs with local labels.  */
बाह्य अचिह्नित वर्ण alld_stuff[];
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

शून्य asm_local_label_diff (शून्य)
{
  प्रारूप_लिख ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#यदि_अन्तः //!__APPLE__
#यदि_अन्तः //!_WIN32

/* This checks that static local variables are available from assembler.  */
शून्य asm_local_statics (शून्य)
{
  स्थिर पूर्णाङ्क localint = 41;
  asm("incl %0" : "+m" (localint));
  प्रारूप_लिख ("asm_local_statics: %d\n", localint);
}

स्थिर
अचिह्नित पूर्णाङ्क समुच्चयः;

शून्य fancy_copy (अचिह्नित *अन्तर्, अचिह्नित *बहिर्गमनम्)
{
  asm चञ्चल ("" : "=r" (*बहिर्गमनम्) : "0" (*अन्तर्));
}

शून्य fancy_copy2 (अचिह्नित *अन्तर्, अचिह्नित *बहिर्गमनम्)
{
  asm चञ्चल ("mov %0,(%1)" : : "r" (*अन्तर्), "r" (बहिर्गमनम्) : "memory");
}

#यदि defined __x86_64__
शून्य clobber_r12(शून्य)
{
    asm चञ्चल("mov $1, %%r12" ::: "r12");
}
#यदि_अन्तः

शून्य test_उच्चः_clobbers_really(शून्य)
{
#यदि defined __x86_64__
    पञ्जिका word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm चञ्चल("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm चञ्चल("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    प्रारूप_लिख("asmhc: 0x%x\n", val2);
#यदि_अन्तः
}

शून्य test_उच्चः_clobbers(शून्य)
{
#यदि defined __x86_64__
    word x1, x2;
    asm चञ्चल("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_उच्चः_clobbers_really();
    asm चञ्चल("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm चञ्चल("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#यदि_अन्तः
}

स्थिर दीर्घ cpu_सङ्ख्या;
शून्य trace_console(दीर्घ len, दीर्घ len2)
{
#यदि_परिभाषितम् __x86_64__
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
    यदि (0
        &&
            ({
              दीर्घ pscr_ret__;
              विकल्प(len) {
                पक्ष 4:
                    {
                       दीर्घ pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 8:	प्रारूप_लिख("bla"); pfo_ret__ = 42; भङ्ग;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  भङ्ग;
                पक्ष 8:
                    {
                       दीर्घ pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	भङ्ग;
                         पक्ष 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	भङ्ग;
                         पक्ष 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	भङ्ग;
                         पक्ष 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	भङ्ग;
                         स्वभाव: प्रारूप_लिख("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  भङ्ग;
              }
              pscr_ret__;
            }))
      {
        प्रारूप_लिख("huh?\n");
      }
#यदि_अन्तः
}

शून्य test_asm_dead_संहिता(शून्य)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm चञ्चल ("" : "=D" (rdi) : "0" (0));
  (शून्य)परिमाण (({
      पूर्णाङ्क var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm चञ्चल ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

शून्य test_asm_call(शून्य)
{
#यदि defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  स्थिर वर्ण str[] = "PATH";
  वर्ण *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm चञ्चल ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#यदि 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#अन्यथा
		"call getenv;"
#यदि_अन्तः
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  प्रारूप_लिख("asmd: %s\n", s);
#यदि_अन्तः
}

#यदि defined __x86_64__
# define RX "(%rip)"
#अन्यथा
# define RX
#यदि_अन्तः

शून्य asm_dot_test(शून्य)
{
#यदि_अपरिभाषितम् __APPLE__
    पूर्णाङ्क x;
    प्रति (x = 1;; ++x) {
        पूर्णाङ्क r = x;
        विकल्प (x) {
        पक्ष 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        पक्ष 2:
#यदि_अपरिभाषितम् __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#अन्यथा
            asm(".text; mov $123, %eax; jmp p0");
#यदि_अन्तः
	पक्ष 3:
#यदि !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#अन्यथा
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#यदि_अन्तः
            asm(".text; mov X"RX",%eax; jmp p0");
        पक्ष 4:
#यदि_परिभाषितम् __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#अन्यथा
#यदि_अपरिभाषितम् _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#अन्यथा
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#यदि_अन्तः
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#यदि_अन्तः
        पक्ष 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); भङ्ग;
	}
        यदि (r == x)
            भङ्ग;
        प्रारूप_लिख("asm_dot_test %d: %d\n", x, r);
    }
#यदि_अन्तः
}

शून्य asm_pcrel_test(शून्य)
{
    अचिह्नित o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    प्रारूप_लिख("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

शून्य asm_test(शून्य)
{
    वर्ण buf[128];
    अचिह्नित पूर्णाङ्क val, val2;
    संरचना struct123 s1;
    संरचना struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    पूर्णाङ्क आधारः_func = 42;
    शून्य override_func3 (शून्य);
    word asmret;
#यदि_परिभाषितम् BOOL_ISOC99
    _Bool somebool;
#यदि_अन्तः
    पञ्जिका पूर्णाङ्क regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm चञ्चल ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm चञ्चल ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    प्रारूप_लिख("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    प्रारूप_लिख("%s\n", buf);

    /* 'A' constraint test */
    प्रारूप_लिख("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    प्रारूप_लिख("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    प्रारूप_लिख("mconstraint: %d", mconstraint_test(&s2));
    प्रारूप_लिख(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    समुच्चयः = 0xff;
    sigdelset1(&समुच्चयः, 2);
    sigaddset1(&समुच्चयः, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    गच्छ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(समुच्चयः) : "Ir"(20) : "cc");
    प्रारूप_लिख("set=0x%x\n", समुच्चयः);
    val = 0x01020304;
    प्रारूप_लिख("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#यदि_अपरिभाषितम् _WIN32
#यदि_अपरिभाषितम् __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm चञ्चल(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    प्रारूप_लिख("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#यदि_अन्तः
#यदि_अन्तः
    asm_local_statics();
#यदि_अपरिभाषितम् __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm चञ्चल("" : "=r" (asmret) : "0"(s2));
    यदि (asmret != s2.addr)
      प्रारूप_लिख("asmstr: failed\n");
#यदि_अन्तः
#यदि_परिभाषितम् BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm चञ्चल("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    यदि (!somebool)
      प्रारूप_लिख("asmbool: failed\n");
#यदि_अन्तः
    val = 43;
    fancy_copy (&val, &val2);
    प्रारूप_लिख ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    प्रारूप_लिख ("fancycpy2(%d)=%d\n", val, val2);
    asm चञ्चल ("mov $0x4243, %%esi" : "=r" (regvar));
    प्रारूप_लिख ("regvar=%x\n", regvar);
    test_उच्चः_clobbers();
    trace_console(8, 8);
    test_asm_dead_संहिता();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    प्रत्यागम;
 label1:
    गच्छ label2;
}

#अन्यथा

शून्य asm_test(शून्य)
{
}

#यदि_अन्तः

#परिभाषय COMPAT_TYPE(type1, type2) \
{\
    प्रारूप_लिख("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

पूर्णाङ्क constant_p_var;

पूर्णाङ्क func(शून्य);


/* __builtin_clz and __builtin_ctz return random values for 0 */
स्थिर शून्य builtin_test_द्वयङ्काः(अचिह्नित दीर्घ दीर्घ x, पूर्णाङ्क cnt[])
{
#यदि GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    यदि ((अचिह्नित पूर्णाङ्क) x) cnt[3] += __builtin_clz(x);
    यदि ((अचिह्नित दीर्घ) x) cnt[4] += __builtin_clzl(x);
    यदि ((अचिह्नित दीर्घ दीर्घ) x) cnt[5] += __builtin_clzll(x);

    यदि ((अचिह्नित पूर्णाङ्क) x) cnt[6] += __builtin_ctz(x);
    यदि ((अचिह्नित दीर्घ) x) cnt[7] += __builtin_ctzl(x);
    यदि ((अचिह्नित दीर्घ दीर्घ) x) cnt[8] += __builtin_ctzll(x);

#यदि GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#यदि_अन्तः

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#यदि_अन्तः
}

शून्य builtin_test(शून्य)
{
    ह्रस्व s;
    पूर्णाङ्क i;
    दीर्घ दीर्घ ll;
#यदि GCC_MAJOR >= 3
    COMPAT_TYPE(पूर्णाङ्क, पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, अचिह्नित पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, वर्ण);
    COMPAT_TYPE(पूर्णाङ्क, ध्रुव पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, चञ्चल पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क[2], ध्रुव पूर्णाङ्क[2]);
    COMPAT_TYPE(पूर्णाङ्क[2][3], चञ्चल पूर्णाङ्क[][3]);
    COMPAT_TYPE(पूर्णाङ्क (*)[], ध्रुव पूर्णाङ्क (*)[]);
#यदि_अपरिभाषितम् __clang__
    COMPAT_TYPE(__typeof__(1 ? (ध्रुव पूर्णाङ्क (*)[2])0 : (पूर्णाङ्क (*)[2])0),
                ध्रुव पूर्णाङ्क (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ध्रुव पूर्णाङ्क (*)[2][3])0 :
                              (चञ्चल पूर्णाङ्क (*)[2][3])0),
                ध्रुव चञ्चल पूर्णाङ्क (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (चञ्चल पूर्णाङ्क (*)[2][3])0 :
                              (ध्रुव पूर्णाङ्क (*)[2][3])0),
                ध्रुव चञ्चल पूर्णाङ्क (*)[2][3]);
#अन्यथा
    /* clang doesn't combine qualifiers through array types */
    प्रारूप_लिख("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    प्रारूप_लिख("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    प्रारूप_लिख("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#यदि_अन्तः
    COMPAT_TYPE(पूर्णाङ्क *, पूर्णाङ्क *);
    COMPAT_TYPE(पूर्णाङ्क *, शून्य *);
    COMPAT_TYPE(पूर्णाङ्क *, ध्रुव पूर्णाङ्क *);
    COMPAT_TYPE(वर्ण *, अचिह्नित वर्ण *);
    COMPAT_TYPE(वर्ण *, चिह्नित वर्ण *);
    COMPAT_TYPE(वर्ण *, वर्ण *);
    COMPAT_TYPE(वर्ण **, शून्य *);
#यदि_अन्तः
    प्रारूप_लिख("res1 = %d\n", __builtin_constant_p(1));
    प्रारूप_लिख("res2 = %d\n", __builtin_constant_p(1 + 2));
    प्रारूप_लिख("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    प्रारूप_लिख("res4 = %d\n", __builtin_constant_p(constant_p_var));
    प्रारूप_लिख("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    प्रारूप_लिख("res6 = %d\n", __builtin_constant_p(i && 1));
    प्रारूप_लिख("res7 = %d\n", __builtin_constant_p("hi"));
    प्रारूप_लिख("res8 = %d\n", __builtin_constant_p(func()));
#यदि_अपरिभाषितम् __clang__
    प्रारूप_लिख("res10 = %d\n", __builtin_constant_p(i && 0));
    प्रारूप_लिख("res11 = %d\n", __builtin_constant_p(i * 0));
    प्रारूप_लिख("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    प्रारूप_लिख("res13 = %d\n", __builtin_constant_p((1,7)));
#अन्यथा
    /* clang doesn't regard these as constant expression */
    प्रारूप_लिख("res10 = 1\n");
    प्रारूप_लिख("res11 = 1\n");
    प्रारूप_लिख("res12 = 1\n");
    प्रारूप_लिख("res13 = 0\n");
#यदि_अन्तः

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    प्रारूप_लिख("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    प्रारूप_लिख("bce: %d\n", i);
    i = परिमाण (__builtin_choose_expr (1, ll, s));
    प्रारूप_लिख("bce: %d\n", i);
    i = परिमाण (__builtin_choose_expr (0, ll, s));
    प्रारूप_लिख("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	पूर्णाङ्क cnt[18];
	अचिह्नित दीर्घ दीर्घ r = 0;

	स्मृतिं_पूरय(cnt, 0, परिमाण(cnt));
	builtin_test_द्वयङ्काः(0, cnt);
	builtin_test_द्वयङ्काः(0xffffffffffffffffull, cnt);
        प्रति (i = 0; i < 64; i++)
	    builtin_test_द्वयङ्काः(1ull << i, cnt);
        प्रति (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_द्वयङ्काः(r, cnt);
	}
	प्रति (i = 0; i < 18; i++)
	    प्रारूप_लिख ("%d %d\n", i, cnt[i]);
    }
}

#यदि defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
शून्य weak_test(शून्य) {}
#अन्यथा
बाह्य पूर्णाङ्क __attribute__((weak)) weak_f1(शून्य);
बाह्य पूर्णाङ्क __attribute__((weak)) weak_f2(शून्य);
बाह्य पूर्णाङ्क                       weak_f3(शून्य);
बाह्य पूर्णाङ्क __attribute__((weak)) weak_v1;
बाह्य पूर्णाङ्क __attribute__((weak)) weak_v2;
बाह्य पूर्णाङ्क                       weak_v3;

बाह्य पूर्णाङ्क                           (*weak_fpa)() __attribute__((weak));
बाह्य पूर्णाङ्क __attribute__((weak))     (*weak_fpb)();
बाह्य     __attribute__((weak)) पूर्णाङ्क (*weak_fpc)();

बाह्य पूर्णाङ्क                     weak_asm_f1(शून्य) asm("weak_asm_f1x") __attribute((weak));
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_f2(शून्य) asm("weak_asm_f2x")                    ;
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_f3(शून्य) asm("weak_asm_f3x") __attribute((weak));
बाह्य पूर्णाङ्क                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_v3(शून्य) asm("weak_asm_v3x") __attribute((weak));

#यदि_अपरिभाषितम् __clang__
स्थिर ध्रुव आकार_t dummy = 0;
बाह्य __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
बाह्य __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
बाह्य __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#यदि_अन्तः

पूर्णाङ्क some_lib_func(शून्य);
पूर्णाङ्क dummy_impl_सम्बन्धि_slf(शून्य) { प्रत्यागम 444; }
#यदि_अपरिभाषितम् __clang__
पूर्णाङ्क some_lib_func(शून्य) __attribute__((weak, alias("dummy_impl_of_slf")));
#यदि_अन्तः

पूर्णाङ्क weak_toolate() __attribute__((weak));
पूर्णाङ्क weak_toolate() { प्रत्यागम 0; }

शून्य __attribute__((weak)) weak_test(शून्य)
{
	प्रारूप_लिख("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	प्रारूप_लिख("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	प्रारूप_लिख("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	प्रारूप_लिख("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	प्रारूप_लिख("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	प्रारूप_लिख("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	प्रारूप_लिख("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	प्रारूप_लिख("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	प्रारूप_लिख("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	प्रारूप_लिख("weak_asm_f1=%d\n", weak_asm_f1 != रिक्त);
	प्रारूप_लिख("weak_asm_f2=%d\n", weak_asm_f2 != रिक्त);
	प्रारूप_लिख("weak_asm_f3=%d\n", weak_asm_f3 != रिक्त);
	प्रारूप_लिख("weak_asm_v1=%d\n",&weak_asm_v1 != रिक्त);
	प्रारूप_लिख("weak_asm_v2=%d\n",&weak_asm_v2 != रिक्त);
	प्रारूप_लिख("weak_asm_v3=%d\n",&weak_asm_v3 != रिक्त);
#यदि_परिभाषितम् __clang__
	प्रारूप_लिख("some_lib_func=444\n");
#अन्यथा
	प्रारूप_लिख("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#यदि_अन्तः
}

पूर्णाङ्क __attribute__((weak)) weak_f2() { प्रत्यागम 222; }
पूर्णाङ्क __attribute__((weak)) weak_f3() { प्रत्यागम 333; }
पूर्णाङ्क __attribute__((weak)) weak_v2 = 222;
पूर्णाङ्क __attribute__((weak)) weak_v3 = 333;
#यदि_अन्तः

शून्य const_func(ध्रुव पूर्णाङ्क a)
{
}

शून्य const_warn_test(शून्य)
{
    const_func(1);
}

संरचना condstruct {
  पूर्णाङ्क i;
};

पूर्णाङ्क getme (संरचना condstruct *s, पूर्णाङ्क i)
{
  पूर्णाङ्क i1 = (i == 0 ? 0 : s)->i;
  पूर्णाङ्क i2 = (i == 0 ? s : 0)->i;
  पूर्णाङ्क i3 = (i == 0 ? (शून्य*)0 : s)->i;
  पूर्णाङ्क i4 = (i == 0 ? s : (शून्य*)0)->i;
  प्रत्यागम i1 + i2 + i3 + i4;
}

संरचना global_दत्त
{
  पूर्णाङ्क a[40];
  पूर्णाङ्क *b[40];
};

संरचना global_दत्त global_दत्त;

पूर्णाङ्क global_दत्त_getstuff (पूर्णाङ्क *, पूर्णाङ्क);

शून्य global_दत्त_callit (पूर्णाङ्क i)
{
  *global_दत्त.b[i] = global_दत्त_getstuff (global_दत्त.b[i], 1);
}

पूर्णाङ्क global_दत्त_getstuff (पूर्णाङ्क *p, पूर्णाङ्क i)
{
  प्रत्यागम *p + i;
}

शून्य global_दत्त_test (शून्य)
{
  global_दत्त.a[0] = 42;
  global_दत्त.b[0] = &global_दत्त.a[0];
  global_दत्त_callit (0);
  प्रारूप_लिख ("%d\n", global_दत्त.a[0]);
}

संरचना cmpcmpS
{
  अचिह्नित वर्ण fill : 3;
  अचिह्नित वर्ण b1 : 1;
  अचिह्नित वर्ण b2 : 1;
  अचिह्नित वर्ण fill2 : 3;
};

पूर्णाङ्क glob1, glob2, glob3;

शून्य compare_comparisons (संरचना cmpcmpS *s)
{
  यदि (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    प्रारूप_लिख ("comparing comparisons broken\n");
}

शून्य cmp_comparison_test(शून्य)
{
  संरचना cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

पूर्णाङ्क fcompare (द्विगुण a, द्विगुण b, पूर्णाङ्क संहिता)
{
  विकल्प (संहिता) {
    पक्ष 0: प्रत्यागम a == b;
    पक्ष 1: प्रत्यागम a != b;
    पक्ष 2: प्रत्यागम a < b;
    पक्ष 3: प्रत्यागम a >= b;
    पक्ष 4: प्रत्यागम a > b;
    पक्ष 5: प्रत्यागम a <= b;
  }
  प्रत्यागम 0;
}

शून्य math_cmp_test(शून्य)
{
  द्विगुण nan = 0.0/0.0;
  द्विगुण one = 1.0;
  द्विगुण two = 2.0;
  पूर्णाङ्क comp = 0;
  पूर्णाङ्क v;
#परिभाषय bug(a,b,op,iop,part) प्रारूप_लिख("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#परिभाषय FCMP(a,b,op,iop,संहिता) \
  यदि (fcompare (a,b,संहिता))    \
    bug (a,b,op,iop,1); \
  यदि (a op b) \
    bug (a,b,op,iop,2); \
  यदि (a iop b) \
    ; \
  अन्यथा \
    bug (a,b,op,iop,3); \
  यदि ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  यदि ((a iop b) || comp) \
    ; \
  अन्यथा \
    bug (a,b,op,iop,5); \
  यदि (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  यदि (!fcompare (nan, nan, 1))
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

द्विगुण get100 () { प्रत्यागम 100.0; }

शून्य callsave_test(शून्य)
{
  पूर्णाङ्क i, s; द्विगुण *d; द्विगुण t;
  s = परिमाण (द्विगुण);
  प्रारूप_लिख ("callsavetest: %d\n", s);
  d = alloca (परिमाण(द्विगुण));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  प्रारूप_लिख ("%d\n", i);
}


शून्य bfa3(ptrdiff_t str_विस्थापनम्)
{
    प्रारूप_लिख("bfa3: %s\n", (वर्ण *)__builtin_frame_address(3) + str_विस्थापनम्);
}
शून्य bfa2(ptrdiff_t str_विस्थापनम्)
{
    प्रारूप_लिख("bfa2: %s\n", (वर्ण *)__builtin_frame_address(2) + str_विस्थापनम्);
    bfa3(str_विस्थापनम्);
}
शून्य bfa1(ptrdiff_t str_विस्थापनम्)
{
    प्रारूप_लिख("bfa1: %s\n", (वर्ण *)__builtin_frame_address(1) + str_विस्थापनम्);
    bfa2(str_विस्थापनम्);
}

शून्य builtin_frame_स्थानाङ्कः_test(शून्य)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#यदि_अपरिभाषितम् __arm__
    वर्ण str[] = "__builtin_frame_address";
    वर्ण *fp0 = __builtin_frame_address(0);

    प्रारूप_लिख("str: %s\n", str);
#यदि_अपरिभाषितम् __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#यदि_अन्तः
#यदि_अन्तः
}

वर्ण द्वारा_volatile (वर्ण i)
{
  वर्ण चञ्चल vi;
  vi = i;
  प्रत्यागम vi;
}

शून्य volatile_test(शून्य)
{
    यदि (द्वारा_volatile (42) != 42)
      प्रारूप_लिख (" broken\n");
    अन्यथा
      प्रारूप_लिख (" ok\n");
}

संरचना __attribute__((__packed__)) Spacked {
    वर्ण a;
    ह्रस्व b;
    पूर्णाङ्क c;
};
संरचना Spacked spacked;
प्रकारनिर्देश संरचना __attribute__((__packed__)) {
    वर्ण a;
    ह्रस्व b;
    पूर्णाङ्क c;
} Spacked2;
Spacked2 spacked2;
प्रकारनिर्देश संरचना Spacked3_s {
    वर्ण a;
    ह्रस्व b;
    पूर्णाङ्क c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
संरचना gate_struct64 {
    अचिह्नित ह्रस्व विस्थापनम्_नीचः;
    अचिह्नित ह्रस्व segment;
    अचिह्नित ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    अचिह्नित ह्रस्व विस्थापनम्_मध्यः;
    अचिह्नित विस्थापनम्_उच्चः;
    अचिह्नित zero1;
} __attribute__((packed));
प्रकारनिर्देश संरचना gate_struct64 gate_desc;
gate_desc a_gate_desc;
शून्य attrib_test(शून्य)
{
#यदि_अपरिभाषितम् _WIN32
  प्रारूप_लिख("attr: %d %d %d %d\n", परिमाण(संरचना Spacked),
	 परिमाण(spacked), परिमाण(Spacked2), परिमाण(spacked2));
  प्रारूप_लिख("attr: %d %d\n", परिमाण(Spacked3), परिमाण(spacked3));
  प्रारूप_लिख("attr: %d %d\n", परिमाण(gate_desc), परिमाण(a_gate_desc));
#यदि_अन्तः
}
बाह्य __attribute__((__unused__)) वर्ण * __attribute__((__unused__)) *
strange_attrib_placement (शून्य);

शून्य * __attribute__((__unused__)) get_void_ptr (शून्य *a)
{
  प्रत्यागम a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
स्थिर अन्तःस्थ
पूर्णाङ्क __get_order(अचिह्नित दीर्घ दीर्घ आकार)
{
  पूर्णाङ्क क्रमः;
  आकार -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      संरचना S { पूर्णाङ्क i : 1; } s; // constructed for this '1'
    }
  क्रमः = आकार;
  प्रत्यागम क्रमः;
}

/* This just forces the above inline function to be actually emitted.  */
पूर्णाङ्क force_get_क्रमः(अचिह्नित दीर्घ s)
{
    प्रत्यागम __get_order(s);
}

#परिभाषय pv(m) प्रारूप_लिख(परिमाण (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
शून्य bounds_check1_test (शून्य)
{
    संरचना s {
        पूर्णाङ्क x;
        दीर्घ दीर्घ y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
शून्य map_सङ्कलय(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c, पूर्णाङ्क d, पूर्णाङ्क e, पूर्णाङ्क f, पूर्णाङ्क g, पूर्णाङ्क h, पूर्णाङ्क i)
{
  प्रारूप_लिख ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

शून्य func_arg_test(शून्य)
{
    पूर्णाङ्क a = 0;
    पूर्णाङ्क b = 1;
    map_सङ्कलय(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#परिभाषय CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#यदि_परिभाषितम् __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#यदि_अन्तः

#परिभाषय	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
शून्य whitespace_test(शून्य)
{
    वर्ण *str;
    पूर्णाङ्क tcc_test = 1;

#यदि 1
    pri\
ntf("whitspace:\n");
#यदि_अन्तः
    pf("N=%d\n", 2);

#यदि_परिभाषितम् CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#यदि_अन्तः

    pri\
\
ntf("min=%d\n", 4);

#यदि_परिभाषितम् ACCEPT_LF_अन्तर्_वाक्यानि
    प्रारूप_लिख("len1=%d\n", वाक्यदैर्घ्यम्("
"));
#यदि_परिभाषितम् CORRECT_CR_HANDLING
    str = "
";
    प्रारूप_लिख("len1=%d str[0]=%d\n", वाक्यदैर्घ्यम्(str), str[0]);
#यदि_अन्तः
    प्रारूप_लिख("len1=%d\n", वाक्यदैर्घ्यम्("a
"));
#अन्यथा
    प्रारूप_लिख("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#यदि_अन्तः /* ACCEPT_LF_IN_STRINGS */

#यदि_परिभाषितम् __LINE__
    प्रारूप_लिख("__LINE__ defined\n");
#यदि_अन्तः

#यदि 0
    /* wrong with GCC */
    प्रारूप_लिख("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#पङ्क्तिः 1111
    प्रारूप_लिख("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#पङ्क्तिः 2222 "test"
    प्रारूप_लिख("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#यदि_अन्तः

    प्रारूप_लिख("\\
"12\\
063\\
n 456\"\n");

    प्रारूप_लिख ("%d\n",
#यदि 1
	    tcc_test
#यदि_अन्तः
            );

}

#परिभाषय सततम्_2(test) पङ्क्तिं_लिख("---- " #test " ----"), test(), पङ्क्तिं_लिख("")

पूर्णाङ्क मुख्यम्(पूर्णाङ्क argc, वर्ण **argv)
{
    सततम्_2(whitespace_test);
    सततम्_2(macro_test);
    सततम्_2(recursive_macro_test);
    सततम्_2(string_test);
    सततम्_2(व्यञ्जकम्_test);
    सततम्_2(scope_test);
    सततम्_2(scope2_test);
    सततम्_2(forward_test);
    सततम्_2(funcptr_test);
    सततम्_2(if_test);
    सततम्_2(loop_test);
    सततम्_2(switch_test);
    सततम्_2(goto_test);
    सततम्_2(enum_test);
    सततम्_2(typedef_test);
    सततम्_2(struct_test);
    सततम्_2(array_test);
    सततम्_2(व्यञ्जकम्_ptr_test);
    सततम्_2(bool_test);
    सततम्_2(optimize_बहिर्गमनम्_test);
    सततम्_2(expr2_test);
    सततम्_2(constant_व्यञ्जकम्_test);
    सततम्_2(व्यञ्जकम्_cmp_test);
    सततम्_2(char_short_test);
    सततम्_2(init_test);
    सततम्_2(compound_literal_test);
    सततम्_2(kr_test);
    सततम्_2(struct_नियोजय_test);
    सततम्_2(cast_test);
    सततम्_2(bitfield_test);
    सततम्_2(c99_bool_test);
    सततम्_2(float_test);
    सततम्_2(longlong_test);
    सततम्_2(manyarg_test);
    सततम्_2(stdarg_test);
    सततम्_2(relocation_test);
    सततम्_2(old_style_function_test);
    सततम्_2(alloca_test);
    सततम्_2(c99_vla_test);
    सततम्_2(sizeof_test);
    सततम्_2(typeof_test);
    सततम्_2(statement_व्यञ्जकम्_test);
    सततम्_2(local_label_test);
    सततम्_2(asm_test);
    सततम्_2(builtin_test);
    सततम्_2(weak_test);
    सततम्_2(global_दत्त_test);
    सततम्_2(cmp_comparison_test);
    सततम्_2(math_cmp_test);
    सततम्_2(callsave_test);
    सततम्_2(builtin_frame_स्थानाङ्कः_test);
    सततम्_2(volatile_test);
    सततम्_2(attrib_test);
    सततम्_2(bounds_check1_test);
    सततम्_2(func_arg_test);

    प्रत्यागम 0;
}
