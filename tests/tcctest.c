/*
 * TCC auto test program
 */
#అన్తర్భావ "config.h"

/* identify the configured reference compiler in use */
#నిర్వచించు CC_gcc 1
#నిర్వచించు CC_clang 2
#నిర్వచించు CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#నిర్వచించు ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#నిర్వచించు BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#నిర్వచించు C99_MACROS

#ఒకవేళ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#నిర్వచించు LONG_LONG_FORMAT "%lld"
#నిర్వచించు ULONG_LONG_FORMAT "%llu"
#నిర్వచించు XLONG_LONG_FORMAT "%llx"
#లేకపోతే
#నిర్వచించు LONG_LONG_FORMAT "%Ld"
#నిర్వచించు ULONG_LONG_FORMAT "%Lu"
#నిర్వచించు XLONG_LONG_FORMAT "%Lx"
#అయితే_ముగింపు

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ఒకవేళ defined(_WIN32)
#నిర్వచించు LONG_DOUBLE ద్విగుణ
#నిర్వచించు LONG_DOUBLE_LITERAL(x) x
#లేకపోతే
#నిర్వచించు LONG_DOUBLE దీర్ఘ ద్విగుణ
#నిర్వచించు LONG_DOUBLE_LITERAL(x) x ## L
#అయితే_ముగింపు

రకనిర్వచనం __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#నిర్వచించు TCCLIB_INC <tcclib.h>
#నిర్వచించు TCCLIB_INC1 <tcclib
#నిర్వచించు TCCLIB_INC2 h>
#నిర్వచించు TCCLIB_INC3 "tcclib.h"

#అన్తర్భావ TCCLIB_INC

#అన్తర్భావ TCCLIB_INC1.TCCLIB_INC2

#అన్తర్భావ TCCLIB_INC1.h>

#అన్తర్భావ TCCLIB_INC3

#అన్తర్భావ <tcclib.h>

#అన్తర్భావ "tcclib.h"

#అన్తర్భావ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#నిర్వచించు INC(name) <tests/name.h>
#నిర్వచించు funnyname 42test.h
#నిర్వచించు incdir tests/
#నిర్వచితమైతే __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#నిర్వచించు incname <tests/42test.h>
#లేకపోతే
#నిర్వచించు incname < incdir funnyname >
#అయితే_ముగింపు
#నిర్వచించు __stringify(x) #x
#నిర్వచించు stringify(x) __stringify(x)
#అన్తర్భావ INC(42test)
#అన్తర్భావ incname
#అన్తర్భావ stringify(funnyname)

