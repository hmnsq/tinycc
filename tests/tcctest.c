/*
 * TCC auto test program
 */
#ਅਨ੍ਤਰ੍ਭਾਵ "config.h"

/* identify the configured reference compiler in use */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_gcc 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_clang 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C99_MACROS

#ਜੇ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_LONG_FORMAT "%lld"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULONG_LONG_FORMAT "%llu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XLONG_LONG_FORMAT "%llx"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_LONG_FORMAT "%Ld"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULONG_LONG_FORMAT "%Lu"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XLONG_LONG_FORMAT "%Lx"
#ਜੇ_ਅੰਤ

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ਜੇ defined(_WIN32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE ਦੁੱਗਣਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE_LITERAL(x) x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE ਲੰਮਾ ਦੁੱਗਣਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LONG_DOUBLE_LITERAL(x) x ## L
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCLIB_INC <tcclib.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCLIB_INC1 <tcclib
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCLIB_INC2 h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCCLIB_INC3 "tcclib.h"

#ਅਨ੍ਤਰ੍ਭਾਵ TCCLIB_INC

#ਅਨ੍ਤਰ੍ਭਾਵ TCCLIB_INC1.TCCLIB_INC2

#ਅਨ੍ਤਰ੍ਭਾਵ TCCLIB_INC1.h>

#ਅਨ੍ਤਰ੍ਭਾਵ TCCLIB_INC3

#ਅਨ੍ਤਰ੍ਭਾਵ <tcclib.h>

#ਅਨ੍ਤਰ੍ਭਾਵ "tcclib.h"

#ਅਨ੍ਤਰ੍ਭਾਵ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INC(name) <tests/name.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ funnyname 42test.h
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ incdir tests/
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ incname <tests/42test.h>
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ incname < incdir funnyname >
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stringify(x) #x
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ stringify(x) __stringify(x)
#ਅਨ੍ਤਰ੍ਭਾਵ INC(42test)
#ਅਨ੍ਤਰ੍ਭਾਵ incname
#ਅਨ੍ਤਰ੍ਭਾਵ stringify(funnyname)

ਪੂਰਨ fib(ਪੂਰਨ n);
ਖਾਲੀ ਅੰਕ(ਪੂਰਨ n);
ਖਾਲੀ forward_ref(ਖਾਲੀ);
ਪੂਰਨ isid(ਪੂਰਨ c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
ਖਾਲੀ funny_ਸਤਰ_continuation (ਪੂਰਨ, ..\
. );

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ A 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N 1234 + A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pf ਲਿਖੋ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M1(a, b)  (a) + (b)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ str\
(s) # s
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ glue(a, b) a ## b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ xglue(a, b) glue(a, b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HIGHLOW "hello"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨੀਵਾਂ_2 ਨੀਵਾਂ_2 ", world"

ਸਥਿਰ ਪੂਰਨ onetwothree = 123;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ onetwothree4 onetwothree
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ onetwothree xglue(onetwothree,4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ min(a, b) ((a) < (b) ? (a) : (b))

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ C99_MACROS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dprintf(level,...) ਲਿਖੋ(__VA_ARGS__)
#ਜੇ_ਅੰਤ

/* gcc vararg macros */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ dprintf1(level, fmt, ਦਲੀਲਾਂ...) ਲਿਖੋ(fmt, ## ਦਲੀਲਾਂ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MACRO_NOARGS()

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST_CALL(f, ...) f(__VA_ARGS__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST_CONST()      123

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AAA 3
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ AAA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AAA 4

#ਜੇ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ B3 1
#ਜਾਂਜੇ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ B3 2
#ਜਾਂਜੇ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ B3 3
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ B3 4
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __INT64_C(c)	c ## LL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INT64_MIN	(-__INT64_C(9223372036854775807)-1)

ਪੂਰਨ qq(ਪੂਰਨ x)
{
    ਵਾਪਸ x + 40;
}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ qq(x) x

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ spin_ਤਾਲਾ(ਤਾਲਾ) ਕਰੋ { } ਜਦੋਂ (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wq_spin_ਤਾਲਾ spin_ਤਾਲਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEST2() wq_spin_ਤਾਲਾ(a)

ਖਾਲੀ macro_test(ਖਾਲੀ)
{
    pf("N=%d\n", N);
    ਲਿਖੋ("aaa=%d\n", AAA);

    ਲਿਖੋ("min=%d\n", min(1, min(2, -1)));

    ਲਿਖੋ("s1=%s\n", glue(ਉੱਚਾ_2, ਨੀਵਾਂ_2));
    ਲਿਖੋ("s2=%s\n", xglue(ਉੱਚਾ_2, ਨੀਵਾਂ_2));
    ਲਿਖੋ("s3=%s\n", str("c"));
    ਲਿਖੋ("s4=%s\n", str(a1));
    ਲਿਖੋ("B3=%d\n", B3);

    ਲਿਖੋ("onetwothree=%d\n", onetwothree);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ A
    ਲਿਖੋ("A defined\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ B
    ਲਿਖੋ("B defined\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ A
    ਲਿਖੋ("A defined\n");
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("A not defined\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ B
    ਲਿਖੋ("B defined\n");
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("B not defined\n");
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ A
    ਲਿਖੋ("A defined\n");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ B
    ਲਿਖੋ("B1 defined\n");
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("B1 not defined\n");
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("A not defined\n");
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ B
    ਲਿਖੋ("B2 defined\n");
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("B2 not defined\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ 1+1
    ਲਿਖੋ("test true1\n");
#ਜੇ_ਅੰਤ
#ਜੇ 0
    ਲਿਖੋ("test true2\n");
#ਜੇ_ਅੰਤ
#ਜੇ 1-1
    ਲਿਖੋ("test true3\n");
#ਜੇ_ਅੰਤ
#ਜੇ defined(A)
    ਲਿਖੋ("test trueA\n");
#ਜੇ_ਅੰਤ
#ਜੇ defined(B)
    ਲਿਖੋ("test trueB\n");
#ਜੇ_ਅੰਤ

#ਜੇ 0
    ਲਿਖੋ("test 0\n");
#ਜਾਂਜੇ 0
    ਲਿਖੋ("test 1\n");
#ਜਾਂਜੇ 2
    ਲਿਖੋ("test 2\n");
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("test 3\n");
#ਜੇ_ਅੰਤ

    MACRO_NOARGS();

    ਲਿਖੋ("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ C99_MACROS
    ਲਿਖੋ("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#ਜੇ_ਅੰਤ
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    ਲਿਖੋ("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    ਲਿਖੋ("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        ਪੂਰਨ a;
        a = 1;
        glue(a+, +);
        ਲਿਖੋ("a=%d\n", a);
        glue(a <, <= 2);
        ਲਿਖੋ("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_s MF_hello
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_hello(ਸੁਨੇਹਾ) ਲਿਖੋ("%s\n",ਸੁਨੇਹਾ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_t ਲਿਖੋ("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    ਲਿਖੋ("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ qq1(x) 1
    ਲਿਖੋ("qq1=%d\n", qq1( ));

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

    ਲਿਖੋ("basefromheader %s\n", get_basefile_from_ਸਿਰਲੇਖ());
    ਲਿਖੋ("base %s\n", __BASE_FILE__);
#ਜੇ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ਅਚਲ ਅੱਖਰ *fn = get_file_from_ਸਿਰਲੇਖ();
      ਜੇ (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      ਲਿਖੋ("filefromheader %s\n", fn);
    }
#ਜੇ_ਅੰਤ

    ਲਿਖੋ("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_ਦੂਜਾ = 1;
    have_included_42test_h_ਤੀਜਾ = 1;

    /* Check that we don't complain about stray \ here */
    ਲਿਖੋ("print a backslash: %s\n", stringify(\\));
}


ਸਥਿਰ ਖਾਲੀ print_ਅੰਕ(ਅੱਖਰ *fn, ਪੂਰਨ ਸਤਰ, ਪੂਰਨ ਅੰਕ) {
    ਲਿਖੋ("fn %s, line %d, num %d\n", fn, ਸਤਰ, ਅੰਕ);
}

ਖਾਲੀ recursive_macro_test(ਖਾਲੀ)
{

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF32_ST_TYPE(val)              ((val) & 0xf)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STB_WEAK        2               /* Weak symbol */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELFW(type) ELF##32##_##type
    ਲਿਖੋ("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WRAP(x) x
    
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ print_ਅੰਕ(x) print_ਅੰਕ(__FILE__,__LINE__,x)
    print_ਅੰਕ(123);
    WRAP(print_ਅੰਕ(123));
    WRAP(WRAP(print_ਅੰਕ(123)));

ਸਥਿਰ ਬਣਤਰ recursive_macro { ਪੂਰਨ rm_ਖੇਤਰ; } G;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ rm_ਖੇਤਰ (G.rm_ਖੇਤਰ)
    ਲਿਖੋ("rm_field = %d\n", rm_ਖੇਤਰ);
    ਲਿਖੋ("rm_field = %d\n", WRAP(rm_ਖੇਤਰ));
    WRAP((ਲਿਖੋ("rm_field = %d %d\n", rm_ਖੇਤਰ, WRAP(rm_ਖੇਤਰ))));
}

#ਜੇ __TINYC__
ਪੂਰਨ op(a, b)
{
    ਵਾਪਸ a / b;
}

ਪੂਰਨ ret(a)
{
    ਜੇ (a == 2)
        ਵਾਪਸ 1;
    ਜੇ (a == 3)
        ਵਾਪਸ 2;
    ਵਾਪਸ 0;
}
#ਜੇ_ਅੰਤ

#ਜੇ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSTANTINDEXEDSTRLIT
#ਜੇ_ਅੰਤ
ਅੱਖਰ str_ag1[] = "b";
ਅੱਖਰ str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONSTANTINDEXEDSTRLIT
ਅੱਖਰ str_ag3[] = { "ab"[1], 0 };
ਅੱਖਰ str_x[2] = { "xy" "z"[2], 0 };
#ਜੇ_ਅੰਤ
ਅੱਖਰ *str_ar[] = { "one", "two" };
ਬਣਤਰ str_SS {ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ a[3], b; };
ਬਣਤਰ str_SS str_sinit15 = { "r" };
ਬਣਤਰ str_SS str_sinit16[] = { { "q" }, 2 };

ਸਥਿਰ ਖਾਲੀ string_test2()
{
    ਅੱਖਰ *p = "hello";
    ਅੱਖਰ a3[2] = { "p" };
    ਅੱਖਰ a4[2] = { "ab" "c"[2], 0 };
    ਅੱਖਰ *pa1 = "def" + 1;
    ਅੱਖਰ *pa2 = { "xyz" + 1 };
    ਪੂਰਨ i = 0;
    ਬਣਤਰ str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CONSTANTINDEXEDSTRLIT
    ਅੱਖਰ str_ag3[] = { "ab"[1], 0 };
    ਅੱਖਰ str_x[2] = { "xy" "z"[2], 0 };
#ਜੇ_ਅੰਤ
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
    ਲਿਖੋ("%s\n", "bla");
    puts(str_ar[0]);
    puts(str_ar[1]);
    puts(ss.a);
    puts(i >= 0 ? "one" : "two");
    puts(pa1);
    puts(pa2);
}

ਖਾਲੀ ps(ਅਚਲ ਅੱਖਰ *s)
{
    ਪੂਰਨ c;
    ਜਦੋਂ (1) {
        c = *s;
        ਜੇ (c == 0)
            ਰੋਕੋ;
        ਲਿਖੋ("%c", c);
        s++;
    }
}

ਅਚਲ ਅੱਖਰ foo1_string[] = "\
bar\n\
test\14\
1";

ਖਾਲੀ string_test()
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ b;
    ਲਿਖੋ("string:\n");
    ਲਿਖੋ("\141\1423\143\n");/* dezdez test */
    ਲਿਖੋ("\x41\x42\x43\x3a\n");
    ਲਿਖੋ("c=%c\n", 'r');
    ਲਿਖੋ("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    ਲਿਖੋ("foo1_string='%s'\n", foo1_string);
#ਜੇ 0
    ਲਿਖੋ("wstring=%S\n", L"abc");
    ਲਿਖੋ("wstring=%S\n", L"abc" L"def" "ghi");
    ਲਿਖੋ("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    ਲਿਖੋ("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#ਜੇ_ਅੰਤ
    ps("test\n");
    b = 32;
    ਜਦੋਂ ((b = b + 1) < 96) {
        ਲਿਖੋ("%c", b);
    }
    ਲਿਖੋ("\n");
    ਲਿਖੋ("fib=%d\n", fib(33));
    b = 262144;
    ਜਦੋਂ (b != 0x80000000) {
        ਅੰਕ(b);
        b = b * 2;
    }
    string_test2();
}


ਖਾਲੀ if1t(ਪੂਰਨ n, ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ c)
{
    ਜੇ (a && b) ਲਿਖੋ("if1t: %d 1 %d %d\n", n, a, b);
    ਜੇ (a && !b) ਲਿਖੋ("if1t: %d 2 %d %d\n", n, a, b);
    ਜੇ (!a && b) ਲਿਖੋ("if1t: %d 3 %d %d\n", n, a, b);
    ਜੇ (!a && !b) ਲਿਖੋ("if1t: %d 4 %d %d\n", n, a, b);
    ਜੇ (a || b) ਲਿਖੋ("if1t: %d 5 %d %d\n", n, a, b);
    ਜੇ (a || !b) ਲਿਖੋ("if1t: %d 6 %d %d\n", n, a, b);
    ਜੇ (!a || b) ਲਿਖੋ("if1t: %d 7 %d %d\n", n, a, b);
    ਜੇ (!a || !b) ਲਿਖੋ("if1t: %d 8 %d %d\n", n, a, b);
    ਜੇ (a && b || c) ਲਿਖੋ("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ਜੇ (a || b && c) ਲਿਖੋ("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ਜੇ (a > b - 1 && c) ਲਿਖੋ("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ਜੇ (a > b - 1 || c) ਲਿਖੋ("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ਜੇ (a > 0 && 1) ਲਿਖੋ("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ਜੇ (a > 0 || 0) ਲਿਖੋ("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

ਖਾਲੀ if2t(ਖਾਲੀ)
{
    ਜੇ (0 && 1 || ਲਿਖੋ("if2t:ok\n") || 1)
      ਲਿਖੋ("if2t:ok2\n");
    ਲਿਖੋ("if2t:ok3\n");
}

ਖਾਲੀ if3t(ਖਾਲੀ)
{
    ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ i = 1;
    ਜੇ (i <= 18446744073709551615ULL)
      ;
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ ("if3t:wrong 1\n");
}

ਖਾਲੀ if_test(ਖਾਲੀ)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

ਖਾਲੀ loop_test()
{
    ਪੂਰਨ i;
    i = 0;
    ਜਦੋਂ (i < 10)
        ਲਿਖੋ("%d", i++);
    ਲਿਖੋ("\n");
    ਲਈ(i = 0; i < 10;i++)
        ਲਿਖੋ("%d", i);
    ਲਿਖੋ("\n");
    i = 0;
    ਕਰੋ {
        ਲਿਖੋ("%d", i++);
    } ਜਦੋਂ (i < 10);
    ਲਿਖੋ("\n");

    ਅੱਖਰ ਗਿਣਤੀ_3 = 123;
    /* c99 for loop init test */
    ਲਈ (ਮਾਪ_t ਗਿਣਤੀ_3 = 1; ਗਿਣਤੀ_3 < 3; ਗਿਣਤੀ_3++)
        ਲਿਖੋ("count=%d\n", ਗਿਣਤੀ_3);
    ਲਿਖੋ("count = %d\n", ਗਿਣਤੀ_3);

    /* break/continue tests */
    i = 0;
    ਜਦੋਂ (1) {
        ਜੇ (i == 6)
            ਰੋਕੋ;
        i++;
        ਜੇ (i == 3)
            ਜਾਰੀ;
        ਲਿਖੋ("%d", i);
    }
    ਲਿਖੋ("\n");

    /* break/continue tests */
    i = 0;
    ਕਰੋ {
        ਜੇ (i == 6)
            ਰੋਕੋ;
        i++;
        ਜੇ (i == 3)
            ਜਾਰੀ;
        ਲਿਖੋ("%d", i);
    } ਜਦੋਂ(1);
    ਲਿਖੋ("\n");

    ਲਈ(i = 0;i < 10;i++) {
        ਜੇ (i == 3)
            ਜਾਰੀ;
        ਲਿਖੋ("%d", i);
    }
    ਲਿਖੋ("\n");
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ typedef_and_label;

ਖਾਲੀ goto_test()
{
    ਪੂਰਨ i;
    ਸਥਿਰ ਖਾਲੀ *label_ਸਾਰਣੀ[3] = { &&label1, &&label2, &&label3 };
    ਬਣਤਰ {
        ਪੂਰਨ bla;
        /* This needs to parse as typedef, not as label.  */
        typedef_and_label : 32;
    } y = {1};

    ਲਿਖੋ("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    ਜੇ (i >= 10) 
        ਜਾਓ s_ਸਿਰਾ;
    ਲਿਖੋ("%d", i);
    i++;
    ਜਾਓ s_loop;
 s_ਸਿਰਾ:
    ਲਿਖੋ("\n");

    /* we also test computed gotos (GCC extension) */
    ਲਈ(i=0;i<3;i++) {
        ਜਾਓ *label_ਸਾਰਣੀ[i];
    label1:
        ਲਿਖੋ("label1\n");
        ਜਾਓ ਅਗਲਾ;
    label2:
        ਲਿਖੋ("label2\n");
        ਜਾਓ ਅਗਲਾ;
    label3:
        ਲਿਖੋ("label3\n");
    ਅਗਲਾ: ;
    }
}

ਗਿਣਤੀ {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ਗਿਣਤੀ test {
    E5 = 1000,
};

ਬਣਤਰ S_enum {
    ਗਿਣਤੀ {E6 = 42, E7, E8} e:8;
};

ਗਿਣਤੀ ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)0xf000 << 31) << 1,
};

ਗਿਣਤੀ { BIASU = -1U<<31 };
ਗਿਣਤੀ { BIASS = -1 << 31 };

ਸਥਿਰ ਪੂਰਨ getint(ਪੂਰਨ i)
{
  ਜੇ (i)
    ਵਾਪਸ 0;
  ਨਹੀਂਤਾਂ
    ਵਾਪਸ (ਪੂਰਨ)(-1U << 31);
}

ਖਾਲੀ enum_test()
{
    ਗਿਣਤੀ test b1;
    /* The following should give no warning */
    ਬਿਨਾਨਿਸ਼ਾਨੀ *p = &b1;
    ਬਣਤਰ S_enum s = {E7};
    ਲਿਖੋ("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    ਲਿਖੋ("b1=%d\n", b1);
    ਲਿਖੋ("enum large: %ld\n", EL_large);

    ਜੇ (getint(0) == BIASU)
      ਲਿਖੋ("enum unsigned: ok\n");
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ("enum unsigned: wrong\n");
    ਜੇ (getint(0) == BIASS)
      ਲਿਖੋ("enum unsigned: ok\n");
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ("enum unsigned: wrong\n");
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ *my_ptr;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ mytype1;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ mytype2;

ਖਾਲੀ typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    ਪੂਰਨ b;

    a = &b;
    *a = 1234;
    ਲਿਖੋ("a=%d\n", *a);
    mytype2 = 2;
    ਲਿਖੋ("mytype2=%d\n", mytype2);
}

ਖਾਲੀ forward_test()
{
    forward_ref();
    forward_ref();
}


ਖਾਲੀ forward_ref(ਖਾਲੀ)
{
    ਲਿਖੋ("forward ok\n");
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ struct1 {
    ਪੂਰਨ f1;
    ਪੂਰਨ f2, f3;
    ਸੰਘ union1 {
        ਪੂਰਨ v1;
        ਪੂਰਨ v2;
    } u;
    ਅੱਖਰ str[3];
} struct1;

ਬਣਤਰ struct2 {
    ਪੂਰਨ a;
    ਅੱਖਰ b;
};

ਸੰਘ union2 {
    ਪੂਰਨ w1;
    ਪੂਰਨ w2;
};

ਬਣਤਰ struct1 st1, st2;

ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ_mem {
    /* nothing */ ;
    ਪੂਰਨ x;
};

ਪੂਰਨ tab[3];
ਪੂਰਨ tab2[3][2];

ਪੂਰਨ g;

ਖਾਲੀ f1(ਪੂਰਨ g)
{
    ਲਿਖੋ("g1=%d\n", g);
}

ਖਾਲੀ scope_test()
{
    g = 2;
    f1(1);
    ਲਿਖੋ("g2=%d\n", g);
    {
        ਪੂਰਨ g;
        g = 3;
        ਲਿਖੋ("g3=%d\n", g);
        {
            ਪੂਰਨ g;
            g = 4;
            ਲਿਖੋ("g4=%d\n", g);
        }
    }
    ਲਿਖੋ("g5=%d\n", g);
}

ਪੂਰਨ st2_i;
ਪੂਰਨ *st2_p = &st2_i;
ਖਾਲੀ scope2_test()
{
    ਅੱਖਰ a[50];
    st2_i = 42;
    ਲਈ (ਪੂਰਨ st2_i = 1; st2_i < 10; st2_i++) {
        ਬਾਹਰੀ ਪੂਰਨ st2_i;
        st2_i++;
        ਲਿਖੋ("exloc: %d\n", st2_i);
    }
    ਲਿਖੋ("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
ਬਾਹਰੀ ਪੂਰਨ st_global1;
ਪੂਰਨ st_global1=42;
ਬਾਹਰੀ ਪੂਰਨ st_global1;
ਪੂਰਨ st_global1;
ਬਾਹਰੀ ਪੂਰਨ st_global2;
ਪੂਰਨ st_global2;
ਬਾਹਰੀ ਪੂਰਨ st_global2;
ਪੂਰਨ st_global2;

ਖਾਲੀ array_test()
{
    ਪੂਰਨ i, j, a[4];

    ਲਿਖੋ("sizeof(a) = %d\n", ਆਕਾਰ(a));
    ਲਿਖੋ("sizeof(\"a\") = %d\n", ਆਕਾਰ("a"));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ C99_MACROS
    ਲਿਖੋ("sizeof(__func__) = %d\n", ਆਕਾਰ(__func__));
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("sizeof tab %d\n", ਆਕਾਰ(tab));
    ਲਿਖੋ("sizeof tab2 %d\n", ਆਕਾਰ tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    ਲਿਖੋ("%d %d %d\n", tab[0], tab[1], tab[2]);
    ਲਈ(i=0;i<3;i++)
        ਲਈ(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    ਲਈ(i=0;i<3*2;i++) {
        ਲਿਖੋ(" %3d", ((ਪੂਰਨ *)tab2)[i]);
    }
    ਲਿਖੋ("\n");
    ਲਿਖੋ("sizeof(size_t)=%d\n", ਆਕਾਰ(ਮਾਪ_t));
    ਲਿਖੋ("sizeof(ptrdiff_t)=%d\n", ਆਕਾਰ(ptrdiff_t));
}

ਖਾਲੀ ਵਿਅੰਜਕ_test()
{
    ਪੂਰਨ a, b;
    a = 0;
    ਲਿਖੋ("%d\n", a += 1);
    ਲਿਖੋ("%d\n", a -= 2);
    ਲਿਖੋ("%d\n", a *= 31232132);
    ਲਿਖੋ("%d\n", a /= 4);
    ਲਿਖੋ("%d\n", a %= 20);
    ਲਿਖੋ("%d\n", a &= 6);
    ਲਿਖੋ("%d\n", a ^= 7);
    ਲਿਖੋ("%d\n", a |= 8);
    ਲਿਖੋ("%d\n", a >>= 3);
    ਲਿਖੋ("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    ਲਿਖੋ("%d\n", a + 1);
    ਲਿਖੋ("%d\n", a - 2);
    ਲਿਖੋ("%d\n", a * 312);
    ਲਿਖੋ("%d\n", a / 4);
    ਲਿਖੋ("%d\n", b / 4);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)b / 4);
    ਲਿਖੋ("%d\n", a % 20);
    ਲਿਖੋ("%d\n", b % 20);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)b % 20);
    ਲਿਖੋ("%d\n", a & 6);
    ਲਿਖੋ("%d\n", a ^ 7);
    ਲਿਖੋ("%d\n", a | 8);
    ਲਿਖੋ("%d\n", a >> 3);
    ਲਿਖੋ("%d\n", b >> 3);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)b >> 3);
    ਲਿਖੋ("%d\n", a << 4);
    ਲਿਖੋ("%d\n", ~a);
    ਲਿਖੋ("%d\n", -a);
    ਲਿਖੋ("%d\n", +a);

    ਲਿਖੋ("%d\n", 12 + 1);
    ਲਿਖੋ("%d\n", 12 - 2);
    ਲਿਖੋ("%d\n", 12 * 312);
    ਲਿਖੋ("%d\n", 12 / 4);
    ਲਿਖੋ("%d\n", 12 % 20);
    ਲਿਖੋ("%d\n", 12 & 6);
    ਲਿਖੋ("%d\n", 12 ^ 7);
    ਲਿਖੋ("%d\n", 12 | 8);
    ਲਿਖੋ("%d\n", 12 >> 2);
    ਲਿਖੋ("%d\n", 12 << 4);
    ਲਿਖੋ("%d\n", ~12);
    ਲਿਖੋ("%d\n", -12);
    ਲਿਖੋ("%d\n", +12);
    ਲਿਖੋ("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

ਪੂਰਨ isid(ਪੂਰਨ c)
{
    ਵਾਪਸ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

ਪੂਰਨ vstack[10], *vstack_ptr;

ਖਾਲੀ vpush(ਪੂਰਨ vt, ਪੂਰਨ vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

ਖਾਲੀ vpop(ਪੂਰਨ *ft, ਪੂਰਨ *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

ਖਾਲੀ expr2_test()
{
    ਪੂਰਨ a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    ਲਿਖੋ("res= %d %d\n", a, b);
}

ਪੂਰਨ const_len_ar[ਆਕਾਰ(1/0)]; /* div-by-zero, but in unevaluated context */

ਖਾਲੀ constant_ਵਿਅੰਜਕ_test()
{
    ਪੂਰਨ a;
    a = 3;
    ਲਿਖੋ("%d\n", a * 16);
    ਲਿਖੋ("%d\n", a * 1);
    ਲਿਖੋ("%d\n", a + 0);
    ਲਿਖੋ("%d\n", ਆਕਾਰ(const_len_ar));
}

ਪੂਰਨ tab4[10];

ਖਾਲੀ ਵਿਅੰਜਕ_ptr_test()
{
    ਪੂਰਨ arr[10], *p, *q;
    ਪੂਰਨ i = -1;

    p = tab4;
    q = tab4 + 10;
    ਲਿਖੋ("diff=%d\n", q - p);
    p++;
    ਲਿਖੋ("inc=%d\n", p - tab4);
    p--;
    ਲਿਖੋ("dec=%d\n", p - tab4);
    ++p;
    ਲਿਖੋ("inc=%d\n", p - tab4);
    --p;
    ਲਿਖੋ("dec=%d\n", p - tab4);
    ਲਿਖੋ("add=%d\n", p + 3 - tab4);
    ਲਿਖੋ("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    ਲਿਖੋ("%p %p %ld\n", q, p, p-q);
    ਲਿਖੋ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    ਲਿਖੋ("%p %p %ld\n", q, p, p-q);
    ਲਿਖੋ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (ਪੂਰਨ *)((ਅੱਖਰ *)p + 0xf0000000);
    ਲਿਖੋ("%p %p %ld\n", q, p, p-q);
    ਲਿਖੋ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    ਲਿਖੋ("%p %p %ld\n", q, p, p-q);
    ਲਿਖੋ("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ਬਣਤਰ size12 {
            ਪੂਰਨ i, j, k;
        };
        ਬਣਤਰ size12 s[2], *sp = s;
        ਪੂਰਨ i, j;
        sp->i = 42;
        sp++;
        j = -1;
        ਲਿਖੋ("%d\n", sp[j].i);
    }
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __LP64__
    i = 1;
    p = (ਪੂਰਨ*)0x100000000UL + i;
    i = ((ਲੰਮਾ)p) >> 32;
    ਲਿਖੋ("largeptr: %p %d\n", p, i);
#ਜੇ_ਅੰਤ
    p = &arr[0];
    q = p + 3;
    ਲਿਖੋ ("%d\n", (ਪੂਰਨ)((p - q) / 3));
}

ਖਾਲੀ ਵਿਅੰਜਕ_cmp_test()
{
    ਪੂਰਨ a, b;
    a = -1;
    b = 1;
    ਲਿਖੋ("%d\n", a == a);
    ਲਿਖੋ("%d\n", a != a);

    ਲਿਖੋ("%d\n", a < b);
    ਲਿਖੋ("%d\n", a <= b);
    ਲਿਖੋ("%d\n", a <= a);
    ਲਿਖੋ("%d\n", b >= a);
    ਲਿਖੋ("%d\n", a >= a);
    ਲਿਖੋ("%d\n", b > a);

    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)a < b);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)a <= b);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)a <= a);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)b >= a);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)a >= a);
    ਲਿਖੋ("%d\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ)b > a);
}

ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ {
};

ਬਣਤਰ aligntest1 {
    ਅੱਖਰ a[10];
};

ਬਣਤਰ aligntest2 {
    ਪੂਰਨ a;
    ਅੱਖਰ b[10];
};

ਬਣਤਰ aligntest3 {
    ਦੁੱਗਣਾ a, b;
};

ਬਣਤਰ aligntest4 {
    ਦੁੱਗਣਾ a[0];
};

ਬਣਤਰ __attribute__((aligned(16))) aligntest5
{
    ਪੂਰਨ i;
};
ਬਣਤਰ aligntest6
{
    ਪੂਰਨ i;
} __attribute__((aligned(16)));
ਬਣਤਰ aligntest7
{
    ਪੂਰਨ i;
};
ਬਣਤਰ aligntest5 altest5[2];
ਬਣਤਰ aligntest6 altest6[2];
ਪੂਰਨ pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ਬਣਤਰ aligntest7 altest7[2] __attribute__((aligned(16)));

ਬਣਤਰ aligntest8
{
  ਪੂਰਨ i;
} __attribute__((aligned(4096)));

ਬਣਤਰ Large {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ flags;
    ਸੰਘ {
	ਖਾਲੀ *u1;
	ਪੂਰਨ *u2;
    };

    ਬਣਤਰ {
	ਸੰਘ {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਸੂਚਕਾਂਕ;
	    ਖਾਲੀ *freelist;
	};
	ਸੰਘ {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ counters;
	    ਬਣਤਰ {
		ਪੂਰਨ bla;
	    };
	};
    };

    ਸੰਘ {
	ਬਣਤਰ {
	    ਲੰਮਾ u3;
	    ਲੰਮਾ u4;
	};
	ਖਾਲੀ *u5;
	ਬਣਤਰ {
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ compound_ਸਿਰ;
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ compound_dtor;
	    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ compound_ਕ੍ਰਮ;
	};
    };
} __attribute__((aligned(2 * ਆਕਾਰ(ਲੰਮਾ))));

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ __attribute__((aligned(4))) unaligned_u64;

ਬਣਤਰ aligntest9 {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ buf_nr;
    unaligned_u64 ਸ਼ੁਰੂ_lba;
};

ਬਣਤਰ aligntest10 {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ buf_nr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਸ਼ੁਰੂ_lba;
};

ਖਾਲੀ struct_test()
{
    struct1 *s;
    ਸੰਘ union2 u;
    ਬਣਤਰ Large ls;

    ਲਿਖੋ("sizes: %d %d %d %d\n",
           ਆਕਾਰ(ਬਣਤਰ struct1),
           ਆਕਾਰ(ਬਣਤਰ struct2),
           ਆਕਾਰ(ਸੰਘ union1),
           ਆਕਾਰ(ਸੰਘ union2));
    ਲਿਖੋ("offsets: %d\n", (ਪੂਰਨ)((ਅੱਖਰ*)&st1.u.v1 - (ਅੱਖਰ*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    ਲਿਖੋ("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    ਲਿਖੋ("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    ਲਿਖੋ("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    ਲਿਖੋ("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    ਲਿਖੋ("str_addr=%x\n", (ਪੂਰਨ)(uintptr_t)st1.str - (ਪੂਰਨ)(uintptr_t)&st1.f1);

    /* align / size tests */
    ਲਿਖੋ("aligntest1 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest1), __alignof__(ਬਣਤਰ aligntest1));
    ਲਿਖੋ("aligntest2 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest2), __alignof__(ਬਣਤਰ aligntest2));
    ਲਿਖੋ("aligntest3 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest3), __alignof__(ਬਣਤਰ aligntest3));
#ਜੇ !(defined _WIN32 && CC_NAME == CC_clang)
    ਲਿਖੋ("aligntest4 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest4), __alignof__(ਬਣਤਰ aligntest4));
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("aligntest5 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest5), __alignof__(ਬਣਤਰ aligntest5));
    ਲਿਖੋ("aligntest6 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest6), __alignof__(ਬਣਤਰ aligntest6));
    ਲਿਖੋ("aligntest7 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest7), __alignof__(ਬਣਤਰ aligntest7));
    ਲਿਖੋ("aligntest8 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest8), __alignof__(ਬਣਤਰ aligntest8));
#ਜੇ !(defined _WIN32 && CC_NAME == CC_clang)
    ਲਿਖੋ("aligntest9 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest9), __alignof__(ਬਣਤਰ aligntest9));
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("aligntest10 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(ਬਣਤਰ aligntest10), __alignof__(ਬਣਤਰ aligntest10));
    ਲਿਖੋ("altest5 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(altest5), __alignof__(altest5));
    ਲਿਖੋ("altest6 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(altest6), __alignof__(altest6));
    ਲਿਖੋ("altest7 sizeof=%d alignof=%d\n",
           ਆਕਾਰ(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ਜੇ !(defined _WIN32 && CC_NAME == CC_clang)
    ਲਿਖੋ("sizeof(struct empty) = %d\n", ਆਕਾਰ(ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ));
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("alignof(struct empty) = %d\n", __alignof__(ਬਣਤਰ ਖਾਲੀ_ਥਾਵਾਂ));

    ਲਿਖੋ("Large: sizeof=%d\n", ਆਕਾਰ(ls));
    memset(&ls, 0, ਆਕਾਰ(ls));
    ls.compound_ਸਿਰ = 42;
    ਲਿਖੋ("Large: offsetof(compound_head)=%d\n", (ਪੂਰਨ)((ਅੱਖਰ*)&ls.compound_ਸਿਰ - (ਅੱਖਰ*)&ls));
}

/* simulate char/short return value with undefined upper bits */
ਸਥਿਰ ਪੂਰਨ __csf(ਪੂਰਨ x) { ਵਾਪਸ x; }
ਸਥਿਰ ਖਾਲੀ *_csf = __csf;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ csf(t,n) ((t(*)(ਪੂਰਨ))_csf)(n)

/* XXX: depend on endianness */
ਖਾਲੀ char_short_test()
{
    ਪੂਰਨ var1, var2;
    ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ var3;
    ਲੰਮਾ ਲੰਮਾ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    ਲਿਖੋ("s8=%d %d\n", 
           *(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ *)&var1, *(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ *)&var2);
    ਲਿਖੋ("u8=%d %d\n", 
           *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)&var1, *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)&var2);
    ਲਿਖੋ("s16=%d %d\n", 
           *(ਛੋਟਾ *)&var1, *(ਛੋਟਾ *)&var2);
    ਲਿਖੋ("u16=%d %d\n", 
           *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *)&var1, *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *)&var2);
    ਲਿਖੋ("s32=%d %d\n", 
           *(ਪੂਰਨ *)&var1, *(ਪੂਰਨ *)&var2);
    ਲਿਖੋ("u32=%d %d\n", 
           *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *)&var1, *(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *)&var2);
    *(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ *)&var1 = 0x08;
    ਲਿਖੋ("var1=%x\n", var1);
    *(ਛੋਟਾ *)&var1 = 0x0809;
    ਲਿਖੋ("var1=%x\n", var1);
    *(ਪੂਰਨ *)&var1 = 0x08090a0b;
    ਲਿਖੋ("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    ਲਿਖੋ("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    ਲਿਖੋ("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    ਲਿਖੋ("promote char/short cast VA %d %d\n", (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)(var1 + 1), (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)(var4 + 1));
#ਜੇ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ,0x89898989);
    var4 = csf(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ,0xabababab);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    ਲਿਖੋ("promote char/short fumcret VA %d %d %d %d\n",
        csf(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,0xcdcdcdcd),
        csf(ਛੋਟਾ,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#ਜੇ_ਅੰਤ
    var3 = -10;
    var1 = (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(var3 + 1);
    var4 = (ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(var3 + 1);
    ਲਿਖੋ("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (ਬਿਨਾਨਿਸ਼ਾਨੀ)(ਪੂਰਨ)(var4 + 1);
    ਲਿਖੋ("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (ਬਿਨਾਨਿਸ਼ਾਨੀ)(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)(var4 + 1);
    ਲਿਖੋ("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Sym {
    ਪੂਰਨ v;
    ਪੂਰਨ t;
    ਪੂਰਨ c;
    ਬਣਤਰ Sym *ਅਗਲਾ;
    ਬਣਤਰ Sym *prev;
} Sym;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

ਸਥਿਰ ਪੂਰਨ toupper1(ਪੂਰਨ a)
{
    ਵਾਪਸ TOUPPER(a);
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ calc_vm_flags(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ prot)
{
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ prot_ਬਿੱਟ;
  /* This used to segfault in some revisions: */
  prot_ਬਿੱਟ = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ਵਾਪਸ prot_ਬਿੱਟ;
}

ਗਿਣਤੀ cast_enum { ਪਹਿਲਾ_2, ਆਖਰੀ_2 };

ਸਥਿਰ ਖਾਲੀ tst_cast(ਗਿਣਤੀ cast_enum ce)
{
    ਲਿਖੋ("%d\n", ce);
}

ਖਾਲੀ bool_test()
{
    ਪੂਰਨ *s, a, b, t, f, i;

    a = 0;
    s = (ਖਾਲੀ*)0;
    ਲਿਖੋ("!s=%d\n", !s);

    ਜੇ (!s || !s[0])
        a = 1;
    ਲਿਖੋ("a=%d\n", a);

    ਲਿਖੋ("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    ਲਿਖੋ("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    ਲਿਖੋ("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ਜੇ 1 && 1
    ਲਿਖੋ("a1\n");
#ਜੇ_ਅੰਤ
#ਜੇ 1 || 0
    ਲਿਖੋ("a2\n");
#ਜੇ_ਅੰਤ
#ਜੇ 1 ? 0 : 1
    ਲਿਖੋ("a3\n");
#ਜੇ_ਅੰਤ
#ਜੇ 0 ? 0 : 1
    ਲਿਖੋ("a4\n");
#ਜੇ_ਅੰਤ

    a = 4;
    ਲਿਖੋ("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    ਲਿਖੋ("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    ਲਿਖੋ("exp=%d\n", f == (32 <= a && a <= 3));
    ਲਿਖੋ("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    ਲਿਖੋ("type of bool: %d\n", (ਪੂਰਨ) ( (~ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ) (t && 1))) / 2) );
    tst_cast(t >= 0 ? ਪਹਿਲਾ_2 : ਆਖਰੀ_2);

    ਲਿਖੋ("type of cond: %d\n", (~(t ? 0U : (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ)0)) / 2 );
    /* test ? : cast */
    {
        ਪੂਰਨ aspect_on;
        ਪੂਰਨ aspect_native = 65536;
        ਦੁੱਗਣਾ bfu_aspect = 1.0;
        ਪੂਰਨ aspect;
        ਲਈ(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            ਲਿਖੋ("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        ਸਥਿਰ ਪੂਰਨ v1 = 34 ? : -1; /* constant case */
        ਸਥਿਰ ਪੂਰਨ v2 = 0 ? : -1; /* constant case */
        ਪੂਰਨ a = 30;
        
        ਲਿਖੋ("%d %d\n", v1, v2);
        ਲਿਖੋ("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    ਲਈ(i=0;i<256;i++) {
        ਜੇ (toupper1 (i) != TOUPPER (i))
            ਲਿਖੋ("error %d\n", i);
    }
    ਲਿਖੋ ("bits = 0x%x\n", calc_vm_flags (0x1));
}

ਬਾਹਰੀ ਪੂਰਨ undefined_function(ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ defined_function(ਖਾਲੀ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
ਪੂਰਨ undefined_function(ਖਾਲੀ) {}
#ਜੇ_ਅੰਤ

ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ refer_ਮੰਜ਼ਿਲ_undefined(ਖਾਲੀ)
{
  undefined_function();
}

ਖਾਲੀ optimize_ਬਾਹਰਲਾ_test(ਖਾਲੀ)
{
  ਪੂਰਨ i = 0 ? undefined_function() : defined_function();
  ਲਿਖੋ ("oo:%d\n", i);
  ਪੂਰਨ j = 1 ? defined_function() : undefined_function();
  ਲਿਖੋ ("oo:%d\n", j);
  ਜੇ (0)
    ਲਿਖੋ("oo:%d\n", undefined_function());
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ("oo:%d\n", defined_function());
  ਜੇ (1)
    ਲਿਖੋ("oo:%d\n", defined_function());
  ਨਹੀਂਤਾਂ
    ਲਿਖੋ("oo:%d\n", undefined_function());
  ਜਦੋਂ (1) {
      ਲਿਖੋ("oow:%d\n", defined_function());
      ਰੋਕੋ;
      ਲਿਖੋ("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  ਚੋਣ (j)
    ਹਾਲਤ 1: ਰੋਕੋ;
  ਲਿਖੋ ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ਜਦੋਂ (1)
    ਰੋਕੋ;
  ਲਿਖੋ ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  ਕਰੋ
    ਰੋਕੋ;
  ਜਦੋਂ (1);
  ਲਿਖੋ ("ool2:%d\n", defined_function());
  ਲਈ (;;)
    ਰੋਕੋ;
  ਲਿਖੋ ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ਜਦੋਂ (1) {
	{
	  ਰੋਕੋ;
	}
      ਲਿਖੋ ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ਜਦੋਂ (j) {
      ਜੇ (j == 0)
	ਰੋਕੋ; /* this break shouldn't disable code outside the if. */
      ਲਿਖੋ("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ਜਦੋਂ (j) {
      ਜੇ (1)
	j--;
      ਨਹੀਂਤਾਂ
	breakhere: ਰੋਕੋ;
      ਲਿਖੋ("ool6:%d\n", defined_function());
      ਜਾਓ breakhere;
  }
  j = 1;
  ਜਦੋਂ (j) {
      j--;
      ਜਾਰੀ;
      ਲਿਖੋ("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ਜੇ (0 && undefined_function())
    undefined_function();
  ਜੇ (defined_function() && 0)
    undefined_function();
  ਜੇ (0 && 0)
    undefined_function();
  ਜੇ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ਜੇ (1 || undefined_function())
    ;
  ਨਹੀਂਤਾਂ
    undefined_function();
  ਜੇ (defined_function() || 1)
    ;
  ਨਹੀਂਤਾਂ
    undefined_function();
  ਜੇ (1 || 1)
    ;
  ਨਹੀਂਤਾਂ
    undefined_function();
  ਜੇ (defined_function() || 1 || undefined_function())
    ;
  ਨਹੀਂਤਾਂ
    undefined_function();

  ਜੇ (defined_function() && 0)
    refer_ਮੰਜ਼ਿਲ_undefined();

  ਜੇ (0) {
      (ਖਾਲੀ)ਆਕਾਰ( ({
		     ਕਰੋ { } ਜਦੋਂ (0);
		     0;
		     }) );
      undefined_function();
  }

  ਜੇ (0) {
      ਚੋਣ (defined_function()) {
          ਹਾਲਤ 0: undefined_function(); ਰੋਕੋ;
          ਮੂਲ: undefined_function(); ਰੋਕੋ;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ਜੇ (1)
    ਵਾਪਸ;
  ਲਿਖੋ ("oor:%d\n", undefined_function());
}

ਪੂਰਨ defined_function(ਖਾਲੀ)
{
  ਸਥਿਰ ਪੂਰਨ i = 40;
  ਵਾਪਸ i++;
}

/* GCC accepts that */
ਸਥਿਰ ਪੂਰਨ tab_reinit[];
ਸਥਿਰ ਪੂਰਨ tab_reinit[10];

ਸਥਿਰ ਪੂਰਨ tentative_ar[];
ਸਥਿਰ ਪੂਰਨ tentative_ar[] = {1,2,3};

ਪੂਰਨ cinit1; /* a global variable can be defined several times without error ! */
ਪੂਰਨ cinit1; 
ਪੂਰਨ cinit1 = 0;
ਪੂਰਨ *cinit2 = (ਪੂਰਨ []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
ਅੱਖਰ ਅਚਲ * ਅਚਲ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
ਖਾਲੀ *cinit52 = &(ਖਾਲੀ*){ (ਖਾਲੀ*) 52 };

#ਜੇ __TINYC__ || __GNUC__ >= 6
ਪੂਰਨ cinit4 = (ਪੂਰਨ){44};
ਖਾਲੀ *cinit51 = (ਖਾਲੀ*){ (ਖਾਲੀ*) 51 };
ਬਣਤਰ _c6 { ਪੂਰਨ a,b; } cinit6 = (ਬਣਤਰ _c6){61,62}, *cinit7 = &(ਬਣਤਰ _c6){71,72};
#ਨਹੀਂਤਾਂ
ਪੂਰਨ cinit4 = 44;
ਖਾਲੀ *cinit51 = (ਖਾਲੀ*)51;
ਬਣਤਰ _c6 { ਪੂਰਨ a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#ਜੇ_ਅੰਤ

ਖਾਲੀ compound_literal_test(ਖਾਲੀ)
{
    ਪੂਰਨ *p, i;
    ਅੱਖਰ *q, *q3;

    ਲਿਖੋ("cinit3 : %s\n", cinit3);
    ਲਿਖੋ("cinit4 : %d\n", cinit4);
    ਲਿਖੋ("cinit51 : %d\n", (ਪੂਰਨ)cinit51);
    ਲਿਖੋ("cinit52 : %d\n", *(ਪੂਰਨ*)cinit52);
    ਲਿਖੋ("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    ਲਿਖੋ("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    ਲਿਖੋ("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (ਪੂਰਨ []){1, 2, 3};
    ਲਈ(i=0;i<3;i++)
        ਲਿਖੋ(" %d", p[i]);
    ਲਿਖੋ("\n");

    ਲਈ(i=0;i<3;i++)
        ਲਿਖੋ("%d", cinit2[i]);
    ਲਿਖੋ("\n");

    q = "tralala1";
    ਲਿਖੋ("q1=%s\n", q);

    q = (ਅੱਖਰ *){ "tralala2" };
    ਲਿਖੋ("q2=%s\n", q);

    q3 = (ਅੱਖਰ *){ q };
    ਲਿਖੋ("q3=%s\n", q3);

    q = (ਅੱਖਰ []){ "tralala3" };
    ਲਿਖੋ("q4=%s\n", q);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ALL_ISOC99
    p = (ਪੂਰਨ []){1, 2, cinit1 + 3};
    ਲਈ(i=0;i<3;i++)
        ਲਿਖੋ(" %d", p[i]);
    ਲਿਖੋ("\n");

    ਲਈ(i=0;i<3;i++) {
        p = (ਪੂਰਨ []){1, 2, 4 + i};
        ਲਿਖੋ("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#ਜੇ_ਅੰਤ
}


#ਜੇ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ਵਾਪਸ a + b;
}

ਪੂਰਨ kr_func2(a, b)
{
    ਵਾਪਸ a + b;
}

kr_test()
{
    ਲਿਖੋ("func1=%d\n", kr_func1(3, 4));
    ਲਿਖੋ("func2=%d\n", kr_func2(3, 4));
    ਵਾਪਸ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
ਅੱਖਰ invalid_function_def()[] {ਵਾਪਸ 0;}

#ਨਹੀਂਤਾਂ
# define kr_test() ਲਿਖੋ("func1=7\nfunc2=7\n")
#ਜੇ_ਅੰਤ

ਖਾਲੀ ਅੰਕ(ਪੂਰਨ n)
{
    ਅੱਖਰ *tab, *p;
    tab = (ਅੱਖਰ*)ਸਮ੍ਰਿਤੀ_ਦਿਓ(20); 
    p = tab;
    ਜਦੋਂ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ਜੇ (n == 0)
            ਰੋਕੋ;
    }
    ਜਦੋਂ (p != tab) {
        p--;
        ਲਿਖੋ("%c", *p);
    }
    ਲਿਖੋ("\n");
    ਮੁਕਤ(tab);
}

/* structure assignment tests */
ਬਣਤਰ structa1 {
    ਪੂਰਨ f1;
    ਅੱਖਰ f2;
};

ਖਾਲੀ struct_ਸੌਂਪੋ_test1(ਬਣਤਰ structa1 s1, ਪੂਰਨ t, ਦਸ਼ਮਲਵ f)
{
    ਲਿਖੋ("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ਬਣਤਰ structa1 struct_ਸੌਂਪੋ_test2(ਬਣਤਰ structa1 s1, ਪੂਰਨ t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ਵਾਪਸ s1;
}

ਖਾਲੀ struct_ਸੌਂਪੋ_test(ਖਾਲੀ)
{
    ਬਣਤਰ S {
      ਬਣਤਰ structa1 lsta1, lsta2;
      ਪੂਰਨ i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_ਸੌਂਪੋ_test1(ps->lsta2, 3, 4.5);
    ਲਿਖੋ("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_ਸੌਂਪੋ_test2(ps->lsta2, ps->i);
    ਲਿਖੋ("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    ਸਥਿਰ ਬਣਤਰ {
        ਖਾਲੀ (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_ਸੌਂਪੋ_test }
    };
    ਲਿਖੋ("%d\n", struct_ਸੌਂਪੋ_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_ਸੌਂਪੋ_test2(s.lsta1, 1);
    ਲਿਖੋ("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

ਖਾਲੀ cast1(ਅੱਖਰ a, ਛੋਟਾ b, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c, ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ d)
{
    ਲਿਖੋ("%d %d %d %d\n", a, b, c, d);
}

ਅੱਖਰ bcast;
ਛੋਟਾ scast;

ਖਾਲੀ cast_test()
{
    ਪੂਰਨ a;
    ਅੱਖਰ c;
    ਅੱਖਰ tab[10];
    ਬਿਨਾਨਿਸ਼ਾਨੀ b,d;
    ਛੋਟਾ s;
    ਅੱਖਰ *p = ਨਿਰਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    ਲਿਖੋ("%d %d %d %d\n",
           (ਅੱਖਰ)(a + 1),
           (ਛੋਟਾ)(a + 1),
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)(a + 1),
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)(a + 1));
    ਲਿਖੋ("%d %d %d %d\n",
           (ਅੱਖਰ)0xfffff,
           (ਛੋਟਾ)0xfffff,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)0xfffff,
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)0xfffff);

    a = (bcast = 128) + 1;
    ਲਿਖੋ("%d\n", a);
    a = (scast = 65536) + 1;
    ਲਿਖੋ("%d\n", a);
    
    ਲਿਖੋ("sizeof(c) = %d, sizeof((int)c) = %d\n", ਆਕਾਰ(c), ਆਕਾਰ((ਪੂਰਨ)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (ਛੋਟਾ)b;
    ਲਿਖੋ("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (ਅੱਖਰ)b;
    ਲਿਖੋ("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    ਲਿਖੋ("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    ਲਿਖੋ("sizeof(+(char)'a') = %d\n", ਆਕਾਰ(+(ਅੱਖਰ)'a'));
    ਲਿਖੋ("sizeof(-(char)'a') = %d\n", ਆਕਾਰ(-(ਅੱਖਰ)'a'));
    ਲਿਖੋ("sizeof(~(char)'a') = %d\n", ਆਕਾਰ(-(ਅੱਖਰ)'a'));

#ਜੇ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    ਲਿਖੋ("%d %d %ld %ld %lld %lld\n",
           (ਪੂਰਨ)p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ)p,
           (ਲੰਮਾ)p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)p,
           (ਲੰਮਾ ਲੰਮਾ)p, (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)p);
#ਜੇ_ਅੰਤ

    /* from integers to pointers */
    ਲਿਖੋ("%p %p %p %p\n",
           (ਖਾਲੀ *)a, (ਖਾਲੀ *)b, (ਖਾਲੀ *)c, (ਖਾਲੀ *)d);

    /* int to int with sign set */
    ਲਿਖੋ("0x%lx\n", (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)(ਪੂਰਨ)ul);
}

/* initializers tests */
ਬਣਤਰ structinit1 {
    ਪੂਰਨ f1;
    ਅੱਖਰ f2;
    ਛੋਟਾ f3;
    ਪੂਰਨ farray[3];
};

ਪੂਰਨ sinit1 = 2;
ਪੂਰਨ sinit2 = { 3 };
ਪੂਰਨ sinit3[3] = { 1, 2, {3}, };
ਪੂਰਨ sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
ਪੂਰਨ sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
ਪੂਰਨ sinit6[] = { 1, 2, 3 };
ਪੂਰਨ sinit7[] = { [2] = 3, [0] = 1, 2 };
ਅੱਖਰ sinit8[] = "hello" "trala";

ਬਣਤਰ structinit1 sinit9 = { 1, 2, 3 };
ਬਣਤਰ structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ਬਣਤਰ structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#ਜੇ_ਅੰਤ
};

ਅੱਖਰ *sinit12 = "hello world";
ਅੱਖਰ *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
ਅੱਖਰ sinit14[10] = { "abc" };
ਪੂਰਨ sinit15[3] = { ਆਕਾਰ(sinit15), 1, 2 };

ਬਣਤਰ { ਪੂਰਨ a[3], b; } sinit16[] = { { 1 }, 2 };

ਬਣਤਰ bar {
        ਅੱਖਰ *s;
        ਪੂਰਨ len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

ਪੂਰਨ sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ਬਣਤਰ complexinit0 {
    ਪੂਰਨ a;
    ਪੂਰਨ b;
};

ਬਣਤਰ complexinit {
    ਪੂਰਨ a;
    ਅਚਲ ਬਣਤਰ complexinit0 *b;
};

ਅਚਲ ਸਥਿਰ ਬਣਤਰ complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (ਅਚਲ ਬਣਤਰ complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ਬਣਤਰ complexinit2 {
	ਪੂਰਨ a;
	ਪੂਰਨ b[];
};

ਬਣਤਰ complexinit2 cix20;

ਬਣਤਰ complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ਬਣਤਰ complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
ਪੂਰਨ sinit23[2] = { "astring" ? ਆਕਾਰ("astring") : -1,
		   &sinit23 ? 42 : -1 };

ਪੂਰਨ sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ਬਣਤਰ bf_SS {ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਦੋਆਧਾਰੀ_ਅੰਕ:1,bits31:31; };
ਬਣਤਰ bf_SS bf_init = { .ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
ਬਣਤਰ bfn_SS {ਪੂਰਨ a,b; ਬਣਤਰ bf_SS c; ਪੂਰਨ d,e; };
ਬਣਤਰ bfn_SS bfn_init = { .c.ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
ਬਣਤਰ bfa_SS {ਪੂਰਨ a,b; ਬਣਤਰ bf_SS c[3]; ਪੂਰਨ d,e; };
ਬਣਤਰ bfa_SS bfa_init = { .c[1].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
ਬਣਤਰ bf_SS bfaa_init[3] = { [1].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
ਬਣਤਰ bf_SS bfaa_vinit[] = { [2].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
ਬਣਤਰ b2_SS {ਲੰਮਾ ਲੰਮਾ ਪੂਰਨ ਖੇਤਰ : 52; ਲੰਮਾ ਲੰਮਾ ਪੂਰਨ pad : 12; };
ਬਣਤਰ b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

ਬਾਹਰੀ ਪੂਰਨ external_inited = 42;

ਖਾਲੀ init_test(ਖਾਲੀ)
{
    ਪੂਰਨ linit1 = 2;
    ਪੂਰਨ linit2 = { 3 };
    ਪੂਰਨ linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    ਪੂਰਨ linit6[] = { 1, 2, 3 };
    ਪੂਰਨ i, j;
    ਅੱਖਰ linit8[] = "hello" "trala";
    ਪੂਰਨ linit12[10] = { 1, 2 };
    ਪੂਰਨ linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    ਅੱਖਰ linit14[10] = "abc";
    ਪੂਰਨ linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ਬਣਤਰ linit16 { ਪੂਰਨ a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    ਪੂਰਨ linit17 = ਆਕਾਰ(linit17);
    ਪੂਰਨ zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    ਪੂਰਨ linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ਬਣਤਰ bf_SS bf_finit = { .ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
    ਬਣਤਰ bfn_SS bfn_finit = { .c.ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
    ਬਣਤਰ bfa_SS bfa_finit = { .c[1].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
    ਬਣਤਰ bf_SS bfaa_finit[3] = { [1].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
    ਬਣਤਰ bf_SS bfaa_fvinit[] = { [2].ਦੋਆਧਾਰੀ_ਅੰਕ = 1 };
    ਬਣਤਰ b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    ਲਿਖੋ("sinit1=%d\n", sinit1);
    ਲਿਖੋ("sinit2=%d\n", sinit2);
    ਲਿਖੋ("sinit3=%d %d %d %d\n", 
           ਆਕਾਰ(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    ਲਿਖੋ("sinit6=%d\n", ਆਕਾਰ(sinit6));
    ਲਿਖੋ("sinit7=%d %d %d %d\n", 
           ਆਕਾਰ(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    ਲਿਖੋ("sinit8=%s\n", sinit8);
    ਲਿਖੋ("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    ਲਿਖੋ("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    ਲਿਖੋ("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    ਲਈ(i=0;i<3;i++)
        ਲਈ(j=0;j<2;j++)
            ਲਿਖੋ("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    ਲਿਖੋ("linit1=%d\n", linit1);
    ਲਿਖੋ("linit2=%d\n", linit2);
    ਲਿਖੋ("linit6=%d\n", ਆਕਾਰ(linit6));
    ਲਿਖੋ("linit8=%d %s\n", ਆਕਾਰ(linit8), linit8);

    ਲਿਖੋ("sinit12=%s\n", sinit12);
    ਲਿਖੋ("sinit13=%d %s %s %s\n",
           ਆਕਾਰ(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    ਲਿਖੋ("sinit14=%s\n", sinit14);

    ਲਈ(i=0;i<10;i++) ਲਿਖੋ(" %d", linit12[i]);
    ਲਿਖੋ("\n");
    ਲਈ(i=0;i<10;i++) ਲਿਖੋ(" %d", linit13[i]);
    ਲਿਖੋ("\n");
    ਲਈ(i=0;i<10;i++) ਲਿਖੋ(" %d", linit14[i]);
    ਲਿਖੋ("\n");
    ਲਈ(i=0;i<10;i++) ਲਿਖੋ(" %d", linit15[i]);
    ਲਿਖੋ("\n");
    ਲਿਖੋ("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    ਲਿਖੋ("linit17=%d\n", linit17);
    ਲਿਖੋ("sinit15=%d\n", sinit15[0]);
    ਲਿਖੋ("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    ਲਿਖੋ("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    ਲਈ(i=0;i<10;i++)
        ਲਿਖੋ("%x ", sinit18[i]);
    ਲਿਖੋ("\n");
    /* complex init check */
    ਲਿਖੋ("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    ਲਿਖੋ("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    ਲਿਖੋ("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", ਆਕਾਰ cix20, ਆਕਾਰ cix21, ਆਕਾਰ cix22);

    ਲਿਖੋ("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    ਲਿਖੋ("arrtype2: %d %d\n", ਆਕਾਰ(sinit19), ਆਕਾਰ(sinit20));
    ਲਿਖੋ("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    ਲਿਖੋ("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    ਲਿਖੋ("arrtype5: %d %d\n", ਆਕਾਰ(sinit21), ਆਕਾਰ(sinit22));
    ਲਿਖੋ("arrtype6: %d\n", ਆਕਾਰ(arrtype2));

    ਲਿਖੋ("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    ਲਿਖੋ("sinit24=%d\n", sinit24);
    ਲਿਖੋ("linit18= %d %d\n", linit18[0], linit18[1]);
    ਲਿਖੋ ("bf1: %u %u\n", bf_init.ਦੋਆਧਾਰੀ_ਅੰਕ, bf_init.bits31);
    ਲਿਖੋ ("bf2: %u %u\n", bf_finit.ਦੋਆਧਾਰੀ_ਅੰਕ, bf_finit.bits31);
    ਲਿਖੋ ("bf3: %u %u\n", bfn_init.c.ਦੋਆਧਾਰੀ_ਅੰਕ, bfn_init.c.bits31);
    ਲਿਖੋ ("bf4: %u %u\n", bfn_finit.c.ਦੋਆਧਾਰੀ_ਅੰਕ, bfn_finit.c.bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf5[%d]: %u %u\n", i, bfa_init.c[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfa_init.c[i].bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfa_finit.c[i].bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf7[%d]: %u %u\n", i, bfaa_init[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfaa_init[i].bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf8[%d]: %u %u\n", i, bfaa_finit[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfaa_finit[i].bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfaa_vinit[i].bits31);
    ਲਈ (i = 0; i < 3; i++)
        ਲਿਖੋ ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].ਦੋਆਧਾਰੀ_ਅੰਕ, bfaa_fvinit[i].bits31);
}

ਖਾਲੀ switch_uc(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uc)
{
	ਚੋਣ (uc) {
	    ਹਾਲਤ 0xfb ... 0xfe:
		ਲਿਖੋ("ucsw:1\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 0xff:
		ਲਿਖੋ("ucsw:2\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 0 ... 5:
		ਲਿਖੋ("ucsw:3\n");
		ਰੋਕੋ;
	    ਮੂਲ:
		ਲਿਖੋ("ucsw: broken!\n");
	}
}

ਖਾਲੀ switch_sc(ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ sc)
{
	ਚੋਣ (sc) {
	    ਹਾਲਤ -5 ... -2:
		ਲਿਖੋ("scsw:1\n");
		ਰੋਕੋ;
	    ਹਾਲਤ -1:
		ਲਿਖੋ("scsw:2\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 0 ... 5:
		ਲਿਖੋ("scsw:3\n");
		ਰੋਕੋ;
	    ਮੂਲ:
		ਲਿਖੋ("scsw: broken!\n");
	}
}

ਖਾਲੀ switch_test()
{
    ਪੂਰਨ i;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ull;
    ਲੰਮਾ ਲੰਮਾ ll;

    ਲਈ(i=0;i<15;i++) {
        ਚੋਣ(i) {
        ਹਾਲਤ 0:
        ਹਾਲਤ 1:
            ਲਿਖੋ("a");
            ਰੋਕੋ;
        ਮੂਲ:
            ਲਿਖੋ("%d", i);
            ਰੋਕੋ;
        ਹਾਲਤ 8 ... 12:
            ਲਿਖੋ("c");
            ਰੋਕੋ;
        ਹਾਲਤ 3:
            ਲਿਖੋ("b");
            ਰੋਕੋ;
        ਹਾਲਤ 0xc33c6b9fU:
        ਹਾਲਤ 0x7c9eeeb9U:
            ਰੋਕੋ;
        }
    }
    ਲਿਖੋ("\n");

    ਲਈ (i = 1; i <= 5; i++) {
	ull = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)i << 61;
	ਚੋਣ (ull) {
	    ਹਾਲਤ 1ULL << 61:
		ਲਿਖੋ("ullsw:1\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 2ULL << 61:
		ਲਿਖੋ("ullsw:2\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 3ULL << 61:
		ਲਿਖੋ("ullsw:3\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 4ULL << 61:
		ਲਿਖੋ("ullsw:4\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 5ULL << 61:
		ਲਿਖੋ("ullsw:5\n");
		ਰੋਕੋ;
	    ਮੂਲ:
		ਲਿਖੋ("ullsw: broken!\n");
	}
    }

    ਲਈ (i = 1; i <= 5; i++) {
	ll = (ਲੰਮਾ ਲੰਮਾ)i << 61;
	ਚੋਣ (ll) {
	    ਹਾਲਤ 1LL << 61:
		ਲਿਖੋ("llsw:1\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 2LL << 61:
		ਲਿਖੋ("llsw:2\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 3LL << 61:
		ਲਿਖੋ("llsw:3\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 4LL << 61:
		ਲਿਖੋ("llsw:4\n");
		ਰੋਕੋ;
	    ਹਾਲਤ 5LL << 61:
		ਲਿਖੋ("llsw:5\n");
		ਰੋਕੋ;
	    ਮੂਲ:
		ਲਿਖੋ("llsw: broken!\n");
	}
    }

    ਲਈ (i = -5; i <= 5; i++) {
	switch_uc((ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ)i);
    }

    ਲਈ (i = -5; i <= 5; i++) {
	switch_sc ((ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ)i);
    }
}

/* ISOC99 _Bool type */
ਖਾਲੀ c99_bool_test(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BOOL_ISOC99
    ਪੂਰਨ a;
    _Bool b, b2;

    ਲਿਖੋ("sizeof(_Bool) = %d\n", ਆਕਾਰ(_Bool));
    a = 3;
    ਲਿਖੋ("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    ਲਿਖੋ("b = %d\n", b);
    b++;
    ਲਿਖੋ("b = %d\n", b);
    b2 = 0;
    ਲਿਖੋ("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           ਆਕਾਰ ((ਅਸਥਿਰ ਪੂਰਨ)a ? b : b2));
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ bitfield_test(ਖਾਲੀ)
{
    ਪੂਰਨ a;
    ਛੋਟਾ sa;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ca;
    ਬਣਤਰ sbf1 {
        ਪੂਰਨ f1 : 3;
        ਪੂਰਨ : 2;
        ਪੂਰਨ f2 : 1;
        ਪੂਰਨ : 0;
        ਪੂਰਨ f3 : 5;
        ਪੂਰਨ f4 : 7;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ f5 : 7;
    } st1;
    ਲਿਖੋ("sizeof(st1) = %d\n", ਆਕਾਰ(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    ਲਿਖੋ("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    ਲਿਖੋ("%d %d\n", sa, ca);

    st1.f1 = 7;
    ਜੇ (st1.f1 == -1) 
        ਲਿਖੋ("st1.f1 == -1\n");
    ਨਹੀਂਤਾਂ 
        ਲਿਖੋ("st1.f1 != -1\n");
    ਜੇ (st1.f2 == -1) 
        ਲਿਖੋ("st1.f2 == -1\n");
    ਨਹੀਂਤਾਂ 
        ਲਿਖੋ("st1.f2 != -1\n");

    ਬਣਤਰ sbf2 {
        ਲੰਮਾ ਲੰਮਾ f1 : 45;
        ਲੰਮਾ ਲੰਮਾ : 2;
        ਲੰਮਾ ਲੰਮਾ f2 : 35;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (ਲੰਮਾ ਲੰਮਾ)a << 25;
    st2.f3 = a;
    st2.f2++;
    ਲਿਖੋ("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#ਜੇ 0
    Disabled ਲਈ now until further clarification re GCC compatibility
    ਬਣਤਰ sbf3 {
        ਪੂਰਨ f1 : 7;
        ਪੂਰਨ f2 : 1;
        ਅੱਖਰ f3;
        ਪੂਰਨ f4 : 8;
        ਪੂਰਨ f5 : 1;
        ਪੂਰਨ f6 : 16;
    } st3;
    ਲਿਖੋ("sizeof(st3) = %d\n", ਆਕਾਰ(st3));
#ਜੇ_ਅੰਤ

    ਬਣਤਰ sbf4 {
	ਪੂਰਨ x : 31;
	ਅੱਖਰ y : 2;
    } st4;
    st4.y = 1;
    ਲਿਖੋ("st4.y == %d\n", st4.y);
    ਬਣਤਰ sbf5 {
	ਪੂਰਨ a;
	ਅੱਖਰ b;
	ਪੂਰਨ x : 12, y : 4, : 0, : 4, z : 3;
	ਅੱਖਰ c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    ਲਿਖੋ("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ਬਣਤਰ sbf6 {
	ਛੋਟਾ x : 12;
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ y : 2;
    } st6;
    st6.y = 1;
    ਲਿਖੋ("st6.y == %d\n", st6.y);
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOAT_FMT "%f\n"
#ਨਹੀਂਤਾਂ
/* x86's float isn't compatible with GCC */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOAT_FMT "%.5f\n"
#ਜੇ_ਅੰਤ

/* declare strto* functions as they are C99 */
ਦੁੱਗਣਾ strtod(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr);

#ਜੇ defined(_WIN32)
ਦਸ਼ਮਲਵ strtof(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr) {ਵਾਪਸ (ਦਸ਼ਮਲਵ)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr) {ਵਾਪਸ (LONG_DOUBLE)strtod(nptr, endptr);}
#ਨਹੀਂਤਾਂ
ਦਸ਼ਮਲਵ strtof(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr);
LONG_DOUBLE strtold(ਅਚਲ ਅੱਖਰ *nptr, ਅੱਖਰ **endptr);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FTEST(ਅਗੇਤਰ, typename, type, fmt)\
ਖਾਲੀ ਅਗੇਤਰ ## cmp(type a, type b)\
{\
    ਲਿਖੋ("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    ਲਿਖੋ(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    ਲਿਖੋ(fmt "\n", ++a);\
    ਲਿਖੋ(fmt "\n", a++);\
    ਲਿਖੋ(fmt "\n", a);\
    b = 0;\
    ਲਿਖੋ("%d %d\n", !a, !b);\
}\
ਖਾਲੀ ਅਗੇਤਰ ## fcast(type a)\
{\
    ਦਸ਼ਮਲਵ fa;\
    ਦੁੱਗਣਾ da;\
    LONG_DOUBLE la;\
    ਪੂਰਨ ia;\
    ਲੰਮਾ ਲੰਮਾ llia;\
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ua;\
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    ਲਿਖੋ("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (ਪੂਰਨ)a;\
    llia = (ਲੰਮਾ ਲੰਮਾ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ)a;\
    llua = (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)a;\
    ਲਿਖੋ("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    ਲਿਖੋ("itof: " fmt "\n", b);\
    b = ua;\
    ਲਿਖੋ("utof: " fmt "\n", b);\
    b = llia;\
    ਲਿਖੋ("lltof: " fmt "\n", b);\
    b = llua;\
    ਜੇ (CC_NAME != CC_clang) ਲਿਖੋ("ulltof: " fmt "\n", b);\
}\
\
ਦਸ਼ਮਲਵ ਅਗੇਤਰ ## retf(type a) { ਵਾਪਸ a; }\
ਦੁੱਗਣਾ ਅਗੇਤਰ ## retd(type a) { ਵਾਪਸ a; }\
LONG_DOUBLE ਅਗੇਤਰ ## retld(type a) { ਵਾਪਸ a; }\
\
ਖਾਲੀ ਅਗੇਤਰ ## call(ਖਾਲੀ)\
{\
    ਲਿਖੋ("float: " FLOAT_FMT, ਅਗੇਤਰ ## retf(42.123456789));\
    ਲਿਖੋ("double: %f\n", ਅਗੇਤਰ ## retd(42.123456789));\
    ਲਿਖੋ("long double: %Lf\n", ਅਗੇਤਰ ## retld(42.123456789));\
    ਲਿਖੋ("strto%s: %f\n", #prefix, (ਦੁੱਗਣਾ)strto ## ਅਗੇਤਰ("1.2", ਨਿਰਾ));\
}\
\
ਖਾਲੀ ਅਗੇਤਰ ## signed_zeros(ਖਾਲੀ) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ਜੇ (x == y)\
    ਲਿਖੋ ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ਨਹੀਂਤਾਂ\
    ਲਿਖੋ ("x != y; this is wrong!\n");\
\
  n = -x;\
  ਜੇ (x == n)\
    ਲਿਖੋ ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ਨਹੀਂਤਾਂ\
    ਲਿਖੋ ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ਜੇ (x == p)\
    ਲਿਖੋ ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ਨਹੀਂਤਾਂ\
    ਲਿਖੋ ("x != +y; this is wrong!\n");\
  p = -y;\
  ਜੇ (x == p)\
    ਲਿਖੋ ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ਨਹੀਂਤਾਂ\
    ਲਿਖੋ ("x != -y; this is wrong!\n");\
}\
ਖਾਲੀ ਅਗੇਤਰ ## nan(ਖਾਲੀ)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    ਲਿਖੋ("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
ਖਾਲੀ ਅਗੇਤਰ ## test(ਖਾਲੀ)\
{\
    ਲਿਖੋ("testing '%s'\n", #typename);\
    ਅਗੇਤਰ ## cmp(1, 2.5);\
    ਅਗੇਤਰ ## cmp(2, 1.5);\
    ਅਗੇਤਰ ## cmp(1, 1);\
    ਅਗੇਤਰ ## fcast(234.6);\
    ਅਗੇਤਰ ## fcast(-2334.6);\
    ਅਗੇਤਰ ## call();\
    ਅਗੇਤਰ ## signed_zeros();\
    ਜੇ (CC_NAME != CC_clang) ਅਗੇਤਰ ## nan();\
}

FTEST(f, ਦਸ਼ਮਲਵ, ਦਸ਼ਮਲਵ, "%f")
FTEST(d, ਦੁੱਗਣਾ, ਦੁੱਗਣਾ, "%f")
FTEST(ld, ਲੰਮਾ ਦੁੱਗਣਾ, LONG_DOUBLE, "%Lf")

ਦੁੱਗਣਾ ftab1[3] = { 1.2, 3.4, -5.6 };


ਖਾਲੀ float_test(ਖਾਲੀ)
{
#ਜੇ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    ਅਸਥਿਰ ਦਸ਼ਮਲਵ fa, fb;
    ਅਸਥਿਰ ਦੁੱਗਣਾ da, db;
    ਪੂਰਨ a;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ b;
    ਸਥਿਰ ਦੁੱਗਣਾ nan2 = 0.0/0.0;
    ਸਥਿਰ ਦੁੱਗਣਾ inf1 = 1.0/0.0;
    ਸਥਿਰ ਦੁੱਗਣਾ inf2 = 1e5000;
    ਅਸਥਿਰ LONG_DOUBLE la;

    ਲਿਖੋ("sizeof(float) = %d\n", ਆਕਾਰ(ਦਸ਼ਮਲਵ));
    ਲਿਖੋ("sizeof(double) = %d\n", ਆਕਾਰ(ਦੁੱਗਣਾ));
    ਲਿਖੋ("sizeof(long double) = %d\n", ਆਕਾਰ(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    ਲਿਖੋ("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    ਲਿਖੋ("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    ਲਿਖੋ("da=%f\n", da);
    fa = 123;
    ਲਿਖੋ("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    ਲਿਖੋ("da = %f\n", da);
    b = 4000000000;
    db = b;
    ਲਿਖੋ("db = %f\n", db);
    ਲਿਖੋ("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    ਲਿਖੋ ("da subnormal = %a\n", da);
    ਲਿਖੋ ("da subnormal = %.40g\n", da);
    ਲਿਖੋ ("la subnormal = %La\n", la);
    ਲਿਖੋ ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    ਲਿਖੋ ("da/2 subnormal = %a\n", da);
    ਲਿਖੋ ("da/2 subnormal = %.40g\n", da);
    ਲਿਖੋ ("la/2 subnormal = %La\n", la);
    ਲਿਖੋ ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    ਲਿਖੋ ("fa subnormal = %a\n", fa);
    ਲਿਖੋ ("fa subnormal = %.40g\n", fa);
    ਲਿਖੋ ("la subnormal = %La\n", la);
    ਲਿਖੋ ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    ਲਿਖੋ ("fa/2 subnormal = %a\n", fa);
    ਲਿਖੋ ("fa/2 subnormal = %.40g\n", fa);
    ਲਿਖੋ ("la/2 subnormal = %La\n", la);
    ਲਿਖੋ ("la/2 subnormal = %.40Lg\n", la);
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ fib(ਪੂਰਨ n)
{
    ਜੇ (n <= 2)
        ਵਾਪਸ 1;
    ਨਹੀਂਤਾਂ
        ਵਾਪਸ fib(n-1) + fib(n-2);
}

#ਜੇ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ਨਹੀਂਤਾਂ
ਖਾਲੀ __attribute__((aligned(16))) aligned_function(ਪੂਰਨ i) {}
#ਜੇ_ਅੰਤ

ਖਾਲੀ funcptr_test()
{
    ਖਾਲੀ (*func)(ਪੂਰਨ);
    ਪੂਰਨ a;
    ਬਣਤਰ {
        ਪੂਰਨ dummy;
        ਖਾਲੀ (*func)(ਪੂਰਨ);
    } st1;
    ਲੰਮਾ diff;

    func = &ਅੰਕ;
    (*func)(12345);
    func = ਅੰਕ;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = ਅੰਕ;
    st1.func(12346);
    ਲਿਖੋ("sizeof1 = %d\n", ਆਕਾਰ(funcptr_test));
    ਲਿਖੋ("sizeof2 = %d\n", ਆਕਾਰ funcptr_test);
    ਲਿਖੋ("sizeof3 = %d\n", ਆਕਾਰ(&funcptr_test));
    ਲਿਖੋ("sizeof4 = %d\n", ਆਕਾਰ &funcptr_test);
    a = 0;
    func = ਅੰਕ + a;
    diff = func - ਅੰਕ;
    func(42);
    (func + diff)(42);
    (ਅੰਕ + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    ਲਿਖੋ("aligned_function (should be zero): %d\n", ((ਪੂਰਨ)(uintptr_t)func) & 15);
}

ਖਾਲੀ lloptest(ਲੰਮਾ ਲੰਮਾ a, ਲੰਮਾ ਲੰਮਾ b)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    ਲਿਖੋ("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ਜੇ (b != 0) {
        ਲਿਖੋ("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ਦੁਆਧਾਰੀ*/
    ਲਿਖੋ("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    ਲਿਖੋ("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    ਲਿਖੋ("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    ਲਿਖੋ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    ਲਿਖੋ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    ਲਿਖੋ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    ਲਿਖੋ("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    ਲਿਖੋ("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

ਖਾਲੀ llshift(ਲੰਮਾ ਲੰਮਾ a, ਪੂਰਨ b)
{
    ਲਿਖੋ("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)a >> b,
           a >> b,
           a << b);
    ਲਿਖੋ("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)a >> 3,
           a >> 3,
           a << 3);
    ਲਿਖੋ("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)a >> 35,
           a >> 35,
           a << 35);
}

ਖਾਲੀ llfloat(ਖਾਲੀ)
{
    ਦਸ਼ਮਲਵ fa;
    ਦੁੱਗਣਾ da;
    LONG_DOUBLE lda;
    ਲੰਮਾ ਲੰਮਾ la, lb, lc;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    ਲਿਖੋ("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    ਲਿਖੋ("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    ਲਿਖੋ("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    ਲਿਖੋ("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    ਲਿਖੋ("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

ਲੰਮਾ ਲੰਮਾ llfunc1(ਪੂਰਨ a)
{
    ਵਾਪਸ a * 2;
}

ਬਣਤਰ S {
    ਪੂਰਨ id; 
    ਅੱਖਰ ਵਸਤੂ;
};

ਲੰਮਾ ਲੰਮਾ ਪੂਰਨ ਮੁੱਲ(ਬਣਤਰ S *v)
{
    ਵਾਪਸ ((ਲੰਮਾ ਲੰਮਾ ਪੂਰਨ)v->ਵਸਤੂ);
}

ਲੰਮਾ ਲੰਮਾ llfunc2(ਲੰਮਾ ਲੰਮਾ x, ਲੰਮਾ ਲੰਮਾ y, ਪੂਰਨ z)
{
    ਵਾਪਸ x * y * z;
}

ਖਾਲੀ check_opl_save_regs(ਅੱਖਰ *a, ਲੰਮਾ ਲੰਮਾ b, ਪੂਰਨ c)
{
    *a = b < 0 && !c;
}

ਖਾਲੀ longlong_test(ਖਾਲੀ)
{
    ਲੰਮਾ ਲੰਮਾ a, b, c;
    ਪੂਰਨ ia;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ua;
    ਲਿਖੋ("sizeof(long long) = %d\n", ਆਕਾਰ(ਲੰਮਾ ਲੰਮਾ));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    ਲਿਖੋ(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    ਲਿਖੋ(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (ਲੰਮਾ ਲੰਮਾ)1,
           (ਲੰਮਾ ਲੰਮਾ)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    ਲਿਖੋ(LONG_LONG_FORMAT "\n", a);

    lloptest(1000, 23);
    lloptest(0xff, 0x1234);
    b = 0x72345678 << 10;
    lloptest(-3, b);
    llshift(0x123, 5);
    llshift(-23, 5);
    b = 0x72345678LL << 10;
    llshift(b, 47);

    llfloat();
#ਜੇ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    ਲਿਖੋ(XLONG_LONG_FORMAT"\n", c);
#ਜੇ_ਅੰਤ

    /* long long reg spill test */
    {
          ਬਣਤਰ S a;

          a.ਵਸਤੂ = 3;
          ਲਿਖੋ("%lld\n", ਮੁੱਲ(&a));
    }
    lloptest(0x80000000, 0);

    {
        ਲੰਮਾ ਲੰਮਾ *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        ਲਿਖੋ("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        ਲਿਖੋ("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    ਲਿਖੋ("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    ਲਿਖੋ(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    ਲੰਮਾ ਲੰਮਾ *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ u = 0x8000000000000001ULL;
    u = (ਬਿਨਾਨਿਸ਼ਾਨੀ)(u + 1);
    ਲਿਖੋ("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (ਬਿਨਾਨਿਸ਼ਾਨੀ)(ਪੂਰਨ)(u + 1);
    ਲਿਖੋ("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    ਅੱਖਰ cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    ਲਿਖੋ("check_opl_save_regs: %d\n", cc);
}

ਖਾਲੀ manyarg_test(ਖਾਲੀ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ਲਿਖੋ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    ਲਿਖੋ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    ਲਿਖੋ("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    ਲਿਖੋ("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    ਲਿਖੋ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    ਲਿਖੋ("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

ਖਾਲੀ*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ਬਣਤਰ X { ਪੂਰਨ _x; };
        ਬਣਤਰ X *x = va_arg(ap, ਬਣਤਰ X *);
        ਵਾਪਸ x;
}

ਖਾਲੀ vprintf1(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ap, aq;
    ਅਚਲ ਅੱਖਰ *p;
    ਪੂਰਨ c, i;
    ਦੁੱਗਣਾ d;
    ਲੰਮਾ ਲੰਮਾ ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    ਲਈ(;;) {
        c = *p;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        p++;
        ਜੇ (c == '%') {
            c = *p;
            ਚੋਣ(c) {
            ਹਾਲਤ '\0':
                ਜਾਓ the_ਸਿਰਾ;
            ਹਾਲਤ 'd':
                i = va_arg(ap, ਪੂਰਨ);
                ਲਿਖੋ("%d", i);
                ਰੋਕੋ;
            ਹਾਲਤ 'f':
                d = va_arg(ap, ਦੁੱਗਣਾ);
                ਲਿਖੋ("%f", d);
                ਰੋਕੋ;
            ਹਾਲਤ 'l':
                ll = va_arg(ap, ਲੰਮਾ ਲੰਮਾ);
                ਲਿਖੋ(LONG_LONG_FORMAT, ll);
                ਰੋਕੋ;
            ਹਾਲਤ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                ਲਿਖੋ("%Lf", ld);
                ਰੋਕੋ;
            }
            p++;
        } ਨਹੀਂਤਾਂ {
            ਅੱਖਰ_ਲਿਖੋ(c);
        }
    }
 the_ਸਿਰਾ:
    va_end(aq);
    va_end(ap);
}

ਬਣਤਰ myspace {
    ਛੋਟਾ ਪੂਰਨ profile;
};
ਬਣਤਰ myspace2 {
#ਜੇ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    ਅੱਖਰ a[1];
#ਨਹੀਂਤਾਂ
    ਅੱਖਰ a[0];
#ਜੇ_ਅੰਤ
};
ਬਣਤਰ myspace3 {
    ਅੱਖਰ a[1];
};
ਬਣਤਰ myspace4 {
    ਅੱਖਰ a[2];
};
ਬਣਤਰ mytest {
    ਖਾਲੀ *foo, *bar, *baz;
};

ਬਣਤਰ mytest stdarg_for_struct(ਬਣਤਰ myspace bob, ...)
{
    ਬਣਤਰ myspace george, bill;
    ਬਣਤਰ myspace2 alex1;
    ਬਣਤਰ myspace3 alex2;
    ਬਣਤਰ myspace4 alex3;
    va_list ap;
    ਛੋਟਾ ਪੂਰਨ validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ਬਣਤਰ myspace2);
    alex2    = va_arg(ap, ਬਣਤਰ myspace3);
    alex3    = va_arg(ap, ਬਣਤਰ myspace4);
    bill     = va_arg(ap, ਬਣਤਰ myspace);
    george   = va_arg(ap, ਬਣਤਰ myspace);
    validate = va_arg(ap, ਪੂਰਨ);
    ਲਿਖੋ("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ਵਾਪਸ (ਬਣਤਰ mytest) {};
}

ਖਾਲੀ stdarg_for_libc(ਅਚਲ ਅੱਖਰ *fmt, ...)
{
    va_list ਦਲੀਲਾਂ;
    va_start(ਦਲੀਲਾਂ, fmt);
    vprintf(fmt, ਦਲੀਲਾਂ);
    va_end(ਦਲੀਲਾਂ);
}

ਖਾਲੀ stdarg_syntax(ਪੂਰਨ n, ...)
{
    ਪੂਰਨ i;
    va_list ap;
    ਜੇ (1)
      va_start(ap, n);
    ਨਹੀਂਤਾਂ
      ;
    i = va_arg(ap, ਪੂਰਨ);
    ਲਿਖੋ("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ{
    ਦੁੱਗਣਾ x,y;
} ਬਿੰਦੂ;
ਬਿੰਦੂ pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

ਸਥਿਰ ਖਾਲੀ stdarg_double_struct(ਪੂਰਨ nargs, ਪੂਰਨ posd,...)
{
    ਪੂਰਨ i;
    ਦੁੱਗਣਾ d;
    ਬਿੰਦੂ pi;
    va_list ਦਲੀਲਾਂ;

    ਲਿਖੋ ("stdarg_double_struct: %d\n", posd);
    va_start(ਦਲੀਲਾਂ,posd);
    ਲਈ(i = 0; i < nargs; i++) {
        ਜੇ (i == posd) {
            d = va_arg (ਦਲੀਲਾਂ, ਦੁੱਗਣਾ);
            ਲਿਖੋ ("d %d = %g\n", i, d);
        }
        ਨਹੀਂਤਾਂ {
            pi = va_arg (ਦਲੀਲਾਂ, ਬਿੰਦੂ);
            ਲਿਖੋ ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(ਦਲੀਲਾਂ);
}

ਖਾਲੀ stdarg_test(ਖਾਲੀ)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ਬਣਤਰ myspace bob;
    ਬਣਤਰ myspace2 bob2;
    ਬਣਤਰ myspace3 bob3;
    ਬਣਤਰ myspace4 bob4;

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
#ਜੇ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ reltab[3] = { 1, 2, 3 };

ਪੂਰਨ *rel1 = &reltab[1];
ਪੂਰਨ *rel2 = &reltab[2];

ਖਾਲੀ getmyaddress(ਖਾਲੀ)
{
    ਲਿਖੋ("in getmyaddress\n");
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __LP64__
ਲੰਮਾ __pa_symbol(ਖਾਲੀ)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ਵਾਪਸ ((ਲੰਮਾ)(((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)(&rel1))) - (0xffffffff80000000UL));
}
#ਜੇ_ਅੰਤ

uintptr_t theaddress = (uintptr_t)getmyaddress;
ਖਾਲੀ relocation_test(ਖਾਲੀ)
{
    ਖਾਲੀ (*fptr)(ਖਾਲੀ) = (ਖਾਲੀ (*)(ਖਾਲੀ))theaddress;
    ਲਿਖੋ("*rel1=%d\n", *rel1);
    ਲਿਖੋ("*rel2=%d\n", *rel2);
    fptr();
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    ਲਿਖੋ("pa_symbol: %d\n", (ਲੰਮਾ)&rel1 == __pa_symbol() - 0x80000000);
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ old_style_f(a,b,c)
     ਪੂਰਨ a, b;
     ਦੁੱਗਣਾ c;
{
    ਲਿਖੋ("a=%d b=%d b=%f\n", a, b, c);
}

ਖਾਲੀ decl_func1(ਪੂਰਨ cmpfn())
{
    ਲਿਖੋ("cmpfn=%lx\n", (ਲੰਮਾ)cmpfn);
}

ਖਾਲੀ decl_func2(cmpfn)
ਪੂਰਨ cmpfn();
{
    ਲਿਖੋ("cmpfn=%lx\n", (ਲੰਮਾ)cmpfn);
}

ਖਾਲੀ old_style_function_test(ਖਾਲੀ)
{
#ਜੇ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ਨਹੀਂਤਾਂ
    old_style_f((ਖਾਲੀ *)1, 2, 3.0);
#ਜੇ_ਅੰਤ
    decl_func1(ਨਿਰਾ);
    decl_func2(ਨਿਰਾ);
}

ਖਾਲੀ alloca_test()
{
    ਅੱਖਰ *p = alloca(16);
    strcpy(p,"123456789012345");
    ਲਿਖੋ("alloca: p is %s\n", p);
    ਅੱਖਰ *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    ਲਿਖੋ("alloca: %s\n", strcpy(alloca(ਲੜੀ_ਲੰਬਾਈ(demo)+1),demo) );
}

ਖਾਲੀ *bounds_checking_is_enabled()
{
    ਅੱਖਰ ca[10], *cp = ca-1;
    ਵਾਪਸ (ca != cp + 1) ? cp : ਨਿਰਾ;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ constant_negative_array_ਮਾਪ_as_compile_ਸਮਾਂ_assertion_idiom[(1 ? 2 : 0) - 1];

ਖਾਲੀ c99_vla_test_1(ਪੂਰਨ size1, ਪੂਰਨ size2)
{
    ਪੂਰਨ ਮਾਪ = size1 * size2;
    ਪੂਰਨ tab1[ਮਾਪ][2], tab2[10][2];
    ਖਾਲੀ *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    ਮਾਪ = ਮਾਪ-1;
    
    ਲਿਖੋ("Test C99 VLA 1 (sizeof): ");
    ਲਿਖੋ("%s\n", (ਆਕਾਰ tab1 == size1 * size2 * 2 * ਆਕਾਰ(ਪੂਰਨ)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    ਲਿਖੋ("Test C99 VLA 2 (ptrs subtract): ");
    ਲਿਖੋ("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (ਆਕਾਰ(ਪੂਰਨ) * 2)) ? "PASSED" : "FAILED");
    ਲਿਖੋ("Test C99 VLA 3 (ptr add): ");
    ਲਿਖੋ("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * ਆਕਾਰ(ਪੂਰਨ)) ? "PASSED" : "FAILED");
    ਲਿਖੋ("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    ਲਿਖੋ("%s\n", (*((ਪੂਰਨ *) (tab1_ptr + (size1 * 2 + 1) * ਆਕਾਰ(ਪੂਰਨ))) == 42) ? "PASSED" : "FAILED");

    ਲਿਖੋ("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ਜੇ (bad_ptr = bounds_checking_is_enabled()) {
        ਪੂਰਨ *t1 = &tab1[size1 * size2 - 1][3];
        ਪੂਰਨ *t2 = &tab2[9][3];
        ਲਿਖੋ("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        ਲਿਖੋ("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        ਅੱਖਰ*c1 = 1 + ਆਕਾਰ(tab1) + (ਅੱਖਰ*)tab1;
        ਅੱਖਰ*c2 = 1 + ਆਕਾਰ(tab2) + (ਅੱਖਰ*)tab2;
        ਲਿਖੋ("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        ਲਿਖੋ("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        ਪੂਰਨ *i1 = tab1[-1];
        ਪੂਰਨ *i2 = tab2[-1];
        ਲਿਖੋ("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        ਲਿਖੋ("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        ਪੂਰਨ *x1 = tab1[size1 * size2 + 1];
        ਪੂਰਨ *x2 = tab2[10 + 1];
        ਲਿਖੋ("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        ਲਿਖੋ("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ਨਹੀਂਤਾਂ {
        ਲਿਖੋ("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    ਲਿਖੋ("\n");
}

ਖਾਲੀ c99_vla_test_2(ਪੂਰਨ d, ਪੂਰਨ h, ਪੂਰਨ w)
{
    ਪੂਰਨ x, y, z;
    ਪੂਰਨ (*arr)[h][w] = ਸਮ੍ਰਿਤੀ_ਦਿਓ(ਆਕਾਰ(ਪੂਰਨ) * d*h*w);
    ਪੂਰਨ c = 1;
    ਸਥਿਰ ਪੂਰਨ (*starr)[h][w];

    ਲਿਖੋ("Test C99 VLA 6 (pointer)\n");

    ਲਈ (z=0; z<d; z++) {
        ਲਈ (y=0; y<h; y++) {
            ਲਈ (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    ਲਈ (z=0; z<d; z++) {
        ਲਈ (y=0; y<h; y++) {
            ਲਈ (x=0; x<w; x++) {
                ਲਿਖੋ(" %2d", arr[z][y][x]);
            }
            puts("");
        }
        puts("");
    }
    starr = &arr[1];
    ਲਿਖੋ(" sizes : %d %d %d\n"
           " pdiff : %d %d\n"
           " tests : %d %d %d\n",
        ਆਕਾਰ (*arr), ਆਕਾਰ (*arr)[0], ਆਕਾਰ (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == ਆਕਾਰ (*arr + 1) - ਆਕਾਰ arr,
        0 == ਆਕਾਰ ਆਕਾਰ *arr - ਆਕਾਰ arr,
        starr[0][2][3] == arr[1][2][3]
        );
    ਮੁਕਤ (arr);
}

ਖਾਲੀ c99_vla_test_3a (ਪੂਰਨ arr[2][3][4])
{
    ਲਿਖੋ ("%d\n", arr[1][2][3]);
}

ਖਾਲੀ c99_vla_test_3b(ਪੂਰਨ s, ਪੂਰਨ arr[s][3][4])
{
    ਲਿਖੋ ("%d\n", arr[1][2][3]);
}

ਖਾਲੀ c99_vla_test_3c(ਪੂਰਨ s, ਪੂਰਨ arr[2][s][4])
{
    ਲਿਖੋ ("%d\n", arr[1][2][3]);
}

ਖਾਲੀ c99_vla_test_3d(ਪੂਰਨ s, ਪੂਰਨ arr[2][3][s])
{
    ਲਿਖੋ ("%d\n", arr[1][2][3]);
}

ਖਾਲੀ c99_vla_test_3e(ਪੂਰਨ s, ਪੂਰਨ arr[][3][--s])
{
    ਲਿਖੋ ("%d %d %d\n", ਆਕਾਰ arr, s, arr[1][2][3]);
}

ਖਾਲੀ c99_vla_test_3(ਖਾਲੀ)
{
    ਪੂਰਨ a[2][3][4];

    memset (a, 0, ਆਕਾਰ(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

ਖਾਲੀ c99_vla_test(ਖਾਲੀ)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


ਖਾਲੀ sizeof_test(ਖਾਲੀ)
{
    ਪੂਰਨ a;
    ਪੂਰਨ **ptr;

    ਲਿਖੋ("sizeof(int) = %d\n", ਆਕਾਰ(ਪੂਰਨ));
    ਲਿਖੋ("sizeof(unsigned int) = %d\n", ਆਕਾਰ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ));
    ਲਿਖੋ("sizeof(long) = %d\n", ਆਕਾਰ(ਲੰਮਾ));
    ਲਿਖੋ("sizeof(unsigned long) = %d\n", ਆਕਾਰ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ));
    ਲਿਖੋ("sizeof(short) = %d\n", ਆਕਾਰ(ਛੋਟਾ));
    ਲਿਖੋ("sizeof(unsigned short) = %d\n", ਆਕਾਰ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ));
    ਲਿਖੋ("sizeof(char) = %d\n", ਆਕਾਰ(ਅੱਖਰ));
    ਲਿਖੋ("sizeof(unsigned char) = %d\n", ਆਕਾਰ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ));
    ਲਿਖੋ("sizeof(func) = %d\n", ਆਕਾਰ sizeof_test());
    a = 1;
    ਲਿਖੋ("sizeof(a++) = %d\n", ਆਕਾਰ a++);
    ਲਿਖੋ("a=%d\n", a);
    ptr = ਨਿਰਾ;
    ਲਿਖੋ("sizeof(**ptr) = %d\n", ਆਕਾਰ (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    ਲਿਖੋ("sizeof(sizeof(int) = %d\n", ਆਕਾਰ(ਆਕਾਰ(ਪੂਰਨ)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -ਆਕਾਰ(uintptr_t);
    ਲਿਖੋ ("%lu %lu\n", t, t2);

    /* some alignof tests */
    ਲਿਖੋ("__alignof__(int) = %d\n", __alignof__(ਪੂਰਨ));
    ਲਿਖੋ("__alignof__(unsigned int) = %d\n", __alignof__(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ));
    ਲਿਖੋ("__alignof__(short) = %d\n", __alignof__(ਛੋਟਾ));
    ਲਿਖੋ("__alignof__(unsigned short) = %d\n", __alignof__(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ));
    ਲਿਖੋ("__alignof__(char) = %d\n", __alignof__(ਅੱਖਰ));
    ਲਿਖੋ("__alignof__(unsigned char) = %d\n", __alignof__(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ));
    ਲਿਖੋ("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    ਲਿਖੋ("sizeof(char[1+2*a]) = %d\n", ਆਕਾਰ(ਅੱਖਰ[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    ਲਿਖੋ("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   ਆਕਾਰ( (ਬਣਤਰ {ਪੂਰਨ i; ਪੂਰਨ j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    ਲਿਖੋ("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   ਆਕਾਰ (ਬਣਤਰ {ਛੋਟਾ i; ਛੋਟਾ j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    ਲਿਖੋ("sizeof(t && 0) = %d\n", ਆਕਾਰ(t && 0));
    ਲਿਖੋ("sizeof(1 && 1) = %d\n", ਆਕਾਰ(1 && 1));
    ਲਿਖੋ("sizeof(t || 1) = %d\n", ਆਕਾਰ(t || 1));
    ਲਿਖੋ("sizeof(0 || 0) = %d\n", ਆਕਾਰ(0 || 0));

    ਪੂਰਨ arr[4], fn();
    ਲਿਖੋ("sizeof(0, arr) = %d\n", ਆਕਾਰ(0, arr));
    ਲਿਖੋ("sizeof(0, fn) = %d\n", ਆਕਾਰ(0, fn));
}

ਖਾਲੀ typeof_test(ਖਾਲੀ)
{
    ਦੁੱਗਣਾ a;
    typeof(a) b;
    typeof(ਦਸ਼ਮਲਵ) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    ਲਿਖੋ("a=%f b=%f c=%f\n", a, b, c);
}


ਬਣਤਰ hlist_ਗੰਢ;
ਬਣਤਰ hlist_ਸਿਰ {
    ਬਣਤਰ hlist_ਗੰਢ *ਪਹਿਲਾ, *ਆਖਰੀ;
};

ਖਾਲੀ consume_ulong (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ i)
{
    i = 0;
}

ਖਾਲੀ statement_ਵਿਅੰਜਕ_test(ਖਾਲੀ)
{
    ਪੂਰਨ a, i;

    /* Basic stmt expr test */
    a = 0;
    ਲਈ(i=0;i<10;i++) {
        a += 1 + 
            ( { ਪੂਰਨ b, j; 
                b = 0; 
                ਲਈ(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    ਲਿਖੋ("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    ਖਾਲੀ *v = (ਖਾਲੀ*)39;
    typeof(({
	    (ਬਣਤਰ hlist_ਗੰਢ *)v;
	    })) x;
    typeof (x)
	ptr = (ਬਣਤਰ hlist_ਗੰਢ *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ some_attr     __attribute__((aligned(1)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ tps(str) ({                  \
            ਸਥਿਰ ਅਚਲ ਅੱਖਰ *t some_attr = str; \
            t;                                    \
          })
    ਲਿਖੋ ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    ਪੂਰਨ t = 40;
    ਪੂਰਨ b = ({ ਪੂਰਨ t = 41; t; });
    ਪੂਰਨ c = ({ ਪੂਰਨ t = 42; t; });

    /* Test that aggregate return values work.  */
    ਬਣਤਰ hlist_ਸਿਰ h
	= ({
	   ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hlist_ਸਿਰ T;
	   ਲੰਮਾ pre = 48;
	   T t = { (ਖਾਲੀ*)43, (ਖਾਲੀ*)44 };
	   ਲੰਮਾ post = 49;
	   t;
	   });
    ਲਿਖੋ ("stmtexpr: %d %d %d\n", t, b, c);
    ਲਿਖੋ ("stmtexpr: %ld %ld\n", (ਲੰਮਾ)h.ਪਹਿਲਾ, (ਲੰਮਾ)h.ਆਖਰੀ);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ)&&__here; }));

    /* Test interaction between local and global label stacks and the
       need to defer popping symbol from them when within statement
       expressions.  Note how the labels are both named LBL.  */
    i = 0;
    ({
      {
        __label__ LBL;
       LBL: ਜੇ (i++ == 0) ਜਾਓ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      ਜਾਓ LBL;
    });
  LBL:
    ਲਿਖੋ("stmtexpr: %d should be 2\n", i);
}

ਖਾਲੀ local_label_test(ਖਾਲੀ)
{
    ਪੂਰਨ a;
    ਜਾਓ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        ਜਾਓ l1;
    l4:
        ਲਿਖੋ("aa1\n");
        ਜਾਓ l3;
    l2:
        ਲਿਖੋ("aa3\n");
        ਜਾਓ l4;
    l1:
        ਲਿਖੋ("aa2\n");
        ਜਾਓ l2;
    l3:;
        1;
    });
    ਲਿਖੋ("a=%d\n", a);
    ਵਾਪਸ;
 l4:
    ਲਿਖੋ("bb1\n");
    ਜਾਓ l2;
 l1:
    ਲਿਖੋ("bb2\n");
    ਜਾਓ l4;
}

/* inline assembler test */
#ਜੇ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ __SIZE_TYPE__ ਸ਼ਬਦ;

/* from linux kernel */
ਸਥਿਰ ਅੱਖਰ * strncat1(ਅੱਖਰ * dest,ਅਚਲ ਅੱਖਰ * src,ਮਾਪ_t ਗਿਣਤੀ_3)
{
ਸ਼ਬਦ d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ਗਿਣਤੀ_3)
	: "memory");
ਵਾਪਸ dest;
}

ਸਥਿਰ ਅੱਖਰ * strncat2(ਅੱਖਰ * dest,ਅਚਲ ਅੱਖਰ * src,ਮਾਪ_t ਗਿਣਤੀ_3)
{
ਸ਼ਬਦ d0, d1, d2, d3;
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ਗਿਣਤੀ_3)
	: "memory");
ਵਾਪਸ dest;
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ * memcpy1(ਖਾਲੀ * ਮੰਜ਼ਿਲ, ਅਚਲ ਖਾਲੀ * from, ਮਾਪ_t n)
{
ਸ਼ਬਦ d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((ਸ਼ਬਦ) ਮੰਜ਼ਿਲ),"2" ((ਸ਼ਬਦ) from)
	: "memory");
ਵਾਪਸ (ਮੰਜ਼ਿਲ);
}

ਸਥਿਰ ਸਤਰਅੰਦਰ ਖਾਲੀ * memcpy2(ਖਾਲੀ * ਮੰਜ਼ਿਲ, ਅਚਲ ਖਾਲੀ * from, ਮਾਪ_t n)
{
ਸ਼ਬਦ d0, d1, d2;
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
	:"0" (n/4), "q" (n),"1" ((ਸ਼ਬਦ) ਮੰਜ਼ਿਲ),"2" ((ਸ਼ਬਦ) from)
	: "memory");
ਵਾਪਸ (ਮੰਜ਼ਿਲ);
}

ਸਥਿਰ __inline__ ਖਾਲੀ sigaddset1(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਸੈੱਟ, ਪੂਰਨ _sig)
{
	__asm__("btsl %1,%0" : "=m"(*ਸੈੱਟ) : "Ir"(_sig - 1) : "cc");
}

ਸਥਿਰ __inline__ ਖਾਲੀ sigdelset1(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ *ਸੈੱਟ, ਪੂਰਨ _sig)
{
	asm("btrl %1,%0" : "=m"(*ਸੈੱਟ) : "Ir"(_sig - 1) : "cc", "flags");
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
ਸਥਿਰ __inline__ __const__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ swab32(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x)
{
        ਵਾਪਸ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ਨਹੀਂਤਾਂ
ਸਥਿਰ __inline__ __const__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ swab32(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ਵਾਪਸ x;
}
#ਜੇ_ਅੰਤ

ਸਥਿਰ __inline__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ mul64(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ a, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ b)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ res;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ)resh << 32) | resl;
#ਨਹੀਂਤਾਂ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#ਜੇ_ਅੰਤ
    ਵਾਪਸ res;
}

ਸਥਿਰ __inline__ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ inc64(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ a)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ res;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ਨਹੀਂਤਾਂ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#ਜੇ_ਅੰਤ
    ਵਾਪਸ res;
}

ਬਣਤਰ struct123 {
    ਪੂਰਨ a;
    ਪੂਰਨ b;
};
ਬਣਤਰ struct1231 {
    ਸ਼ਬਦ addr;
};

ਸ਼ਬਦ mconstraint_test(ਬਣਤਰ struct1231 *r)
{
    ਸ਼ਬਦ ret;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ a[2];
    a[0] = 0;
    __asm__ ਅਸਥਿਰ ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ਬਣਤਰ struct123 *)r->addr));
    ਵਾਪਸ ret + a[0];
}

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64__
ਪੂਰਨ fls64(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x)
{
  ਪੂਰਨ bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ਵਾਪਸ bitpos + 1;
}
#ਜੇ_ਅੰਤ

ਖਾਲੀ other_constraints_test(ਖਾਲੀ)
{
    ਸ਼ਬਦ ret;
    ਪੂਰਨ var;
#ਜੇ CC_NAME != CC_clang
    __asm__ ਅਸਥਿਰ ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    ਲਿਖੋ ("oc1: %d\n", ret == (ਸ਼ਬਦ)&var);
#ਜੇ_ਅੰਤ
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
/* Test global asm blocks playing with aliases.  */
ਖਾਲੀ ਅਧਾਰ_func(ਖਾਲੀ)
{
  ਲਿਖੋ ("asmc: base\n");
}

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __APPLE__
ਬਾਹਰੀ ਖਾਲੀ override_func1 (ਖਾਲੀ);
ਬਾਹਰੀ ਖਾਲੀ override_func2 (ਖਾਲੀ);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

ਖਾਲੀ override_func2 (ਖਾਲੀ)
{
  ਲਿਖੋ ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
ਬਾਹਰੀ ਪੂਰਨ bug_ਸਾਰਣੀ[] __attribute__((section("__bug_table")));
ਅੱਖਰ * get_asm_string (ਖਾਲੀ)
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
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
  ਬਾਹਰੀ ਪੂਰਨ some_ਚਿੰਨ੍ਹ;
  asm ਅਸਥਿਰ (".globl some_symbol\n"
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
  ਅੱਖਰ * str = ((ਅੱਖਰ*)bug_ਸਾਰਣੀ) + bug_ਸਾਰਣੀ[1];
  ਵਾਪਸ str;
#ਨਹੀਂਤਾਂ
  ਵਾਪਸ (ਅੱਖਰ *) "A string";
#ਜੇ_ਅੰਤ
}

/* This checks another constructs with local labels.  */
ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ alld_stuff[];
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

ਖਾਲੀ asm_local_label_diff (ਖਾਲੀ)
{
  ਲਿਖੋ ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#ਜੇ_ਅੰਤ //!__APPLE__
#ਜੇ_ਅੰਤ //!_WIN32

/* This checks that static local variables are available from assembler.  */
ਖਾਲੀ asm_local_statics (ਖਾਲੀ)
{
  ਸਥਿਰ ਪੂਰਨ localint = 41;
  asm("incl %0" : "+m" (localint));
  ਲਿਖੋ ("asm_local_statics: %d\n", localint);
}

ਸਥਿਰ
ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਸੈੱਟ;

ਖਾਲੀ fancy_copy (ਬਿਨਾਨਿਸ਼ਾਨੀ *ਵਿੱਚ, ਬਿਨਾਨਿਸ਼ਾਨੀ *ਬਾਹਰਲਾ)
{
  asm ਅਸਥਿਰ ("" : "=r" (*ਬਾਹਰਲਾ) : "0" (*ਵਿੱਚ));
}

ਖਾਲੀ fancy_copy2 (ਬਿਨਾਨਿਸ਼ਾਨੀ *ਵਿੱਚ, ਬਿਨਾਨਿਸ਼ਾਨੀ *ਬਾਹਰਲਾ)
{
  asm ਅਸਥਿਰ ("mov %0,(%1)" : : "r" (*ਵਿੱਚ), "r" (ਬਾਹਰਲਾ) : "memory");
}

#ਜੇ defined __x86_64__
ਖਾਲੀ clobber_r12(ਖਾਲੀ)
{
    asm ਅਸਥਿਰ("mov $1, %%r12" ::: "r12");
}
#ਜੇ_ਅੰਤ

ਖਾਲੀ test_ਉੱਚਾ_clobbers_really(ਖਾਲੀ)
{
#ਜੇ defined __x86_64__
    ਰਜਿਸਟਰ ਸ਼ਬਦ val asm("r12");
    ਸ਼ਬਦ val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm ਅਸਥਿਰ("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm ਅਸਥਿਰ("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    ਲਿਖੋ("asmhc: 0x%x\n", val2);
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ test_ਉੱਚਾ_clobbers(ਖਾਲੀ)
{
#ਜੇ defined __x86_64__
    ਸ਼ਬਦ x1, x2;
    asm ਅਸਥਿਰ("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ਉੱਚਾ_clobbers_really();
    asm ਅਸਥਿਰ("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm ਅਸਥਿਰ("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#ਜੇ_ਅੰਤ
}

ਸਥਿਰ ਲੰਮਾ cpu_ਸੰਖਿਆ;
ਖਾਲੀ trace_console(ਲੰਮਾ len, ਲੰਮਾ len2)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64__
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
    ਜੇ (0
        &&
            ({
              ਲੰਮਾ pscr_ret__;
              ਚੋਣ(len) {
                ਹਾਲਤ 4:
                    {
                       ਲੰਮਾ pfo_ret__;
                       ਚੋਣ (len2) {
                         ਹਾਲਤ 8:	ਲਿਖੋ("bla"); pfo_ret__ = 42; ਰੋਕੋ;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  ਰੋਕੋ;
                ਹਾਲਤ 8:
                    {
                       ਲੰਮਾ pfo_ret__;
                       ਚੋਣ (len2) {
                         ਹਾਲਤ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ਸੰਖਿਆ));	ਰੋਕੋ;
                         ਹਾਲਤ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ਸੰਖਿਆ));	ਰੋਕੋ;
                         ਹਾਲਤ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ਸੰਖਿਆ));	ਰੋਕੋ;
                         ਹਾਲਤ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_ਸੰਖਿਆ));	ਰੋਕੋ;
                         ਮੂਲ: ਲਿਖੋ("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  ਰੋਕੋ;
              }
              pscr_ret__;
            }))
      {
        ਲਿਖੋ("huh?\n");
      }
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ test_asm_dead_ਕੋਡ(ਖਾਲੀ)
{
  ਸ਼ਬਦ rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm ਅਸਥਿਰ ("" : "=D" (rdi) : "0" (0));
  (ਖਾਲੀ)ਆਕਾਰ (({
      ਪੂਰਨ var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm ਅਸਥਿਰ ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

ਖਾਲੀ test_asm_call(ਖਾਲੀ)
{
#ਜੇ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  ਸਥਿਰ ਅੱਖਰ str[] = "PATH";
  ਅੱਖਰ *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm ਅਸਥਿਰ ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ਜੇ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ਨਹੀਂਤਾਂ
		"call getenv;"
#ਜੇ_ਅੰਤ
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  ਲਿਖੋ("asmd: %s\n", s);
#ਜੇ_ਅੰਤ
}

#ਜੇ defined __x86_64__
# define RX "(%rip)"
#ਨਹੀਂਤਾਂ
# define RX
#ਜੇ_ਅੰਤ

ਖਾਲੀ asm_dot_test(ਖਾਲੀ)
{
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __APPLE__
    ਪੂਰਨ x;
    ਲਈ (x = 1;; ++x) {
        ਪੂਰਨ r = x;
        ਚੋਣ (x) {
        ਹਾਲਤ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        ਹਾਲਤ 2:
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ਨਹੀਂਤਾਂ
            asm(".text; mov $123, %eax; jmp p0");
#ਜੇ_ਅੰਤ
	ਹਾਲਤ 3:
#ਜੇ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ਨਹੀਂਤਾਂ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#ਜੇ_ਅੰਤ
            asm(".text; mov X"RX",%eax; jmp p0");
        ਹਾਲਤ 4:
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ਨਹੀਂਤਾਂ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ਨਹੀਂਤਾਂ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#ਜੇ_ਅੰਤ
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#ਜੇ_ਅੰਤ
        ਹਾਲਤ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); ਰੋਕੋ;
	}
        ਜੇ (r == x)
            ਰੋਕੋ;
        ਲਿਖੋ("asm_dot_test %d: %d\n", x, r);
    }
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ asm_pcrel_test(ਖਾਲੀ)
{
    ਬਿਨਾਨਿਸ਼ਾਨੀ o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    ਲਿਖੋ("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

ਖਾਲੀ asm_test(ਖਾਲੀ)
{
    ਅੱਖਰ buf[128];
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ val, val2;
    ਬਣਤਰ struct123 s1;
    ਬਣਤਰ struct1231 s2 = { (ਸ਼ਬਦ)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    ਪੂਰਨ ਅਧਾਰ_func = 42;
    ਖਾਲੀ override_func3 (ਖਾਲੀ);
    ਸ਼ਬਦ asmret;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BOOL_ISOC99
    _Bool somebool;
#ਜੇ_ਅੰਤ
    ਰਜਿਸਟਰ ਪੂਰਨ regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm ਅਸਥਿਰ ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm ਅਸਥਿਰ ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    ਲਿਖੋ("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    ਲਿਖੋ("%s\n", buf);

    /* 'A' constraint test */
    ਲਿਖੋ("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    ਲਿਖੋ("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    ਲਿਖੋ("mconstraint: %d", mconstraint_test(&s2));
    ਲਿਖੋ(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    ਸੈੱਟ = 0xff;
    sigdelset1(&ਸੈੱਟ, 2);
    sigaddset1(&ਸੈੱਟ, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    ਜਾਓ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(ਸੈੱਟ) : "Ir"(20) : "cc");
    ਲਿਖੋ("set=0x%x\n", ਸੈੱਟ);
    val = 0x01020304;
    ਲਿਖੋ("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    asm ਅਸਥਿਰ(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    ਲਿਖੋ("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
    asm_local_statics();
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    asm ਅਸਥਿਰ("" : "=r" (asmret) : "0"(s2));
    ਜੇ (asmret != s2.addr)
      ਲਿਖੋ("asmstr: failed\n");
#ਜੇ_ਅੰਤ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm ਅਸਥਿਰ("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ਜੇ (!somebool)
      ਲਿਖੋ("asmbool: failed\n");
#ਜੇ_ਅੰਤ
    val = 43;
    fancy_copy (&val, &val2);
    ਲਿਖੋ ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    ਲਿਖੋ ("fancycpy2(%d)=%d\n", val, val2);
    asm ਅਸਥਿਰ ("mov $0x4243, %%esi" : "=r" (regvar));
    ਲਿਖੋ ("regvar=%x\n", regvar);
    test_ਉੱਚਾ_clobbers();
    trace_console(8, 8);
    test_asm_dead_ਕੋਡ();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ਵਾਪਸ;
 label1:
    ਜਾਓ label2;
}

#ਨਹੀਂਤਾਂ

ਖਾਲੀ asm_test(ਖਾਲੀ)
{
}

#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPAT_TYPE(type1, type2) \
{\
    ਲਿਖੋ("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

ਪੂਰਨ constant_p_var;

ਪੂਰਨ func(ਖਾਲੀ);


/* __builtin_clz and __builtin_ctz return random values for 0 */
ਸਥਿਰ ਖਾਲੀ builtin_test_ਬਿੱਟ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ x, ਪੂਰਨ cnt[])
{
#ਜੇ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ) x) cnt[3] += __builtin_clz(x);
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) x) cnt[4] += __builtin_clzl(x);
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ) x) cnt[5] += __builtin_clzll(x);

    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ) x) cnt[6] += __builtin_ctz(x);
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ) x) cnt[7] += __builtin_ctzl(x);
    ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ) x) cnt[8] += __builtin_ctzll(x);

#ਜੇ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#ਜੇ_ਅੰਤ

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#ਜੇ_ਅੰਤ
}

ਖਾਲੀ builtin_test(ਖਾਲੀ)
{
    ਛੋਟਾ s;
    ਪੂਰਨ i;
    ਲੰਮਾ ਲੰਮਾ ll;
#ਜੇ GCC_MAJOR >= 3
    COMPAT_TYPE(ਪੂਰਨ, ਪੂਰਨ);
    COMPAT_TYPE(ਪੂਰਨ, ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ);
    COMPAT_TYPE(ਪੂਰਨ, ਅੱਖਰ);
    COMPAT_TYPE(ਪੂਰਨ, ਅਚਲ ਪੂਰਨ);
    COMPAT_TYPE(ਪੂਰਨ, ਅਸਥਿਰ ਪੂਰਨ);
    COMPAT_TYPE(ਪੂਰਨ[2], ਅਚਲ ਪੂਰਨ[2]);
    COMPAT_TYPE(ਪੂਰਨ[2][3], ਅਸਥਿਰ ਪੂਰਨ[][3]);
    COMPAT_TYPE(ਪੂਰਨ (*)[], ਅਚਲ ਪੂਰਨ (*)[]);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
    COMPAT_TYPE(__typeof__(1 ? (ਅਚਲ ਪੂਰਨ (*)[2])0 : (ਪੂਰਨ (*)[2])0),
                ਅਚਲ ਪੂਰਨ (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (ਅਚਲ ਪੂਰਨ (*)[2][3])0 :
                              (ਅਸਥਿਰ ਪੂਰਨ (*)[2][3])0),
                ਅਚਲ ਅਸਥਿਰ ਪੂਰਨ (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (ਅਸਥਿਰ ਪੂਰਨ (*)[2][3])0 :
                              (ਅਚਲ ਪੂਰਨ (*)[2][3])0),
                ਅਚਲ ਅਸਥਿਰ ਪੂਰਨ (*)[2][3]);
#ਨਹੀਂਤਾਂ
    /* clang doesn't combine qualifiers through array types */
    ਲਿਖੋ("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    ਲਿਖੋ("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    ਲਿਖੋ("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#ਜੇ_ਅੰਤ
    COMPAT_TYPE(ਪੂਰਨ *, ਪੂਰਨ *);
    COMPAT_TYPE(ਪੂਰਨ *, ਖਾਲੀ *);
    COMPAT_TYPE(ਪੂਰਨ *, ਅਚਲ ਪੂਰਨ *);
    COMPAT_TYPE(ਅੱਖਰ *, ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *);
    COMPAT_TYPE(ਅੱਖਰ *, ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ *);
    COMPAT_TYPE(ਅੱਖਰ *, ਅੱਖਰ *);
    COMPAT_TYPE(ਅੱਖਰ **, ਖਾਲੀ *);
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("res1 = %d\n", __builtin_constant_p(1));
    ਲਿਖੋ("res2 = %d\n", __builtin_constant_p(1 + 2));
    ਲਿਖੋ("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    ਲਿਖੋ("res4 = %d\n", __builtin_constant_p(constant_p_var));
    ਲਿਖੋ("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    ਲਿਖੋ("res6 = %d\n", __builtin_constant_p(i && 1));
    ਲਿਖੋ("res7 = %d\n", __builtin_constant_p("hi"));
    ਲਿਖੋ("res8 = %d\n", __builtin_constant_p(func()));
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
    ਲਿਖੋ("res10 = %d\n", __builtin_constant_p(i && 0));
    ਲਿਖੋ("res11 = %d\n", __builtin_constant_p(i * 0));
    ਲਿਖੋ("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    ਲਿਖੋ("res13 = %d\n", __builtin_constant_p((1,7)));
#ਨਹੀਂਤਾਂ
    /* clang doesn't regard these as constant expression */
    ਲਿਖੋ("res10 = 1\n");
    ਲਿਖੋ("res11 = 1\n");
    ਲਿਖੋ("res12 = 1\n");
    ਲਿਖੋ("res13 = 0\n");
#ਜੇ_ਅੰਤ

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    ਲਿਖੋ("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    ਲਿਖੋ("bce: %d\n", i);
    i = ਆਕਾਰ (__builtin_choose_expr (1, ll, s));
    ਲਿਖੋ("bce: %d\n", i);
    i = ਆਕਾਰ (__builtin_choose_expr (0, ll, s));
    ਲਿਖੋ("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	ਪੂਰਨ cnt[18];
	ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ r = 0;

	memset(cnt, 0, ਆਕਾਰ(cnt));
	builtin_test_ਬਿੱਟ(0, cnt);
	builtin_test_ਬਿੱਟ(0xffffffffffffffffull, cnt);
        ਲਈ (i = 0; i < 64; i++)
	    builtin_test_ਬਿੱਟ(1ull << i, cnt);
        ਲਈ (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_ਬਿੱਟ(r, cnt);
	}
	ਲਈ (i = 0; i < 18; i++)
	    ਲਿਖੋ ("%d %d\n", i, cnt[i]);
    }
}

#ਜੇ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
ਖਾਲੀ weak_test(ਖਾਲੀ) {}
#ਨਹੀਂਤਾਂ
ਬਾਹਰੀ ਪੂਰਨ __attribute__((weak)) weak_f1(ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ __attribute__((weak)) weak_f2(ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ                       weak_f3(ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ __attribute__((weak)) weak_v1;
ਬਾਹਰੀ ਪੂਰਨ __attribute__((weak)) weak_v2;
ਬਾਹਰੀ ਪੂਰਨ                       weak_v3;

ਬਾਹਰੀ ਪੂਰਨ                           (*weak_fpa)() __attribute__((weak));
ਬਾਹਰੀ ਪੂਰਨ __attribute__((weak))     (*weak_fpb)();
ਬਾਹਰੀ     __attribute__((weak)) ਪੂਰਨ (*weak_fpc)();

ਬਾਹਰੀ ਪੂਰਨ                     weak_asm_f1(ਖਾਲੀ) asm("weak_asm_f1x") __attribute((weak));
ਬਾਹਰੀ ਪੂਰਨ __attribute((weak)) weak_asm_f2(ਖਾਲੀ) asm("weak_asm_f2x")                    ;
ਬਾਹਰੀ ਪੂਰਨ __attribute((weak)) weak_asm_f3(ਖਾਲੀ) asm("weak_asm_f3x") __attribute((weak));
ਬਾਹਰੀ ਪੂਰਨ                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
ਬਾਹਰੀ ਪੂਰਨ __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
ਬਾਹਰੀ ਪੂਰਨ __attribute((weak)) weak_asm_v3(ਖਾਲੀ) asm("weak_asm_v3x") __attribute((weak));

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
ਸਥਿਰ ਅਚਲ ਮਾਪ_t dummy = 0;
ਬਾਹਰੀ __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
ਬਾਹਰੀ __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
ਬਾਹਰੀ __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#ਜੇ_ਅੰਤ

ਪੂਰਨ some_lib_func(ਖਾਲੀ);
ਪੂਰਨ dummy_impl_ਦਾ_slf(ਖਾਲੀ) { ਵਾਪਸ 444; }
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __clang__
ਪੂਰਨ some_lib_func(ਖਾਲੀ) __attribute__((weak, alias("dummy_impl_of_slf")));
#ਜੇ_ਅੰਤ

ਪੂਰਨ weak_toolate() __attribute__((weak));
ਪੂਰਨ weak_toolate() { ਵਾਪਸ 0; }

ਖਾਲੀ __attribute__((weak)) weak_test(ਖਾਲੀ)
{
	ਲਿਖੋ("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	ਲਿਖੋ("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	ਲਿਖੋ("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	ਲਿਖੋ("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	ਲਿਖੋ("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	ਲਿਖੋ("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	ਲਿਖੋ("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	ਲਿਖੋ("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	ਲਿਖੋ("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	ਲਿਖੋ("weak_asm_f1=%d\n", weak_asm_f1 != ਨਿਰਾ);
	ਲਿਖੋ("weak_asm_f2=%d\n", weak_asm_f2 != ਨਿਰਾ);
	ਲਿਖੋ("weak_asm_f3=%d\n", weak_asm_f3 != ਨਿਰਾ);
	ਲਿਖੋ("weak_asm_v1=%d\n",&weak_asm_v1 != ਨਿਰਾ);
	ਲਿਖੋ("weak_asm_v2=%d\n",&weak_asm_v2 != ਨਿਰਾ);
	ਲਿਖੋ("weak_asm_v3=%d\n",&weak_asm_v3 != ਨਿਰਾ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __clang__
	ਲਿਖੋ("some_lib_func=444\n");
#ਨਹੀਂਤਾਂ
	ਲਿਖੋ("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ __attribute__((weak)) weak_f2() { ਵਾਪਸ 222; }
ਪੂਰਨ __attribute__((weak)) weak_f3() { ਵਾਪਸ 333; }
ਪੂਰਨ __attribute__((weak)) weak_v2 = 222;
ਪੂਰਨ __attribute__((weak)) weak_v3 = 333;
#ਜੇ_ਅੰਤ

ਖਾਲੀ const_func(ਅਚਲ ਪੂਰਨ a)
{
}

ਖਾਲੀ const_warn_test(ਖਾਲੀ)
{
    const_func(1);
}

ਬਣਤਰ condstruct {
  ਪੂਰਨ i;
};

ਪੂਰਨ getme (ਬਣਤਰ condstruct *s, ਪੂਰਨ i)
{
  ਪੂਰਨ i1 = (i == 0 ? 0 : s)->i;
  ਪੂਰਨ i2 = (i == 0 ? s : 0)->i;
  ਪੂਰਨ i3 = (i == 0 ? (ਖਾਲੀ*)0 : s)->i;
  ਪੂਰਨ i4 = (i == 0 ? s : (ਖਾਲੀ*)0)->i;
  ਵਾਪਸ i1 + i2 + i3 + i4;
}

ਬਣਤਰ global_ਅੰਕੜੇ
{
  ਪੂਰਨ a[40];
  ਪੂਰਨ *b[40];
};

ਬਣਤਰ global_ਅੰਕੜੇ global_ਅੰਕੜੇ;

ਪੂਰਨ global_ਅੰਕੜੇ_getstuff (ਪੂਰਨ *, ਪੂਰਨ);

ਖਾਲੀ global_ਅੰਕੜੇ_callit (ਪੂਰਨ i)
{
  *global_ਅੰਕੜੇ.b[i] = global_ਅੰਕੜੇ_getstuff (global_ਅੰਕੜੇ.b[i], 1);
}

ਪੂਰਨ global_ਅੰਕੜੇ_getstuff (ਪੂਰਨ *p, ਪੂਰਨ i)
{
  ਵਾਪਸ *p + i;
}

ਖਾਲੀ global_ਅੰਕੜੇ_test (ਖਾਲੀ)
{
  global_ਅੰਕੜੇ.a[0] = 42;
  global_ਅੰਕੜੇ.b[0] = &global_ਅੰਕੜੇ.a[0];
  global_ਅੰਕੜੇ_callit (0);
  ਲਿਖੋ ("%d\n", global_ਅੰਕੜੇ.a[0]);
}

ਬਣਤਰ cmpcmpS
{
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ fill : 3;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ b1 : 1;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ b2 : 1;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ fill2 : 3;
};

ਪੂਰਨ glob1, glob2, glob3;

ਖਾਲੀ compare_comparisons (ਬਣਤਰ cmpcmpS *s)
{
  ਜੇ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    ਲਿਖੋ ("comparing comparisons broken\n");
}

ਖਾਲੀ cmp_comparison_test(ਖਾਲੀ)
{
  ਬਣਤਰ cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

ਪੂਰਨ fcompare (ਦੁੱਗਣਾ a, ਦੁੱਗਣਾ b, ਪੂਰਨ ਕੋਡ)
{
  ਚੋਣ (ਕੋਡ) {
    ਹਾਲਤ 0: ਵਾਪਸ a == b;
    ਹਾਲਤ 1: ਵਾਪਸ a != b;
    ਹਾਲਤ 2: ਵਾਪਸ a < b;
    ਹਾਲਤ 3: ਵਾਪਸ a >= b;
    ਹਾਲਤ 4: ਵਾਪਸ a > b;
    ਹਾਲਤ 5: ਵਾਪਸ a <= b;
  }
  ਵਾਪਸ 0;
}

ਖਾਲੀ math_cmp_test(ਖਾਲੀ)
{
  ਦੁੱਗਣਾ nan = 0.0/0.0;
  ਦੁੱਗਣਾ one = 1.0;
  ਦੁੱਗਣਾ two = 2.0;
  ਪੂਰਨ comp = 0;
  ਪੂਰਨ v;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ bug(a,b,op,iop,part) ਲਿਖੋ("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FCMP(a,b,op,iop,ਕੋਡ) \
  ਜੇ (fcompare (a,b,ਕੋਡ))    \
    bug (a,b,op,iop,1); \
  ਜੇ (a op b) \
    bug (a,b,op,iop,2); \
  ਜੇ (a iop b) \
    ; \
  ਨਹੀਂਤਾਂ \
    bug (a,b,op,iop,3); \
  ਜੇ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ਜੇ ((a iop b) || comp) \
    ; \
  ਨਹੀਂਤਾਂ \
    bug (a,b,op,iop,5); \
  ਜੇ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ਜੇ (!fcompare (nan, nan, 1))
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

ਦੁੱਗਣਾ get100 () { ਵਾਪਸ 100.0; }

ਖਾਲੀ callsave_test(ਖਾਲੀ)
{
  ਪੂਰਨ i, s; ਦੁੱਗਣਾ *d; ਦੁੱਗਣਾ t;
  s = ਆਕਾਰ (ਦੁੱਗਣਾ);
  ਲਿਖੋ ("callsavetest: %d\n", s);
  d = alloca (ਆਕਾਰ(ਦੁੱਗਣਾ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  ਲਿਖੋ ("%d\n", i);
}


ਖਾਲੀ bfa3(ptrdiff_t str_ਵਿੱਥ)
{
    ਲਿਖੋ("bfa3: %s\n", (ਅੱਖਰ *)__builtin_frame_address(3) + str_ਵਿੱਥ);
}
ਖਾਲੀ bfa2(ptrdiff_t str_ਵਿੱਥ)
{
    ਲਿਖੋ("bfa2: %s\n", (ਅੱਖਰ *)__builtin_frame_address(2) + str_ਵਿੱਥ);
    bfa3(str_ਵਿੱਥ);
}
ਖਾਲੀ bfa1(ptrdiff_t str_ਵਿੱਥ)
{
    ਲਿਖੋ("bfa1: %s\n", (ਅੱਖਰ *)__builtin_frame_address(1) + str_ਵਿੱਥ);
    bfa2(str_ਵਿੱਥ);
}

ਖਾਲੀ builtin_ਚੌਖਟਾ_ਪਤਾ_test(ਖਾਲੀ)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __arm__
    ਅੱਖਰ str[] = "__builtin_frame_address";
    ਅੱਖਰ *fp0 = __builtin_frame_address(0);

    ਲਿਖੋ("str: %s\n", str);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
}

ਅੱਖਰ ਰਾਹੀਂ_volatile (ਅੱਖਰ i)
{
  ਅੱਖਰ ਅਸਥਿਰ vi;
  vi = i;
  ਵਾਪਸ vi;
}

ਖਾਲੀ volatile_test(ਖਾਲੀ)
{
    ਜੇ (ਰਾਹੀਂ_volatile (42) != 42)
      ਲਿਖੋ (" broken\n");
    ਨਹੀਂਤਾਂ
      ਲਿਖੋ (" ok\n");
}

ਬਣਤਰ __attribute__((__packed__)) Spacked {
    ਅੱਖਰ a;
    ਛੋਟਾ b;
    ਪੂਰਨ c;
};
ਬਣਤਰ Spacked spacked;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __attribute__((__packed__)) {
    ਅੱਖਰ a;
    ਛੋਟਾ b;
    ਪੂਰਨ c;
} Spacked2;
Spacked2 spacked2;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Spacked3_s {
    ਅੱਖਰ a;
    ਛੋਟਾ b;
    ਪੂਰਨ c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ਬਣਤਰ gate_struct64 {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਵਿੱਥ_ਨੀਵਾਂ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ segment;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਵਿੱਥ_ਵਿਚਕਾਰ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਵਿੱਥ_ਉੱਚਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ zero1;
} __attribute__((packed));
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ gate_struct64 gate_desc;
gate_desc a_gate_desc;
ਖਾਲੀ attrib_test(ਖਾਲੀ)
{
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32
  ਲਿਖੋ("attr: %d %d %d %d\n", ਆਕਾਰ(ਬਣਤਰ Spacked),
	 ਆਕਾਰ(spacked), ਆਕਾਰ(Spacked2), ਆਕਾਰ(spacked2));
  ਲਿਖੋ("attr: %d %d\n", ਆਕਾਰ(Spacked3), ਆਕਾਰ(spacked3));
  ਲਿਖੋ("attr: %d %d\n", ਆਕਾਰ(gate_desc), ਆਕਾਰ(a_gate_desc));
#ਜੇ_ਅੰਤ
}
ਬਾਹਰੀ __attribute__((__unused__)) ਅੱਖਰ * __attribute__((__unused__)) *
strange_attrib_placement (ਖਾਲੀ);

ਖਾਲੀ * __attribute__((__unused__)) get_void_ptr (ਖਾਲੀ *a)
{
  ਵਾਪਸ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
ਸਥਿਰ ਸਤਰਅੰਦਰ
ਪੂਰਨ __get_order(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ ਮਾਪ)
{
  ਪੂਰਨ ਕ੍ਰਮ;
  ਮਾਪ -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ਬਣਤਰ S { ਪੂਰਨ i : 1; } s; // constructed for this '1'
    }
  ਕ੍ਰਮ = ਮਾਪ;
  ਵਾਪਸ ਕ੍ਰਮ;
}

/* This just forces the above inline function to be actually emitted.  */
ਪੂਰਨ force_get_ਕ੍ਰਮ(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ s)
{
    ਵਾਪਸ __get_order(s);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pv(m) ਲਿਖੋ(ਆਕਾਰ (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
ਖਾਲੀ bounds_check1_test (ਖਾਲੀ)
{
    ਬਣਤਰ s {
        ਪੂਰਨ x;
        ਲੰਮਾ ਲੰਮਾ y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
ਖਾਲੀ map_ਜੋੜੋ(ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ c, ਪੂਰਨ d, ਪੂਰਨ e, ਪੂਰਨ f, ਪੂਰਨ g, ਪੂਰਨ h, ਪੂਰਨ i)
{
  ਲਿਖੋ ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

ਖਾਲੀ func_arg_test(ਖਾਲੀ)
{
    ਪੂਰਨ a = 0;
    ਪੂਰਨ b = 1;
    map_ਜੋੜੋ(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
ਖਾਲੀ whitespace_test(ਖਾਲੀ)
{
    ਅੱਖਰ *str;
    ਪੂਰਨ tcc_test = 1;

#ਜੇ 1
    pri\
ntf("whitspace:\n");
#ਜੇ_ਅੰਤ
    pf("N=%d\n", 2);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#ਜੇ_ਅੰਤ

    pri\
\
ntf("min=%d\n", 4);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ACCEPT_LF_ਵਿੱਚ_ਲੜੀਆਂ
    ਲਿਖੋ("len1=%d\n", ਲੜੀ_ਲੰਬਾਈ("
"));
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CORRECT_CR_HANDLING
    str = "
";
    ਲਿਖੋ("len1=%d str[0]=%d\n", ਲੜੀ_ਲੰਬਾਈ(str), str[0]);
#ਜੇ_ਅੰਤ
    ਲਿਖੋ("len1=%d\n", ਲੜੀ_ਲੰਬਾਈ("a
"));
#ਨਹੀਂਤਾਂ
    ਲਿਖੋ("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#ਜੇ_ਅੰਤ /* ACCEPT_LF_IN_STRINGS */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __LINE__
    ਲਿਖੋ("__LINE__ defined\n");
#ਜੇ_ਅੰਤ

#ਜੇ 0
    /* wrong with GCC */
    ਲਿਖੋ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ਸਤਰ 1111
    ਲਿਖੋ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ਸਤਰ 2222 "test"
    ਲਿਖੋ("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#ਜੇ_ਅੰਤ

    ਲਿਖੋ("\\
"12\\
063\\
n 456\"\n");

    ਲਿਖੋ ("%d\n",
#ਜੇ 1
	    tcc_test
#ਜੇ_ਅੰਤ
            );

}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੜੀਵਾਰ_2(test) puts("---- " #test " ----"), test(), puts("")

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv)
{
    ਲੜੀਵਾਰ_2(whitespace_test);
    ਲੜੀਵਾਰ_2(macro_test);
    ਲੜੀਵਾਰ_2(recursive_macro_test);
    ਲੜੀਵਾਰ_2(string_test);
    ਲੜੀਵਾਰ_2(ਵਿਅੰਜਕ_test);
    ਲੜੀਵਾਰ_2(scope_test);
    ਲੜੀਵਾਰ_2(scope2_test);
    ਲੜੀਵਾਰ_2(forward_test);
    ਲੜੀਵਾਰ_2(funcptr_test);
    ਲੜੀਵਾਰ_2(if_test);
    ਲੜੀਵਾਰ_2(loop_test);
    ਲੜੀਵਾਰ_2(switch_test);
    ਲੜੀਵਾਰ_2(goto_test);
    ਲੜੀਵਾਰ_2(enum_test);
    ਲੜੀਵਾਰ_2(typedef_test);
    ਲੜੀਵਾਰ_2(struct_test);
    ਲੜੀਵਾਰ_2(array_test);
    ਲੜੀਵਾਰ_2(ਵਿਅੰਜਕ_ptr_test);
    ਲੜੀਵਾਰ_2(bool_test);
    ਲੜੀਵਾਰ_2(optimize_ਬਾਹਰਲਾ_test);
    ਲੜੀਵਾਰ_2(expr2_test);
    ਲੜੀਵਾਰ_2(constant_ਵਿਅੰਜਕ_test);
    ਲੜੀਵਾਰ_2(ਵਿਅੰਜਕ_cmp_test);
    ਲੜੀਵਾਰ_2(char_short_test);
    ਲੜੀਵਾਰ_2(init_test);
    ਲੜੀਵਾਰ_2(compound_literal_test);
    ਲੜੀਵਾਰ_2(kr_test);
    ਲੜੀਵਾਰ_2(struct_ਸੌਂਪੋ_test);
    ਲੜੀਵਾਰ_2(cast_test);
    ਲੜੀਵਾਰ_2(bitfield_test);
    ਲੜੀਵਾਰ_2(c99_bool_test);
    ਲੜੀਵਾਰ_2(float_test);
    ਲੜੀਵਾਰ_2(longlong_test);
    ਲੜੀਵਾਰ_2(manyarg_test);
    ਲੜੀਵਾਰ_2(stdarg_test);
    ਲੜੀਵਾਰ_2(relocation_test);
    ਲੜੀਵਾਰ_2(old_style_function_test);
    ਲੜੀਵਾਰ_2(alloca_test);
    ਲੜੀਵਾਰ_2(c99_vla_test);
    ਲੜੀਵਾਰ_2(sizeof_test);
    ਲੜੀਵਾਰ_2(typeof_test);
    ਲੜੀਵਾਰ_2(statement_ਵਿਅੰਜਕ_test);
    ਲੜੀਵਾਰ_2(local_label_test);
    ਲੜੀਵਾਰ_2(asm_test);
    ਲੜੀਵਾਰ_2(builtin_test);
    ਲੜੀਵਾਰ_2(weak_test);
    ਲੜੀਵਾਰ_2(global_ਅੰਕੜੇ_test);
    ਲੜੀਵਾਰ_2(cmp_comparison_test);
    ਲੜੀਵਾਰ_2(math_cmp_test);
    ਲੜੀਵਾਰ_2(callsave_test);
    ਲੜੀਵਾਰ_2(builtin_ਚੌਖਟਾ_ਪਤਾ_test);
    ਲੜੀਵਾਰ_2(volatile_test);
    ਲੜੀਵਾਰ_2(attrib_test);
    ਲੜੀਵਾਰ_2(bounds_check1_test);
    ਲੜੀਵਾਰ_2(func_arg_test);

    ਵਾਪਸ 0;
}