పూర్ణాంకం fib(పూర్ణాంకం n);
శూన్య అంకె(పూర్ణాంకం n);
శూన్య forward_ref(శూన్య);
పూర్ణాంకం isid(పూర్ణాంకం c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
శూన్య funny_పంక్తి_continuation (పూర్ణాంకం, ..\
. );

#నిర్వచించు A 2
#నిర్వచించు N 1234 + A
#నిర్వచించు pf రాయి
#నిర్వచించు M1(a, b)  (a) + (b)

#నిర్వచించు str\
(s) # s
#నిర్వచించు glue(a, b) a ## b
#నిర్వచించు xglue(a, b) glue(a, b)
#నిర్వచించు HIGHLOW "hello"
#నిర్వచించు దిగువ_2 దిగువ_2 ", world"

స్థిర పూర్ణాంకం onetwothree = 123;
#నిర్వచించు onetwothree4 onetwothree
#నిర్వచించు onetwothree xglue(onetwothree,4)

#నిర్వచించు min(a, b) ((a) < (b) ? (a) : (b))

#నిర్వచితమైతే C99_MACROS
#నిర్వచించు dprintf(level,...) రాయి(__VA_ARGS__)
#అయితే_ముగింపు

/* gcc vararg macros */
#నిర్వచించు dprintf1(level, fmt, వాదనలు...) రాయి(fmt, ## వాదనలు)

#నిర్వచించు MACRO_NOARGS()

#నిర్వచించు TEST_CALL(f, ...) f(__VA_ARGS__)
#నిర్వచించు TEST_CONST()      123

#నిర్వచించు AAA 3
#నిర్వచనం_రద్దు AAA
#నిర్వచించు AAA 4

#ఒకవేళ 1
#నిర్వచించు B3 1
#లేదావేళ 1
#నిర్వచించు B3 2
#లేదావేళ 0
#నిర్వచించు B3 3
#లేకపోతే
#నిర్వచించు B3 4
#అయితే_ముగింపు

#నిర్వచించు __INT64_C(c)	c ## LL
#నిర్వచించు INT64_MIN	(-__INT64_C(9223372036854775807)-1)

పూర్ణాంకం qq(పూర్ణాంకం x)
{
    తిరిగి x + 40;
}
#నిర్వచించు qq(x) x

#నిర్వచించు spin_తాళం(తాళం) చేయి { } అయితే (0)
#నిర్వచించు wq_spin_తాళం spin_తాళం
#నిర్వచించు TEST2() wq_spin_తాళం(a)

శూన్య macro_test(శూన్య)
{
    pf("N=%d\n", N);
    రాయి("aaa=%d\n", AAA);

    రాయి("min=%d\n", min(1, min(2, -1)));

    రాయి("s1=%s\n", glue(ఎగువ_2, దిగువ_2));
    రాయి("s2=%s\n", xglue(ఎగువ_2, దిగువ_2));
    రాయి("s3=%s\n", str("c"));
    రాయి("s4=%s\n", str(a1));
    రాయి("B3=%d\n", B3);

    రాయి("onetwothree=%d\n", onetwothree);

#నిర్వచితమైతే A
    రాయి("A defined\n");
#అయితే_ముగింపు
#నిర్వచితమైతే B
    రాయి("B defined\n");
#అయితే_ముగింపు
#నిర్వచితమైతే A
    రాయి("A defined\n");
#లేకపోతే
    రాయి("A not defined\n");
#అయితే_ముగింపు
#నిర్వచితమైతే B
    రాయి("B defined\n");
#లేకపోతే
    రాయి("B not defined\n");
#అయితే_ముగింపు

#నిర్వచితమైతే A
    రాయి("A defined\n");
#నిర్వచితమైతే B
    రాయి("B1 defined\n");
#లేకపోతే
    రాయి("B1 not defined\n");
#అయితే_ముగింపు
#లేకపోతే
    రాయి("A not defined\n");
#నిర్వచితమైతే B
    రాయి("B2 defined\n");
#లేకపోతే
    రాయి("B2 not defined\n");
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ 1+1
    రాయి("test true1\n");
#అయితే_ముగింపు
#ఒకవేళ 0
    రాయి("test true2\n");
#అయితే_ముగింపు
#ఒకవేళ 1-1
    రాయి("test true3\n");
#అయితే_ముగింపు
#ఒకవేళ defined(A)
    రాయి("test trueA\n");
#అయితే_ముగింపు
#ఒకవేళ defined(B)
    రాయి("test trueB\n");
#అయితే_ముగింపు

#ఒకవేళ 0
    రాయి("test 0\n");
#లేదావేళ 0
    రాయి("test 1\n");
#లేదావేళ 2
    రాయి("test 2\n");
#లేకపోతే
    రాయి("test 3\n");
#అయితే_ముగింపు

    MACRO_NOARGS();

    రాయి("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#నిర్వచితమైతే C99_MACROS
    రాయి("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#అయితే_ముగింపు
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    రాయి("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    రాయి("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        పూర్ణాంకం a;
        a = 1;
        glue(a+, +);
        రాయి("a=%d\n", a);
        glue(a <, <= 2);
        రాయి("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#నిర్వచించు MF_s MF_hello
#నిర్వచించు MF_hello(సందేశం) రాయి("%s\n",సందేశం)

#నిర్వచించు MF_t రాయి("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    రాయి("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#నిర్వచించు qq1(x) 1
    రాయి("qq1=%d\n", qq1( ));

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

    రాయి("basefromheader %s\n", get_basefile_from_శీర్షిక());
    రాయి("base %s\n", __BASE_FILE__);
#ఒకవేళ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      స్థిరరాశి అక్షరం *fn = get_file_from_శీర్షిక();
      ఒకవేళ (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      రాయి("filefromheader %s\n", fn);
    }
#అయితే_ముగింపు

    రాయి("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_రెండవ = 1;
    have_included_42test_h_మూడవ = 1;

    /* Check that we don't complain about stray \ here */
    రాయి("print a backslash: %s\n", stringify(\\));
}


స్థిర శూన్య print_అంకె(అక్షరం *fn, పూర్ణాంకం పంక్తి, పూర్ణాంకం అంకె) {
    రాయి("fn %s, line %d, num %d\n", fn, పంక్తి, అంకె);
}

శూన్య recursive_macro_test(శూన్య)
{

#నిర్వచించు ELF32_ST_TYPE(val)              ((val) & 0xf)
#నిర్వచించు ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#నిర్వచించు STB_WEAK        2               /* Weak symbol */
#నిర్వచించు ELFW(type) ELF##32##_##type
    రాయి("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#నిర్వచించు WRAP(x) x
    
#నిర్వచించు print_అంకె(x) print_అంకె(__FILE__,__LINE__,x)
    print_అంకె(123);
    WRAP(print_అంకె(123));
    WRAP(WRAP(print_అంకె(123)));

స్థిర నిర్మాణం recursive_macro { పూర్ణాంకం rm_క్షేత్రం; } G;
#నిర్వచించు rm_క్షేత్రం (G.rm_క్షేత్రం)
    రాయి("rm_field = %d\n", rm_క్షేత్రం);
    రాయి("rm_field = %d\n", WRAP(rm_క్షేత్రం));
    WRAP((రాయి("rm_field = %d %d\n", rm_క్షేత్రం, WRAP(rm_క్షేత్రం))));
}

#ఒకవేళ __TINYC__
పూర్ణాంకం op(a, b)
{
    తిరిగి a / b;
}

పూర్ణాంకం ret(a)
{
    ఒకవేళ (a == 2)
        తిరిగి 1;
    ఒకవేళ (a == 3)
        తిరిగి 2;
    తిరిగి 0;
}
#అయితే_ముగింపు

#ఒకవేళ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#నిర్వచించు CONSTANTINDEXEDSTRLIT
#అయితే_ముగింపు
అక్షరం str_ag1[] = "b";
అక్షరం str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#నిర్వచితమైతే CONSTANTINDEXEDSTRLIT
అక్షరం str_ag3[] = { "ab"[1], 0 };
అక్షరం str_x[2] = { "xy" "z"[2], 0 };
#అయితే_ముగింపు
అక్షరం *str_ar[] = { "one", "two" };
నిర్మాణం str_SS {గుర్తులేని అక్షరం a[3], b; };
నిర్మాణం str_SS str_sinit15 = { "r" };
నిర్మాణం str_SS str_sinit16[] = { { "q" }, 2 };

స్థిర శూన్య string_test2()
{
    అక్షరం *p = "hello";
    అక్షరం a3[2] = { "p" };
    అక్షరం a4[2] = { "ab" "c"[2], 0 };
    అక్షరం *pa1 = "def" + 1;
    అక్షరం *pa2 = { "xyz" + 1 };
    పూర్ణాంకం i = 0;
    నిర్మాణం str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#నిర్వచితం_కాకపోతే CONSTANTINDEXEDSTRLIT
    అక్షరం str_ag3[] = { "ab"[1], 0 };
    అక్షరం str_x[2] = { "xy" "z"[2], 0 };
#అయితే_ముగింపు
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
    రాయి("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

శూన్య ps(స్థిరరాశి అక్షరం *s)
{
    పూర్ణాంకం c;
    అయితే (1) {
        c = *s;
        ఒకవేళ (c == 0)
            ఆపు;
        రాయి("%c", c);
        s++;
    }
}

స్థిరరాశి అక్షరం foo1_string[] = "\
bar\n\
test\14\
1";

శూన్య string_test()
{
    గుర్తులేని పూర్ణాంకం b;
    రాయి("string:\n");
    రాయి("\141\1423\143\n");/* dezdez test */
    రాయి("\x41\x42\x43\x3a\n");
    రాయి("c=%c\n", 'r');
    రాయి("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    రాయి("foo1_string='%s'\n", foo1_string);
#ఒకవేళ 0
    రాయి("wstring=%S\n", L"abc");
    రాయి("wstring=%S\n", L"abc" L"def" "ghi");
    రాయి("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    రాయి("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#అయితే_ముగింపు
    ps("test\n");
    b = 32;
    అయితే ((b = b + 1) < 96) {
        రాయి("%c", b);
    }
    రాయి("\n");
    రాయి("fib=%d\n", fib(33));
    b = 262144;
    అయితే (b != 0x80000000) {
        అంకె(b);
        b = b * 2;
    }
    string_test2();
}


శూన్య if1t(పూర్ణాంకం n, పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం c)
{
    ఒకవేళ (a && b) రాయి("if1t: %d 1 %d %d\n", n, a, b);
    ఒకవేళ (a && !b) రాయి("if1t: %d 2 %d %d\n", n, a, b);
    ఒకవేళ (!a && b) రాయి("if1t: %d 3 %d %d\n", n, a, b);
    ఒకవేళ (!a && !b) రాయి("if1t: %d 4 %d %d\n", n, a, b);
    ఒకవేళ (a || b) రాయి("if1t: %d 5 %d %d\n", n, a, b);
    ఒకవేళ (a || !b) రాయి("if1t: %d 6 %d %d\n", n, a, b);
    ఒకవేళ (!a || b) రాయి("if1t: %d 7 %d %d\n", n, a, b);
    ఒకవేళ (!a || !b) రాయి("if1t: %d 8 %d %d\n", n, a, b);
    ఒకవేళ (a && b || c) రాయి("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ఒకవేళ (a || b && c) రాయి("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ఒకవేళ (a > b - 1 && c) రాయి("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ఒకవేళ (a > b - 1 || c) రాయి("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ఒకవేళ (a > 0 && 1) రాయి("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ఒకవేళ (a > 0 || 0) రాయి("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

శూన్య if2t(శూన్య)
{
    ఒకవేళ (0 && 1 || రాయి("if2t:ok\n") || 1)
      రాయి("if2t:ok2\n");
    రాయి("if2t:ok3\n");
}

శూన్య if3t(శూన్య)
{
    అస్థిర దీర్ఘ దీర్ఘ i = 1;
    ఒకవేళ (i <= 18446744073709551615ULL)
      ;
    లేకపోతే
      రాయి ("if3t:wrong 1\n");
}

శూన్య if_test(శూన్య)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

శూన్య loop_test()
{
    పూర్ణాంకం i;
    i = 0;
    అయితే (i < 10)
        రాయి("%d", i++);
    రాయి("\n");
    కొరకు(i = 0; i < 10;i++)
        రాయి("%d", i);
    రాయి("\n");
    i = 0;
    చేయి {
        రాయి("%d", i++);
    } అయితే (i < 10);
    రాయి("\n");

    అక్షరం లెక్క_2 = 123;
    /* c99 for loop init test */
    కొరకు (కొలత_t లెక్క_2 = 1; లెక్క_2 < 3; లెక్క_2++)
        రాయి("count=%d\n", లెక్క_2);
    రాయి("count = %d\n", లెక్క_2);

    /* break/continue tests */
    i = 0;
    అయితే (1) {
        ఒకవేళ (i == 6)
            ఆపు;
        i++;
        ఒకవేళ (i == 3)
            కొనసాగు;
        రాయి("%d", i);
    }
    రాయి("\n");

    /* break/continue tests */
    i = 0;
    చేయి {
        ఒకవేళ (i == 6)
            ఆపు;
        i++;
        ఒకవేళ (i == 3)
            కొనసాగు;
        రాయి("%d", i);
    } అయితే(1);
    రాయి("\n");

    కొరకు(i = 0;i < 10;i++) {
        ఒకవేళ (i == 3)
            కొనసాగు;
        రాయి("%d", i);
    }
    రాయి("\n");
}

రకనిర్వచనం పూర్ణాంకం typedef_and_label;

శూన్య goto_test()
{
    పూర్ణాంకం i;
    స్థిర శూన్య *label_పట్టిక[3] = { &&label1, &&label2, &&label3 };
    నిర్మాణం {
        పూర్ణాంకం bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    రాయి("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    ఒకవేళ (i >= 10) 
        వెళ్ళు s_చివర;
    రాయి("%d", i);
    i++;
    వెళ్ళు s_loop;
 s_చివర:
    రాయి("\n");

    /* we also test computed gotos (GCC extension) */
    కొరకు(i=0;i<3;i++) {
        వెళ్ళు *label_పట్టిక[i];
    label1:
        రాయి("label1\n");
        వెళ్ళు తదుపరి;
    label2:
        రాయి("label2\n");
        వెళ్ళు తదుపరి;
    label3:
        రాయి("label3\n");
    తదుపరి: ;
    }
}

గణన {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

గణన test {
    E5 = 1000,
};

నిర్మాణం S_enum {
    గణన {E6 = 42, E7, E8} e:8;
};

గణన ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((గుర్తులేని దీర్ఘ)0xf000 << 31) << 1,
};

గణన { BIASU = -1U<<31 };
గణన { BIASS = -1 << 31 };

స్థిర పూర్ణాంకం getint(పూర్ణాంకం i)
{
  ఒకవేళ (i)
    తిరిగి 0;
  లేకపోతే
    తిరిగి (పూర్ణాంకం)(-1U << 31);
}

శూన్య enum_test()
{
    గణన test b1;
    /* The following should give no warning */
    గుర్తులేని *p = &b1;
    నిర్మాణం S_enum s = {E7};
    రాయి("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    రాయి("b1=%d\n", b1);
    రాయి("enum large: %ld\n", EL_large);

    ఒకవేళ (getint(0) == BIASU)
      రాయి("enum unsigned: ok\n");
    లేకపోతే
      రాయి("enum unsigned: wrong\n");
    ఒకవేళ (getint(0) == BIASS)
      రాయి("enum unsigned: ok\n");
    లేకపోతే
      రాయి("enum unsigned: wrong\n");
}

రకనిర్వచనం పూర్ణాంకం *my_ptr;

రకనిర్వచనం పూర్ణాంకం mytype1;
రకనిర్వచనం పూర్ణాంకం mytype2;

శూన్య typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    పూర్ణాంకం b;

    a = &b;
    *a = 1234;
    రాయి("a=%d\n", *a);
    mytype2 = 2;
    రాయి("mytype2=%d\n", mytype2);
}

శూన్య forward_test()
{
    forward_ref();
    forward_ref();
}


శూన్య forward_ref(శూన్య)
{
    రాయి("forward ok\n");
}

రకనిర్వచనం నిర్మాణం struct1 {
    పూర్ణాంకం f1;
    పూర్ణాంకం f2, f3;
    సంఘం union1 {
        పూర్ణాంకం v1;
        పూర్ణాంకం v2;
    } u;
    అక్షరం str[3];
} struct1;

నిర్మాణం struct2 {
    పూర్ణాంకం a;
    అక్షరం b;
};

సంఘం union2 {
    పూర్ణాంకం w1;
    పూర్ణాంకం w2;
};

నిర్మాణం struct1 st1, st2;

నిర్మాణం ఖాళీలు_mem {
    /* nothing */ ;
    పూర్ణాంకం x;
};

పూర్ణాంకం tab[3];
పూర్ణాంకం tab2[3][2];

పూర్ణాంకం g;

శూన్య f1(పూర్ణాంకం g)
{
    రాయి("g1=%d\n", g);
}

శూన్య scope_test()
{
    g = 2;
    f1(1);
    రాయి("g2=%d\n", g);
    {
        పూర్ణాంకం g;
        g = 3;
        రాయి("g3=%d\n", g);
        {
            పూర్ణాంకం g;
            g = 4;
            రాయి("g4=%d\n", g);
        }
    }
    రాయి("g5=%d\n", g);
}

పూర్ణాంకం st2_i;
పూర్ణాంకం *st2_p = &st2_i;
శూన్య scope2_test()
{
    అక్షరం a[50];
    st2_i = 42;
    కొరకు (పూర్ణాంకం st2_i = 1; st2_i < 10; st2_i++) {
        బాహ్య పూర్ణాంకం st2_i;
        st2_i++;
        రాయి("exloc: %d\n", st2_i);
    }
    రాయి("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
బాహ్య పూర్ణాంకం st_global1;
పూర్ణాంకం st_global1=42;
బాహ్య పూర్ణాంకం st_global1;
పూర్ణాంకం st_global1;
బాహ్య పూర్ణాంకం st_global2;
పూర్ణాంకం st_global2;
బాహ్య పూర్ణాంకం st_global2;
పూర్ణాంకం st_global2;

శూన్య array_test()
{
    పూర్ణాంకం i, j, a[4];

    రాయి("sizeof(a) = %d\n", పరిమాణం(a));
    రాయి("sizeof(\"a\") = %d\n", పరిమాణం("a"));
#నిర్వచితమైతే C99_MACROS
    రాయి("sizeof(__func__) = %d\n", పరిమాణం(__func__));
#అయితే_ముగింపు
    రాయి("sizeof tab %d\n", పరిమాణం(tab));
    రాయి("sizeof tab2 %d\n", పరిమాణం tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    రాయి("%d %d %d\n", tab[0], tab[1], tab[2]);
    కొరకు(i=0;i<3;i++)
        కొరకు(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    కొరకు(i=0;i<3*2;i++) {
        రాయి(" %3d", ((పూర్ణాంకం *)tab2)[i]);
    }
    రాయి("\n");
    రాయి("sizeof(size_t)=%d\n", పరిమాణం(కొలత_t));
    రాయి("sizeof(ptrdiff_t)=%d\n", పరిమాణం(ptrdiff_t));
}

శూన్య సమాసం_test()
{
    పూర్ణాంకం a, b;
    a = 0;
    రాయి("%d\n", a += 1);
    రాయి("%d\n", a -= 2);
    రాయి("%d\n", a *= 31232132);
    రాయి("%d\n", a /= 4);
    రాయి("%d\n", a %= 20);
    రాయి("%d\n", a &= 6);
    రాయి("%d\n", a ^= 7);
    రాయి("%d\n", a |= 8);
    రాయి("%d\n", a >>= 3);
    రాయి("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    రాయి("%d\n", a + 1);
    రాయి("%d\n", a - 2);
    రాయి("%d\n", a * 312);
    రాయి("%d\n", a / 4);
    రాయి("%d\n", b / 4);
    రాయి("%d\n", (గుర్తులేని)b / 4);
    రాయి("%d\n", a % 20);
    రాయి("%d\n", b % 20);
    రాయి("%d\n", (గుర్తులేని)b % 20);
    రాయి("%d\n", a & 6);
    రాయి("%d\n", a ^ 7);
    రాయి("%d\n", a | 8);
    రాయి("%d\n", a >> 3);
    రాయి("%d\n", b >> 3);
    రాయి("%d\n", (గుర్తులేని)b >> 3);
    రాయి("%d\n", a << 4);
    రాయి("%d\n", ~a);
    రాయి("%d\n", -a);
    రాయి("%d\n", +a);

    రాయి("%d\n", 12 + 1);
    రాయి("%d\n", 12 - 2);
    రాయి("%d\n", 12 * 312);
    రాయి("%d\n", 12 / 4);
    రాయి("%d\n", 12 % 20);
    రాయి("%d\n", 12 & 6);
    రాయి("%d\n", 12 ^ 7);
    రాయి("%d\n", 12 | 8);
    రాయి("%d\n", 12 >> 2);
    రాయి("%d\n", 12 << 4);
    రాయి("%d\n", ~12);
    రాయి("%d\n", -12);
    రాయి("%d\n", +12);
    రాయి("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

పూర్ణాంకం isid(పూర్ణాంకం c)
{
    తిరిగి (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

పూర్ణాంకం vstack[10], *vstack_ptr;

శూన్య vpush(పూర్ణాంకం vt, పూర్ణాంకం vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

శూన్య vpop(పూర్ణాంకం *ft, పూర్ణాంకం *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

శూన్య expr2_test()
{
    పూర్ణాంకం a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    రాయి("res= %d %d\n", a, b);
}

పూర్ణాంకం const_len_ar[పరిమాణం(1/0)]; /* div-by-zero, but in unevaluated context */

శూన్య constant_సమాసం_test()
{
    పూర్ణాంకం a;
    a = 3;
    రాయి("%d\n", a * 16);
    రాయి("%d\n", a * 1);
    రాయి("%d\n", a + 0);
    రాయి("%d\n", పరిమాణం(const_len_ar));
}

పూర్ణాంకం tab4[10];

శూన్య సమాసం_ptr_test()
{
    పూర్ణాంకం arr[10], *p, *q;
    పూర్ణాంకం i = -1;

    p = tab4;
    q = tab4 + 10;
    రాయి("diff=%d\n", q - p);
    p++;
    రాయి("inc=%d\n", p - tab4);
    p--;
    రాయి("dec=%d\n", p - tab4);
    ++p;
    రాయి("inc=%d\n", p - tab4);
    --p;
    రాయి("dec=%d\n", p - tab4);
    రాయి("add=%d\n", p + 3 - tab4);
    రాయి("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    రాయి("%p %p %ld\n", q, p, p-q);
    రాయి("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    రాయి("%p %p %ld\n", q, p, p-q);
    రాయి("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (పూర్ణాంకం *)((అక్షరం *)p + 0xf0000000);
    రాయి("%p %p %ld\n", q, p, p-q);
    రాయి("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    రాయి("%p %p %ld\n", q, p, p-q);
    రాయి("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        నిర్మాణం size12 {
            పూర్ణాంకం i, j, k;
        };
        నిర్మాణం size12 s[2], *sp = s;
        పూర్ణాంకం i, j;
        sp->i = 42;
        sp++;
        j = -1;
        రాయి("%d\n", sp[j].i);
    }
#నిర్వచితమైతే __LP64__
    i = 1;
    p = (పూర్ణాంకం*)0x100000000UL + i;
    i = ((దీర్ఘ)p) >> 32;
    రాయి("largeptr: %p %d\n", p, i);
#అయితే_ముగింపు
    p = &arr[0];
    q = p + 3;
    రాయి ("%d\n", (పూర్ణాంకం)((p - q) / 3));
}

శూన్య సమాసం_cmp_test()
{
    పూర్ణాంకం a, b;
    a = -1;
    b = 1;
    రాయి("%d\n", a == a);
    రాయి("%d\n", a != a);

    రాయి("%d\n", a < b);
    రాయి("%d\n", a <= b);
    రాయి("%d\n", a <= a);
    రాయి("%d\n", b >= a);
    రాయి("%d\n", a >= a);
    రాయి("%d\n", b > a);

    రాయి("%d\n", (గుర్తులేని)a < b);
    రాయి("%d\n", (గుర్తులేని)a <= b);
    రాయి("%d\n", (గుర్తులేని)a <= a);
    రాయి("%d\n", (గుర్తులేని)b >= a);
    రాయి("%d\n", (గుర్తులేని)a >= a);
    రాయి("%d\n", (గుర్తులేని)b > a);
}

నిర్మాణం ఖాళీలు {
};

నిర్మాణం aligntest1 {
    అక్షరం a[10];
};

నిర్మాణం aligntest2 {
    పూర్ణాంకం a;
    అక్షరం b[10];
};

నిర్మాణం aligntest3 {
    ద్విగుణ a, b;
};

నిర్మాణం aligntest4 {
    ద్విగుణ a[0];
};

నిర్మాణం __attribute__((aligned(16))) aligntest5
{
    పూర్ణాంకం i;
};
నిర్మాణం aligntest6
{
    పూర్ణాంకం i;
} __attribute__((aligned(16)));
నిర్మాణం aligntest7
{
    పూర్ణాంకం i;
};
నిర్మాణం aligntest5 altest5[2];
నిర్మాణం aligntest6 altest6[2];
పూర్ణాంకం pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
నిర్మాణం aligntest7 altest7[2] __attribute__((aligned(16)));

నిర్మాణం aligntest8
{
  పూర్ణాంకం i;
} __attribute__((aligned(4096)));

నిర్మాణం Large {
    గుర్తులేని దీర్ఘ flags;
    సంఘం {
	శూన్య *u1;
	పూర్ణాంకం *u2;
    };

    నిర్మాణం {
	సంఘం {
	    గుర్తులేని దీర్ఘ సూచీ;
	    శూన్య *freelist;
	};
	సంఘం {
	    గుర్తులేని దీర్ఘ counters;
	    నిర్మాణం {
		పూర్ణాంకం bla;
	    };
	};
    };

    సంఘం {
	నిర్మాణం {
	    దీర్ఘ u3;
	    దీర్ఘ u4;
	};
	శూన్య *u5;
	నిర్మాణం {
	    గుర్తులేని దీర్ఘ compound_తల;
	    గుర్తులేని పూర్ణాంకం compound_dtor;
	    గుర్తులేని పూర్ణాంకం compound_క్రమం;
	};
    };
} __attribute__((aligned(2 * పరిమాణం(దీర్ఘ))));

రకనిర్వచనం గుర్తులేని దీర్ఘ దీర్ఘ __attribute__((aligned(4))) unaligned_u64;

నిర్మాణం aligntest9 {
    గుర్తులేని పూర్ణాంకం buf_nr;
    unaligned_u64 ప్రారంభం_lba;
};

నిర్మాణం aligntest10 {
    గుర్తులేని పూర్ణాంకం buf_nr;
    గుర్తులేని దీర్ఘ దీర్ఘ ప్రారంభం_lba;
};

శూన్య struct_test()
{
    struct1 *s;
    సంఘం union2 u;
    నిర్మాణం Large ls;

    రాయి("sizes: %d %d %d %d\n",
           పరిమాణం(నిర్మాణం struct1),
           పరిమాణం(నిర్మాణం struct2),
           పరిమాణం(సంఘం union1),
           పరిమాణం(సంఘం union2));
    రాయి("offsets: %d\n", (పూర్ణాంకం)((అక్షరం*)&st1.u.v1 - (అక్షరం*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    రాయి("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    రాయి("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    రాయి("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    రాయి("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    రాయి("str_addr=%x\n", (పూర్ణాంకం)(uintptr_t)st1.str - (పూర్ణాంకం)(uintptr_t)&st1.f1);

    /* align / size tests */
    రాయి("aligntest1 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest1), __alignof__(నిర్మాణం aligntest1));
    రాయి("aligntest2 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest2), __alignof__(నిర్మాణం aligntest2));
    రాయి("aligntest3 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest3), __alignof__(నిర్మాణం aligntest3));
#ఒకవేళ !(defined _WIN32 && CC_NAME == CC_clang)
    రాయి("aligntest4 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest4), __alignof__(నిర్మాణం aligntest4));
#అయితే_ముగింపు
    రాయి("aligntest5 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest5), __alignof__(నిర్మాణం aligntest5));
    రాయి("aligntest6 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest6), __alignof__(నిర్మాణం aligntest6));
    రాయి("aligntest7 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest7), __alignof__(నిర్మాణం aligntest7));
    రాయి("aligntest8 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest8), __alignof__(నిర్మాణం aligntest8));
#ఒకవేళ !(defined _WIN32 && CC_NAME == CC_clang)
    రాయి("aligntest9 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest9), __alignof__(నిర్మాణం aligntest9));
#అయితే_ముగింపు
    రాయి("aligntest10 sizeof=%d alignof=%d\n",
           పరిమాణం(నిర్మాణం aligntest10), __alignof__(నిర్మాణం aligntest10));
    రాయి("altest5 sizeof=%d alignof=%d\n",
           పరిమాణం(altest5), __alignof__(altest5));
    రాయి("altest6 sizeof=%d alignof=%d\n",
           పరిమాణం(altest6), __alignof__(altest6));
    రాయి("altest7 sizeof=%d alignof=%d\n",
           పరిమాణం(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ఒకవేళ !(defined _WIN32 && CC_NAME == CC_clang)
    రాయి("sizeof(struct empty) = %d\n", పరిమాణం(నిర్మాణం ఖాళీలు));
#అయితే_ముగింపు
    రాయి("alignof(struct empty) = %d\n", __alignof__(నిర్మాణం ఖాళీలు));

    రాయి("Large: sizeof=%d\n", పరిమాణం(ls));
    memset(&ls, 0, పరిమాణం(ls));
    ls.compound_తల = 42;
    రాయి("Large: offsetof(compound_head)=%d\n", (పూర్ణాంకం)((అక్షరం*)&ls.compound_తల - (అక్షరం*)&ls));
}

/* simulate char/short return value with undefined upper bits */
స్థిర పూర్ణాంకం __csf(పూర్ణాంకం x) { తిరిగి x; }
స్థిర శూన్య *_csf = __csf;
#నిర్వచించు csf(t,n) ((t(*)(పూర్ణాంకం))_csf)(n)

/* XXX: depend on endianness */
శూన్య char_short_test()
{
    పూర్ణాంకం var1, var2;
    గుర్తుగల అక్షరం var3;
    దీర్ఘ దీర్ఘ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    రాయి("s8=%d %d\n", 
           *(గుర్తుగల అక్షరం *)&var1, *(గుర్తుగల అక్షరం *)&var2);
    రాయి("u8=%d %d\n", 
           *(గుర్తులేని అక్షరం *)&var1, *(గుర్తులేని అక్షరం *)&var2);
    రాయి("s16=%d %d\n", 
           *(పొట్టి *)&var1, *(పొట్టి *)&var2);
    రాయి("u16=%d %d\n", 
           *(గుర్తులేని పొట్టి *)&var1, *(గుర్తులేని పొట్టి *)&var2);
    రాయి("s32=%d %d\n", 
           *(పూర్ణాంకం *)&var1, *(పూర్ణాంకం *)&var2);
    రాయి("u32=%d %d\n", 
           *(గుర్తులేని పూర్ణాంకం *)&var1, *(గుర్తులేని పూర్ణాంకం *)&var2);
    *(గుర్తుగల అక్షరం *)&var1 = 0x08;
    రాయి("var1=%x\n", var1);
    *(పొట్టి *)&var1 = 0x0809;
    రాయి("var1=%x\n", var1);
    *(పూర్ణాంకం *)&var1 = 0x08090a0b;
    రాయి("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    రాయి("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    రాయి("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    రాయి("promote char/short cast VA %d %d\n", (గుర్తుగల అక్షరం)(var1 + 1), (గుర్తుగల అక్షరం)(var4 + 1));
#ఒకవేళ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(గుర్తులేని అక్షరం,0x89898989);
    var4 = csf(గుర్తుగల అక్షరం,0xabababab);
#నిర్వచితమైతే __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#అయితే_ముగింపు
    రాయి("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    రాయి("promote char/short fumcret VA %d %d %d %d\n",
        csf(గుర్తులేని పొట్టి,0xcdcdcdcd),
        csf(పొట్టి,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#అయితే_ముగింపు
    var3 = -10;
    var1 = (గుర్తుగల అక్షరం)(గుర్తులేని అక్షరం)(var3 + 1);
    var4 = (గుర్తుగల అక్షరం)(గుర్తులేని అక్షరం)(var3 + 1);
    రాయి("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (గుర్తులేని)(పూర్ణాంకం)(var4 + 1);
    రాయి("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (గుర్తులేని)(గుర్తుగల అక్షరం)(var4 + 1);
    రాయి("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

రకనిర్వచనం నిర్మాణం Sym {
    పూర్ణాంకం v;
    పూర్ణాంకం t;
    పూర్ణాంకం c;
    నిర్మాణం Sym *తదుపరి;
    నిర్మాణం Sym *prev;
} Sym;

#నిర్వచించు ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#నిర్వచించు TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

స్థిర పూర్ణాంకం toupper1(పూర్ణాంకం a)
{
    తిరిగి TOUPPER(a);
}

స్థిర గుర్తులేని పూర్ణాంకం calc_vm_flags(గుర్తులేని పూర్ణాంకం prot)
{
  గుర్తులేని పూర్ణాంకం prot_బిట్లు;
  /* This used to segfault in some revisions: */
  prot_బిట్లు = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  తిరిగి prot_బిట్లు;
}

గణన cast_enum { మొదటి_2, చివరి_2 };

స్థిర శూన్య tst_cast(గణన cast_enum ce)
{
    రాయి("%d\n", ce);
}

శూన్య bool_test()
{
    పూర్ణాంకం *s, a, b, t, f, i;

    a = 0;
    s = (శూన్య*)0;
    రాయి("!s=%d\n", !s);

    ఒకవేళ (!s || !s[0])
        a = 1;
    రాయి("a=%d\n", a);

    రాయి("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    రాయి("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    రాయి("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ఒకవేళ 1 && 1
    రాయి("a1\n");
#అయితే_ముగింపు
#ఒకవేళ 1 || 0
    రాయి("a2\n");
#అయితే_ముగింపు
#ఒకవేళ 1 ? 0 : 1
    రాయి("a3\n");
#అయితే_ముగింపు
#ఒకవేళ 0 ? 0 : 1
    రాయి("a4\n");
#అయితే_ముగింపు

    a = 4;
    రాయి("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    రాయి("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    రాయి("exp=%d\n", f == (32 <= a && a <= 3));
    రాయి("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    రాయి("type of bool: %d\n", (పూర్ణాంకం) ( (~ ((గుర్తులేని పూర్ణాంకం) (t && 1))) / 2) );
    tst_cast(t >= 0 ? మొదటి_2 : చివరి_2);

    రాయి("type of cond: %d\n", (~(t ? 0U : (గుర్తులేని పూర్ణాంకం)0)) / 2 );
    /* test ? : cast */
    {
        పూర్ణాంకం aspect_on;
        పూర్ణాంకం aspect_native = 65536;
        ద్విగుణ bfu_aspect = 1.0;
        పూర్ణాంకం aspect;
        కొరకు(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            రాయి("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        స్థిర పూర్ణాంకం v1 = 34 ? : -1; /* constant case */
        స్థిర పూర్ణాంకం v2 = 0 ? : -1; /* constant case */
        పూర్ణాంకం a = 30;
        
        రాయి("%d %d\n", v1, v2);
        రాయి("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    కొరకు(i=0;i<256;i++) {
        ఒకవేళ (toupper1 (i) != TOUPPER (i))
            రాయి("error %d\n", i);
    }
    రాయి ("bits = 0x%x\n", calc_vm_flags (0x1));
}

బాహ్య పూర్ణాంకం undefined_function(శూన్య);
బాహ్య పూర్ణాంకం defined_function(శూన్య);

#నిర్వచితమైతే __clang__
పూర్ణాంకం undefined_function(శూన్య) {}
#అయితే_ముగింపు

స్థిర అంతఃవరుస శూన్య refer_గమ్యం_undefined(శూన్య)
{
  undefined_function();
}

శూన్య optimize_బహిర్గతం_test(శూన్య)
{
  పూర్ణాంకం i = 0 ? undefined_function() : defined_function();
  రాయి ("oo:%d\n", i);
  పూర్ణాంకం j = 1 ? defined_function() : undefined_function();
  రాయి ("oo:%d\n", j);
  ఒకవేళ (0)
    రాయి("oo:%d\n", undefined_function());
  లేకపోతే
    రాయి("oo:%d\n", defined_function());
  ఒకవేళ (1)
    రాయి("oo:%d\n", defined_function());
  లేకపోతే
    రాయి("oo:%d\n", undefined_function());
  అయితే (1) {
      రాయి("oow:%d\n", defined_function());
      ఆపు;
      రాయి("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ఎంపిక (j)
    స్థితి 1: ఆపు;
  రాయి ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  అయితే (1)
    ఆపు;
  రాయి ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  చేయి
    ఆపు;
  అయితే (1);
  రాయి ("ool2:%d\n", defined_function());
  కొరకు (;;)
    ఆపు;
  రాయి ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  అయితే (1) {
	{
	  ఆపు;
	}
      రాయి ("ool4:%d\n", undefined_function());
  }
  j = 1;
  అయితే (j) {
      ఒకవేళ (j == 0)
	ఆపు; /* this break shouldn't disable code outside the if. */
      రాయి("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  అయితే (j) {
      ఒకవేళ (1)
	j--;
      లేకపోతే
	breakhere: ఆపు;
      రాయి("ool6:%d\n", defined_function());
      వెళ్ళు breakhere;
  }
  j = 1;
  అయితే (j) {
      j--;
      కొనసాగు;
      రాయి("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ఒకవేళ (0 && undefined_function())
    undefined_function();
  ఒకవేళ (defined_function() && 0)
    undefined_function();
  ఒకవేళ (0 && 0)
    undefined_function();
  ఒకవేళ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ఒకవేళ (1 || undefined_function())
    ;
  లేకపోతే
    undefined_function();
  ఒకవేళ (defined_function() || 1)
    ;
  లేకపోతే
    undefined_function();
  ఒకవేళ (1 || 1)
    ;
  లేకపోతే
    undefined_function();
  ఒకవేళ (defined_function() || 1 || undefined_function())
    ;
  లేకపోతే
    undefined_function();

  ఒకవేళ (defined_function() && 0)
    refer_గమ్యం_undefined();

  ఒకవేళ (0) {
      (శూన్య)పరిమాణం( ({
		     చేయి { } అయితే (0);
		     0;
		     }) );
      undefined_function();
  }

  ఒకవేళ (0) {
      ఎంపిక (defined_function()) {
          స్థితి 0: undefined_function(); ఆపు;
          అప్రమేయ: undefined_function(); ఆపు;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ఒకవేళ (1)
    తిరిగి;
  రాయి ("oor:%d\n", undefined_function());
}

పూర్ణాంకం defined_function(శూన్య)
{
  స్థిర పూర్ణాంకం i = 40;
  తిరిగి i++;
}

/* GCC accepts that */
స్థిర పూర్ణాంకం tab_reinit[];
స్థిర పూర్ణాంకం tab_reinit[10];

స్థిర పూర్ణాంకం tentative_ar[];
స్థిర పూర్ణాంకం tentative_ar[] = {1,2,3};

పూర్ణాంకం cinit1; /* a global variable can be defined several times without error ! */
పూర్ణాంకం cinit1; 
పూర్ణాంకం cinit1 = 0;
పూర్ణాంకం *cinit2 = (పూర్ణాంకం []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
అక్షరం స్థిరరాశి * స్థిరరాశి cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
శూన్య *cinit52 = &(శూన్య*){ (శూన్య*) 52 };

#ఒకవేళ __TINYC__ || __GNUC__ >= 6
పూర్ణాంకం cinit4 = (పూర్ణాంకం){44};
శూన్య *cinit51 = (శూన్య*){ (శూన్య*) 51 };
నిర్మాణం _c6 { పూర్ణాంకం a,b; } cinit6 = (నిర్మాణం _c6){61,62}, *cinit7 = &(నిర్మాణం _c6){71,72};
#లేకపోతే
పూర్ణాంకం cinit4 = 44;
శూన్య *cinit51 = (శూన్య*)51;
నిర్మాణం _c6 { పూర్ణాంకం a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#అయితే_ముగింపు

శూన్య compound_literal_test(శూన్య)
{
    పూర్ణాంకం *p, i;
    అక్షరం *q, *q3;

    రాయి("cinit3 : %s\n", cinit3);
    రాయి("cinit4 : %d\n", cinit4);
    రాయి("cinit51 : %d\n", (పూర్ణాంకం)cinit51);
    రాయి("cinit52 : %d\n", *(పూర్ణాంకం*)cinit52);
    రాయి("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    రాయి("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    రాయి("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (పూర్ణాంకం []){1, 2, 3};
    కొరకు(i=0;i<3;i++)
        రాయి(" %d", p[i]);
    రాయి("\n");

    కొరకు(i=0;i<3;i++)
        రాయి("%d", cinit2[i]);
    రాయి("\n");

    q = "tralala1";
    రాయి("q1=%s\n", q);

    q = (అక్షరం *){ "tralala2" };
    రాయి("q2=%s\n", q);

    q3 = (అక్షరం *){ q };
    రాయి("q3=%s\n", q3);

    q = (అక్షరం []){ "tralala3" };
    రాయి("q4=%s\n", q);

#నిర్వచితమైతే ALL_ISOC99
    p = (పూర్ణాంకం []){1, 2, cinit1 + 3};
    కొరకు(i=0;i<3;i++)
        రాయి(" %d", p[i]);
    రాయి("\n");

    కొరకు(i=0;i<3;i++) {
        p = (పూర్ణాంకం []){1, 2, 4 + i};
        రాయి("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#అయితే_ముగింపు
}


#ఒకవేళ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    తిరిగి a + b;
}

పూర్ణాంకం kr_func2(a, b)
{
    తిరిగి a + b;
}

kr_test()
{
    రాయి("func1=%d\n", kr_func1(3, 4));
    రాయి("func2=%d\n", kr_func2(3, 4));
    తిరిగి 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
అక్షరం invalid_function_def()[] {తిరిగి 0;}

#లేకపోతే
# define kr_test() రాయి("func1=7\nfunc2=7\n")
#అయితే_ముగింపు

శూన్య అంకె(పూర్ణాంకం n)
{
    అక్షరం *tab, *p;
    tab = (అక్షరం*)జ్ఞాపకం_ఇవ్వు(20); 
    p = tab;
    అయితే (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ఒకవేళ (n == 0)
            ఆపు;
    }
    అయితే (p != tab) {
        p--;
        రాయి("%c", *p);
    }
    రాయి("\n");
    విడుదల(tab);
}

/* structure assignment tests */
నిర్మాణం structa1 {
    పూర్ణాంకం f1;
    అక్షరం f2;
};

శూన్య struct_కేటాయించు_test1(నిర్మాణం structa1 s1, పూర్ణాంకం t, దశాంశం f)
{
    రాయి("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

నిర్మాణం structa1 struct_కేటాయించు_test2(నిర్మాణం structa1 s1, పూర్ణాంకం t)
{
    s1.f1 += t;
    s1.f2 -= t;
    తిరిగి s1;
}

శూన్య struct_కేటాయించు_test(శూన్య)
{
    నిర్మాణం S {
      నిర్మాణం structa1 lsta1, lsta2;
      పూర్ణాంకం i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_కేటాయించు_test1(ps->lsta2, 3, 4.5);
    రాయి("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_కేటాయించు_test2(ps->lsta2, ps->i);
    రాయి("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    స్థిర నిర్మాణం {
        శూన్య (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_కేటాయించు_test }
    };
    రాయి("%d\n", struct_కేటాయించు_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_కేటాయించు_test2(s.lsta1, 1);
    రాయి("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

శూన్య cast1(అక్షరం a, పొట్టి b, గుర్తులేని అక్షరం c, గుర్తులేని పొట్టి d)
{
    రాయి("%d %d %d %d\n", a, b, c, d);
}

అక్షరం bcast;
పొట్టి scast;

శూన్య cast_test()
{
    పూర్ణాంకం a;
    అక్షరం c;
    అక్షరం tab[10];
    గుర్తులేని b,d;
    పొట్టి s;
    అక్షరం *p = ఖాళీ;
    గుర్తులేని దీర్ఘ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    రాయి("%d %d %d %d\n",
           (అక్షరం)(a + 1),
           (పొట్టి)(a + 1),
           (గుర్తులేని అక్షరం)(a + 1),
           (గుర్తులేని పొట్టి)(a + 1));
    రాయి("%d %d %d %d\n",
           (అక్షరం)0xfffff,
           (పొట్టి)0xfffff,
           (గుర్తులేని అక్షరం)0xfffff,
           (గుర్తులేని పొట్టి)0xfffff);

    a = (bcast = 128) + 1;
    రాయి("%d\n", a);
    a = (scast = 65536) + 1;
    రాయి("%d\n", a);
    
    రాయి("sizeof(c) = %d, sizeof((int)c) = %d\n", పరిమాణం(c), పరిమాణం((పూర్ణాంకం)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (పొట్టి)b;
    రాయి("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (అక్షరం)b;
    రాయి("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    రాయి("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    రాయి("sizeof(+(char)'a') = %d\n", పరిమాణం(+(అక్షరం)'a'));
    రాయి("sizeof(-(char)'a') = %d\n", పరిమాణం(-(అక్షరం)'a'));
    రాయి("sizeof(~(char)'a') = %d\n", పరిమాణం(-(అక్షరం)'a'));

#ఒకవేళ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    రాయి("%d %d %ld %ld %lld %lld\n",
           (పూర్ణాంకం)p, (గుర్తులేని పూర్ణాంకం)p,
           (దీర్ఘ)p, (గుర్తులేని దీర్ఘ)p,
           (దీర్ఘ దీర్ఘ)p, (గుర్తులేని దీర్ఘ దీర్ఘ)p);
#అయితే_ముగింపు

    /* from integers to pointers */
    రాయి("%p %p %p %p\n",
           (శూన్య *)a, (శూన్య *)b, (శూన్య *)c, (శూన్య *)d);

    /* int to int with sign set */
    రాయి("0x%lx\n", (గుర్తులేని దీర్ఘ)(పూర్ణాంకం)ul);
}

/* initializers tests */
నిర్మాణం structinit1 {
    పూర్ణాంకం f1;
    అక్షరం f2;
    పొట్టి f3;
    పూర్ణాంకం farray[3];
};

పూర్ణాంకం sinit1 = 2;
పూర్ణాంకం sinit2 = { 3 };
పూర్ణాంకం sinit3[3] = { 1, 2, {3}, };
పూర్ణాంకం sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
పూర్ణాంకం sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
పూర్ణాంకం sinit6[] = { 1, 2, 3 };
పూర్ణాంకం sinit7[] = { [2] = 3, [0] = 1, 2 };
అక్షరం sinit8[] = "hello" "trala";

నిర్మాణం structinit1 sinit9 = { 1, 2, 3 };
నిర్మాణం structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
నిర్మాణం structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#నిర్వచితమైతే ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#అయితే_ముగింపు
};

అక్షరం *sinit12 = "hello world";
అక్షరం *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
అక్షరం sinit14[10] = { "abc" };
పూర్ణాంకం sinit15[3] = { పరిమాణం(sinit15), 1, 2 };

నిర్మాణం { పూర్ణాంకం a[3], b; } sinit16[] = { { 1 }, 2 };

నిర్మాణం bar {
        అక్షరం *s;
        పూర్ణాంకం len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

పూర్ణాంకం sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

నిర్మాణం complexinit0 {
    పూర్ణాంకం a;
    పూర్ణాంకం b;
};

నిర్మాణం complexinit {
    పూర్ణాంకం a;
    స్థిరరాశి నిర్మాణం complexinit0 *b;
};

స్థిరరాశి స్థిర నిర్మాణం complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (స్థిరరాశి నిర్మాణం complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

నిర్మాణం complexinit2 {
	పూర్ణాంకం a;
	పూర్ణాంకం b[];
};

నిర్మాణం complexinit2 cix20;

నిర్మాణం complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

నిర్మాణం complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

రకనిర్వచనం పూర్ణాంకం arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
రకనిర్వచనం పూర్ణాంకం arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
పూర్ణాంకం sinit23[2] = { "astring" ? పరిమాణం("astring") : -1,
		   &sinit23 ? 42 : -1 };

పూర్ణాంకం sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
నిర్మాణం bf_SS {గుర్తులేని పూర్ణాంకం బిట్టు:1,bits31:31; };
నిర్మాణం bf_SS bf_init = { .బిట్టు = 1 };
నిర్మాణం bfn_SS {పూర్ణాంకం a,b; నిర్మాణం bf_SS c; పూర్ణాంకం d,e; };
నిర్మాణం bfn_SS bfn_init = { .c.బిట్టు = 1 };
నిర్మాణం bfa_SS {పూర్ణాంకం a,b; నిర్మాణం bf_SS c[3]; పూర్ణాంకం d,e; };
నిర్మాణం bfa_SS bfa_init = { .c[1].బిట్టు = 1 };
నిర్మాణం bf_SS bfaa_init[3] = { [1].బిట్టు = 1 };
నిర్మాణం bf_SS bfaa_vinit[] = { [2].బిట్టు = 1 };
నిర్మాణం b2_SS {దీర్ఘ దీర్ఘ పూర్ణాంకం క్షేత్రం : 52; దీర్ఘ దీర్ఘ పూర్ణాంకం pad : 12; };
నిర్మాణం b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

బాహ్య పూర్ణాంకం external_inited = 42;

శూన్య init_test(శూన్య)
{
    పూర్ణాంకం linit1 = 2;
    పూర్ణాంకం linit2 = { 3 };
    పూర్ణాంకం linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    పూర్ణాంకం linit6[] = { 1, 2, 3 };
    పూర్ణాంకం i, j;
    అక్షరం linit8[] = "hello" "trala";
    పూర్ణాంకం linit12[10] = { 1, 2 };
    పూర్ణాంకం linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    అక్షరం linit14[10] = "abc";
    పూర్ణాంకం linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    నిర్మాణం linit16 { పూర్ణాంకం a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    పూర్ణాంకం linit17 = పరిమాణం(linit17);
    పూర్ణాంకం zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    పూర్ణాంకం linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    నిర్మాణం bf_SS bf_finit = { .బిట్టు = 1 };
    నిర్మాణం bfn_SS bfn_finit = { .c.బిట్టు = 1 };
    నిర్మాణం bfa_SS bfa_finit = { .c[1].బిట్టు = 1 };
    నిర్మాణం bf_SS bfaa_finit[3] = { [1].బిట్టు = 1 };
    నిర్మాణం bf_SS bfaa_fvinit[] = { [2].బిట్టు = 1 };
    నిర్మాణం b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    రాయి("sinit1=%d\n", sinit1);
    రాయి("sinit2=%d\n", sinit2);
    రాయి("sinit3=%d %d %d %d\n", 
           పరిమాణం(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    రాయి("sinit6=%d\n", పరిమాణం(sinit6));
    రాయి("sinit7=%d %d %d %d\n", 
           పరిమాణం(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    రాయి("sinit8=%s\n", sinit8);
    రాయి("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    రాయి("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    రాయి("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    కొరకు(i=0;i<3;i++)
        కొరకు(j=0;j<2;j++)
            రాయి("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    రాయి("linit1=%d\n", linit1);
    రాయి("linit2=%d\n", linit2);
    రాయి("linit6=%d\n", పరిమాణం(linit6));
    రాయి("linit8=%d %s\n", పరిమాణం(linit8), linit8);

    రాయి("sinit12=%s\n", sinit12);
    రాయి("sinit13=%d %s %s %s\n",
           పరిమాణం(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    రాయి("sinit14=%s\n", sinit14);

    కొరకు(i=0;i<10;i++) రాయి(" %d", linit12[i]);
    రాయి("\n");
    కొరకు(i=0;i<10;i++) రాయి(" %d", linit13[i]);
    రాయి("\n");
    కొరకు(i=0;i<10;i++) రాయి(" %d", linit14[i]);
    రాయి("\n");
    కొరకు(i=0;i<10;i++) రాయి(" %d", linit15[i]);
    రాయి("\n");
    రాయి("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    రాయి("linit17=%d\n", linit17);
    రాయి("sinit15=%d\n", sinit15[0]);
    రాయి("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    రాయి("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    కొరకు(i=0;i<10;i++)
        రాయి("%x ", sinit18[i]);
    రాయి("\n");
    /* complex init check */
    రాయి("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    రాయి("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    రాయి("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", పరిమాణం cix20, పరిమాణం cix21, పరిమాణం cix22);

    రాయి("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    రాయి("arrtype2: %d %d\n", పరిమాణం(sinit19), పరిమాణం(sinit20));
    రాయి("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    రాయి("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    రాయి("arrtype5: %d %d\n", పరిమాణం(sinit21), పరిమాణం(sinit22));
    రాయి("arrtype6: %d\n", పరిమాణం(arrtype2));

    రాయి("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    రాయి("sinit24=%d\n", sinit24);
    రాయి("linit18= %d %d\n", linit18[0], linit18[1]);
    రాయి ("bf1: %u %u\n", bf_init.బిట్టు, bf_init.bits31);
    రాయి ("bf2: %u %u\n", bf_finit.బిట్టు, bf_finit.bits31);
    రాయి ("bf3: %u %u\n", bfn_init.c.బిట్టు, bfn_init.c.bits31);
    రాయి ("bf4: %u %u\n", bfn_finit.c.బిట్టు, bfn_finit.c.bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf5[%d]: %u %u\n", i, bfa_init.c[i].బిట్టు, bfa_init.c[i].bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].బిట్టు, bfa_finit.c[i].bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf7[%d]: %u %u\n", i, bfaa_init[i].బిట్టు, bfaa_init[i].bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf8[%d]: %u %u\n", i, bfaa_finit[i].బిట్టు, bfaa_finit[i].bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].బిట్టు, bfaa_vinit[i].bits31);
    కొరకు (i = 0; i < 3; i++)
        రాయి ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].బిట్టు, bfaa_fvinit[i].bits31);
}

శూన్య switch_uc(గుర్తులేని అక్షరం uc)
{
	ఎంపిక (uc) {
	    స్థితి 0xfb ... 0xfe:
		రాయి("ucsw:1\n");
		ఆపు;
	    స్థితి 0xff:
		రాయి("ucsw:2\n");
		ఆపు;
	    స్థితి 0 ... 5:
		రాయి("ucsw:3\n");
		ఆపు;
	    అప్రమేయ:
		రాయి("ucsw: broken!\n");
	}
}

శూన్య switch_sc(గుర్తుగల అక్షరం sc)
{
	ఎంపిక (sc) {
	    స్థితి -5 ... -2:
		రాయి("scsw:1\n");
		ఆపు;
	    స్థితి -1:
		రాయి("scsw:2\n");
		ఆపు;
	    స్థితి 0 ... 5:
		రాయి("scsw:3\n");
		ఆపు;
	    అప్రమేయ:
		రాయి("scsw: broken!\n");
	}
}

శూన్య switch_test()
{
    పూర్ణాంకం i;
    గుర్తులేని దీర్ఘ దీర్ఘ ull;
    దీర్ఘ దీర్ఘ ll;

    కొరకు(i=0;i<15;i++) {
        ఎంపిక(i) {
        స్థితి 0:
        స్థితి 1:
            రాయి("a");
            ఆపు;
        అప్రమేయ:
            రాయి("%d", i);
            ఆపు;
        స్థితి 8 ... 12:
            రాయి("c");
            ఆపు;
        స్థితి 3:
            రాయి("b");
            ఆపు;
        స్థితి 0xc33c6b9fU:
        స్థితి 0x7c9eeeb9U:
            ఆపు;
        }
    }
    రాయి("\n");

    కొరకు (i = 1; i <= 5; i++) {
	ull = (గుర్తులేని దీర్ఘ దీర్ఘ)i << 61;
	ఎంపిక (ull) {
	    స్థితి 1ULL << 61:
		రాయి("ullsw:1\n");
		ఆపు;
	    స్థితి 2ULL << 61:
		రాయి("ullsw:2\n");
		ఆపు;
	    స్థితి 3ULL << 61:
		రాయి("ullsw:3\n");
		ఆపు;
	    స్థితి 4ULL << 61:
		రాయి("ullsw:4\n");
		ఆపు;
	    స్థితి 5ULL << 61:
		రాయి("ullsw:5\n");
		ఆపు;
	    అప్రమేయ:
		రాయి("ullsw: broken!\n");
	}
    }

    కొరకు (i = 1; i <= 5; i++) {
	ll = (దీర్ఘ దీర్ఘ)i << 61;
	ఎంపిక (ll) {
	    స్థితి 1LL << 61:
		రాయి("llsw:1\n");
		ఆపు;
	    స్థితి 2LL << 61:
		రాయి("llsw:2\n");
		ఆపు;
	    స్థితి 3LL << 61:
		రాయి("llsw:3\n");
		ఆపు;
	    స్థితి 4LL << 61:
		రాయి("llsw:4\n");
		ఆపు;
	    స్థితి 5LL << 61:
		రాయి("llsw:5\n");
		ఆపు;
	    అప్రమేయ:
		రాయి("llsw: broken!\n");
	}
    }

    కొరకు (i = -5; i <= 5; i++) {
	switch_uc((గుర్తులేని అక్షరం)i);
    }

    కొరకు (i = -5; i <= 5; i++) {
	switch_sc ((గుర్తుగల అక్షరం)i);
    }
}

/* ISOC99 _Bool type */
శూన్య c99_bool_test(శూన్య)
{
#నిర్వచితమైతే BOOL_ISOC99
    పూర్ణాంకం a;
    _Bool b, b2;

    రాయి("sizeof(_Bool) = %d\n", పరిమాణం(_Bool));
    a = 3;
    రాయి("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    రాయి("b = %d\n", b);
    b++;
    రాయి("b = %d\n", b);
    b2 = 0;
    రాయి("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           పరిమాణం ((అస్థిర పూర్ణాంకం)a ? b : b2));
#అయితే_ముగింపు
}

శూన్య bitfield_test(శూన్య)
{
    పూర్ణాంకం a;
    పొట్టి sa;
    గుర్తులేని అక్షరం ca;
    నిర్మాణం sbf1 {
        పూర్ణాంకం f1 : 3;
        పూర్ణాంకం : 2;
        పూర్ణాంకం f2 : 1;
        పూర్ణాంకం : 0;
        పూర్ణాంకం f3 : 5;
        పూర్ణాంకం f4 : 7;
        గుర్తులేని పూర్ణాంకం f5 : 7;
    } st1;
    రాయి("sizeof(st1) = %d\n", పరిమాణం(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    రాయి("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    రాయి("%d %d\n", sa, ca);

    st1.f1 = 7;
    ఒకవేళ (st1.f1 == -1) 
        రాయి("st1.f1 == -1\n");
    లేకపోతే 
        రాయి("st1.f1 != -1\n");
    ఒకవేళ (st1.f2 == -1) 
        రాయి("st1.f2 == -1\n");
    లేకపోతే 
        రాయి("st1.f2 != -1\n");

    నిర్మాణం sbf2 {
        దీర్ఘ దీర్ఘ f1 : 45;
        దీర్ఘ దీర్ఘ : 2;
        దీర్ఘ దీర్ఘ f2 : 35;
        గుర్తులేని దీర్ఘ దీర్ఘ f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (దీర్ఘ దీర్ఘ)a << 25;
    st2.f3 = a;
    st2.f2++;
    రాయి("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#ఒకవేళ 0
    Disabled కొరకు now until further clarification re GCC compatibility
    నిర్మాణం sbf3 {
        పూర్ణాంకం f1 : 7;
        పూర్ణాంకం f2 : 1;
        అక్షరం f3;
        పూర్ణాంకం f4 : 8;
        పూర్ణాంకం f5 : 1;
        పూర్ణాంకం f6 : 16;
    } st3;
    రాయి("sizeof(st3) = %d\n", పరిమాణం(st3));
#అయితే_ముగింపు

    నిర్మాణం sbf4 {
	పూర్ణాంకం x : 31;
	అక్షరం y : 2;
    } st4;
    st4.y = 1;
    రాయి("st4.y == %d\n", st4.y);
    నిర్మాణం sbf5 {
	పూర్ణాంకం a;
	అక్షరం b;
	పూర్ణాంకం x : 12, y : 4, : 0, : 4, z : 3;
	అక్షరం c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    రాయి("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    నిర్మాణం sbf6 {
	పొట్టి x : 12;
	గుర్తులేని అక్షరం y : 2;
    } st6;
    st6.y = 1;
    రాయి("st6.y == %d\n", st6.y);
}

#నిర్వచితమైతే __x86_64__
#నిర్వచించు FLOAT_FMT "%f\n"
#లేకపోతే
/* x86's float isn't compatible with GCC */
#నిర్వచించు FLOAT_FMT "%.5f\n"
#అయితే_ముగింపు

/* declare strto* functions as they are C99 */
ద్విగుణ strtod(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr);

#ఒకవేళ defined(_WIN32)
దశాంశం strtof(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr) {తిరిగి (దశాంశం)strtod(nptr, endptr);}
LONG_DOUBLE strtold(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr) {తిరిగి (LONG_DOUBLE)strtod(nptr, endptr);}
#లేకపోతే
దశాంశం strtof(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr);
LONG_DOUBLE strtold(స్థిరరాశి అక్షరం *nptr, అక్షరం **endptr);
#అయితే_ముగింపు

#నిర్వచించు FTEST(ఉపసర్గ, typename, type, fmt)\
శూన్య ఉపసర్గ ## cmp(type a, type b)\
{\
    రాయి("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    రాయి(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    రాయి(fmt "\n", ++a);\
    రాయి(fmt "\n", a++);\
    రాయి(fmt "\n", a);\
    b = 0;\
    రాయి("%d %d\n", !a, !b);\
}\
శూన్య ఉపసర్గ ## fcast(type a)\
{\
    దశాంశం fa;\
    ద్విగుణ da;\
    LONG_DOUBLE la;\
    పూర్ణాంకం ia;\
    దీర్ఘ దీర్ఘ llia;\
    గుర్తులేని పూర్ణాంకం ua;\
    గుర్తులేని దీర్ఘ దీర్ఘ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    రాయి("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (పూర్ణాంకం)a;\
    llia = (దీర్ఘ దీర్ఘ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (గుర్తులేని పూర్ణాంకం)a;\
    llua = (గుర్తులేని దీర్ఘ దీర్ఘ)a;\
    రాయి("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    రాయి("itof: " fmt "\n", b);\
    b = ua;\
    రాయి("utof: " fmt "\n", b);\
    b = llia;\
    రాయి("lltof: " fmt "\n", b);\
    b = llua;\
    ఒకవేళ (CC_NAME != CC_clang) రాయి("ulltof: " fmt "\n", b);\
}\
\
దశాంశం ఉపసర్గ ## retf(type a) { తిరిగి a; }\
ద్విగుణ ఉపసర్గ ## retd(type a) { తిరిగి a; }\
LONG_DOUBLE ఉపసర్గ ## retld(type a) { తిరిగి a; }\
\
శూన్య ఉపసర్గ ## call(శూన్య)\
{\
    రాయి("float: " FLOAT_FMT, ఉపసర్గ ## retf(42.123456789));\
    రాయి("double: %f\n", ఉపసర్గ ## retd(42.123456789));\
    రాయి("long double: %Lf\n", ఉపసర్గ ## retld(42.123456789));\
    రాయి("strto%s: %f\n", #prefix, (ద్విగుణ)strto ## ఉపసర్గ("1.2", ఖాళీ));\
}\
\
శూన్య ఉపసర్గ ## signed_zeros(శూన్య) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ఒకవేళ (x == y)\
    రాయి ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  లేకపోతే\
    రాయి ("x != y; this is wrong!\n");\
\
  n = -x;\
  ఒకవేళ (x == n)\
    రాయి ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  లేకపోతే\
    రాయి ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ఒకవేళ (x == p)\
    రాయి ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  లేకపోతే\
    రాయి ("x != +y; this is wrong!\n");\
  p = -y;\
  ఒకవేళ (x == p)\
    రాయి ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  లేకపోతే\
    రాయి ("x != -y; this is wrong!\n");\
}\
శూన్య ఉపసర్గ ## nan(శూన్య)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    రాయి("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
శూన్య ఉపసర్గ ## test(శూన్య)\
{\
    రాయి("testing '%s'\n", #typename);\
    ఉపసర్గ ## cmp(1, 2.5);\
    ఉపసర్గ ## cmp(2, 1.5);\
    ఉపసర్గ ## cmp(1, 1);\
    ఉపసర్గ ## fcast(234.6);\
    ఉపసర్గ ## fcast(-2334.6);\
    ఉపసర్గ ## call();\
    ఉపసర్గ ## signed_zeros();\
    ఒకవేళ (CC_NAME != CC_clang) ఉపసర్గ ## nan();\
}

FTEST(f, దశాంశం, దశాంశం, "%f")
FTEST(d, ద్విగుణ, ద్విగుణ, "%f")
FTEST(ld, దీర్ఘ ద్విగుణ, LONG_DOUBLE, "%Lf")

ద్విగుణ ftab1[3] = { 1.2, 3.4, -5.6 };


శూన్య float_test(శూన్య)
{
#ఒకవేళ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    అస్థిర దశాంశం fa, fb;
    అస్థిర ద్విగుణ da, db;
    పూర్ణాంకం a;
    గుర్తులేని పూర్ణాంకం b;
    స్థిర ద్విగుణ nan2 = 0.0/0.0;
    స్థిర ద్విగుణ inf1 = 1.0/0.0;
    స్థిర ద్విగుణ inf2 = 1e5000;
    అస్థిర LONG_DOUBLE la;

    రాయి("sizeof(float) = %d\n", పరిమాణం(దశాంశం));
    రాయి("sizeof(double) = %d\n", పరిమాణం(ద్విగుణ));
    రాయి("sizeof(long double) = %d\n", పరిమాణం(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    రాయి("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    రాయి("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    రాయి("da=%f\n", da);
    fa = 123;
    రాయి("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    రాయి("da = %f\n", da);
    b = 4000000000;
    db = b;
    రాయి("db = %f\n", db);
    రాయి("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    రాయి ("da subnormal = %a\n", da);
    రాయి ("da subnormal = %.40g\n", da);
    రాయి ("la subnormal = %La\n", la);
    రాయి ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    రాయి ("da/2 subnormal = %a\n", da);
    రాయి ("da/2 subnormal = %.40g\n", da);
    రాయి ("la/2 subnormal = %La\n", la);
    రాయి ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    రాయి ("fa subnormal = %a\n", fa);
    రాయి ("fa subnormal = %.40g\n", fa);
    రాయి ("la subnormal = %La\n", la);
    రాయి ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    రాయి ("fa/2 subnormal = %a\n", fa);
    రాయి ("fa/2 subnormal = %.40g\n", fa);
    రాయి ("la/2 subnormal = %La\n", la);
    రాయి ("la/2 subnormal = %.40Lg\n", la);
#అయితే_ముగింపు
}

పూర్ణాంకం fib(పూర్ణాంకం n)
{
    ఒకవేళ (n <= 2)
        తిరిగి 1;
    లేకపోతే
        తిరిగి fib(n-1) + fib(n-2);
}

#ఒకవేళ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#లేకపోతే
శూన్య __attribute__((aligned(16))) aligned_function(పూర్ణాంకం i) {}
#అయితే_ముగింపు

శూన్య funcptr_test()
{
    శూన్య (*func)(పూర్ణాంకం);
    పూర్ణాంకం a;
    నిర్మాణం {
        పూర్ణాంకం dummy;
        శూన్య (*func)(పూర్ణాంకం);
    } st1;
    దీర్ఘ diff;

    func = &అంకె;
    (*func)(12345);
    func = అంకె;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = అంకె;
    st1.func(12346);
    రాయి("sizeof1 = %d\n", పరిమాణం(funcptr_test));
    రాయి("sizeof2 = %d\n", పరిమాణం funcptr_test);
    రాయి("sizeof3 = %d\n", పరిమాణం(&funcptr_test));
    రాయి("sizeof4 = %d\n", పరిమాణం &funcptr_test);
    a = 0;
    func = అంకె + a;
    diff = func - అంకె;
    func(42);
    (func + diff)(42);
    (అంకె + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    రాయి("aligned_function (should be zero): %d\n", ((పూర్ణాంకం)(uintptr_t)func) & 15);
}

శూన్య lloptest(దీర్ఘ దీర్ఘ a, దీర్ఘ దీర్ఘ b)
{
    గుర్తులేని దీర్ఘ దీర్ఘ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    రాయి("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ఒకవేళ (b != 0) {
        రాయి("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ద్విమాన*/
    రాయి("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    రాయి("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    రాయి("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    రాయి("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    రాయి("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    రాయి("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    రాయి("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    రాయి("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

శూన్య llshift(దీర్ఘ దీర్ఘ a, పూర్ణాంకం b)
{
    రాయి("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (గుర్తులేని దీర్ఘ దీర్ఘ)a >> b,
           a >> b,
           a << b);
    రాయి("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (గుర్తులేని దీర్ఘ దీర్ఘ)a >> 3,
           a >> 3,
           a << 3);
    రాయి("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (గుర్తులేని దీర్ఘ దీర్ఘ)a >> 35,
           a >> 35,
           a << 35);
}

శూన్య llfloat(శూన్య)
{
    దశాంశం fa;
    ద్విగుణ da;
    LONG_DOUBLE lda;
    దీర్ఘ దీర్ఘ la, lb, lc;
    గుర్తులేని దీర్ఘ దీర్ఘ ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    రాయి("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    రాయి("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    రాయి("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    రాయి("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    రాయి("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

దీర్ఘ దీర్ఘ llfunc1(పూర్ణాంకం a)
{
    తిరిగి a * 2;
}

నిర్మాణం S {
    పూర్ణాంకం id; 
    అక్షరం అంశం;
};

దీర్ఘ దీర్ఘ పూర్ణాంకం విలువ(నిర్మాణం S *v)
{
    తిరిగి ((దీర్ఘ దీర్ఘ పూర్ణాంకం)v->అంశం);
}

దీర్ఘ దీర్ఘ llfunc2(దీర్ఘ దీర్ఘ x, దీర్ఘ దీర్ఘ y, పూర్ణాంకం z)
{
    తిరిగి x * y * z;
}

శూన్య check_opl_save_regs(అక్షరం *a, దీర్ఘ దీర్ఘ b, పూర్ణాంకం c)
{
    *a = b < 0 && !c;
}

శూన్య longlong_test(శూన్య)
{
    దీర్ఘ దీర్ఘ a, b, c;
    పూర్ణాంకం ia;
    గుర్తులేని పూర్ణాంకం ua;
    రాయి("sizeof(long long) = %d\n", పరిమాణం(దీర్ఘ దీర్ఘ));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    రాయి(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    రాయి(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (దీర్ఘ దీర్ఘ)1,
           (దీర్ఘ దీర్ఘ)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    రాయి(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#ఒకవేళ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    రాయి(XLONG_LONG_FORMAT"\n", c);
#అయితే_ముగింపు

    /* long long reg spill test */
    {
          నిర్మాణం S a;

          a.అంశం = 3;
          రాయి("%lld\n", విలువ(&a));
    }
    lloptest(0x80000000, 0);

    {
        దీర్ఘ దీర్ఘ *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        రాయి("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        రాయి("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    రాయి("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    రాయి(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    దీర్ఘ దీర్ఘ *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    గుర్తులేని దీర్ఘ దీర్ఘ u = 0x8000000000000001ULL;
    u = (గుర్తులేని)(u + 1);
    రాయి("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (గుర్తులేని)(పూర్ణాంకం)(u + 1);
    రాయి("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    అక్షరం cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    రాయి("check_opl_save_regs: %d\n", cc);
}

శూన్య manyarg_test(శూన్య)
{
    LONG_DOUBLE ld = 1234567891234LL;
    రాయి("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    రాయి("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    రాయి("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    రాయి("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    రాయి("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    రాయి("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

శూన్య*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        నిర్మాణం X { పూర్ణాంకం _x; };
        నిర్మాణం X *x = va_arg(ap, నిర్మాణం X *);
        తిరిగి x;
}

శూన్య vprintf1(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list ap, aq;
    స్థిరరాశి అక్షరం *p;
    పూర్ణాంకం c, i;
    ద్విగుణ d;
    దీర్ఘ దీర్ఘ ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    కొరకు(;;) {
        c = *p;
        ఒకవేళ (c == '\0')
            ఆపు;
        p++;
        ఒకవేళ (c == '%') {
            c = *p;
            ఎంపిక(c) {
            స్థితి '\0':
                వెళ్ళు the_చివర;
            స్థితి 'd':
                i = va_arg(ap, పూర్ణాంకం);
                రాయి("%d", i);
                ఆపు;
            స్థితి 'f':
                d = va_arg(ap, ద్విగుణ);
                రాయి("%f", d);
                ఆపు;
            స్థితి 'l':
                ll = va_arg(ap, దీర్ఘ దీర్ఘ);
                రాయి(LONG_LONG_FORMAT, ll);
                ఆపు;
            స్థితి 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                రాయి("%Lf", ld);
                ఆపు;
            }
            p++;
        } లేకపోతే {
            అక్షరం_రాయి(c);
        }
    }
 the_చివర:
    va_end(aq);
    va_end(ap);
}

నిర్మాణం myspace {
    పొట్టి పూర్ణాంకం profile;
};
నిర్మాణం myspace2 {
#ఒకవేళ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    అక్షరం a[1];
#లేకపోతే
    అక్షరం a[0];
#అయితే_ముగింపు
};
నిర్మాణం myspace3 {
    అక్షరం a[1];
};
నిర్మాణం myspace4 {
    అక్షరం a[2];
};
నిర్మాణం mytest {
    శూన్య *foo, *bar, *baz;
};

నిర్మాణం mytest stdarg_for_struct(నిర్మాణం myspace bob, ...)
{
    నిర్మాణం myspace george, bill;
    నిర్మాణం myspace2 alex1;
    నిర్మాణం myspace3 alex2;
    నిర్మాణం myspace4 alex3;
    va_list ap;
    పొట్టి పూర్ణాంకం validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, నిర్మాణం myspace2);
    alex2    = va_arg(ap, నిర్మాణం myspace3);
    alex3    = va_arg(ap, నిర్మాణం myspace4);
    bill     = va_arg(ap, నిర్మాణం myspace);
    george   = va_arg(ap, నిర్మాణం myspace);
    validate = va_arg(ap, పూర్ణాంకం);
    రాయి("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    తిరిగి (నిర్మాణం mytest) {};
}

శూన్య stdarg_for_libc(స్థిరరాశి అక్షరం *fmt, ...)
{
    va_list వాదనలు;
    va_start(వాదనలు, fmt);
    vprintf(fmt, వాదనలు);
    va_end(వాదనలు);
}

శూన్య stdarg_syntax(పూర్ణాంకం n, ...)
{
    పూర్ణాంకం i;
    va_list ap;
    ఒకవేళ (1)
      va_start(ap, n);
    లేకపోతే
      ;
    i = va_arg(ap, పూర్ణాంకం);
    రాయి("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

రకనిర్వచనం నిర్మాణం{
    ద్విగుణ x,y;
} బిందువు;
బిందువు pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

స్థిర శూన్య stdarg_double_struct(పూర్ణాంకం nargs, పూర్ణాంకం posd,...)
{
    పూర్ణాంకం i;
    ద్విగుణ d;
    బిందువు pi;
    va_list వాదనలు;

    రాయి ("stdarg_double_struct: %d\n", posd);
    va_start(వాదనలు,posd);
    కొరకు(i = 0; i < nargs; i++) {
        ఒకవేళ (i == posd) {
            d = va_arg (వాదనలు, ద్విగుణ);
            రాయి ("d %d = %g\n", i, d);
        }
        లేకపోతే {
            pi = va_arg (వాదనలు, బిందువు);
            రాయి ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(వాదనలు);
}

శూన్య stdarg_test(శూన్య)
{
    LONG_DOUBLE ld = 1234567891234LL;
    నిర్మాణం myspace bob;
    నిర్మాణం myspace2 bob2;
    నిర్మాణం myspace3 bob3;
    నిర్మాణం myspace4 bob4;

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
#ఒకవేళ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#అయితే_ముగింపు
}

పూర్ణాంకం reltab[3] = { 1, 2, 3 };

పూర్ణాంకం *rel1 = &reltab[1];
పూర్ణాంకం *rel2 = &reltab[2];

శూన్య getmyaddress(శూన్య)
{
    రాయి("in getmyaddress\n");
}

#నిర్వచితమైతే __LP64__
దీర్ఘ __pa_symbol(శూన్య)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       తిరిగి ((దీర్ఘ)(((గుర్తులేని దీర్ఘ)(&rel1))) - (0xffffffff80000000UL));
}
#అయితే_ముగింపు

uintptr_t theaddress = (uintptr_t)getmyaddress;
శూన్య relocation_test(శూన్య)
{
    శూన్య (*fptr)(శూన్య) = (శూన్య (*)(శూన్య))theaddress;
    రాయి("*rel1=%d\n", *rel1);
    రాయి("*rel2=%d\n", *rel2);
    fptr();
#నిర్వచితమైతే __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    రాయి("pa_symbol: %d\n", (దీర్ఘ)&rel1 == __pa_symbol() - 0x80000000);
#అయితే_ముగింపు
}

శూన్య old_style_f(a,b,c)
     పూర్ణాంకం a, b;
     ద్విగుణ c;
{
    రాయి("a=%d b=%d b=%f\n", a, b, c);
}

శూన్య decl_func1(పూర్ణాంకం cmpfn())
{
    రాయి("cmpfn=%lx\n", (దీర్ఘ)cmpfn);
}

శూన్య decl_func2(cmpfn)
పూర్ణాంకం cmpfn();
{
    రాయి("cmpfn=%lx\n", (దీర్ఘ)cmpfn);
}

శూన్య old_style_function_test(శూన్య)
{
#ఒకవేళ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#లేకపోతే
    old_style_f((శూన్య *)1, 2, 3.0);
#అయితే_ముగింపు
    decl_func1(ఖాళీ);
    decl_func2(ఖాళీ);
}

శూన్య alloca_test()
{
    అక్షరం *p = alloca(16);
    strcpy(p,"123456789012345");
    రాయి("alloca: p is %s\n", p);
    అక్షరం *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    రాయి("alloca: %s\n", strcpy(alloca(అక్షరశ్రేణి_పొడవు(demo)+1),demo) );
}

శూన్య *bounds_checking_is_enabled()
{
    అక్షరం ca[10], *cp = ca-1;
    తిరిగి (ca != cp + 1) ? cp : ఖాళీ;
}

రకనిర్వచనం పూర్ణాంకం constant_negative_array_కొలత_as_compile_సమయం_assertion_idiom[(1 ? 2 : 0) - 1];

శూన్య c99_vla_test_1(పూర్ణాంకం size1, పూర్ణాంకం size2)
{
    పూర్ణాంకం కొలత = size1 * size2;
    పూర్ణాంకం tab1[కొలత][2], tab2[10][2];
    శూన్య *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    కొలత = కొలత-1;
    
    రాయి("Test C99 VLA 1 (sizeof): ");
    రాయి("%s\n", (పరిమాణం tab1 == size1 * size2 * 2 * పరిమాణం(పూర్ణాంకం)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    రాయి("Test C99 VLA 2 (ptrs subtract): ");
    రాయి("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (పరిమాణం(పూర్ణాంకం) * 2)) ? "PASSED" : "FAILED");
    రాయి("Test C99 VLA 3 (ptr add): ");
    రాయి("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * పరిమాణం(పూర్ణాంకం)) ? "PASSED" : "FAILED");
    రాయి("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    రాయి("%s\n", (*((పూర్ణాంకం *) (tab1_ptr + (size1 * 2 + 1) * పరిమాణం(పూర్ణాంకం))) == 42) ? "PASSED" : "FAILED");

    రాయి("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ఒకవేళ (bad_ptr = bounds_checking_is_enabled()) {
        పూర్ణాంకం *t1 = &tab1[size1 * size2 - 1][3];
        పూర్ణాంకం *t2 = &tab2[9][3];
        రాయి("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        రాయి("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        అక్షరం*c1 = 1 + పరిమాణం(tab1) + (అక్షరం*)tab1;
        అక్షరం*c2 = 1 + పరిమాణం(tab2) + (అక్షరం*)tab2;
        రాయి("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        రాయి("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        పూర్ణాంకం *i1 = tab1[-1];
        పూర్ణాంకం *i2 = tab2[-1];
        రాయి("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        రాయి("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        పూర్ణాంకం *x1 = tab1[size1 * size2 + 1];
        పూర్ణాంకం *x2 = tab2[10 + 1];
        రాయి("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        రాయి("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } లేకపోతే {
        రాయి("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    రాయి("\n");
}

శూన్య c99_vla_test_2(పూర్ణాంకం d, పూర్ణాంకం h, పూర్ణాంకం w)
{
    పూర్ణాంకం x, y, z;
    పూర్ణాంకం (*arr)[h][w] = జ్ఞాపకం_ఇవ్వు(పరిమాణం(పూర్ణాంకం) * d*h*w);
    పూర్ణాంకం c = 1;
    స్థిర పూర్ణాంకం (*starr)[h][w];

    రాయి("Test C99 VLA 6 (pointer)\n");

    కొరకు (z=0; z<d; z++) {
        కొరకు (y=0; y<h; y++) {
            కొరకు (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    కొరకు (z=0; z<d; z++) {
        కొరకు (y=0; y<h; y++) {
            కొరకు (x=0; x<w; x++) {
                రాయి(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    రాయి(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        పరిమాణం (*arr), పరిమాణం (*arr)[0], పరిమాణం (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == పరిమాణం (*arr + 1) - పరిమాణం arr,
        0 == పరిమాణం పరిమాణం *arr - పరిమాణం arr,
        starr[0][2][3] == arr[1][2][3]
        );
    విడుదల (arr);
}

శూన్య c99_vla_test_3a (పూర్ణాంకం arr[2][3][4])
{
    రాయి ("%d\n", arr[1][2][3]);
}

శూన్య c99_vla_test_3b(పూర్ణాంకం s, పూర్ణాంకం arr[s][3][4])
{
    రాయి ("%d\n", arr[1][2][3]);
}

శూన్య c99_vla_test_3c(పూర్ణాంకం s, పూర్ణాంకం arr[2][s][4])
{
    రాయి ("%d\n", arr[1][2][3]);
}

శూన్య c99_vla_test_3d(పూర్ణాంకం s, పూర్ణాంకం arr[2][3][s])
{
    రాయి ("%d\n", arr[1][2][3]);
}

శూన్య c99_vla_test_3e(పూర్ణాంకం s, పూర్ణాంకం arr[][3][--s])
{
    రాయి ("%d %d %d\n", పరిమాణం arr, s, arr[1][2][3]);
}

శూన్య c99_vla_test_3(శూన్య)
{
    పూర్ణాంకం a[2][3][4];

    memset (a, 0, పరిమాణం(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

శూన్య c99_vla_test(శూన్య)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


శూన్య sizeof_test(శూన్య)
{
    పూర్ణాంకం a;
    పూర్ణాంకం **ptr;

    రాయి("sizeof(int) = %d\n", పరిమాణం(పూర్ణాంకం));
    రాయి("sizeof(unsigned int) = %d\n", పరిమాణం(గుర్తులేని పూర్ణాంకం));
    రాయి("sizeof(long) = %d\n", పరిమాణం(దీర్ఘ));
    రాయి("sizeof(unsigned long) = %d\n", పరిమాణం(గుర్తులేని దీర్ఘ));
    రాయి("sizeof(short) = %d\n", పరిమాణం(పొట్టి));
    రాయి("sizeof(unsigned short) = %d\n", పరిమాణం(గుర్తులేని పొట్టి));
    రాయి("sizeof(char) = %d\n", పరిమాణం(అక్షరం));
    రాయి("sizeof(unsigned char) = %d\n", పరిమాణం(గుర్తులేని అక్షరం));
    రాయి("sizeof(func) = %d\n", పరిమాణం sizeof_test());
    a = 1;
    రాయి("sizeof(a++) = %d\n", పరిమాణం a++);
    రాయి("a=%d\n", a);
    ptr = ఖాళీ;
    రాయి("sizeof(**ptr) = %d\n", పరిమాణం (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    రాయి("sizeof(sizeof(int) = %d\n", పరిమాణం(పరిమాణం(పూర్ణాంకం)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -పరిమాణం(uintptr_t);
    రాయి ("%lu %lu\n", t, t2);

    /* some alignof tests */
    రాయి("__alignof__(int) = %d\n", __alignof__(పూర్ణాంకం));
    రాయి("__alignof__(unsigned int) = %d\n", __alignof__(గుర్తులేని పూర్ణాంకం));
    రాయి("__alignof__(short) = %d\n", __alignof__(పొట్టి));
    రాయి("__alignof__(unsigned short) = %d\n", __alignof__(గుర్తులేని పొట్టి));
    రాయి("__alignof__(char) = %d\n", __alignof__(అక్షరం));
    రాయి("__alignof__(unsigned char) = %d\n", __alignof__(గుర్తులేని అక్షరం));
    రాయి("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    రాయి("sizeof(char[1+2*a]) = %d\n", పరిమాణం(అక్షరం[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    రాయి("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   పరిమాణం( (నిర్మాణం {పూర్ణాంకం i; పూర్ణాంకం j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    రాయి("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   పరిమాణం (నిర్మాణం {పొట్టి i; పొట్టి j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    రాయి("sizeof(t && 0) = %d\n", పరిమాణం(t && 0));
    రాయి("sizeof(1 && 1) = %d\n", పరిమాణం(1 && 1));
    రాయి("sizeof(t || 1) = %d\n", పరిమాణం(t || 1));
    రాయి("sizeof(0 || 0) = %d\n", పరిమాణం(0 || 0));

    పూర్ణాంకం arr[4], fn();
    రాయి("sizeof(0, arr) = %d\n", పరిమాణం(0, arr));
    రాయి("sizeof(0, fn) = %d\n", పరిమాణం(0, fn));
}

శూన్య typeof_test(శూన్య)
{
    ద్విగుణ a;
    typeof(a) b;
    typeof(దశాంశం) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    రాయి("a=%f b=%f c=%f\n", a, b, c);
}


నిర్మాణం hlist_కణుపు;
నిర్మాణం hlist_తల {
    నిర్మాణం hlist_కణుపు *మొదటి, *చివరి;
};

శూన్య consume_ulong (గుర్తులేని దీర్ఘ i)
{
    i = 0;
}

శూన్య statement_సమాసం_test(శూన్య)
{
    పూర్ణాంకం a, i;

    /* Basic stmt expr test */
    a = 0;
    కొరకు(i=0;i<10;i++) {
        a += 1 + 
            ( { పూర్ణాంకం b, j; 
                b = 0; 
                కొరకు(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    రాయి("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    శూన్య *v = (శూన్య*)39;
    typeof(({
	    (నిర్మాణం hlist_కణుపు *)v;
	    })) x;
    typeof (x)
	ptr = (నిర్మాణం hlist_కణుపు *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#నిర్వచించు some_attr     __attribute__((aligned(1)))
#నిర్వచించు tps(str) ({                  \
            స్థిర స్థిరరాశి అక్షరం *t some_attr = str; \
            t;                                    \
          })
    రాయి ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    పూర్ణాంకం t = 40;
    పూర్ణాంకం b = ({ పూర్ణాంకం t = 41; t; });
    పూర్ణాంకం c = ({ పూర్ణాంకం t = 42; t; });

    /* Test that aggregate return values work.  */
    నిర్మాణం hlist_తల h
	= ({
	   రకనిర్వచనం నిర్మాణం hlist_తల T;
	   దీర్ఘ pre = 48;
	   T t = { (శూన్య*)43, (శూన్య*)44 };
	   దీర్ఘ post = 49;
	   t;
	   });
    రాయి ("stmtexpr: %d %d %d\n", t, b, c);
    రాయి ("stmtexpr: %ld %ld\n", (దీర్ఘ)h.మొదటి, (దీర్ఘ)h.చివరి);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (గుర్తులేని దీర్ఘ)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: ఒకవేళ (i++ == 0) వెళ్ళు LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      వెళ్ళు LBL;
    });
  LBL:
    రాయి("stmtexpr: %d should be 2\n", i);
}

శూన్య local_label_test(శూన్య)
{
    పూర్ణాంకం a;
    వెళ్ళు l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        వెళ్ళు l1;
    l4:
        రాయి("aa1\n");
        వెళ్ళు l3;
    l2:
        రాయి("aa3\n");
        వెళ్ళు l4;
    l1:
        రాయి("aa2\n");
        వెళ్ళు l2;
    l3:;
        1;
    });
    రాయి("a=%d\n", a);
    తిరిగి;
 l4:
    రాయి("bb1\n");
    వెళ్ళు l2;
 l1:
    రాయి("bb2\n");
    వెళ్ళు l4;
}

/* inline assembler test */
#ఒకవేళ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

రకనిర్వచనం __SIZE_TYPE__ మాట;

/* from linux kernel */
స్థిర అక్షరం * strncat1(అక్షరం * dest,స్థిరరాశి అక్షరం * src,కొలత_t లెక్క_2)
{
మాట d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (లెక్క_2)
	: "memory");
తిరిగి dest;
}

స్థిర అక్షరం * strncat2(అక్షరం * dest,స్థిరరాశి అక్షరం * src,కొలత_t లెక్క_2)
{
మాట d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (లెక్క_2)
	: "memory");
తిరిగి dest;
}

స్థిర అంతఃవరుస శూన్య * memcpy1(శూన్య * గమ్యం, స్థిరరాశి శూన్య * from, కొలత_t n)
{
మాట d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((మాట) గమ్యం),"2" ((మాట) from)
	: "memory");
తిరిగి (గమ్యం);
}

స్థిర అంతఃవరుస శూన్య * memcpy2(శూన్య * గమ్యం, స్థిరరాశి శూన్య * from, కొలత_t n)
{
మాట d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((మాట) గమ్యం),"2" ((మాట) from)
	: "memory");
తిరిగి (గమ్యం);
}

స్థిర __inline__ శూన్య sigaddset1(గుర్తులేని పూర్ణాంకం *సమితి, పూర్ణాంకం _sig)
{
	__asm__("btsl %1,%0" : "=m"(*సమితి) : "Ir"(_sig - 1) : "cc");
}

స్థిర __inline__ శూన్య sigdelset1(గుర్తులేని పూర్ణాంకం *సమితి, పూర్ణాంకం _sig)
{
	asm("btrl %1,%0" : "=m"(*సమితి) : "Ir"(_sig - 1) : "cc", "flags");
}

#నిర్వచితమైతే __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
స్థిర __inline__ __const__ గుర్తులేని పూర్ణాంకం swab32(గుర్తులేని పూర్ణాంకం x)
{
        తిరిగి ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#లేకపోతే
స్థిర __inline__ __const__ గుర్తులేని పూర్ణాంకం swab32(గుర్తులేని పూర్ణాంకం x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	తిరిగి x;
}
#అయితే_ముగింపు

స్థిర __inline__ గుర్తులేని దీర్ఘ దీర్ఘ mul64(గుర్తులేని పూర్ణాంకం a, గుర్తులేని పూర్ణాంకం b)
{
    గుర్తులేని దీర్ఘ దీర్ఘ res;
#నిర్వచితమైతే __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    గుర్తులేని పూర్ణాంకం resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((గుర్తులేని దీర్ఘ దీర్ఘ)resh << 32) | resl;
#లేకపోతే
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#అయితే_ముగింపు
    తిరిగి res;
}

స్థిర __inline__ గుర్తులేని దీర్ఘ దీర్ఘ inc64(గుర్తులేని దీర్ఘ దీర్ఘ a)
{
    గుర్తులేని దీర్ఘ దీర్ఘ res;
#నిర్వచితమైతే __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#లేకపోతే
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#అయితే_ముగింపు
    తిరిగి res;
}

నిర్మాణం struct123 {
    పూర్ణాంకం a;
    పూర్ణాంకం b;
};
నిర్మాణం struct1231 {
    మాట addr;
};

మాట mconstraint_test(నిర్మాణం struct1231 *r)
{
    మాట ret;
    గుర్తులేని పూర్ణాంకం a[2];
    a[0] = 0;
    __asm__ అస్థిర ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(నిర్మాణం struct123 *)r->addr));
    తిరిగి ret + a[0];
}

#నిర్వచితమైతే __x86_64__
పూర్ణాంకం fls64(గుర్తులేని దీర్ఘ దీర్ఘ x)
{
  పూర్ణాంకం bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  తిరిగి bitpos + 1;
}
#అయితే_ముగింపు

శూన్య other_constraints_test(శూన్య)
{
    మాట ret;
    పూర్ణాంకం var;
#ఒకవేళ CC_NAME != CC_clang
    __asm__ అస్థిర ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    రాయి ("oc1: %d\n", ret == (మాట)&var);
#అయితే_ముగింపు
}

#నిర్వచితం_కాకపోతే _WIN32
/* Test global asm blocks playing with aliases.  */
శూన్య పునాది_func(శూన్య)
{
  రాయి ("asmc: base\n");
}

#నిర్వచితం_కాకపోతే __APPLE__
బాహ్య శూన్య override_func1 (శూన్య);
బాహ్య శూన్య override_func2 (శూన్య);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

శూన్య override_func2 (శూన్య)
{
  రాయి ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
బాహ్య పూర్ణాంకం bug_పట్టిక[] __attribute__((section("__bug_table")));
అక్షరం * get_asm_string (శూన్య)
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
#నిర్వచితం_కాకపోతే __clang__
  బాహ్య పూర్ణాంకం some_చిహ్నం;
  asm అస్థిర (".globl some_symbol\n"
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
  అక్షరం * str = ((అక్షరం*)bug_పట్టిక) + bug_పట్టిక[1];
  తిరిగి str;
#లేకపోతే
  తిరిగి (అక్షరం *) "A string";
#అయితే_ముగింపు
}

/* This checks another constructs with local labels.  */
బాహ్య గుర్తులేని అక్షరం alld_stuff[];
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

శూన్య asm_local_label_diff (శూన్య)
{
  రాయి ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#అయితే_ముగింపు //!__APPLE__
#అయితే_ముగింపు //!_WIN32

/* This checks that static local variables are available from assembler.  */
శూన్య asm_local_statics (శూన్య)
{
  స్థిర పూర్ణాంకం localint = 41;
  asm("incl %0" : "+m" (localint));
  రాయి ("asm_local_statics: %d\n", localint);
}

స్థిర
గుర్తులేని పూర్ణాంకం సమితి;

శూన్య fancy_copy (గుర్తులేని *లోపల, గుర్తులేని *బహిర్గతం)
{
  asm అస్థిర ("" : "=r" (*బహిర్గతం) : "0" (*లోపల));
}

శూన్య fancy_copy2 (గుర్తులేని *లోపల, గుర్తులేని *బహిర్గతం)
{
  asm అస్థిర ("mov %0,(%1)" : : "r" (*లోపల), "r" (బహిర్గతం) : "memory");
}

#ఒకవేళ defined __x86_64__
శూన్య clobber_r12(శూన్య)
{
    asm అస్థిర("mov $1, %%r12" ::: "r12");
}
#అయితే_ముగింపు

శూన్య test_ఎగువ_clobbers_really(శూన్య)
{
#ఒకవేళ defined __x86_64__
    నమోదు మాట val asm("r12");
    మాట val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm అస్థిర("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm అస్థిర("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    రాయి("asmhc: 0x%x\n", val2);
#అయితే_ముగింపు
}

శూన్య test_ఎగువ_clobbers(శూన్య)
{
#ఒకవేళ defined __x86_64__
    మాట x1, x2;
    asm అస్థిర("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ఎగువ_clobbers_really();
    asm అస్థిర("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm అస్థిర("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#అయితే_ముగింపు
}

స్థిర దీర్ఘ cpu_సంఖ్య;
శూన్య trace_console(దీర్ఘ len, దీర్ఘ len2)
{
#నిర్వచితమైతే __x86_64__
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
    ఒకవేళ (0
        &&
            ({
              దీర్ఘ pscr_ret__;
              ఎంపిక(len) {
                స్థితి 4:
                    {
                       దీర్ఘ pfo_ret__;
                       ఎంపిక (len2) {
                         స్థితి 8:	రాయి("bla"); pfo_ret__ = 42; ఆపు;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ఆపు;
                స్థితి 8:
                    {
                       దీర్ఘ pfo_ret__;
                       ఎంపిక (len2) {
                         స్థితి 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_సంఖ్య));	ఆపు;
                         స్థితి 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_సంఖ్య));	ఆపు;
                         స్థితి 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_సంఖ్య));	ఆపు;
                         స్థితి 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_సంఖ్య));	ఆపు;
                         అప్రమేయ: రాయి("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ఆపు;
              }
              pscr_ret__;
            }))
      {
        రాయి("huh?\n");
      }
#అయితే_ముగింపు
}

శూన్య test_asm_dead_సంకేతం(శూన్య)
{
  మాట rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm అస్థిర ("" : "=D" (rdi) : "0" (0));
  (శూన్య)పరిమాణం (({
      పూర్ణాంకం var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm అస్థిర ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

శూన్య test_asm_call(శూన్య)
{
#ఒకవేళ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  స్థిర అక్షరం str[] = "PATH";
  అక్షరం *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm అస్థిర ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ఒకవేళ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#లేకపోతే
		"call getenv;"
#అయితే_ముగింపు
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  రాయి("asmd: %s\n", s);
#అయితే_ముగింపు
}

#ఒకవేళ defined __x86_64__
# define RX "(%rip)"
#లేకపోతే
# define RX
#అయితే_ముగింపు

శూన్య asm_dot_test(శూన్య)
{
#నిర్వచితం_కాకపోతే __APPLE__
    పూర్ణాంకం x;
    కొరకు (x = 1;; ++x) {
        పూర్ణాంకం r = x;
        ఎంపిక (x) {
        స్థితి 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        స్థితి 2:
#నిర్వచితం_కాకపోతే __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#లేకపోతే
            asm(".text; mov $123, %eax; jmp p0");
#అయితే_ముగింపు
	స్థితి 3:
#ఒకవేళ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#లేకపోతే
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#అయితే_ముగింపు
            asm(".text; mov X"RX",%eax; jmp p0");
        స్థితి 4:
#నిర్వచితమైతే __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#లేకపోతే
#నిర్వచితం_కాకపోతే _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#లేకపోతే
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#అయితే_ముగింపు
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#అయితే_ముగింపు
        స్థితి 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ఆపు;
	}
        ఒకవేళ (r == x)
            ఆపు;
        రాయి("asm_dot_test %d: %d\n", x, r);
    }
#అయితే_ముగింపు
}

శూన్య asm_pcrel_test(శూన్య)
{
    గుర్తులేని o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    రాయి("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

శూన్య asm_test(శూన్య)
{
    అక్షరం buf[128];
    గుర్తులేని పూర్ణాంకం val, val2;
    నిర్మాణం struct123 s1;
    నిర్మాణం struct1231 s2 = { (మాట)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    పూర్ణాంకం పునాది_func = 42;
    శూన్య override_func3 (శూన్య);
    మాట asmret;
#నిర్వచితమైతే BOOL_ISOC99
    _Bool somebool;
#అయితే_ముగింపు
    నమోదు పూర్ణాంకం regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm అస్థిర ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm అస్థిర ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    రాయి("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    రాయి("%s\n", buf);

    /* 'A' constraint test */
    రాయి("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    రాయి("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    రాయి("mconstraint: %d", mconstraint_test(&s2));
    రాయి(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    సమితి = 0xff;
    sigdelset1(&సమితి, 2);
    sigaddset1(&సమితి, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    వెళ్ళు label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(సమితి) : "Ir"(20) : "cc");
    రాయి("set=0x%x\n", సమితి);
    val = 0x01020304;
    రాయి("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#నిర్వచితం_కాకపోతే _WIN32
#నిర్వచితం_కాకపోతే __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm అస్థిర(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    రాయి("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#అయితే_ముగింపు
#అయితే_ముగింపు
    asm_local_statics();
#నిర్వచితం_కాకపోతే __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm అస్థిర("" : "=r" (asmret) : "0"(s2));
    ఒకవేళ (asmret != s2.addr)
      రాయి("asmstr: failed\n");
#అయితే_ముగింపు
#నిర్వచితమైతే BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm అస్థిర("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ఒకవేళ (!somebool)
      రాయి("asmbool: failed\n");
#అయితే_ముగింపు
    val = 43;
    fancy_copy (&val, &val2);
    రాయి ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    రాయి ("fancycpy2(%d)=%d\n", val, val2);
    asm అస్థిర ("mov $0x4243, %%esi" : "=r" (regvar));
    రాయి ("regvar=%x\n", regvar);
    test_ఎగువ_clobbers();
    trace_console(8, 8);
    test_asm_dead_సంకేతం();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    తిరిగి;
 label1:
    వెళ్ళు label2;
}

#లేకపోతే

శూన్య asm_test(శూన్య)
{
}

#అయితే_ముగింపు

#నిర్వచించు COMPAT_TYPE(type1, type2) \
{\
    రాయి("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

పూర్ణాంకం constant_p_var;

పూర్ణాంకం func(శూన్య);


/* __builtin_clz and __builtin_ctz return random values for 0 */
స్థిర శూన్య builtin_test_బిట్లు(గుర్తులేని దీర్ఘ దీర్ఘ x, పూర్ణాంకం cnt[])
{
#ఒకవేళ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ఒకవేళ ((గుర్తులేని పూర్ణాంకం) x) cnt[3] += __builtin_clz(x);
    ఒకవేళ ((గుర్తులేని దీర్ఘ) x) cnt[4] += __builtin_clzl(x);
    ఒకవేళ ((గుర్తులేని దీర్ఘ దీర్ఘ) x) cnt[5] += __builtin_clzll(x);

    ఒకవేళ ((గుర్తులేని పూర్ణాంకం) x) cnt[6] += __builtin_ctz(x);
    ఒకవేళ ((గుర్తులేని దీర్ఘ) x) cnt[7] += __builtin_ctzl(x);
    ఒకవేళ ((గుర్తులేని దీర్ఘ దీర్ఘ) x) cnt[8] += __builtin_ctzll(x);

#ఒకవేళ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#అయితే_ముగింపు

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#అయితే_ముగింపు
}

శూన్య builtin_test(శూన్య)
{
    పొట్టి s;
    పూర్ణాంకం i;
    దీర్ఘ దీర్ఘ ll;
#ఒకవేళ GCC_MAJOR >= 3
    COMPAT_TYPE(పూర్ణాంకం, పూర్ణాంకం);
    COMPAT_TYPE(పూర్ణాంకం, గుర్తులేని పూర్ణాంకం);
    COMPAT_TYPE(పూర్ణాంకం, అక్షరం);
    COMPAT_TYPE(పూర్ణాంకం, స్థిరరాశి పూర్ణాంకం);
    COMPAT_TYPE(పూర్ణాంకం, అస్థిర పూర్ణాంకం);
    COMPAT_TYPE(పూర్ణాంకం[2], స్థిరరాశి పూర్ణాంకం[2]);
    COMPAT_TYPE(పూర్ణాంకం[2][3], అస్థిర పూర్ణాంకం[][3]);
    COMPAT_TYPE(పూర్ణాంకం (*)[], స్థిరరాశి పూర్ణాంకం (*)[]);
#నిర్వచితం_కాకపోతే __clang__
    COMPAT_TYPE(__typeof__(1 ? (స్థిరరాశి పూర్ణాంకం (*)[2])0 : (పూర్ణాంకం (*)[2])0),
                స్థిరరాశి పూర్ణాంకం (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (స్థిరరాశి పూర్ణాంకం (*)[2][3])0 :
                              (అస్థిర పూర్ణాంకం (*)[2][3])0),
                స్థిరరాశి అస్థిర పూర్ణాంకం (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (అస్థిర పూర్ణాంకం (*)[2][3])0 :
                              (స్థిరరాశి పూర్ణాంకం (*)[2][3])0),
                స్థిరరాశి అస్థిర పూర్ణాంకం (*)[2][3]);
#లేకపోతే
    /* clang doesn't combine qualifiers through array types */
    రాయి("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    రాయి("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    రాయి("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#అయితే_ముగింపు
    COMPAT_TYPE(పూర్ణాంకం *, పూర్ణాంకం *);
    COMPAT_TYPE(పూర్ణాంకం *, శూన్య *);
    COMPAT_TYPE(పూర్ణాంకం *, స్థిరరాశి పూర్ణాంకం *);
    COMPAT_TYPE(అక్షరం *, గుర్తులేని అక్షరం *);
    COMPAT_TYPE(అక్షరం *, గుర్తుగల అక్షరం *);
    COMPAT_TYPE(అక్షరం *, అక్షరం *);
    COMPAT_TYPE(అక్షరం **, శూన్య *);
#అయితే_ముగింపు
    రాయి("res1 = %d\n", __builtin_constant_p(1));
    రాయి("res2 = %d\n", __builtin_constant_p(1 + 2));
    రాయి("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    రాయి("res4 = %d\n", __builtin_constant_p(constant_p_var));
    రాయి("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    రాయి("res6 = %d\n", __builtin_constant_p(i && 1));
    రాయి("res7 = %d\n", __builtin_constant_p("hi"));
    రాయి("res8 = %d\n", __builtin_constant_p(func()));
#నిర్వచితం_కాకపోతే __clang__
    రాయి("res10 = %d\n", __builtin_constant_p(i && 0));
    రాయి("res11 = %d\n", __builtin_constant_p(i * 0));
    రాయి("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    రాయి("res13 = %d\n", __builtin_constant_p((1,7)));
#లేకపోతే
    /* clang doesn't regard these as constant expression */
    రాయి("res10 = 1\n");
    రాయి("res11 = 1\n");
    రాయి("res12 = 1\n");
    రాయి("res13 = 0\n");
#అయితే_ముగింపు

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    రాయి("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    రాయి("bce: %d\n", i);
    i = పరిమాణం (__builtin_choose_expr (1, ll, s));
    రాయి("bce: %d\n", i);
    i = పరిమాణం (__builtin_choose_expr (0, ll, s));
    రాయి("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	పూర్ణాంకం cnt[18];
	గుర్తులేని దీర్ఘ దీర్ఘ r = 0;

	memset(cnt, 0, పరిమాణం(cnt));
	builtin_test_బిట్లు(0, cnt);
	builtin_test_బిట్లు(0xffffffffffffffffull, cnt);
        కొరకు (i = 0; i < 64; i++)
	    builtin_test_బిట్లు(1ull << i, cnt);
        కొరకు (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_బిట్లు(r, cnt);
	}
	కొరకు (i = 0; i < 18; i++)
	    రాయి ("%d %d\n", i, cnt[i]);
    }
}

#ఒకవేళ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
శూన్య weak_test(శూన్య) {}
#లేకపోతే
బాహ్య పూర్ణాంకం __attribute__((weak)) weak_f1(శూన్య);
బాహ్య పూర్ణాంకం __attribute__((weak)) weak_f2(శూన్య);
బాహ్య పూర్ణాంకం                       weak_f3(శూన్య);
బాహ్య పూర్ణాంకం __attribute__((weak)) weak_v1;
బాహ్య పూర్ణాంకం __attribute__((weak)) weak_v2;
బాహ్య పూర్ణాంకం                       weak_v3;

బాహ్య పూర్ణాంకం                           (*weak_fpa)() __attribute__((weak));
బాహ్య పూర్ణాంకం __attribute__((weak))     (*weak_fpb)();
బాహ్య     __attribute__((weak)) పూర్ణాంకం (*weak_fpc)();

బాహ్య పూర్ణాంకం                     weak_asm_f1(శూన్య) asm("weak_asm_f1x") __attribute((weak));
బాహ్య పూర్ణాంకం __attribute((weak)) weak_asm_f2(శూన్య) asm("weak_asm_f2x")                    ;
బాహ్య పూర్ణాంకం __attribute((weak)) weak_asm_f3(శూన్య) asm("weak_asm_f3x") __attribute((weak));
బాహ్య పూర్ణాంకం                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
బాహ్య పూర్ణాంకం __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
బాహ్య పూర్ణాంకం __attribute((weak)) weak_asm_v3(శూన్య) asm("weak_asm_v3x") __attribute((weak));

#నిర్వచితం_కాకపోతే __clang__
స్థిర స్థిరరాశి కొలత_t dummy = 0;
బాహ్య __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
బాహ్య __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
బాహ్య __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#అయితే_ముగింపు

పూర్ణాంకం some_lib_func(శూన్య);
పూర్ణాంకం dummy_impl_యొక్క_slf(శూన్య) { తిరిగి 444; }
#నిర్వచితం_కాకపోతే __clang__
పూర్ణాంకం some_lib_func(శూన్య) __attribute__((weak, alias("dummy_impl_of_slf")));
#అయితే_ముగింపు

పూర్ణాంకం weak_toolate() __attribute__((weak));
పూర్ణాంకం weak_toolate() { తిరిగి 0; }

శూన్య __attribute__((weak)) weak_test(శూన్య)
{
	రాయి("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	రాయి("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	రాయి("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	రాయి("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	రాయి("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	రాయి("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	రాయి("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	రాయి("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	రాయి("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	రాయి("weak_asm_f1=%d\n", weak_asm_f1 != ఖాళీ);
	రాయి("weak_asm_f2=%d\n", weak_asm_f2 != ఖాళీ);
	రాయి("weak_asm_f3=%d\n", weak_asm_f3 != ఖాళీ);
	రాయి("weak_asm_v1=%d\n",&weak_asm_v1 != ఖాళీ);
	రాయి("weak_asm_v2=%d\n",&weak_asm_v2 != ఖాళీ);
	రాయి("weak_asm_v3=%d\n",&weak_asm_v3 != ఖాళీ);
#నిర్వచితమైతే __clang__
	రాయి("some_lib_func=444\n");
#లేకపోతే
	రాయి("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#అయితే_ముగింపు
}

పూర్ణాంకం __attribute__((weak)) weak_f2() { తిరిగి 222; }
పూర్ణాంకం __attribute__((weak)) weak_f3() { తిరిగి 333; }
పూర్ణాంకం __attribute__((weak)) weak_v2 = 222;
పూర్ణాంకం __attribute__((weak)) weak_v3 = 333;
#అయితే_ముగింపు

శూన్య const_func(స్థిరరాశి పూర్ణాంకం a)
{
}

శూన్య const_warn_test(శూన్య)
{
    const_func(1);
}

నిర్మాణం condstruct {
  పూర్ణాంకం i;
};

పూర్ణాంకం getme (నిర్మాణం condstruct *s, పూర్ణాంకం i)
{
  పూర్ణాంకం i1 = (i == 0 ? 0 : s)->i;
  పూర్ణాంకం i2 = (i == 0 ? s : 0)->i;
  పూర్ణాంకం i3 = (i == 0 ? (శూన్య*)0 : s)->i;
  పూర్ణాంకం i4 = (i == 0 ? s : (శూన్య*)0)->i;
  తిరిగి i1 + i2 + i3 + i4;
}

నిర్మాణం global_దత్తాంశం
{
  పూర్ణాంకం a[40];
  పూర్ణాంకం *b[40];
};

నిర్మాణం global_దత్తాంశం global_దత్తాంశం;

పూర్ణాంకం global_దత్తాంశం_getstuff (పూర్ణాంకం *, పూర్ణాంకం);

శూన్య global_దత్తాంశం_callit (పూర్ణాంకం i)
{
  *global_దత్తాంశం.b[i] = global_దత్తాంశం_getstuff (global_దత్తాంశం.b[i], 1);
}

పూర్ణాంకం global_దత్తాంశం_getstuff (పూర్ణాంకం *p, పూర్ణాంకం i)
{
  తిరిగి *p + i;
}

శూన్య global_దత్తాంశం_test (శూన్య)
{
  global_దత్తాంశం.a[0] = 42;
  global_దత్తాంశం.b[0] = &global_దత్తాంశం.a[0];
  global_దత్తాంశం_callit (0);
  రాయి ("%d\n", global_దత్తాంశం.a[0]);
}

నిర్మాణం cmpcmpS
{
  గుర్తులేని అక్షరం fill : 3;
  గుర్తులేని అక్షరం b1 : 1;
  గుర్తులేని అక్షరం b2 : 1;
  గుర్తులేని అక్షరం fill2 : 3;
};

పూర్ణాంకం glob1, glob2, glob3;

శూన్య compare_comparisons (నిర్మాణం cmpcmpS *s)
{
  ఒకవేళ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    రాయి ("comparing comparisons broken\n");
}

శూన్య cmp_comparison_test(శూన్య)
{
  నిర్మాణం cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

పూర్ణాంకం fcompare (ద్విగుణ a, ద్విగుణ b, పూర్ణాంకం సంకేతం_2)
{
  ఎంపిక (సంకేతం_2) {
    స్థితి 0: తిరిగి a == b;
    స్థితి 1: తిరిగి a != b;
    స్థితి 2: తిరిగి a < b;
    స్థితి 3: తిరిగి a >= b;
    స్థితి 4: తిరిగి a > b;
    స్థితి 5: తిరిగి a <= b;
  }
  తిరిగి 0;
}

శూన్య math_cmp_test(శూన్య)
{
  ద్విగుణ nan = 0.0/0.0;
  ద్విగుణ one = 1.0;
  ద్విగుణ two = 2.0;
  పూర్ణాంకం comp = 0;
  పూర్ణాంకం v;
#నిర్వచించు bug(a,b,op,iop,part) రాయి("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#నిర్వచించు FCMP(a,b,op,iop,సంకేతం_2) \
  ఒకవేళ (fcompare (a,b,సంకేతం_2))    \
    bug (a,b,op,iop,1); \
  ఒకవేళ (a op b) \
    bug (a,b,op,iop,2); \
  ఒకవేళ (a iop b) \
    ; \
  లేకపోతే \
    bug (a,b,op,iop,3); \
  ఒకవేళ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ఒకవేళ ((a iop b) || comp) \
    ; \
  లేకపోతే \
    bug (a,b,op,iop,5); \
  ఒకవేళ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ఒకవేళ (!fcompare (nan, nan, 1))
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

ద్విగుణ get100 () { తిరిగి 100.0; }

శూన్య callsave_test(శూన్య)
{
  పూర్ణాంకం i, s; ద్విగుణ *d; ద్విగుణ t;
  s = పరిమాణం (ద్విగుణ);
  రాయి ("callsavetest: %d\n", s);
  d = alloca (పరిమాణం(ద్విగుణ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  రాయి ("%d\n", i);
}


శూన్య bfa3(ptrdiff_t str_స్థానభ్రంశం)
{
    రాయి("bfa3: %s\n", (అక్షరం *)__builtin_frame_address(3) + str_స్థానభ్రంశం);
}
శూన్య bfa2(ptrdiff_t str_స్థానభ్రంశం)
{
    రాయి("bfa2: %s\n", (అక్షరం *)__builtin_frame_address(2) + str_స్థానభ్రంశం);
    bfa3(str_స్థానభ్రంశం);
}
శూన్య bfa1(ptrdiff_t str_స్థానభ్రంశం)
{
    రాయి("bfa1: %s\n", (అక్షరం *)__builtin_frame_address(1) + str_స్థానభ్రంశం);
    bfa2(str_స్థానభ్రంశం);
}

శూన్య builtin_చట్రం_చిరునామా_test(శూన్య)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#నిర్వచితం_కాకపోతే __arm__
    అక్షరం str[] = "__builtin_frame_address";
    అక్షరం *fp0 = __builtin_frame_address(0);

    రాయి("str: %s\n", str);
#నిర్వచితం_కాకపోతే __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#అయితే_ముగింపు
#అయితే_ముగింపు
}

అక్షరం ద్వారా_volatile (అక్షరం i)
{
  అక్షరం అస్థిర vi;
  vi = i;
  తిరిగి vi;
}

శూన్య volatile_test(శూన్య)
{
    ఒకవేళ (ద్వారా_volatile (42) != 42)
      రాయి (" broken\n");
    లేకపోతే
      రాయి (" ok\n");
}

నిర్మాణం __attribute__((__packed__)) Spacked {
    అక్షరం a;
    పొట్టి b;
    పూర్ణాంకం c;
};
నిర్మాణం Spacked spacked;
రకనిర్వచనం నిర్మాణం __attribute__((__packed__)) {
    అక్షరం a;
    పొట్టి b;
    పూర్ణాంకం c;
} Spacked2;
Spacked2 spacked2;
రకనిర్వచనం నిర్మాణం Spacked3_s {
    అక్షరం a;
    పొట్టి b;
    పూర్ణాంకం c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
నిర్మాణం gate_struct64 {
    గుర్తులేని పొట్టి స్థానభ్రంశం_దిగువ;
    గుర్తులేని పొట్టి segment;
    గుర్తులేని ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    గుర్తులేని పొట్టి స్థానభ్రంశం_మధ్య;
    గుర్తులేని స్థానభ్రంశం_ఎగువ;
    గుర్తులేని zero1;
} __attribute__((packed));
రకనిర్వచనం నిర్మాణం gate_struct64 gate_desc;
gate_desc a_gate_desc;
శూన్య attrib_test(శూన్య)
{
#నిర్వచితం_కాకపోతే _WIN32
  రాయి("attr: %d %d %d %d\n", పరిమాణం(నిర్మాణం Spacked),
	 పరిమాణం(spacked), పరిమాణం(Spacked2), పరిమాణం(spacked2));
  రాయి("attr: %d %d\n", పరిమాణం(Spacked3), పరిమాణం(spacked3));
  రాయి("attr: %d %d\n", పరిమాణం(gate_desc), పరిమాణం(a_gate_desc));
#అయితే_ముగింపు
}
బాహ్య __attribute__((__unused__)) అక్షరం * __attribute__((__unused__)) *
strange_attrib_placement (శూన్య);

శూన్య * __attribute__((__unused__)) get_void_ptr (శూన్య *a)
{
  తిరిగి a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
స్థిర అంతఃవరుస
పూర్ణాంకం __get_order(గుర్తులేని దీర్ఘ దీర్ఘ కొలత)
{
  పూర్ణాంకం క్రమం;
  కొలత -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      నిర్మాణం S { పూర్ణాంకం i : 1; } s; // constructed for this '1'
    }
  క్రమం = కొలత;
  తిరిగి క్రమం;
}

/* This just forces the above inline function to be actually emitted.  */
పూర్ణాంకం force_get_క్రమం(గుర్తులేని దీర్ఘ s)
{
    తిరిగి __get_order(s);
}

#నిర్వచించు pv(m) రాయి(పరిమాణం (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
శూన్య bounds_check1_test (శూన్య)
{
    నిర్మాణం s {
        పూర్ణాంకం x;
        దీర్ఘ దీర్ఘ y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
శూన్య map_కూడు(పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం c, పూర్ణాంకం d, పూర్ణాంకం e, పూర్ణాంకం f, పూర్ణాంకం g, పూర్ణాంకం h, పూర్ణాంకం i)
{
  రాయి ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

శూన్య func_arg_test(శూన్య)
{
    పూర్ణాంకం a = 0;
    పూర్ణాంకం b = 1;
    map_కూడు(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#నిర్వచించు CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#నిర్వచితమైతే __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#అయితే_ముగింపు

#నిర్వచించు	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
శూన్య whitespace_test(శూన్య)
{
    అక్షరం *str;
    పూర్ణాంకం tcc_test = 1;

#ఒకవేళ 1
    pri\
ntf("whitspace:\n");
#అయితే_ముగింపు
    pf("N=%d\n", 2);

#నిర్వచితమైతే CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#అయితే_ముగింపు

    pri\
\
ntf("min=%d\n", 4);

#నిర్వచితమైతే ACCEPT_LF_లోపల_అక్షరశ్రేణులు
    రాయి("len1=%d\n", అక్షరశ్రేణి_పొడవు("
"));
#నిర్వచితమైతే CORRECT_CR_HANDLING
    str = "
";
    రాయి("len1=%d str[0]=%d\n", అక్షరశ్రేణి_పొడవు(str), str[0]);
#అయితే_ముగింపు
    రాయి("len1=%d\n", అక్షరశ్రేణి_పొడవు("a
"));
#లేకపోతే
    రాయి("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#అయితే_ముగింపు /* ACCEPT_LF_IN_STRINGS */

#నిర్వచితమైతే __LINE__
    రాయి("__LINE__ defined\n");
#అయితే_ముగింపు

#ఒకవేళ 0
    /* wrong with GCC */
    రాయి("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#పంక్తి 1111
    రాయి("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#పంక్తి 2222 "test"
    రాయి("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#అయితే_ముగింపు

    రాయి("\\
"12\\
063\\
n 456\"\n");

    రాయి ("%d\n",
#ఒకవేళ 1
	    tcc_test
#అయితే_ముగింపు
            );

}

#నిర్వచించు నిరంతరం_2(test) puts("---- " #test " ----"), test(), puts("")

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv)
{
    నిరంతరం_2(whitespace_test);
    నిరంతరం_2(macro_test);
    నిరంతరం_2(recursive_macro_test);
    నిరంతరం_2(string_test);
    నిరంతరం_2(సమాసం_test);
    నిరంతరం_2(scope_test);
    నిరంతరం_2(scope2_test);
    నిరంతరం_2(forward_test);
    నిరంతరం_2(funcptr_test);
    నిరంతరం_2(if_test);
    నిరంతరం_2(loop_test);
    నిరంతరం_2(switch_test);
    నిరంతరం_2(goto_test);
    నిరంతరం_2(enum_test);
    నిరంతరం_2(typedef_test);
    నిరంతరం_2(struct_test);
    నిరంతరం_2(array_test);
    నిరంతరం_2(సమాసం_ptr_test);
    నిరంతరం_2(bool_test);
    నిరంతరం_2(optimize_బహిర్గతం_test);
    నిరంతరం_2(expr2_test);
    నిరంతరం_2(constant_సమాసం_test);
    నిరంతరం_2(సమాసం_cmp_test);
    నిరంతరం_2(char_short_test);
    నిరంతరం_2(init_test);
    నిరంతరం_2(compound_literal_test);
    నిరంతరం_2(kr_test);
    నిరంతరం_2(struct_కేటాయించు_test);
    నిరంతరం_2(cast_test);
    నిరంతరం_2(bitfield_test);
    నిరంతరం_2(c99_bool_test);
    నిరంతరం_2(float_test);
    నిరంతరం_2(longlong_test);
    నిరంతరం_2(manyarg_test);
    నిరంతరం_2(stdarg_test);
    నిరంతరం_2(relocation_test);
    నిరంతరం_2(old_style_function_test);
    నిరంతరం_2(alloca_test);
    నిరంతరం_2(c99_vla_test);
    నిరంతరం_2(sizeof_test);
    నిరంతరం_2(typeof_test);
    నిరంతరం_2(statement_సమాసం_test);
    నిరంతరం_2(local_label_test);
    నిరంతరం_2(asm_test);
    నిరంతరం_2(builtin_test);
    నిరంతరం_2(weak_test);
    నిరంతరం_2(global_దత్తాంశం_test);
    నిరంతరం_2(cmp_comparison_test);
    నిరంతరం_2(math_cmp_test);
    నిరంతరం_2(callsave_test);
    నిరంతరం_2(builtin_చట్రం_చిరునామా_test);
    నిరంతరం_2(volatile_test);
    నిరంతరం_2(attrib_test);
    నిరంతరం_2(bounds_check1_test);
    నిరంతరం_2(func_arg_test);

    తిరిగి 0;
}
